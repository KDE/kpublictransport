/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef LINEINFO_H
#define LINEINFO_H

#include <osm/datatypes.h>
#include <wikidata/entities.h>

#include <QColor>
#include <QString>

struct LineInfo
{
    Q_GADGET
public:

    LineInfo();
    ~LineInfo();

    enum Mode { // ordered by accuracy in OSM data, ie. higher value -> higher probability of being the correctly detected mode
        Unknown,
        Train, // any kind of rail service
        LongDistance,
        LocalTrain,
        RapidTransit,
        Tram,
        Subway,
    };
    Q_ENUM(Mode)

    static bool isUseful(const LineInfo &info);
    static Mode determineMode(const OSM::Relation &rel);
    static LineInfo fromRelation(const OSM::Relation &rel);
    static void merge(LineInfo &lhs, const LineInfo &rhs);

    OSM::Id relId;
    OSM::BoundingBox bbox;
    QString name;
    QColor color;
    Mode mode = Unknown;
    QStringList lineLogos;
    QStringList productLogos;
    Wikidata::Q wdId;
    std::vector<Wikidata::Q> wdProducts;
};

QDebug operator<<(QDebug debug, const LineInfo &info);

#endif // LINEINFO_H
