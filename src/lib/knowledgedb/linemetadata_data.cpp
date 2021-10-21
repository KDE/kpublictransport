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
    "221\0"
    "U13\0"
    "263\0"
    "261\0"
    "368\0"
    "362\0"
    "437\0"
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
    "372\0"
    "U76\0"
    "U77\0"
    "S60\0"
    "S3\0"
    "267\0"
    "N27\0"
    "M17\0"
    "S50\0"
    "U79\0"
    "324\0"
    "332\0"
    "WLB\0"
    "358\0"
    "S6\0"
    "RT1\0"
    "265\0"
    "S4\0"
    "RS 1\0"
    "238\0"
    "FXC\0"
    "T1 A\0"
    "N17\0"
    "S25\0"
    "KJ\0"
    "3F\0"
    "S46\0"
    "S45\0"
    "320\0"
    "223\0"
    "A3\0"
    "S51\0"
    "FM1\0"
    "MRT Blue\0"
    "Yellow\0"
    "Red\0"
    "289\0"
    "Overground\0"
    "S34\0"
    "LSM\0"
    "LM\0"
    "LU\0"
    "LGR9\0"
    "614P\0"
    "LGR\0"
    "196\0"
    "286\0"
    "U49\0"
    "M2\0"
    "M3\0"
    "859\0"
    "181 (SN)\0"
    "S85\0"
    "FL4\0"
    "FL1\0"
    "FL2\0"
    "ML3\0"
    "109\0"
    "PH\0"
    "657\0"
    "North Jersey Coast\0"
    "248\0"
    "330\0"
    "U43\0"
    "U41\0"
    "IK\0"
    "C-5\0"
    "ISL\0"
    "TCL\0"
    "AEL\0"
    "EAL\0"
    "TML\0"
    "28E\0"
    "S9\0"
    "Green\0"
    "C-1\0"
    "STB\0"
    "U35\0"
    "SIR1\0"
    "SG\0"
    "25N\0"
    "Q\0"
    "Bx\0"
    "L9\0"
    "RT2\0"
    "856\0"
    "S47\0"
    "215\0"
    "MD-W\0"
    "326\0"
    "D1\0"
    "N10\0"
    "N4\0"
    "N1\0"
    "H5\0"
    "364\0"
    "Raritan Valley\0"
    "DRL\0"
    "N82\0"
    "Harlem\0"
    "117\0"
    "119\0"
    "227\0"
    "269\0"
    "209\0"
    "201\0"
    "231\0"
    "213\0"
    "271\0"
    "229\0"
    "Hudson\0"
    "Port Jervis\0"
    "406\0"
    "410\0"
    "408\0"
    "SFMA\0"
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
    "300\0"
    "334\0"
    "366\0"
    "352\0"
    "314\0"
    "336\0"
    "304\0"
    "312\0"
    "354\0"
    "322\0"
    "376\0"
    "Oyster Bay\0"
    "S31\0"
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
    "845\0"
    "892\0"
    "893\0"
    "881\0"
    "878\0"
    "12E\0"
    "15E\0"
    "S26\0"
    "198\0"
    "291\0"
    "194\0"
    "S33\0"
    "N19\0"
    "Zoo Tram\0"
    "S10\0"
    "309\0"
    "307\0"
    "305\0"
    "315\0"
    "S24\0"
    "199\0"
    "TMR\0"
    "S12\0"
    "H9\0"
    "H8\0"
    "H6\0"
    "S42\0"
    "62A\0"
    "51A\0"
    "28A\0"
    "S28\0"
    "37A\0"
    "RED\0"
    "СТ\0"
    "2 Салтівська\0"
    "3 Олексіївська\0"
    "12а\0"
    "Port Washington\0"
    "U75\0"
    "U78\0"
    "Fremantle\0"
    "Mandurah\0"
    "Joondalup\0"
    "Armadale\0"
    "N20\0"
    "S20\0"
    "FC1\0"
    "FC2\0"
    "FC3\0"
    "FL5\0"
    "FL6\0"
    "FL7\0"
    "FL8\0"
    "LEX\0"
    "631\0"
    "635\0"
    "665\0"
    "639\0"
    "655\0"
    "487\0"
    "901\0"
    "RB23\0"
    "S13\0"
    "S68\0"
    "Μ3\0"
    "7bis\0"
    "Brown\0"
    "Orange\0"
    "Scala mobile\0"
    "S 8\0"
    "RS 4\0"
    "SFM 1\0"
    "SFM 4\0"
    "U44\0"
    "PAO\0"
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
    "272\0"
    "S18\0"
    "479\0"
    "825\0"
    "S 7\0"
    "RS 3\0"
    "STY\0"
    "857\0"
    "662\0"
    "666\0"
    "660\0"
    "664\0"
    "710\0"
    "752\0"
    "754\0"
    "MSC 1708\0"
    "704\0"
    "706\0"
    "S40\0"
    "S32\0"
    "S52\0"
    "195\0"
    "L21\0"
    "L22\0"
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
    "Midland\0"
    "S 5X\0"
    "Metrotranvía\0"
    "APM\0"
    "LBS\0"
    "1510\0"
    "1500\0"
    "1502\0"
    "1504\0"
    "1512\0"
    "1508\0"
    "DART\0"
    "U BRA\0"
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
    "197\0"
    "100\0"
    "BR\0"
    "SFM 6\0"
    "S19\0"
    "S21\0"
    "Gold\0"
    "Providence/Stoughton Line\0"
    "Franklin Line\0"
    "TRAB\0"
    "Montauk\0"
    "Babylon\0"
    "253\0"
    "Z30\0"
    "NS\0"
    "m2\0"
    "T6\0"
    "L10\0"
    "L11\0"
    "L9 Nord\0"
    "Tren Urbano\0"
    "A2\0"
    "Tide\0"
    "703\0"
    "1517\0"
    "1511\0"
    "532\0"
    "520\0"
    "544\0"
    "G10\0"
    "S72\0"
    "S30\0"
    "G43\0"
    "S36\0"
    "S355\0"
    "S80\0"
    "U17\0"
    "WTR\0"
    "TDV\0"
    "C-3\0"
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
    "701\0"
    "211\0"
    "235\0"
    "205\0"
    "257\0"
    "241\0"
    "277\0"
    "285\0"
    "245\0"
    "249\0"
    "Sul\0"
    "BLUE\0"
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
    "705\0"
    "25E\0"
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
    "Orlyval\0"
    "CDGVAL\0"
    "Luas Green Line\0"
    "LISA\0"
    "MetroValpo\0"
    "C-2\0"
    "Central\0"
    "S41\0"
    "RL1\0"
    "3bis\0"
    "I2\0"
    "YL\0"
    "Silver\0"
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
    "T2B\0"
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
    "4a\0"
    "WCE\0"
    "Conexão Metrô-Aeroporto\0"
    "RMGL\0"
    "RD\0"
    "SV\0"
    "BL\0"
    "L1B\0"
    "PATCO\0"
    "HOB–WTC\0"
    "HOB–33\0"
    "JSQ–33\0"
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
    "金山(Jinshan)\0"
    "G44\0"
    "Blue Line\0"
    "Violet Line\0"
    "Yellow Line\0"
    "AEx\0"
    "Magenta Line\0"
    "浦江(Pujiang)\0"
    "311\0"
    "Red Line\0"
    "环\0"
    "Xijiao\0"
    "S 6\0"
    "S27\0"
    "S15\0"
    "WES\0"
    "JL\0"
    "S35\0"
    "S29\0"
    "S17\0"
    "ExpressTram\0"
    "ATS\0"
    "T11\0"
    "Π4\0"
    "Π1\0"
    "Π2\0"
    "25S\0"
    "42X\0"
    "TGM\0"
    "43X\0"
    "GC\0"
    "L10 Sud\0"
    "G·J\0"
    "202\0"
    "902\0"
    "750\0"
    "SH\0"
    "1720\0"
    "GG\0"
    "56A\0"
    "59A\0"
    "59B\0"
    "MXP1\0"
    "SC\0"
    "Circular\0"
    "1519\0"
    "1521\0"
    "1523\0"
    "1525\0"
    "MNC\0"
    "C-4\0"
    "C-9\0"
    "СТ-2\0"
    "NT\0"
    "Aqua Line\0"
    "exo1\0"
    "exo4\0"
    "exo2\0"
    "SR\0"
    "MG\0"
    "OM\0"
    "DT\0"
    "TM\0"
    "exo5\0"
    "KD\0"
    "exo3\0"
    "U16\0"
    "捷運紅線 (新北投支線)\0"
    "RN\0"
    "KS-AE\0"
    "F3\0"
    "SS\0"
    "JN\0"
    "Orange Line\0"
    "U GUS\0"
    "U MCS\0"
    "11AB\0"
    "10AB\0"
    "9AB\0"
    "HN\0"
    "478\0"
    "472\0"
    "470\0"
    "192\0"
    "219\0"
    "268\0"
    "243\0"
    "203\0"
    "207\0"
    "259\0"
    "255\0"
    "239\0"
    "251\0"
    "293\0"
    "247\0"
    "273\0"
    "281\0"
    "234\0"
    "276\0"
    "206\0"
    "222\0"
    "260\0"
    "242\0"
    "230\0"
    "250\0"
    "288\0"
    "246\0"
    "254\0"
    "284\0"
    "256\0"
    "214\0"
    "264\0"
    "240\0"
    "252\0"
    "218\0"
    "210\0"
    "226\0"
    "232\0"
    "280\0"
    "244\0"
    "236\0"
    "GF\0"
    "TEL\0"
    "D11\0"
    "PURP\0"
    "YELL\0"
    "TT\0"
    "SIR\0"
    "<7>\0"
    "<6>\0"
    "501\0"
    "TWL\0"
    "TKL\0"
    "Yangluo\0"
    "751P\0"
    "NEC\0"
    "C-6\0"
    "NLR\0"
    "JFK\0"
    "Norte\0"
    "ARL\0"
    "1530\0"
    "AREX\0"
    "SAR-VIN\0"
    "Belford Roxo\0"
    "Deodoro\0"
    "Saracuruna\0"
    "JRI-PBI\0"
    "SAR-GIM\0"
    "Parangaba-Mucuripe\0"
    "Oeste\0"
    "E2\0"
    "TJ\0"
    "OT\0"
    "STS\0"
    "South\0"
    "1702\0"
    "North\0"
    "김포 골드라인\0"
    "Daxing Airport\0"
    "River Line\0"
    "CMET\0"
    "APT Blue\0"
    "BTS Sukhumvit\0"
    "D2\0"
    "Roch\0"
    "EDid\0"
    "Sh&C\0"
    "JB\0"
    "Dean\0"
    "Vict\0"
    "Airp\0"
    "MCUK\0"
    "Arcobaleno\0"
    "Eccl\0"
    "Asht\0"
    "Picc\0"
    "Altr\0"
    "Bury\0"
    "ESFECO\0"
    "MSC 821\0"
    "KS\0"
    "Airtrain\0"
    "Taipa\0"
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
    "TGM1\0"
    "CBTU\0"
    "550\0"
    "TEX\0"
    "656\0"
    "630\0"
    "640\0"
    "636\0"
    "654\0"
    "UP Express\0"
    "Stouffville\0"
    "Richmond Hill\0"
    "Milton\0"
    "Kitchener\0"
    "Barrie\0"
    "Lakeshore East\0"
    "LRT\0"
    "102\0"
    "101\0"
    "SI\0"
    "1645\0"
    "TrfC\0"
    "Corn\0"
    "JSQ–33 via HOB\0"
    "1M\0"
    "S61\0"
    "2M\0"
    "<F>\0"
    "HBLR\0"
    "Metro\0"
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
    "TL-3\0"
    "4-环直快\0"
    "ST\0"
    "E5\0"
    "M7\0"
    "TI\0"
    "TN\0"
    "FEX\0"
    "CK\0"
    "NH\0"
    "Z80\0"
    "751\0"
    "753\0"
    "200\0"
    "262\0"
    "208\0"
    "270\0"
    "212\0"
    "204\0"
    "266\0"
    "860\0"
    "858\0"
    "661\0"
    "667\0"
    "663\0"
    "403\0"
    "407\0"
    "409\0"
    "401\0"
    "303\0"
    "319\0"
    "313\0"
    "363\0"
    "321\0"
    "325\0"
    "377\0"
    "353\0"
    "369\0"
    "331\0"
    "373\0"
    "357\0"
    "367\0"
    "359\0"
    "351\0"
    "333\0"
    "335\0"
    "317\0"
    "104\0"
    "11L\0"
    "12L2\0"
    "12L5\0"
    "14L3\0"
    "1524\0"
    "1513\0"
    "103\0"
    "108\0"
    "115\0"
    "121\0"
    "116\0"
    "110\0"
    "118\0"
    "700\0"
    "712\0"
    "381\0"
    "382\0"
    "811\0"
    "809\0"
    "817\0"
    "805\0"
    "807\0"
    "814\0"
    "806\0"
    "800\0"
    "802\0"
    "810\0"
    "808\0"
    "812\0"
    "803\0"
    "815\0"
    "686\0"
    "688\0"
    "684\0"
    "685\0"
    "689\0"
    "683\0"
    "681\0"
    "607\0"
    "605\0"
    "603\0"
    "604\0"
    "602\0"
    "606\0"
    "609\0"
    "601\0"
    "608\0"
    "600\0"
    "463\0"
    "427\0"
    "465\0"
    "461\0"
    "425\0"
    "455\0"
    "423\0"
    "475\0"
    "457\0"
    "467\0"
    "459\0"
    "445\0"
    "473\0"
    "441\0"
    "439\0"
    "471\0"
    "431\0"
    "451\0"
    "449\0"
    "447\0"
    "429\0"
    "453\0"
    "443\0"
    "433\0"
    "421\0"
    "469\0"
    "435\0"
    "477\0"
    "424\0"
    "432\0"
    "448\0"
    "422\0"
    "462\0"
    "428\0"
    "474\0"
    "468\0"
    "436\0"
    "442\0"
    "438\0"
    "476\0"
    "452\0"
    "466\0"
    "426\0"
    "458\0"
    "480\0"
    "430\0"
    "460\0"
    "454\0"
    "440\0"
    "444\0"
    "456\0"
    "450\0"
    "446\0"
    "464\0"
    "434\0"
    "851\0"
    "849\0"
    "846\0"
    "852\0"
    "877\0"
    "875\0"
    "880\0"
    "872\0"
    "536\0"
    "537\0"
    "497\0"
    "495\0"
    "491\0"
    "415\0"
    "499\0"
    "485\0"
    "481\0"
    "492\0"
    "414\0"
    "486\0"
    "482\0"
    "416\0"
    "490\0"
    "494\0"
    "696\0"
    "694\0"
    "642\0"
    "612\0"
    "692\0"
    "698\0"
    "634\0"
    "677\0"
    "641\0"
    "675\0"
    "111\0"
    "106\0"
    "112\0"
    "114\0"
    "613\0"
    "503\0"
    "509\0"
    "506\0"
    "220\0"
    "216\0"
    "217\0"
    "107\0"
    "113\0"
    "123\0"
    "TECO\0"
    "MXP2\0"
    "APT Rose\0"
    "m1\0"
    "399\0"
    "Π5\0"
    "OH\0"
    "T9\0"
    "Atlantic City\0"
    "M9\0"
    "Route 2020\0"
    "HH\0"
    "THP1\0"
    "Ouargla tram\0"
    "TRS\0"
    "1E\0"
    "TAD\0"
    "F1\0"
    "F2\0"
    "TPC\0"
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
    "DeLijn icon 2antw.svg\0"
    "Logo tramway-budapest.svg\0"
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
    "SRS Tram Logo.svg\0"
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
    "Berlin U6.svg\0"
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
    "Berlin U9.svg\0"
    "Berlin U8.svg\0"
    "Berlin U7.svg\0"
    "Berlin U3.svg\0"
    "Berlin U2.svg\0"
    "Berlin U4.svg\0"
    "Berlin U5.svg\0"
    "Berlin U1.svg\0"
    "Prague Metro Line C.svg\0"
    "Prag Metro Logo.svg\0"
    "Prague Metro Line A.svg\0"
    "Prague Metro Line B.svg\0"
    "Nürnberg T5.png\0"
    "Tram Nürnberg Logo.png\0"
    "München Tram 17.svg\0"
    "München Tram 19.svg\0"
    "München Tram 18.svg\0"
    "Berlin S2.svg\0"
    "Berlin S25.svg\0"
    "Hamburg U3.svg\0"
    "J Church logo.svg\0"
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
    "S4 S-Bahn Stuttgart Logo (2021).svg\0"
    "Berlin Tram M1.svg\0"
    "S5 S-Bahn Stuttgart Logo (2021).svg\0"
    "TriMet MAX logo.svg\0"
    "Nürnberg T4.png\0"
    "Nürnberg T8.png\0"
    "Logo Strausberger Eisenbahn.svg\0"
    "TTC - Line 4 - Sheppard line.svg\0"
    "TTC.svg\0"
    "TTC - Line 3 - Scarborough RT line.svg\0"
    "Overground roundel.svg\0"
    "Paris transit icons - RER C.svg\0"
    "RER.svg\0"
    "Línea P (SBASE) bullet.svg\0"
    "Kyiv Metro Line 1.svg\0"
    "Kyiv Metro logo.svg\0"
    "M2 icon.svg\0"
    "Copenhagen metro logo.svg\0"
    "Kyiv Metro Line 3.svg\0"
    "Marseille métro M1.svg\0"
    "Panneau Métro de Marseille.svg\0"
    "Marseille métro M2.svg\0"
    "Berlin S85.svg\0"
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
    "Paris Transilien U.svg\0"
    "Transilien-train.svg\0"
    "SML7.svg\0"
    "Stockholm commuter rail symbol.svg\0"
    "Paris Transilien K.svg\0"
    "C-5 green.svg\0"
    "Logo Saarbahn.svg\0"
    "Berlin S9.svg\0"
    "M1-20px.svg\0"
    "Warsaw Metro logo.svg\0"
    "München S3.svg\0"
    "NYCS-bull-trans-G-Std.svg\0"
    "NYCS-bull-trans-7-Std.svg\0"
    "NYCS-bull-trans-S-Std.svg\0"
    "NYCS-bull-trans-N-Std.svg\0"
    "NYCS-bull-trans-Q-Std.svg\0"
    "NYCS-bull-trans-A-Std.svg\0"
    "NYCS-bull-trans-6-Std.svg\0"
    "NYCS-bull-trans-R-Std.svg\0"
    "Paris Transilien P.svg\0"
    "S-train service F.svg\0"
    "Logo Metropolitane Italia.svg\0"
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
    "Taipei Metro Line R.svg\0"
    "Metro Taipei Logo.svg\0"
    "Berlin S1.svg\0"
    "Frankfurt S7.svg\0"
    "Tamway-algiers.svg\0"
    "Augsburg Tram 2.svg\0"
    "S60 S-Bahn Stuttgart Logo (2021).svg\0"
    "Metra Logo.svg\0"
    "BKV h5 jms.svg\0"
    "Budapest hev symbol.svg\0"
    "Frankfurt U2.svg\0"
    "Metrolink logo.svg\0"
    "BJS Yizhuang Line icon.svg\0"
    "BJS Changping Line icon.svg\0"
    "BJS Fangshan Line icon.svg\0"
    "BKV h7 jms.svg\0"
    "Moskwa Metro Line 5.svg\0"
    "Логотип метро в системе бренда московского транспорта.svg\0"
    "Moskwa Metro Line 4.svg\0"
    "Moskwa Metro Line 3.svg\0"
    "Moskwa Metro Line 1.svg\0"
    "Línea A (Logo Metro de Medellín).svg\0"
    "Logo Metro de Medellín.svg\0"
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
    "Nürnberg U3.svg\0"
    "Nürnberg U1.svg\0"
    "Frankfurt am Main Tram 21.png\0"
    "Frankfurt am Main Tram 11.png\0"
    "Frankfurt am Main Tram 12.png\0"
    "Frankfurt am Main Tram 14.png\0"
    "Frankfurt am Main Tram 15.png\0"
    "Frankfurt am Main Tram 17.png\0"
    "Frankfurt S6.svg\0"
    "Number prefix Randen Arashiyama mainline.png\0"
    "Nürnberg T6.png\0"
    "Tokyu SG line symbol.svg\0"
    "Berlin Tram M2.svg\0"
    "Augsburg Tram 3.svg\0"
    "München S20.svg\0"
    "München S7.svg\0"
    "Logo Tramway Nantes.png\0"
    "Cptm 8.svg\0"
    "Cptm 9.svg\0"
    "Metropolitana di Roma - logo linea A.svg\0"
    "Metropolitana di Roma - logo linea B.svg\0"
    "Ferrovia regionale laziale FL1.svg\0"
    "Ferrovia regionale laziale FL2.svg\0"
    "Ferrovia regionale laziale FL4.svg\0"
    "Ferrovia regionale laziale FL5.svg\0"
    "Ferrovia regionale laziale FL6.svg\0"
    "Ferrovia regionale laziale FL7.svg\0"
    "Ferrovia regionale laziale FL8.svg\0"
    "STIB-MIVB Line 8.svg\0"
    "Brussels tramway icon.svg\0"
    "Paris transit icons - RER A.svg\0"
    "CDML1.svg\0"
    "Spårvagnslinje 10.svg\0"
    "Spårvagnslinje 8.svg\0"
    "Spårvagnslinje 13.svg\0"
    "Spårvagnslinje 2.svg\0"
    "Spårvagnslinje 4.svg\0"
    "Berlin S47.svg\0"
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
    "Frankfurt S3.svg\0"
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
    "NRW S7.svg\0"
    "Hannover S1.svg\0"
    "Paris Metro 7 bis.svg\0"
    "Metro-M.svg\0"
    "Hannover S6.svg\0"
    "Hannover S4.svg\0"
    "Metrorex logo.svg\0"
    "Paris transit icons - Tram 1.svg\0"
    "NNMetro Line 1.svg\0"
    "NNMetro.svg\0"
    "Oslo T-bane Logo.svg\0"
    "München Tram 29 (2019).svg\0"
    "DSW21 U46.svg\0"
    "Lyon tcl tram-5.svg\0"
    "Lyon tcl logo-tram-full.svg\0"
    "Logo Tramway Bordeaux ligne A.svg\0"
    "Logo Tramway Bordeaux.svg\0"
    "Logo Tramway Bordeaux ligne B.svg\0"
    "Logo Tramway Bordeaux ligne C.svg\0"
    "BJS Line 9 icon.svg\0"
    "S1 Wien.svg\0"
    "S-Bahn Wien.svg\0"
    "S2 Wien.svg\0"
    "S3 Wien.svg\0"
    "Hannover S2.svg\0"
    "BJS Daxing Line icon.svg\0"
    "BJS Line 15 icon.svg\0"
    "South Korea subway logo.svg\0"
    "Milano linea M5.svg\0"
    "Zurich tram route 10.PNG\0"
    "Zurich tram route 12.PNG\0"
    "Zurich tram route 7.PNG\0"
    "Zurich tram route 14.PNG\0"
    "Zurich tram route 11.PNG\0"
    "Zurich tram route 15.PNG\0"
    "Bart-logo.svg\0"
    "Nanchang Metro Line 1.png\0"
    "Hamburg U4.svg\0"
    "Cptm 11.svg\0"
    "Cptm 12.svg\0"
    "Cptm 7.svg\0"
    "Cptm 10.svg\0"
    "Línea B (Logo Metro de Medellín).svg\0"
    "Línea C (SBASE) bullet.svg\0"
    "Línea B (SBASE) bullet.svg\0"
    "Línea E (SBASE) bullet.svg\0"
    "Línea D (SBASE) bullet.svg\0"
    "Línea H (SBASE) bullet.svg\0"
    "Istanbul T1 Line Symbol (2020).svg\0"
    "Istanbul T5 Line Symbol (2020).svg\0"
    "Hannover S7.svg\0"
    "Montreal Metro.svg\0"
    "MtlMetro1.svg\0"
    "GZM Line 2 icon.svg\0"
    "Wien U2.svg\0"
    "Wien U1.svg\0"
    "Paris Metro 4.svg\0"
    "Paris Metro 14.svg\0"
    "Paris Metro 1.svg\0"
    "Paris Metro 9.svg\0"
    "München U4.svg\0"
    "U-Bahnlogo München.svg\0"
    "Paris Metro 10.svg\0"
    "Paris Metro 6.svg\0"
    "Paris Metro 7.svg\0"
    "Augsburg Tram 1.svg\0"
    "Bremen RS2.svg\0"
    "Bremen RS1.svg\0"
    "STIB-MIVB Line 44.svg\0"
    "STIB-MIVB Line 39.svg\0"
    "NJM Line 10 icon.svg\0"
    "Nanjing Metro Logo.svg\0"
    "NJM Line 1 icon.svg\0"
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
    "DeLijn icon 11antw.svg\0"
    "DeLijn icon 8antw.svg\0"
    "DeLijn icon 15antw.svg\0"
    "L Taraval logo.svg\0"
    "M Ocean View logo.svg\0"
    "N Judah logo.svg\0"
    "STIB-MIVB Line 19.svg\0"
    "München U5.svg\0"
    "München U6.svg\0"
    "München U3.svg\0"
    "Metro de Bilbao L2.svg\0"
    "Frankfurt U6.svg\0"
    "München U1.svg\0"
    "München U2.svg\0"
    "München U7.svg\0"
    "München U8.svg\0"
    "Kyiv Metro Line 2.svg\0"
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
    "München Tram 28.svg\0"
    "Logo Metro Rennes ligne a.svg\0"
    "Logo Metro Rennes.svg\0"
    "M1 icon.svg\0"
    "GZM Line 1 icon.svg\0"
    "S-Bahn Austria.svg\0"
    "Paris transit icons - Tram 8.svg\0"
    "STIB-MIVB Line 97.svg\0"
    "Montpellier t 4.png\0"
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
    "Hannover S51.svg\0"
    "Hannover S21.svg\0"
    "S-Bahn Salzburg.svg\0"
    "Hannover S8.svg\0"
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
    "Hamburg S21.svg\0"
    "Seoul Metro Line 5.svg\0"
    "Hamburg A2.svg\0"
    "S80 Wien.svg\0"
    "Number prefix Toyo-Rapid.svg\0"
    "C-3 dark pink.svg\0"
    "Kaohsiung Rapid Transit Circular Line.svg\0"
    "The seal of Mass Rapid Transit Bureau, Kaohsiung City Government 20140108.svg\0"
    "Hamburg S11.svg\0"
    "Hamburg S2.svg\0"
    "Hamburg S3.svg\0"
    "Hamburg A1.svg\0"
    "Línia 2 de Metrovalència.svg\0"
    "Línia 9 de Metrovalència.svg\0"
    "Línia 7 de Metrovalència.svg\0"
    "Toulouse line T2 symbol.svg\0"
    "R2 barcelona.svg\0"
    "R3 barcelona.svg\0"
    "R4 barcelona.svg\0"
    "R8 barcelona.svg\0"
    "RT1 tarragona.svg\0"
    "RT2 tarragona.svg\0"
    "RG1 girona.svg\0"
    "DSW21 U45.svg\0"
    "R12 Rodalies de Catalunya.svg\0"
    "Metro Rotterdam logo.svg\0"
    "Map Point.png\0"
    "R11 Rodalies de Catalunya.svg\0"
    "R13 Rodalies de Catalunya.svg\0"
    "R14 Rodalies de Catalunya.svg\0"
    "R15 Rodalies de Catalunya.svg\0"
    "Mitja distància Ca6.svg\0"
    "Metro do Porto linha D.svg\0"
    "Porto Metro logo.svg\0"
    "Metro do Porto linha E.svg\0"
    "Metro do Porto linha F.svg\0"
    "Metro do Porto linha A.svg\0"
    "Metro do Porto linha C.svg\0"
    "S Shuttle logo.svg\0"
    "MetroBH logo.svg\0"
    "S (South Line - Fortaleza Subway).png\0"
    "Metro do Porto linha B.svg\0"
    "Dallas Area Rapid Transit logo.svg\0"
    "Victoria line roundel.svg\0"
    "Underground.svg\0"
    "18E CCFL.png\0"
    "25E CCFL.png\0"
    "Logo VLT Carioca Linha 1.svg\0"
    "Vlt carioca logo.svg\0"
    "L12 barcelona.svg\0"
    "Logo of the Athens Tram (icon only).svg\0"
    "SHM Line 1 icon.svg\0"
    "SHM Line 16 icon.svg\0"
    "SML5.svg\0"
    "SML3.svg\0"
    "SML6.svg\0"
    "SITEUR T logo.png\0"
    "Línea 2 - Tren Concepción - Coronel, Biotren (2021).svg\0"
    "Línea 1 - Tren Mercado de Talcahuano - Hualqui, Biotren (2021).svg\0"
    "Paris Transilien J.svg\0"
    "Paris transit icons - Tram 3a.svg\0"
    "Paris transit icons - Tram 4.svg\0"
    "Paris transit icons - Tram 5.svg\0"
    "Paris transit icons - Tram 6.svg\0"
    "Paris transit icons - Tram 7.svg\0"
    "Bremen RS3.svg\0"
    "Bremen RS4.svg\0"
    "Paris Orlyval icon.svg\0"
    "Taoyuan Metro Line Airport.svg\0"
    "NYCS-bull-trans-W-Std.svg\0"
    "STIB-MIVB Line 5.svg\0"
    "Brussels Metro Logo.svg\0"
    "STIB-MIVB Line 1.svg\0"
    "Logo VLT Carioca Linha 2.svg\0"
    "München S2.svg\0"
    "Metro de Bilbao L1.svg\0"
    "STIB-MIVB Line 7.svg\0"
    "Metro de Bilbao L3.svg\0"
    "STIB-MIVB Line 92.svg\0"
    "L1 Metro de Granada.svg\0"
    "Paris Metro 2.svg\0"
    "Central Line roundel.svg\0"
    "Paris transit icons - RER E.svg\0"
    "STIB-MIVB Line 2.svg\0"
    "Berlin S41.svg\0"
    "STIB-MIVB Line 81.svg\0"
    "NMBS S-Trein logo.svg\0"
    "الخط الأول لطرامواي اليضاء.png\0"
    "الخط الثاني لطرامواي البيضاء.png\0"
    "Istanbul T4 Line Symbol.svg\0"
    "Paris Metro 13.svg\0"
    "Paris Metro 12.svg\0"
    "Paris Metro 11.svg\0"
    "Paris Metro 8.svg\0"
    "Paris Metro 5.svg\0"
    "Paris Metro 3 bis.svg\0"
    "Paris Transilien R.svg\0"
    "Paris Transilien N.svg\0"
    "Paris transit icons - RER B.svg\0"
    "SML4.svg\0"
    "SML8.svg\0"
    "SML9.svg\0"
    "SHM Line 12 icon.svg\0"
    "SML13.svg\0"
    "SML10.svg\0"
    "Incheon Metro Line 2.svg\0"
    "Seoul Metro Line U Line.svg\0"
    "Cleveland RTA logo.svg\0"
    "WMATA Yellow.svg\0"
    "WMATA Metro Logo.svg\0"
    "Seoul Metro Line 2.svg\0"
    "Seoul Metro Line 4.svg\0"
    "M1alger.png\0"
    "STIB-MIVB Line 51.svg\0"
    "STIB-MIVB Line 93.svg\0"
    "Tabriz Metro Line 1.png\0"
    "NNMetro Line 2.svg\0"
    "Helsingin metro logo.svg\0"
    "Bakerloo line roundel.svg\0"
    "H&c line roundel.svg\0"
    "Circle Line roundel.svg\0"
    "W&c line roundel.svg\0"
    "Jubilee line roundel.svg\0"
    "Metropolitan line roundel.svg\0"
    "District line roundel.svg\0"
    "Logo metropolitana di Catania.svg\0"
    "Astram Logo.svg\0"
    "Subway FukuokaHakozaki.svg\0"
    "Fukuoka City Subway Logo.svg\0"
    "Piccadilly line roundel.svg\0"
    "Northern line roundel.svg\0"
    "Subway FukuokaKuko.svg\0"
    "Number prefix Minatomirai.svg\0"
    "Yokohama Municipal Subway Logo.svg\0"
    "Esfahan Metro Logo.png\0"
    "Tehran Metro Line 7.png\0"
    "Tehran Metro Logo.svg\0"
    "Tehran Metro Line 4.png\0"
    "Busan-Gimhae Line.svg\0"
    "Nagoya Subway Logo V2 (Kamiiida Line).svg\0"
    "Nagoya Municipal Subway Logo.svg\0"
    "Kobe Municipal Subway Logo.svg\0"
    "Port Island Line logo.svg\0"
    "Subway KobeKaigan.svg\0"
    "ShenzhenMetroLine4.svg\0"
    "Istanbul M2 Line Symbol.svg\0"
    "Istanbul Metro Logo.svg\0"
    "Istanbul M4 Line Symbol.svg\0"
    "Istanbul M1 Line Symbol.svg\0"
    "Istanbul M3 Line Symbol.svg\0"
    "Istanbul M6 Line Symbol.svg\0"
    "Subway KobeSeishin.svg\0"
    "MRT Blue.svg\0"
    "MRT (Bangkok) logo.svg\0"
    "MRT Purple.svg\0"
    "Lima Metro Linea 1.svg\0"
    "Lima Metro logo 2 (full).svg\0"
    "Seoul Metro Line Shinbundang.svg\0"
    "Sendai City Subway Logo.svg\0"
    "Yokohama Municipal Subway Blue Line symbol.svg\0"
    "Yokohama Municipal Subway Green Line symbol.svg\0"
    "Santiago de Chile L1.svg\0"
    "Santiago de Chile L4A.svg\0"
    "Santiago de Chile L5.svg\0"
    "Santiago de Chile L6.svg\0"
    "Paris Metro 3.svg\0"
    "Kazan-metro-Logo.svg\0"
    "Novosibirsk Metro logo.svg\0"
    "Ekb metro logo.svg\0"
    "Icon V (set f).png\0"
    "Icon L (set orange).png\0"
    "Minsk Metro First Line logo.svg\0"
    "Minsk metro logo.svg\0"
    "Minsk Metro Second Line logo.svg\0"
    "Sofia Metro Logo.svg\0"
    "Metropolitano Lisboa logo.svg\0"
    "Glasgow Subway.svg\0"
    "Subway FukuokaNanakuma.svg\0"
    "Metro Almaty line A.svg\0"
    "Almaty metro logo.svg\0"
    "Logo of the Pyongyang Metro.svg\0"
    "Tehran Metro Line 1.png\0"
    "Paris Transilien H.svg\0"
    "Tehran Metro Line 3.png\0"
    "Línea 1 Metro de Sevilla.svg\0"
    "Símbolo del Metro de Sevilla.svg\0"
    "MetroMalaga L2.svg\0"
    "Símbolo del Metro de Málaga.svg\0"
    "MetroMalaga L1.svg\0"
    "Metro Palma M2.svg\0"
    "Metro Palma M1.svg\0"
    "Metro Tbilisi logo.svg\0"
    "Kyiv Urban Electric Train.svg\0"
    "Symbole Lille 2.svg\0"
    "Lille Metro Logo 2017.svg\0"
    "Symbole Lille 1.svg\0"
    "Baku Subway logo.svg\0"
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
    "Shijiazhuang Metro.svg\0"
    "Madrid-MetroLinea6.svg\0"
    "Madrid-MetroLinea11.svg\0"
    "Chennai Metro logo.svg\0"
    "SHM Line 17 icon.svg\0"
    "Daegu Metro Line 2.svg\0"
    "Daegu Metro Line 1.svg\0"
    "Madrid MetroLigero1.svg\0"
    "Stadtbahn Madrid Logo.svg\0"
    "Madrid MetroLigero2.svg\0"
    "Madrid MetroLigero3.svg\0"
    "Incheon Metro Line 1.png\0"
    "STIB-MIVB Line 3.svg\0"
    "R7 barcelona.svg\0"
    "Sul blue.png\0"
    "C-10 lime.svg\0"
    "C-1 light blue.svg\0"
    "C-7 red.svg\0"
    "长沙地铁2号线线标.svg\0"
    "长沙地铁1号线线标.svg\0"
    "CLRT Line 4 icon.svg\0"
    "CLRT Line 3 icon.svg\0"
    "Ankaray logo.svg\0"
    "Ankara Metro logo.svg\0"
    "Kaohsiung Rapid Transit Orange Line.svg\0"
    "Kaohsiung Rapid Transit Red Line.svg\0"
    "Seoul Metro Line 3.svg\0"
    "Seoul Metro Line 9.svg\0"
    "NBRT Line 2 icon.svg\0"
    "TTC - Line 1 - Yonge-University-Spadina line.svg\0"
    "TTC - Line 2 - Bloor-Danforth line.svg\0"
    "SRT-1.png\0"
    "RMRG logo.svg\0"
    "Delhi Metro logo.svg\0"
    "Line1mtymetro.png\0"
    "Line2mtymetro.png\0"
    "DLM Line 2 icon.svg\0"
    "Dalian Metro Logo Image Only.svg\0"
    "Shenyang Metro Corporation Logo.svg\0"
    "Icon of FZM L1.svg\0"
    "DLM Line 3 icon.svg\0"
    "NJM Line S1 icon.svg\0"
    "NJM Line S3 icon.svg\0"
    "ShenzhenMetroLine1.svg\0"
    "Seoul Metro Line 8.svg\0"
    "Seoul Metro Line 6.svg\0"
    "WMATA Orange.svg\0"
    "WMATA Red.svg\0"
    "WMATA Silver.svg\0"
    "WMATA Blue.svg\0"
    "WMATA Green.svg\0"
    "Seoul Metro Line 7.svg\0"
    "Logo of Miami-Dade County, Florida.svg\0"
    "STIB-MIVB Line 6.svg\0"
    "Línea 2 CAMETRO.png\0"
    "Metro de Caracas (Venezuela) logo.svg\0"
    "Línea 3 CAMETRO.png\0"
    "MetroDF Línea 1.svg\0"
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
    "PATCO Line.svg\0"
    "PATH.svg\0"
    "CRRT line1 logo.svg\0"
    "Athens Metro Line 1.svg\0"
    "Athens Metro Line 2.svg\0"
    "Rinkai Line symbol.svg\0"
    "Yerevan Metro.svg\0"
    "Wuhan Metro Logo.svg\0"
    "TranviaParlaLogo.svg\0"
    "Metro İzmir logo.svg\0"
    "Jaipur Metro Logo.png\0"
    "STIB-MIVB Line 4.svg\0"
    "STIB-MIVB Line 25.svg\0"
    "STIB-MIVB Line 55.svg\0"
    "STIB-MIVB Line 82.svg\0"
    "Lrtalogo.svg\0"
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
    "Logo of Tokyo Metro Hanzōmon Line.svg\0"
    "Logo of Tokyo Metro Fukutoshin Line.svg\0"
    "Osaka Metro Sennichimae line symbol.svg\0"
    "Osaka Metro Midosuji line symbol.svg\0"
    "Osaka Metro Imazatosuji line symbol.svg\0"
    "Osaka Metro Sakaisuji line symbol.svg\0"
    "Osaka Metro Nagahori Tsurumi-ryokuchi line symbol.svg\0"
    "Osaka Metro Yotsubashi line symbol.svg\0"
    "2T-2.svg\0"
    "Subway KyotoKarasuma.svg\0"
    "Kyoto MTB Logo.svg\0"
    "Subway KyotoTozai.png\0"
    "Nagoya Subway Logo V2 (Sakura-dori Line).svg\0"
    "Nagoya Subway Logo V2 (Higashiyama Line).svg\0"
    "Nagoya Subway Logo V2 (Meiko Line).svg\0"
    "Nagoya Subway Logo V2 (Tsurumai Line).svg\0"
    "Nagoya Subway Logo V2 (Meijo Line).svg\0"
    "Kolkata Metro Logo.svg\0"
    "Istanbul M5 Line Symbol.svg\0"
    "LACMTA Circle B Line.svg\0"
    "Busan Metro Line 3.svg\0"
    "Busan Metro Line 1.svg\0"
    "Busan Metro Line 2.svg\0"
    "CDML7.svg\0"
    "CDML3.svg\0"
    "CDML2.svg\0"
    "CDML4.svg\0"
    "CDML10.svg\0"
    "Lucknow Metro Logo.svg\0"
    "JinanMetro Logo.svg\0"
    "WHM Line 1 icon.svg\0"
    "HZM Line 2 icon.svg\0"
    "NBRT Line 1 icon.svg\0"
    "BJS Line 16 icon.svg\0"
    "Amoy Metro logo.svg\0"
    "JR JL line symbol.svg\0"
    "Nürnberg T7.png\0"
    "SRT-4.png\0"
    "SRT-2.png\0"
    "Amsterdam unofficial metro icon line 52.svg\0"
    "Paris transit icons - Tram 11.svg\0"
    "TianjinMetro.svg\0"
    "STIB-MIVB Line 9.svg\0"
    "Gyeongchun Line.svg\0"
    "Milano S1.svg\0"
    "Linee S di Milano.svg\0"
    "Milano S2.svg\0"
    "Milano S3.svg\0"
    "Milano S4.svg\0"
    "Milano S5.svg\0"
    "Milano S6.svg\0"
    "24E CCFL.png\0"
    "Seoul Metro Line 1.svg\0"
    "Seoul Metro Line Seohae Bilingual.svg\0"
    "UTA S-Line logo.svg\0"
    "Seoul Metro Line Gyeonggang.svg\0"
    "Euskotren TR.svg\0"
    "Milano S8.svg\0"
    "Milano S13.svg\0"
    "Milano S9.svg\0"
    "Milano S11.svg\0"
    "C-4 dark blue.svg\0"
    "C-9 orange.svg\0"
    "C-2 green.svg\0"
    "Yurikamome line symbol.svg\0"
    "Tokyo Sakura Tram symbol.svg\0"
    "Tokyu TY line symbol.svg\0"
    "ShenzhenMetroLine11.svg\0"
    "Saitama Stadium Line symbol.svg\0"
    "Tokyu MG line symbol.svg\0"
    "Tokyu OM line symbol.svg\0"
    "Tokyu DT line symbol.svg\0"
    "Tokyu IK line symbol.svg\0"
    "Tokyu TM line symbol.svg\0"
    "Tokyu KD line symbol.svg\0"
    "New Shuttle Line symbol.svg\0"
    "Logo trireno black.svg\0"
    "Taipei Metro Line Xinbeitou Branch.svg\0"
    "Taipei Metro Line BL.svg\0"
    "Berlin S26.svg\0"
    "Logo VLT Carioca Linha 3.svg\0"
    "Tehran Metro Line 6.png\0"
    "Number prefix SkyAccess.svg\0"
    "TfNSW M.svg\0"
    "Istanbul F3 Line Symbol.svg\0"
    "SeibuShinjuku.svg\0"
    "NJM Line S7 icon.svg\0"
    "NJM Line S9 icon.svg\0"
    "NJM Line S8 icon.svg\0"
    "WHM Line 2 icon.svg\0"
    "Number prefix Hankai Tramway line.png\0"
    "Osaka Metro Nanko Port Town line symbol.svg\0"
    "MRT Singapore Destination 13.png\0"
    "ShenzhenMetroLine3.svg\0"
    "WHM Line 4 icon.svg\0"
    "ShenzhenMetroLine5.svg\0"
    "NYCS-bull-trans-1-Std.svg\0"
    "NYCS-bull-trans-2-Std.svg\0"
    "NYCS-bull-trans-3-Std.svg\0"
    "NYCS-bull-trans-4-Std.svg\0"
    "TfNSW L.svg\0"
    "NYCS-bull-trans-5-Std.svg\0"
    "ShenzhenMetroLine9.svg\0"
    "NYCS-bull-trans-M-Std.svg\0"
    "NYCS-bull-trans-L-Std.svg\0"
    "Logo PT Kereta Api Indonesia (Persero) 2020.svg\0"
    "NYCS-bull-trans-B-Std.svg\0"
    "NYCS-bull-trans-F-Std.svg\0"
    "NYCS-bull-trans-C-Std.svg\0"
    "NYCS-bull-trans-D-Std.svg\0"
    "NYCS-bull-trans-E-Std.svg\0"
    "C-6 dark blue.svg\0"
    "GZL3.svg\0"
    "Cptm 13.svg\0"
    "VTA-Green-icon.svg\0"
    "VTA-Blue-icon.svg\0"
    "ARLbangkok.svg\0"
    "GZM Line 9 icon.svg\0"
    "Berlin S42.svg\0"
    "O ( West Line - Fortaleza Subway).png\0"
    "S-train service A.svg\0"
    "KTM Komuter logo.png\0"
    "Moskwa Metro Line 15.svg\0"
    "Tobu Tojo Line (TJ) symbol.svg\0"
    "JRW kinki-O.svg\0"
    "Seoul Metro Line Gimpo Goldline Bilingual.svg\0"
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
    "Xuzhou Metro Logo.svg\0"
    "NBRT Line 3 icon.svg\0"
    "ZZMetro Line 5.svg\0"
    "Logo Tramway Bordeaux ligne D.svg\0"
    "DeLijn icon 1antw.svg\0"
    "Icon of FZM L2.svg\0"
    "CDML5.svg\0"
    "Montpellier t 2.png\0"
    "Montpellier t 3.png\0"
    "Montpellier t 1.png\0"
    "GO Milton logo.svg\0"
    "GO Kitchener logo.svg\0"
    "GO Barrie logo.svg\0"
    "GO Lakeshore East logo.svg\0"
    "GO Lakeshore West logo.svg\0"
    "Taipei Metro Line Y.svg\0"
    "Milano linea M2.svg\0"
    "Milano linea M3.svg\0"
    "Milano linea M1.svg\0"
    "M4 icon.svg\0"
    "SeibuIkebukuro.svg\0"
    "Tobu Skytree Line (TS) symbol.svg\0"
    "St Louis MetroLink Logo.svg\0"
    "Milano S7.svg\0"
    "Bcr logo.svg\0"
    "Number prefix Keikyū.PNG\0"
    "ShenzhenMetroLine6.svg\0"
    "ShenzhenMetroLine10.svg\0"
    "R1 barcelona.svg\0"
    "CDML18.svg\0"
    "NP-ST.png\0"
    "Istanbul M7 Line Symbol.svg\0"
    "Tobu Isesaki Line (TI) symbol.svg\0"
    "Tobu Nikko Line (TN) symbol.svg\0"
    "FEX VBB (2021).png\0"
    "Minsk Metro Third Line logo.svg\0"
    "NP-NH.png\0"
    "Hanoi Metro Line 3 Symbol.png\0"
    "CDML6.svg\0"
    "CDML8.svg\0"
    "CDML17.svg\0"
    "Paris Transilien L.svg\0"
    "NBRT Line 4 icon.svg\0"
    "Istanbul T5 Line Symbol.svg\0"
    "SML15.svg\0"
    "Tramİzmir logo.svg\0"
    "Houston Metro icon.svg\0"
    "Logo du M1 de Lausanne.svg\0"
    "Logo linea 2 Napoli.svg\0"
    "Paris transit icons - Tram 9.svg\0"
    "Istanbul M9 Line Symbol.svg\0"
    "HZM Line 1 icon.svg\0"
    "CDML9.svg\0"
    "ShenzhenMetroLine2.svg\0"
    "ShenzhenMetroLine8.svg\0"
    "BJS Batong Line icon.svg\0"
    "Istanbul F1 Line Symbol.svg\0"
    "Istanbul Line Symbol Tünel.png\0"
    "Istanbul F2 Line Symbol.svg\0"
    "Línea 1 CAMETRO.png\0"
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
    { 29, 128, 19, LineMetaDataContent::Tramway, Color{0x003388} }, // M6 OSM: 11145 WD: Q62511960 52.52, 13.4 x 52.55, 13.62
    { 16, 147, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 2 OSM: 11201 WD: Q1854674 51.17, 4.35 x 51.26, 4.464
    { 16, NoLogo, 169, LineMetaDataContent::Tramway, Color{0xffd800} }, // 2 OSM: 12016 WD: Q950776 47.47, 19.05 x 47.51, 19.08
    { 33, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa70049} }, // S OSM: 14163 -37.2, 174.8 x -36.84, 175
    { 37, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfec330} }, // E OSM: 14165 -37, 174.8 x -36.84, 174.9
    { 39, 195, 209, LineMetaDataContent::RapidTransit, Color{0x8070b7} }, // S7 OSM: 14809 WD: Q7388362 52.39, 13.07 x 52.57, 13.57
    { 4, 225, 209, LineMetaDataContent::RapidTransit, Color{0x8070b7} }, // S75 OSM: 14810 WD: Q3744483 52.5, 13.45 x 52.57, 13.54
    { 42, 240, 209, LineMetaDataContent::RapidTransit, Color{0xf25721} }, // S5 OSM: 14811 WD: Q3743008 52.5, 13.28 x 52.59, 13.91
    { 45, 254, 209, LineMetaDataContent::RapidTransit, Color{0x52b447} }, // S8 OSM: 14984 WD: Q4048678 52.35, 13.29 x 52.69, 13.63
    { 48, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x9313ba} }, // S2 OSM: 16111 48.95, 8.283 x 49.11, 8.505
    { 53, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xb3ee3a} }, // 1 OSM: 17413 WD: Q318073 51.49, 10.79 x 51.52, 10.8
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x2e8b57} }, // 2 OSM: 17415 WD: Q318073 51.5, 10.78 x 51.51, 10.82
    { 57, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x996633} }, // 3 OSM: 17839 48.99, 8.347 x 49.04, 8.411
    { 53, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 1 OSM: 17840 48.98, 8.347 x 49.02, 8.479
    { 51, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // S11 OSM: 17842 48.87, 8.373 x 49.13, 8.518
    { 59, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // S1 OSM: 17843 48.8, 8.373 x 49.13, 8.458
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x18a6d9} }, // 5 OSM: 17847 49, 8.347 x 49.02, 8.444
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffcc00} }, // 4 OSM: 17848 48.99, 8.347 x 49.05, 8.452
    { 45, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x6d682a} }, // S8 OSM: 17849 48.44, 8.215 x 49.01, 8.863
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff9933} }, // 8 OSM: 17855 48.98, 8.452 x 49, 8.479
    { 62, 268, 19, LineMetaDataContent::Tramway, Color{0x108449} }, // M10 OSM: 17865 WD: Q62500489 52.5, 13.36 x 52.54, 13.45
    { 55, 288, 19, LineMetaDataContent::Tramway, Color{0x00cc00} }, // M13 OSM: 17884 WD: Q62512599 52.51, 13.34 x 52.56, 13.48
    { 67, 308, 19, LineMetaDataContent::Tramway, Color{0x996699} }, // 21 OSM: 17885 WD: Q62476959 52.45, 13.45 x 52.53, 13.52
    { 70, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xeda5b4} }, // U13 OSM: 19070 48.76, 9.134 x 48.81, 9.254
    { 75, 327, 19, LineMetaDataContent::Tramway, Color{0x009999} }, // 63 OSM: 19115 WD: Q63996601 52.43, 13.53 x 52.5, 13.61
    { 79, 346, 19, LineMetaDataContent::Tramway, Color{0x669933} }, // 61 OSM: 19265 WD: Q62512736 52.43, 13.53 x 52.46, 13.69
    { 83, 365, 19, LineMetaDataContent::Tramway, Color{0x009933} }, // 68 OSM: 19271 WD: Q62470539 52.37, 13.57 x 52.46, 13.65
    { 87, 384, 19, LineMetaDataContent::Tramway, Color{0x006633} }, // 62 OSM: 19296 WD: Q62476843 52.42, 13.57 x 52.51, 13.61
    { 91, 403, 19, LineMetaDataContent::Tramway, Color{0x993333} }, // 37 OSM: 19451 WD: Q62499413 52.45, 13.5 x 52.53, 13.53
    { 95, NoLogo, 422, LineMetaDataContent::Tramway, Color{} }, // 88 OSM: 19597 WD: Q638246 52.46, 13.63 x 52.48, 13.81
    { 98, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xc7956c} }, // U1 OSM: 19916 48.73, 9.111 x 48.81, 9.277
    { 101, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf58220} }, // U2 OSM: 19917 48.77, 9.122 x 48.83, 9.238
    { 104, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x935f39} }, // U3 OSM: 19918 48.71, 9.112 x 48.73, 9.202
    { 107, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7a68ae} }, // U4 OSM: 19919 48.77, 9.158 x 48.79, 9.25
    { 110, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00baf2} }, // U5 OSM: 19920 48.7, 9.136 x 48.8, 9.187
    { 113, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xec008c} }, // U6 OSM: 19921 48.71, 9.064 x 48.81, 9.187
    { 116, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0eb48d} }, // U7 OSM: 19922 48.71, 9.173 x 48.84, 9.296
    { 119, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xc3b47d} }, // U8 OSM: 19923 48.71, 9.112 x 48.76, 9.296
    { 122, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffd503} }, // U9 OSM: 19924 48.75, 9.138 x 48.79, 9.254
    { 63, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf8b710} }, // 10 OSM: 19925 WD: Q143861 48.75, 9.167 x 48.76, 9.174
    { 125, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xcccccc} }, // U11 OSM: 19926 48.77, 9.168 x 48.8, 9.226
    { 14, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x93bbe9} }, // U12 OSM: 19927 48.72, 9.118 x 48.87, 9.271
    { 129, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x69be51} }, // U14 OSM: 19928 48.77, 9.168 x 48.84, 9.23
    { 133, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x005aab} }, // U15 OSM: 19929 48.74, 9.156 x 48.85, 9.234
    { 137, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xcccccc} }, // U19 OSM: 19930 48.79, 9.213 x 48.83, 9.238
    { 63, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x312783} }, // 10 OSM: 19941 53.06, 8.753 x 53.12, 8.9
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x005ca9} }, // 2 OSM: 19942 53.06, 8.753 x 53.12, 8.9
    { 142, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x9eb4a5} }, // 72 OSM: 20258 WD: Q6811968 -37.86, 145 x -37.8, 145.1
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf287b6} }, // 2 OSM: 22852 54.08, 12.08 x 54.11, 12.17
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf8a500} }, // 6 OSM: 22871 54.07, 12.09 x 54.09, 12.14
    { 53, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x5d106a} }, // 1 OSM: 23389 54.09, 12.05 x 54.16, 12.16
    { 57, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x690713} }, // 3 OSM: 23742 54.07, 12.09 x 54.11, 12.18
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc30175} }, // 4 OSM: 23743 54.07, 12.1 x 54.11, 12.18
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe2001d} }, // 5 OSM: 23747 54.06, 12.05 x 54.16, 12.14
    { 107, 440, 452, LineMetaDataContent::Subway, Color{0x029540} }, // U4 OSM: 27113 WD: Q877322 48.18, 16.26 x 48.25, 16.39
    { 113, 468, 452, LineMetaDataContent::Subway, Color{0x9c6830} }, // U6 OSM: 27115 WD: Q281409 48.13, 16.31 x 48.26, 16.4
    { 0, 480, NoLogo, LineMetaDataContent::Subway, Color{0x302276} }, // U70 OSM: 27662 WD: Q661002 51.22, 6.566 x 51.33, 6.796
    { 145, 480, NoLogo, LineMetaDataContent::Subway, Color{0x302276} }, // U76 OSM: 27663 WD: Q661002 51.22, 6.566 x 51.33, 6.806
    { 149, 480, NoLogo, LineMetaDataContent::Subway, Color{0x302276} }, // U77 OSM: 27667 WD: Q661002 51.17, 6.735 x 51.24, 6.834
    { 154, 494, 19, LineMetaDataContent::Tramway, Color{0x0b9ada} }, // 60 OSM: 28289 WD: Q62512766 52.44, 13.5 x 52.46, 13.64
    { 157, 513, 209, LineMetaDataContent::RapidTransit, Color{0x055a99} }, // S3 OSM: 28314 WD: Q7388282 52.43, 13.2 x 52.53, 13.75
    { 161, 527, 19, LineMetaDataContent::Tramway, Color{0x009933} }, // 67 OSM: 28352 WD: Q66459350 52.44, 13.51 x 52.46, 13.59
    { 165, 546, 19, LineMetaDataContent::Tramway, Color{0x993333} }, // 27 OSM: 28377 WD: Q66091843 52.44, 13.46 x 52.56, 13.59
    { 168, 565, 19, LineMetaDataContent::Tramway, Color{0xa6422a} }, // M17 OSM: 28391 WD: Q62512560 52.45, 13.51 x 52.57, 13.53
    { 173, 585, 19, LineMetaDataContent::Tramway, Color{0x36ab94} }, // 50 OSM: 28420 WD: Q62499869 52.54, 13.34 x 52.61, 13.43
    { 176, 480, NoLogo, LineMetaDataContent::Subway, Color{0x302276} }, // U79 OSM: 28424 WD: Q661002 51.19, 6.739 x 51.47, 6.815
    { 67, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x945692} }, // 21 OSM: 29440 WD: Q4415661 51.91, 4.368 x 51.94, 4.525
    { 181, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x945692} }, // 24 OSM: 29446 WD: Q14500289 51.91, 4.341 x 51.94, 4.525
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // 6 OSM: 30058 49.16, 16.59 x 49.23, 16.61
    { 52, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xd62631} }, // 11 OSM: 33897 51.28, 12.22 x 51.4, 12.4
    { 185, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf2a100} }, // 32 OSM: 33900 51.31, 12.28 x 51.37, 12.38
    { 26, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe3000f} }, // 16 OSM: 34068 51.3, 12.37 x 51.4, 12.4
    { 188, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x005395} }, // WLB OSM: 34086 WD: Q875199 48, 16.23 x 48.2, 16.37
    { 40, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0e4094} }, // 7 OSM: 34148 51.34, 12.27 x 51.36, 12.48
    { 83, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xcea4cb} }, // 68 OSM: 34480 50.7, 6.985 x 50.76, 7.156
    { 59, 604, 209, LineMetaDataContent::RapidTransit, Color{0x5c8e3c} }, // S1 OSM: 35610 WD: Q18946157 48.59, 8.861 x 48.8, 9.444
    { 48, 640, 209, LineMetaDataContent::RapidTransit, Color{0xff2e1d} }, // S2 OSM: 35611 WD: Q66537943 48.68, 9.105 x 48.83, 9.527
    { 157, 676, 209, LineMetaDataContent::RapidTransit, Color{0xff7d24} }, // S3 OSM: 35612 WD: Q67504621 48.69, 9.105 x 48.94, 9.428
    { 123, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe6877e} }, // 9 OSM: 36132 50.92, 6.907 x 50.94, 7.096
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8cc63f} }, // 12 OSM: 36133 50.9, 6.939 x 51.03, 6.96
    { 134, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00accd} }, // 15 OSM: 36134 50.92, 6.898 x 51.02, 6.966
    { 193, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x83898f} }, // 58 OSM: 37338 WD: Q28428375 -37.84, 144.9 x -37.74, 145
    { 196, 712, 209, LineMetaDataContent::RapidTransit, Color{0x874a0a} }, // S6 OSM: 37419 WD: Q67501804 48.76, 8.872 x 48.83, 9.195
    { 200, NoLogo, 748, LineMetaDataContent::Tramway, Color{0xff0000} }, // T1 OSM: 38872 WD: Q5985908 28.45, -16.32 x 28.49, -16.25
    { 134, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0e4094} }, // 15 OSM: 38883 51.29, 12.34 x 51.34, 12.44
    { 204, NoLogo, 480, LineMetaDataContent::Tramway, Color{0xc8d300} }, // 65 OSM: 39079 WD: Q20035842 50.72, 7.071 x 50.76, 7.156
    { 27, 786, NoLogo, LineMetaDataContent::Tramway, Color{0x9049a8} }, // 6 OSM: 48024 WD: Q62296933 52.13, 11.57 x 52.15, 11.68
    { 53, 814, NoLogo, LineMetaDataContent::Tramway, Color{0xb6005c} }, // 1 OSM: 48025 WD: Q62289804 52.11, 11.59 x 52.18, 11.64
    { 9, 842, NoLogo, LineMetaDataContent::Tramway, Color{0x73e700} }, // 4 OSM: 48453 WD: Q62295350 52.13, 11.58 x 52.16, 11.67
    { 6, 870, NoLogo, LineMetaDataContent::Tramway, Color{0xb48654} }, // 5 OSM: 48459 WD: Q62296384 52.11, 11.58 x 52.16, 11.64
    { 190, 898, 920, LineMetaDataContent::RapidTransit, Color{0x32cd32} }, // B OSM: 51750 WD: Q1903862 55.65, 12.27 x 55.81, 12.59
    { 53, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x62b32c} }, // 1 OSM: 51858 51.28, 12.31 x 51.38, 12.42
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf7c53a} }, // 2 OSM: 51859 339.5, 249.5 x 339.5, 249.5
    { 113, 930, 944, LineMetaDataContent::Subway, Color{0x8070b7} }, // U6 OSM: 51942 WD: Q99720 52.44, 13.28 x 52.59, 13.39
    { 53, 955, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 1 OSM: 52282 WD: Q106921117 57.64, 11.9 x 57.73, 12.05
    { 6, 977, NoLogo, LineMetaDataContent::Tramway, Color{0xeb1923} }, // 5 OSM: 52617 WD: Q106921184 57.7, 11.89 x 57.74, 12.05
    { 40, 999, NoLogo, LineMetaDataContent::Tramway, Color{0x7d4313} }, // 7 OSM: 53027 WD: Q106921197 57.64, 11.9 x 57.76, 12.07
    { 45, 1021, 209, LineMetaDataContent::RapidTransit, Color{0xffc734} }, // S8 OSM: 53231 WD: Q17148488 48, 11.17 x 48.35, 11.79
    { 207, 1037, 209, LineMetaDataContent::RapidTransit, Color{0xff2d1d} }, // S4 OSM: 53235 WD: Q7388308 48.04, 11.04 x 48.18, 11.97
    { 27, 1053, NoLogo, LineMetaDataContent::Tramway, Color{0xfa8719} }, // 6 OSM: 53254 WD: Q106921192 57.68, 11.89 x 57.76, 12.04
    { 123, 1075, NoLogo, LineMetaDataContent::Tramway, Color{0x1e8164} }, // 9 OSM: 53748 WD: Q62299846 52.08, 11.6 x 52.18, 11.64
    { 16, 1103, NoLogo, LineMetaDataContent::Tramway, Color{0x004799} }, // 2 OSM: 53752 WD: Q62291398 52.06, 11.61 x 52.15, 11.68
    { 19, 1131, NoLogo, LineMetaDataContent::Tramway, Color{0xf29400} }, // 8 OSM: 53770 WD: Q62299313 52.06, 11.61 x 52.18, 11.68
    { 196, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x3d2d7c} }, // S6 OSM: 53844 48.75, 8.549 x 48.9, 8.705
    { 63, 1159, NoLogo, LineMetaDataContent::Tramway, Color{0xaac1e1} }, // 10 OSM: 54125 WD: Q62288523 52.11, 11.59 x 52.21, 11.67
    { 63, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x9acd32} }, // 10 OSM: 54452 WD: Q318073 51.49, 10.77 x 51.58, 10.8
    { 53, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xda0873} }, // 1 OSM: 54602 53.59, 11.41 x 53.65, 11.47
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xd9261c} }, // 2 OSM: 54603 53.59, 11.36 x 53.65, 11.47
    { 57, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe87878} }, // 3 OSM: 54604 53.57, 11.38 x 53.6, 11.47
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xdb214c} }, // 4 OSM: 54605 53.57, 11.38 x 53.65, 11.43
    { 57, 1188, NoLogo, LineMetaDataContent::Tramway, Color{0xffd600} }, // 3 OSM: 55097 WD: Q62292031 52.09, 11.58 x 52.16, 11.63
    { 211, NoLogo, 209, LineMetaDataContent::RapidTransit, Color{0x408040} }, // S 1 OSM: 55107 WD: Q56378592 52, 11.62 x 53.01, 11.87
    { 122, 1216, 944, LineMetaDataContent::Subway, Color{0xff7300} }, // U9 OSM: 58423 WD: Q99744 52.46, 13.32 x 52.56, 13.37
    { 119, 1230, 944, LineMetaDataContent::Subway, Color{0x055a99} }, // U8 OSM: 58424 WD: Q99729 52.47, 13.33 x 52.6, 13.43
    { 116, 1244, 944, LineMetaDataContent::Subway, Color{0x0b9ada} }, // U7 OSM: 58425 WD: Q99725 52.42, 13.2 x 52.54, 13.5
    { 104, 1258, 944, LineMetaDataContent::Subway, Color{0x15ac99} }, // U3 OSM: 58426 WD: Q99702 52.44, 13.24 x 52.51, 13.45
    { 101, 1272, 944, LineMetaDataContent::Subway, Color{0xff3300} }, // U2 OSM: 58428 WD: Q99697 52.5, 13.24 x 52.57, 13.41
    { 107, 1286, 944, LineMetaDataContent::Subway, Color{0xffcd00} }, // U4 OSM: 58429 WD: Q99708 52.48, 13.34 x 52.5, 13.36
    { 110, 1300, 944, LineMetaDataContent::Subway, Color{0x7d533d} }, // U5 OSM: 58430 WD: Q99711 52.49, 13.37 x 52.54, 13.63
    { 98, 1314, 944, LineMetaDataContent::Subway, Color{0x52b447} }, // U1 OSM: 58767 WD: Q99691 52.5, 13.33 x 52.51, 13.45
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0f3f93} }, // 12 OSM: 58815 51.32, 12.37 x 51.38, 12.4
    { 216, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffcc00} }, // 38 OSM: 58819 51.33, 12.37 x 51.36, 12.47
    { 57, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x62b32c} }, // 3 OSM: 58829 51.31, 12.26 x 51.38, 12.49
    { 221, 1328, 1352, LineMetaDataContent::Subway, Color{0xcf003d} }, // C OSM: 58898 WD: Q168571 50.03, 14.43 x 50.13, 14.53
    { 226, 1372, 1352, LineMetaDataContent::Subway, Color{0x00a562} }, // A OSM: 58899 WD: Q1292805 50.07, 14.34 x 50.1, 14.52
    { 190, 1396, 1352, LineMetaDataContent::Subway, Color{0xf8b322} }, // B OSM: 58900 WD: Q1460442 50.04, 14.29 x 50.11, 14.58
    { 6, 1420, 1437, LineMetaDataContent::Tramway, Color{} }, // 5 OSM: 61453 WD: Q104867893 49.41, 11.07 x 49.46, 11.14
    { 169, 1461, 19, LineMetaDataContent::Tramway, Color{0x865a46} }, // 17 OSM: 61454 WD: Q20438593 48.13, 11.49 x 48.18, 11.64
    { 138, 1482, 19, LineMetaDataContent::Tramway, Color{0xed1c24} }, // 19 OSM: 61456 WD: Q20438608 48.14, 11.46 x 48.15, 11.63
    { 22, 1503, 19, LineMetaDataContent::Tramway, Color{0x0cb14b} }, // 18 OSM: 61458 WD: Q20438601 48.1, 11.49 x 48.14, 11.6
    { 228, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x006cb2} }, // N17 OSM: 61459 48.13, 11.49 x 48.17, 11.61
    { 53, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf78a21} }, // 1 OSM: 61460 50.85, 12.07 x 50.89, 12.09
    { 48, 1524, 209, LineMetaDataContent::RapidTransit, Color{0x018a47} }, // S2 OSM: 61466 WD: Q3743635 52.34, 13.36 x 52.68, 13.59
    { 232, 1538, 209, LineMetaDataContent::RapidTransit, Color{0x018a47} }, // S25 OSM: 61469 WD: Q7388229 52.4, 13.21 x 52.64, 13.4
    { 104, 1553, 944, LineMetaDataContent::Subway, Color{0xfcdf00} }, // U3 OSM: 62839 WD: Q781351 53.54, 9.969 x 53.59, 10.08
    { 237, 1568, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfaa635} }, // J OSM: 63222 WD: Q6109356 37.72, -122.4 x 37.77, -122.4
    { 240, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf0e68c} }, // F OSM: 63224 WD: Q1137818 37.76, -122.4 x 37.81, -122.4
    { 59, 1586, 209, LineMetaDataContent::RapidTransit, Color{0x36caec} }, // S1 OSM: 63809 WD: Q7388207 48.13, 11.48 x 48.4, 11.79
    { 196, 1602, 209, LineMetaDataContent::RapidTransit, Color{0x00ac6f} }, // S6 OSM: 63839 WD: Q7388348 47.91, 11.27 x 48.15, 11.97
    { 57, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff7f00} }, // 3 OSM: 63875 51.82, 12.18 x 51.84, 12.24
    { 242, 1618, 209, LineMetaDataContent::RapidTransit, Color{0xba8a4d} }, // S46 OSM: 64094 WD: Q3737194 52.3, 13.28 x 52.52, 13.64
    { 246, 1633, 209, LineMetaDataContent::RapidTransit, Color{0xba8a4d} }, // S45 OSM: 64095 WD: Q2090939 52.36, 13.36 x 52.48, 13.57
    { 134, 1648, 19, LineMetaDataContent::Tramway, Color{0xf58f98} }, // 15 OSM: 66007 WD: Q20438575 48.08, 11.55 x 48.14, 11.6
    { 233, 1669, 19, LineMetaDataContent::Tramway, Color{0xf58f98} }, // 25 OSM: 66008 WD: Q20439051 48.04, 11.52 x 48.14, 11.6
    { 15, 1690, 19, LineMetaDataContent::Tramway, Color{0x903f98} }, // 12 OSM: 66043 WD: Q20438570 48.15, 11.51 x 48.17, 11.58
    { 26, 1711, 19, LineMetaDataContent::Tramway, Color{0x006cb2} }, // 16 OSM: 66044 WD: Q20438583 48.13, 11.51 x 48.18, 11.64
    { 165, 1732, 19, LineMetaDataContent::Tramway, Color{0xfaa61a} }, // 27 OSM: 66053 WD: Q20439073 48.13, 11.56 x 48.18, 11.58
    { 251, 1753, 19, LineMetaDataContent::Tramway, Color{0x00bfe8} }, // 20 OSM: 66079 WD: Q20438843 48.14, 11.51 x 48.18, 11.56
    { 67, 1774, 19, LineMetaDataContent::Tramway, Color{0x00bfe8} }, // 21 OSM: 66080 WD: Q20439015 48.12, 11.53 x 48.17, 11.64
    { 255, 1802, 19, LineMetaDataContent::Tramway, Color{0xb2d233} }, // 23 OSM: 66100 WD: Q20439033 48.16, 11.59 x 48.19, 11.59
    { 258, 1823, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe67310} }, // A3 OSM: 66588 WD: Q19606155 53.75, 9.656 x 53.8, 9.983
    { 207, 1838, 209, LineMetaDataContent::RapidTransit, Color{0x0065b7} }, // S4 OSM: 66840 WD: Q67504669 48.77, 9.155 x 48.95, 9.428
    { 261, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x8d1d81} }, // S51 OSM: 67184 46.7, 15.63 x 46.73, 15.99
    { 266, 1874, 19, LineMetaDataContent::Tramway, Color{0xee6600} }, // M1 OSM: 67233 WD: Q62512139 52.52, 13.37 x 52.6, 13.41
    { 42, 1893, 209, LineMetaDataContent::RapidTransit, Color{0x00b7e1} }, // S5 OSM: 67283 WD: Q18926034 48.77, 9.122 x 48.95, 9.195
    { 57, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf59e00} }, // 3 OSM: 69178 47.97, 7.796 x 48, 7.85
    { 53, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe8001b} }, // 1 OSM: 69191 47.98, 7.808 x 48.03, 7.895
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008bc5} }, // 5 OSM: 69199 47.99, 7.787 x 48, 7.852
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x646363} }, // 2 OSM: 69202 47.96, 7.833 x 48.02, 7.858
    { 273, NoLogo, 1929, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // Blue OSM: 71390 WD: Q6714611 45.49, -123 x 45.54, -122.4
    { 278, NoLogo, 1929, LineMetaDataContent::RapidTransit, Color{0xffff00} }, // Yellow OSM: 71397 WD: Q6714624 45.51, -122.7 x 45.61, -122.7
    { 285, NoLogo, 1929, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // Red OSM: 71404 WD: Q6714623 45.49, -122.8 x 45.59, -122.6
    { 53, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf6a6ab} }, // 1 OSM: 71785 WD: Q106996879 47.25, 11.39 x 47.28, 11.41
    { 57, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xd66775} }, // 3 OSM: 71787 WD: Q106996895 47.26, 11.39 x 47.27, 11.43
    { 9, 1949, 1437, LineMetaDataContent::Tramway, Color{} }, // 4 OSM: 72527 WD: Q104867838 49.43, 11.05 x 49.49, 11.07
    { 19, 1966, 1437, LineMetaDataContent::Tramway, Color{} }, // 8 OSM: 73226 WD: Q104868033 49.43, 11.08 x 49.47, 11.14
    { 53, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfbba00} }, // 1 OSM: 73662 51.45, 11.94 x 51.51, 11.99
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff9900} }, // 2 OSM: 73667 WD: Q61889098 51.43, 11.89 x 51.49, 11.99
    { 57, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0066cc} }, // 3 OSM: 73670 WD: Q61887067 51.43, 11.96 x 51.52, 11.99
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x9b1006} }, // 4 OSM: 73671 WD: Q61889270 51.44, 11.93 x 51.51, 11.99
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0f3f93} }, // 5 OSM: 73672 WD: Q61889316 51.29, 11.93 x 51.51, 12.07
    { 40, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff6699} }, // 7 OSM: 73929 WD: Q61889355 51.48, 11.93 x 51.51, 12.04
    { 123, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x999933} }, // 9 OSM: 73932 WD: Q61889418 51.48, 11.89 x 51.48, 11.99
    { 63, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x336633} }, // 10 OSM: 73933 WD: Q61889438 51.48, 11.9 x 51.49, 11.99
    { 51, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00983a} }, // S11 OSM: 76229 47.2, 15.23 x 47.23, 15.34
    { 290, NoLogo, 1983, LineMetaDataContent::Tramway, Color{} }, // 89 OSM: 77259 WD: Q534882 52.53, 13.84 x 52.58, 13.88
    { 59, NoLogo, 209, LineMetaDataContent::RapidTransit, Color{0x800000} }, // S1 OSM: 77908 WD: Q7388209 49.44, 10.9 x 49.9, 11.56
    { 48, NoLogo, 209, LineMetaDataContent::RapidTransit, Color{0x65b949} }, // S2 OSM: 77962 WD: Q7388248 49.24, 11.04 x 49.45, 11.35
    { 157, NoLogo, 209, LineMetaDataContent::RapidTransit, Color{0xf05c3d} }, // S3 OSM: 77971 WD: Q7388284 49.27, 11.08 x 49.45, 11.46
    { 57, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xef1c29} }, // 3 OSM: 78206 50.84, 12.05 x 50.91, 12.1
    { 57, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x4098de} }, // 3 OSM: 79325 WD: Q60318542 51.72, 14.3 x 51.76, 14.35
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xa81a30} }, // 6 OSM: 89518 WD: Q1664234 47.23, 11.4 x 47.26, 11.44
    { 48, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // S2 OSM: 89793 46.71, 9.386 x 46.98, 9.689
    { 59, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffc0cb} }, // S1 OSM: 89796 46.69, 9.386 x 46.86, 9.532
    { 9, 2015, 2048, LineMetaDataContent::Subway, Color{0x800080} }, // 4 OSM: 102389 WD: Q54373 43.76, -79.41 x 43.78, -79.35
    { 57, 2056, 2048, LineMetaDataContent::RapidTransit, Color{0x0093dd} }, // 3 OSM: 102390 WD: Q54372 43.73, -79.28 x 43.78, -79.25
    { 293, NoLogo, 2095, LineMetaDataContent::RapidTransit, Color{0xef7b10} }, // Overground OSM: 112649 WD: Q1854601 51.46, -0.3961 x 51.66, 0.08118
    { 221, 2118, 2150, LineMetaDataContent::RapidTransit, Color{0xfcd946} }, // C OSM: 122886 WD: Q200906 48.43, 1.995 x 49.05, 2.427
    { 304, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00907a} }, // S34 OSM: 126249 49.04, 8.585 x 49.13, 8.694
    { 308, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x193a94} }, // LSM OSM: 129382 WD: Q3239199 -34.61, -59.08 x -34.45, -58.37
    { 312, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // LM OSM: 129383 WD: Q66759479 -34.59, -59.1 x -34.1, -58.37
    { 315, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xef3e33} }, // LU OSM: 129393 WD: Q7887242 -34.6, -58.7 x -34.53, -58.46
    { 318, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0066cc} }, // LGR9 OSM: 129486 -34.79, -58.59 x -34.64, -58.4
    { 326, 2158, NoLogo, LineMetaDataContent::Tramway, Color{0xf38733} }, // P OSM: 129505 WD: Q3409024 -34.69, -58.47 x -34.64, -58.44
    { 164, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfaa61a} }, // N27 OSM: 129569 48.08, 11.55 x 48.18, 11.58
    { 328, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0066cc} }, // LGR OSM: 129698 -34.83, -58.4 x -34.63, -58.18
    { 333, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe33385} }, // 96 OSM: 132386 WD: Q12061652 -37.87, 145 x -37.77, 145
    { 337, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfeba10} }, // 86 OSM: 137969 WD: Q12061650 -37.82, 144.9 x -37.68, 145.1
    { 57, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x88d1f0} }, // 3 OSM: 144407 WD: Q6811954 -37.89, 145 x -37.8, 145.1
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe04038} }, // 5 OSM: 145649 WD: Q6811959 -37.87, 145 x -37.8, 145.1
    { 226, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe2001c} }, // A OSM: 146067 WD: Q2204240 48.52, 7.693 x 48.6, 7.754
    { 341, NoLogo, 169, LineMetaDataContent::Tramway, Color{0xffd800} }, // 49 OSM: 147322 WD: Q1491114 47.47, 19.02 x 47.5, 19.06
    { 266, 2186, 2208, LineMetaDataContent::Subway, Color{0xff0000} }, // M1 OSM: 149920 WD: Q2334153 50.44, 30.35 x 50.47, 30.65
    { 344, 2228, 2240, LineMetaDataContent::Subway, Color{0xfdc110} }, // M2 OSM: 152340 WD: Q1880954 55.63, 12.49 x 55.69, 12.65
    { 347, 2266, 2208, LineMetaDataContent::Subway, Color{0x00ff00} }, // M3 OSM: 153243 WD: Q2420584 50.39, 30.43 x 50.48, 30.7
    { 53, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009640} }, // 1 OSM: 153893 53.04, 8.741 x 53.16, 8.965
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00ff00} }, // 6 OSM: 155951 49, 8.295 x 49.02, 8.44
    { 190, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x127bca} }, // B OSM: 163585 WD: Q2799227 48.55, 7.689 x 48.63, 7.769
    { 37, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xa85faa} }, // E OSM: 163591 WD: Q2903493 48.53, 7.733 x 48.61, 7.786
    { 53, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xec008c} }, // 1 OSM: 163714 52.48, -2.125 x 52.58, -1.896
    { 15, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x98002e} }, // 12 OSM: 163759 43.11, -79.89 x 43.65, -79.06
    { 266, 2288, 2312, LineMetaDataContent::Subway, Color{0x0075be} }, // M1 OSM: 165613 WD: Q3238660 43.29, 5.374 x 43.33, 5.43
    { 344, 2344, 2312, LineMetaDataContent::Subway, Color{0xe30513} }, // M2 OSM: 165618 WD: Q3238804 43.27, 5.367 x 43.33, 5.403
    { 351, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x49805b} }, // 59 OSM: 167658 WD: Q6811962 -37.82, 144.9 x -37.71, 145
    { 53, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x003828} }, // 1 OSM: 170076 52.92, -1.263 x 53.04, -1.145
    { 354, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x42816b} }, // 181 (SN) OSM: 172834 51.28, -0.1727 x 51.49, -0.07193
    { 278, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xd39f06} }, // Yellow OSM: 172864 WD: Q19960799 54.95, -1.623 x 55.04, -1.429
    { 363, 2368, 209, LineMetaDataContent::RapidTransit, Color{0x52b447} }, // S85 OSM: 175267 WD: Q4048677 52.41, 13.4 x 52.57, 13.58
    { 328, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0066cc} }, // LGR OSM: 176910 -35.44, -59.09 x -34.85, -58.52
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x82cee6} }, // 8 OSM: 178504 39.46, -0.339 x 39.46, -0.3254
    { 27, 2383, NoLogo, LineMetaDataContent::Tramway, Color{0x9b70cb} }, // 6 OSM: 178505 WD: Q3832664 39.46, -0.3726 x 39.5, -0.3256
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x004a99} }, // 4 OSM: 178506 39.47, -0.4364 x 39.53, -0.3256
    { 6, 2414, NoLogo, LineMetaDataContent::Subway, Color{0x009870} }, // 5 OSM: 178522 WD: Q3238965 39.46, -0.4744 x 39.49, -0.3383
    { 57, 2445, NoLogo, LineMetaDataContent::Subway, Color{0xdd052b} }, // 3 OSM: 178523 WD: Q3238906 39.47, -0.4744 x 39.59, -0.33
    { 53, 2476, NoLogo, LineMetaDataContent::Subway, Color{0xfdc600} }, // 1 OSM: 178526 WD: Q2165952 39.08, -0.5268 x 39.59, -0.3815
    { 368, 2507, 2535, LineMetaDataContent::Tramway, Color{0xc19dc2} }, // L4 OSM: 190184 WD: Q5474600 38.35, -0.4907 x 38.38, -0.4118
    { 372, 2576, 2535, LineMetaDataContent::Tramway, Color{0xd72028} }, // L1 OSM: 190196 WD: Q594538 38.35, -0.4907 x 38.55, -0.1346
    { 376, NoLogo, 2535, LineMetaDataContent::Tramway, Color{0x00ff00} }, // L2 OSM: 190199 WD: Q9025903 38.35, -0.5172 x 38.39, -0.4678
    { 380, NoLogo, 2535, LineMetaDataContent::Tramway, Color{0xf9d114} }, // L3 OSM: 190203 WD: Q9025931 38.35, -0.4907 x 38.43, -0.3952
    { 383, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf58122} }, // 109 OSM: 190802 WD: Q6811947 -37.84, 144.9 x -37.81, 145.1
    { 221, 2604, 920, LineMetaDataContent::RapidTransit, Color{0xffa500} }, // C OSM: 191280 WD: Q4452746 55.66, 12.07 x 55.84, 12.59
    { 388, 2626, 920, LineMetaDataContent::RapidTransit, Color{0xe64415} }, // H OSM: 191281 WD: Q1891933 55.66, 12.07 x 55.84, 12.59
    { 391, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x33bdca} }, // 57 OSM: 196209 WD: Q16926803 -37.82, 144.9 x -37.77, 145
    { 36, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0e4094} }, // 4E OSM: 207342 51.32, 12.35 x 51.38, 12.43
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0e4094} }, // 4 OSM: 207342 51.32, 12.35 x 51.38, 12.43
    { 394, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00a5e3} }, // North Jersey Coast OSM: 207401 WD: Q7055732 40.07, -74.29 x 40.77, -73.99
    { 16, 2648, NoLogo, LineMetaDataContent::Subway, Color{0x97d700} }, // 2 OSM: 207417 WD: Q1325437 31.15, 121.3 x 31.24, 121.8
    { 414, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x434244} }, // 48 OSM: 207445 WD: Q16926797 -37.82, 144.9 x -37.79, 145.1
    { 53, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 1 OSM: 207718 45.55, 18.62 x 45.57, 18.73
    { 316, 2657, 2680, LineMetaDataContent::RapidTransit, Color{0xc90062} }, // U OSM: 215565 WD: Q93559 48.76, 1.943 x 48.89, 2.237
    { 32, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0066cc} }, // LS OSM: 223925 -35.19, -59.43 x -34.58, -58.41
    { 40, 2701, NoLogo, LineMetaDataContent::Subway, Color{0xff6900} }, // 7 OSM: 228608 WD: Q2707909 31.17, 121.3 x 31.41, 121.6
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffff00} }, // 8 OSM: 237270 49.17, 16.55 x 49.21, 16.69
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00ff00} }, // 2 OSM: 237285 49.13, 16.59 x 49.2, 16.64
    { 53, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 1 OSM: 237306 49.19, 16.57 x 49.25, 16.61
    { 418, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xd77d00} }, // 30 OSM: 241384 WD: Q1760190 59.29, 17.96 x 59.36, 18.12
    { 422, NoLogo, 2710, LineMetaDataContent::RapidTransit, Color{0xf166a7} }, // 43 OSM: 241411 WD: Q106806959 58.9, 17.53 x 59.57, 18.16
    { 426, NoLogo, 2710, LineMetaDataContent::RapidTransit, Color{0xf166a7} }, // 41 OSM: 241413 WD: Q106806951 59.17, 17.63 x 59.63, 18.07
    { 414, NoLogo, 2710, LineMetaDataContent::RapidTransit, Color{0xf166a7} }, // 48 OSM: 241414 WD: Q106808255 59.04, 17.31 x 59.19, 17.65
    { 430, 2745, NoLogo, LineMetaDataContent::RapidTransit, Color{0xc7b300} }, // K OSM: 253357 WD: Q93382 48.88, 2.352 x 49.23, 2.888
    { 432, 2768, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008a29} }, // C-5 OSM: 254510 WD: Q9026057 39.44, -0.5754 x 39.95, -0.2715
    { 436, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x007dc5} }, // ISL OSM: 269670 WD: Q989316 22.26, 114.1 x 22.29, 114.2
    { 440, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xf7943e} }, // TCL OSM: 269671 WD: Q989358 22.28, 113.9 x 22.36, 114.2
    { 444, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x00888a} }, // AEL OSM: 272078 WD: Q409036 22.29, 113.9 x 22.36, 114.2
    { 448, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x53b7e8} }, // EAL OSM: 272132 WD: Q989339 22.3, 114.1 x 22.53, 114.2
    { 452, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x923011} }, // TML OSM: 272133 WD: Q5329661 22.29, 114 x 22.45, 114.2
    { 211, 2782, NoLogo, LineMetaDataContent::Tramway, Color{0xef7c00} }, // S 1 OSM: 273002 WD: Q65643711 49.11, 6.891 x 49.41, 7.068
    { 456, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff7e00} }, // 28E OSM: 274460 WD: Q63034669 38.71, -9.17 x 38.72, -9.128
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // 2 OSM: 300207 48.46, 34.61 x 48.52, 34.69
    { 53, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff00ff} }, // 1 OSM: 300208 48.51, 34.57 x 48.52, 34.62
    { 460, 2800, 209, LineMetaDataContent::RapidTransit, Color{0x9a3052} }, // S9 OSM: 304163 WD: Q4048680 52.36, 13.2 x 52.53, 13.57
    { 463, NoLogo, 1929, LineMetaDataContent::RapidTransit, Color{0x008000} }, // Green OSM: 304623 WD: Q6714613 45.44, -122.7 x 45.54, -122.6
    { 266, 2814, 2826, LineMetaDataContent::Subway, Color{0x0000ff} }, // M1 OSM: 309619 WD: Q17462780 52.13, 20.93 x 52.29, 21.07
    { 326, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // P OSM: 357191 60.17, 24.84 x 60.33, 25.06
    { 469, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // C-1 OSM: 357967 43.25, -3.03 x 43.33, -2.928
    { 473, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x630016} }, // STB OSM: 359908 WD: Q872840 47.16, 11.35 x 47.27, 11.4
    { 478, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x723b1f} }, // 35 OSM: 363305 WD: Q5123100 -37.82, 144.9 x -37.81, 145
    { 138, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8f4a78} }, // 19 OSM: 363891 WD: Q6811950 -37.82, 145 x -37.73, 145
    { 157, 2848, 209, LineMetaDataContent::RapidTransit, Color{0x862996} }, // S3 OSM: 364187 WD: Q7388283 47.88, 11.17 x 48.22, 11.7
    { 481, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // SIR1 OSM: 365296 WD: Q107133892 45.37, 11.87 x 45.44, 11.89
    { 487, 2864, NoLogo, LineMetaDataContent::Subway, Color{0x6cbe45} }, // G OSM: 366764 WD: Q126527 40.64, -74 x 40.75, -73.94
    { 40, 2890, NoLogo, LineMetaDataContent::Subway, Color{0xb933ad} }, // 7 OSM: 366765 WD: Q126203 40.74, -74 x 40.76, -73.83
    { 33, 2916, NoLogo, LineMetaDataContent::Subway, Color{0x808183} }, // S OSM: 366766 WD: Q126698 40.75, -73.99 x 40.76, -73.98
    { 491, 2942, NoLogo, LineMetaDataContent::Subway, Color{0xfccc0a} }, // N OSM: 366768 WD: Q126434 40.58, -74.02 x 40.78, -73.91
    { 493, 2968, NoLogo, LineMetaDataContent::Subway, Color{0xfccc0a} }, // Q OSM: 366769 WD: Q126448 40.58, -74 x 40.78, -73.95
    { 226, 2994, NoLogo, LineMetaDataContent::Subway, Color{0x0039a6} }, // A OSM: 366774 WD: Q126344 40.58, -74.01 x 40.87, -73.75
    { 27, 3020, NoLogo, LineMetaDataContent::Subway, Color{0x00933c} }, // 6 OSM: 366777 WD: Q126192 40.71, -74.01 x 40.85, -73.83
    { 330, 3046, NoLogo, LineMetaDataContent::Subway, Color{0xfccc0a} }, // R OSM: 366780 WD: Q126459 40.62, -74.03 x 40.77, -73.84
    { 495, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x9acd32} }, // Bx OSM: 367751 55.65, 12.27 x 55.81, 12.59
    { 326, 3072, NoLogo, LineMetaDataContent::RapidTransit, Color{0xeaab00} }, // P OSM: 370597 WD: Q93874 48.51, 2.359 x 49.18, 3.417
    { 240, 3095, 920, LineMetaDataContent::RapidTransit, Color{0xffc225} }, // F OSM: 381625 WD: Q2133631 55.65, 12.49 x 55.73, 12.57
    { 40, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008030} }, // 7 OSM: 382533 WD: Q2590490 51.91, 4.471 x 51.93, 4.526
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xdf60a4} }, // 8 OSM: 382535 WD: Q3277304 51.9, 4.432 x 51.95, 4.488
    { 233, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x6192c7} }, // 25 OSM: 382566 WD: Q2321951 51.84, 4.46 x 51.96, 4.514
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xdaa520} }, // 6 OSM: 383846 50.89, 10.56 x 50.9, 10.58
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 12 OSM: 384321 49.18, 16.58 x 49.23, 16.62
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff00ff} }, // 5 OSM: 384539 49.16, 16.59 x 49.22, 16.63
    { 52, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 11 OSM: 384541 49.19, 16.52 x 49.23, 16.63
    { 266, NoLogo, 3117, LineMetaDataContent::Subway, Color{0xff0000} }, // M1 OSM: 386242 WD: Q3238662 45.02, 7.591 x 45.08, 7.68
    { 37, 3147, 920, LineMetaDataContent::RapidTransit, Color{0x9370db} }, // E OSM: 394091 WD: Q4624816 55.46, 12.17 x 55.81, 12.59
    { 52, 3169, NoLogo, LineMetaDataContent::Subway, Color{0x76232f} }, // 11 OSM: 396879 WD: Q2636308 31.13, 121.1 x 31.4, 121.7
    { 498, NoLogo, 2535, LineMetaDataContent::Tramway, Color{0x706e6d} }, // L9 OSM: 404372 WD: Q11690013 38.55, -0.1352 x 38.84, 0.1131
    { 16, 3179, 3199, LineMetaDataContent::Subway, Color{0x00529b} }, // 2 OSM: 414866 WD: Q680973 39.9, 116.3 x 39.95, 116.4
    { 53, 3234, 3199, LineMetaDataContent::Subway, Color{0xa12830} }, // 1 OSM: 415571 WD: Q748987 39.91, 116.2 x 39.95, 116.5
    { 56, 3254, 3199, LineMetaDataContent::Subway, Color{0xf9e700} }, // 13 OSM: 417951 WD: Q847744 39.94, 116.3 x 40.07, 116.5
    { 266, 3275, 3291, LineMetaDataContent::Subway, Color{0xffe507} }, // M1 OSM: 418343 WD: Q1078111 47.5, 19.05 x 47.52, 19.09
    { 502, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x006d78} }, // T2 OSM: 418631 WD: Q16011471 47.22, 5.951 x 47.25, 6.03
    { 63, 3305, 3199, LineMetaDataContent::Subway, Color{0x178abb} }, // 10 OSM: 420835 WD: Q847886 39.84, 116.3 x 39.98, 116.5
    { 6, 3326, 3199, LineMetaDataContent::Subway, Color{0xae005f} }, // 5 OSM: 420836 WD: Q647340 39.84, 116.4 x 40.08, 116.4
    { 19, 3346, 3199, LineMetaDataContent::Subway, Color{0x009b77} }, // 8 OSM: 420837 WD: Q847771 39.76, 116.3 x 40.1, 116.4
    { 9, 3366, 3199, LineMetaDataContent::Subway, Color{0x008193} }, // 4 OSM: 420838 WD: Q304264 39.81, 116.3 x 40.01, 116.4
    { 19, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x008c95} }, // 8 OSM: 443998 WD: Q862965 23.09, 113.2 x 23.24, 113.4
    { 330, 3386, 3410, LineMetaDataContent::Subway, Color{0xff0000} }, // R OSM: 447451 WD: Q697140 25.03, 121.4 x 25.17, 121.6
    { 53, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0026ff} }, // 1 OSM: 453141 36.23, 59.44 x 36.35, 59.64
    { 59, 3432, 209, LineMetaDataContent::RapidTransit, Color{0xd474ae} }, // S1 OSM: 454054 WD: Q2579762 52.42, 13.18 x 52.75, 13.4
    { 39, 3446, 209, LineMetaDataContent::RapidTransit, Color{0x20543f} }, // S7 OSM: 456933 WD: Q2588691 49.83, 8.488 x 50.11, 8.664
    { 200, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe40716} }, // T1 OSM: 535990 WD: Q3239228 45.41, 4.364 x 45.48, 4.394
    { 223, 3463, 3463, LineMetaDataContent::Tramway, Color{0x0363ff} }, // T1 A OSM: 548496 WD: Q1688502 36.72, 3.083 x 36.78, 3.263
    { 506, NoLogo, 169, LineMetaDataContent::Tramway, Color{0xffd800} }, // 56 OSM: 557061 WD: Q1491414 47.43, 18.96 x 47.54, 19.05
    { 138, NoLogo, 169, LineMetaDataContent::Tramway, Color{0xffd800} }, // 19 OSM: 557063 WD: Q776651 47.47, 19.02 x 47.55, 19.05
    { 510, NoLogo, 169, LineMetaDataContent::Tramway, Color{0xffd800} }, // 47 OSM: 557066 WD: Q1491058 47.43, 19.04 x 47.5, 19.06
    { 426, NoLogo, 169, LineMetaDataContent::Tramway, Color{0xffd800} }, // 41 OSM: 557068 WD: Q1490823 47.44, 18.98 x 47.55, 19.05
    { 79, NoLogo, 169, LineMetaDataContent::Tramway, Color{0xffd800} }, // 61 OSM: 557070 WD: Q1491592 47.48, 18.96 x 47.54, 19.05
    { 16, 3482, NoLogo, LineMetaDataContent::Tramway, Color{0x0068b3} }, // 2 OSM: 563459 WD: Q78198199 48.32, 10.84 x 48.38, 10.91
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xef7c00} }, // 8 OSM: 563484 48.33, 10.89 x 48.37, 10.9
    { 153, 3502, 209, LineMetaDataContent::RapidTransit, Color{0x928d1d} }, // S60 OSM: 570588 WD: Q63952011 48.69, 8.922 x 48.83, 9.195
    { 513, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x6699cc} }, // 215 OSM: 571534 WD: Q105045768 46.95, 6.839 x 46.99, 6.928
    { 154, NoLogo, 169, LineMetaDataContent::Tramway, Color{0xffd800} }, // 60 OSM: 899388 WD: Q851167 47.5, 18.98 x 47.51, 19.01
    { 351, NoLogo, 169, LineMetaDataContent::Tramway, Color{0xffd800} }, // 59 OSM: 906131 WD: Q744461 47.48, 19 x 47.51, 19.02
    { 169, NoLogo, 169, LineMetaDataContent::Tramway, Color{0xffd800} }, // 17 OSM: 911937 WD: Q1486400 47.44, 19.02 x 47.55, 19.05
    { 26, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffda66} }, // 16 OSM: 916109 WD: Q16926791 -37.87, 145 x -37.8, 145
    { 517, NoLogo, 3539, LineMetaDataContent::RapidTransit, Color{0xffa21d} }, // MD-W OSM: 932986 WD: Q5250950 41.88, -88.33 x 42.06, -87.64
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x19633a} }, // 6 OSM: 962031 47.06, 15.41 x 47.07, 15.48
    { 57, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x68ba45} }, // 3 OSM: 962059 47.07, 15.42 x 47.1, 15.46
    { 40, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe42714} }, // 7 OSM: 962240 47.06, 15.39 x 47.08, 15.47
    { 53, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00b8ea} }, // 1 OSM: 962920 47.07, 15.39 x 47.11, 15.49
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x95c11f} }, // 8 OSM: 963052 53.05, 8.741 x 53.1, 8.841
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffcc00} }, // 6 OSM: 963103 53.05, 8.783 x 53.11, 8.859
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x025191} }, // 5 OSM: 963685 47.03, 15.42 x 47.1, 15.45
    { 523, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff7d24} }, // 26 OSM: 963723 47.06, 15.44 x 47.07, 15.48
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x9462b1} }, // 13 OSM: 963724 47.04, 15.44 x 47.07, 15.46
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xdeaa2e} }, // 4 OSM: 963737 47.04, 15.41 x 47.07, 15.46
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe30613} }, // 4 OSM: 964983 53.03, 8.799 x 53.16, 8.945
    { 57, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009fe3} }, // 3 OSM: 966312 53.06, 8.752 x 53.12, 8.868
    { 526, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00a54f} }, // D1 OSM: 1014078 51.1, 15.22 x 51.29, 17.04
    { 200, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // T1 OSM: 1059709 WD: Q107172293 42.84, -2.702 x 42.87, -2.664
    { 529, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0075bf} }, // N10 OSM: 1070763 53.06, 8.753 x 53.12, 8.9
    { 533, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe30613} }, // N4 OSM: 1070810 53.03, 8.799 x 53.16, 8.945
    { 536, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009640} }, // N1 OSM: 1070812 53.04, 8.741 x 53.09, 8.965
    { 27, NoLogo, 169, LineMetaDataContent::Tramway, Color{0xffd800} }, // 6 OSM: 1102938 WD: Q1491542 47.48, 19.02 x 47.51, 19.07
    { 9, NoLogo, 169, LineMetaDataContent::Tramway, Color{0xffd800} }, // 4 OSM: 1102941 WD: Q1490736 47.47, 19.02 x 47.51, 19.07
    { 539, 3554, 3569, LineMetaDataContent::RapidTransit, Color{0xa72a75} }, // H5 OSM: 1103027 WD: Q1031914 47.51, 19.03 x 47.66, 19.08
    { 543, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x1aaa6f} }, // 64 OSM: 1110830 WD: Q6811964 -37.91, 145 x -37.8, 145
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x004c6c} }, // 6 OSM: 1111658 WD: Q16926785 -37.86, 145 x -37.76, 145.1
    { 161, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xac7963} }, // 67 OSM: 1111659 WD: Q6811965 -37.89, 145 x -37.8, 145.1
    { 546, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfaa634} }, // Raritan Valley OSM: 1122386 WD: Q7294577 40.56, -74.9 x 40.74, -74.16
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x90ee90} }, // 5 OSM: 1133389 49.84, 24.03 x 49.86, 24.04
    { 40, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x90ee90} }, // 7 OSM: 1133430 49.83, 23.99 x 49.85, 24.06
    { 561, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xf173ac} }, // DRL OSM: 1139477 WD: Q989330 22.32, 114 x 22.33, 114
    { 226, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xed389c} }, // A OSM: 1142411 45.5, -122.7 x 45.53, -122.7
    { 565, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe41f25} }, // N82 OSM: 1147592 48.24, 14.28 x 48.33, 14.36
    { 173, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe41f25} }, // 50 OSM: 1149422 48.31, 14.26 x 48.32, 14.29
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe41f25} }, // 2 OSM: 1149423 48.24, 14.28 x 48.33, 14.36
    { 57, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe41f25} }, // 3 OSM: 1149424 48.23, 14.23 x 48.31, 14.29
    { 53, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe41f25} }, // 1 OSM: 1149425 48.25, 14.28 x 48.33, 14.32
    { 101, 3593, 944, LineMetaDataContent::Subway, Color{0x00a54f} }, // U2 OSM: 1150977 WD: Q3040891 50.1, 8.64 x 50.22, 8.688
    { 569, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0039a6} }, // Harlem OSM: 1158719 WD: Q5658559 40.75, -73.98 x 41.82, -73.55
    { 576, NoLogo, 3610, LineMetaDataContent::RapidTransit, Color{0xffc260} }, // 117 OSM: 1165701 WD: Q4132754 34.05, -119.2 x 34.29, -118.2
    { 580, NoLogo, 3610, LineMetaDataContent::RapidTransit, Color{0xffc260} }, // 119 OSM: 1165701 WD: Q4132754 34.05, -119.2 x 34.29, -118.2
    { 160, NoLogo, 3610, LineMetaDataContent::RapidTransit, Color{0x008000} }, // 267 OSM: 1172222 WD: Q4162507 34.05, -118.5 x 34.7, -118.1
    { 584, NoLogo, 3610, LineMetaDataContent::RapidTransit, Color{0x008000} }, // 227 OSM: 1172222 WD: Q4162507 34.05, -118.5 x 34.7, -118.1
    { 588, NoLogo, 3610, LineMetaDataContent::RapidTransit, Color{0x008000} }, // 269 OSM: 1172222 WD: Q4162507 34.05, -118.5 x 34.7, -118.1
    { 592, NoLogo, 3610, LineMetaDataContent::RapidTransit, Color{0x008000} }, // 209 OSM: 1172222 WD: Q4162507 34.05, -118.5 x 34.7, -118.1
    { 596, NoLogo, 3610, LineMetaDataContent::RapidTransit, Color{0x008000} }, // 201 OSM: 1172222 WD: Q4162507 34.05, -118.5 x 34.7, -118.1
    { 74, NoLogo, 3610, LineMetaDataContent::RapidTransit, Color{0x008000} }, // 263 OSM: 1172222 WD: Q4162507 34.05, -118.5 x 34.7, -118.1
    { 600, NoLogo, 3610, LineMetaDataContent::RapidTransit, Color{0x008000} }, // 231 OSM: 1172222 WD: Q4162507 34.05, -118.5 x 34.7, -118.1
    { 203, NoLogo, 3610, LineMetaDataContent::RapidTransit, Color{0x008000} }, // 265 OSM: 1172222 WD: Q4162507 34.05, -118.5 x 34.7, -118.1
    { 604, NoLogo, 3610, LineMetaDataContent::RapidTransit, Color{0x008000} }, // 213 OSM: 1172222 WD: Q4162507 34.05, -118.5 x 34.7, -118.1
    { 608, NoLogo, 3610, LineMetaDataContent::RapidTransit, Color{0x008000} }, // 271 OSM: 1172222 WD: Q4162507 34.05, -118.5 x 34.7, -118.1
    { 66, NoLogo, 3610, LineMetaDataContent::RapidTransit, Color{0x008000} }, // 221 OSM: 1172222 WD: Q4162507 34.05, -118.5 x 34.7, -118.1
    { 254, NoLogo, 3610, LineMetaDataContent::RapidTransit, Color{0x008000} }, // 223 OSM: 1172222 WD: Q4162507 34.05, -118.5 x 34.7, -118.1
    { 612, NoLogo, 3610, LineMetaDataContent::RapidTransit, Color{0x008000} }, // 229 OSM: 1172222 WD: Q4162507 34.05, -118.5 x 34.7, -118.1
    { 78, NoLogo, 3610, LineMetaDataContent::RapidTransit, Color{0x008000} }, // 261 OSM: 1172222 WD: Q4162507 34.05, -118.5 x 34.7, -118.1
    { 616, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x009b3a} }, // Hudson OSM: 1186686 40.75, -73.99 x 41.71, -73.86
    { 623, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff7900} }, // Port Jervis OSM: 1190915 WD: Q7230730 41.11, -74.69 x 41.49, -74.09
    { 372, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe52422} }, // L1 OSM: 1190932 WD: Q28662810 41.62, -0.9378 x 41.69, -0.8708
    { 635, NoLogo, 3610, LineMetaDataContent::RapidTransit, Color{0x800080} }, // 406 OSM: 1199065 WD: Q4801982 33.96, -118.2 x 34.06, -117.4
    { 639, NoLogo, 3610, LineMetaDataContent::RapidTransit, Color{0x800080} }, // 410 OSM: 1199065 WD: Q4801982 33.96, -118.2 x 34.06, -117.4
    { 643, NoLogo, 3610, LineMetaDataContent::RapidTransit, Color{0x800080} }, // 408 OSM: 1199065 WD: Q4801982 33.96, -118.2 x 34.06, -117.4
    { 647, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0065ff} }, // SFMA OSM: 1204872 WD: Q3832760 45.09, 7.47 x 45.27, 7.677
    { 652, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0065ff} }, // SFM 2 OSM: 1210497 WD: Q3832754 44.89, 7.337 x 45.19, 7.89
    { 658, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x95aa53} }, // 308 OSM: 1228606 51.4, 7.16 x 51.52, 7.284
    { 662, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xb14e7a} }, // 310 OSM: 1228607 51.44, 7.152 x 51.48, 7.337
    { 477, NoLogo, 480, LineMetaDataContent::Subway, Color{0x294488} }, // U35 OSM: 1228608 WD: Q2466100 51.45, 7.21 x 51.55, 7.273
    { 21, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x72a7a0} }, // 318 OSM: 1228609 51.42, 7.143 x 51.52, 7.284
    { 666, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xea504c} }, // 306 OSM: 1228610 51.48, 7.16 x 51.53, 7.223
    { 670, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x6ba5d9} }, // 302 OSM: 1228611 51.46, 7.056 x 51.58, 7.324
    { 674, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00b2f6} }, // 301 OSM: 1236118 51.5, 7.026 x 51.58, 7.11
    { 678, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf47a14} }, // S 5 OSM: 1241173 49.14, 8.674 x 49.42, 9.102
    { 682, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0039a6} }, // Port Jefferson OSM: 1255264 WD: Q7230720 40.7, -73.99 x 40.94, -73.05
    { 697, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe00034} }, // New Haven OSM: 1260624 40.75, -73.98 x 41.31, -72.92
    { 707, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x89728e} }, // VMLR OSM: 1266358 33.41, -112.1 x 33.57, -111.8
    { 502, NoLogo, 748, LineMetaDataContent::Tramway, Color{0x0000ff} }, // T2 OSM: 1286854 WD: Q5986172 28.44, -16.3 x 28.47, -16.29
    { 417, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x800000} }, // 330 OSM: 1287719 34.05, -118.2 x 34.11, -117.3
    { 712, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x800000} }, // 300 OSM: 1287719 34.05, -118.2 x 34.11, -117.3
    { 192, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x800000} }, // 358 OSM: 1287719 34.05, -118.2 x 34.11, -117.3
    { 180, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x800000} }, // 324 OSM: 1287719 34.05, -118.2 x 34.11, -117.3
    { 542, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x800000} }, // 364 OSM: 1287719 34.05, -118.2 x 34.11, -117.3
    { 716, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x800000} }, // 334 OSM: 1287719 34.05, -118.2 x 34.11, -117.3
    { 720, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x800000} }, // 366 OSM: 1287719 34.05, -118.2 x 34.11, -117.3
    { 184, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x800000} }, // 332 OSM: 1287719 34.05, -118.2 x 34.11, -117.3
    { 724, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x800000} }, // 352 OSM: 1287719 34.05, -118.2 x 34.11, -117.3
    { 522, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x800000} }, // 326 OSM: 1287719 34.05, -118.2 x 34.11, -117.3
    { 728, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x800000} }, // 314 OSM: 1287719 34.05, -118.2 x 34.11, -117.3
    { 732, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x800000} }, // 336 OSM: 1287719 34.05, -118.2 x 34.11, -117.3
    { 250, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x800000} }, // 320 OSM: 1287719 34.05, -118.2 x 34.11, -117.3
    { 736, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x800000} }, // 304 OSM: 1287719 34.05, -118.2 x 34.11, -117.3
    { 21, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x800000} }, // 318 OSM: 1287719 34.05, -118.2 x 34.11, -117.3
    { 740, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x800000} }, // 312 OSM: 1287719 34.05, -118.2 x 34.11, -117.3
    { 141, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x800000} }, // 372 OSM: 1287719 34.05, -118.2 x 34.11, -117.3
    { 82, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x800000} }, // 368 OSM: 1287719 34.05, -118.2 x 34.11, -117.3
    { 666, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x800000} }, // 306 OSM: 1287719 34.05, -118.2 x 34.11, -117.3
    { 744, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x800000} }, // 354 OSM: 1287719 34.05, -118.2 x 34.11, -117.3
    { 748, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x800000} }, // 322 OSM: 1287719 34.05, -118.2 x 34.11, -117.3
    { 752, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x800000} }, // 376 OSM: 1287719 34.05, -118.2 x 34.11, -117.3
    { 86, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x800000} }, // 362 OSM: 1287719 34.05, -118.2 x 34.11, -117.3
    { 756, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00af3f} }, // Oyster Bay OSM: 1308975 WD: Q7116314 40.7, -73.99 x 40.88, -73.53
    { 767, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe6007e} }, // S31 OSM: 1319745 47.1, 15.62 x 47.22, 15.71
    { 376, 3629, 3199, LineMetaDataContent::Subway, Color{0xd61572} }, // L2 OSM: 1350576 WD: Q5944471 39.77, 116.4 x 39.84, 116.6
    { 181, 3629, 3199, LineMetaDataContent::Subway, Color{0xd61572} }, // 24 OSM: 1350576 WD: Q5944471 39.77, 116.4 x 39.84, 116.6
    { 165, 3656, 3199, LineMetaDataContent::Subway, Color{0xd47daa} }, // 27 OSM: 1350622 WD: Q5066697 40.05, 116.2 x 40.24, 116.3
    { 489, 3684, 3199, LineMetaDataContent::Subway, Color{0xd85f26} }, // 25N OSM: 1350671 WD: Q5433860 39.72, 116.1 x 39.86, 116.3
    { 771, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7b388c} }, // Kingston/Plymouth Line OSM: 1353691 WD: Q7083739 41.98, -71.06 x 42.35, -70.69
    { 794, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7b388c} }, // Needham Line OSM: 1353692 WD: Q6986548 42.27, -71.24 x 42.35, -71.05
    { 807, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7b388c} }, // Fairmount Line OSM: 1353693 WD: Q5430648 42.24, -71.13 x 42.35, -71.05
    { 822, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7b388c} }, // Greenbush Line OSM: 1353695 WD: Q5603780 42.18, -71.06 x 42.35, -70.74
    { 837, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7b388c} }, // Middleborough/Lakeville Line OSM: 1353697 WD: Q7083739 41.88, -71.06 x 42.35, -70.92
    { 372, NoLogo, 3199, LineMetaDataContent::Subway, Color{0x9b91b1} }, // L1 OSM: 1354082 WD: Q847767 39.94, 116.4 x 40.08, 116.6
    { 866, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7b388c} }, // Framingham/Worcester Line OSM: 1354954 WD: Q801994 42.23, -71.8 x 42.36, -71.06
    { 892, 3711, 3569, LineMetaDataContent::RapidTransit, Color{0xee701b} }, // H7 OSM: 1358702 WD: Q1031921 47.42, 19.07 x 47.48, 19.07
    { 57, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 3 OSM: 1361661 56.48, 84.95 x 56.48, 85.02
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xcc9900} }, // 8 OSM: 1374424 WD: Q61887882 51.45, 11.95 x 51.52, 11.99
    { 53, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfed265} }, // 1 OSM: 1375736 46.24, 20.12 x 46.27, 20.15
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x99cc00} }, // 12 OSM: 1375884 WD: Q61888162 51.48, 11.96 x 51.52, 11.99
    { 895, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfece08} }, // Main OSM: 1377995 WD: Q6736006 40.73, -74.17 x 41.11, -74.03
    { 900, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa1d4ae} }, // Gladstone OSM: 1377996 WD: Q5566325 40.67, -74.67 x 40.77, -73.99
    { 910, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xb9c9df} }, // Bergen County OSM: 1377997 WD: Q4891507 40.73, -74.15 x 41.11, -74.03
    { 924, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00a94e} }, // Morristown OSM: 1377998 WD: Q1948559 40.71, -74.83 x 40.91, -73.99
    { 935, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe76b5b} }, // Montclair-Boonton OSM: 1377999 WD: Q6904583 40.73, -74.83 x 40.93, -73.99
    { 219, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff8942} }, // FXC OSM: 1388637 WD: Q8565193 39.95, -75.18 x 40.08, -75.08
    { 953, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7c5e4a} }, // DOY OSM: 1388640 WD: Q6487336 39.95, -75.28 x 40.31, -75.13
    { 957, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffd457} }, // WAR OSM: 1390135 WD: Q7969637 39.95, -75.18 x 40.26, -74.82
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 2 OSM: 1390151 34.31, 132.3 x 34.4, 132.5
    { 961, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfaa93f} }, // 845 OSM: 1403277 WD: Q5025789 38.9, -77.01 x 39.28, -76.62
    { 505, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfaa93f} }, // 856 OSM: 1403278 WD: Q5025789 38.9, -77.01 x 39.28, -76.62
    { 965, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfbcab6} }, // 892 OSM: 1405414 WD: Q4979520 38.9, -77.53 x 39.41, -76.99
    { 969, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfbcab6} }, // 893 OSM: 1405415 WD: Q4979520 38.9, -77.53 x 39.41, -76.99
    { 973, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfbcab6} }, // 881 OSM: 1405856 WD: Q4979520 38.9, -77.96 x 39.46, -76.99
    { 977, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfbcab6} }, // 878 OSM: 1405857 WD: Q4979520 38.9, -77.96 x 39.46, -76.99
    { 981, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff7f00} }, // 12E OSM: 1411178 WD: Q1487139 38.71, -9.138 x 38.72, -9.13
    { 985, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff00ff} }, // 15E OSM: 1411205 WD: Q63229924 38.69, -9.233 x 38.71, -9.135
    { 240, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xb1c800} }, // F OSM: 1416967 WD: Q2724954 48.58, 7.716 x 48.59, 7.778
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfed265} }, // 4 OSM: 1443866 46.24, 20.12 x 46.28, 20.16
    { 989, NoLogo, 209, LineMetaDataContent::RapidTransit, Color{} }, // S26 OSM: 1444441 WD: Q819377 47.45, 9.591 x 47.47, 9.601
    { 6, 3726, 3750, LineMetaDataContent::Subway, Color{0x802f08} }, // 5 OSM: 1462012 WD: Q831673 55.73, 37.57 x 55.78, 37.66
    { 9, 3855, 3750, LineMetaDataContent::Subway, Color{0x33ccff} }, // 4 OSM: 1463287 WD: Q834540 55.73, 37.45 x 55.75, 37.61
    { 57, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe5005a} }, // 3 OSM: 1469415 51.02, 13.7 x 51.1, 13.75
    { 57, 3879, 3750, LineMetaDataContent::Subway, Color{0x0000ff} }, // 3 OSM: 1472548 WD: Q626941 55.73, 37.35 x 55.86, 37.8
    { 53, 3903, 3750, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 1475758 WD: Q729631 55.55, 37.4 x 55.82, 37.75
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffa500} }, // 4 OSM: 1476874 56.45, 84.98 x 56.48, 85.02
    { 460, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x73c82c} }, // S9 OSM: 1483885 48.99, 8.399 x 49.71, 8.58
    { 994, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0896dd} }, // 98 OSM: 1490387 52.36, 13.03 x 52.4, 13.1
    { 998, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 91 OSM: 1492311 52.36, 13.01 x 52.4, 13.1
    { 226, 3927, 3966, LineMetaDataContent::Subway, Color{0x0000ff} }, // A OSM: 1502599 WD: Q17621067 6.152, -75.63 x 6.339, -75.54
    { 53, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // 1 OSM: 1503481 56.47, 84.95 x 56.53, 85.02
    { 978, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x897cb9} }, // 78 OSM: 1504645 WD: Q6811971 -37.87, 145 x -37.81, 145
    { 966, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x19488e} }, // 92 OSM: 1505928 52.36, 13.03 x 52.42, 13.14
    { 970, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfe9800} }, // 93 OSM: 1509473 52.36, 13.06 x 52.41, 13.1
    { 1002, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x838a8f} }, // 94 OSM: 1512265 52.37, 13.01 x 52.4, 13.11
    { 1005, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x803c9f} }, // S33 OSM: 1513484 49.12, 8.364 x 49.24, 8.594
    { 27, 3994, 3750, LineMetaDataContent::Subway, Color{0xffa500} }, // 6 OSM: 1514439 WD: Q175271 55.6, 37.51 x 55.89, 37.67
    { 40, 4018, 3750, LineMetaDataContent::Subway, Color{0xff00ff} }, // 7 OSM: 1516383 WD: Q924028 55.67, 37.43 x 55.86, 37.86
    { 19, 4042, 3750, LineMetaDataContent::Subway, Color{0xffff00} }, // 8 OSM: 1526351 WD: Q585986 55.74, 37.63 x 55.76, 37.87
    { 63, 4066, 3750, LineMetaDataContent::Subway, Color{0xb4d445} }, // 10 OSM: 1532877 WD: Q582194 55.61, 37.55 x 55.87, 37.76
    { 1009, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xed1c24} }, // N19 OSM: 1536166 48.12, 11.46 x 48.15, 11.64
    { 1013, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf6c046} }, // Zoo Tram OSM: 1536345 35.15, -90 x 35.15, -89.99
    { 157, NoLogo, 209, LineMetaDataContent::RapidTransit, Color{0x0097d8} }, // S3 OSM: 1549250 WD: Q7388286 47.32, 8.501 x 47.53, 8.806
    { 478, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xed1c24} }, // 35 OSM: 1555118 44.42, 25.98 x 44.45, 26.07
    { 190, 4091, 4118, LineMetaDataContent::Subway, Color{0xffd900} }, // B OSM: 1557177 WD: Q3239063 43.56, 1.43 x 43.64, 1.478
    { 200, 4142, 4170, LineMetaDataContent::Tramway, Color{0x004687} }, // T1 OSM: 1557178 WD: Q3239230 43.59, 1.36 x 43.67, 1.446
    { 226, 4194, 4118, LineMetaDataContent::Subway, Color{0xdb001b} }, // A OSM: 1557179 WD: Q3239050 43.57, 1.392 x 43.63, 1.483
    { 1022, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf6c454} }, // S10 OSM: 1561016 WD: Q687279 47.35, 8.465 x 47.38, 8.54
    { 207, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe67d63} }, // S4 OSM: 1567629 WD: Q685807 47.27, 8.517 x 47.38, 8.558
    { 123, 4221, 3750, LineMetaDataContent::Subway, Color{0xa0a2a3} }, // 9 OSM: 1570146 WD: Q739170 55.57, 37.57 x 55.9, 37.63
    { 1026, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe73035} }, // 309 OSM: 1571429 38.22, -77.46 x 38.9, -77
    { 1030, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe73035} }, // 307 OSM: 1571429 38.22, -77.46 x 38.9, -77
    { 1034, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe73035} }, // 305 OSM: 1571429 38.22, -77.46 x 38.9, -77
    { 674, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe73035} }, // 301 OSM: 1571429 38.22, -77.46 x 38.9, -77
    { 1038, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe73035} }, // 315 OSM: 1571429 38.22, -77.46 x 38.9, -77
    { 16, 4245, 3750, LineMetaDataContent::Subway, Color{0x006400} }, // 2 OSM: 1572626 WD: Q834482 55.61, 37.47 x 55.88, 37.77
    { 1042, NoLogo, 209, LineMetaDataContent::RapidTransit, Color{0x946644} }, // S24 OSM: 1574036 WD: Q7388228 47.17, 8.516 x 47.75, 9.106
    { 15, 4269, 3750, LineMetaDataContent::Subway, Color{0xa8bce2} }, // 12 OSM: 1580617 WD: Q678759 55.54, 37.52 x 55.6, 37.59
    { 333, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00a995} }, // 96 OSM: 1585204 52.36, 13.05 x 52.43, 13.14
    { 1047, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x59c133} }, // 99 OSM: 1585259 52.37, 13.06 x 52.4, 13.11
    { 51, NoLogo, 209, LineMetaDataContent::RapidTransit, Color{0xccaaff} }, // S11 OSM: 1588232 WD: Q56435440 47.37, 8.048 x 47.54, 8.771
    { 1050, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0066cc} }, // TMR OSM: 1603490 -27.46, -59.05 x -27.42, -58.98
    { 196, NoLogo, 209, LineMetaDataContent::RapidTransit, Color{0x7751a1} }, // S6 OSM: 1609735 WD: Q7388350 47.26, 8.305 x 47.48, 8.683
    { 1054, NoLogo, 209, LineMetaDataContent::RapidTransit, Color{0xd8242b} }, // S12 OSM: 1614502 WD: Q7388182 47.37, 8.208 x 47.7, 9.042
    { 25, NoLogo, 209, LineMetaDataContent::RapidTransit, Color{0x64b97a} }, // S16 OSM: 1618466 WD: Q7388193 47.28, 8.511 x 47.45, 8.621
    { 1005, NoLogo, 209, LineMetaDataContent::RapidTransit, Color{0x2da7df} }, // S33 OSM: 1619213 WD: Q7388269 47.5, 8.611 x 47.7, 8.726
    { 460, NoLogo, 209, LineMetaDataContent::RapidTransit, Color{0x00a34f} }, // S9 OSM: 1620987 WD: Q7388394 47.35, 8.501 x 47.7, 8.721
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc32b3c} }, // 2 OSM: 1624727 WD: Q60282113 51.75, 14.31 x 51.76, 14.35
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x239537} }, // 4 OSM: 1628047 WD: Q60328960 51.72, 14.32 x 51.79, 14.35
    { 502, 4294, 4327, LineMetaDataContent::Tramway, Color{0xbb4a9b} }, // T2 OSM: 1635139 WD: Q1771110 48.82, 2.217 x 48.92, 2.288
    { 469, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // C-1 OSM: 1636998 WD: Q59928410 41.63, -1.023 x 41.72, -0.8655
    { 53, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xece116} }, // 1 OSM: 1637446 WD: Q60213236 51.75, 14.33 x 51.78, 14.34
    { 226, 4358, NoLogo, LineMetaDataContent::Subway, Color{0x1ca4cb} }, // A OSM: 1637478 WD: Q1209679 -34.63, -58.47 x -34.61, -58.37
    { 22, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x54ad4b} }, // 18 OSM: 1646141 50.73, 6.893 x 50.98, 7.096
    { 1058, 4386, 3569, LineMetaDataContent::RapidTransit, Color{0xed677e} }, // H9 OSM: 1647378 WD: Q947539 47.5, 19.14 x 47.55, 19.27
    { 1061, 4386, 3569, LineMetaDataContent::RapidTransit, Color{0xed677e} }, // H8 OSM: 1647379 WD: Q947539 47.5, 19.14 x 47.6, 19.36
    { 1064, 4401, 3569, LineMetaDataContent::RapidTransit, Color{0x824b00} }, // H6 OSM: 1647380 WD: Q1031918 47.18, 18.94 x 47.47, 19.12
    { 53, NoLogo, 169, LineMetaDataContent::Tramway, Color{0xffd800} }, // 1 OSM: 1658046 WD: Q651686 47.46, 19.02 x 47.55, 19.11
    { 181, NoLogo, 169, LineMetaDataContent::Tramway, Color{0xffd800} }, // 24 OSM: 1658053 WD: Q1489900 47.47, 19.07 x 47.5, 19.09
    { 173, NoLogo, 169, LineMetaDataContent::Tramway, Color{0xffd800} }, // 50 OSM: 1658057 WD: Q643837 47.43, 19.13 x 47.47, 19.22
    { 87, NoLogo, 169, LineMetaDataContent::Tramway, Color{0xffd800} }, // 62 OSM: 1658060 WD: Q1491622 47.48, 19.07 x 47.54, 19.14
    { 1068, NoLogo, 169, LineMetaDataContent::Tramway, Color{0xffd800} }, // 42 OSM: 1658062 WD: Q1490864 47.45, 19.13 x 47.47, 19.15
    { 57, NoLogo, 169, LineMetaDataContent::Tramway, Color{0xffd800} }, // 3 OSM: 1658063 WD: Q1490196 47.44, 19.09 x 47.52, 19.14
    { 130, NoLogo, 169, LineMetaDataContent::Tramway, Color{0xffd800} }, // 14 OSM: 1658066 WD: Q1485881 47.52, 19.06 x 47.59, 19.12
    { 589, NoLogo, 169, LineMetaDataContent::Tramway, Color{0xffd800} }, // 69 OSM: 1658067 WD: Q1491929 47.52, 19.09 x 47.55, 19.15
    { 725, NoLogo, 169, LineMetaDataContent::Tramway, Color{0xffd800} }, // 52 OSM: 1658071 WD: Q1491293 47.42, 19.1 x 47.47, 19.13
    { 1071, NoLogo, 169, LineMetaDataContent::Tramway, Color{0xffd800} }, // 62A OSM: 1658072 WD: Q743389 47.48, 19.1 x 47.54, 19.14
    { 91, NoLogo, 169, LineMetaDataContent::Tramway, Color{0xffd800} }, // 37 OSM: 1658073 WD: Q1490525 47.47, 19.07 x 47.5, 19.18
    { 1075, NoLogo, 169, LineMetaDataContent::Tramway, Color{0xffd800} }, // 51A OSM: 1658076 WD: Q16516127 47.47, 19.07 x 47.48, 19.09
    { 262, NoLogo, 169, LineMetaDataContent::Tramway, Color{0xffd800} }, // 51 OSM: 1658077 WD: Q1491245 47.44, 19.07 x 47.48, 19.12
    { 1079, NoLogo, 169, LineMetaDataContent::Tramway, Color{0xffd800} }, // 28A OSM: 1658080 WD: Q12813290 47.47, 19.07 x 47.5, 19.18
    { 1084, NoLogo, 169, LineMetaDataContent::Tramway, Color{0xffd800} }, // 28 OSM: 1658081 WD: Q1490084 47.47, 19.07 x 47.5, 19.18
    { 1087, NoLogo, 169, LineMetaDataContent::Tramway, Color{0xffd800} }, // 37A OSM: 1658082 WD: Q287376 47.49, 19.07 x 47.5, 19.14
    { 59, 4416, 209, LineMetaDataContent::RapidTransit, Color{0x33b540} }, // S1 OSM: 1660624 WD: Q19377130 53.55, 9.705 x 53.65, 10.09
    { 1093, 4431, 2150, LineMetaDataContent::RapidTransit, Color{0x5e9620} }, // D OSM: 1673421 WD: Q1425351 48.29, 2.344 x 49.27, 2.657
    { 101, 4463, 944, LineMetaDataContent::Subway, Color{0xff0000} }, // U2 OSM: 1676043 WD: Q3433227 49.42, 11.03 x 49.49, 11.11
    { 53, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xdc008f} }, // 1 OSM: 1679960 50.09, 14.34 x 50.1, 14.5
    { 101, 4480, 944, LineMetaDataContent::Subway, Color{0xee1d23} }, // U2 OSM: 1686090 WD: Q275451 53.53, 9.943 x 53.64, 10.15
    { 98, 4495, 944, LineMetaDataContent::Subway, Color{0x0066b3} }, // U1 OSM: 1687370 WD: Q248623 53.55, 9.985 x 53.71, 10.29
    { 767, 4510, 209, LineMetaDataContent::RapidTransit, Color{0x5d1d81} }, // S31 OSM: 1727359 WD: Q19368873 53.46, 9.851 x 53.56, 10.03
    { 239, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfed265} }, // 3F OSM: 1733222 46.25, 20.11 x 46.28, 20.16
    { 57, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfed265} }, // 3 OSM: 1733225 46.25, 20.12 x 46.28, 20.16
    { 1095, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // СТ OSM: 1759150 48.7, 44.5 x 48.8, 44.6
    { 1100, 4526, 4548, LineMetaDataContent::Subway, Color{0x0000ff} }, // 2 Салтівська OSM: 1766294 WD: Q2332390 49.99, 36.23 x 50.03, 36.34
    { 53, 4571, 4548, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 1766295 WD: Q2710248 49.95, 36.18 x 49.99, 36.4
    { 1123, 4593, 4548, LineMetaDataContent::Subway, Color{0x008000} }, // 3 Олексіївська OSM: 1766296 WD: Q2109890 49.98, 36.2 x 50.06, 36.27
    { 53, 4615, NoLogo, LineMetaDataContent::Tramway, Color{} }, // 1 OSM: 1767386 WD: Q63890946 50.41, 30.38 x 50.45, 30.49
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // 2 OSM: 1788097 55.67, 52.28 x 55.73, 52.47
    { 1150, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x1b522b} }, // 12а OSM: 1789317 55.67, 52.28 x 55.75, 52.47
    { 502, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x96bf0d} }, // T2 OSM: 1824544 WD: Q106915028 47.29, 5.006 x 47.37, 5.059
    { 200, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xcc0088} }, // T1 OSM: 1824550 WD: Q106915007 47.31, 5.028 x 47.33, 5.112
    { 418, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x4f4a9f} }, // 30 OSM: 1830395 WD: Q6811953 -37.81, 144.9 x -37.81, 145
    { 1155, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xc60c30} }, // Port Washington OSM: 1834644 WD: Q7231025 40.7, -73.99 x 40.83, -73.69
    { 104, 4631, 944, LineMetaDataContent::Subway, Color{0x00868b} }, // U3 OSM: 1857497 WD: Q3433219 49.44, 11.02 x 49.47, 11.09
    { 98, 4648, 944, LineMetaDataContent::Subway, Color{0x000066} }, // U1 OSM: 1857639 WD: Q3433210 49.4, 10.96 x 49.48, 11.14
    { 67, 4665, NoLogo, LineMetaDataContent::Tramway, Color{} }, // 21 OSM: 1871117 WD: Q85093119 50.07, 8.567 x 50.11, 8.67
    { 226, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe30613} }, // A OSM: 1874970 WD: Q2066292 339.5, 249.5 x 339.5, 249.5
    { 190, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009fe3} }, // B OSM: 1874971 WD: Q2085986 339.5, 249.5 x 339.5, 249.5
    { 52, 4695, NoLogo, LineMetaDataContent::Tramway, Color{} }, // 11 OSM: 1875166 WD: Q85088920 50.1, 8.552 x 50.13, 8.774
    { 15, 4725, NoLogo, LineMetaDataContent::Tramway, Color{} }, // 12 OSM: 1875167 WD: Q85090131 50.08, 8.581 x 50.13, 8.756
    { 130, 4755, NoLogo, LineMetaDataContent::Tramway, Color{} }, // 14 OSM: 1875169 WD: Q85112445 50.1, 8.618 x 50.13, 8.716
    { 134, 4785, NoLogo, LineMetaDataContent::Tramway, Color{} }, // 15 OSM: 1875170 WD: Q85112688 50.09, 8.636 x 50.1, 8.745
    { 169, 4815, NoLogo, LineMetaDataContent::Tramway, Color{} }, // 17 OSM: 1875171 WD: Q107028657 50.06, 8.619 x 50.12, 8.695
    { 196, 4845, 209, LineMetaDataContent::RapidTransit, Color{0xf57921} }, // S6 OSM: 1880910 WD: Q3238987 50.1, 8.633 x 50.34, 8.789
    { 169, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8d1d2c} }, // 17 OSM: 1903836 WD: Q96578284 47.35, 8.482 x 47.4, 8.542
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x9bd6f9} }, // 4 OSM: 1904829 50.03, 14.37 x 50.08, 14.48
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xed1c24} }, // 8 OSM: 1927430 44.39, 25.98 x 44.43, 26.09
    { 226, 4862, NoLogo, LineMetaDataContent::Tramway, Color{0xa83939} }, // A OSM: 1940504 WD: Q10883225 35, 135.7 x 35.02, 135.7
    { 27, 4907, 1437, LineMetaDataContent::Tramway, Color{} }, // 6 OSM: 1942851 WD: Q104867938 49.43, 11.05 x 49.46, 11.12
    { 221, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x913108} }, // C OSM: 1958845 37.79, -122.4 x 37.79, -122.4
    { 130, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 14 OSM: 1968651 44.76, 20.47 x 44.81, 20.52
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 6 OSM: 1968652 44.78, 20.47 x 44.81, 20.52
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x003828} }, // 2 OSM: 1984325 52.9, -1.207 x 52.99, -1.145
    { 486, 4924, NoLogo, LineMetaDataContent::Tramway, Color{} }, // SG OSM: 1994315 WD: Q339069 35.64, 139.6 x 35.67, 139.7
    { 437, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x004ea2} }, // SL OSM: 1994316 WD: Q6360898 35.33, 139.6 x 35.39, 139.7
    { 344, 4949, 19, LineMetaDataContent::Tramway, Color{0x33ff33} }, // M2 OSM: 2001598 WD: Q62512253 52.52, 13.41 x 52.57, 13.44
    { 1171, 480, NoLogo, LineMetaDataContent::Subway, Color{0x302276} }, // U75 OSM: 2003447 WD: Q661002 51.2, 6.684 x 51.23, 6.847
    { 1175, 480, NoLogo, LineMetaDataContent::Subway, Color{0x302276} }, // U78 OSM: 2003448 WD: Q661002 51.22, 6.733 x 51.27, 6.795
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x967b68} }, // 13 OSM: 2003476 50.91, 6.908 x 50.97, 7.038
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x948fb8} }, // 5 OSM: 2003477 50.93, 6.888 x 50.98, 6.96
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfff500} }, // 5 OSM: 2024979 50.03, 14.37 x 50.09, 14.48
    { 57, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe693b5} }, // 3 OSM: 2026288 50.93, 6.87 x 50.98, 7.086
    { 79, NoLogo, 480, LineMetaDataContent::Tramway, Color{0x98c000} }, // 61 OSM: 2026289 WD: Q20035840 50.7, 7.071 x 50.76, 7.112
    { 87, NoLogo, 480, LineMetaDataContent::Tramway, Color{0x61af20} }, // 62 OSM: 2026290 WD: Q20035841 50.7, 7.095 x 50.74, 7.176
    { 75, NoLogo, 480, LineMetaDataContent::Tramway, Color{0x60d6f7} }, // 63 OSM: 2026291 WD: Q20035835 50.68, 7.047 x 50.75, 7.159
    { 161, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xee99bf} }, // 67 OSM: 2026293 50.68, 7.092 x 50.79, 7.203
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf7d09b} }, // 6 OSM: 2032473 50.07, 14.42 x 50.11, 14.48
    { 1179, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x005a9c} }, // Fremantle OSM: 2033169 WD: Q5501509 -32.05, 115.7 x -31.94, 115.9
    { 1189, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe06f1d} }, // Mandurah OSM: 2033178 WD: Q1895265 -32.53, 115.7 x -31.95, 115.9
    { 1198, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa6aa12} }, // Joondalup OSM: 2033180 WD: Q6276051 -31.95, 115.7 x -31.63, 115.9
    { 1208, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfebe10} }, // Armadale OSM: 2033191 WD: Q1924165 -32.16, 115.9 x -31.95, 116
    { 40, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00ffff} }, // 7 OSM: 2061854 50.06, 14.39 x 50.08, 14.51
    { 53, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009cdd} }, // 1 OSM: 2067963 53.43, 14.49 x 53.47, 14.55
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009cdd} }, // 12 OSM: 2074000 53.4, 14.52 x 53.46, 14.55
    { 200, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe3002b} }, // T1 OSM: 2074462 48.65, 6.145 x 48.7, 6.225
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009cdd} }, // 5 OSM: 2077222 53.43, 14.49 x 53.46, 14.55
    { 52, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009cdd} }, // 11 OSM: 2077355 53.4, 14.53 x 53.45, 14.58
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009cdd} }, // 6 OSM: 2077516 53.4, 14.53 x 53.48, 14.61
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009cdd} }, // 8 OSM: 2080359 53.38, 14.49 x 53.43, 14.64
    { 40, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009cdd} }, // 7 OSM: 2080360 53.38, 14.49 x 53.45, 14.64
    { 57, 4968, NoLogo, LineMetaDataContent::Tramway, Color{0xef7c00} }, // 3 OSM: 2083643 WD: Q99229508 48.31, 10.84 x 48.37, 10.9
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x94c11c} }, // 6 OSM: 2083654 48.35, 10.89 x 48.37, 10.96
    { 53, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xb5c426} }, // 1 OSM: 2100315 WD: Q6811945 -37.85, 144.9 x -37.74, 145
    { 1217, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00bfe8} }, // N20 OSM: 2101204 48.14, 11.51 x 48.18, 11.56
    { 53, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // 1 OSM: 2102327 51.98, 8.502 x 52.06, 8.546
    { 57, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffff00} }, // 3 OSM: 2102329 52.02, 8.518 x 52.06, 8.543
    { 16, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // 2 OSM: 2102391 52, 8.532 x 52.06, 8.628
    { 9, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // 4 OSM: 2102392 52, 8.485 x 52.05, 8.589
    { 53, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffeedd} }, // 1 OSM: 2104341 54.14, 19.39 x 54.19, 19.44
    { 1221, 4988, 209, LineMetaDataContent::RapidTransit, Color{0xe7526b} }, // S20 OSM: 2113865 WD: Q7388223 48.04, 11.46 x 48.15, 11.54
    { 39, 5005, 209, LineMetaDataContent::RapidTransit, Color{0x983224} }, // S7 OSM: 2113867 WD: Q7388364 47.91, 11.42 x 48.14, 11.78
    { 53, NoLogo, 5021, LineMetaDataContent::Tramway, Color{0x00a651} }, // 1 OSM: 2116454 WD: Q3238670 47.2, -1.639 x 47.26, -1.515
    { 57, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x90ee90} }, // 3 OSM: 2161840 49.81, 24 x 49.84, 24.04
    { 16, NoLogo, 5021, LineMetaDataContent::Tramway, Color{0xee1c25} }, // 2 OSM: 2166523 WD: Q3238813 47.19, -1.593 x 47.26, -1.542
    { 57, NoLogo, 5021, LineMetaDataContent::Tramway, Color{0x006db1} }, // 3 OSM: 2166524 WD: Q3238913 47.18, -1.617 x 47.25, -1.542
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x90ee90} }, // 2 OSM: 2169223 49.82, 23.99 x 49.84, 24.07
    { 19, 5045, NoLogo, LineMetaDataContent::RapidTransit, Color{0x808080} }, // 8 OSM: 2174536 WD: Q3296720 -23.55, -46.98 x -23.51, -46.64
    { 123, 5056, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00a88e} }, // 9 OSM: 2183695 WD: Q5245848 -23.76, -46.78 x -23.53, -46.69
    { 207, NoLogo, 209, LineMetaDataContent::RapidTransit, Color{0x000080} }, // S4 OSM: 2199152 WD: Q7388307 49.25, 10.3 x 49.44, 11.08
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0071bc} }, // 2 OSM: 2203208 48.98, 8.345 x 49.04, 8.479
    { 52, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xed1c24} }, // 11 OSM: 2205114 44.38, 26.02 x 44.47, 26.1
    { 57, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 3 OSM: 2206996 WD: Q104521929 41.87, 12.47 x 41.92, 12.52
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x1c63b7} }, // 2 OSM: 2206997 WD: Q104521890 41.91, 12.46 x 41.93, 12.48
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xed1c24} }, // 5 OSM: 2206998 WD: Q104537333 41.88, 12.5 x 41.9, 12.57
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xbfdf14} }, // 8 OSM: 2206999 WD: Q104537360 41.87, 12.44 x 41.9, 12.52
    { 226, 5067, 3117, LineMetaDataContent::Subway, Color{0xf68b1f} }, // A OSM: 2207255 WD: Q572544 41.84, 12.42 x 41.91, 12.59
    { 190, 5108, 3117, LineMetaDataContent::Subway, Color{0x3783c6} }, // B OSM: 2208346 WD: Q2666571 41.83, 12.46 x 41.95, 12.57
    { 1225, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfbbc09} }, // FC1 OSM: 2208347 41.87, 12.51 x 41.9, 12.56
    { 1229, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7eb9e6} }, // FC2 OSM: 2208348 41.71, 12.28 x 41.88, 12.48
    { 1233, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x55b036} }, // FC3 OSM: 2208349 41.91, 12.11 x 42.44, 12.5
    { 130, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00adef} }, // 14 OSM: 2208350 WD: Q415821 41.89, 12.5 x 41.9, 12.57
    { 138, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf89c0e} }, // 19 OSM: 2208351 WD: Q104537271 41.88, 12.46 x 41.92, 12.57
    { 371, 5149, NoLogo, LineMetaDataContent::RapidTransit, Color{0x007663} }, // FL1 OSM: 2208499 WD: Q3737286 41.79, 12.25 x 42.44, 12.65
    { 375, 5184, NoLogo, LineMetaDataContent::RapidTransit, Color{0x004174} }, // FL2 OSM: 2208500 WD: Q3737287 41.9, 12.53 x 42.1, 13.43
    { 367, 5219, NoLogo, LineMetaDataContent::RapidTransit, Color{0x965b0e} }, // FL4 OSM: 2208502 WD: Q25064 41.67, 12.5 x 41.9, 12.78
    { 1237, 5254, NoLogo, LineMetaDataContent::RapidTransit, Color{0xdccc00} }, // FL5 OSM: 2208503 WD: Q3737292 41.86, 11.8 x 42.09, 12.53
    { 1241, 5289, NoLogo, LineMetaDataContent::RapidTransit, Color{0xdc66ba} }, // FL6 OSM: 2208504 WD: Q3737295 41.48, 12.5 x 41.9, 13.83
    { 1245, 5324, NoLogo, LineMetaDataContent::RapidTransit, Color{0x91d44f} }, // FL7 OSM: 2208505 WD: Q661786 41.25, 12.5 x 41.9, 13.72
    { 1249, 5359, NoLogo, LineMetaDataContent::RapidTransit, Color{0x6cbf68} }, // FL8 OSM: 2208506 WD: Q3737301 41.45, 12.5 x 41.9, 12.66
    { 1253, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xca0a23} }, // LEX OSM: 2208507 WD: Q1207539 41.79, 12.25 x 41.9, 12.53
    { 63, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xed1c24} }, // 10 OSM: 2212352 44.38, 26.05 x 44.45, 26.15
    { 19, 5394, 5415, LineMetaDataContent::Tramway, Color{0x0098d4} }, // 8 OSM: 2262665 WD: Q431783 50.8, 4.353 x 50.85, 4.44
    { 390, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00ff80} }, // 657 OSM: 2271832 32.72, -117.4 x 33.19, -117.2
    { 1257, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00ff80} }, // 631 OSM: 2271832 32.72, -117.4 x 33.19, -117.2
    { 1261, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00ff80} }, // 635 OSM: 2271832 32.72, -117.4 x 33.19, -117.2
    { 1265, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00ff80} }, // 665 OSM: 2271832 32.72, -118.2 x 34.06, -117.2
    { 1269, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00ff80} }, // 639 OSM: 2271832 32.72, -117.4 x 33.19, -117.2
    { 1273, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00ff80} }, // 655 OSM: 2271832 32.72, -117.4 x 33.19, -117.2
    { 1278, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x669933} }, // 87 OSM: 2282096 WD: Q428288 52.44, 13.69 x 52.46, 13.76
    { 53, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008f4d} }, // 1 OSM: 2309633 33.84, 132.8 x 33.85, 132.8
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf9a51b} }, // 2 OSM: 2309634 33.84, 132.8 x 33.85, 132.8
    { 226, 5441, 2150, LineMetaDataContent::RapidTransit, Color{0xd1302f} }, // A OSM: 2333448 WD: Q741818 48.75, 2.01 x 49.05, 2.783
    { 123, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x112233} }, // 9 OSM: 2336329 54.27, 48.29 x 54.34, 48.39
    { 53, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xe4002b} }, // 1 OSM: 2336458 WD: Q263572 29.53, 106.2 x 29.62, 106.6
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xd75128} }, // 4 OSM: 2368452 50.72, 12.43 x 50.75, 12.49
    { 63, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009cdd} }, // 10 OSM: 2372195 53.41, 14.49 x 53.43, 14.55
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfed265} }, // 2 OSM: 2380276 46.24, 20.13 x 46.27, 20.15
    { 53, 5473, NoLogo, LineMetaDataContent::Subway, Color{0x10069f} }, // 1 OSM: 2381769 WD: Q6118988 30.39, 104.1 x 30.72, 104.1
    { 45, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x04a5c8} }, // S8 OSM: 2396232 WD: Q2381339 41.35, 1.919 x 41.48, 2.149
    { 261, NoLogo, 209, LineMetaDataContent::RapidTransit, Color{0xf8a20d} }, // S51 OSM: 2412316 WD: Q96388878 49.3, 8.674 x 49.42, 8.991
    { 63, 5483, NoLogo, LineMetaDataContent::Tramway, Color{0xb4e16e} }, // 10 OSM: 2413392 WD: Q106921203 57.68, 11.89 x 57.73, 11.98
    { 19, 5506, NoLogo, LineMetaDataContent::Tramway, Color{0x872387} }, // 8 OSM: 2413517 WD: Q106921198 57.65, 11.91 x 57.8, 12.05
    { 56, 5528, NoLogo, LineMetaDataContent::Tramway, Color{0xfee6c2} }, // 13 OSM: 2413518 WD: Q106921216 57.66, 11.85 x 57.71, 11.99
    { 16, 5551, NoLogo, LineMetaDataContent::Tramway, Color{0xfff014} }, // 2 OSM: 2413613 WD: Q106921120 57.65, 11.93 x 57.71, 12.02
    { 9, 5573, NoLogo, LineMetaDataContent::Tramway, Color{0x14823c} }, // 4 OSM: 2413615 WD: Q106921167 57.65, 11.97 x 57.8, 12.05
    { 509, 5595, 209, LineMetaDataContent::RapidTransit, Color{0xba8a4d} }, // S47 OSM: 2413847 WD: Q3742025 52.45, 13.43 x 52.47, 13.56
    { 57, 5610, NoLogo, LineMetaDataContent::Tramway, Color{0x004b85} }, // 3 OSM: 2418220 WD: Q106921163 57.67, 11.91 x 57.72, 12.03
    { 123, 5632, NoLogo, LineMetaDataContent::Tramway, Color{0x6ec8dc} }, // 9 OSM: 2418235 WD: Q106921200 57.68, 11.9 x 57.8, 12.05
    { 52, 5654, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 11 OSM: 2418236 WD: Q106921207 57.66, 11.85 x 57.76, 12.07
    { 1281, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // 901 OSM: 2440421 WD: Q1617191 44.85, -93.28 x 44.98, -93.2
    { 1285, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x61af20} }, // RB23 OSM: 2441590 WD: Q1699351 50.56, 6.761 x 50.74, 7.098
    { 94, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf0e130} }, // 888 OSM: 2442946 44.98, -93.73 x 45.33, -93.25
    { 59, 5677, 209, LineMetaDataContent::RapidTransit, Color{0x0b9a33} }, // S1 OSM: 2444997 WD: Q7388210 51.16, 6.772 x 51.52, 7.46
    { 51, 5688, 209, LineMetaDataContent::RapidTransit, Color{0xef7c00} }, // S11 OSM: 2445000 WD: Q7388174 50.94, 6.674 x 51.28, 7.125
    { 1054, 5700, 209, LineMetaDataContent::RapidTransit, Color{0x61af20} }, // S12 OSM: 2445001 WD: Q7388180 50.76, 6.713 x 50.95, 7.66
    { 1290, 5712, 209, LineMetaDataContent::RapidTransit, Color{0x00a6eb} }, // S13 OSM: 2445007 WD: Q7388184 50.81, 6.482 x 50.95, 7.151
    { 48, 5724, 209, LineMetaDataContent::RapidTransit, Color{0x006db6} }, // S2 OSM: 2445008 WD: Q7388251 51.45, 7.015 x 51.62, 7.46
    { 1083, 5735, 209, LineMetaDataContent::RapidTransit, Color{0x717676} }, // S28 OSM: 2445009 WD: Q7388234 51.2, 6.594 x 51.25, 7.152
    { 157, 5747, 209, LineMetaDataContent::RapidTransit, Color{0x999999} }, // S3 OSM: 2445010 WD: Q7388285 51.4, 6.835 x 51.48, 7.181
    { 207, 5758, 209, LineMetaDataContent::RapidTransit, Color{0xef7c00} }, // S4 OSM: 2445011 WD: Q7388319 51.5, 7.334 x 51.55, 7.692
    { 42, 5769, 209, LineMetaDataContent::RapidTransit, Color{0x98c60f} }, // S5 OSM: 2445012 WD: Q7388333 51.36, 7.325 x 51.52, 7.46
    { 196, 5780, 209, LineMetaDataContent::RapidTransit, Color{0xdc052d} }, // S6 OSM: 2445013 WD: Q7388349 50.94, 6.79 x 51.45, 7.023
    { 1294, 5791, 209, LineMetaDataContent::RapidTransit, Color{0x14bae6} }, // S68 OSM: 2445014 WD: Q7388346 51.1, 6.79 x 51.23, 7.074
    { 45, 5803, 209, LineMetaDataContent::RapidTransit, Color{0xb03303} }, // S8 OSM: 2445015 WD: Q7388383 51.19, 6.445 x 51.36, 7.46
    { 460, 5814, 209, LineMetaDataContent::RapidTransit, Color{0xc7007f} }, // S9 OSM: 2445016 WD: Q7388395 51.23, 6.921 x 51.74, 7.46
    { 59, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xec192e} }, // S1 OSM: 2445551 49.33, 7.334 x 49.48, 9.424
    { 48, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x2960b5} }, // S2 OSM: 2445552 49.34, 7.768 x 49.48, 9.144
    { 157, 5825, 209, LineMetaDataContent::RapidTransit, Color{0x00a896} }, // S3 OSM: 2445553 WD: Q2781002 49.87, 8.504 x 50.16, 8.699
    { 157, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfcd804} }, // S3 OSM: 2445554 48.99, 8.349 x 49.48, 8.685
    { 207, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x1a9d47} }, // S4 OSM: 2445555 48.99, 8.349 x 49.48, 9.528
    { 53, 5842, 5862, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 2446076 WD: Q519861 59.84, 30.25 x 60.05, 30.44
    { 16, 5881, 5862, LineMetaDataContent::Subway, Color{0x0000ff} }, // 2 OSM: 2446077 WD: Q1459627 59.83, 30.3 x 60.07, 30.38
    { 57, 5901, 5862, LineMetaDataContent::Subway, Color{0x008000} }, // 3 OSM: 2446078 WD: Q1509576 59.83, 30.2 x 59.99, 30.5
    { 9, 5921, 5862, LineMetaDataContent::Subway, Color{0xffa500} }, // 4 OSM: 2446079 WD: Q1784097 59.91, 30.32 x 59.93, 30.48
    { 6, 5941, 5862, LineMetaDataContent::Subway, Color{0x800080} }, // 5 OSM: 2446080 WD: Q1579583 59.82, 30.25 x 60.01, 30.43
    { 502, 5961, 5983, LineMetaDataContent::Tramway, Color{0xf5e615} }, // T2 OSM: 2449769 WD: Q3238811 43.3, 5.367 x 43.32, 5.406
    { 200, 6004, 5983, LineMetaDataContent::Tramway, Color{0xf18e00} }, // T1 OSM: 2452278 WD: Q3238668 43.29, 5.381 x 43.3, 5.444
    { 1298, 6026, 6050, LineMetaDataContent::Subway, Color{0x008cd1} }, // Μ3 OSM: 2473158 WD: Q6553119 37.91, 23.65 x 38.02, 23.94
    { 157, 6104, 209, LineMetaDataContent::RapidTransit, Color{0xdb6eab} }, // S3 OSM: 2474189 WD: Q63433452 52.16, 9.739 x 52.38, 10.02
    { 42, 6120, 209, LineMetaDataContent::RapidTransit, Color{0xf78a18} }, // S5 OSM: 2474199 WD: Q63433456 51.71, 8.737 x 52.46, 9.773
    { 16, 6136, 6162, LineMetaDataContent::Subway, Color{0x0000ff} }, // 2 OSM: 2507796 WD: Q2001449 41.24, 69.2 x 41.35, 69.37
    { 57, 6181, 6162, LineMetaDataContent::Subway, Color{0x008000} }, // 3 OSM: 2507797 WD: Q4534678 41.3, 69.27 x 41.38, 69.3
    { 53, 6207, 6162, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 2507927 WD: Q4515924 41.21, 69.19 x 41.33, 69.33
    { 42, 6233, 209, LineMetaDataContent::RapidTransit, Color{0xa52a2a} }, // S5 OSM: 2515355 WD: Q2515085 50.1, 8.583 x 50.25, 8.699
    { 207, 6250, 209, LineMetaDataContent::RapidTransit, Color{0xfecb09} }, // S4 OSM: 2515408 WD: Q2204443 49.99, 8.516 x 50.18, 8.699
    { 39, 6267, 209, LineMetaDataContent::RapidTransit, Color{0x14bae6} }, // S7 OSM: 2544304 WD: Q1195962 51.16, 7.004 x 51.28, 7.253
    { 59, 6278, 209, LineMetaDataContent::RapidTransit, Color{0x7760b0} }, // S1 OSM: 2548861 WD: Q63433445 52.27, 8.934 x 52.42, 9.773
    { 1302, 6294, 6316, LineMetaDataContent::Subway, Color{0x79bb92} }, // 7bis OSM: 2554103 WD: Q50749 48.88, 2.366 x 48.88, 2.401
    { 196, 6328, 209, LineMetaDataContent::RapidTransit, Color{0x005aab} }, // S6 OSM: 2557420 WD: Q63433460 52.37, 9.739 x 52.62, 10.06
    { 1307, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x62361b} }, // Brown OSM: 2562976 WD: Q3112936 41.88, -87.71 x 41.97, -87.63
    { 207, 6344, 209, LineMetaDataContent::RapidTransit, Color{0x972f50} }, // S4 OSM: 2567719 WD: Q63433455 52.16, 9.687 x 52.58, 9.956
    { 8, NoLogo, 6360, LineMetaDataContent::Subway, Color{0x347c11} }, // M4 OSM: 2568424 WD: Q2552821 44.45, 26.03 x 44.5, 26.07
    { 200, 6378, 4327, LineMetaDataContent::Tramway, Color{0x216eb4} }, // T1 OSM: 2572573 WD: Q369969 48.9, 2.274 x 48.94, 2.47
    { 372, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xd6457d} }, // L1 OSM: 2575540 59.74, 10.34 x 59.96, 11.05
    { 1313, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xf9461c} }, // Orange OSM: 2578312 WD: Q3180068 41.79, -87.74 x 41.89, -87.63
    { 53, 6411, 6430, LineMetaDataContent::Subway, Color{0xe50b00} }, // 1 OSM: 2580502 WD: Q1771534 56.24, 43.86 x 56.32, 43.99
    { 1320, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xa52a2a} }, // Scala mobile OSM: 2581270 41.84, 12.89 x 41.84, 12.89
    { 285, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xc60c30} }, // Red OSM: 2584583 WD: Q642623 41.72, -87.67 x 42.02, -87.62
    { 196, NoLogo, 209, LineMetaDataContent::RapidTransit, Color{0xec192e} }, // S6 OSM: 2587144 WD: Q96388302 49.44, 8.256 x 50, 8.667
    { 1333, NoLogo, 209, LineMetaDataContent::RapidTransit, Color{0x6b2c94} }, // S 8 OSM: 2605126 WD: Q63213955 51.47, 11.98 x 51.87, 12.66
    { 678, NoLogo, 209, LineMetaDataContent::RapidTransit, Color{0xf17f1a} }, // S 5 OSM: 2606971 WD: Q63216051 50.7, 11.99 x 51.48, 12.48
    { 1338, NoLogo, 209, LineMetaDataContent::RapidTransit, Color{0x00a650} }, // S 4 OSM: 2607472 WD: Q63215993 51.25, 12.37 x 51.59, 14.23
    { 59, NoLogo, 209, LineMetaDataContent::RapidTransit, Color{0x66cdaa} }, // S1 OSM: 2609006 WD: Q50331474 54.08, 12.06 x 54.18, 12.13
    { 157, NoLogo, 209, LineMetaDataContent::RapidTransit, Color{} }, // S3 OSM: 2609009 WD: Q50331483 53.79, 12.06 x 54.18, 12.35
    { 48, NoLogo, 209, LineMetaDataContent::RapidTransit, Color{0x9400d3} }, // S2 OSM: 2609011 WD: Q50331479 53.8, 12.06 x 54.18, 12.17
    { 1342, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff9700} }, // SFM 1 OSM: 2610264 WD: Q3832755 44.97, 7.603 x 45.42, 7.824
    { 1348, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // SFM 4 OSM: 2610270 WD: Q3832758 44.69, 7.654 x 45.12, 8.031
    { 463, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x009b3a} }, // Green OSM: 2613599 WD: Q3176204 41.78, -87.81 x 41.89, -87.61
    { 1354, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x7fd2e6} }, // U44 OSM: 2615764 51.51, 7.385 x 51.53, 7.484
    { 67, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe2000a} }, // 21 OSM: 2617691 49.4, 8.675 x 49.43, 8.693
    { 749, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfcc200} }, // 22 OSM: 2617692 49.4, 8.627 x 49.41, 8.693
    { 255, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe48e00} }, // 23 OSM: 2617693 49.34, 8.682 x 49.43, 8.693
    { 181, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8b1c75} }, // 24 OSM: 2617694 49.37, 8.66 x 49.47, 8.691
    { 523, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf39a9a} }, // 26 OSM: 2617695 49.38, 8.658 x 49.41, 8.693
    { 123, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x93c13b} }, // 9 OSM: 2621592 49.48, 8.469 x 49.48, 8.523
    { 278, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xf9e300} }, // Yellow OSM: 2622574 WD: Q595450 42.02, -87.75 x 42.04, -87.67
    { 310, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x004595} }, // M OSM: 2629655 WD: Q55079952 49.39, 1.042 x 49.45, 1.106
    { 1358, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x20825c} }, // PAO OSM: 2629939 WD: Q7132125 39.95, -75.76 x 40.05, -75.15
    { 123, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf171ab} }, // 9 OSM: 2629996 WD: Q56302775 46.93, 7.431 x 46.97, 7.468
    { 57, NoLogo, 6442, LineMetaDataContent::Subway, Color{0xa066aa} }, // 3 OSM: 2635252 WD: Q15731044 59.85, 10.5 x 59.94, 10.85
    { 613, 6463, 19, LineMetaDataContent::Tramway, Color{0x00bfe8} }, // 29 OSM: 2635531 WD: Q63435524 48.14, 11.49 x 48.16, 11.56
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x028dd2} }, // 6 OSM: 2635960 55.67, 52.28 x 55.77, 52.45
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x3adf00} }, // 8 OSM: 2635970 55.67, 52.28 x 55.77, 52.45
    { 16, NoLogo, 6442, LineMetaDataContent::Subway, Color{0xf26522} }, // 2 OSM: 2636245 WD: Q15731043 59.91, 10.61 x 59.95, 10.92
    { 6, NoLogo, 6442, LineMetaDataContent::Subway, Color{0x50b848} }, // 5 OSM: 2640907 WD: Q15731051 59.91, 10.71 x 59.97, 10.93
    { 1362, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // Meadowlands OSM: 2641818 WD: Q6803384 40.73, -74.1 x 40.83, -74.03
    { 1374, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa0218c} }, // Pascack Valley OSM: 2641819 WD: Q11328810 40.73, -74.1 x 41.11, -74.01
    { 1389, 6491, 480, LineMetaDataContent::Tramway, Color{0x8874c7} }, // U46 OSM: 2642232 WD: Q107740407 51.5, 7.459 x 51.53, 7.471
    { 1393, 6505, 6525, LineMetaDataContent::Tramway, Color{0x873f98} }, // T5 OSM: 2643507 WD: Q3238967 45.73, 4.879 x 45.74, 4.948
    { 57, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // 3 OSM: 2644926 55.72, 52.41 x 55.77, 52.5
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xa82582} }, // 4 OSM: 2646469 55.69, 52.41 x 55.77, 52.53
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe6087f} }, // 5 OSM: 2646596 55.72, 52.41 x 55.76, 52.5
    { 40, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x393186} }, // 7 OSM: 2646626 55.69, 52.41 x 55.77, 52.53
    { 1396, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa0a0a0} }, // C-8 OSM: 2647592 40.38, -4.067 x 40.74, -3.181
    { 226, 6553, 6587, LineMetaDataContent::Tramway, Color{0x802990} }, // A OSM: 2648050 WD: Q2658981 44.83, -0.6686 x 44.89, -0.5081
    { 190, 6613, 6587, LineMetaDataContent::Tramway, Color{0xed164b} }, // B OSM: 2648235 WD: Q2420027 44.79, -0.6632 x 44.89, -0.5415
    { 63, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 10 OSM: 2653185 44.76, 20.45 x 44.83, 20.48
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 2 OSM: 2653193 44.8, 20.45 x 44.83, 20.48
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 5 OSM: 2653197 44.78, 20.45 x 44.83, 20.52
    { 1400, 3117, 3117, LineMetaDataContent::Subway, Color{0xff0000} }, // Metropolitana OSM: 2653212 WD: Q1163754 44.4, 8.894 x 44.43, 8.949
    { 27, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x2c8195} }, // 6 OSM: 2653338 WD: Q6553143 25.03, 102.7 x 25.1, 102.9
    { 221, 6647, 6587, LineMetaDataContent::Tramway, Color{0xcf56a0} }, // C OSM: 2654042 WD: Q2331392 44.77, -0.6237 x 44.92, -0.5499
    { 1414, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xe27ea6} }, // Pink OSM: 2656070 WD: Q3112661 41.85, -87.76 x 41.89, -87.63
    { 273, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x00a1de} }, // Blue OSM: 2672370 WD: Q2534873 41.87, -87.9 x 41.98, -87.63
    { 1419, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xa3d20b} }, // U47 OSM: 2673747 51.49, 7.382 x 51.55, 7.556
    { 123, 6681, 3199, LineMetaDataContent::Subway, Color{0x87d300} }, // 9 OSM: 2674584 WD: Q5929508 39.81, 116.3 x 39.94, 116.3
    { 425, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfcdc00} }, // U41 OSM: 2674820 51.48, 7.44 x 51.59, 7.502
    { 421, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00a991} }, // U43 OSM: 2675103 51.51, 7.419 x 51.53, 7.625
    { 40, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x9e0234} }, // 7 OSM: 2675693 51.04, 13.63 x 51.14, 13.8
    { 1427, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x522398} }, // Purple OSM: 2675822 WD: Q3112074 41.88, -87.69 x 42.07, -87.63
    { 59, 6701, 6713, LineMetaDataContent::RapidTransit, Color{0x159dd9} }, // S1 OSM: 2679058 WD: Q17101540 48.17, 16.33 x 48.34, 16.92
    { 48, 6729, 6713, LineMetaDataContent::RapidTransit, Color{0x159dd9} }, // S2 OSM: 2679059 WD: Q96484152 48.08, 16.28 x 48.72, 16.57
    { 157, 6741, 6713, LineMetaDataContent::RapidTransit, Color{0x159dd9} }, // S3 OSM: 2679060 WD: Q96484012 47.81, 16.06 x 48.56, 16.41
    { 48, 6753, 209, LineMetaDataContent::RapidTransit, Color{0x118349} }, // S2 OSM: 2682237 WD: Q63433449 52.28, 9.217 x 52.65, 9.773
    { 1434, 6769, 3199, LineMetaDataContent::Subway, Color{0x007e84} }, // 4S OSM: 2684711 WD: Q5242742 39.67, 116.3 x 39.81, 116.4
    { 134, 6794, 3199, LineMetaDataContent::Subway, Color{0x6a1d44} }, // 15 OSM: 2688949 WD: Q734917 39.99, 116.3 x 40.13, 116.7
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x006b42} }, // 12 OSM: 2690192 51.04, 13.67 x 51.06, 13.81
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x223344} }, // 2 OSM: 2694563 54.26, 48.28 x 54.34, 48.41
    { 523, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00aaad} }, // 26 OSM: 2705952 59.27, 18.27 x 59.29, 18.3
    { 233, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00aaad} }, // 25 OSM: 2705957 59.28, 18.11 x 59.31, 18.31
    { 226, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffbf00} }, // A OSM: 2716905 32.98, -97.13 x 33.21, -96.93
    { 1437, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x003e7e} }, // TRE OSM: 2716975 WD: Q2453601 32.75, -97.33 x 32.82, -96.81
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0066} }, // 5 OSM: 2718682 339.5, 249.5 x 339.5, 249.5
    { 1441, NoLogo, 6815, LineMetaDataContent::Subway, Color{0xf5a200} }, // 272 OSM: 2718887 WD: Q84389881 37.24, 126.6 x 37.58, 127.1
    { 63, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xdc008f} }, // 10 OSM: 2728288 50.06, 14.3 x 50.13, 14.48
    { 52, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xdc008f} }, // 11 OSM: 2728371 50.05, 14.43 x 50.09, 14.5
    { 1445, NoLogo, 209, LineMetaDataContent::RapidTransit, Color{0xeb3c2e} }, // S18 OSM: 2729450 WD: Q686782 47.29, 8.547 x 47.37, 8.71
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xa28a6a} }, // 12 OSM: 2729904 50.03, 14.37 x 50.11, 14.45
    { 11, 6843, 3117, LineMetaDataContent::Subway, Color{0x7956a3} }, // M5 OSM: 2753306 WD: Q3238963 45.48, 9.117 x 45.53, 9.212
    { 1449, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 479 OSM: 2768041 37.33, -122.4 x 37.78, -121.9
    { 27, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xf67599} }, // 6 OSM: 2768662 WD: Q5931449 29.49, 106.4 x 29.85, 106.7
    { 53, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe3000b} }, // 1 OSM: 2777016 52.2, 10.51 x 52.33, 10.54
    { 1453, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x7b2f3d} }, // 825 OSM: 2788830 32.78, -96.8 x 32.81, -96.79
    { 1457, NoLogo, 209, LineMetaDataContent::RapidTransit, Color{0x015ca3} }, // S 7 OSM: 2791180 WD: Q63217583 51.45, 11.91 x 51.49, 12
    { 1462, NoLogo, 209, LineMetaDataContent::RapidTransit, Color{0xd7171f} }, // S 3 OSM: 2793231 WD: Q62749908 51.31, 11.96 x 51.52, 13.11
    { 57, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x687362} }, // 3 OSM: 2797182 52.5, 103.8 x 52.58, 103.9
    { 1466, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x149943} }, // STY OSM: 2797718 WD: Q7619599 -38.37, 145.1 x -38.14, 145.2
    { 1400, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x030f3f} }, // Metropolitana OSM: 2797904 WD: Q1725884 45.51, 10.21 x 45.58, 10.28
    { 63, 6863, NoLogo, LineMetaDataContent::Tramway, Color{0xce1f75} }, // 10 OSM: 2799185 WD: Q70711877 47.35, 8.507 x 47.45, 8.573
    { 15, 6888, NoLogo, LineMetaDataContent::Tramway, Color{0x92d6e3} }, // 12 OSM: 2799201 WD: Q70711314 47.4, 8.556 x 47.45, 8.608
    { 53, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x4c677a} }, // 1 OSM: 2801578 52.52, 103.9 x 52.56, 103.9
    { 40, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe5e6ea} }, // 7 OSM: 2802264 52.5, 103.8 x 52.53, 103.9
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x70492c} }, // 5 OSM: 2807017 WD: Q96483196 47.36, 8.516 x 47.38, 8.572
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xbe8543} }, // 6 OSM: 2807025 WD: Q96483372 47.36, 8.482 x 47.4, 8.572
    { 40, 6913, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 7 OSM: 2807030 WD: Q70712535 47.34, 8.53 x 47.41, 8.597
    { 123, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x322e71} }, // 9 OSM: 2807033 WD: Q70710278 47.37, 8.495 x 47.41, 8.592
    { 130, 6937, NoLogo, LineMetaDataContent::Tramway, Color{0x0093d0} }, // 14 OSM: 2807051 WD: Q70714895 47.37, 8.495 x 47.42, 8.55
    { 52, 6962, NoLogo, LineMetaDataContent::Tramway, Color{0x00923c} }, // 11 OSM: 2807068 WD: Q70714560 47.35, 8.533 x 47.42, 8.583
    { 57, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00923c} }, // 3 OSM: 2807070 WD: Q96483170 47.36, 8.485 x 47.38, 8.567
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x322e71} }, // 4 OSM: 2807089 WD: Q96483185 47.35, 8.49 x 47.39, 8.561
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xcb0a25} }, // 2 OSM: 2807095 WD: Q73249054 47.35, 8.444 x 47.4, 8.561
    { 134, 6987, NoLogo, LineMetaDataContent::Tramway, Color{0xcb0a25} }, // 15 OSM: 2807117 WD: Q70707977 47.37, 8.533 x 47.4, 8.548
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8bc036} }, // 8 OSM: 2807118 WD: Q96483377 47.36, 8.504 x 47.39, 8.567
    { 1470, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // 857 OSM: 2808958 33.19, -117.9 x 34.1, -117.3
    { 350, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // 859 OSM: 2808958 33.19, -117.9 x 34.1, -117.3
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf39100} }, // 5 OSM: 2810470 52.23, 10.48 x 52.26, 10.54
    { 1474, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff8000} }, // 662 OSM: 2812899 32.72, -118.2 x 34.06, -117.2
    { 1478, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff8000} }, // 666 OSM: 2812899 33.19, -118.2 x 34.06, -117.4
    { 1482, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff8000} }, // 660 OSM: 2812899 33.19, -118.2 x 34.06, -117.4
    { 1486, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff8000} }, // 664 OSM: 2812899 33.19, -118.2 x 34.06, -117.4
    { 1490, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x4782ff} }, // 710 OSM: 2812902 33.76, -118.2 x 34.06, -117.2
    { 1494, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x4782ff} }, // 752 OSM: 2812902 33.76, -118.2 x 34.06, -117.2
    { 1498, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x4782ff} }, // 754 OSM: 2812902 33.76, -118.2 x 34.06, -117.2
    { 1507, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x4782ff} }, // 708 OSM: 2812902 33.76, -118.2 x 34.06, -117.2
    { 1511, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x4782ff} }, // 704 OSM: 2812902 33.76, -118.2 x 34.06, -117.2
    { 1515, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x4782ff} }, // 706 OSM: 2812902 33.76, -118.2 x 34.06, -117.2
    { 26, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xa9c1d1} }, // 16 OSM: 2820891 50.06, 14.3 x 50.08, 14.53
    { 53, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0b0080} }, // 1 OSM: 2826218 WD: Q5017774 29.85, 31.23 x 30.16, 31.34
    { 9, NoLogo, 6442, LineMetaDataContent::Subway, Color{0x0054a6} }, // 4 OSM: 2827680 WD: Q15731046 59.87, 10.71 x 59.97, 10.93
    { 278, NoLogo, 7012, LineMetaDataContent::Subway, Color{0xffe800} }, // Yellow OSM: 2827683 WD: Q54874971 37.6, -122.5 x 38.02, -121.9
    { 1520, NoLogo, 2710, LineMetaDataContent::RapidTransit, Color{0xf166a7} }, // 40 OSM: 2836163 WD: Q106806725 59.17, 17.63 x 59.86, 18.07
    { 57, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x006531} }, // 3 OSM: 2837394 52.24, 10.47 x 52.29, 10.58
    { 53, 7026, NoLogo, LineMetaDataContent::Subway, Color{0xe60039} }, // 1 OSM: 2843401 WD: Q6850056 28.68, 115.8 x 28.75, 116
    { 566, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xbed639} }, // 82 OSM: 2844184 WD: Q6811974 -37.8, 144.9 x -37.77, 144.9
    { 40, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x800080} }, // 7 OSM: 2845552 37.33, -122 x 37.96, -121.3
    { 53, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x800080} }, // 1 OSM: 2845552 37.33, -122 x 37.96, -121.3
    { 6, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x800080} }, // 5 OSM: 2845552 37.33, -122 x 37.96, -121.3
    { 57, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x800080} }, // 3 OSM: 2845552 37.33, -122 x 37.96, -121.3
    { 285, NoLogo, 7012, LineMetaDataContent::Subway, Color{0xed1c24} }, // Red OSM: 2851513 WD: Q3809179 37.6, -122.5 x 37.94, -122.3
    { 1313, NoLogo, 7012, LineMetaDataContent::Subway, Color{0xfaa61a} }, // Orange OSM: 2851514 WD: Q3866809 37.36, -122.4 x 37.94, -121.9
    { 463, NoLogo, 7012, LineMetaDataContent::Subway, Color{0x4db848} }, // Green OSM: 2851729 WD: Q3720557 37.36, -122.5 x 37.81, -121.9
    { 273, NoLogo, 7012, LineMetaDataContent::Subway, Color{0x00aeef} }, // Blue OSM: 2851730 WD: Q3720569 37.69, -122.5 x 37.81, -121.9
    { 52, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x86c5a2} }, // 11 OSM: 2858845 WD: Q18165625 -37.82, 144.9 x -37.73, 145
    { 40, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x878a83} }, // 7 OSM: 2860817 59.32, 18.06 x 59.33, 18.11
    { 767, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00907a} }, // S31 OSM: 2872363 48.44, 8.215 x 49.18, 8.785
    { 1523, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00907a} }, // S32 OSM: 2872364 48.99, 8.402 x 49.16, 8.775
    { 261, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf49694} }, // S51 OSM: 2872365 48.89, 8.262 x 49.23, 8.703
    { 1527, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf49694} }, // S52 OSM: 2872366 48.98, 8.262 x 49.23, 8.433
    { 107, 7052, 944, LineMetaDataContent::Subway, Color{0x2ec6ff} }, // U4 OSM: 2872790 WD: Q209739 53.53, 9.983 x 53.56, 10.11
    { 52, 7067, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff7f50} }, // 11 OSM: 2875658 WD: Q5245830 -23.56, -46.64 x -23.52, -46.19
    { 15, 7079, NoLogo, LineMetaDataContent::RapidTransit, Color{0x1c146b} }, // 12 OSM: 2877633 WD: Q5245789 -23.55, -46.62 x -23.48, -46.33
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8c6e66} }, // 6 OSM: 2877971 52.5, 103.8 x 52.56, 103.9
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xec7394} }, // 4 OSM: 2877979 52.5, 103.8 x 52.53, 103.9
    { 40, 7091, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa8034f} }, // 7 OSM: 2885794 WD: Q3296728 -23.55, -46.87 x -23.19, -46.62
    { 53, NoLogo, 6442, LineMetaDataContent::Subway, Color{0x00b6f1} }, // 1 OSM: 2890637 WD: Q15731038 59.87, 10.65 x 59.98, 10.82
    { 63, 7102, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00ced1} }, // 10 OSM: 2893113 WD: Q5245819 -23.74, -46.62 x -23.54, -46.39
    { 190, 7114, 3966, LineMetaDataContent::Subway, Color{0xffa500} }, // B OSM: 2896644 WD: Q18420098 6.247, -75.61 x 6.259, -75.57
    { 211, NoLogo, 209, LineMetaDataContent::RapidTransit, Color{0xffff00} }, // S 1 OSM: 2920398 WD: Q56600177 51.31, 12.27 x 51.37, 12.41
    { 138, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf7942a} }, // 19 OSM: 2921482 59.85, 10.72 x 59.93, 10.8
    { 22, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfdb927} }, // 18 OSM: 2921905 59.91, 10.71 x 59.95, 10.78
    { 221, 7153, NoLogo, LineMetaDataContent::Subway, Color{0x003ea1} }, // C OSM: 2931139 WD: Q1157050 -34.63, -58.38 x -34.59, -58.37
    { 190, 7181, NoLogo, LineMetaDataContent::Subway, Color{0xc20924} }, // B OSM: 2933167 WD: Q1157061 -34.6, -58.49 x -34.57, -58.37
    { 37, 7209, NoLogo, LineMetaDataContent::Subway, Color{0x6b297e} }, // E OSM: 2933872 WD: Q1044919 -34.64, -58.46 x -34.59, -58.37
    { 1093, 7237, NoLogo, LineMetaDataContent::Subway, Color{0x217861} }, // D OSM: 2934099 WD: Q1157052 -34.61, -58.46 x -34.56, -58.37
    { 388, 7265, NoLogo, LineMetaDataContent::Subway, Color{0xf4cc21} }, // H OSM: 2934107 WD: Q1132660 -34.64, -58.41 x -34.58, -58.39
    { 344, NoLogo, 6360, LineMetaDataContent::Subway, Color{0x003399} }, // M2 OSM: 2947130 WD: Q1884455 44.36, 26.09 x 44.48, 26.15
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf9b000} }, // 4 OSM: 2951397 WD: Q63350784 52.37, 9.596 x 52.42, 9.819
    { 200, 7293, 7328, LineMetaDataContent::Tramway, Color{0x281570} }, // T1 OSM: 2962731 WD: Q26273325 41, 28.86 x 41.03, 28.99
    { 1002, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x6f1b14} }, // 94 OSM: 2982672 51.48, 11.93 x 51.51, 11.97
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf9b000} }, // 6 OSM: 2991603 WD: Q63350805 52.32, 9.69 x 52.42, 9.837
    { 52, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf9b000} }, // 11 OSM: 2991649 WD: Q63350814 52.37, 9.713 x 52.39, 9.775
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf9b000} }, // 5 OSM: 2991701 WD: Q63350794 52.36, 9.659 x 52.41, 9.859
    { 53, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe4003a} }, // 1 OSM: 2995652 WD: Q63344401 52.24, 9.731 x 52.44, 9.86
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe4003a} }, // 2 OSM: 2998555 WD: Q63345326 52.29, 9.734 x 52.42, 9.818
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe4003a} }, // 8 OSM: 2998722 WD: Q63345432 52.33, 9.734 x 52.4, 9.805
    { 169, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x76b82a} }, // 17 OSM: 2998733 WD: Q63348315 52.34, 9.718 x 52.38, 9.743
    { 63, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x76b82a} }, // 10 OSM: 3004809 WD: Q63348270 52.37, 9.664 x 52.39, 9.756
    { 1532, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x051541} }, // 95 OSM: 3006197 51.42, 11.96 x 51.52, 11.99
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xed1943} }, // 12 OSM: 3009639 WD: Q2189640 51.88, 4.471 x 51.92, 4.568
    { 57, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0069b4} }, // 3 OSM: 3016071 WD: Q63348707 52.33, 9.69 x 52.44, 9.848
    { 40, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0069b4} }, // 7 OSM: 3038575 WD: Q63348805 52.33, 9.69 x 52.41, 9.854
    { 123, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0069b4} }, // 9 OSM: 3038600 WD: Q63349759 52.34, 9.667 x 52.43, 9.802
    { 1535, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x9e75ad} }, // L21 OSM: 3061373 59.43, 10.61 x 59.92, 10.84
    { 1539, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0075a7} }, // L22 OSM: 3067038 59.43, 10.68 x 59.92, 11.34
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xffda01} }, // 2 OSM: 3067723 WD: Q6850047 28.55, 115.8 x 28.7, 116
    { 1543, NoLogo, 3539, LineMetaDataContent::RapidTransit, Color{0x236214} }, // UP-N OSM: 3117549 WD: Q7885883 41.88, -87.85 x 42.59, -87.64
    { 1548, NoLogo, 3539, LineMetaDataContent::RapidTransit, Color{0xff821d} }, // MD-N OSM: 3117594 WD: Q16982046 41.88, -88.18 x 42.4, -87.64
    { 1553, NoLogo, 3539, LineMetaDataContent::RapidTransit, Color{0x7c53af} }, // NCS OSM: 3117600 WD: Q7054760 41.88, -88.09 x 42.48, -87.64
    { 1557, NoLogo, 3539, LineMetaDataContent::RapidTransit, Color{0xfae218} }, // UP-NW OSM: 3117607 WD: Q16985937 41.88, -88.62 x 42.42, -87.64
    { 1563, NoLogo, 3539, LineMetaDataContent::RapidTransit, Color{0xfeb8fa} }, // UP-W OSM: 3117615 WD: Q7885886 41.86, -88.47 x 41.9, -87.64
    { 1568, NoLogo, 3539, LineMetaDataContent::RapidTransit, Color{0x77b337} }, // BNSF OSM: 3117619 WD: Q4836140 41.76, -88.31 x 41.88, -87.64
    { 1573, NoLogo, 3539, LineMetaDataContent::RapidTransit, Color{0xee4848} }, // HC OSM: 3117625 WD: Q5738778 41.52, -88.08 x 41.88, -87.64
    { 1576, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa81818} }, // RI OSM: 3117651 41.51, -88.08 x 41.88, -87.63
    { 1579, NoLogo, 3539, LineMetaDataContent::RapidTransit, Color{0x117bac} }, // SWS OSM: 3117664 WD: Q7565331 41.42, -87.99 x 41.88, -87.64
    { 1583, NoLogo, 3539, LineMetaDataContent::RapidTransit, Color{0xf67b7b} }, // ME OSM: 3117670 WD: Q4501968 41.46, -87.72 x 41.89, -87.55
    { 1587, NoLogo, 209, LineMetaDataContent::RapidTransit, Color{0x00ffff} }, // S 2 OSM: 3119892 WD: Q56809294 51.31, 12.23 x 51.87, 12.66
    { 1591, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe37c26} }, // L13 OSM: 3123398 59.74, 10.2 x 60.25, 11.2
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xafe0ee} }, // 8 OSM: 3144745 WD: Q56302773 46.94, 7.374 x 46.95, 7.487
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x088742} }, // 2 OSM: 3152801 51.13, 14.94 x 51.17, 14.99
    { 53, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff2e17} }, // 1 OSM: 3152809 51.12, 14.97 x 51.17, 14.99
    { 1595, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa11c20} }, // LBN OSM: 3155062 -34.59, -58.87 x -34.42, -58.37
    { 265, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // FM1 OSM: 3158700 41.12, 16.78 x 41.14, 16.87
    { 39, 7363, 209, LineMetaDataContent::RapidTransit, Color{0xa5ce43} }, // S7 OSM: 3168072 WD: Q63433461 52.37, 9.739 x 52.62, 10.06
    { 226, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xca305b} }, // A OSM: 3190626 WD: Q3537211 47.34, 0.6578 x 47.42, 0.7119
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00b26b} }, // 13 OSM: 3201250 59.85, 10.59 x 59.93, 10.8
    { 1599, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x88be5f} }, // 1707 OSM: 3207386 47.6, -122.4 x 47.98, -122.2
    { 52, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x82c341} }, // 11 OSM: 3218724 59.91, 10.72 x 59.96, 10.79
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xa166aa} }, // 12 OSM: 3221100 59.91, 10.7 x 59.96, 10.79
    { 9, NoLogo, 7379, LineMetaDataContent::Subway, Color{0xf1ce00} }, // 4 OSM: 3228501 WD: Q1597847 45.51, -73.56 x 45.52, -73.52
    { 16, NoLogo, 7379, LineMetaDataContent::Subway, Color{0xd06d07} }, // 2 OSM: 3228502 WD: Q967397 45.47, -73.72 x 45.56, -73.55
    { 6, NoLogo, 7379, LineMetaDataContent::Subway, Color{0x3465b4} }, // 5 OSM: 3228503 WD: Q1726049 45.49, -73.63 x 45.56, -73.6
    { 53, 7398, 7379, LineMetaDataContent::Subway, Color{0x5f8c55} }, // 1 OSM: 3228504 WD: Q1925762 45.45, -73.6 x 45.6, -73.53
    { 1604, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa90056} }, // Midland OSM: 3228561 WD: Q6842474 -31.95, 115.9 x -31.89, 116
    { 16, 7412, NoLogo, LineMetaDataContent::Subway, Color{0x00629b} }, // 2 OSM: 3244073 WD: Q1047377 22.99, 113.3 x 23.24, 113.3
    { 101, 7432, 452, LineMetaDataContent::Subway, Color{0xa762a4} }, // U2 OSM: 3245522 WD: Q873397 48.21, 16.36 x 48.23, 16.51
    { 57, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xd9001c} }, // 3 OSM: 3252762 WD: Q3294315 -23.55, -46.67 x -23.53, -46.47
    { 169, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xef4123} }, // 17 OSM: 3259480 59.91, 10.71 x 59.95, 10.78
    { 98, 7444, 452, LineMetaDataContent::Subway, Color{0xe20613} }, // U1 OSM: 3278144 WD: Q663755 48.14, 16.37 x 48.28, 16.45
    { 226, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xef3f30} }, // A OSM: 3309751 WD: Q3239051 47.44, -0.5972 x 47.51, -0.5454
    { 26, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xaf1867} }, // 16 OSM: 3315633 51.43, 11.9 x 51.48, 11.99
    { 9, 7456, 6316, LineMetaDataContent::Subway, Color{0xbb4d98} }, // 4 OSM: 3326845 WD: Q50743 48.82, 2.318 x 48.9, 2.359
    { 130, 7474, 6316, LineMetaDataContent::Subway, Color{0x67328e} }, // 14 OSM: 3328694 WD: Q50761 48.83, 2.31 x 48.92, 2.387
    { 53, 7493, 6316, LineMetaDataContent::Subway, Color{0xf2c931} }, // 1 OSM: 3328695 WD: Q13224 48.84, 2.23 x 48.89, 2.441
    { 123, 7511, 6316, LineMetaDataContent::Subway, Color{0xcdc83f} }, // 9 OSM: 3328717 WD: Q50753 48.83, 2.231 x 48.87, 2.442
    { 107, 7529, 7545, LineMetaDataContent::Subway, Color{0x10b48d} }, // U4 OSM: 3328726 WD: Q20439761 48.13, 11.52 x 48.15, 11.62
    { 63, 7569, 6316, LineMetaDataContent::Subway, Color{0xdfb039} }, // 10 OSM: 3328741 WD: Q50754 48.84, 2.229 x 48.85, 2.365
    { 27, 7588, 6316, LineMetaDataContent::Subway, Color{0x75c695} }, // 6 OSM: 3328765 WD: Q50746 48.83, 2.285 x 48.87, 2.402
    { 40, 7606, 6316, LineMetaDataContent::Subway, Color{0xfa9aba} }, // 7 OSM: 3328805 WD: Q50748 48.79, 2.332 x 48.92, 2.411
    { 2, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xbb0022} }, // 0 OSM: 3348003 WD: Q1510414 51.08, 2.581 x 51.34, 3.285
    { 53, 7624, NoLogo, LineMetaDataContent::Tramway, Color{0xe3000f} }, // 1 OSM: 3367545 WD: Q78199222 48.34, 10.87 x 48.38, 10.94
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x951881} }, // 4 OSM: 3367554 48.37, 10.88 x 48.4, 10.89
    { 1586, 7644, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff9e00} }, // RS 2 OSM: 3372285 WD: Q84703704 52.79, 8.597 x 53.57, 8.895
    { 210, 7659, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ee} }, // RS 1 OSM: 3372313 WD: Q84703702 52.92, 8.516 x 53.21, 9.238
    { 1612, NoLogo, 209, LineMetaDataContent::RapidTransit, Color{0xfdd456} }, // S 5X OSM: 3382470 WD: Q63216058 50.7, 11.99 x 51.48, 12.48
    { 1355, 7674, 5415, LineMetaDataContent::Tramway, Color{0xe3ba12} }, // 44 OSM: 3394367 WD: Q1931983 50.82, 4.409 x 50.84, 4.514
    { 1270, 7696, 5415, LineMetaDataContent::Tramway, Color{0xde3b21} }, // 39 OSM: 3394368 WD: Q2719066 50.83, 4.409 x 50.85, 4.504
    { 63, 7718, 7739, LineMetaDataContent::Subway, Color{0xeac384} }, // 10 OSM: 3400216 WD: Q6553053 31.98, 118.6 x 32.07, 118.8
    { 53, 7762, 7739, LineMetaDataContent::Subway, Color{0x00a2df} }, // 1 OSM: 3400217 WD: Q6127241 31.9, 118.8 x 32.1, 118.9
    { 16, 7782, 7739, LineMetaDataContent::Subway, Color{0xc7003f} }, // 2 OSM: 3413089 WD: Q5960302 31.97, 118.7 x 32.12, 119
    { 1617, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // Metrotranvía OSM: 3413332 -32.96, -68.85 x -32.84, -68.78
    { 59, 7802, 209, LineMetaDataContent::RapidTransit, Color{0x0095da} }, // S1 OSM: 3413905 WD: Q600891 49.97, 8.244 x 50.11, 8.885
    { 48, 7819, 209, LineMetaDataContent::RapidTransit, Color{0xee1c23} }, // S2 OSM: 3414422 WD: Q1985592 50.01, 8.31 x 50.16, 8.813
    { 45, 7836, 209, LineMetaDataContent::RapidTransit, Color{0xd7df23} }, // S8 OSM: 3415070 WD: Q2005458 49.98, 8.242 x 50.13, 8.931
    { 460, 7853, 209, LineMetaDataContent::RapidTransit, Color{0x91268f} }, // S9 OSM: 3415113 WD: Q508402 49.98, 8.244 x 50.13, 8.931
    { 432, 7870, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfab700} }, // C-5 OSM: 3418151 WD: Q3832677 40.25, -3.883 x 40.41, -3.677
    { 15, 7885, NoLogo, LineMetaDataContent::Tramway, Color{0xbb0022} }, // 12 OSM: 3419132 WD: Q2200976 51.22, 4.42 x 51.23, 4.444
    { 123, 7908, NoLogo, LineMetaDataContent::Tramway, Color{0xee8822} }, // 9 OSM: 3419133 WD: Q1891687 51.2, 4.361 x 51.22, 4.464
    { 181, 7930, NoLogo, LineMetaDataContent::Tramway, Color{0xff88aa} }, // 24 OSM: 3419134 WD: Q2483765 51.2, 4.408 x 51.24, 4.484
    { 57, 7953, NoLogo, LineMetaDataContent::Tramway, Color{0xffcc11} }, // 3 OSM: 3419435 WD: Q3238908 51.22, 4.305 x 51.26, 4.464
    { 9, 7975, NoLogo, LineMetaDataContent::Tramway, Color{0x1199dd} }, // 4 OSM: 3419473 WD: Q2344285 51.17, 4.35 x 51.22, 4.484
    { 6, 7997, NoLogo, LineMetaDataContent::Tramway, Color{0x771133} }, // 5 OSM: 3419525 WD: Q2147524 51.22, 4.361 x 51.23, 4.512
    { 27, 8019, NoLogo, LineMetaDataContent::Tramway, Color{0xdd0077} }, // 6 OSM: 3419912 WD: Q2128494 51.18, 4.391 x 51.26, 4.443
    { 40, 8041, NoLogo, LineMetaDataContent::Tramway, Color{0x0044bb} }, // 7 OSM: 3420306 WD: Q2413292 51.17, 4.4 x 51.23, 4.449
    { 52, 8063, NoLogo, LineMetaDataContent::Tramway, Color{0xffccff} }, // 11 OSM: 3420543 WD: Q2500256 51.2, 4.402 x 51.22, 4.439
    { 63, 8086, NoLogo, LineMetaDataContent::Tramway, Color{0xbbdd00} }, // 10 OSM: 3420544 WD: Q1962342 51.17, 4.362 x 51.23, 4.512
    { 134, 8108, NoLogo, LineMetaDataContent::Tramway, Color{0xffffff} }, // 15 OSM: 3420997 WD: Q959739 51.17, 4.361 x 51.22, 4.494
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 8 OSM: 3428481 47.05, 21.9 x 47.08, 21.93
    { 53, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf5d200} }, // 1 OSM: 3430333 49.72, 13.37 x 49.78, 13.4
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf5d200} }, // 2 OSM: 3430559 49.73, 13.32 x 49.75, 13.41
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf5d200} }, // 4 OSM: 3430578 49.73, 13.36 x 49.78, 13.38
    { 1632, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x913108} }, // PM OSM: 3433159 37.78, -122.4 x 37.81, -122.4
    { 387, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x913108} }, // PH OSM: 3433160 37.78, -122.4 x 37.81, -122.4
    { 438, 8131, NoLogo, LineMetaDataContent::RapidTransit, Color{0x92278f} }, // L OSM: 3435879 WD: Q16981005 37.74, -122.5 x 37.79, -122.4
    { 310, 8150, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008752} }, // M OSM: 3435882 WD: Q6720518 37.71, -122.5 x 37.79, -122.4
    { 491, 8172, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00539b} }, // N OSM: 3435884 WD: Q6956302 37.76, -122.5 x 37.79, -122.4
    { 138, 8189, 5415, LineMetaDataContent::Tramway, Color{0xde3b21} }, // 19 OSM: 3437796 WD: Q2702907 50.86, 4.275 x 50.9, 4.357
    { 1635, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0066cc} }, // LBS OSM: 3443504 -34.79, -58.83 x -34.65, -58.42
    { 110, 8211, 7545, LineMetaDataContent::Subway, Color{0xb77510} }, // U5 OSM: 3475206 WD: Q3832790 48.09, 11.5 x 48.14, 11.65
    { 113, 8227, 7545, LineMetaDataContent::Subway, Color{0x0071bb} }, // U6 OSM: 3477966 WD: Q751039 48.11, 11.47 x 48.27, 11.67
    { 104, 8243, 7545, LineMetaDataContent::Subway, Color{0xf36f33} }, // U3 OSM: 3484056 WD: Q20439760 48.09, 11.48 x 48.19, 11.59
    { 1639, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x5fb04f} }, // 1510 OSM: 3494093 WD: Q56525586 47.15, -122.5 x 47.6, -122.2
    { 1644, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x5fb04f} }, // 1500 OSM: 3494093 WD: Q56525586 47.15, -122.5 x 47.6, -122.2
    { 1649, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x5fb04f} }, // 1502 OSM: 3494093 WD: Q56525586 47.15, -122.5 x 47.6, -122.2
    { 1654, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x5fb04f} }, // 1504 OSM: 3494093 WD: Q56525586 47.15, -122.5 x 47.6, -122.2
    { 1659, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x5fb04f} }, // 1512 OSM: 3494093 WD: Q56525586 47.15, -122.5 x 47.6, -122.2
    { 1664, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x5fb04f} }, // 1508 OSM: 3494093 WD: Q56525586 47.15, -122.5 x 47.6, -122.2
    { 1672, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffa500} }, // T OSM: 3494094 WD: Q1999971 47.24, -122.4 x 47.26, -122.4
    { 376, 8259, NoLogo, LineMetaDataContent::Subway, Color{0x000000} }, // L2 OSM: 3517295 WD: Q3011583 43.24, -3.042 x 43.33, -2.881
    { 113, 8282, 944, LineMetaDataContent::Subway, Color{0x007ec6} }, // U6 OSM: 3524791 WD: Q19863008 50.11, 8.624 x 50.14, 8.708
    { 196, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x66c87f} }, // S6 OSM: 3529247 46.92, 8.814 x 47.23, 9.084
    { 98, 8299, 7545, LineMetaDataContent::Subway, Color{0x448137} }, // U1 OSM: 3531712 WD: Q20439756 48.1, 11.53 x 48.18, 11.58
    { 101, 8315, 7545, LineMetaDataContent::Subway, Color{0xc40f39} }, // U2 OSM: 3531713 WD: Q830301 48.11, 11.54 x 48.21, 11.7
    { 116, 8331, 7545, LineMetaDataContent::Subway, Color{0x468037} }, // U7 OSM: 3531714 WD: Q20439774 48.1, 11.53 x 48.18, 11.65
    { 119, 8347, 7545, LineMetaDataContent::Subway, Color{0xff6a2f} }, // U8 OSM: 3531715 WD: Q20439777 48.1, 11.56 x 48.18, 11.65
    { 59, NoLogo, 209, LineMetaDataContent::RapidTransit, Color{0x40b93c} }, // S1 OSM: 3533698 WD: Q106453739 47.4, 9.039 x 47.46, 9.371
    { 48, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x4763b8} }, // S2 OSM: 3537054 47.23, 9.078 x 47.48, 9.651
    { 6, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x9200c3} }, // 5 OSM: 3539820 WD: Q3308465 -23.66, -46.77 x -23.59, -46.63
    { 226, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe3000b} }, // A OSM: 3555528 WD: Q107044417 49.49, 0.09576 x 49.53, 0.137
    { 190, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00963e} }, // B OSM: 3555531 WD: Q107044421 49.49, 0.09576 x 49.52, 0.1801
    { 1674, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x50b948} }, // U BRA OSM: 3579399 41.14, -8.61 x 41.55, -8.434
    { 502, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffdd00} }, // T2 OSM: 3589646 WD: Q3239232 45.44, 4.384 x 45.45, 4.403
    { 1680, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xafcb07} }, // T3 OSM: 3589647 WD: Q3239231 45.42, 4.378 x 45.47, 4.405
    { 53, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x1a5ba3} }, // 1 OSM: 3596996 WD: Q3362568 -23.65, -46.64 x -23.48, -46.6
    { 344, 8363, 2208, LineMetaDataContent::Subway, Color{0x0000ff} }, // M2 OSM: 3598362 WD: Q2204296 50.37, 30.45 x 50.52, 30.53
    { 9, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xffd700} }, // 4 OSM: 3613482 WD: Q3308457 -23.59, -46.72 x -23.54, -46.63
    { 285, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xcd5c5c} }, // Red OSM: 3616739 WD: Q2472181 53.28, -6.438 x 53.35, -6.229
    { 57, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00bb00} }, // 3 OSM: 3618379 WD: Q107187377 58.58, 16.13 x 58.61, 16.19
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xcc0000} }, // 2 OSM: 3618409 WD: Q107187376 58.55, 16.13 x 58.61, 16.23
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x008000} }, // 2 OSM: 3619672 WD: Q588499 -23.6, -46.69 x -23.55, -46.58
    { 1683, 8385, 4327, LineMetaDataContent::Tramway, Color{0x009641} }, // T3b OSM: 3662457 WD: Q3136247 48.85, 2.301 x 48.9, 2.411
    { 200, 8419, 6525, LineMetaDataContent::Tramway, Color{0x873f98} }, // T1 OSM: 3667340 WD: Q2903 45.73, 4.817 x 45.79, 4.884
    { 1687, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xb80e28} }, // Rhônexpress OSM: 3667553 45.72, 4.862 x 45.78, 5.077
    { 502, 8439, 6525, LineMetaDataContent::Tramway, Color{0x873f98} }, // T2 OSM: 3667554 WD: Q2906 45.69, 4.819 x 45.75, 4.956
    { 1680, 8459, 6525, LineMetaDataContent::Tramway, Color{0x873f98} }, // T3 OSM: 3667555 WD: Q2911 45.75, 4.862 x 45.78, 5.035
    { 1700, 8479, 6525, LineMetaDataContent::Tramway, Color{0x873f98} }, // T4 OSM: 3667556 WD: Q2918 45.69, 4.858 x 45.78, 4.888
    { 190, 8499, 8520, LineMetaDataContent::Subway, Color{0x007dc5} }, // B OSM: 3687323 WD: Q2965 45.72, 4.81 x 45.77, 4.864
    { 1093, 8549, 8520, LineMetaDataContent::Subway, Color{0x00ac4d} }, // D OSM: 3687324 WD: Q2976 45.7, 4.803 x 45.78, 4.89
    { 221, 8570, 8520, LineMetaDataContent::Subway, Color{0xf99d1d} }, // C OSM: 3687325 WD: Q2969 45.77, 4.827 x 45.79, 4.836
    { 226, 8591, 8520, LineMetaDataContent::Subway, Color{0xee3898} }, // A OSM: 3687326 WD: Q2944 45.75, 4.826 x 45.77, 4.922
    { 1703, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0066cc} }, // LGR7 OSM: 3737973 -34.98, -58.4 x -34.63, -58.37
    { 1708, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0066cc} }, // LGR6 OSM: 3737975 -34.85, -58.52 x -34.63, -58.38
    { 1713, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0066cc} }, // LGR5 OSM: 3738002 -34.9, -58.38 x -34.63, -57.95
    { 104, 8612, 452, LineMetaDataContent::Subway, Color{0xef7c00} }, // U3 OSM: 3752340 WD: Q876472 48.17, 16.31 x 48.21, 16.42
    { 87, 8624, 5415, LineMetaDataContent::Tramway, Color{0xff9ec2} }, // 62 OSM: 3775501 WD: Q2544169 50.86, 4.332 x 50.88, 4.435
    { 1718, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // Line 3 OSM: 3788350 WD: Q341464 29.25, 47.97 x 29.26, 47.97
    { 380, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7daf42} }, // L3 OSM: 3793874 59.91, 10.55 x 60.39, 10.87
    { 414, NoLogo, 169, LineMetaDataContent::Tramway, Color{0xffd800} }, // 48 OSM: 3820771 WD: Q15982247 47.44, 19.03 x 47.5, 19.06
    { 57, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 3 OSM: 3822945 55.16, 30.21 x 55.2, 30.24
    { 40, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 7 OSM: 3823035 55.16, 30.12 x 55.2, 30.27
    { 53, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 1 OSM: 3823370 55.16, 30.12 x 55.2, 30.23
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 2 OSM: 3823520 55.16, 30.12 x 55.19, 30.24
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 6 OSM: 3824263 55.16, 30.12 x 55.2, 30.19
    { 123, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 9 OSM: 3824285 55.16, 30.12 x 55.2, 30.2
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 8 OSM: 3824316 55.16, 30.14 x 55.2, 30.24
    { 1084, 8646, 19, LineMetaDataContent::Tramway, Color{0xfaa61a} }, // 28 OSM: 3858971 WD: Q20439076 48.13, 11.56 x 48.17, 11.58
    { 1412, 8667, 8697, LineMetaDataContent::Subway, Color{0xed1c24} }, // a OSM: 3889841 WD: Q24641190 48.09, -1.711 x 48.12, -1.644
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008995} }, // 12 OSM: 3903646 WD: Q18165631 -37.86, 145 x -37.81, 145
    { 1725, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00a1de} }, // West Hempstead OSM: 3917588 WD: Q7985342 40.66, -73.97 x 40.71, -73.64
    { 221, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe4007c} }, // C OSM: 3921484 WD: Q3239086 45.17, 5.69 x 45.19, 5.776
    { 37, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x58318a} }, // E OSM: 3921488 WD: Q3239103 45.17, 5.661 x 45.26, 5.72
    { 190, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009b3a} }, // B OSM: 3921491 WD: Q3239068 45.18, 5.698 x 45.21, 5.787
    { 226, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0076bd} }, // A OSM: 3921492 WD: Q3239056 45.14, 5.618 x 45.27, 5.734
    { 1093, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf39a00} }, // D OSM: 3921494 WD: Q3239096 45.17, 5.754 x 45.19, 5.759
    { 266, 8719, 2240, LineMetaDataContent::Subway, Color{0x007d58} }, // M1 OSM: 3931373 WD: Q1880894 55.62, 12.49 x 55.69, 12.59
    { 53, 8731, NoLogo, LineMetaDataContent::Subway, Color{0xf3d03e} }, // 1 OSM: 3936877 WD: Q1047385 23.07, 113.2 x 23.15, 113.3
    { 196, 8751, 209, LineMetaDataContent::RapidTransit, Color{} }, // S6 OSM: 3937942 WD: Q680235 47.25, 11.1 x 47.49, 11.4
    { 1741, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x233e81} }, // TL OSM: 3939642 WD: Q2576140 19.26, -99.15 x 19.34, -99.11
    { 6, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xc5003e} }, // 5 OSM: 3967180 WD: Q862888 23.1, 113.2 x 23.15, 113.5
    { 1744, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xef87b6} }, // HBB OSM: 3988307 47.27, 11.4 x 47.29, 11.4
    { 39, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf07f3a} }, // S7 OSM: 4006931 46.93, 7.438 x 46.98, 7.563
    { 1748, 8770, 4327, LineMetaDataContent::Tramway, Color{0xb1a245} }, // T8 OSM: 4007734 WD: Q3239029 48.93, 2.294 x 48.96, 2.358
    { 255, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x66ba86} }, // 23 OSM: 4016993 WD: Q2914455 51.88, 4.432 x 51.92, 4.574
    { 273, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0000ff} }, // Blue OSM: 4086917 WD: Q152015 42.36, -71.06 x 42.41, -70.99
    { 57, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x99b3be} }, // 3 OSM: 4089342 WD: Q56302770 46.94, 7.431 x 46.95, 7.441
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0089cf} }, // 6 OSM: 4089819 WD: Q56302772 46.93, 7.419 x 46.95, 7.563
    { 1752, 8803, 5415, LineMetaDataContent::Tramway, Color{0x991f36} }, // 97 OSM: 4092822 WD: Q1865502 50.8, 4.313 x 50.84, 4.357
    { 9, 8825, NoLogo, LineMetaDataContent::Tramway, Color{0x4a2a15} }, // 4 OSM: 4107687 WD: Q3238942 43.59, 3.872 x 43.62, 3.897
    { 52, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xee1d23} }, // 11 OSM: 4108299 WD: Q3239102 47.47, 7.573 x 47.58, 7.612
    { 1755, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // 100 OSM: 4117854 WD: Q3537097 39.1, -84.52 x 39.12, -84.51
    { 347, 8845, 3291, LineMetaDataContent::Subway, Color{0x0a0e65} }, // M3 OSM: 4121437 WD: Q692916 47.46, 19.05 x 47.56, 19.15
    { 8, 8861, 3291, LineMetaDataContent::Subway, Color{0x007b1c} }, // M4 OSM: 4121438 WD: Q832651 47.46, 19.02 x 47.5, 19.08
    { 344, 8877, 3291, LineMetaDataContent::Subway, Color{0xd50a0e} }, // M2 OSM: 4121439 WD: Q1071156 47.49, 19.02 x 47.51, 19.14
    { 57, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0079c3} }, // 3 OSM: 4129878 WD: Q10908095 28.51, 115.9 x 28.71, 116
    { 9, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x00a560} }, // 4 OSM: 4129938 28.6, 115.7 x 28.72, 116
    { 6, 4615, NoLogo, LineMetaDataContent::Tramway, Color{} }, // 5 OSM: 4152663 WD: Q63890965 50.48, 30.57 x 50.53, 30.63
    { 40, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xee1d23} }, // 7 OSM: 4152763 WD: Q56302771 46.94, 7.38 x 46.95, 7.472
    { 221, 8893, 3117, LineMetaDataContent::Subway, Color{0x008752} }, // C OSM: 4173958 WD: Q2261550 41.86, 12.51 x 41.89, 12.71
    { 53, 8934, NoLogo, LineMetaDataContent::Tramway, Color{} }, // 1 OSM: 4222397 WD: Q108215311 50.96, 10.99 x 51.01, 11.04
    { 16, 8960, NoLogo, LineMetaDataContent::Tramway, Color{} }, // 2 OSM: 4222399 WD: Q108215316 50.96, 10.98 x 51, 11.07
    { 57, 8986, NoLogo, LineMetaDataContent::Tramway, Color{} }, // 3 OSM: 4222400 WD: Q108215641 50.94, 10.99 x 51.01, 11.09
    { 9, 9012, NoLogo, LineMetaDataContent::Tramway, Color{} }, // 4 OSM: 4222401 WD: Q108215690 50.95, 10.96 x 50.98, 11.07
    { 6, 9038, NoLogo, LineMetaDataContent::Tramway, Color{} }, // 5 OSM: 4222402 WD: Q108215699 50.97, 11.02 x 51.02, 11.04
    { 27, 9064, NoLogo, LineMetaDataContent::Tramway, Color{} }, // 6 OSM: 4222403 WD: Q108215015 50.96, 11 x 51.01, 11.04
    { 344, 9090, 2826, LineMetaDataContent::Subway, Color{0xff0000} }, // M2 OSM: 4232535 WD: Q3832673 52.23, 20.94 x 52.28, 21.06
    { 53, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff7f00} }, // 1 OSM: 4234654 51.8, 12.24 x 51.84, 12.24
    { 1360, 9102, 3410, LineMetaDataContent::Subway, Color{0xffa500} }, // O OSM: 4250359 WD: Q6141590 24.99, 121.4 x 25.1, 121.5
    { 487, 9126, 3410, LineMetaDataContent::Subway, Color{0xcedc00} }, // G OSM: 4250382 WD: Q8044250 24.96, 121.5 x 25.05, 121.6
    { 1759, 9165, 3410, LineMetaDataContent::Subway, Color{0xa74c00} }, // BR OSM: 4264893 WD: Q707644 25, 121.5 x 25.09, 121.6
    { 1762, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x8b231d} }, // SFM 6 OSM: 4277114 WD: Q15077697 44.88, 7.655 x 45.12, 8.209
    { 42, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf49694} }, // S5 OSM: 4292646 48.89, 8.243 x 49.06, 8.705
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x028f34} }, // 2 OSM: 4292976 WD: Q2333639 -22.95, -43.37 x -22.81, -43.17
    { 53, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xbb0022} }, // 1 OSM: 4307991 WD: Q972127 51.02, 3.692 x 51.11, 3.75
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x229922} }, // 4 OSM: 4307994 WD: Q1984797 51.02, 3.709 x 51.07, 3.751
    { 1768, NoLogo, 209, LineMetaDataContent::RapidTransit, Color{0x00a6eb} }, // S19 OSM: 4434302 WD: Q30597732 50.76, 6.482 x 50.95, 7.66
    { 261, 9190, 209, LineMetaDataContent::RapidTransit, Color{0xf78a18} }, // S51 OSM: 4435864 WD: Q63433457 52.1, 9.374 x 52.4, 9.773
    { 1772, 9207, 209, LineMetaDataContent::RapidTransit, Color{0x118349} }, // S21 OSM: 4435868 WD: Q63433451 52.28, 9.466 x 52.38, 9.773
    { 285, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xcc0000} }, // Red OSM: 4439533 WD: Q7304502 33.64, -84.45 x 33.95, -84.34
    { 1776, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xf67705} }, // Gold OSM: 4439534 WD: Q5578774 33.64, -84.45 x 33.9, -84.28
    { 463, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x009544} }, // Green OSM: 4439535 WD: Q5602819 33.75, -84.43 x 33.78, -84.28
    { 273, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0274ba} }, // Blue OSM: 4439536 WD: Q4929368 33.75, -84.47 x 33.78, -84.23
    { 63, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x114283} }, // 10 OSM: 4443860 54.27, 48.29 x 54.32, 48.39
    { 207, 9224, 209, LineMetaDataContent::RapidTransit, Color{0x903f98} }, // S4 OSM: 4452991 WD: Q459508 47.62, 12.87 x 47.84, 13
    { 45, 9244, 209, LineMetaDataContent::RapidTransit, Color{0x8ec7e8} }, // S8 OSM: 4470844 WD: Q63433462 52.32, 9.687 x 52.46, 9.792
    { 1781, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7b388c} }, // Providence/Stoughton Line OSM: 4473913 WD: Q7252371 41.58, -71.49 x 42.35, -71.05
    { 1807, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7b388c} }, // Franklin Line OSM: 4476404 WD: Q5491659 42.08, -71.44 x 42.35, -71.05
    { 130, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x5a1e82} }, // 14 OSM: 4489019 WD: Q3238565 46.17, 6.06 x 46.24, 6.144
    { 22, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xb82f89} }, // 18 OSM: 4489020 WD: Q3238636 46.17, 6.055 x 46.23, 6.144
    { 134, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x84471c} }, // 15 OSM: 4489138 WD: Q3238583 46.18, 6.12 x 46.22, 6.149
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 4 OSM: 4494871 WD: Q2105648 52.34, 4.889 x 52.38, 4.905
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xab10d2} }, // 12 OSM: 4495366 WD: Q14500288 52.35, 4.879 x 52.38, 4.919
    { 53, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffbf00} }, // 1 OSM: 4497227 WD: Q2663350 52.35, 4.775 x 52.36, 4.934
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffbf00} }, // 2 OSM: 4497722 WD: Q2033321 52.34, 4.804 x 52.38, 4.899
    { 1821, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x87ceeb} }, // TRAB OSM: 4497962 WD: Q2829306 33.37, -7.672 x 33.61, -7.554
    { 57, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xab10d2} }, // 3 OSM: 4498754 WD: Q2051638 52.35, 4.87 x 52.38, 4.952
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffbf00} }, // 5 OSM: 4501532 WD: Q2343376 52.3, 4.867 x 52.38, 4.884
    { 1826, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x006983} }, // Montauk OSM: 4501572 WD: Q4044495 40.7, -73.99 x 41.05, -71.95
    { 40, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff7f00} }, // 7 OSM: 4502267 WD: Q4405692 52.36, 4.818 x 52.38, 4.94
    { 138, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 19 OSM: 4507967 WD: Q2402279 52.34, 4.838 x 52.39, 4.971
    { 1834, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00985f} }, // Babylon OSM: 4509487 WD: Q4838506 40.66, -73.99 x 40.75, -73.32
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xab10d2} }, // 13 OSM: 4512711 WD: Q2157983 52.37, 4.803 x 52.38, 4.899
    { 130, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00ff00} }, // 14 OSM: 4513498 WD: Q2108285 52.36, 4.892 x 52.38, 4.952
    { 181, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf49ac1} }, // 24 OSM: 4513900 WD: Q2651682 52.34, 4.857 x 52.38, 4.898
    { 169, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x007fff} }, // 17 OSM: 4514442 WD: Q2400889 52.36, 4.786 x 52.38, 4.899
    { 523, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xd59758} }, // 26 OSM: 4514564 WD: Q2503173 52.35, 4.903 x 52.38, 5.005
    { 173, 9260, 9304, LineMetaDataContent::Subway, Color{0x29ab4d} }, // 50 OSM: 4515358 WD: Q2466111 52.29, 4.834 x 52.4, 4.99
    { 262, NoLogo, 9304, LineMetaDataContent::Subway, Color{0xf69931} }, // 51 OSM: 4515359 WD: Q606629 52.33, 4.834 x 52.4, 4.924
    { 745, 9329, 9304, LineMetaDataContent::Subway, Color{0xfcfb05} }, // 54 OSM: 4515360 WD: Q2183200 52.29, 4.9 x 52.38, 4.99
    { 1843, 9373, 9304, LineMetaDataContent::Subway, Color{0xff0000} }, // 53 OSM: 4515361 WD: Q2163442 52.31, 4.9 x 52.38, 4.985
    { 1022, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x1c9fda} }, // S10 OSM: 4543849 47.45, 17.64 x 47.75, 19.03
    { 1846, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfecd07} }, // Z30 OSM: 4546118 47.17, 18.43 x 47.5, 19.04
    { 1850, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffa500} }, // NS OSM: 4566683 45.49, -122.7 x 45.53, -122.7
    { 1730, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xce8e00} }, // Hempstead OSM: 4600806 WD: Q5712708 40.68, -73.97 x 40.73, -73.62
    { 1853, 9417, 9444, LineMetaDataContent::Subway, Color{0xff0000} }, // m2 OSM: 4621397 WD: Q3239144 46.51, 6.626 x 46.54, 6.662
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x94c11a} }, // 2 OSM: 4622863 52.23, 10.52 x 52.29, 10.54
    { 40, 9469, 3199, LineMetaDataContent::Subway, Color{0xffc66e} }, // 7 OSM: 4624900 WD: Q6553149 39.85, 116.3 x 39.89, 116.7
    { 130, 9489, 3199, LineMetaDataContent::Subway, Color{0xd4a7a1} }, // 14 OSM: 4624915 WD: Q6553070 39.86, 116.2 x 40.03, 116.5
    { 27, 9510, 3199, LineMetaDataContent::Subway, Color{0xbb8900} }, // 6 OSM: 4625142 WD: Q6553138 39.9, 116.2 x 39.93, 116.7
    { 53, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xec008c} }, // 1 OSM: 4628650 47.15, 27.56 x 47.19, 27.63
    { 57, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00a650} }, // 3 OSM: 4629075 47.15, 27.57 x 47.17, 27.66
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf9c0c1} }, // 6 OSM: 4631231 47.16, 27.54 x 47.17, 27.59
    { 40, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x2e3092} }, // 7 OSM: 4631274 47.14, 27.54 x 47.17, 27.64
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xd2e288} }, // 8 OSM: 4631290 47.15, 27.56 x 47.19, 27.61
    { 98, 9530, 944, LineMetaDataContent::Subway, Color{0xb8282e} }, // U1 OSM: 4656730 WD: Q198432 50.1, 8.634 x 50.17, 8.688
    { 104, 9547, 944, LineMetaDataContent::Subway, Color{0x4a5eaa} }, // U3 OSM: 4656731 WD: Q19862991 50.1, 8.537 x 50.22, 8.688
    { 107, 9564, 944, LineMetaDataContent::Subway, Color{0xf172ac} }, // U4 OSM: 4656732 WD: Q19862998 50.11, 8.652 x 50.14, 8.755
    { 110, 9581, 944, LineMetaDataContent::Subway, Color{0x007942} }, // U5 OSM: 4656733 WD: Q3040872 50.11, 8.662 x 50.16, 8.692
    { 116, 9598, 944, LineMetaDataContent::Subway, Color{0xe4a023} }, // U7 OSM: 4656734 WD: Q3040904 50.11, 8.608 x 50.14, 8.755
    { 119, 9615, 944, LineMetaDataContent::Subway, Color{0xc77db5} }, // U8 OSM: 4656735 WD: Q3063407 50.1, 8.621 x 50.18, 8.688
    { 122, 9632, 944, LineMetaDataContent::Subway, Color{0xeed700} }, // U9 OSM: 4656736 WD: Q19862984 50.14, 8.621 x 50.2, 8.674
    { 1700, 9649, 9656, LineMetaDataContent::Tramway, Color{0x008176} }, // T4 OSM: 4665787 WD: Q49368235 41.39, 2.187 x 41.42, 2.231
    { 1856, 9680, 9656, LineMetaDataContent::Tramway, Color{0x008176} }, // T6 OSM: 4665788 WD: Q49375135 41.4, 2.187 x 41.42, 2.231
    { 1393, 9687, 9656, LineMetaDataContent::Tramway, Color{0x008176} }, // T5 OSM: 4665789 WD: Q49394264 41.4, 2.187 x 41.44, 2.233
    { 1680, 9709, 9656, LineMetaDataContent::Tramway, Color{0x008176} }, // T3 OSM: 4667001 WD: Q49770929 41.37, 2.053 x 41.39, 2.143
    { 200, 6019, 9656, LineMetaDataContent::Tramway, Color{0x008176} }, // T1 OSM: 4667002 WD: Q49770336 41.36, 2.058 x 41.39, 2.143
    { 502, 5976, 9656, LineMetaDataContent::Tramway, Color{0x008176} }, // T2 OSM: 4667003 WD: Q49770664 41.36, 2.058 x 41.39, 2.143
    { 376, 9716, 9733, LineMetaDataContent::Subway, Color{0x992f9c} }, // L2 OSM: 4671269 WD: Q1348921 41.38, 2.163 x 41.45, 2.244
    { 368, 9758, 9733, LineMetaDataContent::Subway, Color{0xfab70a} }, // L4 OSM: 4671321 WD: Q961384 41.38, 2.163 x 41.45, 2.218
    { 1238, 9775, 9733, LineMetaDataContent::Subway, Color{0x317bc8} }, // L5 OSM: 4673514 WD: Q1348939 41.36, 2.071 x 41.43, 2.187
    { 1859, 9792, 9733, LineMetaDataContent::Subway, Color{0x00adef} }, // L10 OSM: 4673515 WD: Q1785338 41.42, 2.186 x 41.44, 2.234
    { 380, 9810, 9733, LineMetaDataContent::Subway, Color{0x39af57} }, // L3 OSM: 4673516 WD: Q385168 41.37, 2.111 x 41.45, 2.188
    { 1250, 9827, 9733, LineMetaDataContent::Subway, Color{0xd5578f} }, // L8 OSM: 4673517 WD: Q763319 41.35, 2.035 x 41.37, 2.149
    { 1246, 9844, 9733, LineMetaDataContent::Subway, Color{0xac5414} }, // L7 OSM: 4673518 WD: Q678390 41.39, 2.137 x 41.41, 2.169
    { 372, 9861, 9733, LineMetaDataContent::Subway, Color{0xe33638} }, // L1 OSM: 4673519 WD: Q1348946 41.34, 2.099 x 41.45, 2.218
    { 1863, 9878, 9733, LineMetaDataContent::Subway, Color{0x9ed74c} }, // L11 OSM: 4673520 WD: Q1419762 41.45, 2.173 x 41.46, 2.186
    { 1242, 9896, 9733, LineMetaDataContent::Subway, Color{0x7280c0} }, // L6 OSM: 4673521 WD: Q1577019 41.39, 2.125 x 41.4, 2.169
    { 1867, 9913, 9733, LineMetaDataContent::Subway, Color{0xf6842a} }, // L9 Nord OSM: 4673522 WD: Q1577033 41.42, 2.186 x 41.46, 2.219
    { 1772, 9930, 209, LineMetaDataContent::RapidTransit, Color{0xa70f47} }, // S21 OSM: 4708731 WD: Q19368759 53.49, 9.893 x 53.6, 10.32
    { 6, 9946, 6815, LineMetaDataContent::Subway, Color{0x996cac} }, // 5 OSM: 4744337 WD: Q92530 37.49, 126.8 x 37.58, 127.2
    { 53, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe30e68} }, // 1 OSM: 4748602 52.38, 16.83 x 52.4, 17
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x70c9e8} }, // 2 OSM: 4750038 52.37, 16.88 x 52.42, 16.92
    { 1875, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x800080} }, // Tren Urbano OSM: 4751620 WD: Q1577126 18.39, -66.15 x 18.44, -66.05
    { 57, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x84254b} }, // 3 OSM: 4756145 52.38, 16.91 x 52.44, 17
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x7dc833} }, // 5 OSM: 4763766 52.37, 16.88 x 52.41, 16.98
    { 1887, 9969, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe67310} }, // A2 OSM: 4785912 WD: Q19582807 53.71, 9.966 x 53.83, 9.993
    { 1890, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x004d9f} }, // Tide OSM: 4788761 WD: Q646388 36.84, -76.3 x 36.86, -76.19
    { 1895, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xee3a43} }, // 703 OSM: 4789075 WD: Q7304509 40.54, -112 x 40.77, -111.8
    { 1900, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xbdbadc} }, // 517 OSM: 4799475 WD: Q7163197 38.9, -77.01 x 39.56, -76.07
    { 1905, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xbdbadc} }, // 511 OSM: 4799475 WD: Q7163197 38.9, -77.01 x 39.56, -76.07
    { 1909, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xbdbadc} }, // 532 OSM: 4799476 WD: Q7163197 38.9, -77.01 x 39.56, -76.07
    { 1913, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xbdbadc} }, // 520 OSM: 4799476 WD: Q7163197 38.9, -77.01 x 39.56, -76.07
    { 1917, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xbdbadc} }, // 544 OSM: 4799476 WD: Q7163197 38.9, -77.01 x 39.56, -76.07
    { 19, 8086, NoLogo, LineMetaDataContent::Tramway, Color{0xff80c0} }, // 8 OSM: 4828592 WD: Q1962342 51.21, 4.42 x 51.22, 4.492
    { 57, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008080} }, // 3 OSM: 5143295 49.2, 16.52 x 49.23, 16.64
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffa500} }, // 4 OSM: 5151976 49.19, 16.58 x 49.21, 16.63
    { 200, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00a5c1} }, // T1 OSM: 5157502 WD: Q16011470 47.22, 5.949 x 47.26, 6.061
    { 2, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0d7b49} }, // 0 OSM: 5175545 52.39, 16.89 x 52.41, 16.94
    { 53, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe4002c} }, // 1 OSM: 5185991 51, 13.67 x 51.06, 13.82
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xeb5b2d} }, // 2 OSM: 5186008 51.01, 13.65 x 51.06, 13.85
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc9061a} }, // 4 OSM: 5186035 51.02, 13.56 x 51.16, 13.84
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffdd00} }, // 6 OSM: 5186067 51, 13.68 x 51.06, 13.84
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x229133} }, // 8 OSM: 5186073 51.03, 13.72 x 51.12, 13.77
    { 123, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x93c355} }, // 9 OSM: 5186435 51, 13.69 x 51.08, 13.8
    { 63, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf9b000} }, // 10 OSM: 5186677 51.04, 13.71 x 51.07, 13.81
    { 52, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc2ddaf} }, // 11 OSM: 5186681 51.02, 13.73 x 51.07, 13.86
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfdc300} }, // 13 OSM: 5186751 51, 13.69 x 51.08, 13.8
    { 1067, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x1c9fda} }, // S42 OSM: 5189590 46.96, 18.76 x 47.5, 19.04
    { 1921, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xafca36} }, // G10 OSM: 5189591 47.45, 17.64 x 47.75, 19.12
    { 1925, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x1c9fda} }, // S72 OSM: 5189592 47.51, 18.71 x 47.78, 19.1
    { 1929, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x1c9fda} }, // S30 OSM: 5189595 46.75, 17.56 x 47.5, 19.04
    { 1933, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xafca36} }, // G43 OSM: 5189602 47.17, 18.43 x 47.48, 19.35
    { 1519, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x1c9fda} }, // S40 OSM: 5189605 46.37, 18.15 x 47.5, 19.04
    { 1937, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x1c9fda} }, // S36 OSM: 5189606 47.25, 18.69 x 47.48, 19.35
    { 1941, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x1c9fda} }, // S355 OSM: 5189607 46.44, 16.99 x 47.5, 19.04
    { 304, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x1c9fda} }, // S34 OSM: 5189609 46.69, 17.24 x 47.5, 19.04
    { 53, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xd52330} }, // 1 OSM: 5209167 50.93, 6.816 x 50.96, 7.162
    { 40, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe6855c} }, // 7 OSM: 5231292 50.87, 6.797 x 50.94, 7.06
    { 39, NoLogo, 6713, LineMetaDataContent::RapidTransit, Color{0x159dd9} }, // S7 OSM: 5248498 WD: Q17101554 48.1, 16.38 x 48.57, 17.01
    { 153, 6713, 209, LineMetaDataContent::RapidTransit, Color{0x159dd9} }, // S60 OSM: 5248503 WD: Q695595 47.81, 16.23 x 48.19, 16.78
    { 172, 6713, 209, LineMetaDataContent::RapidTransit, Color{0x159dd9} }, // S50 OSM: 5248504 WD: Q695595 48.17, 15.89 x 48.21, 16.34
    { 1946, 9984, 6713, LineMetaDataContent::RapidTransit, Color{0x159dd9} }, // S80 OSM: 5248538 WD: Q96483911 48.17, 16.26 x 48.23, 16.51
    { 246, NoLogo, 6713, LineMetaDataContent::RapidTransit, Color{0xbdd542} }, // S45 OSM: 5248540 WD: Q17101545 48.19, 16.26 x 48.26, 16.39
    { 1519, 6713, 209, LineMetaDataContent::RapidTransit, Color{0x159dd9} }, // S40 OSM: 5248548 WD: Q695595 48.21, 15.62 x 48.35, 16.37
    { 53, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // 1 OSM: 5252357 WD: Q1548435 39.22, 9.125 x 39.27, 9.143
    { 53, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xeb4690} }, // 1 OSM: 5293755 33.98, -6.865 x 34.05, -6.794
    { 1680, 9694, 5983, LineMetaDataContent::Tramway, Color{0x96be0d} }, // T3 OSM: 5296539 WD: Q3238910 43.29, 5.367 x 43.32, 5.384
    { 125, 480, NoLogo, LineMetaDataContent::Subway, Color{} }, // U11 OSM: 5311905 WD: Q203252 51.42, 6.992 x 51.54, 7.026
    { 1950, 480, NoLogo, LineMetaDataContent::Subway, Color{} }, // U17 OSM: 5312041 WD: Q203252 51.43, 6.973 x 51.5, 7.013
    { 1955, 9997, NoLogo, LineMetaDataContent::Subway, Color{0x02ac39} }, // TR OSM: 5326658 WD: Q843148 35.7, 140 x 35.73, 140.1
    { 123, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8a2be2} }, // 9 OSM: 5329880 49.19, 16.61 x 49.23, 16.65
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x221815} }, // 6 OSM: 5335066 WD: Q957721 33.84, 132.8 x 33.85, 132.8
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x036eb8} }, // 5 OSM: 5335067 33.84, 132.8 x 33.85, 132.8
    { 57, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe60012} }, // 3 OSM: 5335068 33.84, 132.8 x 33.85, 132.8
    { 1958, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0066cc} }, // TDV OSM: 5371521 WD: Q23951292 -38.96, -68.23 x -38.94, -68
    { 1962, 10026, NoLogo, LineMetaDataContent::RapidTransit, Color{0x8b039b} }, // C-3 OSM: 5382815 WD: Q8879464 40.03, -4.271 x 40.63, -3.608
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x662584} }, // 2 OSM: 5391128 33.99, -6.872 x 34.04, -6.799
    { 59, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffa500} }, // S1 OSM: 5405974 WD: Q2316170 41.39, 2.007 x 41.58, 2.169
    { 48, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7e971e} }, // S2 OSM: 5405975 WD: Q2316170 41.39, 2.068 x 41.57, 2.169
    { 196, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x6295ce} }, // S6 OSM: 5405976 WD: Q2316170 41.39, 2.068 x 41.5, 2.169
    { 42, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x6295ce} }, // S5 OSM: 5405977 WD: Q2316170 41.39, 2.068 x 41.47, 2.169
    { 251, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf9b000} }, // 20 OSM: 5421483 51.04, 13.71 x 51.07, 13.74
    { 53, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x000080} }, // 1 OSM: 5465576 WD: Q10318641 -30.03, -51.23 x -29.69, -51.13
    { 57, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0000ff} }, // 3 OSM: 5468841 WD: Q54366530 17.39, 78.38 x 17.45, 78.56
    { 53, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 1 OSM: 5490398 41.66, 123.4 x 41.74, 123.5
    { 57, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 3 OSM: 5490400 41.65, 123.4 x 41.72, 123.5
    { 53, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x3dae2b} }, // 1 OSM: 5517061 WD: Q1067251 47.42, -122.3 x 47.7, -122.3
    { 1313, NoLogo, 1929, LineMetaDataContent::RapidTransit, Color{0xffa500} }, // Orange OSM: 5543450 WD: Q6714620 45.43, -122.7 x 45.51, -122.6
    { 190, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0088ab} }, // B OSM: 5575252 45.5, -122.7 x 45.54, -122.7
    { 1960, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe5554f} }, // V OSM: 5576487 WD: Q11152362 25.15, 121.4 x 25.2, 121.5
    { 221, 10044, 10086, LineMetaDataContent::RapidTransit, Color{0x80b352} }, // C OSM: 5593997 WD: Q4121246 22.59, 120.3 x 22.64, 120.3
    { 1966, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00bd19} }, // Π3 OSM: 5596928 WD: Q47477355 37.99, 23.57 x 38.46, 23.87
    { 51, 10164, 209, LineMetaDataContent::RapidTransit, Color{0x44a325} }, // S11 OSM: 5607596 WD: Q19368865 53.55, 9.814 x 53.65, 10.09
    { 48, 10180, 209, LineMetaDataContent::RapidTransit, Color{0xa70f47} }, // S2 OSM: 5607597 WD: Q19390036 53.49, 9.934 x 53.56, 10.21
    { 157, 10195, 209, LineMetaDataContent::RapidTransit, Color{0x5d1d81} }, // S3 OSM: 5607598 WD: Q19368685 53.46, 9.477 x 53.66, 10.03
    { 1970, 10210, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe79500} }, // A1 OSM: 5610369 WD: Q19368804 53.55, 9.889 x 54.08, 10.02
    { 16, 10225, NoLogo, LineMetaDataContent::Subway, Color{0xe70095} }, // 2 OSM: 5616937 WD: Q3832658 39.43, -0.5963 x 39.62, -0.3815
    { 123, 10256, NoLogo, LineMetaDataContent::Subway, Color{0xb7814f} }, // 9 OSM: 5622181 WD: Q18613779 39.47, -0.5603 x 39.54, -0.3521
    { 40, 10287, NoLogo, LineMetaDataContent::Subway, Color{0xf28c00} }, // 7 OSM: 5626070 WD: Q11690011 39.43, -0.4726 x 39.47, -0.3383
    { 57, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xd75128} }, // 3 OSM: 5646916 50.69, 12.46 x 50.73, 12.53
    { 154, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffa500} }, // 60 OSM: 5664426 WD: Q1632888 52.01, 5.076 x 52.09, 5.108
    { 79, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffa500} }, // 61 OSM: 5664427 WD: Q1632888 52.01, 5.028 x 52.09, 5.108
    { 52, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf05b72} }, // 11 OSM: 5668462 47.15, 27.54 x 47.17, 27.63
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00adef} }, // 13 OSM: 5668463 47.15, 27.56 x 47.19, 27.63
    { 1973, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // E-W OSM: 5697658 WD: Q53778901 9.01, 38.72 x 9.022, 38.87
    { 1977, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // S-N OSM: 5697659 WD: Q53779001 8.936, 38.73 x 9.039, 38.77
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x66cc00} }, // 2 OSM: 5711071 WD: Q56911095 36.28, 59.55 x 36.33, 59.68
    { 502, 10318, 4170, LineMetaDataContent::Tramway, Color{0x0098d4} }, // T2 OSM: 5720061 WD: Q16655787 43.59, 1.374 x 43.63, 1.446
    { 157, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x36a390} }, // S3 OSM: 5721287 WD: Q2381339 41.35, 2.005 x 41.4, 2.149
    { 207, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa25e23} }, // S4 OSM: 5721688 WD: Q2381339 41.35, 1.888 x 41.54, 2.149
    { 1710, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xb8b6b7} }, // R6 OSM: 5724702 41.35, 1.63 x 41.58, 2.149
    { 1981, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x707072} }, // R60 OSM: 5724705 41.35, 1.63 x 41.58, 2.149
    { 1715, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x38b0b1} }, // R5 OSM: 5724850 WD: Q2381339 41.35, 1.828 x 41.73, 2.149
    { 1985, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x3592a3} }, // R50 OSM: 5724851 WD: Q2381339 41.35, 1.828 x 41.73, 2.149
    { 169, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x6dcff6} }, // 17 OSM: 5740169 50.86, 6.957 x 50.93, 7.004
    { 26, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x21bfc1} }, // 16 OSM: 5742444 50.68, 6.943 x 50.99, 7.159
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe06e9f} }, // 4 OSM: 5742445 50.93, 6.873 x 51.02, 7.044
    { 169, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x286290} }, // 17 OSM: 5742856 52.37, 16.88 x 52.42, 16.98
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc88922} }, // 13 OSM: 5744834 52.37, 16.83 x 52.41, 16.96
    { 134, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8d98a2} }, // 15 OSM: 5745673 52.39, 16.85 x 52.46, 16.92
    { 1989, 480, NoLogo, LineMetaDataContent::Subway, Color{0xda251d} }, // U71 OSM: 5747258 WD: Q661002 51.16, 6.775 x 51.26, 6.886
    { 1993, 480, NoLogo, LineMetaDataContent::Subway, Color{0xda251d} }, // U83 OSM: 5748738 WD: Q661002 51.16, 6.775 x 51.25, 6.886
    { 63, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf2b023} }, // 10 OSM: 5752352 52.37, 16.9 x 52.44, 16.94
    { 1997, 480, NoLogo, LineMetaDataContent::Subway, Color{0xda251d} }, // U73 OSM: 5756097 WD: Q661002 51.19, 6.775 x 51.24, 6.867
    { 2001, 480, NoLogo, LineMetaDataContent::Subway, Color{0xda251d} }, // U72 OSM: 5756147 WD: Q661002 51.19, 6.762 x 51.3, 6.847
    { 2005, 10346, NoLogo, LineMetaDataContent::RapidTransit, Color{0x006434} }, // R2Sud OSM: 5758580 WD: Q1880046 41.19, 1.523 x 41.4, 2.194
    { 2011, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff6600} }, // HVL OSM: 5793083 -41.28, 174.8 x -41.13, 175.1
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xa4107f} }, // 4 OSM: 5804724 WD: Q3476269 51.91, 4.432 x 51.96, 4.504
    { 372, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x800080} }, // L1 OSM: 5812905 WD: Q95982832 38.09, 13.37 x 38.11, 13.41
    { 376, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffa500} }, // L2 OSM: 5812931 WD: Q95983858 38.13, 13.29 x 38.13, 13.34
    { 368, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // L4 OSM: 5813038 WD: Q95983909 38.1, 13.33 x 38.13, 13.34
    { 380, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // L3 OSM: 5813039 WD: Q95983869 38.13, 13.3 x 38.14, 13.34
    { 2015, NoLogo, 169, LineMetaDataContent::Tramway, Color{0xffd800} }, // 47B OSM: 5830635 WD: Q22696462 47.44, 18.98 x 47.5, 19.06
    { 2019, 10346, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00a85a} }, // R2 OSM: 5838299 WD: Q1880046 41.28, 1.978 x 41.6, 2.292
    { 2022, 10363, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff131a} }, // R3 OSM: 5844031 WD: Q2113761 41.36, 1.896 x 42.46, 2.297
    { 340, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffbacd} }, // U49 OSM: 5847183 51.48, 7.442 x 51.52, 7.476
    { 2025, 10380, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff8c00} }, // R4 OSM: 5849061 WD: Q2226508 41.19, 1.524 x 41.72, 2.189
    { 2028, 10397, NoLogo, LineMetaDataContent::RapidTransit, Color{0x9b1987} }, // R8 OSM: 5866129 WD: Q3817638 41.45, 1.926 x 41.6, 2.292
    { 199, 10414, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00bdac} }, // RT1 OSM: 5866193 WD: Q5985874 41.11, 1.098 x 41.16, 1.255
    { 501, 10432, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe579cb} }, // RT2 OSM: 5867875 WD: Q9025898 41, 0.9109 x 41.27, 1.6
    { 2031, 10450, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0073ce} }, // RG1 OSM: 5867923 WD: Q5985872 41.36, 2.099 x 42.42, 3.161
    { 2035, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0060a9} }, // Expo Line OSM: 5881298 WD: Q5421492 49.18, -123.1 x 49.29, -122.8
    { 2045, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xffd520} }, // Millennium Line OSM: 5881419 WD: Q1534900 49.25, -123.1 x 49.29, -122.8
    { 2061, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x009ac8} }, // Canada Line OSM: 5881439 WD: Q1031997 49.17, -123.2 x 49.29, -123.1
    { 2073, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfbba00} }, // U42 OSM: 5890483 51.47, 7.433 x 51.56, 7.547
    { 2077, 10465, 480, LineMetaDataContent::Tramway, Color{0xdc2a1b} }, // U45 OSM: 5892934 WD: Q107740406 51.49, 7.455 x 51.54, 7.475
    { 2081, 10479, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffdd00} }, // R12 OSM: 5927786 WD: Q9026146 41.36, 0.6331 x 41.75, 2.189
    { 37, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x1e9999} }, // E OSM: 5953002 WD: Q5324790 37.78, -122.4 x 37.81, -122.4
    { 323, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf4858d} }, // 614P OSM: 5955260 WD: Q15903043 22.37, 114 x 22.41, 114
    { 2085, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x006684} }, // 615P OSM: 5955261 WD: Q15903207 22.37, 114 x 22.41, 114
    { 226, NoLogo, 10509, LineMetaDataContent::Subway, Color{0x00aa50} }, // A OSM: 5955845 WD: Q2310450 51.9, 4.314 x 51.96, 4.566
    { 190, NoLogo, 10509, LineMetaDataContent::Subway, Color{0xffd301} }, // B OSM: 5955846 WD: Q2960661 51.9, 4.129 x 51.98, 4.587
    { 221, NoLogo, 10509, LineMetaDataContent::Subway, Color{0xef1f1f} }, // C OSM: 5955847 WD: Q2058778 51.83, 4.319 x 51.94, 4.601
    { 1093, NoLogo, 10509, LineMetaDataContent::Subway, Color{0x1bc5e9} }, // D OSM: 5955848 WD: Q2034685 51.83, 4.319 x 51.92, 4.497
    { 37, NoLogo, 10534, LineMetaDataContent::Subway, Color{0x1a389a} }, // E OSM: 5955849 WD: Q2687418 51.87, 4.325 x 52.08, 4.497
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x90130c} }, // 2 OSM: 5955850 WD: Q1982139 51.88, 4.464 x 51.9, 4.554
    { 251, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfbb316} }, // 20 OSM: 5966563 WD: Q3118970 51.88, 4.471 x 51.92, 4.539
    { 40, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x97d700} }, // 7 OSM: 5971692 WD: Q6553152 22.99, 113.3 x 23.05, 113.4
    { 2090, 9913, 9733, LineMetaDataContent::Subway, Color{0xf6842a} }, // L9 Sud OSM: 5972747 WD: Q1577033 41.29, 2.055 x 41.38, 2.136
    { 2097, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // NL1 OSM: 5976635 49, 8.405 x 49.01, 8.479
    { 2101, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x006699} }, // NL2 OSM: 5976636 48.99, 8.384 x 49.01, 8.411
    { 2105, 10548, NoLogo, LineMetaDataContent::RapidTransit, Color{0x002369} }, // R11 OSM: 6021945 WD: Q11050690 41.38, 2.14 x 42.43, 3.161
    { 2109, 10578, NoLogo, LineMetaDataContent::RapidTransit, Color{0xed3896} }, // R13 OSM: 6025765 WD: Q6018166 41.18, 0.6331 x 41.62, 2.194
    { 2113, 10608, NoLogo, LineMetaDataContent::RapidTransit, Color{0x4e53ab} }, // R14 OSM: 6028425 WD: Q2880157 41.11, 0.6331 x 41.62, 2.194
    { 2117, 10638, NoLogo, LineMetaDataContent::RapidTransit, Color{0x9a836c} }, // R15 OSM: 6028724 WD: Q5845244 41.09, 0.4797 x 41.4, 2.194
    { 305, 10668, NoLogo, LineMetaDataContent::RapidTransit, Color{0x94288e} }, // 34 OSM: 6028756 WD: Q9025916 41.09, -0.9102 x 41.66, 2.194
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // 5 OSM: 6059624 41.74, 123.5 x 41.81, 123.7
    { 169, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x4d3d00} }, // 17 OSM: 6061801 49.01, 8.359 x 49.05, 8.452
    { 26, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffaaaa} }, // 16 OSM: 6061802 48.99, 8.383 x 49.05, 8.452
    { 22, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00805a} }, // 18 OSM: 6061803 49, 8.431 x 49.05, 8.479
    { 37, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // E OSM: 6062533 48.95, 8.283 x 49.11, 8.505
    { 1093, 10693, 10720, LineMetaDataContent::RapidTransit, Color{0xf9c212} }, // D OSM: 6063097 WD: Q10318679 41.11, -8.611 x 41.18, -8.599
    { 37, 10741, 10720, LineMetaDataContent::RapidTransit, Color{0x937bb8} }, // E OSM: 6063237 WD: Q10318682 41.15, -8.67 x 41.24, -8.582
    { 240, 10768, 10720, LineMetaDataContent::RapidTransit, Color{0xf68b1f} }, // F OSM: 6064751 WD: Q10318684 41.15, -8.655 x 41.19, -8.542
    { 226, 10795, 10720, LineMetaDataContent::RapidTransit, Color{0x3caeef} }, // A OSM: 6064925 WD: Q18473912 41.15, -8.694 x 41.19, -8.582
    { 221, 10822, 10720, LineMetaDataContent::RapidTransit, Color{0x8bc63e} }, // C OSM: 6065645 WD: Q10318673 41.15, -8.656 x 41.27, -8.586
    { 33, 10849, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffff00} }, // S OSM: 6071918 WD: Q7395342 37.74, -122.5 x 37.79, -122.4
    { 1511, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // 704 OSM: 6073252 WD: Q5602824 40.69, -112 x 40.78, -111.9
    { 2121, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // 701 OSM: 6073253 WD: Q4929373 40.53, -111.9 x 40.77, -111.9
    { 53, NoLogo, 10868, LineMetaDataContent::Subway, Color{0x000080} }, // 1 OSM: 6087653 WD: Q10318642 -19.95, -44.03 x -19.82, -43.91
    { 78, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf0e68c} }, // 261 OSM: 6088583 37.31, -122.4 x 37.78, -121.9
    { 1842, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf0e68c} }, // 253 OSM: 6088583 37.31, -122.4 x 37.78, -121.9
    { 584, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf0e68c} }, // 227 OSM: 6088583 37.31, -122.4 x 37.78, -121.9
    { 2125, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf0e68c} }, // 211 OSM: 6088583 37.31, -122.4 x 37.78, -121.9
    { 2129, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf0e68c} }, // 235 OSM: 6088583 37.31, -122.4 x 37.78, -121.9
    { 2133, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf0e68c} }, // 205 OSM: 6088583 37.31, -122.4 x 37.78, -121.9
    { 2137, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf0e68c} }, // 257 OSM: 6088583 37.31, -122.4 x 37.78, -121.9
    { 2141, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf0e68c} }, // 241 OSM: 6088583 37.31, -122.4 x 37.78, -121.9
    { 588, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf0e68c} }, // 269 OSM: 6088583 37.31, -122.4 x 37.78, -121.9
    { 2145, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf0e68c} }, // 277 OSM: 6088583 37.31, -122.4 x 37.78, -121.9
    { 997, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf0e68c} }, // 291 OSM: 6088583 37.31, -122.4 x 37.78, -121.9
    { 2149, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf0e68c} }, // 285 OSM: 6088583 37.31, -122.4 x 37.78, -121.9
    { 2153, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf0e68c} }, // 245 OSM: 6088583 37.31, -122.4 x 37.78, -121.9
    { 2157, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf0e68c} }, // 249 OSM: 6088583 37.31, -122.4 x 37.78, -121.9
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xea5297} }, // 4 OSM: 6092716 47.99, 7.829 x 48.04, 7.863
    { 2161, 10885, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // Sul OSM: 6113028 WD: Q10318728 -3.895, -38.63 x -3.72, -38.53
    { 211, NoLogo, 209, LineMetaDataContent::RapidTransit, Color{0xf36421} }, // S 1 OSM: 6116272 WD: Q56378877 50.88, 13.46 x 51.16, 14.24
    { 1587, NoLogo, 209, LineMetaDataContent::RapidTransit, Color{0xb8282e} }, // S 2 OSM: 6116280 WD: Q56378880 50.96, 13.72 x 51.13, 13.93
    { 1462, NoLogo, 209, LineMetaDataContent::RapidTransit, Color{0xed0172} }, // S 3 OSM: 6116305 WD: Q56378881 50.9, 13.34 x 51.04, 13.73
    { 207, 6713, 209, LineMetaDataContent::RapidTransit, Color{0x159dd9} }, // S4 OSM: 6157906 WD: Q695595 47.81, 15.98 x 48.4, 16.41
    { 190, 10923, 10720, LineMetaDataContent::RapidTransit, Color{0xe62621} }, // B OSM: 6161229 WD: Q10318669 41.15, -8.758 x 41.38, -8.582
    { 53, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc01115} }, // 1 OSM: 6182760 WD: Q2085324 51.98, 4.277 x 52.12, 4.359
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x006600} }, // 2 OSM: 6182761 WD: Q3926989 52.05, 4.236 x 52.09, 4.383
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0093de} }, // 6 OSM: 6182762 WD: Q2205103 52.06, 4.264 x 52.1, 4.4
    { 52, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xcd853f} }, // 11 OSM: 6192619 WD: Q2084217 52.06, 4.27 x 52.11, 4.324
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff66ff} }, // 12 OSM: 6192620 WD: Q2541548 52.06, 4.252 x 52.09, 4.324
    { 123, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xa6c116} }, // 9 OSM: 6192621 WD: Q2293268 52.03, 4.257 x 52.12, 4.324
    { 134, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe63a6b} }, // 15 OSM: 6197181 WD: Q2202159 52.04, 4.31 x 52.08, 4.393
    { 26, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfa7222} }, // 16 OSM: 6197182 WD: Q2746551 52.02, 4.271 x 52.1, 4.327
    { 169, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x006b8b} }, // 17 OSM: 6197183 WD: Q2417431 52.02, 4.289 x 52.08, 4.339
    { 138, NoLogo, 10534, LineMetaDataContent::Tramway, Color{0xc01115} }, // 19 OSM: 6197184 WD: Q2886326 52.01, 4.35 x 52.09, 4.406
    { 2165, NoLogo, 10950, LineMetaDataContent::RapidTransit, Color{0x0275a4} }, // BLUE OSM: 6265609 WD: Q4929367 32.65, -96.81 x 32.92, -96.56
    { 1091, NoLogo, 10950, LineMetaDataContent::RapidTransit, Color{0xcc0000} }, // RED OSM: 6265610 WD: Q16984038 32.72, -96.87 x 33.03, -96.7
    { 2170, NoLogo, 10950, LineMetaDataContent::RapidTransit, Color{0x00873f} }, // GREEN OSM: 6265672 WD: Q5602816 32.72, -96.94 x 32.99, -96.68
    { 2176, NoLogo, 10950, LineMetaDataContent::RapidTransit, Color{0xcc6600} }, // ORANGE OSM: 6265702 WD: Q7099665 32.78, -97.04 x 33.03, -96.7
    { 2183, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000066} }, // 620 OSM: 6265792 WD: Q19878111 32.75, -96.82 x 32.78, -96.81
    { 63, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0000ff} }, // 10 OSM: 6286483 WD: Q3239219 59.33, 17.88 x 59.4, 18.07
    { 52, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0000ff} }, // 11 OSM: 6286484 WD: Q3239220 59.33, 17.91 x 59.42, 18.07
    { 169, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x008000} }, // 17 OSM: 6286485 WD: Q3239225 59.27, 17.92 x 59.34, 18.13
    { 22, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x008000} }, // 18 OSM: 6286486 WD: Q3239226 59.23, 17.98 x 59.34, 18.1
    { 138, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x008000} }, // 19 OSM: 6286487 WD: Q3239227 59.26, 17.83 x 59.37, 18.08
    { 56, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // 13 OSM: 6286488 WD: Q3239222 59.24, 17.81 x 59.36, 18.1
    { 130, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // 14 OSM: 6286489 WD: Q3239223 59.29, 17.96 x 59.4, 18.08
    { 2187, 10985, 11011, LineMetaDataContent::Subway, Color{0x0a9cda} }, // Victoria OSM: 6354922 WD: Q203030 51.46, -0.1441 x 51.59, -0.01927
    { 2196, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x3a75c4} }, // North Clyde OSM: 6399061 55.85, -4.733 x 56, -3.19
    { 2208, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x2e8b57} }, // North Berwick OSM: 6399368 55.93, -3.187 x 56.06, -2.514
    { 2222, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xcc5500} }, // Maryhill OSM: 6403662 55.86, -4.321 x 55.9, -4.239
    { 2231, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0b4ea2} }, // TL 1 OSM: 6421836 50.83, -0.5143 x 52.14, -0.03743
    { 2236, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x629f3f} }, // Santa Cruz OSM: 6432131 WD: Q10318722 -22.92, -43.69 x -22.85, -43.19
    { 2247, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0691f6} }, // Japeri OSM: 6432248 WD: Q10318695 -22.91, -43.66 x -22.64, -43.19
    { 9, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xffcc29} }, // 4 OSM: 6432702 WD: Q6553130 -23.01, -43.31 x -22.98, -43.2
    { 1740, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x00ab4e} }, // KTL OSM: 6452936 WD: Q736412 22.29, 114.2 x 22.34, 114.3
    { 2254, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe6180a} }, // 505 OSM: 6481283 WD: Q13645607 22.38, 114 x 22.41, 114
    { 2258, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x1a8539} }, // 507 OSM: 6481317 WD: Q15917019 22.37, 114 x 22.41, 114
    { 2262, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x8d3219} }, // 610 OSM: 6481421 WD: Q15908713 22.37, 114 x 22.45, 114
    { 2266, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf4e619} }, // 615 OSM: 6481435 WD: Q15903207 22.37, 114 x 22.45, 114
    { 2270, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x44adc3} }, // 614 OSM: 6485195 WD: Q15903043 22.37, 114 x 22.45, 114
    { 2274, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x70147b} }, // 761P OSM: 6485222 WD: Q15909914 22.44, 114 x 22.47, 114
    { 2279, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf7931d} }, // SN 5 OSM: 6489645 51.07, -0.3187 x 51.5, 0.2699
    { 2284, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009933} }, // T-A OSM: 6491413 6.233, -75.57 x 6.248, -75.54
    { 200, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xed1c24} }, // T1 OSM: 6497386 43.28, 5.547 x 43.3, 5.566
    { 2288, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x6633ff} }, // T1 R OSM: 6545828 36.72, 3.083 x 36.78, 3.263
    { 2293, 11027, NoLogo, LineMetaDataContent::Tramway, Color{0xff00ff} }, // 18E OSM: 6547489 WD: Q63230200 38.7, -9.203 x 38.71, -9.145
    { 1515, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xba85bb} }, // 706 OSM: 6558996 WD: Q6718531 22.45, 114 x 22.47, 114
    { 2297, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x8cc022} }, // 705 OSM: 6558997 WD: Q16057726 22.45, 114 x 22.47, 114
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe41f25} }, // 4 OSM: 6576221 48.22, 14.23 x 48.31, 14.29
    { 226, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0171b7} }, // A OSM: 6585129 33.77, -118.3 x 34.05, -118.2
    { 2301, 11040, NoLogo, LineMetaDataContent::Tramway, Color{0xff7f00} }, // 25E OSM: 6595981 WD: Q63230206 38.71, -9.17 x 38.72, -9.135
    { 53, 11053, 11082, LineMetaDataContent::Tramway, Color{0x0000ff} }, // 1 OSM: 6667548 WD: Q30926891 -22.91, -43.21 x -22.89, -43.17
    { 502, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // T2 OSM: 6679929 WD: Q107172304 42.84, -2.685 x 42.88, -2.665
    { 40, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x2948a3} }, // 7 OSM: 6679981 52.38, 16.88 x 52.42, 16.96
    { 22, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfad50e} }, // 18 OSM: 6680332 52.41, 16.88 x 52.44, 16.92
    { 2305, 11103, 9733, LineMetaDataContent::Subway, Color{0xb2aed3} }, // L12 OSM: 6699916 WD: Q20107064 41.4, 2.119 x 41.4, 2.126
    { 130, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x81312f} }, // 14 OSM: 6728233 WD: Q6553073 23.24, 113.3 x 23.57, 113.6
    { 2309, NoLogo, 209, LineMetaDataContent::RapidTransit, Color{0x6c421b} }, // S14 OSM: 6731045 WD: Q7388188 47.27, 8.429 x 47.41, 8.84
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x90ee90} }, // 8 OSM: 6749431 49.78, 24.03 x 49.84, 24.06
    { 157, NoLogo, 8751, LineMetaDataContent::RapidTransit, Color{0x3c2c90} }, // S3 OSM: 6754348 WD: Q67882855 48.26, 14.29 x 48.36, 14.52
    { 2313, 480, NoLogo, LineMetaDataContent::Subway, Color{0x302276} }, // U74 OSM: 6760736 WD: Q661002 51.16, 6.615 x 51.28, 6.853
    { 53, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x791714} }, // 1 OSM: 6774704 WD: Q10318644 -12.99, -38.52 x -12.92, -38.47
    { 2317, NoLogo, 11121, LineMetaDataContent::Tramway, Color{0x83b81a} }, // Τ5 OSM: 6792080 WD: Q25535312 37.85, 23.7 x 37.97, 23.75
    { 2321, NoLogo, 11121, LineMetaDataContent::Tramway, Color{0x0098d4} }, // Τ3 OSM: 6792082 WD: Q25535308 37.85, 23.66 x 37.94, 23.75
    { 2325, NoLogo, 11121, LineMetaDataContent::Tramway, Color{0xe32119} }, // Τ4 OSM: 6792083 WD: Q25535309 37.92, 23.66 x 37.97, 23.74
    { 39, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfff90a} }, // S7 OSM: 6796259 48.63, 8.065 x 49.01, 8.432
    { 2329, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfff90a} }, // S71 OSM: 6796260 48.63, 8.065 x 48.99, 8.405
    { 2333, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x6d682a} }, // S81 OSM: 6796368 48.44, 8.215 x 48.99, 8.864
    { 40, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffa500} }, // 7 OSM: 6799066 39.75, 30.49 x 39.76, 30.54
    { 53, 11161, NoLogo, LineMetaDataContent::Subway, Color{0xe4002b} }, // 1 OSM: 6800211 WD: Q1326478 31.11, 121.4 x 31.4, 121.5
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00bfff} }, // 4 OSM: 6800376 39.75, 30.5 x 39.78, 30.56
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffff00} }, // 6 OSM: 6800649 39.74, 30.52 x 39.78, 30.59
    { 59, NoLogo, 8751, LineMetaDataContent::RapidTransit, Color{0xf5831a} }, // S1 OSM: 6800744 WD: Q67882646 48.02, 14.29 x 48.3, 14.52
    { 26, 11181, NoLogo, LineMetaDataContent::Subway, Color{0x2cd5c4} }, // 16 OSM: 6803864 WD: Q5954911 30.91, 121.6 x 31.2, 121.9
    { 6, 11202, NoLogo, LineMetaDataContent::Subway, Color{0xac4fc6} }, // 5 OSM: 6806165 WD: Q1331322 30.91, 121.4 x 31.12, 121.5
    { 57, 11211, NoLogo, LineMetaDataContent::Subway, Color{0xffd100} }, // 3 OSM: 6817204 WD: Q1326495 31.15, 121.4 x 31.41, 121.5
    { 2337, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xb6bd00} }, // SIL OSM: 6827213 WD: Q2041013 22.24, 114.1 x 22.28, 114.2
    { 27, 11220, NoLogo, LineMetaDataContent::Subway, Color{0xd9017a} }, // 6 OSM: 6840940 WD: Q631135 31.15, 121.5 x 31.36, 121.6
    { 2341, NoLogo, 11229, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // TL-1 OSM: 6849311 WD: Q5985920 20.61, -103.4 x 20.74, -103.3
    { 2346, NoLogo, 11229, LineMetaDataContent::RapidTransit, Color{0x008000} }, // TL-2 OSM: 6851904 WD: Q5986178 20.66, -103.4 x 20.68, -103.3
    { 2351, 4042, 3750, LineMetaDataContent::Subway, Color{0xffff00} }, // 8А OSM: 6855054 WD: Q585986 55.63, 37.33 x 55.75, 37.54
    { 376, 11247, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff6600} }, // L2 OSM: 6857222 WD: Q5986175 -37.03, -73.16 x -36.82, -73.06
    { 372, 11305, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff6600} }, // L1 OSM: 6857223 WD: Q5985914 -36.98, -73.12 x -36.71, -72.94
    { 42, NoLogo, 8751, LineMetaDataContent::RapidTransit, Color{0xee008d} }, // S5 OSM: 6881147 WD: Q67882950 48.27, 14.02 x 48.3, 14.29
    { 237, 11373, NoLogo, LineMetaDataContent::RapidTransit, Color{0xc6cc00} }, // J OSM: 6904183 WD: Q93388 48.88, 1.478 x 49.29, 2.326
    { 2355, 11396, 4327, LineMetaDataContent::Tramway, Color{0xf68c59} }, // T3a OSM: 6907402 WD: Q2420695 48.82, 2.27 x 48.85, 2.411
    { 1700, 11430, 4327, LineMetaDataContent::Tramway, Color{0xf2af00} }, // T4 OSM: 6910344 WD: Q1826681 48.89, 2.48 x 48.93, 2.571
    { 1393, 11463, 4327, LineMetaDataContent::Tramway, Color{0xb156a1} }, // T5 OSM: 6910410 WD: Q3238968 48.94, 2.356 x 48.98, 2.391
    { 1856, 11496, 4327, LineMetaDataContent::Tramway, Color{0xe85426} }, // T6 OSM: 6910437 WD: Q3238993 48.78, 2.169 x 48.81, 2.301
    { 2359, 11529, 4327, LineMetaDataContent::Tramway, Color{0xb98b59} }, // T7 OSM: 6910465 WD: Q3239019 48.71, 2.352 x 48.79, 2.373
    { 1461, 11562, NoLogo, LineMetaDataContent::RapidTransit, Color{0x5cda21} }, // RS 3 OSM: 6925925 WD: Q84703705 53.05, 8.002 x 53.18, 8.815
    { 1337, 11577, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // RS 4 OSM: 6925927 WD: Q84703708 53.05, 8.452 x 53.49, 8.815
    { 2362, 11592, NoLogo, LineMetaDataContent::Subway, Color{0xffcf00} }, // Orlyval OSM: 6928902 WD: Q432593 48.73, 2.3 x 48.76, 2.37
    { 2370, 11592, 11592, LineMetaDataContent::Subway, Color{0x142b4a} }, // CDGVAL OSM: 6928933 WD: Q1023114 49, 2.542 x 49.01, 2.572
    { 226, 11615, NoLogo, LineMetaDataContent::Subway, Color{0x800080} }, // A OSM: 6937084 WD: Q4268353 24.95, 121.2 x 25.09, 121.5
    { 520, 11646, NoLogo, LineMetaDataContent::Subway, Color{0xfccc0a} }, // W OSM: 6942556 WD: Q126567 40.7, -74.01 x 40.78, -73.91
    { 48, NoLogo, 8751, LineMetaDataContent::RapidTransit, Color{0x00acaf} }, // S2 OSM: 6967088 WD: Q67882763 48.17, 14.03 x 48.29, 14.29
    { 2377, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008531} }, // Luas Green Line OSM: 6975500 WD: Q2086105 53.24, -6.298 x 53.37, -6.143
    { 1669, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x68c56b} }, // DART OSM: 6979159 WD: Q839815 53.14, -6.255 x 53.45, -6.06
    { 53, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc00027} }, // 1 OSM: 6981890 47.74, 7.321 x 47.78, 7.343
    { 6, 11672, 11693, LineMetaDataContent::Subway, Color{0xb5ba05} }, // 5 OSM: 6996917 WD: Q957143 50.81, 4.266 x 50.86, 4.432
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffd80e} }, // 2 OSM: 7006051 47.73, 7.297 x 47.76, 7.352
    { 53, 11717, 11693, LineMetaDataContent::Subway, Color{0xc4008f} }, // 1 OSM: 7006076 WD: Q1345228 50.84, 4.319 x 50.86, 4.464
    { 57, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00a651} }, // 3 OSM: 7006942 47.74, 7.275 x 47.76, 7.344
    { 2393, NoLogo, 11592, LineMetaDataContent::Subway, Color{0x142b4a} }, // LISA OSM: 7011253 WD: Q52773923 49, 2.578 x 49, 2.592
    { 52, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 11 OSM: 7023559 44.79, 20.37 x 44.83, 20.46
    { 16, 11738, 11082, LineMetaDataContent::Tramway, Color{0x008000} }, // 2 OSM: 7064054 WD: Q30926895 -22.91, -43.21 x -22.9, -43.17
    { 48, 11767, 209, LineMetaDataContent::RapidTransit, Color{0x6cc247} }, // S2 OSM: 7091572 WD: Q7388247 48.13, 11.25 x 48.41, 11.91
    { 749, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x223344} }, // 22 OSM: 7095091 54.26, 48.28 x 54.36, 48.41
    { 372, 11783, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // L1 OSM: 7106760 WD: Q3011576 43.24, -3.013 x 43.4, -2.897
    { 207, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // S4 OSM: 7113761 46.55, 13.37 x 46.63, 13.85
    { 48, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x006400} }, // S2 OSM: 7113763 46.53, 13.83 x 46.77, 14.37
    { 59, 8751, 209, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // S1 OSM: 7113764 WD: Q680235 46.6, 12.77 x 46.95, 14.48
    { 2398, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // MetroValpo OSM: 7114438 WD: Q1320531 -33.06, -71.63 x -32.98, -71.28
    { 40, 11806, 5415, LineMetaDataContent::Tramway, Color{0xefe048} }, // 7 OSM: 7135778 WD: Q3239018 50.81, 4.336 x 50.9, 4.408
    { 380, 11827, NoLogo, LineMetaDataContent::Subway, Color{0xe3007d} }, // L3 OSM: 7141757 WD: Q2992379 43.25, -2.926 x 43.27, -2.889
    { 966, 11850, 5415, LineMetaDataContent::Tramway, Color{0xde3b21} }, // 92 OSM: 7152034 WD: Q2661521 50.79, 4.34 x 50.88, 4.381
    { 207, NoLogo, 8751, LineMetaDataContent::RapidTransit, Color{0x97bd2f} }, // S4 OSM: 7152118 WD: Q67882906 47.91, 14.1 x 48.29, 14.29
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x37b355} }, // 2 OSM: 7157243 WD: Q60031554 48.38, 9.936 x 48.43, 9.987
    { 53, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xed1b24} }, // 1 OSM: 7157244 WD: Q60031375 48.39, 9.955 x 48.43, 10.03
    { 372, 11872, NoLogo, LineMetaDataContent::Tramway, Color{0xc00b31} }, // L1 OSM: 7183555 WD: Q29634861 37.14, -3.654 x 37.23, -3.592
    { 2409, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // C-2 OSM: 7193330 43.25, -3.112 x 43.32, -2.928
    { 16, 11896, 6316, LineMetaDataContent::Subway, Color{0x216eb4} }, // 2 OSM: 7227705 WD: Q50718 48.85, 2.278 x 48.88, 2.399
    { 53, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x93c21c} }, // 1 OSM: 7252644 WD: Q60669571 -23.97, -46.41 x -23.96, -46.31
    { 2413, 11914, 11011, LineMetaDataContent::Subway, Color{0xe42313} }, // Central OSM: 7254206 WD: Q205355 51.5, -0.4378 x 51.69, 0.1146
    { 53, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xbf4525} }, // 1 OSM: 7271947 WD: Q24500 60.29, 5.232 x 60.39, 5.361
    { 37, 11939, 2150, LineMetaDataContent::RapidTransit, Color{0xbd76a1} }, // E OSM: 7271953 WD: Q668655 48.74, 2.327 x 48.9, 2.761
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf6c828} }, // 13 OSM: 7295272 WD: Q96483392 47.35, 8.481 x 47.41, 8.542
    { 16, 11971, 11693, LineMetaDataContent::Subway, Color{0xf57000} }, // 2 OSM: 7305855 WD: Q1826676 50.83, 4.321 x 50.87, 4.37
    { 27, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x80225f} }, // 6 OSM: 7322006 WD: Q6553140 23.11, 113.2 x 23.2, 113.5
    { 2421, 11992, 209, LineMetaDataContent::RapidTransit, Color{0x9f4c37} }, // S41 OSM: 7369771 WD: Q12374455 52.46, 13.28 x 52.55, 13.48
    { 974, 12007, 5415, LineMetaDataContent::Tramway, Color{0x338c26} }, // 81 OSM: 7375224 WD: Q2133516 50.82, 4.28 x 50.84, 4.408
    { 59, NoLogo, 12029, LineMetaDataContent::RapidTransit, Color{0x005f33} }, // S1 OSM: 7382640 WD: Q24929119 50.6, 4.32 x 51.22, 4.497
    { 48, NoLogo, 12029, LineMetaDataContent::RapidTransit, Color{0xf16122} }, // S2 OSM: 7383577 WD: Q56309162 50.61, 4.139 x 50.9, 4.716
    { 1221, NoLogo, 12029, LineMetaDataContent::RapidTransit, Color{0x009696} }, // S20 OSM: 7386794 WD: Q56309254 50.67, 4.565 x 50.88, 4.719
    { 42, NoLogo, 12029, LineMetaDataContent::RapidTransit, Color{0xffcc06} }, // S5 OSM: 7387151 WD: Q56309389 50.69, 3.87 x 51.02, 4.484
    { 157, NoLogo, 12029, LineMetaDataContent::RapidTransit, Color{0x222975} }, // S3 OSM: 7388964 WD: Q56309590 50.82, 3.601 x 51.02, 4.366
    { 207, NoLogo, 12029, LineMetaDataContent::RapidTransit, Color{0xcb2127} }, // S4 OSM: 7389117 WD: Q56309251 50.82, 4.039 x 50.94, 4.433
    { 196, NoLogo, 12029, LineMetaDataContent::RapidTransit, Color{0x965f26} }, // S6 OSM: 7391007 WD: Q56309855 50.69, 3.87 x 50.88, 4.378
    { 39, NoLogo, 12029, LineMetaDataContent::RapidTransit, Color{0x571759} }, // S7 OSM: 7391045 WD: Q56309167 50.73, 4.241 x 51.02, 4.523
    { 45, NoLogo, 12029, LineMetaDataContent::RapidTransit, Color{0x0096cb} }, // S8 OSM: 7391071 WD: Q56309403 50.65, 4.336 x 50.87, 4.617
    { 460, NoLogo, 12029, LineMetaDataContent::RapidTransit, Color{0x67bc45} }, // S9 OSM: 7391314 WD: Q56309779 50.68, 4.335 x 50.9, 4.717
    { 1022, NoLogo, 12029, LineMetaDataContent::RapidTransit, Color{0x000000} }, // S10 OSM: 7391375 WD: Q56309273 50.83, 4.039 x 51.02, 4.366
    { 2425, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x4a611c} }, // RL1 OSM: 7399137 WD: Q3781389 41.62, 0.631 x 41.79, 0.8166
    { 233, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffff00} }, // 25 OSM: 7409703 31.2, 29.9 x 31.22, 29.93
    { 53, 12051, NoLogo, LineMetaDataContent::Tramway, Color{0xf38230} }, // 1 OSM: 7418079 WD: Q59134535 33.53, -7.67 x 33.6, -7.5
    { 16, 12105, NoLogo, LineMetaDataContent::Tramway, Color{0xffdb2f} }, // 2 OSM: 7418090 WD: Q59159905 33.56, -7.682 x 33.61, -7.507
    { 1700, 12163, NoLogo, LineMetaDataContent::Tramway, Color{0xffa500} }, // T4 OSM: 7420266 WD: Q15507510 41.02, 28.85 x 41.12, 28.93
    { 56, 12191, 6316, LineMetaDataContent::Subway, Color{0x89c7d6} }, // 13 OSM: 7420641 WD: Q50759 48.81, 2.284 x 48.95, 2.369
    { 15, 12210, 6316, LineMetaDataContent::Subway, Color{0x328e5b} }, // 12 OSM: 7420642 WD: Q50757 48.82, 2.273 x 48.91, 2.366
    { 52, 12229, 6316, LineMetaDataContent::Subway, Color{0x8e6538} }, // 11 OSM: 7420643 WD: Q50756 48.86, 2.348 x 48.88, 2.416
    { 19, 12248, 6316, LineMetaDataContent::Subway, Color{0xc5a3ca} }, // 8 OSM: 7420644 WD: Q50751 48.77, 2.278 x 48.87, 2.465
    { 6, 12266, 6316, LineMetaDataContent::Subway, Color{0xde8b53} }, // 5 OSM: 7420645 WD: Q50745 48.83, 2.355 x 48.91, 2.449
    { 2429, 12284, 6316, LineMetaDataContent::Subway, Color{0x89c7d6} }, // 3bis OSM: 7420646 WD: Q50742 48.87, 2.399 x 48.88, 2.406
    { 330, 12306, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe4b4d1} }, // R OSM: 7420697 WD: Q93383 48.01, 2.373 x 48.84, 2.946
    { 388, NoLogo, 2680, LineMetaDataContent::RapidTransit, Color{0x7b4339} }, // H OSM: 7420698 WD: Q2572054 48.88, 2.093 x 49.26, 2.469
    { 491, 12329, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00b092} }, // N OSM: 7420700 WD: Q93376 48.64, 1.37 x 48.99, 2.319
    { 190, 12352, 2150, LineMetaDataContent::RapidTransit, Color{0x5092c9} }, // B OSM: 7420701 WD: Q1347825 48.69, 2.071 x 49.01, 2.642
    { 33, 6713, 209, LineMetaDataContent::RapidTransit, Color{0xfd8fb4} }, // S OSM: 7424194 WD: Q695595 48.17, 16.33 x 48.26, 16.4
    { 9, 12384, NoLogo, LineMetaDataContent::Subway, Color{0x5f259f} }, // 4 OSM: 7448424 WD: Q1326504 31.18, 121.4 x 31.26, 121.5
    { 19, 12393, NoLogo, LineMetaDataContent::Subway, Color{0x009fdf} }, // 8 OSM: 7451833 WD: Q1152341 31.06, 121.5 x 31.32, 121.5
    { 123, 12402, NoLogo, LineMetaDataContent::Subway, Color{0x71c5e8} }, // 9 OSM: 7451835 WD: Q1152370 30.99, 121.2 x 31.27, 121.7
    { 15, 12411, NoLogo, LineMetaDataContent::Subway, Color{0x007b5f} }, // 12 OSM: 7451887 WD: Q877180 31.13, 121.3 x 31.28, 121.6
    { 56, 12432, NoLogo, LineMetaDataContent::Subway, Color{0xef95cf} }, // 13 OSM: 7451890 WD: Q607539 31.17, 121.3 x 31.25, 121.6
    { 63, 12442, NoLogo, LineMetaDataContent::Subway, Color{0xc1a7e2} }, // 10 OSM: 7452119 WD: Q528209 31.17, 121.3 x 31.36, 121.6
    { 2434, 12452, 6815, LineMetaDataContent::Subway, Color{0xed8000} }, // I2 OSM: 7527498 WD: Q484739 37.44, 126.6 x 37.6, 126.8
    { 316, 12477, 6815, LineMetaDataContent::RapidTransit, Color{0xfda600} }, // U OSM: 7530882 WD: Q491655 37.72, 127 x 37.75, 127.1
    { 37, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x509f22} }, // E OSM: 7531174 37.24, 127.1 x 37.29, 127.2
    { 520, NoLogo, 6815, LineMetaDataContent::RapidTransit, Color{0xb0ce18} }, // W OSM: 7533584 WD: Q3832795 37.58, 127 x 37.66, 127
    { 273, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // Blue OSM: 7548642 41.47, -81.71 x 41.51, -81.54
    { 463, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // Green OSM: 7548643 41.48, -81.71 x 41.51, -81.52
    { 285, NoLogo, 12505, LineMetaDataContent::Subway, Color{0xff0000} }, // Red OSM: 7551457 WD: Q2136023 41.41, -81.84 x 41.53, -81.58
    { 57, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00ff00} }, // 3 OSM: 7560907 51.34, -0.1055 x 51.38, -0.01745
    { 502, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe40053} }, // T2 OSM: 7568737 WD: Q3239070 50.32, 3.511 x 50.46, 3.596
    { 2437, 12528, 12545, LineMetaDataContent::Subway, Color{0xffff00} }, // YL OSM: 7572167 WD: Q4710841 38.79, -77.08 x 39.01, -76.91
    { 2440, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xbcbdc0} }, // Silver OSM: 7572385 40.29, -80.03 x 40.45, -79.99
    { 1640, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // 510 OSM: 7572438 32.54, -117.2 x 32.72, -117
    { 285, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xec1b24} }, // Red OSM: 7574880 40.34, -80.05 x 40.45, -79.99
    { 273, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x77b6e4} }, // Blue OSM: 7575525 40.34, -80.05 x 40.45, -79.99
    { 200, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe40046} }, // T1 OSM: 7580424 WD: Q3239057 50.32, 3.385 x 50.37, 3.523
    { 2454, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x087c4c} }, // TC OSM: 7597545 WD: Q3538439 -34.51, -58.58 x -34.42, -58.48
    { 16, 12566, 6815, LineMetaDataContent::Subway, Color{0x33a23d} }, // 2 OSM: 7625892 WD: Q17501 37.48, 126.8 x 37.57, 127.1
    { 9, 12589, 6815, LineMetaDataContent::Subway, Color{0x289dd5} }, // 4 OSM: 7625893 WD: Q489253 37.3, 126.7 x 37.67, 127.1
    { 372, 12612, NoLogo, LineMetaDataContent::Subway, Color{0x0033cc} }, // L1 OSM: 7627370 WD: Q20685853 36.71, 3.054 x 36.79, 3.138
    { 262, 12624, 5415, LineMetaDataContent::Tramway, Color{0xe3ba12} }, // 51 OSM: 7632520 WD: Q751385 50.78, 4.326 x 50.89, 4.349
    { 970, 12646, 5415, LineMetaDataContent::Tramway, Color{0xe87d0d} }, // 93 OSM: 7632524 WD: Q2845878 50.82, 4.33 x 50.89, 4.372
    { 53, 12668, NoLogo, LineMetaDataContent::Subway, Color{0x008a94} }, // 1 OSM: 7643008 WD: Q21034316 38.02, 46.23 x 38.08, 46.36
    { 16, 12692, 6430, LineMetaDataContent::Subway, Color{0x006abc} }, // 2 OSM: 7660420 WD: Q1771527 56.32, 43.89 x 56.34, 43.97
    { 266, 12711, 12711, LineMetaDataContent::Subway, Color{0xf25e24} }, // M1 OSM: 7664663 WD: Q207287 60.16, 24.74 x 60.21, 25.15
    { 344, 12711, 12711, LineMetaDataContent::Subway, Color{0xf25e24} }, // M2 OSM: 7664664 WD: Q207287 60.16, 24.8 x 60.24, 25.11
    { 2457, 12736, 11011, LineMetaDataContent::Subway, Color{0xae6017} }, // Bakerloo OSM: 7666698 WD: Q19892 51.5, -0.3355 x 51.59, -0.1007
    { 2466, 12762, 11011, LineMetaDataContent::Subway, Color{0xf4a9be} }, // Hammersmith & City OSM: 7666927 WD: Q211270 51.49, -0.2269 x 51.54, 0.08088
    { 2485, 12783, 11011, LineMetaDataContent::Subway, Color{0xffd329} }, // Circle OSM: 7671007 WD: Q210321 51.49, -0.2269 x 51.53, -0.07523
    { 2492, 12807, 11011, LineMetaDataContent::Subway, Color{0x93ceba} }, // Waterloo & City OSM: 7672075 WD: Q207699 51.5, -0.1142 x 51.51, -0.09074
    { 2508, 12828, 11011, LineMetaDataContent::Subway, Color{0x949699} }, // Jubilee OSM: 7673326 WD: Q961290 51.5, -0.303 x 51.62, 0.01165
    { 2516, 12853, 11011, LineMetaDataContent::Subway, Color{0x91005a} }, // Metropolitan OSM: 7673626 WD: Q19891 51.51, -0.6112 x 51.71, -0.0757
    { 2529, 12883, 11011, LineMetaDataContent::Subway, Color{0x00a166} }, // District OSM: 7677096 WD: Q211265 51.42, -0.3016 x 51.56, 0.2526
    { 53, 12909, 12909, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 7683834 WD: Q239927 37.5, 14.98 x 37.54, 15.1
    { 53, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0000ff} }, // 1 OSM: 7684062 WD: Q6553099 19.09, 72.82 x 19.13, 72.91
    { 57, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x00af23} }, // 3 OSM: 7686574 WD: Q5017776 30.05, 31.25 x 30.15, 31.43
    { 2538, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xdc241f} }, // NSL OSM: 7695961 WD: Q759229 1.27, 103.7 x 1.45, 103.9
    { 53, 12943, 12943, LineMetaDataContent::Subway, Color{0xffa500} }, // 1 OSM: 7702663 WD: Q389415 34.39, 132.4 x 34.48, 132.5
    { 388, 12959, 12986, LineMetaDataContent::Subway, Color{0x0077cc} }, // H OSM: 7702769 WD: Q1073881 33.59, 130.4 x 33.63, 130.4
    { 2542, 13015, 11011, LineMetaDataContent::Subway, Color{0x094fa3} }, // Piccadilly OSM: 7702940 WD: Q207689 51.46, -0.4877 x 51.65, -0.09515
    { 2553, 13043, 11011, LineMetaDataContent::Subway, Color{0x000000} }, // Northern OSM: 7702944 WD: Q214793 51.4, -0.2756 x 51.65, -0.08677
    { 430, 13069, 12986, LineMetaDataContent::Subway, Color{0xff4500} }, // K OSM: 7703353 WD: Q908188 33.58, 130.3 x 33.6, 130.4
    { 2562, 13092, 13122, LineMetaDataContent::Subway, Color{0xc61094} }, // MM OSM: 7703640 WD: Q852314 35.44, 139.6 x 35.47, 139.7
    { 26, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x313495} }, // 16 OSM: 7704225 52.38, 16.91 x 52.46, 17
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x38ab43} }, // 6 OSM: 7705201 52.38, 16.83 x 52.41, 17
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe7212a} }, // 8 OSM: 7705202 52.38, 16.88 x 52.41, 17
    { 53, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xee3c3c} }, // 1 OSM: 7705626 WD: Q2607679 29.55, 52.45 x 29.69, 52.6
    { 53, NoLogo, 13157, LineMetaDataContent::Subway, Color{0x008033} }, // 1 OSM: 7705633 WD: Q104230289 32.49, 51.53 x 32.84, 51.75
    { 40, 13180, 13204, LineMetaDataContent::Subway, Color{0x6a00ff} }, // 7 OSM: 7705644 WD: Q20110124 35.67, 51.37 x 35.75, 51.49
    { 9, 13226, 13204, LineMetaDataContent::Subway, Color{0xffff00} }, // 4 OSM: 7705669 WD: Q20110121 35.69, 51.3 x 35.72, 51.5
    { 2565, 13250, 6815, LineMetaDataContent::RapidTransit, Color{0x8652a1} }, // BGL OSM: 7705740 WD: Q87056 35.16, 128.9 x 35.27, 129
    { 2569, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x43b02a} }, // THZ1 OSM: 7708095 23.1, 113.3 x 23.11, 113.4
    { 53, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 7712343 WD: Q25420888 8.962, -79.55 x 9.065, -79.51
    { 430, 13272, 13314, LineMetaDataContent::Subway, Color{0xffc0cb} }, // K OSM: 7712576 WD: Q1078347 35.2, 136.9 x 35.2, 136.9
    { 330, NoLogo, 13347, LineMetaDataContent::RapidTransit, Color{0x00561b} }, // R OSM: 7712694 WD: Q7360056 34.68, 135.3 x 34.72, 135.3
    { 326, 13378, 13347, LineMetaDataContent::RapidTransit, Color{0x07502b} }, // P OSM: 7712875 WD: Q7230715 34.64, 135.2 x 34.7, 135.2
    { 430, 13404, 13347, LineMetaDataContent::Subway, Color{0x267dce} }, // K OSM: 7712969 WD: Q844019 34.65, 135.1 x 34.69, 135.2
    { 9, 13426, NoLogo, LineMetaDataContent::Subway, Color{0xdc241f} }, // 4 OSM: 7713538 WD: Q1004293 22.52, 114 x 22.73, 114.1
    { 123, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf04723} }, // 9 OSM: 7715858 52.37, 16.9 x 52.41, 16.95
    { 344, 13449, 13477, LineMetaDataContent::Subway, Color{0x009a4c} }, // M2 OSM: 7719078 WD: Q1880934 41.01, 28.95 x 41.14, 29.03
    { 8, 13501, 13477, LineMetaDataContent::Subway, Color{0xe91e76} }, // M4 OSM: 7719080 WD: Q1880989 40.88, 29.02 x 41, 29.25
    { 266, 13529, 13477, LineMetaDataContent::Subway, Color{0xe32726} }, // M1 OSM: 7719081 WD: Q6048705 40.98, 28.82 x 41.05, 28.95
    { 347, 13557, 13477, LineMetaDataContent::Subway, Color{0x00a8e1} }, // M3 OSM: 7719082 WD: Q1880963 41.03, 28.79 x 41.11, 28.84
    { 29, 13585, 13477, LineMetaDataContent::Subway, Color{0xcaaa79} }, // M6 OSM: 7719783 WD: Q16949744 41.08, 29.01 x 41.09, 29.05
    { 33, 13613, 13347, LineMetaDataContent::Subway, Color{0x00ae8e} }, // S OSM: 7720729 WD: Q1066548 34.66, 135 x 34.76, 135.2
    { 269, 13636, 13649, LineMetaDataContent::Subway, Color{0x0000ff} }, // MRT Blue OSM: 7725030 WD: Q2486364 13.71, 100.4 x 13.81, 100.6
    { 1423, 13672, 13649, LineMetaDataContent::Subway, Color{0x800080} }, // MRT Purple OSM: 7725058 WD: Q6584549 13.81, 100.4 x 13.89, 100.5
    { 372, 13687, 13710, LineMetaDataContent::Subway, Color{0x228b22} }, // L1 OSM: 7727216 WD: Q5985884 -12.21, -77.01 x -11.96, -76.93
    { 666, 13739, 6815, LineMetaDataContent::Subway, Color{0xc82127} }, // 306 OSM: 7728256 WD: Q20388 37.29, 127 x 37.5, 127.1
    { 2574, NoLogo, 13772, LineMetaDataContent::Subway, Color{0x2e8b57} }, // 仙台市南北線 (Sendai Namboku Line) OSM: 7732249 WD: Q908156 38.21, 140.9 x 38.32, 140.9
    { 2615, NoLogo, 13772, LineMetaDataContent::Subway, Color{0x00bfff} }, // 仙台市東西線 (Sendai Tozai Line) OSM: 7732250 WD: Q7450186 38.24, 140.8 x 38.26, 140.9
    { 190, 13800, 13122, LineMetaDataContent::Subway, Color{0x005ba5} }, // B OSM: 7732280 WD: Q841360 35.4, 139.5 x 35.57, 139.6
    { 487, 13847, 13122, LineMetaDataContent::Subway, Color{0x048d58} }, // G OSM: 7732283 WD: Q910329 35.51, 139.5 x 35.56, 139.6
    { 53, 13895, NoLogo, LineMetaDataContent::Subway, Color{0xcc0000} }, // 1 OSM: 7732970 WD: Q4215382 -33.46, -70.72 x -33.41, -70.55
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xffbe2e} }, // 2 OSM: 7732971 WD: Q11690005 -33.54, -70.66 x -33.38, -70.64
    { 9, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x292d91} }, // 4 OSM: 7732972 WD: Q9025952 -33.61, -70.6 x -33.42, -70.57
    { 2654, 13920, NoLogo, LineMetaDataContent::Subway, Color{0x0099ff} }, // 4A OSM: 7732973 WD: Q11690009 -33.54, -70.67 x -33.52, -70.6
    { 6, 13946, NoLogo, LineMetaDataContent::Subway, Color{0x006633} }, // 5 OSM: 7732974 WD: Q9025969 -33.53, -70.76 x -33.44, -70.6
    { 27, 13971, NoLogo, LineMetaDataContent::Subway, Color{0x8e16a1} }, // 6 OSM: 7732978 WD: Q5986809 -33.48, -70.7 x -33.42, -70.6
    { 57, 13996, 6316, LineMetaDataContent::Subway, Color{0x9a9940} }, // 3 OSM: 7733214 WD: Q50741 48.86, 2.28 x 48.9, 2.418
    { 53, 14014, 14014, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 7733917 WD: Q494079 55.74, 49.08 x 55.86, 49.22
    { 53, 3903, 14035, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 7733918 WD: Q594532 54.98, 82.89 x 55.06, 82.94
    { 16, 4245, 14035, LineMetaDataContent::Subway, Color{0x008000} }, // 2 OSM: 7733919 WD: Q2711371 55.03, 82.9 x 55.04, 82.98
    { 53, 14062, 14062, LineMetaDataContent::Subway, Color{0x1c8c3a} }, // 1 OSM: 7733920 WD: Q750441 56.8, 60.6 x 56.9, 60.63
    { 2657, 14081, NoLogo, LineMetaDataContent::Subway, Color{0x076c57} }, // Verde OSM: 7733971 WD: Q10318743 -15.84, -48.12 x -15.79, -47.88
    { 2663, 14100, NoLogo, LineMetaDataContent::Subway, Color{0xeb9710} }, // Laranja OSM: 7733972 WD: Q10318700 -15.87, -48.09 x -15.79, -47.88
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // 2 OSM: 7734060 WD: Q25421356 18.48, -69.97 x 18.51, -69.86
    { 53, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0000ff} }, // 1 OSM: 7734061 WD: Q25421357 18.45, -69.93 x 18.55, -69.9
    { 53, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // 1 OSM: 7734069 10.62, -71.67 x 10.64, -71.62
    { 53, 14124, 14156, LineMetaDataContent::Subway, Color{0x0000ff} }, // 1 OSM: 7734077 WD: Q28604 53.85, 27.47 x 53.95, 27.69
    { 16, 14177, 14156, LineMetaDataContent::Subway, Color{0xff0000} }, // 2 OSM: 7734078 WD: Q2638932 53.86, 27.43 x 53.91, 27.67
    { 344, NoLogo, 14210, LineMetaDataContent::Subway, Color{0x0000ff} }, // M2 OSM: 7734092 WD: Q12295702 42.66, 23.28 x 42.74, 23.32
    { 266, NoLogo, 14210, LineMetaDataContent::Subway, Color{0xff0000} }, // M1 OSM: 7734093 WD: Q20020737 42.63, 23.26 x 42.74, 23.38
    { 2671, NoLogo, 14231, LineMetaDataContent::Subway, Color{0xdf096f} }, // Vermelha OSM: 7734163 WD: Q163215 38.73, -9.154 x 38.78, -9.1
    { 2680, NoLogo, 14231, LineMetaDataContent::Subway, Color{0xf4bc18} }, // Amarela OSM: 7734164 WD: Q1826607 38.71, -9.173 x 38.79, -9.145
    { 2688, NoLogo, 14231, LineMetaDataContent::Subway, Color{0x5e82c4} }, // Azul OSM: 7734165 WD: Q1826609 38.71, -9.224 x 38.76, -9.122
    { 2657, NoLogo, 14231, LineMetaDataContent::Subway, Color{0x2f9b9c} }, // Verde OSM: 7734166 WD: Q1826613 38.71, -9.169 x 38.76, -9.133
    { 2693, 14261, 14261, LineMetaDataContent::Subway, Color{0xff6600} }, // Subway OSM: 7734173 WD: Q506290 55.85, -4.312 x 55.88, -4.253
    { 53, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 7734180 WD: Q4504162 48.48, 34.93 x 48.48, 35.02
    { 491, 14280, 12986, LineMetaDataContent::Subway, Color{0x008000} }, // N OSM: 7734239 WD: Q1039166 33.55, 130.3 x 33.59, 130.4
    { 285, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xcc0000} }, // Red OSM: 7734262 WD: Q1369034 24.98, 55.09 x 25.27, 55.39
    { 463, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x00cc00} }, // Green OSM: 7734263 WD: Q1544621 25.22, 55.29 x 25.28, 55.4
    { 33, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xffc0cb} }, // S OSM: 7734268 WD: Q16240707 21.33, 39.87 x 21.42, 39.98
    { 53, 14307, 14331, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 7734272 WD: Q1473986 43.23, 76.87 x 43.27, 76.95
    { 16, NoLogo, 14353, LineMetaDataContent::Subway, Color{0x008000} }, // 2 OSM: 7734279 WD: Q712790 39.03, 125.7 x 39.07, 125.8
    { 53, NoLogo, 14353, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 7734280 WD: Q711112 39.01, 125.7 x 39.07, 125.8
    { 53, 14385, 13204, LineMetaDataContent::Subway, Color{0xff0f04} }, // 1 OSM: 7735256 WD: Q20110118 35.4, 51.15 x 35.8, 51.44
    { 53, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x4caf50} }, // 1 OSM: 7740660 WD: Q19856263 26.5, 106.6 x 26.66, 106.7
    { 2700, 14409, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7b4339} }, // ODEA OSM: 7747967 WD: Q93386 48.88, 2.345 x 48.94, 2.358
    { 2705, 14409, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7b4339} }, // ADEO OSM: 7747968 WD: Q93386 48.88, 2.345 x 48.94, 2.358
    { 2710, 14409, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7b4339} }, // VOBA OSM: 7747969 WD: Q93386 48.88, 2.345 x 48.94, 2.358
    { 2715, 14409, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7b4339} }, // AVOL OSM: 7747970 WD: Q93386 48.88, 2.345 x 48.94, 2.358
    { 2720, 14409, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7b4339} }, // APOR OSM: 7747972 WD: Q93386 48.88, 2.345 x 48.94, 2.358
    { 200, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x64318f} }, // T1 OSM: 7758458 WD: Q50319281 49.6, 6.119 x 49.64, 6.176
    { 57, 14432, 13204, LineMetaDataContent::Subway, Color{0x00aad4} }, // 3 OSM: 7770934 WD: Q20110120 35.63, 51.34 x 35.8, 51.52
    { 2725, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00afad} }, // B-L OSM: 7772561 51.46, -0.08835 x 51.51, -0.009433
    { 2729, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00afad} }, // B-WA OSM: 7772562 51.49, -0.08835 x 51.51, 0.07755
    { 2734, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00afad} }, // S-L OSM: 7772563 51.46, -0.02287 x 51.54, -0.004134
    { 2738, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00afad} }, // TG-B OSM: 7772565 51.51, -0.07453 x 51.51, 0.07181
    { 2743, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00afad} }, // SI-WA OSM: 7772566 51.49, -0.01336 x 51.55, 0.07755
    { 347, NoLogo, 6360, LineMetaDataContent::Subway, Color{0xbc1725} }, // M3 OSM: 7772846 WD: Q2735258 44.41, 25.98 x 44.44, 26.21
    { 266, NoLogo, 6360, LineMetaDataContent::Subway, Color{0xffff00} }, // M1 OSM: 7772847 WD: Q2056949 44.41, 26.04 x 44.45, 26.2
    { 67, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xb56631} }, // 21 OSM: 7779520 59.34, 18.1 x 59.36, 18.23
    { 372, 14456, 14486, LineMetaDataContent::Subway, Color{0x008000} }, // L1 OSM: 7781389 WD: Q2668472 37.33, -6.052 x 37.38, -5.934
    { 376, 14520, 14539, LineMetaDataContent::Subway, Color{0x0000ff} }, // L2 OSM: 7781442 WD: Q5986162 36.68, -4.458 x 36.71, -4.432
    { 372, 14573, 14539, LineMetaDataContent::Subway, Color{0xff0000} }, // L1 OSM: 7781445 WD: Q5392889 36.71, -4.496 x 36.72, -4.432
    { 344, 14592, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe93324} }, // M2 OSM: 7781535 WD: Q11180785 39.58, 2.654 x 39.63, 2.725
    { 266, 14611, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf1b03e} }, // M1 OSM: 7781536 WD: Q5985887 39.58, 2.648 x 39.63, 2.673
    { 16, NoLogo, 14630, LineMetaDataContent::Subway, Color{0x008000} }, // 2 OSM: 7786077 WD: Q2210273 41.72, 44.72 x 41.73, 44.8
    { 53, NoLogo, 14630, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 7786078 WD: Q340562 41.68, 44.78 x 41.79, 44.87
    { 37, 14653, 14653, LineMetaDataContent::RapidTransit, Color{0xffff00} }, // E OSM: 7786518 WD: Q1714062 50.4, 30.4 x 50.5, 30.64
    { 16, 14683, 14703, LineMetaDataContent::Subway, Color{0xed1d24} }, // 2 OSM: 7786752 WD: Q3238802 50.62, 2.974 x 50.74, 3.181
    { 53, 14729, 14703, LineMetaDataContent::Subway, Color{0xffd400} }, // 1 OSM: 7786754 WD: Q3238658 50.61, 3.036 x 50.64, 3.143
    { 2750, 14749, 14749, LineMetaDataContent::Subway, Color{0x90ee90} }, // 2B OSM: 7792472 WD: Q213271 40.38, 49.85 x 40.38, 49.87
    { 53, NoLogo, 14749, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 7792473 WD: Q3832654 40.37, 49.83 x 40.42, 49.95
    { 16, NoLogo, 14749, LineMetaDataContent::Subway, Color{0x008000} }, // 2 OSM: 7792474 WD: Q3832656 40.37, 49.8 x 40.43, 49.95
    { 57, NoLogo, 14749, LineMetaDataContent::Subway, Color{0x800080} }, // 3 OSM: 7792475 WD: Q25547220 40.4, 49.79 x 40.42, 49.82
    { 53, NoLogo, 6815, LineMetaDataContent::Subway, Color{0x007448} }, // 1 OSM: 7792528 WD: Q200310 36.32, 127.3 x 36.39, 127.5
    { 53, NoLogo, 6815, LineMetaDataContent::Subway, Color{0x009088} }, // 1 OSM: 7792534 WD: Q626996 35.11, 126.8 x 35.16, 126.9
    { 1768, NoLogo, 209, LineMetaDataContent::RapidTransit, Color{0xf58220} }, // S19 OSM: 7800298 WD: Q25352054 47.37, 8.227 x 47.6, 8.787
    { 2753, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffd503} }, // U29 OSM: 7801954 48.77, 9.122 x 48.78, 9.182
    { 2757, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x69be51} }, // U34 OSM: 7801962 48.76, 9.143 x 48.78, 9.178
    { 2761, NoLogo, 209, LineMetaDataContent::RapidTransit, Color{0xf17f1a} }, // S 9 OSM: 7805411 WD: Q63217750 51.45, 11.98 x 51.52, 12.64
    { 368, 14770, 14793, LineMetaDataContent::Subway, Color{0x824100} }, // L4 OSM: 7827780 WD: Q1826677 40.42, -3.716 x 40.48, -3.635
    { 372, 14813, 14793, LineMetaDataContent::Subway, Color{0x67c0dd} }, // L1 OSM: 7831481 WD: Q1826675 40.36, -3.705 x 40.48, -3.591
    { 16, 14836, 13204, LineMetaDataContent::Subway, Color{0x003380} }, // 2 OSM: 7832325 WD: Q20110119 35.69, 51.33 x 35.74, 51.55
    { 1859, 14860, 14793, LineMetaDataContent::Subway, Color{0x015396} }, // L10 OSM: 7834660 WD: Q1760090 40.34, -3.813 x 40.56, -3.611
    { 1577, NoLogo, 14884, LineMetaDataContent::Subway, Color{0x7fffd4} }, // I OSM: 7834960 WD: Q55810159 9.95, 76.28 x 10.11, 76.35
    { 1250, 14905, 14793, LineMetaDataContent::Subway, Color{0xff0080} }, // L8 OSM: 7837169 WD: Q1475527 40.44, -3.692 x 40.49, -3.572
    { 498, 14928, 14793, LineMetaDataContent::Subway, Color{0x9c3293} }, // L9 OSM: 7837206 WD: Q1759707 40.3, -3.721 x 40.5, -3.447
    { 2765, 14951, NoLogo, LineMetaDataContent::Subway, Color{0x996633} }, // Z OSM: 7837591 WD: Q126484 40.68, -74.01 x 40.72, -73.8
    { 1238, 14977, 14793, LineMetaDataContent::Subway, Color{0x96bf0d} }, // L5 OSM: 7838614 WD: Q1568028 40.38, -3.769 x 40.46, -3.588
    { 266, 15000, 15000, LineMetaDataContent::Subway, Color{0xffa500} }, // M1 OSM: 7838818 WD: Q1577356 36.98, 35.26 x 37.05, 35.34
    { 380, 15021, 14793, LineMetaDataContent::Subway, Color{0xffdf00} }, // L3 OSM: 7838838 WD: Q1826673 40.34, -3.719 x 40.43, -3.693
    { 376, 15044, 14793, LineMetaDataContent::Subway, Color{0xfb0f0c} }, // L2 OSM: 7838963 WD: Q1826679 40.42, -3.71 x 40.45, -3.602
    { 1246, 15067, 14793, LineMetaDataContent::Subway, Color{0xed7b24} }, // L7 OSM: 7840623 WD: Q1826683 40.42, -3.727 x 40.5, -3.524
    { 330, 15090, 14793, LineMetaDataContent::Subway, Color{0xffffff} }, // R OSM: 7840747 WD: Q1496137 40.42, -3.72 x 40.42, -3.71
    { 1427, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xe542de} }, // Purple OSM: 7841332 WD: Q7261433 12.91, 77.47 x 12.99, 77.66
    { 2305, 15112, 14793, LineMetaDataContent::Subway, Color{0xa49a00} }, // L12 OSM: 7841412 WD: Q1558864 40.28, -3.876 x 40.35, -3.71
    { 53, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xf03b3f} }, // 1 OSM: 7841834 WD: Q11085985 31.44, 120.3 x 31.68, 120.3
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x00a43c} }, // 2 OSM: 7841837 WD: Q11085986 31.55, 120.2 x 31.61, 120.5
    { 53, NoLogo, 15136, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 7841839 WD: Q30326155 38.04, 114.4 x 38.16, 114.6
    { 57, NoLogo, 15136, LineMetaDataContent::Subway, Color{0x0000ff} }, // 3 OSM: 7841854 WD: Q30326157 38, 114.4 x 38.08, 114.7
    { 53, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x00b04f} }, // 1 OSM: 7841881 WD: Q17498765 22.82, 108.2 x 22.84, 108.4
    { 1242, 15159, 14793, LineMetaDataContent::Subway, Color{0x939393} }, // L6 OSM: 7842094 WD: Q514227 40.39, -3.745 x 40.45, -3.669
    { 1863, 15182, 14793, LineMetaDataContent::Subway, Color{0x006400} }, // L11 OSM: 7842127 WD: Q608251 40.36, -3.778 x 40.39, -3.718
    { 463, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x009933} }, // Green OSM: 7842288 WD: Q17054000 12.86, 77.5 x 13.05, 77.58
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xc32a05} }, // 2 OSM: 7844345 WD: Q11149384 36.06, 120.3 x 36.17, 120.5
    { 16, NoLogo, 15206, LineMetaDataContent::Subway, Color{0x53b848} }, // 2 OSM: 7845614 WD: Q20647027 12.99, 80.19 x 13.09, 80.27
    { 169, 15229, NoLogo, LineMetaDataContent::Subway, Color{0xc09c83} }, // 17 OSM: 7845847 WD: Q6553108 31.1, 121 x 31.2, 121.3
    { 16, 15250, 6815, LineMetaDataContent::Subway, Color{0x18be00} }, // 2 OSM: 7845969 WD: Q200332 35.83, 128.4 x 35.87, 128.8
    { 53, 15273, 6815, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 7845971 WD: Q200331 35.8, 128.5 x 35.89, 128.7
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xffff00} }, // 2 OSM: 7846276 WD: Q15908164 34.66, 113.6 x 34.87, 113.7
    { 2767, 15296, 15320, LineMetaDataContent::RapidTransit, Color{0x4682b4} }, // ML1 OSM: 7849381 WD: Q2058921 40.48, -3.669 x 40.51, -3.651
    { 2771, 15346, 15320, LineMetaDataContent::RapidTransit, Color{0x660066} }, // ML2 OSM: 7853073 WD: Q3832710 40.4, -3.812 x 40.45, -3.775
    { 379, 15370, 15320, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // ML3 OSM: 7853483 WD: Q3832709 40.39, -3.905 x 40.41, -3.775
    { 2775, 15394, 6815, LineMetaDataContent::Subway, Color{0x6fa0ce} }, // I1 OSM: 7854149 WD: Q487733 37.38, 126.6 x 37.57, 126.7
    { 57, 15419, 5415, LineMetaDataContent::Tramway, Color{0xb5ba05} }, // 3 OSM: 7857250 WD: Q1888831 50.81, 4.336 x 50.9, 4.377
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x02406f} }, // 2 OSM: 7857258 WD: Q10318650 -12.98, -38.48 x -12.9, -38.34
    { 2778, 10346, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa6c82b} }, // R2Nord OSM: 7867878 WD: Q1880046 41.3, 2.052 x 41.77, 2.673
    { 1705, 15440, NoLogo, LineMetaDataContent::RapidTransit, Color{0xba55d3} }, // R7 OSM: 7867903 WD: Q1647981 41.43, 2.115 x 41.51, 2.189
    { 2785, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // B1 OSM: 7868621 WD: Q56067295 40.19, 28.95 x 40.26, 29.12
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xf30215} }, // 2 OSM: 7869228 WD: Q5934457 34.14, 108.9 x 34.38, 108.9
    { 53, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x01abf7} }, // 1 OSM: 7869253 WD: Q14917524 34.27, 108.7 x 34.32, 109.1
    { 57, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xb688a9} }, // 3 OSM: 7869255 WD: Q15927288 34.22, 108.8 x 34.41, 109.1
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xd9001c} }, // 2 OSM: 7869334 WD: Q104231524 -8.111, -35.02 x -8.069, -34.89
    { 53, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xe77405} }, // 1 OSM: 7869352 WD: Q104231463 -8.092, -35 x -8.024, -34.89
    { 2161, 15457, NoLogo, LineMetaDataContent::Subway, Color{0x1a5ba3} }, // Sul OSM: 7869374 WD: Q10329288 -8.168, -34.93 x -8.069, -34.88
    { 2788, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x000000} }, // B2 OSM: 7869622 WD: Q61074931 40.19, 28.87 x 40.22, 29.21
    { 53, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 7871046 WD: Q15303225 34.75, 113.5 x 34.83, 113.8
    { 123, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xb93ff5} }, // 9 OSM: 7871541 WD: Q28441548 34.53, 113.7 x 34.66, 113.9
    { 2791, 15470, NoLogo, LineMetaDataContent::RapidTransit, Color{0x8fbe00} }, // C-10 OSM: 7871793 WD: Q583732 40.4, -4.009 x 40.63, -3.594
    { 469, 15484, NoLogo, LineMetaDataContent::RapidTransit, Color{0x009ad5} }, // C-1 OSM: 7871905 WD: Q3832674 40.4, -3.722 x 40.49, -3.594
    { 2796, 15503, NoLogo, LineMetaDataContent::RapidTransit, Color{0xde0118} }, // C-7 OSM: 7872150 WD: Q8879938 40.38, -3.874 x 40.51, -3.365
    { 285, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // Red OSM: 7874288 WD: Q152039 42.21, -71.14 x 42.4, -71
    { 1313, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff8000} }, // Orange OSM: 7874312 WD: Q152029 42.3, -71.12 x 42.44, -71.06
    { 53, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 1 OSM: 7874579 52.26, 104.3 x 52.29, 104.3
    { 16, 15515, NoLogo, LineMetaDataContent::Subway, Color{0x00afec} }, // 2 OSM: 7875250 WD: Q15919822 28.15, 112.9 x 28.21, 113.1
    { 53, 15545, NoLogo, LineMetaDataContent::Subway, Color{0xe60012} }, // 1 OSM: 7875257 WD: Q15911087 28.06, 113 x 28.27, 113
    { 2800, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 4a OSM: 7875272 52.28, 104.3 x 52.29, 104.4
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 4 OSM: 7875274 52.28, 104.3 x 52.29, 104.4
    { 9, 15575, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7d4697} }, // 4 OSM: 7875301 WD: Q6553125 43.79, 125.3 x 43.91, 125.4
    { 57, 15596, NoLogo, LineMetaDataContent::RapidTransit, Color{0x009943} }, // 3 OSM: 7875360 WD: Q6123656 43.77, 125.3 x 43.91, 125.4
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x4bc7df} }, // 2 OSM: 7875922 52.27, 104.3 x 52.29, 104.3
    { 226, 15617, 15634, LineMetaDataContent::Subway, Color{0x008000} }, // A OSM: 7877753 WD: Q770771 39.91, 32.81 x 39.93, 32.88
    { 266, NoLogo, 15634, LineMetaDataContent::Subway, Color{0xff0000} }, // M1 OSM: 7877773 WD: Q21526526 39.9, 32.69 x 39.97, 32.86
    { 344, NoLogo, 15634, LineMetaDataContent::Subway, Color{0xffff00} }, // M2 OSM: 7877891 WD: Q21526527 39.89, 32.69 x 39.94, 32.86
    { 1360, 15656, 10086, LineMetaDataContent::Subway, Color{0xffa500} }, // O OSM: 7879290 WD: Q7099668 22.62, 120.3 x 22.63, 120.4
    { 330, 15696, 10086, LineMetaDataContent::Subway, Color{0xff0000} }, // R OSM: 7879291 WD: Q7304504 22.56, 120.3 x 22.78, 120.4
    { 57, 15733, 6815, LineMetaDataContent::Subway, Color{0xfe5b10} }, // 3 OSM: 7879839 WD: Q20393 37.48, 126.7 x 37.68, 127.1
    { 57, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x006dbb} }, // 3 OSM: 7883242 WD: Q15907883 36.05, 120.3 x 36.17, 120.4
    { 123, 15756, 6815, LineMetaDataContent::Subway, Color{0xaa9872} }, // 9 OSM: 7883317 WD: Q17503 37.5, 126.8 x 37.58, 127.1
    { 16, 15779, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // 2 OSM: 7883944 WD: Q10946021 29.81, 121.5 x 29.95, 121.7
    { 53, 15800, 2048, LineMetaDataContent::Subway, Color{0xffff00} }, // 1 OSM: 7884489 WD: Q54369 43.65, -79.53 x 43.79, -79.38
    { 53, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 7885089 WD: Q56277837 40.59, 22.93 x 40.65, 22.97
    { 16, 15849, 2048, LineMetaDataContent::Subway, Color{0x008000} }, // 2 OSM: 7885287 WD: Q54371 43.64, -79.54 x 43.73, -79.26
    { 57, NoLogo, 7739, LineMetaDataContent::Subway, Color{0x009651} }, // 3 OSM: 7885547 WD: Q10906683 31.87, 118.7 x 32.17, 118.8
    { 2803, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x77278b} }, // WCE OSM: 7887557 49.13, -123.1 x 49.29, -122.3
    { 2807, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x000000} }, // Conexão Metrô-Aeroporto OSM: 7889062 WD: Q23891467 -29.99, -51.18 x -29.99, -51.18
    { 53, 15888, NoLogo, LineMetaDataContent::Subway, Color{0x008000} }, // 1 OSM: 7889178 WD: Q45668 31.28, 120.5 x 31.33, 120.8
    { 2833, 15898, 15912, LineMetaDataContent::Subway, Color{0x808080} }, // RMGL OSM: 7890003 WD: Q7294170 28.42, 77.09 x 28.5, 77.11
    { 53, 15933, NoLogo, LineMetaDataContent::Subway, Color{0xfec04f} }, // 1 OSM: 7890223 WD: Q5985916 25.68, -100.4 x 25.76, -100.2
    { 16, 15951, NoLogo, LineMetaDataContent::Subway, Color{0x6bc069} }, // 2 OSM: 7890224 WD: Q2842186 25.67, -100.3 x 25.77, -100.3
    { 16, 15969, 15989, LineMetaDataContent::Subway, Color{0x0066a1} }, // 2 OSM: 7890240 WD: Q6379343 38.9, 121.5 x 38.97, 121.7
    { 33, 2916, NoLogo, LineMetaDataContent::Subway, Color{0x808183} }, // S OSM: 7893704 WD: Q126772 40.58, -73.84 x 40.61, -73.81
    { 33, 2916, NoLogo, LineMetaDataContent::Subway, Color{0x808183} }, // S OSM: 7894362 WD: Q126725 40.66, -73.96 x 40.68, -73.96
    { 53, NoLogo, 16022, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 7894481 WD: Q5934658 41.76, 123.2 x 41.81, 123.5
    { 16, NoLogo, 16022, LineMetaDataContent::Subway, Color{0xffff00} }, // 2 OSM: 7894597 WD: Q5933526 41.63, 123.4 x 41.96, 123.5
    { 53, 16058, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 7895188 WD: Q15941872 25.99, 119.3 x 26.15, 119.4
    { 56, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x8e8c13} }, // 13 OSM: 7895357 WD: Q6553065 23.08, 113.4 x 23.14, 113.6
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0070ff} }, // 2 OSM: 7898299 WD: Q56277844 40.57, 22.93 x 40.65, 22.97
    { 27, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xffc0cb} }, // 6 OSM: 7898711 WD: Q30603104 19.12, 72.82 x 19.14, 72.94
    { 57, 16077, 15989, LineMetaDataContent::Subway, Color{0x008000} }, // 3 OSM: 7908058 WD: Q5976456 38.92, 121.6 x 39.15, 122
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0000ff} }, // 2 OSM: 7909740 WD: Q11087464 25.03, 102.7 x 25.12, 102.8
    { 53, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xdb372b} }, // 1 OSM: 7909748 WD: Q11087462 24.83, 102.7 x 25.03, 102.9
    { 59, 16097, 7739, LineMetaDataContent::Subway, Color{0x4bbbb4} }, // S1 OSM: 7913272 WD: Q10946118 31.72, 118.8 x 31.97, 118.9
    { 157, 16118, 7739, LineMetaDataContent::Subway, Color{0xda60cd} }, // S3 OSM: 7913273 WD: Q10945835 31.91, 118.5 x 31.99, 118.8
    { 53, 16139, NoLogo, LineMetaDataContent::Subway, Color{0x00ab39} }, // 1 OSM: 7913936 WD: Q842103 22.53, 113.8 x 22.65, 114.1
    { 226, NoLogo, 6815, LineMetaDataContent::Subway, Color{0x3681b7} }, // A OSM: 7919001 WD: Q487643 37.44, 126.4 x 37.6, 127
    { 19, 16162, 6815, LineMetaDataContent::Subway, Color{0xea545d} }, // 8 OSM: 7919019 WD: Q45086 37.43, 127.1 x 37.55, 127.2
    { 27, 16185, 6815, LineMetaDataContent::Subway, Color{0x9e4510} }, // 6 OSM: 7919154 WD: Q92549 37.53, 126.9 x 37.62, 127.1
    { 310, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x00a651} }, // M OSM: 7919553 WD: Q805751 39.29, -76.78 x 39.41, -76.59
    { 2722, 16208, 12545, LineMetaDataContent::Subway, Color{0xe89038} }, // OR OSM: 7919601 WD: Q4715683 38.88, -77.28 x 38.95, -76.87
    { 2838, 16225, 12545, LineMetaDataContent::Subway, Color{0xe94333} }, // RD OSM: 7919630 WD: Q2193330 38.89, -77.17 x 39.12, -76.99
    { 2841, 16239, 12545, LineMetaDataContent::Subway, Color{0xc0c0c0} }, // SV OSM: 7919737 WD: Q4711838 38.88, -77.34 x 38.95, -76.84
    { 2844, 16256, 12545, LineMetaDataContent::Subway, Color{0x0000ff} }, // BL OSM: 7919758 WD: Q2602185 38.77, -77.17 x 38.9, -76.84
    { 329, 16271, 12545, LineMetaDataContent::Subway, Color{0x008000} }, // GR OSM: 7919786 WD: Q4715207 38.83, -77.03 x 39.01, -76.91
    { 40, 16287, 6815, LineMetaDataContent::Subway, Color{0x54640d} }, // 7 OSM: 7922930 WD: Q22910 37.48, 126.7 x 37.7, 127.1
    { 463, NoLogo, 16310, LineMetaDataContent::Subway, Color{0x62bb46} }, // Green OSM: 7924527 WD: Q55734262 25.68, -80.32 x 25.85, -80.2
    { 1313, NoLogo, 16310, LineMetaDataContent::Subway, Color{0xf78f1e} }, // Orange OSM: 7924528 WD: Q55734269 25.68, -80.31 x 25.81, -80.2
    { 1093, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009832} }, // D OSM: 7925628 WD: Q3239098 48.57, 7.691 x 48.59, 7.816
    { 221, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf68712} }, // C OSM: 7925656 WD: Q2321331 48.55, 7.735 x 48.59, 7.773
    { 27, 16349, 11693, LineMetaDataContent::Subway, Color{0x0078ad} }, // 6 OSM: 7927182 WD: Q668977 50.83, 4.321 x 50.9, 4.37
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff7000} }, // 2 OSM: 7927236 WD: Q5017773 29.98, 31.2 x 30.12, 31.25
    { 16, 16370, 16391, LineMetaDataContent::Subway, Color{0xafc805} }, // 2 OSM: 7927568 WD: Q5986160 10.5, -66.92 x 10.5, -66.92
    { 380, 16429, 16391, LineMetaDataContent::Subway, Color{0x0887ff} }, // L3 OSM: 7927573 WD: Q21346332 10.43, -66.94 x 10.5, -66.88
    { 2847, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // L1B OSM: 7928119 WD: Q107191177 37.99, -1.187 x 38.01, -1.161
    { 53, 16450, NoLogo, LineMetaDataContent::Subway, Color{0xe86495} }, // 1 OSM: 7935038 WD: Q2295084 19.4, -99.2 x 19.43, -99.07
    { 221, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // C OSM: 7935053 33.89, -118.4 x 33.93, -118.1
    { 438, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffd700} }, // L OSM: 7935245 34.03, -118.2 x 34.15, -117.9
    { 1093, 16471, NoLogo, LineMetaDataContent::Subway, Color{0x800080} }, // D OSM: 7935318 WD: Q3916689 34.05, -118.4 x 34.07, -118.2
    { 9, 16496, NoLogo, LineMetaDataContent::Subway, Color{0x80ffff} }, // 4 OSM: 7935352 WD: Q2837181 19.4, -99.12 x 19.49, -99.1
    { 6, 16517, NoLogo, LineMetaDataContent::Subway, Color{0xffff11} }, // 5 OSM: 7935366 WD: Q1152238 19.41, -99.15 x 19.5, -99.07
    { 15, 16538, NoLogo, LineMetaDataContent::Subway, Color{0xb69764} }, // 12 OSM: 7935368 WD: Q5985548 19.28, -99.2 x 19.38, -99.01
    { 40, 16560, NoLogo, LineMetaDataContent::Subway, Color{0xff8000} }, // 7 OSM: 7935375 WD: Q929645 19.36, -99.2 x 19.51, -99.18
    { 226, 16581, NoLogo, LineMetaDataContent::Subway, Color{0xa3277d} }, // A OSM: 7935382 WD: Q3239049 19.35, -99.08 x 19.42, -98.96
    { 19, 16602, NoLogo, LineMetaDataContent::Subway, Color{0x30c090} }, // 8 OSM: 7935426 WD: Q1149545 19.34, -99.14 x 19.45, -99.05
    { 190, 16623, NoLogo, LineMetaDataContent::Subway, Color{0x408080} }, // B OSM: 7935433 WD: Q3239062 19.43, -99.16 x 19.53, -99.03
    { 16, 16644, NoLogo, LineMetaDataContent::Subway, Color{0x0080ff} }, // 2 OSM: 7935439 WD: Q1152993 19.34, -99.22 x 19.46, -99.13
    { 123, 16665, NoLogo, LineMetaDataContent::Subway, Color{0x804000} }, // 9 OSM: 7935444 WD: Q3239046 19.4, -99.19 x 19.42, -99.06
    { 57, 16686, NoLogo, LineMetaDataContent::Subway, Color{0xae9d27} }, // 3 OSM: 7935449 WD: Q945935 19.32, -99.18 x 19.5, -99.12
    { 27, 16707, NoLogo, LineMetaDataContent::Subway, Color{0xe00050} }, // 6 OSM: 7935454 WD: Q3238990 19.48, -99.2 x 19.51, -99.1
    { 2851, 16728, NoLogo, LineMetaDataContent::Subway, Color{0xdb5450} }, // PATCO OSM: 7939445 WD: Q2043730 39.83, -75.17 x 39.96, -75
    { 1954, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x233e99} }, // WTR OSM: 7940934 WD: Q7986701 39.95, -75.18 x 40.26, -74.82
    { 2447, NoLogo, 16743, LineMetaDataContent::Subway, Color{0xef3941} }, // NWK–WTC OSM: 7943869 WD: Q2673356 40.71, -74.16 x 40.74, -74.01
    { 2857, NoLogo, 16743, LineMetaDataContent::Subway, Color{0x009e58} }, // HOB–WTC OSM: 7943874 WD: Q2789573 40.71, -74.04 x 40.74, -74.01
    { 2867, NoLogo, 16743, LineMetaDataContent::Subway, Color{0x0082c6} }, // HOB–33 OSM: 7943885 WD: Q2319374 40.73, -74.03 x 40.75, -73.99
    { 2876, NoLogo, 16743, LineMetaDataContent::Subway, Color{0xfdb827} }, // JSQ–33 OSM: 7943962 WD: Q4993433 40.72, -74.06 x 40.75, -73.99
    { 53, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xe77405} }, // 1 OSM: 7944061 WD: Q2333617 -22.98, -43.24 x -22.9, -43.17
    { 53, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 7948593 WD: Q10921992 45.6, 126.6 x 45.79, 126.7
    { 57, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xffa500} }, // 3 OSM: 7949019 WD: Q10921994 45.69, 126.5 x 45.7, 126.6
    { 53, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xc51623} }, // 1 OSM: 7949047 WD: Q10916959 31.69, 117.3 x 31.89, 117.3
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x343fcd} }, // 2 OSM: 7949335 WD: Q10916960 31.85, 117.1 x 31.87, 117.4
    { 53, 16752, NoLogo, LineMetaDataContent::Subway, Color{0xe50011} }, // 1 OSM: 7949339 WD: Q15913092 43.79, 125.3 x 43.95, 125.3
    { 2885, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xf58220} }, // BSL OSM: 7950670 WD: Q837022 39.91, -75.17 x 40.04, -75.14
    { 53, NoLogo, 15989, LineMetaDataContent::Subway, Color{0x008000} }, // 1 OSM: 7951024 WD: Q6379309 38.84, 121.5 x 39.04, 121.6
    { 2889, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0066ff} }, // MFL OSM: 7953598 WD: Q823251 39.95, -75.26 x 40.02, -75.08
    { 2893, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x84388a} }, // NHSL OSM: 7953621 WD: Q2205806 39.96, -75.35 x 40.11, -75.26
    { 15, NoLogo, 15989, LineMetaDataContent::Subway, Color{0x5f259f} }, // 12 OSM: 7957874 WD: Q10938157 38.8, 121.1 x 38.86, 121.5
    { 2898, 16772, 6050, LineMetaDataContent::Subway, Color{0x38a800} }, // Μ1 OSM: 7963514 WD: Q6553095 37.94, 23.64 x 38.07, 23.81
    { 2902, 16796, 6050, LineMetaDataContent::Subway, Color{0xff0000} }, // Μ2 OSM: 7963569 WD: Q9295813 37.89, 23.69 x 38.02, 23.75
    { 330, 16820, NoLogo, LineMetaDataContent::Subway, Color{0x2d3087} }, // R OSM: 7963671 WD: Q225095 35.61, 139.7 x 35.65, 139.8
    { 53, NoLogo, 16843, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 7963913 WD: Q30750331 40.14, 44.47 x 40.2, 44.52
    { 19, NoLogo, 16861, LineMetaDataContent::Subway, Color{0x9aaead} }, // 8 OSM: 7964884 WD: Q11124525 30.43, 114.3 x 30.68, 114.4
    { 2906, 16882, 15320, LineMetaDataContent::Tramway, Color{0x98cd37} }, // ML4 OSM: 7968999 WD: Q1637556 40.22, -3.773 x 40.25, -3.749
    { 2910, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x006400} }, // Tranvía OSM: 7981323 37.77, -3.79 x 37.81, -3.778
    { 2919, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0354a6} }, // DTL OSM: 7981644 WD: Q1663943 1.278, 103.7 x 1.413, 104
    { 2923, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x9016b2} }, // NEL OSM: 7981649 WD: Q1725116 1.265, 103.8 x 1.415, 103.9
    { 2927, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff9a00} }, // CCL OSM: 7981685 WD: Q2154003 1.265, 103.8 x 1.353, 103.9
    { 2931, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x009530} }, // EWL OSM: 7981689 WD: Q1895425 1.276, 103.6 x 1.376, 104
    { 347, NoLogo, 15634, LineMetaDataContent::Subway, Color{0x1e90ff} }, // M3 OSM: 7981707 WD: Q21526528 39.97, 32.56 x 39.99, 32.73
    { 8, NoLogo, 15634, LineMetaDataContent::Subway, Color{0x800080} }, // M4 OSM: 7981756 WD: Q31193144 39.94, 32.84 x 40, 32.88
    { 266, NoLogo, 16903, LineMetaDataContent::Subway, Color{0x0000ff} }, // M1 OSM: 7981873 WD: Q3238655 38.39, 27.07 x 38.47, 27.23
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xed1c24} }, // 2 OSM: 7986215 WD: Q11103955 22.86, 113.7 x 23.09, 113.9
    { 2935, NoLogo, 16925, LineMetaDataContent::Subway, Color{0xff748c} }, // Pink Line OSM: 7989308 WD: Q17053988 26.88, 75.75 x 26.93, 75.83
    { 2945, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x246b5b} }, // BTS Silom OSM: 7989387 WD: Q2634702 13.71, 100.5 x 13.75, 100.5
    { 2955, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf9c212} }, // U AVO OSM: 7993108 40.64, -8.654 x 41.15, -8.564
    { 9, 16947, 5415, LineMetaDataContent::Tramway, Color{0xf25482} }, // 4 OSM: 7999217 WD: Q2527775 50.79, 4.318 x 50.86, 4.363
    { 233, 16968, 5415, LineMetaDataContent::Tramway, Color{0x991f36} }, // 25 OSM: 7999338 WD: Q3238750 50.8, 4.358 x 50.87, 4.408
    { 1274, 16990, 5415, LineMetaDataContent::Tramway, Color{0xe3ba12} }, // 55 OSM: 7999374 WD: Q2236365 50.86, 4.358 x 50.88, 4.416
    { 566, 17012, 5415, LineMetaDataContent::Tramway, Color{0x91bee7} }, // 82 OSM: 7999733 WD: Q2534011 50.78, 4.29 x 50.87, 4.341
    { 57, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffcc00} }, // 3 OSM: 8000255 WD: Q13422345 14.54, 121 x 14.65, 121.1
    { 53, 17034, 17034, LineMetaDataContent::RapidTransit, Color{0x008000} }, // 1 OSM: 8000262 WD: Q4165607 14.53, 121 x 14.66, 121
    { 16, NoLogo, 17034, LineMetaDataContent::Subway, Color{0x800080} }, // 2 OSM: 8000265 WD: Q4165317 14.6, 121 x 14.63, 121.1
    { 2961, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfe8e10} }, // AG OSM: 8000298 WD: Q474391 3.12, 101.7 x 3.188, 101.8
    { 123, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x008000} }, // 9 OSM: 8000326 WD: Q6717618 2.98, 101.6 x 3.207, 101.8
    { 2964, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x721422} }, // SP OSM: 8000405 WD: Q474391 2.994, 101.6 x 3.188, 101.7
    { 236, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe0115f} }, // KJ OSM: 8000461 2.995, 101.6 x 3.231, 101.7
    { 1672, 17047, 17071, LineMetaDataContent::Subway, Color{0xff8c00} }, // T OSM: 8000572 WD: Q981826 43.03, 141.3 x 43.09, 141.5
    { 491, 17083, 17071, LineMetaDataContent::Subway, Color{0x008800} }, // N OSM: 8000575 WD: Q843793 42.99, 141.3 x 43.11, 141.4
    { 1710, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0377ae} }, // R6 OSM: 8005936 48.62, 21.19 x 48.71, 21.24
    { 57, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x55bace} }, // 3 OSM: 8013591 48.68, 21.26 x 48.72, 21.3
    { 40, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x5cbf14} }, // 7 OSM: 8013592 48.68, 21.24 x 48.73, 21.3
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x7477b0} }, // 4 OSM: 8013593 48.68, 21.24 x 48.74, 21.27
    { 123, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf5d907} }, // 9 OSM: 8013594 48.68, 21.23 x 48.74, 21.3
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xd2005c} }, // 2 OSM: 8013595 48.72, 21.24 x 48.74, 21.27
    { 310, 17109, 17149, LineMetaDataContent::Subway, Color{0xf62e36} }, // M OSM: 8015940 WD: Q1147028 35.67, 139.6 x 35.73, 139.8
    { 2967, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x11385b} }, // 金山(Jinshan) OSM: 8019734 WD: Q3338133 30.73, 121.3 x 31.16, 121.4
    { 226, 17177, NoLogo, LineMetaDataContent::Subway, Color{0xe85298} }, // A OSM: 8019854 WD: Q720653 35.58, 139.7 x 35.71, 139.8
    { 33, 17206, NoLogo, LineMetaDataContent::Subway, Color{0x6cbb5a} }, // S OSM: 8019866 WD: Q1374502 35.65, 139.4 x 35.8, 139.9
    { 37, 17236, NoLogo, LineMetaDataContent::Subway, Color{0xb6007a} }, // E OSM: 8019893 WD: Q384862 35.65, 139.6 x 35.76, 139.8
    { 1577, 17262, NoLogo, LineMetaDataContent::Subway, Color{0x0079c2} }, // I OSM: 8019914 WD: Q1374506 35.63, 139.6 x 35.79, 139.8
    { 2983, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xafca36} }, // G44 OSM: 8021111 47.37, 18.87 x 47.5, 19.04
    { 221, 17288, 17149, LineMetaDataContent::Subway, Color{0x00bb85} }, // C OSM: 8026069 WD: Q1075089 35.66, 139.7 x 35.78, 139.8
    { 491, 17325, 17149, LineMetaDataContent::Subway, Color{0x00ac9b} }, // N OSM: 8026071 WD: Q520772 35.63, 139.7 x 35.78, 139.8
    { 487, 17362, 17149, LineMetaDataContent::Subway, Color{0xff9500} }, // G OSM: 8026077 WD: Q1073046 35.66, 139.7 x 35.71, 139.8
    { 955, 17397, 17149, LineMetaDataContent::Subway, Color{0xc1a470} }, // Y OSM: 8026115 WD: Q787305 35.64, 139.6 x 35.79, 139.8
    { 1672, 17438, 17149, LineMetaDataContent::Subway, Color{0x009bbf} }, // T OSM: 8026124 WD: Q1147054 35.66, 139.7 x 35.71, 140
    { 388, 17474, 17149, LineMetaDataContent::Subway, Color{0xb5b5ac} }, // H OSM: 8026149 WD: Q1196223 35.64, 139.7 x 36.11, 139.8
    { 2765, 17510, 17149, LineMetaDataContent::Subway, Color{0x8f76d6} }, // Z OSM: 8026157 WD: Q1376030 35.51, 139.4 x 36.11, 139.8
    { 240, 17549, 17149, LineMetaDataContent::Subway, Color{0x9c5e31} }, // F OSM: 8026161 WD: Q1332908 35.66, 139.6 x 35.79, 139.7
    { 33, 17589, NoLogo, LineMetaDataContent::Subway, Color{0xffaadd} }, // S OSM: 8028801 WD: Q1073354 34.64, 135.5 x 34.69, 135.6
    { 310, 17629, NoLogo, LineMetaDataContent::Subway, Color{0xdd0000} }, // M OSM: 8028805 WD: Q1192413 34.56, 135.5 x 34.81, 135.5
    { 1577, 17666, NoLogo, LineMetaDataContent::Subway, Color{0xff9900} }, // I OSM: 8028826 WD: Q1066118 34.67, 135.5 x 34.76, 135.6
    { 430, 17706, NoLogo, LineMetaDataContent::Subway, Color{0x662211} }, // K OSM: 8028828 WD: Q1143250 34.64, 135.5 x 34.71, 135.5
    { 491, 17744, NoLogo, LineMetaDataContent::Subway, Color{0xaadd55} }, // N OSM: 8028846 WD: Q284828 34.67, 135.5 x 34.72, 135.6
    { 955, 17798, NoLogo, LineMetaDataContent::Subway, Color{0x0000ff} }, // Y OSM: 8028853 WD: Q1067748 34.61, 135.5 x 34.7, 135.5
    { 1672, 17837, NoLogo, LineMetaDataContent::Subway, Color{0x540a56} }, // T OSM: 8028879 WD: Q1142773 34.6, 135.5 x 34.75, 135.6
    { 430, 17846, 17871, LineMetaDataContent::Subway, Color{0x3cb371} }, // K OSM: 8030551 WD: Q762347 34.96, 135.8 x 35.06, 135.8
    { 1672, 17890, 17871, LineMetaDataContent::Subway, Color{0xff4500} }, // T OSM: 8030553 WD: Q1143898 34.93, 135.7 x 35.01, 135.8
    { 33, 17912, 13314, LineMetaDataContent::Subway, Color{0xff0000} }, // S OSM: 8030762 WD: Q1132780 35.09, 136.9 x 35.17, 137
    { 388, 17957, 13314, LineMetaDataContent::Subway, Color{0xffffcc} }, // H OSM: 8030765 WD: Q1132799 35.14, 136.9 x 35.18, 137
    { 37, 18002, 13314, LineMetaDataContent::Subway, Color{0x8f76d6} }, // E OSM: 8030779 WD: Q1045061 35.09, 136.9 x 35.14, 136.9
    { 1672, 18041, 13314, LineMetaDataContent::Subway, Color{0xadd8e6} }, // T OSM: 8030785 WD: Q1043806 35.12, 136.9 x 35.22, 137
    { 310, 18083, 13314, LineMetaDataContent::Subway, Color{0x8f76d6} }, // M OSM: 8031607 WD: Q906775 35.12, 136.9 x 35.2, 137
    { 460, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe9527d} }, // S9 OSM: 8033205 WD: Q2381339 41.35, 2.001 x 41.41, 2.149
    { 53, NoLogo, 18122, LineMetaDataContent::Subway, Color{0x008000} }, // 1 OSM: 8034179 WD: Q6427301 22.46, 88.34 x 22.65, 88.4
    { 53, NoLogo, 15206, LineMetaDataContent::Subway, Color{0x3281c4} }, // 1 OSM: 8037596 WD: Q19891160 12.98, 80.16 x 13.18, 80.31
    { 2987, NoLogo, 15912, LineMetaDataContent::Subway, Color{0x0000ff} }, // Blue Line OSM: 8037671 WD: Q1029921 28.55, 77.02 x 28.66, 77.38
    { 2382, NoLogo, 15912, LineMetaDataContent::Subway, Color{0x008000} }, // Green Line OSM: 8037672 WD: Q5602820 28.65, 76.91 x 28.7, 77.17
    { 2997, NoLogo, 15912, LineMetaDataContent::Subway, Color{0x800080} }, // Violet Line OSM: 8037706 WD: Q3634451 28.34, 77.21 x 28.67, 77.32
    { 3009, NoLogo, 15912, LineMetaDataContent::Subway, Color{0xffff00} }, // Yellow Line OSM: 8037713 WD: Q795156 28.46, 77.07 x 28.75, 77.23
    { 3021, NoLogo, 15912, LineMetaDataContent::Subway, Color{0xffa500} }, // AEx OSM: 8037716 WD: Q5253735 28.55, 77.06 x 28.64, 77.22
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xeb3d1a} }, // 2 OSM: 8040132 WD: Q21245979 22.72, 108.3 x 22.9, 108.4
    { 57, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xfe4998} }, // 3 OSM: 8040148 WD: Q11087465 24.99, 102.6 x 25.05, 102.8
    { 39, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x991f36} }, // S7 OSM: 8043820 WD: Q2316170 41.39, 2.032 x 41.49, 2.169
    { 3025, NoLogo, 15912, LineMetaDataContent::Subway, Color{0xff00ff} }, // Magenta Line OSM: 8051576 WD: Q19893471 28.54, 77.08 x 28.63, 77.34
    { 123, NoLogo, 15912, LineMetaDataContent::Subway, Color{0x808080} }, // 9 OSM: 8051593 WD: Q47100305 28.61, 76.98 x 28.62, 77.02
    { 22, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xabd02c} }, // 18 OSM: 8054951 50.05, 14.39 x 50.11, 14.44
    { 169, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xa7c9ae} }, // 17 OSM: 8055113 50, 14.4 x 50.13, 14.46
    { 1047, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xdc008f} }, // 99 OSM: 8060661 50.06, 14.3 x 50.08, 14.51
    { 994, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xdc008f} }, // 98 OSM: 8060662 50.06, 14.3 x 50.09, 14.5
    { 11, 18145, 13477, LineMetaDataContent::Subway, Color{0x683064} }, // M5 OSM: 8061299 WD: Q1229371 41.01, 29.01 x 41.03, 29.19
    { 52, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x82c0c0} }, // 11 OSM: 8119161 55.75, 37.51 x 55.79, 37.59
    { 200, NoLogo, 16391, LineMetaDataContent::Subway, Color{0x0000ff} }, // T1 OSM: 8120923 WD: Q56168307 10.34, -67.04 x 10.43, -67.01
    { 51, 9224, 209, LineMetaDataContent::RapidTransit, Color{0xb72841} }, // S11 OSM: 8149205 WD: Q459508 47.98, 12.85 x 48.04, 12.93
    { 157, 9224, 209, LineMetaDataContent::RapidTransit, Color{0x22b24c} }, // S3 OSM: 8149206 WD: Q459508 47.28, 12.79 x 47.84, 13.23
    { 48, 9224, 209, LineMetaDataContent::RapidTransit, Color{0x0072bc} }, // S2 OSM: 8149207 WD: Q459508 47.81, 12.97 x 47.97, 13.27
    { 59, 9224, 209, LineMetaDataContent::RapidTransit, Color{0xb72841} }, // S1 OSM: 8149208 WD: Q459508 47.81, 12.92 x 47.99, 13.05
    { 3038, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x999999} }, // 浦江(Pujiang) OSM: 8167022 31.03, 121.5 x 31.06, 121.5
    { 2025, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0377ae} }, // R4 OSM: 8196259 48.62, 21.19 x 48.73, 21.25
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xea7b08} }, // 6 OSM: 8196338 48.7, 21.23 x 48.73, 21.27
    { 2022, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0377ae} }, // R3 OSM: 8197830 48.62, 21.19 x 48.74, 21.25
    { 1705, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0377ae} }, // R7 OSM: 8197872 48.62, 21.19 x 48.73, 21.24
    { 502, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // T2 OSM: 8209896 WD: Q16655789 47.99, 0.1929 x 48.02, 0.2359
    { 200, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xeb001b} }, // T1 OSM: 8209897 WD: Q3239229 47.96, 0.152 x 48.02, 0.2304
    { 463, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x009933} }, // Green OSM: 8212097 WD: Q19960507 54.9, -1.711 x 55.04, -1.382
    { 190, 18173, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // B OSM: 8219357 WD: Q2778331 34.05, -118.4 x 34.17, -118.2
    { 278, NoLogo, 7012, LineMetaDataContent::RapidTransit, Color{0xffe800} }, // Yellow OSM: 8237627 WD: Q54874971 38, -121.9 x 38.02, -121.8
    { 2935, NoLogo, 15912, LineMetaDataContent::Subway, Color{0xffc0cb} }, // Pink Line OSM: 8242438 WD: Q19891094 28.57, 77.12 x 28.72, 77.32
    { 57, 18198, 6815, LineMetaDataContent::Subway, Color{0xbb8c00} }, // 3 OSM: 8247017 WD: Q86468 35.17, 129 x 35.21, 129.1
    { 9, NoLogo, 10534, LineMetaDataContent::Tramway, Color{0xfc751c} }, // 4 OSM: 8255319 WD: Q2735863 52.04, 4.245 x 52.08, 4.543
    { 57, NoLogo, 10534, LineMetaDataContent::Tramway, Color{0x703276} }, // 3 OSM: 8255320 WD: Q3056105 52.05, 4.228 x 52.08, 4.518
    { 53, 18221, NoLogo, LineMetaDataContent::Subway, Color{0xf06a00} }, // 1 OSM: 8255698 WD: Q86356 35.05, 129 x 35.28, 129.1
    { 16, 18244, 6815, LineMetaDataContent::Subway, Color{0x81bf48} }, // 2 OSM: 8258658 WD: Q86467 35.13, 129 x 35.34, 129.2
    { 3054, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x00a2c9} }, // 311 OSM: 8272972 WD: Q85977451 35.16, 129.1 x 35.27, 129.2
    { 45, NoLogo, 209, LineMetaDataContent::RapidTransit, Color{0x5e2d91} }, // S8 OSM: 8294822 WD: Q7388382 47.2, 8.519 x 47.5, 8.782
    { 39, NoLogo, 209, LineMetaDataContent::RapidTransit, Color{0xfebe10} }, // S7 OSM: 8294823 WD: Q7388366 47.22, 8.511 x 47.5, 8.824
    { 48, NoLogo, 209, LineMetaDataContent::RapidTransit, Color{0x5da526} }, // S2 OSM: 8294824 WD: Q7388254 47.13, 8.519 x 47.45, 9.063
    { 40, 18267, NoLogo, LineMetaDataContent::Subway, Color{0x6ad1e3} }, // 7 OSM: 8297146 WD: Q11074646 30.61, 104 x 30.7, 104.1
    { 57, 18277, NoLogo, LineMetaDataContent::Subway, Color{0xd40f7d} }, // 3 OSM: 8297273 WD: Q8985154 30.54, 103.9 x 30.82, 104.2
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x008000} }, // 2 OSM: 8297697 WD: Q84767109 17.37, 78.48 x 17.45, 78.5
    { 3058, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // Red Line OSM: 8297698 WD: Q646209 17.35, 78.37 x 17.5, 78.55
    { 16, 18287, NoLogo, LineMetaDataContent::Subway, Color{0xff5c39} }, // 2 OSM: 8298113 WD: Q4391357 30.56, 104 x 30.76, 104.3
    { 9, 18297, NoLogo, LineMetaDataContent::Subway, Color{0x44af52} }, // 4 OSM: 8298132 WD: Q11074645 30.64, 103.8 x 30.69, 104.2
    { 63, 18307, NoLogo, LineMetaDataContent::Subway, Color{0x003da5} }, // 10 OSM: 8298254 WD: Q11074644 30.41, 103.8 x 30.63, 104
    { 53, NoLogo, 18318, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 8299497 WD: Q18128813 26.77, 80.88 x 26.89, 81
    { 3067, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xa89968} }, // 环 OSM: 8300611 WD: Q15915083 29.5, 106.4 x 29.61, 106.6
    { 6, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x00a3e0} }, // 5 OSM: 8300867 WD: Q15912187 29.57, 106.5 x 29.68, 106.6
    { 63, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x5a2a8d} }, // 10 OSM: 8300873 WD: Q15914281 29.58, 106.5 x 29.75, 106.7
    { 3071, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe1261c} }, // Xijiao OSM: 8303696 39.97, 116.2 x 39.99, 116.3
    { 3078, NoLogo, 209, LineMetaDataContent::RapidTransit, Color{0x56033a} }, // S 6 OSM: 8303864 WD: Q63217185 51.06, 12.37 x 51.4, 12.7
    { 1772, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x799ccd} }, // S21 OSM: 8303997 47.38, 8.47 x 47.44, 8.55
    { 16, NoLogo, 18341, LineMetaDataContent::Subway, Color{0xfdb935} }, // 2 OSM: 8306848 WD: Q28412021 36.68, 117 x 36.71, 117.2
    { 2421, NoLogo, 209, LineMetaDataContent::RapidTransit, Color{0xf9aa8f} }, // S41 OSM: 8306928 WD: Q15088595 47.49, 8.535 x 47.53, 8.724
    { 3082, NoLogo, 209, LineMetaDataContent::RapidTransit, Color{} }, // S27 OSM: 8308820 WD: Q106451356 47.47, 8.22 x 47.62, 8.308
    { 53, 18361, 16861, LineMetaDataContent::Subway, Color{0x0000ff} }, // 1 OSM: 8309087 WD: Q5963161 30.57, 114.1 x 30.71, 114.3
    { 3086, NoLogo, 209, LineMetaDataContent::RapidTransit, Color{0xbda07c} }, // S15 OSM: 8309090 WD: Q7388191 47.22, 8.368 x 47.51, 8.864
    { 42, NoLogo, 209, LineMetaDataContent::RapidTransit, Color{0x48b4ca} }, // S5 OSM: 8311264 WD: Q7388335 47.17, 8.429 x 47.41, 8.864
    { 3090, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x000000} }, // WES OSM: 8313440 45.31, -122.8 x 45.49, -122.8
    { 16, 18381, NoLogo, LineMetaDataContent::Subway, Color{0xff7300} }, // 2 OSM: 8323745 WD: Q2657097 30.12, 120 x 30.36, 120.3
    { 53, 18401, NoLogo, LineMetaDataContent::Subway, Color{0x3180b7} }, // 1 OSM: 8324096 WD: Q10946020 29.84, 121.4 x 29.92, 121.9
    { 26, 18422, 3199, LineMetaDataContent::Subway, Color{0x6ba53a} }, // 16 OSM: 8324250 WD: Q6553080 39.92, 116.1 x 40.07, 116.3
    { 1929, NoLogo, 209, LineMetaDataContent::RapidTransit, Color{0x0588cc} }, // S30 OSM: 8327718 WD: Q7388265 47.5, 8.722 x 47.59, 9.106
    { 989, NoLogo, 209, LineMetaDataContent::RapidTransit, Color{0x007e94} }, // S26 OSM: 8327719 WD: Q2321332 47.26, 8.724 x 47.51, 8.934
    { 1290, NoLogo, 209, LineMetaDataContent::RapidTransit, Color{0x7a4c29} }, // S13 OSM: 8327720 WD: Q7388186 47.13, 8.675 x 47.23, 8.75
    { 53, NoLogo, 18443, LineMetaDataContent::Subway, Color{0xff7300} }, // 1 OSM: 8337169 WD: Q15953685 24.45, 118 x 24.66, 118.1
    { 232, NoLogo, 209, LineMetaDataContent::RapidTransit, Color{0xb41e8e} }, // S25 OSM: 8355962 WD: Q18391643 46.92, 8.519 x 47.38, 9.084
    { 3094, 18463, NoLogo, LineMetaDataContent::Subway, Color{0x939598} }, // JL OSM: 8391469 WD: Q5365768 35.71, 139.8 x 35.9, 140.1
    { 40, 18485, 1437, LineMetaDataContent::Tramway, Color{} }, // 7 OSM: 8426298 WD: Q104867986 49.43, 11.08 x 49.45, 11.09
    { 3058, NoLogo, 15912, LineMetaDataContent::Subway, Color{0xff0000} }, // Red Line OSM: 8429148 WD: Q3278367 28.67, 77.1 x 28.72, 77.42
    { 749, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa82618} }, // 22 OSM: 8435621 41.59, -87.62 x 41.88, -86.29
    { 130, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa82618} }, // 14 OSM: 8435621 41.59, -87.62 x 41.88, -86.29
    { 251, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa82618} }, // 20 OSM: 8435621 41.59, -87.62 x 41.88, -86.29
    { 22, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa82618} }, // 18 OSM: 8435621 41.59, -87.62 x 41.88, -86.29
    { 40, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa82618} }, // 7 OSM: 8435622 41.59, -87.62 x 41.88, -86.29
    { 123, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa82618} }, // 9 OSM: 8435622 41.59, -87.62 x 41.88, -86.29
    { 138, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa82618} }, // 19 OSM: 8435622 41.59, -87.62 x 41.88, -86.29
    { 3097, NoLogo, 209, LineMetaDataContent::RapidTransit, Color{0x73b3d7} }, // S35 OSM: 8437405 WD: Q7388272 47.46, 8.724 x 47.51, 9.042
    { 3101, NoLogo, 209, LineMetaDataContent::RapidTransit, Color{0x32a384} }, // S29 OSM: 8437511 WD: Q7388235 47.5, 8.714 x 47.66, 8.855
    { 1519, NoLogo, 209, LineMetaDataContent::RapidTransit, Color{0xad99c9} }, // S40 OSM: 8437648 WD: Q7388295 47.13, 8.682 x 47.22, 8.817
    { 3105, NoLogo, 209, LineMetaDataContent::RapidTransit, Color{0x198ea3} }, // S17 OSM: 8437734 WD: Q225086 47.34, 8.27 x 47.41, 8.406
    { 3109, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // ExpressTram OSM: 8438647 WD: Q5421647 42.2, -83.36 x 42.21, -83.35
    { 3121, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfc0200} }, // ATS OSM: 8438739 WD: Q2828747 41.97, -87.91 x 41.99, -87.88
    { 9, 18502, NoLogo, LineMetaDataContent::Subway, Color{0x0000ff} }, // 4 OSM: 8439223 WD: Q6112249 31.13, 120.6 x 31.41, 120.7
    { 16, 18512, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // 2 OSM: 8439253 WD: Q1054280 31.25, 120.6 x 31.44, 120.8
    { 278, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffff00} }, // Yellow OSM: 8464133 WD: Q55683262 9.006, 7.272 x 9.057, 7.475
    { 725, 18522, 9304, LineMetaDataContent::Subway, Color{0x00adef} }, // 52 OSM: 8466672 WD: Q2466115 52.34, 4.874 x 52.4, 4.933
    { 3125, 18566, 2680, LineMetaDataContent::Tramway, Color{0xe65e37} }, // T11 OSM: 8467024 WD: Q1083349 48.93, 2.302 x 48.96, 2.424
    { 3129, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa1a5a7} }, // Π4 OSM: 8467447 WD: Q17853551 37.91, 23.71 x 38.07, 23.94
    { 3133, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffd000} }, // Π1 OSM: 8467448 WD: Q47477364 37.91, 23.64 x 38.07, 23.94
    { 3137, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0098d8} }, // Π2 OSM: 8467516 WD: Q20552930 37.91, 22.73 x 38.09, 23.74
    { 3141, NoLogo, 3199, LineMetaDataContent::Subway, Color{0xd85f26} }, // 25S OSM: 8469061 WD: Q8048350 39.7, 116 x 39.73, 116.1
    { 200, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x254395} }, // T1 OSM: 8475071 WD: Q55693065 43.75, 11.17 x 43.8, 11.25
    { 123, NoLogo, 18600, LineMetaDataContent::Subway, Color{0x0b0080} }, // 9 OSM: 8478970 WD: Q3125123 39.01, 117.2 x 39.14, 117.7
    { 57, NoLogo, 18600, LineMetaDataContent::Subway, Color{0x128bbe} }, // 3 OSM: 8489969 WD: Q6553117 39.06, 117.1 x 39.24, 117.3
    { 16, NoLogo, 18600, LineMetaDataContent::Subway, Color{0xffff00} }, // 2 OSM: 8489970 WD: Q6553104 39.13, 117.1 x 39.16, 117.4
    { 53, NoLogo, 18600, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 8489971 WD: Q6126171 39.01, 117.1 x 39.21, 117.4
    { 27, NoLogo, 18600, LineMetaDataContent::Subway, Color{0x9f216f} }, // 6 OSM: 8490135 WD: Q10940001 39.04, 117.1 x 39.21, 117.3
    { 9, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x009049} }, // 4 OSM: 8499866 36.8, 10.06 x 36.82, 10.19
    { 596, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 201 OSM: 8505446 52.37, 16.91 x 52.46, 16.98
    { 130, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xaa6133} }, // 14 OSM: 8505950 52.38, 16.88 x 52.46, 16.92
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc597cd} }, // 12 OSM: 8505951 52.37, 16.91 x 52.46, 16.94
    { 52, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x5ec79f} }, // 11 OSM: 8505952 52.37, 16.89 x 52.44, 16.96
    { 3145, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf166a7} }, // 42X OSM: 8506177 58.9, 17.86 x 59.63, 18.16
    { 3149, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // TGM OSM: 8510421 36.8, 10.19 x 36.88, 10.34
    { 6, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x009049} }, // 5 OSM: 8510688 36.8, 10.12 x 36.84, 10.18
    { 57, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x009049} }, // 3 OSM: 8510789 36.8, 10.13 x 36.83, 10.18
    { 16, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x009049} }, // 2 OSM: 8511768 36.81, 10.18 x 36.86, 10.2
    { 1355, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf166a7} }, // 44 OSM: 8518402 59.2, 17.81 x 59.45, 18.07
    { 3153, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf166a7} }, // 43X OSM: 8518405 58.9, 17.81 x 59.45, 18.16
    { 123, 18617, 5415, LineMetaDataContent::Tramway, Color{0xff00ff} }, // 9 OSM: 8624098 WD: Q28609936 50.86, 4.309 x 50.89, 4.33
    { 3157, 18638, 6815, LineMetaDataContent::Subway, Color{0x0c8e72} }, // GC OSM: 8656365 WD: Q20192 37.58, 127 x 37.88, 127.7
    { 59, 18658, 18672, LineMetaDataContent::RapidTransit, Color{0xde3d30} }, // S1 OSM: 8661616 WD: Q46365 45.31, 9.032 x 45.62, 9.498
    { 48, 18694, 18672, LineMetaDataContent::RapidTransit, Color{0x009478} }, // S2 OSM: 8661617 WD: Q1160540 45.43, 9.14 x 45.69, 9.238
    { 157, 18708, 18672, LineMetaDataContent::RapidTransit, Color{0x942138} }, // S3 OSM: 8662821 WD: Q600028 45.47, 9.032 x 45.62, 9.176
    { 207, 18722, 18672, LineMetaDataContent::RapidTransit, Color{0x59b530} }, // S4 OSM: 8662822 WD: Q1160571 45.47, 9.134 x 45.67, 9.176
    { 42, 18736, 18672, LineMetaDataContent::RapidTransit, Color{0xeb8738} }, // S5 OSM: 8662846 WD: Q1159300 45.46, 8.789 x 45.82, 9.589
    { 196, 18750, 18672, LineMetaDataContent::RapidTransit, Color{0xebcc00} }, // S6 OSM: 8662847 WD: Q1160580 45.43, 8.625 x 45.53, 9.589
    { 3160, 9913, 9733, LineMetaDataContent::Subway, Color{0x009fe3} }, // L10 Sud OSM: 8663605 WD: Q1577033 41.34, 2.113 x 41.38, 2.148
    { 3168, NoLogo, 6815, LineMetaDataContent::Subway, Color{0x73c7a6} }, // G·J OSM: 8667957 WD: Q18233162 37.47, 126.7 x 37.89, 127.6
    { 438, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffff00} }, // L OSM: 8668342 39.74, -105 x 39.76, -105
    { 3173, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 202 OSM: 8671529 52.38, 16.91 x 52.46, 17
    { 35, 18764, NoLogo, LineMetaDataContent::Tramway, Color{0xff7f00} }, // 24E OSM: 8682141 WD: Q63230204 38.71, -9.162 x 38.73, -9.143
    { 53, 18777, 6815, LineMetaDataContent::Subway, Color{0x005daa} }, // 1 OSM: 8691899 WD: Q20280 36.77, 126.6 x 37.95, 127.2
    { 3177, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008144} }, // 902 OSM: 8708438 WD: Q5060656 44.95, -93.28 x 44.98, -93.09
    { 26, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf9b000} }, // 16 OSM: 8712352 52.32, 9.722 x 52.38, 9.837
    { 22, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe4003a} }, // 18 OSM: 8712368 52.33, 9.734 x 52.39, 9.804
    { 3181, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xba55d3} }, // 750 OSM: 8718106 40.23, -112 x 41.23, -111.7
    { 3185, 18800, NoLogo, LineMetaDataContent::Subway, Color{0x8fc31e} }, // SH OSM: 8725316 WD: Q12601528 37.3, 126.8 x 37.48, 126.8
    { 3189, 18838, NoLogo, LineMetaDataContent::Tramway, Color{} }, // 720 OSM: 8725393 WD: Q7634842 40.72, -111.9 x 40.72, -111.9
    { 3122, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x9bb14f} }, // TS OSM: 8729960 33.41, -111.9 x 33.43, -111.9
    { 3193, 18858, 6815, LineMetaDataContent::Subway, Color{0x0054a6} }, // GG OSM: 8735483 WD: Q23933857 37.26, 127.1 x 37.41, 127.6
    { 53, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x10069f} }, // 1 OSM: 8742572 WD: Q17498490 43.76, 87.47 x 43.92, 87.62
    { 200, 18890, 18890, LineMetaDataContent::Tramway, Color{0x008000} }, // T1 OSM: 8753522 WD: Q2661356 43.25, -2.952 x 43.27, -2.921
    { 15, NoLogo, 169, LineMetaDataContent::Tramway, Color{0xffd800} }, // 12 OSM: 8823281 WD: Q1485440 47.55, 19.09 x 47.57, 19.13
    { 3196, NoLogo, 169, LineMetaDataContent::Tramway, Color{0xffd800} }, // 56A OSM: 8823482 WD: Q21996124 47.48, 18.96 x 47.54, 19.05
    { 3200, NoLogo, 169, LineMetaDataContent::Tramway, Color{0xffd800} }, // 59A OSM: 8823524 WD: Q1491496 47.48, 19 x 47.51, 19.02
    { 3204, NoLogo, 169, LineMetaDataContent::Tramway, Color{0xffd800} }, // 59B OSM: 8823525 WD: Q22810651 47.48, 18.96 x 47.54, 19.02
    { 45, 18907, 18672, LineMetaDataContent::RapidTransit, Color{0xf09ea1} }, // S8 OSM: 8840314 WD: Q1160824 45.48, 9.179 x 45.86, 9.435
    { 1290, 18921, 18672, LineMetaDataContent::RapidTransit, Color{0x784f24} }, // S13 OSM: 8840315 WD: Q1160881 45.19, 9.143 x 45.5, 9.245
    { 460, 18936, 18672, LineMetaDataContent::RapidTransit, Color{0x8c3682} }, // S9 OSM: 8840324 WD: Q56920 45.4, 8.956 x 45.65, 9.274
    { 51, 18950, 18672, LineMetaDataContent::RapidTransit, Color{0x8787ba} }, // S11 OSM: 8840325 WD: Q1160879 45.48, 9.029 x 45.83, 9.274
    { 3208, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x961a54} }, // MXP1 OSM: 8840353 WD: Q1858023 45.47, 8.704 x 45.65, 9.175
    { 53, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0000ff} }, // 1 OSM: 8857089 24.54, 46.61 x 24.84, 46.78
    { 27, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x800080} }, // 6 OSM: 8857388 24.7, 46.64 x 24.81, 46.83
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf5a300} }, // 12 OSM: 8871002 WD: Q16655708 46.17, 6.129 x 46.2, 6.207
    { 3213, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // SC OSM: 8888446 43.03, 141.3 x 43.06, 141.4
    { 3216, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // Circular OSM: 9084313 WD: Q8048613 16.78, 96.09 x 16.94, 96.18
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xa68351} }, // 2 OSM: 9112026 WD: Q16854978 47.54, 7.571 x 47.59, 7.651
    { 57, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x324ea1} }, // 3 OSM: 9118502 WD: Q16854981 47.55, 7.553 x 47.59, 7.631
    { 53, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x835237} }, // 1 OSM: 9118510 WD: Q16854970 47.55, 7.573 x 47.57, 7.608
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0072bc} }, // 6 OSM: 9128621 WD: Q16854982 47.55, 7.537 x 47.59, 7.656
    { 1904, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x5fb04f} }, // 1511 OSM: 9133294 WD: Q56525586 47.15, -122.5 x 47.6, -122.2
    { 1899, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x5fb04f} }, // 1517 OSM: 9133294 WD: Q56525586 47.15, -122.5 x 47.6, -122.2
    { 3225, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x5fb04f} }, // 1519 OSM: 9133294 WD: Q56525586 47.15, -122.5 x 47.6, -122.2
    { 3230, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x5fb04f} }, // 1521 OSM: 9133294 WD: Q56525586 47.15, -122.5 x 47.6, -122.2
    { 3235, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x5fb04f} }, // 1523 OSM: 9133294 WD: Q56525586 47.15, -122.5 x 47.6, -122.2
    { 3240, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x5fb04f} }, // 1525 OSM: 9133294 WD: Q56525586 47.15, -122.5 x 47.6, -122.2
    { 40, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x8b0000} }, // 7 OSM: 9140122 14.65, 121 x 14.77, 121.1
    { 3245, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // MNC OSM: 9165727 14.61, 121 x 14.67, 121
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf171ab} }, // 8 OSM: 9173651 WD: Q16854983 47.55, 7.557 x 47.59, 7.608
    { 3249, 18965, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00289c} }, // C-4 OSM: 9174513 WD: Q1919488 40.24, -3.778 x 40.65, -3.635
    { 63, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfeca0a} }, // 10 OSM: 9177454 WD: Q7885420 47.48, 7.459 x 47.55, 7.62
    { 3253, 18983, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffa500} }, // C-9 OSM: 9181540 WD: Q8880294 40.74, -4.066 x 40.82, -3.963
    { 2409, 18998, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008a29} }, // C-2 OSM: 9187669 WD: Q2287356 40.38, -3.694 x 40.64, -3.181
    { 130, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf58220} }, // 14 OSM: 9190891 WD: Q16854972 47.52, 7.587 x 47.57, 7.694
    { 134, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00a54f} }, // 15 OSM: 9193744 WD: Q89415715 47.53, 7.587 x 47.56, 7.6
    { 26, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xa6ce39} }, // 16 OSM: 9196819 WD: Q16854975 47.53, 7.584 x 47.56, 7.605
    { 169, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00aeef} }, // 17 OSM: 9201222 WD: Q16854977 47.48, 7.545 x 47.58, 7.593
    { 316, 19012, NoLogo, LineMetaDataContent::RapidTransit, Color{0x1662b8} }, // U OSM: 9221982 WD: Q1191079 35.62, 139.8 x 35.67, 139.8
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xd64560} }, // 2 OSM: 9235815 WD: Q106996888 47.26, 11.34 x 47.28, 11.44
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8b445b} }, // 5 OSM: 9235816 WD: Q106996949 47.26, 11.34 x 47.28, 11.44
    { 3257, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // СТ-2 OSM: 9244973 48.68, 44.47 x 48.8, 44.6
    { 273, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000c0} }, // Blue OSM: 9248096 38.45, -121.5 x 38.65, -121.4
    { 463, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00c000} }, // Green OSM: 9248097 38.57, -121.5 x 38.6, -121.5
    { 1776, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xc0ba00} }, // Gold OSM: 9248098 38.55, -121.5 x 38.68, -121.2
    { 3264, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff69b4} }, // NT OSM: 9253571 35.73, 139.8 x 35.81, 139.8
    { 2395, 19039, NoLogo, LineMetaDataContent::Tramway, Color{0xd85b81} }, // SA OSM: 9254426 WD: Q1064795 35.71, 139.7 x 35.75, 139.8
    { 3267, NoLogo, 15912, LineMetaDataContent::Subway, Color{0x00ffff} }, // Aqua Line OSM: 9256785 WD: Q41668068 28.44, 77.37 x 28.59, 77.55
    { 2019, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0377ae} }, // R2 OSM: 9266121 48.62, 21.19 x 48.71, 21.3
    { 2028, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0377ae} }, // R8 OSM: 9266263 48.62, 21.19 x 48.71, 21.27
    { 483, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0377ae} }, // R1 OSM: 9273350 48.62, 21.19 x 48.72, 21.27
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0377ae} }, // 5 OSM: 9274837 48.7, 21.24 x 48.72, 21.27
    { 3277, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xcc3333} }, // exo1 OSM: 9288759 WD: Q3239247 45.39, -74.14 x 45.5, -73.57
    { 1467, 19068, NoLogo, LineMetaDataContent::RapidTransit, Color{0xda0442} }, // TY OSM: 9288983 WD: Q1192468 35.47, 139.6 x 35.66, 139.7
    { 3282, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x808080} }, // exo4 OSM: 9298215 45.36, -73.66 x 45.5, -73.51
    { 502, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x5d3988} }, // T2 OSM: 9298542 WD: Q61670436 43.77, 11.2 x 43.8, 11.25
    { 52, 19093, NoLogo, LineMetaDataContent::Subway, Color{0x6a1d44} }, // 11 OSM: 9318442 WD: Q4698920 22.52, 113.8 x 22.79, 114.1
    { 3287, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x009900} }, // exo2 OSM: 9326028 45.45, -74 x 45.77, -73.57
    { 3292, 19117, NoLogo, LineMetaDataContent::Subway, Color{0x3564af} }, // SR OSM: 9336150 WD: Q1065949 35.78, 139.7 x 35.89, 139.8
    { 3295, 19149, NoLogo, LineMetaDataContent::RapidTransit, Color{0x009cd2} }, // MG OSM: 9340970 WD: Q283861 35.55, 139.6 x 35.63, 139.7
    { 3298, 19174, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf18c43} }, // OM OSM: 9341650 WD: Q384995 35.6, 139.6 x 35.61, 139.7
    { 3301, 19199, NoLogo, LineMetaDataContent::RapidTransit, Color{0x20a288} }, // DT OSM: 9341816 WD: Q1190086 35.51, 139.4 x 35.66, 139.7
    { 429, 19224, NoLogo, LineMetaDataContent::RapidTransit, Color{0xee86a7} }, // IK OSM: 9342009 WD: Q1192388 35.56, 139.7 x 35.63, 139.7
    { 3304, 19249, NoLogo, LineMetaDataContent::RapidTransit, Color{0xae0378} }, // TM OSM: 9343887 WD: Q379292 35.56, 139.7 x 35.59, 139.7
    { 3307, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff00ff} }, // exo5 OSM: 9344059 45.52, -73.67 x 45.74, -73.49
    { 3312, 19274, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0068b7} }, // KD OSM: 9344153 WD: Q842701 35.53, 139.5 x 35.56, 139.5
    { 1850, 19299, NoLogo, LineMetaDataContent::RapidTransit, Color{0x10a899} }, // NS OSM: 9346454 WD: Q846381 35.91, 139.6 x 36.01, 139.6
    { 3315, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x6600cc} }, // exo3 OSM: 9348176 45.49, -73.57 x 45.58, -73.18
    { 3320, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xbac219} }, // U16 OSM: 9354869 48.8, 9.087 x 48.81, 9.277
    { 255, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf8b710} }, // 23 OSM: 9396890 48.75, 9.179 x 48.81, 9.221
    { 226, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc01903} }, // A OSM: 9413576 WD: Q1419423 45.76, 3.082 x 45.81, 3.134
    { 67, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00ae9d} }, // 21 OSM: 9414064 WD: Q16854979 47.56, 7.573 x 47.57, 7.608
    { 42, NoLogo, 19327, LineMetaDataContent::RapidTransit, Color{0x79d4f0} }, // S5 OSM: 9414242 WD: Q63705361 47.59, 7.608 x 47.64, 7.744
    { 1937, NoLogo, 209, LineMetaDataContent::RapidTransit, Color{0xcb7eb5} }, // S36 OSM: 9414253 WD: Q15088595 47.52, 8.22 x 47.62, 8.538
    { 266, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xb43c46} }, // M1 OSM: 9434553 WD: Q60608236 -6.292, 106.8 x -6.191, 106.8
    { 3324, 19350, 3410, LineMetaDataContent::Subway, Color{0xf890a5} }, // 捷運紅線 (新北投支線) OSM: 9437207 WD: Q8044505 25.13, 121.5 x 25.14, 121.5
    { 2844, 19389, 3410, LineMetaDataContent::Subway, Color{0x398afc} }, // BL OSM: 9437778 WD: Q708378 24.96, 121.4 x 25.05, 121.6
    { 1438, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x2ab04f} }, // RE OSM: 9441941 46.95, 7.438 x 47.2, 7.559
    { 460, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xea1a2a} }, // S9 OSM: 9441942 46.95, 7.438 x 46.99, 7.458
    { 45, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x201f20} }, // S8 OSM: 9441943 46.95, 7.438 x 47.2, 7.559
    { 989, 19414, 209, LineMetaDataContent::RapidTransit, Color{0x018a47} }, // S26 OSM: 9445376 WD: Q7388232 52.4, 13.28 x 52.61, 13.4
    { 57, 19429, 11082, LineMetaDataContent::Tramway, Color{0xffff00} }, // 3 OSM: 9453120 WD: Q61000373 -22.91, -43.19 x -22.9, -43.17
    { 27, 19458, 13204, LineMetaDataContent::Subway, Color{0xff5599} }, // 6 OSM: 9468298 WD: Q20110123 35.62, 51.31 x 35.74, 51.46
    { 3355, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff6600} }, // RN OSM: 9477810 WD: Q1055870 35.81, 139.9 x 35.86, 139.9
    { 3358, 19482, NoLogo, LineMetaDataContent::Subway, Color{0xffff00} }, // KS-AE OSM: 9480386 WD: Q1045305 35.54, 139.7 x 35.81, 140.4
    { 310, NoLogo, 19510, LineMetaDataContent::Subway, Color{0x3e9397} }, // M OSM: 9487066 WD: Q7057341 -33.8, 150.9 x -33.69, 151.2
    { 3364, 19522, 13477, LineMetaDataContent::RapidTransit, Color{0x7a745a} }, // F3 OSM: 9488738 WD: Q31193173 41.1, 28.99 x 41.11, 28.99
    { 2173, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x006400} }, // EN OSM: 9499957 35.3, 139.5 x 35.34, 139.6
    { 3367, 19550, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00a6bf} }, // SS OSM: 9507192 WD: Q195685 35.7, 139.3 x 35.91, 139.7
    { 53, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0000ff} }, // 1 OSM: 9522022 23, 72.61 x 23.01, 72.67
    { 53, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa6dfe6} }, // 1 OSM: 9525005 36.75, 10.18 x 36.8, 10.22
    { 27, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x652c90} }, // 6 OSM: 9530554 36.72, 10.18 x 36.8, 10.22
    { 376, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x008000} }, // L2 OSM: 9536631 WD: Q25420937 9.029, -79.51 x 9.104, -79.35
    { 273, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // Blue OSM: 9542499 9.046, 7.285 x 9.155, 7.344
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009999} }, // 5 OSM: 9544852 53.08, 8.78 x 53.09, 8.818
    { 3370, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffff00} }, // JN OSM: 9555851 35.51, 139.4 x 35.7, 139.7
    { 3373, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xffa500} }, // Orange Line OSM: 9571557 WD: Q61996404 21.04, 79.04 x 21.16, 79.09
    { 285, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xe2251c} }, // Red OSM: 9573815 WD: Q25343681 25.19, 51.49 x 25.42, 51.61
    { 39, 19568, 7739, LineMetaDataContent::Subway, Color{0xca8687} }, // S7 OSM: 9584586 WD: Q10946062 31.61, 118.9 x 31.76, 119
    { 460, 19589, 7739, LineMetaDataContent::Subway, Color{0xf1bc1a} }, // S9 OSM: 9584587 WD: Q47471478 31.34, 118.8 x 31.76, 118.9
    { 3385, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xee1e23} }, // U GUS OSM: 9586670 41.14, -8.61 x 41.44, -8.294
    { 45, 19610, 7739, LineMetaDataContent::Subway, Color{0xeca153} }, // S8 OSM: 9588181 WD: Q10945880 32.15, 118.7 x 32.47, 119
    { 9, NoLogo, 7739, LineMetaDataContent::Subway, Color{0xa513c0} }, // 4 OSM: 9588283 WD: Q10906684 32.06, 118.7 x 32.13, 119
    { 57, NoLogo, 16861, LineMetaDataContent::Subway, Color{0xdab866} }, // 3 OSM: 9588292 WD: Q11124519 30.49, 114.2 x 30.68, 114.3
    { 16, 19631, 16861, LineMetaDataContent::Subway, Color{0xe99bc1} }, // 2 OSM: 9592190 WD: Q5952205 30.44, 114.2 x 30.79, 114.4
    { 3391, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x3caeef} }, // U MCS OSM: 9599441 41.14, -8.61 x 41.26, -8.136
    { 19, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x800080} }, // 8 OSM: 9599549 37.33, -122 x 37.96, -121.3
    { 9, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x800080} }, // 4 OSM: 9599549 37.33, -122 x 37.96, -121.3
    { 63, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x800080} }, // 10 OSM: 9599549 37.33, -122 x 37.96, -121.3
    { 27, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x800080} }, // 6 OSM: 9599549 37.33, -122 x 37.96, -121.3
    { 426, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x006400} }, // 41 OSM: 9600352 51.66, 19.32 x 51.74, 19.46
    { 22, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 18 OSM: 9600353 51.74, 19.38 x 51.78, 19.51
    { 169, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffc0cb} }, // 17 OSM: 9600354 51.7, 19.41 x 51.78, 19.51
    { 26, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffc0cb} }, // 16 OSM: 9600355 51.73, 19.37 x 51.8, 19.46
    { 134, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffc0cb} }, // 15 OSM: 9600356 51.72, 19.45 x 51.78, 19.53
    { 130, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // 14 OSM: 9600357 51.74, 19.38 x 51.76, 19.51
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 13 OSM: 9600358 51.73, 19.37 x 51.8, 19.49
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 12 OSM: 9600359 51.74, 19.38 x 51.78, 19.53
    { 3397, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffa500} }, // 11AB OSM: 9600360 51.7, 19.41 x 51.83, 19.49
    { 3402, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // 10AB OSM: 9600361 51.73, 19.38 x 51.76, 19.58
    { 3407, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 9AB OSM: 9600362 51.73, 19.41 x 51.77, 19.58
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // 8 OSM: 9600363 51.75, 19.36 x 51.8, 19.54
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffa500} }, // 6 OSM: 9600365 51.72, 19.45 x 51.8, 19.49
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x800080} }, // 5 OSM: 9600366 51.72, 19.41 x 51.79, 19.49
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 4 OSM: 9600367 51.74, 19.43 x 51.83, 19.51
    { 57, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffa500} }, // 3 OSM: 9600368 51.72, 19.45 x 51.81, 19.55
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffa500} }, // 2 OSM: 9600370 51.74, 19.36 x 51.8, 19.51
    { 53, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x800080} }, // 1 OSM: 9600371 51.73, 19.46 x 51.8, 19.49
    { 3411, 19651, NoLogo, LineMetaDataContent::Tramway, Color{} }, // HN OSM: 9603867 WD: Q5648522 34.54, 135.4 x 34.65, 135.5
    { 326, 19689, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7777ff} }, // P OSM: 9603949 WD: Q1073366 34.61, 135.4 x 34.64, 135.5
    { 3414, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 478 OSM: 9604089 37.33, -122.4 x 37.78, -121.9
    { 3418, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 472 OSM: 9604089 37.33, -122.4 x 37.78, -121.9
    { 3422, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 470 OSM: 9604089 37.33, -122.4 x 37.78, -121.9
    { 6, NoLogo, 18600, LineMetaDataContent::Subway, Color{0xfb6f14} }, // 5 OSM: 9604983 WD: Q10940000 39.04, 117.1 x 39.27, 117.2
    { 3426, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 192 OSM: 9605482 37.31, -122.4 x 37.78, -121.9
    { 332, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 196 OSM: 9605482 37.31, -122.4 x 37.78, -121.9
    { 993, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 198 OSM: 9605482 37.31, -122.4 x 37.78, -121.9
    { 1001, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 194 OSM: 9605482 37.31, -122.4 x 37.78, -121.9
    { 1751, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 197 OSM: 9605484 37.31, -122.4 x 37.78, -121.9
    { 1046, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 199 OSM: 9605484 37.31, -122.4 x 37.78, -121.9
    { 1531, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 195 OSM: 9605484 37.31, -122.4 x 37.78, -121.9
    { 3430, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf0e68c} }, // 219 OSM: 9605923 37, -122.4 x 37.78, -121.6
    { 3434, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf0e68c} }, // 268 OSM: 9605964 37, -122.4 x 37.78, -121.6
    { 600, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf0e68c} }, // 231 OSM: 9606118 37.33, -122.4 x 37.78, -121.9
    { 3438, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf0e68c} }, // 243 OSM: 9606118 37.33, -122.4 x 37.78, -121.9
    { 254, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf0e68c} }, // 223 OSM: 9606118 37.33, -122.4 x 37.78, -121.9
    { 3442, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf0e68c} }, // 203 OSM: 9606118 37.33, -122.4 x 37.78, -121.9
    { 3446, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf0e68c} }, // 207 OSM: 9606118 37.33, -122.4 x 37.78, -121.9
    { 3450, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf0e68c} }, // 259 OSM: 9606118 37.33, -122.4 x 37.78, -121.9
    { 3454, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf0e68c} }, // 255 OSM: 9606118 37.33, -122.4 x 37.78, -121.9
    { 3458, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf0e68c} }, // 239 OSM: 9606118 37.33, -122.4 x 37.78, -121.9
    { 3462, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf0e68c} }, // 251 OSM: 9606118 37.33, -122.4 x 37.78, -121.9
    { 3466, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf0e68c} }, // 293 OSM: 9606118 37.33, -122.4 x 37.78, -121.9
    { 3470, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf0e68c} }, // 247 OSM: 9606118 37.33, -122.4 x 37.78, -121.9
    { 3474, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf0e68c} }, // 273 OSM: 9606118 37.33, -122.4 x 37.78, -121.9
    { 3478, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf0e68c} }, // 281 OSM: 9606118 37.33, -122.4 x 37.78, -121.9
    { 289, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf0e68c} }, // 289 OSM: 9606118 37.33, -122.4 x 37.78, -121.9
    { 3482, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf0e68c} }, // 234 OSM: 9606121 37.31, -122.4 x 37.78, -121.9
    { 3486, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf0e68c} }, // 276 OSM: 9606121 37.31, -122.4 x 37.78, -121.9
    { 3490, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf0e68c} }, // 206 OSM: 9606121 37.31, -122.4 x 37.78, -121.9
    { 3494, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf0e68c} }, // 222 OSM: 9606121 37.31, -122.4 x 37.78, -121.9
    { 3498, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf0e68c} }, // 260 OSM: 9606121 37.31, -122.4 x 37.78, -121.9
    { 215, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf0e68c} }, // 238 OSM: 9606121 37.31, -122.4 x 37.78, -121.9
    { 3502, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf0e68c} }, // 242 OSM: 9606121 37.31, -122.4 x 37.78, -121.9
    { 3506, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf0e68c} }, // 230 OSM: 9606121 37.31, -122.4 x 37.78, -121.9
    { 3510, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf0e68c} }, // 250 OSM: 9606121 37.31, -122.4 x 37.78, -121.9
    { 3514, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf0e68c} }, // 288 OSM: 9606121 37.31, -122.4 x 37.78, -121.9
    { 3518, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf0e68c} }, // 246 OSM: 9606121 37.31, -122.4 x 37.78, -121.9
    { 3522, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf0e68c} }, // 254 OSM: 9606121 37.31, -122.4 x 37.78, -121.9
    { 3526, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf0e68c} }, // 284 OSM: 9606121 37.31, -122.4 x 37.78, -121.9
    { 3530, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf0e68c} }, // 256 OSM: 9606198 37, -122.4 x 37.78, -121.6
    { 3534, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf0e68c} }, // 214 OSM: 9606201 37.31, -122.4 x 37.78, -121.9
    { 513, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf0e68c} }, // 215 OSM: 9606321 37, -122.4 x 37.78, -121.6
    { 413, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf0e68c} }, // 248 OSM: 9606324 37.33, -122.4 x 37.78, -121.9
    { 1441, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf0e68c} }, // 272 OSM: 9606324 37.33, -122.4 x 37.78, -121.9
    { 3173, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf0e68c} }, // 202 OSM: 9606324 37.33, -122.4 x 37.78, -121.9
    { 3538, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf0e68c} }, // 264 OSM: 9606324 37.33, -122.4 x 37.78, -121.9
    { 3542, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf0e68c} }, // 240 OSM: 9606324 37.33, -122.4 x 37.78, -121.9
    { 3546, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf0e68c} }, // 252 OSM: 9606324 37.33, -122.4 x 37.78, -121.9
    { 3550, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf0e68c} }, // 218 OSM: 9606324 37.33, -122.4 x 37.78, -121.9
    { 336, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf0e68c} }, // 286 OSM: 9606324 37.33, -122.4 x 37.78, -121.9
    { 3554, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf0e68c} }, // 210 OSM: 9606324 37.33, -122.4 x 37.78, -121.9
    { 3558, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf0e68c} }, // 226 OSM: 9606324 37.33, -122.4 x 37.78, -121.9
    { 3562, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf0e68c} }, // 232 OSM: 9606324 37.33, -122.4 x 37.78, -121.9
    { 3566, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf0e68c} }, // 280 OSM: 9606324 37.33, -122.4 x 37.78, -121.9
    { 3570, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf0e68c} }, // 244 OSM: 9606324 37.33, -122.4 x 37.78, -121.9
    { 3574, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf0e68c} }, // 236 OSM: 9606324 37.33, -122.4 x 37.78, -121.9
    { 9, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x00843d} }, // 4 OSM: 9607978 WD: Q863422 22.75, 113.4 x 23.13, 113.6
    { 9, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xdc8633} }, // 4 OSM: 9609521 WD: Q15900365 29.57, 106.5 x 29.78, 106.8
    { 1631, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x00b5e2} }, // APM OSM: 9611409 WD: Q862929 23.11, 113.3 x 23.14, 113.3
    { 67, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x201747} }, // 21 OSM: 9611531 WD: Q6553110 23.12, 113.4 x 23.29, 113.8
    { 3578, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xc4d600} }, // GF OSM: 9612493 WD: Q3272527 22.96, 113.1 x 23.09, 113.3
    { 27, NoLogo, 16861, LineMetaDataContent::Subway, Color{0x007733} }, // 6 OSM: 9617440 WD: Q15899990 30.49, 114.2 x 30.64, 114.3
    { 40, NoLogo, 16861, LineMetaDataContent::Subway, Color{0xee7800} }, // 7 OSM: 9617441 WD: Q11124507 30.32, 114.2 x 30.64, 114.3
    { 42, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x8d1d81} }, // S5 OSM: 9626749 46.71, 15.42 x 47.07, 15.63
    { 3581, 19733, NoLogo, LineMetaDataContent::Subway, Color{0x734538} }, // TEL OSM: 9627860 WD: Q7795883 1.272, 103.8 x 1.452, 104
    { 40, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0035ad} }, // 7 OSM: 9629866 WD: Q5938409 22.52, 113.9 x 22.6, 114.1
    { 57, 19766, NoLogo, LineMetaDataContent::Subway, Color{0x00a2e1} }, // 3 OSM: 9629887 WD: Q1065551 22.51, 114 x 22.73, 114.3
    { 59, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00983a} }, // S1 OSM: 9631352 47.07, 15.28 x 47.41, 15.42
    { 9, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x920783} }, // 4 OSM: 9632502 WD: Q24835582 28.14, 112.9 x 28.3, 113.1
    { 9, 19789, 16861, LineMetaDataContent::Subway, Color{0xb8d200} }, // 4 OSM: 9633082 WD: Q6553126 30.53, 114 x 30.61, 114.4
    { 52, NoLogo, 16861, LineMetaDataContent::Subway, Color{0xfdd000} }, // 11 OSM: 9633134 WD: Q11124500 30.49, 114.3 x 30.54, 114.7
    { 57, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x8b4513} }, // 3 OSM: 9633218 WD: Q5986353 -33.46, -70.69 x -33.37, -70.56
    { 460, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x9f7fb8} }, // S9 OSM: 9634178 47.41, 15.27 x 47.61, 15.68
    { 45, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x5cc1d1} }, // S8 OSM: 9634179 47.17, 14.44 x 47.41, 15.28
    { 438, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0067c0} }, // L OSM: 9638873 WD: Q1329642 35.17, 137 x 35.18, 137.1
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x3b6a96} }, // 2 OSM: 9642906 WD: Q15913266 43.83, 125.2 x 43.88, 125.4
    { 19, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x25b7bc} }, // 8 OSM: 9642908 43.95, 125.3 x 44.01, 125.4
    { 6, 19809, NoLogo, LineMetaDataContent::Subway, Color{0x9950b2} }, // 5 OSM: 9645952 WD: Q5926109 22.48, 113.9 x 22.63, 114.1
    { 53, 19832, NoLogo, LineMetaDataContent::Subway, Color{0xee352e} }, // 1 OSM: 9651536 WD: Q126093 40.7, -74.02 x 40.89, -73.9
    { 1221, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf05b94} }, // S20 OSM: 9652168 47.24, 8.514 x 47.39, 8.727
    { 16, 19858, NoLogo, LineMetaDataContent::Subway, Color{0xee352e} }, // 2 OSM: 9655665 WD: Q126142 40.63, -74.01 x 40.9, -73.85
    { 57, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x571887} }, // 3 OSM: 9656354 WD: Q25824052 22.72, 108.2 x 22.88, 108.4
    { 57, 19884, NoLogo, LineMetaDataContent::Subway, Color{0xee352e} }, // 3 OSM: 9663807 WD: Q126151 40.66, -74.01 x 40.82, -73.88
    { 3585, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x6c8bc6} }, // D11 OSM: 9672611 51.1, 16.15 x 51.4, 17.04
    { 9, 19910, NoLogo, LineMetaDataContent::Subway, Color{0x00933c} }, // 4 OSM: 9677108 WD: Q126163 40.66, -74.01 x 40.89, -73.88
    { 1850, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xce0037} }, // NS OSM: 9677671 WD: Q3333785 -6.292, 106.8 x -6.191, 106.8
    { 372, NoLogo, 19936, LineMetaDataContent::RapidTransit, Color{0xee343f} }, // L1 OSM: 9678605 WD: Q14543324 -33.91, 151.1 x -33.87, 151.2
    { 438, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe4022d} }, // L OSM: 9678765 -32.93, 151.8 x -32.92, 151.8
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 2 OSM: 9680853 51.37, -0.2081 x 51.42, -0.02612
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xb5e61d} }, // 4 OSM: 9680854 51.37, -0.2081 x 51.42, -0.04953
    { 6, 19948, NoLogo, LineMetaDataContent::Subway, Color{0x00933c} }, // 5 OSM: 9682651 WD: Q126177 40.63, -74.01 x 40.9, -73.83
    { 123, 19974, NoLogo, LineMetaDataContent::Subway, Color{0x846e74} }, // 9 OSM: 9699772 WD: Q5939429 22.51, 113.9 x 22.57, 114.1
    { 2165, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // BLUE OSM: 9701744 53.33, -1.508 x 53.4, -1.344
    { 3589, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x800080} }, // PURP OSM: 9701781 53.34, -1.469 x 53.38, -1.424
    { 3594, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffff00} }, // YELL OSM: 9701824 53.38, -1.51 x 53.42, -1.405
    { 3599, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // TT OSM: 9701873 53.38, -1.469 x 53.44, -1.343
    { 3602, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x006bb6} }, // SIR OSM: 9701910 WD: Q1273068 40.51, -74.25 x 40.64, -74.07
    { 130, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe2368c} }, // 14 OSM: 9708096 47.14, 37.54 x 47.18, 37.62
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe2368c} }, // 13 OSM: 9708097 47.14, 37.54 x 47.18, 37.62
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x13b5eb} }, // 8 OSM: 9708100 47.1, 37.51 x 47.12, 37.56
    { 40, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x329932} }, // 7 OSM: 9708101 47.1, 37.54 x 47.18, 37.57
    { 53, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe51919} }, // 1 OSM: 9708102 47.1, 37.54 x 47.15, 37.62
    { 63, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x4f3893} }, // 10 OSM: 9708103 47.1, 37.51 x 47.18, 37.62
    { 57, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf37b24} }, // 3 OSM: 9709247 47.1, 37.51 x 47.12, 37.65
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf37b24} }, // 4 OSM: 9709278 47.1, 37.51 x 47.12, 37.65
    { 37, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008150} }, // E OSM: 9709938 WD: Q172040 42.33, -71.11 x 42.37, -71.06
    { 52, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x897ab7} }, // 11 OSM: 9712140 47.1, 37.54 x 47.18, 37.65
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffbf00} }, // 5 OSM: 9712141 47.1, 37.54 x 47.15, 37.65
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffbf00} }, // 6 OSM: 9712142 47.1, 37.54 x 47.12, 37.65
    { 123, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0068b2} }, // 9 OSM: 9712143 47.1, 37.54 x 47.18, 37.65
    { 310, 19997, NoLogo, LineMetaDataContent::Subway, Color{0xff6319} }, // M OSM: 9712349 WD: Q126418 40.7, -74 x 40.76, -73.84
    { 438, 20023, NoLogo, LineMetaDataContent::Subway, Color{0xa7a9ac} }, // L OSM: 9716997 WD: Q126534 40.65, -74 x 40.74, -73.9
    { 460, NoLogo, 19327, LineMetaDataContent::RapidTransit, Color{0x9589c6} }, // S9 OSM: 9719969 WD: Q3239195 47.35, 7.812 x 47.46, 7.918
    { 3606, 2890, NoLogo, LineMetaDataContent::Subway, Color{0xb933ad} }, // <7> OSM: 9721629 WD: Q126203 40.74, -74 x 40.76, -73.83
    { 3610, 3020, NoLogo, LineMetaDataContent::Subway, Color{0x00933c} }, // <6> OSM: 9721630 WD: Q126192 40.71, -74.01 x 40.85, -73.83
    { 3173, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // 202 OSM: 9729897 51.04, -114.2 x 51.13, -113.9
    { 596, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // 201 OSM: 9729912 50.9, -114.2 x 51.13, -114.1
    { 1650, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfc6357} }, // 502 OSM: 9730137 53.46, -113.5 x 53.57, -113.5
    { 3614, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x3a59a9} }, // 501 OSM: 9730138 53.46, -113.5 x 53.6, -113.4
    { 53, 20049, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // 1 OSM: 9732464 WD: Q56188749 -3.039, 104.7 x -2.894, 104.8
    { 3618, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xed1d24} }, // TWL OSM: 9736531 WD: Q1194568 22.28, 114.1 x 22.38, 114.2
    { 3622, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x7d499d} }, // TKL OSM: 9736612 WD: Q989347 22.29, 114.2 x 22.32, 114.3
    { 237, 14951, NoLogo, LineMetaDataContent::Subway, Color{0x996633} }, // J OSM: 9747970 WD: Q126484 40.68, -74.01 x 40.72, -73.8
    { 190, 20097, NoLogo, LineMetaDataContent::Subway, Color{0xff6319} }, // B OSM: 9748435 WD: Q126381 40.58, -74 x 40.87, -73.89
    { 293, NoLogo, 2095, LineMetaDataContent::RapidTransit, Color{0xef7b10} }, // Overground OSM: 9752361 WD: Q7363198 51.56, 0.1837 x 51.58, 0.2521
    { 240, 20123, NoLogo, LineMetaDataContent::Subway, Color{0xff6319} }, // F OSM: 9753684 WD: Q126404 40.58, -74 x 40.77, -73.78
    { 3626, NoLogo, 16861, LineMetaDataContent::Subway, Color{0xb60081} }, // Yangluo OSM: 9765661 WD: Q11124502 30.65, 114.3 x 30.72, 114.6
    { 989, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xc89f3b} }, // S26 OSM: 9767547 47.14, 7.907 x 47.4, 8.436
    { 221, 20149, NoLogo, LineMetaDataContent::Subway, Color{0x0039a6} }, // C OSM: 9767766 WD: Q126358 40.67, -74.01 x 40.84, -73.87
    { 1093, 20175, NoLogo, LineMetaDataContent::Subway, Color{0xff6319} }, // D OSM: 9769161 WD: Q126396 40.58, -74.01 x 40.88, -73.88
    { 37, 20201, NoLogo, LineMetaDataContent::Subway, Color{0x0039a6} }, // E OSM: 9769302 WD: Q126368 40.7, -74.01 x 40.76, -73.8
    { 3634, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x000000} }, // 751P OSM: 9788142 WD: Q15903000 22.41, 114 x 22.47, 114
    { 3639, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xee3a41} }, // NEC OSM: 9795466 WD: Q7057868 40.2, -74.79 x 40.77, -73.99
    { 502, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe73132} }, // T2 OSM: 9797089 49.18, -0.3663 x 49.21, -0.3479
    { 1680, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009adf} }, // T3 OSM: 9797090 49.16, -0.364 x 49.19, -0.3411
    { 1437, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf686c3} }, // TRE OSM: 9797671 WD: Q7838588 39.95, -75.2 x 40.22, -74.75
    { 9, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x37ad96} }, // 4 OSM: 9807766 WD: Q15939632 34.14, 108.9 x 34.38, 109
    { 3643, 20227, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008a29} }, // C-6 OSM: 9812239 WD: Q5987225 39.44, -0.3834 x 39.99, -0.05192
    { 3647, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x3096c2} }, // NLR OSM: 9821052 WD: Q3078283 40.73, -74.19 x 40.78, -74.16
    { 57, 20245, NoLogo, LineMetaDataContent::Subway, Color{0xeca154} }, // 3 OSM: 9841063 WD: Q862941 22.94, 113.3 x 23.4, 113.4
    { 3651, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0194d7} }, // JFK OSM: 9862004 WD: Q406683 40.64, -73.83 x 40.7, -73.78
    { 56, 20254, NoLogo, LineMetaDataContent::RapidTransit, Color{0x2ca05a} }, // 13 OSM: 9881314 WD: Q6553067 -23.54, -46.63 x -23.43, -46.49
    { 3655, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // Norte OSM: 9881792 -5.797, -35.42 x -5.632, -35.21
    { 2161, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // Sul OSM: 9881793 -5.916, -35.26 x -5.78, -35.21
    { 123, NoLogo, 16022, LineMetaDataContent::Subway, Color{0x0000ff} }, // 9 OSM: 9893306 WD: Q11138917 41.72, 123.3 x 41.84, 123.5
    { 463, 20266, NoLogo, LineMetaDataContent::RapidTransit, Color{0x76c761} }, // Green OSM: 9897509 WD: Q6925400 37.28, -122 x 37.41, -121.9
    { 273, 20285, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00a4e2} }, // Blue OSM: 9897510 WD: Q4737344 37.24, -121.9 x 37.41, -121.8
    { 3661, 20303, 20303, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // ARL OSM: 9921501 WD: Q1133704 13.69, 100.5 x 13.76, 100.8
    { 123, 20318, NoLogo, LineMetaDataContent::Subway, Color{0x71cc98} }, // 9 OSM: 9924027 WD: Q6553161 23.36, 113.1 x 23.4, 113.3
    { 1067, 20338, 209, LineMetaDataContent::RapidTransit, Color{0xc36939} }, // S42 OSM: 9942315 WD: Q15118875 52.46, 13.28 x 52.55, 13.48
    { 487, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffd700} }, // G OSM: 9942698 WD: Q5578772 39.75, -105.1 x 39.81, -105
    { 190, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // B OSM: 9942699 WD: Q19865232 39.75, -105 x 39.82, -105
    { 226, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x57c0e8} }, // A OSM: 9942719 WD: Q5328174 39.75, -105 x 39.85, -104.7
    { 2440, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xcccccc} }, // Silver OSM: 9946498 32.71, -117.2 x 32.72, -117.2
    { 3666, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // 530 OSM: 9946502 32.71, -117.2 x 32.84, -117
    { 1913, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffa500} }, // 520 OSM: 9946503 32.71, -117.2 x 32.81, -117
    { 221, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf79239} }, // C OSM: 9947502 WD: Q5015067 39.58, -105 x 39.76, -105
    { 1093, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008348} }, // D OSM: 9947503 39.58, -105 x 39.75, -105
    { 37, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x552683} }, // E OSM: 9947507 39.52, -105 x 39.76, -104.9
    { 240, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xee3e33} }, // F OSM: 9947520 39.52, -105 x 39.75, -104.9
    { 388, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0075bf} }, // H OSM: 9947525 39.63, -105 x 39.75, -104.8
    { 330, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xb7f037} }, // R OSM: 9947529 39.52, -104.9 x 39.77, -104.8
    { 520, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x37b5a5} }, // W OSM: 9947532 39.72, -105.2 x 39.76, -105
    { 200, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x23a638} }, // T1 OSM: 9953164 49.15, -0.3663 x 49.2, -0.3292
    { 1054, NoLogo, 18672, LineMetaDataContent::RapidTransit, Color{0x293838} }, // S12 OSM: 9959066 WD: Q26828150 45.36, 9.159 x 45.5, 9.32
    { 3670, NoLogo, 6815, LineMetaDataContent::Subway, Color{0x996746} }, // AREX OSM: 9961461 WD: Q487643 37.44, 126.4 x 37.6, 127
    { 3675, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xd1aa00} }, // SAR-VIN OSM: 9963645 WD: Q10318744 -22.68, -43.25 x -22.57, -43.18
    { 3683, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x660066} }, // Belford Roxo OSM: 9963651 WD: Q10318671 -22.91, -43.4 x -22.76, -43.19
    { 3696, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf60619} }, // Deodoro OSM: 9963665 WD: Q18473921 -22.91, -43.39 x -22.85, -43.19
    { 3704, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfa8835} }, // Saracuruna OSM: 9963667 WD: Q10318727 -22.91, -43.31 x -22.68, -43.19
    { 3715, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x5194c4} }, // JRI-PBI OSM: 9963669 WD: Q10318719 -22.64, -43.71 x -22.61, -43.65
    { 3723, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x96333b} }, // SAR-GIM OSM: 9963674 WD: Q10318688 -22.68, -43.25 x -22.52, -42.98
    { 3731, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x6b297e} }, // Parangaba-Mucuripe OSM: 9963934 WD: Q10318709 -3.776, -38.56 x -3.721, -38.48
    { 3750, 20353, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // Oeste OSM: 9963937 WD: Q14325543 -3.77, -38.66 x -3.718, -38.54
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009ee3} }, // 4 OSM: 9964886 52.25, 10.51 x 52.27, 10.56
    { 226, 20391, 920, LineMetaDataContent::RapidTransit, Color{0x00bfff} }, // A OSM: 9971068 WD: Q2323144 55.46, 12.17 x 55.93, 12.59
    { 709, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xde1d43} }, // LR OSM: 9976617 39.17, -76.68 x 39.5, -76.62
    { 16, NoLogo, 20413, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // 2 OSM: 9984970 WD: Q4873303 2.999, 101.4 x 3.685, 101.7
    { 53, NoLogo, 20413, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // 1 OSM: 9985625 WD: Q4207166 2.452, 101.7 x 3.239, 102.2
    { 63, NoLogo, 20413, LineMetaDataContent::RapidTransit, Color{0xa52a2a} }, // 10 OSM: 9985661 WD: Q51419215 3.081, 101.6 x 3.136, 101.7
    { 134, 20434, 3750, LineMetaDataContent::Subway, Color{0xde64a1} }, // 15 OSM: 10011657 WD: Q4226438 55.7, 37.7 x 55.78, 37.94
    { 273, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // Blue OSM: 10012484 35.11, -80.88 x 35.32, -80.73
    { 123, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009cdd} }, // 9 OSM: 10015448 53.41, 14.49 x 53.47, 14.55
    { 3295, 19149, NoLogo, LineMetaDataContent::Subway, Color{0x8ba2ae} }, // MG OSM: 10023806 WD: Q283861 35.55, 139.6 x 35.63, 139.7
    { 3756, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xbcbe00} }, // E2 OSM: 10025161 WD: Q104233849 43.27, -2.021 x 43.35, -1.782
    { 3759, 20459, NoLogo, LineMetaDataContent::Subway, Color{0x01aaaa} }, // TJ OSM: 10032387 WD: Q1040703 35.73, 139.2 x 36.12, 139.7
    { 3301, 19199, NoLogo, LineMetaDataContent::Subway, Color{0x01aaaa} }, // DT OSM: 10032468 WD: Q1190086 35.47, 139.4 x 36.11, 139.8
    { 53, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xee1b2e} }, // 1 OSM: 10036404 WD: Q5159786 45.4, -75.74 x 45.43, -75.61
    { 3762, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x00a650} }, // OT OSM: 10036880 WD: Q1063832 35.36, 139.2 x 35.67, 139.7
    { 1360, 20490, 20490, LineMetaDataContent::RapidTransit, Color{0xe80000} }, // O OSM: 10073686 WD: Q1142127 34.65, 135.5 x 34.71, 135.5
    { 3765, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x000000} }, // STS OSM: 10077802 WD: Q7426074 47.44, -122.3 x 47.45, -122.3
    { 3769, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x5fb04f} }, // South OSM: 10077909 WD: Q56525586 47.15, -122.5 x 47.6, -122.2
    { 3775, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x88be5f} }, // 1702 OSM: 10077947 47.6, -122.4 x 47.98, -122.2
    { 3780, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x88be5f} }, // North OSM: 10077955 47.6, -122.4 x 47.98, -122.2
    { 63, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe3000b} }, // 10 OSM: 10082596 52.25, 10.51 x 52.31, 10.54
    { 3786, 20506, NoLogo, LineMetaDataContent::Subway, Color{0xa17800} }, // 김포 골드라인 OSM: 10092719 WD: Q12589088 37.56, 126.6 x 37.65, 126.8
    { 22, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xd6a461} }, // 18 OSM: 10095918 WD: Q6553089 31.04, 121.6 x 31.16, 121.6
    { 1093, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008150} }, // D OSM: 10099594 WD: Q172031 42.32, -71.25 x 42.36, -71.06
    { 123, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x4ea391} }, // 9 OSM: 10103679 47.12, 27.56 x 47.19, 27.59
    { 130, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xb289bc} }, // 14 OSM: 10131355 WD: Q63781395 34.73, 113.5 x 34.78, 113.5
    { 3806, NoLogo, 3199, LineMetaDataContent::Subway, Color{0x0045bd} }, // Daxing Airport OSM: 10136967 WD: Q19840478 39.51, 116.3 x 39.85, 116.4
    { 53, NoLogo, 18341, LineMetaDataContent::Subway, Color{0xb5198d} }, // 1 OSM: 10149342 WD: Q18654264 36.5, 116.8 x 36.68, 116.9
    { 53, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xcd5c5c} }, // 1 OSM: 10163085 WD: Q66660306 31.63, 119.9 x 31.9, 120
    { 200, NoLogo, 20552, LineMetaDataContent::Tramway, Color{0x363d42} }, // T1 OSM: 10181950 WD: Q48747416 43.93, 4.799 x 43.94, 4.841
    { 3821, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x015698} }, // River Line OSM: 10213690 WD: Q2155505 39.94, -75.13 x 40.22, -74.71
    { 376, NoLogo, 19936, LineMetaDataContent::RapidTransit, Color{0xee343f} }, // L2 OSM: 10214162 WD: Q16927050 -33.92, 151.2 x -33.86, 151.2
    { 1856, NoLogo, 6525, LineMetaDataContent::Tramway, Color{0x873f98} }, // T6 OSM: 10218859 WD: Q21657685 45.73, 4.834 x 45.75, 4.897
    { 3762, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffe100} }, // OT OSM: 10238058 34.97, 135.8 x 35.07, 135.9
    { 59, NoLogo, 19327, LineMetaDataContent::RapidTransit, Color{0x81cd7b} }, // S1 OSM: 10249610 WD: Q3239193 47.51, 7.591 x 47.57, 8.063
    { 157, NoLogo, 19327, LineMetaDataContent::RapidTransit, Color{0x5ba3d8} }, // S3 OSM: 10249618 WD: Q3239191 47.33, 7.08 x 47.55, 7.918
    { 221, 20583, NoLogo, LineMetaDataContent::Subway, Color{0x00dd00} }, // C OSM: 10258970 WD: Q1057729 34.64, 135.4 x 34.73, 135.8
    { 33, NoLogo, 20599, LineMetaDataContent::RapidTransit, Color{0xbf1600} }, // S OSM: 10261953 WD: Q1621240 19.45, -99.2 x 19.67, -99.15
    { 3832, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x343f4b} }, // CMET OSM: 10271387 WD: Q16927042 -35.28, 149.1 x -35.19, 149.2
    { 3837, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x004792} }, // APT Blue OSM: 10274979 32.86, -96.94 x 32.87, -96.93
    { 57, NoLogo, 20625, LineMetaDataContent::Tramway, Color{0x14b845} }, // 3 OSM: 10281452 WD: Q16655742 43.66, 7.195 x 43.71, 7.212
    { 347, 20647, 2240, LineMetaDataContent::Subway, Color{0xff0a0a} }, // M3 OSM: 10283923 WD: Q1094251 55.67, 12.53 x 55.71, 12.59
    { 3846, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x65b724} }, // BTS Sukhumvit OSM: 10285801 WD: Q4921598 13.56, 100.5 x 13.93, 100.7
    { 53, NoLogo, 20625, LineMetaDataContent::Tramway, Color{0xcb1723} }, // 1 OSM: 10286521 WD: Q3238669 43.7, 7.254 x 43.73, 7.293
    { 240, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // F OSM: 10286522 WD: Q3537109 35.91, 136.2 x 36.07, 136.2
    { 526, 20659, 20684, LineMetaDataContent::RapidTransit, Color{0xf6a602} }, // D1 OSM: 10309188 WD: Q62091003 55.67, 37.28 x 56.01, 37.59
    { 3860, 20697, 20684, LineMetaDataContent::RapidTransit, Color{0xe83f83} }, // D2 OSM: 10309312 WD: Q62091175 55.43, 37.18 x 55.84, 37.74
    { 53, 20722, 20722, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 10309985 WD: Q2106 53.2, 50.12 x 53.21, 50.28
    { 3863, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff88bb} }, // Roch OSM: 10310648 53.41, -2.28 x 53.62, -2.088
    { 3868, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x887766} }, // EDid OSM: 10310683 53.41, -2.28 x 53.62, -2.088
    { 3873, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x887766} }, // Sh&C OSM: 10310683 53.41, -2.28 x 53.58, -2.089
    { 3878, 20744, NoLogo, LineMetaDataContent::Subway, Color{0xffd700} }, // JB OSM: 10312072 WD: Q1091295 35.61, 139.6 x 35.9, 140.1
    { 3881, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0066bb} }, // Dean OSM: 10314875 WD: Q22712167 53.37, -2.297 x 53.49, -2.238
    { 3886, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0066bb} }, // Vict OSM: 10314875 53.37, -2.297 x 53.49, -2.238
    { 3891, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0066bb} }, // Airp OSM: 10314875 53.37, -2.297 x 53.49, -2.238
    { 3896, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff7700} }, // MCUK OSM: 10320090 53.47, -2.297 x 53.49, -2.098
    { 3901, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xffffff} }, // Arcobaleno OSM: 10320583 WD: Q3832713 40.89, 14.21 x 40.97, 14.24
    { 1776, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xf9b428} }, // Gold OSM: 10322047 WD: Q22948672 25.26, 51.44 x 25.29, 51.57
    { 3912, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00ccff} }, // Eccl OSM: 10326857 WD: Q22087023 53.47, -2.334 x 53.49, -2.098
    { 3917, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00ccff} }, // Asht OSM: 10326857 53.47, -2.334 x 53.49, -2.098
    { 3922, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffbb00} }, // Picc OSM: 10334672 WD: Q22087020 53.39, -2.347 x 53.59, -2.226
    { 3927, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008800} }, // Altr OSM: 10334764 53.39, -2.347 x 53.59, -2.226
    { 3932, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008800} }, // Bury OSM: 10334764 53.39, -2.347 x 53.59, -2.226
    { 3937, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xd32232} }, // ESFECO OSM: 10334823 WD: Q1132053 -22.95, -43.22 x -22.94, -43.2
    { 3944, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff6600} }, // MSC 821 OSM: 10366537 14.17, 121 x 14.62, 121.3
    { 1502, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff6600} }, // MSC 1708 OSM: 10366538 14.17, 121 x 14.62, 121.3
    { 53, NoLogo, 20766, LineMetaDataContent::Subway, Color{0xbf3a35} }, // 1 OSM: 10379854 WD: Q47004909 34.24, 117.1 x 34.27, 117.3
    { 53, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0080bc} }, // 1 OSM: 10380194 WD: Q10893610 36.04, 103.7 x 36.1, 103.9
    { 130, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xccad02} }, // 14 OSM: 10381397 WD: Q85884202 34.37, 108.8 x 34.46, 109.1
    { 57, 20788, NoLogo, LineMetaDataContent::Subway, Color{0xf1a82b} }, // 3 OSM: 10383244 WD: Q10946022 29.79, 121.5 x 29.91, 121.6
    { 157, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xf1a82b} }, // S3 OSM: 10383349 WD: Q18111493 29.65, 121.4 x 29.79, 121.5
    { 3952, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x073686} }, // KS OSM: 10384058 WD: Q855470 35.53, 139.8 x 35.81, 140.4
    { 6, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0db0c8} }, // 5 OSM: 10386968 30.17, 120 x 30.32, 120.3
    { 6, 20809, NoLogo, LineMetaDataContent::Subway, Color{0x2a5947} }, // 5 OSM: 10387105 WD: Q15928521 34.72, 113.6 x 34.78, 113.8
    { 3955, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffc425} }, // Airtrain OSM: 10391556 WD: Q409266 -27.47, 153 x -27.38, 153.1
    { 749, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffa500} }, // 22 OSM: 10396259 WD: Q2885972 52.07, 5.112 x 52.09, 5.184
    { 3964, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x96c93c} }, // Taipa OSM: 10402175 WD: Q15935354 22.14, 113.5 x 22.16, 113.6
    { 463, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x009530} }, // Green OSM: 10403427 WD: Q25343673 25.27, 51.35 x 25.32, 51.53
    { 1093, 20828, 6587, LineMetaDataContent::Tramway, Color{0x850b22} }, // D OSM: 10406565 WD: Q16655779 44.82, -0.6676 x 44.89, -0.55
    { 1034, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xdb6198} }, // 305 OSM: 10409526 51.46, 7.152 x 51.48, 7.324
    { 1026, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x40558e} }, // 309 OSM: 10409567 51.44, 7.297 x 51.48, 7.337
    { 3970, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe28e07} }, // 316 OSM: 10409642 51.48, 7.16 x 51.53, 7.272
    { 380, NoLogo, 19936, LineMetaDataContent::RapidTransit, Color{0xee343f} }, // L3 OSM: 10411683 WD: Q16927050 -33.93, 151.2 x -33.86, 151.2
    { 53, 20862, NoLogo, LineMetaDataContent::Tramway, Color{0x96368b} }, // 1 OSM: 10413963 WD: Q15883002 51.2, 4.388 x 51.26, 4.421
    { 3974, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // 4М OSM: 10423669 47.83, 33.34 x 48, 33.5
    { 3978, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // 3М OSM: 10423670 WD: Q106432004 47.88, 33.39 x 48, 33.5
    { 3982, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // 2М OSM: 10423671 WD: Q106432003 47.89, 33.39 x 48, 33.5
    { 3986, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // 1М OSM: 10423672 WD: Q106432002 47.89, 33.39 x 47.96, 33.46
    { 221, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffa500} }, // C OSM: 10423828 WD: Q5061366 18.79, 72.83 x 19.65, 73.47
    { 3990, 5724, 209, LineMetaDataContent::RapidTransit, Color{0x006db6} }, // RB 32 OSM: 10432813 WD: Q7388251 51.43, 6.775 x 51.58, 7.459
    { 3996, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00bbb3} }, // CHW OSM: 10433666 WD: Q5093959 39.95, -75.21 x 40.08, -75.15
    { 4000, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa57b27} }, // CHE OSM: 10433667 WD: Q5093950 39.95, -75.21 x 40.08, -75.15
    { 4004, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x91456c} }, // AIR OSM: 10433668 WD: Q4698916 39.87, -75.26 x 39.96, -75.16
    { 4008, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x775ca7} }, // CYN OSM: 10433669 WD: Q5200188 39.95, -75.23 x 40.01, -75.17
    { 4012, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xee5067} }, // NOR OSM: 10433670 WD: Q6747157 39.95, -75.35 x 40.12, -75.15
    { 4016, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0081c5} }, // ELW OSM: 10433671 WD: Q6805374 39.9, -75.41 x 39.98, -75.15
    { 4020, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x8ed16a} }, // NWK OSM: 10433672 WD: Q8022734 39.67, -75.75 x 39.96, -75.16
    { 1238, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xc72a80} }, // L5 OSM: 10443588 46.18, 5.999 x 46.22, 6.144
    { 1242, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00b3b9} }, // L6 OSM: 10447940 46.1, 5.821 x 46.22, 6.144
    { 16, 20884, NoLogo, LineMetaDataContent::Subway, Color{0x00643a} }, // 2 OSM: 10458608 WD: Q20063925 26.04, 119.1 x 26.11, 119.4
    { 368, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xdc911b} }, // L4 OSM: 10464491 46.17, 6.121 x 46.32, 6.237
    { 52, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x304299} }, // 11 OSM: 10467354 WD: Q15944362 36.1, 120.5 x 36.48, 120.8
    { 56, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x00ac84} }, // 13 OSM: 10467728 WD: Q15937512 35.67, 119.7 x 35.95, 120.2
    { 4024, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // Sado OSM: 10484570 WD: Q1314068 38.51, -9.08 x 38.66, -8.838
    { 169, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00ace7} }, // 17 OSM: 10486182 WD: Q3238620 46.19, 6.125 x 46.2, 6.232
    { 226, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // A OSM: 10486983 WD: Q3239053 47.83, 1.9 x 47.93, 1.939
    { 16, NoLogo, 18443, LineMetaDataContent::Subway, Color{0x008900} }, // 2 OSM: 10488738 WD: Q24838989 24.48, 117.9 x 24.58, 118.2
    { 57, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xf57b00} }, // 3 OSM: 10488912 WD: Q6112757 31.26, 120.5 x 31.37, 120.8
    { 57, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0cd634} }, // 3 OSM: 10488951 WD: Q17023374 31.75, 117.2 x 31.93, 117.4
    { 502, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x44d62c} }, // T2 OSM: 10490757 30.69, 103.8 x 30.83, 104
    { 190, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x72277b} }, // B OSM: 10494114 WD: Q3239067 47.9, 1.854 x 47.91, 1.977
    { 380, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x6c9d40} }, // L3 OSM: 10505987 45.91, 6.121 x 46.32, 6.703
    { 2749, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x44d62c} }, // T2B OSM: 10506169 30.73, 104 x 30.8, 104
    { 53, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xe82311} }, // 1 OSM: 10507454 WD: Q76339003 40.78, 111.6 x 40.86, 111.8
    { 57, NoLogo, 18341, LineMetaDataContent::Subway, Color{0x3f63e6} }, // 3 OSM: 10513363 WD: Q24837836 36.62, 117.1 x 36.77, 117.2
    { 4029, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x43b02a} }, // TGM1 OSM: 10519278 22.9, 112.8 x 22.95, 112.9
    { 372, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xbf3527} }, // L1 OSM: 10521809 46.17, 6.121 x 46.4, 6.581
    { 376, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0085c4} }, // L2 OSM: 10526246 45.9, 6.116 x 46.32, 6.362
    { 6, 20903, NoLogo, LineMetaDataContent::Subway, Color{0xbb29bb} }, // 5 OSM: 10526316 WD: Q22100474 30.45, 104 x 30.83, 104.1
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffcc11} }, // 2 OSM: 10547015 WD: Q1878641 51, 3.709 x 51.05, 3.772
    { 123, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff2e17} }, // 9 OSM: 10547655 48.34, 10.89 x 48.37, 10.9
    { 226, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe3028c} }, // A OSM: 10551319 WD: Q93096868 48.38, -4.556 x 48.43, -4.444
    { 1313, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf9661e} }, // Orange OSM: 10561837 37.36, -122.1 x 37.42, -121.8
    { 2987, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // Blue Line OSM: 10563564 25.31, 51.42 x 25.32, 51.43
    { 2413, 9224, 209, LineMetaDataContent::RapidTransit, Color{0x008000} }, // Central OSM: 10570207 WD: Q459508 -7.233, -39.41 x -7.206, -39.3
    { 53, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x8a8988} }, // 1 OSM: 10570395 WD: Q10318643 -5.111, -42.82 x -5.08, -42.74
    { 4034, NoLogo, 209, LineMetaDataContent::RapidTransit, Color{0x008000} }, // CBTU OSM: 10570416 WD: Q18484877 -7.131, -34.98 x -6.974, -34.83
    { 3655, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // Norte OSM: 10570453 -3.683, -40.37 x -3.662, -40.34
    { 2161, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // Sul OSM: 10570461 -3.699, -40.36 x -3.682, -40.33
    { 4039, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // 550 OSM: 10577109 WD: Q4338668 30.26, -97.86 x 30.59, -97.7
    { 16, 20913, NoLogo, LineMetaDataContent::Tramway, Color{0xf18e00} }, // 2 OSM: 10579671 WD: Q3238812 43.57, 3.831 x 43.65, 3.931
    { 57, 20933, NoLogo, LineMetaDataContent::Tramway, Color{0xcbd300} }, // 3 OSM: 10579672 WD: Q3238911 43.56, 3.81 x 43.62, 3.964
    { 53, 20953, NoLogo, LineMetaDataContent::Tramway, Color{0x005ba1} }, // 1 OSM: 10579673 WD: Q3238667 43.6, 3.817 x 43.64, 3.92
    { 4043, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xee293d} }, // TEX OSM: 10580066 WD: Q28228164 32.75, -97.34 x 32.94, -97.04
    { 4047, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00ff80} }, // 656 OSM: 10588005 32.72, -117.4 x 33.19, -117.2
    { 4051, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00ff80} }, // 630 OSM: 10588005 32.72, -117.4 x 33.19, -117.2
    { 4055, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00ff80} }, // 640 OSM: 10588005 32.72, -117.4 x 33.19, -117.2
    { 4059, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00ff80} }, // 636 OSM: 10588005 32.72, -117.4 x 33.19, -117.2
    { 4063, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00ff80} }, // 654 OSM: 10588005 32.72, -117.4 x 33.19, -117.2
    { 4067, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x55502b} }, // UP Express OSM: 10608917 WD: Q497520 43.64, -79.62 x 43.71, -79.38
    { 4078, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x794400} }, // Stouffville OSM: 10624851 WD: Q3239216 43.64, -79.38 x 44, -79.23
    { 4090, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x009ac7} }, // Richmond Hill OSM: 10624852 WD: Q3239183 43.64, -79.43 x 43.88, -79.32
    { 4104, 20973, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf57f25} }, // Milton OSM: 10624853 WD: Q3239156 43.52, -79.87 x 43.67, -79.38
    { 4111, 20992, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00853f} }, // Kitchener OSM: 10624854 WD: Q3239126 43.46, -80.49 x 43.71, -79.38
    { 4121, 21014, NoLogo, LineMetaDataContent::RapidTransit, Color{0x003768} }, // Barrie OSM: 10624855 WD: Q3239071 43.64, -79.69 x 44.37, -79.38
    { 4128, 21033, NoLogo, LineMetaDataContent::RapidTransit, Color{0xee3124} }, // Lakeshore East OSM: 10624856 WD: Q3239134 43.64, -79.38 x 43.87, -78.89
    { 1083, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x8c86bf} }, // S28 OSM: 10644936 47.29, 7.939 x 47.39, 8.17
    { 597, 21060, NoLogo, LineMetaDataContent::RapidTransit, Color{0x9f142c} }, // 01 OSM: 10647448 WD: Q3239135 43.25, -79.89 x 43.65, -79.38
    { 955, 21087, 3410, LineMetaDataContent::Subway, Color{0xfedb00} }, // Y OSM: 10658528 WD: Q5971413 24.98, 121.5 x 25.06, 121.5
    { 3267, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x00ffff} }, // Aqua Line OSM: 10659365 WD: Q62051025 21.11, 79 x 21.14, 79.09
    { 4143, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xadd8e6} }, // LRT OSM: 10693161 WD: Q65762187 -6.193, 106.9 x -6.155, 106.9
    { 4147, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x3e6c01} }, // 102 OSM: 10696526 39.91, -75.3 x 39.96, -75.26
    { 4151, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x3e6c01} }, // 101 OSM: 10696527 39.91, -75.39 x 39.96, -75.26
    { 157, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe6007e} }, // S3 OSM: 10699280 46.95, 15.42 x 47.1, 16.02
    { 63, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x3e6c01} }, // 10 OSM: 10703006 WD: Q839339 39.95, -75.25 x 39.98, -75.16
    { 305, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x3e6c01} }, // 34 OSM: 10703188 WD: Q839339 39.94, -75.25 x 39.96, -75.16
    { 733, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x3e6c01} }, // 36 OSM: 10703676 WD: Q839339 39.9, -75.24 x 39.96, -75.16
    { 52, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x3e6c01} }, // 11 OSM: 10705415 WD: Q839339 39.92, -75.26 x 39.96, -75.16
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x3e6c01} }, // 13 OSM: 10705526 WD: Q839339 39.92, -75.26 x 39.96, -75.16
    { 196, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf39200} }, // S6 OSM: 10748876 46.72, 15.21 x 47.07, 15.48
    { 344, 21111, 3117, LineMetaDataContent::Subway, Color{0x008000} }, // M2 OSM: 10760559 WD: Q2519385 45.4, 9.145 x 45.55, 9.44
    { 347, 21131, 3117, LineMetaDataContent::Subway, Color{0xffff00} }, // M3 OSM: 10788272 WD: Q2519355 45.43, 9.163 x 45.53, 9.257
    { 266, 21151, 3117, LineMetaDataContent::Subway, Color{0xff0000} }, // M1 OSM: 10803053 WD: Q2400801 45.46, 9.084 x 45.54, 9.238
    { 134, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x3fbfaa} }, // 15 OSM: 10899251 47.1, 37.62 x 47.12, 37.65
    { 8, 21171, 2240, LineMetaDataContent::Subway, Color{0x36b6f1} }, // M4 OSM: 10925800 WD: Q88965328 55.67, 12.56 x 55.71, 12.6
    { 4155, 21183, NoLogo, LineMetaDataContent::RapidTransit, Color{0xed772d} }, // SI OSM: 10956060 WD: Q93546 35.72, 139.2 x 35.91, 139.7
    { 1054, NoLogo, 209, LineMetaDataContent::RapidTransit, Color{} }, // S12 OSM: 10961967 WD: Q106455671 46.85, 9.441 x 47.05, 9.562
    { 1772, NoLogo, 209, LineMetaDataContent::RapidTransit, Color{0x099690} }, // S21 OSM: 10963311 WD: Q106455085 47.33, 9.359 x 47.43, 9.462
    { 3188, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffa500} }, // 1720 OSM: 10976185 13.13, 123.2 x 13.62, 123.8
    { 4158, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffa500} }, // 1645 OSM: 10976234 13.59, 123 x 13.77, 123.2
    { 3665, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffa500} }, // 1530 OSM: 10976234 13.59, 123 x 13.77, 123.2
    { 491, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x9f26b4} }, // N OSM: 11004619 WD: Q19877104 39.75, -105 x 39.92, -104.9
    { 4163, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xee0011} }, // TrfC OSM: 11041584 53.46, -2.348 x 53.47, -2.267
    { 4168, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xee0011} }, // Corn OSM: 11041584 53.46, -2.348 x 53.47, -2.267
    { 3122, 21202, NoLogo, LineMetaDataContent::Subway, Color{0x0000ff} }, // TS OSM: 11065562 WD: Q2791146 35.51, 139.4 x 36.11, 139.8
    { 26, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xffb25b} }, // 16 OSM: 11076299 30.2, 119.7 x 30.27, 120
    { 388, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x303888} }, // H OSM: 11093106 WD: Q5654835 18.94, 72.83 x 19.12, 73.12
    { 520, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xebcf1f} }, // W OSM: 11094510 WD: Q7988022 18.93, 72.81 x 19.46, 72.86
    { 4173, NoLogo, 16743, LineMetaDataContent::Subway, Color{0x252525} }, // JSQ–33 via HOB OSM: 11100813 WD: Q1931652 40.72, -74.06 x 40.75, -73.99
    { 63, NoLogo, 16022, LineMetaDataContent::Subway, Color{0x008000} }, // 10 OSM: 11123255 WD: Q20688706 41.71, 123.3 x 41.86, 123.5
    { 33, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffc0cb} }, // S OSM: 11135401 WD: Q5364907 34.32, 134.1 x 34.34, 134.2
    { 430, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffff00} }, // K OSM: 11135402 WD: Q5371397 34.19, 133.8 x 34.35, 134.1
    { 491, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // N OSM: 11135412 WD: Q5364831 34.27, 134 x 34.35, 134.2
    { 165, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa05ea6} }, // 27 OSM: 11151437 WD: Q106813236 59.35, 18.04 x 59.66, 18.27
    { 1084, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa05ea6} }, // 28 OSM: 11151439 WD: Q106813260 59.35, 18.04 x 59.48, 18.31
    { 613, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa05ea6} }, // 29 OSM: 11151441 WD: Q106813276 59.35, 18.04 x 59.43, 18.1
    { 4190, NoLogo, 169, LineMetaDataContent::Tramway, Color{0xffd800} }, // 1M OSM: 11165876 WD: Q1489900 47.48, 19.03 x 47.55, 19.11
    { 59, 9224, 209, LineMetaDataContent::RapidTransit, Color{} }, // S1 OSM: 11183563 WD: Q2204422 47.15, 9.601 x 47.55, 9.817
    { 157, 9224, 209, LineMetaDataContent::RapidTransit, Color{0x6f8f30} }, // S3 OSM: 11185510 WD: Q2204422 47.42, 9.367 x 47.55, 9.754
    { 207, 9224, 209, LineMetaDataContent::RapidTransit, Color{} }, // S4 OSM: 11185615 WD: Q2204422 47.08, 9.816 x 47.15, 9.918
    { 39, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xbe1622} }, // S7 OSM: 11185888 46.96, 15.08 x 47.07, 15.42
    { 4193, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf39200} }, // S61 OSM: 11185889 46.72, 15.21 x 47.07, 15.42
    { 4197, NoLogo, 169, LineMetaDataContent::Tramway, Color{0xffd800} }, // 2M OSM: 11219607 WD: Q950776 47.47, 19.05 x 47.51, 19.09
    { 4200, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff6319} }, // <F> OSM: 11248274 40.58, -74 x 40.77, -73.78
    { 57, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x9acd32} }, // 3 OSM: 11257190 WD: Q17030673 28.1, 112.9 x 28.25, 113.1
    { 6, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xffff00} }, // 5 OSM: 11257230 WD: Q18668926 28.09, 113 x 28.29, 113.1
    { 4204, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00aeef} }, // HBLR OSM: 11269271 40.65, -74.13 x 40.79, -74.01
    { 1067, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x9a6b31} }, // S42 OSM: 11277216 47.28, 8.204 x 47.44, 8.539
    { 57, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 3 OSM: 11279461 46.95, 31.98 x 46.98, 32.03
    { 347, NoLogo, 14210, LineMetaDataContent::Subway, Color{0x008000} }, // M3 OSM: 11299964 WD: Q12289405 42.68, 23.24 x 42.7, 23.35
    { 134, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x3e6c01} }, // 15 OSM: 11328858 39.96, -75.25 x 39.98, -75.13
    { 310, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // M OSM: 11359791 42.27, -71.09 x 42.28, -71.06
    { 190, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008150} }, // B OSM: 11359792 WD: Q172011 42.34, -71.17 x 42.36, -71.06
    { 221, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008150} }, // C OSM: 11359793 WD: Q172022 42.34, -71.15 x 42.37, -71.06
    { 4209, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x73757d} }, // Metro OSM: 11364344 42.88, -78.88 x 42.95, -78.82
    { 273, NoLogo, 21236, LineMetaDataContent::RapidTransit, Color{0x0000f8} }, // Blue OSM: 11366428 WD: Q4929372 38.59, -90.35 x 38.65, -90.05
    { 285, NoLogo, 21236, LineMetaDataContent::RapidTransit, Color{0xf80000} }, // Red OSM: 11366429 WD: Q7304508 38.51, -90.36 x 38.74, -89.88
    { 39, 21264, 18672, LineMetaDataContent::RapidTransit, Color{0xd50054} }, // S7 OSM: 11479781 WD: Q26878568 45.48, 9.179 x 45.86, 9.399
    { 59, NoLogo, 21278, LineMetaDataContent::RapidTransit, Color{0x11385b} }, // S1 OSM: 11482970 WD: Q43285793 39.7, 116.1 x 39.9, 116.7
    { 316, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf0d808} }, // U OSM: 11490692 WD: Q28153731 18.88, 72.95 x 19.03, 73.04
    { 1672, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x4b0082} }, // T OSM: 11490693 WD: Q7833528 18.99, 72.97 x 19.19, 73.12
    { 48, NoLogo, 21278, LineMetaDataContent::RapidTransit, Color{0x11385b} }, // S2 OSM: 11494225 WD: Q4390966 40.07, 115.5 x 40.44, 116.3
    { 42, NoLogo, 21278, LineMetaDataContent::RapidTransit, Color{0xfabbcb} }, // S5 OSM: 11494329 WD: Q42308711 39.94, 116.2 x 40.69, 117.1
    { 674, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0092db} }, // 301 OSM: 11494376 43.42, -80.55 x 43.5, -80.44
    { 196, NoLogo, 19327, LineMetaDataContent::RapidTransit, Color{0xe9583f} }, // S6 OSM: 11519985 WD: Q63705067 47.54, 7.591 x 47.71, 7.849
    { 4215, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0072bc} }, // N6 OSM: 11522997 47.55, 7.587 x 47.59, 7.656
    { 347, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffcf06} }, // M3 OSM: 11525600 WD: Q2637212 50.41, 4.43 x 50.48, 4.452
    { 4218, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // Thilawa OSM: 11548643 16.66, 96.16 x 16.86, 96.26
    { 4226, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // Eastern University OSM: 11548647 16.74, 96.16 x 16.86, 96.29
    { 4245, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // Ywar Thar Gyi OSM: 11548648 16.78, 96.16 x 16.93, 96.27
    { 4259, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffff00} }, // Computer University OSM: 11548671 16.78, 96.07 x 17.01, 96.16
    { 4279, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffff00} }, // Insein - Hlaw Karr OSM: 11548680 16.87, 96.08 x 17, 96.11
    { 4298, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // Dagon University OSM: 11549059 16.78, 96.16 x 16.91, 96.23
    { 305, NoLogo, 10534, LineMetaDataContent::Tramway, Color{0x858585} }, // 34 OSM: 11565304 WD: Q100991407 52.04, 4.244 x 52.08, 4.543
    { 4315, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe1e1ff} }, // SN 4 OSM: 11566470 50.97, -0.1728 x 51.5, 0.213
    { 4320, 21291, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00bfff} }, // KK OSM: 11568311 WD: Q906807 35.18, 139.6 x 35.64, 139.8
    { 16, NoLogo, 15136, LineMetaDataContent::Subway, Color{0xffff00} }, // 2 OSM: 11582700 WD: Q85776743 37.97, 114.5 x 38.09, 114.5
    { 27, 21317, NoLogo, LineMetaDataContent::Subway, Color{0x3abca8} }, // 6 OSM: 11583149 WD: Q6119435 22.54, 113.8 x 22.79, 114.1
    { 63, 21340, NoLogo, LineMetaDataContent::Subway, Color{0xf8779e} }, // 10 OSM: 11583622 WD: Q15925362 22.52, 114.1 x 22.7, 114.1
    { 4323, 18998, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008a29} }, // C-2 (CIVIS) OSM: 11589066 WD: Q2287356 40.44, -3.682 x 40.64, -3.183
    { 2333, NoLogo, 12029, LineMetaDataContent::RapidTransit, Color{0x6b4d9f} }, // S81 OSM: 11589604 WD: Q56309403 50.65, 4.373 x 50.88, 4.617
    { 483, 21364, NoLogo, LineMetaDataContent::RapidTransit, Color{0x449ad5} }, // R1 OSM: 11592118 WD: Q2395239 41.36, 2.02 x 41.77, 2.769
    { 190, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x094b8d} }, // B OSM: 11592473 WD: Q4705897 -37.91, 145 x -37.75, 145.4
    { 8, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x84c8eb} }, // M4 OSM: 11592482 50.41, 4.435 x 50.43, 4.503
    { 4335, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffb531} }, // CH OSM: 11592485 WD: Q4705897 -37.82, 144.7 x -37.58, 145.2
    { 4338, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xee1d23} }, // E11 OSM: 11604709 WD: Q106925455 47.48, 7.584 x 47.55, 7.612
    { 4342, NoLogo, 11229, LineMetaDataContent::RapidTransit, Color{0xffc0cb} }, // TL-3 OSM: 11637375 WD: Q5986357 20.62, -103.4 x 20.74, -103.3
    { 9, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xffa500} }, // 4 OSM: 11643429 WD: Q24837537 24.86, 102.6 x 25.11, 102.9
    { 4347, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xdd8800} }, // 4-环直快 OSM: 11665748 WD: Q15900365 29.53, 106.5 x 29.63, 106.7
    { 22, 21381, NoLogo, LineMetaDataContent::Subway, Color{0x6ad1e3} }, // 18 OSM: 11697795 WD: Q22100462 30.27, 104.1 x 30.61, 104.5
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0645ad} }, // 2 OSM: 11697809 WD: Q82669483 40.75, 111.6 x 40.87, 111.8
    { 11, NoLogo, 6360, LineMetaDataContent::Subway, Color{0xff8040} }, // M5 OSM: 11697885 WD: Q1641397 44.41, 26.01 x 44.43, 26.07
    { 4359, 21392, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7d2483} }, // ST OSM: 11714593 WD: Q6810422 35.17, 136.9 x 35.23, 137.1
    { 16, NoLogo, 18122, LineMetaDataContent::Subway, Color{0xff0000} }, // 2 OSM: 11720074 WD: Q6427302 22.57, 88.39 x 22.59, 88.43
    { 190, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x406681} }, // B OSM: 11727456 35.02, 135.7 x 35.03, 135.7
    { 207, 8751, 209, LineMetaDataContent::RapidTransit, Color{0xd7df23} }, // S4 OSM: 11758267 WD: Q680235 47.25, 11.08 x 47.58, 12.17
    { 157, 8751, 209, LineMetaDataContent::RapidTransit, Color{0xbec2d0} }, // S3 OSM: 11763877 WD: Q680235 47, 11.39 x 47.26, 11.51
    { 42, 8751, 209, LineMetaDataContent::RapidTransit, Color{0xd4b4c4} }, // S5 OSM: 11763897 WD: Q680235 47.24, 10.86 x 47.39, 11.78
    { 45, 8751, 209, LineMetaDataContent::RapidTransit, Color{0x257ca7} }, // S8 OSM: 11763916 WD: Q680235 47.42, 12.06 x 47.52, 12.63
    { 4362, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x9a897e} }, // E5 OSM: 11796871 WD: Q104233835 43.3, -1.983 x 43.32, -1.931
    { 57, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0101f8} }, // 3 OSM: 11798336 WD: Q19852709 31.5, 120.2 x 31.6, 120.4
    { 4365, 21402, 13477, LineMetaDataContent::Subway, Color{0xf19ebf} }, // M7 OSM: 11799411 WD: Q16949749 41.05, 28.83 x 41.09, 29
    { 4368, 21430, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0f6cc3} }, // TI OSM: 11801291 WD: Q906598 36.02, 139.2 x 36.33, 139.7
    { 4371, 21464, NoLogo, LineMetaDataContent::Subway, Color{0xf68b1e} }, // TN OSM: 11801775 WD: Q845954 35.51, 139.4 x 36.75, 139.8
    { 1360, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xf7943a} }, // O OSM: 11803501 WD: Q18385578 31.46, 74.24 x 31.59, 74.43
    { 27, NoLogo, 3117, LineMetaDataContent::Subway, Color{0x0099cc} }, // 6 OSM: 11807149 WD: Q3832666 40.82, 14.19 x 40.84, 14.25
    { 4374, 21496, NoLogo, LineMetaDataContent::RapidTransit, Color{} }, // FEX OSM: 11815470 WD: Q100533383 52.36, 13.36 x 52.55, 13.6
    { 4378, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // CK OSM: 11830794 WD: Q5097496 33.75, 130.7 x 33.87, 130.8
    { 388, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0072bc} }, // H OSM: 11839798 WD: Q1074266 42.64, 141.3 x 43.11, 141.7
    { 57, 21515, 14156, LineMetaDataContent::Subway, Color{0x008000} }, // 3 OSM: 11845129 WD: Q2889805 53.84, 27.53 x 53.91, 27.55
    { 4381, 21547, NoLogo, LineMetaDataContent::RapidTransit, Color{0xd12027} }, // NH OSM: 11851821 WD: Q1137838 34.76, 136.8 x 35.41, 137.4
    { 376, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // L2 OSM: 11871075 WD: Q42387974 30.44, 114.4 x 30.51, 114.5
    { 1776, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfece0c} }, // Gold OSM: 11873946 WD: Q5059275 35.21, -80.86 x 35.25, -80.82
    { 57, 21557, NoLogo, LineMetaDataContent::Subway, Color{0x90403e} }, // 3 OSM: 11899105 WD: Q30641320 21.03, 105.7 x 21.05, 105.8
    { 9, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xdae600} }, // 4 OSM: 11923211 WD: Q26262003 22.75, 108.2 x 22.77, 108.5
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // 2 OSM: 11993968 WD: Q97325177 37.69, 112.5 x 37.92, 112.6
    { 233, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 25 OSM: 12010107 WD: Q2619013 52.27, 4.831 x 52.34, 4.874
    { 27, 21587, NoLogo, LineMetaDataContent::Subway, Color{0xb36924} }, // 6 OSM: 12039115 WD: Q22100481 30.43, 103.9 x 30.81, 104.1
    { 4384, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf7f31d} }, // Z80 OSM: 12048896 47.49, 19.09 x 47.66, 19.67
    { 16, NoLogo, 20625, LineMetaDataContent::Tramway, Color{0x1d71b8} }, // 2 OSM: 12078298 WD: Q3238814 43.66, 7.203 x 43.7, 7.286
    { 19, 21597, NoLogo, LineMetaDataContent::Subway, Color{0x88dd00} }, // 8 OSM: 12086373 WD: Q26262006 30.54, 104 x 30.72, 104.2
    { 2121, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x4782ff} }, // 701 OSM: 12092635 33.76, -118.2 x 34.06, -117.2
    { 1600, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x4782ff} }, // 707 OSM: 12092635 33.76, -118.2 x 34.06, -117.2
    { 4388, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x4782ff} }, // 751 OSM: 12092635 33.76, -118.2 x 34.06, -117.2
    { 4392, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x4782ff} }, // 753 OSM: 12092635 33.76, -118.2 x 34.06, -117.2
    { 1895, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x4782ff} }, // 703 OSM: 12092635 33.76, -118.2 x 34.06, -117.2
    { 2297, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x4782ff} }, // 705 OSM: 12092635 33.76, -118.2 x 34.06, -117.2
    { 3434, NoLogo, 3610, LineMetaDataContent::RapidTransit, Color{0x008000} }, // 268 OSM: 12092988 WD: Q4162507 34.05, -118.5 x 34.7, -118.1
    { 4396, NoLogo, 3610, LineMetaDataContent::RapidTransit, Color{0x008000} }, // 200 OSM: 12092988 WD: Q4162507 34.05, -118.5 x 34.7, -118.1
    { 4400, NoLogo, 3610, LineMetaDataContent::RapidTransit, Color{0x008000} }, // 262 OSM: 12092988 WD: Q4162507 34.05, -118.5 x 34.7, -118.1
    { 4404, NoLogo, 3610, LineMetaDataContent::RapidTransit, Color{0x008000} }, // 208 OSM: 12092988 WD: Q4162507 34.05, -118.5 x 34.7, -118.1
    { 4408, NoLogo, 3610, LineMetaDataContent::RapidTransit, Color{0x008000} }, // 270 OSM: 12092988 WD: Q4162507 34.05, -118.5 x 34.7, -118.1
    { 4412, NoLogo, 3610, LineMetaDataContent::RapidTransit, Color{0x008000} }, // 212 OSM: 12092988 WD: Q4162507 34.05, -118.5 x 34.7, -118.1
    { 3173, NoLogo, 3610, LineMetaDataContent::RapidTransit, Color{0x008000} }, // 202 OSM: 12092988 WD: Q4162507 34.05, -118.5 x 34.7, -118.1
    { 3538, NoLogo, 3610, LineMetaDataContent::RapidTransit, Color{0x008000} }, // 264 OSM: 12092988 WD: Q4162507 34.05, -118.5 x 34.7, -118.1
    { 4416, NoLogo, 3610, LineMetaDataContent::RapidTransit, Color{0x008000} }, // 204 OSM: 12092988 WD: Q4162507 34.05, -118.5 x 34.7, -118.1
    { 3506, NoLogo, 3610, LineMetaDataContent::RapidTransit, Color{0x008000} }, // 230 OSM: 12092988 WD: Q4162507 34.05, -118.5 x 34.7, -118.1
    { 3498, NoLogo, 3610, LineMetaDataContent::RapidTransit, Color{0x008000} }, // 260 OSM: 12092988 WD: Q4162507 34.05, -118.5 x 34.7, -118.1
    { 3494, NoLogo, 3610, LineMetaDataContent::RapidTransit, Color{0x008000} }, // 222 OSM: 12092988 WD: Q4162507 34.05, -118.5 x 34.7, -118.1
    { 3550, NoLogo, 3610, LineMetaDataContent::RapidTransit, Color{0x008000} }, // 218 OSM: 12092988 WD: Q4162507 34.05, -118.5 x 34.7, -118.1
    { 4420, NoLogo, 3610, LineMetaDataContent::RapidTransit, Color{0x008000} }, // 266 OSM: 12092988 WD: Q4162507 34.05, -118.5 x 34.7, -118.1
    { 4424, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // 860 OSM: 12093019 33.19, -117.9 x 34.1, -117.3
    { 4428, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // 858 OSM: 12093019 33.19, -117.9 x 34.1, -117.3
    { 4432, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff8000} }, // 661 OSM: 12093056 33.19, -118.2 x 34.06, -117.4
    { 4436, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff8000} }, // 667 OSM: 12093056 33.19, -118.2 x 34.06, -117.4
    { 4440, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff8000} }, // 663 OSM: 12093056 33.19, -118.2 x 34.06, -117.4
    { 4444, NoLogo, 3610, LineMetaDataContent::RapidTransit, Color{0x800080} }, // 403 OSM: 12094164 WD: Q4801982 33.96, -118.2 x 34.06, -117.4
    { 4448, NoLogo, 3610, LineMetaDataContent::RapidTransit, Color{0x800080} }, // 407 OSM: 12094164 WD: Q4801982 33.96, -118.2 x 34.06, -117.4
    { 4452, NoLogo, 3610, LineMetaDataContent::RapidTransit, Color{0x800080} }, // 409 OSM: 12094164 WD: Q4801982 33.96, -118.2 x 34.06, -117.4
    { 4456, NoLogo, 3610, LineMetaDataContent::RapidTransit, Color{0x800080} }, // 401 OSM: 12094164 WD: Q4801982 33.96, -118.2 x 34.06, -117.4
    { 1038, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x800000} }, // 315 OSM: 12094201 34.05, -118.2 x 34.11, -117.3
    { 1030, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x800000} }, // 307 OSM: 12094201 34.05, -118.2 x 34.11, -117.3
    { 4460, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x800000} }, // 303 OSM: 12094201 34.05, -118.2 x 34.11, -117.3
    { 674, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x800000} }, // 301 OSM: 12094201 34.05, -118.2 x 34.11, -117.3
    { 4464, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x800000} }, // 319 OSM: 12094201 34.05, -118.2 x 34.11, -117.3
    { 1026, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x800000} }, // 309 OSM: 12094201 34.05, -118.2 x 34.11, -117.3
    { 4468, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x800000} }, // 313 OSM: 12094201 34.05, -118.2 x 34.11, -117.3
    { 4472, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x800000} }, // 363 OSM: 12094201 34.05, -118.2 x 34.11, -117.3
    { 4476, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x800000} }, // 321 OSM: 12094201 34.05, -118.2 x 34.11, -117.3
    { 4480, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x800000} }, // 325 OSM: 12094201 34.05, -118.2 x 34.11, -117.3
    { 4484, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x800000} }, // 377 OSM: 12094201 34.05, -118.2 x 34.11, -117.3
    { 4488, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x800000} }, // 353 OSM: 12094201 34.05, -118.2 x 34.11, -117.3
    { 4492, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x800000} }, // 369 OSM: 12094201 34.05, -118.2 x 34.11, -117.3
    { 4496, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x800000} }, // 331 OSM: 12094201 34.05, -118.2 x 34.11, -117.3
    { 4500, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x800000} }, // 373 OSM: 12094201 34.05, -118.2 x 34.11, -117.3
    { 4504, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x800000} }, // 357 OSM: 12094201 34.05, -118.2 x 34.11, -117.3
    { 1034, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x800000} }, // 305 OSM: 12094201 34.05, -118.2 x 34.11, -117.3
    { 4508, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x800000} }, // 367 OSM: 12094201 34.05, -118.2 x 34.11, -117.3
    { 4512, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x800000} }, // 359 OSM: 12094201 34.05, -118.2 x 34.11, -117.3
    { 4516, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x800000} }, // 351 OSM: 12094201 34.05, -118.2 x 34.11, -117.3
    { 4520, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x800000} }, // 333 OSM: 12094201 34.05, -118.2 x 34.11, -117.3
    { 4524, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x800000} }, // 335 OSM: 12094201 34.05, -118.2 x 34.11, -117.3
    { 4528, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x800000} }, // 317 OSM: 12094201 34.05, -118.2 x 34.11, -117.3
    { 4532, NoLogo, 3610, LineMetaDataContent::RapidTransit, Color{0xffc260} }, // 104 OSM: 12094203 WD: Q4132754 34.05, -119.2 x 34.29, -118.2
    { 4147, NoLogo, 3610, LineMetaDataContent::RapidTransit, Color{0xffc260} }, // 102 OSM: 12094203 WD: Q4132754 34.05, -119.2 x 34.29, -118.2
    { 169, 21607, NoLogo, LineMetaDataContent::Subway, Color{0x80e0a7} }, // 17 OSM: 12095438 WD: Q28973151 30.63, 103.8 x 30.76, 104.2
    { 40, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 7 OSM: 12114202 44.78, 20.37 x 44.81, 20.52
    { 123, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 9 OSM: 12114471 44.76, 20.37 x 44.81, 20.48
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 13 OSM: 12115860 44.77, 20.37 x 44.81, 20.43
    { 4536, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 11L OSM: 12115960 44.79, 20.37 x 44.82, 20.45
    { 4540, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 12L2 OSM: 12116052 44.77, 20.41 x 44.81, 20.49
    { 4545, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 12L5 OSM: 12116088 44.77, 20.41 x 44.82, 20.45
    { 53, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00985f} }, // 1 OSM: 12116142 60.16, 24.92 x 60.22, 24.96
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00985f} }, // 2 OSM: 12116144 60.16, 24.92 x 60.2, 24.96
    { 57, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00985f} }, // 3 OSM: 12116149 60.16, 24.9 x 60.2, 24.96
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00985f} }, // 4 OSM: 12116155 60.17, 24.87 x 60.2, 24.98
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00985f} }, // 5 OSM: 12116158 60.16, 24.94 x 60.17, 24.97
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00985f} }, // 6 OSM: 12116159 60.16, 24.92 x 60.21, 24.98
    { 40, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00985f} }, // 7 OSM: 12116160 60.15, 24.92 x 60.2, 24.96
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00985f} }, // 8 OSM: 12116163 60.16, 24.91 x 60.21, 24.98
    { 123, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00985f} }, // 9 OSM: 12116164 60.16, 24.91 x 60.2, 24.95
    { 63, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00985f} }, // 10 OSM: 12116165 60.16, 24.89 x 60.21, 24.95
    { 4550, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 14L3 OSM: 12116474 44.76, 20.47 x 44.81, 20.49
    { 438, 21618, 2680, LineMetaDataContent::RapidTransit, Color{0x7577c0} }, // L OSM: 12142601 WD: Q93379 48.81, 2.01 x 49.05, 2.324
    { 9, 21641, NoLogo, LineMetaDataContent::Subway, Color{0xabcd03} }, // 4 OSM: 12144421 WD: Q10946023 29.78, 121.4 x 29.98, 121.6
    { 1393, 21662, 7293, LineMetaDataContent::Tramway, Color{0x7c72b3} }, // T5 OSM: 12174617 WD: Q48848864 41.02, 28.94 x 41.09, 28.96
    { 48, 8751, 209, LineMetaDataContent::RapidTransit, Color{} }, // S2 OSM: 12206186 WD: Q680235 46.73, 12.27 x 46.83, 12.77
    { 134, 21690, NoLogo, LineMetaDataContent::Subway, Color{0xbba786} }, // 15 OSM: 12231218 WD: Q6553078 31.02, 121.4 x 31.35, 121.4
    { 1072, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xb8b803} }, // 2A OSM: 12231738 WD: Q30919856 20.95, 105.7 x 21.03, 105.8
    { 4555, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x5fb04f} }, // 1524 OSM: 12234225 WD: Q56525586 47.19, -122.4 x 47.6, -122.2
    { 4560, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x5fb04f} }, // 1513 OSM: 12234226 WD: Q56525586 47.19, -122.4 x 47.6, -122.2
    { 4565, NoLogo, 3610, LineMetaDataContent::RapidTransit, Color{0xffc260} }, // 103 OSM: 12237559 WD: Q4132754 34.05, -118.6 x 34.25, -118.2
    { 4569, NoLogo, 3610, LineMetaDataContent::RapidTransit, Color{0xffc260} }, // 108 OSM: 12237560 WD: Q4132754 34.05, -118.6 x 34.25, -118.2
    { 4573, NoLogo, 3610, LineMetaDataContent::RapidTransit, Color{0xffc260} }, // 115 OSM: 12237561 WD: Q4132754 34.05, -118.9 x 34.29, -118.2
    { 383, NoLogo, 3610, LineMetaDataContent::RapidTransit, Color{0xffc260} }, // 109 OSM: 12237561 WD: Q4132754 34.05, -118.9 x 34.29, -118.2
    { 4577, NoLogo, 3610, LineMetaDataContent::RapidTransit, Color{0xffc260} }, // 121 OSM: 12237561 WD: Q4132754 34.05, -118.9 x 34.29, -118.2
    { 4151, NoLogo, 3610, LineMetaDataContent::RapidTransit, Color{0xffc260} }, // 101 OSM: 12237561 WD: Q4132754 34.05, -118.9 x 34.29, -118.2
    { 1755, NoLogo, 3610, LineMetaDataContent::RapidTransit, Color{0xffc260} }, // 100 OSM: 12237562 WD: Q4132754 34.05, -118.9 x 34.29, -118.2
    { 4581, NoLogo, 3610, LineMetaDataContent::RapidTransit, Color{0xffc260} }, // 116 OSM: 12237562 WD: Q4132754 34.05, -118.9 x 34.29, -118.2
    { 4585, NoLogo, 3610, LineMetaDataContent::RapidTransit, Color{0xffc260} }, // 110 OSM: 12237562 WD: Q4132754 34.05, -118.9 x 34.29, -118.2
    { 4589, NoLogo, 3610, LineMetaDataContent::RapidTransit, Color{0xffc260} }, // 118 OSM: 12237562 WD: Q4132754 34.05, -118.9 x 34.29, -118.2
    { 4593, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x4782ff} }, // 700 OSM: 12238215 33.86, -118.2 x 34.06, -117.4
    { 4597, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x4782ff} }, // 712 OSM: 12238215 33.86, -118.2 x 34.06, -117.4
    { 4601, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x800000} }, // 381 OSM: 12241691 34.05, -118.2 x 34.11, -117.3
    { 4605, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x800000} }, // 382 OSM: 12241692 34.05, -118.2 x 34.11, -117.3
    { 4609, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // 811 OSM: 12242583 33.55, -117.9 x 33.98, -117.4
    { 4613, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // 809 OSM: 12242583 33.55, -117.9 x 33.98, -117.4
    { 4617, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // 817 OSM: 12242583 33.55, -117.9 x 33.98, -117.4
    { 4621, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // 805 OSM: 12242584 33.66, -117.9 x 34.1, -117.3
    { 4625, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // 807 OSM: 12242585 33.55, -117.9 x 34.1, -117.3
    { 4629, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // 814 OSM: 12242586 33.55, -117.9 x 33.98, -117.4
    { 4633, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // 806 OSM: 12242586 33.55, -117.9 x 33.98, -117.4
    { 4637, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // 800 OSM: 12242587 33.19, -117.9 x 33.98, -117.4
    { 4641, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // 802 OSM: 12242588 33.55, -117.9 x 34.1, -117.3
    { 4645, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // 810 OSM: 12242588 33.55, -117.9 x 34.1, -117.3
    { 4649, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // 808 OSM: 12242588 33.55, -117.9 x 34.1, -117.3
    { 4653, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // 812 OSM: 12242589 33.19, -117.9 x 34.1, -117.3
    { 4657, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // 803 OSM: 12242590 33.19, -117.9 x 34.1, -117.3
    { 4661, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // 815 OSM: 12242590 33.19, -117.9 x 34.1, -117.3
    { 4665, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff8000} }, // 686 OSM: 12242591 33.66, -118.2 x 34.06, -117.7
    { 4669, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff8000} }, // 688 OSM: 12242592 33.55, -118.2 x 34.06, -117.7
    { 4673, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff8000} }, // 684 OSM: 12242592 33.55, -118.2 x 34.06, -117.7
    { 4677, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff8000} }, // 685 OSM: 12242593 33.55, -118.2 x 34.06, -117.7
    { 4681, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff8000} }, // 689 OSM: 12242594 33.66, -118.2 x 34.06, -117.7
    { 4685, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff8000} }, // 683 OSM: 12242594 33.66, -118.2 x 34.06, -117.7
    { 4689, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff8000} }, // 681 OSM: 12242595 33.55, -118.2 x 34.06, -117.7
    { 4693, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff8000} }, // 607 OSM: 12242596 33.19, -118.2 x 34.06, -117.4
    { 4697, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff8000} }, // 605 OSM: 12242596 33.19, -118.2 x 34.06, -117.4
    { 4701, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff8000} }, // 603 OSM: 12242596 33.19, -118.2 x 34.06, -117.4
    { 4705, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff8000} }, // 604 OSM: 12242597 33.19, -118.2 x 34.06, -117.4
    { 4709, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff8000} }, // 602 OSM: 12242597 33.19, -118.2 x 34.06, -117.4
    { 4713, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff8000} }, // 606 OSM: 12242597 33.19, -118.2 x 34.06, -117.4
    { 4717, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff8000} }, // 609 OSM: 12242598 33.19, -118.2 x 34.06, -117.4
    { 4721, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff8000} }, // 601 OSM: 12242598 33.19, -118.2 x 34.06, -117.4
    { 4725, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff8000} }, // 608 OSM: 12242599 33.19, -118.2 x 34.06, -117.4
    { 4729, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff8000} }, // 600 OSM: 12242599 33.19, -118.2 x 34.06, -117.4
    { 4733, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 463 OSM: 12246240 37.31, -122.4 x 37.78, -121.9
    { 4737, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 427 OSM: 12246240 37.31, -122.4 x 37.78, -121.9
    { 4741, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 465 OSM: 12246240 37.31, -122.4 x 37.78, -121.9
    { 4745, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 461 OSM: 12246240 37.31, -122.4 x 37.78, -121.9
    { 4749, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 425 OSM: 12246240 37.31, -122.4 x 37.78, -121.9
    { 4753, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 455 OSM: 12246240 37.31, -122.4 x 37.78, -121.9
    { 4757, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 423 OSM: 12246240 37.31, -122.4 x 37.78, -121.9
    { 4761, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 475 OSM: 12246240 37.31, -122.4 x 37.78, -121.9
    { 4765, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 457 OSM: 12246240 37.31, -122.4 x 37.78, -121.9
    { 4769, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 467 OSM: 12246240 37.31, -122.4 x 37.78, -121.9
    { 4773, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 459 OSM: 12246240 37.31, -122.4 x 37.78, -121.9
    { 4777, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 445 OSM: 12246240 37.31, -122.4 x 37.78, -121.9
    { 4781, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 473 OSM: 12246240 37.31, -122.4 x 37.78, -121.9
    { 4785, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 441 OSM: 12246240 37.31, -122.4 x 37.78, -121.9
    { 4789, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 439 OSM: 12246240 37.31, -122.4 x 37.78, -121.9
    { 4793, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 471 OSM: 12246240 37.31, -122.4 x 37.78, -121.9
    { 4797, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 431 OSM: 12246240 37.31, -122.4 x 37.78, -121.9
    { 4801, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 451 OSM: 12246240 37.31, -122.4 x 37.78, -121.9
    { 4805, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 449 OSM: 12246240 37.31, -122.4 x 37.78, -121.9
    { 4809, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 447 OSM: 12246240 37.31, -122.4 x 37.78, -121.9
    { 4813, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 429 OSM: 12246240 37.31, -122.4 x 37.78, -121.9
    { 90, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 437 OSM: 12246240 37.31, -122.4 x 37.78, -121.9
    { 4817, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 453 OSM: 12246240 37.31, -122.4 x 37.78, -121.9
    { 4821, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 443 OSM: 12246240 37.31, -122.4 x 37.78, -121.9
    { 4825, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 433 OSM: 12246240 37.31, -122.4 x 37.78, -121.9
    { 4829, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 421 OSM: 12246240 37.31, -122.4 x 37.78, -121.9
    { 4833, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 469 OSM: 12246240 37.31, -122.4 x 37.78, -121.9
    { 4837, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 435 OSM: 12246240 37.31, -122.4 x 37.78, -121.9
    { 4841, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 477 OSM: 12246240 37.31, -122.4 x 37.78, -121.9
    { 4845, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 424 OSM: 12246241 37.31, -122.4 x 37.78, -121.9
    { 4849, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 432 OSM: 12246241 37.31, -122.4 x 37.78, -121.9
    { 4853, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 448 OSM: 12246241 37.31, -122.4 x 37.78, -121.9
    { 4857, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 422 OSM: 12246241 37.31, -122.4 x 37.78, -121.9
    { 4861, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 462 OSM: 12246241 37.31, -122.4 x 37.78, -121.9
    { 4865, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 428 OSM: 12246241 37.31, -122.4 x 37.78, -121.9
    { 4869, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 474 OSM: 12246241 37.31, -122.4 x 37.78, -121.9
    { 4873, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 468 OSM: 12246241 37.31, -122.4 x 37.78, -121.9
    { 4877, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 436 OSM: 12246241 37.31, -122.4 x 37.78, -121.9
    { 4881, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 442 OSM: 12246241 37.31, -122.4 x 37.78, -121.9
    { 4885, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 438 OSM: 12246241 37.31, -122.4 x 37.78, -121.9
    { 4889, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 476 OSM: 12246241 37.31, -122.4 x 37.78, -121.9
    { 4893, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 452 OSM: 12246241 37.31, -122.4 x 37.78, -121.9
    { 4897, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 466 OSM: 12246241 37.31, -122.4 x 37.78, -121.9
    { 4901, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 426 OSM: 12246241 37.31, -122.4 x 37.78, -121.9
    { 4905, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 458 OSM: 12246241 37.31, -122.4 x 37.78, -121.9
    { 4909, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 480 OSM: 12246241 37.31, -122.4 x 37.78, -121.9
    { 4913, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 430 OSM: 12246241 37.31, -122.4 x 37.78, -121.9
    { 4917, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 460 OSM: 12246241 37.31, -122.4 x 37.78, -121.9
    { 4921, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 454 OSM: 12246241 37.31, -122.4 x 37.78, -121.9
    { 4925, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 440 OSM: 12246241 37.31, -122.4 x 37.78, -121.9
    { 4929, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 444 OSM: 12246241 37.31, -122.4 x 37.78, -121.9
    { 4933, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 456 OSM: 12246241 37.31, -122.4 x 37.78, -121.9
    { 4937, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 450 OSM: 12246241 37.31, -122.4 x 37.78, -121.9
    { 4941, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 446 OSM: 12246241 37.31, -122.4 x 37.78, -121.9
    { 4945, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 464 OSM: 12246241 37.31, -122.4 x 37.78, -121.9
    { 4949, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 434 OSM: 12246241 37.31, -122.4 x 37.78, -121.9
    { 712, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe73035} }, // 300 OSM: 12250423 38.22, -77.46 x 38.9, -77
    { 670, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe73035} }, // 302 OSM: 12250424 38.22, -77.46 x 38.9, -77
    { 666, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe73035} }, // 306 OSM: 12250424 38.22, -77.46 x 38.9, -77
    { 728, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe73035} }, // 314 OSM: 12250424 38.22, -77.46 x 38.9, -77
    { 662, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe73035} }, // 310 OSM: 12250424 38.22, -77.46 x 38.9, -77
    { 4155, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xed772d} }, // SI OSM: 12250873 35.74, 139.3 x 35.85, 139.7
    { 1470, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfaa93f} }, // 857 OSM: 12252673 WD: Q5025789 38.9, -77.01 x 39.28, -76.62
    { 4953, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfaa93f} }, // 851 OSM: 12252674 WD: Q5025789 38.9, -77.01 x 39.28, -76.62
    { 4957, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfaa93f} }, // 849 OSM: 12252674 WD: Q5025789 38.9, -77.01 x 39.28, -76.62
    { 4961, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfaa93f} }, // 846 OSM: 12252675 WD: Q5025789 38.9, -77.01 x 39.28, -76.62
    { 4428, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfaa93f} }, // 858 OSM: 12252676 WD: Q5025789 38.9, -77.01 x 39.28, -76.62
    { 4965, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfaa93f} }, // 852 OSM: 12252676 WD: Q5025789 38.9, -77.01 x 39.28, -76.62
    { 4969, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfbcab6} }, // 877 OSM: 12252790 WD: Q4979520 38.9, -77.63 x 39.31, -76.99
    { 4973, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfbcab6} }, // 875 OSM: 12252790 WD: Q4979520 38.9, -77.63 x 39.31, -76.99
    { 4977, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfbcab6} }, // 880 OSM: 12252791 WD: Q4979520 38.9, -77.63 x 39.31, -76.99
    { 4981, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfbcab6} }, // 872 OSM: 12252792 WD: Q4979520 38.9, -77.96 x 39.46, -76.99
    { 1650, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xbdbadc} }, // 502 OSM: 12253097 WD: Q7163197 38.9, -77.01 x 39.56, -76.07
    { 4985, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xbdbadc} }, // 536 OSM: 12253098 WD: Q7163197 38.9, -77.01 x 39.56, -76.07
    { 4989, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xbdbadc} }, // 537 OSM: 12253099 WD: Q7163197 38.9, -77.01 x 39.56, -76.07
    { 3241, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xbdbadc} }, // 525 OSM: 12253100 WD: Q7163197 38.9, -77.01 x 39.56, -76.07
    { 4821, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xbdbadc} }, // 443 OSM: 12253101 WD: Q7163197 38.9, -77.01 x 39.31, -76.62
    { 4817, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xbdbadc} }, // 453 OSM: 12253102 WD: Q7163197 38.9, -77.01 x 39.31, -76.62
    { 1277, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xbdbadc} }, // 487 OSM: 12253102 WD: Q7163197 38.9, -77.01 x 39.31, -76.62
    { 4993, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xbdbadc} }, // 497 OSM: 12253102 WD: Q7163197 38.9, -77.01 x 39.31, -76.62
    { 4444, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xbdbadc} }, // 403 OSM: 12253102 WD: Q7163197 38.9, -77.01 x 39.31, -76.62
    { 4997, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xbdbadc} }, // 495 OSM: 12253102 WD: Q7163197 38.9, -77.01 x 39.31, -76.62
    { 5001, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xbdbadc} }, // 491 OSM: 12253102 WD: Q7163197 38.9, -77.01 x 39.31, -76.62
    { 5005, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xbdbadc} }, // 415 OSM: 12253102 WD: Q7163197 38.9, -77.01 x 39.31, -76.62
    { 4737, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xbdbadc} }, // 427 OSM: 12253102 WD: Q7163197 38.9, -77.01 x 39.31, -76.62
    { 5009, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xbdbadc} }, // 499 OSM: 12253102 WD: Q7163197 38.9, -77.01 x 39.31, -76.62
    { 4829, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xbdbadc} }, // 421 OSM: 12253102 WD: Q7163197 38.9, -77.01 x 39.31, -76.62
    { 4448, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xbdbadc} }, // 407 OSM: 12253102 WD: Q7163197 38.9, -77.01 x 39.31, -76.62
    { 4805, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xbdbadc} }, // 449 OSM: 12253102 WD: Q7163197 38.9, -77.01 x 39.31, -76.62
    { 5013, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xbdbadc} }, // 485 OSM: 12253102 WD: Q7163197 38.9, -77.01 x 39.31, -76.62
    { 5017, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xbdbadc} }, // 481 OSM: 12253102 WD: Q7163197 38.9, -77.01 x 39.31, -76.62
    { 4837, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xbdbadc} }, // 435 OSM: 12253102 WD: Q7163197 38.9, -77.01 x 39.31, -76.62
    { 4797, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xbdbadc} }, // 431 OSM: 12253102 WD: Q7163197 38.9, -77.01 x 39.31, -76.62
    { 3414, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xbdbadc} }, // 478 OSM: 12253103 WD: Q7163197 38.9, -77.01 x 39.31, -76.61
    { 4845, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xbdbadc} }, // 424 OSM: 12253103 WD: Q7163197 38.9, -77.01 x 39.31, -76.61
    { 639, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xbdbadc} }, // 410 OSM: 12253103 WD: Q7163197 38.9, -77.01 x 39.31, -76.61
    { 4853, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xbdbadc} }, // 448 OSM: 12253103 WD: Q7163197 38.9, -77.01 x 39.31, -76.61
    { 5021, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xbdbadc} }, // 492 OSM: 12253103 WD: Q7163197 38.9, -77.01 x 39.31, -76.61
    { 4925, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xbdbadc} }, // 440 OSM: 12253103 WD: Q7163197 38.9, -77.01 x 39.31, -76.61
    { 5025, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xbdbadc} }, // 414 OSM: 12253103 WD: Q7163197 38.9, -77.01 x 39.31, -76.61
    { 4893, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xbdbadc} }, // 452 OSM: 12253103 WD: Q7163197 38.9, -77.01 x 39.31, -76.61
    { 4901, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xbdbadc} }, // 426 OSM: 12253103 WD: Q7163197 38.9, -77.01 x 39.31, -76.61
    { 5029, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xbdbadc} }, // 486 OSM: 12253103 WD: Q7163197 38.9, -77.01 x 39.31, -76.61
    { 5033, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xbdbadc} }, // 482 OSM: 12253103 WD: Q7163197 38.9, -77.01 x 39.31, -76.61
    { 5037, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xbdbadc} }, // 416 OSM: 12253103 WD: Q7163197 38.9, -77.01 x 39.31, -76.61
    { 4889, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xbdbadc} }, // 476 OSM: 12253103 WD: Q7163197 38.9, -77.01 x 39.31, -76.61
    { 5041, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xbdbadc} }, // 490 OSM: 12253103 WD: Q7163197 38.9, -77.01 x 39.31, -76.61
    { 5045, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xbdbadc} }, // 494 OSM: 12253103 WD: Q7163197 38.9, -77.01 x 39.31, -76.61
    { 5049, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xbdbadc} }, // 696 OSM: 12253104 WD: Q7163197 38.9, -77.01 x 39.34, -76.42
    { 5053, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xbdbadc} }, // 694 OSM: 12253104 WD: Q7163197 38.9, -77.01 x 39.34, -76.42
    { 5057, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xbdbadc} }, // 642 OSM: 12253104 WD: Q7163197 38.9, -77.01 x 39.34, -76.42
    { 5061, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xbdbadc} }, // 612 OSM: 12253104 WD: Q7163197 38.9, -77.01 x 39.34, -76.42
    { 4669, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xbdbadc} }, // 688 OSM: 12253104 WD: Q7163197 38.9, -77.01 x 39.34, -76.42
    { 5065, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xbdbadc} }, // 692 OSM: 12253104 WD: Q7163197 38.9, -77.01 x 39.34, -76.42
    { 5069, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xbdbadc} }, // 698 OSM: 12253104 WD: Q7163197 38.9, -77.01 x 39.34, -76.42
    { 5073, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xbdbadc} }, // 634 OSM: 12253104 WD: Q7163197 38.9, -77.01 x 39.34, -76.42
    { 4689, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xbdbadc} }, // 681 OSM: 12253105 WD: Q7163197 38.9, -77.01 x 39.34, -76.42
    { 5077, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xbdbadc} }, // 677 OSM: 12253105 WD: Q7163197 38.9, -77.01 x 39.34, -76.42
    { 4681, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xbdbadc} }, // 689 OSM: 12253105 WD: Q7163197 38.9, -77.01 x 39.34, -76.42
    { 5081, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xbdbadc} }, // 641 OSM: 12253105 WD: Q7163197 38.9, -77.01 x 39.34, -76.42
    { 5085, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xbdbadc} }, // 675 OSM: 12253105 WD: Q7163197 38.9, -77.01 x 39.34, -76.42
    { 576, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa82618} }, // 117 OSM: 12256726 41.59, -87.62 x 41.88, -86.87
    { 5089, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa82618} }, // 111 OSM: 12256727 41.59, -87.62 x 41.88, -86.87
    { 4573, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa82618} }, // 115 OSM: 12256728 41.59, -87.62 x 41.88, -86.87
    { 4151, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa82618} }, // 101 OSM: 12256729 41.59, -87.62 x 41.88, -86.87
    { 4721, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa82618} }, // 601 OSM: 12256729 41.59, -87.62 x 41.88, -86.87
    { 5093, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa82618} }, // 106 OSM: 12256730 41.59, -87.62 x 41.88, -86.87
    { 4585, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa82618} }, // 110 OSM: 12256731 41.59, -87.62 x 41.88, -86.87
    { 5097, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa82618} }, // 112 OSM: 12256732 41.59, -87.62 x 41.88, -86.87
    { 4569, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa82618} }, // 108 OSM: 12256733 41.59, -87.62 x 41.88, -86.87
    { 4147, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa82618} }, // 102 OSM: 12256734 41.59, -87.62 x 41.88, -86.87
    { 5101, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa82618} }, // 114 OSM: 12256735 41.59, -87.62 x 41.88, -86.87
    { 2133, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa82618} }, // 205 OSM: 12256736 41.6, -87.62 x 41.88, -87.34
    { 3442, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa82618} }, // 203 OSM: 12256737 41.6, -87.62 x 41.88, -87.34
    { 1655, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa82618} }, // 504 OSM: 12256738 41.59, -87.62 x 41.88, -86.29
    { 27, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa82618} }, // 6 OSM: 12256739 41.59, -87.62 x 41.88, -86.29
    { 169, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa82618} }, // 17 OSM: 12256740 41.59, -87.62 x 41.88, -86.29
    { 52, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa82618} }, // 11 OSM: 12256741 41.59, -87.62 x 41.88, -86.29
    { 580, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa82618} }, // 119 OSM: 12256742 41.59, -87.62 x 41.88, -86.87
    { 592, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa82618} }, // 209 OSM: 12256743 41.6, -87.62 x 41.88, -87.34
    { 4697, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa82618} }, // 605 OSM: 12256744 41.59, -87.62 x 41.88, -86.87
    { 4701, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa82618} }, // 603 OSM: 12256744 41.59, -87.62 x 41.88, -86.87
    { 5105, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa82618} }, // 613 OSM: 12256744 41.59, -87.62 x 41.88, -86.87
    { 4725, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa82618} }, // 608 OSM: 12256745 41.59, -87.62 x 41.88, -86.87
    { 2262, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa82618} }, // 610 OSM: 12256745 41.59, -87.62 x 41.88, -86.87
    { 4713, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa82618} }, // 606 OSM: 12256745 41.59, -87.62 x 41.88, -86.87
    { 4729, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa82618} }, // 600 OSM: 12256745 41.59, -87.62 x 41.88, -86.87
    { 5109, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa82618} }, // 503 OSM: 12256746 41.59, -87.62 x 41.88, -86.29
    { 2258, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa82618} }, // 507 OSM: 12256746 41.59, -87.62 x 41.88, -86.29
    { 5113, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa82618} }, // 509 OSM: 12256746 41.59, -87.62 x 41.88, -86.29
    { 2254, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa82618} }, // 505 OSM: 12256746 41.59, -87.62 x 41.88, -86.29
    { 1905, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa82618} }, // 511 OSM: 12256746 41.59, -87.62 x 41.88, -86.29
    { 1640, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa82618} }, // 510 OSM: 12256747 41.59, -87.62 x 41.88, -86.29
    { 1650, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa82618} }, // 502 OSM: 12256747 41.59, -87.62 x 41.88, -86.29
    { 5117, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa82618} }, // 506 OSM: 12256747 41.59, -87.62 x 41.88, -86.29
    { 1665, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa82618} }, // 508 OSM: 12256747 41.59, -87.62 x 41.88, -86.29
    { 3494, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa82618} }, // 222 OSM: 12256748 41.6, -87.62 x 41.88, -87.34
    { 3534, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa82618} }, // 214 OSM: 12256748 41.6, -87.62 x 41.88, -87.34
    { 5121, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa82618} }, // 220 OSM: 12256748 41.6, -87.62 x 41.88, -87.34
    { 3550, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa82618} }, // 218 OSM: 12256748 41.6, -87.62 x 41.88, -87.34
    { 5125, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa82618} }, // 216 OSM: 12256748 41.6, -87.62 x 41.88, -87.34
    { 3446, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa82618} }, // 207 OSM: 12256749 41.6, -87.62 x 41.88, -87.34
    { 5129, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa82618} }, // 217 OSM: 12256749 41.6, -87.62 x 41.88, -87.34
    { 4532, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa82618} }, // 104 OSM: 12256750 41.59, -87.62 x 41.88, -86.87
    { 4581, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa82618} }, // 116 OSM: 12256750 41.59, -87.62 x 41.88, -86.87
    { 4589, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa82618} }, // 118 OSM: 12256750 41.59, -87.62 x 41.88, -86.87
    { 4577, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa82618} }, // 121 OSM: 12256751 41.59, -87.62 x 41.88, -86.87
    { 383, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa82618} }, // 109 OSM: 12256751 41.59, -87.62 x 41.88, -86.87
    { 5133, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa82618} }, // 107 OSM: 12256751 41.59, -87.62 x 41.88, -86.87
    { 5137, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa82618} }, // 113 OSM: 12256751 41.59, -87.62 x 41.88, -86.87
    { 5141, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa82618} }, // 123 OSM: 12256751 41.59, -87.62 x 41.88, -86.87
    { 2121, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa82618} }, // 701 OSM: 12256752 41.68, -86.87 x 41.72, -86.29
    { 1895, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa82618} }, // 703 OSM: 12256752 41.68, -86.87 x 41.72, -86.29
    { 4456, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa82618} }, // 401 OSM: 12256752 41.68, -86.87 x 41.72, -86.29
    { 4444, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa82618} }, // 403 OSM: 12256752 41.68, -86.87 x 41.72, -86.29
    { 4857, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa82618} }, // 422 OSM: 12256753 41.68, -86.87 x 41.72, -86.29
    { 4845, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa82618} }, // 424 OSM: 12256753 41.68, -86.87 x 41.72, -86.29
    { 5145, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe3e049} }, // TECO OSM: 12321313 27.94, -82.46 x 27.96, -82.44
    { 310, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // M OSM: 12331275 43.03, -87.92 x 43.05, -87.9
    { 33, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // S OSM: 12332844 34.65, 133.9 x 34.67, 133.9
    { 388, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // H OSM: 12332845 34.66, 133.9 x 34.67, 133.9
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // 2 OSM: 12340019 WD: Q18155116 29.95, -90.07 x 29.96, -90.06
    { 414, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x90ee90} }, // 48 OSM: 12340020 29.96, -90.1 x 29.98, -90.08
    { 510, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 47 OSM: 12340021 29.95, -90.11 x 29.98, -90.07
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 12 OSM: 12340022 29.93, -90.13 x 29.96, -90.07
    { 273, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00aae4} }, // Blue OSM: 12340243 34.74, -92.27 x 34.76, -92.26
    { 463, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x66ff00} }, // Green OSM: 12340244 34.74, -92.27 x 34.75, -92.26
    { 53, NoLogo, 3117, LineMetaDataContent::Subway, Color{0xffff00} }, // 1 OSM: 12341393 WD: Q1085934 40.84, 14.22 x 40.9, 14.27
    { 502, NoLogo, 21700, LineMetaDataContent::Tramway, Color{0xfeba33} }, // T2 OSM: 12342707 WD: Q30634535 38.4, 27.07 x 38.44, 27.17
    { 5150, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x961a54} }, // MXP2 OSM: 12343018 WD: Q1858023 45.48, 8.704 x 45.65, 9.215
    { 1427, NoLogo, 21720, LineMetaDataContent::RapidTransit, Color{0x800080} }, // Purple OSM: 12356340 WD: Q4533683 29.7, -95.37 x 29.76, -95.33
    { 285, NoLogo, 21720, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // Red OSM: 12356341 WD: Q16934038 29.67, -95.41 x 29.83, -95.36
    { 463, NoLogo, 21720, LineMetaDataContent::RapidTransit, Color{0x008000} }, // Green OSM: 12356342 WD: Q4262189 29.74, -95.37 x 29.76, -95.3
    { 5155, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff1b6e} }, // APT Rose OSM: 12360663 32.86, -96.94 x 32.87, -96.93
    { 5164, 21743, 9444, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // m1 OSM: 12371355 WD: Q685114 46.52, 6.564 x 46.54, 6.63
    { 200, NoLogo, 21700, LineMetaDataContent::Tramway, Color{0x63a14d} }, // T1 OSM: 12378475 WD: Q21523607 38.45, 27.07 x 38.48, 27.13
    { 57, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff8000} }, // 3 OSM: 12380649 WD: Q56377988 25.67, -100.3 x 25.71, -100.3
    { 6, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xb5e51d} }, // 5 OSM: 12385671 WD: Q43445187 31.7, 117.3 x 31.81, 117.3
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x146eb7} }, // 4 OSM: 12400338 WD: Q107104582 40.83, 14.26 x 40.85, 14.31
    { 53, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x4096d2} }, // 1 OSM: 12400369 WD: Q107104562 40.84, 14.26 x 40.87, 14.29
    { 5167, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x8fbc8f} }, // 399 OSM: 12417807 33.12, -117.4 x 33.22, -117.1
    { 5171, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x662483} }, // Π5 OSM: 12423300 WD: Q35645597 37.91, 22.1 x 38.24, 23.94
    { 16, 21770, NoLogo, LineMetaDataContent::Tramway, Color{0x025257} }, // 2 OSM: 12462807 WD: Q2274338 40.82, 14.13 x 40.87, 14.31
    { 5175, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0d82c7} }, // OH OSM: 12463786 WD: Q11430772 35.23, 139 x 35.69, 139.7
    { 40, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x88129e} }, // 7 OSM: 12561898 30.2, 120.2 x 30.33, 120.5
    { 5178, 21794, 4327, LineMetaDataContent::Tramway, Color{0x5291ce} }, // T9 OSM: 12564972 WD: Q3537038 48.75, 2.365 x 48.82, 2.419
    { 5181, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x015dab} }, // Atlantic City OSM: 12577780 WD: Q756350 39.36, -75.2 x 40.01, -74.44
    { 53, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 1 OSM: 12606970 WD: Q107191166 37.99, -1.174 x 38.04, -1.124
    { 6, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xffa500} }, // 5 OSM: 12608512 19.22, 72.98 x 19.3, 73.13
    { 2657, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x78b942} }, // Verde OSM: 12632067 -9.672, -35.74 x -9.65, -35.72
    { 2688, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x1a5ba3} }, // Azul OSM: 12632071 -9.625, -35.86 x -9.478, -35.75
    { 8, NoLogo, 14210, LineMetaDataContent::Subway, Color{0xffff00} }, // M4 OSM: 12668937 WD: Q101570868 42.65, 23.26 x 42.74, 23.42
    { 57, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // 3 OSM: 12758107 61.44, 23.74 x 61.5, 23.87
    { 330, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x81cf00} }, // R OSM: 12765542 WD: Q3239181 50.64, 3.071 x 50.69, 3.179
    { 1672, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0099ff} }, // T OSM: 12765723 WD: Q3239234 50.64, 3.071 x 50.72, 3.159
    { 5195, 21827, 13477, LineMetaDataContent::Subway, Color{0xffd400} }, // M9 OSM: 12769834 WD: Q25209252 41.06, 28.77 x 41.08, 28.81
    { 53, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // 1 OSM: 12771497 31.53, 130.5 x 31.6, 130.6
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 2 OSM: 12771498 31.56, 130.5 x 31.6, 130.6
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0645ad} }, // 2 OSM: 12791163 WD: Q19856264 26.52, 106.6 x 26.7, 106.8
    { 5198, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xcc0000} }, // Route 2020 OSM: 12820286 WD: Q97940934 24.96, 55.13 x 25.06, 55.16
    { 57, NoLogo, 18443, LineMetaDataContent::Subway, Color{0x0c89de} }, // 3 OSM: 12893656 WD: Q47500936 24.47, 118.1 x 24.58, 118.3
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x529fc9} }, // 2 OSM: 12914035 WD: Q106783516 31.75, 119.9 x 31.81, 120.1
    { 53, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xe82311} }, // 1 OSM: 12920991 30.08, 120.2 x 30.31, 120.5
    { 6, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xa6e35f} }, // 5 OSM: 12925442 WD: Q15939245 34.22, 108.6 x 34.27, 109
    { 57, NoLogo, 20766, LineMetaDataContent::Subway, Color{0x008bd5} }, // 3 OSM: 12935364 WD: Q47291030 34.14, 117.1 x 34.3, 117.3
    { 16, NoLogo, 20766, LineMetaDataContent::Subway, Color{0xef8200} }, // 2 OSM: 12935365 WD: Q47004987 34.21, 117.2 x 34.33, 117.3
    { 53, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xc4608c} }, // 1 OSM: 12942003 WD: Q15936968 34.66, 112.3 x 34.7, 112.6
    { 123, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff9e1b} }, // 9 OSM: 13042254 WD: Q97350661 34.27, 109.1 x 34.4, 109.2
    { 19, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x9d2933} }, // 8 OSM: 13042427 30.3, 120.4 x 30.31, 120.5
    { 53, NoLogo, 13649, LineMetaDataContent::RapidTransit, Color{0xe10506} }, // 1 OSM: 13058394 WD: Q15078613 13.8, 100.5 x 14, 100.6
    { 123, 21855, NoLogo, LineMetaDataContent::Subway, Color{0xd2691e} }, // 9 OSM: 13060970 WD: Q133748 30.31, 120.3 x 30.46, 120.3
    { 53, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xd9aa19} }, // 1 OSM: 13067815 36.17, 120.4 x 36.34, 120.4
    { 19, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xc02996} }, // 8 OSM: 13068450 36.17, 120 x 36.4, 120.4
    { 27, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0000c6} }, // 6 OSM: 13077350 30.05, 119.9 x 30.31, 120.2
    { 9, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x6bc349} }, // 4 OSM: 13077360 30.16, 120.1 x 30.3, 120.2
    { 5209, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0033ff} }, // HH OSM: 13078550 30.38, 120.3 x 30.52, 120.7
    { 59, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x1b61ae} }, // S1 OSM: 13084233 27.91, 120.6 x 27.99, 121
    { 123, 21875, NoLogo, LineMetaDataContent::Subway, Color{0xffb81c} }, // 9 OSM: 13088859 WD: Q28972638 30.58, 104 x 30.7, 104.1
    { 6, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xf348b4} }, // 5 OSM: 13091428 WD: Q6553133 31.23, 120.4 x 31.37, 120.8
    { 5212, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xd42d1b} }, // THP1 OSM: 13140107 23.18, 113.5 x 23.22, 113.5
    { 1238, NoLogo, 2535, LineMetaDataContent::Tramway, Color{0x172983} }, // L5 OSM: 13154071 WD: Q9025966 38.34, -0.479 x 38.35, -0.4669
    { 5217, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // Ouargla tram OSM: 13159622 WD: Q16680954 31.94, 5.265 x 31.96, 5.333
    { 16, 21885, NoLogo, LineMetaDataContent::Subway, Color{0xdb6d1c} }, // 2 OSM: 13176924 WD: Q5947229 22.48, 113.9 x 22.57, 114.2
    { 19, 21908, NoLogo, LineMetaDataContent::Subway, Color{0xdb6d1c} }, // 8 OSM: 13176927 WD: Q11174946 22.56, 114.2 x 22.59, 114.3
    { 1355, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xed1c24} }, // 44 OSM: 13199272 44.44, 26.02 x 44.47, 26.09
    { 196, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xb58bd7} }, // S6 OSM: 13200482 31.92, 118.9 x 32.06, 119.2
    { 63, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe50a80} }, // 10 OSM: 13217677 55.67, 52.28 x 55.77, 52.45
    { 123, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x362d86} }, // 9 OSM: 13217678 55.67, 52.28 x 55.77, 52.45
    { 52, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x182f72} }, // 11 OSM: 13217860 55.7, 52.34 x 55.74, 52.47
    { 40, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x808080} }, // 7 OSM: 13242817 49.17, 16.57 x 49.23, 16.63
    { 22, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0047ba} }, // 18 OSM: 13246294 22.7, 113.3 x 23.13, 113.6
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x008000} }, // 2 OSM: 13250192 WD: Q10921993 45.71, 126.5 x 45.87, 126.8
    { 5230, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0066cc} }, // TRS OSM: 13262889 WD: Q39081226 -24.98, -65.65 x -24.65, -65.04
    { 48, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xe4222b} }, // S2 OSM: 13282128 27.75, 120.6 x 28.08, 121
    { 5234, 21931, 3199, LineMetaDataContent::Subway, Color{0xa12830} }, // 1E OSM: 13298577 WD: Q1039452 39.85, 116.5 x 39.91, 116.7
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009cdd} }, // 13 OSM: 13305615 53.38, 14.53 x 53.43, 14.64
    { 5237, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // TAD OSM: 13308590 WD: Q18286525 -27.78, -64.27 x -27.73, -64.24
    { 5241, 21956, 13477, LineMetaDataContent::RapidTransit, Color{} }, // F1 OSM: 13313680 WD: Q503503 41.03, 28.99 x 41.04, 28.99
    { 5244, 21984, 22016, LineMetaDataContent::RapidTransit, Color{0x7a745a} }, // F2 OSM: 13313681 WD: Q387264 41.02, 28.97 x 41.03, 28.97
    { 9, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0000ff} }, // 4 OSM: 13317505 WD: Q15938386 34.68, 113.6 x 34.83, 113.7
    { 57, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff8000} }, // 3 OSM: 13317992 WD: Q15950459 34.72, 113.6 x 34.84, 113.8
    { 372, 22044, 16391, LineMetaDataContent::Subway, Color{0xff7400} }, // L1 OSM: 13335174 WD: Q6515333 10.48, -66.96 x 10.52, -66.8
    { 5247, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0066cc} }, // TPC OSM: 13341386 -31.77, -60.53 x -31.74, -60.41
};

static constexpr const auto line_data_count = sizeof(line_data) / sizeof(LineMetaDataContent);

static inline constexpr uint16_t Bucket(uint16_t index) { return line_data_count + index; }

static const int16_t line_data_bucketTable[] = {
    1295, 1276, 1292, 1293, 1294, -1,
    2612, 2611, 365, 366, -1,
    364, 381, 1097, 446, 445, 398, 397, -1,
    1178, 1110, 1180, 1185, 1184, -1,
    832, 1955, 254, -1,
    837, 2091, 839, 2090, 838, 2092, 836, 2089, -1,
    402, 2591, 2590, 414, 2604, 419, 2589, 2593, 416, 2594, 411, 2588, 2610, 415, 2592, 413, 2596, 421, 404, 2597, 410, 401, 2601, 408, 2608, 406, 2609, 412, 2607, 409, 2599, 420, 2603, 403, 2606, 423, 2595, 405, 407, 2605, 418, 2600, 417, 2602, 422, 2598, 2651, 2652, 2587, 2584, 384, 2585, 386, 2586, 385, 2683, 2681, 2678, 2676, 2677, 2675, 2679, 2674, 2682, 2680, 820, 2581, 818, 2583, 821, 647, 819, 2582, 2673, 2672, 2669, 2670, 2667, 2668, 2671, 2649, 2559, 2563, 826, 2564, 827, 2560, 825, 822, 2650, 2561, 823, 2562, 824, 1750, -1,
    892, 893, 888, 329, 889, 894, 895, 887, 890, 891, -1,
    2764, 2771, 2779, 2783, 2767, 2788, 2770, 2778, 2785, 2768, 2776, 2775, 2782, 2760, 2780, 2772, 2784, 2761, 2789, 2777, 2774, 2787, 2773, 2786, 2762, 2790, 2766, 2781, 2791, 2765, 2763, 2769, 2756, 1159, 1158, 1161, 2759, 1160, 2757, 2758, 1162, 2795, 2799, 2803, 2794, 2804, 2801, 2800, 2796, 2802, 2797, 2793, 2792, 2798, 451, 2749, 2748, 2747, 2751, 452, 2746, 2750, 2755, 2753, 2752, 456, 2754, 455, 453, 454, -1,
    443, 2246, 353, -1,
    1013, 1011, 248, -1,
    430, 434, -1,
    1682, 1205, 1684, 755, -1,
    232, 258, 234, -1,
    1291, 1270, -1,
    1355, 1354, -1,
    1522, 1530, 1357, -1,
    536, 1482, 1411, 257, 287, 1481, -1,
    2404, 2405, 2399, -1,
    635, 638, 639, -1,
    1942, 2885, -1,
    701, 1076, -1,
    773, 774, 1329, 1193, 1190, 1189, -1,
    342, 2197, -1,
    255, 1961, -1,
    2376, 2465, -1,
    2360, 2919, -1,
    2390, 2916, -1,
    785, 1700, 1509, 1149, 1738, 1702, 1971, -1,
    2300, 1829, 2339, 2453, 2745, 2071, 2299, 2541, 2462, 1830, -1,
    2117, 2120, 2123, 2118, 2121, 2119, 2122, 2158, 2129, 1315, 2142, 2130, 2164, 1313, 2154, 2155, 2162, 2124, 2143, 2128, 2165, 1312, 2147, 2126, 2166, 2140, 1314, 2169, 2145, 2133, 2160, 1317, 2146, 2127, 2168, 1322, 2150, 2136, 2156, 1323, 2148, 2134, 2161, 1311, 2151, 2132, 2153, 1316, 2131, 2144, 1310, 2159, 2125, 1318, 2157, 2137, 2141, 1319, 2167, 2138, 2152, 1321, 2163, 2149, 2139, 1320, 2135, 2709, 2716, 2690, 2713, 2688, 2727, 2685, 2718, 2704, 2730, 2700, 2714, 2708, 2739, 2711, 2721, 2705, 2723, 2698, 2733, 2697, 2722, 2707, 2734, 2695, 2737, 2703, 2715, 2702, 2736, 2701, 2725, 2706, 2732, 2689, 2735, 2692, 2728, 2694, 2731, 2687, 2717, 2684, 2738, 2686, 2726, 2693, 2720, 2710, 2115, 2699, 2114, 2696, 2719, 2691, 2724, 2712, 2113, 791, 2729, 842, 841, -1,
    2117, 2120, 2123, 2118, 2121, 2119, 2122, 2158, 2129, 1315, 2142, 2130, 2164, 1313, 2154, 2155, 2162, 2124, 2143, 2128, 2165, 1312, 2147, 2126, 2166, 2140, 1314, 2169, 2145, 2133, 2160, 1317, 2146, 2127, 2168, 1322, 2150, 2136, 2156, 1323, 2148, 2134, 2161, 1311, 2151, 2132, 2153, 1316, 2131, 2144, 1310, 2159, 2125, 1318, 2157, 2137, 2141, 1319, 2167, 2138, 2152, 1321, 2163, 2149, 2139, 1320, 2135, 2709, 2716, 2690, 2713, 2688, 2727, 2685, 2718, 2704, 2730, 2700, 2714, 2708, 2739, 2711, 2721, 2705, 2723, 2698, 2733, 2697, 2722, 2707, 2734, 2695, 2737, 2703, 2715, 2702, 2736, 2701, 2725, 2706, 2732, 2689, 2735, 2692, 2728, 2694, 2731, 2687, 2717, 2684, 2738, 2686, 2726, 2693, 2720, 2710, 2115, 2699, 2114, 2696, 2719, 2691, 2724, 2712, 2113, 791, 2729, 843, 842, 841, 831, -1,
    2645, 2644, 2642, 2647, 2641, 2646, 2648, 2643, -1,
    1503, 2269, 2268, 2660, 2665, 2664, 2666, 815, 2580, 816, 2579, -1,
    782, 1344, 783, -1,
    2493, 2494, -1,
    2808, 2814, 2847, 2810, 2852, 2813, 2851, 2821, 2811, 2806, 2812, 2853, 2815, 2807, 2848, 2805, 2849, 2822, 2850, 2854, 1923, 2820, 1925, 1928, 1924, 2817, 2816, 2845, 2823, 2841, 2844, 2846, 2843, 1922, 2842, 2840, 2857, 2858, 2859, 2860, 2837, 2831, 2818, 2834, 2838, 2832, 2839, 2833, 2836, 2835, 2819, 2830, 2809, 2825, 2824, 2829, 2827, 2828, 2826, 1926, 2855, 2856, 1927, 896, -1,
    2435, 218, 2431, -1,
    2740, 495, 2741, 494, 2742, 493, 492, 2744, 2743, 496, -1,
    2890, 448, 1777, 2382, 739, 1763, 2318, 2249, 449, 1764, -1,
    857, 851, 917, 855, 619, -1,
    1072, 2281, 2282, 1359, 1358, 2283, -1,
    436, 1085, -1,
    2519, 1263, 1670, 1255, 1264, 1266, 1242, 1243, 1240, 1241, 1267, 1207, 1239, 660, -1,
    1425, 997, -1,
    2349, 2350, 2337, 2348, 2336, 2338, -1,
    2337, 2336, 2338, -1,
    653, 195, 2631, 1483, 247, -1,
    727, 388, 728, 1070, -1,
    1245, 515, 82, 86, 672, 264, 676, 677, 1075, -1,
    1186, 1245, 515, 583, 394, 86, 2377, 674, 675, 676, 677, 1075, 678, 679, 680, 684, 707, 685, 686, -1,
    636, 637, 640, -1,
    699, 1941, 1221, 1940, -1,
    1994, 2873, 1969, 728, 1070, -1,
    502, 1384, 1908, 1630, 498, 1918, 1914, 1929, 1909, 1888, 1887, -1,
    505, 1630, 498, 1914, 846, 847, 26, 1394, -1,
    560, 561, 661, 313, 944, -1,
    2634, 2533, 2536, -1,
    1438, 1437, -1,
    722, 935, -1,
    786, 1862, 132, 133, 1326, -1,
    213, 346, 934, 933, 1417, 1418, -1,
    897, 796, 722, 935, 721, 1633, -1,
    726, 725, -1,
    770, 37, 15, -1,
    238, 239, -1,
    2441, 2177, 2447, 2479, 2186, -1,
    1181, 1183, 1182, 1177, 1179, 1111, -1,
    2104, 2103, -1,
    715, 898, 1017, -1,
    1621, 210, 212, -1,
    1657, 1648, -1,
    2292, 2291, 1806, 1808, 1807, -1,
    1527, 2178, -1,
    592, 590, -1,
    2353, 2352, -1,
    2930, 550, 549, 743, 744, 2931, -1,
    1725, 1855, 2525, -1,
    1383, 2253, -1,
    2182, 2483, -1,
    2184, 2240, -1,
    1652, 1653, -1,
    298, 1660, -1,
    1117, 777, 1913, 429, 306, 307, 435, 2499, -1,
    1562, 2044, 2078, 2513, 2887, 2302, 1820, -1,
    2639, 2640, 2566, 371, 2571, 2573, 2568, 370, 2570, 375, 2577, 377, 2576, 378, 368, 379, 2574, 373, 2575, 380, 2567, 372, 2572, 374, 2578, 367, 2565, 369, 2569, 376, 1878, 1749, 1751, -1,
    2423, 645, 646, 2425, 648, 2424, 2426, 649, 2422, 644, -1,
    2661, 2656, 2659, 2657, 2663, 2654, 2662, 2653, 2658, 2655, -1,
    2639, 2640, 2566, 371, 2571, 2573, 2568, 370, 2570, 375, 2577, 377, 2576, 378, 368, 379, 2574, 373, 2575, 380, 2567, 372, 2572, 374, 2578, 367, 2565, 369, 2569, 376, 1878, -1,
    2266, 2270, 2271, 2272, 2273, 2274, 2275, -1,
    167, 269, 1910, -1,
    973, 974, 975, 977, 972, 2004, 976, 2005, 2006, 2007, 2008, 2009, 2305, -1,
    2230, 2229, -1,
    1754, 1761, 1752, 1753, 1755, 1757, 1756, 1758, 2325, -1,
    1341, 1343, 1342, -1,
    1079, 1078, -1,
    1505, 1504, 1502, -1,
    2432, 2433, 2430, 2429, 2428, -1,
    1733, 1735, -1,
    2433, 2429, 2428, -1,
    2194, 2196, 2198, 2204, 284, 279, 2228, 2227, 2481, 283, 2242, 2243, 2244, 2239, 1113, 2236, 2224, 243, 424, 554, 285, 1029, 1641, -1,
    2194, 2198, 2204, 283, 2243, 424, -1,
    913, 911, 2035, 2040, 2037, -1,
    902, 198, 197, -1,
    1472, 1473, 1094, -1,
    1330, 991, 2083, 2088, -1,
    1683, 2016, 2517, 2013, 1635, 1637, 1645, 1642, 1646, 1640, -1,
    1226, 2251, -1,
    223, 2202, 1499, 2203, 1607, 1451, 1523, 1518, 1521, 2512, 1368, 1609, 1353, -1,
    1476, 1475, 923, 1479, 928, 929, 1478, 925, 1484, 1453, 714, 511, 1412, -1,
    1469, 1464, 1462, 1465, -1,
    1003, 1005, -1,
    2014, 2060, 2323, 1041, 2062, -1,
    1469, 1464, 1462, -1,
    1099, 1105, 1106, 1109, 1108, -1,
    683, 64, 1387, 65, 73, -1,
    681, 768, 1274, 769, 766, -1,
    633, 627, 628, 1058, 631, 634, 641, -1,
    1781, 1390, 1389, -1,
    2450, 2448, 2449, 790, 1964, 1993, 2278, 1991, 1965, 1966, 1967, 1968, 1992, -1,
    505, 1916, 1932, 1889, 2056, 1931, 2485, 504, -1,
    1916, 1931, 981, -1,
    1968, 1969, -1,
    2475, 2477, -1,
    214, 1300, 23, 17, 848, 849, 111, 1392, 1393, -1,
    83, 84, 85, 90, 323, 38, 49, 31, 51, 2051, 39, 40, 41, 42, 43, 44, 45, 46, -1,
    942, 943, 945, -1,
    2534, 2535, -1,
    145, 1434, 276, 146, 612, 105, 983, -1,
    1423, 1444, 1410, -1,
    700, 712, 710, 904, -1,
    1225, 535, 1222, 1223, 1148, 1224, 541, 540, 539, 142, 850, -1,
    112, 94, 119, -1,
    99, 77, 79, 130, 78, 129, 81, 859, 1902, -1,
    72, 29, 312, 140, 141, 2063, 68, 1457, 2263, 148, 13, 16, 268, 127, 124, 123, 101, 122, 121, 120, -1,
    72, 312, 140, 141, 2063, 16, -1,
    2289, 98, 286, 297, 1035, 211, -1,
    2181, 2187, -1,
    517, 516, -1,
    745, 741, 830, 746, 884, 885, -1,
    1232, 1120, 1122, -1,
    1580, 1581, -1,
    2374, 2373, 2372, -1,
    1021, 1022, 1020, -1,
    1515, 1516, -1,
    2508, 2509, -1,
    2913, 2261, 2330, -1,
    1787, 1790, -1,
    2458, 2457, -1,
    1592, 1591, -1,
    2216, 2220, 2221, 2223, -1,
    466, 481, 497, 465, 479, 480, -1,
    1722, 2464, -1,
    704, 702, -1,
    1853, 1849, 1850, 1857, 1880, 1921, 1852, -1,
    1654, 1854, 2195, -1,
    1896, 2613, 1891, 1895, 2555, 2397, -1,
    655, 2171, 2526, 792, 1898, -1,
    2934, 2170, 2174, -1,
    261, 260, 263, -1,
    1728, 2039, 2191, 2515, 2179, 2205, 263, -1,
    2183, 2176, -1,
    1891, 2555, 2397, -1,
    1674, 2356, 1675, 2250, 2907, -1,
    1917, 2394, 2904, -1,
    834, 1054, 1055, -1,
    2059, 1069, 1068, 310, -1,
    2463, 2914, -1,
    2920, 2937, -1,
    1912, 1703, 2357, -1,
    1773, 2396, -1,
    939, 938, 940, 1707, 2929, -1,
    1935, 2922, -1,
    1396, 1491, 1489, 1490, 2635, 1400, 2310, 244, 1402, 1486, 1404, 249, 1487, 1488, -1,
    2915, 2389, -1,
    2938, 427, 1118, 1116, 2314, 426, 2496, -1,
    1948, 1945, -1,
    1776, 1714, -1,
    1975, 1729, 2279, -1,
    1975, 1983, -1,
    1774, 1693, 1692, -1,
    1975, 1963, -1,
    1885, 1886, -1,
    2470, 2468, -1,
    2111, 1833, 2321, -1,
    1919, 2359, 2067, 1199, -1,
    237, 206, 245, 0, 55, 1, 205, 2520, 2522, -1,
    2260, 2259, 2410, -1,
    2025, 2027, -1,
    1308, 1157, -1,
    2265, 2264, 2459, 2276, -1,
    1216, 2638, 2637, -1,
    1216, 973, 974, 975, 977, 972, 2004, 976, 2638, 2005, 2006, 2007, 2008, 2637, 2009, 2306, 907, 2307, 2305, -1,
    2232, 2231, -1,
    2876, 2874, 2875, -1,
    765, 711, 771, 719, -1,
    1496, 1497, 1498, -1,
    1736, 1737, 1734, 1501, -1,
    2290, 1732, -1,
    2440, 2383, 1778, -1,
    2237, 444, 278, 2484, 2225, 442, 747, 281, 1765, 748, 282, 2210, -1,
    444, 442, 748, -1,
    1566, 1568, -1,
    1012, 200, -1,
    199, 1507, -1,
    994, 2255, 618, -1,
    994, 852, 2255, -1,
    2490, 2311, 2219, 432, 433, 431, 1686, 1685, -1,
    1304, 1302, 1797, -1,
    2298, 2537, -1,
    1618, 1617, -1,
    1137, 1671, 1208, 1209, -1,
    488, 486, 487, 1237, -1,
    2420, 2418, 2419, -1,
    756, 757, 763, 2366, -1,
    1517, 1531, 194, -1,
    1877, 224, -1,
    924, 927, -1,
    1623, 1622, 2897, 2898, -1,
    1429, 967, 1455, 1668, 1798, 1427, 1511, 1743, 1015, 1441, 1458, 1801, 1512, 1047, 1459, 1460, 1466, 1467, 2518, 1468, -1,
    2385, 2386, -1,
    1166, 304, -1,
    1046, 1057, 899, -1,
    1046, 899, -1,
    2322, 2502, 2226, -1,
    1460, 1461, 1467, 2518, 1468, -1,
    2055, 2502, -1,
    208, 215, 1741, -1,
    586, 1187, -1,
    584, 585, 586, 587, -1,
    950, 1459, 1466, -1,
    1331, 1337, 1883, 2511, 1333, 1280, 1282, 1283, 1284, -1,
    1187, 1250, 1253, 1251, -1,
    395, 2367, 389, 390, 392, -1,
    2073, 2074, 1956, -1,
    623, 630, -1,
    1553, 2539, 1474, -1,
    1550, 1551, 1863, 2539, 1474, 2633, -1,
    1695, 1792, -1,
    2495, 1990, -1,
    2241, 2434, 2323, 2226, -1,
    800, 809, 1454, 808, 566, 812, 810, 811, 804, 805, 806, 814, 807, 489, 506, 788, 2193, 1903, 484, 490, 508, -1,
    505, 1915, 484, -1,
    2454, 190, -1,
    987, 2455, 2476, -1,
    2533, 2535, 1037, -1,
    1298, 1297, 1299, 25, 22, 690, 477, 196, 691, 468, -1,
    396, 687, 688, -1,
    734, 687, 688, 690, 691, 468, -1,
    942, 943, 689, 706, -1,
    689, 706, 565, -1,
    1434, 106, 105, -1,
    172, 570, 173, 185, 556, 537, 555, -1,
    136, 482, 611, 106, 970, -1,
    1868, 1867, 1083, -1,
    1399, 1386, -1,
    538, 789, 828, 1860, 1859, 567, 582, 593, 1861, -1,
    538, 789, 1860, 1859, 582, -1,
    606, 608, 609, -1,
    874, 1977, 1978, 875, 881, 868, 873, 871, 882, 876, 883, 708, 775, 1084, -1,
    1060, 1061, 1062, -1,
    114, 115, 116, -1,
    59, 61, 57, -1,
    59, 60, 61, 57, -1,
    1170, 1326, 1328, -1,
    470, 474, 475, 476, 500, 469, 501, -1,
    7, 6, 70, 67, 33, 32, 69, 34, 2544, 8, 5, 149, 225, 126, -1,
    1192, 1191, 62, -1,
    1485, 1192, 1191, 919, 916, 1014, 62, 63, -1,
    319, 1262, 316, 1987, 1989, 320, 1823, 518, 1052, -1,
    901, 900, -1,
    1167, 1150, 1252, 1954, 1953, 1248, 1952, 1249, 1534, 1247, 1151, 1951, 1973, 1153, 1154, 1535, 1380, 1536, 1549, -1,
    2102, 2101, 2100, 2099, 2098, 2096, 2095, 2094, 2109, 2107, 2093, 2106, -1,
    2101, 2100, 2099, 2096, 2095, 2094, 2109, 2107, 2106, -1,
    856, 908, 909, 906, 918, 861, -1,
    670, 664, -1,
    1613, 2471, 2472, -1,
    617, 355, 1385, -1,
    642, 622, 485, 568, 1612, 867, 1611, 2529, -1,
    2629, 2623, 271, -1,
    692, 693, 694, 695, 696, -1,
    1234, 1235, -1,
    2510, 2506, 2505, 2507, -1,
    1556, 1557, -1,
    1803, 1802, 2011, -1,
    1995, 1996, -1,
    1540, 2065, -1,
    546, 547, -1,
    1864, 463, 462, 478, 1407, 491, -1,
    1082, 779, 1435, 654, -1,
    751, 752, 753, 754, -1,
    659, 1894, 2406, 2558, 2921, -1,
    915, 1039, 1456, 1287, -1,
    259, 1361, 2235, -1,
    1794, 2170, -1,
    2516, 2180, 1548, 2927, -1,
    1689, 1688, 2482, -1,
    1907, 2087, 2086, 2175, 1784, -1,
    1680, 2313, 1663, 2943, -1,
    1680, 1663, 2944, 2943, 2361, -1,
    2401, 2528, -1,
    1220, 1699, -1,
    2906, 1911, 2918, 2917, -1,
    2906, 2912, -1,
    2354, 2908, -1,
    2085, 2084, -1,
    1401, 1818, -1,
    301, 305, 302, 308, 776, 767, -1,
    302, 428, -1,
    1947, 1946, 2116, 1949, -1,
    1662, 1661, -1,
    1214, 1215, -1,
    1214, 2467, 1215, 1296, 2258, -1,
    1884, 1881, 1541, -1,
    1842, 1841, 2530, 1844, -1,
    1819, 1824, 2045, 2042, 2297, 1782, 1828, 2036, 2021, 1827, -1,
    604, 844, 275, 240, 89, 221, 351, 835, 204, -1,
    144, 143, 964, 966, 1306, -1,
    1405, 1406, 2524, -1,
    1271, 1272, -1,
    1217, 168, -1,
    1748, 1759, 1760, -1,
    729, 716, -1,
    1739, 1740, -1,
    1704, 1706, -1,
    2439, 2445, 2446, 2444, 2380, 1775, -1,
    2192, 1767, 1768, 2466, 1422, -1,
    2192, 2237, -1,
    1564, 1565, 1567, 1569, -1,
    514, 863, 1012, -1,
    1677, 1676, 1678, -1,
    458, 1372, 1586, -1,
    1305, 1301, 1303, -1,
    946, 1649, -1,
    946, 1656, 1649, 1655, -1,
    272, 1436, 979, -1,
    343, 1379, -1,
    272, 1436, 979, 1442, -1,
    231, 229, 230, 1228, 1227, -1,
    315, 1371, -1,
    1238, 1856, 1846, -1,
    1144, 1970, 1141, 1138, 1139, 1146, 1143, 1142, 1238, 1210, 1856, 1846, 1135, 1136, 1134, -1,
    2342, 2340, 2341, -1,
    2342, 2347, 2340, 2346, 2343, 2341, -1,
    2206, 2207, 2209, 2208, -1,
    194, 1610, -1,
    2393, 2398, -1,
    922, 1419, 1416, -1,
    1449, 1570, 922, 1600, 1603, 1602, 1599, 1939, 1001, 1042, 1601, -1,
    1420, 1413, -1,
    2504, 2521, -1,
    1799, 937, 936, 643, 1443, -1,
    1010, 1008, 1002, 1004, 1006, 2320, -1,
    1032, 1030, 1031, -1,
    1087, 1089, 1088, -1,
    2002, 1049, 2017, 2018, 2019, 2020, 2000, 2054, 2001, 2003, 2012, 2523, 2503, -1,
    1049, 2020, 2000, 2001, 2003, 2012, 2503, -1,
    163, 165, -1,
    580, 88, 1244, -1,
    1073, 2407, 1074, -1,
    2371, 956, 957, 9, 949, 951, 952, 953, 954, 1163, 948, -1,
    1334, 1335, 1338, 1332, 1882, 1336, -1,
    74, 1043, 75, 291, 1257, 290, -1,
    1340, 1332, 1882, -1,
    1092, 1101, 1104, 1093, 1103, 2554, 1107, 1098, -1,
    1230, 1231, -1,
    1254, 578, 66, 579, -1,
    580, 88, 1244, 1246, -1,
    1197, 1198, -1,
    393, 2369, 391, -1,
    2368, 682, -1,
    1744, 1526, -1,
    1583, 1582, 2487, 2895, -1,
    1793, 2879, 2872, -1,
    1696, 1697, -1,
    1915, 507, 1905, -1,
    191, 190, -1,
    1889, 1930, -1,
    21, 621, 24, 1289, 1071, -1,
    396, 691, -1,
    942, 945, -1,
    732, 733, 396, -1,
    563, 564, 557, 945, -1,
    562, 563, 564, 557, 705, 1124, 363, 1125, 980, 1128, 1129, 1130, -1,
    170, 2022, 171, 2023, 273, -1,
    152, 150, 153, 135, 137, 156, 151, 154, 1026, 138, 202, 982, 971, 926, 969, 984, 985, -1,
    185, 186, -1,
    362, 360, 361, 1375, 359, 358, -1,
    959, 961, -1,
    53, 54, 341, 340, 335, 344, 345, -1,
    878, 1077, -1,
    793, 2308, 1115, 833, 2288, 817, -1,
    174, 181, 921, 175, 176, 177, 179, 439, 879, 795, -1,
    109, 110, 108, -1,
    92, 242, 241, -1,
    1168, 1175, 778, 1176, 1169, 464, 1171, 1172, 1173, 1327, -1,
    4, 30, 36, 71, 2, 3, 667, 14, -1,
    1168, 1175, 1176, 1169, 1171, 1173, 1327, -1,
    594, 657, 597, 601, 600, 2296, -1,
    594, 597, 601, 2296, -1,
    338, 339, 336, -1,
    338, 339, -1,
    252, 295, 293, 251, 1164, 1165, 294, 76, 2933, 250, 1200, -1,
    519, 1986, 327, 317, 10, 520, 533, 532, 524, 529, 534, 318, 1018, 209, 531, 527, 522, 528, 526, 437, 1053, 1051, -1,
    1432, 2617, 2616, 2614, 2615, -1,
    1816, 1814, 1872, 1813, 1815, 2033, 2031, 1873, 1871, 1811, 1874, 2032, -1,
    102, 665, 668, 666, 103, 107, 104, 663, 669, -1,
    999, 998, -1,
    1351, 1350, 1960, -1,
    1351, 1352, 1348, 1349, 1350, 253, 1960, -1,
    1351, 1352, 1348, 1349, 1350, 2473, 253, 1960, 845, -1,
    2928, 713, -1,
    267, 266, -1,
    1019, 1025, -1,
    2057, 2199, -1,
    1789, 1788, -1,
    1636, 1605, 1539, -1,
    1625, 1626, -1,
    2215, 2212, 2211, 2217, 2218, 2222, -1,
    2215, 2212, 2211, -1,
    544, 2024, -1,
    2498, 2497, -1,
    1213, 1893, -1,
    472, 438, -1,
    1900, 1899, -1,
    1036, 309, 2172, -1,
    1720, 2923, -1,
    262, 2234, -1,
    2926, 262, -1,
    797, 854, 853, 803, -1,
    1687, 1694, 1691, 1690, -1,
    1067, 2436, -1,
    1650, 2538, -1,
    2316, 2905, -1,
    1710, 2395, -1,
    1650, 1651, 2538, -1,
    1710, 1936, 2395, -1,
    1658, 1701, -1,
    1667, 1492, 1980, -1,
    1667, 1492, 2309, -1,
    1508, 1731, 1495, -1,
    1731, 1730, 1495, -1,
    651, 652, 1203, -1,
    1547, 1546, 1555, -1,
    1834, 1835, 1836, 2303, 1832, 1838, 1837, -1,
    569, 2532, 1840, -1,
    2043, 2046, -1,
    1821, 1831, 1826, 1822, 1817, 1825, 2029, -1,
    1028, 553, 274, 350, 352, -1,
    2319, 2370, -1,
    1712, 1713, 2880, -1,
    357, 1218, 1112, -1,
    2868, 2867, -1,
    2867, 2866, -1,
    1081, 1080, -1,
    2442, 2488, 2443, 2379, 2378, 2381, 447, -1,
    2379, 2378, 447, -1,
    2488, 447, -1,
    864, 201, -1,
    865, 864, -1,
    1000, 996, -1,
    1769, 2351, -1,
    1974, 1377, 265, 1587, 1584, -1,
    1665, 1666, -1,
    1644, 1634, -1,
    1634, 1664, -1,
    236, 233, -1,
    228, 227, -1,
    1140, 1147, 1131, 1133, 1132, -1,
    219, 698, -1,
    1876, 1875, -1,
    2277, 2247, -1,
    2461, 2460, -1,
    2347, 2346, 2343, -1,
    1606, 1520, -1,
    1606, 1608, -1,
    314, 992, 993, -1,
    1477, 1480, 709, -1,
    1997, 2392, -1,
    1045, 740, -1,
    1426, 1428, -1,
    164, 166, -1,
    164, 166, 1324, -1,
    1742, 216, 459, -1,
    880, 1285, 1286, 289, -1,
    880, 1043, 1280, -1,
    1091, 1102, 1095, 1090, 1096, -1,
    87, 581, -1,
    730, 1275, 749, 1265, -1,
    1959, 1958, 1957, -1,
    1944, 2038, -1,
    1259, 1261, -1,
    2871, 2543, -1,
    1705, 1721, -1,
    1397, 1398, 1395, -1,
    1397, 1398, -1,
    1552, 869, -1,
    159, 162, 1631, -1,
    2052, 162, 48, 50, 52, 1631, -1,
    159, 50, 52, -1,
    731, 735, -1,
    1126, 1127, -1,
    943, 1126, 1128, -1,
    931, 321, 602, 932, 322, 2408, -1,
    155, 742, 605, -1,
    139, 187, -1,
    787, 588, -1,
    2077, 334, -1,
    872, 877, -1,
    18, 19, -1,
    1059, 1063, 1064, -1,
    441, 180, 870, -1,
    95, 118, 96, 97, -1,
    58, 724, -1,
    58, 56, 724, -1,
    1174, 1211, -1,
    161, 28, 577, -1,
    598, 2939, 599, -1,
    598, 599, -1,
    288, 2329, 2452, -1,
    333, 331, 332, -1,
    333, 331, -1,
    525, 2474, 2480, 530, 349, 303, -1,
    758, 2618, 2619, 572, 2630, 760, 573, -1,
    2618, 572, 2630, 760, 573, 2614, -1,
    440, 658, 543, 542, 460, -1,
    525, 349, -1,
    2939, 601, 600, -1,
    1346, 1347, 1352, -1,
    1346, 1347, -1,
    1119, 1233, 1123, 2312, -1,
    1119, 1233, 1121, 1123, 2312, -1,
    1023, 1024, -1,
    2625, 2626, -1,
    2620, 2621, 2622, 2624, 2625, 2626, 2627, 2628, -1,
    1620, 1619, -1,
    1625, 1626, 1627, -1,
    2214, 2213, -1,
    1362, 1363, 1364, 1366, 1278, 1365, 1279, -1,
    1362, 1363, 1364, 1366, 1278, 1365, 1279, 1374, 1373, 2245, 1367, -1,
    1532, 1590, -1,
    2900, 2901, -1,
    328, 207, 473, -1,
    571, 1277, 963, 962, -1,
    2327, 2877, -1,
    2869, 2870, -1,
    862, 866, -1,
    1378, 1433, 2064, -1,
    2415, 2416, -1,
    235, 233, -1,
    697, 1196, -1,
    625, 629, -1,
    1174, 778, -1,
    513, 188, 510, -1,
    513, 510, -1,
    337, 330, 332, -1,
    326, 1988, 325, -1,
    348, 326, 1988, 347, -1,
    2110, 2105, -1,
    1352, 1348, -1,
    1348, 253, -1,
    1119, 1233, -1,
    1364, 1366, 1365, -1,
    2864, 2863, -1,
    100, 784, 558, 559, -1,
};

static const constexpr LineMetaDataQuadTreeDepthIndex line_data_depthOffsets[] = {
    { 27, 0 },
    { 26, 1 },
    { 25, 8 },
    { 24, 50 },
    { 23, 142 },
    { 22, 332 },
    { 21, 625 },
    { 20, 950 },
    { 19, 1227 },
    { 18, 1361 },
    { 17, 1411 },
    { 16, 1461 },
};

static const constexpr LineMetaDataZIndex line_data_zquadtree[] = {
    { 227, Bucket(0) }, // 30.8, -5.517 x 44.22, 7.905
    { 390, Bucket(6) }, // 30.8, -119.6 x 37.51, -112.9
    { 397, 1979 }, // 37.51, -112.9 x 44.22, -106.2
    { 400, 1708 }, // 44.22, -126.3 x 50.93, -119.6
    { 431, Bucket(11) }, // 37.51, -79.34 x 44.22, -72.63
    { 773, 1097 }, // 37.51, -72.63 x 44.22, -65.91
    { 946, Bucket(19) }, // 44.22, 14.62 x 50.93, 21.33
    { 950, Bucket(25) }, // 57.64, 14.62 x 64.35, 21.33
    { 1555, Bucket(29) }, // 34.15, -123 x 37.51, -119.6
    { 1558, Bucket(29) }, // 37.51, -123 x 40.86, -119.6
    { 1560, Bucket(38) }, // 30.8, -119.6 x 34.15, -116.2
    { 1561, 1750 }, // 34.15, -119.6 x 37.51, -116.2
    { 1695, Bucket(134) }, // 40.86, -89.4 x 44.22, -86.05
    { 1724, Bucket(145) }, // 37.51, -79.34 x 40.86, -75.98
    { 1726, Bucket(216) }, // 37.51, -75.98 x 40.86, -72.63
    { 1727, 382 }, // 40.86, -75.98 x 44.22, -72.63
    { 2314, 248 }, // -36.31, -62.56 x -32.96, -59.2
    { 2336, Bucket(220) }, // -36.31, -59.2 x -32.96, -55.85
    { 3093, Bucket(224) }, // 40.86, -72.63 x 44.22, -69.27
    { 3636, Bucket(227) }, // 37.51, -5.517 x 40.86, -2.162
    { 3638, Bucket(232) }, // 37.51, -2.162 x 40.86, 1.194
    { 3645, Bucket(236) }, // 40.86, 1.194 x 44.22, 4.549
    { 3683, 1357 }, // 47.57, -2.162 x 50.93, 1.194
    { 3685, Bucket(239) }, // 54.28, -5.517 x 57.64, -2.162
    { 3686, Bucket(242) }, // 50.93, -2.162 x 54.28, 1.194
    { 3689, Bucket(246) }, // 47.57, 1.194 x 50.93, 4.549
    { 3690, Bucket(253) }, // 44.22, 4.549 x 47.57, 7.905
    { 3692, 930 }, // 50.93, 1.194 x 54.28, 4.549
    { 3735, Bucket(257) }, // 40.86, 11.26 x 44.22, 14.62
    { 3764, Bucket(261) }, // 37.51, 21.33 x 40.86, 24.68
    { 3778, 1439 }, // 44.22, 11.26 x 47.57, 14.62
    { 3780, Bucket(264) }, // 50.93, 7.905 x 54.28, 11.26
    { 3782, 723 }, // 50.93, 11.26 x 54.28, 14.62
    { 3785, Bucket(267) }, // 47.57, 14.62 x 50.93, 17.97
    { 3786, 2556 }, // 44.22, 17.97 x 47.57, 21.33
    { 3787, 2556 }, // 47.57, 17.97 x 50.93, 21.33
    { 3788, Bucket(274) }, // 50.93, 14.62 x 54.28, 17.97
    { 3800, Bucket(277) }, // 57.64, 14.62 x 60.99, 17.97
    { 3802, Bucket(277) }, // 57.64, 17.97 x 60.99, 21.33
    { 9180, 2456 }, // 10.66, 122 x 14.02, 125.3
    { 9285, 2333 }, // 54.28, 34.75 x 57.64, 38.1
    { 9354, Bucket(280) }, // 17.37, 71.66 x 20.73, 75.01
    { 9771, 2173 }, // 20.73, 111.9 x 24.09, 115.3
    { 9863, Bucket(283) }, // 27.44, 118.6 x 30.8, 122
    { 9875, Bucket(286) }, // 34.15, 118.6 x 37.51, 122
    { 9876, 2500 }, // 37.51, 115.3 x 40.86, 118.6
    { 9883, Bucket(289) }, // 34.15, 125.3 x 37.51, 128.7
    { 9886, Bucket(289) }, // 37.51, 125.3 x 40.86, 128.7
    { 9913, 2548 }, // 34.15, 135.4 x 37.51, 138.8
    { 9915, Bucket(297) }, // 34.15, 138.8 x 37.51, 142.1
    { 3830, 1558 }, // -12.82, -77.66 x -11.15, -75.98
    { 6221, Bucket(308) }, // 35.83, -123 x 37.51, -121.3
    { 6232, Bucket(438) }, // 37.51, -123 x 39.18, -121.3
    { 6241, Bucket(570) }, // 32.47, -119.6 x 34.15, -117.9
    { 6243, Bucket(579) }, // 32.47, -117.9 x 34.15, -116.2
    { 6244, Bucket(570) }, // 34.15, -119.6 x 35.83, -117.9
    { 6337, 399 }, // 32.47, -112.9 x 34.15, -111.2
    { 6723, Bucket(591) }, // 32.47, -97.79 x 34.15, -96.11
    { 6770, Bucket(595) }, // 37.51, -91.08 x 39.18, -89.4
    { 6782, Bucket(598) }, // 40.86, -87.73 x 42.54, -86.05
    { 6879, Bucket(663) }, // 42.54, -81.01 x 44.22, -79.34
    { 6898, Bucket(667) }, // 37.51, -77.66 x 39.18, -75.98
    { 6901, 218 }, // 42.54, -79.34 x 44.22, -77.66
    { 6905, Bucket(678) }, // 39.18, -75.98 x 40.86, -74.3
    { 6907, 1100 }, // 39.18, -74.3 x 40.86, -72.63
    { 6922, 673 }, // 44.22, -94.44 x 45.9, -92.76
    { 7082, 2050 }, // 44.22, -74.3 x 45.9, -72.63
    { 9268, 2936 }, // -26.25, -65.91 x -24.57, -64.24
    { 9345, 203 }, // -34.64, -59.2 x -32.96, -57.53
    { 9407, Bucket(689) }, // -24.57, -47.46 x -22.89, -45.78
    { 9751, Bucket(695) }, // -24.57, -44.1 x -22.89, -42.43
    { 9794, Bucket(695) }, // -22.89, -44.1 x -21.21, -42.43
    { 12372, Bucket(702) }, // 40.86, -72.63 x 42.54, -70.95
    { 14551, 1448 }, // 42.54, -3.839 x 44.22, -2.162
    { 14558, 1470 }, // 40.86, -0.4838 x 42.54, 1.194
    { 14580, Bucket(705) }, // 40.86, 1.194 x 42.54, 2.872
    { 14651, Bucket(720) }, // 52.61, -7.195 x 54.28, -5.517
    { 14739, Bucket(723) }, // 52.61, -3.839 x 54.28, -2.162
    { 14745, Bucket(730) }, // 52.61, -2.162 x 54.28, -0.4838
    { 14756, Bucket(734) }, // 47.57, 1.194 x 49.25, 2.872
    { 14759, 1463 }, // 49.25, 2.872 x 50.93, 4.549
    { 14762, Bucket(740) }, // 44.22, 6.227 x 45.9, 7.905
    { 14766, 264 }, // 47.57, 6.227 x 49.25, 7.905
    { 14767, Bucket(745) }, // 49.25, 6.227 x 50.93, 7.905
    { 14770, 1463 }, // 50.93, 2.872 x 52.61, 4.549
    { 14778, Bucket(755) }, // 50.93, 6.227 x 52.61, 7.905
    { 14940, Bucket(775) }, // 40.86, 11.26 x 42.54, 12.94
    { 15031, 829 }, // 29.12, 29.72 x 30.8, 31.39
    { 15058, Bucket(779) }, // 37.51, 23 x 39.18, 24.68
    { 15089, 1679 }, // 39.18, 28.04 x 40.86, 29.72
    { 15104, Bucket(784) }, // 44.22, 7.905 x 45.9, 9.583
    { 15105, Bucket(790) }, // 45.9, 7.905 x 47.57, 9.583
    { 15108, Bucket(802) }, // 47.57, 7.905 x 49.25, 9.583
    { 15109, Bucket(811) }, // 49.25, 7.905 x 50.93, 9.583
    { 15111, 620 }, // 49.25, 9.583 x 50.93, 11.26
    { 15113, Bucket(817) }, // 45.9, 11.26 x 47.57, 12.94
    { 15115, Bucket(821) }, // 45.9, 12.94 x 47.57, 14.62
    { 15117, Bucket(824) }, // 49.25, 11.26 x 50.93, 12.94
    { 15119, Bucket(827) }, // 49.25, 12.94 x 50.93, 14.62
    { 15121, Bucket(833) }, // 52.61, 7.905 x 54.28, 9.583
    { 15128, Bucket(840) }, // 50.93, 11.26 x 52.61, 12.94
    { 15129, Bucket(847) }, // 52.61, 11.26 x 54.28, 12.94
    { 15130, Bucket(850) }, // 50.93, 12.94 x 52.61, 14.62
    { 15132, Bucket(854) }, // 54.28, 11.26 x 55.96, 12.94
    { 15137, Bucket(857) }, // 45.9, 14.62 x 47.57, 16.29
    { 15140, 2186 }, // 47.57, 14.62 x 49.25, 16.29
    { 15142, 1188 }, // 47.57, 16.29 x 49.25, 17.97
    { 15145, Bucket(863) }, // 45.9, 17.97 x 47.57, 19.65
    { 15148, 1179 }, // 47.57, 17.97 x 49.25, 19.65
    { 15160, Bucket(870) }, // 50.93, 17.97 x 52.61, 19.65
    { 15171, Bucket(873) }, // 59.32, 9.583 x 60.99, 11.26
    { 15271, Bucket(877) }, // 49.25, 29.72 x 50.93, 31.39
    { 34771, Bucket(881) }, // 12.34, 76.69 x 14.02, 78.37
    { 34779, 1848 }, // 12.34, 80.05 x 14.02, 81.72
    { 36159, Bucket(884) }, // 2.275, 100.2 x 3.952, 101.9
    { 36245, 2292 }, // 2.275, 101.9 x 3.952, 103.5
    { 36246, Bucket(890) }, // 0.597, 103.5 x 2.275, 105.2
    { 36356, Bucket(893) }, // -32.96, 115.3 x -31.28, 117
    { 36702, Bucket(896) }, // 14.02, 120.3 x 15.7, 122
    { 37142, 2334 }, // 54.28, 36.43 x 55.96, 38.1
    { 37276, Bucket(899) }, // 54.28, 51.53 x 55.96, 53.2
    { 37526, 2030 }, // 27.44, 76.69 x 29.12, 78.37
    { 39056, Bucket(906) }, // 24.09, 101.9 x 25.76, 103.5
    { 39063, 2527 }, // 29.12, 103.5 x 30.8, 105.2
    { 39065, 2902 }, // 25.76, 105.2 x 27.44, 106.9
    { 39085, Bucket(910) }, // 22.41, 111.9 x 24.09, 113.6
    { 39100, Bucket(913) }, // 27.44, 111.9 x 29.12, 113.6
    { 39103, Bucket(916) }, // 29.12, 113.6 x 30.8, 115.3
    { 39162, Bucket(919) }, // 37.51, 113.6 x 39.18, 115.3
    { 39455, 2632 }, // 29.12, 120.3 x 30.8, 122
    { 39493, 2315 }, // 35.83, 115.3 x 37.51, 117
    { 39496, 2082 }, // 30.8, 118.6 x 32.47, 120.3
    { 39498, Bucket(922) }, // 30.8, 120.3 x 32.47, 122
    { 39505, Bucket(925) }, // 39.18, 115.3 x 40.86, 117
    { 39514, 1779 }, // 37.51, 120.3 x 39.18, 122
    { 39540, 1718 }, // 40.86, 122 x 42.54, 123.7
    { 39660, Bucket(934) }, // 34.15, 138.8 x 35.83, 140.4
    { 39661, 2540 }, // 35.83, 138.8 x 37.51, 140.4
    { 39679, 1809 }, // 42.54, 140.4 x 44.22, 142.1
    { 41819, 1256 }, // -41.35, 174 x -39.67, 175.7
    { 41823, 11 }, // -37.99, 174 x -36.31, 175.7
    { 42019, 2068 }, // -34.64, 150.5 x -32.96, 152.2
    { 12287, 1409 }, // -37.15, -73.46 x -36.31, -72.63
    { 16292, 471 }, // 5.63, -75.98 x 6.469, -75.14
    { 24928, 840 }, // 37.51, -123 x 38.35, -122.1
    { 24967, Bucket(942) }, // 33.31, -118.8 x 34.15, -117.9
    { 24972, Bucket(976) }, // 32.47, -117.9 x 33.31, -117.1
    { 24973, Bucket(987) }, // 33.31, -117.9 x 34.15, -117.1
    { 24978, Bucket(998) }, // 34.15, -118.8 x 34.99, -117.9
    { 25542, Bucket(1030) }, // 39.18, -105.3 x 40.02, -104.5
    { 25633, Bucket(1038) }, // 45.06, -123 x 45.9, -122.1
    { 25637, Bucket(1042) }, // 46.73, -123 x 47.57, -122.1
    { 25789, 2230 }, // 50.09, -114.6 x 50.93, -113.7
    { 25832, Bucket(1056) }, // 50.93, -114.6 x 51.77, -113.7
    { 26628, Bucket(1059) }, // 19.05, -99.47 x 19.89, -98.63
    { 26711, 2417 }, // 29.96, -98.63 x 30.8, -97.79
    { 26717, 2417 }, // 29.96, -97.79 x 30.8, -96.95
    { 26892, 2421 }, // 32.47, -97.79 x 33.31, -96.95
    { 26894, Bucket(1069) }, // 32.47, -96.95 x 33.31, -96.11
    { 27399, Bucket(1073) }, // 33.31, -85.21 x 34.15, -84.37
    { 27405, Bucket(1073) }, // 33.31, -84.37 x 34.15, -83.53
    { 27503, Bucket(1076) }, // 40.02, -80.18 x 40.86, -79.34
    { 27519, Bucket(1080) }, // 43.38, -80.18 x 44.22, -79.34
    { 27593, Bucket(1086) }, // 38.35, -77.66 x 39.18, -76.82
    { 27605, Bucket(1089) }, // 43.38, -79.34 x 44.22, -78.5
    { 27620, 2384 }, // 39.18, -75.98 x 40.02, -75.14
    { 27629, Bucket(1093) }, // 40.02, -74.3 x 40.86, -73.46
    { 27640, Bucket(1117) }, // 40.86, -74.3 x 41.7, -73.46
    { 27690, 1976 }, // 44.22, -93.6 x 45.06, -92.76
    { 28329, Bucket(1124) }, // 45.06, -74.3 x 45.9, -73.46
    { 34162, 1204 }, // -39.67, -68.43 x -38.83, -67.59
    { 36871, 1440 }, // -33.8, -71.79 x -32.96, -70.95
    { 36877, 2185 }, // -33.8, -70.95 x -32.96, -70.11
    { 36901, 941 }, // -33.8, -69.27 x -32.96, -68.43
    { 36912, 941 }, // -32.96, -69.27 x -32.12, -68.43
    { 37049, 2946 }, // -32.12, -60.88 x -31.28, -60.04
    { 37377, 968 }, // -35.47, -59.2 x -34.64, -58.37
    { 37380, Bucket(1130) }, // -34.64, -59.2 x -33.8, -58.37
    { 37527, 1212 }, // -30.44, -51.65 x -29.6, -50.82
    { 40084, 2287 }, // -4.436, -39.07 x -3.597, -38.23
    { 40112, 2256 }, // -6.114, -35.72 x -5.275, -34.88
    { 49491, 1086 }, // 41.7, -71.79 x 42.54, -70.95
    { 57767, Bucket(1134) }, // 33.31, -8.034 x 34.15, -7.195
    { 57791, 1614 }, // 36.67, -6.356 x 37.51, -5.517
    { 57803, 1585 }, // 38.35, -9.711 x 39.18, -8.872
    { 57840, Bucket(1138) }, // 40.86, -8.872 x 41.7, -8.034
    { 58189, Bucket(1143) }, // 40.02, -3.839 x 40.86, -3
    { 58214, 1226 }, // 39.18, -1.323 x 40.02, -0.4838
    { 58217, 299 }, // 38.35, -0.4838 x 39.18, 0.3551
    { 58220, Bucket(1154) }, // 39.18, -0.4838 x 40.02, 0.3551
    { 58226, 512 }, // 40.86, -1.323 x 41.7, -0.4838
    { 58227, 512 }, // 41.7, -1.323 x 42.54, -0.4838
    { 58982, 222 }, // 52.61, -1.323 x 53.45, -0.4838
    { 58984, Bucket(1157) }, // 50.93, -0.4838 x 51.77, 0.3551
    { 59027, Bucket(1171) }, // 48.41, 2.033 x 49.25, 2.872
    { 59039, Bucket(1185) }, // 50.09, 3.711 x 50.93, 4.549
    { 59041, Bucket(1190) }, // 45.06, 4.549 x 45.9, 5.388
    { 59046, 2388 }, // 45.9, 5.388 x 46.73, 6.227
    { 59051, 387 }, // 45.06, 7.066 x 45.9, 7.905
    { 59052, 2388 }, // 45.9, 6.227 x 46.73, 7.066
    { 59055, Bucket(1193) }, // 46.73, 7.066 x 47.57, 7.905
    { 59070, 687 }, // 49.25, 7.066 x 50.09, 7.905
    { 59082, Bucket(1199) }, // 50.93, 3.711 x 51.77, 4.549
    { 59083, 1281 }, // 51.77, 3.711 x 52.61, 4.549
    { 59105, Bucket(1203) }, // 51.77, 4.549 x 52.61, 5.388
    { 59112, Bucket(1209) }, // 50.93, 6.227 x 51.77, 7.066
    { 59114, Bucket(1215) }, // 50.93, 7.066 x 51.77, 7.905
    { 59759, 2886 }, // 40.02, 13.78 x 40.86, 14.62
    { 59763, Bucket(1221) }, // 41.7, 12.1 x 42.54, 12.94
    { 59770, 2886 }, // 40.86, 13.78 x 41.7, 14.62
    { 59797, 1524 }, // 36.67, 14.62 x 37.51, 15.45
    { 59840, 1524 }, // 37.51, 14.62 x 38.35, 15.45
    { 60232, Bucket(1229) }, // 37.51, 23 x 38.35, 23.84
    { 60390, 1791 }, // 39.18, 32.23 x 40.02, 33.07
    { 60419, Bucket(1233) }, // 45.06, 8.744 x 45.9, 9.583
    { 60421, Bucket(1247) }, // 46.73, 7.905 x 47.57, 8.744
    { 60423, Bucket(1256) }, // 46.73, 8.744 x 47.57, 9.583
    { 60425, Bucket(1260) }, // 45.06, 9.583 x 45.9, 10.42
    { 60429, Bucket(1263) }, // 46.73, 9.583 x 47.57, 10.42
    { 60432, 2056 }, // 47.57, 7.905 x 48.41, 8.744
    { 60433, Bucket(1266) }, // 48.41, 7.905 x 49.25, 8.744
    { 60435, Bucket(1276) }, // 48.41, 8.744 x 49.25, 9.583
    { 60436, 720 }, // 49.25, 7.905 x 50.09, 8.744
    { 60437, Bucket(1295) }, // 50.09, 7.905 x 50.93, 8.744
    { 60438, 691 }, // 49.25, 8.744 x 50.09, 9.583
    { 60442, 276 }, // 47.57, 10.42 x 48.41, 11.26
    { 60443, 620 }, // 48.41, 10.42 x 49.25, 11.26
    { 60446, 184 }, // 49.25, 10.42 x 50.09, 11.26
    { 60453, Bucket(1299) }, // 46.73, 11.26 x 47.57, 12.1
    { 60464, Bucket(1302) }, // 47.57, 11.26 x 48.41, 12.1
    { 60468, 184 }, // 49.25, 11.26 x 50.09, 12.1
    { 60474, Bucket(1310) }, // 47.57, 13.78 x 48.41, 14.62
    { 60476, 960 }, // 49.25, 12.94 x 50.09, 13.78
    { 60477, 1328 }, // 50.09, 12.94 x 50.93, 13.78
    { 60483, 708 }, // 51.77, 8.744 x 52.61, 9.583
    { 60489, Bucket(1314) }, // 51.77, 9.583 x 52.61, 10.42
    { 60492, Bucket(1316) }, // 52.61, 9.583 x 53.45, 10.42
    { 60493, Bucket(1319) }, // 53.45, 9.583 x 54.28, 10.42
    { 60512, 178 }, // 50.93, 11.26 x 51.77, 12.1
    { 60513, Bucket(1331) }, // 51.77, 11.26 x 52.61, 12.1
    { 60514, Bucket(1335) }, // 50.93, 12.1 x 51.77, 12.94
    { 60516, 119 }, // 52.61, 11.26 x 53.45, 12.1
    { 60521, Bucket(1345) }, // 51.77, 12.94 x 52.61, 13.78
    { 60522, 1326 }, // 50.93, 13.78 x 51.77, 14.62
    { 60524, Bucket(1366) }, // 52.61, 12.94 x 53.45, 13.78
    { 60531, Bucket(1373) }, // 55.12, 12.1 x 55.96, 12.94
    { 60549, Bucket(1380) }, // 46.73, 14.62 x 47.57, 15.45
    { 60550, 160 }, // 45.9, 15.45 x 46.73, 16.29
    { 60551, 425 }, // 46.73, 15.45 x 47.57, 16.29
    { 60568, 772 }, // 47.57, 16.29 x 48.41, 17.13
    { 60583, Bucket(1383) }, // 46.73, 18.81 x 47.57, 19.65
    { 60594, 517 }, // 47.57, 18.81 x 48.41, 19.65
    { 60651, 270 }, // 51.77, 20.49 x 52.61, 21.33
    { 60686, Bucket(1386) }, // 59.32, 10.42 x 60.16, 11.26
    { 60708, 885 }, // 59.32, 11.26 x 60.16, 12.1
    { 60811, 256 }, // 58.48, 17.13 x 59.32, 17.97
    { 60975, Bucket(1393) }, // 46.73, 27.2 x 47.57, 28.04
    { 61039, Bucket(1397) }, // 53.45, 27.2 x 54.28, 28.04
    { 61085, 995 }, // 50.09, 29.72 x 50.93, 30.55
    { 61112, Bucket(1400) }, // 47.57, 33.07 x 48.41, 33.91
    { 61145, Bucket(1404) }, // 55.12, 29.72 x 55.96, 30.55
    { 61221, Bucket(1408) }, // 60.16, 24.68 x 60.99, 25.52
    { 144855, Bucket(1411) }, // 16.54, 95.99 x 17.37, 96.82
    { 144877, Bucket(1414) }, // 13.18, 100.2 x 14.02, 101
    { 144927, 2233 }, // -3.597, 104.4 x -2.758, 105.2
    { 144984, Bucket(1418) }, // 0.597, 103.5 x 1.436, 104.4
    { 145425, 591 }, // -32.12, 115.3 x -31.28, 116.1
    { 146887, Bucket(1421) }, // 13.18, 122.8 x 14.02, 123.7
    { 148043, 2080 }, // 24.92, 50.69 x 25.76, 51.53
    { 148065, 2080 }, // 24.92, 51.53 x 25.76, 52.36
    { 148161, Bucket(1424) }, // 24.92, 54.88 x 25.76, 55.72
    { 148251, 1597 }, // 34.99, 50.69 x 35.83, 51.53
    { 148406, 311 }, // 35.83, 59.08 x 36.67, 59.91
    { 148495, Bucket(1427) }, // 46.73, 37.26 x 47.57, 38.1
    { 148571, Bucket(1432) }, // 55.12, 37.26 x 55.96, 38.1
    { 149068, 2335 }, // 52.61, 49.85 x 53.45, 50.69
    { 149667, 2464 }, // 18.21, 72.5 x 19.05, 73.34
    { 149670, Bucket(1439) }, // 19.05, 72.5 x 19.89, 73.34
    { 149970, Bucket(1442) }, // 40.86, 69.14 x 41.7, 69.98
    { 150064, 2079 }, // 20.73, 78.37 x 21.57, 79.21
    { 150105, Bucket(1445) }, // 28.28, 76.69 x 29.12, 77.53
    { 150525, 1984 }, // 43.38, 86.76 x 44.22, 87.6
    { 150527, 1984 }, // 43.38, 87.6 x 44.22, 88.44
    { 156222, Bucket(1453) }, // 22.41, 107.7 x 23.25, 108.6
    { 156253, Bucket(1457) }, // 29.96, 103.5 x 30.8, 104.4
    { 156278, Bucket(1464) }, // 29.12, 106.1 x 29.96, 106.9
    { 156342, Bucket(1470) }, // 22.41, 112.8 x 23.25, 113.6
    { 156343, 2262 }, // 23.25, 112.8 x 24.09, 113.6
    { 156345, Bucket(1474) }, // 21.57, 113.6 x 22.41, 114.4
    { 156348, Bucket(1478) }, // 22.41, 113.6 x 23.25, 114.4
    { 156413, Bucket(1486) }, // 29.96, 113.6 x 30.8, 114.4
    { 156424, Bucket(1489) }, // 30.8, 103.5 x 31.63, 104.4
    { 156549, 2250 }, // 33.31, 108.6 x 34.15, 109.4
    { 156560, Bucket(1493) }, // 34.15, 108.6 x 34.99, 109.4
    { 156592, 2910 }, // 34.15, 111.9 x 34.99, 112.8
    { 156600, 1681 }, // 34.15, 113.6 x 34.99, 114.4
    { 157770, Bucket(1499) }, // 24.09, 117.8 x 24.92, 118.6
    { 157777, Bucket(1503) }, // 28.28, 115.3 x 29.12, 116.1
    { 157803, Bucket(1507) }, // 24.92, 121.2 x 25.76, 122
    { 157815, Bucket(1512) }, // 29.96, 119.5 x 30.8, 120.3
    { 157816, Bucket(1515) }, // 27.44, 120.3 x 28.28, 121.2
    { 157822, Bucket(1518) }, // 29.12, 121.2 x 29.96, 122
    { 157961, Bucket(1522) }, // 31.63, 117 x 32.47, 117.8
    { 157963, 938 }, // 31.63, 117.8 x 32.47, 118.6
    { 157985, Bucket(1525) }, // 31.63, 118.6 x 32.47, 119.5
    { 157992, Bucket(1531) }, // 30.8, 120.3 x 31.63, 121.2
    { 157994, Bucket(1534) }, // 30.8, 121.2 x 31.63, 122
    { 158012, Bucket(1549) }, // 35.83, 120.3 x 36.67, 121.2
    { 158022, Bucket(1552) }, // 39.18, 116.1 x 40.02, 117
    { 158025, Bucket(1560) }, // 38.35, 117 x 39.18, 117.8
    { 158028, 1948 }, // 39.18, 117 x 40.02, 117.8
    { 158059, Bucket(1563) }, // 38.35, 121.2 x 39.18, 122
    { 158135, Bucket(1566) }, // 36.67, 126.2 x 37.51, 127
    { 158140, 1628 }, // 35.83, 127 x 36.67, 127.9
    { 158141, Bucket(1570) }, // 36.67, 127 x 37.51, 127.9
    { 158163, 1717 }, // 41.7, 122.8 x 42.54, 123.7
    { 158175, Bucket(1573) }, // 43.38, 124.5 x 44.22, 125.3
    { 158177, 1595 }, // 38.35, 125.3 x 39.18, 126.2
    { 158178, Bucket(1566) }, // 37.51, 126.2 x 38.35, 127
    { 158184, Bucket(1577) }, // 37.51, 127 x 38.35, 127.9
    { 158197, Bucket(1574) }, // 43.38, 125.3 x 44.22, 126.2
    { 158481, Bucket(1580) }, // 34.99, 128.7 x 35.83, 129.5
    { 158512, 450 }, // 34.15, 132.1 x 34.99, 132.9
    { 158520, Bucket(1583) }, // 34.15, 133.7 x 34.99, 134.6
    { 158608, Bucket(1586) }, // 34.15, 135.4 x 34.99, 136.3
    { 158609, 2321 }, // 34.99, 135.4 x 35.83, 136.3
    { 158643, Bucket(1590) }, // 34.99, 139.6 x 35.83, 140.4
    { 158646, 1919 }, // 35.83, 139.6 x 36.67, 140.4
    { 158696, 1561 }, // 37.51, 140.4 x 38.35, 141.3
    { 158718, 2546 }, // 42.54, 141.3 x 43.38, 142.1
    { 158883, 2935 }, // 45.06, 126.2 x 45.9, 127
    { 165214, Bucket(1595) }, // -37.99, 144.6 x -37.15, 145.5
    { 49148, 1408 }, // -37.15, -73.46 x -36.73, -73.05
    { 64751, 1543 }, // 8.566, -79.76 x 8.986, -79.34
    { 64762, 1543 }, // 8.986, -79.76 x 9.405, -79.34
    { 99549, Bucket(1605) }, // 37.09, -122.1 x 37.51, -121.7
    { 99714, 965 }, // 37.51, -122.5 x 37.93, -122.1
    { 99721, 1879 }, // 37.93, -122.1 x 38.35, -121.7
    { 99726, Bucket(1609) }, // 38.35, -121.7 x 38.77, -121.3
    { 99748, 2027 }, // 38.35, -121.3 x 38.77, -120.9
    { 99871, 1376 }, // 33.73, -118.3 x 34.15, -117.9
    { 99891, 2884 }, // 32.89, -117.5 x 33.31, -117.1
    { 101661, Bucket(1612) }, // 40.44, -112.1 x 40.86, -111.6
    { 102169, Bucket(1615) }, // 39.6, -105.3 x 40.02, -104.9
    { 102511, 1273 }, // 48.83, -123.4 x 49.25, -123
    { 102522, 1273 }, // 49.25, -123.4 x 49.67, -123
    { 102533, 169 }, // 45.48, -123 x 45.9, -122.5
    { 102551, Bucket(1620) }, // 47.15, -122.5 x 47.57, -122.1
    { 102594, Bucket(1624) }, // 47.57, -122.5 x 47.99, -122.1
    { 103356, Bucket(1644) }, // 53.45, -113.7 x 53.86, -113.3
    { 106512, 1038 }, // 19.05, -99.47 x 19.47, -99.05
    { 106963, Bucket(1647) }, // 29.54, -95.69 x 29.96, -95.28
    { 108494, 765 }, // 41.7, -88.14 x 42.12, -87.73
    { 108516, Bucket(1651) }, // 41.7, -87.73 x 42.12, -87.31
    { 109796, 2295 }, // 34.99, -81.01 x 35.41, -80.59
    { 110025, Bucket(1656) }, // 41.28, -81.85 x 41.7, -81.43
    { 110078, 2427 }, // 43.38, -79.76 x 43.8, -79.34
    { 110206, 1156 }, // 36.67, -76.4 x 37.09, -75.98
    { 110375, Bucket(1660) }, // 38.77, -77.24 x 39.18, -76.82
    { 110392, Bucket(1665) }, // 39.18, -76.82 x 39.6, -76.4
    { 110483, Bucket(1668) }, // 39.6, -75.56 x 40.02, -75.14
    { 110486, 1778 }, // 40.02, -75.56 x 40.44, -75.14
    { 110517, Bucket(1672) }, // 40.44, -74.3 x 40.86, -73.88
    { 110519, 2254 }, // 40.44, -73.88 x 40.86, -73.46
    { 110560, Bucket(1685) }, // 40.86, -74.3 x 41.28, -73.88
    { 112810, 2432 }, // 44.22, -79.76 x 44.64, -79.34
    { 113319, 2047 }, // 45.48, -73.88 x 45.9, -73.46
    { 147508, Bucket(1689) }, // -33.8, -70.95 x -33.38, -70.53
    { 149508, 226 }, // -35.47, -59.2 x -35.05, -58.78
    { 149509, 226 }, // -35.05, -59.2 x -34.64, -58.78
    { 149510, 226 }, // -35.47, -58.78 x -35.05, -58.37
    { 149511, Bucket(1692) }, // -35.05, -58.78 x -34.64, -58.37
    { 149522, Bucket(1695) }, // -34.64, -58.78 x -34.22, -58.37
    { 149777, 503 }, // -27.5, -59.2 x -27.09, -58.78
    { 150518, Bucket(1698) }, // -23.73, -47.04 x -23.31, -46.62
    { 150524, Bucket(1702) }, // -23.73, -46.62 x -23.31, -46.2
    { 151432, 1575 }, // -16.18, -48.3 x -15.76, -47.88
    { 152823, 1746 }, // 10.24, -67.17 x 10.66, -66.75
    { 156712, 2285 }, // -22.89, -43.27 x -22.47, -42.85
    { 157463, 1669 }, // -13.24, -38.65 x -12.82, -38.23
    { 160339, 1325 }, // -4.017, -38.65 x -3.597, -38.23
    { 160450, 2257 }, // -6.114, -35.3 x -5.694, -34.88
    { 188152, 1937 }, // 8.986, 7.066 x 9.405, 7.485
    { 196652, 1577 }, // 18.21, -70.11 x 18.63, -69.69
    { 196782, 1152 }, // 18.21, -66.33 x 18.63, -65.91
    { 197967, Bucket(1706) }, // 42.12, -71.37 x 42.54, -70.95
    { 197989, 433 }, // 42.12, -70.95 x 42.54, -70.53
    { 231214, 2391 }, // 38.35, -9.292 x 38.77, -8.872
    { 231300, 2391 }, // 38.35, -8.872 x 38.77, -8.453
    { 231317, 1797 }, // 40.44, -8.872 x 40.86, -8.453
    { 231360, Bucket(1715) }, // 40.86, -8.872 x 41.28, -8.453
    { 232540, 1616 }, // 36.67, -4.678 x 37.09, -4.259
    { 232565, 1447 }, // 37.09, -3.839 x 37.51, -3.42
    { 232735, 2015 }, // 40.44, -4.259 x 40.86, -3.839
    { 232757, 1639 }, // 40.44, -3.839 x 40.86, -3.42
    { 232913, Bucket(1719) }, // 42.96, -2.162 x 43.38, -1.742
    { 232938, 1269 }, // 40.86, 0.7745 x 41.28, 1.194
    { 233076, 1510 }, // 36.67, 2.872 x 37.09, 3.291
    { 233242, Bucket(1722) }, // 39.18, 2.452 x 39.6, 2.872
    { 233243, Bucket(1722) }, // 39.6, 2.452 x 40.02, 2.872
    { 233280, 1269 }, // 40.86, 1.194 x 41.28, 1.613
    { 233289, Bucket(1725) }, // 41.28, 2.033 x 41.7, 2.452
    { 233300, Bucket(1730) }, // 43.38, 1.194 x 43.8, 1.613
    { 233340, Bucket(1735) }, // 43.38, 3.711 x 43.8, 4.13
    { 233468, 2557 }, // 43.38, 7.066 x 43.8, 7.485
    { 234425, 1424 }, // 53.03, -6.356 x 53.45, -5.936
    { 235593, 2409 }, // 47.99, -4.678 x 48.41, -4.259
    { 235596, 2409 }, // 48.41, -4.678 x 48.83, -4.259
    { 235659, Bucket(1739) }, // 44.64, -0.9032 x 45.06, -0.4838
    { 235671, 613 }, // 47.15, -1.742 x 47.57, -1.323
    { 235709, 905 }, // 47.15, 0.3551 x 47.57, 0.7745
    { 235762, 990 }, // 49.25, -0.06436 x 49.67, 0.3551
    { 235909, 217 }, // 52.19, -2.162 x 52.61, -1.742
    { 235937, Bucket(1744) }, // 51.35, -0.4838 x 51.77, -0.06436
    { 235971, Bucket(1748) }, // 54.7, -1.742 x 55.12, -1.323
    { 236108, 1415 }, // 48.41, 2.033 x 48.83, 2.452
    { 236109, Bucket(1751) }, // 48.83, 2.033 x 49.25, 2.452
    { 236149, Bucket(1754) }, // 50.51, 2.872 x 50.93, 3.291
    { 236150, 1506 }, // 50.09, 3.291 x 50.51, 3.711
    { 236159, Bucket(1759) }, // 50.51, 4.13 x 50.93, 4.549
    { 236172, 1033 }, // 45.06, 5.388 x 45.48, 5.808
    { 236183, 551 }, // 47.15, 4.969 x 47.57, 5.388
    { 236186, Bucket(1780) }, // 45.9, 5.808 x 46.31, 6.227
    { 236191, Bucket(1783) }, // 47.15, 5.808 x 47.57, 6.227
    { 236209, 2878 }, // 46.31, 6.227 x 46.73, 6.647
    { 236214, 324 }, // 46.73, 6.647 x 47.15, 7.066
    { 236220, Bucket(1786) }, // 46.73, 7.066 x 47.15, 7.485
    { 236222, Bucket(1790) }, // 46.73, 7.485 x 47.15, 7.905
    { 236223, Bucket(1793) }, // 47.15, 7.485 x 47.57, 7.905
    { 236245, Bucket(1797) }, // 50.51, 4.549 x 50.93, 4.969
    { 236264, 1430 }, // 47.57, 7.066 x 47.99, 7.485
    { 236266, Bucket(1803) }, // 47.57, 7.485 x 47.99, 7.905
    { 236270, Bucket(1806) }, // 48.41, 7.485 x 48.83, 7.905
    { 236279, Bucket(1810) }, // 50.51, 6.647 x 50.93, 7.066
    { 236282, 688 }, // 49.25, 7.485 x 49.67, 7.905
    { 236285, Bucket(1813) }, // 50.51, 7.066 x 50.93, 7.485
    { 236330, Bucket(1818) }, // 50.93, 4.13 x 51.35, 4.549
    { 236334, Bucket(1822) }, // 51.77, 4.13 x 52.19, 4.549
    { 236420, 1281 }, // 51.77, 4.549 x 52.19, 4.969
    { 236421, 1938 }, // 52.19, 4.549 x 52.61, 4.969
    { 236422, 2363 }, // 51.77, 4.969 x 52.19, 5.388
    { 236450, Bucket(1832) }, // 50.93, 6.647 x 51.35, 7.066
    { 236451, 395 }, // 51.35, 6.647 x 51.77, 7.066
    { 236457, Bucket(1837) }, // 51.35, 7.066 x 51.77, 7.485
    { 237206, 1452 }, // 60.16, 4.969 x 60.58, 5.388
    { 238710, Bucket(1843) }, // 36.67, 10 x 37.09, 10.42
    { 239052, Bucket(1847) }, // 41.7, 12.1 x 42.12, 12.52
    { 239054, 623 }, // 41.7, 12.52 x 42.12, 12.94
    { 241436, 1672 }, // 40.02, 28.88 x 40.44, 29.3
    { 241474, Bucket(1850) }, // 40.86, 28.46 x 41.28, 28.88
    { 241480, Bucket(1854) }, // 40.86, 28.88 x 41.28, 29.3
    { 241563, Bucket(1861) }, // 39.6, 32.65 x 40.02, 33.07
    { 241672, 761 }, // 44.22, 8.744 x 44.64, 9.163
    { 241679, Bucket(1864) }, // 45.48, 9.163 x 45.9, 9.583
    { 241684, 2241 }, // 46.73, 7.905 x 47.15, 8.324
    { 241685, Bucket(1867) }, // 47.15, 7.905 x 47.57, 8.324
    { 241687, Bucket(1872) }, // 47.15, 8.324 x 47.57, 8.744
    { 241692, 1889 }, // 46.73, 8.744 x 47.15, 9.163
    { 241693, Bucket(1894) }, // 47.15, 8.744 x 47.57, 9.163
    { 241694, Bucket(1898) }, // 46.73, 9.163 x 47.15, 9.583
    { 241695, Bucket(1901) }, // 47.15, 9.163 x 47.57, 9.583
    { 241716, 190 }, // 46.73, 9.583 x 47.15, 10
    { 241717, 987 }, // 47.15, 9.583 x 47.57, 10
    { 241727, Bucket(1905) }, // 47.15, 10.84 x 47.57, 11.26
    { 241730, 508 }, // 47.57, 8.324 x 47.99, 8.744
    { 241733, 1071 }, // 48.83, 7.905 x 49.25, 8.324
    { 241735, Bucket(1909) }, // 48.83, 8.324 x 49.25, 8.744
    { 241742, 159 }, // 48.41, 9.163 x 48.83, 9.583
    { 241744, Bucket(1921) }, // 49.25, 7.905 x 49.67, 8.324
    { 241746, Bucket(1924) }, // 49.25, 8.324 x 49.67, 8.744
    { 241747, Bucket(1931) }, // 49.67, 8.324 x 50.09, 8.744
    { 241750, Bucket(1936) }, // 50.09, 8.324 x 50.51, 8.744
    { 241752, Bucket(1920) }, // 49.25, 8.744 x 49.67, 9.163
    { 241754, 687 }, // 49.25, 9.163 x 49.67, 9.583
    { 241756, 565 }, // 50.09, 8.744 x 50.51, 9.163
    { 241771, Bucket(1940) }, // 47.99, 10.84 x 48.41, 11.26
    { 241775, 185 }, // 48.83, 10.84 x 49.25, 11.26
    { 241786, Bucket(1944) }, // 49.25, 10.84 x 49.67, 11.26
    { 241798, 277 }, // 45.06, 11.68 x 45.48, 12.1
    { 241813, 1037 }, // 47.15, 11.26 x 47.57, 11.68
    { 241823, 1867 }, // 47.15, 12.52 x 47.57, 12.94
    { 241845, 1867 }, // 47.15, 12.94 x 47.57, 13.36
    { 241855, 2187 }, // 47.15, 14.2 x 47.57, 14.62
    { 241856, 2533 }, // 47.57, 11.26 x 47.99, 11.68
    { 241857, Bucket(1952) }, // 47.99, 11.26 x 48.41, 11.68
    { 241858, 2533 }, // 47.57, 11.68 x 47.99, 12.1
    { 241859, 106 }, // 47.99, 11.68 x 48.41, 12.1
    { 241860, 1434 }, // 48.41, 11.26 x 48.83, 11.68
    { 241862, 1434 }, // 48.41, 11.68 x 48.83, 12.1
    { 241866, Bucket(1959) }, // 47.57, 12.52 x 47.99, 12.94
    { 241885, 656 }, // 50.51, 12.1 x 50.93, 12.52
    { 241887, 1229 }, // 50.51, 12.52 x 50.93, 12.94
    { 241888, Bucket(1958) }, // 47.57, 12.94 x 47.99, 13.36
    { 241899, Bucket(1962) }, // 47.99, 14.2 x 48.41, 14.62
    { 241915, Bucket(1965) }, // 49.67, 14.2 x 50.09, 14.62
    { 241918, Bucket(1975) }, // 50.09, 14.2 x 50.51, 14.62
    { 241926, Bucket(1981) }, // 51.77, 8.324 x 52.19, 8.744
    { 241935, 775 }, // 52.19, 9.163 x 52.61, 9.583
    { 241946, 775 }, // 52.61, 9.163 x 53.03, 9.583
    { 241950, 1224 }, // 53.45, 9.163 x 53.86, 9.583
    { 241957, Bucket(1985) }, // 52.19, 9.583 x 52.61, 10
    { 241961, 113 }, // 51.35, 10.42 x 51.77, 10.84
    { 241962, Bucket(2000) }, // 50.93, 10.84 x 51.35, 11.26
    { 241972, 158 }, // 53.45, 9.583 x 53.86, 10
    { 242068, Bucket(2004) }, // 53.45, 11.26 x 53.86, 11.68
    { 242071, Bucket(2008) }, // 53.86, 11.68 x 54.28, 12.1
    { 242077, Bucket(2012) }, // 53.86, 12.1 x 54.28, 12.52
    { 242082, Bucket(2017) }, // 50.93, 13.36 x 51.35, 13.78
    { 242085, Bucket(2021) }, // 52.19, 12.94 x 52.61, 13.36
    { 242087, Bucket(2029) }, // 52.19, 13.36 x 52.61, 13.78
    { 242088, 1170 }, // 50.93, 13.78 x 51.35, 14.2
    { 242198, 2478 }, // 46.73, 15.04 x 47.15, 15.45
    { 242199, 182 }, // 47.15, 15.04 x 47.57, 15.45
    { 242251, Bucket(2044) }, // 47.99, 15.87 x 48.41, 16.29
    { 242273, Bucket(2048) }, // 47.99, 16.29 x 48.41, 16.71
    { 242333, Bucket(2057) }, // 47.15, 18.81 x 47.57, 19.23
    { 242432, Bucket(2067) }, // 50.93, 14.62 x 51.35, 15.04
    { 242471, Bucket(2070) }, // 52.19, 16.71 x 52.61, 17.13
    { 242571, Bucket(2090) }, // 51.35, 19.23 x 51.77, 19.65
    { 242574, Bucket(2103) }, // 51.77, 19.23 x 52.19, 19.65
    { 242591, 610 }, // 53.86, 19.23 x 54.28, 19.65
    { 242745, Bucket(2113) }, // 59.74, 10.42 x 60.16, 10.84
    { 242818, Bucket(2120) }, // 57.64, 11.68 x 58.06, 12.1
    { 243333, 781 }, // 58.9, 17.97 x 59.32, 18.39
    { 243344, Bucket(2123) }, // 59.32, 17.97 x 59.74, 18.39
    { 243833, Bucket(2127) }, // 49.67, 23.84 x 50.09, 24.26
    { 243850, Bucket(2131) }, // 44.22, 25.94 x 44.64, 26.36
    { 244374, 2486 }, // 46.73, 31.81 x 47.15, 32.23
    { 244884, Bucket(2140) }, // 60.16, 24.68 x 60.58, 25.1
    { 245299, Bucket(2144) }, // 59.74, 30.13 x 60.16, 30.55
    { 545991, 1235 }, // 8.566, 38.52 x 8.986, 38.94
    { 546002, Bucket(2150) }, // 8.986, 38.52 x 9.405, 38.94
    { 556126, 1638 }, // 9.824, 76.27 x 10.24, 76.69
    { 556465, 1659 }, // 12.76, 80.05 x 13.18, 80.47
    { 578555, 2293 }, // 2.694, 101.4 x 3.114, 101.9
    { 578558, 2293 }, // 3.114, 101.4 x 3.533, 101.9
    { 579420, Bucket(2153) }, // 16.54, 95.99 x 16.95, 96.4
    { 579509, Bucket(2158) }, // 13.6, 100.2 x 14.02, 100.6
    { 581702, 914 }, // -32.12, 115.7 x -31.7, 116.1
    { 587235, Bucket(2161) }, // 14.44, 120.7 x 14.86, 121.2
    { 590049, 1593 }, // 21.15, 39.78 x 21.57, 40.2
    { 590753, Bucket(2165) }, // 24.5, 46.49 x 24.92, 46.91
    { 591755, 1513 }, // 37.93, 46.07 x 38.35, 46.49
    { 592345, 1537 }, // 29.54, 52.36 x 29.96, 52.78
    { 593007, Bucket(2168) }, // 35.41, 51.11 x 35.83, 51.53
    { 593040, 1538 }, // 32.47, 51.53 x 32.89, 51.95
    { 593988, 1589 }, // 48.41, 34.75 x 48.83, 35.17
    { 594011, Bucket(2171) }, // 49.67, 36.01 x 50.09, 36.43
    { 594285, Bucket(2174) }, // 55.54, 37.26 x 55.96, 37.68
    { 594287, 2294 }, // 55.54, 37.68 x 55.96, 38.1
    { 596245, Bucket(2181) }, // 53.86, 48.17 x 54.28, 48.59
    { 596288, Bucket(2181) }, // 54.28, 48.17 x 54.7, 48.59
    { 596301, 1571 }, // 55.54, 49.01 x 55.96, 49.43
    { 596429, Bucket(2186) }, // 55.54, 52.36 x 55.96, 52.78
    { 598682, 2892 }, // 19.05, 72.92 x 19.47, 73.34
    { 599721, 2542 }, // 31.22, 74.17 x 31.63, 74.59
    { 600258, 2437 }, // 20.73, 78.79 x 21.15, 79.21
    { 600420, 1711 }, // 28.28, 76.69 x 28.7, 77.11
    { 600422, 1851 }, // 28.28, 77.11 x 28.7, 77.53
    { 600502, 1897 }, // 26.6, 80.47 x 27.02, 80.89
    { 600508, 1897 }, // 26.6, 80.89 x 27.02, 81.31
    { 600826, 1847 }, // 22.41, 88.02 x 22.83, 88.44
    { 601457, 1594 }, // 42.96, 76.69 x 43.38, 77.11
    { 624890, 2552 }, // 22.41, 108.1 x 22.83, 108.6
    { 624908, 762 }, // 24.92, 102.7 x 25.34, 103.1
    { 625015, Bucket(2191) }, // 30.38, 104 x 30.8, 104.4
    { 625051, 1598 }, // 26.18, 106.5 x 26.6, 106.9
    { 625054, 1598 }, // 26.6, 106.5 x 27.02, 106.9
    { 625371, Bucket(2197) }, // 22.83, 113.2 x 23.25, 113.6
    { 625383, Bucket(2202) }, // 21.99, 114 x 22.41, 114.4
    { 625393, Bucket(2206) }, // 22.83, 113.6 x 23.25, 114
    { 625394, Bucket(2209) }, // 22.41, 114 x 22.83, 114.4
    { 625609, Bucket(2214) }, // 27.86, 112.8 x 28.28, 113.2
    { 625655, Bucket(2218) }, // 30.38, 114 x 30.8, 114.4
    { 625776, 2355 }, // 35.83, 103.5 x 36.25, 104
    { 626240, 1673 }, // 34.15, 108.6 x 34.57, 109
    { 626242, 2911 }, // 34.15, 109 x 34.57, 109.4
    { 626379, Bucket(2224) }, // 34.57, 113.2 x 34.99, 113.6
    { 626401, Bucket(2229) }, // 34.57, 113.6 x 34.99, 114
    { 626495, Bucket(2235) }, // 40.44, 111.5 x 40.86, 111.9
    { 626538, 2528 }, // 40.86, 111.5 x 41.28, 111.9
    { 626562, 2553 }, // 37.51, 112.3 x 37.93, 112.8
    { 631002, Bucket(2238) }, // 22.41, 119.9 x 22.83, 120.3
    { 631024, Bucket(2238) }, // 22.41, 120.3 x 22.83, 120.7
    { 631110, 886 }, // 28.28, 115.7 x 28.7, 116.1
    { 631186, 2387 }, // 25.76, 119.1 x 26.18, 119.5
    { 631212, 1421 }, // 24.92, 121.2 x 25.34, 121.6
    { 631262, Bucket(2241) }, // 29.96, 119.9 x 30.38, 120.3
    { 631284, Bucket(2246) }, // 29.96, 120.3 x 30.38, 120.7
    { 631289, 2358 }, // 29.54, 121.2 x 29.96, 121.6
    { 631293, 1818 }, // 30.38, 121.2 x 30.8, 121.6
    { 631844, 1772 }, // 31.63, 117 x 32.05, 117.4
    { 631861, 2908 }, // 33.73, 117 x 34.15, 117.4
    { 631904, Bucket(2249) }, // 34.15, 117 x 34.57, 117.4
    { 631924, 1904 }, // 36.67, 117 x 37.09, 117.4
    { 631940, 1726 }, // 31.63, 118.6 x 32.05, 119.1
    { 631941, Bucket(2252) }, // 32.05, 118.6 x 32.47, 119.1
    { 631971, 1936 }, // 31.22, 120.7 x 31.63, 121.2
    { 631976, Bucket(2255) }, // 30.8, 121.2 x 31.22, 121.6
    { 632089, Bucket(2258) }, // 39.6, 116.1 x 40.02, 116.5
    { 632092, Bucket(2265) }, // 40.02, 116.1 x 40.44, 116.5
    { 632101, Bucket(2268) }, // 38.77, 117 x 39.18, 117.4
    { 632112, Bucket(2269) }, // 39.18, 117 x 39.6, 117.4
    { 632239, 1723 }, // 38.77, 121.6 x 39.18, 122
    { 632526, 1629 }, // 34.99, 126.6 x 35.41, 127
    { 632559, 1662 }, // 35.41, 128.3 x 35.83, 128.7
    { 632565, 1559 }, // 37.09, 127 x 37.51, 127.4
    { 632570, Bucket(2273) }, // 35.83, 128.3 x 36.25, 128.7
    { 632581, 1723 }, // 38.77, 122 x 39.18, 122.4
    { 632651, Bucket(2276) }, // 41.28, 123.2 x 41.7, 123.7
    { 632654, Bucket(2279) }, // 41.7, 123.2 x 42.12, 123.7
    { 633924, Bucket(2285) }, // 34.99, 128.7 x 35.41, 129.1
    { 634080, 2469 }, // 34.15, 133.7 x 34.57, 134.2
    { 634433, 2324 }, // 34.57, 135.4 x 34.99, 135.8
    { 634446, Bucket(2289) }, // 34.99, 136.7 x 35.41, 137.1
    { 634450, 2332 }, // 35.83, 135.8 x 36.25, 136.3
    { 634468, 2530 }, // 34.99, 137.1 x 35.41, 137.5
    { 634573, Bucket(2294) }, // 35.41, 139.6 x 35.83, 140
    { 635535, 1770 }, // 45.48, 126.6 x 45.9, 127
    { 660847, 798 }, // -38.41, 145.1 x -37.99, 145.5
    { 660856, Bucket(2305) }, // -37.99, 144.6 x -37.57, 145.1
    { 669174, 12 }, // -37.15, 174.4 x -36.73, 174.8
    { 669180, 12 }, // -37.15, 174.8 x -36.73, 175.3
    { 672260, 2326 }, // -35.47, 148.8 x -35.05, 149.3
    { 672307, 2200 }, // -34.22, 150.9 x -33.8, 151.4
    { 259050, 2075 }, // 8.986, -79.55 x 9.195, -79.34
    { 398857, Bucket(2315) }, // 37.72, -122.5 x 37.93, -122.3
    { 403703, Bucket(2321) }, // 20.52, -103.5 x 20.73, -103.2
    { 403874, 2524 }, // 20.73, -103.5 x 20.94, -103.2
    { 405616, 1982 }, // 33.31, -112.1 x 33.52, -111.8
    { 406645, 1307 }, // 40.65, -112.1 x 40.86, -111.8
    { 410047, Bucket(2325) }, // 49.04, -123.2 x 49.25, -123
    { 410090, Bucket(2325) }, // 49.25, -123.2 x 49.46, -123
    { 410131, 1217 }, // 45.27, -122.7 x 45.48, -122.5
    { 410134, Bucket(2328) }, // 45.48, -122.7 x 45.69, -122.5
    { 410389, Bucket(2325) }, // 49.04, -123 x 49.25, -122.7
    { 410432, Bucket(2325) }, // 49.25, -123 x 49.46, -122.7
    { 426051, Bucket(2331) }, // 19.26, -99.26 x 19.47, -99.05
    { 426054, 1762 }, // 19.47, -99.26 x 19.68, -99.05
    { 430305, 794 }, // 32.68, -96.95 x 32.89, -96.74
    { 433978, Bucket(2335) }, // 41.7, -87.94 x 41.91, -87.73
    { 434064, Bucket(2335) }, // 41.7, -87.73 x 41.91, -87.52
    { 435871, Bucket(2338) }, // 25.55, -80.39 x 25.76, -80.18
    { 435914, Bucket(2338) }, // 25.76, -80.39 x 25.97, -80.18
    { 438484, 1081 }, // 33.73, -84.37 x 33.94, -84.16
    { 440280, 2501 }, // 43.38, -80.59 x 43.59, -80.39
    { 440315, Bucket(2341) }, // 43.59, -79.55 x 43.8, -79.34
    { 441681, 1706 }, // 43.59, -79.34 x 43.8, -79.13
    { 441935, Bucket(2344) }, // 39.81, -75.35 x 40.02, -75.14
    { 441957, 1775 }, // 39.81, -75.14 x 40.02, -74.93
    { 442069, 2252 }, // 40.65, -74.3 x 40.86, -74.09
    { 442071, Bucket(2351) }, // 40.65, -74.09 x 40.86, -73.88
    { 442242, Bucket(2357) }, // 40.86, -74.09 x 41.07, -73.88
    { 443047, 671 }, // 44.85, -93.39 x 45.06, -93.18
    { 453139, 2301 }, // 45.27, -75.77 x 45.48, -75.56
    { 590035, Bucket(2360) }, // -33.59, -70.74 x -33.38, -70.53
    { 598044, 226 }, // -35.05, -58.78 x -34.84, -58.57
    { 598046, 226 }, // -35.05, -58.57 x -34.84, -58.37
    { 598047, 203 }, // -34.84, -58.57 x -34.64, -58.37
    { 598069, 203 }, // -34.84, -58.37 x -34.64, -58.16
    { 598090, Bucket(2365) }, // -34.64, -58.57 x -34.43, -58.37
    { 602074, 988 }, // -23.73, -46.83 x -23.52, -46.62
    { 605731, 1576 }, // -15.97, -48.09 x -15.76, -47.88
    { 611292, 1865 }, // 10.24, -67.17 x 10.45, -66.96
    { 611295, 2945 }, // 10.45, -66.96 x 10.66, -66.75
    { 624095, 1360 }, // -23.1, -43.48 x -22.89, -43.27
    { 624117, 1360 }, // -23.1, -43.27 x -22.89, -43.06
    { 626849, 2280 }, // -22.68, -43.27 x -22.47, -43.06
    { 626900, 1309 }, // -19.96, -44.1 x -19.75, -43.89
    { 629853, 1388 }, // -13.03, -38.65 x -12.82, -38.44
    { 630271, 2894 }, // -9.679, -35.93 x -9.469, -35.72
    { 639724, 2412 }, // -7.372, -39.49 x -7.162, -39.28
    { 641357, 2286 }, // -3.807, -38.65 x -3.597, -38.44
    { 641566, Bucket(2369) }, // -8.211, -35.09 x -8.001, -34.88
    { 641615, 2414 }, // -7.162, -35.09 x -6.953, -34.88
    { 641637, 2414 }, // -7.162, -34.88 x -6.953, -34.67
    { 752610, 2076 }, // 8.986, 7.276 x 9.195, 7.485
    { 786609, 1578 }, // 18.42, -70.11 x 18.63, -69.9
    { 791871, 1044 }, // 42.33, -71.16 x 42.54, -70.95
    { 918960, 91 }, // 28.28, -16.42 x 28.49, -16.21
    { 924375, 1195 }, // 33.94, -6.985 x 34.15, -6.775
    { 924857, Bucket(2373) }, // 38.56, -9.292 x 38.77, -9.082
    { 925443, Bucket(2377) }, // 41.07, -8.663 x 41.28, -8.453
    { 930939, Bucket(2381) }, // 40.23, -4.049 x 40.44, -3.839
    { 931025, Bucket(2384) }, // 40.23, -3.839 x 40.44, -3.63
    { 931028, 1655 }, // 40.44, -3.839 x 40.65, -3.63
    { 931279, Bucket(2389) }, // 43.17, -3.21 x 43.38, -3
    { 931299, Bucket(2393) }, // 42.75, -2.791 x 42.96, -2.581
    { 931301, Bucket(2396) }, // 43.17, -3 x 43.38, -2.791
    { 931364, 2891 }, // 37.93, -1.323 x 38.14, -1.113
    { 931435, 1227 }, // 39.39, -0.6935 x 39.6, -0.4838
    { 931521, Bucket(2401) }, // 39.39, -0.4838 x 39.6, -0.2741
    { 932306, Bucket(2407) }, // 36.67, 3.081 x 36.88, 3.291
    { 932379, 2925 }, // 31.84, 5.179 x 32.05, 5.388
    { 933134, Bucket(2410) }, // 41.28, 1.823 x 41.49, 2.033
    { 933156, Bucket(2414) }, // 41.28, 2.033 x 41.49, 2.243
    { 933711, 220 }, // 43.17, 5.179 x 43.38, 5.388
    { 933733, 220 }, // 43.17, 5.388 x 43.38, 5.598
    { 933873, 2328 }, // 43.59, 7.066 x 43.8, 7.276
    { 942684, 615 }, // 47.15, -1.742 x 47.36, -1.532
    { 942719, 920 }, // 47.36, -0.6935 x 47.57, -0.4838
    { 942860, 1027 }, // 47.99, -1.742 x 48.2, -1.532
    { 943082, 738 }, // 49.25, 0.9842 x 49.46, 1.194
    { 943343, Bucket(2430) }, // 53.24, -2.371 x 53.45, -2.162
    { 943354, Bucket(2434) }, // 53.45, -2.371 x 53.65, -2.162
    { 943415, 1588 }, // 55.75, -4.468 x 55.96, -4.259
    { 943421, 1588 }, // 55.75, -4.259 x 55.96, -4.049
    { 943695, Bucket(2441) }, // 53.24, -1.532 x 53.45, -1.323
    { 943713, 574 }, // 52.82, -1.323 x 53.03, -1.113
    { 943750, 1519 }, // 51.35, -0.2741 x 51.56, -0.06436
    { 943756, Bucket(2446) }, // 51.35, -0.06436 x 51.56, 0.1454
    { 943757, 194 }, // 51.56, -0.06436 x 51.77, 0.1454
    { 943759, 2238 }, // 51.56, 0.1454 x 51.77, 0.3551
    { 944279, 2053 }, // 45.69, 3.081 x 45.9, 3.291
    { 944395, Bucket(2449) }, // 47.78, 1.823 x 47.99, 2.033
    { 944435, Bucket(2452) }, // 48.62, 2.243 x 48.83, 2.452
    { 944438, Bucket(2456) }, // 48.83, 2.243 x 49.04, 2.452
    { 944444, Bucket(2468) }, // 48.83, 2.452 x 49.04, 2.662
    { 944603, 1500 }, // 50.3, 3.501 x 50.51, 3.711
    { 944635, Bucket(2471) }, // 50.3, 4.34 x 50.51, 4.549
    { 944639, Bucket(2474) }, // 50.72, 4.34 x 50.93, 4.549
    { 944663, Bucket(2480) }, // 45.69, 4.759 x 45.9, 4.969
    { 944690, Bucket(2487) }, // 45.06, 5.598 x 45.27, 5.808
    { 944732, 552 }, // 47.15, 4.969 x 47.36, 5.179
    { 944747, Bucket(2491) }, // 46.11, 6.017 x 46.31, 6.227
    { 944893, Bucket(2495) }, // 47.36, 7.485 x 47.57, 7.695
    { 945003, 1604 }, // 49.46, 6.017 x 49.67, 6.227
    { 945064, Bucket(2509) }, // 47.57, 7.485 x 47.78, 7.695
    { 945067, Bucket(2517) }, // 47.78, 7.695 x 47.99, 7.905
    { 945070, Bucket(2517) }, // 47.99, 7.695 x 48.2, 7.905
    { 945119, Bucket(2520) }, // 50.72, 6.856 x 50.93, 7.066
    { 945290, Bucket(2524) }, // 50.93, 3.501 x 51.14, 3.711
    { 945312, Bucket(2524) }, // 50.93, 3.711 x 51.14, 3.92
    { 945323, Bucket(2528) }, // 51.14, 4.34 x 51.35, 4.549
    { 945337, Bucket(2540) }, // 51.98, 4.13 x 52.19, 4.34
    { 945338, Bucket(2547) }, // 51.77, 4.34 x 51.98, 4.549
    { 945339, Bucket(2554) }, // 51.98, 4.34 x 52.19, 4.549
    { 945680, 1282 }, // 51.77, 4.549 x 51.98, 4.759
    { 945686, Bucket(2558) }, // 52.19, 4.759 x 52.4, 4.969
    { 945689, Bucket(2567) }, // 51.98, 4.969 x 52.19, 5.179
    { 945801, Bucket(2570) }, // 51.14, 6.647 x 51.35, 6.856
    { 945802, Bucket(2575) }, // 50.93, 6.856 x 51.14, 7.066
    { 945806, Bucket(2580) }, // 51.35, 6.856 x 51.56, 7.066
    { 945828, Bucket(2583) }, // 51.35, 7.066 x 51.56, 7.276
    { 945830, Bucket(2587) }, // 51.35, 7.276 x 51.56, 7.485
    { 954840, 1950 }, // 36.67, 10 x 36.88, 10.21
    { 956157, 2882 }, // 40.65, 14.2 x 40.86, 14.41
    { 956328, 2344 }, // 40.86, 14.2 x 41.07, 14.41
    { 957833, 903 }, // 41.07, 16.71 x 41.28, 16.92
    { 962042, Bucket(2590) }, // 29.96, 31.18 x 30.17, 31.39
    { 962384, 1526 }, // 29.96, 31.39 x 30.17, 31.6
    { 963726, 1780 }, // 37.93, 23.63 x 38.14, 23.84
    { 964034, Bucket(2593) }, // 42.54, 23.21 x 42.75, 23.42
    { 964250, Bucket(2598) }, // 38.35, 26.99 x 38.56, 27.2
    { 964272, 1793 }, // 38.35, 27.2 x 38.56, 27.41
    { 965898, 2899 }, // 40.86, 28.67 x 41.07, 28.88
    { 965899, 2899 }, // 41.07, 28.67 x 41.28, 28.88
    { 965920, 869 }, // 40.86, 28.88 x 41.07, 29.09
    { 966253, Bucket(2602) }, // 39.81, 32.65 x 40.02, 32.86
    { 966741, 2322 }, // 47.36, 7.905 x 47.57, 8.115
    { 966745, 2241 }, // 46.94, 8.324 x 47.15, 8.534
    { 966748, 2241 }, // 47.15, 8.324 x 47.36, 8.534
    { 966749, 2241 }, // 47.36, 8.324 x 47.57, 8.534
    { 966751, Bucket(2605) }, // 47.36, 8.534 x 47.57, 8.744
    { 966767, Bucket(2609) }, // 46.52, 9.373 x 46.73, 9.583
    { 966772, 1889 }, // 47.15, 8.744 x 47.36, 8.953
    { 966773, Bucket(2612) }, // 47.36, 8.744 x 47.57, 8.953
    { 966775, 986 }, // 47.36, 8.953 x 47.57, 9.163
    { 966778, 191 }, // 46.73, 9.373 x 46.94, 9.583
    { 966781, 986 }, // 47.36, 9.163 x 47.57, 9.373
    { 966853, 190 }, // 46.52, 9.583 x 46.73, 9.792
    { 966869, 2476 }, // 47.36, 9.583 x 47.57, 9.792
    { 966922, 507 }, // 47.57, 8.534 x 47.78, 8.744
    { 966940, Bucket(2615) }, // 48.83, 8.324 x 49.04, 8.534
    { 966941, 1071 }, // 49.04, 8.324 x 49.25, 8.534
    { 966942, 1071 }, // 48.83, 8.534 x 49.04, 8.744
    { 966944, 1930 }, // 47.57, 8.744 x 47.78, 8.953
    { 966964, 691 }, // 48.83, 8.744 x 49.04, 8.953
    { 966965, Bucket(2621) }, // 49.04, 8.744 x 49.25, 8.953
    { 966966, 162 }, // 48.83, 8.953 x 49.04, 9.163
    { 966967, Bucket(2621) }, // 49.04, 8.953 x 49.25, 9.163
    { 966972, 162 }, // 48.83, 9.163 x 49.04, 9.373
    { 966973, 691 }, // 49.04, 9.163 x 49.25, 9.373
    { 966975, 691 }, // 49.04, 9.373 x 49.25, 9.583
    { 966983, Bucket(2624) }, // 49.88, 8.115 x 50.09, 8.324
    { 966986, Bucket(2627) }, // 49.25, 8.534 x 49.46, 8.744
    { 966988, 468 }, // 49.67, 8.324 x 49.88, 8.534
    { 966989, 945 }, // 49.88, 8.324 x 50.09, 8.534
    { 966991, Bucket(2631) }, // 49.88, 8.534 x 50.09, 8.744
    { 967002, Bucket(2636) }, // 50.09, 8.534 x 50.3, 8.744
    { 967013, Bucket(2624) }, // 49.88, 8.744 x 50.09, 8.953
    { 967024, Bucket(2624) }, // 50.09, 8.744 x 50.3, 8.953
    { 967071, 620 }, // 49.04, 10.21 x 49.25, 10.42
    { 967082, 2533 }, // 47.57, 11.05 x 47.78, 11.26
    { 967085, 603 }, // 48.2, 10.84 x 48.41, 11.05
    { 967146, 186 }, // 49.25, 11.05 x 49.46, 11.26
    { 967252, Bucket(2649) }, // 47.15, 11.26 x 47.36, 11.47
    { 967430, Bucket(2655) }, // 47.99, 11.47 x 48.2, 11.68
    { 967467, 1869 }, // 47.78, 12.73 x 47.99, 12.94
    { 967488, Bucket(2673) }, // 49.25, 11.26 x 49.46, 11.47
    { 967553, 1869 }, // 47.78, 12.94 x 47.99, 13.15
    { 967597, Bucket(2676) }, // 48.2, 14.2 x 48.41, 14.41
    { 967628, Bucket(2683) }, // 49.67, 13.36 x 49.88, 13.57
    { 967663, 131 }, // 49.88, 14.41 x 50.09, 14.62
    { 967674, 131 }, // 50.09, 14.41 x 50.3, 14.62
    { 967742, 1077 }, // 52.19, 9.373 x 52.4, 9.583
    { 967780, Bucket(2686) }, // 53.03, 8.744 x 53.24, 8.953
    { 967828, Bucket(2694) }, // 52.19, 9.583 x 52.4, 9.792
    { 967860, Bucket(2697) }, // 52.19, 10.42 x 52.4, 10.63
    { 967872, 775 }, // 52.61, 9.583 x 52.82, 9.792
    { 967891, 1155 }, // 53.65, 9.792 x 53.86, 10
    { 968206, Bucket(2704) }, // 51.35, 11.89 x 51.56, 12.1
    { 968211, Bucket(2715) }, // 51.98, 11.47 x 52.19, 11.68
    { 968227, Bucket(2719) }, // 51.14, 12.31 x 51.35, 12.52
    { 968230, Bucket(2720) }, // 51.35, 12.31 x 51.56, 12.52
    { 968240, 147 }, // 51.77, 12.1 x 51.98, 12.31
    { 968321, 796 }, // 51.14, 12.94 x 51.35, 13.15
    { 968322, 1328 }, // 50.93, 13.15 x 51.14, 13.36
    { 968324, 796 }, // 51.35, 12.94 x 51.56, 13.15
    { 968330, Bucket(2723) }, // 50.93, 13.57 x 51.14, 13.78
    { 968349, Bucket(2734) }, // 52.4, 13.36 x 52.61, 13.57
    { 968351, 35 }, // 52.4, 13.57 x 52.61, 13.78
    { 968352, Bucket(2743) }, // 50.93, 13.78 x 51.14, 13.99
    { 968431, Bucket(2751) }, // 53.24, 14.41 x 53.45, 14.62
    { 968442, Bucket(2758) }, // 53.45, 14.41 x 53.65, 14.62
    { 968795, Bucket(2763) }, // 46.94, 15.24 x 47.15, 15.45
    { 968817, Bucket(2767) }, // 46.94, 15.45 x 47.15, 15.66
    { 969006, 80 }, // 47.99, 16.08 x 48.2, 16.29
    { 969092, 80 }, // 47.99, 16.29 x 48.2, 16.5
    { 969111, Bucket(2770) }, // 49.04, 16.5 x 49.25, 16.71
    { 969246, 246 }, // 45.48, 18.6 x 45.69, 18.81
    { 969335, Bucket(2782) }, // 47.36, 19.02 x 47.57, 19.23
    { 969358, Bucket(2805) }, // 44.64, 20.28 x 44.85, 20.49
    { 969659, Bucket(2811) }, // 48.62, 21.12 x 48.83, 21.33
    { 970287, 2108 }, // 51.56, 19.44 x 51.77, 19.65
    { 970298, 2108 }, // 51.77, 19.44 x 51.98, 19.65
    { 970428, 1065 }, // 52.19, 20.91 x 52.4, 21.12
    { 970982, 860 }, // 59.74, 10.63 x 59.95, 10.84
    { 971274, Bucket(2824) }, // 57.64, 11.89 x 57.85, 12.1
    { 972858, Bucket(2834) }, // 58.48, 16.08 x 58.69, 16.29
    { 972991, Bucket(2837) }, // 59.11, 17.76 x 59.32, 17.97
    { 973034, Bucket(2837) }, // 59.32, 17.76 x 59.53, 17.97
    { 973333, Bucket(2841) }, // 59.11, 17.97 x 59.32, 18.18
    { 973335, 780 }, // 59.11, 18.18 x 59.32, 18.39
    { 973376, Bucket(2849) }, // 59.32, 17.97 x 59.53, 18.18
    { 975401, Bucket(2859) }, // 44.43, 25.94 x 44.64, 26.15
    { 977371, 548 }, // 50.3, 30.34 x 50.51, 30.55
    { 977850, Bucket(2862) }, // 48.41, 34.54 x 48.62, 34.75
    { 978328, Bucket(2865) }, // 55.12, 30.13 x 55.33, 30.34
    { 2226005, 1893 }, // 17.16, 78.37 x 17.37, 78.58
    { 2314234, 1805 }, // 3.114, 101.6 x 3.323, 101.9
    { 2317681, 1999 }, // 16.75, 95.99 x 16.95, 96.19
    { 2318038, 1796 }, // 13.6, 100.4 x 13.81, 100.6
    { 2318975, Bucket(2868) }, // -6.324, 106.7 x -6.114, 106.9
    { 2319751, Bucket(2871) }, // 1.226, 103.7 x 1.436, 104
    { 2326808, 589 }, // -32.12, 115.7 x -31.91, 115.9
    { 2348942, 1804 }, // 14.44, 120.9 x 14.65, 121.2
    { 2348943, 2010 }, // 14.65, 120.9 x 14.86, 121.2
    { 2363737, 1643 }, // 36.88, 35.17 x 37.09, 35.38
    { 2366712, 1783 }, // 40.02, 44.4 x 40.23, 44.6
    { 2368699, 2365 }, // 25.13, 51.32 x 25.34, 51.53
    { 2370578, 2903 }, // 24.92, 55.09 x 25.13, 55.3
    { 2372031, Bucket(2874) }, // 35.62, 51.32 x 35.83, 51.53
    { 2372373, 1636 }, // 35.62, 51.53 x 35.83, 51.74
    { 2372817, Bucket(2878) }, // 40.23, 49.85 x 40.44, 50.06
    { 2374508, 1236 }, // 36.25, 59.49 x 36.46, 59.7
    { 2375923, Bucket(2881) }, // 46.94, 37.47 x 47.15, 37.68
    { 2375926, Bucket(2888) }, // 47.15, 37.47 x 47.36, 37.68
    { 2376047, 545 }, // 49.88, 36.22 x 50.09, 36.43
    { 2377139, 499 }, // 55.33, 37.47 x 55.54, 37.68
    { 2377142, 499 }, // 55.54, 37.47 x 55.75, 37.68
    { 2378169, Bucket(2892) }, // 48.62, 44.4 x 48.83, 44.6
    { 2379211, 717 }, // 56.17, 43.77 x 56.38, 43.98
    { 2379233, 717 }, // 56.17, 43.98 x 56.38, 44.19
    { 2385716, 2932 }, // 55.54, 52.36 x 55.75, 52.57
    { 2394685, Bucket(2895) }, // 18.84, 72.92 x 19.05, 73.13
    { 2394728, 2498 }, // 19.05, 72.92 x 19.26, 73.13
    { 2400768, Bucket(2898) }, // 17.37, 78.37 x 17.58, 78.58
    { 2401371, 1795 }, // 26.81, 75.64 x 27.02, 75.85
    { 2401683, 1858 }, // 28.49, 76.9 x 28.7, 77.11
    { 2420007, 1572 }, // 54.91, 82.77 x 55.12, 82.98
    { 2420206, Bucket(2901) }, // 56.38, 84.87 x 56.59, 85.08
    { 2499337, 2551 }, // 20.94, 105.6 x 21.15, 105.8
    { 2499632, 1724 }, // 24.92, 102.7 x 25.13, 102.9
    { 2500061, 1890 }, // 30.59, 104 x 30.8, 104.2
    { 2500460, Bucket(2904) }, // 29.54, 106.5 x 29.75, 106.7
    { 2501476, 2403 }, // 22.83, 112.8 x 23.04, 113
    { 2501485, Bucket(2907) }, // 23.04, 113.2 x 23.25, 113.4
    { 2501487, Bucket(2911) }, // 23.04, 113.4 x 23.25, 113.6
    { 2501533, Bucket(2914) }, // 22.2, 114 x 22.41, 114.2
    { 2501570, 2926 }, // 22.41, 113.8 x 22.62, 114
    { 2501571, 1548 }, // 22.62, 113.8 x 22.83, 114
    { 2501576, Bucket(2917) }, // 22.41, 114 x 22.62, 114.2
    { 2502622, 2549 }, // 30.38, 114.2 x 30.59, 114.4
    { 2502644, 2549 }, // 30.38, 114.4 x 30.59, 114.6
    { 2502792, 2406 }, // 30.8, 104 x 31.01, 104.2
    { 2506404, 2514 }, // 37.93, 114.4 x 38.14, 114.6
    { 2516119, Bucket(2920) }, // 52.4, 103.7 x 52.61, 104
    { 2516126, Bucket(2925) }, // 52.19, 104.2 x 52.4, 104.4
    { 2524747, 1719 }, // 25.97, 119.3 x 26.18, 119.5
    { 2524850, Bucket(2930) }, // 24.92, 121.4 x 25.13, 121.6
    { 2525051, 2888 }, // 30.17, 120.1 x 30.38, 120.3
    { 2525137, 2888 }, // 30.17, 120.3 x 30.38, 120.5
    { 2527378, 2881 }, // 31.63, 117.2 x 31.84, 117.4
    { 2527419, 1727 }, // 31.84, 118.4 x 32.05, 118.6
    { 2527618, 2909 }, // 34.15, 117.2 x 34.36, 117.4
    { 2527751, 2081 }, // 31.43, 118.8 x 31.63, 119.1
    { 2527761, 1727 }, // 31.84, 118.6 x 32.05, 118.8
    { 2527762, 2081 }, // 31.63, 118.8 x 31.84, 119.1
    { 2527791, Bucket(2933) }, // 31.43, 120.1 x 31.63, 120.3
    { 2527800, Bucket(2936) }, // 31.63, 119.9 x 31.84, 120.1
    { 2527876, Bucket(2939) }, // 31.22, 120.3 x 31.43, 120.5
    { 2527877, Bucket(2942) }, // 31.43, 120.3 x 31.63, 120.5
    { 2527878, Bucket(2946) }, // 31.22, 120.5 x 31.43, 120.7
    { 2527879, 1936 }, // 31.43, 120.5 x 31.63, 120.7
    { 2527884, Bucket(2939) }, // 31.22, 120.7 x 31.43, 120.9
    { 2528107, 1701 }, // 36.04, 120.1 x 36.25, 120.3
    { 2528193, Bucket(2950) }, // 36.04, 120.3 x 36.25, 120.5
    { 2528334, 1943 }, // 39.6, 115.9 x 39.81, 116.1
    { 2528357, 1901 }, // 39.81, 116.1 x 40.02, 116.3
    { 2528359, 300 }, // 39.81, 116.3 x 40.02, 116.5
    { 2530173, Bucket(2953) }, // 37.3, 126.6 x 37.51, 126.8
    { 2530175, 1508 }, // 37.3, 126.8 x 37.51, 127
    { 2530260, 1494 }, // 37.09, 127 x 37.3, 127.2
    { 2530261, 1730 }, // 37.3, 127 x 37.51, 127.2
    { 2530814, 2189 }, // 43.8, 125.1 x 44.01, 125.3
    { 2530856, Bucket(2957) }, // 37.51, 126.6 x 37.72, 126.8
    { 2530858, Bucket(2961) }, // 37.51, 126.8 x 37.72, 127
    { 2530944, Bucket(2965) }, // 37.51, 127 x 37.72, 127.2
    { 2535633, 1529 }, // 33.52, 130.4 x 33.73, 130.6
    { 2535638, 2545 }, // 33.73, 130.6 x 33.94, 130.8
    { 2536030, Bucket(2969) }, // 33.73, 132.7 x 33.94, 132.9
    { 2536195, 1528 }, // 34.36, 132.3 x 34.57, 132.5
    { 2536201, 1528 }, // 34.36, 132.5 x 34.57, 132.7
    { 2536364, Bucket(2973) }, // 34.57, 135 x 34.78, 135.2
    { 2537732, Bucket(2977) }, // 34.57, 135.4 x 34.78, 135.6
    { 2537735, 1840 }, // 34.78, 135.6 x 34.99, 135.8
    { 2537746, Bucket(2985) }, // 34.99, 135.6 x 35.2, 135.8
    { 2537786, 1843 }, // 34.99, 136.9 x 35.2, 137.1
    { 2538267, 2070 }, // 35.2, 139.4 x 35.41, 139.6
    { 2538292, Bucket(2989) }, // 35.41, 139.6 x 35.62, 139.8
    { 2538293, Bucket(2992) }, // 35.62, 139.6 x 35.83, 139.8
    { 2538314, 2049 }, // 35.83, 139.4 x 36.04, 139.6
    { 2538336, 2049 }, // 35.83, 139.6 x 36.04, 139.8
    { 2539149, 1560 }, // 38.14, 140.9 x 38.35, 141.1
    { 2539492, 1810 }, // 42.96, 141.3 x 43.17, 141.5
    { 2643426, Bucket(3000) }, // -37.99, 144.8 x -37.78, 145.1
    { 2689231, Bucket(3006) }, // -34.01, 151.1 x -33.8, 151.4
    { 2690638, 2362 }, // -27.5, 152.8 x -27.3, 153
    { 2690660, 2362 }, // -27.5, 153 x -27.3, 153.2
    { 1042715, 858 }, // 6.154, -75.67 x 6.259, -75.56
    { 1620607, Bucket(3009) }, // 25.66, -100.4 x 25.76, -100.3
    { 1620693, Bucket(3009) }, // 25.66, -100.3 x 25.76, -100.2
    { 1626582, 1981 }, // 40.65, -111.9 x 40.76, -111.8
    { 1634715, 1972 }, // 39.71, -105 x 39.81, -104.9
    { 1639162, 167 }, // 45.48, -123.1 x 45.58, -123
    { 1640536, Bucket(3013) }, // 45.48, -122.7 x 45.58, -122.6
    { 1718167, Bucket(3017) }, // 29.85, -90.14 x 29.96, -90.03
    { 1718210, Bucket(3020) }, // 29.96, -90.14 x 30.06, -90.03
    { 1735915, 764 }, // 41.81, -87.83 x 41.91, -87.73
    { 1735916, 1934 }, // 41.91, -87.94 x 42.02, -87.83
    { 1736257, 764 }, // 41.81, -87.73 x 41.91, -87.62
    { 1736261, 737 }, // 42.02, -87.73 x 42.12, -87.62
    { 1753594, Bucket(3023) }, // 33.73, -84.47 x 33.84, -84.37
    { 1753936, 1080 }, // 33.73, -84.37 x 33.84, -84.27
    { 1756742, 2550 }, // 35.2, -80.91 x 35.3, -80.8
    { 1761263, 192 }, // 43.69, -79.44 x 43.8, -79.34
    { 1766103, 2290 }, // 39.08, -76.72 x 39.18, -76.61
    { 1766693, 2492 }, // 42.85, -78.92 x 42.96, -78.81
    { 1766725, 193 }, // 43.69, -79.34 x 43.8, -79.23
    { 1767743, Bucket(3026) }, // 39.92, -75.25 x 40.02, -75.14
    { 1767786, Bucket(3034) }, // 40.02, -75.25 x 40.13, -75.14
    { 1767829, Bucket(3038) }, // 39.92, -75.14 x 40.02, -75.04
    { 1767872, 447 }, // 40.02, -75.14 x 40.13, -75.04
    { 1768305, 1715 }, // 40.55, -73.88 x 40.65, -73.78
    { 1813112, 912 }, // 45.48, -73.67 x 45.58, -73.57
    { 2372011, 2940 }, // -27.82, -64.34 x -27.71, -64.24
    { 2392191, Bucket(3041) }, // -34.74, -58.47 x -34.64, -58.37
    { 2392362, Bucket(3044) }, // -34.64, -58.47 x -34.53, -58.37
    { 2408299, Bucket(3047) }, // -23.63, -46.73 x -23.52, -46.62
    { 2408345, 1450 }, // -24.04, -46.41 x -23.94, -46.31
    { 2408385, 1000 }, // -23.63, -46.62 x -23.52, -46.52
    { 2442711, 1579 }, // 10.56, -71.68 x 10.66, -71.58
    { 2496469, Bucket(3050) }, // -23, -43.27 x -22.89, -43.16
    { 2507278, 2284 }, // -22.68, -43.79 x -22.58, -43.69
    { 2507300, 2284 }, // -22.68, -43.69 x -22.58, -43.58
    { 2557665, 2413 }, // -5.17, -42.85 x -5.065, -42.74
    { 3167481, 2489 }, // 42.23, -71.16 x 42.33, -71.05
    { 3167484, 2491 }, // 42.33, -71.16 x 42.44, -71.05
    { 3697502, 1206 }, // 33.94, -6.88 x 34.05, -6.775
    { 3699431, Bucket(3053) }, // 38.66, -9.187 x 38.77, -9.082
    { 3699442, 1584 }, // 38.77, -9.187 x 38.87, -9.082
    { 3723759, 1666 }, // 40.34, -3.944 x 40.44, -3.839
    { 3723780, 1786 }, // 37.72, -3.839 x 37.82, -3.734
    { 3724101, Bucket(3059) }, // 40.34, -3.839 x 40.44, -3.734
    { 3724103, Bucket(3062) }, // 40.34, -3.734 x 40.44, -3.63
    { 3724112, 1665 }, // 40.44, -3.839 x 40.55, -3.734
    { 3724114, Bucket(3065) }, // 40.44, -3.734 x 40.55, -3.63
    { 3725204, 1985 }, // 43.17, -3 x 43.27, -2.896
    { 3725248, 1436 }, // 43.38, -3 x 43.48, -2.896
    { 3725458, 1747 }, // 37.93, -1.218 x 38.03, -1.113
    { 3725546, 236 }, // 38.35, -0.5886 x 38.45, -0.4838
    { 3725888, Bucket(3068) }, // 38.35, -0.4838 x 38.45, -0.3789
    { 3726086, Bucket(3071) }, // 39.39, -0.3789 x 39.5, -0.2741
    { 3726495, 383 }, // 41.6, -1.008 x 41.7, -0.9032
    { 3726517, 383 }, // 41.6, -0.9032 x 41.7, -0.7984
    { 3727022, 1268 }, // 41.07, 1.089 x 41.18, 1.194
    { 3732484, 1268 }, // 41.07, 1.194 x 41.18, 1.299
    { 3732624, 1288 }, // 41.28, 2.033 x 41.39, 2.138
    { 3732627, Bucket(3074) }, // 41.39, 2.138 x 41.49, 2.243
    { 3734847, 219 }, // 43.27, 5.283 x 43.38, 5.388
    { 3734873, 2317 }, // 43.9, 4.759 x 44.01, 4.864
    { 3734933, Bucket(3080) }, // 43.27, 5.388 x 43.38, 5.493
    { 3770738, 616 }, // 47.15, -1.637 x 47.26, -1.532
    { 3771949, Bucket(3083) }, // 47.89, 0.1454 x 47.99, 0.2502
    { 3771960, Bucket(3083) }, // 47.99, 0.1454 x 48.1, 0.2502
    { 3771991, Bucket(3086) }, // 49.15, -0.3789 x 49.25, -0.2741
    { 3772198, 989 }, // 49.46, 0.0405 x 49.57, 0.1454
    { 3773416, Bucket(3089) }, // 53.45, -2.371 x 53.55, -2.266
    { 3773663, 1356 }, // 55.86, -4.364 x 55.96, -4.259
    { 3774784, Bucket(3092) }, // 53.45, -2.162 x 53.55, -2.057
    { 3775003, Bucket(3096) }, // 51.45, -0.1692 x 51.56, -0.06436
    { 3775025, Bucket(3099) }, // 51.45, -0.06436 x 51.56, 0.0405
    { 3777261, Bucket(3102) }, // 45.37, 4.34 x 45.48, 4.445
    { 3777272, 314 }, // 45.48, 4.34 x 45.58, 4.445
    { 3777743, 2889 }, // 48.73, 2.347 x 48.83, 2.452
    { 3777754, Bucket(3106) }, // 48.83, 2.347 x 48.94, 2.452
    { 3778551, 1962 }, // 50.82, 4.235 x 50.93, 4.34
    { 3778557, 1800 }, // 50.82, 4.34 x 50.93, 4.445
    { 3778652, 1007 }, // 45.69, 4.759 x 45.79, 4.864
    { 3778654, 750 }, // 45.69, 4.864 x 45.79, 4.969
    { 3778763, 1034 }, // 45.16, 5.703 x 45.27, 5.808
    { 3778990, Bucket(3110) }, // 46.11, 6.122 x 46.21, 6.227
    { 3779255, 296 }, // 44.95, 7.59 x 45.06, 7.695
    { 3779298, 296 }, // 45.06, 7.59 x 45.16, 7.695
    { 3779531, Bucket(3113) }, // 46.84, 7.381 x 46.94, 7.485
    { 3779534, Bucket(3113) }, // 46.94, 7.381 x 47.05, 7.485
    { 3779822, 596 }, // 48.62, 6.122 x 48.73, 6.227
    { 3780233, Bucket(3116) }, // 47.68, 7.276 x 47.78, 7.381
    { 3780271, Bucket(3119) }, // 47.89, 7.8 x 47.99, 7.905
    { 3780282, Bucket(3122) }, // 47.99, 7.8 x 48.1, 7.905
    { 3780329, Bucket(3126) }, // 48.52, 7.695 x 48.62, 7.8
    { 3780564, 93 }, // 50.72, 7.066 x 50.82, 7.171
    { 3781350, 1339 }, // 51.98, 4.235 x 52.08, 4.34
    { 3781355, Bucket(3130) }, // 51.87, 4.445 x 51.98, 4.549
    { 3782721, Bucket(3135) }, // 51.87, 4.549 x 51.98, 4.654
    { 3782747, Bucket(3139) }, // 52.29, 4.864 x 52.4, 4.969
    { 3783208, Bucket(3145) }, // 50.93, 6.856 x 51.03, 6.961
    { 3783323, Bucket(3148) }, // 51.45, 7.381 x 51.56, 7.485
    { 3819363, Bucket(3153) }, // 36.77, 10.11 x 36.88, 10.21
    { 3821962, 1194 }, // 39.18, 9.058 x 39.29, 9.163
    { 3823599, Bucket(3157) }, // 43.69, 11.16 x 43.8, 11.26
    { 3823610, Bucket(3157) }, // 43.8, 11.16 x 43.9, 11.26
    { 3824155, Bucket(3160) }, // 38.03, 13.25 x 38.14, 13.36
    { 3824177, 1258 }, // 38.03, 13.36 x 38.14, 13.46
    { 3824629, Bucket(3163) }, // 40.76, 14.2 x 40.86, 14.3
    { 3824843, 626 }, // 41.81, 12.41 x 41.91, 12.52
    { 3824846, 624 }, // 41.91, 12.41 x 42.02, 12.52
    { 3824865, 632 }, // 41.81, 12.52 x 41.91, 12.62
    { 3825312, 2871 }, // 40.86, 14.2 x 40.97, 14.3
    { 3854843, Bucket(3166) }, // 40.55, 22.9 x 40.65, 23
    { 3854893, 1391 }, // 37.82, 23.63 x 37.93, 23.74
    { 3854904, 1391 }, // 37.93, 23.63 x 38.03, 23.74
    { 3863355, Bucket(3169) }, // 39.71, 30.45 x 39.81, 30.55
    { 3863441, Bucket(3173) }, // 39.71, 30.55 x 39.81, 30.66
    { 3863595, Bucket(3176) }, // 40.97, 28.77 x 41.07, 28.88
    { 3863681, 1552 }, // 40.97, 28.88 x 41.07, 28.98
    { 3863686, 1554 }, // 41.07, 28.98 x 41.18, 29.09
    { 3866975, 1906 }, // 47.47, 8.219 x 47.57, 8.324
    { 3867003, 1915 }, // 47.26, 8.639 x 47.36, 8.744
    { 3867004, 801 }, // 47.36, 8.534 x 47.47, 8.639
    { 3867007, 1930 }, // 47.47, 8.639 x 47.57, 8.744
    { 3867096, 1889 }, // 47.15, 8.953 x 47.26, 9.058
    { 3867097, 1889 }, // 47.26, 8.953 x 47.36, 9.058
    { 3867100, 1889 }, // 47.36, 8.953 x 47.47, 9.058
    { 3867103, 987 }, // 47.47, 9.058 x 47.57, 9.163
    { 3867256, 799 }, // 45.48, 10.21 x 45.58, 10.32
    { 3867658, 1906 }, // 47.57, 8.219 x 47.68, 8.324
    { 3867690, 1930 }, // 47.57, 8.639 x 47.68, 8.744
    { 3867761, 20 }, // 48.94, 8.324 x 49.04, 8.429
    { 3867763, 27 }, // 48.94, 8.429 x 49.04, 8.534
    { 3867772, 1071 }, // 49.04, 8.534 x 49.15, 8.639
    { 3867775, 396 }, // 49.15, 8.639 x 49.25, 8.744
    { 3867855, Bucket(3179) }, // 48.73, 9.058 x 48.83, 9.163
    { 3867865, 691 }, // 48.94, 8.953 x 49.04, 9.058
    { 3867866, 159 }, // 48.83, 9.058 x 48.94, 9.163
    { 3867877, Bucket(3183) }, // 48.73, 9.163 x 48.83, 9.268
    { 3867888, Bucket(3190) }, // 48.83, 9.163 x 48.94, 9.268
    { 3867890, 159 }, // 48.83, 9.268 x 48.94, 9.373
    { 3867896, 159 }, // 48.83, 9.373 x 48.94, 9.478
    { 3867935, 943 }, // 49.98, 8.219 x 50.09, 8.324
    { 3867942, 736 }, // 49.46, 8.429 x 49.57, 8.534
    { 3867947, Bucket(3194) }, // 49.36, 8.639 x 49.46, 8.744
    { 3868010, Bucket(3197) }, // 50.09, 8.639 x 50.19, 8.744
    { 3868053, 943 }, // 49.98, 8.744 x 50.09, 8.849
    { 3868096, Bucket(3200) }, // 50.09, 8.744 x 50.19, 8.849
    { 3868191, 1445 }, // 48.31, 9.897 x 48.41, 10
    { 3868234, 1445 }, // 48.41, 9.897 x 48.52, 10
    { 3868319, 321 }, // 48.31, 10.74 x 48.41, 10.84
    { 3868341, Bucket(3204) }, // 48.31, 10.84 x 48.41, 10.95
    { 3868585, 134 }, // 49.36, 11.05 x 49.46, 11.16
    { 3868631, 292 }, // 50.82, 10.53 x 50.93, 10.63
    { 3869010, 189 }, // 47.15, 11.37 x 47.26, 11.47
    { 3869721, Bucket(3211) }, // 48.1, 11.47 x 48.2, 11.57
    { 3869781, 185 }, // 49.15, 11.26 x 49.25, 11.37
    { 3869824, 2533 }, // 47.57, 12.1 x 47.68, 12.2
    { 3869871, 1866 }, // 47.89, 12.83 x 47.99, 12.94
    { 3869882, 1866 }, // 47.99, 12.83 x 48.1, 12.94
    { 3870079, Bucket(3215) }, // 50.82, 11.99 x 50.93, 12.1
    { 3870165, 187 }, // 50.82, 12.1 x 50.93, 12.2
    { 3870171, 1229 }, // 50.61, 12.41 x 50.72, 12.52
    { 3870174, 1229 }, // 50.72, 12.41 x 50.82, 12.52
    { 3870653, Bucket(3218) }, // 49.98, 14.41 x 50.09, 14.51
    { 3870696, Bucket(3218) }, // 50.09, 14.41 x 50.19, 14.51
    { 3870822, 607 }, // 51.98, 8.429 x 52.08, 8.534
    { 3870828, 607 }, // 51.98, 8.534 x 52.08, 8.639
    { 3871034, 334 }, // 53.03, 8.639 x 53.13, 8.744
    { 3871120, Bucket(3221) }, // 53.03, 8.744 x 53.13, 8.849
    { 3871315, Bucket(3224) }, // 52.29, 9.687 x 52.4, 9.792
    { 3871387, Bucket(3227) }, // 51.45, 10.74 x 51.56, 10.84
    { 3871394, Bucket(3230) }, // 50.93, 10.95 x 51.03, 11.05
    { 3872825, Bucket(3234) }, // 51.45, 11.89 x 51.56, 11.99
    { 3872847, Bucket(3238) }, // 52.08, 11.57 x 52.19, 11.68
    { 3872962, 1066 }, // 51.77, 12.2 x 51.87, 12.31
    { 3873091, 117 }, // 53.55, 11.37 x 53.65, 11.47
    { 3873150, Bucket(3243) }, // 54.07, 11.99 x 54.18, 12.1
    { 3873236, Bucket(3246) }, // 54.07, 12.1 x 54.18, 12.2
    { 3873323, Bucket(3250) }, // 51.03, 13.67 x 51.14, 13.78
    { 3873397, Bucket(3253) }, // 52.5, 13.36 x 52.61, 13.46
    { 3873406, 650 }, // 52.4, 13.67 x 52.5, 13.78
    { 3873463, 509 }, // 51.66, 14.3 x 51.77, 14.41
    { 3873493, 183 }, // 52.5, 13.78 x 52.61, 13.88
    { 3873727, Bucket(3257) }, // 53.34, 14.51 x 53.45, 14.62
    { 3873770, Bucket(3261) }, // 53.45, 14.51 x 53.55, 14.62
    { 3874011, 288 }, // 55.65, 12.41 x 55.75, 12.52
    { 3874033, Bucket(3264) }, // 55.65, 12.52 x 55.75, 12.62
    { 3875183, Bucket(3268) }, // 47.05, 15.35 x 47.15, 15.45
    { 3875269, Bucket(3272) }, // 47.05, 15.45 x 47.15, 15.56
    { 3877341, Bucket(3275) }, // 47.47, 19.02 x 47.57, 19.12
    { 3877342, 521 }, // 47.36, 19.12 x 47.47, 19.23
    { 3877435, Bucket(3282) }, // 44.74, 20.38 x 44.85, 20.49
    { 3877521, Bucket(3290) }, // 44.74, 20.49 x 44.85, 20.59
    { 3877669, Bucket(3297) }, // 46.21, 20.07 x 46.31, 20.17
    { 3878024, Bucket(3303) }, // 47.57, 19.02 x 47.68, 19.12
    { 3878638, 1812 }, // 48.62, 21.22 x 48.73, 21.33
    { 3879189, Bucket(3306) }, // 53.34, 14.62 x 53.45, 14.72
    { 3881149, 2097 }, // 51.66, 19.44 x 51.77, 19.54
    { 3881192, 2097 }, // 51.77, 19.44 x 51.87, 19.54
    { 3885096, 662 }, // 57.64, 11.89 x 57.74, 11.99
    { 3892138, Bucket(3310) }, // 59.32, 17.87 x 59.42, 17.97
    { 3893504, Bucket(3314) }, // 59.32, 17.97 x 59.42, 18.08
    { 3899751, 958 }, // 47.05, 21.85 x 47.15, 21.96
    { 3901331, 614 }, // 49.78, 23.95 x 49.88, 24.05
    { 3902415, Bucket(3317) }, // 47.05, 27.51 x 47.15, 27.62
    { 3902426, Bucket(3322) }, // 47.15, 27.51 x 47.26, 27.62
    { 3909573, 1056 }, // 50.4, 30.55 x 50.51, 30.66
    { 3909584, 1056 }, // 50.51, 30.55 x 50.61, 30.66
    { 3911183, 2375 }, // 47.89, 33.39 x 47.99, 33.49
    { 3913290, Bucket(3328) }, // 55.12, 30.03 x 55.23, 30.13
    { 3913312, Bucket(3328) }, // 55.12, 30.13 x 55.23, 30.24
    { 3917370, 2896 }, // 61.41, 23.74 x 61.52, 23.84
    { 3917456, 2896 }, // 61.41, 23.84 x 61.52, 23.95
    { 3918109, Bucket(3331) }, // 60.05, 24.89 x 60.16, 25
    { 3918152, Bucket(3334) }, // 60.16, 24.89 x 60.26, 25
    { 9276245, 2438 }, // -6.219, 106.9 x -6.114, 107
    { 9467626, Bucket(3343) }, // 41.7, 44.71 x 41.81, 44.81
    { 9468949, 1620 }, // 41.6, 44.81 x 41.7, 44.92
    { 9468992, 1620 }, // 41.7, 44.81 x 41.81, 44.92
    { 9474799, 2345 }, // 25.24, 51.42 x 25.34, 51.53
    { 9476165, 2365 }, // 25.24, 51.53 x 25.34, 51.63
    { 9490927, Bucket(3346) }, // 40.34, 49.74 x 40.44, 49.85
    { 9503693, Bucket(3350) }, // 47.05, 37.47 x 47.15, 37.58
    { 9503695, 2451 }, // 47.05, 37.58 x 47.15, 37.68
    { 9516847, 1514 }, // 56.28, 43.87 x 56.38, 43.98
    { 9551720, 1574 }, // 56.8, 60.54 x 56.91, 60.65
    { 9578890, 1525 }, // 19.05, 72.81 x 19.16, 72.92
    { 9579923, 2072 }, // 22.93, 72.6 x 23.04, 72.71
    { 9598098, 703 }, // 41.28, 69.25 x 41.39, 69.35
    { 9603074, 1892 }, // 17.37, 78.47 x 17.48, 78.58
    { 9680031, 1573 }, // 55.02, 82.88 x 55.12, 82.98
    { 9997350, 2636 }, // 20.94, 105.7 x 21.04, 105.8
    { 10000245, 2400 }, // 30.69, 104 x 30.8, 104.1
    { 10005755, 2364 }, // 22.09, 113.5 x 22.2, 113.6
    { 10005942, 1542 }, // 23.04, 113.3 x 23.14, 113.4
    { 10006111, Bucket(3353) }, // 22.3, 113.9 x 22.41, 114
    { 10006134, 1403 }, // 22.2, 114.1 x 22.3, 114.2
    { 10006277, 2170 }, // 22.72, 113.6 x 22.83, 113.7
    { 10006282, Bucket(3361) }, // 22.41, 113.9 x 22.51, 114
    { 10006283, 1548 }, // 22.51, 113.9 x 22.62, 114
    { 10006292, 1720 }, // 23.04, 113.6 x 23.14, 113.7
    { 10006304, 1367 }, // 22.41, 114 x 22.51, 114.1
    { 10019167, 1673 }, // 34.05, 108.9 x 34.15, 109
    { 10064479, 802 }, // 52.5, 103.8 x 52.61, 104
    { 10096388, 1698 }, // 22.62, 120.3 x 22.72, 120.4
    { 10099404, 1219 }, // 25.13, 121.4 x 25.24, 121.5
    { 10110743, 2402 }, // 36.56, 117.1 x 36.67, 117.2
    { 10110786, 2402 }, // 36.67, 117.1 x 36.77, 117.2
    { 10111157, 2316 }, // 31.53, 119.9 x 31.63, 120
    { 10111167, 1651 }, // 31.53, 120.2 x 31.63, 120.3
    { 10111204, 2316 }, // 31.84, 119.9 x 31.95, 120
    { 10111630, 1870 }, // 31.01, 121.5 x 31.11, 121.6
    { 10121045, 1508 }, // 37.4, 127 x 37.51, 127.1
    { 10123259, 2190 }, // 43.9, 125.2 x 44.01, 125.3
    { 10123358, 1596 }, // 38.97, 125.7 x 39.08, 125.8
    { 10123776, 1508 }, // 37.51, 127 x 37.61, 127.1
    { 10123780, 1493 }, // 37.72, 127 x 37.82, 127.1
    { 10124624, 2189 }, // 43.8, 125.3 x 43.9, 125.5
    { 10124625, 2190 }, // 43.9, 125.3 x 44.01, 125.5
    { 10142190, Bucket(3373) }, // 33.52, 130.3 x 33.63, 130.4
    { 10142231, Bucket(3376) }, // 31.53, 130.5 x 31.63, 130.6
    { 10142532, Bucket(3373) }, // 33.52, 130.4 x 33.63, 130.5
    { 10142976, Bucket(2273) }, // 35.83, 128.7 x 35.93, 128.8
    { 10145466, 2112 }, // 34.57, 135.3 x 34.68, 135.4
    { 10150928, 2112 }, // 34.57, 135.4 x 34.68, 135.5
    { 10150943, 1839 }, // 34.89, 135.7 x 34.99, 135.8
    { 10150986, 1839 }, // 34.99, 135.7 x 35.1, 135.8
    { 10151145, 1845 }, // 35.1, 136.9 x 35.2, 137
    { 10151147, 2188 }, // 35.1, 137 x 35.2, 137.1
    { 10153083, 1563 }, // 35.51, 139.5 x 35.62, 139.6
    { 10153157, 576 }, // 35.3, 139.6 x 35.41, 139.7
    { 10153168, 1533 }, // 35.41, 139.6 x 35.51, 139.7
    { 10153172, 575 }, // 35.62, 139.6 x 35.72, 139.7
    { 10153175, 2028 }, // 35.72, 139.7 x 35.83, 139.8
    { 10153346, 2041 }, // 35.83, 139.7 x 35.93, 139.8
    { 10157968, 1998 }, // 42.96, 141.3 x 43.06, 141.4
    { 10168542, 1771 }, // 45.69, 126.5 x 45.79, 126.6
    { 10573707, Bucket(3379) }, // -37.89, 145 x -37.78, 145.1
    { 4170863, 1369 }, // 6.207, -75.61 x 6.259, -75.56
    { 4170949, 1369 }, // 6.207, -75.56 x 6.259, -75.51
    { 6381721, Bucket(3383) }, // 37.77, -122.4 x 37.82, -122.4
    { 6382490, 2026 }, // 38.56, -121.5 x 38.61, -121.5
    { 6393016, 2267 }, // 32.68, -117.2 x 32.74, -117.1
    { 6461986, 1405 }, // 20.73, -103.4 x 20.78, -103.3
    { 6563313, 2304 }, // 47.42, -122.3 x 47.47, -122.3
    { 6872671, 2865 }, // 29.9, -90.08 x 29.96, -90.03
    { 6872842, 2865 }, // 29.96, -90.08 x 30.01, -90.03
    { 6884885, Bucket(3388) }, // 32.84, -96.95 x 32.89, -96.9
    { 6884889, 1345 }, // 32.74, -96.85 x 32.79, -96.8
    { 6918343, Bucket(3391) }, // 34.73, -92.29 x 34.78, -92.23
    { 6943678, 737 }, // 42.02, -87.78 x 42.07, -87.73
    { 6944481, 2862 }, // 43.01, -87.94 x 43.06, -87.88
    { 6975585, 2861 }, // 27.91, -82.48 x 27.96, -82.43
    { 7029750, 1050 }, // 39.08, -84.53 x 39.13, -84.47
    { 7071146, 1775 }, // 40.02, -75.19 x 40.08, -75.14
    { 7073139, 1766 }, // 40.7, -74.04 x 40.76, -73.99
    { 7073144, 1716 }, // 40.65, -73.99 x 40.7, -73.94
    { 7252456, 910 }, // 45.48, -73.57 x 45.53, -73.52
    { 9568767, 866 }, // -34.69, -58.42 x -34.64, -58.37
    { 9569450, Bucket(3394) }, // -34.64, -58.42 x -34.58, -58.37
    { 9985879, Bucket(3397) }, // -22.94, -43.21 x -22.89, -43.16
    { 10084346, 2893 }, // -9.679, -35.77 x -9.627, -35.72
    { 10239102, Bucket(3401) }, // -3.702, -40.38 x -3.65, -40.33
    { 14703373, 400 }, // 28.44, -16.32 x 28.49, -16.26
    { 14882592, 1615 }, // 36.67, -4.468 x 36.72, -4.416
    { 14896391, 1785 }, // 40.18, -3.787 x 40.23, -3.734
    { 14896402, 1785 }, // 40.23, -3.787 x 40.29, -3.734
    { 14902186, Bucket(3404) }, // 38.35, -0.5362 x 38.4, -0.4838
    { 14903552, 235 }, // 38.35, -0.4838 x 38.4, -0.4314
    { 14933786, 1048 }, // 43.59, 3.868 x 43.64, 3.92
    { 14939390, Bucket(3407) }, // 43.27, 5.336 x 43.33, 5.388
    { 14939732, 697 }, // 43.27, 5.388 x 43.33, 5.441
    { 14941982, 2331 }, // 43.69, 7.223 x 43.75, 7.276
    { 14942004, 2331 }, // 43.69, 7.276 x 43.75, 7.328
    { 15087964, 2248 }, // 49.15, -0.3789 x 49.2, -0.3265
    { 15094740, 1356 }, // 55.86, -4.259 x 55.91, -4.206
    { 15111020, 1414 }, // 48.94, 2.347 x 48.99, 2.4
    { 15111117, 1431 }, // 48.99, 2.557 x 49.04, 2.61
    { 15118138, 2061 }, // 46.94, 7.433 x 47, 7.485
    { 15121911, 87 }, // 50.88, 6.909 x 50.93, 6.961
    { 15125171, 955 }, // 51.19, 4.392 x 51.24, 4.445
    { 15296623, 1260 }, // 38.08, 13.3 x 38.14, 13.36
    { 15298431, 2543 }, // 40.81, 14.14 x 40.86, 14.2
    { 15298519, 2883 }, // 40.81, 14.25 x 40.86, 14.3
    { 15299375, Bucket(3410) }, // 41.86, 12.47 x 41.91, 12.52
    { 15299461, Bucket(3410) }, // 41.86, 12.52 x 41.91, 12.57
    { 15301250, 2883 }, // 40.86, 14.25 x 40.91, 14.3
    { 15435807, 1471 }, // 31.16, 29.87 x 31.22, 29.92
    { 15435850, 1471 }, // 31.22, 29.87 x 31.27, 29.92
    { 15467994, 813 }, // 47.36, 8.482 x 47.42, 8.534
    { 15468016, 813 }, // 47.36, 8.534 x 47.42, 8.586
    { 15468392, 1889 }, // 47.15, 9.058 x 47.21, 9.111
    { 15468395, 987 }, // 47.21, 9.111 x 47.26, 9.163
    { 15468398, 987 }, // 47.26, 9.111 x 47.31, 9.163
    { 15468399, 987 }, // 47.31, 9.111 x 47.36, 9.163
    { 15468410, 987 }, // 47.36, 9.111 x 47.42, 9.163
    { 15468411, 987 }, // 47.42, 9.111 x 47.47, 9.163
    { 15471047, 1290 }, // 48.99, 8.377 x 49.04, 8.429
    { 15471096, 1071 }, // 49.04, 8.639 x 49.09, 8.691
    { 15471099, 396 }, // 49.09, 8.691 x 49.15, 8.744
    { 15471469, 691 }, // 48.99, 9.058 x 49.04, 9.111
    { 15471471, 691 }, // 48.99, 9.111 x 49.04, 9.163
    { 15471508, 47 }, // 48.73, 9.163 x 48.78, 9.216
    { 15471556, 159 }, // 48.94, 9.163 x 48.99, 9.216
    { 15471557, 691 }, // 48.99, 9.163 x 49.04, 9.216
    { 15471558, 159 }, // 48.94, 9.216 x 48.99, 9.268
    { 15471559, 691 }, // 48.99, 9.216 x 49.04, 9.268
    { 15471564, 159 }, // 48.94, 9.268 x 48.99, 9.32
    { 15471565, 691 }, // 48.99, 9.268 x 49.04, 9.32
    { 15471566, 159 }, // 48.94, 9.32 x 48.99, 9.373
    { 15471567, 691 }, // 48.99, 9.32 x 49.04, 9.373
    { 15471588, 159 }, // 48.94, 9.373 x 48.99, 9.425
    { 15471589, 691 }, // 48.99, 9.373 x 49.04, 9.425
    { 15471591, 691 }, // 48.99, 9.425 x 49.04, 9.478
    { 15471597, 691 }, // 48.99, 9.478 x 49.04, 9.53
    { 15471840, 468 }, // 49.67, 8.534 x 49.72, 8.586
    { 15472767, 1446 }, // 48.36, 9.95 x 48.41, 10
    { 15472853, 1446 }, // 48.36, 10 x 48.41, 10.05
    { 15472938, 1446 }, // 48.41, 9.95 x 48.46, 10
    { 15473024, 1446 }, // 48.41, 10 x 48.46, 10.05
    { 15474341, 1920 }, // 49.41, 11.05 x 49.46, 11.1
    { 15476044, 1040 }, // 47.26, 11.37 x 47.31, 11.42
    { 15478893, 157 }, // 48.15, 11.57 x 48.2, 11.63
    { 15491639, 128 }, // 51.3, 12.36 x 51.35, 12.41
    { 15491682, 128 }, // 51.35, 12.36 x 51.4, 12.41
    { 15492602, 56 }, // 54.07, 12.05 x 54.13, 12.1
    { 15493636, Bucket(3413) }, // 51.03, 13.78 x 51.09, 13.83
    { 15493853, Bucket(3416) }, // 51.72, 14.3 x 51.77, 14.35
    { 15494024, Bucket(3420) }, // 51.77, 14.3 x 51.82, 14.35
    { 15494909, 595 }, // 53.39, 14.51 x 53.45, 14.56
    { 15495080, 595 }, // 53.45, 14.51 x 53.5, 14.56
    { 15500734, 330 }, // 47.05, 15.4 x 47.1, 15.45
    { 15501076, Bucket(3423) }, // 47.05, 15.45 x 47.1, 15.51
    { 15509342, Bucket(3427) }, // 47.47, 18.97 x 47.52, 19.02
    { 15509364, Bucket(3431) }, // 47.47, 19.02 x 47.52, 19.07
    { 15509369, 523 }, // 47.42, 19.12 x 47.47, 19.18
    { 15509743, 759 }, // 44.79, 20.44 x 44.85, 20.49
    { 15514553, 2034 }, // 48.67, 21.22 x 48.73, 21.27
    { 15516928, 601 }, // 53.45, 14.62 x 53.5, 14.67
    { 15518170, 1381 }, // 52.4, 16.87 x 52.45, 16.92
    { 15524597, Bucket(3436) }, // 51.72, 19.44 x 51.77, 19.49
    { 15524768, Bucket(3436) }, // 51.77, 19.44 x 51.82, 19.49
    { 15567871, Bucket(3439) }, // 59.26, 17.92 x 59.32, 17.97
    { 15568554, Bucket(3442) }, // 59.32, 17.92 x 59.37, 17.97
    { 15605327, 354 }, // 49.83, 24 x 49.88, 24.05
    { 15609792, Bucket(3445) }, // 47.15, 27.62 x 47.21, 27.67
    { 15626045, 2547 }, // 53.81, 27.51 x 53.86, 27.57
    { 15626088, 2547 }, // 53.86, 27.51 x 53.92, 27.57
    { 37870335, 1620 }, // 41.65, 44.76 x 41.7, 44.81
    { 37904660, 2345 }, // 25.24, 51.53 x 25.29, 51.58
    { 38014818, 2214 }, // 47.15, 37.53 x 47.21, 37.58
    { 38171119, 2932 }, // 55.7, 52.31 x 55.75, 52.36
    { 38206711, 1574 }, // 56.75, 60.6 x 56.8, 60.65
    { 38452911, 2531 }, // 22.56, 88.38 x 22.62, 88.44
    { 38723305, 467 }, // 56.43, 84.98 x 56.49, 85.03
    { 40024532, 356 }, // 22.3, 114 x 22.35, 114.1
    { 40024533, Bucket(3448) }, // 22.35, 114 x 22.41, 114.1
    { 40025216, Bucket(3448) }, // 22.41, 114 x 22.46, 114.1
    { 40044672, 2400 }, // 30.8, 104 x 30.85, 104
    { 40384186, 1698 }, // 22.62, 120.3 x 22.67, 120.3
    { 40444842, 1650 }, // 31.63, 120.3 x 31.69, 120.3
    { 40446208, 1650 }, // 31.63, 120.3 x 31.69, 120.4
    { 40571221, 1662 }, // 35.78, 128.7 x 35.83, 128.8
    { 40576486, 1202 }, // 33.84, 132.7 x 33.89, 132.8
    { 40581857, 1546 }, // 34.62, 135.2 x 34.68, 135.3
    { 40581860, 1546 }, // 34.68, 135.2 x 34.73, 135.3
    { 40581862, 1545 }, // 34.68, 135.3 x 34.73, 135.3
    { 40605957, 2188 }, // 35.15, 137.1 x 35.2, 137.1
    { 40612326, 2048 }, // 35.51, 139.4 x 35.57, 139.5
    { 40612676, 1563 }, // 35.51, 139.6 x 35.57, 139.7
    { 40612701, 2041 }, // 35.78, 139.7 x 35.83, 139.8
    { 40613410, 2066 }, // 35.83, 139.9 x 35.88, 139.9
    { 25933824, 1713 }, // 25.76, -100.3 x 25.79, -100.3
    { 26253071, 978 }, // 47.23, -122.5 x 47.26, -122.4
    { 26253093, 978 }, // 47.23, -122.4 x 47.26, -122.4
    { 27683990, 483 }, // 35.15, -90.01 x 35.17, -89.98
    { 28142893, 1933 }, // 42.2, -83.37 x 42.23, -83.35
    { 28285952, 1775 }, // 40.02, -75.14 x 40.05, -75.12
    { 59602602, 1436 }, // 43.38, -3.027 x 43.41, -3
    { 59613525, 2924 }, // 38.32, -0.4838 x 38.35, -0.4576
    { 59614208, 2924 }, // 38.35, -0.4838 x 38.37, -0.4576
    { 59722010, 1382 }, // 41.39, 2.111 x 41.41, 2.138
    { 59722038, 1145 }, // 41.44, 2.164 x 41.47, 2.19
    { 59758968, 1370 }, // 43.27, 5.546 x 43.3, 5.572
    { 60458445, 1009 }, // 45.76, 4.812 x 45.79, 4.838
    { 60469317, 2392 }, // 46.18, 6.227 x 46.21, 6.253
    { 60469695, 1114 }, // 46.5, 6.62 x 46.52, 6.647
    { 60469738, 1114 }, // 46.52, 6.62 x 46.55, 6.647
    { 60470037, 1114 }, // 46.5, 6.647 x 46.52, 6.673
    { 60470080, 1114 }, // 46.52, 6.647 x 46.55, 6.673
    { 60500687, 947 }, // 51.22, 4.418 x 51.24, 4.445
    { 60523536, 1285 }, // 51.87, 4.549 x 51.9, 4.576
    { 61197503, 632 }, // 41.88, 12.49 x 41.91, 12.52
    { 61743317, 1471 }, // 31.19, 29.92 x 31.22, 29.95
    { 61818977, 2069 }, // 41.1, 28.98 x 41.12, 29.01
    { 61873574, 987 }, // 47.21, 9.084 x 47.23, 9.111
    { 61873575, 987 }, // 47.23, 9.084 x 47.26, 9.111
    { 61873586, 987 }, // 47.26, 9.084 x 47.28, 9.111
    { 61873587, 987 }, // 47.28, 9.084 x 47.31, 9.111
    { 61873590, 987 }, // 47.31, 9.084 x 47.34, 9.111
    { 61873591, 987 }, // 47.34, 9.084 x 47.36, 9.111
    { 61873634, 987 }, // 47.36, 9.084 x 47.39, 9.111
    { 61873635, 987 }, // 47.39, 9.084 x 47.42, 9.111
    { 61873638, 987 }, // 47.42, 9.084 x 47.44, 9.111
    { 61873639, 987 }, // 47.44, 9.084 x 47.47, 9.111
    { 61879621, 461 }, // 47.44, 9.583 x 47.47, 9.609
    { 61884391, 396 }, // 49.12, 8.665 x 49.15, 8.691
    { 61884392, 1071 }, // 49.04, 8.691 x 49.07, 8.717
    { 61885691, 1632 }, // 48.75, 9.137 x 48.78, 9.163
    { 61885882, 159 }, // 48.94, 9.137 x 48.96, 9.163
    { 61886033, 1632 }, // 48.75, 9.163 x 48.78, 9.189
    { 61886360, 159 }, // 48.94, 9.425 x 48.96, 9.451
    { 61889536, 563 }, // 50.09, 8.744 x 50.12, 8.77
    { 61973999, 125 }, // 52.48, 13.33 x 52.5, 13.36
    { 62002938, 337 }, // 47.05, 15.43 x 47.08, 15.45
    { 62271487, 253 }, // 59.29, 17.94 x 59.32, 17.97
    { 151255697, 1016 }, // 29.25, 47.96 x 29.28, 47.99
    { 151860305, 1624 }, // 40.36, 49.85 x 40.39, 49.87
    { 162305944, 1201 }, // 33.84, 132.7 x 33.86, 132.8
    { 162324783, Bucket(3452) }, // 34.65, 133.9 x 34.68, 133.9
    { 162450911, 2066 }, // 35.8, 139.9 x 35.83, 139.9
    { 172124673, 2201 }, // -32.93, 151.8 x -32.91, 151.8
    { 103729834, 1713 }, // 25.76, -100.3 x 25.78, -100.3
    { 113170325, 280 }, // 40.74, -73.99 x 40.76, -73.98
    { 153713678, 1709 }, // -30, -51.2 x -29.98, -51.18
    { 153713700, 1709 }, // -30, -51.18 x -29.98, -51.17
    { 238342614, 1647 }, // 40.42, -3.721 x 40.43, -3.708
    { 239030251, 698 }, // 43.29, 5.375 x 43.3, 5.388
    { 247275642, 2942 }, // 41.02, 28.97 x 41.03, 28.98
    { 247275729, 2941 }, // 41.03, 28.98 x 41.05, 28.99
    { 247494288, 1889 }, // 47.21, 9.058 x 47.22, 9.071
    { 247494289, 1889 }, // 47.22, 9.058 x 47.23, 9.071
    { 247494292, 1889 }, // 47.23, 9.058 x 47.25, 9.071
    { 247494293, 1889 }, // 47.25, 9.058 x 47.26, 9.071
    { 247494294, 987 }, // 47.23, 9.071 x 47.25, 9.084
    { 247494295, 987 }, // 47.25, 9.071 x 47.26, 9.084
    { 247494336, 1889 }, // 47.26, 9.058 x 47.27, 9.071
    { 247494337, 1889 }, // 47.27, 9.058 x 47.28, 9.071
    { 247494338, 987 }, // 47.26, 9.071 x 47.27, 9.084
    { 247494339, 987 }, // 47.27, 9.071 x 47.28, 9.084
    { 247494340, 1889 }, // 47.28, 9.058 x 47.3, 9.071
    { 247494341, 1889 }, // 47.3, 9.058 x 47.31, 9.071
    { 247494342, 987 }, // 47.28, 9.071 x 47.3, 9.084
    { 247494343, 987 }, // 47.3, 9.071 x 47.31, 9.084
    { 247494352, 1889 }, // 47.31, 9.058 x 47.32, 9.071
    { 247494353, 1889 }, // 47.32, 9.058 x 47.34, 9.071
    { 247494354, 987 }, // 47.31, 9.071 x 47.32, 9.084
    { 247494355, 987 }, // 47.32, 9.071 x 47.34, 9.084
    { 247494356, 1889 }, // 47.34, 9.058 x 47.35, 9.071
    { 247494357, 1889 }, // 47.35, 9.058 x 47.36, 9.071
    { 247494358, 987 }, // 47.34, 9.071 x 47.35, 9.084
    { 247494359, 987 }, // 47.35, 9.071 x 47.36, 9.084
    { 247494528, 1889 }, // 47.36, 9.058 x 47.38, 9.071
    { 247494529, 1889 }, // 47.38, 9.058 x 47.39, 9.071
    { 247494530, 987 }, // 47.36, 9.071 x 47.38, 9.084
    { 247494531, 987 }, // 47.38, 9.071 x 47.39, 9.084
    { 247494532, 1889 }, // 47.39, 9.058 x 47.4, 9.071
    { 247494533, 1889 }, // 47.4, 9.058 x 47.42, 9.071
    { 247494534, 987 }, // 47.39, 9.071 x 47.4, 9.084
    { 247494535, 987 }, // 47.4, 9.071 x 47.42, 9.084
    { 247494544, 1889 }, // 47.42, 9.058 x 47.43, 9.071
    { 247494545, 1889 }, // 47.43, 9.058 x 47.44, 9.071
    { 247494546, 987 }, // 47.42, 9.071 x 47.43, 9.084
    { 247494547, 987 }, // 47.43, 9.071 x 47.44, 9.084
    { 247494548, 1889 }, // 47.44, 9.058 x 47.46, 9.071
    { 247494550, 987 }, // 47.44, 9.071 x 47.46, 9.084
    { 247494551, 987 }, // 47.46, 9.071 x 47.47, 9.084
    { 249755989, Bucket(3445) }, // 47.14, 27.62 x 47.15, 27.63
    { 606387153, 2411 }, // 25.3, 51.42 x 25.32, 51.43
    { 646361821, 2058 }, // 25.12, 121.5 x 25.13, 121.5
    { 646361992, 2058 }, // 25.13, 121.5 x 25.15, 121.5
    { 688497326, 2201 }, // -32.93, 151.8 x -32.92, 151.8
    { 625966141, 1745 }, // 10.5, -66.92 x 10.51, -66.92
    { 947054399, 457 }, // 38.71, -9.141 x 38.71, -9.135
    { 947054442, 457 }, // 38.71, -9.141 x 38.72, -9.135
    { 947054485, 457 }, // 38.71, -9.135 x 38.71, -9.128
    { 947054528, 457 }, // 38.71, -9.135 x 38.72, -9.128
    { 979168146, 718 }, // 41.83, 12.89 x 41.84, 12.9
    { 987895808, 1471 }, // 31.22, 29.92 x 31.22, 29.93
    { 989977167, 987 }, // 47.23, 9.078 x 47.23, 9.084
    { 990221653, 563 }, // 50.08, 8.744 x 50.09, 8.75
    { 990309034, 1434 }, // 48.41, 11.25 x 48.42, 11.26
    { 2596894943, 1201 }, // 33.83, 132.8 x 33.84, 132.8
    { 2598693247, 1544 }, // 35.19, 136.9 x 35.2, 136.9
    { 2598693930, 1544 }, // 35.2, 136.9 x 35.21, 136.9
    { 4294967295, Bucket(3455) }, // 339.5, 249.5 x 339.5, 249.5
};
}
