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

void OSMElementInformationModel::clear()
{
    if (m_element.type() == OSM::Type::Null) {
        return;
    }
    beginResetModel();
    m_infos.clear();
    m_element = {};
    endResetModel();
    emit elementChanged();
}

QString OSMElementInformationModel::name() const
{
    return valueForKey(m_nameKey).toString();
}

QString OSMElementInformationModel::category() const
{
    return valueForKey(m_categoryKey).toString();
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
            switch (info.key) {
                case Wikipedia:
                case Phone:
                case Email:
                case Website:
                case OperatorWikipedia:
                case DebugLink:
                    return Link;
                case Address:
                    return PostalAddress;
                case OpeningHours:
                    return OpeningHoursType;
                default:
                    return String;
            }
        case KeyRole:
            return info.key;
        case KeyLabelRole:
            if (info.key == DebugKey) {
                return debugTagKey(index.row());
            }
            return keyName(info.key);
        case ValueRole:
            switch (info.key) {
                case DebugKey: return debugTagValue(index.row());
                case Wikipedia: return tr("Wikipedia");
                default: return valueForKey(info.key);
            }
        case ValueUrlRole:
            return urlify(valueForKey(info.key), info.key);
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
    M("brand:wikipedia", Wikipedia, Main),
    M("centralkey", CentralKey, Accessibility),
    M("changing_table", DiaperChangingTable, Main),
    M("charge", Fee, Main),
    M("contact:city", Address, Contact),
    M("contact:email", Email, Contact),
    M("contact:phone", Phone, Contact),
    M("contact:street", Address, Contact),
    M("contact:website", Website, Contact),
    M("cuisine", Cuisine, Main),
    M("diaper", DiaperChangingTable, Main),
    M("email", Email, Contact),
    M("fee", Fee, Main),
    M("payment:cash", PaymentCash, Payment),
    M("payment:coins", PaymentCash, Payment),
    M("payment:notes", PaymentCash, Payment),
    M("phone", Phone, Contact),
    M("office", Category, Main),
    M("old_name", OldName, Main),
    M("opening_hours", OpeningHours, Main),
    M("operator", OperatorName, Operator),
    M("operator:wikipedia", OperatorWikipedia, Operator),
    M("room", Category, Main),
    M("url", Website, Contact),
    M("shop", Category, Main),
    M("takeaway", Takeaway, Main),
    M("tourism", Category, Main),
    M("website", Website, Contact),
    M("wheelchair", Wheelchair, Accessibility),
};
#undef M

// generic payment types (excluding cash, that's handled separately)
struct {
    const char *name;
    OSMElementInformationModel::Key key;
} static constexpr const payment_generic_type_map[] = {
    { "payment:account_cards", OSMElementInformationModel::PaymentDebitCard },
    { "payment:credit_cards", OSMElementInformationModel::PaymentCreditCard },
    { "payment:debit_cards", OSMElementInformationModel::PaymentDebitCard },
    { "payment:electronic_purses", OSMElementInformationModel::PaymentStoredValueCard },
};

// payment vendor types only, generic ones go into the list above and are handled separately
struct {
    const char *name;
    OSMElementInformationModel::Key key;
    const char *label;
} static constexpr const payment_type_map[] = {
    { "payment:american_express", OSMElementInformationModel::PaymentCreditCard, QT_TRANSLATE_NOOP("payment method", "American Express") },
    { "payment:apple_pay", OSMElementInformationModel::PaymentDigital, QT_TRANSLATE_NOOP("payment method", "Apple Pay") },
    { "payment:diners_club", OSMElementInformationModel::PaymentCreditCard, QT_TRANSLATE_NOOP("payment method", "Diners Club") },
    { "payment:discover_card", OSMElementInformationModel::PaymentCreditCard, QT_TRANSLATE_NOOP("payment method", "Discover Card") },
    { "payment:jcb", OSMElementInformationModel::PaymentCreditCard, QT_TRANSLATE_NOOP("payment method", "JCB") },
    { "payment:girocard", OSMElementInformationModel::PaymentDebitCard, QT_TRANSLATE_NOOP("payment method", "Girocard") },
    { "payment:google_pay", OSMElementInformationModel::PaymentDigital, QT_TRANSLATE_NOOP("payment method", "Google Pay") },
    { "payment:maestro", OSMElementInformationModel::PaymentDebitCard, QT_TRANSLATE_NOOP("payment method", "Maestro") },
    { "payment:mastercard", OSMElementInformationModel::PaymentCreditCard, QT_TRANSLATE_NOOP("payment method", "Mastercard") },
    { "payment:unionpay", OSMElementInformationModel::PaymentCreditCard, QT_TRANSLATE_NOOP("payment method", "UnionPay") },
    { "payment:v_pay", OSMElementInformationModel::PaymentCreditCard, QT_TRANSLATE_NOOP("payment method", "V Pay") },
    { "payment:vpay", OSMElementInformationModel::PaymentCreditCard, QT_TRANSLATE_NOOP("payment method", "V Pay") },
    { "payment:visa", OSMElementInformationModel::PaymentCreditCard, QT_TRANSLATE_NOOP("payment method", "Visa") },
};

// diet types offered at restaurants
struct {
    const char *name;
    const char *label;
} static constexpr const diet_type_map[] = {
    { "diet:gluten_free", QT_TRANSLATE_NOOP("diet type", "gluten free") },
    { "diet:halal", QT_TRANSLATE_NOOP("diet type", "halal") },
    { "diet:kosher", QT_TRANSLATE_NOOP("diet type", "kosher") },
    { "diet:lactose_free", QT_TRANSLATE_NOOP("diet type", "lactose free") },
    { "diet:vegan", QT_TRANSLATE_NOOP("diet type", "vegan") },
    { "diet:vegetarian", QT_TRANSLATE_NOOP("diet type", "vegetarian") },
};

void OSMElementInformationModel::reload()
{
    m_nameKey = NoKey;
    m_categoryKey = NoKey;

    for (auto it = m_element.tagsBegin(); it != m_element.tagsEnd(); ++it) {
        if (std::strncmp((*it).key.name(), "name", 4) == 0) {
            m_nameKey = Name;
            continue;
        }
        if (std::strncmp((*it).key.name(), "wikipedia", 9) == 0 && !std::any_of(m_infos.begin(), m_infos.end(), [](auto info) { return info.key == Wikipedia; })) {
            m_infos.push_back(Info{Wikipedia, Main});
            continue;
        }
        for (const auto &simpleKey : simple_key_map) {
            if (std::strcmp((*it).key.name(), simpleKey.name) == 0 && !std::any_of(m_infos.begin(), m_infos.end(), [simpleKey](auto info) { return info.key == simpleKey.key; })) {
                m_infos.push_back(Info{simpleKey.key, simpleKey.category});
                break;
            }
        }
        for (const auto &payment : payment_generic_type_map) {
            if (std::strcmp((*it).key.name(), payment.name) == 0 && !std::any_of(m_infos.begin(), m_infos.end(), [payment](auto info) { return info.key == payment.key; })) {
                m_infos.push_back(Info{payment.key, Payment});
                break;
            }
        }
        for (const auto &payment : payment_type_map) {
            if (std::strcmp((*it).key.name(), payment.name) == 0 && !std::any_of(m_infos.begin(), m_infos.end(), [payment](auto info) { return info.key == payment.key; })) {
                m_infos.push_back(Info{payment.key, Payment});
                break;
            }
        }
        for (const auto &diet: diet_type_map) {
            if (std::strcmp((*it).key.name(), diet.name) == 0 && !std::any_of(m_infos.begin(), m_infos.end(), [](auto info) { return info.key == Diet; })) {
                m_infos.push_back(Info{Diet, Main});
                break;
            }
        }
    }

    std::sort(m_infos.begin(), m_infos.end());

    // we use the categories as header if there is no name, so don't duplicate that
    if (!m_infos.empty() && m_infos[0].key == Category) {
        m_infos.erase(m_infos.begin());
        if (m_nameKey == NoKey) {
            m_nameKey = Category;
        } else {
            m_categoryKey = Category;
        }
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
        case Header:
        case Main:          return {};
        case Contact:       return tr("Contact");
        case Payment:       return tr("Payment");
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
    return QString::fromUtf8((*(m_element.tagsBegin() + tagIdx)).value);
}

QString OSMElementInformationModel::keyName(OSMElementInformationModel::Key key) const
{
    switch (key) {
        case NoKey:
        case Name:
        case Category: return {};
        case OldName: return tr("Fomerly");
        case Cuisine: return tr("Cuisine");
        case Diet: return tr("Diet");
        case Takeaway: return tr("Takeaway");
        case OpeningHours: return tr("Opening hours");
        case Fee: return tr("Fee");
        case DiaperChangingTable: return tr("Diaper changing table");
        case Wikipedia: return {};
        case Address: return tr("Address");
        case Phone: return tr("Phone");
        case Email: return tr("Email");
        case Website: return tr("Website");
        case PaymentCash: return tr("Cash");
        case PaymentDigital: return tr("Digital");
        case PaymentDebitCard: return tr("Debit cards");
        case PaymentCreditCard: return tr("Credit cards");
        case PaymentStoredValueCard: return tr("Stored value cards");
        case Wheelchair: return tr("Wheelchair access");
        case CentralKey: return tr("Central key");
        case OperatorName: return {};
        case OperatorWikipedia: return {};
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
    { "attraction", QT_TRANSLATE_NOOP("amenity/shop", "Attraction") },
    { "bakery",  QT_TRANSLATE_NOOP("amenity/shop", "Bakery") },
    { "bag", QT_TRANSLATE_NOOP("amenity/shop", "Bag") },
    { "bank",  QT_TRANSLATE_NOOP("amenity/shop", "Bank") },
    { "bar",  QT_TRANSLATE_NOOP("amenity/shop", "Bar") },
    { "beauty",  QT_TRANSLATE_NOOP("amenity/shop", "Beauty") },
    { "beverages", QT_TRANSLATE_NOOP("amenity/shop", "Beverages") },
    { "bicycle",  QT_TRANSLATE_NOOP("amenity/shop", "Bicycle") },
    { "bicycle_parking",  QT_TRANSLATE_NOOP("amenity/shop", "Bicycle Parking") },
    { "bicycle_rental",  QT_TRANSLATE_NOOP("amenity/shop", "Bicycle Rental") },
    { "bureau_de_change", QT_TRANSLATE_NOOP("amenity/shop", "Bureau de Change") },
    { "books",  QT_TRANSLATE_NOOP("amenity/shop", "Books") },
    { "boutique",  QT_TRANSLATE_NOOP("amenity/shop", "Boutique") },
    { "butcher",  QT_TRANSLATE_NOOP("amenity/shop", "Butcher") },
    { "cafe",  QT_TRANSLATE_NOOP("amenity/shop", "Cafe") },
    { "car_rental",  QT_TRANSLATE_NOOP("amenity/shop", "Car Rental") },
    { "car_sharing", QT_TRANSLATE_NOOP("amenity/shop", "Car Sharing") },
    { "chemist",  QT_TRANSLATE_NOOP("amenity/shop", "Chemist") },
    { "chocolate",  QT_TRANSLATE_NOOP("amenity/shop", "Chocolate") },
    { "cinema",  QT_TRANSLATE_NOOP("amenity/shop", "Cinema") },
    { "clothes",  QT_TRANSLATE_NOOP("amenity/shop", "Clothes") },
    { "coffee",  QT_TRANSLATE_NOOP("amenity/shop", "Coffee") },
    { "computer",  QT_TRANSLATE_NOOP("amenity/shop", "Computer") },
    { "confectionery",  QT_TRANSLATE_NOOP("amenity/shop", "Confectionery") },
    { "convenience",  QT_TRANSLATE_NOOP("amenity/shop", "Convenience Store") },
    { "copyshop", QT_TRANSLATE_NOOP("amenity/shop", "Copy Shop") },
    { "cosmetics",  QT_TRANSLATE_NOOP("amenity/shop", "Cosmetics") },
    { "courthouse", QT_TRANSLATE_NOOP("amenity/shop", "Court House") },
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
    { "guest_house", QT_TRANSLATE_NOOP("amenity/shop", "Guest House") },
    { "hairdresser",  QT_TRANSLATE_NOOP("amenity/shop", "Hairdresser") },
    { "hospital",  QT_TRANSLATE_NOOP("amenity/shop", "Hospital") },
    { "hostel",  QT_TRANSLATE_NOOP("amenity/shop", "Hostel") },
    { "hotel",  QT_TRANSLATE_NOOP("amenity/shop", "Hotel") },
    { "ice_cream",  QT_TRANSLATE_NOOP("amenity/shop", "Ice Cream") },
    { "information",  QT_TRANSLATE_NOOP("amenity/shop", "Information") },
    { "interior_decoration",  QT_TRANSLATE_NOOP("amenity/shop", "Interior Decoration") },
    { "jewelry",  QT_TRANSLATE_NOOP("amenity/shop", "Jewelry") },
    { "kiosk",  QT_TRANSLATE_NOOP("amenity/shop", "Kiosk") },
    { "laundry",  QT_TRANSLATE_NOOP("amenity/shop", "Laundry") },
    { "library", QT_TRANSLATE_NOOP("amenity/shop", "Library") },
    { "lockers",  QT_TRANSLATE_NOOP("amenity/shop", "Locker") },
    { "locksmith",  QT_TRANSLATE_NOOP("amenity/shop", "Locksmith") },
    { "lost_and_found",  QT_TRANSLATE_NOOP("amenity/shop", "Lost & Found") },
    { "lost_property",  QT_TRANSLATE_NOOP("amenity/shop", "Lost & Found") },
    { "luggage_locker",  QT_TRANSLATE_NOOP("amenity/shop", "Locker") },
    { "mall",  QT_TRANSLATE_NOOP("amenity/shop", "Mall") },
    { "mobile_phone",  QT_TRANSLATE_NOOP("amenity/shop", "Mobile Phone") },
    { "money_transfer", QT_TRANSLATE_NOOP("amenity/shop", "Money Transfer") },
    { "museum",  QT_TRANSLATE_NOOP("amenity/shop", "Museum") },
    { "newsagent",  QT_TRANSLATE_NOOP("amenity/shop", "Newsagent") },
    { "office",  QT_TRANSLATE_NOOP("amenity/shop", "Office") },
    { "optician",  QT_TRANSLATE_NOOP("amenity/shop", "Optician") },
    { "outdoor", QT_TRANSLATE_NOOP("amenity/shop", "Outdoor") },
    { "parking",  QT_TRANSLATE_NOOP("amenity/shop", "Parking") },
    { "pastry",  QT_TRANSLATE_NOOP("amenity/shop", "Pastry") },
    { "perfumery",  QT_TRANSLATE_NOOP("amenity/shop", "Perfumery") },
    { "pet",  QT_TRANSLATE_NOOP("amenity/shop", "Pet") },
    { "pharmacy",  QT_TRANSLATE_NOOP("amenity/shop", "Pharmacy") },
    { "photo", QT_TRANSLATE_NOOP("amenity/shop", "Photo") },
    { "place_of_worship", QT_TRANSLATE_NOOP("amenity/shop", "Place of Worship") },
    { "police",  QT_TRANSLATE_NOOP("amenity/shop", "Police") },
    { "post_box", QT_TRANSLATE_NOOP("amenity/shop", "Post Box") },
    { "post_office",  QT_TRANSLATE_NOOP("amenity/shop", "Post Office") },
    { "pub",  QT_TRANSLATE_NOOP("amenity/shop", "Pub") },
    { "public_transport_tickets", QT_TRANSLATE_NOOP("amenity/shop", "Public Transport Tickets") },
    { "restaurant",  QT_TRANSLATE_NOOP("amenity/shop", "Restaurant") },
    { "school",  QT_TRANSLATE_NOOP("amenity/shop", "School") },
    { "shoes",  QT_TRANSLATE_NOOP("amenity/shop", "Shoes") },
    { "shop",  QT_TRANSLATE_NOOP("amenity/shop", "Shop") },
    { "social_facility",  QT_TRANSLATE_NOOP("amenity/shop", "Social Facility") },
    { "souveniers",  QT_TRANSLATE_NOOP("amenity/shop", "Souveniers") },
    { "sports", QT_TRANSLATE_NOOP("amenity/shop", "Sports") },
    { "supermarket",  QT_TRANSLATE_NOOP("amenity/shop", "Supermarket") },
    { "stationery",  QT_TRANSLATE_NOOP("amenity/shop", "Stationery") },
    { "tailor",  QT_TRANSLATE_NOOP("amenity/shop", "Tailor") },
    { "tatoo",  QT_TRANSLATE_NOOP("amenity/shop", "Tattoo") },
    { "taxi",  QT_TRANSLATE_NOOP("amenity/shop", "Taxi") },
    { "tea",  QT_TRANSLATE_NOOP("amenity/shop", "Tea") },
    { "theatre", QT_TRANSLATE_NOOP("amenity/shop", "Theatre") },
    { "ticket",  QT_TRANSLATE_NOOP("amenity/shop", "Tickets") },
    { "tobacco",  QT_TRANSLATE_NOOP("amenity/shop", "Tobacco") },
    { "toilets",  QT_TRANSLATE_NOOP("amenity/shop", "Toilets") },
    { "toys",  QT_TRANSLATE_NOOP("amenity/shop", "Toys") },
    { "travel_agency",  QT_TRANSLATE_NOOP("amenity/shop", "Travel Agency") },
    { "university", QT_TRANSLATE_NOOP("amenity/shop", "University") },
    { "waiting",  QT_TRANSLATE_NOOP("amenity/shop", "Waiting Area") },
    { "waiting_area",  QT_TRANSLATE_NOOP("amenity/shop", "Waiting Area") },
    { "waiting_room", QT_TRANSLATE_NOOP("amenity/shop", "Waiting Area") },
    { "wine", QT_TRANSLATE_NOOP("amenity/shop", "Wine") },
};

// TODO expand this, see https://taginfo.openstreetmap.org/keys/cuisine#values
struct {
    const char *code;
    const char *name;
} static constexpr const cuisine_map[] = {
    { "american", QT_TRANSLATE_NOOP("cuisine", "American") },
    { "arab", QT_TRANSLATE_NOOP("cuisine", "Arab") },
    { "argentinian", QT_TRANSLATE_NOOP("cuisine", "Argentinian") },
    { "asian", QT_TRANSLATE_NOOP("cuisine", "Asian") },
    { "austrian", QT_TRANSLATE_NOOP("cuisine", "Austrian") },
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
        case NoKey: return {};
        case Name: return QString::fromUtf8(m_element.tagValue("name", QLocale()));
        case Category:
        {
            QList<QByteArray> l;
            l += m_element.tagValue("amenity").split(';');
            l += m_element.tagValue("shop").split(';');
            l += m_element.tagValue("tourism").split(';');
            l += m_element.tagValue("vending").split(';');
            l += m_element.tagValue("office").split(';');
            if (l.isEmpty()) {
                l += m_element.tagValue("room").split(';');
            }
            QStringList out;
            out.reserve(l.size());

            // TODO drop general categories if specific ones are available (e.g. restaurant vs fast_food)

            for (auto it = l.begin(); it != l.end();++it) {
                (*it) = (*it).trimmed();
                if ((*it).isEmpty() || (*it) == "yes" || (*it) == "vending_machine") {
                    continue;
                }
                bool found = false;
                for (const auto &a : amenity_map) {
                    if (std::strcmp((*it).constData(), a.code) == 0) {
                        found = true;
                        out.push_back(tr(a.name, "amenity/shop"));
                        break;
                    }
                }
                if (!found) {
                    out.push_back(QString::fromUtf8(*it));
                }
            }

            std::sort(out.begin(), out.end());
            out.erase(std::unique(out.begin(), out.end()), out.end());
            return QLocale().createSeparatedList(out);
        }
        case OldName: return QString::fromUtf8(m_element.tagValue("old_name"));
        case Cuisine:
        {
            auto l = m_element.tagValue("cuisine").split(';');
            QStringList out;
            out.reserve(l.size());
            for (auto &code : l) {
                bool found = false;
                for (const auto &c : cuisine_map) {
                    if (std::strcmp(code.constData(), c.code) == 0) {
                        found = true;
                        out.push_back(tr(c.name, "cuisine"));
                        break;
                    }
                }
                if (!found) {
                    out.push_back(QString::fromUtf8(code));
                }
            }
            std::sort(out.begin(), out.end());
            return QLocale().createSeparatedList(out);
        }
        case Diet:
        {
            QStringList l;
            for (const auto &d : diet_type_map) {
                const auto v = m_element.tagValue(d.name);
                if (v == "yes") {
                    l.push_back(tr(d.label, "diet type"));
                } else if (v == "only") {
                    l.push_back(tr("only %1").arg(tr(d.label, "diet type")));
                } else if (v == "no") {
                    l.push_back(tr("no %1").arg(tr(d.label, "diet type")));
                }
            }
            return l.join(QLatin1String(", "));
        }
        case Takeaway: return QString::fromUtf8(m_element.tagValue("takeaway")); // TODO decode (yes/only/no) and translate
        case OpeningHours: return QString::fromUtf8(m_element.tagValue("opening_hours"));
        case Fee:
        {
            auto s = QString::fromUtf8(m_element.tagValue("fee")); // TODO decode boolean
            const auto charge = QString::fromUtf8(m_element.tagValue("charge"));
            if (s.isEmpty()) {
                return charge;
            }
            if (!charge.isEmpty()) {
                s += QLatin1String(" (") + charge + QLatin1Char(')');
            }
            return s;
        }
        case DiaperChangingTable:
            // TODO bool value translation
            // TODO look for changing_table:location too
            return QString::fromUtf8(m_element.tagValue("changing_table", "diaper"));
        case Wikipedia: return wikipediaUrl(m_element.tagValue("wikipedia", "brand:wikipedia", QLocale()));
        case Address: return QVariant::fromValue(OSMAddress(m_element));
        case Phone: return QString::fromUtf8(m_element.tagValue("contact:phone", "phone", "telephone"));
        case Email: return QString::fromUtf8(m_element.tagValue("contact:email", "email"));
        case Website: return QString::fromUtf8(m_element.tagValue("website", "contact:website", "url"));
        case PaymentCash:
        {
            const auto coins = m_element.tagValue("payment:coins");
            const auto notes = m_element.tagValue("payment:notes");
            if (coins.isEmpty() && notes.isEmpty()) {
                return m_element.tagValue("payment:cash"); // TODO decode bool
            }
            if (coins == "yes" && notes == "yes") {
                return tr("yes");
            }
            if (coins == "yes") {
                return tr("coins only");
            }
            if (notes == "yes") {
                return tr("notes only");
            }
            return tr("no");
        }
        case PaymentDigital:
        case PaymentDebitCard:
        case PaymentCreditCard:
        case PaymentStoredValueCard:
            return paymentMethodValue(key);
        case Wheelchair:
        {
            const auto a = QString::fromUtf8(m_element.tagValue("wheelchair")); // TODO decode and translate
            const auto d = QString::fromUtf8(m_element.tagValue("wheelchair:description", QLocale()));
            if (!d.isEmpty()) {
                return QString(a + QLatin1String(" (") + d + QLatin1Char(')'));
            }
            return a;
        }
        case CentralKey:
            // translate enum values
            return QString::fromUtf8(m_element.tagValue("centralkey"));
        case OperatorName: return QString::fromUtf8(m_element.tagValue("operator"));
        case OperatorWikipedia: return wikipediaUrl(m_element.tagValue("operator:wikipedia", QLocale()));
        case DebugLink: return m_element.url();
        case DebugKey: return {};
    }
    return {};
}

QVariant OSMElementInformationModel::urlify(const QVariant& v, OSMElementInformationModel::Key key) const
{
    if (v.type() != QVariant::String) {
        return v;
    }
    const auto s = v.toString();

    switch (key) {
        case Email:
            if (!s.startsWith(QLatin1String("mailto:"))) {
                return QString(QLatin1String("mailto:") + s);
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
            return QString(QLatin1String("https://") + s);
        default:
            return {};
    }

    return {};
}

QString OSMElementInformationModel::paymentMethodList(OSMElementInformationModel::Key key) const
{
    QStringList l;
    for (const auto &payment : payment_type_map) {
        if (payment.key != key) {
            continue;
        }
        if (m_element.tagValue(payment.name) == "yes") {
            l.push_back(tr(payment.label, "payment method"));
        }
    }
    std::sort(l.begin(), l.end());
    return QLocale().createSeparatedList(l);
}

QString OSMElementInformationModel::paymentMethodValue(OSMElementInformationModel::Key key) const
{
    const auto s = paymentMethodList(key);
    if (!s.isEmpty()) {
        return s;
    }

    for (const auto &payment : payment_generic_type_map) {
        if (payment.key != key) {
            continue;
        }
        const auto s = m_element.tagValue(payment.name);
        if (!s.isEmpty()) {
            return QString::fromUtf8(s);
        }
    }
    return {};
}

QUrl OSMElementInformationModel::wikipediaUrl(const QByteArray &wp) const
{
    if (wp.isEmpty()) {
        return {};
    }

    const auto s = QString::fromUtf8(wp);
    const auto idx = s.indexOf(QLatin1Char(':'));
    if (idx < 0) {
        return {};
    }

    QUrl url;
    url.setScheme(QStringLiteral("https"));
    url.setHost(s.leftRef(idx) + QLatin1String(".wikipedia.org"));
    url.setPath(QLatin1String("/wiki/") + s.midRef(idx + 1));
    return url;
}
