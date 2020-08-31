/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef OSM_OVERPASSQUERY_H
#define OSM_OVERPASSQUERY_H

#include "datatypes.h"

#include <QObject>
#include <QRectF>

class QNetworkReply;

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
    /** Minimum tile size to which tiles can be broken down in case of query timeouts. */
    QSizeF minimumTileSize() const;
    /** Sets the minimum tile size.
     *  Should be smaller than tile size by a power of 2.
     */
    void setMinimumTileSize(const QSizeF &minTileSize);

    /** Error codes. */
    enum Error {
        NoError,
        QueryError, ///< generic query error
        QueryTimeout, ///< query exceeded its execution time budget
        NetworkError,
    };
    /** Error code of this query job. */
    Error error() const;

    /** Query result data set. */
    const DataSet& result() const;
    DataSet&& takeResult();

Q_SIGNALS:
    void finished();

private:
    friend class OverpassQueryManager;
    friend class OverpassQueryManagerPrivate;

    Error processReply(QNetworkReply *reply);

    QString m_query;
    QRectF m_bbox = { -180.0, -90.0, 360.0, 180.0 };
    QSizeF m_tileSize = { 360.0, 180.0 };
    QSizeF m_minimumTileSize = { 1.0, 1.0 };
    Error m_error = NoError;
    OSM::DataSet m_result;
};

}

#endif // OSM_OVERPASSQUERY_H
