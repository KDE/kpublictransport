/*
    SPDX-FileCopyrightText: 2023 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "../src/lib/json/jsonpointer.cpp"

#include <QJsonArray>
#include <QJsonObject>
#include <QObject>
#include <QTest>

using namespace KPublicTransport;

class JsonPointerTest: public QObject
{
    Q_OBJECT
private Q_SLOTS:
    void testResolve()
    {
        // examples from RFC 6901
        QJsonObject obj({
            { QLatin1String("foo"), QJsonArray({QStringLiteral("bar"), QStringLiteral("baz")}) },
            { QLatin1String(""), 0 },
            { QLatin1String("a/b"), 1 },
            { QLatin1String("c%%d"), 2 },
            { QLatin1String("e^f"), 3 },
            { QLatin1String("g|h"), 4 },
            { QLatin1String("i\\j"), 5 },
            { QLatin1String("k\"l"), 6 },
            { QLatin1String(" "), 7 },
            { QLatin1String("m~n"), 8 },
        });

        QJsonObject top({{ QLatin1String("obj"), obj }});

        QCOMPARE(JsonPointer::evaluate(obj, u""), obj);
        QCOMPARE(JsonPointer::evaluate(top, u""), top);
        QCOMPARE(JsonPointer::evaluate(obj, u"foo"), QJsonArray({QStringLiteral("bar"), QStringLiteral("baz")}));
        QCOMPARE(JsonPointer::evaluate(top, u"obj"), obj);
        QCOMPARE(JsonPointer::evaluate(top, u"obj/foo"), QJsonArray({QStringLiteral("bar"), QStringLiteral("baz")}));
        QCOMPARE(JsonPointer::evaluate(top, u"obj/g|h"), 4);
        QCOMPARE(JsonPointer::evaluate(top, u"/obj/ "), 7);
    }
};

QTEST_APPLESS_MAIN(JsonPointerTest)

#include "jsonpointertest.moc"
