/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
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
    ~AbstractQueryModel() override;

    [[nodiscard]] Manager* manager() const;
    void setManager(Manager *mgr);

    [[nodiscard]] bool isLoading() const;
    [[nodiscard]] QString errorMessage() const;

    /** The attribution information for the current model content. */
    [[nodiscard]] const std::vector<Attribution>& attributions() const;

    /** Cancel ongoing query operations, but keep the results that are already there. */
    Q_INVOKABLE void cancel();

    /** Cancel any ongoing query operations, and clear the results. */
    Q_INVOKABLE void clear();

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
