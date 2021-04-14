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

public:
    explicit BackendModel(QObject *parent = nullptr);
    ~BackendModel();

    enum Roles {
        NameRole = Qt::DisplayRole,
        DescriptionRole = Qt::UserRole,
        IdentifierRole,
        SecureRole,
        ItemEnabledRole,
        BackendEnabledRole,
        PrimaryCountryCodeRole, ///< See Backend::primaryCountry, useful for section grouping
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

private:
    friend class BackendModelPrivate;
    const std::unique_ptr<BackendModelPrivate> d;
};

}

#endif // KPUBLICTRANSPORT_BACKENDMODEL_H
