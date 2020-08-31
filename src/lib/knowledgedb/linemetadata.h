/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_LINEMETADATA_H
#define KPUBLICTRANSPORT_LINEMETADATA_H

#include "kpublictransport_export.h"

#include <KPublicTransport/Line>

class QColor;
class QString;
class QUrl;

namespace KPublicTransport {

struct LineMetaDataContent;

/** Static information about a public transport line.
 *  @internal exported only for unit tests
 */
class KPUBLICTRANSPORT_EXPORT LineMetaData
{
public:
    LineMetaData();
    ~LineMetaData();
    LineMetaData(const LineMetaData&);
    LineMetaData& operator=(const LineMetaData&);

    bool isNull() const;
    QString name() const;
    QColor color() const;
    QUrl logoUrl() const;
    Line::Mode mode() const;
    QUrl modeLogoUrl() const;

    /** Attempts to find information about a line with the given name and a stop at the given coordinates. */
    static LineMetaData find(double latitude, double longitude, const QString &name, Line::Mode mode);

private:
    LineMetaData(const LineMetaDataContent *dd);
    const LineMetaDataContent *d = nullptr;
};

}

#endif // KPUBLICTRANSPORT_LINEMETADATA_H
