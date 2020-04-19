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

#include "element.h"

using namespace OSM;

Coordinate Element::center() const
{
    if (!m_elem) {
        return {};
    }

    switch (type()) {
        case Type::Node:
            return node()->coordinate;
        case Type::Way:
            return way()->bbox.center();
        case Type::Relation:
            return relation()->bbox.center();
    }

    return {};
}

BoundingBox Element::boundingBox() const
{
    if (!m_elem) {
        return {};
    }

    switch (type()) {
        case Type::Node:
            return BoundingBox(node()->coordinate, node()->coordinate);
        case Type::Way:
            return way()->bbox;
        case Type::Relation:
            return relation()->bbox;
    }

    return {};
}

QString Element::tagValue(const QLatin1String &key) const
{
    if (!m_elem) {
        return {};
    }

    switch (type()) {
        case Type::Node:
            return OSM::tagValue(*node(), key);
        case Type::Way:
            return OSM::tagValue(*way(), key);
        case Type::Relation:
            return OSM::tagValue(*relation(), key);
    }

    return {};
}

QString Element::url() const
{
    if (!m_elem) {
        return {};
    }

    switch (type()) {
        case Type::Node:
            return node()->url();
        case Type::Way:
            return way()->url();
        case Type::Relation:
            return relation()->url();
    }

    return {};
}
