/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
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
    Q_PROPERTY(QString category READ category NOTIFY elementChanged)
    Q_PROPERTY(bool debug MEMBER m_debug)

public:
    explicit OSMElementInformationModel(QObject *parent = nullptr);
    ~OSMElementInformationModel();

    enum Role {
        KeyRole = Qt::UserRole,
        KeyLabelRole,
        ValueRole,
        ValueUrlRole,
        CategoryRole,
        CategoryLabelRole,
        TypeRole,
    };
    enum KeyCategory {
        UnresolvedCategory,
        Header,
        Main,
        Contact,
        Payment,
        Toilets,
        Accessibility,
        Parking,
        Operator,
        DebugCategory,
    };
    Q_ENUM(KeyCategory)
    enum Key {
        NoKey,
        Name,
        Category,
        OldName,
        Routes,
        Cuisine,
        Diet,
        Takeaway,
        Socket,
        OpeningHours,
        Fee,
        Authentication,
        BicycleParking,
        Capacity,
        CapacityDisabled,
        CapacityWomen,
        CapacityParent,
        CapacityCharing,
        MaxStay,
        DiaperChangingTable,
        Wikipedia,
        Address,
        Phone,
        Email,
        Website,
        PaymentCash,
        PaymentDigital,
        PaymentDebitCard,
        PaymentCreditCard,
        PaymentStoredValueCard,
        Wheelchair,
        CentralKey,
        OperatorName,
        Network,
        OperatorWikipedia,
        DebugLink,
        DebugKey,
    };
    Q_ENUM(Key)
    enum Type {
        String,
        Link,
        PostalAddress,
        OpeningHoursType,
    };
    Q_ENUM(Type)

    OSMElement element() const;
    void setElement(const OSMElement &element);
    Q_INVOKABLE void clear();

    QString name() const;
    QString category() const;

    int rowCount(const QModelIndex &parent = {}) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

Q_SIGNALS:
    void elementChanged();

private:
    struct Info;

    void reload();
    /** Resolve elements who's group depends on context. */
    void resolveCategories();
    /** Make sure we have at least one naming element. */
    void resolveHeaders();
    bool promoteMainCategory(KeyCategory cat);
    QString categoryLabel(KeyCategory cat) const;
    QString debugTagKey(int row) const;
    QString debugTagValue(int row) const;
    QString keyName(Key key) const;
    QVariant valueForKey(Info info) const;
    QVariant urlify(const QVariant &v, Key key) const;
    QString paymentMethodList(Key key) const;
    QString paymentMethodValue(Key key) const;
    QUrl wikipediaUrl(const QByteArray &wp) const;
    QString capacitryValue(const char *prop) const;

    template <typename KeyMapEntry, std::size_t N>
    void addEntryForKey(const char *keyName, const KeyMapEntry(&map)[N]);

    OSM::Element m_element;

    struct Info {
        Key key;
        KeyCategory category;

        bool operator<(Info other) const;
        bool operator==(Info other) const;
    };
    std::vector<Info> m_infos;
    Key m_nameKey = NoKey;
    Key m_categoryKey = NoKey;
    bool m_debug = false;
};

}

#endif // KOSMINDOORMAP_OSMELEMENTINFORMATIONMODEL_H
