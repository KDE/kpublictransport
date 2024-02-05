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

/** Response parsing for Motis. */
class MotisParser
{
public:
    explicit MotisParser(QString locIdentifierType);

    [[nodiscard]] std::vector<Journey> parseConnections(const QByteArray &data);
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
