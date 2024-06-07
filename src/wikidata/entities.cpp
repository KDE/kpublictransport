/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "entities.h"

#include <QJsonArray>
#include <QVariant>

using namespace Qt::Literals::StringLiterals;
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

    auto propA = m_data.value("claims"_L1).toObject().value(property.toString()).toArray();
    for (const auto & propV : propA) {
        const auto propObj = propV.toObject();
        const auto rank = propObj.value("rank"_L1).toString();
        if (rank == "deprecated"_L1) {
            continue;
        }
        const auto valueObj = propObj.value("mainsnak"_L1).toObject().value("datavalue"_L1).toObject();
        const auto type = valueObj.value("type"_L1).toString();
        if (type == "string"_L1) {
            values.push_back(valueObj.value("value"_L1).toString());
        } else if (type == "wikibase-entityid"_L1) {
            values.push_back(QVariant::fromValue(Wikidata::Q(valueObj.value("value"_L1).toObject().value("id"_L1).toString())));
        }
        // TODO other types

        prefRank.push_back(rank == "preferred"_L1);
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
    return m_data.value("title"_L1).toString().mid(5);
}

uint64_t Image::fileSize() const
{
    return imageInfo().value("size"_L1).toInt();
}

uint32_t Image::width() const
{
    return imageInfo().value("width"_L1).toInt();
}

uint32_t Image::height() const
{
    return imageInfo().value("height"_L1).toInt();
}

QString Image::mimeType() const
{
    return imageInfo().value("mime"_L1).toString();
}

QString Image::license() const
{
    const auto extmeta = imageInfo().value("extmetadata"_L1).toObject();
    return extmeta.value("LicenseShortName"_L1).toObject().value("value"_L1).toString();
}

QJsonObject Image::imageInfo() const
{
    const auto ii = m_data.value("imageinfo"_L1).toArray();
    if (ii.isEmpty()) {
        return {};
    }
    return ii.at(0).toObject();
}
