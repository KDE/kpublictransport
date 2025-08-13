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

    [[nodiscard]] bool isNull() const;
    [[nodiscard]] QString name() const;
    [[nodiscard]] QColor color() const;
    [[nodiscard]] QUrl logoUrl() const;
    [[nodiscard]] Line::Mode mode() const;
    [[nodiscard]] QUrl modeLogoUrl() const;

    /** Attempts to find information about a line with the given name and a stop at the given coordinates. */
    [[nodiscard]] static LineMetaData find(double latitude, double longitude, const QString &name, Line::Mode mode);
    /** Attempts to find information about an entire line mode at the given coordinates.
     *  Line-specific data in the result are to be ignored in that case.
     */
    [[nodiscard]] static LineMetaData find(double latitude, double longitude, Line::Mode mode);

private:
    LineMetaData(const LineMetaDataContent *dd);
    const LineMetaDataContent *d = nullptr;
};

}

#endif // KPUBLICTRANSPORT_LINEMETADATA_H
