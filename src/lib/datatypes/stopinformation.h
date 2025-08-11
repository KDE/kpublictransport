/*
    SPDX-FileCopyrightText: ⓒ 2025 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_STOPINFORMATION_H
#define KPUBLICTRANSPORT_STOPINFORMATION_H

#include "datatypes.h"
#include <QVariant>

class QJsonArray;
class QJsonObject;

namespace KPublicTransport {

class Line;
class Location;
class StopInformationPrivate;

/** Transit stop specific additional information for a location.
 *  @see Location::data
 *  @since 25.12
 */
class KPUBLICTRANSPORT_EXPORT StopInformation
{
    KPUBLICTRANSPORT_GADGET(StopInformation)

    /** Lines served at this stop. */
    Q_PROPERTY(std::vector<KPublicTransport::Line> lines READ lines)
public:
    /** Served lines at this stop. Can be fully qualified lines or just transport modes,
     *  depending on what the backend provides.
     */
    [[nodiscard]] const std::vector<Line>& lines() const;

    /** Add another served line. */
    void addLine(const KPublicTransport::Line &line);
    /** Sets lines servied at this stop. */
    void setLines(const std::vector<Line> &lines);

    /** Augment line meta data.
     *  @param download when set to @c true trigger download of missing assets.
     */
    void applyMetaData(const Location &loc, bool download);

    /** Merge two stop information instances.
     *  This assumes isSame(lhs, rhs) and tries to preserve the most detailed information.
     */
    [[nodiscard]] static StopInformation merge(const StopInformation &lhs, const StopInformation &rhs);

    /** Serializes one StopInformation object to JSON. */
    [[nodiscard]] static QJsonObject toJson(const StopInformation &info);
    /** Deserialize a StopInformation object from JSON. */
    [[nodiscard]] static StopInformation fromJson(const QJsonObject &obj);
};

}

Q_DECLARE_METATYPE(KPublicTransport::StopInformation)

#endif // KPUBLICTRANSPORT_STOPINFORMATION_H
