/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_ACCESSIBILITYCLOUDPARSER_H
#define KPUBLICTRANSPORT_ACCESSIBILITYCLOUDPARSER_H

#include <KPublicTransport/Attribution>
#include <KPublicTransport/Location>

namespace KPublicTransport {

/** Parser for Accessibility Cloud JSON responses. */
class AccessibilityCloudParser
{
public:
    bool parseLocations(const QByteArray &data);

    std::vector<Location> locations;
    std::vector<Attribution> attributions;
};

}

#endif // KPUBLICTRANSPORT_ACCESSIBILITYCLOUDPARSER_H
