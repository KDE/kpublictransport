/*
    SPDX-FileCopyrightText: 2024 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_MOTISPARSER_H
#define KPUBLICTRANSPORT_MOTISPARSER_H

#include <QUrl>

class QJsonObject;

namespace KPublicTransport {

class Location;
class Journey;
class Stopover;

struct MotisConnections
{
    std::vector<Journey> journeys;
    quint64 begin = 0;
    quint64 end = 0;

    [[nodiscard]] inline bool empty() const { return journeys.empty(); }
};

/** Response parsing for Motis. */
class MotisParser
{
public:
    explicit MotisParser(QString locIdentifierType);

    [[nodiscard]] MotisConnections parseConnections(const QByteArray &data);
    [[nodiscard]] std::vector<Stopover> parseEvents(const QByteArray &data);
    [[nodiscard]] std::vector<Location> parseStations(const QByteArray &data);

    [[nodiscard]] bool hasError() const;
    [[nodiscard]] QString errorMessage() const;

private:
    [[nodiscard]] Journey parseConnection(const QJsonObject &con) const;
    [[nodiscard]] Location parseStation(const QJsonObject &station) const;
    [[nodiscard]] QJsonObject parseContent(const QByteArray &data);

    QString m_locIdentifierType;
    QString m_errorMsg;
};

}

#endif
