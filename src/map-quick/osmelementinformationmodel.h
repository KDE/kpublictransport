/*
    Copyright (C) 2020 Volker Krause <vkrause@kde.org>

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

#ifndef KOSMINDOORMAP_OSMELEMENTINFORMATIONMODEL_H
#define KOSMINDOORMAP_OSMELEMENTINFORMATIONMODEL_H

#include "osmelement.h"

#include <osm/element.h>

#include <QAbstractListModel>

namespace KOSMIndoorMap {

/** Model containing information about a selected element.
 *  Exact content depends on the type of element and the available information.
 */
class OSMElementInformationModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(KOSMIndoorMap::OSMElement element READ element WRITE setElement NOTIFY elementChanged)
    Q_PROPERTY(QString name READ name NOTIFY elementChanged)
    Q_PROPERTY(bool debug MEMBER m_debug)

public:
    explicit OSMElementInformationModel(QObject *parent = nullptr);
    ~OSMElementInformationModel();

    enum Role {
        KeyRole = Qt::UserRole,
        KeyLabelRole,
        ValueRole,
        CategoryRole,
        TypeRole,
    };
    enum KeyCategory {
        Main,
        Contact,
        Accessibility,
        Operator,
        DebugCategory
    };
    enum Key {
        Category,
        Cuisine,
        OpeningHours,
        Address,
        Phone,
        Email,
        Website,
        Wheelchair,
        OperatorName,
        DebugKey,
    };
    Q_ENUM(Key)
    enum Type {
        String,
        Link,
        PostalAddress,
    };
    Q_ENUM(Type)

    OSMElement element() const;
    void setElement(const OSMElement &element);

    QString name() const;

    int rowCount(const QModelIndex &parent = {}) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

Q_SIGNALS:
    void elementChanged();

private:
    void reload();
    QString categoryLabel(KeyCategory cat) const;
    QString debugTagKey(int row) const;
    QString debugTagValue(int row) const;
    QString keyName(Key key) const;
    QVariant valueForKey(Key key) const;

    OSM::Element m_element;

    struct Info {
        Key key;
        KeyCategory category;

        bool operator<(Info other) const;
    };
    std::vector<Info> m_infos;
    bool m_debug = false;
};

}

#endif // KOSMINDOORMAP_OSMELEMENTINFORMATIONMODEL_H
