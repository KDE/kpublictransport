/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "mapcssresult.h"

#include <algorithm>

using namespace KOSMIndoorMap;

MapCSSResult::MapCSSResult() = default;
MapCSSResult::~MapCSSResult() = default;

void MapCSSResult::clear()
{
    m_declarations.clear();
    m_flags = MapCSSDeclaration::NoFlag;
}

bool MapCSSResult::hasAreaProperties() const
{
    return m_flags & MapCSSDeclaration::AreaProperty;
}

bool MapCSSResult::hasLineProperties() const
{
    return m_flags & MapCSSDeclaration::LineProperty;
}

bool MapCSSResult::hasLabelProperties() const
{
    return m_flags & MapCSSDeclaration::LabelProperty;
}

const MapCSSDeclaration* MapCSSResult::declaration(MapCSSDeclaration::Property prop) const
{
    const auto it = std::lower_bound(m_declarations.begin(), m_declarations.end(), prop, [](auto lhs, auto rhs) {
        return lhs->property() < rhs;
    });
    if (it == m_declarations.end() || (*it)->property() != prop) {
        return nullptr;
    }
    return (*it);
}

const std::vector<const MapCSSDeclaration*>& MapCSSResult::declarations() const
{
    return m_declarations;
}

void MapCSSResult::addDeclaration(const MapCSSDeclaration *decl)
{
    const auto it = std::lower_bound(m_declarations.begin(), m_declarations.end(), decl, [](auto lhs, auto rhs) {
        return lhs->property() < rhs->property();
    });
    if (it == m_declarations.end() || (*it)->property() != decl->property()) {
        m_declarations.insert(it, decl);
    } else {
        (*it) = decl;
    }

    m_flags |= decl->propertyFlags();
}
