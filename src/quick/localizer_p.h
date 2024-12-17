/*
    SPDX-FileCopyrightText: 2018 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef LOCALIZER_H
#define LOCALIZER_H

#include <QObject>


namespace KPublicTransport
{
class Journey;
}

/** 
 * @internal
 * Similar to Itinerary::Localized but only for KPublicTransport::Journey properties
 */
class Localizer
{
    Q_GADGET
public:
    Q_INVOKABLE QString formatTime(const KPublicTransport::Journey &journey, const QString &propertyName) const;
    Q_INVOKABLE QString formatDurationCustom(int seconds) const;
};

#endif // LOCALIZER_H
