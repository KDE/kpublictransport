/*
    SPDX-FileCopyrightText: Ⓒ 2025 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include <KPublicTransport/LocationRequest>

#include <QJsonObject>
#include <QTest>

using namespace Qt::Literals;
using namespace KPublicTransport;

class CountryBoundingBoxTest : public QObject
{
    Q_OBJECT
private Q_SLOTS:
    void testBoundingBoxLookup()
    {
        LocationRequest req;
        QVERIFY(!req.viewbox().isValid());

        Location loc;
        loc.setCountry(u"AT"_s);
        req.setLocation(loc);
        QVERIFY(req.viewbox().isValid());
        QCOMPARE(req.viewbox(), QRectF(QPointF{9.53, 46.38}, QSizeF{7.63, 2.65}));
        QVERIFY(!LocationRequest::toJson(req).contains("viewbox"_L1));

        req.setViewbox(QRectF(QPointF(-10, -20), QSizeF(3, 4)));
        QVERIFY(req.viewbox().isValid());
        QCOMPARE(req.viewbox(), QRectF(QPointF{-10, -20}, QSizeF{3, 4}));
        QVERIFY(LocationRequest::toJson(req).contains("viewbox"_L1));
    }

    void testInvalidLookup()
    {
        LocationRequest req;
        Location loc;
        loc.setCountry(u"XX"_s);
        req.setLocation(loc);
        QVERIFY(!req.viewbox().isValid());
    }
};

QTEST_APPLESS_MAIN(CountryBoundingBoxTest)

#include "countryboundingboxtest.moc"
