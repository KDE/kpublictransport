/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_IVVASSPARSER_H
#define KPUBLICTRANSPORT_IVVASSPARSER_H

#include <KPublicTransport/Location>

#include <QDateTime>
#include <QString>
#include <QTimeZone>

#include <vector>

class QByteArray;
class QJsonObject;

namespace KPublicTransport {

class Journey;
class Stopover;

/** Parser for IVV ASS responses. */
class IvvAssParser
{
public:
    explicit IvvAssParser(const QTimeZone &tz, const QString &locationIdentifier);

    std::vector<Location> parseLocations(const QByteArray &data);
    std::vector<Stopover> parseStopovers(const QByteArray &data);
    std::vector<Journey> parseJourneys(const QByteArray &data);

    QString errorMessage;

private:
    bool parseError(const QJsonObject &top);

    struct EventTime {
        QDateTime scheduled;
        QDateTime expected;
    };
    EventTime parseTime(const QJsonObject &obj, const char *baseKey, const char *scheduledKey) const;

    struct LocationData
    {
        Location loc;
        QString platform;
    };
    LocationData parseLocation(const QJsonObject &stopObj) const;

    QTimeZone m_timezone;
    QString m_locationIdentifier;
};

}

#endif // KPUBLICTRANSPORT_IVVASSPARSER_H
