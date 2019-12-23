/*
    Copyright (C) 2019 Volker Krause <vkrause@kde.org>

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

#include "deutschebahnbackend.h"
#include "deutschebahnvehiclelayoutparser.h"

#include <KPublicTransport/Departure>
#include <KPublicTransport/VehicleLayoutReply>
#include <KPublicTransport/VehicleLayoutRequest>

#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QRegularExpression>
#include <QUrl>

using namespace KPublicTransport;

AbstractBackend::Capabilities DeutscheBahnBackend::capabilities() const
{
    return Secure; // hardcoded API endpoint below
}

static QString extractTrainNumber(const Line &line)
{
    qDebug() << line.modeString() << line.name();
    QRegularExpression regex(QStringLiteral("(?:ICE|IC|EC)\\s*(\\d+)"));
    const auto match = regex.match(line.modeString() + line.name());
    if (match.hasMatch()) {
        return match.captured(1);
    }
    return {};
}

bool DeutscheBahnBackend::queryVehicleLayout(const VehicleLayoutRequest &request, VehicleLayoutReply *reply, QNetworkAccessManager *nam) const
{
    // we need two parameters for the online API: the train number (numeric only), and the departure time
    // note: data is only available withing the upcoming 24h
    // checking this early is useful as the error response from the online service is extremely verbose...
    const auto dt = request.departure().scheduledDepartureTime();
    const auto trainNum = extractTrainNumber(request.departure().route().line());
    qDebug() << dt << trainNum;
    if (!dt.isValid() || trainNum.isEmpty()) { // TODO check dt in valid range
        return false;
    }

    QUrl url;
    url.setScheme(QStringLiteral("https"));
    url.setHost(QStringLiteral("www.apps-bahn.de"));
    url.setPath(QLatin1String("/wr/wagenreihung/1.0/") + trainNum + QLatin1Char('/') + dt.toString(QStringLiteral("yyyyMMddhhmm")));

    QNetworkRequest netReq(url);
    logRequest(request, netReq);
    auto netReply = nam->get(netReq);

    QObject::connect(netReply, &QNetworkReply::finished, reply, [this, reply, netReply] {
        const auto data = netReply->readAll();
        logReply(reply, netReply, data);

        if (netReply->error() == QNetworkReply::NoError) {
            DeutscheBahnVehicleLayoutParser p;
            if (p.parse(data)) {
                addResult(reply, p.vehicle, p.platform, p.departure);
            } else {
                addError(reply, this, p.error, {});
            }
        } else {
            addError(reply, this, Reply::NetworkError, reply->errorString());
        }
        netReply->deleteLater();
    });

    return true;
}
