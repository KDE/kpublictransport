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

#include "efabackend.h"
#include "efaparser.h"
#include "logging.h"

#include <KPublicTransport/Location>
#include <KPublicTransport/LocationReply>
#include <KPublicTransport/LocationRequest>

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>
#include <QUrlQuery>

using namespace KPublicTransport;

EfaBackend::EfaBackend() = default;
EfaBackend::~EfaBackend() = default;

bool EfaBackend::isSecure() const
{
    return m_endpoint.startsWith(QLatin1String("https"));
}

bool EfaBackend::queryLocation(const LocationRequest& request, LocationReply *reply, QNetworkAccessManager *nam) const
{
    // TODO support query by coordinate
    if (request.name().isEmpty()) {
        return false;
    }

    QUrl url(m_endpoint);
    url.setPath(url.path() + QLatin1String("XML_STOPFINDER_REQUEST"));

    QUrlQuery query;
    query.addQueryItem(QStringLiteral("locationServiceActive"), QStringLiteral("1"));
    query.addQueryItem(QStringLiteral("outputFormat"), QStringLiteral("XML"));
    query.addQueryItem(QStringLiteral("type_sf"), QStringLiteral("stop"));
    query.addQueryItem(QStringLiteral("name_sf"), request.name());
    query.addQueryItem(QStringLiteral("anyObjFilter_sf"), QStringLiteral("2")); // bitfield, "2" is the flag for stops
    query.addQueryItem(QStringLiteral("coordOutputFormat"), QStringLiteral("WGS84[DD.ddddd]"));
    url.setQuery(query);

    auto netReply = nam->get(QNetworkRequest(url));
    QObject::connect(netReply, &QNetworkReply::finished, reply, [this, reply, netReply]() {
        netReply->deleteLater();
        if (netReply->error() != QNetworkReply::NoError) {
            qCDebug(Log) << netReply->url() << netReply->errorString();
            addError(reply, Reply::NetworkError, netReply->errorString());
            return;
        }
        qDebug() << netReply->url();
        EfaParser p;
        p.setLocationIdentifierType(locationIdentifierType());
        // TODO handle parser and response errors
        addResult(reply, p.parseStopFinderResponse(netReply->readAll()));
    });

    return true;
}

QString EfaBackend::locationIdentifierType() const
{
    return m_locationIdentifierType.isEmpty() ? backendId() : m_locationIdentifierType;
}
