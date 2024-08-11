/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_DEUTSCHEBAHNPRODUCTS_H
#define KPUBLICTRANSPORT_DEUTSCHEBAHNPRODUCTS_H

#include <KPublicTransport/Line>

namespace KPublicTransport {

/** Product category mapping for DB. */
namespace DeutscheBahnProducts
{
    [[nodiscard]] bool isValid(QStringView categoryName);
    [[nodiscard]] Line::Mode modeType(QStringView categoryName);
}

}

#endif
