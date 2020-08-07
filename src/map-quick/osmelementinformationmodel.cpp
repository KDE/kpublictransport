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
#include "osmelementinformationmodel_p.h"
#include "osmelementinformationmodel_data.cpp"
#include "osmaddress.h"

using namespace KOSMIndoorMap;

bool OSMElementInformationModel::Info::operator<(OSMElementInformationModel::Info other) const
{
    if (category == other.category) {
        return key < other.key;
    }
    return category < other.category;
}

bool OSMElementInformationModel::Info::operator==(OSMElementInformationModel::Info other) const
{
    return category == other.category && key == other.key;
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
    return valueForKey(Info{m_nameKey, Header}).toString();
}

QString OSMElementInformationModel::category() const
{
    return valueForKey(Info{m_categoryKey, Header}).toString();
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
                default: return valueForKey(info);
            }
        case ValueUrlRole:
            return urlify(valueForKey(info), info.key);
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
    const char *keyName;
    OSMElementInformationModel::Key m_key;
    OSMElementInformationModel::KeyCategory m_category;

    constexpr inline OSMElementInformationModel::Key key() const { return m_key; }
    constexpr inline OSMElementInformationModel::KeyCategory category() const { return m_category; }
} static constexpr const simple_key_map[] = {
    M("addr:city", Address, Contact),
    M("addr:street", Address, Contact),
    M("amenity", Category, Header),
    M("brand:wikipedia", Wikipedia, Main),
    M("capacity", Capacity, Parking),
    M("capacity:charging", CapacityCharing, Parking),
    M("capacity:disabled", CapacityDisabled, Parking),
    M("capacity:parent", CapacityParent, Parking),
    M("capacity:women", CapacityWomen, Parking),
    M("centralkey", CentralKey, Accessibility),
    M("changing_table", DiaperChangingTable, Main),
    M("charge", Fee, UnresolvedCategory),
    M("contact:city", Address, Contact),
    M("contact:email", Email, Contact),
    M("contact:phone", Phone, Contact),
    M("contact:street", Address, Contact),
    M("contact:website", Website, Contact),
    M("cuisine", Cuisine, Main),
    M("diaper", DiaperChangingTable, Main),
    M("email", Email, Contact),
    M("fee", Fee, UnresolvedCategory),
    M("maxstay", MaxStay, Parking),
    M("network", Network, Operator),
    M("office", Category, Header),
    M("old_name", OldName, Main),
    M("opening_hours", OpeningHours, UnresolvedCategory),
    M("operator", OperatorName, Operator),
    M("operator:wikipedia", OperatorWikipedia, Operator),
    M("parking:fee", Fee, Parking),
    M("payment:cash", PaymentCash, Payment),
    M("payment:coins", PaymentCash, Payment),
    M("payment:notes", PaymentCash, Payment),
    M("phone", Phone, Contact),
    M("room", Category, Header),
    M("shop", Category, Header),
    M("takeaway", Takeaway, Main),
    M("toilets:fee", Fee, Toilets),
    M("toilets:wheelchair", Wheelchair, Toilets),
    M("tourism", Category, Header),
    M("url", Website, Contact),
    M("website", Website, Contact),
    M("wheelchair", Wheelchair, Accessibility),
};
#undef M
static_assert(isSortedLookupTable(simple_key_map), "key map is not sorted!");

template <typename KeyMapEntry, std::size_t N>
void OSMElementInformationModel::addEntryForKey(const char *keyName, const KeyMapEntry(&map)[N])
{
    const auto it = std::lower_bound(std::begin(map), std::end(map), keyName, [](const auto &lhs, auto rhs) {
        return std::strcmp(lhs.keyName, rhs) < 0;
    });
    if (it != std::end(map) && std::strcmp((*it).keyName, keyName) == 0) {
        m_infos.push_back(Info{(*it).key(), (*it).category()});
    }
}

void OSMElementInformationModel::reload()
{
    m_nameKey = NoKey;
    m_categoryKey = NoKey;

    for (auto it = m_element.tagsBegin(); it != m_element.tagsEnd(); ++it) {
        if (std::strncmp((*it).key.name(), "name", 4) == 0) {
            m_nameKey = Name;
            continue;
        }
        if (std::strncmp((*it).key.name(), "wikipedia", 9) == 0) {
            m_infos.push_back(Info{Wikipedia, UnresolvedCategory});
            continue;
        }
        addEntryForKey((*it).key.name(), simple_key_map);
        addEntryForKey((*it).key.name(), payment_generic_type_map);
        addEntryForKey((*it).key.name(), payment_type_map);
        addEntryForKey((*it).key.name(), diet_type_map);
    }

    std::sort(m_infos.begin(), m_infos.end());
    m_infos.erase(std::unique(m_infos.begin(), m_infos.end()), m_infos.end());
    resolveCategories();
    resolveHeaders();

    // if we don't have a primary group, promote a suitable secondary one
    for (auto cat : {Parking, Toilets}) {
        if (promoteMainCategory(cat)) {
            break;
        }
    }

    // resolve all remaining unresolved elements to the primary category
    for (auto &info : m_infos) {
        if (info.category == UnresolvedCategory) {
            info.category = Main;
        }
    }
    std::sort(m_infos.begin(), m_infos.end());

    if (m_debug) {
        m_infos.push_back(Info{ DebugLink, DebugCategory });
        const auto count = std::distance(m_element.tagsBegin(), m_element.tagsEnd());
        std::fill_n(std::back_inserter(m_infos), count, Info{ DebugKey, DebugCategory });
    }
}

void OSMElementInformationModel::resolveCategories()
{
    if (m_infos.empty() || m_infos[0].category != UnresolvedCategory) {
        return;
    }
    for (auto &info : m_infos) {
        if (info.category != UnresolvedCategory) {
            break;
        }
        switch (info.key) {
            case Fee:
                if (m_element.tagValue("parking:fee").isEmpty() && (!m_element.tagValue("parking").isEmpty()
                    || m_element.tagValue("amenity") == "parking" || m_element.tagValue("amenity") == "bicycle_parking"))
                {
                    info.category = Parking;
                } else if (m_element.tagValue("toilets:fee").isEmpty() && m_element.tagValue("toilets") == "yes") {
                    info.category = Toilets;
                } else {
                    info.category = Main;
                }
                break;
            default:
            {
                // for anything else: if it's not clearly something we have a secondary group for, resovle it to Main
                const auto amenity = m_element.tagValue("amenity");
                if ((amenity != "parking" && amenity != "toilets")
                    || !m_element.tagValue("office").isEmpty()
                    || !m_element.tagValue("room").isEmpty()
                    || !m_element.tagValue("shop").isEmpty()
                    || !m_element.tagValue("tourism").isEmpty()) {
                    info.category = Main;
                }
                break;
            }
        }
    }
    std::sort(m_infos.begin(), m_infos.end());
}

void OSMElementInformationModel::resolveHeaders()
{
    // we use the categories as header if there is no name, so don't duplicate that
    const auto it = std::find_if(m_infos.begin(), m_infos.end(), [](Info info) {
        return info.key == Category;
    });
    if (it == m_infos.end()) {
        return;
    }

    m_infos.erase(it);
    if (m_nameKey == NoKey) {
        m_nameKey = Category;
    } else {
        m_categoryKey = Category;
    }
}

bool OSMElementInformationModel::promoteMainCategory(OSMElementInformationModel::KeyCategory cat)
{
    const auto hasMain = std::any_of(m_infos.begin(), m_infos.end(), [](const auto &info) {
        return info.category == Main;
    });

    if (hasMain) {
        return true;
    }

    bool didPromote = false;
    for (auto &info : m_infos) {
        if (info.category == cat) {
            info.category = Main;
            didPromote = true;
        }
    }

    if (didPromote) {
        std::sort(m_infos.begin(), m_infos.end());
    }
    return didPromote;
}

QString OSMElementInformationModel::categoryLabel(OSMElementInformationModel::KeyCategory cat) const
{
    switch (cat) {
        case UnresolvedCategory:
        case Header:
        case Main:          return {};
        case Contact:       return tr("Contact");
        case Payment:       return tr("Payment");
        case Toilets:       return tr("Toilets");
        case Accessibility: return tr("Accessibility");
        case Parking:       return tr("Parking");
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
        case Capacity: return tr("Capacity");
        case CapacityDisabled: return tr("Disabled parking spaces");
        case CapacityWomen: return tr("Women parking spaces");
        case CapacityParent: return tr("Parent parking spaces");
        case CapacityCharing: return tr("Parking spaces for charging");
        case MaxStay: return tr("Maximum stay");
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
        case Network: return tr("Network", "transport network");
        case OperatorWikipedia: return {};
        case DebugLink: return QStringLiteral("OSM");
        case DebugKey: return {};
    }
    return {};
}

QVariant OSMElementInformationModel::valueForKey(Info info) const
{
    switch (info.key) {
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
                out.push_back(translateValue((*it).constData(), amenity_map, "OSM::amenity/shop"));
            }

            std::sort(out.begin(), out.end());
            out.erase(std::unique(out.begin(), out.end()), out.end());
            return QLocale().createSeparatedList(out);
        }
        case OldName:
        {
            const auto l = QString::fromUtf8(m_element.tagValue("old_name")).split(QLatin1Char(';'));;
            return l.join(QLatin1String(", "));
        }
        case Cuisine:
        {
            auto l = m_element.tagValue("cuisine").split(';');
            QStringList out;
            out.reserve(l.size());
            for (auto &code : l) {
                out.push_back(translateValue(code.constData(), cuisine_map, "OSM::cuisine"));
            }
            std::sort(out.begin(), out.end());
            return QLocale().createSeparatedList(out);
        }
        case Diet:
        {
            QStringList l;
            for (const auto &d : diet_type_map) {
                const auto v = m_element.tagValue(d.keyName);
                const auto label = QCoreApplication::translate("OSM::diet_type", d.label);
                if (v == "yes") {
                    l.push_back(label);
                } else if (v == "only") {
                    l.push_back(tr("only %1").arg(label));
                } else if (v == "no") {
                    l.push_back(tr("no %1").arg(label));
                }
            }
            return l.join(QLatin1String(", "));
        }
        case Takeaway: return QString::fromUtf8(m_element.tagValue("takeaway")); // TODO decode (yes/only/no) and translate
        case OpeningHours: return QString::fromUtf8(m_element.tagValue("opening_hours"));
        case Fee:
        {
            QByteArray fee;
            switch (info.category) {
                case Parking: fee = m_element.tagValue("parking:fee", "fee"); break;
                case Toilets: fee = m_element.tagValue("toilets:fee", "fee"); break;
                default: fee = m_element.tagValue("fee");
            }
            auto s = QString::fromUtf8(fee);
            const auto charge = QString::fromUtf8(m_element.tagValue("charge"));
            if (s.isEmpty()) {
                return charge;
            }
            if (!charge.isEmpty()) {
                s += QLatin1String(" (") + charge + QLatin1Char(')');
            }
            return s;
        }
        case Capacity: return QString::fromUtf8(m_element.tagValue("capacity"));
        case CapacityDisabled: return capacitryValue("capacity:disabled");
        case CapacityWomen: return capacitryValue("capacity:women");
        case CapacityParent: return capacitryValue("capacity:parent");
        case CapacityCharing: return capacitryValue("capacity:charging");
        case MaxStay: return QString::fromUtf8(m_element.tagValue("maxstay"));
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
            return paymentMethodValue(info.key);
        case Wheelchair:
        {
            QByteArray wheelchair;
            if (info.category == Toilets) {
                wheelchair = m_element.tagValue("toilets:wheelchair", "wheelchair");
            } else {
                wheelchair = m_element.tagValue("wheelchair");
            }
            const auto a = translateValue(wheelchair.constData(), wheelchair_map, "OSM::wheelchair_access");
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
        case Network: return QString::fromUtf8(m_element.tagValue("network"));
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
        if (payment.key() != key) {
            continue;
        }
        if (m_element.tagValue(payment.keyName) == "yes") {
            l.push_back(QCoreApplication::translate("OSM::payment_method", payment.label));
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
        if (payment.key() != key) {
            continue;
        }
        const auto s = m_element.tagValue(payment.keyName);
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

QString OSMElementInformationModel::capacitryValue(const char *prop) const
{
    const auto v = m_element.tagValue(prop);
    if (v == "yes") {
        return tr("yes");
    }
    if (v == "no") {
        return tr("no");
    }
    return QString::fromUtf8(v);
}
