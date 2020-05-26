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

#ifndef KOSMINDOORMAP_MAPCSSSELECTOR_H
#define KOSMINDOORMAP_MAPCSSSELECTOR_H

#include <osm/datatypes.h>

#include <memory>
#include <vector>

class QIODevice;

namespace KOSMIndoorMap {

class MapCSSCondition;
class MapCSSConditionHolder;
class MapCSSState;

/** Base class for a style selector. */
class MapCSSSelector
{
public:
    virtual ~MapCSSSelector();

    /** Resolve tag keys. */
    virtual void compile(const OSM::DataSet &dataSet) = 0;
    /** Returns @c true if this selector matches the evaluation state. */
    virtual bool matches(const MapCSSState &state) const = 0;
    /** Selector matches the canvas element. */
    virtual bool matchesCanvas() const = 0;

    virtual void write(QIODevice *out) const = 0;

protected:
    explicit MapCSSSelector();
};

/** Basic selector, ie one that only contains tests but no sub-selectors. */
class MapCSSBasicSelector : public MapCSSSelector
{
public:
    explicit MapCSSBasicSelector();
    ~MapCSSBasicSelector();

    enum ObjectType {
        Node,
        Way,
        Relation,
        Area,
        Line,
        Canvas,
        Any
    };
    ObjectType objectType;

    void compile(const OSM::DataSet &dataSet) override;
    bool matches(const MapCSSState &state) const override;
    bool matchesCanvas() const override;
    void write(QIODevice* out) const override;

    /** @internal only to be used by the parser */
    void setObjectType(const char *str, std::size_t len);
    void setZoomRange(int low, int high);
    void setConditions(MapCSSConditionHolder *conds);

    std::vector<std::unique_ptr<MapCSSCondition>> conditions;
    OSM::TagKey m_areaKey;
    int m_zoomLow = 0;
    int m_zoomHigh = 0;
};

/** Selector chain. */
class MapCSSChainedSelector : public MapCSSSelector
{
public:
    void compile(const OSM::DataSet &dataSet) override;
    bool matches(const MapCSSState &state) const override;
    bool matchesCanvas() const override;
    void write(QIODevice* out) const override;
    std::vector<std::unique_ptr<MapCSSBasicSelector>> selectors;
};

/** Union selector set. */
class MapCSSUnionSelector : public MapCSSSelector
{
public:
    explicit MapCSSUnionSelector();
    ~MapCSSUnionSelector();

    void compile(const OSM::DataSet &dataSet) override;
    bool matches(const MapCSSState &state) const override;
    bool matchesCanvas() const override;
    void write(QIODevice* out) const override;
    std::vector<std::unique_ptr<MapCSSSelector>> selectors;
};

}

#endif // KOSMINDOORMAP_MAPCSSSELECTOR_H
