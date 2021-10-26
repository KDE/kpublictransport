/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_BACKENDMODEL_H
#define KPUBLICTRANSPORT_BACKENDMODEL_H

#include "kpublictransport_export.h"

#include <QAbstractListModel>

#include <memory>

namespace KPublicTransport {

class BackendModelPrivate;
class Manager;

/** Model listing backends and allowing to configure which ones are active. */
class KPUBLICTRANSPORT_EXPORT BackendModel : public QAbstractListModel
{
    Q_OBJECT

    /** Sets the KPublicTransport::Manager instance. Necessary for this to work at all. */
    Q_PROPERTY(KPublicTransport::Manager* manager READ manager WRITE setManager NOTIFY managerChanged)
    /** Configures the grouping mode for the content of this model. */
    Q_PROPERTY(Mode mode READ mode WRITE setMode NOTIFY modeChanged)
public:
    explicit BackendModel(QObject *parent = nullptr);
    ~BackendModel() override;

    /** Content grouping modes. */
    enum Mode {
        Flat, ///< Each backend appears exactly once, grouping by country is possible (the data is order by country), but multi-country operators might not be properly associated.
        GroupByCountry, ///< A backend might occur multiple times, for each country it is associated with.
    };
    Q_ENUM(Mode)

    Mode mode() const;
    void setMode(Mode mode);

    enum Roles {
        NameRole = Qt::DisplayRole,
        DescriptionRole = Qt::UserRole,
        IdentifierRole,
        SecureRole,
        ItemEnabledRole,
        BackendEnabledRole,
        PrimaryCountryCodeRole [[deprecated("use CountryCodeRole")]], ///< @deprecated use CountryCodeRole instead
        CountryCodeRole, ///< a ISO 3166-1 code usable for grouping content by country
    };

    Manager* manager() const;
    void setManager(Manager *mgr);

    int rowCount(const QModelIndex &parent = {}) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role) override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    QHash<int, QByteArray> roleNames() const override;

Q_SIGNALS:
    void managerChanged();
    void modeChanged();

private:
    friend class BackendModelPrivate;
    const std::unique_ptr<BackendModelPrivate> d;
};

}

#endif // KPUBLICTRANSPORT_BACKENDMODEL_H
