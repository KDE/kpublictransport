/*
    SPDX-FileCopyrightText: 2026 Jonah Brüchert <jbb@kaidan.im>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "photonbackend.h"

#include "backends/abstractbackend.h"
#include "http/useragent_p.h"
#include "locationreply.h"
#include "locationrequest.h"
#include "photonparser.h"

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QString>
#include <QUrlQuery>

#include <utility>

using namespace KPublicTransport;

using namespace Qt::StringLiterals;

AbstractBackend::Capabilities KPublicTransport::PhotonBackend::capabilities() const
{
    return m_url.scheme() == "https"_L1 ? Secure : NoCapability;
}

bool PhotonBackend::queryLocation(const LocationRequest &request,
                                  LocationReply *reply,
                                  QNetworkAccessManager *nam) const
{
    if (request.name().size() <= 3) {
        return false;
    }

    QUrl url = m_url;
    QUrlQuery query;
    query.addQueryItem(u"q"_s, request.name());
    if (request.location().hasCoordinate()) {
        query.addQueryItem(u"lat"_s, QString::number(request.location().latitude()));
        query.addQueryItem(u"lon"_s, QString::number(request.location().longitude()));
    }
    url.setQuery(query);

    QNetworkRequest req(url);
    req.setHeader(QNetworkRequest::KnownHeaders::UserAgentHeader, Http::userAgent().toUtf8());
    logRequest(request, req);

    auto *netReply = nam->get(req);
    QObject::connect(netReply, &QNetworkReply::finished, reply, [=, this]() {
        if (netReply->error() != QNetworkReply::NoError) {
            addError(reply, Reply::NetworkError, netReply->errorString());
            return;
        }

        const auto body = netReply->readAll();
        logReply(reply, netReply, body);
        auto locations = PhotonParser::parseLocations(body);
        addResult(reply, std::move(locations));
    });

    // async
    return true;
}

Location::Types PhotonBackend::supportedLocationTypes() const
{
    return Location::Type::Address | Location::Type::Place | Location::Type::Stop;
}
