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

#ifndef KPUBLICTRANSPORT_ABSTRACTQUERYMODEL_P_H
#define KPUBLICTRANSPORT_ABSTRACTQUERYMODEL_P_H

#include <QAbstractListModel>

namespace KPublicTransport {

class Manager;
class Reply;

class AbstractQueryModelPrivate
{
public:
    void setLoading(bool l);
    void setErrorMessage(const QString &msg);
    void monitorReply(Reply *reply);
    void resetForNewRequest();

    AbstractQueryModel *q_ptr = nullptr;
    Manager *m_manager = nullptr;

    std::vector<Attribution> m_attributions;

    QString m_errorMessage;
    bool m_loading = false;
};

}

#endif // KPUBLICTRANSPORT_ABSTRACTQUERYMODEL_H

