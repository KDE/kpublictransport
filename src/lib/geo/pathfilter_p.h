/*
    SPDX-FileCopyrightText: 2024 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_PATHUTIL_P_H
#define KPUBLICTRANSPORT_PATHUTIL_P_H

class QPolygonF;

namespace KPublicTransport {

namespace PathFilter {

/** Remove spikes from @p path that require turn angles above @p maxAngle. */
void removeSpikes(QPolygonF &path, double maxAngle);

}

}

#endif
