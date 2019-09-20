/*
    Copyright (C) 2018 Volker Krause <vkrause@kde.org>

    This program is free software; you can redistribute it and/or modify it
    under the terms of the GNU Library General Public License as published by
    the Free Software Foundation; either version 2 of the License, or (at your
    option) any later version.

    This program is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public
    License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#ifndef KPUBLICTRANSPORT_MANAGER_H
#define KPUBLICTRANSPORT_MANAGER_H

#include "kpublictransport_export.h"

#include <QObject>

#include <memory>

class QNetworkAccessManager;

/** Query operations and data types for accessing realtime public transport information
 *  from online services.
 */
namespace KPublicTransport {

class Attribution;
class DepartureReply;
class DepartureRequest;
class JourneyReply;
class JourneyRequest;
class LocationReply;
class LocationRequest;
class ManagerPrivate;

/** Entry point for starting public transport queries.
 *
 *  Queries return reply objects, you are responsible for deleting those,
 *  typically by calling deleteLater() on them after having retrieved their
 *  result (similar to how QNetworkAccessManager works).
 */
class KPUBLICTRANSPORT_EXPORT Manager : public QObject
{
    Q_OBJECT
    /** QML-compatible access to attributions(). */
    Q_PROPERTY(QVariantList attributions READ attributionsVariant NOTIFY attributionsChanged)
    /** Allow usage of insecure backends (default: off). */
    Q_PROPERTY(bool allowInsecureBackends READ allowInsecureBackends WRITE setAllowInsecureBackends NOTIFY configurationChanged)

public:
    explicit Manager(QObject *parent = nullptr);
    ~Manager();

    /** Set the network access manager to use for network operations.
     *  If not set, an instance is created internally.
     *  Ownership is not transferred.
     */
    void setNetworkAccessManager(QNetworkAccessManager *nam);

    /** Returns whether access to insecure backends is allowed. */
    bool allowInsecureBackends() const;
    /** Allow usage of insecure backends, that is services not using
     *  transport encryption.
     */
    void setAllowInsecureBackends(bool insecure);

    /** Query a journey. */
    JourneyReply* queryJourney(const JourneyRequest &req) const;

    /** Query departures from a specific station. */
    DepartureReply* queryDeparture(const DepartureRequest &req) const;

    /** Query location information based on coordinates or (parts of) the name. */
    LocationReply* queryLocation(const LocationRequest &req) const;

    /** Returns all static attribution information, as well as all dynamic ones
     *  found in the cache or accumulated during the lifetime of this instance.
     */
    const std::vector<Attribution>& attributions() const;

Q_SIGNALS:
    void attributionsChanged();
    void configurationChanged();

private:
    Q_DECL_HIDDEN QVariantList attributionsVariant() const;

    std::unique_ptr<ManagerPrivate> d;
};

}

#endif // KPUBLICTRANSPORT_MANAGER_H
