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

#ifndef OSM_OVERPASSQUERY_H
#define OSM_OVERPASSQUERY_H

#include <QObject>
#include <QRectF>

namespace OSM {

/** An Overpass QL query job, to be executed by OverpassQueryManager.
 *  @note Use this wrongly can cause excessive load on Overpass servers,
 *  so only use this when you know what you are doing!
 */
class OverpassQuery : public QObject
{
    Q_OBJECT
public:
    explicit OverpassQuery(QObject *parent = nullptr);
    ~OverpassQuery();

    /** Returns the raw (without bbox replacement) query string. */
    QString query() const;
    /** Returns the query with @p bbox applied. */
    QString query(const QRectF &bbox) const;
    /** Overpass QL query string.
     *  Can contain the '{{bbox}}' bounding box placeholder also supported by Overpass Turbo.
     */
    void setQuery(const QString &query);

    /** Bounding box for this query, values in degree. */
    QRectF boundingBox() const;
    /** Set the bounding box for this query, values in degree. */
    void setBoundingBox(const QRectF &bbox);

    /** Tile size in which the bounding box is broken down for querying.
     *  Values in degree.
     */
    QSizeF tileSize() const;
    /** Sets the tile size in which the bounding box is broken down for querying.
     *  Values in degree.
     */
    void setTileSize(const QSizeF &tileSize);

    /** Error codes. */
    enum Error {
        NoError,
        QueryError,
        NetworkError,
    };
    /** Error code of this query job. */
    Error error() const;

Q_SIGNALS:
    void finished();

private:
    friend class OverpassQueryManager;
    friend class OverpassQueryManagerPrivate;

    QString m_query;
    QRectF m_bbox = { -180.0, -90.0, 360.0, 180.0 };
    QSizeF m_tileSize = { 360.0, 180.0 };
    Error m_error = NoError;
};

}

#endif // OSM_OVERPASSQUERY_H
