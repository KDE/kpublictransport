/*
    SPDX-FileCopyrightText: 2025 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "identifier_p.h"

#include <QJsonArray>
#include <QJsonObject>

#include <algorithm>

using namespace Qt::Literals;
using namespace KPublicTransport;

bool IdentifierSet::hasIdentifier(QAnyStringView type) const
{
    return std::ranges::find_if(m_identifiers, [type](const auto &id) {
        return id.type == type;
    }) != m_identifiers.end();
}

QString IdentifierSet::identifier(QAnyStringView type) const
{
    const auto it = std::ranges::find_if(m_identifiers, [type](const auto &id) {
        return id.type == type;
    });
    return it == m_identifiers.end() ? QString() : (*it).value;
}

void IdentifierSet::setIdentifier(const QString &type, const QString &value)
{
    const auto it = std::ranges::find_if(m_identifiers, [type](const auto &id) {
        return id.type == type;
    });
    if (it == m_identifiers.end()) {
        if (!value.isEmpty()) {
            m_identifiers.emplace_back(type, value);
        }
    } else {
        if (value.isEmpty()) {
            m_identifiers.erase(it);
        } else {
            (*it).value = value;
        }
    }
}

QStringList IdentifierSet::identifierTypes() const
{
    QStringList l;
    l.reserve((qsizetype)m_identifiers.size());
    std::ranges::transform(m_identifiers, std::back_inserter(l), [](const auto &id) { return id.type; });
    return l;
}

IdentifierSet::PartialCompare IdentifierSet::compare(const IdentifierSet &other) const
{
    bool foundEqualId = false;
    for (const auto &id :m_identifiers) {
        const auto otherValue = other.identifier(id.type);
        if (id.value.isEmpty() || otherValue.isEmpty()) {
            continue;
        }
        if (id.value == otherValue) {
            foundEqualId = true;
        } else {
            return NotEqual;
        }
    }
    return foundEqualId ? Equal : NoIntersection;
}

void IdentifierSet::merge(const IdentifierSet &other)
{
    for (const auto &otherId : other.m_identifiers) {
        if (otherId.value.isEmpty()) {
            continue;
        }
        const auto it = std::ranges::find_if(m_identifiers, [&otherId](const auto &id) {
            return id.type == otherId.type;
        });
        if (it == m_identifiers.end()) {
            m_identifiers.push_back(otherId);
        } else if ((*it).value.isEmpty()) {
            (*it).value = otherId.value;
        }
    }
}

QJsonObject IdentifierSet::toJson() const
{
    QJsonObject obj;
    for (const auto &id : m_identifiers) {
        obj.insert(id.type, id.value);
    }
    return obj;
}

void IdentifierSet::fromJson(const QJsonObject &ids)
{
    m_identifiers.clear();
    m_identifiers.reserve(ids.size());
    for (auto it = ids.begin(); it != ids.end(); ++it) {
        m_identifiers.emplace_back(it.key(), it.value().toString());
    }
}
