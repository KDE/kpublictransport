/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_ABSTRACTQUERYMODEL_P_H
#define KPUBLICTRANSPORT_ABSTRACTQUERYMODEL_P_H

#include <QAbstractListModel>

#include "pointer_helper_p.h"

namespace KPublicTransport {

class Manager;
class Reply;

class AbstractQueryModelPrivate
{
public:
    virtual ~AbstractQueryModelPrivate();

    void setLoading(bool l);
    void setErrorMessage(const QString &msg);
    void monitorReply(Reply *reply);
    void resetForNewRequest();

    /** Compresses query execution calls by one event loop.
     *  This helps with direct writes to the request property from QML, which shows up as
     *  multiple calls to the request setter.
     */
    void query();
    virtual void doQuery() = 0;

    AbstractQueryModel *q_ptr = nullptr;
    Manager *m_manager = nullptr;

    std::vector<Attribution> m_attributions;

    QString m_errorMessage;
    bool m_loading = false;
    bool m_pendingQuery = false;
};

}

#endif // KPUBLICTRANSPORT_ABSTRACTQUERYMODEL_H

