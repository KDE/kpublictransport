/*
    SPDX-License-Identifier: ODbL-1.0

    Generated code based on data from OpenStreetMap (ODbL) and Wikidata (CC0), do not edit!
*/

#include "linemetadata_p.h"

namespace KPublicTransport {

static const char line_name_stringtab[] = {
    "M4\0"
    "M5\0"
    "U12\0"
    "M8\0"
    "318\0"
    "S16\0"
    "SFM6\0"
    "S7\0"
    "S75\0"
    "S5\0"
    "S8\0"
    "Straßenbahn S2: Spöck <=> Rheinstetten\0"
    "S11\0"
    "M13\0"
    "S1\0"
    "M10\0"
    "S21\0"
    "63\0"
    "61\0"
    "S68\0"
    "62\0"
    "37\0"
    "U70\0"
    "U76\0"
    "U77\0"
    "S60\0"
    "S3\0"
    "67\0"
    "N27\0"
    "M17\0"
    "50\0"
    "U79\0"
    "S24\0"
    "S2\0"
    "215\0"
    "S6\0"
    "65\0"
    "U6\0"
    "S4\0"
    "RS 1\0"
    "U9\0"
    "U8\0"
    "U7\0"
    "U3\0"
    "U2\0"
    "U4\0"
    "U5\0"
    "U55\0"
    "U1\0"
    "U14\0"
    "EDid;Sh&C\0"
    "SFMA\0"
    "HBB\0"
    "U19\0"
    "N17\0"
    "S25\0"
    "S46\0"
    "S45\0"
    "N20\0"
    "S23;RB23\0"
    "A3\0"
    "M1\0"
    "4;4E\0"
    "181 (SN)\0"
    "S85\0"
    "U\0"
    "APOR\0"
    "K\0"
    "S9\0"
    "SIR1\0"
    "PURP\0"
    "T1\0"
    "U13\0"
    "T2\0"
    "TT\0"
    "S13\0"
    "U11\0"
    "N10\0"
    "N4\0"
    "N1\0"
    "N82\0"
    "308\0"
    "310\0"
    "U35\0"
    "306\0"
    "302\0"
    "301\0"
    "S 5\0"
    "98\0"
    "91\0"
    "92\0"
    "93\0"
    "94\0"
    "S33\0"
    "N19\0"
    "S10\0"
    "96\0"
    "99\0"
    "S12\0"
    "D\0"
    "R143\0"
    "M2\0"
    "U75\0"
    "U78\0"
    "F\0"
    "S20\0"
    "87\0"
    "S51\0"
    "S47\0"
    "S28\0"
    "7bis\0"
    "RS 4\0"
    "22\0"
    "S26\0"
    "M\0"
    "S29\0"
    "T5\0"
    "S 7\0"
    "RS 3\0"
    "Metropolitana\0"
    "M3\0"
    "S31\0"
    "S32\0"
    "S52\0"
    "95\0"
    "RS 2\0"
    "S42\0"
    "44\0"
    "39\0"
    "T3\0"
    "T3b\0"
    "T4\0"
    "T8\0"
    "97\0"
    "S19\0"
    "54\0"
    "53\0"
    "m2\0"
    "A2\0"
    "U17\0"
    "A1\0"
    "U71\0"
    "U83\0"
    "U73\0"
    "U72\0"
    "U42\0"
    "U45\0"
    "NL1\0"
    "NL2\0"
    "Victoria\0"
    "TL 1\0"
    "SN 5\0"
    "S14\0"
    "U74\0"
    "S71\0"
    "S81\0"
    "J\0"
    "T3a\0"
    "T6\0"
    "T7\0"
    "OrlyVAL\0"
    "CDGVAL\0"
    "Central\0"
    "S41\0"
    "3bis\0"
    "H\0"
    "N\0"
    "Bakerloo\0"
    "Hammersmith & City\0"
    "Circle\0"
    "Waterloo & City\0"
    "Jubilee\0"
    "Metropolitan\0"
    "District\0"
    "Piccadilly\0"
    "Northern\0"
    "ODEA\0"
    "ADEO\0"
    "VOBA\0"
    "AVOL\0"
    "U34\0"
    "S 9\0"
    "S 6\0"
    "S15\0"
    "S30\0"
    "S35\0"
    "S40\0"
    "T11\0"
    "11*\0"
    "U16\0"
    "U29\0"
    "U15\0"
    "S36\0"
    "BLUE\0"
    "YELL\0"
    "Overground\0"
    "21A\0"
    "EDid;Roch\0"
    "Airp;Vict;Dean\0"
    "MCUK;Asht\0"
    "Asht;Eccl\0"
    "Altr;Picc\0"
    "Bury;Picc\0"
    "Bury;Altr\0"
    "TrfC;Crmp\0"
    "305\0"
    "309\0"
    "316\0"
    "RB 32\0"
    "L5\0"
    "L6\0"
    "L4\0"
    "L3\0"
};

static const char line_logo_stringtab[] = {
    "Berlin S7.svg\0"
    "S-Bahn-Logo.svg\0"
    "Berlin S5.svg\0"
    "Berlin S8.svg\0"
    "Stadtbahn.svg\0"
    "Berlin S3.svg\0"
    "Berlin U6.svg\0"
    "U-Bahn.svg\0"
    "München S8.svg\0"
    "München S4.svg\0"
    "Berlin U9.svg\0"
    "Berlin U8.svg\0"
    "Berlin U7.svg\0"
    "Berlin U3.svg\0"
    "Berlin U2.svg\0"
    "Berlin U4.svg\0"
    "Berlin U5.svg\0"
    "Berlin U55.svg\0"
    "Berlin U1.svg\0"
    "Prague Metro Line C.svg\0"
    "Prag Metro Logo.svg\0"
    "Prague Metro Line A.svg\0"
    "Prague Metro Line B.svg\0"
    "Berlin S2.svg\0"
    "Berlin S25.svg\0"
    "Hamburg U3.svg\0"
    "München S1.svg\0"
    "München S6.svg\0"
    "Berlin S46.svg\0"
    "Hamburg A3.svg\0"
    "S-Bahn Austria.svg\0"
    "Berlin S85.svg\0"
    "Logo Paris Transilien ligneU.svg\0"
    "Logo Paris Transilien ligneK.svg\0"
    "Berlin S9.svg\0"
    "München S5.svg\0"
    "Logo Paris Transilien ligneP.svg\0"
    "Logo Metropolitane Italia.svg\0"
    "Berlin S1.svg\0"
    "Frankfurt S7.svg\0"
    "Milano S3.svg\0"
    "Linee S di Milano.svg\0"
    "Milano S1.svg\0"
    "Milano S13.svg\0"
    "Milano S4.svg\0"
    "Milano S2.svg\0"
    "Frankfurt U2.svg\0"
    "Logo Paris tram ligne1.svg\0"
    "Paris logo tram jms.svg\0"
    "Paris RER D icon.svg\0"
    "RER.svg\0"
    "Nürnberg U2.svg\0"
    "Hamburg U2.svg\0"
    "Hamburg U1.svg\0"
    "Nürnberg U3.svg\0"
    "Nürnberg U1.svg\0"
    "Frankfurt S6.svg\0"
    "München S20.svg\0"
    "München S7.svg\0"
    "Paris RER A icon.svg\0"
    "Berlin S47.svg\0"
    "Frankfurt S3.svg\0"
    "Frankfurt S5.svg\0"
    "Frankfurt S4.svg\0"
    "Paris m 7bis jms.svg\0"
    "Metro-M.svg\0"
    "Lyon tcl tram-5.svg\0"
    "Milano linea M5.svg\0"
    "Hamburg U4.svg\0"
    "Paris m 4 jms.svg\0"
    "Paris m 14 jms.svg\0"
    "Paris m 1 jms.svg\0"
    "Paris m 9 jms.svg\0"
    "München U4.svg\0"
    "Paris m 10 jms.svg\0"
    "Paris m 6 jms.svg\0"
    "Paris m 7 jms.svg\0"
    "Frankfurt S1.svg\0"
    "Frankfurt S2.svg\0"
    "Frankfurt S8.svg\0"
    "Frankfurt S9.svg\0"
    "München U5.svg\0"
    "München U6.svg\0"
    "München U3.svg\0"
    "Frankfurt U6.svg\0"
    "München U1.svg\0"
    "München U2.svg\0"
    "München U7.svg\0"
    "München U8.svg\0"
    "S-Bahn Salzburg.svg\0"
    "Logo Paris tram ligne3b.svg\0"
    "Logo Metro Rennes.svg\0"
    "Logo Paris tram ligne8.svg\0"
    "Amsterdam metro logo.svg\0"
    "Logo du M2 de Lausanne.svg\0"
    "Logo Métro Lausanne.svg\0"
    "Frankfurt U1.svg\0"
    "Frankfurt U3.svg\0"
    "Frankfurt U4.svg\0"
    "Frankfurt U5.svg\0"
    "Frankfurt U7.svg\0"
    "Frankfurt U8.svg\0"
    "Frankfurt U9.svg\0"
    "Hamburg A2.svg\0"
    "Hamburg A1.svg\0"
    "Metro Rotterdam logo.svg\0"
    "Map Point.png\0"
    "Victoria line roundel.svg\0"
    "Underground.svg\0"
    "Logo Paris Transilien ligneJ.svg\0"
    "Logo Paris tram ligne4.svg\0"
    "Logo Paris tram ligne5.svg\0"
    "Logo Paris tram ligne7.svg\0"
    "STIB-MIVB Line 5.svg\0"
    "Brussels Metro Logo.svg\0"
    "STIB-MIVB Line 1.svg\0"
    "München S2.svg\0"
    "STIB-MIVB Line 7.svg\0"
    "Brussels tramway icon.svg\0"
    "Paris m 2 jms.svg\0"
    "Central Line roundel.svg\0"
    "Paris RER E icon.svg\0"
    "STIB-MIVB Line 2.svg\0"
    "Berlin S41.svg\0"
    "NMBS S-Trein logo.svg\0"
    "Paris m 13 jms.svg\0"
    "Paris m 12 jms.svg\0"
    "Paris m 11 jms.svg\0"
    "Paris m 8 jms.svg\0"
    "Paris m 5 jms.svg\0"
    "Paris m 3bis jms.svg\0"
    "Logo Paris Transilien ligneR.svg\0"
    "Logo Paris Transilien ligneN.svg\0"
    "Paris RER B icon.svg\0"
    "Bakerloo line roundel.svg\0"
    "H&c line roundel.svg\0"
    "Circle Line roundel.svg\0"
    "W&c line roundel.svg\0"
    "Jubilee line roundel.svg\0"
    "Metropolitan line roundel.svg\0"
    "District line roundel.svg\0"
    "Piccadilly line roundel.svg\0"
    "Northern line roundel.svg\0"
    "Paris m 3 jms.svg\0"
    "Logo Paris Transilien ligneH.svg\0"
    "Symbole Lille 2.svg\0"
    "Lille Metro Logo 2017.svg\0"
    "Symbole Lille 1.svg\0"
    "STIB-MIVB Line 3.svg\0"
    "STIB-MIVB Line 6.svg\0"
    "STIB-MIVB Line 4.svg\0"
    "STIB-MIVB Line 25.svg\0"
    "STIB-MIVB Line 55.svg\0"
    "STIB-MIVB Line 82.svg\0"
    "Logo Paris tram ligne11 SNCF.svg\0"
    "Logo Paris Transilien ligneL.svg\0"
    "Milano S5.svg\0"
    "Milano S6.svg\0"
    "Milano S8.svg\0"
    "Milano S9.svg\0"
    "Milano S11.svg\0"
    "Berlin S26.svg\0"
    "Overground roundel.svg\0"
    "Berlin S42.svg\0"
    "Milano linea M2.svg\0"
    "Milano linea M3.svg\0"
    "Milano linea M1.svg\0"
};

static const constexpr auto NoLogo = 13;

static const constexpr LineMetaDataContent line_data[] = {
    { 0, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xbb0000} }, // M4 OSM: 11134 52.52, 13.4 x 52.57, 13.53
    { 3, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xcc9933} }, // M5 OSM: 11135 52.52, 13.36 x 52.57, 13.52
    { 7, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x996699} }, // 12 OSM: 11140 52.52, 13.38 x 52.56, 13.47
    { 10, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff6633} }, // M8 OSM: 11141 52.52, 13.36 x 52.57, 13.58
    { 14, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff6633} }, // 18 OSM: 11142 52.53, 13.54 x 52.55, 13.62
    { 18, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x006699} }, // 16 OSM: 11143 52.51, 13.47 x 52.57, 13.58
    { 23, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x003388} }, // M6 OSM: 11145 52.52, 13.4 x 52.55, 13.62
    { 8, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 2 OSM: 11201 51.17, 4.35 x 51.26, 4.464
    { 26, 0, 14, LineMetaDataContent::RapidTransit, Color{0x8070b7} }, // S7 OSM: 14809 WD: Q7388362 52.39, 13.07 x 52.57, 13.57
    { 29, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x8070b7} }, // S75 OSM: 14810 52.5, 13.43 x 52.57, 13.54
    { 33, 30, 14, LineMetaDataContent::RapidTransit, Color{0xf25721} }, // S5 OSM: 14811 WD: Q3743008 52.5, 13.28 x 52.59, 13.91
    { 36, 44, 14, LineMetaDataContent::RapidTransit, Color{0x52b447} }, // S8 OSM: 14984 WD: Q4048678 52.35, 13.29 x 52.69, 13.63
    { 39, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x9313ba} }, // Straßenbahn S2: Spöck <=> Rheinstetten OSM: 16111 48.95, 8.283 x 49.11, 8.505
    { 82, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xb3ee3a} }, // 1 OSM: 17413 WD: Q318073 51.49, 10.79 x 51.52, 10.8
    { 8, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x2e8b57} }, // 2 OSM: 17415 WD: Q318073 51.5, 10.78 x 51.51, 10.82
    { 86, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x996633} }, // 3 OSM: 17839 48.99, 8.347 x 49.04, 8.411
    { 82, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 1 OSM: 17840 48.98, 8.347 x 49.02, 8.479
    { 80, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // S11 OSM: 17842 48.87, 8.373 x 49.13, 8.518
    { 88, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // S1 OSM: 17843 48.8, 8.373 x 49.13, 8.458
    { 4, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x18a6d9} }, // 5 OSM: 17847 49, 8.347 x 49.02, 8.444
    { 1, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffcc00} }, // 4 OSM: 17848 48.99, 8.347 x 49.05, 8.452
    { 36, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x6d682a} }, // S8 OSM: 17849 48.46, 8.215 x 49.01, 8.435
    { 11, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff9933} }, // 8 OSM: 17855 48.98, 8.452 x 49, 8.479
    { 91, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x108449} }, // M10 OSM: 17865 52.5, 13.36 x 52.54, 13.45
    { 84, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00cc00} }, // M13 OSM: 17884 52.51, 13.34 x 52.56, 13.48
    { 96, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x996699} }, // 21 OSM: 17885 52.45, 13.45 x 52.53, 13.52
    { 99, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009999} }, // 63 OSM: 19115 52.43, 13.52 x 52.5, 13.61
    { 102, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x669933} }, // 61 OSM: 19265 52.43, 13.52 x 52.46, 13.69
    { 106, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009933} }, // 68 OSM: 19271 52.37, 13.57 x 52.46, 13.65
    { 109, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x006633} }, // 62 OSM: 19296 52.42, 13.57 x 52.51, 13.61
    { 112, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x993333} }, // 37 OSM: 19451 52.45, 13.5 x 52.53, 13.53
    { 92, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf8b710} }, // 10 OSM: 19925 WD: Q143861 48.75, 9.167 x 48.76, 9.174
    { 92, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x312783} }, // 10 OSM: 19941 53.06, 8.752 x 53.12, 8.9
    { 8, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x005ca9} }, // 2 OSM: 19942 53.06, 8.752 x 53.12, 8.9
    { 8, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf287b6} }, // 2 OSM: 22852 54.08, 12.08 x 54.11, 12.17
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf8a500} }, // 6 OSM: 22871 54.07, 12.09 x 54.09, 12.14
    { 82, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x5d106a} }, // 1 OSM: 23389 54.09, 12.05 x 54.16, 12.16
    { 86, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x690713} }, // 3 OSM: 23742 54.07, 12.09 x 54.11, 12.18
    { 1, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc30175} }, // 4 OSM: 23743 54.07, 12.1 x 54.11, 12.18
    { 4, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe2001d} }, // 5 OSM: 23747 54.06, 12.05 x 54.16, 12.14
    { 115, 58, 58, LineMetaDataContent::Subway, Color{0x302276} }, // U70 OSM: 27662 WD: Q661002 51.22, 6.566 x 51.33, 6.796
    { 119, 58, 58, LineMetaDataContent::Subway, Color{0x302276} }, // U76 OSM: 27663 WD: Q661002 51.22, 6.566 x 51.33, 6.806
    { 123, 58, 58, LineMetaDataContent::Subway, Color{0x302276} }, // U77 OSM: 27667 WD: Q661002 51.17, 6.735 x 51.24, 6.834
    { 128, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x669933} }, // 60 OSM: 28289 52.44, 13.5 x 52.46, 13.64
    { 131, 72, 14, LineMetaDataContent::RapidTransit, Color{0x055a99} }, // S3 OSM: 28314 WD: Q7388282 52.43, 13.2 x 52.54, 13.75
    { 134, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009933} }, // 67 OSM: 28352 52.44, 13.51 x 52.46, 13.59
    { 138, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x993333} }, // 27 OSM: 28377 52.44, 13.46 x 52.56, 13.59
    { 141, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x9900aa} }, // M17 OSM: 28391 52.45, 13.51 x 52.57, 13.53
    { 145, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x36ab94} }, // 50 OSM: 28420 52.54, 13.34 x 52.61, 13.43
    { 148, 58, 58, LineMetaDataContent::Subway, Color{0x302276} }, // U79 OSM: 28424 WD: Q661002 51.19, 6.739 x 51.47, 6.815
    { 96, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x3251a3} }, // 21 OSM: 29440 WD: Q4415661 51.91, 4.368 x 51.94, 4.525
    { 153, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x3251a3} }, // 24 OSM: 29446 WD: Q14500289 51.91, 4.341 x 51.94, 4.525
    { 81, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xd62631} }, // 11 OSM: 33897 51.28, 12.22 x 51.4, 12.4
    { 92, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xd62631} }, // 10 OSM: 33900 51.3, 12.32 x 51.37, 12.4
    { 18, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe3000f} }, // 16 OSM: 34068 51.3, 12.38 x 51.4, 12.4
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0e4094} }, // 7 OSM: 34148 51.34, 12.27 x 51.36, 12.48
    { 106, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xcea4cb} }, // 68 OSM: 34480 50.7, 6.985 x 50.76, 7.156
    { 88, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x5c8e3c} }, // S1 OSM: 35610 48.59, 8.861 x 48.8, 9.444
    { 156, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff2e1d} }, // S2 OSM: 35611 48.68, 9.105 x 48.83, 9.527
    { 131, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff7d24} }, // S3 OSM: 35612 48.69, 9.105 x 48.94, 9.428
    { 150, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe6877e} }, // 9 OSM: 36132 50.92, 6.907 x 50.94, 7.097
    { 7, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8cc63f} }, // 12 OSM: 36133 50.9, 6.939 x 51.03, 6.96
    { 160, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00accd} }, // 15 OSM: 36134 50.92, 6.898 x 51.02, 6.966
    { 150, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfecc00} }, // 9 OSM: 36930 51.3, 12.37 x 51.38, 12.43
    { 163, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x874a0a} }, // S6 OSM: 37419 48.76, 8.872 x 48.83, 9.195
    { 160, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0e4094} }, // 15 OSM: 38883 51.29, 12.26 x 51.34, 12.44
    { 166, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc8d300} }, // 65 OSM: 39079 50.72, 7.071 x 50.76, 7.156
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x9049a8} }, // 6 OSM: 48024 52.09, 11.61 x 52.15, 11.68
    { 82, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xb6005c} }, // 1 OSM: 48025 52.11, 11.58 x 52.17, 11.64
    { 1, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x73e700} }, // 4 OSM: 48453 52.11, 11.58 x 52.16, 11.67
    { 4, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xb48654} }, // 5 OSM: 48459 52.11, 11.57 x 52.14, 11.67
    { 82, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x62b32c} }, // 1 OSM: 51858 51.31, 12.26 x 51.38, 12.42
    { 8, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf7c53a} }, // 2 OSM: 51859 51.29, 12.28 x 51.34, 12.44
    { 169, 86, 100, LineMetaDataContent::Subway, Color{0x8070b7} }, // U6 OSM: 51942 WD: Q99720 52.44, 13.28 x 52.59, 13.39
    { 36, 111, 14, LineMetaDataContent::RapidTransit, Color{0xffc734} }, // S8 OSM: 53231 WD: Q17148488 48, 11.17 x 48.35, 11.79
    { 172, 127, 14, LineMetaDataContent::RapidTransit, Color{0xff2d1d} }, // S4 OSM: 53235 WD: Q7388308 48.04, 11.04 x 48.18, 11.97
    { 150, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x1e8164} }, // 9 OSM: 53748 52.08, 11.6 x 52.18, 11.64
    { 8, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x004799} }, // 2 OSM: 53752 52.06, 11.63 x 52.15, 11.68
    { 11, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf29400} }, // 8 OSM: 53770 52.06, 11.63 x 52.18, 11.68
    { 163, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x3d2d7c} }, // S6 OSM: 53844 48.75, 8.549 x 48.9, 8.705
    { 92, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xaac1e1} }, // 10 OSM: 54125 52.11, 11.59 x 52.21, 11.67
    { 92, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x9acd32} }, // 10 OSM: 54452 WD: Q318073 51.49, 10.77 x 51.58, 10.8
    { 82, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xda0873} }, // 1 OSM: 54602 53.59, 11.41 x 53.65, 11.47
    { 8, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xd9261c} }, // 2 OSM: 54603 53.59, 11.36 x 53.65, 11.47
    { 86, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe87878} }, // 3 OSM: 54604 53.57, 11.38 x 53.6, 11.47
    { 1, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xdb214c} }, // 4 OSM: 54605 53.57, 11.38 x 53.65, 11.43
    { 86, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffd600} }, // 3 OSM: 55097 52.13, 11.57 x 52.16, 11.62
    { 176, NoLogo, 14, LineMetaDataContent::RapidTransit, Color{0x408040} }, // S 1 OSM: 55107 WD: Q56378592 52, 11.62 x 53.01, 11.87
    { 180, 143, 100, LineMetaDataContent::Subway, Color{0xff7300} }, // U9 OSM: 58423 WD: Q99744 52.46, 13.32 x 52.56, 13.37
    { 183, 157, 100, LineMetaDataContent::Subway, Color{0x055a99} }, // U8 OSM: 58424 WD: Q99729 52.47, 13.33 x 52.6, 13.43
    { 186, 171, 100, LineMetaDataContent::Subway, Color{0x0b9ada} }, // U7 OSM: 58425 WD: Q99725 52.42, 13.2 x 52.54, 13.5
    { 189, 185, 100, LineMetaDataContent::Subway, Color{0x15ac99} }, // U3 OSM: 58426 WD: Q99702 52.44, 13.24 x 52.51, 13.45
    { 192, 199, 100, LineMetaDataContent::Subway, Color{0xff3300} }, // U2 OSM: 58428 WD: Q99697 52.5, 13.24 x 52.57, 13.41
    { 195, 213, 100, LineMetaDataContent::Subway, Color{0xffcd00} }, // U4 OSM: 58429 WD: Q99708 52.48, 13.34 x 52.5, 13.36
    { 198, 227, 100, LineMetaDataContent::Subway, Color{0x7d533d} }, // U5 OSM: 58430 WD: Q99711 52.49, 13.41 x 52.54, 13.63
    { 201, 241, 100, LineMetaDataContent::Subway, Color{0x7d533d} }, // U55 OSM: 58431 WD: Q99715 52.52, 13.37 x 52.53, 13.38
    { 205, 256, 100, LineMetaDataContent::Subway, Color{0x52b447} }, // U1 OSM: 58767 WD: Q99691 52.5, 13.33 x 52.51, 13.45
    { 7, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0e4094} }, // 12 OSM: 58815 51.32, 12.37 x 51.38, 12.4
    { 11, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf7c53a} }, // 8 OSM: 58819 51.32, 12.28 x 51.36, 12.47
    { 209, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00a6e7} }, // 14 OSM: 58827 51.33, 12.32 x 51.34, 12.38
    { 86, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x62b32c} }, // 3 OSM: 58829 51.28, 12.31 x 51.38, 12.49
    { 220, 270, 294, LineMetaDataContent::Subway, Color{0xcf003d} }, // C OSM: 58898 WD: Q168571 50.03, 14.43 x 50.13, 14.53
    { 225, 314, 294, LineMetaDataContent::Subway, Color{0x00a562} }, // A OSM: 58899 WD: Q1292805 50.07, 14.34 x 50.1, 14.52
    { 229, 338, 294, LineMetaDataContent::Subway, Color{0xf8b322} }, // B OSM: 58900 WD: Q1460442 50.04, 14.29 x 50.11, 14.58
    { 142, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x865a46} }, // 17 OSM: 61454 48.13, 11.49 x 48.18, 11.64
    { 232, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xed1c24} }, // 19 OSM: 61456 48.14, 11.46 x 48.15, 11.63
    { 14, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0cb14b} }, // 18 OSM: 61458 48.1, 11.49 x 48.14, 11.6
    { 235, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x006cb2} }, // N17 OSM: 61459 48.13, 11.49 x 48.17, 11.61
    { 82, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf78a21} }, // 1 OSM: 61460 50.85, 12.07 x 50.89, 12.09
    { 156, 362, 14, LineMetaDataContent::RapidTransit, Color{0x018a47} }, // S2 OSM: 61466 WD: Q3743635 52.34, 13.36 x 52.68, 13.59
    { 239, 376, 14, LineMetaDataContent::RapidTransit, Color{0x018a47} }, // S25 OSM: 61469 WD: Q7388229 52.4, 13.21 x 52.64, 13.4
    { 189, 391, 100, LineMetaDataContent::Subway, Color{0xfcdf00} }, // U3 OSM: 62839 WD: Q781351 53.54, 9.969 x 53.59, 10.08
    { 88, 406, 14, LineMetaDataContent::RapidTransit, Color{0x36caec} }, // S1 OSM: 63809 WD: Q7388207 48.13, 11.48 x 48.4, 11.79
    { 163, 422, 14, LineMetaDataContent::RapidTransit, Color{0x00ac6f} }, // S6 OSM: 63839 WD: Q7388348 47.91, 11.27 x 48.15, 11.97
    { 86, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff7f00} }, // 3 OSM: 63875 51.82, 12.18 x 51.84, 12.24
    { 243, 438, 14, LineMetaDataContent::RapidTransit, Color{0xba8a4d} }, // S46 OSM: 64094 WD: Q3737194 52.3, 13.28 x 52.52, 13.64
    { 247, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xba8a4d} }, // S45 OSM: 64095 52.39, 13.36 x 52.48, 13.57
    { 160, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf58f98} }, // 15 OSM: 66007 48.08, 11.55 x 48.14, 11.6
    { 240, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf58f98} }, // 25 OSM: 66008 48.04, 11.52 x 48.14, 11.6
    { 7, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x903f98} }, // 12 OSM: 66043 48.15, 11.51 x 48.17, 11.58
    { 18, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x006cb2} }, // 16 OSM: 66044 48.13, 11.51 x 48.18, 11.64
    { 138, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfaa61a} }, // 27 OSM: 66053 48.13, 11.56 x 48.18, 11.58
    { 252, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00bfe8} }, // 20 OSM: 66079 48.14, 11.51 x 48.18, 11.56
    { 96, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00bfe8} }, // 21 OSM: 66080 48.12, 11.53 x 48.17, 11.64
    { 261, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xb2d233} }, // 23 OSM: 66100 48.16, 11.59 x 48.19, 11.59
    { 264, 453, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe67310} }, // A3 OSM: 66588 WD: Q19606155 53.75, 9.656 x 53.8, 9.983
    { 172, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0065b7} }, // S4 OSM: 66840 48.77, 9.155 x 48.95, 9.428
    { 267, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xee6600} }, // M1 OSM: 67233 52.52, 13.37 x 52.6, 13.41
    { 33, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00b7e1} }, // S5 OSM: 67283 48.77, 9.122 x 48.95, 9.195
    { 86, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf59e00} }, // 3 OSM: 69178 47.97, 7.796 x 48, 7.85
    { 82, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe8001b} }, // 1 OSM: 69191 47.98, 7.808 x 48.03, 7.895
    { 4, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008bc5} }, // 5 OSM: 69199 47.99, 7.787 x 48, 7.852
    { 8, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x646363} }, // 2 OSM: 69202 47.96, 7.833 x 48.02, 7.858
    { 82, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf6a6ab} }, // 1 OSM: 71785 47.25, 11.39 x 47.28, 11.41
    { 86, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xd66775} }, // 3 OSM: 71787 47.26, 11.39 x 47.27, 11.43
    { 82, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfbba00} }, // 1 OSM: 73662 WD: Q61888705 51.43, 11.94 x 51.51, 11.99
    { 8, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff9900} }, // 2 OSM: 73667 WD: Q61889098 51.43, 11.89 x 51.5, 11.99
    { 86, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0066cc} }, // 3 OSM: 73670 WD: Q61887067 51.43, 11.96 x 51.52, 11.99
    { 1, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x9b1006} }, // 4 OSM: 73671 WD: Q61889270 51.44, 11.93 x 51.51, 11.99
    { 4, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0f3f93} }, // 5 OSM: 73672 WD: Q61889316 51.29, 11.93 x 51.51, 12.07
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff6699} }, // 7 OSM: 73929 WD: Q61889355 51.48, 11.93 x 51.51, 12.04
    { 150, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x999933} }, // 9 OSM: 73932 WD: Q61889418 51.48, 11.89 x 51.48, 11.99
    { 92, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x336633} }, // 10 OSM: 73933 WD: Q61889438 51.48, 11.9 x 51.49, 11.99
    { 88, NoLogo, 14, LineMetaDataContent::RapidTransit, Color{0x800000} }, // S1 OSM: 77908 WD: Q7388209 49.44, 10.9 x 49.9, 11.56
    { 156, NoLogo, 14, LineMetaDataContent::RapidTransit, Color{0x65b949} }, // S2 OSM: 77962 WD: Q7388248 49.24, 11.04 x 49.45, 11.35
    { 131, NoLogo, 14, LineMetaDataContent::RapidTransit, Color{0xf05c3d} }, // S3 OSM: 77971 WD: Q7388284 49.27, 11.08 x 49.45, 11.46
    { 86, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xef1c29} }, // 3 OSM: 78206 50.84, 12.05 x 50.91, 12.1
    { 86, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x4098de} }, // 3 OSM: 79325 WD: Q60318542 51.72, 14.3 x 51.76, 14.35
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xa81a30} }, // 6 OSM: 89518 WD: Q1664234 47.23, 11.4 x 47.26, 11.44
    { 220, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfcd946} }, // C OSM: 122886 48.43, 1.995 x 49.05, 2.427
    { 137, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfaa61a} }, // N27 OSM: 129569 48.08, 11.55 x 48.18, 11.58
    { 225, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe2001c} }, // A OSM: 146067 48.52, 7.693 x 48.6, 7.754
    { 131, 468, 468, LineMetaDataContent::RapidTransit, Color{0x874487} }, // S3 OSM: 152203 WD: Q680235 47.09, 11.39 x 47.28, 11.5
    { 82, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009640} }, // 1 OSM: 153893 53.04, 8.741 x 53.16, 8.965
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00ff00} }, // 6 OSM: 155951 49, 8.295 x 49.02, 8.44
    { 189, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x935f39} }, // U3 OSM: 162288 48.71, 9.112 x 48.73, 9.202
    { 229, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x127bca} }, // B OSM: 163585 48.55, 7.689 x 48.63, 7.769
    { 273, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xa85faa} }, // E OSM: 163591 48.53, 7.733 x 48.61, 7.786
    { 82, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xec008c} }, // 1 OSM: 163714 52.48, -2.125 x 52.58, -1.896
    { 82, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x003828} }, // 1 OSM: 170076 52.92, -1.263 x 53.04, -1.145
    { 275, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x42816b} }, // 181 (SN) OSM: 172834 51.28, -0.1727 x 51.49, -0.07193
    { 284, 487, 14, LineMetaDataContent::RapidTransit, Color{0x52b447} }, // S85 OSM: 175267 WD: Q4048677 52.4, 13.4 x 52.57, 13.59
    { 270, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0e4094} }, // 4;4E OSM: 207342 51.32, 12.35 x 51.38, 12.43
    { 288, 502, NoLogo, LineMetaDataContent::RapidTransit, Color{0xc90062} }, // U OSM: 215565 WD: Q93559 48.76, 1.943 x 48.89, 2.237
    { 293, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009f4d} }, // R OSM: 224816 WD: Q3239181 50.64, 3.071 x 50.69, 3.179
    { 295, 535, NoLogo, LineMetaDataContent::RapidTransit, Color{0xc7b300} }, // K OSM: 253357 WD: Q93382 48.88, 2.352 x 49.23, 2.888
    { 183, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xc3b47d} }, // U8 OSM: 253394 48.71, 9.112 x 48.76, 9.296
    { 297, 568, 14, LineMetaDataContent::RapidTransit, Color{0x9a3052} }, // S9 OSM: 304163 WD: Q4048680 52.39, 13.2 x 52.54, 13.57
    { 131, 582, 14, LineMetaDataContent::RapidTransit, Color{0x862996} }, // S3 OSM: 364187 WD: Q7388283 47.88, 11.17 x 48.22, 11.7
    { 300, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // SIR1 OSM: 365296 45.37, 11.87 x 45.44, 11.89
    { 308, 598, NoLogo, LineMetaDataContent::RapidTransit, Color{0xeaab00} }, // P OSM: 370597 WD: Q93874 48.51, 2.359 x 49.18, 3.417
    { 205, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xc7956c} }, // U1 OSM: 370946 48.73, 9.111 x 48.81, 9.277
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008030} }, // 7 OSM: 382533 WD: Q2590490 51.91, 4.471 x 51.93, 4.526
    { 11, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xdf60a4} }, // 8 OSM: 382535 WD: Q3277304 51.9, 4.432 x 51.95, 4.488
    { 240, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x52b947} }, // 25 OSM: 382566 WD: Q2321951 51.84, 4.46 x 51.96, 4.514
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xdaa520} }, // 6 OSM: 383846 50.89, 10.56 x 50.9, 10.58
    { 267, NoLogo, 631, LineMetaDataContent::Subway, Color{0xffff00} }, // M1 OSM: 386242 WD: Q3238662 45.03, 7.591 x 45.08, 7.68
    { 310, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // T1 OSM: 399912 45.69, 9.676 x 45.76, 9.798
    { 313, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xeda5b4} }, // U13 OSM: 407256 48.76, 9.134 x 48.81, 9.254
    { 317, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x006d78} }, // T2 OSM: 418631 47.22, 5.951 x 47.25, 6.03
    { 186, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0eb48d} }, // U7 OSM: 445602 48.71, 9.173 x 48.84, 9.296
    { 88, 661, 14, LineMetaDataContent::RapidTransit, Color{0xd474ae} }, // S1 OSM: 454054 WD: Q2579762 52.42, 13.18 x 52.75, 13.4
    { 26, 675, 14, LineMetaDataContent::RapidTransit, Color{0x20543f} }, // S7 OSM: 456933 WD: Q2588691 49.83, 8.488 x 50.11, 8.664
    { 310, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe40716} }, // T1 OSM: 535990 45.41, 4.364 x 45.48, 4.394
    { 8, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0068b3} }, // 2 OSM: 563459 48.32, 10.84 x 48.38, 10.91
    { 11, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xef7c00} }, // 8 OSM: 563484 48.33, 10.89 x 48.37, 10.9
    { 127, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x928d1d} }, // S60 OSM: 570588 48.69, 8.922 x 48.83, 9.195
    { 159, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x6699cc} }, // 215 OSM: 571534 46.95, 6.839 x 46.99, 6.928
    { 321, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009f4d} }, // T OSM: 593563 WD: Q3239234 50.64, 3.071 x 50.72, 3.159
    { 198, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x00baf2} }, // U5 OSM: 898046 48.7, 9.136 x 48.8, 9.187
    { 169, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xec008c} }, // U6 OSM: 898581 48.71, 9.064 x 48.81, 9.187
    { 131, 692, 706, LineMetaDataContent::RapidTransit, Color{0x942138} }, // S3 OSM: 919367 WD: Q600028 45.47, 9.031 x 45.63, 9.175
    { 192, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xf58220} }, // U2 OSM: 919383 48.77, 9.122 x 48.83, 9.238
    { 88, 728, 728, LineMetaDataContent::RapidTransit, Color{0xde3d30} }, // S1 OSM: 919412 WD: Q46365 45.31, 9.031 x 45.63, 9.498
    { 323, 742, 706, LineMetaDataContent::RapidTransit, Color{0x784f24} }, // S13 OSM: 919471 WD: Q1160881 45.19, 9.143 x 45.5, 9.245
    { 195, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x7a68ae} }, // U4 OSM: 932204 48.77, 9.158 x 48.79, 9.25
    { 180, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xffd503} }, // U9 OSM: 932277 48.75, 9.138 x 48.79, 9.254
    { 208, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x69be51} }, // U14 OSM: 932386 48.77, 9.168 x 48.84, 9.23
    { 327, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xcccccc} }, // U11 OSM: 932425 48.77, 9.168 x 48.8, 9.226
    { 231, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xcccccc} }, // U19 OSM: 932433 48.79, 9.213 x 48.83, 9.238
    { 172, 757, 706, LineMetaDataContent::RapidTransit, Color{0x59b530} }, // S4 OSM: 936755 WD: Q1160571 45.47, 9.134 x 45.67, 9.176
    { 156, 771, 706, LineMetaDataContent::RapidTransit, Color{0x009478} }, // S2 OSM: 936757 WD: Q1160540 45.43, 9.14 x 45.65, 9.239
    { 11, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x95c11f} }, // 8 OSM: 963052 53.05, 8.741 x 53.1, 8.841
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffcc00} }, // 6 OSM: 963103 53.05, 8.783 x 53.11, 8.859
    { 1, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe30613} }, // 4 OSM: 964983 53.03, 8.799 x 53.16, 8.945
    { 86, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009fe3} }, // 3 OSM: 966312 53.06, 8.752 x 53.12, 8.868
    { 331, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0075bf} }, // N10 OSM: 1070763 53.06, 8.752 x 53.12, 8.9
    { 335, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe30613} }, // N4 OSM: 1070810 53.03, 8.799 x 53.16, 8.945
    { 338, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009640} }, // N1 OSM: 1070812 53.04, 8.741 x 53.09, 8.965
    { 341, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe41f25} }, // N82 OSM: 1147592 48.24, 14.28 x 48.33, 14.36
    { 145, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe41f25} }, // 50 OSM: 1149422 48.31, 14.26 x 48.32, 14.29
    { 8, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe41f25} }, // 2 OSM: 1149423 48.24, 14.28 x 48.33, 14.36
    { 86, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe41f25} }, // 3 OSM: 1149424 48.23, 14.23 x 48.31, 14.29
    { 82, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe41f25} }, // 1 OSM: 1149425 48.25, 14.28 x 48.33, 14.32
    { 192, 785, 100, LineMetaDataContent::Subway, Color{0x00a54f} }, // U2 OSM: 1150977 WD: Q3040891 50.1, 8.64 x 50.22, 8.687
    { 222, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0065ff} }, // SFMA OSM: 1204872 WD: Q3832760 45.09, 7.47 x 45.27, 7.677
    { 6, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x93bbe9} }, // U12 OSM: 1214006 48.72, 9.118 x 48.87, 9.271
    { 345, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x95aa53} }, // 308 OSM: 1228606 51.4, 7.16 x 51.52, 7.284
    { 349, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xb14e7a} }, // 310 OSM: 1228607 51.44, 7.152 x 51.48, 7.337
    { 353, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x294488} }, // U35 OSM: 1228608 WD: Q2466100 51.45, 7.21 x 51.55, 7.273
    { 13, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x72a7a0} }, // 318 OSM: 1228609 51.42, 7.143 x 51.52, 7.284
    { 357, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xea504c} }, // 306 OSM: 1228610 51.48, 7.16 x 51.53, 7.223
    { 361, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x6ba5d9} }, // 302 OSM: 1228611 51.46, 7.056 x 51.58, 7.324
    { 365, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00b2f6} }, // 301 OSM: 1236118 51.5, 7.019 x 51.58, 7.11
    { 369, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf47a14} }, // S 5 OSM: 1241173 49.14, 8.674 x 49.42, 9.102
    { 11, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xcc9900} }, // 8 OSM: 1374424 WD: Q61887882 51.45, 11.95 x 51.52, 11.99
    { 7, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x99cc00} }, // 12 OSM: 1375884 WD: Q61888162 51.48, 11.96 x 51.52, 11.99
    { 86, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe5005a} }, // 3 OSM: 1469415 51.02, 13.7 x 51.1, 13.75
    { 373, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe6f2fc} }, // 98 OSM: 1490387 52.36, 13.03 x 52.4, 13.1
    { 376, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 91 OSM: 1492311 52.36, 13.01 x 52.4, 13.1
    { 379, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x19488e} }, // 92 OSM: 1505928 52.36, 13.03 x 52.42, 13.14
    { 382, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfe9800} }, // 93 OSM: 1509473 52.36, 13.06 x 52.41, 13.1
    { 385, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfe9800} }, // 94 OSM: 1512265 52.37, 13.01 x 52.4, 13.11
    { 388, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x803c9f} }, // S33 OSM: 1513484 49.12, 8.364 x 49.24, 8.594
    { 392, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xed1c24} }, // N19 OSM: 1536166 48.12, 11.46 x 48.15, 11.64
    { 131, NoLogo, 14, LineMetaDataContent::RapidTransit, Color{0x0097d8} }, // S3 OSM: 1549250 WD: Q7388286 47.32, 8.501 x 47.53, 8.806
    { 396, NoLogo, 14, LineMetaDataContent::RapidTransit, Color{0xf6c454} }, // S10 OSM: 1561016 WD: Q687279 47.35, 8.465 x 47.38, 8.54
    { 172, NoLogo, 14, LineMetaDataContent::RapidTransit, Color{0xe67d63} }, // S4 OSM: 1567629 WD: Q685807 47.27, 8.517 x 47.38, 8.558
    { 152, NoLogo, 14, LineMetaDataContent::RapidTransit, Color{0x946644} }, // S24 OSM: 1574036 WD: Q7388228 47.17, 8.516 x 47.75, 9.106
    { 400, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfe9800} }, // 96 OSM: 1585204 52.36, 13.05 x 52.43, 13.14
    { 403, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x59c133} }, // 99 OSM: 1585259 52.39, 13.06 x 52.4, 13.11
    { 163, NoLogo, 14, LineMetaDataContent::RapidTransit, Color{0x7751a1} }, // S6 OSM: 1609735 WD: Q7388350 47.26, 8.305 x 47.48, 8.683
    { 406, NoLogo, 14, LineMetaDataContent::RapidTransit, Color{0xd8242b} }, // S12 OSM: 1614502 WD: Q7388182 47.37, 8.208 x 47.7, 9.042
    { 17, NoLogo, 14, LineMetaDataContent::RapidTransit, Color{0x64b97a} }, // S16 OSM: 1618466 WD: Q7388193 47.28, 8.511 x 47.45, 8.615
    { 388, NoLogo, 14, LineMetaDataContent::RapidTransit, Color{0x2da7df} }, // S33 OSM: 1619213 WD: Q7388269 47.5, 8.611 x 47.7, 8.726
    { 297, NoLogo, 14, LineMetaDataContent::RapidTransit, Color{0x00a34f} }, // S9 OSM: 1620987 WD: Q7388394 47.35, 8.501 x 47.7, 8.721
    { 8, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc32b3c} }, // 2 OSM: 1624727 WD: Q60282113 51.75, 14.31 x 51.76, 14.35
    { 1, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x239537} }, // 4 OSM: 1628047 WD: Q60328960 51.72, 14.32 x 51.79, 14.35
    { 317, 802, 829, LineMetaDataContent::Tramway, Color{0xbb4a9b} }, // T2 OSM: 1635139 WD: Q369969 48.82, 2.217 x 48.92, 2.288
    { 82, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xece116} }, // 1 OSM: 1637446 WD: Q60213236 51.75, 14.33 x 51.78, 14.34
    { 14, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x54ad4b} }, // 18 OSM: 1646141 50.73, 6.893 x 50.98, 7.097
    { 410, 853, 874, LineMetaDataContent::RapidTransit, Color{0x5e9620} }, // D OSM: 1673421 WD: Q1425351 48.29, 2.344 x 49.27, 2.657
    { 192, 882, 100, LineMetaDataContent::Subway, Color{0xff0000} }, // U2 OSM: 1676043 WD: Q3433227 49.42, 11.03 x 49.49, 11.11
    { 82, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xdc008f} }, // 1 OSM: 1679960 50.09, 14.34 x 50.11, 14.5
    { 192, 899, 100, LineMetaDataContent::Subway, Color{0xee1d23} }, // U2 OSM: 1686090 WD: Q275451 53.53, 9.943 x 53.64, 10.15
    { 205, 914, 100, LineMetaDataContent::Subway, Color{0x0066b3} }, // U1 OSM: 1687370 WD: Q248623 53.55, 9.985 x 53.71, 10.29
    { 412, NoLogo, 468, LineMetaDataContent::RapidTransit, Color{} }, // R143 OSM: 1756181 WD: Q1827165 48.27, 13.72 x 48.34, 14.02
    { 317, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x96bf0d} }, // T2 OSM: 1824544 47.29, 5.006 x 47.37, 5.059
    { 310, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xcc0088} }, // T1 OSM: 1824550 47.31, 5.028 x 47.33, 5.112
    { 189, 929, 100, LineMetaDataContent::Subway, Color{0x00868b} }, // U3 OSM: 1857497 WD: Q3433219 49.44, 11.04 x 49.47, 11.09
    { 205, 946, 100, LineMetaDataContent::Subway, Color{0x000066} }, // U1 OSM: 1857639 WD: Q3433210 49.4, 10.96 x 49.48, 11.14
    { 163, 963, 14, LineMetaDataContent::RapidTransit, Color{0xf57921} }, // S6 OSM: 1880910 WD: Q3238987 50.1, 8.633 x 50.34, 8.789
    { 142, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8d1d2c} }, // 17 OSM: 1903836 47.35, 8.482 x 47.4, 8.542
    { 1, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x9bd6f9} }, // 4 OSM: 1904829 50.03, 14.37 x 50.08, 14.46
    { 8, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x003828} }, // 2 OSM: 1984359 52.9, -1.207 x 52.99, -1.145
    { 417, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x33ff33} }, // M2 OSM: 2001598 52.52, 13.41 x 52.57, 13.44
    { 420, 58, 58, LineMetaDataContent::Subway, Color{0x302276} }, // U75 OSM: 2003447 WD: Q661002 51.2, 6.684 x 51.23, 6.847
    { 424, 58, 58, LineMetaDataContent::Subway, Color{0x302276} }, // U78 OSM: 2003448 WD: Q661002 51.22, 6.733 x 51.27, 6.795
    { 85, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x967b68} }, // 13 OSM: 2003476 50.91, 6.908 x 50.97, 7.038
    { 4, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x948fb8} }, // 5 OSM: 2003477 50.93, 6.888 x 50.98, 6.96
    { 4, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfff500} }, // 5 OSM: 2024979 50.03, 14.37 x 50.09, 14.53
    { 86, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe693b5} }, // 3 OSM: 2026288 50.93, 6.87 x 50.98, 7.086
    { 102, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x98c000} }, // 61 OSM: 2026289 50.7, 7.071 x 50.76, 7.112
    { 109, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x61af20} }, // 62 OSM: 2026290 50.7, 7.095 x 50.74, 7.176
    { 99, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x60d6f7} }, // 63 OSM: 2026291 50.68, 7.047 x 50.75, 7.159
    { 134, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xee99bf} }, // 67 OSM: 2026293 50.68, 7.092 x 50.79, 7.203
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf7d09b} }, // 6 OSM: 2032473 50.07, 14.42 x 50.11, 14.48
    { 428, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xb1c800} }, // F OSM: 2060446 48.57, 7.724 x 48.59, 7.777
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00ffff} }, // 7 OSM: 2061854 50.06, 14.39 x 50.08, 14.51
    { 82, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009cdd} }, // 1 OSM: 2067963 53.41, 14.49 x 53.47, 14.56
    { 86, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009cdd} }, // 3 OSM: 2073969 53.4, 14.52 x 53.46, 14.55
    { 7, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009cdd} }, // 12 OSM: 2074000 53.4, 14.53 x 53.45, 14.55
    { 310, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe3002b} }, // T1 OSM: 2074462 48.65, 6.145 x 48.7, 6.225
    { 4, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009cdd} }, // 5 OSM: 2077222 53.43, 14.49 x 53.45, 14.58
    { 81, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009cdd} }, // 11 OSM: 2077355 53.4, 14.53 x 53.45, 14.58
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009cdd} }, // 6 OSM: 2077516 53.4, 14.53 x 53.48, 14.61
    { 11, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009cdd} }, // 8 OSM: 2080359 53.38, 14.49 x 53.43, 14.64
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009cdd} }, // 7 OSM: 2080360 53.38, 14.49 x 53.45, 14.64
    { 86, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xef7c00} }, // 3 OSM: 2083643 48.31, 10.84 x 48.37, 10.9
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x94c11c} }, // 6 OSM: 2083654 48.35, 10.89 x 48.37, 10.96
    { 251, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00bfe8} }, // N20 OSM: 2101204 48.14, 11.51 x 48.18, 11.56
    { 430, 980, 14, LineMetaDataContent::RapidTransit, Color{0xe7526b} }, // S20 OSM: 2113865 WD: Q7388223 48.04, 11.46 x 48.15, 11.54
    { 26, 997, 14, LineMetaDataContent::RapidTransit, Color{0x983224} }, // S7 OSM: 2113867 WD: Q7388364 47.91, 11.42 x 48.14, 11.78
    { 82, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00a651} }, // 1 OSM: 2116454 47.2, -1.639 x 47.26, -1.515
    { 8, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xee1c25} }, // 2 OSM: 2166523 47.19, -1.593 x 47.26, -1.542
    { 86, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x006db1} }, // 3 OSM: 2166524 47.18, -1.617 x 47.25, -1.542
    { 172, NoLogo, 14, LineMetaDataContent::RapidTransit, Color{0x000080} }, // S4 OSM: 2199152 WD: Q7388307 49.25, 10.3 x 49.44, 11.08
    { 8, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x006699} }, // 2 OSM: 2203208 48.98, 8.347 x 49.03, 8.479
    { 11, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0098d4} }, // 8 OSM: 2262665 50.8, 4.353 x 50.85, 4.44
    { 434, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x669933} }, // 87 OSM: 2282096 WD: Q428288 52.44, 13.69 x 52.46, 13.76
    { 225, 1013, 874, LineMetaDataContent::RapidTransit, Color{0xd1302f} }, // A OSM: 2333448 WD: Q741818 48.75, 2.009 x 49.05, 2.783
    { 1, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xd75128} }, // 4 OSM: 2368452 50.72, 12.43 x 50.75, 12.49
    { 92, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009cdd} }, // 10 OSM: 2372195 53.42, 14.49 x 53.46, 14.55
    { 437, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf8a20d} }, // S51 OSM: 2412316 49.3, 8.674 x 49.42, 8.991
    { 441, 1034, 14, LineMetaDataContent::RapidTransit, Color{0xba8a4d} }, // S47 OSM: 2413847 WD: Q3742025 52.45, 13.43 x 52.47, 13.56
    { 255, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x61af20} }, // S23;RB23 OSM: 2441590 WD: Q1699351 50.56, 6.761 x 50.74, 7.098
    { 88, NoLogo, 14, LineMetaDataContent::RapidTransit, Color{0x0b9a33} }, // S1 OSM: 2444997 WD: Q7388210 51.16, 6.772 x 51.52, 7.46
    { 80, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xef7c00} }, // S11 OSM: 2445000 WD: Q7388174 50.94, 6.674 x 51.28, 7.125
    { 406, NoLogo, 14, LineMetaDataContent::RapidTransit, Color{0x61af20} }, // S12 OSM: 2445001 WD: Q7388180 50.76, 6.713 x 50.95, 7.66
    { 323, NoLogo, 14, LineMetaDataContent::RapidTransit, Color{0x00a6eb} }, // S13 OSM: 2445007 WD: Q7388184 50.81, 6.482 x 50.95, 7.151
    { 156, NoLogo, 14, LineMetaDataContent::RapidTransit, Color{0x006db6} }, // S2 OSM: 2445008 WD: Q7388251 51.45, 7.015 x 51.62, 7.46
    { 445, NoLogo, 14, LineMetaDataContent::RapidTransit, Color{0x717676} }, // S28 OSM: 2445009 WD: Q7388234 51.2, 6.594 x 51.25, 6.988
    { 131, NoLogo, 14, LineMetaDataContent::RapidTransit, Color{0x999999} }, // S3 OSM: 2445010 WD: Q7388285 51.4, 6.835 x 51.48, 7.181
    { 172, NoLogo, 14, LineMetaDataContent::RapidTransit, Color{0xef7c00} }, // S4 OSM: 2445011 WD: Q7388319 51.5, 7.334 x 51.55, 7.698
    { 33, NoLogo, 14, LineMetaDataContent::RapidTransit, Color{0x98c60f} }, // S5 OSM: 2445012 WD: Q7388333 51.36, 7.325 x 51.52, 7.46
    { 163, NoLogo, 14, LineMetaDataContent::RapidTransit, Color{0xdc052d} }, // S6 OSM: 2445013 WD: Q7388349 50.94, 6.79 x 51.45, 7.023
    { 105, NoLogo, 14, LineMetaDataContent::RapidTransit, Color{0x14bae6} }, // S68 OSM: 2445014 WD: Q7388346 51.1, 6.79 x 51.23, 7.074
    { 36, NoLogo, 14, LineMetaDataContent::RapidTransit, Color{0xb03303} }, // S8 OSM: 2445015 WD: Q7388383 51.19, 6.445 x 51.36, 7.46
    { 297, NoLogo, 14, LineMetaDataContent::RapidTransit, Color{0xc7007f} }, // S9 OSM: 2445016 WD: Q7388395 51.23, 6.921 x 51.74, 7.186
    { 88, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xec192e} }, // S1 OSM: 2445551 49.33, 7.334 x 49.48, 9.424
    { 156, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x2960b5} }, // S2 OSM: 2445552 49.34, 7.767 x 49.48, 9.144
    { 131, 1049, 14, LineMetaDataContent::RapidTransit, Color{0x00a896} }, // S3 OSM: 2445553 WD: Q2781002 49.87, 8.504 x 50.16, 8.699
    { 131, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfcd804} }, // S3 OSM: 2445554 48.99, 8.349 x 49.48, 8.685
    { 172, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x1a9d47} }, // S4 OSM: 2445555 48.99, 8.349 x 49.48, 9.528
    { 131, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xdb6eab} }, // S3 OSM: 2474189 52.16, 9.739 x 52.38, 10.02
    { 33, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf78a18} }, // S5 OSM: 2474199 51.71, 8.737 x 52.46, 9.773
    { 33, 1066, 14, LineMetaDataContent::RapidTransit, Color{0xa52a2a} }, // S5 OSM: 2515355 WD: Q2515085 50.1, 8.583 x 50.25, 8.699
    { 172, 1083, 14, LineMetaDataContent::RapidTransit, Color{0xfecb09} }, // S4 OSM: 2515408 WD: Q2204443 49.99, 8.516 x 50.18, 8.699
    { 26, NoLogo, 14, LineMetaDataContent::RapidTransit, Color{0x14bae6} }, // S7 OSM: 2544304 WD: Q1195962 51.16, 7.004 x 51.28, 7.253
    { 449, 1100, 1121, LineMetaDataContent::Subway, Color{0x79bb92} }, // 7bis OSM: 2554103 WD: Q50749 48.88, 2.366 x 48.88, 2.401
    { 163, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x005aab} }, // S6 OSM: 2557420 52.37, 9.739 x 52.62, 10.06
    { 172, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x972f50} }, // S4 OSM: 2567719 52.16, 9.687 x 52.58, 9.956
    { 310, 802, 829, LineMetaDataContent::Tramway, Color{0x216eb4} }, // T1 OSM: 2572573 WD: Q369969 48.9, 2.274 x 48.94, 2.47
    { 163, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xec192e} }, // S6 OSM: 2587144 49.44, 8.256 x 50, 8.582
    { 369, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf17f1a} }, // S 5 OSM: 2606971 50.7, 11.99 x 51.48, 12.48
    { 455, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00a650} }, // S 4 OSM: 2607472 51.25, 12.37 x 51.59, 14.23
    { 88, NoLogo, 14, LineMetaDataContent::RapidTransit, Color{0x66cdaa} }, // S1 OSM: 2609006 WD: Q50331474 54.08, 12.06 x 54.17, 12.13
    { 131, NoLogo, 14, LineMetaDataContent::RapidTransit, Color{} }, // S3 OSM: 2609009 WD: Q50331483 53.79, 12.13 x 54.08, 12.35
    { 156, NoLogo, 14, LineMetaDataContent::RapidTransit, Color{0x9400d3} }, // S2 OSM: 2609011 WD: Q50331479 53.8, 12.06 x 54.17, 12.17
    { 96, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe2000a} }, // 21 OSM: 2617691 49.4, 8.675 x 49.43, 8.693
    { 459, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfcc200} }, // 22 OSM: 2617692 49.4, 8.627 x 49.41, 8.693
    { 261, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe48e00} }, // 23 OSM: 2617693 49.34, 8.681 x 49.44, 8.693
    { 153, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8b1c75} }, // 24 OSM: 2617694 49.36, 8.66 x 49.47, 8.691
    { 463, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf39a9a} }, // 26 OSM: 2617695 49.38, 8.658 x 49.41, 8.693
    { 150, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x93c13b} }, // 9 OSM: 2621592 49.48, 8.467 x 49.48, 8.525
    { 466, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x004595} }, // M OSM: 2629655 49.39, 1.042 x 49.45, 1.106
    { 150, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf171ab} }, // 9 OSM: 2629996 46.93, 7.436 x 46.97, 7.468
    { 469, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00bfe8} }, // 29 OSM: 2635531 48.14, 11.49 x 48.16, 11.56
    { 472, 1133, NoLogo, LineMetaDataContent::Tramway, Color{0x873f98} }, // T5 OSM: 2643507 WD: Q3238967 45.73, 4.88 x 45.74, 4.948
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x9e0234} }, // 7 OSM: 2675693 51.04, 13.63 x 51.14, 13.8
    { 156, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x118349} }, // S2 OSM: 2682237 52.28, 9.217 x 52.65, 9.773
    { 7, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x006b42} }, // 12 OSM: 2690192 51.04, 13.67 x 51.06, 13.81
    { 92, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xdc008f} }, // 10 OSM: 2728288 50.06, 14.3 x 50.13, 14.48
    { 7, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xdc008f} }, // 12 OSM: 2729904 50.03, 14.37 x 50.11, 14.45
    { 3, 1153, 631, LineMetaDataContent::Subway, Color{0x7956a3} }, // M5 OSM: 2753306 WD: Q3238963 45.48, 9.117 x 45.53, 9.212
    { 82, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe3000b} }, // 1 OSM: 2777016 52.2, 10.51 x 52.33, 10.54
    { 475, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x015ca3} }, // S 7 OSM: 2791180 51.45, 11.91 x 51.49, 12
    { 480, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xd7171f} }, // S 3 OSM: 2793231 51.31, 11.96 x 51.52, 13.11
    { 484, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x030f3f} }, // Metropolitana OSM: 2797904 WD: Q1725884 45.51, 10.21 x 45.58, 10.28
    { 92, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1f75} }, // 10 OSM: 2799185 47.35, 8.507 x 47.45, 8.573
    { 7, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x92d6e3} }, // 12 OSM: 2799201 47.4, 8.556 x 47.45, 8.608
    { 498, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x93ad00} }, // M3 OSM: 2804168 WD: Q2637212 50.41, 4.43 x 50.48, 4.452
    { 4, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x70492c} }, // 5 OSM: 2807017 47.36, 8.516 x 47.38, 8.572
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xbe8543} }, // 6 OSM: 2807025 47.36, 8.482 x 47.4, 8.572
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 7 OSM: 2807030 47.34, 8.53 x 47.41, 8.597
    { 150, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x322e71} }, // 9 OSM: 2807033 47.37, 8.495 x 47.41, 8.592
    { 209, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0093d0} }, // 14 OSM: 2807051 47.37, 8.495 x 47.42, 8.55
    { 81, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00923c} }, // 11 OSM: 2807068 47.35, 8.533 x 47.42, 8.583
    { 86, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00923c} }, // 3 OSM: 2807070 47.36, 8.485 x 47.38, 8.567
    { 1, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x322e71} }, // 4 OSM: 2807089 47.35, 8.49 x 47.39, 8.561
    { 8, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xcb0a25} }, // 2 OSM: 2807095 47.35, 8.444 x 47.4, 8.561
    { 160, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xcb0a25} }, // 15 OSM: 2807117 47.37, 8.533 x 47.4, 8.548
    { 11, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8bc036} }, // 8 OSM: 2807118 47.36, 8.504 x 47.39, 8.567
    { 4, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf39100} }, // 5 OSM: 2810470 52.23, 10.48 x 52.26, 10.54
    { 18, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xa9c1d1} }, // 16 OSM: 2820891 50.06, 14.3 x 50.11, 14.55
    { 86, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x006531} }, // 3 OSM: 2837394 52.24, 10.47 x 52.29, 10.58
    { 501, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00907a} }, // S31 OSM: 2872363 48.44, 8.215 x 49.18, 8.785
    { 505, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00907a} }, // S32 OSM: 2872364 48.99, 8.402 x 49.16, 8.775
    { 437, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf49694} }, // S51 OSM: 2872365 48.89, 8.262 x 49.23, 8.703
    { 509, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf49694} }, // S52 OSM: 2872366 48.98, 8.262 x 49.23, 8.433
    { 195, 1173, 100, LineMetaDataContent::Subway, Color{0x2ec6ff} }, // U4 OSM: 2872790 WD: Q209739 53.53, 9.983 x 53.56, 10.11
    { 176, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffff00} }, // S 1 OSM: 2920398 51.31, 12.27 x 51.37, 12.41
    { 1, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf9b000} }, // 4 OSM: 2951397 52.37, 9.596 x 52.42, 9.819
    { 385, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x6f1b14} }, // 94 OSM: 2982672 51.48, 11.93 x 51.51, 11.97
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf9b000} }, // 6 OSM: 2991603 52.32, 9.69 x 52.42, 9.837
    { 81, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf9b000} }, // 11 OSM: 2991649 52.36, 9.713 x 52.39, 9.775
    { 4, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf9b000} }, // 5 OSM: 2991701 52.36, 9.659 x 52.41, 9.859
    { 82, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe4003a} }, // 1 OSM: 2995652 52.24, 9.731 x 52.44, 9.86
    { 8, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe4003a} }, // 2 OSM: 2998555 52.29, 9.734 x 52.42, 9.818
    { 11, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe4003a} }, // 8 OSM: 2998722 52.33, 9.734 x 52.39, 9.805
    { 142, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x76b82a} }, // 17 OSM: 2998733 52.34, 9.718 x 52.38, 9.743
    { 92, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x76b82a} }, // 10 OSM: 3004809 52.37, 9.664 x 52.38, 9.744
    { 513, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x051541} }, // 95 OSM: 3006197 51.42, 11.96 x 51.52, 11.99
    { 7, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xed1943} }, // 12 OSM: 3009639 WD: Q2189640 51.88, 4.471 x 51.92, 4.568
    { 86, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0069b4} }, // 3 OSM: 3016071 52.33, 9.69 x 52.44, 9.848
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0069b4} }, // 7 OSM: 3038575 52.33, 9.69 x 52.41, 9.854
    { 150, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0069b4} }, // 9 OSM: 3038600 52.34, 9.667 x 52.43, 9.802
    { 1, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 4 OSM: 3061160 50.49, 12.13 x 50.51, 12.18
    { 517, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00ffff} }, // S 2 OSM: 3119892 51.31, 12.23 x 51.87, 12.66
    { 11, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xafe0ee} }, // 8 OSM: 3144745 46.94, 7.374 x 46.95, 7.487
    { 8, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x088742} }, // 2 OSM: 3152801 51.13, 14.94 x 51.17, 14.99
    { 82, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff2e17} }, // 1 OSM: 3152809 51.12, 14.97 x 51.17, 14.99
    { 26, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa5ce43} }, // S7 OSM: 3168072 52.37, 9.739 x 52.62, 10.06
    { 225, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xca305b} }, // A OSM: 3190626 47.34, 0.6578 x 47.42, 0.7119
    { 417, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x489224} }, // M2 OSM: 3287304 WD: Q2094433 50.4, 4.271 x 50.42, 4.452
    { 225, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xef3f30} }, // A OSM: 3309751 47.44, -0.5972 x 47.51, -0.549
    { 1, 1188, 1121, LineMetaDataContent::Subway, Color{0xbb4d98} }, // 4 OSM: 3326845 WD: Q50743 48.82, 2.318 x 48.9, 2.359
    { 209, 1206, 1121, LineMetaDataContent::Subway, Color{0x67328e} }, // 14 OSM: 3328694 WD: Q50761 48.83, 2.323 x 48.88, 2.387
    { 82, 1225, 1121, LineMetaDataContent::Subway, Color{0xf2c931} }, // 1 OSM: 3328695 WD: Q13224 48.84, 2.23 x 48.89, 2.441
    { 150, 1243, 1121, LineMetaDataContent::Subway, Color{0xcdc83f} }, // 9 OSM: 3328717 WD: Q50753 48.83, 2.231 x 48.87, 2.442
    { 195, 1261, 100, LineMetaDataContent::Subway, Color{0x10b48d} }, // U4 OSM: 3328726 WD: Q20439761 48.13, 11.52 x 48.15, 11.62
    { 92, 1277, 1121, LineMetaDataContent::Subway, Color{0xdfb039} }, // 10 OSM: 3328741 WD: Q50754 48.84, 2.229 x 48.85, 2.365
    { 19, 1296, 1121, LineMetaDataContent::Subway, Color{0x75c695} }, // 6 OSM: 3328765 WD: Q50746 48.83, 2.285 x 48.87, 2.402
    { 27, 1314, 1121, LineMetaDataContent::Subway, Color{0xfa9aba} }, // 7 OSM: 3328805 WD: Q50748 48.79, 2.332 x 48.92, 2.411
    { 93, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xbb0022} }, // 0 OSM: 3348003 WD: Q1510414 51.08, 2.581 x 51.34, 3.285
    { 82, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe3000f} }, // 1 OSM: 3367545 48.34, 10.87 x 48.38, 10.94
    { 1, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x951881} }, // 4 OSM: 3367554 48.37, 10.88 x 48.4, 10.89
    { 521, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0097ba} }, // S42 OSM: 3368507 49.14, 8.875 x 49.25, 9.229
    { 516, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff9e00} }, // RS 2 OSM: 3372285 52.79, 8.597 x 53.57, 8.895
    { 175, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ee} }, // RS 1 OSM: 3372313 52.92, 8.516 x 53.21, 9.238
    { 525, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe3ba12} }, // 44 OSM: 3394367 50.82, 4.409 x 50.84, 4.514
    { 528, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xde3b21} }, // 39 OSM: 3394368 50.83, 4.409 x 50.85, 4.503
    { 88, 1332, 14, LineMetaDataContent::RapidTransit, Color{0x0095da} }, // S1 OSM: 3413905 WD: Q600891 49.97, 8.244 x 50.11, 8.885
    { 156, 1349, 14, LineMetaDataContent::RapidTransit, Color{0xee1c23} }, // S2 OSM: 3414422 WD: Q1985592 50.01, 8.31 x 50.16, 8.813
    { 36, 1366, 14, LineMetaDataContent::RapidTransit, Color{0xd7df23} }, // S8 OSM: 3415070 WD: Q2005458 49.98, 8.242 x 50.13, 8.931
    { 297, 1383, 14, LineMetaDataContent::RapidTransit, Color{0x91268f} }, // S9 OSM: 3415113 WD: Q508402 49.98, 8.244 x 50.13, 8.931
    { 7, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xbb0022} }, // 12 OSM: 3419132 WD: Q2200976 51.22, 4.42 x 51.23, 4.444
    { 150, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xee8822} }, // 9 OSM: 3419133 51.2, 4.361 x 51.22, 4.464
    { 153, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff88aa} }, // 24 OSM: 3419134 51.2, 4.408 x 51.24, 4.484
    { 86, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffcc11} }, // 3 OSM: 3419435 51.22, 4.305 x 51.26, 4.464
    { 1, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x1199dd} }, // 4 OSM: 3419473 51.17, 4.35 x 51.22, 4.484
    { 4, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x771133} }, // 5 OSM: 3419525 51.22, 4.361 x 51.23, 4.512
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xdd0077} }, // 6 OSM: 3419912 51.18, 4.391 x 51.26, 4.443
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0044bb} }, // 7 OSM: 3420306 51.17, 4.4 x 51.23, 4.449
    { 92, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xbbdd00} }, // 10 OSM: 3420544 51.17, 4.362 x 51.23, 4.512
    { 160, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffffff} }, // 15 OSM: 3420997 51.17, 4.361 x 51.22, 4.494
    { 82, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf5d200} }, // 1 OSM: 3430333 49.72, 13.37 x 49.78, 13.4
    { 8, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf5d200} }, // 2 OSM: 3430559 49.73, 13.32 x 49.75, 13.41
    { 1, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf5d200} }, // 4 OSM: 3430578 49.73, 13.36 x 49.78, 13.38
    { 232, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xde3b21} }, // 19 OSM: 3437796 50.86, 4.273 x 50.9, 4.357
    { 198, 1400, 100, LineMetaDataContent::Subway, Color{0xb77510} }, // U5 OSM: 3475206 WD: Q3832790 48.09, 11.5 x 48.14, 11.65
    { 169, 1416, 100, LineMetaDataContent::Subway, Color{0x0071bb} }, // U6 OSM: 3477966 WD: Q751039 48.11, 11.47 x 48.27, 11.67
    { 189, 1432, 100, LineMetaDataContent::Subway, Color{0xf36f33} }, // U3 OSM: 3484056 WD: Q20439760 48.09, 11.48 x 48.19, 11.59
    { 169, 1448, 100, LineMetaDataContent::Subway, Color{0x007ec6} }, // U6 OSM: 3524791 WD: Q19863008 50.11, 8.624 x 50.14, 8.708
    { 205, 1465, 100, LineMetaDataContent::Subway, Color{0x448137} }, // U1 OSM: 3531712 WD: Q20439756 48.1, 11.53 x 48.18, 11.58
    { 192, 1481, 100, LineMetaDataContent::Subway, Color{0xc40f39} }, // U2 OSM: 3531713 WD: Q830301 48.11, 11.54 x 48.21, 11.7
    { 186, 1497, 100, LineMetaDataContent::Subway, Color{0x468037} }, // U7 OSM: 3531714 WD: Q20439774 48.1, 11.53 x 48.18, 11.65
    { 183, 1513, 100, LineMetaDataContent::Subway, Color{0xff6a2f} }, // U8 OSM: 3531715 WD: Q20439777 48.1, 11.56 x 48.18, 11.65
    { 225, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // A OSM: 3555528 49.49, 0.09563 x 49.53, 0.137
    { 229, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // B OSM: 3555531 49.49, 0.09563 x 49.52, 0.1801
    { 317, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffdd00} }, // T2 OSM: 3589646 45.44, 4.384 x 45.45, 4.403
    { 531, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xafcb07} }, // T3 OSM: 3589647 45.42, 4.378 x 45.47, 4.405
    { 88, 468, 468, LineMetaDataContent::RapidTransit, Color{0xd7df23} }, // S1 OSM: 3654415 WD: Q680235 47.25, 11.08 x 47.59, 12.17
    { 172, 468, 468, LineMetaDataContent::RapidTransit, Color{0xbec2d0} }, // S4 OSM: 3654766 WD: Q680235 47, 11.23 x 47.27, 11.51
    { 163, 468, 468, LineMetaDataContent::RapidTransit, Color{0x257ca7} }, // S6 OSM: 3655247 WD: Q680235 47.42, 12.06 x 47.52, 12.63
    { 172, 1529, 1529, LineMetaDataContent::RapidTransit, Color{} }, // S4 OSM: 3660338 WD: Q2204422 47.08, 9.816 x 47.15, 9.918
    { 534, 1549, 829, LineMetaDataContent::Tramway, Color{0x009641} }, // T3b OSM: 3662457 WD: Q3136247 48.85, 2.301 x 48.9, 2.411
    { 310, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x873f98} }, // T1 OSM: 3667340 WD: Q2903 45.73, 4.817 x 45.79, 4.884
    { 317, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x873f98} }, // T2 OSM: 3667554 WD: Q2906 45.69, 4.827 x 45.75, 4.956
    { 531, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x873f98} }, // T3 OSM: 3667555 WD: Q2911 45.75, 4.862 x 45.78, 5.035
    { 538, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x873f98} }, // T4 OSM: 3667556 WD: Q2918 45.69, 4.858 x 45.78, 4.888
    { 131, 1529, 1529, LineMetaDataContent::RapidTransit, Color{} }, // S3 OSM: 3671005 WD: Q2204422 47.45, 9.637 x 47.5, 9.744
    { 229, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x007dc5} }, // B OSM: 3687323 WD: Q2965 45.72, 4.81 x 45.77, 4.864
    { 410, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x00ac4d} }, // D OSM: 3687324 WD: Q2976 45.7, 4.803 x 45.78, 4.89
    { 220, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xf99d1d} }, // C OSM: 3687325 WD: Q2969 45.77, 4.827 x 45.79, 4.836
    { 225, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xee3898} }, // A OSM: 3687326 WD: Q2944 45.75, 4.825 x 45.77, 4.922
    { 1, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009cdd} }, // 4 OSM: 3733545 53.4, 14.49 x 53.45, 14.54
    { 109, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff9ec2} }, // 62 OSM: 3775501 50.86, 4.332 x 50.88, 4.435
    { 446, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfaa61a} }, // 28 OSM: 3858971 48.13, 11.56 x 48.17, 11.58
    { 496, NoLogo, 1577, LineMetaDataContent::Subway, Color{0xed1c24} }, // a OSM: 3889841 WD: Q24641190 48.09, -1.711 x 48.12, -1.644
    { 220, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe4007c} }, // C OSM: 3921484 45.17, 5.69 x 45.19, 5.776
    { 273, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x58318a} }, // E OSM: 3921488 WD: Q3239103 45.17, 5.661 x 45.26, 5.72
    { 229, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009b3a} }, // B OSM: 3921491 45.18, 5.698 x 45.21, 5.787
    { 225, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0076bd} }, // A OSM: 3921492 45.14, 5.671 x 45.2, 5.734
    { 410, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf39a00} }, // D OSM: 3921494 45.17, 5.754 x 45.19, 5.759
    { 267, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe5442e} }, // M1 OSM: 3939086 WD: Q2740923 50.4, 4.271 x 50.42, 4.452
    { 227, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xef87b6} }, // HBB OSM: 3988307 47.27, 11.4 x 47.29, 11.4
    { 541, 1599, 829, LineMetaDataContent::Tramway, Color{0xb1a245} }, // T8 OSM: 4007734 WD: Q3239029 48.93, 2.294 x 48.96, 2.358
    { 261, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xed1943} }, // 23 OSM: 4016993 WD: Q2914455 51.88, 4.432 x 51.92, 4.574
    { 86, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x99b3be} }, // 3 OSM: 4089342 46.94, 7.431 x 46.95, 7.441
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0089cf} }, // 6 OSM: 4089819 46.93, 7.419 x 46.95, 7.563
    { 544, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x991f36} }, // 97 OSM: 4092822 50.8, 4.313 x 50.84, 4.357
    { 81, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xee1d23} }, // 11 OSM: 4108299 47.47, 7.573 x 47.58, 7.612
    { 0, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x84c8eb} }, // M4 OSM: 4139149 WD: Q1841724 50.41, 4.435 x 50.43, 4.503
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xee1d23} }, // 7 OSM: 4152763 46.94, 7.38 x 46.95, 7.472
    { 82, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff7f00} }, // 1 OSM: 4234654 51.8, 12.24 x 51.84, 12.24
    { 21, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x8b231d} }, // SFM6 OSM: 4282833 WD: Q15077697 45, 7.655 x 45.12, 7.717
    { 33, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf49694} }, // S5 OSM: 4292646 48.89, 8.243 x 49.06, 8.705
    { 82, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xbb0022} }, // 1 OSM: 4307991 51.02, 3.692 x 51.11, 3.75
    { 1, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x229922} }, // 4 OSM: 4307994 51.02, 3.709 x 51.07, 3.751
    { 547, NoLogo, 14, LineMetaDataContent::RapidTransit, Color{0x00a6eb} }, // S19 OSM: 4434302 WD: Q30597732 50.76, 6.482 x 50.95, 7.66
    { 437, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf78a18} }, // S51 OSM: 4435864 52.1, 9.374 x 52.4, 9.773
    { 95, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x118349} }, // S21 OSM: 4435868 52.28, 9.466 x 52.38, 9.773
    { 172, 1529, 1529, LineMetaDataContent::RapidTransit, Color{0x903f98} }, // S4 OSM: 4452991 WD: Q459508 47.62, 12.87 x 47.84, 13
    { 36, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x8ec7e8} }, // S8 OSM: 4470844 52.32, 9.687 x 52.46, 9.792
    { 209, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x59249a} }, // 14 OSM: 4489019 46.18, 6.077 x 46.24, 6.144
    { 14, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xa84b97} }, // 18 OSM: 4489020 46.17, 6.054 x 46.23, 6.144
    { 160, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x774c2d} }, // 15 OSM: 4489138 46.18, 6.12 x 46.22, 6.149
    { 1, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 4 OSM: 4494871 WD: Q2105648 52.34, 4.889 x 52.38, 4.905
    { 7, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xab10d2} }, // 12 OSM: 4495366 WD: Q14500288 52.35, 4.879 x 52.38, 4.919
    { 82, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffbf00} }, // 1 OSM: 4497227 WD: Q2663350 52.35, 4.775 x 52.36, 4.934
    { 8, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffbf00} }, // 2 OSM: 4497722 WD: Q2033321 52.34, 4.804 x 52.38, 4.899
    { 86, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xab10d2} }, // 3 OSM: 4498754 WD: Q2051638 52.35, 4.87 x 52.39, 4.952
    { 4, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffbf00} }, // 5 OSM: 4501532 WD: Q2343376 52.3, 4.867 x 52.38, 4.884
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff7f00} }, // 7 OSM: 4502267 WD: Q4405692 52.36, 4.818 x 52.38, 4.94
    { 232, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 19 OSM: 4507967 WD: Q2402279 52.34, 4.838 x 52.39, 4.971
    { 85, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xab10d2} }, // 13 OSM: 4512711 WD: Q2157983 52.37, 4.803 x 52.38, 4.899
    { 209, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00ff00} }, // 14 OSM: 4513498 WD: Q2108285 52.36, 4.892 x 52.38, 4.952
    { 153, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf49ac1} }, // 24 OSM: 4513900 WD: Q2651682 52.34, 4.857 x 52.38, 4.902
    { 142, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x007fff} }, // 17 OSM: 4514442 WD: Q2400889 52.36, 4.787 x 52.38, 4.899
    { 463, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xd59758} }, // 26 OSM: 4514564 WD: Q2503173 52.35, 4.898 x 52.38, 5.005
    { 145, NoLogo, 1626, LineMetaDataContent::Subway, Color{0x29ab4d} }, // 50 OSM: 4515358 WD: Q2466111 52.29, 4.834 x 52.4, 4.99
    { 438, NoLogo, 1626, LineMetaDataContent::Subway, Color{0xf69931} }, // 51 OSM: 4515359 WD: Q606629 52.33, 4.834 x 52.4, 4.924
    { 551, NoLogo, 1626, LineMetaDataContent::Subway, Color{0xfcfb05} }, // 54 OSM: 4515360 WD: Q2183200 52.29, 4.9 x 52.38, 4.99
    { 554, NoLogo, 1626, LineMetaDataContent::Subway, Color{0xff0000} }, // 53 OSM: 4515361 WD: Q2163442 52.31, 4.9 x 52.38, 4.985
    { 156, 468, 468, LineMetaDataContent::RapidTransit, Color{0x5b9a6d} }, // S2 OSM: 4615535 WD: Q680235 47.24, 10.86 x 47.39, 11.78
    { 33, 468, 468, LineMetaDataContent::RapidTransit, Color{0xd4b4c4} }, // S5 OSM: 4615672 WD: Q680235 47.25, 11.19 x 47.39, 11.4
    { 88, 1529, 1529, LineMetaDataContent::RapidTransit, Color{} }, // S1 OSM: 4615721 WD: Q2204422 47.15, 9.601 x 47.55, 9.817
    { 557, 1651, 1678, LineMetaDataContent::Subway, Color{0xff0000} }, // m2 OSM: 4621397 WD: Q3239144 46.51, 6.626 x 46.54, 6.661
    { 8, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x94c11a} }, // 2 OSM: 4622863 52.23, 10.52 x 52.29, 10.54
    { 205, 1703, 100, LineMetaDataContent::Subway, Color{0xb8282e} }, // U1 OSM: 4656730 WD: Q198432 50.1, 8.634 x 50.17, 8.687
    { 189, 1720, 100, LineMetaDataContent::Subway, Color{0x4a5eaa} }, // U3 OSM: 4656731 WD: Q19862991 50.1, 8.537 x 50.22, 8.687
    { 195, 1737, 100, LineMetaDataContent::Subway, Color{0xf172ac} }, // U4 OSM: 4656732 WD: Q19862998 50.11, 8.652 x 50.14, 8.755
    { 198, 1754, 100, LineMetaDataContent::Subway, Color{0x007942} }, // U5 OSM: 4656733 WD: Q3040872 50.11, 8.662 x 50.16, 8.692
    { 186, 1771, 100, LineMetaDataContent::Subway, Color{0xe4a023} }, // U7 OSM: 4656734 WD: Q3040904 50.11, 8.607 x 50.15, 8.755
    { 183, 1788, 100, LineMetaDataContent::Subway, Color{0xc77db5} }, // U8 OSM: 4656735 WD: Q3063407 50.1, 8.621 x 50.18, 8.687
    { 180, 1805, 100, LineMetaDataContent::Subway, Color{0xeed700} }, // U9 OSM: 4656736 WD: Q19862984 50.14, 8.621 x 50.2, 8.674
    { 560, 1822, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe67310} }, // A2 OSM: 4785912 WD: Q19582807 53.71, 9.966 x 53.83, 9.993
    { 310, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00a5c1} }, // T1 OSM: 5157502 47.22, 5.949 x 47.26, 6.061
    { 82, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe4002c} }, // 1 OSM: 5185991 51, 13.67 x 51.06, 13.82
    { 8, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xeb5b2d} }, // 2 OSM: 5186008 51.01, 13.65 x 51.06, 13.85
    { 1, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc9061a} }, // 4 OSM: 5186035 51.02, 13.56 x 51.16, 13.84
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffdd00} }, // 6 OSM: 5186067 51, 13.65 x 51.06, 13.84
    { 11, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x229133} }, // 8 OSM: 5186073 51.03, 13.72 x 51.12, 13.77
    { 150, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x93c355} }, // 9 OSM: 5186435 51, 13.69 x 51.08, 13.8
    { 92, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf9b000} }, // 10 OSM: 5186677 51.04, 13.71 x 51.07, 13.81
    { 81, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc2ddaf} }, // 11 OSM: 5186681 51.02, 13.73 x 51.07, 13.86
    { 85, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfdc300} }, // 13 OSM: 5186751 51, 13.69 x 51.08, 13.8
    { 82, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xd52330} }, // 1 OSM: 5209167 50.93, 6.816 x 50.96, 7.162
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe6855c} }, // 7 OSM: 5231292 50.87, 6.797 x 50.94, 7.06
    { 327, 58, 58, LineMetaDataContent::Subway, Color{} }, // U11 OSM: 5311905 WD: Q203252 51.42, 6.992 x 51.54, 7.026
    { 563, 58, 58, LineMetaDataContent::Subway, Color{} }, // U17 OSM: 5312041 WD: Q203252 51.43, 6.973 x 51.5, 7.013
    { 252, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf9b000} }, // 20 OSM: 5421483 51.04, 13.71 x 51.07, 13.74
    { 8, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009cdd} }, // 2 OSM: 5484713 53.38, 14.55 x 53.45, 14.64
    { 567, 1837, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe79500} }, // A1 OSM: 5610369 WD: Q19368804 53.55, 9.889 x 54.08, 10.02
    { 86, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xd75128} }, // 3 OSM: 5646916 50.69, 12.46 x 50.73, 12.53
    { 128, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffa500} }, // 60 OSM: 5664426 WD: Q30716928 52.01, 5.076 x 52.09, 5.108
    { 102, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffa500} }, // 61 OSM: 5664427 WD: Q81422423 52.01, 5.028 x 52.09, 5.108
    { 142, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x6dcff6} }, // 17 OSM: 5740169 50.86, 6.957 x 50.93, 7.004
    { 18, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x21bfc1} }, // 16 OSM: 5742444 50.68, 6.943 x 50.99, 7.159
    { 1, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe06e9f} }, // 4 OSM: 5742445 50.93, 6.872 x 51.02, 7.044
    { 570, 58, 58, LineMetaDataContent::Subway, Color{0xda251d} }, // U71 OSM: 5747258 WD: Q661002 51.16, 6.775 x 51.26, 6.886
    { 574, 58, 58, LineMetaDataContent::Subway, Color{0xda251d} }, // U83 OSM: 5748738 WD: Q661002 51.16, 6.775 x 51.25, 6.886
    { 578, 58, 58, LineMetaDataContent::Subway, Color{0xda251d} }, // U73 OSM: 5756097 WD: Q661002 51.19, 6.775 x 51.24, 6.867
    { 582, 58, 58, LineMetaDataContent::Subway, Color{0xda251d} }, // U72 OSM: 5756147 WD: Q661002 51.19, 6.762 x 51.3, 6.847
    { 1, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xa4107f} }, // 4 OSM: 5804724 WD: Q3476269 51.91, 4.432 x 51.96, 4.504
    { 586, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfbc424} }, // U42 OSM: 5890483 51.47, 7.433 x 51.56, 7.547
    { 590, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xec2425} }, // U45 OSM: 5892934 51.49, 7.46 x 51.52, 7.475
    { 225, NoLogo, 1852, LineMetaDataContent::Subway, Color{0x00aa50} }, // A OSM: 5955845 WD: Q2310450 51.9, 4.315 x 51.96, 4.566
    { 229, NoLogo, 1852, LineMetaDataContent::Subway, Color{0xffd301} }, // B OSM: 5955846 WD: Q2960661 51.9, 4.129 x 51.98, 4.587
    { 220, NoLogo, 1852, LineMetaDataContent::Subway, Color{0xef1f1f} }, // C OSM: 5955847 WD: Q2058778 51.83, 4.32 x 51.94, 4.601
    { 410, NoLogo, 1852, LineMetaDataContent::Subway, Color{0x1bc5e9} }, // D OSM: 5955848 WD: Q2034685 51.83, 4.32 x 51.92, 4.497
    { 273, NoLogo, 1877, LineMetaDataContent::Subway, Color{0x1a389a} }, // E OSM: 5955849 WD: Q2687418 51.87, 4.325 x 52.08, 4.497
    { 8, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x90130c} }, // 2 OSM: 5955850 WD: Q1982139 51.88, 4.464 x 51.9, 4.554
    { 252, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfbb316} }, // 20 OSM: 5966563 WD: Q3118970 51.88, 4.471 x 51.92, 4.539
    { 594, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // NL1 OSM: 5976635 49, 8.405 x 49.01, 8.479
    { 598, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x006699} }, // NL2 OSM: 5976636 48.99, 8.384 x 49.01, 8.411
    { 142, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x4d3d00} }, // 17 OSM: 6061801 49.01, 8.359 x 49.05, 8.452
    { 18, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffaaaa} }, // 16 OSM: 6061802 48.99, 8.383 x 49.05, 8.452
    { 14, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00805a} }, // 18 OSM: 6061803 49, 8.431 x 49.05, 8.479
    { 273, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // E OSM: 6062533 48.95, 8.283 x 49.11, 8.505
    { 1, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xea5297} }, // 4 OSM: 6092716 47.99, 7.829 x 48.04, 7.863
    { 176, NoLogo, 14, LineMetaDataContent::RapidTransit, Color{0xf36421} }, // S 1 OSM: 6116272 WD: Q56378877 50.88, 13.46 x 51.16, 14.24
    { 517, NoLogo, 14, LineMetaDataContent::RapidTransit, Color{0xb8282e} }, // S 2 OSM: 6116280 WD: Q56378880 50.96, 13.72 x 51.13, 13.93
    { 480, NoLogo, 14, LineMetaDataContent::RapidTransit, Color{0xed0172} }, // S 3 OSM: 6116305 WD: Q56378881 50.9, 13.34 x 51.04, 13.73
    { 82, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc01115} }, // 1 OSM: 6182760 WD: Q2085324 51.98, 4.277 x 52.12, 4.359
    { 8, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x006600} }, // 2 OSM: 6182761 WD: Q3926989 52.05, 4.236 x 52.09, 4.383
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0093de} }, // 6 OSM: 6182762 WD: Q2205103 52.06, 4.264 x 52.1, 4.4
    { 81, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xcd853f} }, // 11 OSM: 6192619 WD: Q2084217 52.06, 4.27 x 52.11, 4.324
    { 7, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff66ff} }, // 12 OSM: 6192620 WD: Q2541548 52.06, 4.252 x 52.09, 4.324
    { 150, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xa6c116} }, // 9 OSM: 6192621 WD: Q2293268 52.03, 4.257 x 52.12, 4.329
    { 160, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe63a6b} }, // 15 OSM: 6197181 WD: Q2202159 52.04, 4.315 x 52.08, 4.393
    { 18, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfa7222} }, // 16 OSM: 6197182 WD: Q2746551 52.02, 4.271 x 52.1, 4.327
    { 142, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x006b8b} }, // 17 OSM: 6197183 WD: Q2417431 52.02, 4.289 x 52.08, 4.339
    { 232, NoLogo, 1877, LineMetaDataContent::Tramway, Color{0xc01115} }, // 19 OSM: 6197184 WD: Q2886326 52.01, 4.35 x 52.09, 4.406
    { 602, 1891, 1917, LineMetaDataContent::Subway, Color{0x0a9cda} }, // Victoria OSM: 6354922 WD: Q203030 51.46, -0.1441 x 51.59, -0.01927
    { 611, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0b4ea2} }, // TL 1 OSM: 6421836 50.83, -0.5143 x 52.14, -0.03743
    { 616, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf7931d} }, // SN 5 OSM: 6489645 51.07, -0.3198 x 51.5, 0.2709
    { 1, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe41f25} }, // 4 OSM: 6576221 48.22, 14.23 x 48.31, 14.29
    { 621, NoLogo, 14, LineMetaDataContent::RapidTransit, Color{0x6c421b} }, // S14 OSM: 6731045 WD: Q7388188 47.27, 8.429 x 47.41, 8.84
    { 625, 58, 58, LineMetaDataContent::Subway, Color{0x302276} }, // U74 OSM: 6760736 WD: Q661002 51.16, 6.615 x 51.28, 6.853
    { 26, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfff200} }, // S7 OSM: 6796259 48.63, 8.065 x 49.01, 8.432
    { 629, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfff200} }, // S71 OSM: 6796260 48.63, 8.065 x 48.99, 8.405
    { 633, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x6d682a} }, // S81 OSM: 6796368 48.44, 8.215 x 48.99, 8.782
    { 637, 1933, NoLogo, LineMetaDataContent::RapidTransit, Color{0xc6cc00} }, // J OSM: 6904183 WD: Q93388 48.88, 1.478 x 49.29, 2.326
    { 639, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf68c59} }, // T3a OSM: 6907402 48.82, 2.271 x 48.85, 2.411
    { 538, 1966, 829, LineMetaDataContent::Tramway, Color{0xf2af00} }, // T4 OSM: 6910344 WD: Q1826681 48.89, 2.478 x 48.93, 2.562
    { 472, 1993, 829, LineMetaDataContent::Tramway, Color{0xb156a1} }, // T5 OSM: 6910410 WD: Q3238968 48.94, 2.356 x 48.98, 2.391
    { 643, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe85426} }, // T6 OSM: 6910437 48.78, 2.169 x 48.81, 2.301
    { 646, 2020, 829, LineMetaDataContent::Tramway, Color{0xb98b59} }, // T7 OSM: 6910465 WD: Q3239019 48.71, 2.352 x 48.79, 2.373
    { 479, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x5cda21} }, // RS 3 OSM: 6925925 53.05, 8.002 x 53.18, 8.815
    { 454, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // RS 4 OSM: 6925927 53.05, 8.452 x 53.49, 8.815
    { 649, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xffcf00} }, // OrlyVAL OSM: 6928902 WD: Q432593 48.73, 2.3 x 48.76, 2.37
    { 657, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x142b4a} }, // CDGVAL OSM: 6928933 WD: Q1023114 49, 2.542 x 49.01, 2.572
    { 82, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc00027} }, // 1 OSM: 6981890 47.74, 7.321 x 47.78, 7.343
    { 506, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf7e017} }, // 32 OSM: 6995933 50.78, 4.313 x 50.88, 4.416
    { 4, 2047, 2068, LineMetaDataContent::Subway, Color{0xfab20b} }, // 5 OSM: 6996917 WD: Q957143 50.81, 4.266 x 50.86, 4.432
    { 8, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffd80e} }, // 2 OSM: 7006051 47.73, 7.297 x 47.76, 7.352
    { 82, 2092, 2068, LineMetaDataContent::Subway, Color{0xb91893} }, // 1 OSM: 7006076 WD: Q1345228 50.84, 4.319 x 50.86, 4.464
    { 86, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00a651} }, // 3 OSM: 7006942 47.74, 7.276 x 47.76, 7.344
    { 156, 2113, 14, LineMetaDataContent::RapidTransit, Color{0x6cc247} }, // S2 OSM: 7091572 WD: Q7388247 48.13, 11.25 x 48.41, 11.91
    { 27, 2129, 2150, LineMetaDataContent::Tramway, Color{0xfff06e} }, // 7 OSM: 7135778 WD: Q3239018 50.81, 4.336 x 50.9, 4.408
    { 379, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xde3b21} }, // 92 OSM: 7152034 50.79, 4.34 x 50.88, 4.381
    { 8, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x37b355} }, // 2 OSM: 7157243 WD: Q60031554 48.38, 9.936 x 48.43, 9.987
    { 82, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xed1b24} }, // 1 OSM: 7157244 WD: Q60031375 48.39, 9.955 x 48.43, 10.03
    { 8, 2176, 1121, LineMetaDataContent::Subway, Color{0x216eb4} }, // 2 OSM: 7227705 WD: Q50718 48.85, 2.278 x 48.88, 2.399
    { 664, 2194, 1917, LineMetaDataContent::Subway, Color{0xe42313} }, // Central OSM: 7254206 WD: Q205355 51.5, -0.4378 x 51.69, 0.1146
    { 273, 2219, 874, LineMetaDataContent::RapidTransit, Color{0xbd76a1} }, // E OSM: 7271953 WD: Q668655 48.74, 2.327 x 48.9, 2.761
    { 85, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf6c828} }, // 13 OSM: 7295272 47.35, 8.481 x 47.41, 8.542
    { 8, 2240, 2068, LineMetaDataContent::Subway, Color{0xf57000} }, // 2 OSM: 7305855 WD: Q1826676 50.83, 4.321 x 50.87, 4.37
    { 672, 2261, 14, LineMetaDataContent::RapidTransit, Color{0x9f4c37} }, // S41 OSM: 7369771 WD: Q12374455 52.46, 13.28 x 52.55, 13.48
    { 634, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x338c26} }, // 81 OSM: 7375224 50.82, 4.28 x 50.84, 4.408
    { 88, NoLogo, 2276, LineMetaDataContent::RapidTransit, Color{0x025f33} }, // S1 OSM: 7382640 WD: Q24929119 50.6, 4.32 x 51.22, 4.497
    { 156, NoLogo, 2276, LineMetaDataContent::RapidTransit, Color{0xf26122} }, // S2 OSM: 7383577 WD: Q56309162 50.61, 4.139 x 50.9, 4.716
    { 430, NoLogo, 2276, LineMetaDataContent::RapidTransit, Color{0x059797} }, // S20 OSM: 7386794 WD: Q56309254 50.67, 4.565 x 50.88, 4.719
    { 33, NoLogo, 2276, LineMetaDataContent::RapidTransit, Color{0xfecc09} }, // S5 OSM: 7387151 WD: Q56309389 50.69, 3.87 x 51.02, 4.484
    { 131, NoLogo, 2276, LineMetaDataContent::RapidTransit, Color{0x212876} }, // S3 OSM: 7388964 WD: Q56309590 50.82, 3.601 x 51.02, 4.366
    { 172, NoLogo, 2276, LineMetaDataContent::RapidTransit, Color{0xce2127} }, // S4 OSM: 7389117 WD: Q56309251 50.82, 4.039 x 50.94, 4.433
    { 163, NoLogo, 2276, LineMetaDataContent::RapidTransit, Color{0x965f26} }, // S6 OSM: 7391007 WD: Q56309855 50.69, 3.87 x 50.88, 4.378
    { 26, NoLogo, 2276, LineMetaDataContent::RapidTransit, Color{0x581759} }, // S7 OSM: 7391045 WD: Q56309167 50.73, 4.241 x 51.02, 4.523
    { 36, NoLogo, 2276, LineMetaDataContent::RapidTransit, Color{0x0d96cd} }, // S8 OSM: 7391071 WD: Q56309403 50.65, 4.336 x 50.87, 4.617
    { 297, NoLogo, 2276, LineMetaDataContent::RapidTransit, Color{0x67bc45} }, // S9 OSM: 7391314 WD: Q56309779 50.68, 4.335 x 50.9, 4.717
    { 396, NoLogo, 2276, LineMetaDataContent::RapidTransit, Color{0xff1f20} }, // S10 OSM: 7391375 WD: Q56309273 50.83, 4.039 x 51.02, 4.366
    { 85, 2298, 1121, LineMetaDataContent::Subway, Color{0x89c7d6} }, // 13 OSM: 7420641 WD: Q50759 48.81, 2.284 x 48.95, 2.369
    { 7, 2317, 1121, LineMetaDataContent::Subway, Color{0x328e5b} }, // 12 OSM: 7420642 WD: Q50757 48.82, 2.273 x 48.91, 2.366
    { 81, 2336, 1121, LineMetaDataContent::Subway, Color{0x8e6538} }, // 11 OSM: 7420643 WD: Q50756 48.86, 2.348 x 48.88, 2.416
    { 11, 2355, 1121, LineMetaDataContent::Subway, Color{0xc5a3ca} }, // 8 OSM: 7420644 WD: Q50751 48.77, 2.278 x 48.87, 2.465
    { 4, 2373, 1121, LineMetaDataContent::Subway, Color{0xde8b53} }, // 5 OSM: 7420645 WD: Q50745 48.83, 2.355 x 48.91, 2.449
    { 676, 2391, 1121, LineMetaDataContent::Subway, Color{0x89c7d6} }, // 3bis OSM: 7420646 WD: Q50742 48.87, 2.399 x 48.88, 2.406
    { 293, 2412, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe4b4d1} }, // R OSM: 7420697 WD: Q93383 48.01, 2.373 x 48.84, 2.946
    { 681, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7b4339} }, // H OSM: 7420698 WD: Q2572054 48.88, 2.093 x 49.28, 2.474
    { 683, 2445, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00b092} }, // N OSM: 7420700 WD: Q93376 48.64, 1.37 x 48.99, 2.319
    { 229, 2478, 874, LineMetaDataContent::RapidTransit, Color{0x5092c9} }, // B OSM: 7420701 WD: Q1347825 48.69, 2.071 x 49.01, 2.642
    { 86, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00ff00} }, // 3 OSM: 7560907 51.34, -0.1055 x 51.38, -0.01745
    { 317, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe40053} }, // T2 OSM: 7580423 WD: Q3239070 50.32, 3.509 x 50.47, 3.596
    { 438, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe3ba12} }, // 51 OSM: 7632520 50.78, 4.326 x 50.89, 4.349
    { 382, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe87d0d} }, // 93 OSM: 7632524 50.82, 4.33 x 50.89, 4.372
    { 685, 2499, 1917, LineMetaDataContent::Subway, Color{0xae6017} }, // Bakerloo OSM: 7666698 WD: Q19892 51.49, -0.3357 x 51.59, -0.09912
    { 694, 2525, 1917, LineMetaDataContent::Subway, Color{0xf4a9be} }, // Hammersmith & City OSM: 7666927 WD: Q211270 51.49, -0.2268 x 51.54, 0.08088
    { 713, 2546, 1917, LineMetaDataContent::Subway, Color{0xffd329} }, // Circle OSM: 7671007 WD: Q210321 51.49, -0.2268 x 51.53, -0.07523
    { 720, 2570, 1917, LineMetaDataContent::Subway, Color{0x93ceba} }, // Waterloo & City OSM: 7672075 WD: Q207699 51.5, -0.1142 x 51.51, -0.09074
    { 736, 2591, 1917, LineMetaDataContent::Subway, Color{0x949699} }, // Jubilee OSM: 7673326 WD: Q961290 51.5, -0.303 x 51.62, 0.01165
    { 744, 2616, 1917, LineMetaDataContent::Subway, Color{0x91005a} }, // Metropolitan OSM: 7673626 WD: Q19891 51.51, -0.6112 x 51.71, -0.0757
    { 757, 2646, 1917, LineMetaDataContent::Subway, Color{0x00a166} }, // District OSM: 7677096 WD: Q211265 51.42, -0.3016 x 51.56, 0.253
    { 766, 2672, 1917, LineMetaDataContent::Subway, Color{0x094fa3} }, // Piccadilly OSM: 7702940 WD: Q207689 51.46, -0.4929 x 51.65, -0.09515
    { 777, 2700, 1917, LineMetaDataContent::Subway, Color{0x000000} }, // Northern OSM: 7702944 WD: Q214793 51.4, -0.2756 x 51.65, -0.08677
    { 86, 2726, 1121, LineMetaDataContent::Subway, Color{0x9a9940} }, // 3 OSM: 7733214 WD: Q50741 48.86, 2.28 x 48.9, 2.418
    { 786, 2744, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7b4339} }, // ODEA OSM: 7747967 WD: Q93386 48.88, 2.345 x 48.94, 2.358
    { 791, 2744, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7b4339} }, // ADEO OSM: 7747968 WD: Q93386 48.88, 2.345 x 48.94, 2.358
    { 796, 2744, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7b4339} }, // VOBA OSM: 7747969 WD: Q93386 48.88, 2.345 x 48.94, 2.358
    { 801, 2744, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7b4339} }, // AVOL OSM: 7747970 WD: Q93386 48.88, 2.345 x 48.94, 2.358
    { 290, 2744, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7b4339} }, // APOR OSM: 7747972 WD: Q93386 48.88, 2.345 x 48.94, 2.358
    { 310, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x64318f} }, // T1 OSM: 7758458 WD: Q50319281 49.61, 6.119 x 49.64, 6.176
    { 8, 2777, 2797, LineMetaDataContent::Subway, Color{0xed1d24} }, // 2 OSM: 7786752 WD: Q3238802 50.62, 2.973 x 50.74, 3.181
    { 82, 2823, 2797, LineMetaDataContent::Subway, Color{0xffd400} }, // 1 OSM: 7786754 WD: Q3238658 50.61, 3.036 x 50.64, 3.143
    { 547, NoLogo, 14, LineMetaDataContent::RapidTransit, Color{0xf58220} }, // S19 OSM: 7800298 WD: Q25352054 47.37, 8.227 x 47.6, 8.787
    { 806, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x69be51} }, // U34 OSM: 7801960 48.76, 9.143 x 48.78, 9.178
    { 810, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf17f1a} }, // S 9 OSM: 7805411 51.45, 11.98 x 51.52, 12.64
    { 86, 2843, 2150, LineMetaDataContent::Tramway, Color{0xb5ba05} }, // 3 OSM: 7857250 WD: Q1888831 50.81, 4.336 x 50.9, 4.377
    { 410, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009832} }, // D OSM: 7925628 48.57, 7.691 x 48.59, 7.816
    { 220, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf68712} }, // C OSM: 7925656 48.55, 7.735 x 48.59, 7.773
    { 19, 2864, 2068, LineMetaDataContent::Subway, Color{0x0078ad} }, // 6 OSM: 7927182 WD: Q668977 50.83, 4.321 x 50.9, 4.37
    { 1, 2885, 2150, LineMetaDataContent::Tramway, Color{0xf25482} }, // 4 OSM: 7999217 WD: Q2527775 50.79, 4.318 x 50.86, 4.363
    { 240, 2906, 2150, LineMetaDataContent::Tramway, Color{0x991f36} }, // 25 OSM: 7999338 WD: Q3238750 50.8, 4.358 x 50.87, 4.408
    { 202, 2928, 2150, LineMetaDataContent::Tramway, Color{0xe3ba12} }, // 55 OSM: 7999374 WD: Q2236365 50.86, 4.358 x 50.88, 4.416
    { 342, 2950, 2150, LineMetaDataContent::Tramway, Color{0x9ebfe3} }, // 82 OSM: 7999733 WD: Q2534011 50.78, 4.29 x 50.87, 4.341
    { 14, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xabd02c} }, // 18 OSM: 8054951 50.05, 14.39 x 50.11, 14.44
    { 142, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xa7c9ae} }, // 17 OSM: 8055113 50, 14.4 x 50.13, 14.46
    { 81, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xdc008f} }, // 11 OSM: 8060662 50.05, 14.3 x 50.09, 14.54
    { 80, 1529, 1529, LineMetaDataContent::RapidTransit, Color{0xb72841} }, // S11 OSM: 8149205 WD: Q459508 47.98, 12.85 x 48.04, 12.93
    { 131, 1529, 1529, LineMetaDataContent::RapidTransit, Color{0x22b24c} }, // S3 OSM: 8149206 WD: Q459508 47.28, 12.79 x 47.84, 13.23
    { 156, 1529, 1529, LineMetaDataContent::RapidTransit, Color{0x0072bc} }, // S2 OSM: 8149207 WD: Q459508 47.81, 12.97 x 47.97, 13.27
    { 88, 1529, 1529, LineMetaDataContent::RapidTransit, Color{0xb72841} }, // S1 OSM: 8149208 WD: Q459508 47.81, 12.92 x 47.99, 13.05
    { 317, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // T2 OSM: 8209896 WD: Q16655789 47.99, 0.1929 x 48.02, 0.2359
    { 310, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xeb001b} }, // T1 OSM: 8209897 WD: Q3239229 47.96, 0.152 x 48.02, 0.2304
    { 1, NoLogo, 1877, LineMetaDataContent::Tramway, Color{0xfc751c} }, // 4 OSM: 8255319 WD: Q2735863 52.04, 4.245 x 52.08, 4.543
    { 86, NoLogo, 1877, LineMetaDataContent::Tramway, Color{0x703276} }, // 3 OSM: 8255320 WD: Q3056105 52.05, 4.228 x 52.08, 4.518
    { 36, NoLogo, 14, LineMetaDataContent::RapidTransit, Color{0x5e2d91} }, // S8 OSM: 8294822 WD: Q7388382 47.2, 8.519 x 47.5, 8.782
    { 26, NoLogo, 14, LineMetaDataContent::RapidTransit, Color{0xfebe10} }, // S7 OSM: 8294823 WD: Q7388366 47.22, 8.511 x 47.5, 8.824
    { 156, NoLogo, 14, LineMetaDataContent::RapidTransit, Color{0x5da526} }, // S2 OSM: 8294824 WD: Q7388254 47.13, 8.519 x 47.45, 9.063
    { 814, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x56033a} }, // S 6 OSM: 8303864 51.06, 12.37 x 51.4, 12.7
    { 672, NoLogo, 14, LineMetaDataContent::RapidTransit, Color{0xf9aa8f} }, // S41 OSM: 8306928 WD: Q15088595 47.49, 8.535 x 47.53, 8.724
    { 818, NoLogo, 14, LineMetaDataContent::RapidTransit, Color{0xbda07c} }, // S15 OSM: 8309090 WD: Q7388191 47.22, 8.368 x 47.51, 8.864
    { 33, NoLogo, 14, LineMetaDataContent::RapidTransit, Color{0x48b4ca} }, // S5 OSM: 8311264 WD: Q7388335 47.17, 8.429 x 47.41, 8.864
    { 822, NoLogo, 14, LineMetaDataContent::RapidTransit, Color{0x0588cc} }, // S30 OSM: 8327718 WD: Q7388265 47.5, 8.722 x 47.59, 9.106
    { 323, NoLogo, 14, LineMetaDataContent::RapidTransit, Color{0x7a4c29} }, // S13 OSM: 8327720 WD: Q7388186 47.13, 8.675 x 47.23, 8.75
    { 239, NoLogo, 14, LineMetaDataContent::RapidTransit, Color{0xb41e8e} }, // S25 OSM: 8355962 WD: Q18391643 46.92, 8.519 x 47.38, 9.084
    { 826, NoLogo, 14, LineMetaDataContent::RapidTransit, Color{0x73b3d7} }, // S35 OSM: 8437405 WD: Q7388272 47.46, 8.724 x 47.51, 9.042
    { 468, NoLogo, 14, LineMetaDataContent::RapidTransit, Color{0x32a384} }, // S29 OSM: 8437511 WD: Q7388235 47.5, 8.714 x 47.66, 8.855
    { 830, NoLogo, 14, LineMetaDataContent::RapidTransit, Color{0xad99c9} }, // S40 OSM: 8437648 WD: Q7388295 47.13, 8.682 x 47.22, 8.817
    { 510, NoLogo, 1626, LineMetaDataContent::Subway, Color{0x00adef} }, // 52 OSM: 8466672 WD: Q2466115 52.34, 4.874 x 52.4, 4.933
    { 834, 2972, 829, LineMetaDataContent::Tramway, Color{0xe65e37} }, // T11 OSM: 8467024 WD: Q1083349 48.93, 2.302 x 48.96, 2.424
    { 838, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff7f00} }, // 11* OSM: 8510354 WD: Q2662616 52.36, 4.851 x 52.38, 4.899
    { 655, 3005, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7577c0} }, // L OSM: 8557335 WD: Q93379 48.81, 2.009 x 49.05, 2.324
    { 150, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff00ff} }, // 9 OSM: 8624098 50.86, 4.309 x 50.89, 4.33
    { 33, 3038, 706, LineMetaDataContent::RapidTransit, Color{0xeb8738} }, // S5 OSM: 8662846 WD: Q1159300 45.46, 8.789 x 45.82, 9.589
    { 163, 3052, 706, LineMetaDataContent::RapidTransit, Color{0xebcc00} }, // S6 OSM: 8662847 WD: Q1160580 45.43, 8.625 x 45.53, 9.589
    { 18, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf9b000} }, // 16 OSM: 8712352 52.32, 9.722 x 52.38, 9.837
    { 14, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe4003a} }, // 18 OSM: 8712368 52.33, 9.739 x 52.38, 9.805
    { 36, 3066, 706, LineMetaDataContent::RapidTransit, Color{0xf09ea1} }, // S8 OSM: 8840314 WD: Q1160824 45.48, 9.179 x 45.86, 9.435
    { 297, 3080, 706, LineMetaDataContent::RapidTransit, Color{0x8c3682} }, // S9 OSM: 8840324 WD: Q56920 45.4, 8.956 x 45.65, 9.274
    { 80, 3094, 706, LineMetaDataContent::RapidTransit, Color{0x8787ba} }, // S11 OSM: 8840325 WD: Q1160879 45.48, 9.029 x 45.83, 9.274
    { 7, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf5a300} }, // 12 OSM: 8871002 46.17, 6.122 x 46.2, 6.207
    { 842, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xbac219} }, // U16 OSM: 9091023 48.8, 9.087 x 48.81, 9.277
    { 8, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xa68351} }, // 2 OSM: 9112026 47.54, 7.571 x 47.57, 7.617
    { 86, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x324ea1} }, // 3 OSM: 9118502 47.55, 7.553 x 47.59, 7.631
    { 82, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x835237} }, // 1 OSM: 9118510 47.55, 7.573 x 47.57, 7.608
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0072bc} }, // 6 OSM: 9128621 47.55, 7.537 x 47.59, 7.656
    { 11, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf171ab} }, // 8 OSM: 9173651 47.55, 7.557 x 47.59, 7.608
    { 92, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfeca0a} }, // 10 OSM: 9177454 47.48, 7.459 x 47.55, 7.62
    { 209, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf58220} }, // 14 OSM: 9190891 47.52, 7.587 x 47.57, 7.694
    { 160, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00a54f} }, // 15 OSM: 9193744 47.53, 7.587 x 47.56, 7.6
    { 18, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xa6ce39} }, // 16 OSM: 9196819 47.53, 7.584 x 47.56, 7.605
    { 142, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00aeef} }, // 17 OSM: 9201222 47.48, 7.545 x 47.58, 7.593
    { 8, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xd64560} }, // 2 OSM: 9235815 47.26, 11.34 x 47.28, 11.44
    { 4, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8b445b} }, // 5 OSM: 9235816 47.26, 11.34 x 47.28, 11.44
    { 846, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xffd503} }, // U29 OSM: 9352741 48.77, 9.122 x 48.78, 9.182
    { 850, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x005aab} }, // U15 OSM: 9355172 48.74, 9.156 x 48.85, 9.234
    { 261, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf8b710} }, // 23 OSM: 9396890 48.75, 9.179 x 48.81, 9.221
    { 225, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc01903} }, // A OSM: 9413576 45.76, 3.082 x 45.81, 3.135
    { 96, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00ae9d} }, // 21 OSM: 9414064 47.56, 7.573 x 47.57, 7.608
    { 854, NoLogo, 14, LineMetaDataContent::RapidTransit, Color{0xcb7eb5} }, // S36 OSM: 9414253 WD: Q15088595 47.52, 8.22 x 47.62, 8.538
    { 462, 3109, 14, LineMetaDataContent::RapidTransit, Color{0x018a47} }, // S26 OSM: 9445376 WD: Q7388232 52.4, 13.28 x 52.61, 13.4
    { 4, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009999} }, // 5 OSM: 9544852 53.08, 8.752 x 53.12, 8.818
    { 36, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x5cc1d1} }, // S8 OSM: 9634179 47.17, 14.44 x 47.34, 15
    { 8, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 2 OSM: 9680853 51.37, -0.2081 x 51.42, -0.02612
    { 1, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xb5e61d} }, // 4 OSM: 9680854 51.37, -0.2081 x 51.42, -0.04953
    { 858, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // BLUE OSM: 9701744 53.33, -1.508 x 53.4, -1.344
    { 305, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x800080} }, // PURP OSM: 9701781 53.34, -1.469 x 53.38, -1.424
    { 863, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffff00} }, // YELL OSM: 9701824 53.38, -1.51 x 53.42, -1.405
    { 320, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // TT OSM: 9701873 53.38, -1.469 x 53.44, -1.343
    { 317, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe2393a} }, // T2 OSM: 9797089 49.18, -0.3663 x 49.21, -0.348
    { 531, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x049adc} }, // T3 OSM: 9797090 49.16, -0.3636 x 49.19, -0.3411
    { 868, NoLogo, 3124, LineMetaDataContent::RapidTransit, Color{0xef7b10} }, // Overground OSM: 9806929 WD: Q1854601 51.46, -0.3011 x 51.56, -0.003557
    { 521, 3147, 14, LineMetaDataContent::RapidTransit, Color{0xc36939} }, // S42 OSM: 9942315 WD: Q15118875 52.46, 13.28 x 52.55, 13.48
    { 310, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x23a638} }, // T1 OSM: 9953164 49.15, -0.3663 x 49.2, -0.329
    { 406, NoLogo, 706, LineMetaDataContent::RapidTransit, Color{0x293838} }, // S12 OSM: 9959066 WD: Q26828150 45.36, 9.159 x 45.5, 9.319
    { 1, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009ee3} }, // 4 OSM: 9964886 52.25, 10.51 x 52.27, 10.56
    { 150, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009cdd} }, // 9 OSM: 10015448 53.41, 14.49 x 53.47, 14.55
    { 879, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe2000a} }, // 21A OSM: 10034064 49.4, 8.675 x 49.41, 8.693
    { 92, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe3000b} }, // 10 OSM: 10082596 52.25, 10.51 x 52.31, 10.54
    { 883, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff88bb} }, // EDid;Roch OSM: 10310648 53.41, -2.28 x 53.62, -2.088
    { 212, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x887766} }, // EDid;Sh&C OSM: 10310683 53.41, -2.28 x 53.58, -2.089
    { 893, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0066bb} }, // Airp;Vict;Dean OSM: 10314875 WD: Q22712167 53.37, -2.297 x 53.49, -2.238
    { 908, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff7700} }, // MCUK;Asht OSM: 10320090 53.47, -2.297 x 53.49, -2.098
    { 918, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00ccff} }, // Asht;Eccl OSM: 10326857 WD: Q22087023 53.47, -2.334 x 53.49, -2.098
    { 928, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x881188} }, // Altr;Picc OSM: 10328430 WD: Q22087020 53.39, -2.347 x 53.48, -2.23
    { 938, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffbb00} }, // Bury;Picc OSM: 10334672 53.48, -2.321 x 53.59, -2.226
    { 948, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008800} }, // Bury;Altr OSM: 10334764 53.39, -2.347 x 53.59, -2.226
    { 958, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // TrfC;Crmp OSM: 10334906 53.46, -2.348 x 53.52, -2.227
    { 459, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffa500} }, // 22 OSM: 10396259 WD: Q2885972 52.07, 5.112 x 52.09, 5.184
    { 968, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xdb6198} }, // 305 OSM: 10409526 51.46, 7.152 x 51.48, 7.324
    { 972, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x40558e} }, // 309 OSM: 10409567 51.44, 7.297 x 51.46, 7.337
    { 976, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe28e07} }, // 316 OSM: 10409642 51.48, 7.16 x 51.53, 7.272
    { 82, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x96368b} }, // 1 OSM: 10413963 51.2, 4.388 x 51.26, 4.421
    { 980, NoLogo, 14, LineMetaDataContent::RapidTransit, Color{0x006db6} }, // RB 32 OSM: 10432813 WD: Q7388251 51.43, 6.775 x 51.58, 7.459
    { 986, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xc72a80} }, // L5 OSM: 10443588 46.18, 5.999 x 46.22, 6.144
    { 989, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00b3b9} }, // L6 OSM: 10447940 46.1, 5.821 x 46.22, 6.144
    { 992, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xdc911b} }, // L4 OSM: 10464491 46.17, 6.121 x 46.32, 6.237
    { 142, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00ace7} }, // 17 OSM: 10486182 46.19, 6.125 x 46.2, 6.232
    { 225, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // A OSM: 10486983 47.83, 1.9 x 47.93, 1.939
    { 229, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x72277b} }, // B OSM: 10494114 47.9, 1.854 x 47.91, 1.977
    { 995, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x6c9d40} }, // L3 OSM: 10505987 45.91, 6.121 x 46.32, 6.703
    { 595, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xbf3527} }, // L1 OSM: 10521809 46.17, 6.121 x 46.4, 6.58
    { 599, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0085c4} }, // L2 OSM: 10526246 45.9, 6.116 x 46.32, 6.362
    { 8, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffcc11} }, // 2 OSM: 10547015 51, 3.709 x 51.05, 3.772
    { 150, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff2e17} }, // 9 OSM: 10547655 48.34, 10.89 x 48.37, 10.9
    { 225, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe3028c} }, // A OSM: 10551319 48.38, -4.556 x 48.43, -4.444
    { 417, 3162, 631, LineMetaDataContent::Subway, Color{0x82bb32} }, // M2 OSM: 10760559 WD: Q2519385 45.4, 9.145 x 45.55, 9.44
    { 498, 3182, 631, LineMetaDataContent::Subway, Color{0xe2e11d} }, // M3 OSM: 10788272 WD: Q2519355 45.43, 9.163 x 45.53, 9.257
    { 267, 3202, 631, LineMetaDataContent::Subway, Color{0xeb312e} }, // M1 OSM: 10803053 WD: Q2400801 45.46, 9.084 x 45.54, 9.238
};

static constexpr const auto line_data_count = sizeof(line_data) / sizeof(LineMetaDataContent);

static inline constexpr uint16_t Bucket(uint16_t index) { return line_data_count + index; }

static const int16_t line_data_bucketTable[] = {
    765, 308, 490, -1,
    300, 642, 149, 640, 594, 641, -1,
    238, 696, 694, -1,
    419, 418, 601, 325, -1,
    334, 667, -1,
    647, 616, 653, 651, 652, 655, 743, 654, 587, -1,
    647, 616, 653, 651, 652, 655, 743, 654, -1,
    251, 165, 703, 170, -1,
    414, 663, -1,
    773, 772, -1,
    589, 692, 243, 689, 235, 693, 241, 688, 687, -1,
    711, 200, 705, 709, -1,
    517, 689, -1,
    105, 234, 516, 292, 74, 441, -1,
    681, 680, -1,
    622, 623, 624, 630, 631, -1,
    549, 305, 317, -1,
    17, 320, 322, 376, 377, 323, 379, 592, 21, 12, -1,
    350, 492, 324, 331, 491, 330, 402, -1,
    544, 125, -1,
    338, 337, -1,
    335, 181, 115, 8, 11, -1,
    756, 758, 759, -1,
    737, 739, -1,
    617, 639, -1,
    774, 766, 767, -1,
    359, 363, 365, 242, 665, 691, 245, -1,
    778, 193, 194, 706, -1,
    452, 515, -1,
    475, 404, -1,
    608, 434, 435, 7, 605, 431, 606, 467, 298, 621, 612, 627, 625, 628, 629, -1,
    538, 271, 550, 539, 306, 307, 309, 311, 312, 315, 316, -1,
    584, 50, 51, 174, 686, 577, 558, 559, 560, 561, 562, -1,
    487, 378, 593, -1,
    341, 342, 233, 333, -1,
    422, 423, 321, 327, 182, 424, 425, 521, -1,
    57, 58, 59, -1,
    319, 320, 323, -1,
    255, 254, -1,
    143, 144, 145, 296, 260, -1,
    141, 356, -1,
    357, 690, -1,
    531, 349, 533, 572, 573, 574, -1,
    83, 85, -1,
    4, 43, 27, 29, 26, 28, 6, 44, 10, 94, -1,
    253, 352, 678, 353, 374, 677, 263, 270, 278, 102, 103, 101, -1,
    160, 735, 643, 648, 585, -1,
    753, 755, 751, 752, 754, -1,
    598, 163, -1,
    413, 636, 596, 598, -1,
    775, 489, 626, 625, -1,
    183, 451, -1,
    706, 710, -1,
    719, 482, 720, 723, -1,
    698, 244, 697, -1,
    780, 779, 354, 746, 201, 710, -1,
    515, 152, 453, -1,
    112, 610, 168, 113, -1,
    452, 454, -1,
    668, 671, 611, 632, 626, -1,
    668, 611, -1,
    274, 275, -1,
    40, 590, 41, 49, -1,
    548, 250, 272, 273, 274, 66, 275, 56, -1,
    223, 222, 310, 328, 318, -1,
    223, 222, 310, 318, -1,
    16, 297, 15, 20, 19, 154, 570, 79, 591, -1,
    57, 186, -1,
    16, 297, 15, 20, 19, 154, 570, 487, 378, 591, -1,
    306, 313, 317, 556, -1,
    728, 128, 64, 186, 171, 198, 216, 178, 197, 727, 713, 192, 155, 195, 189, 190, 180, 166, 196, -1,
    313, 556, -1,
    153, 32, 33, 205, 733, 202, 208, 206, -1,
    111, 380, -1,
    415, 184, 288, -1,
    112, 610, 168, -1,
    112, 610, -1,
    52, 65, 139, 381, 398, 357, -1,
    436, 437, -1,
    71, 53, 52, 65, 54, 72, 100, 63, 381, 398, -1,
    529, 535, 536, 351, 530, 532, -1,
    68, 80, 86, 69, 78, 76, -1,
    36, 34, 37, 38, 39, 35, 336, -1,
    2, 48, 127, 23, 24, 1, 3, 109, 110, 732, 620, 744, 116, 167, 96, 92, 91, 73, 90, 89, -1,
    147, 247, 335, -1,
    284, 281, 543, 280, 466, 285, 287, 286, -1,
    293, 294, 295, -1,
    745, 742, -1,
    736, 649, -1,
    634, 332, 248, -1,
    408, 635, 634, 633, 407, 615, 656, 637, 412, 329, 409, 658, 661, 660, 657, 332, 701, 248, 595, 456, 597, 659, -1,
    465, 462, 463, 457, 458, 460, 348, -1,
    472, 470, -1,
    712, 497, 769, 496, -1,
    484, 399, -1,
    715, 717, -1,
    130, 129, 571, 131, -1,
    360, 370, -1,
    133, 724, 134, 725, -1,
    120, 104, 123, 118, 107, 291, 445, 410, 440, 446, 447, -1,
    645, 675, -1,
    430, 427, -1,
    421, 420, -1,
    764, 428, 430, 432, 433, 427, -1,
    551, 554, 553, 266, 42, 267, 552, -1,
    61, 268, 62, 60, -1,
    540, 541, -1,
    761, 221, 217, 218, 763, 220, -1,
    575, 579, 581, 582, 583, 576, 685, 580, -1,
    393, 563, 564, 478, 555, 172, 173, -1,
    581, 576, 173, -1,
    500, 702, 499, 507, 509, 505, 501, 508, 502, 498, 511, 512, 700, 504, -1,
    546, 547, -1,
    702, 499, 506, 507, 509, 505, 501, 508, 502, 498, 511, 512, 700, 504, -1,
    221, 763, -1,
    569, 22, 565, 18, -1,
    569, 565, 18, -1,
    340, 343, 224, -1,
    224, 303, -1,
    310, 314, -1,
    326, 261, 520, 214, 522, 523, 443, 524, 525, 526, -1,
    204, 203, 207, -1,
    387, 385, 390, 394, 386, 384, 395, 396, 494, -1,
    391, 385, 390, 394, 386, 384, 395, 396, 494, -1,
    355, 750, 519, 375, 747, 373, -1,
    120, 104, 123, 168, 445, 446, 447, -1,
    71, 53, 72, 100, 55, 98, -1,
    537, 227, 534, -1,
    485, 114, -1,
    229, 230, 231, 239, 228, -1,
    229, 230, 231, 232, 239, 228, 240, -1,
    5, 25, 46, 30, 47, 0, 304, 9, 161, -1,
    213, 211, 212, 588, 209, -1,
    249, 246, -1,
    279, 302, 283, 748, -1,
    408, 411, 409, -1,
    602, 599, -1,
    411, 406, -1,
    664, 164, -1,
    367, 618, 366, 371, 262, 368, 369, 364, 372, 236, -1,
    367, 364, 372, -1,
    106, 442, 440, -1,
    119, 117, 106, 122, 347, 290, 150, 444, 442, -1,
    439, 619, 673, 672, 704, 646, 481, -1,
    673, 646, -1,
    426, 429, -1,
    514, 513, -1,
    151, 157, -1,
    568, 567, 566, -1,
    222, 761, 218, -1,
    614, 613, -1,
    387, 707, 708, 388, 389, -1,
    387, 394, 384, -1,
    289, 185, -1,
    119, 122, 290, 150, 444, 442, -1,
    135, 142, 226, 136, 137, 138, 225, 392, -1,
    71, 72, -1,
    97, 162, -1,
    77, 67, -1,
    164, 188, -1,
    604, 607, 609, -1,
    721, 722, 714, -1,
    716, 721, 722, 714, 730, -1,
    362, 237, -1,
    104, 347, 107, 112, -1,
    121, 468, -1,
    151, 156, -1,
    156, 670, 277, -1,
    31, 126, 666, -1,
    707, 394, 386, 384, 395, -1,
    386, 395, -1,
    13, 81, -1,
    368, 362, -1,
    339, 749, -1,
};

static const constexpr LineMetaDataQuadTreeDepthIndex line_data_depthOffsets[] = {
    { 26, 0 },
    { 25, 2 },
    { 24, 7 },
    { 23, 32 },
    { 22, 76 },
    { 21, 164 },
    { 20, 258 },
    { 19, 353 },
    { 18, 430 },
    { 17, 448 },
};

static const constexpr LineMetaDataZIndex line_data_zquadtree[] = {
    { 1190, 586 }, // 48.17, -2.758 x 54.88, 3.952
    { 1196, Bucket(0) }, // 48.17, 3.952 x 54.88, 10.66
    { 4762, Bucket(4) }, // 48.17, 0.597 x 51.53, 3.952
    { 4775, Bucket(11) }, // 44.81, 7.308 x 48.17, 10.66
    { 4786, 417 }, // 48.17, 7.308 x 51.53, 10.66
    { 4787, Bucket(15) }, // 51.53, 7.308 x 54.88, 10.66
    { 4792, Bucket(20) }, // 48.17, 10.66 x 51.53, 14.02
    { 19043, Bucket(23) }, // 49.85, -1.081 x 51.53, 0.597
    { 19046, Bucket(33) }, // 51.53, -1.081 x 53.2, 0.597
    { 19048, 703 }, // 48.17, 0.597 x 49.85, 2.275
    { 19050, Bucket(42) }, // 48.17, 2.275 x 49.85, 3.952
    { 19051, Bucket(47) }, // 49.85, 2.275 x 51.53, 3.952
    { 19094, Bucket(50) }, // 44.81, 5.63 x 46.49, 7.308
    { 19100, 705 }, // 44.81, 7.308 x 46.49, 8.986
    { 19101, Bucket(53) }, // 46.49, 7.308 x 48.17, 8.986
    { 19102, Bucket(63) }, // 44.81, 8.986 x 46.49, 10.66
    { 19103, Bucket(68) }, // 46.49, 8.986 x 48.17, 10.66
    { 19125, Bucket(71) }, // 46.49, 10.66 x 48.17, 12.34
    { 19127, Bucket(78) }, // 46.49, 12.34 x 48.17, 14.02
    { 19133, 734 }, // 46.49, 14.02 x 48.17, 15.7
    { 19137, Bucket(81) }, // 49.85, 3.952 x 51.53, 5.63
    { 19139, Bucket(87) }, // 49.85, 5.63 x 51.53, 7.308
    { 19144, Bucket(91) }, // 48.17, 7.308 x 49.85, 8.986
    { 19148, 600 }, // 51.53, 7.308 x 53.2, 8.986
    { 19150, Bucket(102) }, // 51.53, 8.986 x 53.2, 10.66
    { 19151, Bucket(110) }, // 53.2, 8.986 x 54.88, 10.66
    { 19168, Bucket(75) }, // 48.17, 10.66 x 49.85, 12.34
    { 19171, 335 }, // 49.85, 12.34 x 51.53, 14.02
    { 19172, 87 }, // 51.53, 10.66 x 53.2, 12.34
    { 19173, Bucket(113) }, // 53.2, 10.66 x 54.88, 12.34
    { 19174, Bucket(116) }, // 51.53, 12.34 x 53.2, 14.02
    { 19175, 337 }, // 53.2, 12.34 x 54.88, 14.02
    { 76023, 771 }, // 47.33, 1.436 x 48.17, 2.275
    { 76029, 639 }, // 47.33, 2.275 x 48.17, 3.114
    { 76171, 449 }, // 49.01, -0.2419 x 49.85, 0.597
    { 76180, Bucket(122) }, // 53.2, -2.758 x 54.04, -1.92
    { 76182, Bucket(126) }, // 53.2, -1.92 x 54.04, -1.081
    { 76200, Bucket(129) }, // 48.17, 2.275 x 49.01, 3.114
    { 76206, 644 }, // 49.85, 3.114 x 50.69, 3.952
    { 76207, 488 }, // 50.69, 3.114 x 51.53, 3.952
    { 76376, 471 }, // 44.81, 5.63 x 45.65, 6.469
    { 76377, Bucket(132) }, // 45.65, 5.63 x 46.49, 6.469
    { 76380, 528 }, // 46.49, 5.63 x 47.33, 6.469
    { 76382, 187 }, // 46.49, 6.469 x 47.33, 7.308
    { 76400, 215 }, // 44.81, 7.308 x 45.65, 8.147
    { 76407, Bucket(136) }, // 47.33, 8.147 x 48.17, 8.986
    { 76408, Bucket(144) }, // 44.81, 8.986 x 45.65, 9.824
    { 76500, Bucket(149) }, // 46.49, 10.66 x 47.33, 11.5
    { 76501, 75 }, // 47.33, 10.66 x 48.17, 11.5
    { 76502, 452 }, // 46.49, 11.5 x 47.33, 12.34
    { 76503, 75 }, // 47.33, 11.5 x 48.17, 12.34
    { 76509, 493 }, // 47.33, 12.34 x 48.17, 13.18
    { 76548, Bucket(152) }, // 49.85, 3.952 x 50.69, 4.791
    { 76549, Bucket(155) }, // 50.69, 3.952 x 51.53, 4.791
    { 76559, Bucket(171) }, // 50.69, 6.469 x 51.53, 7.308
    { 76560, Bucket(183) }, // 51.53, 3.952 x 52.36, 4.791
    { 76576, 669 }, // 48.17, 7.308 x 49.01, 8.147
    { 76577, 319 }, // 49.01, 7.308 x 49.85, 8.147
    { 76578, Bucket(195) }, // 48.17, 8.147 x 49.01, 8.986
    { 76579, Bucket(199) }, // 49.01, 8.147 x 49.85, 8.986
    { 76582, Bucket(204) }, // 49.85, 8.147 x 50.69, 8.986
    { 76584, Bucket(213) }, // 48.17, 8.986 x 49.01, 9.824
    { 76585, Bucket(217) }, // 49.01, 8.986 x 49.85, 9.824
    { 76587, 296 }, // 49.01, 9.824 x 49.85, 10.66
    { 76606, Bucket(221) }, // 53.2, 9.824 x 54.04, 10.66
    { 76672, 75 }, // 48.17, 10.66 x 49.01, 11.5
    { 76673, Bucket(224) }, // 49.01, 10.66 x 49.85, 11.5
    { 76674, 75 }, // 48.17, 11.5 x 49.01, 12.34
    { 76676, 143 }, // 49.85, 10.66 x 50.69, 11.5
    { 76679, Bucket(230) }, // 50.69, 11.5 x 51.53, 12.34
    { 76685, Bucket(233) }, // 50.69, 12.34 x 51.53, 13.18
    { 76687, Bucket(236) }, // 50.69, 13.18 x 51.53, 14.02
    { 76692, Bucket(243) }, // 53.2, 10.66 x 54.04, 11.5
    { 76699, Bucket(246) }, // 52.36, 13.18 x 53.2, 14.02
    { 76708, Bucket(257) }, // 49.85, 14.02 x 50.69, 14.86
    { 76709, 572 }, // 50.69, 14.02 x 51.53, 14.86
    { 303965, 469 }, // 47.75, -1.92 x 48.17, -1.5
    { 303997, 684 }, // 47.75, -0.2419 x 48.17, 0.1775
    { 303999, 684 }, // 47.75, 0.1775 x 48.17, 0.597
    { 304266, 777 }, // 48.17, -4.856 x 48.59, -4.436
    { 304701, Bucket(270) }, // 51.11, -0.2419 x 51.53, 0.1775
    { 304710, 158 }, // 52.36, -2.339 x 52.78, -1.92
    { 304716, 158 }, // 52.36, -1.92 x 52.78, -1.5
    { 304719, 159 }, // 52.78, -1.5 x 53.2, -1.081
    { 304722, Bucket(276) }, // 53.2, -2.339 x 53.62, -1.92
    { 304730, 740 }, // 53.2, -1.5 x 53.62, -1.081
    { 304744, Bucket(273) }, // 51.53, -0.2419 x 51.95, 0.1775
    { 304779, Bucket(282) }, // 48.59, 1.855 x 49.01, 2.275
    { 304801, Bucket(285) }, // 48.59, 2.275 x 49.01, 2.694
    { 304830, Bucket(290) }, // 50.69, 3.533 x 51.11, 3.952
    { 305473, 183 }, // 45.23, 3.952 x 45.65, 4.372
    { 305475, Bucket(295) }, // 45.23, 4.372 x 45.65, 4.791
    { 305484, 459 }, // 45.65, 4.791 x 46.07, 5.211
    { 305511, 768 }, // 46.07, 6.05 x 46.49, 6.469
    { 305600, 486 }, // 44.81, 7.308 x 45.23, 7.727
    { 305611, Bucket(298) }, // 45.23, 8.566 x 45.65, 8.986
    { 305617, 480 }, // 46.91, 7.308 x 47.33, 7.727
    { 305620, Bucket(301) }, // 47.33, 7.308 x 47.75, 7.727
    { 305627, 699 }, // 46.91, 8.566 x 47.33, 8.986
    { 305628, 731 }, // 47.33, 8.147 x 47.75, 8.566
    { 305630, Bucket(306) }, // 47.33, 8.566 x 47.75, 8.986
    { 305633, Bucket(310) }, // 45.23, 8.986 x 45.65, 9.405
    { 305651, 455 }, // 46.91, 9.405 x 47.33, 9.824
    { 305652, 242 }, // 47.33, 8.986 x 47.75, 9.405
    { 305657, 455 }, // 46.91, 9.824 x 47.33, 10.24
    { 306003, Bucket(318) }, // 46.91, 11.08 x 47.33, 11.5
    { 306004, Bucket(149) }, // 47.33, 10.66 x 47.75, 11.08
    { 306006, Bucket(149) }, // 47.33, 11.08 x 47.75, 11.5
    { 306007, Bucket(322) }, // 47.75, 11.08 x 48.17, 11.5
    { 306009, Bucket(317) }, // 46.91, 11.5 x 47.33, 11.92
    { 306012, Bucket(149) }, // 47.33, 11.5 x 47.75, 11.92
    { 306013, Bucket(321) }, // 47.75, 11.5 x 48.17, 11.92
    { 306014, Bucket(326) }, // 47.33, 11.92 x 47.75, 12.34
    { 306015, 113 }, // 47.75, 11.92 x 48.17, 12.34
    { 306036, 454 }, // 47.33, 12.34 x 47.75, 12.76
    { 306039, 682 }, // 47.75, 12.76 x 48.17, 13.18
    { 306195, 361 }, // 50.27, 4.372 x 50.69, 4.791
    { 306196, Bucket(329) }, // 50.69, 3.952 x 51.11, 4.372
    { 306198, Bucket(335) }, // 50.69, 4.372 x 51.11, 4.791
    { 306235, Bucket(338) }, // 50.27, 6.888 x 50.69, 7.308
    { 306237, Bucket(341) }, // 51.11, 6.469 x 51.53, 6.888
    { 306238, Bucket(346) }, // 50.69, 6.888 x 51.11, 7.308
    { 306239, Bucket(355) }, // 51.11, 6.888 x 51.53, 7.308
    { 306249, 510 }, // 51.95, 4.791 x 52.36, 5.211
    { 306252, 510 }, // 52.36, 4.791 x 52.78, 5.211
    { 306282, Bucket(361) }, // 51.53, 6.888 x 51.95, 7.308
    { 306307, 591 }, // 48.59, 7.727 x 49.01, 8.147
    { 306313, Bucket(366) }, // 48.59, 8.147 x 49.01, 8.566
    { 306315, Bucket(376) }, // 48.59, 8.566 x 49.01, 8.986
    { 306316, Bucket(379) }, // 49.01, 8.147 x 49.43, 8.566
    { 306317, 319 }, // 49.43, 8.147 x 49.85, 8.566
    { 306318, 319 }, // 49.01, 8.566 x 49.43, 8.986
    { 306319, 319 }, // 49.43, 8.566 x 49.85, 8.986
    { 306325, Bucket(390) }, // 51.11, 7.308 x 51.53, 7.727
    { 306328, 333 }, // 49.85, 8.147 x 50.27, 8.566
    { 306331, 261 }, // 50.27, 8.566 x 50.69, 8.986
    { 306337, Bucket(395) }, // 48.59, 8.986 x 49.01, 9.405
    { 306340, 224 }, // 49.01, 8.986 x 49.43, 9.405
    { 306368, Bucket(415) }, // 51.53, 7.308 x 51.95, 7.727
    { 306383, Bucket(418) }, // 52.78, 8.566 x 53.2, 8.986
    { 306406, 382 }, // 52.36, 9.405 x 52.78, 9.824
    { 306424, Bucket(427) }, // 53.2, 9.824 x 53.62, 10.24
    { 306425, 527 }, // 53.62, 9.824 x 54.04, 10.24
    { 306688, Bucket(430) }, // 48.17, 10.66 x 48.59, 11.08
    { 306690, Bucket(434) }, // 48.17, 11.08 x 48.59, 11.5
    { 306696, Bucket(438) }, // 48.17, 11.5 x 48.59, 11.92
    { 306701, 143 }, // 49.43, 11.5 x 49.85, 11.92
    { 306718, 146 }, // 50.69, 11.92 x 51.11, 12.34
    { 306719, Bucket(441) }, // 51.11, 11.92 x 51.53, 12.34
    { 306730, 256 }, // 48.17, 13.6 x 48.59, 14.02
    { 306733, Bucket(448) }, // 49.43, 13.18 x 49.85, 13.6
    { 306741, Bucket(451) }, // 51.11, 12.34 x 51.53, 12.76
    { 306750, Bucket(462) }, // 50.69, 13.6 x 51.11, 14.02
    { 306761, Bucket(469) }, // 51.95, 11.5 x 52.36, 11.92
    { 306762, 398 }, // 51.53, 11.92 x 51.95, 12.34
    { 306782, Bucket(476) }, // 54.04, 11.92 x 54.46, 12.34
    { 306784, 398 }, // 51.53, 12.34 x 51.95, 12.76
    { 306793, 109 }, // 51.95, 13.18 x 52.36, 13.6
    { 306796, Bucket(484) }, // 52.36, 13.18 x 52.78, 13.6
    { 306832, 676 }, // 49.85, 14.02 x 50.27, 14.44
    { 306834, 676 }, // 49.85, 14.44 x 50.27, 14.86
    { 306837, 335 }, // 51.11, 14.02 x 51.53, 14.44
    { 306880, Bucket(505) }, // 51.53, 14.02 x 51.95, 14.44
    { 306898, Bucket(509) }, // 53.2, 14.44 x 53.62, 14.86
    { 1215847, Bucket(518) }, // 47.12, -1.71 x 47.33, -1.5
    { 1215960, 405 }, // 47.33, -0.6613 x 47.54, -0.4516
    { 1216336, 403 }, // 47.33, 0.597 x 47.54, 0.8067
    { 1216380, 770 }, // 47.75, 1.855 x 47.96, 2.065
    { 1218714, Bucket(522) }, // 49.01, -0.4516 x 49.22, -0.2419
    { 1218805, Bucket(525) }, // 51.32, -0.2419 x 51.53, -0.03218
    { 1218878, 264 }, // 52.78, -1.29 x 52.99, -1.081
    { 1218889, 757 }, // 53.41, -2.339 x 53.62, -2.129
    { 1218976, 649 }, // 51.53, -0.2419 x 51.74, -0.03218
    { 1219119, Bucket(528) }, // 48.8, 2.065 x 49.01, 2.275
    { 1219205, Bucket(532) }, // 48.8, 2.275 x 49.01, 2.484
    { 1219322, 628 }, // 50.69, 3.743 x 50.9, 3.952
    { 1221936, Bucket(555) }, // 45.65, 4.791 x 45.86, 5.001
    { 1221991, 258 }, // 47.12, 5.001 x 47.33, 5.211
    { 1222017, Bucket(563) }, // 45.02, 5.63 x 45.23, 5.84
    { 1222044, Bucket(566) }, // 46.07, 6.05 x 46.28, 6.259
    { 1222087, 179 }, // 47.12, 5.84 x 47.33, 6.05
    { 1222403, 176 }, // 45.02, 7.518 x 45.23, 7.727
    { 1222468, Bucket(571) }, // 46.91, 7.308 x 47.12, 7.518
    { 1222483, Bucket(574) }, // 47.54, 7.518 x 47.75, 7.727
    { 1222493, Bucket(577) }, // 47.96, 7.727 x 48.17, 7.937
    { 1222509, 695 }, // 47.12, 8.566 x 47.33, 8.776
    { 1222514, Bucket(582) }, // 47.33, 8.356 x 47.54, 8.566
    { 1222520, 360 }, // 47.33, 8.566 x 47.54, 8.776
    { 1222533, 191 }, // 45.44, 8.986 x 45.65, 9.195
    { 1222554, 177 }, // 45.65, 9.615 x 45.86, 9.824
    { 1222567, 358 }, // 45.44, 10.03 x 45.65, 10.24
    { 1222573, 358 }, // 45.44, 10.24 x 45.65, 10.45
    { 1222618, 461 }, // 47.33, 9.615 x 47.54, 9.824
    { 1224015, Bucket(585) }, // 47.12, 11.29 x 47.33, 11.5
    { 1224031, 291 }, // 47.96, 11.29 x 48.17, 11.5
    { 1224053, Bucket(590) }, // 47.96, 11.5 x 48.17, 11.71
    { 1224157, 679 }, // 47.96, 12.76 x 48.17, 12.97
    { 1224780, 483 }, // 50.27, 4.372 x 50.48, 4.582
    { 1224786, Bucket(602) }, // 50.69, 4.162 x 50.9, 4.372
    { 1224790, Bucket(605) }, // 51.11, 4.162 x 51.32, 4.372
    { 1224792, Bucket(608) }, // 50.69, 4.372 x 50.9, 4.582
    { 1224796, Bucket(611) }, // 51.11, 4.372 x 51.32, 4.582
    { 1224844, 282 }, // 48.59, 6.05 x 48.8, 6.259
    { 1224860, 662 }, // 49.43, 6.05 x 49.64, 6.259
    { 1224950, Bucket(618) }, // 51.11, 6.679 x 51.32, 6.888
    { 1224953, Bucket(626) }, // 50.9, 6.888 x 51.11, 7.098
    { 1224957, Bucket(631) }, // 51.32, 6.888 x 51.53, 7.098
    { 1224959, Bucket(634) }, // 51.32, 7.098 x 51.53, 7.308
    { 1224966, Bucket(641) }, // 51.95, 4.162 x 52.15, 4.372
    { 1224969, Bucket(650) }, // 51.74, 4.372 x 51.95, 4.582
    { 1224972, Bucket(658) }, // 51.95, 4.372 x 52.15, 4.582
    { 1224997, Bucket(662) }, // 52.15, 4.791 x 52.36, 5.001
    { 1224998, Bucket(677) }, // 51.95, 5.001 x 52.15, 5.211
    { 1225008, Bucket(680) }, // 52.36, 4.791 x 52.57, 5.001
    { 1225128, 540 }, // 51.53, 6.888 x 51.74, 7.098
    { 1225130, Bucket(695) }, // 51.53, 7.098 x 51.74, 7.308
    { 1225255, Bucket(698) }, // 48.8, 8.356 x 49.01, 8.566
    { 1225260, 79 }, // 48.59, 8.566 x 48.8, 8.776
    { 1225261, 79 }, // 48.8, 8.566 x 49.01, 8.776
    { 1225262, 64 }, // 48.59, 8.776 x 48.8, 8.986
    { 1225263, 64 }, // 48.8, 8.776 x 49.01, 8.986
    { 1225265, 319 }, // 49.22, 8.147 x 49.43, 8.356
    { 1225266, Bucket(703) }, // 49.01, 8.356 x 49.22, 8.566
    { 1225267, 319 }, // 49.22, 8.356 x 49.43, 8.566
    { 1225272, 378 }, // 49.01, 8.566 x 49.22, 8.776
    { 1225273, Bucket(707) }, // 49.22, 8.566 x 49.43, 8.776
    { 1225274, 224 }, // 49.01, 8.776 x 49.22, 8.986
    { 1225275, Bucket(711) }, // 49.22, 8.776 x 49.43, 8.986
    { 1225301, Bucket(714) }, // 51.32, 7.308 x 51.53, 7.518
    { 1225320, 333 }, // 49.85, 8.566 x 50.06, 8.776
    { 1225321, Bucket(717) }, // 50.06, 8.566 x 50.27, 8.776
    { 1225323, 261 }, // 50.06, 8.776 x 50.27, 8.986
    { 1225350, 126 }, // 48.59, 9.195 x 48.8, 9.405
    { 1225361, 303 }, // 49.22, 8.986 x 49.43, 9.195
    { 1225472, 310 }, // 51.53, 7.308 x 51.74, 7.518
    { 1225535, Bucket(728) }, // 52.99, 8.776 x 53.2, 8.986
    { 1225615, Bucket(732) }, // 52.15, 9.615 x 52.36, 9.824
    { 1225626, Bucket(742) }, // 52.36, 9.615 x 52.57, 9.824
    { 1225637, 387 }, // 52.15, 9.824 x 52.36, 10.03
    { 1225647, Bucket(752) }, // 52.15, 10.45 x 52.36, 10.66
    { 1226784, Bucket(759) }, // 48.17, 11.5 x 48.38, 11.71
    { 1226877, 140 }, // 51.32, 11.92 x 51.53, 12.13
    { 1226933, 438 }, // 49.64, 13.18 x 49.85, 13.39
    { 1226960, 301 }, // 50.69, 12.34 x 50.9, 12.55
    { 1226965, Bucket(771) }, // 51.32, 12.34 x 51.53, 12.55
    { 1227001, Bucket(774) }, // 50.9, 13.6 x 51.11, 13.81
    { 1227044, 70 }, // 51.95, 11.5 x 52.15, 11.71
    { 1227051, Bucket(778) }, // 51.74, 12.13 x 51.95, 12.34
    { 1227083, 84 }, // 53.41, 11.29 x 53.62, 11.5
    { 1227151, Bucket(781) }, // 52.15, 12.97 x 52.36, 13.18
    { 1227162, Bucket(787) }, // 52.36, 12.97 x 52.57, 13.18
    { 1227184, 88 }, // 52.36, 13.18 x 52.57, 13.39
    { 1227186, Bucket(795) }, // 52.36, 13.39 x 52.57, 13.6
    { 1227192, 299 }, // 52.36, 13.6 x 52.57, 13.81
    { 1227266, Bucket(805) }, // 48.17, 14.23 x 48.38, 14.44
    { 1227380, 400 }, // 51.11, 14.86 x 51.32, 15.07
    { 1227523, Bucket(811) }, // 51.74, 14.23 x 51.95, 14.44
    { 1227593, Bucket(814) }, // 53.41, 14.44 x 53.62, 14.65
    { 4863988, 683 }, // 47.96, 0.1775 x 48.07, 0.2824
    { 4865643, 729 }, // 45.76, 3.009 x 45.86, 3.114
    { 4865729, 729 }, // 45.76, 3.114 x 45.86, 3.218
    { 4874970, 448 }, // 49.43, 0.07268 x 49.53, 0.1775
    { 4875681, 738 }, // 53.31, -1.5 x 53.41, -1.395
    { 4876389, 345 }, // 49.32, 1.016 x 49.43, 1.121
    { 4876400, 345 }, // 49.43, 1.016 x 49.53, 1.121
    { 4876478, Bucket(819) }, // 48.8, 2.17 x 48.9, 2.275
    { 4876817, Bucket(823) }, // 48.69, 2.275 x 48.8, 2.38
    { 4876820, Bucket(826) }, // 48.8, 2.275 x 48.9, 2.38
    { 4876821, 477 }, // 48.9, 2.275 x 49.01, 2.38
    { 4877119, 664 }, // 50.58, 3.009 x 50.69, 3.114
    { 4877205, Bucket(829) }, // 50.58, 3.114 x 50.69, 3.218
    { 4877248, 164 }, // 50.69, 3.114 x 50.79, 3.218
    { 4887965, 257 }, // 47.23, 5.001 x 47.33, 5.106
    { 4888008, 257 }, // 47.33, 5.001 x 47.44, 5.106
    { 4888069, 473 }, // 45.13, 5.63 x 45.23, 5.735
    { 4888071, 474 }, // 45.13, 5.735 x 45.23, 5.84
    { 4888177, 495 }, // 46.18, 6.05 x 46.28, 6.154
    { 4889874, 346 }, // 46.91, 7.413 x 47.02, 7.518
    { 4889932, 718 }, // 47.54, 7.518 x 47.65, 7.622
    { 4889974, 132 }, // 47.96, 7.832 x 48.07, 7.937
    { 4890015, 237 }, // 47.23, 8.461 x 47.33, 8.566
    { 4890058, Bucket(832) }, // 47.33, 8.461 x 47.44, 8.566
    { 4890080, Bucket(843) }, // 47.33, 8.566 x 47.44, 8.671
    { 4890433, 697 }, // 47.44, 8.986 x 47.54, 9.09
    { 4895899, 169 }, // 45.34, 11.82 x 45.44, 11.92
    { 4896061, 476 }, // 47.23, 11.29 x 47.33, 11.4
    { 4896063, 476 }, // 47.23, 11.4 x 47.33, 11.5
    { 4896127, Bucket(847) }, // 48.07, 11.4 x 48.17, 11.5
    { 4896213, Bucket(851) }, // 48.07, 11.5 x 48.17, 11.61
    { 4899147, Bucket(861) }, // 50.79, 4.267 x 50.9, 4.372
    { 4899163, 429 }, // 51.21, 4.267 x 51.32, 4.372
    { 4899169, Bucket(869) }, // 50.79, 4.372 x 50.9, 4.477
    { 4899185, Bucket(872) }, // 51.21, 4.372 x 51.32, 4.477
    { 4899790, 269 }, // 50.9, 6.784 x 51, 6.888
    { 4899812, 269 }, // 50.9, 6.888 x 51, 6.993
    { 4899839, 219 }, // 51.42, 7.203 x 51.53, 7.308
    { 4899867, 578 }, // 52.05, 4.267 x 52.15, 4.372
    { 4899889, 685 }, // 52.05, 4.372 x 52.15, 4.477
    { 4899891, 685 }, // 52.05, 4.477 x 52.15, 4.582
    { 4899989, 503 }, // 52.26, 4.791 x 52.36, 4.896
    { 4899991, Bucket(875) }, // 52.26, 4.896 x 52.36, 5.001
    { 4899995, 760 }, // 52.05, 5.106 x 52.15, 5.211
    { 4900034, Bucket(875) }, // 52.36, 4.896 x 52.47, 5.001
    { 4900522, 219 }, // 51.53, 7.203 x 51.63, 7.308
    { 4900879, 151 }, // 48.48, 7.622 x 48.59, 7.727
    { 4900901, Bucket(878) }, // 48.48, 7.727 x 48.59, 7.832
    { 4900912, 157 }, // 48.59, 7.727 x 48.69, 7.832
    { 4900970, 591 }, // 49.01, 8.042 x 49.11, 8.147
    { 4901021, Bucket(881) }, // 48.9, 8.356 x 49.01, 8.461
    { 4901064, Bucket(881) }, // 49.01, 8.356 x 49.11, 8.461
    { 4901082, 344 }, // 49.43, 8.461 x 49.53, 8.566
    { 4901087, 182 }, // 49.74, 8.461 x 49.85, 8.566
    { 4901088, 487 }, // 49.01, 8.566 x 49.11, 8.671
    { 4901091, 224 }, // 49.11, 8.671 x 49.22, 8.776
    { 4901092, 378 }, // 49.22, 8.566 x 49.32, 8.671
    { 4901095, 303 }, // 49.32, 8.671 x 49.43, 8.776
    { 4901109, 182 }, // 49.74, 8.566 x 49.85, 8.671
    { 4901205, Bucket(885) }, // 51.42, 7.308 x 51.53, 7.413
    { 4901207, 557 }, // 51.42, 7.413 x 51.53, 7.518
    { 4901395, 726 }, // 48.69, 9.09 x 48.8, 9.195
    { 4901397, 323 }, // 48.9, 8.986 x 49.01, 9.09
    { 4901398, 126 }, // 48.8, 9.09 x 48.9, 9.195
    { 4901404, 126 }, // 48.8, 9.195 x 48.9, 9.3
    { 4901406, 126 }, // 48.8, 9.3 x 48.9, 9.405
    { 4901428, 126 }, // 48.8, 9.405 x 48.9, 9.51
    { 4901510, Bucket(889) }, // 48.38, 9.929 x 48.48, 10.03
    { 4901888, 222 }, // 51.53, 7.308 x 51.63, 7.413
    { 4902463, Bucket(893) }, // 52.26, 9.72 x 52.36, 9.824
    { 4902506, Bucket(892) }, // 52.36, 9.72 x 52.47, 9.824
    { 4902592, Bucket(898) }, // 52.36, 9.824 x 52.47, 9.929
    { 4907017, Bucket(902) }, // 48.27, 10.87 x 48.38, 10.98
    { 4907098, 252 }, // 49.43, 10.98 x 49.53, 11.08
    { 4907120, 252 }, // 49.43, 11.08 x 49.53, 11.19
    { 4907136, Bucket(905) }, // 48.17, 11.5 x 48.27, 11.61
    { 4907351, 14 }, // 51.42, 10.77 x 51.53, 10.87
    { 4907392, 143 }, // 49.85, 11.5 x 49.95, 11.61
    { 4907487, 136 }, // 51.42, 11.82 x 51.53, 11.92
    { 4907491, 108 }, // 50.79, 12.03 x 50.9, 12.13
    { 4907509, Bucket(912) }, // 51.42, 11.92 x 51.53, 12.03
    { 4907515, Bucket(921) }, // 51.21, 12.24 x 51.32, 12.34
    { 4907518, Bucket(767) }, // 51.32, 12.24 x 51.42, 12.34
    { 4907842, 545 }, // 50.69, 12.45 x 50.79, 12.55
    { 4907860, Bucket(924) }, // 51.32, 12.34 x 51.42, 12.45
    { 4908007, 542 }, // 51, 13.7 x 51.11, 13.81
    { 4908034, 81 }, // 51.53, 10.77 x 51.63, 10.87
    { 4908179, Bucket(927) }, // 52.05, 11.61 x 52.15, 11.71
    { 4908335, 82 }, // 53.52, 11.4 x 53.62, 11.5
    { 4908346, 82 }, // 53.62, 11.4 x 53.73, 11.5
    { 4908739, 95 }, // 52.47, 13.28 x 52.57, 13.39
    { 4908745, 265 }, // 52.47, 13.39 x 52.57, 13.49
    { 4908746, 45 }, // 52.36, 13.49 x 52.47, 13.6
    { 4909065, 210 }, // 48.27, 14.23 x 48.38, 14.33
    { 4909522, 401 }, // 51.11, 14.96 x 51.21, 15.07
    { 19499431, 741 }, // 49.17, -0.3992 x 49.22, -0.3468
    { 19500893, 650 }, // 51.47, -0.137 x 51.53, -0.08461
    { 19505914, 595 }, // 48.8, 2.222 x 48.85, 2.275
    { 19507289, 638 }, // 48.85, 2.38 x 48.9, 2.432
    { 19507319, 603 }, // 48.96, 2.537 x 49.01, 2.589
    { 19507490, 603 }, // 49.01, 2.537 x 49.06, 2.589
    { 19508479, Bucket(930) }, // 50.63, 3.061 x 50.69, 3.114
    { 19508650, Bucket(930) }, // 50.69, 3.061 x 50.74, 3.114
    { 19508821, 188 }, // 50.63, 3.114 x 50.69, 3.166
    { 19508992, 188 }, // 50.69, 3.114 x 50.74, 3.166
    { 19550405, 450 }, // 45.39, 4.372 x 45.44, 4.424
    { 19550416, 450 }, // 45.44, 4.372 x 45.5, 4.424
    { 19550980, 464 }, // 45.76, 4.791 x 45.81, 4.844
    { 19553802, 518 }, // 46.49, 6.626 x 46.54, 6.679
    { 19554239, 609 }, // 47.7, 7.255 x 47.75, 7.308
    { 19554282, 609 }, // 47.75, 7.255 x 47.8, 7.308
    { 19559496, 479 }, // 46.91, 7.413 x 46.96, 7.465
    { 19559701, Bucket(933) }, // 47.7, 7.308 x 47.75, 7.36
    { 19559719, Bucket(937) }, // 47.49, 7.57 x 47.54, 7.622
    { 19559730, Bucket(941) }, // 47.54, 7.57 x 47.59, 7.622
    { 19559744, Bucket(933) }, // 47.75, 7.308 x 47.8, 7.36
    { 19560234, Bucket(947) }, // 47.33, 8.514 x 47.38, 8.566
    { 19584252, 148 }, // 47.23, 11.4 x 47.28, 11.45
    { 19584511, Bucket(950) }, // 48.12, 11.45 x 48.17, 11.5
    { 19584855, Bucket(955) }, // 48.12, 11.55 x 48.17, 11.61
    { 19596591, 674 }, // 50.84, 4.319 x 50.9, 4.372
    { 19596677, 674 }, // 50.84, 4.372 x 50.9, 4.424
    { 19599358, 762 }, // 51.42, 7.255 x 51.47, 7.308
    { 19599553, 685 }, // 52, 4.372 x 52.05, 4.424
    { 19599554, 555 }, // 51.95, 4.424 x 52, 4.477
    { 19599555, 685 }, // 52, 4.424 x 52.05, 4.477
    { 19599560, 555 }, // 51.95, 4.477 x 52, 4.529
    { 19599561, 685 }, // 52, 4.477 x 52.05, 4.529
    { 19600130, 503 }, // 52.36, 4.844 x 52.42, 4.896
    { 19603519, 156 }, // 48.54, 7.675 x 48.59, 7.727
    { 19603562, Bucket(958) }, // 48.59, 7.675 x 48.64, 7.727
    { 19603605, Bucket(961) }, // 48.54, 7.727 x 48.59, 7.78
    { 19603648, Bucket(958) }, // 48.59, 7.727 x 48.64, 7.78
    { 19604360, 487 }, // 49.01, 8.671 x 49.06, 8.723
    { 19604376, 378 }, // 49.22, 8.671 x 49.27, 8.723
    { 19604377, 303 }, // 49.27, 8.671 x 49.32, 8.723
    { 19604379, 303 }, // 49.27, 8.723 x 49.32, 8.776
    { 19604820, 762 }, // 51.42, 7.308 x 51.47, 7.36
    { 19605583, Bucket(965) }, // 48.75, 9.143 x 48.8, 9.195
    { 19605597, 323 }, // 48.96, 9.09 x 49.01, 9.143
    { 19605598, 126 }, // 48.9, 9.143 x 48.96, 9.195
    { 19605599, 323 }, // 48.96, 9.143 x 49.01, 9.195
    { 19605605, 199 }, // 48.75, 9.195 x 48.8, 9.248
    { 19605616, 199 }, // 48.8, 9.195 x 48.85, 9.248
    { 19605620, 126 }, // 48.9, 9.195 x 48.96, 9.248
    { 19605621, 323 }, // 48.96, 9.195 x 49.01, 9.248
    { 19605622, 126 }, // 48.9, 9.248 x 48.96, 9.3
    { 19605623, 323 }, // 48.96, 9.248 x 49.01, 9.3
    { 19605628, 126 }, // 48.9, 9.3 x 48.96, 9.353
    { 19605629, 323 }, // 48.96, 9.3 x 49.01, 9.353
    { 19605630, 126 }, // 48.9, 9.353 x 48.96, 9.405
    { 19605631, 323 }, // 48.96, 9.353 x 49.01, 9.405
    { 19605701, 126 }, // 48.75, 9.405 x 48.8, 9.457
    { 19605716, 126 }, // 48.9, 9.405 x 48.96, 9.457
    { 19605717, 323 }, // 48.96, 9.405 x 49.01, 9.457
    { 19605719, 323 }, // 48.96, 9.457 x 49.01, 9.51
    { 19610197, Bucket(969) }, // 52.31, 9.824 x 52.36, 9.877
    { 19610368, Bucket(975) }, // 52.36, 9.824 x 52.42, 9.877
    { 19628069, 776 }, // 48.33, 10.87 x 48.38, 10.93
    { 19628351, 252 }, // 49.38, 11.03 x 49.43, 11.08
    { 19628394, 259 }, // 49.43, 11.03 x 49.48, 11.08
    { 19628437, 252 }, // 49.38, 11.08 x 49.43, 11.14
    { 19628480, 259 }, // 49.43, 11.08 x 49.48, 11.14
    { 19629405, Bucket(978) }, // 51.47, 10.77 x 51.53, 10.82
    { 19629808, 397 }, // 50.48, 12.13 x 50.53, 12.18
    { 19630037, 383 }, // 51.47, 11.92 x 51.53, 11.97
    { 19630063, 100 }, // 51.26, 12.29 x 51.32, 12.34
    { 19630074, 99 }, // 51.32, 12.29 x 51.37, 12.34
    { 19631440, 99 }, // 51.32, 12.34 x 51.37, 12.39
    { 19634958, 93 }, // 52.47, 13.34 x 52.52, 13.39
    { 19637306, 276 }, // 50.06, 14.39 x 50.11, 14.44
    { 19637392, 276 }, // 50.06, 14.44 x 50.11, 14.49
    { 78216959, 607 }, // 47.72, 7.282 x 47.75, 7.308
    { 78241281, Bucket(981) }, // 47.36, 8.566 x 47.38, 8.592
    { 78398253, 685 }, // 52.02, 4.529 x 52.05, 4.555
    { 78398463, 500 }, // 52.34, 4.765 x 52.36, 4.791
    { 78399146, 509 }, // 52.36, 4.765 x 52.39, 4.791
    { 78414079, 277 }, // 48.56, 7.701 x 48.59, 7.727
    { 78417525, Bucket(984) }, // 49.4, 8.671 x 49.43, 8.697
    { 78422901, 323 }, // 48.98, 9.51 x 49.01, 9.536
    { 78429877, 175 }, // 50.87, 10.56 x 50.9, 10.58
    { 78429920, 175 }, // 50.9, 10.56 x 50.92, 10.58
    { 78441472, 707 }, // 52.36, 9.824 x 52.39, 9.851
    { 78512277, 416 }, // 48.35, 10.87 x 48.38, 10.9
    { 78512320, 416 }, // 48.38, 10.87 x 48.41, 10.9
    { 78512810, 442 }, // 48.17, 11.48 x 48.2, 11.5
    { 78514184, Bucket(955) }, // 48.17, 11.55 x 48.2, 11.58
    { 78514186, 124 }, // 48.17, 11.58 x 48.2, 11.61
    { 78519806, 142 }, // 51.47, 11.9 x 51.5, 11.92
    { 78520255, 53 }, // 51.29, 12.31 x 51.32, 12.34
    { 312868522, 607 }, // 47.75, 7.295 x 47.76, 7.308
    { 313357693, 124 }, // 48.16, 11.58 x 48.17, 11.59
    { 313593855, 509 }, // 52.35, 4.778 x 52.36, 4.791
    { 314051242, 104 }, // 48.17, 11.49 x 48.18, 11.5
};
}
