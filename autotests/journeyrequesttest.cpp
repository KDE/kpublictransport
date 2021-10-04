/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include <KPublicTransport/JourneyRequest>

#include <QTest>

#define s(x) QStringLiteral(x)

using namespace KPublicTransport;

namespace KPublicTransport {
class JourneyRequestTest : public QObject
{
    Q_OBJECT
private Q_SLOTS:
    void testAccessEgressModeValidation()
    {
        JourneyRequest req;

        // there always has to be at least one access/egress mode
        req.setAccessModes(std::vector<IndividualTransport>{});
        req.setEgressModes(std::vector<IndividualTransport>{});
        req.validate();
        QCOMPARE(req.accessModes().size(), 1);
        QCOMPARE(req.accessModes()[0], IndividualTransport{IndividualTransport::Walk});
        QCOMPARE(req.egressModes().size(), 1);
        QCOMPARE(req.egressModes()[0], IndividualTransport{IndividualTransport::Walk});

        // parking is not a valid qualifier for egress
        req.setEgressModes(std::vector<IndividualTransport>{{IndividualTransport::Bike, IndividualTransport::Park}});
        req.validate();
        QCOMPARE(req.egressModes()[0], IndividualTransport{IndividualTransport::Walk});

        // when taking a bike on public transport, we also need to take it off again
        req.setAccessModes(std::vector<IndividualTransport>{{IndividualTransport::Bike}});
        req.validate();
        QCOMPARE(req.egressModes().size(), 2);
        QCOMPARE(req.egressModes()[1], IndividualTransport{IndividualTransport::Bike});

        // cars can't be taken on a train
        req.setAccessModes(std::vector<IndividualTransport>{{IndividualTransport::Car}});
        req.validate();
        QCOMPARE(req.accessModes().size(), 1);
        QCOMPARE(req.accessModes()[0], IndividualTransport{IndividualTransport::Walk});
        // ... and that also means we wont have a bike to take of the train again
        QCOMPARE(req.egressModes().size(), 1);
        QCOMPARE(req.egressModes()[0], IndividualTransport{IndividualTransport::Walk});
    }
};
}

QTEST_GUILESS_MAIN(JourneyRequestTest)

#include "journeyrequesttest.moc"
