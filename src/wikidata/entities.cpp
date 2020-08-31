/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "entities.h"

#include <QJsonArray>
#include <QVariant>

using namespace Wikidata;

Item::Item() = default;
Item::Item(Wikidata::Q id, const QJsonObject& data)
    : m_id(id)
    , m_data(data)
{
}

Item::~Item() = default;

std::vector<QVariant> Item::values(P property) const
{
    std::vector<QVariant> values;
    std::vector<bool> prefRank;

    auto propA = m_data.value(QLatin1String("claims")).toObject().value(property.toString()).toArray();
    for (const auto & propV : propA) {
        const auto propObj = propV.toObject();
        const auto rank = propObj.value(QLatin1String("rank")).toString();
        if (rank == QLatin1String("deprecated")) {
            continue;
        }
        const auto valueObj = propObj.value(QLatin1String("mainsnak")).toObject().value(QLatin1String("datavalue")).toObject();
        const auto type = valueObj.value(QLatin1String("type")).toString();
        if (type == QLatin1String("string")) {
            values.push_back(valueObj.value(QLatin1String("value")).toString());
        } else if (type == QLatin1String("wikibase-entityid")) {
            values.push_back(QVariant::fromValue(Wikidata::Q(valueObj.value(QLatin1String("value")).toObject().value(QLatin1String("id")).toString())));
        }
        // TODO other types

        prefRank.push_back(rank == QLatin1String("preferred"));
    }

    // if there are preferred rank values, take those, otherwise take all normal ranked ones
    if (std::any_of(prefRank.begin(), prefRank.end(), [](bool v) { return v; })) {
        int i = 0;
        for (auto it = values.begin(); it != values.end();) {
            if (prefRank[i++]) {
                ++it;
            } else {
                it = values.erase(it);
            }
        }
    }

    return values;
}

QVariant Item::value(Wikidata::P property) const
{
    const auto vals = values(property);
    return vals.empty() ? QVariant() : vals[0];
}


Image::Image() = default;
Image::Image(const QJsonObject &obj)
    : m_data(obj)
{
}

Image::~Image() = default;

QString Image::name() const
{
    return m_data.value(QLatin1String("title")).toString().mid(5);
}

uint64_t Image::fileSize() const
{
    return imageInfo().value(QLatin1String("size")).toInt();
}

uint32_t Image::width() const
{
    return imageInfo().value(QLatin1String("width")).toDouble();
}

uint32_t Image::height() const
{
    return imageInfo().value(QLatin1String("height")).toDouble();
}

QString Image::mimeType() const
{
    return imageInfo().value(QLatin1String("mime")).toString();
}

QString Image::license() const
{
    const auto extmeta = imageInfo().value(QLatin1String("extmetadata")).toObject();
    return extmeta.value(QLatin1String("LicenseShortName")).toObject().value(QLatin1String("value")).toString();
}

QJsonObject Image::imageInfo() const
{
    const auto ii = m_data.value(QLatin1String("imageinfo")).toArray();
    if (ii.isEmpty()) {
        return {};
    }
    return ii.at(0).toObject();
}
