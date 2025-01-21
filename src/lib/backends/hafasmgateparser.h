/*
    SPDX-FileCopyrightText: 2018 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_HAFASMGATEPARSER_H
#define KPUBLICTRANSPORT_HAFASMGATEPARSER_H

#include "kpublictransport_export.h"
#include "hafasparser.h"
#include "hafasconfiguration.h"

#include <KPublicTransport/Disruption>
#include <KPublicTransport/Feature>
#include <KPublicTransport/Line>
#include <KPublicTransport/Reply>

#include <vector>

#include <QColor>

class QByteArray;
class QJsonValue;

namespace KPublicTransport {

class Journey;
class JourneySection;
class Location;
class Stopover;

struct Ico {
    QColor bg;
    QColor fg;
};

enum HafasMessageType {
    UndefinedRemark,
    IgnoreRemark,
    FeatureRemark,
    OperatorRemark,
    TrainFormationRemark,
    PlatformSectorsRemark,
};

struct HafasRemarkData {
    const char *type = nullptr;
    const char *code = nullptr;
    HafasMessageType msg = UndefinedRemark;
    Feature::Type featureType = Feature::NoFeature;
    Feature::Availability featureAvailability = Feature::Unknown;
};

struct HafasMgateParserContext;

/** Hafas response parser.
 *  @internal exported for unit tests only
 */
class KPUBLICTRANSPORT_EXPORT HafasMgateParser : public HafasParser
{
public:
    HafasMgateParser();
    ~HafasMgateParser();
    void setProductNameMappings(std::vector<HafasMgateProductNameMapping> &&productNameMappings);

    std::vector<Stopover> parseDepartures(const QByteArray &data) const;
    std::vector<Location> parseLocations(const QByteArray &data) const;
    std::vector<Journey> parseJourneys(const QByteArray &data);
    [[nodiscard]] JourneySection parseTrip(const QByteArray &data) const;

    static QDateTime parseDateTime(const QString &date, const QJsonValue &time, const QJsonValue &tzOffset);
    static HafasRemarkData lookupRemarkData(QStringView type, QStringView code);

    QString m_previousJourneyContext;
    QString m_nextJourneyContext;
private:
    Q_DISABLE_COPY(HafasMgateParser)
    std::vector<Stopover> parseStationBoardResponse(const QJsonObject &obj) const;
    std::vector<Route> parseProducts(const QJsonArray &prodL, const std::vector<Ico> &icos, const std::vector<QString> &ops) const;
    std::vector<Location> parseLocations(const QJsonArray &locL) const;
    std::vector<Journey> parseTripSearch(const QJsonObject &obj);
    JourneySection parseJourneyDetails(const QJsonObject &obj) const;

    HafasMgateParserContext parseCommon(const QJsonObject &obj) const;
    void parsePublicTransportSection(const HafasMgateParserContext &common, const QJsonObject &jnyObj, int fromIdx, int toIdx, const QString &dateStr, JourneySection &section) const;
    bool parseError(const QJsonObject &obj) const;

    std::vector<HafasMgateProductNameMapping> m_productNameMappings;
};

}

#endif // KPUBLICTRANSPORT_HAFASMGATEPARSER_H
