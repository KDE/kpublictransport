/*
    SPDX-FileCopyrightText: 2026 Jonah Brüchert <jbb@kaidan.im>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_PHOTONPARSER_H
#define KPUBLICTRANSPORT_PHOTONPARSER_H

#include <KPublicTransport/Location>

namespace KPublicTransport {

class PhotonParser
{
public:
    [[nodiscard]] static std::vector<Location> parseLocations(const QByteArray &data);
};

}

#endif
