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
    OSMElementInformationModel::String,        // Operator
    OSMElementInformationModel::Link,          // DebugLink
    OSMElementInformationModel::String,        // DebugKey
};

static_assert((sizeof(type_map) / sizeof(type_map[0])) == OSMElementInformationModel::DebugKey + 1, "");

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

QString OSMElementInformationModel::name() const
{
    const auto n = m_element.tagValue("name", QLocale());
    if (!n.isEmpty()) {
        return n;
    }
    return valueForKey(Category).toString();
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
        case ValueUrlRole:
            return urlify(valueForKey(info.key).toString(), info.key);
        case CategoryRole:
            return info.category;
        case CategoryLabelRole:
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
    r.insert(ValueUrlRole, "url");
    r.insert(CategoryRole, "category");
    r.insert(CategoryLabelRole, "categoryLabel");
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
    M("email", Email, Contact),
    M("phone", Phone, Contact),
    M("office", Category, Main),
    M("opening_hours", OpeningHours, Main),
    M("operator", OperatorName, Operator),
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
    bool hasName = false;
    for (auto it = m_element.tagsBegin(); it != m_element.tagsEnd(); ++it) {
        if (std::strncmp((*it).key.name(), "name", 4) == 0) {
            hasName = true;
            continue;
        }
        for (const auto &simpleKey : simple_key_map) {
            if (std::strcmp((*it).key.name(), simpleKey.name) == 0 && !std::any_of(m_infos.begin(), m_infos.end(), [simpleKey](auto info) { return info.key == simpleKey.key; })) {
                m_infos.push_back(Info{simpleKey.key, simpleKey.category});
                break;
            }
        }
    }

    std::sort(m_infos.begin(), m_infos.end());

    // we use the categories as header if there is no name, so don't duplicate that
    if (!hasName && !m_infos.empty() && m_infos[0].key == Category) {
        m_infos.erase(m_infos.begin());
    }

    if (m_debug) {
        m_infos.push_back(Info{ DebugLink, DebugCategory });
        const auto count = std::distance(m_element.tagsBegin(), m_element.tagsEnd());
        std::fill_n(std::back_inserter(m_infos), count, Info{ DebugKey, DebugCategory });
    }
}

QString OSMElementInformationModel::categoryLabel(OSMElementInformationModel::KeyCategory cat) const
{
    switch (cat) {
        case Main:          return {};
        case Contact:       return tr("Contact");
        case Accessibility: return tr("Accessibility");
        case Operator:      return tr("Operator");
        case DebugCategory: return QStringLiteral("Debug");
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
        case OperatorName: return {};
        case DebugLink: return QStringLiteral("OSM");
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
    { "alcohol",  QT_TRANSLATE_NOOP("amenity/shop", "Alcohol") },
    { "atm",  QT_TRANSLATE_NOOP("amenity/shop", "ATM") },
    { "bakery",  QT_TRANSLATE_NOOP("amenity/shop", "Bakery") },
    { "bank",  QT_TRANSLATE_NOOP("amenity/shop", "Bank") },
    { "bar",  QT_TRANSLATE_NOOP("amenity/shop", "Bar") },
    { "beauty",  QT_TRANSLATE_NOOP("amenity/shop", "Beauty") },
    { "bicycle",  QT_TRANSLATE_NOOP("amenity/shop", "Bicycle") },
    { "bicycle_parking",  QT_TRANSLATE_NOOP("amenity/shop", "Bicycle Parking") },
    { "bicycle_rental",  QT_TRANSLATE_NOOP("amenity/shop", "Bicycle Rental") },
    { "bureau_de_change", QT_TRANSLATE_NOOP("amenity/shop", "Bureau de Change") },
    { "books",  QT_TRANSLATE_NOOP("amenity/shop", "Books") },
    { "boutique",  QT_TRANSLATE_NOOP("amenity/shop", "Boutique") },
    { "butcher",  QT_TRANSLATE_NOOP("amenity/shop", "Butcher") },
    { "cafe",  QT_TRANSLATE_NOOP("amenity/shop", "Cafe") },
    { "car_rental",  QT_TRANSLATE_NOOP("amenity/shop", "Car Rental") },
    { "chemist",  QT_TRANSLATE_NOOP("amenity/shop", "Chemist") },
    { "chocolate",  QT_TRANSLATE_NOOP("amenity/shop", "Chocolate") },
    { "cinema",  QT_TRANSLATE_NOOP("amenity/shop", "Cinema") },
    { "clothes",  QT_TRANSLATE_NOOP("amenity/shop", "Clothes") },
    { "coffee",  QT_TRANSLATE_NOOP("amenity/shop", "Coffee") },
    { "computer",  QT_TRANSLATE_NOOP("amenity/shop", "Computer") },
    { "confectionery",  QT_TRANSLATE_NOOP("amenity/shop", "Confectionery") },
    { "convenience",  QT_TRANSLATE_NOOP("amenity/shop", "Convenience Store") },
    { "cosmetics",  QT_TRANSLATE_NOOP("amenity/shop", "Cosmetics") },
    { "deli", QT_TRANSLATE_NOOP("amenity/shop", "Deli") },
    { "department_store", QT_TRANSLATE_NOOP("amenity/shop", "Department Store") },
    { "doctors", QT_TRANSLATE_NOOP("amenity/shop", "Doctor") },
    { "dry_cleaning",  QT_TRANSLATE_NOOP("amenity/shop", "Dry Cleaning") },
    { "electronics",  QT_TRANSLATE_NOOP("amenity/shop", "Electronics") },
    { "fashion",  QT_TRANSLATE_NOOP("amenity/shop", "Fashion") },
    { "fast_food",  QT_TRANSLATE_NOOP("amenity/shop", "Fast Food") },
    { "florist",  QT_TRANSLATE_NOOP("amenity/shop", "Florist") },
    { "food_court",  QT_TRANSLATE_NOOP("amenity/shop", "Food Court") },
    { "furniture",  QT_TRANSLATE_NOOP("amenity/shop", "Furniture") },
    { "gift",  QT_TRANSLATE_NOOP("amenity/shop", "Gift Shop") },
    { "hairdresser",  QT_TRANSLATE_NOOP("amenity/shop", "Hairdresser") },
    { "hospital",  QT_TRANSLATE_NOOP("amenity/shop", "Hospital") },
    { "hostel",  QT_TRANSLATE_NOOP("amenity/shop", "Hostel") },
    { "hotel",  QT_TRANSLATE_NOOP("amenity/shop", "Hotel") },
    { "ice_cream",  QT_TRANSLATE_NOOP("amenity/shop", "Ice Cream") },
    { "information",  QT_TRANSLATE_NOOP("amenity/shop", "Information") },
    { "jewelry",  QT_TRANSLATE_NOOP("amenity/shop", "Jewelry") },
    { "kiosk",  QT_TRANSLATE_NOOP("amenity/shop", "Kiosk") },
    { "laundry",  QT_TRANSLATE_NOOP("amenity/shop", "Laundry") },
    { "lockers",  QT_TRANSLATE_NOOP("amenity/shop", "Locker") },
    { "locksmith",  QT_TRANSLATE_NOOP("amenity/shop", "Locksmith") },
    { "lost_and_found",  QT_TRANSLATE_NOOP("amenity/shop", "Lost & Found") },
    { "lost_property",  QT_TRANSLATE_NOOP("amenity/shop", "Lost & Found") },
    { "luggage_locker",  QT_TRANSLATE_NOOP("amenity/shop", "Locker") },
    { "mall",  QT_TRANSLATE_NOOP("amenity/shop", "Mall") },
    { "mobile_phone",  QT_TRANSLATE_NOOP("amenity/shop", "Mobile Phone") },
    { "museum",  QT_TRANSLATE_NOOP("amenity/shop", "Museum") },
    { "newsagent",  QT_TRANSLATE_NOOP("amenity/shop", "Newsagent") },
    { "office",  QT_TRANSLATE_NOOP("amenity/shop", "Office") },
    { "optician",  QT_TRANSLATE_NOOP("amenity/shop", "Optician") },
    { "parking",  QT_TRANSLATE_NOOP("amenity/shop", "Parking") },
    { "pastry",  QT_TRANSLATE_NOOP("amenity/shop", "Pastry") },
    { "perfumery",  QT_TRANSLATE_NOOP("amenity/shop", "Perfumery") },
    { "pet",  QT_TRANSLATE_NOOP("amenity/shop", "Pet") },
    { "pharmacy",  QT_TRANSLATE_NOOP("amenity/shop", "Pharmacy") },
    { "police",  QT_TRANSLATE_NOOP("amenity/shop", "Police") },
    { "post_office",  QT_TRANSLATE_NOOP("amenity/shop", "Post Office") },
    { "pub",  QT_TRANSLATE_NOOP("amenity/shop", "Pub") },
    { "restaurant",  QT_TRANSLATE_NOOP("amenity/shop", "Restaurant") },
    { "school",  QT_TRANSLATE_NOOP("amenity/shop", "School") },
    { "shoes",  QT_TRANSLATE_NOOP("amenity/shop", "Shoes") },
    { "shop",  QT_TRANSLATE_NOOP("amenity/shop", "Shop") },
    { "social_facility",  QT_TRANSLATE_NOOP("amenity/shop", "Social Facility") },
    { "souveniers",  QT_TRANSLATE_NOOP("amenity/shop", "Souveniers") },
    { "supermarket",  QT_TRANSLATE_NOOP("amenity/shop", "Supermarket") },
    { "stationery",  QT_TRANSLATE_NOOP("amenity/shop", "Stationery") },
    { "tailor",  QT_TRANSLATE_NOOP("amenity/shop", "Tailor") },
    { "tatoo",  QT_TRANSLATE_NOOP("amenity/shop", "Tattoo") },
    { "taxi",  QT_TRANSLATE_NOOP("amenity/shop", "Taxi") },
    { "tea",  QT_TRANSLATE_NOOP("amenity/shop", "Tea") },
    { "ticket",  QT_TRANSLATE_NOOP("amenity/shop", "Ticket") },
    { "tobacco",  QT_TRANSLATE_NOOP("amenity/shop", "Tobacco") },
    { "toilets",  QT_TRANSLATE_NOOP("amenity/shop", "Toilets") },
    { "toys",  QT_TRANSLATE_NOOP("amenity/shop", "Toys") },
    { "travel_agency",  QT_TRANSLATE_NOOP("amenity/shop", "Travel Agency") },
    { "waiting",  QT_TRANSLATE_NOOP("amenity/shop", "Waiting Area") },
    { "waiting_area",  QT_TRANSLATE_NOOP("amenity/shop", "Waiting Area") },
};

// TODO expand this, see https://taginfo.openstreetmap.org/keys/cuisine#values
struct {
    const char *code;
    const char *name;
} static constexpr const cuisine_map[] = {
    { "american", QT_TRANSLATE_NOOP("cuisine", "American") },
    { "arab", QT_TRANSLATE_NOOP("cuisine", "Arab") },
    { "asian", QT_TRANSLATE_NOOP("cuisine", "Asian") },
    { "barbecue", QT_TRANSLATE_NOOP("cuisine", "BBQ") },
    { "bbq", QT_TRANSLATE_NOOP("cuisine", "BBQ") },
    { "breakfast", QT_TRANSLATE_NOOP("cuisine", "Breakfast") },
    { "burger", QT_TRANSLATE_NOOP("cuisine", "Burger") },
    { "cake", QT_TRANSLATE_NOOP("cuisine", "Cake") },
    { "chicken", QT_TRANSLATE_NOOP("cuisine", "Chicken") },
    { "chinese", QT_TRANSLATE_NOOP("cuisine", "Chinese") },
    { "coffee_shop", QT_TRANSLATE_NOOP("cuisine", "Coffee Shop") },
    { "cookies", QT_TRANSLATE_NOOP("cuisine", "Cookies") },
    { "crepe", QT_TRANSLATE_NOOP("cuisine", "Crêpe") },
    { "donut", QT_TRANSLATE_NOOP("cuisine", "Donut") },
    { "falafel", QT_TRANSLATE_NOOP("cuisine", "Falafel") },
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
    { "pakistani",  QT_TRANSLATE_NOOP("cuisine", "Pakistani") },
    { "pancake", QT_TRANSLATE_NOOP("cuisine", "Pancake") },
    { "pasta", QT_TRANSLATE_NOOP("cuisine", "Pasta") },
    { "pizza", QT_TRANSLATE_NOOP("cuisine", "Pizza") },
    { "polish", QT_TRANSLATE_NOOP("cuisine", "Polish") },
    { "portuguese", QT_TRANSLATE_NOOP("cuisine", "Portuguese") },
    { "ramen", QT_TRANSLATE_NOOP("cuisine", "Ramen") },
    { "regional", QT_TRANSLATE_NOOP("cuisine", "Regional") },
    { "salad", QT_TRANSLATE_NOOP("cuisine", "Salad") },
    { "sandwich", QT_TRANSLATE_NOOP("cuisine", "Sandwich") },
    { "sausage", QT_TRANSLATE_NOOP("cuisine", "Sausage") },
    { "seafood", QT_TRANSLATE_NOOP("cuisine", "Seafood") },
    { "soup", QT_TRANSLATE_NOOP("cuisine", "Soup") },
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
                (*it) = (*it).trimmed();
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
        case Phone: return m_element.tagValue("contact:phone", "phone");
        case Email: return m_element.tagValue("contact:email", "email");
        case Website: return m_element.tagValue("website", "contact:website", "url");
        case Wheelchair:
        {
            const auto a = m_element.tagValue("wheelchair"); // TODO decode and translate
            const auto d = m_element.tagValue("wheelchair:description", QLocale());
            if (!d.isEmpty()) {
                return QString(a + QLatin1String(" (") + d + QLatin1Char(')'));
            }
            return a;
        }
        case OperatorName: return m_element.tagValue("operator");
        case DebugLink: return m_element.url();
        case DebugKey: return {};
    }
    return {};
}

QString OSMElementInformationModel::urlify(const QString& s, OSMElementInformationModel::Key key) const
{
    switch (key) {
        case Email:
            if (!s.startsWith(QLatin1String("mailto:"))) {
                return QLatin1String("mailto:") + s;
            }
            return s;
        case Phone:
        {
            if (s.startsWith(QLatin1String("tel:"))) {
                return s;
            }
            QString e = QLatin1String("tel:") + s;
            e.remove(QLatin1Char(' '));
            return e;
        }
        case Website:
        case DebugLink:
            if (s.startsWith(QLatin1String("http"))) {
                return s;
            }
            return QLatin1String("https://") + s;
        default:
            return {};
    }

    return {};
}
