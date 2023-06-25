/*
    SPDX-FileCopyrightText: 2021-2023 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_IVVASSPRODUCTMAP_H
#define KPUBLICTRANSPORT_IVVASSPRODUCTMAP_H

#include <KPublicTransport/Line>

class QUrlQuery;

namespace KPublicTransport {

/** Product type mappings for IVV ASS. */
namespace IvvAssProductMap
{
    /** Convert "physical mode" to Line::Mode */
    Line::Mode parseProduct(QStringView mode);

    /** Convert a set of line modes to a corresponding URL query. */
    void lineModesToQuery(const std::vector<Line::Mode> &lineModes, QUrlQuery &query);
}

}

#endif // KPUBLICTRANSPORT_IVVASSPRODUCTMAP_H
