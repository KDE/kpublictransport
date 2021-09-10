/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_UICUTIL_H
#define KPUBLICTRANSPORT_UICUTIL_H

#include <cstdint>
#include <vector>

class QStringView;

namespace KPublicTransport {


/** Utility functions for dealing with UIC station codes.
 *  Also works for the syntactically identical IBNR station codes.
 */
namespace UicUtil
{

/** Returns @c true if @p id is a valid UIC station code.
 *  @params allowedCountryCodes if non-empty, only UIC station codes with an UIC country code included
 *  in that list are considered valid. This list has to be sorted.
 */
bool isStationId(QStringView id, const std::vector<uint8_t> &allowedCountryCodes = {});

}

}

#endif // KPUBLICTRANSPORT_UICUTIL_H
