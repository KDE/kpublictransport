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

std::vector<const MapCSSDeclaration*> MapCSSResult::declarations() const
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
