/*
    SPDX-FileCopyrightText: 2019-2026 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "hafasattributemap.h"

#include "logging.h"
#include "standardpaths_p.h"

#include <datatypes/json_p.h>

#include <KPublicTransport/Feature>

#include <QFile>
#include <QHash>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>

using namespace Qt::Literals;
using namespace KPublicTransport;

static QHash<QString, QExplicitlySharedDataPointer<HafasAttributeMapData>> s_attrMaps;

class KPublicTransport::HafasAttributeData {
    Q_GADGET
    Q_PROPERTY(QString category MEMBER category)
    Q_PROPERTY(QString code MEMBER code)
    Q_PROPERTY(KPublicTransport::HafasAttribute::Type type MEMBER type)
    Q_PROPERTY(KPublicTransport::Feature::Type feature MEMBER featureType)
    Q_PROPERTY(KPublicTransport::Feature::Availability availability MEMBER featureAvailability)
    Q_PROPERTY(KPublicTransport::PickupDropoff::Type pickup MEMBER pickupType)
    Q_PROPERTY(KPublicTransport::PickupDropoff::Type dropoff MEMBER dropoffType)
public:
    [[nodiscard]] static HafasAttributeData fromJson(const QJsonObject &obj);

    QString category;
    QString code;
    HafasAttribute::Type type = HafasAttribute::Undefined;
    Feature::Type featureType = Feature::NoFeature;
    Feature::Availability featureAvailability = Feature::Unknown;
    PickupDropoff::Type pickupType = PickupDropoff::Normal;
    PickupDropoff::Type dropoffType = PickupDropoff::Normal;
};

class KPublicTransport::HafasAttributeMapData : public QSharedData {
public:
    [[nodiscard]] HafasAttribute lookup(QAnyStringView category, QAnyStringView code) const;

    std::vector<HafasAttributeData> attrs;
    QExplicitlySharedDataPointer<HafasAttributeMapData> base;
};


HafasAttributeData HafasAttributeData::fromJson(const QJsonObject &obj)
{
    return Json::fromJson<HafasAttributeData>(obj);
}

HafasAttribute HafasAttributeMapData::lookup(QAnyStringView category, QAnyStringView code) const
{
    for (const auto &attr : attrs) {
        if (attr.category == category && attr.code == code) {
            return HafasAttribute(&attr);
        }
    }

    return base ? base->lookup(category, code) : HafasAttribute(nullptr);
}


HafasAttribute::HafasAttribute(const HafasAttributeData *dd)
    : d(dd)
{
}

HafasAttribute::Type HafasAttribute::type() const
{
    return d ? d->type :HafasAttribute::Undefined;
}

Feature HafasAttribute::feature() const
{
    return d ? ::Feature(d->featureType, d->featureAvailability) : ::Feature(Feature::NoFeature);
}

PickupDropoff::Type HafasAttribute::pickupType() const
{
    return d ? d->pickupType : PickupDropoff::Normal;
}

PickupDropoff::Type HafasAttribute::dropoffType() const
{
    return d ? d->dropoffType :PickupDropoff::Normal;
}

[[nodiscard]] static QExplicitlySharedDataPointer<HafasAttributeMapData> loadMap(QStringView name)
{
    if (const auto it = s_attrMaps.find(name); it != s_attrMaps.end()) {
        return it.value();
    }

    const auto fileName = StandardPaths::locateFile("networks/hafas-attributes/"_L1 + name + ".json"_L1);
    QFile f(fileName);
    if (!f.open(QFile::ReadOnly)) {
        qCWarning(Log) << "Failed to open Hafas attribute map" << name << f.fileName() << f.errorString();
        return {};
    }
    QJsonParseError error;
    const auto attrMap = QJsonDocument::fromJson(f.readAll(), &error).object();
    if (error.error != QJsonParseError::NoError) {
        qCWarning(Log) << fileName << error.errorString() << error.offset;
    }
    QExplicitlySharedDataPointer<HafasAttributeMapData> data(new HafasAttributeMapData);
    data->attrs = Json::fromJson<HafasAttributeData>(attrMap.value("attributes"_L1).toArray());
    for (auto it = data->attrs.begin(); it != data->attrs.end();) {
        // drop all invalid entries, as those could come in via online updates with features we don't support yet
        if ((*it).category.isEmpty() || (*it).code.isEmpty() || (*it).type == HafasAttribute::Undefined ||
            ((*it).type == HafasAttribute::Feature && ((*it).featureType == Feature::NoFeature || (*it).featureAvailability == Feature::Unknown))
        ) {
            qCWarning(Log) << "invalid Hafas attribute" << (*it).category << (*it).code << (*it).type << (*it).featureType << (*it).featureAvailability << name;
            it = data->attrs.erase(it);
        } else {
            ++it;
        }
    }
    s_attrMaps[name.toString()] = data;

    if (const auto baseName = attrMap.value("inherits"_L1).toString(); !baseName.isEmpty()) {
        data->base = loadMap(baseName);
        // ensure there's no cycles
        auto parent = data->base;
        while (parent) {
            if (parent == data) {
                qCWarning(Log) << "cyclic attribute map base found, discarding!" << name;
                data->base = nullptr;
                break;
            }
            parent = parent->base;
        }
    }

    return data;
}

HafasAttributeMap::HafasAttributeMap() = default;

HafasAttributeMap::HafasAttributeMap(QStringView name)
{
    d = loadMap(name);
}

HafasAttributeMap::HafasAttributeMap(HafasAttributeMap &&) noexcept = default;
HafasAttributeMap& HafasAttributeMap::operator=(HafasAttributeMap &&) noexcept = default;
HafasAttributeMap::~HafasAttributeMap() = default;

HafasAttribute HafasAttributeMap::lookup(QAnyStringView category, QAnyStringView code) const
{
    return d ? d->lookup(category, code) : HafasAttribute(nullptr);
}

void HafasAttributeMap::reload()
{
    s_attrMaps.clear();
}

#include "moc_hafasattributemap.cpp"
#include "hafasattributemap.moc"
