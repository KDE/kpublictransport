/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_PATHMODEL_H
#define KPUBLICTRANSPORT_PATHMODEL_H

#include "kpublictransport_export.h"

#include <KPublicTransport/Path>

#include <QAbstractListModel>

namespace KPublicTransport {

/** Model representing a KPublicTransport::Path.
 *  Each row is a KPublicTransport::PathSection, the model computes
 *  additional information such as turn directions for each section.
 */
class KPUBLICTRANSPORT_EXPORT PathModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(KPublicTransport::Path path READ path WRITE setPath)

public:
    explicit PathModel(QObject *parent = nullptr);
    ~PathModel() override;

    enum Role {
        PathSectionRole = Qt::UserRole,
        TurnDirectionRole,
    };

    Path path() const;
    void setPath(const Path &path);

    int rowCount(const QModelIndex &parent = {}) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

private:
    Path m_path;
};

}

#endif // KPUBLICTRANSPORT_PATHMODEL_H
