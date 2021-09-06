/*
    SPDX-FileCopyrightText: 2018 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include <KPublicTransport/Cache>
#include <KPublicTransport/Location>
#include <KPublicTransport/LocationRequest>

#include <QDir>
#include <QStandardPaths>
#include <QTest>
#include <QTimeZone>

using namespace KPublicTransport;

class CacheTest : public QObject
{
    Q_OBJECT

private Q_SLOTS:
    void initTestCase()
    {
        qputenv("TZ", "UTC");
        QStandardPaths::setTestModeEnabled(true);
        QDir(QStandardPaths::writableLocation(QStandardPaths::GenericCacheLocation)).removeRecursively();
    }

    void testLocationCache()
    {
        LocationRequest req;
        req.setCoordinate(52.5, 13.5);
        QVERIFY(!req.cacheKey().isEmpty());

        auto entry = Cache::lookupLocation(QStringLiteral("unittest"), req.cacheKey());
        QCOMPARE(entry.type, CacheHitType::Miss);

        Cache::addNegativeLocationCacheEntry(QStringLiteral("unittest"), req.cacheKey());
        entry = Cache::lookupLocation(QStringLiteral("unittest"), req.cacheKey());
        QCOMPARE(entry.type, CacheHitType::Negative);
        Cache::expire();
        entry = Cache::lookupLocation(QStringLiteral("unittest"), req.cacheKey());
        QCOMPARE(entry.type, CacheHitType::Negative);

        Location loc;
        loc.setName(QStringLiteral("Randa"));
        loc.setCoordinate(7.6, 46.1);
        loc.setIdentifier(QStringLiteral("uic"), QStringLiteral("85xxxxx"));

        Attribution attr;
        attr.setName(QStringLiteral("KDE"));
        attr.setLicense(QStringLiteral("LGPL"));
        attr.setUrl(QUrl(QStringLiteral("https://www.kde.org")));

        Cache::addLocationCacheEntry(QStringLiteral("unittest"), req.cacheKey(), {loc}, {attr});
        entry = Cache::lookupLocation(QStringLiteral("unittest"), req.cacheKey());
        QCOMPARE(entry.type, CacheHitType::Positive);
        QCOMPARE(entry.data.size(), 1);
        QCOMPARE(entry.data[0].name(), loc.name());
        QCOMPARE(entry.data[0].latitude(), 7.6f);
        QCOMPARE(entry.data[0].longitude(), 46.1f);
        QCOMPARE(entry.data[0].identifiers().size(), 1);
        QCOMPARE(entry.data[0].identifier(QStringLiteral("uic")), QLatin1String("85xxxxx"));
        QCOMPARE(entry.data[0].timeZone().isValid(), false);
        QCOMPARE(entry.attributions.size(), 1);
        QCOMPARE(entry.attributions[0].name(), QLatin1String("KDE"));
        QCOMPARE(entry.attributions[0].license(), QLatin1String("LGPL"));
        QCOMPARE(entry.attributions[0].url().toString(), QLatin1String("https://www.kde.org"));

        std::vector<Attribution> cachedAttrs;
        Cache::allCachedAttributions(cachedAttrs);
        QCOMPARE(cachedAttrs.size(), 1);
        QCOMPARE(cachedAttrs[0].name(), attr.name());

        Cache::expire();

        entry = Cache::lookupLocation(QStringLiteral("unittest"), req.cacheKey());
        QCOMPARE(entry.type, CacheHitType::Positive);
        QCOMPARE(entry.data.size(), 1);
        QCOMPARE(entry.attributions.size(), 1);
    }

    void testLocationCacheKey()
    {
        {
            LocationRequest req;
            req.setCoordinate(-52.5, -13.5);
            QCOMPARE(req.cacheKey(), QLatin1String("73be02317c4a7a43aff31f3186b18c22c6466250"));
            req.setTypes(Location::RentedVehicle|Location::RentedVehicleStation);
            QCOMPARE(req.cacheKey(), QLatin1String("4dfaecadb1a7d03106fe585b119948c158509807"));
        }
        {
            LocationRequest req;
            req.setName(QStringLiteral("Randa"));
            QCOMPARE(req.cacheKey(), QLatin1String("c4053bc0f4582f2977f3e43cad07b6587e6b6935"));
            req.setName(QStringLiteral("RANDA"));
            QCOMPARE(req.cacheKey(), QLatin1String("c4053bc0f4582f2977f3e43cad07b6587e6b6935"));
        }
    }
};

QTEST_GUILESS_MAIN(CacheTest)

#include "cachetest.moc"
