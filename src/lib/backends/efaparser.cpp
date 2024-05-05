/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "efaparser.h"
#include "logging.h"
#include "scopedxmlstreamreader.h"

#include <KPublicTransport/IndividualTransport>
#include <KPublicTransport/Path>

using namespace KPublicTransport;

bool EfaRequestContext::isEmpty() const
{
    return sessionId.isEmpty() || requestId.isEmpty() || sessionId == QLatin1String("0");
}


EfaParser::~EfaParser() = default;

void EfaParser::setLocationIdentifierType(const QString& locationIdentifierType)
{
    m_locationIdentifierType = locationIdentifierType;
}

Reply::Error EfaParser::error() const
{
    return m_error;
}

QString EfaParser::errorMessage() const
{
    return m_errorMsg;
}

IndividualTransport EfaParser::motTypeToIndividualTransportMode(int mot)
{
    switch (mot) {
        case 100: return { IndividualTransport::Walk, IndividualTransport::None };
        case 101: return { IndividualTransport::Bike, IndividualTransport::Park };
        case 102: return { IndividualTransport::Bike, IndividualTransport::None };
        case 103:
        case 104:
            return { IndividualTransport::Car, IndividualTransport::None }; // TODO
    }
    qCDebug(Log) << "Unknown means of individual transport: " << mot;
    return IndividualTransport::Walk;
}

QPolygonF EfaParser::parsePathCoordinatesElement(ScopedXmlStreamReader &reader)
{
    QPolygonF poly;
    // TODO do we need to support the format attributes, or is this always the same anyway?
    const auto coords = reader.readElementText().split(QLatin1Char(' '), Qt::SkipEmptyParts);
    poly.reserve(coords.size());
    for (const auto &coord : coords) {
        const auto p = coord.split(QLatin1Char(','));
        if (p.size() == 2) {
            poly.push_back({p[0].toDouble(), p[1].toDouble()});
        }
    }
    if (std::any_of(poly.begin(), poly.end(), [](const auto &p) { return p.x() < -180.0 || p.x() > 180.0 || p.y() < -90.0 || p.y() > 90.0; })) {
        qCWarning(Log) << "discarding path with invalid coordinates!";
        return {};
    }
    return poly;
}

Path EfaParser::polygonToPath(const QPolygonF &poly)
{
    PathSection section;
    section.setPath(poly);
    Path path;
    path.setSections({section});
    return path;
}

bool EfaParser::isDummyStopId(QStringView id)
{
    return id == QLatin1String("99999997") || id == QLatin1String("99999998");
}

EfaRequestContext EfaParser::requestContext() const
{
    return m_requestContext;
}

QHash<QString, QString> EfaParser::parseKeyValueList(ScopedXmlStreamReader &&reader, QLatin1String elemName, QLatin1String keyName, QLatin1String valueName)
{
    QHash<QString, QString> attrs;
    while (reader.readNextSibling()) {
        if (reader.name() == elemName) {
            auto attrReader = reader.subReader();
            QString name, value;
            while (attrReader.readNextSibling()) {
                if (attrReader.name() == keyName) {
                    name = attrReader.readElementText();
                } else if (attrReader.name() == valueName) {
                    value = attrReader.readElementText();
                }
            }
            attrs.insert(name, value);
        }
    }
    return attrs;
}
