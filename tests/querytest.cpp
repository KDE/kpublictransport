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

    static bool hasRealtimeJourneyData(const std::vector<Journey> &journeys) {
        return std::any_of(journeys.begin(), journeys.end(), [](const auto &jny) {
            return std::any_of(jny.sections().begin(), jny.sections().end(), [](const auto &sec) {
                return sec.hasExpectedDepartureTime() || sec.hasExpectedArrivalTime() || sec.hasExpectedDeparturePlatform() || sec.hasExpectedArrivalPlatform();
            });
        });
    }

    static constexpr const auto TIMEOUT = 60000;

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
        QTest::newRow("un_navitia") << "un_navitia" << loc("Paris Gare de Lyon", 48.84444, 2.37412) << loc("Paris Aéroport Charles de Gaulle 2 TGV", 49.00423, 2.57215);
        QTest::newRow("un_navitia_qld") << "un_navitia" << loc("Brisbane King George Square Station",  -27.468903869, 153.0242799) << loc("Brisbane International Airport", -27.40029526, 153.0242500);

        // national
        QTest::newRow("at_oebb") << "at_oebb" << loc("Wien Hauptbahnhof", 48.18282, 16.37859) << loc("Linz/Donau Hbf", 48.29058, 14.29018);
        QTest::newRow("be_sncb") << "be_sncb" << loc("Bruxelles Midi", 50.83604, 4.33679) << loc("Mechelen", 51.01745, 4.48336);
        QTest::newRow("ch_opentransportdata") << "ch_opentransportdata" << loc("Zürich Flughafen", 47.45, 8.561) << loc("Randa", 46.09982, 7.78149);
        // endpoint defunct
        // QTest::newRow("ch_sbb") << "ch_sbb" << loc("Zürich Flughafen", 47.45015, 8.56199 ) << loc("Randa", 46.09982, 7.78149);
        QTest::newRow("de_db") << "de_db" << loc("Berlin Hauptbahnhof", 52.52509, 13.36946) << loc("Frankfurt Hbf", 50.10675, 8.66281);
        QTest::newRow("dk_dsb") << "dk_dsb" << loc("København H", 55.67228, 12.56442) << loc("Københavns Lufthavn Kastrup", 55.62940, 12.64872);
        QTest::newRow("ee_peatus") << "ee_peatus" << loc("Tallinn Hobujaama", 59.43727, 24.75824) << loc("Pärnu", 58.37254, 24.55502);
        QTest::newRow("eu_railteam") << "eu_railteam" << loc("Bruxelles Midi", 50.8353, 4.33679) << loc("Amsterdam Centraal", 52.37923, 4.90055);
        QTest::newRow("fi_digitransit") << "fi_digitransit" << loc("Helsinki", 60.17174, 24.94148) << loc("Espoo", 60.20530, 24.65748);
        QTest::newRow("fi_waltti") << "fi_waltti" << loc("Helsinki", 60.17174, 24.94148) << loc("Tampere", 61.49859, 23.77392);
        QTest::newRow("fr_sncf") << "fr_sncf" << loc("Paris Gare de Lyon", 48.84444, 2.37412) << loc("Paris Aéroport Charles de Gaulle 2 TGV", 49.00423, 2.57215);
        QTest::newRow("gb_traveline") << "gb_traveline" << loc( "London Euston", 51.52814, -0.13365) << loc("Glasgow Queen Street", 55.86252, -4.25074);
        QTest::newRow("ie_tfi") << "ie_tfi" << loc("Dublin Connolly", 53.35258, -6.24706) << loc("Cork Kent", 51.90159, -8.45823);
        QTest::newRow("lu_cfl") << "lu_cfl" << loc("Luxembourg Gare Centrale", 49.59962, 6.13473) << loc("Ettelbruck", 49.84745, 6.10645);
        QTest::newRow("nl_ns") << "nl_ns" << loc("Amsterdam Centraal", 52.37923, 4.90055) << loc("Den Haag Centraal", 52.08108, 4.32406);
        QTest::newRow("no_entur") << "no_entur" << loc("Oslo", 59.91157, 10.75413) << loc("Bergen", 60.39033, 5.33396);
        QTest::newRow("pl_pkp") << "pl_pkp" << loc("Warszawa Centralna", 52.228862, 21.00323295) << loc("Gdańsk Główny", 54.35625, 18.64417);
        QTest::newRow("se_resrobot") << "se_resrobot" << loc("Stockholm Central", 59.32976, 18.05715) << loc("Göteborgs centralstation", 57.70913, 11.97321);
        // TODO tn_sncft

        // local
        QTest::newRow("at_3_vor") << "at_3_vor" << loc("Wien Hauptbahnhof", 48.185184, 16.37641) << loc("Wien Flughafen", 48.12012, 16.56441);
        QTest::newRow("at_4_linz") << "at_4_linz" << loc("Linz/Donau Hbf", 48.29007, 14.29207) << loc("Hörsching", 48.24549, 14.18587);
        QTest::newRow("at_4_ooevv") << "at_4_ooevv" << loc("Linz/Donau Hbf", 48.29058, 14.29018) << loc("Hörsching", 48.24549, 14.18587);
        QTest::newRow("at_5_svv") << "at_5_svv" << loc("Salzburg Hbf", 47.81285, 13.04592) << loc("Freilassing", 47.83690, 12.97673);
        QTest::newRow("at_6_vvst") << "at_6_vvst" << loc("Graz Hauptbahnhof", 47.07236, 15.41665) << loc("Bruck an der Mur", 47.41413, 15.28000);
        QTest::newRow("at_7_vvt") << "at_7_vvt" << loc("Innsbruck Hbf", 47.26289, 11.40163) << loc("Kufstein", 47.58308, 12.16626);
        QTest::newRow("at_8_vvv") << "at_8_vvv" << loc("Bregenz", 47.50307, 9.74019) << loc("Dornbirn", 47.413280, 9.743741);
        QTest::newRow("at_9_wien") << "at_9_wien" << loc("Wien Hauptbahnhof", 48.18282, 16.37859) << loc("Wien Praterstern", 48.21870, 16.39247);

        QTest::newRow("au_nsw") << "au_nsw" << loc("Sydney Central", -33.88315, 151.20587) << loc("Sydney Internation Airport", -33.93503, 151.16603);

        QTest::newRow("ch_zh_zvv") << "ch_zh_zvv" << loc("Zürich Flughafen", 47.45015, 8.56199 ) << loc("Zürich HB", 47.37833, 8.53912);

        QTest::newRow("de_bb_bbnavi_angermuende") << "de_bb_bbnavi_angermuende" << loc("Angermünde", 53.01579, 13.99634) << loc("Schwedt", 53.06298, 14.29054);
        QTest::newRow("de_bb_vbb") << "de_bb_vbb" << loc("Berlin Hauptbahnhof", 52.52509, 13.36946) << loc("Berlin Alexanderplatz", 52.52147, 13.41134);
        QTest::newRow("de_be_bvg") << "de_be_bvg" << loc("Berlin Hauptbahnhof", 52.52509, 13.36946) << loc("Berlin Alexanderplatz", 52.52147, 13.41134);
        QTest::newRow("de_bw_bwegt") << "de_bw_bwegt" << loc("Stuttgart Hbf", 48.78539, 9.18345) << loc("Herrenberg", 48.59392, 8.86275);
        QTest::newRow("de_bw_kvv") << "de_bw_kvv" << loc("Karlsruhe Hbf", 48.99342, 8.40173 ) << loc("Ettlingen Stadt", 48.93867, 8.40953);
        QTest::newRow("de_bw_stadtnavi") << "de_bw_stadtnavi" << loc("Stuttgart Hbf", 48.78539, 9.18345) << loc("Herrenberg", 48.59392, 8.86275);
        QTest::newRow("de_bw_ulm") << "de_bw_ulm" << loc("Ulm Hbf", 48.39946, 9.98302) << loc("Neu Ulm", 48.39330, 10.00520);
        QTest::newRow("de_bw_vvs") << "de_bw_vvs" << loc("Stuttgart Hbf", 48.78539, 9.18345) << loc("Herrenberg", 48.59392, 8.86275);
        QTest::newRow("de_by_bayern") << "de_by_bayern" << loc("München Hbf", 48.14046, 11.55819) << loc("Nürnberg Hbf", 49.44559, 11.08219);
        QTest::newRow("de_by_invg") << "de_by_invg" << loc("Ingolstadt Hbf", 48.74436, 11.43746) << loc("Ingolstadt Nord", 48.77350, 11.43251);
        QTest::newRow("de_by_mvv") << "de_by_mvv" << loc("München Hbf", 48.14046, 11.55819) << loc("Isartor", 48.13375, 11.58303);
        QTest::newRow("de_by_vgn") << "de_by_vgn" << loc("Erlangen", 49.59591, 11.00220) << loc("Nürnberg Hbf", 49.44559, 11.08219);
        QTest::newRow("de_he_nvv") << "de_he_nvv" << loc("Kassel Hbf", 51.31836, 9.48946) << loc("Kassel Wilhelmshöhe", 51.31137, 9.44827);
        QTest::newRow("de_he_rmv") << "de_he_rmv" << loc("Frankfurt Hbf", 50.10675, 8.66281) << loc("Frankfurt Flughafen Regionalbf", 50.05129, 8.57170);
        QTest::newRow("de_hh_hvv") << "de_hh_hvv" << loc("Hamburg Hauptbahnhof", 53.55299, 10.00702) << loc("Hamburg Altona", 53.55284, 9.93569);
        QTest::newRow("de_mv_rsag") << "de_mv_rsag" << loc("Rostock Hauptbahnhof", 54.07814, 12.13206) << loc("Warnemünde Bahnhof", 54.17695, 12.09069);
        QTest::newRow("de_mv_vmv") << "de_mv_vmv" << loc("Rostock Hauptbahnhof", 54.07814, 12.13206) << loc("Stralsund Hbf", 54.30766, 13.07931);
        QTest::newRow("de_ni_efa") << "de_ni_efa" << loc("Hannover Hbf", 52.37715, 9.74171) << loc("Bremen Hbf", 53.08322, 8.81388);
        QTest::newRow("de_ni_gvh") << "de_ni_gvh" << loc("Hannover Hbf", 52.37715, 9.74171) << loc("Bremen Hbf", 53.08322, 8.81388);
        QTest::newRow("de_ni_vbn") << "de_ni_vbn" << loc("Hannover Hbf", 52.37715, 9.74171) << loc("Bremen Hbf", 53.08322, 8.81388);
        QTest::newRow("de_ni_vsn") << "de_ni_vsn" << loc("Osnabrück Hbf",52.27280, 8.06136) << loc("Göttingen", 51.53676, 9.92626);
        QTest::newRow("de_nw_avv") << "de_nw_avv" << loc("Aachen Hbf", 50.76784, 6.09130) << loc("Aachen West", 50.78025, 6.07124);
        // TODO de_nw_muenster
        QTest::newRow("de_nw_vrr") << "de_nw_vrr" << loc("Düsseldorf Hbf", 51.21991, 6.79419) << loc("Essen Hbf", 51.45127, 7.01388);
        QTest::newRow("de_nw_vrs") << "de_nw_vrs" << loc("Köln Hbf", 50.94305, 6.95908) << loc("Bonn Hbf", 50.73203, 7.09719);
        QTest::newRow("de_nw_zks") << "de_nw_zks" << loc("Düsseldorf Hbf", 51.21991, 6.79419) << loc("Essen Hbf", 51.45127, 7.01388);
        QTest::newRow("de_rp_rolph") << "de_rp_rolph" << loc("Mainz Hbf", 50.00113, 8.25865) << loc("Kaiserslautern Hauptbahnhof", 49.43607, 7.76849);
        QTest::newRow("de_rp_vrn") << "de_rp_vrn" << loc("Kaiserslautern Hauptbahnhof", 49.43607, 7.76849) << loc("Mannheim Hauptbahnhof", 49.47930, 8.46947);
        QTest::newRow("de_rp_vrt") << "de_rp_vrt" << loc("Trier Hauptbahnhof", 49.75687, 6.65245) << loc("Wittlich Hauptbahnhof", 49.97306, 6.94357);
        QTest::newRow("de_sh_sh") << "de_sh_sh" << loc("Hamburg Hauptbahnhof", 53.55299, 10.00702) << loc("Hamburg-Altona", 53.55284, 9.93569);
        QTest::newRow("de_sl_saarvv") << "de_sl_saarvv" << loc("Saarbrücken Hauptbahnhof", 49.24116, 6.99110) << loc("Saarlouis Hbf", 49.32766, 6.75103);
        QTest::newRow("de_sn_vvo") << "de_sn_vvo" << loc("Dresden Hbf", 51.04025, 13.73160) << loc("Chemnitz Hauptbahnhof", 50.83981, 12.93069);
        QTest::newRow("de_st_insa") << "de_st_insa" << loc("Leipzig Hbf", 51.34508, 12.38196) << loc("Leipzig S Bahnhof Messe", 51.39603, 12.38987);
        QTest::newRow("de_th_vmt") << "de_th_vmt" << loc("Erfurt Hbf", 50.97227, 11.03790) << loc("Jena Paradies", 50.92491, 11.58725);

        QTest::newRow("fi_17_helsinki") << "fi_17_helsinki" << loc("Helsinki", 60.17174, 24.94148) << loc("Espoo", 60.20530, 24.65748);

        QTest::newRow("fr_ara_metromobilite") << "fr_ara_metromobilite" << loc("Grenoble", 45.19140, 5.71449) << loc("Échorolles", 45.15272, 5.71976);

        // TODO it_21_piemonte
        QTest::newRow("it_21_torino") << "it_21_torino" << loc("Torino Porta Nuova", 45.06098, 7.67777) << loc("Torino Dora GTT", 45.09068, 7.67700);

        QTest::newRow("us_ca_bart") << "us_ca_bart" << loc("San Francisco International Airport (SFO)", 37.61622, -122.39180) << loc("San Francisco Powell Street",  37.78441, -122.40767);
        QTest::newRow("us_ca_la_metro") << "us_ca_la_metro" << loc("Los Angeles Union Station", 34.05563, -118.23407) << loc("South Pasadena", 34.11518, -118.15811);
        QTest::newRow("us_ga_marta") << "us_ga_marta" << loc("Five Points", 33.75390, -84.39140) << loc("Airport", 33.64084, -84.44637);
        // TODO us_il_chicago
        QTest::newRow("us_ma_mbta") << "us_ma_mbta" << loc("Boston South Station", 42.35057, -71.05535) << loc("Boston North Station", 42.36696, -71.06263);
        // TODO us_or_trimet
        QTest::newRow("us_tx_cmta") << "us_tx_cmta" << loc("Downtown", 30.26487, -97.73928) << loc("crestview", 30.33921, -97.71968);
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
            QEXPECT_FAIL("us_ga_marta", "needs investigation", Continue);
            QCOMPARE(reply->error(), Reply::NoError);
            QEXPECT_FAIL("us_ga_marta", "needs investigation", Continue);
            QCOMPARE(reply->errorString(), QString());
            QEXPECT_FAIL("fr_ara_metromobilite", "needs investigation", Continue);
            QEXPECT_FAIL("it_21_torino", "needs investigation", Continue);
            QEXPECT_FAIL("us_ga_marta", "needs investigation", Continue);
            QVERIFY(reply->result().size() > 0);
        }

        // location search by coordinate
        {
            LocationRequest req;
            req.setBackendIds({backend});
            req.setCoordinate(loc2.latitude(), loc2.longitude());
            req.setMaximumResults(1);
            auto reply = m_ptMgr.queryLocation(req);
            QSignalSpy spy(reply, &LocationReply::finished);
            QVERIFY(spy.wait(TIMEOUT));
            QCOMPARE(reply->error(), Reply::NoError);
            QCOMPARE(reply->errorString(), QString());
            QCOMPARE(spy.size(), 1);
            QEXPECT_FAIL("at_6_vvst", "needs investigation", Continue);
            QEXPECT_FAIL("fr_ara_metromobilite", "needs investigation", Continue);
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
            QEXPECT_FAIL("it_21_torino", "needs investigation", Continue);
            QEXPECT_FAIL("us_ca_la_metro", "needs investigation", Continue);
            QEXPECT_FAIL("us_ga_marta", "needs investigation", Continue);
            QEXPECT_FAIL("us_ma_mbta", "needs investigation", Continue);
            QCOMPARE(reply->error(), Reply::NoError);
            QEXPECT_FAIL("no_entur", "name-based location search returns null results?!", Continue);
            QEXPECT_FAIL("it_21_torino", "needs investigation", Continue);
            QEXPECT_FAIL("us_ca_la_metro", "needs investigation", Continue);
            QEXPECT_FAIL("us_ga_marta", "needs investigation", Continue);
            QEXPECT_FAIL("us_ma_mbta", "needs investigation", Continue);
            QCOMPARE(reply->errorString(), QString());
            QCOMPARE(spy.size(), 1);
            QEXPECT_FAIL("no_entur", "name-based location search returns null results?!", Continue);
            QEXPECT_FAIL("fr_ara_metromobilite", "needs investigation", Continue);
            QEXPECT_FAIL("it_21_torino", "needs investigation", Continue);
            QEXPECT_FAIL("us_ca_la_metro", "needs investigation", Continue);
            QEXPECT_FAIL("us_ga_marta", "needs investigation", Continue);
            QEXPECT_FAIL("us_ma_mbta", "needs investigation", Continue);
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
            QEXPECT_FAIL("at_3_vor", "needs investigation", Continue);
            QEXPECT_FAIL("at_4_ooevv", "needs investigation", Continue);
            QEXPECT_FAIL("at_8_vvv", "needs investigation", Continue);
            QEXPECT_FAIL("fr_ara_metromobilite", "needs investigation", Continue);
            QEXPECT_FAIL("pl_pkp", "needs investigation", Continue);
            QEXPECT_FAIL("us_ca_la_metro", "needs investigation", Continue);
            QEXPECT_FAIL("us_ma_mbta", "needs investigation", Continue);
            QVERIFY(reply->result().size() > 0);
        }

        // journey
        {
            JourneyRequest req;
            req.setBackendIds({backend});
            req.setFrom(loc1);
            req.setTo(loc2);
            req.setMaximumResults(1);
            auto reply = m_ptMgr.queryJourney(req);
            QSignalSpy spy(reply, &JourneyReply::finished);
            QVERIFY(spy.wait(TIMEOUT));
            QCOMPARE(reply->error(), Reply::NoError);
            QCOMPARE(reply->errorString(), QString());
            QCOMPARE(spy.size(), 1);
            QVERIFY(reply->result().size() > 0);
            qDebug() << "Journey realtime data:" << hasRealtimeJourneyData(reply->result());
        }
    }
};

QTEST_GUILESS_MAIN(QueryTest)

#include "querytest.moc"
