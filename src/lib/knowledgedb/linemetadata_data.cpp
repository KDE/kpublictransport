/*
    SPDX-FileCopyrightText: OpenStreetMap contributors
    SPDX-License-Identifier: ODbL-1.0

    Generated code based on data from OpenStreetMap (ODbL) and Wikidata (CC0), do not edit!
*/

#include "linemetadata_p.h"

namespace KPublicTransport {

static const char line_name_stringtab[] = {
    "U70\0"
    "S75\0"
    "M4\0"
    "M5\0"
    "U12\0"
    "M8\0"
    "318\0"
    "S16\0"
    "M6\0"
    "STH\0"
    "EAST\0"
    "S7\0"
    "S5\0"
    "S8\0"
    "S2\0"
    "S11\0"
    "M13\0"
    "S1\0"
    "M10\0"
    "TER 21\0"
    "U13\0"
    "S63\0"
    "S61\0"
    "S68\0"
    "TER 62\0"
    "1037\0"
    "888\0"
    "U1\0"
    "U2\0"
    "U3\0"
    "U4\0"
    "U5\0"
    "U6\0"
    "U7\0"
    "U8\0"
    "U9\0"
    "U11\0"
    "U14\0"
    "U15\0"
    "U19\0"
    "U72\0"
    "U76\0"
    "U77\0"
    "S60\0"
    "S3\0"
    "1967\0"
    "N27\0"
    "M17\0"
    "S50\0"
    "U79\0"
    "S24\0"
    "WLB\0"
    "RB 58\0"
    "S6\0"
    "TER T1\0"
    "665\0"
    "S4\0"
    "RS 1\0"
    "N17\0"
    "S25\0"
    "KJ\0"
    "3F\0"
    "S46\0"
    "S45\0"
    "N20\0"
    "RB23\0"
    "A3\0"
    "S51\0"
    "FM1\0"
    "MRT Blue\0"
    "Yellow\0"
    "Red\0"
    "86989\0"
    "RE 30\0"
    "RB 12\0"
    "LO\0"
    "FXC\0"
    "LS\0"
    "LSM\0"
    "LM\0"
    "LU\0"
    "614P\0"
    "86996\0"
    "86\0"
    "1049\0"
    "FM2\0"
    "RB 80\0"
    "RB 81\0"
    "24E\0"
    "RB 59\0"
    "181 (SN)\0"
    "S85\0"
    "FL4\0"
    "FL1\0"
    "FL2\0"
    "FL3\0"
    "109\0"
    "657\0"
    "North Jersey Coast\0"
    "RB 48\0"
    "U43\0"
    "1041\0"
    "ATS\0"
    "IK\0"
    "ISL\0"
    "TCL\0"
    "21R\0"
    "AEL\0"
    "EAL\0"
    "TML\0"
    "28E\0"
    "S9\0"
    "Green\0"
    "C-1\0"
    "RI\0"
    "STB\0"
    "U35\0"
    "RB 55\0"
    "SIR1\0"
    "SG\0"
    "25N\0"
    "Q\0"
    "T1 A\0"
    "Bx\0"
    "155\0"
    "TER T2\0"
    "RB 56\0"
    "S47\0"
    "MSC 1908\0"
    "MD-W\0"
    "RE7\0"
    "N10\0"
    "N4\0"
    "N1\0"
    "H5\0"
    "S64\0"
    "Raritan Valley\0"
    "DRL\0"
    "N82\0"
    "Harlem\0"
    "Hudson\0"
    "Port Jervis\0"
    "SFM 2\0"
    "308\0"
    "310\0"
    "306\0"
    "302\0"
    "301\0"
    "S 5\0"
    "Port Jefferson\0"
    "New Haven\0"
    "VMLR\0"
    "Oyster Bay\0"
    "Kingston/Plymouth Line\0"
    "Needham Line\0"
    "Fairmount Line\0"
    "Greenbush Line\0"
    "Middleborough/Lakeville Line\0"
    "Framingham/Worcester\0"
    "H7\0"
    "Main\0"
    "Gladstone\0"
    "Bergen County\0"
    "Morristown\0"
    "Montclair-Boonton\0"
    "DOY\0"
    "WAR\0"
    "Camden\0"
    "Brunswick\0"
    "12E\0"
    "15E\0"
    "RB 13\0"
    "86998\0"
    "91\0"
    "U78\0"
    "1992\0"
    "93\0"
    "94\0"
    "S33\0"
    "N19\0"
    "Zoo Tram\0"
    "S32\0"
    "S10\0"
    "399\0"
    "TMR\0"
    "S29\0"
    "S12\0"
    "H9\0"
    "H8\0"
    "H6\0"
    "S42\0"
    "69\0"
    "S52\0"
    "62A\0"
    "51A\0"
    "28A\0"
    "S28\0"
    "37A\0"
    "RED\0"
    "326\0"
    "639\0"
    "8А\0"
    "38\0"
    "S31\0"
    "СТ\0"
    "2 Салтівська\0"
    "1 Холодногірсько-заводська\0"
    "3 Олексіївська\0"
    "12а\0"
    "SSL\0"
    "RB 40\0"
    "Port Washington\0"
    "TER 22\0"
    "S36\0"
    "SFM3\0"
    "U75\0"
    "86966\0"
    "S20\0"
    "Тр3\0"
    "Тр2\0"
    "Тр4\0"
    "FC1\0"
    "FL5\0"
    "FL6\0"
    "FL7\0"
    "FL8\0"
    "635\0"
    "655\0"
    "631\0"
    "TER 01\0"
    "TER 60\0"
    "86987\0"
    "901\0"
    "S13\0"
    "Μ3\0"
    "RE5\0"
    "RE4\0"
    "Тр1\0"
    "Тр9\0"
    "Тр6\0"
    "7bis\0"
    "Brown\0"
    "Orange\0"
    "100\0"
    "Scala mobile\0"
    "S 8\0"
    "RB14\0"
    "RS 4\0"
    "RE 18\0"
    "RE2\0"
    "RE 15\0"
    "RE1\0"
    "RE3\0"
    "SFM 1\0"
    "SFM 4\0"
    "1047\0"
    "1025\0"
    "1031\0"
    "1057\0"
    "1029\0"
    "1027\0"
    "1051\0"
    "1039\0"
    "1045\0"
    "1033\0"
    "1035\0"
    "1055\0"
    "1053\0"
    "1023\0"
    "U44\0"
    "8 EX\0"
    "SFM7\0"
    "PAO\0"
    "Meadowlands\0"
    "Pascack Valley\0"
    "U46\0"
    "T5\0"
    "C-8\0"
    "Metropolitana\0"
    "Pink\0"
    "U47\0"
    "U41\0"
    "MRT Purple\0"
    "4S\0"
    "TRE\0"
    "S18\0"
    "M-LINE\0"
    "RS 3\0"
    "STY\0"
    "CBTU\0"
    "DPM\0"
    "95\0"
    "UP-N\0"
    "MD-N\0"
    "NCS\0"
    "UP-NW\0"
    "UP-W\0"
    "BNSF\0"
    "HC\0"
    "SWS\0"
    "ME\0"
    "RS 2\0"
    "LBN\0"
    "خط الضاحية الجنوبية لتونس\0"
    "RB55\0"
    "RB20\0"
    "S 5X\0"
    "RB13\0"
    "MTM\0"
    "C-5\0"
    "PH\0"
    "LBS\0"
    "RB49\0"
    "IC LSA<=>BRA\0"
    "U BRA\0"
    "T3\0"
    "T3b\0"
    "Rhônexpress\0"
    "T4\0"
    "9 EX\0"
    "Line 3\0"
    "West Hempstead\0"
    "M1/M2\0"
    "KTL\0"
    "T8\0"
    "97\0"
    "BR\0"
    "SFM 6\0"
    "C11\0"
    "IC 8\0"
    "S19\0"
    "S21\0"
    "Gold\0"
    "Providence/Stoughton Line\0"
    "Franklin Line\0"
    "TRAB\0"
    "Z70\0"
    "PST\0"
    "S70\0"
    "S71\0"
    "Montauk\0"
    "Babylon\0"
    "VLT Cabo - Cajueiro Seco\0"
    "654\0"
    "S210\0"
    "Z50\0"
    "Z30\0"
    "NS\0"
    "m2\0"
    "T6\0"
    "L10 Nord\0"
    "L11\0"
    "L9 Nord\0"
    "86990\0"
    "Tren Urbano\0"
    "A2\0"
    "Tide\0"
    "703\0"
    "Penn\0"
    "S150\0"
    "G30\0"
    "S820\0"
    "G10\0"
    "S30\0"
    "S220\0"
    "G71\0"
    "G70\0"
    "G60\0"
    "G43\0"
    "S80\0"
    "S40\0"
    "S35\0"
    "S34\0"
    "Z60\0"
    "U17\0"
    "U18\0"
    "WTR\0"
    "TDV\0"
    "C-3\0"
    "Π3\0"
    "A1\0"
    "E-W\0"
    "S-N\0"
    "R6\0"
    "R60\0"
    "R5\0"
    "R50\0"
    "U71\0"
    "U83\0"
    "U73\0"
    "R2Sud\0"
    "HVL\0"
    "47B\0"
    "R2\0"
    "R3\0"
    "U49\0"
    "R4\0"
    "R8\0"
    "UMRT1\0"
    "RT2\0"
    "RG1\0"
    "Expo Line\0"
    "Millennium Line\0"
    "Canada Line\0"
    "U42\0"
    "U45\0"
    "R12\0"
    "615P\0"
    "L9 Sud\0"
    "NL1\0"
    "R11\0"
    "R13\0"
    "R14\0"
    "R15\0"
    "RE6\0"
    "704\0"
    "701\0"
    "Sul\0"
    "N2\0"
    "BLUE\0"
    "GREEN\0"
    "ORANGE\0"
    "620\0"
    "Manchester Airport - Manchester Victoria\0"
    "North Clyde\0"
    "North Berwick\0"
    "Maryhill\0"
    "TL 1\0"
    "Santa Cruz\0"
    "Japeri\0"
    "505\0"
    "507\0"
    "610\0"
    "615\0"
    "614\0"
    "751\0"
    "761P\0"
    "SN 5\0"
    "T-A\0"
    "T1 R\0"
    "18E\0"
    "706\0"
    "705\0"
    "RB22\0"
    "25E\0"
    "C13\0"
    "MSC\0"
    "L12\0"
    "S14\0"
    "Тр8\0"
    "U74\0"
    "Τ6\0"
    "Τ7\0"
    "S43\0"
    "S81\0"
    "SIL\0"
    "TL-1\0"
    "TL-2\0"
    "T3a\0"
    "T7\0"
    "RB10\0"
    "Orlyval\0"
    "CDGVAL\0"
    "Luas Green Line\0"
    "DART\0"
    "C-2\0"
    "C14\0"
    "C15\0"
    "Central\0"
    "S41\0"
    "L-17\0"
    "S62\0"
    "RL1\0"
    "3bis\0"
    "I2\0"
    "YL\0"
    "Silver\0"
    "510\0"
    "NWK–WTC\0"
    "Bakerloo\0"
    "Hammersmith & City\0"
    "Circle\0"
    "Waterloo & City\0"
    "Jubilee\0"
    "Metropolitan\0"
    "District\0"
    "CAT\0"
    "NSL\0"
    "RB66\0"
    "Bury - Manchester Piccadilly\0"
    "Northern\0"
    "MM\0"
    "BGL\0"
    "THZ1\0"
    "RB51\0"
    "仙台市南北線 (Sendai Namboku Line)\0"
    "仙台市東西線 (Sendai Tozai Line)\0"
    "L4A\0"
    "Verde\0"
    "Laranja\0"
    "Vermelha\0"
    "Amarela\0"
    "Azul\0"
    "Broadway Subway\0"
    "ODEA\0"
    "ADEO\0"
    "VOBA\0"
    "AVOL\0"
    "APOR\0"
    "B-L\0"
    "B-WA\0"
    "S-L\0"
    "TG-B\0"
    "SI-WA\0"
    "IC 1\0"
    "IC 5\0"
    "IC 2\0"
    "IC 3\0"
    "IC 51\0"
    "IC 21\0"
    "IR 26\0"
    "IR 27\0"
    "IR 75\0"
    "IR 46\0"
    "IR 70\0"
    "IC 6\0"
    "IC 61\0"
    "T2B\0"
    "IR 15\0"
    "IR 37\0"
    "RB 43\0"
    "IR 16\0"
    "IR 36\0"
    "IR 17\0"
    "IR 90\0"
    "U29\0"
    "U34\0"
    "S 9\0"
    "RB24\0"
    "L10\0"
    "L9\0"
    "Z\0"
    "ML1\0"
    "ML2\0"
    "ML3\0"
    "I1\0"
    "R2Nord\0"
    "R7\0"
    "B1\0"
    "B2\0"
    "C-10\0"
    "C-7\0"
    "4a\0"
    "WCE\0"
    "Conexão Metrô-Aeroporto\0"
    "RMGL\0"
    "RD\0"
    "SV\0"
    "BL\0"
    "GR\0"
    "L1B\0"
    "PATCO\0"
    "HOB–WTC\0"
    "HOB–33\0"
    "JSQ–33\0"
    "VLT Curado-Cajueiro Seco\0"
    "BSL\0"
    "MFL\0"
    "NHSL\0"
    "Μ1\0"
    "Μ2\0"
    "ML4\0"
    "Tranvía\0"
    "DTL\0"
    "NEL\0"
    "CCL\0"
    "EWL\0"
    "Pink Line\0"
    "BTS Silom\0"
    "U AVO\0"
    "AG\0"
    "SP\0"
    "941\0"
    "金山(Jinshan)\0"
    "G44\0"
    "S506\0"
    "G80\0"
    "G50\0"
    "Blue Line\0"
    "Violet Line\0"
    "Yellow Line\0"
    "AEx\0"
    "Magenta Line\0"
    "浦江\0"
    "311\0"
    "Red Line\0"
    "环\0"
    "西郊\0"
    "S 6\0"
    "S27\0"
    "S15\0"
    "JRL\0"
    "WES\0"
    "S26\0"
    "RB 32\0"
    "JL\0"
    "S17\0"
    "ExpressTram\0"
    "RB 57\0"
    "T11\0"
    "Π4\0"
    "Π1\0"
    "Π2\0"
    "25S\0"
    "201\0"
    "42X\0"
    "TGM\0"
    "43X\0"
    "GC\0"
    "L10 Sud\0"
    "G·J\0"
    "902\0"
    "750\0"
    "321\0"
    "1720\0"
    "GG\0"
    "56A\0"
    "59A\0"
    "59B\0"
    "Circular\0"
    "MSC 621\0"
    "MNC\0"
    "RE 22\0"
    "C-4\0"
    "C-9\0"
    "СТ-2\0"
    "NT\0"
    "SA\0"
    "Aqua Line\0"
    "exo1\0"
    "exo4\0"
    "exo2\0"
    "SR\0"
    "SY\0"
    "MG\0"
    "OM\0"
    "DT\0"
    "exo5\0"
    "KD\0"
    "exo3\0"
    "U16\0"
    "捷運紅線 (新北投支線)\0"
    "Z72\0"
    "RN\0"
    "KS-AE\0"
    "F3\0"
    "SS\0"
    "JN\0"
    "Orange Line\0"
    "S44\0"
    "U GUS\0"
    "U MCS\0"
    "ACE\0"
    "SMART\0"
    "10AB\0"
    "9AB\0"
    "8AB\0"
    "2AB\0"
    "HN\0"
    "Local\0"
    "APM\0"
    "GF\0"
    "CRL\0"
    "TEL\0"
    "D11\0"
    "PURP\0"
    "YELL\0"
    "TT\0"
    "SIR\0"
    "GL(E)\0"
    "<7>\0"
    "<6>\0"
    "202\0"
    "22R\0"
    "TWL\0"
    "TKL\0"
    "Yangluo\0"
    "S23\0"
    "751P\0"
    "NEC\0"
    "NLR\0"
    "JFK\0"
    "Norte\0"
    "ARL\0"
    "1530\0"
    "520\0"
    "AREX\0"
    "SAR-VIN\0"
    "Belford Roxo\0"
    "Deodoro\0"
    "Saracuruna\0"
    "JRI-PBI\0"
    "SAR-GIM\0"
    "Parangaba-Mucuripe\0"
    "Oeste\0"
    "TJ\0"
    "OT\0"
    "김포 골드라인\0"
    "1983\0"
    "1975\0"
    "1968\0"
    "1984\0"
    "910\0"
    "GL(D)\0"
    "Daxing Airport\0"
    "River Line\0"
    "CMET\0"
    "APT Blue\0"
    "BTS Sukhumvit\0"
    "D1\0"
    "D2\0"
    "Rochdale - East Didsbury\0"
    "Shaw and Crompton - East Didsbury\0"
    "JB\0"
    "Ashton-under-Lyne – MediaCityUK\0"
    "Arcobaleno\0"
    "Ashton-under-Lyne – Eccles\0"
    "Piccadilly - Altrincham\0"
    "Altrincham – Bury\0"
    "ESFECO\0"
    "MSC 821\0"
    "MSC 1708\0"
    "KS\0"
    "Taipa\0"
    "305\0"
    "309\0"
    "316\0"
    "4М\0"
    "3М\0"
    "2М\0"
    "1М\0"
    "Fredericksburg\0"
    "CHW\0"
    "CHE\0"
    "AIR\0"
    "CYN\0"
    "NOR\0"
    "ELW\0"
    "NWK\0"
    "Sado\0"
    "TGM1\0"
    "Hartford Line\0"
    "IR 65\0"
    "91/Perris Valley\0"
    "Inland Empire-Orange County\0"
    "Riverside\0"
    "San Bernardino\0"
    "Ventura County\0"
    "Antelope Valley\0"
    "Purple Line\0"
    "Turquoise Line\0"
    "RE 1\0"
    "550\0"
    "TEX\0"
    "630\0"
    "662\0"
    "636\0"
    "656\0"
    "640\0"
    "UP Express\0"
    "Stouffville\0"
    "Richmond Hill\0"
    "Milton\0"
    "Kitchener\0"
    "Barrie\0"
    "Lakeshore East\0"
    "Lakeshore West\0"
    "S22\0"
    "LRT\0"
    "102\0"
    "101\0"
    "SI\0"
    "1645\0"
    "The Trafford Centre – Cornbrook\0"
    "JSQ–33 via HOB\0"
    "<F>\0"
    "S76\0"
    "HBLR\0"
    "RL(M)\0"
    "GL(B)\0"
    "GL(C)\0"
    "Metro\0"
    "S82\0"
    "C-1a\0"
    "N6\0"
    "Thilawa\0"
    "Eastern University\0"
    "Ywar Thar Gyi\0"
    "Computer University\0"
    "Insein - Hlaw Karr\0"
    "Dagon University\0"
    "SN 4\0"
    "KK\0"
    "C-2 (CIVIS)\0"
    "CH\0"
    "E11\0"
    "272\0"
    "T1a\0"
    "T2a\0"
    "TL-3\0"
    "4–环–5\0"
    "BTS Gold Line\0"
    "86967\0"
    "86981\0"
    "86960\0"
    "86964\0"
    "TI\0"
    "TN\0"
    "T1A\0"
    "T1B\0"
    "FEX\0"
    "CK\0"
    "NH\0"
    "RB 14\0"
    "RB 54\0"
    "RE 5\0"
    "Limited\0"
    "RB 33\0"
    "TECO\0"
    "QLine\0"
    "APT Rose\0"
    "m1\0"
    "Π5\0"
    "OH\0"
    "RE 31\0"
    "RE 32\0"
    "RE 35\0"
    "RB 18\0"
    "T9\0"
    "Atlantic City\0"
    "Route 2020\0"
    "IR87\0"
    "G40\0"
    "Z42\0"
    "HH\0"
    "Т1\0"
    "TNH1\0"
    "IR 35\0"
    "THP1\0"
    "Ouargla tram\0"
    "TRS\0"
    "1E\0"
    "TAD\0"
    "F1\0"
    "F2\0"
    "7а\0"
    "TPC\0"
    "1N\0"
    "S 47\0"
    "TER\0"
    "RE 3\0"
    "GAWC\0"
    "GWY\0"
    "Aqua\0"
    "R40\0"
    "IR 66\0"
    "LIL\0"
    "7AB\0"
    "RB 73\0"
    "T10\0"
    "T13\0"
    "Z40\0"
    "RE80\0"
    "JT\0"
    "Jinyi\0"
    "S90\0"
    "Fremantle\0"
    "Midland\0"
    "Mandurah\0"
    "Thornlie\0"
    "Armadale\0"
    "Joondalup\0"
    "Arrow\0"
    "F4\0"
    "GR01\0"
    "6B\0"
    "S74\0"
    "S 10\0"
    "RE8\0"
    "S53\0"
    "IR85\0"
    "215\0"
    "58d\0"
    "M11\0"
    "M14\0"
    "L-9\0"
    "M12\0"
    "M9\0"
    "M20\0"
    "RB32\0"
    "RB21\0"
    "RB37\0"
    "S225\0"
    "PR\0"
};

static const char line_logo_stringtab[] = {
    "Berlin Tram M4.svg\0"
    "Tram-Logo.svg\0"
    "Berlin Tram M5.svg\0"
    "Berlin Tram 12.svg\0"
    "Berlin Tram M8.svg\0"
    "Berlin Tram 18.svg\0"
    "Berlin Tram 16.svg\0"
    "Berlin Tram M6.svg\0"
    "Tramway Budapest 2.svg\0"
    "Logo tramway-budapest.svg\0"
    "Berlin transit icons - S7.svg\0"
    "S-Bahn-Logo.svg\0"
    "Berlin transit icons - S75.svg\0"
    "Berlin transit icons - S5.svg\0"
    "Berlin transit icons - S8.svg\0"
    "Berlin Tram M10.svg\0"
    "Berlin Tram M13.svg\0"
    "Berlin Tram 21.svg\0"
    "Logo Stadtbahn Stuttgart.svg\0"
    "Berlin Tram 63.svg\0"
    "Berlin Tram 61.svg\0"
    "Berlin Tram 68.svg\0"
    "Berlin Tram 62.svg\0"
    "Berlin Tram 37.svg\0"
    "SRS Tram Logo.svg\0"
    "Zahnradbahn-Logo VVS.svg\0"
    "Wien U4.svg\0"
    "U-Bahn Wien.svg\0"
    "Wien U6.svg\0"
    "Stadtbahn.svg\0"
    "Berlin Tram 60.svg\0"
    "Berlin transit icons - S3.svg\0"
    "Berlin Tram 67.svg\0"
    "Berlin Tram 27.svg\0"
    "Berlin Tram M17.svg\0"
    "Berlin Tram 50.svg\0"
    "S1 S-Bahn Stuttgart Logo (2021).svg\0"
    "S2 S-Bahn Stuttgart Logo (2021).svg\0"
    "S3 S-Bahn Stuttgart Logo (2021).svg\0"
    "S6 S-Bahn Stuttgart Logo (2021).svg\0"
    "Símbolo del tranvía de Tenerife.svg\0"
    "Magdeburg Tram 6 (2021).png\0"
    "Magdeburg Tram 1 (2021).png\0"
    "Magdeburg Tram 4 (2021).png\0"
    "Magdeburg Tram 5 (2021).png\0"
    "S-train service B.svg\0"
    "S-tog.svg\0"
    "Berlin transit icons - U6.svg\0"
    "U-Bahn.svg\0"
    "Spårvagnslinje 1.svg\0"
    "Spårvagnslinje 5.svg\0"
    "Spårvagnslinje 7.svg\0"
    "München S8.svg\0"
    "München S4.svg\0"
    "Spårvagnslinje 6.svg\0"
    "Magdeburg Tram 9 (2021).png\0"
    "Magdeburg Tram 2 (2021).png\0"
    "Magdeburg Tram 8 (2021).png\0"
    "Magdeburg Tram 10 (2021).png\0"
    "Magdeburg Tram 3 (2021).png\0"
    "Berlin transit icons - U9.svg\0"
    "Berlin transit icons - U8.svg\0"
    "Berlin transit icons - U7.svg\0"
    "Berlin transit icons - U3.svg\0"
    "Berlin transit icons - U2.svg\0"
    "Berlin transit icons - U4.svg\0"
    "Berlin transit icons - U5.svg\0"
    "Berlin transit icons - U1.svg\0"
    "Nürnberg T5.png\0"
    "Tram Nürnberg Logo.png\0"
    "München Tram 17.svg\0"
    "München Tram 19.svg\0"
    "München Tram 18.svg\0"
    "Berlin transit icons - S2.svg\0"
    "Berlin transit icons - S25.svg\0"
    "Hamburg U3.svg\0"
    "J Church logo.svg\0"
    "F Market & Wharves logo.svg\0"
    "München S1.svg\0"
    "München S6.svg\0"
    "Berlin transit icons - S46alt.svg\0"
    "Berlin transit icons - S45.svg\0"
    "München Tram 25.svg\0"
    "München Tram 12.svg\0"
    "München Tram 16.svg\0"
    "München Tram 27.svg\0"
    "München Tram 20.svg\0"
    "München Tram 21 (2019).svg\0"
    "München Tram 23.svg\0"
    "Hamburg A3.svg\0"
    "S4 S-Bahn Stuttgart Logo (2021).svg\0"
    "S51 Steiermark.svg\0"
    "S-Bahn Austria.svg\0"
    "Berlin Tram M1.svg\0"
    "S5 S-Bahn Stuttgart Logo (2021).svg\0"
    "TriMet MAX logo.svg\0"
    "Nürnberg T4.png\0"
    "Nürnberg T8.png\0"
    "S11 Steiermark.svg\0"
    "Logo Strausberger Eisenbahn.svg\0"
    "Bayern RE 30.svg\0"
    "Bayern RB 12.svg\0"
    "TTC - Line 4 - Sheppard line.svg\0"
    "TTC.svg\0"
    "TTC - Line 3 - Scarborough RT line.svg\0"
    "London Overground logo.svg\0"
    "Overground roundel.svg\0"
    "Paris transit icons - RER C.svg\0"
    "Paris transit icons - RER.svg\0"
    "Eo circle orange letter-u.svg\0"
    "Línea P (SBASE) bullet.svg\0"
    "Subte-logo.svg\0"
    "Tramway Budapest 49.svg\0"
    "M2 icon.svg\0"
    "Copenhagen metro logo.svg\0"
    "Bayern RB 80.svg\0"
    "Bayern RB 81.svg\0"
    "GO Lakeshore West logo.svg\0"
    "Marseille métro M1.svg\0"
    "Panneau Métro de Marseille.svg\0"
    "Marseille métro M2.svg\0"
    "Tyne Wear Metro logo.svg\0"
    "Berlin transit icons - S85.svg\0"
    "Línia 6 de Metrovalència.svg\0"
    "Línia 5 de Metrovalència.svg\0"
    "Línia 3 de Metrovalència.svg\0"
    "Línia 1 de Metrovalència.svg\0"
    "TRAM - Alicante Logo-L4.svg\0"
    "TRAM - Metropolitano de Alicante -T-.svg\0"
    "TRAM - Alicante Logo-L1.svg\0"
    "S-train service C.svg\0"
    "S-train service H.svg\0"
    "SML2.svg\0"
    "Paris transit icons - Train U.svg\0"
    "Paris transit icons - Train.svg\0"
    "SML7.svg\0"
    "Stockholm Pendeltag Logo.svg\0"
    "Stockholm commuter rail symbol.svg\0"
    "Paris transit icons - Train K.svg\0"
    "Logo Saarbahn.svg\0"
    "Berlin transit icons - S9.svg\0"
    "M1-20px.svg\0"
    "Warsaw Metro logo.svg\0"
    "Helsingin lähiliikenteen logo.png\0"
    "Cercanías C1 (Rojo).svg\0"
    "Bayern RB 55.svg\0"
    "München S3.svg\0"
    "NYCS-bull-trans-G-Std.svg\0"
    "NYCS-bull-trans-7-Std.svg\0"
    "NYCS-bull-trans-S-Std.svg\0"
    "NYCS-bull-trans-N-Std.svg\0"
    "NYCS-bull-trans-Q-Std.svg\0"
    "NYCS-bull-trans-A-Std.svg\0"
    "NYCS-bull-trans-6-Std.svg\0"
    "NYCS-bull-trans-R-Std.svg\0"
    "S-train service F.svg\0"
    "S-train service E.svg\0"
    "SML11.svg\0"
    "BJS Line 2 icon.svg\0"
    "Beijing Subway simplified logo.svg\0"
    "BJS Line 1 icon.svg\0"
    "BJS Line 13 icon.svg\0"
    "BKV m 1 jms.svg\0"
    "BKV metro.svg\0"
    "BJS Line 10 icon.svg\0"
    "BJS Line 5 icon.svg\0"
    "BJS Line 8 icon.svg\0"
    "BJS Line 4 icon.svg\0"
    "GZM Line 8 icon.svg\0"
    "Taipei Metro Line R.svg\0"
    "Berlin transit icons - S1.svg\0"
    "Frankfurt S7.svg\0"
    "Bybanen line 1 symbol.png\0"
    "Tramway Budapest 19.svg\0"
    "Tramway Budapest 47.svg\0"
    "Tramway Budapest 41.svg\0"
    "Tramway Budapest 61.svg\0"
    "Augsburg Tram 2.svg\0"
    "S60 S-Bahn Stuttgart Logo (2021).svg\0"
    "Tramway Budapest 60.svg\0"
    "Tramway Budapest 59.svg\0"
    "Budapest Tram 17.png\0"
    "RE7 VBB (2021).png\0"
    "Tramway Budapest 6.svg\0"
    "Tramway Budapest 4.svg\0"
    "BKV h5 jms.svg\0"
    "Budapest hev symbol.svg\0"
    "Frankfurt U2.svg\0"
    "BJS Yizhuang Line icon.svg\0"
    "BJS Changping Line icon.svg\0"
    "BJS Fangshan Line icon.svg\0"
    "BKV h7 jms.svg\0"
    "MARC train.svg\0"
    "Moskwa Metro Line 5.svg\0"
    "Логотип метро в системе бренда московского транспорта.svg\0"
    "Moskwa Metro Line 4.svg\0"
    "Moskwa Metro Line 3.svg\0"
    "Bayern RB 13.svg\0"
    "Moskwa Metro Line 1.svg\0"
    "RheinNeckar S9.svg\0"
    "Línea A (Logo Metro de Medellín).svg\0"
    "Logo Metro de Medellín.svg\0"
    "RheinNeckar S33.svg\0"
    "Moskwa Metro Line 6.svg\0"
    "Moskwa Metro Line 7.svg\0"
    "Moskwa Metro Line 8.svg\0"
    "Moskwa Metro Line 10.svg\0"
    "Toulouse line B symbol.svg\0"
    "Toulouse \"M\" symbol.svg\0"
    "Toulouse line T1 symbol.svg\0"
    "Toulouse \"T\" symbol.svg\0"
    "Toulouse line A symbol.svg\0"
    "Moskwa Metro Line 9.svg\0"
    "Moskwa Metro Line 2.svg\0"
    "Moskwa Metro Line 12.svg\0"
    "Paris transit icons - Tram 2.svg\0"
    "Paris transit icons - Tram.svg\0"
    "Línea A (SBASE) bullet.svg\0"
    "BKV h8 jms.svg\0"
    "BKV h6 jms.svg\0"
    "Tramway Budapest 1.svg\0"
    "Tramway Budapest 24.svg\0"
    "Tramway Budapest 50.svg\0"
    "Tramway Budapest 62.svg\0"
    "Tramway Budapest 42.svg\0"
    "Tramway Budapest 3.svg\0"
    "Tramway Budapest 14.svg\0"
    "Tramway Budapest 69.svg\0"
    "Tramway Budapest 52.svg\0"
    "Tramway Budapest 62A.svg\0"
    "Tramway Budapest 37.svg\0"
    "Tramway Budapest 51A.svg\0"
    "Tramway Budapest 51.svg\0"
    "Budapest Tram 28A.png\0"
    "Tramway Budapest 28.svg\0"
    "Tramway Budapest 37A.svg\0"
    "Hamburg S1.svg\0"
    "Paris transit icons - RER D.svg\0"
    "Nürnberg U2.svg\0"
    "Hamburg U2.svg\0"
    "Hamburg U1.svg\0"
    "Hamburg S31.svg\0"
    "Kiev Metro Line 2.svg\0"
    "Kharkiv Metro logo.svg\0"
    "Kiev Metro Line 1.svg\0"
    "Kiev Metro Line 3.svg\0"
    "Kiev T logo.svg\0"
    "Logo Tramway Dijon Line 2.svg\0"
    "Logo Tramway Dijon.svg\0"
    "Logo Tramway Dijon Line 1.svg\0"
    "Bayern RB 40.svg\0"
    "Nürnberg U3.svg\0"
    "Nürnberg U1.svg\0"
    "Frankfurt am Main Tram 21.svg\0"
    "Frankfurt am Main Tram 11.svg\0"
    "Frankfurt am Main Tram 12.svg\0"
    "Frankfurt am Main Tram 14.svg\0"
    "Frankfurt am Main Tram 15.svg\0"
    "Frankfurt am Main Tram 17.svg\0"
    "Frankfurt S6.svg\0"
    "Number prefix Randen Arashiyama mainline.png\0"
    "Nürnberg T6.png\0"
    "Tokyu SG line symbol.svg\0"
    "Berlin Tram M2.svg\0"
    "Szczecin Tram 1.svg\0"
    "Szczecin Tram 12.svg\0"
    "Szczecin Tram 5.svg\0"
    "Szczecin Tram 11.svg\0"
    "Szczecin Tram 6.svg\0"
    "Szczecin Tram 8.svg\0"
    "Szczecin Tram 7.svg\0"
    "Augsburg Tram 3.svg\0"
    "Ligne1bielefeld.svg\0"
    "Ligne3bielefeld.svg\0"
    "Ligne2bielefeld.svg\0"
    "Ligne4bielefeld.svg\0"
    "München S20.svg\0"
    "München S7.svg\0"
    "Logo du Tramway de Nantes.svg\0"
    "Cptm 8.svg\0"
    "Cptm 9.svg\0"
    "Metropolitana di Roma - logo linea A.svg\0"
    "Logo Metropolitane Italia.svg\0"
    "Metropolitana di Roma - logo linea B.svg\0"
    "Ferrovia Roma-Giardinetti.svg\0"
    "Ferrovia regionale laziale FL1.svg\0"
    "Ferrovia regionale laziale FL2.svg\0"
    "Ferrovia regionale laziale FL3.svg\0"
    "Ferrovia regionale laziale FL4.svg\0"
    "Ferrovia regionale laziale FL5.svg\0"
    "Ferrovia regionale laziale FL6.svg\0"
    "Ferrovia regionale laziale FL7.svg\0"
    "Ferrovia regionale laziale FL8.svg\0"
    "STIB-MIVB Line 8.svg\0"
    "Brussels tramway icon.svg\0"
    "Paris transit icons - RER A.svg\0"
    "Szczecin Tram 10.svg\0"
    "CDML1.svg\0"
    "RheinNeckar S4.svg\0"
    "RheinNeckar S51.svg\0"
    "Spårvagnslinje 10.svg\0"
    "Spårvagnslinje 8.svg\0"
    "Spårvagnslinje 13.svg\0"
    "Spårvagnslinje 2.svg\0"
    "Spårvagnslinje 4.svg\0"
    "Berlin transit icons - S47.svg\0"
    "Spårvagnslinje 3.svg\0"
    "Spårvagnslinje 9.svg\0"
    "Spårvagnslinje 11.svg\0"
    "NRW S1.svg\0"
    "NRW S11.svg\0"
    "NRW S12.svg\0"
    "NRW S13.svg\0"
    "NRW S2.svg\0"
    "NRW S28.svg\0"
    "NRW S3.svg\0"
    "NRW S4.svg\0"
    "NRW S5.svg\0"
    "NRW S6.svg\0"
    "NRW S68.svg\0"
    "NRW S8.svg\0"
    "NRW S9.svg\0"
    "RheinNeckar S1.svg\0"
    "RheinNeckar S2.svg\0"
    "Frankfurt S3.svg\0"
    "RheinNeckar S3.svg\0"
    "Spb metro line1.svg\0"
    "Spb metro logo.svg\0"
    "Spb metro line2.svg\0"
    "Spb metro line3.svg\0"
    "Spb metro line4.svg\0"
    "Spb metro line5.svg\0"
    "Marseille tram T2.svg\0"
    "Symbole AMP Tram.svg\0"
    "Marseille tram T1.svg\0"
    "Athens Metro Line 3.svg\0"
    "Logo of the Athens Metro Operating Company (AMEL).svg\0"
    "Hannover S3.svg\0"
    "Hannover S5.svg\0"
    "Tashkent Metro Line 2.svg\0"
    "Tashkent metro.svg\0"
    "Tashkent Metro Line 3.svg\0"
    "Tashkent Metro Line 1.svg\0"
    "Frankfurt S5.svg\0"
    "Frankfurt S4.svg\0"
    "RE5 VBB (2021).png\0"
    "RE4 VBB (2022).svg\0"
    "NRW S7.svg\0"
    "Hannover S1.svg\0"
    "Paris transit icons - Métro 7bis.svg\0"
    "Paris transit icons - Métro.svg\0"
    "Hannover S6.svg\0"
    "Icon brownline CTA.png\0"
    "Chicago L fictional logo.svg\0"
    "Hannover S4.svg\0"
    "Metrorex logo.svg\0"
    "Paris transit icons - Tram 1.svg\0"
    "Icon orange line CTA.png\0"
    "NNMetro Line 1.svg\0"
    "NNMetro.svg\0"
    "Icon redline CTA.png\0"
    "RheinNeckar S6.svg\0"
    "Mitteldeutschland S8.svg\0"
    "RB14 VBB (2021).png\0"
    "Mitteldeutschland S4.svg\0"
    "RE18 VBB (2021).png\0"
    "RE2 VBB (2022).svg\0"
    "RE15 VBB (2021).png\0"
    "Hamburg RE1.svg\0"
    "RE3 VBB (2021).png\0"
    "Icon greenline CTA.png\0"
    "Icon yellowline CTA.png\0"
    "Oslo Metro 3 2016.svg\0"
    "Oslo T-bane Logo.svg\0"
    "München Tram 29 (2019).svg\0"
    "Oslo Metro 2 2016.svg\0"
    "Oslo Metro 5 2016.svg\0"
    "DSW21 U46.svg\0"
    "Lyon tcl tram-5.svg\0"
    "Lyon tcl logo-tram-full.svg\0"
    "Logo Tramway Bordeaux ligne A.svg\0"
    "Logo Tramway Bordeaux.svg\0"
    "Logo Tramway Bordeaux ligne B.svg\0"
    "KRT Line 6 icon.svg\0"
    "Logo Tramway Bordeaux ligne C.svg\0"
    "Icon pinkline CTA.png\0"
    "Icon blueline CTA.png\0"
    "BJS Line 9 icon.svg\0"
    "Icon purpleline CTA.png\0"
    "S1 Wien.svg\0"
    "S-Bahn Wien.svg\0"
    "S2 Wien.svg\0"
    "S3 Wien.svg\0"
    "Hannover S2.svg\0"
    "BJS Daxing Line icon.svg\0"
    "BJS Line 15 icon.svg\0"
    "Milano linea M5.svg\0"
    "Mitteldeutschland S3.svg\0"
    "Zurich tram route 10.PNG\0"
    "Zurich tram route 12.PNG\0"
    "Zurich tram route 7.PNG\0"
    "Zurich tram route 14.PNG\0"
    "Zurich tram route 11.PNG\0"
    "Zurich tram route 15.PNG\0"
    "Oslo Metro 4.svg\0"
    "Bart-logo.svg\0"
    "Nanchang Metro Line 1.png\0"
    "Dgrd pfm.noe.svg\0"
    "Dark orange.PNG\0"
    "Chs2 Greend40.png\0"
    "Solid blue.svg\0"
    "Hamburg U4.svg\0"
    "Cptm 11.svg\0"
    "Cptm 12.svg\0"
    "Cptm 7.svg\0"
    "Oslo Metro 1.svg\0"
    "Cptm 10.svg\0"
    "Línea B (Logo Metro de Medellín).svg\0"
    "Mitteldeutschland S1.svg\0"
    "Oslo Tramway new 19.svg\0"
    "Oslo Tramway 18.svg\0"
    "Línea C (SBASE) bullet.svg\0"
    "Línea B (SBASE) bullet.svg\0"
    "Línea E (SBASE) bullet.svg\0"
    "Línea D (SBASE) bullet.svg\0"
    "Línea H (SBASE) bullet.svg\0"
    "Istanbul T1 Line Symbol.svg\0"
    "Istanbul T4 Line Symbol.svg\0"
    "Paris transit icons - Métro 15.svg\0"
    "Mitteldeutschland S2.svg\0"
    "Hannover S7.svg\0"
    "Oslo Tramway new 13.svg\0"
    "Oslo Tramway new 11.svg\0"
    "Oslo Tramway new 12.svg\0"
    "MtlMetro4.svg\0"
    "Montreal Metro.svg\0"
    "MtlMetro2.svg\0"
    "MtlMetro5.svg\0"
    "MtlMetro1.svg\0"
    "GZM Line 2 icon.svg\0"
    "Wien U2.svg\0"
    "Spmetro 3.svg\0"
    "Oslo Tramway new 17.svg\0"
    "Wien U1.svg\0"
    "Paris transit icons - Métro 4.svg\0"
    "Paris transit icons - Métro 14.svg\0"
    "Paris transit icons - Métro 1.svg\0"
    "Paris transit icons - Métro 9.svg\0"
    "München U4.svg\0"
    "U-Bahnlogo München.svg\0"
    "Paris transit icons - Métro 10.svg\0"
    "Paris transit icons - Métro 6.svg\0"
    "Paris transit icons - Métro 7.svg\0"
    "RB55 VBB (2021).png\0"
    "RB20 VBB (2021).png\0"
    "Augsburg Tram 1.svg\0"
    "Bremen RS2.svg\0"
    "Bremen RS1.svg\0"
    "Bayern RB 58.svg\0"
    "STIB-MIVB Line 44.svg\0"
    "STIB-MIVB Line 39.svg\0"
    "RB23 VBB (2021).png\0"
    "NJM Line 10 icon.svg\0"
    "Nanjing Metro Logo.svg\0"
    "NJM Line 1 icon.svg\0"
    "RB13 VBB (2021).png\0"
    "NJM Line 2 icon.svg\0"
    "Frankfurt S1.svg\0"
    "Frankfurt S2.svg\0"
    "Frankfurt S8.svg\0"
    "Frankfurt S9.svg\0"
    "C-5 yellow.svg\0"
    "DeLijn icon 12antw.svg\0"
    "DeLijn icon 9antw.svg\0"
    "DeLijn icon 24antw.svg\0"
    "DeLijn icon 3antw.svg\0"
    "DeLijn icon 4antw.svg\0"
    "DeLijn icon 5antw.svg\0"
    "DeLijn icon 6antw.svg\0"
    "DeLijn icon 7antw.svg\0"
    "DeLijn icon 8antw.svg\0"
    "DeLijn icon 15antw.svg\0"
    "K Ingleside logo.svg\0"
    "L Taraval logo.svg\0"
    "M Ocean View logo.svg\0"
    "N Judah logo.svg\0"
    "STIB-MIVB Line 19.svg\0"
    "München U5.svg\0"
    "München U6.svg\0"
    "München U3.svg\0"
    "RB49 VBB (2021).png\0"
    "Metro de Bilbao L2.svg\0"
    "Frankfurt U6.svg\0"
    "München U1.svg\0"
    "München U2.svg\0"
    "München U7.svg\0"
    "München U8.svg\0"
    "Spmetro 5.svg\0"
    "Intercidades.svg\0"
    "Spmetro 1.svg\0"
    "Spmetro 4.svg\0"
    "Spmetro 2.svg\0"
    "Paris transit icons - Tram 3b.svg\0"
    "Lyon tcl tram-1.svg\0"
    "Lyon tcl tram-2.svg\0"
    "Lyon tcl tram-3.svg\0"
    "Lyon tcl tram-4.svg\0"
    "Lyon tcl metro-b.svg\0"
    "Lyon tcl logo-metro-full.svg\0"
    "Lyon tcl metro-d.svg\0"
    "Lyon tcl metro-c.svg\0"
    "Lyon tcl metro-a.svg\0"
    "Wien U3.svg\0"
    "STIB-MIVB Line 62.svg\0"
    "Tramway Budapest 48.svg\0"
    "München Tram 28.svg\0"
    "Logo Metro Rennes ligne a.svg\0"
    "Logo Metro Rennes.svg\0"
    "M1 icon.svg\0"
    "GZM Line 1 icon.svg\0"
    "GZM Line 5 icon.svg\0"
    "S-Bahn Bern.svg\0"
    "Paris transit icons - Tram 8.svg\0"
    "Icon-blue-line-default.svg\0"
    "STIB-MIVB Line 97.svg\0"
    "TAM-4.svg\0"
    "BKV m 3 jms.svg\0"
    "BKV m 4 jms.svg\0"
    "BKV m 2 jms.svg\0"
    "Metropolitana di Roma - logo linea C.svg\0"
    "Erfurt Straßenbahn 1.svg\0"
    "Erfurt Straßenbahn 2.svg\0"
    "Erfurt Straßenbahn 3.svg\0"
    "Erfurt Straßenbahn 4.svg\0"
    "Erfurt Straßenbahn 5.svg\0"
    "Erfurt Straßenbahn 6.svg\0"
    "M2-20px.svg\0"
    "Taipei Metro Line O.svg\0"
    "Taipei Metro Line Xiaobitan Branch.svg\0"
    "Taipei Metro Line BR.svg\0"
    "Icon 2 (set f).png\0"
    "IC 8 logo.svg\0"
    "Hannover S51.svg\0"
    "Hannover S21.svg\0"
    "S-Bahn Salzburg.svg\0"
    "Hannover S8.svg\0"
    "Taichung Metro Green Line icon.svg\0"
    "Amsterdam unofficial metro icon line 50.svg\0"
    "Amsterdam metro logo.svg\0"
    "Amsterdam unofficial metro icon line 54.svg\0"
    "Amsterdam unofficial metro icon line 53.svg\0"
    "Logo du M2 de Lausanne.svg\0"
    "Logo Métro Lausanne.svg\0"
    "BJS Line 7 icon.svg\0"
    "BJS Line 14 icon.svg\0"
    "BJS Line 6 icon.svg\0"
    "Frankfurt U1.svg\0"
    "Frankfurt U3.svg\0"
    "Frankfurt U4.svg\0"
    "Frankfurt U5.svg\0"
    "Frankfurt U7.svg\0"
    "Frankfurt U8.svg\0"
    "Frankfurt U9.svg\0"
    "T4.svg\0"
    "Tramvia metropolita.svg\0"
    "T6.svg\0"
    "T5.svg\0"
    "Marseille tram T3.svg\0"
    "L2 barcelona.svg\0"
    "Barcelona Metro Logo.svg\0"
    "L4 barcelona.svg\0"
    "L5 barcelona.svg\0"
    "L10 barcelona.svg\0"
    "L3 barcelona.svg\0"
    "L8 barcelona.svg\0"
    "L7 barcelona.svg\0"
    "L1 barcelona.svg\0"
    "L11 barcelona.svg\0"
    "L6 barcelona.svg\0"
    "L9 barcelona.svg\0"
    "Logo TER.svg\0"
    "Hamburg S21.svg\0"
    "Poznań ikona linii tramwajowej 1.png\0"
    "Poznań ikona linii tramwajowej 2.png\0"
    "Hamburg A2.svg\0"
    "Antwerpen S-Trein S32.svg\0"
    "NMBS S-Trein logo.svg\0"
    "S60 Wien.svg\0"
    "S50 Wien.svg\0"
    "S80 Wien.svg\0"
    "S40 Wien.svg\0"
    "Number prefix Toyo-Rapid.svg\0"
    "C-3 dark pink.svg\0"
    "New Taipei Metro Danhai LRT Line icon.svg\0"
    "Hamburg RE5.svg\0"
    "Kaohsiung Rapid Transit Circular Line.svg\0"
    "Athens Suburban Railway Line 3.svg\0"
    "Hamburg S11.svg\0"
    "Hamburg S2.svg\0"
    "Hamburg S3.svg\0"
    "Hamburg A1.svg\0"
    "Línia 2 de Metrovalència.svg\0"
    "Línia 9 de Metrovalència.svg\0"
    "Línia 7 de Metrovalència.svg\0"
    "Toulouse line T2 symbol.svg\0"
    "Poznań ikona linii tramwajowej 15.png\0"
    "R2 barcelona.svg\0"
    "R3 barcelona.svg\0"
    "R4 barcelona.svg\0"
    "R8 barcelona.svg\0"
    "RT1 tarragona.svg\0"
    "RT2 tarragona.svg\0"
    "RG1 girona.svg\0"
    "DSW21 U45.svg\0"
    "R12 Rodalies de Catalunya.svg\0"
    "RET metro logo.svg\0"
    "Metro Rotterdam logo.svg\0"
    "RandstadRail logo.png\0"
    "R11 Rodalies de Catalunya.svg\0"
    "R13 Rodalies de Catalunya.svg\0"
    "R14 Rodalies de Catalunya.svg\0"
    "R15 Rodalies de Catalunya.svg\0"
    "Mitja distància Ca6.svg\0"
    "Hamburg RE6.svg\0"
    "Metro do Porto linha D.svg\0"
    "Porto Metro logo.svg\0"
    "Metro do Porto linha E.svg\0"
    "Metro do Porto linha F.svg\0"
    "Metro do Porto linha A.svg\0"
    "Metro do Porto linha C.svg\0"
    "S Shuttle logo.svg\0"
    "S (South Line - Fortaleza Subway).png\0"
    "S4 Wien.svg\0"
    "Metro do Porto linha B.svg\0"
    "Dallas Area Rapid Transit logo.svg\0"
    "Blå linjen logo.svg\0"
    "Stockholm metro symbol.svg\0"
    "Gröna linjen logo.svg\0"
    "Röda linjen logo.svg\0"
    "Underground.svg\0"
    "MTR LR 505.svg\0"
    "18E CCFL.png\0"
    "LACMTA Circle E Line.svg\0"
    "LACMTA Circle A Line.svg\0"
    "RB22 VBB (2021).png\0"
    "25E CCFL.png\0"
    "Logo Metro Rennes ligne b.svg\0"
    "Logo VLT Carioca Linha 1.svg\0"
    "Vlt carioca logo.svg\0"
    "Poznań ikona linii tramwajowej 7.png\0"
    "L12 barcelona.svg\0"
    "GZM Line 14 icon.svg\0"
    "Athens Tram Line 6.svg\0"
    "Logo of the Athens Tram (icon only).svg\0"
    "Athens Tram Line 7.svg\0"
    "Liege S-Trein S43.svg\0"
    "SHM Line 1 icon.svg\0"
    "SHM Line 16 icon.svg\0"
    "SHM Line 5 icon.svg\0"
    "SML3.svg\0"
    "SML6.svg\0"
    "Logo de la Línea 1 del Tren Eléctrico Urbano de Guadalajara.svg\0"
    "Hamburg RE7.svg\0"
    "Logo de la Línea 2 del Tren Eléctrico Urbano de Guadalajara.svg\0"
    "Línea 2 - Tren Concepción - Coronel, Biotren (2021).svg\0"
    "Línea 1 - Tren Mercado de Talcahuano - Hualqui, Biotren (2021).svg\0"
    "Paris transit icons - Train J.svg\0"
    "Paris transit icons - Tram 3a.svg\0"
    "Paris transit icons - Tram 4.svg\0"
    "Paris transit icons - Tram 5.svg\0"
    "Paris transit icons - Tram 6.svg\0"
    "Paris transit icons - Tram 7.svg\0"
    "RB10 VBB (2021).png\0"
    "Bremen RS3.svg\0"
    "Bremen RS4.svg\0"
    "Paris Orlyval icon.svg\0"
    "RE6 VBB (2021).png\0"
    "Taoyuan Metro Line Airport.svg\0"
    "NYCS-bull-trans-W-Std.svg\0"
    "Logo tram 1 Mulhouse.svg\0"
    "Logo tram Mulhouse.svg\0"
    "STIB-MIVB Line 5.svg\0"
    "Brussels Metro Logo.svg\0"
    "Logo tram 2 Mulhouse.svg\0"
    "STIB-MIVB Line 1.svg\0"
    "Logo tram 3 Mulhouse.svg\0"
    "RE1 VBB (2021).png\0"
    "Logo VLT Carioca Linha 2.svg\0"
    "München S2.svg\0"
    "Metro de Bilbao L1.svg\0"
    "STIB-MIVB Line 7.svg\0"
    "Metro de Bilbao L3.svg\0"
    "STIB-MIVB Line 92.svg\0"
    "L1 Metro de Granada.svg\0"
    "Cercanías C2.svg\0"
    "Paris transit icons - Métro 2.svg\0"
    "Central Line roundel.svg\0"
    "Paris transit icons - RER E.svg\0"
    "STIB-MIVB Line 2.svg\0"
    "GZM Line 6 icon.svg\0"
    "Moskwa Metro Line 14.svg\0"
    "Euskotren E1.svg\0"
    "Berlin transit icons - S41.svg\0"
    "STIB-MIVB Line 81.svg\0"
    "Brussel S-Trein S1.svg\0"
    "Gand S-Trein S51.svg\0"
    "Liege S-Trein S41.svg\0"
    "Charleroi S-Trein S61.svg\0"
    "Charleroi S-Trein S62.svg\0"
    "Charleroi S-Trein S63.svg\0"
    "Antwerpen S-Trein S33.svg\0"
    "Gand S-Trein S52.svg\0"
    "Charleroi S-Trein S64.svg\0"
    "الخط الأول لطرامواي اليضاء.png\0"
    "Paris transit icons - Métro 13.svg\0"
    "Paris transit icons - Métro 12.svg\0"
    "Paris transit icons - Métro 11.svg\0"
    "Paris transit icons - Métro 8.svg\0"
    "Paris transit icons - Métro 5.svg\0"
    "Paris transit icons - Métro 3bis.svg\0"
    "Paris transit icons - Train P.svg\0"
    "Paris transit icons - Train R.svg\0"
    "Paris transit icons - Train H.svg\0"
    "Paris transit icons - Train N.svg\0"
    "Paris transit icons - RER B.svg\0"
    "VR Group logo.svg\0"
    "SML4.svg\0"
    "SML8.svg\0"
    "SML9.svg\0"
    "SHM Line 12 icon.svg\0"
    "SML13.svg\0"
    "SML10.svg\0"
    "Incheon Metro Line 2.svg\0"
    "South Korea subway logo.svg\0"
    "Seoul Metro Line U Line.svg\0"
    "Seoul Metro Line Ui LRT Bilingual.svg\0"
    "Cleveland RTA logo.svg\0"
    "WMATA Yellow.svg\0"
    "WMATA Metro Logo.svg\0"
    "Seoul Metro Line 2.svg\0"
    "Seoul Metro Line 4.svg\0"
    "Logo ligne 1 métro d'Alger.svg\0"
    "STIB-MIVB Line 51.svg\0"
    "STIB-MIVB Line 93.svg\0"
    "Tabriz Metro Line 1.png\0"
    "NNMetro Line 2.svg\0"
    "Helsingin metro logo.svg\0"
    "District line roundel.svg\0"
    "Logo metropolitana di Catania.svg\0"
    "Maha Mumbai Metro.png\0"
    "RB66 VBB (2021).png\0"
    "Astram Logo.svg\0"
    "Subway FukuokaHakozaki.svg\0"
    "Fukuoka City Subway Logo.svg\0"
    "Piccadilly line roundel.svg\0"
    "Northern line roundel.svg\0"
    "Subway FukuokaKuko.svg\0"
    "Esfahan Metro Logo.png\0"
    "Tehran Metro Line 7.svg\0"
    "Tehran Metro Logo.svg\0"
    "Tehran Metro Line 4.svg\0"
    "Busan-Gimhae Line.svg\0"
    "Nagoya Subway Logo V2 (Kamiiida Line).svg\0"
    "Nagoya Municipal Subway Logo.svg\0"
    "Port Island Line logo.svg\0"
    "Subway KobeKaigan.svg\0"
    "Kobe Municipal Subway Logo.svg\0"
    "ShenzhenMetroLine4.svg\0"
    "Istanbul M2 Line Symbol.svg\0"
    "Istanbul Metro Logo.svg\0"
    "Istanbul M4 Line Symbol.svg\0"
    "Istanbul M1 Line Symbol.svg\0"
    "Istanbul M6 Line Symbol.svg\0"
    "Subway KobeSeishin.svg\0"
    "RB51 VBB (2022).svg\0"
    "MRT Blue.svg\0"
    "MRT (Bangkok) logo.svg\0"
    "MRT Purple.svg\0"
    "Lima Metro Linea 1.svg\0"
    "Logotipo del Metro de Lima y Callao (ATU).svg\0"
    "Seoul Metro Line Shinbundang.svg\0"
    "Sendai City Subway Logo.svg\0"
    "Yokohama Municipal Subway Blue Line symbol.svg\0"
    "Yokohama Municipal Subway Logo.svg\0"
    "Yokohama Municipal Subway Green Line symbol.svg\0"
    "Santiago de Chile L1.svg\0"
    "Santiago de Chile L4A.svg\0"
    "Santiago de Chile L5.svg\0"
    "Santiago de Chile L6.svg\0"
    "Paris transit icons - Métro 3.svg\0"
    "Kazan-metro-Logo.svg\0"
    "Novosibirsk Metro logo.svg\0"
    "Ekb metro logo.svg\0"
    "Icon V (set f).png\0"
    "Icon L (set orange).png\0"
    "Icon 2 red.svg\0"
    "Icon 1 blue.svg\0"
    "Minsk Metro First Line logo.svg\0"
    "Minsk metro logo.svg\0"
    "Sofia-metro-lines-02.svg\0"
    "Sofia Metro Logo.svg\0"
    "Sofia-metro-lines-01.svg\0"
    "MetroLisboa-linha-vermelha.svg\0"
    "Metropolitano Lisboa logo.svg\0"
    "MetroLisboa-linha-amarela.svg\0"
    "MetroLisboa-linha-verde.svg\0"
    "Subway FukuokaNanakuma.svg\0"
    "Almaty metro logo v2.svg\0"
    "Almaty metro logo.svg\0"
    "Logo of the Pyongyang Metro.svg\0"
    "Tehran Metro Line 1.png\0"
    "Luxtram T1 2020.png\0"
    "Tehran Metro Line 3.png\0"
    "IC 1 logo.svg\0"
    "IC 5 logo.svg\0"
    "IC 2 logo.svg\0"
    "IC 3 logo.svg\0"
    "Línea 1 Metro de Sevilla.svg\0"
    "Símbolo del Metro de Sevilla.svg\0"
    "MetroMalaga L2.svg\0"
    "Símbolo del Metro de Málaga.svg\0"
    "MetroMalaga L1.svg\0"
    "Metro Palma M2.svg\0"
    "Metro Palma M1.svg\0"
    "IC 51 logo.svg\0"
    "IC 21 logo.svg\0"
    "IR 26 logo.svg\0"
    "IR 27 logo.svg\0"
    "Metro Tbilisi logo.svg\0"
    "Kyiv Urban Electric Train.svg\0"
    "Symbole Lille 2.svg\0"
    "Lille Metro Logo 2017.svg\0"
    "Symbole Lille 1.svg\0"
    "IR 75 logo.svg\0"
    "IR 46 logo.svg\0"
    "IR 70 logo.svg\0"
    "IC 6 logo.svg\0"
    "IC 61 logo.svg\0"
    "Daejeon Metro Line 1.svg\0"
    "IR 15 logo.svg\0"
    "IR 37 logo.svg\0"
    "RB43 VBB (2021).png\0"
    "IR 16 logo.svg\0"
    "IR 36 logo.svg\0"
    "IR 17 logo.svg\0"
    "IR 90 logo.svg\0"
    "Mitteldeutschland S9.svg\0"
    "RB24 VBB (2021).png\0"
    "RER Vaudois.png\0"
    "Madrid-MetroLinea4.svg\0"
    "MetroMadridLogo.svg\0"
    "Madrid-MetroLinea1.svg\0"
    "Tehran Metro Line 2.png\0"
    "Madrid-MetroLinea10.svg\0"
    "Kochi Metro logo.png\0"
    "Madrid-MetroLinea8.svg\0"
    "Madrid-MetroLinea9.svg\0"
    "NYCS-bull-trans-J-Std.svg\0"
    "Madrid-MetroLinea5.svg\0"
    "Adana Metro logo.svg\0"
    "Madrid-MetroLinea3.svg\0"
    "Madrid-MetroLinea2.svg\0"
    "Madrid-MetroLinea7.svg\0"
    "Madrid-MetroRamal.svg\0"
    "Madrid-MetroLinea12.svg\0"
    "WX Metro Line 1 icon.svg\0"
    "WX Metro Line 2 icon.svg\0"
    "Shijiazhuang Metro.svg\0"
    "Madrid-MetroLinea6.svg\0"
    "Madrid-MetroLinea11.svg\0"
    "Chennai Metro logo.svg\0"
    "SHM Line 17 icon.svg\0"
    "Daegu Metro Line 2.svg\0"
    "Daegu Metro Line 1.svg\0"
    "ZZMetro Line 2.svg\0"
    "Madrid MetroLigero1.svg\0"
    "Stadtbahn Madrid Logo.svg\0"
    "Madrid MetroLigero2.svg\0"
    "Madrid MetroLigero3.svg\0"
    "Incheon Metro Line 1.png\0"
    "STIB-MIVB Line 3.svg\0"
    "R7 barcelona.svg\0"
    "BursaRay logo.svg\0"
    "XAM Line 1 icon.svg\0"
    "XAM Line 3 icon.svg\0"
    "Sul blue.png\0"
    "ZZMetro Line 1.svg\0"
    "ZZMetro Line CJ.svg\0"
    "Cercanías C10.svg\0"
    "Cercanías C1.svg\0"
    "C-7 red.svg\0"
    "Icon-red-line-default.svg\0"
    "Icon-orange-line-default.svg\0"
    "长沙地铁2号线线标.svg\0"
    "长沙地铁1号线线标.svg\0"
    "CLRT Line 4 icon.svg\0"
    "CLRT Line 3 icon.svg\0"
    "Ankaray logo.svg\0"
    "Ankara Metro logo.svg\0"
    "Kaohsiung Rapid Transit Orange Line.svg\0"
    "Kaohsiung Rapid Transit Red Line.svg\0"
    "Seoul Metro Line 3.svg\0"
    "Seoul Metro Line 5.svg\0"
    "Seoul Metro Line 9.svg\0"
    "NBRT Line 2 icon.svg\0"
    "TTC - Line 1 - Yonge-University-Spadina line.svg\0"
    "Thessaloniki Metro Line 1.svg\0"
    "TTC - Line 2 - Bloor-Danforth line.svg\0"
    "SRT-1.png\0"
    "RMRG logo.svg\0"
    "Delhi Metro logo.svg\0"
    "Linea1mty.svg\0"
    "Linea2mty.svg\0"
    "DLM Line 2 icon.svg\0"
    "NYCS-bull-trans-SF-Std.svg\0"
    "SYM Line 1 icon.svg\0"
    "Shenyang Metro Line 2 Logo.svg\0"
    "Icon of FZM L1.svg\0"
    "GZM Line 13 icon.svg\0"
    "Thessaloniki Metro Line 2.svg\0"
    "DLM Line 3 icon.svg\0"
    "KRT Line 2 icon.svg\0"
    "KRT Line 1 icon.svg\0"
    "NJM Line S1 icon.svg\0"
    "NJM Line S3 icon.svg\0"
    "ShenzhenMetroLine1.svg\0"
    "Seoul Metro Line Arex.svg\0"
    "Seoul Metro Line 8.svg\0"
    "Seoul Metro Line 6.svg\0"
    "Baltimore Metro SubwayLink Logo for Signage (Blue).svg\0"
    "WMATA Orange.svg\0"
    "WMATA Red.svg\0"
    "WMATA Silver.svg\0"
    "WMATA Blue.svg\0"
    "WMATA Green.svg\0"
    "Seoul Metro Line 7.svg\0"
    "Logo of Miami-Dade County, Florida.svg\0"
    "STIB-MIVB Line 6.svg\0"
    "Línea 2 CAMETRO.png\0"
    "Metrodecaracas.svg\0"
    "Línea 3 CAMETRO.png\0"
    "MetroDF Línea 1.svg\0"
    "LACMTA Circle C Line.svg\0"
    "LACMTA Circle D Line.svg\0"
    "MetroDF Línea 4.svg\0"
    "MetroDF Línea 5.svg\0"
    "MetroDF Línea 12.svg\0"
    "MetroDF Línea 7.svg\0"
    "MetroDF Línea A.svg\0"
    "MetroDF Línea 8.svg\0"
    "MetroDF Línea B.svg\0"
    "MetroDF Línea 2.svg\0"
    "MetroDF Línea 9.svg\0"
    "MetroDF Línea 3.svg\0"
    "MetroDF Línea 6.svg\0"
    "PATH.svg\0"
    "PATH logo.svg\0"
    "Icon 1 (set orange).png\0"
    "Harbin Metro Line 1.svg\0"
    "Harbin Metro Line 3.svg\0"
    "CRRT line1 logo.svg\0"
    "DLM Line 12 icon.svg\0"
    "Athens Metro Line 1.svg\0"
    "Athens Metro Line 2.svg\0"
    "Rinkai Line symbol.svg\0"
    "Yerevan Metro.svg\0"
    "Madrid MetroLigero4.svg\0"
    "Metro İzmir logo.svg\0"
    "Jaipur Metro Logo.svg\0"
    "Jaipur Metro Logo.png\0"
    "BTS-Logo.svg\0"
    "STIB-MIVB Line 4.svg\0"
    "STIB-MIVB Line 25.svg\0"
    "STIB-MIVB Line 55.svg\0"
    "STIB-MIVB Line 82.svg\0"
    "Lrtalogo.svg\0"
    "KLRT Line 9 icon.svg\0"
    "KLRT Line 5 icon.svg\0"
    "Subway SapporoTozai.svg\0"
    "ST Logo.svg\0"
    "Subway SapporoNamboku.svg\0"
    "Logo of Tokyo Metro Marunouchi Line.svg\0"
    "Tokyo Metro logo (full).svg\0"
    "Toei Asakusa line symbol.svg\0"
    "Toei Shinjuku line symbol.svg\0"
    "Toei Oedo line symbol.svg\0"
    "Toei Mita line symbol.svg\0"
    "Logo of Tokyo Metro Chiyoda Line.svg\0"
    "Logo of Tokyo Metro Namboku Line.svg\0"
    "Logo of Tokyo Metro Ginza Line.svg\0"
    "Logo of Tokyo Metro Yūrakuchō Line.svg\0"
    "Logo of Tokyo Metro Tōzai Line.svg\0"
    "Logo of Tokyo Metro Hibiya Line.svg\0"
    "Logo of Tokyo Metro Fukutoshin Line.svg\0"
    "Osaka Metro Sennichimae line symbol.svg\0"
    "Osaka Metro Midosuji line symbol.svg\0"
    "Osaka Metro Imazatosuji line symbol.svg\0"
    "Osaka Metro Sakaisuji line symbol.svg\0"
    "Osaka Metro Nagahori Tsurumi-ryokuchi line symbol.svg\0"
    "Osaka Metro Yotsubashi line symbol.svg\0"
    "Osaka Metro Tanimachi line symbol.svg\0"
    "Subway KyotoKarasuma.svg\0"
    "Kyoto MTB Logo.svg\0"
    "Subway KyotoTozai.png\0"
    "Nagoya Subway Logo V2 (Sakura-dori Line).svg\0"
    "Nagoya Subway Logo V2 (Higashiyama Line).svg\0"
    "Nagoya Subway Logo V2 (Meiko Line).svg\0"
    "Nagoya Subway Logo V2 (Tsurumai Line).svg\0"
    "Nagoya Subway Logo V2 (Meijo Line).svg\0"
    "Kolkata Metro Logo.svg\0"
    "Kolkata Metro System Logo.svg\0"
    "Delhi Metro Line 3.svg\0"
    "Delhi Metro Line 5.svg\0"
    "Delhi Metro Line 6.svg\0"
    "Delhi Metro Line 2.svg\0"
    "Delhi Metro Line 8.svg\0"
    "Delhi Metro Line 9.svg\0"
    "Moskwa Metro Line 11.svg\0"
    "KLRT Line 7 icon.svg\0"
    "KLRT Line 6 icon.svg\0"
    "SHM Line PJ icon.svg\0"
    "LACMTA Circle B Line.svg\0"
    "Busan Metro Line 3.svg\0"
    "Busan Metro Line 1.svg\0"
    "Busan Metro Line 2.svg\0"
    "CDML7.svg\0"
    "CDML3.svg\0"
    "CDML2.svg\0"
    "CDML4.svg\0"
    "CDML10.svg\0"
    "KLRT Line 12 icon.svg\0"
    "Mitteldeutschland S6.svg\0"
    "济南轨道交通2号线logo.svg\0"
    "JinanMetro Logo.svg\0"
    "WHM Line 1 icon.svg\0"
    "HZM Line 2 icon.svg\0"
    "NBRT Line 1 icon.svg\0"
    "BJS Line 16 icon.svg\0"
    "Amoy Metro logo.svg\0"
    "Bayern RB 32.svg\0"
    "Bayern RB 59.svg\0"
    "JR JL line symbol.svg\0"
    "Nürnberg T7.png\0"
    "Delhi Metro Line 1.svg\0"
    "SZRT Line 4 icon.svg\0"
    "SRT-2.png\0"
    "Bayern RB 57.svg\0"
    "Bayern RB 56 SWEG.svg\0"
    "Amsterdam unofficial metro icon line 52.svg\0"
    "Paris transit icons - Tram 11.svg\0"
    "Athens Suburban Railway Line 4.svg\0"
    "Athens Suburban Railway Line 1.svg\0"
    "Athens Suburban Railway Line 2.svg\0"
    "BJS Yanfang Line icon.svg\0"
    "Firenze Tramvia logo.svg\0"
    "TianjinMetro.svg\0"
    "Tianjin Metro Line 1 icon.svg\0"
    "Tunis Metro Ligne 4.svg\0"
    "Poznań ikona linii tramwajowej 11.png\0"
    "Tunis Metro Ligne 5.svg\0"
    "Tunis Metro Ligne 3.svg\0"
    "Tunis Metro Ligne 2.svg\0"
    "TJM TEDA Tram icon.svg\0"
    "STIB-MIVB Line 9.svg\0"
    "Gyeongchun Line.svg\0"
    "Milano S1.svg\0"
    "Linee S di Milano.svg\0"
    "Milano S2.svg\0"
    "Milano S3.svg\0"
    "Milano S4.svg\0"
    "Milano S5.svg\0"
    "Milano S6.svg\0"
    "Gyeongui-Jungang Line.svg\0"
    "24E CCFL.png\0"
    "Seoul Metro Line 1.svg\0"
    "Seoul Metro Line Seohae Bilingual.svg\0"
    "UTA S-Line logo.svg\0"
    "Gyeonggang Line.svg\0"
    "UM Logo1.png\0"
    "Euskotren TR.svg\0"
    "Tramway Budapest 12.svg\0"
    "Tramway Budapest 59A.svg\0"
    "T Third Street logo.svg\0"
    "Milano S8.svg\0"
    "Milano S13.svg\0"
    "Milano S9.svg\0"
    "Milano S11.svg\0"
    "Bayern RE 22.svg\0"
    "C-4 dark blue.svg\0"
    "C-9 orange.svg\0"
    "C-2 green.svg\0"
    "Yurikamome line symbol.svg\0"
    "Logo trireno black.svg\0"
    "Nippori-Toneri Liner symbol.svg\0"
    "Tokyo Sakura Tram symbol.svg\0"
    "Tokyu TY line symbol.svg\0"
    "ShenzhenMetroLine11.svg\0"
    "Saitama Stadium Line symbol.svg\0"
    "SeibuYamaguchi.svg\0"
    "Tokyu MG line symbol.svg\0"
    "Tokyu OM line symbol.svg\0"
    "Tokyu DT line symbol.svg\0"
    "Tokyu IK line symbol.svg\0"
    "Tokyu TM line symbol.svg\0"
    "Tokyu KD line symbol.svg\0"
    "New Shuttle Line symbol.svg\0"
    "Taipei Metro Line Xinbeitou Branch.svg\0"
    "Taipei Metro Line BL.svg\0"
    "Berlin transit icons - S26.svg\0"
    "Logo VLT Carioca Linha 3.svg\0"
    "Tehran Metro Line 6.svg\0"
    "Number prefix SkyAccess.svg\0"
    "TfNSW M.svg\0"
    "Istanbul F3 Line Symbol.svg\0"
    "SeibuShinjuku.svg\0"
    "Tunis Metro Ligne 1.svg\0"
    "Tunis Metro Ligne 6.svg\0"
    "NJM Line S7 icon.svg\0"
    "NJM Line S9 icon.svg\0"
    "NJM Line S8 icon.svg\0"
    "WHM Line 2 icon.svg\0"
    "Number prefix Hankai Tramway line.png\0"
    "Nankai group logo.svg\0"
    "Osaka Metro Nanko Port Town line symbol.svg\0"
    "GZM Line 4 icon.svg\0"
    "GZM Line 21 icon.svg\0"
    "GZM Guangfo Line icon.svg\0"
    "WHM Line 7 icon.svg\0"
    "S5 Steiermark.svg\0"
    "ShenzhenMetroLine3.svg\0"
    "S1 Steiermark.svg\0"
    "CS Line 4 icon.svg\0"
    "WHM Line 4 icon.svg\0"
    "WH Line 11 icon.png\0"
    "S9 Steiermark.svg\0"
    "S8 Steiermark.svg\0"
    "ShenzhenMetroLine5.svg\0"
    "NYCS-bull-trans-1-Std.svg\0"
    "NYCS-bull-trans-2-Std.svg\0"
    "NYCS-bull-trans-3-Std.svg\0"
    "NYCS-bull-trans-4-Std.svg\0"
    "TfNSW L1.png\0"
    "TfNSW L.svg\0"
    "NYCS-bull-trans-5-Std.svg\0"
    "TfNSW T8.svg\0"
    "ShenzhenMetroLine9.svg\0"
    "Icon-green-line-default.svg\0"
    "NYCS-bull-trans-M-Std.svg\0"
    "NYCS-bull-trans-L-Std.svg\0"
    "Logo PT Kereta Api Indonesia (Persero) 2020.svg\0"
    "Bayern RB 40 Erfurt.svg\0"
    "NYCS-bull-trans-B-Std.svg\0"
    "NYCS-bull-trans-F-Std.svg\0"
    "NYCS-bull-trans-C-Std.svg\0"
    "NYCS-bull-trans-D-Std.svg\0"
    "NYCS-bull-trans-E-Std.svg\0"
    "GZM Line 3 icon.svg\0"
    "Cptm 13.svg\0"
    "Shenyang Metro Line 9 Logo.svg\0"
    "VTA-Green-icon.svg\0"
    "VTA-Blue-icon.svg\0"
    "ARLbangkok.svg\0"
    "GZM Line 9 icon.svg\0"
    "Berlin transit icons - S42.svg\0"
    "O ( West Line - Fortaleza Subway).png\0"
    "S-train service A.svg\0"
    "KLRT Line 2 icon.svg\0"
    "KTM Komuter logo.svg\0"
    "KLRT Line 1 icon.svg\0"
    "KLRT Line 10 icon.svg\0"
    "Moskwa Metro Line 15.svg\0"
    "Szczecin Tram 9.svg\0"
    "Tobu Tojo Line (TJ) symbol.svg\0"
    "JRW kinki-O.svg\0"
    "ZZMetro Line 14.svg\0"
    "济南轨道交通1号线logo.svg\0"
    "Logo-tramway-orizo-avignon.png\0"
    "KT number-C.svg\0"
    "Ferrocarril Suburbano.svg\0"
    "Nice Tramway Logo.svg\0"
    "M3 icon.svg\0"
    "Moskwa Metro Line D1.svg\0"
    "MCD logo.svg\0"
    "Moskwa Metro Line D2.svg\0"
    "Samara Metro logo.svg\0"
    "JR JB line symbol.svg\0"
    "XuzhouMetro.svg\0"
    "NBRT Line 3 icon.svg\0"
    "HZM Line 5 icon.svg\0"
    "ZZMetro Line 5.svg\0"
    "DeLijn icon 1antw.svg\0"
    "Icon of FZM L2.svg\0"
    "济南轨道交通3号线logo.svg\0"
    "CDML5.svg\0"
    "CTrail Hartford Line logo.svg\0"
    "IR 65 logo.svg\0"
    "SML14.svg\0"
    "Metrolink logo.svg\0"
    "Bayern RE 1.svg\0"
    "TAM-2.svg\0"
    "TAM-3.svg\0"
    "TAM-1.svg\0"
    "GO Milton logo.svg\0"
    "GO Kitchener logo.svg\0"
    "GO Barrie logo.svg\0"
    "GO Lakeshore East logo.svg\0"
    "Taipei Metro Line Y.svg\0"
    "S3 Steiermark.svg\0"
    "S6 Steiermark.svg\0"
    "Milano linea M2.svg\0"
    "Milano linea M3.svg\0"
    "Milano linea M1.svg\0"
    "RER Fribourg Freiburg.svg\0"
    "M4 icon.svg\0"
    "SeibuIkebukuro.svg\0"
    "Tobu Skytree Line (TS) symbol.svg\0"
    "HZM Line 16 icon.svg\0"
    "Shenyang Metro Line 10 Logo.svg\0"
    "S7 Steiermark.svg\0"
    "S61 Steiermark.svg\0"
    "CS Line 5 icon.svg\0"
    "Sofia-metro-lines-03.svg\0"
    "St Louis MetroLink Logo.svg\0"
    "C-1 light blue.svg\0"
    "C-3 red.svg\0"
    "C-5 dark blue.svg\0"
    "Milano S7.svg\0"
    "Bcr logo.svg\0"
    "Waterloo ION logo.svg\0"
    "Number prefix Keikyū.PNG\0"
    "ShenzhenMetroLine6.svg\0"
    "ShenzhenMetroLine10.svg\0"
    "R1 barcelona.svg\0"
    "Suin-Bundang Line.svg\0"
    "Kayseri public transport - T1 symbol.svg\0"
    "Kayseray logo.svg\0"
    "Kayseri public transport - T2 symbol.svg\0"
    "Logo de la Línea 3 del Tren Eléctrico Urbano de Guadalajara.svg\0"
    "CDML18.svg\0"
    "Kolkata Metro Rail Corporation Logo.svg\0"
    "S4 Tirol.svg\0"
    "S5 Tirol.svg\0"
    "S3 Tirol.svg\0"
    "S8 Tirol (2021).svg\0"
    "WX Metro Line 3 icon.svg\0"
    "Tobu Isesaki Line (TI) symbol.svg\0"
    "Tobu Nikko Line (TN) symbol.svg\0"
    "Antalya public transport - T3 symbol.svg\0"
    "Antalya public transport - T2 symbol.svg\0"
    "Antalya public transport - T1A symbol.svg\0"
    "Antalya public transport - T1B symbol.svg\0"
    "FEX VBB (2021).png\0"
    "NP-NH.png\0"
    "Hanoi Metro Line 3 Symbol.png\0"
    "Bayern RB 48.svg\0"
    "HCMC Metro logo.svg\0"
    "CDML6.svg\0"
    "CDML8.svg\0"
    "CDML17.svg\0"
    "Paris transit icons - Train L.svg\0"
    "NBRT Line 4 icon.svg\0"
    "Bayern RB 14.svg\0"
    "Istanbul T5 Line Symbol.svg\0"
    "S2 Tirol.svg\0"
    "SML15.svg\0"
    "Bayern RB 54.svg\0"
    "Bayern RE 5.svg\0"
    "Bayern RB 33.svg\0"
    "Tramİzmir logo.svg\0"
    "Houston Metro icon.svg\0"
    "Logo du M1 de Lausanne.svg\0"
    "Linea3mty.svg\0"
    "Athens Suburban Railway Line 5.svg\0"
    "Logo L2 Napoli.svg\0"
    "Bayern RE 31.svg\0"
    "Bayern RE 32.svg\0"
    "Bayern RE 35.svg\0"
    "Bayern RB 18.svg\0"
    "Paris transit icons - Tram 9.svg\0"
    "HZML8.png\0"
    "HZML9.png\0"
    "HZML6icon.png\0"
    "HZM Line 4 icon.svg\0"
    "CDML9.svg\0"
    "IR 35 logo.svg\0"
    "ShenzhenMetroLine2.svg\0"
    "ShenzhenMetroLine8.svg\0"
    "Harbin Metro Line 2.svg\0"
    "BJS Batong Line icon.svg\0"
    "Szczecin Tram 2.svg\0"
    "Istanbul F1 Line Symbol.svg\0"
    "Istanbul F2 Line Symbol.svg\0"
    "ZZMetro Line 4.svg\0"
    "ZZMetro Line 3.svg\0"
    "Línea 1 CAMETRO.png\0"
    "Línea 4 CAMETRO.png\0"
    "HZML7.png\0"
    "HZML10.png\0"
    "HZM Line 3 icon.svg\0"
    "Gwangju Metro Line 1.svg\0"
    "BJS Line 11 icon.svg\0"
    "BJS Line 17 icon.svg\0"
    "BJS Line 19 icon.svg\0"
    "NBRT Line 5 icon.svg\0"
    "DLM Line 13 icon.svg\0"
    "Bayern RE 3.svg\0"
    "S31 Steiermark.svg\0"
    "S5 OÖ.svg\0"
    "S3 OÖ.svg\0"
    "S2 OÖ.svg\0"
    "S1 OÖ.svg\0"
    "S4 OÖ.svg\0"
    "IR 66 logo.svg\0"
    "Tashkent Metro Line 4.svg\0"
    "Icon of FZM L5.svg\0"
    "DeLijn icon 2antw.svg\0"
    "Bayern RB 73.svg\0"
    "Paris transit icons - Tram 10.svg\0"
    "Paris transit icons - Tram 13.svg\0"
    "CS Line 6 icon.svg\0"
    "TAM-5.svg\0"
    "RE80-Tilo.svg\0"
    "Paris transit icons - Métro 18.svg\0"
    "Icon of FZM L6.svg\0"
    "S90-Tilo.svg\0"
    "S20-Tilo.svg\0"
    "S10-Tilo.svg\0"
    "S30-Tilo.svg\0"
    "S60-Tilo.svg\0"
    "S40-Tilo.svg\0"
    "S50-Tilo.svg\0"
    "LACMTA Circle K Line.svg\0"
    "Istanbul F4 Line Symbol.svg\0"
    "Trambahía T1.svg\0"
    "ShenzhenMetroLine14.svg\0"
    "Istanbul M8 Line Symbol.svg\0"
    "Milano linea M4.svg\0"
    "ShenzhenMetroLine12.svg\0"
    "RE8 VBB (2022).svg\0"
    "Gand S-Trein S53.svg\0"
    "ShenzhenMetroLine16.svg\0"
    "Istanbul M11 Line Symbol.svg\0"
    "Istanbul M14 Line Symbol.svg\0"
    "New Taipei Metro Line K.png\0"
    "Shiraz Metro Line 2.png\0"
    "Istanbul M12 Line Symbol.svg\0"
    "Karaj Metro Line 2-2.png\0"
    "لوگو قطار شهری کرج و حومه.svg\0"
    "Istanbul M5 Line Symbol.svg\0"
    "Istanbul M13 Line Symbol.svg\0"
    "Istanbul M7 Line Symbol.svg\0"
    "Istanbul M3 Line Symbol.svg\0"
    "Istanbul M9 Line Symbol.svg\0"
    "Istanbul M20 Line Symbol.svg\0"
    "Kayseri public transport - T3 symbol.svg\0"
    "RB32 VBB (2022).svg\0"
    "RB21 VBB (2021).png\0"
    "RB37 VBB (2022).svg\0"
    "Linka A (Praha).svg\0"
    "Prag Metro Logo.svg\0"
    "Linka B (Praha).svg\0"
    "Linka C (Praha).svg\0"
    "Kyiv Metro Line 3.svg\0"
    "Kyiv Metro logo.svg\0"
    "Kyiv Metro Line 1.svg\0"
    "Kyiv Metro Line 2.svg\0"
    "METROQ.svg\0"
    "Logo Tramway Bordeaux ligne D.svg\0"
};

static const constexpr uint16_t NoLogo = 18;

static const constexpr LineMetaDataContent line_data[] = {
    { 1, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf38bb9} }, // 70 OSM: 9056 WD: Q6811967 -37.84, 144.9 x -37.81, 145.1
    { 5, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009fda} }, // 75 OSM: 9057 WD: Q6811970 -37.86, 144.9 x -37.81, 145.2
    { 8, 0, 19, LineMetaDataContent::Tramway, Color{0xbb0000} }, // M4 OSM: 11134 WD: Q62512299 52.52, 13.4 x 52.57, 13.53
    { 11, 33, 19, LineMetaDataContent::Tramway, Color{0xcc9933} }, // M5 OSM: 11135 WD: Q62512324 52.52, 13.36 x 52.57, 13.52
    { 15, 52, 19, LineMetaDataContent::Tramway, Color{0x996699} }, // 12 OSM: 11140 WD: Q65954567 52.52, 13.38 x 52.56, 13.47
    { 18, 71, 19, LineMetaDataContent::Tramway, Color{0xff6633} }, // M8 OSM: 11141 WD: Q62512359 52.52, 13.36 x 52.57, 13.58
    { 22, 90, 19, LineMetaDataContent::Tramway, Color{0xff6633} }, // 18 OSM: 11142 WD: Q62554449 52.52, 13.44 x 52.55, 13.62
    { 26, 109, 19, LineMetaDataContent::Tramway, Color{0x006699} }, // 16 OSM: 11143 WD: Q62476614 52.51, 13.47 x 52.57, 13.58
    { 29, 128, 19, LineMetaDataContent::Tramway, Color{0x003388} }, // M6 OSM: 11145 WD: Q62511960 52.52, 13.4 x 52.55, 13.62
    { 16, 147, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 2 OSM: 12016 WD: Q950776 47.47, 19.05 x 47.51, 19.08
    { 32, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xee2e27} }, // STH OSM: 14163 WD: Q7570091 -37.07, 174.8 x -36.84, 174.9
    { 36, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfdb913} }, // EAST OSM: 14165 WD: Q5330260 -37, 174.8 x -36.84, 174.9
    { 41, 196, 226, LineMetaDataContent::RapidTransit, Color{0x8070b7} }, // S7 OSM: 14809 WD: Q7388362 52.39, 13.07 x 52.57, 13.57
    { 4, 242, 226, LineMetaDataContent::RapidTransit, Color{0x8070b7} }, // S75 OSM: 14810 WD: Q3744483 52.5, 13.45 x 52.57, 13.54
    { 44, 273, 226, LineMetaDataContent::RapidTransit, Color{0xf25721} }, // S5 OSM: 14811 WD: Q3743008 52.5, 13.28 x 52.59, 13.91
    { 47, 303, 226, LineMetaDataContent::RapidTransit, Color{0x52b447} }, // S8 OSM: 14984 WD: Q4048678 52.35, 13.29 x 52.69, 13.63
    { 50, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x9313ba} }, // S2 OSM: 16111 48.95, 8.283 x 49.11, 8.505
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xb3ee3a} }, // 1 OSM: 17413 WD: Q318073 51.49, 10.79 x 51.52, 10.8
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x2e8b57} }, // 2 OSM: 17415 WD: Q318073 51.5, 10.78 x 51.51, 10.82
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x996633} }, // 3 OSM: 17839 48.99, 8.295 x 49.02, 8.444
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 1 OSM: 17840 49, 8.347 x 49.04, 8.479
    { 53, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // S11 OSM: 17842 48.87, 8.373 x 49.13, 8.518
    { 61, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // S1 OSM: 17843 48.8, 8.373 x 49.13, 8.458
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x18a6d9} }, // 5 OSM: 17847 49, 8.347 x 49.02, 8.463
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffcc00} }, // 4 OSM: 17848 48.98, 8.347 x 49.05, 8.452
    { 47, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x6d682a} }, // S8 OSM: 17849 48.44, 8.215 x 49.01, 8.83
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff9933} }, // 8 OSM: 17855 48.98, 8.452 x 49, 8.479
    { 64, 333, 19, LineMetaDataContent::Tramway, Color{0x108449} }, // M10 OSM: 17865 WD: Q62500489 52.5, 13.36 x 52.54, 13.45
    { 57, 353, 19, LineMetaDataContent::Tramway, Color{0x00cc00} }, // M13 OSM: 17884 WD: Q62512599 52.51, 13.34 x 52.56, 13.48
    { 72, 373, 19, LineMetaDataContent::Tramway, Color{0x996699} }, // 21 OSM: 17885 WD: Q62476959 52.45, 13.45 x 52.53, 13.52
    { 75, NoLogo, 392, LineMetaDataContent::RapidTransit, Color{0xeda5b4} }, // U13 OSM: 19070 WD: Q70718526 48.76, 9.134 x 48.81, 9.254
    { 80, 421, 19, LineMetaDataContent::Tramway, Color{0x009999} }, // 63 OSM: 19115 WD: Q63996601 52.43, 13.53 x 52.5, 13.61
    { 84, 440, 19, LineMetaDataContent::Tramway, Color{0x669933} }, // 61 OSM: 19265 WD: Q62512736 52.43, 13.51 x 52.46, 13.69
    { 88, 459, 19, LineMetaDataContent::Tramway, Color{0x009933} }, // 68 OSM: 19271 WD: Q62470539 52.37, 13.57 x 52.46, 13.65
    { 95, 478, 19, LineMetaDataContent::Tramway, Color{0x006633} }, // 62 OSM: 19296 WD: Q62476843 52.42, 13.57 x 52.51, 13.61
    { 100, 497, 19, LineMetaDataContent::Tramway, Color{0x993333} }, // 37 OSM: 19451 WD: Q62499413 52.45, 13.5 x 52.53, 13.53
    { 104, NoLogo, 516, LineMetaDataContent::Tramway, Color{} }, // 88 OSM: 19597 WD: Q638246 52.46, 13.63 x 52.48, 13.81
    { 107, NoLogo, 392, LineMetaDataContent::RapidTransit, Color{0xc7956c} }, // U1 OSM: 19916 WD: Q106879557 48.73, 9.111 x 48.81, 9.277
    { 110, NoLogo, 392, LineMetaDataContent::RapidTransit, Color{0xf58220} }, // U2 OSM: 19917 WD: Q106879558 48.77, 9.122 x 48.83, 9.238
    { 113, NoLogo, 392, LineMetaDataContent::RapidTransit, Color{0x935f39} }, // U3 OSM: 19918 WD: Q106879559 48.71, 9.112 x 48.73, 9.202
    { 116, NoLogo, 392, LineMetaDataContent::RapidTransit, Color{0x7a68ae} }, // U4 OSM: 19919 WD: Q106879560 48.77, 9.158 x 48.79, 9.25
    { 119, NoLogo, 392, LineMetaDataContent::RapidTransit, Color{0x00baf2} }, // U5 OSM: 19920 WD: Q106879561 48.7, 9.136 x 48.8, 9.187
    { 122, NoLogo, 392, LineMetaDataContent::RapidTransit, Color{0xec008c} }, // U6 OSM: 19921 WD: Q106879562 48.69, 9.064 x 48.81, 9.192
    { 125, NoLogo, 392, LineMetaDataContent::RapidTransit, Color{0x0eb48d} }, // U7 OSM: 19922 WD: Q106879563 48.71, 9.173 x 48.84, 9.296
    { 128, NoLogo, 392, LineMetaDataContent::RapidTransit, Color{0xc3b47d} }, // U8 OSM: 19923 WD: Q106879564 48.71, 9.112 x 48.76, 9.296
    { 131, NoLogo, 392, LineMetaDataContent::RapidTransit, Color{0xffd503} }, // U9 OSM: 19924 WD: Q106879565 48.75, 9.138 x 48.79, 9.254
    { 65, 534, 392, LineMetaDataContent::Tramway, Color{0xf8b710} }, // 10 OSM: 19925 WD: Q143861 48.75, 9.167 x 48.76, 9.174
    { 134, NoLogo, 392, LineMetaDataContent::RapidTransit, Color{0xcccccc} }, // U11 OSM: 19926 WD: Q106879566 48.77, 9.168 x 48.8, 9.226
    { 14, NoLogo, 392, LineMetaDataContent::RapidTransit, Color{0x93bbe9} }, // U12 OSM: 19927 WD: Q106879567 48.72, 9.118 x 48.87, 9.271
    { 138, NoLogo, 392, LineMetaDataContent::RapidTransit, Color{0x69be51} }, // U14 OSM: 19928 WD: Q70723042 48.77, 9.168 x 48.84, 9.23
    { 142, NoLogo, 392, LineMetaDataContent::RapidTransit, Color{0x005aab} }, // U15 OSM: 19929 WD: Q106879570 48.74, 9.156 x 48.85, 9.234
    { 146, NoLogo, 392, LineMetaDataContent::RapidTransit, Color{0xcccccc} }, // U19 OSM: 19930 WD: Q106879572 48.79, 9.213 x 48.83, 9.238
    { 65, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x312783} }, // 10 OSM: 19941 53.06, 8.752 x 53.12, 8.9
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x005ca9} }, // 2 OSM: 19942 53.06, 8.752 x 53.12, 8.9
    { 151, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x9eb4a5} }, // 72 OSM: 20258 WD: Q6811968 -37.86, 145 x -37.8, 145.1
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf287b6} }, // 2 OSM: 22852 WD: Q56558793 54.09, 12.08 x 54.11, 12.17
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf8a500} }, // 6 OSM: 22871 WD: Q56558799 54.07, 12.09 x 54.09, 12.14
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x5d106a} }, // 1 OSM: 23389 WD: Q56558792 54.09, 12.05 x 54.16, 12.16
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x690713} }, // 3 OSM: 23742 WD: Q56558795 54.07, 12.09 x 54.11, 12.18
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc30175} }, // 4 OSM: 23743 WD: Q56558796 54.07, 12.1 x 54.11, 12.18
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe2001d} }, // 5 OSM: 23747 WD: Q56558797 54.06, 12.05 x 54.16, 12.14
    { 116, 559, 571, LineMetaDataContent::Subway, Color{0x029540} }, // U4 OSM: 27113 WD: Q877322 48.18, 16.26 x 48.25, 16.39
    { 122, 587, 571, LineMetaDataContent::Subway, Color{0x9c6830} }, // U6 OSM: 27115 WD: Q281409 48.13, 16.31 x 48.26, 16.4
    { 0, 599, NoLogo, LineMetaDataContent::Subway, Color{0x70b1d0} }, // U70 OSM: 27662 WD: Q661002 51.22, 6.566 x 51.33, 6.796
    { 154, 599, NoLogo, LineMetaDataContent::Subway, Color{0x0063af} }, // U76 OSM: 27663 WD: Q661002 51.22, 6.566 x 51.33, 6.806
    { 158, 599, NoLogo, LineMetaDataContent::Subway, Color{0x7197cf} }, // U77 OSM: 27667 WD: Q661002 51.17, 6.735 x 51.24, 6.834
    { 163, 613, 19, LineMetaDataContent::Tramway, Color{0x0b9ada} }, // 60 OSM: 28289 WD: Q62512766 52.44, 13.5 x 52.46, 13.64
    { 166, 632, 226, LineMetaDataContent::RapidTransit, Color{0x055a99} }, // S3 OSM: 28314 WD: Q7388282 52.43, 13.2 x 52.53, 13.75
    { 171, 662, 19, LineMetaDataContent::Tramway, Color{0x009933} }, // 67 OSM: 28352 WD: Q66459350 52.44, 13.51 x 52.46, 13.59
    { 175, 681, 19, LineMetaDataContent::Tramway, Color{0x993333} }, // 27 OSM: 28377 WD: Q66091843 52.44, 13.46 x 52.56, 13.59
    { 178, 700, 19, LineMetaDataContent::Tramway, Color{0xa6422a} }, // M17 OSM: 28391 WD: Q62512560 52.43, 13.51 x 52.57, 13.54
    { 183, 720, 19, LineMetaDataContent::Tramway, Color{0x36ab94} }, // 50 OSM: 28420 WD: Q62499869 52.54, 13.34 x 52.61, 13.43
    { 186, NoLogo, 599, LineMetaDataContent::Subway, Color{0x009a93} }, // U79 OSM: 28424 WD: Q1272295 51.19, 6.739 x 51.47, 6.815
    { 72, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x945692} }, // 21 OSM: 29440 WD: Q4415661 51.91, 4.368 x 51.94, 4.525
    { 191, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x945692} }, // 24 OSM: 29446 WD: Q14500289 51.91, 4.341 x 51.94, 4.525
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // 6 OSM: 30058 49.17, 16.55 x 49.23, 16.61
    { 54, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xd62631} }, // 11 OSM: 33897 51.28, 12.22 x 51.4, 12.4
    { 65, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xd62631} }, // 10 OSM: 33900 51.3, 12.32 x 51.37, 12.4
    { 26, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe3000f} }, // 16 OSM: 34068 51.3, 12.38 x 51.4, 12.4
    { 194, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x005395} }, // WLB OSM: 34086 WD: Q875199 48, 16.23 x 48.2, 16.37
    { 42, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0e4094} }, // 7 OSM: 34148 51.34, 12.27 x 51.36, 12.48
    { 88, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xcea4cb} }, // 68 OSM: 34480 50.7, 6.985 x 50.76, 7.156
    { 61, 739, 226, LineMetaDataContent::RapidTransit, Color{0x5c8e3c} }, // S1 OSM: 35610 WD: Q18946157 48.59, 8.861 x 48.8, 9.444
    { 50, 775, 226, LineMetaDataContent::RapidTransit, Color{0xff2e1d} }, // S2 OSM: 35611 WD: Q66537943 48.68, 9.105 x 48.83, 9.527
    { 166, 811, 226, LineMetaDataContent::RapidTransit, Color{0xff7d24} }, // S3 OSM: 35612 WD: Q67504621 48.69, 9.105 x 48.94, 9.426
    { 132, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe6877e} }, // 9 OSM: 36132 50.92, 6.907 x 50.94, 7.096
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8cc63f} }, // 12 OSM: 36133 50.9, 6.939 x 51.03, 6.96
    { 143, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00accd} }, // 15 OSM: 36134 50.92, 6.898 x 51.02, 6.966
    { 201, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x83898f} }, // 58 OSM: 37338 WD: Q28428375 -37.84, 144.9 x -37.74, 145
    { 204, 847, 226, LineMetaDataContent::RapidTransit, Color{0x874a0a} }, // S6 OSM: 37419 WD: Q67501804 48.76, 8.872 x 48.83, 9.195
    { 211, NoLogo, 883, LineMetaDataContent::Tramway, Color{0xff0000} }, // T1 OSM: 38872 WD: Q5985908 28.45, -16.32 x 28.49, -16.25
    { 143, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0e4094} }, // 15 OSM: 38883 51.29, 12.26 x 51.34, 12.44
    { 215, NoLogo, 599, LineMetaDataContent::Tramway, Color{0xc8d300} }, // 65 OSM: 39079 WD: Q20035842 50.72, 7.071 x 50.76, 7.156
    { 27, 921, NoLogo, LineMetaDataContent::Tramway, Color{0x9049a8} }, // 6 OSM: 48024 WD: Q62296933 52.13, 11.57 x 52.15, 11.68
    { 55, 949, NoLogo, LineMetaDataContent::Tramway, Color{0xb6005c} }, // 1 OSM: 48025 WD: Q62289804 52.11, 11.59 x 52.17, 11.64
    { 9, 977, NoLogo, LineMetaDataContent::Tramway, Color{0x73e700} }, // 4 OSM: 48453 WD: Q62295350 52.11, 11.58 x 52.16, 11.67
    { 6, 1005, NoLogo, LineMetaDataContent::Tramway, Color{0xb48654} }, // 5 OSM: 48459 WD: Q62296384 52.09, 11.58 x 52.16, 11.62
    { 196, 1033, 1055, LineMetaDataContent::RapidTransit, Color{0x32cd32} }, // B OSM: 51750 WD: Q1903862 55.65, 12.27 x 55.81, 12.59
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x62b32c} }, // 1 OSM: 51858 51.31, 12.26 x 51.38, 12.42
    { 122, 1065, 1095, LineMetaDataContent::Subway, Color{0x8070b7} }, // U6 OSM: 51942 WD: Q99720 52.44, 13.33 x 52.56, 13.39
    { 55, 1106, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 1 OSM: 52282 WD: Q106921117 57.64, 11.9 x 57.73, 12.05
    { 6, 1128, NoLogo, LineMetaDataContent::Tramway, Color{0xeb1923} }, // 5 OSM: 52617 WD: Q106921184 57.7, 11.89 x 57.74, 12.05
    { 42, 1150, NoLogo, LineMetaDataContent::Tramway, Color{0x7d4313} }, // 7 OSM: 53027 WD: Q10562726 57.64, 11.9 x 57.76, 12.07
    { 47, 1172, 226, LineMetaDataContent::RapidTransit, Color{0xffc734} }, // S8 OSM: 53231 WD: Q17148488 48, 11.17 x 48.35, 11.79
    { 218, 1188, 226, LineMetaDataContent::RapidTransit, Color{0xff2d1d} }, // S4 OSM: 53235 WD: Q7388308 48.04, 11.04 x 48.18, 11.97
    { 27, 1204, NoLogo, LineMetaDataContent::Tramway, Color{0xfa8719} }, // 6 OSM: 53254 WD: Q10562724 57.68, 11.89 x 57.76, 12.04
    { 132, 1226, NoLogo, LineMetaDataContent::Tramway, Color{0x1e8164} }, // 9 OSM: 53748 WD: Q62299846 52.08, 11.6 x 52.18, 11.64
    { 16, 1254, NoLogo, LineMetaDataContent::Tramway, Color{0x004799} }, // 2 OSM: 53752 WD: Q62291398 52.06, 11.63 x 52.15, 11.68
    { 19, 1282, NoLogo, LineMetaDataContent::Tramway, Color{0xf29400} }, // 8 OSM: 53770 WD: Q62299313 52.06, 11.63 x 52.18, 11.68
    { 204, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x3d2d7c} }, // S6 OSM: 53844 48.75, 8.549 x 48.9, 8.705
    { 65, 1310, NoLogo, LineMetaDataContent::Tramway, Color{0xaac1e1} }, // 10 OSM: 54125 WD: Q62288523 52.11, 11.59 x 52.21, 11.67
    { 65, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x9acd32} }, // 10 OSM: 54452 WD: Q318073 51.49, 10.77 x 51.58, 10.8
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xda0873} }, // 1 OSM: 54602 53.59, 11.41 x 53.65, 11.47
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xd9261c} }, // 2 OSM: 54603 53.59, 11.36 x 53.65, 11.47
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe87878} }, // 3 OSM: 54604 53.57, 11.38 x 53.6, 11.47
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xdb214c} }, // 4 OSM: 54605 53.57, 11.38 x 53.65, 11.43
    { 59, 1339, NoLogo, LineMetaDataContent::Tramway, Color{0xffd600} }, // 3 OSM: 55097 WD: Q62292031 52.09, 11.58 x 52.16, 11.63
    { 222, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x408040} }, // S 1 OSM: 55107 WD: Q56378592 52, 11.62 x 53.01, 11.87
    { 131, 1367, 1095, LineMetaDataContent::Subway, Color{0xff7300} }, // U9 OSM: 58423 WD: Q99744 52.46, 13.32 x 52.56, 13.37
    { 128, 1397, 1095, LineMetaDataContent::Subway, Color{0x055a99} }, // U8 OSM: 58424 WD: Q99729 52.47, 13.33 x 52.6, 13.43
    { 125, 1427, 1095, LineMetaDataContent::Subway, Color{0x0b9ada} }, // U7 OSM: 58425 WD: Q99725 52.42, 13.2 x 52.54, 13.5
    { 113, 1457, 1095, LineMetaDataContent::Subway, Color{0x15ac99} }, // U3 OSM: 58426 WD: Q99702 52.44, 13.24 x 52.51, 13.45
    { 110, 1487, 1095, LineMetaDataContent::Subway, Color{0xff3300} }, // U2 OSM: 58428 WD: Q99697 52.5, 13.24 x 52.57, 13.41
    { 116, 1517, 1095, LineMetaDataContent::Subway, Color{0xffcd00} }, // U4 OSM: 58429 WD: Q99708 52.48, 13.34 x 52.5, 13.36
    { 119, 1547, 1095, LineMetaDataContent::Subway, Color{0x7d533d} }, // U5 OSM: 58430 WD: Q99711 52.49, 13.37 x 52.54, 13.63
    { 107, 1577, 1095, LineMetaDataContent::Subway, Color{0x52b447} }, // U1 OSM: 58767 WD: Q99691 52.5, 13.33 x 52.51, 13.45
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf2a100} }, // 12 OSM: 58815 51.32, 12.37 x 51.38, 12.4
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffcc00} }, // 8 OSM: 58819 51.32, 12.28 x 51.36, 12.47
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x62b32c} }, // 3 OSM: 58829 51.28, 12.31 x 51.38, 12.49
    { 6, 1607, 1624, LineMetaDataContent::Tramway, Color{} }, // 5 OSM: 61453 WD: Q104867893 49.41, 11.07 x 49.46, 11.14
    { 179, 1648, 19, LineMetaDataContent::Tramway, Color{0x865a46} }, // 17 OSM: 61454 WD: Q20438593 48.13, 11.49 x 48.17, 11.57
    { 147, 1669, 19, LineMetaDataContent::Tramway, Color{0xdc281e} }, // 19 OSM: 61456 WD: Q20438608 48.14, 11.46 x 48.15, 11.63
    { 22, 1690, 19, LineMetaDataContent::Tramway, Color{0x00a03c} }, // 18 OSM: 61458 WD: Q20438601 48.1, 11.49 x 48.14, 11.6
    { 226, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x865a46} }, // N17 OSM: 61459 48.13, 11.49 x 48.17, 11.61
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf78a21} }, // 1 OSM: 61460 50.85, 12.07 x 50.89, 12.09
    { 50, 1711, 226, LineMetaDataContent::RapidTransit, Color{0x018a47} }, // S2 OSM: 61466 WD: Q3743635 52.34, 13.36 x 52.68, 13.59
    { 230, 1741, 226, LineMetaDataContent::RapidTransit, Color{0x018a47} }, // S25 OSM: 61469 WD: Q7388229 52.4, 13.21 x 52.64, 13.4
    { 113, 1772, 1095, LineMetaDataContent::Subway, Color{0xfcdf00} }, // U3 OSM: 62839 WD: Q781351 53.54, 9.969 x 53.59, 10.08
    { 235, 1787, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfaa635} }, // J OSM: 63222 WD: Q6109356 37.72, -122.4 x 37.79, -122.4
    { 238, 1805, NoLogo, LineMetaDataContent::Tramway, Color{0xf0e68c} }, // F OSM: 63224 WD: Q1137818 37.76, -122.4 x 37.81, -122.4
    { 61, 1833, 226, LineMetaDataContent::RapidTransit, Color{0x36caec} }, // S1 OSM: 63809 WD: Q7388207 48.13, 11.48 x 48.4, 11.79
    { 204, 1849, 226, LineMetaDataContent::RapidTransit, Color{0x00ac6f} }, // S6 OSM: 63839 WD: Q7388348 47.91, 11.27 x 48.15, 11.97
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff7f00} }, // 3 OSM: 63875 51.82, 12.18 x 51.84, 12.24
    { 240, 1865, 226, LineMetaDataContent::RapidTransit, Color{0xba8a4d} }, // S46 OSM: 64094 WD: Q3737194 52.3, 13.28 x 52.52, 13.64
    { 244, 1899, 226, LineMetaDataContent::RapidTransit, Color{0xba8a4d} }, // S45 OSM: 64095 WD: Q2090939 52.36, 13.36 x 52.48, 13.57
    { 231, 1930, 19, LineMetaDataContent::Tramway, Color{0xe6828c} }, // 25 OSM: 66008 WD: Q20439051 48.04, 11.52 x 48.14, 11.6
    { 15, 1951, 19, LineMetaDataContent::Tramway, Color{0x903f98} }, // 12 OSM: 66043 WD: Q20438570 48.15, 11.51 x 48.17, 11.58
    { 26, 1972, 19, LineMetaDataContent::Tramway, Color{0x006cb2} }, // 16 OSM: 66044 WD: Q20438583 48.13, 11.51 x 48.18, 11.64
    { 175, 1993, 19, LineMetaDataContent::Tramway, Color{0xf0a014} }, // 27 OSM: 66053 WD: Q20439073 48.13, 11.56 x 48.18, 11.58
    { 249, 2014, 19, LineMetaDataContent::Tramway, Color{0x00aadc} }, // 20 OSM: 66079 WD: Q20438843 48.14, 11.51 x 48.18, 11.56
    { 72, 2035, 19, LineMetaDataContent::Tramway, Color{0x00aadc} }, // 21 OSM: 66080 WD: Q20439015 48.12, 11.53 x 48.17, 11.64
    { 254, 2063, 19, LineMetaDataContent::Tramway, Color{0x96c81e} }, // 23 OSM: 66100 WD: Q20439033 48.16, 11.59 x 48.19, 11.59
    { 257, 2084, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe67310} }, // A3 OSM: 66588 WD: Q19606155 53.75, 9.656 x 53.8, 9.983
    { 218, 2099, 226, LineMetaDataContent::RapidTransit, Color{0x0065b7} }, // S4 OSM: 66840 WD: Q67504669 48.77, 9.155 x 48.95, 9.426
    { 260, 2135, 2154, LineMetaDataContent::RapidTransit, Color{0x8d1d81} }, // S51 OSM: 67184 WD: Q116125186 46.7, 15.63 x 46.73, 15.99
    { 265, 2173, 19, LineMetaDataContent::Tramway, Color{0xee6600} }, // M1 OSM: 67233 WD: Q62512139 52.52, 13.37 x 52.6, 13.41
    { 44, 2192, 226, LineMetaDataContent::RapidTransit, Color{0x00b7e1} }, // S5 OSM: 67283 WD: Q18926034 48.77, 9.122 x 48.95, 9.195
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf59e00} }, // 3 OSM: 69178 47.97, 7.796 x 48, 7.85
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe8001b} }, // 1 OSM: 69191 47.98, 7.808 x 48.03, 7.895
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008bc5} }, // 5 OSM: 69199 47.99, 7.788 x 48, 7.852
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x13a538} }, // 2 OSM: 69202 47.96, 7.833 x 48.02, 7.858
    { 272, NoLogo, 2228, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // Blue OSM: 71390 WD: Q6714611 45.49, -123 x 45.54, -122.4
    { 277, NoLogo, 2228, LineMetaDataContent::RapidTransit, Color{0xffff00} }, // Yellow OSM: 71397 WD: Q6714624 45.51, -122.7 x 45.61, -122.7
    { 284, NoLogo, 2228, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // Red OSM: 71404 WD: Q6714623 45.49, -122.8 x 45.59, -122.6
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf6a6ab} }, // 1 OSM: 71785 WD: Q106996879 47.25, 11.39 x 47.28, 11.41
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xd66775} }, // 3 OSM: 71787 WD: Q106996895 47.26, 11.39 x 47.27, 11.43
    { 9, 2248, 1624, LineMetaDataContent::Tramway, Color{} }, // 4 OSM: 72527 WD: Q104867838 49.43, 11.05 x 49.49, 11.07
    { 19, 2265, 1624, LineMetaDataContent::Tramway, Color{} }, // 8 OSM: 73226 WD: Q104868033 49.43, 11.08 x 49.47, 11.14
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfbba00} }, // 1 OSM: 73662 51.47, 11.96 x 51.51, 11.99
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff9900} }, // 2 OSM: 73667 WD: Q61889098 51.43, 11.89 x 51.49, 11.99
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0066cc} }, // 3 OSM: 73670 WD: Q61887067 51.43, 11.96 x 51.52, 11.99
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x9b1006} }, // 4 OSM: 73671 WD: Q61889270 51.44, 11.93 x 51.51, 11.99
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0f3f93} }, // 5 OSM: 73672 WD: Q61889316 51.29, 11.93 x 51.51, 12.07
    { 42, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff6699} }, // 7 OSM: 73929 WD: Q61889355 51.48, 11.93 x 51.51, 12.04
    { 132, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x999933} }, // 9 OSM: 73932 WD: Q61889418 51.48, 11.89 x 51.48, 11.99
    { 65, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x336633} }, // 10 OSM: 73933 WD: Q61889438 51.48, 11.9 x 51.49, 11.99
    { 53, 2282, 2154, LineMetaDataContent::RapidTransit, Color{0x00983a} }, // S11 OSM: 76229 WD: Q116125180 47.2, 15.24 x 47.23, 15.34
    { 291, NoLogo, 2301, LineMetaDataContent::Tramway, Color{} }, // 89 OSM: 77259 WD: Q534882 52.53, 13.84 x 52.58, 13.88
    { 61, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x800000} }, // S1 OSM: 77908 WD: Q7388209 49.44, 10.9 x 49.9, 11.56
    { 50, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x65b949} }, // S2 OSM: 77962 WD: Q7388248 49.24, 11.04 x 49.45, 11.35
    { 166, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0xf05c3d} }, // S3 OSM: 77971 WD: Q7388284 49.27, 11.08 x 49.45, 11.46
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xef1c29} }, // 3 OSM: 78206 50.84, 12.05 x 50.91, 12.1
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x4098de} }, // 3 OSM: 79325 WD: Q60318542 51.72, 14.3 x 51.76, 14.35
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xa81a30} }, // 6 OSM: 89518 WD: Q1664234 47.23, 11.4 x 47.26, 11.44
    { 204, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x0066b3} }, // S6 OSM: 91626 WD: Q115646650 46.9, 7.778 x 47.22, 8.31
    { 41, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x78b6e4} }, // S7 OSM: 91629 WD: Q115646652 47.06, 7.778 x 47.22, 8.082
    { 294, 2333, NoLogo, LineMetaDataContent::LocalTrain, Color{0xf37231} }, // RE 30 OSM: 93946 WD: Q113462371 49.44, 11.08 x 49.95, 11.63
    { 300, 2350, NoLogo, LineMetaDataContent::LocalTrain, Color{0xf09280} }, // RB 12 OSM: 100360 WD: Q114717482 49.44, 10.66 x 49.51, 11.09
    { 9, 2367, 2400, LineMetaDataContent::Subway, Color{0x800080} }, // 4 OSM: 102389 WD: Q54373 43.76, -79.41 x 43.78, -79.35
    { 59, 2408, 2400, LineMetaDataContent::RapidTransit, Color{0x0093dd} }, // 3 OSM: 102390 WD: Q54372 43.73, -79.28 x 43.78, -79.25
    { 306, 2447, 2474, LineMetaDataContent::RapidTransit, Color{0xef7b10} }, // LO OSM: 112649 WD: Q1854601 51.46, -0.3961 x 51.66, 0.1233
    { 311, 2497, 2529, LineMetaDataContent::RapidTransit, Color{0xfcd946} }, // C OSM: 122886 WD: Q200906 48.43, 1.995 x 49.05, 2.427
    { 313, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0066cc} }, // LS OSM: 129379 WD: Q15982573 -35.19, -59.43 x -34.58, -58.41
    { 316, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0066cc} }, // LSM OSM: 129382 WD: Q3239199 -34.61, -59.08 x -34.45, -58.37
    { 320, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0066cc} }, // LM OSM: 129383 WD: Q66759479 -34.59, -59.1 x -34.1, -58.37
    { 323, 2559, NoLogo, LineMetaDataContent::RapidTransit, Color{0xef3e33} }, // LU OSM: 129393 WD: Q7887242 -34.6, -58.7 x -34.53, -58.46
    { 329, 2589, 2617, LineMetaDataContent::Tramway, Color{0xf38733} }, // P OSM: 129505 WD: Q3409024 -34.69, -58.47 x -34.64, -58.44
    { 174, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf0a014} }, // N27 OSM: 129569 48.08, 11.55 x 48.18, 11.59
    { 334, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe33385} }, // 96 OSM: 132386 WD: Q12061652 -37.87, 145 x -37.77, 145
    { 337, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfeba10} }, // 86 OSM: 137969 WD: Q12061650 -37.82, 144.9 x -37.68, 145.1
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x88d1f0} }, // 3 OSM: 144407 WD: Q6811954 -37.89, 145 x -37.8, 145.1
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe04038} }, // 5 OSM: 145649 WD: Q6811959 -37.87, 145 x -37.8, 145.1
    { 342, 2632, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 49 OSM: 147322 WD: Q1491114 47.47, 19.02 x 47.5, 19.06
    { 346, 2656, 2668, LineMetaDataContent::Subway, Color{0xfdc110} }, // M2 OSM: 152340 WD: Q1880954 55.63, 12.49 x 55.69, 12.65
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009640} }, // 1 OSM: 153893 53.04, 8.741 x 53.16, 8.965
    { 349, 2694, NoLogo, LineMetaDataContent::LocalTrain, Color{0x2a89ca} }, // RB 80 OSM: 158860 WD: Q114713941 48.96, 9.933 x 49.8, 10.91
    { 44, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x23c4fc} }, // S5 OSM: 160986 WD: Q55632180 49.26, 11.08 x 49.45, 11.21
    { 355, 2711, NoLogo, LineMetaDataContent::LocalTrain, Color{0x5d97ce} }, // RB 81 OSM: 161886 WD: Q107110025 49.45, 10.27 x 49.58, 10.59
    { 363, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x9085ba} }, // E OSM: 163591 WD: Q2903493 48.53, 7.733 x 48.61, 7.786
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xec008c} }, // 1 OSM: 163714 52.47, -2.125 x 52.58, -1.896
    { 15, 2728, NoLogo, LineMetaDataContent::RapidTransit, Color{0x98002e} }, // 12 OSM: 163759 WD: Q3239135 43.11, -79.89 x 43.65, -79.06
    { 265, 2755, 2779, LineMetaDataContent::Subway, Color{0x0075be} }, // M1 OSM: 165613 WD: Q3238660 43.29, 5.374 x 43.33, 5.43
    { 346, 2811, 2779, LineMetaDataContent::Subway, Color{0xe30513} }, // M2 OSM: 165618 WD: Q3238804 43.27, 5.367 x 43.33, 5.403
    { 368, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x49805b} }, // 59 OSM: 167658 WD: Q6811962 -37.82, 144.9 x -37.71, 145
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x003828} }, // 1 OSM: 170076 52.92, -1.263 x 53.04, -1.145
    { 371, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x42816b} }, // 181 (SN) OSM: 172834 51.28, -0.1728 x 51.49, -0.07193
    { 277, NoLogo, 2835, LineMetaDataContent::RapidTransit, Color{0xd39f06} }, // Yellow OSM: 172864 WD: Q19960799 54.95, -1.623 x 55.04, -1.429
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x78ccc9} }, // 3 OSM: 173596 50.42, 30.37 x 50.45, 30.49
    { 380, 2860, 226, LineMetaDataContent::RapidTransit, Color{0x52b447} }, // S85 OSM: 175267 WD: Q4048677 52.41, 13.4 x 52.57, 13.58
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x82cee6} }, // 8 OSM: 178504 39.46, -0.339 x 39.46, -0.3254
    { 27, 2891, NoLogo, LineMetaDataContent::Tramway, Color{0x9b70cb} }, // 6 OSM: 178505 WD: Q3832664 39.46, -0.3726 x 39.5, -0.3256
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x004a99} }, // 4 OSM: 178506 39.47, -0.4364 x 39.53, -0.3256
    { 6, 2922, NoLogo, LineMetaDataContent::Subway, Color{0x009870} }, // 5 OSM: 178522 WD: Q3238965 39.46, -0.4744 x 39.49, -0.3383
    { 59, 2953, NoLogo, LineMetaDataContent::Subway, Color{0xdd052b} }, // 3 OSM: 178523 WD: Q3238906 39.47, -0.4744 x 39.59, -0.33
    { 55, 2984, NoLogo, LineMetaDataContent::Subway, Color{0xfdc600} }, // 1 OSM: 178526 WD: Q2165952 39.08, -0.5268 x 39.59, -0.3815
    { 385, 3015, 3043, LineMetaDataContent::Tramway, Color{0xc19dc2} }, // L4 OSM: 190184 WD: Q5474600 38.35, -0.4907 x 38.38, -0.4118
    { 389, 3084, 3043, LineMetaDataContent::Tramway, Color{0xd72028} }, // L1 OSM: 190196 WD: Q594538 38.35, -0.4907 x 38.55, -0.1348
    { 393, NoLogo, 3043, LineMetaDataContent::Tramway, Color{0x00ff00} }, // L2 OSM: 190199 WD: Q9025903 38.35, -0.5172 x 38.39, -0.4678
    { 397, NoLogo, 3043, LineMetaDataContent::Tramway, Color{0xf9d114} }, // L3 OSM: 190203 WD: Q9025931 38.35, -0.4907 x 38.43, -0.3952
    { 400, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf58122} }, // 109 OSM: 190802 WD: Q6811947 -37.84, 144.9 x -37.81, 145.1
    { 311, 3112, 1055, LineMetaDataContent::RapidTransit, Color{0xffa500} }, // C OSM: 191280 WD: Q4452746 55.66, 12.07 x 55.84, 12.59
    { 34, 3134, 1055, LineMetaDataContent::RapidTransit, Color{0xe64415} }, // H OSM: 191281 WD: Q1891933 55.66, 12.07 x 55.84, 12.59
    { 405, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x33bdca} }, // 57 OSM: 196209 WD: Q16926803 -37.82, 144.9 x -37.77, 145
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0e4094} }, // 4 OSM: 207342 51.32, 12.36 x 51.38, 12.43
    { 362, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0e4094} }, // 4E OSM: 207342 51.32, 12.36 x 51.38, 12.43
    { 408, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00a5e3} }, // North Jersey Coast OSM: 207401 WD: Q7055732 40.07, -74.29 x 40.77, -73.99
    { 16, 3156, NoLogo, LineMetaDataContent::Subway, Color{0x97d700} }, // 2 OSM: 207417 WD: Q1325437 31.15, 121.3 x 31.24, 121.8
    { 430, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x434244} }, // 48 OSM: 207445 WD: Q16926797 -37.82, 144.9 x -37.79, 145.1
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 1 OSM: 207718 45.55, 18.62 x 45.57, 18.73
    { 324, 3165, 3199, LineMetaDataContent::RapidTransit, Color{0xb90845} }, // U OSM: 215565 WD: Q93559 48.76, 1.943 x 48.89, 2.237
    { 42, 3231, NoLogo, LineMetaDataContent::Subway, Color{0xff6900} }, // 7 OSM: 228608 WD: Q2707909 31.17, 121.3 x 31.41, 121.6
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffff00} }, // 8 OSM: 237270 49.17, 16.55 x 49.21, 16.69
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00ff00} }, // 2 OSM: 237285 49.13, 16.59 x 49.2, 16.64
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 1 OSM: 237306 49.19, 16.51 x 49.25, 16.61
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x738ba4} }, // 12 OSM: 241383 WD: Q1759931 59.32, 17.92 x 59.33, 17.98
    { 297, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xd77d00} }, // 30 OSM: 241384 WD: Q1760190 59.29, 17.96 x 59.36, 18.12
    { 434, 3240, 3269, LineMetaDataContent::RapidTransit, Color{0xf166a7} }, // 43 OSM: 241411 WD: Q106806959 58.9, 17.53 x 59.57, 18.16
    { 439, 3240, 3269, LineMetaDataContent::RapidTransit, Color{0xf166a7} }, // 41 OSM: 241413 WD: Q106806951 59.17, 17.63 x 59.63, 18.07
    { 430, 3240, 3269, LineMetaDataContent::RapidTransit, Color{0xf166a7} }, // 48 OSM: 241414 WD: Q106808255 59.04, 17.31 x 59.19, 17.65
    { 443, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0066cc} }, // TS OSM: 252385 WD: Q802144 -31.42, -64.49 x -31.12, -64.17
    { 447, 3304, 3199, LineMetaDataContent::RapidTransit, Color{0x9f9825} }, // K OSM: 253357 WD: Q93382 48.88, 2.352 x 49.23, 2.887
    { 449, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x007dc5} }, // ISL OSM: 269670 WD: Q989316 22.26, 114.1 x 22.29, 114.2
    { 453, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xf7943e} }, // TCL OSM: 269671 WD: Q989358 22.28, 113.9 x 22.36, 114.2
    { 458, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 1R OSM: 271401 47.05, 21.91 x 47.08, 21.94
    { 461, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x00888a} }, // AEL OSM: 272078 WD: Q409036 22.29, 113.9 x 22.36, 114.2
    { 465, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x53b7e8} }, // EAL OSM: 272132 WD: Q989339 22.28, 114.1 x 22.53, 114.2
    { 469, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x923011} }, // TML OSM: 272133 WD: Q5329661 22.29, 114 x 22.45, 114.2
    { 222, 3338, NoLogo, LineMetaDataContent::Tramway, Color{0xef7c00} }, // S 1 OSM: 273002 WD: Q65643711 49.11, 6.891 x 49.41, 7.069
    { 473, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff7e00} }, // 28E OSM: 274460 WD: Q63034669 38.71, -9.17 x 38.72, -9.128
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // 2 OSM: 300207 48.46, 34.61 x 48.52, 34.69
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff00ff} }, // 1 OSM: 300208 48.51, 34.57 x 48.52, 34.62
    { 477, 3356, 226, LineMetaDataContent::RapidTransit, Color{0x9a3052} }, // S9 OSM: 304163 WD: Q4048680 52.36, 13.2 x 52.53, 13.57
    { 480, NoLogo, 2228, LineMetaDataContent::RapidTransit, Color{0x008000} }, // Green OSM: 304623 WD: Q6714613 45.44, -122.7 x 45.54, -122.6
    { 265, 3386, 3398, LineMetaDataContent::Subway, Color{0x0000ff} }, // M1 OSM: 309619 WD: Q17462780 52.13, 20.93 x 52.29, 21.07
    { 477, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf49ac1} }, // S9 OSM: 349282 47.3, 9.039 x 47.46, 9.088
    { 329, NoLogo, 3420, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // P OSM: 357191 WD: Q118874962 60.17, 24.84 x 60.33, 25.06
    { 486, 3455, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // C-1 OSM: 357967 WD: Q3239078 43.25, -3.03 x 43.33, -2.928
    { 491, NoLogo, 3420, LineMetaDataContent::RapidTransit, Color{0x035eb9} }, // I OSM: 358139 WD: Q118874956 60.17, 24.84 x 60.33, 25.06
    { 493, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x630016} }, // STB OSM: 359908 WD: Q872840 47.16, 11.35 x 47.27, 11.4
    { 498, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x723b1f} }, // 35 OSM: 363305 WD: Q5123100 -37.82, 144.9 x -37.81, 145
    { 501, 3480, NoLogo, LineMetaDataContent::LocalTrain, Color{} }, // RB 55 OSM: 363679 WD: Q108409627 47.68, 11.53 x 48.14, 12.01
    { 147, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8f4a78} }, // 19 OSM: 363891 WD: Q6811950 -37.82, 145 x -37.73, 145
    { 166, 3497, 226, LineMetaDataContent::RapidTransit, Color{0x862996} }, // S3 OSM: 364187 WD: Q56996474 47.88, 11.17 x 48.22, 11.7
    { 507, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // SIR1 OSM: 365296 WD: Q107133892 45.37, 11.87 x 45.44, 11.89
    { 513, 3513, NoLogo, LineMetaDataContent::Subway, Color{0x6cbe45} }, // G OSM: 366764 WD: Q126527 40.64, -74 x 40.75, -73.94
    { 42, 3539, NoLogo, LineMetaDataContent::Subway, Color{0xb933ad} }, // 7 OSM: 366765 WD: Q126203 40.74, -74 x 40.76, -73.83
    { 314, 3565, NoLogo, LineMetaDataContent::Subway, Color{0x808183} }, // S OSM: 366766 WD: Q126698 40.75, -73.99 x 40.76, -73.98
    { 517, 3591, NoLogo, LineMetaDataContent::Subway, Color{0xfccc0a} }, // N OSM: 366768 WD: Q126434 40.58, -74.02 x 40.78, -73.91
    { 519, 3617, NoLogo, LineMetaDataContent::Subway, Color{0xfccc0a} }, // Q OSM: 366769 WD: Q126448 40.58, -74 x 40.78, -73.95
    { 524, 3643, NoLogo, LineMetaDataContent::Subway, Color{0x0039a6} }, // A OSM: 366774 WD: Q126344 40.58, -74.01 x 40.87, -73.75
    { 27, 3669, NoLogo, LineMetaDataContent::Subway, Color{0x00933c} }, // 6 OSM: 366777 WD: Q126192 40.71, -74.01 x 40.85, -73.83
    { 459, 3695, NoLogo, LineMetaDataContent::Subway, Color{0xfccc0a} }, // R OSM: 366780 WD: Q126459 40.62, -74.03 x 40.77, -73.84
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 8 OSM: 367548 47.2, 38.88 x 47.22, 38.94
    { 526, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x9acd32} }, // Bx OSM: 367751 55.65, 12.27 x 55.75, 12.59
    { 238, 3721, 1055, LineMetaDataContent::RapidTransit, Color{0xffc225} }, // F OSM: 381625 WD: Q2133631 55.65, 12.49 x 55.73, 12.57
    { 42, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008030} }, // 7 OSM: 382533 WD: Q2590490 51.91, 4.471 x 51.93, 4.526
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xdf60a4} }, // 8 OSM: 382535 WD: Q3277304 51.9, 4.432 x 51.95, 4.488
    { 231, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x6192c7} }, // 25 OSM: 382566 WD: Q2321951 51.84, 4.46 x 51.96, 4.514
    { 65, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xa05a2c} }, // 10 OSM: 383124 49.19, 16.51 x 49.23, 16.68
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00ccff} }, // 12 OSM: 384321 49.18, 16.58 x 49.23, 16.62
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff00ff} }, // 5 OSM: 384539 49.16, 16.59 x 49.22, 16.63
    { 54, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xafca28} }, // 11 OSM: 384541 49.21, 16.56 x 49.22, 16.57
    { 529, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe40000} }, // 155 OSM: 391346 46.38, 6.073 x 46.47, 6.235
    { 533, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa3429b} }, // TER T2 OSM: 394022 WD: Q3536981 47.09, -1.542 x 47.22, -1.286
    { 363, 3743, 1055, LineMetaDataContent::RapidTransit, Color{0x9370db} }, // E OSM: 394091 WD: Q4624816 55.46, 12.17 x 55.81, 12.59
    { 54, 3765, NoLogo, LineMetaDataContent::Subway, Color{0x76232f} }, // 11 OSM: 396879 WD: Q2636308 31.13, 120.8 x 31.4, 121.7
    { 16, 3775, 3795, LineMetaDataContent::Subway, Color{0x00529b} }, // 2 OSM: 414866 WD: Q680973 39.9, 116.3 x 39.95, 116.4
    { 55, 3830, 3795, LineMetaDataContent::Subway, Color{0xa12830} }, // 1 OSM: 415571 WD: Q748987 39.85, 116.1 x 39.95, 116.7
    { 58, 3850, 3795, LineMetaDataContent::Subway, Color{0xf9e700} }, // 13 OSM: 417951 WD: Q847744 39.94, 116.3 x 40.07, 116.5
    { 265, 3871, 3887, LineMetaDataContent::Subway, Color{0xffd800} }, // M1 OSM: 418343 WD: Q1078111 47.5, 19.05 x 47.52, 19.09
    { 537, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x006d78} }, // T2 OSM: 418631 WD: Q16011471 47.22, 5.951 x 47.25, 6.03
    { 65, 3901, 3795, LineMetaDataContent::Subway, Color{0x178abb} }, // 10 OSM: 420835 WD: Q847886 39.84, 116.3 x 39.98, 116.5
    { 6, 3922, 3795, LineMetaDataContent::Subway, Color{0xae005f} }, // 5 OSM: 420836 WD: Q647340 39.84, 116.4 x 40.08, 116.4
    { 19, 3942, 3795, LineMetaDataContent::Subway, Color{0x00997a} }, // 8 OSM: 420837 WD: Q847771 39.76, 116.3 x 40.1, 116.4
    { 9, 3962, 3795, LineMetaDataContent::Subway, Color{0x008994} }, // 4 OSM: 420838 WD: Q304264 39.67, 116.3 x 40.01, 116.4
    { 19, 3982, NoLogo, LineMetaDataContent::Subway, Color{0x008c95} }, // 8 OSM: 443998 WD: Q862965 23.09, 113.2 x 23.24, 113.4
    { 42, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xeb262b} }, // 7 OSM: 446001 WD: Q3743333 40.83, 14.27 x 40.88, 14.34
    { 459, 4002, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // R OSM: 447451 WD: Q697140 25.03, 121.4 x 25.17, 121.6
    { 55, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0026ff} }, // 1 OSM: 453141 WD: Q104222652 36.23, 59.44 x 36.35, 59.64
    { 61, 4026, 226, LineMetaDataContent::RapidTransit, Color{0xd474ae} }, // S1 OSM: 454054 WD: Q2579762 52.42, 13.18 x 52.75, 13.4
    { 41, 4056, 226, LineMetaDataContent::RapidTransit, Color{0x20543f} }, // S7 OSM: 456933 WD: Q2588691 49.83, 8.488 x 50.11, 8.664
    { 211, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe40716} }, // T1 OSM: 535990 WD: Q3239228 45.41, 4.364 x 45.48, 4.394
    { 521, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0363ff} }, // T1 A OSM: 548496 WD: Q1688502 36.72, 3.083 x 36.78, 3.263
    { 55, 4073, NoLogo, LineMetaDataContent::RapidTransit, Color{0xbf4525} }, // 1 OSM: 556308 WD: Q110248494 60.29, 5.232 x 60.39, 5.361
    { 543, NoLogo, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 56 OSM: 557061 WD: Q1491414 47.43, 18.96 x 47.54, 19.05
    { 147, 4099, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 19 OSM: 557063 WD: Q776651 47.47, 19.02 x 47.55, 19.05
    { 547, 4123, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 47 OSM: 557066 WD: Q1491058 47.43, 19.04 x 47.5, 19.06
    { 439, 4147, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 41 OSM: 557068 WD: Q1490823 47.44, 18.98 x 47.55, 19.05
    { 84, 4171, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 61 OSM: 557070 WD: Q1491592 47.48, 18.96 x 47.54, 19.05
    { 16, 4195, NoLogo, LineMetaDataContent::Tramway, Color{0x0068b3} }, // 2 OSM: 563459 WD: Q78198199 48.32, 10.84 x 48.38, 10.91
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xef7c00} }, // 8 OSM: 563484 48.33, 10.89 x 48.37, 10.9
    { 162, 4215, 226, LineMetaDataContent::RapidTransit, Color{0x928d1d} }, // S60 OSM: 570588 WD: Q63952011 48.69, 8.922 x 48.83, 9.195
    { 550, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff6600} }, // MSC 1908 OSM: 660480 14.2, 121 x 14.62, 121.2
    { 163, 4252, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 60 OSM: 899388 WD: Q851167 47.5, 18.98 x 47.51, 19.01
    { 368, 4276, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 59 OSM: 906131 WD: Q744461 47.48, 19 x 47.51, 19.02
    { 179, 4300, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 17 OSM: 911937 WD: Q1486400 47.44, 19.02 x 47.55, 19.05
    { 26, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffda66} }, // 16 OSM: 916109 WD: Q16926791 -37.87, 145 x -37.8, 145
    { 559, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffa21d} }, // MD-W OSM: 932986 WD: Q5250950 41.88, -88.33 x 42.06, -87.64
    { 564, 4321, NoLogo, LineMetaDataContent::LocalTrain, Color{0x269900} }, // RE7 OSM: 939026 WD: Q95186801 51.53, 12.23 x 52.53, 14.06
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x19633a} }, // 6 OSM: 962031 47.06, 15.41 x 47.08, 15.48
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x68ba45} }, // 3 OSM: 962059 47.07, 15.42 x 47.1, 15.46
    { 42, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe42714} }, // 7 OSM: 962240 47.06, 15.39 x 47.08, 15.47
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00b8ea} }, // 1 OSM: 962920 47.07, 15.39 x 47.11, 15.49
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x95c11f} }, // 8 OSM: 963052 53.05, 8.741 x 53.1, 8.841
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffcc00} }, // 6 OSM: 963103 53.05, 8.783 x 53.11, 8.859
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x025191} }, // 5 OSM: 963685 47.03, 15.42 x 47.1, 15.45
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xdeaa2e} }, // 4 OSM: 963737 47.04, 15.41 x 47.07, 15.46
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe30613} }, // 4 OSM: 964983 53.03, 8.799 x 53.16, 8.945
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009fe3} }, // 3 OSM: 966312 53.06, 8.752 x 53.12, 8.868
    { 211, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x808080} }, // T1 OSM: 1059709 WD: Q107172293 42.84, -2.702 x 42.87, -2.649
    { 568, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0075bf} }, // N10 OSM: 1070763 53.06, 8.752 x 53.12, 8.9
    { 572, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe30613} }, // N4 OSM: 1070810 53.03, 8.799 x 53.16, 8.945
    { 575, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009640} }, // N1 OSM: 1070812 53.04, 8.741 x 53.09, 8.965
    { 27, 4340, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 6 OSM: 1102938 WD: Q1491542 47.48, 19.02 x 47.51, 19.07
    { 9, 4363, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 4 OSM: 1102941 WD: Q1490736 47.47, 19.02 x 47.51, 19.07
    { 578, 4386, 4401, LineMetaDataContent::RapidTransit, Color{0x8a236c} }, // H5 OSM: 1103027 WD: Q1031914 47.51, 19.03 x 47.66, 19.08
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffc734} }, // 1 OSM: 1105466 52.4, 12.47 x 52.43, 12.57
    { 582, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x1aaa6f} }, // 64 OSM: 1110830 WD: Q6811964 -37.91, 145 x -37.8, 145
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x004c6c} }, // 6 OSM: 1111658 WD: Q16926785 -37.86, 145 x -37.76, 145.1
    { 171, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xac7963} }, // 67 OSM: 1111659 WD: Q6811965 -37.89, 145 x -37.8, 145.1
    { 585, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfaa634} }, // Raritan Valley OSM: 1122386 WD: Q7294577 40.56, -74.9 x 40.74, -74.16
    { 600, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xf173ac} }, // DRL OSM: 1139477 WD: Q989330 22.32, 114 x 22.33, 114
    { 524, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xed389c} }, // A OSM: 1142411 45.5, -122.7 x 45.53, -122.7
    { 604, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe41f25} }, // N82 OSM: 1147592 48.24, 14.28 x 48.33, 14.36
    { 183, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe41f25} }, // 50 OSM: 1149422 48.31, 14.26 x 48.32, 14.29
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe41f25} }, // 2 OSM: 1149423 48.24, 14.28 x 48.33, 14.36
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe41f25} }, // 3 OSM: 1149424 48.23, 14.23 x 48.31, 14.29
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe41f25} }, // 1 OSM: 1149425 48.25, 14.28 x 48.33, 14.32
    { 110, 4425, 1095, LineMetaDataContent::Subway, Color{0x00a54f} }, // U2 OSM: 1150977 WD: Q3040891 50.1, 8.64 x 50.22, 8.688
    { 608, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0039a6} }, // Harlem OSM: 1158719 WD: Q5658559 40.75, -73.98 x 41.82, -73.55
    { 68, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008be0} }, // TER 21 OSM: 1184795 45.67, 4.755 x 45.77, 4.827
    { 615, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x009b3a} }, // Hudson OSM: 1186686 40.75, -73.99 x 41.71, -73.86
    { 622, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff7900} }, // Port Jervis OSM: 1190915 WD: Q7230730 41.11, -74.69 x 41.49, -74.09
    { 389, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe52422} }, // L1 OSM: 1190932 WD: Q28662810 41.62, -0.9378 x 41.69, -0.8708
    { 634, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0065ff} }, // SFM 2 OSM: 1210497 WD: Q3832754 44.89, 7.337 x 45.19, 7.89
    { 640, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x95aa53} }, // 308 OSM: 1228606 51.4, 7.16 x 51.52, 7.284
    { 644, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xb14e7a} }, // 310 OSM: 1228607 51.44, 7.152 x 51.48, 7.337
    { 497, NoLogo, 599, LineMetaDataContent::Subway, Color{0x294488} }, // U35 OSM: 1228608 WD: Q2466100 51.45, 7.21 x 51.55, 7.273
    { 21, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x72a7a0} }, // 318 OSM: 1228609 51.42, 7.143 x 51.52, 7.284
    { 648, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xea504c} }, // 306 OSM: 1228610 51.48, 7.16 x 51.53, 7.223
    { 652, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x6ba5d9} }, // 302 OSM: 1228611 51.46, 7.056 x 51.58, 7.324
    { 656, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00b2f6} }, // 301 OSM: 1236118 51.5, 7.026 x 51.58, 7.11
    { 660, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf47a14} }, // S 5 OSM: 1241173 49.14, 8.674 x 49.42, 9.102
    { 664, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0039a6} }, // Port Jefferson OSM: 1255264 WD: Q7230720 40.7, -73.99 x 40.94, -73.05
    { 679, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe00034} }, // New Haven OSM: 1260624 40.75, -73.98 x 41.31, -72.92
    { 689, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x89728e} }, // VMLR OSM: 1266358 33.41, -112.1 x 33.57, -111.8
    { 537, NoLogo, 883, LineMetaDataContent::Tramway, Color{0x0000ff} }, // T2 OSM: 1286854 WD: Q5986172 28.44, -16.3 x 28.47, -16.29
    { 694, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00af3f} }, // Oyster Bay OSM: 1308975 WD: Q7116314 40.7, -73.99 x 40.88, -73.53
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 3 OSM: 1343415 55.64, 37.6 x 55.76, 37.65
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 1 OSM: 1343815 55.6, 37.59 x 55.66, 37.61
    { 26, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 16 OSM: 1348910 55.6, 37.59 x 55.7, 37.63
    { 393, 4442, 3795, LineMetaDataContent::Subway, Color{0xd61572} }, // L2 OSM: 1350576 WD: Q5944471 39.77, 116.4 x 39.84, 116.6
    { 191, 4442, 3795, LineMetaDataContent::Subway, Color{0xd61572} }, // 24 OSM: 1350576 WD: Q5944471 39.77, 116.4 x 39.84, 116.6
    { 175, 4469, 3795, LineMetaDataContent::Subway, Color{0xd47daa} }, // 27 OSM: 1350622 WD: Q5066697 39.97, 116.2 x 40.24, 116.3
    { 515, 4497, 3795, LineMetaDataContent::Subway, Color{0xd85f26} }, // 25N OSM: 1350671 WD: Q5433860 39.72, 116.1 x 39.86, 116.3
    { 705, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7b388c} }, // Kingston/Plymouth Line OSM: 1353691 WD: Q7083739 41.98, -71.06 x 42.35, -70.69
    { 728, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7b388c} }, // Needham Line OSM: 1353692 WD: Q6986548 42.27, -71.24 x 42.35, -71.06
    { 741, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7b388c} }, // Fairmount Line OSM: 1353693 WD: Q5430648 42.24, -71.13 x 42.35, -71.05
    { 756, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7b388c} }, // Greenbush Line OSM: 1353695 WD: Q5603780 42.18, -71.06 x 42.35, -70.74
    { 771, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7b388c} }, // Middleborough/Lakeville Line OSM: 1353697 WD: Q7083739 41.88, -71.06 x 42.35, -70.92
    { 389, NoLogo, 3795, LineMetaDataContent::Subway, Color{0x9b91b1} }, // L1 OSM: 1354082 WD: Q847767 39.94, 116.4 x 40.08, 116.6
    { 800, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7b388c} }, // Framingham/Worcester OSM: 1354954 WD: Q801994 42.23, -71.8 x 42.36, -71.06
    { 821, 4524, 4401, LineMetaDataContent::RapidTransit, Color{0xee7101} }, // H7 OSM: 1358702 WD: Q1031921 47.42, 19.07 x 47.48, 19.07
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 3 OSM: 1361661 56.48, 84.95 x 56.48, 85.02
    { 179, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 17 OSM: 1371410 55.82, 37.62 x 55.89, 37.67
    { 54, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 11 OSM: 1371613 55.78, 37.62 x 55.83, 37.82
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xcc9900} }, // 8 OSM: 1374424 WD: Q61887882 51.45, 11.95 x 51.52, 11.99
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x99cc00} }, // 12 OSM: 1375884 WD: Q61888162 51.48, 11.96 x 51.52, 11.99
    { 824, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfece08} }, // Main OSM: 1377995 WD: Q6736006 40.73, -74.17 x 41.11, -74.03
    { 829, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa1d4ae} }, // Gladstone OSM: 1377996 WD: Q5566325 40.67, -74.67 x 40.77, -73.99
    { 839, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xb9c9df} }, // Bergen County OSM: 1377997 WD: Q4891507 40.73, -74.15 x 41.11, -74.03
    { 853, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00a94e} }, // Morristown OSM: 1377998 WD: Q1948559 40.71, -74.83 x 40.91, -73.99
    { 864, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe76b5b} }, // Montclair-Boonton OSM: 1377999 WD: Q6904583 40.73, -74.83 x 40.93, -73.99
    { 309, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff8942} }, // FXC OSM: 1388637 WD: Q8565193 39.95, -75.18 x 40.08, -75.08
    { 882, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7c5e4a} }, // DOY OSM: 1388640 WD: Q6487336 39.95, -75.28 x 40.31, -75.13
    { 886, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffd457} }, // WAR OSM: 1390135 WD: Q7969637 39.95, -75.18 x 40.26, -74.82
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 2 OSM: 1390151 34.31, 132.3 x 34.4, 132.5
    { 890, NoLogo, 4539, LineMetaDataContent::RapidTransit, Color{0xfaa93f} }, // Camden OSM: 1403279 WD: Q5025789 38.9, -77.01 x 39.28, -76.62
    { 897, NoLogo, 4539, LineMetaDataContent::RapidTransit, Color{0xfbcab6} }, // Brunswick OSM: 1405417 WD: Q4979520 38.9, -77.96 x 39.46, -76.99
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 2 OSM: 1405516 44.8, 20.45 x 44.83, 20.48
    { 907, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff7f00} }, // 12E OSM: 1411178 WD: Q1487139 38.71, -9.138 x 38.72, -9.13
    { 911, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff00ff} }, // 15E OSM: 1411205 WD: Q63229924 38.69, -9.233 x 38.71, -9.135
    { 238, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x97bf0d} }, // F OSM: 1416967 WD: Q2724954 48.58, 7.716 x 48.59, 7.778
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfdc434} }, // 4 OSM: 1443866 46.24, 20.12 x 46.28, 20.16
    { 6, 4554, 4578, LineMetaDataContent::Subway, Color{0x802f08} }, // 5 OSM: 1462012 WD: Q831673 55.73, 37.57 x 55.78, 37.66
    { 9, 4683, 4578, LineMetaDataContent::Subway, Color{0x33ccff} }, // 4 OSM: 1463287 WD: Q834540 55.73, 37.44 x 55.75, 37.61
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe5005a} }, // 3 OSM: 1469415 51.02, 13.7 x 51.1, 13.75
    { 59, 4707, 4578, LineMetaDataContent::Subway, Color{0x0000ff} }, // 3 OSM: 1472548 WD: Q626941 55.73, 37.35 x 55.86, 37.8
    { 915, 4731, NoLogo, LineMetaDataContent::LocalTrain, Color{0xfbba00} }, // RB 13 OSM: 1472736 WD: Q113237031 48.35, 10.88 x 48.75, 11.45
    { 55, 4748, 4578, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 1475758 WD: Q729631 55.56, 37.4 x 55.82, 37.75
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffa500} }, // 4 OSM: 1476874 56.45, 84.98 x 56.48, 85.02
    { 477, 4772, 226, LineMetaDataContent::RapidTransit, Color{0x73c82c} }, // S9 OSM: 1483885 WD: Q115215302 48.99, 8.399 x 49.71, 8.58
    { 924, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0896dd} }, // 98 OSM: 1490387 52.36, 13.03 x 52.4, 13.1
    { 927, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 91 OSM: 1492311 52.36, 13.01 x 52.4, 13.1
    { 524, 4791, 4830, LineMetaDataContent::Subway, Color{0x0000ff} }, // A OSM: 1502599 WD: Q17621067 6.152, -75.63 x 6.339, -75.54
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // 1 OSM: 1503481 56.47, 84.95 x 56.53, 85.02
    { 931, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x897cb9} }, // 78 OSM: 1504645 WD: Q6811971 -37.87, 145 x -37.81, 145
    { 936, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x19488e} }, // 92 OSM: 1505928 52.36, 13.03 x 52.42, 13.14
    { 939, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfe9800} }, // 93 OSM: 1509473 52.36, 13.06 x 52.41, 13.1
    { 942, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x838a8f} }, // 94 OSM: 1512265 52.37, 13.01 x 52.4, 13.11
    { 945, 4858, 226, LineMetaDataContent::RapidTransit, Color{0x803c9f} }, // S33 OSM: 1513484 WD: Q115206384 49.12, 8.364 x 49.24, 8.594
    { 27, 4878, 4578, LineMetaDataContent::Subway, Color{0xffa500} }, // 6 OSM: 1514439 WD: Q175271 55.6, 37.51 x 55.89, 37.67
    { 42, 4902, 4578, LineMetaDataContent::Subway, Color{0xff00ff} }, // 7 OSM: 1516383 WD: Q924028 55.67, 37.43 x 55.86, 37.86
    { 19, 4926, 4578, LineMetaDataContent::Subway, Color{0xffff00} }, // 8 OSM: 1526351 WD: Q585986 55.74, 37.63 x 55.76, 37.87
    { 65, 4950, 4578, LineMetaDataContent::Subway, Color{0xb4d445} }, // 10 OSM: 1532877 WD: Q582194 55.61, 37.55 x 55.87, 37.76
    { 949, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xdc281e} }, // N19 OSM: 1536166 48.12, 11.46 x 48.15, 11.64
    { 953, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf6c046} }, // Zoo Tram OSM: 1536345 35.15, -90 x 35.15, -89.99
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 12 OSM: 1538177 55.71, 37.66 x 55.79, 37.82
    { 183, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 50 OSM: 1538180 55.75, 37.6 x 55.79, 37.72
    { 241, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 46 OSM: 1538181 55.75, 37.7 x 55.83, 37.78
    { 100, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 37 OSM: 1538182 55.75, 37.65 x 55.78, 37.82
    { 963, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 32 OSM: 1538183 55.75, 37.66 x 55.79, 37.75
    { 166, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x0097d8} }, // S3 OSM: 1549250 WD: Q7388286 47.32, 8.501 x 47.53, 8.806
    { 498, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xed1c24} }, // 35 OSM: 1555118 44.42, 25.98 x 44.45, 26.07
    { 196, 4975, 5002, LineMetaDataContent::Subway, Color{0xffd900} }, // B OSM: 1557177 WD: Q3239063 43.56, 1.43 x 43.64, 1.478
    { 211, 5026, 5054, LineMetaDataContent::Tramway, Color{0x004687} }, // T1 OSM: 1557178 WD: Q3239230 43.59, 1.36 x 43.67, 1.444
    { 524, 5078, 5002, LineMetaDataContent::Subway, Color{0xdb001b} }, // A OSM: 1557179 WD: Q3239050 43.57, 1.392 x 43.63, 1.483
    { 966, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf6c454} }, // S10 OSM: 1561016 WD: Q687279 47.35, 8.465 x 47.38, 8.54
    { 218, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe67d63} }, // S4 OSM: 1567629 WD: Q685807 47.27, 8.517 x 47.38, 8.558
    { 132, 5105, 4578, LineMetaDataContent::Subway, Color{0xa0a2a3} }, // 9 OSM: 1570146 WD: Q739170 55.57, 37.57 x 55.9, 37.63
    { 16, 5129, 4578, LineMetaDataContent::Subway, Color{0x006400} }, // 2 OSM: 1572626 WD: Q834482 55.61, 37.47 x 55.88, 37.77
    { 190, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x946644} }, // S24 OSM: 1574036 WD: Q7388228 47.17, 8.516 x 47.75, 9.106
    { 15, 5153, 4578, LineMetaDataContent::Subway, Color{0xacbfe3} }, // 12 OSM: 1580617 WD: Q678759 55.54, 37.52 x 55.6, 37.59
    { 334, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00a995} }, // 96 OSM: 1585204 52.36, 13.05 x 52.43, 13.14
    { 971, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x59c133} }, // 99 OSM: 1585259 52.37, 13.06 x 52.4, 13.11
    { 53, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0xccaaff} }, // S11 OSM: 1588232 WD: Q56435440 47.37, 8.048 x 47.54, 8.771
    { 974, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0066cc} }, // TMR OSM: 1603490 -27.46, -59.05 x -27.42, -58.98
    { 978, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x00c0f3} }, // S29 OSM: 1609488 WD: Q115646661 47.17, 7.903 x 47.49, 8.257
    { 61, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x00ab4e} }, // S1 OSM: 1609559 WD: Q115646641 47.04, 8.098 x 47.2, 8.524
    { 204, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x7751a1} }, // S6 OSM: 1609735 WD: Q7388350 47.26, 8.305 x 47.48, 8.683
    { 982, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0xd8242b} }, // S12 OSM: 1614502 WD: Q7388182 47.37, 8.208 x 47.7, 9.042
    { 25, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x64b97a} }, // S16 OSM: 1618466 WD: Q7388193 47.28, 8.511 x 47.45, 8.621
    { 945, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x2da7df} }, // S33 OSM: 1619213 WD: Q7388269 47.5, 8.611 x 47.7, 8.726
    { 477, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x00a34f} }, // S9 OSM: 1620987 WD: Q7388394 47.35, 8.501 x 47.7, 8.721
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc32b3c} }, // 2 OSM: 1624727 WD: Q60282113 51.75, 14.31 x 51.76, 14.35
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x239537} }, // 4 OSM: 1628047 WD: Q60328960 51.72, 14.32 x 51.79, 14.35
    { 537, 5178, 5211, LineMetaDataContent::Tramway, Color{0xbb4a9b} }, // T2 OSM: 1635139 WD: Q1771110 48.82, 2.217 x 48.92, 2.288
    { 486, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // C-1 OSM: 1636998 WD: Q59928410 41.63, -1.023 x 41.72, -0.8658
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xece116} }, // 1 OSM: 1637446 WD: Q60213236 51.75, 14.33 x 51.78, 14.34
    { 524, 5242, 2617, LineMetaDataContent::Subway, Color{0x1ca4cb} }, // A OSM: 1637478 WD: Q1209679 -34.63, -58.47 x -34.61, -58.37
    { 22, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x54ad4b} }, // 18 OSM: 1646141 50.73, 6.893 x 50.98, 7.096
    { 986, 5270, 4401, LineMetaDataContent::RapidTransit, Color{0xed6e86} }, // H9 OSM: 1647378 WD: Q947539 47.5, 19.14 x 47.55, 19.27
    { 989, 5270, 4401, LineMetaDataContent::RapidTransit, Color{0xed6e86} }, // H8 OSM: 1647379 WD: Q947539 47.5, 19.14 x 47.6, 19.36
    { 992, 5285, 4401, LineMetaDataContent::RapidTransit, Color{0x7b4400} }, // H6 OSM: 1647380 WD: Q1031918 47.18, 18.94 x 47.47, 19.12
    { 61, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffa500} }, // S1 OSM: 1647847 WD: Q2316170 41.39, 2.007 x 41.58, 2.169
    { 55, 5300, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 1 OSM: 1658046 WD: Q651686 47.46, 19.02 x 47.55, 19.11
    { 191, 5323, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 24 OSM: 1658053 WD: Q1489900 47.44, 19.07 x 47.5, 19.12
    { 183, 5347, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 50 OSM: 1658057 WD: Q643837 47.43, 19.13 x 47.47, 19.22
    { 95, 5371, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 62 OSM: 1658060 WD: Q1491622 47.48, 19.07 x 47.54, 19.14
    { 996, 5395, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 42 OSM: 1658062 WD: Q1490864 47.45, 19.13 x 47.47, 19.15
    { 59, 5419, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 3 OSM: 1658063 WD: Q1490196 47.44, 19.09 x 47.52, 19.14
    { 139, 5442, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 14 OSM: 1658066 WD: Q1485881 47.52, 19.06 x 47.59, 19.12
    { 999, 5466, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 69 OSM: 1658067 WD: Q1491929 47.52, 19.09 x 47.55, 19.15
    { 1003, 5490, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 52 OSM: 1658071 WD: Q1491293 47.42, 19.1 x 47.47, 19.13
    { 1006, 5514, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 62A OSM: 1658072 WD: Q743389 47.48, 19.1 x 47.54, 19.14
    { 100, 5539, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 37 OSM: 1658073 WD: Q1490525 47.47, 19.07 x 47.5, 19.18
    { 1010, 5563, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 51A OSM: 1658076 WD: Q16516127 47.47, 19.07 x 47.48, 19.08
    { 261, 5588, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 51 OSM: 1658077 WD: Q1491245 47.44, 19.07 x 47.48, 19.12
    { 1014, 5612, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 28A OSM: 1658080 WD: Q12813290 47.47, 19.07 x 47.5, 19.18
    { 1019, 5634, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 28 OSM: 1658081 WD: Q1490084 47.47, 19.07 x 47.5, 19.18
    { 1022, 5658, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 37A OSM: 1658082 WD: Q287376 47.49, 19.07 x 47.5, 19.14
    { 61, 5683, 226, LineMetaDataContent::RapidTransit, Color{0x33b540} }, // S1 OSM: 1660624 WD: Q19377130 53.55, 9.705 x 53.65, 10.09
    { 1028, 5698, 2529, LineMetaDataContent::RapidTransit, Color{0x5e9620} }, // D OSM: 1673421 WD: Q1425351 48.29, 2.344 x 49.27, 2.657
    { 110, 5730, 1095, LineMetaDataContent::Subway, Color{0xff0000} }, // U2 OSM: 1676043 WD: Q3433227 49.42, 11.03 x 49.49, 11.11
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xdc008f} }, // 1 OSM: 1679960 50.09, 14.34 x 50.13, 14.48
    { 110, 5747, 1095, LineMetaDataContent::Subway, Color{0xee1d23} }, // U2 OSM: 1686090 WD: Q275451 53.53, 9.943 x 53.64, 10.15
    { 107, 5762, 1095, LineMetaDataContent::Subway, Color{0x0066b3} }, // U1 OSM: 1687370 WD: Q248623 53.55, 9.985 x 53.71, 10.29
    { 1031, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 26 OSM: 1689065 55.68, 37.54 x 55.73, 37.62
    { 1035, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 39 OSM: 1689391 55.68, 37.54 x 55.76, 37.65
    { 1039, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // А OSM: 1689398 WD: Q4461919 55.73, 37.63 x 55.76, 37.7
    { 547, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 47 OSM: 1689752 55.68, 37.61 x 55.73, 37.69
    { 1042, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 38 OSM: 1690017 55.68, 37.59 x 55.73, 37.66
    { 1045, 5777, 226, LineMetaDataContent::RapidTransit, Color{0x5d1d81} }, // S31 OSM: 1727359 WD: Q19368873 53.46, 9.851 x 53.56, 10.03
    { 237, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfdc434} }, // 3F OSM: 1733222 46.25, 20.11 x 46.28, 20.16
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfdc434} }, // 3 OSM: 1733225 46.25, 20.12 x 46.28, 20.16
    { 1049, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // СТ OSM: 1759150 WD: Q107191041 48.7, 44.5 x 48.8, 44.6
    { 1054, 5793, 5815, LineMetaDataContent::Subway, Color{0x0000ff} }, // 2 Салтівська OSM: 1766294 WD: Q2332390 49.99, 36.23 x 50.03, 36.34
    { 1077, 5838, 5815, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 Холодногірсько-заводська OSM: 1766295 WD: Q2710248 49.95, 36.18 x 49.99, 36.4
    { 1127, 5860, 5815, LineMetaDataContent::Subway, Color{0x008000} }, // 3 Олексіївська OSM: 1766296 WD: Q2109890 49.98, 36.2 x 50.06, 36.27
    { 55, 5882, NoLogo, LineMetaDataContent::Tramway, Color{0x78ccc9} }, // 1 OSM: 1767386 WD: Q63890946 50.41, 30.38 x 50.45, 30.49
    { 139, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7a7dbc} }, // 14 OSM: 1770128 WD: Q3743657 40.63, 14.27 x 40.85, 14.49
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x78ccc9} }, // 2 OSM: 1773735 50.41, 30.37 x 50.43, 30.41
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff6600} }, // 1 OSM: 1783293 WD: Q25522217 59.44, 24.67 x 59.46, 24.79
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff6600} }, // 2 OSM: 1783294 WD: Q18624670 59.43, 24.67 x 59.46, 24.81
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff6600} }, // 3 OSM: 1783295 WD: Q25522221 59.41, 24.73 x 59.44, 24.79
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff6600} }, // 4 OSM: 1783296 WD: Q16409268 59.41, 24.73 x 59.44, 24.8
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // 2 OSM: 1788097 55.67, 52.28 x 55.73, 52.47
    { 1154, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x1b522b} }, // 12а OSM: 1789317 55.67, 52.28 x 55.75, 52.47
    { 1159, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa82618} }, // SSL OSM: 1811654 41.59, -87.62 x 41.88, -86.29
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 6 OSM: 1821113 59.93, 30.23 x 59.97, 30.36
    { 1166, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 40 OSM: 1821265 59.93, 30.23 x 60.01, 30.37
    { 537, 5898, 5928, LineMetaDataContent::Tramway, Color{0x96bf0d} }, // T2 OSM: 1824544 WD: Q106915028 47.29, 5.006 x 47.37, 5.059
    { 211, 5951, 5928, LineMetaDataContent::Tramway, Color{0xcc0088} }, // T1 OSM: 1824550 WD: Q106915007 47.31, 5.028 x 47.33, 5.112
    { 297, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x4f4a9f} }, // 30 OSM: 1830395 WD: Q6811953 -37.81, 144.9 x -37.81, 145
    { 26, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 16 OSM: 1831075 59.9, 30.27 x 59.93, 30.37
    { 439, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 41 OSM: 1831189 59.88, 30.24 x 59.92, 30.29
    { 1169, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xc60c30} }, // Port Washington OSM: 1834644 WD: Q7231025 40.74, -73.99 x 40.83, -73.69
    { 1163, 5981, NoLogo, LineMetaDataContent::LocalTrain, Color{} }, // RB 40 OSM: 1845480 WD: Q113237935 48.12, 11.53 x 48.28, 12.52
    { 1185, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008be0} }, // TER 22 OSM: 1849404 45.76, 4.601 x 45.85, 4.827
    { 113, 5998, 1095, LineMetaDataContent::Subway, Color{0x00868b} }, // U3 OSM: 1857497 WD: Q3433219 49.44, 11.02 x 49.47, 11.09
    { 107, 6015, 1095, LineMetaDataContent::Subway, Color{0x000066} }, // U1 OSM: 1857639 WD: Q3433210 49.4, 10.96 x 49.48, 11.14
    { 72, 6032, NoLogo, LineMetaDataContent::Tramway, Color{0xf89c0e} }, // 21 OSM: 1871117 WD: Q85093119 50.07, 8.567 x 50.11, 8.67
    { 1193, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 36 OSM: 1871436 59.85, 30.06 x 59.89, 30.28
    { 524, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe30613} }, // A OSM: 1874970 WD: Q2066292 339.5, 249.5 x 339.5, 249.5
    { 196, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009fe3} }, // B OSM: 1874971 WD: Q2085986 339.5, 249.5 x 339.5, 249.5
    { 54, 6062, NoLogo, LineMetaDataContent::Tramway, Color{0xfbbc09} }, // 11 OSM: 1875166 WD: Q85088920 50.1, 8.552 x 50.13, 8.774
    { 15, 6092, NoLogo, LineMetaDataContent::Tramway, Color{0xc73a17} }, // 12 OSM: 1875167 WD: Q85090131 50.08, 8.581 x 50.13, 8.756
    { 139, 6122, NoLogo, LineMetaDataContent::Tramway, Color{0xf1471d} }, // 14 OSM: 1875169 WD: Q85112445 50.1, 8.618 x 50.13, 8.716
    { 143, 6152, NoLogo, LineMetaDataContent::Tramway, Color{0xfbbc09} }, // 15 OSM: 1875170 WD: Q85112688 50.09, 8.636 x 50.1, 8.745
    { 179, 6182, NoLogo, LineMetaDataContent::Tramway, Color{0xf1471d} }, // 17 OSM: 1875171 WD: Q107028657 50.06, 8.619 x 50.12, 8.695
    { 204, 6212, 226, LineMetaDataContent::RapidTransit, Color{0xf57921} }, // S6 OSM: 1880910 WD: Q3238987 50.1, 8.633 x 50.34, 8.789
    { 179, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8d1d2c} }, // 17 OSM: 1903836 WD: Q96578284 47.35, 8.482 x 47.4, 8.542
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x9bd6f9} }, // 4 OSM: 1904829 50.03, 14.37 x 50.08, 14.48
    { 65, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 10 OSM: 1905347 44.76, 20.45 x 44.83, 20.48
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 12 OSM: 1905348 44.77, 20.41 x 44.81, 20.49
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 5 OSM: 1905349 44.78, 20.45 x 44.83, 20.52
    { 245, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 45 OSM: 1926572 59.83, 30.32 x 59.88, 30.41
    { 979, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 29 OSM: 1926573 59.83, 30.32 x 59.9, 30.35
    { 434, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 43 OSM: 1927169 59.83, 30.32 x 59.89, 30.4
    { 231, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 25 OSM: 1933012 59.83, 30.35 x 59.93, 30.4
    { 342, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 49 OSM: 1933013 59.83, 30.35 x 59.93, 30.42
    { 72, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 21 OSM: 1938644 59.98, 30.24 x 60.06, 30.38
    { 430, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 48 OSM: 1938658 59.98, 30.19 x 59.99, 30.35
    { 249, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 20 OSM: 1938751 59.96, 30.32 x 60.05, 30.38
    { 201, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 58 OSM: 1939721 60.04, 30.3 x 60.07, 30.38
    { 524, 6229, NoLogo, LineMetaDataContent::Tramway, Color{0xa83939} }, // A OSM: 1940504 WD: Q10883225 35, 135.7 x 35.02, 135.7
    { 504, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 55 OSM: 1942053 59.99, 30.23 x 60.06, 30.37
    { 27, 6274, 1624, LineMetaDataContent::Tramway, Color{} }, // 6 OSM: 1942851 WD: Q104867938 49.43, 11.05 x 49.46, 11.12
    { 311, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x913108} }, // C OSM: 1958845 37.79, -122.4 x 37.79, -122.4
    { 132, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 9 OSM: 1959399 59.98, 30.32 x 60.04, 30.44
    { 65, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 10 OSM: 1965337 59.91, 30.41 x 59.95, 30.5
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 8 OSM: 1965401 59.93, 30.44 x 59.95, 30.49
    { 368, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 59 OSM: 1965402 59.93, 30.44 x 59.97, 30.49
    { 582, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 64 OSM: 1965403 59.93, 30.44 x 59.98, 30.51
    { 139, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 14 OSM: 1968651 44.76, 20.47 x 44.81, 20.52
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 6 OSM: 1968652 44.78, 20.47 x 44.81, 20.52
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x003828} }, // 2 OSM: 1984325 52.9, -1.207 x 52.99, -1.145
    { 1196, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x82bf40} }, // SFM3 OSM: 1988841 WD: Q3832756 45.04, 6.71 x 45.14, 7.678
    { 512, 6291, NoLogo, LineMetaDataContent::Tramway, Color{0xfcc70d} }, // SG OSM: 1994315 WD: Q339069 35.64, 139.6 x 35.67, 139.7
    { 450, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x004ea2} }, // SL OSM: 1994316 WD: Q6360898 35.33, 139.6 x 35.39, 139.7
    { 346, 6316, 19, LineMetaDataContent::Tramway, Color{0x33ff33} }, // M2 OSM: 2001598 WD: Q62512253 52.52, 13.41 x 52.57, 13.44
    { 1201, 599, NoLogo, LineMetaDataContent::Subway, Color{0x008fc2} }, // U75 OSM: 2003447 WD: Q661002 51.2, 6.684 x 51.23, 6.847
    { 930, NoLogo, 599, LineMetaDataContent::Subway, Color{0x009adf} }, // U78 OSM: 2003448 WD: Q107015816 51.22, 6.733 x 51.27, 6.795
    { 58, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x967b68} }, // 13 OSM: 2003476 50.91, 6.908 x 50.97, 7.038
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x948fb8} }, // 5 OSM: 2003477 50.93, 6.888 x 50.98, 6.96
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfff500} }, // 5 OSM: 2024979 50.03, 14.36 x 50.09, 14.48
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe693b5} }, // 3 OSM: 2026288 50.93, 6.87 x 50.98, 7.086
    { 84, NoLogo, 599, LineMetaDataContent::Tramway, Color{0x98c000} }, // 61 OSM: 2026289 WD: Q20035840 50.7, 7.071 x 50.76, 7.112
    { 95, NoLogo, 599, LineMetaDataContent::Tramway, Color{0x61af20} }, // 62 OSM: 2026290 WD: Q20035841 50.7, 7.095 x 50.74, 7.176
    { 80, NoLogo, 599, LineMetaDataContent::Tramway, Color{0x60d6f7} }, // 63 OSM: 2026291 WD: Q20035835 50.68, 7.047 x 50.75, 7.159
    { 1208, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe5007d} }, // 66 OSM: 2026292 50.64, 7.092 x 50.79, 7.217
    { 171, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xee99bf} }, // 67 OSM: 2026293 50.68, 7.092 x 50.79, 7.203
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf7d09b} }, // 6 OSM: 2032473 50.07, 14.42 x 50.11, 14.48
    { 42, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00ffff} }, // 7 OSM: 2061854 50.06, 14.39 x 50.08, 14.52
    { 55, 6335, NoLogo, LineMetaDataContent::Tramway, Color{0x009cdd} }, // 1 OSM: 2067963 WD: Q12804359 53.41, 14.49 x 53.46, 14.56
    { 15, 6355, NoLogo, LineMetaDataContent::Tramway, Color{0x009cdd} }, // 12 OSM: 2074000 WD: Q28792440 53.4, 14.53 x 53.43, 14.56
    { 211, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe3002b} }, // T1 OSM: 2074460 48.65, 6.145 x 48.7, 6.225
    { 6, 6376, NoLogo, LineMetaDataContent::Tramway, Color{0x009cdd} }, // 5 OSM: 2077222 WD: Q25501513 53.43, 14.49 x 53.45, 14.58
    { 54, 6396, NoLogo, LineMetaDataContent::Tramway, Color{0x009cdd} }, // 11 OSM: 2077355 WD: Q32946105 53.4, 14.53 x 53.45, 14.58
    { 27, 6417, NoLogo, LineMetaDataContent::Tramway, Color{0x009cdd} }, // 6 OSM: 2077516 WD: Q26003028 53.42, 14.55 x 53.48, 14.61
    { 19, 6437, NoLogo, LineMetaDataContent::Tramway, Color{0x009cdd} }, // 8 OSM: 2080359 WD: Q26160394 53.38, 14.49 x 53.43, 14.64
    { 42, 6457, NoLogo, LineMetaDataContent::Tramway, Color{0x009cdd} }, // 7 OSM: 2080360 WD: Q26111009 53.38, 14.49 x 53.45, 14.64
    { 59, 6477, NoLogo, LineMetaDataContent::Tramway, Color{0xef7c00} }, // 3 OSM: 2083643 WD: Q99229508 48.27, 10.88 x 48.37, 10.9
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x94c11c} }, // 6 OSM: 2083654 48.35, 10.84 x 48.37, 10.96
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xb5c426} }, // 1 OSM: 2100315 WD: Q6811945 -37.85, 144.9 x -37.74, 145
    { 248, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00aadc} }, // N20 OSM: 2101204 48.14, 11.51 x 48.18, 11.56
    { 55, 6497, 599, LineMetaDataContent::Tramway, Color{0x0000ff} }, // 1 OSM: 2102327 WD: Q117468577 51.98, 8.502 x 52.06, 8.546
    { 59, 6517, 599, LineMetaDataContent::Tramway, Color{0xffff00} }, // 3 OSM: 2102329 WD: Q117468931 52.02, 8.518 x 52.06, 8.543
    { 16, 6537, 599, LineMetaDataContent::Tramway, Color{0x008000} }, // 2 OSM: 2102391 WD: Q117468882 52, 8.532 x 52.06, 8.628
    { 9, 6557, 599, LineMetaDataContent::Tramway, Color{0xff0000} }, // 4 OSM: 2102392 WD: Q117468952 52, 8.485 x 52.05, 8.589
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffeedd} }, // 1 OSM: 2104341 54.14, 19.39 x 54.19, 19.44
    { 1211, 6577, 226, LineMetaDataContent::RapidTransit, Color{0xe7526b} }, // S20 OSM: 2113865 WD: Q7388223 48.04, 11.04 x 48.18, 11.54
    { 41, 6594, 226, LineMetaDataContent::RapidTransit, Color{0x983224} }, // S7 OSM: 2113867 WD: Q7388364 47.91, 11.42 x 48.14, 11.78
    { 55, NoLogo, 6610, LineMetaDataContent::Tramway, Color{0x00a651} }, // 1 OSM: 2116454 WD: Q3238670 47.2, -1.639 x 47.26, -1.515
    { 1215, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x4dbe63} }, // Тр3 OSM: 2161840 49.81, 24 x 49.84, 24.04
    { 16, NoLogo, 6610, LineMetaDataContent::Tramway, Color{0xee1c25} }, // 2 OSM: 2166523 WD: Q3238813 47.19, -1.593 x 47.26, -1.542
    { 59, NoLogo, 6610, LineMetaDataContent::Tramway, Color{0x006db1} }, // 3 OSM: 2166524 WD: Q3238913 47.18, -1.617 x 47.25, -1.542
    { 15, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf499b6} }, // 12 OSM: 2168260 WD: Q3743529 40.75, 14.27 x 40.85, 14.54
    { 132, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x771e1b} }, // 9 OSM: 2168283 WD: Q3743526 40.85, 14.27 x 40.97, 14.62
    { 58, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x6f195c} }, // 13 OSM: 2168298 WD: Q3743527 40.8, 14.27 x 40.88, 14.62
    { 1221, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8e4b34} }, // Тр2 OSM: 2169223 49.82, 23.99 x 49.84, 24.07
    { 1227, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x35ccf5} }, // Тр4 OSM: 2171616 49.78, 23.99 x 49.84, 24.06
    { 19, 6640, NoLogo, LineMetaDataContent::RapidTransit, Color{0x808080} }, // 8 OSM: 2174536 WD: Q3296720 -23.55, -46.98 x -23.51, -46.64
    { 132, 6651, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00a88e} }, // 9 OSM: 2183695 WD: Q5245848 -23.76, -46.78 x -23.53, -46.69
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x666666} }, // 2 OSM: 2189262 45.55, 18.68 x 45.56, 18.73
    { 218, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x000080} }, // S4 OSM: 2199152 WD: Q7388307 49.25, 10.3 x 49.44, 11.08
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0071bc} }, // 2 OSM: 2203208 48.98, 8.345 x 49.04, 8.479
    { 54, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xed1c24} }, // 11 OSM: 2205114 WD: Q85980501 44.39, 26.02 x 44.47, 26.09
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x1c63b7} }, // 2 OSM: 2206997 WD: Q104521890 41.91, 12.46 x 41.93, 12.48
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xed1c24} }, // 5 OSM: 2206998 WD: Q104537333 41.88, 12.5 x 41.9, 12.57
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xbfdf14} }, // 8 OSM: 2206999 WD: Q104537360 41.87, 12.44 x 41.9, 12.52
    { 524, 6662, 6703, LineMetaDataContent::Subway, Color{0xf68b1f} }, // A OSM: 2207255 WD: Q572544 41.84, 12.42 x 41.91, 12.59
    { 196, 6733, 6703, LineMetaDataContent::Subway, Color{0x3783c6} }, // B OSM: 2208346 WD: Q2666571 41.83, 12.46 x 41.95, 12.57
    { 1233, 6774, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfbbc09} }, // FC1 OSM: 2208347 WD: Q3743595 41.87, 12.51 x 41.9, 12.56
    { 139, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00adef} }, // 14 OSM: 2208350 WD: Q415821 41.89, 12.5 x 41.9, 12.57
    { 147, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf89c0e} }, // 19 OSM: 2208351 WD: Q104537271 41.88, 12.46 x 41.92, 12.57
    { 388, 6804, NoLogo, LineMetaDataContent::LocalTrain, Color{0x007663} }, // FL1 OSM: 2208499 WD: Q3737286 41.79, 12.25 x 42.44, 12.65
    { 392, 6839, NoLogo, LineMetaDataContent::RapidTransit, Color{0x004174} }, // FL2 OSM: 2208500 WD: Q3737287 41.9, 12.53 x 42.1, 13.43
    { 396, 6874, NoLogo, LineMetaDataContent::LocalTrain, Color{0x88aca0} }, // FL3 OSM: 2208501 WD: Q3737289 41.87, 12.08 x 42.43, 12.53
    { 384, 6909, NoLogo, LineMetaDataContent::RapidTransit, Color{0x965b0e} }, // FL4 OSM: 2208502 WD: Q25064 41.67, 12.5 x 41.9, 12.78
    { 1237, 6944, NoLogo, LineMetaDataContent::RapidTransit, Color{0xdccc00} }, // FL5 OSM: 2208503 WD: Q3737292 41.86, 11.8 x 42.09, 12.53
    { 1241, 6979, NoLogo, LineMetaDataContent::RapidTransit, Color{0xd880b4} }, // FL6 OSM: 2208504 WD: Q3737295 41.48, 12.5 x 41.9, 13.83
    { 1245, 7014, NoLogo, LineMetaDataContent::RapidTransit, Color{0x9acc66} }, // FL7 OSM: 2208505 WD: Q661786 41.25, 12.5 x 41.9, 13.72
    { 1249, 7049, NoLogo, LineMetaDataContent::RapidTransit, Color{0x6cbf68} }, // FL8 OSM: 2208506 WD: Q3737301 41.45, 12.5 x 41.9, 12.66
    { 65, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xed1c24} }, // 10 OSM: 2212352 44.39, 26.05 x 44.45, 26.14
    { 19, 7084, 7105, LineMetaDataContent::Tramway, Color{0x169fdb} }, // 8 OSM: 2262665 WD: Q431783 50.8, 4.353 x 50.85, 4.44
    { 214, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00ff80} }, // 665 OSM: 2271832 32.72, -117.4 x 33.19, -117.2
    { 1253, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00ff80} }, // 635 OSM: 2271832 32.72, -117.4 x 33.19, -117.2
    { 1034, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00ff80} }, // 639 OSM: 2271832 32.72, -117.4 x 33.19, -117.2
    { 1257, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00ff80} }, // 655 OSM: 2271832 32.72, -117.4 x 33.19, -117.2
    { 1261, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00ff80} }, // 631 OSM: 2271832 32.72, -117.4 x 33.19, -117.2
    { 404, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00ff80} }, // 657 OSM: 2271832 32.72, -117.4 x 33.19, -117.2
    { 1265, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0092d8} }, // TER 01 OSM: 2272829 45.19, 4.823 x 45.76, 5.715
    { 91, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0092d8} }, // TER 62 OSM: 2272886 45.15, 5.417 x 45.57, 6.045
    { 1272, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0092d8} }, // TER 60 OSM: 2274103 45.15, 5.417 x 45.57, 6.045
    { 1282, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x669933} }, // 87 OSM: 2282096 WD: Q428288 52.44, 13.69 x 52.46, 13.76
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008f4d} }, // 1 OSM: 2309633 33.84, 132.8 x 33.85, 132.8
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf9a51b} }, // 2 OSM: 2309634 33.84, 132.8 x 33.85, 132.8
    { 524, 7131, 2529, LineMetaDataContent::RapidTransit, Color{0xe3051c} }, // A OSM: 2333448 WD: Q741818 48.75, 2.012 x 49.05, 2.782
    { 132, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x112233} }, // 9 OSM: 2336329 54.27, 48.29 x 54.34, 48.39
    { 55, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xe4002b} }, // 1 OSM: 2336458 WD: Q263572 29.53, 106.2 x 29.62, 106.6
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfbba00} }, // 2 OSM: 2344988 50.84, 12.05 x 50.85, 12.08
    { 1003, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 52 OSM: 2345812 59.83, 30.14 x 59.88, 30.26
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xd75128} }, // 4 OSM: 2368452 50.72, 12.43 x 50.75, 12.49
    { 65, 7163, NoLogo, LineMetaDataContent::Tramway, Color{0x009cdd} }, // 10 OSM: 2372195 WD: Q26298715 53.42, 14.49 x 53.43, 14.56
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfdc434} }, // 2 OSM: 2380276 46.24, 20.13 x 46.27, 20.15
    { 55, 7184, NoLogo, LineMetaDataContent::Subway, Color{0x10069f} }, // 1 OSM: 2381769 WD: Q6118988 30.39, 104.1 x 30.72, 104.1
    { 218, 7194, 226, LineMetaDataContent::RapidTransit, Color{0x9f184c} }, // S4 OSM: 2395148 WD: Q68930086 48.99, 8.349 x 49.48, 9.528
    { 47, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x04a5c8} }, // S8 OSM: 2396232 41.35, 1.919 x 41.48, 2.149
    { 260, 7213, 226, LineMetaDataContent::RapidTransit, Color{0xf8a20d} }, // S51 OSM: 2412316 WD: Q96388878 49.3, 8.674 x 49.42, 8.991
    { 65, 7233, NoLogo, LineMetaDataContent::Tramway, Color{0xb4e16e} }, // 10 OSM: 2413392 WD: Q106921203 57.68, 11.89 x 57.73, 11.98
    { 19, 7256, NoLogo, LineMetaDataContent::Tramway, Color{0x872387} }, // 8 OSM: 2413517 WD: Q10562727 57.65, 11.91 x 57.8, 12.05
    { 58, 7278, NoLogo, LineMetaDataContent::Tramway, Color{0xfee6c2} }, // 13 OSM: 2413518 WD: Q10562720 57.66, 11.85 x 57.72, 11.99
    { 16, 7301, NoLogo, LineMetaDataContent::Tramway, Color{0xfff014} }, // 2 OSM: 2413613 WD: Q106921120 57.65, 11.93 x 57.71, 12.02
    { 9, 7323, NoLogo, LineMetaDataContent::Tramway, Color{0x14823c} }, // 4 OSM: 2413615 WD: Q106921167 57.65, 11.97 x 57.8, 12.05
    { 546, 7345, 226, LineMetaDataContent::RapidTransit, Color{0xba8a4d} }, // S47 OSM: 2413847 WD: Q3742025 52.45, 13.43 x 52.47, 13.56
    { 59, 7376, NoLogo, LineMetaDataContent::Tramway, Color{0x004b85} }, // 3 OSM: 2418220 WD: Q106921163 57.67, 11.91 x 57.72, 12.03
    { 132, 7398, NoLogo, LineMetaDataContent::Tramway, Color{0x6ec8dc} }, // 9 OSM: 2418235 WD: Q106921200 57.68, 11.9 x 57.8, 12.05
    { 54, 7420, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 11 OSM: 2418236 WD: Q106921207 57.66, 11.85 x 57.76, 12.07
    { 1285, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // 901 OSM: 2440421 WD: Q1617191 44.85, -93.28 x 44.98, -93.2
    { 252, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x61af20} }, // RB23 OSM: 2441590 WD: Q1699351 50.56, 6.761 x 50.74, 7.098
    { 103, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf0e130} }, // 888 OSM: 2442946 44.98, -93.73 x 45.33, -93.25
    { 61, 7443, 226, LineMetaDataContent::RapidTransit, Color{0x0b9a33} }, // S1 OSM: 2444997 WD: Q7388210 51.16, 6.772 x 51.52, 7.46
    { 53, 7454, 226, LineMetaDataContent::RapidTransit, Color{0xef7c00} }, // S11 OSM: 2445000 WD: Q7388174 50.94, 6.674 x 51.28, 7.125
    { 982, 7466, 226, LineMetaDataContent::RapidTransit, Color{0x61af20} }, // S12 OSM: 2445001 WD: Q7388180 50.76, 6.713 x 50.95, 7.66
    { 1289, 7478, 226, LineMetaDataContent::RapidTransit, Color{0x00a6eb} }, // S13 OSM: 2445007 WD: Q7388184 50.81, 6.482 x 50.95, 7.151
    { 50, 7490, 226, LineMetaDataContent::RapidTransit, Color{0x006db6} }, // S2 OSM: 2445008 WD: Q7388251 51.45, 7.015 x 51.62, 7.46
    { 1018, 7501, 226, LineMetaDataContent::RapidTransit, Color{0x717676} }, // S28 OSM: 2445009 WD: Q7388234 51.2, 6.594 x 51.25, 7.153
    { 166, 7513, 226, LineMetaDataContent::RapidTransit, Color{0x999999} }, // S3 OSM: 2445010 WD: Q7388285 51.4, 6.835 x 51.48, 7.181
    { 218, 7524, 226, LineMetaDataContent::RapidTransit, Color{0xef7c00} }, // S4 OSM: 2445011 WD: Q7388319 51.5, 7.334 x 51.55, 7.692
    { 44, 7535, 226, LineMetaDataContent::RapidTransit, Color{0x98c60f} }, // S5 OSM: 2445012 WD: Q7388333 51.36, 7.325 x 51.52, 7.46
    { 204, 7546, 226, LineMetaDataContent::RapidTransit, Color{0xdc052d} }, // S6 OSM: 2445013 WD: Q7388349 50.94, 6.79 x 51.45, 7.023
    { 87, 7557, 226, LineMetaDataContent::RapidTransit, Color{0x14bae6} }, // S68 OSM: 2445014 WD: Q7388346 51.1, 6.79 x 51.23, 7.074
    { 47, 7569, 226, LineMetaDataContent::RapidTransit, Color{0xb03303} }, // S8 OSM: 2445015 WD: Q7388383 51.19, 6.445 x 51.36, 7.46
    { 477, 7580, 226, LineMetaDataContent::RapidTransit, Color{0xc7007f} }, // S9 OSM: 2445016 WD: Q7388395 51.23, 6.921 x 51.74, 7.46
    { 61, 7591, 226, LineMetaDataContent::RapidTransit, Color{0xec192e} }, // S1 OSM: 2445551 WD: Q67858837 49.33, 7.334 x 49.48, 9.424
    { 50, 7610, 226, LineMetaDataContent::RapidTransit, Color{0x2960b5} }, // S2 OSM: 2445552 WD: Q64667644 49.34, 7.768 x 49.48, 9.144
    { 166, 7629, 226, LineMetaDataContent::RapidTransit, Color{0x00a896} }, // S3 OSM: 2445553 WD: Q2781002 49.87, 8.504 x 50.16, 8.699
    { 166, 7646, 226, LineMetaDataContent::RapidTransit, Color{0xfcd804} }, // S3 OSM: 2445554 WD: Q68929824 48.99, 8.349 x 49.48, 8.685
    { 55, 7665, 7685, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 2446076 WD: Q519861 59.84, 30.25 x 60.05, 30.44
    { 16, 7704, 7685, LineMetaDataContent::Subway, Color{0x0000ff} }, // 2 OSM: 2446077 WD: Q1459627 59.83, 30.3 x 60.07, 30.38
    { 59, 7724, 7685, LineMetaDataContent::Subway, Color{0x008000} }, // 3 OSM: 2446078 WD: Q1509576 59.83, 30.2 x 59.99, 30.5
    { 9, 7744, 7685, LineMetaDataContent::Subway, Color{0xffa500} }, // 4 OSM: 2446079 WD: Q1784097 59.91, 30.32 x 59.93, 30.48
    { 6, 7764, 7685, LineMetaDataContent::Subway, Color{0x800080} }, // 5 OSM: 2446080 WD: Q1579583 59.82, 30.25 x 60.01, 30.43
    { 537, 7784, 7806, LineMetaDataContent::Tramway, Color{0xf5e615} }, // T2 OSM: 2449769 WD: Q3238811 43.3, 5.367 x 43.32, 5.406
    { 211, 7827, 7806, LineMetaDataContent::Tramway, Color{0xf18e00} }, // T1 OSM: 2452278 WD: Q3238668 43.29, 5.381 x 43.3, 5.444
    { 1293, 7849, 7873, LineMetaDataContent::Subway, Color{0x10069f} }, // Μ3 OSM: 2473158 WD: Q6553119 37.91, 23.64 x 38.02, 23.95
    { 166, 7927, 226, LineMetaDataContent::RapidTransit, Color{0xdb6eab} }, // S3 OSM: 2474189 WD: Q63433452 52.16, 9.739 x 52.38, 10.02
    { 44, 7943, 226, LineMetaDataContent::RapidTransit, Color{0xf78a18} }, // S5 OSM: 2474199 WD: Q63433456 51.71, 8.737 x 52.46, 9.773
    { 16, 7959, 7985, LineMetaDataContent::Subway, Color{0x0000ff} }, // 2 OSM: 2507796 WD: Q2001449 41.29, 69.2 x 41.35, 69.32
    { 59, 8004, 7985, LineMetaDataContent::Subway, Color{0x008000} }, // 3 OSM: 2507797 WD: Q4534678 41.3, 69.27 x 41.38, 69.3
    { 55, 8030, 7985, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 2507927 WD: Q4515924 41.21, 69.19 x 41.33, 69.33
    { 44, 8056, 226, LineMetaDataContent::RapidTransit, Color{0xa52a2a} }, // S5 OSM: 2515355 WD: Q2515085 50.1, 8.583 x 50.25, 8.699
    { 218, 8073, 226, LineMetaDataContent::RapidTransit, Color{0xfecb09} }, // S4 OSM: 2515408 WD: Q2204443 49.99, 8.516 x 50.18, 8.699
    { 1297, 8090, NoLogo, LineMetaDataContent::LocalTrain, Color{0x0080ff} }, // RE5 OSM: 2523198 WD: Q50374543 52.47, 12.11 x 54.31, 13.46
    { 1301, 8109, NoLogo, LineMetaDataContent::LocalTrain, Color{0x80004d} }, // RE4 OSM: 2523200 WD: Q15195675 52, 12.35 x 52.6, 13.38
    { 58, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 13 OSM: 2529840 55.77, 37.65 x 55.83, 37.77
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff2e17} }, // 1 OSM: 2531659 50.93, 10.67 x 50.95, 10.71
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xaf2a21} }, // 2 OSM: 2531812 50.94, 10.71 x 50.96, 10.72
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff9929} }, // 3 OSM: 2531813 50.94, 10.68 x 50.96, 10.72
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffb530} }, // 4 OSM: 2531864 WD: Q2430929 50.86, 10.52 x 50.95, 10.71
    { 41, 8128, 226, LineMetaDataContent::RapidTransit, Color{0x14bae6} }, // S7 OSM: 2544304 WD: Q1195962 51.16, 7.004 x 51.28, 7.253
    { 1305, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff3818} }, // Тр1 OSM: 2548724 49.83, 24 x 49.84, 24.06
    { 1311, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x1b5620} }, // Тр9 OSM: 2548725 49.83, 23.99 x 49.86, 24.04
    { 1317, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8144a3} }, // Тр6 OSM: 2548730 49.84, 24 x 49.87, 24.04
    { 61, 8139, 226, LineMetaDataContent::RapidTransit, Color{0x7760b0} }, // S1 OSM: 2548861 WD: Q63433445 52.27, 8.934 x 52.42, 9.773
    { 1323, 8155, 8193, LineMetaDataContent::Subway, Color{0x71cc98} }, // 7bis OSM: 2554103 WD: Q50749 48.88, 2.366 x 48.88, 2.4
    { 204, 8226, 226, LineMetaDataContent::RapidTransit, Color{0x005aab} }, // S6 OSM: 2557420 WD: Q63433460 52.37, 9.739 x 52.62, 10.06
    { 1328, 8242, 8265, LineMetaDataContent::Subway, Color{0x62361b} }, // Brown OSM: 2562976 WD: Q3112936 41.88, -87.71 x 41.97, -87.63
    { 218, 8294, 226, LineMetaDataContent::RapidTransit, Color{0x972f50} }, // S4 OSM: 2567719 WD: Q63433455 52.16, 9.687 x 52.58, 9.956
    { 8, NoLogo, 8310, LineMetaDataContent::Subway, Color{0x228b22} }, // M4 OSM: 2568424 WD: Q2552821 44.45, 26.03 x 44.5, 26.07
    { 393, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x9ecd58} }, // L2 OSM: 2568862 WD: Q115328482 59.72, 10.61 x 59.92, 10.84
    { 211, 8328, 5211, LineMetaDataContent::Tramway, Color{0x216eb4} }, // T1 OSM: 2572573 WD: Q369969 48.9, 2.274 x 48.94, 2.47
    { 389, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x9ecd58} }, // L1 OSM: 2575540 WD: Q115217962 59.74, 10.34 x 59.96, 11.05
    { 1334, 8361, 8265, LineMetaDataContent::Subway, Color{0xf9461c} }, // Orange OSM: 2578312 WD: Q3180068 41.79, -87.74 x 41.89, -87.63
    { 1341, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 100 OSM: 2579608 60, 30.34 x 60.06, 30.44
    { 55, 8386, 8405, LineMetaDataContent::Subway, Color{0xe50b00} }, // 1 OSM: 2580502 WD: Q1771534 56.24, 43.86 x 56.32, 43.99
    { 1345, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xa52a2a} }, // Scala mobile OSM: 2581270 41.84, 12.89 x 41.84, 12.89
    { 284, 8417, 8265, LineMetaDataContent::Subway, Color{0xc60c30} }, // Red OSM: 2584583 WD: Q642623 41.72, -87.67 x 42.02, -87.62
    { 204, 8438, 226, LineMetaDataContent::RapidTransit, Color{0xec192e} }, // S6 OSM: 2587144 WD: Q96388302 49.44, 8.256 x 50, 8.667
    { 9, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x78ccc9} }, // 4 OSM: 2588070 50.48, 30.57 x 50.53, 30.61
    { 537, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x228b22} }, // T2 OSM: 2597272 WD: Q113671831 45.46, 12.21 x 45.49, 12.25
    { 1358, 8457, 226, LineMetaDataContent::RapidTransit, Color{0x6b2c94} }, // S 8 OSM: 2605126 WD: Q63213955 51.47, 11.98 x 51.87, 12.66
    { 660, 273, 226, LineMetaDataContent::RapidTransit, Color{0xf17f1a} }, // S 5 OSM: 2606971 WD: Q63216051 50.7, 11.99 x 51.48, 12.48
    { 1362, 8482, NoLogo, LineMetaDataContent::LocalTrain, Color{0xa5027d} }, // RB14 OSM: 2607468 WD: Q15119376 52.36, 12.88 x 52.61, 13.6
    { 1368, 8502, 226, LineMetaDataContent::RapidTransit, Color{0x00a650} }, // S 4 OSM: 2607472 WD: Q63215993 51.25, 12.37 x 51.59, 13.25
    { 1372, 8527, NoLogo, LineMetaDataContent::LocalTrain, Color{0x0474ec} }, // RE 18 OSM: 2607473 WD: Q63348135 51.04, 13.5 x 51.75, 14.33
    { 1378, 8547, NoLogo, LineMetaDataContent::LocalTrain, Color{0xffe600} }, // RE2 OSM: 2607475 WD: Q15119419 51.75, 11.36 x 53.9, 14.33
    { 1382, 8566, NoLogo, LineMetaDataContent::LocalTrain, Color{0x00a25d} }, // RE 15 OSM: 2607476 WD: Q105947741 51.04, 13.5 x 51.46, 14.23
    { 61, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x66cdaa} }, // S1 OSM: 2609006 WD: Q50331474 54.08, 12.06 x 54.18, 12.13
    { 1388, 8586, NoLogo, LineMetaDataContent::LocalTrain, Color{0x36803d} }, // RE1 OSM: 2609008 WD: Q19624774 53.36, 10 x 54.08, 12.15
    { 166, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0xa66540} }, // S3 OSM: 2609009 WD: Q50331483 53.79, 12.06 x 54.18, 12.35
    { 50, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x9400d3} }, // S2 OSM: 2609011 WD: Q50331479 53.8, 12.06 x 54.18, 12.17
    { 1392, 8602, NoLogo, LineMetaDataContent::LocalTrain, Color{0xff5900} }, // RE3 OSM: 2609916 WD: Q15195663 51.58, 12.66 x 54.31, 14.29
    { 1396, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff9700} }, // SFM 1 OSM: 2610264 WD: Q3832755 44.97, 7.603 x 45.42, 7.824
    { 1402, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // SFM 4 OSM: 2610270 WD: Q3832758 44.69, 7.655 x 45.12, 8.031
    { 480, 8621, 8265, LineMetaDataContent::Subway, Color{0x009b3a} }, // Green OSM: 2613599 WD: Q3176204 41.78, -87.81 x 41.89, -87.61
    { 1408, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe30021} }, // 1047 OSM: 2614957 WD: Q115597810 36.46, 2.617 x 36.78, 3.133
    { 1413, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe30021} }, // 1025 OSM: 2614957 WD: Q115597810 36.46, 2.617 x 36.78, 3.133
    { 98, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe30021} }, // 1037 OSM: 2614957 WD: Q115597810 36.46, 2.617 x 36.78, 3.133
    { 1418, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe30021} }, // 1031 OSM: 2614957 WD: Q115597810 36.46, 2.617 x 36.78, 3.133
    { 1423, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe30021} }, // 1057 OSM: 2614957 WD: Q115597810 36.46, 2.617 x 36.78, 3.133
    { 1428, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe30021} }, // 1029 OSM: 2614957 WD: Q115597810 36.46, 2.617 x 36.78, 3.133
    { 1433, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe30021} }, // 1027 OSM: 2614957 WD: Q115597810 36.46, 2.617 x 36.78, 3.133
    { 1438, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe30021} }, // 1051 OSM: 2614957 WD: Q115597810 36.46, 2.617 x 36.78, 3.133
    { 340, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe30021} }, // 1049 OSM: 2614957 WD: Q115597810 36.46, 2.617 x 36.78, 3.133
    { 1443, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe30021} }, // 1039 OSM: 2614957 WD: Q115597810 36.46, 2.617 x 36.78, 3.133
    { 1448, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe30021} }, // 1045 OSM: 2614957 WD: Q115597810 36.46, 2.617 x 36.78, 3.133
    { 1453, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe30021} }, // 1033 OSM: 2614957 WD: Q115597810 36.46, 2.617 x 36.78, 3.133
    { 1458, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe30021} }, // 1035 OSM: 2614957 WD: Q115597810 36.46, 2.617 x 36.78, 3.133
    { 1463, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe30021} }, // 1055 OSM: 2614957 WD: Q115597810 36.46, 2.617 x 36.78, 3.133
    { 1468, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe30021} }, // 1053 OSM: 2614957 WD: Q115597810 36.46, 2.617 x 36.78, 3.133
    { 1473, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe30021} }, // 1023 OSM: 2614957 WD: Q115597810 36.46, 2.617 x 36.78, 3.133
    { 437, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe30021} }, // 1041 OSM: 2614957 WD: Q115597810 36.46, 2.617 x 36.78, 3.133
    { 1478, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x7fd2e6} }, // U44 OSM: 2615764 51.51, 7.385 x 51.53, 7.484
    { 72, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe2000a} }, // 21 OSM: 2617691 49.4, 8.675 x 49.43, 8.693
    { 1189, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfcc200} }, // 22 OSM: 2617692 49.4, 8.627 x 49.41, 8.693
    { 254, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe48e00} }, // 23 OSM: 2617693 49.34, 8.685 x 49.41, 8.693
    { 191, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8b1c75} }, // 24 OSM: 2617694 49.37, 8.66 x 49.47, 8.691
    { 1031, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf39a9a} }, // 26 OSM: 2617695 49.38, 8.658 x 49.43, 8.693
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe3000b} }, // 4 OSM: 2619046 49.46, 8.17 x 49.54, 8.509
    { 6, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00965e} }, // 5 OSM: 2619047 49.4, 8.463 x 49.55, 8.693
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xd5ad00} }, // 3 OSM: 2621587 49.45, 8.449 x 49.54, 8.482
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x956b25} }, // 6 OSM: 2621588 49.44, 8.419 x 49.49, 8.525
    { 42, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffcc00} }, // 7 OSM: 2621590 49.48, 8.407 x 49.52, 8.545
    { 1482, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe17500} }, // 8 EX OSM: 2621591 49.42, 8.407 x 49.52, 8.536
    { 1487, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfcdc12} }, // SFM7 OSM: 2622309 WD: Q15077685 44.55, 7.655 x 45.12, 7.753
    { 277, 8644, 8265, LineMetaDataContent::Subway, Color{0xf9e300} }, // Yellow OSM: 2622574 WD: Q595450 42.02, -87.75 x 42.04, -87.67
    { 318, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x004595} }, // M OSM: 2629655 49.39, 1.042 x 49.45, 1.106
    { 1492, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x20825c} }, // PAO OSM: 2629939 WD: Q7132125 39.95, -75.76 x 40.05, -75.15
    { 132, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf171ab} }, // 9 OSM: 2629996 WD: Q56302775 46.93, 7.431 x 46.97, 7.468
    { 59, 8668, 8690, LineMetaDataContent::Subway, Color{0xa066aa} }, // 3 OSM: 2635252 WD: Q15731044 59.85, 10.5 x 59.94, 10.85
    { 979, 8711, 19, LineMetaDataContent::Tramway, Color{0xdc281e} }, // 29 OSM: 2635531 WD: Q63435524 48.14, 11.49 x 48.16, 11.56
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x028dd2} }, // 6 OSM: 2635960 55.67, 52.28 x 55.77, 52.45
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x3adf00} }, // 8 OSM: 2635970 55.67, 52.28 x 55.77, 52.45
    { 16, 8739, 8690, LineMetaDataContent::Subway, Color{0xf26522} }, // 2 OSM: 2636245 WD: Q15731043 59.91, 10.61 x 59.95, 10.92
    { 6, 8761, 8690, LineMetaDataContent::Subway, Color{0x50b848} }, // 5 OSM: 2640907 WD: Q15731051 59.91, 10.71 x 59.97, 10.93
    { 42, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 7 OSM: 2641075 59.88, 30.38 x 59.93, 30.5
    { 1496, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // Meadowlands OSM: 2641818 WD: Q6803384 40.73, -74.1 x 40.83, -74.03
    { 1508, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa0218c} }, // Pascack Valley OSM: 2641819 WD: Q11328810 40.73, -74.1 x 41.11, -74.01
    { 1523, 8783, 599, LineMetaDataContent::Tramway, Color{0x8874c7} }, // U46 OSM: 2642232 WD: Q107740407 51.5, 7.459 x 51.53, 7.471
    { 1527, 8797, 8817, LineMetaDataContent::Tramway, Color{0x873f98} }, // T5 OSM: 2643507 WD: Q3238967 45.73, 4.879 x 45.74, 4.948
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // 3 OSM: 2644926 55.72, 52.41 x 55.77, 52.5
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xa82582} }, // 4 OSM: 2646469 55.69, 52.41 x 55.77, 52.53
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe6087f} }, // 5 OSM: 2646596 55.72, 52.41 x 55.76, 52.5
    { 42, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x393186} }, // 7 OSM: 2646626 55.69, 52.41 x 55.77, 52.53
    { 1530, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa0a0a0} }, // C-8 OSM: 2647592 40.38, -4.067 x 40.74, -3.181
    { 524, 8845, 8879, LineMetaDataContent::Tramway, Color{0x802990} }, // A OSM: 2648050 WD: Q2658981 44.83, -0.6686 x 44.89, -0.5081
    { 196, 8905, 8879, LineMetaDataContent::Tramway, Color{0xed164b} }, // B OSM: 2648235 WD: Q2420027 44.79, -0.6632 x 44.89, -0.5415
    { 22, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 18 OSM: 2651053 59.99, 30.23 x 60.02, 30.25
    { 254, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 23 OSM: 2651263 59.9, 30.35 x 59.97, 30.5
    { 191, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 24 OSM: 2651264 59.83, 30.38 x 59.93, 30.51
    { 147, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 19 OSM: 2651265 59.98, 30.19 x 59.99, 30.26
    { 1039, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // А OSM: 2651266 59.9, 30.44 x 59.92, 30.5
    { 175, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 27 OSM: 2651267 59.83, 30.44 x 59.92, 30.51
    { 547, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 47 OSM: 2652192 60, 30.23 x 60.02, 30.31
    { 215, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 65 OSM: 2652193 59.91, 30.39 x 59.93, 30.5
    { 1042, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 38 OSM: 2652196 59.98, 30.35 x 60.05, 30.44
    { 95, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 62 OSM: 2652197 59.83, 30.38 x 59.84, 30.42
    { 163, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 60 OSM: 2652198 59.85, 30.12 x 59.88, 30.26
    { 84, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 61 OSM: 2652199 59.97, 30.34 x 60.05, 30.41
    { 1534, 6703, 6703, LineMetaDataContent::Subway, Color{0xff0000} }, // Metropolitana OSM: 2653212 WD: Q1163754 44.4, 8.894 x 44.43, 8.949
    { 27, 8939, NoLogo, LineMetaDataContent::Subway, Color{0x2c8195} }, // 6 OSM: 2653338 WD: Q6553143 25.03, 102.7 x 25.1, 102.9
    { 311, 8959, 8879, LineMetaDataContent::Tramway, Color{0xcf56a0} }, // C OSM: 2654042 WD: Q2331392 44.77, -0.6237 x 44.92, -0.5499
    { 1548, 8993, 8265, LineMetaDataContent::Subway, Color{0xe27ea6} }, // Pink OSM: 2656070 WD: Q3112661 41.85, -87.76 x 41.89, -87.63
    { 272, 9015, 8265, LineMetaDataContent::Subway, Color{0x00a1de} }, // Blue OSM: 2672370 WD: Q2534873 41.87, -87.9 x 41.98, -87.63
    { 1553, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xa3d20b} }, // U47 OSM: 2673747 51.49, 7.382 x 51.55, 7.556
    { 132, 9037, 3795, LineMetaDataContent::Subway, Color{0x87d300} }, // 9 OSM: 2674584 WD: Q5929508 39.81, 116.3 x 39.94, 116.3
    { 1557, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfcdc00} }, // U41 OSM: 2674820 51.48, 7.44 x 51.59, 7.502
    { 433, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00a991} }, // U43 OSM: 2675103 51.51, 7.419 x 51.53, 7.625
    { 42, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x9e0234} }, // 7 OSM: 2675693 51.04, 13.63 x 51.14, 13.8
    { 1565, 9057, 8265, LineMetaDataContent::Subway, Color{0x522398} }, // Purple OSM: 2675822 WD: Q3112074 41.88, -87.69 x 42.07, -87.63
    { 61, 9081, 9093, LineMetaDataContent::RapidTransit, Color{0x159dd9} }, // S1 OSM: 2679058 WD: Q17101540 48.17, 16.33 x 48.34, 16.92
    { 50, 9109, 9093, LineMetaDataContent::RapidTransit, Color{0x159dd9} }, // S2 OSM: 2679059 WD: Q96484152 48.08, 16.28 x 48.72, 16.57
    { 166, 9121, 9093, LineMetaDataContent::RapidTransit, Color{0x159dd9} }, // S3 OSM: 2679060 WD: Q96484012 47.81, 16.06 x 48.56, 16.41
    { 50, 9133, 226, LineMetaDataContent::RapidTransit, Color{0x118349} }, // S2 OSM: 2682237 WD: Q63433449 52.28, 9.217 x 52.65, 9.773
    { 1572, 9149, 3795, LineMetaDataContent::Subway, Color{0x007e84} }, // 4S OSM: 2684711 WD: Q5242742 39.67, 116.3 x 39.81, 116.4
    { 143, 9174, 3795, LineMetaDataContent::Subway, Color{0x6a1d44} }, // 15 OSM: 2688949 WD: Q734917 39.99, 116.3 x 40.13, 116.7
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x006b42} }, // 12 OSM: 2690192 51.04, 13.67 x 51.06, 13.81
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x223344} }, // 2 OSM: 2694563 54.26, 48.28 x 54.34, 48.41
    { 1031, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00aaad} }, // 26 OSM: 2705952 59.27, 18.27 x 59.29, 18.3
    { 231, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00aaad} }, // 25 OSM: 2705957 59.28, 18.11 x 59.31, 18.31
    { 1575, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x003e7e} }, // TRE OSM: 2716975 WD: Q2453601 32.75, -97.33 x 32.82, -96.81
    { 65, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xdc008f} }, // 10 OSM: 2728288 50.06, 14.3 x 50.13, 14.48
    { 54, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xdc008f} }, // 11 OSM: 2728371 50.05, 14.43 x 50.09, 14.5
    { 1579, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0xeb3c2e} }, // S18 OSM: 2729450 WD: Q686782 47.29, 8.547 x 47.37, 8.71
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xa28a6a} }, // 12 OSM: 2729904 50.03, 14.37 x 50.11, 14.45
    { 55, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // 1 OSM: 2746761 WD: Q12406939 31.77, 35.18 x 31.83, 35.24
    { 11, 9195, 6703, LineMetaDataContent::Subway, Color{0xb395d0} }, // M5 OSM: 2753306 WD: Q3238963 45.48, 9.117 x 45.53, 9.212
    { 27, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xf67599} }, // 6 OSM: 2768662 WD: Q5931449 29.49, 106.4 x 29.85, 106.7
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffff00} }, // 1 OSM: 2773668 47.52, 21.62 x 47.56, 21.63
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe3000b} }, // 1 OSM: 2777016 52.2, 10.51 x 52.33, 10.54
    { 1583, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x7b2f3d} }, // M-LINE OSM: 2788830 32.78, -96.8 x 32.81, -96.79
    { 1591, 9215, 226, LineMetaDataContent::RapidTransit, Color{0xd7171f} }, // S 3 OSM: 2793231 WD: Q62749908 51.31, 11.91 x 51.49, 13.11
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x687362} }, // 3 OSM: 2797182 52.5, 103.8 x 52.58, 103.9
    { 1595, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x149943} }, // STY OSM: 2797718 WD: Q7619599 -38.37, 145.1 x -38.14, 145.2
    { 1534, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0078ad} }, // Metropolitana OSM: 2797904 WD: Q1725884 45.51, 10.21 x 45.58, 10.28
    { 65, 9240, NoLogo, LineMetaDataContent::Tramway, Color{0xce1f75} }, // 10 OSM: 2799185 WD: Q70711877 47.38, 8.536 x 47.45, 8.573
    { 15, 9265, NoLogo, LineMetaDataContent::Tramway, Color{0x92d6e3} }, // 12 OSM: 2799201 WD: Q70711314 47.4, 8.556 x 47.45, 8.608
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x4c677a} }, // 1 OSM: 2801578 52.52, 103.9 x 52.56, 103.9
    { 42, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe5e6ea} }, // 7 OSM: 2802264 52.5, 103.8 x 52.53, 103.9
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 3 OSM: 2804939 59.92, 30.28 x 59.97, 30.36
    { 543, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 56 OSM: 2804944 59.86, 30.23 x 59.88, 30.26
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x70492c} }, // 5 OSM: 2807017 WD: Q96483196 47.36, 8.516 x 47.38, 8.572
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xbe8543} }, // 6 OSM: 2807025 WD: Q96483372 47.36, 8.531 x 47.38, 8.572
    { 42, 9290, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 7 OSM: 2807030 WD: Q70712535 47.34, 8.53 x 47.41, 8.597
    { 132, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x322e71} }, // 9 OSM: 2807033 WD: Q70710278 47.37, 8.495 x 47.41, 8.592
    { 139, 9314, NoLogo, LineMetaDataContent::Tramway, Color{0x0093d0} }, // 14 OSM: 2807051 WD: Q70714895 47.37, 8.495 x 47.42, 8.55
    { 54, 9339, NoLogo, LineMetaDataContent::Tramway, Color{0x00923c} }, // 11 OSM: 2807068 WD: Q70714560 47.35, 8.533 x 47.42, 8.583
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00923c} }, // 3 OSM: 2807070 WD: Q96483170 47.36, 8.485 x 47.38, 8.567
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x322e71} }, // 4 OSM: 2807089 WD: Q96483185 47.35, 8.49 x 47.39, 8.561
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xcb0a25} }, // 2 OSM: 2807095 WD: Q73249054 47.35, 8.444 x 47.4, 8.561
    { 143, 9364, NoLogo, LineMetaDataContent::Tramway, Color{0xcb0a25} }, // 15 OSM: 2807117 WD: Q70707977 47.37, 8.533 x 47.4, 8.548
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8bc036} }, // 8 OSM: 2807118 WD: Q96483377 47.36, 8.504 x 47.39, 8.567
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf39100} }, // 5 OSM: 2810470 52.23, 10.48 x 52.26, 10.54
    { 26, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xa9c1d1} }, // 16 OSM: 2820891 50.07, 14.36 x 50.08, 14.53
    { 55, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0b0080} }, // 1 OSM: 2826218 WD: Q5017774 29.85, 31.23 x 30.16, 31.34
    { 9, 9389, 8690, LineMetaDataContent::Subway, Color{0x0054a6} }, // 4 OSM: 2827680 WD: Q15731046 59.87, 10.71 x 59.97, 10.93
    { 277, NoLogo, 9406, LineMetaDataContent::Subway, Color{0xffe800} }, // Yellow OSM: 2827687 WD: Q54874971 37.6, -122.5 x 38.02, -121.9
    { 1166, 3240, 3269, LineMetaDataContent::RapidTransit, Color{0xf166a7} }, // 40 OSM: 2836163 WD: Q106806725 59.17, 17.63 x 59.86, 18.07
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x006531} }, // 3 OSM: 2837394 52.24, 10.47 x 52.29, 10.58
    { 55, 9420, NoLogo, LineMetaDataContent::Subway, Color{0xe60039} }, // 1 OSM: 2843401 WD: Q6850056 28.68, 115.8 x 28.75, 116
    { 605, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xbed639} }, // 82 OSM: 2844184 WD: Q6811974 -37.8, 144.9 x -37.77, 144.9
    { 284, 9446, 9406, LineMetaDataContent::Subway, Color{0xed1c24} }, // Red OSM: 2851513 WD: Q3809179 37.6, -122.5 x 37.94, -122.3
    { 1334, 9463, 9406, LineMetaDataContent::Subway, Color{0xfaa61a} }, // Orange OSM: 2851514 WD: Q3866809 37.37, -122.4 x 37.94, -121.9
    { 480, 9479, 9406, LineMetaDataContent::Subway, Color{0x4db848} }, // Green OSM: 2851729 WD: Q3720557 37.37, -122.5 x 37.81, -121.9
    { 272, 9497, 9406, LineMetaDataContent::Subway, Color{0x00aeef} }, // Blue OSM: 2851730 WD: Q3720569 37.69, -122.5 x 37.81, -121.9
    { 54, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x86c5a2} }, // 11 OSM: 2858845 WD: Q18165625 -37.82, 144.9 x -37.73, 145
    { 42, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x878a83} }, // 7 OSM: 2860817 WD: Q1138075 59.32, 18.06 x 59.33, 18.11
    { 1045, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00907a} }, // S31 OSM: 2872363 48.99, 8.399 x 49.18, 8.747
    { 962, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00907a} }, // S32 OSM: 2872364 48.99, 8.399 x 49.16, 8.775
    { 116, 9512, 1095, LineMetaDataContent::Subway, Color{0x2ec6ff} }, // U4 OSM: 2872790 WD: Q209739 53.53, 9.983 x 53.56, 10.04
    { 54, 9527, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff7f50} }, // 11 OSM: 2875658 WD: Q5245830 -23.56, -46.64 x -23.52, -46.19
    { 15, 9539, NoLogo, LineMetaDataContent::RapidTransit, Color{0x1c146b} }, // 12 OSM: 2877633 WD: Q5245789 -23.55, -46.62 x -23.48, -46.33
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8c6e66} }, // 6 OSM: 2877971 52.5, 103.8 x 52.56, 103.9
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xec7394} }, // 4 OSM: 2877979 52.5, 103.8 x 52.53, 103.9
    { 42, 9551, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa8034f} }, // 7 OSM: 2885794 WD: Q3296728 -23.55, -46.87 x -23.19, -46.62
    { 55, 9562, 8690, LineMetaDataContent::Subway, Color{0x00b6f1} }, // 1 OSM: 2890637 WD: Q15731038 59.87, 10.65 x 59.98, 10.82
    { 65, 9579, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00ced1} }, // 10 OSM: 2893113 WD: Q5245819 -23.74, -46.62 x -23.54, -46.39
    { 196, 9591, 4830, LineMetaDataContent::Subway, Color{0xffa500} }, // B OSM: 2896644 WD: Q18420098 6.247, -75.61 x 6.259, -75.57
    { 1601, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x211e1e} }, // TU OSM: 2897278 WD: Q16438501 -34.93, -57.95 x -34.9, -57.92
    { 1604, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x546684} }, // DPM OSM: 2914673 WD: Q1201543 42.32, -83.05 x 42.34, -83.04
    { 222, 9630, 226, LineMetaDataContent::RapidTransit, Color{0xffff00} }, // S 1 OSM: 2920398 WD: Q56600177 51.31, 12.27 x 51.37, 12.41
    { 147, 9655, NoLogo, LineMetaDataContent::Tramway, Color{0xf7942a} }, // 19 OSM: 2921482 WD: Q109462009 59.85, 10.72 x 59.93, 10.8
    { 22, 9679, NoLogo, LineMetaDataContent::Tramway, Color{0xfdb927} }, // 18 OSM: 2921905 WD: Q56850451 59.91, 10.71 x 59.95, 10.78
    { 311, 9699, 2617, LineMetaDataContent::Subway, Color{0x003ea1} }, // C OSM: 2931139 WD: Q1157050 -34.63, -58.38 x -34.59, -58.37
    { 196, 9727, 2617, LineMetaDataContent::Subway, Color{0xc20924} }, // B OSM: 2933167 WD: Q1157061 -34.6, -58.49 x -34.57, -58.37
    { 363, 9755, 2617, LineMetaDataContent::Subway, Color{0x6b297e} }, // E OSM: 2933872 WD: Q1044919 -34.64, -58.46 x -34.59, -58.37
    { 1028, 9783, 2617, LineMetaDataContent::Subway, Color{0x217861} }, // D OSM: 2934099 WD: Q1157052 -34.61, -58.46 x -34.56, -58.37
    { 34, 9811, 2617, LineMetaDataContent::Subway, Color{0xf4cc21} }, // H OSM: 2934107 WD: Q1132660 -34.64, -58.41 x -34.58, -58.39
    { 346, NoLogo, 8310, LineMetaDataContent::Subway, Color{0x4b5799} }, // M2 OSM: 2947130 WD: Q1884455 44.36, 26.09 x 44.48, 26.15
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf9b000} }, // 4 OSM: 2951397 WD: Q63350784 52.37, 9.596 x 52.42, 9.819
    { 211, 9839, 9867, LineMetaDataContent::Tramway, Color{0x281570} }, // T1 OSM: 2962731 WD: Q6043955 41, 28.86 x 41.03, 28.99
    { 942, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x6f1b14} }, // 94 OSM: 2982672 51.48, 11.93 x 51.51, 11.97
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf9b000} }, // 6 OSM: 2991603 WD: Q63350805 52.32, 9.69 x 52.42, 9.837
    { 54, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf9b000} }, // 11 OSM: 2991649 WD: Q63350814 52.37, 9.713 x 52.39, 9.775
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf9b000} }, // 5 OSM: 2991701 WD: Q63350794 52.36, 9.659 x 52.41, 9.859
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe4003a} }, // 1 OSM: 2995652 WD: Q63344401 52.24, 9.731 x 52.44, 9.86
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe4003a} }, // 2 OSM: 2998555 WD: Q63345326 52.29, 9.734 x 52.42, 9.818
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe4003a} }, // 8 OSM: 2998722 WD: Q63345432 52.33, 9.734 x 52.4, 9.805
    { 179, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x76b82a} }, // 17 OSM: 2998733 WD: Q63348315 52.34, 9.718 x 52.38, 9.743
    { 65, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x76b82a} }, // 10 OSM: 3004809 WD: Q63348270 52.37, 9.664 x 52.39, 9.756
    { 1608, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x051541} }, // 95 OSM: 3006197 51.42, 11.96 x 51.52, 11.99
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xed1943} }, // 12 OSM: 3009639 WD: Q2189640 51.88, 4.471 x 51.92, 4.568
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0069b4} }, // 3 OSM: 3016071 WD: Q63348707 52.33, 9.69 x 52.44, 9.848
    { 42, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0069b4} }, // 7 OSM: 3038575 WD: Q63348805 52.33, 9.69 x 52.41, 9.854
    { 132, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0069b4} }, // 9 OSM: 3038600 WD: Q63349759 52.34, 9.667 x 52.43, 9.802
    { 143, 9895, 8193, LineMetaDataContent::Subway, Color{0xb90845} }, // 15 OSM: 3094380 WD: Q3240151 48.78, 2.197 x 48.92, 2.583
    { 1611, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x236214} }, // UP-N OSM: 3117549 WD: Q7885883 41.88, -87.85 x 42.59, -87.64
    { 1616, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff821d} }, // MD-N OSM: 3117594 WD: Q16982046 41.88, -88.18 x 42.4, -87.64
    { 1621, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7c53af} }, // NCS OSM: 3117600 WD: Q7054760 41.88, -88.09 x 42.48, -87.64
    { 1625, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfae218} }, // UP-NW OSM: 3117607 WD: Q16985937 41.88, -88.62 x 42.42, -87.64
    { 1631, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfeb8fa} }, // UP-W OSM: 3117615 WD: Q7885886 41.86, -88.47 x 41.9, -87.64
    { 1636, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x77b337} }, // BNSF OSM: 3117619 WD: Q4836140 41.76, -88.31 x 41.88, -87.64
    { 1641, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xee4848} }, // HC OSM: 3117625 WD: Q5738778 41.52, -88.08 x 41.88, -87.64
    { 490, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa81818} }, // RI OSM: 3117651 41.51, -88.08 x 41.88, -87.63
    { 1644, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x117bac} }, // SWS OSM: 3117664 WD: Q7565331 41.42, -87.99 x 41.88, -87.64
    { 1648, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf67b7b} }, // ME OSM: 3117670 WD: Q4501968 41.46, -87.72 x 41.89, -87.55
    { 1652, 9931, 226, LineMetaDataContent::RapidTransit, Color{0x00ffff} }, // S 2 OSM: 3119892 WD: Q56809294 51.31, 12.23 x 51.87, 12.66
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xafe0ee} }, // 8 OSM: 3144745 WD: Q56302773 46.94, 7.374 x 46.95, 7.487
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x088742} }, // 2 OSM: 3152801 51.13, 14.94 x 51.17, 14.99
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff2e17} }, // 1 OSM: 3152809 51.12, 14.97 x 51.17, 14.99
    { 1656, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // LBN OSM: 3155062 WD: Q46654325 -34.59, -58.87 x -34.42, -58.37
    { 264, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // FM1 OSM: 3158700 41.12, 16.78 x 41.14, 16.87
    { 345, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffc100} }, // FM2 OSM: 3158701 41.11, 16.68 x 41.14, 16.87
    { 41, 9956, 226, LineMetaDataContent::RapidTransit, Color{0xa5ce43} }, // S7 OSM: 3168072 WD: Q63433461 52.37, 9.739 x 52.62, 10.06
    { 143, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 15 OSM: 3184018 55.8, 37.39 x 55.81, 37.51
    { 254, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 23 OSM: 3184019 55.81, 37.49 x 55.84, 37.53
    { 297, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 30 OSM: 3184021 55.8, 37.39 x 55.84, 37.53
    { 1019, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 28 OSM: 3184024 55.78, 37.45 x 55.81, 37.51
    { 65, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 10 OSM: 3184063 55.8, 37.39 x 55.81, 37.46
    { 72, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 21 OSM: 3184064 55.8, 37.39 x 55.81, 37.46
    { 175, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 27 OSM: 3184107 55.81, 37.5 x 55.84, 37.58
    { 231, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 25 OSM: 3186266 55.79, 37.62 x 55.83, 37.69
    { 524, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xca305b} }, // A OSM: 3190626 WD: Q3537211 47.34, 0.6578 x 47.42, 0.7119
    { 58, 9972, NoLogo, LineMetaDataContent::Tramway, Color{0x00b26b} }, // 13 OSM: 3201250 WD: Q109462007 59.85, 10.59 x 59.93, 10.8
    { 54, 9996, NoLogo, LineMetaDataContent::Tramway, Color{0x82c341} }, // 11 OSM: 3218724 WD: Q109462005 59.91, 10.72 x 59.96, 10.79
    { 15, 10020, NoLogo, LineMetaDataContent::Tramway, Color{0xa166aa} }, // 12 OSM: 3221100 WD: Q109462006 59.91, 10.7 x 59.96, 10.79
    { 9, 10044, 10058, LineMetaDataContent::Subway, Color{0xf1ce00} }, // 4 OSM: 3228501 WD: Q1597847 45.51, -73.56 x 45.52, -73.52
    { 16, 10077, 10058, LineMetaDataContent::Subway, Color{0xd06d07} }, // 2 OSM: 3228502 WD: Q967397 45.47, -73.73 x 45.56, -73.55
    { 6, 10091, 10058, LineMetaDataContent::Subway, Color{0x3465b4} }, // 5 OSM: 3228503 WD: Q1726049 45.49, -73.63 x 45.56, -73.6
    { 55, 10105, 10058, LineMetaDataContent::Subway, Color{0x5f8c55} }, // 1 OSM: 3228504 WD: Q1925762 45.44, -73.61 x 45.6, -73.53
    { 16, 10119, NoLogo, LineMetaDataContent::Subway, Color{0x00629b} }, // 2 OSM: 3244073 WD: Q1047377 22.99, 113.3 x 23.24, 113.3
    { 110, 10139, 571, LineMetaDataContent::Subway, Color{0xa762a4} }, // U2 OSM: 3245522 WD: Q873397 48.21, 16.36 x 48.23, 16.51
    { 59, 10151, NoLogo, LineMetaDataContent::Subway, Color{0xd9001c} }, // 3 OSM: 3252762 WD: Q3294315 -23.55, -46.67 x -23.53, -46.47
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 3 OSM: 3258552 47.2, 38.9 x 47.23, 38.94
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 4 OSM: 3258575 47.2, 38.88 x 47.26, 38.92
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 5 OSM: 3258583 47.2, 38.89 x 47.24, 38.94
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 6 OSM: 3258591 47.2, 38.88 x 47.24, 38.91
    { 42, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 7 OSM: 3258600 47.22, 38.89 x 47.26, 38.92
    { 179, 10165, NoLogo, LineMetaDataContent::Tramway, Color{0xef4123} }, // 17 OSM: 3259480 WD: Q109462008 59.91, 10.71 x 59.95, 10.78
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 1 OSM: 3272067 47.2, 38.88 x 47.23, 38.92
    { 107, 10189, 571, LineMetaDataContent::Subway, Color{0xe20613} }, // U1 OSM: 3278144 WD: Q663755 48.14, 16.37 x 48.28, 16.45
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 2 OSM: 3285146 47.2, 38.92 x 47.26, 38.94
    { 166, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf5821f} }, // S3 OSM: 3298634 46.54, 14.24 x 46.62, 14.32
    { 42, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 7 OSM: 3299881 55.77, 37.58 x 55.82, 37.73
    { 524, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xef3f30} }, // A OSM: 3309751 WD: Q3239051 47.44, -0.5972 x 47.51, -0.5454
    { 26, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xaf1867} }, // 16 OSM: 3315633 51.43, 11.9 x 51.48, 11.99
    { 1660, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0e58c4} }, // خط الضاحية الجنوبية لتونس OSM: 3316983 WD: Q3240068 36.7, 10.18 x 36.79, 10.42
    { 9, 10201, 8193, LineMetaDataContent::Subway, Color{0xc800a1} }, // 4 OSM: 3326845 WD: Q50743 48.8, 2.316 x 48.9, 2.359
    { 139, 10236, 8193, LineMetaDataContent::Subway, Color{0x5f259f} }, // 14 OSM: 3328694 WD: Q50761 48.73, 2.31 x 48.92, 2.387
    { 55, 10272, 8193, LineMetaDataContent::Subway, Color{0xffcd00} }, // 1 OSM: 3328695 WD: Q13224 48.84, 2.23 x 48.89, 2.441
    { 132, 10307, 8193, LineMetaDataContent::Subway, Color{0xb5bd00} }, // 9 OSM: 3328717 WD: Q50753 48.83, 2.231 x 48.87, 2.442
    { 116, 10342, 10358, LineMetaDataContent::Subway, Color{0x00a082} }, // U4 OSM: 3328726 WD: Q20439761 48.13, 11.52 x 48.15, 11.62
    { 65, 10382, 8193, LineMetaDataContent::Subway, Color{0xc69214} }, // 10 OSM: 3328741 WD: Q50754 48.84, 2.228 x 48.85, 2.365
    { 27, 10418, 8193, LineMetaDataContent::Subway, Color{0x71cc98} }, // 6 OSM: 3328765 WD: Q50746 48.83, 2.285 x 48.87, 2.402
    { 42, 10453, 8193, LineMetaDataContent::Subway, Color{0xf59bbb} }, // 7 OSM: 3328805 WD: Q50748 48.79, 2.332 x 48.92, 2.411
    { 2, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xbb0022} }, // 0 OSM: 3348003 WD: Q118899944 51.08, 2.581 x 51.34, 3.285
    { 1708, 10488, NoLogo, LineMetaDataContent::LocalTrain, Color{0xf47922} }, // RB55 OSM: 3366300 WD: Q63224617 52.64, 13.04 x 52.75, 13.21
    { 1713, 10508, NoLogo, LineMetaDataContent::LocalTrain, Color{0x007734} }, // RB20 OSM: 3366342 WD: Q68007873 52.39, 12.97 x 52.75, 13.29
    { 55, 10528, NoLogo, LineMetaDataContent::Tramway, Color{0xe3000f} }, // 1 OSM: 3367545 WD: Q78199222 48.34, 10.87 x 48.38, 10.94
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x951881} }, // 4 OSM: 3367554 48.37, 10.88 x 48.4, 10.89
    { 995, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0097ba} }, // S42 OSM: 3368507 49.14, 8.875 x 49.25, 9.229
    { 1651, 10548, 226, LineMetaDataContent::RapidTransit, Color{0xff9e00} }, // RS 2 OSM: 3372285 WD: Q84703704 52.79, 8.597 x 53.57, 8.895
    { 221, 10563, 226, LineMetaDataContent::RapidTransit, Color{0x0000ee} }, // RS 1 OSM: 3372313 WD: Q84703702 52.92, 8.516 x 53.21, 9.238
    { 1046, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 31 OSM: 3375725 55.78, 37.45 x 55.82, 37.5
    { 198, 10578, NoLogo, LineMetaDataContent::LocalTrain, Color{} }, // RB 58 OSM: 3379684 WD: Q108409640 47.85, 11.53 x 48.14, 12.12
    { 218, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xec008c} }, // S4 OSM: 3379960 47.04, 8.978 x 47.48, 9.651
    { 1718, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0xfdd456} }, // S 5X OSM: 3382470 WD: Q63216058 50.7, 11.99 x 51.48, 12.48
    { 1479, 10595, 7105, LineMetaDataContent::Tramway, Color{0xf3c300} }, // 44 OSM: 3394367 WD: Q1931983 50.82, 4.409 x 50.84, 4.514
    { 1035, 10617, 7105, LineMetaDataContent::Tramway, Color{0xe43c2e} }, // 39 OSM: 3394368 WD: Q2719066 50.83, 4.409 x 50.85, 4.504
    { 252, 10639, NoLogo, LineMetaDataContent::LocalTrain, Color{0xeb7405} }, // RB23 OSM: 3399395 WD: Q108546612 52.36, 12.97 x 52.53, 13.6
    { 65, 10659, 10680, LineMetaDataContent::Subway, Color{0xeac384} }, // 10 OSM: 3400216 WD: Q6553053 31.98, 118.6 x 32.07, 118.8
    { 55, 10703, 10680, LineMetaDataContent::Subway, Color{0x00a2df} }, // 1 OSM: 3400217 WD: Q6127241 31.9, 118.8 x 32.15, 118.9
    { 1723, 10723, NoLogo, LineMetaDataContent::LocalTrain, Color{0xff5900} }, // RB13 OSM: 3407777 WD: Q63434598 52.53, 12.94 x 52.55, 13.31
    { 16, 10743, 10680, LineMetaDataContent::Subway, Color{0xc7003f} }, // 2 OSM: 3413089 WD: Q5960302 31.96, 118.7 x 32.12, 119
    { 1728, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // MTM OSM: 3413332 WD: Q1337838 -32.96, -68.85 x -32.84, -68.78
    { 61, 10763, 226, LineMetaDataContent::RapidTransit, Color{0x0095da} }, // S1 OSM: 3413905 WD: Q600891 49.97, 8.244 x 50.11, 8.885
    { 50, 10780, 226, LineMetaDataContent::RapidTransit, Color{0xee1c23} }, // S2 OSM: 3414422 WD: Q1985592 50.01, 8.31 x 50.16, 8.813
    { 47, 10797, 226, LineMetaDataContent::RapidTransit, Color{0xd7df23} }, // S8 OSM: 3415070 WD: Q2005458 49.98, 8.242 x 50.13, 8.931
    { 477, 10814, 226, LineMetaDataContent::RapidTransit, Color{0x91268f} }, // S9 OSM: 3415113 WD: Q508402 49.98, 8.244 x 50.13, 8.931
    { 1732, 10831, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfab700} }, // C-5 OSM: 3418151 WD: Q3832677 40.25, -3.883 x 40.41, -3.677
    { 15, 10846, NoLogo, LineMetaDataContent::Tramway, Color{0xbb0022} }, // 12 OSM: 3419132 WD: Q2200976 51.22, 4.42 x 51.23, 4.44
    { 132, 10869, NoLogo, LineMetaDataContent::Tramway, Color{0xee8822} }, // 9 OSM: 3419133 WD: Q1891687 51.2, 4.344 x 51.22, 4.464
    { 191, 10891, NoLogo, LineMetaDataContent::Tramway, Color{0xff88aa} }, // 24 OSM: 3419134 WD: Q2483765 51.2, 4.408 x 51.24, 4.484
    { 59, 10914, NoLogo, LineMetaDataContent::Tramway, Color{0xffcc11} }, // 3 OSM: 3419435 WD: Q3238908 51.22, 4.305 x 51.26, 4.464
    { 9, 10936, NoLogo, LineMetaDataContent::Tramway, Color{0x1199dd} }, // 4 OSM: 3419473 WD: Q2344285 51.17, 4.35 x 51.22, 4.484
    { 6, 10958, NoLogo, LineMetaDataContent::Tramway, Color{0x771133} }, // 5 OSM: 3419525 WD: Q2147524 51.22, 4.344 x 51.23, 4.512
    { 27, 10980, NoLogo, LineMetaDataContent::Tramway, Color{0xdd0077} }, // 6 OSM: 3419912 WD: Q2128494 51.18, 4.391 x 51.26, 4.443
    { 42, 11002, NoLogo, LineMetaDataContent::Tramway, Color{0x0044bb} }, // 7 OSM: 3420306 WD: Q2413292 51.17, 4.4 x 51.23, 4.449
    { 65, 11024, NoLogo, LineMetaDataContent::Tramway, Color{0xbbdd00} }, // 10 OSM: 3420544 WD: Q1962342 51.17, 4.362 x 51.23, 4.512
    { 143, 11046, NoLogo, LineMetaDataContent::Tramway, Color{0xffffff} }, // 15 OSM: 3420997 WD: Q959739 51.17, 4.361 x 51.22, 4.494
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf5d200} }, // 1 OSM: 3430333 49.72, 13.37 x 49.78, 13.4
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf5d200} }, // 2 OSM: 3430559 49.73, 13.32 x 49.75, 13.41
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf5d200} }, // 4 OSM: 3430578 49.73, 13.36 x 49.78, 13.38
    { 1605, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x913108} }, // PM OSM: 3433159 37.78, -122.4 x 37.81, -122.4
    { 1736, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x913108} }, // PH OSM: 3433160 37.78, -122.4 x 37.81, -122.4
    { 447, 11069, NoLogo, LineMetaDataContent::RapidTransit, Color{0x539cbe} }, // K OSM: 3433320 WD: Q6342899 37.72, -122.5 x 37.79, -122.4
    { 451, 11090, NoLogo, LineMetaDataContent::RapidTransit, Color{0x92278f} }, // L OSM: 3435879 WD: Q16981005 37.74, -122.5 x 37.79, -122.4
    { 318, 11109, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008752} }, // M OSM: 3435882 WD: Q6720518 37.71, -122.5 x 37.79, -122.4
    { 517, 11131, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00539b} }, // N OSM: 3435884 WD: Q6956302 37.76, -122.5 x 37.79, -122.4
    { 147, 11148, 7105, LineMetaDataContent::Tramway, Color{0xe43c2e} }, // 19 OSM: 3437796 WD: Q2702907 50.86, 4.275 x 50.9, 4.357
    { 1739, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0066cc} }, // LBS OSM: 3443504 WD: Q67311453 -34.83, -58.94 x -34.65, -58.42
    { 119, 11170, 10358, LineMetaDataContent::Subway, Color{0xa06e1e} }, // U5 OSM: 3475206 WD: Q3832790 48.09, 11.5 x 48.14, 11.65
    { 122, 11186, 10358, LineMetaDataContent::Subway, Color{0x005a96} }, // U6 OSM: 3477966 WD: Q751039 48.11, 11.47 x 48.27, 11.67
    { 113, 11202, 10358, LineMetaDataContent::Subway, Color{0xe66432} }, // U3 OSM: 3484056 WD: Q20439760 48.09, 11.48 x 48.19, 11.59
    { 1743, 11218, NoLogo, LineMetaDataContent::LocalTrain, Color{0x90244b} }, // RB49 OSM: 3490614 WD: Q84436359 51.44, 13.25 x 51.75, 14.32
    { 39, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf38b00} }, // T OSM: 3494094 WD: Q1999971 47.24, -122.4 x 47.26, -122.4
    { 393, 11238, NoLogo, LineMetaDataContent::Subway, Color{0x000000} }, // L2 OSM: 3517295 WD: Q3011583 43.24, -3.042 x 43.33, -2.881
    { 122, 11261, 1095, LineMetaDataContent::Subway, Color{0x007ec6} }, // U6 OSM: 3524791 WD: Q19863008 50.11, 8.624 x 50.14, 8.708
    { 204, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x66c18c} }, // S6 OSM: 3529247 46.92, 8.814 x 47.23, 9.084
    { 107, 11278, 10358, LineMetaDataContent::Subway, Color{0x46b450} }, // U1 OSM: 3531712 WD: Q20439756 48.1, 11.53 x 48.18, 11.58
    { 110, 11294, 10358, LineMetaDataContent::Subway, Color{0xb4283c} }, // U2 OSM: 3531713 WD: Q830301 48.11, 11.54 x 48.21, 11.7
    { 125, 11310, 10358, LineMetaDataContent::Subway, Color{0x46b450} }, // U7 OSM: 3531714 WD: Q20439774 48.1, 11.53 x 48.18, 11.65
    { 128, 11326, 10358, LineMetaDataContent::Subway, Color{0xb4283c} }, // U8 OSM: 3531715 WD: Q20439777 48.1, 11.56 x 48.18, 11.65
    { 61, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x006536} }, // S1 OSM: 3533698 WD: Q106453739 47.4, 8.632 x 47.7, 9.4
    { 6, 11342, NoLogo, LineMetaDataContent::Subway, Color{0x9200c3} }, // 5 OSM: 3539820 WD: Q3308465 -23.66, -46.77 x -23.59, -46.63
    { 524, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe3000b} }, // A OSM: 3555528 WD: Q107044417 49.49, 0.09576 x 49.53, 0.137
    { 196, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00963e} }, // B OSM: 3555531 WD: Q107044421 49.49, 0.09576 x 49.52, 0.1801
    { 1748, 11356, NoLogo, LineMetaDataContent::LongDistanceTrain, Color{0x0e7135} }, // IC LSA<=>BRA OSM: 3572421 WD: Q917100 38.71, -9.123 x 41.55, -8.415
    { 1761, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x50b948} }, // U BRA OSM: 3579399 41.14, -8.61 x 41.55, -8.434
    { 1035, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 39 OSM: 3587361 59.86, 30.38 x 59.93, 30.47
    { 537, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffdd00} }, // T2 OSM: 3589646 WD: Q3239232 45.44, 4.384 x 45.45, 4.403
    { 1767, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xafcb07} }, // T3 OSM: 3589647 WD: Q3239231 45.42, 4.378 x 45.47, 4.405
    { 55, 11373, NoLogo, LineMetaDataContent::Subway, Color{0x1a5ba3} }, // 1 OSM: 3596996 WD: Q3362568 -23.65, -46.64 x -23.48, -46.6
    { 9, 11387, NoLogo, LineMetaDataContent::Subway, Color{0xffd700} }, // 4 OSM: 3613482 WD: Q3308457 -23.59, -46.73 x -23.54, -46.63
    { 284, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xcd5c5c} }, // Red OSM: 3616739 WD: Q2472181 53.28, -6.438 x 53.35, -6.229
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00bb00} }, // 3 OSM: 3618379 WD: Q107187377 58.58, 16.13 x 58.61, 16.19
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xcc0000} }, // 2 OSM: 3618409 WD: Q107187376 58.55, 16.13 x 58.61, 16.23
    { 16, 11401, NoLogo, LineMetaDataContent::Subway, Color{0x008162} }, // 2 OSM: 3619672 WD: Q588499 -23.6, -46.69 x -23.55, -46.58
    { 1770, 11415, 5211, LineMetaDataContent::Tramway, Color{0x009641} }, // T3b OSM: 3662457 WD: Q3136247 48.85, 2.301 x 48.9, 2.411
    { 211, 11449, 8817, LineMetaDataContent::Tramway, Color{0x873f98} }, // T1 OSM: 3667340 WD: Q2903 45.73, 4.817 x 45.79, 4.884
    { 1774, NoLogo, 8817, LineMetaDataContent::Tramway, Color{0xb80e28} }, // Rhônexpress OSM: 3667553 WD: Q1559 45.72, 4.862 x 45.78, 5.077
    { 537, 11469, 8817, LineMetaDataContent::Tramway, Color{0x873f98} }, // T2 OSM: 3667554 WD: Q2906 45.69, 4.819 x 45.75, 4.956
    { 1767, 11489, 8817, LineMetaDataContent::Tramway, Color{0x873f98} }, // T3 OSM: 3667555 WD: Q2911 45.75, 4.862 x 45.78, 5.035
    { 1787, 11509, 8817, LineMetaDataContent::Tramway, Color{0x873f98} }, // T4 OSM: 3667556 WD: Q2918 45.69, 4.858 x 45.78, 4.888
    { 196, 11529, 11550, LineMetaDataContent::Subway, Color{0x007dc5} }, // B OSM: 3687323 WD: Q2965 45.72, 4.81 x 45.77, 4.864
    { 1028, 11579, 11550, LineMetaDataContent::Subway, Color{0x00ac4d} }, // D OSM: 3687324 WD: Q2976 45.7, 4.803 x 45.78, 4.89
    { 311, 11600, 11550, LineMetaDataContent::Subway, Color{0xf99d1d} }, // C OSM: 3687325 WD: Q2969 45.77, 4.827 x 45.79, 4.836
    { 524, 11621, 11550, LineMetaDataContent::Subway, Color{0xee3898} }, // A OSM: 3687326 WD: Q2944 45.75, 4.826 x 45.77, 4.922
    { 113, 11642, 571, LineMetaDataContent::Subway, Color{0xef7c00} }, // U3 OSM: 3752340 WD: Q876472 48.17, 16.31 x 48.21, 16.42
    { 1790, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x93c13b} }, // 9 EX OSM: 3757041 49.46, 8.17 x 49.49, 8.523
    { 95, 11654, 7105, LineMetaDataContent::Tramway, Color{0xf29dc3} }, // 62 OSM: 3775501 WD: Q2544169 50.86, 4.334 x 50.88, 4.435
    { 1795, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // Line 3 OSM: 3788350 WD: Q341464 29.25, 47.97 x 29.26, 47.97
    { 430, 11676, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 48 OSM: 3820771 WD: Q15982247 47.44, 19.03 x 47.5, 19.06
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 3 OSM: 3822945 55.16, 30.21 x 55.2, 30.24
    { 42, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 7 OSM: 3823035 55.16, 30.12 x 55.2, 30.27
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 1 OSM: 3823370 55.16, 30.12 x 55.2, 30.23
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 2 OSM: 3823520 55.16, 30.12 x 55.19, 30.24
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 6 OSM: 3824263 55.16, 30.12 x 55.2, 30.19
    { 132, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 9 OSM: 3824285 55.16, 30.12 x 55.2, 30.2
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 8 OSM: 3824316 55.16, 30.14 x 55.2, 30.24
    { 691, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0066cc} }, // LR OSM: 3846824 WD: Q3239186 -36.02, -60.02 x -34.63, -57.95
    { 1019, 11700, 19, LineMetaDataContent::Tramway, Color{0x00a082} }, // 28 OSM: 3858971 WD: Q20439076 48.13, 11.56 x 48.17, 11.58
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xbbee00} }, // 3 OSM: 3862190 WD: Q100159791 51.27, 9.441 x 51.34, 9.518
    { 1546, 11721, 11751, LineMetaDataContent::Subway, Color{0xed1c24} }, // a OSM: 3889841 WD: Q24641190 48.09, -1.711 x 48.12, -1.644
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008995} }, // 12 OSM: 3903646 WD: Q18165631 -37.86, 145 x -37.81, 145
    { 1802, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00a1de} }, // West Hempstead OSM: 3917588 WD: Q7985342 40.66, -73.97 x 40.71, -73.64
    { 311, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe4007c} }, // C OSM: 3921484 WD: Q3239086 45.17, 5.69 x 45.19, 5.776
    { 363, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x58318a} }, // E OSM: 3921488 WD: Q3239103 45.17, 5.661 x 45.26, 5.72
    { 196, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009b3a} }, // B OSM: 3921491 WD: Q3239068 45.18, 5.698 x 45.21, 5.787
    { 524, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0076bd} }, // A OSM: 3921492 WD: Q3239056 45.14, 5.671 x 45.2, 5.734
    { 1028, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf39a00} }, // D OSM: 3921494 WD: Q3239096 45.17, 5.754 x 45.19, 5.759
    { 265, 11773, 2668, LineMetaDataContent::Subway, Color{0x007d58} }, // M1 OSM: 3931373 WD: Q1880894 55.62, 12.49 x 55.69, 12.59
    { 55, 11785, NoLogo, LineMetaDataContent::Subway, Color{0xf3d03e} }, // 1 OSM: 3936877 WD: Q1047385 23.07, 113.2 x 23.15, 113.3
    { 204, 2154, 226, LineMetaDataContent::RapidTransit, Color{0xd4b4c4} }, // S6 OSM: 3937942 WD: Q680235 47.25, 11.1 x 47.49, 11.4
    { 1817, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x489224} }, // M1/M2 OSM: 3939086 WD: Q2094433 50.4, 4.271 x 50.42, 4.452
    { 1824, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x233e81} }, // TL OSM: 3939642 WD: Q2576140 19.26, -99.15 x 19.34, -99.11
    { 6, 11805, NoLogo, LineMetaDataContent::Subway, Color{0xc5003e} }, // 5 OSM: 3967180 WD: Q862888 23.1, 113.2 x 23.15, 113.5
    { 41, NoLogo, 11825, LineMetaDataContent::RapidTransit, Color{0xf07f3a} }, // S7 OSM: 4006931 WD: Q115689937 46.93, 7.438 x 46.98, 7.563
    { 1827, 11841, 5211, LineMetaDataContent::Tramway, Color{0xb1a245} }, // T8 OSM: 4007734 WD: Q3239029 48.93, 2.294 x 48.96, 2.358
    { 254, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x66ba86} }, // 23 OSM: 4016993 WD: Q2914455 51.88, 4.432 x 51.92, 4.574
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00bb00} }, // 1 OSM: 4037940 WD: Q105476776 51.31, 9.423 x 51.37, 9.502
    { 207, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa3429b} }, // TER T1 OSM: 4042689 WD: Q3239738 47.22, -1.549 x 47.72, -1.371
    { 272, 11874, NoLogo, LineMetaDataContent::Subway, Color{0x0000ff} }, // Blue OSM: 4086917 WD: Q152015 42.36, -71.06 x 42.41, -70.99
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x99b3be} }, // 3 OSM: 4089342 WD: Q56302770 46.94, 7.431 x 46.95, 7.441
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0089cf} }, // 6 OSM: 4089819 WD: Q56302772 46.93, 7.419 x 46.95, 7.563
    { 1830, 11901, 7105, LineMetaDataContent::Tramway, Color{0xa12944} }, // 97 OSM: 4092822 WD: Q1865502 50.8, 4.313 x 50.84, 4.357
    { 9, 11923, NoLogo, LineMetaDataContent::Tramway, Color{0x4a2a15} }, // 4 OSM: 4107687 WD: Q3238942 43.59, 3.872 x 43.62, 3.897
    { 54, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xee1d23} }, // 11 OSM: 4108299 WD: Q3239102 47.47, 7.573 x 47.58, 7.612
    { 1341, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // 100 OSM: 4117854 WD: Q3537097 39.1, -84.52 x 39.12, -84.51
    { 1198, 11933, 3887, LineMetaDataContent::Subway, Color{0x005ca5} }, // M3 OSM: 4121437 WD: Q692916 47.46, 19.05 x 47.56, 19.15
    { 8, 11949, 3887, LineMetaDataContent::Subway, Color{0x4ca22f} }, // M4 OSM: 4121438 WD: Q832651 47.46, 19.02 x 47.5, 19.08
    { 346, 11965, 3887, LineMetaDataContent::Subway, Color{0xe41f18} }, // M2 OSM: 4121439 WD: Q1071156 47.49, 19.02 x 47.51, 19.14
    { 6, 5882, NoLogo, LineMetaDataContent::Tramway, Color{0x78ccc9} }, // 5 OSM: 4152662 WD: Q63890965 50.48, 30.57 x 50.53, 30.63
    { 42, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xee1d23} }, // 7 OSM: 4152763 WD: Q56302771 46.94, 7.38 x 46.95, 7.472
    { 245, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 45 OSM: 4161955 55.73, 37.66 x 55.76, 37.7
    { 311, 11981, 6703, LineMetaDataContent::Subway, Color{0x008751} }, // C OSM: 4173958 WD: Q2261550 41.86, 12.51 x 41.89, 12.71
    { 434, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 43 OSM: 4179202 55.71, 37.66 x 55.79, 37.72
    { 55, 12022, NoLogo, LineMetaDataContent::Tramway, Color{0xf18700} }, // 1 OSM: 4222397 WD: Q108215311 50.96, 10.99 x 51.01, 11.04
    { 16, 12048, NoLogo, LineMetaDataContent::Tramway, Color{0xe3000b} }, // 2 OSM: 4222399 WD: Q108215316 50.95, 10.98 x 50.98, 11.07
    { 59, 12074, NoLogo, LineMetaDataContent::Tramway, Color{0x67095f} }, // 3 OSM: 4222400 WD: Q108215641 50.94, 10.99 x 51.01, 11.09
    { 9, 12100, NoLogo, LineMetaDataContent::Tramway, Color{0x007ac3} }, // 4 OSM: 4222401 WD: Q108215690 50.97, 10.96 x 51, 11.07
    { 6, 12126, NoLogo, LineMetaDataContent::Tramway, Color{0x00883c} }, // 5 OSM: 4222402 WD: Q108215699 50.97, 11.02 x 51.02, 11.04
    { 27, 12152, NoLogo, LineMetaDataContent::Tramway, Color{0x78ac28} }, // 6 OSM: 4222403 WD: Q108215015 50.96, 11 x 51.01, 11.04
    { 346, 12178, 3398, LineMetaDataContent::Subway, Color{0xff0000} }, // M2 OSM: 4232535 WD: Q3832673 52.23, 20.91 x 52.29, 21.06
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff7f00} }, // 1 OSM: 4234654 51.8, 12.24 x 51.84, 12.24
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x18683c} }, // 6 OSM: 4236150 52.4, 12.52 x 52.44, 12.57
    { 307, 12190, NoLogo, LineMetaDataContent::Subway, Color{0xffa500} }, // O OSM: 4250359 WD: Q6141590 24.99, 121.4 x 25.1, 121.5
    { 513, 12214, NoLogo, LineMetaDataContent::Subway, Color{0xcedc00} }, // G OSM: 4250382 WD: Q8044250 24.96, 121.5 x 25.05, 121.6
    { 1833, 12253, NoLogo, LineMetaDataContent::Subway, Color{0xa74c00} }, // BR OSM: 4264893 WD: Q707644 25, 121.5 x 25.09, 121.6
    { 1836, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x8b231d} }, // SFM 6 OSM: 4277114 WD: Q15077697 44.88, 7.654 x 45.12, 8.209
    { 1842, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // C11 OSM: 4287063 50.71, 12.77 x 50.84, 12.93
    { 44, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf49694} }, // S5 OSM: 4292646 48.89, 8.243 x 49.06, 8.705
    { 16, 12278, NoLogo, LineMetaDataContent::Subway, Color{0x028f34} }, // 2 OSM: 4292976 WD: Q2333639 -22.95, -43.37 x -22.81, -43.17
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xbb0022} }, // 1 OSM: 4307991 WD: Q972127 51.02, 3.692 x 51.11, 3.723
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x229922} }, // 4 OSM: 4307994 WD: Q1984797 51.02, 3.71 x 51.07, 3.742
    { 1846, 12297, NoLogo, LineMetaDataContent::LongDistanceTrain, Color{0x009bdf} }, // IC 8 OSM: 4421943 WD: Q115932389 46.29, 7.437 x 47.59, 9.38
    { 1851, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x00a6eb} }, // S19 OSM: 4434302 WD: Q30597732 50.76, 6.482 x 50.95, 7.66
    { 260, 12311, 226, LineMetaDataContent::RapidTransit, Color{0xf78a18} }, // S51 OSM: 4435864 WD: Q63433457 52.1, 9.374 x 52.4, 9.773
    { 1855, 12328, 226, LineMetaDataContent::RapidTransit, Color{0x118349} }, // S21 OSM: 4435868 WD: Q63433451 52.28, 9.466 x 52.38, 9.773
    { 284, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xcc0000} }, // Red OSM: 4439533 WD: Q7304502 33.64, -84.45 x 33.95, -84.34
    { 1859, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xf67705} }, // Gold OSM: 4439534 WD: Q5578774 33.64, -84.45 x 33.9, -84.28
    { 480, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x009544} }, // Green OSM: 4439535 WD: Q5602819 33.75, -84.43 x 33.78, -84.28
    { 272, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0274ba} }, // Blue OSM: 4439536 WD: Q4929368 33.75, -84.47 x 33.78, -84.23
    { 65, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x114283} }, // 10 OSM: 4443860 54.27, 48.29 x 54.32, 48.39
    { 218, NoLogo, 12345, LineMetaDataContent::RapidTransit, Color{0x903f98} }, // S4 OSM: 4452991 WD: Q106368752 47.62, 12.87 x 47.84, 13
    { 47, 12365, 226, LineMetaDataContent::RapidTransit, Color{0x8ec7e8} }, // S8 OSM: 4470844 WD: Q63433462 52.32, 9.687 x 52.46, 9.792
    { 1864, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7b388c} }, // Providence/Stoughton Line OSM: 4473913 WD: Q7252371 41.58, -71.49 x 42.35, -71.06
    { 1890, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7b388c} }, // Franklin Line OSM: 4476404 WD: Q5491659 42.08, -71.44 x 42.35, -71.05
    { 139, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x5a1e82} }, // 14 OSM: 4489019 WD: Q3238565 46.17, 6.06 x 46.24, 6.144
    { 22, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xb82f89} }, // 18 OSM: 4489020 WD: Q3238636 46.17, 6.055 x 46.23, 6.144
    { 143, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x84471c} }, // 15 OSM: 4489138 WD: Q3238583 46.18, 6.12 x 46.22, 6.149
    { 55, 12381, NoLogo, LineMetaDataContent::Subway, Color{0x008000} }, // 1 OSM: 4494027 WD: Q10914047 24.11, 120.6 x 24.19, 120.7
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 4 OSM: 4494871 WD: Q2105648 52.34, 4.889 x 52.38, 4.905
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xab10d2} }, // 12 OSM: 4495366 WD: Q14500288 52.35, 4.879 x 52.38, 4.919
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffbf00} }, // 1 OSM: 4497227 WD: Q2663350 52.35, 4.775 x 52.36, 4.934
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffbf00} }, // 2 OSM: 4497722 WD: Q2033321 52.34, 4.804 x 52.38, 4.899
    { 1904, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x87ceeb} }, // TRAB OSM: 4497962 WD: Q2829306 33.37, -7.672 x 33.61, -7.554
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xab10d2} }, // 3 OSM: 4498754 WD: Q2051638 52.35, 4.87 x 52.38, 4.952
    { 1909, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffcd28} }, // Z70 OSM: 4498934 WD: Q109333261 47.51, 18.86 x 47.83, 19.16
    { 1913, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xb0c4de} }, // PST OSM: 4499555 33.43, -112 x 33.45, -112
    { 1917, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00aff0} }, // S70 OSM: 4500998 WD: Q109333249 47.51, 18.86 x 47.83, 19.16
    { 1921, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00aff0} }, // S71 OSM: 4500999 WD: Q109333250 47.51, 19.06 x 47.78, 19.3
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffbf00} }, // 5 OSM: 4501532 WD: Q2343376 52.3, 4.867 x 52.38, 4.884
    { 1925, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x006983} }, // Montauk OSM: 4501572 WD: Q4044495 40.7, -73.99 x 41.05, -71.95
    { 42, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff7f00} }, // 7 OSM: 4502267 WD: Q4405692 52.36, 4.818 x 52.38, 4.94
    { 147, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 19 OSM: 4507967 WD: Q2402279 52.34, 4.838 x 52.39, 4.971
    { 182, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00aff0} }, // S50 OSM: 4508158 WD: Q104161828 47.17, 19.06 x 47.52, 20.18
    { 1933, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00985f} }, // Babylon OSM: 4509487 WD: Q4838506 40.66, -73.99 x 40.75, -73.33
    { 1941, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // VLT Cabo - Cajueiro Seco OSM: 4510254 WD: Q18473915 -8.287, -35.04 x -8.168, -34.93
    { 58, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xab10d2} }, // 13 OSM: 4512711 WD: Q2157983 52.37, 4.803 x 52.38, 4.899
    { 139, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00ff00} }, // 14 OSM: 4513498 WD: Q2108285 52.36, 4.892 x 52.38, 4.952
    { 191, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf49ac1} }, // 24 OSM: 4513900 WD: Q2651682 52.34, 4.857 x 52.38, 4.902
    { 179, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x007fff} }, // 17 OSM: 4514442 WD: Q2400889 52.36, 4.786 x 52.38, 4.899
    { 1031, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xd59758} }, // 26 OSM: 4514564 WD: Q2503173 52.35, 4.898 x 52.38, 5.005
    { 183, 12416, 12460, LineMetaDataContent::Subway, Color{0x29ab4d} }, // 50 OSM: 4515358 WD: Q2466111 52.29, 4.834 x 52.4, 4.99
    { 261, NoLogo, 12460, LineMetaDataContent::Subway, Color{0xf69931} }, // 51 OSM: 4515359 WD: Q606629 52.33, 4.834 x 52.4, 4.924
    { 1967, 12485, 12460, LineMetaDataContent::Subway, Color{0xfcfb05} }, // 54 OSM: 4515360 WD: Q2183200 52.29, 4.9 x 52.38, 4.99
    { 1470, 12529, 12460, LineMetaDataContent::Subway, Color{0xff0000} }, // 53 OSM: 4515361 WD: Q2163442 52.31, 4.9 x 52.38, 4.985
    { 1855, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00aff0} }, // S21 OSM: 4517111 WD: Q101148856 46.89, 19.06 x 47.52, 19.71
    { 1970, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00aff0} }, // S210 OSM: 4522098 WD: Q109333255 46.89, 19.48 x 47.1, 19.71
    { 1975, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffcd28} }, // Z50 OSM: 4537671 WD: Q104170252 47.17, 19.06 x 47.52, 20.18
    { 966, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00aff0} }, // S10 OSM: 4543849 WD: Q103726127 47.45, 17.64 x 47.75, 19.03
    { 1979, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffcd28} }, // Z30 OSM: 4546118 WD: Q109333259 47.17, 18.42 x 47.5, 19.04
    { 1983, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffa500} }, // NS OSM: 4566683 45.49, -122.7 x 45.53, -122.7
    { 1986, 12573, 12600, LineMetaDataContent::Subway, Color{0x1e59ae} }, // m2 OSM: 4621397 WD: Q3239144 46.51, 6.626 x 46.54, 6.662
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x94c11a} }, // 2 OSM: 4622863 52.23, 10.52 x 52.29, 10.54
    { 42, 12625, 3795, LineMetaDataContent::Subway, Color{0xffc66e} }, // 7 OSM: 4624900 WD: Q6553149 39.85, 116.3 x 39.89, 116.7
    { 139, 12645, 3795, LineMetaDataContent::Subway, Color{0xd4a7a1} }, // 14 OSM: 4624915 WD: Q6553070 39.86, 116.2 x 40.03, 116.5
    { 27, 12666, 3795, LineMetaDataContent::Subway, Color{0xbb8900} }, // 6 OSM: 4625142 WD: Q6553138 39.9, 116.2 x 39.93, 116.7
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xec008c} }, // 1 OSM: 4628650 47.15, 27.56 x 47.19, 27.63
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00a650} }, // 3 OSM: 4629075 47.15, 27.57 x 47.17, 27.66
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf9c0c1} }, // 6 OSM: 4631231 47.16, 27.54 x 47.17, 27.59
    { 42, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x2e3092} }, // 7 OSM: 4631274 47.14, 27.54 x 47.17, 27.64
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xd2e288} }, // 8 OSM: 4631290 47.14, 27.56 x 47.19, 27.64
    { 107, 12686, 1095, LineMetaDataContent::Subway, Color{0xb8282e} }, // U1 OSM: 4656730 WD: Q198432 50.1, 8.634 x 50.17, 8.688
    { 113, 12703, 1095, LineMetaDataContent::Subway, Color{0x4a5eaa} }, // U3 OSM: 4656731 WD: Q19862991 50.1, 8.537 x 50.22, 8.688
    { 116, 12720, 1095, LineMetaDataContent::Subway, Color{0xf172ac} }, // U4 OSM: 4656732 WD: Q19862998 50.11, 8.652 x 50.14, 8.755
    { 119, 12737, 1095, LineMetaDataContent::Subway, Color{0x007942} }, // U5 OSM: 4656733 WD: Q3040872 50.11, 8.662 x 50.16, 8.692
    { 125, 12754, 1095, LineMetaDataContent::Subway, Color{0xe4a023} }, // U7 OSM: 4656734 WD: Q3040904 50.11, 8.608 x 50.14, 8.755
    { 128, 12771, 1095, LineMetaDataContent::Subway, Color{0xc77db5} }, // U8 OSM: 4656735 WD: Q3063407 50.1, 8.621 x 50.18, 8.688
    { 131, 12788, 1095, LineMetaDataContent::Subway, Color{0xeed700} }, // U9 OSM: 4656736 WD: Q19862984 50.14, 8.621 x 50.2, 8.674
    { 1787, 12805, 12812, LineMetaDataContent::Tramway, Color{0x008176} }, // T4 OSM: 4665787 WD: Q49368235 41.39, 2.187 x 41.42, 2.231
    { 1989, 12836, 12812, LineMetaDataContent::Tramway, Color{0x008176} }, // T6 OSM: 4665788 WD: Q49375135 41.4, 2.187 x 41.42, 2.231
    { 1527, 12843, 12812, LineMetaDataContent::Tramway, Color{0x008176} }, // T5 OSM: 4665789 WD: Q49394264 41.4, 2.187 x 41.44, 2.233
    { 1767, 12865, 12812, LineMetaDataContent::Tramway, Color{0x008176} }, // T3 OSM: 4667001 WD: Q49770929 41.37, 2.053 x 41.39, 2.143
    { 211, 7842, 12812, LineMetaDataContent::Tramway, Color{0x008176} }, // T1 OSM: 4667002 WD: Q49770336 41.36, 2.058 x 41.39, 2.143
    { 537, 7799, 12812, LineMetaDataContent::Tramway, Color{0x008176} }, // T2 OSM: 4667003 WD: Q49770664 41.36, 2.058 x 41.39, 2.143
    { 393, 12872, 12889, LineMetaDataContent::Subway, Color{0x992f9c} }, // L2 OSM: 4671269 WD: Q1348921 41.38, 2.163 x 41.45, 2.244
    { 385, 12914, 12889, LineMetaDataContent::Subway, Color{0xfab70a} }, // L4 OSM: 4671321 WD: Q961384 41.38, 2.163 x 41.45, 2.218
    { 1238, 12931, 12889, LineMetaDataContent::Subway, Color{0x317bc8} }, // L5 OSM: 4673514 WD: Q1348939 41.36, 2.07 x 41.43, 2.187
    { 1992, 12948, 12889, LineMetaDataContent::Subway, Color{0x00adef} }, // L10 Nord OSM: 4673515 WD: Q1785338 41.42, 2.186 x 41.44, 2.234
    { 397, 12966, 12889, LineMetaDataContent::Subway, Color{0x39af57} }, // L3 OSM: 4673516 WD: Q385168 41.37, 2.11 x 41.45, 2.188
    { 1250, 12983, 12889, LineMetaDataContent::Subway, Color{0xd5578f} }, // L8 OSM: 4673517 WD: Q763319 41.35, 2.035 x 41.37, 2.149
    { 1246, 13000, 12889, LineMetaDataContent::Subway, Color{0xac5414} }, // L7 OSM: 4673518 WD: Q678390 41.39, 2.137 x 41.41, 2.169
    { 389, 13017, 12889, LineMetaDataContent::Subway, Color{0xe33638} }, // L1 OSM: 4673519 WD: Q1348946 41.34, 2.099 x 41.45, 2.218
    { 2001, 13034, 12889, LineMetaDataContent::Subway, Color{0x9ed74c} }, // L11 OSM: 4673520 WD: Q1419762 41.45, 2.173 x 41.46, 2.186
    { 1242, 13052, 12889, LineMetaDataContent::Subway, Color{0x7280c0} }, // L6 OSM: 4673521 WD: Q1577019 41.39, 2.125 x 41.4, 2.169
    { 2005, 13069, 12889, LineMetaDataContent::Subway, Color{0xf6842a} }, // L9 Nord OSM: 4673522 WD: Q1577033 41.42, 2.186 x 41.46, 2.22
    { 1205, 13086, NoLogo, LineMetaDataContent::LocalTrain, Color{0xfdda24} }, // 86966 OSM: 4684542 WD: Q205585 42.42, 2.866 x 43.94, 4.805
    { 2013, 13086, NoLogo, LineMetaDataContent::LocalTrain, Color{0xfdda24} }, // 86990 OSM: 4684543 WD: Q205585 42.42, 2.866 x 43.19, 3.168
    { 1855, 13099, 226, LineMetaDataContent::RapidTransit, Color{0xa70f47} }, // S21 OSM: 4708731 WD: Q19368759 53.49, 9.893 x 53.6, 10.32
    { 55, 13115, NoLogo, LineMetaDataContent::Tramway, Color{0xe30e68} }, // 1 OSM: 4748602 WD: Q117280796 52.38, 16.83 x 52.4, 17
    { 16, 13153, NoLogo, LineMetaDataContent::Tramway, Color{0x70c9e8} }, // 2 OSM: 4750038 WD: Q108006450 52.37, 16.88 x 52.42, 16.92
    { 2019, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x800080} }, // Tren Urbano OSM: 4751620 WD: Q1577126 18.39, -66.15 x 18.44, -66.05
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x84254b} }, // 3 OSM: 4756145 52.39, 16.85 x 52.46, 16.95
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x7dc833} }, // 5 OSM: 4763766 52.37, 16.88 x 52.4, 16.96
    { 2031, 13191, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe67310} }, // A2 OSM: 4785912 WD: Q19582807 53.71, 9.966 x 53.83, 9.993
    { 2034, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x004d9f} }, // Tide OSM: 4788761 WD: Q646388 36.84, -76.3 x 36.86, -76.19
    { 2039, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xec1c24} }, // 703 OSM: 4789075 WD: Q7304509 40.54, -112 x 40.77, -111.8
    { 2043, NoLogo, 4539, LineMetaDataContent::RapidTransit, Color{0xbdbadc} }, // Penn OSM: 4799477 WD: Q7163197 38.9, -77.01 x 39.56, -76.07
    { 19, 11024, NoLogo, LineMetaDataContent::Tramway, Color{0xff80c0} }, // 8 OSM: 4828592 WD: Q1962342 51.21, 4.42 x 51.22, 4.492
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008080} }, // 3 OSM: 5143295 49.2, 16.52 x 49.23, 16.64
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffa500} }, // 4 OSM: 5151976 49.19, 16.58 x 49.23, 16.65
    { 211, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00a5c1} }, // T1 OSM: 5157502 WD: Q16011470 47.22, 5.951 x 47.26, 6.061
    { 2, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0d7b49} }, // 0 OSM: 5175545 52.39, 16.89 x 52.41, 16.92
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe4002c} }, // 1 OSM: 5185991 51, 13.67 x 51.06, 13.82
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xeb5b2d} }, // 2 OSM: 5186008 51.01, 13.65 x 51.06, 13.85
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc9061a} }, // 4 OSM: 5186035 51.02, 13.56 x 51.16, 13.84
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffdd00} }, // 6 OSM: 5186067 51, 13.68 x 51.06, 13.84
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x229133} }, // 8 OSM: 5186073 51.03, 13.72 x 51.12, 13.77
    { 132, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x93c355} }, // 9 OSM: 5186435 51, 13.69 x 51.08, 13.8
    { 65, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf9b000} }, // 10 OSM: 5186677 51.04, 13.71 x 51.07, 13.81
    { 54, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc2ddaf} }, // 11 OSM: 5186681 51.02, 13.73 x 51.07, 13.86
    { 58, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfdc300} }, // 13 OSM: 5186751 51, 13.69 x 51.08, 13.8
    { 982, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00aff0} }, // S12 OSM: 5189449 WD: Q103770328 47.45, 18.31 x 47.59, 19.03
    { 2048, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00aff0} }, // S150 OSM: 5189451 WD: Q101110277 47.18, 18.01 x 47.75, 18.42
    { 2053, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xaacd46} }, // G30 OSM: 5189583 WD: Q104161605 47.17, 18.43 x 47.5, 19.04
    { 2057, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00aff0} }, // S820 OSM: 5189587 WD: Q109333257 47.17, 19.67 x 47.66, 20.18
    { 995, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00aff0} }, // S42 OSM: 5189590 WD: Q112963134 46.96, 18.76 x 47.5, 19.04
    { 2062, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xaacd46} }, // G10 OSM: 5189591 WD: Q103834888 47.45, 17.64 x 47.75, 19.12
    { 162, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00aff0} }, // S60 OSM: 5189593 WD: Q109333246 47.17, 19.08 x 47.5, 20.18
    { 2066, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00aff0} }, // S30 OSM: 5189595 WD: Q101095853 46.75, 17.56 x 47.5, 19.04
    { 2070, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00aff0} }, // S220 OSM: 5189596 WD: Q112963797 46.85, 19.7 x 47.18, 20.18
    { 2075, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xaacd46} }, // G71 OSM: 5189597 WD: Q109333268 47.51, 19.06 x 47.78, 19.3
    { 2079, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xaacd46} }, // G70 OSM: 5189600 WD: Q109333266 47.51, 18.86 x 47.83, 19.16
    { 2083, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xaacd46} }, // G60 OSM: 5189601 WD: Q101147966 47.17, 19.08 x 47.5, 20.18
    { 2087, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xaacd46} }, // G43 OSM: 5189602 WD: Q109333264 47.17, 18.42 x 47.48, 19.35
    { 2091, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00aff0} }, // S80 OSM: 5189603 WD: Q101142569 47.49, 19.08 x 47.75, 20.42
    { 1211, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00aff0} }, // S20 OSM: 5189604 WD: Q103835740 46.23, 19.06 x 47.52, 20.14
    { 2095, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00aff0} }, // S40 OSM: 5189605 WD: Q112963108 46.37, 18.15 x 47.5, 19.04
    { 1192, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00aff0} }, // S36 OSM: 5189606 WD: Q109333242 47.25, 18.69 x 47.48, 19.35
    { 2099, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00aff0} }, // S35 OSM: 5189607 WD: Q109333241 46.44, 16.99 x 47.5, 19.04
    { 2103, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00aff0} }, // S34 OSM: 5189609 WD: Q104433012 46.69, 17.24 x 47.5, 19.04
    { 2107, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffcd28} }, // Z60 OSM: 5189611 WD: Q101147976 47.17, 19.08 x 47.5, 20.18
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xd52330} }, // 1 OSM: 5209167 50.93, 6.816 x 50.96, 7.162
    { 962, 13206, 13232, LineMetaDataContent::RapidTransit, Color{0xf26021} }, // S32 OSM: 5219521 WD: Q87069535 51.08, 4.283 x 51.54, 4.467
    { 42, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe6855c} }, // 7 OSM: 5231292 50.87, 6.797 x 50.94, 7.06
    { 41, NoLogo, 9093, LineMetaDataContent::RapidTransit, Color{0x159dd9} }, // S7 OSM: 5248498 WD: Q17101554 48.1, 16.38 x 48.57, 17.01
    { 162, 13254, 9093, LineMetaDataContent::RapidTransit, Color{0x159dd9} }, // S60 OSM: 5248503 WD: Q96483899 47.81, 16.23 x 48.19, 16.78
    { 182, 13267, 9093, LineMetaDataContent::RapidTransit, Color{0x159dd9} }, // S50 OSM: 5248504 WD: Q96483895 48.17, 15.89 x 48.21, 16.34
    { 2091, 13280, 9093, LineMetaDataContent::RapidTransit, Color{0x159dd9} }, // S80 OSM: 5248538 WD: Q96483911 48.17, 16.26 x 48.23, 16.51
    { 244, NoLogo, 9093, LineMetaDataContent::RapidTransit, Color{0xbdd542} }, // S45 OSM: 5248540 WD: Q17101545 48.19, 16.26 x 48.26, 16.39
    { 2095, 13293, 9093, LineMetaDataContent::RapidTransit, Color{0x159dd9} }, // S40 OSM: 5248548 WD: Q96483953 48.21, 15.62 x 48.35, 16.37
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // 1 OSM: 5252357 WD: Q1548435 39.22, 9.125 x 39.27, 9.143
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xeb4690} }, // 1 OSM: 5293755 33.98, -6.865 x 34.05, -6.794
    { 1767, 12850, 7806, LineMetaDataContent::Tramway, Color{0x96be0d} }, // T3 OSM: 5296539 WD: Q3238910 43.29, 5.367 x 43.32, 5.384
    { 134, 599, NoLogo, LineMetaDataContent::Subway, Color{0x152a92} }, // U11 OSM: 5311905 WD: Q203252 51.42, 6.992 x 51.54, 7.026
    { 2111, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x59bee6} }, // U17 OSM: 5312041 51.43, 6.973 x 51.5, 7.013
    { 2115, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x008fd3} }, // U18 OSM: 5312153 51.43, 6.886 x 51.46, 7.013
    { 2120, 13306, NoLogo, LineMetaDataContent::Subway, Color{0x02ac39} }, // TR OSM: 5326658 WD: Q843148 35.7, 140 x 35.73, 140.1
    { 132, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8a2be2} }, // 9 OSM: 5329880 49.19, 16.61 x 49.23, 16.65
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x221815} }, // 6 OSM: 5335066 WD: Q957721 33.84, 132.8 x 33.85, 132.8
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x036eb8} }, // 5 OSM: 5335067 33.84, 132.8 x 33.85, 132.8
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe60012} }, // 3 OSM: 5335068 33.84, 132.8 x 33.85, 132.8
    { 2123, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0066cc} }, // TDV OSM: 5371521 WD: Q23951292 -38.96, -68.23 x -38.96, -68.06
    { 2127, 13335, NoLogo, LineMetaDataContent::RapidTransit, Color{0x8b039b} }, // C-3 OSM: 5382815 WD: Q8879464 40.03, -4.271 x 40.63, -3.608
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x662584} }, // 2 OSM: 5391128 33.99, -6.872 x 34.04, -6.752
    { 50, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7e971e} }, // S2 OSM: 5405975 WD: Q2316170 41.39, 2.068 x 41.57, 2.169
    { 249, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf9b000} }, // 20 OSM: 5421483 51.04, 13.71 x 51.07, 13.74
    { 55, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x000080} }, // 1 OSM: 5465576 WD: Q10318641 -30.03, -51.23 x -29.69, -51.13
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 1 OSM: 5490398 41.66, 123.4 x 41.74, 123.5
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 3 OSM: 5490400 41.65, 123.4 x 41.72, 123.5
    { 211, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // T1 OSM: 5510640 WD: Q113671848 45.44, 12.25 x 45.51, 12.32
    { 55, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x3dae2b} }, // 1 OSM: 5517061 WD: Q1067251 47.42, -122.3 x 47.7, -122.3
    { 1334, NoLogo, 2228, LineMetaDataContent::RapidTransit, Color{0xffa500} }, // Orange OSM: 5543450 WD: Q6714620 45.43, -122.7 x 45.53, -122.6
    { 196, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0088ab} }, // B OSM: 5575252 45.5, -122.7 x 45.54, -122.7
    { 2125, 13353, 13353, LineMetaDataContent::RapidTransit, Color{0xe5554f} }, // V OSM: 5576487 WD: Q11152362 25.15, 121.4 x 25.2, 121.5
    { 1297, 13395, NoLogo, LineMetaDataContent::LocalTrain, Color{} }, // RE5 OSM: 5577109 WD: Q64223427 53.45, 8.704 x 53.86, 10.03
    { 311, 13411, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7cbd52} }, // C OSM: 5593997 WD: Q4121246 22.59, 120.3 x 22.66, 120.3
    { 2131, 13453, NoLogo, LineMetaDataContent::RapidTransit, Color{0x78be20} }, // Π3 OSM: 5596928 WD: Q47477355 37.99, 23.57 x 38.46, 23.87
    { 53, 13488, 226, LineMetaDataContent::RapidTransit, Color{0x44a325} }, // S11 OSM: 5607596 WD: Q19368865 53.55, 9.814 x 53.65, 10.09
    { 50, 13504, 226, LineMetaDataContent::RapidTransit, Color{0xa70f47} }, // S2 OSM: 5607597 WD: Q19390036 53.49, 9.934 x 53.56, 10.21
    { 166, 13519, 226, LineMetaDataContent::RapidTransit, Color{0x5d1d81} }, // S3 OSM: 5607598 WD: Q19368685 53.46, 9.477 x 53.66, 10.03
    { 2135, 13534, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe79500} }, // A1 OSM: 5610369 WD: Q19368804 53.55, 9.889 x 54.08, 10.02
    { 16, 13549, NoLogo, LineMetaDataContent::Subway, Color{0xe70095} }, // 2 OSM: 5616937 WD: Q3832658 39.43, -0.5963 x 39.62, -0.3815
    { 132, 13580, NoLogo, LineMetaDataContent::Subway, Color{0xb7814f} }, // 9 OSM: 5622181 WD: Q18613779 39.47, -0.5603 x 39.54, -0.3521
    { 42, 13611, NoLogo, LineMetaDataContent::Subway, Color{0xf28c00} }, // 7 OSM: 5626070 WD: Q11690011 39.43, -0.4726 x 39.47, -0.3383
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xd75128} }, // 3 OSM: 5646916 50.69, 12.46 x 50.74, 12.53
    { 72, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffa500} }, // 21 OSM: 5664427 WD: Q1632888 52.01, 5.028 x 52.09, 5.184
    { 54, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf05b72} }, // 11 OSM: 5668462 47.15, 27.54 x 47.17, 27.63
    { 58, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00adef} }, // 13 OSM: 5668463 47.15, 27.56 x 47.19, 27.63
    { 2138, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // E-W OSM: 5697658 WD: Q53778901 9.01, 38.72 x 9.022, 38.87
    { 2142, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // S-N OSM: 5697659 WD: Q53779001 8.936, 38.73 x 9.039, 38.77
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x66cc00} }, // 2 OSM: 5711071 WD: Q56911095 36.28, 59.55 x 36.33, 59.68
    { 537, 13642, 5054, LineMetaDataContent::Tramway, Color{0x0098d4} }, // T2 OSM: 5720061 WD: Q16655787 43.59, 1.374 x 43.63, 1.446
    { 166, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x36a390} }, // S3 OSM: 5721287 41.35, 2.005 x 41.4, 2.149
    { 218, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa25e23} }, // S4 OSM: 5721688 41.35, 1.888 x 41.54, 2.149
    { 2146, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xb8b6b7} }, // R6 OSM: 5724702 41.35, 1.63 x 41.58, 2.149
    { 2149, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x707072} }, // R60 OSM: 5724705 41.35, 1.63 x 41.58, 2.149
    { 2153, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x38b0b1} }, // R5 OSM: 5724850 41.35, 1.828 x 41.73, 2.149
    { 2156, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x3592a3} }, // R50 OSM: 5724851 41.35, 1.828 x 41.73, 2.149
    { 179, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x6dcff6} }, // 17 OSM: 5740169 50.86, 6.957 x 50.93, 7.004
    { 26, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x21bfc1} }, // 16 OSM: 5742444 50.68, 6.943 x 50.99, 7.159
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe06e9f} }, // 4 OSM: 5742445 50.93, 6.873 x 51.02, 7.044
    { 179, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x286290} }, // 17 OSM: 5742856 52.41, 16.88 x 52.42, 16.96
    { 58, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc88922} }, // 13 OSM: 5744834 52.37, 16.93 x 52.41, 16.95
    { 143, 13670, NoLogo, LineMetaDataContent::Tramway, Color{0x8d98a2} }, // 15 OSM: 5745673 WD: Q110074597 52.39, 16.85 x 52.46, 16.92
    { 2160, NoLogo, 599, LineMetaDataContent::Subway, Color{0x59c6f2} }, // U71 OSM: 5747258 WD: Q87660333 51.16, 6.775 x 51.26, 6.886
    { 2164, 599, NoLogo, LineMetaDataContent::Subway, Color{0x1d3a8f} }, // U83 OSM: 5748738 WD: Q661002 51.16, 6.775 x 51.25, 6.886
    { 65, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf2b023} }, // 10 OSM: 5752352 WD: Q108006469 52.37, 16.9 x 52.46, 16.95
    { 2168, 599, NoLogo, LineMetaDataContent::Subway, Color{0x4465ad} }, // U73 OSM: 5756097 WD: Q661002 51.19, 6.775 x 51.24, 6.867
    { 150, 599, NoLogo, LineMetaDataContent::Subway, Color{0x25b8c5} }, // U72 OSM: 5756147 WD: Q661002 51.19, 6.762 x 51.3, 6.847
    { 2172, 13709, NoLogo, LineMetaDataContent::RapidTransit, Color{0x006434} }, // R2Sud OSM: 5758580 WD: Q1880046 41.19, 1.523 x 41.4, 2.194
    { 2178, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff6600} }, // HVL OSM: 5793083 -41.28, 174.8 x -41.13, 175.1
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xa4107f} }, // 4 OSM: 5804724 WD: Q3476269 51.91, 4.432 x 51.96, 4.504
    { 389, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x800080} }, // L1 OSM: 5812905 WD: Q95982832 38.09, 13.37 x 38.11, 13.41
    { 393, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffa500} }, // L2 OSM: 5812931 WD: Q95983858 38.13, 13.29 x 38.13, 13.34
    { 385, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // L4 OSM: 5813038 WD: Q95983909 38.1, 13.33 x 38.13, 13.34
    { 397, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // L3 OSM: 5813039 WD: Q95983869 38.13, 13.3 x 38.14, 13.34
    { 65, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x4b371b} }, // 10 OSM: 5821632 WD: Q117011248 54.35, 18.57 x 54.4, 18.67
    { 2182, NoLogo, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 47B OSM: 5830635 WD: Q22696462 47.44, 18.98 x 47.5, 19.06
    { 2186, 13709, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00a85a} }, // R2 OSM: 5838299 WD: Q1880046 41.28, 1.978 x 41.6, 2.292
    { 2189, 13726, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff131a} }, // R3 OSM: 5844031 WD: Q2113761 41.36, 1.896 x 42.46, 2.297
    { 2192, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffbacd} }, // U49 OSM: 5847183 51.48, 7.442 x 51.52, 7.476
    { 2196, 13743, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff8c00} }, // R4 OSM: 5849061 WD: Q2226508 41.19, 1.524 x 41.72, 2.189
    { 2199, 13760, NoLogo, LineMetaDataContent::RapidTransit, Color{0x9b1987} }, // R8 OSM: 5866129 WD: Q3817638 41.45, 1.926 x 41.6, 2.292
    { 2204, 13777, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00bdac} }, // RT1 OSM: 5866193 WD: Q5985874 41.11, 1.098 x 41.16, 1.255
    { 2208, 13795, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe579cb} }, // RT2 OSM: 5867875 WD: Q9025898 41, 0.9109 x 41.27, 1.6
    { 2212, 13813, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0073ce} }, // RG1 OSM: 5867923 WD: Q5985872 41.36, 2.099 x 42.42, 3.161
    { 2216, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0060a9} }, // Expo Line OSM: 5881298 WD: Q736619 49.18, -123.1 x 49.29, -122.8
    { 2226, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xffd520} }, // Millennium Line OSM: 5881419 WD: Q1534900 49.25, -123.1 x 49.29, -122.8
    { 2242, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x009ac8} }, // Canada Line OSM: 5881439 WD: Q1031997 49.17, -123.2 x 49.29, -123.1
    { 2254, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfbba00} }, // U42 OSM: 5890483 51.47, 7.433 x 51.56, 7.547
    { 2258, 13828, 599, LineMetaDataContent::Tramway, Color{0xdc2a1b} }, // U45 OSM: 5892934 WD: Q107740406 51.49, 7.455 x 51.54, 7.475
    { 2262, 13842, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffdd00} }, // R12 OSM: 5927786 WD: Q9026146 41.36, 0.6331 x 41.75, 2.189
    { 363, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x1e9999} }, // E OSM: 5953002 WD: Q5324790 37.78, -122.4 x 37.81, -122.4
    { 326, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf4858d} }, // 614P OSM: 5955260 WD: Q15903043 22.37, 114 x 22.41, 114
    { 2266, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x006684} }, // 615P OSM: 5955261 WD: Q15903207 22.37, 114 x 22.41, 114
    { 524, 13872, 13891, LineMetaDataContent::Subway, Color{0x00aa50} }, // A OSM: 5955845 WD: Q2310450 51.9, 4.314 x 51.96, 4.566
    { 196, NoLogo, 13891, LineMetaDataContent::Subway, Color{0xffd301} }, // B OSM: 5955846 WD: Q2960661 51.9, 4.105 x 51.99, 4.587
    { 311, NoLogo, 13891, LineMetaDataContent::Subway, Color{0xef1f1f} }, // C OSM: 5955847 WD: Q2058778 51.83, 4.319 x 51.94, 4.601
    { 1028, NoLogo, 13891, LineMetaDataContent::Subway, Color{0x1bc5e9} }, // D OSM: 5955848 WD: Q2034685 51.83, 4.319 x 51.92, 4.497
    { 363, NoLogo, 13916, LineMetaDataContent::Subway, Color{0x1a389a} }, // E OSM: 5955849 WD: Q2687418 51.87, 4.325 x 52.08, 4.497
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x90130c} }, // 2 OSM: 5955850 WD: Q1982139 51.88, 4.464 x 51.9, 4.554
    { 249, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfbb316} }, // 20 OSM: 5966563 WD: Q3118970 51.88, 4.471 x 51.92, 4.539
    { 42, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x97d700} }, // 7 OSM: 5971692 WD: Q6553152 22.93, 113.2 x 23.05, 113.4
    { 2271, 13069, 12889, LineMetaDataContent::Subway, Color{0xf6842a} }, // L9 Sud OSM: 5972747 WD: Q1577033 41.29, 2.055 x 41.38, 2.134
    { 2278, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // NL1 OSM: 5976635 48.98, 8.362 x 49.05, 8.479
    { 2282, 13938, NoLogo, LineMetaDataContent::RapidTransit, Color{0x002369} }, // R11 OSM: 6021945 WD: Q11050690 41.38, 2.139 x 42.43, 3.161
    { 2286, 13968, NoLogo, LineMetaDataContent::RapidTransit, Color{0xed3896} }, // R13 OSM: 6025765 WD: Q6018166 41.18, 0.6331 x 41.62, 2.194
    { 2290, 13998, NoLogo, LineMetaDataContent::RapidTransit, Color{0x4e53ab} }, // R14 OSM: 6028425 WD: Q2880157 41.11, 0.6331 x 41.62, 2.194
    { 2294, 14028, NoLogo, LineMetaDataContent::RapidTransit, Color{0x9a836c} }, // R15 OSM: 6028724 WD: Q5845244 41.09, 0.4797 x 41.4, 2.194
    { 2104, 14058, NoLogo, LineMetaDataContent::RapidTransit, Color{0x94288e} }, // 34 OSM: 6028756 WD: Q9025916 41.09, -0.9102 x 41.66, 2.194
    { 2298, 14083, NoLogo, LineMetaDataContent::LocalTrain, Color{0x009641} }, // RE6 OSM: 6059535 WD: Q63438537 53.55, 8.31 x 54.91, 9.936
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // 5 OSM: 6059624 41.74, 123.5 x 41.81, 123.7
    { 179, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x4d3d00} }, // 17 OSM: 6061801 49.01, 8.359 x 49.05, 8.452
    { 26, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffaaaa} }, // 16 OSM: 6061802 48.99, 8.378 x 49.05, 8.452
    { 22, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00805a} }, // 18 OSM: 6061803 49, 8.431 x 49.05, 8.479
    { 363, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // E OSM: 6062533 48.95, 8.283 x 49.11, 8.505
    { 1028, 14099, 14126, LineMetaDataContent::RapidTransit, Color{0xf9c212} }, // D OSM: 6063097 WD: Q10318679 41.11, -8.611 x 41.18, -8.598
    { 363, 14147, 14126, LineMetaDataContent::RapidTransit, Color{0x937bb8} }, // E OSM: 6063237 WD: Q10318682 41.15, -8.67 x 41.24, -8.582
    { 238, 14174, 14126, LineMetaDataContent::RapidTransit, Color{0xf68b1f} }, // F OSM: 6064751 WD: Q10318684 41.15, -8.655 x 41.19, -8.542
    { 524, 14201, 14126, LineMetaDataContent::RapidTransit, Color{0x3caeef} }, // A OSM: 6064925 WD: Q18473912 41.15, -8.694 x 41.19, -8.582
    { 311, 14228, 14126, LineMetaDataContent::RapidTransit, Color{0x8bc63e} }, // C OSM: 6065645 WD: Q10318673 41.15, -8.656 x 41.27, -8.586
    { 314, 14255, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffff00} }, // S OSM: 6071918 WD: Q7395342 37.74, -122.5 x 37.79, -122.4
    { 2302, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00a076} }, // 704 OSM: 6073252 WD: Q5602824 40.69, -112 x 40.78, -111.9
    { 2306, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0055a4} }, // 701 OSM: 6073253 WD: Q4929373 40.53, -111.9 x 40.77, -111.9
    { 55, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x000080} }, // 1 OSM: 6087653 WD: Q10318642 -19.95, -44.03 x -19.82, -43.91
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xea5297} }, // 4 OSM: 6092716 47.99, 7.829 x 48.04, 7.863
    { 2310, 14274, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // Sul OSM: 6113028 WD: Q10318728 -3.895, -38.63 x -3.72, -38.53
    { 222, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0xf36421} }, // S 1 OSM: 6116272 WD: Q56378877 50.88, 13.46 x 51.16, 14.24
    { 1652, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0xb8282e} }, // S 2 OSM: 6116280 WD: Q56378880 50.96, 13.72 x 51.13, 13.93
    { 1591, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0xed0172} }, // S 3 OSM: 6116305 WD: Q56378881 50.9, 13.34 x 51.04, 13.73
    { 218, 14312, 9093, LineMetaDataContent::RapidTransit, Color{0x159dd9} }, // S4 OSM: 6157906 WD: Q96484000 47.81, 15.98 x 48.4, 16.41
    { 196, 14324, 14126, LineMetaDataContent::RapidTransit, Color{0xe62621} }, // B OSM: 6161229 WD: Q10318669 41.15, -8.758 x 41.38, -8.582
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc01115} }, // 1 OSM: 6182760 WD: Q2085324 51.98, 4.277 x 52.12, 4.359
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x006600} }, // 2 OSM: 6182761 WD: Q3926989 52.05, 4.236 x 52.09, 4.383
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0093de} }, // 6 OSM: 6182762 WD: Q2205103 52.06, 4.264 x 52.1, 4.4
    { 54, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xcd853f} }, // 11 OSM: 6192619 WD: Q2084217 52.06, 4.27 x 52.11, 4.324
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff66ff} }, // 12 OSM: 6192620 WD: Q2541548 52.06, 4.252 x 52.09, 4.324
    { 132, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xa6c116} }, // 9 OSM: 6192621 WD: Q2293268 52.03, 4.257 x 52.12, 4.324
    { 143, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe63a6b} }, // 15 OSM: 6197181 WD: Q2202159 52.04, 4.31 x 52.08, 4.393
    { 26, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfa7222} }, // 16 OSM: 6197182 WD: Q2746551 52.02, 4.274 x 52.08, 4.327
    { 179, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x006b8b} }, // 17 OSM: 6197183 WD: Q2417431 52.02, 4.28 x 52.09, 4.339
    { 147, NoLogo, 13916, LineMetaDataContent::Tramway, Color{0xc01115} }, // 19 OSM: 6197184 WD: Q2886326 52.01, 4.35 x 52.09, 4.406
    { 2314, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff9c2a} }, // N2 OSM: 6227258 47.47, 19.05 x 47.51, 19.08
    { 2317, NoLogo, 14351, LineMetaDataContent::RapidTransit, Color{0x0275a4} }, // BLUE OSM: 6265609 WD: Q4929367 32.65, -96.81 x 32.92, -96.56
    { 1026, NoLogo, 14351, LineMetaDataContent::RapidTransit, Color{0xcc0000} }, // RED OSM: 6265610 WD: Q16984038 32.72, -96.87 x 33.03, -96.7
    { 2322, NoLogo, 14351, LineMetaDataContent::RapidTransit, Color{0x00873f} }, // GREEN OSM: 6265672 WD: Q5602816 32.72, -96.94 x 32.99, -96.68
    { 2328, NoLogo, 14351, LineMetaDataContent::RapidTransit, Color{0xcc6600} }, // ORANGE OSM: 6265702 WD: Q7099665 32.78, -97.04 x 33.03, -96.7
    { 2335, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000066} }, // 620 OSM: 6265792 WD: Q19878111 32.75, -96.82 x 32.78, -96.81
    { 65, 14386, 14407, LineMetaDataContent::Subway, Color{0x0000ff} }, // 10 OSM: 6286483 WD: Q3239219 59.33, 17.88 x 59.4, 18.07
    { 54, 14386, 14407, LineMetaDataContent::Subway, Color{0x0000ff} }, // 11 OSM: 6286484 WD: Q3239220 59.33, 17.91 x 59.42, 18.07
    { 179, 14434, 14407, LineMetaDataContent::Subway, Color{0x008000} }, // 17 OSM: 6286485 WD: Q3239225 59.27, 17.92 x 59.34, 18.13
    { 22, 14434, 14407, LineMetaDataContent::Subway, Color{0x008000} }, // 18 OSM: 6286486 WD: Q3239226 59.23, 17.98 x 59.34, 18.1
    { 147, 14434, 14407, LineMetaDataContent::Subway, Color{0x008000} }, // 19 OSM: 6286487 WD: Q3239227 59.26, 17.83 x 59.37, 18.08
    { 58, 14457, 14407, LineMetaDataContent::Subway, Color{0xff0000} }, // 13 OSM: 6286488 WD: Q3239222 59.24, 17.81 x 59.36, 18.1
    { 139, 14457, 14407, LineMetaDataContent::Subway, Color{0xff0000} }, // 14 OSM: 6286489 WD: Q3239223 59.29, 17.96 x 59.4, 18.08
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe51919} }, // 1 OSM: 6336724 47.1, 37.54 x 47.15, 37.62
    { 2371, NoLogo, 14479, LineMetaDataContent::Subway, Color{0x0a9cda} }, // Victoria OSM: 6354922 WD: Q203030 51.46, -0.1441 x 51.59, -0.01927
    { 2380, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x3a75c4} }, // North Clyde OSM: 6399061 55.85, -4.733 x 56, -3.19
    { 2392, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x2e8b57} }, // North Berwick OSM: 6399368 55.93, -3.187 x 56.06, -2.513
    { 2406, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xcc5500} }, // Maryhill OSM: 6403662 55.86, -4.321 x 55.9, -4.239
    { 2415, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0b4ea2} }, // TL 1 OSM: 6421836 50.83, -0.5143 x 52.14, -0.03743
    { 2420, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x629f3f} }, // Santa Cruz OSM: 6432131 WD: Q10318722 -22.92, -43.69 x -22.85, -43.19
    { 2431, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0691f6} }, // Japeri OSM: 6432248 WD: Q10318695 -22.91, -43.66 x -22.64, -43.19
    { 9, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xffcc29} }, // 4 OSM: 6432702 WD: Q6553130 -23.01, -43.31 x -22.98, -43.2
    { 1823, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x00ab4e} }, // KTL OSM: 6452936 WD: Q736412 22.29, 114.2 x 22.34, 114.3
    { 2438, 14495, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe6180a} }, // 505 OSM: 6481283 WD: Q13645607 22.38, 114 x 22.41, 114
    { 2442, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x1a8539} }, // 507 OSM: 6481317 WD: Q15917019 22.37, 114 x 22.41, 114
    { 2446, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x8d3219} }, // 610 OSM: 6481421 WD: Q15908713 22.37, 114 x 22.45, 114
    { 2450, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf4e619} }, // 615 OSM: 6481435 WD: Q15903207 22.37, 114 x 22.45, 114
    { 2454, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x44adc3} }, // 614 OSM: 6485195 WD: Q15903043 22.37, 114 x 22.45, 114
    { 2458, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf58c14} }, // 751 OSM: 6485220 WD: Q15903000 22.39, 114 x 22.47, 114
    { 2462, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x70147b} }, // 761P OSM: 6485222 WD: Q15909914 22.44, 114 x 22.47, 114
    { 2467, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf7931d} }, // SN 5 OSM: 6489645 51.07, -0.3187 x 51.5, 0.2699
    { 2472, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009933} }, // T-A OSM: 6491413 6.233, -75.57 x 6.248, -75.54
    { 211, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xed1c24} }, // T1 OSM: 6497386 43.28, 5.547 x 43.3, 5.566
    { 2476, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x6633ff} }, // T1 R OSM: 6545828 WD: Q118592004 36.72, 3.083 x 36.78, 3.263
    { 2481, 14510, NoLogo, LineMetaDataContent::Tramway, Color{0xff00ff} }, // 18E OSM: 6547489 WD: Q63230200 38.7, -9.203 x 38.71, -9.145
    { 2485, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xba85bb} }, // 706 OSM: 6558996 WD: Q6718531 22.45, 114 x 22.47, 114
    { 2489, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x8cc022} }, // 705 OSM: 6558997 WD: Q16057726 22.45, 114 x 22.47, 114
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe41f25} }, // 4 OSM: 6576221 48.22, 14.23 x 48.31, 14.29
    { 363, 14523, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf7b618} }, // E OSM: 6584634 WD: Q4993859 34.01, -118.5 x 34.05, -118.2
    { 524, 14548, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0072bc} }, // A OSM: 6585129 WD: Q3267759 33.77, -118.3 x 34.15, -117.9
    { 2493, 14573, NoLogo, LineMetaDataContent::LocalTrain, Color{0x009bd5} }, // RB22 OSM: 6593456 WD: Q68006335 52.3, 12.97 x 52.41, 13.64
    { 2498, 14593, NoLogo, LineMetaDataContent::Tramway, Color{0xff7f00} }, // 25E OSM: 6595981 WD: Q63230206 38.71, -9.17 x 38.72, -9.135
    { 2502, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // C13 OSM: 6641930 50.59, 12.69 x 50.92, 12.98
    { 979, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 29 OSM: 6653146 55.81, 37.52 x 55.84, 37.58
    { 1772, 14606, 11751, LineMetaDataContent::Subway, Color{0x00893e} }, // b OSM: 6659014 WD: Q24641690 48.09, -1.707 x 48.13, -1.62
    { 55, 14636, 14665, LineMetaDataContent::Tramway, Color{0x0000ff} }, // 1 OSM: 6667548 WD: Q30926891 -22.91, -43.21 x -22.89, -43.17
    { 537, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // T2 OSM: 6679929 WD: Q107172304 42.84, -2.685 x 42.88, -2.664
    { 42, 14686, NoLogo, LineMetaDataContent::Tramway, Color{0x2948a3} }, // 7 OSM: 6679981 WD: Q117302440 52.38, 16.88 x 52.44, 16.96
    { 22, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfad50e} }, // 18 OSM: 6680332 52.38, 16.88 x 52.42, 17
    { 2506, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffa500} }, // MSC OSM: 6686325 14.2, 121 x 14.62, 121.2
    { 2510, 14724, 12889, LineMetaDataContent::Subway, Color{0xb2aed3} }, // L12 OSM: 6699916 WD: Q20107064 41.4, 2.119 x 41.4, 2.126
    { 139, 14742, NoLogo, LineMetaDataContent::Subway, Color{0x81312f} }, // 14 OSM: 6728233 WD: Q6553073 23.24, 113.3 x 23.57, 113.6
    { 2514, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x6c421b} }, // S14 OSM: 6731045 WD: Q7388188 47.27, 8.429 x 47.41, 8.84
    { 2518, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x9a9b9f} }, // Тр8 OSM: 6749431 49.78, 24.03 x 49.84, 24.06
    { 2524, 599, NoLogo, LineMetaDataContent::Subway, Color{0x2c2276} }, // U74 OSM: 6760736 WD: Q661002 51.16, 6.615 x 51.28, 6.854
    { 55, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x791714} }, // 1 OSM: 6774704 WD: Q10318644 -12.99, -38.52 x -12.92, -38.46
    { 2528, 14763, 14786, LineMetaDataContent::Tramway, Color{0x83b81a} }, // Τ6 OSM: 6792080 WD: Q25535312 37.92, 23.7 x 37.97, 23.74
    { 2532, 14826, 14786, LineMetaDataContent::Tramway, Color{0x83b81a} }, // Τ7 OSM: 6792082 WD: Q25535308 37.85, 23.64 x 37.95, 23.75
    { 2536, 14849, 13232, LineMetaDataContent::RapidTransit, Color{0x202776} }, // S43 OSM: 6794665 WD: Q86674587 50.62, 5.327 x 50.93, 5.718
    { 41, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfff90a} }, // S7 OSM: 6796259 48.63, 8.065 x 49.01, 8.432
    { 1921, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfff90a} }, // S71 OSM: 6796260 48.63, 8.065 x 48.99, 8.405
    { 2540, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x6d682a} }, // S81 OSM: 6796368 48.44, 8.215 x 48.99, 8.83
    { 42, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffa500} }, // 7 OSM: 6799066 39.75, 30.49 x 39.76, 30.54
    { 55, 14871, NoLogo, LineMetaDataContent::Subway, Color{0xe4002b} }, // 1 OSM: 6800211 WD: Q1326478 31.11, 121.4 x 31.4, 121.5
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00bfff} }, // 4 OSM: 6800376 39.75, 30.5 x 39.78, 30.56
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffff00} }, // 6 OSM: 6800649 39.74, 30.52 x 39.78, 30.59
    { 26, 14891, NoLogo, LineMetaDataContent::Subway, Color{0x2cd5c4} }, // 16 OSM: 6803864 WD: Q5954911 30.91, 121.6 x 31.2, 121.9
    { 6, 14912, NoLogo, LineMetaDataContent::Subway, Color{0xac4fc6} }, // 5 OSM: 6806165 WD: Q1331322 30.91, 121.4 x 31.12, 121.5
    { 59, 14932, NoLogo, LineMetaDataContent::Subway, Color{0xffd100} }, // 3 OSM: 6817204 WD: Q1326495 31.15, 121.4 x 31.41, 121.5
    { 2544, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xb6bd00} }, // SIL OSM: 6827213 WD: Q2041013 22.24, 114.1 x 22.28, 114.2
    { 27, 14941, NoLogo, LineMetaDataContent::Subway, Color{0xd9017a} }, // 6 OSM: 6840940 WD: Q631135 31.15, 121.5 x 31.36, 121.6
    { 2548, 14950, NoLogo, LineMetaDataContent::RapidTransit, Color{0x692832} }, // TL-1 OSM: 6849311 WD: Q5985920 20.61, -103.4 x 20.74, -103.4
    { 564, 15016, NoLogo, LineMetaDataContent::LocalTrain, Color{0xef7d00} }, // RE7 OSM: 6851149 WD: Q1753399 53.55, 9.374 x 54.78, 10.14
    { 2553, 15032, NoLogo, LineMetaDataContent::RapidTransit, Color{0x407058} }, // TL-2 OSM: 6851904 WD: Q5986178 20.66, -103.4 x 20.68, -103.3
    { 1038, 4926, 4578, LineMetaDataContent::Subway, Color{0xffff00} }, // 8А OSM: 6855054 WD: Q585986 55.63, 37.33 x 55.75, 37.54
    { 393, 15098, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff6600} }, // L2 OSM: 6857222 WD: Q5986175 -37.03, -73.16 x -36.82, -73.06
    { 389, 15156, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff6600} }, // L1 OSM: 6857223 WD: Q5985914 -36.98, -73.12 x -36.71, -72.94
    { 235, 15224, 3199, LineMetaDataContent::RapidTransit, Color{0xc6cc00} }, // J OSM: 6904183 WD: Q93388 48.88, 1.478 x 49.29, 2.326
    { 2558, 15258, 5211, LineMetaDataContent::Tramway, Color{0xf68c59} }, // T3a OSM: 6907402 WD: Q2420695 48.82, 2.27 x 48.85, 2.411
    { 1787, 15292, 5211, LineMetaDataContent::Tramway, Color{0xf2af00} }, // T4 OSM: 6910344 WD: Q1826681 48.89, 2.476 x 48.93, 2.571
    { 1527, 15325, 5211, LineMetaDataContent::Tramway, Color{0xb156a1} }, // T5 OSM: 6910410 WD: Q3238968 48.94, 2.356 x 48.98, 2.391
    { 1989, 15358, 5211, LineMetaDataContent::Tramway, Color{0xe85426} }, // T6 OSM: 6910437 WD: Q3238993 48.78, 2.169 x 48.81, 2.301
    { 2562, 15391, 5211, LineMetaDataContent::Tramway, Color{0xb98b59} }, // T7 OSM: 6910465 WD: Q3239019 48.71, 2.352 x 48.79, 2.373
    { 2565, 15424, NoLogo, LineMetaDataContent::LocalTrain, Color{0x66aa22} }, // RB10 OSM: 6924342 WD: Q15195695 52.47, 12.88 x 52.61, 13.38
    { 1590, 15444, 226, LineMetaDataContent::RapidTransit, Color{0x5cda21} }, // RS 3 OSM: 6925925 WD: Q84703705 53.05, 8.002 x 53.18, 8.815
    { 1367, 15459, 226, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // RS 4 OSM: 6925927 WD: Q84703708 53.05, 8.452 x 53.49, 8.815
    { 2570, 15474, 15474, LineMetaDataContent::Subway, Color{0xffcf00} }, // Orlyval OSM: 6928902 WD: Q432593 48.73, 2.3 x 48.76, 2.37
    { 2578, 15474, 15474, LineMetaDataContent::Subway, Color{0x142b4a} }, // CDGVAL OSM: 6928933 WD: Q1023114 49, 2.542 x 49.01, 2.572
    { 2298, 15497, NoLogo, LineMetaDataContent::LocalTrain, Color{0xe64dff} }, // RE6 OSM: 6933203 WD: Q63224485 52.5, 11.76 x 53.16, 13.3
    { 524, 15516, NoLogo, LineMetaDataContent::Subway, Color{0x800080} }, // A OSM: 6937084 WD: Q4268353 24.97, 121.2 x 25.09, 121.5
    { 562, 15547, NoLogo, LineMetaDataContent::Subway, Color{0xfccc0a} }, // W OSM: 6942556 WD: Q126567 40.7, -74.01 x 40.78, -73.91
    { 2585, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008531} }, // Luas Green Line OSM: 6975500 WD: Q2086105 53.24, -6.298 x 53.37, -6.143
    { 2601, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x68c56b} }, // DART OSM: 6979159 53.14, -6.255 x 53.45, -6.06
    { 55, 15573, 15598, LineMetaDataContent::Tramway, Color{0xc00027} }, // 1 OSM: 6981890 WD: Q2211906 47.74, 7.321 x 47.78, 7.343
    { 6, 15621, 15642, LineMetaDataContent::Subway, Color{0xf6a90b} }, // 5 OSM: 6996917 WD: Q957143 50.81, 4.266 x 50.86, 4.432
    { 16, 15666, 15598, LineMetaDataContent::Tramway, Color{0xffd80e} }, // 2 OSM: 7006051 WD: Q2024859 47.73, 7.297 x 47.76, 7.352
    { 55, 15691, 15642, LineMetaDataContent::Subway, Color{0xb5378c} }, // 1 OSM: 7006076 WD: Q1345228 50.84, 4.319 x 50.86, 4.464
    { 59, 15712, 15598, LineMetaDataContent::Tramway, Color{0x00a651} }, // 3 OSM: 7006942 WD: Q3238912 47.74, 7.275 x 47.76, 7.344
    { 16, NoLogo, 15474, LineMetaDataContent::RapidTransit, Color{0x142b4a} }, // 2 OSM: 7011253 WD: Q52773923 49, 2.578 x 49, 2.591
    { 1388, 15737, NoLogo, LineMetaDataContent::LocalTrain, Color{0xff0000} }, // RE1 OSM: 7024716 WD: Q15119401 52.13, 11.63 x 52.53, 14.66
    { 16, 15756, 14665, LineMetaDataContent::Tramway, Color{0x008000} }, // 2 OSM: 7064054 WD: Q30926895 -22.91, -43.21 x -22.9, -43.17
    { 1193, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 36 OSM: 7080875 55.75, 37.71 x 55.83, 37.82
    { 50, 15785, 226, LineMetaDataContent::RapidTransit, Color{0x6cc247} }, // S2 OSM: 7091572 WD: Q7388247 48.13, 11.25 x 48.41, 11.91
    { 1189, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x223344} }, // 22 OSM: 7095091 54.26, 48.28 x 54.36, 48.41
    { 389, 15801, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // L1 OSM: 7106760 WD: Q3011576 43.24, -3.013 x 43.4, -2.897
    { 218, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0xed1c24} }, // S4 OSM: 7113761 WD: Q116210481 46.55, 13.37 x 46.63, 13.85
    { 50, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x3c8475} }, // S2 OSM: 7113763 WD: Q116210398 46.62, 13.85 x 46.77, 14.37
    { 61, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x17489e} }, // S1 OSM: 7113764 WD: Q116209766 46.6, 12.77 x 46.95, 14.48
    { 42, 15824, 7105, LineMetaDataContent::Tramway, Color{0xefe048} }, // 7 OSM: 7135778 WD: Q3239018 50.81, 4.336 x 50.9, 4.408
    { 397, 15845, NoLogo, LineMetaDataContent::Subway, Color{0xe3007d} }, // L3 OSM: 7141757 WD: Q2992379 43.25, -2.926 x 43.27, -2.889
    { 936, 15868, 7105, LineMetaDataContent::Tramway, Color{0xe43c2e} }, // 92 OSM: 7152034 WD: Q2661521 50.79, 4.34 x 50.88, 4.381
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x37b355} }, // 2 OSM: 7157243 WD: Q60031554 48.38, 9.936 x 48.43, 9.987
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xed1b24} }, // 1 OSM: 7157244 WD: Q60031375 48.39, 9.955 x 48.43, 10.03
    { 389, 15890, NoLogo, LineMetaDataContent::RapidTransit, Color{0xc00b31} }, // L1 OSM: 7183555 WD: Q29634861 37.14, -3.654 x 37.23, -3.592
    { 2606, 15914, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // C-2 OSM: 7193330 WD: Q4802702 43.25, -3.112 x 43.32, -2.928
    { 2610, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // C14 OSM: 7204222 50.7, 12.85 x 50.99, 12.98
    { 2614, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // C15 OSM: 7211723 50.81, 12.92 x 50.97, 13.12
    { 16, 15932, 8193, LineMetaDataContent::Subway, Color{0x003da5} }, // 2 OSM: 7227705 WD: Q50718 48.85, 2.278 x 48.88, 2.399
    { 55, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x93c21c} }, // 1 OSM: 7252644 WD: Q60669571 -23.97, -46.41 x -23.96, -46.31
    { 2618, 15967, 14479, LineMetaDataContent::Subway, Color{0xe42313} }, // Central OSM: 7254206 WD: Q205355 51.5, -0.4377 x 51.69, 0.1146
    { 363, 15992, 2529, LineMetaDataContent::RapidTransit, Color{0xc04191} }, // E OSM: 7271953 WD: Q668655 48.74, 2.329 x 48.9, 2.759
    { 58, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf6c828} }, // 13 OSM: 7295272 WD: Q96483392 47.35, 8.481 x 47.41, 8.542
    { 16, 16024, 15642, LineMetaDataContent::Subway, Color{0xed6c23} }, // 2 OSM: 7305855 WD: Q1826676 50.83, 4.321 x 50.87, 4.37
    { 27, 16045, NoLogo, LineMetaDataContent::Subway, Color{0x80225f} }, // 6 OSM: 7322006 WD: Q6553140 23.11, 113.2 x 23.2, 113.5
    { 139, 16065, 4578, LineMetaDataContent::Tramway, Color{0x000000} }, // 14 OSM: 7339185 WD: Q26856861 55.68, 37.49 x 55.85, 37.75
    { 1389, 16090, NoLogo, LineMetaDataContent::LocalTrain, Color{0x0063a9} }, // E1 OSM: 7353799 WD: Q43263877 43.16, -2.926 x 43.31, -1.981
    { 2626, 16107, 226, LineMetaDataContent::RapidTransit, Color{0x9f4c37} }, // S41 OSM: 7369771 WD: Q12374455 52.46, 13.28 x 52.55, 13.48
    { 358, 16138, 7105, LineMetaDataContent::Tramway, Color{0x4c8b33} }, // 81 OSM: 7375224 WD: Q2133516 50.82, 4.28 x 50.84, 4.408
    { 61, 16160, 13232, LineMetaDataContent::RapidTransit, Color{0x005f33} }, // S1 OSM: 7382640 WD: Q24929119 50.6, 4.32 x 51.22, 4.497
    { 50, NoLogo, 13232, LineMetaDataContent::RapidTransit, Color{0xf16122} }, // S2 OSM: 7383577 WD: Q56309162 50.61, 4.139 x 50.9, 4.716
    { 1211, NoLogo, 13232, LineMetaDataContent::RapidTransit, Color{0x009696} }, // S20 OSM: 7386794 WD: Q56309254 50.67, 4.565 x 50.88, 4.719
    { 44, NoLogo, 13232, LineMetaDataContent::RapidTransit, Color{0xffcc06} }, // S5 OSM: 7387151 WD: Q56309389 50.69, 3.87 x 51.02, 4.484
    { 166, NoLogo, 13232, LineMetaDataContent::RapidTransit, Color{0x222975} }, // S3 OSM: 7388964 WD: Q56309590 50.82, 3.814 x 51.02, 4.366
    { 218, NoLogo, 13232, LineMetaDataContent::RapidTransit, Color{0xcb2127} }, // S4 OSM: 7389117 WD: Q56309251 50.82, 4.039 x 51.02, 4.523
    { 204, NoLogo, 13232, LineMetaDataContent::RapidTransit, Color{0x965f26} }, // S6 OSM: 7391007 WD: Q56309855 50.69, 3.87 x 50.89, 4.378
    { 41, NoLogo, 13232, LineMetaDataContent::RapidTransit, Color{0x571759} }, // S7 OSM: 7391045 WD: Q56309167 50.73, 4.241 x 50.92, 4.434
    { 47, NoLogo, 13232, LineMetaDataContent::RapidTransit, Color{0x0096cb} }, // S8 OSM: 7391071 WD: Q56309403 50.65, 3.814 x 50.91, 4.617
    { 477, NoLogo, 13232, LineMetaDataContent::RapidTransit, Color{0x67bc45} }, // S9 OSM: 7391314 WD: Q56309779 50.6, 4.335 x 50.9, 5.08
    { 966, NoLogo, 13232, LineMetaDataContent::RapidTransit, Color{0x000000} }, // S10 OSM: 7391375 WD: Q56309273 50.83, 4.039 x 51.02, 4.366
    { 260, 16183, 226, LineMetaDataContent::LocalTrain, Color{0x035e33} }, // S51 OSM: 7392144 WD: Q115284858 50.74, 3.575 x 51.18, 3.758
    { 2630, 16204, 13232, LineMetaDataContent::RapidTransit, Color{0x005d30} }, // L-17 OSM: 7392801 WD: Q86358695 50.56, 5.559 x 50.66, 5.854
    { 83, 16226, NoLogo, LineMetaDataContent::RapidTransit, Color{0x005d30} }, // S61 OSM: 7394292 WD: Q84951112 50.39, 4.432 x 50.67, 4.881
    { 2635, 16252, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf26021} }, // S62 OSM: 7395296 WD: Q86070870 50.4, 4.17 x 50.51, 4.439
    { 79, 16278, NoLogo, LineMetaDataContent::RapidTransit, Color{0x202776} }, // S63 OSM: 7396143 WD: Q85178055 50.27, 3.967 x 50.41, 4.439
    { 2639, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x4a611c} }, // RL1 OSM: 7399137 WD: Q3781389 41.62, 0.631 x 41.79, 0.8166
    { 945, 16304, 13232, LineMetaDataContent::RapidTransit, Color{0x202776} }, // S33 OSM: 7400676 WD: Q87071069 51.14, 4.421 x 51.22, 5.115
    { 1002, 16330, 226, LineMetaDataContent::LocalTrain, Color{0xf26021} }, // S52 OSM: 7400734 WD: Q115285798 50.77, 3.71 x 51.04, 3.875
    { 581, 16351, NoLogo, LineMetaDataContent::RapidTransit, Color{0xcc2027} }, // S64 OSM: 7403404 WD: Q85944484 50.06, 4.387 x 50.41, 4.538
    { 231, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffff00} }, // 25 OSM: 7409703 31.2, 29.9 x 31.22, 29.93
    { 55, 16377, NoLogo, LineMetaDataContent::Tramway, Color{0xf38230} }, // 1 OSM: 7418079 WD: Q59134535 33.53, -7.67 x 33.6, -7.5
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffdb2f} }, // 2 OSM: 7418090 WD: Q59159905 33.56, -7.682 x 33.61, -7.507
    { 1787, 9867, 9839, LineMetaDataContent::Tramway, Color{0xffa500} }, // T4 OSM: 7420266 WD: Q15507510 41.02, 28.85 x 41.12, 28.93
    { 58, 16431, 8193, LineMetaDataContent::Subway, Color{0x71c5e8} }, // 13 OSM: 7420641 WD: Q50759 48.81, 2.284 x 48.95, 2.369
    { 15, 16467, 8193, LineMetaDataContent::Subway, Color{0x007a53} }, // 12 OSM: 7420642 WD: Q50757 48.82, 2.273 x 48.91, 2.381
    { 54, 16503, 8193, LineMetaDataContent::Subway, Color{0x6e4c1e} }, // 11 OSM: 7420643 WD: Q50756 48.86, 2.348 x 48.88, 2.466
    { 19, 16539, 8193, LineMetaDataContent::Subway, Color{0xdd9cdf} }, // 8 OSM: 7420644 WD: Q50751 48.77, 2.278 x 48.87, 2.465
    { 6, 16574, 8193, LineMetaDataContent::Subway, Color{0xff7f32} }, // 5 OSM: 7420645 WD: Q50745 48.83, 2.354 x 48.91, 2.449
    { 2643, 16609, 8193, LineMetaDataContent::Subway, Color{0x71c5e8} }, // 3bis OSM: 7420646 WD: Q50742 48.87, 2.399 x 48.88, 2.407
    { 329, 16647, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf28e42} }, // P OSM: 7420696 WD: Q93874 48.51, 2.359 x 49.18, 3.409
    { 459, 16681, 3199, LineMetaDataContent::RapidTransit, Color{0xf3a4ba} }, // R OSM: 7420697 WD: Q93383 48.01, 2.374 x 48.84, 2.943
    { 34, 16715, 3199, LineMetaDataContent::RapidTransit, Color{0x7b4339} }, // H OSM: 7420698 WD: Q93386 48.88, 2.093 x 49.26, 2.469
    { 517, 16749, 3199, LineMetaDataContent::RapidTransit, Color{0x00a88f} }, // N OSM: 7420700 WD: Q93376 48.64, 1.37 x 48.99, 2.319
    { 196, 16783, 2529, LineMetaDataContent::RapidTransit, Color{0x5291ce} }, // B OSM: 7420701 WD: Q1347825 48.69, 2.071 x 49.01, 2.642
    { 314, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfd8fb4} }, // S OSM: 7424196 WD: Q2329867 48.17, 16.33 x 48.26, 16.4
    { 513, NoLogo, 3420, LineMetaDataContent::RapidTransit, Color{0x035eb9} }, // G OSM: 7435094 WD: Q118923662 60.74, 24.78 x 60.98, 25.66
    { 447, NoLogo, 3420, LineMetaDataContent::RapidTransit, Color{0x035eb9} }, // K OSM: 7435653 WD: Q118874957 60.17, 24.93 x 60.41, 25.11
    { 459, NoLogo, 3420, LineMetaDataContent::RapidTransit, Color{0x357219} }, // R OSM: 7439055 WD: Q118874959 60.17, 23.74 x 61.5, 25.11
    { 524, 16815, 3420, LineMetaDataContent::RapidTransit, Color{0x8c4799} }, // A OSM: 7440364 WD: Q118874158 60.17, 24.81 x 60.22, 24.94
    { 363, NoLogo, 3420, LineMetaDataContent::RapidTransit, Color{0x008000} }, // E OSM: 7442189 WD: Q118869683 60.17, 24.6 x 60.22, 24.94
    { 324, NoLogo, 3420, LineMetaDataContent::RapidTransit, Color{0x008000} }, // U OSM: 7442496 WD: Q118869424 60.12, 24.43 x 60.22, 24.94
    { 451, NoLogo, 3420, LineMetaDataContent::RapidTransit, Color{0x008000} }, // L OSM: 7442589 WD: Q118869556 60.12, 24.44 x 60.22, 24.94
    { 884, NoLogo, 3420, LineMetaDataContent::RapidTransit, Color{0x357219} }, // Y OSM: 7442716 WD: Q118868930 60.11, 24.22 x 60.22, 24.94
    { 9, 16833, NoLogo, LineMetaDataContent::Subway, Color{0x5f259f} }, // 4 OSM: 7448424 WD: Q1326504 31.18, 121.4 x 31.26, 121.5
    { 19, 16842, NoLogo, LineMetaDataContent::Subway, Color{0x009fdf} }, // 8 OSM: 7451833 WD: Q1152341 31.06, 121.5 x 31.32, 121.5
    { 132, 16851, NoLogo, LineMetaDataContent::Subway, Color{0x71c5e8} }, // 9 OSM: 7451835 WD: Q1152370 30.99, 121.2 x 31.27, 121.7
    { 15, 16860, NoLogo, LineMetaDataContent::Subway, Color{0x007b5f} }, // 12 OSM: 7451887 WD: Q877180 31.13, 121.3 x 31.28, 121.6
    { 58, 16881, NoLogo, LineMetaDataContent::Subway, Color{0xef95cf} }, // 13 OSM: 7451890 WD: Q607539 31.17, 121.3 x 31.25, 121.6
    { 65, 16891, NoLogo, LineMetaDataContent::Subway, Color{0xc1a7e2} }, // 10 OSM: 7452119 WD: Q528209 31.17, 121.3 x 31.36, 121.6
    { 2648, 16901, 16926, LineMetaDataContent::RapidTransit, Color{0xed8000} }, // I2 OSM: 7527498 WD: Q484739 37.44, 126.6 x 37.6, 126.8
    { 324, 16954, 16926, LineMetaDataContent::RapidTransit, Color{0xfda600} }, // U OSM: 7530882 WD: Q491655 37.72, 127 x 37.75, 127.1
    { 363, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x509f22} }, // E OSM: 7531174 37.24, 127.1 x 37.29, 127.2
    { 562, 16982, 16926, LineMetaDataContent::RapidTransit, Color{0xb0ce18} }, // W OSM: 7533584 WD: Q3832795 37.58, 127 x 37.66, 127
    { 272, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // Blue OSM: 7548642 41.47, -81.71 x 41.51, -81.54
    { 480, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // Green OSM: 7548643 41.48, -81.71 x 41.51, -81.52
    { 284, NoLogo, 17020, LineMetaDataContent::Subway, Color{0xff0000} }, // Red OSM: 7551457 WD: Q2136023 41.41, -81.84 x 41.53, -81.58
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00ff00} }, // 3 OSM: 7560907 51.34, -0.1055 x 51.38, -0.01745
    { 2651, 17043, 17060, LineMetaDataContent::Subway, Color{0xffff00} }, // YL OSM: 7572167 WD: Q4710841 38.79, -77.08 x 38.91, -77.02
    { 2654, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xbcbdc0} }, // Silver OSM: 7572385 40.29, -80.03 x 40.45, -79.99
    { 2661, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // 510 OSM: 7572438 32.54, -117.2 x 32.88, -117
    { 284, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xec1b24} }, // Red OSM: 7574880 40.34, -80.05 x 40.45, -79.99
    { 272, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x77b6e4} }, // Blue OSM: 7575525 40.34, -80.05 x 40.45, -79.99
    { 211, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe40046} }, // T1 OSM: 7580424 WD: Q3239057 50.32, 3.385 x 50.37, 3.523
    { 2672, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0066cc} }, // TC OSM: 7597545 WD: Q3538439 -34.51, -58.58 x -34.42, -58.48
    { 16, 17081, 16926, LineMetaDataContent::Subway, Color{0x33a23d} }, // 2 OSM: 7625892 WD: Q17501 37.48, 126.8 x 37.57, 127.1
    { 9, 17104, 16926, LineMetaDataContent::Subway, Color{0x32a1c8} }, // 4 OSM: 7625893 WD: Q489253 37.3, 126.7 x 37.72, 127.2
    { 389, 17127, NoLogo, LineMetaDataContent::Subway, Color{0x659acd} }, // L1 OSM: 7627370 WD: Q20685853 36.71, 3.054 x 36.79, 3.138
    { 261, 17159, 7105, LineMetaDataContent::Tramway, Color{0xf3c300} }, // 51 OSM: 7632520 WD: Q751385 50.78, 4.326 x 50.89, 4.349
    { 939, 17181, 7105, LineMetaDataContent::Tramway, Color{0xed7807} }, // 93 OSM: 7632524 WD: Q2845878 50.82, 4.33 x 50.89, 4.372
    { 55, 17203, NoLogo, LineMetaDataContent::Subway, Color{0x147049} }, // 1 OSM: 7643008 WD: Q21034316 38.02, 46.23 x 38.08, 46.36
    { 342, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 49 OSM: 7657682 55.68, 37.62 x 55.7, 37.69
    { 16, 17227, 8405, LineMetaDataContent::Subway, Color{0x006abc} }, // 2 OSM: 7660420 WD: Q1771527 56.32, 43.89 x 56.34, 43.97
    { 265, 17246, 17246, LineMetaDataContent::Subway, Color{0xf25e24} }, // M1 OSM: 7664663 WD: Q207287 60.14, 24.64 x 60.21, 25.15
    { 346, 17246, 17246, LineMetaDataContent::Subway, Color{0xf25e24} }, // M2 OSM: 7664664 WD: Q207287 60.16, 24.8 x 60.24, 25.11
    { 2675, NoLogo, 14479, LineMetaDataContent::Subway, Color{0xae6017} }, // Bakerloo OSM: 7666698 WD: Q19892 51.5, -0.3355 x 51.59, -0.1007
    { 2684, NoLogo, 14479, LineMetaDataContent::Subway, Color{0xf4a9be} }, // Hammersmith & City OSM: 7666927 WD: Q211270 51.49, -0.2269 x 51.54, 0.08088
    { 2703, NoLogo, 14479, LineMetaDataContent::Subway, Color{0xffd329} }, // Circle OSM: 7671007 WD: Q210321 51.49, -0.2269 x 51.53, -0.07523
    { 2710, NoLogo, 14479, LineMetaDataContent::Subway, Color{0x93ceba} }, // Waterloo & City OSM: 7672075 WD: Q207699 51.5, -0.1142 x 51.51, -0.09074
    { 2726, NoLogo, 14479, LineMetaDataContent::Subway, Color{0x949699} }, // Jubilee OSM: 7673326 WD: Q961290 51.5, -0.303 x 51.62, 0.01165
    { 2734, NoLogo, 14479, LineMetaDataContent::Subway, Color{0x91005a} }, // Metropolitan OSM: 7673626 WD: Q19891 51.51, -0.6366 x 51.71, -0.0757
    { 2747, 17271, 14479, LineMetaDataContent::Subway, Color{0x00a166} }, // District OSM: 7677096 WD: Q211265 51.42, -0.3016 x 51.56, 0.2526
    { 55, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xcc0000} }, // 1 OSM: 7680781 10.15, -68.01 x 10.2, -68
    { 55, 17297, 17297, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 7683834 WD: Q239927 37.51, 15.05 x 37.52, 15.1
    { 55, 17331, NoLogo, LineMetaDataContent::Subway, Color{0x0000ff} }, // 1 OSM: 7684062 WD: Q6553099 19.09, 72.82 x 19.13, 72.91
    { 2756, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008f75} }, // CAT OSM: 7685186 10.48, -66.81 x 10.49, -66.8
    { 59, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x00af23} }, // 3 OSM: 7686574 WD: Q5017776 30.05, 31.21 x 30.15, 31.43
    { 2760, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xdc241f} }, // NSL OSM: 7695961 WD: Q759229 1.27, 103.7 x 1.45, 103.9
    { 2764, 17353, NoLogo, LineMetaDataContent::LocalTrain, Color{0x06844b} }, // RB66 OSM: 7699251 WD: Q67991420 53.02, 13.97 x 53.42, 14.55
    { 55, 17373, 17373, LineMetaDataContent::Subway, Color{0xffa500} }, // 1 OSM: 7702663 WD: Q389415 34.39, 132.4 x 34.48, 132.5
    { 34, 17389, 17416, LineMetaDataContent::Subway, Color{0x0077cc} }, // H OSM: 7702769 WD: Q1073881 33.59, 130.4 x 33.63, 130.4
    { 2787, 17445, 14479, LineMetaDataContent::Subway, Color{0x094fa3} }, // Piccadilly OSM: 7702940 WD: Q207689 51.46, -0.4877 x 51.65, -0.09515
    { 2798, 17473, 14479, LineMetaDataContent::Subway, Color{0x000000} }, // Northern OSM: 7702944 WD: Q214793 51.4, -0.2756 x 51.65, -0.08677
    { 447, 17499, 17416, LineMetaDataContent::Subway, Color{0xff4500} }, // K OSM: 7703353 WD: Q908188 33.58, 130.3 x 33.6, 130.4
    { 2807, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xc61094} }, // MM OSM: 7703640 WD: Q852314 35.44, 139.6 x 35.47, 139.7
    { 26, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x313495} }, // 16 OSM: 7704225 52.41, 16.91 x 52.46, 16.93
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x38ab43} }, // 6 OSM: 7705201 52.38, 16.83 x 52.41, 17
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe7212a} }, // 8 OSM: 7705202 52.38, 16.88 x 52.41, 17
    { 55, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xee3c3c} }, // 1 OSM: 7705626 WD: Q66782266 29.55, 52.45 x 29.69, 52.6
    { 55, NoLogo, 17522, LineMetaDataContent::Subway, Color{0x1a988c} }, // 1 OSM: 7705633 WD: Q104230289 32.49, 51.53 x 32.84, 51.75
    { 42, 17545, 17569, LineMetaDataContent::Subway, Color{0x6a00ff} }, // 7 OSM: 7705644 WD: Q20110124 35.67, 51.35 x 35.79, 51.49
    { 9, 17591, 17569, LineMetaDataContent::Subway, Color{0xffff00} }, // 4 OSM: 7705669 WD: Q20110121 35.69, 51.3 x 35.75, 51.5
    { 2810, 17615, 16926, LineMetaDataContent::RapidTransit, Color{0x8652a1} }, // BGL OSM: 7705740 WD: Q87056 35.16, 128.9 x 35.27, 129
    { 2814, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x43b02a} }, // THZ1 OSM: 7708095 23.1, 113.3 x 23.11, 113.4
    { 55, 13017, NoLogo, LineMetaDataContent::Subway, Color{0xdf2937} }, // 1 OSM: 7712343 WD: Q25420888 8.962, -79.55 x 9.065, -79.51
    { 447, 17637, 17679, LineMetaDataContent::Subway, Color{0xec78b4} }, // K OSM: 7712576 WD: Q1078347 35.2, 136.9 x 35.2, 136.9
    { 459, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x3e754e} }, // R OSM: 7712694 WD: Q7360056 34.68, 135.3 x 34.72, 135.3
    { 329, 17712, NoLogo, LineMetaDataContent::RapidTransit, Color{0x3573bd} }, // P OSM: 7712875 WD: Q7230715 34.64, 135.2 x 34.7, 135.2
    { 447, 17738, 17760, LineMetaDataContent::Subway, Color{0x267dce} }, // K OSM: 7712969 WD: Q844019 34.65, 135.1 x 34.69, 135.2
    { 9, 17791, NoLogo, LineMetaDataContent::Subway, Color{0xdc241f} }, // 4 OSM: 7713538 WD: Q1004293 22.52, 114 x 22.73, 114.1
    { 132, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf04723} }, // 9 OSM: 7715858 52.37, 16.9 x 52.41, 16.94
    { 346, 17814, 17842, LineMetaDataContent::Subway, Color{0x009a4c} }, // M2 OSM: 7719078 WD: Q1880934 41.01, 28.95 x 41.14, 29.03
    { 8, 17866, 17842, LineMetaDataContent::Subway, Color{0xe91e76} }, // M4 OSM: 7719080 WD: Q1880989 40.88, 29.02 x 41, 29.31
    { 265, 17894, 17842, LineMetaDataContent::Subway, Color{0xe32726} }, // M1 OSM: 7719081 WD: Q6048705 40.98, 28.82 x 41.05, 28.95
    { 29, 17922, 17842, LineMetaDataContent::Subway, Color{0xcaaa79} }, // M6 OSM: 7719783 WD: Q16949744 41.08, 29.01 x 41.09, 29.05
    { 314, 17950, 17760, LineMetaDataContent::Subway, Color{0x00ae8e} }, // S OSM: 7720729 WD: Q1066548 34.66, 135 x 34.76, 135.2
    { 2819, 17973, NoLogo, LineMetaDataContent::LocalTrain, Color{0xe64dff} }, // RB51 OSM: 7724425 WD: Q63348259 52.39, 12.33 x 52.6, 12.56
    { 268, 17993, 18006, LineMetaDataContent::Subway, Color{0x1964b7} }, // MRT Blue OSM: 7725030 WD: Q2486364 13.71, 100.4 x 13.81, 100.6
    { 1561, 18029, 18006, LineMetaDataContent::Subway, Color{0x660066} }, // MRT Purple OSM: 7725058 WD: Q6584549 13.81, 100.4 x 13.89, 100.5
    { 389, 18044, 18067, LineMetaDataContent::Subway, Color{0x228b22} }, // L1 OSM: 7727216 WD: Q5985884 -12.21, -77.01 x -11.96, -76.93
    { 1030, 18113, 16926, LineMetaDataContent::Subway, Color{0xc82127} }, // 326 OSM: 7728256 WD: Q20388 37.29, 127 x 37.52, 127.1
    { 2824, 18146, 18146, LineMetaDataContent::Subway, Color{0x2e8b57} }, // 仙台市南北線 (Sendai Namboku Line) OSM: 7732249 WD: Q908156 38.21, 140.9 x 38.32, 140.9
    { 2865, 18146, 18146, LineMetaDataContent::Subway, Color{0x00bfff} }, // 仙台市東西線 (Sendai Tozai Line) OSM: 7732250 WD: Q7450186 38.24, 140.8 x 38.26, 140.9
    { 196, 18174, 18221, LineMetaDataContent::Subway, Color{0x005ba5} }, // B OSM: 7732280 WD: Q841360 35.4, 139.5 x 35.57, 139.6
    { 513, 18256, 18221, LineMetaDataContent::Subway, Color{0x048d58} }, // G OSM: 7732283 WD: Q910329 35.51, 139.5 x 35.56, 139.6
    { 389, 18304, NoLogo, LineMetaDataContent::Subway, Color{0xcc0000} }, // L1 OSM: 7732970 WD: Q4215382 -33.46, -70.72 x -33.41, -70.55
    { 393, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xffbe2e} }, // L2 OSM: 7732971 WD: Q11690005 -33.54, -70.66 x -33.38, -70.64
    { 385, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x292d91} }, // L4 OSM: 7732972 WD: Q9025952 -33.61, -70.6 x -33.42, -70.57
    { 2904, 18329, NoLogo, LineMetaDataContent::Subway, Color{0x0099ff} }, // L4A OSM: 7732973 WD: Q11690009 -33.54, -70.67 x -33.52, -70.6
    { 1238, 18355, NoLogo, LineMetaDataContent::Subway, Color{0x006633} }, // L5 OSM: 7732974 WD: Q9025969 -33.53, -70.76 x -33.44, -70.6
    { 27, 18380, NoLogo, LineMetaDataContent::Subway, Color{0x8e16a1} }, // 6 OSM: 7732978 WD: Q5986809 -33.48, -70.7 x -33.42, -70.6
    { 59, 18405, 8193, LineMetaDataContent::Subway, Color{0x827a04} }, // 3 OSM: 7733214 WD: Q50741 48.86, 2.28 x 48.9, 2.418
    { 55, 18440, 18440, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 7733917 WD: Q2047989 55.74, 49.08 x 55.86, 49.22
    { 55, 4748, 18461, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 7733918 WD: Q594532 54.98, 82.89 x 55.06, 82.94
    { 16, 5129, 18461, LineMetaDataContent::Subway, Color{0x008000} }, // 2 OSM: 7733919 WD: Q2711371 55.03, 82.9 x 55.04, 82.98
    { 55, 18488, 18488, LineMetaDataContent::Subway, Color{0x1c8c3a} }, // 1 OSM: 7733920 WD: Q750441 56.8, 60.6 x 56.9, 60.63
    { 2908, 18507, NoLogo, LineMetaDataContent::Subway, Color{0x076c57} }, // Verde OSM: 7733971 WD: Q10318743 -15.84, -48.12 x -15.79, -47.88
    { 2914, 18526, NoLogo, LineMetaDataContent::Subway, Color{0xeb9710} }, // Laranja OSM: 7733972 WD: Q10318700 -15.87, -48.09 x -15.79, -47.88
    { 16, 18550, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // 2 OSM: 7734060 WD: Q25421356 18.48, -69.97 x 18.51, -69.86
    { 55, 18565, NoLogo, LineMetaDataContent::Subway, Color{0x0000ff} }, // 1 OSM: 7734061 WD: Q25421357 18.45, -69.93 x 18.55, -69.9
    { 55, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // 1 OSM: 7734069 10.62, -71.67 x 10.64, -71.62
    { 55, 18581, 18613, LineMetaDataContent::Subway, Color{0x0000ff} }, // 1 OSM: 7734077 WD: Q28604 53.85, 27.47 x 53.95, 27.69
    { 16, NoLogo, 18613, LineMetaDataContent::Subway, Color{0xff0000} }, // 2 OSM: 7734078 WD: Q2638932 53.86, 27.43 x 53.91, 27.67
    { 346, 18634, 18659, LineMetaDataContent::Subway, Color{0x0000ff} }, // M2 OSM: 7734092 WD: Q12295702 42.66, 23.28 x 42.74, 23.32
    { 265, 18680, 18659, LineMetaDataContent::Subway, Color{0xff0000} }, // M1 OSM: 7734093 WD: Q20020737 42.63, 23.26 x 42.73, 23.38
    { 2922, 18705, 18736, LineMetaDataContent::Subway, Color{0xdf096f} }, // Vermelha OSM: 7734163 WD: Q163215 38.73, -9.153 x 38.78, -9.1
    { 2931, 18766, 18736, LineMetaDataContent::Subway, Color{0xf4bc18} }, // Amarela OSM: 7734164 WD: Q1826607 38.72, -9.173 x 38.79, -9.145
    { 2939, NoLogo, 18736, LineMetaDataContent::Subway, Color{0x4e84c4} }, // Azul OSM: 7734165 WD: Q1826609 38.71, -9.224 x 38.76, -9.122
    { 2908, 18796, 18736, LineMetaDataContent::Subway, Color{0x00aaa6} }, // Verde OSM: 7734166 WD: Q1826613 38.71, -9.167 x 38.76, -9.133
    { 2953, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff6600} }, // Subway OSM: 7734173 55.85, -4.312 x 55.88, -4.253
    { 55, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 7734180 WD: Q4504162 48.48, 34.93 x 48.48, 35.02
    { 517, 18824, 17416, LineMetaDataContent::Subway, Color{0x008000} }, // N OSM: 7734239 WD: Q1039166 33.55, 130.3 x 33.59, 130.4
    { 284, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xcc0000} }, // Red OSM: 7734262 WD: Q1369034 24.98, 55.09 x 25.27, 55.39
    { 480, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x00cc00} }, // Green OSM: 7734263 WD: Q1544621 25.22, 55.29 x 25.28, 55.4
    { 314, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xffc0cb} }, // S OSM: 7734268 WD: Q16240707 21.33, 39.87 x 21.42, 39.98
    { 55, 18851, 18876, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 7734272 WD: Q1473986 43.22, 76.84 x 43.27, 76.95
    { 16, 18898, 18898, LineMetaDataContent::Subway, Color{0x008000} }, // 2 OSM: 7734279 WD: Q712790 39.03, 125.7 x 39.07, 125.8
    { 55, 18898, 18898, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 7734280 WD: Q711112 39.01, 125.7 x 39.07, 125.8
    { 55, 18930, 17569, LineMetaDataContent::Subway, Color{0xff0f04} }, // 1 OSM: 7735256 WD: Q20110118 35.4, 51.15 x 35.8, 51.44
    { 55, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x259b24} }, // 1 OSM: 7740660 WD: Q19856263 26.5, 106.6 x 26.66, 106.7
    { 2960, 16715, 3199, LineMetaDataContent::RapidTransit, Color{0x7b4339} }, // ODEA OSM: 7747967 WD: Q93386 48.88, 2.345 x 48.94, 2.358
    { 2965, 16715, 3199, LineMetaDataContent::RapidTransit, Color{0x7b4339} }, // ADEO OSM: 7747968 WD: Q93386 48.88, 2.345 x 48.94, 2.358
    { 2970, 16715, 3199, LineMetaDataContent::RapidTransit, Color{0x7b4339} }, // VOBA OSM: 7747969 WD: Q93386 48.88, 2.345 x 48.94, 2.358
    { 2975, 16715, 3199, LineMetaDataContent::RapidTransit, Color{0x7b4339} }, // AVOL OSM: 7747970 WD: Q93386 48.88, 2.345 x 48.94, 2.358
    { 2980, 16715, 3199, LineMetaDataContent::RapidTransit, Color{0x7b4339} }, // APOR OSM: 7747972 WD: Q93386 48.88, 2.345 x 48.94, 2.358
    { 211, 18954, NoLogo, LineMetaDataContent::Tramway, Color{0x64318f} }, // T1 OSM: 7758458 WD: Q50319281 49.59, 6.119 x 49.64, 6.176
    { 59, 18974, 17569, LineMetaDataContent::Subway, Color{0x00aad4} }, // 3 OSM: 7770934 WD: Q20110120 35.63, 51.34 x 35.8, 51.52
    { 2985, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00afad} }, // B-L OSM: 7772561 51.46, -0.08835 x 51.51, -0.009527
    { 2989, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00afad} }, // B-WA OSM: 7772562 51.49, -0.08835 x 51.51, 0.07755
    { 2994, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00afad} }, // S-L OSM: 7772563 51.46, -0.02287 x 51.54, -0.004134
    { 2998, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00afad} }, // TG-B OSM: 7772565 51.51, -0.07453 x 51.51, 0.07189
    { 3003, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00afad} }, // SI-WA OSM: 7772566 51.49, -0.01336 x 51.55, 0.07755
    { 1198, NoLogo, 8310, LineMetaDataContent::Subway, Color{0xbc1725} }, // M3 OSM: 7772846 WD: Q2735258 44.41, 25.98 x 44.44, 26.21
    { 265, NoLogo, 8310, LineMetaDataContent::Subway, Color{0xffff00} }, // M1 OSM: 7772847 WD: Q2056949 44.41, 26.04 x 44.45, 26.2
    { 3009, 18998, NoLogo, LineMetaDataContent::LongDistanceTrain, Color{0xe43d2e} }, // IC 1 OSM: 7778963 WD: Q115929517 46.21, 6.099 x 47.51, 9.371
    { 3014, 19012, NoLogo, LineMetaDataContent::LongDistanceTrain, Color{0xf7941d} }, // IC 5 OSM: 7778977 WD: Q115932346 46.21, 6.099 x 47.51, 9.511
    { 3019, 19026, NoLogo, LineMetaDataContent::LongDistanceTrain, Color{0x8781bd} }, // IC 2 OSM: 7779154 WD: Q115932323 46, 8.496 x 47.38, 9.042
    { 3024, 19040, NoLogo, LineMetaDataContent::LongDistanceTrain, Color{0x00984a} }, // IC 3 OSM: 7779203 WD: Q115932338 46.85, 7.587 x 47.55, 9.562
    { 72, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xb56631} }, // 21 OSM: 7779520 WD: Q1432090 59.34, 18.1 x 59.36, 18.23
    { 389, 19054, 19084, LineMetaDataContent::Subway, Color{0x008000} }, // L1 OSM: 7781389 WD: Q2668472 37.33, -6.052 x 37.38, -5.934
    { 393, 19118, 19137, LineMetaDataContent::RapidTransit, Color{0x173ba0} }, // L2 OSM: 7781442 WD: Q5986162 36.68, -4.458 x 36.72, -4.43
    { 389, 19171, 19137, LineMetaDataContent::RapidTransit, Color{0xe60000} }, // L1 OSM: 7781445 WD: Q5392889 36.71, -4.496 x 36.72, -4.423
    { 346, 19190, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe93324} }, // M2 OSM: 7781535 WD: Q11180785 39.58, 2.654 x 39.63, 2.725
    { 265, 19209, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf1b03e} }, // M1 OSM: 7781536 WD: Q5985887 39.58, 2.648 x 39.63, 2.673
    { 3029, 19228, NoLogo, LineMetaDataContent::LongDistanceTrain, Color{0xb01116} }, // IC 51 OSM: 7782231 WD: Q115932401 47.13, 7.239 x 47.55, 7.619
    { 3035, 19243, NoLogo, LineMetaDataContent::LongDistanceTrain, Color{0xffc80b} }, // IC 21 OSM: 7782364 WD: Q115932392 46, 7.587 x 47.55, 9.042
    { 3041, 19258, NoLogo, LineMetaDataContent::LongDistanceTrain, Color{0xaf8889} }, // IR 26 OSM: 7782601 WD: Q115987448 46.19, 7.586 x 47.55, 9.042
    { 3047, 19273, NoLogo, LineMetaDataContent::LongDistanceTrain, Color{0x5b6e25} }, // IR 27 OSM: 7782646 WD: Q115987465 47.04, 7.586 x 47.55, 8.311
    { 16, 19288, 19288, LineMetaDataContent::Subway, Color{0x008000} }, // 2 OSM: 7786077 WD: Q2210273 41.72, 44.72 x 41.73, 44.8
    { 55, NoLogo, 19288, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 7786078 WD: Q340562 41.68, 44.78 x 41.79, 44.87
    { 363, 19311, 19311, LineMetaDataContent::RapidTransit, Color{0xffff00} }, // E OSM: 7786518 WD: Q1714062 50.4, 30.39 x 50.5, 30.64
    { 16, 19341, 19361, LineMetaDataContent::Subway, Color{0xed1d24} }, // 2 OSM: 7786752 WD: Q3238802 50.62, 2.974 x 50.74, 3.181
    { 55, 19387, 19361, LineMetaDataContent::Subway, Color{0xffd400} }, // 1 OSM: 7786754 WD: Q3238658 50.61, 3.036 x 50.64, 3.143
    { 3053, 19407, NoLogo, LineMetaDataContent::LongDistanceTrain, Color{} }, // IR 75 OSM: 7787427 WD: Q116053272 47.04, 8.286 x 47.66, 9.192
    { 3059, 19422, NoLogo, LineMetaDataContent::LongDistanceTrain, Color{0x006d8b} }, // IR 46 OSM: 7787446 WD: Q116052876 46.66, 7.907 x 47.38, 8.674
    { 3065, 19437, NoLogo, LineMetaDataContent::LongDistanceTrain, Color{} }, // IR 70 OSM: 7787497 WD: Q116053265 47.04, 8.286 x 47.45, 8.593
    { 3071, 19452, NoLogo, LineMetaDataContent::LongDistanceTrain, Color{0x8dc63f} }, // IC 6 OSM: 7791233 WD: Q115932382 46.29, 7.434 x 47.55, 7.991
    { 3076, 19466, NoLogo, LineMetaDataContent::LongDistanceTrain, Color{0xef59a1} }, // IC 61 OSM: 7791339 WD: Q115932445 46.65, 7.434 x 47.55, 7.918
    { 3083, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x90ee90} }, // 2B OSM: 7792472 WD: Q3832656 40.38, 49.85 x 40.38, 49.87
    { 55, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 7792473 WD: Q3832654 40.37, 49.83 x 40.42, 49.95
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x008000} }, // 2 OSM: 7792474 WD: Q3832656 40.37, 49.8 x 40.43, 49.95
    { 59, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x800080} }, // 3 OSM: 7792475 WD: Q25547220 40.4, 49.78 x 40.43, 49.82
    { 55, 19481, 16926, LineMetaDataContent::Subway, Color{0x007448} }, // 1 OSM: 7792528 WD: Q200310 36.32, 127.3 x 36.39, 127.5
    { 3086, 19506, NoLogo, LineMetaDataContent::LongDistanceTrain, Color{0x11b895} }, // IR 15 OSM: 7793337 WD: Q115973525 46.21, 6.099 x 47.31, 8.311
    { 3092, 19521, NoLogo, LineMetaDataContent::LongDistanceTrain, Color{0xb8da89} }, // IR 37 OSM: 7793439 WD: Q116052863 47.35, 7.585 x 47.55, 8.684
    { 3098, 19536, NoLogo, LineMetaDataContent::LocalTrain, Color{0x5c64b8} }, // RB 43 OSM: 7793791 WD: Q84429153 51.58, 13.24 x 52.34, 14.73
    { 3104, 19556, NoLogo, LineMetaDataContent::LongDistanceTrain, Color{0xa07032} }, // IR 16 OSM: 7794142 WD: Q115987375 46.95, 7.434 x 47.49, 8.539
    { 3110, 19571, NoLogo, LineMetaDataContent::LongDistanceTrain, Color{0xad227a} }, // IR 36 OSM: 7794220 WD: Q116052855 47.38, 7.585 x 47.57, 8.566
    { 3116, 19586, NoLogo, LineMetaDataContent::LongDistanceTrain, Color{0x25539c} }, // IR 17 OSM: 7795137 WD: Q115987430 46.95, 7.433 x 47.35, 7.908
    { 3122, 19601, NoLogo, LineMetaDataContent::LongDistanceTrain, Color{0x007ca3} }, // IR 90 OSM: 7796313 WD: Q115973464 46.11, 6.099 x 46.54, 7.988
    { 1851, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0xf58220} }, // S19 OSM: 7800298 WD: Q25352054 47.37, 8.227 x 47.6, 8.787
    { 3128, NoLogo, 392, LineMetaDataContent::RapidTransit, Color{0xffd503} }, // U29 OSM: 7801954 WD: Q106879574 48.77, 9.122 x 48.78, 9.182
    { 3132, NoLogo, 392, LineMetaDataContent::RapidTransit, Color{0x69be51} }, // U34 OSM: 7801962 WD: Q106879575 48.76, 9.143 x 48.78, 9.178
    { 3136, 19616, 226, LineMetaDataContent::RapidTransit, Color{0xf17f1a} }, // S 9 OSM: 7805411 WD: Q63217750 51.45, 11.98 x 51.52, 12.64
    { 3140, 19641, NoLogo, LineMetaDataContent::LocalTrain, Color{0xda6ba2} }, // RB24 OSM: 7814259 WD: Q67993390 51.53, 13.4 x 52.84, 14.06
    { 61, NoLogo, 19661, LineMetaDataContent::RapidTransit, Color{0xf39100} }, // S1 OSM: 7819263 WD: Q110265543 46.52, 6.517 x 46.81, 6.654
    { 385, 19677, 19700, LineMetaDataContent::Subway, Color{0x824100} }, // L4 OSM: 7827780 WD: Q1826677 40.42, -3.716 x 40.48, -3.635
    { 389, 19720, 19700, LineMetaDataContent::Subway, Color{0x67c0dd} }, // L1 OSM: 7831481 WD: Q1826675 40.36, -3.706 x 40.48, -3.591
    { 16, 19743, 17569, LineMetaDataContent::Subway, Color{0x003380} }, // 2 OSM: 7832325 WD: Q20110119 35.69, 51.33 x 35.74, 51.55
    { 3145, 19767, 19700, LineMetaDataContent::Subway, Color{0x015396} }, // L10 OSM: 7834660 WD: Q1760090 40.34, -3.813 x 40.56, -3.611
    { 491, NoLogo, 19791, LineMetaDataContent::Subway, Color{0x7fffd4} }, // I OSM: 7834960 WD: Q106775989 9.95, 76.28 x 10.11, 76.35
    { 1250, 19812, 19700, LineMetaDataContent::Subway, Color{0xff0080} }, // L8 OSM: 7837169 WD: Q1475527 40.44, -3.692 x 40.49, -3.572
    { 3149, 19835, 19700, LineMetaDataContent::Subway, Color{0x9c3293} }, // L9 OSM: 7837206 WD: Q1759707 40.3, -3.721 x 40.5, -3.447
    { 3152, 19858, NoLogo, LineMetaDataContent::Subway, Color{0x996633} }, // Z OSM: 7837591 WD: Q126484 40.68, -74.01 x 40.72, -73.8
    { 1238, 19884, 19700, LineMetaDataContent::Subway, Color{0x96bf0d} }, // L5 OSM: 7838614 WD: Q1568028 40.38, -3.769 x 40.46, -3.588
    { 265, 19907, 19907, LineMetaDataContent::Subway, Color{0xffa500} }, // M1 OSM: 7838818 WD: Q1577356 36.98, 35.26 x 37.05, 35.34
    { 397, 19928, 19700, LineMetaDataContent::Subway, Color{0xffdf00} }, // L3 OSM: 7838838 WD: Q1826673 40.34, -3.72 x 40.44, -3.692
    { 393, 19951, 19700, LineMetaDataContent::Subway, Color{0xfb0f0c} }, // L2 OSM: 7838963 WD: Q1826679 40.42, -3.71 x 40.45, -3.602
    { 1246, 19974, 19700, LineMetaDataContent::Subway, Color{0xed7b24} }, // L7 OSM: 7840623 WD: Q1826683 40.42, -3.727 x 40.5, -3.524
    { 459, 19997, 19700, LineMetaDataContent::Subway, Color{0xffffff} }, // R OSM: 7840747 WD: Q1496137 40.42, -3.72 x 40.42, -3.71
    { 1565, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xe542de} }, // Purple OSM: 7841332 WD: Q7261433 12.91, 77.47 x 13, 77.76
    { 2510, 20019, 19700, LineMetaDataContent::Subway, Color{0xa49a00} }, // L12 OSM: 7841412 WD: Q1558864 40.28, -3.876 x 40.35, -3.71
    { 55, 20043, NoLogo, LineMetaDataContent::Subway, Color{0xf03b3f} }, // 1 OSM: 7841834 WD: Q11085985 31.44, 120.3 x 31.68, 120.3
    { 16, 20068, NoLogo, LineMetaDataContent::Subway, Color{0x00a43c} }, // 2 OSM: 7841837 WD: Q11085986 31.55, 120.2 x 31.61, 120.5
    { 55, NoLogo, 20093, LineMetaDataContent::Subway, Color{0xe53e30} }, // 1 OSM: 7841839 WD: Q30326155 38.04, 114.4 x 38.16, 114.6
    { 59, NoLogo, 20093, LineMetaDataContent::Subway, Color{0x00a1e0} }, // 3 OSM: 7841854 WD: Q30326157 38, 114.4 x 38.08, 114.7
    { 55, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x00b04f} }, // 1 OSM: 7841881 WD: Q17498765 22.82, 108.2 x 22.84, 108.4
    { 1242, 20116, 19700, LineMetaDataContent::Subway, Color{0x939393} }, // L6 OSM: 7842094 WD: Q514227 40.39, -3.746 x 40.45, -3.668
    { 2001, 20139, 19700, LineMetaDataContent::Subway, Color{0x006400} }, // L11 OSM: 7842127 WD: Q608251 40.36, -3.778 x 40.39, -3.718
    { 480, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x009933} }, // Green OSM: 7842288 WD: Q17054000 12.86, 77.5 x 13.05, 77.58
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xc32a05} }, // 2 OSM: 7844345 WD: Q11149384 36.06, 120.3 x 36.17, 120.5
    { 16, NoLogo, 20163, LineMetaDataContent::Subway, Color{0x53b848} }, // 2 OSM: 7845614 WD: Q20647027 12.99, 80.19 x 13.09, 80.27
    { 179, 20186, NoLogo, LineMetaDataContent::Subway, Color{0xc09c83} }, // 17 OSM: 7845847 WD: Q6553108 31.1, 121 x 31.2, 121.3
    { 16, 20207, 16926, LineMetaDataContent::Subway, Color{0x18be00} }, // 2 OSM: 7845969 WD: Q200332 35.83, 128.4 x 35.87, 128.8
    { 55, 20230, 16926, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 7845971 WD: Q200331 35.8, 128.5 x 35.89, 128.7
    { 16, 20253, NoLogo, LineMetaDataContent::Subway, Color{0xfff100} }, // 2 OSM: 7846276 WD: Q15908164 34.66, 113.6 x 34.87, 113.7
    { 3154, 20272, 20296, LineMetaDataContent::RapidTransit, Color{0x4682b4} }, // ML1 OSM: 7849381 WD: Q2058921 40.48, -3.669 x 40.51, -3.651
    { 3158, 20322, 20296, LineMetaDataContent::RapidTransit, Color{0x660066} }, // ML2 OSM: 7853073 WD: Q3832710 40.4, -3.812 x 40.45, -3.775
    { 3162, 20346, 20296, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // ML3 OSM: 7853483 WD: Q3832709 40.39, -3.905 x 40.41, -3.775
    { 3166, 20370, 16926, LineMetaDataContent::Subway, Color{0x6fa0ce} }, // I1 OSM: 7854149 WD: Q487733 37.38, 126.6 x 37.57, 126.7
    { 59, 20395, NoLogo, LineMetaDataContent::Tramway, Color{0xb5ba05} }, // 3 OSM: 7857250 WD: Q1888831 50.81, 4.336 x 50.9, 4.377
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x02406f} }, // 2 OSM: 7857258 WD: Q10318650 -12.98, -38.48 x -12.9, -38.34
    { 3169, 13709, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa6c82b} }, // R2Nord OSM: 7867878 WD: Q1880046 41.3, 2.052 x 41.77, 2.673
    { 3176, 20416, NoLogo, LineMetaDataContent::RapidTransit, Color{0xba55d3} }, // R7 OSM: 7867903 WD: Q1647981 41.43, 2.115 x 41.51, 2.189
    { 3179, NoLogo, 20433, LineMetaDataContent::Subway, Color{0xff0000} }, // B1 OSM: 7868621 WD: Q56067295 40.19, 28.95 x 40.26, 29.12
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xf30215} }, // 2 OSM: 7869228 WD: Q5934457 34.14, 108.9 x 34.38, 108.9
    { 55, 20451, NoLogo, LineMetaDataContent::Subway, Color{0x01abf7} }, // 1 OSM: 7869253 WD: Q14917524 34.27, 108.7 x 34.32, 109.1
    { 59, 20471, NoLogo, LineMetaDataContent::Subway, Color{0xb688a9} }, // 3 OSM: 7869255 WD: Q15927288 34.22, 108.8 x 34.41, 109.1
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xd9001c} }, // 2 OSM: 7869334 WD: Q104231524 -8.111, -35.02 x -8.069, -34.89
    { 55, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xe77405} }, // 1 OSM: 7869352 WD: Q104231463 -8.092, -35 x -8.024, -34.89
    { 2310, 20491, NoLogo, LineMetaDataContent::Subway, Color{0x1a5ba3} }, // Sul OSM: 7869374 WD: Q10329288 -8.168, -34.93 x -8.069, -34.88
    { 3182, NoLogo, 20433, LineMetaDataContent::Subway, Color{0x000000} }, // B2 OSM: 7869622 WD: Q61074931 40.19, 28.87 x 40.22, 29.21
    { 55, 20504, NoLogo, LineMetaDataContent::Subway, Color{0xe60012} }, // 1 OSM: 7871046 WD: Q15303225 34.75, 113.5 x 34.83, 113.8
    { 132, 20523, NoLogo, LineMetaDataContent::Subway, Color{0xa2ae73} }, // 9 OSM: 7871541 WD: Q28441548 34.53, 113.7 x 34.66, 113.9
    { 3185, 20543, NoLogo, LineMetaDataContent::RapidTransit, Color{0x8fbe00} }, // C-10 OSM: 7871793 WD: Q583732 40.4, -4.009 x 40.63, -3.594
    { 486, 20562, NoLogo, LineMetaDataContent::RapidTransit, Color{0x009ad5} }, // C-1 OSM: 7871905 WD: Q3832674 40.4, -3.722 x 40.49, -3.593
    { 3190, 20580, NoLogo, LineMetaDataContent::RapidTransit, Color{0xde0118} }, // C-7 OSM: 7872150 WD: Q8879938 40.38, -3.874 x 40.51, -3.365
    { 284, 20592, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // Red OSM: 7874288 WD: Q152039 42.21, -71.14 x 42.4, -71
    { 1334, 20618, NoLogo, LineMetaDataContent::Subway, Color{0xff8000} }, // Orange OSM: 7874312 WD: Q152029 42.3, -71.12 x 42.44, -71.06
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 1 OSM: 7874579 52.26, 104.3 x 52.29, 104.3
    { 16, 20647, NoLogo, LineMetaDataContent::Subway, Color{0x00afec} }, // 2 OSM: 7875250 WD: Q15919822 28.15, 112.9 x 28.21, 113.1
    { 55, 20677, NoLogo, LineMetaDataContent::Subway, Color{0xe60012} }, // 1 OSM: 7875257 WD: Q15911087 28.06, 113 x 28.27, 113
    { 3194, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 4a OSM: 7875273 52.28, 104.3 x 52.29, 104.4
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 4 OSM: 7875274 52.28, 104.3 x 52.29, 104.4
    { 9, 20707, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7d4697} }, // 4 OSM: 7875301 WD: Q6553125 43.75, 125.3 x 43.91, 125.4
    { 59, 20728, NoLogo, LineMetaDataContent::RapidTransit, Color{0x009943} }, // 3 OSM: 7875360 WD: Q6123656 43.77, 125.3 x 43.91, 125.4
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x4bc7df} }, // 2 OSM: 7875923 52.27, 104.3 x 52.29, 104.3
    { 524, 20749, 20766, LineMetaDataContent::Subway, Color{0x056d2e} }, // A OSM: 7877753 WD: Q770771 39.92, 32.81 x 39.93, 32.88
    { 265, NoLogo, 20766, LineMetaDataContent::Subway, Color{0xbf0e1c} }, // M1 OSM: 7877773 WD: Q21526526 39.92, 32.73 x 39.97, 32.86
    { 346, NoLogo, 20766, LineMetaDataContent::Subway, Color{0xbf0e1c} }, // M2 OSM: 7877891 WD: Q21526527 39.88, 32.68 x 39.92, 32.86
    { 307, 20788, NoLogo, LineMetaDataContent::Subway, Color{0xffa500} }, // O OSM: 7879290 WD: Q7099668 22.62, 120.3 x 22.63, 120.4
    { 459, 20828, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // R OSM: 7879291 WD: Q7304504 22.56, 120.3 x 22.78, 120.4
    { 59, 20865, 16926, LineMetaDataContent::Subway, Color{0xfe5b10} }, // 3 OSM: 7879839 WD: Q20393 37.48, 126.7 x 37.68, 127.1
    { 6, 20888, 16926, LineMetaDataContent::Subway, Color{0x996cac} }, // 5 OSM: 7879871 WD: Q92530 37.49, 126.8 x 37.58, 127.2
    { 59, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x006dbb} }, // 3 OSM: 7883242 WD: Q15907883 36.05, 120.3 x 36.17, 120.4
    { 132, 20911, 16926, LineMetaDataContent::Subway, Color{0xaa9872} }, // 9 OSM: 7883317 WD: Q17503 37.5, 126.8 x 37.58, 127.1
    { 16, 20934, NoLogo, LineMetaDataContent::Subway, Color{0xd60e19} }, // 2 OSM: 7883944 WD: Q10946021 29.81, 121.5 x 29.95, 121.7
    { 55, 20955, 2400, LineMetaDataContent::Subway, Color{0xffff00} }, // 1 OSM: 7884489 WD: Q54369 43.65, -79.53 x 43.79, -79.38
    { 55, 21004, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 7885089 WD: Q56277837 40.59, 22.93 x 40.65, 22.97
    { 16, 21034, 2400, LineMetaDataContent::Subway, Color{0x008000} }, // 2 OSM: 7885287 WD: Q54371 43.64, -79.54 x 43.73, -79.26
    { 59, NoLogo, 10680, LineMetaDataContent::Subway, Color{0x009651} }, // 3 OSM: 7885547 WD: Q10906683 31.87, 118.7 x 32.17, 118.8
    { 3197, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x77278b} }, // WCE OSM: 7887557 49.13, -123.1 x 49.29, -122.3
    { 3201, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x000000} }, // Conexão Metrô-Aeroporto OSM: 7889062 WD: Q23891467 -29.99, -51.18 x -29.99, -51.18
    { 55, 21073, NoLogo, LineMetaDataContent::Subway, Color{0x5cb439} }, // 1 OSM: 7889178 WD: Q45668 31.28, 120.5 x 31.33, 120.8
    { 3227, 21083, 21097, LineMetaDataContent::Subway, Color{0x808080} }, // RMGL OSM: 7890003 WD: Q7294170 28.42, 77.09 x 28.5, 77.11
    { 55, 21118, NoLogo, LineMetaDataContent::Subway, Color{0xfec04f} }, // 1 OSM: 7890223 WD: Q5985916 25.68, -100.4 x 25.76, -100.2
    { 16, 21132, NoLogo, LineMetaDataContent::Subway, Color{0x6bc069} }, // 2 OSM: 7890224 WD: Q2842186 25.67, -100.3 x 25.77, -100.3
    { 16, 21146, NoLogo, LineMetaDataContent::Subway, Color{0x0066a1} }, // 2 OSM: 7890240 WD: Q6379343 38.9, 121.5 x 39.02, 121.7
    { 314, 3565, NoLogo, LineMetaDataContent::Subway, Color{0x808183} }, // S OSM: 7893704 WD: Q126772 40.58, -73.84 x 40.61, -73.81
    { 314, 21166, NoLogo, LineMetaDataContent::Subway, Color{0x808183} }, // S OSM: 7894362 WD: Q126725 40.66, -73.96 x 40.68, -73.96
    { 55, 21193, NoLogo, LineMetaDataContent::Subway, Color{0xb63f1f} }, // 1 OSM: 7894481 WD: Q5934658 41.76, 123.2 x 41.81, 123.5
    { 16, 21213, NoLogo, LineMetaDataContent::Subway, Color{0xe5703a} }, // 2 OSM: 7894597 WD: Q5933526 41.63, 123.4 x 41.96, 123.5
    { 55, 21244, NoLogo, LineMetaDataContent::Subway, Color{0xeb212f} }, // 1 OSM: 7895188 WD: Q15941872 25.98, 119.3 x 26.15, 119.4
    { 58, 21263, NoLogo, LineMetaDataContent::Subway, Color{0x8e8c13} }, // 13 OSM: 7895357 WD: Q6553065 23.08, 113.4 x 23.14, 113.6
    { 16, 21284, NoLogo, LineMetaDataContent::Subway, Color{0x0070ff} }, // 2 OSM: 7898299 WD: Q56277844 40.57, 22.93 x 40.65, 22.97
    { 59, 21314, NoLogo, LineMetaDataContent::Subway, Color{0xdd00bb} }, // 3 OSM: 7908058 WD: Q5976456 38.92, 121.6 x 39.15, 122
    { 16, 21334, NoLogo, LineMetaDataContent::Subway, Color{0x0000ff} }, // 2 OSM: 7909740 WD: Q11087464 25.03, 102.7 x 25.12, 102.8
    { 55, 21354, NoLogo, LineMetaDataContent::Subway, Color{0xdb372b} }, // 1 OSM: 7909748 WD: Q11087462 24.83, 102.7 x 25.03, 102.9
    { 61, 21374, 10680, LineMetaDataContent::Subway, Color{0x4bbbb4} }, // S1 OSM: 7913272 WD: Q10946118 31.72, 118.8 x 31.97, 118.9
    { 166, 21395, 10680, LineMetaDataContent::Subway, Color{0xda60cd} }, // S3 OSM: 7913273 WD: Q10945835 31.91, 118.5 x 31.99, 118.8
    { 55, 21416, NoLogo, LineMetaDataContent::Subway, Color{0x00ab39} }, // 1 OSM: 7913936 WD: Q842103 22.53, 113.8 x 22.65, 114.1
    { 524, 21439, 16926, LineMetaDataContent::Subway, Color{0x3681b7} }, // A OSM: 7919001 WD: Q487643 37.44, 126.4 x 37.6, 127
    { 19, 21465, 16926, LineMetaDataContent::Subway, Color{0xea545d} }, // 8 OSM: 7919019 WD: Q45086 37.43, 127.1 x 37.55, 127.2
    { 27, 21488, 16926, LineMetaDataContent::Subway, Color{0x9e4510} }, // 6 OSM: 7919154 WD: Q92549 37.53, 126.9 x 37.62, 127.1
    { 318, NoLogo, 21511, LineMetaDataContent::Subway, Color{0x00a651} }, // M OSM: 7919553 WD: Q106336770 39.29, -76.78 x 39.41, -76.59
    { 2982, 21566, 17060, LineMetaDataContent::Subway, Color{0xe89038} }, // OR OSM: 7919601 WD: Q4715683 38.88, -77.28 x 38.95, -76.87
    { 3232, 21583, 17060, LineMetaDataContent::Subway, Color{0xe94333} }, // RD OSM: 7919630 WD: Q2193330 38.89, -77.17 x 39.12, -76.99
    { 3235, 21597, 17060, LineMetaDataContent::Subway, Color{0xc0c0c0} }, // SV OSM: 7919737 WD: Q4711838 38.88, -77.49 x 39.01, -76.84
    { 3238, 21614, 17060, LineMetaDataContent::Subway, Color{0x0000ff} }, // BL OSM: 7919758 WD: Q2602185 38.77, -77.17 x 38.9, -76.84
    { 3241, 21629, 17060, LineMetaDataContent::Subway, Color{0x008000} }, // GR OSM: 7919786 WD: Q4715207 38.83, -77.03 x 39.01, -76.91
    { 42, 21645, 16926, LineMetaDataContent::Subway, Color{0x54640d} }, // 7 OSM: 7922930 WD: Q22910 37.48, 126.7 x 37.7, 127.1
    { 480, NoLogo, 21668, LineMetaDataContent::Subway, Color{0x62bb46} }, // Green OSM: 7924527 WD: Q55734262 25.68, -80.32 x 25.85, -80.2
    { 1334, NoLogo, 21668, LineMetaDataContent::Subway, Color{0xf78f1e} }, // Orange OSM: 7924528 WD: Q55734269 25.68, -80.31 x 25.81, -80.2
    { 1028, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009832} }, // D OSM: 7925628 WD: Q3239098 48.57, 7.691 x 48.59, 7.816
    { 311, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf29400} }, // C OSM: 7925656 WD: Q2321331 48.55, 7.735 x 48.59, 7.773
    { 27, 21707, 15642, LineMetaDataContent::Subway, Color{0x0066a3} }, // 6 OSM: 7927182 WD: Q668977 50.83, 4.321 x 50.9, 4.37
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff7000} }, // 2 OSM: 7927236 WD: Q5017773 29.98, 31.2 x 30.12, 31.25
    { 393, 21728, 21749, LineMetaDataContent::Subway, Color{0x00dc3c} }, // L2 OSM: 7927568 WD: Q5986160 10.43, -67.01 x 10.51, -66.92
    { 397, 21768, 21749, LineMetaDataContent::Subway, Color{0x0887ff} }, // L3 OSM: 7927573 WD: Q21346332 10.43, -66.94 x 10.5, -66.88
    { 3244, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // L1B OSM: 7928119 WD: Q107191177 37.99, -1.187 x 38.01, -1.161
    { 55, 21789, NoLogo, LineMetaDataContent::Subway, Color{0xf04e98} }, // 1 OSM: 7935038 WD: Q2295084 19.4, -99.2 x 19.43, -99.07
    { 311, 21810, NoLogo, LineMetaDataContent::RapidTransit, Color{0x58a738} }, // C OSM: 7935053 WD: Q2482571 33.89, -118.4 x 33.93, -118.1
    { 1028, 21835, NoLogo, LineMetaDataContent::Subway, Color{0xa05da5} }, // D OSM: 7935318 WD: Q3916689 34.05, -118.3 x 34.06, -118.2
    { 9, 21860, NoLogo, LineMetaDataContent::Subway, Color{0x80ffff} }, // 4 OSM: 7935352 WD: Q2837181 19.4, -99.12 x 19.49, -99.1
    { 6, 21881, NoLogo, LineMetaDataContent::Subway, Color{0xffff11} }, // 5 OSM: 7935366 WD: Q1152238 19.41, -99.15 x 19.5, -99.07
    { 15, 21902, NoLogo, LineMetaDataContent::Subway, Color{0xb69764} }, // 12 OSM: 7935368 WD: Q5985548 19.28, -99.2 x 19.38, -99.01
    { 42, 21924, NoLogo, LineMetaDataContent::Subway, Color{0xff8000} }, // 7 OSM: 7935375 WD: Q929645 19.36, -99.2 x 19.51, -99.19
    { 524, 21945, NoLogo, LineMetaDataContent::Subway, Color{0xa3277d} }, // A OSM: 7935382 WD: Q3239049 19.35, -99.07 x 19.42, -98.96
    { 19, 21966, NoLogo, LineMetaDataContent::Subway, Color{0x30c090} }, // 8 OSM: 7935426 WD: Q1149545 19.35, -99.14 x 19.45, -99.06
    { 196, 21987, NoLogo, LineMetaDataContent::Subway, Color{0x408080} }, // B OSM: 7935433 WD: Q3239062 19.43, -99.16 x 19.53, -99.03
    { 16, 22008, NoLogo, LineMetaDataContent::Subway, Color{0x0080ff} }, // 2 OSM: 7935439 WD: Q1152993 19.34, -99.22 x 19.46, -99.13
    { 132, 22029, NoLogo, LineMetaDataContent::Subway, Color{0x804000} }, // 9 OSM: 7935444 WD: Q3239046 19.4, -99.19 x 19.42, -99.06
    { 59, 22050, NoLogo, LineMetaDataContent::Subway, Color{0xae9d27} }, // 3 OSM: 7935449 WD: Q945935 19.32, -99.18 x 19.5, -99.12
    { 27, 22071, NoLogo, LineMetaDataContent::Subway, Color{0xe00050} }, // 6 OSM: 7935454 WD: Q3238990 19.48, -99.2 x 19.51, -99.1
    { 3248, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xdb5450} }, // PATCO OSM: 7939445 39.83, -75.17 x 39.96, -75
    { 2119, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x233e99} }, // WTR OSM: 7940934 WD: Q7986701 39.95, -75.18 x 40.26, -74.82
    { 2665, NoLogo, 22092, LineMetaDataContent::Subway, Color{0xef3941} }, // NWK–WTC OSM: 7943869 WD: Q2673356 40.71, -74.16 x 40.74, -74.01
    { 3254, 22101, 22092, LineMetaDataContent::Subway, Color{0x009e58} }, // HOB–WTC OSM: 7943874 WD: Q2789573 40.71, -74.04 x 40.74, -74.01
    { 3264, NoLogo, 22092, LineMetaDataContent::Subway, Color{0x0082c6} }, // HOB–33 OSM: 7943885 WD: Q2319374 40.73, -74.03 x 40.75, -73.99
    { 3273, NoLogo, 22092, LineMetaDataContent::Subway, Color{0xfdb827} }, // JSQ–33 OSM: 7943962 WD: Q4993433 40.72, -74.06 x 40.75, -73.99
    { 55, 22115, NoLogo, LineMetaDataContent::Subway, Color{0xe77405} }, // 1 OSM: 7944061 WD: Q2333617 -22.98, -43.24 x -22.9, -43.17
    { 3282, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x999e9e} }, // VLT Curado-Cajueiro Seco OSM: 7945216 WD: Q18473919 -8.177, -34.99 x -8.075, -34.93
    { 55, 22139, NoLogo, LineMetaDataContent::Subway, Color{0xc8102e} }, // 1 OSM: 7948593 WD: Q10921992 45.6, 126.6 x 45.79, 126.7
    { 59, 22163, NoLogo, LineMetaDataContent::Subway, Color{0xffc72c} }, // 3 OSM: 7949019 WD: Q10921994 45.69, 126.5 x 45.78, 126.7
    { 55, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xf50000} }, // 1 OSM: 7949047 WD: Q10916959 31.69, 117.3 x 31.89, 117.3
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x006bfa} }, // 2 OSM: 7949335 WD: Q10916960 31.85, 117.1 x 31.87, 117.4
    { 55, 22187, NoLogo, LineMetaDataContent::Subway, Color{0xe50011} }, // 1 OSM: 7949339 WD: Q15913092 43.79, 125.3 x 43.95, 125.3
    { 3307, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xf58220} }, // BSL OSM: 7950670 WD: Q837022 39.91, -75.17 x 40.04, -75.14
    { 55, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x42b227} }, // 1 OSM: 7951024 WD: Q6379309 38.84, 121.5 x 39.02, 121.6
    { 3311, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0066ff} }, // MFL OSM: 7953598 WD: Q823251 39.95, -75.26 x 40.02, -75.08
    { 3315, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x84388a} }, // NHSL OSM: 7953621 WD: Q2205806 39.96, -75.35 x 40.11, -75.26
    { 15, 22207, NoLogo, LineMetaDataContent::Subway, Color{0x523e98} }, // 12 OSM: 7957874 WD: Q10938157 38.8, 121.1 x 38.86, 121.5
    { 3320, 22228, 7873, LineMetaDataContent::Subway, Color{0x007a33} }, // Μ1 OSM: 7963514 WD: Q6553095 37.94, 23.64 x 38.07, 23.81
    { 3324, 22252, 7873, LineMetaDataContent::Subway, Color{0xda291c} }, // Μ2 OSM: 7963569 WD: Q9295813 37.89, 23.69 x 38.02, 23.75
    { 459, 22276, NoLogo, LineMetaDataContent::Subway, Color{0x2d3087} }, // R OSM: 7963671 WD: Q225095 35.61, 139.7 x 35.65, 139.8
    { 55, NoLogo, 22299, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 7963913 WD: Q30750331 40.14, 44.47 x 40.2, 44.52
    { 19, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x9dabaa} }, // 8 OSM: 7964884 WD: Q11124525 30.43, 114.3 x 30.68, 114.4
    { 3328, 22317, 20296, LineMetaDataContent::Tramway, Color{0x98cd37} }, // ML4 OSM: 7968999 WD: Q1637556 40.22, -3.773 x 40.25, -3.749
    { 3332, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x006400} }, // Tranvía OSM: 7981323 37.77, -3.79 x 37.81, -3.778
    { 3341, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0354a6} }, // DTL OSM: 7981644 WD: Q1663943 1.278, 103.7 x 1.413, 104
    { 3345, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x9016b2} }, // NEL OSM: 7981649 WD: Q1725116 1.265, 103.8 x 1.415, 103.9
    { 3349, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff9a00} }, // CCL OSM: 7981685 WD: Q2154003 1.265, 103.8 x 1.353, 103.9
    { 3353, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x009530} }, // EWL OSM: 7981689 WD: Q1895425 1.276, 103.6 x 1.376, 104
    { 1198, NoLogo, 20766, LineMetaDataContent::Subway, Color{0xbf0e1c} }, // M3 OSM: 7981707 WD: Q21526528 39.97, 32.55 x 39.99, 32.73
    { 8, NoLogo, 20766, LineMetaDataContent::Subway, Color{0xedaf2e} }, // M4 OSM: 7981756 WD: Q31193144 39.92, 32.84 x 40, 32.88
    { 265, NoLogo, 22341, LineMetaDataContent::Subway, Color{0x0000ff} }, // M1 OSM: 7981873 WD: Q3238655 38.39, 27.07 x 38.47, 27.23
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xed1c24} }, // 2 OSM: 7986215 WD: Q11103955 22.86, 113.7 x 23.09, 113.9
    { 3357, 22363, 22385, LineMetaDataContent::Subway, Color{0xff748c} }, // Pink Line OSM: 7989308 WD: Q17053988 26.88, 75.75 x 26.93, 75.83
    { 3367, 22407, NoLogo, LineMetaDataContent::Subway, Color{0x246b5b} }, // BTS Silom OSM: 7989387 WD: Q2634702 13.71, 100.5 x 13.75, 100.5
    { 3377, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf9c212} }, // U AVO OSM: 7993108 40.64, -8.654 x 41.15, -8.564
    { 9, 22420, NoLogo, LineMetaDataContent::Tramway, Color{0xf25482} }, // 4 OSM: 7999217 WD: Q2527775 50.79, 4.318 x 50.86, 4.363
    { 231, 22441, 7105, LineMetaDataContent::Tramway, Color{0xa12944} }, // 25 OSM: 7999338 WD: Q3238750 50.8, 4.358 x 50.87, 4.408
    { 504, 22463, 7105, LineMetaDataContent::Tramway, Color{0xf3c300} }, // 55 OSM: 7999374 WD: Q2236365 50.86, 4.358 x 50.88, 4.416
    { 605, 22485, 7105, LineMetaDataContent::Tramway, Color{0x91bee7} }, // 82 OSM: 7999733 WD: Q2534011 50.78, 4.29 x 50.87, 4.341
    { 59, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffcc00} }, // 3 OSM: 8000255 WD: Q13422345 14.54, 121 x 14.65, 121.1
    { 55, 22507, 22507, LineMetaDataContent::RapidTransit, Color{0x008000} }, // 1 OSM: 8000262 WD: Q4165607 14.53, 121 x 14.66, 121
    { 16, NoLogo, 22507, LineMetaDataContent::Subway, Color{0x800080} }, // 2 OSM: 8000265 WD: Q4165317 14.6, 121 x 14.63, 121.1
    { 3383, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfe8e10} }, // AG OSM: 8000298 WD: Q474391 3.12, 101.7 x 3.186, 101.8
    { 132, 22520, NoLogo, LineMetaDataContent::Subway, Color{0x008000} }, // 9 OSM: 8000326 WD: Q6717618 2.983, 101.6 x 3.177, 101.8
    { 3386, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x721422} }, // SP OSM: 8000405 WD: Q474391 2.994, 101.6 x 3.186, 101.7
    { 234, 22541, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe0115f} }, // KJ OSM: 8000461 WD: Q248445 2.996, 101.6 x 3.231, 101.7
    { 39, 22562, 22586, LineMetaDataContent::Subway, Color{0xff8c00} }, // T OSM: 8000572 WD: Q981826 43.03, 141.3 x 43.09, 141.5
    { 517, 22598, 22586, LineMetaDataContent::Subway, Color{0x008800} }, // N OSM: 8000575 WD: Q843793 42.99, 141.3 x 43.11, 141.4
    { 2146, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0377ae} }, // R6 OSM: 8005936 48.62, 21.19 x 48.71, 21.24
    { 3389, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x3a88bf} }, // 941 OSM: 8009538 WD: Q115756382 46.7, 9.386 x 46.98, 9.689
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x55bace} }, // 3 OSM: 8013591 48.68, 21.26 x 48.72, 21.3
    { 42, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x5cbf14} }, // 7 OSM: 8013592 48.68, 21.24 x 48.73, 21.3
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x7477b0} }, // 4 OSM: 8013593 48.68, 21.24 x 48.74, 21.27
    { 132, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf5d907} }, // 9 OSM: 8013594 48.68, 21.23 x 48.74, 21.3
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xd2005c} }, // 2 OSM: 8013595 48.72, 21.24 x 48.74, 21.27
    { 318, 22624, 22664, LineMetaDataContent::Subway, Color{0xf62e36} }, // M OSM: 8015940 WD: Q1147028 35.67, 139.6 x 35.73, 139.8
    { 3393, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x11385b} }, // 金山(Jinshan) OSM: 8019734 WD: Q3338133 30.73, 121.3 x 31.16, 121.4
    { 524, 22692, NoLogo, LineMetaDataContent::Subway, Color{0xe85298} }, // A OSM: 8019854 WD: Q720653 35.58, 139.7 x 35.71, 139.8
    { 314, 22721, NoLogo, LineMetaDataContent::Subway, Color{0x6cbb5a} }, // S OSM: 8019866 WD: Q1374502 35.65, 139.4 x 35.8, 139.9
    { 363, 22751, NoLogo, LineMetaDataContent::Subway, Color{0xb6007a} }, // E OSM: 8019893 WD: Q384862 35.65, 139.6 x 35.76, 139.8
    { 491, 22777, NoLogo, LineMetaDataContent::Subway, Color{0x0079c2} }, // I OSM: 8019914 WD: Q1374506 35.63, 139.6 x 35.79, 139.8
    { 3409, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xaacd46} }, // G44 OSM: 8021111 WD: Q101110571 47.37, 18.87 x 47.5, 19.04
    { 3413, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00aff0} }, // S506 OSM: 8021112 WD: Q111752752 47.19, 21.58 x 47.52, 21.82
    { 3418, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xaacd46} }, // G80 OSM: 8021113 WD: Q101147264 47.49, 19.08 x 47.54, 19.39
    { 3422, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xaacd46} }, // G50 OSM: 8021114 WD: Q109333265 47.17, 19.06 x 47.52, 20.18
    { 311, 22803, 22664, LineMetaDataContent::Subway, Color{0x00bb85} }, // C OSM: 8026069 WD: Q1075089 35.66, 139.7 x 35.78, 139.8
    { 517, 22840, 22664, LineMetaDataContent::Subway, Color{0x00ac9b} }, // N OSM: 8026071 WD: Q520772 35.63, 139.7 x 35.78, 139.8
    { 513, 22877, 22664, LineMetaDataContent::Subway, Color{0xff9500} }, // G OSM: 8026077 WD: Q1073046 35.66, 139.7 x 35.71, 139.8
    { 884, 22912, 22664, LineMetaDataContent::Subway, Color{0xc1a470} }, // Y OSM: 8026115 WD: Q787305 35.64, 139.6 x 35.79, 139.8
    { 39, 22953, 22664, LineMetaDataContent::Subway, Color{0x009bbf} }, // T OSM: 8026124 WD: Q1147054 35.66, 139.7 x 35.71, 140
    { 34, 22989, 22664, LineMetaDataContent::Subway, Color{0xb5b5ac} }, // H OSM: 8026149 WD: Q1196223 35.64, 139.7 x 35.75, 139.8
    { 238, 23025, 22664, LineMetaDataContent::Subway, Color{0x9c5e31} }, // F OSM: 8026161 WD: Q1332908 35.44, 139.4 x 36.05, 139.7
    { 314, 23065, NoLogo, LineMetaDataContent::Subway, Color{0xffaadd} }, // S OSM: 8028801 WD: Q1073354 34.64, 135.5 x 34.69, 135.6
    { 318, 23105, NoLogo, LineMetaDataContent::Subway, Color{0xdd0000} }, // M OSM: 8028805 WD: Q1192413 34.56, 135.5 x 34.81, 135.5
    { 491, 23142, NoLogo, LineMetaDataContent::Subway, Color{0xff9900} }, // I OSM: 8028826 WD: Q1066118 34.67, 135.5 x 34.76, 135.6
    { 447, 23182, NoLogo, LineMetaDataContent::Subway, Color{0x662211} }, // K OSM: 8028828 WD: Q1143250 34.64, 135.5 x 34.71, 135.5
    { 517, 23220, NoLogo, LineMetaDataContent::Subway, Color{0xaadd55} }, // N OSM: 8028846 WD: Q284828 34.67, 135.5 x 34.72, 135.6
    { 884, 23274, NoLogo, LineMetaDataContent::Subway, Color{0x0000ff} }, // Y OSM: 8028853 WD: Q1067748 34.61, 135.5 x 34.7, 135.5
    { 39, 23313, NoLogo, LineMetaDataContent::Subway, Color{0x540a56} }, // T OSM: 8028879 WD: Q1142773 34.6, 135.5 x 34.75, 135.6
    { 447, 23351, 23376, LineMetaDataContent::Subway, Color{0x3cb371} }, // K OSM: 8030551 WD: Q762347 34.96, 135.8 x 35.06, 135.8
    { 39, 23395, 23376, LineMetaDataContent::Subway, Color{0xff4500} }, // T OSM: 8030553 WD: Q1143898 34.93, 135.7 x 35.01, 135.8
    { 314, 23417, 17679, LineMetaDataContent::Subway, Color{0xff0000} }, // S OSM: 8030762 WD: Q1132780 35.09, 136.9 x 35.17, 137
    { 34, 23462, 17679, LineMetaDataContent::Subway, Color{0xffffcc} }, // H OSM: 8030765 WD: Q1132799 35.14, 136.9 x 35.18, 137
    { 363, 23507, 17679, LineMetaDataContent::Subway, Color{0x8f76d6} }, // E OSM: 8030779 WD: Q1045061 35.09, 136.9 x 35.14, 136.9
    { 39, 23546, 17679, LineMetaDataContent::Subway, Color{0xadd8e6} }, // T OSM: 8030785 WD: Q1043806 35.12, 136.9 x 35.22, 137
    { 318, 23588, 17679, LineMetaDataContent::Subway, Color{0x8f76d6} }, // M OSM: 8031607 WD: Q906775 35.12, 136.9 x 35.2, 137
    { 477, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe9527d} }, // S9 OSM: 8033205 41.35, 2.001 x 41.41, 2.149
    { 55, 23627, 23650, LineMetaDataContent::Subway, Color{0x0000ff} }, // 1 OSM: 8034179 WD: Q6427301 22.46, 88.34 x 22.65, 88.4
    { 55, NoLogo, 20163, LineMetaDataContent::Subway, Color{0x3281c4} }, // 1 OSM: 8037596 WD: Q19891160 12.98, 80.16 x 13.18, 80.31
    { 3426, 23680, 21097, LineMetaDataContent::Subway, Color{0x4169e1} }, // Blue Line OSM: 8037671 WD: Q1029921 28.55, 77.02 x 28.66, 77.38
    { 2590, 23703, 21097, LineMetaDataContent::Subway, Color{0x008000} }, // Green Line OSM: 8037672 WD: Q5602820 28.65, 76.91 x 28.7, 77.17
    { 3436, 23726, 21097, LineMetaDataContent::Subway, Color{0x553592} }, // Violet Line OSM: 8037706 WD: Q3634451 28.34, 77.21 x 28.67, 77.32
    { 3448, 23749, 21097, LineMetaDataContent::Subway, Color{0xffdf00} }, // Yellow Line OSM: 8037713 WD: Q795156 28.46, 77.07 x 28.75, 77.23
    { 3460, NoLogo, 21097, LineMetaDataContent::Subway, Color{0xff8c00} }, // AEx OSM: 8037716 WD: Q5253735 28.55, 77.06 x 28.64, 77.22
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xeb3d1a} }, // 2 OSM: 8040132 WD: Q21245979 22.72, 108.3 x 22.89, 108.4
    { 59, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xfe4998} }, // 3 OSM: 8040148 WD: Q11087465 24.99, 102.6 x 25.05, 102.8
    { 3464, 23772, 21097, LineMetaDataContent::Subway, Color{0xcc338b} }, // Magenta Line OSM: 8051576 WD: Q19893471 28.54, 77.08 x 28.63, 77.34
    { 132, 23795, 21097, LineMetaDataContent::Subway, Color{0x838996} }, // 9 OSM: 8051593 WD: Q47100305 28.61, 76.98 x 28.62, 77.02
    { 22, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xabd02c} }, // 18 OSM: 8054951 50.05, 14.39 x 50.11, 14.44
    { 179, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xa7c9ae} }, // 17 OSM: 8055113 50, 14.4 x 50.13, 14.46
    { 971, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xdc008f} }, // 99 OSM: 8060661 50.06, 14.3 x 50.08, 14.51
    { 924, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xdc008f} }, // 98 OSM: 8060662 50.06, 14.3 x 50.09, 14.5
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf36f42} }, // 3 OSM: 8101318 WD: Q109558673 52.29, 14.47 x 52.34, 14.56
    { 54, 23818, 4578, LineMetaDataContent::Subway, Color{0x82c0c0} }, // 11 OSM: 8119161 WD: Q617574 55.65, 37.44 x 55.8, 37.74
    { 42, 23843, NoLogo, LineMetaDataContent::LocalTrain, Color{0x139593} }, // 7 OSM: 8119877 WD: Q6151888 2.743, 101.7 x 3.134, 101.7
    { 27, 23864, NoLogo, LineMetaDataContent::LocalTrain, Color{0x800080} }, // 6 OSM: 8119880 WD: Q1431592 2.743, 101.7 x 3.134, 101.7
    { 211, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0000ff} }, // T1 OSM: 8120923 10.34, -67.04 x 10.43, -67.01
    { 53, NoLogo, 12345, LineMetaDataContent::RapidTransit, Color{0xb72841} }, // S11 OSM: 8149205 WD: Q106368746 47.98, 12.85 x 48.04, 12.93
    { 166, NoLogo, 12345, LineMetaDataContent::RapidTransit, Color{0x22b24c} }, // S3 OSM: 8149206 WD: Q106368750 47.28, 12.79 x 47.84, 13.23
    { 50, NoLogo, 12345, LineMetaDataContent::RapidTransit, Color{0x0072bc} }, // S2 OSM: 8149207 WD: Q106368749 47.81, 12.97 x 47.97, 13.27
    { 61, NoLogo, 12345, LineMetaDataContent::RapidTransit, Color{0xb72841} }, // S1 OSM: 8149208 WD: Q106368744 47.81, 12.92 x 47.99, 13.05
    { 3477, 23885, NoLogo, LineMetaDataContent::RapidTransit, Color{0x999999} }, // 浦江 OSM: 8167022 WD: Q29704153 31.03, 121.5 x 31.06, 121.5
    { 2196, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0377ae} }, // R4 OSM: 8196259 48.62, 21.19 x 48.73, 21.25
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xea7b08} }, // 6 OSM: 8196338 48.7, 21.23 x 48.73, 21.27
    { 2189, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0377ae} }, // R3 OSM: 8197830 48.62, 21.19 x 48.74, 21.25
    { 3176, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0377ae} }, // R7 OSM: 8197872 48.62, 21.19 x 48.73, 21.24
    { 537, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // T2 OSM: 8209896 WD: Q16655789 47.99, 0.1929 x 48.02, 0.2359
    { 211, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xeb001b} }, // T1 OSM: 8209897 WD: Q3239229 47.96, 0.152 x 48.02, 0.2304
    { 480, NoLogo, 2835, LineMetaDataContent::RapidTransit, Color{0x009933} }, // Green OSM: 8212097 WD: Q19960507 54.9, -1.711 x 55.04, -1.382
    { 196, 23906, NoLogo, LineMetaDataContent::Subway, Color{0xe3131b} }, // B OSM: 8219357 WD: Q2778331 34.05, -118.4 x 34.17, -118.2
    { 277, NoLogo, 9406, LineMetaDataContent::RapidTransit, Color{0xffe800} }, // Yellow OSM: 8237627 WD: Q54874971 38, -121.9 x 38.02, -121.8
    { 3357, NoLogo, 21097, LineMetaDataContent::Subway, Color{0xfc8eac} }, // Pink Line OSM: 8242438 WD: Q19891094 28.57, 77.12 x 28.72, 77.32
    { 59, 23931, 16926, LineMetaDataContent::Subway, Color{0xbb8c00} }, // 3 OSM: 8247017 WD: Q86468 35.17, 129 x 35.21, 129.1
    { 9, NoLogo, 13916, LineMetaDataContent::Tramway, Color{0xfc751c} }, // 4 OSM: 8255319 WD: Q2735863 52.04, 4.245 x 52.08, 4.543
    { 59, NoLogo, 13916, LineMetaDataContent::Tramway, Color{0x703276} }, // 3 OSM: 8255320 WD: Q3056105 52.05, 4.228 x 52.08, 4.518
    { 55, 23954, 16926, LineMetaDataContent::Subway, Color{0xf06a00} }, // 1 OSM: 8255698 WD: Q86356 35.05, 129 x 35.28, 129.1
    { 16, 23977, 16926, LineMetaDataContent::Subway, Color{0x81bf48} }, // 2 OSM: 8258658 WD: Q86467 35.13, 129 x 35.34, 129.2
    { 3484, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x00a2c9} }, // 311 OSM: 8272972 WD: Q85977451 35.16, 129.1 x 35.54, 129.4
    { 47, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x5e2d91} }, // S8 OSM: 8294822 WD: Q7388382 47.2, 8.519 x 47.5, 8.782
    { 41, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0xfebe10} }, // S7 OSM: 8294823 WD: Q7388366 47.22, 8.511 x 47.5, 8.824
    { 42, 24000, NoLogo, LineMetaDataContent::Subway, Color{0x6ad1e3} }, // 7 OSM: 8297146 WD: Q11074646 30.61, 104 x 30.7, 104.1
    { 59, 24010, NoLogo, LineMetaDataContent::Subway, Color{0xd40f7d} }, // 3 OSM: 8297273 WD: Q8985154 30.54, 103.9 x 30.82, 104.2
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x008000} }, // 2 OSM: 8297697 WD: Q84767109 17.37, 78.48 x 17.45, 78.5
    { 3488, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // Red Line OSM: 8297698 WD: Q646209 17.35, 78.37 x 17.5, 78.55
    { 16, 24020, NoLogo, LineMetaDataContent::Subway, Color{0xff5c39} }, // 2 OSM: 8298113 WD: Q4391357 30.56, 104 x 30.76, 104.3
    { 9, 24030, NoLogo, LineMetaDataContent::Subway, Color{0x44af52} }, // 4 OSM: 8298132 WD: Q11074645 30.64, 103.8 x 30.69, 104.2
    { 65, 24040, NoLogo, LineMetaDataContent::Subway, Color{0x003da5} }, // 10 OSM: 8298254 WD: Q11074644 30.41, 103.8 x 30.63, 104
    { 15, 24051, NoLogo, LineMetaDataContent::Subway, Color{0xffcc00} }, // 12 OSM: 8298259 WD: Q17053935 2.931, 101.6 x 3.215, 101.7
    { 55, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 8299497 WD: Q18128813 26.77, 80.88 x 26.89, 81
    { 3497, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xf2a900} }, // 环 OSM: 8300611 WD: Q15915083 29.5, 106.4 x 29.61, 106.6
    { 6, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x00a3e0} }, // 5 OSM: 8300867 WD: Q15912187 29.41, 106.4 x 29.76, 106.6
    { 65, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x5a2a8d} }, // 10 OSM: 8300873 WD: Q15914281 29.51, 106.5 x 29.75, 106.7
    { 3501, NoLogo, 3795, LineMetaDataContent::Tramway, Color{0xe1261c} }, // 西郊 OSM: 8303696 WD: Q3400451 39.97, 116.2 x 39.99, 116.3
    { 3508, 24073, 226, LineMetaDataContent::RapidTransit, Color{0x56033a} }, // S 6 OSM: 8303864 WD: Q63217185 51.06, 12.37 x 51.4, 12.7
    { 1855, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x799ccd} }, // S21 OSM: 8303997 WD: Q7388225 47.38, 8.47 x 47.44, 8.55
    { 16, 24098, 24132, LineMetaDataContent::Subway, Color{0xfdb935} }, // 2 OSM: 8306848 WD: Q28412021 36.62, 116.9 x 36.71, 117.2
    { 2626, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0xf9aa8f} }, // S41 OSM: 8306928 WD: Q15088595 47.49, 8.535 x 47.53, 8.724
    { 3512, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x75593b} }, // S27 OSM: 8308820 WD: Q106451356 47.47, 8.22 x 47.62, 8.308
    { 55, 24152, NoLogo, LineMetaDataContent::Subway, Color{0x0067a1} }, // 1 OSM: 8309087 WD: Q5963161 30.57, 114.1 x 30.71, 114.3
    { 3516, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0xbda07c} }, // S15 OSM: 8309090 WD: Q7388191 47.22, 8.368 x 47.51, 8.864
    { 44, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x48b4ca} }, // S5 OSM: 8311264 WD: Q7388335 47.17, 8.429 x 47.41, 8.864
    { 3520, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0099aa} }, // JRL OSM: 8312419 WD: Q3391052 1.312, 103.7 x 1.386, 103.7
    { 3524, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x000000} }, // WES OSM: 8313440 45.31, -122.8 x 45.49, -122.8
    { 16, 24172, NoLogo, LineMetaDataContent::Subway, Color{0xff7300} }, // 2 OSM: 8323745 WD: Q2657097 30.12, 120 x 30.36, 120.3
    { 55, 24192, NoLogo, LineMetaDataContent::Subway, Color{0x1590ca} }, // 1 OSM: 8324096 WD: Q10946020 29.84, 121.4 x 29.92, 121.9
    { 26, 24213, 3795, LineMetaDataContent::Subway, Color{0x6ba53a} }, // 16 OSM: 8324250 WD: Q6553080 39.83, 116.1 x 40.07, 116.3
    { 2066, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x0588cc} }, // S30 OSM: 8327718 WD: Q7388265 47.5, 8.722 x 47.59, 9.106
    { 3528, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x007e94} }, // S26 OSM: 8327719 WD: Q2321332 47.26, 8.724 x 47.51, 8.934
    { 1289, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x7a4c29} }, // S13 OSM: 8327720 WD: Q7388186 47.13, 8.675 x 47.23, 8.75
    { 55, NoLogo, 24234, LineMetaDataContent::Subway, Color{0xec7000} }, // 1 OSM: 8337169 WD: Q15953685 24.45, 118 x 24.66, 118.1
    { 3532, 24254, NoLogo, LineMetaDataContent::LocalTrain, Color{} }, // RB 32 OSM: 8347311 WD: Q113258586 48.73, 12.19 x 48.91, 12.69
    { 230, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0xb41e8e} }, // S25 OSM: 8355962 WD: Q18391643 46.92, 8.519 x 47.38, 9.084
    { 365, 24271, NoLogo, LineMetaDataContent::LocalTrain, Color{} }, // RB 59 OSM: 8377332 WD: Q110188017 47.87, 12.64 x 47.93, 12.73
    { 3538, 24288, NoLogo, LineMetaDataContent::Subway, Color{0x939598} }, // JL OSM: 8391469 WD: Q5365768 35.75, 139.8 x 35.9, 140.1
    { 42, 24310, 1624, LineMetaDataContent::Tramway, Color{} }, // 7 OSM: 8426298 WD: Q104867986 49.43, 11.08 x 49.45, 11.09
    { 55, 24327, 21097, LineMetaDataContent::Subway, Color{0xff4040} }, // 1 OSM: 8429148 WD: Q3278367 28.67, 77.1 x 28.72, 77.42
    { 2099, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x73b3d7} }, // S35 OSM: 8437405 WD: Q7388272 47.46, 8.724 x 47.51, 9.042
    { 978, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x32a384} }, // S29 OSM: 8437511 WD: Q7388235 47.5, 8.714 x 47.66, 8.856
    { 2095, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0xad99c9} }, // S40 OSM: 8437648 WD: Q7388295 47.13, 8.682 x 47.22, 8.817
    { 3541, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x198ea3} }, // S17 OSM: 8437734 WD: Q225086 47.34, 8.27 x 47.41, 8.406
    { 3545, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // ExpressTram OSM: 8438647 WD: Q5421647 42.2, -83.36 x 42.21, -83.35
    { 442, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfc0200} }, // ATS OSM: 8438739 WD: Q2828747 41.97, -87.91 x 41.99, -87.88
    { 9, 24350, NoLogo, LineMetaDataContent::Subway, Color{0x0072ce} }, // 4 OSM: 8439223 WD: Q6112249 31.13, 120.6 x 31.41, 120.7
    { 16, 24371, NoLogo, LineMetaDataContent::Subway, Color{0xe60000} }, // 2 OSM: 8439253 WD: Q1054280 31.25, 120.6 x 31.44, 120.8
    { 3557, 24381, NoLogo, LineMetaDataContent::LocalTrain, Color{} }, // RB 57 OSM: 8442834 WD: Q108409635 47.71, 11.53 x 48.14, 11.76
    { 540, 24398, NoLogo, LineMetaDataContent::LocalTrain, Color{} }, // RB 56 OSM: 8442835 WD: Q108409632 47.68, 11.53 x 48.14, 11.71
    { 277, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffff00} }, // Yellow OSM: 8464133 WD: Q55683262 9.006, 7.272 x 9.057, 7.472
    { 1003, 24420, 12460, LineMetaDataContent::Subway, Color{0x00adef} }, // 52 OSM: 8466672 WD: Q2466115 52.34, 4.874 x 52.4, 4.933
    { 3563, 24464, 3199, LineMetaDataContent::Tramway, Color{0xe65e37} }, // T11 OSM: 8467024 WD: Q1083349 48.93, 2.302 x 48.96, 2.424
    { 3567, 24498, NoLogo, LineMetaDataContent::RapidTransit, Color{0x666666} }, // Π4 OSM: 8467447 WD: Q17853551 37.91, 23.71 x 38.07, 23.95
    { 3571, 24533, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffcd00} }, // Π1 OSM: 8467448 WD: Q47477364 37.91, 23.64 x 38.07, 23.95
    { 3575, 24568, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00a3e0} }, // Π2 OSM: 8467516 WD: Q20552930 37.91, 22.73 x 38.09, 23.74
    { 3579, 24603, 3795, LineMetaDataContent::Subway, Color{0xd85f26} }, // 25S OSM: 8469061 WD: Q8048350 39.7, 116 x 39.73, 116.1
    { 211, NoLogo, 24629, LineMetaDataContent::Tramway, Color{0x254395} }, // T1 OSM: 8475071 WD: Q55693065 43.75, 11.17 x 43.8, 11.25
    { 132, NoLogo, 24654, LineMetaDataContent::Subway, Color{0x063a91} }, // 9 OSM: 8478970 WD: Q3125123 39.01, 117.2 x 39.14, 117.7
    { 59, NoLogo, 24654, LineMetaDataContent::Subway, Color{0x128bbe} }, // 3 OSM: 8489969 WD: Q6553117 39.06, 117.1 x 39.24, 117.3
    { 16, NoLogo, 24654, LineMetaDataContent::Subway, Color{0xece114} }, // 2 OSM: 8489970 WD: Q6553104 39.13, 117.1 x 39.16, 117.4
    { 55, 24671, 24654, LineMetaDataContent::Subway, Color{0xbd0016} }, // 1 OSM: 8489971 WD: Q6126171 39.01, 117.1 x 39.21, 117.4
    { 27, NoLogo, 24654, LineMetaDataContent::Subway, Color{0x9f216f} }, // 6 OSM: 8490135 WD: Q10940001 39.04, 117.1 x 39.21, 117.3
    { 9, 24701, NoLogo, LineMetaDataContent::RapidTransit, Color{0x009049} }, // 4 OSM: 8499866 WD: Q109046034 36.8, 10.06 x 36.82, 10.19
    { 3583, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 201 OSM: 8505446 52.41, 16.91 x 52.46, 16.96
    { 139, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xaa6133} }, // 14 OSM: 8505950 52.38, 16.88 x 52.46, 16.92
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc597cd} }, // 12 OSM: 8505951 52.37, 16.91 x 52.46, 16.95
    { 54, 24725, NoLogo, LineMetaDataContent::Tramway, Color{0x5ec79f} }, // 11 OSM: 8505952 WD: Q108000659 52.37, 16.89 x 52.44, 16.96
    { 3587, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf166a7} }, // 42X OSM: 8506177 58.9, 17.86 x 59.63, 18.16
    { 3591, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // TGM OSM: 8510421 WD: Q1306749 36.8, 10.19 x 36.88, 10.34
    { 6, 24764, NoLogo, LineMetaDataContent::RapidTransit, Color{0x009049} }, // 5 OSM: 8510688 WD: Q109046037 36.8, 10.12 x 36.84, 10.18
    { 59, 24788, NoLogo, LineMetaDataContent::RapidTransit, Color{0x009049} }, // 3 OSM: 8510789 WD: Q109046031 36.8, 10.13 x 36.83, 10.18
    { 16, 24812, NoLogo, LineMetaDataContent::RapidTransit, Color{0x009049} }, // 2 OSM: 8511768 WD: Q109046023 36.81, 10.18 x 36.86, 10.2
    { 1479, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf166a7} }, // 44 OSM: 8518402 59.2, 17.81 x 59.45, 18.07
    { 3595, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf166a7} }, // 43X OSM: 8518405 58.9, 17.81 x 59.45, 18.16
    { 55, 24836, 24654, LineMetaDataContent::Tramway, Color{0x8fc31f} }, // 1 OSM: 8548848 WD: Q1659593 39.02, 117.7 x 39.09, 117.7
    { 132, 24859, 7105, LineMetaDataContent::Tramway, Color{0xc44f97} }, // 9 OSM: 8624098 WD: Q28609936 50.86, 4.309 x 50.9, 4.332
    { 3599, 24880, 16926, LineMetaDataContent::Subway, Color{0x0c8e72} }, // GC OSM: 8656365 WD: Q20192 37.58, 127 x 37.88, 127.7
    { 61, 24900, 24914, LineMetaDataContent::RapidTransit, Color{0xfd0000} }, // S1 OSM: 8661616 WD: Q46365 45.31, 9.032 x 45.62, 9.498
    { 50, 24936, 24914, LineMetaDataContent::RapidTransit, Color{0x00ad8d} }, // S2 OSM: 8661617 WD: Q1160540 45.43, 9.14 x 45.65, 9.238
    { 166, 24950, 24914, LineMetaDataContent::RapidTransit, Color{0xb90042} }, // S3 OSM: 8662821 WD: Q600028 45.47, 9.032 x 45.62, 9.176
    { 218, 24964, 24914, LineMetaDataContent::RapidTransit, Color{0x00d133} }, // S4 OSM: 8662822 WD: Q1160571 45.47, 9.133 x 45.67, 9.175
    { 44, 24978, 24914, LineMetaDataContent::RapidTransit, Color{0xff980d} }, // S5 OSM: 8662846 WD: Q1159300 45.46, 8.789 x 45.82, 9.591
    { 204, 24992, 24914, LineMetaDataContent::RapidTransit, Color{0xf0df00} }, // S6 OSM: 8662847 WD: Q1160580 45.43, 8.625 x 45.53, 9.591
    { 3602, 13069, 12889, LineMetaDataContent::Subway, Color{0x009fe3} }, // L10 Sud OSM: 8663605 WD: Q1577033 41.32, 2.113 x 41.38, 2.148
    { 3610, 25006, 16926, LineMetaDataContent::Subway, Color{0x73c7a6} }, // G·J OSM: 8667957 WD: Q18233162 37.47, 126.7 x 37.9, 127.6
    { 451, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffff00} }, // L OSM: 8668342 WD: Q48770897 39.74, -105 x 39.76, -105
    { 361, 25032, NoLogo, LineMetaDataContent::Tramway, Color{0xff7f00} }, // 24E OSM: 8682141 WD: Q63230204 38.71, -9.162 x 38.73, -9.143
    { 55, 25045, 16926, LineMetaDataContent::Subway, Color{0x005daa} }, // 1 OSM: 8691899 WD: Q20280 36.77, 126.6 x 37.95, 127.2
    { 3615, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008144} }, // 902 OSM: 8708438 WD: Q5060656 44.95, -93.28 x 44.98, -93.09
    { 26, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf9b000} }, // 16 OSM: 8712352 52.32, 9.722 x 52.38, 9.837
    { 22, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe4003a} }, // 18 OSM: 8712368 52.33, 9.734 x 52.39, 9.804
    { 3619, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa4228e} }, // 750 OSM: 8718106 40.23, -112 x 41.23, -111.7
    { 3623, 25068, 16926, LineMetaDataContent::Subway, Color{0x8fc31e} }, // 321 OSM: 8725316 WD: Q12601528 37.3, 126.8 x 37.48, 126.8
    { 3628, 25106, NoLogo, LineMetaDataContent::Tramway, Color{0x808080} }, // 720 OSM: 8725393 WD: Q7634842 40.72, -111.9 x 40.72, -111.9
    { 443, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x9bb14f} }, // TS OSM: 8729960 33.41, -111.9 x 33.43, -111.9
    { 3632, 25126, 16926, LineMetaDataContent::Subway, Color{0x0054a6} }, // GG OSM: 8735483 WD: Q23933857 37.26, 127.1 x 37.41, 127.6
    { 55, NoLogo, 25146, LineMetaDataContent::Subway, Color{0x10069f} }, // 1 OSM: 8742572 WD: Q17498490 43.76, 87.47 x 43.92, 87.62
    { 211, 25159, 25159, LineMetaDataContent::Tramway, Color{0x008000} }, // T1 OSM: 8753522 WD: Q2661356 43.24, -2.952 x 43.27, -2.905
    { 15, 25176, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 12 OSM: 8823281 WD: Q1485440 47.55, 19.09 x 47.57, 19.13
    { 3635, NoLogo, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 56A OSM: 8823482 WD: Q21996124 47.48, 18.96 x 47.54, 19.05
    { 3639, 25200, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 59A OSM: 8823524 WD: Q1491496 47.48, 19 x 47.51, 19.02
    { 3643, NoLogo, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 59B OSM: 8823525 WD: Q22810651 47.48, 18.96 x 47.54, 19.02
    { 39, 25225, NoLogo, LineMetaDataContent::RapidTransit, Color{0xd31245} }, // T OSM: 8826111 WD: Q1755582 37.71, -122.4 x 37.8, -122.4
    { 47, 25249, 24914, LineMetaDataContent::RapidTransit, Color{0xffa5ac} }, // S8 OSM: 8840314 WD: Q1160824 45.48, 9.183 x 45.86, 9.435
    { 1289, 25263, 24914, LineMetaDataContent::RapidTransit, Color{0x966524} }, // S13 OSM: 8840315 WD: Q1160881 45.19, 9.143 x 45.5, 9.245
    { 477, 25278, 24914, LineMetaDataContent::RapidTransit, Color{0xb30095} }, // S9 OSM: 8840324 WD: Q56920 45.4, 8.956 x 45.65, 9.274
    { 53, 25292, 24914, LineMetaDataContent::RapidTransit, Color{0xa08fc8} }, // S11 OSM: 8840325 WD: Q1160879 45.48, 9.028 x 45.83, 9.274
    { 55, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0000ff} }, // 1 OSM: 8857089 24.54, 46.61 x 24.84, 46.78
    { 27, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x800080} }, // 6 OSM: 8857388 24.7, 46.64 x 24.81, 46.83
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf5a300} }, // 12 OSM: 8871002 WD: Q16655708 46.17, 6.129 x 46.2, 6.207
    { 2507, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // SC OSM: 8888446 43.03, 141.3 x 43.06, 141.4
    { 537, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe40053} }, // T2 OSM: 8973402 WD: Q3239070 50.32, 3.511 x 50.46, 3.596
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf37b24} }, // 4 OSM: 9063210 47.1, 37.51 x 47.12, 37.65
    { 3647, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // Circular OSM: 9084313 WD: Q8048613 16.78, 96.09 x 16.94, 96.18
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xa68351} }, // 2 OSM: 9112026 WD: Q16854978 47.54, 7.571 x 47.59, 7.651
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x324ea1} }, // 3 OSM: 9118502 WD: Q16854981 47.55, 7.553 x 47.59, 7.631
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x835237} }, // 1 OSM: 9118510 WD: Q16854970 47.55, 7.573 x 47.57, 7.608
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0072bc} }, // 6 OSM: 9128621 WD: Q16854982 47.55, 7.537 x 47.59, 7.656
    { 42, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x8b0000} }, // 7 OSM: 9140122 14.65, 121 x 14.77, 121.1
    { 3656, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff6600} }, // MSC 621 OSM: 9165725 14.2, 121 x 14.62, 121.2
    { 3664, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // MNC OSM: 9165728 14.61, 121 x 14.67, 121
    { 3668, 25307, NoLogo, LineMetaDataContent::LocalTrain, Color{} }, // RE 22 OSM: 9173483 WD: Q108179529 48.33, 11.68 x 49.01, 12.22
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf171ab} }, // 8 OSM: 9173651 WD: Q16854983 47.55, 7.557 x 47.59, 7.608
    { 3674, 25324, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00289c} }, // C-4 OSM: 9174513 WD: Q1919488 40.24, -3.778 x 40.65, -3.635
    { 65, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfeca0a} }, // 10 OSM: 9177454 WD: Q7885420 47.48, 7.459 x 47.55, 7.62
    { 3678, 25342, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffa500} }, // C-9 OSM: 9181540 WD: Q8880294 40.74, -4.066 x 40.82, -3.963
    { 2606, 25357, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008a29} }, // C-2 OSM: 9187669 WD: Q2287356 40.38, -3.694 x 40.64, -3.181
    { 139, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf58220} }, // 14 OSM: 9190891 WD: Q16854972 47.52, 7.587 x 47.57, 7.694
    { 143, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00a54f} }, // 15 OSM: 9193744 WD: Q89415715 47.53, 7.587 x 47.56, 7.6
    { 26, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xa6ce39} }, // 16 OSM: 9196819 WD: Q16854975 47.53, 7.584 x 47.56, 7.605
    { 179, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00aeef} }, // 17 OSM: 9201222 WD: Q16854977 47.48, 7.545 x 47.58, 7.593
    { 324, 25371, NoLogo, LineMetaDataContent::RapidTransit, Color{0x1662b8} }, // U OSM: 9221982 WD: Q1191079 35.62, 139.8 x 35.67, 139.8
    { 147, NoLogo, 25398, LineMetaDataContent::RapidTransit, Color{0xff1493} }, // 19 OSM: 9234808 WD: Q154730 47.39, 7.729 x 47.49, 7.773
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xd64560} }, // 2 OSM: 9235815 WD: Q106996888 47.26, 11.35 x 47.28, 11.44
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8b445b} }, // 5 OSM: 9235816 WD: Q106996949 47.26, 11.34 x 47.28, 11.46
    { 3682, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // СТ-2 OSM: 9244973 WD: Q107191059 48.68, 44.47 x 48.8, 44.6
    { 272, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000c0} }, // Blue OSM: 9248096 38.45, -121.5 x 38.65, -121.4
    { 480, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00c000} }, // Green OSM: 9248097 38.57, -121.5 x 38.6, -121.5
    { 1859, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xc0ba00} }, // Gold OSM: 9248098 38.55, -121.5 x 38.68, -121.2
    { 3689, 25421, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff69b4} }, // NT OSM: 9253571 WD: Q910032 35.73, 139.8 x 35.81, 139.8
    { 3692, 25453, NoLogo, LineMetaDataContent::Tramway, Color{0xd85b81} }, // SA OSM: 9254426 WD: Q1064795 35.71, 139.7 x 35.75, 139.8
    { 3695, NoLogo, 21097, LineMetaDataContent::Subway, Color{0x00ffff} }, // Aqua Line OSM: 9256785 WD: Q41668068 28.44, 77.37 x 28.59, 77.55
    { 2186, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0377ae} }, // R2 OSM: 9266121 48.62, 21.19 x 48.71, 21.3
    { 2199, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0377ae} }, // R8 OSM: 9266263 48.62, 21.19 x 48.71, 21.27
    { 509, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0377ae} }, // R1 OSM: 9273350 48.62, 21.19 x 48.72, 21.27
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0377ae} }, // 5 OSM: 9274837 48.7, 21.24 x 48.72, 21.27
    { 3705, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xcc3333} }, // exo1 OSM: 9288759 WD: Q3239247 45.39, -74.14 x 45.5, -73.57
    { 1596, 25482, NoLogo, LineMetaDataContent::RapidTransit, Color{0xda0442} }, // TY OSM: 9288983 WD: Q1192468 35.47, 139.6 x 35.66, 139.7
    { 3710, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x808080} }, // exo4 OSM: 9298215 WD: Q3239087 45.36, -73.66 x 45.5, -73.51
    { 537, NoLogo, 24629, LineMetaDataContent::Tramway, Color{0x5d3988} }, // T2 OSM: 9298542 WD: Q61670436 43.77, 11.2 x 43.8, 11.25
    { 54, 25507, NoLogo, LineMetaDataContent::Subway, Color{0x6a1d44} }, // 11 OSM: 9318442 WD: Q4698920 22.52, 113.8 x 22.79, 114.1
    { 3715, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x009900} }, // exo2 OSM: 9326028 WD: Q3239074 45.45, -74 x 45.77, -73.57
    { 3720, 25531, NoLogo, LineMetaDataContent::Subway, Color{0x3564af} }, // SR OSM: 9336150 WD: Q1065949 35.78, 139.7 x 35.89, 139.8
    { 3723, 25563, 25563, LineMetaDataContent::RapidTransit, Color{0xef473d} }, // SY OSM: 9338171 WD: Q842520 35.77, 139.4 x 35.77, 139.4
    { 3726, 25582, NoLogo, LineMetaDataContent::RapidTransit, Color{0x009cd2} }, // MG OSM: 9340970 WD: Q283861 35.55, 139.6 x 35.63, 139.7
    { 3729, 25607, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf18c43} }, // OM OSM: 9341650 WD: Q384995 35.6, 139.6 x 35.61, 139.7
    { 3732, 25632, NoLogo, LineMetaDataContent::RapidTransit, Color{0x20a288} }, // DT OSM: 9341816 WD: Q1190086 35.51, 139.4 x 35.66, 139.7
    { 446, 25657, NoLogo, LineMetaDataContent::RapidTransit, Color{0xee86a7} }, // IK OSM: 9342009 WD: Q1192388 35.56, 139.7 x 35.63, 139.7
    { 1729, 25682, NoLogo, LineMetaDataContent::RapidTransit, Color{0xae0378} }, // TM OSM: 9343887 WD: Q379292 35.56, 139.7 x 35.59, 139.7
    { 3735, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff00ff} }, // exo5 OSM: 9344059 WD: Q3239152 45.52, -73.67 x 45.74, -73.49
    { 3740, 25707, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0068b7} }, // KD OSM: 9344153 WD: Q842701 35.53, 139.5 x 35.56, 139.5
    { 1983, 25732, NoLogo, LineMetaDataContent::RapidTransit, Color{0x10a899} }, // NS OSM: 9346454 WD: Q846381 35.91, 139.6 x 36.01, 139.6
    { 3743, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x6600cc} }, // exo3 OSM: 9348176 WD: Q3239159 45.49, -73.57 x 45.58, -73.18
    { 3748, NoLogo, 392, LineMetaDataContent::RapidTransit, Color{0xbac219} }, // U16 OSM: 9354869 WD: Q106879571 48.8, 9.087 x 48.81, 9.277
    { 254, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf8b710} }, // 23 OSM: 9396890 48.75, 9.179 x 48.81, 9.221
    { 524, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc01903} }, // A OSM: 9413576 WD: Q1419423 45.76, 3.082 x 45.81, 3.134
    { 72, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00ae9d} }, // 21 OSM: 9414064 WD: Q16854979 47.56, 7.573 x 47.57, 7.608
    { 44, NoLogo, 25398, LineMetaDataContent::RapidTransit, Color{0x79d4f0} }, // S5 OSM: 9414242 WD: Q63705361 47.59, 7.608 x 47.64, 7.744
    { 1192, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0xcb7eb5} }, // S36 OSM: 9414253 WD: Q15088595 47.52, 8.22 x 47.62, 8.538
    { 3752, 25760, NoLogo, LineMetaDataContent::Subway, Color{0xf890a5} }, // 捷運紅線 (新北投支線) OSM: 9437207 WD: Q8044505 25.13, 121.5 x 25.14, 121.5
    { 3238, 25799, NoLogo, LineMetaDataContent::Subway, Color{0x398afc} }, // BL OSM: 9437778 WD: Q708378 24.96, 121.4 x 25.05, 121.6
    { 1576, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x2ab04f} }, // RE OSM: 9441941 46.95, 7.438 x 47.2, 7.559
    { 477, NoLogo, 11825, LineMetaDataContent::RapidTransit, Color{0xea1a2a} }, // S9 OSM: 9441942 WD: Q115689939 46.95, 7.438 x 46.99, 7.458
    { 47, NoLogo, 11825, LineMetaDataContent::RapidTransit, Color{0x201f20} }, // S8 OSM: 9441943 WD: Q115689938 46.95, 7.438 x 47.2, 7.544
    { 3528, 25824, 226, LineMetaDataContent::RapidTransit, Color{0x018a47} }, // S26 OSM: 9445376 WD: Q7388232 52.4, 13.28 x 52.61, 13.4
    { 265, NoLogo, 6703, LineMetaDataContent::Subway, Color{0xff0000} }, // M1 OSM: 9449959 WD: Q3238662 45.02, 7.591 x 45.08, 7.68
    { 59, 25855, 14665, LineMetaDataContent::Tramway, Color{0xffff00} }, // 3 OSM: 9453120 WD: Q61000373 -22.91, -43.19 x -22.9, -43.17
    { 3083, NoLogo, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 2B OSM: 9453936 WD: Q113118555 47.42, 19.05 x 47.51, 19.12
    { 27, 25884, 17569, LineMetaDataContent::Subway, Color{0xff5599} }, // 6 OSM: 9468298 WD: Q20110123 35.62, 51.32 x 35.74, 51.46
    { 3783, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffcd28} }, // Z72 OSM: 9470080 WD: Q101321651 47.51, 18.71 x 47.78, 19.1
    { 3787, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff6600} }, // RN OSM: 9477810 WD: Q1055870 35.81, 139.9 x 35.86, 139.9
    { 3790, 25908, NoLogo, LineMetaDataContent::Subway, Color{0xffff00} }, // KS-AE OSM: 9480386 WD: Q1045305 35.54, 139.7 x 35.81, 140.4
    { 318, NoLogo, 25936, LineMetaDataContent::Subway, Color{0x3e9397} }, // M OSM: 9487066 WD: Q7057341 -33.8, 150.9 x -33.69, 151.2
    { 3796, 25948, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7a745a} }, // F3 OSM: 9488738 WD: Q31193173 41.1, 28.99 x 41.11, 28.99
    { 2325, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x006400} }, // EN OSM: 9499957 WD: Q250760 35.3, 139.5 x 35.34, 139.6
    { 3799, 25976, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00a6bf} }, // SS OSM: 9507192 WD: Q195685 35.7, 139.3 x 35.91, 139.7
    { 55, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0000ff} }, // 1 OSM: 9522022 WD: Q61990549 23, 72.52 x 23.05, 72.67
    { 55, 25994, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa6dfe6} }, // 1 OSM: 9525005 WD: Q109046020 36.75, 10.18 x 36.8, 10.22
    { 27, 26018, NoLogo, LineMetaDataContent::RapidTransit, Color{0x652c90} }, // 6 OSM: 9530554 WD: Q109046039 36.72, 10.18 x 36.8, 10.22
    { 393, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x48a23e} }, // L2 OSM: 9536631 WD: Q25420937 9.029, -79.51 x 9.104, -79.35
    { 272, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // Blue OSM: 9542499 9.046, 7.285 x 9.155, 7.344
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009999} }, // 5 OSM: 9544852 53.08, 8.78 x 53.09, 8.818
    { 3802, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffff00} }, // JN OSM: 9555851 35.51, 139.4 x 35.7, 139.7
    { 949, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff9c2a} }, // N19 OSM: 9570043 47.48, 19.04 x 47.53, 19.06
    { 3805, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xffa500} }, // Orange Line OSM: 9571557 WD: Q61996404 21.04, 79.04 x 21.19, 79.12
    { 284, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xe2251c} }, // Red OSM: 9573815 WD: Q25343681 25.19, 51.49 x 25.42, 51.62
    { 61, NoLogo, 11825, LineMetaDataContent::RapidTransit, Color{0x4cb848} }, // S1 OSM: 9577262 WD: Q115689931 46.75, 7.15 x 46.97, 7.631
    { 50, NoLogo, 11825, LineMetaDataContent::RapidTransit, Color{0x00abe5} }, // S2 OSM: 9577399 WD: Q115689932 46.88, 7.241 x 46.97, 7.784
    { 218, NoLogo, 11825, LineMetaDataContent::RapidTransit, Color{0x45bfad} }, // S4 OSM: 9579475 WD: Q115689934 46.75, 7.407 x 47.07, 7.784
    { 3817, NoLogo, 11825, LineMetaDataContent::RapidTransit, Color{0x5d5910} }, // S44 OSM: 9582296 WD: Q115689941 46.75, 7.407 x 47.2, 7.737
    { 44, NoLogo, 11825, LineMetaDataContent::RapidTransit, Color{0x7f0041} }, // S5 OSM: 9582947 WD: Q115689935 46.82, 6.933 x 47.01, 7.44
    { 204, NoLogo, 11825, LineMetaDataContent::RapidTransit, Color{0xea595b} }, // S6 OSM: 9584378 WD: Q115689936 46.82, 7.34 x 46.95, 7.439
    { 41, 26042, 10680, LineMetaDataContent::Subway, Color{0xca8687} }, // S7 OSM: 9584586 WD: Q10946062 31.61, 118.9 x 31.76, 119
    { 477, 26063, 10680, LineMetaDataContent::Subway, Color{0xf1bc1a} }, // S9 OSM: 9584587 WD: Q47471478 31.34, 118.8 x 31.76, 118.9
    { 1002, NoLogo, 11825, LineMetaDataContent::RapidTransit, Color{0xe9ce0e} }, // S52 OSM: 9584652 WD: Q115689943 46.93, 7.098 x 47, 7.439
    { 166, NoLogo, 11825, LineMetaDataContent::RapidTransit, Color{0x8a6aae} }, // S3 OSM: 9585454 WD: Q115689933 46.89, 7.24 x 47.13, 7.499
    { 3821, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xee1e23} }, // U GUS OSM: 9586670 41.14, -8.61 x 41.44, -8.294
    { 47, 26084, 10680, LineMetaDataContent::Subway, Color{0xeca153} }, // S8 OSM: 9588181 WD: Q10945880 32.13, 118.7 x 32.47, 119
    { 9, NoLogo, 10680, LineMetaDataContent::Subway, Color{0xa513c0} }, // 4 OSM: 9588283 WD: Q10906684 32.06, 118.7 x 32.13, 119
    { 59, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xd3b466} }, // 3 OSM: 9588292 WD: Q11124519 30.49, 114.2 x 30.68, 114.3
    { 16, 26105, NoLogo, LineMetaDataContent::Subway, Color{0xec9cbb} }, // 2 OSM: 9592190 WD: Q5952205 30.44, 114.2 x 30.79, 114.4
    { 3827, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x3caeef} }, // U MCS OSM: 9599441 41.14, -8.61 x 41.26, -8.136
    { 3833, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x800080} }, // ACE OSM: 9599550 37.33, -122 x 37.96, -121.3
    { 3837, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x006400} }, // SMART OSM: 9599558 37.95, -122.8 x 38.51, -122.5
    { 245, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x006400} }, // 45 OSM: 9600350 51.78, 19.41 x 51.85, 19.51
    { 439, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x006400} }, // 41 OSM: 9600352 51.66, 19.32 x 51.74, 19.46
    { 22, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 18 OSM: 9600353 51.74, 19.38 x 51.78, 19.51
    { 179, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffc0cb} }, // 17 OSM: 9600354 51.7, 19.41 x 51.78, 19.53
    { 26, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffc0cb} }, // 16 OSM: 9600355 51.72, 19.37 x 51.8, 19.49
    { 143, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffc0cb} }, // 15 OSM: 9600356 51.72, 19.45 x 51.78, 19.53
    { 139, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // 14 OSM: 9600357 51.74, 19.38 x 51.76, 19.49
    { 58, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 13 OSM: 9600358 51.73, 19.37 x 51.8, 19.49
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 12 OSM: 9600359 51.74, 19.38 x 51.78, 19.53
    { 54, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffa500} }, // 11 OSM: 9600360 51.7, 19.41 x 51.83, 19.46
    { 3843, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // 10AB OSM: 9600361 51.73, 19.38 x 51.76, 19.58
    { 3848, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 9AB OSM: 9600362 51.73, 19.41 x 51.77, 19.58
    { 3852, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // 8AB OSM: 9600363 51.75, 19.36 x 51.8, 19.54
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffa500} }, // 6 OSM: 9600365 51.72, 19.41 x 51.85, 19.55
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x800080} }, // 5 OSM: 9600366 51.72, 19.41 x 51.79, 19.49
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 4 OSM: 9600367 51.74, 19.43 x 51.83, 19.51
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffa500} }, // 3 OSM: 9600368 51.72, 19.45 x 51.81, 19.55
    { 3856, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffa500} }, // 2AB OSM: 9600370 51.74, 19.36 x 51.8, 19.51
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x800080} }, // 1 OSM: 9600371 51.73, 19.46 x 51.8, 19.49
    { 3860, 26125, 26163, LineMetaDataContent::Tramway, Color{0x32cd32} }, // HN OSM: 9603867 WD: Q5648522 34.54, 135.4 x 34.65, 135.5
    { 329, 26185, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7777ff} }, // P OSM: 9603949 WD: Q1073366 34.61, 135.4 x 34.64, 135.5
    { 3863, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // Local OSM: 9604092 37.31, -122.4 x 37.78, -121.9
    { 6, NoLogo, 24654, LineMetaDataContent::Subway, Color{0xfb6f14} }, // 5 OSM: 9604983 WD: Q10940000 39.03, 117.1 x 39.27, 117.2
    { 9, 26229, NoLogo, LineMetaDataContent::Subway, Color{0x00843d} }, // 4 OSM: 9607978 WD: Q863422 22.75, 113.4 x 23.13, 113.6
    { 9, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xdc8633} }, // 4 OSM: 9609521 WD: Q15900365 29.6, 106.5 x 29.78, 106.8
    { 3869, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x00b5e2} }, // APM OSM: 9611409 WD: Q862929 23.11, 113.3 x 23.14, 113.3
    { 72, 26249, NoLogo, LineMetaDataContent::Subway, Color{0x201747} }, // 21 OSM: 9611531 WD: Q6553110 23.12, 113.4 x 23.29, 113.8
    { 3873, 26270, NoLogo, LineMetaDataContent::Subway, Color{0xc4d600} }, // GF OSM: 9612493 WD: Q3272527 22.96, 113.1 x 23.09, 113.3
    { 27, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x007128} }, // 6 OSM: 9617440 WD: Q15899990 30.49, 114.1 x 30.65, 114.3
    { 42, 26296, NoLogo, LineMetaDataContent::Subway, Color{0xeb7c16} }, // 7 OSM: 9617441 WD: Q11124507 30.32, 114.2 x 30.81, 114.3
    { 44, 26316, 2154, LineMetaDataContent::RapidTransit, Color{0x8d1d81} }, // S5 OSM: 9626749 WD: Q116125185 46.71, 15.42 x 47.07, 15.63
    { 3876, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x97c616} }, // CRL OSM: 9627859 1.311, 103.7 x 1.406, 104
    { 3880, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x734538} }, // TEL OSM: 9627860 WD: Q7795883 1.272, 103.8 x 1.452, 104
    { 42, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0035ad} }, // 7 OSM: 9629866 WD: Q5938409 22.52, 113.9 x 22.6, 114.1
    { 59, 26334, NoLogo, LineMetaDataContent::Subway, Color{0x00a2e1} }, // 3 OSM: 9629887 WD: Q1065551 22.51, 114 x 22.73, 114.3
    { 61, 26357, 2154, LineMetaDataContent::RapidTransit, Color{0x00983a} }, // S1 OSM: 9631352 WD: Q116125178 47.07, 15.28 x 47.41, 15.42
    { 9, 26375, NoLogo, LineMetaDataContent::Subway, Color{0x920783} }, // 4 OSM: 9632502 WD: Q24835582 28.14, 112.9 x 28.3, 113.1
    { 9, 26394, NoLogo, LineMetaDataContent::Subway, Color{0xa6d30b} }, // 4 OSM: 9633082 WD: Q6553126 30.53, 114 x 30.61, 114.4
    { 54, 26414, NoLogo, LineMetaDataContent::Subway, Color{0xf6d300} }, // 11 OSM: 9633134 WD: Q11124500 30.49, 114.3 x 30.54, 114.7
    { 397, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x8b4513} }, // L3 OSM: 9633218 WD: Q5986353 -33.46, -70.69 x -33.37, -70.56
    { 477, 26434, 2154, LineMetaDataContent::RapidTransit, Color{0x9f7fb8} }, // S9 OSM: 9634178 WD: Q116125198 47.41, 15.27 x 47.61, 15.68
    { 47, 26452, 2154, LineMetaDataContent::RapidTransit, Color{0x5cc1d1} }, // S8 OSM: 9634179 WD: Q116125196 47.17, 14.44 x 47.42, 15.28
    { 451, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0067c0} }, // L OSM: 9638873 WD: Q1329642 35.17, 137 x 35.18, 137.1
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x3b6a96} }, // 2 OSM: 9642906 WD: Q15913266 43.83, 125.2 x 43.88, 125.4
    { 19, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x25b7bc} }, // 8 OSM: 9642908 WD: Q15956288 43.95, 125.3 x 44.01, 125.4
    { 6, 26470, NoLogo, LineMetaDataContent::Subway, Color{0x9950b2} }, // 5 OSM: 9645952 WD: Q5926109 22.48, 113.9 x 22.63, 114.1
    { 55, 26493, NoLogo, LineMetaDataContent::Subway, Color{0xee352e} }, // 1 OSM: 9651536 WD: Q126093 40.7, -74.02 x 40.89, -73.9
    { 1211, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0xf05b94} }, // S20 OSM: 9652168 WD: Q111523342 47.24, 8.514 x 47.39, 8.727
    { 16, 26519, NoLogo, LineMetaDataContent::Subway, Color{0xee352e} }, // 2 OSM: 9655665 WD: Q126142 40.63, -74.01 x 40.9, -73.85
    { 59, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x571887} }, // 3 OSM: 9656354 WD: Q25824052 22.72, 108.2 x 22.88, 108.4
    { 59, 26545, NoLogo, LineMetaDataContent::Subway, Color{0xee352e} }, // 3 OSM: 9663807 WD: Q126151 40.66, -74.01 x 40.82, -73.88
    { 3884, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x6c8bc6} }, // D11 OSM: 9672611 51.1, 16.15 x 51.4, 17.04
    { 9, 26571, NoLogo, LineMetaDataContent::Subway, Color{0x00933c} }, // 4 OSM: 9677108 WD: Q126163 40.66, -74.01 x 40.89, -73.88
    { 1983, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xce0037} }, // NS OSM: 9677671 WD: Q60608236 -6.292, 106.8 x -6.191, 106.8
    { 389, 26597, 26610, LineMetaDataContent::RapidTransit, Color{0xee343f} }, // L1 OSM: 9678605 WD: Q14543324 -33.91, 151.1 x -33.87, 151.2
    { 451, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe4022d} }, // L OSM: 9678765 -32.93, 151.8 x -32.92, 151.8
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 2 OSM: 9680853 51.37, -0.2081 x 51.42, -0.02612
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xb5e61d} }, // 4 OSM: 9680854 51.37, -0.2081 x 51.42, -0.04953
    { 6, 26622, NoLogo, LineMetaDataContent::Subway, Color{0x00933c} }, // 5 OSM: 9682651 WD: Q126177 40.63, -74.01 x 40.9, -73.83
    { 1827, 26648, NoLogo, LineMetaDataContent::LocalTrain, Color{0x008a45} }, // T8 OSM: 9698883 WD: Q4698965 -34.07, 150.8 x -33.86, 151.2
    { 132, 26661, NoLogo, LineMetaDataContent::Subway, Color{0x846e74} }, // 9 OSM: 9699772 WD: Q5939429 22.51, 113.9 x 22.57, 114.1
    { 2317, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // BLUE OSM: 9701744 53.33, -1.508 x 53.4, -1.344
    { 3888, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x800080} }, // PURP OSM: 9701781 53.34, -1.469 x 53.38, -1.424
    { 3893, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffff00} }, // YELL OSM: 9701824 53.38, -1.51 x 53.42, -1.405
    { 3898, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // TT OSM: 9701873 53.38, -1.469 x 53.44, -1.343
    { 3901, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x006bb6} }, // SIR OSM: 9701910 40.51, -74.25 x 40.64, -74.07
    { 139, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe2368c} }, // 14 OSM: 9708096 47.14, 37.54 x 47.18, 37.62
    { 58, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe2368c} }, // 13 OSM: 9708097 47.14, 37.54 x 47.18, 37.62
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x13b5eb} }, // 8 OSM: 9708100 47.1, 37.51 x 47.12, 37.56
    { 65, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x4f3893} }, // 10 OSM: 9708103 47.1, 37.51 x 47.17, 37.62
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf37b24} }, // 3 OSM: 9709247 47.1, 37.51 x 47.12, 37.65
    { 3905, 26684, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008150} }, // GL(E) OSM: 9709938 WD: Q172040 42.33, -71.12 x 42.41, -71.06
    { 54, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x897ab7} }, // 11 OSM: 9712140 47.1, 37.54 x 47.18, 37.65
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffbf00} }, // 5 OSM: 9712141 47.1, 37.54 x 47.15, 37.65
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffbf00} }, // 6 OSM: 9712142 47.1, 37.54 x 47.12, 37.65
    { 132, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0068b2} }, // 9 OSM: 9712143 47.1, 37.54 x 47.18, 37.65
    { 318, 26712, NoLogo, LineMetaDataContent::Subway, Color{0xff6319} }, // M OSM: 9712349 WD: Q126418 40.7, -74 x 40.76, -73.84
    { 451, 26738, NoLogo, LineMetaDataContent::Subway, Color{0xa7a9ac} }, // L OSM: 9716997 WD: Q126534 40.65, -74 x 40.74, -73.9
    { 477, NoLogo, 25398, LineMetaDataContent::RapidTransit, Color{0x9589c6} }, // S9 OSM: 9719969 WD: Q3239195 47.35, 7.81 x 47.46, 7.918
    { 3911, 3539, NoLogo, LineMetaDataContent::Subway, Color{0xb933ad} }, // <7> OSM: 9721629 WD: Q126203 40.74, -74 x 40.76, -73.83
    { 3915, 3669, NoLogo, LineMetaDataContent::Subway, Color{0x00933c} }, // <6> OSM: 9721630 WD: Q126192 40.71, -74.01 x 40.85, -73.83
    { 3919, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // 202 OSM: 9729897 WD: Q51912653 51.04, -114.2 x 51.13, -113.9
    { 3583, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // 201 OSM: 9729912 WD: Q51898028 50.9, -114.2 x 51.13, -114.1
    { 3923, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfc6357} }, // 22R OSM: 9730137 WD: Q14192100 53.46, -113.5 x 53.57, -113.5
    { 457, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x3a59a9} }, // 21R OSM: 9730138 WD: Q12054219 53.46, -113.5 x 53.6, -113.4
    { 55, 26764, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // 1 OSM: 9732464 WD: Q56188749 -3.033, 104.7 x -2.894, 104.8
    { 3927, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xed1d24} }, // TWL OSM: 9736531 WD: Q1194568 22.28, 114.1 x 22.38, 114.2
    { 3931, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x7d499d} }, // TKL OSM: 9736612 WD: Q989347 22.29, 114.2 x 22.32, 114.3
    { 1163, 26812, NoLogo, LineMetaDataContent::LocalTrain, Color{0xff8c00} }, // RB 40 OSM: 9740849 WD: Q62594138 50.03, 10.13 x 50.57, 10.44
    { 235, 19858, NoLogo, LineMetaDataContent::Subway, Color{0x996633} }, // J OSM: 9747970 WD: Q126484 40.68, -74.01 x 40.72, -73.8
    { 196, 26836, NoLogo, LineMetaDataContent::Subway, Color{0xff6319} }, // B OSM: 9748435 WD: Q126381 40.58, -74 x 40.87, -73.89
    { 306, 2447, 2474, LineMetaDataContent::RapidTransit, Color{0xef7b10} }, // LO OSM: 9752361 WD: Q7363198 51.56, 0.1838 x 51.58, 0.2521
    { 238, 26862, NoLogo, LineMetaDataContent::Subway, Color{0xff6319} }, // F OSM: 9753684 WD: Q126404 40.58, -74 x 40.77, -73.78
    { 3935, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xb2007b} }, // Yangluo OSM: 9765661 WD: Q11124502 30.65, 114.3 x 30.72, 114.6
    { 230, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0xf17079} }, // S25 OSM: 9767545 WD: Q115743707 47.28, 8.204 x 47.48, 8.341
    { 3943, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0xfece08} }, // S23 OSM: 9767546 WD: Q115743940 47.22, 7.784 x 47.49, 8.308
    { 3528, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0xc89f3b} }, // S26 OSM: 9767547 WD: Q115646660 47.14, 7.907 x 47.4, 8.436
    { 311, 26888, NoLogo, LineMetaDataContent::Subway, Color{0x0039a6} }, // C OSM: 9767766 WD: Q126358 40.67, -74.01 x 40.84, -73.87
    { 2514, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x13ae99} }, // S14 OSM: 9768340 WD: Q115747591 47.24, 8.041 x 47.39, 8.19
    { 1028, 26914, NoLogo, LineMetaDataContent::Subway, Color{0xff6319} }, // D OSM: 9769161 WD: Q126396 40.58, -74.01 x 40.88, -73.88
    { 363, 26940, NoLogo, LineMetaDataContent::Subway, Color{0x0039a6} }, // E OSM: 9769302 WD: Q126368 40.7, -74.01 x 40.76, -73.8
    { 3947, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x000000} }, // 751P OSM: 9788142 WD: Q15903000 22.41, 114 x 22.47, 114
    { 3952, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xee3a41} }, // NEC OSM: 9795466 WD: Q7057868 40.2, -74.79 x 40.77, -73.99
    { 537, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe73132} }, // T2 OSM: 9797089 49.18, -0.3663 x 49.21, -0.3479
    { 1767, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009adf} }, // T3 OSM: 9797090 49.15, -0.364 x 49.19, -0.3411
    { 1575, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf686c3} }, // TRE OSM: 9797671 WD: Q7838588 39.95, -75.2 x 40.22, -74.75
    { 1045, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0xffc709} }, // S31 OSM: 9800222 WD: Q115646663 47.05, 8.548 x 47.16, 8.724
    { 9, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x37ad96} }, // 4 OSM: 9807766 WD: Q15939632 34.14, 108.9 x 34.38, 109
    { 3956, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x3096c2} }, // NLR OSM: 9821052 WD: Q3078283 40.73, -74.19 x 40.78, -74.16
    { 59, 26966, NoLogo, LineMetaDataContent::Subway, Color{0xeca154} }, // 3 OSM: 9841063 WD: Q862941 22.94, 113.3 x 23.4, 113.4
    { 3960, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0194d7} }, // JFK OSM: 9862004 WD: Q406683 40.64, -73.83 x 40.7, -73.78
    { 58, 26986, NoLogo, LineMetaDataContent::RapidTransit, Color{0x2ca05a} }, // 13 OSM: 9881314 WD: Q6553067 -23.55, -46.64 x -23.43, -46.49
    { 3964, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // Norte OSM: 9881792 -5.797, -35.42 x -5.632, -35.21
    { 132, 26998, NoLogo, LineMetaDataContent::Subway, Color{0x017cbf} }, // 9 OSM: 9893306 WD: Q11138917 41.72, 123.3 x 41.84, 123.5
    { 480, 27029, NoLogo, LineMetaDataContent::RapidTransit, Color{0x76c761} }, // Green OSM: 9897509 WD: Q6925400 37.28, -122 x 37.41, -121.9
    { 272, 27048, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00a4e2} }, // Blue OSM: 9897510 WD: Q4737344 37.24, -121.9 x 37.41, -121.8
    { 3970, 27066, 27066, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // ARL OSM: 9921501 WD: Q1133704 13.69, 100.5 x 13.76, 100.8
    { 132, 27081, NoLogo, LineMetaDataContent::Subway, Color{0x71cc98} }, // 9 OSM: 9924027 WD: Q6553161 23.36, 113.1 x 23.4, 113.3
    { 995, 27101, 226, LineMetaDataContent::RapidTransit, Color{0xc36939} }, // S42 OSM: 9942315 WD: Q15118875 52.46, 13.28 x 52.55, 13.48
    { 513, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffd700} }, // G OSM: 9942698 WD: Q5578772 39.75, -105.1 x 39.81, -105
    { 196, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // B OSM: 9942699 WD: Q19865232 39.75, -105 x 39.82, -105
    { 524, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x57c0e8} }, // A OSM: 9942719 WD: Q5328174 39.75, -105 x 39.85, -104.7
    { 2654, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xcccccc} }, // Silver OSM: 9946498 32.71, -117.2 x 32.72, -117.2
    { 3975, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // 530 OSM: 9946502 32.71, -117.2 x 32.84, -117
    { 3979, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffa500} }, // 520 OSM: 9946503 32.71, -117.2 x 32.81, -117
    { 311, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf79239} }, // C OSM: 9947502 WD: Q5015067 39.58, -105 x 39.76, -105
    { 1028, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008348} }, // D OSM: 9947503 WD: Q5207092 39.58, -105 x 39.75, -105
    { 363, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x552683} }, // E OSM: 9947507 WD: Q5324803 39.52, -105 x 39.76, -104.9
    { 238, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xee3e33} }, // F OSM: 9947520 WD: Q5427493 39.52, -105 x 39.75, -104.9
    { 34, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0075bf} }, // H OSM: 9947525 39.63, -105 x 39.75, -104.8
    { 459, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xb7f037} }, // R OSM: 9947529 WD: Q5515134 39.52, -104.9 x 39.77, -104.8
    { 562, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x37b5a5} }, // W OSM: 9947532 WD: Q7958496 39.72, -105.2 x 39.76, -105
    { 211, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x23a638} }, // T1 OSM: 9953164 49.15, -0.3663 x 49.2, -0.3292
    { 982, NoLogo, 24914, LineMetaDataContent::RapidTransit, Color{0x293838} }, // S12 OSM: 9959066 WD: Q26828150 45.36, 9.159 x 45.5, 9.32
    { 3983, 21439, 16926, LineMetaDataContent::Subway, Color{0x996746} }, // AREX OSM: 9961461 WD: Q487643 37.44, 126.4 x 37.6, 127
    { 3988, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xd1aa00} }, // SAR-VIN OSM: 9963645 WD: Q10318744 -22.68, -43.25 x -22.57, -43.18
    { 3996, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x660066} }, // Belford Roxo OSM: 9963651 WD: Q10318671 -22.91, -43.4 x -22.76, -43.19
    { 4009, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf60619} }, // Deodoro OSM: 9963665 WD: Q18473921 -22.91, -43.39 x -22.85, -43.19
    { 4017, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfa8835} }, // Saracuruna OSM: 9963667 WD: Q10318727 -22.91, -43.31 x -22.68, -43.19
    { 4028, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x5194c4} }, // JRI-PBI OSM: 9963669 WD: Q10318719 -22.64, -43.71 x -22.61, -43.65
    { 4036, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x96333b} }, // SAR-GIM OSM: 9963674 WD: Q10318688 -22.68, -43.25 x -22.52, -42.98
    { 4044, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x6b297e} }, // Parangaba-Mucuripe OSM: 9963934 WD: Q10318709 -3.776, -38.56 x -3.72, -38.48
    { 4063, 27132, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // Oeste OSM: 9963937 WD: Q14325543 -3.77, -38.66 x -3.718, -38.54
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009ee3} }, // 4 OSM: 9964886 52.25, 10.51 x 52.27, 10.56
    { 524, 27170, 1055, LineMetaDataContent::RapidTransit, Color{0x00bfff} }, // A OSM: 9971068 WD: Q2323144 55.46, 12.17 x 55.93, 12.59
    { 691, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xde1d43} }, // LR OSM: 9976617 39.17, -76.68 x 39.5, -76.62
    { 16, 27192, 27213, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // 2 OSM: 9984970 WD: Q4873303 2.999, 101.4 x 3.685, 101.7
    { 55, 27234, 27213, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // 1 OSM: 9985625 WD: Q4207166 2.452, 101.7 x 3.239, 102.2
    { 65, 27255, 27213, LineMetaDataContent::RapidTransit, Color{0xa52a2a} }, // 10 OSM: 9985661 WD: Q51419215 3.081, 101.6 x 3.136, 101.7
    { 143, 27277, 4578, LineMetaDataContent::Subway, Color{0xde64a1} }, // 15 OSM: 10011657 WD: Q4226438 55.7, 37.73 x 55.73, 37.93
    { 272, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // Blue OSM: 10012484 WD: Q4929376 35.11, -80.88 x 35.32, -80.73
    { 132, 27302, NoLogo, LineMetaDataContent::Tramway, Color{0x009cdd} }, // 9 OSM: 10015448 WD: Q26197601 53.41, 14.49 x 53.47, 14.55
    { 3726, 25582, NoLogo, LineMetaDataContent::Subway, Color{0x8ba2ae} }, // MG OSM: 10023806 WD: Q283861 35.55, 139.6 x 35.63, 139.7
    { 1379, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xbcbe00} }, // E2 OSM: 10025161 WD: Q104233849 43.27, -2.021 x 43.35, -1.782
    { 4069, 27322, NoLogo, LineMetaDataContent::Subway, Color{0x01aaaa} }, // TJ OSM: 10032387 WD: Q1040703 35.44, 139.2 x 36.12, 139.7
    { 3732, 25632, NoLogo, LineMetaDataContent::Subway, Color{0x01aaaa} }, // DT OSM: 10032468 WD: Q1190086 35.47, 139.4 x 36.11, 139.8
    { 55, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xee1b2e} }, // 1 OSM: 10036404 WD: Q5159786 45.4, -75.74 x 45.43, -75.61
    { 4072, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x00a650} }, // OT OSM: 10036880 WD: Q1063832 35.36, 139.2 x 35.67, 139.7
    { 307, 27353, 27353, LineMetaDataContent::RapidTransit, Color{0xe80000} }, // O OSM: 10073686 WD: Q1142127 34.65, 135.5 x 34.71, 135.5
    { 314, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x9ab6d3} }, // S OSM: 10077909 WD: Q56525586 47.15, -122.5 x 47.6, -122.2
    { 517, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x9ab6d3} }, // N OSM: 10077955 47.6, -122.4 x 47.98, -122.2
    { 65, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe3000b} }, // 10 OSM: 10082596 52.25, 10.51 x 52.31, 10.54
    { 4075, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa17800} }, // 김포 골드라인 OSM: 10092720 37.56, 126.6 x 37.65, 126.8
    { 132, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 9 OSM: 10092776 WD: Q15222207 63.4, 10.31 x 63.43, 10.39
    { 4095, 2728, NoLogo, LineMetaDataContent::RapidTransit, Color{0x98002e} }, // 1983 OSM: 10094530 WD: Q3239135 43.11, -79.89 x 43.64, -79.06
    { 4100, 2728, NoLogo, LineMetaDataContent::RapidTransit, Color{0x98002e} }, // 1975 OSM: 10094530 WD: Q3239135 43.11, -79.89 x 43.64, -79.06
    { 169, 2728, NoLogo, LineMetaDataContent::RapidTransit, Color{0x98002e} }, // 1967 OSM: 10094530 WD: Q3239135 43.11, -79.89 x 43.64, -79.06
    { 4105, 2728, NoLogo, LineMetaDataContent::RapidTransit, Color{0x98002e} }, // 1968 OSM: 10094533 WD: Q3239135 43.11, -79.89 x 43.65, -79.06
    { 4110, 2728, NoLogo, LineMetaDataContent::RapidTransit, Color{0x98002e} }, // 1984 OSM: 10094533 WD: Q3239135 43.11, -79.89 x 43.65, -79.06
    { 934, 2728, NoLogo, LineMetaDataContent::RapidTransit, Color{0x98002e} }, // 1992 OSM: 10094533 WD: Q3239135 43.11, -79.89 x 43.65, -79.06
    { 22, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xd6a461} }, // 18 OSM: 10095918 WD: Q6553089 31.04, 121.5 x 31.34, 121.6
    { 4115, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00214d} }, // 910 OSM: 10098291 55.76, 12.5 x 55.81, 12.53
    { 4119, 26684, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008150} }, // GL(D) OSM: 10099594 WD: Q172031 42.32, -71.25 x 42.38, -71.06
    { 132, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x4ea391} }, // 9 OSM: 10112938 47.12, 27.56 x 47.19, 27.59
    { 139, 27369, NoLogo, LineMetaDataContent::Subway, Color{0xb289bc} }, // 14 OSM: 10131355 WD: Q63781395 34.73, 113.5 x 34.78, 113.5
    { 4125, NoLogo, 3795, LineMetaDataContent::Subway, Color{0x3f48cc} }, // Daxing Airport OSM: 10136967 WD: Q19840478 39.51, 116.3 x 39.85, 116.4
    { 55, 27389, 24132, LineMetaDataContent::Subway, Color{0xa55fc8} }, // 1 OSM: 10149342 WD: Q18654264 36.5, 116.8 x 36.68, 116.9
    { 55, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xcd5c5c} }, // 1 OSM: 10163085 WD: Q66660306 31.63, 119.9 x 31.9, 120
    { 211, NoLogo, 27423, LineMetaDataContent::Tramway, Color{0x363d42} }, // T1 OSM: 10181950 WD: Q48747416 43.93, 4.799 x 43.94, 4.841
    { 4140, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x015698} }, // River Line OSM: 10213690 WD: Q2155505 39.94, -75.13 x 40.22, -74.71
    { 393, NoLogo, 26610, LineMetaDataContent::RapidTransit, Color{0xee343f} }, // L2 OSM: 10214162 WD: Q16927050 -33.92, 151.2 x -33.86, 151.2
    { 1989, NoLogo, 8817, LineMetaDataContent::Tramway, Color{0x873f98} }, // T6 OSM: 10218860 WD: Q21657685 45.73, 4.834 x 45.75, 4.897
    { 4072, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffe100} }, // OT OSM: 10238058 34.97, 135.7 x 35.07, 135.9
    { 61, NoLogo, 25398, LineMetaDataContent::RapidTransit, Color{0x81cd7b} }, // S1 OSM: 10249610 WD: Q3239193 47.51, 7.591 x 47.57, 8.063
    { 166, NoLogo, 25398, LineMetaDataContent::RapidTransit, Color{0x5ba3d8} }, // S3 OSM: 10249618 WD: Q3239191 47.33, 7.08 x 47.55, 7.918
    { 311, 27454, NoLogo, LineMetaDataContent::Subway, Color{0x00dd00} }, // C OSM: 10258970 WD: Q1057729 34.64, 135.4 x 34.73, 135.8
    { 314, NoLogo, 27470, LineMetaDataContent::RapidTransit, Color{0xbf1600} }, // S OSM: 10261953 WD: Q1621240 19.45, -99.2 x 19.67, -99.15
    { 4151, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x343f4b} }, // CMET OSM: 10271387 WD: Q16927042 -35.28, 149.1 x -35.19, 149.2
    { 4156, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x004792} }, // APT Blue OSM: 10274979 32.86, -96.94 x 32.87, -96.93
    { 397, NoLogo, 27496, LineMetaDataContent::Tramway, Color{0x009640} }, // L3 OSM: 10281452 WD: Q16655742 43.66, 7.194 x 43.71, 7.212
    { 1198, 27518, 2668, LineMetaDataContent::Subway, Color{0xff0a0a} }, // M3 OSM: 10283923 WD: Q1094251 55.67, 12.53 x 55.71, 12.59
    { 4165, 27066, NoLogo, LineMetaDataContent::Subway, Color{0x65b724} }, // BTS Sukhumvit OSM: 10285801 WD: Q4921598 13.57, 100.5 x 13.93, 100.6
    { 389, NoLogo, 27496, LineMetaDataContent::Tramway, Color{0xd20a11} }, // L1 OSM: 10286521 WD: Q3238669 43.7, 7.254 x 43.73, 7.293
    { 238, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // F OSM: 10286522 WD: Q3537109 35.91, 136.2 x 36.07, 136.2
    { 4179, 27530, 27555, LineMetaDataContent::RapidTransit, Color{0xf6a602} }, // D1 OSM: 10309188 WD: Q62091003 55.67, 37.28 x 56.01, 37.59
    { 4182, 27568, 27555, LineMetaDataContent::RapidTransit, Color{0xe83f83} }, // D2 OSM: 10309312 WD: Q62091175 55.43, 37.18 x 55.84, 37.74
    { 55, 27593, 27593, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 10309985 WD: Q2106 53.2, 50.13 x 53.21, 50.28
    { 4185, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff88bb} }, // Rochdale - East Didsbury OSM: 10310648 53.41, -2.28 x 53.62, -2.088
    { 4210, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x887766} }, // Shaw and Crompton - East Didsbury OSM: 10310683 53.41, -2.28 x 53.58, -2.089
    { 4244, 27615, NoLogo, LineMetaDataContent::Subway, Color{0xffd700} }, // JB OSM: 10312072 WD: Q1091295 35.61, 139.6 x 35.9, 140.1
    { 2339, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0066bb} }, // Manchester Airport - Manchester Victoria OSM: 10314875 WD: Q22712167 53.37, -2.297 x 53.49, -2.238
    { 4247, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff7700} }, // Ashton-under-Lyne – MediaCityUK OSM: 10320090 53.47, -2.297 x 53.49, -2.098
    { 4281, NoLogo, 6703, LineMetaDataContent::Subway, Color{0xffffff} }, // Arcobaleno OSM: 10320583 WD: Q3832713 40.89, 14.21 x 40.97, 14.24
    { 1859, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xf9b428} }, // Gold OSM: 10322047 WD: Q22948672 25.26, 51.44 x 25.29, 51.57
    { 4292, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00ccff} }, // Ashton-under-Lyne – Eccles OSM: 10326857 WD: Q22087023 53.47, -2.335 x 53.49, -2.098
    { 4321, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x881188} }, // Piccadilly - Altrincham OSM: 10328430 WD: Q22087020 53.39, -2.347 x 53.48, -2.23
    { 2769, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffbb00} }, // Bury - Manchester Piccadilly OSM: 10334672 53.48, -2.321 x 53.59, -2.226
    { 4345, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008800} }, // Altrincham – Bury OSM: 10334764 53.39, -2.347 x 53.59, -2.226
    { 4365, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xd32232} }, // ESFECO OSM: 10334823 WD: Q1132053 -22.95, -43.22 x -22.94, -43.2
    { 4372, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff6600} }, // MSC 821 OSM: 10366537 14.17, 121 x 14.62, 121.3
    { 4380, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff6600} }, // MSC 1708 OSM: 10366538 14.17, 121 x 14.62, 121.3
    { 55, 27637, NoLogo, LineMetaDataContent::Subway, Color{0xbf3a35} }, // 1 OSM: 10379854 WD: Q47004909 34.24, 117.1 x 34.27, 117.3
    { 55, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0080bc} }, // 1 OSM: 10380194 WD: Q10893610 36.04, 103.7 x 36.1, 103.9
    { 139, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xccad02} }, // 14 OSM: 10381397 WD: Q85884202 34.37, 108.8 x 34.46, 109.1
    { 59, 27653, NoLogo, LineMetaDataContent::Subway, Color{0xf39800} }, // 3 OSM: 10383244 WD: Q10946022 29.65, 121.4 x 29.91, 121.6
    { 4389, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x073686} }, // KS OSM: 10384058 WD: Q855470 35.53, 139.8 x 35.81, 140.4
    { 6, 27674, NoLogo, LineMetaDataContent::Subway, Color{0x0db0c8} }, // 5 OSM: 10386968 WD: Q11102446 30.17, 120 x 30.32, 120.3
    { 6, 27694, NoLogo, LineMetaDataContent::Subway, Color{0x2a5947} }, // 5 OSM: 10387105 WD: Q15928521 34.72, 113.6 x 34.78, 113.8
    { 1189, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffa500} }, // 22 OSM: 10396259 WD: Q2885972 52.07, 5.112 x 52.09, 5.184
    { 4392, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x96c93c} }, // Taipa OSM: 10402175 WD: Q15935354 22.14, 113.5 x 22.16, 113.6
    { 480, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x009530} }, // Green OSM: 10403427 WD: Q25343673 25.27, 51.35 x 25.32, 51.53
    { 4398, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xdb6198} }, // 305 OSM: 10409526 51.46, 7.152 x 51.48, 7.324
    { 4402, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x40558e} }, // 309 OSM: 10409567 51.44, 7.297 x 51.48, 7.337
    { 4406, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe28e07} }, // 316 OSM: 10409642 51.48, 7.16 x 51.53, 7.272
    { 397, NoLogo, 26610, LineMetaDataContent::RapidTransit, Color{0xee343f} }, // L3 OSM: 10411683 WD: Q16927050 -33.93, 151.2 x -33.86, 151.2
    { 55, 27713, NoLogo, LineMetaDataContent::Tramway, Color{0x96368b} }, // 1 OSM: 10413963 WD: Q15883002 51.2, 4.388 x 51.26, 4.421
    { 4410, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // 4М OSM: 10423669 47.83, 33.34 x 48, 33.5
    { 4414, 5860, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // 3М OSM: 10423670 WD: Q106432004 47.88, 33.39 x 48, 33.5
    { 4418, 19951, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // 2М OSM: 10423671 WD: Q106432003 47.89, 33.39 x 48, 33.5
    { 4422, 19720, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // 1М OSM: 10423672 WD: Q106432002 47.89, 33.39 x 47.96, 33.46
    { 311, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffa500} }, // C OSM: 10423828 WD: Q5061366 18.79, 72.83 x 19.65, 73.47
    { 3532, 7490, 226, LineMetaDataContent::RapidTransit, Color{0x006db6} }, // RB 32 OSM: 10432813 WD: Q7388251 51.43, 6.775 x 51.58, 7.459
    { 4426, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe73035} }, // Fredericksburg OSM: 10433416 38.22, -77.46 x 38.9, -77
    { 4441, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00bbb3} }, // CHW OSM: 10433666 WD: Q5093959 39.95, -75.21 x 40.08, -75.15
    { 4445, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa57b27} }, // CHE OSM: 10433667 WD: Q5093950 39.95, -75.21 x 40.08, -75.15
    { 4449, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x91456c} }, // AIR OSM: 10433668 WD: Q4698916 39.87, -75.26 x 39.96, -75.16
    { 4453, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x775ca7} }, // CYN OSM: 10433669 WD: Q5200188 39.95, -75.23 x 40.01, -75.17
    { 4457, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xee5067} }, // NOR OSM: 10433670 WD: Q6747157 39.95, -75.35 x 40.12, -75.15
    { 4461, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0081c5} }, // ELW OSM: 10433671 WD: Q6805374 39.89, -75.46 x 39.98, -75.15
    { 4465, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x8ed16a} }, // NWK OSM: 10433672 WD: Q8022734 39.67, -75.75 x 39.96, -75.16
    { 1238, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xc72a80} }, // L5 OSM: 10443588 46.18, 5.999 x 46.22, 6.144
    { 1242, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00b3b9} }, // L6 OSM: 10447940 46.1, 5.821 x 46.22, 6.144
    { 16, 27735, NoLogo, LineMetaDataContent::Subway, Color{0x00643a} }, // 2 OSM: 10458608 WD: Q20063925 26.04, 119.1 x 26.11, 119.4
    { 385, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xdc911b} }, // L4 OSM: 10464491 46.17, 6.121 x 46.32, 6.237
    { 54, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x3850a2} }, // 11 OSM: 10467354 WD: Q15944362 36.1, 120.5 x 36.48, 120.8
    { 58, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x00ac84} }, // 13 OSM: 10467728 WD: Q15937512 35.67, 119.7 x 35.95, 120.2
    { 4469, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // Sado OSM: 10484570 WD: Q1314068 38.51, -9.08 x 38.66, -8.838
    { 179, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00ace7} }, // 17 OSM: 10486182 WD: Q3238620 46.19, 6.125 x 46.2, 6.232
    { 524, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // A OSM: 10486983 WD: Q3239053 47.83, 1.9 x 47.93, 1.939
    { 16, NoLogo, 24234, LineMetaDataContent::Subway, Color{0x4bb134} }, // 2 OSM: 10488738 WD: Q24838989 24.48, 117.9 x 24.58, 118.2
    { 59, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xf57b00} }, // 3 OSM: 10488912 WD: Q6112757 31.26, 120.5 x 31.37, 120.8
    { 59, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x098137} }, // 3 OSM: 10488951 WD: Q17023374 31.75, 117.2 x 31.93, 117.4
    { 537, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x44d62c} }, // T2 OSM: 10490757 30.69, 103.8 x 30.83, 104
    { 196, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x72277b} }, // B OSM: 10494114 WD: Q3239067 47.9, 1.854 x 47.91, 1.977
    { 397, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x6c9d40} }, // L3 OSM: 10505987 45.91, 6.121 x 46.32, 6.703
    { 3082, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x44d62c} }, // T2B OSM: 10506169 30.73, 104 x 30.8, 104
    { 55, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xe82311} }, // 1 OSM: 10507454 WD: Q76339003 40.78, 111.6 x 40.86, 111.8
    { 59, 27754, 24132, LineMetaDataContent::Subway, Color{0x3f63e6} }, // 3 OSM: 10513363 WD: Q24837836 36.62, 117.1 x 36.77, 117.2
    { 4474, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x4ca585} }, // TGM1 OSM: 10519279 22.9, 112.8 x 22.95, 112.9
    { 389, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xbf3527} }, // L1 OSM: 10521809 46.17, 6.121 x 46.4, 6.581
    { 393, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0085c4} }, // L2 OSM: 10526246 45.9, 6.116 x 46.32, 6.362
    { 6, 27788, NoLogo, LineMetaDataContent::Subway, Color{0xbb29bb} }, // 5 OSM: 10526316 WD: Q22100474 30.45, 104 x 30.83, 104.1
    { 4479, 27798, NoLogo, LineMetaDataContent::LocalTrain, Color{0xe31937} }, // Hartford Line OSM: 10530881 WD: Q7008596 41.3, -72.93 x 42.11, -72.58
    { 4493, 27828, NoLogo, LineMetaDataContent::LongDistanceTrain, Color{0x007dbe} }, // IR 65 OSM: 10533323 WD: Q116053231 46.95, 7.24 x 47.13, 7.47
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffcc11} }, // 2 OSM: 10547015 WD: Q1878641 51, 3.709 x 51.05, 3.773
    { 132, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xef7c00} }, // 9 OSM: 10547655 48.34, 10.89 x 48.37, 10.9
    { 524, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe3028c} }, // A OSM: 10551319 WD: Q93096868 48.38, -4.556 x 48.43, -4.444
    { 139, 27843, NoLogo, LineMetaDataContent::Subway, Color{0x827a04} }, // 14 OSM: 10557252 WD: Q6553074 31.22, 121.3 x 31.27, 121.6
    { 1334, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf9661e} }, // Orange OSM: 10561837 37.36, -122.1 x 37.42, -121.8
    { 4499, NoLogo, 27853, LineMetaDataContent::RapidTransit, Color{0x4782ff} }, // 91/Perris Valley OSM: 10563416 WD: Q4645737 33.76, -118.2 x 34.06, -117.2
    { 4516, NoLogo, 27853, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // Inland Empire-Orange County OSM: 10563417 WD: Q6380515 33.19, -117.9 x 34.1, -117.3
    { 4530, NoLogo, 27853, LineMetaDataContent::RapidTransit, Color{0xff8000} }, // Orange County OSM: 10563418 WD: Q5220500 33.19, -118.2 x 34.06, -117.4
    { 4544, NoLogo, 27853, LineMetaDataContent::RapidTransit, Color{0x800080} }, // Riverside OSM: 10563419 WD: Q4801982 33.96, -118.2 x 34.06, -117.4
    { 4554, NoLogo, 27853, LineMetaDataContent::RapidTransit, Color{0x800000} }, // San Bernardino OSM: 10563420 WD: Q4798016 34.05, -118.2 x 34.11, -117.2
    { 4569, NoLogo, 27853, LineMetaDataContent::RapidTransit, Color{0xffc260} }, // Ventura County OSM: 10563421 WD: Q4132754 34.05, -119.2 x 34.29, -118.2
    { 4584, NoLogo, 27853, LineMetaDataContent::RapidTransit, Color{0x008000} }, // Antelope Valley OSM: 10563422 WD: Q4162507 34.05, -118.5 x 34.7, -118.1
    { 3426, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // Blue Line OSM: 10563564 25.31, 51.42 x 25.32, 51.43
    { 4600, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7c66a4} }, // Purple Line OSM: 10563805 25.37, 51.49 x 25.42, 51.53
    { 4612, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x4ba7a6} }, // Turquoise Line OSM: 10563806 25.41, 51.49 x 25.43, 51.5
    { 3805, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xdd722d} }, // Orange Line OSM: 10563807 25.37, 51.49 x 25.43, 51.53
    { 2618, 12345, 226, LineMetaDataContent::RapidTransit, Color{0x008000} }, // Central OSM: 10570207 WD: Q459508 -7.233, -39.41 x -7.206, -39.3
    { 55, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x8a8988} }, // 1 OSM: 10570395 WD: Q10318643 -5.111, -42.82 x -5.08, -42.74
    { 1599, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x008000} }, // CBTU OSM: 10570416 WD: Q18484877 -7.131, -34.98 x -6.974, -34.83
    { 3964, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // Norte OSM: 10570453 -3.683, -40.37 x -3.662, -40.34
    { 2310, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // Sul OSM: 10570461 -3.699, -40.36 x -3.682, -40.33
    { 4627, 27872, NoLogo, LineMetaDataContent::LocalTrain, Color{0xdf091d} }, // RE 1 OSM: 10573474 WD: Q322058 48.14, 11.08 x 49.45, 11.57
    { 4632, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // 550 OSM: 10577109 30.26, -97.86 x 30.59, -97.7
    { 16, 27888, NoLogo, LineMetaDataContent::Tramway, Color{0xf18e00} }, // 2 OSM: 10579671 WD: Q3238812 43.57, 3.831 x 43.65, 3.931
    { 59, 27898, NoLogo, LineMetaDataContent::Tramway, Color{0xcbd300} }, // 3 OSM: 10579672 WD: Q3238911 43.56, 3.81 x 43.62, 3.964
    { 55, 27908, NoLogo, LineMetaDataContent::Tramway, Color{0x005ba1} }, // 1 OSM: 10579673 WD: Q3238667 43.6, 3.817 x 43.64, 3.92
    { 4636, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xee293d} }, // TEX OSM: 10580066 WD: Q28228164 32.75, -97.34 x 32.94, -97.04
    { 4640, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00ff80} }, // 630 OSM: 10588005 32.72, -117.4 x 33.19, -117.2
    { 4644, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00ff80} }, // 662 OSM: 10588005 32.72, -117.4 x 33.19, -117.2
    { 1966, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00ff80} }, // 654 OSM: 10588005 32.72, -117.4 x 33.19, -117.2
    { 4648, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00ff80} }, // 636 OSM: 10588005 32.72, -117.4 x 33.19, -117.2
    { 4652, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00ff80} }, // 656 OSM: 10588005 32.72, -117.4 x 33.19, -117.2
    { 4656, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00ff80} }, // 640 OSM: 10588005 32.72, -117.4 x 33.19, -117.2
    { 4660, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x55502b} }, // UP Express OSM: 10608917 WD: Q497520 43.64, -79.62 x 43.71, -79.38
    { 3516, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7d4d31} }, // S15 OSM: 10615459 47.46, 8.895 x 47.56, 9.041
    { 966, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x9285bf} }, // S10 OSM: 10615934 47.46, 9.021 x 47.57, 9.38
    { 4671, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x794400} }, // Stouffville OSM: 10624851 WD: Q3239216 43.64, -79.38 x 44, -79.23
    { 4683, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x009ac7} }, // Richmond Hill OSM: 10624852 WD: Q3239183 43.64, -79.43 x 43.88, -79.32
    { 4697, 27918, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf57f25} }, // Milton OSM: 10624853 WD: Q3239156 43.52, -79.87 x 43.67, -79.38
    { 4704, 27937, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00853f} }, // Kitchener OSM: 10624854 WD: Q3239126 42.98, -81.25 x 43.71, -79.38
    { 4714, 27959, NoLogo, LineMetaDataContent::RapidTransit, Color{0x003768} }, // Barrie OSM: 10624855 WD: Q3239071 43.64, -79.69 x 44.37, -79.38
    { 4721, 27978, NoLogo, LineMetaDataContent::RapidTransit, Color{0xee3124} }, // Lakeshore East OSM: 10624856 WD: Q3239134 43.64, -79.38 x 43.87, -78.89
    { 1018, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x8c86bf} }, // S28 OSM: 10644936 WD: Q115747154 47.29, 7.939 x 47.39, 8.17
    { 4736, 2728, NoLogo, LineMetaDataContent::RapidTransit, Color{0x9f142c} }, // Lakeshore West OSM: 10647448 WD: Q3239135 43.25, -79.89 x 43.65, -79.38
    { 4751, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xb41d8e} }, // S22 OSM: 10650450 47.39, 9.359 x 47.43, 9.462
    { 884, 28005, NoLogo, LineMetaDataContent::Subway, Color{0xfedb00} }, // Y OSM: 10658528 WD: Q5971413 24.98, 121.5 x 25.06, 121.5
    { 3695, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x00ffff} }, // Aqua Line OSM: 10659365 WD: Q62051025 21.11, 78.99 x 21.15, 79.15
    { 2514, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf7941d} }, // S14 OSM: 10685821 47.56, 9.103 x 47.66, 9.192
    { 4755, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xadd8e6} }, // LRT OSM: 10693161 WD: Q65762187 -6.193, 106.9 x -6.155, 106.9
    { 41, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf26531} }, // S7 OSM: 10696321 47.48, 9.102 x 47.57, 9.51
    { 4759, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x3e6c01} }, // 102 OSM: 10696526 39.91, -75.3 x 39.96, -75.26
    { 4763, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x3e6c01} }, // 101 OSM: 10696527 39.91, -75.39 x 39.96, -75.26
    { 166, 28029, 2154, LineMetaDataContent::RapidTransit, Color{0xe6007e} }, // S3 OSM: 10699280 WD: Q116125181 46.95, 15.42 x 47.1, 16.02
    { 65, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x3e6c01} }, // 10 OSM: 10703006 WD: Q839339 39.95, -75.25 x 39.98, -75.16
    { 2104, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x3e6c01} }, // 34 OSM: 10703188 WD: Q839339 39.94, -75.25 x 39.96, -75.16
    { 1193, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x3e6c01} }, // 36 OSM: 10703676 WD: Q839339 39.9, -75.24 x 39.96, -75.16
    { 54, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x3e6c01} }, // 11 OSM: 10705415 WD: Q839339 39.92, -75.26 x 39.96, -75.16
    { 58, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x3e6c01} }, // 13 OSM: 10705526 WD: Q839339 39.92, -75.26 x 39.96, -75.16
    { 50, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x5da526} }, // S2 OSM: 10724094 WD: Q115646644 46.82, 8.496 x 47.45, 9.063
    { 166, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0xf58220} }, // S3 OSM: 10724334 WD: Q115646645 47, 8.297 x 47.1, 8.632
    { 218, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0xa62b48} }, // S4 OSM: 10736536 WD: Q115646646 46.91, 8.3 x 47.05, 8.398
    { 44, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0xee3d96} }, // S5 OSM: 10736575 WD: Q115646648 46.84, 8.185 x 47.05, 8.314
    { 204, 28047, 2154, LineMetaDataContent::RapidTransit, Color{0xf39200} }, // S6 OSM: 10748876 WD: Q116125188 46.72, 15.21 x 47.07, 15.48
    { 346, 28065, 6703, LineMetaDataContent::Subway, Color{0x5d9732} }, // M2 OSM: 10760559 WD: Q2519385 45.4, 9.145 x 45.55, 9.437
    { 1198, 28085, 6703, LineMetaDataContent::Subway, Color{0xfdb813} }, // M3 OSM: 10788272 WD: Q2519355 45.43, 9.163 x 45.53, 9.257
    { 265, 28105, 6703, LineMetaDataContent::Subway, Color{0xee2e24} }, // M1 OSM: 10803053 WD: Q2400801 45.46, 9.084 x 45.54, 9.239
    { 182, NoLogo, 28125, LineMetaDataContent::RapidTransit, Color{0x644215} }, // S50 OSM: 10816434 WD: Q110305283 46.48, 6.836 x 46.62, 7.087
    { 2066, NoLogo, 28125, LineMetaDataContent::RapidTransit, Color{0x0c5a6c} }, // S30 OSM: 10816437 WD: Q115701424 46.78, 6.638 x 46.85, 7.154
    { 1855, NoLogo, 28125, LineMetaDataContent::RapidTransit, Color{0x6e9ed4} }, // S21 OSM: 10816438 WD: Q110305258 46.8, 7.094 x 47, 7.154
    { 1211, NoLogo, 28125, LineMetaDataContent::RapidTransit, Color{0x24318a} }, // S20 OSM: 10816439 WD: Q115702408 46.8, 6.933 x 47.01, 7.154
    { 143, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x3fbfaa} }, // 15 OSM: 10899251 47.1, 37.62 x 47.12, 37.65
    { 8, 28151, 2668, LineMetaDataContent::Subway, Color{0x36b6f1} }, // M4 OSM: 10925800 WD: Q88965328 55.67, 12.56 x 55.71, 12.6
    { 4767, 28163, NoLogo, LineMetaDataContent::RapidTransit, Color{0xed772d} }, // SI OSM: 10956060 WD: Q93546 35.72, 139.2 x 35.91, 139.7
    { 44, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x8dc63f} }, // S5 OSM: 10958455 47.4, 9.102 x 47.57, 9.642
    { 982, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x6a489d} }, // S12 OSM: 10961967 WD: Q106455671 46.85, 9.441 x 47.05, 9.562
    { 190, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x38b54a} }, // S24 OSM: 10963118 47.36, 9.451 x 47.38, 9.538
    { 1855, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x089690} }, // S21 OSM: 10963311 WD: Q106455085 47.33, 9.359 x 47.43, 9.462
    { 3627, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffa500} }, // 1720 OSM: 10976185 13.13, 123.2 x 13.62, 123.8
    { 4770, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffa500} }, // 1645 OSM: 10976234 13.59, 123 x 13.77, 123.2
    { 3974, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffa500} }, // 1530 OSM: 10976234 13.59, 123 x 13.77, 123.2
    { 517, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x9f26b4} }, // N OSM: 11004619 WD: Q19877104 39.75, -105 x 39.92, -104.9
    { 4775, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xee0011} }, // The Trafford Centre – Cornbrook OSM: 11041584 WD: Q28404109 53.46, -2.348 x 53.47, -2.267
    { 443, 28182, NoLogo, LineMetaDataContent::Subway, Color{0x0000ff} }, // TS OSM: 11065562 WD: Q2791146 35.51, 139.4 x 36.11, 139.8
    { 26, 28216, NoLogo, LineMetaDataContent::Subway, Color{0xffb25b} }, // 16 OSM: 11076299 WD: Q22099544 30.2, 119.7 x 30.27, 120
    { 34, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x303888} }, // H OSM: 11093106 WD: Q5654835 18.94, 72.83 x 19.12, 73.12
    { 562, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xebcf1f} }, // W OSM: 11094510 WD: Q7988022 18.93, 72.81 x 19.46, 72.86
    { 4809, NoLogo, 22092, LineMetaDataContent::Subway, Color{0x252525} }, // JSQ–33 via HOB OSM: 11100813 WD: Q1931652 40.72, -74.06 x 40.75, -73.99
    { 65, 28237, NoLogo, LineMetaDataContent::Subway, Color{0x62aa3c} }, // 10 OSM: 11123255 WD: Q20688706 41.71, 123.3 x 41.86, 123.5
    { 314, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffc0cb} }, // S OSM: 11135401 WD: Q5364907 34.32, 134.1 x 34.34, 134.2
    { 447, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffff00} }, // K OSM: 11135402 WD: Q5371397 34.19, 133.8 x 34.35, 134.1
    { 517, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // N OSM: 11135412 WD: Q5364831 34.27, 134 x 34.35, 134.2
    { 61, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x000000} }, // S1 OSM: 11183563 47.15, 9.601 x 47.55, 9.817
    { 50, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x000000} }, // S2 OSM: 11185452 47.16, 9.078 x 47.48, 9.651
    { 166, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x000000} }, // S3 OSM: 11185510 47.45, 9.637 x 47.55, 9.754
    { 218, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x000000} }, // S4 OSM: 11185615 47.08, 9.816 x 47.15, 9.918
    { 41, 28269, 2154, LineMetaDataContent::RapidTransit, Color{0xbe1622} }, // S7 OSM: 11185888 WD: Q116125192 46.96, 15.08 x 47.07, 15.42
    { 83, 28287, 2154, LineMetaDataContent::RapidTransit, Color{0xf39200} }, // S61 OSM: 11185889 WD: Q116125190 46.72, 15.21 x 47.07, 15.42
    { 4826, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff6319} }, // <F> OSM: 11248274 40.58, -74 x 40.77, -73.78
    { 59, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xabcd03} }, // 3 OSM: 11257190 WD: Q17030673 28.1, 112.9 x 28.25, 113.1
    { 6, 28306, NoLogo, LineMetaDataContent::Subway, Color{0xffe200} }, // 5 OSM: 11257230 WD: Q18668926 28.09, 113 x 28.29, 113.1
    { 4830, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00aff0} }, // S76 OSM: 11266353 WD: Q100707374 47.49, 18.9 x 47.62, 19.17
    { 4834, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00aeef} }, // HBLR OSM: 11269271 WD: Q114054273 40.65, -74.13 x 40.79, -74.01
    { 995, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x9a6b31} }, // S42 OSM: 11277216 WD: Q106451501 47.28, 8.204 x 47.44, 8.539
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 3 OSM: 11279461 46.95, 31.98 x 46.98, 32.03
    { 1198, 28325, 18659, LineMetaDataContent::Subway, Color{0x008000} }, // M3 OSM: 11299964 WD: Q12289405 42.68, 23.24 x 42.7, 23.35
    { 143, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x3e6c01} }, // 15 OSM: 11328858 39.96, -75.25 x 39.98, -75.13
    { 4839, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // RL(M) OSM: 11359791 WD: Q172144 42.27, -71.09 x 42.28, -71.06
    { 4845, 26684, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008150} }, // GL(B) OSM: 11359792 WD: Q172011 42.34, -71.17 x 42.36, -71.06
    { 4851, 26684, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008150} }, // GL(C) OSM: 11359793 WD: Q172022 42.34, -71.15 x 42.36, -71.06
    { 4857, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x73757d} }, // Metro OSM: 11364344 42.88, -78.88 x 42.95, -78.82
    { 272, NoLogo, 28350, LineMetaDataContent::RapidTransit, Color{0x0000f8} }, // Blue OSM: 11366428 WD: Q4929372 38.59, -90.35 x 38.65, -90.05
    { 284, NoLogo, 28350, LineMetaDataContent::RapidTransit, Color{0xf80000} }, // Red OSM: 11366429 WD: Q7304508 38.51, -90.36 x 38.74, -89.88
    { 80, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 63 OSM: 11375919 59.93, 30.44 x 59.96, 30.49
    { 2606, 25357, NoLogo, LineMetaDataContent::LocalTrain, Color{0x00874d} }, // C-2 OSM: 11378343 WD: Q5987206 37.39, -6.01 x 37.45, -5.95
    { 486, 28378, NoLogo, LineMetaDataContent::LocalTrain, Color{0x619bc1} }, // C-1 OSM: 11378450 WD: Q5987193 37.18, -5.98 x 37.66, -5.53
    { 2127, 28397, NoLogo, LineMetaDataContent::LocalTrain, Color{0xff061d} }, // C-3 OSM: 11382024 WD: Q5987212 37.39, -5.975 x 37.93, -5.704
    { 3674, 25324, NoLogo, LineMetaDataContent::LocalTrain, Color{0x991b87} }, // C-4 OSM: 11382119 WD: Q5987216 37.34, -5.98 x 37.42, -5.934
    { 1732, 28409, NoLogo, LineMetaDataContent::LocalTrain, Color{0x053388} }, // C-5 OSM: 11384993 WD: Q5987218 37.33, -6.208 x 37.45, -5.95
    { 41, 28427, 24914, LineMetaDataContent::RapidTransit, Color{0xf60060} }, // S7 OSM: 11479781 WD: Q26878568 45.48, 9.179 x 45.86, 9.399
    { 61, NoLogo, 28441, LineMetaDataContent::RapidTransit, Color{0x11385b} }, // S1 OSM: 11482970 WD: Q43285793 39.7, 116.1 x 39.9, 116.7
    { 2540, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x55c5d0} }, // S81 OSM: 11484467 47.39, 9.275 x 47.42, 9.369
    { 4863, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00b9f2} }, // S82 OSM: 11484468 47.42, 9.367 x 47.46, 9.4
    { 2606, 15914, NoLogo, LineMetaDataContent::LocalTrain, Color{0x00874d} }, // C-2 OSM: 11488015 WD: Q5987203 36.7, -4.724 x 36.82, -4.427
    { 486, 20562, NoLogo, LineMetaDataContent::LocalTrain, Color{0x619bc1} }, // C-1 OSM: 11488016 WD: Q25411554 36.54, -4.624 x 36.72, -4.427
    { 324, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf0d808} }, // U OSM: 11490692 WD: Q28153731 18.88, 72.95 x 19.03, 73.04
    { 39, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x4b0082} }, // T OSM: 11490693 WD: Q7833528 18.99, 72.97 x 19.19, 73.12
    { 50, NoLogo, 28441, LineMetaDataContent::RapidTransit, Color{0x11385b} }, // S2 OSM: 11494225 WD: Q4390966 40.07, 115.5 x 40.44, 116.3
    { 44, NoLogo, 28441, LineMetaDataContent::RapidTransit, Color{0xfabbcb} }, // S5 OSM: 11494329 WD: Q42308711 39.94, 116.2 x 40.69, 117.1
    { 656, 28454, 28454, LineMetaDataContent::RapidTransit, Color{0x0092db} }, // 301 OSM: 11494376 WD: Q106676138 43.42, -80.55 x 43.5, -80.44
    { 4867, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff061d} }, // C-1a OSM: 11498247 36.53, -6.206 x 36.54, -6.194
    { 204, NoLogo, 25398, LineMetaDataContent::RapidTransit, Color{0xe9583f} }, // S6 OSM: 11519985 WD: Q63705067 47.54, 7.591 x 47.71, 7.849
    { 4872, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0072bc} }, // N6 OSM: 11522997 47.55, 7.587 x 47.59, 7.656
    { 1198, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffcf06} }, // M3 OSM: 11525600 WD: Q2637212 50.41, 4.43 x 50.48, 4.452
    { 4875, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // Thilawa OSM: 11548643 16.66, 96.16 x 16.86, 96.26
    { 4883, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // Eastern University OSM: 11548647 16.74, 96.16 x 16.86, 96.29
    { 4902, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // Ywar Thar Gyi OSM: 11548648 16.78, 96.16 x 16.93, 96.27
    { 4916, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffff00} }, // Computer University OSM: 11548671 16.78, 96.07 x 17.01, 96.16
    { 4936, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffff00} }, // Insein - Hlaw Karr OSM: 11548680 16.87, 96.08 x 17, 96.11
    { 4955, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // Dagon University OSM: 11549059 16.78, 96.16 x 16.91, 96.23
    { 2104, NoLogo, 13916, LineMetaDataContent::Tramway, Color{0x858585} }, // 34 OSM: 11565304 WD: Q100991407 52.04, 4.244 x 52.08, 4.543
    { 4972, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe1e1ff} }, // SN 4 OSM: 11566470 50.97, -0.1728 x 51.5, 0.213
    { 4977, 28476, NoLogo, LineMetaDataContent::LocalTrain, Color{0x00bfff} }, // KK OSM: 11568311 WD: Q906807 35.18, 139.6 x 35.64, 139.8
    { 16, NoLogo, 20093, LineMetaDataContent::Subway, Color{0xfec30a} }, // 2 OSM: 11582700 WD: Q85776743 37.97, 114.5 x 38.09, 114.5
    { 27, 28502, NoLogo, LineMetaDataContent::Subway, Color{0x3abca8} }, // 6 OSM: 11583149 WD: Q6119435 22.54, 113.8 x 22.79, 114.1
    { 65, 28525, NoLogo, LineMetaDataContent::Subway, Color{0xf8779e} }, // 10 OSM: 11583622 WD: Q15925362 22.52, 114.1 x 22.7, 114.1
    { 4980, 25357, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008a29} }, // C-2 (CIVIS) OSM: 11589066 WD: Q2287356 40.44, -3.682 x 40.64, -3.183
    { 509, 28549, NoLogo, LineMetaDataContent::RapidTransit, Color{0x449ad5} }, // R1 OSM: 11592118 WD: Q2395239 41.36, 2.02 x 41.77, 2.769
    { 196, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x094b8d} }, // B OSM: 11592473 WD: Q4705897 -37.91, 144.9 x -37.76, 145.4
    { 8, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x84c8eb} }, // M4 OSM: 11592482 WD: Q1841724 50.41, 4.435 x 50.43, 4.503
    { 4992, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffb531} }, // CH OSM: 11592485 WD: Q7639008 -37.82, 144.7 x -37.58, 145
    { 4995, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xee1d23} }, // E11 OSM: 11604709 WD: Q106925455 47.48, 7.584 x 47.55, 7.612
    { 4999, 28566, 16926, LineMetaDataContent::Subway, Color{0xf5a200} }, // 272 OSM: 11619514 WD: Q84389881 37.24, 126.6 x 37.58, 127.1
    { 5003, 28588, 28629, LineMetaDataContent::Tramway, Color{0xdce3e9} }, // T1a OSM: 11636568 WD: Q117008305 38.72, 35.37 x 38.79, 35.63
    { 5007, 28647, 28629, LineMetaDataContent::Tramway, Color{0xdce3e9} }, // T2a OSM: 11636816 WD: Q117008320 38.69, 35.49 x 38.73, 35.56
    { 5011, 28688, NoLogo, LineMetaDataContent::Subway, Color{0xb8007c} }, // TL-3 OSM: 11637375 WD: Q5986357 20.62, -103.4 x 20.74, -103.3
    { 211, 28588, 28629, LineMetaDataContent::Tramway, Color{0xdce3e9} }, // T1 OSM: 11641755 WD: Q117008305 38.72, 35.37 x 38.79, 35.63
    { 9, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xffa500} }, // 4 OSM: 11643429 WD: Q24837537 24.86, 102.6 x 25.11, 102.9
    { 537, 28647, 28629, LineMetaDataContent::Tramway, Color{0xdce3e9} }, // T2 OSM: 11644048 WD: Q117008320 38.69, 35.49 x 38.73, 35.56
    { 5016, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xc16c18} }, // 4–环–5 OSM: 11665748 29.41, 106.4 x 29.63, 106.7
    { 5028, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xa58704} }, // BTS Gold Line OSM: 11681440 WD: Q25540775 13.72, 100.5 x 13.73, 100.5
    { 22, 28754, NoLogo, LineMetaDataContent::Subway, Color{0x006272} }, // 18 OSM: 11697795 WD: Q22100462 30.27, 104.1 x 30.61, 104.5
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0645ad} }, // 2 OSM: 11697809 WD: Q82669483 40.75, 111.6 x 40.87, 111.8
    { 11, NoLogo, 8310, LineMetaDataContent::Subway, Color{0xff8040} }, // M5 OSM: 11697885 WD: Q1641397 44.41, 26.01 x 44.44, 26.07
    { 16, 28765, 23650, LineMetaDataContent::Subway, Color{0x00ff00} }, // 2 OSM: 11720074 WD: Q6427302 22.57, 88.37 x 22.59, 88.43
    { 196, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x406681} }, // B OSM: 11727456 35.02, 135.7 x 35.03, 135.7
    { 3571, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xbd0d2e} }, // Π1 OSM: 11748540 WD: Q3536559 38.24, 21.73 x 38.3, 21.78
    { 3575, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x27509b} }, // Π2 OSM: 11748541 WD: Q3536559 38.14, 21.56 x 38.24, 21.73
    { 218, 28805, 2154, LineMetaDataContent::RapidTransit, Color{0xd7df23} }, // S4 OSM: 11758267 WD: Q112707549 47.25, 11.08 x 47.58, 12.17
    { 44, 28818, 2154, LineMetaDataContent::RapidTransit, Color{0x5b9a6d} }, // S5 OSM: 11758341 WD: Q112707550 47.24, 10.86 x 47.39, 11.78
    { 166, 28831, 2154, LineMetaDataContent::RapidTransit, Color{0xb4bece} }, // S3 OSM: 11763862 WD: Q112707548 47, 11.39 x 47.26, 11.51
    { 47, 28844, 2154, LineMetaDataContent::RapidTransit, Color{0x257ca7} }, // S8 OSM: 11763916 WD: Q112707555 47.42, 12.06 x 47.52, 12.63
    { 318, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x035eb9} }, // M OSM: 11772006 WD: Q118902123 61.17, 23.5 x 61.51, 23.86
    { 5042, 13086, NoLogo, LineMetaDataContent::LocalTrain, Color{0xfdda24} }, // 86967 OSM: 11792134 WD: Q205585 42.42, 2.866 x 43.83, 4.367
    { 5048, 13086, NoLogo, LineMetaDataContent::LocalTrain, Color{0xfdda24} }, // 86981 OSM: 11792135 WD: Q205585 42.42, 2.88 x 42.7, 3.168
    { 288, 13086, NoLogo, LineMetaDataContent::LocalTrain, Color{0xfdda24} }, // 86989 OSM: 11792146 WD: Q205585 42.42, 2.866 x 43.94, 4.805
    { 1279, 13086, NoLogo, LineMetaDataContent::LocalTrain, Color{0xfdda24} }, // 86987 OSM: 11792148 WD: Q205585 42.42, 2.866 x 43.94, 4.805
    { 921, 13086, NoLogo, LineMetaDataContent::LocalTrain, Color{0xfdda24} }, // 86998 OSM: 11792152 WD: Q205585 42.42, 2.866 x 43.83, 4.366
    { 331, 13086, NoLogo, LineMetaDataContent::LocalTrain, Color{0xfdda24} }, // 86996 OSM: 11792153 WD: Q205585 42.42, 2.866 x 43.83, 4.366
    { 5054, 13086, NoLogo, LineMetaDataContent::LocalTrain, Color{0xfdda24} }, // 86960 OSM: 11792154 WD: Q205585 42.42, 2.879 x 42.7, 3.168
    { 5060, 13086, NoLogo, LineMetaDataContent::LocalTrain, Color{0xfdda24} }, // 86964 OSM: 11792157 WD: Q205585 42.42, 2.879 x 42.7, 3.168
    { 1298, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x9a897e} }, // E5 OSM: 11796871 WD: Q104233835 43.3, -1.983 x 43.32, -1.931
    { 59, 28864, NoLogo, LineMetaDataContent::Subway, Color{0x0101f8} }, // 3 OSM: 11798336 WD: Q19852709 31.5, 120.2 x 31.6, 120.4
    { 5066, 28889, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0f6cc3} }, // TI OSM: 11801291 WD: Q906598 36.02, 139.2 x 36.33, 139.7
    { 5069, 28923, NoLogo, LineMetaDataContent::Subway, Color{0xf68b1e} }, // TN OSM: 11801775 WD: Q845954 35.51, 139.4 x 36.75, 139.8
    { 307, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xf7943a} }, // O OSM: 11803501 WD: Q18385578 31.46, 74.24 x 31.59, 74.43
    { 27, NoLogo, 6703, LineMetaDataContent::Subway, Color{0x0099cc} }, // 6 OSM: 11807149 WD: Q3832666 40.82, 14.19 x 40.84, 14.25
    { 1767, 28955, NoLogo, LineMetaDataContent::Tramway, Color{0xcc0099} }, // T3 OSM: 11813038 WD: Q117327547 36.88, 30.66 x 36.99, 30.72
    { 537, 28996, NoLogo, LineMetaDataContent::Tramway, Color{0x027ffd} }, // T2 OSM: 11813041 WD: Q116369823 36.87, 30.68 x 36.89, 30.72
    { 5072, 29037, NoLogo, LineMetaDataContent::Tramway, Color{0xff6400} }, // T1A OSM: 11813042 WD: Q117327542 36.89, 30.64 x 36.94, 30.81
    { 5076, 29079, NoLogo, LineMetaDataContent::Tramway, Color{0xff6400} }, // T1B OSM: 11813043 WD: Q117327753 36.89, 30.64 x 36.95, 30.88
    { 5080, 29121, NoLogo, LineMetaDataContent::LocalTrain, Color{} }, // FEX OSM: 11815470 WD: Q100533383 52.36, 13.36 x 52.55, 13.6
    { 5084, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // CK OSM: 11830794 WD: Q5097496 33.75, 130.7 x 33.87, 130.8
    { 34, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0072bc} }, // H OSM: 11839798 WD: Q1074266 42.64, 141.3 x 43.11, 141.7
    { 59, NoLogo, 18613, LineMetaDataContent::Subway, Color{0x008000} }, // 3 OSM: 11845129 WD: Q2889805 53.84, 27.53 x 53.91, 27.55
    { 5087, 29140, NoLogo, LineMetaDataContent::RapidTransit, Color{0xd12027} }, // NH OSM: 11851821 WD: Q1137838 34.76, 136.8 x 35.41, 137.4
    { 393, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000cd} }, // L2 OSM: 11871075 WD: Q42387974 30.44, 114.4 x 30.51, 114.5
    { 1859, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfece0c} }, // Gold OSM: 11873946 WD: Q5059275 35.21, -80.86 x 35.25, -80.82
    { 59, 29150, NoLogo, LineMetaDataContent::Subway, Color{0x90403e} }, // 3 OSM: 11899105 WD: Q30641320 21.03, 105.7 x 21.05, 105.8
    { 427, 29180, NoLogo, LineMetaDataContent::LocalTrain, Color{0x800080} }, // RB 48 OSM: 11913928 WD: Q107023360 48.04, 11.6 x 48.13, 12.19
    { 2202, NoLogo, 29197, LineMetaDataContent::Subway, Color{0xff0000} }, // UMRT1 OSM: 11919222 WD: Q61132107 10.77, 106.7 x 10.88, 106.8
    { 9, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xdae600} }, // 4 OSM: 11923211 WD: Q26262003 22.75, 108.2 x 22.77, 108.5
    { 1046, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xd77d00} }, // 31 OSM: 11997852 WD: Q1760190 59.33, 17.95 x 59.36, 17.98
    { 231, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 25 OSM: 12010107 WD: Q2619013 52.27, 4.831 x 52.34, 4.876
    { 27, 29217, NoLogo, LineMetaDataContent::Subway, Color{0xb36924} }, // 6 OSM: 12039115 WD: Q22100481 30.43, 103.9 x 30.81, 104.1
    { 393, NoLogo, 27496, LineMetaDataContent::Tramway, Color{0x004f9f} }, // L2 OSM: 12078298 WD: Q3238814 43.66, 7.199 x 43.7, 7.285
    { 19, 29227, NoLogo, LineMetaDataContent::Subway, Color{0x88dd00} }, // 8 OSM: 12086373 WD: Q26262006 30.54, 104 x 30.73, 104.2
    { 179, 29237, NoLogo, LineMetaDataContent::Subway, Color{0x80e0a7} }, // 17 OSM: 12095438 WD: Q28973151 30.63, 103.8 x 30.76, 104.2
    { 42, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 7 OSM: 12114202 44.78, 20.37 x 44.81, 20.52
    { 132, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 9 OSM: 12114471 44.76, 20.37 x 44.81, 20.48
    { 54, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 11 OSM: 12114747 44.79, 20.37 x 44.83, 20.46
    { 58, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 13 OSM: 12115860 44.77, 20.37 x 44.81, 20.43
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00985f} }, // 1 OSM: 12116142 60.16, 24.92 x 60.22, 24.96
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00985f} }, // 2 OSM: 12116144 60.16, 24.92 x 60.2, 24.96
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00985f} }, // 3 OSM: 12116149 60.16, 24.9 x 60.2, 24.96
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00985f} }, // 4 OSM: 12116155 60.17, 24.87 x 60.2, 24.98
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00985f} }, // 5 OSM: 12116158 60.16, 24.94 x 60.17, 24.97
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00985f} }, // 6 OSM: 12116159 60.15, 24.92 x 60.21, 24.98
    { 42, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00985f} }, // 7 OSM: 12116160 60.15, 24.92 x 60.2, 24.96
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00985f} }, // 8 OSM: 12116163 60.16, 24.91 x 60.21, 24.98
    { 132, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00985f} }, // 9 OSM: 12116164 60.15, 24.91 x 60.2, 24.95
    { 65, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00985f} }, // 10 OSM: 12116165 60.16, 24.89 x 60.21, 24.95
    { 451, 29248, 3199, LineMetaDataContent::RapidTransit, Color{0x7577c0} }, // L OSM: 12142601 WD: Q93379 48.81, 2.011 x 49.05, 2.324
    { 9, 29282, NoLogo, LineMetaDataContent::Subway, Color{0xabcd03} }, // 4 OSM: 12144421 WD: Q10946023 29.78, 121.4 x 29.98, 121.6
    { 5090, 29303, NoLogo, LineMetaDataContent::LocalTrain, Color{0xfbba00} }, // RB 14 OSM: 12144619 WD: Q106109581 48.74, 11.16 x 48.9, 11.44
    { 1527, 29320, 9839, LineMetaDataContent::Tramway, Color{0x7c72b3} }, // T5 OSM: 12174617 WD: Q48848864 41.02, 28.94 x 41.09, 28.96
    { 3152, 25632, NoLogo, LineMetaDataContent::Subway, Color{0x937cb9} }, // Z OSM: 12184336 WD: Q1190086 35.51, 139.4 x 36.11, 139.8
    { 50, 29348, 2154, LineMetaDataContent::RapidTransit, Color{0x4f9961} }, // S2 OSM: 12206186 WD: Q112707418 46.73, 12.27 x 46.83, 12.77
    { 143, 29361, NoLogo, LineMetaDataContent::Subway, Color{0xbba786} }, // 15 OSM: 12231218 WD: Q6553078 31.02, 121.4 x 31.35, 121.4
    { 1007, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x00c000} }, // 2A OSM: 12231738 WD: Q30919856 20.95, 105.7 x 21.03, 105.8
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfab71b} }, // 2 OSM: 12232119 50.89, 11.58 x 50.93, 11.62
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x6a2e74} }, // 5 OSM: 12232120 50.88, 11.58 x 50.93, 11.64
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xda020e} }, // 4 OSM: 12232121 50.88, 11.58 x 50.96, 11.62
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x7f5f00} }, // 3 OSM: 12232122 50.88, 11.58 x 50.9, 11.64
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe94c0a} }, // 1 OSM: 12232123 50.88, 11.58 x 50.96, 11.62
    { 5096, 29371, NoLogo, LineMetaDataContent::LocalTrain, Color{} }, // RB 54 OSM: 12233202 WD: Q113229669 47.58, 11.53 x 48.14, 12.2
    { 5102, 29388, NoLogo, LineMetaDataContent::LocalTrain, Color{} }, // RE 5 OSM: 12234223 WD: Q113228374 47.81, 11.53 x 48.14, 13.05
    { 5107, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf0e68c} }, // Limited OSM: 12246239 37, -122.4 x 37.78, -121.6
    { 4767, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xed772d} }, // SI OSM: 12250869 35.74, 139.3 x 35.85, 139.7
    { 5115, 29404, NoLogo, LineMetaDataContent::LocalTrain, Color{0xbf73bf} }, // RB 33 OSM: 12276395 WD: Q113257915 48.4, 11.74 x 48.55, 12.14
    { 5121, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe3e049} }, // TECO OSM: 12321313 27.94, -82.46 x 27.96, -82.44
    { 5126, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xdb161c} }, // QLine OSM: 12330605 42.33, -83.07 x 42.37, -83.05
    { 318, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // M OSM: 12331275 43.03, -87.92 x 43.05, -87.9
    { 314, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // S OSM: 12332844 34.65, 133.9 x 34.67, 133.9
    { 34, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // H OSM: 12332845 34.66, 133.9 x 34.67, 133.9
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // 2 OSM: 12340019 WD: Q18155116 29.95, -90.07 x 29.96, -90.06
    { 430, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x90ee90} }, // 48 OSM: 12340020 29.96, -90.1 x 29.98, -90.08
    { 547, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 47 OSM: 12340021 29.95, -90.11 x 29.98, -90.07
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 12 OSM: 12340022 29.93, -90.13 x 29.96, -90.07
    { 272, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00aae4} }, // Blue OSM: 12340243 34.74, -92.27 x 34.76, -92.26
    { 480, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x66ff00} }, // Green OSM: 12340244 34.74, -92.27 x 34.75, -92.26
    { 55, NoLogo, 6703, LineMetaDataContent::Subway, Color{0xfeca1b} }, // 1 OSM: 12341393 WD: Q1085934 40.84, 14.22 x 40.9, 14.27
    { 537, NoLogo, 29421, LineMetaDataContent::Tramway, Color{0x50ab43} }, // T2 OSM: 12342707 WD: Q30634535 38.4, 27.07 x 38.44, 27.17
    { 1565, NoLogo, 29441, LineMetaDataContent::RapidTransit, Color{0x800080} }, // Purple OSM: 12356340 WD: Q4533683 29.7, -95.37 x 29.76, -95.33
    { 284, NoLogo, 29441, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // Red OSM: 12356341 WD: Q16934038 29.67, -95.41 x 29.83, -95.36
    { 480, NoLogo, 29441, LineMetaDataContent::RapidTransit, Color{0x008000} }, // Green OSM: 12356342 WD: Q4262189 29.74, -95.37 x 29.76, -95.3
    { 5132, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff1b6e} }, // APT Rose OSM: 12360663 32.86, -96.94 x 32.87, -96.93
    { 5141, 29464, 12600, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // m1 OSM: 12371355 WD: Q685114 46.52, 6.564 x 46.54, 6.63
    { 211, NoLogo, 29421, LineMetaDataContent::Tramway, Color{0x50ab43} }, // T1 OSM: 12378475 WD: Q21523607 38.45, 27.07 x 38.48, 27.13
    { 59, 29491, NoLogo, LineMetaDataContent::Subway, Color{0xff8000} }, // 3 OSM: 12380649 WD: Q56377988 25.67, -100.3 x 25.71, -100.3
    { 6, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xc1d522} }, // 5 OSM: 12385671 WD: Q43445187 31.7, 117.3 x 31.94, 117.3
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x146eb7} }, // 4 OSM: 12400338 WD: Q107104582 40.83, 14.26 x 40.85, 14.31
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x4096d2} }, // 1 OSM: 12400369 WD: Q107104562 40.84, 14.26 x 40.87, 14.29
    { 970, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x8fbc8f} }, // 399 OSM: 12417807 33.12, -117.4 x 33.22, -117.1
    { 5144, 29505, NoLogo, LineMetaDataContent::RapidTransit, Color{0x9b26b6} }, // Π5 OSM: 12423300 WD: Q35645597 38.01, 22.1 x 38.24, 22.73
    { 16, 29540, 6703, LineMetaDataContent::Tramway, Color{0x025257} }, // 2 OSM: 12462807 WD: Q2274338 40.82, 14.13 x 40.87, 14.31
    { 5148, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0d82c7} }, // OH OSM: 12463786 WD: Q11430772 35.23, 139 x 35.69, 139.7
    { 204, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0xd72319} }, // S6 OSM: 12524258 WD: Q110186534 49.44, 10.58 x 49.58, 11.08
    { 5151, 29559, NoLogo, LineMetaDataContent::LocalTrain, Color{0xf37231} }, // RE 31 OSM: 12529911 WD: Q113462372 49.44, 11.08 x 50.31, 12.09
    { 5157, 29576, NoLogo, LineMetaDataContent::LocalTrain, Color{} }, // RE 32 OSM: 12535805 WD: Q113462373 49.9, 10.89 x 50.16, 11.6
    { 5163, 29593, NoLogo, LineMetaDataContent::LocalTrain, Color{} }, // RE 35 OSM: 12535884 WD: Q113462494 49.9, 10.89 x 50.31, 11.94
    { 5169, 29610, NoLogo, LineMetaDataContent::LocalTrain, Color{} }, // RB 18 OSM: 12548478 WD: Q104149638 50.26, 10.78 x 50.34, 10.96
    { 5175, 29627, 5211, LineMetaDataContent::Tramway, Color{0x5291ce} }, // T9 OSM: 12564972 WD: Q3537038 48.75, 2.365 x 48.82, 2.419
    { 211, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xd22630} }, // T1 OSM: 12567203 39.71, 116.5 x 39.8, 116.6
    { 5178, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x015dab} }, // Atlantic City OSM: 12577780 WD: Q756350 39.36, -75.2 x 40.01, -74.44
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 1 OSM: 12606970 WD: Q107191166 37.99, -1.174 x 38.04, -1.124
    { 2908, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x78b942} }, // Verde OSM: 12632067 -9.672, -35.74 x -9.65, -35.72
    { 2939, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x1a5ba3} }, // Azul OSM: 12632071 -9.625, -35.86 x -9.478, -35.75
    { 8, NoLogo, 18659, LineMetaDataContent::Subway, Color{0xffff00} }, // M4 OSM: 12668937 WD: Q101570868 42.65, 23.26 x 42.74, 23.42
    { 55, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfdc434} }, // 1 OSM: 12686111 WD: Q56388740 46.24, 20.12 x 46.42, 20.34
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 3 OSM: 12758107 61.44, 23.74 x 61.5, 23.87
    { 459, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x81cf00} }, // R OSM: 12765542 WD: Q3239181 50.64, 3.071 x 50.69, 3.179
    { 39, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0099ff} }, // T OSM: 12765723 WD: Q3239234 50.64, 3.071 x 50.72, 3.159
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 2 OSM: 12771496 31.56, 130.5 x 31.6, 130.6
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // 1 OSM: 12771497 31.53, 130.5 x 31.6, 130.6
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x005bac} }, // 2 OSM: 12791164 WD: Q19856264 26.52, 106.6 x 26.7, 106.8
    { 5192, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xcc0000} }, // Route 2020 OSM: 12820286 WD: Q97940934 24.96, 55.13 x 25.06, 55.16
    { 59, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x800080} }, // 3 OSM: 12824257 12.82, 80.22 x 13.15, 80.27
    { 9, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff8000} }, // 4 OSM: 12824987 13.03, 80.08 x 13.05, 80.28
    { 5203, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // IR87 OSM: 12856601 47.49, 19.08 x 47.89, 20.42
    { 5208, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xaacd46} }, // G40 OSM: 12856603 WD: Q112963120 46.37, 18.15 x 47.5, 19.04
    { 5212, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffcd28} }, // Z42 OSM: 12856604 WD: Q112225437 46.96, 18.76 x 47.5, 19.04
    { 59, NoLogo, 24234, LineMetaDataContent::Subway, Color{0x0c89de} }, // 3 OSM: 12893656 WD: Q47500936 24.43, 118.1 x 24.58, 118.3
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x529fc9} }, // 2 OSM: 12914035 WD: Q106783516 31.75, 119.9 x 31.81, 120.1
    { 55, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xc5003e} }, // 1 OSM: 12920991 WD: Q24836509 29.92, 120.2 x 30.31, 120.6
    { 6, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xa6e35f} }, // 5 OSM: 12925442 WD: Q15939245 34.22, 108.7 x 34.27, 109
    { 59, 27637, NoLogo, LineMetaDataContent::Subway, Color{0x008bd5} }, // 3 OSM: 12935364 WD: Q47291030 34.15, 117.2 x 34.28, 117.2
    { 16, 27637, NoLogo, LineMetaDataContent::Subway, Color{0xef8200} }, // 2 OSM: 12935365 WD: Q47004987 34.21, 117.2 x 34.33, 117.3
    { 6, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // 5 OSM: 12940681 12.9, 80.16 x 13.16, 80.24
    { 55, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xc4608c} }, // 1 OSM: 12942003 WD: Q15936968 34.66, 112.3 x 34.7, 112.6
    { 27, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x767fb8} }, // 6 OSM: 13040751 WD: Q52596166 34.15, 108.8 x 34.28, 109.1
    { 132, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xec9e3c} }, // 9 OSM: 13042254 WD: Q97350661 34.27, 109.1 x 34.4, 109.2
    { 19, 29660, NoLogo, LineMetaDataContent::Subway, Color{0xac145a} }, // 8 OSM: 13042427 WD: Q11102451 30.3, 120.4 x 30.31, 120.5
    { 55, NoLogo, 18006, LineMetaDataContent::RapidTransit, Color{0xe10506} }, // 1 OSM: 13058394 WD: Q15078613 13.8, 100.5 x 14, 100.6
    { 132, 29670, NoLogo, LineMetaDataContent::Subway, Color{0xbe4d00} }, // 9 OSM: 13060970 WD: Q18653898 30.25, 120.2 x 30.46, 120.3
    { 55, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xdfaa00} }, // 1 OSM: 13067815 WD: Q15935678 35.94, 120.2 x 36.34, 120.4
    { 19, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xc02996} }, // 8 OSM: 13068450 WD: Q22100048 36.17, 120 x 36.4, 120.4
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 1 OSM: 13072753 61.49, 23.77 x 61.51, 23.82
    { 27, 29680, NoLogo, LineMetaDataContent::Subway, Color{0x0072ce} }, // 6 OSM: 13077350 WD: Q11102449 30.05, 119.9 x 30.3, 120.2
    { 9, 29694, NoLogo, LineMetaDataContent::Subway, Color{0x6bc349} }, // 4 OSM: 13077360 WD: Q11102444 30.16, 120.1 x 30.36, 120.2
    { 5216, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0077c8} }, // HH OSM: 13078550 30.38, 120.3 x 30.52, 120.7
    { 61, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x1b61ae} }, // S1 OSM: 13084233 27.91, 120.6 x 27.99, 121
    { 132, 29714, NoLogo, LineMetaDataContent::Subway, Color{0xffb81c} }, // 9 OSM: 13088859 WD: Q28972638 30.58, 104 x 30.7, 104.1
    { 6, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xe93cac} }, // 5 OSM: 13091428 WD: Q6553133 31.23, 120.4 x 31.37, 120.8
    { 5219, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // Т1 OSM: 13121369 59.94, 30.26 x 59.96, 30.35
    { 5223, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x5eb3e4} }, // TNH1 OSM: 13124236 WD: Q18651563 23, 113.2 x 23.04, 113.2
    { 5228, 29724, NoLogo, LineMetaDataContent::LongDistanceTrain, Color{0x005b23} }, // IR 35 OSM: 13131233 WD: Q115996431 46.85, 7.434 x 47.44, 9.562
    { 5234, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xd42d1b} }, // THP1 OSM: 13140107 23.18, 113.5 x 23.22, 113.5
    { 5239, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // Ouargla tram OSM: 13159622 WD: Q16680954 31.94, 5.265 x 31.96, 5.333
    { 16, 29739, NoLogo, LineMetaDataContent::Subway, Color{0xdb6d1c} }, // 2 OSM: 13176924 WD: Q5947229 22.48, 113.9 x 22.57, 114.2
    { 19, 29762, NoLogo, LineMetaDataContent::Subway, Color{0xdb6d1c} }, // 8 OSM: 13176927 WD: Q11174946 22.56, 114.2 x 22.59, 114.3
    { 1479, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xed1c24} }, // 44 OSM: 13199272 44.44, 26.02 x 44.47, 26.09
    { 204, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xb58bd7} }, // S6 OSM: 13200482 31.92, 118.9 x 32.06, 119.2
    { 65, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe50a80} }, // 10 OSM: 13217677 55.67, 52.28 x 55.77, 52.45
    { 132, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x362d86} }, // 9 OSM: 13217678 55.67, 52.28 x 55.77, 52.45
    { 54, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x182f72} }, // 11 OSM: 13217860 55.7, 52.34 x 55.74, 52.47
    { 42, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x808080} }, // 7 OSM: 13242817 49.17, 16.55 x 49.23, 16.63
    { 22, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0047ba} }, // 18 OSM: 13246294 22.7, 113.3 x 23.13, 113.6
    { 16, 29785, NoLogo, LineMetaDataContent::Subway, Color{0x00ae59} }, // 2 OSM: 13250192 WD: Q10921993 45.72, 126.5 x 45.87, 126.7
    { 5252, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0066cc} }, // TRS OSM: 13262889 WD: Q39081226 -24.98, -65.65 x -24.65, -65.04
    { 50, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xe4222b} }, // S2 OSM: 13282128 27.75, 120.6 x 28.08, 121
    { 5256, 29809, 3795, LineMetaDataContent::Subway, Color{0xa12830} }, // 1E OSM: 13298577 WD: Q1039452 39.85, 116.5 x 39.91, 116.7
    { 16, 29834, NoLogo, LineMetaDataContent::Tramway, Color{0x009cdd} }, // 2 OSM: 13305615 WD: Q13390010 53.38, 14.55 x 53.43, 14.64
    { 5259, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // TAD OSM: 13308590 WD: Q18286525 -27.78, -64.27 x -27.73, -64.24
    { 5263, 29854, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7a745a} }, // F1 OSM: 13313680 WD: Q503503 41.03, 28.99 x 41.04, 28.99
    { 5266, 29882, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7a745a} }, // F2 OSM: 13313681 WD: Q387264 41.02, 28.97 x 41.03, 28.97
    { 9, 29910, NoLogo, LineMetaDataContent::Subway, Color{0x00a0e9} }, // 4 OSM: 13317505 WD: Q15938386 34.68, 113.6 x 34.83, 113.7
    { 59, 29929, NoLogo, LineMetaDataContent::Subway, Color{0xf39939} }, // 3 OSM: 13317992 WD: Q15950459 34.72, 113.6 x 34.84, 113.8
    { 5269, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 7а OSM: 13334566 59.88, 30.39 x 59.93, 30.5
    { 389, 29948, 21749, LineMetaDataContent::Subway, Color{0xff7400} }, // L1 OSM: 13335174 WD: Q6515333 10.48, -66.96 x 10.52, -66.8
    { 5273, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0066cc} }, // TPC OSM: 13341386 -31.77, -60.53 x -31.73, -60.29
    { 385, 29969, 21749, LineMetaDataContent::Subway, Color{0xfff000} }, // L4 OSM: 13350037 WD: Q21659772 10.43, -67.01 x 10.5, -66.84
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffcc00} }, // 2 OSM: 13395428 51.29, 12.28 x 51.34, 12.44
    { 132, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffcc00} }, // 9 OSM: 13397093 51.3, 12.37 x 51.38, 12.43
    { 5277, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 1N OSM: 13408107 47.05, 21.91 x 47.08, 21.94
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 8 OSM: 13408524 47.05, 21.9 x 47.08, 21.93
    { 254, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x9462b1} }, // 23 OSM: 13443923 47.07, 15.44 x 47.07, 15.46
    { 3448, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffff00} }, // Yellow Line OSM: 13475083 25.31, 51.42 x 25.32, 51.45
    { 58, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 13 OSM: 13489151 52.1, 11.59 x 52.11, 11.65
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xffda01} }, // 2 OSM: 13502832 WD: Q6850047 28.56, 115.8 x 28.7, 116
    { 59, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0079c3} }, // 3 OSM: 13507037 WD: Q10908095 28.51, 115.9 x 28.7, 116
    { 42, 29990, NoLogo, LineMetaDataContent::Subway, Color{0x88129e} }, // 7 OSM: 13528567 WD: Q11102450 30.2, 120.2 x 30.33, 120.5
    { 65, 30000, NoLogo, LineMetaDataContent::Subway, Color{0xdaa520} }, // 10 OSM: 13535688 WD: Q18653896 30.27, 120.1 x 30.38, 120.1
    { 9, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff850d} }, // 4 OSM: 13536846 WD: Q43283453 31.8, 117.1 x 31.95, 117.3
    { 59, 30011, NoLogo, LineMetaDataContent::Subway, Color{0xffd700} }, // 3 OSM: 13538221 WD: Q11102442 30.21, 120 x 30.39, 120.3
    { 55, 30031, 16926, LineMetaDataContent::Subway, Color{0x009088} }, // 1 OSM: 13538911 WD: Q626996 35.11, 126.8 x 35.16, 126.9
    { 9, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x800080} }, // 4 OSM: 13540934 31.47, 120.3 x 31.63, 120.3
    { 6, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x3b62a9} }, // 5 OSM: 13557463 WD: Q26262004 22.75, 108.3 x 22.87, 108.4
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009cdd} }, // 3 OSM: 13562401 53.44, 14.49 x 53.46, 14.55
    { 5280, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x50af47} }, // S 47 OSM: 13562799 51.48, 11.96 x 51.52, 11.99
    { 982, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // S12 OSM: 13566082 48.87, 8.347 x 49.02, 8.518
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x6fba2c} }, // 2 OSM: 13592842 WD: Q48899497 34.6, 112.4 x 34.71, 112.5
    { 5266, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xc10230} }, // F2 OSM: 13604445 WD: Q10886732 22.97, 113 x 23.01, 113.3
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 3 OSM: 13606198 WD: Q785655 41.87, 12.47 x 41.92, 12.52
    { 55, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xffa500} }, // 1 OSM: 13615315 WD: Q110419397 26.48, 80.25 x 26.51, 80.32
    { 249, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x00ced1} }, // 20 OSM: 13620411 WD: Q27940747 22.65, 113.8 x 22.72, 113.8
    { 54, 30056, 3795, LineMetaDataContent::Subway, Color{0xed796a} }, // 11 OSM: 13623628 WD: Q6553057 39.9, 116.1 x 39.93, 116.2
    { 179, 30077, 3795, LineMetaDataContent::Subway, Color{0x00a9a9} }, // 17 OSM: 13625147 WD: Q24834015 39.79, 116.5 x 39.86, 116.6
    { 147, 30098, 3795, LineMetaDataContent::Subway, Color{0xd6aac1} }, // 19 OSM: 13625329 WD: Q6553202 39.81, 116.3 x 39.98, 116.4
    { 6, 30119, NoLogo, LineMetaDataContent::Subway, Color{0x1d2088} }, // 5 OSM: 13626146 WD: Q10946024 29.81, 121.5 x 29.92, 121.6
    { 58, 30140, NoLogo, LineMetaDataContent::Subway, Color{0xffe400} }, // 13 OSM: 13633615 WD: Q10938159 39.15, 121.7 x 39.43, 121.9
    { 5285, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x664827} }, // TER OSM: 13645078 WD: Q66819158 14.68, -17.44 x 14.77, -17.2
    { 5289, 30161, NoLogo, LineMetaDataContent::LocalTrain, Color{} }, // RE 3 OSM: 13646696 WD: Q93290679 48.14, 11.48 x 48.78, 13.45
    { 6, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xa43034} }, // 5 OSM: 13647962 WD: Q11124520 30.45, 114.3 x 30.65, 114.4
    { 26, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xc24c6d} }, // 16 OSM: 13648363 30.27, 114 x 30.51, 114.2
    { 565, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xee0000} }, // E7 OSM: 13649968 48.1, 11.58 x 48.14, 11.61
    { 9, NoLogo, 24654, LineMetaDataContent::Subway, Color{0x1c7736} }, // 4 OSM: 13652091 WD: Q10940016 39.1, 117.2 x 39.14, 117.4
    { 100, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xee0000} }, // 37 OSM: 13664761 48.13, 11.6 x 48.18, 11.64
    { 9, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x00a560} }, // 4 OSM: 13681035 WD: Q15907959 28.6, 115.7 x 28.72, 116
    { 1045, 30177, 2154, LineMetaDataContent::RapidTransit, Color{0xe6007e} }, // S31 OSM: 13708521 WD: Q116125183 47.1, 15.62 x 47.22, 15.71
    { 19, NoLogo, 24654, LineMetaDataContent::Subway, Color{0x602e7c} }, // 8 OSM: 13711701 WD: Q10940012 38.98, 117.3 x 39.04, 117.4
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xca9822} }, // 6 OSM: 13743101 50.89, 10.56 x 50.9, 10.58
    { 524, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xee1d23} }, // A OSM: 13746337 WD: Q2204240 48.52, 7.693 x 48.6, 7.754
    { 196, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009ee0} }, // B OSM: 13746399 WD: Q2799227 48.55, 7.689 x 48.63, 7.769
    { 1211, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0xb4532f} }, // S20 OSM: 13763963 WD: Q106455085 47.33, 9.359 x 47.43, 9.462
    { 3943, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xc6912f} }, // S23 OSM: 13763964 47.29, 9.252 x 47.41, 9.437
    { 3528, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0xb55b59} }, // S26 OSM: 13763966 WD: Q819377 47.45, 9.59 x 47.47, 9.601
    { 230, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x66a4d9} }, // S25 OSM: 13763967 WD: Q337800 47.45, 9.493 x 47.48, 9.541
    { 5294, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x9c2727} }, // GAWC OSM: 13903112 WD: Q5528455 -34.92, 138.5 x -34.59, 138.7
    { 5299, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x094b8d} }, // GWY OSM: 13903708 WD: Q5568092 -37.88, 145 x -37.81, 145.2
    { 5303, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x00ffff} }, // Aqua OSM: 13916711 WD: Q59155699 18.51, 73.8 x 18.51, 73.84
    { 1565, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x800080} }, // Purple OSM: 13917129 WD: Q59155676 18.59, 73.8 x 18.63, 73.83
    { 211, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xcc5923} }, // T1 OSM: 13962101 30.4, 114.1 x 30.5, 114.2
    { 59, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0000ff} }, // 3 OSM: 13986696 WD: Q54366530 17.39, 78.38 x 17.45, 78.56
    { 1189, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xcd5228} }, // 22 OSM: 13988001 22.94, 113.3 x 23.02, 113.4
    { 16, 17331, NoLogo, LineMetaDataContent::Subway, Color{0xffff00} }, // 2 OSM: 13989917 WD: Q28419528 19.13, 72.83 x 19.26, 72.87
    { 42, 17331, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // 7 OSM: 13989918 WD: Q28419537 19.11, 72.85 x 19.25, 72.87
    { 44, 30196, 2154, LineMetaDataContent::RapidTransit, Color{0xec008c} }, // S5 OSM: 13995159 WD: Q67882950 48.27, 14.02 x 48.3, 14.29
    { 166, 30207, 2154, LineMetaDataContent::RapidTransit, Color{0x3f318f} }, // S3 OSM: 13995160 WD: Q67882855 48.26, 14.29 x 48.36, 14.52
    { 50, 30218, 2154, LineMetaDataContent::RapidTransit, Color{0x00aaad} }, // S2 OSM: 13995161 WD: Q67882763 48.16, 14.02 x 48.29, 14.29
    { 61, 30229, 2154, LineMetaDataContent::RapidTransit, Color{0xf58220} }, // S1 OSM: 13995162 WD: Q67882646 48.02, 14.29 x 48.3, 14.52
    { 218, 30240, 2154, LineMetaDataContent::RapidTransit, Color{0x96bc33} }, // S4 OSM: 13995163 WD: Q67882906 47.91, 14.1 x 48.29, 14.29
    { 132, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x862041} }, // 9 OSM: 14004564 WD: Q15917000 29.53, 106.4 x 29.76, 106.6
    { 5308, 13293, 9093, LineMetaDataContent::RapidTransit, Color{0x159dd9} }, // R40 OSM: 14008626 WD: Q96483953 48.23, 16.21 x 48.35, 16.37
    { 5312, 30251, NoLogo, LineMetaDataContent::LongDistanceTrain, Color{0x1eb2b3} }, // IR 66 OSM: 14049006 WD: Q116053240 46.93, 6.811 x 47.1, 7.439
    { 9, 30266, 7985, LineMetaDataContent::Subway, Color{0x9933ff} }, // 4 OSM: 14074756 WD: Q55663681 41.22, 69.26 x 41.3, 69.37
    { 39, NoLogo, 3420, LineMetaDataContent::RapidTransit, Color{0x357219} }, // T OSM: 14079401 WD: Q118874961 60.17, 24.78 x 60.74, 25.11
    { 6, 30292, NoLogo, LineMetaDataContent::Subway, Color{0x893b67} }, // 5 OSM: 14085418 WD: Q25305553 25.99, 119.2 x 26.11, 119.3
    { 3179, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00a49f} }, // B1 OSM: 14125993 WD: Q7521893 39.91, 32.58 x 39.97, 32.97
    { 5318, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x094b8d} }, // LIL OSM: 14142941 WD: Q6548623 -37.83, 144.9 x -37.76, 145.3
    { 65, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xb3cb6d} }, // 10 OSM: 14166437 39.45, -0.378 x 39.46, -0.3348
    { 1238, NoLogo, 3043, LineMetaDataContent::Tramway, Color{0x172983} }, // L5 OSM: 14193223 WD: Q9025966 38.34, -0.479 x 38.38, -0.4118
    { 5322, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffa500} }, // 7AB OSM: 14194208 51.72, 19.41 x 51.83, 19.55
    { 16, 30311, NoLogo, LineMetaDataContent::Tramway, Color{0x229922} }, // 2 OSM: 14211347 WD: Q1854674 51.17, 4.35 x 51.26, 4.464
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // 2 OSM: 14215022 WD: Q97325177 37.71, 112.6 x 37.92, 112.6
    { 5326, 30333, NoLogo, LineMetaDataContent::LocalTrain, Color{} }, // RB 73 OSM: 14228504 WD: Q113458371 47.57, 10.32 x 47.71, 10.58
    { 5332, 30350, 5211, LineMetaDataContent::Tramway, Color{0x827a04} }, // T10 OSM: 14232362 WD: Q3537026 48.76, 2.248 x 48.79, 2.304
    { 5336, 30384, 3199, LineMetaDataContent::Tramway, Color{0x8a5f20} }, // T13 OSM: 14263358 WD: Q3515106 48.8, 2.043 x 48.97, 2.095
    { 27, 30418, NoLogo, LineMetaDataContent::Subway, Color{0x005bac} }, // 6 OSM: 14303415 WD: Q46096730 28.17, 112.8 x 28.22, 113.2
    { 5340, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffcd28} }, // Z40 OSM: 14319938 WD: Q112225436 46.37, 18.15 x 47.5, 19.04
    { 6, 30437, NoLogo, LineMetaDataContent::Tramway, Color{0x95254c} }, // 5 OSM: 14329573 WD: Q16655754 43.59, 3.81 x 43.66, 3.877
    { 44, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf3c737} }, // S5 OSM: 14372453 46.53, 13.83 x 46.62, 14.04
    { 272, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x3bbfef} }, // Blue OSM: 14381218 30.2, -97.75 x 30.42, -97.66
    { 139, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00a8e7} }, // 14 OSM: 14402834 51.33, 12.32 x 51.34, 12.38
    { 5344, 30447, NoLogo, LineMetaDataContent::LongDistanceTrain, Color{0xed1c24} }, // RE80 OSM: 14432436 WD: Q107263607 45.49, 8.801 x 46.18, 9.274
    { 5349, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x187dcd} }, // JT OSM: 14434654 WD: Q112169762 29.31, 106.3 x 29.41, 106.4
    { 22, 30461, 8193, LineMetaDataContent::Subway, Color{0x00a88f} }, // 18 OSM: 14455702 WD: Q3240157 48.71, 2.07 x 48.79, 2.362
    { 1807, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xce8e00} }, // Hempstead OSM: 14460239 WD: Q5712708 40.68, -73.97 x 40.73, -73.62
    { 5352, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xc33032} }, // Jinyi OSM: 14489040 WD: Q43304703 29.08, 119.6 x 29.33, 120.1
    { 27, 30497, NoLogo, LineMetaDataContent::Subway, Color{0x005eb8} }, // 6 OSM: 14509136 WD: Q24886992 25.9, 119.4 x 26.02, 119.6
    { 2125, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x228b22} }, // V OSM: 14576928 -17.41, -66.28 x -17.4, -66.15
    { 459, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // R OSM: 14576929 -17.45, -66.15 x -17.41, -66.13
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffcc99} }, // 1 OSM: 14594829 WD: Q16924991 22.67, 114 x 22.72, 114.1
    { 5358, 30516, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffce00} }, // S90 OSM: 14604626 WD: Q108075807 45.87, 8.92 x 46.17, 9.005
    { 1211, 30529, NoLogo, LineMetaDataContent::RapidTransit, Color{0x007dc6} }, // S20 OSM: 14604783 WD: Q3832731 46.15, 8.801 x 46.22, 9.042
    { 966, 30542, NoLogo, LineMetaDataContent::RapidTransit, Color{0xed1c24} }, // S10 OSM: 14604788 WD: Q3832722 45.81, 8.933 x 46.35, 9.074
    { 2066, 30555, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00a651} }, // S30 OSM: 14604990 WD: Q3832740 45.66, 8.624 x 46.16, 8.942
    { 162, 30568, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe35a13} }, // S60 OSM: 14605103 WD: Q112899163 45.97, 8.86 x 46.01, 8.948
    { 2095, 30581, NoLogo, LineMetaDataContent::RapidTransit, Color{0x6cc27f} }, // S40 OSM: 14605384 WD: Q47219003 45.81, 8.833 x 45.87, 9.074
    { 182, 30594, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7d4808} }, // S50 OSM: 14605385 WD: Q47219058 45.6, 8.704 x 46.35, 9.042
    { 55, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // 1 OSM: 14611374 WD: Q48868979 38.64, -9.167 x 38.69, -9.147
    { 59, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // 3 OSM: 14611403 WD: Q48868985 38.66, -9.208 x 38.69, -9.147
    { 16, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffff00} }, // 2 OSM: 14611445 WD: Q48868981 38.64, -9.18 x 38.67, -9.151
    { 147, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x05c3de} }, // 19 OSM: 14613133 WD: Q48903466 30.22, 120 x 30.3, 120.5
    { 27, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x920783} }, // 6 OSM: 14642983 WD: Q15935783 34.67, 113.4 x 34.74, 113.5
    { 132, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 9 OSM: 14644778 47.2, 38.88 x 47.22, 38.94
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // 2 OSM: 14657624 WD: Q65081142 22.98, 72.53 x 23.1, 72.6
    { 447, 30607, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe96bb0} }, // K OSM: 14669757 WD: Q5184164 33.96, -118.4 x 34.02, -118.3
    { 5362, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x005a9c} }, // Fremantle OSM: 14677734 WD: Q5501509 -32.05, 115.7 x -31.94, 115.9
    { 5372, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa90056} }, // Midland OSM: 14677911 WD: Q6842474 -31.95, 115.9 x -31.89, 116
    { 5380, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe06f1d} }, // Mandurah OSM: 14678704 WD: Q1895265 -32.53, 115.7 x -31.95, 115.9
    { 5389, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfebe10} }, // Thornlie OSM: 14683170 WD: Q1924165 -32.05, 115.9 x -31.95, 116
    { 5398, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfebe10} }, // Armadale OSM: 14683171 WD: Q1924165 -32.15, 115.9 x -31.95, 116
    { 5407, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa6aa12} }, // Joondalup OSM: 14689510 WD: Q6276051 -31.96, 115.7 x -31.64, 115.9
    { 2905, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe3000b} }, // 4A OSM: 14712448 49.48, 8.364 x 49.53, 8.509
    { 5417, NoLogo, 27853, LineMetaDataContent::RapidTransit, Color{0xc2e35c} }, // Arrow OSM: 14728552 WD: Q7413424 34.06, -117.3 x 34.1, -117.2
    { 16, NoLogo, 27213, LineMetaDataContent::RapidTransit, Color{0x008000} }, // 2 OSM: 14729478 WD: Q20977784 5.357, 100.3 x 6.664, 100.5
    { 5423, 30632, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7a745a} }, // F4 OSM: 14738978 WD: Q31193345 41.08, 29.05 x 41.09, 29.05
    { 55, NoLogo, 27213, LineMetaDataContent::RapidTransit, Color{0x1964b7} }, // 1 OSM: 14744287 WD: Q20977784 4.776, 100.4 x 5.394, 100.9
    { 211, 30660, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7cfc00} }, // T1 OSM: 14758569 WD: Q5985905 36.41, -6.288 x 36.53, -6.134
    { 139, 30678, NoLogo, LineMetaDataContent::Subway, Color{0xf2c75c} }, // 14 OSM: 14764338 WD: Q21245993 22.54, 114.1 x 22.76, 114.4
    { 5426, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xecdb3b} }, // GR01 OSM: 14785799 37.06, 37.33 x 37.17, 37.45
    { 55, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 14870574 WD: Q47015943 31.91, 120.8 x 32.11, 121
    { 18, 30702, 17842, LineMetaDataContent::Subway, Color{0x23387f} }, // M8 OSM: 14900218 WD: Q5996245 40.95, 29.09 x 41.03, 29.16
    { 65, NoLogo, 24654, LineMetaDataContent::Subway, Color{0xb9cf09} }, // 10 OSM: 14903908 WD: Q10940015 39.05, 117.2 x 39.15, 117.3
    { 16, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xbf4525} }, // 2 OSM: 14933919 WD: Q114608664 60.35, 5.289 x 60.39, 5.362
    { 55, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xed4800} }, // 1 OSM: 14934588 WD: Q28412165 27.47, 118 x 27.63, 118.1
    { 8, 30730, 6703, LineMetaDataContent::Subway, Color{0x2f4481} }, // M4 OSM: 14937470 WD: Q943476 45.46, 9.218 x 45.47, 9.278
    { 389, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x30556e} }, // L1 OSM: 14942883 56.15, 10.2 x 56.41, 10.88
    { 15, 30750, NoLogo, LineMetaDataContent::Subway, Color{0xa192b2} }, // 12 OSM: 14944729 WD: Q11559867 22.47, 113.8 x 22.73, 113.9
    { 5431, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x428d89} }, // 6B OSM: 14953717 WD: Q114025973 22.77, 113.9 x 22.81, 114
    { 393, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x30556e} }, // L2 OSM: 14973319 55.97, 10.12 x 56.23, 10.23
    { 3817, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf7941d} }, // S44 OSM: 14978073 47.56, 9.103 x 47.66, 9.192
    { 249, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xa0216e} }, // 20 OSM: 14987053 47.39, 8.353 x 47.43, 8.489
    { 1851, NoLogo, 13232, LineMetaDataContent::RapidTransit, Color{0xed6fa7} }, // S19 OSM: 14987372 WD: Q110973246 50.4, 4.335 x 50.9, 4.488
    { 2944, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xffd520} }, // Broadway Subway OSM: 14991403 49.26, -123.2 x 49.27, -123.1
    { 5434, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00aff0} }, // S74 OSM: 14995079 WD: Q115171353 47.72, 18.11 x 47.78, 18.74
    { 5438, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffff00} }, // S 10 OSM: 14995860 51.32, 12.27 x 51.37, 12.39
    { 5443, 30774, NoLogo, LineMetaDataContent::LocalTrain, Color{0x816da6} }, // RE8 OSM: 15001253 WD: Q112992594 51.46, 11.36 x 53.9, 13.71
    { 5447, 30793, 226, LineMetaDataContent::RapidTransit, Color{0x202776} }, // S53 OSM: 15014017 WD: Q115285815 51.03, 3.711 x 51.11, 3.986
    { 211, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfdec4a} }, // T1 OSM: 15022247 45.69, 9.676 x 45.76, 9.798
    { 9, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x007a33} }, // 4 OSM: 15051229 WD: Q15947246 36.06, 120.3 x 36.14, 120.6
    { 3796, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x002f87} }, // F3 OSM: 15054273 WD: Q10886732 22.82, 113.1 x 23.02, 113.3
    { 61, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0061ae} }, // S1 OSM: 15058106 WD: Q48899113 28.32, 121.3 x 28.66, 121.4
    { 5451, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // IR85 OSM: 15058598 47.49, 19.08 x 47.78, 19.95
    { 26, 30814, NoLogo, LineMetaDataContent::Subway, Color{0x1e22aa} }, // 16 OSM: 15059918 WD: Q11215578 22.69, 114.2 x 22.74, 114.4
    { 5456, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x6699cc} }, // 215 OSM: 15059991 WD: Q105045768 46.95, 6.839 x 46.99, 6.928
    { 27, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x006e34} }, // 6 OSM: 15060937 WD: Q97257710 23.73, 90.36 x 23.87, 90.42
    { 5460, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x83898f} }, // 58d OSM: 15062383 -37.84, 145 x -37.81, 145
    { 59, 23627, 23650, LineMetaDataContent::Subway, Color{0x800080} }, // 3 OSM: 15068969 WD: Q27502952 22.45, 88.3 x 22.51, 88.32
    { 5464, 30838, 17842, LineMetaDataContent::Subway, Color{0xa1609b} }, // M11 OSM: 15083966 WD: Q31193348 41.08, 28.71 x 41.26, 28.98
    { 5468, 30867, 17842, LineMetaDataContent::Subway, Color{} }, // M14 OSM: 15099622 WD: Q31193350 41.02, 29.05 x 41.04, 29.1
    { 2310, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // Sul OSM: 15268630 -6.071, -35.26 x -5.78, -35.21
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe77817} }, // 5 OSM: 15268961 47.14, 27.54 x 47.17, 27.64
    { 5472, NoLogo, 3043, LineMetaDataContent::Tramway, Color{0x706e6d} }, // L-9 OSM: 15320668 WD: Q11690013 38.55, -0.1354 x 38.84, 0.1131
    { 42, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x96d700} }, // 7 OSM: 15336346 32.11, 118.8 x 32.13, 118.9
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffa500} }, // 3 OSM: 15351431 41.37, 36.19 x 41.38, 36.23
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 2 OSM: 15354644 41.22, 36.34 x 41.29, 36.46
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 1 OSM: 15378703 41.29, 36.23 x 41.37, 36.34
    { 1392, NoLogo, 28125, LineMetaDataContent::RapidTransit, Color{0xefd51f} }, // RE3 OSM: 15413862 WD: Q115749580 46.6, 6.906 x 46.85, 7.191
    { 1378, NoLogo, 28125, LineMetaDataContent::RapidTransit, Color{0xc31622} }, // RE2 OSM: 15413942 WD: Q115749575 46.6, 6.906 x 46.95, 7.44
    { 447, 30896, NoLogo, LineMetaDataContent::RapidTransit, Color{0xc3b091} }, // K OSM: 15443527 WD: Q10914168 24.94, 121.5 x 24.99, 121.5
    { 1767, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0d0dff} }, // T3 OSM: 15463464 37.03, 37.31 x 37.09, 37.35
    { 4751, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x3a6198} }, // S22 OSM: 15463831 WD: Q115743565 47.29, 7.688 x 47.31, 7.71
    { 211, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff2b0a} }, // T1 OSM: 15470242 37.02, 37.32 x 37.07, 37.38
    { 537, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x08ff08} }, // T2 OSM: 15471517 37.06, 37.33 x 37.09, 37.38
    { 16, 30924, NoLogo, LineMetaDataContent::Subway, Color{0x229954} }, // 2 OSM: 15510494 WD: Q97218492 29.57, 52.49 x 29.63, 52.57
    { 5476, 30948, 17842, LineMetaDataContent::Subway, Color{0xc8cb2d} }, // M12 OSM: 15520693 WD: Q31193310 40.97, 29.06 x 41.04, 29.12
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe2e200} }, // 2 OSM: 15520695 47.52, 21.61 x 47.56, 21.63
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffb752} }, // 1 OSM: 15540826 WD: Q116860182 35.92, 0.06022 x 35.98, 0.1102
    { 16, 30977, 31002, LineMetaDataContent::Subway, Color{0x58e558} }, // 2 OSM: 15545706 WD: Q116978502 35.7, 50.88 x 35.86, 51.01
    { 11, 31052, 17842, LineMetaDataContent::Subway, Color{0x683064} }, // M5 OSM: 15547373 WD: Q1229371 40.96, 29.01 x 41.03, 29.28
    { 57, 31080, 17842, LineMetaDataContent::Subway, Color{0x0ca950} }, // M13 OSM: 15547419 WD: Q48742876 41, 29.2 x 41.03, 29.25
    { 1489, 31109, 17842, LineMetaDataContent::Subway, Color{0xf19ebf} }, // M7 OSM: 15547431 WD: Q16949749 41.03, 28.67 x 41.09, 29.01
    { 1198, 31137, 17842, LineMetaDataContent::Subway, Color{0x00a8e1} }, // M3 OSM: 15547443 WD: Q1880963 40.97, 28.77 x 41.12, 28.88
    { 5480, 31165, 17842, LineMetaDataContent::Subway, Color{0xffd400} }, // M9 OSM: 15547473 WD: Q25209252 40.98, 28.77 x 41.08, 28.86
    { 5483, 31193, 17842, LineMetaDataContent::Subway, Color{} }, // M20 OSM: 15547627 WD: Q109779737 40.98, 28.62 x 41.03, 28.88
    { 297, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 30 OSM: 15554589 59.92, 30.38 x 59.93, 30.44
    { 2558, 31222, 28629, LineMetaDataContent::Tramway, Color{0x037bdf} }, // T3a OSM: 15568057 WD: Q117008328 38.72, 35.4 x 38.79, 35.63
    { 1767, 31222, 28629, LineMetaDataContent::Tramway, Color{0x037bdf} }, // T3 OSM: 15568179 WD: Q117008328 38.72, 35.4 x 38.79, 35.63
    { 1787, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xdce3e9} }, // T4 OSM: 15571056 38.7, 35.43 x 38.78, 35.57
    { 524, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffbf00} }, // A OSM: 15603175 WD: Q4647009 32.98, -97.13 x 33.21, -96.93
    { 5487, 31263, NoLogo, LineMetaDataContent::LocalTrain, Color{0x5d7688} }, // RB32 OSM: 15608623 WD: Q112802971 52.3, 13.27 x 52.37, 13.51
    { 6, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xe60012} }, // 5 OSM: 15611913 WD: Q28411250 38.88, 121.6 x 39.05, 121.7
    { 5492, 31283, NoLogo, LineMetaDataContent::LocalTrain, Color{0x501689} }, // RB21 OSM: 15615526 WD: Q105947745 52.39, 12.94 x 52.55, 13.39
    { 5497, 31303, NoLogo, LineMetaDataContent::LocalTrain, Color{0xff0000} }, // RB37 OSM: 15615531 WD: Q112803049 52.24, 12.96 x 52.42, 13.19
    { 254, NoLogo, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 23 OSM: 15624869 WD: Q100741440 47.47, 19.05 x 47.51, 19.09
    { 524, 31323, 31343, LineMetaDataContent::Subway, Color{0x00a562} }, // A OSM: 15640862 WD: Q1292805 50.07, 14.34 x 50.1, 14.52
    { 196, 31363, 31343, LineMetaDataContent::Subway, Color{0xf8b322} }, // B OSM: 15640873 WD: Q1460442 50.04, 14.29 x 50.11, 14.58
    { 311, 31383, 31343, LineMetaDataContent::Subway, Color{0xcf003d} }, // C OSM: 15640889 WD: Q168571 50.03, 14.43 x 50.13, 14.53
    { 363, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00ad4f} }, // E OSM: 15654116 WD: Q118612325 36.78, 10.1 x 36.79, 10.18
    { 1198, 31403, 31425, LineMetaDataContent::Subway, Color{0x35ab52} }, // M3 OSM: 15655643 WD: Q2420584 50.39, 30.43 x 50.48, 30.7
    { 265, 31445, 31425, LineMetaDataContent::Subway, Color{0xdd2a26} }, // M1 OSM: 15655644 WD: Q2334153 50.44, 30.35 x 50.47, 30.65
    { 346, 31467, 31425, LineMetaDataContent::Subway, Color{0x2782c5} }, // M2 OSM: 15655645 WD: Q2204296 50.37, 30.45 x 50.52, 30.53
    { 272, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0000ff} }, // Blue OSM: 15668739 6.446, 3.312 x 6.479, 3.395
    { 147, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffa500} }, // 19 OSM: 15670312 51.72, 19.43 x 51.83, 19.49
    { 5263, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x00adbb} }, // F1 OSM: 15700253 25.88, 119.3 x 26.11, 119.7
    { 55, NoLogo, 31489, LineMetaDataContent::Subway, Color{0xe31d1b} }, // 1 OSM: 15797036 WD: Q18419905 -0.2955, -78.56 x -0.1536, -78.48
    { 1028, 31500, 8879, LineMetaDataContent::Tramway, Color{0x91619d} }, // D OSM: 15797847 WD: Q16655779 44.82, -0.6675 x 44.89, -0.55
    { 5502, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00aff0} }, // S225 OSM: 15809425 46.91, 19.7 x 47.18, 20.18
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 6 OSM: 15840812 55.81, 37.41 x 55.86, 37.51
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 4 OSM: 15840813 55.75, 37.66 x 55.82, 37.73
    { 132, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 9 OSM: 15840817 55.78, 37.58 x 55.79, 37.61
    { 249, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x595fa7} }, // 20 OSM: 15858526 52.4, 16.91 x 52.41, 16.96
    { 50, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0xffc0cb} }, // S2 OSM: 15865690 WD: Q115756448 46.7, 9.386 x 46.85, 9.531
    { 61, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x62a0ea} }, // S1 OSM: 15865708 WD: Q115756382 46.8, 9.386 x 46.98, 9.689
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // 2 OSM: 15924888 WD: Q65050458 36.03, 103.8 x 36.07, 103.9
    { 307, NoLogo, 3420, LineMetaDataContent::RapidTransit, Color{0x035eb9} }, // O OSM: 15925639 WD: Q118924451 60.46, 25.66 x 60.98, 26.96
    { 3152, NoLogo, 3420, LineMetaDataContent::RapidTransit, Color{0xe0071c} }, // Z OSM: 15925779 WD: Q118874964 60.17, 24.93 x 60.98, 26.71
    { 1028, NoLogo, 3420, LineMetaDataContent::RapidTransit, Color{0x035eb9} }, // D OSM: 15932097 WD: Q118874955 61, 24.48 x 61, 24.48
    { 1011, NoLogo, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 1A OSM: 15953835 WD: Q15982260 47.48, 19.03 x 47.55, 19.11
    { 1011, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfdc434} }, // 1A OSM: 15961882 WD: Q56388740 46.24, 20.12 x 46.27, 20.15
    { 5507, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce0000} }, // PR OSM: 16019086 53.24, 19.57 x 53.58, 20.17
};

static constexpr const auto line_data_count = sizeof(line_data) / sizeof(LineMetaDataContent);

static inline constexpr uint16_t Bucket(uint16_t index) { return line_data_count + index; }

static const int16_t line_data_bucketTable[] = {
    1364, 1346, 1361, 1362, 1363, -1,
    359, 361, 1155, 402, 401, 374, 373, -1,
    1210, 2650, 2649, -1,
    1127, 1718, 2496, 2742, 2743, 2744, -1,
    1241, 2958, 2763, 1173, 1236, 1243, 1254, 1253, -1,
    869, 2064, 246, -1,
    1563, 1568, -1,
    2480, 1436, 2482, 2483, 2484, -1,
    923, 924, 919, 327, 920, 925, 926, 918, 921, 922, -1,
    408, 407, 1221, -1,
    399, 2313, 350, -1,
    1072, 192, -1,
    385, 389, -1,
    1789, 1277, 1791, 796, -1,
    224, 226, -1,
    762, 748, 753, 752, 750, 758, 759, 749, 756, 763, 757, 747, 755, 754, 761, 760, 751, -1,
    2647, 1211, 2652, 2651, 1360, 1340, -1,
    1413, 1412, -1,
    1605, 1616, 1415, -1,
    492, 1557, 1474, 250, 1555, 1556, -1,
    1699, 1700, 1728, 1734, 2470, 2471, 2465, -1,
    627, 631, 632, -1,
    2898, 2913, -1,
    2846, 2710, -1,
    1289, 1365, 1469, 698, 1129, -1,
    1365, 1469, -1,
    1480, 994, 734, 979, 2998, 1739, 737, 705, 704, 1485, 328, 2952, 735, -1,
    823, 824, 1385, 1264, 1261, 1260, -1,
    1934, 1247, 1250, 1170, 1158, 1242, 1249, 1172, 1255, -1,
    247, 2070, -1,
    3021, 3022, -1,
    2441, 2560, -1,
    2917, 2784, 2902, -1,
    2779, 2456, 2780, -1,
    2626, 1807, 1591, 1808, 1845, 1810, 2081, -1,
    2366, 1941, 2410, 2547, 2712, 2182, 2365, 2658, 2557, 2700, -1,
    875, 2711, 2232, 874, -1,
    876, 875, 2711, 2232, 874, 2210, 868, -1,
    1585, 2335, 2334, 2481, -1,
    2995, 1401, 832, -1,
    2585, 2586, -1,
    927, 518, -1,
    210, 2377, 2378, 2376, 2375, 2379, 2380, 2518, -1,
    210, 2377, 2378, 2376, 2375, 2379, 2380, -1,
    2748, 404, 1884, 2448, 779, 1869, 2390, 2316, 405, 1870, -1,
    888, 882, 954, 886, 613, -1,
    1124, 2347, 2348, 1417, 1416, 2349, -1,
    391, 2473, 1138, -1,
    2598, 2597, -1,
    2621, 1333, 1777, 1324, 1334, 1336, 1311, 1312, 1309, 1310, 1337, 474, 1308, 658, -1,
    1489, 1046, -1,
    2418, 2408, 2409, -1,
    648, 191, 2696, 1558, 239, -1,
    1536, 1543, 1544, -1,
    744, 364, 745, 1121, 567, 776, -1,
    1710, 1721, 1722, 1711, 2878, 2974, 2973, 2544, 2542, 2197, 2541, -1,
    1314, 470, 81, 85, 670, 257, 674, 675, 1128, -1,
    1536, 1543, -1,
    1256, 1314, 470, 576, 370, 85, 2442, 672, 673, 674, 675, 1128, 676, 677, 678, 682, 711, 683, 684, -1,
    628, 629, 630, 633, -1,
    696, 2050, 1291, 2049, -1,
    2964, 2990, 2987, -1,
    2910, 2079, 745, 1121, -1,
    1919, 1699, 1701, 1710, 1702, 1700, 1721, 1722, 1728, 1711, 2790, 1719, 455, 1735, 2036, 1998, -1,
    1919, 2889, -1,
    1735, 451, 2026, 879, 880, 25, 1458, -1,
    535, 536, 659, 310, 999, -1,
    418, 2889, -1,
    2299, 207, 615, -1,
    2701, 2642, 2645, -1,
    1503, 1502, -1,
    418, 2713, 527, 2673, 2709, 986, 2118, -1,
    733, 988, -1,
    833, 1971, 3001, 3002, 1382, -1,
    204, 342, 984, 983, 1481, 1482, -1,
    1496, 928, 843, 733, 988, 732, 1738, -1,
    740, 742, 741, -1,
    820, 36, 1026, 738, 736, 1496, 14, -1,
    230, 231, -1,
    2527, 2241, 2537, 2571, 2251, -1,
    1238, 2764, 1248, 1252, 1251, 1240, 1174, 2893, 2765, 2176, -1,
    2223, 2222, -1,
    1715, 3006, 3005, -1,
    1561, 1567, 1598, 1566, -1,
    1764, 1755, -1,
    2358, 2007, 2357, 1975, 1974, 1913, 1915, 1914, -1,
    1612, 2243, -1,
    2926, 2924, -1,
    1446, 2421, 322, 2116, 2420, -1,
    2630, 2627, 2993, 2992, -1,
    2797, 517, 516, 783, 784, 2798, -1,
    1832, 1965, 2631, -1,
    1448, 2320, -1,
    2247, 2574, -1,
    2249, 2304, -1,
    1759, 1760, -1,
    2903, 3010, -1,
    2387, 2015, -1,
    295, 1767, -1,
    1179, 827, 2025, 384, 383, 302, 303, 390, 2601, -1,
    1648, 2153, 2189, 2616, 2740, 2368, 1928, -1,
    2486, 1989, 1856, 1435, -1,
    2502, 640, 637, 2505, 638, 2507, 2504, 639, 2506, 641, 2503, 636, -1,
    2486, 1989, -1,
    2332, 2336, 2337, 2338, 2339, 2340, 2341, -1,
    161, 262, 1286, 2022, -1,
    2293, 2292, -1,
    1860, 1867, 1858, 1859, 1861, 1862, 1864, 2397, -1,
    2497, 2896, -1,
    1398, 1400, 1399, -1,
    1132, 1131, -1,
    1587, 1586, 1584, -1,
    2515, 2516, 2513, 2512, 2511, -1,
    1840, 1842, -1,
    2516, 2512, 2511, -1,
    2259, 2261, 2263, 2269, 280, 275, 2291, 2290, 2572, 279, 2308, 2310, 2311, 2303, 2901, 2300, 2287, 235, 377, 526, 281, 1077, 1748, -1,
    2259, 2263, 2269, 279, 2310, 377, -1,
    951, 949, 2143, 2148, 2145, -1,
    932, 194, 193, -1,
    1546, 1547, 1148, -1,
    2589, 2590, 1704, -1,
    2589, 2590, -1,
    1386, 1040, 2203, 2208, -1,
    1790, 2123, 2620, 2120, 1742, 1744, 1752, 1749, 1753, 1747, -1,
    215, 2267, 1582, 2268, 1693, 1516, 1606, 1601, 1604, 2615, 1427, 1695, 1411, -1,
    1551, 1550, 1549, 970, 917, 969, 1553, 975, 976, 1552, 972, 1559, 1517, 722, 2891, 466, 1475, -1,
    1535, 2948, 1529, 1530, 1528, 1531, 1538, 1539, 1540, 1533, -1,
    1052, 1054, -1,
    644, 643, -1,
    2454, 1740, -1,
    2121, 1702, 1709, 1731, 1733, 1712, 2790, 2168, 2194, 2195, 2196, 2170, -1,
    1538, 1534, -1,
    1535, 1529, 1257, 1530, 1528, -1,
    1157, 1165, 1166, 1169, 1168, -1,
    681, 63, 1451, 64, 72, -1,
    679, 818, 1344, 819, 816, -1,
    625, 621, 622, 1107, 626, -1,
    1888, 2051, 1454, -1,
    2882, 1898, -1,
    2540, 2538, 2539, 838, 2074, 2103, 2344, 2101, 2075, 2076, 2077, 2078, 2102, -1,
    1731, 1733, 1712, 1732, 1729, 1720, 460, 2028, 2039, 2533, 2317, 2165, 2038, 2577, -1,
    2510, 2028, 987, 2038, 2946, 1030, -1,
    2078, 2079, -1,
    460, 2165, -1,
    19, 1370, 22, 16, 109, 1456, 1457, -1,
    1035, 2522, 2946, -1,
    82, 83, 84, 982, 89, 321, 37, 48, 30, 50, 2160, 38, 39, 40, 41, 42, 43, 44, 45, -1,
    770, 1061, 729, -1,
    997, 998, 1000, -1,
    2698, 615, -1,
    187, 186, 178, 2741, -1,
    2644, 2643, -1,
    270, 2045, 2044, 140, 1499, 272, 141, 602, 103, 1032, -1,
    186, 178, -1,
    2873, 2875, 2871, -1,
    697, 719, 717, 935, -1,
    1295, 491, 1292, 1293, 1212, 1294, 502, 496, 495, 137, -1,
    110, 93, 117, -1,
    98, 76, 78, 128, 80, 127, 892, 2951, 2013, -1,
    71, 28, 1437, 991, 2996, 309, 135, 136, 2171, 67, 1523, 2329, 143, 12, 15, 261, 125, 122, 121, 99, 120, 119, 118, -1,
    71, 309, 135, 136, 2171, 15, -1,
    2355, 97, 283, 294, 1083, 203, -1,
    2246, 2252, -1,
    1245, 1933, 472, 471, 1153, -1,
    1244, 3013, 1239, -1,
    1237, 2950, -1,
    1245, 472, 1153, -1,
    785, 781, 867, 786, 721, -1,
    1301, 1182, 2967, 1184, 1185, -1,
    1666, 1667, -1,
    2439, 2438, 2437, -1,
    1067, 1068, 1066, -1,
    1562, 1599, 2880, -1,
    532, 809, -1,
    2611, 2612, -1,
    2777, 2327, 2402, -1,
    2242, 1894, 1897, -1,
    2554, 2553, -1,
    1678, 1677, -1,
    2280, 2283, 2284, 2286, -1,
    419, 434, 1973, 395, 437, 706, 1521, 450, 417, 441, 440, 500, 438, 432, 965, 433, -1,
    701, 2879, -1,
    2521, 2191, -1,
    2035, 1963, 1959, 1960, 1966, 1991, 1962, -1,
    1761, 1964, 2260, 2831, -1,
    2006, 2681, 2001, 2005, 2678, 2463, -1,
    650, 2011, 2633, 2010, 839, 2876, 2009, -1,
    2801, 2234, 2836, 2956, 2238, 2789, -1,
    254, 252, 256, -1,
    1835, 2147, 2256, 2618, 2244, 2271, 256, -1,
    2848, 2248, 2240, -1,
    2001, 2678, 2463, -1,
    2318, 2774, -1,
    1781, 2424, 1782, 2318, 2769, 2774, -1,
    2029, 2460, 2766, -1,
    871, 2852, -1,
    2167, 1120, 1119, 307, -1,
    2826, 2558, 2828, 2778, -1,
    2785, 2804, -1,
    2024, 1811, 2425, 2843, -1,
    1880, 2462, -1,
    993, 992, 995, 1815, 2796, -1,
    1460, 1574, 1572, 1573, 2478, 2702, 1463, 2381, 236, 1465, 1569, 1467, 240, 1570, 1571, -1,
    297, 2841, 2805, 382, 1180, 1178, 2386, 381, 2594, 2747, -1,
    2057, 2054, -1,
    1883, 1822, -1,
    2084, 1836, 2345, -1,
    2084, 2092, -1,
    1881, 1800, 1799, -1,
    2084, 2073, -1,
    1996, 1997, -1,
    2565, 2563, -1,
    2230, 1943, -1,
    2033, 2426, 2178, 1271, -1,
    2802, 1878, -1,
    229, 200, 237, 0, 54, 1, 199, 2622, 2863, 2883, -1,
    2326, 2325, 2479, -1,
    1019, 2099, -1,
    2133, 2135, -1,
    1378, 1220, -1,
    2331, 2330, 2555, 2342, -1,
    1285, 2371, 2370, -1,
    2295, 2294, -1,
    2729, 2727, 2728, -1,
    815, 718, 821, 728, -1,
    1579, 1580, 1581, -1,
    1843, 1844, 1841, 1583, -1,
    2356, 1839, -1,
    2526, 2449, 1885, -1,
    2301, 400, 274, 2576, 2288, 398, 788, 277, 1871, 789, 278, 2276, -1,
    400, 398, 789, -1,
    1652, 1654, -1,
    195, 1589, -1,
    1044, 2322, 612, -1,
    1044, 883, 2322, -1,
    1852, 1853, 2815, -1,
    387, 2582, 2383, 2282, 388, 386, 1793, 1792, -1,
    1374, 1372, 1904, -1,
    2364, 2655, -1,
    1708, 1707, -1,
    1199, 1778, 1279, -1,
    446, 444, 445, 1306, -1,
    2653, 2654, 2648, -1,
    2500, 2498, 2499, 2894, -1,
    797, 798, 813, 3012, -1,
    603, 1093, -1,
    1600, 190, 1617, -1,
    1988, 216, -1,
    2900, 1478, -1,
    971, 974, -1,
    1717, 1716, 2755, 2756, -1,
    1493, 1021, 1519, 1775, 1905, 1491, 1593, 1850, 1062, 1505, 1524, 1908, 1594, 1097, 1525, 1526, 1532, 1534, -1,
    360, 528, -1,
    2451, 2452, -1,
    1225, 300, -1,
    1096, 1105, 929, 2474, 2193, 2543, 2202, 2201, 2198, 1089, -1,
    1096, 929, 2193, 2202, 184, -1,
    1732, 1729, 2394, 2306, 457, 2395, 2289, -1,
    1526, 1527, 1533, -1,
    2164, 2605, -1,
    2856, 2857, 1848, -1,
    579, 1258, -1,
    577, 578, 579, 580, 581, -1,
    1005, 1525, -1,
    1387, 1393, 1994, 2614, 1389, 1350, 1352, 1353, 1354, -1,
    1300, 2429, -1,
    1258, 1319, 1322, 1320, -1,
    371, 2432, 365, 366, 368, -1,
    313, 2939, -1,
    2184, 2185, 2065, 968, -1,
    607, 609, 510, 608, -1,
    609, 608, -1,
    2663, 2664, -1,
    2988, 2989, 1548, -1,
    2981, 2965, 1636, 2988, 2985, 2937, 1548, 2699, -1,
    1802, 1899, -1,
    2909, 2912, 2907, -1,
    2593, 2100, -1,
    458, 2307, 2535, 2536, 184, -1,
    2309, 2306, 2305, 2307, 2517, 457, 2395, 2289, -1,
    2031, 2534, 2535, -1,
    858, 1518, 857, 541, 861, 859, 860, 853, 855, 863, 856, 447, 1449, 2019, 461, 835, 2258, 2014, 451, 442, 448, 2020, 459, 1999, 463, -1,
    2908, 2910, 2907, -1,
    2533, 2031, -1,
    1035, 460, 451, 2031, 2027, 442, 2026, 264, -1,
    3019, 2549, -1,
    1035, 2567, 2858, 2551, 2519, 2859, 2550, 2548, 2524, 2596, -1,
    2566, 2567, -1,
    2642, 2643, 1085, -1,
    1368, 1367, 1369, 24, 1359, 21, 688, 430, 657, 421, -1,
    372, 685, 686, -1,
    768, 772, 771, 773, 774, 775, 685, 686, 688, 657, 421, -1,
    997, 998, 687, 703, -1,
    687, 703, 540, -1,
    1499, 601, 104, 103, -1,
    166, 557, 167, 179, 530, 493, 529, -1,
    131, 435, 601, 104, 1024, -1,
    1979, 1978, 1136, -1,
    1299, 1122, 1439, 1512, -1,
    2874, 2872, -1,
    494, 836, 865, 1969, 1968, 542, 575, 583, 1970, -1,
    494, 836, 1969, 1968, 575, -1,
    596, 598, 599, -1,
    907, 2086, 2087, 908, 914, 901, 906, 904, 915, 909, 916, 715, 825, 1137, -1,
    1110, 1111, 1112, -1,
    91, 2816, -1,
    112, 113, 114, -1,
    58, 60, 56, -1,
    58, 59, 60, 56, -1,
    1229, 1382, 1384, -1,
    423, 427, 428, 429, 453, 422, 454, 2999, -1,
    7, 6, 69, 66, 32, 31, 68, 33, 2665, 8, 5, 144, 218, 124, -1,
    1263, 1262, 61, -1,
    1560, 1263, 1262, 962, 953, 1060, 61, 62, -1,
    317, 1332, 314, 2096, 2098, 318, 1931, 1246, 473, 1102, 1152, 2575, 1150, -1,
    1246, 1152, 2575, 1150, -1,
    931, 930, -1,
    1213, 1321, 2063, 2062, 2061, 1318, 1620, 1316, 1445, 1214, 3017, 2060, 1216, 1217, 1621, 1444, 1622, -1,
    2221, 2220, 2219, 2218, 2217, 2215, 2214, 2213, 3009, 2228, 2226, 2212, 2225, 2224, 2886, -1,
    2220, 2219, 2218, 2215, 2214, 2213, 3009, 2228, 2226, 2211, 2225, 2224, 2886, -1,
    887, 946, 947, 945, 960, 894, -1,
    668, 662, -1,
    712, 610, 611, 1450, -1,
    634, 617, 443, 1698, 900, 1697, 2637, -1,
    2695, 2689, 1564, 1565, 267, 265, -1,
    689, 560, 725, 524, 690, 553, 551, 800, 547, 851, 691, 692, 520, 548, 546, 552, 693, 556, 554, 562, 519, 810, 2587, 563, 559, 2788, -1,
    1303, 1304, -1,
    1766, 2761, 2762, 2772, -1,
    2613, 2609, 2608, 2610, -1,
    1642, 1643, -1,
    2923, 2925, -1,
    1910, 1909, 2117, -1,
    2104, 2105, -1,
    1626, 2175, -1,
    507, 508, -1,
    936, 939, 378, 938, 985, 498, 415, 3015, 1108, 414, 431, 3014, 1471, 449, 499, -1,
    2360, 1498, 3015, 1108, 439, 499, -1,
    1135, 829, 1500, 649, -1,
    792, 793, 794, 795, -1,
    2183, 2920, -1,
    656, 2004, 2472, 2680, 2786, -1,
    952, 1088, 1520, 1357, -1,
    251, 1419, 2298, -1,
    1901, 2234, -1,
    2619, 2934, 2959, 2245, 1634, 2794, -1,
    1796, 1795, 2573, -1,
    2018, 2207, 2206, 2847, 2239, 1891, -1,
    2423, 3020, -1,
    1787, 2385, 1770, 2810, -1,
    1787, 1770, 2811, 2810, 2428, -1,
    2467, 2636, -1,
    1290, 1806, -1,
    2823, 2824, -1,
    2453, 2881, -1,
    2023, 2783, 2427, 2782, -1,
    2768, 2776, -1,
    1879, 2827, 2734, -1,
    2422, 2770, -1,
    2205, 2969, 2204, -1,
    1464, 1926, -1,
    301, 298, 2842, 304, 826, 817, -1,
    2938, 2056, 2055, 2233, 2058, -1,
    2844, 1830, 2997, -1,
    1769, 1768, -1,
    1282, 1283, -1,
    1282, 2562, 1283, 1366, 2324, -1,
    1995, 1992, 1627, -1,
    1952, 1951, 1954, -1,
    1927, 1935, 2154, 2151, 2363, 1889, 1939, 2144, 2128, 1938, -1,
    594, 877, 271, 232, 88, 213, 348, 872, 198, 2624, -1,
    139, 138, 1017, 1018, 1020, 1376, -1,
    1468, 1470, 2629, -1,
    1341, 1342, -1,
    1855, 1865, 1863, 1866, -1,
    746, 724, -1,
    1846, 1847, -1,
    1812, 1814, -1,
    2525, 2531, 2532, 2530, 2446, 1882, -1,
    2257, 1873, 1874, 2561, 1487, -1,
    2257, 2301, -1,
    1655, 1650, 1651, 1653, -1,
    469, 896, -1,
    1045, 1036, -1,
    1784, 1783, 1785, 1876, -1,
    2588, 2591, -1,
    2914, 411, 1431, 2916, 2915, 1672, -1,
    1375, 1371, 1373, -1,
    1001, 1756, -1,
    1001, 1763, 1756, 1762, -1,
    266, 1501, 1028, -1,
    339, 1443, -1,
    266, 1501, 1028, 1506, -1,
    223, 221, 222, 1298, 1297, -1,
    312, 1430, -1,
    1307, 1956, -1,
    1206, 2080, 1203, 1200, 1201, 1208, 1205, 1204, 1307, 1956, 1197, 1198, 1196, -1,
    1075, 1441, -1,
    2415, 2412, 2417, 2411, 2416, -1,
    2272, 2273, 2275, 2274, -1,
    190, 1696, -1,
    2459, 2464, -1,
    1483, 1479, -1,
    1514, 1656, 1686, 1689, 1688, 1685, 2048, 1050, 1090, 1687, -1,
    1484, 1476, -1,
    2607, 2623, -1,
    1906, 990, 989, 635, 1507, -1,
    1059, 1057, 1051, 1053, 1055, 2392, -1,
    1081, 1080, 1078, 1079, -1,
    1140, 1142, 1141, -1,
    2113, 1099, 2124, 2125, 2126, 2127, 2111, 2163, 2112, 2114, 2119, 2625, 2606, -1,
    184, 185, -1,
    2129, 2605, -1,
    1099, 2127, 2111, 2112, 2114, 2119, 2606, -1,
    157, 159, -1,
    573, 87, 1313, -1,
    1125, 2475, 1126, -1,
    2436, 1010, 1011, 2887, 1004, 1006, 1007, 1008, 1009, 1222, 1003, -1,
    1390, 1391, 1395, 1388, 1993, 1392, -1,
    73, 1091, 74, 287, 1326, 286, -1,
    1396, 1388, 1993, -1,
    1146, 1161, 1164, 1147, 1163, 2677, 1167, 1156, -1,
    1323, 571, 65, 572, -1,
    573, 87, 1313, 1315, -1,
    1268, 1269, 1270, -1,
    369, 2434, 367, -1,
    2433, 680, -1,
    2059, 3004, -1,
    2735, 306, -1,
    306, 2413, -1,
    1851, 1611, -1,
    2640, 2641, -1,
    1669, 1668, 2579, 2752, -1,
    1900, 2732, 2726, -1,
    1803, 1804, -1,
    458, 2307, -1,
    2947, 2307, -1,
    1035, 2031, 2027, 462, 2016, -1,
    2019, 2533, 2020, 1999, -1,
    2533, 2037, 2020, 1999, -1,
    2509, 2548, -1,
    2568, 987, 2548, -1,
    1035, 462, -1,
    20, 616, 23, 2834, 1123, -1,
    372, 657, -1,
    997, 1000, -1,
    766, 767, 372, -1,
    538, 539, 531, 1000, -1,
    537, 538, 539, 531, 702, 1186, 358, 1187, 1029, 1190, 1191, 1192, -1,
    592, 593, -1,
    180, 206, -1,
    164, 2130, 165, 2131, 268, -1,
    146, 147, 132, 150, 145, 148, 1073, 133, 197, 1031, 1025, 973, 1023, 1033, 1034, -1,
    179, 180, -1,
    357, 355, 356, 1434, 354, 353, -1,
    1012, 1014, -1,
    1092, 1074, -1,
    52, 53, 338, 337, 334, 340, 341, -1,
    911, 1130, -1,
    841, 2372, 1177, 870, 2354, 864, -1,
    168, 175, 967, 169, 170, 171, 173, 396, 912, -1,
    107, 108, 106, -1,
    233, 234, 2817, -1,
    1227, 1234, 828, 1235, 1228, 416, 1230, 1231, 1232, 1383, -1,
    4, 29, 35, 70, 2, 3, 665, 13, -1,
    1227, 1234, 1235, 1228, 1230, 1232, 1383, -1,
    584, 654, 2832, 587, 591, 590, 2362, -1,
    584, 2832, 587, 591, 2362, -1,
    336, 335, -1,
    243, 288, 289, 242, 1223, 1224, 290, 75, 2800, 241, 1272, -1,
    238, 614, -1,
    475, 2095, 325, 315, 9, 476, 489, 488, 2174, 480, 485, 490, 316, 1064, 202, 487, 483, 478, 484, 482, 392, 1103, 1101, 1397, -1,
    2684, 2685, 2682, 2683, -1,
    1924, 1922, 1983, 1921, 1923, 2141, 2139, 1984, 1982, 1918, 1985, 2140, -1,
    100, 663, 666, 664, 101, 105, 102, 661, 667, -1,
    1048, 1047, -1,
    1408, 1407, 2069, -1,
    1408, 1409, 1405, 1406, 1407, 245, 2069, -1,
    1408, 1409, 1405, 1406, 1407, 245, 2069, 878, -1,
    2795, 720, -1,
    509, 217, -1,
    260, 259, -1,
    1065, 1071, -1,
    513, 514, 515, -1,
    652, 852, -1,
    799, 802, 805, -1,
    801, 549, 804, 1041, 550, 806, 787, 2812, 561, 803, -1,
    1896, 1895, -1,
    2978, 2979, -1,
    1743, 1691, 1625, -1,
    1724, 1725, -1,
    1410, 2278, 2277, 2281, 2109, 2285, -1,
    1410, 2278, 2277, -1,
    963, 956, 959, -1,
    379, 452, 380, 497, -1,
    505, 2132, -1,
    2600, 2599, -1,
    2869, 2870, -1,
    2867, 2003, -1,
    425, 393, -1,
    1084, 305, 2236, -1,
    1828, 2791, -1,
    255, 2297, -1,
    2793, 255, -1,
    844, 885, 884, 850, -1,
    1794, 1801, 1798, 1797, -1,
    1118, 2520, -1,
    2427, 2825, -1,
    1757, 2656, 2830, -1,
    2388, 2767, -1,
    1818, 2461, -1,
    1757, 1758, 2656, 2830, -1,
    1818, 2043, 2461, 2042, -1,
    1765, 1809, -1,
    2840, 2012, -1,
    2850, 2854, -1,
    2089, 1774, 1575, -1,
    1774, 1575, 2373, -1,
    1590, 1838, 1578, -1,
    1838, 1837, 1578, -1,
    646, 647, 1275, -1,
    1633, 1632, 1640, -1,
    1944, 1945, 1946, 2369, 1942, 1948, 1947, -1,
    555, 2639, 1950, -1,
    2152, 2155, -1,
    1929, 1937, 1940, 1930, 1925, 1936, 2137, -1,
    1076, 523, 269, 347, 349, -1,
    2391, 2435, -1,
    1820, 1821, 2733, -1,
    352, 1287, 1175, -1,
    2722, 2721, -1,
    2721, 2720, -1,
    1134, 1133, -1,
    2528, 2580, 2529, 2445, 2444, 2447, 403, -1,
    2445, 2444, 403, -1,
    2580, 403, -1,
    897, 196, -1,
    898, 897, -1,
    1875, 2419, -1,
    2083, 1438, 258, 1673, 1670, -1,
    1772, 1773, -1,
    1751, 1741, -1,
    1741, 1771, -1,
    228, 225, 2885, -1,
    220, 219, -1,
    1202, 1209, 1193, 1195, 1194, -1,
    211, 695, -1,
    1987, 1986, -1,
    2343, 2314, -1,
    2415, 2412, -1,
    1692, 1603, -1,
    1692, 1694, -1,
    311, 1042, 1043, -1,
    1554, 716, -1,
    2106, 2458, -1,
    1095, 780, -1,
    1490, 1492, -1,
    158, 160, -1,
    158, 160, 1380, -1,
    1849, 208, 412, -1,
    913, 1355, 1356, 285, -1,
    913, 1091, 1350, -1,
    1145, 1162, 1149, 1144, 1154, -1,
    86, 574, -1,
    764, 1345, 790, 1335, -1,
    2068, 2067, 2066, -1,
    2053, 2146, -1,
    1328, 1330, -1,
    2725, 2660, -1,
    1813, 1829, -1,
    1461, 1462, 1459, -1,
    1461, 1462, -1,
    1638, 902, -1,
    847, 848, -1,
    2037, 2026, -1,
    1449, 2019, -1,
    2522, 2567, 2524, -1,
    153, 156, 1736, -1,
    2161, 156, 47, 49, 51, 1736, -1,
    153, 49, 51, -1,
    765, 769, -1,
    1188, 1189, -1,
    998, 1188, 1190, -1,
    980, 319, 981, 320, 2476, -1,
    130, 149, 782, 595, -1,
    2707, 2705, -1,
    134, 181, -1,
    834, 582, -1,
    2188, 333, -1,
    905, 910, -1,
    707, 709, -1,
    17, 18, -1,
    1109, 1113, 1114, -1,
    397, 174, 903, 2833, -1,
    94, 2822, 116, 95, 96, -1,
    77, 2897, -1,
    57, 739, -1,
    57, 55, 739, -1,
    1233, 1280, -1,
    155, 27, 570, -1,
    588, 2806, 589, -1,
    588, 589, -1,
    284, 2401, 2546, -1,
    332, 330, 331, -1,
    332, 330, -1,
    481, 3024, 3000, 486, 345, 299, 2190, -1,
    543, 544, 564, 545, 565, -1,
    544, 564, 545, 565, 2682, -1,
    3025, 655, 504, 503, 413, -1,
    481, 345, -1,
    2806, 591, 590, -1,
    1403, 1404, 244, 1409, -1,
    1403, 1404, -1,
    840, 2982, -1,
    604, 714, 713, -1,
    1181, 1302, 2384, -1,
    1181, 1302, 1183, 2384, -1,
    730, 1104, -1,
    1069, 1070, -1,
    2781, 2754, -1,
    2691, 2692, 2694, -1,
    2686, 2687, 2688, 2690, 2691, 2692, 2693, 2694, -1,
    2632, 2628, -1,
    1714, 1713, -1,
    2490, 2488, -1,
    1724, 1725, 1726, -1,
    961, 955, 957, 958, 282, 2919, -1,
    940, 941, -1,
    501, 1596, -1,
    937, 942, 1440, -1,
    1420, 1421, 1422, 1424, 1348, 1423, 1349, -1,
    1420, 1421, 1422, 1424, 1348, 1423, 1349, 1433, 1432, 1425, 2312, 1426, -1,
    1590, 1645, -1,
    1618, 1676, -1,
    2758, 2757, -1,
    326, 201, 2962, 426, -1,
    558, 1347, 1016, 1015, -1,
    2399, 2730, -1,
    2723, 2724, -1,
    895, 899, -1,
    1442, 1497, 2173, -1,
    2494, 2495, -1,
    227, 225, -1,
    694, 1267, -1,
    619, 623, -1,
    862, 854, -1,
    2708, 2704, 2706, -1,
    346, 1117, -1,
    1233, 828, -1,
    468, 182, 465, -1,
    468, 465, -1,
    329, 331, -1,
    324, 2097, 323, -1,
    344, 324, 2097, 343, -1,
    1409, 1405, -1,
    1405, 245, 2676, -1,
    2818, 253, -1,
    1181, 1302, -1,
    512, 513, -1,
    1422, 1424, 1423, -1,
    854, 2031, -1,
    2718, 2717, -1,
    533, 534, -1,
};

static const constexpr LineMetaDataQuadTreeDepthIndex line_data_depthOffsets[] = {
    { 27, 0 },
    { 26, 2 },
    { 25, 17 },
    { 24, 68 },
    { 23, 180 },
    { 22, 391 },
    { 21, 727 },
    { 20, 1103 },
    { 19, 1453 },
    { 18, 1624 },
    { 17, 1699 },
    { 16, 1765 },
};

static const constexpr LineMetaDataZIndex line_data_zquadtree[] = {
    { 227, Bucket(0) }, // 30.8, -5.517 x 44.22, 7.905
    { 236, 1730 }, // 44.22, 7.905 x 57.64, 21.33
    { 390, 2485 }, // 30.8, -119.6 x 37.51, -112.9
    { 397, 2088 }, // 37.51, -112.9 x 44.22, -106.2
    { 400, 1816 }, // 44.22, -126.3 x 50.93, -119.6
    { 431, Bucket(6) }, // 37.51, -79.34 x 44.22, -72.63
    { 773, 1155 }, // 37.51, -72.63 x 44.22, -65.91
    { 903, 1039 }, // 37.51, -12.23 x 44.22, -5.517
    { 909, 1522 }, // 37.51, -5.517 x 44.22, 1.194
    { 911, Bucket(14) }, // 37.51, 1.194 x 44.22, 7.905
    { 922, 1127 }, // 44.22, 1.194 x 50.93, 7.905
    { 923, 1542 }, // 50.93, 1.194 x 57.64, 7.905
    { 944, Bucket(18) }, // 44.22, 7.905 x 50.93, 14.62
    { 945, 743 }, // 50.93, 7.905 x 57.64, 14.62
    { 946, Bucket(25) }, // 44.22, 14.62 x 50.93, 21.33
    { 950, Bucket(34) }, // 57.64, 14.62 x 64.35, 21.33
    { 956, Bucket(38) }, // 57.64, 21.33 x 64.35, 28.04
    { 1555, 2209 }, // 34.15, -123 x 37.51, -119.6
    { 1558, 2209 }, // 37.51, -123 x 40.86, -119.6
    { 1560, Bucket(41) }, // 30.8, -119.6 x 34.15, -116.2
    { 1561, 1436 }, // 34.15, -119.6 x 37.51, -116.2
    { 1695, Bucket(47) }, // 40.86, -89.4 x 44.22, -86.05
    { 1719, 2514 }, // 40.86, -82.69 x 44.22, -79.34
    { 1724, Bucket(58) }, // 37.51, -79.34 x 40.86, -75.98
    { 1726, Bucket(62) }, // 37.51, -75.98 x 40.86, -72.63
    { 1727, 362 }, // 40.86, -75.98 x 44.22, -72.63
    { 2314, Bucket(66) }, // -36.31, -62.56 x -32.96, -59.2
    { 2336, Bucket(66) }, // -36.31, -59.2 x -32.96, -55.85
    { 3093, Bucket(69) }, // 40.86, -72.63 x 44.22, -69.27
    { 3636, Bucket(72) }, // 37.51, -5.517 x 40.86, -2.162
    { 3638, Bucket(77) }, // 37.51, -2.162 x 40.86, 1.194
    { 3641, Bucket(80) }, // 34.15, 1.194 x 37.51, 4.549
    { 3645, Bucket(98) }, // 40.86, 1.194 x 44.22, 4.549
    { 3683, 1415 }, // 47.57, -2.162 x 50.93, 1.194
    { 3685, Bucket(105) }, // 54.28, -5.517 x 57.64, -2.162
    { 3686, Bucket(108) }, // 50.93, -2.162 x 54.28, 1.194
    { 3689, Bucket(112) }, // 47.57, 1.194 x 50.93, 4.549
    { 3690, Bucket(119) }, // 44.22, 4.549 x 47.57, 7.905
    { 3692, 977 }, // 50.93, 1.194 x 54.28, 4.549
    { 3735, Bucket(127) }, // 40.86, 11.26 x 44.22, 14.62
    { 3776, Bucket(131) }, // 44.22, 7.905 x 47.57, 11.26
    { 3777, 205 }, // 47.57, 7.905 x 50.93, 11.26
    { 3778, 1504 }, // 44.22, 11.26 x 47.57, 14.62
    { 3779, Bucket(134) }, // 47.57, 11.26 x 50.93, 14.62
    { 3780, Bucket(137) }, // 50.93, 7.905 x 54.28, 11.26
    { 3781, Bucket(143) }, // 54.28, 7.905 x 57.64, 11.26
    { 3782, Bucket(146) }, // 50.93, 11.26 x 54.28, 14.62
    { 3783, 704 }, // 54.28, 11.26 x 57.64, 14.62
    { 3785, Bucket(160) }, // 47.57, 14.62 x 50.93, 17.97
    { 3786, Bucket(167) }, // 44.22, 17.97 x 47.57, 21.33
    { 3787, 1249 }, // 47.57, 17.97 x 50.93, 21.33
    { 3788, 2262 }, // 50.93, 14.62 x 54.28, 17.97
    { 3790, 3026 }, // 50.93, 17.97 x 54.28, 21.33
    { 3800, Bucket(177) }, // 57.64, 14.62 x 60.99, 17.97
    { 3802, Bucket(177) }, // 57.64, 17.97 x 60.99, 21.33
    { 3826, Bucket(180) }, // 57.64, 24.68 x 60.99, 28.04
    { 9050, 2930 }, // 3.952, 98.5 x 7.308, 101.9
    { 9180, 2552 }, // 10.66, 122 x 14.02, 125.3
    { 9285, 2405 }, // 54.28, 34.75 x 57.64, 38.1
    { 9354, Bucket(183) }, // 17.37, 71.66 x 20.73, 75.01
    { 9771, 2237 }, // 20.73, 111.9 x 24.09, 115.3
    { 9863, Bucket(186) }, // 27.44, 118.6 x 30.8, 122
    { 9875, Bucket(190) }, // 34.15, 118.6 x 37.51, 122
    { 9876, 2602 }, // 37.51, 115.3 x 40.86, 118.6
    { 9883, Bucket(194) }, // 34.15, 125.3 x 37.51, 128.7
    { 9886, Bucket(194) }, // 37.51, 125.3 x 40.86, 128.7
    { 9913, 2669 }, // 34.15, 135.4 x 37.51, 138.8
    { 9915, Bucket(202) }, // 34.15, 138.8 x 37.51, 142.1
    { 3830, 1644 }, // -12.82, -77.66 x -11.15, -75.98
    { 6221, Bucket(213) }, // 35.83, -123 x 37.51, -121.3
    { 6232, Bucket(218) }, // 37.51, -123 x 39.18, -121.3
    { 6243, Bucket(226) }, // 32.47, -117.9 x 34.15, -116.2
    { 6337, 375 }, // 32.47, -112.9 x 34.15, -111.2
    { 6723, Bucket(231) }, // 32.47, -97.79 x 34.15, -96.11
    { 6770, Bucket(235) }, // 37.51, -91.08 x 39.18, -89.4
    { 6782, Bucket(238) }, // 40.86, -87.73 x 42.54, -86.05
    { 6879, Bucket(241) }, // 42.54, -81.01 x 44.22, -79.34
    { 6898, 2443 }, // 37.51, -77.66 x 39.18, -75.98
    { 6901, Bucket(250) }, // 42.54, -79.34 x 44.22, -77.66
    { 6905, Bucket(258) }, // 39.18, -75.98 x 40.86, -74.3
    { 6907, 1159 }, // 39.18, -74.3 x 40.86, -72.63
    { 6910, 2473 }, // 40.86, -74.3 x 42.54, -72.63
    { 6922, 671 }, // 44.22, -94.44 x 45.9, -92.76
    { 7082, 2159 }, // 44.22, -74.3 x 45.9, -72.63
    { 9268, 2803 }, // -26.25, -65.91 x -24.57, -64.24
    { 9407, Bucket(269) }, // -24.57, -47.46 x -22.89, -45.78
    { 9751, Bucket(275) }, // -24.57, -44.1 x -22.89, -42.43
    { 9794, Bucket(275) }, // -22.89, -44.1 x -21.21, -42.43
    { 12372, Bucket(282) }, // 40.86, -72.63 x 42.54, -70.95
    { 14533, Bucket(286) }, // 35.83, -5.517 x 37.51, -3.839
    { 14551, 1511 }, // 42.54, -3.839 x 44.22, -2.162
    { 14558, 1541 }, // 40.86, -0.4838 x 42.54, 1.194
    { 14580, Bucket(289) }, // 40.86, 1.194 x 42.54, 2.872
    { 14651, Bucket(304) }, // 52.61, -7.195 x 54.28, -5.517
    { 14729, 293 }, // 45.9, -2.162 x 47.57, -0.4838
    { 14739, Bucket(307) }, // 52.61, -3.839 x 54.28, -2.162
    { 14745, Bucket(308) }, // 52.61, -2.162 x 54.28, -0.4838
    { 14756, Bucket(311) }, // 47.57, 1.194 x 49.25, 2.872
    { 14759, Bucket(317) }, // 49.25, 2.872 x 50.93, 4.549
    { 14760, 642 }, // 44.22, 4.549 x 45.9, 6.227
    { 14762, Bucket(321) }, // 44.22, 6.227 x 45.9, 7.905
    { 14763, Bucket(328) }, // 45.9, 6.227 x 47.57, 7.905
    { 14765, 1455 }, // 49.25, 4.549 x 50.93, 6.227
    { 14766, 257 }, // 47.57, 6.227 x 49.25, 7.905
    { 14767, Bucket(340) }, // 49.25, 6.227 x 50.93, 7.905
    { 14770, Bucket(350) }, // 50.93, 2.872 x 52.61, 4.549
    { 14776, 1455 }, // 50.93, 4.549 x 52.61, 6.227
    { 14778, Bucket(353) }, // 50.93, 6.227 x 52.61, 7.905
    { 14940, Bucket(373) }, // 40.86, 11.26 x 42.54, 12.94
    { 15031, 866 }, // 29.12, 29.72 x 30.8, 31.39
    { 15056, 2738 }, // 37.51, 21.33 x 39.18, 23
    { 15058, Bucket(378) }, // 37.51, 23 x 39.18, 24.68
    { 15089, 1786 }, // 39.18, 28.04 x 40.86, 29.72
    { 15092, Bucket(383) }, // 40.86, 28.04 x 42.54, 29.72
    { 15104, Bucket(387) }, // 44.22, 7.905 x 45.9, 9.583
    { 15105, Bucket(392) }, // 45.9, 7.905 x 47.57, 9.583
    { 15107, Bucket(409) }, // 45.9, 9.583 x 47.57, 11.26
    { 15108, Bucket(412) }, // 47.57, 7.905 x 49.25, 9.583
    { 15109, Bucket(420) }, // 49.25, 7.905 x 50.93, 9.583
    { 15110, Bucket(426) }, // 47.57, 9.583 x 49.25, 11.26
    { 15111, Bucket(429) }, // 49.25, 9.583 x 50.93, 11.26
    { 15113, Bucket(433) }, // 45.9, 11.26 x 47.57, 12.94
    { 15115, Bucket(437) }, // 45.9, 12.94 x 47.57, 14.62
    { 15116, Bucket(440) }, // 47.57, 11.26 x 49.25, 12.94
    { 15117, Bucket(448) }, // 49.25, 11.26 x 50.93, 12.94
    { 15119, Bucket(451) }, // 49.25, 12.94 x 50.93, 14.62
    { 15121, Bucket(457) }, // 52.61, 7.905 x 54.28, 9.583
    { 15123, 740 }, // 52.61, 9.583 x 54.28, 11.26
    { 15127, 2942 }, // 55.96, 9.583 x 57.64, 11.26
    { 15128, Bucket(464) }, // 50.93, 11.26 x 52.61, 12.94
    { 15129, Bucket(472) }, // 52.61, 11.26 x 54.28, 12.94
    { 15130, Bucket(476) }, // 50.93, 12.94 x 52.61, 14.62
    { 15132, Bucket(484) }, // 54.28, 11.26 x 55.96, 12.94
    { 15137, Bucket(487) }, // 45.9, 14.62 x 47.57, 16.29
    { 15140, 2251 }, // 47.57, 14.62 x 49.25, 16.29
    { 15142, 1259 }, // 47.57, 16.29 x 49.25, 17.97
    { 15145, Bucket(493) }, // 45.9, 17.97 x 47.57, 19.65
    { 15148, 2176 }, // 47.57, 17.97 x 49.25, 19.65
    { 15160, Bucket(504) }, // 50.93, 17.97 x 52.61, 19.65
    { 15171, 723 }, // 59.32, 9.583 x 60.99, 11.26
    { 15271, Bucket(507) }, // 49.25, 29.72 x 50.93, 31.39
    { 15299, Bucket(512) }, // 59.32, 23 x 60.99, 24.68
    { 15302, 2646 }, // 60.99, 23 x 62.67, 24.68
    { 15305, Bucket(511) }, // 59.32, 24.68 x 60.99, 26.36
    { 34771, Bucket(516) }, // 12.34, 76.69 x 14.02, 78.37
    { 34779, 1958 }, // 12.34, 80.05 x 14.02, 81.72
    { 36159, Bucket(519) }, // 2.275, 100.2 x 3.952, 101.9
    { 36202, 2932 }, // 3.952, 100.2 x 5.63, 101.9
    { 36245, 2358 }, // 2.275, 101.9 x 3.952, 103.5
    { 36246, Bucket(528) }, // 0.597, 103.5 x 2.275, 105.2
    { 36356, Bucket(531) }, // -32.96, 115.3 x -31.28, 117
    { 36702, Bucket(534) }, // 14.02, 120.3 x 15.7, 122
    { 36944, Bucket(540) }, // 37.51, 34.75 x 39.18, 36.43
    { 37142, 2406 }, // 54.28, 36.43 x 55.96, 38.1
    { 37276, Bucket(545) }, // 54.28, 51.53 x 55.96, 53.2
    { 37526, 2138 }, // 27.44, 76.69 x 29.12, 78.37
    { 39056, Bucket(552) }, // 24.09, 101.9 x 25.76, 103.5
    { 39063, 2635 }, // 29.12, 103.5 x 30.8, 105.2
    { 39065, 2759 }, // 25.76, 105.2 x 27.44, 106.9
    { 39085, Bucket(556) }, // 22.41, 111.9 x 24.09, 113.6
    { 39100, Bucket(559) }, // 27.44, 111.9 x 29.12, 113.6
    { 39103, Bucket(562) }, // 29.12, 113.6 x 30.8, 115.3
    { 39162, Bucket(565) }, // 37.51, 113.6 x 39.18, 115.3
    { 39449, Bucket(568) }, // 25.76, 118.6 x 27.44, 120.3
    { 39453, 2768 }, // 29.12, 118.6 x 30.8, 120.3
    { 39455, 2697 }, // 29.12, 120.3 x 30.8, 122
    { 39493, Bucket(571) }, // 35.83, 115.3 x 37.51, 117
    { 39495, 2015 }, // 35.83, 117 x 37.51, 118.6
    { 39496, 2200 }, // 30.8, 118.6 x 32.47, 120.3
    { 39498, Bucket(574) }, // 30.8, 120.3 x 32.47, 122
    { 39505, Bucket(577) }, // 39.18, 115.3 x 40.86, 117
    { 39514, 1886 }, // 37.51, 120.3 x 39.18, 122
    { 39540, 1826 }, // 40.86, 122 x 42.54, 123.7
    { 39652, 2393 }, // 34.15, 135.4 x 35.83, 137.1
    { 39660, Bucket(587) }, // 34.15, 138.8 x 35.83, 140.4
    { 39661, 2657 }, // 35.83, 138.8 x 37.51, 140.4
    { 39679, 1916 }, // 42.54, 140.4 x 44.22, 142.1
    { 41819, 1325 }, // -41.35, 174 x -39.67, 175.7
    { 41823, 10 }, // -37.99, 174 x -36.31, 175.7
    { 42019, 2179 }, // -34.64, 150.5 x -32.96, 152.2
    { 12287, 1473 }, // -37.15, -73.46 x -36.31, -72.63
    { 16292, 424 }, // 5.63, -75.98 x 6.469, -75.14
    { 24928, 873 }, // 37.51, -123 x 38.35, -122.1
    { 24967, Bucket(595) }, // 33.31, -118.8 x 34.15, -117.9
    { 24972, Bucket(600) }, // 32.47, -117.9 x 33.31, -117.1
    { 24978, Bucket(613) }, // 34.15, -118.8 x 34.99, -117.9
    { 25542, Bucket(616) }, // 39.18, -105.3 x 40.02, -104.5
    { 25633, Bucket(624) }, // 45.06, -123 x 45.9, -122.1
    { 25637, 2370 }, // 46.73, -123 x 47.57, -122.1
    { 25789, 2293 }, // 50.09, -114.6 x 50.93, -113.7
    { 25832, Bucket(629) }, // 50.93, -114.6 x 51.77, -113.7
    { 26628, Bucket(632) }, // 19.05, -99.47 x 19.89, -98.63
    { 26711, 2497 }, // 29.96, -98.63 x 30.8, -97.79
    { 26717, Bucket(641) }, // 29.96, -97.79 x 30.8, -96.95
    { 26892, 2501 }, // 32.47, -97.79 x 33.31, -96.95
    { 26894, Bucket(644) }, // 32.47, -96.95 x 33.31, -96.11
    { 27399, Bucket(648) }, // 33.31, -85.21 x 34.15, -84.37
    { 27405, Bucket(648) }, // 33.31, -84.37 x 34.15, -83.53
    { 27503, Bucket(651) }, // 40.02, -80.18 x 40.86, -79.34
    { 27519, Bucket(655) }, // 43.38, -80.18 x 44.22, -79.34
    { 27593, Bucket(661) }, // 38.35, -77.66 x 39.18, -76.82
    { 27605, Bucket(664) }, // 43.38, -79.34 x 44.22, -78.5
    { 27620, 2450 }, // 39.18, -75.98 x 40.02, -75.14
    { 27629, Bucket(668) }, // 40.02, -74.3 x 40.86, -73.46
    { 27640, Bucket(692) }, // 40.86, -74.3 x 41.7, -73.46
    { 27690, 2085 }, // 44.22, -93.6 x 45.06, -92.76
    { 28329, Bucket(699) }, // 45.06, -74.3 x 45.9, -73.46
    { 36877, 2250 }, // -33.8, -70.95 x -32.96, -70.11
    { 36901, 996 }, // -33.8, -69.27 x -32.96, -68.43
    { 36912, 996 }, // -32.96, -69.27 x -32.12, -68.43
    { 37049, 2814 }, // -32.12, -60.88 x -31.28, -60.04
    { 37377, 1022 }, // -35.47, -59.2 x -34.64, -58.37
    { 37380, Bucket(705) }, // -34.64, -59.2 x -33.8, -58.37
    { 37527, 1281 }, // -30.44, -51.65 x -29.6, -50.82
    { 40084, 2353 }, // -4.436, -39.07 x -3.597, -38.23
    { 40097, 1160 }, // -8.631, -35.72 x -7.792, -34.88
    { 40112, 2323 }, // -6.114, -35.72 x -5.275, -34.88
    { 49491, 1139 }, // 41.7, -71.79 x 42.54, -70.95
    { 57767, Bucket(709) }, // 33.31, -8.034 x 34.15, -7.195
    { 57773, 1278 }, // 33.31, -7.195 x 34.15, -6.356
    { 57791, Bucket(713) }, // 36.67, -6.356 x 37.51, -5.517
    { 57834, Bucket(717) }, // 37.51, -6.356 x 38.35, -5.517
    { 57840, Bucket(720) }, // 40.86, -8.872 x 41.7, -8.034
    { 58189, Bucket(725) }, // 40.02, -3.839 x 40.86, -3
    { 58214, 1296 }, // 39.18, -1.323 x 40.02, -0.4838
    { 58217, 2968 }, // 38.35, -0.4838 x 39.18, 0.3551
    { 58220, 1296 }, // 39.18, -0.4838 x 40.02, 0.3551
    { 58226, 467 }, // 40.86, -1.323 x 41.7, -0.4838
    { 58227, 467 }, // 41.7, -1.323 x 42.54, -0.4838
    { 58982, 214 }, // 52.61, -1.323 x 53.45, -0.4838
    { 58984, Bucket(736) }, // 50.93, -0.4838 x 51.77, 0.3551
    { 59027, Bucket(750) }, // 48.41, 2.033 x 49.25, 2.872
    { 59039, Bucket(768) }, // 50.09, 3.711 x 50.93, 4.549
    { 59041, Bucket(779) }, // 45.06, 4.549 x 45.9, 5.388
    { 59043, Bucket(782) }, // 45.06, 5.388 x 45.9, 6.227
    { 59046, 2454 }, // 45.9, 5.388 x 46.73, 6.227
    { 59052, Bucket(785) }, // 45.9, 6.227 x 46.73, 7.066
    { 59053, 1740 }, // 46.73, 6.227 x 47.57, 7.066
    { 59055, Bucket(788) }, // 46.73, 7.066 x 47.57, 7.905
    { 59061, Bucket(801) }, // 50.09, 4.549 x 50.93, 5.388
    { 59063, 1537 }, // 50.09, 5.388 x 50.93, 6.227
    { 59070, 685 }, // 49.25, 7.066 x 50.09, 7.905
    { 59082, Bucket(804) }, // 50.93, 3.711 x 51.77, 4.549
    { 59083, 1351 }, // 51.77, 3.711 x 52.61, 4.549
    { 59105, Bucket(810) }, // 51.77, 4.549 x 52.61, 5.388
    { 59112, Bucket(816) }, // 50.93, 6.227 x 51.77, 7.066
    { 59114, Bucket(822) }, // 50.93, 7.066 x 51.77, 7.905
    { 59759, 2739 }, // 40.02, 13.78 x 40.86, 14.62
    { 59763, Bucket(828) }, // 41.7, 12.1 x 42.54, 12.94
    { 59770, 2739 }, // 40.86, 13.78 x 41.7, 14.62
    { 59864, 934 }, // 40.86, 16.29 x 41.7, 17.13
    { 60226, 2051 }, // 37.51, 22.17 x 38.35, 23
    { 60232, Bucket(834) }, // 37.51, 23 x 38.35, 23.84
    { 60370, 1637 }, // 40.86, 28.88 x 41.7, 29.72
    { 60390, Bucket(838) }, // 39.18, 32.23 x 40.02, 33.07
    { 60419, Bucket(841) }, // 45.06, 8.744 x 45.9, 9.583
    { 60420, 1734 }, // 45.9, 7.905 x 46.73, 8.744
    { 60421, Bucket(855) }, // 46.73, 7.905 x 47.57, 8.744
    { 60422, 2909 }, // 45.9, 8.744 x 46.73, 9.583
    { 60423, Bucket(870) }, // 46.73, 8.744 x 47.57, 9.583
    { 60425, Bucket(877) }, // 45.06, 9.583 x 45.9, 10.42
    { 60432, Bucket(880) }, // 47.57, 7.905 x 48.41, 8.744
    { 60433, Bucket(883) }, // 48.41, 7.905 x 49.25, 8.744
    { 60434, Bucket(891) }, // 47.57, 8.744 x 48.41, 9.583
    { 60435, Bucket(895) }, // 48.41, 8.744 x 49.25, 9.583
    { 60436, Bucket(915) }, // 49.25, 7.905 x 50.09, 8.744
    { 60437, Bucket(919) }, // 50.09, 7.905 x 50.93, 8.744
    { 60438, 657 }, // 49.25, 8.744 x 50.09, 9.583
    { 60442, 272 }, // 47.57, 10.42 x 48.41, 11.26
    { 60443, Bucket(923) }, // 48.41, 10.42 x 49.25, 11.26
    { 60446, Bucket(926) }, // 49.25, 10.42 x 50.09, 11.26
    { 60447, 2745 }, // 50.09, 10.42 x 50.93, 11.26
    { 60453, Bucket(931) }, // 46.73, 11.26 x 47.57, 12.1
    { 60464, Bucket(934) }, // 47.57, 11.26 x 48.41, 12.1
    { 60465, 2698 }, // 48.41, 11.26 x 49.25, 12.1
    { 60467, 2030 }, // 48.41, 12.1 x 49.25, 12.94
    { 60468, Bucket(945) }, // 49.25, 11.26 x 50.09, 12.1
    { 60474, Bucket(948) }, // 47.57, 13.78 x 48.41, 14.62
    { 60476, 1013 }, // 49.25, 12.94 x 50.09, 13.78
    { 60477, 1384 }, // 50.09, 12.94 x 50.93, 13.78
    { 60483, 715 }, // 51.77, 8.744 x 52.61, 9.583
    { 60489, Bucket(952) }, // 51.77, 9.583 x 52.61, 10.42
    { 60492, Bucket(954) }, // 52.61, 9.583 x 53.45, 10.42
    { 60493, Bucket(957) }, // 53.45, 9.583 x 54.28, 10.42
    { 60512, 172 }, // 50.93, 11.26 x 51.77, 12.1
    { 60513, Bucket(968) }, // 51.77, 11.26 x 52.61, 12.1
    { 60514, Bucket(972) }, // 50.93, 12.1 x 51.77, 12.94
    { 60515, 1641 }, // 51.77, 12.1 x 52.61, 12.94
    { 60516, 117 }, // 52.61, 11.26 x 53.45, 12.1
    { 60521, Bucket(982) }, // 51.77, 12.94 x 52.61, 13.78
    { 60522, 1382 }, // 50.93, 13.78 x 51.77, 14.62
    { 60524, Bucket(1006) }, // 52.61, 12.94 x 53.45, 13.78
    { 60526, 1613 }, // 52.61, 13.78 x 53.45, 14.62
    { 60531, Bucket(1013) }, // 55.12, 12.1 x 55.96, 12.94
    { 60549, Bucket(1020) }, // 46.73, 14.62 x 47.57, 15.45
    { 60550, 154 }, // 45.9, 15.45 x 46.73, 16.29
    { 60551, 2853 }, // 46.73, 15.45 x 47.57, 16.29
    { 60568, 822 }, // 47.57, 16.29 x 48.41, 17.13
    { 60581, 1237 }, // 46.73, 17.97 x 47.57, 18.81
    { 60583, Bucket(1023) }, // 46.73, 18.81 x 47.57, 19.65
    { 60588, 2753 }, // 45.9, 19.65 x 46.73, 20.49
    { 60589, Bucket(1029) }, // 46.73, 19.65 x 47.57, 20.49
    { 60592, Bucket(1033) }, // 47.57, 17.97 x 48.41, 18.81
    { 60594, Bucket(1036) }, // 47.57, 18.81 x 48.41, 19.65
    { 60600, 1239 }, // 47.57, 19.65 x 48.41, 20.49
    { 60609, 1496 }, // 51.77, 14.62 x 52.61, 15.45
    { 60651, 263 }, // 51.77, 20.49 x 52.61, 21.33
    { 60686, Bucket(1040) }, // 59.32, 10.42 x 60.16, 11.26
    { 60811, 248 }, // 58.48, 17.13 x 59.32, 17.97
    { 60933, 1932 }, // 46.73, 21.33 x 47.57, 22.17
    { 60975, Bucket(1046) }, // 46.73, 27.2 x 47.57, 28.04
    { 61039, Bucket(1052) }, // 53.45, 27.2 x 54.28, 28.04
    { 61085, 3007 }, // 50.09, 29.72 x 50.93, 30.55
    { 61112, Bucket(1055) }, // 47.57, 33.07 x 48.41, 33.91
    { 61145, Bucket(1059) }, // 55.12, 29.72 x 55.96, 30.55
    { 61221, Bucket(1063) }, // 60.16, 24.68 x 60.99, 25.52
    { 61324, Bucket(1067) }, // 59.32, 29.72 x 60.16, 30.55
    { 144855, Bucket(1070) }, // 16.54, 95.99 x 17.37, 96.82
    { 144877, Bucket(1073) }, // 13.18, 100.2 x 14.02, 101
    { 144984, Bucket(1077) }, // 0.597, 103.5 x 1.436, 104.4
    { 145425, 2927 }, // -32.12, 115.3 x -31.28, 116.1
    { 146887, Bucket(1081) }, // 13.18, 122.8 x 14.02, 123.7
    { 147743, 2935 }, // 36.67, 37.26 x 37.51, 38.1
    { 147777, 2994 }, // 38.35, 34.75 x 39.18, 35.59
    { 147794, 2971 }, // 40.86, 35.59 x 41.7, 36.43
    { 147800, 2971 }, // 40.86, 36.43 x 41.7, 37.26
    { 148043, 2192 }, // 24.92, 50.69 x 25.76, 51.53
    { 148065, 2192 }, // 24.92, 51.53 x 25.76, 52.36
    { 148161, Bucket(1084) }, // 24.92, 54.88 x 25.76, 55.72
    { 148251, 1683 }, // 34.99, 50.69 x 35.83, 51.53
    { 148406, 308 }, // 35.83, 59.08 x 36.67, 59.91
    { 148495, Bucket(1087) }, // 46.73, 37.26 x 47.57, 38.1
    { 148571, Bucket(1092) }, // 55.12, 37.26 x 55.96, 38.1
    { 149068, 2407 }, // 52.61, 49.85 x 53.45, 50.69
    { 149667, 2559 }, // 18.21, 72.5 x 19.05, 73.34
    { 149670, 2559 }, // 19.05, 72.5 x 19.89, 73.34
    { 149970, Bucket(1109) }, // 40.86, 69.14 x 41.7, 69.98
    { 150064, Bucket(1112) }, // 20.73, 78.37 x 21.57, 79.21
    { 150105, Bucket(1115) }, // 28.28, 76.69 x 29.12, 77.53
    { 150525, 2093 }, // 43.38, 86.76 x 44.22, 87.6
    { 150527, 2093 }, // 43.38, 87.6 x 44.22, 88.44
    { 156222, Bucket(1123) }, // 22.41, 107.7 x 23.25, 108.6
    { 156253, Bucket(1128) }, // 29.96, 103.5 x 30.8, 104.4
    { 156278, Bucket(1135) }, // 29.12, 106.1 x 29.96, 106.9
    { 156342, Bucket(1143) }, // 22.41, 112.8 x 23.25, 113.6
    { 156343, 2328 }, // 23.25, 112.8 x 24.09, 113.6
    { 156345, Bucket(1150) }, // 21.57, 113.6 x 22.41, 114.4
    { 156348, Bucket(1154) }, // 22.41, 113.6 x 23.25, 114.4
    { 156402, 2892 }, // 27.44, 112.8 x 28.28, 113.6
    { 156413, Bucket(1162) }, // 29.96, 113.6 x 30.8, 114.4
    { 156424, Bucket(1166) }, // 30.8, 103.5 x 31.63, 104.4
    { 156549, Bucket(1170) }, // 33.31, 108.6 x 34.15, 109.4
    { 156560, Bucket(1173) }, // 34.15, 108.6 x 34.99, 109.4
    { 156592, 2773 }, // 34.15, 111.9 x 34.99, 112.8
    { 156600, 1788 }, // 34.15, 113.6 x 34.99, 114.4
    { 157770, Bucket(1180) }, // 24.09, 117.8 x 24.92, 118.6
    { 157777, Bucket(1184) }, // 28.28, 115.3 x 29.12, 116.1
    { 157803, Bucket(1187) }, // 24.92, 121.2 x 25.76, 122
    { 157815, Bucket(1192) }, // 29.96, 119.5 x 30.8, 120.3
    { 157816, Bucket(1197) }, // 27.44, 120.3 x 28.28, 121.2
    { 157822, Bucket(1200) }, // 29.12, 121.2 x 29.96, 122
    { 157961, Bucket(1205) }, // 31.63, 117 x 32.47, 117.8
    { 157963, 992 }, // 31.63, 117.8 x 32.47, 118.6
    { 157985, Bucket(1208) }, // 31.63, 118.6 x 32.47, 119.5
    { 157992, 2787 }, // 30.8, 120.3 x 31.63, 121.2
    { 157994, Bucket(1214) }, // 30.8, 121.2 x 31.63, 122
    { 158012, 2455 }, // 35.83, 120.3 x 36.67, 121.2
    { 158022, Bucket(1230) }, // 39.18, 116.1 x 40.02, 117
    { 158025, Bucket(1241) }, // 38.35, 117 x 39.18, 117.8
    { 158028, 2057 }, // 39.18, 117 x 40.02, 117.8
    { 158059, Bucket(1244) }, // 38.35, 121.2 x 39.18, 122
    { 158135, Bucket(1247) }, // 36.67, 126.2 x 37.51, 127
    { 158140, 1727 }, // 35.83, 127 x 36.67, 127.9
    { 158141, Bucket(1251) }, // 36.67, 127 x 37.51, 127.9
    { 158163, 1825 }, // 41.7, 122.8 x 42.54, 123.7
    { 158175, Bucket(1254) }, // 43.38, 124.5 x 44.22, 125.3
    { 158177, 1681 }, // 38.35, 125.3 x 39.18, 126.2
    { 158178, Bucket(1247) }, // 37.51, 126.2 x 38.35, 127
    { 158184, Bucket(1258) }, // 37.51, 127 x 38.35, 127.9
    { 158197, Bucket(1255) }, // 43.38, 125.3 x 44.22, 126.2
    { 158481, Bucket(1261) }, // 34.99, 128.7 x 35.83, 129.5
    { 158512, 406 }, // 34.15, 132.1 x 34.99, 132.9
    { 158520, Bucket(1264) }, // 34.15, 133.7 x 34.99, 134.6
    { 158608, Bucket(1267) }, // 34.15, 135.4 x 34.99, 136.3
    { 158643, Bucket(1270) }, // 34.99, 139.6 x 35.83, 140.4
    { 158646, 2033 }, // 35.83, 139.6 x 36.67, 140.4
    { 158696, 1647 }, // 37.51, 140.4 x 38.35, 141.3
    { 158718, 2667 }, // 42.54, 141.3 x 43.38, 142.1
    { 158883, Bucket(1275) }, // 45.06, 126.2 x 45.9, 127
    { 165214, Bucket(1278) }, // -37.99, 144.6 x -37.15, 145.5
    { 168076, 2270 }, // -34.64, 150.5 x -33.8, 151.4
    { 49148, 1472 }, // -37.15, -73.46 x -36.73, -73.05
    { 64751, 1629 }, // 8.566, -79.76 x 8.986, -79.34
    { 64762, 1629 }, // 8.986, -79.76 x 9.405, -79.34
    { 99549, Bucket(1289) }, // 37.09, -122.1 x 37.51, -121.7
    { 99714, Bucket(1293) }, // 37.51, -122.5 x 37.93, -122.1
    { 99721, 1990 }, // 37.93, -122.1 x 38.35, -121.7
    { 99726, Bucket(1296) }, // 38.35, -121.7 x 38.77, -121.3
    { 99748, 2135 }, // 38.35, -121.3 x 38.77, -120.9
    { 99891, 2737 }, // 32.89, -117.5 x 33.31, -117.1
    { 99895, 2929 }, // 33.73, -117.5 x 34.15, -117.1
    { 101661, Bucket(1299) }, // 40.44, -112.1 x 40.86, -111.6
    { 102169, Bucket(1302) }, // 39.6, -105.3 x 40.02, -104.9
    { 102511, 1343 }, // 48.83, -123.4 x 49.25, -123
    { 102522, 1343 }, // 49.25, -123.4 x 49.67, -123
    { 102533, 163 }, // 45.48, -123 x 45.9, -122.5
    { 102551, 1285 }, // 47.15, -122.5 x 47.57, -122.1
    { 102594, Bucket(1307) }, // 47.57, -122.5 x 47.99, -122.1
    { 103356, Bucket(1311) }, // 53.45, -113.7 x 53.86, -113.3
    { 106512, 1087 }, // 19.05, -99.47 x 19.47, -99.05
    { 106963, Bucket(1314) }, // 29.54, -95.69 x 29.96, -95.28
    { 108494, 815 }, // 41.7, -88.14 x 42.12, -87.73
    { 108516, Bucket(1318) }, // 41.7, -87.73 x 42.12, -87.31
    { 109796, 2361 }, // 34.99, -81.01 x 35.41, -80.59
    { 110025, Bucket(1323) }, // 41.28, -81.85 x 41.7, -81.43
    { 110078, 2508 }, // 43.38, -79.76 x 43.8, -79.34
    { 110206, 1219 }, // 36.67, -76.4 x 37.09, -75.98
    { 110375, Bucket(1327) }, // 38.77, -77.24 x 39.18, -76.82
    { 110392, Bucket(1332) }, // 39.18, -76.82 x 39.6, -76.4
    { 110483, Bucket(1335) }, // 39.6, -75.56 x 40.02, -75.14
    { 110486, 1885 }, // 40.02, -75.56 x 40.44, -75.14
    { 110517, Bucket(1339) }, // 40.44, -74.3 x 40.86, -73.88
    { 110519, 2321 }, // 40.44, -73.88 x 40.86, -73.46
    { 110560, Bucket(1352) }, // 40.86, -74.3 x 41.28, -73.88
    { 112810, 2515 }, // 44.22, -79.76 x 44.64, -79.34
    { 113319, 2156 }, // 45.48, -73.88 x 45.9, -73.46
    { 136649, 1276 }, // -39.25, -68.43 x -38.83, -68.01
    { 147508, Bucket(1356) }, // -33.8, -70.95 x -33.38, -70.53
    { 148047, 249 }, // -31.7, -64.66 x -31.28, -64.24
    { 148058, 249 }, // -31.28, -64.66 x -30.86, -64.24
    { 149522, Bucket(1359) }, // -34.64, -58.78 x -34.22, -58.37
    { 149777, 456 }, // -27.5, -59.2 x -27.09, -58.78
    { 150518, Bucket(1362) }, // -23.73, -47.04 x -23.31, -46.62
    { 150524, Bucket(1366) }, // -23.73, -46.62 x -23.31, -46.2
    { 151432, 1661 }, // -16.18, -48.3 x -15.76, -47.88
    { 152823, Bucket(1370) }, // 10.24, -67.17 x 10.66, -66.75
    { 156712, 2351 }, // -22.89, -43.27 x -22.47, -42.85
    { 157463, 1776 }, // -13.24, -38.65 x -12.82, -38.23
    { 160339, 1381 }, // -4.017, -38.65 x -3.597, -38.23
    { 160450, 2966 }, // -6.114, -35.3 x -5.694, -34.88
    { 188152, 2046 }, // 8.986, 7.066 x 9.405, 7.485
    { 196652, 1663 }, // 18.21, -70.11 x 18.63, -69.69
    { 196782, 1215 }, // 18.21, -66.33 x 18.63, -65.91
    { 197967, Bucket(1374) }, // 42.12, -71.37 x 42.54, -70.95
    { 197989, 388 }, // 42.12, -70.95 x 42.54, -70.53
    { 231161, 2933 }, // 36.25, -6.356 x 36.67, -5.936
    { 231165, 2592 }, // 37.09, -6.356 x 37.51, -5.936
    { 231214, 2457 }, // 38.35, -9.292 x 38.77, -8.872
    { 231300, 2457 }, // 38.35, -8.872 x 38.77, -8.453
    { 231317, 1904 }, // 40.44, -8.872 x 40.86, -8.453
    { 231360, Bucket(1383) }, // 40.86, -8.872 x 41.28, -8.453
    { 232540, 1706 }, // 36.67, -4.678 x 37.09, -4.259
    { 232565, 1510 }, // 37.09, -3.839 x 37.51, -3.42
    { 232735, 2122 }, // 40.44, -4.259 x 40.86, -3.839
    { 232757, 1746 }, // 40.44, -3.839 x 40.86, -3.42
    { 232913, Bucket(1387) }, // 42.96, -2.162 x 43.38, -1.742
    { 232938, 1339 }, // 40.86, 0.7745 x 41.28, 1.194
    { 233076, 1592 }, // 36.67, 2.872 x 37.09, 3.291
    { 233242, Bucket(1390) }, // 39.18, 2.452 x 39.6, 2.872
    { 233243, Bucket(1390) }, // 39.6, 2.452 x 40.02, 2.872
    { 233280, 1339 }, // 40.86, 1.194 x 41.28, 1.613
    { 233289, Bucket(1393) }, // 41.28, 2.033 x 41.7, 2.452
    { 233300, Bucket(1397) }, // 43.38, 1.194 x 43.8, 1.613
    { 233317, Bucket(1402) }, // 42.12, 2.872 x 42.54, 3.291
    { 233328, Bucket(1402) }, // 42.54, 2.872 x 42.96, 3.291
    { 233340, Bucket(1406) }, // 43.38, 3.711 x 43.8, 4.13
    { 233468, 2679 }, // 43.38, 7.066 x 43.8, 7.485
    { 234425, 1488 }, // 53.03, -6.356 x 53.45, -5.936
    { 235593, 2477 }, // 47.99, -4.678 x 48.41, -4.259
    { 235596, 2477 }, // 48.41, -4.678 x 48.83, -4.259
    { 235659, Bucket(1411) }, // 44.64, -0.9032 x 45.06, -0.4838
    { 235671, Bucket(1416) }, // 47.15, -1.742 x 47.57, -1.323
    { 235709, 944 }, // 47.15, 0.3551 x 47.57, 0.7745
    { 235714, 1093 }, // 47.57, -1.742 x 47.99, -1.323
    { 235762, 1038 }, // 49.25, -0.06436 x 49.67, 0.3551
    { 235909, 209 }, // 52.19, -2.162 x 52.61, -1.742
    { 235937, Bucket(1419) }, // 51.35, -0.4838 x 51.77, -0.06436
    { 235971, Bucket(1423) }, // 54.7, -1.742 x 55.12, -1.323
    { 236108, Bucket(1426) }, // 48.41, 2.033 x 48.83, 2.452
    { 236109, Bucket(1429) }, // 48.83, 2.033 x 49.25, 2.452
    { 236149, Bucket(1432) }, // 50.51, 2.872 x 50.93, 3.291
    { 236150, 1588 }, // 50.09, 3.291 x 50.51, 3.711
    { 236158, 1086 }, // 50.09, 4.13 x 50.51, 4.549
    { 236159, Bucket(1437) }, // 50.51, 4.13 x 50.93, 4.549
    { 236165, Bucket(1456) }, // 45.48, 4.549 x 45.9, 4.969
    { 236183, 521 }, // 47.15, 4.969 x 47.57, 5.388
    { 236186, Bucket(1459) }, // 45.9, 5.808 x 46.31, 6.227
    { 236191, Bucket(1462) }, // 47.15, 5.808 x 47.57, 6.227
    { 236209, 2731 }, // 46.31, 6.227 x 46.73, 6.647
    { 236214, 2960 }, // 46.73, 6.647 x 47.15, 7.066
    { 236220, Bucket(1465) }, // 46.73, 7.066 x 47.15, 7.485
    { 236221, 2395 }, // 47.15, 7.066 x 47.57, 7.485
    { 236222, Bucket(1476) }, // 46.73, 7.485 x 47.15, 7.905
    { 236223, Bucket(1482) }, // 47.15, 7.485 x 47.57, 7.905
    { 236245, Bucket(1490) }, // 50.51, 4.549 x 50.93, 4.969
    { 236264, 1494 }, // 47.57, 7.066 x 47.99, 7.485
    { 236266, Bucket(1494) }, // 47.57, 7.485 x 47.99, 7.905
    { 236270, Bucket(1497) }, // 48.41, 7.485 x 48.83, 7.905
    { 236279, Bucket(1501) }, // 50.51, 6.647 x 50.93, 7.066
    { 236282, 686 }, // 49.25, 7.485 x 49.67, 7.905
    { 236285, Bucket(1504) }, // 50.51, 7.066 x 50.93, 7.485
    { 236328, 2953 }, // 50.93, 3.711 x 51.35, 4.13
    { 236330, Bucket(1510) }, // 50.93, 4.13 x 51.35, 4.549
    { 236334, Bucket(1513) }, // 51.77, 4.13 x 52.19, 4.549
    { 236420, 1351 }, // 51.77, 4.549 x 52.19, 4.969
    { 236421, 2047 }, // 52.19, 4.549 x 52.61, 4.969
    { 236422, Bucket(1523) }, // 51.77, 4.969 x 52.19, 5.388
    { 236450, Bucket(1526) }, // 50.93, 6.647 x 51.35, 7.066
    { 236451, 371 }, // 51.35, 6.647 x 51.77, 7.066
    { 236457, Bucket(1531) }, // 51.35, 7.066 x 51.77, 7.485
    { 237206, Bucket(1537) }, // 60.16, 4.969 x 60.58, 5.388
    { 238710, Bucket(1540) }, // 36.67, 10 x 37.09, 10.42
    { 239039, Bucket(1545) }, // 40.44, 14.2 x 40.86, 14.62
    { 239052, 2837 }, // 41.7, 12.1 x 42.12, 12.52
    { 239054, 2837 }, // 41.7, 12.52 x 42.12, 12.94
    { 239082, Bucket(1550) }, // 40.86, 14.2 x 41.28, 14.62
    { 241276, Bucket(1553) }, // 36.67, 30.55 x 37.09, 30.97
    { 241436, 1779 }, // 40.02, 28.88 x 40.44, 29.3
    { 241474, Bucket(1556) }, // 40.86, 28.46 x 41.28, 28.88
    { 241480, Bucket(1560) }, // 40.86, 28.88 x 41.28, 29.3
    { 241563, Bucket(1569) }, // 39.6, 32.65 x 40.02, 33.07
    { 241672, 811 }, // 44.22, 8.744 x 44.64, 9.163
    { 241677, Bucket(1572) }, // 45.48, 8.744 x 45.9, 9.163
    { 241679, Bucket(1576) }, // 45.48, 9.163 x 45.9, 9.583
    { 241682, 2910 }, // 45.9, 8.324 x 46.31, 8.744
    { 241684, Bucket(1579) }, // 46.73, 7.905 x 47.15, 8.324
    { 241685, Bucket(1585) }, // 47.15, 7.905 x 47.57, 8.324
    { 241686, Bucket(1594) }, // 46.73, 8.324 x 47.15, 8.744
    { 241687, Bucket(1598) }, // 47.15, 8.324 x 47.57, 8.744
    { 241688, Bucket(1624) }, // 45.9, 8.744 x 46.31, 9.163
    { 241692, Bucket(1628) }, // 46.73, 8.744 x 47.15, 9.163
    { 241693, Bucket(1631) }, // 47.15, 8.744 x 47.57, 9.163
    { 241694, Bucket(1640) }, // 46.73, 9.163 x 47.15, 9.583
    { 241695, Bucket(1643) }, // 47.15, 9.163 x 47.57, 9.583
    { 241701, 2954 }, // 45.48, 9.583 x 45.9, 10
    { 241717, Bucket(1654) }, // 47.15, 9.583 x 47.57, 10
    { 241727, Bucket(1657) }, // 47.15, 10.84 x 47.57, 11.26
    { 241730, 463 }, // 47.57, 8.324 x 47.99, 8.744
    { 241733, 1123 }, // 48.83, 7.905 x 49.25, 8.324
    { 241735, Bucket(1661) }, // 48.83, 8.324 x 49.25, 8.744
    { 241736, 460 }, // 47.57, 8.744 x 47.99, 9.163
    { 241742, 153 }, // 48.41, 9.163 x 48.83, 9.583
    { 241744, Bucket(1673) }, // 49.25, 7.905 x 49.67, 8.324
    { 241746, Bucket(1676) }, // 49.25, 8.324 x 49.67, 8.744
    { 241747, Bucket(1688) }, // 49.67, 8.324 x 50.09, 8.744
    { 241750, Bucket(1693) }, // 50.09, 8.324 x 50.51, 8.744
    { 241752, Bucket(1672) }, // 49.25, 8.744 x 49.67, 9.163
    { 241754, 685 }, // 49.25, 9.163 x 49.67, 9.583
    { 241756, 540 }, // 50.09, 8.744 x 50.51, 9.163
    { 241771, Bucket(1697) }, // 47.99, 10.84 x 48.41, 11.26
    { 241775, 179 }, // 48.83, 10.84 x 49.25, 11.26
    { 241786, Bucket(1702) }, // 49.25, 10.84 x 49.67, 11.26
    { 241789, 710 }, // 50.51, 10.42 x 50.93, 10.84
    { 241798, 273 }, // 45.06, 11.68 x 45.48, 12.1
    { 241804, 1284 }, // 45.06, 12.1 x 45.48, 12.52
    { 241805, 1284 }, // 45.48, 12.1 x 45.9, 12.52
    { 241813, 1085 }, // 47.15, 11.26 x 47.57, 11.68
    { 241823, 1978 }, // 47.15, 12.52 x 47.57, 12.94
    { 241845, 1978 }, // 47.15, 12.94 x 47.57, 13.36
    { 241849, 2895 }, // 46.31, 13.78 x 46.73, 14.2
    { 241855, 2252 }, // 47.15, 14.2 x 47.57, 14.62
    { 241856, 2642 }, // 47.57, 11.26 x 47.99, 11.68
    { 241857, Bucket(1710) }, // 47.99, 11.26 x 48.41, 11.68
    { 241858, 2642 }, // 47.57, 11.68 x 47.99, 12.1
    { 241859, 104 }, // 47.99, 11.68 x 48.41, 12.1
    { 241860, 1499 }, // 48.41, 11.26 x 48.83, 11.68
    { 241862, 1499 }, // 48.41, 11.68 x 48.83, 12.1
    { 241866, Bucket(1717) }, // 47.57, 12.52 x 47.99, 12.94
    { 241885, 653 }, // 50.51, 12.1 x 50.93, 12.52
    { 241887, Bucket(1720) }, // 50.51, 12.52 x 50.93, 12.94
    { 241888, Bucket(1716) }, // 47.57, 12.94 x 47.99, 13.36
    { 241899, Bucket(1725) }, // 47.99, 14.2 x 48.41, 14.62
    { 241909, Bucket(1722) }, // 50.51, 12.94 x 50.93, 13.36
    { 241915, Bucket(1728) }, // 49.67, 14.2 x 50.09, 14.62
    { 241918, Bucket(1738) }, // 50.09, 14.2 x 50.51, 14.62
    { 241926, Bucket(1744) }, // 51.77, 8.324 x 52.19, 8.744
    { 241935, 825 }, // 52.19, 9.163 x 52.61, 9.583
    { 241946, 825 }, // 52.61, 9.163 x 53.03, 9.583
    { 241950, 1294 }, // 53.45, 9.163 x 53.86, 9.583
    { 241957, Bucket(1748) }, // 52.19, 9.583 x 52.61, 10
    { 241960, 710 }, // 50.93, 10.42 x 51.35, 10.84
    { 241961, 111 }, // 51.35, 10.42 x 51.77, 10.84
    { 241962, Bucket(1763) }, // 50.93, 10.84 x 51.35, 11.26
    { 241972, 152 }, // 53.45, 9.583 x 53.86, 10
    { 242034, 2945 }, // 55.96, 10 x 56.38, 10.42
    { 242056, Bucket(1767) }, // 50.93, 12.1 x 51.35, 12.52
    { 242068, Bucket(1770) }, // 53.45, 11.26 x 53.86, 11.68
    { 242071, Bucket(1774) }, // 53.86, 11.68 x 54.28, 12.1
    { 242077, Bucket(1778) }, // 53.86, 12.1 x 54.28, 12.52
    { 242082, Bucket(1783) }, // 50.93, 13.36 x 51.35, 13.78
    { 242085, Bucket(1787) }, // 52.19, 12.94 x 52.61, 13.36
    { 242087, Bucket(1796) }, // 52.19, 13.36 x 52.61, 13.78
    { 242088, 1229 }, // 50.93, 13.78 x 51.35, 14.2
    { 242096, 978 }, // 52.61, 12.94 x 53.03, 13.36
    { 242198, 2570 }, // 46.73, 15.04 x 47.15, 15.45
    { 242199, 176 }, // 47.15, 15.04 x 47.57, 15.45
    { 242251, Bucket(1811) }, // 47.99, 15.87 x 48.41, 16.29
    { 242273, Bucket(1815) }, // 47.99, 16.29 x 48.41, 16.71
    { 242333, Bucket(1824) }, // 47.15, 18.81 x 47.57, 19.23
    { 242334, 1171 }, // 46.73, 19.23 x 47.15, 19.65
    { 242356, 1171 }, // 46.73, 19.65 x 47.15, 20.07
    { 242376, Bucket(1838) }, // 47.57, 18.81 x 47.99, 19.23
    { 242432, Bucket(1843) }, // 50.93, 14.62 x 51.35, 15.04
    { 242471, Bucket(1846) }, // 52.19, 16.71 x 52.61, 17.13
    { 242571, Bucket(1864) }, // 51.35, 19.23 x 51.77, 19.65
    { 242574, Bucket(1880) }, // 51.77, 19.23 x 52.19, 19.65
    { 242591, 600 }, // 53.86, 19.23 x 54.28, 19.65
    { 242626, 1331 }, // 54.28, 18.39 x 54.7, 18.81
    { 242745, Bucket(1894) }, // 59.74, 10.42 x 60.16, 10.84
    { 242818, Bucket(1901) }, // 57.64, 11.68 x 58.06, 12.1
    { 243333, 831 }, // 58.9, 17.97 x 59.32, 18.39
    { 243344, 1703 }, // 59.32, 17.97 x 59.74, 18.39
    { 243833, Bucket(1904) }, // 49.67, 23.84 x 50.09, 24.26
    { 243850, Bucket(1909) }, // 44.22, 25.94 x 44.64, 26.36
    { 244374, 2578 }, // 46.73, 31.81 x 47.15, 32.23
    { 244884, Bucket(1917) }, // 60.16, 24.68 x 60.58, 25.1
    { 245299, Bucket(1924) }, // 59.74, 30.13 x 60.16, 30.55
    { 545991, 1304 }, // 8.566, 38.52 x 8.986, 38.94
    { 546002, Bucket(1951) }, // 8.986, 38.52 x 9.405, 38.94
    { 556126, 1745 }, // 9.824, 76.27 x 10.24, 76.69
    { 556465, Bucket(1954) }, // 12.76, 80.05 x 13.18, 80.47
    { 578555, 2359 }, // 2.694, 101.4 x 3.114, 101.9
    { 578558, 2359 }, // 3.114, 101.4 x 3.533, 101.9
    { 579420, Bucket(1959) }, // 16.54, 95.99 x 16.95, 96.4
    { 579509, Bucket(1964) }, // 13.6, 100.2 x 14.02, 100.6
    { 579709, 2296 }, // -3.178, 104.4 x -2.758, 104.8
    { 579937, 2021 }, // 1.016, 103.5 x 1.436, 104
    { 581002, 2674 }, // 10.66, 106.5 x 11.08, 106.9
    { 581702, Bucket(1967) }, // -32.12, 115.7 x -31.7, 116.1
    { 584239, 2862 }, // -35.05, 138.3 x -34.64, 138.8
    { 584250, 2862 }, // -34.64, 138.3 x -34.22, 138.8
    { 587235, Bucket(1970) }, // 14.44, 120.7 x 14.86, 121.2
    { 590049, 1679 }, // 21.15, 39.78 x 21.57, 40.2
    { 590753, Bucket(1974) }, // 24.5, 46.49 x 24.92, 46.91
    { 591755, 1595 }, // 37.93, 46.07 x 38.35, 46.49
    { 592345, 1623 }, // 29.54, 52.36 x 29.96, 52.78
    { 593005, 2984 }, // 35.41, 50.69 x 35.83, 51.11
    { 593007, Bucket(1977) }, // 35.41, 51.11 x 35.83, 51.53
    { 593016, 2984 }, // 35.83, 50.69 x 36.25, 51.11
    { 593040, 1624 }, // 32.47, 51.53 x 32.89, 51.95
    { 593988, 1675 }, // 48.41, 34.75 x 48.83, 35.17
    { 594011, Bucket(1980) }, // 49.67, 36.01 x 50.09, 36.43
    { 594285, Bucket(1983) }, // 55.54, 37.26 x 55.96, 37.68
    { 594287, Bucket(1999) }, // 55.54, 37.68 x 55.96, 38.1
    { 596245, Bucket(2006) }, // 53.86, 48.17 x 54.28, 48.59
    { 596288, Bucket(2006) }, // 54.28, 48.17 x 54.7, 48.59
    { 596301, 1657 }, // 55.54, 49.01 x 55.96, 49.43
    { 596429, Bucket(2011) }, // 55.54, 52.36 x 55.96, 52.78
    { 598745, Bucket(2016) }, // 22.83, 72.5 x 23.25, 72.92
    { 599721, 2659 }, // 31.22, 74.17 x 31.63, 74.59
    { 600420, 1819 }, // 28.28, 76.69 x 28.7, 77.11
    { 600422, 1961 }, // 28.28, 77.11 x 28.7, 77.53
    { 600497, 2838 }, // 26.18, 80.05 x 26.6, 80.47
    { 600502, 2008 }, // 26.6, 80.47 x 27.02, 80.89
    { 600508, 2008 }, // 26.6, 80.89 x 27.02, 81.31
    { 600826, 1957 }, // 22.41, 88.02 x 22.83, 88.44
    { 601457, 1680 }, // 42.96, 76.69 x 43.38, 77.11
    { 624890, 2675 }, // 22.41, 108.1 x 22.83, 108.6
    { 624908, 812 }, // 24.92, 102.7 x 25.34, 103.1
    { 625015, Bucket(2019) }, // 30.38, 104 x 30.8, 104.4
    { 625051, 1684 }, // 26.18, 106.5 x 26.6, 106.9
    { 625054, 1684 }, // 26.6, 106.5 x 27.02, 106.9
    { 625112, 2899 }, // 29.12, 106.1 x 29.54, 106.5
    { 625115, 2235 }, // 29.54, 106.5 x 29.96, 106.9
    { 625371, Bucket(2025) }, // 22.83, 113.2 x 23.25, 113.6
    { 625383, Bucket(2030) }, // 21.99, 114 x 22.41, 114.4
    { 625392, 2943 }, // 22.41, 113.6 x 22.83, 114
    { 625393, Bucket(2034) }, // 22.83, 113.6 x 23.25, 114
    { 625394, Bucket(2037) }, // 22.41, 114 x 22.83, 114.4
    { 625609, Bucket(2044) }, // 27.86, 112.8 x 28.28, 113.2
    { 625655, Bucket(2048) }, // 30.38, 114 x 30.8, 114.4
    { 625776, Bucket(2055) }, // 35.83, 103.5 x 36.25, 104
    { 626240, 1780 }, // 34.15, 108.6 x 34.57, 109
    { 626242, 2775 }, // 34.15, 109 x 34.57, 109.4
    { 626338, 2240 }, // 30.8, 114 x 31.22, 114.4
    { 626379, Bucket(2058) }, // 34.57, 113.2 x 34.99, 113.6
    { 626401, Bucket(2063) }, // 34.57, 113.6 x 34.99, 114
    { 626495, Bucket(2069) }, // 40.44, 111.5 x 40.86, 111.9
    { 626538, 2636 }, // 40.86, 111.5 x 41.28, 111.9
    { 626562, 2888 }, // 37.51, 112.3 x 37.93, 112.8
    { 631002, Bucket(2072) }, // 22.41, 119.9 x 22.83, 120.3
    { 631024, Bucket(2072) }, // 22.41, 120.3 x 22.83, 120.7
    { 631110, Bucket(2075) }, // 28.28, 115.7 x 28.7, 116.1
    { 631144, 2940 }, // 27.44, 117.8 x 27.86, 118.2
    { 631186, Bucket(2078) }, // 25.76, 119.1 x 26.18, 119.5
    { 631212, 1486 }, // 24.92, 121.2 x 25.34, 121.6
    { 631262, Bucket(2081) }, // 29.96, 119.9 x 30.38, 120.3
    { 631276, 2957 }, // 28.28, 121.2 x 28.7, 121.6
    { 631281, 2768 }, // 29.54, 120.3 x 29.96, 120.7
    { 631284, Bucket(2086) }, // 29.96, 120.3 x 30.38, 120.7
    { 631293, 1926 }, // 30.38, 121.2 x 30.8, 121.6
    { 631844, Bucket(2089) }, // 31.63, 117 x 32.05, 117.4
    { 631904, Bucket(2093) }, // 34.15, 117 x 34.57, 117.4
    { 631940, 1833 }, // 31.63, 118.6 x 32.05, 119.1
    { 631941, Bucket(2096) }, // 32.05, 118.6 x 32.47, 119.1
    { 631971, 2043 }, // 31.22, 120.7 x 31.63, 121.2
    { 631974, 2936 }, // 31.63, 120.7 x 32.05, 121.2
    { 631975, 2936 }, // 32.05, 120.7 x 32.47, 121.2
    { 631976, Bucket(2100) }, // 30.8, 121.2 x 31.22, 121.6
    { 632048, 2955 }, // 35.83, 120.3 x 36.25, 120.7
    { 632089, Bucket(2103) }, // 39.6, 116.1 x 40.02, 116.5
    { 632092, 298 }, // 40.02, 116.1 x 40.44, 116.5
    { 632101, Bucket(2110) }, // 38.77, 117 x 39.18, 117.4
    { 632112, Bucket(2112) }, // 39.18, 117 x 39.6, 117.4
    { 632239, Bucket(2116) }, // 38.77, 121.6 x 39.18, 122
    { 632250, 2844 }, // 39.18, 121.6 x 39.6, 122
    { 632526, 2829 }, // 34.99, 126.6 x 35.41, 127
    { 632543, 1645 }, // 37.09, 126.6 x 37.51, 127
    { 632559, 1769 }, // 35.41, 128.3 x 35.83, 128.7
    { 632565, 1645 }, // 37.09, 127 x 37.51, 127.4
    { 632570, Bucket(2120) }, // 35.83, 128.3 x 36.25, 128.7
    { 632581, 1830 }, // 38.77, 122 x 39.18, 122.4
    { 632651, Bucket(2123) }, // 41.28, 123.2 x 41.7, 123.7
    { 632654, Bucket(2126) }, // 41.7, 123.2 x 42.12, 123.7
    { 633924, Bucket(2132) }, // 34.99, 128.7 x 35.41, 129.1
    { 634080, 2564 }, // 34.15, 133.7 x 34.57, 134.2
    { 634433, 2396 }, // 34.57, 135.4 x 34.99, 135.8
    { 634446, Bucket(2136) }, // 34.99, 136.7 x 35.41, 137.1
    { 634450, 2404 }, // 35.83, 135.8 x 36.25, 136.3
    { 634573, Bucket(2140) }, // 35.41, 139.6 x 35.83, 140
    { 635535, 1877 }, // 45.48, 126.6 x 45.9, 127
    { 660847, 845 }, // -38.41, 145.1 x -37.99, 145.5
    { 660856, Bucket(2151) }, // -37.99, 144.6 x -37.57, 145.1
    { 669174, 11 }, // -37.15, 174.4 x -36.73, 174.8
    { 669180, 11 }, // -37.15, 174.8 x -36.73, 175.3
    { 672260, 2398 }, // -35.47, 148.8 x -35.05, 149.3
    { 672307, 2265 }, // -34.22, 150.9 x -33.8, 151.4
    { 259050, 2186 }, // 8.986, -79.55 x 9.195, -79.34
    { 398857, Bucket(2162) }, // 37.72, -122.5 x 37.93, -122.3
    { 399485, 1857 }, // 33.94, -118.3 x 34.15, -118.1
    { 403703, Bucket(2169) }, // 20.52, -103.5 x 20.73, -103.2
    { 403874, 2629 }, // 20.73, -103.5 x 20.94, -103.2
    { 405616, 2091 }, // 33.31, -112.1 x 33.52, -111.8
    { 406645, 1377 }, // 40.65, -112.1 x 40.86, -111.8
    { 410047, Bucket(2173) }, // 49.04, -123.2 x 49.25, -123
    { 410090, Bucket(2173) }, // 49.25, -123.2 x 49.46, -123
    { 410134, 162 }, // 45.48, -122.7 x 45.69, -122.5
    { 410389, Bucket(2173) }, // 49.04, -123 x 49.25, -122.7
    { 410432, Bucket(2173) }, // 49.25, -123 x 49.46, -122.7
    { 426051, Bucket(2176) }, // 19.26, -99.26 x 19.47, -99.05
    { 426054, 1868 }, // 19.47, -99.26 x 19.68, -99.05
    { 430305, 842 }, // 32.68, -96.95 x 32.89, -96.74
    { 433978, Bucket(2181) }, // 41.7, -87.94 x 41.91, -87.73
    { 434064, Bucket(2181) }, // 41.7, -87.73 x 41.91, -87.52
    { 435871, Bucket(2184) }, // 25.55, -80.39 x 25.76, -80.18
    { 435914, Bucket(2184) }, // 25.76, -80.39 x 25.97, -80.18
    { 438484, 1134 }, // 33.73, -84.37 x 33.94, -84.16
    { 440280, 2603 }, // 43.38, -80.59 x 43.59, -80.39
    { 440315, Bucket(2187) }, // 43.59, -79.55 x 43.8, -79.34
    { 441681, 1814 }, // 43.59, -79.34 x 43.8, -79.13
    { 441935, Bucket(2190) }, // 39.81, -75.35 x 40.02, -75.14
    { 441957, 1882 }, // 39.81, -75.14 x 40.02, -74.93
    { 442069, 2319 }, // 40.65, -74.3 x 40.86, -74.09
    { 442071, Bucket(2197) }, // 40.65, -74.09 x 40.86, -73.88
    { 442242, Bucket(2203) }, // 40.86, -74.09 x 41.07, -73.88
    { 443047, 669 }, // 44.85, -93.39 x 45.06, -93.18
    { 453139, 2367 }, // 45.27, -75.77 x 45.48, -75.56
    { 590035, Bucket(2206) }, // -33.59, -70.74 x -33.38, -70.53
    { 592277, 249 }, // -31.49, -64.24 x -31.28, -64.03
    { 592320, 249 }, // -31.28, -64.24 x -31.07, -64.03
    { 594924, 2904 }, // -17.44, -66.33 x -17.23, -66.12
    { 598090, Bucket(2211) }, // -34.64, -58.57 x -34.43, -58.37
    { 602074, Bucket(2214) }, // -23.73, -46.83 x -23.52, -46.62
    { 605731, 1662 }, // -15.97, -48.09 x -15.76, -47.88
    { 611292, 1976 }, // 10.24, -67.17 x 10.45, -66.96
    { 611295, 2813 }, // 10.45, -66.96 x 10.66, -66.75
    { 624095, 1418 }, // -23.1, -43.48 x -22.89, -43.27
    { 624117, 1418 }, // -23.1, -43.27 x -22.89, -43.06
    { 626849, 2346 }, // -22.68, -43.27 x -22.47, -43.06
    { 626900, 1379 }, // -19.96, -44.1 x -19.75, -43.89
    { 629853, 1452 }, // -13.03, -38.65 x -12.82, -38.44
    { 630271, 2751 }, // -9.679, -35.93 x -9.469, -35.72
    { 639724, 2491 }, // -7.372, -39.49 x -7.162, -39.28
    { 641357, 2352 }, // -3.807, -38.65 x -3.597, -38.44
    { 641566, Bucket(2217) }, // -8.211, -35.09 x -8.001, -34.88
    { 641615, 2493 }, // -7.162, -35.09 x -6.953, -34.88
    { 641637, 2493 }, // -7.162, -34.88 x -6.953, -34.67
    { 742703, 2845 }, // 14.65, -17.47 x 14.86, -17.26
    { 742789, 2845 }, // 14.65, -17.26 x 14.86, -17.05
    { 752610, 2187 }, // 8.986, 7.276 x 9.195, 7.485
    { 786609, 1664 }, // 18.42, -70.11 x 18.63, -69.9
    { 791871, 1094 }, // 42.33, -71.16 x 42.54, -70.95
    { 918960, 90 }, // 28.28, -16.42 x 28.49, -16.21
    { 924375, 1266 }, // 33.94, -6.985 x 34.15, -6.775
    { 924663, Bucket(2222) }, // 37.3, -6.146 x 37.51, -5.936
    { 924669, 2591 }, // 37.3, -5.936 x 37.51, -5.727
    { 924857, Bucket(2225) }, // 38.56, -9.292 x 38.77, -9.082
    { 925443, Bucket(2232) }, // 41.07, -8.663 x 41.28, -8.453
    { 930760, 2983 }, // 35.83, -0.06436 x 36.04, 0.1454
    { 930939, Bucket(2236) }, // 40.23, -4.049 x 40.44, -3.839
    { 931025, Bucket(2239) }, // 40.23, -3.839 x 40.44, -3.63
    { 931028, 1762 }, // 40.44, -3.839 x 40.65, -3.63
    { 931279, Bucket(2244) }, // 43.17, -3.21 x 43.38, -3
    { 931299, Bucket(2248) }, // 42.75, -2.791 x 42.96, -2.581
    { 931301, Bucket(2251) }, // 43.17, -3 x 43.38, -2.791
    { 931364, 2749 }, // 37.93, -1.323 x 38.14, -1.113
    { 931435, 1297 }, // 39.39, -0.6935 x 39.6, -0.4838
    { 931521, Bucket(2256) }, // 39.39, -0.4838 x 39.6, -0.2741
    { 932306, Bucket(2262) }, // 36.67, 3.081 x 36.88, 3.291
    { 932379, 2792 }, // 31.84, 5.179 x 32.05, 5.388
    { 933134, Bucket(2265) }, // 41.28, 1.823 x 41.49, 2.033
    { 933156, Bucket(2268) }, // 41.28, 2.033 x 41.49, 2.243
    { 933711, 212 }, // 43.17, 5.179 x 43.38, 5.388
    { 933733, 212 }, // 43.17, 5.388 x 43.38, 5.598
    { 933873, 2400 }, // 43.59, 7.066 x 43.8, 7.276
    { 942684, 605 }, // 47.15, -1.742 x 47.36, -1.532
    { 942719, 966 }, // 47.36, -0.6935 x 47.57, -0.4838
    { 942860, Bucket(2282) }, // 47.99, -1.742 x 48.2, -1.532
    { 943082, 778 }, // 49.25, 0.9842 x 49.46, 1.194
    { 943343, Bucket(2288) }, // 53.24, -2.371 x 53.45, -2.162
    { 943354, Bucket(2285) }, // 53.45, -2.371 x 53.65, -2.162
    { 943415, 1674 }, // 55.75, -4.468 x 55.96, -4.259
    { 943421, 1674 }, // 55.75, -4.259 x 55.96, -4.049
    { 943695, Bucket(2291) }, // 53.24, -1.532 x 53.45, -1.323
    { 943713, 566 }, // 52.82, -1.323 x 53.03, -1.113
    { 943750, 1602 }, // 51.35, -0.2741 x 51.56, -0.06436
    { 943756, Bucket(2296) }, // 51.35, -0.06436 x 51.56, 0.1454
    { 943757, 190 }, // 51.56, -0.06436 x 51.77, 0.1454
    { 943759, 2302 }, // 51.56, 0.1454 x 51.77, 0.3551
    { 944279, 2162 }, // 45.69, 3.081 x 45.9, 3.291
    { 944395, Bucket(2299) }, // 47.78, 1.823 x 47.99, 2.033
    { 944435, Bucket(2302) }, // 48.62, 2.243 x 48.83, 2.452
    { 944438, Bucket(2305) }, // 48.83, 2.243 x 49.04, 2.452
    { 944444, Bucket(2316) }, // 48.83, 2.452 x 49.04, 2.662
    { 944603, 2108 }, // 50.3, 3.501 x 50.51, 3.711
    { 944635, Bucket(2319) }, // 50.3, 4.34 x 50.51, 4.549
    { 944639, Bucket(2322) }, // 50.72, 4.34 x 50.93, 4.549
    { 944663, Bucket(2328) }, // 45.69, 4.759 x 45.9, 4.969
    { 944690, Bucket(2335) }, // 45.06, 5.598 x 45.27, 5.808
    { 944732, 522 }, // 47.15, 4.969 x 47.36, 5.179
    { 944747, Bucket(2340) }, // 46.11, 6.017 x 46.31, 6.227
    { 944750, 292 }, // 46.31, 6.017 x 46.52, 6.227
    { 944836, 292 }, // 46.31, 6.227 x 46.52, 6.437
    { 944891, 185 }, // 46.94, 7.695 x 47.15, 7.905
    { 944893, Bucket(2344) }, // 47.36, 7.485 x 47.57, 7.695
    { 944894, Bucket(2358) }, // 47.15, 7.695 x 47.36, 7.905
    { 944895, Bucket(2361) }, // 47.36, 7.695 x 47.57, 7.905
    { 945003, 1690 }, // 49.46, 6.017 x 49.67, 6.227
    { 945064, Bucket(2364) }, // 47.57, 7.485 x 47.78, 7.695
    { 945067, Bucket(2372) }, // 47.78, 7.695 x 47.99, 7.905
    { 945070, Bucket(2372) }, // 47.99, 7.695 x 48.2, 7.905
    { 945119, Bucket(2375) }, // 50.72, 6.856 x 50.93, 7.066
    { 945290, Bucket(2379) }, // 50.93, 3.501 x 51.14, 3.711
    { 945312, Bucket(2379) }, // 50.93, 3.711 x 51.14, 3.92
    { 945323, Bucket(2383) }, // 51.14, 4.34 x 51.35, 4.549
    { 945337, Bucket(2395) }, // 51.98, 4.13 x 52.19, 4.34
    { 945338, Bucket(2402) }, // 51.77, 4.34 x 51.98, 4.549
    { 945339, Bucket(2409) }, // 51.98, 4.34 x 52.19, 4.549
    { 945680, 1352 }, // 51.77, 4.549 x 51.98, 4.759
    { 945686, Bucket(2413) }, // 52.19, 4.759 x 52.4, 4.969
    { 945801, Bucket(2422) }, // 51.14, 6.647 x 51.35, 6.856
    { 945802, Bucket(2427) }, // 50.93, 6.856 x 51.14, 7.066
    { 945806, Bucket(2432) }, // 51.35, 6.856 x 51.56, 7.066
    { 945828, Bucket(2436) }, // 51.35, 7.066 x 51.56, 7.276
    { 945830, Bucket(2440) }, // 51.35, 7.276 x 51.56, 7.485
    { 954840, Bucket(2443) }, // 36.67, 10 x 36.88, 10.21
    { 956157, Bucket(2446) }, // 40.65, 14.2 x 40.86, 14.41
    { 956328, Bucket(2449) }, // 40.86, 14.2 x 41.07, 14.41
    { 957833, 933 }, // 41.07, 16.71 x 41.28, 16.92
    { 962042, Bucket(2452) }, // 29.96, 31.18 x 30.17, 31.39
    { 962384, 1611 }, // 29.96, 31.39 x 30.17, 31.6
    { 963591, Bucket(2455) }, // 38.14, 21.54 x 38.35, 21.75
    { 963597, 2640 }, // 38.14, 21.75 x 38.35, 21.96
    { 963726, 1887 }, // 37.93, 23.63 x 38.14, 23.84
    { 964034, Bucket(2458) }, // 42.54, 23.21 x 42.75, 23.42
    { 964250, Bucket(2463) }, // 38.35, 26.99 x 38.56, 27.2
    { 964272, 1900 }, // 38.35, 27.2 x 38.56, 27.41
    { 965105, 2661 }, // 36.88, 30.55 x 37.09, 30.76
    { 965920, 902 }, // 40.86, 28.88 x 41.07, 29.09
    { 966253, Bucket(2467) }, // 39.81, 32.65 x 40.02, 32.86
    { 966713, 2941 }, // 45.27, 9.163 x 45.48, 9.373
    { 966737, 185 }, // 46.94, 7.905 x 47.15, 8.115
    { 966739, 2534 }, // 46.94, 8.115 x 47.15, 8.324
    { 966740, Bucket(2358) }, // 47.15, 7.905 x 47.36, 8.115
    { 966741, 2394 }, // 47.36, 7.905 x 47.57, 8.115
    { 966742, 458 }, // 47.15, 8.115 x 47.36, 8.324
    { 966743, 459 }, // 47.36, 8.115 x 47.57, 8.324
    { 966745, Bucket(2470) }, // 46.94, 8.324 x 47.15, 8.534
    { 966748, Bucket(2470) }, // 47.15, 8.324 x 47.36, 8.534
    { 966749, Bucket(2473) }, // 47.36, 8.324 x 47.57, 8.534
    { 966750, 2031 }, // 47.15, 8.534 x 47.36, 8.744
    { 966751, Bucket(2476) }, // 47.36, 8.534 x 47.57, 8.744
    { 966752, 2911 }, // 45.9, 8.744 x 46.11, 8.953
    { 966767, 3018 }, // 46.52, 9.373 x 46.73, 9.583
    { 966772, Bucket(2482) }, // 47.15, 8.744 x 47.36, 8.953
    { 966773, Bucket(2487) }, // 47.36, 8.744 x 47.57, 8.953
    { 966775, Bucket(2492) }, // 47.36, 8.953 x 47.57, 9.163
    { 966778, 3018 }, // 46.73, 9.373 x 46.94, 9.583
    { 966783, 2861 }, // 47.36, 9.373 x 47.57, 9.583
    { 966864, 3019 }, // 46.73, 9.583 x 46.94, 9.792
    { 966865, 987 }, // 46.94, 9.583 x 47.15, 9.792
    { 966867, 2569 }, // 46.94, 9.792 x 47.15, 10
    { 966868, 987 }, // 47.15, 9.583 x 47.36, 9.792
    { 966869, Bucket(2495) }, // 47.36, 9.583 x 47.57, 9.792
    { 966870, 2569 }, // 47.15, 9.792 x 47.36, 10
    { 966922, Bucket(2499) }, // 47.57, 8.534 x 47.78, 8.744
    { 966940, Bucket(2502) }, // 48.83, 8.324 x 49.04, 8.534
    { 966941, 1123 }, // 49.04, 8.324 x 49.25, 8.534
    { 966942, 1123 }, // 48.83, 8.534 x 49.04, 8.744
    { 966944, 2037 }, // 47.57, 8.744 x 47.78, 8.953
    { 966964, 657 }, // 48.83, 8.744 x 49.04, 8.953
    { 966965, Bucket(2508) }, // 49.04, 8.744 x 49.25, 8.953
    { 966966, 156 }, // 48.83, 8.953 x 49.04, 9.163
    { 966967, Bucket(2508) }, // 49.04, 8.953 x 49.25, 9.163
    { 966972, 156 }, // 48.83, 9.163 x 49.04, 9.373
    { 966973, 657 }, // 49.04, 9.163 x 49.25, 9.373
    { 966975, 657 }, // 49.04, 9.373 x 49.25, 9.583
    { 966983, Bucket(2511) }, // 49.88, 8.115 x 50.09, 8.324
    { 966985, 2928 }, // 49.46, 8.324 x 49.67, 8.534
    { 966986, Bucket(2514) }, // 49.25, 8.534 x 49.46, 8.744
    { 966988, 421 }, // 49.67, 8.324 x 49.88, 8.534
    { 966989, 1000 }, // 49.88, 8.324 x 50.09, 8.534
    { 966991, Bucket(2518) }, // 49.88, 8.534 x 50.09, 8.744
    { 967002, Bucket(2523) }, // 50.09, 8.534 x 50.3, 8.744
    { 967013, Bucket(2511) }, // 49.88, 8.744 x 50.09, 8.953
    { 967024, Bucket(2511) }, // 50.09, 8.744 x 50.3, 8.953
    { 967071, 615 }, // 49.04, 10.21 x 49.25, 10.42
    { 967082, 2642 }, // 47.57, 11.05 x 47.78, 11.26
    { 967085, Bucket(2536) }, // 48.2, 10.84 x 48.41, 11.05
    { 967146, Bucket(2539) }, // 49.25, 11.05 x 49.46, 11.26
    { 967252, Bucket(2542) }, // 47.15, 11.26 x 47.36, 11.47
    { 967405, 964 }, // 46.52, 14.2 x 46.73, 14.41
    { 967430, Bucket(2548) }, // 47.99, 11.47 x 48.2, 11.68
    { 967465, 2032 }, // 47.78, 12.52 x 47.99, 12.73
    { 967467, 1980 }, // 47.78, 12.73 x 47.99, 12.94
    { 967488, Bucket(2564) }, // 49.25, 11.26 x 49.46, 11.47
    { 967551, 1513 }, // 50.72, 12.73 x 50.93, 12.94
    { 967553, 1980 }, // 47.78, 12.94 x 47.99, 13.15
    { 967597, Bucket(2567) }, // 48.2, 14.2 x 48.41, 14.41
    { 967628, Bucket(2574) }, // 49.67, 13.36 x 49.88, 13.57
    { 967637, 1513 }, // 50.72, 12.94 x 50.93, 13.15
    { 967663, 3003 }, // 49.88, 14.41 x 50.09, 14.62
    { 967674, 3003 }, // 50.09, 14.41 x 50.3, 14.62
    { 967723, Bucket(2577) }, // 51.14, 9.373 x 51.35, 9.583
    { 967726, 1092 }, // 51.35, 9.373 x 51.56, 9.583
    { 967742, 1130 }, // 52.19, 9.373 x 52.4, 9.583
    { 967780, Bucket(2580) }, // 53.03, 8.744 x 53.24, 8.953
    { 967828, Bucket(2588) }, // 52.19, 9.583 x 52.4, 9.792
    { 967860, Bucket(2591) }, // 52.19, 10.42 x 52.4, 10.63
    { 967872, 825 }, // 52.61, 9.583 x 52.82, 9.792
    { 967890, 881 }, // 53.45, 9.792 x 53.65, 10
    { 967891, 1218 }, // 53.65, 9.792 x 53.86, 10
    { 967896, 881 }, // 53.45, 10 x 53.65, 10.21
    { 968206, Bucket(2598) }, // 51.35, 11.89 x 51.56, 12.1
    { 968211, Bucket(2608) }, // 51.98, 11.47 x 52.19, 11.68
    { 968227, Bucket(2612) }, // 51.14, 12.31 x 51.35, 12.52
    { 968230, Bucket(2612) }, // 51.35, 12.31 x 51.56, 12.52
    { 968240, 142 }, // 51.77, 12.1 x 51.98, 12.31
    { 968320, 1513 }, // 50.93, 12.94 x 51.14, 13.15
    { 968321, 843 }, // 51.14, 12.94 x 51.35, 13.15
    { 968322, 1384 }, // 50.93, 13.15 x 51.14, 13.36
    { 968324, 843 }, // 51.35, 12.94 x 51.56, 13.15
    { 968330, Bucket(2616) }, // 50.93, 13.57 x 51.14, 13.78
    { 968349, Bucket(2627) }, // 52.4, 13.36 x 52.61, 13.57
    { 968351, 34 }, // 52.4, 13.57 x 52.61, 13.78
    { 968352, Bucket(2636) }, // 50.93, 13.78 x 51.14, 13.99
    { 968382, 1972 }, // 52.19, 14.41 x 52.4, 14.62
    { 968431, Bucket(2644) }, // 53.24, 14.41 x 53.45, 14.62
    { 968442, Bucket(2652) }, // 53.45, 14.41 x 53.65, 14.62
    { 968795, Bucket(2658) }, // 46.94, 15.24 x 47.15, 15.45
    { 968817, 336 }, // 46.94, 15.45 x 47.15, 15.66
    { 969006, 79 }, // 47.99, 16.08 x 48.2, 16.29
    { 969007, 2877 }, // 48.2, 16.08 x 48.41, 16.29
    { 969092, 79 }, // 47.99, 16.29 x 48.2, 16.5
    { 969093, 2877 }, // 48.2, 16.29 x 48.41, 16.5
    { 969111, Bucket(2661) }, // 49.04, 16.5 x 49.25, 16.71
    { 969246, Bucket(2673) }, // 45.48, 18.6 x 45.69, 18.81
    { 969335, Bucket(2676) }, // 47.36, 19.02 x 47.57, 19.23
    { 969358, Bucket(2701) }, // 44.64, 20.28 x 44.85, 20.49
    { 969659, Bucket(2706) }, // 48.62, 21.12 x 48.83, 21.33
    { 970287, 2227 }, // 51.56, 19.44 x 51.77, 19.65
    { 970298, 2227 }, // 51.77, 19.44 x 51.98, 19.65
    { 970428, 1115 }, // 52.19, 20.91 x 52.4, 21.12
    { 970982, 893 }, // 59.74, 10.63 x 59.95, 10.84
    { 971215, 2374 }, // 63.3, 10.21 x 63.51, 10.42
    { 971274, Bucket(2719) }, // 57.64, 11.89 x 57.85, 12.1
    { 972858, Bucket(2729) }, // 58.48, 16.08 x 58.69, 16.29
    { 972991, Bucket(2732) }, // 59.11, 17.76 x 59.32, 17.97
    { 973034, Bucket(2732) }, // 59.32, 17.76 x 59.53, 17.97
    { 973333, Bucket(2736) }, // 59.11, 17.97 x 59.32, 18.18
    { 973335, 830 }, // 59.11, 18.18 x 59.32, 18.39
    { 973376, Bucket(2744) }, // 59.32, 17.97 x 59.53, 18.18
    { 975401, Bucket(2753) }, // 44.43, 25.94 x 44.64, 26.15
    { 977371, Bucket(2756) }, // 50.3, 30.34 x 50.51, 30.55
    { 977850, Bucket(2759) }, // 48.41, 34.54 x 48.62, 34.75
    { 978328, Bucket(2762) }, // 55.12, 30.13 x 55.33, 30.34
    { 979520, Bucket(2765) }, // 59.32, 24.68 x 59.53, 24.89
    { 981196, Bucket(2769) }, // 59.74, 30.13 x 59.95, 30.34
    { 981197, Bucket(2772) }, // 59.95, 30.13 x 60.16, 30.34
    { 981198, Bucket(2776) }, // 59.74, 30.34 x 59.95, 30.55
    { 2226005, 2003 }, // 17.16, 78.37 x 17.37, 78.58
    { 2314234, 1912 }, // 3.114, 101.6 x 3.323, 101.9
    { 2317681, 2110 }, // 16.75, 95.99 x 16.95, 96.19
    { 2318038, 1903 }, // 13.6, 100.4 x 13.81, 100.6
    { 2318975, 2264 }, // -6.324, 106.7 x -6.114, 106.9
    { 2319751, Bucket(2787) }, // 1.226, 103.7 x 1.436, 104
    { 2326808, 2922 }, // -32.12, 115.7 x -31.91, 115.9
    { 2348942, 1911 }, // 14.44, 120.9 x 14.65, 121.2
    { 2348943, 2115 }, // 14.65, 120.9 x 14.86, 121.2
    { 2363737, 1750 }, // 36.88, 35.17 x 37.09, 35.38
    { 2363889, Bucket(2790) }, // 36.88, 37.26 x 37.09, 37.47
    { 2363892, 2979 }, // 37.09, 37.26 x 37.3, 37.47
    { 2364718, 2972 }, // 41.28, 36.22 x 41.49, 36.43
    { 2366712, 1890 }, // 40.02, 44.4 x 40.23, 44.6
    { 2368699, 2431 }, // 25.13, 51.32 x 25.34, 51.53
    { 2370578, 2760 }, // 24.92, 55.09 x 25.13, 55.3
    { 2372031, Bucket(2793) }, // 35.62, 51.32 x 35.83, 51.53
    { 2372373, 1743 }, // 35.62, 51.53 x 35.83, 51.74
    { 2372817, Bucket(2797) }, // 40.23, 49.85 x 40.44, 50.06
    { 2374508, 1305 }, // 36.25, 59.49 x 36.46, 59.7
    { 2375923, Bucket(2800) }, // 46.94, 37.47 x 47.15, 37.68
    { 2375926, Bucket(2807) }, // 47.15, 37.47 x 47.36, 37.68
    { 2376047, 506 }, // 49.88, 36.22 x 50.09, 36.43
    { 2376286, Bucket(2811) }, // 47.15, 38.73 x 47.36, 38.94
    { 2377139, 452 }, // 55.33, 37.47 x 55.54, 37.68
    { 2377142, Bucket(2815) }, // 55.54, 37.47 x 55.75, 37.68
    { 2377143, 394 }, // 55.75, 37.47 x 55.96, 37.68
    { 2378169, Bucket(2820) }, // 48.62, 44.4 x 48.83, 44.6
    { 2379211, 726 }, // 56.17, 43.77 x 56.38, 43.98
    { 2379233, 726 }, // 56.17, 43.98 x 56.38, 44.19
    { 2385716, 2799 }, // 55.54, 52.36 x 55.75, 52.57
    { 2394685, Bucket(2823) }, // 18.84, 72.92 x 19.05, 73.13
    { 2394722, Bucket(2826) }, // 19.05, 72.71 x 19.26, 72.92
    { 2394728, 2600 }, // 19.05, 72.92 x 19.26, 73.13
    { 2399524, 699 }, // 41.28, 69.14 x 41.49, 69.35
    { 2400768, Bucket(2829) }, // 17.37, 78.37 x 17.58, 78.58
    { 2401371, 1902 }, // 26.81, 75.64 x 27.02, 75.85
    { 2401683, 1967 }, // 28.49, 76.9 x 28.7, 77.11
    { 2420007, 1658 }, // 54.91, 82.77 x 55.12, 82.98
    { 2420206, Bucket(2832) }, // 56.38, 84.87 x 56.59, 85.08
    { 2490838, 2961 }, // 23.67, 90.32 x 23.88, 90.53
    { 2499337, 2672 }, // 20.94, 105.6 x 21.15, 105.8
    { 2499632, 1831 }, // 24.92, 102.7 x 25.13, 102.9
    { 2500061, 2000 }, // 30.59, 104 x 30.8, 104.2
    { 2501476, 2469 }, // 22.83, 112.8 x 23.04, 113
    { 2501484, 2868 }, // 22.83, 113.2 x 23.04, 113.4
    { 2501485, Bucket(2835) }, // 23.04, 113.2 x 23.25, 113.4
    { 2501487, Bucket(2839) }, // 23.04, 113.4 x 23.25, 113.6
    { 2501533, Bucket(2842) }, // 22.2, 114 x 22.41, 114.2
    { 2501570, 2793 }, // 22.41, 113.8 x 22.62, 114
    { 2501571, 1634 }, // 22.62, 113.8 x 22.83, 114
    { 2501576, Bucket(2845) }, // 22.41, 114 x 22.62, 114.2
    { 2502620, 2866 }, // 30.38, 114 x 30.59, 114.2
    { 2502622, 2670 }, // 30.38, 114.2 x 30.59, 114.4
    { 2502644, 2670 }, // 30.38, 114.4 x 30.59, 114.6
    { 2502792, 2472 }, // 30.8, 104 x 31.01, 104.2
    { 2505484, 2835 }, // 34.57, 112.3 x 34.78, 112.6
    { 2505518, 2918 }, // 34.57, 113.4 x 34.78, 113.6
    { 2506404, 2617 }, // 37.93, 114.4 x 38.14, 114.6
    { 2516119, Bucket(2848) }, // 52.4, 103.7 x 52.61, 104
    { 2516126, Bucket(2853) }, // 52.19, 104.2 x 52.4, 104.4
    { 2524747, 1827 }, // 25.97, 119.3 x 26.18, 119.5
    { 2524802, 1143 }, // 24.09, 120.5 x 24.29, 120.7
    { 2524850, Bucket(2858) }, // 24.92, 121.4 x 25.13, 121.6
    { 2525051, 2825 }, // 30.17, 120.1 x 30.38, 120.3
    { 2525137, Bucket(2861) }, // 30.17, 120.3 x 30.38, 120.5
    { 2527419, 1834 }, // 31.84, 118.4 x 32.05, 118.6
    { 2527618, 2771 }, // 34.15, 117.2 x 34.36, 117.4
    { 2527751, 2199 }, // 31.43, 118.8 x 31.63, 119.1
    { 2527761, 1834 }, // 31.84, 118.6 x 32.05, 118.8
    { 2527762, 2199 }, // 31.63, 118.8 x 31.84, 119.1
    { 2527791, Bucket(2864) }, // 31.43, 120.1 x 31.63, 120.3
    { 2527800, Bucket(2868) }, // 31.63, 119.9 x 31.84, 120.1
    { 2527875, 2042 }, // 31.01, 120.5 x 31.22, 120.7
    { 2527876, Bucket(2871) }, // 31.22, 120.3 x 31.43, 120.5
    { 2527877, Bucket(2874) }, // 31.43, 120.3 x 31.63, 120.5
    { 2527878, Bucket(2879) }, // 31.22, 120.5 x 31.43, 120.7
    { 2527879, 2043 }, // 31.43, 120.5 x 31.63, 120.7
    { 2527884, Bucket(2871) }, // 31.22, 120.7 x 31.43, 120.9
    { 2528107, 1809 }, // 36.04, 120.1 x 36.25, 120.3
    { 2528193, Bucket(2884) }, // 36.04, 120.3 x 36.25, 120.5
    { 2528334, 2052 }, // 39.6, 115.9 x 39.81, 116.1
    { 2528357, Bucket(2887) }, // 39.81, 116.1 x 40.02, 116.3
    { 2528359, 296 }, // 39.81, 116.3 x 40.02, 116.5
    { 2528407, Bucket(2890) }, // 38.97, 117.2 x 39.18, 117.4
    { 2528415, 2071 }, // 38.97, 117.6 x 39.18, 117.8
    { 2530173, Bucket(2893) }, // 37.3, 126.6 x 37.51, 126.8
    { 2530175, 1590 }, // 37.3, 126.8 x 37.51, 127
    { 2530260, 1577 }, // 37.09, 127 x 37.3, 127.2
    { 2530261, 1837 }, // 37.3, 127 x 37.51, 127.2
    { 2530814, 2254 }, // 43.8, 125.1 x 44.01, 125.3
    { 2530856, Bucket(2897) }, // 37.51, 126.6 x 37.72, 126.8
    { 2530858, Bucket(2901) }, // 37.51, 126.8 x 37.72, 127
    { 2530944, Bucket(2905) }, // 37.51, 127 x 37.72, 127.2
    { 2535633, 1615 }, // 33.52, 130.4 x 33.73, 130.6
    { 2535638, 2666 }, // 33.73, 130.6 x 33.94, 130.8
    { 2536030, Bucket(2909) }, // 33.73, 132.7 x 33.94, 132.9
    { 2536195, 1614 }, // 34.36, 132.3 x 34.57, 132.5
    { 2536201, 1614 }, // 34.36, 132.5 x 34.57, 132.7
    { 2536364, Bucket(2913) }, // 34.57, 135 x 34.78, 135.2
    { 2537732, Bucket(2917) }, // 34.57, 135.4 x 34.78, 135.6
    { 2537735, 1950 }, // 34.78, 135.6 x 34.99, 135.8
    { 2537746, Bucket(2925) }, // 34.99, 135.6 x 35.2, 135.8
    { 2537786, 1953 }, // 34.99, 136.9 x 35.2, 137.1
    { 2538267, 2181 }, // 35.2, 139.4 x 35.41, 139.6
    { 2538292, Bucket(2929) }, // 35.41, 139.6 x 35.62, 139.8
    { 2538293, Bucket(2932) }, // 35.62, 139.6 x 35.83, 139.8
    { 2538314, 2158 }, // 35.83, 139.4 x 36.04, 139.6
    { 2538336, 2158 }, // 35.83, 139.6 x 36.04, 139.8
    { 2539149, 1646 }, // 38.14, 140.9 x 38.35, 141.1
    { 2539492, 1917 }, // 42.96, 141.3 x 43.17, 141.5
    { 2643426, Bucket(2940) }, // -37.99, 144.8 x -37.78, 145.1
    { 2689231, Bucket(2946) }, // -34.01, 151.1 x -33.8, 151.4
    { 1028415, 3011 }, // -0.3468, -78.6 x -0.2419, -78.5
    { 1028458, 3011 }, // -0.2419, -78.6 x -0.137, -78.5
    { 1028501, 3011 }, // -0.3468, -78.5 x -0.2419, -78.39
    { 1028544, 3011 }, // -0.2419, -78.5 x -0.137, -78.39
    { 1042715, 889 }, // 6.154, -75.67 x 6.259, -75.56
    { 1597918, 2921 }, // 33.94, -118.4 x 34.05, -118.3
    { 1597940, 2921 }, // 33.94, -118.3 x 34.05, -118.2
    { 1620607, Bucket(2949) }, // 25.66, -100.4 x 25.76, -100.3
    { 1620693, Bucket(2949) }, // 25.66, -100.3 x 25.76, -100.2
    { 1622465, 1151 }, // 33.42, -112.1 x 33.52, -111.9
    { 1626582, 2090 }, // 40.65, -111.9 x 40.76, -111.8
    { 1634715, 2082 }, // 39.71, -105 x 39.81, -104.9
    { 1639162, 161 }, // 45.48, -123.1 x 45.58, -123
    { 1640360, 2949 }, // 49.25, -123.2 x 49.36, -123.1
    { 1640536, Bucket(2953) }, // 45.48, -122.7 x 45.58, -122.6
    { 1718167, Bucket(2957) }, // 29.85, -90.14 x 29.96, -90.03
    { 1718210, Bucket(2960) }, // 29.96, -90.14 x 30.06, -90.03
    { 1735915, 814 }, // 41.81, -87.83 x 41.91, -87.73
    { 1735916, 2041 }, // 41.91, -87.94 x 42.02, -87.83
    { 1736257, 814 }, // 41.81, -87.73 x 41.91, -87.62
    { 1736261, 777 }, // 42.02, -87.73 x 42.12, -87.62
    { 1753594, Bucket(2963) }, // 33.73, -84.47 x 33.84, -84.37
    { 1753936, 1133 }, // 33.73, -84.37 x 33.84, -84.27
    { 1756742, 2671 }, // 35.2, -80.91 x 35.3, -80.8
    { 1758961, 2715 }, // 42.23, -83.11 x 42.33, -83.01
    { 1758964, 2715 }, // 42.33, -83.11 x 42.44, -83.01
    { 1761263, 188 }, // 43.69, -79.44 x 43.8, -79.34
    { 1766103, 2356 }, // 39.08, -76.72 x 39.18, -76.61
    { 1766693, 2584 }, // 42.85, -78.92 x 42.96, -78.81
    { 1766725, 189 }, // 43.69, -79.34 x 43.8, -79.23
    { 1767743, Bucket(2966) }, // 39.92, -75.25 x 40.02, -75.14
    { 1767786, Bucket(2974) }, // 40.02, -75.25 x 40.13, -75.14
    { 1767829, Bucket(2978) }, // 39.92, -75.14 x 40.02, -75.04
    { 1767872, 403 }, // 40.02, -75.14 x 40.13, -75.04
    { 1768305, 1823 }, // 40.55, -73.88 x 40.65, -73.78
    { 1813112, 950 }, // 45.48, -73.67 x 45.58, -73.57
    { 2372011, 2807 }, // -27.82, -64.34 x -27.71, -64.24
    { 2392191, Bucket(2981) }, // -34.74, -58.47 x -34.64, -58.37
    { 2392362, Bucket(2984) }, // -34.64, -58.47 x -34.53, -58.37
    { 2408299, 1049 }, // -23.63, -46.73 x -23.52, -46.62
    { 2408345, 1515 }, // -24.04, -46.41 x -23.94, -46.31
    { 2408385, 1049 }, // -23.63, -46.62 x -23.52, -46.52
    { 2442711, 1665 }, // 10.56, -71.68 x 10.66, -71.58
    { 2444773, 1607 }, // 10.14, -68.01 x 10.24, -67.91
    { 2496469, Bucket(2987) }, // -23, -43.27 x -22.89, -43.16
    { 2507278, 2350 }, // -22.68, -43.79 x -22.58, -43.69
    { 2507300, 2350 }, // -22.68, -43.69 x -22.58, -43.58
    { 2557665, 2492 }, // -5.17, -42.85 x -5.065, -42.74
    { 3007285, 3008 }, // 6.364, 3.291 x 6.469, 3.396
    { 3007328, 3008 }, // 6.469, 3.291 x 6.574, 3.396
    { 3167481, 2581 }, // 42.23, -71.16 x 42.33, -71.05
    { 3167484, 2583 }, // 42.33, -71.16 x 42.44, -71.05
    { 3698582, 2604 }, // 36.46, -6.251 x 36.56, -6.146
    { 3699431, Bucket(2990) }, // 38.66, -9.187 x 38.77, -9.082
    { 3699442, 1670 }, // 38.77, -9.187 x 38.87, -9.082
    { 3723759, 1773 }, // 40.34, -3.944 x 40.44, -3.839
    { 3723780, 1893 }, // 37.72, -3.839 x 37.82, -3.734
    { 3724101, Bucket(2996) }, // 40.34, -3.839 x 40.44, -3.734
    { 3724103, Bucket(2999) }, // 40.34, -3.734 x 40.44, -3.63
    { 3724112, 1772 }, // 40.44, -3.839 x 40.55, -3.734
    { 3724114, Bucket(3002) }, // 40.44, -3.734 x 40.55, -3.63
    { 3725204, 2094 }, // 43.17, -3 x 43.27, -2.896
    { 3725248, 1501 }, // 43.38, -3 x 43.48, -2.896
    { 3725458, 1854 }, // 37.93, -1.218 x 38.03, -1.113
    { 3725546, 228 }, // 38.35, -0.5886 x 38.45, -0.4838
    { 3725845, 2885 }, // 38.24, -0.4838 x 38.35, -0.3789
    { 3725888, Bucket(3005) }, // 38.35, -0.4838 x 38.45, -0.3789
    { 3726086, Bucket(3009) }, // 39.39, -0.3789 x 39.5, -0.2741
    { 3726495, 363 }, // 41.6, -1.008 x 41.7, -0.9032
    { 3726517, 363 }, // 41.6, -0.9032 x 41.7, -0.7984
    { 3727022, 1338 }, // 41.07, 1.089 x 41.18, 1.194
    { 3732484, 1338 }, // 41.07, 1.194 x 41.18, 1.299
    { 3732624, 1358 }, // 41.28, 2.033 x 41.39, 2.138
    { 3732627, Bucket(3012) }, // 41.39, 2.138 x 41.49, 2.243
    { 3734847, 211 }, // 43.27, 5.283 x 43.38, 5.388
    { 3734873, 2389 }, // 43.9, 4.759 x 44.01, 4.864
    { 3734933, Bucket(3018) }, // 43.27, 5.388 x 43.38, 5.493
    { 3770738, 606 }, // 47.15, -1.637 x 47.26, -1.532
    { 3771949, Bucket(3021) }, // 47.89, 0.1454 x 47.99, 0.2502
    { 3771960, Bucket(3021) }, // 47.99, 0.1454 x 48.1, 0.2502
    { 3771991, Bucket(3024) }, // 49.15, -0.3789 x 49.25, -0.2741
    { 3772198, 1037 }, // 49.46, 0.0405 x 49.57, 0.1454
    { 3773416, 2556 }, // 53.45, -2.371 x 53.55, -2.266
    { 3773663, 1414 }, // 55.86, -4.364 x 55.96, -4.259
    { 3774784, Bucket(3027) }, // 53.45, -2.162 x 53.55, -2.057
    { 3775003, Bucket(3030) }, // 51.45, -0.1692 x 51.56, -0.06436
    { 3775025, Bucket(3033) }, // 51.45, -0.06436 x 51.56, 0.0405
    { 3777261, Bucket(3036) }, // 45.37, 4.34 x 45.48, 4.445
    { 3777272, 311 }, // 45.48, 4.34 x 45.58, 4.445
    { 3777741, 2890 }, // 48.73, 2.243 x 48.83, 2.347
    { 3777743, 2746 }, // 48.73, 2.347 x 48.83, 2.452
    { 3777754, Bucket(3040) }, // 48.83, 2.347 x 48.94, 2.452
    { 3778551, 2072 }, // 50.82, 4.235 x 50.93, 4.34
    { 3778557, 1907 }, // 50.82, 4.34 x 50.93, 4.445
    { 3778652, 1056 }, // 45.69, 4.759 x 45.79, 4.864
    { 3778654, 791 }, // 45.69, 4.864 x 45.79, 4.969
    { 3778763, 1082 }, // 45.16, 5.703 x 45.27, 5.808
    { 3778990, Bucket(3043) }, // 46.11, 6.122 x 46.21, 6.227
    { 3779255, 2172 }, // 44.95, 7.59 x 45.06, 7.695
    { 3779298, 2172 }, // 45.06, 7.59 x 45.16, 7.695
    { 3779531, Bucket(3046) }, // 46.84, 7.381 x 46.94, 7.485
    { 3779534, Bucket(3046) }, // 46.94, 7.381 x 47.05, 7.485
    { 3779553, 1089 }, // 46.84, 7.485 x 46.94, 7.59
    { 3779556, 1089 }, // 46.94, 7.485 x 47.05, 7.59
    { 3779571, 2977 }, // 47.26, 7.59 x 47.36, 7.695
    { 3779575, 2605 }, // 47.47, 7.59 x 47.57, 7.695
    { 3779577, 2977 }, // 47.26, 7.695 x 47.36, 7.8
    { 3779822, 586 }, // 48.62, 6.122 x 48.73, 6.227
    { 3780233, Bucket(3049) }, // 47.68, 7.276 x 47.78, 7.381
    { 3780271, Bucket(3052) }, // 47.89, 7.8 x 47.99, 7.905
    { 3780282, Bucket(3055) }, // 47.99, 7.8 x 48.1, 7.905
    { 3780329, Bucket(3059) }, // 48.52, 7.695 x 48.62, 7.8
    { 3780564, 92 }, // 50.72, 7.066 x 50.82, 7.171
    { 3781350, 1394 }, // 51.98, 4.235 x 52.08, 4.34
    { 3781355, Bucket(3063) }, // 51.87, 4.445 x 51.98, 4.549
    { 3782721, Bucket(3068) }, // 51.87, 4.549 x 51.98, 4.654
    { 3782747, Bucket(3072) }, // 52.29, 4.864 x 52.4, 4.969
    { 3783208, Bucket(3078) }, // 50.93, 6.856 x 51.03, 6.961
    { 3783323, Bucket(3081) }, // 51.45, 7.381 x 51.56, 7.485
    { 3819363, Bucket(3086) }, // 36.77, 10.11 x 36.88, 10.21
    { 3821962, 1265 }, // 39.18, 9.058 x 39.29, 9.163
    { 3823599, Bucket(3090) }, // 43.69, 11.16 x 43.8, 11.26
    { 3823610, Bucket(3090) }, // 43.8, 11.16 x 43.9, 11.26
    { 3824155, Bucket(3093) }, // 38.03, 13.25 x 38.14, 13.36
    { 3824177, 1327 }, // 38.03, 13.36 x 38.14, 13.46
    { 3824629, Bucket(3096) }, // 40.76, 14.2 x 40.86, 14.3
    { 3824843, 620 }, // 41.81, 12.41 x 41.91, 12.52
    { 3824846, 618 }, // 41.91, 12.41 x 42.02, 12.52
    { 3824865, 624 }, // 41.81, 12.52 x 41.91, 12.62
    { 3825312, 2725 }, // 40.86, 14.2 x 40.97, 14.3
    { 3829792, 1608 }, // 37.51, 15.04 x 37.61, 15.14
    { 3830101, 609 }, // 40.76, 14.62 x 40.86, 14.72
    { 3830784, 608 }, // 40.86, 14.62 x 40.97, 14.72
    { 3854843, Bucket(3099) }, // 40.55, 22.9 x 40.65, 23
    { 3860419, 2662 }, // 36.77, 30.66 x 36.88, 30.76
    { 3860422, 2662 }, // 36.88, 30.66 x 36.98, 30.76
    { 3863355, Bucket(3102) }, // 39.71, 30.45 x 39.81, 30.55
    { 3863441, Bucket(3106) }, // 39.71, 30.55 x 39.81, 30.66
    { 3863595, Bucket(3109) }, // 40.97, 28.77 x 41.07, 28.88
    { 3863681, 1638 }, // 40.97, 28.88 x 41.07, 28.98
    { 3863686, 1639 }, // 41.07, 28.98 x 41.18, 29.09
    { 3863691, 2986 }, // 40.97, 29.19 x 41.07, 29.3
    { 3866968, 184 }, // 47.15, 8.115 x 47.26, 8.219
    { 3866971, 459 }, // 47.26, 8.219 x 47.36, 8.324
    { 3866975, 2017 }, // 47.47, 8.219 x 47.57, 8.324
    { 3866993, 2305 }, // 47.26, 8.324 x 47.36, 8.429
    { 3866994, 2031 }, // 47.15, 8.429 x 47.26, 8.534
    { 3866995, 2031 }, // 47.26, 8.429 x 47.36, 8.534
    { 3866996, 2305 }, // 47.36, 8.324 x 47.47, 8.429
    { 3867003, 2027 }, // 47.26, 8.639 x 47.36, 8.744
    { 3867004, Bucket(3112) }, // 47.36, 8.534 x 47.47, 8.639
    { 3867007, Bucket(3115) }, // 47.47, 8.639 x 47.57, 8.744
    { 3867089, 1449 }, // 47.26, 8.744 x 47.36, 8.849
    { 3867092, Bucket(3118) }, // 47.36, 8.744 x 47.47, 8.849
    { 3867093, 2019 }, // 47.47, 8.744 x 47.57, 8.849
    { 3867096, 2533 }, // 47.15, 8.953 x 47.26, 9.058
    { 3867097, 2533 }, // 47.26, 8.953 x 47.36, 9.058
    { 3867100, 2533 }, // 47.36, 8.953 x 47.47, 9.058
    { 3867103, Bucket(3121) }, // 47.47, 9.058 x 47.57, 9.163
    { 3867126, 2595 }, // 47.36, 9.268 x 47.47, 9.373
    { 3867256, 846 }, // 45.48, 10.21 x 45.58, 10.32
    { 3867460, 3019 }, // 46.94, 9.583 x 47.05, 9.687
    { 3867461, 2566 }, // 47.05, 9.583 x 47.15, 9.687
    { 3867463, 2566 }, // 47.05, 9.687 x 47.15, 9.792
    { 3867658, 2017 }, // 47.57, 8.219 x 47.68, 8.324
    { 3867690, 2037 }, // 47.57, 8.639 x 47.68, 8.744
    { 3867763, 26 }, // 48.94, 8.429 x 49.04, 8.534
    { 3867772, 1123 }, // 49.04, 8.534 x 49.15, 8.639
    { 3867775, 372 }, // 49.15, 8.639 x 49.25, 8.744
    { 3867855, Bucket(3125) }, // 48.73, 9.058 x 48.83, 9.163
    { 3867865, 657 }, // 48.94, 8.953 x 49.04, 9.058
    { 3867866, 153 }, // 48.83, 9.058 x 48.94, 9.163
    { 3867877, Bucket(3129) }, // 48.73, 9.163 x 48.83, 9.268
    { 3867888, Bucket(3136) }, // 48.83, 9.163 x 48.94, 9.268
    { 3867890, 153 }, // 48.83, 9.268 x 48.94, 9.373
    { 3867896, 153 }, // 48.83, 9.373 x 48.94, 9.478
    { 3867935, 998 }, // 49.98, 8.219 x 50.09, 8.324
    { 3867947, Bucket(3140) }, // 49.36, 8.639 x 49.46, 8.744
    { 3868010, Bucket(3143) }, // 50.09, 8.639 x 50.19, 8.744
    { 3868053, 998 }, // 49.98, 8.744 x 50.09, 8.849
    { 3868096, Bucket(3146) }, // 50.09, 8.744 x 50.19, 8.849
    { 3868191, 1508 }, // 48.31, 9.897 x 48.41, 10
    { 3868234, 1508 }, // 48.41, 9.897 x 48.52, 10
    { 3868319, 319 }, // 48.31, 10.74 x 48.41, 10.84
    { 3868341, Bucket(3150) }, // 48.31, 10.84 x 48.41, 10.95
    { 3868585, 129 }, // 49.36, 11.05 x 49.46, 11.16
    { 3868637, 707 }, // 50.82, 10.63 x 50.93, 10.74
    { 3869010, 183 }, // 47.15, 11.37 x 47.26, 11.47
    { 3869721, Bucket(3156) }, // 48.1, 11.47 x 48.2, 11.57
    { 3869723, 2851 }, // 48.1, 11.57 x 48.2, 11.68
    { 3869781, 179 }, // 49.15, 11.26 x 49.25, 11.37
    { 3869824, 2642 }, // 47.57, 12.1 x 47.68, 12.2
    { 3869871, 1977 }, // 47.89, 12.83 x 47.99, 12.94
    { 3869882, 1977 }, // 47.99, 12.83 x 48.1, 12.94
    { 3870047, Bucket(3161) }, // 50.82, 11.57 x 50.93, 11.68
    { 3870079, Bucket(3164) }, // 50.82, 11.99 x 50.93, 12.1
    { 3870165, 181 }, // 50.82, 12.1 x 50.93, 12.2
    { 3870171, 1299 }, // 50.61, 12.41 x 50.72, 12.52
    { 3870174, 1299 }, // 50.72, 12.41 x 50.82, 12.52
    { 3870653, Bucket(3167) }, // 49.98, 14.41 x 50.09, 14.51
    { 3870696, Bucket(3167) }, // 50.09, 14.41 x 50.19, 14.51
    { 3870822, 597 }, // 51.98, 8.429 x 52.08, 8.534
    { 3870828, 597 }, // 51.98, 8.534 x 52.08, 8.639
    { 3871034, 333 }, // 53.03, 8.639 x 53.13, 8.744
    { 3871120, Bucket(3170) }, // 53.03, 8.744 x 53.13, 8.849
    { 3871315, Bucket(3173) }, // 52.29, 9.687 x 52.4, 9.792
    { 3871368, Bucket(3176) }, // 50.93, 10.63 x 51.03, 10.74
    { 3871387, Bucket(3179) }, // 51.45, 10.74 x 51.56, 10.84
    { 3871394, Bucket(3182) }, // 50.93, 10.95 x 51.03, 11.05
    { 3872825, Bucket(3186) }, // 51.45, 11.89 x 51.56, 11.99
    { 3872847, Bucket(3191) }, // 52.08, 11.57 x 52.19, 11.68
    { 3872909, Bucket(3197) }, // 51.24, 12.31 x 51.35, 12.41
    { 3872920, 77 }, // 51.35, 12.31 x 51.45, 12.41
    { 3872938, 1512 }, // 50.93, 12.83 x 51.03, 12.94
    { 3872962, 1116 }, // 51.77, 12.2 x 51.87, 12.31
    { 3873091, 115 }, // 53.55, 11.37 x 53.65, 11.47
    { 3873150, Bucket(3200) }, // 54.07, 11.99 x 54.18, 12.1
    { 3873236, Bucket(3203) }, // 54.07, 12.1 x 54.18, 12.2
    { 3873280, 1512 }, // 50.93, 12.94 x 51.03, 13.04
    { 3873323, Bucket(3207) }, // 51.03, 13.67 x 51.14, 13.78
    { 3873397, Bucket(3210) }, // 52.5, 13.36 x 52.61, 13.46
    { 3873406, 645 }, // 52.4, 13.67 x 52.5, 13.78
    { 3873463, 464 }, // 51.66, 14.3 x 51.77, 14.41
    { 3873493, 177 }, // 52.5, 13.78 x 52.61, 13.88
    { 3873727, Bucket(3214) }, // 53.34, 14.51 x 53.45, 14.62
    { 3873770, Bucket(3218) }, // 53.45, 14.51 x 53.55, 14.62
    { 3874011, 284 }, // 55.65, 12.41 x 55.75, 12.52
    { 3874014, 2382 }, // 55.75, 12.41 x 55.86, 12.52
    { 3874033, Bucket(3221) }, // 55.65, 12.52 x 55.75, 12.62
    { 3874036, 2382 }, // 55.75, 12.52 x 55.86, 12.62
    { 3875183, Bucket(3225) }, // 47.05, 15.35 x 47.15, 15.45
    { 3875269, Bucket(3229) }, // 47.05, 15.45 x 47.15, 15.56
    { 3877340, 486 }, // 47.36, 19.02 x 47.47, 19.12
    { 3877341, Bucket(3232) }, // 47.47, 19.02 x 47.57, 19.12
    { 3877342, 477 }, // 47.36, 19.12 x 47.47, 19.23
    { 3877435, Bucket(3240) }, // 44.74, 20.38 x 44.85, 20.49
    { 3877521, Bucket(3246) }, // 44.74, 20.49 x 44.85, 20.59
    { 3877669, Bucket(3252) }, // 46.21, 20.07 x 46.31, 20.17
    { 3878024, Bucket(3258) }, // 47.57, 19.02 x 47.68, 19.12
    { 3878638, 1920 }, // 48.62, 21.22 x 48.73, 21.33
    { 3879189, Bucket(3261) }, // 53.34, 14.62 x 53.45, 14.72
    { 3881149, 2216 }, // 51.66, 19.44 x 51.77, 19.54
    { 3881192, 2216 }, // 51.77, 19.44 x 51.87, 19.54
    { 3885096, 660 }, // 57.64, 11.89 x 57.74, 11.99
    { 3892138, Bucket(3265) }, // 59.32, 17.87 x 59.42, 17.97
    { 3893504, Bucket(3270) }, // 59.32, 17.97 x 59.42, 18.08
    { 3899741, Bucket(3273) }, // 47.47, 21.54 x 47.57, 21.64
    { 3899751, 2819 }, // 47.05, 21.85 x 47.15, 21.96
    { 3901331, Bucket(3276) }, // 49.78, 23.95 x 49.88, 24.05
    { 3902415, Bucket(3280) }, // 47.05, 27.51 x 47.15, 27.62
    { 3902426, Bucket(3284) }, // 47.15, 27.51 x 47.26, 27.62
    { 3909485, 511 }, // 50.4, 30.34 x 50.51, 30.45
    { 3909573, Bucket(3289) }, // 50.4, 30.55 x 50.51, 30.66
    { 3909584, Bucket(3289) }, // 50.51, 30.55 x 50.61, 30.66
    { 3911183, 2440 }, // 47.89, 33.39 x 47.99, 33.49
    { 3913290, Bucket(3292) }, // 55.12, 30.03 x 55.23, 30.13
    { 3913312, Bucket(3292) }, // 55.12, 30.13 x 55.23, 30.24
    { 3916778, 1565 }, // 60.16, 24.58 x 60.26, 24.68
    { 3917370, Bucket(3295) }, // 61.41, 23.74 x 61.52, 23.84
    { 3917456, 2754 }, // 61.41, 23.84 x 61.52, 23.95
    { 3918081, 512 }, // 59.42, 24.68 x 59.53, 24.79
    { 3918109, Bucket(3298) }, // 60.05, 24.89 x 60.16, 25
    { 3918152, Bucket(3302) }, // 60.16, 24.89 x 60.26, 25
    { 3924787, 525 }, // 59.84, 30.24 x 59.95, 30.34
    { 3924792, 808 }, // 59.74, 30.34 x 59.84, 30.45
    { 3924793, 2991 }, // 59.84, 30.34 x 59.95, 30.45
    { 3924796, 807 }, // 59.95, 30.34 x 60.05, 30.45
    { 9276245, 2523 }, // -6.219, 106.9 x -6.114, 107
    { 9453665, 837 }, // 31.74, 35.17 x 31.84, 35.27
    { 9455557, 2976 }, // 36.98, 37.26 x 37.09, 37.37
    { 9455568, 2976 }, // 37.09, 37.26 x 37.19, 37.37
    { 9457775, Bucket(3311) }, // 38.66, 35.48 x 38.77, 35.59
    { 9467626, Bucket(3314) }, // 41.7, 44.71 x 41.81, 44.81
    { 9468949, 1714 }, // 41.6, 44.81 x 41.7, 44.92
    { 9468992, 1714 }, // 41.7, 44.81 x 41.81, 44.92
    { 9474799, 2414 }, // 25.24, 51.42 x 25.34, 51.53
    { 9474810, Bucket(3317) }, // 25.34, 51.42 x 25.45, 51.53
    { 9476165, 2431 }, // 25.24, 51.53 x 25.34, 51.63
    { 9476176, Bucket(3317) }, // 25.34, 51.53 x 25.45, 51.63
    { 9477522, 2980 }, // 29.54, 52.47 x 29.64, 52.57
    { 9490927, Bucket(3320) }, // 40.34, 49.74 x 40.44, 49.85
    { 9503693, 2279 }, // 47.05, 37.47 x 47.15, 37.58
    { 9503695, 2545 }, // 47.05, 37.58 x 47.15, 37.68
    { 9505146, Bucket(3324) }, // 47.15, 38.84 x 47.26, 38.94
    { 9508566, Bucket(3331) }, // 55.75, 37.37 x 55.86, 37.47
    { 9508571, Bucket(3334) }, // 55.65, 37.58 x 55.75, 37.68
    { 9508572, Bucket(3337) }, // 55.75, 37.47 x 55.86, 37.58
    { 9508574, 943 }, // 55.75, 37.58 x 55.86, 37.68
    { 9508593, 1596 }, // 55.65, 37.68 x 55.75, 37.79
    { 9508596, 943 }, // 55.75, 37.68 x 55.86, 37.79
    { 9516847, 1597 }, // 56.28, 43.87 x 56.38, 43.98
    { 9551720, 1660 }, // 56.8, 60.54 x 56.91, 60.65
    { 9578890, 1609 }, // 19.05, 72.81 x 19.16, 72.92
    { 9579108, 2864 }, // 18.42, 73.76 x 18.53, 73.86
    { 9579109, 2865 }, // 18.53, 73.76 x 18.63, 73.86
    { 9598098, 700 }, // 41.28, 69.25 x 41.39, 69.35
    { 9603074, 2002 }, // 17.37, 78.47 x 17.48, 78.58
    { 9613224, 2963 }, // 22.41, 88.23 x 22.51, 88.33
    { 9613227, 2638 }, // 22.51, 88.33 x 22.62, 88.44
    { 9680031, 1659 }, // 55.02, 82.88 x 55.12, 82.98
    { 9997350, 2703 }, // 20.94, 105.7 x 21.04, 105.8
    { 10000245, 2466 }, // 30.69, 104 x 30.8, 104.1
    { 10005755, 2430 }, // 22.09, 113.5 x 22.2, 113.6
    { 10005942, 1628 }, // 23.04, 113.3 x 23.14, 113.4
    { 10006111, Bucket(3341) }, // 22.3, 113.9 x 22.41, 114
    { 10006134, 1466 }, // 22.2, 114.1 x 22.3, 114.2
    { 10006277, 2234 }, // 22.72, 113.6 x 22.83, 113.7
    { 10006278, 2839 }, // 22.62, 113.7 x 22.72, 113.8
    { 10006282, Bucket(3349) }, // 22.41, 113.9 x 22.51, 114
    { 10006283, 1634 }, // 22.51, 113.9 x 22.62, 114
    { 10006287, 2944 }, // 22.72, 113.9 x 22.83, 114
    { 10006292, 1828 }, // 23.04, 113.6 x 23.14, 113.7
    { 10006304, 1426 }, // 22.41, 114 x 22.51, 114.1
    { 10006308, 2906 }, // 22.62, 114 x 22.72, 114.1
    { 10019167, 1780 }, // 34.05, 108.9 x 34.15, 109
    { 10064479, 849 }, // 52.5, 103.8 x 52.61, 104
    { 10096388, 1805 }, // 22.62, 120.3 x 22.72, 120.4
    { 10099402, 2975 }, // 24.92, 121.5 x 25.03, 121.6
    { 10099404, 1288 }, // 25.13, 121.4 x 25.24, 121.5
    { 10110743, 2468 }, // 36.56, 117.1 x 36.67, 117.2
    { 10110786, 2468 }, // 36.67, 117.1 x 36.77, 117.2
    { 10111157, 2388 }, // 31.53, 119.9 x 31.63, 120
    { 10111167, 1758 }, // 31.53, 120.2 x 31.63, 120.3
    { 10111204, 2388 }, // 31.84, 119.9 x 31.95, 120
    { 10111630, 1981 }, // 31.01, 121.5 x 31.11, 121.6
    { 10121045, 1590 }, // 37.4, 127 x 37.51, 127.1
    { 10123259, 2255 }, // 43.9, 125.2 x 44.01, 125.3
    { 10123358, 1682 }, // 38.97, 125.7 x 39.08, 125.8
    { 10123776, Bucket(3362) }, // 37.51, 127 x 37.61, 127.1
    { 10123780, 1576 }, // 37.72, 127 x 37.82, 127.1
    { 10124624, 2254 }, // 43.8, 125.3 x 43.9, 125.5
    { 10124625, 2255 }, // 43.9, 125.3 x 44.01, 125.5
    { 10142190, Bucket(3365) }, // 33.52, 130.3 x 33.63, 130.4
    { 10142231, Bucket(3368) }, // 31.53, 130.5 x 31.63, 130.6
    { 10142532, Bucket(3365) }, // 33.52, 130.4 x 33.63, 130.5
    { 10142976, Bucket(2120) }, // 35.83, 128.7 x 35.93, 128.8
    { 10145466, 2231 }, // 34.57, 135.3 x 34.68, 135.4
    { 10150928, 2231 }, // 34.57, 135.4 x 34.68, 135.5
    { 10150943, 1949 }, // 34.89, 135.7 x 34.99, 135.8
    { 10150986, 1949 }, // 34.99, 135.7 x 35.1, 135.8
    { 10151145, 1955 }, // 35.1, 136.9 x 35.2, 137
    { 10151147, 2253 }, // 35.1, 137 x 35.2, 137.1
    { 10153083, 1649 }, // 35.51, 139.5 x 35.62, 139.6
    { 10153157, 569 }, // 35.3, 139.6 x 35.41, 139.7
    { 10153168, 1619 }, // 35.41, 139.6 x 35.51, 139.7
    { 10153172, 568 }, // 35.62, 139.6 x 35.72, 139.7
    { 10153175, 2136 }, // 35.72, 139.7 x 35.83, 139.8
    { 10153346, 2149 }, // 35.83, 139.7 x 35.93, 139.8
    { 10157968, 2107 }, // 42.96, 141.3 x 43.06, 141.4
    { 10573707, Bucket(3371) }, // -37.89, 145 x -37.78, 145.1
    { 4170863, 1428 }, // 6.207, -75.61 x 6.259, -75.56
    { 4170949, 1428 }, // 6.207, -75.56 x 6.259, -75.51
    { 6381721, Bucket(3376) }, // 37.77, -122.4 x 37.82, -122.4
    { 6382490, 2134 }, // 38.56, -121.5 x 38.61, -121.5
    { 6393016, 2333 }, // 32.68, -117.2 x 32.74, -117.1
    { 6461986, 1468 }, // 20.73, -103.4 x 20.78, -103.3
    { 6872671, 2719 }, // 29.9, -90.08 x 29.96, -90.03
    { 6872842, 2719 }, // 29.96, -90.08 x 30.01, -90.03
    { 6884885, Bucket(3381) }, // 32.84, -96.95 x 32.89, -96.9
    { 6884889, 1402 }, // 32.74, -96.85 x 32.79, -96.8
    { 6918343, Bucket(3384) }, // 34.73, -92.29 x 34.78, -92.23
    { 6943678, 777 }, // 42.02, -87.78 x 42.07, -87.73
    { 6944481, 2716 }, // 43.01, -87.94 x 43.06, -87.88
    { 6975585, 2714 }, // 27.91, -82.48 x 27.96, -82.43
    { 7029750, 1100 }, // 39.08, -84.53 x 39.13, -84.47
    { 7071146, 1882 }, // 40.02, -75.19 x 40.08, -75.14
    { 7073139, 1872 }, // 40.7, -74.04 x 40.76, -73.99
    { 7073144, 1824 }, // 40.65, -73.99 x 40.7, -73.94
    { 7252456, 948 }, // 45.48, -73.57 x 45.53, -73.52
    { 9518751, 2905 }, // -17.49, -66.18 x -17.44, -66.12
    { 9518794, 2905 }, // -17.44, -66.18 x -17.39, -66.12
    { 9568767, 899 }, // -34.69, -58.42 x -34.64, -58.37
    { 9569134, 890 }, // -34.95, -58 x -34.9, -57.95
    { 9569220, 890 }, // -34.95, -57.95 x -34.9, -57.89
    { 9569450, Bucket(3387) }, // -34.64, -58.42 x -34.58, -58.37
    { 9780728, 1610 }, // 10.45, -66.86 x 10.51, -66.81
    { 9780730, 1610 }, // 10.45, -66.81 x 10.51, -66.75
    { 9985879, Bucket(3390) }, // -22.94, -43.21 x -22.89, -43.16
    { 10084346, 2750 }, // -9.679, -35.77 x -9.627, -35.72
    { 10239102, Bucket(3394) }, // -3.702, -40.38 x -3.65, -40.33
    { 14703373, 376 }, // 28.44, -16.32 x 28.49, -16.26
    { 14797725, 1671 }, // 38.71, -9.187 x 38.77, -9.135
    { 14797768, 1671 }, // 38.77, -9.187 x 38.82, -9.135
    { 14882592, 1705 }, // 36.67, -4.468 x 36.72, -4.416
    { 14896391, 1892 }, // 40.18, -3.787 x 40.23, -3.734
    { 14896402, 1892 }, // 40.23, -3.787 x 40.29, -3.734
    { 14902186, Bucket(3397) }, // 38.35, -0.5362 x 38.4, -0.4838
    { 14903552, 227 }, // 38.35, -0.4838 x 38.4, -0.4314
    { 14904345, 2884 }, // 39.45, -0.3789 x 39.5, -0.3265
    { 14933786, 1098 }, // 43.59, 3.868 x 43.64, 3.92
    { 14939390, Bucket(3400) }, // 43.27, 5.336 x 43.33, 5.388
    { 14939732, 694 }, // 43.27, 5.388 x 43.33, 5.441
    { 14941982, 2403 }, // 43.69, 7.223 x 43.75, 7.276
    { 14942004, 2403 }, // 43.69, 7.276 x 43.75, 7.328
    { 15087964, 2315 }, // 49.15, -0.3789 x 49.2, -0.3265
    { 15094740, 1414 }, // 55.86, -4.259 x 55.91, -4.206
    { 15111020, 1477 }, // 48.94, 2.347 x 48.99, 2.4
    { 15111117, 1495 }, // 48.99, 2.557 x 49.04, 2.61
    { 15118138, 2169 }, // 46.94, 7.433 x 47, 7.485
    { 15121911, 86 }, // 50.88, 6.909 x 50.93, 6.961
    { 15296623, 1329 }, // 38.08, 13.3 x 38.14, 13.36
    { 15298431, 2660 }, // 40.81, 14.14 x 40.86, 14.2
    { 15298519, 2736 }, // 40.81, 14.25 x 40.86, 14.3
    { 15299375, Bucket(3403) }, // 41.86, 12.47 x 41.91, 12.52
    { 15299461, Bucket(3403) }, // 41.86, 12.52 x 41.91, 12.57
    { 15301250, 2736 }, // 40.86, 14.25 x 40.91, 14.3
    { 15419575, 1453 }, // 37.87, 23.69 x 37.93, 23.74
    { 15419618, 1453 }, // 37.93, 23.69 x 37.98, 23.74
    { 15435807, 1545 }, // 31.16, 29.87 x 31.22, 29.92
    { 15435850, 1545 }, // 31.22, 29.87 x 31.27, 29.92
    { 15467850, 458 }, // 47.15, 8.062 x 47.21, 8.115
    { 15467880, 184 }, // 47.15, 8.219 x 47.21, 8.272
    { 15467881, 184 }, // 47.21, 8.219 x 47.26, 8.272
    { 15467882, 184 }, // 47.15, 8.272 x 47.21, 8.324
    { 15467994, 862 }, // 47.36, 8.482 x 47.42, 8.534
    { 15468016, Bucket(3406) }, // 47.36, 8.534 x 47.42, 8.586
    { 15468376, 2019 }, // 47.36, 8.849 x 47.42, 8.901
    { 15468379, 2509 }, // 47.42, 8.901 x 47.47, 8.953
    { 15468381, 2509 }, // 47.52, 8.849 x 47.57, 8.901
    { 15468382, 2509 }, // 47.47, 8.901 x 47.52, 8.953
    { 15468383, 2509 }, // 47.52, 8.901 x 47.57, 8.953
    { 15468394, 2567 }, // 47.15, 9.111 x 47.21, 9.163
    { 15468395, 2567 }, // 47.21, 9.111 x 47.26, 9.163
    { 15468398, 2567 }, // 47.26, 9.111 x 47.31, 9.163
    { 15468399, 2567 }, // 47.31, 9.111 x 47.36, 9.163
    { 15468410, 2567 }, // 47.36, 9.111 x 47.42, 9.163
    { 15468411, 2567 }, // 47.42, 9.111 x 47.47, 9.163
    { 15468501, 2522 }, // 47.52, 9.163 x 47.57, 9.216
    { 15469848, 3019 }, // 46.94, 9.687 x 47, 9.74
    { 15471096, 1123 }, // 49.04, 8.639 x 49.09, 8.691
    { 15471099, 372 }, // 49.09, 8.691 x 49.15, 8.744
    { 15471469, 657 }, // 48.99, 9.058 x 49.04, 9.111
    { 15471471, 657 }, // 48.99, 9.111 x 49.04, 9.163
    { 15471508, 46 }, // 48.73, 9.163 x 48.78, 9.216
    { 15471556, 153 }, // 48.94, 9.163 x 48.99, 9.216
    { 15471557, 657 }, // 48.99, 9.163 x 49.04, 9.216
    { 15471558, 153 }, // 48.94, 9.216 x 48.99, 9.268
    { 15471559, 657 }, // 48.99, 9.216 x 49.04, 9.268
    { 15471564, 153 }, // 48.94, 9.268 x 48.99, 9.32
    { 15471565, 657 }, // 48.99, 9.268 x 49.04, 9.32
    { 15471566, 153 }, // 48.94, 9.32 x 48.99, 9.373
    { 15471567, 657 }, // 48.99, 9.32 x 49.04, 9.373
    { 15471588, 153 }, // 48.94, 9.373 x 48.99, 9.425
    { 15471589, 657 }, // 48.99, 9.373 x 49.04, 9.425
    { 15471591, 657 }, // 48.99, 9.425 x 49.04, 9.478
    { 15471597, 657 }, // 48.99, 9.478 x 49.04, 9.53
    { 15471840, 421 }, // 49.67, 8.534 x 49.72, 8.586
    { 15472767, 1509 }, // 48.36, 9.95 x 48.41, 10
    { 15472853, 1509 }, // 48.36, 10 x 48.41, 10.05
    { 15472938, 1509 }, // 48.41, 9.95 x 48.46, 10
    { 15473024, 1509 }, // 48.41, 10 x 48.46, 10.05
    { 15474341, 2034 }, // 49.41, 11.05 x 49.46, 11.1
    { 15475485, 731 }, // 45.42, 12.2 x 45.48, 12.26
    { 15475528, 731 }, // 45.48, 12.2 x 45.53, 12.26
    { 15478892, 2849 }, // 48.1, 11.57 x 48.15, 11.63
    { 15478893, 151 }, // 48.15, 11.57 x 48.2, 11.63
    { 15480189, Bucket(3409) }, // 50.88, 11.57 x 50.93, 11.63
    { 15480318, 651 }, // 50.82, 12.05 x 50.88, 12.1
    { 15485474, 708 }, // 50.93, 10.68 x 50.98, 10.74
    { 15491112, Bucket(3409) }, // 50.93, 11.57 x 50.98, 11.63
    { 15491639, 126 }, // 51.3, 12.36 x 51.35, 12.41
    { 15491682, 126 }, // 51.35, 12.36 x 51.4, 12.41
    { 15491754, 1513 }, // 50.93, 12.89 x 50.98, 12.94
    { 15491962, Bucket(3413) }, // 52.4, 12.47 x 52.45, 12.52
    { 15492048, Bucket(3413) }, // 52.4, 12.52 x 52.45, 12.57
    { 15492602, 55 }, // 54.07, 12.05 x 54.13, 12.1
    { 15493636, Bucket(3416) }, // 51.03, 13.78 x 51.09, 13.83
    { 15493853, Bucket(3419) }, // 51.72, 14.3 x 51.77, 14.35
    { 15494024, Bucket(3423) }, // 51.77, 14.3 x 51.82, 14.35
    { 15494909, 585 }, // 53.39, 14.51 x 53.45, 14.56
    { 15500734, 329 }, // 47.05, 15.4 x 47.1, 15.45
    { 15501076, Bucket(3426) }, // 47.05, 15.45 x 47.1, 15.51
    { 15509342, Bucket(3429) }, // 47.47, 18.97 x 47.52, 19.02
    { 15509364, Bucket(3433) }, // 47.47, 19.02 x 47.52, 19.07
    { 15509369, 479 }, // 47.42, 19.12 x 47.47, 19.18
    { 15509743, 409 }, // 44.79, 20.44 x 44.85, 20.49
    { 15514553, 2142 }, // 48.67, 21.22 x 48.73, 21.27
    { 15516928, 591 }, // 53.45, 14.62 x 53.5, 14.67
    { 15518159, 1226 }, // 52.34, 16.87 x 52.4, 16.92
    { 15518170, 1226 }, // 52.4, 16.87 x 52.45, 16.92
    { 15518181, 1317 }, // 52.34, 16.92 x 52.4, 16.98
    { 15518192, 1317 }, // 52.4, 16.92 x 52.45, 16.98
    { 15524597, 2229 }, // 51.72, 19.44 x 51.77, 19.49
    { 15524768, 2229 }, // 51.77, 19.44 x 51.82, 19.49
    { 15567871, Bucket(3438) }, // 59.26, 17.92 x 59.32, 17.97
    { 15568554, Bucket(3441) }, // 59.32, 17.92 x 59.37, 17.97
    { 15574016, 2676 }, // 59.32, 17.97 x 59.37, 18.02
    { 15599006, Bucket(3445) }, // 47.05, 21.9 x 47.1, 21.96
    { 15609792, Bucket(3448) }, // 47.15, 27.62 x 47.21, 27.67
    { 15626045, 2668 }, // 53.81, 27.51 x 53.86, 27.57
    { 15626088, 2668 }, // 53.86, 27.51 x 53.92, 27.57
    { 15666862, Bucket(3451) }, // 59.42, 24.63 x 59.47, 24.68
    { 37088620, 2634 }, // 13.7, 100.5 x 13.76, 100.5
    { 37835467, 2970 }, // 41.33, 36.16 x 41.39, 36.22
    { 37870335, 1714 }, // 41.65, 44.76 x 41.7, 44.81
    { 37899197, 2821 }, // 25.29, 51.42 x 25.34, 51.47
    { 37899243, 2489 }, // 25.4, 51.47 x 25.45, 51.53
    { 37904660, 2414 }, // 25.24, 51.53 x 25.29, 51.58
    { 38034296, 3016 }, // 55.75, 37.58 x 55.8, 37.63
    { 38171119, 2799 }, // 55.7, 52.31 x 55.75, 52.36
    { 38206711, 1660 }, // 56.75, 60.6 x 56.8, 60.65
    { 38723305, 420 }, // 56.43, 84.98 x 56.49, 85.03
    { 40024447, 1425 }, // 22.35, 114 x 22.41, 114
    { 40024532, 351 }, // 22.3, 114 x 22.35, 114.1
    { 40024533, Bucket(3454) }, // 22.35, 114 x 22.41, 114.1
    { 40025216, Bucket(3454) }, // 22.41, 114 x 22.46, 114.1
    { 40044672, 2466 }, // 30.8, 104 x 30.85, 104
    { 40384186, 1805 }, // 22.62, 120.3 x 22.67, 120.3
    { 40444842, 1757 }, // 31.63, 120.3 x 31.69, 120.3
    { 40446208, 1757 }, // 31.63, 120.3 x 31.69, 120.4
    { 40571221, 1769 }, // 35.78, 128.7 x 35.83, 128.8
    { 40576486, 1274 }, // 33.84, 132.7 x 33.89, 132.8
    { 40581857, 1632 }, // 34.62, 135.2 x 34.68, 135.3
    { 40581860, 1632 }, // 34.68, 135.2 x 34.73, 135.3
    { 40581862, 1631 }, // 34.68, 135.3 x 34.73, 135.3
    { 40605957, 2253 }, // 35.15, 137.1 x 35.2, 137.1
    { 40612326, 2157 }, // 35.51, 139.4 x 35.57, 139.5
    { 40612340, 2150 }, // 35.72, 139.4 x 35.78, 139.4
    { 40612676, 1649 }, // 35.51, 139.6 x 35.57, 139.7
    { 40612701, 2149 }, // 35.78, 139.7 x 35.83, 139.8
    { 40613410, 2177 }, // 35.83, 139.9 x 35.88, 139.9
    { 25933824, 1821 }, // 25.76, -100.3 x 25.79, -100.3
    { 26253071, 1027 }, // 47.23, -122.5 x 47.26, -122.4
    { 26253093, 1027 }, // 47.23, -122.4 x 47.26, -122.4
    { 27683990, 436 }, // 35.15, -90.01 x 35.17, -89.98
    { 28142893, 2040 }, // 42.2, -83.37 x 42.23, -83.35
    { 28143389, 891 }, // 42.3, -83.06 x 42.33, -83.03
    { 28143432, 891 }, // 42.33, -83.06 x 42.36, -83.03
    { 28285952, 1882 }, // 40.02, -75.14 x 40.05, -75.12
    { 59602602, 1501 }, // 43.38, -3.027 x 43.41, -3
    { 59722010, 1447 }, // 41.39, 2.111 x 41.41, 2.138
    { 59722038, 1207 }, // 41.44, 2.164 x 41.47, 2.19
    { 59758968, 1429 }, // 43.27, 5.546 x 43.3, 5.572
    { 60458445, 1058 }, // 45.76, 4.812 x 45.79, 4.838
    { 60469317, 2458 }, // 46.18, 6.227 x 46.21, 6.253
    { 60469695, 1176 }, // 46.5, 6.62 x 46.52, 6.647
    { 60469738, 1176 }, // 46.52, 6.62 x 46.55, 6.647
    { 60470037, 1176 }, // 46.5, 6.647 x 46.52, 6.673
    { 60470080, 1176 }, // 46.52, 6.647 x 46.55, 6.673
    { 60500687, 1002 }, // 51.22, 4.418 x 51.24, 4.445
    { 60523536, 1355 }, // 51.87, 4.549 x 51.9, 4.576
    { 61197503, 624 }, // 41.88, 12.49 x 41.91, 12.52
    { 61281621, 608 }, // 40.84, 14.62 x 40.86, 14.64
    { 61743317, 1545 }, // 31.19, 29.92 x 31.22, 29.95
    { 61818977, 2180 }, // 41.1, 28.98 x 41.12, 29.01
    { 61818984, 2931 }, // 41.07, 29.03 x 41.1, 29.06
    { 61871532, 184 }, // 47.21, 8.272 x 47.23, 8.298
    { 61871535, 459 }, // 47.23, 8.298 x 47.26, 8.324
    { 61871952, 2305 }, // 47.47, 8.324 x 47.49, 8.35
    { 61871978, Bucket(3458) }, // 47.36, 8.508 x 47.39, 8.534
    { 61873508, 2019 }, // 47.42, 8.849 x 47.44, 8.875
    { 61873509, 2019 }, // 47.44, 8.849 x 47.47, 8.875
    { 61873520, 2019 }, // 47.47, 8.849 x 47.49, 8.875
    { 61873521, 2019 }, // 47.49, 8.849 x 47.52, 8.875
    { 61873522, 2509 }, // 47.47, 8.875 x 47.49, 8.901
    { 61873523, 2509 }, // 47.49, 8.875 x 47.52, 8.901
    { 61873570, 2567 }, // 47.15, 9.084 x 47.18, 9.111
    { 61873571, 2567 }, // 47.18, 9.084 x 47.21, 9.111
    { 61873574, 2567 }, // 47.21, 9.084 x 47.23, 9.111
    { 61873575, 2567 }, // 47.23, 9.084 x 47.26, 9.111
    { 61873586, 2567 }, // 47.26, 9.084 x 47.28, 9.111
    { 61873587, 2567 }, // 47.28, 9.084 x 47.31, 9.111
    { 61873590, 2567 }, // 47.31, 9.084 x 47.34, 9.111
    { 61873591, 2567 }, // 47.34, 9.084 x 47.36, 9.111
    { 61873634, 2567 }, // 47.36, 9.084 x 47.39, 9.111
    { 61873635, 2567 }, // 47.39, 9.084 x 47.42, 9.111
    { 61873638, 2567 }, // 47.42, 9.084 x 47.44, 9.111
    { 61873639, 2567 }, // 47.44, 9.084 x 47.47, 9.111
    { 61879509, 2566 }, // 47.13, 9.792 x 47.15, 9.818
    { 61879621, 2860 }, // 47.44, 9.583 x 47.47, 9.609
    { 61884391, 372 }, // 49.12, 8.665 x 49.15, 8.691
    { 61884392, 1123 }, // 49.04, 8.691 x 49.07, 8.717
    { 61885691, 1737 }, // 48.75, 9.137 x 48.78, 9.163
    { 61885882, 153 }, // 48.94, 9.137 x 48.96, 9.163
    { 61886033, 1737 }, // 48.75, 9.163 x 48.78, 9.189
    { 61886360, 153 }, // 48.94, 9.425 x 48.96, 9.451
    { 61889536, 538 }, // 50.09, 8.744 x 50.12, 8.77
    { 61898102, 2855 }, // 50.88, 10.55 x 50.9, 10.58
    { 61973999, 123 }, // 52.48, 13.33 x 52.5, 13.36
    { 62023132, 291 }, // 49.2, 16.56 x 49.22, 16.58
    { 62072639, 1635 }, // 52.37, 16.9 x 52.4, 16.92
    { 62072682, 1635 }, // 52.4, 16.9 x 52.42, 16.92
    { 62072725, 1635 }, // 52.37, 16.92 x 52.4, 16.95
    { 62271487, 245 }, // 59.29, 17.94 x 59.32, 17.97
    { 62296064, 244 }, // 59.32, 17.97 x 59.34, 18
    { 151255697, 1063 }, // 29.25, 47.96 x 29.28, 47.99
    { 151341957, 2970 }, // 41.36, 36.22 x 41.39, 36.24
    { 151860305, 1723 }, // 40.36, 49.85 x 40.39, 49.87
    { 152137151, 1106 }, // 55.73, 37.66 x 55.75, 37.68
    { 152137194, 1106 }, // 55.75, 37.66 x 55.78, 37.68
    { 152137493, 1106 }, // 55.73, 37.68 x 55.75, 37.71
    { 152137536, 1106 }, // 55.75, 37.68 x 55.78, 37.71
    { 162305944, 1273 }, // 33.84, 132.7 x 33.86, 132.8
    { 162324783, Bucket(3461) }, // 34.65, 133.9 x 34.68, 133.9
    { 162450911, 2177 }, // 35.8, 139.9 x 35.83, 139.9
    { 172124673, 2266 }, // -32.93, 151.8 x -32.91, 151.8
    { 103729834, 1821 }, // 25.76, -100.3 x 25.78, -100.3
    { 113170325, 276 }, // 40.74, -73.99 x 40.76, -73.98
    { 153713678, 1817 }, // -30, -51.2 x -29.98, -51.18
    { 153713700, 1817 }, // -30, -51.18 x -29.98, -51.17
    { 238342614, 1754 }, // 40.42, -3.721 x 40.43, -3.708
    { 239030251, 695 }, // 43.29, 5.375 x 43.3, 5.388
    { 245170176, 609 }, // 40.86, 14.62 x 40.88, 14.63
    { 247275642, 2809 }, // 41.02, 28.97 x 41.03, 28.98
    { 247275729, 2808 }, // 41.03, 28.98 x 41.05, 28.99
    { 247486136, 184 }, // 47.21, 8.298 x 47.22, 8.311
    { 247494047, 2509 }, // 47.46, 8.888 x 47.47, 8.901
    { 247494272, 2533 }, // 47.15, 9.058 x 47.17, 9.071
    { 247494273, 2533 }, // 47.17, 9.058 x 47.18, 9.071
    { 247494275, 2567 }, // 47.17, 9.071 x 47.18, 9.084
    { 247494276, 2533 }, // 47.18, 9.058 x 47.19, 9.071
    { 247494277, 2533 }, // 47.19, 9.058 x 47.21, 9.071
    { 247494278, 2567 }, // 47.18, 9.071 x 47.19, 9.084
    { 247494279, 2567 }, // 47.19, 9.071 x 47.21, 9.084
    { 247494288, 2533 }, // 47.21, 9.058 x 47.22, 9.071
    { 247494289, 2533 }, // 47.22, 9.058 x 47.23, 9.071
    { 247494290, 2567 }, // 47.21, 9.071 x 47.22, 9.084
    { 247494291, 2567 }, // 47.22, 9.071 x 47.23, 9.084
    { 247494292, 2533 }, // 47.23, 9.058 x 47.25, 9.071
    { 247494293, 2533 }, // 47.25, 9.058 x 47.26, 9.071
    { 247494294, 2567 }, // 47.23, 9.071 x 47.25, 9.084
    { 247494295, 2567 }, // 47.25, 9.071 x 47.26, 9.084
    { 247494336, 2533 }, // 47.26, 9.058 x 47.27, 9.071
    { 247494337, 2533 }, // 47.27, 9.058 x 47.28, 9.071
    { 247494338, 2567 }, // 47.26, 9.071 x 47.27, 9.084
    { 247494339, 2567 }, // 47.27, 9.071 x 47.28, 9.084
    { 247494340, 2533 }, // 47.28, 9.058 x 47.3, 9.071
    { 247494341, 2533 }, // 47.3, 9.058 x 47.31, 9.071
    { 247494342, 2567 }, // 47.28, 9.071 x 47.3, 9.084
    { 247494343, 2567 }, // 47.3, 9.071 x 47.31, 9.084
    { 247494352, 2533 }, // 47.31, 9.058 x 47.32, 9.071
    { 247494353, 2533 }, // 47.32, 9.058 x 47.34, 9.071
    { 247494354, 2567 }, // 47.31, 9.071 x 47.32, 9.084
    { 247494355, 2567 }, // 47.32, 9.071 x 47.34, 9.084
    { 247494356, 2533 }, // 47.34, 9.058 x 47.35, 9.071
    { 247494357, 2533 }, // 47.35, 9.058 x 47.36, 9.071
    { 247494358, 2567 }, // 47.34, 9.071 x 47.35, 9.084
    { 247494359, 2567 }, // 47.35, 9.071 x 47.36, 9.084
    { 247494528, 2533 }, // 47.36, 9.058 x 47.38, 9.071
    { 247494529, 2533 }, // 47.38, 9.058 x 47.39, 9.071
    { 247494530, 2567 }, // 47.36, 9.071 x 47.38, 9.084
    { 247494531, 2567 }, // 47.38, 9.071 x 47.39, 9.084
    { 247494532, 2533 }, // 47.39, 9.058 x 47.4, 9.071
    { 247494533, 2533 }, // 47.4, 9.058 x 47.42, 9.071
    { 247494534, 2567 }, // 47.39, 9.071 x 47.4, 9.084
    { 247494535, 2567 }, // 47.4, 9.071 x 47.42, 9.084
    { 247494544, 2533 }, // 47.42, 9.058 x 47.43, 9.071
    { 247494545, 2533 }, // 47.43, 9.058 x 47.44, 9.071
    { 247494546, 2567 }, // 47.42, 9.071 x 47.43, 9.084
    { 247494547, 2567 }, // 47.43, 9.071 x 47.44, 9.084
    { 247494548, 2533 }, // 47.44, 9.058 x 47.46, 9.071
    { 247494550, 2567 }, // 47.44, 9.071 x 47.46, 9.084
    { 247494551, 2567 }, // 47.46, 9.071 x 47.47, 9.084
    { 248011755, 2820 }, // 47.06, 15.44 x 47.08, 15.45
    { 248017217, 2820 }, // 47.06, 15.45 x 47.08, 15.47
    { 248291072, 1635 }, // 52.4, 16.92 x 52.41, 16.94
    { 249755989, Bucket(3448) }, // 47.14, 27.62 x 47.15, 27.63
    { 606387153, 2487 }, // 25.3, 51.42 x 25.32, 51.43
    { 646361821, 2166 }, // 25.12, 121.5 x 25.13, 121.5
    { 646361992, 2166 }, // 25.13, 121.5 x 25.15, 121.5
    { 647899818, 1645 }, // 37.51, 127 x 37.52, 127
    { 688497326, 2266 }, // -32.93, 151.8 x -32.92, 151.8
    { 947054399, 410 }, // 38.71, -9.141 x 38.71, -9.135
    { 947054442, 410 }, // 38.71, -9.141 x 38.72, -9.135
    { 947054485, 410 }, // 38.71, -9.135 x 38.71, -9.128
    { 947054528, 410 }, // 38.71, -9.135 x 38.72, -9.128
    { 979168146, 727 }, // 41.83, 12.89 x 41.84, 12.9
    { 987895808, 1545 }, // 31.22, 29.92 x 31.22, 29.93
    { 989977099, 2567 }, // 47.16, 9.078 x 47.17, 9.084
    { 990221653, 538 }, // 50.08, 8.744 x 50.09, 8.75
    { 990309034, 1499 }, // 48.41, 11.25 x 48.42, 11.26
    { 1002874883, 3023 }, // 61, 24.48 x 61.01, 24.49
    { 2596894943, 1273 }, // 33.83, 132.8 x 33.84, 132.8
    { 2598693247, 1630 }, // 35.19, 136.9 x 35.2, 136.9
    { 2598693930, 1630 }, // 35.2, 136.9 x 35.21, 136.9
    { 4294967295, Bucket(3464) }, // 339.5, 249.5 x 339.5, 249.5
};
}
