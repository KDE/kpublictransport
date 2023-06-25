/*
    SPDX-FileCopyrightText: 2021-2023 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_IVVASSPRODUCTMAP_H
#define KPUBLICTRANSPORT_IVVASSPRODUCTMAP_H

#include <KPublicTransport/Line>

namespace KPublicTransport {

/** Product type mappings for IVV ASS. */
namespace IvvAssProductMap
{
    /** Convert "physical mode" to Line::Mode */
    Line::Mode parseProduct(QStringView mode);
}

}

#endif // KPUBLICTRANSPORT_IVVASSPRODUCTMAP_H
