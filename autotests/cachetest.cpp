/*
    Copyright (C) 2018 Volker Krause <vkrause@kde.org>

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

        auto entry = Cache::lookupLocation(QLatin1String("unittest"), req.cacheKey());
        QCOMPARE(entry.type, CacheHitType::Miss);

        Cache::addNegativeLocationCacheEntry(QStringLiteral("unittest"), req.cacheKey());
        entry = Cache::lookupLocation(QLatin1String("unittest"), req.cacheKey());
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
        QCOMPARE(entry.data[0].identifier(QLatin1String("uic")), QLatin1String("85xxxxx"));
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
    }

    void testLocationCacheKey()
    {
        {
            LocationRequest req;
            req.setCoordinate(-52.5, -13.5);
            QCOMPARE(req.cacheKey(), QLatin1String("-52500000x-13500000"));
        }
        {
            LocationRequest req;
            req.setName(QStringLiteral("Randa"));
            QCOMPARE(req.cacheKey(), QLatin1String("8fb4b1073d1c288ae089ce8eb7ad0c16e478e919"));
            req.setName(QStringLiteral("RANDA"));
            QCOMPARE(req.cacheKey(), QLatin1String("8fb4b1073d1c288ae089ce8eb7ad0c16e478e919"));
        }
    }
};

QTEST_GUILESS_MAIN(CacheTest)

#include "cachetest.moc"
