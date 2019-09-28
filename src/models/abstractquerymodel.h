/*
    Copyright (C) 2019 Volker Krause <vkrause@kde.org>

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

#ifndef KPUBLICTRANSPORT_ABSTRACTQUERYMODEL_H
#define KPUBLICTRANSPORT_ABSTRACTQUERYMODEL_H

#include "kpublictransport_export.h"

#include <QAbstractListModel>

#include <memory>
#include <vector>

namespace KPublicTransport {

class AbstractQueryModelPrivate;
class Attribution;
class Manager;

/** Common base class for query models, do not use directly. */
class KPUBLICTRANSPORT_EXPORT AbstractQueryModel : public QAbstractListModel
{
    Q_OBJECT

    /** Sets the KPublicTransport::Manager instance. Necessary for this to work at all. */
    Q_PROPERTY(KPublicTransport::Manager* manager READ manager WRITE setManager NOTIFY managerChanged)

    /** @c true if there is still an ongoing network operation. */
    Q_PROPERTY(bool loading READ isLoading NOTIFY loadingChanged)
    /** Contains the error message if all backends failed to provide a result. */
    Q_PROPERTY(QString errorMessage READ errorMessage NOTIFY errorMessageChanged)

    /** Attributions for the provided data. */
    Q_PROPERTY(QVariantList attributions READ attributionsVariant NOTIFY attributionsChanged)

public:
    ~AbstractQueryModel();

    Manager* manager() const;
    void setManager(Manager *mgr);

    bool isLoading() const;
    QString errorMessage() const;

    /** The attribution information for the current model content. */
    const std::vector<Attribution>& attributions() const;

Q_SIGNALS:
    void managerChanged();
    void loadingChanged();
    void errorMessageChanged();
    void attributionsChanged();

protected:
    ///@cond internal
    Q_DECL_HIDDEN explicit AbstractQueryModel(AbstractQueryModelPrivate *dd, QObject *parent);
    std::unique_ptr<AbstractQueryModelPrivate> d_ptr;
    ///@endcond

private:
    Q_DECL_HIDDEN QVariantList attributionsVariant() const;
};

}

#endif // KPUBLICTRANSPORT_ABSTRACTQUERYMODEL_H
