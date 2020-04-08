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
    "M6\0"
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
    "21A\0"
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
    "R\0"
    "S9\0"
    "SIR1\0"
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
    "U74\0"
    "S71\0"
    "S81\0"
    "T3a\0"
    "T6\0"
    "T7\0"
    "OrlyVAL\0"
    "CDGVAL\0"
    "Central\0"
    "S41\0"
    "3bis\0"
    "Bakerloo\0"
    "Hammersmith & City\0"
    "Circle\0"
    "Waterloo & City\0"
    "Jubilee\0"
    "Metropolitan\0"
    "District\0"
    "Piccadilly\0"
    "Northern\0"
    "U34\0"
    "S 9\0"
    "S 6\0"
    "S30\0"
    "S35\0"
    "T11\0"
    "11*\0"
    "U16\0"
    "U29\0"
    "U15\0"
    "S36\0"
    "BLUE\0"
    "PURP\0"
    "YELL\0"
    "Overground\0"
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
    "Berlin S5.svg\0"
    "Berlin S8.svg\0"
    "Berlin S3.svg\0"
    "Berlin U6.svg\0"
    "U-Bahn.svg\0"
    "München S8 1985-1988.svg\0"
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
    "Berlin S85.svg\0"
    "Berlin S9.svg\0"
    "München S5.svg\0"
    "Logo Metropolitane Italia.svg\0"
    "Berlin S1.svg\0"
    "Frankfurt S7.svg\0"
    "Milano S3.svg\0"
    "Linee S di Milano.svg\0"
    "Milano S1.svg\0"
    "Milano S13.svg\0"
    "Milano S4.svg\0"
    "Milano S2.svg\0"
    "S-Bahn Salzburg.svg\0"
    "Frankfurt U2.svg\0"
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
    "Logo Paris tram ligne1.svg\0"
    "Paris logo tram jms.svg\0"
    "S-Bahn-Logo.svg\0"
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
    "Logo Paris tram ligne3b.svg\0"
    "Logo Metro Rennes.svg\0"
    "Logo Paris tram ligne8.svg\0"
    "Amsterdam metro logo.svg\0"
    "S-Bahn Austria.svg\0"
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
    "Stadtbahn.svg\0"
    "Hamburg A1.svg\0"
    "Metro Rotterdam logo.svg\0"
    "Map Point.png\0"
    "Victoria line roundel.svg\0"
    "Underground.svg\0"
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
    "Symbole Lille 2.svg\0"
    "Lille Metro Logo 2017.svg\0"
    "Symbole Lille 1.svg\0"
    "STIB-MIVB Line 3.svg\0"
    "STIB-MIVB Line 6.svg\0"
    "STIB-MIVB Line 4.svg\0"
    "STIB-MIVB Line 25.svg\0"
    "STIB-MIVB Line 55.svg\0"
    "STIB-MIVB Line 82.svg\0"
    "Milano S5.svg\0"
    "Milano S6.svg\0"
    "Milano S8.svg\0"
    "Milano S9.svg\0"
    "Milano S11.svg\0"
    "Berlin S26.svg\0"
    "Berlin S42.svg\0"
    "Milano linea M2.svg\0"
    "Milano linea M3.svg\0"
    "Milano linea M1.svg\0"
};

static const constexpr auto NoLogo = 13;

static const constexpr LineMetaDataContent line_data[] = {
    { 0, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xbb, 0x0, 0x0 }, // M4 OSM: 11134 52.52, 13.4 x 52.57, 13.53
    { 3, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xcc, 0x99, 0x33 }, // M5 OSM: 11135 52.52, 13.36 x 52.57, 13.52
    { 7, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x99, 0x66, 0x99 }, // 12 OSM: 11140 52.52, 13.38 x 52.56, 13.47
    { 10, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xff, 0x66, 0x33 }, // M8 OSM: 11141 52.52, 13.36 x 52.57, 13.58
    { 14, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xff, 0x66, 0x33 }, // 18 OSM: 11142 52.53, 13.54 x 52.55, 13.62
    { 18, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0x66, 0x99 }, // 16 OSM: 11143 52.51, 13.47 x 52.57, 13.58
    { 21, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0x33, 0x88 }, // M6 OSM: 11145 52.52, 13.4 x 52.55, 13.62
    { 8, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0x80, 0x0 }, // 2 OSM: 11201 51.17, 4.35 x 51.26, 4.464
    { 24, 0, NoLogo, LineMetaDataContent::RapidTransit, 0x80, 0x70, 0xb7 }, // S7 OSM: 14809 WD: Q7388362 52.39, 13.07 x 52.57, 13.57
    { 27, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0x80, 0x70, 0xb7 }, // S75 OSM: 14810 52.5, 13.43 x 52.57, 13.54
    { 31, 14, NoLogo, LineMetaDataContent::RapidTransit, 0xf2, 0x57, 0x21 }, // S5 OSM: 14811 WD: Q3743008 52.5, 13.28 x 52.59, 13.91
    { 34, 28, NoLogo, LineMetaDataContent::RapidTransit, 0x52, 0xb4, 0x47 }, // S8 OSM: 14984 WD: Q4048678 52.35, 13.29 x 52.69, 13.63
    { 37, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x93, 0x13, 0xba }, // Straßenbahn S2: Spöck <=> Rheinstetten OSM: 16111 48.95, 8.283 x 49.11, 8.505
    { 80, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xb3, 0xee, 0x3a }, // 1 OSM: 17413 WD: Q318073 51.49, 10.79 x 51.52, 10.8
    { 8, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x2e, 0x8b, 0x57 }, // 2 OSM: 17415 WD: Q318073 51.5, 10.78 x 51.51, 10.82
    { 84, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x99, 0x66, 0x33 }, // 3 OSM: 17839 48.99, 8.347 x 49.04, 8.411
    { 80, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xff, 0x0, 0x0 }, // 1 OSM: 17840 48.98, 8.347 x 49.02, 8.479
    { 78, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0x0, 0x80, 0x0 }, // S11 OSM: 17842 48.87, 8.373 x 49.13, 8.518
    { 86, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0x0, 0x80, 0x0 }, // S1 OSM: 17843 48.8, 8.373 x 49.13, 8.458
    { 4, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x18, 0xa6, 0xd9 }, // 5 OSM: 17847 49, 8.347 x 49.02, 8.444
    { 1, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xff, 0xcc, 0x0 }, // 4 OSM: 17848 48.99, 8.347 x 49.05, 8.452
    { 34, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0x6d, 0x68, 0x2a }, // S8 OSM: 17849 48.46, 8.215 x 49.01, 8.435
    { 11, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xff, 0x99, 0x33 }, // 8 OSM: 17855 48.98, 8.452 x 49, 8.479
    { 89, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x10, 0x84, 0x49 }, // M10 OSM: 17865 52.5, 13.36 x 52.54, 13.45
    { 82, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0xcc, 0x0 }, // M13 OSM: 17884 52.51, 13.34 x 52.56, 13.48
    { 94, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x99, 0x66, 0x99 }, // 21 OSM: 17885 52.45, 13.45 x 52.53, 13.52
    { 97, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0x99, 0x99 }, // 63 OSM: 19115 52.43, 13.52 x 52.5, 13.61
    { 100, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x66, 0x99, 0x33 }, // 61 OSM: 19265 52.43, 13.52 x 52.46, 13.69
    { 104, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0x99, 0x33 }, // 68 OSM: 19271 52.37, 13.57 x 52.46, 13.65
    { 107, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0x66, 0x33 }, // 62 OSM: 19296 52.42, 13.57 x 52.51, 13.61
    { 110, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x99, 0x33, 0x33 }, // 37 OSM: 19451 52.45, 13.5 x 52.53, 13.53
    { 90, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xf8, 0xb7, 0x10 }, // 10 OSM: 19925 WD: Q143861 48.75, 9.167 x 48.76, 9.174
    { 90, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x31, 0x27, 0x83 }, // 10 OSM: 19941 53.06, 8.752 x 53.12, 8.9
    { 8, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0x5c, 0xa9 }, // 2 OSM: 19942 53.06, 8.752 x 53.12, 8.9
    { 8, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xf2, 0x87, 0xb6 }, // 2 OSM: 22852 54.08, 12.08 x 54.11, 12.17
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xf8, 0xa5, 0x0 }, // 6 OSM: 22871 54.07, 12.09 x 54.09, 12.14
    { 80, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x5d, 0x10, 0x6a }, // 1 OSM: 23389 54.09, 12.05 x 54.16, 12.16
    { 84, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x69, 0x7, 0x13 }, // 3 OSM: 23742 54.07, 12.09 x 54.11, 12.18
    { 1, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xc3, 0x1, 0x75 }, // 4 OSM: 23743 54.07, 12.1 x 54.11, 12.18
    { 4, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xe2, 0x0, 0x1d }, // 5 OSM: 23747 54.06, 12.05 x 54.16, 12.14
    { 113, NoLogo, NoLogo, LineMetaDataContent::Subway, 0x30, 0x22, 0x76 }, // U70 OSM: 27662 WD: Q661002 51.22, 6.566 x 51.33, 6.796
    { 117, NoLogo, NoLogo, LineMetaDataContent::Subway, 0x30, 0x22, 0x76 }, // U76 OSM: 27663 WD: Q661002 51.22, 6.566 x 51.33, 6.806
    { 121, NoLogo, NoLogo, LineMetaDataContent::Subway, 0x30, 0x22, 0x76 }, // U77 OSM: 27667 WD: Q661002 51.17, 6.735 x 51.24, 6.834
    { 126, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x66, 0x99, 0x33 }, // 60 OSM: 28289 52.44, 13.5 x 52.46, 13.64
    { 129, 42, NoLogo, LineMetaDataContent::RapidTransit, 0x5, 0x5a, 0x99 }, // S3 OSM: 28314 WD: Q7388282 52.43, 13.2 x 52.54, 13.75
    { 132, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0x99, 0x33 }, // 67 OSM: 28352 52.44, 13.51 x 52.46, 13.59
    { 136, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x99, 0x33, 0x33 }, // 27 OSM: 28377 52.44, 13.46 x 52.56, 13.59
    { 139, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x99, 0x0, 0xaa }, // M17 OSM: 28391 52.45, 13.51 x 52.57, 13.53
    { 143, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x36, 0xab, 0x94 }, // 50 OSM: 28420 52.54, 13.34 x 52.61, 13.43
    { 146, NoLogo, NoLogo, LineMetaDataContent::Subway, 0x30, 0x22, 0x76 }, // U79 OSM: 28424 WD: Q661002 51.19, 6.739 x 51.47, 6.815
    { 94, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x32, 0x51, 0xa3 }, // 21 OSM: 29440 WD: Q4415661 51.91, 4.368 x 51.94, 4.525
    { 151, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x32, 0x51, 0xa3 }, // 24 OSM: 29446 WD: Q14500289 51.91, 4.341 x 51.94, 4.525
    { 79, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xd6, 0x26, 0x31 }, // 11 OSM: 33897 51.28, 12.22 x 51.4, 12.4
    { 90, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xd6, 0x26, 0x31 }, // 10 OSM: 33900 51.3, 12.32 x 51.37, 12.4
    { 18, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xe3, 0x0, 0xf }, // 16 OSM: 34068 51.3, 12.38 x 51.4, 12.4
    { 25, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xe, 0x40, 0x94 }, // 7 OSM: 34148 51.34, 12.27 x 51.36, 12.48
    { 104, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xce, 0xa4, 0xcb }, // 68 OSM: 34480 50.7, 6.985 x 50.76, 7.156
    { 86, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0x5c, 0x8e, 0x3c }, // S1 OSM: 35610 48.59, 8.861 x 48.8, 9.444
    { 154, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0xff, 0x2e, 0x1d }, // S2 OSM: 35611 48.68, 9.105 x 48.83, 9.527
    { 129, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0xff, 0x7d, 0x24 }, // S3 OSM: 35612 48.69, 9.105 x 48.94, 9.428
    { 148, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xe6, 0x87, 0x7e }, // 9 OSM: 36132 50.92, 6.907 x 50.94, 7.097
    { 7, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x8c, 0xc6, 0x3f }, // 12 OSM: 36133 50.9, 6.939 x 51.03, 6.96
    { 158, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0xac, 0xcd }, // 15 OSM: 36134 50.92, 6.898 x 51.02, 6.966
    { 148, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xfe, 0xcc, 0x0 }, // 9 OSM: 36930 51.3, 12.37 x 51.38, 12.43
    { 161, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0x87, 0x4a, 0xa }, // S6 OSM: 37419 48.76, 8.872 x 48.83, 9.195
    { 158, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xe, 0x40, 0x94 }, // 15 OSM: 38883 51.29, 12.26 x 51.34, 12.44
    { 164, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xc8, 0xd3, 0x0 }, // 65 OSM: 39079 50.72, 7.071 x 50.76, 7.156
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x90, 0x49, 0xa8 }, // 6 OSM: 48024 52.09, 11.61 x 52.15, 11.68
    { 80, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xb6, 0x0, 0x5c }, // 1 OSM: 48025 52.11, 11.58 x 52.17, 11.64
    { 1, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x73, 0xe7, 0x0 }, // 4 OSM: 48453 52.11, 11.58 x 52.16, 11.67
    { 4, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xb4, 0x86, 0x54 }, // 5 OSM: 48459 52.11, 11.57 x 52.14, 11.67
    { 80, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x62, 0xb3, 0x2c }, // 1 OSM: 51858 51.31, 12.26 x 51.38, 12.42
    { 8, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xf7, 0xc5, 0x3a }, // 2 OSM: 51859 51.29, 12.28 x 51.34, 12.44
    { 167, 56, 70, LineMetaDataContent::Subway, 0x80, 0x70, 0xb7 }, // U6 OSM: 51942 WD: Q99720 52.44, 13.28 x 52.59, 13.39
    { 34, 81, NoLogo, LineMetaDataContent::RapidTransit, 0xff, 0xc7, 0x34 }, // S8 OSM: 53231 WD: Q17148488 48, 11.17 x 48.35, 11.79
    { 170, 107, NoLogo, LineMetaDataContent::RapidTransit, 0xff, 0x2d, 0x1d }, // S4 OSM: 53235 WD: Q7388308 48.04, 11.04 x 48.18, 11.97
    { 148, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x1e, 0x81, 0x64 }, // 9 OSM: 53748 52.08, 11.6 x 52.18, 11.64
    { 8, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0x47, 0x99 }, // 2 OSM: 53752 52.06, 11.63 x 52.15, 11.68
    { 11, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xf2, 0x94, 0x0 }, // 8 OSM: 53770 52.06, 11.63 x 52.18, 11.68
    { 161, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0x3d, 0x2d, 0x7c }, // S6 OSM: 53844 48.75, 8.549 x 48.9, 8.705
    { 90, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xaa, 0xc1, 0xe1 }, // 10 OSM: 54125 52.11, 11.59 x 52.21, 11.67
    { 90, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x9a, 0xcd, 0x32 }, // 10 OSM: 54452 WD: Q318073 51.49, 10.77 x 51.58, 10.8
    { 80, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xda, 0x8, 0x73 }, // 1 OSM: 54602 53.59, 11.41 x 53.65, 11.47
    { 8, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xd9, 0x26, 0x1c }, // 2 OSM: 54603 53.59, 11.36 x 53.65, 11.47
    { 84, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xe8, 0x78, 0x78 }, // 3 OSM: 54604 53.57, 11.38 x 53.6, 11.47
    { 1, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xdb, 0x21, 0x4c }, // 4 OSM: 54605 53.57, 11.38 x 53.65, 11.43
    { 84, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xff, 0xd6, 0x0 }, // 3 OSM: 55097 52.13, 11.57 x 52.16, 11.62
    { 174, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0x40, 0x80, 0x40 }, // S 1 OSM: 55107 WD: Q56378592 52, 11.62 x 53.01, 11.87
    { 178, 123, 70, LineMetaDataContent::Subway, 0xff, 0x73, 0x0 }, // U9 OSM: 58423 WD: Q99744 52.46, 13.32 x 52.56, 13.37
    { 181, 137, 70, LineMetaDataContent::Subway, 0x5, 0x5a, 0x99 }, // U8 OSM: 58424 WD: Q99729 52.47, 13.33 x 52.6, 13.43
    { 184, 151, 70, LineMetaDataContent::Subway, 0xb, 0x9a, 0xda }, // U7 OSM: 58425 WD: Q99725 52.42, 13.2 x 52.54, 13.5
    { 187, 165, 70, LineMetaDataContent::Subway, 0x15, 0xac, 0x99 }, // U3 OSM: 58426 WD: Q99702 52.44, 13.24 x 52.51, 13.45
    { 190, 179, 70, LineMetaDataContent::Subway, 0xff, 0x33, 0x0 }, // U2 OSM: 58428 WD: Q99697 52.5, 13.24 x 52.57, 13.41
    { 193, 193, 70, LineMetaDataContent::Subway, 0xff, 0xcd, 0x0 }, // U4 OSM: 58429 WD: Q99708 52.48, 13.34 x 52.5, 13.36
    { 196, 207, 70, LineMetaDataContent::Subway, 0x7d, 0x53, 0x3d }, // U5 OSM: 58430 WD: Q99711 52.49, 13.41 x 52.54, 13.63
    { 199, 221, 70, LineMetaDataContent::Subway, 0x7d, 0x53, 0x3d }, // U55 OSM: 58431 WD: Q99715 52.52, 13.37 x 52.53, 13.38
    { 203, 236, 70, LineMetaDataContent::Subway, 0x52, 0xb4, 0x47 }, // U1 OSM: 58767 WD: Q99691 52.5, 13.33 x 52.51, 13.45
    { 7, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xe, 0x40, 0x94 }, // 12 OSM: 58815 51.32, 12.37 x 51.38, 12.4
    { 11, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xf7, 0xc5, 0x3a }, // 8 OSM: 58819 51.32, 12.28 x 51.36, 12.47
    { 207, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0xa6, 0xe7 }, // 14 OSM: 58827 51.33, 12.32 x 51.34, 12.38
    { 84, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x62, 0xb3, 0x2c }, // 3 OSM: 58829 51.28, 12.31 x 51.38, 12.49
    { 218, 250, 274, LineMetaDataContent::Subway, 0xcf, 0x0, 0x3d }, // C OSM: 58898 WD: Q168571 50.03, 14.43 x 50.13, 14.53
    { 222, 294, 274, LineMetaDataContent::Subway, 0x0, 0xa5, 0x62 }, // A OSM: 58899 WD: Q1292805 50.07, 14.34 x 50.1, 14.52
    { 226, 318, 274, LineMetaDataContent::Subway, 0xf8, 0xb3, 0x22 }, // B OSM: 58900 WD: Q1460442 50.04, 14.29 x 50.11, 14.58
    { 140, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x86, 0x5a, 0x46 }, // 17 OSM: 61454 48.13, 11.49 x 48.18, 11.64
    { 229, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xed, 0x1c, 0x24 }, // 19 OSM: 61456 48.14, 11.46 x 48.15, 11.63
    { 14, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xc, 0xb1, 0x4b }, // 18 OSM: 61458 48.1, 11.49 x 48.14, 11.6
    { 232, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0x6c, 0xb2 }, // N17 OSM: 61459 48.13, 11.49 x 48.17, 11.61
    { 80, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xf7, 0x8a, 0x21 }, // 1 OSM: 61460 50.85, 12.07 x 50.89, 12.09
    { 154, 342, NoLogo, LineMetaDataContent::RapidTransit, 0x1, 0x8a, 0x47 }, // S2 OSM: 61466 WD: Q3743635 52.34, 13.36 x 52.68, 13.59
    { 236, 356, NoLogo, LineMetaDataContent::RapidTransit, 0x1, 0x8a, 0x47 }, // S25 OSM: 61469 WD: Q7388229 52.4, 13.21 x 52.64, 13.4
    { 187, 371, 70, LineMetaDataContent::Subway, 0xfc, 0xdf, 0x0 }, // U3 OSM: 62839 WD: Q781351 53.54, 9.969 x 53.59, 10.08
    { 86, 386, NoLogo, LineMetaDataContent::RapidTransit, 0x36, 0xca, 0xec }, // S1 OSM: 63809 WD: Q7388207 48.13, 11.48 x 48.4, 11.79
    { 161, 402, NoLogo, LineMetaDataContent::RapidTransit, 0x0, 0xac, 0x6f }, // S6 OSM: 63839 WD: Q7388348 47.91, 11.27 x 48.15, 11.97
    { 84, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xff, 0x7f, 0x0 }, // 3 OSM: 63875 51.82, 12.18 x 51.84, 12.24
    { 240, 418, NoLogo, LineMetaDataContent::RapidTransit, 0xba, 0x8a, 0x4d }, // S46 OSM: 64094 WD: Q3737194 52.3, 13.28 x 52.52, 13.64
    { 244, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0xba, 0x8a, 0x4d }, // S45 OSM: 64095 52.39, 13.36 x 52.48, 13.57
    { 158, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xf5, 0x8f, 0x98 }, // 15 OSM: 66007 48.08, 11.55 x 48.14, 11.6
    { 237, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xf5, 0x8f, 0x98 }, // 25 OSM: 66008 48.04, 11.52 x 48.14, 11.6
    { 7, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x90, 0x3f, 0x98 }, // 12 OSM: 66043 48.15, 11.51 x 48.17, 11.58
    { 18, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0x6c, 0xb2 }, // 16 OSM: 66044 48.13, 11.51 x 48.18, 11.64
    { 136, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xfa, 0xa6, 0x1a }, // 27 OSM: 66053 48.13, 11.56 x 48.18, 11.58
    { 249, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0xbf, 0xe8 }, // 20 OSM: 66079 48.14, 11.51 x 48.18, 11.56
    { 94, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0xbf, 0xe8 }, // 21 OSM: 66080 48.12, 11.53 x 48.17, 11.64
    { 258, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xb2, 0xd2, 0x33 }, // 23 OSM: 66100 48.16, 11.59 x 48.19, 11.59
    { 261, 433, NoLogo, LineMetaDataContent::RapidTransit, 0xe6, 0x73, 0x10 }, // A3 OSM: 66588 WD: Q19606155 53.75, 9.656 x 53.8, 9.983
    { 170, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0x0, 0x65, 0xb7 }, // S4 OSM: 66840 48.77, 9.155 x 48.95, 9.428
    { 264, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xee, 0x66, 0x0 }, // M1 OSM: 67233 52.52, 13.37 x 52.6, 13.41
    { 31, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0x0, 0xb7, 0xe1 }, // S5 OSM: 67283 48.77, 9.122 x 48.95, 9.195
    { 84, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xf5, 0x9e, 0x0 }, // 3 OSM: 69178 47.97, 7.796 x 48, 7.85
    { 80, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xe8, 0x0, 0x1b }, // 1 OSM: 69191 47.98, 7.808 x 48.03, 7.895
    { 4, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0x8b, 0xc5 }, // 5 OSM: 69199 47.99, 7.787 x 48, 7.852
    { 8, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x64, 0x63, 0x63 }, // 2 OSM: 69202 47.96, 7.833 x 48.02, 7.858
    { 80, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xf6, 0xa6, 0xab }, // 1 OSM: 71785 47.25, 11.39 x 47.28, 11.41
    { 84, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xd6, 0x67, 0x75 }, // 3 OSM: 71787 47.26, 11.39 x 47.27, 11.43
    { 80, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xfb, 0xba, 0x0 }, // 1 OSM: 73662 WD: Q61888705 51.43, 11.94 x 51.51, 11.99
    { 8, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xff, 0x99, 0x0 }, // 2 OSM: 73667 WD: Q61889098 51.43, 11.89 x 51.5, 11.99
    { 84, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0x66, 0xcc }, // 3 OSM: 73670 WD: Q61887067 51.43, 11.96 x 51.52, 11.99
    { 1, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x9b, 0x10, 0x6 }, // 4 OSM: 73671 WD: Q61889270 51.44, 11.93 x 51.51, 11.99
    { 4, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xf, 0x3f, 0x93 }, // 5 OSM: 73672 WD: Q61889316 51.29, 11.93 x 51.51, 12.07
    { 25, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xff, 0x66, 0x99 }, // 7 OSM: 73929 WD: Q61889355 51.48, 11.93 x 51.51, 12.04
    { 148, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x99, 0x99, 0x33 }, // 9 OSM: 73932 WD: Q61889418 51.48, 11.89 x 51.48, 11.99
    { 90, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x33, 0x66, 0x33 }, // 10 OSM: 73933 WD: Q61889438 51.48, 11.9 x 51.49, 11.99
    { 86, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0x80, 0x0, 0x0 }, // S1 OSM: 77908 WD: Q7388209 49.44, 10.9 x 49.9, 11.56
    { 154, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0x65, 0xb9, 0x49 }, // S2 OSM: 77962 WD: Q7388248 49.24, 11.04 x 49.45, 11.35
    { 129, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0xf0, 0x5c, 0x3d }, // S3 OSM: 77971 WD: Q7388284 49.27, 11.08 x 49.45, 11.46
    { 84, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xef, 0x1c, 0x29 }, // 3 OSM: 78206 50.84, 12.05 x 50.91, 12.1
    { 84, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x40, 0x98, 0xde }, // 3 OSM: 79325 WD: Q60318542 51.72, 14.3 x 51.76, 14.35
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xa8, 0x1a, 0x30 }, // 6 OSM: 89518 WD: Q1664234 47.23, 11.4 x 47.26, 11.44
    { 218, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0xfc, 0xd9, 0x46 }, // C OSM: 122886 48.43, 1.995 x 49.05, 2.427
    { 135, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xfa, 0xa6, 0x1a }, // N27 OSM: 129569 48.08, 11.55 x 48.18, 11.58
    { 222, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xe2, 0x0, 0x1c }, // A OSM: 146067 48.52, 7.693 x 48.6, 7.754
    { 129, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0x87, 0x44, 0x87 }, // S3 OSM: 152203 WD: Q680235 47.09, 11.39 x 47.28, 11.5
    { 80, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0x96, 0x40 }, // 1 OSM: 153893 53.04, 8.741 x 53.16, 8.965
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0xff, 0x0 }, // 6 OSM: 155951 49, 8.295 x 49.02, 8.44
    { 187, NoLogo, NoLogo, LineMetaDataContent::Subway, 0x93, 0x5f, 0x39 }, // U3 OSM: 162288 48.71, 9.112 x 48.73, 9.202
    { 226, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x12, 0x7b, 0xca }, // B OSM: 163585 48.55, 7.689 x 48.63, 7.769
    { 270, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xa8, 0x5f, 0xaa }, // E OSM: 163591 48.53, 7.733 x 48.61, 7.786
    { 80, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xec, 0x0, 0x8c }, // 1 OSM: 163714 52.48, -2.125 x 52.58, -1.896
    { 80, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0x38, 0x28 }, // 1 OSM: 170076 52.92, -1.263 x 53.04, -1.145
    { 272, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0x42, 0x81, 0x6b }, // 181 (SN) OSM: 172834 51.28, -0.1727 x 51.49, -0.07193
    { 281, 448, NoLogo, LineMetaDataContent::RapidTransit, 0x52, 0xb4, 0x47 }, // S85 OSM: 175267 WD: Q4048677 52.4, 13.4 x 52.57, 13.59
    { 267, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xe, 0x40, 0x94 }, // 4;4E OSM: 207342 51.32, 12.35 x 51.38, 12.43
    { 285, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0x9f, 0x4d }, // R OSM: 224816 WD: Q3239181 50.64, 3.071 x 50.69, 3.179
    { 181, NoLogo, NoLogo, LineMetaDataContent::Subway, 0xc3, 0xb4, 0x7d }, // U8 OSM: 253394 48.71, 9.112 x 48.76, 9.296
    { 287, 463, NoLogo, LineMetaDataContent::RapidTransit, 0x9a, 0x30, 0x52 }, // S9 OSM: 304163 WD: Q4048680 52.39, 13.2 x 52.54, 13.57
    { 129, 477, NoLogo, LineMetaDataContent::RapidTransit, 0x86, 0x29, 0x96 }, // S3 OSM: 364187 WD: Q7388283 47.88, 11.17 x 48.22, 11.7
    { 290, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0x0, 0xff }, // SIR1 OSM: 365296 45.37, 11.87 x 45.44, 11.89
    { 203, NoLogo, NoLogo, LineMetaDataContent::Subway, 0xc7, 0x95, 0x6c }, // U1 OSM: 370946 48.73, 9.111 x 48.81, 9.277
    { 25, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0x80, 0x30 }, // 7 OSM: 382533 WD: Q2590490 51.91, 4.471 x 51.93, 4.526
    { 11, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xdf, 0x60, 0xa4 }, // 8 OSM: 382535 WD: Q3277304 51.9, 4.432 x 51.95, 4.488
    { 237, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x52, 0xb9, 0x47 }, // 25 OSM: 382566 WD: Q2321951 51.84, 4.46 x 51.96, 4.514
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xda, 0xa5, 0x20 }, // 6 OSM: 383846 50.89, 10.56 x 50.9, 10.58
    { 264, NoLogo, 493, LineMetaDataContent::Subway, 0xff, 0xff, 0x0 }, // M1 OSM: 386242 WD: Q3238662 45.03, 7.591 x 45.08, 7.68
    { 295, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0x0, 0xff }, // T1 OSM: 399912 45.69, 9.676 x 45.76, 9.798
    { 298, NoLogo, NoLogo, LineMetaDataContent::Subway, 0xed, 0xa5, 0xb4 }, // U13 OSM: 407256 48.76, 9.134 x 48.81, 9.254
    { 302, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0x6d, 0x78 }, // T2 OSM: 418631 47.22, 5.951 x 47.25, 6.03
    { 184, NoLogo, NoLogo, LineMetaDataContent::Subway, 0xe, 0xb4, 0x8d }, // U7 OSM: 445602 48.71, 9.173 x 48.84, 9.296
    { 86, 523, NoLogo, LineMetaDataContent::RapidTransit, 0xd4, 0x74, 0xae }, // S1 OSM: 454054 WD: Q2579762 52.42, 13.18 x 52.75, 13.4
    { 24, 537, NoLogo, LineMetaDataContent::RapidTransit, 0x20, 0x54, 0x3f }, // S7 OSM: 456933 WD: Q2588691 49.83, 8.488 x 50.11, 8.664
    { 295, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xe4, 0x7, 0x16 }, // T1 OSM: 535990 45.41, 4.364 x 45.48, 4.394
    { 8, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0x68, 0xb3 }, // 2 OSM: 563459 48.32, 10.84 x 48.38, 10.91
    { 11, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xef, 0x7c, 0x0 }, // 8 OSM: 563484 48.33, 10.89 x 48.37, 10.9
    { 125, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0x92, 0x8d, 0x1d }, // S60 OSM: 570588 48.69, 8.922 x 48.83, 9.195
    { 157, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x66, 0x99, 0xcc }, // 215 OSM: 571534 46.95, 6.839 x 46.99, 6.928
    { 306, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0x9f, 0x4d }, // T OSM: 593563 WD: Q3239234 50.64, 3.071 x 50.72, 3.159
    { 196, NoLogo, NoLogo, LineMetaDataContent::Subway, 0x0, 0xba, 0xf2 }, // U5 OSM: 898046 48.7, 9.136 x 48.8, 9.187
    { 167, NoLogo, NoLogo, LineMetaDataContent::Subway, 0xec, 0x0, 0x8c }, // U6 OSM: 898581 48.71, 9.064 x 48.81, 9.187
    { 129, 554, 568, LineMetaDataContent::RapidTransit, 0x94, 0x21, 0x38 }, // S3 OSM: 919367 WD: Q600028 45.47, 9.031 x 45.63, 9.175
    { 190, NoLogo, NoLogo, LineMetaDataContent::Subway, 0xf5, 0x82, 0x20 }, // U2 OSM: 919383 48.77, 9.122 x 48.83, 9.238
    { 86, 590, 568, LineMetaDataContent::RapidTransit, 0xde, 0x3d, 0x30 }, // S1 OSM: 919412 WD: Q46365 45.31, 9.031 x 45.63, 9.498
    { 308, 604, 568, LineMetaDataContent::RapidTransit, 0x78, 0x4f, 0x24 }, // S13 OSM: 919471 WD: Q1160881 45.19, 9.143 x 45.5, 9.245
    { 193, NoLogo, NoLogo, LineMetaDataContent::Subway, 0x7a, 0x68, 0xae }, // U4 OSM: 932204 48.77, 9.158 x 48.79, 9.25
    { 178, NoLogo, NoLogo, LineMetaDataContent::Subway, 0xff, 0xd5, 0x3 }, // U9 OSM: 932277 48.75, 9.138 x 48.79, 9.254
    { 206, NoLogo, NoLogo, LineMetaDataContent::Subway, 0x69, 0xbe, 0x51 }, // U14 OSM: 932386 48.77, 9.168 x 48.84, 9.23
    { 312, NoLogo, NoLogo, LineMetaDataContent::Subway, 0xcc, 0xcc, 0xcc }, // U11 OSM: 932425 48.77, 9.168 x 48.8, 9.226
    { 228, NoLogo, NoLogo, LineMetaDataContent::Subway, 0xcc, 0xcc, 0xcc }, // U19 OSM: 932433 48.79, 9.213 x 48.83, 9.238
    { 170, 619, 568, LineMetaDataContent::RapidTransit, 0x59, 0xb5, 0x30 }, // S4 OSM: 936755 WD: Q1160571 45.47, 9.134 x 45.67, 9.176
    { 154, 633, 568, LineMetaDataContent::RapidTransit, 0x0, 0x94, 0x78 }, // S2 OSM: 936757 WD: Q1160540 45.43, 9.14 x 45.65, 9.239
    { 11, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x95, 0xc1, 0x1f }, // 8 OSM: 963052 53.05, 8.741 x 53.1, 8.841
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xff, 0xcc, 0x0 }, // 6 OSM: 963103 53.05, 8.783 x 53.11, 8.859
    { 1, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xe3, 0x6, 0x13 }, // 4 OSM: 964983 53.03, 8.799 x 53.16, 8.945
    { 84, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0x9f, 0xe3 }, // 3 OSM: 966312 53.06, 8.752 x 53.12, 8.868
    { 316, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0x75, 0xbf }, // N10 OSM: 1070763 53.06, 8.752 x 53.12, 8.9
    { 320, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xe3, 0x6, 0x13 }, // N4 OSM: 1070810 53.03, 8.799 x 53.16, 8.945
    { 323, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0x96, 0x40 }, // N1 OSM: 1070812 53.04, 8.741 x 53.09, 8.965
    { 170, 647, NoLogo, LineMetaDataContent::RapidTransit, 0x0, 0x0, 0x0 }, // S4 OSM: 1136740 WD: Q2204422 47.08, 9.816 x 47.15, 9.918
    { 326, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xe4, 0x1f, 0x25 }, // N82 OSM: 1147592 48.24, 14.28 x 48.33, 14.36
    { 143, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xe4, 0x1f, 0x25 }, // 50 OSM: 1149422 48.31, 14.26 x 48.32, 14.29
    { 8, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xe4, 0x1f, 0x25 }, // 2 OSM: 1149423 48.24, 14.28 x 48.33, 14.36
    { 84, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xe4, 0x1f, 0x25 }, // 3 OSM: 1149424 48.23, 14.23 x 48.31, 14.29
    { 80, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xe4, 0x1f, 0x25 }, // 1 OSM: 1149425 48.25, 14.28 x 48.33, 14.32
    { 190, 667, 70, LineMetaDataContent::Subway, 0x0, 0xa5, 0x4f }, // U2 OSM: 1150977 WD: Q3040891 50.1, 8.64 x 50.22, 8.687
    { 6, NoLogo, NoLogo, LineMetaDataContent::Subway, 0x93, 0xbb, 0xe9 }, // U12 OSM: 1214006 48.72, 9.118 x 48.87, 9.271
    { 330, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x95, 0xaa, 0x53 }, // 308 OSM: 1228606 51.4, 7.16 x 51.52, 7.284
    { 334, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xb1, 0x4e, 0x7a }, // 310 OSM: 1228607 51.44, 7.152 x 51.48, 7.337
    { 338, NoLogo, NoLogo, LineMetaDataContent::Subway, 0x29, 0x44, 0x88 }, // U35 OSM: 1228608 WD: Q2466100 51.45, 7.21 x 51.55, 7.273
    { 13, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x72, 0xa7, 0xa0 }, // 318 OSM: 1228609 51.42, 7.143 x 51.52, 7.284
    { 342, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xea, 0x50, 0x4c }, // 306 OSM: 1228610 51.48, 7.16 x 51.53, 7.223
    { 346, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x6b, 0xa5, 0xd9 }, // 302 OSM: 1228611 51.46, 7.056 x 51.58, 7.324
    { 350, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0xb2, 0xf6 }, // 301 OSM: 1236118 51.5, 7.019 x 51.58, 7.11
    { 354, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0xf4, 0x7a, 0x14 }, // S 5 OSM: 1241173 49.14, 8.674 x 49.42, 9.102
    { 11, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xcc, 0x99, 0x0 }, // 8 OSM: 1374424 WD: Q61887882 51.45, 11.95 x 51.52, 11.99
    { 7, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x99, 0xcc, 0x0 }, // 12 OSM: 1375884 WD: Q61888162 51.48, 11.96 x 51.52, 11.99
    { 84, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xe5, 0x0, 0x5a }, // 3 OSM: 1469415 51.02, 13.7 x 51.1, 13.75
    { 358, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xe6, 0xf2, 0xfc }, // 98 OSM: 1490387 52.36, 13.03 x 52.4, 13.1
    { 361, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xff, 0x0, 0x0 }, // 91 OSM: 1492311 52.36, 13.01 x 52.4, 13.1
    { 364, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x19, 0x48, 0x8e }, // 92 OSM: 1505928 52.36, 13.03 x 52.42, 13.14
    { 367, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xfe, 0x98, 0x0 }, // 93 OSM: 1509473 52.36, 13.06 x 52.41, 13.1
    { 370, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xfe, 0x98, 0x0 }, // 94 OSM: 1512265 52.37, 13.01 x 52.4, 13.11
    { 373, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0x80, 0x3c, 0x9f }, // S33 OSM: 1513484 49.12, 8.364 x 49.24, 8.594
    { 377, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xed, 0x1c, 0x24 }, // N19 OSM: 1536166 48.12, 11.46 x 48.15, 11.64
    { 129, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0x0, 0x97, 0xd8 }, // S3 OSM: 1549250 WD: Q7388286 47.32, 8.501 x 47.53, 8.806
    { 381, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0xf6, 0xc4, 0x54 }, // S10 OSM: 1561016 WD: Q687279 47.35, 8.465 x 47.38, 8.54
    { 150, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0x94, 0x66, 0x44 }, // S24 OSM: 1574036 WD: Q7388228 47.17, 8.516 x 47.75, 9.106
    { 385, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xfe, 0x98, 0x0 }, // 96 OSM: 1585204 52.36, 13.05 x 52.43, 13.14
    { 388, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x59, 0xc1, 0x33 }, // 99 OSM: 1585259 52.39, 13.06 x 52.4, 13.11
    { 161, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0x77, 0x51, 0xa1 }, // S6 OSM: 1609735 WD: Q7388350 47.26, 8.305 x 47.48, 8.683
    { 391, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0xd8, 0x24, 0x2b }, // S12 OSM: 1614502 WD: Q7388182 47.37, 8.208 x 47.7, 9.042
    { 17, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0x64, 0xb9, 0x7a }, // S16 OSM: 1618466 WD: Q7388193 47.28, 8.511 x 47.45, 8.615
    { 373, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0x2d, 0xa7, 0xdf }, // S33 OSM: 1619213 WD: Q7388269 47.5, 8.611 x 47.7, 8.726
    { 287, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0x0, 0xa3, 0x4f }, // S9 OSM: 1620987 WD: Q7388394 47.35, 8.501 x 47.7, 8.721
    { 8, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xc3, 0x2b, 0x3c }, // 2 OSM: 1624727 WD: Q60282113 51.75, 14.31 x 51.76, 14.35
    { 1, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x23, 0x95, 0x37 }, // 4 OSM: 1628047 WD: Q60328960 51.72, 14.32 x 51.79, 14.35
    { 302, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xbb, 0x4a, 0x9b }, // T2 OSM: 1635139 WD: Q369969 48.82, 2.217 x 48.92, 2.288
    { 80, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xec, 0xe1, 0x16 }, // 1 OSM: 1637446 WD: Q60213236 51.75, 14.33 x 51.78, 14.34
    { 14, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x54, 0xad, 0x4b }, // 18 OSM: 1646141 50.73, 6.893 x 50.98, 7.097
    { 395, 684, 705, LineMetaDataContent::RapidTransit, 0x5e, 0x96, 0x20 }, // D OSM: 1673421 WD: Q1425351 48.29, 2.344 x 49.27, 2.657
    { 190, 713, 70, LineMetaDataContent::Subway, 0xff, 0x0, 0x0 }, // U2 OSM: 1676043 WD: Q3433227 49.42, 11.03 x 49.49, 11.11
    { 80, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xdc, 0x0, 0x8f }, // 1 OSM: 1679960 50.09, 14.34 x 50.11, 14.5
    { 190, 730, 70, LineMetaDataContent::Subway, 0xee, 0x1d, 0x23 }, // U2 OSM: 1686090 WD: Q275451 53.53, 9.943 x 53.64, 10.15
    { 203, 745, 70, LineMetaDataContent::Subway, 0x0, 0x66, 0xb3 }, // U1 OSM: 1687370 WD: Q248623 53.55, 9.985 x 53.71, 10.29
    { 302, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x96, 0xbf, 0xd }, // T2 OSM: 1824544 47.29, 5.006 x 47.37, 5.059
    { 295, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xcc, 0x0, 0x88 }, // T1 OSM: 1824550 47.31, 5.028 x 47.33, 5.112
    { 187, 760, 70, LineMetaDataContent::Subway, 0x0, 0x86, 0x8b }, // U3 OSM: 1857497 WD: Q3433219 49.44, 11.04 x 49.47, 11.09
    { 203, 777, 70, LineMetaDataContent::Subway, 0x0, 0x0, 0x66 }, // U1 OSM: 1857639 WD: Q3433210 49.4, 10.96 x 49.48, 11.14
    { 161, 794, NoLogo, LineMetaDataContent::RapidTransit, 0xf5, 0x79, 0x21 }, // S6 OSM: 1880910 WD: Q3238987 50.1, 8.633 x 50.34, 8.789
    { 140, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x8d, 0x1d, 0x2c }, // 17 OSM: 1903836 47.35, 8.482 x 47.4, 8.542
    { 1, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x9b, 0xd6, 0xf9 }, // 4 OSM: 1904829 50.03, 14.37 x 50.08, 14.46
    { 8, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0x38, 0x28 }, // 2 OSM: 1984359 52.9, -1.207 x 52.99, -1.145
    { 397, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x33, 0xff, 0x33 }, // M2 OSM: 2001598 52.52, 13.41 x 52.57, 13.44
    { 400, NoLogo, NoLogo, LineMetaDataContent::Subway, 0x30, 0x22, 0x76 }, // U75 OSM: 2003447 WD: Q661002 51.2, 6.684 x 51.23, 6.847
    { 404, NoLogo, NoLogo, LineMetaDataContent::Subway, 0x30, 0x22, 0x76 }, // U78 OSM: 2003448 WD: Q661002 51.22, 6.733 x 51.27, 6.795
    { 83, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x96, 0x7b, 0x68 }, // 13 OSM: 2003476 50.91, 6.908 x 50.97, 7.038
    { 4, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x94, 0x8f, 0xb8 }, // 5 OSM: 2003477 50.93, 6.888 x 50.98, 6.96
    { 4, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xff, 0xf5, 0x0 }, // 5 OSM: 2024979 50.03, 14.37 x 50.09, 14.53
    { 84, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xe6, 0x93, 0xb5 }, // 3 OSM: 2026288 50.93, 6.87 x 50.98, 7.086
    { 100, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x98, 0xc0, 0x0 }, // 61 OSM: 2026289 50.7, 7.071 x 50.76, 7.112
    { 107, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x61, 0xaf, 0x20 }, // 62 OSM: 2026290 50.7, 7.095 x 50.74, 7.176
    { 97, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x60, 0xd6, 0xf7 }, // 63 OSM: 2026291 50.68, 7.047 x 50.75, 7.159
    { 132, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xee, 0x99, 0xbf }, // 67 OSM: 2026293 50.68, 7.092 x 50.79, 7.203
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xf7, 0xd0, 0x9b }, // 6 OSM: 2032473 50.07, 14.42 x 50.11, 14.48
    { 408, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xb1, 0xc8, 0x0 }, // F OSM: 2060446 48.57, 7.724 x 48.59, 7.777
    { 25, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0xff, 0xff }, // 7 OSM: 2061854 50.06, 14.39 x 50.08, 14.51
    { 80, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0x9c, 0xdd }, // 1 OSM: 2067963 53.41, 14.49 x 53.47, 14.56
    { 84, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0x9c, 0xdd }, // 3 OSM: 2073969 53.4, 14.52 x 53.46, 14.55
    { 7, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0x9c, 0xdd }, // 12 OSM: 2074000 53.4, 14.53 x 53.45, 14.55
    { 295, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xe3, 0x0, 0x2b }, // T1 OSM: 2074462 48.65, 6.145 x 48.7, 6.225
    { 4, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0x9c, 0xdd }, // 5 OSM: 2077222 53.43, 14.49 x 53.45, 14.58
    { 79, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0x9c, 0xdd }, // 11 OSM: 2077355 53.4, 14.53 x 53.45, 14.58
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0x9c, 0xdd }, // 6 OSM: 2077516 53.4, 14.53 x 53.48, 14.61
    { 11, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0x9c, 0xdd }, // 8 OSM: 2080359 53.38, 14.49 x 53.43, 14.64
    { 25, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0x9c, 0xdd }, // 7 OSM: 2080360 53.38, 14.49 x 53.45, 14.64
    { 84, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xef, 0x7c, 0x0 }, // 3 OSM: 2083643 48.31, 10.84 x 48.37, 10.9
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x94, 0xc1, 0x1c }, // 6 OSM: 2083654 48.35, 10.89 x 48.37, 10.96
    { 248, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0xbf, 0xe8 }, // N20 OSM: 2101204 48.14, 11.51 x 48.18, 11.56
    { 410, 811, NoLogo, LineMetaDataContent::RapidTransit, 0xe7, 0x52, 0x6b }, // S20 OSM: 2113865 WD: Q7388223 48.04, 11.46 x 48.15, 11.54
    { 24, 828, NoLogo, LineMetaDataContent::RapidTransit, 0x98, 0x32, 0x24 }, // S7 OSM: 2113867 WD: Q7388364 47.91, 11.42 x 48.14, 11.78
    { 80, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0xa6, 0x51 }, // 1 OSM: 2116454 47.2, -1.639 x 47.26, -1.515
    { 8, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xee, 0x1c, 0x25 }, // 2 OSM: 2166523 47.19, -1.593 x 47.26, -1.542
    { 84, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0x6d, 0xb1 }, // 3 OSM: 2166524 47.18, -1.617 x 47.25, -1.542
    { 170, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0x0, 0x0, 0x80 }, // S4 OSM: 2199152 WD: Q7388307 49.25, 10.3 x 49.44, 11.08
    { 8, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0x66, 0x99 }, // 2 OSM: 2203208 48.98, 8.347 x 49.03, 8.479
    { 11, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0x98, 0xd4 }, // 8 OSM: 2262665 50.8, 4.353 x 50.85, 4.44
    { 414, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x66, 0x99, 0x33 }, // 87 OSM: 2282096 WD: Q428288 52.44, 13.69 x 52.46, 13.76
    { 222, 844, 705, LineMetaDataContent::RapidTransit, 0xd1, 0x30, 0x2f }, // A OSM: 2333448 WD: Q741818 48.75, 2.009 x 49.05, 2.783
    { 1, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xd7, 0x51, 0x28 }, // 4 OSM: 2368452 50.72, 12.43 x 50.75, 12.49
    { 90, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0x9c, 0xdd }, // 10 OSM: 2372195 53.42, 14.49 x 53.46, 14.55
    { 417, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0xf8, 0xa2, 0xd }, // S51 OSM: 2412316 49.3, 8.674 x 49.42, 8.991
    { 421, 865, NoLogo, LineMetaDataContent::RapidTransit, 0xba, 0x8a, 0x4d }, // S47 OSM: 2413847 WD: Q3742025 52.45, 13.43 x 52.47, 13.56
    { 252, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0x61, 0xaf, 0x20 }, // S23;RB23 OSM: 2441590 WD: Q1699351 50.56, 6.761 x 50.74, 7.098
    { 86, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0xb, 0x9a, 0x33 }, // S1 OSM: 2444997 WD: Q7388210 51.16, 6.772 x 51.52, 7.46
    { 78, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0xef, 0x7c, 0x0 }, // S11 OSM: 2445000 WD: Q7388174 50.94, 6.674 x 51.28, 7.125
    { 391, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0x61, 0xaf, 0x20 }, // S12 OSM: 2445001 WD: Q7388180 50.76, 6.713 x 50.95, 7.66
    { 308, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0x0, 0xa6, 0xeb }, // S13 OSM: 2445007 WD: Q7388184 50.81, 6.482 x 50.95, 7.151
    { 425, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0x71, 0x76, 0x76 }, // S28 OSM: 2445009 WD: Q7388234 51.2, 6.594 x 51.25, 6.988
    { 129, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0x99, 0x99, 0x99 }, // S3 OSM: 2445010 WD: Q7388285 51.4, 6.835 x 51.48, 7.181
    { 170, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0xef, 0x7c, 0x0 }, // S4 OSM: 2445011 WD: Q7388319 51.5, 7.334 x 51.55, 7.698
    { 31, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0x98, 0xc6, 0xf }, // S5 OSM: 2445012 WD: Q7388333 51.36, 7.325 x 51.52, 7.46
    { 161, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0xdc, 0x5, 0x2d }, // S6 OSM: 2445013 WD: Q7388349 50.94, 6.79 x 51.45, 7.023
    { 103, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0x14, 0xba, 0xe6 }, // S68 OSM: 2445014 WD: Q7388346 51.1, 6.79 x 51.23, 7.074
    { 34, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0xb0, 0x33, 0x3 }, // S8 OSM: 2445015 WD: Q7388383 51.19, 6.445 x 51.36, 7.46
    { 287, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0xc7, 0x0, 0x7f }, // S9 OSM: 2445016 WD: Q7388395 51.23, 6.921 x 51.74, 7.186
    { 86, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0xec, 0x19, 0x2e }, // S1 OSM: 2445551 49.33, 7.334 x 49.48, 9.424
    { 154, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0x29, 0x60, 0xb5 }, // S2 OSM: 2445552 49.34, 7.767 x 49.48, 9.144
    { 129, 880, NoLogo, LineMetaDataContent::RapidTransit, 0x0, 0xa8, 0x96 }, // S3 OSM: 2445553 WD: Q2781002 49.87, 8.504 x 50.16, 8.699
    { 129, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0xfc, 0xd8, 0x4 }, // S3 OSM: 2445554 48.99, 8.349 x 49.48, 8.685
    { 170, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0x1a, 0x9d, 0x47 }, // S4 OSM: 2445555 48.99, 8.349 x 49.48, 9.528
    { 129, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0xdb, 0x6e, 0xab }, // S3 OSM: 2474189 52.16, 9.739 x 52.38, 10.02
    { 31, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0xf7, 0x8a, 0x18 }, // S5 OSM: 2474199 51.71, 8.737 x 52.46, 9.773
    { 31, 897, NoLogo, LineMetaDataContent::RapidTransit, 0xa5, 0x2a, 0x2a }, // S5 OSM: 2515355 WD: Q2515085 50.1, 8.583 x 50.25, 8.699
    { 170, 914, NoLogo, LineMetaDataContent::RapidTransit, 0xfe, 0xcb, 0x9 }, // S4 OSM: 2515408 WD: Q2204443 49.99, 8.516 x 50.18, 8.699
    { 24, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0x14, 0xba, 0xe6 }, // S7 OSM: 2544304 WD: Q1195962 51.16, 7.004 x 51.28, 7.253
    { 429, 931, 952, LineMetaDataContent::Subway, 0x79, 0xbb, 0x92 }, // 7bis OSM: 2554103 WD: Q50749 48.88, 2.366 x 48.88, 2.401
    { 161, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0x0, 0x5a, 0xab }, // S6 OSM: 2557420 52.37, 9.739 x 52.62, 10.06
    { 170, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0x97, 0x2f, 0x50 }, // S4 OSM: 2567719 52.16, 9.687 x 52.58, 9.956
    { 295, 964, 991, LineMetaDataContent::Tramway, 0x21, 0x6e, 0xb4 }, // T1 OSM: 2572573 WD: Q369969 48.9, 2.274 x 48.94, 2.47
    { 161, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0xec, 0x19, 0x2e }, // S6 OSM: 2587144 49.44, 8.256 x 50, 8.582
    { 354, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0xf1, 0x7f, 0x1a }, // S 5 OSM: 2606971 50.7, 11.99 x 51.48, 12.48
    { 435, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0x0, 0xa6, 0x50 }, // S 4 OSM: 2607472 51.25, 12.37 x 51.59, 14.23
    { 86, NoLogo, 1015, LineMetaDataContent::RapidTransit, 0x66, 0xcd, 0xaa }, // S1 OSM: 2609006 WD: Q50331474 54.08, 12.06 x 54.17, 12.13
    { 129, NoLogo, 1015, LineMetaDataContent::RapidTransit, 0x0, 0x0, 0x0 }, // S3 OSM: 2609009 WD: Q50331483 53.79, 12.13 x 54.08, 12.35
    { 154, NoLogo, 1015, LineMetaDataContent::RapidTransit, 0x94, 0x0, 0xd3 }, // S2 OSM: 2609011 WD: Q50331479 53.8, 12.06 x 54.17, 12.17
    { 94, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xe2, 0x0, 0xa }, // 21 OSM: 2617691 49.4, 8.675 x 49.43, 8.693
    { 439, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xfc, 0xc2, 0x0 }, // 22 OSM: 2617692 49.4, 8.627 x 49.41, 8.693
    { 258, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xe4, 0x8e, 0x0 }, // 23 OSM: 2617693 49.34, 8.681 x 49.44, 8.693
    { 151, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x8b, 0x1c, 0x75 }, // 24 OSM: 2617694 49.36, 8.66 x 49.47, 8.691
    { 443, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xf3, 0x9a, 0x9a }, // 26 OSM: 2617695 49.38, 8.658 x 49.41, 8.693
    { 148, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x93, 0xc1, 0x3b }, // 9 OSM: 2621592 49.48, 8.467 x 49.48, 8.525
    { 446, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0x45, 0x95 }, // M OSM: 2629655 49.39, 1.042 x 49.45, 1.106
    { 148, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xf1, 0x71, 0xab }, // 9 OSM: 2629996 46.93, 7.436 x 46.97, 7.468
    { 449, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0xbf, 0xe8 }, // 29 OSM: 2635531 48.14, 11.49 x 48.16, 11.56
    { 452, 1031, NoLogo, LineMetaDataContent::Tramway, 0x87, 0x3f, 0x98 }, // T5 OSM: 2643507 WD: Q3238967 45.73, 4.88 x 45.74, 4.948
    { 25, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x9e, 0x2, 0x34 }, // 7 OSM: 2675693 51.04, 13.63 x 51.14, 13.8
    { 154, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0x11, 0x83, 0x49 }, // S2 OSM: 2682237 52.28, 9.217 x 52.65, 9.773
    { 7, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0x6b, 0x42 }, // 12 OSM: 2690192 51.04, 13.67 x 51.06, 13.81
    { 90, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xdc, 0x0, 0x8f }, // 10 OSM: 2728288 50.06, 14.3 x 50.13, 14.48
    { 7, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xdc, 0x0, 0x8f }, // 12 OSM: 2729904 50.03, 14.37 x 50.11, 14.45
    { 3, 1051, 493, LineMetaDataContent::Subway, 0x79, 0x56, 0xa3 }, // M5 OSM: 2753306 WD: Q3238963 45.48, 9.117 x 45.53, 9.212
    { 80, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xe3, 0x0, 0xb }, // 1 OSM: 2777016 52.2, 10.51 x 52.33, 10.54
    { 455, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0x1, 0x5c, 0xa3 }, // S 7 OSM: 2791180 51.45, 11.91 x 51.49, 12
    { 460, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0xd7, 0x17, 0x1f }, // S 3 OSM: 2793231 51.31, 11.96 x 51.52, 13.11
    { 464, NoLogo, NoLogo, LineMetaDataContent::Subway, 0x3, 0xf, 0x3f }, // Metropolitana OSM: 2797904 WD: Q1725884 45.51, 10.21 x 45.58, 10.28
    { 90, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xce, 0x1f, 0x75 }, // 10 OSM: 2799185 47.35, 8.507 x 47.45, 8.573
    { 7, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x92, 0xd6, 0xe3 }, // 12 OSM: 2799201 47.4, 8.556 x 47.45, 8.608
    { 478, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x93, 0xad, 0x0 }, // M3 OSM: 2804168 WD: Q2637212 50.41, 4.43 x 50.48, 4.452
    { 4, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x70, 0x49, 0x2c }, // 5 OSM: 2807017 47.36, 8.516 x 47.38, 8.572
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xbe, 0x85, 0x43 }, // 6 OSM: 2807025 47.36, 8.482 x 47.4, 8.572
    { 25, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0x0, 0x0 }, // 7 OSM: 2807030 47.34, 8.53 x 47.41, 8.597
    { 148, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x32, 0x2e, 0x71 }, // 9 OSM: 2807033 47.37, 8.495 x 47.41, 8.592
    { 207, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0x93, 0xd0 }, // 14 OSM: 2807051 47.37, 8.495 x 47.42, 8.55
    { 79, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0x92, 0x3c }, // 11 OSM: 2807068 47.35, 8.533 x 47.42, 8.583
    { 84, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0x92, 0x3c }, // 3 OSM: 2807070 47.36, 8.485 x 47.38, 8.567
    { 1, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x32, 0x2e, 0x71 }, // 4 OSM: 2807089 47.35, 8.49 x 47.39, 8.561
    { 8, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xcb, 0xa, 0x25 }, // 2 OSM: 2807095 47.35, 8.444 x 47.4, 8.561
    { 158, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xcb, 0xa, 0x25 }, // 15 OSM: 2807117 47.37, 8.533 x 47.4, 8.548
    { 11, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x8b, 0xc0, 0x36 }, // 8 OSM: 2807118 47.36, 8.504 x 47.39, 8.567
    { 4, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xf3, 0x91, 0x0 }, // 5 OSM: 2810470 52.23, 10.48 x 52.26, 10.54
    { 18, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xa9, 0xc1, 0xd1 }, // 16 OSM: 2820891 50.06, 14.3 x 50.11, 14.55
    { 84, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0x65, 0x31 }, // 3 OSM: 2837394 52.24, 10.47 x 52.29, 10.58
    { 481, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0x0, 0x90, 0x7a }, // S31 OSM: 2872363 48.44, 8.215 x 49.18, 8.785
    { 485, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0x0, 0x90, 0x7a }, // S32 OSM: 2872364 48.99, 8.402 x 49.16, 8.775
    { 417, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0xf4, 0x96, 0x94 }, // S51 OSM: 2872365 48.89, 8.262 x 49.23, 8.703
    { 489, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0xf4, 0x96, 0x94 }, // S52 OSM: 2872366 48.98, 8.262 x 49.23, 8.433
    { 193, 1071, 70, LineMetaDataContent::Subway, 0x2e, 0xc6, 0xff }, // U4 OSM: 2872790 WD: Q209739 53.53, 9.983 x 53.56, 10.11
    { 174, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0xff, 0xff, 0x0 }, // S 1 OSM: 2920398 51.31, 12.27 x 51.37, 12.41
    { 1, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xf9, 0xb0, 0x0 }, // 4 OSM: 2951397 52.37, 9.596 x 52.42, 9.819
    { 370, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x6f, 0x1b, 0x14 }, // 94 OSM: 2982672 51.48, 11.93 x 51.51, 11.97
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xf9, 0xb0, 0x0 }, // 6 OSM: 2991603 52.32, 9.69 x 52.42, 9.837
    { 79, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xf9, 0xb0, 0x0 }, // 11 OSM: 2991649 52.36, 9.713 x 52.39, 9.775
    { 4, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xf9, 0xb0, 0x0 }, // 5 OSM: 2991701 52.36, 9.659 x 52.41, 9.859
    { 80, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xe4, 0x0, 0x3a }, // 1 OSM: 2995652 52.24, 9.731 x 52.44, 9.86
    { 8, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xe4, 0x0, 0x3a }, // 2 OSM: 2998555 52.29, 9.734 x 52.42, 9.818
    { 11, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xe4, 0x0, 0x3a }, // 8 OSM: 2998722 52.33, 9.734 x 52.39, 9.805
    { 140, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x76, 0xb8, 0x2a }, // 17 OSM: 2998733 52.34, 9.718 x 52.38, 9.743
    { 90, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x76, 0xb8, 0x2a }, // 10 OSM: 3004809 52.37, 9.664 x 52.38, 9.744
    { 493, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x5, 0x15, 0x41 }, // 95 OSM: 3006197 51.42, 11.96 x 51.52, 11.99
    { 7, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xed, 0x19, 0x43 }, // 12 OSM: 3009639 WD: Q2189640 51.88, 4.471 x 51.92, 4.568
    { 84, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0x69, 0xb4 }, // 3 OSM: 3016071 52.33, 9.69 x 52.44, 9.848
    { 25, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0x69, 0xb4 }, // 7 OSM: 3038575 52.33, 9.69 x 52.41, 9.854
    { 148, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0x69, 0xb4 }, // 9 OSM: 3038600 52.34, 9.667 x 52.43, 9.802
    { 1, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0x80, 0x0 }, // 4 OSM: 3061160 50.49, 12.13 x 50.51, 12.18
    { 497, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0x0, 0xff, 0xff }, // S 2 OSM: 3119892 51.31, 12.23 x 51.87, 12.66
    { 11, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xaf, 0xe0, 0xee }, // 8 OSM: 3144745 46.94, 7.374 x 46.95, 7.487
    { 8, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x8, 0x87, 0x42 }, // 2 OSM: 3152801 51.13, 14.94 x 51.17, 14.99
    { 80, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xff, 0x2e, 0x17 }, // 1 OSM: 3152809 51.12, 14.97 x 51.17, 14.99
    { 24, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0xa5, 0xce, 0x43 }, // S7 OSM: 3168072 52.37, 9.739 x 52.62, 10.06
    { 222, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xca, 0x30, 0x5b }, // A OSM: 3190626 47.34, 0.6578 x 47.42, 0.7119
    { 397, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x48, 0x92, 0x24 }, // M2 OSM: 3287304 WD: Q2094433 50.4, 4.271 x 50.42, 4.452
    { 222, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xef, 0x3f, 0x30 }, // A OSM: 3309751 47.44, -0.5972 x 47.51, -0.549
    { 1, 1086, 952, LineMetaDataContent::Subway, 0xbb, 0x4d, 0x98 }, // 4 OSM: 3326845 WD: Q50743 48.82, 2.318 x 48.9, 2.359
    { 207, 1104, 952, LineMetaDataContent::Subway, 0x67, 0x32, 0x8e }, // 14 OSM: 3328694 WD: Q50761 48.83, 2.323 x 48.88, 2.387
    { 80, 1123, 952, LineMetaDataContent::Subway, 0xf2, 0xc9, 0x31 }, // 1 OSM: 3328695 WD: Q13224 48.84, 2.23 x 48.89, 2.441
    { 148, 1141, 952, LineMetaDataContent::Subway, 0xcd, 0xc8, 0x3f }, // 9 OSM: 3328717 WD: Q50753 48.83, 2.231 x 48.87, 2.442
    { 193, 1159, 70, LineMetaDataContent::Subway, 0x10, 0xb4, 0x8d }, // U4 OSM: 3328726 WD: Q20439761 48.13, 11.52 x 48.15, 11.62
    { 90, 1175, 952, LineMetaDataContent::Subway, 0xdf, 0xb0, 0x39 }, // 10 OSM: 3328741 WD: Q50754 48.84, 2.229 x 48.85, 2.365
    { 19, 1194, 952, LineMetaDataContent::Subway, 0x75, 0xc6, 0x95 }, // 6 OSM: 3328765 WD: Q50746 48.83, 2.285 x 48.87, 2.402
    { 25, 1212, 952, LineMetaDataContent::Subway, 0xfa, 0x9a, 0xba }, // 7 OSM: 3328805 WD: Q50748 48.79, 2.332 x 48.92, 2.411
    { 91, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xbb, 0x0, 0x22 }, // 0 OSM: 3348003 WD: Q1510414 51.08, 2.581 x 51.34, 3.285
    { 80, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xe3, 0x0, 0xf }, // 1 OSM: 3367545 48.34, 10.87 x 48.38, 10.94
    { 1, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x95, 0x18, 0x81 }, // 4 OSM: 3367554 48.37, 10.88 x 48.4, 10.89
    { 501, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0x0, 0x97, 0xba }, // S42 OSM: 3368507 49.14, 8.875 x 49.25, 9.229
    { 496, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0xff, 0x9e, 0x0 }, // RS 2 OSM: 3372285 52.79, 8.597 x 53.57, 8.895
    { 173, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0x0, 0x0, 0xee }, // RS 1 OSM: 3372313 52.92, 8.516 x 53.21, 9.238
    { 505, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xe3, 0xba, 0x12 }, // 44 OSM: 3394367 50.82, 4.409 x 50.84, 4.514
    { 508, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xde, 0x3b, 0x21 }, // 39 OSM: 3394368 50.83, 4.409 x 50.85, 4.503
    { 86, 1230, NoLogo, LineMetaDataContent::RapidTransit, 0x0, 0x95, 0xda }, // S1 OSM: 3413905 WD: Q600891 49.97, 8.244 x 50.11, 8.885
    { 154, 1247, NoLogo, LineMetaDataContent::RapidTransit, 0xee, 0x1c, 0x23 }, // S2 OSM: 3414422 WD: Q1985592 50.01, 8.31 x 50.16, 8.813
    { 34, 1264, NoLogo, LineMetaDataContent::RapidTransit, 0xd7, 0xdf, 0x23 }, // S8 OSM: 3415070 WD: Q2005458 49.98, 8.242 x 50.13, 8.931
    { 287, 1281, NoLogo, LineMetaDataContent::RapidTransit, 0x91, 0x26, 0x8f }, // S9 OSM: 3415113 WD: Q508402 49.98, 8.244 x 50.13, 8.931
    { 7, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xbb, 0x0, 0x22 }, // 12 OSM: 3419132 WD: Q2200976 51.22, 4.42 x 51.23, 4.444
    { 148, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xee, 0x88, 0x22 }, // 9 OSM: 3419133 51.2, 4.361 x 51.22, 4.464
    { 151, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xff, 0x88, 0xaa }, // 24 OSM: 3419134 51.2, 4.408 x 51.24, 4.484
    { 84, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xff, 0xcc, 0x11 }, // 3 OSM: 3419435 51.22, 4.305 x 51.26, 4.464
    { 1, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x11, 0x99, 0xdd }, // 4 OSM: 3419473 51.17, 4.35 x 51.22, 4.484
    { 4, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x77, 0x11, 0x33 }, // 5 OSM: 3419525 51.22, 4.361 x 51.23, 4.512
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xdd, 0x0, 0x77 }, // 6 OSM: 3419912 51.18, 4.391 x 51.26, 4.443
    { 25, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0x44, 0xbb }, // 7 OSM: 3420306 51.17, 4.4 x 51.23, 4.449
    { 90, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xbb, 0xdd, 0x0 }, // 10 OSM: 3420544 51.17, 4.362 x 51.23, 4.512
    { 158, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xff, 0xff, 0xff }, // 15 OSM: 3420997 51.17, 4.361 x 51.22, 4.494
    { 80, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xf5, 0xd2, 0x0 }, // 1 OSM: 3430333 49.72, 13.37 x 49.78, 13.4
    { 8, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xf5, 0xd2, 0x0 }, // 2 OSM: 3430559 49.73, 13.32 x 49.75, 13.41
    { 1, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xf5, 0xd2, 0x0 }, // 4 OSM: 3430578 49.73, 13.36 x 49.78, 13.38
    { 229, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xde, 0x3b, 0x21 }, // 19 OSM: 3437796 50.86, 4.273 x 50.9, 4.357
    { 196, 1298, 70, LineMetaDataContent::Subway, 0xb7, 0x75, 0x10 }, // U5 OSM: 3475206 WD: Q3832790 48.09, 11.5 x 48.14, 11.65
    { 167, 1314, 70, LineMetaDataContent::Subway, 0x0, 0x71, 0xbb }, // U6 OSM: 3477966 WD: Q751039 48.11, 11.47 x 48.27, 11.67
    { 187, 1330, 70, LineMetaDataContent::Subway, 0xf3, 0x6f, 0x33 }, // U3 OSM: 3484056 WD: Q20439760 48.09, 11.48 x 48.19, 11.59
    { 167, 1346, 70, LineMetaDataContent::Subway, 0x0, 0x7e, 0xc6 }, // U6 OSM: 3524791 WD: Q19863008 50.11, 8.624 x 50.14, 8.708
    { 203, 1363, 70, LineMetaDataContent::Subway, 0x44, 0x81, 0x37 }, // U1 OSM: 3531712 WD: Q20439756 48.1, 11.53 x 48.18, 11.58
    { 190, 1379, 70, LineMetaDataContent::Subway, 0xc4, 0xf, 0x39 }, // U2 OSM: 3531713 WD: Q830301 48.11, 11.54 x 48.21, 11.7
    { 184, 1395, 70, LineMetaDataContent::Subway, 0x46, 0x80, 0x37 }, // U7 OSM: 3531714 WD: Q20439774 48.1, 11.53 x 48.18, 11.65
    { 181, 1411, 70, LineMetaDataContent::Subway, 0xff, 0x6a, 0x2f }, // U8 OSM: 3531715 WD: Q20439777 48.1, 11.56 x 48.18, 11.65
    { 222, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xff, 0x0, 0x0 }, // A OSM: 3555528 49.49, 0.09563 x 49.53, 0.137
    { 226, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0x80, 0x0 }, // B OSM: 3555531 49.49, 0.09563 x 49.52, 0.1801
    { 302, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xff, 0xdd, 0x0 }, // T2 OSM: 3589646 45.44, 4.384 x 45.45, 4.403
    { 511, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xaf, 0xcb, 0x7 }, // T3 OSM: 3589647 45.42, 4.378 x 45.47, 4.405
    { 86, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0xd7, 0xdf, 0x23 }, // S1 OSM: 3654419 WD: Q680235 47.25, 11.08 x 47.59, 12.17
    { 31, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0xd4, 0xb4, 0xc4 }, // S5 OSM: 3654634 WD: Q680235 47.25, 11.19 x 47.39, 11.4
    { 170, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0xbe, 0xc2, 0xd0 }, // S4 OSM: 3654766 WD: Q680235 47, 11.23 x 47.27, 11.51
    { 161, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0x25, 0x7c, 0xa7 }, // S6 OSM: 3655247 WD: Q680235 47.42, 12.06 x 47.52, 12.63
    { 514, 1427, 991, LineMetaDataContent::Tramway, 0x0, 0x96, 0x41 }, // T3b OSM: 3662457 WD: Q3136247 48.85, 2.301 x 48.9, 2.411
    { 295, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x87, 0x3f, 0x98 }, // T1 OSM: 3667340 WD: Q2903 45.73, 4.817 x 45.79, 4.884
    { 302, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x87, 0x3f, 0x98 }, // T2 OSM: 3667554 WD: Q2906 45.69, 4.827 x 45.75, 4.956
    { 511, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x87, 0x3f, 0x98 }, // T3 OSM: 3667555 WD: Q2911 45.75, 4.862 x 45.78, 5.035
    { 518, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x87, 0x3f, 0x98 }, // T4 OSM: 3667556 WD: Q2918 45.69, 4.858 x 45.78, 4.888
    { 226, NoLogo, NoLogo, LineMetaDataContent::Subway, 0x0, 0x7d, 0xc5 }, // B OSM: 3687323 WD: Q2965 45.72, 4.81 x 45.77, 4.864
    { 395, NoLogo, NoLogo, LineMetaDataContent::Subway, 0x0, 0xac, 0x4d }, // D OSM: 3687324 WD: Q2976 45.7, 4.803 x 45.78, 4.89
    { 218, NoLogo, NoLogo, LineMetaDataContent::Subway, 0xf9, 0x9d, 0x1d }, // C OSM: 3687325 WD: Q2969 45.77, 4.827 x 45.79, 4.836
    { 222, NoLogo, NoLogo, LineMetaDataContent::Subway, 0xee, 0x38, 0x98 }, // A OSM: 3687326 WD: Q2944 45.75, 4.825 x 45.77, 4.922
    { 1, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0x9c, 0xdd }, // 4 OSM: 3733545 53.4, 14.49 x 53.45, 14.54
    { 107, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xff, 0x9e, 0xc2 }, // 62 OSM: 3775501 50.86, 4.332 x 50.88, 4.435
    { 426, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xfa, 0xa6, 0x1a }, // 28 OSM: 3858971 48.13, 11.56 x 48.17, 11.58
    { 476, NoLogo, 1455, LineMetaDataContent::Subway, 0xed, 0x1c, 0x24 }, // a OSM: 3889841 WD: Q24641190 48.09, -1.711 x 48.12, -1.644
    { 218, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xe4, 0x0, 0x7c }, // C OSM: 3921484 45.17, 5.69 x 45.19, 5.776
    { 270, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x58, 0x31, 0x8a }, // E OSM: 3921488 WD: Q3239103 45.17, 5.661 x 45.26, 5.72
    { 226, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0x9b, 0x3a }, // B OSM: 3921491 45.18, 5.698 x 45.21, 5.787
    { 222, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0x76, 0xbd }, // A OSM: 3921492 45.14, 5.671 x 45.2, 5.734
    { 395, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xf3, 0x9a, 0x0 }, // D OSM: 3921494 45.17, 5.754 x 45.19, 5.759
    { 264, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xe5, 0x44, 0x2e }, // M1 OSM: 3939086 WD: Q2740923 50.4, 4.271 x 50.42, 4.452
    { 224, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xef, 0x87, 0xb6 }, // HBB OSM: 3988307 47.27, 11.4 x 47.29, 11.4
    { 521, 1477, 991, LineMetaDataContent::Tramway, 0xb1, 0xa2, 0x45 }, // T8 OSM: 4007734 WD: Q3239029 48.93, 2.294 x 48.96, 2.358
    { 258, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xed, 0x19, 0x43 }, // 23 OSM: 4016993 WD: Q2914455 51.88, 4.432 x 51.92, 4.574
    { 84, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x99, 0xb3, 0xbe }, // 3 OSM: 4089342 46.94, 7.431 x 46.95, 7.441
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0x89, 0xcf }, // 6 OSM: 4089819 46.93, 7.419 x 46.95, 7.563
    { 524, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x99, 0x1f, 0x36 }, // 97 OSM: 4092822 50.8, 4.313 x 50.84, 4.357
    { 79, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xee, 0x1d, 0x23 }, // 11 OSM: 4108299 47.47, 7.573 x 47.58, 7.612
    { 0, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x84, 0xc8, 0xeb }, // M4 OSM: 4139149 WD: Q1841724 50.41, 4.435 x 50.43, 4.503
    { 25, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xee, 0x1d, 0x23 }, // 7 OSM: 4152763 46.94, 7.38 x 46.95, 7.472
    { 80, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xff, 0x7f, 0x0 }, // 1 OSM: 4234654 51.8, 12.24 x 51.84, 12.24
    { 31, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0xf4, 0x96, 0x94 }, // S5 OSM: 4292646 48.89, 8.243 x 49.06, 8.705
    { 80, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xbb, 0x0, 0x22 }, // 1 OSM: 4307991 51.02, 3.692 x 51.11, 3.75
    { 1, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x22, 0x99, 0x22 }, // 4 OSM: 4307994 51.02, 3.709 x 51.07, 3.751
    { 527, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0x0, 0xa6, 0xeb }, // S19 OSM: 4434302 WD: Q30597732 50.76, 6.482 x 50.95, 7.66
    { 417, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0xf7, 0x8a, 0x18 }, // S51 OSM: 4435864 52.1, 9.374 x 52.4, 9.773
    { 93, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0x11, 0x83, 0x49 }, // S21 OSM: 4435868 52.28, 9.466 x 52.38, 9.773
    { 170, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0x90, 0x3f, 0x98 }, // S4 OSM: 4452991 WD: Q459508 47.62, 12.87 x 47.84, 13
    { 34, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0x8e, 0xc7, 0xe8 }, // S8 OSM: 4470844 52.32, 9.687 x 52.46, 9.792
    { 207, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x59, 0x24, 0x9a }, // 14 OSM: 4489019 46.18, 6.077 x 46.24, 6.144
    { 14, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xa8, 0x4b, 0x97 }, // 18 OSM: 4489020 46.17, 6.054 x 46.23, 6.144
    { 158, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x77, 0x4c, 0x2d }, // 15 OSM: 4489138 46.18, 6.12 x 46.22, 6.149
    { 1, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xff, 0x0, 0x0 }, // 4 OSM: 4494871 WD: Q2105648 52.34, 4.889 x 52.38, 4.905
    { 7, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xab, 0x10, 0xd2 }, // 12 OSM: 4495366 WD: Q14500288 52.35, 4.879 x 52.38, 4.919
    { 80, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xff, 0xbf, 0x0 }, // 1 OSM: 4497227 WD: Q2663350 52.35, 4.775 x 52.36, 4.934
    { 8, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xff, 0xbf, 0x0 }, // 2 OSM: 4497722 WD: Q2033321 52.34, 4.804 x 52.38, 4.899
    { 84, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xab, 0x10, 0xd2 }, // 3 OSM: 4498754 WD: Q2051638 52.35, 4.87 x 52.39, 4.952
    { 4, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xff, 0xbf, 0x0 }, // 5 OSM: 4501532 WD: Q2343376 52.3, 4.867 x 52.38, 4.884
    { 25, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xff, 0x7f, 0x0 }, // 7 OSM: 4502267 WD: Q4405692 52.36, 4.818 x 52.38, 4.94
    { 229, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xff, 0x0, 0x0 }, // 19 OSM: 4507967 WD: Q2402279 52.34, 4.838 x 52.39, 4.971
    { 83, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xab, 0x10, 0xd2 }, // 13 OSM: 4512711 WD: Q2157983 52.37, 4.803 x 52.38, 4.899
    { 207, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0xff, 0x0 }, // 14 OSM: 4513498 WD: Q2108285 52.36, 4.892 x 52.38, 4.952
    { 151, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xf4, 0x9a, 0xc1 }, // 24 OSM: 4513900 WD: Q2651682 52.34, 4.857 x 52.38, 4.902
    { 140, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0x7f, 0xff }, // 17 OSM: 4514442 WD: Q2400889 52.36, 4.787 x 52.38, 4.899
    { 443, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xd5, 0x97, 0x58 }, // 26 OSM: 4514564 WD: Q2503173 52.35, 4.898 x 52.38, 5.005
    { 143, NoLogo, 1504, LineMetaDataContent::Subway, 0x29, 0xab, 0x4d }, // 50 OSM: 4515358 WD: Q2466111 52.29, 4.834 x 52.4, 4.99
    { 418, NoLogo, 1504, LineMetaDataContent::Subway, 0xf6, 0x99, 0x31 }, // 51 OSM: 4515359 WD: Q606629 52.33, 4.834 x 52.4, 4.924
    { 531, NoLogo, 1504, LineMetaDataContent::Subway, 0xfc, 0xfb, 0x5 }, // 54 OSM: 4515360 WD: Q2183200 52.29, 4.9 x 52.38, 4.99
    { 534, NoLogo, 1504, LineMetaDataContent::Subway, 0xff, 0x0, 0x0 }, // 53 OSM: 4515361 WD: Q2163442 52.31, 4.9 x 52.38, 4.985
    { 154, 1529, NoLogo, LineMetaDataContent::RapidTransit, 0x5b, 0x9a, 0x6d }, // S2 OSM: 4615535 WD: Q680235 47.24, 10.86 x 47.39, 11.78
    { 537, 1548, 1575, LineMetaDataContent::Subway, 0xff, 0x0, 0x0 }, // m2 OSM: 4621397 WD: Q3239144 46.51, 6.626 x 46.54, 6.661
    { 8, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x94, 0xc1, 0x1a }, // 2 OSM: 4622863 52.23, 10.52 x 52.29, 10.54
    { 203, 1600, 70, LineMetaDataContent::Subway, 0xb8, 0x28, 0x2e }, // U1 OSM: 4656730 WD: Q198432 50.1, 8.634 x 50.17, 8.687
    { 187, 1617, 70, LineMetaDataContent::Subway, 0x4a, 0x5e, 0xaa }, // U3 OSM: 4656731 WD: Q19862991 50.1, 8.537 x 50.22, 8.687
    { 193, 1634, 70, LineMetaDataContent::Subway, 0xf1, 0x72, 0xac }, // U4 OSM: 4656732 WD: Q19862998 50.11, 8.652 x 50.14, 8.755
    { 196, 1651, 70, LineMetaDataContent::Subway, 0x0, 0x79, 0x42 }, // U5 OSM: 4656733 WD: Q3040872 50.11, 8.662 x 50.16, 8.692
    { 184, 1668, 70, LineMetaDataContent::Subway, 0xe4, 0xa0, 0x23 }, // U7 OSM: 4656734 WD: Q3040904 50.11, 8.607 x 50.15, 8.755
    { 181, 1685, 70, LineMetaDataContent::Subway, 0xc7, 0x7d, 0xb5 }, // U8 OSM: 4656735 WD: Q3063407 50.1, 8.621 x 50.18, 8.687
    { 178, 1702, 70, LineMetaDataContent::Subway, 0xee, 0xd7, 0x0 }, // U9 OSM: 4656736 WD: Q19862984 50.14, 8.621 x 50.2, 8.674
    { 540, 1719, NoLogo, LineMetaDataContent::RapidTransit, 0xe6, 0x73, 0x10 }, // A2 OSM: 4785912 WD: Q19582807 53.71, 9.966 x 53.83, 9.993
    { 295, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0xa5, 0xc1 }, // T1 OSM: 5157502 47.22, 5.949 x 47.26, 6.061
    { 80, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xe4, 0x0, 0x2c }, // 1 OSM: 5185991 51, 13.67 x 51.06, 13.82
    { 8, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xeb, 0x5b, 0x2d }, // 2 OSM: 5186008 51.01, 13.65 x 51.06, 13.85
    { 1, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xc9, 0x6, 0x1a }, // 4 OSM: 5186035 51.02, 13.56 x 51.16, 13.84
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xff, 0xdd, 0x0 }, // 6 OSM: 5186067 51, 13.65 x 51.06, 13.84
    { 11, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x22, 0x91, 0x33 }, // 8 OSM: 5186073 51.03, 13.72 x 51.12, 13.77
    { 148, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x93, 0xc3, 0x55 }, // 9 OSM: 5186435 51, 13.69 x 51.08, 13.8
    { 90, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xf9, 0xb0, 0x0 }, // 10 OSM: 5186677 51.04, 13.71 x 51.07, 13.81
    { 79, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xc2, 0xdd, 0xaf }, // 11 OSM: 5186681 51.02, 13.73 x 51.07, 13.86
    { 83, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xfd, 0xc3, 0x0 }, // 13 OSM: 5186751 51, 13.69 x 51.08, 13.8
    { 80, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xd5, 0x23, 0x30 }, // 1 OSM: 5209167 50.93, 6.816 x 50.96, 7.162
    { 25, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xe6, 0x85, 0x5c }, // 7 OSM: 5231292 50.87, 6.797 x 50.94, 7.06
    { 543, 1734, 1734, LineMetaDataContent::Subway, 0x0, 0x0, 0x0 }, // U17 OSM: 5312041 WD: Q203252 51.43, 6.973 x 51.5, 7.013
    { 249, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xf9, 0xb0, 0x0 }, // 20 OSM: 5421483 51.04, 13.71 x 51.07, 13.74
    { 8, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0x9c, 0xdd }, // 2 OSM: 5484713 53.38, 14.55 x 53.45, 14.64
    { 547, 1748, NoLogo, LineMetaDataContent::RapidTransit, 0xe7, 0x95, 0x0 }, // A1 OSM: 5610369 WD: Q19368804 53.55, 9.889 x 54.08, 10.02
    { 84, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xd7, 0x51, 0x28 }, // 3 OSM: 5646916 50.69, 12.46 x 50.73, 12.53
    { 126, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xff, 0xa5, 0x0 }, // 60 OSM: 5664426 WD: Q30716928 52.01, 5.076 x 52.09, 5.108
    { 100, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xff, 0xa5, 0x0 }, // 61 OSM: 5664427 WD: Q81422423 52.01, 5.028 x 52.09, 5.108
    { 140, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x6d, 0xcf, 0xf6 }, // 17 OSM: 5740169 50.86, 6.957 x 50.93, 7.004
    { 18, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x21, 0xbf, 0xc1 }, // 16 OSM: 5742444 50.68, 6.943 x 50.99, 7.159
    { 1, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xe0, 0x6e, 0x9f }, // 4 OSM: 5742445 50.93, 6.872 x 51.02, 7.044
    { 550, NoLogo, NoLogo, LineMetaDataContent::Subway, 0xda, 0x25, 0x1d }, // U71 OSM: 5747258 WD: Q661002 51.16, 6.775 x 51.26, 6.886
    { 554, 1734, 1734, LineMetaDataContent::Subway, 0xda, 0x25, 0x1d }, // U83 OSM: 5748738 WD: Q661002 51.16, 6.775 x 51.25, 6.886
    { 558, NoLogo, NoLogo, LineMetaDataContent::Subway, 0xda, 0x25, 0x1d }, // U73 OSM: 5756097 WD: Q661002 51.19, 6.775 x 51.24, 6.867
    { 562, NoLogo, NoLogo, LineMetaDataContent::Subway, 0xda, 0x25, 0x1d }, // U72 OSM: 5756147 WD: Q661002 51.19, 6.762 x 51.3, 6.847
    { 1, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xa4, 0x10, 0x7f }, // 4 OSM: 5804724 WD: Q3476269 51.91, 4.432 x 51.96, 4.504
    { 566, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xfb, 0xc4, 0x24 }, // U42 OSM: 5890483 51.47, 7.433 x 51.56, 7.547
    { 570, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xec, 0x24, 0x25 }, // U45 OSM: 5892934 51.49, 7.46 x 51.52, 7.475
    { 222, NoLogo, 1763, LineMetaDataContent::Subway, 0x0, 0xaa, 0x50 }, // A OSM: 5955845 WD: Q2310450 51.9, 4.315 x 51.96, 4.566
    { 226, NoLogo, 1763, LineMetaDataContent::Subway, 0xff, 0xd3, 0x1 }, // B OSM: 5955846 WD: Q2960661 51.9, 4.129 x 51.98, 4.587
    { 218, NoLogo, 1763, LineMetaDataContent::Subway, 0xef, 0x1f, 0x1f }, // C OSM: 5955847 WD: Q2058778 51.83, 4.32 x 51.94, 4.601
    { 395, NoLogo, 1763, LineMetaDataContent::Subway, 0x1b, 0xc5, 0xe9 }, // D OSM: 5955848 WD: Q2034685 51.83, 4.32 x 51.92, 4.497
    { 270, NoLogo, 1788, LineMetaDataContent::Subway, 0x1a, 0x38, 0x9a }, // E OSM: 5955849 WD: Q2687418 51.87, 4.325 x 52.08, 4.497
    { 8, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x90, 0x13, 0xc }, // 2 OSM: 5955850 WD: Q1982139 51.88, 4.464 x 51.9, 4.554
    { 249, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xfb, 0xb3, 0x16 }, // 20 OSM: 5966563 WD: Q3118970 51.88, 4.471 x 51.92, 4.539
    { 574, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xff, 0x0, 0x0 }, // NL1 OSM: 5976635 49, 8.405 x 49.01, 8.479
    { 578, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0x66, 0x99 }, // NL2 OSM: 5976636 48.99, 8.384 x 49.01, 8.411
    { 140, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x4d, 0x3d, 0x0 }, // 17 OSM: 6061801 49.01, 8.359 x 49.05, 8.452
    { 18, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xff, 0xaa, 0xaa }, // 16 OSM: 6061802 48.99, 8.383 x 49.05, 8.452
    { 14, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0x80, 0x5a }, // 18 OSM: 6061803 49, 8.431 x 49.05, 8.479
    { 270, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0x0, 0x0 }, // E OSM: 6062533 48.95, 8.283 x 49.11, 8.505
    { 1, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xea, 0x52, 0x97 }, // 4 OSM: 6092716 47.99, 7.829 x 48.04, 7.863
    { 174, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0xf3, 0x64, 0x21 }, // S 1 OSM: 6116272 WD: Q56378877 50.88, 13.46 x 51.16, 14.24
    { 497, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0xb8, 0x28, 0x2e }, // S 2 OSM: 6116280 WD: Q56378880 50.96, 13.72 x 51.13, 13.93
    { 460, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0xed, 0x1, 0x72 }, // S 3 OSM: 6116305 WD: Q56378881 50.9, 13.34 x 51.04, 13.73
    { 80, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xc0, 0x11, 0x15 }, // 1 OSM: 6182760 WD: Q2085324 51.98, 4.277 x 52.12, 4.359
    { 8, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0x66, 0x0 }, // 2 OSM: 6182761 WD: Q3926989 52.05, 4.236 x 52.09, 4.383
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0x93, 0xde }, // 6 OSM: 6182762 WD: Q2205103 52.06, 4.264 x 52.1, 4.4
    { 79, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xcd, 0x85, 0x3f }, // 11 OSM: 6192619 WD: Q2084217 52.06, 4.27 x 52.11, 4.324
    { 7, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xff, 0x66, 0xff }, // 12 OSM: 6192620 WD: Q2541548 52.06, 4.252 x 52.09, 4.324
    { 148, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xa6, 0xc1, 0x16 }, // 9 OSM: 6192621 WD: Q2293268 52.03, 4.257 x 52.12, 4.329
    { 158, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xe6, 0x3a, 0x6b }, // 15 OSM: 6197181 WD: Q2202159 52.04, 4.315 x 52.08, 4.393
    { 18, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xfa, 0x72, 0x22 }, // 16 OSM: 6197182 WD: Q2746551 52.02, 4.271 x 52.1, 4.327
    { 140, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0x6b, 0x8b }, // 17 OSM: 6197183 WD: Q2417431 52.02, 4.289 x 52.08, 4.339
    { 229, NoLogo, 1788, LineMetaDataContent::Tramway, 0xc0, 0x11, 0x15 }, // 19 OSM: 6197184 WD: Q2886326 52.01, 4.35 x 52.09, 4.406
    { 582, 1802, 1828, LineMetaDataContent::Subway, 0xa, 0x9c, 0xda }, // Victoria OSM: 6354922 WD: Q203030 51.46, -0.1441 x 51.59, -0.01927
    { 591, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0xb, 0x4e, 0xa2 }, // TL 1 OSM: 6421836 50.83, -0.5143 x 52.14, -0.03743
    { 596, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0xf7, 0x93, 0x1d }, // SN 5 OSM: 6489645 51.07, -0.3198 x 51.5, 0.2709
    { 1, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xe4, 0x1f, 0x25 }, // 4 OSM: 6576221 48.22, 14.23 x 48.31, 14.29
    { 601, NoLogo, NoLogo, LineMetaDataContent::Subway, 0x30, 0x22, 0x76 }, // U74 OSM: 6760736 WD: Q661002 51.16, 6.615 x 51.28, 6.853
    { 24, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0xff, 0xf2, 0x0 }, // S7 OSM: 6796259 48.63, 8.065 x 49.01, 8.432
    { 605, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0xff, 0xf2, 0x0 }, // S71 OSM: 6796260 48.63, 8.065 x 48.99, 8.405
    { 609, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0x6d, 0x68, 0x2a }, // S81 OSM: 6796368 48.44, 8.215 x 48.99, 8.782
    { 613, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xf6, 0x8c, 0x59 }, // T3a OSM: 6907402 48.82, 2.271 x 48.85, 2.411
    { 518, 1844, 991, LineMetaDataContent::Tramway, 0xf2, 0xaf, 0x0 }, // T4 OSM: 6910344 WD: Q1826681 48.89, 2.478 x 48.93, 2.562
    { 452, 1871, 991, LineMetaDataContent::Tramway, 0xb1, 0x56, 0xa1 }, // T5 OSM: 6910410 WD: Q3238968 48.94, 2.356 x 48.98, 2.391
    { 617, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xe8, 0x54, 0x26 }, // T6 OSM: 6910437 48.78, 2.169 x 48.81, 2.301
    { 620, 1898, 991, LineMetaDataContent::Tramway, 0xb9, 0x8b, 0x59 }, // T7 OSM: 6910465 WD: Q3239019 48.71, 2.352 x 48.79, 2.373
    { 459, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0x5c, 0xda, 0x21 }, // RS 3 OSM: 6925925 53.05, 8.002 x 53.18, 8.815
    { 434, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0xff, 0x0, 0x0 }, // RS 4 OSM: 6925927 53.05, 8.452 x 53.49, 8.815
    { 623, NoLogo, NoLogo, LineMetaDataContent::Subway, 0xff, 0xcf, 0x0 }, // OrlyVAL OSM: 6928902 WD: Q432593 48.73, 2.3 x 48.76, 2.37
    { 631, NoLogo, NoLogo, LineMetaDataContent::Subway, 0x14, 0x2b, 0x4a }, // CDGVAL OSM: 6928933 WD: Q1023114 49, 2.542 x 49.01, 2.572
    { 80, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xc0, 0x0, 0x27 }, // 1 OSM: 6981890 47.74, 7.321 x 47.78, 7.343
    { 486, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xf7, 0xe0, 0x17 }, // 32 OSM: 6995933 50.78, 4.313 x 50.88, 4.416
    { 4, 1925, 1946, LineMetaDataContent::Subway, 0xfa, 0xb2, 0xb }, // 5 OSM: 6996917 WD: Q957143 50.81, 4.266 x 50.86, 4.432
    { 8, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xff, 0xd8, 0xe }, // 2 OSM: 7006051 47.73, 7.297 x 47.76, 7.352
    { 80, 1970, 1946, LineMetaDataContent::Subway, 0xb9, 0x18, 0x93 }, // 1 OSM: 7006076 WD: Q1345228 50.84, 4.319 x 50.86, 4.464
    { 84, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0xa6, 0x51 }, // 3 OSM: 7006942 47.74, 7.276 x 47.76, 7.344
    { 154, 1991, NoLogo, LineMetaDataContent::RapidTransit, 0x6c, 0xc2, 0x47 }, // S2 OSM: 7091572 WD: Q7388247 48.13, 11.25 x 48.41, 11.91
    { 25, 2007, 2028, LineMetaDataContent::Tramway, 0xff, 0xf0, 0x6e }, // 7 OSM: 7135778 WD: Q3239018 50.81, 4.336 x 50.9, 4.408
    { 364, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xde, 0x3b, 0x21 }, // 92 OSM: 7152034 50.79, 4.34 x 50.88, 4.381
    { 8, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x37, 0xb3, 0x55 }, // 2 OSM: 7157243 WD: Q60031554 48.38, 9.936 x 48.43, 9.987
    { 80, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xed, 0x1b, 0x24 }, // 1 OSM: 7157244 WD: Q60031375 48.39, 9.955 x 48.43, 10.03
    { 8, 2054, 952, LineMetaDataContent::Subway, 0x21, 0x6e, 0xb4 }, // 2 OSM: 7227705 WD: Q50718 48.85, 2.278 x 48.88, 2.399
    { 638, 2072, 1828, LineMetaDataContent::Subway, 0xe4, 0x23, 0x13 }, // Central OSM: 7254206 WD: Q205355 51.5, -0.4378 x 51.69, 0.1146
    { 270, 2097, 705, LineMetaDataContent::RapidTransit, 0xbd, 0x76, 0xa1 }, // E OSM: 7271953 WD: Q668655 48.74, 2.327 x 48.9, 2.761
    { 83, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xf6, 0xc8, 0x28 }, // 13 OSM: 7295272 47.35, 8.481 x 47.41, 8.542
    { 8, 2118, 1946, LineMetaDataContent::Subway, 0xf5, 0x70, 0x0 }, // 2 OSM: 7305855 WD: Q1826676 50.83, 4.321 x 50.87, 4.37
    { 646, 2139, NoLogo, LineMetaDataContent::RapidTransit, 0x9f, 0x4c, 0x37 }, // S41 OSM: 7369771 WD: Q12374455 52.46, 13.28 x 52.55, 13.48
    { 610, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x33, 0x8c, 0x26 }, // 81 OSM: 7375224 50.82, 4.28 x 50.84, 4.408
    { 86, NoLogo, 2154, LineMetaDataContent::RapidTransit, 0x2, 0x5f, 0x33 }, // S1 OSM: 7382640 WD: Q24929119 50.6, 4.32 x 51.22, 4.497
    { 154, NoLogo, 2154, LineMetaDataContent::RapidTransit, 0xf2, 0x61, 0x22 }, // S2 OSM: 7383577 WD: Q56309162 50.61, 4.139 x 50.9, 4.716
    { 410, NoLogo, 2154, LineMetaDataContent::RapidTransit, 0x5, 0x97, 0x97 }, // S20 OSM: 7386794 WD: Q56309254 50.67, 4.565 x 50.88, 4.719
    { 31, NoLogo, 2154, LineMetaDataContent::RapidTransit, 0xfe, 0xcc, 0x9 }, // S5 OSM: 7387151 WD: Q56309389 50.69, 3.87 x 51.02, 4.484
    { 129, NoLogo, 2154, LineMetaDataContent::RapidTransit, 0x21, 0x28, 0x76 }, // S3 OSM: 7388964 WD: Q56309590 50.82, 3.601 x 51.02, 4.366
    { 170, NoLogo, 2154, LineMetaDataContent::RapidTransit, 0xce, 0x21, 0x27 }, // S4 OSM: 7389117 WD: Q56309251 50.82, 4.039 x 50.94, 4.433
    { 161, NoLogo, 2154, LineMetaDataContent::RapidTransit, 0x96, 0x5f, 0x26 }, // S6 OSM: 7391007 WD: Q56309855 50.69, 3.87 x 50.88, 4.378
    { 24, NoLogo, 2154, LineMetaDataContent::RapidTransit, 0x58, 0x17, 0x59 }, // S7 OSM: 7391045 WD: Q56309167 50.73, 4.241 x 51.02, 4.523
    { 34, NoLogo, 2154, LineMetaDataContent::RapidTransit, 0xd, 0x96, 0xcd }, // S8 OSM: 7391071 WD: Q56309403 50.65, 4.336 x 50.87, 4.617
    { 287, NoLogo, 2154, LineMetaDataContent::RapidTransit, 0x67, 0xbc, 0x45 }, // S9 OSM: 7391314 WD: Q56309779 50.68, 4.335 x 50.9, 4.717
    { 381, NoLogo, 2154, LineMetaDataContent::RapidTransit, 0xff, 0x1f, 0x20 }, // S10 OSM: 7391375 WD: Q56309273 50.83, 4.039 x 51.02, 4.366
    { 83, 2176, 952, LineMetaDataContent::Subway, 0x89, 0xc7, 0xd6 }, // 13 OSM: 7420641 WD: Q50759 48.81, 2.284 x 48.95, 2.369
    { 7, 2195, 952, LineMetaDataContent::Subway, 0x32, 0x8e, 0x5b }, // 12 OSM: 7420642 WD: Q50757 48.82, 2.273 x 48.91, 2.366
    { 79, 2214, 952, LineMetaDataContent::Subway, 0x8e, 0x65, 0x38 }, // 11 OSM: 7420643 WD: Q50756 48.86, 2.348 x 48.88, 2.416
    { 11, 2233, 952, LineMetaDataContent::Subway, 0xc5, 0xa3, 0xca }, // 8 OSM: 7420644 WD: Q50751 48.77, 2.278 x 48.87, 2.465
    { 4, 2251, 952, LineMetaDataContent::Subway, 0xde, 0x8b, 0x53 }, // 5 OSM: 7420645 WD: Q50745 48.83, 2.355 x 48.91, 2.449
    { 650, 2269, 952, LineMetaDataContent::Subway, 0x89, 0xc7, 0xd6 }, // 3bis OSM: 7420646 WD: Q50742 48.87, 2.399 x 48.88, 2.406
    { 226, 2290, 705, LineMetaDataContent::RapidTransit, 0x50, 0x92, 0xc9 }, // B OSM: 7420701 WD: Q1347825 48.69, 2.071 x 49.01, 2.642
    { 84, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0xff, 0x0 }, // 3 OSM: 7560907 51.34, -0.1055 x 51.38, -0.01745
    { 302, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xe4, 0x0, 0x53 }, // T2 OSM: 7580423 WD: Q3239070 50.32, 3.509 x 50.47, 3.596
    { 418, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xe3, 0xba, 0x12 }, // 51 OSM: 7632520 50.78, 4.326 x 50.89, 4.349
    { 367, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xe8, 0x7d, 0xd }, // 93 OSM: 7632524 50.82, 4.33 x 50.89, 4.372
    { 655, 2311, 1828, LineMetaDataContent::Subway, 0xae, 0x60, 0x17 }, // Bakerloo OSM: 7666698 WD: Q19892 51.49, -0.3357 x 51.59, -0.09912
    { 664, 2337, 1828, LineMetaDataContent::Subway, 0xf4, 0xa9, 0xbe }, // Hammersmith & City OSM: 7666927 WD: Q211270 51.49, -0.2268 x 51.54, 0.08088
    { 683, 2358, 1828, LineMetaDataContent::Subway, 0xff, 0xd3, 0x29 }, // Circle OSM: 7671007 WD: Q210321 51.49, -0.2268 x 51.53, -0.07523
    { 690, 2382, 1828, LineMetaDataContent::Subway, 0x93, 0xce, 0xba }, // Waterloo & City OSM: 7672075 WD: Q207699 51.5, -0.1142 x 51.51, -0.09074
    { 706, 2403, 1828, LineMetaDataContent::Subway, 0x94, 0x96, 0x99 }, // Jubilee OSM: 7673326 WD: Q961290 51.5, -0.303 x 51.62, 0.01165
    { 714, 2428, 1828, LineMetaDataContent::Subway, 0x91, 0x0, 0x5a }, // Metropolitan OSM: 7673626 WD: Q19891 51.51, -0.6112 x 51.71, -0.0757
    { 727, 2458, 1828, LineMetaDataContent::Subway, 0x0, 0xa1, 0x66 }, // District OSM: 7677096 WD: Q211265 51.42, -0.3016 x 51.56, 0.253
    { 736, 2484, 1828, LineMetaDataContent::Subway, 0x9, 0x4f, 0xa3 }, // Piccadilly OSM: 7702940 WD: Q207689 51.46, -0.4929 x 51.65, -0.09515
    { 747, 2512, 1828, LineMetaDataContent::Subway, 0x0, 0x0, 0x0 }, // Northern OSM: 7702944 WD: Q214793 51.4, -0.2756 x 51.65, -0.08677
    { 84, 2538, 952, LineMetaDataContent::Subway, 0x9a, 0x99, 0x40 }, // 3 OSM: 7733214 WD: Q50741 48.86, 2.28 x 48.9, 2.418
    { 295, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x64, 0x31, 0x8f }, // T1 OSM: 7758458 WD: Q50319281 49.61, 6.119 x 49.64, 6.176
    { 8, 2556, 2576, LineMetaDataContent::Subway, 0xed, 0x1d, 0x24 }, // 2 OSM: 7786752 WD: Q3238802 50.62, 2.973 x 50.74, 3.181
    { 80, 2602, 2576, LineMetaDataContent::Subway, 0xff, 0xd4, 0x0 }, // 1 OSM: 7786754 WD: Q3238658 50.61, 3.036 x 50.64, 3.143
    { 527, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0xf5, 0x82, 0x20 }, // S19 OSM: 7800298 WD: Q25352054 47.37, 8.227 x 47.6, 8.787
    { 756, NoLogo, NoLogo, LineMetaDataContent::Subway, 0x69, 0xbe, 0x51 }, // U34 OSM: 7801960 48.76, 9.143 x 48.78, 9.178
    { 760, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0xf1, 0x7f, 0x1a }, // S 9 OSM: 7805411 51.45, 11.98 x 51.52, 12.64
    { 84, 2622, 2028, LineMetaDataContent::Tramway, 0xb5, 0xba, 0x5 }, // 3 OSM: 7857250 WD: Q1888831 50.81, 4.336 x 50.9, 4.377
    { 395, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0x98, 0x32 }, // D OSM: 7925628 48.57, 7.691 x 48.59, 7.816
    { 218, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xf6, 0x87, 0x12 }, // C OSM: 7925656 48.55, 7.735 x 48.59, 7.773
    { 19, 2643, 1946, LineMetaDataContent::Subway, 0x0, 0x78, 0xad }, // 6 OSM: 7927182 WD: Q668977 50.83, 4.321 x 50.9, 4.37
    { 1, 2664, 2028, LineMetaDataContent::Tramway, 0xf2, 0x54, 0x82 }, // 4 OSM: 7999217 WD: Q2527775 50.79, 4.318 x 50.86, 4.363
    { 237, 2685, 2028, LineMetaDataContent::Tramway, 0x99, 0x1f, 0x36 }, // 25 OSM: 7999338 WD: Q3238750 50.8, 4.358 x 50.87, 4.408
    { 200, 2707, 2028, LineMetaDataContent::Tramway, 0xe3, 0xba, 0x12 }, // 55 OSM: 7999374 WD: Q2236365 50.86, 4.358 x 50.88, 4.416
    { 327, 2729, 2028, LineMetaDataContent::Tramway, 0x9e, 0xbf, 0xe3 }, // 82 OSM: 7999733 WD: Q2534011 50.78, 4.29 x 50.87, 4.341
    { 14, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xab, 0xd0, 0x2c }, // 18 OSM: 8054951 50.05, 14.39 x 50.11, 14.44
    { 140, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xa7, 0xc9, 0xae }, // 17 OSM: 8055113 50, 14.4 x 50.13, 14.46
    { 79, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xdc, 0x0, 0x8f }, // 11 OSM: 8060662 50.05, 14.3 x 50.09, 14.54
    { 78, 647, NoLogo, LineMetaDataContent::RapidTransit, 0xb7, 0x28, 0x41 }, // S11 OSM: 8149205 WD: Q459508 47.98, 12.85 x 48.04, 12.93
    { 129, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0x22, 0xb2, 0x4c }, // S3 OSM: 8149206 WD: Q459508 47.28, 12.79 x 47.84, 13.23
    { 154, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0x0, 0x72, 0xbc }, // S2 OSM: 8149207 WD: Q459508 47.81, 12.97 x 47.97, 13.27
    { 86, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0xb7, 0x28, 0x41 }, // S1 OSM: 8149208 WD: Q459508 47.81, 12.92 x 47.99, 13.05
    { 302, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0x0, 0xff }, // T2 OSM: 8209896 WD: Q16655789 47.99, 0.1929 x 48.02, 0.2359
    { 295, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xeb, 0x0, 0x1b }, // T1 OSM: 8209897 WD: Q3239229 47.96, 0.152 x 48.02, 0.2304
    { 1, NoLogo, 1788, LineMetaDataContent::Tramway, 0xfc, 0x75, 0x1c }, // 4 OSM: 8255319 WD: Q2735863 52.04, 4.245 x 52.08, 4.543
    { 84, NoLogo, 1788, LineMetaDataContent::Tramway, 0x70, 0x32, 0x76 }, // 3 OSM: 8255320 WD: Q3056105 52.05, 4.228 x 52.08, 4.518
    { 34, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0x5e, 0x2d, 0x91 }, // S8 OSM: 8294822 WD: Q7388382 47.2, 8.519 x 47.5, 8.782
    { 24, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0xfe, 0xbe, 0x10 }, // S7 OSM: 8294823 WD: Q7388366 47.22, 8.511 x 47.5, 8.824
    { 154, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0x5d, 0xa5, 0x26 }, // S2 OSM: 8294824 WD: Q7388254 47.13, 8.519 x 47.45, 9.063
    { 764, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0x56, 0x3, 0x3a }, // S 6 OSM: 8303864 51.06, 12.37 x 51.4, 12.7
    { 768, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0x5, 0x88, 0xcc }, // S30 OSM: 8327718 WD: Q7388265 47.5, 8.722 x 47.59, 9.106
    { 308, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0x7a, 0x4c, 0x29 }, // S13 OSM: 8327720 WD: Q7388186 47.13, 8.675 x 47.23, 8.75
    { 772, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0x73, 0xb3, 0xd7 }, // S35 OSM: 8437405 WD: Q7388272 47.46, 8.724 x 47.51, 9.042
    { 448, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0x32, 0xa3, 0x84 }, // S29 OSM: 8437511 WD: Q7388235 47.5, 8.714 x 47.66, 8.855
    { 490, NoLogo, 1504, LineMetaDataContent::Subway, 0x0, 0xad, 0xef }, // 52 OSM: 8466672 WD: Q2466115 52.34, 4.874 x 52.4, 4.933
    { 776, NoLogo, 991, LineMetaDataContent::Tramway, 0xe6, 0x5e, 0x37 }, // T11 OSM: 8467024 WD: Q1083349 48.93, 2.302 x 48.96, 2.424
    { 780, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xff, 0x7f, 0x0 }, // 11* OSM: 8510354 WD: Q2662616 52.36, 4.851 x 52.38, 4.899
    { 148, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xff, 0x0, 0xff }, // 9 OSM: 8624098 50.86, 4.309 x 50.89, 4.33
    { 31, 2751, 568, LineMetaDataContent::RapidTransit, 0xeb, 0x87, 0x38 }, // S5 OSM: 8662846 WD: Q1159300 45.46, 8.789 x 45.82, 9.589
    { 161, 2765, 568, LineMetaDataContent::RapidTransit, 0xeb, 0xcc, 0x0 }, // S6 OSM: 8662847 WD: Q1160580 45.43, 8.625 x 45.53, 9.589
    { 18, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xf9, 0xb0, 0x0 }, // 16 OSM: 8712352 52.32, 9.722 x 52.38, 9.837
    { 14, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xe4, 0x0, 0x3a }, // 18 OSM: 8712368 52.33, 9.739 x 52.38, 9.805
    { 34, 2779, 568, LineMetaDataContent::RapidTransit, 0xf0, 0x9e, 0xa1 }, // S8 OSM: 8840314 WD: Q1160824 45.48, 9.179 x 45.86, 9.435
    { 287, 2793, 568, LineMetaDataContent::RapidTransit, 0x8c, 0x36, 0x82 }, // S9 OSM: 8840324 WD: Q56920 45.4, 8.956 x 45.65, 9.274
    { 78, 2807, 568, LineMetaDataContent::RapidTransit, 0x87, 0x87, 0xba }, // S11 OSM: 8840325 WD: Q1160879 45.48, 9.029 x 45.83, 9.274
    { 7, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xf5, 0xa3, 0x0 }, // 12 OSM: 8871002 46.17, 6.122 x 46.2, 6.207
    { 784, NoLogo, NoLogo, LineMetaDataContent::Subway, 0xba, 0xc2, 0x19 }, // U16 OSM: 9091024 48.8, 9.087 x 48.81, 9.277
    { 8, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xa6, 0x83, 0x51 }, // 2 OSM: 9112026 47.54, 7.571 x 47.57, 7.617
    { 84, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x32, 0x4e, 0xa1 }, // 3 OSM: 9118502 47.55, 7.553 x 47.59, 7.631
    { 80, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x83, 0x52, 0x37 }, // 1 OSM: 9118510 47.55, 7.573 x 47.57, 7.608
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0x72, 0xbc }, // 6 OSM: 9128621 47.55, 7.537 x 47.59, 7.656
    { 11, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xf1, 0x71, 0xab }, // 8 OSM: 9173651 47.55, 7.557 x 47.59, 7.608
    { 90, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xfe, 0xca, 0xa }, // 10 OSM: 9177454 47.48, 7.459 x 47.55, 7.62
    { 207, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xf5, 0x82, 0x20 }, // 14 OSM: 9190891 47.52, 7.587 x 47.57, 7.694
    { 158, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0xa5, 0x4f }, // 15 OSM: 9193744 47.53, 7.587 x 47.56, 7.6
    { 18, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xa6, 0xce, 0x39 }, // 16 OSM: 9196819 47.53, 7.584 x 47.56, 7.605
    { 140, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0xae, 0xef }, // 17 OSM: 9201222 47.48, 7.545 x 47.58, 7.593
    { 8, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xd6, 0x45, 0x60 }, // 2 OSM: 9235815 47.26, 11.34 x 47.28, 11.44
    { 4, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x8b, 0x44, 0x5b }, // 5 OSM: 9235816 47.26, 11.34 x 47.28, 11.44
    { 788, NoLogo, NoLogo, LineMetaDataContent::Subway, 0xff, 0xd5, 0x3 }, // U29 OSM: 9352741 48.77, 9.122 x 48.78, 9.182
    { 792, NoLogo, NoLogo, LineMetaDataContent::Subway, 0x0, 0x5a, 0xab }, // U15 OSM: 9355173 48.74, 9.156 x 48.85, 9.234
    { 258, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xf8, 0xb7, 0x10 }, // 23 OSM: 9396890 48.75, 9.179 x 48.81, 9.221
    { 222, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xc0, 0x19, 0x3 }, // A OSM: 9413576 45.76, 3.082 x 45.81, 3.135
    { 94, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0xae, 0x9d }, // 21 OSM: 9414064 47.56, 7.573 x 47.57, 7.608
    { 796, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0xcb, 0x7e, 0xb5 }, // S36 OSM: 9414253 WD: Q15088595 47.52, 8.22 x 47.62, 8.538
    { 442, 2822, NoLogo, LineMetaDataContent::RapidTransit, 0x1, 0x8a, 0x47 }, // S26 OSM: 9445376 WD: Q7388232 52.4, 13.28 x 52.61, 13.4
    { 4, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0x99, 0x99 }, // 5 OSM: 9544852 53.08, 8.752 x 53.12, 8.818
    { 34, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0x5c, 0xc1, 0xd1 }, // S8 OSM: 9634179 47.17, 14.44 x 47.34, 15
    { 8, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xff, 0x0, 0x0 }, // 2 OSM: 9680853 51.37, -0.2081 x 51.42, -0.02612
    { 1, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xb5, 0xe6, 0x1d }, // 4 OSM: 9680854 51.37, -0.2081 x 51.42, -0.04953
    { 800, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0x0, 0xff }, // BLUE OSM: 9701744 53.33, -1.508 x 53.4, -1.344
    { 805, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x80, 0x0, 0x80 }, // PURP OSM: 9701781 53.34, -1.469 x 53.38, -1.424
    { 810, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xff, 0xff, 0x0 }, // YELL OSM: 9701824 53.38, -1.51 x 53.42, -1.405
    { 305, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0x0, 0x0 }, // TT OSM: 9701873 53.38, -1.469 x 53.44, -1.343
    { 302, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xe2, 0x39, 0x3a }, // T2 OSM: 9797089 49.18, -0.3663 x 49.21, -0.348
    { 511, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x4, 0x9a, 0xdc }, // T3 OSM: 9797090 49.16, -0.3636 x 49.19, -0.3411
    { 815, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0xef, 0x7b, 0x10 }, // Overground OSM: 9874367 WD: Q17986446 51.46, -0.3962 x 51.66, 0.08118
    { 501, 2837, NoLogo, LineMetaDataContent::RapidTransit, 0xc3, 0x69, 0x39 }, // S42 OSM: 9942315 WD: Q15118875 52.46, 13.28 x 52.55, 13.48
    { 295, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x23, 0xa6, 0x38 }, // T1 OSM: 9953164 49.15, -0.3663 x 49.2, -0.329
    { 391, NoLogo, 568, LineMetaDataContent::RapidTransit, 0x29, 0x38, 0x38 }, // S12 OSM: 9959066 WD: Q26828150 45.36, 9.159 x 45.5, 9.319
    { 1, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0x9e, 0xe3 }, // 4 OSM: 9964886 52.25, 10.51 x 52.27, 10.56
    { 148, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0x9c, 0xdd }, // 9 OSM: 10015448 53.41, 14.49 x 53.47, 14.55
    { 220, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xe2, 0x0, 0xa }, // 21A OSM: 10034064 49.4, 8.675 x 49.41, 8.693
    { 90, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xe3, 0x0, 0xb }, // 10 OSM: 10082596 52.25, 10.51 x 52.31, 10.54
    { 826, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xff, 0x88, 0xbb }, // EDid;Roch OSM: 10310648 53.41, -2.28 x 53.62, -2.088
    { 210, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x88, 0x77, 0x66 }, // EDid;Sh&C OSM: 10310683 53.41, -2.28 x 53.58, -2.089
    { 836, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0x66, 0xbb }, // Airp;Vict;Dean OSM: 10314875 WD: Q22712167 53.37, -2.297 x 53.49, -2.238
    { 851, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xff, 0x77, 0x0 }, // MCUK;Asht OSM: 10320090 53.47, -2.297 x 53.49, -2.098
    { 861, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0xcc, 0xff }, // Asht;Eccl OSM: 10326857 WD: Q22087023 53.47, -2.334 x 53.49, -2.098
    { 871, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x88, 0x11, 0x88 }, // Altr;Picc OSM: 10328430 WD: Q22087020 53.39, -2.347 x 53.48, -2.23
    { 881, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xff, 0xbb, 0x0 }, // Bury;Picc OSM: 10334672 53.48, -2.321 x 53.59, -2.226
    { 891, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0x88, 0x0 }, // Bury;Altr OSM: 10334764 53.39, -2.347 x 53.59, -2.226
    { 901, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0x0, 0x0 }, // TrfC;Crmp OSM: 10334906 53.46, -2.348 x 53.52, -2.227
    { 439, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xff, 0xa5, 0x0 }, // 22 OSM: 10396259 WD: Q2885972 52.07, 5.112 x 52.09, 5.184
    { 911, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xdb, 0x61, 0x98 }, // 305 OSM: 10409526 51.46, 7.152 x 51.48, 7.324
    { 915, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x40, 0x55, 0x8e }, // 309 OSM: 10409567 51.44, 7.297 x 51.46, 7.337
    { 919, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xe2, 0x8e, 0x7 }, // 316 OSM: 10409642 51.48, 7.16 x 51.53, 7.272
    { 80, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x96, 0x36, 0x8b }, // 1 OSM: 10413963 51.2, 4.388 x 51.26, 4.421
    { 923, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0x0, 0x6d, 0xb6 }, // RB 32 OSM: 10432813 WD: Q7388251 51.43, 6.775 x 51.58, 7.459
    { 929, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0xc7, 0x2a, 0x80 }, // L5 OSM: 10443588 46.18, 5.999 x 46.22, 6.144
    { 932, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0x0, 0xb3, 0xb9 }, // L6 OSM: 10447940 46.1, 5.821 x 46.22, 6.144
    { 935, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0xdc, 0x91, 0x1b }, // L4 OSM: 10464491 46.17, 6.121 x 46.32, 6.237
    { 140, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x0, 0xac, 0xe7 }, // 17 OSM: 10486182 46.19, 6.125 x 46.2, 6.232
    { 222, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xff, 0x0, 0x0 }, // A OSM: 10486983 47.83, 1.9 x 47.93, 1.939
    { 226, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0x72, 0x27, 0x7b }, // B OSM: 10494114 47.9, 1.854 x 47.91, 1.977
    { 938, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0x6c, 0x9d, 0x40 }, // L3 OSM: 10505987 45.91, 6.121 x 46.32, 6.703
    { 575, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0xbf, 0x35, 0x27 }, // L1 OSM: 10521809 46.17, 6.121 x 46.4, 6.58
    { 579, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, 0x0, 0x85, 0xc4 }, // L2 OSM: 10526246 45.9, 6.116 x 46.32, 6.362
    { 8, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xff, 0xcc, 0x11 }, // 2 OSM: 10547015 51, 3.709 x 51.05, 3.772
    { 148, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xff, 0x2e, 0x17 }, // 9 OSM: 10547655 48.34, 10.89 x 48.37, 10.9
    { 222, NoLogo, NoLogo, LineMetaDataContent::Tramway, 0xe3, 0x2, 0x8c }, // A OSM: 10551319 48.38, -4.556 x 48.43, -4.444
    { 397, 2852, 493, LineMetaDataContent::Subway, 0x82, 0xbb, 0x32 }, // M2 OSM: 10760559 WD: Q2519385 45.4, 9.145 x 45.55, 9.44
    { 478, 2872, 493, LineMetaDataContent::Subway, 0xe2, 0xe1, 0x1d }, // M3 OSM: 10788272 WD: Q2519355 45.43, 9.163 x 45.53, 9.257
    { 264, 2892, 493, LineMetaDataContent::Subway, 0xeb, 0x31, 0x2e }, // M1 OSM: 10803053 WD: Q2400801 45.46, 9.084 x 45.54, 9.238
};

static constexpr const auto line_data_count = sizeof(line_data) / sizeof(LineMetaDataContent);

static inline constexpr uint16_t Bucket(uint16_t index) { return line_data_count + index; }

static const int16_t line_data_bucketTable[] = {
    461, 285, 150, -1,
    631, 603, 633, 637, 632, 635, 636, 639, 716, 638, 574, -1,
    220, 219, 734, 218, 735, 215, 736, 303, 482, 216, 545, -1,
    405, 621, 403, 295, 626, 149, 326, 582, 585, -1,
    234, 670, 672, 678, -1,
    411, 183, -1,
    99, 65, 143, -1,
    590, 247, -1,
    408, 163, 185, -1,
    746, 745, -1,
    239, 232, 237, 667, 666, -1,
    684, 197, 682, -1,
    106, 105, 341, 107, 231, 446, 507, 286, 152, 448, 447, 113, 287, 434, -1,
    660, 659, -1,
    609, 610, 611, 617, 618, -1,
    538, 269, 270, 300, -1,
    499, 502, 495, 503, 504, 674, 506, 505, -1,
    16, 557, 556, 558, 292, 15, 20, 19, 154, 554, 555, 18, 17, 316, 370, 371, 479, 372, 373, 579, 580, 21, 12, -1,
    379, 680, 384, 681, 378, 389, 383, 390, 344, 484, 318, 325, 483, 324, 396, 486, -1,
    533, 125, -1,
    226, 227, 228, 235, 225, 178, 109, 115, 8, 11, -1,
    729, 731, 732, -1,
    710, 712, -1,
    747, 739, 740, -1,
    353, 361, 354, 362, 356, 357, 358, 366, 359, 644, 241, -1,
    751, 190, 191, -1,
    468, 398, -1,
    428, 429, 652, 592, 653, 460, 293, 608, 599, 630, 614, 616, -1,
    528, 266, 539, 264, 529, 302, 304, 305, 306, 309, 310, -1,
    570, 573, 50, 51, 171, 665, 566, 170, 547, 548, 549, 550, 551, -1,
    151, 156, 648, 157, 272, -1,
    79, 581, -1,
    335, 336, 230, -1,
    416, 417, 315, 321, 256, 418, 419, 511, -1,
    58, 59, 126, -1,
    251, 250, -1,
    144, 145, 255, 248, 254, -1,
    142, 136, 141, -1,
    521, 343, 523, -1,
    82, 83, 85, -1,
    4, 43, 27, 29, 26, 28, 6, 44, 10, 94, -1,
    249, 346, 657, 347, 368, 656, 655, 258, 265, 271, 273, 102, 103, 101, -1,
    160, 708, 627, -1,
    726, 728, 724, 725, 727, -1,
    407, 623, 583, -1,
    748, 481, -1,
    444, 445, -1,
    692, 475, 693, 694, 695, 696, 687, -1,
    673, 240, -1,
    753, 752, 348, 719, 198, -1,
    647, 593, 650, 619, -1,
    423, 425, -1,
    647, 593, -1,
    40, 578, 41, 49, -1,
    537, 246, 267, 268, 66, 56, -1,
    701, 128, 168, 195, 213, 175, 194, 700, 686, 196, 189, 155, 192, 186, 187, 177, 164, 193, -1,
    153, 32, 33, 202, 706, 199, 205, 203, -1,
    111, 374, -1,
    409, 181, 283, 410, -1,
    430, 431, -1,
    54, 63, -1,
    519, 525, 526, 345, 520, 522, -1,
    68, 80, 86, 69, 78, 76, -1,
    36, 34, 37, 38, 39, 35, 330, -1,
    2, 48, 127, 23, 24, 1, 3, 110, 705, 607, 717, 116, 165, 96, 92, 91, 73, 90, 89, -1,
    147, 243, -1,
    279, 276, 532, 275, 459, 280, 282, 281, -1,
    288, 289, 290, -1,
    718, 715, -1,
    622, 620, 401, 602, 640, 624, 406, 323, 675, 450, 584, -1,
    458, 455, 456, 451, 452, 454, 342, -1,
    465, 463, -1,
    685, 489, 742, 488, -1,
    477, 393, -1,
    688, 690, -1,
    130, 129, 560, 131, -1,
    133, 697, 134, 698, 469, -1,
    118, 404, -1,
    629, 654, -1,
    415, 414, -1,
    737, 422, 426, 427, -1,
    540, 543, 542, 261, 42, 262, 541, -1,
    61, 263, 62, 60, -1,
    214, 217, -1,
    564, 568, 571, 572, 569, -1,
    387, 552, 553, 471, 169, -1,
    535, 536, -1,
    334, 337, -1,
    320, 510, 212, 512, 513, 437, 514, 515, 516, -1,
    201, 200, 204, -1,
    349, 723, 509, 369, 720, 367, -1,
    527, 224, 524, -1,
    478, 114, -1,
    229, 236, -1,
    5, 25, 46, 30, 47, 0, 299, 9, 161, -1,
    211, 209, 210, 577, 207, -1,
    245, 242, -1,
    274, 297, 278, 721, -1,
    589, 586, -1,
    605, 360, 365, 257, 363, 233, -1,
    433, 606, 651, 677, 474, -1,
    601, 600, -1,
    284, 182, -1,
    135, 223, 137, 138, 222, 386, -1,
    97, 162, -1,
    77, 67, -1,
    689, 703, -1,
    31, 645, -1,
    333, 722, -1,
};

static const constexpr LineMetaDataQuadTreeDepthIndex line_data_depthOffsets[] = {
    { 28, 0 },
    { 26, 1 },
    { 25, 3 },
    { 24, 8 },
    { 23, 28 },
    { 22, 63 },
    { 21, 107 },
    { 20, 168 },
    { 19, 206 },
    { 18, 227 },
};

static const constexpr LineMetaDataZIndex line_data_zquadtree[] = {
    { 74, Bucket(0) }, // 34.75, -9.469 x 61.59, 17.37
    { 1190, Bucket(4) }, // 48.17, -2.758 x 54.88, 3.952
    { 1196, Bucket(16) }, // 48.17, 3.952 x 54.88, 10.66
    { 4762, Bucket(28) }, // 48.17, 0.597 x 51.53, 3.952
    { 4775, Bucket(38) }, // 44.81, 7.308 x 48.17, 10.66
    { 4786, Bucket(43) }, // 48.17, 7.308 x 51.53, 10.66
    { 4787, 319 }, // 51.53, 7.308 x 54.88, 10.66
    { 4792, Bucket(46) }, // 48.17, 10.66 x 51.53, 14.02
    { 19006, 702 }, // 44.81, 2.275 x 46.49, 3.952
    { 19043, 576 }, // 49.85, -1.081 x 51.53, 0.597
    { 19050, Bucket(50) }, // 48.17, 2.275 x 49.85, 3.952
    { 19051, Bucket(53) }, // 49.85, 2.275 x 51.53, 3.952
    { 19093, 252 }, // 46.49, 3.952 x 48.17, 5.63
    { 19094, Bucket(57) }, // 44.81, 5.63 x 46.49, 7.308
    { 19101, Bucket(60) }, // 46.49, 7.308 x 48.17, 8.986
    { 19102, Bucket(66) }, // 44.81, 8.986 x 46.49, 10.66
    { 19103, 206 }, // 46.49, 8.986 x 48.17, 10.66
    { 19125, Bucket(70) }, // 46.49, 10.66 x 48.17, 12.34
    { 19127, Bucket(85) }, // 46.49, 12.34 x 48.17, 14.02
    { 19133, 707 }, // 46.49, 14.02 x 48.17, 15.7
    { 19137, Bucket(88) }, // 49.85, 3.952 x 51.53, 5.63
    { 19139, Bucket(94) }, // 49.85, 5.63 x 51.53, 7.308
    { 19140, Bucket(99) }, // 51.53, 3.952 x 53.2, 5.63
    { 19144, Bucket(108) }, // 48.17, 7.308 x 49.85, 8.986
    { 19150, Bucket(132) }, // 51.53, 8.986 x 53.2, 10.66
    { 19151, Bucket(149) }, // 53.2, 8.986 x 54.88, 10.66
    { 19173, 332 }, // 53.2, 10.66 x 54.88, 12.34
    { 19174, Bucket(152) }, // 51.53, 12.34 x 53.2, 14.02
    { 75999, 663 }, // 47.33, -0.2419 x 48.17, 0.597
    { 76023, 744 }, // 47.33, 1.436 x 48.17, 2.275
    { 76171, 443 }, // 49.01, -0.2419 x 49.85, 0.597
    { 76180, Bucket(163) }, // 53.2, -2.758 x 54.04, -1.92
    { 76182, Bucket(167) }, // 53.2, -1.92 x 54.04, -1.081
    { 76193, 339 }, // 49.01, 0.597 x 49.85, 1.436
    { 76200, 604 }, // 48.17, 2.275 x 49.01, 3.114
    { 76206, 628 }, // 49.85, 3.114 x 50.69, 3.952
    { 76207, 480 }, // 50.69, 3.114 x 51.53, 3.952
    { 76368, 180 }, // 44.81, 3.952 x 45.65, 4.791
    { 76376, 464 }, // 44.81, 5.63 x 45.65, 6.469
    { 76377, Bucket(170) }, // 45.65, 5.63 x 46.49, 6.469
    { 76380, 518 }, // 46.49, 5.63 x 47.33, 6.469
    { 76382, 184 }, // 46.49, 6.469 x 47.33, 7.308
    { 76407, Bucket(174) }, // 47.33, 8.147 x 48.17, 8.986
    { 76408, Bucket(186) }, // 44.81, 8.986 x 45.65, 9.824
    { 76410, 352 }, // 44.81, 9.824 x 45.65, 10.66
    { 76509, 485 }, // 47.33, 12.34 x 48.17, 13.18
    { 76548, Bucket(190) }, // 49.85, 3.952 x 50.69, 4.791
    { 76549, Bucket(193) }, // 50.69, 3.952 x 51.53, 4.791
    { 76559, Bucket(206) }, // 50.69, 6.469 x 51.53, 7.308
    { 76560, Bucket(218) }, // 51.53, 3.952 x 52.36, 4.791
    { 76576, Bucket(232) }, // 48.17, 7.308 x 49.01, 8.147
    { 76578, Bucket(238) }, // 48.17, 8.147 x 49.01, 8.986
    { 76579, Bucket(241) }, // 49.01, 8.147 x 49.85, 8.986
    { 76582, Bucket(245) }, // 49.85, 8.147 x 50.69, 8.986
    { 76584, Bucket(254) }, // 48.17, 8.986 x 49.01, 9.824
    { 76606, Bucket(258) }, // 53.2, 9.824 x 54.04, 10.66
    { 76673, Bucket(261) }, // 49.01, 10.66 x 49.85, 11.5
    { 76679, Bucket(267) }, // 50.69, 11.5 x 51.53, 12.34
    { 76685, 669 }, // 50.69, 12.34 x 51.53, 13.18
    { 76687, Bucket(271) }, // 50.69, 13.18 x 51.53, 14.02
    { 76692, Bucket(275) }, // 53.2, 10.66 x 54.04, 11.5
    { 76699, Bucket(279) }, // 52.36, 13.18 x 53.2, 14.02
    { 76708, Bucket(290) }, // 49.85, 14.02 x 50.69, 14.86
    { 303965, 462 }, // 47.75, -1.92 x 48.17, -1.5
    { 304266, 750 }, // 48.17, -4.856 x 48.59, -4.436
    { 304701, Bucket(305) }, // 51.11, -0.2419 x 51.53, 0.1775
    { 304719, 159 }, // 52.78, -1.5 x 53.2, -1.081
    { 304722, Bucket(309) }, // 53.2, -2.339 x 53.62, -1.92
    { 304730, 713 }, // 53.2, -1.5 x 53.62, -1.081
    { 304801, Bucket(315) }, // 48.59, 2.275 x 49.01, 2.694
    { 304830, Bucket(319) }, // 50.69, 3.533 x 51.11, 3.952
    { 305475, Bucket(322) }, // 45.23, 4.372 x 45.65, 4.791
    { 305484, 453 }, // 45.65, 4.791 x 46.07, 5.211
    { 305511, 741 }, // 46.07, 6.05 x 46.49, 6.469
    { 305617, 473 }, // 46.91, 7.308 x 47.33, 7.727
    { 305620, Bucket(325) }, // 47.33, 7.308 x 47.75, 7.727
    { 305628, 704 }, // 47.33, 8.147 x 47.75, 8.566
    { 305630, Bucket(333) }, // 47.33, 8.566 x 47.75, 8.986
    { 305633, Bucket(336) }, // 45.23, 8.986 x 45.65, 9.405
    { 306039, 661 }, // 47.75, 12.76 x 48.17, 13.18
    { 306195, 355 }, // 50.27, 4.372 x 50.69, 4.791
    { 306196, Bucket(342) }, // 50.69, 3.952 x 51.11, 4.372
    { 306197, Bucket(347) }, // 51.11, 3.952 x 51.53, 4.372
    { 306198, Bucket(350) }, // 50.69, 4.372 x 51.11, 4.791
    { 306199, Bucket(347) }, // 51.11, 4.372 x 51.53, 4.791
    { 306237, Bucket(353) }, // 51.11, 6.469 x 51.53, 6.888
    { 306238, Bucket(358) }, // 50.69, 6.888 x 51.11, 7.308
    { 306239, 322 }, // 51.11, 6.888 x 51.53, 7.308
    { 306241, 664 }, // 51.95, 3.952 x 52.36, 4.372
    { 306242, 544 }, // 51.53, 4.372 x 51.95, 4.791
    { 306337, Bucket(365) }, // 48.59, 8.986 x 49.01, 9.405
    { 306366, 172 }, // 50.69, 10.24 x 51.11, 10.66
    { 306383, Bucket(384) }, // 52.78, 8.566 x 53.2, 8.986
    { 306406, 376 }, // 52.36, 9.405 x 52.78, 9.824
    { 306424, Bucket(393) }, // 53.2, 9.824 x 53.62, 10.24
    { 306425, 517 }, // 53.62, 9.824 x 54.04, 10.24
    { 306688, Bucket(396) }, // 48.17, 10.66 x 48.59, 11.08
    { 306718, 146 }, // 50.69, 11.92 x 51.11, 12.34
    { 306719, 139 }, // 51.11, 11.92 x 51.53, 12.34
    { 306733, Bucket(401) }, // 49.43, 13.18 x 49.85, 13.6
    { 306741, Bucket(404) }, // 51.11, 12.34 x 51.53, 12.76
    { 306750, Bucket(407) }, // 50.69, 13.6 x 51.11, 14.02
    { 306761, Bucket(414) }, // 51.95, 11.5 x 52.36, 11.92
    { 306782, Bucket(421) }, // 54.04, 11.92 x 54.46, 12.34
    { 306796, Bucket(429) }, // 52.36, 13.18 x 52.78, 13.6
    { 306880, Bucket(449) }, // 51.53, 14.02 x 51.95, 14.44
    { 306898, Bucket(452) }, // 53.2, 14.44 x 53.62, 14.86
    { 1215847, Bucket(461) }, // 47.12, -1.71 x 47.33, -1.5
    { 1215960, 399 }, // 47.33, -0.6613 x 47.54, -0.4516
    { 1216336, 397 }, // 47.33, 0.597 x 47.54, 0.8067
    { 1216380, 743 }, // 47.75, 1.855 x 47.96, 2.065
    { 1218714, Bucket(465) }, // 49.01, -0.4516 x 49.22, -0.2419
    { 1218805, 709 }, // 51.32, -0.2419 x 51.53, -0.03218
    { 1218878, 259 }, // 52.78, -1.29 x 52.99, -1.081
    { 1218889, 730 }, // 53.41, -2.339 x 53.62, -2.129
    { 1219205, Bucket(468) }, // 48.8, 2.275 x 49.01, 2.484
    { 1221936, Bucket(480) }, // 45.65, 4.791 x 45.86, 5.001
    { 1221991, 253 }, // 47.12, 5.001 x 47.33, 5.211
    { 1222017, Bucket(488) }, // 45.02, 5.63 x 45.23, 5.84
    { 1222044, Bucket(491) }, // 46.07, 6.05 x 46.28, 6.259
    { 1222087, 176 }, // 47.12, 5.84 x 47.33, 6.05
    { 1222403, 173 }, // 45.02, 7.518 x 45.23, 7.727
    { 1222468, Bucket(496) }, // 46.91, 7.308 x 47.12, 7.518
    { 1222483, Bucket(499) }, // 47.54, 7.518 x 47.75, 7.727
    { 1222493, Bucket(502) }, // 47.96, 7.727 x 48.17, 7.937
    { 1222509, 671 }, // 47.12, 8.566 x 47.33, 8.776
    { 1222514, 364 }, // 47.33, 8.356 x 47.54, 8.566
    { 1222533, 188 }, // 45.44, 8.986 x 45.65, 9.195
    { 1222554, 174 }, // 45.65, 9.615 x 45.86, 9.824
    { 1224015, Bucket(507) }, // 47.12, 11.29 x 47.33, 11.5
    { 1224053, Bucket(513) }, // 47.96, 11.5 x 48.17, 11.71
    { 1224157, 658 }, // 47.96, 12.76 x 48.17, 12.97
    { 1224780, 476 }, // 50.27, 4.372 x 50.48, 4.582
    { 1224786, Bucket(516) }, // 50.69, 4.162 x 50.9, 4.372
    { 1224792, Bucket(519) }, // 50.69, 4.372 x 50.9, 4.582
    { 1224796, Bucket(522) }, // 51.11, 4.372 x 51.32, 4.582
    { 1224844, 277 }, // 48.59, 6.05 x 48.8, 6.259
    { 1224860, 641 }, // 49.43, 6.05 x 49.64, 6.259
    { 1224950, Bucket(527) }, // 51.11, 6.679 x 51.32, 6.888
    { 1224953, Bucket(535) }, // 50.9, 6.888 x 51.11, 7.098
    { 1224957, 530 }, // 51.32, 6.888 x 51.53, 7.098
    { 1224959, Bucket(540) }, // 51.32, 7.098 x 51.53, 7.308
    { 1224966, Bucket(543) }, // 51.95, 4.162 x 52.15, 4.372
    { 1224969, Bucket(549) }, // 51.74, 4.372 x 51.95, 4.582
    { 1224998, Bucket(555) }, // 51.95, 5.001 x 52.15, 5.211
    { 1225008, 498 }, // 52.36, 4.791 x 52.57, 5.001
    { 1225255, 22 }, // 48.8, 8.356 x 49.01, 8.566
    { 1225273, Bucket(558) }, // 49.22, 8.566 x 49.43, 8.776
    { 1225301, 308 }, // 51.32, 7.308 x 51.53, 7.518
    { 1225321, Bucket(561) }, // 50.06, 8.566 x 50.27, 8.776
    { 1225535, Bucket(571) }, // 52.99, 8.776 x 53.2, 8.986
    { 1225626, 385 }, // 52.36, 9.615 x 52.57, 9.824
    { 1225647, Bucket(575) }, // 52.15, 10.45 x 52.36, 10.66
    { 1226877, 140 }, // 51.32, 11.92 x 51.53, 12.13
    { 1226933, 432 }, // 49.64, 13.18 x 49.85, 13.39
    { 1226960, 296 }, // 50.69, 12.34 x 50.9, 12.55
    { 1227001, Bucket(582) }, // 50.9, 13.6 x 51.11, 13.81
    { 1227044, 70 }, // 51.95, 11.5 x 52.15, 11.71
    { 1227051, Bucket(586) }, // 51.74, 12.13 x 51.95, 12.34
    { 1227083, 84 }, // 53.41, 11.29 x 53.62, 11.5
    { 1227162, Bucket(589) }, // 52.36, 12.97 x 52.57, 13.18
    { 1227184, 88 }, // 52.36, 13.18 x 52.57, 13.39
    { 1227186, Bucket(592) }, // 52.36, 13.39 x 52.57, 13.6
    { 1227192, 294 }, // 52.36, 13.6 x 52.57, 13.81
    { 1227266, Bucket(602) }, // 48.17, 14.23 x 48.38, 14.44
    { 1227380, 394 }, // 51.11, 14.86 x 51.32, 15.07
    { 1227523, Bucket(608) }, // 51.74, 14.23 x 51.95, 14.44
    { 1227593, Bucket(611) }, // 53.41, 14.44 x 53.62, 14.65
    { 4863988, 662 }, // 47.96, 0.1775 x 48.07, 0.2824
    { 4874970, 442 }, // 49.43, 0.07268 x 49.53, 0.1775
    { 4875681, 711 }, // 53.31, -1.5 x 53.41, -1.395
    { 4876817, Bucket(616) }, // 48.69, 2.275 x 48.8, 2.38
    { 4876820, 400 }, // 48.8, 2.275 x 48.9, 2.38
    { 4876821, 470 }, // 48.9, 2.275 x 49.01, 2.38
    { 4888069, 466 }, // 45.13, 5.63 x 45.23, 5.735
    { 4888071, 467 }, // 45.13, 5.735 x 45.23, 5.84
    { 4888177, 487 }, // 46.18, 6.05 x 46.28, 6.154
    { 4889874, 340 }, // 46.91, 7.413 x 47.02, 7.518
    { 4889932, 691 }, // 47.54, 7.518 x 47.65, 7.622
    { 4889974, 132 }, // 47.96, 7.832 x 48.07, 7.937
    { 4890058, Bucket(619) }, // 47.33, 8.461 x 47.44, 8.566
    { 4895899, 167 }, // 45.34, 11.82 x 45.44, 11.92
    { 4896213, 117 }, // 48.07, 11.5 x 48.17, 11.61
    { 4899147, Bucket(626) }, // 50.79, 4.267 x 50.9, 4.372
    { 4899185, 420 }, // 51.21, 4.372 x 51.32, 4.477
    { 4899867, 567 }, // 52.05, 4.267 x 52.15, 4.372
    { 4899889, 664 }, // 52.05, 4.372 x 52.15, 4.477
    { 4899891, 664 }, // 52.05, 4.477 x 52.15, 4.582
    { 4899995, 733 }, // 52.05, 5.106 x 52.15, 5.211
    { 4901082, 338 }, // 49.43, 8.461 x 49.53, 8.566
    { 4901207, 546 }, // 51.42, 7.413 x 51.53, 7.518
    { 4901395, 699 }, // 48.69, 9.09 x 48.8, 9.195
    { 4901510, Bucket(632) }, // 48.38, 9.929 x 48.48, 10.03
    { 4907017, Bucket(635) }, // 48.27, 10.87 x 48.38, 10.98
    { 4907351, 14 }, // 51.42, 10.77 x 51.53, 10.87
    { 4907491, 108 }, // 50.79, 12.03 x 50.9, 12.13
    { 4907509, Bucket(638) }, // 51.42, 11.92 x 51.53, 12.03
    { 4907842, 534 }, // 50.69, 12.45 x 50.79, 12.55
    { 4907860, Bucket(645) }, // 51.32, 12.34 x 51.42, 12.45
    { 4908007, 531 }, // 51, 13.7 x 51.11, 13.81
    { 4908179, Bucket(648) }, // 52.05, 11.61 x 52.15, 11.71
    { 4908739, 95 }, // 52.47, 13.28 x 52.57, 13.39
    { 4908745, 260 }, // 52.47, 13.39 x 52.57, 13.49
    { 4908746, 45 }, // 52.36, 13.49 x 52.47, 13.6
    { 4909065, 208 }, // 48.27, 14.23 x 48.38, 14.33
    { 4909522, 395 }, // 51.11, 14.96 x 51.21, 15.07
    { 19499431, 714 }, // 49.17, -0.3992 x 49.22, -0.3468
    { 19500893, 634 }, // 51.47, -0.137 x 51.53, -0.08461
    { 19507289, 625 }, // 48.85, 2.38 x 48.9, 2.432
    { 19550980, 457 }, // 45.76, 4.791 x 45.81, 4.844
    { 19553802, 508 }, // 46.49, 6.626 x 46.54, 6.679
    { 19559496, 472 }, // 46.91, 7.413 x 46.96, 7.465
    { 19559730, Bucket(651) }, // 47.54, 7.57 x 47.59, 7.622
    { 19584252, 148 }, // 47.23, 11.4 x 47.28, 11.45
    { 19599553, 664 }, // 52, 4.372 x 52.05, 4.424
    { 19599554, 544 }, // 51.95, 4.424 x 52, 4.477
    { 19599555, 664 }, // 52, 4.424 x 52.05, 4.477
    { 19599560, 544 }, // 51.95, 4.477 x 52, 4.529
    { 19599561, 664 }, // 52, 4.477 x 52.05, 4.529
    { 19599563, 664 }, // 52, 4.529 x 52.05, 4.582
    { 19603605, 649 }, // 48.54, 7.727 x 48.59, 7.78
    { 19605583, Bucket(654) }, // 48.75, 9.143 x 48.8, 9.195
    { 19628069, 749 }, // 48.33, 10.87 x 48.38, 10.93
    { 19629405, 13 }, // 51.47, 10.77 x 51.53, 10.82
    { 19629808, 391 }, // 50.48, 12.13 x 50.53, 12.18
    { 19630037, 377 }, // 51.47, 11.92 x 51.53, 11.97
    { 19634958, 93 }, // 52.47, 13.34 x 52.52, 13.39
    { 78417525, Bucket(657) }, // 49.4, 8.671 x 49.43, 8.697
};
}
