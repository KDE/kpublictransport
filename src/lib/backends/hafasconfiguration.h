/*
    SPDX-FileCopyrightText: 2023 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_HAFASCONFIGURATION_H
#define KPUBLICTRANSPORT_HAFASCONFIGURATION_H

#include <QStringList>

namespace KPublicTransport {

/** Configuration entry for product name mappings.
 *  @see HafasMgateBackend::productNameMapping
 */
struct HafasMgateProductNameMapping
{
    int cls;
    QStringList lineName;
    QStringList routeName;

    constexpr inline bool operator==(int otherCls) const { return cls == otherCls; }
};

}

#endif
