/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "accessibilitycloudparser.h"
#include "../datatypes/geojson_p.h"

#include <KPublicTransport/Attribution>
#include <KPublicTransport/Equipment>

#include <QDebug>
#include <QDateTime>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QPointF>
#include <QUrl>

using namespace KPublicTransport;

bool AccessibilityCloudParser::parseLocations(const QByteArray &data)
{
    QJsonParseError error;
    const auto obj = QJsonDocument::fromJson(data, &error).object();
    if (error.error != QJsonParseError::NoError) {
        qDebug() << error.errorString();
        return false;
    }

    const auto licensesObj = obj.value(QLatin1String("related")).toObject().value(QLatin1String("licenses")).toObject();
    QHash<QString, Attribution> licenses;
    for (auto it = licensesObj.begin(); it != licensesObj.end(); ++it) {
        const auto obj = it.value().toObject();
        const auto id = obj.value(QLatin1String("organizationId")).toString();

        Attribution attr;
        attr.setLicense(obj.value(QLatin1String("name")).toString());
        attr.setLicenseUrl(QUrl(obj.value(QLatin1String("websiteURL")).toString()));
        licenses.insert(id, attr);
    }

    const auto features = obj.value(QLatin1String("features")).toArray();
    for (const auto &featureV : features) {
        const auto feature = featureV.toObject();
        const auto coordinate = GeoJson::readPoint(feature.value(QLatin1String("geometry")).toObject());
        if (coordinate.isNull()) {
            continue;
        }

        const auto properties = feature.value(QLatin1String("properties")).toObject();

        // ignore old entries, seems to be mostly duplicates messing up matching with OSM data
        const auto lastUpdate = QDateTime::fromString(properties.value(QLatin1String("lastUpdate")).toString(), Qt::ISODate);
        if (lastUpdate.isValid() && lastUpdate.addDays(1) < QDateTime::currentDateTime()) {
            continue;
        }

        const auto type = properties.value(QLatin1String("category")).toString();
        Equipment e;
        if (type == QLatin1String("elevator")) {
            e.setType(Equipment::Elevator);
        } else if (type == QLatin1String("escalator")) {
            e.setType(Equipment::Escalator);
        }
        if (e.type() == Equipment::Unknown) {
            continue;
        }

        const auto working = properties.value(QLatin1String("isWorking")).toBool();
        e.setDisruptionEffect(working ? Disruption::NormalService : Disruption::NoService);
        const auto explanation = properties.value(QLatin1String("lastDisruptionProperties")).toObject().value(QLatin1String("stateExplanation")).toString();
        e.addNote(explanation);

        Location loc;
        loc.setType(Location::Equipment);
        loc.setCoordinate(coordinate.y(), coordinate.x());
        // there seem to be occasionally elements referring to the same piece of equipment (and thus same originalId)
        // but one of those having a widely wrong coordinate. Our merging code would then produce results that we cannot
        // match against OSM anymore. By including the sourceId we prevent merging in those cases, and let OSM matching take
        // care of the bogus elements
        loc.setIdentifier(QStringLiteral("a11ycloud"),
                          properties.value(QLatin1String("sourceId")).toString() +
                          QLatin1Char(':') +
                          properties.value(QLatin1String("originalId")).toString());
        loc.setName(properties.value(QLatin1String("description")).toString());
        loc.setData(e);

        locations.push_back(std::move(loc));

        const auto orgId = properties.value(QLatin1String("sourceOrganizationId")).toString();
        const auto attrIt = licenses.find(orgId);
        if (attrIt != licenses.end()) {
            attrIt.value().setName(properties.value(QLatin1String("organizationName")).toString());
            attributions.push_back(std::move(attrIt.value()));
            licenses.erase(attrIt);
        }
    }

    return true;
}
