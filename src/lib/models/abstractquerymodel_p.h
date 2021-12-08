/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_ABSTRACTQUERYMODEL_P_H
#define KPUBLICTRANSPORT_ABSTRACTQUERYMODEL_P_H

#include <QAbstractListModel>
#include <QTimer>

#include <chrono>

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

    /** Compresses query execution calls by one event loop.
     *  This helps with direct writes to the request property from QML, which shows up as
     *  multiple calls to the request setter.
     */
    void query();
    virtual void doQuery() = 0;
    virtual void doClearResults() = 0;

    AbstractQueryModel *q_ptr = nullptr;
    Manager *m_manager = nullptr;
    Reply *m_reply = nullptr;

    std::vector<Attribution> m_attributions;

    QTimer m_queryTimer;
    std::chrono::milliseconds m_queryDelay = std::chrono::milliseconds(0);

    QString m_errorMessage;
    bool m_loading = false;
};

}

#endif // KPUBLICTRANSPORT_ABSTRACTQUERYMODEL_H

