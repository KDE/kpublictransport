/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include <KPublicTransport/Journey>
#include <KPublicTransport/JourneyReply>
#include <KPublicTransport/JourneyRequest>
#include <KPublicTransport/Location>
#include <KPublicTransport/LocationReply>
#include <KPublicTransport/LocationRequest>
#include <KPublicTransport/Manager>
#include <KPublicTransport/Stopover>
#include <KPublicTransport/StopoverReply>
#include <KPublicTransport/StopoverRequest>

#include <QDir>
#include <QSignalSpy>
#include <QStandardPaths>
#include <QtTest>

using namespace KPublicTransport;

class QueryTest : public QObject
{
    Q_OBJECT
private:
    Location loc(const char *name, float lat, float lon) const
    {
        Location l;
        l.setName(QString::fromUtf8(name));
        l.setCoordinate(lat, lon);
        return l;
    }

    static constexpr const auto TIMEOUT = 30000;

    KPublicTransport::Manager m_ptMgr;

private Q_SLOTS:
    void initTestCase()
    {
        QStandardPaths::setTestModeEnabled(true);
        QDir(QStandardPaths::writableLocation(QStandardPaths::GenericCacheLocation)).removeRecursively();

        m_ptMgr.setAllowInsecureBackends(true);
    }

    void testBackend_data()
    {
        QTest::addColumn<QString>("backend");
        QTest::addColumn<Location>("loc1");
        QTest::addColumn<Location>("loc2");

        // international
        // TODO un_gbfs - this needs special-casing given it cannot do journey and departure searches
        QTest::newRow("un_navitia") << "un_navitia" << loc("Paris Gare de Lyon", 48.84444, 2.37412) << loc("Paris Aéroport Charles de Gaulle 2", 49.00423, 2.57215);

        // national
        QTest::newRow("at_oebb") << "at_oebb" << loc("Wien Hauptbahnhof", 48.18282, 16.37859) << loc("Linz/Donau Hbf", 48.29058, 14.29018);
        QTest::newRow("be_sncb") << "be_sncb" << loc("Bruxelles Midi", 50.83604, 4.33679) << loc("Mechelen", 51.01745, 4.48336);
        QTest::newRow("ch_sbb") << "ch_sbb" << loc("Zürich Flughafen", 47.45015, 8.56199 ) << loc("Randa", 46.09982, 7.78149);
        QTest::newRow("de_db") << "de_db" << loc("Berlin Hauptbahnhof", 52.52509, 13.36946) << loc("Frankfurt Hbf", 50.10675, 8.66281);
        QTest::newRow("dk_dsb") << "dk_dsb" << loc("København H", 55.67228, 12.56442) << loc("Københavns Lufthavn Kastrup", 55.62940, 12.64872);
        QTest::newRow("ee_peatus") << "ee_peatus" << loc("Tallinn Hobujaama", 59.43727, 24.75824) << loc("Pärnu", 58.37254, 24.55502);
        // TODO eu_railteam
        QTest::newRow("fi_digitransit") << "fi_digitransit" << loc("Helsinki", 60.17174, 24.94148) << loc("Espoo", 60.20530, 24.65748);
        QTest::newRow("fi_waltti") << "fi_waltti" << loc("Helsinki", 60.17174, 24.94148) << loc("Tampere", 61.49859, 23.77392);
        QTest::newRow("fr_sncf") << "fr_sncf" << loc("Paris Gare de Lyon", 48.84444, 2.37412) << loc("Paris Aéroport Charles de Gaulle 2", 49.00423, 2.57215);
        // TODO gb_traveline
        // TODO ie_tfi
        QTest::newRow("lu_cfl") << "lu_cfl" << loc("Luxembourg Gare Centrale", 49.59962, 6.13473) << loc("Ettelbruck", 49.84745, 6.10645);
        QTest::newRow("nl_ns") << "nl_ns" << loc("Amsterdam Centraal", 52.37923, 4.90055) << loc("Den Haag Centraal", 52.08108, 4.32406);
        QTest::newRow("no_entur") << "no_entur" << loc("Oslo", 59.91157, 10.75413) << loc("Bergen", 60.39033, 5.33396);
        // TODO pl_pkp
        // TODO se_resrobot
        // TODO tn_sncft

        // local
        // TODO at_3_vor
        QTest::newRow("at_4_linz") << "at_4_linz" << loc("Linz/Donau Hbf", 48.29007, 14.29207) << loc("Hörsching", 48.24549, 14.18587);
        QTest::newRow("at_4_ooevv") << "at_4_ooevv" << loc("Linz/Donau Hbf", 48.29058, 14.29018) << loc("Hörsching", 48.24549, 14.18587);
        QTest::newRow("at_5_svv") << "at_5_svv" << loc("Salzburg Hbf", 47.81285, 13.04592) << loc("Freilassing", 47.83690, 12.97673);
        // TODO at_6_vvst
        // TODO at_7_vvt
        // TODO at_8_vvv

        // TODO au_nsw.json

        QTest::newRow("de_bb_vbb") << "de_bb_vbb" << loc("Berlin Hauptbahnhof", 52.52509, 13.36946) << loc("Berlin Alexanderplatz", 52.52147, 13.41134);
        QTest::newRow("de_be_bvg") << "de_be_bvg" << loc("Berlin Hauptbahnhof", 52.52509, 13.36946) << loc("Berlin Alexanderplatz", 52.52147, 13.41134);
        QTest::newRow("de_bw_bwegt") << "de_bw_bwegt" << loc("Stuttgart Hbf", 48.78539, 9.18345) << loc("Herrenberg", 48.59392, 8.86275);
        // TODO de_bw_kvv
        QTest::newRow("de_bw_stadtnavi") << "de_bw_stadtnavi" << loc("Stuttgart Hbf", 48.78539, 9.18345) << loc("Herrenberg", 48.59392, 8.86275);
        // TODO de_bw_ulm
        QTest::newRow("de_bw_vvs") << "de_bw_vvs" << loc("Stuttgart Hbf", 48.78539, 9.18345) << loc("Herrenberg", 48.59392, 8.86275);
        QTest::newRow("de_by_bayern") << "de_by_bayern" << loc("München Hbf", 48.14046, 11.55819) << loc("Nürnberg Hbf", 49.44559, 11.08219);
        QTest::newRow("de_by_mvv") << "de_by_mvv" << loc("München Hbf", 48.14046, 11.55819) << loc("Isartor", 48.13375, 11.58303);
        QTest::newRow("de_by_vgn") << "de_by_vgn" << loc("Erlangen", 49.59591, 11.00220) << loc("Nürnberg Hbf", 49.44559, 11.08219);
        // TODO de_he_nvv
        QTest::newRow("de_he_rmv") << "de_he_rmv" << loc("Frankfurt Hbf", 50.10675, 8.66281) << loc("Frankfurt Flughafen Regionalbf", 50.05129, 8.57170);
        QTest::newRow("de_hh_hvv") << "de_hh_hvv" << loc("Hamburg Hauptbahnhof", 53.55299, 10.00702) << loc("Hamburg Altona", 53.55284, 9.93569);
        // TODO de_mv_vmv
        QTest::newRow("de_ni_efa") << "de_ni_efa" << loc("Hannover Hbf", 52.37715, 9.74171) << loc("Bremen Hbf", 53.08322, 8.81388);
        QTest::newRow("de_ni_gvh") << "de_ni_gvh" << loc("Hannover Hbf", 52.37715, 9.74171) << loc("Bremen Hbf", 53.08322, 8.81388);
        QTest::newRow("de_ni_vbn") << "de_ni_vbn" << loc("Hannover Hbf", 52.37715, 9.74171) << loc("Bremen Hbf", 53.08322, 8.81388);
        // TODO de_nw_avv
        // TODO de_nw_muenster
        QTest::newRow("de_nw_vrr") << "de_nw_vrr" << loc("Düsseldorf Hbf", 51.21991, 6.79419) << loc("Essen Hbf", 51.45127, 7.01388);
        QTest::newRow("de_nw_zks") << "de_nw_zks" << loc("Düsseldorf Hbf", 51.21991, 6.79419) << loc("Essen Hbf", 51.45127, 7.01388);
        // TODO de_rp_takt
        // TODO de_sh_sh
        // TODO de_sl_saarvv
        // TODO de_sn_vvo
        // TODO de_st_insa
        // TODO de_th_vmt

        QTest::newRow("fi_17_helsinki") << "fi_17_helsinki" << loc("Helsinki", 60.17174, 24.94148) << loc("Espoo", 60.20530, 24.65748);

        // TODO fr_ara_metromobilite

        // TODO it_21_piemonte
        // TODO it_21_torino

        // TODO us_ca_bart
        // TODO us_ca_la_metro
        // TODO us_ga_marta
        // TODO us_il_chicago
        // TODO us_ma_mbta
        // TODO us_or_trimet
        // TODO us_tx_cmta
    }

    void testBackend()
    {
        QFETCH(QString, backend);
        QFETCH(Location, loc1);
        QFETCH(Location, loc2);

        // location search by name
        {
            LocationRequest req;
            req.setBackendIds({backend});
            req.setName(loc1.name());
            auto reply = m_ptMgr.queryLocation(req);
            QSignalSpy spy(reply, &LocationReply::finished);
            QVERIFY(spy.wait(TIMEOUT));
            QCOMPARE(spy.size(), 1);
            QCOMPARE(reply->error(), Reply::NoError);
            QCOMPARE(reply->errorString(), QString());
            QVERIFY(reply->result().size() > 0);
        }

        // location search by coordinate
        {
            LocationRequest req;
            req.setBackendIds({backend});
            req.setCoordinate(loc2.latitude(), loc2.longitude());
            auto reply = m_ptMgr.queryLocation(req);
            QSignalSpy spy(reply, &LocationReply::finished);
            QVERIFY(spy.wait(TIMEOUT));
            QCOMPARE(reply->error(), Reply::NoError);
            QCOMPARE(reply->errorString(), QString());
            QCOMPARE(spy.size(), 1);
            QVERIFY(reply->result().size() > 0);
        }

        // departure by name
        {
            StopoverRequest req;
            req.setBackendIds({backend});
            Location loc;
            loc.setName(loc2.name());
            req.setStop(loc);
            auto reply = m_ptMgr.queryStopover(req);
            QSignalSpy spy(reply, &StopoverReply::finished);
            QVERIFY(spy.wait(TIMEOUT));
            QEXPECT_FAIL("no_entur", "name-based location search returns null results?!", Continue);
            QCOMPARE(reply->error(), Reply::NoError);
            QEXPECT_FAIL("no_entur", "name-based location search returns null results?!", Continue);
            QCOMPARE(reply->errorString(), QString());
            QCOMPARE(spy.size(), 1);
            QEXPECT_FAIL("no_entur", "name-based location search returns null results?!", Continue);
            QVERIFY(reply->result().size() > 0);
        }

        // departure by coordinate
        {
            StopoverRequest req;
            req.setBackendIds({backend});
            Location loc;
            loc.setCoordinate(loc1.latitude(), loc1.longitude());
            req.setStop(loc);
            auto reply = m_ptMgr.queryStopover(req);
            QSignalSpy spy(reply, &StopoverReply::finished);
            QVERIFY(spy.wait(TIMEOUT));
            QCOMPARE(reply->error(), Reply::NoError);
            QCOMPARE(reply->errorString(), QString());
            QCOMPARE(spy.size(), 1);
            QEXPECT_FAIL("at_4_ooevv", "needs investigation", Continue);
            QVERIFY(reply->result().size() > 0);
        }

        // journey
        {
            JourneyRequest req;
            req.setBackendIds({backend});
            req.setFrom(loc1);
            req.setTo(loc2);
            auto reply = m_ptMgr.queryJourney(req);
            QSignalSpy spy(reply, &JourneyReply::finished);
            QVERIFY(spy.wait(TIMEOUT));
            QCOMPARE(reply->error(), Reply::NoError);
            QCOMPARE(reply->errorString(), QString());
            QCOMPARE(spy.size(), 1);
            QVERIFY(reply->result().size() > 0);
        }
    }
};

QTEST_GUILESS_MAIN(QueryTest)

#include "querytest.moc"
