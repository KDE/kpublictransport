/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KOSMINDOORMAP_OVERLAYSOURCE_H
#define KOSMINDOORMAP_OVERLAYSOURCE_H

#include <osm/element.h>

#include <QPointer>

#include <functional>

class QAbstractItemModel;

namespace KOSMIndoorMap {

/** A source for overlay elements, drawn on top of the static map data.
 *  @todo If we ever get different sources than QAIMs, this could be split into
 *  an abstract base and specific implementations.
 */
class OverlaySource
{
public:
    explicit OverlaySource(QAbstractItemModel *model);
    ~OverlaySource();

    /** Callback to trigger map re-rendering when the source changes. */
    void setUpdateCallback(QObject *context, const std::function<void()> &updateFunc) const;

    /** Callback to trigger style re-compilation.
     *  This is needed for example when the source added new tag keys that the map data
     *  didn't previously contain (and thus would be optimized out of the style).
     */
    void setResetCallback(QObject *context, const std::function<void()> &resetFunc) const;

    /** Iteration interface with floor level filtering. */
    void forEach(int floorLevel, const std::function<void(OSM::Element, int)> &func) const;

    /** Adds hidden elements to @param elems. */
    void hiddenElements(std::vector<OSM::Element> &elems) const;

private:
    void recursiveForEach(const QModelIndex &rootIdx, int floorLevel, const std::function<void (OSM::Element, int)> &func) const;

    QPointer<QAbstractItemModel> m_model;
    int m_elementRole = -1;
    int m_floorRole = -1;
    int m_hiddenElementRole = -1;
};

}

#endif // KOSMINDOORMAP_OVERLAYSOURCE_H
