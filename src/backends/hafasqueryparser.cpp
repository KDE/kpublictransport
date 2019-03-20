/*
    Copyright (C) 2018 Volker Krause <vkrause@kde.org>

    This program is free software; you can redistribute it and/or modify it
    under the terms of the GNU Library General Public License as published by
    the Free Software Foundation; either version 2 of the License, or (at your
    option) any later version.

    This program is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public
    License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include "hafasqueryparser.h"
#include "logging.h"

#include <KPublicTransport/Departure>
#include <KPublicTransport/Journey>
#include <KPublicTransport/Location>

#include <QDateTime>
#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QXmlStreamReader>

#include <zlib.h>

using namespace KPublicTransport;

void HafasQueryParser::setLocationIdentifierType(const QString &idType)
{
    m_locationIdentifierType = idType;
}

std::vector<Departure> HafasQueryParser::parseStationBoardResponse(const QByteArray &data, bool isArrival)
{
    qDebug().noquote() << data;
    std::vector<Departure> res;

    QXmlStreamReader reader;
    if (data.startsWith("<Journey")) { // SBB and RT don't reply with valid XML...
        reader.addData("<dummyRoot>");
        reader.addData(data);
        reader.addData("</dummyRoot>");
    } else {
        reader.addData(data);
    }

    Location stopPoint;
    while (!reader.atEnd()) {
        const auto token = reader.readNext();
        switch (token) {
            case QXmlStreamReader::StartElement:
                if (reader.name() == QLatin1String("St")) {
                    stopPoint.setName(reader.attributes().value(QLatin1String("name")).toString());
                    stopPoint.setIdentifier(m_locationIdentifierType, reader.attributes().value(QLatin1String("evaId")).toString());
                } else if (reader.name() == QLatin1String("Journey")) {
                    auto dt = QDateTime::fromString(reader.attributes().value(QLatin1String("fpDate")) + reader.attributes().value(QLatin1String("fpTime")), QStringLiteral("dd.MM.yyhh:mm"));
                    if (dt.date().year() < 2000) {
                        dt = dt.addYears(100);
                    }
                    const auto delayStr = reader.attributes().value(QLatin1String("e_delay"));
                    const auto delaySecs = delayStr.toInt() * 60;
                    Departure dep;
                    if (isArrival) {
                        dep.setScheduledArrivalTime(dt);
                        if (!delayStr.isEmpty()) {
                            dep.setExpectedArrivalTime(dt.addSecs(delaySecs));
                        }
                    } else {
                        dep.setScheduledDepartureTime(dt);
                        if (!delayStr.isEmpty()) {
                            dep.setExpectedDepartureTime(dt.addSecs(delaySecs));
                        }
                    }
                    dep.setScheduledPlatform(reader.attributes().value(QLatin1String("platform")).toString());
                    dep.setExpectedPlatform(reader.attributes().value(QLatin1String("newpl")).toString());

                    Route route;
                    route.setDirection(reader.attributes().value(QLatin1String("targetLoc")).toString());
                    Line line;
                    line.setName(reader.attributes().value(QLatin1String("hafasname")).toString());
                    if (line.name().isEmpty()) {
                        const auto prod = reader.attributes().value(QLatin1String("prod"));
                        const auto idx = prod.indexOf(QLatin1Char('#'));
                        line.setName(prod.left(idx).toString().simplified());
                    }
                    // TODO line mode (class attribute, or second part of prod attribute)
                    route.setLine(line);
                    dep.setRoute(route);

                    dep.setStopPoint(stopPoint);
                    res.push_back(dep);
                }
                break;
            default:
                break;
        }
    }

    return res;
}

std::vector<Location> HafasQueryParser::parseGetStopResponse(const QByteArray &data)
{
    // remove garbage around JSON payload
    const auto startIdx = data.indexOf('{');
    const auto endIdx = data.lastIndexOf('}');
    const auto jsonData = data.mid(startIdx, endIdx - startIdx + 1);

    const auto doc = QJsonDocument::fromJson(jsonData);
    //qDebug().noquote() << doc.toJson();
    const auto suggestions = doc.object().value(QLatin1String("suggestions")).toArray();
    std::vector<Location> res;
    res.reserve(suggestions.size());
    for (const auto &suggestion : suggestions) {
        const auto obj = suggestion.toObject();
        Location loc;
        loc.setIdentifier(m_locationIdentifierType, obj.value(QLatin1String("extId")).toString());
        loc.setName(obj.value(QLatin1String("value")).toString());
        loc.setLatitude(obj.value(QLatin1String("ycoord")).toString().toInt() / 1000000.0);
        loc.setLongitude(obj.value(QLatin1String("xcoord")).toString().toInt() / 1000000.0);
        res.push_back(loc);
    }

    return res;
}

std::vector<Journey> HafasQueryParser::parseQueryResponse(const QByteArray &data)
{
    // yes, this is gzip compressed rather than using the HTTP compression transparently...
    QByteArray rawData;
    z_stream stream;
    unsigned char buffer[1024];

    stream.zalloc = nullptr;
    stream.zfree = nullptr;
    stream.opaque = nullptr;
    stream.avail_in = data.size();
    stream.next_in = reinterpret_cast<unsigned char*>(const_cast<char*>(data.data()));

    auto ret = inflateInit2(&stream, 15 + 32); // see docs, the magic numbers enable gzip decoding
    if (ret != Z_OK) {
        qCWarning(Log) << "Failed to initialize zlib stream.";
        return {};
    }

    do {
        stream.avail_out = sizeof(buffer);
        stream.next_out = buffer;

        ret = inflate(&stream, Z_NO_FLUSH);
        if (ret != Z_OK && ret != Z_STREAM_END) {
            qCWarning(Log) << "Zlib decoding failed!" << ret;
            break;
        }

        rawData.append(reinterpret_cast<char*>(buffer), sizeof(buffer) - stream.avail_out);
    } while (stream.avail_out == 0);
    inflateEnd(&stream);

    // TODO
    qDebug() << rawData;

    return {};
}
