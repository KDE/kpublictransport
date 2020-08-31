/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_LOAD_H
#define KPUBLICTRANSPORT_LOAD_H

#include "datatypes.h"

namespace KPublicTransport {

/** Vehicle load categories. */
namespace Load
{
    KPUBLICTRANSPORT_EXPORT Q_NAMESPACE

    /** Vehicle load categories. */
    enum Category {
        Unknown, ///< no load information are available
        Low,
        Medium,
        High,
        Full, ///< no remaining seats
    };
    Q_ENUM_NS(Category)
}

class LoadInfoPrivate;

/** Vehicle load information.
 *  This consists of a load category and additional
 *  specifiers for which part of the vehicle this applies to,
 *  such as the class or vehicle section.
 */
class KPUBLICTRANSPORT_EXPORT LoadInfo
{
    KPUBLICTRANSPORT_GADGET(LoadInfo)
    /** Load category. */
    KPUBLICTRANSPORT_PROPERTY(KPublicTransport::Load::Category, load, setLoad)
    /** Seating class, empty if not applicable.
     *  TODO should this be the same enum as in VehicleSection?
     */
    KPUBLICTRANSPORT_PROPERTY(QString, seatingClass, setSeatingClass)
    // TODO vehicle section, once we have a backend reporting this (SBB has that in theory I think)
public:
    /** Serializes one load information object to JSON. */
    static QJsonObject toJson(const LoadInfo &info);
    /** Serializes a vector of load information objects to JSON. */
    static QJsonArray toJson(const std::vector<LoadInfo> &loadInfos);
    /** Deserialize an object from JSON. */
    static LoadInfo fromJson(const QJsonObject &obj);
    /** Deserialize a list of load information from JSON. */
    static std::vector<LoadInfo> fromJson(const QJsonArray &array);
};

}

Q_DECLARE_METATYPE(KPublicTransport::LoadInfo)

#endif // KPUBLICTRANSPORT_LOAD_H
