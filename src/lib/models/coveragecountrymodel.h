/*
    SPDX-FileCopyrightText: ⓒ 2025 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_COVERAGECOUNTRYMODEL_H
#define KPUBLICTRANSPORT_COVERAGECOUNTRYMODEL_H

#include "kpublictransport_export.h"

#include <QAbstractListModel>

#include <memory>

namespace KPublicTransport {

class CoverageCountryModelPrivate;
class Manager;

/** Model listing covered countries in the current backend configuration. */
class KPUBLICTRANSPORT_EXPORT CoverageCountryModel : public QAbstractListModel
{
    Q_OBJECT

    /** Sets the KPublicTransport::Manager instance. Necessary for this to work at all. */
    Q_PROPERTY(KPublicTransport::Manager* manager READ manager WRITE setManager NOTIFY managerChanged)

public:
    explicit CoverageCountryModel(QObject *parent = nullptr);
    ~CoverageCountryModel() override;

    enum Roles {
        CountryCodeRole = Qt::UserRole,
    };
    Q_ENUM(Roles)

    [[nodiscard]] Manager* manager() const;
    void setManager(Manager *mgr);

    [[nodiscard]] int rowCount(const QModelIndex &parent = {}) const override;
    [[nodiscard]] QVariant data(const QModelIndex &index, int role) const override;
    [[nodiscard]] QHash<int, QByteArray> roleNames() const override;

Q_SIGNALS:
    void managerChanged();

private:
    Q_DECL_HIDDEN void repopulate();
    const std::unique_ptr<CoverageCountryModelPrivate> d;
};

}

#endif
