/*
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
    "SFM6\0"
    "LS\0"
    "24E\0"
    "S7\0"
    "S5\0"
    "S8\0"
    "S2\0"
    "S11\0"
    "M13\0"
    "S1\0"
    "M10\0"
    "L21\0"
    "U13\0"
    "63\0"
    "S61\0"
    "S68\0"
    "62\0"
    "437\0"
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
    "872\0"
    "U76\0"
    "U77\0"
    "S60\0"
    "S3\0"
    "67\0"
    "N27\0"
    "M17\0"
    "S50\0"
    "U79\0"
    "S24\0"
    "WLB\0"
    "58\0"
    "S6\0"
    "RT1\0"
    "65\0"
    "S4\0"
    "SMG\0"
    "RS 1\0"
    "U55\0"
    "FXC\0"
    "T1 A\0"
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
    "Overground\0"
    "LSM\0"
    "ALM\0"
    "LU\0"
    "LGR9\0"
    "614P\0"
    "LGR\0"
    "196\0"
    "86\0"
    "U49\0"
    "M2\0"
    "M3\0"
    "841-859\0"
    "181 (SN)\0"
    "S85\0"
    "FL4\0"
    "FL1\0"
    "FL2\0"
    "ML3\0"
    "109\0"
    "PH\0"
    "57\0"
    "Atlantic City\0"
    "North Jersey Coast\0"
    "48\0"
    "L22\0"
    "U43\0"
    "U41\0"
    "IK\0"
    "C-5\0"
    "ISL\0"
    "TCL\0"
    "AEL\0"
    "WRL\0"
    "EAL\0"
    "TML\0"
    "28E\0"
    "S9\0"
    "Green\0"
    "SHM\0"
    "FKN\0"
    "PKM\0"
    "CBE\0"
    "GWY\0"
    "C-1\0"
    "STB\0"
    "U35\0"
    "SIR1\0"
    "Q\0"
    "Bx\0"
    "L9\0"
    "1E\0"
    "RT2\0"
    "N3\0"
    "156\0"
    "S47\0"
    "215\0"
    "6T\0"
    "S13\0"
    "MD-W\0"
    "D1\0"
    "N10\0"
    "N4\0"
    "N1\0"
    "H5\0"
    "64\0"
    "Raritan Valley\0"
    "?\0"
    "DRL\0"
    "N82\0"
    "Harlem\0"
    "100s, 900s (A700s)\0"
    "200s\0"
    "Hudson\0"
    "Port Jervis\0"
    "400s\0"
    "SFMA\0"
    "308\0"
    "310\0"
    "306\0"
    "302\0"
    "301\0"
    "S 5\0"
    "Port Jefferson\0"
    "New Haven\0"
    "VMLR\0"
    "300s\0"
    "Oyster Bay\0"
    "S31\0"
    "25N\0"
    "Kingston/Plymouth Line\0"
    "Needham Line\0"
    "Fairmount Line\0"
    "Greenbush Line\0"
    "Middleborough/Lakeville Line\0"
    "Framingham/Worcester Line\0"
    "H7\0"
    "Main\0"
    "Gladstone\0"
    "Bergen County\0"
    "Morristown\0"
    "Montclair-Boonton\0"
    "DOY\0"
    "WAR\0"
    "840-860\0"
    "892\0"
    "894\0"
    "890\0"
    "895\0"
    "891\0"
    "893\0"
    "879\0"
    "871\0"
    "877\0"
    "883\0"
    "873\0"
    "875\0"
    "881\0"
    "870\0"
    "880\0"
    "874\0"
    "876\0"
    "878\0"
    "12E\0"
    "15E\0"
    "S26\0"
    "398\0"
    "S33\0"
    "N19\0"
    "S10\0"
    "300-315\0"
    "199\0"
    "M Line\0"
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
    "UFD\0"
    "СТ\0"
    "2 Салтівська\0"
    "SSL\0"
    "CGB\0"
    "SBY\0"
    "WIL\0"
    "WER\0"
    "Z30\0"
    "HBE\0"
    "LIL\0"
    "Port Washington\0"
    "SG\0"
    "U75\0"
    "U78\0"
    "S20\0"
    "FC1\0"
    "FC2\0"
    "FC3\0"
    "FL5\0"
    "FL6\0"
    "FL7\0"
    "FL8\0"
    "87\0"
    "901\0"
    "888\0"
    "Γ3\0"
    "7bis\0"
    "Brown\0"
    "Orange\0"
    "Scala mobile\0"
    "S 8\0"
    "RS 4\0"
    "U44\0"
    "PAO\0"
    "429\0"
    "Meadowlands\0"
    "Pascack Valley\0"
    "U46\0"
    "T5\0"
    "C-8\0"
    "Metropolitana\0"
    "Pink\0"
    "U47\0"
    "MRT Purple\0"
    "4S\0"
    "TRE\0"
    "803\0"
    "801\0"
    "425\0"
    "443\0"
    "441\0"
    "439\0"
    "433\0"
    "431\0"
    "427\0"
    "435\0"
    "M-LINE\0"
    "S 7\0"
    "RS 3\0"
    "STY\0"
    "800s\0"
    "600s (A500s, A700s)\0"
    "700s\0"
    "S40\0"
    "S32\0"
    "UP-N\0"
    "MD-N\0"
    "NCS\0"
    "UP-NW\0"
    "UP-W\0"
    "BNSF\0"
    "HC\0"
    "RI\0"
    "SWS\0"
    "ME\0"
    "RS 2\0"
    "L13\0"
    "LBN\0"
    "1707\0"
    "1703\0"
    "1701\0"
    "S 5X\0"
    "Metrotranvía\0"
    "PM\0"
    "LBS\0"
    "T3\0"
    "T3b\0"
    "Rhônexpress\0"
    "T4\0"
    "LGR7\0"
    "LGR6\0"
    "LGR5\0"
    "Line 3\0"
    "West Hempstead\0"
    "KTL\0"
    "HBB\0"
    "T8\0"
    "Blue Line\0"
    "197\0"
    "100\0"
    "BR\0"
    "C11\0"
    "S19\0"
    "S21\0"
    "Red Line\0"
    "Gold Line\0"
    "Luas Green Line\0"
    "Providence/Stoughton Line\0"
    "Franklin Line\0"
    "TRAB\0"
    "Montauk\0"
    "Babylon\0"
    "54\0"
    "53\0"
    "NS\0"
    "m2\0"
    "T6\0"
    "L10\0"
    "L11\0"
    "L9 Nord\0"
    "Tren Urbano\0"
    "A2\0"
    "Tide\0"
    "TECO\0"
    "401-689\0"
    "400-698\0"
    "G10\0"
    "S72\0"
    "S30\0"
    "G43\0"
    "S36\0"
    "S355\0"
    "S34\0"
    "S80\0"
    "U17\0"
    "WTR\0"
    "C-3\0"
    "24G\0"
    "BLSV\0"
    "Π3\0"
    "A1\0"
    "E-W\0"
    "S-N\0"
    "R60\0"
    "R50\0"
    "U71\0"
    "U83\0"
    "U73\0"
    "U72\0"
    "R2Sud\0"
    "HVL\0"
    "47B\0"
    "R2\0"
    "R3\0"
    "R4\0"
    "R8\0"
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
    "NL2\0"
    "R11\0"
    "R13\0"
    "R14\0"
    "R15\0"
    "SMART\0"
    "Sul\0"
    "BLUE\0"
    "RED\0"
    "GREEN\0"
    "ORANGE\0"
    "620\0"
    "Victoria\0"
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
    "761P\0"
    "SN 5\0"
    "T-A\0"
    "T1 R\0"
    "18E\0"
    "1706\0"
    "705\0"
    "25E\0"
    "CBTU\0"
    "C13\0"
    "L12\0"
    "S14\0"
    "U74\0"
    "Τ5\0"
    "Τ3\0"
    "Τ4\0"
    "S71\0"
    "S81\0"
    "SIL\0"
    "TL-1\0"
    "TL-2\0"
    "8А\0"
    "T3a\0"
    "T7\0"
    "OrlyVAL\0"
    "CDGVAL\0"
    "DART\0"
    "LISA\0"
    "C-2\0"
    "C14\0"
    "C15\0"
    "Central\0"
    "S41\0"
    "RL1\0"
    "3bis\0"
    "I2\0"
    "YL\0"
    "BLLB\0"
    "NWK–WTC\0"
    "Bakerloo\0"
    "Hammersmith & City\0"
    "Circle\0"
    "Waterloo & City\0"
    "Jubilee\0"
    "Metropolitan\0"
    "District\0"
    "NSL\0"
    "Piccadilly\0"
    "Northern\0"
    "MM\0"
    "BGL\0"
    "THZ1\0"
    "M1B\0"
    "M1A\0"
    "DX\0"
    "仙台市南北線 (Sendai Namboku Line)\0"
    "仙台市東西線 (Sendai Tozai Line)\0"
    "4A\0"
    "Verde\0"
    "Laranja\0"
    "Vermelha\0"
    "Amarela\0"
    "Azul\0"
    "Subway\0"
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
    "2B\0"
    "U29\0"
    "U34\0"
    "S 9\0"
    "Z\0"
    "ML1\0"
    "ML2\0"
    "I1\0"
    "R2Nord\0"
    "B1\0"
    "B2\0"
    "C-10\0"
    "C-7\0"
    "Orange Line\0"
    "4a\0"
    "WCE\0"
    "Conexão Metrô-Aeroporto\0"
    "RMGL\0"
    "RD\0"
    "SI\0"
    "BL\0"
    "L1B\0"
    "804\0"
    "805\0"
    "PATCO\0"
    "HOB–WTC\0"
    "HOB–33\0"
    "JSQ–33\0"
    "BSL\0"
    "MFL\0"
    "NHSL\0"
    "Μ1\0"
    "Γ2\0"
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
    "金山(Jinshan)\0"
    "G44\0"
    "Violet Line\0"
    "Yellow Line\0"
    "AEx\0"
    "Magenta Line\0"
    "浦江(Pujiang)\0"
    "802\0"
    "North-South (Red Line)\0"
    "〇\0"
    "Xijiao\0"
    "S 6\0"
    "S15\0"
    "WES\0"
    "S35\0"
    "S29\0"
    "ExpressTram\0"
    "ATS\0"
    "T11\0"
    "Π4\0"
    "Π1\0"
    "Π2\0"
    "25S\0"
    "42X\0"
    "11*\0"
    "TGM\0"
    "43X\0"
    "GC\0"
    "L10 Sud\0"
    "G·J\0"
    "902\0"
    "750\0"
    "SH\0"
    "GG\0"
    "12M\0"
    "56A\0"
    "59A\0"
    "59B\0"
    "SC\0"
    "U16\0"
    "C-4\0"
    "C-9\0"
    "СТ-2\0"
    "Gold\0"
    "NT\0"
    "Aqua Line\0"
    "exo1\0"
    "exo2\0"
    "exo6\0"
    "SR\0"
    "OM\0"
    "TM\0"
    "exo5\0"
    "KD\0"
    "exo3\0"
    "捷運紅線 (新北投支線)\0"
    "RN\0"
    "F3\0"
    "SS\0"
    "JN\0"
    "11AB\0"
    "10AB\0"
    "9AB\0"
    "HN\0"
    "424\0"
    "434\0"
    "428\0"
    "432\0"
    "440\0"
    "444\0"
    "422\0"
    "438\0"
    "436\0"
    "426\0"
    "430\0"
    "442\0"
    "159\0"
    "191\0"
    "135\0"
    "143\0"
    "147\0"
    "139\0"
    "155\0"
    "101\0"
    "193\0"
    "151\0"
    "194\0"
    "192\0"
    "104\0"
    "190\0"
    "138\0"
    "198\0"
    "146\0"
    "134\0"
    "142\0"
    "102\0"
    "150\0"
    "152\0"
    "195\0"
    "103\0"
    "GF\0"
    "TEL\0"
    "D11\0"
    "PURP\0"
    "YELL\0"
    "TT\0"
    "SIR\0"
    "<7>\0"
    "<6>\0"
    "202\0"
    "201\0"
    "502\0"
    "501\0"
    "TWL\0"
    "TKL\0"
    "Yangluo\0"
    "751P\0"
    "NEC\0"
    "CFL\0"
    "C-6\0"
    "NLR\0"
    "NL\0"
    "JFK\0"
    "Norte\0"
    "ARL\0"
    "Silver\0"
    "530\0"
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
    "HBLR\0"
    "JB\0"
    "TJ\0"
    "DT\0"
    "21A\0"
    "OT\0"
    "South\0"
    "1704\0"
    "1700\0"
    "North\0"
    "김포 골드라인\0"
    "Daxing Airport\0"
    "River\0"
    "CMET\0"
    "APT\0"
    "BTS Sukhumvit\0"
    "D2\0"
    "Roch\0"
    "EDid\0"
    "Sh&C\0"
    "Dean\0"
    "Airp\0"
    "Vict\0"
    "MCUK\0"
    "Arcobaleno\0"
    "Asht\0"
    "Eccl\0"
    "Picc\0"
    "Altr\0"
    "Bury\0"
    "ESFECO\0"
    "AIRPORT\0"
    "KS\0"
    "Airtrain\0"
    "Taipa\0"
    "305\0"
    "309\0"
    "316\0"
    "4М\0"
    "3М\0"
    "2М\0"
    "1М\0"
    "RB 32\0"
    "CHW\0"
    "CHE\0"
    "AIR\0"
    "CYN\0"
    "NOR\0"
    "ELW\0"
    "NWK\0"
    "Sado\0"
    "550\0"
    "TEX\0"
    "UP Express\0"
    "Stouffville\0"
    "Richmond Hill\0"
    "Milton\0"
    "Kitchener\0"
    "Barrie\0"
    "Lakeshore East\0"
    "LRT\0"
    "221\0"
    "217\0"
    "TrfC\0"
    "Corn\0"
    "Harbour\0"
    "JSQ–33 via HOB\0"
    "4-6\0"
    "<F>\0"
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
    "Berlin S7.svg\0"
    "S-Bahn-Logo.svg\0"
    "Berlin S75.svg\0"
    "Berlin S5.svg\0"
    "Berlin S8.svg\0"
    "Berlin Tram M10.svg\0"
    "Berlin Tram M13.svg\0"
    "Berlin Tram 21.svg\0"
    "Berlin Tram 63.svg\0"
    "Berlin Tram 61.svg\0"
    "Berlin Tram 68.svg\0"
    "Berlin Tram 62.svg\0"
    "Berlin Tram 37.svg\0"
    "Wien U4.svg\0"
    "U-Bahn Wien.svg\0"
    "Wien U6.svg\0"
    "Stadtbahn.svg\0"
    "Berlin Tram 60.svg\0"
    "Berlin S3.svg\0"
    "Berlin Tram 67.svg\0"
    "Berlin Tram 27.svg\0"
    "Berlin Tram M17.svg\0"
    "Berlin Tram 50.svg\0"
    "S-tog.svg\0"
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
    "München Tram 17.svg\0"
    "München Tram 19.svg\0"
    "München Tram 18.svg\0"
    "Berlin S2.svg\0"
    "Berlin S25.svg\0"
    "Hamburg U3.svg\0"
    "München S1.svg\0"
    "München S6.svg\0"
    "Berlin S46.svg\0"
    "Berlin S45.svg\0"
    "München Tram 15.svg\0"
    "München Tram 25.svg\0"
    "München Tram 12.svg\0"
    "München Tram 16.svg\0"
    "München Tram 27.svg\0"
    "München Tram 20.svg\0"
    "München Tram 21 (2019).svg\0"
    "München Tram 23.svg\0"
    "Hamburg A3.svg\0"
    "Berlin Tram M1.svg\0"
    "TriMet MAX logo.svg\0"
    "TTC - Line 4 - Sheppard line.svg\0"
    "TTC.svg\0"
    "TTC - Line 3 - Scarborough RT line.svg\0"
    "Overground roundel.svg\0"
    "Paris RER C icon.svg\0"
    "RER.svg\0"
    "Logo tramway-budapest.svg\0"
    "Kiev Metro First Line logo.svg\0"
    "Kyiv Metro logo.svg\0"
    "S-Bahn Austria.svg\0"
    "Copenhagen metro logo.svg\0"
    "Kiev Metro Third Line logo.svg\0"
    "Berlin S85.svg\0"
    "TRAM - Metropolitano de Alicante -T-.svg\0"
    "S-train service H.svg\0"
    "SML2.svg\0"
    "Paris Transilien U.svg\0"
    "SML7.svg\0"
    "Paris Transilien K.svg\0"
    "Logo Saarbahn.svg\0"
    "Berlin S9.svg\0"
    "M1-20px.svg\0"
    "Warsaw Metro logo.svg\0"
    "München S5.svg\0"
    "NYCS-bull-trans-G-Std.svg\0"
    "NYCS-bull-trans-7-Std.svg\0"
    "NYCS-bull-trans-S-Std.svg\0"
    "NYCS-bull-trans-N-Std.svg\0"
    "NYCS-bull-trans-Q-Std.svg\0"
    "NYCS-bull-trans-A-Std.svg\0"
    "NYCS-bull-trans-6-Std.svg\0"
    "NYCS-bull-trans-R-Std.svg\0"
    "Paris Transilien P.svg\0"
    "Logo Metropolitane Italia.svg\0"
    "SML11.svg\0"
    "BJS Line 2 icon.svg\0"
    "Beijing Subway icon.svg\0"
    "BJS Line 1 icon.svg\0"
    "BJS Batong Line icon.svg\0"
    "BJS Line 13 icon.svg\0"
    "BKV m 1 jms.svg\0"
    "BKV metro.svg\0"
    "BJS Line 10 icon.svg\0"
    "BJS Line 5 icon.svg\0"
    "BJS Line 8 icon.svg\0"
    "BJS Line 4 icon.svg\0"
    "Guangzhou Metro icon.svg\0"
    "Berlin S1.svg\0"
    "Frankfurt S7.svg\0"
    "Augsburg Tram 2.svg\0"
    "Milano S3.svg\0"
    "Linee S di Milano.svg\0"
    "Milano S1.svg\0"
    "Milano S13.svg\0"
    "Metra Logo.svg\0"
    "Milano S4.svg\0"
    "Milano S2.svg\0"
    "Budapest hev symbol.svg\0"
    "Frankfurt U2.svg\0"
    "BJS Yizhuang Line icon.svg\0"
    "BJS Changping Line icon.svg\0"
    "BJS Fangshan Line icon.svg\0"
    "Moskwa Metro Line 5.svg\0"
    "Логотип метро в системе бренда московского транспорта.svg\0"
    "Moskwa Metro Line 4.svg\0"
    "Moskwa Metro Line 3.svg\0"
    "Moskwa Metro Line 1.svg\0"
    "Línea A (Logo Metro de Medellín).svg\0"
    "Moskwa Metro Line 6.svg\0"
    "Moskwa Metro Line 7.svg\0"
    "Moskwa Metro Line 8.svg\0"
    "Moskwa Metro Line 10.svg\0"
    "Moskwa Metro Line 9.svg\0"
    "Moskwa Metro Line 2.svg\0"
    "Moskwa Metro Line 12.svg\0"
    "Paris Tram 1.svg\0"
    "Paris logo tram jms.svg\0"
    "Línea A (SBASE) bullet.svg\0"
    "Hamburg S1.svg\0"
    "Paris RER D icon.svg\0"
    "Nürnberg U2.svg\0"
    "Hamburg U2.svg\0"
    "Hamburg U1.svg\0"
    "Hamburg S31.svg\0"
    "Kiev Metro Line 2.svg\0"
    "Kiev Metro Line 1.svg\0"
    "Kiev Metro Line 3.svg\0"
    "Kiev T logo.svg\0"
    "Nürnberg U3.svg\0"
    "Nürnberg U1.svg\0"
    "Frankfurt S6.svg\0"
    "Number prefix Randen Arashiyama mainline.png\0"
    "Tokyu SG line symbol.svg\0"
    "Berlin Tram M2.svg\0"
    "München S20.svg\0"
    "München S7.svg\0"
    "CPTM icon.svg\0"
    "Metropolitana di Roma A.svg\0"
    "Metropolitana di Roma B.svg\0"
    "Ferrovia regionale laziale FL1.svg\0"
    "Ferrovia regionale laziale FL2.svg\0"
    "Ferrovia regionale laziale FL5.svg\0"
    "Ferrovia regionale laziale FL6.svg\0"
    "Ferrovia regionale laziale FL7.svg\0"
    "Ferrovia regionale laziale FL8.svg\0"
    "Brussels tramway icon.svg\0"
    "Paris RER A icon.svg\0"
    "CDML1.svg\0"
    "Berlin S47.svg\0"
    "Frankfurt S3.svg\0"
    "Spb metro line1.svg\0"
    "Spb metro logo.svg\0"
    "Spb metro line2.svg\0"
    "Spb metro line3.svg\0"
    "Spb metro line4.svg\0"
    "Spb metro line5.svg\0"
    "Athens Metro Line 3.svg\0"
    "Frankfurt S5.svg\0"
    "Frankfurt S4.svg\0"
    "Paris Metro 7 bis.svg\0"
    "Metro-M.svg\0"
    "Metrorex logo.svg\0"
    "NNMetro.svg\0"
    "Oslo T-bane Logo.svg\0"
    "München Tram 29 (2019).svg\0"
    "Lyon tcl tram-5.svg\0"
    "BJS Line 9 icon.svg\0"
    "BJS Daxing Line icon.svg\0"
    "BJS Line 15 icon.svg\0"
    "Milano linea M5.svg\0"
    "Bart-logo.svg\0"
    "Hamburg U4.svg\0"
    "Línea B (Logo Metro de Medellín).svg\0"
    "Línea C (SBASE) bullet.svg\0"
    "Línea B (SBASE) bullet.svg\0"
    "Montreal Metro.svg\0"
    "Wien U2.svg\0"
    "Metrô-SP icon.svg\0"
    "Wien U1.svg\0"
    "Paris Metro 4.svg\0"
    "Paris Metro 14.svg\0"
    "Paris Metro 1.svg\0"
    "Paris Metro 9.svg\0"
    "München U4.svg\0"
    "Paris Metro 10.svg\0"
    "Paris Metro 6.svg\0"
    "Paris Metro 7.svg\0"
    "Augsburg Tram 1.svg\0"
    "Bremen RS2.svg\0"
    "Bremen RS1.svg\0"
    "STIB-MIVB Line 44.svg\0"
    "STIB-MIVB Line 39.svg\0"
    "Frankfurt S1.svg\0"
    "Frankfurt S2.svg\0"
    "Frankfurt S8.svg\0"
    "Frankfurt S9.svg\0"
    "C-5 yellow.svg\0"
    "STIB-MIVB Line 19.svg\0"
    "München U5.svg\0"
    "München U6.svg\0"
    "München U3.svg\0"
    "Frankfurt U6.svg\0"
    "München U1.svg\0"
    "München U2.svg\0"
    "München U7.svg\0"
    "München U8.svg\0"
    "Kiev Metro Second Line logo.svg\0"
    "Paris Tram 3b.svg\0"
    "Wien U3.svg\0"
    "STIB-MIVB Line 62.svg\0"
    "München Tram 28.svg\0"
    "Logo Metro Rennes.svg\0"
    "STE logo.svg\0"
    "Paris Tram 8.svg\0"
    "STIB-MIVB Line 97.svg\0"
    "BKV m 3 jms.svg\0"
    "Metropolitana di Roma C.svg\0"
    "M2-20px.svg\0"
    "Logo MetroRio.svg\0"
    "S-Bahn Salzburg.svg\0"
    "Amsterdam metro logo.svg\0"
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
    "Barcelona Metro Logo.svg\0"
    "L9 barcelona.svg\0"
    "Hamburg S21.svg\0"
    "Hamburg A2.svg\0"
    "Number prefix Toyo-Rapid.svg\0"
    "C-3 dark pink.svg\0"
    "The seal of Mass Rapid Transit Bureau, Kaohsiung City Government 20140108.svg\0"
    "Hamburg S11.svg\0"
    "Hamburg S2.svg\0"
    "Hamburg S3.svg\0"
    "Hamburg A1.svg\0"
    "R2 barcelona.svg\0"
    "Metro Rotterdam logo.svg\0"
    "Map Point.png\0"
    "Metro do Porto linha D.svg\0"
    "Porto Metro logo.svg\0"
    "Metro do Porto linha E.svg\0"
    "Metro do Porto linha F.svg\0"
    "Metro do Porto linha A.svg\0"
    "Metro do Porto linha C.svg\0"
    "CBTU Logo2.svg\0"
    "Metro do Porto linha B.svg\0"
    "Dallas Area Rapid Transit logo.svg\0"
    "Victoria line roundel.svg\0"
    "Underground.svg\0"
    "Wuhan Metro Logo.svg\0"
    "Logo of the Athens Tram (icon only).svg\0"
    "SML1.svg\0"
    "SML5.svg\0"
    "SML3.svg\0"
    "SML6.svg\0"
    "SITEUR T logo.png\0"
    "BioL2lo.png\0"
    "BioL1lo.png\0"
    "Paris Transilien J.svg\0"
    "Paris Tram 4.svg\0"
    "Paris Tram 7.svg\0"
    "Bremen RS3.svg\0"
    "Bremen RS4.svg\0"
    "NYCS-bull-trans-W-Std.svg\0"
    "STIB-MIVB Line 32.svg\0"
    "STIB-MIVB Line 5.svg\0"
    "Brussels Metro Logo.svg\0"
    "STIB-MIVB Line 1.svg\0"
    "München S2.svg\0"
    "STIB-MIVB Line 7.svg\0"
    "STIB-MIVB Line 92.svg\0"
    "Paris Metro 2.svg\0"
    "Central Line roundel.svg\0"
    "Paris RER E icon.svg\0"
    "STIB-MIVB Line 2.svg\0"
    "Berlin S41.svg\0"
    "STIB-MIVB Line 81.svg\0"
    "NMBS S-Trein logo.svg\0"
    "Paris Metro 13.svg\0"
    "Paris Metro 12.svg\0"
    "Paris Metro 11.svg\0"
    "Paris Metro 8.svg\0"
    "Paris Metro 5.svg\0"
    "Paris Metro 3 bis.svg\0"
    "Paris Transilien R.svg\0"
    "Paris Transilien N.svg\0"
    "Paris RER B icon.svg\0"
    "SML4.svg\0"
    "SML8.svg\0"
    "SML9.svg\0"
    "SML13.svg\0"
    "SML10.svg\0"
    "Seoul Metro Line U Line.svg\0"
    "Cleveland RTA logo.svg\0"
    "WMATA Yellow.svg\0"
    "WMATA Metro Logo.svg\0"
    "STIB-MIVB Line 51.svg\0"
    "STIB-MIVB Line 93.svg\0"
    "Helsingin metro logo.svg\0"
    "Bakerloo line roundel.svg\0"
    "H&c line roundel.svg\0"
    "Circle Line roundel.svg\0"
    "W&c line roundel.svg\0"
    "Jubilee line roundel.svg\0"
    "Metropolitan line roundel.svg\0"
    "District line roundel.svg\0"
    "Astram Logo.svg\0"
    "Fukuoka City Subway Logo.svg\0"
    "Piccadilly line roundel.svg\0"
    "Northern line roundel.svg\0"
    "Number prefix Minatomirai.svg\0"
    "Tehran Metro Logo.svg\0"
    "Nagoya Subway Logo V2 (Kamiiida Line).svg\0"
    "Nagoya Municipal Subway Logo.svg\0"
    "Kobe Municipal Subway Logo.svg\0"
    "MRT (Bangkok) logo.svg\0"
    "Lima Metro Linea 1.svg\0"
    "Seoul Metro Line Shinbundang.svg\0"
    "Sendai City Subway Logo.svg\0"
    "Yokohama Municipal Subway Logo.svg\0"
    "Paris Metro 3.svg\0"
    "Logo-Nsk-Metro.svg\0"
    "Ekb metro logo.svg\0"
    "Minsk Metro Line 1.svg\0"
    "Minsk metro logo.svg\0"
    "Minsk Metro Line 2.svg\0"
    "Sofia Metro Logo.svg\0"
    "Metropolitano Lisboa logo.svg\0"
    "Glasgow Subway.svg\0"
    "Metro Almaty line A.svg\0"
    "Almaty metro logo.svg\0"
    "Logo of the Pyongyang Metro.svg\0"
    "Paris Transilien H.svg\0"
    "Kyiv Urban Electric Train.svg\0"
    "Symbole Lille 2.svg\0"
    "Lille Metro Logo 2017.svg\0"
    "Symbole Lille 1.svg\0"
    "Madrid-MetroLinea4.svg\0"
    "MetroMadridLogo.svg\0"
    "Madrid-MetroLinea1.svg\0"
    "Kochi Metro logo.png\0"
    "Madrid-MetroLinea8.svg\0"
    "Madrid-MetroLinea9.svg\0"
    "NYCS-bull-trans-J-Std.svg\0"
    "Madrid-MetroLinea5.svg\0"
    "Madrid-MetroLinea3.svg\0"
    "Madrid-MetroLinea2.svg\0"
    "Madrid-MetroLinea7.svg\0"
    "Madrid-MetroRamal.svg\0"
    "Madrid-MetroLinea12.svg\0"
    "Shijiazhuang Metro.svg\0"
    "Madrid-MetroLinea6.svg\0"
    "Madrid-MetroLinea11.svg\0"
    "Chennai Metro logo.svg\0"
    "Stadtbahn Madrid Logo.svg\0"
    "Incheon Metro Line 1.png\0"
    "STIB-MIVB Line 3.svg\0"
    "C-10 lime.svg\0"
    "C-1 light blue.svg\0"
    "C-7 red.svg\0"
    "Icon-orange-line-default.svg\0"
    "长沙地铁1号线线标.svg\0"
    "AnkarayLogo.png\0"
    "Qingdao Metro Logo no text.svg\0"
    "NBRT Line 2 icon.svg\0"
    "TTC - Line 1 - Yonge-University-Spadina line.svg\0"
    "TTC - Line 2 - Bloor-Danforth line.svg\0"
    "RMRG logo.svg\0"
    "Line1mtymetro.png\0"
    "Line2mtymetro.png\0"
    "Dalian Metro Logo Image Only.svg\0"
    "Shenyang Metro Corporation Logo.svg\0"
    "WMATA Orange.svg\0"
    "WMATA Red.svg\0"
    "WMATA Silver.svg\0"
    "WMATA Blue.svg\0"
    "WMATA Green.svg\0"
    "STIB-MIVB Line 6.svg\0"
    "Mexico City Metro.svg\0"
    "LACMTA Circle D Line.svg\0"
    "Lametro.svg\0"
    "Athens Metro Line 1.svg\0"
    "Athens Metro Line 2.svg\0"
    "Jaipur Metro Logo.png\0"
    "STIB-MIVB Line 4.svg\0"
    "STIB-MIVB Line 25.svg\0"
    "STIB-MIVB Line 55.svg\0"
    "STIB-MIVB Line 82.svg\0"
    "Lrtalogo.svg\0"
    "ST Logo.svg\0"
    "Logo of Tokyo Metro Marunouchi Line.svg\0"
    "Tokyo Metro logo.svg\0"
    "Seoul Metro Line Suin.svg\0"
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
    "Logo of Tokyo Metro Hanzōmon Line.svg\0"
    "Logo of Tokyo Metro Fukutoshin Line.svg\0"
    "Osaka Metro Sennichimae line symbol.svg\0"
    "Osaka Metro Imazatosuji line symbol.svg\0"
    "Osaka Metro Sakaisuji line symbol.svg\0"
    "Osaka Metro Nagahori Tsurumi-ryokuchi line symbol.svg\0"
    "Osaka Metro Yotsubashi line symbol.svg\0"
    "Subway KyotoKarasuma.svg\0"
    "Kyoto MTB Logo.svg\0"
    "Subway KyotoTozai.png\0"
    "Nagoya Subway Logo V2 (Sakura-dori Line).svg\0"
    "Nagoya Subway Logo V2 (Higashiyama Line).svg\0"
    "Nagoya Subway Logo V2 (Meiko Line).svg\0"
    "Nagoya Subway Logo V2 (Tsurumai Line).svg\0"
    "R1 barcelona.svg\0"
    "Nagoya Subway Logo V2 (Meijo Line).svg\0"
    "Kolkata Metro Logo.svg\0"
    "Delhi Metro logo.svg\0"
    "LACMTA Circle B Line.svg\0"
    "CDML7.svg\0"
    "CDML3.svg\0"
    "CDML2.svg\0"
    "CDML4.svg\0"
    "NBRT Line 1 icon.svg\0"
    "Amoy Metro logo.svg\0"
    "Logo Paris tram ligne11 SNCF.svg\0"
    "Paris Transilien L.svg\0"
    "Seoul Metro Line Bundang.svg\0"
    "Milano S5.svg\0"
    "Milano S6.svg\0"
    "Seoul Metro Line Seohae Bilingual.svg\0"
    "Seoul Metro Line Gyeonggang.svg\0"
    "Milano S8.svg\0"
    "Milano S9.svg\0"
    "Milano S11.svg\0"
    "C-4 dark blue.svg\0"
    "C-9 orange.svg\0"
    "C-2 green.svg\0"
    "Tokyu TY line symbol.svg\0"
    "Tokyu OM line symbol.svg\0"
    "Tokyu IK line symbol.svg\0"
    "Tokyu TM line symbol.svg\0"
    "Tokyu KD line symbol.svg\0"
    "New Shuttle Line symbol.svg\0"
    "Znak T-23g.svg\0"
    "Berlin S26.svg\0"
    "TfNSW M.svg\0"
    "Number prefix Hankai Tramway line.png\0"
    "Osaka Metro Nanko Port Town line symbol.svg\0"
    "NYCS-bull-trans-1-Std.svg\0"
    "NYCS-bull-trans-2-Std.svg\0"
    "NYCS-bull-trans-3-Std.svg\0"
    "NYCS-bull-trans-4-Std.svg\0"
    "NYCS-bull-trans-5-Std.svg\0"
    "NYCS-bull-trans-M-Std.svg\0"
    "NYCS-bull-trans-L-Std.svg\0"
    "Ligne Trillium Line logo.svg\0"
    "NYCS-bull-trans-B-Std.svg\0"
    "NYCS-bull-trans-F-Std.svg\0"
    "NYCS-bull-trans-C-Std.svg\0"
    "NYCS-bull-trans-D-Std.svg\0"
    "NYCS-bull-trans-E-Std.svg\0"
    "VTA light rail Alum Rock–Santa Teresa line logo.svg\0"
    "Berlin S42.svg\0"
    "S-train service A.svg\0"
    "Moskwa Metro Line 15.svg\0"
    "Tokyu MG line symbol.svg\0"
    "JR JL line symbol.svg\0"
    "Tobu Tojo Line (TJ) symbol.svg\0"
    "Tokyu DT line symbol.svg\0"
    "Ottawa - Line 1 Confederation Line.svg\0"
    "JinanMetro Logo.svg\0"
    "Samara Metro logo.svg\0"
    "JR JB line symbol.svg\0"
    "Xuzhou Metro Logo.svg\0"
    "Macau LRT 2019 logo.svg\0"
    "Bcr logo.svg\0"
    "GO Milton logo.svg\0"
    "GO Kitchener logo.svg\0"
    "GO Barrie logo.svg\0"
    "GO Lakeshore East logo.svg\0"
    "GO Lakeshore West logo.svg\0"
    "Milano linea M2.svg\0"
    "Milano linea M3.svg\0"
    "Milano linea M1.svg\0"
    "Tobu Skytree Line (TS) symbol.svg\0"
};

static const constexpr uint16_t NoLogo = 18;

static const constexpr LineMetaDataContent line_data[] = {
    { 1, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf38bb9} }, // 70 OSM: 9056 WD: Q6811967 -37.84, 144.9 x -37.81, 145.1
    { 5, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009fda} }, // 75 OSM: 9057 WD: Q6811970 -37.86, 144.9 x -37.81, 145.2
    { 8, 0, 19, LineMetaDataContent::Tramway, Color{0xbb0000} }, // M4 OSM: 11134 WD: Q62512299 52.52, 13.4 x 52.57, 13.53
    { 11, 33, 19, LineMetaDataContent::Tramway, Color{0xcc9933} }, // M5 OSM: 11135 WD: Q62512324 52.52, 13.36 x 52.57, 13.52
    { 15, 52, 19, LineMetaDataContent::Tramway, Color{0x996699} }, // 12 OSM: 11140 WD: Q65954567 52.52, 13.38 x 52.56, 13.47
    { 18, 71, 19, LineMetaDataContent::Tramway, Color{0xff6633} }, // M8 OSM: 11141 WD: Q62512359 52.52, 13.36 x 52.57, 13.58
    { 22, 90, 19, LineMetaDataContent::Tramway, Color{0xff6633} }, // 18 OSM: 11142 WD: Q62554449 52.53, 13.54 x 52.55, 13.62
    { 26, 109, 19, LineMetaDataContent::Tramway, Color{0x006699} }, // 16 OSM: 11143 WD: Q62476614 52.51, 13.47 x 52.57, 13.58
    { 31, 128, 19, LineMetaDataContent::Tramway, Color{0x003388} }, // M6 OSM: 11145 WD: Q62511960 52.52, 13.4 x 52.55, 13.62
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 2 OSM: 11201 WD: Q1854674 51.17, 4.35 x 51.26, 4.464
    { 35, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa70049} }, // S OSM: 14163 -37.07, 174.8 x -36.84, 174.9
    { 39, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfec330} }, // E OSM: 14165 -37, 174.8 x -36.84, 174.9
    { 41, 147, 161, LineMetaDataContent::RapidTransit, Color{0x8070b7} }, // S7 OSM: 14809 WD: Q7388362 52.39, 13.07 x 52.57, 13.57
    { 4, 177, 161, LineMetaDataContent::RapidTransit, Color{0x8070b7} }, // S75 OSM: 14810 WD: Q3744483 52.5, 13.43 x 52.57, 13.54
    { 44, 192, 161, LineMetaDataContent::RapidTransit, Color{0xf25721} }, // S5 OSM: 14811 WD: Q3743008 52.5, 13.28 x 52.59, 13.91
    { 47, 206, 161, LineMetaDataContent::RapidTransit, Color{0x52b447} }, // S8 OSM: 14984 WD: Q4048678 52.35, 13.29 x 52.69, 13.63
    { 50, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x9313ba} }, // S2 OSM: 16111 48.95, 8.283 x 49.11, 8.505
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xb3ee3a} }, // 1 OSM: 17413 WD: Q318073 51.49, 10.79 x 51.52, 10.8
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x2e8b57} }, // 2 OSM: 17415 WD: Q318073 51.5, 10.78 x 51.51, 10.82
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x996633} }, // 3 OSM: 17839 48.99, 8.347 x 49.04, 8.411
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 1 OSM: 17840 48.98, 8.347 x 49.02, 8.479
    { 53, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // S11 OSM: 17842 48.87, 8.373 x 49.13, 8.518
    { 61, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // S1 OSM: 17843 48.8, 8.373 x 49.13, 8.458
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x18a6d9} }, // 5 OSM: 17847 49, 8.347 x 49.02, 8.444
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffcc00} }, // 4 OSM: 17848 48.99, 8.347 x 49.05, 8.452
    { 47, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x6d682a} }, // S8 OSM: 17849 48.46, 8.215 x 49.01, 8.435
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff9933} }, // 8 OSM: 17855 48.98, 8.452 x 49, 8.479
    { 64, 220, 19, LineMetaDataContent::Tramway, Color{0x108449} }, // M10 OSM: 17865 WD: Q62500489 52.5, 13.36 x 52.54, 13.45
    { 57, 240, 19, LineMetaDataContent::Tramway, Color{0x00cc00} }, // M13 OSM: 17884 WD: Q62512599 52.51, 13.34 x 52.56, 13.48
    { 69, 260, 19, LineMetaDataContent::Tramway, Color{0x996699} }, // 21 OSM: 17885 WD: Q62476959 52.45, 13.45 x 52.53, 13.52
    { 72, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xeda5b4} }, // U13 OSM: 19070 48.76, 9.134 x 48.81, 9.254
    { 76, 279, 19, LineMetaDataContent::Tramway, Color{0x009999} }, // 63 OSM: 19115 WD: Q63996601 52.43, 13.53 x 52.5, 13.61
    { 80, 298, 19, LineMetaDataContent::Tramway, Color{0x669933} }, // 61 OSM: 19265 WD: Q62512736 52.43, 13.53 x 52.46, 13.69
    { 84, 317, 19, LineMetaDataContent::Tramway, Color{0x009933} }, // 68 OSM: 19271 WD: Q62470539 52.37, 13.57 x 52.46, 13.65
    { 87, 336, 19, LineMetaDataContent::Tramway, Color{0x006633} }, // 62 OSM: 19296 WD: Q62476843 52.42, 13.57 x 52.51, 13.61
    { 91, 355, 19, LineMetaDataContent::Tramway, Color{0x993333} }, // 37 OSM: 19451 WD: Q62499413 52.45, 13.5 x 52.53, 13.53
    { 94, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xc7956c} }, // U1 OSM: 19916 48.73, 9.111 x 48.81, 9.277
    { 97, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf58220} }, // U2 OSM: 19917 48.77, 9.122 x 48.83, 9.238
    { 100, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x935f39} }, // U3 OSM: 19918 48.71, 9.112 x 48.73, 9.202
    { 103, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7a68ae} }, // U4 OSM: 19919 48.77, 9.158 x 48.79, 9.25
    { 106, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00baf2} }, // U5 OSM: 19920 48.7, 9.136 x 48.8, 9.187
    { 109, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xec008c} }, // U6 OSM: 19921 48.71, 9.064 x 48.81, 9.187
    { 112, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0eb48d} }, // U7 OSM: 19922 48.71, 9.173 x 48.84, 9.296
    { 115, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xc3b47d} }, // U8 OSM: 19923 48.71, 9.112 x 48.76, 9.296
    { 118, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffd503} }, // U9 OSM: 19924 48.75, 9.138 x 48.79, 9.254
    { 65, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf8b710} }, // 10 OSM: 19925 WD: Q143861 48.75, 9.167 x 48.76, 9.174
    { 121, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xcccccc} }, // U11 OSM: 19926 48.77, 9.168 x 48.8, 9.226
    { 14, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x93bbe9} }, // U12 OSM: 19927 48.72, 9.118 x 48.87, 9.271
    { 125, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x69be51} }, // U14 OSM: 19928 48.77, 9.168 x 48.84, 9.23
    { 129, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x005aab} }, // U15 OSM: 19929 48.74, 9.156 x 48.85, 9.234
    { 133, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xcccccc} }, // U19 OSM: 19930 48.79, 9.213 x 48.83, 9.238
    { 65, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x312783} }, // 10 OSM: 19941 53.06, 8.752 x 53.12, 8.9
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x005ca9} }, // 2 OSM: 19942 53.06, 8.752 x 53.12, 8.9
    { 138, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x9eb4a5} }, // 72 OSM: 20258 WD: Q6811968 -37.86, 145 x -37.8, 145.1
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf287b6} }, // 2 OSM: 22852 54.08, 12.08 x 54.11, 12.17
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf8a500} }, // 6 OSM: 22871 54.07, 12.09 x 54.09, 12.14
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x5d106a} }, // 1 OSM: 23389 54.09, 12.05 x 54.16, 12.16
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x690713} }, // 3 OSM: 23742 54.07, 12.09 x 54.11, 12.18
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc30175} }, // 4 OSM: 23743 54.07, 12.1 x 54.11, 12.18
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe2001d} }, // 5 OSM: 23747 54.06, 12.05 x 54.16, 12.14
    { 103, 374, 386, LineMetaDataContent::Subway, Color{0x029540} }, // U4 OSM: 27113 WD: Q877322 48.18, 16.26 x 48.25, 16.39
    { 109, 402, 386, LineMetaDataContent::Subway, Color{0x9c6830} }, // U6 OSM: 27115 WD: Q281409 48.13, 16.31 x 48.26, 16.4
    { 0, 414, NoLogo, LineMetaDataContent::Subway, Color{0x302276} }, // U70 OSM: 27662 WD: Q661002 51.22, 6.566 x 51.33, 6.796
    { 141, 414, NoLogo, LineMetaDataContent::Subway, Color{0x302276} }, // U76 OSM: 27663 WD: Q661002 51.22, 6.566 x 51.33, 6.806
    { 145, 414, NoLogo, LineMetaDataContent::Subway, Color{0x302276} }, // U77 OSM: 27667 WD: Q661002 51.17, 6.735 x 51.24, 6.834
    { 150, 428, 19, LineMetaDataContent::Tramway, Color{0x0b9ada} }, // 60 OSM: 28289 WD: Q62512766 52.44, 13.5 x 52.46, 13.64
    { 153, 447, 161, LineMetaDataContent::RapidTransit, Color{0x055a99} }, // S3 OSM: 28314 WD: Q7388282 52.43, 13.2 x 52.53, 13.75
    { 156, 461, 19, LineMetaDataContent::Tramway, Color{0x009933} }, // 67 OSM: 28352 WD: Q66459350 52.44, 13.51 x 52.46, 13.59
    { 160, 480, 19, LineMetaDataContent::Tramway, Color{0x993333} }, // 27 OSM: 28377 WD: Q66091843 52.44, 13.46 x 52.56, 13.59
    { 163, 499, 19, LineMetaDataContent::Tramway, Color{0xa6422a} }, // M17 OSM: 28391 WD: Q62512560 52.45, 13.51 x 52.57, 13.53
    { 168, 519, 19, LineMetaDataContent::Tramway, Color{0x36ab94} }, // 50 OSM: 28420 WD: Q62499869 52.54, 13.34 x 52.61, 13.43
    { 171, 414, NoLogo, LineMetaDataContent::Subway, Color{0x302276} }, // U79 OSM: 28424 WD: Q661002 51.19, 6.739 x 51.47, 6.815
    { 69, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x3251a3} }, // 21 OSM: 29440 WD: Q4415661 51.91, 4.368 x 51.94, 4.525
    { 176, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x3251a3} }, // 24 OSM: 29446 WD: Q14500289 51.91, 4.341 x 51.94, 4.525
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 6 OSM: 30058 49.17, 16.55 x 49.23, 16.61
    { 54, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xd62631} }, // 11 OSM: 33897 51.28, 12.22 x 51.4, 12.4
    { 65, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xd62631} }, // 10 OSM: 33900 51.3, 12.32 x 51.37, 12.4
    { 26, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe3000f} }, // 16 OSM: 34068 51.3, 12.38 x 51.4, 12.4
    { 179, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x005395} }, // WLB OSM: 34086 WD: Q875199 48, 16.23 x 48.2, 16.37
    { 42, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0e4094} }, // 7 OSM: 34148 51.34, 12.27 x 51.36, 12.48
    { 84, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xcea4cb} }, // 68 OSM: 34480 50.7, 6.985 x 50.76, 7.156
    { 61, NoLogo, 161, LineMetaDataContent::RapidTransit, Color{0x5c8e3c} }, // S1 OSM: 35610 WD: Q18946157 48.59, 8.861 x 48.8, 9.444
    { 50, NoLogo, 161, LineMetaDataContent::RapidTransit, Color{0xff2e1d} }, // S2 OSM: 35611 WD: Q66537943 48.68, 9.105 x 48.83, 9.527
    { 153, NoLogo, 161, LineMetaDataContent::RapidTransit, Color{0xff7d24} }, // S3 OSM: 35612 WD: Q67504621 48.69, 9.105 x 48.94, 9.428
    { 119, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe6877e} }, // 9 OSM: 36132 50.92, 6.907 x 50.94, 7.097
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8cc63f} }, // 12 OSM: 36133 50.9, 6.939 x 51.03, 6.96
    { 130, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00accd} }, // 15 OSM: 36134 50.92, 6.898 x 51.02, 6.966
    { 119, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfecc00} }, // 9 OSM: 36930 51.3, 12.37 x 51.38, 12.43
    { 183, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x83898f} }, // 58 OSM: 37338 WD: Q28428375 -37.84, 144.9 x -37.74, 145
    { 186, NoLogo, 161, LineMetaDataContent::RapidTransit, Color{0x874a0a} }, // S6 OSM: 37419 WD: Q67501804 48.76, 8.872 x 48.83, 9.195
    { 190, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // T1 OSM: 38872 28.45, -16.32 x 28.49, -16.25
    { 130, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0e4094} }, // 15 OSM: 38883 51.29, 12.26 x 51.34, 12.44
    { 193, NoLogo, 414, LineMetaDataContent::Tramway, Color{0xc8d300} }, // 65 OSM: 39079 WD: Q20035842 50.72, 7.071 x 50.76, 7.156
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x9049a8} }, // 6 OSM: 48024 WD: Q62296933 52.09, 11.61 x 52.15, 11.68
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xb6005c} }, // 1 OSM: 48025 WD: Q62289804 52.11, 11.58 x 52.17, 11.64
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x73e700} }, // 4 OSM: 48453 WD: Q62295350 52.11, 11.58 x 52.16, 11.67
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xb48654} }, // 5 OSM: 48459 WD: Q62296384 52.11, 11.57 x 52.14, 11.67
    { 181, NoLogo, 538, LineMetaDataContent::RapidTransit, Color{0x32cd32} }, // B OSM: 51750 WD: Q1903862 55.65, 12.27 x 55.81, 12.59
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x62b32c} }, // 1 OSM: 51858 51.31, 12.26 x 51.38, 12.42
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf7c53a} }, // 2 OSM: 51859 51.29, 12.28 x 51.34, 12.44
    { 109, 548, 562, LineMetaDataContent::Subway, Color{0x8070b7} }, // U6 OSM: 51942 WD: Q99720 52.44, 13.28 x 52.59, 13.39
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 1 OSM: 52282 57.64, 11.9 x 57.73, 12.05
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xeb1923} }, // 5 OSM: 52617 57.7, 11.89 x 57.74, 12.05
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00985f} }, // 1 OSM: 52918 60.16, 24.92 x 60.22, 24.96
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00985f} }, // 3 OSM: 52930 60.16, 24.9 x 60.2, 24.96
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00985f} }, // 2 OSM: 52932 60.16, 24.92 x 60.2, 24.96
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00985f} }, // 4 OSM: 52941 60.17, 24.87 x 60.2, 24.98
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00985f} }, // 6 OSM: 52945 60.16, 24.92 x 60.21, 24.98
    { 42, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00985f} }, // 7 OSM: 52947 60.15, 24.91 x 60.2, 24.96
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00985f} }, // 8 OSM: 52948 60.16, 24.91 x 60.21, 24.98
    { 119, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00985f} }, // 9 OSM: 52950 60.16, 24.91 x 60.2, 24.95
    { 65, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00985f} }, // 10 OSM: 52951 60.16, 24.89 x 60.21, 24.95
    { 42, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x7d4313} }, // 7 OSM: 53027 57.64, 11.9 x 57.76, 12.07
    { 47, 573, 161, LineMetaDataContent::RapidTransit, Color{0xffc734} }, // S8 OSM: 53231 WD: Q17148488 48, 11.17 x 48.35, 11.79
    { 196, 589, 161, LineMetaDataContent::RapidTransit, Color{0xff2d1d} }, // S4 OSM: 53235 WD: Q7388308 48.04, 11.04 x 48.18, 11.97
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfa8719} }, // 6 OSM: 53254 57.68, 11.89 x 57.76, 12.04
    { 119, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x1e8164} }, // 9 OSM: 53748 WD: Q62299846 52.08, 11.6 x 52.18, 11.64
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x004799} }, // 2 OSM: 53752 WD: Q62291398 52.06, 11.63 x 52.15, 11.68
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf29400} }, // 8 OSM: 53770 WD: Q62299313 52.06, 11.63 x 52.18, 11.68
    { 186, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x3d2d7c} }, // S6 OSM: 53844 48.75, 8.549 x 48.9, 8.705
    { 199, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe42b23} }, // SMG OSM: 53893 WD: Q7567980 -37.82, 145 x -37.6, 145.1
    { 65, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xaac1e1} }, // 10 OSM: 54125 WD: Q62288523 52.11, 11.59 x 52.21, 11.67
    { 65, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x9acd32} }, // 10 OSM: 54452 WD: Q318073 51.49, 10.77 x 51.58, 10.8
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xda0873} }, // 1 OSM: 54602 53.59, 11.41 x 53.65, 11.47
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xd9261c} }, // 2 OSM: 54603 53.59, 11.36 x 53.65, 11.47
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe87878} }, // 3 OSM: 54604 53.57, 11.38 x 53.6, 11.47
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xdb214c} }, // 4 OSM: 54605 53.57, 11.38 x 53.65, 11.43
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffd600} }, // 3 OSM: 55097 WD: Q62292031 52.13, 11.57 x 52.16, 11.62
    { 204, NoLogo, 161, LineMetaDataContent::RapidTransit, Color{0x408040} }, // S 1 OSM: 55107 WD: Q56378592 52, 11.62 x 53.01, 11.87
    { 118, 605, 562, LineMetaDataContent::Subway, Color{0xff7300} }, // U9 OSM: 58423 WD: Q99744 52.46, 13.32 x 52.56, 13.37
    { 115, 619, 562, LineMetaDataContent::Subway, Color{0x055a99} }, // U8 OSM: 58424 WD: Q99729 52.47, 13.33 x 52.6, 13.43
    { 112, 633, 562, LineMetaDataContent::Subway, Color{0x0b9ada} }, // U7 OSM: 58425 WD: Q99725 52.42, 13.2 x 52.54, 13.5
    { 100, 647, 562, LineMetaDataContent::Subway, Color{0x15ac99} }, // U3 OSM: 58426 WD: Q99702 52.44, 13.24 x 52.51, 13.45
    { 97, 661, 562, LineMetaDataContent::Subway, Color{0xff3300} }, // U2 OSM: 58428 WD: Q99697 52.5, 13.24 x 52.57, 13.41
    { 103, 675, 562, LineMetaDataContent::Subway, Color{0xffcd00} }, // U4 OSM: 58429 WD: Q99708 52.48, 13.34 x 52.5, 13.36
    { 106, 689, 562, LineMetaDataContent::Subway, Color{0x7d533d} }, // U5 OSM: 58430 WD: Q99711 52.49, 13.41 x 52.54, 13.63
    { 208, 703, 562, LineMetaDataContent::Subway, Color{0x7d533d} }, // U55 OSM: 58431 WD: Q99715 52.52, 13.37 x 52.53, 13.38
    { 94, 718, 562, LineMetaDataContent::Subway, Color{0x52b447} }, // U1 OSM: 58767 WD: Q99691 52.5, 13.33 x 52.51, 13.45
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0e4094} }, // 12 OSM: 58815 51.32, 12.37 x 51.38, 12.4
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf7c53a} }, // 8 OSM: 58819 51.32, 12.28 x 51.36, 12.47
    { 126, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00a6e7} }, // 14 OSM: 58827 51.33, 12.32 x 51.34, 12.38
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x62b32c} }, // 3 OSM: 58829 51.28, 12.31 x 51.38, 12.49
    { 214, 732, 756, LineMetaDataContent::Subway, Color{0xcf003d} }, // C OSM: 58898 WD: Q168571 50.03, 14.43 x 50.13, 14.53
    { 219, 776, 756, LineMetaDataContent::Subway, Color{0x00a562} }, // A OSM: 58899 WD: Q1292805 50.07, 14.34 x 50.1, 14.52
    { 181, 800, 756, LineMetaDataContent::Subway, Color{0xf8b322} }, // B OSM: 58900 WD: Q1460442 50.04, 14.29 x 50.11, 14.58
    { 164, 824, 19, LineMetaDataContent::Tramway, Color{0x865a46} }, // 17 OSM: 61454 WD: Q20438593 48.13, 11.49 x 48.18, 11.64
    { 134, 845, 19, LineMetaDataContent::Tramway, Color{0xed1c24} }, // 19 OSM: 61456 WD: Q20438608 48.14, 11.46 x 48.15, 11.63
    { 22, 866, 19, LineMetaDataContent::Tramway, Color{0x0cb14b} }, // 18 OSM: 61458 WD: Q20438601 48.1, 11.49 x 48.14, 11.6
    { 221, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x006cb2} }, // N17 OSM: 61459 48.13, 11.49 x 48.17, 11.61
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf78a21} }, // 1 OSM: 61460 50.85, 12.07 x 50.89, 12.09
    { 50, 887, 161, LineMetaDataContent::RapidTransit, Color{0x018a47} }, // S2 OSM: 61466 WD: Q3743635 52.34, 13.36 x 52.68, 13.59
    { 225, 901, 161, LineMetaDataContent::RapidTransit, Color{0x018a47} }, // S25 OSM: 61469 WD: Q7388229 52.4, 13.21 x 52.64, 13.4
    { 100, 916, 562, LineMetaDataContent::Subway, Color{0xfcdf00} }, // U3 OSM: 62839 WD: Q781351 53.54, 9.969 x 53.59, 10.08
    { 230, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfaa635} }, // J OSM: 63222 WD: Q6109356 37.72, -122.4 x 37.79, -122.4
    { 233, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf0e68c} }, // F OSM: 63224 WD: Q1137818 37.76, -122.4 x 37.81, -122.4
    { 61, 931, 161, LineMetaDataContent::RapidTransit, Color{0x36caec} }, // S1 OSM: 63809 WD: Q7388207 48.13, 11.48 x 48.4, 11.79
    { 186, 947, 161, LineMetaDataContent::RapidTransit, Color{0x00ac6f} }, // S6 OSM: 63839 WD: Q7388348 47.91, 11.27 x 48.15, 11.97
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff7f00} }, // 3 OSM: 63875 51.82, 12.18 x 51.84, 12.24
    { 235, 963, 161, LineMetaDataContent::RapidTransit, Color{0xba8a4d} }, // S46 OSM: 64094 WD: Q3737194 52.3, 13.28 x 52.52, 13.64
    { 239, 978, 161, LineMetaDataContent::RapidTransit, Color{0xba8a4d} }, // S45 OSM: 64095 WD: Q2090939 52.39, 13.36 x 52.48, 13.57
    { 130, 993, 19, LineMetaDataContent::Tramway, Color{0xf58f98} }, // 15 OSM: 66007 WD: Q20438575 48.08, 11.55 x 48.14, 11.6
    { 226, 1014, 19, LineMetaDataContent::Tramway, Color{0xf58f98} }, // 25 OSM: 66008 WD: Q20439051 48.04, 11.52 x 48.14, 11.6
    { 15, 1035, 19, LineMetaDataContent::Tramway, Color{0x903f98} }, // 12 OSM: 66043 WD: Q20438570 48.15, 11.51 x 48.17, 11.58
    { 26, 1056, 19, LineMetaDataContent::Tramway, Color{0x006cb2} }, // 16 OSM: 66044 WD: Q20438583 48.13, 11.51 x 48.18, 11.64
    { 160, 1077, 19, LineMetaDataContent::Tramway, Color{0xfaa61a} }, // 27 OSM: 66053 WD: Q20439073 48.13, 11.56 x 48.18, 11.58
    { 244, 1098, 19, LineMetaDataContent::Tramway, Color{0x00bfe8} }, // 20 OSM: 66079 WD: Q20438843 48.14, 11.51 x 48.18, 11.56
    { 69, 1119, 19, LineMetaDataContent::Tramway, Color{0x00bfe8} }, // 21 OSM: 66080 WD: Q20439015 48.12, 11.53 x 48.17, 11.64
    { 249, 1147, 19, LineMetaDataContent::Tramway, Color{0xb2d233} }, // 23 OSM: 66100 WD: Q20439033 48.16, 11.59 x 48.19, 11.59
    { 252, 1168, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe67310} }, // A3 OSM: 66588 WD: Q19606155 53.75, 9.656 x 53.8, 9.983
    { 196, NoLogo, 161, LineMetaDataContent::RapidTransit, Color{0x0065b7} }, // S4 OSM: 66840 WD: Q67504669 48.77, 9.155 x 48.95, 9.428
    { 255, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x8d1d81} }, // S51 OSM: 67184 46.7, 15.63 x 46.73, 15.99
    { 260, 1183, 19, LineMetaDataContent::Tramway, Color{0xee6600} }, // M1 OSM: 67233 WD: Q62512139 52.52, 13.37 x 52.6, 13.41
    { 44, NoLogo, 161, LineMetaDataContent::RapidTransit, Color{0x00b7e1} }, // S5 OSM: 67283 WD: Q18926034 48.77, 9.122 x 48.95, 9.195
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf59e00} }, // 3 OSM: 69178 47.97, 7.796 x 48, 7.85
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe8001b} }, // 1 OSM: 69191 47.98, 7.808 x 48.03, 7.895
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008bc5} }, // 5 OSM: 69199 47.99, 7.787 x 48, 7.852
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x646363} }, // 2 OSM: 69202 47.96, 7.833 x 48.02, 7.858
    { 267, NoLogo, 1202, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // Blue OSM: 71390 WD: Q6714611 45.49, -123 x 45.54, -122.4
    { 272, NoLogo, 1202, LineMetaDataContent::RapidTransit, Color{0xffff00} }, // Yellow OSM: 71397 WD: Q6714624 45.51, -122.7 x 45.61, -122.7
    { 279, NoLogo, 1202, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // Red OSM: 71404 WD: Q6714623 45.49, -122.8 x 45.59, -122.6
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf6a6ab} }, // 1 OSM: 71785 47.25, 11.39 x 47.28, 11.41
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xd66775} }, // 3 OSM: 71787 47.26, 11.39 x 47.27, 11.43
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfbba00} }, // 1 OSM: 73662 WD: Q61888705 51.43, 11.94 x 51.51, 11.99
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff9900} }, // 2 OSM: 73667 WD: Q61889098 51.43, 11.89 x 51.5, 11.99
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0066cc} }, // 3 OSM: 73670 WD: Q61887067 51.43, 11.96 x 51.52, 11.99
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x9b1006} }, // 4 OSM: 73671 WD: Q61889270 51.44, 11.93 x 51.51, 11.99
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0f3f93} }, // 5 OSM: 73672 WD: Q61889316 51.29, 11.93 x 51.51, 12.07
    { 42, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff6699} }, // 7 OSM: 73929 WD: Q61889355 51.48, 11.93 x 51.51, 12.04
    { 119, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x999933} }, // 9 OSM: 73932 WD: Q61889418 51.48, 11.89 x 51.48, 11.99
    { 65, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x336633} }, // 10 OSM: 73933 WD: Q61889438 51.48, 11.9 x 51.49, 11.99
    { 53, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00983a} }, // S11 OSM: 76229 47.2, 15.23 x 47.23, 15.34
    { 61, NoLogo, 161, LineMetaDataContent::RapidTransit, Color{0x800000} }, // S1 OSM: 77908 WD: Q7388209 49.44, 10.9 x 49.9, 11.56
    { 50, NoLogo, 161, LineMetaDataContent::RapidTransit, Color{0x65b949} }, // S2 OSM: 77962 WD: Q7388248 49.24, 11.04 x 49.45, 11.35
    { 153, NoLogo, 161, LineMetaDataContent::RapidTransit, Color{0xf05c3d} }, // S3 OSM: 77971 WD: Q7388284 49.27, 11.08 x 49.45, 11.46
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xef1c29} }, // 3 OSM: 78206 50.84, 12.05 x 50.91, 12.1
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x4098de} }, // 3 OSM: 79325 WD: Q60318542 51.72, 14.3 x 51.76, 14.35
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xa81a30} }, // 6 OSM: 89518 WD: Q1664234 47.23, 11.4 x 47.26, 11.44
    { 9, 1222, 1255, LineMetaDataContent::Subway, Color{0x800080} }, // 4 OSM: 102389 WD: Q54373 43.76, -79.41 x 43.78, -79.35
    { 59, 1263, 1255, LineMetaDataContent::RapidTransit, Color{0x0093dd} }, // 3 OSM: 102390 WD: Q54372 43.73, -79.28 x 43.78, -79.25
    { 283, NoLogo, 1302, LineMetaDataContent::RapidTransit, Color{0xef7b10} }, // Overground OSM: 112649 WD: Q1854601 51.46, -0.3962 x 51.66, 0.08118
    { 214, 1325, 1346, LineMetaDataContent::RapidTransit, Color{0xfcd946} }, // C OSM: 122886 WD: Q200906 48.43, 1.995 x 49.05, 2.427
    { 294, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x193a94} }, // LSM OSM: 129382 WD: Q3239199 -34.61, -59.08 x -34.45, -58.37
    { 299, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // LM OSM: 129383 WD: Q3239158 -34.59, -59.1 x -34.1, -58.37
    { 302, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xef3e33} }, // LU OSM: 129393 WD: Q7887242 -34.6, -58.7 x -34.53, -58.46
    { 305, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0066cc} }, // LGR9 OSM: 129486 -34.79, -58.59 x -34.64, -58.4
    { 313, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf38733} }, // P OSM: 129505 WD: Q3409024 -34.69, -58.47 x -34.64, -58.44
    { 159, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfaa61a} }, // N27 OSM: 129569 48.08, 11.55 x 48.18, 11.58
    { 315, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0066cc} }, // LGR OSM: 129698 -34.83, -58.4 x -34.63, -58.18
    { 320, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe33385} }, // 96 OSM: 132386 WD: Q12061652 -37.87, 145 x -37.77, 145
    { 323, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfeba10} }, // 86 OSM: 137969 WD: Q12061650 -37.82, 144.9 x -37.68, 145.1
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x88d1f0} }, // 3 OSM: 144407 WD: Q6811954 -37.89, 145 x -37.8, 145.1
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe04038} }, // 5 OSM: 145649 WD: Q6811959 -37.87, 145 x -37.8, 145.1
    { 219, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe2001c} }, // A OSM: 146067 48.52, 7.693 x 48.6, 7.754
    { 327, NoLogo, 1354, LineMetaDataContent::Tramway, Color{0xffd800} }, // 49 OSM: 147322 WD: Q1491114 47.47, 19.02 x 47.5, 19.06
    { 260, 1380, 1411, LineMetaDataContent::Subway, Color{0xff0000} }, // M1 OSM: 149920 WD: Q2334153 50.44, 30.35 x 50.47, 30.65
    { 153, 1431, 161, LineMetaDataContent::RapidTransit, Color{0x874487} }, // S3 OSM: 152203 WD: Q680235 47.09, 11.39 x 47.28, 11.5
    { 330, NoLogo, 1450, LineMetaDataContent::Subway, Color{0xfdc110} }, // M2 OSM: 152340 WD: Q1880954 55.63, 12.49 x 55.69, 12.65
    { 333, 1476, 1411, LineMetaDataContent::Subway, Color{0x00ff00} }, // M3 OSM: 153243 WD: Q2420584 50.39, 30.43 x 50.48, 30.7
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009640} }, // 1 OSM: 153893 53.04, 8.741 x 53.16, 8.965
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00ff00} }, // 6 OSM: 155951 49, 8.295 x 49.02, 8.44
    { 181, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x127bca} }, // B OSM: 163585 48.55, 7.689 x 48.63, 7.769
    { 39, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xa85faa} }, // E OSM: 163591 48.53, 7.733 x 48.61, 7.786
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xec008c} }, // 1 OSM: 163714 52.48, -2.125 x 52.58, -1.896
    { 260, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0075be} }, // M1 OSM: 165613 WD: Q3238660 43.29, 5.374 x 43.33, 5.43
    { 330, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xe30513} }, // M2 OSM: 165618 WD: Q3238804 43.27, 5.367 x 43.33, 5.403
    { 341, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x49805b} }, // 59 OSM: 167658 WD: Q6811962 -37.82, 144.9 x -37.71, 145
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x003828} }, // 1 OSM: 170076 52.92, -1.263 x 53.04, -1.145
    { 344, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x42816b} }, // 181 (SN) OSM: 172834 51.28, -0.1727 x 51.49, -0.07193
    { 272, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xd39f06} }, // Yellow OSM: 172864 WD: Q19960799 54.95, -1.623 x 55.04, -1.429
    { 353, 1507, 161, LineMetaDataContent::RapidTransit, Color{0x52b447} }, // S85 OSM: 175267 WD: Q4048677 52.41, 13.4 x 52.57, 13.58
    { 315, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0066cc} }, // LGR OSM: 176910 -35.44, -59.09 x -34.85, -58.52
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x82cee6} }, // 8 OSM: 178504 39.46, -0.339 x 39.46, -0.3254
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x9b70cb} }, // 6 OSM: 178505 WD: Q3832664 39.46, -0.3726 x 39.5, -0.3256
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x004a99} }, // 4 OSM: 178506 39.47, -0.4364 x 39.53, -0.3256
    { 6, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x009870} }, // 5 OSM: 178522 WD: Q3238965 39.46, -0.4744 x 39.49, -0.3383
    { 59, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xdd052b} }, // 3 OSM: 178523 WD: Q3238906 39.47, -0.4744 x 39.59, -0.33
    { 55, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xfdc600} }, // 1 OSM: 178526 WD: Q2165952 39.08, -0.5268 x 39.59, -0.3815
    { 358, NoLogo, 1522, LineMetaDataContent::Tramway, Color{0xc19dc2} }, // L4 OSM: 190184 WD: Q5474600 38.35, -0.4907 x 38.38, -0.4118
    { 362, NoLogo, 1522, LineMetaDataContent::Tramway, Color{0xd72028} }, // L1 OSM: 190196 WD: Q594538 38.35, -0.4907 x 38.55, -0.1346
    { 366, NoLogo, 1522, LineMetaDataContent::Tramway, Color{0x00ff00} }, // L2 OSM: 190199 WD: Q9025903 38.35, -0.5172 x 38.39, -0.4678
    { 370, NoLogo, 1522, LineMetaDataContent::Tramway, Color{0xf9d114} }, // L3 OSM: 190203 WD: Q9025931 38.35, -0.4907 x 38.43, -0.395
    { 373, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf58122} }, // 109 OSM: 190802 WD: Q6811947 -37.84, 144.9 x -37.81, 145.1
    { 214, NoLogo, 538, LineMetaDataContent::RapidTransit, Color{0xffa500} }, // C OSM: 191280 WD: Q4452746 55.66, 12.07 x 55.84, 12.59
    { 378, 1563, 538, LineMetaDataContent::RapidTransit, Color{0xe64415} }, // H OSM: 191281 WD: Q1891933 55.66, 12.07 x 55.84, 12.59
    { 380, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x33bdca} }, // 57 OSM: 196209 WD: Q16926803 -37.82, 144.9 x -37.77, 145
    { 383, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x015dab} }, // Atlantic City OSM: 206515 WD: Q756350 39.36, -75.2 x 40.01, -74.44
    { 186, NoLogo, 161, LineMetaDataContent::RapidTransit, Color{0xd9483d} }, // S6 OSM: 206557 WD: Q63705067 47.54, 7.59 x 47.71, 7.849
    { 38, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0e4094} }, // 4E OSM: 207342 51.32, 12.35 x 51.38, 12.43
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0e4094} }, // 4 OSM: 207342 51.32, 12.35 x 51.38, 12.43
    { 397, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00a5e3} }, // North Jersey Coast OSM: 207401 WD: Q7055732 40.07, -74.29 x 40.77, -73.99
    { 16, 1585, NoLogo, LineMetaDataContent::Subway, Color{0x97d700} }, // 2 OSM: 207417 WD: Q1325437 31.15, 121.3 x 31.24, 121.8
    { 416, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x434244} }, // 48 OSM: 207445 WD: Q16926797 -37.82, 144.9 x -37.79, 145.1
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 1 OSM: 207718 45.55, 18.62 x 45.57, 18.73
    { 303, 1594, NoLogo, LineMetaDataContent::RapidTransit, Color{0xc90062} }, // U OSM: 215565 WD: Q93559 48.76, 1.943 x 48.89, 2.237
    { 34, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0066cc} }, // LS OSM: 223925 -35.19, -59.43 x -34.58, -58.41
    { 317, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009f4d} }, // R OSM: 224816 WD: Q3239181 50.64, 3.071 x 50.69, 3.179
    { 42, 1617, NoLogo, LineMetaDataContent::Subway, Color{0xff6900} }, // 7 OSM: 228608 WD: Q2707909 31.17, 121.3 x 31.41, 121.6
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 8 OSM: 237270 49.17, 16.55 x 49.21, 16.69
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 2 OSM: 237285 49.13, 16.59 x 49.2, 16.64
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 1 OSM: 237306 49.19, 16.51 x 49.25, 16.61
    { 420, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xb56631} }, // 22 OSM: 241384 59.29, 17.96 x 59.36, 18.12
    { 424, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf166a7} }, // 43 OSM: 241411 58.9, 17.53 x 59.57, 18.16
    { 428, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf166a7} }, // 41 OSM: 241413 59.17, 17.63 x 59.63, 18.07
    { 432, 1626, NoLogo, LineMetaDataContent::RapidTransit, Color{0xc7b300} }, // K OSM: 253357 WD: Q93382 48.88, 2.352 x 49.23, 2.888
    { 434, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008a29} }, // C-5 OSM: 254510 WD: Q9026057 39.44, -0.5754 x 39.95, -0.2715
    { 438, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x007dc5} }, // ISL OSM: 269670 WD: Q989316 22.26, 114.1 x 22.29, 114.2
    { 442, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xf7943e} }, // TCL OSM: 269671 WD: Q989358 22.28, 113.9 x 22.36, 114.2
    { 446, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x00888a} }, // AEL OSM: 272078 WD: Q409036 22.29, 113.9 x 22.36, 114.2
    { 450, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xa3238f} }, // WRL OSM: 272079 WD: Q989369 22.29, 114 x 22.45, 114.2
    { 454, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x53b7e8} }, // EAL OSM: 272132 WD: Q989339 22.3, 114.1 x 22.53, 114.2
    { 458, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x923011} }, // TML OSM: 272133 WD: Q5329661 22.33, 114.2 x 22.43, 114.2
    { 204, 1649, 1649, LineMetaDataContent::Tramway, Color{0xef7c00} }, // S 1 OSM: 273002 WD: Q65643711 49.11, 6.891 x 49.41, 7.068
    { 462, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff7e00} }, // 28E OSM: 274460 WD: Q63034669 38.71, -9.17 x 38.72, -9.128
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // 2 OSM: 300207 48.46, 34.61 x 48.52, 34.69
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff00ff} }, // 1 OSM: 300208 48.51, 34.57 x 48.52, 34.62
    { 466, 1667, 161, LineMetaDataContent::RapidTransit, Color{0x9a3052} }, // S9 OSM: 304163 WD: Q4048680 52.39, 13.2 x 52.53, 13.57
    { 469, NoLogo, 1202, LineMetaDataContent::RapidTransit, Color{0x008000} }, // Green OSM: 304623 WD: Q6714613 45.44, -122.7 x 45.54, -122.6
    { 260, 1681, 1693, LineMetaDataContent::Subway, Color{0x0000ff} }, // M1 OSM: 309619 WD: Q17462780 52.13, 20.93 x 52.29, 21.07
    { 475, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfc7ebb} }, // SHM OSM: 331945 WD: Q7416840 -37.95, 145 x -37.82, 145
    { 479, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x149943} }, // FKN OSM: 344911 WD: Q5492274 -38.14, 144.9 x -37.81, 145.1
    { 483, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x16b4e8} }, // PKM OSM: 349554 WD: Q7125454 -38.08, 144.9 x -37.81, 145.5
    { 487, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x16b4e8} }, // CBE OSM: 349555 WD: Q5181939 -38.1, 144.9 x -37.81, 145.3
    { 491, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x094b8d} }, // GWY OSM: 349560 WD: Q5568092 -37.88, 145 x -37.81, 145.2
    { 313, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // P OSM: 357191 60.17, 24.84 x 60.33, 25.06
    { 495, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // C-1 OSM: 357967 43.25, -3.03 x 43.33, -2.928
    { 499, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x630016} }, // STB OSM: 359908 WD: Q872840 47.16, 11.35 x 47.27, 11.4
    { 504, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x723b1f} }, // 35 OSM: 363305 WD: Q5123100 -37.82, 144.9 x -37.81, 145
    { 134, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8f4a78} }, // 19 OSM: 363891 WD: Q6811950 -37.82, 145 x -37.73, 145
    { 153, 1715, 161, LineMetaDataContent::RapidTransit, Color{0x862996} }, // S3 OSM: 364187 WD: Q7388283 47.88, 11.17 x 48.22, 11.7
    { 507, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // SIR1 OSM: 365296 45.37, 11.87 x 45.44, 11.89
    { 201, 1731, NoLogo, LineMetaDataContent::Subway, Color{0x6cbe45} }, // G OSM: 366764 WD: Q126527 40.64, -74 x 40.75, -73.94
    { 42, 1757, NoLogo, LineMetaDataContent::Subway, Color{0xb933ad} }, // 7 OSM: 366765 WD: Q126203 40.74, -74 x 40.76, -73.83
    { 35, 1783, NoLogo, LineMetaDataContent::Subway, Color{0x808183} }, // S OSM: 366766 WD: Q126698 40.75, -73.99 x 40.76, -73.98
    { 481, 1809, NoLogo, LineMetaDataContent::Subway, Color{0xfccc0a} }, // N OSM: 366768 WD: Q126434 40.59, -74.02 x 40.78, -73.91
    { 512, 1835, NoLogo, LineMetaDataContent::Subway, Color{0xfccc0a} }, // Q OSM: 366769 WD: Q126448 40.58, -74 x 40.78, -73.95
    { 219, 1861, NoLogo, LineMetaDataContent::Subway, Color{0x0039a6} }, // A OSM: 366774 WD: Q126344 40.58, -74.01 x 40.87, -73.75
    { 27, 1887, NoLogo, LineMetaDataContent::Subway, Color{0x00933c} }, // 6 OSM: 366777 WD: Q126192 40.71, -74.01 x 40.85, -73.83
    { 317, 1913, NoLogo, LineMetaDataContent::Subway, Color{0xfccc0a} }, // R OSM: 366780 WD: Q126459 40.62, -74.03 x 40.77, -73.84
    { 514, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x9acd32} }, // Bx OSM: 367751 55.65, 12.27 x 55.81, 12.59
    { 313, 1939, NoLogo, LineMetaDataContent::RapidTransit, Color{0xeaab00} }, // P OSM: 370597 WD: Q93874 48.51, 2.359 x 49.18, 3.417
    { 233, NoLogo, 538, LineMetaDataContent::RapidTransit, Color{0xffc225} }, // F OSM: 381625 WD: Q2133631 55.65, 12.49 x 55.73, 12.57
    { 42, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008030} }, // 7 OSM: 382533 WD: Q2590490 51.91, 4.471 x 51.93, 4.526
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xdf60a4} }, // 8 OSM: 382535 WD: Q3277304 51.9, 4.432 x 51.95, 4.488
    { 226, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x52b947} }, // 25 OSM: 382566 WD: Q2321951 51.84, 4.46 x 51.96, 4.514
    { 65, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 10 OSM: 383124 49.17, 16.57 x 49.19, 16.68
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xdaa520} }, // 6 OSM: 383846 50.89, 10.56 x 50.9, 10.58
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 12 OSM: 384321 49.18, 16.58 x 49.23, 16.62
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 5 OSM: 384539 49.16, 16.59 x 49.22, 16.63
    { 54, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 11 OSM: 384541 49.19, 16.52 x 49.23, 16.63
    { 55, NoLogo, 1962, LineMetaDataContent::Subway, Color{0x000099} }, // 1 OSM: 386098 WD: Q1085934 40.84, 14.22 x 40.9, 14.27
    { 260, NoLogo, 1962, LineMetaDataContent::Subway, Color{0xffff00} }, // M1 OSM: 386242 WD: Q3238662 45.03, 7.591 x 45.08, 7.68
    { 39, NoLogo, 538, LineMetaDataContent::RapidTransit, Color{0x9370db} }, // E OSM: 394091 WD: Q4624816 55.46, 12.17 x 55.81, 12.59
    { 54, 1992, NoLogo, LineMetaDataContent::Subway, Color{0x76232f} }, // 11 OSM: 396879 WD: Q2636308 31.13, 121.1 x 31.4, 121.7
    { 190, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // T1 OSM: 399912 45.69, 9.676 x 45.76, 9.798
    { 517, NoLogo, 1522, LineMetaDataContent::Tramway, Color{0x706e6d} }, // L9 OSM: 404372 WD: Q11690013 38.55, -0.1352 x 38.84, 0.1131
    { 16, 2002, 2022, LineMetaDataContent::Subway, Color{0x00529b} }, // 2 OSM: 414866 WD: Q680973 39.9, 116.3 x 39.95, 116.4
    { 55, 2046, 2022, LineMetaDataContent::Subway, Color{0xa12830} }, // 1 OSM: 415571 WD: Q748987 39.91, 116.2 x 39.93, 116.5
    { 520, 2066, 2022, LineMetaDataContent::Subway, Color{0xa12830} }, // 1E OSM: 415574 WD: Q1039452 39.86, 116.5 x 39.91, 116.7
    { 58, 2091, 2022, LineMetaDataContent::Subway, Color{0xf9e700} }, // 13 OSM: 417951 WD: Q847744 39.94, 116.3 x 40.07, 116.5
    { 260, 2112, 2128, LineMetaDataContent::Subway, Color{0xffe507} }, // M1 OSM: 418343 WD: Q1078111 47.5, 19.05 x 47.52, 19.09
    { 524, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x006d78} }, // T2 OSM: 418631 47.22, 5.951 x 47.25, 6.03
    { 65, 2142, 2022, LineMetaDataContent::Subway, Color{0x178abb} }, // 10 OSM: 420835 WD: Q847886 39.84, 116.3 x 39.98, 116.5
    { 6, 2163, 2022, LineMetaDataContent::Subway, Color{0xae005f} }, // 5 OSM: 420836 WD: Q647340 39.84, 116.4 x 40.08, 116.4
    { 19, 2183, 2022, LineMetaDataContent::Subway, Color{0x009b77} }, // 8 OSM: 420837 WD: Q847771 39.76, 116.3 x 40.1, 116.4
    { 9, 2203, 2022, LineMetaDataContent::Subway, Color{0x008193} }, // 4 OSM: 420838 WD: Q304264 39.81, 116.3 x 40.01, 116.4
    { 19, NoLogo, 2223, LineMetaDataContent::Subway, Color{0x008c95} }, // 8 OSM: 443998 WD: Q862965 23.09, 113.2 x 23.11, 113.4
    { 16, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // 2 OSM: 445980 WD: Q2274338 40.82, 14.12 x 40.87, 14.31
    { 27, NoLogo, 1962, LineMetaDataContent::Subway, Color{0x0099cc} }, // 6 OSM: 446007 WD: Q3832666 40.82, 14.19 x 40.83, 14.22
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // 4 OSM: 447292 339.5, 249.5 x 339.5, 249.5
    { 527, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x9400d3} }, // N3 OSM: 447293 339.5, 249.5 x 339.5, 249.5
    { 317, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // R OSM: 447451 WD: Q697140 25.03, 121.4 x 25.17, 121.6
    { 55, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0026ff} }, // 1 OSM: 453141 36.23, 59.44 x 36.35, 59.64
    { 61, 2248, 161, LineMetaDataContent::RapidTransit, Color{0xd474ae} }, // S1 OSM: 454054 WD: Q2579762 52.42, 13.18 x 52.75, 13.4
    { 41, 2262, 161, LineMetaDataContent::RapidTransit, Color{0x20543f} }, // S7 OSM: 456933 WD: Q2588691 49.83, 8.488 x 50.11, 8.664
    { 190, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe40716} }, // T1 OSM: 535990 45.41, 4.364 x 45.48, 4.394
    { 216, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0363ff} }, // T1 A OSM: 548496 WD: Q1688502 36.72, 3.083 x 36.78, 3.263
    { 531, NoLogo, 1354, LineMetaDataContent::Tramway, Color{0xffd800} }, // 56 OSM: 557061 WD: Q1491414 47.43, 18.96 x 47.54, 19.05
    { 134, NoLogo, 1354, LineMetaDataContent::Tramway, Color{0xffd800} }, // 19 OSM: 557063 WD: Q776651 47.47, 19.02 x 47.55, 19.05
    { 535, NoLogo, 1354, LineMetaDataContent::Tramway, Color{0xffd800} }, // 47 OSM: 557066 WD: Q1491058 47.43, 19.04 x 47.5, 19.06
    { 428, NoLogo, 1354, LineMetaDataContent::Tramway, Color{0xffd800} }, // 41 OSM: 557068 WD: Q1490823 47.44, 18.98 x 47.55, 19.05
    { 80, NoLogo, 1354, LineMetaDataContent::Tramway, Color{0xffd800} }, // 61 OSM: 557070 WD: Q1491592 47.48, 18.96 x 47.54, 19.05
    { 16, 2279, NoLogo, LineMetaDataContent::Tramway, Color{0x0068b3} }, // 2 OSM: 563459 WD: Q78198199 48.32, 10.84 x 48.38, 10.91
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xef7c00} }, // 8 OSM: 563484 48.33, 10.89 x 48.37, 10.9
    { 149, NoLogo, 161, LineMetaDataContent::RapidTransit, Color{0x928d1d} }, // S60 OSM: 570588 WD: Q63952011 48.69, 8.922 x 48.83, 9.195
    { 538, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x6699cc} }, // 215 OSM: 571534 46.95, 6.839 x 46.99, 6.928
    { 543, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009f4d} }, // T OSM: 593563 WD: Q3239234 50.64, 3.071 x 50.72, 3.159
    { 150, NoLogo, 1354, LineMetaDataContent::Tramway, Color{0xffd800} }, // 60 OSM: 899388 WD: Q851167 47.5, 18.98 x 47.51, 19.01
    { 341, NoLogo, 1354, LineMetaDataContent::Tramway, Color{0xffd800} }, // 59 OSM: 906131 WD: Q744461 47.48, 19 x 47.51, 19.02
    { 164, NoLogo, 1354, LineMetaDataContent::Tramway, Color{0xffd800} }, // 17 OSM: 911937 WD: Q1486400 47.44, 19.02 x 47.55, 19.05
    { 26, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffda66} }, // 16 OSM: 916109 WD: Q16926791 -37.87, 145 x -37.8, 145
    { 153, 2299, 2313, LineMetaDataContent::RapidTransit, Color{0x942138} }, // S3 OSM: 919367 WD: Q600028 45.47, 9.031 x 45.63, 9.175
    { 61, 2335, 2313, LineMetaDataContent::RapidTransit, Color{0xde3d30} }, // S1 OSM: 919412 WD: Q46365 45.31, 9.031 x 45.63, 9.498
    { 545, 2349, 2313, LineMetaDataContent::RapidTransit, Color{0x784f24} }, // S13 OSM: 919471 WD: Q1160881 45.19, 9.143 x 45.5, 9.245
    { 549, NoLogo, 2364, LineMetaDataContent::RapidTransit, Color{0xffa21d} }, // MD-W OSM: 932986 WD: Q5250950 41.88, -88.33 x 42.06, -87.64
    { 196, 2379, 2313, LineMetaDataContent::RapidTransit, Color{0x59b530} }, // S4 OSM: 936755 WD: Q1160571 45.47, 9.134 x 45.67, 9.176
    { 50, 2393, 2313, LineMetaDataContent::RapidTransit, Color{0x009478} }, // S2 OSM: 936757 WD: Q1160540 45.43, 9.14 x 45.65, 9.239
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x95c11f} }, // 8 OSM: 963052 53.05, 8.741 x 53.1, 8.841
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffcc00} }, // 6 OSM: 963103 53.05, 8.783 x 53.11, 8.859
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x824c34} }, // 5 OSM: 963685 47.03, 15.42 x 47.1, 15.45
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xd79c3b} }, // 4 OSM: 963737 47.04, 15.42 x 47.1, 15.46
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe30613} }, // 4 OSM: 964983 53.03, 8.799 x 53.16, 8.945
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009fe3} }, // 3 OSM: 966312 53.06, 8.752 x 53.12, 8.868
    { 554, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00a54f} }, // D1 OSM: 1014078 51.1, 15.22 x 51.29, 17.04
    { 190, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // T1 OSM: 1059709 42.84, -2.702 x 42.87, -2.664
    { 557, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0075bf} }, // N10 OSM: 1070763 53.06, 8.752 x 53.12, 8.9
    { 561, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe30613} }, // N4 OSM: 1070810 53.03, 8.799 x 53.16, 8.945
    { 564, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009640} }, // N1 OSM: 1070812 53.04, 8.741 x 53.09, 8.965
    { 27, NoLogo, 1354, LineMetaDataContent::Tramway, Color{0xffd800} }, // 6 OSM: 1102938 WD: Q1491542 47.48, 19.02 x 47.51, 19.07
    { 9, NoLogo, 1354, LineMetaDataContent::Tramway, Color{0xffd800} }, // 4 OSM: 1102941 WD: Q1490736 47.47, 19.02 x 47.51, 19.07
    { 567, NoLogo, 2407, LineMetaDataContent::RapidTransit, Color{0xa72a75} }, // H5 OSM: 1103027 WD: Q1031914 47.51, 19.03 x 47.66, 19.08
    { 570, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x1aaa6f} }, // 64 OSM: 1110830 WD: Q6811964 -37.91, 145 x -37.8, 145
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x004c6c} }, // 6 OSM: 1111658 WD: Q16926785 -37.86, 145 x -37.76, 145.1
    { 156, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xac7963} }, // 67 OSM: 1111659 WD: Q6811965 -37.89, 145 x -37.8, 145.1
    { 573, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfaa634} }, // Raritan Valley OSM: 1122386 WD: Q7294577 40.56, -74.9 x 40.74, -74.16
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x90ee90} }, // 2 OSM: 1133379 49.82, 23.99 x 49.84, 24.07
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x90ee90} }, // 3 OSM: 1133381 49.81, 24 x 49.84, 24.04
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x90ee90} }, // 5 OSM: 1133389 49.81, 24 x 49.86, 24.04
    { 42, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x90ee90} }, // 7 OSM: 1133430 49.83, 23.99 x 49.85, 24.06
    { 588, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x90ee90} }, // ? OSM: 1133450 49.81, 24 x 49.84, 24.06
    { 590, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xf173ac} }, // DRL OSM: 1139477 WD: Q989330 22.32, 114 x 22.33, 114
    { 219, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xed389c} }, // A OSM: 1142411 45.5, -122.7 x 45.53, -122.7
    { 594, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe41f25} }, // N82 OSM: 1147592 48.24, 14.28 x 48.33, 14.36
    { 168, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe41f25} }, // 50 OSM: 1149422 48.31, 14.26 x 48.32, 14.29
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe41f25} }, // 2 OSM: 1149423 48.24, 14.28 x 48.33, 14.36
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe41f25} }, // 3 OSM: 1149424 48.23, 14.23 x 48.31, 14.29
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe41f25} }, // 1 OSM: 1149425 48.25, 14.28 x 48.33, 14.32
    { 97, 2431, 562, LineMetaDataContent::Subway, Color{0x00a54f} }, // U2 OSM: 1150977 WD: Q3040891 50.1, 8.64 x 50.22, 8.687
    { 598, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0039a6} }, // Harlem OSM: 1158719 WD: Q5658559 40.75, -73.98 x 41.82, -73.55
    { 605, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffc260} }, // 100s, 900s (A700s) OSM: 1165701 WD: Q4132754 34.05, -119.2 x 34.29, -118.2
    { 624, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // 200s OSM: 1172222 WD: Q4162507 34.05, -118.5 x 34.71, -118.1
    { 629, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x009b3a} }, // Hudson OSM: 1186686 40.75, -73.99 x 41.71, -73.86
    { 636, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff7900} }, // Port Jervis OSM: 1190915 WD: Q7230730 41.11, -74.69 x 41.49, -74.09
    { 362, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe52422} }, // L1 OSM: 1190932 41.62, -0.9378 x 41.69, -0.8708
    { 648, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x800080} }, // 400s OSM: 1199065 WD: Q4801982 33.96, -118.2 x 34.06, -117.4
    { 653, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0065ff} }, // SFMA OSM: 1204872 WD: Q3832760 45.09, 7.47 x 45.27, 7.677
    { 658, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x95aa53} }, // 308 OSM: 1228606 51.4, 7.16 x 51.52, 7.284
    { 662, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xb14e7a} }, // 310 OSM: 1228607 51.44, 7.152 x 51.48, 7.337
    { 503, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x294488} }, // U35 OSM: 1228608 WD: Q2466100 51.45, 7.21 x 51.55, 7.273
    { 21, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x72a7a0} }, // 318 OSM: 1228609 51.42, 7.143 x 51.52, 7.284
    { 666, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xea504c} }, // 306 OSM: 1228610 51.48, 7.16 x 51.53, 7.223
    { 670, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x6ba5d9} }, // 302 OSM: 1228611 51.46, 7.056 x 51.58, 7.324
    { 674, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00b2f6} }, // 301 OSM: 1236118 51.5, 7.019 x 51.58, 7.11
    { 678, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf47a14} }, // S 5 OSM: 1241173 49.14, 8.674 x 49.42, 9.102
    { 682, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0039a6} }, // Port Jefferson OSM: 1255264 WD: Q7230720 40.7, -73.99 x 40.94, -73.05
    { 697, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe00034} }, // New Haven OSM: 1260624 40.75, -73.98 x 41.31, -72.92
    { 707, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x89728e} }, // VMLR OSM: 1266358 33.41, -112.1 x 33.57, -111.8
    { 524, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // T2 OSM: 1286854 28.44, -16.3 x 28.47, -16.29
    { 712, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x800000} }, // 300s OSM: 1287719 34.05, -118.2 x 34.11, -117.3
    { 717, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00af3f} }, // Oyster Bay OSM: 1308975 WD: Q7116314 40.7, -73.99 x 40.88, -73.53
    { 728, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe6007e} }, // S31 OSM: 1319745 47.1, 15.62 x 47.22, 15.71
    { 176, 2448, 2022, LineMetaDataContent::Subway, Color{0xd61572} }, // 24 OSM: 1350576 WD: Q5944471 39.77, 116.4 x 39.84, 116.6
    { 366, 2448, 2022, LineMetaDataContent::Subway, Color{0xd61572} }, // L2 OSM: 1350576 WD: Q5944471 39.77, 116.4 x 39.84, 116.6
    { 160, 2475, 2022, LineMetaDataContent::Subway, Color{0xd47daa} }, // 27 OSM: 1350622 WD: Q5066697 40.05, 116.2 x 40.24, 116.3
    { 732, 2503, 2022, LineMetaDataContent::Subway, Color{0xd85f26} }, // 25N OSM: 1350671 WD: Q5433860 39.72, 116.1 x 39.81, 116.3
    { 736, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7b388c} }, // Kingston/Plymouth Line OSM: 1353691 WD: Q7083739 41.98, -71.06 x 42.35, -70.69
    { 759, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7b388c} }, // Needham Line OSM: 1353692 WD: Q6986548 42.27, -71.24 x 42.35, -71.05
    { 772, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7b388c} }, // Fairmount Line OSM: 1353693 WD: Q5430648 42.24, -71.13 x 42.35, -71.05
    { 787, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7b388c} }, // Greenbush Line OSM: 1353695 WD: Q5603780 42.18, -71.06 x 42.35, -70.74
    { 802, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7b388c} }, // Middleborough/Lakeville Line OSM: 1353697 WD: Q7083739 41.88, -71.06 x 42.35, -70.92
    { 362, NoLogo, 2022, LineMetaDataContent::Subway, Color{0x9b91b1} }, // L1 OSM: 1354082 WD: Q847767 39.94, 116.4 x 40.08, 116.6
    { 831, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7b388c} }, // Framingham/Worcester Line OSM: 1354954 WD: Q801994 42.23, -71.8 x 42.36, -71.06
    { 857, NoLogo, 2407, LineMetaDataContent::RapidTransit, Color{0xee701b} }, // H7 OSM: 1358702 WD: Q1031921 47.42, 19.07 x 47.48, 19.07
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 3 OSM: 1361661 56.48, 84.95 x 56.48, 85.02
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xcc9900} }, // 8 OSM: 1374424 WD: Q61887882 51.45, 11.95 x 51.52, 11.99
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfed265} }, // 1 OSM: 1375736 46.24, 20.12 x 46.27, 20.15
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x99cc00} }, // 12 OSM: 1375884 WD: Q61888162 51.48, 11.96 x 51.52, 11.99
    { 860, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfece08} }, // Main OSM: 1377995 WD: Q6736006 40.73, -74.17 x 41.11, -74.03
    { 865, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa1d4ae} }, // Gladstone OSM: 1377996 WD: Q5566325 40.67, -74.67 x 40.77, -73.99
    { 875, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xb9c9df} }, // Bergen County OSM: 1377997 WD: Q4891507 40.73, -74.15 x 41.11, -74.03
    { 889, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00a94e} }, // Morristown OSM: 1377998 WD: Q1948559 40.71, -74.83 x 40.91, -73.99
    { 900, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe76b5b} }, // Montclair-Boonton OSM: 1377999 WD: Q6904583 40.73, -74.83 x 40.93, -73.99
    { 212, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff8942} }, // FXC OSM: 1388637 WD: Q8565193 39.95, -75.18 x 40.08, -75.08
    { 918, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7c5e4a} }, // DOY OSM: 1388640 WD: Q6487336 39.95, -75.28 x 40.31, -75.13
    { 922, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffd457} }, // WAR OSM: 1390135 WD: Q7969637 39.95, -75.18 x 40.26, -74.82
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 2 OSM: 1390151 34.31, 132.3 x 34.4, 132.5
    { 336, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfaa93f} }, // 841-859 OSM: 1403277 WD: Q5025789 38.9, -77.01 x 39.28, -76.62
    { 926, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfaa93f} }, // 840-860 OSM: 1403278 WD: Q5025789 38.9, -77.01 x 39.28, -76.62
    { 934, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfbcab6} }, // 892 OSM: 1405414 WD: Q4979520 38.9, -77.53 x 39.41, -76.99
    { 938, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfbcab6} }, // 894 OSM: 1405414 WD: Q4979520 38.9, -77.53 x 39.41, -76.99
    { 942, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfbcab6} }, // 890 OSM: 1405414 WD: Q4979520 38.9, -77.53 x 39.41, -76.99
    { 946, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfbcab6} }, // 895 OSM: 1405415 WD: Q4979520 38.9, -77.53 x 39.41, -76.99
    { 950, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfbcab6} }, // 891 OSM: 1405415 WD: Q4979520 38.9, -77.53 x 39.41, -76.99
    { 954, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfbcab6} }, // 893 OSM: 1405415 WD: Q4979520 38.9, -77.53 x 39.41, -76.99
    { 958, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfbcab6} }, // 879 OSM: 1405856 WD: Q4979520 38.9, -77.96 x 39.46, -76.99
    { 962, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfbcab6} }, // 871 OSM: 1405856 WD: Q4979520 38.9, -77.96 x 39.46, -76.99
    { 966, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfbcab6} }, // 877 OSM: 1405856 WD: Q4979520 38.9, -77.96 x 39.46, -76.99
    { 970, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfbcab6} }, // 883 OSM: 1405856 WD: Q4979520 38.9, -77.96 x 39.46, -76.99
    { 974, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfbcab6} }, // 873 OSM: 1405856 WD: Q4979520 38.9, -77.96 x 39.46, -76.99
    { 978, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfbcab6} }, // 875 OSM: 1405856 WD: Q4979520 38.9, -77.96 x 39.46, -76.99
    { 982, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfbcab6} }, // 881 OSM: 1405856 WD: Q4979520 38.9, -77.96 x 39.46, -76.99
    { 986, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfbcab6} }, // 870 OSM: 1405857 WD: Q4979520 38.9, -77.96 x 39.46, -76.99
    { 137, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfbcab6} }, // 872 OSM: 1405857 WD: Q4979520 38.9, -77.96 x 39.46, -76.99
    { 990, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfbcab6} }, // 880 OSM: 1405857 WD: Q4979520 38.9, -77.96 x 39.46, -76.99
    { 994, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfbcab6} }, // 874 OSM: 1405857 WD: Q4979520 38.9, -77.96 x 39.46, -76.99
    { 998, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfbcab6} }, // 876 OSM: 1405857 WD: Q4979520 38.9, -77.96 x 39.46, -76.99
    { 1002, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfbcab6} }, // 878 OSM: 1405857 WD: Q4979520 38.9, -77.96 x 39.46, -76.99
    { 1006, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff7f00} }, // 12E OSM: 1411178 WD: Q1487139 38.71, -9.138 x 38.72, -9.13
    { 1010, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff00ff} }, // 15E OSM: 1411205 WD: Q63229924 38.69, -9.233 x 38.71, -9.135
    { 233, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xb1c800} }, // F OSM: 1416967 48.57, 7.724 x 48.59, 7.777
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfed265} }, // 4 OSM: 1443866 46.24, 20.12 x 46.28, 20.16
    { 1014, NoLogo, 161, LineMetaDataContent::RapidTransit, Color{} }, // S26 OSM: 1444441 WD: Q819377 47.45, 9.591 x 47.47, 9.601
    { 6, 2530, 2554, LineMetaDataContent::Subway, Color{0x802f08} }, // 5 OSM: 1462012 WD: Q831673 55.73, 37.57 x 55.78, 37.66
    { 9, 2659, 2554, LineMetaDataContent::Subway, Color{0x33ccff} }, // 4 OSM: 1463287 WD: Q834540 55.73, 37.45 x 55.75, 37.61
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe5005a} }, // 3 OSM: 1469415 51.02, 13.7 x 51.1, 13.75
    { 59, 2683, 2554, LineMetaDataContent::Subway, Color{0x0000ff} }, // 3 OSM: 1472548 WD: Q626941 55.73, 37.35 x 55.86, 37.8
    { 55, 2707, 2554, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 1475758 WD: Q729631 55.56, 37.4 x 55.82, 37.75
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffa500} }, // 4 OSM: 1476874 56.45, 84.98 x 56.48, 85.02
    { 1019, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe6f2fc} }, // 98 OSM: 1490387 52.36, 13.03 x 52.4, 13.1
    { 951, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 91 OSM: 1492311 52.36, 13.01 x 52.4, 13.1
    { 219, 2731, NoLogo, LineMetaDataContent::Subway, Color{0x0000ff} }, // A OSM: 1502599 WD: Q17621067 6.152, -75.63 x 6.339, -75.54
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // 1 OSM: 1503481 56.47, 84.95 x 56.53, 85.02
    { 1003, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x897cb9} }, // 78 OSM: 1504645 WD: Q6811971 -37.87, 145 x -37.81, 145
    { 935, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x19488e} }, // 92 OSM: 1505928 52.36, 13.03 x 52.42, 13.14
    { 955, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfe9800} }, // 93 OSM: 1509473 52.36, 13.06 x 52.41, 13.1
    { 939, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfe9800} }, // 94 OSM: 1512265 52.37, 13.01 x 52.4, 13.11
    { 1022, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x803c9f} }, // S33 OSM: 1513484 49.12, 8.364 x 49.24, 8.594
    { 27, 2770, 2554, LineMetaDataContent::Subway, Color{0xffa500} }, // 6 OSM: 1514439 WD: Q175271 55.6, 37.51 x 55.89, 37.67
    { 42, 2794, 2554, LineMetaDataContent::Subway, Color{0xff00ff} }, // 7 OSM: 1516383 WD: Q924028 55.67, 37.43 x 55.86, 37.86
    { 19, 2818, 2554, LineMetaDataContent::Subway, Color{0xffff00} }, // 8 OSM: 1526351 WD: Q585986 55.74, 37.63 x 55.76, 37.87
    { 65, 2842, 2554, LineMetaDataContent::Subway, Color{0xb4d445} }, // 10 OSM: 1532877 WD: Q582194 55.61, 37.55 x 55.87, 37.76
    { 1026, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xed1c24} }, // N19 OSM: 1536166 48.12, 11.46 x 48.15, 11.64
    { 153, NoLogo, 161, LineMetaDataContent::RapidTransit, Color{0x0097d8} }, // S3 OSM: 1549250 WD: Q7388286 47.32, 8.501 x 47.53, 8.806
    { 504, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xed1c24} }, // 35 OSM: 1555118 44.42, 25.98 x 44.45, 26.07
    { 181, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xffd900} }, // B OSM: 1557177 WD: Q3239063 43.56, 1.43 x 43.64, 1.478
    { 190, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x004687} }, // T1 OSM: 1557178 43.59, 1.362 x 43.66, 1.446
    { 219, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xdb001b} }, // A OSM: 1557179 WD: Q3239050 43.57, 1.392 x 43.63, 1.483
    { 1030, NoLogo, 161, LineMetaDataContent::RapidTransit, Color{0xf6c454} }, // S10 OSM: 1561016 WD: Q687279 47.35, 8.465 x 47.38, 8.54
    { 196, NoLogo, 161, LineMetaDataContent::RapidTransit, Color{0xe67d63} }, // S4 OSM: 1567629 WD: Q685807 47.27, 8.517 x 47.38, 8.558
    { 119, 2867, 2554, LineMetaDataContent::Subway, Color{0xa0a2a3} }, // 9 OSM: 1570146 WD: Q739170 55.57, 37.57 x 55.9, 37.63
    { 1034, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe73035} }, // 300-315 OSM: 1571429 38.3, -77.46 x 38.53, -77.29
    { 16, 2891, 2554, LineMetaDataContent::Subway, Color{0x006400} }, // 2 OSM: 1572626 WD: Q834482 55.61, 37.47 x 55.88, 37.77
    { 175, NoLogo, 161, LineMetaDataContent::RapidTransit, Color{0x946644} }, // S24 OSM: 1574036 WD: Q7388228 47.17, 8.516 x 47.75, 9.106
    { 15, 2915, 2554, LineMetaDataContent::Subway, Color{0xa8bce2} }, // 12 OSM: 1580617 WD: Q678759 55.54, 37.52 x 55.6, 37.59
    { 320, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfe9800} }, // 96 OSM: 1585204 52.36, 13.05 x 52.43, 13.14
    { 1043, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x59c133} }, // 99 OSM: 1585259 52.39, 13.06 x 52.4, 13.11
    { 53, NoLogo, 161, LineMetaDataContent::RapidTransit, Color{0xccaaff} }, // S11 OSM: 1588232 WD: Q56435440 47.37, 8.048 x 47.54, 8.771
    { 1046, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // M Line OSM: 1600326 42.27, -71.09 x 42.28, -71.06
    { 186, NoLogo, 161, LineMetaDataContent::RapidTransit, Color{0x7751a1} }, // S6 OSM: 1609735 WD: Q7388350 47.26, 8.305 x 47.48, 8.683
    { 1053, NoLogo, 161, LineMetaDataContent::RapidTransit, Color{0xd8242b} }, // S12 OSM: 1614502 WD: Q7388182 47.37, 8.208 x 47.7, 9.042
    { 25, NoLogo, 161, LineMetaDataContent::RapidTransit, Color{0x64b97a} }, // S16 OSM: 1618466 WD: Q7388193 47.28, 8.511 x 47.45, 8.621
    { 1022, NoLogo, 161, LineMetaDataContent::RapidTransit, Color{0x2da7df} }, // S33 OSM: 1619213 WD: Q7388269 47.5, 8.611 x 47.7, 8.726
    { 466, NoLogo, 161, LineMetaDataContent::RapidTransit, Color{0x00a34f} }, // S9 OSM: 1620987 WD: Q7388394 47.35, 8.501 x 47.7, 8.721
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc32b3c} }, // 2 OSM: 1624727 WD: Q60282113 51.75, 14.31 x 51.76, 14.35
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x239537} }, // 4 OSM: 1628047 WD: Q60328960 51.72, 14.32 x 51.79, 14.35
    { 524, 2940, 2957, LineMetaDataContent::Tramway, Color{0xbb4a9b} }, // T2 OSM: 1635139 WD: Q369969 48.82, 2.217 x 48.92, 2.288
    { 495, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // C-1 OSM: 1636998 41.63, -1.023 x 41.72, -0.8655
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xece116} }, // 1 OSM: 1637446 WD: Q60213236 51.75, 14.33 x 51.78, 14.34
    { 219, 2981, NoLogo, LineMetaDataContent::Subway, Color{0x1ca4cb} }, // A OSM: 1637478 WD: Q1209679 -34.63, -58.47 x -34.61, -58.37
    { 22, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x54ad4b} }, // 18 OSM: 1646141 50.73, 6.893 x 50.98, 7.096
    { 1057, NoLogo, 2407, LineMetaDataContent::RapidTransit, Color{0xed677e} }, // H9 OSM: 1647378 WD: Q947539 47.5, 19.14 x 47.55, 19.27
    { 1060, NoLogo, 2407, LineMetaDataContent::RapidTransit, Color{0xed677e} }, // H8 OSM: 1647379 WD: Q947539 47.5, 19.14 x 47.6, 19.36
    { 1063, NoLogo, 2407, LineMetaDataContent::RapidTransit, Color{0x824b00} }, // H6 OSM: 1647380 WD: Q1031918 47.18, 18.94 x 47.47, 19.12
    { 55, NoLogo, 1354, LineMetaDataContent::Tramway, Color{0xffd800} }, // 1 OSM: 1658046 WD: Q651686 47.46, 19.02 x 47.55, 19.11
    { 168, NoLogo, 1354, LineMetaDataContent::Tramway, Color{0xffd800} }, // 50 OSM: 1658057 WD: Q643837 47.43, 19.13 x 47.47, 19.22
    { 87, NoLogo, 1354, LineMetaDataContent::Tramway, Color{0xffd800} }, // 62 OSM: 1658060 WD: Q1491622 47.48, 19.07 x 47.54, 19.14
    { 1067, NoLogo, 1354, LineMetaDataContent::Tramway, Color{0xffd800} }, // 42 OSM: 1658062 WD: Q1490864 47.45, 19.13 x 47.47, 19.15
    { 59, NoLogo, 1354, LineMetaDataContent::Tramway, Color{0xffd800} }, // 3 OSM: 1658063 WD: Q1490196 47.44, 19.09 x 47.52, 19.14
    { 126, NoLogo, 1354, LineMetaDataContent::Tramway, Color{0xffd800} }, // 14 OSM: 1658066 WD: Q1485881 47.52, 19.06 x 47.59, 19.12
    { 1070, NoLogo, 1354, LineMetaDataContent::Tramway, Color{0xffd800} }, // 69 OSM: 1658067 WD: Q1491929 47.52, 19.09 x 47.55, 19.15
    { 1074, NoLogo, 1354, LineMetaDataContent::Tramway, Color{0xffd800} }, // 52 OSM: 1658071 WD: Q1491293 47.42, 19.1 x 47.47, 19.13
    { 1077, NoLogo, 1354, LineMetaDataContent::Tramway, Color{0xffd800} }, // 62A OSM: 1658072 WD: Q743389 47.48, 19.1 x 47.54, 19.14
    { 91, NoLogo, 1354, LineMetaDataContent::Tramway, Color{0xffd800} }, // 37 OSM: 1658073 WD: Q1490525 47.47, 19.07 x 47.5, 19.18
    { 1081, NoLogo, 1354, LineMetaDataContent::Tramway, Color{0xffd800} }, // 51A OSM: 1658076 WD: Q16516127 47.47, 19.07 x 47.48, 19.09
    { 256, NoLogo, 1354, LineMetaDataContent::Tramway, Color{0xffd800} }, // 51 OSM: 1658077 WD: Q1491245 47.44, 19.07 x 47.48, 19.12
    { 1085, NoLogo, 1354, LineMetaDataContent::Tramway, Color{0xffd800} }, // 28A OSM: 1658080 WD: Q12813290 47.47, 19.07 x 47.5, 19.18
    { 1090, NoLogo, 1354, LineMetaDataContent::Tramway, Color{0xffd800} }, // 28 OSM: 1658081 WD: Q1490084 47.47, 19.07 x 47.5, 19.18
    { 1093, NoLogo, 1354, LineMetaDataContent::Tramway, Color{0xffd800} }, // 37A OSM: 1658082 WD: Q287376 47.49, 19.07 x 47.5, 19.14
    { 61, 3009, 161, LineMetaDataContent::RapidTransit, Color{0x33b540} }, // S1 OSM: 1660624 WD: Q19377130 53.55, 9.705 x 53.65, 10.09
    { 42, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00ff00} }, // 7 OSM: 1668728 WD: Q16350085 56.91, 24.1 x 56.96, 24.19
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00ff00} }, // 5 OSM: 1671375 WD: Q16349936 56.94, 24.06 x 57.02, 24.13
    { 1099, 3024, 1346, LineMetaDataContent::RapidTransit, Color{0x5e9620} }, // D OSM: 1673421 WD: Q1425351 48.29, 2.344 x 49.27, 2.657
    { 97, 3045, 562, LineMetaDataContent::Subway, Color{0xff0000} }, // U2 OSM: 1676043 WD: Q3433227 49.42, 11.03 x 49.49, 11.11
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xdc008f} }, // 1 OSM: 1679960 50.09, 14.34 x 50.11, 14.5
    { 119, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00ff00} }, // 9 OSM: 1685792 WD: Q16350160 56.91, 24.1 x 57, 24.19
    { 97, 3062, 562, LineMetaDataContent::Subway, Color{0xee1d23} }, // U2 OSM: 1686090 WD: Q275451 53.53, 9.943 x 53.64, 10.15
    { 94, 3077, 562, LineMetaDataContent::Subway, Color{0x0066b3} }, // U1 OSM: 1687370 WD: Q248623 53.55, 9.985 x 53.71, 10.29
    { 54, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 11 OSM: 1687743 56.95, 24.11 x 57.01, 24.17
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00ff00} }, // 3 OSM: 1715019 WD: Q16349678 56.91, 24.11 x 56.99, 24.24
    { 728, 3092, 161, LineMetaDataContent::RapidTransit, Color{0x5d1d81} }, // S31 OSM: 1727359 WD: Q19368873 53.46, 9.851 x 53.56, 10.03
    { 232, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfed265} }, // 3F OSM: 1733222 46.25, 20.11 x 46.28, 20.16
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfed265} }, // 3 OSM: 1733225 46.25, 20.12 x 46.28, 20.16
    { 65, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00ff00} }, // 10 OSM: 1757059 WD: Q13098696 56.91, 24.08 x 56.95, 24.14
    { 1101, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // СТ OSM: 1759150 48.7, 44.5 x 48.8, 44.6
    { 1106, 3108, NoLogo, LineMetaDataContent::Subway, Color{0x0000ff} }, // 2 Салтівська OSM: 1766294 WD: Q2332390 49.99, 36.23 x 50.03, 36.34
    { 55, 3130, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 1766295 WD: Q2710248 49.95, 36.18 x 49.99, 36.4
    { 59, 3152, NoLogo, LineMetaDataContent::Subway, Color{0x008000} }, // 3 OSM: 1766296 WD: Q2109890 49.98, 36.2 x 50.06, 36.27
    { 55, 3174, NoLogo, LineMetaDataContent::Tramway, Color{} }, // 1 OSM: 1767386 WD: Q63890946 50.41, 30.38 x 50.45, 30.49
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 1 OSM: 1787910 55.67, 52.28 x 55.73, 52.53
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // 2 OSM: 1788097 55.67, 52.28 x 55.73, 52.47
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x006400} }, // 12 OSM: 1789317 55.67, 52.28 x 55.77, 52.44
    { 130, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x3e6c01} }, // 15 OSM: 1808234 39.96, -75.25 x 39.98, -75.13
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 12 OSM: 1809578 29.93, -90.13 x 29.95, -90.07
    { 535, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 47 OSM: 1809579 29.95, -90.11 x 29.98, -90.06
    { 416, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x90ee90} }, // 48 OSM: 1809580 29.95, -90.1 x 29.98, -90.06
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // 2 OSM: 1809582 WD: Q18155116 29.94, -90.06 x 29.96, -90.06
    { 1129, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa82618} }, // SSL OSM: 1811654 41.59, -87.62 x 41.88, -86.29
    { 524, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x96bf0d} }, // T2 OSM: 1824544 47.29, 5.006 x 47.37, 5.059
    { 190, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xcc0088} }, // T1 OSM: 1824550 47.31, 5.028 x 47.33, 5.112
    { 1097, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffb531} }, // UFD OSM: 1825844 WD: Q7898275 -37.82, 144.9 x -37.66, 145
    { 1133, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffb531} }, // CGB OSM: 1825882 WD: Q5181702 -37.82, 144.9 x -37.6, 145
    { 1137, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffb531} }, // SBY OSM: 1825925 WD: Q7639008 -37.82, 144.7 x -37.58, 145
    { 1141, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x149943} }, // WIL OSM: 1825966 WD: Q8021313 -37.87, 144.9 x -37.8, 145
    { 1145, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x149943} }, // WER OSM: 1826009 WD: Q7983583 -37.9, 144.7 x -37.8, 145
    { 1150, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x4f4a9f} }, // 30 OSM: 1830395 WD: Q6811953 -37.81, 144.9 x -37.81, 145
    { 1153, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe42b23} }, // HBE OSM: 1830850 WD: Q16927215 -37.82, 145 x -37.64, 145.2
    { 298, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x094b8d} }, // ALM OSM: 1831005 WD: Q4705897 -37.87, 145 x -37.81, 145.1
    { 1157, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x094b8d} }, // LIL OSM: 1831006 WD: Q6548623 -37.83, 145 x -37.75, 145.3
    { 1161, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xc60c30} }, // Port Washington OSM: 1834644 WD: Q7231025 40.7, -73.99 x 40.83, -73.69
    { 100, 3190, 562, LineMetaDataContent::Subway, Color{0x00868b} }, // U3 OSM: 1857497 WD: Q3433219 49.44, 11.04 x 49.47, 11.09
    { 94, 3207, 562, LineMetaDataContent::Subway, Color{0x000066} }, // U1 OSM: 1857639 WD: Q3433210 49.4, 10.96 x 49.48, 11.14
    { 219, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe30613} }, // A OSM: 1874970 WD: Q2066292 49.23, 4.004 x 49.28, 4.031
    { 181, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009fe3} }, // B OSM: 1874971 WD: Q2085986 49.22, 3.996 x 49.28, 4.032
    { 186, 3224, 161, LineMetaDataContent::RapidTransit, Color{0xf57921} }, // S6 OSM: 1880910 WD: Q3238987 50.1, 8.633 x 50.34, 8.789
    { 164, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8d1d2c} }, // 17 OSM: 1903836 47.35, 8.482 x 47.4, 8.542
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x9bd6f9} }, // 4 OSM: 1904829 50.03, 14.37 x 50.08, 14.46
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xed1c24} }, // 8 OSM: 1927430 44.39, 25.98 x 44.43, 26.09
    { 181, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x406681} }, // B OSM: 1940503 35.02, 135.7 x 35.03, 135.7
    { 219, 3241, NoLogo, LineMetaDataContent::Tramway, Color{0xa83939} }, // A OSM: 1940504 WD: Q10883225 35, 135.7 x 35.02, 135.7
    { 214, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x913108} }, // C OSM: 1958845 37.79, -122.4 x 37.79, -122.4
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x003828} }, // 2 OSM: 1984325 52.9, -1.207 x 52.99, -1.145
    { 1177, 3286, NoLogo, LineMetaDataContent::Tramway, Color{0xfcc70d} }, // SG OSM: 1994315 WD: Q339069 35.64, 139.6 x 35.67, 139.7
    { 439, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x004ea2} }, // SL OSM: 1994316 WD: Q6360898 35.33, 139.6 x 35.39, 139.7
    { 330, 3311, 19, LineMetaDataContent::Tramway, Color{0x33ff33} }, // M2 OSM: 2001598 WD: Q62512253 52.52, 13.41 x 52.57, 13.44
    { 1180, 414, NoLogo, LineMetaDataContent::Subway, Color{0x302276} }, // U75 OSM: 2003447 WD: Q661002 51.2, 6.684 x 51.23, 6.847
    { 1184, 414, NoLogo, LineMetaDataContent::Subway, Color{0x302276} }, // U78 OSM: 2003448 WD: Q661002 51.22, 6.733 x 51.27, 6.795
    { 58, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x967b68} }, // 13 OSM: 2003476 50.91, 6.908 x 50.97, 7.038
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x948fb8} }, // 5 OSM: 2003477 50.93, 6.888 x 50.98, 6.96
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfff500} }, // 5 OSM: 2024979 50.03, 14.37 x 50.09, 14.53
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe693b5} }, // 3 OSM: 2026288 50.93, 6.87 x 50.98, 7.086
    { 80, NoLogo, 414, LineMetaDataContent::Tramway, Color{0x98c000} }, // 61 OSM: 2026289 WD: Q20035840 50.7, 7.071 x 50.76, 7.112
    { 87, NoLogo, 414, LineMetaDataContent::Tramway, Color{0x61af20} }, // 62 OSM: 2026290 WD: Q20035841 50.7, 7.095 x 50.74, 7.176
    { 76, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x60d6f7} }, // 63 OSM: 2026291 50.68, 7.047 x 50.75, 7.159
    { 156, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xee99bf} }, // 67 OSM: 2026293 50.68, 7.092 x 50.79, 7.203
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf7d09b} }, // 6 OSM: 2032473 50.07, 14.42 x 50.11, 14.48
    { 42, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00ffff} }, // 7 OSM: 2061854 50.06, 14.39 x 50.08, 14.51
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009cdd} }, // 1 OSM: 2067963 53.41, 14.49 x 53.47, 14.56
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009cdd} }, // 3 OSM: 2073969 53.4, 14.52 x 53.46, 14.55
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009cdd} }, // 12 OSM: 2074000 53.4, 14.53 x 53.45, 14.55
    { 190, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe3002b} }, // T1 OSM: 2074462 48.65, 6.145 x 48.7, 6.225
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009cdd} }, // 5 OSM: 2077222 53.43, 14.49 x 53.45, 14.58
    { 54, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009cdd} }, // 11 OSM: 2077355 53.4, 14.53 x 53.45, 14.58
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009cdd} }, // 6 OSM: 2077516 53.4, 14.53 x 53.48, 14.61
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009cdd} }, // 8 OSM: 2080359 53.42, 14.49 x 53.45, 14.55
    { 42, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009cdd} }, // 7 OSM: 2080360 53.41, 14.49 x 53.45, 14.55
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xef7c00} }, // 3 OSM: 2083643 48.31, 10.84 x 48.37, 10.9
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x94c11c} }, // 6 OSM: 2083654 48.35, 10.89 x 48.37, 10.96
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xb5c426} }, // 1 OSM: 2100315 WD: Q6811945 -37.85, 144.9 x -37.74, 145
    { 243, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00bfe8} }, // N20 OSM: 2101204 48.14, 11.51 x 48.18, 11.56
    { 55, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // 1 OSM: 2102327 51.98, 8.502 x 52.06, 8.546
    { 58, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // 13 OSM: 2102328 52, 8.532 x 52.06, 8.559
    { 59, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffff00} }, // 3 OSM: 2102329 52, 8.518 x 52.06, 8.589
    { 16, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // 2 OSM: 2102391 52, 8.532 x 52.06, 8.628
    { 9, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // 4 OSM: 2102392 52.02, 8.485 x 52.05, 8.543
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffeedd} }, // 1 OSM: 2104341 54.14, 19.39 x 54.19, 19.44
    { 1188, 3330, 161, LineMetaDataContent::RapidTransit, Color{0xe7526b} }, // S20 OSM: 2113865 WD: Q7388223 48.04, 11.46 x 48.15, 11.54
    { 41, 3347, 161, LineMetaDataContent::RapidTransit, Color{0x983224} }, // S7 OSM: 2113867 WD: Q7388364 47.91, 11.42 x 48.14, 11.78
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00a651} }, // 1 OSM: 2116454 47.2, -1.639 x 47.26, -1.515
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xee1c25} }, // 2 OSM: 2166523 47.19, -1.593 x 47.26, -1.542
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x006db1} }, // 3 OSM: 2166524 47.18, -1.617 x 47.25, -1.542
    { 19, NoLogo, 3363, LineMetaDataContent::RapidTransit, Color{0x808080} }, // 8 OSM: 2174536 WD: Q3296720 -23.55, -46.98 x -23.51, -46.64
    { 119, NoLogo, 3363, LineMetaDataContent::RapidTransit, Color{0x00a88e} }, // 9 OSM: 2183695 WD: Q5245848 -23.74, -46.78 x -23.53, -46.69
    { 196, NoLogo, 161, LineMetaDataContent::RapidTransit, Color{0x000080} }, // S4 OSM: 2199152 WD: Q7388307 49.25, 10.3 x 49.44, 11.08
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x006699} }, // 2 OSM: 2203208 48.98, 8.347 x 49.03, 8.479
    { 54, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xed1c24} }, // 11 OSM: 2205114 44.38, 26.02 x 44.47, 26.15
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 3 OSM: 2206996 41.87, 12.47 x 41.92, 12.52
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x1c63b7} }, // 2 OSM: 2206997 41.91, 12.46 x 41.93, 12.48
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xed1c24} }, // 5 OSM: 2206998 41.88, 12.5 x 41.9, 12.57
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xbfdf14} }, // 8 OSM: 2206999 41.87, 12.44 x 41.9, 12.52
    { 219, 3377, 1962, LineMetaDataContent::Subway, Color{0xf68b1f} }, // A OSM: 2207255 WD: Q572544 41.84, 12.42 x 41.91, 12.59
    { 181, 3405, 1962, LineMetaDataContent::Subway, Color{0x3783c6} }, // B OSM: 2208346 WD: Q2666571 41.83, 12.46 x 41.95, 12.57
    { 1192, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfbbc09} }, // FC1 OSM: 2208347 41.87, 12.51 x 41.9, 12.56
    { 1196, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7eb9e6} }, // FC2 OSM: 2208348 41.71, 12.28 x 41.88, 12.48
    { 1200, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x55b036} }, // FC3 OSM: 2208349 41.91, 12.11 x 42.44, 12.5
    { 126, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00adef} }, // 14 OSM: 2208350 41.89, 12.5 x 41.9, 12.57
    { 134, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf89c0e} }, // 19 OSM: 2208351 41.88, 12.46 x 41.92, 12.57
    { 361, 3433, NoLogo, LineMetaDataContent::RapidTransit, Color{0x007663} }, // FL1 OSM: 2208499 WD: Q3737286 41.79, 12.25 x 42.44, 12.65
    { 365, 3468, NoLogo, LineMetaDataContent::RapidTransit, Color{0x004174} }, // FL2 OSM: 2208500 WD: Q3737287 41.9, 12.53 x 42.1, 13.43
    { 357, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x91510f} }, // FL4 OSM: 2208502 WD: Q25064 41.67, 12.5 x 41.9, 12.78
    { 1204, 3503, NoLogo, LineMetaDataContent::RapidTransit, Color{0xdccc00} }, // FL5 OSM: 2208503 WD: Q3737292 41.86, 11.8 x 42.09, 12.53
    { 1208, 3538, NoLogo, LineMetaDataContent::RapidTransit, Color{0xdc66ba} }, // FL6 OSM: 2208504 WD: Q3737295 41.48, 12.5 x 41.9, 13.83
    { 1212, 3573, NoLogo, LineMetaDataContent::RapidTransit, Color{0x91d44f} }, // FL7 OSM: 2208505 WD: Q661786 41.25, 12.5 x 41.9, 13.72
    { 1216, 3608, NoLogo, LineMetaDataContent::RapidTransit, Color{0x6cbf68} }, // FL8 OSM: 2208506 WD: Q3737301 41.45, 12.5 x 41.9, 12.66
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xed1c24} }, // 1 OSM: 2212352 44.4, 26.05 x 44.45, 26.14
    { 19, NoLogo, 3643, LineMetaDataContent::Tramway, Color{0x0098d4} }, // 8 OSM: 2262665 WD: Q431783 50.8, 4.353 x 50.85, 4.44
    { 1018, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00ff80} }, // 398 OSM: 2271832 32.72, -117.4 x 33.2, -117.2
    { 1220, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x669933} }, // 87 OSM: 2282096 WD: Q428288 52.44, 13.69 x 52.46, 13.76
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008f4d} }, // 1 OSM: 2309633 33.84, 132.8 x 33.85, 132.8
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf9a51b} }, // 2 OSM: 2309634 33.84, 132.8 x 33.85, 132.8
    { 219, 3669, 1346, LineMetaDataContent::RapidTransit, Color{0xd1302f} }, // A OSM: 2333448 WD: Q741818 48.75, 2.009 x 49.05, 2.783
    { 119, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x112233} }, // 9 OSM: 2336329 54.27, 48.29 x 54.34, 48.39
    { 55, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xe4002b} }, // 1 OSM: 2336458 WD: Q263572 29.53, 106.2 x 29.62, 106.6
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xd75128} }, // 4 OSM: 2368452 50.72, 12.43 x 50.75, 12.49
    { 65, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009cdd} }, // 10 OSM: 2372195 53.42, 14.49 x 53.46, 14.55
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfed265} }, // 2 OSM: 2380276 46.24, 20.13 x 46.27, 20.15
    { 55, 3690, NoLogo, LineMetaDataContent::Subway, Color{0x10069f} }, // 1 OSM: 2381769 WD: Q6118988 30.39, 104.1 x 30.72, 104.1
    { 47, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x04a5c8} }, // S8 OSM: 2396232 WD: Q2381339 41.35, 1.919 x 41.48, 2.149
    { 255, NoLogo, 161, LineMetaDataContent::RapidTransit, Color{0xf8a20d} }, // S51 OSM: 2412316 WD: Q96388878 49.3, 8.674 x 49.42, 8.991
    { 65, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xb4e16e} }, // 10 OSM: 2413392 57.68, 11.89 x 57.73, 11.98
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x872387} }, // 8 OSM: 2413517 57.65, 11.91 x 57.8, 12.05
    { 58, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfee6c2} }, // 13 OSM: 2413518 57.66, 11.85 x 57.71, 11.99
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfff014} }, // 2 OSM: 2413613 57.65, 11.93 x 57.71, 12.02
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x14823c} }, // 4 OSM: 2413615 57.65, 11.97 x 57.8, 12.05
    { 534, 3700, 161, LineMetaDataContent::RapidTransit, Color{0xba8a4d} }, // S47 OSM: 2413847 WD: Q3742025 52.45, 13.43 x 52.47, 13.56
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x004b85} }, // 3 OSM: 2418220 57.67, 11.91 x 57.72, 12.03
    { 119, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x6ec8dc} }, // 9 OSM: 2418235 57.68, 11.9 x 57.8, 12.05
    { 54, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 11 OSM: 2418236 57.66, 11.85 x 57.76, 12.07
    { 1223, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // 901 OSM: 2440421 WD: Q1617191 44.85, -93.28 x 44.98, -93.2
    { 247, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x61af20} }, // RB23 OSM: 2441590 WD: Q1699351 50.56, 6.761 x 50.74, 7.098
    { 1227, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf0e130} }, // 888 OSM: 2442946 44.98, -93.73 x 45.33, -93.25
    { 61, NoLogo, 161, LineMetaDataContent::RapidTransit, Color{0x0b9a33} }, // S1 OSM: 2444997 WD: Q7388210 51.16, 6.772 x 51.52, 7.46
    { 53, NoLogo, 161, LineMetaDataContent::RapidTransit, Color{0xef7c00} }, // S11 OSM: 2445000 WD: Q7388174 50.94, 6.674 x 51.28, 7.125
    { 1053, NoLogo, 161, LineMetaDataContent::RapidTransit, Color{0x61af20} }, // S12 OSM: 2445001 WD: Q7388180 50.76, 6.713 x 50.95, 7.66
    { 545, NoLogo, 161, LineMetaDataContent::RapidTransit, Color{0x00a6eb} }, // S13 OSM: 2445007 WD: Q7388184 50.81, 6.482 x 50.95, 7.151
    { 50, NoLogo, 161, LineMetaDataContent::RapidTransit, Color{0x006db6} }, // S2 OSM: 2445008 WD: Q7388251 51.45, 7.015 x 51.62, 7.46
    { 1089, NoLogo, 161, LineMetaDataContent::RapidTransit, Color{0x717676} }, // S28 OSM: 2445009 WD: Q7388234 51.2, 6.594 x 51.25, 6.988
    { 153, NoLogo, 161, LineMetaDataContent::RapidTransit, Color{0x999999} }, // S3 OSM: 2445010 WD: Q7388285 51.4, 6.835 x 51.48, 7.181
    { 196, NoLogo, 161, LineMetaDataContent::RapidTransit, Color{0xef7c00} }, // S4 OSM: 2445011 WD: Q7388319 51.5, 7.334 x 51.55, 7.698
    { 44, NoLogo, 161, LineMetaDataContent::RapidTransit, Color{0x98c60f} }, // S5 OSM: 2445012 WD: Q7388333 51.36, 7.325 x 51.52, 7.46
    { 186, NoLogo, 161, LineMetaDataContent::RapidTransit, Color{0xdc052d} }, // S6 OSM: 2445013 WD: Q7388349 50.94, 6.79 x 51.45, 7.023
    { 83, NoLogo, 161, LineMetaDataContent::RapidTransit, Color{0x14bae6} }, // S68 OSM: 2445014 WD: Q7388346 51.1, 6.79 x 51.23, 7.074
    { 47, NoLogo, 161, LineMetaDataContent::RapidTransit, Color{0xb03303} }, // S8 OSM: 2445015 WD: Q7388383 51.19, 6.445 x 51.36, 7.46
    { 466, NoLogo, 161, LineMetaDataContent::RapidTransit, Color{0xc7007f} }, // S9 OSM: 2445016 WD: Q7388395 51.23, 6.921 x 51.74, 7.46
    { 61, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xec192e} }, // S1 OSM: 2445551 49.33, 7.334 x 49.48, 9.424
    { 50, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x2960b5} }, // S2 OSM: 2445552 49.34, 7.767 x 49.48, 9.144
    { 153, 3715, 161, LineMetaDataContent::RapidTransit, Color{0x00a896} }, // S3 OSM: 2445553 WD: Q2781002 49.87, 8.504 x 50.16, 8.699
    { 153, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfcd804} }, // S3 OSM: 2445554 48.99, 8.349 x 49.48, 8.685
    { 196, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x1a9d47} }, // S4 OSM: 2445555 48.99, 8.349 x 49.48, 9.528
    { 55, 3732, 3752, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 2446076 WD: Q519861 59.84, 30.25 x 60.05, 30.44
    { 16, 3771, 3752, LineMetaDataContent::Subway, Color{0x0000ff} }, // 2 OSM: 2446077 WD: Q1459627 59.83, 30.3 x 60.07, 30.38
    { 59, 3791, 3752, LineMetaDataContent::Subway, Color{0x008000} }, // 3 OSM: 2446078 WD: Q1509576 59.83, 30.2 x 59.99, 30.5
    { 9, 3811, 3752, LineMetaDataContent::Subway, Color{0xffa500} }, // 4 OSM: 2446079 WD: Q1784097 59.91, 30.32 x 59.93, 30.48
    { 6, 3831, 3752, LineMetaDataContent::Subway, Color{0x800080} }, // 5 OSM: 2446080 WD: Q1579583 59.82, 30.25 x 60.01, 30.43
    { 524, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf5e615} }, // T2 OSM: 2449769 43.3, 5.367 x 43.32, 5.406
    { 190, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf18e00} }, // T1 OSM: 2452278 43.29, 5.381 x 43.3, 5.445
    { 1231, 3851, NoLogo, LineMetaDataContent::Subway, Color{0x008cd1} }, // Γ3 OSM: 2473158 WD: Q6553119 37.91, 23.67 x 38.02, 23.95
    { 153, NoLogo, 161, LineMetaDataContent::RapidTransit, Color{0xdb6eab} }, // S3 OSM: 2474189 WD: Q63433452 52.16, 9.739 x 52.38, 10.02
    { 44, NoLogo, 161, LineMetaDataContent::RapidTransit, Color{0xf78a18} }, // S5 OSM: 2474199 WD: Q63433456 51.71, 8.737 x 52.46, 9.773
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0000ff} }, // 2 OSM: 2507796 WD: Q2001449 41.29, 69.2 x 41.35, 69.32
    { 59, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x008000} }, // 3 OSM: 2507797 WD: Q491886 41.3, 69.27 x 41.35, 69.29
    { 55, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 2507927 WD: Q4515924 41.26, 69.2 x 41.33, 69.33
    { 44, 3875, 161, LineMetaDataContent::RapidTransit, Color{0xa52a2a} }, // S5 OSM: 2515355 WD: Q2515085 50.1, 8.583 x 50.25, 8.699
    { 196, 3892, 161, LineMetaDataContent::RapidTransit, Color{0xfecb09} }, // S4 OSM: 2515408 WD: Q2204443 49.99, 8.516 x 50.18, 8.699
    { 41, NoLogo, 161, LineMetaDataContent::RapidTransit, Color{0x14bae6} }, // S7 OSM: 2544304 WD: Q1195962 51.16, 7.004 x 51.28, 7.253
    { 61, NoLogo, 161, LineMetaDataContent::RapidTransit, Color{0x7760b0} }, // S1 OSM: 2548861 WD: Q63433445 52.27, 8.934 x 52.42, 9.773
    { 1235, 3909, 3931, LineMetaDataContent::Subway, Color{0x79bb92} }, // 7bis OSM: 2554103 WD: Q50749 48.88, 2.366 x 48.88, 2.401
    { 186, NoLogo, 161, LineMetaDataContent::RapidTransit, Color{0x005aab} }, // S6 OSM: 2557420 WD: Q63433460 52.37, 9.739 x 52.62, 10.06
    { 1240, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x62361b} }, // Brown OSM: 2562976 WD: Q3112936 41.88, -87.71 x 41.97, -87.63
    { 196, NoLogo, 161, LineMetaDataContent::RapidTransit, Color{0x972f50} }, // S4 OSM: 2567719 WD: Q63433455 52.16, 9.687 x 52.58, 9.956
    { 8, NoLogo, 3943, LineMetaDataContent::Subway, Color{0x347c11} }, // M4 OSM: 2568424 WD: Q2552821 44.45, 26.02 x 44.5, 26.07
    { 190, 2940, 2957, LineMetaDataContent::Tramway, Color{0x216eb4} }, // T1 OSM: 2572573 WD: Q369969 48.9, 2.274 x 48.94, 2.47
    { 362, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xd6457d} }, // L1 OSM: 2575540 59.74, 10.34 x 59.96, 11.05
    { 1246, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xf9461c} }, // Orange OSM: 2578312 WD: Q3180068 41.79, -87.74 x 41.89, -87.63
    { 55, NoLogo, 3961, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 2580502 WD: Q1771534 56.24, 43.85 x 56.32, 44
    { 1253, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xa52a2a} }, // Scala mobile OSM: 2581270 41.84, 12.89 x 41.84, 12.89
    { 279, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xc60c30} }, // Red OSM: 2584583 WD: Q642623 41.72, -87.67 x 42.02, -87.62
    { 186, NoLogo, 161, LineMetaDataContent::RapidTransit, Color{0xec192e} }, // S6 OSM: 2587144 WD: Q96388302 49.44, 8.256 x 50, 8.582
    { 1266, NoLogo, 161, LineMetaDataContent::RapidTransit, Color{0x6b2c94} }, // S 8 OSM: 2605126 WD: Q63213955 51.47, 11.98 x 51.87, 12.66
    { 678, NoLogo, 161, LineMetaDataContent::RapidTransit, Color{0xf17f1a} }, // S 5 OSM: 2606971 WD: Q63216051 50.7, 11.99 x 51.48, 12.48
    { 1271, NoLogo, 161, LineMetaDataContent::RapidTransit, Color{0x00a650} }, // S 4 OSM: 2607472 WD: Q63215993 51.25, 12.37 x 51.59, 14.23
    { 61, NoLogo, 161, LineMetaDataContent::RapidTransit, Color{0x66cdaa} }, // S1 OSM: 2609006 WD: Q50331474 54.08, 12.06 x 54.17, 12.13
    { 153, NoLogo, 161, LineMetaDataContent::RapidTransit, Color{} }, // S3 OSM: 2609009 WD: Q50331483 53.79, 12.13 x 54.08, 12.35
    { 50, NoLogo, 161, LineMetaDataContent::RapidTransit, Color{0x9400d3} }, // S2 OSM: 2609011 WD: Q50331479 53.8, 12.06 x 54.17, 12.17
    { 469, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x009b3a} }, // Green OSM: 2613599 WD: Q3176204 41.78, -87.81 x 41.89, -87.61
    { 1275, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x75bdce} }, // U44 OSM: 2615764 51.51, 7.385 x 51.53, 7.484
    { 69, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe2000a} }, // 21 OSM: 2617691 49.4, 8.675 x 49.43, 8.693
    { 420, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfcc200} }, // 22 OSM: 2617692 49.4, 8.627 x 49.41, 8.693
    { 249, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe48e00} }, // 23 OSM: 2617693 49.34, 8.681 x 49.44, 8.693
    { 176, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8b1c75} }, // 24 OSM: 2617694 49.36, 8.66 x 49.47, 8.691
    { 1015, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf39a9a} }, // 26 OSM: 2617695 49.38, 8.658 x 49.41, 8.693
    { 119, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x93c13b} }, // 9 OSM: 2621592 49.48, 8.467 x 49.48, 8.525
    { 272, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xf9e300} }, // Yellow OSM: 2622574 WD: Q595450 42.02, -87.75 x 42.04, -87.67
    { 296, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x004595} }, // M OSM: 2629655 49.39, 1.042 x 49.45, 1.106
    { 1279, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x20825c} }, // PAO OSM: 2629939 WD: Q7132125 39.95, -75.76 x 40.05, -75.15
    { 119, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf171ab} }, // 9 OSM: 2629996 46.93, 7.436 x 46.97, 7.468
    { 65, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x90ee90} }, // 10 OSM: 2632695 49.83, 23.99 x 49.84, 24.07
    { 59, NoLogo, 3973, LineMetaDataContent::Subway, Color{0xa066aa} }, // 3 OSM: 2635252 WD: Q15731044 59.85, 10.5 x 59.94, 10.85
    { 1284, 3994, 19, LineMetaDataContent::Tramway, Color{0x00bfe8} }, // 29 OSM: 2635531 WD: Q63435524 48.14, 11.49 x 48.16, 11.56
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffff00} }, // 6 OSM: 2635960 55.67, 52.28 x 55.77, 52.45
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x3adf00} }, // 8 OSM: 2635970 55.67, 52.28 x 55.77, 52.45
    { 16, NoLogo, 3973, LineMetaDataContent::Subway, Color{0xf26522} }, // 2 OSM: 2636245 WD: Q15731043 59.91, 10.61 x 59.95, 10.92
    { 6, NoLogo, 3973, LineMetaDataContent::Subway, Color{0x50b848} }, // 5 OSM: 2640907 WD: Q15731051 59.91, 10.71 x 59.97, 10.93
    { 1287, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // Meadowlands OSM: 2641818 WD: Q6803384 40.73, -74.1 x 40.83, -74.03
    { 1299, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa0218c} }, // Pascack Valley OSM: 2641819 WD: Q11328810 40.73, -74.1 x 41.11, -74.01
    { 1314, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x6e689c} }, // U46 OSM: 2642232 51.5, 7.459 x 51.53, 7.471
    { 1318, 4022, NoLogo, LineMetaDataContent::Tramway, Color{0x873f98} }, // T5 OSM: 2643507 WD: Q3238967 45.73, 4.88 x 45.74, 4.948
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // 3 OSM: 2644926 55.72, 52.41 x 55.77, 52.5
    { 1321, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa0a0a0} }, // C-8 OSM: 2647592 40.38, -4.067 x 40.74, -3.181
    { 219, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x802990} }, // A OSM: 2648050 44.83, -0.6686 x 44.89, -0.5081
    { 181, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xed164b} }, // B OSM: 2648235 44.79, -0.6632 x 44.89, -0.5415
    { 1325, 1962, 1962, LineMetaDataContent::Subway, Color{0xff0000} }, // Metropolitana OSM: 2653212 WD: Q1163754 44.4, 8.894 x 44.43, 8.949
    { 27, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x2c8195} }, // 6 OSM: 2653338 WD: Q6553143 25.03, 102.8 x 25.1, 102.9
    { 214, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xcf56a0} }, // C OSM: 2654042 44.77, -0.6237 x 44.92, -0.5499
    { 1339, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xe27ea6} }, // Pink OSM: 2656070 WD: Q3112661 41.85, -87.76 x 41.89, -87.63
    { 267, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x00a1de} }, // Blue OSM: 2672370 WD: Q2534873 41.87, -87.9 x 41.98, -87.63
    { 1344, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x78ac28} }, // U47 OSM: 2673747 51.49, 7.382 x 51.55, 7.556
    { 119, 4042, 2022, LineMetaDataContent::Subway, Color{0x87d300} }, // 9 OSM: 2674584 WD: Q5929508 39.81, 116.3 x 39.94, 116.3
    { 427, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfde54f} }, // U41 OSM: 2674820 51.48, 7.44 x 51.59, 7.502
    { 423, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009980} }, // U43 OSM: 2675103 51.51, 7.419 x 51.53, 7.625
    { 42, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x9e0234} }, // 7 OSM: 2675693 51.04, 13.63 x 51.14, 13.8
    { 1352, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x522398} }, // Purple OSM: 2675822 WD: Q3112074 41.88, -87.69 x 42.07, -87.63
    { 61, NoLogo, 1431, LineMetaDataContent::RapidTransit, Color{0x343593} }, // S1 OSM: 2679058 WD: Q17101540 48.17, 16.33 x 48.34, 16.74
    { 50, 1431, 161, LineMetaDataContent::RapidTransit, Color{0x20bcbd} }, // S2 OSM: 2679059 WD: Q695595 48.08, 16.28 x 48.72, 16.57
    { 153, 1431, 161, LineMetaDataContent::RapidTransit, Color{0x9d0921} }, // S3 OSM: 2679060 WD: Q695595 47.81, 16.06 x 48.56, 16.41
    { 50, NoLogo, 161, LineMetaDataContent::RapidTransit, Color{0x118349} }, // S2 OSM: 2682237 WD: Q63433449 52.28, 9.217 x 52.65, 9.773
    { 1359, 4062, 2022, LineMetaDataContent::Subway, Color{0x007e84} }, // 4S OSM: 2684711 WD: Q5242742 39.67, 116.3 x 39.81, 116.4
    { 130, 4087, 2022, LineMetaDataContent::Subway, Color{0x6a1d44} }, // 15 OSM: 2688949 WD: Q734917 39.99, 116.3 x 40.13, 116.7
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x006b42} }, // 12 OSM: 2690192 51.04, 13.67 x 51.06, 13.81
    { 542, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00985f} }, // 6T OSM: 2692584 60.15, 24.91 x 60.21, 24.98
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x223344} }, // 2 OSM: 2694563 54.26, 48.28 x 54.34, 48.41
    { 1015, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00aaad} }, // 26 OSM: 2705952 59.27, 18.27 x 59.29, 18.3
    { 226, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00aaad} }, // 25 OSM: 2705957 59.28, 18.11 x 59.31, 18.31
    { 219, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffbf00} }, // A OSM: 2716905 32.98, -97.13 x 33.21, -96.93
    { 1362, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x003e7e} }, // TRE OSM: 2716975 WD: Q2453601 32.75, -97.33 x 32.82, -96.81
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0066} }, // 5 OSM: 2718682 339.5, 249.5 x 339.5, 249.5
    { 65, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xdc008f} }, // 10 OSM: 2728288 50.06, 14.3 x 50.13, 14.48
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xdc008f} }, // 12 OSM: 2729904 50.03, 14.37 x 50.11, 14.45
    { 11, 4108, 1962, LineMetaDataContent::Subway, Color{0x7956a3} }, // M5 OSM: 2753306 WD: Q3238963 45.48, 9.117 x 45.53, 9.212
    { 1366, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // 803 OSM: 2768040 37.33, -122.4 x 37.78, -121.9
    { 1370, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // 801 OSM: 2768040 37.33, -122.4 x 37.78, -121.9
    { 1374, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 425 OSM: 2768041 37.33, -122.4 x 37.78, -121.9
    { 1378, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 443 OSM: 2768041 37.33, -122.4 x 37.78, -121.9
    { 1382, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 441 OSM: 2768041 37.33, -122.4 x 37.78, -121.9
    { 1386, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 439 OSM: 2768041 37.33, -122.4 x 37.78, -121.9
    { 90, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 437 OSM: 2768041 37.33, -122.4 x 37.78, -121.9
    { 1390, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 433 OSM: 2768041 37.33, -122.4 x 37.78, -121.9
    { 1394, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 431 OSM: 2768041 37.33, -122.4 x 37.78, -121.9
    { 1283, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 429 OSM: 2768041 37.33, -122.4 x 37.78, -121.9
    { 1398, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 427 OSM: 2768041 37.33, -122.4 x 37.78, -121.9
    { 1402, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 435 OSM: 2768041 37.33, -122.4 x 37.78, -121.9
    { 27, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xf67599} }, // 6 OSM: 2768662 WD: Q5931449 29.49, 106.4 x 29.83, 106.7
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe3000b} }, // 1 OSM: 2777016 52.2, 10.51 x 52.33, 10.54
    { 1406, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x7b2f3d} }, // M-LINE OSM: 2788830 32.78, -96.8 x 32.81, -96.79
    { 1413, NoLogo, 161, LineMetaDataContent::RapidTransit, Color{0x015ca3} }, // S 7 OSM: 2791180 WD: Q63217583 51.45, 11.91 x 51.49, 12
    { 1418, NoLogo, 161, LineMetaDataContent::RapidTransit, Color{0xd7171f} }, // S 3 OSM: 2793231 WD: Q62749908 51.31, 11.96 x 51.52, 13.11
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x687362} }, // 3 OSM: 2797182 52.5, 103.9 x 52.58, 103.9
    { 1422, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x149943} }, // STY OSM: 2797718 WD: Q7619599 -38.37, 145.1 x -38.14, 145.2
    { 1325, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x030f3f} }, // Metropolitana OSM: 2797904 WD: Q1725884 45.51, 10.21 x 45.58, 10.28
    { 65, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1f75} }, // 10 OSM: 2799185 WD: Q70711877 47.35, 8.507 x 47.45, 8.573
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x92d6e3} }, // 12 OSM: 2799201 WD: Q70711314 47.4, 8.556 x 47.45, 8.608
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x4c677a} }, // 1 OSM: 2801578 52.52, 103.9 x 52.56, 103.9
    { 65, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x83b2d0} }, // 10 OSM: 2801699 52.5, 103.9 x 52.57, 103.9
    { 54, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xa2be73} }, // 11 OSM: 2802261 52.5, 103.9 x 52.56, 103.9
    { 42, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe5e6ea} }, // 7 OSM: 2802264 52.5, 103.8 x 52.53, 103.9
    { 333, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x93ad00} }, // M3 OSM: 2804168 WD: Q2637212 50.41, 4.43 x 50.48, 4.452
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x70492c} }, // 5 OSM: 2807017 47.36, 8.516 x 47.38, 8.572
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xbe8543} }, // 6 OSM: 2807025 47.36, 8.482 x 47.4, 8.572
    { 42, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 7 OSM: 2807030 WD: Q70712535 47.34, 8.53 x 47.41, 8.597
    { 119, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x322e71} }, // 9 OSM: 2807033 WD: Q70710278 47.37, 8.495 x 47.41, 8.592
    { 126, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0093d0} }, // 14 OSM: 2807051 WD: Q70714895 47.37, 8.495 x 47.42, 8.55
    { 54, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00923c} }, // 11 OSM: 2807068 WD: Q70714560 47.35, 8.533 x 47.42, 8.583
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00923c} }, // 3 OSM: 2807070 WD: Q96483170 47.36, 8.485 x 47.38, 8.567
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x322e71} }, // 4 OSM: 2807089 WD: Q96483185 47.35, 8.49 x 47.39, 8.561
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xcb0a25} }, // 2 OSM: 2807095 WD: Q73249054 47.35, 8.444 x 47.4, 8.561
    { 130, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xcb0a25} }, // 15 OSM: 2807117 WD: Q70707977 47.37, 8.533 x 47.4, 8.548
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8bc036} }, // 8 OSM: 2807118 WD: Q96483377 47.36, 8.504 x 47.39, 8.567
    { 1426, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // 800s OSM: 2808958 33.19, -117.9 x 34.1, -117.3
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf39100} }, // 5 OSM: 2810470 52.23, 10.48 x 52.26, 10.54
    { 1431, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff8000} }, // 600s (A500s, A700s) OSM: 2812899 33.19, -118.2 x 34.06, -117.4
    { 1451, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x4782ff} }, // 700s OSM: 2812902 33.76, -118.2 x 34.06, -117.2
    { 26, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xa9c1d1} }, // 16 OSM: 2820891 50.06, 14.3 x 50.11, 14.55
    { 55, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0b0080} }, // 1 OSM: 2826218 WD: Q5017774 29.85, 31.23 x 30.16, 31.34
    { 9, NoLogo, 3973, LineMetaDataContent::Subway, Color{0x0054a6} }, // 4 OSM: 2827680 WD: Q15731046 59.87, 10.71 x 59.97, 10.93
    { 272, NoLogo, 4128, LineMetaDataContent::Subway, Color{0xffe800} }, // Yellow OSM: 2827687 WD: Q54874971 37.6, -122.5 x 38.02, -121.9
    { 1457, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf166a7} }, // 40 OSM: 2836163 59.17, 17.63 x 59.86, 18.07
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x006531} }, // 3 OSM: 2837394 52.24, 10.47 x 52.29, 10.58
    { 595, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xbed639} }, // 82 OSM: 2844184 WD: Q6811974 -37.8, 144.9 x -37.77, 144.9
    { 6, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x800080} }, // 5 OSM: 2845552 37.33, -122 x 37.96, -121.3
    { 42, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x800080} }, // 7 OSM: 2845552 37.33, -122 x 37.96, -121.3
    { 55, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x800080} }, // 1 OSM: 2845552 37.33, -122 x 37.96, -121.3
    { 59, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x800080} }, // 3 OSM: 2845552 37.33, -122 x 37.96, -121.3
    { 279, NoLogo, 4128, LineMetaDataContent::Subway, Color{0xed1c24} }, // Red OSM: 2851513 WD: Q3809179 37.6, -122.5 x 37.94, -122.3
    { 1246, NoLogo, 4128, LineMetaDataContent::Subway, Color{0xfaa61a} }, // Orange OSM: 2851514 WD: Q3866809 37.36, -122.4 x 37.94, -121.9
    { 469, NoLogo, 4128, LineMetaDataContent::Subway, Color{0x4db848} }, // Green OSM: 2851729 WD: Q3720557 37.36, -122.5 x 37.81, -121.9
    { 267, NoLogo, 4128, LineMetaDataContent::Subway, Color{0x00aeef} }, // Blue OSM: 2851730 WD: Q3720569 37.69, -122.5 x 37.81, -121.9
    { 54, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x86c5a2} }, // 11 OSM: 2858845 WD: Q18165625 -37.82, 144.9 x -37.73, 145
    { 42, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x878a83} }, // 7 OSM: 2860817 59.32, 18.06 x 59.33, 18.11
    { 728, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00907a} }, // S31 OSM: 2872363 48.44, 8.215 x 49.18, 8.785
    { 1460, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00907a} }, // S32 OSM: 2872364 48.99, 8.402 x 49.16, 8.775
    { 255, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf49694} }, // S51 OSM: 2872365 48.89, 8.262 x 49.23, 8.703
    { 1073, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf49694} }, // S52 OSM: 2872366 48.98, 8.262 x 49.23, 8.433
    { 103, 4142, 562, LineMetaDataContent::Subway, Color{0x2ec6ff} }, // U4 OSM: 2872790 WD: Q209739 53.53, 9.983 x 53.56, 10.11
    { 54, NoLogo, 3363, LineMetaDataContent::RapidTransit, Color{0xff7f50} }, // 11 OSM: 2875658 WD: Q5245830 -23.56, -46.64 x -23.52, -46.19
    { 15, NoLogo, 3363, LineMetaDataContent::RapidTransit, Color{0x1c146b} }, // 12 OSM: 2877633 WD: Q5245789 -23.55, -46.62 x -23.48, -46.33
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8c6e66} }, // 6 OSM: 2877971 52.5, 103.8 x 52.56, 103.9
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xec7394} }, // 4 OSM: 2877979 52.5, 103.8 x 52.53, 103.9
    { 42, NoLogo, 3363, LineMetaDataContent::RapidTransit, Color{0xa8034f} }, // 7 OSM: 2885794 WD: Q3296728 -23.55, -46.87 x -23.19, -46.62
    { 55, NoLogo, 3973, LineMetaDataContent::Subway, Color{0x00b6f1} }, // 1 OSM: 2890637 WD: Q15731038 59.87, 10.65 x 59.98, 10.82
    { 65, NoLogo, 3363, LineMetaDataContent::RapidTransit, Color{0x00ced1} }, // 10 OSM: 2893113 WD: Q5245819 -23.74, -46.62 x -23.54, -46.39
    { 181, 4157, NoLogo, LineMetaDataContent::Subway, Color{0xffa500} }, // B OSM: 2896644 WD: Q18420098 6.247, -75.61 x 6.259, -75.57
    { 204, NoLogo, 161, LineMetaDataContent::RapidTransit, Color{0xffff00} }, // S 1 OSM: 2920398 WD: Q56600177 51.31, 12.27 x 51.37, 12.41
    { 134, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff7300} }, // 19 OSM: 2921482 59.85, 10.68 x 59.92, 10.8
    { 22, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffb300} }, // 18 OSM: 2921905 59.85, 10.71 x 59.95, 10.8
    { 214, 4196, NoLogo, LineMetaDataContent::Subway, Color{0x003ea1} }, // C OSM: 2931139 WD: Q1157050 -34.63, -58.38 x -34.59, -58.37
    { 181, 4224, NoLogo, LineMetaDataContent::Subway, Color{0xc20924} }, // B OSM: 2933167 WD: Q1157061 -34.6, -58.49 x -34.57, -58.37
    { 39, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x6b297e} }, // E OSM: 2933872 WD: Q1044919 -34.64, -58.46 x -34.59, -58.37
    { 1099, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x217861} }, // D OSM: 2934099 WD: Q1157052 -34.61, -58.46 x -34.56, -58.37
    { 378, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xf4cc21} }, // H OSM: 2934107 WD: Q1132660 -34.64, -58.41 x -34.58, -58.39
    { 330, NoLogo, 3943, LineMetaDataContent::Subway, Color{0x003399} }, // M2 OSM: 2947130 WD: Q1884455 44.36, 26.09 x 44.48, 26.15
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf9b000} }, // 4 OSM: 2951397 WD: Q63350784 52.37, 9.596 x 52.42, 9.819
    { 190, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x281570} }, // T1 OSM: 2962731 WD: Q26273325 41, 28.86 x 41.03, 28.99
    { 54, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x90ee90} }, // 11 OSM: 2971659 49.82, 23.99 x 49.84, 24.04
    { 939, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x6f1b14} }, // 94 OSM: 2982672 51.48, 11.93 x 51.51, 11.97
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf9b000} }, // 6 OSM: 2991603 WD: Q63350805 52.32, 9.69 x 52.42, 9.837
    { 54, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf9b000} }, // 11 OSM: 2991649 WD: Q63350814 52.36, 9.713 x 52.39, 9.775
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf9b000} }, // 5 OSM: 2991701 WD: Q63350794 52.36, 9.659 x 52.41, 9.859
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe4003a} }, // 1 OSM: 2995652 WD: Q63344401 52.24, 9.731 x 52.44, 9.86
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe4003a} }, // 2 OSM: 2998555 WD: Q63345326 52.29, 9.734 x 52.42, 9.818
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe4003a} }, // 8 OSM: 2998722 WD: Q63345432 52.33, 9.734 x 52.39, 9.805
    { 164, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x76b82a} }, // 17 OSM: 2998733 WD: Q63348315 52.34, 9.718 x 52.38, 9.743
    { 65, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x76b82a} }, // 10 OSM: 3004809 WD: Q63348270 52.37, 9.664 x 52.38, 9.744
    { 947, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x051541} }, // 95 OSM: 3006197 51.42, 11.96 x 51.52, 11.99
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xed1943} }, // 12 OSM: 3009639 WD: Q2189640 51.88, 4.471 x 51.92, 4.568
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0069b4} }, // 3 OSM: 3016071 WD: Q63348707 52.33, 9.69 x 52.44, 9.848
    { 42, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0069b4} }, // 7 OSM: 3038575 WD: Q63348805 52.33, 9.69 x 52.41, 9.854
    { 119, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0069b4} }, // 9 OSM: 3038600 WD: Q63349759 52.34, 9.667 x 52.43, 9.802
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 4 OSM: 3061160 50.49, 12.13 x 50.51, 12.18
    { 68, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x9e75ad} }, // L21 OSM: 3061373 59.43, 10.61 x 59.92, 10.84
    { 419, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0075a7} }, // L22 OSM: 3067038 59.43, 10.68 x 59.92, 11.34
    { 186, 1431, 161, LineMetaDataContent::RapidTransit, Color{0x257ca7} }, // S6 OSM: 3096901 WD: Q680235 47.42, 12.06 x 47.52, 12.63
    { 1464, NoLogo, 2364, LineMetaDataContent::RapidTransit, Color{0x236214} }, // UP-N OSM: 3117549 WD: Q7885883 41.88, -87.85 x 42.59, -87.64
    { 1469, NoLogo, 2364, LineMetaDataContent::RapidTransit, Color{0xff821d} }, // MD-N OSM: 3117594 WD: Q16982046 41.88, -88.18 x 42.4, -87.64
    { 1474, NoLogo, 2364, LineMetaDataContent::RapidTransit, Color{0x7c53af} }, // NCS OSM: 3117600 WD: Q7054760 41.88, -88.09 x 42.48, -87.64
    { 1478, NoLogo, 2364, LineMetaDataContent::RapidTransit, Color{0xfae218} }, // UP-NW OSM: 3117607 WD: Q16985937 41.88, -88.62 x 42.42, -87.64
    { 1484, NoLogo, 2364, LineMetaDataContent::RapidTransit, Color{0xfeb8fa} }, // UP-W OSM: 3117615 WD: Q7885886 41.86, -88.47 x 41.9, -87.64
    { 1489, NoLogo, 2364, LineMetaDataContent::RapidTransit, Color{0x77b337} }, // BNSF OSM: 3117619 WD: Q4836140 41.76, -88.31 x 41.88, -87.64
    { 1494, NoLogo, 2364, LineMetaDataContent::RapidTransit, Color{0xee4848} }, // HC OSM: 3117625 WD: Q5738778 41.52, -88.08 x 41.88, -87.64
    { 1497, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa81818} }, // RI OSM: 3117651 41.51, -88.08 x 41.88, -87.63
    { 1500, NoLogo, 2364, LineMetaDataContent::RapidTransit, Color{0x117bac} }, // SWS OSM: 3117664 WD: Q7565331 41.42, -87.99 x 41.88, -87.64
    { 1504, NoLogo, 2364, LineMetaDataContent::RapidTransit, Color{0xf67b7b} }, // ME OSM: 3117670 WD: Q4501968 41.46, -87.72 x 41.89, -87.55
    { 1508, NoLogo, 161, LineMetaDataContent::RapidTransit, Color{0x00ffff} }, // S 2 OSM: 3119892 WD: Q56809294 51.31, 12.23 x 51.87, 12.66
    { 1512, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe37c26} }, // L13 OSM: 3123398 59.74, 10.2 x 60.25, 11.2
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xafe0ee} }, // 8 OSM: 3144745 46.94, 7.374 x 46.95, 7.487
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x088742} }, // 2 OSM: 3152801 51.13, 14.94 x 51.17, 14.99
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff2e17} }, // 1 OSM: 3152809 51.12, 14.97 x 51.17, 14.99
    { 1516, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa11c20} }, // LBN OSM: 3155062 -34.59, -58.87 x -34.42, -58.37
    { 259, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // FM1 OSM: 3158700 41.12, 16.78 x 41.14, 16.87
    { 41, NoLogo, 161, LineMetaDataContent::RapidTransit, Color{0xa5ce43} }, // S7 OSM: 3168072 WD: Q63433461 52.37, 9.739 x 52.62, 10.06
    { 219, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xca305b} }, // A OSM: 3190626 47.34, 0.6578 x 47.42, 0.7119
    { 58, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x33ff33} }, // 13 OSM: 3201250 59.91, 10.59 x 59.93, 10.76
    { 1520, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x88be5f} }, // 1707 OSM: 3207386 WD: Q56525585 47.6, -122.4 x 47.98, -122.2
    { 1525, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x88be5f} }, // 1703 OSM: 3207386 WD: Q56525585 47.6, -122.4 x 47.98, -122.2
    { 1530, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x88be5f} }, // 1701 OSM: 3207386 WD: Q56525585 47.6, -122.4 x 47.98, -122.2
    { 54, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x75ff00} }, // 11 OSM: 3218724 59.91, 10.73 x 59.96, 10.79
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x994dff} }, // 12 OSM: 3221100 59.91, 10.68 x 59.96, 10.79
    { 9, NoLogo, 4252, LineMetaDataContent::Subway, Color{0xf1ce00} }, // 4 OSM: 3228501 WD: Q1597847 45.51, -73.56 x 45.52, -73.52
    { 16, NoLogo, 4252, LineMetaDataContent::Subway, Color{0xd06d07} }, // 2 OSM: 3228502 WD: Q967397 45.47, -73.72 x 45.56, -73.55
    { 6, NoLogo, 4252, LineMetaDataContent::Subway, Color{0x3465b4} }, // 5 OSM: 3228503 WD: Q1726049 45.49, -73.63 x 45.56, -73.6
    { 55, NoLogo, 4252, LineMetaDataContent::Subway, Color{0x5f8c55} }, // 1 OSM: 3228504 WD: Q1925762 45.45, -73.6 x 45.6, -73.53
    { 16, NoLogo, 2223, LineMetaDataContent::Subway, Color{0x15629a} }, // 2 OSM: 3244073 WD: Q1047377 22.99, 113.3 x 23.24, 113.3
    { 97, 4271, 386, LineMetaDataContent::Subway, Color{0xa762a4} }, // U2 OSM: 3245522 WD: Q873397 48.2, 16.36 x 48.23, 16.51
    { 59, NoLogo, 4283, LineMetaDataContent::Subway, Color{0xd9001c} }, // 3 OSM: 3252762 WD: Q3294315 -23.55, -46.67 x -23.53, -46.47
    { 164, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0019} }, // 17 OSM: 3259480 59.91, 10.71 x 59.95, 10.79
    { 94, 4302, 386, LineMetaDataContent::Subway, Color{0xe20613} }, // U1 OSM: 3278144 WD: Q663755 48.14, 16.37 x 48.28, 16.45
    { 330, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x489224} }, // M2 OSM: 3287304 WD: Q2094433 50.4, 4.271 x 50.42, 4.452
    { 219, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xef3f30} }, // A OSM: 3309751 47.44, -0.5972 x 47.51, -0.549
    { 9, 4314, 3931, LineMetaDataContent::Subway, Color{0xbb4d98} }, // 4 OSM: 3326845 WD: Q50743 48.82, 2.318 x 48.9, 2.359
    { 126, 4332, 3931, LineMetaDataContent::Subway, Color{0x67328e} }, // 14 OSM: 3328694 WD: Q50761 48.83, 2.323 x 48.88, 2.387
    { 55, 4351, 3931, LineMetaDataContent::Subway, Color{0xf2c931} }, // 1 OSM: 3328695 WD: Q13224 48.84, 2.23 x 48.89, 2.441
    { 119, 4369, 3931, LineMetaDataContent::Subway, Color{0xcdc83f} }, // 9 OSM: 3328717 WD: Q50753 48.83, 2.231 x 48.87, 2.442
    { 103, 4387, 562, LineMetaDataContent::Subway, Color{0x10b48d} }, // U4 OSM: 3328726 WD: Q20439761 48.13, 11.52 x 48.15, 11.62
    { 65, 4403, 3931, LineMetaDataContent::Subway, Color{0xdfb039} }, // 10 OSM: 3328741 WD: Q50754 48.84, 2.229 x 48.85, 2.365
    { 27, 4422, 3931, LineMetaDataContent::Subway, Color{0x75c695} }, // 6 OSM: 3328765 WD: Q50746 48.83, 2.285 x 48.87, 2.402
    { 42, 4440, 3931, LineMetaDataContent::Subway, Color{0xfa9aba} }, // 7 OSM: 3328805 WD: Q50748 48.79, 2.332 x 48.92, 2.411
    { 2, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xbb0022} }, // 0 OSM: 3348003 WD: Q1510414 51.08, 2.581 x 51.34, 3.285
    { 55, 4458, NoLogo, LineMetaDataContent::Tramway, Color{0xe3000f} }, // 1 OSM: 3367545 WD: Q78199222 48.34, 10.87 x 48.38, 10.94
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x951881} }, // 4 OSM: 3367554 48.37, 10.88 x 48.4, 10.89
    { 1066, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0097ba} }, // S42 OSM: 3368507 49.14, 8.875 x 49.25, 9.229
    { 1507, 4478, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff9e00} }, // RS 2 OSM: 3372285 WD: Q84703704 52.79, 8.597 x 53.57, 8.895
    { 203, 4493, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ee} }, // RS 1 OSM: 3372313 WD: Q84703702 52.92, 8.516 x 53.21, 9.238
    { 1535, NoLogo, 161, LineMetaDataContent::RapidTransit, Color{0xfdd456} }, // S 5X OSM: 3382470 WD: Q63216058 50.7, 11.99 x 51.48, 12.48
    { 1276, 4508, 3643, LineMetaDataContent::Tramway, Color{0xe3ba12} }, // 44 OSM: 3394367 WD: Q1931983 50.82, 4.409 x 50.84, 4.514
    { 1387, 4530, 3643, LineMetaDataContent::Tramway, Color{0xde3b21} }, // 39 OSM: 3394368 WD: Q2719066 50.83, 4.409 x 50.85, 4.503
    { 65, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xe6be80} }, // 10 OSM: 3400216 WD: Q6553053 31.98, 118.6 x 32.07, 118.8
    { 55, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0000ff} }, // 1 OSM: 3400217 WD: Q6127241 31.9, 118.8 x 32.11, 118.9
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // 2 OSM: 3413089 WD: Q5960302 31.97, 118.7 x 32.12, 119
    { 1540, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // Metrotranvía OSM: 3413332 -32.96, -68.85 x -32.84, -68.78
    { 61, 4552, 161, LineMetaDataContent::RapidTransit, Color{0x0095da} }, // S1 OSM: 3413905 WD: Q600891 49.97, 8.244 x 50.11, 8.885
    { 50, 4569, 161, LineMetaDataContent::RapidTransit, Color{0xee1c23} }, // S2 OSM: 3414422 WD: Q1985592 50.01, 8.31 x 50.16, 8.813
    { 47, 4586, 161, LineMetaDataContent::RapidTransit, Color{0xd7df23} }, // S8 OSM: 3415070 WD: Q2005458 49.98, 8.242 x 50.13, 8.931
    { 466, 4603, 161, LineMetaDataContent::RapidTransit, Color{0x91268f} }, // S9 OSM: 3415113 WD: Q508402 49.98, 8.244 x 50.13, 8.931
    { 434, 4620, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfab700} }, // C-5 OSM: 3418151 WD: Q3832677 40.25, -3.883 x 40.41, -3.677
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xbb0022} }, // 12 OSM: 3419132 WD: Q2200976 51.22, 4.42 x 51.23, 4.444
    { 119, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xee8822} }, // 9 OSM: 3419133 WD: Q1891687 51.2, 4.361 x 51.22, 4.464
    { 176, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff88aa} }, // 24 OSM: 3419134 WD: Q2483765 51.2, 4.408 x 51.24, 4.484
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffcc11} }, // 3 OSM: 3419435 WD: Q3238908 51.22, 4.305 x 51.26, 4.464
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x1199dd} }, // 4 OSM: 3419473 WD: Q2344285 51.17, 4.35 x 51.22, 4.484
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x771133} }, // 5 OSM: 3419525 WD: Q2147524 51.22, 4.361 x 51.23, 4.512
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xdd0077} }, // 6 OSM: 3419912 WD: Q2128494 51.18, 4.391 x 51.26, 4.443
    { 42, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0044bb} }, // 7 OSM: 3420306 WD: Q2413292 51.17, 4.4 x 51.23, 4.449
    { 54, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffffff} }, // 11 OSM: 3420543 WD: Q2500256 51.2, 4.402 x 51.22, 4.439
    { 65, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xbbdd00} }, // 10 OSM: 3420544 WD: Q1962342 51.17, 4.362 x 51.23, 4.512
    { 130, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffffff} }, // 15 OSM: 3420997 WD: Q959739 51.17, 4.361 x 51.22, 4.494
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf5d200} }, // 1 OSM: 3430333 49.72, 13.37 x 49.78, 13.4
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf5d200} }, // 2 OSM: 3430559 49.73, 13.32 x 49.75, 13.41
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf5d200} }, // 4 OSM: 3430578 49.73, 13.36 x 49.78, 13.38
    { 1554, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x913108} }, // PM OSM: 3433159 37.78, -122.4 x 37.81, -122.4
    { 377, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x913108} }, // PH OSM: 3433160 37.78, -122.4 x 37.81, -122.4
    { 440, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x92278f} }, // L OSM: 3435879 WD: Q16981005 37.74, -122.5 x 37.79, -122.4
    { 296, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008752} }, // M OSM: 3435882 WD: Q6720518 37.71, -122.5 x 37.79, -122.4
    { 481, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00539b} }, // N OSM: 3435884 WD: Q6956302 37.76, -122.5 x 37.79, -122.4
    { 134, 4635, 3643, LineMetaDataContent::Tramway, Color{0xde3b21} }, // 19 OSM: 3437796 WD: Q2702907 50.86, 4.273 x 50.9, 4.357
    { 1557, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0066cc} }, // LBS OSM: 3443504 -34.78, -58.74 x -34.65, -58.42
    { 106, 4657, 562, LineMetaDataContent::Subway, Color{0xb77510} }, // U5 OSM: 3475206 WD: Q3832790 48.09, 11.5 x 48.14, 11.65
    { 109, 4673, 562, LineMetaDataContent::Subway, Color{0x0071bb} }, // U6 OSM: 3477966 WD: Q751039 48.11, 11.47 x 48.27, 11.67
    { 100, 4689, 562, LineMetaDataContent::Subway, Color{0xf36f33} }, // U3 OSM: 3484056 WD: Q20439760 48.09, 11.48 x 48.19, 11.59
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 1 OSM: 3496727 37.99, -1.174 x 38.04, -1.124
    { 366, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x000000} }, // L2 OSM: 3517295 WD: Q3011583 43.24, -3.042 x 43.33, -2.881
    { 109, 4705, 562, LineMetaDataContent::Subway, Color{0x007ec6} }, // U6 OSM: 3524791 WD: Q19863008 50.11, 8.624 x 50.14, 8.708
    { 94, 4722, 562, LineMetaDataContent::Subway, Color{0x448137} }, // U1 OSM: 3531712 WD: Q20439756 48.1, 11.53 x 48.18, 11.58
    { 97, 4738, 562, LineMetaDataContent::Subway, Color{0xc40f39} }, // U2 OSM: 3531713 WD: Q830301 48.11, 11.54 x 48.21, 11.7
    { 112, 4754, 562, LineMetaDataContent::Subway, Color{0x468037} }, // U7 OSM: 3531714 WD: Q20439774 48.1, 11.53 x 48.18, 11.65
    { 115, 4770, 562, LineMetaDataContent::Subway, Color{0xff6a2f} }, // U8 OSM: 3531715 WD: Q20439777 48.1, 11.56 x 48.18, 11.65
    { 6, NoLogo, 4283, LineMetaDataContent::Subway, Color{0x9200c3} }, // 5 OSM: 3539820 WD: Q3308465 -23.66, -46.77 x -23.59, -46.63
    { 219, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // A OSM: 3555528 49.49, 0.09563 x 49.53, 0.137
    { 181, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // B OSM: 3555531 49.49, 0.09563 x 49.52, 0.1801
    { 524, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffdd00} }, // T2 OSM: 3589646 45.44, 4.384 x 45.45, 4.403
    { 1561, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xafcb07} }, // T3 OSM: 3589647 45.42, 4.378 x 45.47, 4.405
    { 55, NoLogo, 4283, LineMetaDataContent::Subway, Color{0x1a5ba3} }, // 1 OSM: 3596996 WD: Q3362568 -23.65, -46.64 x -23.48, -46.6
    { 330, 4786, 1411, LineMetaDataContent::Subway, Color{0x0000ff} }, // M2 OSM: 3598362 WD: Q2204296 50.37, 30.45 x 50.52, 30.53
    { 9, NoLogo, 4283, LineMetaDataContent::Subway, Color{0xffd700} }, // 4 OSM: 3613482 WD: Q3308457 -23.59, -46.72 x -23.54, -46.63
    { 279, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xcd5c5c} }, // Red OSM: 3616739 WD: Q2472181 53.28, -6.44 x 53.35, -6.229
    { 16, NoLogo, 4283, LineMetaDataContent::Subway, Color{0x008000} }, // 2 OSM: 3619672 WD: Q588499 -23.6, -46.69 x -23.55, -46.58
    { 61, 1431, 161, LineMetaDataContent::RapidTransit, Color{0xd7df23} }, // S1 OSM: 3654415 WD: Q680235 47.25, 11.08 x 47.59, 12.17
    { 50, 1431, 161, LineMetaDataContent::RapidTransit, Color{0x5b9a6d} }, // S2 OSM: 3654417 WD: Q680235 47.24, 10.86 x 47.39, 11.78
    { 44, 1431, 161, LineMetaDataContent::RapidTransit, Color{0xd4b4c4} }, // S5 OSM: 3654634 WD: Q680235 47.25, 11.19 x 47.39, 11.4
    { 196, 1431, 161, LineMetaDataContent::RapidTransit, Color{0xbec2d0} }, // S4 OSM: 3654766 WD: Q680235 47, 11.23 x 47.27, 11.51
    { 1564, 4818, 2957, LineMetaDataContent::Tramway, Color{0x009641} }, // T3b OSM: 3662457 WD: Q3136247 48.85, 2.301 x 48.9, 2.411
    { 190, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x873f98} }, // T1 OSM: 3667340 WD: Q2903 45.73, 4.817 x 45.79, 4.884
    { 1568, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xb80e28} }, // Rhônexpress OSM: 3667553 45.72, 4.862 x 45.78, 5.077
    { 524, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x873f98} }, // T2 OSM: 3667554 WD: Q2906 45.69, 4.827 x 45.75, 4.956
    { 1561, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x873f98} }, // T3 OSM: 3667555 WD: Q2911 45.75, 4.862 x 45.78, 5.035
    { 1581, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x873f98} }, // T4 OSM: 3667556 WD: Q2918 45.69, 4.858 x 45.78, 4.888
    { 181, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x007dc5} }, // B OSM: 3687323 WD: Q2965 45.72, 4.81 x 45.77, 4.864
    { 1099, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x00ac4d} }, // D OSM: 3687324 WD: Q2976 45.7, 4.803 x 45.78, 4.89
    { 214, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xf99d1d} }, // C OSM: 3687325 WD: Q2969 45.77, 4.827 x 45.79, 4.836
    { 219, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xee3898} }, // A OSM: 3687326 WD: Q2944 45.75, 4.825 x 45.77, 4.922
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009cdd} }, // 4 OSM: 3733545 53.4, 14.49 x 53.45, 14.54
    { 1584, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0066cc} }, // LGR7 OSM: 3737973 -34.98, -58.4 x -34.63, -58.37
    { 1589, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0066cc} }, // LGR6 OSM: 3737975 -34.85, -58.52 x -34.63, -58.38
    { 1594, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0066cc} }, // LGR5 OSM: 3738002 -34.9, -58.38 x -34.63, -57.95
    { 100, 4836, 386, LineMetaDataContent::Subway, Color{0xef7c00} }, // U3 OSM: 3752340 WD: Q876472 48.17, 16.31 x 48.21, 16.42
    { 87, 4848, 3643, LineMetaDataContent::Tramway, Color{0xff9ec2} }, // 62 OSM: 3775501 WD: Q2544169 50.86, 4.332 x 50.88, 4.435
    { 1599, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // Line 3 OSM: 3788350 WD: Q341464 29.25, 47.97 x 29.26, 47.97
    { 370, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7daf42} }, // L3 OSM: 3793874 59.91, 10.55 x 60.39, 10.87
    { 416, NoLogo, 1354, LineMetaDataContent::Tramway, Color{0xffd800} }, // 48 OSM: 3820771 WD: Q15982247 47.44, 19.03 x 47.5, 19.06
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 3 OSM: 3822945 55.16, 30.21 x 55.22, 30.25
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 5 OSM: 3822946 55.19, 30.21 x 55.22, 30.27
    { 42, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 7 OSM: 3823035 55.16, 30.12 x 55.2, 30.27
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 1 OSM: 3823370 55.16, 30.12 x 55.22, 30.25
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 2 OSM: 3823520 55.16, 30.12 x 55.19, 30.24
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 4 OSM: 3824101 55.18, 30.14 x 55.2, 30.27
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 6 OSM: 3824263 55.16, 30.12 x 55.2, 30.19
    { 119, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 9 OSM: 3824285 55.16, 30.12 x 55.2, 30.2
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 8 OSM: 3824316 55.16, 30.14 x 55.2, 30.24
    { 1090, 4870, 19, LineMetaDataContent::Tramway, Color{0xfaa61a} }, // 28 OSM: 3858971 WD: Q20439076 48.13, 11.56 x 48.17, 11.58
    { 1337, NoLogo, 4891, LineMetaDataContent::Subway, Color{0xed1c24} }, // a OSM: 3889841 WD: Q24641190 48.09, -1.711 x 48.12, -1.644
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008995} }, // 12 OSM: 3903646 WD: Q18165631 -37.86, 145 x -37.81, 145
    { 1606, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00a1de} }, // West Hempstead OSM: 3917588 40.66, -73.97 x 40.71, -73.64
    { 214, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe4007c} }, // C OSM: 3921484 45.17, 5.69 x 45.19, 5.776
    { 39, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x58318a} }, // E OSM: 3921488 WD: Q3239103 45.17, 5.661 x 45.26, 5.72
    { 181, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009b3a} }, // B OSM: 3921491 45.18, 5.698 x 45.21, 5.787
    { 219, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0076bd} }, // A OSM: 3921492 45.14, 5.671 x 45.2, 5.734
    { 1099, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf39a00} }, // D OSM: 3921494 45.17, 5.754 x 45.19, 5.759
    { 260, NoLogo, 1450, LineMetaDataContent::Subway, Color{0x007d58} }, // M1 OSM: 3931373 WD: Q1880894 55.62, 12.49 x 55.69, 12.59
    { 55, NoLogo, 2223, LineMetaDataContent::Subway, Color{0xf3cf45} }, // 1 OSM: 3936877 WD: Q1047385 23.07, 113.2 x 23.15, 113.3
    { 260, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe5442e} }, // M1 OSM: 3939086 WD: Q2740923 50.4, 4.271 x 50.42, 4.452
    { 1622, 4913, NoLogo, LineMetaDataContent::RapidTransit, Color{0x233e81} }, // TL OSM: 3939642 WD: Q2576140 19.26, -99.15 x 19.34, -99.11
    { 6, NoLogo, 2223, LineMetaDataContent::Subway, Color{0xbc1543} }, // 5 OSM: 3967180 WD: Q862888 23.1, 113.2 x 23.15, 113.5
    { 1625, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xef87b6} }, // HBB OSM: 3988307 47.27, 11.4 x 47.29, 11.4
    { 41, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xda5524} }, // S7 OSM: 4006931 46.93, 7.438 x 46.98, 7.563
    { 1629, 4926, 2957, LineMetaDataContent::Tramway, Color{0xb1a245} }, // T8 OSM: 4007734 WD: Q3239029 48.93, 2.294 x 48.96, 2.358
    { 249, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xed1943} }, // 23 OSM: 4016993 WD: Q2914455 51.88, 4.432 x 51.92, 4.574
    { 1632, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0000ff} }, // Blue Line OSM: 4086917 WD: Q152015 42.36, -71.06 x 42.41, -70.99
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x99b3be} }, // 3 OSM: 4089342 46.94, 7.431 x 46.95, 7.441
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0089cf} }, // 6 OSM: 4089819 46.93, 7.419 x 46.95, 7.563
    { 1643, 4943, 3643, LineMetaDataContent::Tramway, Color{0x991f36} }, // 97 OSM: 4092822 WD: Q1865502 50.8, 4.313 x 50.84, 4.357
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x4a2a15} }, // 4 OSM: 4107687 WD: Q3238942 43.59, 3.872 x 43.62, 3.897
    { 54, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xee1d23} }, // 11 OSM: 4108299 47.47, 7.573 x 47.58, 7.612
    { 1646, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // 100 OSM: 4117854 WD: Q3537097 39.1, -84.52 x 39.12, -84.51
    { 333, 4965, 2128, LineMetaDataContent::Subway, Color{0x0a0e65} }, // M3 OSM: 4121437 WD: Q692916 47.46, 19.05 x 47.56, 19.15
    { 8, NoLogo, 2128, LineMetaDataContent::Subway, Color{0x007b1c} }, // M4 OSM: 4121438 WD: Q832651 47.46, 19.02 x 47.5, 19.08
    { 330, NoLogo, 2128, LineMetaDataContent::Subway, Color{0xd50a0e} }, // M2 OSM: 4121439 WD: Q1071156 47.49, 19.02 x 47.51, 19.14
    { 8, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x84c8eb} }, // M4 OSM: 4139149 WD: Q1841724 50.41, 4.435 x 50.43, 4.503
    { 6, 3174, NoLogo, LineMetaDataContent::Tramway, Color{} }, // 5 OSM: 4152663 WD: Q63890965 50.48, 30.57 x 50.53, 30.63
    { 42, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xee1d23} }, // 7 OSM: 4152763 46.94, 7.38 x 46.95, 7.472
    { 214, 4981, 1962, LineMetaDataContent::Subway, Color{0x008752} }, // C OSM: 4173958 WD: Q2261550 41.86, 12.51 x 41.89, 12.71
    { 330, 5009, 1693, LineMetaDataContent::Subway, Color{0xff0000} }, // M2 OSM: 4232535 WD: Q3832673 52.23, 20.94 x 52.28, 21.06
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff7f00} }, // 1 OSM: 4234654 51.8, 12.24 x 51.84, 12.24
    { 1281, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xffa500} }, // O OSM: 4250359 WD: Q6141590 24.99, 121.4 x 25.1, 121.5
    { 201, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xcedc00} }, // G OSM: 4250382 WD: Q8044250 24.96, 121.5 x 25.05, 121.6
    { 1650, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xa74c00} }, // BR OSM: 4264893 WD: Q707644 25, 121.5 x 25.09, 121.6
    { 29, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x8b231d} }, // SFM6 OSM: 4277114 WD: Q15077697 44.88, 7.655 x 45.12, 8.209
    { 1653, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // C11 OSM: 4287063 50.71, 12.77 x 50.84, 12.93
    { 44, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf49694} }, // S5 OSM: 4292646 48.89, 8.243 x 49.06, 8.705
    { 16, NoLogo, 5021, LineMetaDataContent::Subway, Color{0x028f34} }, // 2 OSM: 4292976 WD: Q2333639 -22.95, -43.37 x -22.81, -43.17
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xbb0022} }, // 1 OSM: 4307991 51.02, 3.692 x 51.11, 3.75
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x229922} }, // 4 OSM: 4307994 51.02, 3.709 x 51.07, 3.751
    { 1657, NoLogo, 161, LineMetaDataContent::RapidTransit, Color{0x00a6eb} }, // S19 OSM: 4434302 WD: Q30597732 50.76, 6.482 x 50.95, 7.66
    { 255, NoLogo, 161, LineMetaDataContent::RapidTransit, Color{0xf78a18} }, // S51 OSM: 4435864 WD: Q63433457 52.1, 9.374 x 52.4, 9.773
    { 1661, NoLogo, 161, LineMetaDataContent::RapidTransit, Color{0x118349} }, // S21 OSM: 4435868 WD: Q63433451 52.28, 9.466 x 52.38, 9.773
    { 1665, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xcc0000} }, // Red Line OSM: 4439533 WD: Q7304502 33.64, -84.45 x 33.95, -84.34
    { 1674, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xf67705} }, // Gold Line OSM: 4439534 WD: Q5578774 33.64, -84.45 x 33.9, -84.28
    { 1689, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x009544} }, // Green Line OSM: 4439535 WD: Q5602819 33.75, -84.43 x 33.77, -84.34
    { 1632, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0274ba} }, // Blue Line OSM: 4439536 WD: Q4929368 33.75, -84.47 x 33.78, -84.23
    { 65, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x114283} }, // 10 OSM: 4443860 54.27, 48.29 x 54.32, 48.39
    { 196, 5039, 161, LineMetaDataContent::RapidTransit, Color{0x903f98} }, // S4 OSM: 4452991 WD: Q459508 47.62, 12.87 x 47.84, 13
    { 47, NoLogo, 161, LineMetaDataContent::RapidTransit, Color{0x8ec7e8} }, // S8 OSM: 4470844 WD: Q63433462 52.32, 9.687 x 52.46, 9.792
    { 1700, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7b388c} }, // Providence/Stoughton Line OSM: 4473913 WD: Q7252371 41.58, -71.49 x 42.35, -71.05
    { 1726, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7b388c} }, // Franklin Line OSM: 4476404 WD: Q5491659 42.08, -71.44 x 42.35, -71.05
    { 126, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x59249a} }, // 14 OSM: 4489019 46.18, 6.077 x 46.24, 6.144
    { 22, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xa84b97} }, // 18 OSM: 4489020 46.17, 6.054 x 46.23, 6.144
    { 130, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x774c2d} }, // 15 OSM: 4489138 46.18, 6.12 x 46.22, 6.149
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 4 OSM: 4494871 WD: Q2105648 52.34, 4.889 x 52.38, 4.905
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xab10d2} }, // 12 OSM: 4495366 WD: Q14500288 52.35, 4.879 x 52.38, 4.919
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffbf00} }, // 1 OSM: 4497227 WD: Q2663350 52.35, 4.775 x 52.36, 4.934
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffbf00} }, // 2 OSM: 4497722 WD: Q2033321 52.34, 4.804 x 52.38, 4.902
    { 1740, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x87ceeb} }, // TRAB OSM: 4497962 WD: Q2829306 33.37, -7.672 x 33.61, -7.554
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xab10d2} }, // 3 OSM: 4498754 WD: Q2051638 52.35, 4.87 x 52.39, 4.952
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffbf00} }, // 5 OSM: 4501532 WD: Q2343376 52.3, 4.867 x 52.38, 4.884
    { 1745, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x006983} }, // Montauk OSM: 4501572 WD: Q4044495 40.7, -73.99 x 41.05, -71.95
    { 42, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff7f00} }, // 7 OSM: 4502267 WD: Q4405692 52.36, 4.818 x 52.38, 4.94
    { 134, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 19 OSM: 4507967 WD: Q2402279 52.34, 4.838 x 52.39, 4.971
    { 1753, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00985f} }, // Babylon OSM: 4509487 WD: Q4838506 40.66, -73.99 x 40.75, -73.32
    { 58, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xab10d2} }, // 13 OSM: 4512711 WD: Q2157983 52.37, 4.803 x 52.38, 4.898
    { 126, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00ff00} }, // 14 OSM: 4513498 WD: Q2108285 52.36, 4.892 x 52.38, 4.952
    { 176, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf49ac1} }, // 24 OSM: 4513900 WD: Q2651682 52.34, 4.857 x 52.36, 4.9
    { 164, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x007fff} }, // 17 OSM: 4514442 WD: Q2400889 52.36, 4.787 x 52.38, 4.898
    { 1015, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xd59758} }, // 26 OSM: 4514564 WD: Q2503173 52.35, 4.898 x 52.38, 5.005
    { 168, NoLogo, 5059, LineMetaDataContent::Subway, Color{0x29ab4d} }, // 50 OSM: 4515358 WD: Q2466111 52.29, 4.834 x 52.4, 4.99
    { 256, NoLogo, 5059, LineMetaDataContent::Subway, Color{0xf69931} }, // 51 OSM: 4515359 WD: Q606629 52.33, 4.834 x 52.4, 4.924
    { 1761, NoLogo, 5059, LineMetaDataContent::Subway, Color{0xfcfb05} }, // 54 OSM: 4515360 WD: Q2183200 52.29, 4.9 x 52.38, 4.99
    { 1764, NoLogo, 5059, LineMetaDataContent::Subway, Color{0xff0000} }, // 53 OSM: 4515361 WD: Q2163442 52.31, 4.9 x 52.38, 4.985
    { 1030, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x1c9fda} }, // S10 OSM: 4543849 47.45, 17.64 x 47.75, 19.03
    { 1149, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfecd07} }, // Z30 OSM: 4546118 47.17, 18.42 x 47.5, 19.04
    { 1767, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffa500} }, // NS OSM: 4566683 45.49, -122.7 x 45.53, -122.7
    { 1611, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xce8e00} }, // Hempstead OSM: 4600806 40.68, -73.97 x 40.73, -73.62
    { 1770, 5084, 5111, LineMetaDataContent::Subway, Color{0xff0000} }, // m2 OSM: 4621397 WD: Q3239144 46.51, 6.626 x 46.54, 6.662
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x94c11a} }, // 2 OSM: 4622863 52.23, 10.52 x 52.29, 10.54
    { 42, 5136, 2022, LineMetaDataContent::Subway, Color{0xffc66e} }, // 7 OSM: 4624900 WD: Q6553149 39.85, 116.3 x 39.89, 116.7
    { 126, 5156, 2022, LineMetaDataContent::Subway, Color{0xd4a7a1} }, // 14 OSM: 4624915 WD: Q6553070 39.86, 116.2 x 40.03, 116.5
    { 27, 5177, 2022, LineMetaDataContent::Subway, Color{0xbb8900} }, // 6 OSM: 4625142 WD: Q6553138 39.9, 116.2 x 39.93, 116.7
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xec008c} }, // 1 OSM: 4628650 47.15, 27.56 x 47.19, 27.63
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00a650} }, // 3 OSM: 4629075 47.15, 27.57 x 47.17, 27.66
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf9c0c1} }, // 6 OSM: 4631231 47.16, 27.54 x 47.17, 27.59
    { 42, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x2e3092} }, // 7 OSM: 4631274 47.14, 27.54 x 47.17, 27.64
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xd2e288} }, // 8 OSM: 4631290 47.15, 27.56 x 47.19, 27.61
    { 94, 5197, 562, LineMetaDataContent::Subway, Color{0xb8282e} }, // U1 OSM: 4656730 WD: Q198432 50.1, 8.634 x 50.17, 8.687
    { 100, 5214, 562, LineMetaDataContent::Subway, Color{0x4a5eaa} }, // U3 OSM: 4656731 WD: Q19862991 50.1, 8.537 x 50.22, 8.687
    { 103, 5231, 562, LineMetaDataContent::Subway, Color{0xf172ac} }, // U4 OSM: 4656732 WD: Q19862998 50.11, 8.652 x 50.14, 8.755
    { 106, 5248, 562, LineMetaDataContent::Subway, Color{0x007942} }, // U5 OSM: 4656733 WD: Q3040872 50.11, 8.662 x 50.16, 8.692
    { 112, 5265, 562, LineMetaDataContent::Subway, Color{0xe4a023} }, // U7 OSM: 4656734 WD: Q3040904 50.11, 8.608 x 50.14, 8.755
    { 115, 5282, 562, LineMetaDataContent::Subway, Color{0xc77db5} }, // U8 OSM: 4656735 WD: Q3063407 50.1, 8.621 x 50.18, 8.687
    { 118, 5299, 562, LineMetaDataContent::Subway, Color{0xeed700} }, // U9 OSM: 4656736 WD: Q19862984 50.14, 8.621 x 50.2, 8.674
    { 1581, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008176} }, // T4 OSM: 4665787 41.39, 2.187 x 41.42, 2.231
    { 1773, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008176} }, // T6 OSM: 4665788 41.4, 2.187 x 41.42, 2.231
    { 1318, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008176} }, // T5 OSM: 4665789 41.4, 2.187 x 41.44, 2.233
    { 1561, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008176} }, // T3 OSM: 4667001 41.37, 2.053 x 41.39, 2.143
    { 190, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008176} }, // T1 OSM: 4667002 41.36, 2.058 x 41.39, 2.143
    { 524, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008176} }, // T2 OSM: 4667003 41.36, 2.058 x 41.39, 2.143
    { 366, NoLogo, 5316, LineMetaDataContent::Subway, Color{0x992f9c} }, // L2 OSM: 4671269 WD: Q1348921 41.38, 2.163 x 41.45, 2.244
    { 358, NoLogo, 5316, LineMetaDataContent::Subway, Color{0xfab70a} }, // L4 OSM: 4671321 WD: Q961384 41.38, 2.163 x 41.45, 2.217
    { 1205, NoLogo, 5316, LineMetaDataContent::Subway, Color{0x317bc8} }, // L5 OSM: 4673514 WD: Q1348939 41.36, 2.071 x 41.43, 2.187
    { 1776, NoLogo, 5316, LineMetaDataContent::Subway, Color{0x00adef} }, // L10 OSM: 4673515 WD: Q1785338 41.42, 2.187 x 41.44, 2.234
    { 370, NoLogo, 5316, LineMetaDataContent::Subway, Color{0x39af57} }, // L3 OSM: 4673516 WD: Q385168 41.37, 2.111 x 41.45, 2.185
    { 1217, NoLogo, 5316, LineMetaDataContent::Subway, Color{0xd5578f} }, // L8 OSM: 4673517 WD: Q763319 41.35, 2.035 x 41.37, 2.149
    { 1213, NoLogo, 5316, LineMetaDataContent::Subway, Color{0xac5414} }, // L7 OSM: 4673518 WD: Q678390 41.39, 2.137 x 41.41, 2.17
    { 362, NoLogo, 5316, LineMetaDataContent::Subway, Color{0xe33638} }, // L1 OSM: 4673519 WD: Q1348946 41.34, 2.099 x 41.45, 2.218
    { 1780, NoLogo, 5316, LineMetaDataContent::Subway, Color{0x9ed74c} }, // L11 OSM: 4673520 WD: Q1419762 41.45, 2.173 x 41.46, 2.186
    { 1209, NoLogo, 5316, LineMetaDataContent::Subway, Color{0x7280c0} }, // L6 OSM: 4673521 WD: Q1577019 41.39, 2.125 x 41.4, 2.17
    { 1784, 5341, 5316, LineMetaDataContent::Subway, Color{0xf6842a} }, // L9 Nord OSM: 4673522 WD: Q1577033 41.42, 2.187 x 41.46, 2.219
    { 1661, 5358, 161, LineMetaDataContent::RapidTransit, Color{0xa70f47} }, // S21 OSM: 4708731 WD: Q19368759 53.49, 9.893 x 53.6, 10.32
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe30e68} }, // 1 OSM: 4748602 52.38, 16.83 x 52.4, 17
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x70c9e8} }, // 2 OSM: 4750038 52.37, 16.88 x 52.42, 16.94
    { 1792, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x800080} }, // Tren Urbano OSM: 4751620 WD: Q1577126 18.39, -66.15 x 18.44, -66.05
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x7dc833} }, // 5 OSM: 4763766 52.38, 16.88 x 52.41, 16.98
    { 1804, 5374, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe67310} }, // A2 OSM: 4785912 WD: Q19582807 53.71, 9.966 x 53.83, 9.993
    { 1807, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x004d9f} }, // Tide OSM: 4788761 WD: Q646388 36.84, -76.3 x 36.86, -76.19
    { 1526, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xee3a43} }, // 703 OSM: 4789075 WD: Q7304509 40.54, -112 x 40.77, -111.8
    { 1812, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe3e049} }, // TECO OSM: 4789201 27.94, -82.46 x 27.96, -82.44
    { 1817, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xbdbadc} }, // 401-689 OSM: 4799475 WD: Q7163197 38.9, -77.01 x 39.57, -76.04
    { 1825, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xbdbadc} }, // 400-698 OSM: 4799476 WD: Q7163197 38.9, -77.01 x 39.57, -76.04
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 3 OSM: 5143295 49.2, 16.52 x 49.23, 16.64
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 4 OSM: 5151976 49.19, 16.58 x 49.23, 16.65
    { 190, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00a5c1} }, // T1 OSM: 5157502 47.22, 5.949 x 47.26, 6.061
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe4002c} }, // 1 OSM: 5185991 51, 13.67 x 51.06, 13.82
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xeb5b2d} }, // 2 OSM: 5186008 51.01, 13.65 x 51.06, 13.85
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc9061a} }, // 4 OSM: 5186035 51.02, 13.56 x 51.16, 13.84
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffdd00} }, // 6 OSM: 5186067 51, 13.65 x 51.06, 13.84
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x229133} }, // 8 OSM: 5186073 51.03, 13.72 x 51.12, 13.77
    { 119, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x93c355} }, // 9 OSM: 5186435 51, 13.69 x 51.08, 13.8
    { 65, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf9b000} }, // 10 OSM: 5186677 51.04, 13.71 x 51.07, 13.81
    { 54, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc2ddaf} }, // 11 OSM: 5186681 51.02, 13.73 x 51.07, 13.86
    { 58, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfdc300} }, // 13 OSM: 5186751 51, 13.69 x 51.08, 13.8
    { 1066, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x1c9fda} }, // S42 OSM: 5189590 46.96, 18.76 x 47.5, 19.04
    { 1833, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xafca36} }, // G10 OSM: 5189591 47.45, 17.64 x 47.75, 19.12
    { 1837, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x1c9fda} }, // S72 OSM: 5189592 47.51, 18.71 x 47.78, 19.1
    { 1841, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x1c9fda} }, // S30 OSM: 5189595 46.75, 17.56 x 47.5, 19.04
    { 1845, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xafca36} }, // G43 OSM: 5189602 47.17, 18.42 x 47.48, 19.35
    { 1456, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x1c9fda} }, // S40 OSM: 5189605 46.37, 18.15 x 47.5, 19.04
    { 1849, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x1c9fda} }, // S36 OSM: 5189606 47.25, 18.69 x 47.48, 19.35
    { 1853, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x1c9fda} }, // S355 OSM: 5189607 46.44, 16.99 x 47.5, 19.04
    { 1858, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x1c9fda} }, // S34 OSM: 5189609 46.69, 17.24 x 47.5, 19.04
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xd52330} }, // 1 OSM: 5209167 50.93, 6.816 x 50.96, 7.162
    { 42, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe6855c} }, // 7 OSM: 5231292 50.87, 6.797 x 50.94, 7.06
    { 41, NoLogo, 1431, LineMetaDataContent::RapidTransit, Color{0xec1093} }, // S7 OSM: 5248498 WD: Q17101554 48.1, 16.38 x 48.72, 17.01
    { 149, 1431, 161, LineMetaDataContent::RapidTransit, Color{0x9bbe46} }, // S60 OSM: 5248503 WD: Q695595 47.81, 16.23 x 48.19, 16.78
    { 167, 1431, 161, LineMetaDataContent::RapidTransit, Color{0x05aded} }, // S50 OSM: 5248504 WD: Q695595 48.17, 15.89 x 48.21, 16.34
    { 1862, 1431, 161, LineMetaDataContent::RapidTransit, Color{0xe7c21e} }, // S80 OSM: 5248538 WD: Q695595 48.17, 16.26 x 48.23, 16.51
    { 239, NoLogo, 1431, LineMetaDataContent::RapidTransit, Color{0xbdd542} }, // S45 OSM: 5248540 WD: Q17101545 48.19, 16.26 x 48.26, 16.39
    { 1456, 1431, 161, LineMetaDataContent::RapidTransit, Color{0xf05923} }, // S40 OSM: 5248548 WD: Q695595 48.21, 15.62 x 48.35, 16.37
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // 1 OSM: 5252357 WD: Q1548435 39.22, 9.125 x 39.27, 9.143
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xeb4690} }, // 1 OSM: 5293755 33.98, -6.865 x 34.05, -6.794
    { 1561, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x96be0d} }, // T3 OSM: 5296539 43.29, 5.367 x 43.32, 5.384
    { 121, 414, NoLogo, LineMetaDataContent::Subway, Color{} }, // U11 OSM: 5311905 WD: Q203252 51.42, 6.992 x 51.54, 7.026
    { 1866, 414, NoLogo, LineMetaDataContent::Subway, Color{} }, // U17 OSM: 5312041 WD: Q203252 51.43, 6.973 x 51.5, 7.013
    { 1871, 5389, NoLogo, LineMetaDataContent::Subway, Color{0x02ac39} }, // TR OSM: 5326658 WD: Q843148 35.7, 140 x 35.73, 140.1
    { 119, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 9 OSM: 5329880 49.19, 16.61 x 49.23, 16.62
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x221815} }, // 6 OSM: 5335066 WD: Q957721 33.84, 132.8 x 33.85, 132.8
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x036eb8} }, // 5 OSM: 5335067 33.84, 132.8 x 33.85, 132.8
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe60012} }, // 3 OSM: 5335068 33.84, 132.8 x 33.85, 132.8
    { 1874, 5418, NoLogo, LineMetaDataContent::RapidTransit, Color{0x8b039b} }, // C-3 OSM: 5382815 WD: Q8879464 40.03, -4.133 x 40.63, -3.608
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x662584} }, // 2 OSM: 5391128 33.99, -6.872 x 34.04, -6.799
    { 61, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffa500} }, // S1 OSM: 5405974 WD: Q2316170 41.39, 2.007 x 41.58, 2.17
    { 50, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7e971e} }, // S2 OSM: 5405975 WD: Q2316170 41.39, 2.068 x 41.57, 2.17
    { 186, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x6295ce} }, // S6 OSM: 5405976 WD: Q2316170 41.39, 2.068 x 41.5, 2.17
    { 44, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffa500} }, // S5 OSM: 5405977 WD: Q2316170 41.39, 2.068 x 41.47, 2.17
    { 244, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf9b000} }, // 20 OSM: 5421483 51.04, 13.71 x 51.07, 13.74
    { 1878, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffd800} }, // 24G OSM: 5443927 47.48, 19.07 x 47.5, 19.11
    { 55, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x000080} }, // 1 OSM: 5465576 WD: Q10318641 -30.03, -51.23 x -29.69, -51.13
    { 59, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0000ff} }, // 3 OSM: 5468841 17.39, 78.38 x 17.45, 78.56
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 1 OSM: 5490398 41.66, 123.4 x 41.74, 123.5
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 3 OSM: 5490400 41.65, 123.4 x 41.72, 123.5
    { 1246, NoLogo, 1202, LineMetaDataContent::RapidTransit, Color{0xffa500} }, // Orange OSM: 5543450 WD: Q6714620 45.43, -122.7 x 45.51, -122.6
    { 181, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0088ab} }, // B OSM: 5575252 45.5, -122.7 x 45.54, -122.7
    { 1885, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe5554f} }, // V OSM: 5576487 WD: Q11152362 25.15, 121.4 x 25.2, 121.5
    { 214, NoLogo, 5436, LineMetaDataContent::RapidTransit, Color{0x80b352} }, // C OSM: 5593997 WD: Q4121246 22.59, 120.3 x 22.62, 120.3
    { 1887, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00bd19} }, // Π3 OSM: 5596928 WD: Q47477355 37.99, 23.57 x 38.46, 23.87
    { 53, 5514, 161, LineMetaDataContent::RapidTransit, Color{0x44a325} }, // S11 OSM: 5607596 WD: Q19368865 53.55, 9.814 x 53.65, 10.09
    { 50, 5530, 161, LineMetaDataContent::RapidTransit, Color{0xa70f47} }, // S2 OSM: 5607597 WD: Q19390036 53.49, 9.934 x 53.56, 10.21
    { 153, 5545, 161, LineMetaDataContent::RapidTransit, Color{0x5d1d81} }, // S3 OSM: 5607598 WD: Q19368685 53.46, 9.477 x 53.66, 10.03
    { 1891, 5560, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe79500} }, // A1 OSM: 5610369 WD: Q19368804 53.55, 9.889 x 54.08, 10.02
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xe70095} }, // 2 OSM: 5616937 WD: Q3832658 39.43, -0.5963 x 39.62, -0.3815
    { 119, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xb58150} }, // 9 OSM: 5622181 WD: Q18613779 39.47, -0.5603 x 39.54, -0.3521
    { 42, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xf28c00} }, // 7 OSM: 5626070 WD: Q11690011 39.43, -0.4726 x 39.47, -0.3383
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xd75128} }, // 3 OSM: 5646916 50.69, 12.46 x 50.73, 12.53
    { 150, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffa500} }, // 60 OSM: 5664426 WD: Q1632888 52.01, 5.076 x 52.09, 5.108
    { 80, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffa500} }, // 61 OSM: 5664427 WD: Q1632888 52.01, 5.028 x 52.09, 5.108
    { 54, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf05b72} }, // 11 OSM: 5668462 47.15, 27.54 x 47.17, 27.63
    { 58, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00adef} }, // 13 OSM: 5668463 47.15, 27.56 x 47.19, 27.63
    { 1894, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // E-W OSM: 5697658 WD: Q53778901 9.01, 38.72 x 9.022, 38.87
    { 1898, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // S-N OSM: 5697659 WD: Q53779001 8.936, 38.73 x 9.039, 38.77
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x66cc00} }, // 2 OSM: 5711071 WD: Q4292517 36.28, 59.55 x 36.33, 59.68
    { 524, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0098d4} }, // T2 OSM: 5720061 43.59, 1.374 x 43.63, 1.446
    { 153, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x36a390} }, // S3 OSM: 5721287 WD: Q2381339 41.35, 2.005 x 41.4, 2.149
    { 196, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa25e23} }, // S4 OSM: 5721688 WD: Q2381339 41.35, 1.888 x 41.54, 2.149
    { 1591, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xb8b6b7} }, // R6 OSM: 5724702 41.35, 1.63 x 41.58, 2.149
    { 1902, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x707072} }, // R60 OSM: 5724705 41.35, 1.63 x 41.58, 2.149
    { 1596, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x38b0b1} }, // R5 OSM: 5724850 WD: Q2381339 41.35, 1.828 x 41.73, 2.149
    { 1906, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x3592a3} }, // R50 OSM: 5724851 WD: Q2381339 41.35, 1.828 x 41.73, 2.149
    { 164, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x6dcff6} }, // 17 OSM: 5740169 50.86, 6.957 x 50.93, 7.004
    { 26, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x21bfc1} }, // 16 OSM: 5742444 50.68, 6.943 x 50.99, 7.159
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe06e9f} }, // 4 OSM: 5742445 50.93, 6.873 x 51.02, 7.044
    { 164, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x286290} }, // 17 OSM: 5742856 52.37, 16.88 x 52.42, 16.98
    { 58, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc88922} }, // 13 OSM: 5744834 52.37, 16.83 x 52.41, 16.95
    { 130, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8d98a2} }, // 15 OSM: 5745673 52.39, 16.85 x 52.46, 16.92
    { 1910, 414, NoLogo, LineMetaDataContent::Subway, Color{0xda251d} }, // U71 OSM: 5747258 WD: Q661002 51.16, 6.775 x 51.26, 6.886
    { 1914, 414, NoLogo, LineMetaDataContent::Subway, Color{0xda251d} }, // U83 OSM: 5748738 WD: Q661002 51.16, 6.775 x 51.25, 6.886
    { 65, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf2b023} }, // 10 OSM: 5752352 52.37, 16.9 x 52.41, 16.96
    { 1918, 414, NoLogo, LineMetaDataContent::Subway, Color{0xda251d} }, // U73 OSM: 5756097 WD: Q661002 51.19, 6.775 x 51.24, 6.867
    { 1922, 414, NoLogo, LineMetaDataContent::Subway, Color{0xda251d} }, // U72 OSM: 5756147 WD: Q661002 51.19, 6.762 x 51.3, 6.847
    { 1926, 5575, NoLogo, LineMetaDataContent::RapidTransit, Color{0x006434} }, // R2Sud OSM: 5758580 WD: Q1880046 41.19, 1.523 x 41.4, 2.194
    { 1932, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff6600} }, // HVL OSM: 5793083 -41.28, 174.8 x -41.13, 175.1
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xa4107f} }, // 4 OSM: 5804724 WD: Q3476269 51.91, 4.432 x 51.96, 4.504
    { 362, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x800080} }, // L1 OSM: 5812905 WD: Q95982832 38.09, 13.37 x 38.11, 13.41
    { 366, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffa500} }, // L2 OSM: 5812931 WD: Q95983858 38.13, 13.29 x 38.13, 13.34
    { 358, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // L4 OSM: 5813038 WD: Q95983909 38.1, 13.33 x 38.13, 13.34
    { 370, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // L3 OSM: 5813039 WD: Q95983869 38.13, 13.3 x 38.14, 13.34
    { 1936, NoLogo, 1354, LineMetaDataContent::Tramway, Color{0xffd800} }, // 47B OSM: 5830635 WD: Q22696462 47.44, 18.98 x 47.5, 19.06
    { 1940, 5575, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00a85a} }, // R2 OSM: 5838299 WD: Q1880046 41.28, 1.978 x 41.6, 2.292
    { 1943, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff131a} }, // R3 OSM: 5844031 WD: Q2113761 41.36, 1.896 x 42.46, 2.297
    { 326, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe1a9b2} }, // U49 OSM: 5847183 51.48, 7.443 x 51.52, 7.476
    { 1946, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff8c00} }, // R4 OSM: 5849061 WD: Q2226508 41.19, 1.525 x 41.72, 2.189
    { 1949, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x9b1987} }, // R8 OSM: 5866129 WD: Q3817638 41.45, 1.926 x 41.6, 2.292
    { 189, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00bdac} }, // RT1 OSM: 5866193 WD: Q5985874 41.11, 1.098 x 41.16, 1.254
    { 523, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe579cb} }, // RT2 OSM: 5867875 WD: Q9025898 41, 0.9109 x 41.27, 1.6
    { 1952, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0073ce} }, // RG1 OSM: 5867925 WD: Q5985872 41.36, 2.099 x 42.43, 3.161
    { 1956, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0060a9} }, // Expo Line OSM: 5881298 WD: Q5421492 49.18, -123.1 x 49.29, -122.8
    { 1966, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xffd520} }, // Millennium Line OSM: 5881419 WD: Q1534900 49.25, -123.1 x 49.29, -122.8
    { 1982, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x009ac8} }, // Canada Line OSM: 5881439 WD: Q1031997 49.17, -123.2 x 49.29, -123.1
    { 1994, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfbc424} }, // U42 OSM: 5890483 51.47, 7.433 x 51.56, 7.547
    { 1998, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xec2425} }, // U45 OSM: 5892934 51.49, 7.46 x 51.52, 7.475
    { 2002, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffdd00} }, // R12 OSM: 5927786 WD: Q9026146 41.36, 0.6331 x 41.75, 2.189
    { 39, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x1e9999} }, // E OSM: 5953002 WD: Q5324790 37.78, -122.4 x 37.81, -122.4
    { 310, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf4858d} }, // 614P OSM: 5955260 WD: Q15903043 22.37, 114 x 22.41, 114
    { 2006, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x006684} }, // 615P OSM: 5955261 WD: Q15903207 22.37, 114 x 22.41, 114
    { 219, NoLogo, 5592, LineMetaDataContent::Subway, Color{0x00aa50} }, // A OSM: 5955845 WD: Q2310450 51.9, 4.314 x 51.96, 4.566
    { 181, NoLogo, 5592, LineMetaDataContent::Subway, Color{0xffd301} }, // B OSM: 5955846 WD: Q2960661 51.9, 4.129 x 51.98, 4.587
    { 214, NoLogo, 5592, LineMetaDataContent::Subway, Color{0xef1f1f} }, // C OSM: 5955847 WD: Q2058778 51.83, 4.319 x 51.94, 4.601
    { 1099, NoLogo, 5592, LineMetaDataContent::Subway, Color{0x1bc5e9} }, // D OSM: 5955848 WD: Q2034685 51.83, 4.319 x 51.92, 4.497
    { 39, NoLogo, 5617, LineMetaDataContent::Subway, Color{0x1a389a} }, // E OSM: 5955849 WD: Q2687418 51.87, 4.325 x 52.08, 4.497
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x90130c} }, // 2 OSM: 5955850 WD: Q1982139 51.88, 4.464 x 51.9, 4.554
    { 244, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfbb316} }, // 20 OSM: 5966563 WD: Q3118970 51.88, 4.471 x 51.92, 4.539
    { 42, NoLogo, 2223, LineMetaDataContent::Subway, Color{0x77bc1f} }, // 7 OSM: 5971692 WD: Q6553152 22.99, 113.3 x 23.05, 113.4
    { 2011, 5341, 5316, LineMetaDataContent::Subway, Color{0xf6842a} }, // L9 Sud OSM: 5972747 WD: Q1577033 41.29, 2.055 x 41.38, 2.136
    { 2018, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // NL1 OSM: 5976635 49, 8.405 x 49.01, 8.479
    { 2022, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x006699} }, // NL2 OSM: 5976636 48.99, 8.384 x 49.01, 8.411
    { 2026, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x002369} }, // R11 OSM: 6021945 WD: Q11050690 41.38, 2.14 x 42.43, 3.161
    { 2030, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xed3896} }, // R13 OSM: 6025765 WD: Q6018166 41.18, 0.6331 x 41.62, 2.194
    { 2034, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x4e53ab} }, // R14 OSM: 6028425 WD: Q2880157 41.11, 0.6331 x 41.62, 2.194
    { 2038, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x9a836c} }, // R15 OSM: 6028724 WD: Q5845244 41.09, 0.4797 x 41.4, 2.194
    { 1859, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x94288e} }, // 34 OSM: 6028756 WD: Q9025916 41.09, 0.2988 x 41.4, 2.194
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // 5 OSM: 6059624 41.74, 123.5 x 41.81, 123.7
    { 164, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x4d3d00} }, // 17 OSM: 6061801 49.01, 8.359 x 49.05, 8.452
    { 26, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffaaaa} }, // 16 OSM: 6061802 48.99, 8.383 x 49.05, 8.452
    { 22, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00805a} }, // 18 OSM: 6061803 49, 8.431 x 49.05, 8.479
    { 39, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // E OSM: 6062533 48.95, 8.283 x 49.11, 8.505
    { 1099, 5631, 5658, LineMetaDataContent::RapidTransit, Color{0xffa700} }, // D OSM: 6063097 WD: Q10318679 41.11, -8.611 x 41.18, -8.599
    { 39, 5679, 5658, LineMetaDataContent::RapidTransit, Color{0x645a95} }, // E OSM: 6063237 WD: Q10318682 41.15, -8.67 x 41.24, -8.582
    { 233, 5706, 5658, LineMetaDataContent::RapidTransit, Color{0xf96915} }, // F OSM: 6064751 WD: Q10318684 41.15, -8.655 x 41.19, -8.542
    { 219, 5733, 5658, LineMetaDataContent::RapidTransit, Color{0x0083d7} }, // A OSM: 6064925 WD: Q18473912 41.15, -8.694 x 41.19, -8.582
    { 214, 5760, 5658, LineMetaDataContent::RapidTransit, Color{0x6eab24} }, // C OSM: 6065645 WD: Q10318673 41.15, -8.656 x 41.27, -8.586
    { 35, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffff00} }, // S OSM: 6071918 WD: Q7395342 37.74, -122.5 x 37.79, -122.4
    { 55, 5787, NoLogo, LineMetaDataContent::Subway, Color{0x000080} }, // 1 OSM: 6087653 WD: Q1537708 -19.95, -44.03 x -19.82, -43.91
    { 2042, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x006400} }, // SMART OSM: 6090093 WD: Q7562166 37.95, -122.8 x 38.51, -122.5
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xea5297} }, // 4 OSM: 6092716 47.99, 7.829 x 48.04, 7.863
    { 2048, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // Sul OSM: 6113028 WD: Q10318728 -3.895, -38.63 x -3.72, -38.53
    { 204, NoLogo, 161, LineMetaDataContent::RapidTransit, Color{0xf36421} }, // S 1 OSM: 6116272 WD: Q56378877 50.88, 13.46 x 51.16, 14.24
    { 1508, NoLogo, 161, LineMetaDataContent::RapidTransit, Color{0xb8282e} }, // S 2 OSM: 6116280 WD: Q56378880 50.96, 13.72 x 51.13, 13.93
    { 1418, NoLogo, 161, LineMetaDataContent::RapidTransit, Color{0xed0172} }, // S 3 OSM: 6116305 WD: Q56378881 50.9, 13.34 x 51.04, 13.73
    { 196, 1431, 161, LineMetaDataContent::RapidTransit, Color{0x9d0921} }, // S4 OSM: 6157906 WD: Q695595 47.81, 15.98 x 48.4, 16.41
    { 181, 5802, 5658, LineMetaDataContent::RapidTransit, Color{0xe62621} }, // B OSM: 6161229 WD: Q10318669 41.15, -8.758 x 41.38, -8.582
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc01115} }, // 1 OSM: 6182760 WD: Q2085324 51.98, 4.277 x 52.12, 4.359
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x006600} }, // 2 OSM: 6182761 WD: Q3926989 52.05, 4.236 x 52.09, 4.383
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0093de} }, // 6 OSM: 6182762 WD: Q2205103 52.06, 4.264 x 52.1, 4.4
    { 54, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xcd853f} }, // 11 OSM: 6192619 WD: Q2084217 52.06, 4.27 x 52.11, 4.324
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff66ff} }, // 12 OSM: 6192620 WD: Q2541548 52.06, 4.252 x 52.09, 4.324
    { 119, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xa6c116} }, // 9 OSM: 6192621 WD: Q2293268 52.03, 4.257 x 52.12, 4.329
    { 130, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe63a6b} }, // 15 OSM: 6197181 WD: Q2202159 52.04, 4.315 x 52.08, 4.393
    { 26, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfa7222} }, // 16 OSM: 6197182 WD: Q2746551 52.02, 4.271 x 52.1, 4.327
    { 164, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x006b8b} }, // 17 OSM: 6197183 WD: Q2417431 52.02, 4.289 x 52.08, 4.339
    { 134, NoLogo, 5617, LineMetaDataContent::Tramway, Color{0xc01115} }, // 19 OSM: 6197184 WD: Q2886326 52.01, 4.35 x 52.09, 4.406
    { 2052, NoLogo, 5829, LineMetaDataContent::RapidTransit, Color{0x0275a4} }, // BLUE OSM: 6265609 WD: Q4929367 32.65, -96.81 x 32.92, -96.56
    { 2057, NoLogo, 5829, LineMetaDataContent::RapidTransit, Color{0xcc0000} }, // RED OSM: 6265610 WD: Q16984038 32.72, -96.87 x 33.03, -96.7
    { 2061, NoLogo, 5829, LineMetaDataContent::RapidTransit, Color{0x00873f} }, // GREEN OSM: 6265672 WD: Q5602816 32.72, -96.94 x 32.99, -96.68
    { 2067, NoLogo, 5829, LineMetaDataContent::RapidTransit, Color{0xcc6600} }, // ORANGE OSM: 6265702 WD: Q7099665 32.78, -97.04 x 33.03, -96.7
    { 2074, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000066} }, // 620 OSM: 6265792 WD: Q19878111 32.75, -96.82 x 32.78, -96.81
    { 65, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0000ff} }, // 10 OSM: 6286483 WD: Q3239219 59.33, 17.88 x 59.4, 18.07
    { 54, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0000ff} }, // 11 OSM: 6286484 WD: Q3239220 59.33, 17.91 x 59.42, 18.07
    { 164, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x008000} }, // 17 OSM: 6286485 WD: Q3239225 59.27, 17.92 x 59.34, 18.13
    { 22, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x008000} }, // 18 OSM: 6286486 WD: Q3239226 59.23, 17.98 x 59.34, 18.1
    { 134, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x008000} }, // 19 OSM: 6286487 WD: Q3239227 59.26, 17.83 x 59.37, 18.08
    { 58, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // 13 OSM: 6286488 WD: Q3239222 59.24, 17.81 x 59.36, 18.1
    { 126, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // 14 OSM: 6286489 WD: Q3239223 59.29, 17.96 x 59.4, 18.08
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00985f} }, // 5 OSM: 6334310 60.16, 24.94 x 60.17, 24.97
    { 2078, 5864, 5890, LineMetaDataContent::Subway, Color{0x0a9cda} }, // Victoria OSM: 6354922 WD: Q203030 51.46, -0.1441 x 51.59, -0.01927
    { 2087, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x3a75c4} }, // North Clyde OSM: 6399061 55.85, -4.733 x 56, -3.19
    { 2099, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x2e8b57} }, // North Berwick OSM: 6399368 55.93, -3.188 x 56.06, -2.513
    { 2113, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xcc5500} }, // Maryhill OSM: 6403662 55.86, -4.321 x 55.9, -4.239
    { 2122, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0b4ea2} }, // TL 1 OSM: 6421836 50.83, -0.5143 x 52.14, -0.03743
    { 2127, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x629f3f} }, // Santa Cruz OSM: 6432131 WD: Q10318722 -22.92, -43.69 x -22.85, -43.19
    { 2138, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0691f6} }, // Japeri OSM: 6432248 WD: Q10318695 -22.91, -43.66 x -22.64, -43.19
    { 9, NoLogo, 5021, LineMetaDataContent::Subway, Color{0xffcc29} }, // 4 OSM: 6432702 WD: Q6553130 -23.01, -43.31 x -22.98, -43.2
    { 1621, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x00ab4e} }, // KTL OSM: 6452936 WD: Q736412 22.29, 114.2 x 22.34, 114.3
    { 2145, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe6180a} }, // 505 OSM: 6481283 WD: Q13645607 22.38, 114 x 22.41, 114
    { 2149, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x1a8539} }, // 507 OSM: 6481317 WD: Q15917019 22.37, 114 x 22.41, 114
    { 2153, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x8d3219} }, // 610 OSM: 6481421 WD: Q15908713 22.37, 114 x 22.45, 114
    { 2157, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf4e619} }, // 615 OSM: 6481435 WD: Q15903207 22.37, 114 x 22.45, 114
    { 2161, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x44adc3} }, // 614 OSM: 6485195 WD: Q15903043 22.37, 114 x 22.45, 114
    { 2165, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x70147b} }, // 761P OSM: 6485222 WD: Q15909914 22.44, 114 x 22.47, 114
    { 2170, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf7931d} }, // SN 5 OSM: 6489645 51.07, -0.3198 x 51.5, 0.2709
    { 2175, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009933} }, // T-A OSM: 6491413 6.233, -75.57 x 6.248, -75.54
    { 190, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // T1 OSM: 6497386 43.28, 5.547 x 43.3, 5.566
    { 2179, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x6633ff} }, // T1 R OSM: 6545828 36.72, 3.083 x 36.78, 3.263
    { 2184, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff00ff} }, // 18E OSM: 6547489 WD: Q63230200 38.7, -9.203 x 38.71, -9.145
    { 2189, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xba85bb} }, // 706 OSM: 6558996 WD: Q6718531 22.45, 114 x 22.47, 114
    { 2193, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x8cc022} }, // 705 OSM: 6558997 WD: Q16057726 22.45, 114 x 22.47, 114
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe41f25} }, // 4 OSM: 6576221 48.22, 14.23 x 48.31, 14.29
    { 1370, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0171b7} }, // 801 OSM: 6585129 33.77, -118.3 x 34.05, -118.2
    { 2197, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff7f00} }, // 25E OSM: 6595981 WD: Q63230206 38.71, -9.17 x 38.72, -9.135
    { 2201, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // CBTU OSM: 6636198 WD: Q10388583 -9.672, -35.86 x -9.476, -35.72
    { 2206, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // C13 OSM: 6641930 50.81, 12.81 x 50.92, 12.94
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // 1 OSM: 6667548 WD: Q30926891 -22.91, -43.21 x -22.89, -43.17
    { 524, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // T2 OSM: 6679929 42.84, -2.685 x 42.88, -2.665
    { 42, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x2948a3} }, // 7 OSM: 6679981 52.38, 16.88 x 52.42, 16.96
    { 22, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfad50e} }, // 18 OSM: 6680332 52.38, 16.88 x 52.42, 17
    { 2210, NoLogo, 5316, LineMetaDataContent::Subway, Color{0xb2aed3} }, // L12 OSM: 6699916 WD: Q20107064 41.4, 2.119 x 41.4, 2.125
    { 126, NoLogo, 2223, LineMetaDataContent::Subway, Color{0x81312f} }, // 14 OSM: 6728233 WD: Q6553073 23.24, 113.3 x 23.57, 113.6
    { 2214, NoLogo, 161, LineMetaDataContent::RapidTransit, Color{0x6c421b} }, // S14 OSM: 6731045 WD: Q7388188 47.27, 8.429 x 47.41, 8.84
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x90ee90} }, // 8 OSM: 6749429 49.78, 24.03 x 49.84, 24.06
    { 153, NoLogo, 1431, LineMetaDataContent::RapidTransit, Color{0x3c2c90} }, // S3 OSM: 6754348 WD: Q67882855 48.26, 14.29 x 48.36, 14.52
    { 2218, 414, NoLogo, LineMetaDataContent::Subway, Color{0x302276} }, // U74 OSM: 6760736 WD: Q661002 51.16, 6.615 x 51.28, 6.853
    { 19, NoLogo, 5906, LineMetaDataContent::Subway, Color{0x9aaead} }, // 8 OSM: 6768162 WD: Q11124525 30.43, 114.3 x 30.68, 114.4
    { 55, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x791714} }, // 1 OSM: 6774704 WD: Q10318644 -12.99, -38.52 x -12.92, -38.47
    { 2222, NoLogo, 5927, LineMetaDataContent::Tramway, Color{0x83b81a} }, // Τ5 OSM: 6792080 WD: Q25535312 37.85, 23.7 x 37.97, 23.75
    { 2226, NoLogo, 5927, LineMetaDataContent::Tramway, Color{0x0098d4} }, // Τ3 OSM: 6792082 WD: Q25535308 37.85, 23.66 x 37.94, 23.75
    { 2230, NoLogo, 5927, LineMetaDataContent::Tramway, Color{0xe32119} }, // Τ4 OSM: 6792083 WD: Q25535309 37.92, 23.66 x 37.97, 23.74
    { 41, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfff200} }, // S7 OSM: 6796259 48.63, 8.065 x 49.01, 8.432
    { 2234, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfff200} }, // S71 OSM: 6796260 48.63, 8.065 x 48.99, 8.405
    { 2238, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x6d682a} }, // S81 OSM: 6796368 48.44, 8.215 x 48.99, 8.782
    { 42, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffa500} }, // 7 OSM: 6799066 39.75, 30.49 x 39.76, 30.54
    { 55, 5967, NoLogo, LineMetaDataContent::Subway, Color{0xe4002b} }, // 1 OSM: 6800211 WD: Q1326478 31.11, 121.4 x 31.4, 121.5
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00bfff} }, // 4 OSM: 6800376 39.75, 30.5 x 39.78, 30.56
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffff00} }, // 6 OSM: 6800649 39.74, 30.52 x 39.78, 30.59
    { 61, NoLogo, 1431, LineMetaDataContent::RapidTransit, Color{0xf5831a} }, // S1 OSM: 6800744 WD: Q67882646 48.02, 14.29 x 48.3, 14.52
    { 26, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x2cd5c4} }, // 16 OSM: 6803864 WD: Q5954911 30.91, 121.6 x 31.2, 121.9
    { 6, 5976, NoLogo, LineMetaDataContent::Subway, Color{0xac4fc6} }, // 5 OSM: 6806165 WD: Q1331322 30.91, 121.4 x 31.12, 121.5
    { 59, 5985, NoLogo, LineMetaDataContent::Subway, Color{0xffd100} }, // 3 OSM: 6817204 WD: Q1326495 31.15, 121.4 x 31.41, 121.5
    { 2242, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xb6bd00} }, // SIL OSM: 6827213 WD: Q2041013 22.24, 114.1 x 22.28, 114.2
    { 27, 5994, NoLogo, LineMetaDataContent::Subway, Color{0xd9017a} }, // 6 OSM: 6840940 WD: Q631135 31.15, 121.5 x 31.36, 121.6
    { 2246, NoLogo, 6003, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // TL-1 OSM: 6849311 WD: Q5985920 20.61, -103.4 x 20.74, -103.4
    { 2251, NoLogo, 6003, LineMetaDataContent::RapidTransit, Color{0x008000} }, // TL-2 OSM: 6851904 WD: Q5986178 20.66, -103.4 x 20.68, -103.3
    { 2256, 2818, 2554, LineMetaDataContent::Subway, Color{0xffff00} }, // 8А OSM: 6855054 WD: Q585986 55.63, 37.33 x 55.79, 37.59
    { 366, 6021, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff6600} }, // L2 OSM: 6857222 WD: Q5986175 -37.03, -73.16 x -36.82, -73.06
    { 362, 6033, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff6600} }, // L1 OSM: 6857223 WD: Q5985914 -36.98, -73.12 x -36.71, -72.94
    { 44, NoLogo, 1431, LineMetaDataContent::RapidTransit, Color{0xee008d} }, // S5 OSM: 6881147 WD: Q67882950 48.27, 14.02 x 48.3, 14.29
    { 230, 6045, NoLogo, LineMetaDataContent::RapidTransit, Color{0xc6cc00} }, // J OSM: 6904183 WD: Q93388 48.88, 1.478 x 49.29, 2.326
    { 2260, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf68c59} }, // T3a OSM: 6907402 48.82, 2.271 x 48.85, 2.411
    { 1581, 6068, 2957, LineMetaDataContent::Tramway, Color{0xf2af00} }, // T4 OSM: 6910344 WD: Q1826681 48.89, 2.478 x 48.93, 2.562
    { 1318, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xb156a1} }, // T5 OSM: 6910410 48.94, 2.356 x 48.98, 2.391
    { 1773, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe85426} }, // T6 OSM: 6910437 48.78, 2.169 x 48.81, 2.301
    { 2264, 6085, 2957, LineMetaDataContent::Tramway, Color{0xb98b59} }, // T7 OSM: 6910465 WD: Q3239019 48.71, 2.352 x 48.79, 2.373
    { 1417, 6102, NoLogo, LineMetaDataContent::RapidTransit, Color{0x5cda21} }, // RS 3 OSM: 6925925 WD: Q84703705 53.05, 8.002 x 53.18, 8.815
    { 1270, 6117, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // RS 4 OSM: 6925927 WD: Q84703708 53.05, 8.452 x 53.49, 8.815
    { 2267, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xffcf00} }, // OrlyVAL OSM: 6928902 WD: Q432593 48.73, 2.3 x 48.76, 2.37
    { 2275, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x142b4a} }, // CDGVAL OSM: 6928933 WD: Q1023114 49, 2.542 x 49.01, 2.572
    { 219, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x800080} }, // A OSM: 6937084 WD: Q4268353 24.95, 121.2 x 25.09, 121.5
    { 552, 6132, NoLogo, LineMetaDataContent::Subway, Color{0xfccc0a} }, // W OSM: 6942556 WD: Q126567 40.7, -74.01 x 40.78, -73.91
    { 50, NoLogo, 1431, LineMetaDataContent::RapidTransit, Color{0x00acaf} }, // S2 OSM: 6967088 WD: Q67882763 48.17, 14.03 x 48.29, 14.29
    { 1684, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008531} }, // Luas Green Line OSM: 6975500 WD: Q2086105 53.24, -6.298 x 53.37, -6.143
    { 2282, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x68c56b} }, // DART OSM: 6979159 WD: Q839815 53.14, -6.255 x 53.45, -6.06
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc00027} }, // 1 OSM: 6981890 47.74, 7.321 x 47.78, 7.343
    { 1461, 6158, 3643, LineMetaDataContent::Tramway, Color{0xf7e017} }, // 32 OSM: 6995933 WD: Q2637503 50.78, 4.313 x 50.88, 4.416
    { 6, 6180, 6201, LineMetaDataContent::Subway, Color{0xb5ba05} }, // 5 OSM: 6996917 WD: Q957143 50.81, 4.266 x 50.86, 4.432
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffd80e} }, // 2 OSM: 7006051 47.73, 7.297 x 47.76, 7.352
    { 55, 6225, 6201, LineMetaDataContent::Subway, Color{0xc4008f} }, // 1 OSM: 7006076 WD: Q1345228 50.84, 4.319 x 50.86, 4.464
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00a651} }, // 3 OSM: 7006942 47.74, 7.276 x 47.76, 7.344
    { 2287, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x142b4a} }, // LISA OSM: 7011253 WD: Q1023114 49, 2.578 x 49, 2.59
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 2 OSM: 7064054 WD: Q30926895 -22.91, -43.21 x -22.9, -43.17
    { 50, 6246, 161, LineMetaDataContent::RapidTransit, Color{0x6cc247} }, // S2 OSM: 7091572 WD: Q7388247 48.13, 11.25 x 48.41, 11.91
    { 420, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x223344} }, // 22 OSM: 7095091 54.26, 48.28 x 54.36, 48.41
    { 362, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // L1 OSM: 7106760 WD: Q3011576 43.24, -3.013 x 43.4, -2.897
    { 196, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // S4 OSM: 7113761 46.55, 13.37 x 46.63, 13.85
    { 50, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x006400} }, // S2 OSM: 7113763 46.53, 13.83 x 46.77, 14.37
    { 61, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // S1 OSM: 7113764 46.6, 12.77 x 46.95, 14.48
    { 42, 6262, 3643, LineMetaDataContent::Tramway, Color{0xfff06e} }, // 7 OSM: 7135778 WD: Q3239018 50.81, 4.336 x 50.9, 4.408
    { 209, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc5168c} }, // 55 OSM: 7141514 WD: Q6811960 339.5, 249.5 x 339.5, 249.5
    { 370, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xe3007d} }, // L3 OSM: 7141757 WD: Q2992379 43.25, -2.926 x 43.27, -2.889
    { 935, 6283, 3643, LineMetaDataContent::Tramway, Color{0xde3b21} }, // 92 OSM: 7152034 WD: Q2661521 50.79, 4.34 x 50.88, 4.381
    { 196, NoLogo, 1431, LineMetaDataContent::RapidTransit, Color{0x97bd2f} }, // S4 OSM: 7152118 WD: Q67882906 47.91, 14.1 x 48.29, 14.29
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x37b355} }, // 2 OSM: 7157243 WD: Q60031554 48.38, 9.936 x 48.43, 9.987
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xed1b24} }, // 1 OSM: 7157244 WD: Q60031375 48.39, 9.955 x 48.43, 10.03
    { 362, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc00b31} }, // L1 OSM: 7183555 WD: Q29634861 37.14, -3.654 x 37.23, -3.592
    { 2292, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // C-2 OSM: 7193330 43.25, -3.112 x 43.32, -2.928
    { 2296, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // C14 OSM: 7204222 50.81, 12.92 x 50.99, 12.96
    { 2300, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // C15 OSM: 7211723 50.81, 12.92 x 50.97, 13.12
    { 16, 6305, 3931, LineMetaDataContent::Subway, Color{0x216eb4} }, // 2 OSM: 7227705 WD: Q50718 48.85, 2.278 x 48.88, 2.399
    { 55, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x93c21c} }, // 1 OSM: 7252644 WD: Q60669571 -23.97, -46.41 x -23.96, -46.31
    { 2304, 6323, 5890, LineMetaDataContent::Subway, Color{0xe42313} }, // Central OSM: 7254206 WD: Q205355 51.5, -0.4378 x 51.69, 0.1146
    { 39, 6348, 1346, LineMetaDataContent::RapidTransit, Color{0xbd76a1} }, // E OSM: 7271953 WD: Q668655 48.74, 2.327 x 48.9, 2.761
    { 58, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf6c828} }, // 13 OSM: 7295272 WD: Q96483392 47.35, 8.481 x 47.41, 8.542
    { 16, 6369, 6201, LineMetaDataContent::Subway, Color{0xf57000} }, // 2 OSM: 7305855 WD: Q1826676 50.83, 4.321 x 50.87, 4.37
    { 27, NoLogo, 2223, LineMetaDataContent::Subway, Color{0x772059} }, // 6 OSM: 7322006 WD: Q6553140 23.11, 113.2 x 23.2, 113.5
    { 2312, 6390, 161, LineMetaDataContent::RapidTransit, Color{0x9f4c37} }, // S41 OSM: 7369771 WD: Q12374455 52.46, 13.28 x 52.55, 13.48
    { 983, 6405, 3643, LineMetaDataContent::Tramway, Color{0x338c26} }, // 81 OSM: 7375224 WD: Q2133516 50.82, 4.28 x 50.84, 4.408
    { 61, NoLogo, 6427, LineMetaDataContent::RapidTransit, Color{0x025f33} }, // S1 OSM: 7382640 WD: Q24929119 50.6, 4.32 x 51.22, 4.497
    { 50, NoLogo, 6427, LineMetaDataContent::RapidTransit, Color{0xf26122} }, // S2 OSM: 7383577 WD: Q56309162 50.61, 4.139 x 50.9, 4.716
    { 1188, NoLogo, 6427, LineMetaDataContent::RapidTransit, Color{0x059797} }, // S20 OSM: 7386794 WD: Q56309254 50.67, 4.565 x 50.88, 4.719
    { 44, NoLogo, 6427, LineMetaDataContent::RapidTransit, Color{0xfecc09} }, // S5 OSM: 7387151 WD: Q56309389 50.69, 3.87 x 51.02, 4.484
    { 153, NoLogo, 6427, LineMetaDataContent::RapidTransit, Color{0x212876} }, // S3 OSM: 7388964 WD: Q56309590 50.82, 3.601 x 51.02, 4.366
    { 196, NoLogo, 6427, LineMetaDataContent::RapidTransit, Color{0xce2127} }, // S4 OSM: 7389117 WD: Q56309251 50.82, 4.039 x 50.94, 4.433
    { 186, NoLogo, 6427, LineMetaDataContent::RapidTransit, Color{0x965f26} }, // S6 OSM: 7391007 WD: Q56309855 50.69, 3.87 x 50.88, 4.378
    { 41, NoLogo, 6427, LineMetaDataContent::RapidTransit, Color{0x581759} }, // S7 OSM: 7391045 WD: Q56309167 50.73, 4.241 x 51.02, 4.523
    { 47, NoLogo, 6427, LineMetaDataContent::RapidTransit, Color{0x0d96cd} }, // S8 OSM: 7391071 WD: Q56309403 50.65, 4.336 x 50.87, 4.617
    { 466, NoLogo, 6427, LineMetaDataContent::RapidTransit, Color{0x67bc45} }, // S9 OSM: 7391314 WD: Q56309779 50.68, 4.335 x 50.9, 4.717
    { 1030, NoLogo, 6427, LineMetaDataContent::RapidTransit, Color{0xff1f20} }, // S10 OSM: 7391375 WD: Q56309273 50.83, 4.039 x 51.02, 4.366
    { 2316, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x4a611c} }, // RL1 OSM: 7399137 WD: Q3781389 41.62, 0.631 x 41.79, 0.8166
    { 226, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffff00} }, // 25 OSM: 7409703 31.2, 29.9 x 31.22, 29.93
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf38230} }, // 1 OSM: 7418079 WD: Q59134535 33.53, -7.67 x 33.6, -7.5
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffdb2f} }, // 2 OSM: 7418090 WD: Q59159905 33.56, -7.682 x 33.61, -7.507
    { 1581, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffa500} }, // T4 OSM: 7420266 WD: Q15507510 41.02, 28.85 x 41.12, 28.93
    { 58, 6449, 3931, LineMetaDataContent::Subway, Color{0x89c7d6} }, // 13 OSM: 7420641 WD: Q50759 48.81, 2.284 x 48.95, 2.369
    { 15, 6468, 3931, LineMetaDataContent::Subway, Color{0x328e5b} }, // 12 OSM: 7420642 WD: Q50757 48.82, 2.273 x 48.91, 2.366
    { 54, 6487, 3931, LineMetaDataContent::Subway, Color{0x8e6538} }, // 11 OSM: 7420643 WD: Q50756 48.86, 2.348 x 48.88, 2.416
    { 19, 6506, 3931, LineMetaDataContent::Subway, Color{0xc5a3ca} }, // 8 OSM: 7420644 WD: Q50751 48.77, 2.278 x 48.87, 2.465
    { 6, 6524, 3931, LineMetaDataContent::Subway, Color{0xde8b53} }, // 5 OSM: 7420645 WD: Q50745 48.83, 2.355 x 48.91, 2.449
    { 2320, 6542, 3931, LineMetaDataContent::Subway, Color{0x89c7d6} }, // 3bis OSM: 7420646 WD: Q50742 48.87, 2.399 x 48.88, 2.406
    { 317, 6564, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe4b4d1} }, // R OSM: 7420697 WD: Q93383 48.01, 2.373 x 48.84, 2.946
    { 378, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7b4339} }, // H OSM: 7420698 WD: Q2572054 48.88, 2.093 x 49.28, 2.474
    { 481, 6587, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00b092} }, // N OSM: 7420700 WD: Q93376 48.64, 1.37 x 48.99, 2.319
    { 181, 6610, 1346, LineMetaDataContent::RapidTransit, Color{0x5092c9} }, // B OSM: 7420701 WD: Q1347825 48.69, 2.071 x 49.01, 2.642
    { 35, 1431, 161, LineMetaDataContent::RapidTransit, Color{0xfd8fb4} }, // S OSM: 7424194 WD: Q695595 48.17, 16.33 x 48.26, 16.4
    { 9, 6631, NoLogo, LineMetaDataContent::Subway, Color{0x5f259f} }, // 4 OSM: 7448424 WD: Q1326504 31.18, 121.4 x 31.26, 121.5
    { 19, 6640, NoLogo, LineMetaDataContent::Subway, Color{0x009fdf} }, // 8 OSM: 7451833 WD: Q1152341 31.06, 121.5 x 31.32, 121.5
    { 119, 6649, NoLogo, LineMetaDataContent::Subway, Color{0x71c5e8} }, // 9 OSM: 7451835 WD: Q1152370 30.99, 121.2 x 31.27, 121.7
    { 15, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x007b5f} }, // 12 OSM: 7451887 WD: Q877180 31.13, 121.4 x 31.28, 121.6
    { 58, 6658, NoLogo, LineMetaDataContent::Subway, Color{0xef95cf} }, // 13 OSM: 7451890 WD: Q607539 31.17, 121.3 x 31.25, 121.6
    { 65, 6668, NoLogo, LineMetaDataContent::Subway, Color{0xc1a7e2} }, // 10 OSM: 7452119 WD: Q528209 31.17, 121.3 x 31.33, 121.5
    { 2325, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xed8000} }, // I2 OSM: 7527498 WD: Q484739 37.44, 126.6 x 37.6, 126.8
    { 303, 6678, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfda600} }, // U OSM: 7530882 WD: Q491655 37.72, 127 x 37.75, 127.1
    { 39, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x509f22} }, // E OSM: 7531174 37.24, 127.1 x 37.29, 127.2
    { 552, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x797979} }, // W OSM: 7533584 WD: Q3832795 37.58, 127 x 37.66, 127
    { 267, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // Blue OSM: 7548642 41.47, -81.71 x 41.51, -81.54
    { 469, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // Green OSM: 7548643 41.48, -81.71 x 41.51, -81.52
    { 279, NoLogo, 6706, LineMetaDataContent::Subway, Color{0xff0000} }, // Red OSM: 7551457 WD: Q2136023 41.41, -81.84 x 41.53, -81.58
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 1 OSM: 7557928 339.5, 249.5 x 339.5, 249.5
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00ff00} }, // 3 OSM: 7560907 51.34, -0.1055 x 51.38, -0.01745
    { 2328, 6729, 6746, LineMetaDataContent::Subway, Color{0xffff00} }, // YL OSM: 7572167 WD: Q4710841 38.79, -77.08 x 38.95, -77
    { 2331, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0088ce} }, // BLLB OSM: 7572385 40.29, -80.03 x 40.45, -79.99
    { 1882, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x77b6e4} }, // BLSV OSM: 7575525 40.34, -80.05 x 40.45, -79.99
    { 2057, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf48465} }, // RED OSM: 7575526 40.34, -80.05 x 40.45, -79.99
    { 524, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe40053} }, // T2 OSM: 7580423 WD: Q3239070 50.32, 3.509 x 50.47, 3.596
    { 2343, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x087c4c} }, // TC OSM: 7597545 WD: Q3538439 -34.51, -58.58 x -34.42, -58.48
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x33a23d} }, // 2 OSM: 7625892 WD: Q17501 37.48, 126.8 x 37.58, 127.1
    { 9, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x289dd5} }, // 4 OSM: 7625893 WD: Q489253 37.3, 126.7 x 37.67, 127.1
    { 362, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0033cc} }, // L1 OSM: 7627370 WD: Q20685853 36.71, 3.054 x 36.79, 3.138
    { 256, 6767, 3643, LineMetaDataContent::Tramway, Color{0xe3ba12} }, // 51 OSM: 7632520 WD: Q751385 50.78, 4.326 x 50.89, 4.349
    { 955, 6789, 3643, LineMetaDataContent::Tramway, Color{0xe87d0d} }, // 93 OSM: 7632524 WD: Q2845878 50.82, 4.33 x 50.89, 4.372
    { 16, NoLogo, 3961, LineMetaDataContent::Subway, Color{0x006699} }, // 2 OSM: 7660420 WD: Q1771527 56.32, 43.89 x 56.34, 43.97
    { 260, 6811, 6811, LineMetaDataContent::Subway, Color{0xf25e24} }, // M1 OSM: 7664663 WD: Q207287 60.16, 24.74 x 60.21, 25.15
    { 330, 6811, 6811, LineMetaDataContent::Subway, Color{0xf25e24} }, // M2 OSM: 7664664 WD: Q207287 60.16, 24.8 x 60.24, 25.11
    { 2346, 6836, 5890, LineMetaDataContent::Subway, Color{0xae6017} }, // Bakerloo OSM: 7666698 WD: Q19892 51.49, -0.3357 x 51.59, -0.09912
    { 2355, 6862, 5890, LineMetaDataContent::Subway, Color{0xf4a9be} }, // Hammersmith & City OSM: 7666927 WD: Q211270 51.49, -0.2268 x 51.54, 0.08088
    { 2374, 6883, 5890, LineMetaDataContent::Subway, Color{0xffd329} }, // Circle OSM: 7671007 WD: Q210321 51.49, -0.2268 x 51.53, -0.07523
    { 2381, 6907, 5890, LineMetaDataContent::Subway, Color{0x93ceba} }, // Waterloo & City OSM: 7672075 WD: Q207699 51.5, -0.1142 x 51.51, -0.09074
    { 2397, 6928, 5890, LineMetaDataContent::Subway, Color{0x949699} }, // Jubilee OSM: 7673326 WD: Q961290 51.5, -0.303 x 51.62, 0.01165
    { 2405, 6953, 5890, LineMetaDataContent::Subway, Color{0x91005a} }, // Metropolitan OSM: 7673626 WD: Q19891 51.51, -0.6112 x 51.71, -0.0757
    { 2418, 6983, 5890, LineMetaDataContent::Subway, Color{0x00a166} }, // District OSM: 7677096 WD: Q211265 51.42, -0.3016 x 51.56, 0.253
    { 55, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 7683834 WD: Q239927 37.5, 15.05 x 37.52, 15.1
    { 55, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0000ff} }, // 1 OSM: 7684062 WD: Q6553099 19.09, 72.82 x 19.13, 72.91
    { 59, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x00af23} }, // 3 OSM: 7686574 WD: Q5017776 30.05, 31.25 x 30.12, 31.35
    { 2427, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xdc241f} }, // NSL OSM: 7695961 WD: Q759229 1.27, 103.7 x 1.45, 103.9
    { 55, 7009, NoLogo, LineMetaDataContent::Subway, Color{0xffa500} }, // 1 OSM: 7702663 WD: Q389415 34.39, 132.4 x 34.48, 132.5
    { 378, NoLogo, 7025, LineMetaDataContent::Subway, Color{0x0077cc} }, // H OSM: 7702769 WD: Q1073881 33.59, 130.4 x 33.63, 130.4
    { 2431, 7054, 5890, LineMetaDataContent::Subway, Color{0x094fa3} }, // Piccadilly OSM: 7702940 WD: Q207689 51.46, -0.4929 x 51.65, -0.09515
    { 2442, 7082, 5890, LineMetaDataContent::Subway, Color{0x000000} }, // Northern OSM: 7702944 WD: Q214793 51.4, -0.2756 x 51.65, -0.08677
    { 432, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff4500} }, // K OSM: 7703353 WD: Q6455382 33.58, 130.3 x 33.6, 130.4
    { 2451, 7108, NoLogo, LineMetaDataContent::Subway, Color{0xc61094} }, // MM OSM: 7703640 WD: Q852314 35.44, 139.6 x 35.47, 139.7
    { 26, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x313495} }, // 16 OSM: 7704225 52.38, 16.91 x 52.46, 17
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x38ab43} }, // 6 OSM: 7705201 52.38, 16.83 x 52.41, 17
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe7212a} }, // 8 OSM: 7705202 52.38, 16.88 x 52.41, 17
    { 55, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xee3c3c} }, // 1 OSM: 7705626 29.55, 52.45 x 29.69, 52.6
    { 42, NoLogo, 7138, LineMetaDataContent::Subway, Color{0x6a00ff} }, // 7 OSM: 7705644 WD: Q20110124 35.67, 51.37 x 35.75, 51.49
    { 9, NoLogo, 7138, LineMetaDataContent::Subway, Color{0xffff00} }, // 4 OSM: 7705669 WD: Q20110121 35.69, 51.3 x 35.72, 51.5
    { 2454, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x800080} }, // BGL OSM: 7705740 WD: Q87056 35.16, 128.9 x 35.27, 129
    { 2458, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x3caabc} }, // THZ1 OSM: 7708095 23.1, 113.3 x 23.11, 113.4
    { 55, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 7712343 WD: Q25420888 8.962, -79.55 x 9.065, -79.51
    { 432, 7160, 7202, LineMetaDataContent::Subway, Color{0xffc0cb} }, // K OSM: 7712576 WD: Q1078347 35.2, 136.9 x 35.2, 136.9
    { 313, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x07502b} }, // P OSM: 7712875 WD: Q7230715 34.64, 135.2 x 34.7, 135.2
    { 432, NoLogo, 7235, LineMetaDataContent::Subway, Color{0x0388c0} }, // K OSM: 7712969 WD: Q844019 34.65, 135.1 x 34.69, 135.2
    { 9, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xdc241f} }, // 4 OSM: 7713538 WD: Q1004293 22.52, 114 x 22.73, 114.1
    { 119, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf04723} }, // 9 OSM: 7715858 52.37, 16.9 x 52.41, 16.94
    { 330, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x009a4c} }, // M2 OSM: 7719078 WD: Q1880934 41.01, 28.95 x 41.14, 29.03
    { 2463, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xe32726} }, // M1B OSM: 7719079 WD: Q1880934 41.01, 28.84 x 41.05, 28.95
    { 8, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xe91e76} }, // M4 OSM: 7719080 WD: Q1880989 40.88, 29.02 x 41, 29.25
    { 2467, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xe32726} }, // M1A OSM: 7719081 WD: Q6048705 40.98, 28.82 x 41.05, 28.95
    { 333, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x00a8e1} }, // M3 OSM: 7719082 WD: Q1880963 41.03, 28.77 x 41.11, 28.84
    { 31, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xcaaa79} }, // M6 OSM: 7719783 WD: Q16949744 41.08, 29.01 x 41.09, 29.05
    { 35, NoLogo, 7235, LineMetaDataContent::Subway, Color{0x00ae8e} }, // S OSM: 7720729 WD: Q1066548 34.66, 135 x 34.76, 135.2
    { 263, NoLogo, 7266, LineMetaDataContent::Subway, Color{0x0000ff} }, // MRT Blue OSM: 7725030 WD: Q2486364 13.71, 100.4 x 13.81, 100.6
    { 1348, NoLogo, 7266, LineMetaDataContent::Subway, Color{0x800080} }, // MRT Purple OSM: 7725058 WD: Q6584549 13.81, 100.4 x 13.89, 100.5
    { 362, 7289, NoLogo, LineMetaDataContent::Subway, Color{0x228b22} }, // L1 OSM: 7727216 WD: Q5985884 -12.21, -77.01 x -11.96, -76.93
    { 2471, 7312, NoLogo, LineMetaDataContent::Subway, Color{0xc82127} }, // DX OSM: 7728256 WD: Q20388 37.29, 127 x 37.5, 127.1
    { 2474, NoLogo, 7345, LineMetaDataContent::Subway, Color{0x2e8b57} }, // 仙台市南北線 (Sendai Namboku Line) OSM: 7732249 WD: Q908156 38.21, 140.9 x 38.32, 140.9
    { 2515, NoLogo, 7345, LineMetaDataContent::Subway, Color{0x00bfff} }, // 仙台市東西線 (Sendai Tozai Line) OSM: 7732250 WD: Q7450186 38.24, 140.8 x 38.26, 140.9
    { 181, NoLogo, 7373, LineMetaDataContent::Subway, Color{0x0000ff} }, // B OSM: 7732280 WD: Q841360 35.4, 139.5 x 35.57, 139.6
    { 201, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x1d8b3b} }, // G OSM: 7732283 WD: Q3116096 35.51, 139.5 x 35.56, 139.6
    { 55, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xcc0000} }, // 1 OSM: 7732970 WD: Q4215382 -33.46, -70.72 x -33.41, -70.55
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xffbe2e} }, // 2 OSM: 7732971 WD: Q11690005 -33.54, -70.66 x -33.38, -70.64
    { 9, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x292d91} }, // 4 OSM: 7732972 WD: Q9025952 -33.61, -70.6 x -33.42, -70.57
    { 2554, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0099ff} }, // 4A OSM: 7732973 WD: Q11690009 -33.54, -70.66 x -33.52, -70.6
    { 6, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x006633} }, // 5 OSM: 7732974 WD: Q9025969 -33.53, -70.76 x -33.44, -70.6
    { 27, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x8e16a1} }, // 6 OSM: 7732978 WD: Q5986809 -33.48, -70.7 x -33.42, -70.6
    { 59, 7408, 3931, LineMetaDataContent::Subway, Color{0x9a9940} }, // 3 OSM: 7733214 WD: Q50741 48.86, 2.28 x 48.9, 2.418
    { 55, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 7733917 WD: Q494079 55.74, 49.08 x 55.86, 49.22
    { 55, 2707, 7426, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 7733918 WD: Q594532 54.98, 82.89 x 55.06, 82.94
    { 16, 2891, 7426, LineMetaDataContent::Subway, Color{0x008000} }, // 2 OSM: 7733919 WD: Q2711371 55.03, 82.9 x 55.04, 82.98
    { 55, 7445, 7445, LineMetaDataContent::Subway, Color{0x1c8c3a} }, // 1 OSM: 7733920 WD: Q750441 56.8, 60.6 x 56.9, 60.63
    { 2557, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x076c57} }, // Verde OSM: 7733971 WD: Q10318743 -15.84, -48.12 x -15.79, -47.88
    { 2563, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xeb9710} }, // Laranja OSM: 7733972 WD: Q10318700 -15.88, -48.09 x -15.79, -47.88
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // 2 OSM: 7734060 WD: Q25421356 18.48, -69.97 x 18.51, -69.86
    { 55, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0000ff} }, // 1 OSM: 7734061 WD: Q25421357 18.45, -69.93 x 18.55, -69.9
    { 55, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // 1 OSM: 7734069 10.62, -71.67 x 10.64, -71.62
    { 55, 7464, 7487, LineMetaDataContent::Subway, Color{0x0000ff} }, // 1 OSM: 7734077 WD: Q28604 53.85, 27.47 x 53.95, 27.69
    { 16, 7508, 7487, LineMetaDataContent::Subway, Color{0xff0000} }, // 2 OSM: 7734078 WD: Q2638932 53.86, 27.43 x 53.91, 27.67
    { 16, NoLogo, 7531, LineMetaDataContent::Subway, Color{0x0000ff} }, // 2 OSM: 7734092 WD: Q12295702 42.65, 23.26 x 42.74, 23.42
    { 55, NoLogo, 7531, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 7734093 WD: Q20020737 42.63, 23.26 x 42.74, 23.38
    { 2571, NoLogo, 7552, LineMetaDataContent::Subway, Color{0xdf096f} }, // Vermelha OSM: 7734163 WD: Q163215 38.73, -9.154 x 38.78, -9.1
    { 2580, NoLogo, 7552, LineMetaDataContent::Subway, Color{0xf4bc18} }, // Amarela OSM: 7734164 WD: Q1826607 38.71, -9.173 x 38.79, -9.145
    { 2588, NoLogo, 7552, LineMetaDataContent::Subway, Color{0x5e82c4} }, // Azul OSM: 7734165 WD: Q1826609 38.71, -9.224 x 38.76, -9.122
    { 2557, NoLogo, 7552, LineMetaDataContent::Subway, Color{0x2f9b9c} }, // Verde OSM: 7734166 WD: Q1826613 38.71, -9.167 x 38.76, -9.133
    { 2593, 7582, 7582, LineMetaDataContent::Subway, Color{0xff6600} }, // Subway OSM: 7734173 WD: Q506290 55.85, -4.312 x 55.88, -4.253
    { 55, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 7734180 WD: Q219374 48.48, 34.93 x 48.48, 35.02
    { 481, NoLogo, 7025, LineMetaDataContent::Subway, Color{0x008000} }, // N OSM: 7734239 WD: Q1039166 33.55, 130.3 x 33.59, 130.4
    { 279, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xcc0000} }, // Red OSM: 7734262 WD: Q1369034 24.98, 55.09 x 25.27, 55.39
    { 469, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x00cc00} }, // Green OSM: 7734263 WD: Q1544621 25.22, 55.29 x 25.28, 55.4
    { 35, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xffc0cb} }, // S OSM: 7734268 WD: Q16240707 21.33, 39.87 x 21.42, 39.98
    { 55, 7601, 7625, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 7734272 WD: Q1473986 43.23, 76.87 x 43.27, 76.95
    { 16, NoLogo, 7647, LineMetaDataContent::Subway, Color{0x008000} }, // 2 OSM: 7734279 WD: Q712790 39.03, 125.7 x 39.07, 125.8
    { 55, NoLogo, 7647, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 7734280 WD: Q711112 39.01, 125.7 x 39.07, 125.8
    { 55, NoLogo, 7138, LineMetaDataContent::Subway, Color{0xff0f04} }, // 1 OSM: 7735256 WD: Q20110118 35.52, 51.37 x 35.8, 51.44
    { 6, NoLogo, 7138, LineMetaDataContent::RapidTransit, Color{0x008033} }, // 5 OSM: 7735262 WD: Q20110122 35.72, 50.93 x 35.83, 51.33
    { 55, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x4caf50} }, // 1 OSM: 7740660 WD: Q19856263 26.5, 106.6 x 26.66, 106.7
    { 2600, 7679, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7b4339} }, // ODEA OSM: 7747967 WD: Q93386 48.88, 2.345 x 48.94, 2.358
    { 2605, 7679, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7b4339} }, // ADEO OSM: 7747968 WD: Q93386 48.88, 2.345 x 48.94, 2.358
    { 2610, 7679, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7b4339} }, // VOBA OSM: 7747969 WD: Q93386 48.88, 2.345 x 48.94, 2.358
    { 2615, 7679, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7b4339} }, // AVOL OSM: 7747970 WD: Q93386 48.88, 2.345 x 48.94, 2.358
    { 2620, 7679, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7b4339} }, // APOR OSM: 7747972 WD: Q93386 48.88, 2.345 x 48.94, 2.358
    { 190, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x64318f} }, // T1 OSM: 7758458 WD: Q50319281 49.61, 6.119 x 49.64, 6.176
    { 59, NoLogo, 7138, LineMetaDataContent::Subway, Color{0x00aad4} }, // 3 OSM: 7770934 WD: Q20110120 35.63, 51.34 x 35.8, 51.52
    { 2625, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00afad} }, // B-L OSM: 7772561 51.46, -0.08835 x 51.51, -0.009433
    { 2629, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00afad} }, // B-WA OSM: 7772562 51.49, -0.08835 x 51.51, 0.07706
    { 2634, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00afad} }, // S-L OSM: 7772563 51.46, -0.02287 x 51.54, -0.004134
    { 2638, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00afad} }, // TG-B OSM: 7772565 51.51, -0.07453 x 51.51, 0.07181
    { 2643, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00afad} }, // SI-WA OSM: 7772566 51.49, -0.01336 x 51.55, 0.07706
    { 333, NoLogo, 3943, LineMetaDataContent::Subway, Color{0xbc1725} }, // M3 OSM: 7772846 WD: Q2735258 44.4, 25.98 x 44.44, 26.21
    { 260, NoLogo, 3943, LineMetaDataContent::Subway, Color{0xffff00} }, // M1 OSM: 7772847 WD: Q2056949 44.41, 26.04 x 44.45, 26.2
    { 69, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xb56631} }, // 21 OSM: 7779520 59.34, 18.1 x 59.36, 18.23
    { 362, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x008000} }, // L1 OSM: 7781389 WD: Q2668472 37.33, -6.052 x 37.38, -5.934
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0000ff} }, // 2 OSM: 7781442 WD: Q5986162 36.68, -4.458 x 36.71, -4.432
    { 55, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 7781445 WD: Q5392889 36.71, -4.496 x 36.72, -4.432
    { 330, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe93324} }, // M2 OSM: 7781535 WD: Q11180785 39.58, 2.654 x 39.63, 2.725
    { 260, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf1b03e} }, // M1 OSM: 7781536 WD: Q5985887 39.58, 2.648 x 39.63, 2.673
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x008000} }, // 2 OSM: 7786077 WD: Q2210273 41.72, 44.72 x 41.73, 44.8
    { 55, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 7786078 WD: Q340562 41.68, 44.78 x 41.79, 44.87
    { 39, 7702, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffff00} }, // E OSM: 7786518 WD: Q1714062 50.4, 30.4 x 50.5, 30.64
    { 16, 7732, 7752, LineMetaDataContent::Subway, Color{0xed1d24} }, // 2 OSM: 7786752 WD: Q3238802 50.62, 2.974 x 50.74, 3.181
    { 55, 7778, 7752, LineMetaDataContent::Subway, Color{0xffd400} }, // 1 OSM: 7786754 WD: Q3238658 50.61, 3.036 x 50.64, 3.143
    { 2649, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x90ee90} }, // 2B OSM: 7792472 WD: Q213271 40.38, 49.85 x 40.38, 49.87
    { 55, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 7792473 WD: Q3832654 40.37, 49.83 x 40.42, 49.95
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x008000} }, // 2 OSM: 7792474 WD: Q3832656 40.37, 49.8 x 40.43, 49.95
    { 59, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x800080} }, // 3 OSM: 7792475 WD: Q25547220 40.41, 49.79 x 40.42, 49.81
    { 55, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x007448} }, // 1 OSM: 7792528 WD: Q200310 36.32, 127.3 x 36.39, 127.5
    { 55, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x009088} }, // 1 OSM: 7792534 WD: Q626996 35.11, 126.8 x 35.16, 126.9
    { 1657, NoLogo, 161, LineMetaDataContent::RapidTransit, Color{0xf58220} }, // S19 OSM: 7800298 WD: Q25352054 47.37, 8.227 x 47.6, 8.787
    { 2652, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffd503} }, // U29 OSM: 7801954 48.77, 9.122 x 48.78, 9.182
    { 2656, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x69be51} }, // U34 OSM: 7801962 48.76, 9.143 x 48.78, 9.178
    { 2660, NoLogo, 161, LineMetaDataContent::RapidTransit, Color{0xf17f1a} }, // S 9 OSM: 7805411 WD: Q63217750 51.45, 11.98 x 51.52, 12.64
    { 358, 7798, 7821, LineMetaDataContent::Subway, Color{0x824100} }, // L4 OSM: 7827780 WD: Q1826677 40.42, -3.716 x 40.48, -3.635
    { 362, 7841, 7821, LineMetaDataContent::Subway, Color{0x67c0dd} }, // L1 OSM: 7831481 WD: Q1826675 40.36, -3.705 x 40.48, -3.591
    { 19, NoLogo, 7138, LineMetaDataContent::Subway, Color{0x73b65a} }, // 8 OSM: 7832314 WD: Q20110125 35.4, 51.15 x 35.56, 51.38
    { 16, NoLogo, 7138, LineMetaDataContent::Subway, Color{0x003380} }, // 2 OSM: 7832325 WD: Q20110119 35.69, 51.33 x 35.74, 51.55
    { 1776, NoLogo, 7821, LineMetaDataContent::Subway, Color{0x015396} }, // L10 OSM: 7834660 WD: Q1760090 40.34, -3.813 x 40.56, -3.611
    { 1498, NoLogo, 7864, LineMetaDataContent::Subway, Color{0x7fffd4} }, // I OSM: 7834960 WD: Q55810159 9.959, 76.28 x 10.11, 76.35
    { 1217, 7885, 7821, LineMetaDataContent::Subway, Color{0xff0080} }, // L8 OSM: 7837169 WD: Q1475527 40.44, -3.692 x 40.49, -3.572
    { 517, 7908, 7821, LineMetaDataContent::Subway, Color{0x9c3293} }, // L9 OSM: 7837206 WD: Q1759707 40.3, -3.721 x 40.5, -3.447
    { 2664, 7931, NoLogo, LineMetaDataContent::Subway, Color{0x996633} }, // Z OSM: 7837591 WD: Q126484 40.68, -74.01 x 40.72, -73.8
    { 1205, 7957, 7821, LineMetaDataContent::Subway, Color{0x96bf0d} }, // L5 OSM: 7838614 WD: Q1568028 40.38, -3.769 x 40.46, -3.588
    { 260, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xffa500} }, // M1 OSM: 7838818 36.98, 35.26 x 37.05, 35.34
    { 370, 7980, 7821, LineMetaDataContent::Subway, Color{0xffdf00} }, // L3 OSM: 7838838 WD: Q1826673 40.34, -3.719 x 40.43, -3.693
    { 366, 8003, 7821, LineMetaDataContent::Subway, Color{0xfb0f0c} }, // L2 OSM: 7838963 WD: Q1826679 40.42, -3.71 x 40.45, -3.602
    { 1213, 8026, 7821, LineMetaDataContent::Subway, Color{0xed7b24} }, // L7 OSM: 7840623 WD: Q1826683 40.42, -3.727 x 40.5, -3.524
    { 317, 8049, 7821, LineMetaDataContent::Subway, Color{0xffffff} }, // R OSM: 7840747 WD: Q1496137 40.42, -3.72 x 40.42, -3.71
    { 1352, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xe542de} }, // Purple OSM: 7841332 WD: Q7261433 12.95, 77.53 x 12.99, 77.66
    { 2210, 8071, 7821, LineMetaDataContent::Subway, Color{0xa49a00} }, // L12 OSM: 7841412 WD: Q1558864 40.28, -3.876 x 40.35, -3.71
    { 55, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 7841834 WD: Q11085985 31.44, 120.3 x 31.68, 120.3
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x008000} }, // 2 OSM: 7841837 WD: Q11085986 31.55, 120.2 x 31.61, 120.5
    { 55, NoLogo, 8095, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 7841839 WD: Q30326155 38.04, 114.4 x 38.16, 114.6
    { 59, NoLogo, 8095, LineMetaDataContent::Subway, Color{0x0000ff} }, // 3 OSM: 7841854 WD: Q30326157 38.01, 114.4 x 38.08, 114.5
    { 55, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x00b04f} }, // 1 OSM: 7841881 WD: Q17498765 22.82, 108.2 x 22.84, 108.4
    { 1209, 8118, 7821, LineMetaDataContent::Subway, Color{0x939393} }, // L6 OSM: 7842094 WD: Q514227 40.39, -3.745 x 40.45, -3.669
    { 1780, 8141, 7821, LineMetaDataContent::Subway, Color{0x006400} }, // L11 OSM: 7842127 WD: Q608251 40.36, -3.778 x 40.39, -3.716
    { 469, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x009933} }, // Green OSM: 7842288 WD: Q17054000 12.89, 77.5 x 13.05, 77.58
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xc32a05} }, // 2 OSM: 7844345 WD: Q11149384 36.06, 120.3 x 36.17, 120.5
    { 16, NoLogo, 8165, LineMetaDataContent::Subway, Color{0x53b848} }, // 2 OSM: 7845614 WD: Q20647027 12.99, 80.19 x 13.09, 80.27
    { 164, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xc09c83} }, // 17 OSM: 7845847 WD: Q6553108 31.1, 121 x 31.2, 121.3
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x18be00} }, // 2 OSM: 7845969 WD: Q200332 35.83, 128.4 x 35.87, 128.8
    { 55, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 7845971 WD: Q200331 35.8, 128.5 x 35.89, 128.7
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xffff00} }, // 2 OSM: 7846276 WD: Q15908164 34.66, 113.6 x 34.88, 113.7
    { 2666, NoLogo, 8188, LineMetaDataContent::RapidTransit, Color{0x4682b4} }, // ML1 OSM: 7849381 WD: Q2058921 40.48, -3.669 x 40.51, -3.651
    { 2670, NoLogo, 8188, LineMetaDataContent::RapidTransit, Color{0x660066} }, // ML2 OSM: 7853073 WD: Q3832710 40.4, -3.812 x 40.45, -3.775
    { 369, NoLogo, 8188, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // ML3 OSM: 7853483 WD: Q3832709 40.39, -3.905 x 40.41, -3.775
    { 2674, 8214, NoLogo, LineMetaDataContent::Subway, Color{0x6fa0ce} }, // I1 OSM: 7854149 WD: Q487733 37.38, 126.6 x 37.57, 126.7
    { 59, 8239, 3643, LineMetaDataContent::Tramway, Color{0xb5ba05} }, // 3 OSM: 7857250 WD: Q1888831 50.81, 4.336 x 50.9, 4.377
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x02406f} }, // 2 OSM: 7857258 WD: Q10318650 -12.98, -38.48 x -12.9, -38.34
    { 2677, 5575, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa6c82b} }, // R2Nord OSM: 7867878 WD: Q1880046 41.3, 2.052 x 41.77, 2.673
    { 1586, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xba55d3} }, // R7 OSM: 7867903 WD: Q1647981 41.43, 2.115 x 41.51, 2.189
    { 2684, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // B1 OSM: 7868621 40.19, 28.95 x 40.26, 29.12
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // 2 OSM: 7869228 WD: Q5934457 34.14, 108.9 x 34.37, 108.9
    { 55, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0000ff} }, // 1 OSM: 7869253 WD: Q14917524 34.27, 108.7 x 34.32, 109.1
    { 59, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff00ff} }, // 3 OSM: 7869255 WD: Q15927288 34.22, 108.8 x 34.41, 109.1
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xd9001c} }, // 2 OSM: 7869334 WD: Q1808272 -8.111, -35.02 x -8.069, -34.89
    { 55, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xe77405} }, // 1 OSM: 7869352 WD: Q1808272 -8.092, -35 x -8.024, -34.89
    { 2048, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x1a5ba3} }, // Sul OSM: 7869374 WD: Q10329288 -8.168, -34.93 x -8.069, -34.88
    { 2687, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x000000} }, // B2 OSM: 7869622 40.19, 28.87 x 40.22, 29.21
    { 55, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 7871046 WD: Q15303225 34.75, 113.5 x 34.83, 113.8
    { 119, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xb93ff5} }, // 9 OSM: 7871541 WD: Q28441548 34.53, 113.7 x 34.66, 113.9
    { 2690, 8260, NoLogo, LineMetaDataContent::RapidTransit, Color{0x8fbe00} }, // C-10 OSM: 7871793 WD: Q583732 40.4, -4.009 x 40.63, -3.662
    { 495, 8274, NoLogo, LineMetaDataContent::RapidTransit, Color{0x009ad5} }, // C-1 OSM: 7871905 WD: Q3832674 40.4, -3.719 x 40.49, -3.594
    { 2695, 8293, NoLogo, LineMetaDataContent::RapidTransit, Color{0xde0118} }, // C-7 OSM: 7872150 WD: Q8879938 40.38, -3.874 x 40.51, -3.365
    { 1665, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // Red Line OSM: 7874288 WD: Q152039 42.21, -71.14 x 42.4, -71
    { 2699, 8305, NoLogo, LineMetaDataContent::Subway, Color{0xff8000} }, // Orange Line OSM: 7874312 WD: Q152029 42.3, -71.12 x 42.44, -71.06
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 1 OSM: 7874579 52.26, 104.3 x 52.29, 104.3
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x00afec} }, // 2 OSM: 7875250 WD: Q15919822 28.15, 112.9 x 28.21, 113.1
    { 55, 8334, NoLogo, LineMetaDataContent::Subway, Color{0xe60012} }, // 1 OSM: 7875257 WD: Q15911087 28.07, 113 x 28.27, 113
    { 2711, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 4a OSM: 7875272 52.28, 104.3 x 52.29, 104.4
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 4 OSM: 7875274 52.28, 104.3 x 52.29, 104.4
    { 9, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7d4697} }, // 4 OSM: 7875301 WD: Q6553125 43.79, 125.3 x 43.91, 125.4
    { 59, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x009943} }, // 3 OSM: 7875360 WD: Q6123656 43.77, 125.3 x 43.91, 125.4
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x4bc7df} }, // 2 OSM: 7875922 52.27, 104.3 x 52.29, 104.3
    { 219, 8364, NoLogo, LineMetaDataContent::Subway, Color{0x008000} }, // A OSM: 7877753 WD: Q770771 39.91, 32.81 x 39.93, 32.88
    { 260, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // M1 OSM: 7877773 WD: Q21526526 39.92, 32.73 x 39.97, 32.86
    { 330, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xffff00} }, // M2 OSM: 7877891 WD: Q21526527 39.89, 32.69 x 39.92, 32.85
    { 1281, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xffa500} }, // O OSM: 7879290 WD: Q7099668 22.62, 120.3 x 22.63, 120.4
    { 317, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // R OSM: 7879291 WD: Q7304504 22.56, 120.3 x 22.78, 120.4
    { 59, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xfe5b10} }, // 3 OSM: 7879839 WD: Q20393 37.48, 126.7 x 37.68, 127.1
    { 6, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x8b50a4} }, // 5 OSM: 7879871 WD: Q92530 37.49, 126.8 x 37.58, 127.2
    { 59, NoLogo, 8380, LineMetaDataContent::Subway, Color{0x006dbb} }, // 3 OSM: 7883242 WD: Q15907883 36.05, 120.3 x 36.17, 120.4
    { 119, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xaa9872} }, // 9 OSM: 7883317 WD: Q17503 37.5, 126.8 x 37.58, 127.1
    { 16, 8411, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // 2 OSM: 7883944 WD: Q10946021 29.81, 121.5 x 29.95, 121.7
    { 55, 8432, 1255, LineMetaDataContent::Subway, Color{0xffff00} }, // 1 OSM: 7884489 WD: Q54369 43.65, -79.53 x 43.8, -79.38
    { 55, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 7885089 WD: Q56277837 40.59, 22.93 x 40.65, 22.97
    { 16, 8481, 1255, LineMetaDataContent::Subway, Color{0x008000} }, // 2 OSM: 7885287 WD: Q54371 43.64, -79.54 x 43.73, -79.26
    { 59, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x009651} }, // 3 OSM: 7885547 WD: Q10906683 31.87, 118.7 x 32.17, 118.8
    { 2714, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x77278b} }, // WCE OSM: 7887557 49.13, -123.1 x 49.29, -122.3
    { 2718, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x000000} }, // Conexão Metrô-Aeroporto OSM: 7889062 WD: Q23891467 -29.99, -51.18 x -29.99, -51.18
    { 55, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x008000} }, // 1 OSM: 7889178 WD: Q45668 31.28, 120.5 x 31.33, 120.8
    { 2744, 8520, 8520, LineMetaDataContent::Subway, Color{0x808080} }, // RMGL OSM: 7890003 WD: Q7294170 28.42, 77.09 x 28.5, 77.11
    { 55, 8534, NoLogo, LineMetaDataContent::Subway, Color{0xfec04f} }, // 1 OSM: 7890223 WD: Q5985916 25.68, -100.4 x 25.76, -100.2
    { 16, 8552, NoLogo, LineMetaDataContent::Subway, Color{0x6bc069} }, // 2 OSM: 7890224 WD: Q2842186 25.67, -100.3 x 25.77, -100.3
    { 16, NoLogo, 8570, LineMetaDataContent::Subway, Color{0x0066a1} }, // 2 OSM: 7890240 WD: Q6379343 38.9, 121.5 x 38.96, 121.7
    { 35, 1783, NoLogo, LineMetaDataContent::Subway, Color{0x808183} }, // S OSM: 7893704 WD: Q126772 40.58, -73.84 x 40.61, -73.81
    { 35, 1783, NoLogo, LineMetaDataContent::Subway, Color{0x808183} }, // S OSM: 7894362 WD: Q126725 40.66, -73.96 x 40.68, -73.96
    { 55, NoLogo, 8603, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 7894481 WD: Q5934658 41.76, 123.2 x 41.81, 123.5
    { 16, NoLogo, 8603, LineMetaDataContent::Subway, Color{0xffff00} }, // 2 OSM: 7894597 WD: Q5933526 41.7, 123.4 x 41.96, 123.5
    { 55, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 7895188 WD: Q15941872 25.99, 119.3 x 26.15, 119.4
    { 58, NoLogo, 2223, LineMetaDataContent::Subway, Color{0x918c10} }, // 13 OSM: 7895357 WD: Q6553065 23.08, 113.4 x 23.14, 113.6
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0070ff} }, // 2 OSM: 7898299 WD: Q56277844 40.57, 22.93 x 40.65, 22.97
    { 59, NoLogo, 8570, LineMetaDataContent::Subway, Color{0x008000} }, // 3 OSM: 7908058 WD: Q5976456 38.92, 121.6 x 39.15, 122
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0000ff} }, // 2 OSM: 7909740 WD: Q11087464 25.03, 102.7 x 25.12, 102.8
    { 55, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xdb372b} }, // 1 OSM: 7909748 WD: Q11087462 24.82, 102.7 x 25.03, 102.9
    { 61, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x4bbbb4} }, // S1 OSM: 7913272 WD: Q10946118 31.72, 118.8 x 31.97, 118.9
    { 153, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xda60cd} }, // S3 OSM: 7913273 WD: Q10945835 31.91, 118.5 x 31.99, 118.8
    { 55, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x00ab39} }, // 1 OSM: 7913936 WD: Q842103 22.53, 113.8 x 22.65, 114.1
    { 219, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x3681b7} }, // A OSM: 7919001 WD: Q487643 37.44, 126.4 x 37.6, 127
    { 19, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xf51361} }, // 8 OSM: 7919019 WD: Q45086 37.43, 127.1 x 37.55, 127.2
    { 27, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x9e4510} }, // 6 OSM: 7919154 WD: Q92549 37.53, 126.9 x 37.62, 127.1
    { 296, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x00a651} }, // M OSM: 7919553 WD: Q805751 39.29, -76.78 x 39.41, -76.59
    { 2622, 8639, 6746, LineMetaDataContent::Subway, Color{0xe89038} }, // OR OSM: 7919601 WD: Q4715683 38.88, -77.28 x 38.95, -76.87
    { 2749, 8656, 6746, LineMetaDataContent::Subway, Color{0xe94333} }, // RD OSM: 7919630 WD: Q2193330 38.89, -77.17 x 39.12, -76.99
    { 2752, 8670, 6746, LineMetaDataContent::Subway, Color{0xc0c0c0} }, // SI OSM: 7919737 WD: Q4711838 38.88, -77.34 x 38.95, -76.84
    { 2755, 8687, 6746, LineMetaDataContent::Subway, Color{0x0000ff} }, // BL OSM: 7919758 WD: Q2602185 38.77, -77.17 x 38.9, -76.84
    { 316, 8702, 6746, LineMetaDataContent::Subway, Color{0x008000} }, // GR OSM: 7919786 WD: Q4715207 38.83, -77.03 x 39.01, -76.91
    { 42, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x54640d} }, // 7 OSM: 7922930 WD: Q22910 37.48, 126.7 x 37.7, 127.1
    { 469, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x62bb46} }, // Green OSM: 7924527 WD: Q55734262 25.68, -80.32 x 25.85, -80.2
    { 1246, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xf78f1e} }, // Orange OSM: 7924528 WD: Q55734269 25.68, -80.32 x 25.81, -80.2
    { 1099, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009832} }, // D OSM: 7925628 48.57, 7.691 x 48.59, 7.816
    { 214, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf68712} }, // C OSM: 7925656 48.55, 7.735 x 48.59, 7.773
    { 27, 8718, 6201, LineMetaDataContent::Subway, Color{0x0078ad} }, // 6 OSM: 7927182 WD: Q668977 50.83, 4.321 x 50.9, 4.37
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff7000} }, // 2 OSM: 7927236 WD: Q5017773 29.98, 31.2 x 30.12, 31.25
    { 55, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 7927442 WD: Q6515333 10.48, -66.96 x 10.52, -66.8
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xafc805} }, // 2 OSM: 7927568 WD: Q5986160 10.42, -67.01 x 10.51, -66.87
    { 59, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0000ff} }, // 3 OSM: 7927573 WD: Q21346332 10.43, -66.94 x 10.5, -66.88
    { 2758, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // L1B OSM: 7928119 37.99, -1.187 x 38.01, -1.161
    { 55, NoLogo, 8739, LineMetaDataContent::Subway, Color{0xe86495} }, // 1 OSM: 7935038 WD: Q2295084 19.4, -99.2 x 19.43, -99.07
    { 1366, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // 803 OSM: 7935053 33.89, -118.4 x 33.93, -118.1
    { 2762, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffd700} }, // 804 OSM: 7935245 34.03, -118.2 x 34.15, -117.9
    { 2766, 8761, 8786, LineMetaDataContent::Subway, Color{0x800080} }, // 805 OSM: 7935318 WD: Q3916689 34.05, -118.3 x 34.06, -118.2
    { 9, NoLogo, 8739, LineMetaDataContent::Subway, Color{0x80ffff} }, // 4 OSM: 7935352 WD: Q2837181 19.4, -99.12 x 19.49, -99.1
    { 6, NoLogo, 8739, LineMetaDataContent::Subway, Color{0xffff11} }, // 5 OSM: 7935366 WD: Q1152238 19.41, -99.15 x 19.5, -99.07
    { 15, NoLogo, 8739, LineMetaDataContent::Subway, Color{0xb69764} }, // 12 OSM: 7935368 WD: Q5985548 19.28, -99.2 x 19.38, -99.01
    { 42, NoLogo, 8739, LineMetaDataContent::Subway, Color{0xff8000} }, // 7 OSM: 7935375 WD: Q929645 19.36, -99.2 x 19.51, -99.18
    { 219, NoLogo, 8739, LineMetaDataContent::Subway, Color{0xa3277d} }, // A OSM: 7935382 WD: Q3239049 19.35, -99.08 x 19.42, -98.96
    { 19, NoLogo, 8739, LineMetaDataContent::Subway, Color{0x30c090} }, // 8 OSM: 7935426 WD: Q1149545 19.34, -99.14 x 19.45, -99.05
    { 181, NoLogo, 8739, LineMetaDataContent::Subway, Color{0x408080} }, // B OSM: 7935433 WD: Q3239062 19.43, -99.16 x 19.53, -99.03
    { 16, NoLogo, 8739, LineMetaDataContent::Subway, Color{0x0080ff} }, // 2 OSM: 7935439 WD: Q1152993 19.34, -99.22 x 19.46, -99.13
    { 119, NoLogo, 8739, LineMetaDataContent::Subway, Color{0x804000} }, // 9 OSM: 7935444 WD: Q3239046 19.4, -99.19 x 19.42, -99.06
    { 59, NoLogo, 8739, LineMetaDataContent::Subway, Color{0xae9d27} }, // 3 OSM: 7935449 WD: Q945935 19.32, -99.18 x 19.5, -99.12
    { 27, NoLogo, 8739, LineMetaDataContent::Subway, Color{0xe00050} }, // 6 OSM: 7935454 WD: Q3238990 19.48, -99.2 x 19.5, -99.1
    { 2770, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xdb5450} }, // PATCO OSM: 7939445 WD: Q2043730 39.83, -75.17 x 39.96, -75
    { 1870, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x233e99} }, // WTR OSM: 7940934 WD: Q7986701 39.95, -75.18 x 40.26, -74.82
    { 2336, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xef3941} }, // NWK–WTC OSM: 7943869 WD: Q2673356 40.71, -74.16 x 40.74, -74.01
    { 2776, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x009e58} }, // HOB–WTC OSM: 7943874 WD: Q2789573 40.71, -74.04 x 40.74, -74.01
    { 2786, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0082c6} }, // HOB–33 OSM: 7943885 WD: Q2319374 40.73, -74.03 x 40.75, -73.99
    { 2795, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xfdb827} }, // JSQ–33 OSM: 7943962 WD: Q4993433 40.72, -74.06 x 40.75, -73.99
    { 55, NoLogo, 5021, LineMetaDataContent::Subway, Color{0xe77405} }, // 1 OSM: 7944061 WD: Q2333617 -22.98, -43.24 x -22.9, -43.17
    { 55, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 7948593 WD: Q10921992 45.6, 126.6 x 45.79, 126.7
    { 59, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xffa500} }, // 3 OSM: 7949019 WD: Q10921994 45.69, 126.6 x 45.7, 126.6
    { 55, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 7949047 WD: Q10916959 31.69, 117.3 x 31.92, 117.3
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x3366ff} }, // 2 OSM: 7949335 WD: Q10916960 31.85, 117.1 x 31.87, 117.4
    { 55, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xe50011} }, // 1 OSM: 7949339 WD: Q15913092 43.79, 125.3 x 43.95, 125.3
    { 2804, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xf58220} }, // BSL OSM: 7950670 WD: Q837022 39.91, -75.17 x 40.04, -75.14
    { 55, NoLogo, 8570, LineMetaDataContent::Subway, Color{0x008000} }, // 1 OSM: 7951024 WD: Q6379309 38.84, 121.5 x 39.04, 121.6
    { 2808, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0066ff} }, // MFL OSM: 7953598 WD: Q823251 39.95, -75.26 x 40.02, -75.08
    { 2812, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x84388a} }, // NHSL OSM: 7953621 39.96, -75.35 x 40.11, -75.26
    { 15, NoLogo, 8570, LineMetaDataContent::Subway, Color{0x5f259f} }, // 12 OSM: 7957874 WD: Q10938157 38.8, 121.1 x 38.86, 121.5
    { 2817, 8798, NoLogo, LineMetaDataContent::Subway, Color{0x38a800} }, // Μ1 OSM: 7963514 WD: Q6553095 37.94, 23.64 x 38.07, 23.81
    { 2821, 8822, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // Γ2 OSM: 7963569 WD: Q9295813 37.89, 23.69 x 38.02, 23.75
    { 317, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x2d3087} }, // R OSM: 7963671 WD: Q225095 35.61, 139.7 x 35.65, 139.8
    { 55, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 7963913 WD: Q320337 40.14, 44.47 x 40.2, 44.52
    { 2825, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x98cd37} }, // ML4 OSM: 7968999 40.22, -3.773 x 40.25, -3.749
    { 2829, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x006400} }, // Tranvía OSM: 7981323 37.77, -3.79 x 37.81, -3.778
    { 2838, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0354a6} }, // DTL OSM: 7981644 WD: Q1663943 1.278, 103.7 x 1.417, 104
    { 2842, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x9016b2} }, // NEL OSM: 7981649 WD: Q1725116 1.265, 103.8 x 1.416, 103.9
    { 2846, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff9a00} }, // CCL OSM: 7981685 WD: Q2154003 1.265, 103.8 x 1.353, 103.9
    { 2850, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x009530} }, // EWL OSM: 7981689 WD: Q1895425 1.276, 103.6 x 1.376, 104
    { 333, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x1e90ff} }, // M3 OSM: 7981707 WD: Q21526528 39.97, 32.56 x 39.99, 32.73
    { 8, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x800080} }, // M4 OSM: 7981756 WD: Q31193144 39.94, 32.84 x 40, 32.88
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0000ff} }, // 2 OSM: 7981873 WD: Q55105894 38.39, 27.07 x 38.47, 27.23
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xed1c24} }, // 2 OSM: 7986215 WD: Q11103955 22.86, 113.7 x 23.09, 113.9
    { 2854, NoLogo, 8846, LineMetaDataContent::Subway, Color{0x0000ff} }, // Pink Line OSM: 7989308 WD: Q17053988 26.88, 75.75 x 26.93, 75.83
    { 2864, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x246b5b} }, // BTS Silom OSM: 7989387 WD: Q2634702 13.71, 100.5 x 13.75, 100.5
    { 55, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 7992938 WD: Q133748 30.17, 120.2 x 30.41, 120.4
    { 2874, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffa000} }, // U AVO OSM: 7993108 40.64, -8.654 x 41.15, -8.564
    { 9, 8868, 3643, LineMetaDataContent::Tramway, Color{0xf25482} }, // 4 OSM: 7999217 WD: Q2527775 50.79, 4.318 x 50.86, 4.363
    { 226, 8889, 3643, LineMetaDataContent::Tramway, Color{0x991f36} }, // 25 OSM: 7999338 WD: Q3238750 50.8, 4.358 x 50.87, 4.408
    { 209, 8911, 3643, LineMetaDataContent::Tramway, Color{0xe3ba12} }, // 55 OSM: 7999374 WD: Q2236365 50.86, 4.358 x 50.88, 4.416
    { 595, 8933, 3643, LineMetaDataContent::Tramway, Color{0x9ebfe3} }, // 82 OSM: 7999733 WD: Q2534011 50.78, 4.29 x 50.87, 4.341
    { 59, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffcc00} }, // 3 OSM: 8000255 WD: Q13422345 14.54, 121 x 14.65, 121.1
    { 55, 8955, 8955, LineMetaDataContent::RapidTransit, Color{0x008000} }, // 1 OSM: 8000262 WD: Q4165607 14.53, 121 x 14.66, 121
    { 16, NoLogo, 8955, LineMetaDataContent::Subway, Color{0x800080} }, // 2 OSM: 8000265 WD: Q4165317 14.6, 121 x 14.63, 121.1
    { 2880, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfe8e10} }, // AG OSM: 8000298 WD: Q474391 3.12, 101.7 x 3.188, 101.8
    { 119, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x008000} }, // 9 OSM: 8000326 WD: Q6717618 2.981, 101.6 x 3.207, 101.8
    { 2883, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x721422} }, // SP OSM: 8000405 WD: Q474391 2.994, 101.6 x 3.188, 101.7
    { 229, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe0115f} }, // KJ OSM: 8000461 2.995, 101.6 x 3.233, 101.7
    { 378, NoLogo, 8968, LineMetaDataContent::Subway, Color{0x0000ff} }, // H OSM: 8000565 WD: Q981822 43.02, 141.4 x 43.11, 141.4
    { 543, NoLogo, 8968, LineMetaDataContent::Subway, Color{0xff8c00} }, // T OSM: 8000572 WD: Q981826 43.03, 141.3 x 43.09, 141.5
    { 481, NoLogo, 8968, LineMetaDataContent::Subway, Color{0x008800} }, // N OSM: 8000575 WD: Q843793 42.99, 141.3 x 43.11, 141.4
    { 1591, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0377ae} }, // R6 OSM: 8005936 48.62, 21.19 x 48.71, 21.24
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x55bace} }, // 3 OSM: 8013591 48.68, 21.26 x 48.72, 21.3
    { 42, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x5cbf14} }, // 7 OSM: 8013592 48.68, 21.24 x 48.73, 21.3
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x7477b0} }, // 4 OSM: 8013593 48.68, 21.24 x 48.74, 21.27
    { 119, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf5d907} }, // 9 OSM: 8013594 48.68, 21.23 x 48.74, 21.3
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xd2005c} }, // 2 OSM: 8013595 48.72, 21.24 x 48.74, 21.27
    { 296, 8980, 9020, LineMetaDataContent::Subway, Color{0xf62e36} }, // M OSM: 8015940 WD: Q1147028 35.67, 139.6 x 35.73, 139.8
    { 35, 9041, NoLogo, LineMetaDataContent::Subway, Color{0xffb300} }, // S OSM: 8016135 WD: Q16948 37.36, 126.6 x 37.48, 126.7
    { 2886, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x11385b} }, // 金山(Jinshan) OSM: 8019734 WD: Q3338133 30.73, 121.3 x 31.16, 121.4
    { 219, 9067, NoLogo, LineMetaDataContent::Subway, Color{0xe85298} }, // A OSM: 8019854 WD: Q720653 35.59, 139.7 x 35.71, 139.8
    { 35, 9096, NoLogo, LineMetaDataContent::Subway, Color{0x6cbb5a} }, // S OSM: 8019866 WD: Q1374502 35.65, 139.5 x 35.79, 139.9
    { 39, 9126, NoLogo, LineMetaDataContent::Subway, Color{0xb6007a} }, // E OSM: 8019893 WD: Q384862 35.65, 139.6 x 35.76, 139.8
    { 1498, 9152, NoLogo, LineMetaDataContent::Subway, Color{0x0079c2} }, // I OSM: 8019914 WD: Q1374506 35.63, 139.6 x 35.79, 139.8
    { 2902, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xafca36} }, // G44 OSM: 8021111 47.37, 18.87 x 47.5, 19.04
    { 214, 9178, 9020, LineMetaDataContent::Subway, Color{0x00bb85} }, // C OSM: 8026069 WD: Q1075089 35.66, 139.7 x 35.78, 139.8
    { 481, 9215, 9020, LineMetaDataContent::Subway, Color{0x00ac9b} }, // N OSM: 8026071 WD: Q520772 35.63, 139.7 x 35.78, 139.8
    { 201, 9252, 9020, LineMetaDataContent::Subway, Color{0xff9500} }, // G OSM: 8026077 WD: Q1073046 35.66, 139.7 x 35.71, 139.8
    { 493, 9287, 9020, LineMetaDataContent::Subway, Color{0xc1a470} }, // Y OSM: 8026115 WD: Q787305 35.64, 139.6 x 35.79, 139.8
    { 543, 9328, 9020, LineMetaDataContent::Subway, Color{0x009bbf} }, // T OSM: 8026124 WD: Q1147054 35.66, 139.7 x 35.71, 140
    { 378, 9364, 9020, LineMetaDataContent::Subway, Color{0xb5b5ac} }, // H OSM: 8026149 WD: Q1196223 35.64, 139.7 x 35.75, 139.8
    { 2664, 9400, 9020, LineMetaDataContent::Subway, Color{0x8f76d6} }, // Z OSM: 8026157 WD: Q1376030 35.66, 139.7 x 35.71, 139.8
    { 233, 9439, 9020, LineMetaDataContent::Subway, Color{0x9c5e31} }, // F OSM: 8026161 WD: Q1332908 35.66, 139.6 x 35.79, 139.7
    { 35, 9479, NoLogo, LineMetaDataContent::Subway, Color{0xffaadd} }, // S OSM: 8028801 WD: Q1073354 34.64, 135.5 x 34.69, 135.6
    { 296, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xdd0000} }, // M OSM: 8028805 34.56, 135.5 x 34.81, 135.5
    { 1498, 9519, NoLogo, LineMetaDataContent::Subway, Color{0xff9900} }, // I OSM: 8028826 WD: Q1066118 34.67, 135.5 x 34.76, 135.6
    { 432, 9559, NoLogo, LineMetaDataContent::Subway, Color{0x662211} }, // K OSM: 8028828 WD: Q1143250 34.64, 135.5 x 34.71, 135.5
    { 481, 9597, NoLogo, LineMetaDataContent::Subway, Color{0xaadd55} }, // N OSM: 8028846 WD: Q284828 34.67, 135.5 x 34.72, 135.6
    { 493, 9651, NoLogo, LineMetaDataContent::Subway, Color{0x0000ff} }, // Y OSM: 8028853 WD: Q1067748 34.61, 135.5 x 34.7, 135.5
    { 543, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x540a56} }, // T OSM: 8028879 WD: Q1142773 34.6, 135.5 x 34.75, 135.6
    { 432, 9690, 9715, LineMetaDataContent::Subway, Color{0x3cb371} }, // K OSM: 8030551 WD: Q762347 34.96, 135.8 x 35.06, 135.8
    { 543, 9734, 9715, LineMetaDataContent::Subway, Color{0xff4500} }, // T OSM: 8030553 WD: Q1143898 34.93, 135.7 x 35.01, 135.8
    { 35, 9756, 7202, LineMetaDataContent::Subway, Color{0xff0000} }, // S OSM: 8030762 WD: Q1132780 35.09, 136.9 x 35.17, 137
    { 378, 9801, 7202, LineMetaDataContent::Subway, Color{0xffffcc} }, // H OSM: 8030765 WD: Q1132799 35.14, 136.9 x 35.18, 137
    { 39, 9846, 7202, LineMetaDataContent::Subway, Color{0x8f76d6} }, // E OSM: 8030779 WD: Q1045061 35.09, 136.9 x 35.14, 136.9
    { 543, 9885, 7202, LineMetaDataContent::Subway, Color{0xadd8e6} }, // T OSM: 8030785 WD: Q1043806 35.12, 136.9 x 35.22, 137
    { 509, 9927, NoLogo, LineMetaDataContent::RapidTransit, Color{0x449ad5} }, // R1 OSM: 8030919 WD: Q2395239 41.36, 2.02 x 41.77, 2.769
    { 296, 9944, 7202, LineMetaDataContent::Subway, Color{0x8f76d6} }, // M OSM: 8031607 WD: Q906775 35.12, 136.9 x 35.2, 137
    { 466, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe9527d} }, // S9 OSM: 8033205 WD: Q2381339 41.35, 2.001 x 41.41, 2.149
    { 55, NoLogo, 9983, LineMetaDataContent::Subway, Color{0x008000} }, // 1 OSM: 8034179 WD: Q6427301 22.46, 88.34 x 22.64, 88.4
    { 55, NoLogo, 8165, LineMetaDataContent::Subway, Color{0x3281c4} }, // 1 OSM: 8037596 WD: Q19891160 12.98, 80.16 x 13.11, 80.29
    { 1632, NoLogo, 10006, LineMetaDataContent::Subway, Color{0x0000ff} }, // Blue Line OSM: 8037671 WD: Q1029921 28.55, 77.02 x 28.66, 77.38
    { 1689, NoLogo, 10006, LineMetaDataContent::Subway, Color{0x008000} }, // Green Line OSM: 8037672 WD: Q5602820 28.65, 76.91 x 28.7, 77.17
    { 2906, NoLogo, 10006, LineMetaDataContent::Subway, Color{0x800080} }, // Violet Line OSM: 8037706 WD: Q3634451 28.34, 77.21 x 28.67, 77.32
    { 2918, NoLogo, 10006, LineMetaDataContent::Subway, Color{0xffff00} }, // Yellow Line OSM: 8037713 WD: Q795156 28.46, 77.07 x 28.75, 77.23
    { 2930, NoLogo, 10006, LineMetaDataContent::Subway, Color{0xffa500} }, // AEx OSM: 8037716 WD: Q5253735 28.55, 77.06 x 28.64, 77.22
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xeb3d1a} }, // 2 OSM: 8040132 WD: Q21245979 22.72, 108.3 x 22.9, 108.4
    { 59, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xfe4998} }, // 3 OSM: 8040148 WD: Q11087465 24.99, 102.6 x 25.05, 102.8
    { 41, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x991f36} }, // S7 OSM: 8043820 WD: Q2316170 41.39, 2.032 x 41.49, 2.17
    { 2934, NoLogo, 10006, LineMetaDataContent::Subway, Color{0xff00ff} }, // Magenta Line OSM: 8051576 WD: Q19893471 28.54, 77.08 x 28.63, 77.34
    { 119, NoLogo, 10006, LineMetaDataContent::Subway, Color{0x808080} }, // 9 OSM: 8051593 WD: Q47100305 28.61, 77 x 28.62, 77.02
    { 22, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xabd02c} }, // 18 OSM: 8054951 50.05, 14.39 x 50.11, 14.44
    { 164, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xa7c9ae} }, // 17 OSM: 8055113 50, 14.4 x 50.13, 14.46
    { 54, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xdc008f} }, // 11 OSM: 8060662 50.05, 14.3 x 50.09, 14.54
    { 11, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x683064} }, // M5 OSM: 8061299 WD: Q1229371 41.01, 29.01 x 41.03, 29.19
    { 54, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x82c0c0} }, // 11 OSM: 8119161 55.75, 37.51 x 55.79, 37.59
    { 190, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0000ff} }, // T1 OSM: 8120923 WD: Q613580 10.34, -67.04 x 10.43, -67.01
    { 53, 5039, 161, LineMetaDataContent::RapidTransit, Color{0xb72841} }, // S11 OSM: 8149205 WD: Q459508 47.98, 12.85 x 48.04, 12.93
    { 153, 5039, 161, LineMetaDataContent::RapidTransit, Color{0x22b24c} }, // S3 OSM: 8149206 WD: Q459508 47.28, 12.79 x 47.84, 13.23
    { 50, 5039, 161, LineMetaDataContent::RapidTransit, Color{0x0072bc} }, // S2 OSM: 8149207 WD: Q459508 47.81, 12.97 x 47.97, 13.27
    { 61, 5039, 161, LineMetaDataContent::RapidTransit, Color{0xb72841} }, // S1 OSM: 8149208 WD: Q459508 47.81, 12.92 x 47.99, 13.05
    { 2947, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x999999} }, // 浦江(Pujiang) OSM: 8167022 31.03, 121.5 x 31.06, 121.5
    { 1946, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0377ae} }, // R4 OSM: 8196259 48.62, 21.19 x 48.73, 21.25
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xea7b08} }, // 6 OSM: 8196338 48.7, 21.23 x 48.73, 21.27
    { 1943, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0377ae} }, // R3 OSM: 8197830 48.62, 21.19 x 48.74, 21.25
    { 1586, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0377ae} }, // R7 OSM: 8197872 48.62, 21.19 x 48.73, 21.24
    { 524, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // T2 OSM: 8209896 WD: Q16655789 47.99, 0.1929 x 48.02, 0.2359
    { 190, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xeb001b} }, // T1 OSM: 8209897 WD: Q3239229 47.96, 0.152 x 48.02, 0.2304
    { 469, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x009933} }, // Green OSM: 8212097 WD: Q19960507 54.9, -1.711 x 55.04, -1.382
    { 2963, 10027, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // 802 OSM: 8219357 WD: Q2778331 34.05, -118.4 x 34.17, -118.2
    { 272, NoLogo, 4128, LineMetaDataContent::RapidTransit, Color{0xffe800} }, // Yellow OSM: 8237627 WD: Q54874971 38, -121.9 x 38.02, -121.8
    { 2854, NoLogo, 10006, LineMetaDataContent::Subway, Color{0xffc0cb} }, // Pink Line OSM: 8242438 WD: Q19891094 28.57, 77.12 x 28.72, 77.32
    { 59, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xbb8c00} }, // 3 OSM: 8247017 WD: Q86468 35.17, 129 x 35.21, 129.1
    { 9, NoLogo, 5617, LineMetaDataContent::Tramway, Color{0xfc751c} }, // 4 OSM: 8255319 WD: Q2735863 52.04, 4.245 x 52.08, 4.543
    { 59, NoLogo, 5617, LineMetaDataContent::Tramway, Color{0x703276} }, // 3 OSM: 8255320 WD: Q3056105 52.05, 4.228 x 52.08, 4.518
    { 55, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xf06a00} }, // 1 OSM: 8255698 WD: Q86356 35.05, 129 x 35.29, 129.1
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x81bf48} }, // 2 OSM: 8258658 WD: Q86467 35.13, 129 x 35.34, 129.2
    { 9, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x217dcb} }, // 4 OSM: 8258702 WD: Q86469 35.2, 129.1 x 35.24, 129.2
    { 47, NoLogo, 161, LineMetaDataContent::RapidTransit, Color{0x5e2d91} }, // S8 OSM: 8294822 WD: Q7388382 47.2, 8.519 x 47.5, 8.782
    { 41, NoLogo, 161, LineMetaDataContent::RapidTransit, Color{0xfebe10} }, // S7 OSM: 8294823 WD: Q7388366 47.22, 8.511 x 47.5, 8.824
    { 50, NoLogo, 161, LineMetaDataContent::RapidTransit, Color{0x5da526} }, // S2 OSM: 8294824 WD: Q7388254 47.13, 8.519 x 47.45, 9.063
    { 42, 10052, NoLogo, LineMetaDataContent::Subway, Color{0x6ad1e3} }, // 7 OSM: 8297146 WD: Q11074646 30.61, 104 x 30.7, 104.1
    { 59, 10062, NoLogo, LineMetaDataContent::Subway, Color{0xd40f7d} }, // 3 OSM: 8297273 WD: Q8985154 30.54, 103.9 x 30.82, 104.2
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x008000} }, // 2 OSM: 8297697 17.38, 78.48 x 17.45, 78.5
    { 1665, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // Red Line OSM: 8297698 WD: Q646209 17.35, 78.37 x 17.5, 78.55
    { 16, 10072, NoLogo, LineMetaDataContent::Subway, Color{0xff5c39} }, // 2 OSM: 8298113 WD: Q4391357 30.56, 104 x 30.76, 104.3
    { 9, 10082, NoLogo, LineMetaDataContent::Subway, Color{0x44af52} }, // 4 OSM: 8298132 WD: Q11074645 30.64, 103.8 x 30.69, 104.2
    { 65, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x003da5} }, // 10 OSM: 8298254 WD: Q11074644 30.41, 103.8 x 30.63, 104
    { 2967, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // North-South (Red Line) OSM: 8299497 WD: Q18128813 26.77, 80.88 x 26.89, 81
    { 2990, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xa89968} }, // 〇 OSM: 8300611 WD: Q15915083 29.51, 106.5 x 29.61, 106.6
    { 6, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x00a3e0} }, // 5 OSM: 8300867 WD: Q15912187 29.57, 106.5 x 29.68, 106.6
    { 65, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x00a3e0} }, // 10 OSM: 8300873 WD: Q15914281 29.58, 106.5 x 29.75, 106.7
    { 2994, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe1261c} }, // Xijiao OSM: 8303696 39.97, 116.2 x 39.99, 116.3
    { 3001, NoLogo, 161, LineMetaDataContent::RapidTransit, Color{0x56033a} }, // S 6 OSM: 8303864 WD: Q63217185 51.06, 12.37 x 51.4, 12.7
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xffda01} }, // 2 OSM: 8306856 WD: Q5960302 28.56, 115.8 x 28.7, 116
    { 55, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 8306857 WD: Q6850056 28.67, 115.8 x 28.86, 116.1
    { 2312, NoLogo, 161, LineMetaDataContent::RapidTransit, Color{0xf9aa8f} }, // S41 OSM: 8306928 WD: Q15088595 47.49, 8.535 x 47.53, 8.724
    { 55, NoLogo, 5906, LineMetaDataContent::Subway, Color{0x0000ff} }, // 1 OSM: 8309087 WD: Q5963161 30.57, 114.1 x 30.71, 114.3
    { 3005, NoLogo, 161, LineMetaDataContent::RapidTransit, Color{0xbda07c} }, // S15 OSM: 8309090 WD: Q7388191 47.22, 8.368 x 47.51, 8.864
    { 44, NoLogo, 161, LineMetaDataContent::RapidTransit, Color{0x48b4ca} }, // S5 OSM: 8311264 WD: Q7388335 47.17, 8.429 x 47.41, 8.864
    { 3009, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x000000} }, // WES OSM: 8313440 45.31, -122.8 x 45.49, -122.8
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff7300} }, // 2 OSM: 8323745 WD: Q2657097 30.12, 120 x 30.36, 120.3
    { 55, 10092, NoLogo, LineMetaDataContent::Subway, Color{0x3180b7} }, // 1 OSM: 8324096 WD: Q10946020 29.84, 121.4 x 29.92, 121.9
    { 26, NoLogo, 2022, LineMetaDataContent::Subway, Color{0x6ba53a} }, // 16 OSM: 8324250 WD: Q6553080 40, 116.1 x 40.07, 116.3
    { 1841, NoLogo, 161, LineMetaDataContent::RapidTransit, Color{0x0588cc} }, // S30 OSM: 8327718 WD: Q7388265 47.5, 8.722 x 47.59, 9.106
    { 1014, NoLogo, 161, LineMetaDataContent::RapidTransit, Color{0x007e94} }, // S26 OSM: 8327719 WD: Q2321332 47.26, 8.724 x 47.51, 8.934
    { 545, NoLogo, 161, LineMetaDataContent::RapidTransit, Color{0x7a4c29} }, // S13 OSM: 8327720 WD: Q7388186 47.13, 8.675 x 47.23, 8.75
    { 55, NoLogo, 10113, LineMetaDataContent::Subway, Color{0xff7300} }, // 1 OSM: 8337169 WD: Q15953685 24.45, 118 x 24.66, 118.1
    { 225, NoLogo, 161, LineMetaDataContent::RapidTransit, Color{0xb41e8e} }, // S25 OSM: 8355962 WD: Q18391643 46.92, 8.519 x 47.38, 9.084
    { 1665, NoLogo, 10006, LineMetaDataContent::Subway, Color{0xff0000} }, // Red Line OSM: 8429148 WD: Q3278367 28.67, 77.1 x 28.72, 77.42
    { 3013, NoLogo, 161, LineMetaDataContent::RapidTransit, Color{0x73b3d7} }, // S35 OSM: 8437405 WD: Q7388272 47.46, 8.724 x 47.51, 9.042
    { 3017, NoLogo, 161, LineMetaDataContent::RapidTransit, Color{0x32a384} }, // S29 OSM: 8437511 WD: Q7388235 47.5, 8.714 x 47.66, 8.855
    { 1456, NoLogo, 161, LineMetaDataContent::RapidTransit, Color{0xad99c9} }, // S40 OSM: 8437648 WD: Q7388295 47.13, 8.682 x 47.22, 8.817
    { 3021, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // ExpressTram OSM: 8438647 WD: Q5421647 42.2, -83.36 x 42.21, -83.35
    { 3033, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfc0200} }, // ATS OSM: 8438739 WD: Q2828747 41.97, -87.91 x 41.99, -87.88
    { 9, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0000ff} }, // 4 OSM: 8439223 WD: Q6112249 31.13, 120.6 x 31.41, 120.7
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // 2 OSM: 8439253 WD: Q1054280 31.25, 120.6 x 31.44, 120.8
    { 272, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffff00} }, // Yellow OSM: 8464133 WD: Q55683262 9.006, 7.272 x 9.057, 7.475
    { 1074, NoLogo, 5059, LineMetaDataContent::Subway, Color{0x00adef} }, // 52 OSM: 8466672 WD: Q2466115 52.34, 4.874 x 52.4, 4.933
    { 3037, 10133, 2957, LineMetaDataContent::Tramway, Color{0xe65e37} }, // T11 OSM: 8467024 WD: Q1083349 48.93, 2.302 x 48.96, 2.424
    { 3041, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa1a5a7} }, // Π4 OSM: 8467447 WD: Q17853551 37.91, 23.71 x 38.07, 23.94
    { 3045, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffd000} }, // Π1 OSM: 8467448 WD: Q47477364 37.91, 23.64 x 38.07, 23.94
    { 3049, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0098d8} }, // Π2 OSM: 8467516 WD: Q20552930 37.91, 22.73 x 38.09, 23.74
    { 3053, NoLogo, 2022, LineMetaDataContent::Subway, Color{0xd85f26} }, // 25S OSM: 8469061 WD: Q8048350 39.7, 116 x 39.73, 116.1
    { 190, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x254395} }, // T1 OSM: 8475071 WD: Q55693065 43.75, 11.17 x 43.8, 11.25
    { 119, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0b0080} }, // 9 OSM: 8478970 WD: Q3125123 39.01, 117.2 x 39.13, 117.7
    { 59, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x128bbe} }, // 3 OSM: 8489969 WD: Q6553117 39.06, 117.1 x 39.24, 117.3
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xffff00} }, // 2 OSM: 8489970 WD: Q6553104 39.13, 117.1 x 39.16, 117.4
    { 55, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 8489971 WD: Q6126171 39.01, 117.1 x 39.21, 117.4
    { 27, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x9f216f} }, // 6 OSM: 8490135 WD: Q10940001 39.04, 117.1 x 39.21, 117.3
    { 9, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x009049} }, // 4 OSM: 8499866 36.8, 10.06 x 36.82, 10.19
    { 126, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xaa6133} }, // 14 OSM: 8505950 52.38, 16.88 x 52.46, 16.92
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc597cd} }, // 12 OSM: 8505951 52.37, 16.91 x 52.46, 16.95
    { 3057, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf166a7} }, // 42X OSM: 8506177 58.9, 17.86 x 59.63, 18.16
    { 3061, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff7f00} }, // 11* OSM: 8510354 WD: Q2662616 52.36, 4.851 x 52.38, 4.902
    { 3065, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // TGM OSM: 8510421 36.8, 10.19 x 36.88, 10.34
    { 6, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x009049} }, // 5 OSM: 8510688 36.8, 10.12 x 36.84, 10.18
    { 59, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x009049} }, // 3 OSM: 8510789 36.8, 10.13 x 36.83, 10.18
    { 16, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x009049} }, // 2 OSM: 8511768 36.81, 10.18 x 36.86, 10.2
    { 1276, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf166a7} }, // 44 OSM: 8518402 59.2, 17.81 x 59.45, 18.07
    { 3069, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf166a7} }, // 43X OSM: 8518405 58.9, 17.81 x 59.45, 18.16
    { 440, 10166, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7577c0} }, // L OSM: 8557335 WD: Q93379 48.81, 2.009 x 49.05, 2.324
    { 119, NoLogo, 3643, LineMetaDataContent::Tramway, Color{0xff00ff} }, // 9 OSM: 8624098 WD: Q28609936 50.86, 4.309 x 50.89, 4.33
    { 181, 10189, NoLogo, LineMetaDataContent::Subway, Color{0xffb300} }, // B OSM: 8639238 WD: Q16266 37.25, 127 x 37.58, 127.1
    { 3073, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0c8e72} }, // GC OSM: 8656365 WD: Q20192 37.58, 127 x 37.89, 127.7
    { 44, 10218, 2313, LineMetaDataContent::RapidTransit, Color{0xeb8738} }, // S5 OSM: 8662846 WD: Q1159300 45.46, 8.789 x 45.82, 9.589
    { 186, 10232, 2313, LineMetaDataContent::RapidTransit, Color{0xebcc00} }, // S6 OSM: 8662847 WD: Q1160580 45.43, 8.625 x 45.53, 9.589
    { 3076, 5341, 5316, LineMetaDataContent::Subway, Color{0x009fe3} }, // L10 Sud OSM: 8663605 WD: Q1577033 41.34, 2.113 x 41.38, 2.148
    { 3084, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x73c7a6} }, // G·J OSM: 8667957 WD: Q18233162 37.47, 126.7 x 37.89, 127.6
    { 440, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffff00} }, // L OSM: 8668342 39.74, -105 x 39.76, -105
    { 37, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff7f00} }, // 24E OSM: 8682141 WD: Q63230204 38.71, -9.162 x 38.73, -9.143
    { 55, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x005daa} }, // 1 OSM: 8691899 WD: Q20280 36.77, 126.6 x 37.95, 127.2
    { 3089, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008144} }, // 902 OSM: 8708438 WD: Q5060656 44.95, -93.28 x 44.98, -93.08
    { 26, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf9b000} }, // 16 OSM: 8712352 52.32, 9.722 x 52.38, 9.837
    { 22, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe4003a} }, // 18 OSM: 8712368 52.33, 9.739 x 52.38, 9.804
    { 3093, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xba55d3} }, // 750 OSM: 8718106 WD: Q5505779 40.23, -112 x 41.23, -111.7
    { 3097, 10246, NoLogo, LineMetaDataContent::Subway, Color{0x8fc31e} }, // SH OSM: 8725316 WD: Q12601528 37.3, 126.8 x 37.48, 126.8
    { 3034, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x9bb14f} }, // TS OSM: 8729960 33.41, -111.9 x 33.42, -111.9
    { 3100, 10284, NoLogo, LineMetaDataContent::Subway, Color{0x0054a6} }, // GG OSM: 8735483 WD: Q23933857 37.26, 127.1 x 37.41, 127.6
    { 55, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x10069f} }, // 1 OSM: 8742572 WD: Q17498490 43.75, 87.47 x 43.92, 87.62
    { 190, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // T1 OSM: 8753522 43.25, -2.952 x 43.27, -2.921
    { 15, NoLogo, 1354, LineMetaDataContent::Tramway, Color{0xffd800} }, // 12 OSM: 8823281 WD: Q1485440 47.55, 19.09 x 47.57, 19.13
    { 3103, NoLogo, 1354, LineMetaDataContent::Tramway, Color{0xffd800} }, // 12M OSM: 8823336 WD: Q41594676 339.5, 249.5 x 339.5, 249.5
    { 3107, NoLogo, 1354, LineMetaDataContent::Tramway, Color{0xffd800} }, // 56A OSM: 8823482 WD: Q21996124 47.48, 18.96 x 47.54, 19.05
    { 3111, NoLogo, 1354, LineMetaDataContent::Tramway, Color{0xffd800} }, // 59A OSM: 8823524 WD: Q1491496 47.48, 19 x 47.51, 19.02
    { 3115, NoLogo, 1354, LineMetaDataContent::Tramway, Color{0xffd800} }, // 59B OSM: 8823525 WD: Q22810651 47.48, 18.96 x 47.54, 19.02
    { 47, 10316, 2313, LineMetaDataContent::RapidTransit, Color{0xf09ea1} }, // S8 OSM: 8840314 WD: Q1160824 45.48, 9.179 x 45.86, 9.435
    { 466, 10330, 2313, LineMetaDataContent::RapidTransit, Color{0x8c3682} }, // S9 OSM: 8840324 WD: Q56920 45.4, 8.956 x 45.65, 9.274
    { 53, 10344, 2313, LineMetaDataContent::RapidTransit, Color{0x8787ba} }, // S11 OSM: 8840325 WD: Q1160879 45.48, 9.029 x 45.83, 9.274
    { 55, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0000ff} }, // 1 OSM: 8857089 24.54, 46.61 x 24.84, 46.78
    { 27, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x800080} }, // 6 OSM: 8857388 24.7, 46.64 x 24.81, 46.83
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf5a300} }, // 12 OSM: 8871002 46.17, 6.122 x 46.2, 6.207
    { 3119, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // SC OSM: 8888446 43.03, 141.3 x 43.06, 141.4
    { 3122, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xbac219} }, // U16 OSM: 9091025 339.5, 249.5 x 339.5, 249.5
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xa68351} }, // 2 OSM: 9112026 47.54, 7.571 x 47.57, 7.617
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x324ea1} }, // 3 OSM: 9118502 47.55, 7.553 x 47.59, 7.631
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x835237} }, // 1 OSM: 9118510 47.55, 7.573 x 47.57, 7.608
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0072bc} }, // 6 OSM: 9128621 47.55, 7.537 x 47.59, 7.656
    { 42, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x8b0000} }, // 7 OSM: 9140122 14.65, 121 x 14.78, 121.1
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf171ab} }, // 8 OSM: 9173651 47.55, 7.557 x 47.59, 7.608
    { 3126, 10359, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00289c} }, // C-4 OSM: 9174513 WD: Q1919488 40.24, -3.778 x 40.65, -3.635
    { 65, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfeca0a} }, // 10 OSM: 9177454 47.48, 7.459 x 47.55, 7.62
    { 3130, 10377, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffa500} }, // C-9 OSM: 9181540 WD: Q8880294 40.74, -4.066 x 40.82, -3.963
    { 2292, 10392, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008a29} }, // C-2 OSM: 9187669 WD: Q2287356 40.38, -3.694 x 40.64, -3.181
    { 126, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf58220} }, // 14 OSM: 9190891 47.52, 7.587 x 47.57, 7.694
    { 130, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00a54f} }, // 15 OSM: 9193744 WD: Q89415715 47.53, 7.587 x 47.56, 7.6
    { 26, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xa6ce39} }, // 16 OSM: 9196819 47.53, 7.584 x 47.56, 7.605
    { 164, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00aeef} }, // 17 OSM: 9201222 47.48, 7.545 x 47.58, 7.593
    { 303, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x1662b8} }, // U OSM: 9221982 WD: Q1191079 35.62, 139.8 x 35.67, 139.8
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xd64560} }, // 2 OSM: 9235815 47.26, 11.34 x 47.28, 11.44
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8b445b} }, // 5 OSM: 9235816 47.26, 11.34 x 47.28, 11.44
    { 3134, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // СТ-2 OSM: 9244973 48.68, 44.47 x 48.8, 44.6
    { 267, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000c0} }, // Blue OSM: 9248096 38.45, -121.5 x 38.65, -121.4
    { 469, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00c000} }, // Green OSM: 9248097 38.57, -121.5 x 38.6, -121.5
    { 3141, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xc0ba00} }, // Gold OSM: 9248098 38.55, -121.5 x 38.68, -121.2
    { 3146, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff69b4} }, // NT OSM: 9253571 35.73, 139.8 x 35.82, 139.8
    { 2289, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xd85b81} }, // SA OSM: 9254426 WD: Q1064795 35.71, 139.7 x 35.75, 139.8
    { 3149, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x00ffff} }, // Aqua Line OSM: 9256785 WD: Q41668068 28.44, 77.37 x 28.59, 77.55
    { 1940, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0377ae} }, // R2 OSM: 9266121 48.62, 21.19 x 48.71, 21.3
    { 1949, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0377ae} }, // R8 OSM: 9266263 48.62, 21.19 x 48.71, 21.27
    { 509, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0377ae} }, // R1 OSM: 9273350 48.62, 21.19 x 48.72, 21.27
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0377ae} }, // 5 OSM: 9274837 48.7, 21.24 x 48.72, 21.27
    { 3159, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xcc3333} }, // exo1 OSM: 9288759 WD: Q3239247 45.39, -74.14 x 45.5, -73.57
    { 1423, 10406, NoLogo, LineMetaDataContent::RapidTransit, Color{0xda0442} }, // TY OSM: 9288983 WD: Q1192468 35.47, 139.6 x 35.66, 139.7
    { 524, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x5d3988} }, // T2 OSM: 9298542 WD: Q61670436 43.77, 11.2 x 43.8, 11.25
    { 1352, NoLogo, 4128, LineMetaDataContent::Subway, Color{0x903e98} }, // Purple OSM: 9315479 WD: Q60705613 37.6, -122.4 x 37.62, -122.4
    { 54, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x6a1d44} }, // 11 OSM: 9318442 WD: Q4698920 22.52, 113.8 x 22.79, 114.1
    { 3164, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x009900} }, // exo2 OSM: 9326028 45.45, -74 x 45.77, -73.57
    { 3169, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0099ff} }, // exo6 OSM: 9332052 WD: Q3239101 45.5, -73.91 x 45.55, -73.57
    { 3174, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x3564af} }, // SR OSM: 9336150 WD: Q1065949 35.78, 139.7 x 35.89, 139.8
    { 3177, 10431, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf18c43} }, // OM OSM: 9341650 WD: Q384995 35.6, 139.6 x 35.61, 139.7
    { 431, 10456, NoLogo, LineMetaDataContent::RapidTransit, Color{0xee86a8} }, // IK OSM: 9342009 WD: Q1192388 35.56, 139.7 x 35.63, 139.7
    { 3180, 10481, NoLogo, LineMetaDataContent::RapidTransit, Color{0xae0079} }, // TM OSM: 9343887 WD: Q379292 35.56, 139.7 x 35.59, 139.7
    { 3183, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff00ff} }, // exo5 OSM: 9344059 45.5, -73.67 x 45.74, -73.49
    { 3188, 10506, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0071be} }, // KD OSM: 9344153 WD: Q842701 35.53, 139.5 x 35.56, 139.5
    { 1767, 10531, NoLogo, LineMetaDataContent::RapidTransit, Color{0x10a899} }, // NS OSM: 9346454 WD: Q846381 35.91, 139.6 x 36.01, 139.6
    { 3191, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x6600cc} }, // exo3 OSM: 9348176 45.49, -73.57 x 45.58, -73.18
    { 3122, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xbac219} }, // U16 OSM: 9354869 48.8, 9.087 x 48.81, 9.277
    { 249, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf8b710} }, // 23 OSM: 9396890 48.75, 9.179 x 48.81, 9.221
    { 219, 10559, 10559, LineMetaDataContent::Tramway, Color{0xc01903} }, // A OSM: 9413576 WD: Q1419423 45.76, 3.082 x 45.81, 3.135
    { 69, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00ae9d} }, // 21 OSM: 9414064 47.56, 7.573 x 47.57, 7.608
    { 44, NoLogo, 161, LineMetaDataContent::RapidTransit, Color{0x86d0ed} }, // S5 OSM: 9414242 WD: Q63705361 47.59, 7.608 x 47.64, 7.744
    { 1849, NoLogo, 161, LineMetaDataContent::RapidTransit, Color{0xcb7eb5} }, // S36 OSM: 9414253 WD: Q15088595 47.52, 8.22 x 47.62, 8.538
    { 260, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xb43c46} }, // M1 OSM: 9434553 WD: Q60608236 -6.292, 106.8 x -6.191, 106.8
    { 3196, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xf890a5} }, // 捷運紅線 (新北投支線) OSM: 9437207 WD: Q8044505 25.13, 121.5 x 25.14, 121.5
    { 2755, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x398afc} }, // BL OSM: 9437778 WD: Q708378 24.96, 121.4 x 25.05, 121.6
    { 1014, 10574, 161, LineMetaDataContent::RapidTransit, Color{0x018a47} }, // S26 OSM: 9445376 WD: Q7388232 52.4, 13.28 x 52.61, 13.4
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffff00} }, // 3 OSM: 9453120 WD: Q61000373 -22.91, -43.19 x -22.9, -43.17
    { 27, NoLogo, 7138, LineMetaDataContent::Subway, Color{0xff5599} }, // 6 OSM: 9468298 WD: Q20110123 35.62, 51.44 x 35.7, 51.47
    { 3227, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff6600} }, // RN OSM: 9477810 35.81, 139.9 x 35.86, 139.9
    { 296, NoLogo, 10589, LineMetaDataContent::Subway, Color{0x3e9397} }, // M OSM: 9487066 WD: Q7057341 -33.8, 150.9 x -33.69, 151.2
    { 3230, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7a745a} }, // F3 OSM: 9488738 WD: Q31193173 41.1, 28.99 x 41.11, 28.99
    { 2064, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x006400} }, // EN OSM: 9499957 35.3, 139.5 x 35.34, 139.6
    { 3233, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00ced1} }, // SS OSM: 9507192 WD: Q195685 35.7, 139.3 x 35.91, 139.7
    { 55, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0000ff} }, // 1 OSM: 9522022 23, 72.61 x 23.01, 72.67
    { 55, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa6dfe6} }, // 1 OSM: 9525005 36.75, 10.18 x 36.8, 10.22
    { 27, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x652c90} }, // 6 OSM: 9530554 36.72, 10.18 x 36.8, 10.22
    { 366, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x008000} }, // L2 OSM: 9536631 WD: Q25420937 9.029, -79.51 x 9.104, -79.35
    { 267, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // Blue OSM: 9542499 9.046, 7.285 x 9.155, 7.344
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009999} }, // 5 OSM: 9544852 53.08, 8.752 x 53.12, 8.818
    { 3236, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffff00} }, // JN OSM: 9555851 35.51, 139.4 x 35.7, 139.7
    { 2699, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xffa500} }, // Orange Line OSM: 9571557 21.04, 79.04 x 21.14, 79.09
    { 279, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xe2251c} }, // Red OSM: 9573815 WD: Q25343681 25.19, 51.49 x 25.42, 51.61
    { 41, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xb46b7a} }, // S7 OSM: 9584586 31.61, 118.9 x 31.76, 119
    { 466, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xffc600} }, // S9 OSM: 9584587 31.34, 118.8 x 31.76, 118.9
    { 47, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff8000} }, // S8 OSM: 9588181 WD: Q10945880 32.15, 118.7 x 32.47, 119
    { 9, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x796baf} }, // 4 OSM: 9588283 32.06, 118.7 x 32.13, 119
    { 59, NoLogo, 5906, LineMetaDataContent::Subway, Color{0xdab866} }, // 3 OSM: 9588292 WD: Q11124519 30.49, 114.2 x 30.68, 114.3
    { 16, NoLogo, 5906, LineMetaDataContent::Subway, Color{0xe99bc1} }, // 2 OSM: 9592190 WD: Q5952205 30.44, 114.2 x 30.79, 114.4
    { 27, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x800080} }, // 6 OSM: 9599549 37.33, -122 x 37.96, -121.3
    { 19, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x800080} }, // 8 OSM: 9599549 37.33, -122 x 37.96, -121.3
    { 9, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x800080} }, // 4 OSM: 9599549 37.33, -122 x 37.96, -121.3
    { 65, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x800080} }, // 10 OSM: 9599549 37.33, -122 x 37.96, -121.3
    { 428, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x006400} }, // 41 OSM: 9600352 51.66, 19.32 x 51.74, 19.46
    { 22, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 18 OSM: 9600353 51.74, 19.38 x 51.78, 19.51
    { 164, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffc0cb} }, // 17 OSM: 9600354 51.7, 19.41 x 51.78, 19.51
    { 26, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffc0cb} }, // 16 OSM: 9600355 51.73, 19.37 x 51.8, 19.46
    { 130, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffc0cb} }, // 15 OSM: 9600356 51.72, 19.45 x 51.78, 19.53
    { 126, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // 14 OSM: 9600357 51.74, 19.38 x 51.76, 19.51
    { 58, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 13 OSM: 9600358 51.73, 19.37 x 51.8, 19.49
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 12 OSM: 9600359 51.74, 19.38 x 51.78, 19.53
    { 3239, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffa500} }, // 11AB OSM: 9600360 51.7, 19.41 x 51.83, 19.49
    { 3244, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // 10AB OSM: 9600361 51.73, 19.38 x 51.76, 19.58
    { 3249, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 9AB OSM: 9600362 51.73, 19.41 x 51.77, 19.58
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // 8 OSM: 9600363 51.75, 19.36 x 51.8, 19.54
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffa500} }, // 6 OSM: 9600365 51.72, 19.45 x 51.8, 19.49
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x800080} }, // 5 OSM: 9600366 51.72, 19.41 x 51.79, 19.49
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 4 OSM: 9600367 51.74, 19.43 x 51.83, 19.51
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffa500} }, // 3 OSM: 9600368 51.74, 19.45 x 51.81, 19.55
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffa500} }, // 2 OSM: 9600370 51.74, 19.36 x 51.8, 19.51
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x800080} }, // 1 OSM: 9600371 51.73, 19.46 x 51.8, 19.49
    { 3253, 10601, NoLogo, LineMetaDataContent::Tramway, Color{} }, // HN OSM: 9603867 WD: Q5648522 34.54, 135.4 x 34.65, 135.5
    { 313, 10639, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7777ff} }, // P OSM: 9603949 WD: Q1073366 34.61, 135.4 x 34.64, 135.5
    { 2762, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // 804 OSM: 9604087 37.33, -122.4 x 37.78, -121.9
    { 2963, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // 802 OSM: 9604087 37.33, -122.4 x 37.78, -121.9
    { 3256, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 424 OSM: 9604089 37.33, -122.4 x 37.78, -121.9
    { 3260, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 434 OSM: 9604089 37.33, -122.4 x 37.78, -121.9
    { 3264, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 428 OSM: 9604089 37.33, -122.4 x 37.78, -121.9
    { 3268, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 432 OSM: 9604089 37.33, -122.4 x 37.78, -121.9
    { 3272, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 440 OSM: 9604089 37.33, -122.4 x 37.78, -121.9
    { 3276, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 444 OSM: 9604089 37.33, -122.4 x 37.78, -121.9
    { 3280, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 422 OSM: 9604089 37.33, -122.4 x 37.78, -121.9
    { 3284, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 438 OSM: 9604089 37.33, -122.4 x 37.78, -121.9
    { 3288, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 436 OSM: 9604089 37.33, -122.4 x 37.78, -121.9
    { 3292, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 426 OSM: 9604089 37.33, -122.4 x 37.78, -121.9
    { 3296, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 430 OSM: 9604089 37.33, -122.4 x 37.78, -121.9
    { 3300, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 442 OSM: 9604089 37.33, -122.4 x 37.78, -121.9
    { 6, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xfb6f14} }, // 5 OSM: 9604983 WD: Q10940000 39.04, 117.1 x 39.27, 117.2
    { 530, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 156 OSM: 9605479 37, -122.4 x 37.78, -121.6
    { 3304, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 159 OSM: 9605480 37.33, -122.4 x 37.78, -121.9
    { 3308, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 191 OSM: 9605481 37.33, -122.4 x 37.78, -121.9
    { 3312, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 135 OSM: 9605481 37.33, -122.4 x 37.78, -121.9
    { 3316, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 143 OSM: 9605481 37.33, -122.4 x 37.78, -121.9
    { 3320, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 147 OSM: 9605481 37.33, -122.4 x 37.78, -121.9
    { 3324, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 139 OSM: 9605481 37.33, -122.4 x 37.78, -121.9
    { 3328, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 155 OSM: 9605481 37.33, -122.4 x 37.78, -121.9
    { 3332, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 101 OSM: 9605481 37.33, -122.4 x 37.78, -121.9
    { 1042, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 199 OSM: 9605481 37.33, -122.4 x 37.78, -121.9
    { 3336, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 193 OSM: 9605481 37.33, -122.4 x 37.78, -121.9
    { 3340, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 151 OSM: 9605481 37.33, -122.4 x 37.78, -121.9
    { 3344, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 194 OSM: 9605482 37.31, -122.4 x 37.78, -121.9
    { 3348, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 192 OSM: 9605482 37.31, -122.4 x 37.78, -121.9
    { 3352, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 104 OSM: 9605482 37.31, -122.4 x 37.78, -121.9
    { 3356, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 190 OSM: 9605483 37.33, -122.4 x 37.78, -121.9
    { 3360, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 138 OSM: 9605483 37.33, -122.4 x 37.78, -121.9
    { 3364, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 198 OSM: 9605483 37.33, -122.4 x 37.78, -121.9
    { 3368, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 146 OSM: 9605483 37.33, -122.4 x 37.78, -121.9
    { 3372, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 134 OSM: 9605483 37.33, -122.4 x 37.78, -121.9
    { 3376, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 142 OSM: 9605483 37.33, -122.4 x 37.78, -121.9
    { 3380, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 102 OSM: 9605483 37.33, -122.4 x 37.78, -121.9
    { 3384, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 150 OSM: 9605483 37.33, -122.4 x 37.78, -121.9
    { 319, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 196 OSM: 9605483 37.33, -122.4 x 37.78, -121.9
    { 3388, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 152 OSM: 9605483 37.33, -122.4 x 37.78, -121.9
    { 1642, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 197 OSM: 9605484 37.31, -122.4 x 37.78, -121.9
    { 3392, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 195 OSM: 9605484 37.31, -122.4 x 37.78, -121.9
    { 3396, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 103 OSM: 9605484 37.31, -122.4 x 37.78, -121.9
    { 9, NoLogo, 2223, LineMetaDataContent::Subway, Color{0x117e44} }, // 4 OSM: 9607978 WD: Q863422 22.75, 113.4 x 23.14, 113.6
    { 9, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xdc8633} }, // 4 OSM: 9609521 WD: Q15900365 29.6, 106.5 x 29.63, 106.7
    { 69, NoLogo, 2223, LineMetaDataContent::Subway, Color{0x201747} }, // 21 OSM: 9611531 WD: Q6553110 23.12, 113.4 x 23.29, 113.8
    { 3400, NoLogo, 2223, LineMetaDataContent::Subway, Color{0xb5cc19} }, // GF OSM: 9612493 WD: Q3272527 22.96, 113.1 x 23.09, 113.3
    { 27, NoLogo, 5906, LineMetaDataContent::Subway, Color{0x007733} }, // 6 OSM: 9617440 WD: Q15899990 30.49, 114.2 x 30.64, 114.3
    { 42, NoLogo, 5906, LineMetaDataContent::Subway, Color{0xee7800} }, // 7 OSM: 9617441 WD: Q11124507 30.32, 114.2 x 30.64, 114.3
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xdb6d1c} }, // 2 OSM: 9622751 WD: Q5947229 22.48, 113.9 x 22.56, 114.1
    { 44, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x8d1d81} }, // S5 OSM: 9626749 46.71, 15.42 x 47.07, 15.63
    { 3403, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x734538} }, // TEL OSM: 9627860 WD: Q7795883 1.272, 103.8 x 1.452, 104
    { 42, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0035ad} }, // 7 OSM: 9629866 WD: Q5938409 22.52, 113.9 x 22.6, 114.1
    { 59, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x00a2e1} }, // 3 OSM: 9629887 WD: Q1065551 22.52, 114 x 22.73, 114.3
    { 61, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00983a} }, // S1 OSM: 9631352 47.07, 15.28 x 47.41, 15.42
    { 9, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x920783} }, // 4 OSM: 9632502 WD: Q24835582 28.14, 112.9 x 28.3, 113.1
    { 9, NoLogo, 5906, LineMetaDataContent::Subway, Color{0xb8d200} }, // 4 OSM: 9633082 WD: Q6553126 30.53, 114 x 30.61, 114.4
    { 54, NoLogo, 5906, LineMetaDataContent::Subway, Color{0xfdd000} }, // 11 OSM: 9633134 WD: Q11124500 30.49, 114.3 x 30.53, 114.7
    { 59, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x8b4513} }, // 3 OSM: 9633218 WD: Q5986353 -33.46, -70.69 x -33.37, -70.56
    { 466, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x9f7fb8} }, // S9 OSM: 9634178 47.41, 15.27 x 47.61, 15.68
    { 47, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x5cc1d1} }, // S8 OSM: 9634179 47.17, 14.44 x 47.41, 15.28
    { 440, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0067c0} }, // L OSM: 9638873 WD: Q1329642 35.17, 137 x 35.18, 137.1
    { 9, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x00d800} }, // 4 OSM: 9641052 WD: Q11102444 30.16, 120.1 x 30.3, 120.2
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x3b6a96} }, // 2 OSM: 9642906 WD: Q15913266 43.86, 125.2 x 43.88, 125.4
    { 19, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x25b7bc} }, // 8 OSM: 9642908 43.95, 125.3 x 44.01, 125.4
    { 6, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x9950b2} }, // 5 OSM: 9645952 WD: Q5926109 22.48, 113.9 x 22.63, 114.1
    { 55, 10683, NoLogo, LineMetaDataContent::Subway, Color{0xee352e} }, // 1 OSM: 9651536 WD: Q126093 40.7, -74.02 x 40.89, -73.9
    { 16, 10709, NoLogo, LineMetaDataContent::Subway, Color{0xee352e} }, // 2 OSM: 9655665 WD: Q126142 40.63, -74.01 x 40.9, -73.85
    { 59, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x571887} }, // 3 OSM: 9656354 WD: Q25824052 22.72, 108.2 x 22.88, 108.4
    { 59, 10735, NoLogo, LineMetaDataContent::Subway, Color{0xee352e} }, // 3 OSM: 9663807 WD: Q126151 40.66, -74.01 x 40.82, -73.88
    { 3407, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x6c8bc6} }, // D11 OSM: 9672611 51.1, 16.15 x 51.4, 17.04
    { 9, 10761, NoLogo, LineMetaDataContent::Subway, Color{0x00933c} }, // 4 OSM: 9677108 WD: Q126163 40.66, -74.01 x 40.89, -73.88
    { 1767, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xce0037} }, // NS OSM: 9677671 WD: Q3333785 -6.292, 106.8 x -6.191, 106.8
    { 362, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xee343f} }, // L1 OSM: 9678605 WD: Q14543324 -33.91, 151.1 x -33.87, 151.2
    { 440, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe4022d} }, // L OSM: 9678765 -32.93, 151.8 x -32.92, 151.8
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 2 OSM: 9680853 51.37, -0.2081 x 51.42, -0.02612
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xb5e61d} }, // 4 OSM: 9680854 51.37, -0.2081 x 51.42, -0.04953
    { 6, 10787, NoLogo, LineMetaDataContent::Subway, Color{0x00933c} }, // 5 OSM: 9682651 WD: Q126177 40.63, -74.01 x 40.9, -73.83
    { 119, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x846e74} }, // 9 OSM: 9699772 WD: Q5939429 22.51, 113.9 x 22.57, 114.1
    { 2052, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // BLUE OSM: 9701744 53.33, -1.508 x 53.4, -1.344
    { 3411, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x800080} }, // PURP OSM: 9701781 53.34, -1.469 x 53.38, -1.424
    { 3416, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffff00} }, // YELL OSM: 9701824 53.38, -1.51 x 53.42, -1.405
    { 3421, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // TT OSM: 9701873 53.38, -1.469 x 53.44, -1.343
    { 3424, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x006bb6} }, // SIR OSM: 9701910 WD: Q1273068 40.51, -74.25 x 40.64, -74.07
    { 126, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe2368c} }, // 14 OSM: 9708096 47.14, 37.54 x 47.18, 37.62
    { 58, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe2368c} }, // 13 OSM: 9708097 47.14, 37.54 x 47.18, 37.62
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x13b5eb} }, // 8 OSM: 9708100 47.1, 37.51 x 47.12, 37.56
    { 42, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x329932} }, // 7 OSM: 9708101 47.1, 37.54 x 47.18, 37.57
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe51919} }, // 1 OSM: 9708102 47.1, 37.54 x 47.15, 37.62
    { 65, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x4f3893} }, // 10 OSM: 9708103 47.1, 37.51 x 47.18, 37.62
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf37b24} }, // 3 OSM: 9709247 47.1, 37.51 x 47.12, 37.65
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf37b24} }, // 4 OSM: 9709278 47.1, 37.51 x 47.12, 37.65
    { 469, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008150} }, // Green OSM: 9709938 WD: Q172040 42.33, -71.17 x 42.37, -71.06
    { 54, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x897ab7} }, // 11 OSM: 9712140 47.1, 37.54 x 47.18, 37.65
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffbf00} }, // 5 OSM: 9712141 47.1, 37.54 x 47.15, 37.65
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffbf00} }, // 6 OSM: 9712142 47.1, 37.54 x 47.12, 37.65
    { 119, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0068b2} }, // 9 OSM: 9712143 47.1, 37.54 x 47.18, 37.65
    { 296, 10813, NoLogo, LineMetaDataContent::Subway, Color{0xff6319} }, // M OSM: 9712349 WD: Q126418 40.7, -74 x 40.76, -73.84
    { 440, 10839, NoLogo, LineMetaDataContent::Subway, Color{0xa7a9ac} }, // L OSM: 9716997 WD: Q126534 40.65, -74.01 x 40.74, -73.9
    { 466, NoLogo, 161, LineMetaDataContent::RapidTransit, Color{0x8567a6} }, // S9 OSM: 9719969 WD: Q3239195 47.35, 7.812 x 47.46, 7.918
    { 3428, 1757, NoLogo, LineMetaDataContent::Subway, Color{0xb933ad} }, // <7> OSM: 9721629 WD: Q126203 40.74, -74 x 40.76, -73.83
    { 3432, 1887, NoLogo, LineMetaDataContent::Subway, Color{0x00933c} }, // <6> OSM: 9721630 WD: Q126192 40.71, -74.01 x 40.85, -73.83
    { 16, 10865, NoLogo, LineMetaDataContent::RapidTransit, Color{0x75bd42} }, // 2 OSM: 9727182 WD: Q20814403 45.36, -75.72 x 45.41, -75.66
    { 3436, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // 202 OSM: 9729897 51.04, -114.2 x 51.13, -113.9
    { 3440, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // 201 OSM: 9729912 50.9, -114.2 x 51.13, -114.1
    { 3444, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfc6357} }, // 502 OSM: 9730137 53.52, -113.5 x 53.57, -113.5
    { 3448, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x3a59a9} }, // 501 OSM: 9730138 53.46, -113.5 x 53.6, -113.4
    { 55, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // 1 OSM: 9732464 -3.039, 104.7 x -2.894, 104.8
    { 3452, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xed1d24} }, // TWL OSM: 9736531 WD: Q1194568 22.28, 114.1 x 22.38, 114.2
    { 3456, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x7d499d} }, // TKL OSM: 9736612 WD: Q989347 22.29, 114.2 x 22.32, 114.3
    { 230, 7931, NoLogo, LineMetaDataContent::Subway, Color{0x996633} }, // J OSM: 9747970 WD: Q126484 40.68, -74.01 x 40.72, -73.8
    { 181, 10894, NoLogo, LineMetaDataContent::Subway, Color{0xff6319} }, // B OSM: 9748435 WD: Q126381 40.58, -74 x 40.87, -73.89
    { 233, 10920, NoLogo, LineMetaDataContent::Subway, Color{0xff6319} }, // F OSM: 9753684 WD: Q126404 40.58, -74 x 40.77, -73.78
    { 3460, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xb60081} }, // Yangluo OSM: 9765661 30.65, 114.3 x 30.72, 114.6
    { 214, 10946, NoLogo, LineMetaDataContent::Subway, Color{0x0039a6} }, // C OSM: 9767766 WD: Q126358 40.67, -74.01 x 40.84, -73.87
    { 1099, 10972, NoLogo, LineMetaDataContent::Subway, Color{0xff6319} }, // D OSM: 9769161 WD: Q126396 40.58, -74.01 x 40.88, -73.88
    { 39, 10998, NoLogo, LineMetaDataContent::Subway, Color{0x0039a6} }, // E OSM: 9769302 WD: Q126368 40.7, -74.01 x 40.76, -73.8
    { 3468, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x000000} }, // 751P OSM: 9788142 WD: Q15903000 22.45, 114 x 22.47, 114
    { 3473, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xee3a41} }, // NEC OSM: 9795466 WD: Q7057868 40.2, -74.79 x 40.77, -73.99
    { 524, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe2393a} }, // T2 OSM: 9797089 49.18, -0.3663 x 49.21, -0.348
    { 1561, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x049adc} }, // T3 OSM: 9797090 49.16, -0.3636 x 49.19, -0.3411
    { 1362, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf686c3} }, // TRE OSM: 9797671 WD: Q7838588 39.95, -75.2 x 40.22, -74.75
    { 9, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0cc3a3} }, // 4 OSM: 9807766 WD: Q15939632 34.14, 108.9 x 34.38, 109
    { 3477, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x8c493a} }, // CFL OSM: 9812222 WD: Q5034802 -34.06, 18.43 x -33.92, 18.5
    { 3481, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008a29} }, // C-6 OSM: 9812239 WD: Q5987225 39.44, -0.3834 x 39.99, -0.05192
    { 3485, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x3096c2} }, // NLR OSM: 9821052 WD: Q3078283 40.73, -74.19 x 40.78, -74.16
    { 439, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xed1c24} }, // SL OSM: 9822441 WD: Q7570093 -34.19, 18.43 x -33.92, 18.47
    { 3489, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x99d420} }, // NL OSM: 9822443 WD: Q7058663 -34.01, 18.43 x -33.47, 18.99
    { 443, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x33bef3} }, // CL OSM: 9822444 WD: Q5061363 -34.07, 18.43 x -33.92, 18.71
    { 59, NoLogo, 2223, LineMetaDataContent::Subway, Color{0xef6828} }, // 3 OSM: 9841063 WD: Q862941 22.94, 113.3 x 23.4, 113.4
    { 3492, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0194d7} }, // JFK OSM: 9862004 WD: Q406683 40.64, -73.83 x 40.7, -73.78
    { 58, NoLogo, 3363, LineMetaDataContent::RapidTransit, Color{0x2ca05a} }, // 13 OSM: 9881314 WD: Q6553067 -23.54, -46.63 x -23.43, -46.49
    { 3496, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // Norte OSM: 9881792 -5.797, -35.42 x -5.632, -35.21
    { 2048, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // Sul OSM: 9881793 -5.917, -35.26 x -5.78, -35.21
    { 119, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0000ff} }, // 9 OSM: 9893306 41.72, 123.3 x 41.84, 123.5
    { 469, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x76c761} }, // Green OSM: 9897509 WD: Q6925400 37.28, -122.1 x 37.41, -121.9
    { 267, 11024, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00a4e2} }, // Blue OSM: 9897510 WD: Q4737344 37.24, -121.9 x 37.41, -121.8
    { 3502, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // ARL OSM: 9921501 WD: Q1133704 13.69, 100.5 x 13.76, 100.8
    { 119, NoLogo, 2223, LineMetaDataContent::Subway, Color{0x71cc98} }, // 9 OSM: 9924027 WD: Q6553161 23.35, 113.1 x 23.4, 113.3
    { 1066, 11078, 161, LineMetaDataContent::RapidTransit, Color{0xc36939} }, // S42 OSM: 9942315 WD: Q15118875 52.46, 13.28 x 52.55, 13.48
    { 201, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffd700} }, // G OSM: 9942698 WD: Q5578772 39.75, -105.1 x 39.81, -105
    { 181, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // B OSM: 9942699 WD: Q19865232 39.75, -105 x 39.82, -105
    { 219, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x57c0e8} }, // A OSM: 9942719 WD: Q5328174 39.75, -105 x 39.85, -104.7
    { 3506, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xcccccc} }, // Silver OSM: 9946498 32.71, -117.2 x 32.72, -117.2
    { 3513, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // 530 OSM: 9946502 32.71, -117.2 x 32.84, -117
    { 3517, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffa500} }, // 520 OSM: 9946503 32.71, -117.2 x 32.81, -117
    { 214, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf79239} }, // C OSM: 9947502 WD: Q5015067 39.58, -105 x 39.76, -105
    { 1099, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008348} }, // D OSM: 9947503 39.58, -105 x 39.75, -105
    { 39, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x552683} }, // E OSM: 9947507 39.52, -105 x 39.76, -104.9
    { 233, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xee3e33} }, // F OSM: 9947520 39.52, -105 x 39.75, -104.9
    { 378, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0075bf} }, // H OSM: 9947525 39.63, -105 x 39.75, -104.8
    { 317, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xb7f037} }, // R OSM: 9947529 39.52, -104.9 x 39.77, -104.8
    { 552, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x37b5a5} }, // W OSM: 9947532 39.72, -105.2 x 39.76, -105
    { 190, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x23a638} }, // T1 OSM: 9953164 49.15, -0.3663 x 49.2, -0.329
    { 1053, NoLogo, 2313, LineMetaDataContent::RapidTransit, Color{0x293838} }, // S12 OSM: 9959066 WD: Q26828150 45.36, 9.159 x 45.5, 9.319
    { 3521, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x996746} }, // AREX OSM: 9961461 WD: Q487643 37.44, 126.4 x 37.6, 127
    { 3526, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xd1aa00} }, // SAR-VIN OSM: 9963645 WD: Q10318744 -22.68, -43.25 x -22.57, -43.18
    { 3534, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x660066} }, // Belford Roxo OSM: 9963651 WD: Q10318671 -22.91, -43.4 x -22.76, -43.19
    { 3547, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf60619} }, // Deodoro OSM: 9963665 WD: Q18473921 -22.91, -43.39 x -22.85, -43.19
    { 3555, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfa8835} }, // Saracuruna OSM: 9963667 WD: Q10318727 -22.91, -43.31 x -22.68, -43.19
    { 3566, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x5194c4} }, // JRI-PBI OSM: 9963669 WD: Q10318719 -22.64, -43.71 x -22.61, -43.65
    { 3574, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x96333b} }, // SAR-GIM OSM: 9963674 WD: Q10318688 -22.68, -43.25 x -22.52, -42.98
    { 3582, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x6b297e} }, // Parangaba-Mucuripe OSM: 9963934 WD: Q10318709 -3.776, -38.56 x -3.736, -38.48
    { 3601, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // Oeste OSM: 9963937 WD: Q14325543 -3.77, -38.66 x -3.718, -38.54
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009ee3} }, // 4 OSM: 9964886 52.25, 10.51 x 52.27, 10.56
    { 219, 11093, 538, LineMetaDataContent::RapidTransit, Color{0x00bfff} }, // A OSM: 9971068 WD: Q2323144 55.46, 12.17 x 55.93, 12.59
    { 267, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00aeef} }, // Blue OSM: 9976615 39.18, -76.68 x 39.5, -76.62
    { 272, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfff200} }, // Yellow OSM: 9976616 39.17, -76.66 x 39.45, -76.62
    { 279, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xde1d43} }, // Red OSM: 9976617 39.28, -76.62 x 39.31, -76.61
    { 3607, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008c4e} }, // HBLR OSM: 9997061 40.65, -74.13 x 40.79, -74.01
    { 130, 11115, 2554, LineMetaDataContent::Subway, Color{0xde64a1} }, // 15 OSM: 10011657 WD: Q4226438 55.7, 37.7 x 55.78, 37.94
    { 267, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // Blue OSM: 10012484 35.11, -80.88 x 35.32, -80.73
    { 119, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009cdd} }, // 9 OSM: 10015448 53.41, 14.49 x 53.47, 14.55
    { 200, 11140, NoLogo, LineMetaDataContent::RapidTransit, Color{0x8ba2ae} }, // MG OSM: 10023806 WD: Q283861 35.55, 139.6 x 35.63, 139.7
    { 3612, 11165, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00a650} }, // JB OSM: 10025275 WD: Q5365768 35.75, 139.8 x 35.9, 140.1
    { 3615, 11187, NoLogo, LineMetaDataContent::RapidTransit, Color{0x01aaaa} }, // TJ OSM: 10032387 WD: Q1040703 35.73, 139.2 x 36.12, 139.7
    { 3618, 11218, NoLogo, LineMetaDataContent::RapidTransit, Color{0x01aaaa} }, // DT OSM: 10032468 WD: Q1190086 35.47, 139.4 x 35.66, 139.7
    { 3621, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe2000a} }, // 21A OSM: 10034064 49.4, 8.675 x 49.41, 8.693
    { 55, 11243, NoLogo, LineMetaDataContent::RapidTransit, Color{0xee1b2e} }, // 1 OSM: 10036404 WD: Q5159786 45.4, -75.74 x 45.43, -75.61
    { 3625, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00a650} }, // OT OSM: 10036880 WD: Q1063832 35.39, 139.3 x 35.67, 139.7
    { 1281, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe80000} }, // O OSM: 10073686 WD: Q1142127 34.65, 135.5 x 34.71, 135.5
    { 3628, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x5fb04f} }, // South OSM: 10077909 WD: Q7564853 47.15, -122.5 x 47.6, -122.2
    { 3634, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x88be5f} }, // 1704 OSM: 10077947 WD: Q56525585 47.6, -122.4 x 47.98, -122.2
    { 2188, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x88be5f} }, // 1706 OSM: 10077947 WD: Q56525585 47.6, -122.4 x 47.98, -122.2
    { 3639, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x88be5f} }, // 1700 OSM: 10077947 WD: Q56525585 47.6, -122.4 x 47.98, -122.2
    { 3644, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x88be5f} }, // North OSM: 10077955 WD: Q7564853 47.6, -122.4 x 47.98, -122.2
    { 65, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe3000b} }, // 10 OSM: 10082596 52.25, 10.51 x 52.31, 10.54
    { 3650, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xa17800} }, // 김포 골드라인 OSM: 10092720 WD: Q12589088 37.56, 126.6 x 37.65, 126.8
    { 469, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008150} }, // Green OSM: 10099594 WD: Q172031 42.32, -71.25 x 42.35, -71.06
    { 119, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x4ea391} }, // 9 OSM: 10103680 47.12, 27.56 x 47.19, 27.59
    { 126, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xb289bc} }, // 14 OSM: 10131355 WD: Q63781395 34.72, 113.5 x 34.77, 113.5
    { 3670, NoLogo, 2022, LineMetaDataContent::Subway, Color{0x0045bd} }, // Daxing Airport OSM: 10136967 WD: Q19840478 39.51, 116.3 x 39.85, 116.4
    { 55, NoLogo, 11282, LineMetaDataContent::Subway, Color{0x503a65} }, // 1 OSM: 10149342 WD: Q18654264 36.5, 116.8 x 36.68, 116.9
    { 55, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xcd5c5c} }, // 1 OSM: 10163085 WD: Q66660306 31.61, 119.9 x 31.91, 120
    { 190, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x363d42} }, // T1 OSM: 10181950 WD: Q48747416 43.93, 4.799 x 43.94, 4.841
    { 3685, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x015698} }, // River OSM: 10213690 WD: Q2155505 39.94, -75.13 x 40.22, -74.71
    { 366, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xee343f} }, // L2 OSM: 10214162 WD: Q16927050 -33.92, 151.2 x -33.86, 151.2
    { 3625, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffe100} }, // OT OSM: 10238058 34.97, 135.8 x 35.07, 135.9
    { 61, NoLogo, 161, LineMetaDataContent::RapidTransit, Color{0x80cf66} }, // S1 OSM: 10249610 WD: Q3239193 47.51, 7.591 x 47.57, 8.063
    { 153, NoLogo, 161, LineMetaDataContent::RapidTransit, Color{0x6c99d7} }, // S3 OSM: 10249618 WD: Q3239191 47.33, 7.08 x 47.55, 7.918
    { 214, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x00dd00} }, // C OSM: 10258970 WD: Q1057729 34.64, 135.4 x 34.73, 135.8
    { 3691, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x343f4b} }, // CMET OSM: 10271387 WD: Q16927042 -35.28, 149.1 x -35.19, 149.2
    { 3696, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x000000} }, // APT OSM: 10274979 32.86, -96.94 x 32.87, -96.93
    { 1561, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x14b845} }, // T3 OSM: 10279984 43.66, 7.195 x 43.71, 7.212
    { 333, NoLogo, 1450, LineMetaDataContent::Subway, Color{0xff0a0a} }, // M3 OSM: 10283923 WD: Q1094251 55.67, 12.53 x 55.71, 12.59
    { 3700, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x65b724} }, // BTS Sukhumvit OSM: 10285801 WD: Q4921598 13.56, 100.5 x 13.88, 100.6
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xcb1723} }, // 1 OSM: 10286521 43.7, 7.254 x 43.73, 7.293
    { 233, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // F OSM: 10286522 WD: Q3537109 35.91, 136.2 x 36.07, 136.2
    { 554, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf6a602} }, // D1 OSM: 10309188 WD: Q62091003 55.67, 37.28 x 56.01, 37.59
    { 3714, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe83f83} }, // D2 OSM: 10309312 WD: Q62091175 55.43, 37.18 x 55.84, 37.74
    { 55, 11302, 11302, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 10309985 WD: Q2106 53.2, 50.12 x 53.21, 50.28
    { 3717, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff88bb} }, // Roch OSM: 10310648 53.41, -2.28 x 53.62, -2.088
    { 3722, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x887766} }, // EDid OSM: 10310683 53.41, -2.28 x 53.62, -2.088
    { 3727, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x887766} }, // Sh&C OSM: 10310683 53.41, -2.28 x 53.58, -2.089
    { 3612, 11324, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffd700} }, // JB OSM: 10312072 WD: Q1091295 35.61, 139.6 x 35.74, 140.1
    { 3732, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0066bb} }, // Dean OSM: 10314875 WD: Q22712167 53.37, -2.297 x 53.49, -2.238
    { 3737, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0066bb} }, // Airp OSM: 10314875 53.37, -2.297 x 53.49, -2.238
    { 3742, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0066bb} }, // Vict OSM: 10314875 53.37, -2.297 x 53.49, -2.238
    { 3747, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff7700} }, // MCUK OSM: 10320090 53.47, -2.297 x 53.49, -2.098
    { 3752, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xffffff} }, // Arcobaleno OSM: 10320583 WD: Q3832713 40.89, 14.21 x 40.97, 14.24
    { 3141, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xf9b428} }, // Gold OSM: 10322047 WD: Q22948672 25.26, 51.44 x 25.29, 51.57
    { 3763, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00ccff} }, // Asht OSM: 10326857 53.47, -2.334 x 53.49, -2.098
    { 3768, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00ccff} }, // Eccl OSM: 10326857 WD: Q22087023 53.47, -2.334 x 53.49, -2.098
    { 3773, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffbb00} }, // Picc OSM: 10334672 WD: Q22087020 53.39, -2.347 x 53.59, -2.226
    { 3778, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008800} }, // Altr OSM: 10334764 53.39, -2.347 x 53.59, -2.226
    { 3783, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008800} }, // Bury OSM: 10334764 53.39, -2.347 x 53.59, -2.226
    { 3788, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xd32232} }, // ESFECO OSM: 10334823 WD: Q1132053 -22.95, -43.22 x -22.94, -43.2
    { 55, NoLogo, 11346, LineMetaDataContent::Subway, Color{0xbf3a35} }, // 1 OSM: 10379854 WD: Q47004909 34.24, 117.1 x 34.27, 117.3
    { 55, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0080bc} }, // 1 OSM: 10380194 WD: Q10893610 36.04, 103.7 x 36.1, 103.9
    { 61, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0061ae} }, // S1 OSM: 10380259 WD: Q15910427 27.91, 120.6 x 27.99, 120.9
    { 3795, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x00c1d5} }, // AIRPORT OSM: 10381397 WD: Q15939632 34.38, 108.8 x 34.46, 108.9
    { 59, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xf1a82b} }, // 3 OSM: 10383244 WD: Q10946022 29.79, 121.5 x 29.91, 121.6
    { 153, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xf1a82b} }, // S3 OSM: 10383349 WD: Q18111493 29.77, 121.5 x 29.79, 121.5
    { 3803, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x073686} }, // KS OSM: 10384058 WD: Q855470 35.53, 139.8 x 35.81, 140.4
    { 6, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0db0c8} }, // 5 OSM: 10386968 WD: Q11102446 30.17, 120 x 30.32, 120.3
    { 6, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x2a5947} }, // 5 OSM: 10387105 WD: Q15928521 34.72, 113.6 x 34.78, 113.8
    { 3806, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffc425} }, // Airtrain OSM: 10391556 WD: Q409266 -27.47, 153 x -27.38, 153.1
    { 420, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffa500} }, // 22 OSM: 10396259 WD: Q2885972 52.07, 5.112 x 52.09, 5.184
    { 3815, NoLogo, 11368, LineMetaDataContent::RapidTransit, Color{0x96c93c} }, // Taipa OSM: 10402175 WD: Q15935354 22.14, 113.5 x 22.16, 113.6
    { 469, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x009530} }, // Green OSM: 10403427 WD: Q25343673 25.27, 51.35 x 25.32, 51.53
    { 3821, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xdb6198} }, // 305 OSM: 10409526 51.46, 7.152 x 51.48, 7.324
    { 3825, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x40558e} }, // 309 OSM: 10409567 51.44, 7.297 x 51.46, 7.337
    { 3829, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe28e07} }, // 316 OSM: 10409642 51.48, 7.16 x 51.53, 7.272
    { 370, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xee343f} }, // L3 OSM: 10411683 WD: Q16927050 -33.93, 151.2 x -33.86, 151.2
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x96368b} }, // 1 OSM: 10413963 WD: Q15883002 51.2, 4.388 x 51.26, 4.421
    { 3833, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // 4М OSM: 10423669 47.83, 33.34 x 48, 33.5
    { 3837, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // 3М OSM: 10423670 47.88, 33.39 x 48, 33.5
    { 3841, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // 2М OSM: 10423671 47.89, 33.39 x 48, 33.5
    { 3845, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // 1М OSM: 10423672 47.89, 33.39 x 47.96, 33.46
    { 3849, NoLogo, 161, LineMetaDataContent::RapidTransit, Color{0x006db6} }, // RB 32 OSM: 10432813 WD: Q7388251 51.43, 6.775 x 51.58, 7.459
    { 3855, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00bbb3} }, // CHW OSM: 10433666 WD: Q5093959 39.95, -75.21 x 40.08, -75.15
    { 3859, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa57b27} }, // CHE OSM: 10433667 WD: Q5093950 39.95, -75.21 x 40.08, -75.15
    { 3863, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x91456c} }, // AIR OSM: 10433668 WD: Q4698916 39.87, -75.26 x 39.98, -75.15
    { 3867, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x775ca7} }, // CYN OSM: 10433669 WD: Q5200188 39.95, -75.23 x 40.01, -75.17
    { 3871, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xee5067} }, // NOR OSM: 10433670 WD: Q6747157 39.95, -75.35 x 40.12, -75.15
    { 3875, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0081c5} }, // ELW OSM: 10433671 WD: Q6805374 39.9, -75.41 x 39.98, -75.15
    { 3879, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x8ed16a} }, // NWK OSM: 10433672 WD: Q8022734 39.67, -75.75 x 39.98, -75.15
    { 1205, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xc72a80} }, // L5 OSM: 10443588 46.18, 5.999 x 46.22, 6.144
    { 1209, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00b3b9} }, // L6 OSM: 10447940 46.1, 5.821 x 46.22, 6.144
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x00643a} }, // 2 OSM: 10458608 WD: Q20063925 26.04, 119.1 x 26.11, 119.4
    { 358, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xdc911b} }, // L4 OSM: 10464491 46.17, 6.121 x 46.32, 6.237
    { 54, NoLogo, 8380, LineMetaDataContent::Subway, Color{0x304299} }, // 11 OSM: 10467354 WD: Q15944362 36.1, 120.5 x 36.48, 120.8
    { 58, NoLogo, 8380, LineMetaDataContent::Subway, Color{0x00ac84} }, // 13 OSM: 10467728 WD: Q15937512 35.67, 119.7 x 35.95, 120.2
    { 3883, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // Sado OSM: 10484570 WD: Q1314068 38.51, -9.08 x 38.66, -8.838
    { 164, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00ace7} }, // 17 OSM: 10486182 46.19, 6.125 x 46.2, 6.232
    { 219, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // A OSM: 10486983 47.83, 1.9 x 47.93, 1.939
    { 16, NoLogo, 10113, LineMetaDataContent::Subway, Color{0x008900} }, // 2 OSM: 10488738 WD: Q24838989 24.48, 117.9 x 24.58, 118.2
    { 59, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xf57b00} }, // 3 OSM: 10488912 WD: Q6112757 31.26, 120.5 x 31.37, 120.8
    { 59, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x008000} }, // 3 OSM: 10488951 WD: Q17023374 31.75, 117.2 x 31.93, 117.4
    { 524, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x44d62c} }, // T2 OSM: 10490757 30.69, 103.8 x 30.83, 104
    { 181, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x72277b} }, // B OSM: 10494114 47.9, 1.854 x 47.91, 1.977
    { 370, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x6c9d40} }, // L3 OSM: 10505987 45.91, 6.121 x 46.32, 6.703
    { 55, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xe82311} }, // 1 OSM: 10507454 WD: Q76339003 40.78, 111.6 x 40.86, 111.8
    { 59, NoLogo, 11282, LineMetaDataContent::Subway, Color{0xff0000} }, // 3 OSM: 10513363 WD: Q24837836 36.61, 117.1 x 36.77, 117.2
    { 362, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xbf3527} }, // L1 OSM: 10521809 46.17, 6.121 x 46.4, 6.58
    { 366, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0085c4} }, // L2 OSM: 10526246 45.9, 6.116 x 46.32, 6.362
    { 6, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xbb29bb} }, // 5 OSM: 10526316 WD: Q22100474 30.45, 104 x 30.83, 104.1
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffcc11} }, // 2 OSM: 10547015 51, 3.709 x 51.05, 3.772
    { 119, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff2e17} }, // 9 OSM: 10547655 48.34, 10.89 x 48.37, 10.9
    { 219, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe3028c} }, // A OSM: 10551319 48.38, -4.556 x 48.43, -4.444
    { 1246, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf9661e} }, // Orange OSM: 10561837 37.36, -122.1 x 37.42, -121.8
    { 1632, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // Blue Line OSM: 10563564 25.31, 51.42 x 25.32, 51.43
    { 2304, 5039, 161, LineMetaDataContent::RapidTransit, Color{0x008000} }, // Central OSM: 10570207 WD: Q459508 -7.233, -39.41 x -7.203, -39.3
    { 55, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x8a8988} }, // 1 OSM: 10570395 WD: Q10318643 -5.111, -42.82 x -5.08, -42.74
    { 2201, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // CBTU OSM: 10570416 WD: Q18484877 -7.131, -34.98 x -6.974, -34.83
    { 3496, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // Norte OSM: 10570453 -3.683, -40.37 x -3.662, -40.34
    { 2048, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // Sul OSM: 10570461 -3.699, -40.36 x -3.682, -40.33
    { 3888, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // 550 OSM: 10577109 WD: Q4338668 30.26, -97.86 x 30.59, -97.7
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf18e00} }, // 2 OSM: 10579671 WD: Q3238812 43.57, 3.83 x 43.65, 3.931
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xcbd300} }, // 3 OSM: 10579672 WD: Q3238911 43.56, 3.81 x 43.62, 3.964
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x005ba1} }, // 1 OSM: 10579673 WD: Q3238667 43.6, 3.817 x 43.64, 3.92
    { 3892, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xee293d} }, // TEX OSM: 10580066 WD: Q28228164 32.75, -97.34 x 32.94, -97.04
    { 61, NoLogo, 11392, LineMetaDataContent::RapidTransit, Color{} }, // S1 OSM: 10603188 WD: Q43285793 39.89, 116.3 x 39.9, 116.7
    { 3896, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x55502b} }, // UP Express OSM: 10608917 WD: Q497520 43.64, -79.62 x 43.71, -79.38
    { 3907, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x794400} }, // Stouffville OSM: 10624851 WD: Q3239216 43.64, -79.38 x 44, -79.23
    { 3919, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x009ac7} }, // Richmond Hill OSM: 10624852 WD: Q3239183 43.64, -79.43 x 43.88, -79.32
    { 3933, 11405, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf57f25} }, // Milton OSM: 10624853 WD: Q3239156 43.52, -79.87 x 43.67, -79.38
    { 3940, 11424, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00853f} }, // Kitchener OSM: 10624854 WD: Q3239126 43.46, -80.49 x 43.71, -79.38
    { 3950, 11446, NoLogo, LineMetaDataContent::RapidTransit, Color{0x003768} }, // Barrie OSM: 10624855 WD: Q3239071 43.64, -79.69 x 44.37, -79.38
    { 3957, 11465, NoLogo, LineMetaDataContent::RapidTransit, Color{0xee3124} }, // Lakeshore East OSM: 10624856 WD: Q3239134 43.64, -79.38 x 43.87, -78.89
    { 675, 11492, NoLogo, LineMetaDataContent::RapidTransit, Color{0x9f142c} }, // 01 OSM: 10647448 WD: Q3239135 43.25, -79.89 x 43.65, -79.38
    { 493, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xfedb00} }, // Y OSM: 10658528 24.98, 121.5 x 25.06, 121.5
    { 3149, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x00ffff} }, // Aqua Line OSM: 10659365 21.11, 79 x 21.14, 79.08
    { 3972, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xadd8e6} }, // LRT OSM: 10693161 WD: Q65762187 -6.193, 106.9 x -6.155, 106.9
    { 3380, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x3e6c01} }, // 102 OSM: 10696526 39.91, -75.3 x 39.96, -75.26
    { 3332, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x3e6c01} }, // 101 OSM: 10696527 39.91, -75.39 x 39.96, -75.26
    { 153, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe6007e} }, // S3 OSM: 10699280 46.95, 15.42 x 47.1, 16.01
    { 65, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x3e6c01} }, // 10 OSM: 10703006 WD: Q839339 39.95, -75.25 x 39.98, -75.16
    { 1859, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x3e6c01} }, // 34 OSM: 10703188 WD: Q839339 39.94, -75.25 x 39.96, -75.16
    { 1850, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x3e6c01} }, // 36 OSM: 10703676 WD: Q839339 39.9, -75.24 x 39.96, -75.16
    { 54, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x3e6c01} }, // 11 OSM: 10705415 WD: Q839339 39.92, -75.26 x 39.96, -75.16
    { 58, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x3e6c01} }, // 13 OSM: 10705526 WD: Q839339 39.92, -75.26 x 39.96, -75.16
    { 186, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf39200} }, // S6 OSM: 10748876 46.72, 15.21 x 47.07, 15.48
    { 330, 11519, 1962, LineMetaDataContent::Subway, Color{0x82bb32} }, // M2 OSM: 10760559 WD: Q2519385 45.4, 9.145 x 45.55, 9.44
    { 333, 11539, 1962, LineMetaDataContent::Subway, Color{0xe2e11d} }, // M3 OSM: 10788272 WD: Q2519355 45.43, 9.163 x 45.53, 9.257
    { 260, 11559, 1962, LineMetaDataContent::Subway, Color{0xeb312e} }, // M1 OSM: 10803053 WD: Q2400801 45.46, 9.084 x 45.54, 9.238
    { 130, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x3fbfaa} }, // 15 OSM: 10899251 47.1, 37.62 x 47.12, 37.65
    { 8, NoLogo, 1450, LineMetaDataContent::Subway, Color{0x36b6f1} }, // M4 OSM: 10925800 WD: Q30597405 55.67, 12.56 x 55.71, 12.6
    { 2752, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xed772d} }, // SI OSM: 10956060 WD: Q93546 35.72, 139.2 x 35.91, 139.7
    { 3976, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 221 OSM: 10967056 37, -122.4 x 37.78, -121.6
    { 3980, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 217 OSM: 10967056 37, -122.4 x 37.78, -121.6
    { 481, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x9f26b4} }, // N OSM: 11004619 WD: Q19877104 39.75, -105 x 39.92, -104.9
    { 3984, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xee0011} }, // TrfC OSM: 11041584 53.46, -2.348 x 53.47, -2.267
    { 3989, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xee0011} }, // Corn OSM: 11041584 53.46, -2.348 x 53.47, -2.267
    { 3034, 11579, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // TS OSM: 11065562 WD: Q2791146 35.7, 139.7 x 36.03, 139.8
    { 26, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xffb25b} }, // 16 OSM: 11076299 30.2, 119.7 x 30.27, 120
    { 3994, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // Harbour OSM: 11093104 WD: Q5654835 18.94, 72.83 x 19.07, 73.12
    { 4002, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x252525} }, // JSQ–33 via HOB OSM: 11100813 WD: Q1931652 40.72, -74.06 x 40.75, -73.99
    { 65, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x008000} }, // 10 OSM: 11123255 41.72, 123.3 x 41.86, 123.5
    { 35, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffc0cb} }, // S OSM: 11135401 WD: Q5364907 34.32, 134.1 x 34.34, 134.2
    { 432, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffff00} }, // K OSM: 11135402 WD: Q5371397 34.19, 133.8 x 34.35, 134.1
    { 481, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // N OSM: 11135412 WD: Q5364831 34.27, 134.1 x 34.34, 134.2
    { 160, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa05ea6} }, // 27 OSM: 11151437 59.35, 18.04 x 59.66, 18.27
    { 1090, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa05ea6} }, // 28 OSM: 11151439 59.35, 18.04 x 59.48, 18.31
    { 1284, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa05ea6} }, // 29 OSM: 11151441 59.35, 18.04 x 59.43, 18.1
    { 176, NoLogo, 1354, LineMetaDataContent::Tramway, Color{0xffd800} }, // 24 OSM: 11165877 WD: Q1489900 47.47, 19.07 x 47.5, 19.09
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x7670b3} }, // 6 OSM: 11175874 WD: Q2343376 52.3, 4.867 x 52.34, 4.874
    { 61, 5039, 161, LineMetaDataContent::RapidTransit, Color{} }, // S1 OSM: 11183563 WD: Q2204422 47.15, 9.601 x 47.55, 9.817
    { 153, 5039, 161, LineMetaDataContent::RapidTransit, Color{} }, // S3 OSM: 11185510 WD: Q2204422 47.45, 9.637 x 47.55, 9.754
    { 196, 5039, 161, LineMetaDataContent::RapidTransit, Color{} }, // S4 OSM: 11185615 WD: Q2204422 47.08, 9.816 x 47.15, 9.918
    { 41, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xbe1622} }, // S7 OSM: 11185888 46.96, 15.08 x 47.07, 15.42
    { 79, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf39200} }, // S61 OSM: 11185889 46.72, 15.21 x 47.07, 15.42
    { 4019, NoLogo, 1354, LineMetaDataContent::Tramway, Color{0xffd800} }, // 4-6 OSM: 11219606 WD: Q1490736 47.48, 19.02 x 47.51, 19.07
    { 16, NoLogo, 1354, LineMetaDataContent::Tramway, Color{0xffd800} }, // 2 OSM: 11219608 WD: Q950776 47.47, 19.05 x 47.51, 19.08
    { 4023, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff6319} }, // <F> OSM: 11248274 40.58, -74 x 40.77, -73.78
    { 59, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x9acd32} }, // 3 OSM: 11257190 28.1, 112.9 x 28.25, 113.1
    { 6, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xffff00} }, // 5 OSM: 11257230 28.09, 113 x 28.29, 113.1
};

static constexpr const auto line_data_count = sizeof(line_data) / sizeof(LineMetaDataContent);

static inline constexpr uint16_t Bucket(uint16_t index) { return line_data_count + index; }

static const int16_t line_data_bucketTable[] = {
    1270, 1251, 1267, 1268, 1269, -1,
    387, 390, 1079, 430, 429, 404, 403, -1,
    1154, 1092, 1156, 1161, 1160, -1,
    823, 1909, 261, -1,
    828, 2028, 829, 2027, 826, 2025, 827, 2026, -1,
    407, 393, 817, 818, 1715, -1,
    884, 885, 880, 353, 881, 886, 887, 879, 882, 883, -1,
    1140, 1139, 436, 435, 450, 444, 451, 447, 453, 448, 454, 445, 455, 443, 452, 449, 446, 439, 441, 437, 442, 438, 440, -1,
    427, 2167, 373, -1,
    999, 997, 254, -1,
    414, 418, -1,
    1646, 1180, 1648, 746, -1,
    236, 264, 238, -1,
    1266, 1245, -1,
    1316, 1315, -1,
    1485, 1493, 1318, -1,
    530, 1447, 1375, 263, 299, 1446, -1,
    2323, 2324, 2320, -1,
    636, 639, 640, -1,
    696, 1058, -1,
    761, 762, 1289, 1169, 1166, 1165, -1,
    362, 2119, -1,
    262, 1916, -1,
    1664, 1473, 1665, 1702, 1667, 1924, -1,
    2367, 2009, 2224, -1,
    279, 280, -1,
    2072, 2085, 2091, 2078, 2083, 2067, 2080, 2070, 2084, 2068, 2082, 2069, 2086, 2075, 2088, 2071, 2064, 2065, 2079, 2066, 2077, 2074, 2076, 2090, 2087, 2089, 2081, 2073, 2369, 2368, 2057, 2051, 779, 2060, 787, 2053, 786, 2061, 785, 2054, 784, 2052, 788, 2059, 783, 2058, 782, 2055, 781, 2062, 780, 2056, 778, 2050, 777, 2049, 832, 831, -1,
    2072, 2085, 2091, 2078, 2083, 2067, 2080, 2070, 2084, 2068, 2082, 2069, 2086, 2075, 2088, 2071, 2064, 2065, 2079, 2066, 2077, 2074, 2076, 2090, 2087, 2089, 2081, 2073, 2369, 2368, 2057, 2051, 779, 2060, 787, 2053, 786, 2061, 785, 2054, 784, 2052, 788, 2059, 783, 2058, 782, 2055, 781, 2062, 780, 2056, 778, 2050, 777, 2049, 833, 832, 831, 1283, 822, -1,
    2194, 2193, 815, -1,
    771, 1304, 772, -1,
    888, 555, -1,
    2349, 2346, -1,
    245, 432, 1742, 2303, 732, 1728, 2244, 2170, 433, 1729, -1,
    847, 841, 910, 845, 620, -1,
    1054, 2206, 2207, 1320, 1319, 2208, -1,
    420, 1067, -1,
    1812, 1238, 1634, 1230, 1239, 1241, 1217, 1218, 1215, 1216, 1242, 1182, 1214, 655, -1,
    1389, 980, -1,
    2273, 2274, 2261, 2272, 2260, 2262, -1,
    2261, 2260, 2262, -1,
    648, 200, 1917, 1448, 253, -1,
    1220, 508, 80, 84, 667, 271, 671, 672, 1057, -1,
    1162, 1220, 508, 588, 400, 84, 2298, 669, 670, 671, 672, 1057, 673, 675, 679, 702, 680, 681, -1,
    637, 638, 641, -1,
    694, 1897, 1196, 1896, -1,
    1922, 1051, -1,
    495, 498, 1347, 1874, 1593, 1856, 491, 1884, 1881, 1880, 1886, 1875, 1855, 1854, -1,
    498, 1593, 491, 1880, 836, 837, 1358, -1,
    656, 333, 938, 939, -1,
    1403, 1402, 1401, -1,
    717, 929, -1,
    774, 1829, 819, 143, 144, 1286, -1,
    218, 366, 928, 927, 1381, 1382, -1,
    889, 793, 717, 929, 716, 1596, -1,
    1147, 758, 14, -1,
    242, 243, -1,
    2355, 2099, 2361, 2390, 2108, -1,
    1157, 1159, 1158, 1153, 1155, 1093, -1,
    2040, 2039, -1,
    710, 890, 1003, -1,
    1584, 214, 217, -1,
    1771, 1773, 1772, -1,
    1490, 2100, -1,
    547, 548, 737, 738, -1,
    1689, 1823, -1,
    1346, 2178, -1,
    2104, 2395, -1,
    2106, 2162, -1,
    312, 1624, -1,
    1099, 765, 1879, 413, 322, 323, 419, -1,
    1524, 2225, 2016, 2228, 1787, -1,
    389, 1845, 1714, -1,
    389, 1845, -1,
    2191, 2195, 2196, 2197, 2198, 2199, 2200, -1,
    177, 276, 1876, -1,
    2153, 2152, -1,
    1719, 1726, 1717, 1718, 1720, 1722, 1721, 1723, -1,
    1301, 1303, 1302, -1,
    1061, 1060, -1,
    1467, 1468, 1469, -1,
    2347, 2348, 2345, 2344, 2343, -1,
    1697, 1699, -1,
    2348, 2344, 2343, -1,
    2116, 2118, 2120, 2126, 296, 291, 2150, 2149, 2393, 295, 2163, 2164, 2165, 2161, 1095, 2159, 2146, 249, 408, 567, 297, 1017, 1605, -1,
    2116, 2120, 2126, 295, 2164, 408, -1,
    907, 905, 1978, 1983, 1984, -1,
    894, 202, 201, -1,
    1437, 1438, 1076, -1,
    1647, 1959, 1956, 1598, 1601, 1609, 1606, 1610, 1604, -1,
    1201, 2173, -1,
    227, 2124, 1465, 2125, 1570, 1417, 1486, 1481, 1484, 199, 1329, 1572, 1314, -1,
    1441, 1440, 1444, 921, 922, 1443, 918, 1449, 1418, 709, 504, 1376, -1,
    1434, 1429, 1427, 1430, -1,
    988, 990, -1,
    1957, 2248, 1029, -1,
    1434, 1429, 1427, -1,
    1081, 1087, 1088, 1091, 1090, -1,
    674, 678, 62, 1350, 63, 71, -1,
    676, 756, 1249, 757, 754, -1,
    634, 628, 629, 1045, 632, 635, -1,
    1746, 1354, 1353, -1,
    2364, 2362, 2363, 776, 351, 1944, 2203, 352, 355, 350, 354, 1921, 1943, -1,
    1882, 1998, 1888, 497, -1,
    1882, 1888, -1,
    1921, 1922, -1,
    2386, 2388, -1,
    219, 1275, 22, 16, 838, 839, 119, 1356, 1357, 25, -1,
    81, 82, 83, 926, 89, 343, 36, 47, 30, 49, 1993, 37, 38, 39, 40, 41, 42, 43, 44, -1,
    936, 937, -1,
    982, 983, 215, 985, -1,
    1398, 288, 114, 156, 615, 113, 969, -1,
    1387, 1408, 1374, -1,
    695, 707, 705, 896, -1,
    1200, 527, 1197, 1198, 1130, 1199, 538, 535, 534, 152, 840, -1,
    121, 128, -1,
    98, 75, 77, 141, 79, 139, 849, 1869, -1,
    70, 28, 332, 150, 151, 2002, 66, 1422, 2188, 158, 12, 15, 275, 137, 133, 132, 100, 131, 130, 129, -1,
    70, 332, 150, 151, 2002, 15, -1,
    2214, 97, 298, 311, 1023, 216, -1,
    2103, 2109, -1,
    510, 509, -1,
    739, 735, 821, 740, 876, 877, -1,
    1207, 1102, 1104, -1,
    1542, 1543, -1,
    2296, 2295, 2294, -1,
    1008, 1009, 1007, -1,
    1478, 1479, -1,
    2186, 2254, -1,
    1751, 1754, -1,
    1554, 1553, -1,
    1560, 1599, -1,
    2138, 2142, 2143, 2145, -1,
    465, 479, 490, 464, 477, 478, -1,
    1821, 1817, 1818, 1825, 1847, 1885, 1820, -1,
    1618, 1822, 2117, -1,
    1863, 1858, 1862, 2318, -1,
    650, 789, 1865, -1,
    2092, 2095, -1,
    267, 266, 268, -1,
    1692, 1982, 2114, 2101, 2127, 268, -1,
    2105, 2097, -1,
    1858, 2318, -1,
    1638, 1639, 2171, -1,
    1883, 2315, -1,
    2001, 1050, 1049, 330, -1,
    1761, 2374, -1,
    1878, 1668, 2280, -1,
    1738, 2317, -1,
    933, 932, 934, 1672, -1,
    2316, 1891, -1,
    1360, 1456, 1454, 1455, 1364, 250, 1366, 1451, 1368, 256, 1452, 1453, -1,
    317, 410, 1100, 1098, 2240, 411, 2341, -1,
    1904, 1901, -1,
    1741, 1679, -1,
    1927, 1693, 2204, -1,
    1927, 1934, -1,
    1739, 1657, 1656, -1,
    1927, 1920, -1,
    1852, 1853, -1,
    2380, 2378, -1,
    2047, 1800, 2246, -1,
    2282, 1175, -1,
    241, 210, 251, 0, 53, 1, 209, 565, 281, 282, 564, 566, 120, -1,
    2185, 2184, 2329, -1,
    1968, 1970, -1,
    2190, 2189, 2370, 2201, -1,
    2233, 901, 900, 2231, 2232, 899, 2234, 2230, -1,
    2155, 2154, -1,
    753, 706, 759, 714, -1,
    1461, 1462, 1463, -1,
    1700, 1701, 1698, 1466, -1,
    2215, 1696, 2216, -1,
    2354, 2304, 1743, -1,
    2160, 428, 290, 2218, 2147, 426, 741, 293, 1730, 742, 294, 2132, -1,
    428, 426, 742, -1,
    1528, 1530, -1,
    961, 998, 204, -1,
    203, 1471, -1,
    977, 2180, 619, -1,
    977, 842, 2180, -1,
    1710, 1711, -1,
    2172, 2177, 2175, -1,
    416, 2141, 2237, 417, 415, 1650, 1649, -1,
    1279, 1277, 1762, -1,
    1581, 1580, -1,
    1119, 1635, 1183, 1184, -1,
    485, 483, 484, 1212, -1,
    2339, 2337, 2338, -1,
    747, 748, 751, -1,
    1480, 1494, -1,
    1844, 228, -1,
    917, 920, -1,
    1586, 1585, 255, 345, -1,
    1025, 913, -1,
    1394, 960, 1420, 1632, 1391, 1763, 1392, 1475, 1707, 1001, 1404, 1423, 1766, 1476, 1035, 1424, 1425, 1431, 1432, 1433, -1,
    2306, 2307, -1,
    1143, 320, -1,
    1034, 1044, 891, -1,
    1034, 891, -1,
    2247, 246, 2148, -1,
    1425, 1426, 1432, 1433, -1,
    1997, 246, -1,
    212, 220, 1705, -1,
    591, 1163, -1,
    589, 590, 591, 592, -1,
    944, 1424, 1431, -1,
    1291, 1297, 1850, 1293, 1255, 1257, 1258, 1259, -1,
    1163, 1225, 1228, 1226, -1,
    401, 2289, 395, 396, 398, -1,
    2011, 2012, 1911, -1,
    624, 631, -1,
    1515, 1439, -1,
    1511, 1513, 1830, 1439, -1,
    1659, 1756, -1,
    2248, 2148, -1,
    797, 809, 1419, 808, 573, 812, 810, 811, 804, 805, 806, 814, 807, 486, 499, 481, 487, 501, -1,
    982, 983, 984, -1,
    1273, 1272, 1274, 24, 21, 685, 475, 686, -1,
    402, 682, 683, -1,
    727, 682, 683, 685, 686, -1,
    936, 937, 684, 701, -1,
    684, 701, 572, -1,
    1398, 114, 113, -1,
    192, 569, 531, 568, -1,
    146, 480, 155, 614, 963, -1,
    1835, 1834, 1065, -1,
    1204, 1052, -1,
    1363, 1349, -1,
    532, 775, 1828, 1827, 574, 587, 594, -1,
    532, 775, 1828, 1827, -1,
    608, 609, 611, 610, 612, -1,
    865, 1929, 1930, 866, 872, 858, 864, 862, 873, 867, 874, 703, 763, 1066, -1,
    91, 99, -1,
    123, 124, 125, -1,
    57, 59, 55, -1,
    57, 58, 59, 55, -1,
    1146, 1286, 1288, -1,
    468, 472, 473, 474, 493, 467, 494, -1,
    7, 6, 68, 65, 32, 31, 67, 33, 8, 5, 159, 229, 135, -1,
    1168, 1167, 60, -1,
    1450, 1168, 1167, 912, 909, 1000, 60, 61, -1,
    339, 1237, 336, 1939, 1941, 340, 1790, 511, 1040, -1,
    893, 892, -1,
    1131, 1227, 1908, 1223, 1907, 1224, 1497, 1222, 1344, 1132, 1134, 1498, 1343, 1499, -1,
    2038, 2037, 2036, 2035, 2034, 2032, 2031, 2030, 2045, 2043, 2029, 2042, -1,
    2037, 2036, 2035, 2032, 2031, 2030, 2045, 2043, 2042, -1,
    846, 902, 903, 898, 911, 851, -1,
    665, 659, -1,
    1576, 2381, 2382, -1,
    734, 374, 377, 1348, 378, -1,
    642, 623, 482, 575, 1575, 857, 1574, -1,
    111, 106, 283, -1,
    687, 688, 689, 690, 691, -1,
    1209, 1210, -1,
    1621, 1612, -1,
    1816, 1623, -1,
    1518, 1519, -1,
    1768, 1767, -1,
    1945, 1946, -1,
    1559, 1502, -1,
    544, 545, -1,
    1831, 462, 461, 476, 1371, 488, -1,
    1064, 768, 1399, 649, -1,
    549, 745, -1,
    654, 1861, 2325, -1,
    908, 1027, 1421, 1262, -1,
    265, 1322, 2158, 270, -1,
    1758, 2092, -1,
    2102, 1509, 270, -1,
    1653, 1652, 2394, -1,
    1873, 2024, 2023, 2096, 1351, -1,
    1637, 2279, -1,
    1644, 1627, -1,
    1195, 1663, -1,
    1877, 2111, -1,
    2022, 2021, -1,
    1365, 1785, -1,
    316, 321, 318, 324, 764, 755, -1,
    318, 412, -1,
    1903, 1902, 2063, 1905, -1,
    1919, 1521, -1,
    1626, 1625, -1,
    1190, 1191, -1,
    1190, 2377, 1683, 1191, 1271, 2183, -1,
    1851, 1848, 1503, -1,
    1809, 1808, 1811, -1,
    1786, 1791, 1987, 2222, 1747, 1795, 2373, 1979, 1964, 1794, 1797, -1,
    606, 834, 287, 244, 88, 225, 371, 825, 208, 559, 560, 558, 562, -1,
    154, 153, 957, 959, 1281, -1,
    1369, 1370, -1,
    1246, 1247, -1,
    1192, 178, -1,
    1713, 1724, 1725, -1,
    722, 711, -1,
    1703, 1704, -1,
    1669, 1671, -1,
    2353, 2359, 2360, 2358, 2301, 1740, -1,
    2115, 1732, 1733, 2376, 1386, -1,
    2115, 2160, -1,
    2227, 2151, -1,
    1526, 1527, 1529, 1531, -1,
    507, 853, 998, -1,
    1641, 1640, 1642, -1,
    457, 1333, 1548, -1,
    1280, 1276, 1278, -1,
    940, 1613, -1,
    940, 1620, 1613, 1619, -1,
    284, 1400, 966, -1,
    363, 1342, -1,
    284, 1400, 966, 1406, -1,
    235, 233, 234, 1203, 1202, -1,
    335, 1332, -1,
    1213, 1824, 1814, -1,
    1126, 1923, 1123, 1120, 1121, 1128, 1125, 1124, 1213, 1185, 1824, 1814, 1117, 1118, 1116, -1,
    2265, 2264, 2266, -1,
    2265, 2270, 2264, 2271, 2267, 2266, -1,
    2128, 2129, 2131, 2130, -1,
    2314, 2319, -1,
    916, 915, 1383, 1380, -1,
    916, 1415, 1532, 915, 1563, 1566, 1565, 1562, 1895, 986, 1030, 1564, -1,
    1384, 1377, -1,
    570, 571, -1,
    803, 1042, -1,
    1764, 931, 930, 643, 1407, -1,
    995, 993, 987, 989, 991, -1,
    1021, 1020, 1018, 1019, -1,
    1947, 1069, 1071, 1070, -1,
    1952, 1037, 1960, 1961, 1962, 1963, 1950, 1996, 1951, 1953, 1955, -1,
    1037, 1963, 1951, 1953, 1955, -1,
    173, 175, -1,
    585, 86, 1219, -1,
    1055, 2326, 1056, -1,
    2293, 950, 951, 9, 943, 945, 946, 947, 948, 942, -1,
    1294, 1295, 1298, 1299, 1292, 1849, 1296, -1,
    72, 1031, 73, 303, 1232, 302, -1,
    1300, 1292, 1849, -1,
    1074, 1910, 1083, 1086, 1075, 1085, 1089, 1080, -1,
    1205, 1206, -1,
    1229, 583, 64, 584, -1,
    585, 86, 1219, 1221, -1,
    1173, 1174, -1,
    399, 2291, 397, -1,
    2290, 677, -1,
    1708, 1489, -1,
    1545, 1544, -1,
    1660, 1661, -1,
    500, 1872, -1,
    20, 622, 23, 1264, 1053, -1,
    402, 686, -1,
    725, 726, 402, -1,
    700, 1106, 386, 1107, 967, 1110, 1111, 1112, -1,
    180, 1965, 181, 1966, 285, -1,
    162, 160, 163, 145, 147, 166, 161, 164, 1014, 148, 206, 968, 964, 919, 962, 970, 971, -1,
    192, 193, -1,
    1340, 1413, 1414, -1,
    385, 383, 384, 1336, 382, 381, -1,
    952, 954, -1,
    51, 52, 361, 360, 357, 364, 365, -1,
    869, 1059, -1,
    790, 2235, 1097, 824, 2213, 816, -1,
    182, 189, 183, 184, 185, 187, 423, 870, 792, -1,
    117, 127, 96, 118, 116, -1,
    248, 247, 87, -1,
    1144, 1151, 766, 1152, 1145, 463, 1148, 1149, 1287, -1,
    4, 29, 35, 69, 2, 3, 662, 13, -1,
    1144, 1151, 1152, 1145, 1149, 1287, -1,
    595, 652, 996, 599, 603, 602, 2221, -1,
    359, 358, -1,
    259, 304, 308, 306, 258, 1141, 1142, 307, 74, 257, 1176, -1,
    512, 1937, 348, 337, 2392, 2384, 525, 524, 516, 521, 526, 338, 1004, 213, 523, 519, 514, 520, 518, 421, 1041, 1039, -1,
    1782, 1780, 1839, 1779, 1781, 1976, 1974, 1840, 1838, 1777, 1841, 1975, -1,
    101, 660, 663, 661, 102, 115, 112, 658, 664, -1,
    1311, 1310, 1915, -1,
    1311, 1312, 1308, 1309, 1310, 260, 1915, -1,
    1311, 1312, 1308, 1309, 1310, 260, 2383, 1915, 835, -1,
    536, 537, 528, 533, -1,
    274, 273, -1,
    1005, 1010, 1006, 1013, -1,
    1999, 2121, -1,
    1753, 1752, -1,
    1600, 1568, 1501, -1,
    1588, 1589, -1,
    2137, 2134, 2133, 2139, 2140, 2144, -1,
    2137, 2134, 2133, -1,
    542, 1967, -1,
    1189, 1860, -1,
    470, 422, -1,
    1867, 2093, 1866, -1,
    1024, 325, -1,
    269, 2157, -1,
    2098, 269, -1,
    800, 801, 794, 844, 843, 802, -1,
    1651, 1658, 1655, 1654, -1,
    1048, 2350, -1,
    1614, 1615, -1,
    1675, 1892, -1,
    1622, 1666, -1,
    1631, 1457, 1784, 1932, -1,
    1631, 1457, 2236, -1,
    1472, 1695, 1460, -1,
    1695, 1694, 1919, 1460, -1,
    646, 647, 1179, -1,
    1508, 1507, 1517, -1,
    1801, 1802, 1803, 2229, 1799, 1805, 1804, -1,
    577, 576, 1807, -1,
    2263, 1986, 1988, -1,
    1788, 1798, 1793, 1796, 1789, 1783, 1792, 1972, -1,
    1774, 1776, -1,
    1016, 563, 286, 370, 372, 278, 561, -1,
    2245, 2292, -1,
    1677, 1678, -1,
    380, 1193, 1094, -1,
    551, 552, 553, -1,
    1063, 1062, -1,
    2356, 550, 2357, 2300, 2299, 2302, 431, -1,
    2300, 2299, 431, -1,
    550, 431, -1,
    854, 205, -1,
    855, 854, -1,
    981, 979, -1,
    1734, 2275, -1,
    1926, 1338, 272, 1549, 1546, -1,
    1629, 1630, -1,
    1608, 1597, -1,
    1597, 1628, -1,
    240, 237, -1,
    232, 231, -1,
    1122, 1129, 1113, 1115, 1114, -1,
    223, 693, -1,
    1843, 1842, -1,
    2202, 2168, -1,
    2372, 2371, -1,
    2270, 2271, 2267, -1,
    1569, 1483, -1,
    1569, 1571, -1,
    334, 975, 976, -1,
    1442, 1445, 704, -1,
    1390, 1393, 1395, -1,
    174, 176, -1,
    174, 176, 1284, -1,
    1706, 221, 458, -1,
    871, 1260, 1261, 301, -1,
    1031, 1255, -1,
    1073, 1084, 1077, 1072, 1078, -1,
    85, 586, -1,
    723, 1250, 743, 1240, -1,
    1914, 1913, 1912, -1,
    1900, 1980, -1,
    1234, 1236, -1,
    1670, 1686, -1,
    1361, 1362, 1359, -1,
    1361, 1362, -1,
    1514, 1512, 859, -1,
    1514, 1512, -1,
    169, 172, 1594, -1,
    1994, 172, 46, 48, 50, 1594, -1,
    169, 48, 50, -1,
    724, 2226, 728, -1,
    1108, 1109, -1,
    937, 1108, 1110, -1,
    924, 341, 604, 925, 342, 2327, -1,
    165, 736, 607, -1,
    149, 194, -1,
    1204, 651, -1,
    2015, 356, -1,
    863, 868, -1,
    17, 18, -1,
    425, 188, 861, -1,
    94, 95, 93, -1,
    76, 140, -1,
    56, 719, -1,
    56, 54, 719, -1,
    1150, 1186, -1,
    171, 27, 582, -1,
    600, 601, -1,
    300, 2253, 2366, -1,
    517, 1187, 522, 369, 319, -1,
    424, 653, 540, 539, 459, -1,
    517, 369, -1,
    1306, 1307, 1312, -1,
    1306, 1307, -1,
    860, 375, 376, -1,
    1101, 1208, 1105, 2238, -1,
    1101, 1208, 1103, 1105, 2238, -1,
    1011, 1012, -1,
    767, 108, -1,
    103, 105, 104, 1313, 107, 767, 108, 109, 110, -1,
    1583, 1582, -1,
    1588, 1589, 1590, -1,
    2136, 2135, -1,
    1323, 1324, 1325, 1327, 1253, 1326, 1254, -1,
    1323, 1324, 1325, 1327, 1253, 1326, 1254, 1335, 1334, 2166, 1328, -1,
    1495, 1552, -1,
    2263, 580, -1,
    349, 211, 471, -1,
    578, 1252, 956, 955, -1,
    852, 856, -1,
    1341, 1397, 2003, -1,
    2334, 2335, -1,
    239, 237, -1,
    692, 1172, -1,
    626, 630, -1,
    1150, 766, -1,
    506, 195, 503, -1,
    506, 503, -1,
    597, 596, -1,
    347, 1940, 346, -1,
    368, 2391, 347, 1940, 367, -1,
    2046, 2041, -1,
    1312, 1308, -1,
    1308, 260, -1,
    1101, 1208, -1,
    1325, 1327, 1326, -1,
    1464, 1938, 328, 773, 1405, 329, 1949, -1,
};

static const constexpr LineMetaDataQuadTreeDepthIndex line_data_depthOffsets[] = {
    { 27, 0 },
    { 26, 1 },
    { 25, 8 },
    { 24, 45 },
    { 23, 124 },
    { 22, 301 },
    { 21, 571 },
    { 20, 870 },
    { 19, 1132 },
    { 18, 1257 },
    { 17, 1311 },
    { 16, 1365 },
};

static const constexpr LineMetaDataZIndex line_data_zquadtree[] = {
    { 227, Bucket(0) }, // 30.8, -5.517 x 44.22, 7.905
    { 390, 388 }, // 30.8, -119.6 x 37.51, -112.9
    { 397, 1931 }, // 37.51, -112.9 x 44.22, -106.2
    { 400, 1673 }, // 44.22, -126.3 x 50.93, -119.6
    { 431, Bucket(6) }, // 37.51, -79.34 x 44.22, -72.63
    { 773, 1079 }, // 37.51, -72.63 x 44.22, -65.91
    { 946, Bucket(14) }, // 44.22, 14.62 x 50.93, 21.33
    { 950, Bucket(20) }, // 57.64, 14.62 x 64.35, 21.33
    { 1555, Bucket(24) }, // 34.15, -123 x 37.51, -119.6
    { 1558, Bucket(24) }, // 37.51, -123 x 40.86, -119.6
    { 1560, Bucket(33) }, // 30.8, -119.6 x 34.15, -116.2
    { 1561, 1715 }, // 34.15, -119.6 x 37.51, -116.2
    { 1695, Bucket(39) }, // 40.86, -89.4 x 44.22, -86.05
    { 1724, Bucket(50) }, // 37.51, -79.34 x 40.86, -75.98
    { 1726, Bucket(74) }, // 37.51, -75.98 x 40.86, -72.63
    { 1727, 391 }, // 40.86, -75.98 x 44.22, -72.63
    { 2314, 254 }, // -36.31, -62.56 x -32.96, -59.2
    { 2336, Bucket(78) }, // -36.31, -59.2 x -32.96, -55.85
    { 3093, Bucket(82) }, // 40.86, -72.63 x 44.22, -69.27
    { 3636, Bucket(85) }, // 37.51, -5.517 x 40.86, -2.162
    { 3638, Bucket(90) }, // 37.51, -2.162 x 40.86, 1.194
    { 3645, Bucket(94) }, // 40.86, 1.194 x 44.22, 4.549
    { 3683, 1318 }, // 47.57, -2.162 x 50.93, 1.194
    { 3685, Bucket(97) }, // 54.28, -5.517 x 57.64, -2.162
    { 3686, Bucket(100) }, // 50.93, -2.162 x 54.28, 1.194
    { 3689, Bucket(104) }, // 47.57, 1.194 x 50.93, 4.549
    { 3690, Bucket(111) }, // 44.22, 4.549 x 47.57, 7.905
    { 3692, 923 }, // 50.93, 1.194 x 54.28, 4.549
    { 3735, Bucket(115) }, // 40.86, 11.26 x 44.22, 14.62
    { 3764, 1898 }, // 37.51, 21.33 x 40.86, 24.68
    { 3780, Bucket(119) }, // 50.93, 7.905 x 54.28, 11.26
    { 3782, 718 }, // 50.93, 11.26 x 54.28, 14.62
    { 3785, Bucket(122) }, // 47.57, 14.62 x 50.93, 17.97
    { 3788, Bucket(129) }, // 50.93, 14.62 x 54.28, 17.97
    { 3800, Bucket(132) }, // 57.64, 14.62 x 60.99, 17.97
    { 3802, Bucket(132) }, // 57.64, 17.97 x 60.99, 21.33
    { 9285, 2257 }, // 54.28, 34.75 x 57.64, 38.1
    { 9771, 2094 }, // 20.73, 111.9 x 24.09, 115.3
    { 9863, 2283 }, // 27.44, 118.6 x 30.8, 122
    { 9875, 2311 }, // 34.15, 118.6 x 37.51, 122
    { 9883, Bucket(135) }, // 34.15, 125.3 x 37.51, 128.7
    { 9886, Bucket(135) }, // 37.51, 125.3 x 40.86, 128.7
    { 9915, Bucket(142) }, // 34.15, 138.8 x 37.51, 142.1
    { 10325, Bucket(146) }, // -39.67, 142.1 x -36.31, 145.5
    { 10327, 280 }, // -39.67, 145.5 x -36.31, 148.8
    { 3830, 1520 }, // -12.82, -77.66 x -11.15, -75.98
    { 6221, Bucket(149) }, // 35.83, -123 x 37.51, -121.3
    { 6232, Bucket(208) }, // 37.51, -123 x 39.18, -121.3
    { 6243, Bucket(270) }, // 32.47, -117.9 x 34.15, -116.2
    { 6337, 405 }, // 32.47, -112.9 x 34.15, -111.2
    { 6723, Bucket(274) }, // 32.47, -97.79 x 34.15, -96.11
    { 6782, Bucket(278) }, // 40.86, -87.73 x 42.54, -86.05
    { 6879, Bucket(281) }, // 42.54, -81.01 x 44.22, -79.34
    { 6898, 489 }, // 37.51, -77.66 x 39.18, -75.98
    { 6905, Bucket(284) }, // 39.18, -75.98 x 40.86, -74.3
    { 6907, 1082 }, // 39.18, -74.3 x 40.86, -72.63
    { 6922, 668 }, // 44.22, -94.44 x 45.9, -92.76
    { 7082, 1992 }, // 44.22, -74.3 x 45.9, -72.63
    { 9345, 207 }, // -34.64, -59.2 x -32.96, -57.53
    { 9407, Bucket(295) }, // -24.57, -47.46 x -22.89, -45.78
    { 9751, Bucket(301) }, // -24.57, -44.1 x -22.89, -42.43
    { 9794, Bucket(301) }, // -22.89, -44.1 x -21.21, -42.43
    { 11817, 2176 }, // -34.64, 17.97 x -32.96, 19.65
    { 12372, Bucket(308) }, // 40.86, -72.63 x 42.54, -70.95
    { 14551, 1412 }, // 42.54, -3.839 x 44.22, -2.162
    { 14558, 1435 }, // 40.86, -0.4838 x 42.54, 1.194
    { 14580, Bucket(311) }, // 40.86, 1.194 x 42.54, 2.872
    { 14651, Bucket(326) }, // 52.61, -7.195 x 54.28, -5.517
    { 14739, Bucket(329) }, // 52.61, -3.839 x 54.28, -2.162
    { 14745, Bucket(336) }, // 52.61, -2.162 x 54.28, -0.4838
    { 14756, Bucket(340) }, // 47.57, 1.194 x 49.25, 2.872
    { 14759, 1428 }, // 49.25, 2.872 x 50.93, 4.549
    { 14762, 1051 }, // 44.22, 6.227 x 45.9, 7.905
    { 14766, 271 }, // 47.57, 6.227 x 49.25, 7.905
    { 14767, Bucket(346) }, // 49.25, 6.227 x 50.93, 7.905
    { 14770, 1428 }, // 50.93, 2.872 x 52.61, 4.549
    { 14778, Bucket(356) }, // 50.93, 6.227 x 52.61, 7.905
    { 14940, Bucket(375) }, // 40.86, 11.26 x 42.54, 12.94
    { 15031, 820 }, // 29.12, 29.72 x 30.8, 31.39
    { 15058, Bucket(379) }, // 37.51, 23 x 39.18, 24.68
    { 15089, 1643 }, // 39.18, 28.04 x 40.86, 29.72
    { 15104, Bucket(384) }, // 44.22, 7.905 x 45.9, 9.583
    { 15105, Bucket(387) }, // 45.9, 7.905 x 47.57, 9.583
    { 15108, Bucket(402) }, // 47.57, 7.905 x 49.25, 9.583
    { 15109, Bucket(410) }, // 49.25, 7.905 x 50.93, 9.583
    { 15111, 621 }, // 49.25, 9.583 x 50.93, 11.26
    { 15113, 878 }, // 45.9, 11.26 x 47.57, 12.94
    { 15115, Bucket(415) }, // 45.9, 12.94 x 47.57, 14.62
    { 15117, Bucket(419) }, // 49.25, 11.26 x 50.93, 12.94
    { 15119, Bucket(422) }, // 49.25, 12.94 x 50.93, 14.62
    { 15121, Bucket(429) }, // 52.61, 7.905 x 54.28, 9.583
    { 15128, Bucket(436) }, // 50.93, 11.26 x 52.61, 12.94
    { 15129, 721 }, // 52.61, 11.26 x 54.28, 12.94
    { 15130, Bucket(443) }, // 50.93, 12.94 x 52.61, 14.62
    { 15132, Bucket(447) }, // 54.28, 11.26 x 55.96, 12.94
    { 15137, Bucket(450) }, // 45.9, 14.62 x 47.57, 16.29
    { 15140, 2108 }, // 47.57, 14.62 x 49.25, 16.29
    { 15142, 1164 }, // 47.57, 16.29 x 49.25, 17.97
    { 15145, Bucket(456) }, // 45.9, 17.97 x 47.57, 19.65
    { 15148, 1155 }, // 47.57, 17.97 x 49.25, 19.65
    { 15160, Bucket(463) }, // 50.93, 17.97 x 52.61, 19.65
    { 15171, Bucket(466) }, // 59.32, 9.583 x 60.99, 11.26
    { 15271, Bucket(470) }, // 49.25, 29.72 x 50.93, 31.39
    { 36159, Bucket(474) }, // 2.275, 100.2 x 3.952, 101.9
    { 36246, Bucket(478) }, // 0.597, 103.5 x 2.275, 105.2
    { 37142, 2258 }, // 54.28, 36.43 x 55.96, 38.1
    { 37276, Bucket(481) }, // 54.28, 51.53 x 55.96, 53.2
    { 37526, 1973 }, // 27.44, 76.69 x 29.12, 78.37
    { 37631, 1935 }, // 42.54, 86.76 x 44.22, 88.44
    { 39056, Bucket(486) }, // 24.09, 101.9 x 25.76, 103.5
    { 39085, Bucket(489) }, // 22.41, 111.9 x 24.09, 113.6
    { 39100, Bucket(492) }, // 27.44, 111.9 x 29.12, 113.6
    { 39103, Bucket(495) }, // 29.12, 113.6 x 30.8, 115.3
    { 39162, 1616 }, // 37.51, 113.6 x 39.18, 115.3
    { 39493, 2241 }, // 35.83, 115.3 x 37.51, 117
    { 39496, 2020 }, // 30.8, 118.6 x 32.47, 120.3
    { 39498, Bucket(498) }, // 30.8, 120.3 x 32.47, 122
    { 39505, Bucket(501) }, // 39.18, 115.3 x 40.86, 117
    { 39514, 1744 }, // 37.51, 120.3 x 39.18, 122
    { 39660, Bucket(509) }, // 34.15, 138.8 x 35.83, 140.4
    { 39679, 1775 }, // 42.54, 140.4 x 44.22, 142.1
    { 41819, 1231 }, // -41.35, 174 x -39.67, 175.7
    { 41823, 10 }, // -37.99, 174 x -36.31, 175.7
    { 42019, 2006 }, // -34.64, 150.5 x -32.96, 152.2
    { 12287, 1373 }, // -37.15, -73.46 x -36.31, -72.63
    { 16292, 469 }, // 5.63, -75.98 x 6.469, -75.14
    { 24928, 830 }, // 37.51, -123 x 38.35, -122.1
    { 24967, Bucket(515) }, // 33.31, -118.8 x 34.15, -117.9
    { 24972, 644 }, // 32.47, -117.9 x 33.31, -117.1
    { 24978, Bucket(519) }, // 34.15, -118.8 x 34.99, -117.9
    { 25542, Bucket(522) }, // 39.18, -105.3 x 40.02, -104.5
    { 25633, Bucket(530) }, // 45.06, -123 x 45.9, -122.1
    { 25637, 2230 }, // 46.73, -123 x 47.57, -122.1
    { 25789, 2153 }, // 50.09, -114.6 x 50.93, -113.7
    { 25832, Bucket(534) }, // 50.93, -114.6 x 51.77, -113.7
    { 26628, Bucket(537) }, // 19.05, -99.47 x 19.89, -98.63
    { 26711, 2336 }, // 29.96, -98.63 x 30.8, -97.79
    { 26717, 2336 }, // 29.96, -97.79 x 30.8, -96.95
    { 26892, 2340 }, // 32.47, -97.79 x 33.31, -96.95
    { 26894, Bucket(546) }, // 32.47, -96.95 x 33.31, -96.11
    { 27399, Bucket(550) }, // 33.31, -85.21 x 34.15, -84.37
    { 27405, Bucket(550) }, // 33.31, -84.37 x 34.15, -83.53
    { 27503, Bucket(553) }, // 40.02, -80.18 x 40.86, -79.34
    { 27519, Bucket(557) }, // 43.38, -80.18 x 44.22, -79.34
    { 27593, Bucket(563) }, // 38.35, -77.66 x 39.18, -76.82
    { 27605, Bucket(566) }, // 43.38, -79.34 x 44.22, -78.5
    { 27620, 2305 }, // 39.18, -75.98 x 40.02, -75.14
    { 27629, Bucket(570) }, // 40.02, -74.3 x 40.86, -73.46
    { 27640, Bucket(594) }, // 40.86, -74.3 x 41.7, -73.46
    { 27690, 1928 }, // 44.22, -93.6 x 45.06, -92.76
    { 28329, Bucket(601) }, // 45.06, -74.3 x 45.9, -73.46
    { 36877, 2107 }, // -33.8, -70.95 x -32.96, -70.11
    { 36901, 935 }, // -33.8, -69.27 x -32.96, -68.43
    { 36912, 935 }, // -32.96, -69.27 x -32.12, -68.43
    { 37380, Bucket(607) }, // -34.64, -59.2 x -33.8, -58.37
    { 37527, 1188 }, // -30.44, -51.65 x -29.6, -50.82
    { 40084, 2212 }, // -4.436, -39.07 x -3.597, -38.23
    { 40112, 2181 }, // -6.114, -35.72 x -5.275, -34.88
    { 49491, 1068 }, // 41.7, -71.79 x 42.54, -70.95
    { 57767, Bucket(611) }, // 33.31, -8.034 x 34.15, -7.195
    { 57791, 1577 }, // 36.67, -6.356 x 37.51, -5.517
    { 57803, 1547 }, // 38.35, -9.711 x 39.18, -8.872
    { 57840, 1290 }, // 40.86, -8.872 x 41.7, -8.034
    { 58189, Bucket(615) }, // 40.02, -3.839 x 40.86, -3
    { 58214, 1201 }, // 39.18, -1.323 x 40.02, -0.4838
    { 58217, 314 }, // 38.35, -0.4838 x 39.18, 0.3551
    { 58220, Bucket(625) }, // 39.18, -0.4838 x 40.02, 0.3551
    { 58226, 505 }, // 40.86, -1.323 x 41.7, -0.4838
    { 58227, 505 }, // 41.7, -1.323 x 42.54, -0.4838
    { 58982, 226 }, // 52.61, -1.323 x 53.45, -0.4838
    { 58984, Bucket(628) }, // 50.93, -0.4838 x 51.77, 0.3551
    { 59027, Bucket(642) }, // 48.41, 2.033 x 49.25, 2.872
    { 59039, Bucket(655) }, // 50.09, 3.711 x 50.93, 4.549
    { 59041, Bucket(660) }, // 45.06, 4.549 x 45.9, 5.388
    { 59046, 2309 }, // 45.9, 5.388 x 46.73, 6.227
    { 59051, 394 }, // 45.06, 7.066 x 45.9, 7.905
    { 59052, 2309 }, // 45.9, 6.227 x 46.73, 7.066
    { 59055, Bucket(663) }, // 46.73, 7.066 x 47.57, 7.905
    { 59070, 682 }, // 49.25, 7.066 x 50.09, 7.905
    { 59082, Bucket(667) }, // 50.93, 3.711 x 51.77, 4.549
    { 59083, 1256 }, // 51.77, 3.711 x 52.61, 4.549
    { 59105, Bucket(671) }, // 51.77, 4.549 x 52.61, 5.388
    { 59112, Bucket(677) }, // 50.93, 6.227 x 51.77, 7.066
    { 59114, Bucket(684) }, // 50.93, 7.066 x 51.77, 7.905
    { 59759, 326 }, // 40.02, 13.78 x 40.86, 14.62
    { 59763, Bucket(690) }, // 41.7, 12.1 x 42.54, 12.94
    { 59770, 326 }, // 40.86, 13.78 x 41.7, 14.62
    { 60232, Bucket(697) }, // 37.51, 23 x 38.35, 23.84
    { 60390, 1755 }, // 39.18, 32.23 x 40.02, 33.07
    { 60419, Bucket(701) }, // 45.06, 8.744 x 45.9, 9.583
    { 60421, Bucket(715) }, // 46.73, 7.905 x 47.57, 8.744
    { 60423, Bucket(720) }, // 46.73, 8.744 x 47.57, 9.583
    { 60425, Bucket(723) }, // 45.06, 9.583 x 45.9, 10.42
    { 60429, Bucket(726) }, // 46.73, 9.583 x 47.57, 10.42
    { 60431, 985 }, // 46.73, 10.42 x 47.57, 11.26
    { 60432, 1998 }, // 47.57, 7.905 x 48.41, 8.744
    { 60433, Bucket(729) }, // 48.41, 7.905 x 49.25, 8.744
    { 60435, Bucket(740) }, // 48.41, 8.744 x 49.25, 9.583
    { 60436, 715 }, // 49.25, 7.905 x 50.09, 8.744
    { 60437, Bucket(760) }, // 50.09, 7.905 x 50.93, 8.744
    { 60438, 686 }, // 49.25, 8.744 x 50.09, 9.583
    { 60442, 288 }, // 47.57, 10.42 x 48.41, 11.26
    { 60443, 621 }, // 48.41, 10.42 x 49.25, 11.26
    { 60446, 191 }, // 49.25, 10.42 x 50.09, 11.26
    { 60453, Bucket(763) }, // 46.73, 11.26 x 47.57, 12.1
    { 60464, Bucket(768) }, // 47.57, 11.26 x 48.41, 12.1
    { 60468, 191 }, // 49.25, 11.26 x 50.09, 12.1
    { 60474, Bucket(776) }, // 47.57, 13.78 x 48.41, 14.62
    { 60476, 953 }, // 49.25, 12.94 x 50.09, 13.78
    { 60477, 1288 }, // 50.09, 12.94 x 50.93, 13.78
    { 60483, 703 }, // 51.77, 8.744 x 52.61, 9.583
    { 60489, Bucket(780) }, // 51.77, 9.583 x 52.61, 10.42
    { 60492, Bucket(782) }, // 52.61, 9.583 x 53.45, 10.42
    { 60493, Bucket(785) }, // 53.45, 9.583 x 54.28, 10.42
    { 60512, 186 }, // 50.93, 11.26 x 51.77, 12.1
    { 60513, Bucket(797) }, // 51.77, 11.26 x 52.61, 12.1
    { 60514, Bucket(800) }, // 50.93, 12.1 x 51.77, 12.94
    { 60516, 128 }, // 52.61, 11.26 x 53.45, 12.1
    { 60519, 720 }, // 53.45, 12.1 x 54.28, 12.94
    { 60521, Bucket(809) }, // 51.77, 12.94 x 52.61, 13.78
    { 60522, 1286 }, // 50.93, 13.78 x 51.77, 14.62
    { 60524, Bucket(830) }, // 52.61, 12.94 x 53.45, 13.78
    { 60531, Bucket(837) }, // 55.12, 12.1 x 55.96, 12.94
    { 60549, Bucket(844) }, // 46.73, 14.62 x 47.57, 15.45
    { 60550, 170 }, // 45.9, 15.45 x 46.73, 16.29
    { 60551, 409 }, // 46.73, 15.45 x 47.57, 16.29
    { 60568, 760 }, // 47.57, 16.29 x 48.41, 17.13
    { 60583, Bucket(847) }, // 46.73, 18.81 x 47.57, 19.65
    { 60594, 510 }, // 47.57, 18.81 x 48.41, 19.65
    { 60651, 277 }, // 51.77, 20.49 x 52.61, 21.33
    { 60686, Bucket(850) }, // 59.32, 10.42 x 60.16, 11.26
    { 60708, 877 }, // 59.32, 11.26 x 60.16, 12.1
    { 60975, Bucket(857) }, // 46.73, 27.2 x 47.57, 28.04
    { 61039, Bucket(861) }, // 53.45, 27.2 x 54.28, 28.04
    { 61085, 978 }, // 50.09, 29.72 x 50.93, 30.55
    { 61112, Bucket(864) }, // 47.57, 33.07 x 48.41, 33.91
    { 61145, Bucket(868) }, // 55.12, 29.72 x 55.96, 30.55
    { 61221, Bucket(872) }, // 60.16, 24.68 x 60.99, 25.52
    { 144877, Bucket(875) }, // 13.18, 100.2 x 14.02, 101
    { 144927, 2156 }, // -3.597, 104.4 x -2.758, 105.2
    { 144984, Bucket(878) }, // 0.597, 103.5 x 1.436, 104.4
    { 148043, 2018 }, // 24.92, 50.69 x 25.76, 51.53
    { 148065, 2018 }, // 24.92, 51.53 x 25.76, 52.36
    { 148161, Bucket(881) }, // 24.92, 54.88 x 25.76, 55.72
    { 148251, Bucket(884) }, // 34.99, 50.69 x 35.83, 51.53
    { 148406, 331 }, // 35.83, 59.08 x 36.67, 59.91
    { 148495, Bucket(887) }, // 46.73, 37.26 x 47.57, 38.1
    { 148571, Bucket(892) }, // 55.12, 37.26 x 55.96, 38.1
    { 149068, 2259 }, // 52.61, 49.85 x 53.45, 50.69
    { 149667, 2375 }, // 18.21, 72.5 x 19.05, 73.34
    { 149670, 2375 }, // 19.05, 72.5 x 19.89, 73.34
    { 149970, 699 }, // 40.86, 69.14 x 41.7, 69.98
    { 150105, Bucket(899) }, // 28.28, 76.69 x 29.12, 77.53
    { 156222, Bucket(907) }, // 22.41, 107.7 x 23.25, 108.6
    { 156253, Bucket(911) }, // 29.96, 103.5 x 30.8, 104.4
    { 156278, Bucket(916) }, // 29.12, 106.1 x 29.96, 106.9
    { 156342, Bucket(920) }, // 22.41, 112.8 x 23.25, 113.6
    { 156343, 2187 }, // 23.25, 112.8 x 24.09, 113.6
    { 156345, Bucket(923) }, // 21.57, 113.6 x 22.41, 114.4
    { 156348, Bucket(927) }, // 22.41, 113.6 x 23.25, 114.4
    { 156413, Bucket(934) }, // 29.96, 113.6 x 30.8, 114.4
    { 156424, Bucket(937) }, // 30.8, 103.5 x 31.63, 104.4
    { 156549, 2171 }, // 33.31, 108.6 x 34.15, 109.4
    { 156560, Bucket(940) }, // 34.15, 108.6 x 34.99, 109.4
    { 156600, 1645 }, // 34.15, 113.6 x 34.99, 114.4
    { 157770, Bucket(944) }, // 24.09, 117.8 x 24.92, 118.6
    { 157777, 1871 }, // 28.28, 115.3 x 29.12, 116.1
    { 157803, Bucket(947) }, // 24.92, 121.2 x 25.76, 122
    { 157815, Bucket(952) }, // 29.96, 119.5 x 30.8, 120.3
    { 157816, 2278 }, // 27.44, 120.3 x 28.28, 121.2
    { 157821, 1761 }, // 29.96, 120.3 x 30.8, 121.2
    { 157822, Bucket(955) }, // 29.12, 121.2 x 29.96, 122
    { 157961, Bucket(959) }, // 31.63, 117 x 32.47, 117.8
    { 157963, 932 }, // 31.63, 117.8 x 32.47, 118.6
    { 157985, Bucket(962) }, // 31.63, 118.6 x 32.47, 119.5
    { 157992, Bucket(967) }, // 30.8, 120.3 x 31.63, 121.2
    { 157994, Bucket(970) }, // 30.8, 121.2 x 31.63, 122
    { 158012, 2310 }, // 35.83, 120.3 x 36.67, 121.2
    { 158022, Bucket(983) }, // 39.18, 116.1 x 40.02, 117
    { 158025, Bucket(991) }, // 38.35, 117 x 39.18, 117.8
    { 158028, 1904 }, // 39.18, 117 x 40.02, 117.8
    { 158059, Bucket(994) }, // 38.35, 121.2 x 39.18, 122
    { 158135, Bucket(997) }, // 36.67, 126.2 x 37.51, 127
    { 158140, 1591 }, // 35.83, 127 x 36.67, 127.9
    { 158141, Bucket(1001) }, // 36.67, 127 x 37.51, 127.9
    { 158163, 1682 }, // 41.7, 122.8 x 42.54, 123.7
    { 158175, Bucket(1004) }, // 43.38, 124.5 x 44.22, 125.3
    { 158177, 1557 }, // 38.35, 125.3 x 39.18, 126.2
    { 158178, Bucket(997) }, // 37.51, 126.2 x 38.35, 127
    { 158184, Bucket(1008) }, // 37.51, 127 x 38.35, 127.9
    { 158197, Bucket(1005) }, // 43.38, 125.3 x 44.22, 126.2
    { 158481, Bucket(1011) }, // 34.99, 128.7 x 35.83, 129.5
    { 158512, 434 }, // 34.15, 132.1 x 34.99, 132.9
    { 158520, Bucket(1014) }, // 34.15, 133.7 x 34.99, 134.6
    { 158608, Bucket(1017) }, // 34.15, 135.4 x 34.99, 136.3
    { 158609, 2246 }, // 34.99, 135.4 x 35.83, 136.3
    { 158643, Bucket(1021) }, // 34.99, 139.6 x 35.83, 140.4
    { 158646, 2223 }, // 35.83, 139.6 x 36.67, 140.4
    { 158696, 1523 }, // 37.51, 140.4 x 38.35, 141.3
    { 165211, 281 }, // -38.83, 144.6 x -37.99, 145.5
    { 165214, Bucket(1024) }, // -37.99, 144.6 x -37.15, 145.5
    { 49148, 1372 }, // -37.15, -73.46 x -36.73, -73.05
    { 64751, 1505 }, // 8.566, -79.76 x 8.986, -79.34
    { 64762, 1505 }, // 8.986, -79.76 x 9.405, -79.34
    { 65169, 848 }, // 6.05, -75.98 x 6.469, -75.56
    { 99549, Bucket(1038) }, // 37.09, -122.1 x 37.51, -121.7
    { 99714, 958 }, // 37.51, -122.5 x 37.93, -122.1
    { 99721, 1846 }, // 37.93, -122.1 x 38.35, -121.7
    { 99726, Bucket(1042) }, // 38.35, -121.7 x 38.77, -121.3
    { 99748, 1970 }, // 38.35, -121.3 x 38.77, -120.9
    { 99871, 1337 }, // 33.73, -118.3 x 34.15, -117.9
    { 101661, 1137 }, // 40.44, -112.1 x 40.86, -111.6
    { 102169, Bucket(1045) }, // 39.6, -105.3 x 40.02, -104.9
    { 102511, 1248 }, // 48.83, -123.4 x 49.25, -123
    { 102522, 1248 }, // 49.25, -123.4 x 49.67, -123
    { 102533, 179 }, // 45.48, -123 x 45.9, -122.5
    { 102594, Bucket(1050) }, // 47.57, -122.5 x 47.99, -122.1
    { 103356, Bucket(1059) }, // 53.45, -113.7 x 53.86, -113.3
    { 106512, 1026 }, // 19.05, -99.47 x 19.47, -99.05
    { 108494, 753 }, // 41.7, -88.14 x 42.12, -87.73
    { 108516, Bucket(1062) }, // 41.7, -87.73 x 42.12, -87.31
    { 109796, 2220 }, // 34.99, -81.01 x 35.41, -80.59
    { 110025, Bucket(1067) }, // 41.28, -81.85 x 41.7, -81.43
    { 110078, 2342 }, // 43.38, -79.76 x 43.8, -79.34
    { 110206, 1136 }, // 36.67, -76.4 x 37.09, -75.98
    { 110375, Bucket(1071) }, // 38.77, -77.24 x 39.18, -76.82
    { 110392, Bucket(1076) }, // 39.18, -76.82 x 39.6, -76.4
    { 110483, Bucket(1080) }, // 39.6, -75.56 x 40.02, -75.14
    { 110486, 1743 }, // 40.02, -75.56 x 40.44, -75.14
    { 110517, Bucket(1084) }, // 40.44, -74.3 x 40.86, -73.88
    { 110519, 2179 }, // 40.44, -73.88 x 40.86, -73.46
    { 110560, Bucket(1097) }, // 40.86, -74.3 x 41.28, -73.88
    { 112810, 2347 }, // 44.22, -79.76 x 44.64, -79.34
    { 113319, 1989 }, // 45.48, -73.88 x 45.9, -73.46
    { 147508, Bucket(1101) }, // -33.8, -70.95 x -33.38, -70.53
    { 149508, 230 }, // -35.47, -59.2 x -35.05, -58.78
    { 149509, 230 }, // -35.05, -59.2 x -34.64, -58.78
    { 149510, 230 }, // -35.47, -58.78 x -35.05, -58.37
    { 149511, Bucket(1104) }, // -35.05, -58.78 x -34.64, -58.37
    { 149522, Bucket(1108) }, // -34.64, -58.78 x -34.22, -58.37
    { 150518, Bucket(1111) }, // -23.73, -47.04 x -23.31, -46.62
    { 150524, Bucket(1115) }, // -23.73, -46.62 x -23.31, -46.2
    { 151432, 1537 }, // -16.18, -48.3 x -15.76, -47.88
    { 152823, Bucket(1119) }, // 10.24, -67.17 x 10.66, -66.75
    { 156712, 2210 }, // -22.89, -43.27 x -22.47, -42.85
    { 157463, 1633 }, // -13.24, -38.65 x -12.82, -38.23
    { 160339, 1285 }, // -4.017, -38.65 x -3.597, -38.23
    { 160450, 2182 }, // -6.114, -35.3 x -5.694, -34.88
    { 188152, 1893 }, // 8.986, 7.066 x 9.405, 7.485
    { 189075, Bucket(1122) }, // -34.22, 18.39 x -33.8, 18.81
    { 196652, 1539 }, // 18.21, -70.11 x 18.63, -69.69
    { 196782, 1133 }, // 18.21, -66.33 x 18.63, -65.91
    { 197967, Bucket(1126) }, // 42.12, -71.37 x 42.54, -70.95
    { 197989, 417 }, // 42.12, -70.95 x 42.54, -70.53
    { 231214, 2312 }, // 38.35, -9.292 x 38.77, -8.872
    { 231300, 2312 }, // 38.35, -8.872 x 38.77, -8.453
    { 231317, 1762 }, // 40.44, -8.872 x 40.86, -8.453
    { 231360, Bucket(1134) }, // 40.86, -8.872 x 41.28, -8.453
    { 232540, 1579 }, // 36.67, -4.678 x 37.09, -4.259
    { 232565, 1411 }, // 37.09, -3.839 x 37.51, -3.42
    { 232735, 1958 }, // 40.44, -4.259 x 40.86, -3.839
    { 232757, 1603 }, // 40.44, -3.839 x 40.86, -3.42
    { 232938, 1244 }, // 40.86, 0.7745 x 41.28, 1.194
    { 233076, 1474 }, // 36.67, 2.872 x 37.09, 3.291
    { 233242, Bucket(1138) }, // 39.18, 2.452 x 39.6, 2.872
    { 233243, Bucket(1138) }, // 39.6, 2.452 x 40.02, 2.872
    { 233280, 1244 }, // 40.86, 1.194 x 41.28, 1.613
    { 233289, Bucket(1141) }, // 41.28, 2.033 x 41.7, 2.452
    { 233300, Bucket(1146) }, // 43.38, 1.194 x 43.8, 1.613
    { 233340, Bucket(1151) }, // 43.38, 3.711 x 43.8, 4.13
    { 234425, 1388 }, // 53.03, -6.356 x 53.45, -5.936
    { 235593, 2328 }, // 47.99, -4.678 x 48.41, -4.259
    { 235596, 2328 }, // 48.41, -4.678 x 48.83, -4.259
    { 235659, Bucket(1155) }, // 44.64, -0.9032 x 45.06, -0.4838
    { 235671, 616 }, // 47.15, -1.742 x 47.57, -1.323
    { 235709, 897 }, // 47.15, 0.3551 x 47.57, 0.7745
    { 235762, 974 }, // 49.25, -0.06436 x 49.67, 0.3551
    { 235909, 222 }, // 52.19, -2.162 x 52.61, -1.742
    { 235937, Bucket(1159) }, // 51.35, -0.4838 x 51.77, -0.06436
    { 235971, Bucket(1162) }, // 54.7, -1.742 x 55.12, -1.323
    { 236108, 1379 }, // 48.41, 2.033 x 48.83, 2.452
    { 236109, Bucket(1165) }, // 48.83, 2.033 x 49.25, 2.452
    { 236149, Bucket(1168) }, // 50.51, 2.872 x 50.93, 3.291
    { 236158, Bucket(1173) }, // 50.09, 4.13 x 50.51, 4.549
    { 236159, Bucket(1176) }, // 50.51, 4.13 x 50.93, 4.549
    { 236183, 556 }, // 47.15, 4.969 x 47.57, 5.388
    { 236186, Bucket(1197) }, // 45.9, 5.808 x 46.31, 6.227
    { 236191, Bucket(1200) }, // 47.15, 5.808 x 47.57, 6.227
    { 236214, 344 }, // 46.73, 6.647 x 47.15, 7.066
    { 236220, Bucket(1203) }, // 46.73, 7.066 x 47.15, 7.485
    { 236222, Bucket(1207) }, // 46.73, 7.485 x 47.15, 7.905
    { 236223, Bucket(1210) }, // 47.15, 7.485 x 47.57, 7.905
    { 236245, Bucket(1214) }, // 50.51, 4.549 x 50.93, 4.969
    { 236266, Bucket(1219) }, // 47.57, 7.485 x 47.99, 7.905
    { 236270, Bucket(1222) }, // 48.41, 7.485 x 48.83, 7.905
    { 236279, Bucket(1226) }, // 50.51, 6.647 x 50.93, 7.066
    { 236282, 683 }, // 49.25, 7.485 x 49.67, 7.905
    { 236285, Bucket(1229) }, // 50.51, 7.066 x 50.93, 7.485
    { 236330, Bucket(1234) }, // 50.93, 4.13 x 51.35, 4.549
    { 236334, Bucket(1238) }, // 51.77, 4.13 x 52.19, 4.549
    { 236420, 1256 }, // 51.77, 4.549 x 52.19, 4.969
    { 236421, 1894 }, // 52.19, 4.549 x 52.61, 4.969
    { 236422, 2286 }, // 51.77, 4.969 x 52.19, 5.388
    { 236450, Bucket(1247) }, // 50.93, 6.647 x 51.35, 7.066
    { 236451, 401 }, // 51.35, 6.647 x 51.77, 7.066
    { 236457, Bucket(1252) }, // 51.35, 7.066 x 51.77, 7.485
    { 238710, Bucket(1258) }, // 36.67, 10 x 37.09, 10.42
    { 239052, Bucket(1262) }, // 41.7, 12.1 x 42.12, 12.52
    { 239054, 624 }, // 41.7, 12.52 x 42.12, 12.94
    { 241436, 1636 }, // 40.02, 28.88 x 40.44, 29.3
    { 241474, Bucket(1265) }, // 40.86, 28.46 x 41.28, 28.88
    { 241480, Bucket(1268) }, // 40.86, 28.88 x 41.28, 29.3
    { 241563, Bucket(1273) }, // 39.6, 32.65 x 40.02, 33.07
    { 241672, 749 }, // 44.22, 8.744 x 44.64, 9.163
    { 241679, 1942 }, // 45.48, 9.163 x 45.9, 9.583
    { 241685, Bucket(1276) }, // 47.15, 7.905 x 47.57, 8.324
    { 241687, Bucket(1279) }, // 47.15, 8.324 x 47.57, 8.744
    { 241693, 481 }, // 47.15, 8.744 x 47.57, 9.163
    { 241701, 313 }, // 45.48, 9.583 x 45.9, 10
    { 241727, Bucket(1298) }, // 47.15, 10.84 x 47.57, 11.26
    { 241730, 501 }, // 47.57, 8.324 x 47.99, 8.744
    { 241733, 1053 }, // 48.83, 7.905 x 49.25, 8.324
    { 241735, Bucket(1302) }, // 48.83, 8.324 x 49.25, 8.744
    { 241742, 169 }, // 48.41, 9.163 x 48.83, 9.583
    { 241744, Bucket(1312) }, // 49.25, 7.905 x 49.67, 8.324
    { 241746, Bucket(1315) }, // 49.25, 8.324 x 49.67, 8.744
    { 241747, Bucket(1321) }, // 49.67, 8.324 x 50.09, 8.744
    { 241750, Bucket(1326) }, // 50.09, 8.324 x 50.51, 8.744
    { 241752, Bucket(1311) }, // 49.25, 8.744 x 49.67, 9.163
    { 241754, 682 }, // 49.25, 9.163 x 49.67, 9.583
    { 241756, 572 }, // 50.09, 8.744 x 50.51, 9.163
    { 241771, Bucket(1330) }, // 47.99, 10.84 x 48.41, 11.26
    { 241775, 192 }, // 48.83, 10.84 x 49.25, 11.26
    { 241786, Bucket(1334) }, // 49.25, 10.84 x 49.67, 11.26
    { 241798, 289 }, // 45.06, 11.68 x 45.48, 12.1
    { 241813, 984 }, // 47.15, 11.26 x 47.57, 11.68
    { 241821, 982 }, // 47.15, 12.1 x 47.57, 12.52
    { 241822, 1403 }, // 46.73, 12.52 x 47.15, 12.94
    { 241823, 1834 }, // 47.15, 12.52 x 47.57, 12.94
    { 241845, 1834 }, // 47.15, 12.94 x 47.57, 13.36
    { 241855, 2109 }, // 47.15, 14.2 x 47.57, 14.62
    { 241856, 982 }, // 47.57, 11.26 x 47.99, 11.68
    { 241857, Bucket(1339) }, // 47.99, 11.26 x 48.41, 11.68
    { 241858, 982 }, // 47.57, 11.68 x 47.99, 12.1
    { 241859, 155 }, // 47.99, 11.68 x 48.41, 12.1
    { 241860, 1398 }, // 48.41, 11.26 x 48.83, 11.68
    { 241862, 1398 }, // 48.41, 11.68 x 48.83, 12.1
    { 241866, Bucket(1346) }, // 47.57, 12.52 x 47.99, 12.94
    { 241887, Bucket(1349) }, // 50.51, 12.52 x 50.93, 12.94
    { 241888, Bucket(1345) }, // 47.57, 12.94 x 47.99, 13.36
    { 241899, Bucket(1352) }, // 47.99, 14.2 x 48.41, 14.62
    { 241915, Bucket(1355) }, // 49.67, 14.2 x 50.09, 14.62
    { 241918, Bucket(1363) }, // 50.09, 14.2 x 50.51, 14.62
    { 241926, Bucket(1368) }, // 51.77, 8.324 x 52.19, 8.744
    { 241935, 763 }, // 52.19, 9.163 x 52.61, 9.583
    { 241946, 763 }, // 52.61, 9.163 x 53.03, 9.583
    { 241950, 1199 }, // 53.45, 9.163 x 53.86, 9.583
    { 241957, Bucket(1374) }, // 52.19, 9.583 x 52.61, 10
    { 241961, 122 }, // 51.35, 10.42 x 51.77, 10.84
    { 241972, 168 }, // 53.45, 9.583 x 53.86, 10
    { 242056, Bucket(1389) }, // 50.93, 12.1 x 51.35, 12.52
    { 242068, Bucket(1392) }, // 53.45, 11.26 x 53.86, 11.68
    { 242071, Bucket(1396) }, // 53.86, 11.68 x 54.28, 12.1
    { 242077, Bucket(1400) }, // 53.86, 12.1 x 54.28, 12.52
    { 242082, Bucket(1405) }, // 50.93, 13.36 x 51.35, 13.78
    { 242085, Bucket(1409) }, // 52.19, 12.94 x 52.61, 13.36
    { 242087, Bucket(1417) }, // 52.19, 13.36 x 52.61, 13.78
    { 242088, 1146 }, // 50.93, 13.78 x 51.35, 14.2
    { 242198, 2389 }, // 46.73, 15.04 x 47.15, 15.45
    { 242199, 190 }, // 47.15, 15.04 x 47.57, 15.45
    { 242251, Bucket(1431) }, // 47.99, 15.87 x 48.41, 16.29
    { 242273, Bucket(1435) }, // 47.99, 16.29 x 48.41, 16.71
    { 242333, Bucket(1444) }, // 47.15, 18.81 x 47.57, 19.23
    { 242432, Bucket(1454) }, // 50.93, 14.62 x 51.35, 15.04
    { 242471, Bucket(1457) }, // 52.19, 16.71 x 52.61, 17.13
    { 242571, Bucket(1472) }, // 51.35, 19.23 x 51.77, 19.65
    { 242574, Bucket(1485) }, // 51.77, 19.23 x 52.19, 19.65
    { 242591, 613 }, // 53.86, 19.23 x 54.28, 19.65
    { 242745, Bucket(1495) }, // 59.74, 10.42 x 60.16, 10.84
    { 242818, Bucket(1502) }, // 57.64, 11.68 x 58.06, 12.1
    { 243333, 770 }, // 58.9, 17.97 x 59.32, 18.39
    { 243344, Bucket(1505) }, // 59.32, 17.97 x 59.74, 18.39
    { 243833, Bucket(1509) }, // 49.67, 23.84 x 50.09, 24.26
    { 243850, Bucket(1515) }, // 44.22, 25.94 x 44.64, 26.36
    { 244092, 529 }, // 56.8, 23.84 x 57.22, 24.26
    { 244884, Bucket(1523) }, // 60.16, 24.68 x 60.58, 25.1
    { 245299, Bucket(1527) }, // 59.74, 30.13 x 60.16, 30.55
    { 545991, 1210 }, // 8.566, 38.52 x 8.986, 38.94
    { 546002, Bucket(1533) }, // 8.986, 38.52 x 9.405, 38.94
    { 556126, 1602 }, // 9.824, 76.27 x 10.24, 76.69
    { 556339, Bucket(1536) }, // 12.76, 77.11 x 13.18, 77.53
    { 556345, Bucket(1536) }, // 12.76, 77.53 x 13.18, 77.95
    { 556465, Bucket(1539) }, // 12.76, 80.05 x 13.18, 80.47
    { 579509, Bucket(1542) }, // 13.6, 100.2 x 14.02, 100.6
    { 587235, Bucket(1545) }, // 14.44, 120.7 x 14.86, 121.2
    { 590049, 1555 }, // 21.15, 39.78 x 21.57, 40.2
    { 590753, Bucket(1548) }, // 24.5, 46.49 x 24.92, 46.91
    { 592345, 1500 }, // 29.54, 52.36 x 29.96, 52.78
    { 593007, Bucket(1551) }, // 35.41, 51.11 x 35.83, 51.53
    { 593988, 1551 }, // 48.41, 34.75 x 48.83, 35.17
    { 594011, Bucket(1554) }, // 49.67, 36.01 x 50.09, 36.43
    { 594285, Bucket(1557) }, // 55.54, 37.26 x 55.96, 37.68
    { 594287, 2219 }, // 55.54, 37.68 x 55.96, 38.1
    { 596245, Bucket(1564) }, // 53.86, 48.17 x 54.28, 48.59
    { 596288, Bucket(1564) }, // 54.28, 48.17 x 54.7, 48.59
    { 596301, 1533 }, // 55.54, 49.01 x 55.96, 49.43
    { 596423, 549 }, // 55.54, 51.95 x 55.96, 52.36
    { 596429, Bucket(1569) }, // 55.54, 52.36 x 55.96, 52.78
    { 600258, 2351 }, // 20.73, 78.79 x 21.15, 79.21
    { 600420, 1676 }, // 28.28, 76.69 x 28.7, 77.11
    { 600422, 1819 }, // 28.28, 77.11 x 28.7, 77.53
    { 600502, 1864 }, // 26.6, 80.47 x 27.02, 80.89
    { 600508, 1864 }, // 26.6, 80.89 x 27.02, 81.31
    { 600826, 1815 }, // 22.41, 88.02 x 22.83, 88.44
    { 601457, 1556 }, // 42.96, 76.69 x 43.38, 77.11
    { 624908, 750 }, // 24.92, 102.7 x 25.34, 103.1
    { 625015, Bucket(1572) }, // 30.38, 104 x 30.8, 104.4
    { 625051, 1561 }, // 26.18, 106.5 x 26.6, 106.9
    { 625054, 1561 }, // 26.6, 106.5 x 27.02, 106.9
    { 625371, Bucket(1576) }, // 22.83, 113.2 x 23.25, 113.6
    { 625383, Bucket(1581) }, // 21.99, 114 x 22.41, 114.4
    { 625393, Bucket(1586) }, // 22.83, 113.6 x 23.25, 114
    { 625394, Bucket(1589) }, // 22.41, 114 x 22.83, 114.4
    { 625609, Bucket(1593) }, // 27.86, 112.8 x 28.28, 113.2
    { 625655, Bucket(1597) }, // 30.38, 114 x 30.8, 114.4
    { 625776, 2277 }, // 35.83, 103.5 x 36.25, 104
    { 626240, Bucket(1603) }, // 34.15, 108.6 x 34.57, 109
    { 626379, Bucket(1606) }, // 34.57, 113.2 x 34.99, 113.6
    { 626401, Bucket(1606) }, // 34.57, 113.6 x 34.99, 114
    { 626495, 2321 }, // 40.44, 111.5 x 40.86, 111.9
    { 631002, Bucket(1609) }, // 22.41, 119.9 x 22.83, 120.3
    { 631024, Bucket(1609) }, // 22.41, 120.3 x 22.83, 120.7
    { 631110, 1870 }, // 28.28, 115.7 x 28.7, 116.1
    { 631186, 2308 }, // 25.76, 119.1 x 26.18, 119.5
    { 631212, 1385 }, // 24.92, 121.2 x 25.34, 121.6
    { 631262, Bucket(1612) }, // 29.96, 119.9 x 30.38, 120.3
    { 631293, 1785 }, // 30.38, 121.2 x 30.8, 121.6
    { 631844, 1737 }, // 31.63, 117 x 32.05, 117.4
    { 631904, 2276 }, // 34.15, 117 x 34.57, 117.4
    { 631940, 1690 }, // 31.63, 118.6 x 32.05, 119.1
    { 631941, Bucket(1615) }, // 32.05, 118.6 x 32.47, 119.1
    { 631971, 1892 }, // 31.22, 120.7 x 31.63, 121.2
    { 631976, Bucket(1618) }, // 30.8, 121.2 x 31.22, 121.6
    { 632089, Bucket(1621) }, // 39.6, 116.1 x 40.02, 116.5
    { 632092, Bucket(1628) }, // 40.02, 116.1 x 40.44, 116.5
    { 632101, Bucket(1631) }, // 38.77, 117 x 39.18, 117.4
    { 632112, Bucket(1632) }, // 39.18, 117 x 39.6, 117.4
    { 632239, 1687 }, // 38.77, 121.6 x 39.18, 122
    { 632526, 1592 }, // 34.99, 126.6 x 35.41, 127
    { 632543, 1919 }, // 37.09, 126.6 x 37.51, 127
    { 632559, 1626 }, // 35.41, 128.3 x 35.83, 128.7
    { 632565, Bucket(1636) }, // 37.09, 127 x 37.51, 127.4
    { 632570, Bucket(1639) }, // 35.83, 128.3 x 36.25, 128.7
    { 632581, 1687 }, // 38.77, 122 x 39.18, 122.4
    { 632651, Bucket(1642) }, // 41.28, 123.2 x 41.7, 123.7
    { 632654, Bucket(1645) }, // 41.7, 123.2 x 42.12, 123.7
    { 633924, Bucket(1652) }, // 34.99, 128.7 x 35.41, 129.1
    { 634080, 2379 }, // 34.15, 133.7 x 34.57, 134.2
    { 634433, 2249 }, // 34.57, 135.4 x 34.99, 135.8
    { 634446, Bucket(1656) }, // 34.99, 136.7 x 35.41, 137.1
    { 634450, 2256 }, // 35.83, 135.8 x 36.25, 136.3
    { 634567, 2263 }, // 35.41, 139.2 x 35.83, 139.6
    { 634573, Bucket(1660) }, // 35.41, 139.6 x 35.83, 140
    { 634584, 2373 }, // 35.83, 139.6 x 36.25, 140
    { 635535, 1735 }, // 45.48, 126.6 x 45.9, 127
    { 660847, 795 }, // -38.41, 145.1 x -37.99, 145.5
    { 660856, Bucket(1672) }, // -37.99, 144.6 x -37.57, 145.1
    { 669174, 11 }, // -37.15, 174.4 x -36.73, 174.8
    { 669180, 11 }, // -37.15, 174.8 x -36.73, 175.3
    { 672260, 2250 }, // -35.47, 148.8 x -35.05, 149.3
    { 672307, 2122 }, // -34.22, 150.9 x -33.8, 151.4
    { 259050, 2013 }, // 8.986, -79.55 x 9.195, -79.34
    { 398857, Bucket(1686) }, // 37.72, -122.5 x 37.93, -122.3
    { 399485, 1716 }, // 33.94, -118.3 x 34.15, -118.1
    { 403703, Bucket(1692) }, // 20.52, -103.5 x 20.73, -103.2
    { 410047, Bucket(1695) }, // 49.04, -123.2 x 49.25, -123
    { 410090, Bucket(1695) }, // 49.25, -123.2 x 49.46, -123
    { 410131, 1192 }, // 45.27, -122.7 x 45.48, -122.5
    { 410134, Bucket(1698) }, // 45.48, -122.7 x 45.69, -122.5
    { 410389, Bucket(1695) }, // 49.04, -123 x 49.25, -122.7
    { 410432, Bucket(1695) }, // 49.25, -123 x 49.46, -122.7
    { 426051, Bucket(1701) }, // 19.26, -99.26 x 19.47, -99.05
    { 426054, 1727 }, // 19.47, -99.26 x 19.68, -99.05
    { 430305, 791 }, // 32.68, -96.95 x 32.89, -96.74
    { 433978, Bucket(1705) }, // 41.7, -87.94 x 41.91, -87.73
    { 434064, Bucket(1705) }, // 41.7, -87.73 x 41.91, -87.52
    { 435871, Bucket(1708) }, // 25.55, -80.39 x 25.76, -80.18
    { 435914, Bucket(1708) }, // 25.76, -80.39 x 25.97, -80.18
    { 438484, 1063 }, // 33.73, -84.37 x 33.94, -84.16
    { 440315, Bucket(1711) }, // 43.59, -79.55 x 43.8, -79.34
    { 441568, 2217 }, // 39.18, -76.82 x 39.39, -76.61
    { 441681, 1671 }, // 43.59, -79.34 x 43.8, -79.13
    { 441935, Bucket(1714) }, // 39.81, -75.35 x 40.02, -75.14
    { 441957, 1740 }, // 39.81, -75.14 x 40.02, -74.93
    { 442069, 2174 }, // 40.65, -74.3 x 40.86, -74.09
    { 442071, Bucket(1721) }, // 40.65, -74.09 x 40.86, -73.88
    { 442242, Bucket(1727) }, // 40.86, -74.09 x 41.07, -73.88
    { 443047, 666 }, // 44.85, -93.39 x 45.06, -93.18
    { 453139, Bucket(1730) }, // 45.27, -75.77 x 45.48, -75.56
    { 590035, Bucket(1733) }, // -33.59, -70.74 x -33.38, -70.53
    { 598044, 230 }, // -35.05, -58.78 x -34.84, -58.57
    { 598046, 230 }, // -35.05, -58.57 x -34.84, -58.37
    { 598047, 207 }, // -34.84, -58.57 x -34.64, -58.37
    { 598069, 207 }, // -34.84, -58.37 x -34.64, -58.16
    { 598090, Bucket(1738) }, // -34.64, -58.57 x -34.43, -58.37
    { 602074, 972 }, // -23.73, -46.83 x -23.52, -46.62
    { 605731, 1538 }, // -15.97, -48.09 x -15.76, -47.88
    { 611292, 1832 }, // 10.24, -67.17 x 10.45, -66.96
    { 611295, 1709 }, // 10.45, -66.96 x 10.66, -66.75
    { 624095, 1321 }, // -23.1, -43.48 x -22.89, -43.27
    { 624117, 1321 }, // -23.1, -43.27 x -22.89, -43.06
    { 626849, 2205 }, // -22.68, -43.27 x -22.47, -43.06
    { 626900, 1282 }, // -19.96, -44.1 x -19.75, -43.89
    { 629853, 1352 }, // -13.03, -38.65 x -12.82, -38.44
    { 630271, 1339 }, // -9.679, -35.93 x -9.469, -35.72
    { 639724, 2331 }, // -7.372, -39.49 x -7.162, -39.28
    { 641357, 2211 }, // -3.807, -38.65 x -3.597, -38.44
    { 641566, Bucket(1742) }, // -8.211, -35.09 x -8.001, -34.88
    { 641615, 2333 }, // -7.162, -35.09 x -6.953, -34.88
    { 641637, 2333 }, // -7.162, -34.88 x -6.953, -34.67
    { 752610, 2014 }, // 8.986, 7.276 x 9.195, 7.485
    { 786609, 1540 }, // 18.42, -70.11 x 18.63, -69.9
    { 791871, 1032 }, // 42.33, -71.16 x 42.54, -70.95
    { 918960, 90 }, // 28.28, -16.42 x 28.49, -16.21
    { 924375, 1171 }, // 33.94, -6.985 x 34.15, -6.775
    { 924857, Bucket(1746) }, // 38.56, -9.292 x 38.77, -9.082
    { 925443, Bucket(1750) }, // 41.07, -8.663 x 41.28, -8.453
    { 930939, Bucket(1754) }, // 40.23, -4.049 x 40.44, -3.839
    { 931025, Bucket(1757) }, // 40.23, -3.839 x 40.44, -3.63
    { 931028, 1619 }, // 40.44, -3.839 x 40.65, -3.63
    { 931279, Bucket(1762) }, // 43.17, -3.21 x 43.38, -3
    { 931299, Bucket(1766) }, // 42.75, -2.791 x 42.96, -2.581
    { 931301, Bucket(1769) }, // 43.17, -3 x 43.38, -2.791
    { 931364, 965 }, // 37.93, -1.323 x 38.14, -1.113
    { 931435, 1202 }, // 39.39, -0.6935 x 39.6, -0.4838
    { 931521, Bucket(1774) }, // 39.39, -0.4838 x 39.6, -0.2741
    { 932306, Bucket(1780) }, // 36.67, 3.081 x 36.88, 3.291
    { 933134, Bucket(1783) }, // 41.28, 1.823 x 41.49, 2.033
    { 933156, Bucket(1787) }, // 41.28, 2.033 x 41.49, 2.243
    { 933711, 224 }, // 43.17, 5.179 x 43.38, 5.388
    { 933733, 224 }, // 43.17, 5.388 x 43.38, 5.598
    { 933873, 2252 }, // 43.59, 7.066 x 43.8, 7.276
    { 942684, 617 }, // 47.15, -1.742 x 47.36, -1.532
    { 942719, 914 }, // 47.36, -0.6935 x 47.57, -0.4838
    { 942860, 1015 }, // 47.99, -1.742 x 48.2, -1.532
    { 943082, 731 }, // 49.25, 0.9842 x 49.46, 1.194
    { 943343, Bucket(1803) }, // 53.24, -2.371 x 53.45, -2.162
    { 943354, Bucket(1807) }, // 53.45, -2.371 x 53.65, -2.162
    { 943415, 1550 }, // 55.75, -4.468 x 55.96, -4.259
    { 943421, 1550 }, // 55.75, -4.259 x 55.96, -4.049
    { 943695, Bucket(1814) }, // 53.24, -1.532 x 53.45, -1.323
    { 943713, 579 }, // 52.82, -1.323 x 53.03, -1.113
    { 943750, 1482 }, // 51.35, -0.2741 x 51.56, -0.06436
    { 943756, 1573 }, // 51.35, -0.06436 x 51.56, 0.1454
    { 944279, 1995 }, // 45.69, 3.081 x 45.9, 3.291
    { 944395, Bucket(1819) }, // 47.78, 1.823 x 47.99, 2.033
    { 944435, Bucket(1822) }, // 48.62, 2.243 x 48.83, 2.452
    { 944438, Bucket(1827) }, // 48.83, 2.243 x 49.04, 2.452
    { 944444, Bucket(1840) }, // 48.83, 2.452 x 49.04, 2.662
    { 944567, Bucket(1843) }, // 49.04, 3.92 x 49.25, 4.13
    { 944603, 1470 }, // 50.3, 3.501 x 50.51, 3.711
    { 944610, Bucket(1843) }, // 49.25, 3.92 x 49.46, 4.13
    { 944635, Bucket(1846) }, // 50.3, 4.34 x 50.51, 4.549
    { 944639, Bucket(1849) }, // 50.72, 4.34 x 50.93, 4.549
    { 944663, Bucket(1855) }, // 45.69, 4.759 x 45.9, 4.969
    { 944690, Bucket(1861) }, // 45.06, 5.598 x 45.27, 5.808
    { 944732, 557 }, // 47.15, 4.969 x 47.36, 5.179
    { 944747, Bucket(1866) }, // 46.11, 6.017 x 46.31, 6.227
    { 944893, Bucket(1871) }, // 47.36, 7.485 x 47.57, 7.695
    { 945003, 1567 }, // 49.46, 6.017 x 49.67, 6.227
    { 945064, Bucket(1883) }, // 47.57, 7.485 x 47.78, 7.695
    { 945067, Bucket(1889) }, // 47.78, 7.695 x 47.99, 7.905
    { 945070, Bucket(1889) }, // 47.99, 7.695 x 48.2, 7.905
    { 945119, Bucket(1892) }, // 50.72, 6.856 x 50.93, 7.066
    { 945290, Bucket(1896) }, // 50.93, 3.501 x 51.14, 3.711
    { 945312, Bucket(1896) }, // 50.93, 3.711 x 51.14, 3.92
    { 945323, Bucket(1900) }, // 51.14, 4.34 x 51.35, 4.549
    { 945337, Bucket(1911) }, // 51.98, 4.13 x 52.19, 4.34
    { 945338, Bucket(1919) }, // 51.77, 4.34 x 51.98, 4.549
    { 945339, Bucket(1926) }, // 51.98, 4.34 x 52.19, 4.549
    { 945680, 1257 }, // 51.77, 4.549 x 51.98, 4.759
    { 945686, Bucket(1930) }, // 52.19, 4.759 x 52.4, 4.969
    { 945689, Bucket(1939) }, // 51.98, 4.969 x 52.19, 5.179
    { 945801, Bucket(1942) }, // 51.14, 6.647 x 51.35, 6.856
    { 945802, Bucket(1947) }, // 50.93, 6.856 x 51.14, 7.066
    { 945806, Bucket(1952) }, // 51.35, 6.856 x 51.56, 7.066
    { 945828, Bucket(1955) }, // 51.35, 7.066 x 51.56, 7.276
    { 945830, Bucket(1959) }, // 51.35, 7.276 x 51.56, 7.485
    { 954840, 1906 }, // 36.67, 10 x 36.88, 10.21
    { 956328, 2268 }, // 40.86, 14.2 x 41.07, 14.41
    { 957833, 895 }, // 41.07, 16.71 x 41.28, 16.92
    { 962042, Bucket(1962) }, // 29.96, 31.18 x 30.17, 31.39
    { 963726, 1745 }, // 37.93, 23.63 x 38.14, 23.84
    { 964034, Bucket(1965) }, // 42.54, 23.21 x 42.75, 23.42
    { 964250, 1757 }, // 38.35, 26.99 x 38.56, 27.2
    { 964272, 1757 }, // 38.35, 27.2 x 38.56, 27.41
    { 965920, 859 }, // 40.86, 28.88 x 41.07, 29.09
    { 966253, Bucket(1968) }, // 39.81, 32.65 x 40.02, 32.86
    { 966741, 2247 }, // 47.36, 7.905 x 47.57, 8.115
    { 966751, Bucket(1971) }, // 47.36, 8.534 x 47.57, 8.744
    { 966773, 1887 }, // 47.36, 8.744 x 47.57, 8.953
    { 966869, 2387 }, // 47.36, 9.583 x 47.57, 9.792
    { 966922, 500 }, // 47.57, 8.534 x 47.78, 8.744
    { 966940, Bucket(1974) }, // 48.83, 8.324 x 49.04, 8.534
    { 966941, 1053 }, // 49.04, 8.324 x 49.25, 8.534
    { 966942, 1053 }, // 48.83, 8.534 x 49.04, 8.744
    { 966944, 1887 }, // 47.57, 8.744 x 47.78, 8.953
    { 966964, 686 }, // 48.83, 8.744 x 49.04, 8.953
    { 966965, Bucket(1980) }, // 49.04, 8.744 x 49.25, 8.953
    { 966966, 172 }, // 48.83, 8.953 x 49.04, 9.163
    { 966967, Bucket(1980) }, // 49.04, 8.953 x 49.25, 9.163
    { 966972, 172 }, // 48.83, 9.163 x 49.04, 9.373
    { 966973, 686 }, // 49.04, 9.163 x 49.25, 9.373
    { 966975, 686 }, // 49.04, 9.373 x 49.25, 9.583
    { 966983, 936 }, // 49.88, 8.115 x 50.09, 8.324
    { 966986, Bucket(1983) }, // 49.25, 8.534 x 49.46, 8.744
    { 967002, Bucket(1987) }, // 50.09, 8.534 x 50.3, 8.744
    { 967013, 936 }, // 49.88, 8.744 x 50.09, 8.953
    { 967024, 936 }, // 50.09, 8.744 x 50.3, 8.953
    { 967071, 621 }, // 49.04, 10.21 x 49.25, 10.42
    { 967082, 982 }, // 47.57, 11.05 x 47.78, 11.26
    { 967085, 605 }, // 48.2, 10.84 x 48.41, 11.05
    { 967146, 193 }, // 49.25, 11.05 x 49.46, 11.26
    { 967252, Bucket(1996) }, // 47.15, 11.26 x 47.36, 11.47
    { 967279, 1403 }, // 46.52, 12.73 x 46.73, 12.94
    { 967430, Bucket(2002) }, // 47.99, 11.47 x 48.2, 11.68
    { 967467, 1836 }, // 47.78, 12.73 x 47.99, 12.94
    { 967488, Bucket(2020) }, // 49.25, 11.26 x 49.46, 11.47
    { 967551, Bucket(2023) }, // 50.72, 12.73 x 50.93, 12.94
    { 967553, 1836 }, // 47.78, 12.94 x 47.99, 13.15
    { 967597, Bucket(2027) }, // 48.2, 14.2 x 48.41, 14.41
    { 967628, Bucket(2034) }, // 49.67, 13.36 x 49.88, 13.57
    { 967637, Bucket(2024) }, // 50.72, 12.94 x 50.93, 13.15
    { 967663, 142 }, // 49.88, 14.41 x 50.09, 14.62
    { 967674, 142 }, // 50.09, 14.41 x 50.3, 14.62
    { 967742, 1059 }, // 52.19, 9.373 x 52.4, 9.583
    { 967780, Bucket(2037) }, // 53.03, 8.744 x 53.24, 8.953
    { 967828, Bucket(2045) }, // 52.19, 9.583 x 52.4, 9.792
    { 967860, Bucket(2048) }, // 52.19, 10.42 x 52.4, 10.63
    { 967872, 763 }, // 52.61, 9.583 x 52.82, 9.792
    { 967891, 1135 }, // 53.65, 9.792 x 53.86, 10
    { 968206, Bucket(2055) }, // 51.35, 11.89 x 51.56, 12.1
    { 968211, Bucket(2065) }, // 51.98, 11.47 x 52.19, 11.68
    { 968227, Bucket(2071) }, // 51.14, 12.31 x 51.35, 12.52
    { 968230, Bucket(2071) }, // 51.35, 12.31 x 51.56, 12.52
    { 968240, 157 }, // 51.77, 12.1 x 51.98, 12.31
    { 968320, 1414 }, // 50.93, 12.94 x 51.14, 13.15
    { 968321, 793 }, // 51.14, 12.94 x 51.35, 13.15
    { 968322, 1288 }, // 50.93, 13.15 x 51.14, 13.36
    { 968324, 793 }, // 51.35, 12.94 x 51.56, 13.15
    { 968330, Bucket(2075) }, // 50.93, 13.57 x 51.14, 13.78
    { 968349, Bucket(2085) }, // 52.4, 13.36 x 52.61, 13.57
    { 968351, 34 }, // 52.4, 13.57 x 52.61, 13.78
    { 968352, Bucket(2094) }, // 50.93, 13.78 x 51.14, 13.99
    { 968431, Bucket(2101) }, // 53.24, 14.41 x 53.45, 14.62
    { 968442, Bucket(2101) }, // 53.45, 14.41 x 53.65, 14.62
    { 968795, Bucket(2109) }, // 46.94, 15.24 x 47.15, 15.45
    { 968817, 359 }, // 46.94, 15.45 x 47.15, 15.66
    { 969006, 78 }, // 47.99, 16.08 x 48.2, 16.29
    { 969092, 78 }, // 47.99, 16.29 x 48.2, 16.5
    { 969111, Bucket(2112) }, // 49.04, 16.5 x 49.25, 16.71
    { 969246, 252 }, // 45.48, 18.6 x 45.69, 18.81
    { 969335, Bucket(2124) }, // 47.36, 19.02 x 47.57, 19.23
    { 969659, Bucket(2147) }, // 48.62, 21.12 x 48.83, 21.33
    { 970287, 2044 }, // 51.56, 19.44 x 51.77, 19.65
    { 970298, 2044 }, // 51.77, 19.44 x 51.98, 19.65
    { 970428, 1046 }, // 52.19, 20.91 x 52.4, 21.12
    { 970982, 850 }, // 59.74, 10.63 x 59.95, 10.84
    { 971274, Bucket(2160) }, // 57.64, 11.89 x 57.85, 12.1
    { 972991, Bucket(2170) }, // 59.11, 17.76 x 59.32, 17.97
    { 973034, Bucket(2170) }, // 59.32, 17.76 x 59.53, 17.97
    { 973333, Bucket(2174) }, // 59.11, 17.97 x 59.32, 18.18
    { 973335, 769 }, // 59.11, 18.18 x 59.32, 18.39
    { 973376, Bucket(2182) }, // 59.32, 17.97 x 59.53, 18.18
    { 975401, 708 }, // 44.43, 25.94 x 44.64, 26.15
    { 976370, Bucket(2192) }, // 56.8, 24.05 x 57.01, 24.26
    { 977371, 546 }, // 50.3, 30.34 x 50.51, 30.55
    { 977850, Bucket(2197) }, // 48.41, 34.54 x 48.62, 34.75
    { 978328, Bucket(2200) }, // 55.12, 30.13 x 55.33, 30.34
    { 2226005, 1860 }, // 17.16, 78.37 x 17.37, 78.58
    { 2314234, 1770 }, // 3.114, 101.6 x 3.323, 101.9
    { 2318038, 1760 }, // 13.6, 100.4 x 13.81, 100.6
    { 2318975, Bucket(2205) }, // -6.324, 106.7 x -6.114, 106.9
    { 2319751, Bucket(2208) }, // 1.226, 103.7 x 1.436, 104
    { 2348942, 1769 }, // 14.44, 120.9 x 14.65, 121.2
    { 2348943, 1954 }, // 14.65, 120.9 x 14.86, 121.2
    { 2363737, 1607 }, // 36.88, 35.17 x 37.09, 35.38
    { 2366712, 1748 }, // 40.02, 44.4 x 40.23, 44.6
    { 2368699, 2288 }, // 25.13, 51.32 x 25.34, 51.53
    { 2372031, Bucket(2211) }, // 35.62, 51.32 x 35.83, 51.53
    { 2372373, 1600 }, // 35.62, 51.53 x 35.83, 51.74
    { 2372817, Bucket(2215) }, // 40.23, 49.85 x 40.44, 50.06
    { 2374508, 1211 }, // 36.25, 59.49 x 36.46, 59.7
    { 2375923, Bucket(2218) }, // 46.94, 37.47 x 47.15, 37.68
    { 2375926, Bucket(2225) }, // 47.15, 37.47 x 47.36, 37.68
    { 2376047, 543 }, // 49.88, 36.22 x 50.09, 36.43
    { 2377139, 492 }, // 55.33, 37.47 x 55.54, 37.68
    { 2377142, 492 }, // 55.54, 37.47 x 55.75, 37.68
    { 2378169, Bucket(2229) }, // 48.62, 44.4 x 48.83, 44.6
    { 2379211, 712 }, // 56.17, 43.77 x 56.38, 43.98
    { 2379233, 712 }, // 56.17, 43.98 x 56.38, 44.19
    { 2399524, 697 }, // 41.28, 69.14 x 41.49, 69.35
    { 2400768, Bucket(2232) }, // 17.37, 78.37 x 17.58, 78.58
    { 2401035, 2017 }, // 20.94, 79 x 21.15, 79.21
    { 2401371, 1759 }, // 26.81, 75.64 x 27.02, 75.85
    { 2401683, 1826 }, // 28.49, 76.9 x 28.7, 77.11
    { 2420007, 1534 }, // 54.91, 82.77 x 55.12, 82.98
    { 2420206, Bucket(2235) }, // 56.38, 84.87 x 56.59, 85.08
    { 2499632, 1688 }, // 24.92, 102.7 x 25.13, 102.9
    { 2500061, 1857 }, // 30.59, 104 x 30.8, 104.2
    { 2500460, Bucket(2238) }, // 29.54, 106.5 x 29.75, 106.7
    { 2501485, Bucket(2242) }, // 23.04, 113.2 x 23.25, 113.4
    { 2501487, 1685 }, // 23.04, 113.4 x 23.25, 113.6
    { 2501533, Bucket(2245) }, // 22.2, 114 x 22.41, 114.2
    { 2501570, 2098 }, // 22.41, 113.8 x 22.62, 114
    { 2501571, 1509 }, // 22.62, 113.8 x 22.83, 114
    { 2501576, Bucket(2248) }, // 22.41, 114 x 22.62, 114.2
    { 2502792, 2325 }, // 30.8, 104 x 31.01, 104.2
    { 2505604, 2284 }, // 34.57, 113.6 x 34.78, 113.8
    { 2506404, 1617 }, // 37.93, 114.4 x 38.14, 114.6
    { 2516119, Bucket(2251) }, // 52.4, 103.7 x 52.61, 104
    { 2516126, Bucket(2258) }, // 52.19, 104.2 x 52.4, 104.4
    { 2524747, 1684 }, // 25.97, 119.3 x 26.18, 119.5
    { 2524850, Bucket(2263) }, // 24.92, 121.4 x 25.13, 121.6
    { 2527419, 1691 }, // 31.84, 118.4 x 32.05, 118.6
    { 2527751, 2019 }, // 31.43, 118.8 x 31.63, 119.1
    { 2527761, 1691 }, // 31.84, 118.6 x 32.05, 118.8
    { 2527762, 2019 }, // 31.63, 118.8 x 31.84, 119.1
    { 2527791, 1614 }, // 31.43, 120.1 x 31.63, 120.3
    { 2527800, 2242 }, // 31.63, 119.9 x 31.84, 120.1
    { 2527876, 1675 }, // 31.22, 120.3 x 31.43, 120.5
    { 2527877, Bucket(2266) }, // 31.43, 120.3 x 31.63, 120.5
    { 2527878, Bucket(2269) }, // 31.22, 120.5 x 31.43, 120.7
    { 2527879, 1892 }, // 31.43, 120.5 x 31.63, 120.7
    { 2527884, 1675 }, // 31.22, 120.7 x 31.43, 120.9
    { 2528107, 1666 }, // 36.04, 120.1 x 36.25, 120.3
    { 2528193, Bucket(2272) }, // 36.04, 120.3 x 36.25, 120.5
    { 2528334, 1899 }, // 39.6, 115.9 x 39.81, 116.1
    { 2528357, 1868 }, // 39.81, 116.1 x 40.02, 116.3
    { 2528359, 315 }, // 39.81, 116.3 x 40.02, 116.5
    { 2530173, Bucket(2275) }, // 37.3, 126.6 x 37.51, 126.8
    { 2530175, 1472 }, // 37.3, 126.8 x 37.51, 127
    { 2530260, 1459 }, // 37.09, 127 x 37.3, 127.2
    { 2530261, 1694 }, // 37.3, 127 x 37.51, 127.2
    { 2530814, 2112 }, // 43.8, 125.1 x 44.01, 125.3
    { 2530856, Bucket(2280) }, // 37.51, 126.6 x 37.72, 126.8
    { 2530858, Bucket(2284) }, // 37.51, 126.8 x 37.72, 127
    { 2530944, Bucket(2288) }, // 37.51, 127 x 37.72, 127.2
    { 2535633, 1492 }, // 33.52, 130.4 x 33.73, 130.6
    { 2536030, Bucket(2293) }, // 33.73, 132.7 x 33.94, 132.9
    { 2536195, 1491 }, // 34.36, 132.3 x 34.57, 132.5
    { 2536201, 1491 }, // 34.36, 132.5 x 34.57, 132.7
    { 2536364, Bucket(2297) }, // 34.57, 135 x 34.78, 135.2
    { 2536366, 2249 }, // 34.57, 135.2 x 34.78, 135.4
    { 2537732, Bucket(2301) }, // 34.57, 135.4 x 34.78, 135.6
    { 2537735, 1807 }, // 34.78, 135.6 x 34.99, 135.8
    { 2537746, Bucket(2309) }, // 34.99, 135.6 x 35.2, 135.8
    { 2537786, 1810 }, // 34.99, 136.9 x 35.2, 137.1
    { 2538267, 2008 }, // 35.2, 139.4 x 35.41, 139.6
    { 2538292, Bucket(2313) }, // 35.41, 139.6 x 35.62, 139.8
    { 2538293, Bucket(2317) }, // 35.62, 139.6 x 35.83, 139.8
    { 2538294, 2263 }, // 35.41, 139.8 x 35.62, 140
    { 2538314, 1991 }, // 35.83, 139.4 x 36.04, 139.6
    { 2538336, 1991 }, // 35.83, 139.6 x 36.04, 139.8
    { 2539149, 1522 }, // 38.14, 140.9 x 38.35, 141.1
    { 2539492, Bucket(2326) }, // 42.96, 141.3 x 43.17, 141.5
    { 2643426, Bucket(2329) }, // -37.99, 144.8 x -37.78, 145.1
    { 2689231, Bucket(2337) }, // -34.01, 151.1 x -33.8, 151.4
    { 2690638, 2285 }, // -27.5, 152.8 x -27.3, 153
    { 2690660, 2285 }, // -27.5, 153 x -27.3, 153.2
    { 1620607, Bucket(2340) }, // 25.66, -100.4 x 25.76, -100.3
    { 1620693, Bucket(2340) }, // 25.66, -100.3 x 25.76, -100.2
    { 1634715, 1925 }, // 39.71, -105 x 39.81, -104.9
    { 1639162, 177 }, // 45.48, -123.1 x 45.58, -123
    { 1640536, Bucket(2343) }, // 45.48, -122.7 x 45.58, -122.6
    { 1718167, Bucket(2347) }, // 29.85, -90.14 x 29.96, -90.03
    { 1718210, Bucket(2348) }, // 29.96, -90.14 x 30.06, -90.03
    { 1735915, 752 }, // 41.81, -87.83 x 41.91, -87.73
    { 1735916, 1890 }, // 41.91, -87.94 x 42.02, -87.83
    { 1736257, 752 }, // 41.81, -87.73 x 41.91, -87.62
    { 1753594, Bucket(2351) }, // 33.73, -84.47 x 33.84, -84.37
    { 1761263, 197 }, // 43.69, -79.44 x 43.8, -79.34
    { 1766103, 2215 }, // 39.08, -76.72 x 39.18, -76.61
    { 1766725, 198 }, // 43.69, -79.34 x 43.8, -79.23
    { 1767743, Bucket(2354) }, // 39.92, -75.25 x 40.02, -75.14
    { 1767786, Bucket(2362) }, // 40.02, -75.25 x 40.13, -75.14
    { 1767829, Bucket(2366) }, // 39.92, -75.14 x 40.02, -75.04
    { 1767872, 431 }, // 40.02, -75.14 x 40.13, -75.04
    { 1768305, 1680 }, // 40.55, -73.88 x 40.65, -73.78
    { 1813112, 906 }, // 45.48, -73.67 x 45.58, -73.57
    { 2392191, Bucket(2369) }, // -34.74, -58.47 x -34.64, -58.37
    { 2392362, Bucket(2372) }, // -34.64, -58.47 x -34.53, -58.37
    { 2408299, Bucket(2375) }, // -23.63, -46.73 x -23.52, -46.62
    { 2408345, 1416 }, // -24.04, -46.41 x -23.94, -46.31
    { 2408385, 981 }, // -23.63, -46.62 x -23.52, -46.52
    { 2442711, 1541 }, // 10.56, -71.68 x 10.66, -71.58
    { 2496469, Bucket(2378) }, // -23, -43.27 x -22.89, -43.16
    { 2507278, 2209 }, // -22.68, -43.79 x -22.58, -43.69
    { 2507300, 2209 }, // -22.68, -43.69 x -22.58, -43.58
    { 2557665, 2332 }, // -5.17, -42.85 x -5.065, -42.74
    { 3167481, 496 }, // 42.23, -71.16 x 42.33, -71.05
    { 3697502, 1181 }, // 33.94, -6.88 x 34.05, -6.775
    { 3699431, Bucket(2381) }, // 38.66, -9.187 x 38.77, -9.082
    { 3699442, 1546 }, // 38.77, -9.187 x 38.87, -9.082
    { 3723759, 1630 }, // 40.34, -3.944 x 40.44, -3.839
    { 3723780, 1750 }, // 37.72, -3.839 x 37.82, -3.734
    { 3724101, Bucket(2387) }, // 40.34, -3.839 x 40.44, -3.734
    { 3724103, Bucket(2390) }, // 40.34, -3.734 x 40.44, -3.63
    { 3724112, 1629 }, // 40.44, -3.839 x 40.55, -3.734
    { 3724114, Bucket(2393) }, // 40.44, -3.734 x 40.55, -3.63
    { 3725204, 1936 }, // 43.17, -3 x 43.27, -2.896
    { 3725248, 1400 }, // 43.38, -3 x 43.48, -2.896
    { 3725458, 1712 }, // 37.93, -1.218 x 38.03, -1.113
    { 3725546, 240 }, // 38.35, -0.5886 x 38.45, -0.4838
    { 3725888, Bucket(2396) }, // 38.35, -0.4838 x 38.45, -0.3789
    { 3726086, Bucket(2399) }, // 39.39, -0.3789 x 39.5, -0.2741
    { 3726495, 392 }, // 41.6, -1.008 x 41.7, -0.9032
    { 3726517, 392 }, // 41.6, -0.9032 x 41.7, -0.7984
    { 3727022, 1243 }, // 41.07, 1.089 x 41.18, 1.194
    { 3732484, 1243 }, // 41.07, 1.194 x 41.18, 1.299
    { 3732624, 1263 }, // 41.28, 2.033 x 41.39, 2.138
    { 3732627, Bucket(2402) }, // 41.39, 2.138 x 41.49, 2.243
    { 3734847, 223 }, // 43.27, 5.283 x 43.38, 5.388
    { 3734873, 2243 }, // 43.9, 4.759 x 44.01, 4.864
    { 3734933, Bucket(2408) }, // 43.27, 5.388 x 43.38, 5.493
    { 3770738, 618 }, // 47.15, -1.637 x 47.26, -1.532
    { 3771949, Bucket(2411) }, // 47.89, 0.1454 x 47.99, 0.2502
    { 3771960, Bucket(2411) }, // 47.99, 0.1454 x 48.1, 0.2502
    { 3771991, Bucket(2414) }, // 49.15, -0.3789 x 49.25, -0.2741
    { 3772198, 973 }, // 49.46, 0.0405 x 49.57, 0.1454
    { 3773416, Bucket(2417) }, // 53.45, -2.371 x 53.55, -2.266
    { 3773663, 1317 }, // 55.86, -4.364 x 55.96, -4.259
    { 3774784, Bucket(2420) }, // 53.45, -2.162 x 53.55, -2.057
    { 3775003, Bucket(2424) }, // 51.45, -0.1692 x 51.56, -0.06436
    { 3775025, Bucket(2427) }, // 51.45, -0.06436 x 51.56, 0.0405
    { 3777261, Bucket(2430) }, // 45.37, 4.34 x 45.48, 4.445
    { 3777272, 334 }, // 45.48, 4.34 x 45.58, 4.445
    { 3777754, Bucket(2434) }, // 48.83, 2.347 x 48.94, 2.452
    { 3778551, 1918 }, // 50.82, 4.235 x 50.93, 4.34
    { 3778557, 1765 }, // 50.82, 4.34 x 50.93, 4.445
    { 3778652, 992 }, // 45.69, 4.759 x 45.79, 4.864
    { 3778654, 744 }, // 45.69, 4.864 x 45.79, 4.969
    { 3778763, 1022 }, // 45.16, 5.703 x 45.27, 5.808
    { 3778990, 2313 }, // 46.11, 6.122 x 46.21, 6.227
    { 3779255, 310 }, // 44.95, 7.59 x 45.06, 7.695
    { 3779298, 310 }, // 45.06, 7.59 x 45.16, 7.695
    { 3779531, 1033 }, // 46.84, 7.381 x 46.94, 7.485
    { 3779534, 1033 }, // 46.94, 7.381 x 47.05, 7.485
    { 3779822, 598 }, // 48.62, 6.122 x 48.73, 6.227
    { 3780233, Bucket(2438) }, // 47.68, 7.276 x 47.78, 7.381
    { 3780271, Bucket(2442) }, // 47.89, 7.8 x 47.99, 7.905
    { 3780282, Bucket(2445) }, // 47.99, 7.8 x 48.1, 7.905
    { 3780329, Bucket(2449) }, // 48.52, 7.695 x 48.62, 7.8
    { 3780564, 92 }, // 50.72, 7.066 x 50.82, 7.171
    { 3781355, Bucket(2453) }, // 51.87, 4.445 x 51.98, 4.549
    { 3782721, Bucket(2458) }, // 51.87, 4.549 x 51.98, 4.654
    { 3782747, Bucket(2461) }, // 52.29, 4.864 x 52.4, 4.969
    { 3783208, Bucket(2467) }, // 50.93, 6.856 x 51.03, 6.961
    { 3783323, Bucket(2470) }, // 51.45, 7.381 x 51.56, 7.485
    { 3819363, Bucket(2475) }, // 36.77, 10.11 x 36.88, 10.21
    { 3821962, 1170 }, // 39.18, 9.058 x 39.29, 9.163
    { 3823599, Bucket(2479) }, // 43.69, 11.16 x 43.8, 11.26
    { 3823610, Bucket(2479) }, // 43.8, 11.16 x 43.9, 11.26
    { 3824155, Bucket(2482) }, // 38.03, 13.25 x 38.14, 13.36
    { 3824177, 1233 }, // 38.03, 13.36 x 38.14, 13.46
    { 3824629, 309 }, // 40.76, 14.2 x 40.86, 14.3
    { 3824843, 627 }, // 41.81, 12.41 x 41.91, 12.52
    { 3824846, 625 }, // 41.91, 12.41 x 42.02, 12.52
    { 3824865, 633 }, // 41.81, 12.52 x 41.91, 12.62
    { 3825312, 309 }, // 40.86, 14.2 x 40.97, 14.3
    { 3827061, 1487 }, // 37.4, 15.04 x 37.51, 15.14
    { 3829792, 1487 }, // 37.51, 15.04 x 37.61, 15.14
    { 3854843, Bucket(2485) }, // 40.55, 22.9 x 40.65, 23
    { 3854893, 1355 }, // 37.82, 23.63 x 37.93, 23.74
    { 3854904, 1355 }, // 37.93, 23.63 x 38.03, 23.74
    { 3863355, Bucket(2488) }, // 39.71, 30.45 x 39.81, 30.55
    { 3863441, Bucket(2492) }, // 39.71, 30.55 x 39.81, 30.66
    { 3863595, Bucket(2495) }, // 40.97, 28.77 x 41.07, 28.88
    { 3863681, Bucket(2499) }, // 40.97, 28.88 x 41.07, 28.98
    { 3863686, 1516 }, // 41.07, 28.98 x 41.18, 29.09
    { 3867004, 798 }, // 47.36, 8.534 x 47.47, 8.639
    { 3867007, 1887 }, // 47.47, 8.639 x 47.57, 8.744
    { 3867256, 796 }, // 45.48, 10.21 x 45.58, 10.32
    { 3867690, 1887 }, // 47.57, 8.639 x 47.68, 8.744
    { 3867761, 19 }, // 48.94, 8.324 x 49.04, 8.429
    { 3867763, 26 }, // 48.94, 8.429 x 49.04, 8.534
    { 3867772, 1053 }, // 49.04, 8.534 x 49.15, 8.639
    { 3867775, 402 }, // 49.15, 8.639 x 49.25, 8.744
    { 3867855, Bucket(2502) }, // 48.73, 9.058 x 48.83, 9.163
    { 3867865, 686 }, // 48.94, 8.953 x 49.04, 9.058
    { 3867866, 169 }, // 48.83, 9.058 x 48.94, 9.163
    { 3867877, Bucket(2506) }, // 48.73, 9.163 x 48.83, 9.268
    { 3867888, Bucket(2513) }, // 48.83, 9.163 x 48.94, 9.268
    { 3867890, 169 }, // 48.83, 9.268 x 48.94, 9.373
    { 3867896, 169 }, // 48.83, 9.373 x 48.94, 9.478
    { 3867935, 937 }, // 49.98, 8.219 x 50.09, 8.324
    { 3867942, 729 }, // 49.46, 8.429 x 49.57, 8.534
    { 3867947, Bucket(2517) }, // 49.36, 8.639 x 49.46, 8.744
    { 3868010, Bucket(2521) }, // 50.09, 8.639 x 50.19, 8.744
    { 3868053, 937 }, // 49.98, 8.744 x 50.09, 8.849
    { 3868096, Bucket(2524) }, // 50.09, 8.744 x 50.19, 8.849
    { 3868191, 1409 }, // 48.31, 9.897 x 48.41, 10
    { 3868234, 1409 }, // 48.41, 9.897 x 48.52, 10
    { 3868319, 341 }, // 48.31, 10.74 x 48.41, 10.84
    { 3868341, Bucket(2528) }, // 48.31, 10.84 x 48.41, 10.95
    { 3869010, 196 }, // 47.15, 11.37 x 47.26, 11.47
    { 3869721, Bucket(2535) }, // 48.1, 11.47 x 48.2, 11.57
    { 3869781, 192 }, // 49.15, 11.26 x 49.25, 11.37
    { 3869824, 982 }, // 47.57, 12.1 x 47.68, 12.2
    { 3869871, 1833 }, // 47.89, 12.83 x 47.99, 12.94
    { 3869882, 1833 }, // 47.99, 12.83 x 48.1, 12.94
    { 3870079, Bucket(2539) }, // 50.82, 11.99 x 50.93, 12.1
    { 3870149, 875 }, // 50.4, 12.1 x 50.51, 12.2
    { 3870160, 875 }, // 50.51, 12.1 x 50.61, 12.2
    { 3870165, 194 }, // 50.82, 12.1 x 50.93, 12.2
    { 3870171, Bucket(2542) }, // 50.61, 12.41 x 50.72, 12.52
    { 3870174, Bucket(2542) }, // 50.72, 12.41 x 50.82, 12.52
    { 3870653, 593 }, // 49.98, 14.41 x 50.09, 14.51
    { 3870696, 593 }, // 50.09, 14.41 x 50.19, 14.51
    { 3871034, 356 }, // 53.03, 8.639 x 53.13, 8.744
    { 3871120, Bucket(2545) }, // 53.03, 8.744 x 53.13, 8.849
    { 3871315, Bucket(2548) }, // 52.29, 9.687 x 52.4, 9.792
    { 3871387, Bucket(2551) }, // 51.45, 10.74 x 51.56, 10.84
    { 3872825, Bucket(2554) }, // 51.45, 11.89 x 51.56, 11.99
    { 3872847, Bucket(2558) }, // 52.08, 11.57 x 52.19, 11.68
    { 3872869, 93 }, // 52.08, 11.68 x 52.19, 11.78
    { 3872909, Bucket(2562) }, // 51.24, 12.31 x 51.35, 12.41
    { 3872920, 76 }, // 51.35, 12.31 x 51.45, 12.41
    { 3872938, 1413 }, // 50.93, 12.83 x 51.03, 12.94
    { 3872962, 1047 }, // 51.77, 12.2 x 51.87, 12.31
    { 3873091, 126 }, // 53.55, 11.37 x 53.65, 11.47
    { 3873150, Bucket(2565) }, // 54.07, 11.99 x 54.18, 12.1
    { 3873236, Bucket(2568) }, // 54.07, 12.1 x 54.18, 12.2
    { 3873280, 1413 }, // 50.93, 12.94 x 51.03, 13.04
    { 3873323, Bucket(2572) }, // 51.03, 13.67 x 51.14, 13.78
    { 3873397, Bucket(2575) }, // 52.5, 13.36 x 52.61, 13.46
    { 3873406, 645 }, // 52.4, 13.67 x 52.5, 13.78
    { 3873463, 502 }, // 51.66, 14.3 x 51.77, 14.41
    { 3873727, Bucket(2579) }, // 53.34, 14.51 x 53.45, 14.62
    { 3873770, Bucket(2579) }, // 53.45, 14.51 x 53.55, 14.62
    { 3874011, 300 }, // 55.65, 12.41 x 55.75, 12.52
    { 3874033, Bucket(2582) }, // 55.65, 12.52 x 55.75, 12.62
    { 3877341, Bucket(2586) }, // 47.47, 19.02 x 47.57, 19.12
    { 3877342, 513 }, // 47.36, 19.12 x 47.47, 19.23
    { 3877669, Bucket(2592) }, // 46.21, 20.07 x 46.31, 20.17
    { 3878024, Bucket(2598) }, // 47.57, 19.02 x 47.68, 19.12
    { 3878638, 1778 }, // 48.62, 21.22 x 48.73, 21.33
    { 3881149, 2033 }, // 51.66, 19.44 x 51.77, 19.54
    { 3881192, 2033 }, // 51.77, 19.44 x 51.87, 19.54
    { 3885096, 657 }, // 57.64, 11.89 x 57.74, 11.99
    { 3892138, Bucket(2601) }, // 59.32, 17.87 x 59.42, 17.97
    { 3893504, Bucket(2605) }, // 59.32, 17.97 x 59.42, 18.08
    { 3901331, Bucket(2608) }, // 49.78, 23.95 x 49.88, 24.05
    { 3902415, Bucket(2612) }, // 47.05, 27.51 x 47.15, 27.62
    { 3902426, Bucket(2617) }, // 47.15, 27.51 x 47.26, 27.62
    { 3905481, 541 }, // 56.91, 24.05 x 57.01, 24.16
    { 3909573, 1043 }, // 50.4, 30.55 x 50.51, 30.66
    { 3909584, 1043 }, // 50.51, 30.55 x 50.61, 30.66
    { 3911183, 2297 }, // 47.89, 33.39 x 47.99, 33.49
    { 3913290, Bucket(2623) }, // 55.12, 30.03 x 55.23, 30.13
    { 3913312, Bucket(2623) }, // 55.12, 30.13 x 55.23, 30.24
    { 3918109, Bucket(2626) }, // 60.05, 24.89 x 60.16, 25
    { 3918152, Bucket(2629) }, // 60.16, 24.89 x 60.26, 25
    { 9276245, 2352 }, // -6.219, 106.9 x -6.114, 107
    { 9467626, Bucket(2639) }, // 41.7, 44.71 x 41.81, 44.81
    { 9468949, 1583 }, // 41.6, 44.81 x 41.7, 44.92
    { 9468992, 1583 }, // 41.7, 44.81 x 41.81, 44.92
    { 9474799, 2269 }, // 25.24, 51.42 x 25.34, 51.53
    { 9476165, 2288 }, // 25.24, 51.53 x 25.34, 51.63
    { 9488126, 2004 }, // 35.62, 51.42 x 35.72, 51.53
    { 9490927, Bucket(2642) }, // 40.34, 49.74 x 40.44, 49.85
    { 9503693, Bucket(2646) }, // 47.05, 37.47 x 47.15, 37.58
    { 9503695, 2365 }, // 47.05, 37.58 x 47.15, 37.68
    { 9516847, 1477 }, // 56.28, 43.87 x 56.38, 43.98
    { 9551720, 1536 }, // 56.8, 60.54 x 56.91, 60.65
    { 9578890, 1488 }, // 19.05, 72.81 x 19.16, 72.92
    { 9579923, 2010 }, // 22.93, 72.6 x 23.04, 72.71
    { 9598098, 698 }, // 41.28, 69.25 x 41.39, 69.35
    { 9603074, 1859 }, // 17.37, 78.47 x 17.48, 78.58
    { 9680031, 1535 }, // 55.02, 82.88 x 55.12, 82.98
    { 10005755, 2287 }, // 22.09, 113.5 x 22.2, 113.6
    { 10005942, 1504 }, // 23.04, 113.3 x 23.14, 113.4
    { 10006111, Bucket(2649) }, // 22.3, 113.9 x 22.41, 114
    { 10006134, 1367 }, // 22.2, 114.1 x 22.3, 114.2
    { 10006277, 2092 }, // 22.72, 113.6 x 22.83, 113.7
    { 10006282, Bucket(2657) }, // 22.41, 113.9 x 22.51, 114
    { 10006283, 1509 }, // 22.51, 113.9 x 22.62, 114
    { 10006292, 1685 }, // 23.04, 113.6 x 23.14, 113.7
    { 10006304, 1328 }, // 22.41, 114 x 22.51, 114.1
    { 10019167, 1637 }, // 34.05, 108.9 x 34.15, 109
    { 10022075, 2239 }, // 34.68, 113.5 x 34.78, 113.6
    { 10064479, 799 }, // 52.5, 103.8 x 52.61, 104
    { 10096388, 1662 }, // 22.62, 120.3 x 22.72, 120.4
    { 10099404, 1194 }, // 25.13, 121.4 x 25.24, 121.5
    { 10100638, 2281 }, // 29.75, 121.5 x 29.85, 121.6
    { 10110743, 2322 }, // 36.56, 117.1 x 36.67, 117.2
    { 10110786, 2322 }, // 36.67, 117.1 x 36.77, 117.2
    { 10111157, 2242 }, // 31.53, 119.9 x 31.63, 120
    { 10111167, 1615 }, // 31.53, 120.2 x 31.63, 120.3
    { 10111204, 2242 }, // 31.84, 119.9 x 31.95, 120
    { 10111630, 1837 }, // 31.01, 121.5 x 31.11, 121.6
    { 10121045, 1472 }, // 37.4, 127 x 37.51, 127.1
    { 10123259, 2113 }, // 43.9, 125.2 x 44.01, 125.3
    { 10123358, 1558 }, // 38.97, 125.7 x 39.08, 125.8
    { 10123434, 1919 }, // 37.51, 126.9 x 37.61, 127
    { 10123776, 1472 }, // 37.51, 127 x 37.61, 127.1
    { 10123780, 1458 }, // 37.72, 127 x 37.82, 127.1
    { 10124624, 2112 }, // 43.8, 125.3 x 43.9, 125.5
    { 10124625, 2113 }, // 43.9, 125.3 x 44.01, 125.5
    { 10142190, Bucket(2669) }, // 33.52, 130.3 x 33.63, 130.4
    { 10142532, Bucket(2669) }, // 33.52, 130.4 x 33.63, 130.5
    { 10142976, Bucket(1639) }, // 35.83, 128.7 x 35.93, 128.8
    { 10145466, 2048 }, // 34.57, 135.3 x 34.68, 135.4
    { 10150928, 2048 }, // 34.57, 135.4 x 34.68, 135.5
    { 10150943, 1806 }, // 34.89, 135.7 x 34.99, 135.8
    { 10150986, 1806 }, // 34.99, 135.7 x 35.1, 135.8
    { 10151145, 1813 }, // 35.1, 136.9 x 35.2, 137
    { 10151147, 2110 }, // 35.1, 137 x 35.2, 137.1
    { 10153083, 1525 }, // 35.51, 139.5 x 35.62, 139.6
    { 10153157, 581 }, // 35.3, 139.6 x 35.41, 139.7
    { 10153168, 1496 }, // 35.41, 139.6 x 35.51, 139.7
    { 10153172, Bucket(2672) }, // 35.62, 139.6 x 35.72, 139.7
    { 10153173, 2263 }, // 35.72, 139.6 x 35.83, 139.7
    { 10153174, 2263 }, // 35.62, 139.7 x 35.72, 139.8
    { 10153175, 1971 }, // 35.72, 139.7 x 35.83, 139.8
    { 10153180, 2263 }, // 35.62, 139.8 x 35.72, 139.9
    { 10153182, 2263 }, // 35.62, 139.9 x 35.72, 140
    { 10153201, 2263 }, // 35.51, 140 x 35.62, 140.1
    { 10153204, 2263 }, // 35.62, 140 x 35.72, 140.1
    { 10153346, 1985 }, // 35.83, 139.7 x 35.93, 139.8
    { 10157968, 1948 }, // 42.96, 141.3 x 43.06, 141.4
    { 10573707, Bucket(2675) }, // -37.89, 145 x -37.78, 145.1
    { 4170863, 1330 }, // 6.207, -75.61 x 6.259, -75.56
    { 4170949, 1330 }, // 6.207, -75.56 x 6.259, -75.51
    { 6381721, Bucket(2679) }, // 37.77, -122.4 x 37.82, -122.4
    { 6382490, 1969 }, // 38.56, -121.5 x 38.61, -121.5
    { 6393016, 2192 }, // 32.68, -117.2 x 32.74, -117.1
    { 6461986, 1369 }, // 20.73, -103.4 x 20.78, -103.3
    { 6489865, 1933 }, // 33.36, -111.9 x 33.42, -111.9
    { 6489868, 1933 }, // 33.42, -111.9 x 33.47, -111.9
    { 6872671, 554 }, // 29.9, -90.08 x 29.96, -90.03
    { 6872842, 554 }, // 29.96, -90.08 x 30.01, -90.03
    { 6884885, 2251 }, // 32.84, -96.95 x 32.89, -96.9
    { 6884889, 1305 }, // 32.74, -96.85 x 32.79, -96.8
    { 6943678, 730 }, // 42.02, -87.78 x 42.07, -87.73
    { 6945044, 730 }, // 42.02, -87.73 x 42.07, -87.67
    { 6975585, 1138 }, // 27.91, -82.48 x 27.96, -82.43
    { 7015744, 1062 }, // 33.73, -84.37 x 33.78, -84.32
    { 7029750, 1038 }, // 39.08, -84.53 x 39.13, -84.47
    { 7064415, 2216 }, // 39.13, -76.66 x 39.18, -76.61
    { 7071146, 1740 }, // 40.02, -75.19 x 40.08, -75.14
    { 7073139, 1731 }, // 40.7, -74.04 x 40.76, -73.99
    { 7073144, 1681 }, // 40.65, -73.99 x 40.7, -73.94
    { 7252456, 904 }, // 45.48, -73.57 x 45.53, -73.52
    { 9568767, 856 }, // -34.69, -58.42 x -34.64, -58.37
    { 9569450, Bucket(2684) }, // -34.64, -58.42 x -34.58, -58.37
    { 9985879, Bucket(2687) }, // -22.94, -43.21 x -22.89, -43.16
    { 10239102, Bucket(2691) }, // -3.702, -40.38 x -3.65, -40.33
    { 14703373, 406 }, // 28.44, -16.32 x 28.49, -16.26
    { 14882592, 1578 }, // 36.67, -4.468 x 36.72, -4.416
    { 14896391, 1749 }, // 40.18, -3.787 x 40.23, -3.734
    { 14896402, 1749 }, // 40.23, -3.787 x 40.29, -3.734
    { 14902186, Bucket(2694) }, // 38.35, -0.5362 x 38.4, -0.4838
    { 14903552, 239 }, // 38.35, -0.4838 x 38.4, -0.4314
    { 14933786, 1036 }, // 43.59, 3.868 x 43.64, 3.92
    { 14939390, Bucket(2697) }, // 43.27, 5.336 x 43.33, 5.388
    { 14939732, 692 }, // 43.27, 5.388 x 43.33, 5.441
    { 14941982, 2255 }, // 43.69, 7.223 x 43.75, 7.276
    { 14942004, 2255 }, // 43.69, 7.276 x 43.75, 7.328
    { 15087964, 2169 }, // 49.15, -0.3789 x 49.2, -0.3265
    { 15094740, 1317 }, // 55.86, -4.259 x 55.91, -4.206
    { 15111020, 1378 }, // 48.94, 2.347 x 48.99, 2.4
    { 15111117, 1396 }, // 48.99, 2.557 x 49.04, 2.61
    { 15118127, 733 }, // 46.89, 7.433 x 46.94, 7.485
    { 15118138, 733 }, // 46.94, 7.433 x 47, 7.485
    { 15121911, 85 }, // 50.88, 6.909 x 50.93, 6.961
    { 15125171, 949 }, // 51.19, 4.392 x 51.24, 4.445
    { 15130884, 871 }, // 51.87, 4.549 x 51.92, 4.602
    { 15130988, 2385 }, // 52.29, 4.864 x 52.34, 4.916
    { 15296623, 1235 }, // 38.08, 13.3 x 38.14, 13.36
    { 15299375, Bucket(2700) }, // 41.86, 12.47 x 41.91, 12.52
    { 15299461, Bucket(2700) }, // 41.86, 12.52 x 41.91, 12.57
    { 15435807, 1436 }, // 31.16, 29.87 x 31.22, 29.92
    { 15435850, 1436 }, // 31.22, 29.87 x 31.27, 29.92
    { 15467994, 813 }, // 47.36, 8.482 x 47.42, 8.534
    { 15468016, 813 }, // 47.36, 8.534 x 47.42, 8.586
    { 15471047, 1265 }, // 48.99, 8.377 x 49.04, 8.429
    { 15471096, 1053 }, // 49.04, 8.639 x 49.09, 8.691
    { 15471099, 402 }, // 49.09, 8.691 x 49.15, 8.744
    { 15471469, 686 }, // 48.99, 9.058 x 49.04, 9.111
    { 15471471, 686 }, // 48.99, 9.111 x 49.04, 9.163
    { 15471508, 45 }, // 48.73, 9.163 x 48.78, 9.216
    { 15471556, 169 }, // 48.94, 9.163 x 48.99, 9.216
    { 15471557, 686 }, // 48.99, 9.163 x 49.04, 9.216
    { 15471558, 169 }, // 48.94, 9.216 x 48.99, 9.268
    { 15471559, 686 }, // 48.99, 9.216 x 49.04, 9.268
    { 15471564, 169 }, // 48.94, 9.268 x 48.99, 9.32
    { 15471565, 686 }, // 48.99, 9.268 x 49.04, 9.32
    { 15471566, 169 }, // 48.94, 9.32 x 48.99, 9.373
    { 15471567, 686 }, // 48.99, 9.32 x 49.04, 9.373
    { 15471588, 169 }, // 48.94, 9.373 x 48.99, 9.425
    { 15471589, 686 }, // 48.99, 9.373 x 49.04, 9.425
    { 15471591, 686 }, // 48.99, 9.425 x 49.04, 9.478
    { 15471597, 686 }, // 48.99, 9.478 x 49.04, 9.53
    { 15472767, 1410 }, // 48.36, 9.95 x 48.41, 10
    { 15472853, 1410 }, // 48.36, 10 x 48.41, 10.05
    { 15472938, 1410 }, // 48.41, 9.95 x 48.46, 10
    { 15473024, 1410 }, // 48.41, 10 x 48.46, 10.05
    { 15476044, 1028 }, // 47.26, 11.37 x 47.31, 11.42
    { 15478893, 167 }, // 48.15, 11.57 x 48.2, 11.63
    { 15491639, 138 }, // 51.3, 12.36 x 51.35, 12.41
    { 15491682, 138 }, // 51.35, 12.36 x 51.4, 12.41
    { 15491754, 1414 }, // 50.93, 12.89 x 50.98, 12.94
    { 15492602, 54 }, // 54.07, 12.05 x 54.13, 12.1
    { 15493636, Bucket(2703) }, // 51.03, 13.78 x 51.09, 13.83
    { 15493853, Bucket(2706) }, // 51.72, 14.3 x 51.77, 14.35
    { 15494024, Bucket(2710) }, // 51.77, 14.3 x 51.82, 14.35
    { 15494909, Bucket(2713) }, // 53.39, 14.51 x 53.45, 14.56
    { 15495080, Bucket(2713) }, // 53.45, 14.51 x 53.5, 14.56
    { 15509342, Bucket(2716) }, // 47.47, 18.97 x 47.52, 19.02
    { 15509364, Bucket(2720) }, // 47.47, 19.02 x 47.52, 19.07
    { 15509369, 515 }, // 47.42, 19.12 x 47.47, 19.18
    { 15514553, 1977 }, // 48.67, 21.22 x 48.73, 21.27
    { 15524597, Bucket(2726) }, // 51.72, 19.44 x 51.77, 19.49
    { 15524768, Bucket(2726) }, // 51.77, 19.44 x 51.82, 19.49
    { 15567871, Bucket(2729) }, // 59.26, 17.92 x 59.32, 17.97
    { 15568554, Bucket(2732) }, // 59.32, 17.92 x 59.37, 17.97
    { 15609792, Bucket(2735) }, // 47.15, 27.62 x 47.21, 27.67
    { 37870335, 1583 }, // 41.65, 44.76 x 41.7, 44.81
    { 37904660, 2269 }, // 25.24, 51.53 x 25.29, 51.58
    { 38014818, 2136 }, // 47.15, 37.53 x 47.21, 37.58
    { 38206711, 1536 }, // 56.75, 60.6 x 56.8, 60.65
    { 38723305, 466 }, // 56.43, 84.98 x 56.49, 85.03
    { 40024532, 379 }, // 22.3, 114 x 22.35, 114.1
    { 40024533, Bucket(2738) }, // 22.35, 114 x 22.41, 114.1
    { 40025216, Bucket(2738) }, // 22.41, 114 x 22.46, 114.1
    { 40384186, 1662 }, // 22.62, 120.3 x 22.67, 120.3
    { 40444842, 1614 }, // 31.63, 120.3 x 31.69, 120.3
    { 40446208, 1614 }, // 31.63, 120.3 x 31.69, 120.4
    { 40571221, 1626 }, // 35.78, 128.7 x 35.83, 128.8
    { 40576486, 1178 }, // 33.84, 132.7 x 33.89, 132.8
    { 40581857, 1507 }, // 34.62, 135.2 x 34.68, 135.3
    { 40581860, 1507 }, // 34.68, 135.2 x 34.73, 135.3
    { 40605957, 2110 }, // 35.15, 137.1 x 35.2, 137.1
    { 40612326, 1990 }, // 35.51, 139.4 x 35.57, 139.5
    { 40612676, 1525 }, // 35.51, 139.6 x 35.57, 139.7
    { 40612700, 2263 }, // 35.72, 139.7 x 35.78, 139.8
    { 40612701, 1985 }, // 35.78, 139.7 x 35.83, 139.8
    { 40612703, 2223 }, // 35.78, 139.8 x 35.83, 139.8
    { 40612725, 2223 }, // 35.78, 139.8 x 35.83, 139.9
    { 40612727, 2223 }, // 35.78, 139.9 x 35.83, 139.9
    { 40612733, 2223 }, // 35.78, 139.9 x 35.83, 140
    { 40612735, 2223 }, // 35.78, 140 x 35.83, 140
    { 40612821, 2223 }, // 35.78, 140 x 35.83, 140.1
    { 40612822, 2263 }, // 35.72, 140.1 x 35.78, 140.1
    { 40613410, 2005 }, // 35.83, 139.9 x 35.88, 139.9
    { 40674170, 1736 }, // 45.69, 126.6 x 45.74, 126.6
    { 25526823, 1981 }, // 37.59, -122.4 x 37.61, -122.4
    { 25526834, 1981 }, // 37.61, -122.4 x 37.64, -122.4
    { 25933824, 1678 }, // 25.76, -100.3 x 25.79, -100.3
    { 28142893, 1889 }, // 42.2, -83.37 x 42.23, -83.35
    { 28285952, 1740 }, // 40.02, -75.14 x 40.05, -75.12
    { 59602602, 1400 }, // 43.38, -3.027 x 43.41, -3
    { 59722010, 1345 }, // 41.39, 2.111 x 41.41, 2.138
    { 59722038, 1127 }, // 41.44, 2.164 x 41.47, 2.19
    { 59758968, 1331 }, // 43.27, 5.546 x 43.3, 5.572
    { 60458445, 994 }, // 45.76, 4.812 x 45.79, 4.838
    { 60469317, 2313 }, // 46.18, 6.227 x 46.21, 6.253
    { 60469695, 1096 }, // 46.5, 6.62 x 46.52, 6.647
    { 60469738, 1096 }, // 46.52, 6.62 x 46.55, 6.647
    { 60470037, 1096 }, // 46.5, 6.647 x 46.52, 6.673
    { 60470080, 1096 }, // 46.52, 6.647 x 46.55, 6.673
    { 60500687, 941 }, // 51.22, 4.418 x 51.24, 4.445
    { 60523536, 1260 }, // 51.87, 4.549 x 51.9, 4.576
    { 61194068, 327 }, // 40.81, 14.2 x 40.84, 14.22
    { 61197503, 633 }, // 41.88, 12.49 x 41.91, 12.52
    { 61743317, 1436 }, // 31.19, 29.92 x 31.22, 29.95
    { 61818977, 2007 }, // 41.1, 28.98 x 41.12, 29.01
    { 61879621, 460 }, // 47.44, 9.583 x 47.47, 9.609
    { 61884391, 402 }, // 49.12, 8.665 x 49.15, 8.691
    { 61884392, 1053 }, // 49.04, 8.691 x 49.07, 8.717
    { 61885691, 1595 }, // 48.75, 9.137 x 48.78, 9.163
    { 61885882, 169 }, // 48.94, 9.137 x 48.96, 9.163
    { 61886033, 1595 }, // 48.75, 9.163 x 48.78, 9.189
    { 61886360, 169 }, // 48.94, 9.425 x 48.96, 9.451
    { 61898102, 305 }, // 50.88, 10.55 x 50.9, 10.58
    { 61973999, 134 }, // 52.48, 13.33 x 52.5, 13.36
    { 61974352, 136 }, // 52.5, 13.36 x 52.53, 13.38
    { 62072639, 1510 }, // 52.37, 16.9 x 52.4, 16.92
    { 62072682, 1510 }, // 52.4, 16.9 x 52.42, 16.92
    { 62072725, 1510 }, // 52.37, 16.92 x 52.4, 16.95
    { 62072768, 1510 }, // 52.4, 16.92 x 52.42, 16.95
    { 62271487, 260 }, // 59.29, 17.94 x 59.32, 17.97
    { 151255697, 1002 }, // 29.25, 47.96 x 29.28, 47.99
    { 151860305, 1587 }, // 40.36, 49.85 x 40.39, 49.87
    { 162305944, 1177 }, // 33.84, 132.7 x 33.86, 132.8
    { 162450808, 2263 }, // 35.72, 139.8 x 35.75, 139.8
    { 162450811, 2223 }, // 35.75, 139.8 x 35.78, 139.8
    { 162450897, 2223 }, // 35.75, 139.8 x 35.78, 139.8
    { 162450899, 2223 }, // 35.75, 139.8 x 35.78, 139.9
    { 162450905, 2223 }, // 35.75, 139.9 x 35.78, 139.9
    { 162450907, 2223 }, // 35.75, 139.9 x 35.78, 139.9
    { 162450911, 2005 }, // 35.8, 139.9 x 35.83, 139.9
    { 162450929, 2223 }, // 35.75, 139.9 x 35.78, 139.9
    { 162450931, 2223 }, // 35.75, 139.9 x 35.78, 140
    { 162450937, 2223 }, // 35.75, 140 x 35.78, 140
    { 162450939, 2223 }, // 35.75, 140 x 35.78, 140
    { 162451281, 2223 }, // 35.75, 140 x 35.78, 140.1
    { 162451283, 2223 }, // 35.75, 140.1 x 35.78, 140.1
    { 162697024, 1736 }, // 45.69, 126.6 x 45.71, 126.6
    { 172124673, 2123 }, // -32.93, 151.8 x -32.91, 151.8
    { 103729834, 1678 }, // 25.76, -100.3 x 25.78, -100.3
    { 113170325, 292 }, // 40.74, -73.99 x 40.76, -73.98
    { 153713678, 1674 }, // -30, -51.2 x -29.98, -51.18
    { 153713700, 1674 }, // -30, -51.18 x -29.98, -51.17
    { 238342614, 1611 }, // 40.42, -3.721 x 40.43, -3.708
    { 239030251, 693 }, // 43.29, 5.375 x 43.3, 5.388
    { 244774907, 327 }, // 40.82, 14.18 x 40.84, 14.2
    { 249755989, Bucket(2735) }, // 47.14, 27.62 x 47.15, 27.63
    { 606387153, 2330 }, // 25.3, 51.42 x 25.32, 51.43
    { 646361821, 2000 }, // 25.12, 121.5 x 25.13, 121.5
    { 646361992, 2000 }, // 25.13, 121.5 x 25.15, 121.5
    { 649803240, 2263 }, // 35.72, 139.8 x 35.74, 139.8
    { 649803242, 2263 }, // 35.72, 139.8 x 35.74, 139.8
    { 649803243, 2223 }, // 35.74, 139.8 x 35.75, 139.8
    { 649803584, 2263 }, // 35.72, 139.8 x 35.74, 139.8
    { 649803585, 2223 }, // 35.74, 139.8 x 35.75, 139.8
    { 649803586, 2263 }, // 35.72, 139.8 x 35.74, 139.8
    { 649803587, 2223 }, // 35.74, 139.8 x 35.75, 139.8
    { 649803592, 2263 }, // 35.72, 139.8 x 35.74, 139.9
    { 649803593, 2223 }, // 35.74, 139.8 x 35.75, 139.9
    { 649803594, 2263 }, // 35.72, 139.9 x 35.74, 139.9
    { 649803595, 2223 }, // 35.74, 139.9 x 35.75, 139.9
    { 649803616, 2263 }, // 35.72, 139.9 x 35.74, 139.9
    { 649803617, 2223 }, // 35.74, 139.9 x 35.75, 139.9
    { 649803618, 2263 }, // 35.72, 139.9 x 35.74, 139.9
    { 649803619, 2223 }, // 35.74, 139.9 x 35.75, 139.9
    { 649803624, 2263 }, // 35.72, 139.9 x 35.74, 139.9
    { 649803625, 2223 }, // 35.74, 139.9 x 35.75, 139.9
    { 649803626, 2263 }, // 35.72, 139.9 x 35.74, 139.9
    { 649803627, 2223 }, // 35.74, 139.9 x 35.75, 139.9
    { 649803712, 2263 }, // 35.72, 139.9 x 35.74, 139.9
    { 649803713, 2223 }, // 35.74, 139.9 x 35.75, 139.9
    { 649803714, 2263 }, // 35.72, 139.9 x 35.74, 139.9
    { 649803715, 2223 }, // 35.74, 139.9 x 35.75, 139.9
    { 649803720, 2263 }, // 35.72, 139.9 x 35.74, 140
    { 649803721, 2223 }, // 35.74, 139.9 x 35.75, 140
    { 649803722, 2263 }, // 35.72, 140 x 35.74, 140
    { 649803723, 2223 }, // 35.74, 140 x 35.75, 140
    { 649803744, 2263 }, // 35.72, 140 x 35.74, 140
    { 649803745, 2223 }, // 35.74, 140 x 35.75, 140
    { 649803746, 2263 }, // 35.72, 140 x 35.74, 140
    { 649803747, 2223 }, // 35.74, 140 x 35.75, 140
    { 649803752, 2263 }, // 35.72, 140 x 35.74, 140
    { 649803753, 2223 }, // 35.74, 140 x 35.75, 140
    { 649803754, 2263 }, // 35.72, 140 x 35.74, 140
    { 649803755, 2223 }, // 35.74, 140 x 35.75, 140
    { 649805120, 2263 }, // 35.72, 140 x 35.74, 140
    { 649805121, 2223 }, // 35.74, 140 x 35.75, 140
    { 649805122, 2263 }, // 35.72, 140 x 35.74, 140.1
    { 649805123, 2223 }, // 35.74, 140 x 35.75, 140.1
    { 649805128, 2263 }, // 35.72, 140.1 x 35.74, 140.1
    { 649805129, 2223 }, // 35.74, 140.1 x 35.75, 140.1
    { 649805130, 2263 }, // 35.72, 140.1 x 35.74, 140.1
    { 688497326, 2123 }, // -32.93, 151.8 x -32.92, 151.8
    { 947054399, 456 }, // 38.71, -9.141 x 38.71, -9.135
    { 947054442, 456 }, // 38.71, -9.141 x 38.72, -9.135
    { 947054485, 456 }, // 38.71, -9.135 x 38.71, -9.128
    { 947054528, 456 }, // 38.71, -9.135 x 38.72, -9.128
    { 979168146, 713 }, // 41.83, 12.89 x 41.84, 12.9
    { 987895808, 1436 }, // 31.22, 29.92 x 31.22, 29.93
    { 990309034, 1398 }, // 48.41, 11.25 x 48.42, 11.26
    { 2596894943, 1177 }, // 33.83, 132.8 x 33.84, 132.8
    { 2598693247, 1506 }, // 35.19, 136.9 x 35.2, 136.9
    { 2598693930, 1506 }, // 35.2, 136.9 x 35.21, 136.9
    { 4294967295, Bucket(2742) }, // 339.5, 249.5 x 339.5, 249.5
};
}
