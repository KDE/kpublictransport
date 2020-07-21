/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_LINEMETADATAWRAPPER_H
#define KPUBLICTRANSPORT_LINEMETADATAWRAPPER_H

#include <KPublicTransport/Line>

namespace KPublicTransport {

/** QML API for looking up line metadata. */
class LineMetaDataWrapper
{
    Q_GADGET
public:
    /** Lookup line metadata. */
    Q_INVOKABLE KPublicTransport::Line lookup(const QString &name, double latitude, double longitude, int mode, bool download);
};

}

#endif // KPUBLICTRANSPORT_LINEMETADATAWRAPPER_H
