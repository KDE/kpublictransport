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

#include "osmelementinformationmodel.h"
#include "osmaddress.h"

using namespace KOSMIndoorMap;

bool OSMElementInformationModel::Info::operator<(OSMElementInformationModel::Info other) const
{
    if (category == other.category) {
        return key < other.key;
    }
    return category < other.category;
}

static constexpr const OSMElementInformationModel::Type type_map[] = {
    OSMElementInformationModel::String,        // Category
    OSMElementInformationModel::String,        // Cuisine
    OSMElementInformationModel::String,        // OpeningHours
    OSMElementInformationModel::PostalAddress, // Address
    OSMElementInformationModel::Link,          // Phone
    OSMElementInformationModel::Link,          // Email
    OSMElementInformationModel::Link,          // Website
    OSMElementInformationModel::String,        // Wheelchair
    OSMElementInformationModel::String,        // DebugKey
};

OSMElementInformationModel::OSMElementInformationModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

OSMElementInformationModel::~OSMElementInformationModel() = default;

OSMElement OSMElementInformationModel::element() const
{
    return OSMElement(m_element);
}

void OSMElementInformationModel::setElement(const OSMElement &element)
{
    if (m_element == element.element()) {
        return;
    }

    beginResetModel();
    m_element = element.element();
    m_infos.clear();
    if (m_element.type() != OSM::Type::Null) {
        reload();
    }
    endResetModel();
    emit elementChanged();
}

int OSMElementInformationModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid() || m_element.type() == OSM::Type::Null) {
        return 0;
    }
    return m_infos.size();
}

QVariant OSMElementInformationModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid()) {
        return {};
    }

    const auto info = m_infos[index.row()];
    switch (role) {
        case TypeRole:
            return type_map[info.key];
        case KeyRole:
            return info.key;
        case KeyLabelRole:
            if (info.key == DebugKey) {
                return debugTagKey(index.row());
            }
            return keyName(info.key);
        case ValueRole:
            if (info.key == DebugKey) {
                return debugTagValue(index.row());
            }
            return valueForKey(info.key);
        case CategoryRole:
            return categoryLabel(info.category);
    }

    return {};
}

QHash<int, QByteArray> OSMElementInformationModel::roleNames() const
{
    auto r = QAbstractListModel::roleNames();
    r.insert(KeyRole, "key");
    r.insert(KeyLabelRole, "keyLabel");
    r.insert(ValueRole, "value");
    r.insert(CategoryRole, "category");
    r.insert(TypeRole, "type");
    return r;
}

#define M(name, key, category) { name, OSMElementInformationModel::key, OSMElementInformationModel::category }
struct {
    const char *name;
    OSMElementInformationModel::Key key;
    OSMElementInformationModel::KeyCategory category;
} static constexpr const simple_key_map[] = {
    M("addr:city", Address, Contact),
    M("addr:street", Address, Contact),
    M("amenity", Category, Main),
    M("contact:city", Address, Contact),
    M("contact:email", Email, Contact),
    M("contact:phone", Phone, Contact),
    M("contact:street", Address, Contact),
    M("contact:website", Website, Contact),
    M("cuisine", Cuisine, Main),
    M("phone", Phone, Contact),
    M("office", Category, Main),
    M("opening_hours", OpeningHours, Main),
    M("room", Category, Main),
    M("url", Website, Contact),
    M("shop", Category, Main),
    M("tourism", Category, Main),
    M("website", Website, Contact),
    M("wheelchair", Wheelchair, Accessibility),
};
#undef M

void OSMElementInformationModel::reload()
{
    for (auto it = m_element.tagsBegin(); it != m_element.tagsEnd(); ++it) {
        for (const auto &simpleKey : simple_key_map) {
            if (std::strcmp((*it).key.name(), simpleKey.name) == 0 && !std::any_of(m_infos.begin(), m_infos.end(), [simpleKey](auto info) { return info.key == simpleKey.key; })) {
                m_infos.push_back(Info{simpleKey.key, simpleKey.category});
                break;
            }
        }
    }

    std::sort(m_infos.begin(), m_infos.end());

    if (m_debug) {
        const auto count = std::distance(m_element.tagsBegin(), m_element.tagsEnd());
        std::fill_n(std::back_inserter(m_infos), count, Info{ DebugKey, DebugCategory });
    }
}

QString OSMElementInformationModel::categoryLabel(OSMElementInformationModel::KeyCategory cat) const
{
    switch (cat) {
        case Main:
            return {};
        case DebugCategory:
            return QStringLiteral("Debug");
        case Accessibility:
            return tr("Accessibility");
        case Contact:
            return tr("Contact");
    }
    return {};
}

QString OSMElementInformationModel::debugTagKey(int row) const
{
    const auto tagCount = std::distance(m_element.tagsBegin(), m_element.tagsEnd());
    const auto tagIdx = row - (rowCount() - tagCount);
    return QString::fromUtf8((*(m_element.tagsBegin() + tagIdx)).key.name());
}

QString OSMElementInformationModel::debugTagValue(int row) const
{
    const auto tagCount = std::distance(m_element.tagsBegin(), m_element.tagsEnd());
    const auto tagIdx = row - (rowCount() - tagCount);
    return (*(m_element.tagsBegin() + tagIdx)).value;
}

QString OSMElementInformationModel::keyName(OSMElementInformationModel::Key key) const
{
    switch (key) {
        case Category: return {};
        case Cuisine: return tr("Cuisine");
        case OpeningHours: return tr("Opening hours");
        case Address: return tr("Address");
        case Phone: return tr("Phone");
        case Email: return tr("Email");
        case Website: return tr("Website");
        case Wheelchair: return tr("Wheelchair access");
        case DebugKey: return {};
    }
    return {};
}

// TODO expand this, see:
// - https://taginfo.openstreetmap.org/keys/?key=amenity#values
// - https://taginfo.openstreetmap.org/keys/?key=shop#values
// - https://taginfo.openstreetmap.org/keys/?key=tourism#values
// - parts of https://taginfo.openstreetmap.org/keys/?key=office#values
// - parts of https://taginfo.openstreetmap.org/keys/?key=room#values
struct {
    const char *code;
    const char *name;
} static constexpr const amenity_map[] = {
    { "atm",  QT_TRANSLATE_NOOP("amenity/shop", "ATM") },
    { "bakery",  QT_TRANSLATE_NOOP("amenity/shop", "Bakery") },
    { "bank",  QT_TRANSLATE_NOOP("amenity/shop", "Bank") },
    { "bar",  QT_TRANSLATE_NOOP("amenity/shop", "Bar") },
    { "beauty",  QT_TRANSLATE_NOOP("amenity/shop", "Beauty") },
    { "books",  QT_TRANSLATE_NOOP("amenity/shop", "Books") },
    { "cafe",  QT_TRANSLATE_NOOP("amenity/shop", "Cafe") },
    { "car_rental",  QT_TRANSLATE_NOOP("amenity/shop", "Car Rental") },
    { "chemist",  QT_TRANSLATE_NOOP("amenity/shop", "Chemist") },
    { "confectionery",  QT_TRANSLATE_NOOP("amenity/shop", "Confectionery") },
    { "clothes",  QT_TRANSLATE_NOOP("amenity/shop", "Clothes") },
    { "convenience",  QT_TRANSLATE_NOOP("amenity/shop", "Convenience Store") },
    { "fast_food",  QT_TRANSLATE_NOOP("amenity/shop", "Fast Food") },
    { "florist",  QT_TRANSLATE_NOOP("amenity/shop", "Florist") },
    { "gift",  QT_TRANSLATE_NOOP("amenity/shop", "Gift Shop") },
    { "hairdresser",  QT_TRANSLATE_NOOP("amenity/shop", "Hairdresser") },
    { "ice_cream",  QT_TRANSLATE_NOOP("amenity/shop", "Ice Cream") },
    { "jewelry",  QT_TRANSLATE_NOOP("amenity/shop", "Jewelry") },
    { "kiosk",  QT_TRANSLATE_NOOP("amenity/shop", "Kiosk") },
    { "mobile_phone",  QT_TRANSLATE_NOOP("amenity/shop", "Mobile Phone") },
    { "parking",  QT_TRANSLATE_NOOP("amenity/shop", "Parking") },
    { "pharmacy",  QT_TRANSLATE_NOOP("amenity/shop", "Pharmacy") },
    { "pub",  QT_TRANSLATE_NOOP("amenity/shop", "Pub") },
    { "restaurant",  QT_TRANSLATE_NOOP("amenity/shop", "Restaurant") },
    { "shoes",  QT_TRANSLATE_NOOP("amenity/shop", "Shoes") },
    { "supermarket",  QT_TRANSLATE_NOOP("amenity/shop", "Supermarket") },
    { "taxi",  QT_TRANSLATE_NOOP("amenity/shop", "Taxi") },
    { "toilets",  QT_TRANSLATE_NOOP("amenity/shop", "Toilets") },
    { "travel_agency",  QT_TRANSLATE_NOOP("amenity/shop", "Travel Agency") },
};

// TODO expand this, see https://taginfo.openstreetmap.org/keys/cuisine#values
struct {
    const char *code;
    const char *name;
} static constexpr const cuisine_map[] = {
    { "american", QT_TRANSLATE_NOOP("cuisine", "American") },
    { "asian", QT_TRANSLATE_NOOP("cuisine", "Asian") },
    { "barbecue", QT_TRANSLATE_NOOP("cuisine", "BBQ") },
    { "bbq", QT_TRANSLATE_NOOP("cuisine", "BBQ") },
    { "breakfast", QT_TRANSLATE_NOOP("cuisine", "Breakfast") },
    { "burger", QT_TRANSLATE_NOOP("cuisine", "Burger") },
    { "cake", QT_TRANSLATE_NOOP("cuisine", "Cake") },
    { "chicken", QT_TRANSLATE_NOOP("cuisine", "Chicken") },
    { "chinese", QT_TRANSLATE_NOOP("cuisine", "Chinese") },
    { "coffee_shop", QT_TRANSLATE_NOOP("cuisine", "Coffee Shop") },
    { "crepe", QT_TRANSLATE_NOOP("cuisine", "Crêpe") },
    { "donut", QT_TRANSLATE_NOOP("cuisine", "Donut") },
    { "fish", QT_TRANSLATE_NOOP("cuisine", "Fish") },
    { "fish_and_chips", QT_TRANSLATE_NOOP("cuisine", "Fish & Chips") },
    { "french", QT_TRANSLATE_NOOP("cuisine", "French") },
    { "german", QT_TRANSLATE_NOOP("cuisine", "German") },
    { "greek", QT_TRANSLATE_NOOP("cuisine", "Greek") },
    { "ice_cream", QT_TRANSLATE_NOOP("cuisine", "Ice Cream") },
    { "indian", QT_TRANSLATE_NOOP("cuisine", "Indian") },
    { "indonesian", QT_TRANSLATE_NOOP("cuisine", "Indonesian") },
    { "international", QT_TRANSLATE_NOOP("cuisine", "International") },
    { "italian", QT_TRANSLATE_NOOP("cuisine", "Italian") },
    { "italian_pizza", QT_TRANSLATE_NOOP("cuisine", "Pizza") },
    { "japanese", QT_TRANSLATE_NOOP("cuisine", "Japanese") },
    { "juice", QT_TRANSLATE_NOOP("cuisine", "Juice") },
    { "kebab", QT_TRANSLATE_NOOP("cuisine", "Kebab") },
    { "korean", QT_TRANSLATE_NOOP("cuisine", "Korean") },
    { "lebanese", QT_TRANSLATE_NOOP("cuisine", "Lebanese") },
    { "local", QT_TRANSLATE_NOOP("cuisine", "Local") },
    { "mediterranean", QT_TRANSLATE_NOOP("cuisine", "Mediterranean") },
    { "mexican", QT_TRANSLATE_NOOP("cuisine", "Mexican") },
    { "noodle", QT_TRANSLATE_NOOP("cuisine", "Noodle") },
    { "pancake", QT_TRANSLATE_NOOP("cuisine", "Pancake") },
    { "pasta", QT_TRANSLATE_NOOP("cuisine", "Pasta") },
    { "pizza", QT_TRANSLATE_NOOP("cuisine", "Pizza") },
    { "ramen", QT_TRANSLATE_NOOP("cuisine", "Ramen") },
    { "regional", QT_TRANSLATE_NOOP("cuisine", "Regional") },
    { "sandwich", QT_TRANSLATE_NOOP("cuisine", "Sandwich") },
    { "seafood", QT_TRANSLATE_NOOP("cuisine", "Seafood") },
    { "spanish", QT_TRANSLATE_NOOP("cuisine", "Spanish") },
    { "steak", QT_TRANSLATE_NOOP("cuisine", "Steak") },
    { "steak_house", QT_TRANSLATE_NOOP("cuisine", "Steak") },
    { "sushi", QT_TRANSLATE_NOOP("cuisine", "Sushi") },
    { "tapas", QT_TRANSLATE_NOOP("cuisine", "Tapas") },
    { "thai", QT_TRANSLATE_NOOP("cuisine", "Thai") },
    { "turkish", QT_TRANSLATE_NOOP("cuisine", "Turkish") },
    { "vegetarian", QT_TRANSLATE_NOOP("cuisine", "Vegetarian") },
    { "vietnamese", QT_TRANSLATE_NOOP("cuisine", "Vietnamese") },
};

QVariant OSMElementInformationModel::valueForKey(OSMElementInformationModel::Key key) const
{
    switch (key) {
        case Category:
        {
            QStringList l;
            l += m_element.tagValue("amenity").split(QLatin1Char(';'), Qt::SkipEmptyParts);
            l += m_element.tagValue("shop").split(QLatin1Char(';'), Qt::SkipEmptyParts);
            l += m_element.tagValue("tourism").split(QLatin1Char(';'), Qt::SkipEmptyParts);
            l += m_element.tagValue("office").split(QLatin1Char(';'), Qt::SkipEmptyParts);
            if (l.isEmpty()) {
                l += m_element.tagValue("room").split(QLatin1Char(';'), Qt::SkipEmptyParts);
            }

            // TODO drop general categories if specific ones are available (e.g. restaurant vs fast_food)

            for (auto it = l.begin(); it != l.end();) {
                if ((*it) == QLatin1String("yes")) {
                    it = l.erase(it);
                    continue;
                }
                const auto s = (*it).toUtf8();
                for (const auto &a : amenity_map) {
                    if (std::strcmp(s.constData(), a.code) == 0) {
                        (*it) = tr(a.name, "amenity/shop");
                        break;
                    }
                }
                ++it;
            }

            std::sort(l.begin(), l.end());
            l.erase(std::unique(l.begin(), l.end()), l.end());
            return QLocale().createSeparatedList(l);
        }
        case Cuisine:
        {
            auto l = m_element.tagValue("cuisine").split(QLatin1Char(';'));
            for (auto &s : l) {
                const auto code = s.toUtf8();
                for (const auto &c : cuisine_map) {
                    if (std::strcmp(code.constData(), c.code) == 0) {
                        s = tr(c.name, "cuisine");
                        break;
                    }
                }
            }
            std::sort(l.begin(), l.end());
            return QLocale().createSeparatedList(l);
        }
        case OpeningHours: return m_element.tagValue("opening_hours");
        case Address: return QVariant::fromValue(OSMAddress(m_element));
        case Phone: return m_element.tagValue("contact:phone", "phone"); // TODO make this a link
        case Email: return m_element.tagValue("contact:email"); // TODO make this a link
        case Website:
            return m_element.tagValue("website", "contact:website", "url");
        case Wheelchair:
        {
            const auto a = m_element.tagValue("wheelchair"); // TODO decode and translate
            const auto d = m_element.tagValue("wheelchair:description", QLocale());
            if (!d.isEmpty()) {
                return QString(a + QLatin1String(" (") + d + QLatin1Char(')'));
            }
            return a;
        }
        case DebugKey: return {};
    }
    return {};
}
