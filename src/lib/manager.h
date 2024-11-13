/*
    SPDX-FileCopyrightText: 2018 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
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
class Backend;
class JourneyReply;
class JourneyRequest;
class LocationReply;
class LocationRequest;
class ManagerPrivate;
class StopoverReply;
class StopoverRequest;
class VehicleLayoutReply;
class VehicleLayoutRequest;

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

    /** @see enabledBackends() */
    Q_PROPERTY(QStringList enabledBackends READ enabledBackends WRITE setEnabledBackends NOTIFY configurationChanged)
    /** @see disabledBackends() */
    Q_PROPERTY(QStringList disabledBackends READ disabledBackends WRITE setDisabledBackends NOTIFY configurationChanged)
    /** @see backendsEnabledByDefault() */
    Q_PROPERTY(bool backendsEnabledByDefault READ backendsEnabledByDefault WRITE setBackendsEnabledByDefault NOTIFY configurationChanged)

    /** QML-compatible access to backends(). */
    Q_PROPERTY(QVariantList backends READ backendsVariant NOTIFY backendsChanged)

public:
    explicit Manager(QObject *parent = nullptr);
    ~Manager() override;

    /** Set the network access manager to use for network operations.
     *  If not set, an instance is created internally.
     *  Ownership is not transferred.
     */
    void setNetworkAccessManager(QNetworkAccessManager *nam);

    /** Returns whether access to insecure backends is allowed. */
    [[nodiscard]] bool allowInsecureBackends() const;
    /** Allow usage of insecure backends, that is services not using
     *  transport encryption.
     */
    void setAllowInsecureBackends(bool insecure);

    /** Query a journey. */
    [[nodiscard]] JourneyReply* queryJourney(const JourneyRequest &req) const;

    /** Query arrivals or departures from a specific station. */
    [[nodiscard]] StopoverReply* queryStopover(const StopoverRequest &req) const;

    /** Query location information based on coordinates or (parts of) the name. */
    [[nodiscard]] LocationReply* queryLocation(const LocationRequest &req) const;

    /** Query vehicle and platform layout information.
     *  This is only available for some trains and some operators, so be prepared
     *  for empty results.
     */
    [[nodiscard]] VehicleLayoutReply* queryVehicleLayout(const VehicleLayoutRequest &req) const;

    /** Returns all static attribution information, as well as all dynamic ones
     *  found in the cache or accumulated during the lifetime of this instance.
     */
    [[nodiscard]] const std::vector<Attribution>& attributions() const;

    /** Returns information about all available backends. */
    [[nodiscard]] const std::vector<Backend>& backends() const;

    /** Returns whether the use of the backend with a given identifier is enabled. */
    Q_INVOKABLE [[nodiscard]] bool isBackendEnabled(const QString &backendId) const;
    /** Sets whether the backend with the given identifier should be used.
     *  @note If allowInsecureBackends() is @c false, this has precedence.
     */
    void setBackendEnabled(const QString &backendId, bool enabled);

    /** Returns the identifiers of explicitly enabled backends.
     *  Use this for persisting the settings, not for checking for enabled backends.
     */
    [[nodiscard]] QStringList enabledBackends() const;
    /** Sets the explicitly enabled backends.
     *  Use for restoring persisted settings.
     */
    void setEnabledBackends(const QStringList &backendIds);
    /** Returns the identifiers of explicitly disabled backends.
     *  Use this for persisting settings, not for checking for disabled backends.
     */
    [[nodiscard]] QStringList disabledBackends() const;
    /** Sets the explicitly disabled backends.
     *  Use for restoring persisted settings.
     */
    void setDisabledBackends(const QStringList &backendIds);
    /**
     * Returns wheter backends are enabled by default.
     * Defaults to true.
     */
    [[nodiscard]] bool backendsEnabledByDefault() const;
    /**
     * Set wheter backends are enabled by default.
     */
    void setBackendsEnabledByDefault(bool byDefault);


Q_SIGNALS:
    void attributionsChanged();
    void configurationChanged();
    void backendsChanged();

private:
    Q_DECL_HIDDEN QVariantList attributionsVariant() const;
    Q_DECL_HIDDEN QVariantList backendsVariant() const;

    std::unique_ptr<ManagerPrivate> d;
};

}

#endif // KPUBLICTRANSPORT_MANAGER_H
