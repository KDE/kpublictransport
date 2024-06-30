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
    "RS2\0"
    "S11\0"
    "M13\0"
    "RS1\0"
    "M10\0"
    "TER 21\0"
    "U13\0"
    "S63\0"
    "S61\0"
    "S68\0"
    "TER 62\0"
    "IR37\0"
    "888\0"
    "S22\0"
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
    "RB49\0"
    "S52\0"
    "044\0"
    "S60\0"
    "LO\0"
    "U76\0"
    "U77\0"
    "709\0"
    "704\0"
    "707\0"
    "MSC 1708\0"
    "701\0"
    "706\0"
    "S3\0"
    "86967\0"
    "N27\0"
    "M17\0"
    "S50\0"
    "U79\0"
    "N20\0"
    "S24\0"
    "043\0"
    "38\0"
    "042\0"
    "041\0"
    "S40\0"
    "WLB\0"
    "RED\0"
    "TER T1\0"
    "RB 58\0"
    "S6\0"
    "S46\0"
    "665\0"
    "S71\0"
    "RS4\0"
    "D26\0"
    "S 1\0"
    "N17\0"
    "S25\0"
    "KJ\0"
    "3F\0"
    "S33\0"
    "S45\0"
    "RB23\0"
    "A3\0"
    "S51\0"
    "FM1\0"
    "MRT Blue\0"
    "Yellow\0"
    "Red\0"
    "501\0"
    "503\0"
    "86989\0"
    "RE 30\0"
    "RB 12\0"
    "FXC\0"
    "LS\0"
    "LSM\0"
    "LM\0"
    "LU\0"
    "614P\0"
    "86996\0"
    "86\0"
    "FM2\0"
    "RB 80\0"
    "RB 81\0"
    "RB 59\0"
    "Oyster Bay\0"
    "Atlantic City\0"
    "TL12\0"
    "TL11\0"
    "181 (SN)\0"
    "S85\0"
    "FL4\0"
    "FL1\0"
    "FL2\0"
    "FL3\0"
    "109\0"
    "657\0"
    "C7\0"
    "C-8\0"
    "24E\0"
    "North Jersey Coast\0"
    "RB 48\0"
    "417\0"
    "ATS\0"
    "SYK\0"
    "ISL\0"
    "TCL\0"
    "23R\0"
    "AEL\0"
    "EAL\0"
    "TML\0"
    "28E\0"
    "Belfast-Bangor\0"
    "Belfast-Larne\0"
    "S9\0"
    "Dark Green\0"
    "639\0"
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
    "RE3\0"
    "RB 56\0"
    "S47\0"
    "MSC 1908\0"
    "S13\0"
    "MD-W\0"
    "RE7\0"
    "D1\0"
    "D2\0"
    "D8\0"
    "N10\0"
    "GN4\0"
    "N1\0"
    "H5\0"
    "S64\0"
    "Raritan Valley\0"
    "DRL\0"
    "N82\0"
    "Harlem\0"
    "JVL\0"
    "MEL\0"
    "Hudson\0"
    "Port Jervis\0"
    "SFM A\0"
    "SFM 2\0"
    "308\0"
    "310\0"
    "306\0"
    "302\0"
    "301\0"
    "S 5\0"
    "New Haven\0"
    "VMLR\0"
    "Chengalpattu - Arakkonam\0"
    "H7\0"
    "5а\0"
    "New Main\0"
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
    "92\0"
    "93\0"
    "94\0"
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
    "69\0"
    "62A\0"
    "51A\0"
    "28A\0"
    "S28\0"
    "37A\0"
    "14А\0"
    "СТ\0"
    "2 Салтівська\0"
    "1 Холодногірсько-заводська\0"
    "3 Олексіївська\0"
    "12а\0"
    "SSL\0"
    "BEL\0"
    "S36\0"
    "107\0"
    "SFM3\0"
    "U75\0"
    "631\0"
    "86966\0"
    "금수산태양궁전궤도전차\0"
    "S2/S20\0"
    "Тр3\0"
    "T3\0"
    "Тр2\0"
    "Тр4\0"
    "FC1\0"
    "FC2\0"
    "FC3\0"
    "FL5\0"
    "FL6\0"
    "FL7\0"
    "FL8\0"
    "LEX\0"
    "655\0"
    "635\0"
    "TER 60\0"
    "86987\0"
    "T4\0"
    "T5\0"
    "901\0"
    "TT\0"
    "Μ3\0"
    "RE5\0"
    "RE4\0"
    "Тр1\0"
    "Тр9\0"
    "Тр6\0"
    "RE29\0"
    "7bis\0"
    "Brown\0"
    "Orange\0"
    "100\0"
    "Scala mobile\0"
    "S 8\0"
    "RB14\0"
    "S 4\0"
    "RE 18\0"
    "RE2\0"
    "RE 15\0"
    "RE1\0"
    "SFM 1\0"
    "SFM 4\0"
    "U44\0"
    "SFM7\0"
    "PAO\0"
    "Meadowlands\0"
    "Pascack Valley\0"
    "U46\0"
    "Metropolitana\0"
    "Pink\0"
    "U47\0"
    "U41\0"
    "U43\0"
    "MRT Purple\0"
    "4S\0"
    "TRE\0"
    "S18\0"
    "M-Line\0"
    "S 3\0"
    "STY\0"
    "T6\0"
    "T14\0"
    "S31\0"
    "CBTU\0"
    "DPM\0"
    "M95\0"
    "UP-N\0"
    "MD-N\0"
    "NCS\0"
    "UP-NW\0"
    "UP-W\0"
    "BNSF\0"
    "HC\0"
    "SWS\0"
    "ME\0"
    "S 2\0"
    "LBN\0"
    "C4\0"
    "T16\0"
    "KT\0"
    "RB55\0"
    "RB20\0"
    "S42\0"
    "S 5X\0"
    "RB13\0"
    "MTM\0"
    "C-5\0"
    "DPH\0"
    "LBS\0"
    "T7\0"
    "IC LSA<=>BRA\0"
    "U BRA\0"
    "T3b\0"
    "Rhônexpress\0"
    "Line 3\0"
    "KTL\0"
    "T0\0"
    "T13\0"
    "T17\0"
    "T9\0"
    "T15\0"
    "T24\0"
    "T21\0"
    "T22\0"
    "T27\0"
    "T8\0"
    "S-2\0"
    "GLNELG\0"
    "97\0"
    "103\0"
    "BR\0"
    "104\0"
    "S41\0"
    "SFM 6\0"
    "C11\0"
    "IC 8\0"
    "S19\0"
    "S21\0"
    "Gold\0"
    "105\0"
    "CR-Providence\0"
    "CR-Franklin\0"
    "CR-Kingston\0"
    "Z70\0"
    "PST\0"
    "S70\0"
    "Babylon\0"
    "VLT Curado-Cajueiro Seco\0"
    "VLT Cabo - Cajueiro Seco\0"
    "654\0"
    "S53\0"
    "S210\0"
    "Z50\0"
    "903\0"
    "Z30\0"
    "NS\0"
    "m2\0"
    "L10 Nord\0"
    "L9 Nord\0"
    "86990\0"
    "Tren Urbano\0"
    "SKA2\0"
    "Tide\0"
    "703\0"
    "Penn\0"
    "C6\0"
    "S150\0"
    "G30\0"
    "S820\0"
    "G10\0"
    "RS30\0"
    "S220\0"
    "G71\0"
    "G70\0"
    "G43\0"
    "S35\0"
    "S34\0"
    "NC (NB)\0"
    "S80\0"
    "101\0"
    "106\0"
    "108\0"
    "U17\0"
    "U18\0"
    "WTR\0"
    "TDV\0"
    "S44\0"
    "C-3\0"
    "SKA1\0"
    "S1A\0"
    "S1B\0"
    "S2A\0"
    "S2B\0"
    "S4A\0"
    "S4B\0"
    "102\0"
    "E-W\0"
    "S-N\0"
    "R6\0"
    "R60\0"
    "R5\0"
    "R50\0"
    "U71\0"
    "U83\0"
    "T49\0"
    "T23\0"
    "U73\0"
    "705\0"
    "R2Sud\0"
    "HVL\0"
    "47B\0"
    "R2\0"
    "R3\0"
    "U49\0"
    "R4\0"
    "R8\0"
    "RT1\0"
    "RT2\0"
    "RG1\0"
    "Expo Line\0"
    "Millennium Line\0"
    "Canada Line\0"
    "U42\0"
    "U45\0"
    "R16\0"
    "R12\0"
    "615P\0"
    "L9 Sud\0"
    "NL1\0"
    "R11\0"
    "R13\0"
    "R14\0"
    "R15\0"
    "RE6\0"
    "Sul\0"
    "N2\0"
    "BLUE\0"
    "GREEN\0"
    "ORANGE\0"
    "620\0"
    "Manchester Airport - Manchester Victoria\0"
    "GN5\0"
    "North Clyde\0"
    "North Berwick\0"
    "Maryhill\0"
    "Santa Cruz\0"
    "Japeri\0"
    "TL8\0"
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
    "RB22\0"
    "25E\0"
    "C13\0"
    "MSC\0"
    "S14\0"
    "Тр8\0"
    "Τ6\0"
    "Τ7\0"
    "S43\0"
    "S81\0"
    "T10\0"
    "SIL\0"
    "TL-1\0"
    "TL-2\0"
    "8А\0"
    "T3a\0"
    "RB10\0"
    "Orlyval\0"
    "CDGVAL\0"
    "Luas Green Line\0"
    "DART\0"
    "MTN\0"
    "C-2\0"
    "C14\0"
    "C15\0"
    "Central\0"
    "C5\0"
    "F7\0"
    "L-17\0"
    "C2f\0"
    "S62\0"
    "RL1\0"
    "3bis\0"
    "CCL\0"
    "I2\0"
    "YL\0"
    "Silver\0"
    "510\0"
    "CR-Fitchburg\0"
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
    "326\0"
    "仙台市南北線 (Sendai Namboku Line)\0"
    "仙台市東西線 (Sendai Tozai Line)\0"
    "L4A\0"
    "Verde\0"
    "Laranja\0"
    "Vermelha\0"
    "Amarela\0"
    "Azul\0"
    "Subway\0"
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
    "IR 15\0"
    "RB 43\0"
    "IR 16\0"
    "IR 36\0"
    "IR 17\0"
    "IR 90\0"
    "S 9\0"
    "RB24\0"
    "TL10\0"
    "TL9\0"
    "U2Z\0"
    "ML1\0"
    "ML2\0"
    "ML3\0"
    "I1\0"
    "RL2\0"
    "R2Nord\0"
    "R7\0"
    "B1\0"
    "B2\0"
    "C-10\0"
    "C-7\0"
    "WCE\0"
    "Conexão Metrô-Aeroporto\0"
    "RMGL\0"
    "512\0"
    "NOR\0"
    "SEAFRD\0"
    "SV\0"
    "BL\0"
    "GR\0"
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
    "EWL\0"
    "Pink Line\0"
    "BTS Silom\0"
    "U AVO\0"
    "AG\0"
    "SP\0"
    "941\0"
    "G44\0"
    "S506\0"
    "G50\0"
    "Blue Line\0"
    "Violet Line\0"
    "Yellow Line\0"
    "AEx\0"
    "Magenta Line\0"
    "浦江\0"
    "311\0"
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
    "C-4\0"
    "Rosewood\0"
    "S17\0"
    "ExpressTram\0"
    "RB 57\0"
    "T11\0"
    "A4\0"
    "25S\0"
    "KKY\0"
    "RIU\0"
    "201\0"
    "42X\0"
    "TGM\0"
    "43X\0"
    "GC\0"
    "L10 Sud\0"
    "G·J\0"
    "202\0"
    "902\0"
    "750\0"
    "321\0"
    "1720\0"
    "GG\0"
    "PKM3\0"
    "56A\0"
    "59A\0"
    "59B\0"
    "Circular\0"
    "Long Beach\0"
    "Far Rockaway\0"
    "MSC 621\0"
    "MNC\0"
    "RE 22\0"
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
    "IK\0"
    "exo5\0"
    "KD\0"
    "exo3\0"
    "U16\0"
    "捷運紅線 (新北投支線)\0"
    "Z72\0"
    "OSBORN\0"
    "KS-AE\0"
    "F3\0"
    "SS\0"
    "JN\0"
    "Linea 1\0"
    "Orange Line\0"
    "504\0"
    "509\0"
    "U GUS\0"
    "U MCS\0"
    "ACE\0"
    "SMART\0"
    "10AB\0"
    "9AB\0"
    "HN\0"
    "Local\0"
    "APM\0"
    "GF\0"
    "CRL\0"
    "TEL\0"
    "D11\0"
    "PURP\0"
    "YELL\0"
    "SIR\0"
    "Green-E\0"
    "<7>\0"
    "<6>\0"
    "511\0"
    "R31\0"
    "22R\0"
    "21R\0"
    "TWL\0"
    "TKL\0"
    "S23\0"
    "751P\0"
    "NEC\0"
    "Cape Flats\0"
    "C-6\0"
    "NLR\0"
    "Southern Suburbs\0"
    "Central Line\0"
    "JFK\0"
    "Norte\0"
    "AERA1 City\0"
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
    "OT\0"
    "김포 골드라인\0"
    "910\0"
    "Green-D\0"
    "Daxing Airport\0"
    "River Line\0"
    "CMET\0"
    "APT Blue\0"
    "BTS Sukhumvit\0"
    "Rochdale - East Didsbury\0"
    "Shaw and Crompton - East Didsbury\0"
    "JB\0"
    "Ashton-under-Lyne – MediaCityUK\0"
    "Ashton-under-Lyne – Eccles\0"
    "Piccadilly - Altrincham\0"
    "Altrincham – Bury\0"
    "ESFECO\0"
    "MSC 821\0"
    "Kariega CBD\0"
    "Berlin\0"
    "KS\0"
    "Taipa\0"
    "305\0"
    "309\0"
    "316\0"
    "4М\0"
    "3М\0"
    "2М\0"
    "1М\0"
    "Manassas\0"
    "Fredericksburg\0"
    "CHW\0"
    "CHE\0"
    "AIR\0"
    "CYN\0"
    "ELW\0"
    "NWK\0"
    "Sado\0"
    "T2B\0"
    "West Hempstead\0"
    "Port Washington\0"
    "Montauk\0"
    "Port Jefferson\0"
    "TGM1\0"
    "Hartford Line\0"
    "IR 65\0"
    "CR-Greenbush\0"
    "CR-Worcester\0"
    "CR-Fairmount\0"
    "CR-Haverhill\0"
    "CR-Lowell\0"
    "CR-Middleborough\0"
    "CR-Needham\0"
    "CR-Newburyport\0"
    "91/Perris Valley\0"
    "Inland Empire-Orange County\0"
    "Riverside\0"
    "San Bernardino\0"
    "Ventura County\0"
    "Antelope Valley\0"
    "Turquoise Line\0"
    "Purple Line\0"
    "RE 1\0"
    "550\0"
    "R17\0"
    "TEX\0"
    "630\0"
    "656\0"
    "636\0"
    "662\0"
    "640\0"
    "BTANIC\0"
    "UP Express\0"
    "Stouffville\0"
    "Richmond Hill\0"
    "MI\0"
    "Kitchener\0"
    "Barrie\0"
    "Lakeshore East\0"
    "South Coast\0"
    "Lakeshore West\0"
    "Umlazi\0"
    "Crossmoor\0"
    "kwaMashu\0"
    "Old Main\0"
    "Metrorail\0"
    "LRT\0"
    "5A\0"
    "Airside E\0"
    "SKY\0"
    "1645\0"
    "The Trafford Centre – Cornbrook\0"
    "JSQ–33 via HOB\0"
    "<F>\0"
    "HBLR\0"
    "D10\0"
    "Mattapan\0"
    "Green-B\0"
    "Green-C\0"
    "Metro\0"
    "S82\0"
    "C-1a\0"
    "WEST\0"
    "ONE\0"
    "N6\0"
    "Thilawa\0"
    "Eastern University\0"
    "Ywar Thar Gyi\0"
    "Computer University\0"
    "Insein - Hlaw Karr\0"
    "Dagon University\0"
    "U Coimbra<=>Figueira\0"
    "SN 4\0"
    "KK\0"
    "E11\0"
    "2V\0"
    "1V\0"
    "272\0"
    "T1a\0"
    "T2a\0"
    "TL-3\0"
    "4–环–5\0"
    "TJ\0"
    "SI\0"
    "APM Gold Line\0"
    "Π2\0"
    "Π1\0"
    "86981\0"
    "86960\0"
    "86964\0"
    "TI\0"
    "T1A\0"
    "T1B\0"
    "FEX\0"
    "CK\0"
    "NH\0"
    "Т1\0"
    "RB 14\0"
    "RB 54\0"
    "RE 5\0"
    "Limited\0"
    "TECO\0"
    "QLine\0"
    "APT Rose\0"
    "m1\0"
    "OH\0"
    "E3a\0"
    "RE 31\0"
    "RE 32\0"
    "RE 35\0"
    "RB 18\0"
    "Airside C\0"
    "Airside F\0"
    "Airside A\0"
    "LEB\0"
    "UAE Exchange\0"
    "IR87\0"
    "G40\0"
    "Z42\0"
    "TER 22\0"
    "TNH1\0"
    "IR 35\0"
    "THP1\0"
    "Ouargla tram\0"
    "EKV\0"
    "LKY\0"
    "TRS\0"
    "Northern Express\0"
    "1E\0"
    "TAD\0"
    "F1\0"
    "F2\0"
    "TPC\0"
    "1N\0"
    "15b\0"
    "S 7\0"
    "S 47\0"
    "RE 3\0"
    "Ferny Grove\0"
    "Doomben\0"
    "OUTHA\0"
    "GRNG\0"
    "GAWC\0"
    "FLNDRS\0"
    "Aqua\0"
    "Redcliffe Peninsula\0"
    "R40\0"
    "IR 66\0"
    "Shorncliffe\0"
    "LIL\0"
    "7AB\0"
    "MTR\0"
    "RB 73\0"
    "Z40\0"
    "RE80\0"
    "JT\0"
    "T12\0"
    "Jinyi\0"
    "S88\0"
    "S90\0"
    "F4\0"
    "XR\0"
    "GR01\0"
    "AGTS\0"
    "6B\0"
    "S74\0"
    "S 10\0"
    "RE8\0"
    "IR85\0"
    "215\0"
    "58d\0"
    "M11\0"
    "D7\0"
    "M14\0"
    "D4\0"
    "240\0"
    "M12\0"
    "M9\0"
    "M20\0"
    "31/\0"
    "6b\0"
    "RB32\0"
    "RB 50\0"
    "RB21\0"
    "RB37\0"
    "Caboolture\0"
    "Sunshine Coast\0"
    "Gold Coast\0"
    "S225\0"
    "M206\0"
    "D3\0"
    "D9\0"
    "223\0"
    "245\0"
    "PR\0"
    "CB\0"
    "SCLR\0"
    "BK\0"
    "Xihuan\0"
    "D13\0"
    "T46\0"
    "Cleveland\0"
    "Beenleigh\0"
    "NC (SB)\0"
    "1S\0"
    "3N\0"
    "4N\0"
    "S39\0"
    "Kalayang\0"
    "GLK\0"
    "C-5a\0"
    "Delhi–Meerut RapidX\0"
    "Springfield\0"
    "SALIS\0"
    "NOAR\0"
    "FESTVL\0"
    "GLAN\0"
    "GAW\0"
    "ER-02\0"
    "2-ая Сормовская линия\0"
    "1-ая Сормовская линия\0"
    "Приокская линия\0"
    "REX1\0"
    "T41\0"
    "T30\0"
    "REX3\0"
    "BEG\0"
    "RB 40\0"
    "RL3\0"
    "4а\0"
    "RB 33\0"
    "S49\0"
    "1T\0"
    "S37\0"
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
    "Stuttgart U13.svg\0"
    "Logo Stadtbahn Stuttgart.svg\0"
    "Berlin Tram 63.svg\0"
    "Berlin Tram 61.svg\0"
    "Berlin Tram 68.svg\0"
    "Berlin Tram 62.svg\0"
    "Berlin Tram 37.svg\0"
    "SRS Tram Logo.svg\0"
    "Stuttgart U1.svg\0"
    "Stuttgart U2.svg\0"
    "Stuttgart U3.svg\0"
    "Stuttgart U4.svg\0"
    "Stuttgart U5.svg\0"
    "Stuttgart U6.svg\0"
    "Stuttgart U7.svg\0"
    "Stuttgart U8.svg\0"
    "Stuttgart U9.svg\0"
    "Zahnradbahn-Logo VVS.svg\0"
    "Stuttgart U11.svg\0"
    "Stuttgart U12.svg\0"
    "Stuttgart U14.svg\0"
    "Stuttgart U15.svg\0"
    "Stuttgart U19.svg\0"
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
    "Stadtbahn Logo.png\0"
    "S1 S-Bahn Stuttgart Logo (2021).svg\0"
    "S2 S-Bahn Stuttgart Logo (2021).svg\0"
    "S3 S-Bahn Stuttgart Logo (2021).svg\0"
    "S6 S-Bahn Stuttgart Logo (2021).svg\0"
    "Símbolo del tranvía de Tenerife.svg\0"
    "Magdeburg Tram 6 (2021).png\0"
    "Magdeburg Tram 1 (2021).png\0"
    "Magdeburg Tram 4 (2021).png\0"
    "Magdeburg Tram 5 (2021).png\0"
    "Hiroden Logomark.svg\0"
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
    "Logo of the Toronto Transit Commission.svg\0"
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
    "West Midlands Metro generic symbol.svg\0"
    "Marseille métro M1.svg\0"
    "Panneau Métro de Marseille.svg\0"
    "Marseille métro M2.svg\0"
    "Tyne Wear Metro logo.svg\0"
    "Kyivpastrans blue 01.png\0"
    "Berlin transit icons - S85.svg\0"
    "Línia 8 de Metrovalència.svg\0"
    "Línia 6 de Metrovalència.svg\0"
    "Línia 4 de Metrovalència.svg\0"
    "Línia 5 de Metrovalència.svg\0"
    "Línia 3 de Metrovalència.svg\0"
    "Línia 1 de Metrovalència.svg\0"
    "TRAM - Alicante Logo-L4.svg\0"
    "TRAM - Metropolitano de Alicante -T-.svg\0"
    "TRAM - Alicante Logo-L1.svg\0"
    "S-train service C.svg\0"
    "S-train service H.svg\0"
    "Cercanías C7 (NaranjaAM).svg\0"
    "Cercanias Logo.svg\0"
    "Cercanías C8 (AmarilloAM).svg\0"
    "SML2.svg\0"
    "Paris transit icons - Train U.svg\0"
    "Paris transit icons - Train.svg\0"
    "Logo NN Tram.svg\0"
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
    "MTA NYC logo.svg\0"
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
    "Prag Esko Logo.svg\0"
    "BJS Line 2 icon.svg\0"
    "Beijing Subway simplified logo.svg\0"
    "BJS Line 1 icon.svg\0"
    "BJS Line 13 icon.svg\0"
    "Budapest M1 Metro.svg\0"
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
    "Italian traffic signs - icona tram.svg\0"
    "RheinNeckar S5.svg\0"
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
    "Hamburg S3.svg\0"
    "St Louis MetroLink Logo.svg\0"
    "Izhevsk Tram 10.svg\0"
    "Kiev Metro Line 2.svg\0"
    "Kharkiv Metro logo.svg\0"
    "Kiev Metro Line 1.svg\0"
    "Kiev Metro Line 3.svg\0"
    "Izhevsk Tram 11.svg\0"
    "Kiev T logo.svg\0"
    "Izhevsk Tram 12.svg\0"
    "Tram icon SPB.svg\0"
    "Logo Tramway Dijon Line 2.svg\0"
    "Logo Tramway Dijon.svg\0"
    "Logo Tramway Dijon Line 1.svg\0"
    "Nürnberg U3.svg\0"
    "Nürnberg U1.svg\0"
    "Frankfurt am Main Tram 21.svg\0"
    "Frankfurt am Main Tram 16.svg\0"
    "Logo Tramway Reims Line A.svg\0"
    "Logo Tramway Reims Line B.svg\0"
    "Frankfurt am Main Tram 11.svg\0"
    "Frankfurt am Main Tram 12.svg\0"
    "Frankfurt am Main Tram 14.svg\0"
    "Frankfurt am Main Tram 15.svg\0"
    "Frankfurt am Main Tram 17.svg\0"
    "Frankfurt am Main Tram 18.svg\0"
    "Frankfurt S6.svg\0"
    "Linka 4 (Bratislava).svg\0"
    "Linka 7 (Bratislava).svg\0"
    "Nürnberg T6.png\0"
    "Izhevsk Tram 1.svg\0"
    "Izhevsk Tram 4.svg\0"
    "Izhevsk Tram 7.svg\0"
    "Izhevsk Tram 9.svg\0"
    "Izhevsk Tram 2.svg\0"
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
    "Augsburg Tram 6.svg\0"
    "Ligne1bielefeld.svg\0"
    "Ligne3bielefeld.svg\0"
    "Ligne2bielefeld.svg\0"
    "Ligne4bielefeld.svg\0"
    "München S20.svg\0"
    "München S7.svg\0"
    "Logo de la ligne 1 du tramway de Nantes.svg\0"
    "Logo du Tramway de Nantes.svg\0"
    "TfNSW T3.svg\0"
    "Logo de la ligne 2 du tramway de Nantes.svg\0"
    "Logo de la ligne 3 du tramway de Nantes.svg\0"
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
    "ChongqingMetroLine01.svg\0"
    "Szczecin Tram 10.svg\0"
    "CDML1.svg\0"
    "S8 barcelona.svg\0"
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
    "Logo tram-train Mulhouse.svg\0"
    "Logo tram Mulhouse.svg\0"
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
    "Linka 3 (Bratislava).svg\0"
    "Linka 9 (Bratislava).svg\0"
    "NRW S7.svg\0"
    "Hannover S1.svg\0"
    "Liege S-Trein S41.svg\0"
    "NMBS S-Trein logo.svg\0"
    "Paris transit icons - Métro 7bis.svg\0"
    "Paris transit icons - Métro.svg\0"
    "Hannover S6.svg\0"
    "Icon brownline CTA.png\0"
    "Chicago L fictional logo.svg\0"
    "Hannover S4.svg\0"
    "Bucarest M4.svg\0"
    "Metrorex logo.svg\0"
    "S2 WAW.png\0"
    "PL-SKMWA logo.svg\0"
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
    "DSW21 U44.svg\0"
    "Icon yellowline CTA.png\0"
    "Oslo Metro 3 2016.svg\0"
    "Oslo T-bane Logo.svg\0"
    "Oslo Metro 2 2016.svg\0"
    "Oslo Metro 5 2016.svg\0"
    "DSW21 U46.svg\0"
    "Lyon tcl tram-5.svg\0"
    "Lyon tcl logo-tram-full.svg\0"
    "Cercanías C8.svg\0"
    "Logo Tramway Bordeaux ligne A.svg\0"
    "Logo Tramway Bordeaux.svg\0"
    "Logo Tramway Bordeaux ligne B.svg\0"
    "KRT Line 6 icon.svg\0"
    "Logo Tramway Bordeaux ligne C.svg\0"
    "Icon pinkline CTA.png\0"
    "Icon blueline CTA.png\0"
    "DSW21 U47.svg\0"
    "BJS Line 9 icon.svg\0"
    "DSW21 U41.svg\0"
    "DSW21 U43.svg\0"
    "Icon purpleline CTA.png\0"
    "S1 Wien.svg\0"
    "S-Bahn Wien.svg\0"
    "S2 Wien.svg\0"
    "S3 Wien.svg\0"
    "Hannover S2.svg\0"
    "BJS Daxing Line icon.svg\0"
    "BJS Line 15 icon.svg\0"
    "Milano linea M5.svg\0"
    "ChongqingMetroLine06.svg\0"
    "M-Line Trolley logo.svg\0"
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
    "LogoNaumburgerTouristenBahn.svg\0"
    "Línea C (SBASE) bullet.svg\0"
    "Línea B (SBASE) bullet.svg\0"
    "Línea E (SBASE) bullet.svg\0"
    "Línea D (SBASE) bullet.svg\0"
    "Línea H (SBASE) bullet.svg\0"
    "Bucarest M2.svg\0"
    "Istanbul T1 Line Symbol.svg\0"
    "Paris transit icons - Métro 15.svg\0"
    "Mitteldeutschland S2.svg\0"
    "Hannover S7.svg\0"
    "Oslo Tramway new 13.svg\0"
    "Oslo Tramway new 11.svg\0"
    "Oslo Tramway new 12.svg\0"
    "Montreal public transit icons - Métro 4.svg\0"
    "Montreal public transit icons - Métro.svg\0"
    "Montreal public transit icons - Métro 2.svg\0"
    "Montreal public transit icons - Métro 5.svg\0"
    "Montreal public transit icons - Métro 1.svg\0"
    "GZM Line 2 icon.svg\0"
    "Wien U2.svg\0"
    "Cercanías C4f.svg\0"
    "Spmetro 3.svg\0"
    "Oslo Tramway new 17.svg\0"
    "Wien U1.svg\0"
    "S3 Kärnten.svg\0"
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
    "Augsburg Tram 4.svg\0"
    "Bremen RS2.svg\0"
    "Bremen RS1.svg\0"
    "Bayern RB 58.svg\0"
    "STIB-MIVB Line 44.svg\0"
    "STIB-MIVB Line 39.svg\0"
    "VBB-RB-23-2022.svg\0"
    "NJM Line 10 icon.svg\0"
    "Nanjing Metro Logo.svg\0"
    "NJM Line 1 icon.svg\0"
    "RB13 VBB (2021).png\0"
    "NJM Line 2 icon.svg\0"
    "Frankfurt S1.svg\0"
    "Frankfurt S2.svg\0"
    "Frankfurt S8.svg\0"
    "Frankfurt S9.svg\0"
    "Cercanías C5.svg\0"
    "DeLijn icon 12antw.svg\0"
    "DeLijn icon 9antw.svg\0"
    "DeLijn icon 24antw.svg\0"
    "DeLijn icon 3antw.svg\0"
    "DeLijn icon 4antw.svg\0"
    "DeLijn icon 5antw.svg\0"
    "DeLijn icon 6antw.svg\0"
    "DeLijn icon 7antw.svg\0"
    "DeLijn icon 10antw.svg\0"
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
    "Line T (Sound Transit) icon.svg\0"
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
    "Cercanías C3 (Azul oscuro).svg\0"
    "Icon-blue-line-default.svg\0"
    "STIB-MIVB Line 97.svg\0"
    "TAM-4.svg\0"
    "Logo Tramway Montpellier.svg\0"
    "Budapest M3 Metro.svg\0"
    "Budapest M4 Metro.svg\0"
    "Budapest M2 Metro.svg\0"
    "Linka 1 (Bratislava).svg\0"
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
    "Amsterdam transit icons - Metro 50.svg\0"
    "Amsterdam metro logo.svg\0"
    "Amsterdam transit icons - Metro 51.svg\0"
    "Amsterdam transit icons - Metro 54.svg\0"
    "Amsterdam transit icons - Metro 53.svg\0"
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
    "TfNSW T4.svg\0"
    "T6.svg\0"
    "TfNSW T5.svg\0"
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
    "Poznań ikona linii tramwajowej 1.png\0"
    "Poznań ikona linii tramwajowej 2.png\0"
    "Poznań ikona linii tramwajowej 3.png\0"
    "Hamburg A2.svg\0"
    "DeLijn icon 8antw.svg\0"
    "Cercanías C6 (AzulAM).svg\0"
    "Poznań ikona linii tramwajowej 0.png\0"
    "Antwerpen S-Trein S32.svg\0"
    "S7 Wien.svg\0"
    "S60 Wien.svg\0"
    "S50 Wien.svg\0"
    "S80 Wien.svg\0"
    "S45 Wien.svg\0"
    "S40 Wien.svg\0"
    "MetroCagliari logo.svg\0"
    "Marseille tram T3.svg\0"
    "Number prefix Toyo-Rapid.svg\0"
    "Cercanías C3.svg\0"
    "S1 barcelona.svg\0"
    "S2 barcelona.svg\0"
    "Line 1 (Sound Transit) icon.svg\0"
    "New Taipei Metro Danhai LRT Line icon.svg\0"
    "Hamburg RE5.svg\0"
    "Kaohsiung Rapid Transit Circular Line.svg\0"
    "Athens Suburban Railway Line 3.svg\0"
    "Hamburg S2-2023.svg\0"
    "Hamburg S5.svg\0"
    "Hamburg A1.svg\0"
    "Línia 2 de Metrovalència.svg\0"
    "Línia 9 de Metrovalència.svg\0"
    "Línia 7 de Metrovalència.svg\0"
    "Toulouse line T2 symbol.svg\0"
    "S3 barcelona.svg\0"
    "S4 barcelona.svg\0"
    "R6 barcelona.svg\0"
    "R60 barcelona.svg\0"
    "R5 barcelona.svg\0"
    "R50 barcelona.svg\0"
    "Poznań ikona linii tramwajowej 17.png\0"
    "Poznań ikona linii tramwajowej 13.png\0"
    "Poznań ikona linii tramwajowej 15.png\0"
    "R2S barcelona.svg\0"
    "R2 barcelona.svg\0"
    "R3 barcelona.svg\0"
    "DSW21 U49.svg\0"
    "R4 barcelona.svg\0"
    "R8 barcelona.svg\0"
    "RT1 tarragona.svg\0"
    "RT2 tarragona.svg\0"
    "RG1 girona.svg\0"
    "DSW21 U42.svg\0"
    "DSW21 U45.svg\0"
    "R12 Rodalies de Catalunya.svg\0"
    "E Embarcadero logo.svg\0"
    "Rotterdam transit icons - Metro A.svg\0"
    "Metro Rotterdam logo.svg\0"
    "Rotterdam transit icons - Metro B.svg\0"
    "Rotterdam transit icons - Metro C.svg\0"
    "Rotterdam transit icons - Metro D.svg\0"
    "Rotterdam transit icons - Metro E.svg\0"
    "RandstadRail logo.png\0"
    "GZM Line 7 icon.svg\0"
    "C-1 light blue.svg\0"
    "R11 Rodalies de Catalunya.svg\0"
    "R13 Rodalies de Catalunya.svg\0"
    "R14 Rodalies de Catalunya.svg\0"
    "R15 Rodalies de Catalunya.svg\0"
    "Hamburg RE6.svg\0"
    "Metro do Porto linha D.svg\0"
    "Porto Metro logo.svg\0"
    "Metro do Porto linha E.svg\0"
    "Metro do Porto linha F.svg\0"
    "Metro do Porto linha A.svg\0"
    "Metro do Porto linha C.svg\0"
    "S Shuttle logo.svg\0"
    "MetroBH logo.svg\0"
    "S (South Line - Fortaleza Subway).png\0"
    "S4 Wien.svg\0"
    "Metro do Porto linha B.svg\0"
    "Dallas Area Rapid Transit logo.svg\0"
    "Blå linjen logo.svg\0"
    "Stockholm metro symbol.svg\0"
    "Gröna linjen logo.svg\0"
    "Röda linjen logo.svg\0"
    "Underground.svg\0"
    "Icon 4 (set yellow).png\0"
    "MTR LR 505.svg\0"
    "AubagneTram.svg\0"
    "18E CCFL.png\0"
    "Moskwa Metro Line 14.svg\0"
    "LACMTA Circle E Line.svg\0"
    "LACMTA Circle A Line.svg\0"
    "RB22 VBB (2021).png\0"
    "25E CCFL.png\0"
    "Renfe Media distancia.svg\0"
    "Logo Metro Rennes ligne b.svg\0"
    "Logo VLT Carioca Linha 1.svg\0"
    "Vlt carioca logo.svg\0"
    "Poznań ikona linii tramwajowej 7.png\0"
    "Poznań ikona linii tramwajowej 18.png\0"
    "L12 barcelona.svg\0"
    "GZM Line 14 icon.svg\0"
    "S1 WAW.png\0"
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
    "Moskwa Metro Line 8A.svg\0"
    "Línea 2 - Tren Concepción - Coronel, Biotren (2021).svg\0"
    "Línea 1 - Tren Mercado de Talcahuano - Hualqui, Biotren (2021).svg\0"
    "Paris transit icons - Train J.svg\0"
    "Paris transit icons - Tram 3a.svg\0"
    "Paris transit icons - Tram 4.svg\0"
    "Paris transit icons - Tram 5.svg\0"
    "Paris transit icons - Tram 6.svg\0"
    "Paris transit icons - Tram 7.svg\0"
    "RB10 VBB (2021).png\0"
    "Bremen RS4.svg\0"
    "Paris Orlyval icon.svg\0"
    "RE6 VBB (2021).png\0"
    "Taoyuan Metro Line Airport.svg\0"
    "NYCS-bull-trans-W-Std.svg\0"
    "Logo tram 1 Mulhouse.svg\0"
    "STIB-MIVB Line 5.svg\0"
    "Brussels Metro Logo.svg\0"
    "Logo tram 2 Mulhouse.svg\0"
    "STIB-MIVB Line 1.svg\0"
    "Logo tram 3 Mulhouse.svg\0"
    "RE1 VBB (2021).png\0"
    "Logo VLT Carioca Linha 2.svg\0"
    "München S2.svg\0"
    "Metro de Bilbao L1.svg\0"
    "S4 Kärnten.svg\0"
    "S2 Kärnten.svg\0"
    "S1 Kärnten.svg\0"
    "STIB-MIVB Line 7.svg\0"
    "Metro de Bilbao L3.svg\0"
    "STIB-MIVB Line 92.svg\0"
    "L1 Metro de Granada.svg\0"
    "Cercanías C2.svg\0"
    "Paris transit icons - Métro 2.svg\0"
    "Paris transit icons - RER E.svg\0"
    "STIB-MIVB Line 2.svg\0"
    "GZM Line 6 icon.svg\0"
    "Euskotren E1.svg\0"
    "Berlin transit icons - S41.svg\0"
    "STIB-MIVB Line 81.svg\0"
    "Brussel S-Trein S1.svg\0"
    "Cercanías C4 (MoradoAM).svg\0"
    "Cercanías C5 (VerdeAM).svg\0"
    "Gand S-Trein S51.svg\0"
    "Liege S-Trein S44.svg\0"
    "Charleroi S-Trein S61.svg\0"
    "Charleroi S-Trein S62.svg\0"
    "Charleroi S-Trein S63.svg\0"
    "Antwerpen S-Trein S33.svg\0"
    "Gand S-Trein S52.svg\0"
    "Charleroi S-Trein S64.svg\0"
    "الخط الأول لطرامواي اليضاء.png\0"
    "Istanbul T4 Line Symbol.svg\0"
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
    "Stammstrecke Wien.svg\0"
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
    "Trams roundel.svg\0"
    "WMATA Yellow.svg\0"
    "WMATA Metro Logo.svg\0"
    "Pittsburgh Light Rail (logo).svg\0"
    "Logo Blue Line (San Diego Trolley).svg\0"
    "Seoul Metro Line 2.svg\0"
    "Seoul Metro Line 4.svg\0"
    "Logo ligne 1 métro d'Alger.svg\0"
    "STIB-MIVB Line 51.svg\0"
    "STIB-MIVB Line 93.svg\0"
    "Tabriz Metro Line 1.png\0"
    "NNMetro Line 2.svg\0"
    "Helsingin metro logo.svg\0"
    "Logo metropolitana di Catania.svg\0"
    "Maha Mumbai Metro.png\0"
    "RB66 VBB (2021).png\0"
    "Astram Logo.svg\0"
    "Subway FukuokaHakozaki.svg\0"
    "Fukuoka City Subway Logo.svg\0"
    "Subway FukuokaKuko.svg\0"
    "Poznań ikona linii tramwajowej 16.png\0"
    "Poznań ikona linii tramwajowej 8.png\0"
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
    "Poznań ikona linii tramwajowej 9.png\0"
    "Istanbul M2 Line Symbol.svg\0"
    "Istanbul Metro Logo.svg\0"
    "Istanbul M4 Line Symbol.svg\0"
    "Istanbul M1 Line Symbol.svg\0"
    "Istanbul M3 Line Symbol.svg\0"
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
    "Glasgow Subway.svg\0"
    "Subway FukuokaNanakuma.svg\0"
    "Almaty metro logo v2.svg\0"
    "Almaty metro logo.svg\0"
    "Logo of the Pyongyang Metro.svg\0"
    "Tehran Metro Line 1.png\0"
    "Tehran Metro Line 5.svg\0"
    "Luxtram T1 2020.png\0"
    "Tehran Metro Line 3.png\0"
    "Bucarest M3.svg\0"
    "Bucarest M1.svg\0"
    "IC 1 logo.svg\0"
    "IC 5 logo.svg\0"
    "IC 2 logo.svg\0"
    "IC 3 logo.svg\0"
    "Línea 1 Metro de Sevilla.svg\0"
    "Símbolo del Metro de Sevilla.svg\0"
    "MetroMalaga L2.svg\0"
    "MetroMalaga L1.svg\0"
    "Metro Palma M2.svg\0"
    "Metro Palma M1.svg\0"
    "IC 51 logo.svg\0"
    "IC 21 logo.svg\0"
    "IR 26 logo.svg\0"
    "IR 27 logo.svg\0"
    "2 white, green rounded rectangle.svg\0"
    "Metro Tbilisi logo.svg\0"
    "1 white, red rounded rectangle.svg\0"
    "Kyiv Urban Electric Train.svg\0"
    "Symbole Lille 2.svg\0"
    "Lille Metro Logo 2017.svg\0"
    "Symbole Lille 1.svg\0"
    "IR 75 logo.svg\0"
    "IR 46 logo.svg\0"
    "IR 70 logo.svg\0"
    "IC 6 logo.svg\0"
    "IC 61 logo.svg\0"
    "Baku Subway logo.svg\0"
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
    "NYCS-bull-trans-Z-Std.svg\0"
    "Madrid-MetroLinea5.svg\0"
    "Adana Metro logo.svg\0"
    "Madrid-MetroLinea3.svg\0"
    "Madrid-MetroLinea2.svg\0"
    "Madrid-MetroLinea7.svg\0"
    "Madrid-MetroRamal.svg\0"
    "Namma metro.svg\0"
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
    "R2N barcelona.svg\0"
    "R7 barcelona.svg\0"
    "Bursaray 1 Line Symbol.svg\0"
    "BursaRay logo.svg\0"
    "XAM Line 2 icon.svg\0"
    "XAM Line 1 icon.svg\0"
    "XAM Line 3 icon.svg\0"
    "Centro file.png\0"
    "Sul blue.png\0"
    "Bursaray 2 Line Symbol.svg\0"
    "ZZMetro Line 1.svg\0"
    "ZZMetro Line CJ.svg\0"
    "Cercanías C10.svg\0"
    "Cercanías C1.svg\0"
    "Cercanías C7.svg\0"
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
    "NJM Line 3 icon.svg\0"
    "SZRT Line 1 icon.svg\0"
    "RMRG logo.svg\0"
    "Delhi Metro logo.svg\0"
    "Linea1mty.svg\0"
    "Linea2mty.svg\0"
    "DLM Line 2 icon.svg\0"
    "NYCS-bull-trans-SF-Std.svg\0"
    "Shenyang Metro Line 1 Logo.svg\0"
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
    "PATCO Line.svg\0"
    "PATH.svg\0"
    "PATH logo.svg\0"
    "Icon 1 (set orange).png\0"
    "Harbin Metro Line 1.svg\0"
    "Harbin Metro Line 3.svg\0"
    "CRRT line1 logo.svg\0"
    "DLM Line 1 icon.svg\0"
    "DLM Line 12 icon.svg\0"
    "Athens Metro Line 1.svg\0"
    "Athens Metro Line 2.svg\0"
    "Yerevan Metro.svg\0"
    "WHM Line 8 icon.svg\0"
    "Madrid MetroLigero4.svg\0"
    "Ankara M3 Metro Hattı Logosu.svg\0"
    "Ankara M4 Metro Hattı Logosu.svg\0"
    "İzmir M1 Line Symbol.svg\0"
    "Metro İzmir logo.svg\0"
    "Jaipur Metro Logo.svg\0"
    "Jaipur Metro Logo.png\0"
    "BTS-Logo.svg\0"
    "STIB-MIVB Line 4.svg\0"
    "STIB-MIVB Line 25.svg\0"
    "STIB-MIVB Line 55.svg\0"
    "STIB-MIVB Line 82.svg\0"
    "Lrtalogo.svg\0"
    "KLRT Line 3 icon.svg\0"
    "KLRT Line 9 icon.svg\0"
    "KLRT Line 4 icon.svg\0"
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
    "Logo of Tokyo Metro Hanzōmon Line.svg\0"
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
    "Subway KyotoTozai.svg\0"
    "Nagoya Subway Logo V2 (Sakura-dori Line).svg\0"
    "Nagoya Subway Logo V2 (Higashiyama Line).svg\0"
    "Nagoya Subway Logo V2 (Meiko Line).svg\0"
    "Nagoya Subway Logo V2 (Tsurumai Line).svg\0"
    "Nagoya Subway Logo V2 (Meijo Line).svg\0"
    "S9 barcelona.svg\0"
    "Kolkata Metro Logo.svg\0"
    "Kolkata Metro System Logo.svg\0"
    "Delhi Metro Line 3.svg\0"
    "Delhi Metro Line 5.svg\0"
    "Delhi Metro Line 6.svg\0"
    "Delhi Metro Line 2.svg\0"
    "KRT Line 3 icon.svg\0"
    "Delhi Metro Line 8.svg\0"
    "Delhi Metro Line 9.svg\0"
    "Istanbul M5 Line Symbol.svg\0"
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
    "ChongqingMetroLine00.svg\0"
    "ChongqingMetroLine05.svg\0"
    "ChongqingMetroLine10.svg\0"
    "BJS Xijiao Line icon.svg\0"
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
    "SZRT Line 2 icon.svg\0"
    "Bayern RB 57.svg\0"
    "Bayern RB 56 SWEG.svg\0"
    "Amsterdam transit icons - Metro 52.svg\0"
    "Paris transit icons - Tram 11.svg\0"
    "Athens Suburban Railway Line 2.svg\0"
    "Athens Suburban Railway Line 1.svg\0"
    "Athens Suburban Railway Line 4.svg\0"
    "BJS Yanfang Line icon.svg\0"
    "Firenze Tramvia logo.svg\0"
    "TianjinMetro.svg\0"
    "Tianjin Metro Line 1 icon.svg\0"
    "Tunis Metro Ligne 4.svg\0"
    "Poznań ikona linii tramwajowej 12.png\0"
    "Poznań ikona linii tramwajowej 11.png\0"
    "Tunis Metro Ligne 5.svg\0"
    "Tunis Metro Ligne 3.svg\0"
    "Tunis Metro Ligne 2.svg\0"
    "TJM TEDA Tram icon.svg\0"
    "Paris transit icons - Train L.svg\0"
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
    "Logo Tempe Streetcar.svg\0"
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
    "Manila Line 7 logo.png\0"
    "Bayern RE 22.svg\0"
    "Cercanías C4.svg\0"
    "Cercanías C9.svg\0"
    "Yurikamome line symbol.svg\0"
    "Logo trireno black.svg\0"
    "Nippori-Toneri Liner symbol.svg\0"
    "Tokyo Sakura Tram symbol.svg\0"
    "Montreal public transit icons - Train 11.svg\0"
    "Tokyu TY line symbol.svg\0"
    "Montreal public transit icons - Train 14.svg\0"
    "ShenzhenMetroLine11.svg\0"
    "Montreal public transit icons - Train 12.svg\0"
    "Saitama Stadium Line symbol.svg\0"
    "SeibuYamaguchi.svg\0"
    "Tokyu MG line symbol.svg\0"
    "Tokyu OM line symbol.svg\0"
    "Tokyu DT line symbol.svg\0"
    "Tokyu IK line symbol.svg\0"
    "Tokyu TM line symbol.svg\0"
    "Montreal public transit icons - Train 15.svg\0"
    "Tokyu KD line symbol.svg\0"
    "New Shuttle Line symbol.svg\0"
    "Montreal public transit icons - Train 13.svg\0"
    "Stuttgart U16.svg\0"
    "Taipei Metro Line Xinbeitou Branch.svg\0"
    "Taipei Metro Line BL.svg\0"
    "Berlin transit icons - S26.svg\0"
    "Logo VLT Carioca Linha 3.svg\0"
    "Tehran Metro Line 6.svg\0"
    "Number prefix SkyAccess.svg\0"
    "TfNSW MNWB.svg\0"
    "TfNSW M.svg\0"
    "Istanbul F3 Line Symbol.svg\0"
    "SeibuShinjuku.svg\0"
    "Tunis Metro Ligne 1.svg\0"
    "Tunis Metro Ligne 6.svg\0"
    "JR JN line symbol.svg\0"
    "Doha Metro Logo 04.2019.svg\0"
    "NJM Line S7 icon.svg\0"
    "NJM Line S9 icon.svg\0"
    "NJM Line S8 icon.svg\0"
    "NJM Line 4 icon.svg\0"
    "WHM Line 2 icon.svg\0"
    "Nankai group logo.svg\0"
    "Osaka Metro Nanko Port Town line symbol.svg\0"
    "GZM Line 4 icon.svg\0"
    "ChongqingMetroLine04.svg\0"
    "GZM Line 21 icon.svg\0"
    "GZM Guangfo Line icon.svg\0"
    "WHM Line 7 icon.svg\0"
    "S5 Steiermark.svg\0"
    "ShenzhenMetroLine7.svg\0"
    "ShenzhenMetroLine3.svg\0"
    "S1 Steiermark.svg\0"
    "长沙地铁4号线线标.svg\0"
    "WHM Line 4 icon.svg\0"
    "WHM Line 11 icon.png\0"
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
    "TfNSW T6 (2024).svg\0"
    "TfNSW T7.svg\0"
    "TfNSW T8.svg\0"
    "ShenzhenMetroLine9.svg\0"
    "Icon-green-line-default.svg\0"
    "TfNSW T1.svg\0"
    "NYCS-bull-trans-M-Std.svg\0"
    "NYCS-bull-trans-L-Std.svg\0"
    "CT Blue.svg\0"
    "CT Red.svg\0"
    "Edmonton Transit System logo.svg\0"
    "Logo PT Kereta Api Indonesia (Persero) 2020.svg\0"
    "NYCS-bull-trans-J-Std.svg\0"
    "NYCS-bull-trans-B-Std.svg\0"
    "NYCS-bull-trans-F-Std.svg\0"
    "WHM Line 21 icon.svg\0"
    "NYCS-bull-trans-C-Std.svg\0"
    "NYCS-bull-trans-D-Std.svg\0"
    "NYCS-bull-trans-E-Std.svg\0"
    "TfNSW T2.svg\0"
    "XAM Line 4 icon.svg\0"
    "C-6 dark blue.svg\0"
    "GZM Line 3 icon.svg\0"
    "Cptm 13.svg\0"
    "N (set basic).png\0"
    "Shenyang Metro Line 9 Logo.svg\0"
    "VTA-Green-icon.svg\0"
    "VTA-Blue-icon.svg\0"
    "ARLbangkok.svg\0"
    "GZM Line 9 icon.svg\0"
    "Berlin transit icons - S42.svg\0"
    "Logo Green Line (San Diego Trolley).svg\0"
    "Logo Orange Line (San Diego Trolley).svg\0"
    "O ( West Line - Fortaleza Subway).png\0"
    "S-train service A.svg\0"
    "Baltimore Light RailLink logo.svg\0"
    "Moskwa Metro Line 15.svg\0"
    "Szczecin Tram 9.svg\0"
    "Euskotren E2.svg\0"
    "O-Train Line 1.svg\0"
    "Line S (Sound Transit) icon.svg\0"
    "Line N (Sound Transit) icon.svg\0"
    "Line 2 (Sound Transit) icon.svg\0"
    "C-5 green.svg\0"
    "C-2 yellow.svg\0"
    "C-3 dark pink.svg\0"
    "ZZMetro Line 14.svg\0"
    "济南轨道交通1号线logo.svg\0"
    "Logo-tramway-orizo-avignon.png\0"
    "Lyon tcl tram-6.svg\0"
    "KT number-C.svg\0"
    "Nice Tramway Logo.svg\0"
    "M3 icon.svg\0"
    "Moskwa Metro Line D1.svg\0"
    "MCD logo.svg\0"
    "Moskwa Metro Line D2.svg\0"
    "Samara Metro logo.svg\0"
    "JR JB line symbol.svg\0"
    "XuzhouMetro.svg\0"
    "XAM Line 14 icon.svg\0"
    "NBRT Line 3 icon.svg\0"
    "HZM Line 5 icon.svg\0"
    "ZZMetro Line 5.svg\0"
    "DeLijn icon 1antw.svg\0"
    "Virginia Railway Express.svg\0"
    "Logo Léman Express Ligne 5.svg\0"
    "Logo Léman Express Ligne 6.svg\0"
    "Icon of FZM L2.svg\0"
    "Logo Léman Express Ligne 4.svg\0"
    "SZRT Line 3 icon.svg\0"
    "Logo Léman Express Ligne 3.svg\0"
    "HohhotMetroLine01.svg\0"
    "济南轨道交通3号线logo.svg\0"
    "Logo Léman Express Ligne 1.svg\0"
    "Logo Léman Express Ligne 2.svg\0"
    "CDML5.svg\0"
    "CTrail Hartford Line logo.svg\0"
    "IR 65 logo.svg\0"
    "SML14.svg\0"
    "VTA-Orange-icon.svg\0"
    "Metrolink logo.svg\0"
    "Bayern RE 1.svg\0"
    "TAM-2.svg\0"
    "TAM-3.svg\0"
    "TAM-1.svg\0"
    "GO Milton logo.svg\0"
    "GO Kitchener logo.svg\0"
    "GO Barrie logo.svg\0"
    "GO Lakeshore East logo.svg\0"
    "GO Lakeshore West logo.svg\0"
    "Taipei Metro Line Y.svg\0"
    "S3 Steiermark.svg\0"
    "S6 Steiermark.svg\0"
    "Milano linea M2.svg\0"
    "Milano linea M3.svg\0"
    "Milano linea M1.svg\0"
    "RER Fribourg Freiburg.svg\0"
    "M4 icon.svg\0"
    "Tobu Skytree Line (TS) symbol.svg\0"
    "HZM Line 16 icon.svg\0"
    "Shenyang Metro Line 10 Logo.svg\0"
    "Stockholm - L -Lokalbanor Logo.svg\0"
    "S7 Steiermark.svg\0"
    "S61 Steiermark.svg\0"
    "NYCS-bull-trans-Fd-Std.svg\0"
    "长沙地铁3号线线标.svg\0"
    "长沙地铁5号线线标.svg\0"
    "Sofia-metro-lines-03.svg\0"
    "Icon-green-line-b-default.svg\0"
    "Icon-green-line-c-default.svg\0"
    "Cercanías C3 (Rojo).svg\0"
    "Cercanías C4 (Morado).svg\0"
    "Cercanías C5 (Azul oscuro).svg\0"
    "Milano S7.svg\0"
    "Number prefix Keikyū.PNG\0"
    "ShenzhenMetroLine6.svg\0"
    "ShenzhenMetroLine10.svg\0"
    "R1 barcelona.svg\0"
    "Suin-Bundang Line.svg\0"
    "Kayseri public transport - T1 symbol.svg\0"
    "Kayseray logo.svg\0"
    "Kayseri public transport - T2 symbol.svg\0"
    "Logo de la Línea 3 del Tren Eléctrico Urbano de Guadalajara.svg\0"
    "KRT Line 4 icon.svg\0"
    "CDML18.svg\0"
    "HohhotMetroLine02.svg\0"
    "Bucarest M5.svg\0"
    "Tobu Tojo Line (TJ) symbol.svg\0"
    "SeibuIkebukuro.svg\0"
    "Kolkata Metro Rail Corporation Logo.svg\0"
    "S4 Tirol.svg\0"
    "S5 Tirol.svg\0"
    "S3 Tirol.svg\0"
    "S8 Tirol (2021).svg\0"
    "Euskotren E5.svg\0"
    "SFM T3.svg\0"
    "SFM T2.svg\0"
    "WX Metro Line 3 icon.svg\0"
    "Tobu Nikko Line (TN) symbol.svg\0"
    "Tobu Isesaki Line (TI) symbol.svg\0"
    "Antalya public transport - T3 symbol.svg\0"
    "Antalya public transport - T2 symbol.svg\0"
    "Antalya public transport - T1A symbol.svg\0"
    "Antalya public transport - T1B symbol.svg\0"
    "FEX VBB (2021).png\0"
    "Hanoi Metro Line 3 Symbol.png\0"
    "Bayern RB 48.svg\0"
    "RheinNeckar S44.svg\0"
    "CDML6.svg\0"
    "CDML8.svg\0"
    "CDML17.svg\0"
    "Raitiovaunu HSL logo.png\0"
    "NBRT Line 4 icon.svg\0"
    "Bayern RB 14.svg\0"
    "Istanbul T5 Line Symbol.svg\0"
    "S2 Tirol.svg\0"
    "SML15.svg\0"
    "Jena Straßenbahn 2.svg\0"
    "Jena Straßenbahn 5.svg\0"
    "Jena Straßenbahn 4.svg\0"
    "Jena Straßenbahn 3.svg\0"
    "Jena Straßenbahn 1.svg\0"
    "Bayern RB 54.svg\0"
    "Bayern RE 5.svg\0"
    "Tramİzmir logo.svg\0"
    "Houston Metro icon.svg\0"
    "Logo du M1 de Lausanne.svg\0"
    "Linea3mty.svg\0"
    "Logo L2 Napoli.svg\0"
    "Euskotren E3a.svg\0"
    "Bayern RE 31.svg\0"
    "Bayern RE 32.svg\0"
    "Bayern RE 35.svg\0"
    "Bayern RB 18.svg\0"
    "Paris transit icons - Tram 9.svg\0"
    "Symbole Lille R.svg\0"
    "Symbole Lille T.svg\0"
    "XAM Line 5 icon.svg\0"
    "XAM Line 6 icon.svg\0"
    "XAM Line 9 icon.svg\0"
    "HZML8.png\0"
    "HZML9.png\0"
    "HZML6icon.png\0"
    "HZM Line 4 icon.svg\0"
    "Wenzhou Metro S1 Line Icon.svg\0"
    "CDML9.svg\0"
    "SZRT Line 5 icon.svg\0"
    "IR 35 logo.svg\0"
    "Logo SFM Palermo.svg\0"
    "ShenzhenMetroLine2.svg\0"
    "ShenzhenMetroLine8.svg\0"
    "NJM Line S6 icon.svg\0"
    "GZM Line 18 icon.svg\0"
    "Harbin Metro Line 2.svg\0"
    "BJS Batong Line icon.svg\0"
    "Szczecin Tram 2.svg\0"
    "Istanbul F1 Line Symbol.svg\0"
    "Istanbul F2 Line Symbol.svg\0"
    "ZZMetro Line 4.svg\0"
    "ZZMetro Line 3.svg\0"
    "Línea 1 CAMETRO.png\0"
    "Línea 4 CAMETRO.png\0"
    "Ctp ar 16 tr.svg\0"
    "Ctp ar 15 tr.svg\0"
    "Ctp ar 12 tr.svg\0"
    "Ctp ar 11 tr.svg\0"
    "Ctp ar 6 tr.svg\0"
    "Ctp ar 7 tr.svg\0"
    "Ctp ar 3 tr.svg\0"
    "Ctp ar 1 tr.svg\0"
    "Ctp ar 15b tr.svg\0"
    "23 Graz.png\0"
    "HZML7.png\0"
    "HZML10.png\0"
    "HZM Line 3 icon.svg\0"
    "Gwangju Metro Line 1.svg\0"
    "WX Metro Line 4 icon.svg\0"
    "BJS Line 11 icon.svg\0"
    "BJS Line 17 icon.svg\0"
    "BJS Line 19 icon.svg\0"
    "NBRT Line 5 icon.svg\0"
    "DLM Line 13 icon.svg\0"
    "Bayern RE 3.svg\0"
    "WHM Line 5 icon.svg\0"
    "WHM Line 16 icon.svg\0"
    "S31 Steiermark.svg\0"
    "GZM Line 22 icon.svg\0"
    "S5 OÖ.svg\0"
    "S3 OÖ.svg\0"
    "S2 OÖ.svg\0"
    "S1 OÖ.svg\0"
    "S4 OÖ.svg\0"
    "ChongqingMetroLine09.svg\0"
    "IR 66 logo.svg\0"
    "Lyon tcl tram-7.svg\0"
    "Tashkent metro line-4.png\0"
    "Icon of FZM L5.svg\0"
    "Línia 10 de Metrovalència.svg\0"
    "DeLijn icon 2antw.svg\0"
    "Bayern RB 73.svg\0"
    "Paris transit icons - Tram 10.svg\0"
    "Paris transit icons - Tram 13.svg\0"
    "长沙地铁6号线线标.svg\0"
    "Izhevsk Tram 5.svg\0"
    "TAM-5.svg\0"
    "File S5 Kärnten.svg\0"
    "RE80-Tilo.svg\0"
    "Paris transit icons - Tram 12.svg\0"
    "Icon of FZM L6.svg\0"
    "S90-Tilo.svg\0"
    "S20-Tilo.svg\0"
    "S10-Tilo.svg\0"
    "S30-Tilo.svg\0"
    "S60-Tilo.svg\0"
    "S40-Tilo.svg\0"
    "S50-Tilo.svg\0"
    "ZZ Line 6 icon.svg\0"
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
    "S (set u).png\0"
    "NJM Line 7 icon.svg\0"
    "New Taipei Metro Line K.png\0"
    "Gaziantep T3 Line Symbol.svg\0"
    "Gaziantep T1 Line Symbol.svg\0"
    "Gaziantep T2 Line Symbol.svg\0"
    "Shiraz Metro Line 2.png\0"
    "Istanbul M12 Line Symbol.svg\0"
    "Karaj Metro Line 2-2.png\0"
    "لوگو قطار شهری کرج و حومه.svg\0"
    "Istanbul M13 Line Symbol.svg\0"
    "Istanbul M7 Line Symbol.svg\0"
    "Istanbul M9 Line Symbol.svg\0"
    "Istanbul M20 Line Symbol.svg\0"
    "Kayseri public transport - T3 symbol.svg\0"
    "RB32 VBB (2022).svg\0"
    "Bayern RB 50.svg\0"
    "RB21 VBB (2021).png\0"
    "RB37 VBB (2022).svg\0"
    "Linka A (Praha).svg\0"
    "Prague metro logo without padding.svg\0"
    "Linka B (Praha).svg\0"
    "Linka C (Praha).svg\0"
    "Kyiv Metro Line 3.svg\0"
    "Kyiv Metro logo.svg\0"
    "Kyiv Metro Line 1.svg\0"
    "Kyiv Metro Line 2.svg\0"
    "ChongqingMetroLine18.svg\0"
    "METROQ.svg\0"
    "Logo Tramway Bordeaux ligne D.svg\0"
    "Nanjing-Chuzhou Line logo.svg\0"
    "Santiago de Chile L9.svg\0"
    "长株潭城际西环线.svg\0"
    "XAM Line 16 icon.svg\0"
    "Logo Réseau express métropolitain.svg\0"
    "Moskwa Metro Line D3.svg\0"
    "Dankal Logo.svg\0"
    "STIB-MIVB Line 18.svg\0"
    "Moskwa Metro Line D4.svg\0"
    "RheinNeckar S8.svg\0"
    "RheinNeckar S7.svg\0"
    "RheinNeckar S39.svg\0"
    "Cercanías C5a (VerdeAM).svg\0"
    "CDML19.svg\0"
    "NaviMumbaiMetro-Logo.png\0"
    "Kayseri public transport - T4 symbol.svg\0"
    "Paris transit icons - Train V.svg\0"
    "Icono ER02.svg\0"
    "Nürnberg T11.png\0"
    "Nürnberg T10.png\0"
    "Lima Metro Linea 2 logo.svg\0"
    "Bayern RB 40 Erfurt.svg\0"
    "HCMC Metro logo.svg\0"
    "Bayern RB 40.svg\0"
    "Bayern RB 33.svg\0"
    "UPMRC.svg\0"
    "CCRT Line6 logo.svg\0"
    "Mitja distància Ca6.svg\0"
};

static const constexpr uint16_t NoLogo = 18;

static const constexpr LineMetaDataContent line_data[] = {
    { 1, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf38bb9} }, // 70 OSM: 9056 WD: Q6811967 -37.84, 144.9 x -37.81, 145.1
    { 5, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009fda} }, // 75 OSM: 9057 WD: Q6811970 -37.86, 144.9 x -37.81, 145.2
    { 8, 0, 19, LineMetaDataContent::Tramway, Color{0xbe1414} }, // M4 OSM: 11134 WD: Q62512299 52.52, 13.4 x 52.57, 13.53
    { 11, 33, 19, LineMetaDataContent::Tramway, Color{0xbe1414} }, // M5 OSM: 11135 WD: Q62512324 52.52, 13.36 x 52.57, 13.52
    { 15, 52, 19, LineMetaDataContent::Tramway, Color{0xbe1414} }, // 12 OSM: 11140 WD: Q65954567 52.52, 13.38 x 52.56, 13.47
    { 18, 71, 19, LineMetaDataContent::Tramway, Color{0xff6633} }, // M8 OSM: 11141 WD: Q62512359 52.52, 13.36 x 52.57, 13.58
    { 22, 90, 19, LineMetaDataContent::Tramway, Color{0xff6633} }, // 18 OSM: 11142 WD: Q62554449 52.52, 13.44 x 52.55, 13.62
    { 26, 109, 19, LineMetaDataContent::Tramway, Color{0x006699} }, // 16 OSM: 11143 WD: Q62476614 52.51, 13.47 x 52.57, 13.58
    { 29, 128, 19, LineMetaDataContent::Tramway, Color{0xbe1414} }, // M6 OSM: 11145 WD: Q62511960 52.52, 13.4 x 52.55, 13.62
    { 16, 147, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 2 OSM: 12016 WD: Q950776 47.47, 19.05 x 47.51, 19.08
    { 32, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xee2e27} }, // STH OSM: 14163 WD: Q7570091 -37.07, 174.8 x -36.84, 174.9
    { 36, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfdb913} }, // EAST OSM: 14165 WD: Q5330260 -37, 174.8 x -36.84, 174.9
    { 41, 196, 226, LineMetaDataContent::RapidTransit, Color{0x8070b7} }, // S7 OSM: 14809 WD: Q7388362 52.39, 13.07 x 52.57, 13.57
    { 4, 242, 226, LineMetaDataContent::RapidTransit, Color{0x8070b7} }, // S75 OSM: 14810 WD: Q3744483 52.5, 13.43 x 52.57, 13.54
    { 44, 273, 226, LineMetaDataContent::RapidTransit, Color{0xf25721} }, // S5 OSM: 14811 WD: Q3743008 52.5, 13.28 x 52.59, 13.91
    { 47, 303, 226, LineMetaDataContent::RapidTransit, Color{0x52b447} }, // S8 OSM: 14984 WD: Q4048678 52.35, 13.29 x 52.69, 13.63
    { 51, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x9313ba} }, // S2 OSM: 16111 48.95, 8.283 x 49.11, 8.505
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xb3ee3a} }, // 1 OSM: 17413 WD: Q120801440 51.49, 10.79 x 51.52, 10.8
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x2e8b57} }, // 2 OSM: 17415 WD: Q120804196 51.5, 10.78 x 51.51, 10.82
    { 60, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x996633} }, // 3 OSM: 17839 WD: Q121359743 48.99, 8.295 x 49.02, 8.444
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 1 OSM: 17840 WD: Q121359727 49, 8.347 x 49.04, 8.479
    { 54, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // S11 OSM: 17842 48.87, 8.373 x 49.13, 8.518
    { 63, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // S1 OSM: 17843 48.8, 8.373 x 49.13, 8.458
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x18a6d9} }, // 5 OSM: 17847 WD: Q121359745 49, 8.347 x 49.02, 8.463
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffcc00} }, // 4 OSM: 17848 WD: Q121359744 48.98, 8.347 x 49.05, 8.452
    { 47, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x6d682a} }, // S8 OSM: 17849 WD: Q112623864 48.44, 8.215 x 49.01, 8.83
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff9933} }, // 8 OSM: 17855 WD: Q121359748 48.98, 8.452 x 49, 8.479
    { 66, 333, 19, LineMetaDataContent::Tramway, Color{0xbe1414} }, // M10 OSM: 17865 WD: Q62500489 52.5, 13.34 x 52.54, 13.45
    { 58, 353, 19, LineMetaDataContent::Tramway, Color{0xbe1414} }, // M13 OSM: 17884 WD: Q62512599 52.51, 13.34 x 52.56, 13.48
    { 74, 373, 19, LineMetaDataContent::Tramway, Color{0x996699} }, // 21 OSM: 17885 WD: Q62476959 52.46, 13.45 x 52.53, 13.52
    { 77, 392, 410, LineMetaDataContent::RapidTransit, Color{0xeda5b4} }, // U13 OSM: 19070 WD: Q70718526 48.76, 9.134 x 48.81, 9.254
    { 82, 439, 19, LineMetaDataContent::Tramway, Color{0x009999} }, // 63 OSM: 19115 WD: Q63996601 52.43, 13.53 x 52.5, 13.61
    { 86, 458, 19, LineMetaDataContent::Tramway, Color{0x669933} }, // 61 OSM: 19265 WD: Q62512736 52.43, 13.51 x 52.46, 13.69
    { 90, 477, 19, LineMetaDataContent::Tramway, Color{0x009933} }, // 68 OSM: 19271 WD: Q62470539 52.37, 13.57 x 52.46, 13.65
    { 97, 496, 19, LineMetaDataContent::Tramway, Color{0x006633} }, // 62 OSM: 19296 WD: Q62476843 52.42, 13.57 x 52.51, 13.61
    { 102, 515, 19, LineMetaDataContent::Tramway, Color{0x993333} }, // 37 OSM: 19451 WD: Q62499413 52.46, 13.5 x 52.53, 13.53
    { 106, NoLogo, 534, LineMetaDataContent::Tramway, Color{} }, // 88 OSM: 19597 WD: Q638246 52.46, 13.63 x 52.48, 13.81
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 11 OSM: 19762 WD: Q108783975 42.66, 23.24 x 42.75, 23.32
    { 110, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 22 OSM: 19763 WD: Q108783982 42.69, 23.28 x 42.71, 23.39
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 12 OSM: 19765 WD: Q108783976 42.68, 23.31 x 42.75, 23.33
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 8 OSM: 19766 WD: Q108783965 42.69, 23.24 x 42.72, 23.32
    { 67, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 10 OSM: 19768 WD: Q108783971 42.66, 23.28 x 42.7, 23.34
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 6 OSM: 19771 WD: Q108783961 42.68, 23.27 x 42.75, 23.32
    { 60, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 3 OSM: 19777 WD: Q108783914 42.7, 23.29 x 42.73, 23.32
    { 42, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 7 OSM: 19782 WD: Q108783862 42.66, 23.28 x 42.72, 23.32
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 1 OSM: 19787 WD: Q108783893 42.68, 23.3 x 42.71, 23.32
    { 113, 552, 410, LineMetaDataContent::RapidTransit, Color{0xc7956c} }, // U1 OSM: 19916 WD: Q106879557 48.75, 9.138 x 48.81, 9.277
    { 116, 569, 410, LineMetaDataContent::RapidTransit, Color{0xf58220} }, // U2 OSM: 19917 WD: Q106879558 48.77, 9.122 x 48.83, 9.238
    { 119, 586, 410, LineMetaDataContent::RapidTransit, Color{0x935f39} }, // U3 OSM: 19918 WD: Q106879559 48.71, 9.112 x 48.73, 9.202
    { 122, 603, 410, LineMetaDataContent::RapidTransit, Color{0x7a68ae} }, // U4 OSM: 19919 WD: Q106879560 48.77, 9.158 x 48.79, 9.25
    { 125, 620, 410, LineMetaDataContent::RapidTransit, Color{0x00baf2} }, // U5 OSM: 19920 WD: Q106879561 48.7, 9.136 x 48.8, 9.187
    { 128, 637, 410, LineMetaDataContent::RapidTransit, Color{0xec008c} }, // U6 OSM: 19921 WD: Q106879562 48.69, 9.064 x 48.81, 9.192
    { 131, 654, 410, LineMetaDataContent::RapidTransit, Color{0x0eb48d} }, // U7 OSM: 19922 WD: Q106879563 48.71, 9.173 x 48.84, 9.296
    { 134, 671, 410, LineMetaDataContent::RapidTransit, Color{0xc3b47d} }, // U8 OSM: 19923 WD: Q106879564 48.71, 9.112 x 48.76, 9.296
    { 137, 688, 410, LineMetaDataContent::RapidTransit, Color{0xffd503} }, // U9 OSM: 19924 WD: Q106879565 48.76, 9.122 x 48.79, 9.254
    { 67, 705, 410, LineMetaDataContent::Tramway, Color{0xf8b710} }, // 10 OSM: 19925 WD: Q143861 48.75, 9.167 x 48.76, 9.174
    { 140, 730, 410, LineMetaDataContent::RapidTransit, Color{0xcccccc} }, // U11 OSM: 19926 WD: Q106879566 48.77, 9.168 x 48.8, 9.226
    { 14, 748, 410, LineMetaDataContent::RapidTransit, Color{0x93bbe9} }, // U12 OSM: 19927 WD: Q106879567 48.72, 9.118 x 48.87, 9.271
    { 144, 766, 410, LineMetaDataContent::RapidTransit, Color{0x69be51} }, // U14 OSM: 19928 WD: Q70723042 48.73, 9.111 x 48.84, 9.23
    { 148, 784, 410, LineMetaDataContent::RapidTransit, Color{0x005aab} }, // U15 OSM: 19929 WD: Q106879570 48.74, 9.156 x 48.85, 9.234
    { 152, 802, 410, LineMetaDataContent::RapidTransit, Color{0xcccccc} }, // U19 OSM: 19930 WD: Q106879572 48.79, 9.213 x 48.83, 9.238
    { 67, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x312783} }, // 10 OSM: 19941 WD: Q112609299 53.06, 8.752 x 53.12, 8.9
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x005ca9} }, // 2 OSM: 19942 WD: Q112609282 53.06, 8.752 x 53.12, 8.9
    { 157, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x9eb4a5} }, // 72 OSM: 20258 WD: Q6811968 -37.86, 145 x -37.8, 145.1
    { 162, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc4121a} }, // 49 OSM: 20313 WD: Q47545799 48.2, 16.26 x 48.21, 16.36
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc4121a} }, // 6 OSM: 20838 WD: Q47545889 48.17, 16.34 x 48.2, 16.4
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc4121a} }, // 1 OSM: 20839 WD: Q17348925 48.17, 16.35 x 48.22, 16.41
    { 22, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc4121a} }, // 18 OSM: 20840 WD: Q47563623 48.18, 16.34 x 48.2, 16.41
    { 138, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc4121a} }, // 9 OSM: 21046 WD: Q47545921 48.2, 16.32 x 48.23, 16.34
    { 166, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc4121a} }, // 52 OSM: 21047 WD: Q47545789 48.19, 16.27 x 48.2, 16.34
    { 67, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc4121a} }, // 10 OSM: 21055 WD: Q47563295 48.19, 16.28 x 48.23, 16.32
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf287b6} }, // 2 OSM: 22852 WD: Q56558793 54.09, 12.08 x 54.11, 12.17
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf8a500} }, // 6 OSM: 22871 WD: Q56558799 54.07, 12.09 x 54.09, 12.14
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x5d106a} }, // 1 OSM: 23389 WD: Q56558792 54.09, 12.05 x 54.16, 12.16
    { 170, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc4121a} }, // 44 OSM: 23620 WD: Q47630524 48.21, 16.31 x 48.22, 16.36
    { 60, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x690713} }, // 3 OSM: 23742 WD: Q56558795 54.07, 12.09 x 54.11, 12.18
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc30175} }, // 4 OSM: 23743 WD: Q56558796 54.07, 12.1 x 54.11, 12.18
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe2001d} }, // 5 OSM: 23747 WD: Q56558797 54.06, 12.05 x 54.16, 12.14
    { 174, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc4121a} }, // 60 OSM: 26608 WD: Q47657489 48.13, 16.26 x 48.2, 16.34
    { 122, 820, 832, LineMetaDataContent::Subway, Color{0x029540} }, // U4 OSM: 27113 WD: Q877322 48.18, 16.26 x 48.25, 16.39
    { 128, 848, 832, LineMetaDataContent::Subway, Color{0x9c6830} }, // U6 OSM: 27115 WD: Q281409 48.13, 16.31 x 48.26, 16.4
    { 178, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc4121a} }, // O OSM: 27148 WD: Q20439830 48.17, 16.36 x 48.23, 16.39
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc4121a} }, // 5 OSM: 27149 WD: Q20439827 48.2, 16.34 x 48.23, 16.39
    { 0, NoLogo, 860, LineMetaDataContent::Subway, Color{0x70b1d0} }, // U70 OSM: 27662 WD: Q121295965 51.22, 6.566 x 51.33, 6.803
    { 180, NoLogo, 860, LineMetaDataContent::Subway, Color{0x0063af} }, // U76 OSM: 27663 WD: Q121295971 51.17, 6.566 x 51.33, 6.834
    { 184, NoLogo, 860, LineMetaDataContent::Subway, Color{0x7197cf} }, // U77 OSM: 27667 WD: Q121295972 51.21, 6.735 x 51.24, 6.823
    { 188, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe94190} }, // 709 OSM: 27956 WD: Q121297876 51.19, 6.684 x 51.25, 6.855
    { 192, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xbd1616} }, // 704 OSM: 27957 WD: Q121297871 51.2, 6.78 x 51.25, 6.797
    { 196, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x7e1974} }, // 707 OSM: 27999 WD: Q121297874 51.21, 6.746 x 51.28, 6.793
    { 205, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf29eb7} }, // 708 OSM: 28000 WD: Q121297875 51.22, 6.765 x 51.25, 6.803
    { 209, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf07d00} }, // 701 OSM: 28049 WD: Q4461914 51.2, 6.778 x 51.27, 6.847
    { 213, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe30613} }, // 706 OSM: 28052 WD: Q121297873 51.2, 6.739 x 51.24, 6.812
    { 174, 874, 19, LineMetaDataContent::Tramway, Color{0x0b9ada} }, // 60 OSM: 28289 WD: Q62512766 52.44, 13.5 x 52.46, 13.64
    { 217, 893, 226, LineMetaDataContent::RapidTransit, Color{0x055a99} }, // S3 OSM: 28314 WD: Q7388282 52.43, 13.2 x 52.53, 13.75
    { 223, 923, 19, LineMetaDataContent::Tramway, Color{0x009933} }, // 67 OSM: 28352 WD: Q66459350 52.44, 13.51 x 52.46, 13.59
    { 227, 942, 19, LineMetaDataContent::Tramway, Color{0x993333} }, // 27 OSM: 28377 WD: Q66091843 52.44, 13.46 x 52.56, 13.59
    { 230, 961, 19, LineMetaDataContent::Tramway, Color{0xa6422a} }, // M17 OSM: 28391 WD: Q62512560 52.43, 13.51 x 52.57, 13.54
    { 235, 981, 19, LineMetaDataContent::Tramway, Color{0xbe1414} }, // 50 OSM: 28420 WD: Q62499869 52.54, 13.34 x 52.61, 13.43
    { 238, NoLogo, 1000, LineMetaDataContent::Subway, Color{0x009a93} }, // U79 OSM: 28424 WD: Q1272295 51.19, 6.739 x 51.47, 6.815
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 5 OSM: 29322 WD: Q108783922 42.66, 23.24 x 42.7, 23.32
    { 243, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 20 OSM: 29391 WD: Q108783981 42.66, 23.31 x 42.7, 23.42
    { 74, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x945692} }, // 21 OSM: 29440 WD: Q4415661 51.91, 4.368 x 51.94, 4.525
    { 247, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x945692} }, // 24 OSM: 29446 WD: Q14500289 51.91, 4.341 x 51.94, 4.525
    { 251, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc4121a} }, // 43 OSM: 29564 WD: Q47630223 48.21, 16.29 x 48.23, 16.36
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // 6 OSM: 30058 WD: Q122395004 49.17, 16.55 x 49.23, 16.61
    { 102, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc4121a} }, // 37 OSM: 31353 WD: Q47566702 48.21, 16.35 x 48.25, 16.36
    { 254, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc4121a} }, // 38 OSM: 31355 WD: Q47566941 48.21, 16.34 x 48.26, 16.36
    { 258, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc4121a} }, // 42 OSM: 32332 WD: Q47629937 48.21, 16.33 x 48.23, 16.36
    { 262, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc4121a} }, // 41 OSM: 32333 WD: Q47629601 48.21, 16.31 x 48.24, 16.36
    { 266, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc4121a} }, // 40 OSM: 32334 WD: Q47629313 48.21, 16.32 x 48.23, 16.36
    { 55, NoLogo, 19, LineMetaDataContent::Tramway, Color{0xd62631} }, // 11 OSM: 33897 WD: Q121350810 51.28, 12.22 x 51.4, 12.4
    { 67, NoLogo, 19, LineMetaDataContent::Tramway, Color{0xd62631} }, // 10 OSM: 33900 WD: Q121350630 51.3, 12.37 x 51.34, 12.4
    { 26, NoLogo, 19, LineMetaDataContent::Tramway, Color{0xe3000f} }, // 16 OSM: 34068 WD: Q121351163 51.3, 12.38 x 51.4, 12.4
    { 269, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x005395} }, // WLB OSM: 34086 WD: Q875199 48, 16.23 x 48.2, 16.37
    { 42, NoLogo, 19, LineMetaDataContent::Tramway, Color{0x0e4094} }, // 7 OSM: 34148 WD: Q121345153 51.34, 12.27 x 51.36, 12.48
    { 90, NoLogo, 860, LineMetaDataContent::Tramway, Color{0xcea4cb} }, // 68 OSM: 34480 WD: Q20035838 50.7, 6.985 x 50.76, 7.156
    { 63, 1019, 226, LineMetaDataContent::RapidTransit, Color{0x5c8e3c} }, // S1 OSM: 35610 WD: Q18946157 48.59, 8.861 x 48.8, 9.444
    { 51, 1055, 226, LineMetaDataContent::RapidTransit, Color{0xff2e1d} }, // S2 OSM: 35611 WD: Q66537943 48.68, 9.105 x 48.83, 9.527
    { 217, 1091, 226, LineMetaDataContent::RapidTransit, Color{0xff7d24} }, // S3 OSM: 35612 WD: Q67504621 48.69, 9.105 x 48.94, 9.426
    { 138, NoLogo, 860, LineMetaDataContent::Tramway, Color{0xe6877e} }, // 9 OSM: 36132 WD: Q63442544 50.92, 6.907 x 50.94, 7.096
    { 15, NoLogo, 860, LineMetaDataContent::Tramway, Color{0x8cc63f} }, // 12 OSM: 36133 WD: Q63442549 50.9, 6.939 x 51.03, 6.96
    { 149, NoLogo, 860, LineMetaDataContent::Tramway, Color{0x54ad4b} }, // 15 OSM: 36134 WD: Q63442560 50.92, 6.898 x 51.02, 6.966
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc4121a} }, // 2 OSM: 36362 WD: Q47545833 48.2, 16.31 x 48.24, 16.39
    { 275, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc4121a} }, // D OSM: 36371 WD: Q901027 48.18, 16.36 x 48.26, 16.39
    { 281, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xcf0a1d} }, // T1 OSM: 36937 WD: Q112391133 37.38, -5.996 x 37.39, -5.977
    { 287, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x83898f} }, // 58 OSM: 37338 WD: Q28428375 -37.84, 144.9 x -37.74, 145
    { 290, 1127, 226, LineMetaDataContent::RapidTransit, Color{0x874a0a} }, // S6 OSM: 37419 WD: Q67501804 48.76, 8.872 x 48.83, 9.195
    { 294, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc4121a} }, // 46 OSM: 38368 WD: Q47631053 48.21, 16.3 x 48.21, 16.36
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc4121a} }, // 11 OSM: 38482 WD: Q70516548 48.15, 16.35 x 48.18, 16.47
    { 281, NoLogo, 1163, LineMetaDataContent::Tramway, Color{0xff0000} }, // T1 OSM: 38872 WD: Q5985908 28.45, -16.32 x 28.49, -16.25
    { 149, NoLogo, 19, LineMetaDataContent::Tramway, Color{0x0e4094} }, // 15 OSM: 38883 WD: Q98379997 51.29, 12.26 x 51.34, 12.44
    { 298, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc8d300} }, // 65 OSM: 39079 WD: Q20035842 50.72, 7.071 x 50.76, 7.156
    { 27, 1201, NoLogo, LineMetaDataContent::Tramway, Color{0x9049a8} }, // 6 OSM: 48024 WD: Q62296933 52.13, 11.57 x 52.15, 11.68
    { 56, 1229, NoLogo, LineMetaDataContent::Tramway, Color{0xb6005c} }, // 1 OSM: 48025 WD: Q62289804 52.11, 11.59 x 52.17, 11.64
    { 9, 1257, NoLogo, LineMetaDataContent::Tramway, Color{0x73e700} }, // 4 OSM: 48453 WD: Q62295350 52.11, 11.58 x 52.16, 11.67
    { 6, 1285, NoLogo, LineMetaDataContent::Tramway, Color{0xb48654} }, // 5 OSM: 48459 WD: Q62296384 52.09, 11.58 x 52.16, 11.62
    { 138, NoLogo, 1313, LineMetaDataContent::Tramway, Color{0x808080} }, // 9 OSM: 49277 WD: Q5770109 34.39, 132.5 x 34.4, 132.5
    { 302, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc4121a} }, // 71 OSM: 51076 WD: Q42297591 48.15, 16.36 x 48.22, 16.47
    { 271, 1334, 1356, LineMetaDataContent::RapidTransit, Color{0x32cd32} }, // B OSM: 51750 WD: Q1903862 55.65, 12.27 x 55.81, 12.59
    { 56, NoLogo, 19, LineMetaDataContent::Tramway, Color{0x62b32c} }, // 1 OSM: 51858 WD: Q121343878 51.31, 12.26 x 51.35, 12.41
    { 128, 1366, 1396, LineMetaDataContent::Subway, Color{0x8c6dab} }, // U6 OSM: 51942 WD: Q99720 52.44, 13.33 x 52.56, 13.39
    { 56, 1407, NoLogo, LineMetaDataContent::Tramway, Color{0xffffff} }, // 1 OSM: 52282 WD: Q106921117 57.64, 11.9 x 57.73, 12.05
    { 6, 1429, NoLogo, LineMetaDataContent::Tramway, Color{0xeb1923} }, // 5 OSM: 52617 WD: Q106921184 57.7, 11.89 x 57.74, 12.05
    { 42, 1451, NoLogo, LineMetaDataContent::Tramway, Color{0x7d4313} }, // 7 OSM: 53027 WD: Q10562726 57.64, 11.9 x 57.76, 12.07
    { 47, 1473, 226, LineMetaDataContent::RapidTransit, Color{0xffc734} }, // S8 OSM: 53231 WD: Q17148488 48, 11.17 x 48.35, 11.79
    { 306, 1489, 226, LineMetaDataContent::RapidTransit, Color{0xff2d1d} }, // S4 OSM: 53235 WD: Q7388308 48.04, 11.04 x 48.18, 11.97
    { 27, 1505, NoLogo, LineMetaDataContent::Tramway, Color{0xfa8719} }, // 6 OSM: 53254 WD: Q10562724 57.68, 11.89 x 57.76, 12.04
    { 138, 1527, NoLogo, LineMetaDataContent::Tramway, Color{0x1e8164} }, // 9 OSM: 53748 WD: Q62299846 52.08, 11.6 x 52.18, 11.64
    { 16, 1555, NoLogo, LineMetaDataContent::Tramway, Color{0x004799} }, // 2 OSM: 53752 WD: Q62291398 52.06, 11.63 x 52.15, 11.68
    { 19, 1583, NoLogo, LineMetaDataContent::Tramway, Color{0xf29400} }, // 8 OSM: 53770 WD: Q62299313 52.06, 11.63 x 52.18, 11.68
    { 290, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x3d2d7c} }, // S6 OSM: 53844 WD: Q106378407 48.75, 8.549 x 48.9, 8.705
    { 310, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc4121a} }, // 26 OSM: 53994 WD: Q47564171 48.23, 16.38 x 48.29, 16.49
    { 67, 1611, NoLogo, LineMetaDataContent::Tramway, Color{0xaac1e1} }, // 10 OSM: 54125 WD: Q62288523 52.11, 11.59 x 52.21, 11.67
    { 67, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x9acd32} }, // 10 OSM: 54452 WD: Q116487045 51.49, 10.77 x 51.58, 10.8
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xda0873} }, // 1 OSM: 54602 WD: Q121360083 53.59, 11.41 x 53.65, 11.47
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xd9261c} }, // 2 OSM: 54603 WD: Q121360084 53.59, 11.36 x 53.65, 11.47
    { 60, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe87878} }, // 3 OSM: 54604 WD: Q121360085 53.57, 11.38 x 53.6, 11.47
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xdb214c} }, // 4 OSM: 54605 WD: Q121360086 53.57, 11.38 x 53.65, 11.43
    { 60, 1640, NoLogo, LineMetaDataContent::Tramway, Color{0xffd600} }, // 3 OSM: 55097 WD: Q62292031 52.09, 11.58 x 52.16, 11.63
    { 313, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x408040} }, // S 1 OSM: 55107 WD: Q56378592 52, 11.62 x 53.01, 11.87
    { 97, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc4121a} }, // 62 OSM: 56814 WD: Q47671923 48.16, 16.27 x 48.2, 16.37
    { 44, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // S5 OSM: 56923 WD: Q319443 48.03, 7.589 x 48.16, 7.77
    { 137, 1668, 1396, LineMetaDataContent::Subway, Color{0xf3791d} }, // U9 OSM: 58423 WD: Q99744 52.46, 13.32 x 52.56, 13.37
    { 134, 1698, 1396, LineMetaDataContent::Subway, Color{0x224f86} }, // U8 OSM: 58424 WD: Q99729 52.47, 13.33 x 52.6, 13.43
    { 131, 1728, 1396, LineMetaDataContent::Subway, Color{0x528dba} }, // U7 OSM: 58425 WD: Q99725 52.42, 13.2 x 52.54, 13.5
    { 119, 1758, 1396, LineMetaDataContent::Subway, Color{0x16683d} }, // U3 OSM: 58426 WD: Q99702 52.44, 13.24 x 52.51, 13.45
    { 116, 1788, 1396, LineMetaDataContent::Subway, Color{0xda421e} }, // U2 OSM: 58428 WD: Q99697 52.5, 13.24 x 52.57, 13.41
    { 122, 1818, 1396, LineMetaDataContent::Subway, Color{0xf0d722} }, // U4 OSM: 58429 WD: Q99708 52.48, 13.34 x 52.5, 13.36
    { 125, 1848, 1396, LineMetaDataContent::Subway, Color{0x7e5330} }, // U5 OSM: 58430 WD: Q99711 52.49, 13.37 x 52.54, 13.63
    { 113, 1878, 1396, LineMetaDataContent::Subway, Color{0x7dad4c} }, // U1 OSM: 58767 WD: Q99691 52.5, 13.33 x 52.51, 13.45
    { 19, NoLogo, 19, LineMetaDataContent::Tramway, Color{0xffcc00} }, // 8 OSM: 58819 WD: Q121345179 51.32, 12.28 x 51.36, 12.47
    { 60, NoLogo, 19, LineMetaDataContent::Tramway, Color{0x62b32c} }, // 3 OSM: 58829 WD: Q121344175 51.31, 12.28 x 51.38, 12.49
    { 6, 1908, 1925, LineMetaDataContent::Tramway, Color{0x8b539d} }, // 5 OSM: 61453 WD: Q104867893 49.41, 11.07 x 49.46, 11.14
    { 231, 1949, 19, LineMetaDataContent::Tramway, Color{0x865a46} }, // 17 OSM: 61454 WD: Q20438593 48.13, 11.49 x 48.17, 11.57
    { 153, 1970, 19, LineMetaDataContent::Tramway, Color{0xdc281e} }, // 19 OSM: 61456 WD: Q20438608 48.14, 11.46 x 48.15, 11.63
    { 22, 1991, 19, LineMetaDataContent::Tramway, Color{0x00a03c} }, // 18 OSM: 61458 WD: Q20438601 48.1, 11.49 x 48.14, 11.6
    { 317, NoLogo, 19, LineMetaDataContent::Tramway, Color{0x865a46} }, // N17 OSM: 61459 WD: Q123336308 48.13, 11.56 x 48.15, 11.61
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf78a21} }, // 1 OSM: 61460 WD: Q121304774 50.85, 12.07 x 50.89, 12.09
    { 51, 2012, 226, LineMetaDataContent::RapidTransit, Color{0x018a47} }, // S2 OSM: 61466 WD: Q3743635 52.34, 13.36 x 52.68, 13.59
    { 321, 2042, 226, LineMetaDataContent::RapidTransit, Color{0x018a47} }, // S25 OSM: 61469 WD: Q7388229 52.4, 13.21 x 52.64, 13.4
    { 119, 2073, 1396, LineMetaDataContent::Subway, Color{0xfcdf00} }, // U3 OSM: 62839 WD: Q781351 53.54, 9.969 x 53.59, 10.08
    { 326, 2088, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe18813} }, // J OSM: 63222 WD: Q6109356 37.72, -122.4 x 37.79, -122.4
    { 329, 2106, NoLogo, LineMetaDataContent::Tramway, Color{0xf0e68c} }, // F OSM: 63224 WD: Q1137818 37.76, -122.4 x 37.81, -122.4
    { 332, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc4121a} }, // 33 OSM: 63565 WD: Q47566422 48.21, 16.34 x 48.24, 16.38
    { 63, 2134, 226, LineMetaDataContent::RapidTransit, Color{0x36caec} }, // S1 OSM: 63809 WD: Q7388207 48.13, 11.48 x 48.4, 11.79
    { 290, 2150, 226, LineMetaDataContent::RapidTransit, Color{0x00ac6f} }, // S6 OSM: 63839 WD: Q7388348 47.91, 11.27 x 48.15, 11.97
    { 60, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff7f00} }, // 3 OSM: 63875 WD: Q121287743 51.82, 12.18 x 51.84, 12.24
    { 293, 2166, 226, LineMetaDataContent::RapidTransit, Color{0xba8a4d} }, // S46 OSM: 64094 WD: Q3737194 52.3, 13.28 x 52.52, 13.64
    { 335, 2200, 226, LineMetaDataContent::RapidTransit, Color{0xba8a4d} }, // S45 OSM: 64095 WD: Q2090939 52.36, 13.36 x 52.48, 13.57
    { 322, 2231, 19, LineMetaDataContent::Tramway, Color{0xe6828c} }, // 25 OSM: 66008 WD: Q20439051 48.04, 11.52 x 48.14, 11.6
    { 15, 2252, 19, LineMetaDataContent::Tramway, Color{0x903f98} }, // 12 OSM: 66043 WD: Q20438570 48.15, 11.49 x 48.17, 11.58
    { 26, 2273, 19, LineMetaDataContent::Tramway, Color{0x006cb2} }, // 16 OSM: 66044 WD: Q20438583 48.13, 11.51 x 48.18, 11.64
    { 227, 2294, 19, LineMetaDataContent::Tramway, Color{0xf0a014} }, // 27 OSM: 66053 WD: Q20439073 48.13, 11.56 x 48.18, 11.58
    { 243, 2315, 19, LineMetaDataContent::Tramway, Color{0x00aadc} }, // 20 OSM: 66079 WD: Q20438843 48.14, 11.51 x 48.18, 11.56
    { 74, 2336, 19, LineMetaDataContent::Tramway, Color{0x00aadc} }, // 21 OSM: 66080 WD: Q20439015 48.12, 11.53 x 48.17, 11.64
    { 341, 2364, 19, LineMetaDataContent::Tramway, Color{0x96c81e} }, // 23 OSM: 66100 WD: Q20439033 48.16, 11.59 x 48.19, 11.59
    { 344, 2385, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe67310} }, // A3 OSM: 66588 WD: Q19606155 53.75, 9.656 x 53.8, 9.983
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 4 OSM: 66741 WD: Q121338665 49.77, 9.893 x 49.8, 9.94
    { 306, 2400, 226, LineMetaDataContent::RapidTransit, Color{0x0065b7} }, // S4 OSM: 66840 WD: Q67504669 48.77, 9.155 x 48.95, 9.426
    { 347, 2436, 2455, LineMetaDataContent::RapidTransit, Color{0x8d1d81} }, // S51 OSM: 67184 WD: Q116125186 46.7, 15.63 x 46.73, 15.99
    { 352, 2474, 19, LineMetaDataContent::Tramway, Color{0xbe1414} }, // M1 OSM: 67233 WD: Q62512139 52.52, 13.37 x 52.6, 13.41
    { 44, 2493, 226, LineMetaDataContent::RapidTransit, Color{0x00b7e1} }, // S5 OSM: 67283 WD: Q18926034 48.77, 9.122 x 48.95, 9.195
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x1074bc} }, // 4 OSM: 68612 WD: Q124656079 49.86, 8.555 x 49.9, 8.683
    { 60, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf59e00} }, // 3 OSM: 69178 WD: Q121310314 47.97, 7.796 x 48, 7.85
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe8001b} }, // 1 OSM: 69191 WD: Q121309531 47.98, 7.808 x 48.03, 7.895
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008bc5} }, // 5 OSM: 69199 WD: Q121310770 47.99, 7.788 x 48, 7.852
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x13a538} }, // 2 OSM: 69202 WD: Q121310201 47.96, 7.833 x 48.02, 7.858
    { 359, NoLogo, 2529, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // Blue OSM: 71390 WD: Q6714611 45.49, -123 x 45.54, -122.4
    { 364, NoLogo, 2529, LineMetaDataContent::RapidTransit, Color{0xffff00} }, // Yellow OSM: 71397 WD: Q6714624 45.51, -122.7 x 45.61, -122.7
    { 371, NoLogo, 2529, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // Red OSM: 71404 WD: Q6714623 45.49, -122.8 x 45.59, -122.6
    { 54, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // S11 OSM: 71595 47.86, 7.701 x 48.16, 8.504
    { 217, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // S3 OSM: 71656 WD: Q895607 47.85, 7.698 x 48, 7.843
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf6a6ab} }, // 1 OSM: 71785 WD: Q106996879 47.25, 11.39 x 47.28, 11.41
    { 60, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xd66775} }, // 3 OSM: 71787 WD: Q106996895 47.26, 11.39 x 47.27, 11.43
    { 375, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xee1d23} }, // 501 OSM: 72291 WD: Q3238944 43.59, -79.54 x 43.67, -79.28
    { 379, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xee1d23} }, // 503 OSM: 72293 WD: Q4639788 43.65, -79.38 x 43.68, -79.28
    { 9, 2549, 1925, LineMetaDataContent::Tramway, Color{0xf3898f} }, // 4 OSM: 72527 WD: Q104867838 49.43, 11.05 x 49.49, 11.07
    { 19, 2566, 1925, LineMetaDataContent::Tramway, Color{0x00bbfe} }, // 8 OSM: 73226 WD: Q104868033 49.43, 11.08 x 49.47, 11.14
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfbba00} }, // 1 OSM: 73662 WD: Q61888705 51.45, 11.94 x 51.51, 11.99
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff9900} }, // 2 OSM: 73667 WD: Q61889098 51.43, 11.89 x 51.49, 11.99
    { 60, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0066cc} }, // 3 OSM: 73670 WD: Q61887067 51.43, 11.96 x 51.52, 11.99
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x9b1006} }, // 4 OSM: 73671 WD: Q61889270 51.44, 11.93 x 51.51, 11.99
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0f3f93} }, // 5 OSM: 73672 WD: Q61889316 51.29, 11.93 x 51.51, 12.07
    { 42, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff6699} }, // 7 OSM: 73929 WD: Q61889355 51.48, 11.93 x 51.51, 12.04
    { 138, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x999933} }, // 9 OSM: 73932 WD: Q61889418 51.48, 11.89 x 51.48, 11.99
    { 67, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x336633} }, // 10 OSM: 73933 WD: Q61889438 51.48, 11.9 x 51.49, 11.99
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x228b22} }, // 6 OSM: 75919 WD: Q121537242 53.85, 27.58 x 53.95, 27.63
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000cd} }, // 5 OSM: 75939 WD: Q121537241 53.91, 27.54 x 53.95, 27.62
    { 54, 2583, 2455, LineMetaDataContent::RapidTransit, Color{0x00983a} }, // S11 OSM: 76229 WD: Q116125180 47.2, 15.24 x 47.23, 15.34
    { 386, NoLogo, 2602, LineMetaDataContent::Tramway, Color{0xe30613} }, // 89 OSM: 77259 WD: Q68081929 52.53, 13.84 x 52.58, 13.88
    { 63, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x9a2a23} }, // S1 OSM: 77908 WD: Q7388209 49.27, 10.9 x 49.9, 11.46
    { 51, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x65b949} }, // S2 OSM: 77962 WD: Q7388248 49.24, 11.04 x 49.51, 11.56
    { 217, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0xff561d} }, // S3 OSM: 77971 WD: Q7388284 49.38, 11.08 x 49.45, 11.35
    { 60, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xef1c29} }, // 3 OSM: 78206 WD: Q121304819 50.84, 12.05 x 50.91, 12.1
    { 60, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x4098de} }, // 3 OSM: 79325 WD: Q60318542 51.72, 14.3 x 51.76, 14.35
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xa81a30} }, // 6 OSM: 89518 WD: Q1664234 47.23, 11.4 x 47.26, 11.44
    { 290, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x0066b3} }, // S6 OSM: 91626 WD: Q115646650 46.9, 7.778 x 47.22, 8.31
    { 41, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x78b6e4} }, // S7 OSM: 91629 WD: Q115646652 47.06, 7.778 x 47.22, 8.082
    { 389, 2634, NoLogo, LineMetaDataContent::LocalTrain, Color{0xe50000} }, // RE 30 OSM: 93946 WD: Q113462371 49.44, 11.08 x 49.95, 11.63
    { 395, 2651, NoLogo, LineMetaDataContent::LocalTrain, Color{0xf09280} }, // RB 12 OSM: 100360 WD: Q114717482 49.44, 10.66 x 49.51, 11.09
    { 9, 2668, 2701, LineMetaDataContent::Subway, Color{0x800080} }, // 4 OSM: 102389 WD: Q54373 43.76, -79.41 x 43.78, -79.35
    { 177, 2744, 2771, LineMetaDataContent::RapidTransit, Color{0xef7b10} }, // LO OSM: 112649 WD: Q1854601 51.46, -0.3961 x 51.66, 0.1233
    { 403, 2794, 2826, LineMetaDataContent::RapidTransit, Color{0xfcd946} }, // C OSM: 122886 WD: Q200906 48.43, 1.995 x 49.05, 2.427
    { 405, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x37bbed} }, // LS OSM: 129379 WD: Q15982573 -35.19, -59.43 x -34.58, -58.41
    { 408, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x37bbed} }, // LSM OSM: 129382 WD: Q3239199 -34.61, -59.08 x -34.45, -58.37
    { 412, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x37bbed} }, // LM OSM: 129383 WD: Q66759479 -34.59, -59.04 x -34.1, -58.37
    { 415, 2856, NoLogo, LineMetaDataContent::RapidTransit, Color{0xef3e33} }, // LU OSM: 129393 WD: Q7887242 -34.6, -58.7 x -34.53, -58.46
    { 421, 2886, 2914, LineMetaDataContent::Tramway, Color{0xf38733} }, // P OSM: 129505 WD: Q3409024 -34.69, -58.47 x -34.64, -58.44
    { 226, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf0a014} }, // N27 OSM: 129569 48.08, 11.55 x 48.18, 11.59
    { 426, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe33385} }, // 96 OSM: 132386 WD: Q12061652 -37.87, 145 x -37.77, 145
    { 429, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfeba10} }, // 86 OSM: 137969 WD: Q12061650 -37.82, 144.9 x -37.68, 145.1
    { 22, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 18 OSM: 139323 WD: Q108783978 42.68, 23.32 x 42.72, 23.34
    { 60, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x88d1f0} }, // 3 OSM: 144407 WD: Q6811954 -37.89, 145 x -37.8, 145.1
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe04038} }, // 5 OSM: 145649 WD: Q6811959 -37.87, 145 x -37.8, 145.1
    { 162, 2929, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 49 OSM: 147322 WD: Q1491114 47.47, 19.02 x 47.5, 19.06
    { 433, 2953, 2965, LineMetaDataContent::Subway, Color{0xfdc110} }, // M2 OSM: 152340 WD: Q1880954 55.63, 12.49 x 55.69, 12.65
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009640} }, // 1 OSM: 153893 WD: Q104796303 53.04, 8.741 x 53.09, 8.965
    { 436, 2991, NoLogo, LineMetaDataContent::LocalTrain, Color{0x2a89ca} }, // RB 80 OSM: 158860 WD: Q114713941 49.66, 9.933 x 49.8, 10.15
    { 44, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x23c4fc} }, // S5 OSM: 160986 WD: Q55632180 49.26, 11.08 x 49.45, 11.21
    { 442, 3008, NoLogo, LineMetaDataContent::LocalTrain, Color{0x5d97ce} }, // RB 81 OSM: 161886 WD: Q107110025 49.45, 10.27 x 49.58, 10.59
    { 56, 3025, 3025, LineMetaDataContent::Tramway, Color{0xec008c} }, // 1 OSM: 163714 WD: Q104534472 52.47, -2.125 x 52.59, -1.896
    { 15, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x98002e} }, // 12 OSM: 163759 43.11, -79.89 x 43.65, -79.06
    { 410, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x004595} }, // M OSM: 165610 WD: Q55079952 49.39, 1.042 x 49.45, 1.106
    { 352, 3064, 3088, LineMetaDataContent::Subway, Color{0x0075be} }, // M1 OSM: 165613 WD: Q3238660 43.29, 5.374 x 43.33, 5.43
    { 433, 3120, 3088, LineMetaDataContent::Subway, Color{0xe30513} }, // M2 OSM: 165618 WD: Q3238804 43.27, 5.367 x 43.33, 5.403
    { 451, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x49805b} }, // 59 OSM: 167658 WD: Q6811962 -37.82, 144.9 x -37.71, 145
    { 461, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x6ccff6} }, // Bay OSM: 168229 51.47, -3.172 x 51.48, -3.167
    { 474, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf0af11} }, // City OSM: 168230 51.47, -3.249 x 51.52, -3.17
    { 479, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xee4b95} }, // TL12 OSM: 168327 WD: Q125903429 51.36, -0.3277 x 51.75, -0.0954
    { 484, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xee4b95} }, // TL11 OSM: 168327 WD: Q125903429 51.36, -0.3277 x 51.75, -0.0954
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x003828} }, // 1 OSM: 170076 WD: Q110883264 52.92, -1.263 x 53.04, -1.145
    { 489, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x42816b} }, // 181 (SN) OSM: 172834 51.28, -0.1728 x 51.49, -0.07193
    { 364, NoLogo, 3144, LineMetaDataContent::RapidTransit, Color{0xd39f06} }, // Yellow OSM: 172864 WD: Q19960799 54.95, -1.623 x 55.04, -1.429
    { 60, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x78ccc9} }, // 3 OSM: 173596 50.43, 30.37 x 50.45, 30.49
    { 149, NoLogo, 3169, LineMetaDataContent::Tramway, Color{0xce1417} }, // 15 OSM: 174237 WD: Q123344569 50.42, 30.41 x 50.46, 30.49
    { 498, 3194, 226, LineMetaDataContent::RapidTransit, Color{0x52b447} }, // S85 OSM: 175267 WD: Q4048677 52.41, 13.32 x 52.61, 13.58
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xb7cbd8} }, // 2 OSM: 176853 WD: Q120720200 50.05, 19.91 x 50.07, 19.96
    { 19, 3225, NoLogo, LineMetaDataContent::Tramway, Color{0x82cee6} }, // 8 OSM: 178504 WD: Q18638820 39.46, -0.339 x 39.46, -0.3254
    { 27, 3256, NoLogo, LineMetaDataContent::Tramway, Color{0x9b70cb} }, // 6 OSM: 178505 WD: Q3832664 39.46, -0.3726 x 39.5, -0.3256
    { 9, 3287, NoLogo, LineMetaDataContent::Tramway, Color{0x004a99} }, // 4 OSM: 178506 WD: Q3238939 39.47, -0.4364 x 39.53, -0.3256
    { 6, 3318, NoLogo, LineMetaDataContent::Subway, Color{0x009870} }, // 5 OSM: 178522 WD: Q3238965 39.46, -0.4744 x 39.49, -0.3383
    { 60, 3349, NoLogo, LineMetaDataContent::Subway, Color{0xdd052b} }, // 3 OSM: 178523 WD: Q3238906 39.47, -0.4744 x 39.59, -0.33
    { 56, 3380, NoLogo, LineMetaDataContent::Subway, Color{0xfdc600} }, // 1 OSM: 178526 WD: Q2165952 39.08, -0.5268 x 39.59, -0.3815
    { 22, NoLogo, 3169, LineMetaDataContent::Tramway, Color{0xce1417} }, // 18 OSM: 179505 WD: Q123339549 50.44, 30.48 x 50.47, 30.52
    { 503, 3411, 3439, LineMetaDataContent::Tramway, Color{0xc19dc2} }, // L4 OSM: 190184 WD: Q5474600 38.35, -0.4911 x 38.38, -0.4118
    { 507, 3480, 3439, LineMetaDataContent::Tramway, Color{0xd72028} }, // L1 OSM: 190196 WD: Q594538 38.35, -0.4911 x 38.55, -0.1348
    { 511, NoLogo, 3439, LineMetaDataContent::Tramway, Color{0x00ff00} }, // L2 OSM: 190199 WD: Q9025903 38.35, -0.5172 x 38.39, -0.4678
    { 515, NoLogo, 3439, LineMetaDataContent::Tramway, Color{0xf9d114} }, // L3 OSM: 190203 WD: Q9025931 38.35, -0.4911 x 38.43, -0.3952
    { 518, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf58122} }, // 109 OSM: 190802 WD: Q6811947 -37.84, 144.9 x -37.81, 145.1
    { 403, 3508, 1356, LineMetaDataContent::RapidTransit, Color{0xffa500} }, // C OSM: 191280 WD: Q4452746 55.66, 12.07 x 55.84, 12.59
    { 34, 3530, 1356, LineMetaDataContent::RapidTransit, Color{0xe64415} }, // H OSM: 191281 WD: Q1891933 55.66, 12.36 x 55.73, 12.59
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfff101} }, // 1 OSM: 194681 WD: Q109558646 52.32, 14.53 x 52.34, 14.56
    { 60, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf36f42} }, // 3 OSM: 194690 WD: Q109558673 52.29, 14.47 x 52.34, 14.56
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xcc693a} }, // 5 OSM: 195194 WD: Q109558671 52.32, 14.5 x 52.35, 14.55
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xb368ab} }, // 4 OSM: 195195 WD: Q109558672 52.29, 14.47 x 52.36, 14.55
    { 523, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x33bdca} }, // 57 OSM: 196209 WD: Q16926803 -37.82, 144.9 x -37.77, 145
    { 465, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x015dab} }, // Atlantic City OSM: 206515 WD: Q756350 39.36, -75.2 x 40.01, -74.44
    { 526, 3552, 3582, LineMetaDataContent::RapidTransit, Color{0xff6600} }, // C7 OSM: 207184 WD: Q27976587 43.35, -6.113 x 43.55, -5.676
    { 529, 3601, 3582, LineMetaDataContent::RapidTransit, Color{0x5599ff} }, // C-8 OSM: 207192 WD: Q27976836 43.12, -5.829 x 43.28, -5.566
    { 9, NoLogo, 19, LineMetaDataContent::Tramway, Color{0x0e4094} }, // 4 OSM: 207342 WD: Q68574879 51.32, 12.32 x 51.37, 12.43
    { 534, NoLogo, 19, LineMetaDataContent::Tramway, Color{0x0e4094} }, // 4E OSM: 207342 WD: Q68574879 51.32, 12.32 x 51.37, 12.43
    { 537, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00a5e3} }, // North Jersey Coast OSM: 207401 WD: Q7055732 40.07, -74.29 x 40.77, -73.99
    { 16, 3632, NoLogo, LineMetaDataContent::Subway, Color{0x97d700} }, // 2 OSM: 207417 WD: Q1325437 31.15, 121.3 x 31.24, 121.8
    { 559, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x434244} }, // 48 OSM: 207445 WD: Q16926797 -37.82, 144.9 x -37.79, 145.1
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 1 OSM: 207718 WD: Q121590538 45.55, 18.62 x 45.57, 18.73
    { 416, 3641, 3675, LineMetaDataContent::RapidTransit, Color{0xb90845} }, // U OSM: 215565 WD: Q93559 48.76, 1.943 x 48.89, 2.237
    { 16, NoLogo, 3707, LineMetaDataContent::Tramway, Color{0xce1417} }, // 2 OSM: 227555 WD: Q123224636 56.31, 43.98 x 56.33, 44.03
    { 42, 3724, NoLogo, LineMetaDataContent::Subway, Color{0xff6900} }, // 7 OSM: 228608 WD: Q2707909 31.17, 121.3 x 31.41, 121.6
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffff00} }, // 8 OSM: 237270 WD: Q106673737 49.17, 16.55 x 49.21, 16.69
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00ff00} }, // 2 OSM: 237285 WD: Q122395000 49.13, 16.59 x 49.2, 16.64
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 1 OSM: 237306 WD: Q122394999 49.19, 16.51 x 49.25, 16.61
    { 60, NoLogo, 3707, LineMetaDataContent::Tramway, Color{0xce1417} }, // 3 OSM: 240614 WD: Q123224637 56.27, 43.92 x 56.32, 43.95
    { 6, NoLogo, 3707, LineMetaDataContent::Tramway, Color{0xce1417} }, // 5 OSM: 240615 WD: Q123337615 56.26, 43.97 x 56.32, 44
    { 19, NoLogo, 3707, LineMetaDataContent::Tramway, Color{0xce1417} }, // 8 OSM: 240656 WD: Q123224638 56.21, 43.77 x 56.28, 43.91
    { 22, NoLogo, 3707, LineMetaDataContent::Tramway, Color{0xce1417} }, // 18 OSM: 240658 WD: Q123224642 56.29, 43.99 x 56.31, 44.03
    { 153, NoLogo, 3707, LineMetaDataContent::Tramway, Color{0xce1417} }, // 19 OSM: 240659 WD: Q123337413 56.26, 43.97 x 56.3, 44.05
    { 74, NoLogo, 3707, LineMetaDataContent::Tramway, Color{0xce1417} }, // 21 OSM: 240660 WD: Q123224643 56.27, 43.92 x 56.32, 44.01
    { 110, NoLogo, 3707, LineMetaDataContent::Tramway, Color{0xce1417} }, // 22 OSM: 240661 WD: Q123224644 56.25, 43.84 x 56.27, 43.9
    { 227, NoLogo, 3707, LineMetaDataContent::Tramway, Color{0xce1417} }, // 27 OSM: 240662 WD: Q123224645 56.3, 43.94 x 56.32, 44.05
    { 562, NoLogo, 3707, LineMetaDataContent::Tramway, Color{0xce1417} }, // 417 OSM: 240666 WD: Q123224646 56.24, 43.83 x 56.32, 43.95
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x648fa8} }, // 12 OSM: 241383 WD: Q1759931 59.32, 17.92 x 59.33, 17.98
    { 392, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xd77d00} }, // 30 OSM: 241384 WD: Q1760190 59.29, 17.96 x 59.36, 18.12
    { 251, 3733, 3762, LineMetaDataContent::RapidTransit, Color{0xf166a7} }, // 43 OSM: 241411 WD: Q106806959 58.9, 17.53 x 59.57, 18.16
    { 262, 3733, 3762, LineMetaDataContent::RapidTransit, Color{0xf166a7} }, // 41 OSM: 241413 WD: Q106806951 59.17, 17.63 x 59.63, 18.07
    { 559, 3733, 3762, LineMetaDataContent::RapidTransit, Color{0xf166a7} }, // 48 OSM: 241414 WD: Q106808255 59.04, 17.31 x 59.19, 17.65
    { 567, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x37bbed} }, // TS OSM: 252385 WD: Q802144 -31.42, -64.54 x -30.86, -64.17
    { 572, 3797, 3675, LineMetaDataContent::RapidTransit, Color{0x9f9825} }, // K OSM: 253357 WD: Q93382 48.88, 2.352 x 49.23, 2.887
    { 574, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x007dc5} }, // ISL OSM: 269670 WD: Q989316 22.26, 114.1 x 22.29, 114.2
    { 578, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xf7943e} }, // TCL OSM: 269671 WD: Q989358 22.28, 113.9 x 22.36, 114.2
    { 583, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 3R OSM: 271365 WD: Q122617995 47.03, 21.92 x 47.07, 21.96
    { 586, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x00888a} }, // AEL OSM: 272078 WD: Q409036 22.29, 113.9 x 22.36, 114.2
    { 590, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x53b7e8} }, // EAL OSM: 272132 WD: Q989339 22.28, 114.1 x 22.53, 114.2
    { 594, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x923011} }, // TML OSM: 272133 WD: Q5329661 22.29, 114 x 22.45, 114.2
    { 313, 3831, NoLogo, LineMetaDataContent::Tramway, Color{0xef7c00} }, // S 1 OSM: 273002 WD: Q65643711 49.11, 6.891 x 49.41, 7.069
    { 598, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff7e00} }, // 28E OSM: 274460 WD: Q63034669 38.71, -9.17 x 38.72, -9.128
    { 602, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf7bf56} }, // Belfast-Bangor OSM: 275877 WD: Q3743313 54.59, -5.945 x 54.67, -5.671
    { 617, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xd85054} }, // Belfast-Larne OSM: 275882 WD: Q3743316 54.59, -5.945 x 54.85, -5.709
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // 2 OSM: 284941 WD: Q121832844 53.01, 18.55 x 53.04, 18.67
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // 2 OSM: 300207 48.46, 34.61 x 48.52, 34.69
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff00ff} }, // 1 OSM: 300208 48.51, 34.57 x 48.52, 34.62
    { 631, 3849, 226, LineMetaDataContent::RapidTransit, Color{0x9a3052} }, // S9 OSM: 304163 WD: Q4048680 52.36, 13.2 x 52.53, 13.57
    { 639, NoLogo, 2529, LineMetaDataContent::RapidTransit, Color{0x008000} }, // Green OSM: 304623 WD: Q6714613 45.44, -122.7 x 45.54, -122.6
    { 646, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x2774b9} }, // 39 OSM: 309018 WD: Q17355356 45.41, 28.01 x 45.47, 28.03
    { 352, 3879, 3891, LineMetaDataContent::Subway, Color{0x0000ff} }, // M1 OSM: 309619 WD: Q17462780 52.13, 20.93 x 52.29, 21.07
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 1 OSM: 311323 WD: Q123221543 48.44, 35.02 x 48.48, 35.07
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 11 OSM: 311324 WD: Q123221548 48.42, 34.98 x 48.48, 35.02
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x75c5f0} }, // 1 OSM: 318878 WD: Q122216449 53.12, 17.96 x 53.15, 18.03
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x28166f} }, // 2 OSM: 318879 WD: Q122216450 53.1, 18 x 53.15, 18.06
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x9dcd17} }, // 4 OSM: 318886 WD: Q122216452 53.1, 18 x 53.15, 18.05
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00993d} }, // 6 OSM: 318887 WD: Q122216454 53.1, 18 x 53.15, 18.11
    { 60, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 3 OSM: 318897 WD: Q122216451 53.12, 17.96 x 53.18, 18.17
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8f5144} }, // 8 OSM: 318898 WD: Q122216456 53.1, 17.99 x 53.14, 18.06
    { 42, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff6600} }, // 7 OSM: 319125 WD: Q122216455 53.1, 18.03 x 53.18, 18.17
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 2 OSM: 337341 WD: Q99494736 49.79, 9.892 x 49.8, 9.936
    { 631, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf49ac1} }, // S9 OSM: 349282 47.3, 9.039 x 47.46, 9.088
    { 421, NoLogo, 3913, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // P OSM: 357191 WD: Q118874962 60.17, 24.84 x 60.33, 25.06
    { 649, 3948, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // C-1 OSM: 357967 WD: Q3239078 43.25, -3.03 x 43.33, -2.928
    { 42, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x2774b9} }, // 7 OSM: 358090 WD: Q122616086 45.41, 28.01 x 45.44, 28.05
    { 654, NoLogo, 3913, LineMetaDataContent::RapidTransit, Color{0x035eb9} }, // I OSM: 358139 WD: Q118874956 60.17, 24.84 x 60.33, 25.06
    { 656, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x630016} }, // STB OSM: 359908 WD: Q872840 47.16, 11.35 x 47.27, 11.4
    { 661, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x723b1f} }, // 35 OSM: 363305 WD: Q5123100 -37.82, 144.9 x -37.81, 145
    { 664, 3973, NoLogo, LineMetaDataContent::LocalTrain, Color{0xffffff} }, // RB 55 OSM: 363679 WD: Q108409627 47.68, 11.53 x 48.14, 12.01
    { 153, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8f4a78} }, // 19 OSM: 363891 WD: Q6811950 -37.82, 145 x -37.73, 145
    { 217, 3990, 226, LineMetaDataContent::RapidTransit, Color{0x862996} }, // S3 OSM: 364187 WD: Q56996474 47.88, 11.17 x 48.22, 11.7
    { 670, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // SIR1 OSM: 365296 WD: Q107133892 45.37, 11.87 x 45.44, 11.89
    { 676, 4006, 4032, LineMetaDataContent::Subway, Color{0x6cbe45} }, // G OSM: 366764 WD: Q126527 40.64, -74 x 40.75, -73.94
    { 42, 4049, 4032, LineMetaDataContent::Subway, Color{0xb933ad} }, // 7 OSM: 366765 WD: Q126203 40.74, -74 x 40.76, -73.83
    { 406, 4075, 4032, LineMetaDataContent::Subway, Color{0x808183} }, // S OSM: 366766 WD: Q126698 40.75, -73.99 x 40.76, -73.98
    { 680, 4101, 4032, LineMetaDataContent::Subway, Color{0xfccc0a} }, // N OSM: 366768 WD: Q126434 40.58, -74.02 x 40.78, -73.91
    { 682, 4127, 4032, LineMetaDataContent::Subway, Color{0xfccc0a} }, // Q OSM: 366769 WD: Q126448 40.58, -74 x 40.78, -73.95
    { 687, 4153, 4032, LineMetaDataContent::Subway, Color{0x0039a6} }, // A OSM: 366774 WD: Q126344 40.58, -74.01 x 40.87, -73.75
    { 27, 4179, 4032, LineMetaDataContent::Subway, Color{0x00933c} }, // 6 OSM: 366777 WD: Q126192 40.71, -74.01 x 40.85, -73.83
    { 584, 4205, 4032, LineMetaDataContent::Subway, Color{0xfccc0a} }, // R OSM: 366780 WD: Q126459 40.62, -74.03 x 40.77, -73.84
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 8 OSM: 367548 47.2, 38.88 x 47.22, 38.94
    { 689, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x9acd32} }, // Bx OSM: 367751 55.65, 12.27 x 55.75, 12.59
    { 329, 4231, 1356, LineMetaDataContent::RapidTransit, Color{0xffc225} }, // F OSM: 381625 WD: Q2133631 55.65, 12.49 x 55.73, 12.57
    { 42, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008030} }, // 7 OSM: 382533 WD: Q2590490 51.91, 4.471 x 51.93, 4.526
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xdf60a4} }, // 8 OSM: 382535 WD: Q3277304 51.9, 4.432 x 51.95, 4.488
    { 322, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x6192c7} }, // 25 OSM: 382566 WD: Q2321951 51.84, 4.46 x 51.96, 4.514
    { 67, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xa05a2c} }, // 10 OSM: 383124 WD: Q122395010 49.19, 16.51 x 49.23, 16.68
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00ccff} }, // 12 OSM: 384321 WD: Q122395012 49.18, 16.58 x 49.23, 16.62
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff00ff} }, // 5 OSM: 384539 49.16, 16.59 x 49.22, 16.63
    { 290, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa349a4} }, // S6 OSM: 385176 WD: Q125996922 48.94, 16.61 x 49.19, 17.47
    { 692, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe40000} }, // 155 OSM: 391346 46.38, 6.073 x 46.47, 6.235
    { 696, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa3429b} }, // TER T2 OSM: 394022 WD: Q3536981 47.09, -1.542 x 47.22, -1.286
    { 535, 4253, 1356, LineMetaDataContent::RapidTransit, Color{0x9370db} }, // E OSM: 394091 WD: Q4624816 55.46, 12.17 x 55.81, 12.59
    { 55, 4275, NoLogo, LineMetaDataContent::Subway, Color{0x76232f} }, // 11 OSM: 396879 WD: Q2636308 31.13, 120.6 x 31.4, 121.7
    { 109, NoLogo, 4285, LineMetaDataContent::RapidTransit, Color{0x004c8a} }, // S22 OSM: 401656 WD: Q124207650 50.09, 14.43 x 50.23, 14.88
    { 41, NoLogo, 4285, LineMetaDataContent::RapidTransit, Color{0x8a0e99} }, // S7 OSM: 401678 WD: Q107981429 49.92, 14.08 x 50.08, 14.44
    { 44, NoLogo, 4285, LineMetaDataContent::RapidTransit, Color{0x702e10} }, // S5 OSM: 401709 WD: Q107983553 50.08, 14.11 x 50.13, 14.41
    { 16, 4304, 4324, LineMetaDataContent::Subway, Color{0x00529b} }, // 2 OSM: 414866 WD: Q680973 39.9, 116.3 x 39.95, 116.4
    { 56, 4359, 4324, LineMetaDataContent::Subway, Color{0xa12830} }, // 1 OSM: 415571 WD: Q748987 39.85, 116.2 x 39.94, 116.7
    { 59, 4379, 4324, LineMetaDataContent::Subway, Color{0xf9e700} }, // 13 OSM: 417951 WD: Q847744 39.94, 116.3 x 40.07, 116.5
    { 352, 4400, 4422, LineMetaDataContent::Subway, Color{0xffd800} }, // M1 OSM: 418343 WD: Q1078111 47.5, 19.05 x 47.52, 19.09
    { 700, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x006d78} }, // T2 OSM: 418631 WD: Q16011471 47.22, 5.951 x 47.25, 6.03
    { 60, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x871f58} }, // 3 OSM: 420416 WD: Q123363013 56.81, 60.54 x 56.86, 60.64
    { 67, 4436, 4324, LineMetaDataContent::Subway, Color{0x178abb} }, // 10 OSM: 420835 WD: Q847886 39.84, 116.3 x 39.98, 116.5
    { 6, 4457, 4324, LineMetaDataContent::Subway, Color{0xae005f} }, // 5 OSM: 420836 WD: Q647340 39.84, 116.4 x 40.08, 116.4
    { 19, 4477, 4324, LineMetaDataContent::Subway, Color{0x00997a} }, // 8 OSM: 420837 WD: Q847771 39.76, 116.3 x 40.1, 116.4
    { 9, 4497, 4324, LineMetaDataContent::Subway, Color{0x008994} }, // 4 OSM: 420838 WD: Q304264 39.67, 116.3 x 40.01, 116.4
    { 56, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xcf657c} }, // 1 OSM: 420868 55.56, 12.97 x 55.71, 13.19
    { 74, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x559734} }, // 21 OSM: 422738 WD: Q123363033 56.81, 60.54 x 56.86, 60.64
    { 19, 4517, NoLogo, LineMetaDataContent::Subway, Color{0x008c95} }, // 8 OSM: 443998 WD: Q862965 23.09, 113.2 x 23.24, 113.4
    { 584, 4537, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // R OSM: 447451 WD: Q697140 25.03, 121.4 x 25.17, 121.6
    { 56, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0026ff} }, // 1 OSM: 453141 WD: Q104222652 36.23, 59.44 x 36.35, 59.64
    { 63, 4561, 226, LineMetaDataContent::RapidTransit, Color{0xd474ae} }, // S1 OSM: 454054 WD: Q2579762 52.42, 13.18 x 52.75, 13.4
    { 41, 4591, 226, LineMetaDataContent::RapidTransit, Color{0x20543f} }, // S7 OSM: 456933 WD: Q2588691 49.83, 8.488 x 50.11, 8.664
    { 341, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 23 OSM: 532064 WD: Q108783983 42.65, 23.37 x 42.68, 23.41
    { 281, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe40716} }, // T1 OSM: 535990 WD: Q3239228 45.41, 4.364 x 45.48, 4.394
    { 704, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x009de0} }, // E3 OSM: 542311 43.25, -2.929 x 43.3, -2.836
    { 684, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0363ff} }, // T1 A OSM: 548496 WD: Q1688502 36.72, 3.083 x 36.78, 3.263
    { 56, 4608, NoLogo, LineMetaDataContent::RapidTransit, Color{0xbf4525} }, // 1 OSM: 556308 WD: Q110248494 60.29, 5.232 x 60.39, 5.361
    { 710, NoLogo, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 56 OSM: 557061 WD: Q1491414 47.43, 18.96 x 47.54, 19.05
    { 153, 4634, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 19 OSM: 557063 WD: Q776651 47.47, 19.02 x 47.55, 19.05
    { 714, 4658, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 47 OSM: 557066 WD: Q1491058 47.43, 19.04 x 47.5, 19.06
    { 262, 4682, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 41 OSM: 557068 WD: Q1490823 47.44, 18.98 x 47.55, 19.05
    { 86, 4706, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 61 OSM: 557070 WD: Q1491592 47.48, 18.96 x 47.54, 19.05
    { 16, 4730, NoLogo, LineMetaDataContent::Tramway, Color{0x0068b3} }, // 2 OSM: 563459 WD: Q78198199 48.32, 10.84 x 48.38, 10.91
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xef7c00} }, // 8 OSM: 563484 48.33, 10.89 x 48.37, 10.9
    { 173, 4750, 226, LineMetaDataContent::RapidTransit, Color{0x928d1d} }, // S60 OSM: 570588 WD: Q63952011 48.69, 8.922 x 48.83, 9.195
    { 717, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff6600} }, // MSC 1908 OSM: 660480 14.2, 121 x 14.62, 121.2
    { 726, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe41346} }, // S13 OSM: 660876 WD: Q125989614 49.88, 17.88 x 49.93, 17.92
    { 174, 4787, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 60 OSM: 899388 WD: Q851167 47.5, 18.98 x 47.51, 19.01
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 4 OSM: 900844 WD: Q108783918 42.66, 23.26 x 42.72, 23.34
    { 451, 4811, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 59 OSM: 906131 WD: Q744461 47.48, 19 x 47.51, 19.02
    { 231, 4835, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 17 OSM: 911937 WD: Q1486400 47.44, 19.02 x 47.55, 19.05
    { 26, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffda66} }, // 16 OSM: 916109 WD: Q16926791 -37.87, 145 x -37.8, 145
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xb0cb1f} }, // 11 OSM: 917563 WD: Q122382726 49.78, 18.23 x 49.86, 18.29
    { 730, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffa21d} }, // MD-W OSM: 932986 WD: Q5250950 41.88, -88.33 x 42.06, -87.64
    { 735, 4856, NoLogo, LineMetaDataContent::LocalTrain, Color{0x269900} }, // RE7 OSM: 939026 WD: Q95186801 51.53, 12.23 x 52.53, 14.06
    { 153, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x7ac9ce} }, // 19 OSM: 948994 WD: Q104868215 50.08, 8.581 x 50.1, 8.684
    { 166, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x19aacd} }, // 52 OSM: 960169 WD: Q120720226 50.02, 19.89 x 50.1, 20.04
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x19633a} }, // 6 OSM: 962031 WD: Q121419537 47.06, 15.41 x 47.08, 15.48
    { 60, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x68ba45} }, // 3 OSM: 962059 WD: Q121419534 47.07, 15.42 x 47.1, 15.46
    { 42, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe42714} }, // 7 OSM: 962240 WD: Q121419538 47.06, 15.39 x 47.08, 15.47
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00b8ea} }, // 1 OSM: 962920 WD: Q121419533 47.07, 15.39 x 47.11, 15.49
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x95c11f} }, // 8 OSM: 963052 WD: Q112609295 53.05, 8.741 x 53.1, 8.84
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffcc00} }, // 6 OSM: 963103 WD: Q112609293 53.05, 8.783 x 53.11, 8.859
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x025191} }, // 5 OSM: 963685 WD: Q121419536 47.03, 15.42 x 47.1, 15.45
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xdeaa2e} }, // 4 OSM: 963737 WD: Q121419535 47.04, 15.41 x 47.07, 15.46
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe30613} }, // 4 OSM: 964983 WD: Q112609286 53.03, 8.799 x 53.16, 8.945
    { 60, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009fe3} }, // 3 OSM: 966312 WD: Q98313027 53.06, 8.752 x 53.12, 8.868
    { 739, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00a54f} }, // D1 OSM: 1014078 51.1, 15.22 x 51.29, 17.04
    { 60, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xdb2016} }, // 3 OSM: 1028300 WD: Q120670490 52.73, 15.23 x 52.76, 15.28
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xdb2016} }, // 1 OSM: 1028301 WD: Q120670257 52.72, 15.18 x 52.76, 15.28
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xdb2016} }, // 2 OSM: 1028303 WD: Q120670488 52.72, 15.18 x 52.75, 15.24
    { 742, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x004a8f} }, // D2 OSM: 1050561 51.1, 16.17 x 51.22, 17.04
    { 281, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x808080} }, // T1 OSM: 1059709 WD: Q107172293 42.84, -2.702 x 42.87, -2.649
    { 745, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe00885} }, // D8 OSM: 1067686 51.1, 17 x 51.31, 17.12
    { 748, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0075bf} }, // N10 OSM: 1070763 53.06, 8.752 x 53.12, 8.9
    { 753, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe30613} }, // N4 OSM: 1070810 53.03, 8.799 x 53.16, 8.945
    { 756, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009640} }, // N1 OSM: 1070812 53.04, 8.741 x 53.09, 8.965
    { 55, NoLogo, 3707, LineMetaDataContent::Tramway, Color{0xce1417} }, // 11 OSM: 1102233 WD: Q123224640 56.32, 43.98 x 56.33, 44.01
    { 27, 4875, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 6 OSM: 1102938 WD: Q1491542 47.48, 19.02 x 47.51, 19.07
    { 9, 4898, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 4 OSM: 1102941 WD: Q1490736 47.47, 19.02 x 47.51, 19.07
    { 759, 4921, 4936, LineMetaDataContent::RapidTransit, Color{0x8a236c} }, // H5 OSM: 1103027 WD: Q1031914 47.51, 19.03 x 47.66, 19.08
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffc734} }, // 1 OSM: 1105466 WD: Q121219450 52.4, 12.47 x 52.43, 12.57
    { 763, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x1aaa6f} }, // 64 OSM: 1110830 WD: Q6811964 -37.91, 145 x -37.8, 145
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x004c6c} }, // 6 OSM: 1111658 WD: Q16926785 -37.86, 145 x -37.76, 145.1
    { 223, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xac7963} }, // 67 OSM: 1111659 WD: Q6811965 -37.89, 145 x -37.8, 145.1
    { 766, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfaa634} }, // Raritan Valley OSM: 1122386 WD: Q7294577 40.56, -74.9 x 40.74, -74.16
    { 781, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xf173ac} }, // DRL OSM: 1139477 WD: Q989330 22.32, 114 x 22.33, 114
    { 687, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xed389c} }, // A OSM: 1142411 WD: Q16900249 45.5, -122.7 x 45.53, -122.7
    { 785, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe41f25} }, // N82 OSM: 1147592 48.24, 14.28 x 48.33, 14.36
    { 235, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe41f25} }, // 50 OSM: 1149422 WD: Q121368142 48.31, 14.26 x 48.32, 14.29
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe41f25} }, // 2 OSM: 1149423 WD: Q121368139 48.24, 14.28 x 48.33, 14.36
    { 60, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe41f25} }, // 3 OSM: 1149424 WD: Q121368140 48.23, 14.23 x 48.31, 14.29
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe41f25} }, // 1 OSM: 1149425 WD: Q121368138 48.25, 14.28 x 48.33, 14.32
    { 116, 4960, 1396, LineMetaDataContent::Subway, Color{0x00a54f} }, // U2 OSM: 1150977 WD: Q3040891 50.1, 8.64 x 50.22, 8.688
    { 789, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0039a6} }, // Harlem OSM: 1158719 WD: Q5658559 40.75, -73.98 x 41.82, -73.55
    { 796, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x29c2ce} }, // JVL OSM: 1171503 WD: Q16926948 -41.28, 174.8 x -41.22, 174.8
    { 800, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf48a30} }, // MEL OSM: 1171726 WD: Q124378470 -41.28, 174.8 x -41.2, 174.9
    { 70, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008be0} }, // TER 21 OSM: 1184795 WD: Q120094781 45.67, 4.762 x 45.77, 4.827
    { 804, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x009b3a} }, // Hudson OSM: 1186686 40.75, -73.99 x 41.71, -73.86
    { 811, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff7900} }, // Port Jervis OSM: 1190915 WD: Q7230730 41.11, -74.69 x 41.49, -74.09
    { 507, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe52422} }, // L1 OSM: 1190932 WD: Q28662810 41.62, -0.9378 x 41.69, -0.8708
    { 153, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 19 OSM: 1203707 WD: Q123221555 48.48, 34.94 x 48.53, 35.03
    { 22, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 18 OSM: 1203711 WD: Q123221554 48.48, 34.94 x 48.53, 35.03
    { 149, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 15 OSM: 1204826 WD: Q123221551 48.44, 34.96 x 48.48, 35.02
    { 823, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0065ff} }, // SFM A OSM: 1204872 WD: Q3832760 45.23, 7.39 x 45.31, 7.604
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 5 OSM: 1205626 WD: Q123221544 48.44, 34.94 x 48.48, 35.06
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 6 OSM: 1205663 WD: Q123221545 48.48, 35.02 x 48.5, 35.07
    { 138, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 9 OSM: 1205679 WD: Q123221547 48.48, 35.02 x 48.5, 35.12
    { 231, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 17 OSM: 1205794 WD: Q123221553 48.45, 35.01 x 48.48, 35.03
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 4 OSM: 1205827 WD: Q123346559 48.45, 35.02 x 48.48, 35.04
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 12 OSM: 1205902 WD: Q123221549 48.38, 35 x 48.45, 35.03
    { 26, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 16 OSM: 1205923 WD: Q123221552 48.38, 34.98 x 48.45, 35.03
    { 829, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0065ff} }, // SFM 2 OSM: 1210497 WD: Q3832754 44.89, 7.337 x 45.19, 7.89
    { 9, NoLogo, 4977, LineMetaDataContent::Tramway, Color{0xff0000} }, // 4 OSM: 1212297 WD: Q122202405 45.01, 7.624 x 45.13, 7.715
    { 59, NoLogo, 4977, LineMetaDataContent::Tramway, Color{0x7f9be1} }, // 13 OSM: 1213866 WD: Q122202408 45.06, 7.632 x 45.08, 7.7
    { 67, NoLogo, 4977, LineMetaDataContent::Tramway, Color{0xd9a500} }, // 10 OSM: 1221336 WD: Q122202407 45.02, 7.614 x 45.08, 7.672
    { 60, NoLogo, 4977, LineMetaDataContent::Tramway, Color{0xff9b0a} }, // 3 OSM: 1225333 WD: Q122202404 45.07, 7.624 x 45.1, 7.708
    { 138, NoLogo, 4977, LineMetaDataContent::Tramway, Color{0x35bdff} }, // 9 OSM: 1226867 WD: Q122202406 45.05, 7.655 x 45.11, 7.688
    { 835, NoLogo, 860, LineMetaDataContent::Tramway, Color{0x95aa53} }, // 308 OSM: 1228606 WD: Q121194689 51.4, 7.16 x 51.52, 7.284
    { 839, NoLogo, 860, LineMetaDataContent::Tramway, Color{0xb14e7a} }, // 310 OSM: 1228607 WD: Q121194693 51.44, 7.152 x 51.48, 7.337
    { 660, NoLogo, 860, LineMetaDataContent::Subway, Color{0x294488} }, // U35 OSM: 1228608 WD: Q2466100 51.45, 7.21 x 51.55, 7.273
    { 21, NoLogo, 860, LineMetaDataContent::Tramway, Color{0x72a7a0} }, // 318 OSM: 1228609 WD: Q121194696 51.42, 7.143 x 51.52, 7.284
    { 843, NoLogo, 860, LineMetaDataContent::Tramway, Color{0xea504c} }, // 306 OSM: 1228610 WD: Q121194687 51.48, 7.16 x 51.53, 7.223
    { 847, NoLogo, 860, LineMetaDataContent::Tramway, Color{0x6ba5d9} }, // 302 OSM: 1228611 WD: Q85178556 51.46, 7.056 x 51.58, 7.324
    { 851, NoLogo, 860, LineMetaDataContent::Tramway, Color{0x00b2f6} }, // 301 OSM: 1236118 WD: Q121175248 51.5, 7.019 x 51.58, 7.11
    { 855, 5016, 226, LineMetaDataContent::RapidTransit, Color{0xf47a14} }, // S 5 OSM: 1241173 WD: Q67505528 49.14, 8.674 x 49.42, 9.102
    { 859, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe00034} }, // New Haven OSM: 1260624 40.75, -73.98 x 41.31, -72.92
    { 869, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x89728e} }, // VMLR OSM: 1266358 WD: Q171699 33.41, -112.1 x 33.58, -111.8
    { 700, NoLogo, 1163, LineMetaDataContent::Tramway, Color{0x0000ff} }, // T2 OSM: 1286854 WD: Q5986172 28.44, -16.3 x 28.47, -16.29
    { 874, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x16a117} }, // Chengalpattu - Arakkonam OSM: 1289049 WD: Q7568860 12.69, 79.64 x 13.08, 79.98
    { 60, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 3 OSM: 1343415 WD: Q122585345 55.64, 37.6 x 55.76, 37.7
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 1 OSM: 1343815 WD: Q122585344 55.6, 37.59 x 55.66, 37.61
    { 26, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 16 OSM: 1348910 WD: Q122585356 55.6, 37.59 x 55.7, 37.63
    { 511, 5035, 4324, LineMetaDataContent::Subway, Color{0xd61572} }, // L2 OSM: 1350576 WD: Q5944471 39.77, 116.4 x 39.84, 116.6
    { 247, 5035, 4324, LineMetaDataContent::Subway, Color{0xd61572} }, // 24 OSM: 1350576 WD: Q5944471 39.77, 116.4 x 39.84, 116.6
    { 227, 5062, 4324, LineMetaDataContent::Subway, Color{0xd47daa} }, // 27 OSM: 1350622 WD: Q5066697 39.97, 116.2 x 40.24, 116.3
    { 678, 5090, 4324, LineMetaDataContent::Subway, Color{0xd85f26} }, // 25N OSM: 1350671 WD: Q5433860 39.72, 116.1 x 39.86, 116.3
    { 507, NoLogo, 4324, LineMetaDataContent::Subway, Color{0x9b91b1} }, // L1 OSM: 1354082 WD: Q847767 39.94, 116.4 x 40.08, 116.6
    { 899, 5117, 4936, LineMetaDataContent::RapidTransit, Color{0xee7101} }, // H7 OSM: 1358702 WD: Q1031921 47.42, 19.07 x 47.48, 19.07
    { 60, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 3 OSM: 1361661 WD: Q123352902 56.48, 84.95 x 56.48, 85.02
    { 231, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 17 OSM: 1371410 WD: Q122585357 55.82, 37.62 x 55.89, 37.67
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 11 OSM: 1371613 WD: Q122585352 55.78, 37.62 x 55.83, 37.82
    { 902, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x14ffff} }, // 5а OSM: 1372294 WD: Q124657535 55.73, 49.07 x 55.83, 49.22
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xcc9900} }, // 8 OSM: 1374424 WD: Q61887882 51.45, 11.95 x 51.52, 11.99
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x99cc00} }, // 12 OSM: 1375884 WD: Q61888162 51.48, 11.96 x 51.52, 11.99
    { 910, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfece08} }, // Main OSM: 1377995 WD: Q6736006 40.73, -74.17 x 41.11, -74.03
    { 915, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa1d4ae} }, // Gladstone OSM: 1377996 WD: Q5566325 40.67, -74.67 x 40.77, -73.99
    { 925, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xb9c9df} }, // Bergen County OSM: 1377997 WD: Q4891507 40.73, -74.15 x 41.11, -74.03
    { 939, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00a94e} }, // Morristown OSM: 1377998 WD: Q1948559 40.71, -74.83 x 40.91, -73.99
    { 950, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe76b5b} }, // Montclair-Boonton OSM: 1377999 WD: Q6904583 40.73, -74.83 x 40.93, -73.99
    { 401, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff8942} }, // FXC OSM: 1388637 WD: Q8565193 39.95, -75.18 x 40.08, -75.08
    { 968, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7c5e4a} }, // DOY OSM: 1388640 WD: Q6487336 39.95, -75.28 x 40.31, -75.13
    { 972, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffd457} }, // WAR OSM: 1390135 WD: Q7969637 39.95, -75.18 x 40.26, -74.82
    { 19, NoLogo, 1313, LineMetaDataContent::Tramway, Color{0xff66cc} }, // 8 OSM: 1390138 WD: Q5770106 34.37, 132.4 x 34.41, 132.5
    { 42, NoLogo, 1313, LineMetaDataContent::Tramway, Color{0x346633} }, // 7 OSM: 1390147 WD: Q5770102 34.38, 132.4 x 34.41, 132.5
    { 27, NoLogo, 1313, LineMetaDataContent::Tramway, Color{0xffff00} }, // 6 OSM: 1390148 WD: Q15698320 34.37, 132.4 x 34.4, 132.5
    { 60, NoLogo, 1313, LineMetaDataContent::Tramway, Color{0x003399} }, // 3 OSM: 1390149 WD: Q5770095 34.35, 132.4 x 34.4, 132.5
    { 6, NoLogo, 1313, LineMetaDataContent::Tramway, Color{0x33cc66} }, // 5 OSM: 1390150 WD: Q5770098 34.35, 132.5 x 34.4, 132.5
    { 16, NoLogo, 1313, LineMetaDataContent::Tramway, Color{0xff0000} }, // 2 OSM: 1390151 WD: Q16934367 34.31, 132.3 x 34.4, 132.5
    { 56, NoLogo, 1313, LineMetaDataContent::Tramway, Color{0xff6600} }, // 1 OSM: 1390152 WD: Q16934349 34.35, 132.5 x 34.4, 132.5
    { 976, NoLogo, 5132, LineMetaDataContent::RapidTransit, Color{0xfaa93f} }, // Camden OSM: 1403279 WD: Q5025789 38.9, -77.01 x 39.28, -76.62
    { 983, NoLogo, 5132, LineMetaDataContent::RapidTransit, Color{0xfbcab6} }, // Brunswick OSM: 1405417 WD: Q4979520 38.9, -77.96 x 39.46, -76.99
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 2 OSM: 1405516 WD: Q122917034 44.8, 20.45 x 44.83, 20.48
    { 993, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff7f00} }, // 12E OSM: 1411178 WD: Q1487139 38.71, -9.138 x 38.72, -9.13
    { 997, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff00ff} }, // 15E OSM: 1411205 WD: Q63229924 38.69, -9.233 x 38.71, -9.135
    { 261, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00008b} }, // 041 OSM: 1413948 WD: Q121357423 51.3, 6.497 x 51.33, 6.602
    { 257, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00008b} }, // 042 OSM: 1413950 WD: Q121358966 51.3, 6.554 x 51.37, 6.619
    { 250, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00008b} }, // 043 OSM: 1413951 WD: Q121358976 51.33, 6.566 x 51.36, 6.648
    { 169, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00008b} }, // 044 OSM: 1413956 WD: Q121358885 51.33, 6.513 x 51.37, 6.659
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfdc434} }, // 4 OSM: 1443866 WD: Q1490746 46.24, 20.12 x 46.28, 20.16
    { 6, 5147, 5171, LineMetaDataContent::Subway, Color{0x802f08} }, // 5 OSM: 1462012 WD: Q831673 55.73, 37.57 x 55.78, 37.66
    { 9, 5276, 5171, LineMetaDataContent::Subway, Color{0x33ccff} }, // 4 OSM: 1463287 WD: Q834540 55.73, 37.44 x 55.75, 37.61
    { 60, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe5005a} }, // 3 OSM: 1469415 WD: Q89494370 51.02, 13.7 x 51.1, 13.75
    { 60, 5300, 5171, LineMetaDataContent::Subway, Color{0x0000ff} }, // 3 OSM: 1472548 WD: Q626941 55.73, 37.35 x 55.86, 37.8
    { 1001, 5324, NoLogo, LineMetaDataContent::LocalTrain, Color{0xffb200} }, // RB 13 OSM: 1472736 WD: Q113237031 48.35, 10.88 x 48.75, 11.45
    { 56, 5341, 5171, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 1475758 WD: Q729631 55.56, 37.4 x 55.82, 37.75
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffa500} }, // 4 OSM: 1476874 WD: Q123352951 56.45, 84.98 x 56.48, 85.02
    { 631, 5365, 226, LineMetaDataContent::RapidTransit, Color{0x73c82c} }, // S9 OSM: 1483885 WD: Q115215302 48.99, 8.399 x 49.71, 8.58
    { 1010, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0896dd} }, // 98 OSM: 1490387 WD: Q106462644 52.36, 13.03 x 52.4, 13.1
    { 1013, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 91 OSM: 1492311 WD: Q92930854 52.36, 13.01 x 52.4, 13.1
    { 687, 5384, 5423, LineMetaDataContent::Subway, Color{0x0000ff} }, // A OSM: 1502599 WD: Q17621067 6.152, -75.63 x 6.339, -75.54
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // 1 OSM: 1503481 WD: Q123352876 56.47, 84.95 x 56.53, 85.02
    { 1017, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x897cb9} }, // 78 OSM: 1504645 WD: Q6811971 -37.87, 145 x -37.81, 145
    { 1020, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x19488e} }, // 92 OSM: 1505928 WD: Q106462634 52.36, 13.03 x 52.42, 13.14
    { 1023, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfe9800} }, // 93 OSM: 1509473 WD: Q106461089 52.36, 13.06 x 52.41, 13.1
    { 1026, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x838a8f} }, // 94 OSM: 1512265 WD: Q106462647 52.37, 13.01 x 52.4, 13.11
    { 331, 5451, 226, LineMetaDataContent::RapidTransit, Color{0x803c9f} }, // S33 OSM: 1513484 WD: Q115206384 49.12, 8.364 x 49.24, 8.594
    { 27, 5471, 5171, LineMetaDataContent::Subway, Color{0xffa500} }, // 6 OSM: 1514439 WD: Q175271 55.6, 37.51 x 55.89, 37.67
    { 42, 5495, 5171, LineMetaDataContent::Subway, Color{0xff00ff} }, // 7 OSM: 1516383 WD: Q924028 55.67, 37.43 x 55.86, 37.86
    { 60, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 3 OSM: 1525325 WD: Q123346613 51.53, 45.93 x 51.59, 46.02
    { 26, NoLogo, 4977, LineMetaDataContent::Tramway, Color{0xe0abff} }, // 16 OSM: 1525348 WD: Q122202410 45.05, 7.65 x 45.09, 7.698
    { 19, 5519, 5171, LineMetaDataContent::Subway, Color{0xffff00} }, // 8 OSM: 1526351 WD: Q585986 55.74, 37.63 x 55.76, 37.87
    { 67, 5543, 5171, LineMetaDataContent::Subway, Color{0xb4d445} }, // 10 OSM: 1532877 WD: Q582194 55.61, 37.54 x 55.93, 37.76
    { 1029, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xdc281e} }, // N19 OSM: 1536166 48.12, 11.46 x 48.15, 11.64
    { 1033, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf6c046} }, // Zoo Tram OSM: 1536345 35.15, -90 x 35.15, -89.99
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 12 OSM: 1538177 WD: Q122585353 55.71, 37.66 x 55.79, 37.82
    { 235, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 50 OSM: 1538180 WD: Q122585371 55.75, 37.6 x 55.79, 37.72
    { 294, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 46 OSM: 1538181 WD: Q122585368 55.75, 37.7 x 55.83, 37.78
    { 102, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 37 OSM: 1538182 WD: Q122585363 55.75, 37.65 x 55.78, 37.82
    { 1043, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 32 OSM: 1538183 WD: Q122585361 55.75, 37.66 x 55.79, 37.75
    { 217, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x0097d8} }, // S3 OSM: 1549250 WD: Q7388286 47.32, 8.501 x 47.53, 8.806
    { 271, 5568, 5595, LineMetaDataContent::Subway, Color{0xffd900} }, // B OSM: 1557177 WD: Q3239063 43.56, 1.43 x 43.64, 1.478
    { 281, 5619, 5647, LineMetaDataContent::Tramway, Color{0x004687} }, // T1 OSM: 1557178 WD: Q3239230 43.59, 1.36 x 43.67, 1.444
    { 687, 5671, 5595, LineMetaDataContent::Subway, Color{0xdb001b} }, // A OSM: 1557179 WD: Q3239050 43.57, 1.392 x 43.63, 1.483
    { 1046, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf6c454} }, // S10 OSM: 1561016 WD: Q687279 47.35, 8.465 x 47.38, 8.54
    { 306, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe67d63} }, // S4 OSM: 1567629 WD: Q685807 47.27, 8.517 x 47.38, 8.558
    { 138, 5698, 5171, LineMetaDataContent::Subway, Color{0xa0a2a3} }, // 9 OSM: 1570146 WD: Q739170 55.57, 37.57 x 55.9, 37.63
    { 16, 5722, 5171, LineMetaDataContent::Subway, Color{0x006400} }, // 2 OSM: 1572626 WD: Q834482 55.61, 37.47 x 55.88, 37.77
    { 246, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x946644} }, // S24 OSM: 1574036 WD: Q7388228 47.17, 8.512 x 47.75, 9.106
    { 15, 5746, 5171, LineMetaDataContent::Subway, Color{0xbac8e8} }, // 12 OSM: 1580617 WD: Q678759 55.54, 37.52 x 55.6, 37.59
    { 426, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00a995} }, // 96 OSM: 1585204 WD: Q106462646 52.36, 13.05 x 52.43, 13.14
    { 1051, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x59c133} }, // 99 OSM: 1585259 WD: Q106462643 52.37, 13.06 x 52.4, 13.11
    { 54, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0xccaaff} }, // S11 OSM: 1588232 WD: Q56435440 47.37, 8.048 x 47.54, 8.771
    { 1054, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x37bbed} }, // TMR OSM: 1603490 -27.47, -59.05 x -27.42, -58.98
    { 1058, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x00c0f3} }, // S29 OSM: 1609488 WD: Q115646661 47.17, 7.903 x 47.49, 8.257
    { 63, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x00ab4e} }, // S1 OSM: 1609559 WD: Q115646641 47.04, 8.098 x 47.2, 8.525
    { 290, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x7751a1} }, // S6 OSM: 1609735 WD: Q7388350 47.26, 8.305 x 47.48, 8.683
    { 1062, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0xd8242b} }, // S12 OSM: 1614502 WD: Q7388182 47.37, 8.208 x 47.7, 9.043
    { 25, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x64b97a} }, // S16 OSM: 1618466 WD: Q7388193 47.28, 8.511 x 47.45, 8.621
    { 331, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x2da7df} }, // S33 OSM: 1619213 WD: Q7388269 47.5, 8.611 x 47.7, 8.726
    { 631, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x00a34f} }, // S9 OSM: 1620987 WD: Q7388394 47.35, 8.501 x 47.7, 8.721
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc32b3c} }, // 2 OSM: 1624727 WD: Q60282113 51.75, 14.31 x 51.76, 14.35
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x239537} }, // 4 OSM: 1628047 WD: Q60328960 51.72, 14.32 x 51.79, 14.35
    { 700, 5771, 5804, LineMetaDataContent::Tramway, Color{0xbb4a9b} }, // T2 OSM: 1635139 WD: Q1771110 48.82, 2.217 x 48.92, 2.288
    { 649, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // C-1 OSM: 1636998 WD: Q59928410 41.63, -1.023 x 41.72, -0.8658
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xece116} }, // 1 OSM: 1637446 WD: Q60213236 51.75, 14.33 x 51.78, 14.34
    { 687, 5835, 2914, LineMetaDataContent::Subway, Color{0x1ca4cb} }, // A OSM: 1637478 WD: Q1209679 -34.63, -58.47 x -34.61, -58.37
    { 22, NoLogo, 860, LineMetaDataContent::Tramway, Color{0x0095da} }, // 18 OSM: 1646141 WD: Q20035834 50.73, 6.893 x 50.98, 7.096
    { 1066, 5863, 4936, LineMetaDataContent::RapidTransit, Color{0xed6e86} }, // H9 OSM: 1647378 WD: Q947539 47.5, 19.14 x 47.55, 19.27
    { 1069, 5863, 4936, LineMetaDataContent::RapidTransit, Color{0xed6e86} }, // H8 OSM: 1647379 WD: Q947539 47.5, 19.14 x 47.6, 19.36
    { 1072, 5878, 4936, LineMetaDataContent::RapidTransit, Color{0x7b4400} }, // H6 OSM: 1647380 WD: Q1031918 47.18, 18.94 x 47.47, 19.12
    { 56, 5893, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 1 OSM: 1658046 WD: Q651686 47.46, 19.02 x 47.55, 19.11
    { 247, 5916, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 24 OSM: 1658053 WD: Q1489900 47.44, 19.07 x 47.5, 19.12
    { 235, 5940, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 50 OSM: 1658057 WD: Q643837 47.43, 19.13 x 47.47, 19.22
    { 97, 5964, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 62 OSM: 1658060 WD: Q1491622 47.48, 19.07 x 47.54, 19.14
    { 258, 5988, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 42 OSM: 1658062 WD: Q1490864 47.45, 19.13 x 47.47, 19.15
    { 60, 6012, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 3 OSM: 1658063 WD: Q1490196 47.44, 19.09 x 47.52, 19.14
    { 145, 6035, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 14 OSM: 1658066 WD: Q1485881 47.52, 19.06 x 47.59, 19.12
    { 1075, 6059, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 69 OSM: 1658067 WD: Q1491929 47.52, 19.09 x 47.55, 19.15
    { 166, 6083, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 52 OSM: 1658071 WD: Q1491293 47.42, 19.1 x 47.47, 19.13
    { 1078, 6107, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 62A OSM: 1658072 WD: Q743389 47.48, 19.1 x 47.54, 19.14
    { 102, 6132, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 37 OSM: 1658073 WD: Q1490525 47.47, 19.07 x 47.5, 19.18
    { 1082, 6156, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 51A OSM: 1658076 WD: Q16516127 47.47, 19.07 x 47.48, 19.08
    { 348, 6181, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 51 OSM: 1658077 WD: Q1491245 47.44, 19.07 x 47.48, 19.12
    { 1086, 6205, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 28A OSM: 1658080 WD: Q12813290 47.47, 19.07 x 47.5, 19.18
    { 1091, 6227, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 28 OSM: 1658081 WD: Q1490084 47.47, 19.07 x 47.5, 19.18
    { 1094, 6251, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 37A OSM: 1658082 WD: Q287376 47.49, 19.07 x 47.5, 19.14
    { 63, 6276, 226, LineMetaDataContent::RapidTransit, Color{0x33b540} }, // S1 OSM: 1660624 WD: Q19377130 53.55, 9.705 x 53.65, 10.09
    { 60, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 3 OSM: 1666928 WD: Q123353080 53.36, 58.96 x 53.45, 59.09
    { 74, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 21 OSM: 1667031 WD: Q123353102 53.36, 58.96 x 53.43, 59.01
    { 138, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 9 OSM: 1667386 WD: Q123353086 53.36, 58.98 x 53.48, 59.09
    { 149, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 15 OSM: 1667885 WD: Q123353095 53.36, 58.96 x 53.48, 59.06
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 1 OSM: 1667972 WD: Q123353077 53.39, 58.97 x 53.44, 59.1
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 2 OSM: 1667973 WD: Q123353078 53.4, 58.96 x 53.44, 59.08
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 13 OSM: 1672599 WD: Q123353091 53.4, 58.96 x 53.45, 59.09
    { 145, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 14 OSM: 1672601 WD: Q123353092 53.4, 58.96 x 53.45, 59.09
    { 67, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 10 OSM: 1672603 WD: Q123353087 53.35, 58.96 x 53.45, 59.09
    { 247, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 24 OSM: 1672604 WD: Q123353105 53.35, 58.96 x 53.44, 58.98
    { 1059, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 29 OSM: 1672605 WD: Q123353109 53.36, 58.97 x 53.44, 59.01
    { 231, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 17 OSM: 1672606 WD: Q123353098 53.36, 58.96 x 53.44, 58.98
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 11 OSM: 1672607 WD: Q123353088 53.4, 58.97 x 53.44, 59.08
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 12 OSM: 1672608 WD: Q123353089 53.36, 58.96 x 53.45, 59.08
    { 275, 6291, 2826, LineMetaDataContent::RapidTransit, Color{0x00824e} }, // D OSM: 1673421 WD: Q1425351 48.29, 2.344 x 49.26, 2.657
    { 22, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 18 OSM: 1673878 WD: Q123353099 53.36, 58.96 x 53.41, 59.1
    { 42, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 7 OSM: 1673879 WD: Q123353084 53.36, 58.98 x 53.42, 59.03
    { 110, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 22 OSM: 1673880 WD: Q123353103 53.36, 58.96 x 53.42, 59.03
    { 243, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 20 OSM: 1673881 WD: Q123353101 53.35, 58.96 x 53.42, 59.03
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 6 OSM: 1673882 WD: Q123353083 53.4, 58.96 x 53.43, 59.03
    { 661, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 35 OSM: 1675482 WD: Q123353114 53.39, 59.04 x 53.45, 59.1
    { 392, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 30 OSM: 1675489 WD: Q123353111 53.36, 58.98 x 53.45, 59.09
    { 1091, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 28 OSM: 1675490 WD: Q123353108 53.36, 58.96 x 53.44, 59.08
    { 116, 6323, 1396, LineMetaDataContent::Subway, Color{0xff0000} }, // U2 OSM: 1676043 WD: Q3433227 49.42, 11.03 x 49.49, 11.11
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe96020} }, // 1 OSM: 1679960 WD: Q16655728 50.09, 14.34 x 50.1, 14.46
    { 116, 6340, 1396, LineMetaDataContent::Subway, Color{0xee1d23} }, // U2 OSM: 1686090 WD: Q275451 53.53, 9.943 x 53.64, 10.15
    { 113, 6355, 1396, LineMetaDataContent::Subway, Color{0x0066b3} }, // U1 OSM: 1687370 WD: Q248623 53.55, 9.985 x 53.71, 10.29
    { 310, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 26 OSM: 1689065 WD: Q122585360 55.68, 37.54 x 55.73, 37.62
    { 646, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 39 OSM: 1689391 WD: Q122585365 55.68, 37.54 x 55.76, 37.7
    { 1100, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // А OSM: 1689398 WD: Q4461919 55.73, 37.63 x 55.76, 37.7
    { 714, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 47 OSM: 1689752 WD: Q122585369 55.68, 37.61 x 55.73, 37.69
    { 254, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 38 OSM: 1690017 WD: Q122585364 55.68, 37.59 x 55.73, 37.66
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc80404} }, // 2 OSM: 1707564 WD: Q20902214 55.87, 26.53 x 55.9, 26.56
    { 60, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x66cc66} }, // 3 OSM: 1707565 WD: Q25529489 55.87, 26.5 x 55.91, 26.59
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc80404} }, // 1 OSM: 1708351 WD: Q25529488 55.87, 26.51 x 55.9, 26.56
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x946238} }, // 2 OSM: 1713906 WD: Q109558674 52.34, 14.5 x 52.35, 14.56
    { 217, 6370, 226, LineMetaDataContent::RapidTransit, Color{0x5d1d81} }, // S3 OSM: 1727359 WD: Q19368685 53.46, 9.797 x 53.66, 10.03
    { 328, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfdc434} }, // 3F OSM: 1733222 WD: Q570656 46.25, 20.11 x 46.28, 20.16
    { 60, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfdc434} }, // 3 OSM: 1733225 WD: Q1490201 46.25, 20.12 x 46.28, 20.16
    { 371, NoLogo, 6385, LineMetaDataContent::RapidTransit, Color{0xf80000} }, // Red OSM: 1737997 WD: Q7304508 38.51, -90.36 x 38.74, -89.88
    { 166, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x7c7c7b} }, // 52 OSM: 1744154 WD: Q108464208 49.96, 8.246 x 50, 8.28
    { 1103, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xee1d23} }, // СТ OSM: 1756406 WD: Q121537880 51.9, 29.21 x 52.05, 29.34
    { 1103, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // СТ OSM: 1759150 WD: Q107191041 48.7, 44.5 x 48.8, 44.6
    { 67, 6413, NoLogo, LineMetaDataContent::Tramway, Color{0xffffff} }, // 10 OSM: 1762641 WD: Q123158615 56.84, 53.18 x 56.88, 53.28
    { 1108, 6433, 6455, LineMetaDataContent::Subway, Color{0x0000ff} }, // 2 Салтівська OSM: 1766294 WD: Q2332390 49.99, 36.23 x 50.03, 36.34
    { 1131, 6478, 6455, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 Холодногірсько-заводська OSM: 1766295 WD: Q2710248 49.95, 36.18 x 49.99, 36.4
    { 1181, 6500, 6455, LineMetaDataContent::Subway, Color{0x008000} }, // 3 Олексіївська OSM: 1766296 WD: Q2109890 49.98, 36.2 x 50.06, 36.27
    { 55, 6522, NoLogo, LineMetaDataContent::Tramway, Color{0xde4800} }, // 11 OSM: 1766772 WD: Q123158574 56.84, 53.23 x 56.87, 53.28
    { 56, 6542, 3169, LineMetaDataContent::Tramway, Color{0x78ccc9} }, // 1 OSM: 1767386 WD: Q63890946 50.41, 30.38 x 50.45, 30.49
    { 15, 6558, NoLogo, LineMetaDataContent::Tramway, Color{0xca0706} }, // 12 OSM: 1767871 WD: Q123158535 56.8, 53.19 x 56.87, 53.28
    { 16, 6542, 3169, LineMetaDataContent::Tramway, Color{0x78ccc9} }, // 2 OSM: 1773735 WD: Q63890965 50.41, 30.37 x 50.43, 30.41
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff6600} }, // 1 OSM: 1783293 WD: Q25522217 59.44, 24.67 x 59.46, 24.79
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff6600} }, // 2 OSM: 1783294 WD: Q18624670 59.43, 24.67 x 59.46, 24.81
    { 60, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff6600} }, // 3 OSM: 1783295 WD: Q25522221 59.41, 24.73 x 59.44, 24.79
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff6600} }, // 4 OSM: 1783296 WD: Q16409268 59.41, 24.73 x 59.44, 24.81
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x06a0e6} }, // 2 OSM: 1788097 55.67, 52.28 x 55.73, 52.47
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xa8c45b} }, // 1 OSM: 1788309 WD: Q4461884 48.69, 44.45 x 48.71, 44.51
    { 1208, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x1b522b} }, // 12а OSM: 1789317 55.67, 52.28 x 55.75, 52.47
    { 145, NoLogo, 3169, LineMetaDataContent::Tramway, Color{0xce1417} }, // 14 OSM: 1794175 WD: Q123344581 50.42, 30.41 x 50.47, 30.52
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 1 OSM: 1795490 WD: Q121832771 53.01, 18.56 x 53.03, 18.7
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 4 OSM: 1795572 WD: Q121832895 53.01, 18.56 x 53.04, 18.67
    { 15, NoLogo, 3169, LineMetaDataContent::Tramway, Color{0xce1417} }, // 12 OSM: 1798934 WD: Q123339546 50.46, 30.34 x 50.55, 30.52
    { 1213, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa82618} }, // SSL OSM: 1811654 41.59, -87.62 x 41.88, -86.29
    { 27, NoLogo, 6578, LineMetaDataContent::Tramway, Color{0xce1417} }, // 6 OSM: 1821113 WD: Q123168035 59.93, 30.23 x 59.97, 30.36
    { 266, NoLogo, 6578, LineMetaDataContent::Tramway, Color{0xce1417} }, // 40 OSM: 1821265 WD: Q123168054 59.93, 30.23 x 60.01, 30.37
    { 700, 6596, 6626, LineMetaDataContent::Tramway, Color{0xab0672} }, // T2 OSM: 1824544 WD: Q106915028 47.29, 5.006 x 47.37, 5.059
    { 281, 6649, 6626, LineMetaDataContent::Tramway, Color{0xcc0088} }, // T1 OSM: 1824550 WD: Q3238664 47.31, 5.028 x 47.33, 5.112
    { 1217, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x509e2f} }, // BEL OSM: 1826236 WD: Q4881878 -35.03, 138.6 x -34.92, 138.6
    { 392, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x4f4a9f} }, // 30 OSM: 1830395 WD: Q6811953 -37.81, 144.9 x -37.81, 145
    { 26, NoLogo, 6578, LineMetaDataContent::Tramway, Color{0xce1417} }, // 16 OSM: 1831075 WD: Q123168040 59.9, 30.27 x 59.93, 30.37
    { 262, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 41 OSM: 1831189 59.88, 30.24 x 59.92, 30.29
    { 119, 6679, 1396, LineMetaDataContent::Subway, Color{0x00868b} }, // U3 OSM: 1857497 WD: Q3433219 49.44, 11.02 x 49.47, 11.09
    { 113, 6696, 1396, LineMetaDataContent::Subway, Color{0x000066} }, // U1 OSM: 1857639 WD: Q3433210 49.4, 10.96 x 49.48, 11.14
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0101df} }, // 1 OSM: 1860406 WD: Q104189103 50.82, 12.88 x 50.84, 12.92
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x6a0888} }, // 2 OSM: 1860407 WD: Q104189205 50.81, 12.92 x 50.84, 12.95
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffff00} }, // 4 OSM: 1860420 WD: Q104189434 50.78, 12.88 x 50.84, 12.93
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff8000} }, // 5 OSM: 1862032 WD: Q104189624 50.78, 12.88 x 50.83, 12.97
    { 74, 6713, NoLogo, LineMetaDataContent::Tramway, Color{0xf89c0e} }, // 21 OSM: 1871117 WD: Q85093119 50.07, 8.567 x 50.11, 8.67
    { 26, 6743, NoLogo, LineMetaDataContent::Tramway, Color{0xf47216} }, // 16 OSM: 1871120 WD: Q111155014 50.1, 8.644 x 50.14, 8.745
    { 1222, NoLogo, 6578, LineMetaDataContent::Tramway, Color{0xce1417} }, // 36 OSM: 1871436 WD: Q123168051 59.85, 30.06 x 59.89, 30.28
    { 687, 6773, NoLogo, LineMetaDataContent::Tramway, Color{0xed2625} }, // A OSM: 1874970 WD: Q2066292 49.23, 4.004 x 49.28, 4.032
    { 271, 6803, NoLogo, LineMetaDataContent::Tramway, Color{0x00aef0} }, // B OSM: 1874971 WD: Q2085986 49.22, 3.996 x 49.28, 4.032
    { 55, 6833, NoLogo, LineMetaDataContent::Tramway, Color{0xfbbc09} }, // 11 OSM: 1875166 WD: Q85088920 50.1, 8.552 x 50.13, 8.774
    { 15, 6863, NoLogo, LineMetaDataContent::Tramway, Color{0xc73a17} }, // 12 OSM: 1875167 WD: Q85090131 50.08, 8.581 x 50.13, 8.756
    { 145, 6893, NoLogo, LineMetaDataContent::Tramway, Color{0xf1471d} }, // 14 OSM: 1875169 WD: Q85112445 50.1, 8.618 x 50.13, 8.716
    { 149, 6923, NoLogo, LineMetaDataContent::Tramway, Color{0xfbbc09} }, // 15 OSM: 1875170 WD: Q85112688 50.09, 8.636 x 50.1, 8.745
    { 231, 6953, NoLogo, LineMetaDataContent::Tramway, Color{0xf1471d} }, // 17 OSM: 1875171 WD: Q107028657 50.06, 8.619 x 50.12, 8.695
    { 243, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x939597} }, // 20 OSM: 1875174 WD: Q85089542 50.07, 8.65 x 50.11, 8.67
    { 22, 6983, NoLogo, LineMetaDataContent::Tramway, Color{0xf89c0e} }, // 18 OSM: 1875175 WD: Q109953001 50.08, 8.671 x 50.16, 8.704
    { 290, 7013, 226, LineMetaDataContent::RapidTransit, Color{0xf57921} }, // S6 OSM: 1880910 WD: Q3238987 50.1, 8.633 x 50.34, 8.789
    { 231, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8d1d2c} }, // 17 OSM: 1903836 WD: Q96578284 47.35, 8.482 x 47.4, 8.542
    { 60, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xb71965} }, // 3 OSM: 1904828 WD: Q16655744 50, 14.4 x 50.13, 14.48
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x9bd6f9} }, // 4 OSM: 1904829 WD: Q16655748 50.02, 14.35 x 50.08, 14.48
    { 67, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 10 OSM: 1905347 WD: Q100151899 44.76, 20.45 x 44.83, 20.48
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 12 OSM: 1905348 WD: Q122917040 44.77, 20.41 x 44.81, 20.49
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 5 OSM: 1905349 WD: Q122917036 44.78, 20.45 x 44.83, 20.52
    { 235, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x1d1d1b} }, // 50 OSM: 1909761 WD: Q68580427 49.96, 8.175 x 50.02, 8.275
    { 9, 7030, NoLogo, LineMetaDataContent::Tramway, Color{0x4f71b9} }, // 4 OSM: 1910445 WD: Q21041079 48.14, 17.03 x 48.2, 17.18
    { 42, 7055, NoLogo, LineMetaDataContent::Tramway, Color{0xfeec06} }, // 7 OSM: 1925351 WD: Q21041082 48.14, 17.11 x 48.22, 17.17
    { 1043, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xbe1622} }, // 32 OSM: 1925789 WD: Q117220924 44.4, 26.05 x 44.43, 26.1
    { 336, NoLogo, 6578, LineMetaDataContent::Tramway, Color{0xce1417} }, // 45 OSM: 1926572 WD: Q123168058 59.83, 30.32 x 59.88, 30.41
    { 1059, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 29 OSM: 1926573 59.83, 30.32 x 59.9, 30.35
    { 251, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 43 OSM: 1927169 59.83, 30.32 x 59.89, 30.4
    { 322, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xbe1622} }, // 25 OSM: 1928780 WD: Q121368432 44.37, 25.98 x 44.43, 26.1
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // 5 OSM: 1930407 WD: Q123336516 41.76, 140.7 x 41.79, 140.8
    { 322, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 25 OSM: 1933012 59.83, 30.35 x 59.93, 30.4
    { 162, NoLogo, 6578, LineMetaDataContent::Tramway, Color{0xce1417} }, // 49 OSM: 1933013 WD: Q123168062 59.83, 30.35 x 59.93, 30.42
    { 42, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xbe1622} }, // 7 OSM: 1936713 WD: Q85980453 44.37, 26.09 x 44.43, 26.1
    { 714, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xbe1622} }, // 47 OSM: 1936802 WD: Q121368510 44.41, 26.05 x 44.43, 26.1
    { 74, NoLogo, 6578, LineMetaDataContent::Tramway, Color{0xce1417} }, // 21 OSM: 1938644 WD: Q123168044 59.98, 30.24 x 60.06, 30.38
    { 559, NoLogo, 6578, LineMetaDataContent::Tramway, Color{0xce1417} }, // 48 OSM: 1938658 WD: Q123168061 59.98, 30.19 x 59.99, 30.35
    { 243, NoLogo, 6578, LineMetaDataContent::Tramway, Color{0xce1417} }, // 20 OSM: 1938751 WD: Q123168043 59.96, 30.32 x 60.05, 30.38
    { 287, NoLogo, 6578, LineMetaDataContent::Tramway, Color{0xce1417} }, // 58 OSM: 1939721 WD: Q123168067 60.04, 30.3 x 60.07, 30.38
    { 687, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xa83939} }, // A OSM: 1940504 WD: Q10883225 35, 135.7 x 35.02, 135.7
    { 262, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xbe1622} }, // 41 OSM: 1940779 WD: Q4982647 44.41, 26.03 x 44.48, 26.08
    { 667, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 55 OSM: 1942053 59.99, 30.23 x 60.06, 30.37
    { 27, 7080, 1925, LineMetaDataContent::Tramway, Color{0xfef303} }, // 6 OSM: 1942851 WD: Q104867938 49.43, 11.05 x 49.46, 11.12
    { 51, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // S2 OSM: 1946076 WD: Q884374 48, 7.84 x 48.17, 8.072
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 2 OSM: 1949380 WD: Q123352923 56.45, 84.95 x 56.48, 84.99
    { 403, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x913108} }, // C OSM: 1958845 WD: Q121410577 37.79, -122.4 x 37.79, -122.4
    { 138, NoLogo, 6578, LineMetaDataContent::Tramway, Color{0xce1417} }, // 9 OSM: 1959399 WD: Q123168038 59.98, 30.32 x 60.04, 30.44
    { 67, NoLogo, 6578, LineMetaDataContent::Tramway, Color{0xce1417} }, // 10 OSM: 1965337 WD: Q123168039 59.91, 30.41 x 59.95, 30.5
    { 19, NoLogo, 6578, LineMetaDataContent::Tramway, Color{0xce1417} }, // 8 OSM: 1965401 WD: Q123168037 59.93, 30.44 x 59.95, 30.49
    { 451, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 59 OSM: 1965402 59.93, 30.44 x 59.97, 30.49
    { 763, NoLogo, 6578, LineMetaDataContent::Tramway, Color{0xce1417} }, // 64 OSM: 1965403 WD: Q123168073 59.93, 30.44 x 59.98, 30.51
    { 145, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 14 OSM: 1968651 WD: Q122917042 44.76, 20.47 x 44.81, 20.52
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 6 OSM: 1968652 WD: Q122917037 44.78, 20.47 x 44.81, 20.52
    { 56, 7097, NoLogo, LineMetaDataContent::Tramway, Color{0xca0706} }, // 1 OSM: 1973051 WD: Q28667619 56.8, 53.18 x 56.88, 53.21
    { 9, 7116, NoLogo, LineMetaDataContent::Tramway, Color{0xfccc1c} }, // 4 OSM: 1973053 WD: Q123167877 56.84, 53.18 x 56.88, 53.25
    { 42, 7135, NoLogo, LineMetaDataContent::Tramway, Color{0x2f0583} }, // 7 OSM: 1973055 WD: Q123158699 56.86, 53.18 x 56.88, 53.25
    { 138, 7154, NoLogo, LineMetaDataContent::Tramway, Color{0xca0706} }, // 9 OSM: 1973056 WD: Q123158593 56.8, 53.19 x 56.88, 53.25
    { 16, 7173, NoLogo, LineMetaDataContent::Tramway, Color{0x1aab47} }, // 2 OSM: 1973058 WD: Q123155973 56.84, 53.2 x 56.88, 53.25
    { 1225, NoLogo, 860, LineMetaDataContent::Tramway, Color{0xd01519} }, // 107 OSM: 1976059 WD: Q121174870 51.41, 6.993 x 51.51, 7.103
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x003828} }, // 2 OSM: 1984325 WD: Q110883507 52.9, -1.207 x 52.99, -1.145
    { 1229, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x82bf40} }, // SFM3 OSM: 1988841 WD: Q3832756 45.04, 6.71 x 45.14, 7.678
    { 675, 7192, NoLogo, LineMetaDataContent::Tramway, Color{0xfcc70d} }, // SG OSM: 1994315 WD: Q339069 35.64, 139.6 x 35.67, 139.7
    { 575, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x004ea2} }, // SL OSM: 1994316 WD: Q6360898 35.33, 139.6 x 35.39, 139.7
    { 433, 7217, 19, LineMetaDataContent::Tramway, Color{0x33ff33} }, // M2 OSM: 2001598 WD: Q62512253 52.52, 13.41 x 52.57, 13.44
    { 1234, NoLogo, 860, LineMetaDataContent::Subway, Color{0x008fc2} }, // U75 OSM: 2003447 WD: Q121295970 51.2, 6.684 x 51.23, 6.847
    { 1016, NoLogo, 860, LineMetaDataContent::Subway, Color{0x009adf} }, // U78 OSM: 2003448 WD: Q107015816 51.22, 6.734 x 51.27, 6.795
    { 59, NoLogo, 860, LineMetaDataContent::Tramway, Color{0x967b68} }, // 13 OSM: 2003476 WD: Q63442554 50.91, 6.908 x 50.97, 7.038
    { 6, NoLogo, 860, LineMetaDataContent::Tramway, Color{0x948fb8} }, // 5 OSM: 2003477 WD: Q63442534 50.93, 6.888 x 50.98, 6.96
    { 1239, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc4121a} }, // 31 OSM: 2005491 WD: Q47565641 48.22, 16.37 x 48.3, 16.42
    { 392, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc4121a} }, // 30 OSM: 2005591 WD: Q47564751 48.26, 16.4 x 48.3, 16.42
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x88822a} }, // 5 OSM: 2024979 WD: Q16655756 50.02, 14.35 x 50.09, 14.48
    { 60, NoLogo, 860, LineMetaDataContent::Tramway, Color{0xe693b5} }, // 3 OSM: 2026288 WD: Q63442521 50.93, 6.87 x 50.98, 7.086
    { 86, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x98c000} }, // 61 OSM: 2026289 WD: Q20035840 50.7, 7.071 x 50.76, 7.112
    { 97, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x61af20} }, // 62 OSM: 2026290 WD: Q20035841 50.7, 7.095 x 50.74, 7.176
    { 82, NoLogo, 860, LineMetaDataContent::Tramway, Color{0x60d6f7} }, // 63 OSM: 2026291 WD: Q20035835 50.68, 7.047 x 50.75, 7.159
    { 1245, NoLogo, 860, LineMetaDataContent::Tramway, Color{0xe5007d} }, // 66 OSM: 2026292 WD: Q20035836 50.64, 7.092 x 50.79, 7.217
    { 223, NoLogo, 860, LineMetaDataContent::Tramway, Color{0xee99bf} }, // 67 OSM: 2026293 WD: Q20035837 50.68, 7.092 x 50.79, 7.203
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x149a93} }, // 6 OSM: 2032473 WD: Q16655760 50.07, 14.42 x 50.13, 14.48
    { 42, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe31e25} }, // 7 OSM: 2061854 WD: Q16655764 50.06, 14.39 x 50.11, 14.55
    { 56, 7236, NoLogo, LineMetaDataContent::Tramway, Color{0x009cdd} }, // 1 OSM: 2067963 WD: Q12804359 53.41, 14.49 x 53.46, 14.56
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x605047} }, // 8 OSM: 2070554 WD: Q16655766 50.09, 14.39 x 50.11, 14.53
    { 15, 7256, NoLogo, LineMetaDataContent::Tramway, Color{0x009cdd} }, // 12 OSM: 2074000 WD: Q28792440 53.4, 14.53 x 53.45, 14.55
    { 281, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe3002b} }, // T1 OSM: 2074462 48.65, 6.145 x 48.7, 6.225
    { 6, 7277, NoLogo, LineMetaDataContent::Tramway, Color{0x009cdd} }, // 5 OSM: 2077222 WD: Q25501513 53.44, 14.49 x 53.45, 14.53
    { 55, 7297, NoLogo, LineMetaDataContent::Tramway, Color{0x009cdd} }, // 11 OSM: 2077355 WD: Q32946105 53.4, 14.53 x 53.45, 14.58
    { 27, 7318, NoLogo, LineMetaDataContent::Tramway, Color{0x009cdd} }, // 6 OSM: 2077516 WD: Q26003028 53.42, 14.55 x 53.48, 14.61
    { 19, 7338, NoLogo, LineMetaDataContent::Tramway, Color{0x009cdd} }, // 8 OSM: 2080359 WD: Q26160394 53.38, 14.49 x 53.43, 14.64
    { 42, 7358, NoLogo, LineMetaDataContent::Tramway, Color{0x009cdd} }, // 7 OSM: 2080360 WD: Q26111009 53.38, 14.53 x 53.44, 14.64
    { 60, 7378, NoLogo, LineMetaDataContent::Tramway, Color{0xef7c00} }, // 3 OSM: 2083643 WD: Q99229508 48.27, 10.88 x 48.37, 10.9
    { 27, 7398, NoLogo, LineMetaDataContent::Tramway, Color{0x94c11c} }, // 6 OSM: 2083654 WD: Q121146595 48.35, 10.84 x 48.37, 10.96
    { 138, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x43ac3c} }, // 9 OSM: 2088592 WD: Q16655771 50.06, 14.3 x 50.09, 14.5
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xb5c426} }, // 1 OSM: 2100315 WD: Q6811945 -37.85, 144.9 x -37.74, 145
    { 242, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00aadc} }, // N20 OSM: 2101204 48.14, 11.51 x 48.18, 11.57
    { 56, 7418, 860, LineMetaDataContent::Tramway, Color{0x0000ff} }, // 1 OSM: 2102327 WD: Q117468577 51.98, 8.502 x 52.06, 8.546
    { 60, 7438, 860, LineMetaDataContent::Tramway, Color{0xffff00} }, // 3 OSM: 2102329 WD: Q117468931 52.02, 8.518 x 52.06, 8.543
    { 16, 7458, 860, LineMetaDataContent::Tramway, Color{0x008000} }, // 2 OSM: 2102391 WD: Q117468882 52, 8.532 x 52.06, 8.628
    { 9, 7478, 860, LineMetaDataContent::Tramway, Color{0xff0000} }, // 4 OSM: 2102392 WD: Q117468952 52, 8.485 x 52.05, 8.589
    { 1248, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffc56b} }, // 금수산태양궁전궤도전차 OSM: 2102520 WD: Q121507263 39.06, 125.8 x 39.07, 125.8
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffeedd} }, // 1 OSM: 2104341 WD: Q121691512 54.14, 19.39 x 54.19, 19.44
    { 1285, 7498, 226, LineMetaDataContent::RapidTransit, Color{0xe7526b} }, // S20 OSM: 2113865 WD: Q7388223 48.04, 11.04 x 48.18, 11.54
    { 41, 7515, 226, LineMetaDataContent::RapidTransit, Color{0x983224} }, // S7 OSM: 2113867 WD: Q7388364 47.91, 11.42 x 48.14, 11.78
    { 231, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf58220} }, // 17 OSM: 2114099 WD: Q116950113 45.79, 15.89 x 45.82, 16.02
    { 56, 7531, 7575, LineMetaDataContent::Tramway, Color{0x00a651} }, // 1 OSM: 2116454 WD: Q3238670 47.2, -1.639 x 47.26, -1.515
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x9a94c8} }, // 5 OSM: 2136277 WD: Q117157320 45.79, 15.89 x 45.82, 16.02
    { 60, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc96e80} }, // 3 OSM: 2149224 WD: Q17440804 45.79, 15.94 x 45.8, 16.04
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xcc302a} }, // 1 OSM: 2160531 WD: Q112841862 40.72, 8.545 x 40.74, 8.562
    { 1289, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x4dbe63} }, // Тр3 OSM: 2161840 WD: Q124709844 49.81, 24 x 49.84, 24.04
    { 1295, 7605, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf36421} }, // T3 OSM: 2166474 WD: Q2407219 -33.93, 150.9 x -33.86, 151.2
    { 16, 7618, 7575, LineMetaDataContent::Tramway, Color{0xee1c25} }, // 2 OSM: 2166523 WD: Q3238813 47.19, -1.593 x 47.26, -1.542
    { 60, 7662, 7575, LineMetaDataContent::Tramway, Color{0x006db1} }, // 3 OSM: 2166524 WD: Q3238913 47.18, -1.617 x 47.25, -1.542
    { 1298, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8e4b34} }, // Тр2 OSM: 2169223 WD: Q124709803 49.82, 23.99 x 49.84, 24.07
    { 1304, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x35ccf5} }, // Тр4 OSM: 2171616 WD: Q124735420 49.78, 23.99 x 49.84, 24.06
    { 19, 7706, NoLogo, LineMetaDataContent::RapidTransit, Color{0x808080} }, // 8 OSM: 2174536 WD: Q3296720 -23.55, -46.98 x -23.51, -46.64
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc96d6a} }, // 4 OSM: 2180576 WD: Q116969401 45.79, 15.95 x 45.83, 16.08
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf8a98e} }, // 6 OSM: 2183641 WD: Q17440873 45.78, 15.93 x 45.82, 16
    { 138, 7717, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00a88e} }, // 9 OSM: 2183695 WD: Q5245848 -23.76, -46.78 x -23.53, -46.69
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x666666} }, // 2 OSM: 2189262 WD: Q121590540 45.55, 18.68 x 45.56, 18.73
    { 153, NoLogo, 3169, LineMetaDataContent::Tramway, Color{0xce1417} }, // 19 OSM: 2191470 WD: Q123339551 50.46, 30.45 x 50.52, 30.52
    { 306, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x000080} }, // S4 OSM: 2199152 WD: Q7388307 49.25, 10.3 x 49.44, 11.08
    { 336, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xbe1622} }, // 45 OSM: 2202119 WD: Q121368501 44.45, 26.02 x 44.49, 26.08
    { 26, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xbe1622} }, // 16 OSM: 2202705 WD: Q97192577 44.43, 26.11 x 44.48, 26.13
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0071bc} }, // 2 OSM: 2203208 WD: Q121359742 48.98, 8.345 x 49.04, 8.479
    { 1222, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xbe1622} }, // 36 OSM: 2203210 WD: Q121368246 44.43, 26.11 x 44.48, 26.19
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xbe1622} }, // 5 OSM: 2203626 WD: Q121368338 44.43, 26.08 x 44.5, 26.11
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xbe1622} }, // 11 OSM: 2205114 WD: Q85980501 44.39, 26.02 x 44.47, 26.09
    { 294, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xbe1622} }, // 46 OSM: 2205366 44.43, 26.08 x 44.46, 26.19
    { 145, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xbe1622} }, // 14 OSM: 2206781 WD: Q97192564 44.43, 26.11 x 44.45, 26.18
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x1c63b7} }, // 2 OSM: 2206997 WD: Q104521890 41.91, 12.46 x 41.93, 12.48
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xed1c24} }, // 5 OSM: 2206998 WD: Q104537333 41.88, 12.5 x 41.9, 12.57
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xbfdf14} }, // 8 OSM: 2206999 WD: Q104537360 41.87, 12.44 x 41.9, 12.52
    { 74, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xbe1622} }, // 21 OSM: 2207121 WD: Q99757067 44.43, 26.1 x 44.48, 26.16
    { 687, 7728, 7769, LineMetaDataContent::Subway, Color{0xf68b1f} }, // A OSM: 2207255 WD: Q572544 41.84, 12.42 x 41.91, 12.59
    { 271, 7799, 7769, LineMetaDataContent::Subway, Color{0x3783c6} }, // B OSM: 2208346 WD: Q2666571 41.83, 12.46 x 41.95, 12.57
    { 1310, 7840, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfbbc09} }, // FC1 OSM: 2208347 WD: Q3743595 41.87, 12.51 x 41.9, 12.56
    { 1314, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7eb9e6} }, // FC2 OSM: 2208348 41.71, 12.28 x 41.88, 12.48
    { 1318, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x55b036} }, // FC3 OSM: 2208349 41.91, 12.11 x 42.44, 12.5
    { 145, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00adef} }, // 14 OSM: 2208350 WD: Q415821 41.89, 12.5 x 41.9, 12.57
    { 153, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf89c0e} }, // 19 OSM: 2208351 WD: Q104537271 41.88, 12.46 x 41.92, 12.57
    { 506, 7870, NoLogo, LineMetaDataContent::RapidTransit, Color{0x007663} }, // FL1 OSM: 2208499 WD: Q3737286 41.79, 12.25 x 42.44, 12.65
    { 510, 7905, NoLogo, LineMetaDataContent::RapidTransit, Color{0x004174} }, // FL2 OSM: 2208500 WD: Q3737287 41.9, 12.53 x 42.1, 13.43
    { 514, 7940, NoLogo, LineMetaDataContent::RapidTransit, Color{0x88aca0} }, // FL3 OSM: 2208501 WD: Q3737289 41.87, 12.08 x 42.43, 12.53
    { 502, 7975, NoLogo, LineMetaDataContent::RapidTransit, Color{0x965b0e} }, // FL4 OSM: 2208502 WD: Q25064 41.67, 12.5 x 41.9, 12.78
    { 1322, 8010, NoLogo, LineMetaDataContent::RapidTransit, Color{0xdccc00} }, // FL5 OSM: 2208503 WD: Q3737292 41.86, 11.8 x 42.09, 12.53
    { 1326, 8045, NoLogo, LineMetaDataContent::RapidTransit, Color{0xd880b4} }, // FL6 OSM: 2208504 WD: Q3737295 41.48, 12.5 x 41.9, 13.83
    { 1330, 8080, NoLogo, LineMetaDataContent::RapidTransit, Color{0x9acc66} }, // FL7 OSM: 2208505 WD: Q661786 41.25, 12.5 x 41.9, 13.72
    { 1334, 8115, NoLogo, LineMetaDataContent::RapidTransit, Color{0x6cbf68} }, // FL8 OSM: 2208506 WD: Q3737301 41.45, 12.5 x 41.9, 12.66
    { 1338, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xca0a23} }, // LEX OSM: 2208507 WD: Q1207539 41.79, 12.25 x 41.9, 12.53
    { 247, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xbe1622} }, // 24 OSM: 2208755 WD: Q121368425 44.44, 26.04 x 44.49, 26.09
    { 266, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xbe1622} }, // 40 OSM: 2210742 WD: Q121368458 44.41, 26.11 x 44.44, 26.2
    { 227, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xbe1622} }, // 27 OSM: 2211466 WD: Q121368436 44.41, 26.09 x 44.43, 26.2
    { 341, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xbe1622} }, // 23 OSM: 2211745 WD: Q121368420 44.39, 26.07 x 44.43, 26.18
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe31e24} }, // 1 OSM: 2212352 WD: Q61085901 44.39, 26.05 x 44.45, 26.14
    { 67, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xbe1622} }, // 10 OSM: 2212352 WD: Q61085901 44.39, 26.05 x 44.45, 26.14
    { 19, 8150, 8171, LineMetaDataContent::Tramway, Color{0x169fdb} }, // 8 OSM: 2262665 WD: Q431783 50.8, 4.353 x 50.85, 4.44
    { 645, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008c99} }, // 639 OSM: 2271832 32.72, -117.4 x 33.19, -117.2
    { 1342, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008c99} }, // 655 OSM: 2271832 32.72, -117.4 x 33.19, -117.2
    { 1346, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008c99} }, // 635 OSM: 2271832 32.72, -117.4 x 33.19, -117.2
    { 297, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008c99} }, // 665 OSM: 2271832 32.72, -117.4 x 33.19, -117.2
    { 522, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008c99} }, // 657 OSM: 2271832 32.72, -117.4 x 33.19, -117.2
    { 1238, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008c99} }, // 631 OSM: 2271832 32.72, -117.4 x 33.19, -117.2
    { 93, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0092d8} }, // TER 62 OSM: 2272886 WD: Q120094802 45.15, 5.417 x 45.57, 6.045
    { 1350, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0092d8} }, // TER 60 OSM: 2274103 WD: Q120094799 45.15, 5.417 x 45.57, 6.045
    { 1360, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x669933} }, // 87 OSM: 2282096 WD: Q121341867 52.44, 13.69 x 52.46, 13.76
    { 1363, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf39ec4} }, // T4 OSM: 2305411 WD: Q108046070 50.29, 18.73 x 50.31, 18.83
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008f4d} }, // 1 OSM: 2309633 WD: Q8192892 33.84, 132.8 x 33.85, 132.8
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf9a51b} }, // 2 OSM: 2309634 WD: Q8192892 33.84, 132.8 x 33.85, 132.8
    { 687, 8197, 2826, LineMetaDataContent::RapidTransit, Color{0xe3051c} }, // A OSM: 2333448 WD: Q741818 48.75, 2.012 x 49.05, 2.782
    { 1295, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf1665b} }, // T3 OSM: 2335747 WD: Q108045397 50.27, 18.73 x 50.34, 18.79
    { 138, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x112233} }, // 9 OSM: 2336329 54.27, 48.29 x 54.34, 48.39
    { 56, 8229, NoLogo, LineMetaDataContent::Subway, Color{0xe4002b} }, // 1 OSM: 2336458 WD: Q263572 29.53, 106.2 x 29.62, 106.6
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfbba00} }, // 2 OSM: 2344988 WD: Q121305020 50.84, 12.05 x 50.85, 12.08
    { 166, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 52 OSM: 2345812 59.83, 30.14 x 59.88, 30.26
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe30613} }, // 4 OSM: 2368452 WD: Q121196133 50.72, 12.43 x 50.75, 12.49
    { 67, 8254, NoLogo, LineMetaDataContent::Tramway, Color{0x009cdd} }, // 10 OSM: 2372195 WD: Q26298715 53.42, 14.49 x 53.43, 14.56
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xa8d4af} }, // 8 OSM: 2375053 WD: Q120720205 50.01, 19.88 x 50.08, 19.95
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfdc434} }, // 2 OSM: 2380276 WD: Q1488541 46.24, 20.13 x 46.27, 20.15
    { 56, 8275, NoLogo, LineMetaDataContent::Subway, Color{0x10069f} }, // 1 OSM: 2381769 WD: Q6118988 30.39, 104.1 x 30.72, 104.1
    { 306, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x9f184c} }, // S4 OSM: 2395148 WD: Q106362966 48.99, 8.349 x 49.48, 9.528
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0c7cac} }, // 1 OSM: 2395313 WD: Q122307220 51.1, 17.03 x 51.15, 17.11
    { 67, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0c7cac} }, // 10 OSM: 2395314 WD: Q122307228 51.1, 16.87 x 51.15, 17.11
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0c7cac} }, // 11 OSM: 2395315 WD: Q122307229 51.08, 16.97 x 51.13, 17.07
    { 145, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0c7cac} }, // 14 OSM: 2395316 WD: Q122307232 51.07, 16.98 x 51.12, 17.04
    { 149, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0c7cac} }, // 15 OSM: 2395317 WD: Q122307233 51.07, 17.01 x 51.15, 17.04
    { 231, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0c7cac} }, // 17 OSM: 2395318 WD: Q122307235 51.07, 16.99 x 51.12, 17.1
    { 60, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0c7cac} }, // 3 OSM: 2395323 WD: Q122307221 51.08, 16.87 x 51.15, 17.08
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0c7cac} }, // 4 OSM: 2395324 WD: Q122307222 51.08, 16.97 x 51.11, 17.11
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0c7cac} }, // 5 OSM: 2395325 WD: Q122307223 51.08, 16.98 x 51.11, 17.08
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0c7cac} }, // 6 OSM: 2395326 WD: Q122307224 51.07, 17.01 x 51.13, 17.07
    { 42, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0c7cac} }, // 7 OSM: 2395327 WD: Q122307225 51.07, 16.99 x 51.15, 17.04
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0c7cac} }, // 8 OSM: 2395328 WD: Q122307226 51.08, 17.03 x 51.13, 17.06
    { 138, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0c7cac} }, // 9 OSM: 2395329 WD: Q122307227 51.07, 17.01 x 51.12, 17.1
    { 22, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0c7cac} }, // 18 OSM: 2395331 WD: Q122307236 51.08, 16.95 x 51.14, 17.05
    { 74, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0c7cac} }, // 21 OSM: 2395338 WD: Q122307238 51.08, 16.95 x 51.14, 17.05
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0c7cac} }, // 12 OSM: 2395339 WD: Q122307230 51.11, 16.96 x 51.14, 17.1
    { 47, 8285, NoLogo, LineMetaDataContent::RapidTransit, Color{0x04a5c8} }, // S8 OSM: 2396232 WD: Q110714378 41.35, 1.919 x 41.48, 2.148
    { 1366, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8e0043} }, // T5 OSM: 2396696 WD: Q108046096 50.29, 18.73 x 50.35, 18.92
    { 347, 8302, 226, LineMetaDataContent::RapidTransit, Color{0xf8a20d} }, // S51 OSM: 2412316 WD: Q96388878 49.3, 8.674 x 49.42, 8.991
    { 67, 8322, NoLogo, LineMetaDataContent::Tramway, Color{0xb4e16e} }, // 10 OSM: 2413392 WD: Q106921203 57.68, 11.89 x 57.73, 11.98
    { 19, 8345, NoLogo, LineMetaDataContent::Tramway, Color{0x872387} }, // 8 OSM: 2413517 WD: Q10562727 57.65, 11.91 x 57.8, 12.05
    { 59, 8367, NoLogo, LineMetaDataContent::Tramway, Color{0xfee6c2} }, // 13 OSM: 2413518 WD: Q10562720 57.66, 11.85 x 57.72, 11.99
    { 16, 8390, NoLogo, LineMetaDataContent::Tramway, Color{0xfff014} }, // 2 OSM: 2413613 WD: Q106921120 57.67, 11.93 x 57.71, 12
    { 9, 8412, NoLogo, LineMetaDataContent::Tramway, Color{0x14823c} }, // 4 OSM: 2413615 WD: Q106921167 57.65, 11.97 x 57.8, 12.05
    { 713, 8434, 226, LineMetaDataContent::RapidTransit, Color{0xba8a4d} }, // S47 OSM: 2413847 WD: Q3742025 52.45, 13.43 x 52.47, 13.56
    { 60, 8465, NoLogo, LineMetaDataContent::Tramway, Color{0x004b85} }, // 3 OSM: 2418220 WD: Q106921163 57.67, 11.91 x 57.72, 12.03
    { 138, 8487, NoLogo, LineMetaDataContent::Tramway, Color{0x6ec8dc} }, // 9 OSM: 2418235 WD: Q106921200 57.68, 11.9 x 57.8, 12.05
    { 55, 8509, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 11 OSM: 2418236 WD: Q106921207 57.66, 11.85 x 57.76, 12.07
    { 1369, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // 901 OSM: 2440421 WD: Q1617191 44.85, -93.28 x 44.98, -93.2
    { 339, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x61af20} }, // RB23 OSM: 2441590 WD: Q1699351 50.56, 6.761 x 50.74, 7.098
    { 105, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf0e130} }, // 888 OSM: 2442946 44.98, -93.73 x 45.33, -93.25
    { 63, 8532, 226, LineMetaDataContent::RapidTransit, Color{0x109c37} }, // S1 OSM: 2444997 WD: Q7388210 51.16, 6.772 x 51.52, 7.46
    { 54, 8543, 226, LineMetaDataContent::RapidTransit, Color{0xef7c00} }, // S11 OSM: 2445000 WD: Q7388174 50.94, 6.674 x 51.28, 7.125
    { 1062, 8555, 226, LineMetaDataContent::RapidTransit, Color{0x61af20} }, // S12 OSM: 2445001 WD: Q7388180 50.76, 6.713 x 50.95, 7.66
    { 726, 8567, 226, LineMetaDataContent::RapidTransit, Color{0x00a6eb} }, // S13 OSM: 2445007 WD: Q7388184 50.81, 6.482 x 50.95, 7.151
    { 51, 8579, 226, LineMetaDataContent::RapidTransit, Color{0x006db6} }, // S2 OSM: 2445008 WD: Q7388251 51.45, 7.015 x 51.62, 7.46
    { 1090, 8590, 226, LineMetaDataContent::RapidTransit, Color{0x717676} }, // S28 OSM: 2445009 WD: Q7388234 51.2, 6.594 x 51.25, 7.153
    { 217, 8602, 226, LineMetaDataContent::RapidTransit, Color{0xffff00} }, // S3 OSM: 2445010 WD: Q7388285 51.4, 6.835 x 51.48, 7.181
    { 306, 8613, 226, LineMetaDataContent::RapidTransit, Color{0xef7c00} }, // S4 OSM: 2445011 WD: Q7388319 51.5, 7.334 x 51.55, 7.692
    { 44, 8624, 226, LineMetaDataContent::RapidTransit, Color{0x98c60f} }, // S5 OSM: 2445012 WD: Q7388333 51.36, 7.325 x 51.52, 7.46
    { 290, 8635, 226, LineMetaDataContent::RapidTransit, Color{0xdc052d} }, // S6 OSM: 2445013 WD: Q7388349 50.94, 6.79 x 51.45, 7.023
    { 89, 8646, 226, LineMetaDataContent::RapidTransit, Color{0x14bae6} }, // S68 OSM: 2445014 WD: Q7388346 51.1, 6.79 x 51.23, 7.074
    { 47, 8658, 226, LineMetaDataContent::RapidTransit, Color{0xb03303} }, // S8 OSM: 2445015 WD: Q7388383 51.19, 6.445 x 51.36, 7.46
    { 631, 8669, 226, LineMetaDataContent::RapidTransit, Color{0xc7007f} }, // S9 OSM: 2445016 WD: Q7388395 51.23, 6.921 x 51.74, 7.46
    { 63, 8680, 226, LineMetaDataContent::RapidTransit, Color{0xec192e} }, // S1 OSM: 2445551 WD: Q67858837 49.33, 7.334 x 49.48, 9.424
    { 51, 8699, 226, LineMetaDataContent::RapidTransit, Color{0x2960b5} }, // S2 OSM: 2445552 WD: Q64667644 49.34, 7.768 x 49.48, 9.144
    { 217, 8718, 226, LineMetaDataContent::RapidTransit, Color{0x00a896} }, // S3 OSM: 2445553 WD: Q2781002 49.87, 8.504 x 50.16, 8.699
    { 217, 8735, 226, LineMetaDataContent::RapidTransit, Color{0xfcd804} }, // S3 OSM: 2445554 WD: Q68929824 48.98, 8.262 x 49.48, 8.685
    { 56, 8754, 8774, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 2446076 WD: Q519861 59.84, 30.25 x 60.05, 30.44
    { 16, 8793, 8774, LineMetaDataContent::Subway, Color{0x0000ff} }, // 2 OSM: 2446077 WD: Q1459627 59.83, 30.3 x 60.07, 30.38
    { 60, 8813, 8774, LineMetaDataContent::Subway, Color{0x008000} }, // 3 OSM: 2446078 WD: Q1509576 59.83, 30.2 x 59.99, 30.5
    { 9, 8833, 8774, LineMetaDataContent::Subway, Color{0xffa500} }, // 4 OSM: 2446079 WD: Q1784097 59.91, 30.32 x 59.93, 30.48
    { 6, 8853, 8774, LineMetaDataContent::Subway, Color{0x800080} }, // 5 OSM: 2446080 WD: Q1579583 59.82, 30.25 x 60.01, 30.43
    { 700, 8873, 8895, LineMetaDataContent::Tramway, Color{0xf5e615} }, // T2 OSM: 2449769 WD: Q3238811 43.3, 5.367 x 43.32, 5.406
    { 281, 8916, 8895, LineMetaDataContent::Tramway, Color{0xf18e00} }, // T1 OSM: 2452278 WD: Q3238668 43.29, 5.381 x 43.3, 5.444
    { 1373, 8938, 8967, LineMetaDataContent::Tramway, Color{0xa7ce39} }, // TT OSM: 2466526 WD: Q2448517 47.74, 7.088 x 47.81, 7.344
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xab0000} }, // 2 OSM: 2468631 WD: Q122681310 50.75, 15.03 x 50.78, 15.08
    { 60, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xab0000} }, // 3 OSM: 2468632 WD: Q122681352 50.74, 15.01 x 50.78, 15.08
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xab0000} }, // 11 OSM: 2468639 WD: Q122681278 50.74, 15.04 x 50.77, 15.1
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xab0000} }, // 5 OSM: 2468640 WD: Q122681379 50.74, 15.04 x 50.77, 15.1
    { 1376, 8990, 9014, LineMetaDataContent::Subway, Color{0x10069f} }, // Μ3 OSM: 2473158 WD: Q6553119 37.91, 23.64 x 38.02, 23.95
    { 217, 9068, 226, LineMetaDataContent::RapidTransit, Color{0xdb6eab} }, // S3 OSM: 2474189 WD: Q63433452 52.16, 9.739 x 52.38, 10.02
    { 44, 9084, 226, LineMetaDataContent::RapidTransit, Color{0xf78a18} }, // S5 OSM: 2474199 WD: Q63433456 51.71, 8.737 x 52.46, 9.773
    { 16, 9100, 9126, LineMetaDataContent::Subway, Color{0x0000ff} }, // 2 OSM: 2507796 WD: Q2001449 41.29, 69.2 x 41.35, 69.32
    { 60, 9145, 9126, LineMetaDataContent::Subway, Color{0x008000} }, // 3 OSM: 2507797 WD: Q4534678 41.3, 69.27 x 41.38, 69.3
    { 56, 9171, 9126, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 2507927 WD: Q4515924 41.21, 69.19 x 41.33, 69.33
    { 44, 9197, 226, LineMetaDataContent::RapidTransit, Color{0xa52a2a} }, // S5 OSM: 2515355 WD: Q2515085 50.1, 8.583 x 50.25, 8.699
    { 306, 9214, 226, LineMetaDataContent::RapidTransit, Color{0xfecb09} }, // S4 OSM: 2515408 WD: Q2204443 49.99, 8.516 x 50.18, 8.699
    { 1380, 9231, NoLogo, LineMetaDataContent::LocalTrain, Color{0x0080ff} }, // RE5 OSM: 2523198 WD: Q50374543 52.47, 12.11 x 54.31, 13.46
    { 1384, 9250, NoLogo, LineMetaDataContent::LocalTrain, Color{0x80004d} }, // RE4 OSM: 2523200 WD: Q15195675 52, 12.35 x 52.6, 13.38
    { 60, 9269, NoLogo, LineMetaDataContent::Tramway, Color{0xe31f25} }, // 3 OSM: 2529467 WD: Q21041078 48.12, 17.11 x 48.22, 17.17
    { 138, 9294, NoLogo, LineMetaDataContent::Tramway, Color{0x829714} }, // 9 OSM: 2529468 WD: Q21041086 48.14, 17.05 x 48.17, 17.18
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 13 OSM: 2529840 WD: Q122585354 55.77, 37.65 x 55.83, 37.77
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x800080} }, // 5 OSM: 2531144 WD: Q121338696 49.72, 9.925 x 49.8, 9.968
    { 60, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0066ff} }, // 3 OSM: 2531145 WD: Q121338683 49.74, 9.925 x 49.8, 9.961
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffbb00} }, // 1 OSM: 2531240 WD: Q100555102 49.77, 9.929 x 49.8, 9.955
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff2e17} }, // 1 OSM: 2531659 WD: Q121311468 50.93, 10.67 x 50.95, 10.71
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xaf2a21} }, // 2 OSM: 2531812 WD: Q121315985 50.94, 10.71 x 50.96, 10.72
    { 60, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff9929} }, // 3 OSM: 2531813 WD: Q121315996 50.94, 10.68 x 50.96, 10.72
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffb530} }, // 4 OSM: 2531864 WD: Q2430929 50.86, 10.52 x 50.95, 10.71
    { 41, 9319, 226, LineMetaDataContent::RapidTransit, Color{0x14bae6} }, // S7 OSM: 2544304 WD: Q1195962 51.16, 7.004 x 51.28, 7.253
    { 1388, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff3818} }, // Тр1 OSM: 2548724 WD: Q1032126 49.83, 24 x 49.84, 24.06
    { 1394, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x1b5620} }, // Тр9 OSM: 2548725 WD: Q124735446 49.83, 23.99 x 49.86, 24.04
    { 1400, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8144a3} }, // Тр6 OSM: 2548730 WD: Q124735422 49.84, 24 x 49.87, 24.04
    { 63, 9330, 226, LineMetaDataContent::RapidTransit, Color{0x7760b0} }, // S1 OSM: 2548861 WD: Q63433445 52.27, 8.934 x 52.42, 9.773
    { 1406, 9346, 9368, LineMetaDataContent::RapidTransit, Color{0x005d30} }, // RE29 OSM: 2550762 WD: Q1374322 50.56, 5.559 x 50.77, 6.093
    { 1411, 9390, 9428, LineMetaDataContent::Subway, Color{0x82dc73} }, // 7bis OSM: 2554103 WD: Q50749 48.88, 2.366 x 48.88, 2.4
    { 290, 9461, 226, LineMetaDataContent::RapidTransit, Color{0x005aab} }, // S6 OSM: 2557420 WD: Q63433460 52.37, 9.739 x 52.62, 10.06
    { 19, NoLogo, 3169, LineMetaDataContent::Tramway, Color{0xce1417} }, // 8 OSM: 2560439 WD: Q123339544 50.4, 30.63 x 50.46, 30.66
    { 1091, NoLogo, 3169, LineMetaDataContent::Tramway, Color{0xce1417} }, // 28 OSM: 2561862 WD: Q123339554 50.46, 30.6 x 50.53, 30.64
    { 110, NoLogo, 3169, LineMetaDataContent::Tramway, Color{0xce1417} }, // 22 OSM: 2561865 WD: Q123339552 50.42, 30.6 x 50.49, 30.69
    { 1416, 9477, 9500, LineMetaDataContent::Subway, Color{0x62361b} }, // Brown OSM: 2562976 WD: Q3112936 41.88, -87.71 x 41.97, -87.63
    { 306, 9529, 226, LineMetaDataContent::RapidTransit, Color{0x972f50} }, // S4 OSM: 2567719 WD: Q63433455 52.16, 9.687 x 52.58, 9.957
    { 8, 9545, 9561, LineMetaDataContent::Subway, Color{0x228b22} }, // M4 OSM: 2568424 WD: Q2552821 44.45, 26.03 x 44.5, 26.07
    { 511, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x9ecd58} }, // L2 OSM: 2568862 WD: Q115328482 59.72, 10.61 x 59.92, 10.84
    { 1282, 9579, 9590, LineMetaDataContent::RapidTransit, Color{0x2e8ec7} }, // S2/S20 OSM: 2569296 WD: Q108084309 52.17, 20.94 x 52.26, 21.3
    { 281, 9608, 5804, LineMetaDataContent::Tramway, Color{0x216eb4} }, // T1 OSM: 2572573 WD: Q369969 48.9, 2.274 x 48.94, 2.47
    { 507, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x9ecd58} }, // L1 OSM: 2575540 WD: Q115217962 59.74, 10.34 x 59.96, 11.05
    { 1422, 9641, 9500, LineMetaDataContent::Subway, Color{0xf9461c} }, // Orange OSM: 2578312 WD: Q3180068 41.79, -87.74 x 41.89, -87.63
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xdb7093} }, // 2 OSM: 2578716 WD: Q48759284 32.78, 130.7 x 32.8, 130.8
    { 60, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x1e90ff} }, // 3 OSM: 2578717 WD: Q48759291 32.78, 130.7 x 32.82, 130.8
    { 1429, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 100 OSM: 2579608 60, 30.34 x 60.06, 30.44
    { 56, 9666, 9685, LineMetaDataContent::Subway, Color{0xe50b00} }, // 1 OSM: 2580502 WD: Q1771534 56.24, 43.86 x 56.32, 43.99
    { 1433, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xa52a2a} }, // Scala mobile OSM: 2581270 41.84, 12.89 x 41.84, 12.89
    { 371, 9697, 9500, LineMetaDataContent::Subway, Color{0xc60c30} }, // Red OSM: 2584583 WD: Q642623 41.72, -87.67 x 42.02, -87.62
    { 290, 9718, 226, LineMetaDataContent::RapidTransit, Color{0xec192e} }, // S6 OSM: 2587144 WD: Q96388302 49.44, 8.242 x 50.07, 8.667
    { 700, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x228b22} }, // T2 OSM: 2597272 WD: Q113671831 45.46, 12.21 x 45.49, 12.25
    { 1446, 9737, 226, LineMetaDataContent::RapidTransit, Color{0x6b2c94} }, // S 8 OSM: 2605126 WD: Q63213955 51.47, 11.98 x 51.87, 12.66
    { 855, 273, 226, LineMetaDataContent::RapidTransit, Color{0xf17f1a} }, // S 5 OSM: 2606971 WD: Q63216051 50.7, 11.99 x 51.48, 12.48
    { 1450, 9762, NoLogo, LineMetaDataContent::LocalTrain, Color{0xa5027d} }, // RB14 OSM: 2607468 WD: Q15119376 52.36, 12.88 x 52.61, 13.6
    { 1455, 9782, 226, LineMetaDataContent::RapidTransit, Color{0x00a650} }, // S 4 OSM: 2607472 WD: Q63215993 51.25, 12.37 x 51.59, 13.25
    { 1459, 9807, NoLogo, LineMetaDataContent::LocalTrain, Color{0x0474ec} }, // RE 18 OSM: 2607473 WD: Q63348135 51.04, 13.5 x 51.75, 14.33
    { 1465, 9827, NoLogo, LineMetaDataContent::LocalTrain, Color{0xffe600} }, // RE2 OSM: 2607475 WD: Q15119419 51.75, 11.36 x 53.9, 14.33
    { 1469, 9846, NoLogo, LineMetaDataContent::LocalTrain, Color{0x00a25d} }, // RE 15 OSM: 2607476 WD: Q105947741 51.04, 13.5 x 51.46, 14.23
    { 63, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x66cdaa} }, // S1 OSM: 2609006 WD: Q50331474 54.08, 12.06 x 54.18, 12.13
    { 1475, 9866, NoLogo, LineMetaDataContent::LocalTrain, Color{0x36803d} }, // RE1 OSM: 2609008 WD: Q19624774 53.36, 10 x 54.08, 12.15
    { 217, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0xa66540} }, // S3 OSM: 2609009 WD: Q50331483 53.79, 12.06 x 54.18, 12.35
    { 51, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x9400d3} }, // S2 OSM: 2609011 WD: Q50331479 53.8, 12.06 x 54.18, 12.17
    { 703, 9882, NoLogo, LineMetaDataContent::LocalTrain, Color{0xff5900} }, // RE3 OSM: 2609916 WD: Q15195663 51.58, 12.66 x 54.31, 14.29
    { 1479, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff9700} }, // SFM 1 OSM: 2610264 WD: Q3832755 44.97, 7.603 x 45.42, 7.824
    { 1485, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // SFM 4 OSM: 2610270 WD: Q3832758 44.69, 7.602 x 45.23, 8.031
    { 639, 9901, 9500, LineMetaDataContent::Subway, Color{0x009b3a} }, // Green OSM: 2613599 WD: Q3176204 41.78, -87.81 x 41.89, -87.61
    { 1491, 9924, 860, LineMetaDataContent::Tramway, Color{0x7fd2e6} }, // U44 OSM: 2615764 WD: Q121288210 51.51, 7.385 x 51.53, 7.484
    { 74, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe2000a} }, // 21 OSM: 2617691 WD: Q121338914 49.4, 8.675 x 49.43, 8.693
    { 110, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfcc200} }, // 22 OSM: 2617692 WD: Q121338815 49.4, 8.627 x 49.41, 8.693
    { 341, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe48e00} }, // 23 OSM: 2617693 WD: Q121338937 49.34, 8.685 x 49.41, 8.693
    { 247, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8b1c75} }, // 24 OSM: 2617694 WD: Q121338925 49.37, 8.66 x 49.47, 8.691
    { 310, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf39a9a} }, // 26 OSM: 2617695 WD: Q121338888 49.38, 8.658 x 49.43, 8.693
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf39b9b} }, // 1 OSM: 2619044 WD: Q121317818 49.42, 8.463 x 49.55, 8.536
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xb10346} }, // 2 OSM: 2619045 WD: Q121317819 49.48, 8.457 x 49.5, 8.539
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe3000b} }, // 4 OSM: 2619046 WD: Q121317822 49.46, 8.17 x 49.54, 8.509
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00975f} }, // 5 OSM: 2619047 WD: Q111985934 49.4, 8.463 x 49.55, 8.693
    { 60, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xd6ad00} }, // 3 OSM: 2621587 WD: Q121317820 49.45, 8.449 x 49.54, 8.482
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x966c29} }, // 6 OSM: 2621588 WD: Q121317824 49.44, 8.419 x 49.49, 8.525
    { 42, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffcc00} }, // 7 OSM: 2621590 WD: Q121317825 49.48, 8.407 x 49.52, 8.545
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe17500} }, // 8 OSM: 2621591 WD: Q121317826 49.42, 8.407 x 49.52, 8.536
    { 1495, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfcdc12} }, // SFM7 OSM: 2622309 WD: Q15077685 44.55, 7.602 x 45.23, 7.753
    { 42, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0921} }, // 7 OSM: 2622564 WD: Q106767450 52.18, 20.94 x 52.26, 21.06
    { 364, 9938, 9500, LineMetaDataContent::Subway, Color{0xf9e300} }, // Yellow OSM: 2622574 WD: Q595450 42.02, -87.75 x 42.04, -87.67
    { 1500, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x20825c} }, // PAO OSM: 2629939 WD: Q7132125 39.95, -75.76 x 40.05, -75.15
    { 138, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf171ab} }, // 9 OSM: 2629996 WD: Q56302775 46.93, 7.436 x 46.97, 7.468
    { 60, 9962, 9984, LineMetaDataContent::Subway, Color{0xa066aa} }, // 3 OSM: 2635252 WD: Q15731044 59.85, 10.5 x 59.94, 10.85
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffff00} }, // 6 OSM: 2635960 55.67, 52.28 x 55.77, 52.45
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009746} }, // 8 OSM: 2635970 55.67, 52.28 x 55.77, 52.45
    { 16, 10005, 9984, LineMetaDataContent::Subway, Color{0xf26522} }, // 2 OSM: 2636245 WD: Q15731043 59.91, 10.61 x 59.95, 10.92
    { 6, 10027, 9984, LineMetaDataContent::Subway, Color{0x50b848} }, // 5 OSM: 2640907 WD: Q15731051 59.91, 10.71 x 59.97, 10.93
    { 42, NoLogo, 6578, LineMetaDataContent::Tramway, Color{0xce1417} }, // 7 OSM: 2641075 WD: Q123168036 59.88, 30.39 x 59.93, 30.5
    { 1504, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // Meadowlands OSM: 2641818 WD: Q6803384 40.73, -74.1 x 40.83, -74.03
    { 1516, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa0218c} }, // Pascack Valley OSM: 2641819 WD: Q11328810 40.73, -74.1 x 41.11, -74.01
    { 1531, 10049, 860, LineMetaDataContent::Tramway, Color{0x8874c7} }, // U46 OSM: 2642232 WD: Q107740407 51.5, 7.459 x 51.53, 7.471
    { 1366, 10063, 10083, LineMetaDataContent::Tramway, Color{0x873f98} }, // T5 OSM: 2643507 WD: Q3238967 45.73, 4.879 x 45.74, 4.948
    { 60, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xef7f1b} }, // 3 OSM: 2644926 55.72, 52.41 x 55.77, 52.5
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 5 OSM: 2646596 55.72, 52.41 x 55.76, 52.5
    { 42, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x393186} }, // 7 OSM: 2646626 55.69, 52.41 x 55.77, 52.53
    { 529, 10111, 3582, LineMetaDataContent::RapidTransit, Color{0x76777a} }, // C-8 OSM: 2647592 WD: Q8880127 40.38, -4.271 x 40.74, -3.181
    { 687, 10129, 10163, LineMetaDataContent::Tramway, Color{0x802990} }, // A OSM: 2648050 WD: Q2658981 44.83, -0.6686 x 44.89, -0.5081
    { 271, 10189, 10163, LineMetaDataContent::Tramway, Color{0xed164b} }, // B OSM: 2648235 WD: Q2420027 44.79, -0.6632 x 44.89, -0.5415
    { 138, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xdb1702} }, // 9 OSM: 2648370 WD: Q106766521 52.18, 20.94 x 52.25, 21.12
    { 22, NoLogo, 6578, LineMetaDataContent::Tramway, Color{0xce1417} }, // 18 OSM: 2651053 WD: Q123168041 59.99, 30.23 x 60.02, 30.25
    { 341, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 23 OSM: 2651263 59.9, 30.35 x 59.97, 30.5
    { 247, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 24 OSM: 2651264 59.83, 30.38 x 59.93, 30.51
    { 153, NoLogo, 6578, LineMetaDataContent::Tramway, Color{0xce1417} }, // 19 OSM: 2651265 WD: Q123168042 59.98, 30.19 x 59.99, 30.26
    { 1100, NoLogo, 6578, LineMetaDataContent::Tramway, Color{0xce1417} }, // А OSM: 2651266 WD: Q123168077 59.9, 30.44 x 59.92, 30.5
    { 227, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 27 OSM: 2651267 59.83, 30.44 x 59.92, 30.51
    { 714, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 47 OSM: 2652192 60, 30.23 x 60.02, 30.31
    { 298, NoLogo, 6578, LineMetaDataContent::Tramway, Color{0xce1417} }, // 65 OSM: 2652193 WD: Q123168074 59.91, 30.39 x 59.93, 30.5
    { 523, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 57 OSM: 2652194 60, 30.37 x 60.02, 30.44
    { 254, NoLogo, 6578, LineMetaDataContent::Tramway, Color{0xce1417} }, // 38 OSM: 2652196 WD: Q123168052 59.98, 30.35 x 60.05, 30.44
    { 97, NoLogo, 6578, LineMetaDataContent::Tramway, Color{0xce1417} }, // 62 OSM: 2652197 WD: Q123168071 59.83, 30.38 x 59.84, 30.42
    { 174, NoLogo, 6578, LineMetaDataContent::Tramway, Color{0xce1417} }, // 60 OSM: 2652198 WD: Q123168069 59.85, 30.12 x 59.88, 30.26
    { 86, NoLogo, 6578, LineMetaDataContent::Tramway, Color{0xce1417} }, // 61 OSM: 2652199 WD: Q123168070 59.97, 30.34 x 60.05, 30.41
    { 1535, 7769, 7769, LineMetaDataContent::Subway, Color{0xff0000} }, // Metropolitana OSM: 2653212 WD: Q1163754 44.4, 8.894 x 44.43, 8.949
    { 27, 10223, NoLogo, LineMetaDataContent::Subway, Color{0x2c8195} }, // 6 OSM: 2653338 WD: Q6553143 25.03, 102.7 x 25.1, 102.9
    { 403, 10243, 10163, LineMetaDataContent::Tramway, Color{0xcf56a0} }, // C OSM: 2654042 WD: Q2331392 44.77, -0.6237 x 44.92, -0.5499
    { 322, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc4121a} }, // 25 OSM: 2654656 WD: Q47563867 48.22, 16.4 x 48.26, 16.48
    { 1549, 10277, 9500, LineMetaDataContent::Subway, Color{0xe27ea6} }, // Pink OSM: 2656070 WD: Q3112661 41.85, -87.76 x 41.89, -87.63
    { 359, 10299, 9500, LineMetaDataContent::Subway, Color{0x00a1de} }, // Blue OSM: 2672370 WD: Q2534873 41.87, -87.9 x 41.98, -87.63
    { 1554, 10321, 860, LineMetaDataContent::Tramway, Color{0xa3d20b} }, // U47 OSM: 2673747 WD: Q121287774 51.49, 7.382 x 51.55, 7.556
    { 138, 10335, 4324, LineMetaDataContent::Subway, Color{0x87d300} }, // 9 OSM: 2674584 WD: Q5929508 39.81, 116.3 x 39.94, 116.3
    { 1558, 10355, 860, LineMetaDataContent::Tramway, Color{0xfcdc00} }, // U41 OSM: 2674820 WD: Q121288228 51.48, 7.44 x 51.59, 7.502
    { 1562, 10369, 860, LineMetaDataContent::Tramway, Color{0x00a991} }, // U43 OSM: 2675103 WD: Q121287834 51.51, 7.419 x 51.53, 7.625
    { 42, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x9e0234} }, // 7 OSM: 2675693 WD: Q91660996 51.04, 13.63 x 51.14, 13.8
    { 1570, 10383, 9500, LineMetaDataContent::Subway, Color{0x522398} }, // Purple OSM: 2675822 WD: Q3112074 41.88, -87.69 x 42.07, -87.63
    { 63, 10407, 10419, LineMetaDataContent::RapidTransit, Color{0x159dd9} }, // S1 OSM: 2679058 WD: Q17101540 48.17, 16.33 x 48.34, 16.92
    { 51, 10435, 10419, LineMetaDataContent::RapidTransit, Color{0x159dd9} }, // S2 OSM: 2679059 WD: Q96484152 48.08, 16.28 x 48.72, 16.57
    { 217, 10447, 10419, LineMetaDataContent::RapidTransit, Color{0x159dd9} }, // S3 OSM: 2679060 WD: Q96484012 47.81, 16.06 x 48.56, 16.41
    { 51, 10459, 226, LineMetaDataContent::RapidTransit, Color{0x118349} }, // S2 OSM: 2682237 WD: Q63433449 52.28, 9.217 x 52.65, 9.773
    { 1577, 10475, 4324, LineMetaDataContent::Subway, Color{0x007e84} }, // 4S OSM: 2684711 WD: Q5242742 39.67, 116.3 x 39.81, 116.4
    { 149, 10500, 4324, LineMetaDataContent::Subway, Color{0x6a1d44} }, // 15 OSM: 2688949 WD: Q734917 39.99, 116.3 x 40.13, 116.7
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x006b42} }, // 12 OSM: 2690192 WD: Q93767629 51.04, 13.67 x 51.06, 13.81
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x223344} }, // 2 OSM: 2694563 54.26, 48.28 x 54.34, 48.41
    { 310, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00aaad} }, // 26 OSM: 2705952 WD: Q119905487 59.27, 18.27 x 59.29, 18.3
    { 322, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00aaad} }, // 25 OSM: 2705957 WD: Q119905177 59.28, 18.11 x 59.31, 18.31
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff7f50} }, // 2 OSM: 2710819 WD: Q106767016 52.29, 20.93 x 52.34, 20.97
    { 1580, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x003e7e} }, // TRE OSM: 2716975 WD: Q2453601 32.75, -97.33 x 32.82, -96.81
    { 67, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x179ed8} }, // 10 OSM: 2728288 WD: Q16655703 50.06, 14.3 x 50.13, 14.48
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8c683c} }, // 11 OSM: 2728371 WD: Q16655705 50.05, 14.43 x 50.09, 14.5
    { 1584, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0xeb3c2e} }, // S18 OSM: 2729450 WD: Q686782 47.29, 8.547 x 47.37, 8.71
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x4c2d5f} }, // 12 OSM: 2729904 WD: Q16655709 50.03, 14.37 x 50.11, 14.45
    { 56, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // 1 OSM: 2746761 WD: Q12406939 31.77, 35.18 x 31.83, 35.24
    { 11, 10521, 7769, LineMetaDataContent::Subway, Color{0xb395d0} }, // M5 OSM: 2753306 WD: Q3238963 45.48, 9.117 x 45.53, 9.212
    { 27, 10541, NoLogo, LineMetaDataContent::Subway, Color{0xf67599} }, // 6 OSM: 2768662 WD: Q5931449 29.49, 106.4 x 29.85, 106.7
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffff00} }, // 1 OSM: 2773495 WD: Q1484153 47.52, 21.62 x 47.56, 21.63
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe3000b} }, // 1 OSM: 2777016 WD: Q121253956 52.2, 10.51 x 52.33, 10.54
    { 1588, 10566, NoLogo, LineMetaDataContent::Tramway, Color{0x7b2f3d} }, // M-Line OSM: 2788830 WD: Q124774997 32.78, -96.8 x 32.81, -96.79
    { 1595, 10590, 226, LineMetaDataContent::RapidTransit, Color{0xd7171f} }, // S 3 OSM: 2793231 WD: Q62749908 51.31, 11.91 x 51.49, 13.11
    { 60, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x687362} }, // 3 OSM: 2797182 52.5, 103.8 x 52.58, 103.9
    { 1599, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x149943} }, // STY OSM: 2797718 WD: Q7619599 -38.37, 145.1 x -38.14, 145.2
    { 1535, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xed1c24} }, // Metropolitana OSM: 2797904 WD: Q1725884 45.51, 10.21 x 45.58, 10.28
    { 67, 10615, NoLogo, LineMetaDataContent::Tramway, Color{0xce1f75} }, // 10 OSM: 2799185 WD: Q70711877 47.38, 8.536 x 47.45, 8.573
    { 15, 10640, NoLogo, LineMetaDataContent::Tramway, Color{0x92d6e3} }, // 12 OSM: 2799201 WD: Q70711314 47.4, 8.556 x 47.45, 8.608
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x4c677a} }, // 1 OSM: 2801578 52.52, 103.9 x 52.56, 103.9
    { 42, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe5e6ea} }, // 7 OSM: 2802264 52.5, 103.8 x 52.53, 103.9
    { 60, NoLogo, 6578, LineMetaDataContent::Tramway, Color{0xce1417} }, // 3 OSM: 2804939 WD: Q123168034 59.92, 30.28 x 59.97, 30.36
    { 710, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 56 OSM: 2804944 59.86, 30.23 x 59.88, 30.26
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x70492c} }, // 5 OSM: 2807017 WD: Q96483196 47.36, 8.516 x 47.38, 8.572
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xbe8543} }, // 6 OSM: 2807025 WD: Q96483372 47.36, 8.531 x 47.38, 8.572
    { 42, 10665, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 7 OSM: 2807030 WD: Q70712535 47.34, 8.53 x 47.41, 8.597
    { 138, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x322e71} }, // 9 OSM: 2807033 WD: Q70710278 47.37, 8.495 x 47.41, 8.592
    { 145, 10689, NoLogo, LineMetaDataContent::Tramway, Color{0x0093d0} }, // 14 OSM: 2807051 WD: Q70714895 47.37, 8.495 x 47.42, 8.55
    { 55, 10714, NoLogo, LineMetaDataContent::Tramway, Color{0x00923c} }, // 11 OSM: 2807068 WD: Q70714560 47.35, 8.533 x 47.42, 8.583
    { 60, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00923c} }, // 3 OSM: 2807070 WD: Q96483170 47.36, 8.485 x 47.38, 8.567
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x322e71} }, // 4 OSM: 2807089 WD: Q96483185 47.35, 8.49 x 47.39, 8.561
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xcb0a25} }, // 2 OSM: 2807095 WD: Q73249054 47.35, 8.444 x 47.4, 8.561
    { 149, 10739, NoLogo, LineMetaDataContent::Tramway, Color{0xcb0a25} }, // 15 OSM: 2807117 WD: Q70707977 47.37, 8.533 x 47.4, 8.548
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8bc036} }, // 8 OSM: 2807118 WD: Q96483377 47.36, 8.504 x 47.39, 8.567
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf39100} }, // 5 OSM: 2810470 WD: Q121253961 52.23, 10.48 x 52.26, 10.54
    { 26, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x13519c} }, // 16 OSM: 2820891 WD: Q16655718 50.06, 14.3 x 50.08, 14.53
    { 56, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0b0080} }, // 1 OSM: 2826218 WD: Q5017774 29.85, 31.23 x 30.16, 31.34
    { 9, 10764, 9984, LineMetaDataContent::Subway, Color{0x0054a6} }, // 4 OSM: 2827680 WD: Q15731046 59.87, 10.71 x 59.97, 10.93
    { 364, NoLogo, 10781, LineMetaDataContent::Subway, Color{0xffe800} }, // Yellow OSM: 2827687 WD: Q54874971 37.6, -122.5 x 38.02, -121.9
    { 266, 3733, 3762, LineMetaDataContent::RapidTransit, Color{0xf166a7} }, // 40 OSM: 2836163 WD: Q106806725 59.17, 17.63 x 59.86, 18.07
    { 60, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x006531} }, // 3 OSM: 2837394 WD: Q121253959 52.24, 10.47 x 52.29, 10.58
    { 56, 10795, NoLogo, LineMetaDataContent::Subway, Color{0xe60039} }, // 1 OSM: 2843401 WD: Q6850056 28.68, 115.8 x 28.75, 116
    { 786, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xbed639} }, // 82 OSM: 2844184 WD: Q6811974 -37.8, 144.9 x -37.77, 144.9
    { 1603, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x923cb0} }, // T6 OSM: 2850494 WD: Q108046114 50.23, 18.94 x 50.3, 19.06
    { 371, 10821, 10781, LineMetaDataContent::Subway, Color{0xed1c24} }, // Red OSM: 2851513 WD: Q3809179 37.6, -122.5 x 37.94, -122.3
    { 1422, 10838, 10781, LineMetaDataContent::Subway, Color{0xfaa61a} }, // Orange OSM: 2851514 WD: Q3866809 37.37, -122.4 x 37.94, -121.9
    { 639, 10854, 10781, LineMetaDataContent::Subway, Color{0x4db848} }, // Green OSM: 2851729 WD: Q3720557 37.37, -122.5 x 37.81, -121.9
    { 359, 10872, 10781, LineMetaDataContent::Subway, Color{0x00aeef} }, // Blue OSM: 2851730 WD: Q3720569 37.69, -122.5 x 37.81, -121.9
    { 1606, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf3ca00} }, // T14 OSM: 2856767 WD: Q108046257 50.23, 18.99 x 50.27, 19.11
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x86c5a2} }, // 11 OSM: 2858845 WD: Q18165625 -37.82, 144.9 x -37.73, 145
    { 42, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x878a83} }, // 7 OSM: 2860817 WD: Q1138075 59.32, 18.06 x 59.33, 18.11
    { 1610, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00907a} }, // S31 OSM: 2872363 WD: Q106450415 48.99, 8.399 x 49.18, 8.747
    { 1042, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00907a} }, // S32 OSM: 2872364 WD: Q106362984 48.99, 8.399 x 49.16, 8.775
    { 347, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf49694} }, // S51 OSM: 2872365 WD: Q126120770 48.89, 8.262 x 49.23, 8.705
    { 165, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf49694} }, // S52 OSM: 2872366 48.98, 8.262 x 49.23, 8.404
    { 122, 10887, 1396, LineMetaDataContent::Subway, Color{0x2ec6ff} }, // U4 OSM: 2872790 WD: Q209739 53.53, 9.983 x 53.56, 10.04
    { 55, 10902, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff7f50} }, // 11 OSM: 2875658 WD: Q5245830 -23.56, -46.64 x -23.52, -46.19
    { 15, 10914, NoLogo, LineMetaDataContent::RapidTransit, Color{0x1c146b} }, // 12 OSM: 2877633 WD: Q5245789 -23.55, -46.62 x -23.48, -46.33
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8c6e66} }, // 6 OSM: 2877971 52.5, 103.8 x 52.56, 103.9
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xec7394} }, // 4 OSM: 2877979 52.5, 103.8 x 52.53, 103.9
    { 42, 10926, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa8034f} }, // 7 OSM: 2885794 WD: Q3296728 -23.55, -46.87 x -23.19, -46.62
    { 56, 10937, 9984, LineMetaDataContent::Subway, Color{0x00b6f1} }, // 1 OSM: 2890637 WD: Q15731038 59.87, 10.65 x 59.98, 10.82
    { 67, 10954, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00ced1} }, // 10 OSM: 2893113 WD: Q5245819 -23.74, -46.62 x -23.54, -46.39
    { 271, 10966, 5423, LineMetaDataContent::Subway, Color{0xffa500} }, // B OSM: 2896644 WD: Q18420098 6.247, -75.61 x 6.259, -75.57
    { 1616, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x37bbed} }, // TU OSM: 2897278 WD: Q16438501 -34.95, -57.95 x -34.9, -57.92
    { 1619, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x546684} }, // DPM OSM: 2914673 WD: Q1201543 42.32, -83.05 x 42.34, -83.04
    { 313, 11005, 226, LineMetaDataContent::RapidTransit, Color{0xffff00} }, // S 1 OSM: 2920398 WD: Q56600177 51.31, 12.27 x 51.37, 12.41
    { 153, 11030, NoLogo, LineMetaDataContent::Tramway, Color{0xf7942a} }, // 19 OSM: 2921482 WD: Q109462009 59.85, 10.72 x 59.93, 10.8
    { 22, 11054, NoLogo, LineMetaDataContent::Tramway, Color{0xfdb927} }, // 18 OSM: 2921905 WD: Q56850451 59.91, 10.71 x 59.95, 10.78
    { 9, NoLogo, 11074, LineMetaDataContent::Tramway, Color{0xff0000} }, // 4 OSM: 2930171 WD: Q121323126 51.15, 11.8 x 51.16, 11.81
    { 403, 11106, 2914, LineMetaDataContent::Subway, Color{0x003ea1} }, // C OSM: 2931139 WD: Q1157050 -34.63, -58.38 x -34.59, -58.37
    { 271, 11134, 2914, LineMetaDataContent::Subway, Color{0xc20924} }, // B OSM: 2933167 WD: Q1157061 -34.6, -58.49 x -34.57, -58.37
    { 535, 11162, 2914, LineMetaDataContent::Subway, Color{0x6b297e} }, // E OSM: 2933872 WD: Q1044919 -34.64, -58.46 x -34.59, -58.37
    { 275, 11190, 2914, LineMetaDataContent::Subway, Color{0x217861} }, // D OSM: 2934099 WD: Q1157052 -34.61, -58.46 x -34.56, -58.37
    { 34, 11218, 2914, LineMetaDataContent::Subway, Color{0xf4cc21} }, // H OSM: 2934107 WD: Q1132660 -34.64, -58.41 x -34.58, -58.39
    { 433, 11246, 9561, LineMetaDataContent::Subway, Color{0x4b5799} }, // M2 OSM: 2947130 WD: Q1884455 44.35, 26.09 x 44.48, 26.16
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf9b000} }, // 4 OSM: 2951397 WD: Q63350784 52.37, 9.596 x 52.42, 9.819
    { 281, 11262, NoLogo, LineMetaDataContent::Tramway, Color{0x281570} }, // T1 OSM: 2962731 WD: Q6043955 41, 28.86 x 41.03, 28.99
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x75c3b0} }, // 1 OSM: 2969493 WD: Q123363011 56.77, 60.51 x 56.83, 60.61
    { 1026, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x6f1b14} }, // 94 OSM: 2982672 WD: Q121335024 51.48, 11.93 x 51.51, 11.97
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf9b000} }, // 6 OSM: 2991603 WD: Q63350805 52.32, 9.69 x 52.42, 9.837
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf9b000} }, // 11 OSM: 2991649 WD: Q63350814 52.37, 9.713 x 52.39, 9.775
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf9b000} }, // 5 OSM: 2991701 WD: Q63350794 52.36, 9.659 x 52.41, 9.859
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe4003a} }, // 1 OSM: 2995652 WD: Q63344401 52.24, 9.731 x 52.44, 9.86
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe4003a} }, // 2 OSM: 2998555 WD: Q63345326 52.29, 9.734 x 52.42, 9.817
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe4003a} }, // 8 OSM: 2998722 WD: Q63345432 52.33, 9.734 x 52.4, 9.805
    { 231, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x76b82a} }, // 17 OSM: 2998733 WD: Q63348315 52.34, 9.718 x 52.38, 9.743
    { 67, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x76b82a} }, // 10 OSM: 3004809 WD: Q63348270 52.37, 9.664 x 52.39, 9.756
    { 1624, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x051541} }, // 95 OSM: 3006197 WD: Q121335025 51.42, 11.96 x 51.52, 11.99
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xed1943} }, // 12 OSM: 3009639 WD: Q2189640 51.88, 4.471 x 51.92, 4.568
    { 60, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0069b4} }, // 3 OSM: 3016071 WD: Q63348707 52.33, 9.69 x 52.44, 9.848
    { 42, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0069b4} }, // 7 OSM: 3038575 WD: Q63348805 52.33, 9.69 x 52.41, 9.854
    { 138, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0069b4} }, // 9 OSM: 3038600 WD: Q63349759 52.34, 9.667 x 52.38, 9.744
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008dd2} }, // 2 OSM: 3060916 WD: Q123363012 56.84, 60.56 x 56.9, 60.64
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff7f27} }, // 1 OSM: 3061200 WD: Q121361537 50.49, 12.14 x 50.51, 12.18
    { 60, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00a2e8} }, // 3 OSM: 3061204 WD: Q121361539 50.49, 12.1 x 50.51, 12.14
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf5b2b6} }, // 4 OSM: 3066680 WD: Q123363014 56.8, 60.6 x 56.86, 60.67
    { 149, 11290, 9428, LineMetaDataContent::Subway, Color{0xa50034} }, // 15 OSM: 3094380 WD: Q3240151 48.78, 2.197 x 48.92, 2.583
    { 1627, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x236214} }, // UP-N OSM: 3117549 WD: Q7885883 41.88, -87.85 x 42.59, -87.64
    { 1632, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff821d} }, // MD-N OSM: 3117594 WD: Q16982046 41.88, -88.18 x 42.4, -87.64
    { 1637, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7c53af} }, // NCS OSM: 3117600 WD: Q7054760 41.88, -88.09 x 42.48, -87.64
    { 1641, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfae218} }, // UP-NW OSM: 3117607 WD: Q16985937 41.88, -88.62 x 42.42, -87.64
    { 1647, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfeb8fa} }, // UP-W OSM: 3117615 WD: Q7885886 41.86, -88.47 x 41.9, -87.64
    { 1652, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x77b337} }, // BNSF OSM: 3117619 WD: Q4836140 41.76, -88.31 x 41.88, -87.64
    { 1657, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xee4848} }, // HC OSM: 3117625 WD: Q5738778 41.52, -88.08 x 41.88, -87.64
    { 653, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa81818} }, // RI OSM: 3117651 41.51, -88.08 x 41.88, -87.63
    { 1660, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x117bac} }, // SWS OSM: 3117664 WD: Q7565331 41.42, -87.99 x 41.88, -87.64
    { 1664, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf67b7b} }, // ME OSM: 3117670 WD: Q4501968 41.46, -87.72 x 41.89, -87.55
    { 1667, 11326, 226, LineMetaDataContent::RapidTransit, Color{0x00ffff} }, // S 2 OSM: 3119892 WD: Q56809294 51.31, 12.23 x 51.87, 12.66
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xafe0ee} }, // 8 OSM: 3144745 WD: Q56302773 46.94, 7.374 x 46.95, 7.487
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x088742} }, // 2 OSM: 3152801 WD: Q121311235 51.13, 14.94 x 51.17, 14.99
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff2e17} }, // 1 OSM: 3152809 WD: Q121311074 51.12, 14.97 x 51.17, 14.99
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf7bc58} }, // 5 OSM: 3154103 WD: Q123363015 56.85, 60.59 x 56.89, 60.67
    { 1671, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // LBN OSM: 3155062 WD: Q46654325 -34.59, -58.87 x -34.42, -58.37
    { 351, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // FM1 OSM: 3158700 41.12, 16.78 x 41.14, 16.87
    { 432, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffc100} }, // FM2 OSM: 3158701 41.11, 16.68 x 41.14, 16.87
    { 41, 11351, 226, LineMetaDataContent::RapidTransit, Color{0xa5ce43} }, // S7 OSM: 3168072 WD: Q63433461 52.37, 9.739 x 52.62, 10.06
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x26ac9f} }, // 1 OSM: 3171605 WD: Q120720199 50.05, 19.91 x 50.09, 20.05
    { 60, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009abd} }, // 3 OSM: 3171607 WD: Q120720201 50.01, 19.93 x 50.09, 20.02
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xd19563} }, // 4 OSM: 3171608 WD: Q120720202 50.06, 19.88 x 50.08, 20.07
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf08365} }, // 5 OSM: 3171635 WD: Q120720203 50.07, 19.93 x 50.09, 20.05
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x15834a} }, // 6 OSM: 3171642 WD: Q120720204 50.03, 19.9 x 50.06, 20
    { 67, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf3c13d} }, // 10 OSM: 3171684 WD: Q120720207 50.01, 19.93 x 50.07, 20.12
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xd73c31} }, // 13 OSM: 3171685 WD: Q120720210 50.01, 19.9 x 50.08, 20.02
    { 145, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe5097f} }, // 14 OSM: 3171686 WD: Q120720211 50.06, 19.9 x 50.1, 20.04
    { 26, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x3dab46} }, // 16 OSM: 3171687 WD: Q120720212 50.07, 20 x 50.1, 20.07
    { 22, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x962983} }, // 18 OSM: 3171688 WD: Q120720215 50.02, 19.89 x 50.11, 19.96
    { 138, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xa2d9f7} }, // 9 OSM: 3171689 WD: Q120720206 50.01, 19.96 x 50.1, 20.04
    { 243, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x3dab46} }, // 20 OSM: 3171692 WD: Q120720217 50.04, 19.9 x 50.07, 20
    { 74, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x86755d} }, // 21 OSM: 3171693 WD: Q120720218 50.06, 20.01 x 50.1, 20.12
    { 110, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0094d6} }, // 22 OSM: 3171694 WD: Q120720220 50.01, 19.92 x 50.09, 20.07
    { 231, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xb96638} }, // 17 OSM: 3171695 WD: Q120720213 50.02, 19.89 x 50.08, 19.96
    { 247, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xb2ad81} }, // 24 OSM: 3171696 WD: Q120720221 50.01, 19.88 x 50.08, 19.98
    { 235, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf39430} }, // 50 OSM: 3171697 WD: Q120720225 50.01, 19.93 x 50.11, 19.98
    { 149, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 15 OSM: 3184018 55.8, 37.39 x 55.81, 37.51
    { 341, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 23 OSM: 3184019 55.81, 37.49 x 55.84, 37.53
    { 392, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 30 OSM: 3184021 55.8, 37.39 x 55.84, 37.53
    { 1091, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 28 OSM: 3184024 55.78, 37.45 x 55.81, 37.51
    { 67, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 10 OSM: 3184063 WD: Q122585351 55.8, 37.39 x 55.81, 37.46
    { 74, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 21 OSM: 3184064 55.8, 37.39 x 55.81, 37.46
    { 227, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 27 OSM: 3184107 55.81, 37.5 x 55.84, 37.58
    { 322, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 25 OSM: 3186266 WD: Q122585359 55.79, 37.62 x 55.83, 37.69
    { 687, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xca305b} }, // A OSM: 3190626 WD: Q3537211 47.34, 0.6578 x 47.42, 0.7119
    { 59, 11367, NoLogo, LineMetaDataContent::Tramway, Color{0x00b26b} }, // 13 OSM: 3201250 WD: Q109462007 59.85, 10.59 x 59.93, 10.8
    { 55, 11391, NoLogo, LineMetaDataContent::Tramway, Color{0x82c341} }, // 11 OSM: 3218724 WD: Q109462005 59.91, 10.72 x 59.96, 10.79
    { 15, 11415, NoLogo, LineMetaDataContent::Tramway, Color{0xa166aa} }, // 12 OSM: 3221100 WD: Q109462006 59.91, 10.7 x 59.96, 10.79
    { 9, 11439, 11484, LineMetaDataContent::Subway, Color{0xf1ce00} }, // 4 OSM: 3228501 WD: Q1597847 45.51, -73.56 x 45.52, -73.52
    { 16, 11527, 11484, LineMetaDataContent::Subway, Color{0xd06d07} }, // 2 OSM: 3228502 WD: Q967397 45.47, -73.73 x 45.56, -73.55
    { 6, 11572, 11484, LineMetaDataContent::Subway, Color{0x3465b4} }, // 5 OSM: 3228503 WD: Q1726049 45.49, -73.63 x 45.56, -73.6
    { 56, 11617, 11484, LineMetaDataContent::Subway, Color{0x5f8c55} }, // 1 OSM: 3228504 WD: Q1925762 45.45, -73.6 x 45.6, -73.53
    { 16, 11662, NoLogo, LineMetaDataContent::Subway, Color{0x00629b} }, // 2 OSM: 3244073 WD: Q1047377 22.99, 113.3 x 23.24, 113.3
    { 116, 11682, 832, LineMetaDataContent::Subway, Color{0xa762a4} }, // U2 OSM: 3245522 WD: Q873397 48.21, 16.36 x 48.23, 16.51
    { 1675, 11694, NoLogo, LineMetaDataContent::Tramway, Color{0x802168} }, // C4 OSM: 3252393 WD: Q107432442 37.6, -0.9773 x 37.65, -0.7876
    { 60, 11713, NoLogo, LineMetaDataContent::Subway, Color{0xd9001c} }, // 3 OSM: 3252762 WD: Q3294315 -23.55, -46.67 x -23.53, -46.47
    { 60, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff091d} }, // 3 OSM: 3257819 WD: Q124657531 55.73, 49.1 x 55.79, 49.15
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x01959a} }, // 1 OSM: 3257821 WD: Q110315656 55.77, 49.07 x 55.86, 49.11
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x2a6f39} }, // 4 OSM: 3257827 WD: Q110365894 55.74, 49.17 x 55.82, 49.24
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffd028} }, // 5 OSM: 3257853 WD: Q124657533 55.73, 49.07 x 55.83, 49.22
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff026b} }, // 6 OSM: 3257865 WD: Q124657536 55.82, 49.08 x 55.86, 49.18
    { 60, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 3 OSM: 3258552 47.2, 38.9 x 47.23, 38.94
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 4 OSM: 3258575 47.2, 38.88 x 47.26, 38.92
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 5 OSM: 3258583 47.2, 38.89 x 47.24, 38.94
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 6 OSM: 3258591 47.2, 38.88 x 47.24, 38.91
    { 42, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 7 OSM: 3258600 47.22, 38.89 x 47.26, 38.92
    { 231, 11727, NoLogo, LineMetaDataContent::Tramway, Color{0xef4123} }, // 17 OSM: 3259480 WD: Q109462008 59.91, 10.71 x 59.95, 10.78
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 1 OSM: 3272067 47.2, 38.88 x 47.23, 38.92
    { 113, 11751, 832, LineMetaDataContent::Subway, Color{0xe20613} }, // U1 OSM: 3278144 WD: Q663755 48.14, 16.37 x 48.28, 16.45
    { 1678, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x202f7b} }, // T16 OSM: 3281921 WD: Q108046378 50.23, 18.99 x 50.29, 19.03
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 2 OSM: 3285146 47.2, 38.92 x 47.26, 38.94
    { 217, 11763, 226, LineMetaDataContent::RapidTransit, Color{0xf5821f} }, // S3 OSM: 3298634 WD: Q116212120 46.54, 14.24 x 46.84, 14.86
    { 42, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 7 OSM: 3299881 WD: Q122585349 55.77, 37.58 x 55.82, 37.73
    { 67, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x9e2a96} }, // 10 OSM: 3303135 WD: Q121317828 49.47, 8.412 x 49.5, 8.453
    { 687, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xef3f30} }, // A OSM: 3309751 WD: Q3239051 47.44, -0.5963 x 47.51, -0.5454
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009846} }, // 6 OSM: 3314564 WD: Q123363016 56.82, 60.55 x 56.89, 60.64
    { 26, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xaf1867} }, // 16 OSM: 3315633 WD: Q121335023 51.43, 11.9 x 51.48, 11.99
    { 9, 11779, 9428, LineMetaDataContent::Subway, Color{0xa0006e} }, // 4 OSM: 3326845 WD: Q50743 48.8, 2.316 x 48.9, 2.359
    { 145, 11814, 9428, LineMetaDataContent::Subway, Color{0x640082} }, // 14 OSM: 3328694 WD: Q50761 48.83, 2.31 x 48.92, 2.387
    { 56, 11850, 9428, LineMetaDataContent::Subway, Color{0xffbe00} }, // 1 OSM: 3328695 WD: Q13224 48.84, 2.23 x 48.89, 2.441
    { 138, 11885, 9428, LineMetaDataContent::Subway, Color{0xd2d200} }, // 9 OSM: 3328717 WD: Q50753 48.83, 2.231 x 48.87, 2.442
    { 122, 11920, 11936, LineMetaDataContent::Subway, Color{0x00a082} }, // U4 OSM: 3328726 WD: Q20439761 48.13, 11.52 x 48.15, 11.62
    { 67, 11960, 9428, LineMetaDataContent::Subway, Color{0xdc9600} }, // 10 OSM: 3328741 WD: Q50754 48.84, 2.228 x 48.85, 2.365
    { 27, 11996, 9428, LineMetaDataContent::Subway, Color{0x82dc73} }, // 6 OSM: 3328765 WD: Q50746 48.83, 2.285 x 48.87, 2.402
    { 42, 12031, 9428, LineMetaDataContent::Subway, Color{0xff82b4} }, // 7 OSM: 3328805 WD: Q50748 48.79, 2.332 x 48.92, 2.411
    { 42, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x18b2ae} }, // 7 OSM: 3331526 WD: Q123363017 56.84, 60.5 x 56.9, 60.64
    { 1682, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xbb0022} }, // KT OSM: 3348003 WD: Q1510414 51.08, 2.581 x 51.34, 3.285
    { 1685, 12066, NoLogo, LineMetaDataContent::LocalTrain, Color{0xeb7405} }, // RB55 OSM: 3366300 WD: Q63224617 52.64, 13.04 x 52.75, 13.21
    { 1690, 12086, NoLogo, LineMetaDataContent::LocalTrain, Color{0x007734} }, // RB20 OSM: 3366342 WD: Q68007873 52.39, 12.97 x 52.75, 13.29
    { 56, 12106, NoLogo, LineMetaDataContent::Tramway, Color{0xe3000f} }, // 1 OSM: 3367545 WD: Q78199222 48.34, 10.87 x 48.38, 10.94
    { 9, 12126, NoLogo, LineMetaDataContent::Tramway, Color{0x941680} }, // 4 OSM: 3367554 WD: Q121146092 48.37, 10.88 x 48.4, 10.89
    { 1695, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0097ba} }, // S42 OSM: 3368507 WD: Q121237874 49.14, 8.875 x 49.25, 9.229
    { 50, 12146, 226, LineMetaDataContent::RapidTransit, Color{0xff9e00} }, // RS2 OSM: 3372285 WD: Q84703704 52.79, 8.597 x 53.57, 8.895
    { 62, 12161, 226, LineMetaDataContent::RapidTransit, Color{0x0000ee} }, // RS1 OSM: 3372313 WD: Q84703702 52.92, 8.516 x 53.21, 9.238
    { 1239, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 31 OSM: 3375725 55.78, 37.45 x 55.82, 37.5
    { 284, 12176, NoLogo, LineMetaDataContent::LocalTrain, Color{0xffffff} }, // RB 58 OSM: 3379684 WD: Q108409640 47.85, 11.53 x 48.14, 12.12
    { 306, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0xec008c} }, // S4 OSM: 3379960 WD: Q106453719 47.04, 8.814 x 47.48, 9.651
    { 1699, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0xfdd456} }, // S 5X OSM: 3382470 WD: Q63216058 50.7, 11.99 x 51.48, 12.48
    { 170, 12193, 8171, LineMetaDataContent::Tramway, Color{0xf3c300} }, // 44 OSM: 3394367 WD: Q1931983 50.82, 4.409 x 50.84, 4.514
    { 646, 12215, 8171, LineMetaDataContent::Tramway, Color{0xe43c2e} }, // 39 OSM: 3394368 WD: Q2719066 50.83, 4.409 x 50.85, 4.504
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x006680} }, // 5 OSM: 3398798 WD: Q121691519 54.16, 19.4 x 54.19, 19.43
    { 339, 12237, NoLogo, LineMetaDataContent::LocalTrain, Color{0xeb7405} }, // RB23 OSM: 3399395 WD: Q108546612 52.36, 12.97 x 52.53, 13.6
    { 67, 12256, 12277, LineMetaDataContent::Subway, Color{0xeac384} }, // 10 OSM: 3400216 WD: Q6553053 31.98, 118.6 x 32.07, 118.8
    { 56, 12300, 12277, LineMetaDataContent::Subway, Color{0x00a2df} }, // 1 OSM: 3400217 WD: Q6127241 31.9, 118.8 x 32.15, 118.9
    { 1704, 12320, NoLogo, LineMetaDataContent::LocalTrain, Color{0xff5900} }, // RB13 OSM: 3407777 WD: Q63434598 52.53, 12.94 x 52.55, 13.31
    { 16, 12340, 12277, LineMetaDataContent::Subway, Color{0xc7003f} }, // 2 OSM: 3413089 WD: Q5960302 31.96, 118.7 x 32.12, 119
    { 1709, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // MTM OSM: 3413332 WD: Q1337838 -32.96, -68.85 x -32.84, -68.78
    { 63, 12360, 226, LineMetaDataContent::RapidTransit, Color{0x0095da} }, // S1 OSM: 3413905 WD: Q600891 49.97, 8.244 x 50.11, 8.885
    { 51, 12377, 226, LineMetaDataContent::RapidTransit, Color{0xee1c23} }, // S2 OSM: 3414422 WD: Q1985592 50.01, 8.31 x 50.16, 8.813
    { 47, 12394, 226, LineMetaDataContent::RapidTransit, Color{0xd7df23} }, // S8 OSM: 3415070 WD: Q2005458 49.98, 8.242 x 50.13, 8.931
    { 631, 12411, 226, LineMetaDataContent::RapidTransit, Color{0x91268f} }, // S9 OSM: 3415113 WD: Q508402 49.98, 8.244 x 50.13, 8.931
    { 1713, 12428, 3582, LineMetaDataContent::RapidTransit, Color{0xfab700} }, // C-5 OSM: 3418151 WD: Q3832677 40.25, -3.883 x 40.41, -3.677
    { 15, 12446, NoLogo, LineMetaDataContent::Tramway, Color{0xbb0022} }, // 12 OSM: 3419132 WD: Q2200976 51.22, 4.42 x 51.23, 4.44
    { 138, 12469, NoLogo, LineMetaDataContent::Tramway, Color{0xee8822} }, // 9 OSM: 3419133 WD: Q1891687 51.2, 4.35 x 51.22, 4.484
    { 247, 12491, NoLogo, LineMetaDataContent::Tramway, Color{0x77ccaa} }, // 24 OSM: 3419134 WD: Q2483765 51.2, 4.408 x 51.24, 4.484
    { 60, 12514, NoLogo, LineMetaDataContent::Tramway, Color{0xffcc11} }, // 3 OSM: 3419435 WD: Q3238908 51.22, 4.305 x 51.26, 4.464
    { 9, 12536, NoLogo, LineMetaDataContent::Tramway, Color{0x1199dd} }, // 4 OSM: 3419473 WD: Q2344285 51.18, 4.372 x 51.22, 4.435
    { 6, 12558, NoLogo, LineMetaDataContent::Tramway, Color{0x771133} }, // 5 OSM: 3419525 WD: Q2147524 51.22, 4.345 x 51.23, 4.512
    { 27, 12580, NoLogo, LineMetaDataContent::Tramway, Color{0xdd0077} }, // 6 OSM: 3419912 WD: Q2128494 51.18, 4.391 x 51.26, 4.443
    { 42, 12602, NoLogo, LineMetaDataContent::Tramway, Color{0x0044bb} }, // 7 OSM: 3420306 WD: Q2413292 51.17, 4.4 x 51.23, 4.451
    { 67, 12624, NoLogo, LineMetaDataContent::Tramway, Color{0xbbdd00} }, // 10 OSM: 3420544 WD: Q2318513 51.17, 4.362 x 51.23, 4.512
    { 149, 12647, NoLogo, LineMetaDataContent::Tramway, Color{0xffffff} }, // 15 OSM: 3420997 WD: Q959739 51.17, 4.362 x 51.22, 4.494
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf5d200} }, // 1 OSM: 3430333 WD: Q122382395 49.72, 13.37 x 49.78, 13.4
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf5d200} }, // 2 OSM: 3430559 WD: Q122382396 49.73, 13.32 x 49.75, 13.41
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf5d200} }, // 4 OSM: 3430578 WD: Q122382397 49.73, 13.36 x 49.78, 13.38
    { 1620, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x913108} }, // PM OSM: 3433159 WD: Q113367771 37.78, -122.4 x 37.81, -122.4
    { 1718, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x913108} }, // PH OSM: 3433160 WD: Q121410548 37.78, -122.4 x 37.81, -122.4
    { 572, 12670, NoLogo, LineMetaDataContent::RapidTransit, Color{0x549dbf} }, // K OSM: 3433320 WD: Q6342899 37.72, -122.5 x 37.79, -122.4
    { 576, 12691, NoLogo, LineMetaDataContent::RapidTransit, Color{0x932290} }, // L OSM: 3435879 WD: Q16981005 37.74, -122.5 x 37.79, -122.4
    { 410, 12710, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008851} }, // M OSM: 3435882 WD: Q6720518 37.71, -122.5 x 37.79, -122.4
    { 680, 12732, NoLogo, LineMetaDataContent::RapidTransit, Color{0x004988} }, // N OSM: 3435884 WD: Q6956302 37.76, -122.5 x 37.79, -122.4
    { 153, 12749, 8171, LineMetaDataContent::Tramway, Color{0xe43c2e} }, // 19 OSM: 3437796 WD: Q2702907 50.86, 4.275 x 50.9, 4.357
    { 1721, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x37bbed} }, // LBS OSM: 3443504 WD: Q67311453 -34.85, -59.05 x -34.65, -58.42
    { 125, 12771, 11936, LineMetaDataContent::Subway, Color{0xa06e1e} }, // U5 OSM: 3475206 WD: Q3832790 48.09, 11.5 x 48.14, 11.65
    { 128, 12787, 11936, LineMetaDataContent::Subway, Color{0x005a96} }, // U6 OSM: 3477966 WD: Q751039 48.11, 11.47 x 48.27, 11.67
    { 119, 12803, 11936, LineMetaDataContent::Subway, Color{0xe66432} }, // U3 OSM: 3484056 WD: Q20439760 48.09, 11.48 x 48.19, 11.59
    { 160, 12819, NoLogo, LineMetaDataContent::LocalTrain, Color{0x992746} }, // RB49 OSM: 3490614 WD: Q84436359 51.44, 13.25 x 51.75, 14.32
    { 39, 12839, NoLogo, LineMetaDataContent::Tramway, Color{0xf38b00} }, // T OSM: 3494094 WD: Q1999971 47.24, -122.5 x 47.27, -122.4
    { 511, 12871, NoLogo, LineMetaDataContent::Subway, Color{0x000000} }, // L2 OSM: 3517295 WD: Q3011583 43.24, -3.042 x 43.33, -2.881
    { 128, 12894, 1396, LineMetaDataContent::Subway, Color{0x007ec6} }, // U6 OSM: 3524791 WD: Q19863008 50.11, 8.624 x 50.14, 8.708
    { 290, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x66c18c} }, // S6 OSM: 3529247 WD: Q108602196 46.92, 8.814 x 47.23, 9.084
    { 113, 12911, 11936, LineMetaDataContent::Subway, Color{0x46b450} }, // U1 OSM: 3531712 WD: Q20439756 48.1, 11.53 x 48.18, 11.58
    { 116, 12927, 11936, LineMetaDataContent::Subway, Color{0xb4283c} }, // U2 OSM: 3531713 WD: Q830301 48.11, 11.54 x 48.21, 11.7
    { 131, 12943, 11936, LineMetaDataContent::Subway, Color{0x46b450} }, // U7 OSM: 3531714 WD: Q20439774 48.1, 11.53 x 48.18, 11.65
    { 134, 12959, 11936, LineMetaDataContent::Subway, Color{0xb4283c} }, // U8 OSM: 3531715 WD: Q20439777 48.1, 11.56 x 48.18, 11.65
    { 63, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x006536} }, // S1 OSM: 3533698 WD: Q106453739 47.4, 8.632 x 47.7, 9.4
    { 6, 12975, NoLogo, LineMetaDataContent::Subway, Color{0x9200c3} }, // 5 OSM: 3539820 WD: Q3308465 -23.66, -46.77 x -23.59, -46.63
    { 687, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe3000b} }, // A OSM: 3555528 WD: Q107044417 49.49, 0.09576 x 49.53, 0.137
    { 271, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00963e} }, // B OSM: 3555531 WD: Q107044421 49.49, 0.09576 x 49.52, 0.1801
    { 1725, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf49fc5} }, // T7 OSM: 3571840 WD: Q108046131 50.26, 18.92 x 50.35, 19.06
    { 1728, 12989, NoLogo, LineMetaDataContent::LongDistanceTrain, Color{0x0e7135} }, // IC LSA<=>BRA OSM: 3572421 WD: Q917100 38.71, -9.123 x 41.55, -8.415
    { 1741, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x50b948} }, // U BRA OSM: 3579399 WD: Q124220670 41.14, -8.61 x 41.55, -8.434
    { 646, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 39 OSM: 3587361 59.86, 30.38 x 59.93, 30.47
    { 700, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffdd00} }, // T2 OSM: 3589646 WD: Q3239232 45.44, 4.384 x 45.45, 4.403
    { 1295, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xafcb07} }, // T3 OSM: 3589647 WD: Q3239231 45.42, 4.378 x 45.47, 4.405
    { 56, 13006, NoLogo, LineMetaDataContent::Subway, Color{0x1a5ba3} }, // 1 OSM: 3596996 WD: Q3362568 -23.65, -46.64 x -23.48, -46.6
    { 9, 13020, NoLogo, LineMetaDataContent::Subway, Color{0xffd700} }, // 4 OSM: 3613482 WD: Q3308457 -23.59, -46.73 x -23.54, -46.63
    { 371, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xcd5c5c} }, // Red OSM: 3616739 WD: Q2472181 53.28, -6.438 x 53.35, -6.229
    { 60, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00bb00} }, // 3 OSM: 3618379 WD: Q107187377 58.58, 16.13 x 58.61, 16.19
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xcc0000} }, // 2 OSM: 3618409 WD: Q107187376 58.55, 16.13 x 58.61, 16.23
    { 16, 13034, NoLogo, LineMetaDataContent::Subway, Color{0x008162} }, // 2 OSM: 3619672 WD: Q588499 -23.6, -46.69 x -23.55, -46.58
    { 1747, 13048, 5804, LineMetaDataContent::Tramway, Color{0x009641} }, // T3b OSM: 3662457 WD: Q3136247 48.85, 2.274 x 48.9, 2.411
    { 281, 13082, 10083, LineMetaDataContent::Tramway, Color{0x873f98} }, // T1 OSM: 3667340 WD: Q2903 45.73, 4.817 x 45.79, 4.884
    { 1751, NoLogo, 10083, LineMetaDataContent::Tramway, Color{0xb80e28} }, // Rhônexpress OSM: 3667553 WD: Q1559 45.72, 4.862 x 45.78, 5.077
    { 700, 13102, 10083, LineMetaDataContent::Tramway, Color{0x873f98} }, // T2 OSM: 3667554 WD: Q2906 45.69, 4.819 x 45.75, 4.956
    { 1295, 13122, 10083, LineMetaDataContent::Tramway, Color{0x873f98} }, // T3 OSM: 3667555 WD: Q2911 45.75, 4.862 x 45.78, 5.035
    { 1363, 13142, 10083, LineMetaDataContent::Tramway, Color{0x873f98} }, // T4 OSM: 3667556 WD: Q2918 45.69, 4.858 x 45.78, 4.888
    { 271, 13162, 13183, LineMetaDataContent::Subway, Color{0x007dc5} }, // B OSM: 3687323 WD: Q2965 45.7, 4.802 x 45.77, 4.863
    { 275, 13212, 13183, LineMetaDataContent::Subway, Color{0x00ac4d} }, // D OSM: 3687324 WD: Q2976 45.7, 4.803 x 45.78, 4.89
    { 403, 13233, 13183, LineMetaDataContent::Subway, Color{0xf99d1d} }, // C OSM: 3687325 WD: Q2969 45.77, 4.827 x 45.79, 4.836
    { 687, 13254, 13183, LineMetaDataContent::Subway, Color{0xee3898} }, // A OSM: 3687326 WD: Q2944 45.75, 4.826 x 45.77, 4.922
    { 119, 13275, 832, LineMetaDataContent::Subway, Color{0xef7c00} }, // U3 OSM: 3752340 WD: Q876472 48.17, 16.31 x 48.21, 16.42
    { 138, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x93c13b} }, // 9 OSM: 3757041 WD: Q121317827 49.46, 8.17 x 49.49, 8.523
    { 97, 13287, 8171, LineMetaDataContent::Tramway, Color{0xf29dc3} }, // 62 OSM: 3775501 WD: Q2544169 50.86, 4.334 x 50.88, 4.435
    { 1764, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // Line 3 OSM: 3788350 WD: Q341464 29.25, 47.97 x 29.26, 47.97
    { 559, 13309, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 48 OSM: 3820771 WD: Q15982247 47.44, 19.03 x 47.5, 19.06
    { 60, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 3 OSM: 3822945 WD: Q121539704 55.16, 30.21 x 55.2, 30.24
    { 42, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 7 OSM: 3823035 WD: Q121539707 55.16, 30.12 x 55.2, 30.27
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 1 OSM: 3823370 55.16, 30.12 x 55.2, 30.23
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 2 OSM: 3823520 WD: Q121539702 55.16, 30.12 x 55.19, 30.24
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 6 OSM: 3824263 WD: Q121539706 55.16, 30.12 x 55.2, 30.19
    { 138, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 9 OSM: 3824285 WD: Q121539710 55.16, 30.12 x 55.2, 30.2
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 8 OSM: 3824316 WD: Q121539708 55.16, 30.14 x 55.2, 30.24
    { 871, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x37bbed} }, // LR OSM: 3846824 WD: Q3239186 -35.58, -59.09 x -34.63, -57.95
    { 1091, 13333, 19, LineMetaDataContent::Tramway, Color{0x00a082} }, // 28 OSM: 3858971 WD: Q20439076 48.13, 11.56 x 48.17, 11.58
    { 60, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xbbee00} }, // 3 OSM: 3862190 WD: Q100159791 51.27, 9.441 x 51.34, 9.518
    { 42, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf5f000} }, // 7 OSM: 3862890 WD: Q114442370 51.27, 9.441 x 51.33, 9.541
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x924192} }, // 6 OSM: 3883145 WD: Q121361542 50.49, 12.11 x 50.53, 12.18
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x880015} }, // 5 OSM: 3883412 WD: Q121361541 50.49, 12.11 x 50.52, 12.17
    { 1547, 13354, 13384, LineMetaDataContent::Subway, Color{0xed1c24} }, // a OSM: 3889841 WD: Q24641190 48.09, -1.711 x 48.12, -1.644
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008995} }, // 12 OSM: 3903646 WD: Q18165631 -37.86, 145 x -37.81, 145
    { 403, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe4007c} }, // C OSM: 3921484 WD: Q3239086 45.17, 5.69 x 45.19, 5.776
    { 535, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x58318a} }, // E OSM: 3921488 WD: Q3239103 45.17, 5.661 x 45.26, 5.72
    { 271, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009b3a} }, // B OSM: 3921491 WD: Q3239068 45.18, 5.698 x 45.21, 5.787
    { 687, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0076bd} }, // A OSM: 3921492 WD: Q3239056 45.14, 5.671 x 45.2, 5.734
    { 275, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf39a00} }, // D OSM: 3921494 WD: Q3239096 45.17, 5.754 x 45.19, 5.759
    { 352, 13406, 2965, LineMetaDataContent::Subway, Color{0x007d58} }, // M1 OSM: 3931373 WD: Q1880894 55.62, 12.49 x 55.69, 12.59
    { 56, 13418, NoLogo, LineMetaDataContent::Subway, Color{0xf3d03e} }, // 1 OSM: 3936877 WD: Q1047385 23.07, 113.2 x 23.15, 113.3
    { 290, 2455, 226, LineMetaDataContent::RapidTransit, Color{0xd4b4c4} }, // S6 OSM: 3937942 WD: Q680235 47.25, 11.1 x 47.49, 11.4
    { 352, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe5442e} }, // M1 OSM: 3939086 WD: Q2740923 50.4, 4.271 x 50.42, 4.452
    { 1772, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x233e81} }, // TL OSM: 3939642 WD: Q2576140 19.26, -99.15 x 19.34, -99.11
    { 6, 13438, NoLogo, LineMetaDataContent::Subway, Color{0xc5003e} }, // 5 OSM: 3967180 WD: Q862888 23.05, 113.2 x 23.15, 113.5
    { 1775, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8ac53a} }, // T0 OSM: 3981129 WD: Q108045375 50.26, 18.97 x 50.29, 19.07
    { 1778, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x7fa5d7} }, // T13 OSM: 3981303 WD: Q108046225 50.26, 18.94 x 50.3, 19.03
    { 1782, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x4499a8} }, // T17 OSM: 3981695 WD: Q108046412 50.28, 18.73 x 50.35, 18.95
    { 1786, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8ac53a} }, // T9 OSM: 3981764 WD: Q108046147 50.27, 18.87 x 50.3, 18.95
    { 1789, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x664c9c} }, // T15 OSM: 3984435 WD: Q108046344 50.26, 19.01 x 50.3, 19.2
    { 1793, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf2665b} }, // T24 OSM: 3990046 WD: Q108046716 50.27, 19.08 x 50.33, 19.15
    { 1797, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x650133} }, // T21 OSM: 3990849 WD: Q108046550 50.27, 19.08 x 50.34, 19.27
    { 1801, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc5daf0} }, // T22 OSM: 3990873 WD: Q108046617 50.32, 19.07 x 50.34, 19.27
    { 1805, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe897bb} }, // T27 OSM: 3991031 WD: Q108046791 50.27, 19.11 x 50.33, 19.23
    { 41, NoLogo, 13458, LineMetaDataContent::RapidTransit, Color{0xf07f3a} }, // S7 OSM: 4006931 WD: Q115689937 46.93, 7.438 x 46.98, 7.563
    { 1809, 13474, 5804, LineMetaDataContent::Tramway, Color{0xb1a245} }, // T8 OSM: 4007734 WD: Q3239029 48.93, 2.294 x 48.96, 2.358
    { 341, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x66ba86} }, // 23 OSM: 4016993 WD: Q2914455 51.88, 4.432 x 51.92, 4.574
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00bb00} }, // 1 OSM: 4037940 WD: Q105476776 51.31, 9.423 x 51.37, 9.502
    { 277, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa3429b} }, // TER T1 OSM: 4042689 WD: Q123466158 47.22, -1.549 x 47.72, -1.371
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009036} }, // 1 OSM: 4043180 WD: Q121324553 51.89, 11.05 x 51.9, 11.07
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe2001a} }, // 2 OSM: 4043225 WD: Q121324704 51.87, 11.04 x 51.9, 11.07
    { 1812, 13507, 3582, LineMetaDataContent::RapidTransit, Color{0x000000} }, // S-2 OSM: 4051679 WD: Q107407547 43.34, -3.85 x 43.46, -3.707
    { 1816, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xdb0032} }, // GLNELG OSM: 4055996 WD: Q123413316 -34.98, 138.5 x -34.91, 138.6
    { 359, 13539, NoLogo, LineMetaDataContent::Subway, Color{0x003da5} }, // Blue OSM: 4086917 WD: Q152015 42.36, -71.06 x 42.41, -70.99
    { 60, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x99b3be} }, // 3 OSM: 4089342 WD: Q56302770 46.94, 7.431 x 46.95, 7.441
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0089cf} }, // 6 OSM: 4089819 WD: Q56302772 46.93, 7.419 x 46.95, 7.563
    { 1823, 13566, 8171, LineMetaDataContent::Tramway, Color{0xa12944} }, // 97 OSM: 4092822 WD: Q1865502 50.8, 4.313 x 50.84, 4.357
    { 661, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x6e0b14} }, // 35 OSM: 4096026 WD: Q106766695 52.17, 20.91 x 52.28, 21.02
    { 231, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xae4a34} }, // 17 OSM: 4096027 WD: Q106766682 52.18, 20.94 x 52.34, 21.01
    { 332, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x800000} }, // 33 OSM: 4096028 WD: Q106769899 52.21, 20.92 x 52.29, 21.01
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 6 OSM: 4096029 WD: Q106767360 52.24, 20.93 x 52.3, 21.12
    { 149, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xdb1702} }, // 15 OSM: 4096032 WD: Q106766968 52.22, 20.98 x 52.28, 21.02
    { 67, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf7230c} }, // 10 OSM: 4096042 WD: Q106766948 52.17, 20.9 x 52.24, 21.02
    { 1091, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x960018} }, // 28 OSM: 4096046 WD: Q106767043 52.24, 20.9 x 52.28, 21.05
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf08080} }, // 1 OSM: 4096062 WD: Q106767154 52.21, 20.98 x 52.27, 21.04
    { 227, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xa52a2a} }, // 27 OSM: 4096066 WD: Q106767943 52.22, 20.93 x 52.27, 20.98
    { 110, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xbb0b0b} }, // 22 OSM: 4096081 WD: Q106767519 52.22, 20.94 x 52.27, 21.09
    { 9, 13588, 13598, LineMetaDataContent::Tramway, Color{0x4a2a15} }, // 4 OSM: 4107687 WD: Q3238942 43.59, 3.872 x 43.62, 3.897
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xee1d23} }, // 11 OSM: 4108299 WD: Q3239102 47.47, 7.573 x 47.58, 7.612
    { 1429, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // 100 OSM: 4117854 WD: Q3537097 39.1, -84.52 x 39.12, -84.51
    { 1231, 13627, 4422, LineMetaDataContent::Subway, Color{0x005ca5} }, // M3 OSM: 4121437 WD: Q692916 47.46, 19.05 x 47.56, 19.15
    { 8, 13649, 4422, LineMetaDataContent::Subway, Color{0x4ca22f} }, // M4 OSM: 4121438 WD: Q832651 47.46, 19.02 x 47.5, 19.08
    { 433, 13671, 4422, LineMetaDataContent::Subway, Color{0xe41f18} }, // M2 OSM: 4121439 WD: Q1071156 47.49, 19.02 x 47.51, 19.14
    { 42, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xee1d23} }, // 7 OSM: 4152763 WD: Q56302771 46.94, 7.38 x 46.95, 7.472
    { 336, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 45 OSM: 4161955 WD: Q122585367 55.73, 37.66 x 55.76, 37.7
    { 56, 13693, NoLogo, LineMetaDataContent::Tramway, Color{0xf56202} }, // 1 OSM: 4168138 WD: Q21041074 48.14, 17.11 x 48.16, 17.12
    { 403, 13718, 7769, LineMetaDataContent::Subway, Color{0x008751} }, // C OSM: 4173958 WD: Q2261550 41.86, 12.51 x 41.89, 12.71
    { 251, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 43 OSM: 4179202 WD: Q122585366 55.71, 37.66 x 55.79, 37.72
    { 56, 13759, NoLogo, LineMetaDataContent::Tramway, Color{0xf18700} }, // 1 OSM: 4222397 WD: Q108215311 50.96, 10.99 x 51.01, 11.04
    { 16, 13785, NoLogo, LineMetaDataContent::Tramway, Color{0xe3000b} }, // 2 OSM: 4222399 WD: Q108215316 50.95, 10.98 x 50.98, 11.07
    { 60, 13811, NoLogo, LineMetaDataContent::Tramway, Color{0x67095f} }, // 3 OSM: 4222400 WD: Q108215641 50.94, 10.99 x 51.01, 11.09
    { 9, 13837, NoLogo, LineMetaDataContent::Tramway, Color{0x007ac3} }, // 4 OSM: 4222401 WD: Q108215690 50.97, 10.96 x 51, 11.07
    { 6, 13863, NoLogo, LineMetaDataContent::Tramway, Color{0x00883c} }, // 5 OSM: 4222402 WD: Q108215699 50.97, 11.02 x 51.02, 11.04
    { 27, 13889, NoLogo, LineMetaDataContent::Tramway, Color{0x78ac28} }, // 6 OSM: 4222403 WD: Q108215015 50.96, 11 x 51.01, 11.04
    { 22, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xdc143c} }, // 18 OSM: 4230615 WD: Q106767037 52.18, 20.99 x 52.29, 21.02
    { 310, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xb22222} }, // 26 OSM: 4230616 WD: Q106768213 52.22, 20.91 x 52.29, 21.09
    { 247, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xbc2001} }, // 24 OSM: 4230814 WD: Q106766559 52.22, 20.91 x 52.26, 21.12
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xed0000} }, // 13 OSM: 4230815 WD: Q106767561 52.22, 20.93 x 52.26, 21.06
    { 243, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xbf3030} }, // 20 OSM: 4230816 WD: Q106767203 52.24, 20.9 x 52.29, 21.03
    { 1826, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfecc00} }, // 103 OSM: 4232441 WD: Q121299588 51.45, 6.914 x 51.49, 7.075
    { 433, 13915, 3891, LineMetaDataContent::Subway, Color{0xff0000} }, // M2 OSM: 4232535 WD: Q3832673 52.23, 20.91 x 52.29, 21.06
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff7f00} }, // 1 OSM: 4234654 WD: Q121287729 51.8, 12.24 x 51.84, 12.24
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x18683c} }, // 6 OSM: 4236150 WD: Q121219170 52.4, 12.52 x 52.44, 12.57
    { 178, 13927, NoLogo, LineMetaDataContent::Subway, Color{0xffb619} }, // O OSM: 4250359 WD: Q6141590 24.99, 121.4 x 25.1, 121.5
    { 676, 13951, NoLogo, LineMetaDataContent::Subway, Color{0xcedc00} }, // G OSM: 4250382 WD: Q8044250 24.96, 121.5 x 25.05, 121.6
    { 1830, 13990, NoLogo, LineMetaDataContent::Subway, Color{0xa74c00} }, // BR OSM: 4264893 WD: Q707644 25, 121.5 x 25.09, 121.6
    { 1833, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00519e} }, // 104 OSM: 4272612 WD: Q121299589 51.43, 6.877 x 51.46, 6.934
    { 1837, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xb7d828} }, // S41 OSM: 4272651 WD: Q121237670 49.14, 9.106 x 49.35, 9.229
    { 1841, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x8b231d} }, // SFM 6 OSM: 4277114 WD: Q15077697 44.88, 7.654 x 45.12, 8.209
    { 1847, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // C11 OSM: 4287063 WD: Q104192648 50.71, 12.77 x 50.84, 12.93
    { 44, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf49694} }, // S5 OSM: 4292646 48.89, 8.243 x 49.06, 8.705
    { 16, 14015, NoLogo, LineMetaDataContent::Subway, Color{0x028f34} }, // 2 OSM: 4292976 WD: Q2333639 -22.95, -43.37 x -22.81, -43.17
    { 281, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffcc11} }, // T1 OSM: 4307991 WD: Q124256351 51.02, 3.692 x 51.05, 3.75
    { 1363, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xbb0022} }, // T4 OSM: 4307994 WD: Q124261809 51.02, 3.711 x 51.04, 3.727
    { 1851, 14034, NoLogo, LineMetaDataContent::LongDistanceTrain, Color{0x009bdf} }, // IC 8 OSM: 4421943 WD: Q115932389 46.29, 7.437 x 47.59, 9.38
    { 1856, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x00a6eb} }, // S19 OSM: 4434302 WD: Q30597732 50.76, 6.482 x 50.95, 7.66
    { 347, 14048, 226, LineMetaDataContent::RapidTransit, Color{0xf78a18} }, // S51 OSM: 4435864 WD: Q63433457 52.1, 9.374 x 52.4, 9.773
    { 1860, 14065, 226, LineMetaDataContent::RapidTransit, Color{0x118349} }, // S21 OSM: 4435868 WD: Q63433451 52.28, 9.466 x 52.38, 9.773
    { 371, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xcc0000} }, // Red OSM: 4439533 WD: Q7304502 33.64, -84.45 x 33.95, -84.34
    { 1864, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xf67705} }, // Gold OSM: 4439534 WD: Q5578774 33.64, -84.45 x 33.9, -84.28
    { 639, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x009544} }, // Green OSM: 4439535 WD: Q5602819 33.75, -84.43 x 33.78, -84.28
    { 359, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0274ba} }, // Blue OSM: 4439536 WD: Q4929368 33.75, -84.47 x 33.78, -84.23
    { 67, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x114283} }, // 10 OSM: 4443860 54.27, 48.29 x 54.32, 48.39
    { 306, NoLogo, 14082, LineMetaDataContent::RapidTransit, Color{0x903f98} }, // S4 OSM: 4452991 WD: Q106368752 47.62, 12.87 x 47.84, 13
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe2e200} }, // 2 OSM: 4459896 WD: Q1488530 47.52, 21.61 x 47.56, 21.63
    { 1869, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xb7cd00} }, // 105 OSM: 4460024 WD: Q121299590 51.43, 6.9 x 51.48, 7.049
    { 231, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x714684} }, // 17 OSM: 4464579 WD: Q122382731 49.77, 18.16 x 49.83, 18.26
    { 47, 14102, 226, LineMetaDataContent::RapidTransit, Color{0x8ec7e8} }, // S8 OSM: 4470844 WD: Q63433462 52.32, 9.687 x 52.46, 9.792
    { 1873, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x80276c} }, // CR-Providence OSM: 4473913 WD: Q7252371 41.58, -71.49 x 42.35, -71.06
    { 1887, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x80276c} }, // CR-Franklin OSM: 4476404 WD: Q5491659 42.08, -71.44 x 42.35, -71.05
    { 149, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x714684} }, // 15 OSM: 4479092 WD: Q122382730 49.77, 18.22 x 49.8, 18.26
    { 1899, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x80276c} }, // CR-Kingston OSM: 4479349 WD: Q104818472 41.98, -71.06 x 42.35, -70.72
    { 16, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xc00000} }, // 2 OSM: 4479817 WD: Q125559509 22.92, -82.42 x 23.13, -82.34
    { 145, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x5a1e82} }, // 14 OSM: 4489019 WD: Q3238565 46.17, 6.06 x 46.24, 6.144
    { 22, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xb82f89} }, // 18 OSM: 4489020 WD: Q3238636 46.17, 6.055 x 46.23, 6.144
    { 149, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x84471c} }, // 15 OSM: 4489138 WD: Q3238583 46.17, 6.101 x 46.22, 6.149
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xea556f} }, // 5 OSM: 4492488 WD: Q122382721 49.82, 18.05 x 49.85, 18.16
    { 56, 14118, NoLogo, LineMetaDataContent::Subway, Color{0x008000} }, // 1 OSM: 4494027 WD: Q10914047 24.11, 120.6 x 24.19, 120.7
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 4 OSM: 4494871 WD: Q2105648 52.34, 4.889 x 52.38, 4.905
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xab10d2} }, // 12 OSM: 4495366 WD: Q14500288 52.35, 4.879 x 52.38, 4.919
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffbf00} }, // 1 OSM: 4497227 WD: Q2663350 52.35, 4.775 x 52.36, 4.934
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffbf00} }, // 2 OSM: 4497722 WD: Q2033321 52.34, 4.804 x 52.38, 4.899
    { 60, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xab10d2} }, // 3 OSM: 4498754 WD: Q2051638 52.35, 4.87 x 52.38, 4.952
    { 1911, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffcd28} }, // Z70 OSM: 4498934 WD: Q109333261 47.51, 18.86 x 47.83, 19.16
    { 1915, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xb0c4de} }, // PST OSM: 4499555 WD: Q7119275 33.43, -112 x 33.45, -112
    { 1919, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00aff0} }, // S70 OSM: 4500998 WD: Q109333249 47.51, 18.86 x 47.83, 19.16
    { 301, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00aff0} }, // S71 OSM: 4500999 WD: Q109333250 47.51, 19.06 x 47.78, 19.3
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffbf00} }, // 5 OSM: 4501532 WD: Q2343376 52.3, 4.867 x 52.39, 4.886
    { 42, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff7f00} }, // 7 OSM: 4502267 WD: Q4405692 52.36, 4.818 x 52.38, 4.94
    { 153, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 19 OSM: 4507967 WD: Q2402279 52.34, 4.838 x 52.39, 4.971
    { 234, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00aff0} }, // S50 OSM: 4508158 WD: Q104161828 47.17, 19.06 x 47.52, 20.18
    { 1923, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00985f} }, // Babylon OSM: 4509487 WD: Q4838506 40.66, -73.99 x 40.75, -73.33
    { 1931, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x999e9e} }, // VLT Curado-Cajueiro Seco OSM: 4510189 WD: Q18473919 -8.177, -34.99 x -8.075, -34.93
    { 1956, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // VLT Cabo - Cajueiro Seco OSM: 4510254 WD: Q18473915 -8.287, -35.04 x -8.168, -34.93
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xab10d2} }, // 13 OSM: 4512711 WD: Q2157983 52.37, 4.803 x 52.38, 4.899
    { 145, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00ff00} }, // 14 OSM: 4513498 WD: Q2108285 52.36, 4.892 x 52.38, 4.94
    { 247, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf49ac1} }, // 24 OSM: 4513900 WD: Q2651682 52.34, 4.857 x 52.36, 4.9
    { 231, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x007fff} }, // 17 OSM: 4514442 WD: Q2400889 52.36, 4.786 x 52.38, 4.899
    { 310, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xd59758} }, // 26 OSM: 4514564 WD: Q2503173 52.35, 4.898 x 52.38, 5.005
    { 235, 14153, 14192, LineMetaDataContent::Subway, Color{0x29ab4d} }, // 50 OSM: 4515358 WD: Q2466111 52.29, 4.834 x 52.4, 4.99
    { 348, 14217, 14192, LineMetaDataContent::Subway, Color{0xf69931} }, // 51 OSM: 4515359 WD: Q61964024 52.33, 4.834 x 52.4, 4.924
    { 1982, 14256, 14192, LineMetaDataContent::Subway, Color{0xfcfb05} }, // 54 OSM: 4515360 WD: Q2183200 52.29, 4.9 x 52.38, 4.99
    { 1986, 14295, 14192, LineMetaDataContent::Subway, Color{0xff0000} }, // 53 OSM: 4515361 WD: Q2163442 52.31, 4.9 x 52.38, 4.985
    { 1860, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00aff0} }, // S21 OSM: 4517111 WD: Q101148856 46.89, 19.06 x 47.52, 19.71
    { 1989, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00aff0} }, // S210 OSM: 4522098 WD: Q109333255 46.89, 19.48 x 47.1, 19.71
    { 1369, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009adf} }, // 901 OSM: 4525409 WD: Q121292575 51.43, 6.732 x 51.51, 6.887
    { 1994, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffcd28} }, // Z50 OSM: 4537671 WD: Q104170252 47.17, 19.06 x 47.52, 20.18
    { 1046, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00aff0} }, // S10 OSM: 4543849 WD: Q103726127 47.45, 17.64 x 47.75, 19.03
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xbd1522} }, // 2 OSM: 4543902 WD: Q122204280 50.78, 19.12 x 50.84, 19.15
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x1c70b8} }, // 1 OSM: 4543906 WD: Q122204279 50.78, 19.12 x 50.84, 19.17
    { 60, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x38a935} }, // 3 OSM: 4543907 WD: Q122204281 50.77, 19.12 x 50.84, 19.16
    { 1998, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009adf} }, // 903 OSM: 4544338 WD: Q121292819 51.37, 6.729 x 51.57, 6.795
    { 2002, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffcd28} }, // Z30 OSM: 4546118 WD: Q109333259 47.17, 18.42 x 47.5, 19.04
    { 348, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 51 OSM: 4554929 59.98, 30.4 x 60.05, 30.44
    { 2006, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffa500} }, // NS OSM: 4566683 WD: Q16959474 45.49, -122.7 x 45.53, -122.7
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe9383f} }, // 11 OSM: 4591254 WD: Q106770207 52.21, 20.91 x 52.26, 21.05
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf8c300} }, // 5 OSM: 4616626 WD: Q122216453 53.12, 17.99 x 53.18, 18.17
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff1493} }, // 5 OSM: 4621317 WD: Q55676167 53.01, 18.55 x 53.03, 18.7
    { 2009, 14334, 14361, LineMetaDataContent::Subway, Color{0x1e59ae} }, // m2 OSM: 4621397 WD: Q3239144 46.51, 6.626 x 46.54, 6.662
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x94c11a} }, // 2 OSM: 4622863 WD: Q121253958 52.23, 10.52 x 52.29, 10.54
    { 42, 14386, 4324, LineMetaDataContent::Subway, Color{0xffc66e} }, // 7 OSM: 4624900 WD: Q6553149 39.85, 116.3 x 39.89, 116.7
    { 145, 14406, 4324, LineMetaDataContent::Subway, Color{0xd4a7a1} }, // 14 OSM: 4624915 WD: Q6553070 39.86, 116.2 x 40.03, 116.5
    { 27, 14427, 4324, LineMetaDataContent::Subway, Color{0xbb8900} }, // 6 OSM: 4625142 WD: Q6553138 39.9, 116.2 x 39.93, 116.7
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xec008c} }, // 1 OSM: 4628650 WD: Q121410306 47.15, 27.56 x 47.19, 27.63
    { 60, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00a650} }, // 3 OSM: 4629075 WD: Q121410307 47.15, 27.57 x 47.17, 27.66
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf9c0c1} }, // 6 OSM: 4631231 WD: Q121410309 47.16, 27.54 x 47.17, 27.59
    { 42, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x2e3092} }, // 7 OSM: 4631274 WD: Q121410310 47.14, 27.54 x 47.17, 27.64
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xd2e288} }, // 8 OSM: 4631290 WD: Q121410311 47.14, 27.56 x 47.19, 27.64
    { 113, 14447, 1396, LineMetaDataContent::Subway, Color{0xb8282e} }, // U1 OSM: 4656730 WD: Q198432 50.1, 8.634 x 50.17, 8.688
    { 119, 14464, 1396, LineMetaDataContent::Subway, Color{0x4a5eaa} }, // U3 OSM: 4656731 WD: Q19862991 50.1, 8.537 x 50.22, 8.688
    { 122, 14481, 1396, LineMetaDataContent::Subway, Color{0xf172ac} }, // U4 OSM: 4656732 WD: Q19862998 50.11, 8.652 x 50.14, 8.754
    { 125, 14498, 1396, LineMetaDataContent::Subway, Color{0x007942} }, // U5 OSM: 4656733 WD: Q3040872 50.11, 8.663 x 50.16, 8.692
    { 131, 14515, 1396, LineMetaDataContent::Subway, Color{0xe4a024} }, // U7 OSM: 4656734 WD: Q3040904 50.11, 8.608 x 50.14, 8.754
    { 134, 14532, 1396, LineMetaDataContent::Subway, Color{0xc77db5} }, // U8 OSM: 4656735 WD: Q3063407 50.1, 8.621 x 50.18, 8.688
    { 137, 14549, 1396, LineMetaDataContent::Subway, Color{0xeed700} }, // U9 OSM: 4656736 WD: Q19862984 50.14, 8.621 x 50.2, 8.674
    { 1363, 14572, NoLogo, LineMetaDataContent::Tramway, Color{0x008176} }, // T4 OSM: 4665787 WD: Q49368235 41.39, 2.187 x 41.42, 2.231
    { 1603, 14579, NoLogo, LineMetaDataContent::Tramway, Color{0x008176} }, // T6 OSM: 4665788 WD: Q49375135 41.4, 2.187 x 41.42, 2.231
    { 1366, 14592, NoLogo, LineMetaDataContent::Tramway, Color{0x008176} }, // T5 OSM: 4665789 WD: Q49394264 41.4, 2.187 x 41.44, 2.233
    { 1295, 7611, NoLogo, LineMetaDataContent::Tramway, Color{0x008176} }, // T3 OSM: 4667001 WD: Q49770929 41.37, 2.053 x 41.39, 2.143
    { 281, 8931, NoLogo, LineMetaDataContent::Tramway, Color{0x008176} }, // T1 OSM: 4667002 WD: Q49770336 41.36, 2.058 x 41.39, 2.143
    { 700, 8888, NoLogo, LineMetaDataContent::Tramway, Color{0x008176} }, // T2 OSM: 4667003 WD: Q49770664 41.36, 2.058 x 41.39, 2.143
    { 511, 14599, 14616, LineMetaDataContent::Subway, Color{0x992f9c} }, // L2 OSM: 4671269 WD: Q1348921 41.38, 2.163 x 41.45, 2.244
    { 503, 14641, 14616, LineMetaDataContent::Subway, Color{0xfab70a} }, // L4 OSM: 4671321 WD: Q961384 41.38, 2.163 x 41.45, 2.218
    { 1323, 14658, 14616, LineMetaDataContent::Subway, Color{0x317bc8} }, // L5 OSM: 4673514 WD: Q1348939 41.36, 2.071 x 41.43, 2.187
    { 2012, 14675, 14616, LineMetaDataContent::Subway, Color{0x00adef} }, // L10 Nord OSM: 4673515 WD: Q1785338 41.42, 2.186 x 41.44, 2.234
    { 515, 14693, 14616, LineMetaDataContent::Subway, Color{0x39af57} }, // L3 OSM: 4673516 WD: Q385168 41.37, 2.11 x 41.45, 2.188
    { 1335, 14710, 14616, LineMetaDataContent::Subway, Color{0xe27aaf} }, // L8 OSM: 4673517 WD: Q763319 41.35, 2.035 x 41.37, 2.148
    { 1331, 14727, 14616, LineMetaDataContent::Subway, Color{0xac5414} }, // L7 OSM: 4673518 WD: Q678390 41.39, 2.137 x 41.41, 2.169
    { 507, 14744, 14616, LineMetaDataContent::Subway, Color{0xe33638} }, // L1 OSM: 4673519 WD: Q1348946 41.34, 2.099 x 41.45, 2.218
    { 485, 14761, 14616, LineMetaDataContent::Subway, Color{0x9ed74c} }, // L11 OSM: 4673520 WD: Q1419762 41.45, 2.173 x 41.46, 2.186
    { 1327, 14779, 14616, LineMetaDataContent::Subway, Color{0x7280c0} }, // L6 OSM: 4673521 WD: Q1577019 41.39, 2.125 x 41.4, 2.169
    { 2021, 14796, 14616, LineMetaDataContent::Subway, Color{0xf6842a} }, // L9 Nord OSM: 4673522 WD: Q1577033 41.42, 2.186 x 41.46, 2.22
    { 1242, 14813, NoLogo, LineMetaDataContent::LocalTrain, Color{0xfdda24} }, // 86966 OSM: 4684542 WD: Q205585 42.42, 2.866 x 43.94, 4.805
    { 2029, 14813, NoLogo, LineMetaDataContent::LocalTrain, Color{0xfdda24} }, // 86990 OSM: 4684543 WD: Q205585 42.42, 2.866 x 43.19, 3.168
    { 153, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x60d1c5} }, // 19 OSM: 4748539 52.37, 16.9 x 52.46, 16.94
    { 56, 14826, NoLogo, LineMetaDataContent::Tramway, Color{0xca0047} }, // 1 OSM: 4748602 WD: Q117280796 52.38, 16.85 x 52.4, 17
    { 16, 14864, NoLogo, LineMetaDataContent::Tramway, Color{0x79bee2} }, // 2 OSM: 4750038 WD: Q108006450 52.37, 16.88 x 52.42, 16.94
    { 2035, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x800080} }, // Tren Urbano OSM: 4751620 WD: Q1577126 18.39, -66.15 x 18.44, -66.05
    { 60, 14902, NoLogo, LineMetaDataContent::Tramway, Color{0x6d053d} }, // 3 OSM: 4756145 WD: Q108000703 52.37, 16.91 x 52.46, 16.98
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x76ce47} }, // 5 OSM: 4763766 WD: Q111590889 52.38, 16.88 x 52.41, 16.96
    { 518, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00943c} }, // 109 OSM: 4773640 WD: Q121299593 51.45, 6.955 x 51.46, 7.075
    { 2049, 14940, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe67310} }, // A2 OSM: 4785912 WD: Q19582807 53.71, 9.889 x 54.08, 10.02
    { 2052, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x004d9f} }, // Tide OSM: 4788761 WD: Q112724328 36.84, -76.3 x 36.86, -76.19
    { 2057, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xec1c24} }, // 703 OSM: 4789075 WD: Q7304509 40.54, -112 x 40.77, -111.8
    { 2061, NoLogo, 5132, LineMetaDataContent::RapidTransit, Color{0xbdbadc} }, // Penn OSM: 4799477 WD: Q7163197 38.9, -77.01 x 39.56, -76.07
    { 19, 14955, NoLogo, LineMetaDataContent::Tramway, Color{0xff88aa} }, // 8 OSM: 4828592 WD: Q1962342 51.21, 4.42 x 51.22, 4.492
    { 2066, 14977, 3582, LineMetaDataContent::RapidTransit, Color{0xffcc00} }, // C6 OSM: 4840309 WD: Q77072004 43.34, -5.856 x 43.39, -5.361
    { 60, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008080} }, // 3 OSM: 5143295 WD: Q122395001 49.2, 16.52 x 49.23, 16.64
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffa500} }, // 4 OSM: 5151976 WD: Q122395002 49.19, 16.58 x 49.23, 16.65
    { 281, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00a5c1} }, // T1 OSM: 5157502 WD: Q16011470 47.22, 5.951 x 47.26, 6.061
    { 2, 15004, NoLogo, LineMetaDataContent::Tramway, Color{0x0d7b49} }, // 0 OSM: 5175545 WD: Q108006493 52.39, 16.89 x 52.41, 16.94
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe4002c} }, // 1 OSM: 5185991 WD: Q91659218 51, 13.67 x 51.06, 13.82
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xeb5b2d} }, // 2 OSM: 5186008 WD: Q91659698 51.01, 13.65 x 51.06, 13.85
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc9061a} }, // 4 OSM: 5186035 WD: Q91660551 51.02, 13.56 x 51.16, 13.84
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffdd00} }, // 6 OSM: 5186067 WD: Q93766509 51, 13.68 x 51.06, 13.84
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x229133} }, // 8 OSM: 5186073 WD: Q64022460 51.03, 13.72 x 51.12, 13.77
    { 138, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x93c355} }, // 9 OSM: 5186435 WD: Q93767104 51, 13.69 x 51.08, 13.8
    { 67, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf9b000} }, // 10 OSM: 5186677 WD: Q93767517 51.04, 13.71 x 51.07, 13.81
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc2ddaf} }, // 11 OSM: 5186681 WD: Q91034464 51.02, 13.73 x 51.07, 13.86
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfdc300} }, // 13 OSM: 5186751 WD: Q93767971 51, 13.69 x 51.08, 13.8
    { 2069, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00aff0} }, // S150 OSM: 5189451 WD: Q101110277 47.18, 18.01 x 47.75, 18.42
    { 2074, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xaacd46} }, // G30 OSM: 5189583 WD: Q104161605 47.17, 18.43 x 47.5, 19.04
    { 2078, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00aff0} }, // S820 OSM: 5189587 WD: Q109333257 47.17, 19.67 x 47.66, 20.18
    { 1695, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00aff0} }, // S42 OSM: 5189590 WD: Q112963134 46.96, 18.76 x 47.5, 19.04
    { 2083, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xaacd46} }, // G10 OSM: 5189591 WD: Q103834888 47.45, 17.14 x 47.91, 19.12
    { 2088, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00aff0} }, // S30 OSM: 5189595 WD: Q101095853 46.75, 17.56 x 47.5, 19.04
    { 2092, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00aff0} }, // S220 OSM: 5189596 WD: Q112963797 46.85, 19.7 x 47.18, 20.18
    { 2097, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xaacd46} }, // G71 OSM: 5189597 WD: Q109333268 47.51, 19.06 x 47.78, 19.3
    { 2101, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xaacd46} }, // G70 OSM: 5189600 WD: Q109333266 47.51, 18.86 x 47.83, 19.16
    { 2105, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xaacd46} }, // G43 OSM: 5189602 WD: Q109333264 47.17, 18.42 x 47.48, 19.35
    { 1285, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00aff0} }, // S20 OSM: 5189604 WD: Q103835740 46.23, 19.06 x 47.52, 20.14
    { 265, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00aff0} }, // S40 OSM: 5189605 WD: Q112963108 46.37, 18.15 x 47.5, 19.04
    { 1221, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00aff0} }, // S36 OSM: 5189606 WD: Q109333242 47.25, 18.69 x 47.48, 19.35
    { 2109, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00aff0} }, // S35 OSM: 5189607 WD: Q109333241 46.44, 16.99 x 47.5, 19.04
    { 2113, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00aff0} }, // S34 OSM: 5189609 WD: Q104433012 46.69, 17.24 x 47.5, 19.04
    { 56, NoLogo, 860, LineMetaDataContent::Tramway, Color{0xd52330} }, // 1 OSM: 5209167 WD: Q63442516 50.93, 6.816 x 50.96, 7.162
    { 2117, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x1f9cd8} }, // NC (NB) OSM: 5214593 WD: Q125156771 53.34, -6.429 x 54, -6.112
    { 1042, 15042, 9368, LineMetaDataContent::RapidTransit, Color{0xf26021} }, // S32 OSM: 5219521 WD: Q87069535 51.08, 4.283 x 51.54, 4.467
    { 42, NoLogo, 860, LineMetaDataContent::Tramway, Color{0xe6855c} }, // 7 OSM: 5231292 WD: Q63442539 50.87, 6.797 x 50.94, 7.06
    { 41, 15068, 10419, LineMetaDataContent::RapidTransit, Color{0x159dd9} }, // S7 OSM: 5248498 WD: Q17101554 48.1, 16.38 x 48.57, 17.01
    { 173, 15080, 10419, LineMetaDataContent::RapidTransit, Color{0x159dd9} }, // S60 OSM: 5248503 WD: Q96483899 47.81, 16.23 x 48.19, 16.78
    { 234, 15093, 10419, LineMetaDataContent::RapidTransit, Color{0x159dd9} }, // S50 OSM: 5248504 WD: Q96483895 48.17, 15.98 x 48.21, 16.34
    { 2125, 15106, 10419, LineMetaDataContent::RapidTransit, Color{0x159dd9} }, // S80 OSM: 5248538 WD: Q96483911 48.17, 16.26 x 48.23, 16.51
    { 335, 15119, 10419, LineMetaDataContent::RapidTransit, Color{0xbdd542} }, // S45 OSM: 5248540 WD: Q17101545 48.19, 16.26 x 48.26, 16.39
    { 265, 15132, 10419, LineMetaDataContent::RapidTransit, Color{0x159dd9} }, // S40 OSM: 5248548 WD: Q96483953 48.21, 15.62 x 48.35, 16.37
    { 56, NoLogo, 15145, LineMetaDataContent::Tramway, Color{0x0000ff} }, // 1 OSM: 5252357 WD: Q112081451 39.22, 9.125 x 39.27, 9.143
    { 16, NoLogo, 15145, LineMetaDataContent::Tramway, Color{0x0080ff} }, // 2 OSM: 5252358 WD: Q112081586 39.26, 9.126 x 39.29, 9.177
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xeb4690} }, // 1 OSM: 5293755 33.98, -6.865 x 34.05, -6.794
    { 1295, 15168, 8895, LineMetaDataContent::Tramway, Color{0x96be0d} }, // T3 OSM: 5296539 WD: Q3238910 43.29, 5.367 x 43.32, 5.384
    { 2129, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00519e} }, // 101 OSM: 5310407 WD: Q121299586 51.44, 6.95 x 51.48, 7.019
    { 2133, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x996c1b} }, // 106 OSM: 5310407 WD: Q121299586 51.44, 6.95 x 51.48, 7.019
    { 2137, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xeca900} }, // 108 OSM: 5310861 WD: Q121299592 51.41, 6.993 x 51.48, 7.019
    { 140, NoLogo, 860, LineMetaDataContent::Subway, Color{0x342a82} }, // U11 OSM: 5311905 WD: Q110928761 51.42, 6.992 x 51.54, 7.026
    { 2141, NoLogo, 860, LineMetaDataContent::Subway, Color{0x68b6e3} }, // U17 OSM: 5312041 WD: Q121298190 51.43, 6.973 x 51.5, 7.013
    { 2145, NoLogo, 860, LineMetaDataContent::Subway, Color{0x0080c8} }, // U18 OSM: 5312153 WD: Q88799606 51.43, 6.886 x 51.46, 7.013
    { 2150, 15190, NoLogo, LineMetaDataContent::Subway, Color{0x02ac39} }, // TR OSM: 5326658 WD: Q843148 35.7, 140 x 35.73, 140.1
    { 138, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8a2be2} }, // 9 OSM: 5329880 WD: Q122395008 49.19, 16.61 x 49.23, 16.65
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x221815} }, // 6 OSM: 5335066 WD: Q957721 33.84, 132.8 x 33.85, 132.8
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x036eb8} }, // 5 OSM: 5335067 33.84, 132.8 x 33.85, 132.8
    { 60, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe60012} }, // 3 OSM: 5335068 33.84, 132.8 x 33.85, 132.8
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x6a7045} }, // 8 OSM: 5351647 WD: Q123363018 56.83, 60.56 x 56.9, 60.69
    { 2153, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x37bbed} }, // TDV OSM: 5371521 WD: Q23951292 -38.96, -68.23 x -38.96, -68.06
    { 2157, NoLogo, 4285, LineMetaDataContent::RapidTransit, Color{0x221e44} }, // S44 OSM: 5378417 WD: Q124214433 50.23, 14.24 x 50.28, 14.31
    { 306, NoLogo, 4285, LineMetaDataContent::RapidTransit, Color{0xf27e00} }, // S4 OSM: 5378441 WD: Q107983587 50.09, 14.3 x 50.45, 14.44
    { 67, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xb50094} }, // 10 OSM: 5380834 WD: Q122216458 53.12, 18 x 53.18, 18.17
    { 2161, 15219, 3582, LineMetaDataContent::RapidTransit, Color{0x8b039b} }, // C-3 OSM: 5382815 WD: Q8879464 40.03, -3.71 x 40.48, -3.608
    { 348, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x4a4a49} }, // 51 OSM: 5387664 49.96, 8.178 x 50.02, 8.26
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x1ca9e1} }, // 5 OSM: 5389816 WD: Q124656080 49.85, 8.65 x 49.9, 8.683
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00a54f} }, // 2 OSM: 5390308 WD: Q124656077 49.86, 8.631 x 49.87, 8.682
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x662584} }, // 2 OSM: 5391128 33.99, -6.872 x 34.04, -6.752
    { 42, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xed028c} }, // 7 OSM: 5394295 WD: Q124656082 49.81, 8.644 x 49.87, 8.657
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xdf2a29} }, // 8 OSM: 5394296 WD: Q124656083 49.74, 8.613 x 49.92, 8.658
    { 138, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x7cbe45} }, // 9 OSM: 5394637 WD: Q124656084 49.85, 8.555 x 49.87, 8.67
    { 60, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf6c027} }, // 3 OSM: 5394736 WD: Q124656078 49.85, 8.631 x 49.88, 8.657
    { 63, 15237, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffa500} }, // S1 OSM: 5405974 WD: Q5425454 41.39, 2.007 x 41.58, 2.169
    { 51, 15254, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7e971e} }, // S2 OSM: 5405975 WD: Q5425453 41.39, 2.068 x 41.57, 2.169
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xd51a1f} }, // 8 OSM: 5412689 WD: Q108000373 54.34, 18.58 x 54.42, 18.73
    { 138, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x185696} }, // 9 OSM: 5412706 WD: Q117011206 54.34, 18.58 x 54.39, 18.73
    { 243, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf9b000} }, // 20 OSM: 5421483 51.04, 13.71 x 51.07, 13.74
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00aeef} }, // 6 OSM: 5424499 WD: Q116997752 54.32, 18.56 x 54.42, 18.65
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xa6ce39} }, // 2 OSM: 5424501 WD: Q108000249 54.32, 18.57 x 54.42, 18.65
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf58220} }, // 12 OSM: 5446660 WD: Q117011363 54.33, 18.56 x 54.41, 18.65
    { 56, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x000080} }, // 1 OSM: 5465576 WD: Q10318641 -30.03, -51.23 x -29.69, -51.13
    { 1239, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8b0000} }, // 31 OSM: 5475000 WD: Q106770155 52.18, 20.99 x 52.19, 21.02
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xa2238e} }, // 4 OSM: 5486024 WD: Q116984679 54.35, 18.58 x 54.42, 18.64
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc3272b} }, // 1 OSM: 5490398 WD: Q15934788 41.66, 123.4 x 41.74, 123.5
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x003171} }, // 2 OSM: 5490399 WD: Q28415057 41.63, 123.5 x 41.74, 123.5
    { 60, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x007b43} }, // 3 OSM: 5490400 WD: Q28415058 41.65, 123.4 x 41.72, 123.5
    { 42, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xac8c6a} }, // 7 OSM: 5504875 WD: Q108000365 54.32, 18.6 x 54.4, 18.68
    { 281, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // T1 OSM: 5510640 WD: Q113671848 45.44, 12.25 x 45.51, 12.32
    { 56, 15271, NoLogo, LineMetaDataContent::RapidTransit, Color{0x3dae2b} }, // 1 OSM: 5517061 WD: Q1067251 47.42, -122.3 x 47.7, -122.3
    { 1422, NoLogo, 2529, LineMetaDataContent::RapidTransit, Color{0xffa500} }, // Orange OSM: 5543450 WD: Q6714620 45.43, -122.7 x 45.53, -122.6
    { 271, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0088ab} }, // B OSM: 5575252 WD: Q115210980 45.5, -122.7 x 45.54, -122.7
    { 2155, 15303, 15303, LineMetaDataContent::RapidTransit, Color{0xfebeb5} }, // V OSM: 5576487 WD: Q11152362 25.15, 121.4 x 25.2, 121.5
    { 1380, 15345, NoLogo, LineMetaDataContent::LocalTrain, Color{0xc3d552} }, // RE5 OSM: 5577109 WD: Q64223427 53.45, 8.704 x 53.86, 10.03
    { 341, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc60800} }, // 23 OSM: 5579462 WD: Q106766924 52.24, 20.91 x 52.26, 21.04
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xecb224} }, // 5 OSM: 5587313 WD: Q116997091 54.37, 18.58 x 54.41, 18.68
    { 60, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xed028c} }, // 3 OSM: 5587314 WD: Q108000276 54.34, 18.62 x 54.41, 18.71
    { 403, 15361, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7cbd52} }, // C OSM: 5593997 WD: Q4121246 22.59, 120.3 x 22.66, 120.3
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x392991} }, // 1 OSM: 5594238 WD: Q122781780 45.75, 21.21 x 45.77, 21.26
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xdd2b1c} }, // 2 OSM: 5594256 WD: Q122781781 45.73, 21.2 x 45.77, 21.26
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0c0c0c} }, // 8 OSM: 5594329 WD: Q122781784 45.73, 21.21 x 45.75, 21.27
    { 138, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x82d8df} }, // 9 OSM: 5594335 WD: Q122781785 45.73, 21.2 x 45.75, 21.27
    { 344, 15403, NoLogo, LineMetaDataContent::RapidTransit, Color{0x78be20} }, // A3 OSM: 5596928 WD: Q47477355 37.99, 23.57 x 38.46, 23.87
    { 51, 15438, 226, LineMetaDataContent::RapidTransit, Color{0xa70f47} }, // S2 OSM: 5607597 WD: Q19390036 53.49, 9.932 x 53.56, 10.32
    { 44, 15458, 226, LineMetaDataContent::RapidTransit, Color{0x008abd} }, // S5 OSM: 5607598 WD: Q63451353 53.46, 9.477 x 53.6, 10.03
    { 2167, 15473, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe79500} }, // A1 OSM: 5610369 WD: Q19368804 53.59, 9.898 x 53.77, 9.973
    { 60, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff6347} }, // 3 OSM: 5611529 WD: Q106767972 52.24, 21.03 x 52.27, 21.12
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff5e4d} }, // 4 OSM: 5611530 WD: Q106767540 52.17, 21 x 52.27, 21.04
    { 16, 15488, NoLogo, LineMetaDataContent::Subway, Color{0xe70095} }, // 2 OSM: 5616937 WD: Q3832658 39.43, -0.5963 x 39.62, -0.3815
    { 138, 15519, NoLogo, LineMetaDataContent::Subway, Color{0xb7814f} }, // 9 OSM: 5622181 WD: Q18613779 39.47, -0.5603 x 39.54, -0.3521
    { 42, 15550, NoLogo, LineMetaDataContent::Subway, Color{0xf28c00} }, // 7 OSM: 5626070 WD: Q11690011 39.43, -0.4726 x 39.47, -0.3383
    { 2170, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xed1d24} }, // S1A OSM: 5642742 WD: Q56692645 44.16, 10.98 x 44.52, 11.34
    { 60, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xbe1716} }, // 3 OSM: 5646916 WD: Q121196130 50.69, 12.46 x 50.74, 12.53
    { 2174, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa02225} }, // S1B OSM: 5648214 WD: Q56692647 44.22, 11.18 x 44.51, 11.38
    { 2178, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xbed747} }, // S2A OSM: 5648243 WD: Q56692650 44.48, 11.01 x 44.52, 11.34
    { 2182, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x73a534} }, // S2B OSM: 5648273 WD: Q56692652 44.49, 11.35 x 44.7, 11.81
    { 217, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa50575} }, // S3 OSM: 5648349 WD: Q56692654 44.51, 11.11 x 44.98, 11.34
    { 2186, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0066b3} }, // S4A OSM: 5648362 WD: Q56692656 44.51, 11.32 x 44.84, 11.6
    { 2190, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x2a2a86} }, // S4B OSM: 5648385 WD: Q56692658 44.36, 11.34 x 44.51, 11.72
    { 44, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfdc214} }, // S5 OSM: 5648393 WD: Q56692659 44.51, 10.93 x 44.65, 11.34
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xb141fc} }, // 1 OSM: 5659014 WD: Q123343966 53.73, 20.48 x 53.78, 20.5
    { 60, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xb141fc} }, // 3 OSM: 5659016 WD: Q123343994 53.75, 20.46 x 53.78, 20.5
    { 243, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffa500} }, // 20 OSM: 5664426 WD: Q30716928 52.01, 5.076 x 52.09, 5.184
    { 74, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffa500} }, // 21 OSM: 5664427 WD: Q81422423 52.01, 5.028 x 52.09, 5.184
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf05b72} }, // 11 OSM: 5668462 WD: Q121410312 47.15, 27.54 x 47.17, 27.63
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00adef} }, // 13 OSM: 5668463 WD: Q121410313 47.15, 27.56 x 47.19, 27.63
    { 1429, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 100 OSM: 5671142 WD: Q122466845 46.78, 23.59 x 46.8, 23.65
    { 2129, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 101 OSM: 5673692 WD: Q122466868 46.75, 23.54 x 46.78, 23.59
    { 2194, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 102 OSM: 5673737 WD: Q122466923 46.75, 23.54 x 46.8, 23.65
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x9ad2ae} }, // 8 OSM: 5685450 WD: Q17440814 45.78, 15.97 x 45.86, 16
    { 2198, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // E-W OSM: 5697658 WD: Q53778901 9.01, 38.72 x 9.022, 38.87
    { 2202, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // S-N OSM: 5697659 WD: Q53779001 8.936, 38.73 x 9.039, 38.77
    { 42, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xa3c2d1} }, // 7 OSM: 5706899 WD: Q117193191 45.78, 15.95 x 45.82, 16.04
    { 138, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x9a94c8} }, // 9 OSM: 5707039 WD: Q17440798 45.8, 15.94 x 45.82, 16.02
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfff685} }, // 11 OSM: 5707158 WD: Q116913595 45.81, 15.93 x 45.83, 16.08
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc77db4} }, // 12 OSM: 5707171 WD: Q116918230 45.8, 15.94 x 45.82, 16.04
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xa58e9b} }, // 13 OSM: 5707277 WD: Q116921343 45.8, 15.96 x 45.82, 16.03
    { 145, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf8abad} }, // 14 OSM: 5707492 WD: Q116940834 45.78, 15.95 x 45.84, 16
    { 149, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xee1d23} }, // 15 OSM: 5707544 WD: Q17440801 45.84, 15.97 x 45.86, 15.98
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x66cc00} }, // 2 OSM: 5711071 WD: Q56911095 36.28, 59.55 x 36.33, 59.68
    { 700, 15581, 5647, LineMetaDataContent::Tramway, Color{0x0098d4} }, // T2 OSM: 5720061 WD: Q16655787 43.59, 1.374 x 43.63, 1.446
    { 217, 15609, NoLogo, LineMetaDataContent::RapidTransit, Color{0x36a390} }, // S3 OSM: 5721287 WD: Q110713935 41.35, 2.005 x 41.4, 2.148
    { 306, 15626, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa25e23} }, // S4 OSM: 5721688 WD: Q110714007 41.35, 1.888 x 41.54, 2.148
    { 2206, 15643, NoLogo, LineMetaDataContent::RapidTransit, Color{0xb8b6b7} }, // R6 OSM: 5724702 WD: Q110714580 41.35, 1.63 x 41.58, 2.148
    { 2209, 15660, NoLogo, LineMetaDataContent::RapidTransit, Color{0x707072} }, // R60 OSM: 5724705 WD: Q120985663 41.35, 1.63 x 41.58, 2.148
    { 2213, 15678, NoLogo, LineMetaDataContent::RapidTransit, Color{0x38b0b1} }, // R5 OSM: 5724850 WD: Q110714601 41.35, 1.828 x 41.73, 2.148
    { 2216, 15695, NoLogo, LineMetaDataContent::RapidTransit, Color{0x3592a3} }, // R50 OSM: 5724851 WD: Q120986306 41.35, 1.828 x 41.73, 2.148
    { 231, NoLogo, 860, LineMetaDataContent::Tramway, Color{0x6dcff6} }, // 17 OSM: 5740169 WD: Q63442567 50.86, 6.957 x 50.93, 7.004
    { 26, NoLogo, 860, LineMetaDataContent::Tramway, Color{0x21bfc1} }, // 16 OSM: 5742444 WD: Q20035833 50.68, 6.943 x 50.99, 7.159
    { 9, NoLogo, 860, LineMetaDataContent::Tramway, Color{0xe06e9f} }, // 4 OSM: 5742445 WD: Q63442527 50.93, 6.873 x 51.02, 7.044
    { 231, 15713, NoLogo, LineMetaDataContent::Tramway, Color{0x166187} }, // 17 OSM: 5742856 WD: Q120645681 52.37, 16.88 x 52.41, 16.98
    { 59, 15752, NoLogo, LineMetaDataContent::Tramway, Color{0xb18506} }, // 13 OSM: 5744834 WD: Q108000662 52.37, 16.85 x 52.41, 16.95
    { 149, 15791, NoLogo, LineMetaDataContent::Tramway, Color{0xadb4bb} }, // 15 OSM: 5745673 WD: Q110074597 52.39, 16.85 x 52.46, 16.92
    { 2220, NoLogo, 860, LineMetaDataContent::Subway, Color{0x59c6f2} }, // U71 OSM: 5747258 WD: Q87660333 51.19, 6.763 x 51.26, 6.82
    { 2224, NoLogo, 860, LineMetaDataContent::Subway, Color{0x1d3a8f} }, // U83 OSM: 5748738 WD: Q121295976 51.19, 6.763 x 51.25, 6.855
    { 67, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf2b023} }, // 10 OSM: 5752352 WD: Q108006469 52.37, 16.9 x 52.46, 16.95
    { 2228, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xd2a1f3} }, // T49 OSM: 5755247 WD: Q121818693 50.34, 18.87 x 50.4, 18.92
    { 2232, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xdf1278} }, // T23 OSM: 5755248 WD: Q115219679 50.25, 18.97 x 50.29, 19.07
    { 2236, NoLogo, 860, LineMetaDataContent::Subway, Color{0x4465ad} }, // U73 OSM: 5756097 WD: Q121295967 51.19, 6.775 x 51.24, 6.867
    { 156, NoLogo, 860, LineMetaDataContent::Subway, Color{0x25b8c5} }, // U72 OSM: 5756147 WD: Q121295966 51.16, 6.775 x 51.3, 6.886
    { 2240, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc0087f} }, // 705 OSM: 5757151 WD: Q121297872 51.2, 6.774 x 51.28, 6.787
    { 2244, 15830, NoLogo, LineMetaDataContent::RapidTransit, Color{0x006434} }, // R2Sud OSM: 5758580 WD: Q114215437 41.19, 1.523 x 41.4, 2.194
    { 2250, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff6600} }, // HVL OSM: 5793083 WD: Q5950953 -41.28, 174.8 x -41.13, 175.1
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xa4107f} }, // 4 OSM: 5804724 WD: Q3476269 51.91, 4.453 x 51.96, 4.504
    { 507, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x800080} }, // L1 OSM: 5812905 WD: Q95982832 38.09, 13.37 x 38.11, 13.41
    { 511, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffa500} }, // L2 OSM: 5812931 WD: Q95983858 38.13, 13.29 x 38.13, 13.34
    { 503, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // L4 OSM: 5813038 WD: Q95983909 38.1, 13.33 x 38.13, 13.34
    { 515, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // L3 OSM: 5813039 WD: Q95983869 38.13, 13.3 x 38.14, 13.34
    { 67, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x4b371b} }, // 10 OSM: 5821632 WD: Q117011248 54.35, 18.57 x 54.4, 18.67
    { 2254, NoLogo, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 47B OSM: 5830635 WD: Q22696462 47.44, 18.98 x 47.5, 19.06
    { 2258, 15848, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00a85a} }, // R2 OSM: 5838299 WD: Q1880046 41.28, 1.978 x 41.6, 2.292
    { 2261, 15865, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff131a} }, // R3 OSM: 5844031 WD: Q2113761 41.36, 1.896 x 42.46, 2.297
    { 2264, 15882, 860, LineMetaDataContent::Tramway, Color{0xffbacd} }, // U49 OSM: 5847183 WD: Q121288291 51.48, 7.442 x 51.52, 7.476
    { 2268, 15896, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff8c00} }, // R4 OSM: 5849061 WD: Q2226508 41.19, 1.524 x 41.72, 2.189
    { 2271, 15913, NoLogo, LineMetaDataContent::RapidTransit, Color{0x9b1987} }, // R8 OSM: 5866129 WD: Q3817638 41.45, 1.926 x 41.6, 2.292
    { 2274, 15930, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00bdac} }, // RT1 OSM: 5866193 WD: Q5985874 41.11, 1.098 x 41.16, 1.255
    { 2278, 15948, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe579cb} }, // RT2 OSM: 5867875 WD: Q9025898 41, 0.9109 x 41.27, 1.6
    { 2282, 15966, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0073ce} }, // RG1 OSM: 5867923 WD: Q5985872 41.36, 2.099 x 42.42, 3.161
    { 138, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x974578} }, // 9 OSM: 5879851 WD: Q122216457 53.1, 17.99 x 53.14, 18.11
    { 2286, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0060a9} }, // Expo Line OSM: 5881298 WD: Q736619 49.18, -123.1 x 49.29, -122.8
    { 2296, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xffd520} }, // Millennium Line OSM: 5881419 WD: Q1534900 49.25, -123.1 x 49.29, -122.8
    { 2312, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x009ac8} }, // Canada Line OSM: 5881439 WD: Q1031997 49.17, -123.2 x 49.29, -123.1
    { 2324, 15981, 860, LineMetaDataContent::Tramway, Color{0xfbba00} }, // U42 OSM: 5890483 WD: Q121288273 51.47, 7.433 x 51.56, 7.547
    { 2328, 15995, 860, LineMetaDataContent::Tramway, Color{0xdc2a1b} }, // U45 OSM: 5892934 WD: Q107740406 51.49, 7.455 x 51.54, 7.475
    { 2332, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xb30437} }, // R16 OSM: 5917493 40.6, 0.4494 x 41.4, 2.194
    { 2336, 16009, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffdd00} }, // R12 OSM: 5927786 WD: Q9026146 41.36, 0.6331 x 41.75, 2.189
    { 535, 16039, NoLogo, LineMetaDataContent::Tramway, Color{0x1e9999} }, // E OSM: 5953002 WD: Q5324790 37.78, -122.4 x 37.81, -122.4
    { 418, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf4858d} }, // 614P OSM: 5955260 WD: Q62127915 22.37, 114 x 22.41, 114
    { 2340, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x006684} }, // 615P OSM: 5955261 WD: Q62127917 22.37, 114 x 22.41, 114
    { 687, 16062, 16100, LineMetaDataContent::Subway, Color{0x00aa50} }, // A OSM: 5955845 WD: Q2310450 51.9, 4.314 x 51.96, 4.566
    { 271, 16125, 16100, LineMetaDataContent::Subway, Color{0xffd301} }, // B OSM: 5955846 WD: Q2960661 51.9, 4.105 x 51.99, 4.587
    { 403, 16163, 16100, LineMetaDataContent::Subway, Color{0xef1f1f} }, // C OSM: 5955847 WD: Q2058778 51.83, 4.319 x 51.94, 4.601
    { 275, 16201, 16100, LineMetaDataContent::Subway, Color{0x1bc5e9} }, // D OSM: 5955848 WD: Q2034685 51.83, 4.319 x 51.92, 4.497
    { 535, 16239, 16277, LineMetaDataContent::Subway, Color{0x1a389a} }, // E OSM: 5955849 WD: Q2687418 51.87, 4.325 x 52.08, 4.497
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x90130c} }, // 2 OSM: 5955850 WD: Q1982139 51.88, 4.464 x 51.9, 4.554
    { 42, 16299, NoLogo, LineMetaDataContent::Subway, Color{0x97d700} }, // 7 OSM: 5971692 WD: Q6553152 22.93, 113.2 x 23.2, 113.5
    { 2345, 14796, 14616, LineMetaDataContent::Subway, Color{0xf6842a} }, // L9 Sud OSM: 5972747 WD: Q1577033 41.29, 2.055 x 41.38, 2.134
    { 2352, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // NL1 OSM: 5976635 48.98, 8.362 x 49.05, 8.479
    { 649, 16319, NoLogo, LineMetaDataContent::RapidTransit, Color{0x009ad5} }, // C-1 OSM: 6016052 WD: Q5987195 38.97, -0.4197 x 39.47, -0.1622
    { 2356, 16338, NoLogo, LineMetaDataContent::LocalTrain, Color{0x002369} }, // R11 OSM: 6021945 WD: Q11050690 41.38, 2.139 x 42.43, 3.161
    { 322, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xad390e} }, // 25 OSM: 6023038 WD: Q106766870 52.21, 20.98 x 52.27, 21.05
    { 2360, 16368, NoLogo, LineMetaDataContent::RapidTransit, Color{0xed3896} }, // R13 OSM: 6025765 WD: Q6018166 41.18, 0.6331 x 41.62, 2.194
    { 2364, 16398, NoLogo, LineMetaDataContent::RapidTransit, Color{0x4e53ab} }, // R14 OSM: 6028425 WD: Q2880157 41.11, 0.6331 x 41.62, 2.194
    { 2368, 16428, NoLogo, LineMetaDataContent::RapidTransit, Color{0x9a836c} }, // R15 OSM: 6028724 WD: Q5845244 41.09, 0.4797 x 41.4, 2.194
    { 2372, 16458, NoLogo, LineMetaDataContent::LocalTrain, Color{0x009641} }, // RE6 OSM: 6059535 WD: Q63438537 53.55, 8.31 x 54.91, 9.936
    { 231, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x4d3d00} }, // 17 OSM: 6061801 48.99, 8.347 x 49.05, 8.452
    { 22, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00805a} }, // 18 OSM: 6061803 49, 8.431 x 49.05, 8.479
    { 535, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // E OSM: 6062533 48.95, 8.283 x 49.11, 8.505
    { 275, 16474, 16501, LineMetaDataContent::RapidTransit, Color{0xf9c212} }, // D OSM: 6063097 WD: Q10318679 41.11, -8.611 x 41.18, -8.598
    { 535, 16522, 16501, LineMetaDataContent::RapidTransit, Color{0x937bb8} }, // E OSM: 6063237 WD: Q10318682 41.15, -8.67 x 41.24, -8.582
    { 329, 16549, 16501, LineMetaDataContent::RapidTransit, Color{0xf68b1f} }, // F OSM: 6064751 WD: Q10318684 41.15, -8.655 x 41.19, -8.542
    { 687, 16576, 16501, LineMetaDataContent::RapidTransit, Color{0x3caeef} }, // A OSM: 6064925 WD: Q18473912 41.15, -8.694 x 41.19, -8.582
    { 403, 16603, 16501, LineMetaDataContent::RapidTransit, Color{0x8bc63e} }, // C OSM: 6065645 WD: Q10318673 41.15, -8.656 x 41.27, -8.586
    { 406, 16630, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffcc00} }, // S OSM: 6071918 WD: Q7395342 37.74, -122.5 x 37.79, -122.4
    { 192, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00a076} }, // 704 OSM: 6073252 WD: Q5602824 40.69, -112 x 40.78, -111.9
    { 209, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0055a4} }, // 701 OSM: 6073253 WD: Q4929373 40.53, -111.9 x 40.77, -111.9
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0fa14a} }, // 1 OSM: 6077697 WD: Q107024373 41.14, -8.668 x 41.15, -8.616
    { 153, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0971b7} }, // 19 OSM: 6080693 WD: Q120720216 50.01, 19.93 x 50.09, 19.96
    { 56, 16649, NoLogo, LineMetaDataContent::Subway, Color{0x000080} }, // 1 OSM: 6087653 WD: Q10318642 -19.95, -44.03 x -19.82, -43.91
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xea5297} }, // 4 OSM: 6092716 WD: Q121310605 47.99, 7.829 x 48.04, 7.863
    { 2376, 16666, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // Sul OSM: 6113028 WD: Q10318728 -3.895, -38.63 x -3.72, -38.53
    { 313, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0xf36421} }, // S 1 OSM: 6116272 WD: Q56378877 50.88, 13.46 x 51.16, 14.24
    { 1667, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0xb8282e} }, // S 2 OSM: 6116280 WD: Q56378880 50.96, 13.72 x 51.13, 13.93
    { 1595, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0xed0172} }, // S 3 OSM: 6116305 WD: Q56378881 50.9, 13.34 x 51.04, 13.73
    { 306, 16704, 10419, LineMetaDataContent::RapidTransit, Color{0x159dd9} }, // S4 OSM: 6157906 WD: Q96484000 47.81, 15.98 x 48.4, 16.41
    { 271, 16716, 16501, LineMetaDataContent::RapidTransit, Color{0xe62621} }, // B OSM: 6161229 WD: Q10318669 41.15, -8.758 x 41.38, -8.582
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc01115} }, // 1 OSM: 6182760 WD: Q2085324 51.98, 4.277 x 52.12, 4.359
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x006600} }, // 2 OSM: 6182761 WD: Q3926989 52.05, 4.236 x 52.09, 4.383
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0093de} }, // 6 OSM: 6182762 WD: Q2205103 52.06, 4.264 x 52.1, 4.4
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xcd853f} }, // 11 OSM: 6192619 WD: Q2084217 52.06, 4.27 x 52.11, 4.324
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff66ff} }, // 12 OSM: 6192620 WD: Q2541548 52.06, 4.252 x 52.09, 4.324
    { 138, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xa6c116} }, // 9 OSM: 6192621 WD: Q2293268 52.03, 4.257 x 52.12, 4.324
    { 149, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe63a6b} }, // 15 OSM: 6197181 WD: Q2202159 52.04, 4.31 x 52.08, 4.393
    { 26, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfa7222} }, // 16 OSM: 6197182 WD: Q2746551 52.02, 4.274 x 52.08, 4.327
    { 231, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x006b8b} }, // 17 OSM: 6197183 WD: Q2417431 52.02, 4.272 x 52.1, 4.339
    { 153, NoLogo, 16277, LineMetaDataContent::Tramway, Color{0xc01115} }, // 19 OSM: 6197184 WD: Q2886326 52.01, 4.35 x 52.09, 4.406
    { 2380, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff9c2a} }, // N2 OSM: 6227258 47.47, 19.05 x 47.51, 19.08
    { 2383, NoLogo, 16743, LineMetaDataContent::RapidTransit, Color{0x0275a4} }, // BLUE OSM: 6265609 WD: Q4929367 32.65, -96.81 x 32.92, -96.56
    { 273, NoLogo, 16743, LineMetaDataContent::RapidTransit, Color{0xcc0000} }, // RED OSM: 6265610 WD: Q16984038 32.72, -96.87 x 33.03, -96.7
    { 2388, NoLogo, 16743, LineMetaDataContent::RapidTransit, Color{0x00873f} }, // GREEN OSM: 6265672 WD: Q5602816 32.72, -96.94 x 32.99, -96.68
    { 2394, NoLogo, 16743, LineMetaDataContent::RapidTransit, Color{0xcc6600} }, // ORANGE OSM: 6265702 WD: Q7099665 32.78, -97.04 x 33.03, -96.7
    { 2401, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000066} }, // 620 OSM: 6265792 WD: Q112867830 32.75, -96.82 x 32.78, -96.81
    { 67, 16778, 16799, LineMetaDataContent::Subway, Color{0x0000ff} }, // 10 OSM: 6286483 WD: Q3239219 59.33, 17.88 x 59.4, 18.07
    { 55, 16778, 16799, LineMetaDataContent::Subway, Color{0x0000ff} }, // 11 OSM: 6286484 WD: Q3239220 59.33, 17.91 x 59.42, 18.07
    { 231, 16826, 16799, LineMetaDataContent::Subway, Color{0x008000} }, // 17 OSM: 6286485 WD: Q3239225 59.27, 17.83 x 59.37, 18.13
    { 22, 16826, 16799, LineMetaDataContent::Subway, Color{0x008000} }, // 18 OSM: 6286486 WD: Q3239226 59.23, 17.83 x 59.37, 18.1
    { 153, 16826, 16799, LineMetaDataContent::Subway, Color{0x008000} }, // 19 OSM: 6286487 WD: Q3239227 59.26, 17.83 x 59.37, 18.08
    { 59, 16849, 16799, LineMetaDataContent::Subway, Color{0xff0000} }, // 13 OSM: 6286488 WD: Q3239222 59.24, 17.81 x 59.36, 18.1
    { 145, 16849, 16799, LineMetaDataContent::Subway, Color{0xff0000} }, // 14 OSM: 6286489 WD: Q3239223 59.29, 17.96 x 59.4, 18.08
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe51919} }, // 1 OSM: 6336724 47.1, 37.54 x 47.15, 37.62
    { 2437, NoLogo, 16871, LineMetaDataContent::Subway, Color{0x0a9cda} }, // Victoria OSM: 6354922 WD: Q203030 51.46, -0.1441 x 51.59, -0.01927
    { 2446, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00abe5} }, // GN5 OSM: 6367814 51.52, -0.2222 x 51.8, -0.08662
    { 1098, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 14А OSM: 6389258 WD: Q123353093 53.43, 58.96 x 53.45, 59.08
    { 2450, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x3a75c4} }, // North Clyde OSM: 6399061 55.85, -4.733 x 56, -3.19
    { 2462, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x2e8b57} }, // North Berwick OSM: 6399368 55.93, -3.187 x 56.06, -2.513
    { 2476, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xcc5500} }, // Maryhill OSM: 6403662 55.86, -4.321 x 55.9, -4.239
    { 2485, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x629f3f} }, // Santa Cruz OSM: 6432131 WD: Q10318722 -22.92, -43.69 x -22.85, -43.19
    { 2496, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0691f6} }, // Japeri OSM: 6432248 WD: Q10318695 -22.91, -43.66 x -22.64, -43.19
    { 9, 16887, NoLogo, LineMetaDataContent::Subway, Color{0xffcc29} }, // 4 OSM: 6432702 WD: Q6553130 -23.01, -43.31 x -22.98, -43.2
    { 1771, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x00ab4e} }, // KTL OSM: 6452936 WD: Q736412 22.29, 114.2 x 22.34, 114.3
    { 2503, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xee4b95} }, // TL8 OSM: 6464333 51.28, -0.2222 x 51.8, 0.2044
    { 2507, 16911, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe6180a} }, // 505 OSM: 6481283 WD: Q13645607 22.38, 114 x 22.41, 114
    { 2511, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x1a8539} }, // 507 OSM: 6481317 WD: Q15917019 22.37, 114 x 22.41, 114
    { 2515, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x8d3219} }, // 610 OSM: 6481421 WD: Q15908713 22.37, 114 x 22.45, 114
    { 2519, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf4e619} }, // 615 OSM: 6481435 WD: Q62127916 22.37, 114 x 22.45, 114
    { 2523, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x44adc3} }, // 614 OSM: 6485195 WD: Q62127914 22.37, 114 x 22.45, 114
    { 2527, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf58c14} }, // 751 OSM: 6485220 WD: Q62127921 22.39, 114 x 22.47, 114
    { 2531, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x70147b} }, // 761P OSM: 6485222 WD: Q15909914 22.44, 114 x 22.47, 114
    { 2536, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf7931d} }, // SN 5 OSM: 6489645 51.07, -0.3187 x 51.5, 0.2699
    { 227, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 27 OSM: 6490955 WD: Q123353107 53.35, 58.96 x 53.48, 59.06
    { 2541, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009933} }, // T-A OSM: 6491413 6.233, -75.57 x 6.248, -75.54
    { 281, NoLogo, 16926, LineMetaDataContent::Tramway, Color{0xed1c24} }, // T1 OSM: 6497386 WD: Q110618690 43.28, 5.547 x 43.3, 5.566
    { 2545, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x6633ff} }, // T1 R OSM: 6545828 WD: Q118592004 36.72, 3.083 x 36.78, 3.263
    { 2550, 16942, NoLogo, LineMetaDataContent::Tramway, Color{0xff00ff} }, // 18E OSM: 6547489 WD: Q63230200 38.7, -9.203 x 38.71, -9.145
    { 213, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xba85bb} }, // 706 OSM: 6558996 WD: Q62127919 22.45, 114 x 22.47, 114
    { 2240, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x8cc022} }, // 705 OSM: 6558997 WD: Q62127918 22.45, 114 x 22.47, 114
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe41f25} }, // 4 OSM: 6576221 WD: Q121368141 48.22, 14.23 x 48.31, 14.29
    { 145, 16955, 5171, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // 14 OSM: 6576716 WD: Q26856861 55.69, 37.49 x 55.85, 37.75
    { 535, 16980, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf7b618} }, // E OSM: 6584634 WD: Q4993859 34.01, -118.5 x 34.05, -118.2
    { 687, 17005, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0072bc} }, // A OSM: 6585129 WD: Q3267759 33.77, -118.3 x 34.15, -117.9
    { 2554, 17030, NoLogo, LineMetaDataContent::LocalTrain, Color{0x009bd5} }, // RB22 OSM: 6593456 WD: Q68006335 52.3, 12.97 x 52.41, 13.64
    { 2559, 17050, NoLogo, LineMetaDataContent::Tramway, Color{0xff7f00} }, // 25E OSM: 6595981 WD: Q63230206 38.71, -9.17 x 38.72, -9.135
    { 1239, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 31 OSM: 6617507 WD: Q123353112 53.38, 58.97 x 53.44, 59.1
    { 26, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 16 OSM: 6627041 WD: Q123353097 53.36, 58.96 x 53.41, 59.1
    { 90, 17063, NoLogo, LineMetaDataContent::LocalTrain, Color{} }, // 68 OSM: 6641022 WD: Q9025977 36.83, -3.668 x 37.42, -2.43
    { 2563, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // C13 OSM: 6641930 WD: Q104192645 50.59, 12.69 x 50.92, 12.98
    { 1059, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 29 OSM: 6653146 55.81, 37.52 x 55.84, 37.58
    { 1749, 17089, 13384, LineMetaDataContent::Subway, Color{0x00893e} }, // b OSM: 6659014 WD: Q24641690 48.09, -1.707 x 48.13, -1.62
    { 56, 17119, 17148, LineMetaDataContent::Tramway, Color{0x0000ff} }, // 1 OSM: 6667548 WD: Q30926891 -22.91, -43.21 x -22.89, -43.17
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xec7e2b} }, // 6 OSM: 6674002 WD: Q124656081 49.74, 8.613 x 49.92, 8.658
    { 700, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // T2 OSM: 6679929 WD: Q107172304 42.84, -2.685 x 42.88, -2.664
    { 42, 17169, NoLogo, LineMetaDataContent::Tramway, Color{0x174ca1} }, // 7 OSM: 6679981 WD: Q117302440 52.38, 16.88 x 52.44, 16.96
    { 22, 17207, NoLogo, LineMetaDataContent::Tramway, Color{0xfdd100} }, // 18 OSM: 6680332 WD: Q108000680 52.38, 16.88 x 52.42, 17
    { 2567, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffa500} }, // MSC OSM: 6686325 14.2, 121 x 14.62, 121.2
    { 480, 17246, 14616, LineMetaDataContent::Subway, Color{0xb2aed3} }, // L12 OSM: 6699916 WD: Q20107064 41.4, 2.119 x 41.4, 2.126
    { 145, 17264, NoLogo, LineMetaDataContent::Subway, Color{0x81312f} }, // 14 OSM: 6728233 WD: Q6553073 23.24, 113.3 x 23.57, 113.6
    { 2571, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x6c421b} }, // S14 OSM: 6731045 WD: Q7388188 47.27, 8.429 x 47.41, 8.841
    { 63, 17285, 9590, LineMetaDataContent::RapidTransit, Color{0xe74a4a} }, // S1 OSM: 6747873 WD: Q108084414 52.11, 20.8 x 52.26, 21.26
    { 2575, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x9a9b9f} }, // Тр8 OSM: 6749431 WD: Q124735426 49.78, 24.03 x 49.84, 24.06
    { 56, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x791714} }, // 1 OSM: 6774704 WD: Q10318644 -12.99, -38.52 x -12.89, -38.44
    { 1986, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x646363} }, // 53 OSM: 6783604 WD: Q84991746 49.96, 8.197 x 50, 8.275
    { 2581, 17296, 17319, LineMetaDataContent::Tramway, Color{0x83b81a} }, // Τ6 OSM: 6792080 WD: Q25535312 37.92, 23.7 x 37.97, 23.74
    { 2585, 17359, 17319, LineMetaDataContent::Tramway, Color{0x83b81a} }, // Τ7 OSM: 6792082 WD: Q25535308 37.85, 23.64 x 37.95, 23.75
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xaa8800} }, // 2 OSM: 6792535 WD: Q121691513 54.14, 19.4 x 54.18, 19.44
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x225500} }, // 4 OSM: 6792545 WD: Q121691517 54.14, 19.4 x 54.19, 19.44
    { 60, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x552200} }, // 3 OSM: 6792594 WD: Q121691515 54.16, 19.39 x 54.19, 19.43
    { 2589, 17382, 9368, LineMetaDataContent::RapidTransit, Color{0x202776} }, // S43 OSM: 6794665 WD: Q86674587 50.62, 5.567 x 50.85, 5.718
    { 41, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfff90a} }, // S7 OSM: 6796259 48.63, 8.065 x 49.01, 8.433
    { 301, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfff90a} }, // S71 OSM: 6796260 48.63, 8.065 x 48.99, 8.405
    { 2593, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x6d682a} }, // S81 OSM: 6796368 WD: Q106362968 48.44, 8.215 x 48.99, 8.83
    { 42, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffa500} }, // 7 OSM: 6799066 39.75, 30.49 x 39.76, 30.54
    { 56, 17404, NoLogo, LineMetaDataContent::Subway, Color{0xe4002b} }, // 1 OSM: 6800211 WD: Q1326478 31.11, 121.4 x 31.4, 121.5
    { 1363, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00bfff} }, // T4 OSM: 6800375 39.75, 30.49 x 39.78, 30.56
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffff00} }, // 6 OSM: 6800648 39.71, 30.49 x 39.78, 30.62
    { 2597, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffff00} }, // T10 OSM: 6800876 39.74, 30.52 x 39.8, 30.6
    { 26, 17424, NoLogo, LineMetaDataContent::Subway, Color{0x2cd5c4} }, // 16 OSM: 6803864 WD: Q5954911 30.91, 121.6 x 31.2, 121.9
    { 6, 17445, NoLogo, LineMetaDataContent::Subway, Color{0xac4fc6} }, // 5 OSM: 6806165 WD: Q1331322 30.91, 121.4 x 31.12, 121.5
    { 60, 17465, NoLogo, LineMetaDataContent::Subway, Color{0xffd100} }, // 3 OSM: 6817204 WD: Q1326495 31.15, 121.4 x 31.41, 121.5
    { 60, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf0e68c} }, // 3 OSM: 6820173 WD: Q121537239 53.85, 27.54 x 53.93, 27.63
    { 2601, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xb6bd00} }, // SIL OSM: 6827213 WD: Q2041013 22.24, 114.1 x 22.28, 114.2
    { 138, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x13a962} }, // 9 OSM: 6831389 WD: Q123363019 56.75, 60.57 x 56.8, 60.63
    { 27, 17474, NoLogo, LineMetaDataContent::Subway, Color{0xd9017a} }, // 6 OSM: 6840940 WD: Q631135 31.15, 121.5 x 31.36, 121.6
    { 2605, 17483, NoLogo, LineMetaDataContent::RapidTransit, Color{0x692832} }, // TL-1 OSM: 6849311 WD: Q5985920 20.61, -103.4 x 20.74, -103.4
    { 735, 17549, NoLogo, LineMetaDataContent::LocalTrain, Color{0xef7d00} }, // RE7 OSM: 6851149 WD: Q1753399 53.55, 9.374 x 54.78, 10.14
    { 2610, 17565, NoLogo, LineMetaDataContent::RapidTransit, Color{0x407058} }, // TL-2 OSM: 6851904 WD: Q5986178 20.66, -103.4 x 20.68, -103.3
    { 2615, 17631, 5171, LineMetaDataContent::Subway, Color{0xffff00} }, // 8А OSM: 6855054 WD: Q1978532 55.61, 37.28 x 55.75, 37.54
    { 511, 17656, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff6600} }, // L2 OSM: 6857222 WD: Q5986175 -37.03, -73.16 x -36.82, -73.06
    { 507, 17714, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff6600} }, // L1 OSM: 6857223 WD: Q5985914 -36.98, -73.12 x -36.71, -72.94
    { 22, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc92223} }, // 18 OSM: 6893258 WD: Q123363029 56.81, 60.54 x 56.86, 60.67
    { 243, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xa2d9f7} }, // 20 OSM: 6895239 WD: Q123363032 56.82, 60.61 x 56.87, 60.67
    { 326, 17782, 3675, LineMetaDataContent::RapidTransit, Color{0xc6cc00} }, // J OSM: 6904183 WD: Q93388 48.88, 1.478 x 49.29, 2.326
    { 2619, 17816, 5804, LineMetaDataContent::Tramway, Color{0xf68c59} }, // T3a OSM: 6907402 WD: Q2420695 48.82, 2.27 x 48.85, 2.411
    { 1363, 17850, 5804, LineMetaDataContent::Tramway, Color{0xf2af00} }, // T4 OSM: 6910344 WD: Q1826681 48.89, 2.476 x 48.93, 2.571
    { 1366, 17883, 5804, LineMetaDataContent::Tramway, Color{0xb156a1} }, // T5 OSM: 6910410 WD: Q3238968 48.94, 2.356 x 48.98, 2.391
    { 1603, 17916, 5804, LineMetaDataContent::Tramway, Color{0xe85426} }, // T6 OSM: 6910437 WD: Q3238993 48.78, 2.169 x 48.81, 2.301
    { 1725, 17949, 5804, LineMetaDataContent::Tramway, Color{0xb98b59} }, // T7 OSM: 6910465 WD: Q3239019 48.71, 2.352 x 48.79, 2.373
    { 149, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf8c800} }, // 15 OSM: 6914129 WD: Q29258503 50.07, 14.36 x 50.1, 14.47
    { 2623, 17982, NoLogo, LineMetaDataContent::LocalTrain, Color{0x66aa22} }, // RB10 OSM: 6924342 WD: Q15195695 52.47, 12.88 x 52.61, 13.38
    { 2087, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x5cda21} }, // RS30 OSM: 6925925 53.05, 8.002 x 53.18, 8.815
    { 305, 18002, 226, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // RS4 OSM: 6925927 WD: Q84703708 53.05, 8.452 x 53.49, 8.815
    { 2628, 18017, 18017, LineMetaDataContent::Subway, Color{0xffcf00} }, // Orlyval OSM: 6928902 WD: Q432593 48.73, 2.3 x 48.76, 2.37
    { 2636, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x142b4a} }, // CDGVAL OSM: 6928933 WD: Q1023114 49, 2.542 x 49.01, 2.572
    { 217, NoLogo, 9590, LineMetaDataContent::RapidTransit, Color{0xffae00} }, // S3 OSM: 6931734 WD: Q124516332 52.17, 20.94 x 52.44, 21.18
    { 2372, 18040, NoLogo, LineMetaDataContent::LocalTrain, Color{0xe64dff} }, // RE6 OSM: 6933203 WD: Q63224485 52.5, 11.76 x 53.16, 13.3
    { 687, 18059, NoLogo, LineMetaDataContent::Subway, Color{0x800080} }, // A OSM: 6937084 WD: Q4268353 24.96, 121.2 x 25.09, 121.5
    { 733, 18090, 4032, LineMetaDataContent::Subway, Color{0xfccc0a} }, // W OSM: 6942556 WD: Q126567 40.7, -74.01 x 40.78, -73.91
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xd79c58} }, // 12 OSM: 6945653 WD: Q123363022 56.82, 60.58 x 56.86, 60.69
    { 149, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xd5d6ec} }, // 15 OSM: 6966205 WD: Q123363025 56.77, 60.58 x 56.84, 60.69
    { 2643, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008531} }, // Luas Green Line OSM: 6975500 WD: Q2086105 53.24, -6.298 x 53.37, -6.143
    { 2659, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x68c56b} }, // DART OSM: 6979159 WD: Q125147653 53.14, -6.255 x 53.45, -6.06
    { 56, 18116, 8967, LineMetaDataContent::Tramway, Color{0xc00027} }, // 1 OSM: 6981890 WD: Q2211906 47.74, 7.321 x 47.78, 7.343
    { 6, 18141, 18162, LineMetaDataContent::Subway, Color{0xf6a90b} }, // 5 OSM: 6996917 WD: Q957143 50.81, 4.266 x 50.86, 4.432
    { 16, 18186, 8967, LineMetaDataContent::Tramway, Color{0xffd80e} }, // 2 OSM: 7006051 WD: Q2024859 47.73, 7.297 x 47.76, 7.352
    { 56, 18211, 18162, LineMetaDataContent::Subway, Color{0xb5378c} }, // 1 OSM: 7006076 WD: Q1345228 50.84, 4.319 x 50.86, 4.464
    { 60, 18232, 8967, LineMetaDataContent::Tramway, Color{0x00a651} }, // 3 OSM: 7006942 WD: Q3238912 47.74, 7.275 x 47.76, 7.344
    { 16, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x142b4a} }, // 2 OSM: 7011253 WD: Q52773923 49, 2.578 x 49, 2.591
    { 1475, 18257, NoLogo, LineMetaDataContent::LocalTrain, Color{0xff0000} }, // RE1 OSM: 7024716 WD: Q15119401 52.13, 11.63 x 52.53, 14.66
    { 16, 18276, 17148, LineMetaDataContent::Tramway, Color{0x008000} }, // 2 OSM: 7064054 WD: Q30926895 -22.91, -43.21 x -22.9, -43.17
    { 1222, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 36 OSM: 7080875 WD: Q122585362 55.75, 37.71 x 55.83, 37.82
    { 51, 18305, 226, LineMetaDataContent::RapidTransit, Color{0x6cc247} }, // S2 OSM: 7091572 WD: Q7388247 48.13, 11.25 x 48.41, 11.91
    { 110, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x223344} }, // 22 OSM: 7095091 54.26, 48.28 x 54.36, 48.41
    { 2664, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x151cf3} }, // MTN OSM: 7106220 WD: Q24960835 -33.63, -70.71 x -33.45, -70.68
    { 507, 18321, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // L1 OSM: 7106760 WD: Q3011576 43.24, -3.013 x 43.4, -2.897
    { 306, 18344, 226, LineMetaDataContent::RapidTransit, Color{0xed1c24} }, // S4 OSM: 7113761 WD: Q116210481 46.55, 13.37 x 46.63, 13.85
    { 51, 18360, 226, LineMetaDataContent::RapidTransit, Color{0x3c8475} }, // S2 OSM: 7113763 WD: Q116210398 46.62, 13.85 x 46.77, 14.37
    { 63, 18376, 226, LineMetaDataContent::RapidTransit, Color{0x17489e} }, // S1 OSM: 7113764 WD: Q116209766 46.6, 12.77 x 46.95, 14.48
    { 42, 18392, 8171, LineMetaDataContent::Tramway, Color{0xefe048} }, // 7 OSM: 7135778 WD: Q3239018 50.81, 4.336 x 50.9, 4.408
    { 515, 18413, NoLogo, LineMetaDataContent::Subway, Color{0xe3007d} }, // L3 OSM: 7141757 WD: Q2992379 43.25, -2.926 x 43.27, -2.889
    { 1020, 18436, 8171, LineMetaDataContent::Tramway, Color{0xe43c2e} }, // 92 OSM: 7152034 WD: Q2661521 50.79, 4.34 x 50.88, 4.381
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x37b355} }, // 2 OSM: 7157243 WD: Q60031554 48.38, 9.936 x 48.43, 9.987
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xed1b24} }, // 1 OSM: 7157244 WD: Q60031375 48.39, 9.955 x 48.43, 10.03
    { 1385, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x2b2963} }, // E4 OSM: 7158306 43.2, -2.926 x 43.42, -2.667
    { 60, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 3 OSM: 7176448 WD: Q121133044 44.03, 43 x 44.05, 43.12
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 2 OSM: 7176450 WD: Q121133004 44.04, 42.98 x 44.06, 43.06
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 1 OSM: 7176452 WD: Q121132934 44.03, 43.03 x 44.04, 43.11
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 8 OSM: 7181179 WD: Q121140865 44.03, 43.03 x 44.05, 43.12
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 6 OSM: 7181183 WD: Q121140561 44.04, 43 x 44.06, 43.06
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 4 OSM: 7181187 WD: Q121140903 44.03, 43.06 x 44.06, 43.12
    { 507, 18458, NoLogo, LineMetaDataContent::RapidTransit, Color{0xc00b31} }, // L1 OSM: 7183555 WD: Q29634861 37.14, -3.654 x 37.23, -3.592
    { 2668, 18482, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // C-2 OSM: 7193330 WD: Q4802702 43.25, -3.112 x 43.32, -2.928
    { 2672, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // C14 OSM: 7204222 WD: Q104192612 50.7, 12.85 x 50.99, 12.98
    { 2676, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // C15 OSM: 7211723 WD: Q104192546 50.81, 12.92 x 50.97, 13.12
    { 16, 18500, 9428, LineMetaDataContent::Subway, Color{0x0055c8} }, // 2 OSM: 7227705 WD: Q50718 48.85, 2.278 x 48.88, 2.399
    { 56, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x93c21c} }, // 1 OSM: 7252644 WD: Q60669571 -23.97, -46.41 x -23.96, -46.31
    { 2680, NoLogo, 16871, LineMetaDataContent::Subway, Color{0xe42313} }, // Central OSM: 7254206 WD: Q205355 51.5, -0.4377 x 51.69, 0.1146
    { 535, 18535, 2826, LineMetaDataContent::RapidTransit, Color{0xc04191} }, // E OSM: 7271953 WD: Q668655 48.74, 2.225 x 48.9, 2.759
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf6c828} }, // 13 OSM: 7295272 WD: Q96483392 47.35, 8.481 x 47.41, 8.542
    { 16, 18567, 18162, LineMetaDataContent::Subway, Color{0xed6c23} }, // 2 OSM: 7305855 WD: Q1826676 50.83, 4.321 x 50.87, 4.37
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xef7f1a} }, // 11 OSM: 7313918 WD: Q123363021 56.84, 60.5 x 56.84, 60.56
    { 27, 18588, NoLogo, LineMetaDataContent::Subway, Color{0x80225f} }, // 6 OSM: 7322006 WD: Q6553140 23.11, 113.2 x 23.2, 113.5
    { 145, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 14 OSM: 7339185 WD: Q122585355 55.68, 37.54 x 55.73, 37.61
    { 1476, 18608, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0063a9} }, // E1 OSM: 7353799 WD: Q43263877 43.16, -2.926 x 43.31, -1.981
    { 67, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xb0cb1f} }, // 10 OSM: 7361616 WD: Q123363020 56.82, 60.5 x 56.88, 60.64
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x024428} }, // 13 OSM: 7363045 WD: Q123363023 56.83, 60.5 x 56.88, 60.69
    { 145, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc86a16} }, // 14 OSM: 7363436 WD: Q123363024 56.76, 60.59 x 56.9, 60.64
    { 1837, 18625, 226, LineMetaDataContent::RapidTransit, Color{0x9f4c37} }, // S41 OSM: 7369771 WD: Q12374455 52.46, 13.28 x 52.55, 13.48
    { 63, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // S1 OSM: 7370516 47.8, 7.589 x 48.06, 8.504
    { 445, 18656, 8171, LineMetaDataContent::Tramway, Color{0x4c8b33} }, // 81 OSM: 7375224 WD: Q2133516 50.82, 4.28 x 50.84, 4.408
    { 63, 18678, 9368, LineMetaDataContent::RapidTransit, Color{0x005f33} }, // S1 OSM: 7382640 WD: Q24929119 50.6, 4.32 x 51.22, 4.497
    { 51, NoLogo, 9368, LineMetaDataContent::RapidTransit, Color{0xf16122} }, // S2 OSM: 7383577 WD: Q56309162 50.61, 4.139 x 50.9, 4.716
    { 1285, NoLogo, 9368, LineMetaDataContent::RapidTransit, Color{0x009696} }, // S20 OSM: 7386794 WD: Q56309254 50.67, 4.565 x 50.88, 4.719
    { 1675, 18701, 3582, LineMetaDataContent::RapidTransit, Color{0x66ff00} }, // C4 OSM: 7387133 WD: Q5987394 43.49, -6.152 x 43.59, -5.676
    { 2688, 18730, 3582, LineMetaDataContent::RapidTransit, Color{0xffcc00} }, // C5 OSM: 7387134 WD: Q27968528 43.25, -5.728 x 43.54, -5.565
    { 44, NoLogo, 9368, LineMetaDataContent::RapidTransit, Color{0xffcc06} }, // S5 OSM: 7387151 WD: Q56309389 50.69, 3.87 x 51.02, 4.484
    { 2691, 3552, 3582, LineMetaDataContent::RapidTransit, Color{0xff6600} }, // F7 OSM: 7387168 WD: Q27976587 43.35, -6.113 x 43.55, -5.856
    { 1311, 3948, 3582, LineMetaDataContent::LocalTrain, Color{0xff0000} }, // C1 OSM: 7387234 WD: Q5987183 43.07, -5.877 x 43.54, -5.676
    { 1319, 13507, 3582, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // C3 OSM: 7387332 WD: Q5987208 43.36, -5.931 x 43.59, -5.806
    { 1315, 18482, 3582, LineMetaDataContent::RapidTransit, Color{0x008000} }, // C2 OSM: 7387377 WD: Q5987199 43.29, -5.877 x 43.37, -5.645
    { 217, NoLogo, 9368, LineMetaDataContent::RapidTransit, Color{0x222975} }, // S3 OSM: 7388964 WD: Q56309590 50.82, 3.814 x 51.02, 4.366
    { 306, NoLogo, 9368, LineMetaDataContent::RapidTransit, Color{0xcb2127} }, // S4 OSM: 7389117 WD: Q56309251 50.82, 4.039 x 51.02, 4.523
    { 290, NoLogo, 9368, LineMetaDataContent::RapidTransit, Color{0x965f26} }, // S6 OSM: 7391007 WD: Q56309855 50.69, 3.87 x 50.89, 4.378
    { 41, NoLogo, 9368, LineMetaDataContent::RapidTransit, Color{0x571759} }, // S7 OSM: 7391045 WD: Q56309167 50.73, 4.241 x 50.92, 4.434
    { 47, NoLogo, 9368, LineMetaDataContent::RapidTransit, Color{0x0096cb} }, // S8 OSM: 7391071 WD: Q56309403 50.65, 3.814 x 50.91, 4.617
    { 631, NoLogo, 9368, LineMetaDataContent::RapidTransit, Color{0x67bc45} }, // S9 OSM: 7391314 WD: Q56309779 50.6, 4.335 x 50.9, 5.08
    { 1046, NoLogo, 9368, LineMetaDataContent::RapidTransit, Color{0x000000} }, // S10 OSM: 7391375 WD: Q56309273 50.83, 4.039 x 51.02, 4.366
    { 347, 18758, NoLogo, LineMetaDataContent::LocalTrain, Color{0x035e33} }, // S51 OSM: 7392144 WD: Q115284858 50.74, 3.575 x 51.18, 3.758
    { 2157, 18779, 9368, LineMetaDataContent::RapidTransit, Color{0xcc2027} }, // S44 OSM: 7392745 WD: Q86669124 50.62, 5.08 x 50.75, 5.694
    { 2694, 9346, 9368, LineMetaDataContent::RapidTransit, Color{0x005d30} }, // L-17 OSM: 7392801 WD: Q86358695 50.56, 5.559 x 50.66, 5.854
    { 2699, 18482, 3582, LineMetaDataContent::RapidTransit, Color{} }, // C2f OSM: 7393461 WD: Q107407546 43.31, -4.232 x 43.46, -3.811
    { 85, 18801, NoLogo, LineMetaDataContent::RapidTransit, Color{0x005d30} }, // S61 OSM: 7394292 WD: Q84951112 50.39, 4.432 x 50.67, 4.881
    { 2703, 18827, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf26021} }, // S62 OSM: 7395296 WD: Q86070870 50.4, 4.17 x 50.51, 4.439
    { 81, 18853, NoLogo, LineMetaDataContent::RapidTransit, Color{0x1a2277} }, // S63 OSM: 7396143 WD: Q85178055 50.27, 3.967 x 50.41, 4.439
    { 2707, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x4a611c} }, // RL1 OSM: 7399137 WD: Q3781389 41.62, 0.631 x 41.79, 0.8166
    { 331, 18879, 9368, LineMetaDataContent::RapidTransit, Color{0x202776} }, // S33 OSM: 7400676 WD: Q87071069 51.14, 4.421 x 51.22, 5.115
    { 165, 18905, NoLogo, LineMetaDataContent::LocalTrain, Color{0xf26021} }, // S52 OSM: 7400734 WD: Q115285798 50.77, 3.71 x 51.04, 3.875
    { 762, 18926, NoLogo, LineMetaDataContent::RapidTransit, Color{0xcc2027} }, // S64 OSM: 7403404 WD: Q85944484 50.06, 4.387 x 50.41, 4.538
    { 322, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffff00} }, // 25 OSM: 7409703 31.2, 29.9 x 31.22, 29.93
    { 153, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x7e71b1} }, // 19 OSM: 7415625 WD: Q123363031 56.81, 60.54 x 56.89, 60.59
    { 341, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xd3db58} }, // 23 OSM: 7415926 WD: Q123363034 56.83, 60.55 x 56.89, 60.69
    { 247, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xa75f4a} }, // 24 OSM: 7417521 WD: Q123363035 56.86, 60.5 x 56.9, 60.64
    { 56, 18952, NoLogo, LineMetaDataContent::Tramway, Color{0xf38230} }, // 1 OSM: 7418079 WD: Q59134535 33.53, -7.67 x 33.6, -7.5
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffdb2f} }, // 2 OSM: 7418090 WD: Q59159905 33.56, -7.682 x 33.61, -7.507
    { 1363, 19006, NoLogo, LineMetaDataContent::Tramway, Color{0xffa500} }, // T4 OSM: 7420266 WD: Q15507510 41.02, 28.85 x 41.12, 28.93
    { 59, 19034, 9428, LineMetaDataContent::Subway, Color{0x82c8e6} }, // 13 OSM: 7420641 WD: Q50759 48.81, 2.284 x 48.95, 2.369
    { 15, 19070, 9428, LineMetaDataContent::Subway, Color{0x00643c} }, // 12 OSM: 7420642 WD: Q50757 48.82, 2.273 x 48.91, 2.381
    { 55, 19106, 9428, LineMetaDataContent::Subway, Color{0x6e491e} }, // 11 OSM: 7420643 WD: Q50756 48.86, 2.348 x 48.89, 2.481
    { 19, 19142, 9428, LineMetaDataContent::Subway, Color{0xd282be} }, // 8 OSM: 7420644 WD: Q50751 48.77, 2.278 x 48.87, 2.464
    { 6, 19177, 9428, LineMetaDataContent::Subway, Color{0xff7f32} }, // 5 OSM: 7420645 WD: Q50745 48.83, 2.354 x 48.91, 2.449
    { 2711, 19212, 9428, LineMetaDataContent::Subway, Color{0x82c8e6} }, // 3bis OSM: 7420646 WD: Q50742 48.87, 2.399 x 48.88, 2.407
    { 421, 19250, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf28e42} }, // P OSM: 7420696 WD: Q93874 48.51, 2.359 x 49.18, 3.409
    { 584, 19284, 3675, LineMetaDataContent::RapidTransit, Color{0xf3a4ba} }, // R OSM: 7420697 WD: Q93383 48.01, 2.374 x 48.84, 2.943
    { 34, 19318, 3675, LineMetaDataContent::RapidTransit, Color{0x7b4339} }, // H OSM: 7420698 WD: Q93386 48.88, 2.093 x 49.26, 2.468
    { 680, 19352, 3675, LineMetaDataContent::RapidTransit, Color{0x00a88f} }, // N OSM: 7420700 WD: Q93376 48.64, 1.37 x 48.99, 2.319
    { 271, 19386, 2826, LineMetaDataContent::RapidTransit, Color{0x5291ce} }, // B OSM: 7420701 WD: Q1347825 48.69, 2.071 x 49.01, 2.642
    { 2716, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // CCL OSM: 7422278 WD: Q954278 -41.29, 174.8 x -41.28, 174.8
    { 406, 19418, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfd8fb4} }, // S OSM: 7424196 WD: Q2329867 48.17, 16.33 x 48.26, 16.4
    { 572, NoLogo, 3913, LineMetaDataContent::RapidTransit, Color{0x035eb9} }, // K OSM: 7435653 WD: Q118874957 60.17, 24.93 x 60.41, 25.11
    { 687, 19440, 3913, LineMetaDataContent::RapidTransit, Color{0x8c4799} }, // A OSM: 7440364 WD: Q118874158 60.17, 24.81 x 60.22, 24.94
    { 9, 19458, NoLogo, LineMetaDataContent::Subway, Color{0x5f259f} }, // 4 OSM: 7448424 WD: Q1326504 31.18, 121.4 x 31.26, 121.5
    { 19, 19467, NoLogo, LineMetaDataContent::Subway, Color{0x009fdf} }, // 8 OSM: 7451833 WD: Q1152341 31.06, 121.5 x 31.32, 121.5
    { 138, 19476, NoLogo, LineMetaDataContent::Subway, Color{0x71c5e8} }, // 9 OSM: 7451835 WD: Q1152370 30.99, 121.2 x 31.27, 121.7
    { 15, 19485, NoLogo, LineMetaDataContent::Subway, Color{0x007b5f} }, // 12 OSM: 7451887 WD: Q877180 31.13, 121.3 x 31.28, 121.6
    { 59, 19506, NoLogo, LineMetaDataContent::Subway, Color{0xef95cf} }, // 13 OSM: 7451890 WD: Q607539 31.17, 121.3 x 31.25, 121.6
    { 67, 19516, NoLogo, LineMetaDataContent::Subway, Color{0xc1a7e2} }, // 10 OSM: 7452119 WD: Q528209 31.17, 121.3 x 31.36, 121.6
    { 41, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf9e32c} }, // S7 OSM: 7508635 WD: Q125989608 49.67, 18.35 x 49.75, 18.64
    { 306, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x83d9e0} }, // S4 OSM: 7510544 WD: Q125989605 49.68, 18.04 x 49.91, 18.55
    { 2720, 19526, 19551, LineMetaDataContent::RapidTransit, Color{0xed8000} }, // I2 OSM: 7527498 WD: Q484739 37.44, 126.6 x 37.6, 126.8
    { 416, 19579, 19551, LineMetaDataContent::RapidTransit, Color{0xfda600} }, // U OSM: 7530882 WD: Q491655 37.72, 127 x 37.75, 127.1
    { 535, NoLogo, 19551, LineMetaDataContent::RapidTransit, Color{0x509f22} }, // E OSM: 7531174 WD: Q489609 37.24, 127.1 x 37.29, 127.2
    { 733, 19607, 19551, LineMetaDataContent::RapidTransit, Color{0xb0ce18} }, // W OSM: 7533584 WD: Q3832795 37.58, 127 x 37.66, 127
    { 359, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // Blue OSM: 7548642 41.47, -81.71 x 41.51, -81.54
    { 639, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // Green OSM: 7548643 41.48, -81.71 x 41.51, -81.52
    { 371, NoLogo, 19645, LineMetaDataContent::Subway, Color{0xff0000} }, // Red OSM: 7551457 WD: Q2136023 41.41, -81.84 x 41.53, -81.58
    { 60, NoLogo, 19668, LineMetaDataContent::Tramway, Color{0x00ff00} }, // 3 OSM: 7560907 WD: Q7833152 51.34, -0.1055 x 51.38, -0.01743
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 1 OSM: 7568956 WD: Q4461887 53.89, 27.54 x 53.95, 27.62
    { 42, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8b0000} }, // 7 OSM: 7571262 WD: Q121537243 53.85, 27.54 x 53.91, 27.63
    { 2723, 19686, 19703, LineMetaDataContent::Subway, Color{0xffff00} }, // YL OSM: 7572167 WD: Q4710841 38.79, -77.08 x 38.91, -77.02
    { 2726, NoLogo, 19724, LineMetaDataContent::RapidTransit, Color{0xbcbdc0} }, // Silver OSM: 7572385 WD: Q86752660 40.29, -80.03 x 40.45, -79.99
    { 2733, 19757, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0063a7} }, // 510 OSM: 7572438 WD: Q4929374 32.54, -117.2 x 32.88, -117
    { 2737, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x80276c} }, // CR-Fitchburg OSM: 7573753 WD: Q172548 42.36, -71.85 x 42.58, -71.06
    { 371, NoLogo, 19724, LineMetaDataContent::RapidTransit, Color{0xec1b24} }, // Red OSM: 7574880 WD: Q7304506 40.34, -80.05 x 40.45, -79.99
    { 359, NoLogo, 19724, LineMetaDataContent::RapidTransit, Color{0x77b6e4} }, // Blue OSM: 7575525 WD: Q18229920 40.34, -80.05 x 40.45, -79.99
    { 700, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe0644c} }, // T2 OSM: 7580423 WD: Q3239070 50.32, 3.511 x 50.46, 3.596
    { 281, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf0345c} }, // T1 OSM: 7580424 WD: Q3239057 50.32, 3.385 x 50.37, 3.523
    { 2757, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0066cc} }, // TC OSM: 7597545 WD: Q3538439 -34.51, -58.58 x -34.42, -58.48
    { 16, 19796, 19551, LineMetaDataContent::Subway, Color{0x33a23d} }, // 2 OSM: 7625892 WD: Q17501 37.48, 126.8 x 37.57, 127.1
    { 9, 19819, 19551, LineMetaDataContent::Subway, Color{0x32a1c8} }, // 4 OSM: 7625893 WD: Q489253 37.3, 126.7 x 37.72, 127.2
    { 507, 19842, NoLogo, LineMetaDataContent::Subway, Color{0x659acd} }, // L1 OSM: 7627370 WD: Q20685853 36.71, 3.054 x 36.79, 3.138
    { 348, 19874, 8171, LineMetaDataContent::Tramway, Color{0xf3c300} }, // 51 OSM: 7632520 WD: Q751385 50.84, 4.33 x 50.89, 4.349
    { 1023, 19896, 8171, LineMetaDataContent::Tramway, Color{0xed7807} }, // 93 OSM: 7632524 WD: Q2845878 50.82, 4.33 x 50.89, 4.372
    { 56, 19918, NoLogo, LineMetaDataContent::Subway, Color{0x147049} }, // 1 OSM: 7643008 WD: Q21034316 38.02, 46.23 x 38.08, 46.36
    { 162, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 49 OSM: 7657682 WD: Q122585370 55.68, 37.62 x 55.7, 37.69
    { 16, 19942, 9685, LineMetaDataContent::Subway, Color{0x006abc} }, // 2 OSM: 7660420 WD: Q1771527 56.32, 43.89 x 56.34, 43.97
    { 451, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x929292} }, // 59 OSM: 7662334 WD: Q68580821 49.99, 8.223 x 50.02, 8.26
    { 352, 19961, 19961, LineMetaDataContent::Subway, Color{0xf25e24} }, // M1 OSM: 7664663 WD: Q207287 60.14, 24.64 x 60.21, 25.15
    { 433, 19961, 19961, LineMetaDataContent::Subway, Color{0xf25e24} }, // M2 OSM: 7664664 WD: Q207287 60.16, 24.8 x 60.24, 25.11
    { 2760, NoLogo, 16871, LineMetaDataContent::Subway, Color{0xae6017} }, // Bakerloo OSM: 7666698 WD: Q19892 51.5, -0.3355 x 51.59, -0.1007
    { 2769, NoLogo, 16871, LineMetaDataContent::Subway, Color{0xf4a9be} }, // Hammersmith & City OSM: 7666927 WD: Q211270 51.49, -0.2269 x 51.54, 0.08088
    { 2788, NoLogo, 16871, LineMetaDataContent::Subway, Color{0xffd329} }, // Circle OSM: 7671007 WD: Q210321 51.49, -0.2269 x 51.53, -0.07523
    { 2795, NoLogo, 16871, LineMetaDataContent::Subway, Color{0x93ceba} }, // Waterloo & City OSM: 7672075 WD: Q207699 51.5, -0.1142 x 51.51, -0.09074
    { 2811, NoLogo, 16871, LineMetaDataContent::Subway, Color{0x949699} }, // Jubilee OSM: 7673326 WD: Q961290 51.5, -0.303 x 51.62, 0.01165
    { 2819, NoLogo, 16871, LineMetaDataContent::Subway, Color{0x91005a} }, // Metropolitan OSM: 7673626 WD: Q19891 51.51, -0.6366 x 51.71, -0.0757
    { 2832, NoLogo, 16871, LineMetaDataContent::Subway, Color{0x00a166} }, // District OSM: 7677096 WD: Q211265 51.42, -0.3016 x 51.56, 0.2526
    { 56, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xcc0000} }, // 1 OSM: 7680781 10.15, -68.01 x 10.2, -68
    { 56, 19986, 19986, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 7683834 WD: Q239927 37.51, 15.05 x 37.52, 15.1
    { 56, 20020, NoLogo, LineMetaDataContent::Subway, Color{0x0000ff} }, // 1 OSM: 7684062 WD: Q6553099 19.09, 72.82 x 19.13, 72.91
    { 2841, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008f75} }, // CAT OSM: 7685186 10.48, -66.81 x 10.49, -66.8
    { 60, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x00af23} }, // 3 OSM: 7686574 WD: Q5017776 30.02, 31.18 x 30.15, 31.43
    { 2845, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xdc241f} }, // NSL OSM: 7695961 WD: Q759229 1.27, 103.7 x 1.45, 103.9
    { 2849, 20042, NoLogo, LineMetaDataContent::LocalTrain, Color{0x06844b} }, // RB66 OSM: 7699251 WD: Q67991420 53.02, 13.97 x 53.42, 14.55
    { 56, 20062, 20062, LineMetaDataContent::Subway, Color{0xffa500} }, // 1 OSM: 7702663 WD: Q106335393 34.39, 132.4 x 34.48, 132.5
    { 34, 20078, 20105, LineMetaDataContent::Subway, Color{0x0077cc} }, // H OSM: 7702769 WD: Q1073881 33.59, 130.4 x 33.63, 130.4
    { 2872, NoLogo, 16871, LineMetaDataContent::Subway, Color{0x094fa3} }, // Piccadilly OSM: 7702940 WD: Q207689 51.46, -0.4877 x 51.65, -0.09515
    { 2883, NoLogo, 16871, LineMetaDataContent::Subway, Color{0x000000} }, // Northern OSM: 7702944 WD: Q214793 51.4, -0.2756 x 51.65, -0.08677
    { 572, 20134, 20105, LineMetaDataContent::Subway, Color{0xff4500} }, // K OSM: 7703353 WD: Q908188 33.58, 130.3 x 33.6, 130.4
    { 2892, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xc61094} }, // MM OSM: 7703640 WD: Q852314 35.44, 139.6 x 35.47, 139.7
    { 26, 20157, NoLogo, LineMetaDataContent::Tramway, Color{0x51279e} }, // 16 OSM: 7704225 WD: Q117430136 52.38, 16.91 x 52.46, 17
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x38ab43} }, // 6 OSM: 7705201 WD: Q108000749 52.39, 16.85 x 52.41, 17
    { 19, 20196, NoLogo, LineMetaDataContent::Tramway, Color{0xe7212a} }, // 8 OSM: 7705202 WD: Q117303255 52.41, 16.88 x 52.42, 17
    { 56, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xee3c3c} }, // 1 OSM: 7705626 WD: Q66782266 29.55, 52.45 x 29.69, 52.6
    { 56, NoLogo, 20234, LineMetaDataContent::Subway, Color{0x1a988c} }, // 1 OSM: 7705633 WD: Q104230289 32.49, 51.53 x 32.84, 51.75
    { 42, 20257, 20281, LineMetaDataContent::Subway, Color{0x6a00ff} }, // 7 OSM: 7705644 WD: Q20110124 35.67, 51.35 x 35.79, 51.49
    { 9, 20303, 20281, LineMetaDataContent::Subway, Color{0xffff00} }, // 4 OSM: 7705669 WD: Q20110121 35.69, 51.3 x 35.75, 51.5
    { 2895, 20327, 19551, LineMetaDataContent::RapidTransit, Color{0x8652a1} }, // BGL OSM: 7705740 WD: Q87056 35.16, 128.9 x 35.27, 129
    { 2899, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x43b02a} }, // THZ1 OSM: 7708095 WD: Q15906593 23.1, 113.3 x 23.11, 113.4
    { 56, 14744, NoLogo, LineMetaDataContent::Subway, Color{0xdf2937} }, // 1 OSM: 7712343 WD: Q25420888 8.962, -79.55 x 9.065, -79.51
    { 572, 20349, 20391, LineMetaDataContent::Subway, Color{0xec78b4} }, // K OSM: 7712576 WD: Q1078347 35.2, 136.9 x 35.2, 136.9
    { 584, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x3e754e} }, // R OSM: 7712694 WD: Q7360056 34.68, 135.3 x 34.72, 135.3
    { 421, 20424, NoLogo, LineMetaDataContent::RapidTransit, Color{0x3573bd} }, // P OSM: 7712875 WD: Q7230715 34.64, 135.2 x 34.7, 135.2
    { 572, 20450, 20472, LineMetaDataContent::Subway, Color{0x267dce} }, // K OSM: 7712969 WD: Q844019 34.65, 135.1 x 34.69, 135.2
    { 309, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfb5373} }, // D26 OSM: 7713151 50.58, 15.93 x 50.82, 16.07
    { 9, 20503, NoLogo, LineMetaDataContent::Subway, Color{0xdc241f} }, // 4 OSM: 7713538 WD: Q1004293 22.52, 114 x 22.73, 114.1
    { 138, 20526, NoLogo, LineMetaDataContent::Tramway, Color{0xf7822a} }, // 9 OSM: 7715858 WD: Q108006623 52.37, 16.9 x 52.44, 16.94
    { 433, 20564, 20592, LineMetaDataContent::Subway, Color{0x009a4c} }, // M2 OSM: 7719078 WD: Q1880934 41.01, 28.95 x 41.14, 29.03
    { 8, 20616, 20592, LineMetaDataContent::Subway, Color{0xe91e76} }, // M4 OSM: 7719080 WD: Q1880989 40.88, 29.02 x 41, 29.31
    { 352, 20644, 20592, LineMetaDataContent::Subway, Color{0xe32726} }, // M1 OSM: 7719081 WD: Q6048705 40.98, 28.82 x 41.05, 28.95
    { 1231, 20672, 20592, LineMetaDataContent::Subway, Color{0x00a8e1} }, // M3 OSM: 7719082 WD: Q1880963 40.97, 28.77 x 41.12, 28.88
    { 29, 20700, 20592, LineMetaDataContent::Subway, Color{0xcaaa79} }, // M6 OSM: 7719783 WD: Q16949744 41.08, 29.01 x 41.09, 29.05
    { 406, 20728, 20472, LineMetaDataContent::Subway, Color{0x00ae8e} }, // S OSM: 7720729 WD: Q1066548 34.66, 135 x 34.76, 135.2
    { 2904, 20751, NoLogo, LineMetaDataContent::LocalTrain, Color{0xda6ba2} }, // RB51 OSM: 7724425 WD: Q63348259 52.39, 12.33 x 52.6, 12.56
    { 355, 20771, 20784, LineMetaDataContent::Subway, Color{0x1e398d} }, // MRT Blue OSM: 7725030 WD: Q2486364 13.71, 100.4 x 13.81, 100.6
    { 1566, 20807, 20784, LineMetaDataContent::Subway, Color{0x893b90} }, // MRT Purple OSM: 7725058 WD: Q6584549 13.81, 100.4 x 13.89, 100.5
    { 507, 20822, 20845, LineMetaDataContent::Subway, Color{0x228b22} }, // L1 OSM: 7727216 WD: Q5985884 -12.21, -77.01 x -11.96, -76.93
    { 2909, 20891, 19551, LineMetaDataContent::Subway, Color{0xc82127} }, // 326 OSM: 7728256 WD: Q20388 37.29, 127 x 37.52, 127.1
    { 2913, 20924, 20924, LineMetaDataContent::Subway, Color{0x2e8b57} }, // 仙台市南北線 (Sendai Namboku Line) OSM: 7732249 WD: Q908156 38.21, 140.9 x 38.32, 140.9
    { 2954, 20924, 20924, LineMetaDataContent::Subway, Color{0x00bfff} }, // 仙台市東西線 (Sendai Tozai Line) OSM: 7732250 WD: Q7450186 38.24, 140.8 x 38.26, 140.9
    { 271, 20952, 20999, LineMetaDataContent::Subway, Color{0x005ba5} }, // B OSM: 7732280 WD: Q841360 35.4, 139.5 x 35.57, 139.6
    { 676, 21034, 20999, LineMetaDataContent::Subway, Color{0x048d58} }, // G OSM: 7732283 WD: Q910329 35.51, 139.5 x 35.56, 139.6
    { 507, 21082, NoLogo, LineMetaDataContent::Subway, Color{0xcc0000} }, // L1 OSM: 7732970 WD: Q4215382 -33.46, -70.72 x -33.41, -70.55
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xffbe2e} }, // 2 OSM: 7732971 WD: Q11690005 -33.58, -70.68 x -33.38, -70.64
    { 503, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x292d91} }, // L4 OSM: 7732972 WD: Q9025952 -33.61, -70.6 x -33.42, -70.57
    { 2993, 21107, NoLogo, LineMetaDataContent::Subway, Color{0x0099ff} }, // L4A OSM: 7732973 WD: Q11690009 -33.54, -70.67 x -33.52, -70.6
    { 1323, 21133, NoLogo, LineMetaDataContent::Subway, Color{0x006633} }, // L5 OSM: 7732974 WD: Q9025969 -33.53, -70.76 x -33.44, -70.6
    { 1327, 21158, NoLogo, LineMetaDataContent::Subway, Color{0x8e16a1} }, // L6 OSM: 7732978 WD: Q5986809 -33.48, -70.7 x -33.42, -70.6
    { 60, 21183, 9428, LineMetaDataContent::Subway, Color{0x6e6e00} }, // 3 OSM: 7733214 WD: Q50741 48.86, 2.28 x 48.9, 2.418
    { 56, 21218, 21218, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 7733917 WD: Q2047989 55.74, 49.08 x 55.86, 49.22
    { 56, 5341, 21239, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 7733918 WD: Q594532 54.98, 82.89 x 55.06, 82.94
    { 16, 5722, 21239, LineMetaDataContent::Subway, Color{0x008000} }, // 2 OSM: 7733919 WD: Q2711371 55.03, 82.9 x 55.04, 82.98
    { 56, NoLogo, 21266, LineMetaDataContent::Subway, Color{0x1c8c3a} }, // 1 OSM: 7733920 WD: Q750441 56.8, 60.6 x 56.9, 60.63
    { 2997, 21285, NoLogo, LineMetaDataContent::Subway, Color{0x076c57} }, // Verde OSM: 7733971 WD: Q10318743 -15.84, -48.12 x -15.79, -47.88
    { 3003, 21304, NoLogo, LineMetaDataContent::Subway, Color{0xeb9710} }, // Laranja OSM: 7733972 WD: Q10318700 -15.87, -48.09 x -15.79, -47.88
    { 16, 21328, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // 2 OSM: 7734060 WD: Q25421356 18.48, -69.97 x 18.51, -69.86
    { 56, 21343, NoLogo, LineMetaDataContent::Subway, Color{0x0000ff} }, // 1 OSM: 7734061 WD: Q25421357 18.45, -69.93 x 18.55, -69.9
    { 56, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // 1 OSM: 7734069 10.62, -71.67 x 10.64, -71.62
    { 56, 21359, 21391, LineMetaDataContent::Subway, Color{0x0000ff} }, // 1 OSM: 7734077 WD: Q28604 53.84, 27.47 x 53.95, 27.69
    { 16, NoLogo, 21391, LineMetaDataContent::Subway, Color{0xff0000} }, // 2 OSM: 7734078 WD: Q2638932 53.86, 27.43 x 53.91, 27.67
    { 433, 21412, 21437, LineMetaDataContent::Subway, Color{0x0000ff} }, // M2 OSM: 7734092 WD: Q12295702 42.66, 23.28 x 42.74, 23.32
    { 352, 21458, 21437, LineMetaDataContent::Subway, Color{0xff0000} }, // M1 OSM: 7734093 WD: Q20020737 42.63, 23.26 x 42.73, 23.38
    { 3011, 21483, 21514, LineMetaDataContent::Subway, Color{0xdf096f} }, // Vermelha OSM: 7734163 WD: Q163215 38.73, -9.153 x 38.78, -9.099
    { 3020, 21544, 21514, LineMetaDataContent::Subway, Color{0xf4bc18} }, // Amarela OSM: 7734164 WD: Q1826607 38.72, -9.173 x 38.79, -9.145
    { 3028, NoLogo, 21514, LineMetaDataContent::Subway, Color{0x4e84c4} }, // Azul OSM: 7734165 WD: Q1826609 38.71, -9.224 x 38.76, -9.122
    { 2997, 21574, 21514, LineMetaDataContent::Subway, Color{0x00aaa6} }, // Verde OSM: 7734166 WD: Q1826613 38.71, -9.166 x 38.76, -9.133
    { 3033, 21602, 21602, LineMetaDataContent::Subway, Color{0xff6600} }, // Subway OSM: 7734173 WD: Q106328343 55.85, -4.312 x 55.88, -4.253
    { 56, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 7734180 WD: Q4504162 48.47, 34.93 x 48.48, 35.02
    { 680, 21621, 20105, LineMetaDataContent::Subway, Color{0x008000} }, // N OSM: 7734239 WD: Q1039166 33.55, 130.3 x 33.59, 130.4
    { 371, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xcc0000} }, // Red OSM: 7734262 WD: Q1369034 24.96, 55.13 x 25.27, 55.39
    { 639, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x00cc00} }, // Green OSM: 7734263 WD: Q1544621 25.22, 55.29 x 25.28, 55.4
    { 406, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xffc0cb} }, // S OSM: 7734268 WD: Q16240707 21.33, 39.87 x 21.42, 39.98
    { 56, 21648, 21673, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 7734272 WD: Q1473986 43.22, 76.84 x 43.27, 76.95
    { 16, 21695, 21695, LineMetaDataContent::Subway, Color{0x008000} }, // 2 OSM: 7734279 WD: Q712790 39.03, 125.7 x 39.07, 125.8
    { 56, 21695, 21695, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 7734280 WD: Q711112 39.01, 125.7 x 39.07, 125.8
    { 56, 21727, 20281, LineMetaDataContent::Subway, Color{0xff0f04} }, // 1 OSM: 7735256 WD: Q20110118 35.4, 50.98 x 35.8, 51.44
    { 6, 21751, 20281, LineMetaDataContent::RapidTransit, Color{0x008033} }, // 5 OSM: 7735262 WD: Q20110122 35.72, 50.72 x 35.96, 51.33
    { 56, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x259b24} }, // 1 OSM: 7740660 WD: Q19856263 26.5, 106.6 x 26.66, 106.7
    { 42, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe10886} }, // 7 OSM: 7741475 WD: Q122781783 45.72, 21.2 x 45.77, 21.23
    { 281, 21775, NoLogo, LineMetaDataContent::Tramway, Color{0x64318f} }, // T1 OSM: 7758458 WD: Q50319281 49.59, 6.119 x 49.64, 6.176
    { 60, 21795, 20281, LineMetaDataContent::Subway, Color{0x00aad4} }, // 3 OSM: 7770934 WD: Q20110120 35.63, 51.34 x 35.8, 51.52
    { 3040, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00afad} }, // B-L OSM: 7772561 51.46, -0.08835 x 51.51, -0.009527
    { 3044, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00afad} }, // B-WA OSM: 7772562 51.49, -0.08835 x 51.51, 0.07755
    { 3049, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00afad} }, // S-L OSM: 7772563 51.46, -0.02285 x 51.54, -0.004134
    { 3053, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00afad} }, // TG-B OSM: 7772565 51.51, -0.07453 x 51.51, 0.07189
    { 3058, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00afad} }, // SI-WA OSM: 7772566 51.49, -0.01335 x 51.55, 0.07755
    { 1231, 21819, 9561, LineMetaDataContent::Subway, Color{0xbc1725} }, // M3 OSM: 7772846 WD: Q2735258 44.41, 25.99 x 44.44, 26.21
    { 352, 21835, 9561, LineMetaDataContent::Subway, Color{0xffff00} }, // M1 OSM: 7772847 WD: Q2056949 44.41, 26.04 x 44.45, 26.2
    { 3064, 21851, NoLogo, LineMetaDataContent::LongDistanceTrain, Color{0xe43d2e} }, // IC 1 OSM: 7778963 WD: Q115929517 46.21, 6.099 x 47.51, 9.371
    { 3069, 21865, NoLogo, LineMetaDataContent::LongDistanceTrain, Color{0xf7941d} }, // IC 5 OSM: 7778977 WD: Q115932346 46.21, 6.099 x 47.51, 9.511
    { 3074, 21879, NoLogo, LineMetaDataContent::LongDistanceTrain, Color{0x8781bd} }, // IC 2 OSM: 7779154 WD: Q115932323 46, 8.496 x 47.38, 9.042
    { 3079, 21893, NoLogo, LineMetaDataContent::LongDistanceTrain, Color{0x00984a} }, // IC 3 OSM: 7779203 WD: Q115932338 46.85, 7.587 x 47.55, 9.562
    { 74, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xb56631} }, // 21 OSM: 7779520 WD: Q1432090 59.34, 18.1 x 59.36, 18.23
    { 507, 21907, 21937, LineMetaDataContent::Subway, Color{0x008000} }, // L1 OSM: 7781389 WD: Q2668472 37.33, -6.052 x 37.38, -5.934
    { 511, 21971, NoLogo, LineMetaDataContent::RapidTransit, Color{0x173ba0} }, // L2 OSM: 7781442 WD: Q5986162 36.68, -4.458 x 36.72, -4.43
    { 507, 21990, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe60000} }, // L1 OSM: 7781445 WD: Q5392889 36.71, -4.496 x 36.72, -4.423
    { 433, 22009, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe93324} }, // M2 OSM: 7781535 WD: Q11180785 39.58, 2.654 x 39.63, 2.725
    { 352, 22028, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf1b03e} }, // M1 OSM: 7781536 WD: Q5985887 39.58, 2.648 x 39.63, 2.673
    { 3084, 22047, NoLogo, LineMetaDataContent::LongDistanceTrain, Color{0xb01116} }, // IC 51 OSM: 7782231 WD: Q115932401 47.13, 7.239 x 47.55, 7.619
    { 3090, 22062, NoLogo, LineMetaDataContent::LongDistanceTrain, Color{0xffc80b} }, // IC 21 OSM: 7782364 WD: Q115932392 46, 7.587 x 47.55, 9.042
    { 3096, 22077, NoLogo, LineMetaDataContent::LongDistanceTrain, Color{0xaf8889} }, // IR 26 OSM: 7782601 WD: Q115987448 46.15, 7.586 x 47.55, 9.042
    { 3102, 22092, NoLogo, LineMetaDataContent::LongDistanceTrain, Color{0x5b6e25} }, // IR 27 OSM: 7782646 WD: Q115987465 47.04, 7.586 x 47.55, 8.311
    { 16, 22107, 22144, LineMetaDataContent::Subway, Color{0x008000} }, // 2 OSM: 7786077 WD: Q2210273 41.72, 44.72 x 41.73, 44.8
    { 56, 22167, 22144, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 7786078 WD: Q340562 41.69, 44.78 x 41.79, 44.87
    { 535, 22202, 22202, LineMetaDataContent::RapidTransit, Color{0xffff00} }, // E OSM: 7786518 WD: Q1714062 50.4, 30.39 x 50.5, 30.64
    { 16, 22232, 22252, LineMetaDataContent::Subway, Color{0xed1d24} }, // 2 OSM: 7786752 WD: Q3238802 50.62, 2.974 x 50.74, 3.181
    { 56, 22278, 22252, LineMetaDataContent::Subway, Color{0xffd400} }, // 1 OSM: 7786754 WD: Q3238658 50.61, 3.036 x 50.64, 3.143
    { 3108, 22298, NoLogo, LineMetaDataContent::LongDistanceTrain, Color{} }, // IR 75 OSM: 7787427 WD: Q116053272 47.04, 8.286 x 47.66, 9.192
    { 3114, 22313, NoLogo, LineMetaDataContent::LongDistanceTrain, Color{0x006d8b} }, // IR 46 OSM: 7787446 WD: Q116052876 46.15, 7.907 x 47.38, 9.042
    { 3120, 22328, NoLogo, LineMetaDataContent::LongDistanceTrain, Color{} }, // IR 70 OSM: 7787497 WD: Q116053265 47.04, 8.286 x 47.45, 8.593
    { 3126, 22343, NoLogo, LineMetaDataContent::LongDistanceTrain, Color{0x8dc63f} }, // IC 6 OSM: 7791233 WD: Q115932382 46.29, 7.434 x 47.55, 7.991
    { 3131, 22357, NoLogo, LineMetaDataContent::LongDistanceTrain, Color{0xef59a1} }, // IC 61 OSM: 7791339 WD: Q115932445 46.65, 7.434 x 47.55, 7.918
    { 2183, 22372, NoLogo, LineMetaDataContent::Subway, Color{0x90ee90} }, // 2B OSM: 7792472 WD: Q3832656 40.38, 49.85 x 40.38, 49.87
    { 56, 22372, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 7792473 WD: Q3832654 40.37, 49.83 x 40.42, 49.95
    { 16, 22372, NoLogo, LineMetaDataContent::Subway, Color{0x008000} }, // 2 OSM: 7792474 WD: Q3832656 40.37, 49.8 x 40.43, 49.95
    { 60, 22372, NoLogo, LineMetaDataContent::Subway, Color{0x800080} }, // 3 OSM: 7792475 WD: Q25547220 40.4, 49.78 x 40.43, 49.82
    { 56, 22393, 19551, LineMetaDataContent::Subway, Color{0x007448} }, // 1 OSM: 7792528 WD: Q200310 36.32, 127.3 x 36.39, 127.5
    { 3137, 22418, NoLogo, LineMetaDataContent::LongDistanceTrain, Color{0x11b895} }, // IR 15 OSM: 7793337 WD: Q115973525 46.21, 6.099 x 47.31, 8.311
    { 100, 22433, NoLogo, LineMetaDataContent::LongDistanceTrain, Color{0xb8da89} }, // IR37 OSM: 7793439 WD: Q116052863 47.35, 7.585 x 47.55, 8.539
    { 3143, 22448, NoLogo, LineMetaDataContent::LocalTrain, Color{0x009bd5} }, // RB 43 OSM: 7793791 WD: Q84429153 51.58, 13.24 x 52.34, 14.73
    { 3149, 22468, NoLogo, LineMetaDataContent::LongDistanceTrain, Color{0xa07032} }, // IR 16 OSM: 7794142 WD: Q115987375 46.95, 7.434 x 47.49, 8.539
    { 3155, 22483, NoLogo, LineMetaDataContent::LongDistanceTrain, Color{0xad227a} }, // IR 36 OSM: 7794220 WD: Q116052855 47.38, 7.585 x 47.57, 8.566
    { 3161, 22498, NoLogo, LineMetaDataContent::LongDistanceTrain, Color{0x25539c} }, // IR 17 OSM: 7795137 WD: Q115987430 46.95, 7.433 x 47.35, 7.908
    { 3167, 22513, NoLogo, LineMetaDataContent::LongDistanceTrain, Color{0x007ca3} }, // IR 90 OSM: 7796313 WD: Q115973464 46.11, 6.099 x 46.54, 7.988
    { 1856, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0xf58220} }, // S19 OSM: 7800298 WD: Q25352054 47.37, 8.227 x 47.6, 8.787
    { 26, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xa75f4a} }, // 16 OSM: 7801277 WD: Q123363026 56.81, 60.56 x 56.86, 60.65
    { 3173, 22528, 226, LineMetaDataContent::RapidTransit, Color{0xf17f1a} }, // S 9 OSM: 7805411 WD: Q63217750 51.45, 11.98 x 51.52, 12.64
    { 3177, 22553, NoLogo, LineMetaDataContent::LocalTrain, Color{0xda6ba2} }, // RB24 OSM: 7814259 WD: Q67993390 51.53, 13.4 x 52.84, 14.06
    { 63, NoLogo, 22573, LineMetaDataContent::RapidTransit, Color{0xf39100} }, // S1 OSM: 7819263 WD: Q110265543 46.52, 6.517 x 46.81, 6.654
    { 503, 22589, 22612, LineMetaDataContent::Subway, Color{0x824100} }, // L4 OSM: 7827780 WD: Q1826677 40.42, -3.716 x 40.48, -3.635
    { 507, 22632, 22612, LineMetaDataContent::Subway, Color{0x67c0dd} }, // L1 OSM: 7831481 WD: Q1826675 40.36, -3.706 x 40.48, -3.591
    { 16, 22655, 20281, LineMetaDataContent::Subway, Color{0x003380} }, // 2 OSM: 7832325 WD: Q20110119 35.69, 51.33 x 35.74, 51.55
    { 3183, 22679, 22612, LineMetaDataContent::Subway, Color{0x015396} }, // L10 OSM: 7834660 WD: Q1760090 40.34, -3.813 x 40.56, -3.611
    { 654, NoLogo, 22703, LineMetaDataContent::Subway, Color{0x7fffd4} }, // I OSM: 7834960 WD: Q106775989 9.95, 76.28 x 10.11, 76.35
    { 1335, 22724, 22612, LineMetaDataContent::Subway, Color{0xff0080} }, // L8 OSM: 7837169 WD: Q1475527 40.44, -3.692 x 40.49, -3.572
    { 3188, 22747, 22612, LineMetaDataContent::Subway, Color{0x9c3293} }, // L9 OSM: 7837206 WD: Q1759707 40.3, -3.721 x 40.5, -3.447
    { 3193, 22770, 4032, LineMetaDataContent::Subway, Color{0x996633} }, // Z OSM: 7837591 WD: Q3239257 40.68, -74.01 x 40.72, -73.8
    { 1323, 22796, 22612, LineMetaDataContent::Subway, Color{0x96bf0d} }, // L5 OSM: 7838614 WD: Q1568028 40.38, -3.769 x 40.46, -3.588
    { 352, 22819, 22819, LineMetaDataContent::Subway, Color{0xffa500} }, // M1 OSM: 7838818 WD: Q1577356 36.98, 35.26 x 37.05, 35.34
    { 515, 22840, 22612, LineMetaDataContent::Subway, Color{0xffdf00} }, // L3 OSM: 7838838 WD: Q1826673 40.34, -3.72 x 40.44, -3.692
    { 511, 22863, 22612, LineMetaDataContent::Subway, Color{0xfb0f0c} }, // L2 OSM: 7838963 WD: Q1826679 40.42, -3.71 x 40.45, -3.602
    { 1331, 22886, 22612, LineMetaDataContent::Subway, Color{0xed7b24} }, // L7 OSM: 7840623 WD: Q1826683 40.42, -3.727 x 40.5, -3.524
    { 584, 22909, 22612, LineMetaDataContent::Subway, Color{0xffffff} }, // R OSM: 7840747 WD: Q1496137 40.42, -3.72 x 40.42, -3.71
    { 1570, NoLogo, 22931, LineMetaDataContent::Subway, Color{0xe542de} }, // Purple OSM: 7841332 WD: Q7261433 12.9, 77.46 x 13, 77.76
    { 480, 22947, 22612, LineMetaDataContent::Subway, Color{0xa49a00} }, // L12 OSM: 7841412 WD: Q1558864 40.28, -3.876 x 40.35, -3.71
    { 56, 22971, NoLogo, LineMetaDataContent::Subway, Color{0xf03b3f} }, // 1 OSM: 7841834 WD: Q11085985 31.44, 120.3 x 31.68, 120.3
    { 16, 22996, NoLogo, LineMetaDataContent::Subway, Color{0x00a43c} }, // 2 OSM: 7841837 WD: Q11085986 31.55, 120.2 x 31.61, 120.5
    { 56, NoLogo, 23021, LineMetaDataContent::Subway, Color{0xe53e30} }, // 1 OSM: 7841839 WD: Q30326155 38.04, 114.4 x 38.16, 114.6
    { 60, NoLogo, 23021, LineMetaDataContent::Subway, Color{0x00a1e0} }, // 3 OSM: 7841854 WD: Q30326157 38, 114.4 x 38.08, 114.7
    { 56, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x00b04f} }, // 1 OSM: 7841881 WD: Q17498765 22.82, 108.2 x 22.84, 108.4
    { 1327, 23044, 22612, LineMetaDataContent::Subway, Color{0x939393} }, // L6 OSM: 7842094 WD: Q514227 40.39, -3.746 x 40.45, -3.668
    { 485, 23067, 22612, LineMetaDataContent::Subway, Color{0x006400} }, // L11 OSM: 7842127 WD: Q608251 40.36, -3.778 x 40.39, -3.718
    { 639, NoLogo, 22931, LineMetaDataContent::Subway, Color{0x009933} }, // Green OSM: 7842288 WD: Q17054000 12.86, 77.5 x 13.05, 77.58
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xaf272f} }, // 2 OSM: 7844345 WD: Q11149384 36.06, 120.3 x 36.17, 120.5
    { 16, NoLogo, 23091, LineMetaDataContent::Subway, Color{0x53b848} }, // 2 OSM: 7845614 WD: Q20647027 12.99, 80.19 x 13.09, 80.27
    { 231, 23114, NoLogo, LineMetaDataContent::Subway, Color{0xc09c83} }, // 17 OSM: 7845847 WD: Q6553108 31.1, 121 x 31.2, 121.3
    { 16, 23135, 19551, LineMetaDataContent::Subway, Color{0x18be00} }, // 2 OSM: 7845969 WD: Q200332 35.83, 128.4 x 35.87, 128.8
    { 56, 23158, 19551, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 7845971 WD: Q200331 35.8, 128.5 x 35.89, 128.7
    { 16, 23181, NoLogo, LineMetaDataContent::Subway, Color{0xfff100} }, // 2 OSM: 7846276 WD: Q15908164 34.66, 113.6 x 34.87, 113.7
    { 3195, 23200, 23224, LineMetaDataContent::RapidTransit, Color{0x4682b4} }, // ML1 OSM: 7849381 WD: Q2058921 40.48, -3.669 x 40.51, -3.651
    { 3199, 23250, 23224, LineMetaDataContent::RapidTransit, Color{0x660066} }, // ML2 OSM: 7853073 WD: Q3832710 40.4, -3.812 x 40.45, -3.775
    { 3203, 23274, 23224, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // ML3 OSM: 7853483 WD: Q3832709 40.39, -3.905 x 40.41, -3.775
    { 3207, 23298, 19551, LineMetaDataContent::Subway, Color{0x6fa0ce} }, // I1 OSM: 7854149 WD: Q487733 37.38, 126.6 x 37.57, 126.7
    { 60, 23323, NoLogo, LineMetaDataContent::Tramway, Color{0xb5ba05} }, // 3 OSM: 7857250 WD: Q1888831 50.81, 4.336 x 50.9, 4.377
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x02406f} }, // 2 OSM: 7857258 WD: Q10318650 -12.98, -38.48 x -12.9, -38.34
    { 3210, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x61bf1a} }, // RL2 OSM: 7867506 WD: Q3781389 41.62, 0.631 x 42.24, 0.9662
    { 3214, 23344, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa6c82b} }, // R2Nord OSM: 7867878 WD: Q114215296 41.3, 2.052 x 41.77, 2.673
    { 3221, 23362, NoLogo, LineMetaDataContent::RapidTransit, Color{0xba55d3} }, // R7 OSM: 7867903 WD: Q1647981 41.43, 2.115 x 41.51, 2.189
    { 3224, 23379, 23406, LineMetaDataContent::Subway, Color{0xff0000} }, // B1 OSM: 7868621 WD: Q56067295 40.19, 28.95 x 40.27, 29.12
    { 16, 23424, NoLogo, LineMetaDataContent::Subway, Color{0xef3340} }, // 2 OSM: 7869228 WD: Q5934457 34.11, 108.9 x 34.4, 109
    { 56, 23444, NoLogo, LineMetaDataContent::Subway, Color{0x0077c8} }, // 1 OSM: 7869253 WD: Q14917524 34.27, 108.7 x 34.34, 109.1
    { 60, 23464, NoLogo, LineMetaDataContent::Subway, Color{0xb688a9} }, // 3 OSM: 7869255 WD: Q15927288 34.22, 108.8 x 34.4, 109.1
    { 16, 23484, NoLogo, LineMetaDataContent::Subway, Color{0xd9001c} }, // 2 OSM: 7869334 WD: Q16282623 -8.111, -35.02 x -8.069, -34.89
    { 56, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xe77405} }, // 1 OSM: 7869352 WD: Q104231463 -8.092, -35 x -8.024, -34.89
    { 2376, 23500, NoLogo, LineMetaDataContent::Subway, Color{0x1a5ba3} }, // Sul OSM: 7869374 WD: Q10329288 -8.168, -34.93 x -8.069, -34.88
    { 3227, 23513, 23406, LineMetaDataContent::Subway, Color{0x000000} }, // B2 OSM: 7869622 WD: Q61074931 40.19, 28.87 x 40.22, 29.21
    { 56, 23540, NoLogo, LineMetaDataContent::Subway, Color{0xe60012} }, // 1 OSM: 7871046 WD: Q15303225 34.75, 113.5 x 34.83, 113.8
    { 138, 23559, NoLogo, LineMetaDataContent::Subway, Color{0xa2ae73} }, // 9 OSM: 7871541 WD: Q28441548 34.49, 113.7 x 34.66, 113.9
    { 3230, 23579, 3582, LineMetaDataContent::RapidTransit, Color{0x8fbe00} }, // C-10 OSM: 7871793 WD: Q583732 40.4, -4.009 x 40.63, -3.594
    { 649, 23598, 3582, LineMetaDataContent::RapidTransit, Color{0x009ad5} }, // C-1 OSM: 7871905 WD: Q3832674 40.4, -3.722 x 40.49, -3.593
    { 3235, 23616, 3582, LineMetaDataContent::RapidTransit, Color{0xde0118} }, // C-7 OSM: 7872150 WD: Q8879938 40.38, -3.874 x 40.51, -3.365
    { 371, 23634, NoLogo, LineMetaDataContent::Subway, Color{0xda291c} }, // Red OSM: 7874288 WD: Q152039 42.21, -71.14 x 42.4, -71
    { 1422, 23660, NoLogo, LineMetaDataContent::Subway, Color{0xed8b00} }, // Orange OSM: 7874312 WD: Q152029 42.3, -71.11 x 42.44, -71.06
    { 16, 23689, NoLogo, LineMetaDataContent::Subway, Color{0x00afec} }, // 2 OSM: 7875250 WD: Q15919822 28.15, 112.9 x 28.21, 113.1
    { 56, 23719, NoLogo, LineMetaDataContent::Subway, Color{0xe60012} }, // 1 OSM: 7875257 WD: Q15911087 28.06, 113 x 28.27, 113
    { 9, 23749, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7d4697} }, // 4 OSM: 7875301 WD: Q6553125 43.75, 125.3 x 43.91, 125.4
    { 60, 23770, NoLogo, LineMetaDataContent::RapidTransit, Color{0x009943} }, // 3 OSM: 7875360 WD: Q6123656 43.77, 125.3 x 43.91, 125.4
    { 687, 23791, 23808, LineMetaDataContent::Subway, Color{0x056d2e} }, // A OSM: 7877753 WD: Q770771 39.92, 32.81 x 39.93, 32.88
    { 352, NoLogo, 23808, LineMetaDataContent::Subway, Color{0xbf0e1c} }, // M1 OSM: 7877773 WD: Q21526526 39.92, 32.73 x 39.97, 32.86
    { 433, NoLogo, 23808, LineMetaDataContent::Subway, Color{0xbf0e1c} }, // M2 OSM: 7877891 WD: Q21526527 39.88, 32.68 x 39.92, 32.86
    { 178, 23830, NoLogo, LineMetaDataContent::Subway, Color{0xffa500} }, // O OSM: 7879290 WD: Q7099668 22.62, 120.3 x 22.63, 120.4
    { 584, 23870, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // R OSM: 7879291 WD: Q7304504 22.56, 120.3 x 22.78, 120.4
    { 60, 23907, 19551, LineMetaDataContent::Subway, Color{0xfe5b10} }, // 3 OSM: 7879839 WD: Q20393 37.48, 126.7 x 37.68, 127.1
    { 6, 23930, 19551, LineMetaDataContent::Subway, Color{0x996cac} }, // 5 OSM: 7879871 WD: Q92530 37.49, 126.8 x 37.58, 127.2
    { 60, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x006dbb} }, // 3 OSM: 7883242 WD: Q15907883 36.05, 120.3 x 36.17, 120.4
    { 138, 23953, 19551, LineMetaDataContent::Subway, Color{0xaa9872} }, // 9 OSM: 7883317 WD: Q17503 37.5, 126.8 x 37.58, 127.1
    { 16, 23976, NoLogo, LineMetaDataContent::Subway, Color{0xd60e19} }, // 2 OSM: 7883944 WD: Q10946021 29.81, 121.5 x 29.95, 121.7
    { 56, 23997, 2701, LineMetaDataContent::Subway, Color{0xffff00} }, // 1 OSM: 7884489 WD: Q54369 43.65, -79.53 x 43.79, -79.38
    { 56, 24046, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 7885089 WD: Q56277837 40.59, 22.93 x 40.65, 22.97
    { 16, 24076, 2701, LineMetaDataContent::Subway, Color{0x008000} }, // 2 OSM: 7885287 WD: Q54371 43.64, -79.54 x 43.73, -79.26
    { 60, 24115, 12277, LineMetaDataContent::Subway, Color{0x009651} }, // 3 OSM: 7885547 WD: Q10906683 31.87, 118.7 x 32.17, 118.8
    { 3239, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x77278b} }, // WCE OSM: 7887557 49.13, -123.1 x 49.29, -122.3
    { 3243, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x000000} }, // Conexão Metrô-Aeroporto OSM: 7889062 WD: Q23891467 -29.99, -51.18 x -29.99, -51.18
    { 56, 24135, NoLogo, LineMetaDataContent::Subway, Color{0x5cb439} }, // 1 OSM: 7889178 WD: Q45668 31.28, 120.5 x 31.33, 120.8
    { 3269, 24156, 24170, LineMetaDataContent::Subway, Color{0x808080} }, // RMGL OSM: 7890003 WD: Q7294170 28.42, 77.09 x 28.5, 77.11
    { 56, 24191, NoLogo, LineMetaDataContent::Subway, Color{0xfec04f} }, // 1 OSM: 7890223 WD: Q5985916 25.68, -100.4 x 25.76, -100.2
    { 16, 24205, NoLogo, LineMetaDataContent::Subway, Color{0x6bc069} }, // 2 OSM: 7890224 WD: Q2842186 25.67, -100.3 x 25.77, -100.3
    { 16, 24219, NoLogo, LineMetaDataContent::Subway, Color{0x0066a1} }, // 2 OSM: 7890240 WD: Q6379343 38.9, 121.5 x 39.02, 121.7
    { 406, 4075, 4032, LineMetaDataContent::Subway, Color{0x808183} }, // S OSM: 7893704 WD: Q126772 40.58, -73.84 x 40.61, -73.81
    { 406, 24239, 4032, LineMetaDataContent::Subway, Color{0x808183} }, // S OSM: 7894362 WD: Q126725 40.66, -73.96 x 40.68, -73.96
    { 56, 24266, NoLogo, LineMetaDataContent::Subway, Color{0xb63f1f} }, // 1 OSM: 7894481 WD: Q5934658 41.76, 123.2 x 41.81, 123.5
    { 16, 24297, NoLogo, LineMetaDataContent::Subway, Color{0xe5703a} }, // 2 OSM: 7894597 WD: Q5933526 41.62, 123.4 x 41.96, 123.5
    { 56, 24328, NoLogo, LineMetaDataContent::Subway, Color{0xeb212f} }, // 1 OSM: 7895188 WD: Q15941872 25.98, 119.3 x 26.15, 119.4
    { 59, 24347, NoLogo, LineMetaDataContent::Subway, Color{0x8e8c13} }, // 13 OSM: 7895357 WD: Q6553065 23.08, 113.4 x 23.14, 113.6
    { 16, 24368, NoLogo, LineMetaDataContent::Subway, Color{0x0070ff} }, // 2 OSM: 7898299 WD: Q56277844 40.57, 22.93 x 40.65, 22.97
    { 3274, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xee1d23} }, // 512 OSM: 7904557 WD: Q3238950 43.67, -79.47 x 43.69, -79.39
    { 60, 24398, NoLogo, LineMetaDataContent::Subway, Color{0xdd00bb} }, // 3 OSM: 7908058 WD: Q5976456 38.92, 121.6 x 39.15, 122
    { 16, 24418, NoLogo, LineMetaDataContent::Subway, Color{0x0000ff} }, // 2 OSM: 7909740 WD: Q11087464 25.03, 102.7 x 25.12, 102.8
    { 56, 24438, NoLogo, LineMetaDataContent::Subway, Color{0xdb372b} }, // 1 OSM: 7909748 WD: Q11087462 24.83, 102.7 x 25.03, 102.9
    { 63, 24458, 12277, LineMetaDataContent::Subway, Color{0x4bbbb4} }, // S1 OSM: 7913272 WD: Q10946118 31.72, 118.8 x 31.97, 118.9
    { 217, 24479, 12277, LineMetaDataContent::Subway, Color{0xba84ac} }, // S3 OSM: 7913273 WD: Q10945835 31.91, 118.5 x 31.99, 118.8
    { 56, 24500, NoLogo, LineMetaDataContent::Subway, Color{0x00ab39} }, // 1 OSM: 7913936 WD: Q842103 22.53, 113.8 x 22.65, 114.1
    { 687, 24523, 19551, LineMetaDataContent::Subway, Color{0x3681b7} }, // A OSM: 7919001 WD: Q487643 37.44, 126.4 x 37.6, 127
    { 19, 24549, 19551, LineMetaDataContent::Subway, Color{0xea545d} }, // 8 OSM: 7919019 WD: Q45086 37.43, 127.1 x 37.55, 127.2
    { 27, 24572, 19551, LineMetaDataContent::Subway, Color{0x9e4510} }, // 6 OSM: 7919154 WD: Q92549 37.53, 126.9 x 37.62, 127.1
    { 410, NoLogo, 24595, LineMetaDataContent::Subway, Color{0x00a651} }, // M OSM: 7919553 WD: Q106336770 39.29, -76.78 x 39.41, -76.59
    { 3279, 24650, 19703, LineMetaDataContent::Subway, Color{0xe89038} }, // OR OSM: 7919601 WD: Q4715683 38.88, -77.27 x 38.95, -76.87
    { 3286, 24667, 19703, LineMetaDataContent::Subway, Color{0xe94333} }, // RD OSM: 7919630 WD: Q2193330 38.89, -77.17 x 39.12, -76.99
    { 3289, 24681, 19703, LineMetaDataContent::Subway, Color{0xc0c0c0} }, // SV OSM: 7919737 WD: Q4711838 38.88, -77.49 x 39.01, -76.84
    { 3292, 24698, 19703, LineMetaDataContent::Subway, Color{0x0000ff} }, // BL OSM: 7919758 WD: Q2602185 38.77, -77.17 x 38.9, -76.84
    { 3295, 24713, 19703, LineMetaDataContent::Subway, Color{0x008000} }, // GR OSM: 7919786 WD: Q4715207 38.83, -77.03 x 39.01, -76.91
    { 42, 24729, 19551, LineMetaDataContent::Subway, Color{0x54640d} }, // 7 OSM: 7922930 WD: Q22910 37.48, 126.7 x 37.7, 127.1
    { 639, NoLogo, 24752, LineMetaDataContent::Subway, Color{0x62bb46} }, // Green OSM: 7924527 WD: Q55734262 25.68, -80.32 x 25.85, -80.2
    { 1422, NoLogo, 24752, LineMetaDataContent::Subway, Color{0xf78f1e} }, // Orange OSM: 7924528 WD: Q55734269 25.68, -80.31 x 25.81, -80.2
    { 275, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009933} }, // D OSM: 7925628 WD: Q3239098 48.57, 7.692 x 48.59, 7.816
    { 403, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf29400} }, // C OSM: 7925656 WD: Q2321331 48.55, 7.735 x 48.59, 7.773
    { 27, 24791, 18162, LineMetaDataContent::Subway, Color{0x0066a3} }, // 6 OSM: 7927182 WD: Q668977 50.83, 4.321 x 50.9, 4.37
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff7000} }, // 2 OSM: 7927236 WD: Q5017773 29.98, 31.2 x 30.12, 31.25
    { 511, 24812, 24833, LineMetaDataContent::Subway, Color{0x00dc3c} }, // L2 OSM: 7927568 WD: Q5986160 10.43, -67.01 x 10.51, -66.92
    { 515, 24852, 24833, LineMetaDataContent::Subway, Color{0x0887ff} }, // L3 OSM: 7927573 WD: Q21346332 10.43, -66.94 x 10.5, -66.88
    { 3298, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // L1B OSM: 7928119 WD: Q107191177 37.99, -1.187 x 38.01, -1.161
    { 56, 24873, NoLogo, LineMetaDataContent::Subway, Color{0xf04e98} }, // 1 OSM: 7935038 WD: Q2295084 19.4, -99.2 x 19.43, -99.07
    { 403, 24894, NoLogo, LineMetaDataContent::RapidTransit, Color{0x58a738} }, // C OSM: 7935053 WD: Q2482571 33.89, -118.4 x 33.93, -118.1
    { 275, 24919, NoLogo, LineMetaDataContent::Subway, Color{0xa05da5} }, // D OSM: 7935318 WD: Q3916689 34.05, -118.3 x 34.06, -118.2
    { 9, 24944, NoLogo, LineMetaDataContent::Subway, Color{0x80ffff} }, // 4 OSM: 7935352 WD: Q2837181 19.4, -99.12 x 19.49, -99.1
    { 6, 24965, NoLogo, LineMetaDataContent::Subway, Color{0xffff11} }, // 5 OSM: 7935366 WD: Q1152238 19.41, -99.15 x 19.5, -99.07
    { 15, 24986, NoLogo, LineMetaDataContent::Subway, Color{0xb69764} }, // 12 OSM: 7935368 WD: Q5985548 19.29, -99.2 x 19.38, -99.01
    { 42, 25008, NoLogo, LineMetaDataContent::Subway, Color{0xff8000} }, // 7 OSM: 7935375 WD: Q929645 19.36, -99.2 x 19.51, -99.19
    { 687, 25029, NoLogo, LineMetaDataContent::Subway, Color{0xa3277d} }, // A OSM: 7935382 WD: Q3239049 19.35, -99.07 x 19.42, -98.96
    { 19, 25050, NoLogo, LineMetaDataContent::Subway, Color{0x30c090} }, // 8 OSM: 7935426 WD: Q1149545 19.35, -99.14 x 19.45, -99.06
    { 271, 25071, NoLogo, LineMetaDataContent::Subway, Color{0x408080} }, // B OSM: 7935433 WD: Q3239062 19.43, -99.16 x 19.53, -99.03
    { 16, 25092, NoLogo, LineMetaDataContent::Subway, Color{0x0080ff} }, // 2 OSM: 7935439 WD: Q1152993 19.34, -99.22 x 19.46, -99.13
    { 138, 25113, NoLogo, LineMetaDataContent::Subway, Color{0x804000} }, // 9 OSM: 7935444 WD: Q3239046 19.4, -99.19 x 19.42, -99.06
    { 60, 25134, NoLogo, LineMetaDataContent::Subway, Color{0xae9d27} }, // 3 OSM: 7935449 WD: Q945935 19.32, -99.18 x 19.5, -99.12
    { 27, 25155, NoLogo, LineMetaDataContent::Subway, Color{0xe00050} }, // 6 OSM: 7935454 WD: Q3238990 19.48, -99.2 x 19.51, -99.1
    { 3302, 25176, NoLogo, LineMetaDataContent::Subway, Color{0xdb5450} }, // PATCO OSM: 7939445 WD: Q2043730 39.83, -75.17 x 39.96, -75
    { 2149, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x233e99} }, // WTR OSM: 7940934 WD: Q7986701 39.95, -75.18 x 40.26, -74.82
    { 2750, NoLogo, 25191, LineMetaDataContent::Subway, Color{0xef3941} }, // NWK–WTC OSM: 7943869 WD: Q2673356 40.71, -74.16 x 40.74, -74.01
    { 3308, 25200, 25191, LineMetaDataContent::Subway, Color{0x009e58} }, // HOB–WTC OSM: 7943874 WD: Q2789573 40.71, -74.04 x 40.74, -74.01
    { 3318, NoLogo, 25191, LineMetaDataContent::Subway, Color{0x0082c6} }, // HOB–33 OSM: 7943885 WD: Q2319374 40.73, -74.03 x 40.75, -73.99
    { 3327, NoLogo, 25191, LineMetaDataContent::Subway, Color{0xfdb827} }, // JSQ–33 OSM: 7943962 WD: Q4993433 40.72, -74.06 x 40.75, -73.99
    { 56, 25214, NoLogo, LineMetaDataContent::Subway, Color{0xe77405} }, // 1 OSM: 7944061 WD: Q2333617 -22.98, -43.24 x -22.9, -43.17
    { 56, 25238, NoLogo, LineMetaDataContent::Subway, Color{0xc8102e} }, // 1 OSM: 7948593 WD: Q10921992 45.6, 126.6 x 45.79, 126.7
    { 60, 25262, NoLogo, LineMetaDataContent::Subway, Color{0xffc72c} }, // 3 OSM: 7949019 WD: Q10921994 45.69, 126.5 x 45.79, 126.7
    { 56, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xf50000} }, // 1 OSM: 7949047 WD: Q10916959 31.69, 117.3 x 31.92, 117.3
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x006bfa} }, // 2 OSM: 7949335 WD: Q10916960 31.82, 117.1 x 31.88, 117.5
    { 56, 25286, NoLogo, LineMetaDataContent::Subway, Color{0xe50011} }, // 1 OSM: 7949339 WD: Q15913092 43.79, 125.3 x 43.95, 125.3
    { 3336, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xf58220} }, // BSL OSM: 7950670 WD: Q837022 39.91, -75.17 x 40.04, -75.14
    { 56, 25306, NoLogo, LineMetaDataContent::Subway, Color{0x42b227} }, // 1 OSM: 7951024 WD: Q6379309 38.84, 121.5 x 39.02, 121.6
    { 3340, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0066ff} }, // MFL OSM: 7953598 WD: Q823251 39.95, -75.26 x 40.02, -75.08
    { 3344, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x84388a} }, // NHSL OSM: 7953621 WD: Q2205806 39.96, -75.35 x 40.11, -75.26
    { 15, 25326, NoLogo, LineMetaDataContent::Subway, Color{0x523e98} }, // 12 OSM: 7957874 WD: Q10938157 38.8, 121.1 x 38.86, 121.5
    { 3349, 25347, 9014, LineMetaDataContent::Subway, Color{0x007a33} }, // Μ1 OSM: 7963514 WD: Q6553095 37.94, 23.64 x 38.07, 23.81
    { 3353, 25371, 9014, LineMetaDataContent::Subway, Color{0xda291c} }, // Μ2 OSM: 7963569 WD: Q9295813 37.89, 23.69 x 38.02, 23.75
    { 56, NoLogo, 25395, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 7963913 WD: Q10318696 40.14, 44.47 x 40.2, 44.52
    { 19, 25413, NoLogo, LineMetaDataContent::Subway, Color{0x9dabaa} }, // 8 OSM: 7964884 WD: Q11124525 30.43, 114.3 x 30.68, 114.4
    { 3357, 25433, 23224, LineMetaDataContent::Tramway, Color{0x98cd37} }, // ML4 OSM: 7968999 WD: Q1637556 40.22, -3.773 x 40.25, -3.749
    { 3361, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x006400} }, // Tranvía OSM: 7981323 WD: Q926857 37.77, -3.79 x 37.81, -3.778
    { 3370, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0354a6} }, // DTL OSM: 7981644 WD: Q1663943 1.278, 103.7 x 1.413, 104
    { 3374, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x9016b2} }, // NEL OSM: 7981649 WD: Q1725116 1.265, 103.8 x 1.415, 103.9
    { 2716, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff9a00} }, // CCL OSM: 7981685 WD: Q2154003 1.265, 103.8 x 1.353, 103.9
    { 3378, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x009530} }, // EWL OSM: 7981689 WD: Q1895425 1.276, 103.6 x 1.376, 104
    { 1231, 25457, 23808, LineMetaDataContent::Subway, Color{0xbf0e1c} }, // M3 OSM: 7981707 WD: Q21526528 39.97, 32.55 x 39.99, 32.73
    { 8, 25491, 23808, LineMetaDataContent::Subway, Color{0xedaf2e} }, // M4 OSM: 7981756 WD: Q31193144 39.92, 32.84 x 40, 32.88
    { 352, 25525, 25551, LineMetaDataContent::Subway, Color{0x0000ff} }, // M1 OSM: 7981873 WD: Q3238655 38.39, 26.99 x 38.47, 27.23
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xed1c24} }, // 2 OSM: 7986215 WD: Q11103955 22.86, 113.7 x 23.09, 113.9
    { 3382, 25573, 25595, LineMetaDataContent::Subway, Color{0xff748c} }, // Pink Line OSM: 7989308 WD: Q17053988 26.88, 75.75 x 26.93, 75.83
    { 3392, 25617, NoLogo, LineMetaDataContent::Subway, Color{0x246b5b} }, // BTS Silom OSM: 7989387 WD: Q2634702 13.71, 100.5 x 13.75, 100.5
    { 3402, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf9c212} }, // U AVO OSM: 7993108 WD: Q25430027 40.64, -8.654 x 41.15, -8.564
    { 9, 25630, NoLogo, LineMetaDataContent::Tramway, Color{0xf25482} }, // 4 OSM: 7999217 WD: Q2527775 50.79, 4.318 x 50.86, 4.363
    { 322, 25651, 8171, LineMetaDataContent::Tramway, Color{0xa12944} }, // 25 OSM: 7999338 WD: Q3238750 50.8, 4.358 x 50.87, 4.408
    { 667, 25673, 8171, LineMetaDataContent::Tramway, Color{0xf3c300} }, // 55 OSM: 7999374 WD: Q2236365 50.86, 4.358 x 50.88, 4.416
    { 786, 25695, 8171, LineMetaDataContent::Tramway, Color{0x91bee7} }, // 82 OSM: 7999733 WD: Q2534011 50.78, 4.29 x 50.87, 4.341
    { 60, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffcc00} }, // 3 OSM: 8000255 WD: Q13422345 14.54, 121 x 14.65, 121.1
    { 56, 25717, 25717, LineMetaDataContent::RapidTransit, Color{0x008000} }, // 1 OSM: 8000262 WD: Q4165607 14.53, 121 x 14.66, 121
    { 16, NoLogo, 25717, LineMetaDataContent::Subway, Color{0x800080} }, // 2 OSM: 8000265 WD: Q4165317 14.6, 121 x 14.63, 121.1
    { 3408, 25730, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfe8e10} }, // AG OSM: 8000298 WD: Q113297999 3.12, 101.7 x 3.186, 101.8
    { 138, 25751, NoLogo, LineMetaDataContent::Subway, Color{0x008000} }, // 9 OSM: 8000326 WD: Q6717618 2.982, 101.6 x 3.177, 101.8
    { 3411, 25772, NoLogo, LineMetaDataContent::RapidTransit, Color{0x721422} }, // SP OSM: 8000405 WD: Q113297920 2.994, 101.6 x 3.186, 101.7
    { 325, 25793, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe0115f} }, // KJ OSM: 8000461 WD: Q248445 2.996, 101.6 x 3.231, 101.7
    { 39, 25814, 25838, LineMetaDataContent::Subway, Color{0xff8c00} }, // T OSM: 8000572 WD: Q981826 43.03, 141.3 x 43.09, 141.5
    { 680, 25850, 25838, LineMetaDataContent::Subway, Color{0x008800} }, // N OSM: 8000575 WD: Q843793 42.99, 141.3 x 43.11, 141.4
    { 2206, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0377ae} }, // R6 OSM: 8005936 48.62, 21.19 x 48.71, 21.24
    { 3414, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x3a88bf} }, // 941 OSM: 8009538 WD: Q115756382 46.7, 9.386 x 46.98, 9.689
    { 60, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x55bace} }, // 3 OSM: 8013591 WD: Q3238909 48.68, 21.26 x 48.72, 21.3
    { 42, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x5cbf14} }, // 7 OSM: 8013592 WD: Q3239017 48.68, 21.24 x 48.73, 21.27
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x7477b0} }, // 4 OSM: 8013593 WD: Q3238941 48.68, 21.24 x 48.74, 21.27
    { 138, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf5d907} }, // 9 OSM: 8013594 WD: Q3239047 48.68, 21.23 x 48.74, 21.3
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xd2005c} }, // 2 OSM: 8013595 WD: Q3238807 48.72, 21.24 x 48.74, 21.27
    { 410, 25876, 25916, LineMetaDataContent::Subway, Color{0xf62e36} }, // M OSM: 8015940 WD: Q1147028 35.67, 139.6 x 35.73, 139.8
    { 687, 25944, NoLogo, LineMetaDataContent::Subway, Color{0xe85298} }, // A OSM: 8019854 WD: Q720653 35.58, 139.7 x 35.71, 139.8
    { 406, 25973, NoLogo, LineMetaDataContent::Subway, Color{0x6cbb5a} }, // S OSM: 8019866 WD: Q1374502 35.65, 139.4 x 35.8, 139.9
    { 535, 26003, NoLogo, LineMetaDataContent::Subway, Color{0xb6007a} }, // E OSM: 8019893 WD: Q384862 35.65, 139.6 x 35.76, 139.8
    { 654, 26029, NoLogo, LineMetaDataContent::Subway, Color{0x0079c2} }, // I OSM: 8019914 WD: Q1374506 35.63, 139.6 x 35.79, 139.8
    { 3418, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xaacd46} }, // G44 OSM: 8021111 WD: Q101110571 47.37, 18.87 x 47.5, 19.04
    { 3422, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00aff0} }, // S506 OSM: 8021112 WD: Q111752752 47.19, 21.58 x 47.52, 21.82
    { 3427, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xaacd46} }, // G50 OSM: 8021114 WD: Q109333265 47.17, 19.06 x 47.52, 20.18
    { 403, 26055, 25916, LineMetaDataContent::Subway, Color{0x00bb85} }, // C OSM: 8026069 WD: Q1075089 35.66, 139.7 x 35.78, 139.8
    { 680, 26092, 25916, LineMetaDataContent::Subway, Color{0x00ac9b} }, // N OSM: 8026071 WD: Q520772 35.63, 139.7 x 35.78, 139.8
    { 676, 26129, 25916, LineMetaDataContent::Subway, Color{0xff9500} }, // G OSM: 8026077 WD: Q1073046 35.66, 139.7 x 35.71, 139.8
    { 970, 26164, 25916, LineMetaDataContent::Subway, Color{0xc1a470} }, // Y OSM: 8026115 WD: Q787305 35.64, 139.6 x 35.79, 139.8
    { 39, 26205, 25916, LineMetaDataContent::Subway, Color{0x009bbf} }, // T OSM: 8026124 WD: Q1147054 35.66, 139.7 x 35.71, 140
    { 34, 26241, 25916, LineMetaDataContent::Subway, Color{0xb5b5ac} }, // H OSM: 8026149 WD: Q1196223 35.64, 139.7 x 36.11, 139.8
    { 3193, 26277, 25916, LineMetaDataContent::Subway, Color{0x8f76d6} }, // Z OSM: 8026157 WD: Q1376030 35.51, 139.4 x 36.11, 139.8
    { 329, 26316, 25916, LineMetaDataContent::Subway, Color{0x9c5e31} }, // F OSM: 8026161 WD: Q1332908 35.44, 139.4 x 36.05, 139.7
    { 406, 26356, NoLogo, LineMetaDataContent::Subway, Color{0xffaadd} }, // S OSM: 8028801 WD: Q1073354 34.64, 135.5 x 34.69, 135.6
    { 410, 26396, NoLogo, LineMetaDataContent::Subway, Color{0xdd0000} }, // M OSM: 8028805 WD: Q1192413 34.56, 135.5 x 34.83, 135.5
    { 654, 26433, NoLogo, LineMetaDataContent::Subway, Color{0xff9900} }, // I OSM: 8028826 WD: Q1066118 34.67, 135.5 x 34.76, 135.6
    { 572, 26473, NoLogo, LineMetaDataContent::Subway, Color{0x662211} }, // K OSM: 8028828 WD: Q1143250 34.64, 135.5 x 34.71, 135.5
    { 680, 26511, NoLogo, LineMetaDataContent::Subway, Color{0xaadd55} }, // N OSM: 8028846 WD: Q284828 34.67, 135.5 x 34.72, 135.6
    { 970, 26565, NoLogo, LineMetaDataContent::Subway, Color{0x0000ff} }, // Y OSM: 8028853 WD: Q1067748 34.61, 135.5 x 34.7, 135.5
    { 39, 26604, NoLogo, LineMetaDataContent::Subway, Color{0x540a56} }, // T OSM: 8028879 WD: Q1142773 34.6, 135.5 x 34.75, 135.6
    { 572, 26642, 26667, LineMetaDataContent::Subway, Color{0x3cb371} }, // K OSM: 8030551 WD: Q762347 34.96, 135.8 x 35.06, 135.8
    { 39, 26686, 26667, LineMetaDataContent::Subway, Color{0xff4500} }, // T OSM: 8030553 WD: Q1143898 34.93, 135.7 x 35.01, 135.8
    { 406, 26708, 20391, LineMetaDataContent::Subway, Color{0xff0000} }, // S OSM: 8030762 WD: Q1132780 35.09, 136.9 x 35.17, 137
    { 34, 26753, 20391, LineMetaDataContent::Subway, Color{0xffffcc} }, // H OSM: 8030765 WD: Q1132799 35.14, 136.9 x 35.18, 137
    { 535, 26798, 20391, LineMetaDataContent::Subway, Color{0x8f76d6} }, // E OSM: 8030779 WD: Q1045061 35.09, 136.9 x 35.14, 136.9
    { 39, 26837, 20391, LineMetaDataContent::Subway, Color{0xadd8e6} }, // T OSM: 8030785 WD: Q1043806 35.12, 136.9 x 35.22, 137
    { 410, 26879, 20391, LineMetaDataContent::Subway, Color{0x8f76d6} }, // M OSM: 8031607 WD: Q906775 35.12, 136.9 x 35.2, 137
    { 631, 26918, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe9527d} }, // S9 OSM: 8033205 WD: Q110714397 41.35, 2.001 x 41.41, 2.148
    { 56, 26935, 26958, LineMetaDataContent::Subway, Color{0x0000ff} }, // 1 OSM: 8034179 WD: Q6427301 22.46, 88.34 x 22.65, 88.4
    { 56, NoLogo, 23091, LineMetaDataContent::Subway, Color{0x3281c4} }, // 1 OSM: 8037596 WD: Q19891160 12.97, 80.16 x 13.18, 80.31
    { 3431, 26988, 24170, LineMetaDataContent::Subway, Color{0x4169e1} }, // Blue Line OSM: 8037671 WD: Q1029921 28.55, 77.02 x 28.66, 77.38
    { 2648, 27011, 24170, LineMetaDataContent::Subway, Color{0x008000} }, // Green Line OSM: 8037672 WD: Q5602820 28.65, 76.91 x 28.7, 77.17
    { 3441, 27034, 24170, LineMetaDataContent::Subway, Color{0x553592} }, // Violet Line OSM: 8037706 WD: Q3634451 28.34, 77.21 x 28.67, 77.32
    { 3453, 27057, 24170, LineMetaDataContent::Subway, Color{0xffdf00} }, // Yellow Line OSM: 8037713 WD: Q795156 28.46, 77.07 x 28.75, 77.23
    { 3465, NoLogo, 24170, LineMetaDataContent::Subway, Color{0xff8c00} }, // AEx OSM: 8037716 WD: Q5253735 28.55, 77.04 x 28.64, 77.22
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xeb3d1a} }, // 2 OSM: 8040132 WD: Q21245979 22.72, 108.3 x 22.89, 108.4
    { 60, 27080, NoLogo, LineMetaDataContent::Subway, Color{0xfe4998} }, // 3 OSM: 8040148 WD: Q11087465 24.99, 102.6 x 25.05, 102.8
    { 3469, 27100, 24170, LineMetaDataContent::Subway, Color{0xcc338b} }, // Magenta Line OSM: 8051576 WD: Q19893471 28.54, 77.08 x 28.63, 77.34
    { 138, 27123, 24170, LineMetaDataContent::Subway, Color{0x838996} }, // 9 OSM: 8051593 WD: Q47100305 28.61, 76.98 x 28.62, 77.02
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xb5a08e} }, // 2 OSM: 8054142 WD: Q29221208 50.03, 14.34 x 50.1, 14.42
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xdb9841} }, // 13 OSM: 8054850 WD: Q16655711 50.07, 14.43 x 50.08, 14.47
    { 22, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x9dc329} }, // 18 OSM: 8054951 WD: Q16655724 50.05, 14.39 x 50.11, 14.44
    { 231, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xa88cbf} }, // 17 OSM: 8055113 WD: Q16655722 50, 14.4 x 50.13, 14.46
    { 341, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x605047} }, // 23 OSM: 8055138 WD: Q29251387 50.07, 14.38 x 50.09, 14.43
    { 74, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf3987b} }, // 21 OSM: 8055260 WD: Q29229965 50, 14.39 x 50.07, 14.44
    { 145, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8dcdcc} }, // 14 OSM: 8057517 WD: Q16655713 50.05, 14.42 x 50.11, 14.48
    { 310, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x792522} }, // 26 OSM: 8057518 WD: Q16655738 50.05, 14.3 x 50.1, 14.54
    { 322, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe31e25} }, // 25 OSM: 8057519 WD: Q16655736 50.08, 14.32 x 50.11, 14.55
    { 247, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x1a5a7b} }, // 24 OSM: 8057520 WD: Q16655734 50.06, 14.42 x 50.13, 14.48
    { 243, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf1a1c5} }, // 20 OSM: 8057521 WD: Q16655730 50.03, 14.3 x 50.1, 14.41
    { 1013, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 91 OSM: 8060206 WD: Q122382126 50.07, 14.32 x 50.1, 14.49
    { 110, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf3987b} }, // 22 OSM: 8060656 WD: Q16655732 50.05, 14.32 x 50.09, 14.54
    { 1051, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xdc008f} }, // 99 OSM: 8060661 WD: Q29633417 50.06, 14.3 x 50.08, 14.51
    { 1010, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xdc008f} }, // 98 OSM: 8060662 WD: Q29633902 50.06, 14.3 x 50.09, 14.5
    { 11, 27146, 20592, LineMetaDataContent::Subway, Color{0x683064} }, // M5 OSM: 8061299 WD: Q1229371 40.98, 29.01 x 41.03, 29.23
    { 55, 27174, 5171, LineMetaDataContent::Subway, Color{0x82c0c0} }, // 11 OSM: 8119161 WD: Q617574 55.65, 37.44 x 55.8, 37.74
    { 42, 27199, NoLogo, LineMetaDataContent::LocalTrain, Color{0x139593} }, // 7 OSM: 8119877 WD: Q6151888 2.743, 101.7 x 3.134, 101.7
    { 27, 27220, NoLogo, LineMetaDataContent::LocalTrain, Color{0x800080} }, // 6 OSM: 8119880 WD: Q1431592 2.743, 101.7 x 3.134, 101.7
    { 281, 21343, NoLogo, LineMetaDataContent::Subway, Color{0x0000ff} }, // T1 OSM: 8120923 WD: Q56168307 10.34, -67.04 x 10.43, -67.01
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffaa00} }, // 4 OSM: 8125362 WD: Q114442363 51.2, 9.413 x 51.32, 9.722
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xcc00bb} }, // 5 OSM: 8125363 WD: Q114442364 51.25, 9.39 x 51.34, 9.502
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x773300} }, // 6 OSM: 8125364 WD: Q114442358 51.28, 9.444 x 51.34, 9.518
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x11bbbb} }, // 8 OSM: 8125365 WD: Q114442371 51.29, 9.425 x 51.33, 9.564
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000bb} }, // 2 OSM: 8126133 WD: Q114442360 51.25, 9.39 x 51.28, 9.448
    { 54, NoLogo, 14082, LineMetaDataContent::RapidTransit, Color{0xb72841} }, // S11 OSM: 8149205 WD: Q106368746 47.98, 12.85 x 48.04, 12.93
    { 217, NoLogo, 14082, LineMetaDataContent::RapidTransit, Color{0x22b24c} }, // S3 OSM: 8149206 WD: Q106368750 47.28, 12.79 x 47.84, 13.23
    { 51, NoLogo, 14082, LineMetaDataContent::RapidTransit, Color{0x0072bc} }, // S2 OSM: 8149207 WD: Q106368749 47.81, 12.97 x 47.97, 13.27
    { 63, NoLogo, 14082, LineMetaDataContent::RapidTransit, Color{0xb72841} }, // S1 OSM: 8149208 WD: Q106368744 47.81, 12.92 x 47.99, 13.05
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf2a0c5} }, // 12 OSM: 8154861 WD: Q122382727 49.77, 18.24 x 49.83, 18.32
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x38beef} }, // 8 OSM: 8157519 WD: Q122382724 49.82, 18.16 x 49.85, 18.29
    { 3482, 27241, NoLogo, LineMetaDataContent::RapidTransit, Color{0x999999} }, // 浦江 OSM: 8167022 WD: Q29704153 31.03, 121.5 x 31.06, 121.5
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf7a707} }, // 1 OSM: 8177074 WD: Q122382717 49.77, 18.25 x 49.85, 18.29
    { 2268, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0377ae} }, // R4 OSM: 8196259 48.62, 21.19 x 48.73, 21.25
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xea7b08} }, // 6 OSM: 8196338 WD: Q3238992 48.7, 21.23 x 48.73, 21.27
    { 2261, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0377ae} }, // R3 OSM: 8197830 48.62, 21.19 x 48.74, 21.25
    { 3221, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0377ae} }, // R7 OSM: 8197872 48.62, 21.19 x 48.73, 21.24
    { 700, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // T2 OSM: 8209896 WD: Q16655789 47.99, 0.1929 x 48.02, 0.2359
    { 281, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xeb001b} }, // T1 OSM: 8209897 WD: Q3239229 47.96, 0.152 x 48.02, 0.2304
    { 639, NoLogo, 3144, LineMetaDataContent::RapidTransit, Color{0x009933} }, // Green OSM: 8212097 WD: Q19960507 54.9, -1.711 x 55.04, -1.382
    { 271, 27262, NoLogo, LineMetaDataContent::Subway, Color{0xe3131b} }, // B OSM: 8219357 WD: Q2778331 34.05, -118.4 x 34.17, -118.2
    { 364, NoLogo, 10781, LineMetaDataContent::RapidTransit, Color{0xffe800} }, // Yellow OSM: 8237627 WD: Q54874971 38, -121.9 x 38.02, -121.8
    { 3382, NoLogo, 24170, LineMetaDataContent::Subway, Color{0xfc8eac} }, // Pink Line OSM: 8242438 WD: Q19891094 28.57, 77.12 x 28.72, 77.32
    { 60, 27287, 19551, LineMetaDataContent::Subway, Color{0xbb8c00} }, // 3 OSM: 8247017 WD: Q86468 35.17, 129 x 35.21, 129.1
    { 9, NoLogo, 16277, LineMetaDataContent::Tramway, Color{0xfc751c} }, // 4 OSM: 8255319 WD: Q2735863 52.04, 4.245 x 52.08, 4.543
    { 60, NoLogo, 16277, LineMetaDataContent::Tramway, Color{0x703276} }, // 3 OSM: 8255320 WD: Q3056105 52.05, 4.228 x 52.08, 4.518
    { 56, 27310, 19551, LineMetaDataContent::Subway, Color{0xf06a00} }, // 1 OSM: 8255698 WD: Q86356 35.05, 129 x 35.28, 129.1
    { 16, 27333, 19551, LineMetaDataContent::Subway, Color{0x81bf48} }, // 2 OSM: 8258658 WD: Q86467 35.13, 129 x 35.34, 129.2
    { 3489, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x00a2c9} }, // 311 OSM: 8272972 WD: Q85977451 35.16, 129.1 x 35.54, 129.4
    { 47, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x5e2d91} }, // S8 OSM: 8294822 WD: Q7388382 47.2, 8.519 x 47.5, 8.782
    { 41, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0xfebe10} }, // S7 OSM: 8294823 WD: Q7388366 47.22, 8.511 x 47.5, 8.824
    { 42, 27356, NoLogo, LineMetaDataContent::Subway, Color{0x6ad1e3} }, // 7 OSM: 8297146 WD: Q11074646 30.61, 104 x 30.7, 104.1
    { 60, 27366, NoLogo, LineMetaDataContent::Subway, Color{0xd40f7d} }, // 3 OSM: 8297273 WD: Q8985154 30.54, 103.9 x 30.82, 104.2
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x008000} }, // 2 OSM: 8297697 WD: Q84767109 17.37, 78.48 x 17.45, 78.5
    { 56, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 8297698 WD: Q54366523 17.35, 78.37 x 17.5, 78.55
    { 16, 27376, NoLogo, LineMetaDataContent::Subway, Color{0xff5c39} }, // 2 OSM: 8298113 WD: Q4391357 30.56, 104 x 30.76, 104.3
    { 9, 27386, NoLogo, LineMetaDataContent::Subway, Color{0x44af52} }, // 4 OSM: 8298132 WD: Q11074645 30.64, 103.8 x 30.69, 104.2
    { 67, 27396, NoLogo, LineMetaDataContent::Subway, Color{0x003da5} }, // 10 OSM: 8298254 WD: Q11074644 30.41, 103.8 x 30.63, 104
    { 15, 27407, NoLogo, LineMetaDataContent::Subway, Color{0xffcc00} }, // 12 OSM: 8298259 WD: Q17053935 2.931, 101.6 x 3.215, 101.7
    { 56, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 8299497 WD: Q18128813 26.77, 80.88 x 26.89, 81
    { 3493, 27429, NoLogo, LineMetaDataContent::Subway, Color{0xf2a900} }, // 环 OSM: 8300611 WD: Q15915083 29.5, 106.4 x 29.61, 106.6
    { 6, 27454, NoLogo, LineMetaDataContent::Subway, Color{0x00a3e0} }, // 5 OSM: 8300867 WD: Q15912187 29.41, 106.4 x 29.76, 106.6
    { 67, 27479, NoLogo, LineMetaDataContent::Subway, Color{0x5a2a8d} }, // 10 OSM: 8300873 WD: Q15914281 29.51, 106.5 x 29.75, 106.7
    { 3497, 27504, 4324, LineMetaDataContent::Tramway, Color{0xe1261c} }, // 西郊 OSM: 8303696 WD: Q3400451 39.97, 116.2 x 39.99, 116.3
    { 3504, 27529, 226, LineMetaDataContent::RapidTransit, Color{0x56033a} }, // S 6 OSM: 8303864 WD: Q63217185 51.06, 12.37 x 51.4, 12.7
    { 1860, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x799ccd} }, // S21 OSM: 8303997 WD: Q7388225 47.38, 8.47 x 47.44, 8.55
    { 16, 27554, 27588, LineMetaDataContent::Subway, Color{0xfdb935} }, // 2 OSM: 8306848 WD: Q28412021 36.62, 116.9 x 36.71, 117.2
    { 1837, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0xf9aa8f} }, // S41 OSM: 8306928 WD: Q15088595 47.49, 8.535 x 47.53, 8.724
    { 3508, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x75593b} }, // S27 OSM: 8308820 WD: Q106451356 47.47, 8.22 x 47.62, 8.308
    { 56, 27608, NoLogo, LineMetaDataContent::Subway, Color{0x0067a1} }, // 1 OSM: 8309087 WD: Q5963161 30.57, 114.1 x 30.71, 114.3
    { 3512, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0xbda07c} }, // S15 OSM: 8309090 WD: Q7388191 47.22, 8.368 x 47.51, 8.864
    { 44, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x48b4ca} }, // S5 OSM: 8311264 WD: Q7388335 47.17, 8.429 x 47.41, 8.864
    { 3516, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0099aa} }, // JRL OSM: 8312419 WD: Q3391052 1.312, 103.7 x 1.386, 103.7
    { 3520, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x000000} }, // WES OSM: 8313440 WD: Q12072781 45.31, -122.8 x 45.49, -122.8
    { 16, 27628, NoLogo, LineMetaDataContent::Subway, Color{0xff7300} }, // 2 OSM: 8323745 WD: Q2657097 30.12, 120 x 30.36, 120.3
    { 56, 27648, NoLogo, LineMetaDataContent::Subway, Color{0x1590ca} }, // 1 OSM: 8324096 WD: Q10946020 29.84, 121.4 x 29.92, 121.9
    { 26, 27669, 4324, LineMetaDataContent::Subway, Color{0x6da843} }, // 16 OSM: 8324250 WD: Q6553080 39.83, 116.1 x 40.07, 116.3
    { 2088, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x0588cc} }, // S30 OSM: 8327718 WD: Q7388265 47.5, 8.722 x 47.59, 9.106
    { 3524, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x007e94} }, // S26 OSM: 8327719 WD: Q2321332 47.26, 8.724 x 47.51, 8.934
    { 726, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x7a4c29} }, // S13 OSM: 8327720 WD: Q7388186 47.13, 8.675 x 47.23, 8.75
    { 56, NoLogo, 27690, LineMetaDataContent::Subway, Color{0xec7000} }, // 1 OSM: 8337169 WD: Q15953685 24.45, 118 x 24.66, 118.1
    { 63, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffbabe} }, // S1 OSM: 8340382 WD: Q125989601 49.82, 17.91 x 49.93, 18.21
    { 3528, 27710, NoLogo, LineMetaDataContent::LocalTrain, Color{} }, // RB 32 OSM: 8347311 WD: Q113258586 48.73, 12.19 x 48.91, 12.69
    { 262, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x7b2c1c} }, // 41 OSM: 8350410 WD: Q29229288 50.09, 14.39 x 50.1, 14.43
    { 321, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0xb41e8e} }, // S25 OSM: 8355962 WD: Q18391643 46.92, 8.519 x 47.38, 9.084
    { 1446, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffc700} }, // S 8 OSM: 8376374 51.04, 13.72 x 51.27, 14.09
    { 448, 27727, NoLogo, LineMetaDataContent::LocalTrain, Color{} }, // RB 59 OSM: 8377332 WD: Q110188017 47.87, 12.64 x 47.93, 12.73
    { 3534, 27744, NoLogo, LineMetaDataContent::Subway, Color{0x939598} }, // JL OSM: 8391469 WD: Q5365768 35.75, 139.8 x 35.9, 140.1
    { 3537, 18701, NoLogo, LineMetaDataContent::RapidTransit, Color{0x802168} }, // C-4 OSM: 8394326 WD: Q43264468 43.19, -3.198 x 43.27, -2.926
    { 576, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf3d9a6} }, // L OSM: 8400989 WD: Q123244737 43.04, -87.91 x 43.04, -87.9
    { 3541, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008752} }, // Rosewood OSM: 8409183 WD: Q6065655 -27.64, 152.6 x -27.46, 153
    { 42, 27766, 1925, LineMetaDataContent::Tramway, Color{0x667ab3} }, // 7 OSM: 8426298 WD: Q104867986 49.43, 11.08 x 49.45, 11.09
    { 56, 27783, 24170, LineMetaDataContent::Subway, Color{0xff4040} }, // 1 OSM: 8429148 WD: Q3278367 28.67, 77.1 x 28.72, 77.42
    { 2109, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x73b3d7} }, // S35 OSM: 8437405 WD: Q7388272 47.46, 8.724 x 47.51, 9.043
    { 1058, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x32a384} }, // S29 OSM: 8437511 WD: Q7388235 47.5, 8.714 x 47.66, 8.856
    { 265, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0xad99c9} }, // S40 OSM: 8437648 WD: Q7388295 47.13, 8.682 x 47.22, 8.817
    { 3550, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x198ea3} }, // S17 OSM: 8437734 WD: Q115195960 47.34, 8.27 x 47.41, 8.406
    { 3554, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // ExpressTram OSM: 8438647 WD: Q5421647 42.2, -83.36 x 42.21, -83.35
    { 566, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfc0200} }, // ATS OSM: 8438739 WD: Q2828747 41.97, -87.91 x 41.99, -87.88
    { 9, 27806, NoLogo, LineMetaDataContent::Subway, Color{0x0072ce} }, // 4 OSM: 8439223 WD: Q6112249 31.13, 120.6 x 31.41, 120.7
    { 16, 27827, NoLogo, LineMetaDataContent::Subway, Color{0xe60000} }, // 2 OSM: 8439253 WD: Q1054280 31.25, 120.6 x 31.44, 120.8
    { 3566, 27848, NoLogo, LineMetaDataContent::LocalTrain, Color{0xffffff} }, // RB 57 OSM: 8442834 WD: Q108409635 47.71, 11.53 x 48.14, 11.76
    { 707, 27865, NoLogo, LineMetaDataContent::LocalTrain, Color{0xffffff} }, // RB 56 OSM: 8442835 WD: Q108409632 47.68, 11.53 x 48.14, 11.71
    { 364, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffff00} }, // Yellow OSM: 8464133 WD: Q55683262 9.006, 7.272 x 9.057, 7.472
    { 166, 27887, 14192, LineMetaDataContent::Subway, Color{0x00adef} }, // 52 OSM: 8466672 WD: Q2466115 52.34, 4.874 x 52.4, 4.933
    { 3572, 27926, 3675, LineMetaDataContent::Tramway, Color{0xe65e37} }, // T11 OSM: 8467024 WD: Q1083349 48.93, 2.302 x 48.96, 2.424
    { 2049, 27960, NoLogo, LineMetaDataContent::RapidTransit, Color{0x9b26b6} }, // A2 OSM: 8467447 WD: Q17853551 37.91, 23.71 x 38.07, 23.95
    { 2167, 27995, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffcd00} }, // A1 OSM: 8467448 WD: Q47477364 37.91, 23.64 x 38.07, 23.95
    { 3576, 28030, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00a3e0} }, // A4 OSM: 8467516 WD: Q20552930 37.91, 22.73 x 38.09, 23.74
    { 3579, 28065, 4324, LineMetaDataContent::Subway, Color{0xd85f26} }, // 25S OSM: 8469061 WD: Q8048350 39.7, 116 x 39.73, 116.1
    { 281, NoLogo, 28091, LineMetaDataContent::Tramway, Color{0x254395} }, // T1 OSM: 8475071 WD: Q55693065 43.75, 11.17 x 43.8, 11.25
    { 138, NoLogo, 28116, LineMetaDataContent::Subway, Color{0x063a91} }, // 9 OSM: 8478970 WD: Q3125123 39.01, 117.2 x 39.14, 117.7
    { 570, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7a121c} }, // SYK OSM: 8489646 WD: Q124521879 -1.361, 36.83 x -1.289, 36.91
    { 3583, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7a121c} }, // KKY OSM: 8489647 WD: Q124527546 -1.315, 36.64 x -1.115, 36.83
    { 3587, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7a121c} }, // RIU OSM: 8489648 WD: Q124536401 -1.301, 36.83 x -1.15, 36.96
    { 60, NoLogo, 28116, LineMetaDataContent::Subway, Color{0x128bbe} }, // 3 OSM: 8489969 WD: Q6553117 39.06, 117.1 x 39.24, 117.3
    { 16, NoLogo, 28116, LineMetaDataContent::Subway, Color{0xece114} }, // 2 OSM: 8489970 WD: Q6553104 39.13, 117.1 x 39.16, 117.4
    { 56, 28133, 28116, LineMetaDataContent::Subway, Color{0xbd0016} }, // 1 OSM: 8489971 WD: Q6126171 39.01, 117.1 x 39.21, 117.4
    { 27, NoLogo, 28116, LineMetaDataContent::Subway, Color{0x9f216f} }, // 6 OSM: 8490135 WD: Q10940001 39.04, 117.1 x 39.21, 117.3
    { 9, 28163, NoLogo, LineMetaDataContent::RapidTransit, Color{0x009049} }, // 4 OSM: 8499866 WD: Q109046034 36.8, 10.06 x 36.82, 10.19
    { 3591, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 201 OSM: 8505446 52.37, 16.91 x 52.46, 16.98
    { 145, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xaa6133} }, // 14 OSM: 8505950 52.38, 16.88 x 52.46, 16.92
    { 15, 28187, NoLogo, LineMetaDataContent::Tramway, Color{0xc597cd} }, // 12 OSM: 8505951 WD: Q108000820 52.37, 16.91 x 52.46, 16.95
    { 55, 28226, NoLogo, LineMetaDataContent::Tramway, Color{0x5ec79f} }, // 11 OSM: 8505952 WD: Q108000659 52.37, 16.89 x 52.44, 16.96
    { 3595, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf166a7} }, // 42X OSM: 8506177 58.9, 17.86 x 59.63, 18.16
    { 3599, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // TGM OSM: 8510421 WD: Q1306749 36.8, 10.19 x 36.88, 10.34
    { 6, 28265, NoLogo, LineMetaDataContent::RapidTransit, Color{0x009049} }, // 5 OSM: 8510688 WD: Q109046037 36.8, 10.12 x 36.84, 10.18
    { 60, 28289, NoLogo, LineMetaDataContent::RapidTransit, Color{0x009049} }, // 3 OSM: 8510789 WD: Q109046031 36.8, 10.13 x 36.83, 10.18
    { 16, 28313, NoLogo, LineMetaDataContent::RapidTransit, Color{0x009049} }, // 2 OSM: 8511768 WD: Q109046023 36.81, 10.18 x 36.86, 10.2
    { 170, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf166a7} }, // 44 OSM: 8518402 59.2, 17.81 x 59.45, 18.07
    { 3603, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf166a7} }, // 43X OSM: 8518405 58.9, 17.81 x 59.45, 18.16
    { 56, 28337, 28116, LineMetaDataContent::Tramway, Color{0x8fc31f} }, // 1 OSM: 8548848 WD: Q1659593 39.02, 117.7 x 39.09, 117.7
    { 576, 28360, 3675, LineMetaDataContent::RapidTransit, Color{0x7577c0} }, // L OSM: 8557335 WD: Q93379 48.81, 2.011 x 49.05, 2.324
    { 138, 28394, 8171, LineMetaDataContent::Tramway, Color{0xc44f97} }, // 9 OSM: 8624098 WD: Q28609936 50.86, 4.309 x 50.9, 4.332
    { 3607, 28415, 19551, LineMetaDataContent::Subway, Color{0x0c8e72} }, // GC OSM: 8656365 WD: Q20192 37.58, 127 x 37.88, 127.7
    { 63, 28435, 28449, LineMetaDataContent::RapidTransit, Color{0xee333e} }, // S1 OSM: 8661616 WD: Q46365 45.31, 9.032 x 45.62, 9.498
    { 51, 28471, 28449, LineMetaDataContent::RapidTransit, Color{0x00aa8a} }, // S2 OSM: 8661617 WD: Q1160540 45.43, 9.14 x 45.65, 9.238
    { 217, 28485, 28449, LineMetaDataContent::RapidTransit, Color{0xab2a42} }, // S3 OSM: 8662821 WD: Q600028 45.47, 9.032 x 45.62, 9.176
    { 306, 28499, 28449, LineMetaDataContent::RapidTransit, Color{0x82c44e} }, // S4 OSM: 8662822 WD: Q1160571 45.47, 9.133 x 45.67, 9.175
    { 44, 28513, 28449, LineMetaDataContent::RapidTransit, Color{0xff980d} }, // S5 OSM: 8662846 WD: Q1159300 45.46, 8.789 x 45.82, 9.591
    { 290, 28527, 28449, LineMetaDataContent::RapidTransit, Color{0xf0df00} }, // S6 OSM: 8662847 WD: Q1160580 45.43, 8.625 x 45.53, 9.591
    { 3610, 14796, 14616, LineMetaDataContent::Subway, Color{0x009fe3} }, // L10 Sud OSM: 8663605 WD: Q1577033 41.32, 2.113 x 41.38, 2.148
    { 3618, 28541, 19551, LineMetaDataContent::Subway, Color{0x73c7a6} }, // G·J OSM: 8667957 WD: Q18233162 37.47, 126.7 x 37.9, 127.6
    { 576, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffff00} }, // L OSM: 8668342 WD: Q48770897 39.74, -105 x 39.76, -105
    { 3623, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 202 OSM: 8671531 52.38, 16.91 x 52.46, 17
    { 533, 28567, NoLogo, LineMetaDataContent::Tramway, Color{0xff7f00} }, // 24E OSM: 8682141 WD: Q63230204 38.71, -9.162 x 38.73, -9.143
    { 56, 28580, 19551, LineMetaDataContent::Subway, Color{0x005daa} }, // 1 OSM: 8691899 WD: Q20280 36.77, 126.6 x 38.1, 127.2
    { 3627, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008144} }, // 902 OSM: 8708438 WD: Q5060656 44.95, -93.28 x 44.98, -93.09
    { 26, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf9b000} }, // 16 OSM: 8712352 WD: Q110253214 52.32, 9.722 x 52.38, 9.837
    { 22, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe4003a} }, // 18 OSM: 8712368 WD: Q107242125 52.33, 9.734 x 52.39, 9.804
    { 3631, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa4228e} }, // 750 OSM: 8718106 40.23, -112 x 41.23, -111.7
    { 3635, 28603, 19551, LineMetaDataContent::Subway, Color{0x8fc31e} }, // 321 OSM: 8725316 WD: Q109116480 37.3, 126.8 x 37.68, 126.8
    { 3640, 28641, NoLogo, LineMetaDataContent::Tramway, Color{0x808080} }, // 720 OSM: 8725393 WD: Q7634842 40.72, -111.9 x 40.72, -111.9
    { 567, 28661, NoLogo, LineMetaDataContent::Tramway, Color{0x9bb14f} }, // TS OSM: 8729960 WD: Q23308659 33.41, -111.9 x 33.43, -111.9
    { 3644, 28686, 19551, LineMetaDataContent::Subway, Color{0x0054a6} }, // GG OSM: 8735483 WD: Q23933857 37.26, 127.1 x 37.41, 127.6
    { 56, NoLogo, 28706, LineMetaDataContent::Subway, Color{0x10069f} }, // 1 OSM: 8742572 WD: Q17498490 43.76, 87.47 x 43.92, 87.62
    { 281, 28719, 28719, LineMetaDataContent::Tramway, Color{0x008000} }, // T1 OSM: 8753522 WD: Q2661356 43.24, -2.952 x 43.27, -2.905
    { 3647, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x409337} }, // PKM3 OSM: 8780893 WD: Q112660402 52.09, 16.11 x 52.81, 17.22
    { 15, 28736, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 12 OSM: 8823281 WD: Q1485440 47.55, 19.09 x 47.57, 19.13
    { 3652, NoLogo, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 56A OSM: 8823482 WD: Q21996124 47.48, 18.96 x 47.54, 19.05
    { 3656, 28760, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 59A OSM: 8823524 WD: Q1491496 47.48, 19 x 47.51, 19.02
    { 3660, NoLogo, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 59B OSM: 8823525 WD: Q22810651 47.48, 18.96 x 47.54, 19.02
    { 39, 28785, NoLogo, LineMetaDataContent::RapidTransit, Color{0xd40843} }, // T OSM: 8826111 WD: Q1755582 37.71, -122.4 x 37.8, -122.4
    { 47, 28809, 28449, LineMetaDataContent::RapidTransit, Color{0xf8b1b0} }, // S8 OSM: 8840314 WD: Q1160824 45.48, 9.183 x 45.86, 9.435
    { 726, 28823, 28449, LineMetaDataContent::RapidTransit, Color{0x99642e} }, // S13 OSM: 8840315 WD: Q1160881 45.19, 9.081 x 45.58, 9.245
    { 631, 28838, 28449, LineMetaDataContent::RapidTransit, Color{0xa0499a} }, // S9 OSM: 8840324 WD: Q56920 45.4, 8.956 x 45.65, 9.274
    { 54, 28852, 28449, LineMetaDataContent::RapidTransit, Color{0x9d91c5} }, // S11 OSM: 8840325 WD: Q1160879 45.48, 9.028 x 45.83, 9.274
    { 60, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xffa500} }, // 3 OSM: 8857387 24.57, 46.54 x 24.73, 46.86
    { 27, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x800080} }, // 6 OSM: 8857388 WD: Q106740378 24.7, 46.64 x 24.81, 46.83
    { 9, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xf8eb00} }, // 4 OSM: 8857389 WD: Q106740374 24.77, 46.64 x 24.96, 46.72
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf5a300} }, // 12 OSM: 8871002 WD: Q16655708 46.17, 6.129 x 46.2, 6.207
    { 2568, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // SC OSM: 8888446 43.03, 141.3 x 43.06, 141.4
    { 3664, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // Circular OSM: 9084313 WD: Q8048613 16.78, 96.09 x 16.94, 96.18
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xa68351} }, // 2 OSM: 9112026 WD: Q16854978 47.54, 7.571 x 47.59, 7.651
    { 60, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x324ea1} }, // 3 OSM: 9118502 WD: Q16854981 47.55, 7.553 x 47.59, 7.631
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x835237} }, // 1 OSM: 9118510 WD: Q16854970 47.55, 7.573 x 47.57, 7.608
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0072bc} }, // 6 OSM: 9128621 WD: Q16854982 47.55, 7.537 x 47.59, 7.656
    { 3673, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff6319} }, // Long Beach OSM: 9129728 WD: Q6672281 40.59, -73.99 x 40.75, -73.65
    { 3684, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x6e3219} }, // Far Rockaway OSM: 9129758 WD: Q5434607 40.61, -73.98 x 40.7, -73.7
    { 42, 28867, NoLogo, LineMetaDataContent::Subway, Color{0x8b0000} }, // 7 OSM: 9140122 WD: Q6749694 14.65, 121 x 14.77, 121.1
    { 3697, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff6600} }, // MSC 621 OSM: 9165725 14.2, 121 x 14.62, 121.2
    { 3705, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // MNC OSM: 9165728 14.61, 121 x 14.67, 121
    { 3709, 28890, NoLogo, LineMetaDataContent::LocalTrain, Color{} }, // RE 22 OSM: 9173483 WD: Q108179529 48.33, 11.68 x 49.01, 12.22
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf171ab} }, // 8 OSM: 9173651 WD: Q16854983 47.55, 7.557 x 47.59, 7.608
    { 3537, 28907, 3582, LineMetaDataContent::RapidTransit, Color{0x00289c} }, // C-4 OSM: 9174513 WD: Q1919488 40.24, -3.778 x 40.65, -3.635
    { 67, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfeca0a} }, // 10 OSM: 9177454 WD: Q7885420 47.48, 7.459 x 47.55, 7.62
    { 3715, 28925, 3582, LineMetaDataContent::RapidTransit, Color{0xffa500} }, // C-9 OSM: 9181540 WD: Q8880294 40.74, -4.066 x 40.82, -3.963
    { 2668, 18482, 3582, LineMetaDataContent::RapidTransit, Color{0x008a29} }, // C-2 OSM: 9187669 WD: Q2287356 40.38, -3.694 x 40.64, -3.181
    { 145, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf58220} }, // 14 OSM: 9190891 WD: Q16854972 47.52, 7.587 x 47.57, 7.694
    { 60, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 3 OSM: 9192778 WD: Q104189065 50.81, 12.92 x 50.84, 12.93
    { 149, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00a54f} }, // 15 OSM: 9193744 WD: Q89415715 47.53, 7.587 x 47.56, 7.6
    { 26, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xa6ce39} }, // 16 OSM: 9196819 WD: Q16854975 47.53, 7.584 x 47.56, 7.605
    { 231, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00aeef} }, // 17 OSM: 9201222 WD: Q16854977 47.48, 7.545 x 47.58, 7.593
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf5b85a} }, // 6 OSM: 9217293 WD: Q122781782 45.74, 21.22 x 45.76, 21.25
    { 416, 28943, NoLogo, LineMetaDataContent::RapidTransit, Color{0x1662b8} }, // U OSM: 9221982 WD: Q1191079 35.62, 139.8 x 35.67, 139.8
    { 153, NoLogo, 28970, LineMetaDataContent::RapidTransit, Color{0xff1493} }, // 19 OSM: 9234808 WD: Q154730 47.39, 7.729 x 47.49, 7.773
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xd64560} }, // 2 OSM: 9235815 WD: Q106996888 47.26, 11.35 x 47.28, 11.44
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8b445b} }, // 5 OSM: 9235816 WD: Q106996949 47.26, 11.34 x 47.28, 11.46
    { 3719, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // СТ-2 OSM: 9244973 WD: Q107191059 48.68, 44.47 x 48.8, 44.6
    { 359, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x002666} }, // Blue OSM: 9248096 WD: Q4929369 38.45, -121.5 x 38.65, -121.4
    { 639, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x006633} }, // Green OSM: 9248097 WD: Q16000108 38.57, -121.5 x 38.6, -121.5
    { 1864, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffba00} }, // Gold OSM: 9248098 WD: Q5578775 38.55, -121.5 x 38.68, -121.2
    { 3726, 28993, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff69b4} }, // NT OSM: 9253571 WD: Q910032 35.73, 139.8 x 35.81, 139.8
    { 3729, 29025, NoLogo, LineMetaDataContent::Tramway, Color{0xd85b81} }, // SA OSM: 9254426 WD: Q1064795 35.71, 139.7 x 35.75, 139.8
    { 3732, NoLogo, 24170, LineMetaDataContent::Subway, Color{0x00ffff} }, // Aqua Line OSM: 9256785 WD: Q41668068 28.44, 77.37 x 28.59, 77.55
    { 2258, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0377ae} }, // R2 OSM: 9266121 48.62, 21.19 x 48.71, 21.3
    { 2271, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0377ae} }, // R8 OSM: 9266263 48.62, 21.19 x 48.71, 21.27
    { 672, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0377ae} }, // R1 OSM: 9273350 48.62, 21.19 x 48.72, 21.27
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0377ae} }, // 5 OSM: 9274837 WD: Q3238964 48.7, 21.24 x 48.72, 21.27
    { 3742, 29054, NoLogo, LineMetaDataContent::RapidTransit, Color{0xcc3333} }, // exo1 OSM: 9288759 WD: Q3239247 45.39, -74.14 x 45.5, -73.57
    { 1600, 29099, NoLogo, LineMetaDataContent::RapidTransit, Color{0xda0442} }, // TY OSM: 9288983 WD: Q1192468 35.47, 139.6 x 35.66, 139.7
    { 3747, 29124, NoLogo, LineMetaDataContent::RapidTransit, Color{0x808080} }, // exo4 OSM: 9298215 WD: Q3239087 45.36, -73.66 x 45.5, -73.51
    { 700, NoLogo, 28091, LineMetaDataContent::Tramway, Color{0x5d3988} }, // T2 OSM: 9298542 WD: Q61670436 43.77, 11.2 x 43.8, 11.25
    { 55, 29169, NoLogo, LineMetaDataContent::Subway, Color{0x6a1d44} }, // 11 OSM: 9318442 WD: Q4698920 22.52, 113.8 x 22.79, 114.1
    { 3752, 29193, NoLogo, LineMetaDataContent::RapidTransit, Color{0x009900} }, // exo2 OSM: 9326028 WD: Q3239074 45.45, -74 x 45.77, -73.57
    { 3757, 29238, NoLogo, LineMetaDataContent::Subway, Color{0x3564af} }, // SR OSM: 9336150 WD: Q1065949 35.78, 139.7 x 35.89, 139.8
    { 3760, 29270, NoLogo, LineMetaDataContent::RapidTransit, Color{0xef473d} }, // SY OSM: 9338171 WD: Q842520 35.77, 139.4 x 35.77, 139.4
    { 3763, 29289, NoLogo, LineMetaDataContent::RapidTransit, Color{0x009cd2} }, // MG OSM: 9340970 WD: Q283861 35.55, 139.6 x 35.63, 139.7
    { 3766, 29314, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf18c43} }, // OM OSM: 9341650 WD: Q384995 35.6, 139.6 x 35.61, 139.7
    { 3769, 29339, NoLogo, LineMetaDataContent::RapidTransit, Color{0x20a288} }, // DT OSM: 9341816 WD: Q1190086 35.51, 139.4 x 35.66, 139.7
    { 3772, 29364, NoLogo, LineMetaDataContent::RapidTransit, Color{0xee86a7} }, // IK OSM: 9342009 WD: Q1192388 35.56, 139.7 x 35.63, 139.7
    { 1710, 29389, NoLogo, LineMetaDataContent::RapidTransit, Color{0xae0378} }, // TM OSM: 9343887 WD: Q379292 35.56, 139.7 x 35.59, 139.7
    { 3775, 29414, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff00ff} }, // exo5 OSM: 9344059 WD: Q3239152 45.52, -73.67 x 45.74, -73.49
    { 3780, 29459, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0068b7} }, // KD OSM: 9344153 WD: Q842701 35.53, 139.5 x 35.56, 139.5
    { 2006, 29484, NoLogo, LineMetaDataContent::RapidTransit, Color{0x10a899} }, // NS OSM: 9346454 WD: Q846381 35.91, 139.6 x 36.01, 139.6
    { 3783, 29512, NoLogo, LineMetaDataContent::RapidTransit, Color{0x6600cc} }, // exo3 OSM: 9348176 WD: Q3239159 45.49, -73.57 x 45.58, -73.18
    { 3788, 29557, 410, LineMetaDataContent::RapidTransit, Color{0xbac219} }, // U16 OSM: 9354869 WD: Q106879571 48.8, 9.087 x 48.81, 9.277
    { 60, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x4682b4} }, // 3 OSM: 9357105 WD: Q121543796 43.83, 18.31 x 43.86, 18.43
    { 341, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf8b710} }, // 23 OSM: 9396890 48.75, 9.179 x 48.81, 9.221
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x4682b4} }, // 6 OSM: 9402053 WD: Q121543799 43.83, 18.31 x 43.86, 18.41
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x4682b4} }, // 5 OSM: 9402054 WD: Q121543798 43.84, 18.34 x 43.86, 18.43
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x4682b4} }, // 4 OSM: 9402055 WD: Q121543797 43.83, 18.31 x 43.86, 18.4
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x4682b4} }, // 2 OSM: 9402056 WD: Q121543794 43.85, 18.37 x 43.86, 18.43
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x4682b4} }, // 1 OSM: 9402057 WD: Q121543793 43.86, 18.4 x 43.86, 18.43
    { 687, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc01903} }, // A OSM: 9413576 WD: Q1419423 45.76, 3.082 x 45.81, 3.134
    { 74, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00ae9d} }, // 21 OSM: 9414064 WD: Q16854979 47.56, 7.573 x 47.57, 7.608
    { 44, NoLogo, 28970, LineMetaDataContent::RapidTransit, Color{0x79d4f0} }, // S5 OSM: 9414242 WD: Q63705361 47.59, 7.608 x 47.64, 7.744
    { 1221, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0xcb7eb5} }, // S36 OSM: 9414253 WD: Q15088595 47.52, 8.22 x 47.62, 8.538
    { 3792, 29575, NoLogo, LineMetaDataContent::Subway, Color{0xf890a5} }, // 捷運紅線 (新北投支線) OSM: 9437207 WD: Q8044505 25.13, 121.5 x 25.14, 121.5
    { 3292, 29614, NoLogo, LineMetaDataContent::Subway, Color{0x007ec7} }, // BL OSM: 9437778 WD: Q708378 24.96, 121.4 x 25.05, 121.6
    { 1581, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x2ab04f} }, // RE OSM: 9441941 46.95, 7.438 x 47.2, 7.559
    { 631, NoLogo, 13458, LineMetaDataContent::RapidTransit, Color{0xea1a2a} }, // S9 OSM: 9441942 WD: Q115689939 46.95, 7.438 x 46.99, 7.458
    { 47, NoLogo, 13458, LineMetaDataContent::RapidTransit, Color{0x201f20} }, // S8 OSM: 9441943 WD: Q115689938 46.95, 7.438 x 47.13, 7.535
    { 3524, 29639, 226, LineMetaDataContent::RapidTransit, Color{0x018a47} }, // S26 OSM: 9445376 WD: Q7388232 52.4, 13.28 x 52.59, 13.44
    { 55, NoLogo, 3169, LineMetaDataContent::Tramway, Color{0xce1417} }, // 11 OSM: 9446625 WD: Q123339545 50.46, 30.46 x 50.5, 30.52
    { 352, NoLogo, 7769, LineMetaDataContent::Subway, Color{0xff0000} }, // M1 OSM: 9449959 WD: Q3238662 45.02, 7.591 x 45.08, 7.68
    { 60, 29670, 17148, LineMetaDataContent::Tramway, Color{0xffff00} }, // 3 OSM: 9453120 WD: Q61000373 -22.91, -43.19 x -22.9, -43.17
    { 2183, NoLogo, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 2B OSM: 9453936 WD: Q113118555 47.42, 19.05 x 47.51, 19.12
    { 27, 29699, 20281, LineMetaDataContent::Subway, Color{0xff5599} }, // 6 OSM: 9468298 WD: Q20110123 35.62, 51.28 x 35.77, 51.46
    { 3823, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffcd28} }, // Z72 OSM: 9470080 WD: Q101321651 47.51, 18.71 x 47.78, 19.1
    { 3831, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff6600} }, // RN OSM: 9477810 WD: Q1055870 35.81, 139.9 x 35.86, 139.9
    { 3834, 29723, NoLogo, LineMetaDataContent::Subway, Color{0xffff00} }, // KS-AE OSM: 9480386 WD: Q1045305 35.54, 139.7 x 35.81, 140.4
    { 2733, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xee1d23} }, // 510 OSM: 9481706 WD: Q787200 43.64, -79.4 x 43.67, -79.38
    { 352, 29751, 29766, LineMetaDataContent::Subway, Color{0x3e9397} }, // M1 OSM: 9487066 WD: Q63781320 -33.91, 150.9 x -33.69, 151.2
    { 3840, 29778, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7a745a} }, // F3 OSM: 9488738 WD: Q31193173 41.1, 28.99 x 41.11, 28.99
    { 2391, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x006400} }, // EN OSM: 9499957 WD: Q250760 35.3, 139.5 x 35.34, 139.6
    { 3843, 29806, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00a6bf} }, // SS OSM: 9507192 WD: Q195685 35.7, 139.3 x 35.91, 139.7
    { 700, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x46837b} }, // T2 OSM: 9515444 WD: Q18118581 31.02, 121.2 x 31.06, 121.3
    { 56, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0000ff} }, // 1 OSM: 9522022 WD: Q61990549 23, 72.51 x 23.05, 72.67
    { 56, 29824, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa6dfe6} }, // 1 OSM: 9525005 WD: Q109046020 36.75, 10.18 x 36.8, 10.22
    { 27, 29848, NoLogo, LineMetaDataContent::RapidTransit, Color{0x652c90} }, // 6 OSM: 9530554 WD: Q109046039 36.72, 10.18 x 36.8, 10.22
    { 511, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x48a23e} }, // L2 OSM: 9536631 WD: Q25420937 9.029, -79.51 x 9.104, -79.35
    { 359, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // Blue OSM: 9542499 9.046, 7.285 x 9.155, 7.344
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009999} }, // 5 OSM: 9544852 WD: Q112609290 53.08, 8.752 x 53.12, 8.818
    { 3846, 29872, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffff00} }, // JN OSM: 9555851 WD: Q1366263 35.51, 139.4 x 35.7, 139.7
    { 3849, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // Linea 1 OSM: 9562447 WD: Q113469626 -2.921, -79.04 x -2.882, -78.97
    { 1029, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff9c2a} }, // N19 OSM: 9570043 47.48, 19.04 x 47.53, 19.06
    { 3857, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xffa500} }, // Orange Line OSM: 9571557 WD: Q61996404 21.05, 79.05 x 21.19, 79.12
    { 371, NoLogo, 29894, LineMetaDataContent::Subway, Color{0xe2251c} }, // Red OSM: 9573815 WD: Q25343681 25.19, 51.49 x 25.42, 51.62
    { 63, NoLogo, 13458, LineMetaDataContent::RapidTransit, Color{0x4cb848} }, // S1 OSM: 9577262 WD: Q115689931 46.75, 7.15 x 46.97, 7.631
    { 51, NoLogo, 13458, LineMetaDataContent::RapidTransit, Color{0x00abe5} }, // S2 OSM: 9577399 WD: Q115689932 46.88, 7.241 x 46.97, 7.784
    { 306, NoLogo, 13458, LineMetaDataContent::RapidTransit, Color{0x45bfad} }, // S4 OSM: 9579475 WD: Q115689934 46.75, 7.407 x 47.07, 7.784
    { 2157, NoLogo, 13458, LineMetaDataContent::RapidTransit, Color{0x5d5910} }, // S44 OSM: 9582296 WD: Q115689941 46.75, 7.407 x 47.2, 7.737
    { 44, NoLogo, 13458, LineMetaDataContent::RapidTransit, Color{0x7f0041} }, // S5 OSM: 9582947 WD: Q115689935 46.82, 6.933 x 47.01, 7.44
    { 290, NoLogo, 13458, LineMetaDataContent::RapidTransit, Color{0xea595b} }, // S6 OSM: 9584378 WD: Q115689936 46.82, 7.34 x 46.95, 7.439
    { 41, 29922, 12277, LineMetaDataContent::Subway, Color{0xca8687} }, // S7 OSM: 9584586 WD: Q10946062 31.61, 118.9 x 31.76, 119
    { 631, 29943, 12277, LineMetaDataContent::Subway, Color{0xf1bc1a} }, // S9 OSM: 9584587 WD: Q47471478 31.34, 118.8 x 31.76, 118.9
    { 165, NoLogo, 13458, LineMetaDataContent::RapidTransit, Color{0xe9ce0e} }, // S52 OSM: 9584652 WD: Q115689943 46.93, 7.188 x 46.98, 7.439
    { 217, NoLogo, 13458, LineMetaDataContent::RapidTransit, Color{0x8a6aae} }, // S3 OSM: 9585454 WD: Q115689933 46.89, 7.24 x 47.13, 7.499
    { 3869, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xee1d23} }, // 504 OSM: 9585574 WD: Q3238945 43.63, -79.45 x 43.68, -79.35
    { 3873, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xee1d23} }, // 509 OSM: 9585849 WD: Q3238948 43.64, -79.42 x 43.65, -79.38
    { 3877, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xee1e23} }, // U GUS OSM: 9586670 WD: Q124221046 41.14, -8.61 x 41.44, -8.294
    { 47, 29964, 12277, LineMetaDataContent::Subway, Color{0xeca153} }, // S8 OSM: 9588181 WD: Q10945880 32.13, 118.7 x 32.47, 119
    { 9, 29985, 12277, LineMetaDataContent::Subway, Color{0xa513c0} }, // 4 OSM: 9588283 WD: Q10906684 32.06, 118.7 x 32.13, 119
    { 60, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xd3b466} }, // 3 OSM: 9588292 WD: Q11124519 30.49, 114.2 x 30.67, 114.3
    { 16, 30005, NoLogo, LineMetaDataContent::Subway, Color{0xec9cbb} }, // 2 OSM: 9592190 WD: Q5952205 30.44, 114.2 x 30.77, 114.4
    { 3883, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x3caeef} }, // U MCS OSM: 9599441 WD: Q18473945 41.14, -8.61 x 41.26, -8.136
    { 3889, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x9b68a0} }, // ACE OSM: 9599550 37.33, -122 x 37.96, -121.3
    { 3893, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x114533} }, // SMART OSM: 9599558 37.95, -122.8 x 38.51, -122.5
    { 336, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x006400} }, // 45 OSM: 9600350 51.78, 19.41 x 51.85, 19.51
    { 262, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x006400} }, // 41 OSM: 9600352 51.66, 19.32 x 51.74, 19.46
    { 22, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 18 OSM: 9600353 WD: Q108047266 51.74, 19.38 x 51.78, 19.51
    { 231, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffc0cb} }, // 17 OSM: 9600354 WD: Q108074811 51.7, 19.41 x 51.78, 19.51
    { 26, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffc0cb} }, // 16 OSM: 9600355 WD: Q122338999 51.73, 19.36 x 51.8, 19.51
    { 149, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffc0cb} }, // 15 OSM: 9600356 WD: Q108000775 51.72, 19.45 x 51.78, 19.53
    { 145, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // 14 OSM: 9600357 WD: Q108049889 51.74, 19.38 x 51.76, 19.51
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 13 OSM: 9600358 WD: Q108068380 51.73, 19.37 x 51.8, 19.49
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 12 OSM: 9600359 WD: Q108049384 51.74, 19.38 x 51.78, 19.53
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffa500} }, // 11 OSM: 9600360 WD: Q108049347 51.7, 19.41 x 51.83, 19.46
    { 3899, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // 10AB OSM: 9600361 WD: Q108049512 51.73, 19.38 x 51.76, 19.58
    { 3904, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 9AB OSM: 9600362 WD: Q108049814 51.73, 19.41 x 51.77, 19.58
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // 8 OSM: 9600363 WD: Q108049476 51.75, 19.36 x 51.8, 19.54
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffa500} }, // 6 OSM: 9600365 WD: Q108049423 51.72, 19.45 x 51.8, 19.49
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x800080} }, // 5 OSM: 9600366 WD: Q108068411 51.72, 19.37 x 51.8, 19.49
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 4 OSM: 9600367 51.74, 19.43 x 51.83, 19.51
    { 60, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffa500} }, // 3 OSM: 9600368 WD: Q108049494 51.72, 19.45 x 51.81, 19.55
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffa500} }, // 2 OSM: 9600370 WD: Q108049451 51.74, 19.36 x 51.8, 19.51
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x800080} }, // 1 OSM: 9600371 WD: Q108068411 51.75, 19.46 x 51.8, 19.49
    { 3908, NoLogo, 30025, LineMetaDataContent::Tramway, Color{0x32cd32} }, // HN OSM: 9603867 WD: Q5648522 34.54, 135.4 x 34.65, 135.5
    { 421, 30047, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7777ff} }, // P OSM: 9603949 WD: Q1073366 34.61, 135.4 x 34.64, 135.5
    { 3911, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // Local OSM: 9604092 37.31, -122.4 x 37.78, -121.9
    { 6, NoLogo, 28116, LineMetaDataContent::Subway, Color{0xfb6f14} }, // 5 OSM: 9604983 WD: Q10940000 39.03, 117.1 x 39.27, 117.2
    { 9, 30091, NoLogo, LineMetaDataContent::Subway, Color{0x00843d} }, // 4 OSM: 9607978 WD: Q863422 22.75, 113.4 x 23.13, 113.6
    { 9, 30111, NoLogo, LineMetaDataContent::Subway, Color{0xdc8633} }, // 4 OSM: 9609521 WD: Q15900365 29.6, 106.5 x 29.77, 106.8
    { 3917, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x00b5e2} }, // APM OSM: 9611409 WD: Q862929 23.11, 113.3 x 23.14, 113.3
    { 74, 30136, NoLogo, LineMetaDataContent::Subway, Color{0x201747} }, // 21 OSM: 9611531 WD: Q6553110 23.12, 113.4 x 23.29, 113.8
    { 3921, 30157, NoLogo, LineMetaDataContent::Subway, Color{0xc4d600} }, // GF OSM: 9612493 WD: Q3272527 22.96, 113.1 x 23.09, 113.3
    { 27, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x007128} }, // 6 OSM: 9617440 WD: Q15899990 30.49, 114.1 x 30.65, 114.3
    { 42, 30183, NoLogo, LineMetaDataContent::Subway, Color{0xeb7c16} }, // 7 OSM: 9617441 WD: Q11124507 30.32, 114.2 x 30.81, 114.3
    { 44, 30203, 2455, LineMetaDataContent::RapidTransit, Color{0x8d1d81} }, // S5 OSM: 9626749 WD: Q116125185 46.71, 15.42 x 47.07, 15.63
    { 3924, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x97c616} }, // CRL OSM: 9627859 WD: Q3335354 1.311, 103.7 x 1.406, 104
    { 3928, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x734538} }, // TEL OSM: 9627860 WD: Q7795883 1.272, 103.8 x 1.452, 104
    { 42, 30221, NoLogo, LineMetaDataContent::Subway, Color{0x0035ad} }, // 7 OSM: 9629866 WD: Q5938409 22.52, 113.9 x 22.6, 114.1
    { 60, 30244, NoLogo, LineMetaDataContent::Subway, Color{0x00a2e1} }, // 3 OSM: 9629887 WD: Q1065551 22.51, 114 x 22.73, 114.3
    { 63, 30267, 2455, LineMetaDataContent::RapidTransit, Color{0x00983a} }, // S1 OSM: 9631352 WD: Q116125178 47.07, 15.28 x 47.41, 15.42
    { 9, 30285, NoLogo, LineMetaDataContent::Subway, Color{0x920783} }, // 4 OSM: 9632502 WD: Q24835582 28.14, 112.9 x 28.3, 113.1
    { 9, 30315, NoLogo, LineMetaDataContent::Subway, Color{0xa6d30b} }, // 4 OSM: 9633082 WD: Q6553126 30.53, 114 x 30.61, 114.4
    { 55, 30335, NoLogo, LineMetaDataContent::Subway, Color{0xf6d300} }, // 11 OSM: 9633134 WD: Q11124500 30.49, 114.3 x 30.54, 114.7
    { 515, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x83441d} }, // L3 OSM: 9633218 WD: Q5986353 -33.46, -70.73 x -33.37, -70.56
    { 631, 30356, 2455, LineMetaDataContent::RapidTransit, Color{0x9f7fb8} }, // S9 OSM: 9634178 WD: Q116125198 47.41, 15.27 x 47.61, 15.68
    { 47, 30374, 2455, LineMetaDataContent::RapidTransit, Color{0x5cc1d1} }, // S8 OSM: 9634179 WD: Q116125196 47.17, 14.44 x 47.42, 15.28
    { 576, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0067c0} }, // L OSM: 9638873 WD: Q1329642 35.17, 137 x 35.18, 137.1
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x3b6a96} }, // 2 OSM: 9642906 WD: Q15913266 43.83, 125.2 x 43.88, 125.4
    { 19, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x25b7bc} }, // 8 OSM: 9642908 WD: Q15956288 43.95, 125.3 x 44.01, 125.4
    { 6, 30392, NoLogo, LineMetaDataContent::Subway, Color{0x9950b2} }, // 5 OSM: 9645952 WD: Q5926109 22.48, 113.9 x 22.63, 114.1
    { 56, 30415, 4032, LineMetaDataContent::Subway, Color{0xee352e} }, // 1 OSM: 9651536 WD: Q126093 40.7, -74.02 x 40.89, -73.9
    { 1285, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0xf05b94} }, // S20 OSM: 9652168 WD: Q111523342 47.24, 8.536 x 47.38, 8.756
    { 16, 30441, 4032, LineMetaDataContent::Subway, Color{0xee352e} }, // 2 OSM: 9655665 WD: Q126142 40.63, -74.01 x 40.9, -73.85
    { 60, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x571887} }, // 3 OSM: 9656354 WD: Q25824052 22.72, 108.2 x 22.88, 108.4
    { 60, 30467, 4032, LineMetaDataContent::Subway, Color{0xee352e} }, // 3 OSM: 9663807 WD: Q126151 40.66, -74.01 x 40.82, -73.88
    { 3932, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x6c8bc6} }, // D11 OSM: 9672611 51.1, 16.15 x 51.4, 17.04
    { 9, 30493, 4032, LineMetaDataContent::Subway, Color{0x00933c} }, // 4 OSM: 9677108 WD: Q126163 40.66, -74.01 x 40.89, -73.88
    { 410, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xce0037} }, // M OSM: 9677671 WD: Q60608236 -6.292, 106.8 x -6.191, 106.8
    { 507, 30519, 30532, LineMetaDataContent::RapidTransit, Color{0xee343f} }, // L1 OSM: 9678605 WD: Q14543324 -33.91, 151.1 x -33.87, 151.2
    { 576, 30532, 30532, LineMetaDataContent::RapidTransit, Color{0xe4022d} }, // L OSM: 9678765 WD: Q17016515 -32.93, 151.8 x -32.92, 151.8
    { 16, NoLogo, 19668, LineMetaDataContent::Tramway, Color{0xff0000} }, // 2 OSM: 9680853 WD: Q7833150 51.37, -0.2081 x 51.42, -0.02612
    { 9, NoLogo, 19668, LineMetaDataContent::Tramway, Color{0xb5e61d} }, // 4 OSM: 9680854 WD: Q7833148 51.37, -0.2081 x 51.42, -0.04953
    { 6, 30544, 4032, LineMetaDataContent::Subway, Color{0x00933c} }, // 5 OSM: 9682651 WD: Q126177 40.63, -74.01 x 40.9, -73.83
    { 1603, 30570, NoLogo, LineMetaDataContent::RapidTransit, Color{0x783d1d} }, // T6 OSM: 9684395 WD: Q125727482 -33.92, 151 x -33.86, 151
    { 1786, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xd21f2f} }, // T9 OSM: 9697199 WD: Q63653326 -33.9, 151.1 x -33.7, 151.2
    { 1725, 30590, NoLogo, LineMetaDataContent::RapidTransit, Color{0x6e818e} }, // T7 OSM: 9698738 WD: Q4663585 -33.86, 151 x -33.85, 151.1
    { 1809, 30603, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008a45} }, // T8 OSM: 9698883 WD: Q4698965 -34.07, 150.8 x -33.86, 151.2
    { 138, 30616, NoLogo, LineMetaDataContent::Subway, Color{0x846e74} }, // 9 OSM: 9699772 WD: Q5939429 22.51, 113.9 x 22.57, 114.1
    { 2383, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // BLUE OSM: 9701744 WD: Q113480379 53.33, -1.508 x 53.4, -1.344
    { 3936, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x800080} }, // PURP OSM: 9701781 WD: Q113480418 53.34, -1.469 x 53.38, -1.424
    { 3941, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffff00} }, // YELL OSM: 9701824 WD: Q113471568 53.38, -1.51 x 53.42, -1.405
    { 1373, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // TT OSM: 9701873 WD: Q113480455 53.38, -1.469 x 53.44, -1.343
    { 3946, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x006bb6} }, // SIR OSM: 9701910 40.51, -74.25 x 40.64, -74.07
    { 26, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0c7cac} }, // 16 OSM: 9704849 WD: Q122307234 51.08, 17.03 x 51.13, 17.06
    { 145, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe2368c} }, // 14 OSM: 9708096 47.14, 37.54 x 47.18, 37.62
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe2368c} }, // 13 OSM: 9708097 47.14, 37.54 x 47.18, 37.62
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x13b5eb} }, // 8 OSM: 9708100 47.1, 37.51 x 47.12, 37.56
    { 67, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x4f3893} }, // 10 OSM: 9708103 47.1, 37.51 x 47.17, 37.62
    { 60, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf37b24} }, // 3 OSM: 9709247 47.1, 37.51 x 47.12, 37.65
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf37b24} }, // 4 OSM: 9709277 47.1, 37.51 x 47.12, 37.65
    { 3950, 30639, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00843d} }, // Green-E OSM: 9709938 WD: Q172040 42.33, -71.12 x 42.41, -71.06
    { 281, 30667, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf89c1c} }, // T1 OSM: 9709950 WD: Q979843 -33.9, 150.7 x -33.6, 151.2
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x897ab7} }, // 11 OSM: 9712140 47.1, 37.54 x 47.18, 37.65
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffbf00} }, // 5 OSM: 9712141 47.1, 37.54 x 47.15, 37.65
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffbf00} }, // 6 OSM: 9712142 47.1, 37.54 x 47.12, 37.65
    { 138, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0068b2} }, // 9 OSM: 9712143 47.1, 37.54 x 47.18, 37.65
    { 410, 30680, 4032, LineMetaDataContent::Subway, Color{0xff6319} }, // M OSM: 9712349 WD: Q126418 40.7, -74 x 40.76, -73.84
    { 576, 30706, 4032, LineMetaDataContent::Subway, Color{0xa7a9ac} }, // L OSM: 9716997 WD: Q126534 40.65, -74 x 40.74, -73.9
    { 631, NoLogo, 28970, LineMetaDataContent::RapidTransit, Color{0x9589c6} }, // S9 OSM: 9719969 WD: Q3239195 47.35, 7.81 x 47.46, 7.918
    { 3958, 4049, 4032, LineMetaDataContent::Subway, Color{0xb933ad} }, // <7> OSM: 9721629 WD: Q126203 40.74, -74 x 40.76, -73.83
    { 3962, 4179, 4032, LineMetaDataContent::Subway, Color{0x00933c} }, // <6> OSM: 9721630 WD: Q126192 40.71, -74.01 x 40.85, -73.83
    { 3966, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x5d2f0b} }, // 511 OSM: 9724236 WD: Q4639990 43.64, -79.42 x 43.67, -79.4
    { 1363, 14566, NoLogo, LineMetaDataContent::RapidTransit, Color{0x015aa5} }, // T4 OSM: 9724606 WD: Q5330503 -34.14, 151 x -33.87, 151.2
    { 2332, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xef8016} }, // R16 OSM: 9725787 WD: Q125884567 59.08, 24.24 x 59.44, 24.74
    { 3970, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xef8016} }, // R31 OSM: 9725788 WD: Q11026783 59.28, 24.72 x 59.44, 25.61
    { 2364, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xef8016} }, // R14 OSM: 9726762 WD: Q8567799 59.31, 24.06 x 59.44, 24.74
    { 2360, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xef8016} }, // R13 OSM: 9726763 WD: Q125882969 59.31, 24.24 x 59.44, 24.74
    { 3623, 30732, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // 202 OSM: 9729897 WD: Q51912653 51.04, -114.2 x 51.13, -113.9
    { 3591, 30744, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // 201 OSM: 9729912 WD: Q51898028 50.9, -114.2 x 51.13, -114.1
    { 3974, NoLogo, 30755, LineMetaDataContent::RapidTransit, Color{0xfc6357} }, // 22R OSM: 9730137 WD: Q14192100 53.46, -113.5 x 53.57, -113.5
    { 3978, NoLogo, 30755, LineMetaDataContent::RapidTransit, Color{0x3a59a9} }, // 21R OSM: 9730138 WD: Q12054219 53.46, -113.5 x 53.6, -113.4
    { 56, 30788, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // 1 OSM: 9732464 WD: Q56188749 -3.033, 104.7 x -2.894, 104.8
    { 3982, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xed1d24} }, // TWL OSM: 9736531 WD: Q1194568 22.28, 114.1 x 22.38, 114.2
    { 3986, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x7d499d} }, // TKL OSM: 9736612 WD: Q989347 22.29, 114.2 x 22.32, 114.3
    { 326, 30836, 4032, LineMetaDataContent::Subway, Color{0x996633} }, // J OSM: 9747970 WD: Q126484 40.68, -74.01 x 40.72, -73.8
    { 271, 30862, 4032, LineMetaDataContent::Subway, Color{0xff6319} }, // B OSM: 9748435 WD: Q126381 40.58, -74 x 40.87, -73.89
    { 576, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x679f5a} }, // L OSM: 9749315 WD: Q112398566 55.36, 10.34 x 55.41, 10.44
    { 329, 30888, 4032, LineMetaDataContent::Subway, Color{0xff6319} }, // F OSM: 9753684 WD: Q126404 40.58, -74 x 40.77, -73.78
    { 74, 30914, NoLogo, LineMetaDataContent::Subway, Color{0xb2007b} }, // 21 OSM: 9765661 WD: Q11124502 30.65, 114.3 x 30.72, 114.6
    { 321, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0xf17079} }, // S25 OSM: 9767545 WD: Q115743707 47.28, 8.204 x 47.48, 8.341
    { 3990, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0xfece08} }, // S23 OSM: 9767546 WD: Q115743940 47.22, 7.784 x 47.49, 8.308
    { 3524, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0xc89f3b} }, // S26 OSM: 9767547 WD: Q115646660 47.14, 7.907 x 47.4, 8.436
    { 403, 30935, 4032, LineMetaDataContent::Subway, Color{0x0039a6} }, // C OSM: 9767766 WD: Q126358 40.67, -74.01 x 40.84, -73.87
    { 2571, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x13ae99} }, // S14 OSM: 9768340 WD: Q115747591 47.24, 8.041 x 47.39, 8.19
    { 275, 30961, 4032, LineMetaDataContent::Subway, Color{0xff6319} }, // D OSM: 9769161 WD: Q126396 40.58, -74.01 x 40.88, -73.88
    { 535, 30987, 4032, LineMetaDataContent::Subway, Color{0x0039a6} }, // E OSM: 9769302 WD: Q126368 40.7, -74.01 x 40.76, -73.8
    { 3994, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x000000} }, // 751P OSM: 9788142 WD: Q15903000 22.41, 114 x 22.47, 114
    { 3999, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xee3a41} }, // NEC OSM: 9795466 WD: Q7057868 40.22, -74.75 x 40.77, -73.99
    { 1366, 14586, NoLogo, LineMetaDataContent::RapidTransit, Color{0xc4258f} }, // T5 OSM: 9796604 WD: Q5193991 -33.98, 150.8 x -33.6, 151
    { 700, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe73331} }, // T2 OSM: 9797089 WD: Q109610513 49.18, -0.3663 x 49.21, -0.348
    { 1295, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009adf} }, // T3 OSM: 9797090 WD: Q109610514 49.15, -0.364 x 49.19, -0.3411
    { 1580, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf686c3} }, // TRE OSM: 9797671 WD: Q7838588 39.95, -75.2 x 40.22, -74.75
    { 1610, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0xffc709} }, // S31 OSM: 9800222 WD: Q115646663 47.05, 8.548 x 47.16, 8.724
    { 700, 31013, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0097cd} }, // T2 OSM: 9800349 WD: Q44131634 -33.98, 150.8 x -33.82, 151.2
    { 9, 31026, NoLogo, LineMetaDataContent::Subway, Color{0x39b09e} }, // 4 OSM: 9807766 WD: Q15939632 34.14, 108.9 x 34.38, 109
    { 4003, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x8c493a} }, // Cape Flats OSM: 9812222 WD: Q5034802 -34.06, 18.43 x -33.92, 18.5
    { 4014, 31046, NoLogo, LineMetaDataContent::RapidTransit, Color{0x002d9a} }, // C-6 OSM: 9812239 WD: Q5987225 39.44, -0.3834 x 39.99, -0.05181
    { 3423, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00309a} }, // 506 OSM: 9816773 WD: Q3238947 43.65, -79.46 x 43.69, -79.3
    { 843, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00309a} }, // 306 OSM: 9816774 WD: Q3238947 43.65, -79.45 x 43.69, -79.3
    { 4018, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x3096c2} }, // NLR OSM: 9821052 WD: Q56760909 40.73, -74.19 x 40.78, -74.16
    { 4022, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xed1c24} }, // Southern Suburbs OSM: 9822441 WD: Q7570093 -34.19, 18.43 x -33.92, 18.47
    { 4039, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x33bef3} }, // Central Line OSM: 9822444 WD: Q5061363 -34.07, 18.43 x -33.91, 18.71
    { 60, 31064, NoLogo, LineMetaDataContent::Subway, Color{0xeca154} }, // 3 OSM: 9841063 WD: Q862941 22.94, 113.3 x 23.4, 113.4
    { 4052, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0194d7} }, // JFK OSM: 9862004 WD: Q406683 40.64, -73.83 x 40.7, -73.78
    { 59, 31084, NoLogo, LineMetaDataContent::RapidTransit, Color{0x2ca05a} }, // 13 OSM: 9881314 WD: Q6553067 -23.55, -46.64 x -23.43, -46.49
    { 4056, 31096, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // Norte OSM: 9881792 WD: Q10374984 -5.797, -35.42 x -5.632, -35.21
    { 138, 31114, NoLogo, LineMetaDataContent::Subway, Color{0x017cbf} }, // 9 OSM: 9893306 WD: Q11138917 41.72, 123.3 x 41.84, 123.5
    { 639, 31145, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa0cf65} }, // Green OSM: 9897509 WD: Q6925400 37.28, -122 x 37.41, -121.9
    { 359, 31164, NoLogo, LineMetaDataContent::RapidTransit, Color{0x3bb4e6} }, // Blue OSM: 9897510 WD: Q4737344 37.24, -121.9 x 37.41, -121.8
    { 3187, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xee4b95} }, // TL9 OSM: 9898994 WD: Q125903430 51.37, -0.4163 x 51.88, 0.08924
    { 4062, 31182, NoLogo, LineMetaDataContent::LocalTrain, Color{0x59191f} }, // AERA1 City OSM: 9921501 WD: Q1133704 13.69, 100.5 x 13.76, 100.8
    { 138, 31197, NoLogo, LineMetaDataContent::Subway, Color{0x71cc98} }, // 9 OSM: 9924027 WD: Q6553161 23.36, 113.1 x 23.4, 113.3
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xb22222} }, // 1 OSM: 9934001 WD: Q121537929 55.5, 28.58 x 55.53, 28.67
    { 1695, 31217, 226, LineMetaDataContent::RapidTransit, Color{0xc36939} }, // S42 OSM: 9942315 WD: Q15118875 52.46, 13.28 x 52.55, 13.48
    { 676, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffd700} }, // G OSM: 9942698 WD: Q5578772 39.75, -105.1 x 39.81, -105
    { 271, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // B OSM: 9942699 WD: Q19865232 39.75, -105 x 39.82, -105
    { 687, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x57c0e8} }, // A OSM: 9942719 WD: Q5328174 39.75, -105 x 39.85, -104.7
    { 2726, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x939598} }, // Silver OSM: 9946498 32.71, -117.2 x 32.72, -117.2
    { 4074, 31248, NoLogo, LineMetaDataContent::RapidTransit, Color{0x01ab52} }, // 530 OSM: 9946502 WD: Q11681429 32.71, -117.2 x 32.84, -117
    { 4078, 31288, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf7831f} }, // 520 OSM: 9946503 WD: Q597476 32.71, -117.2 x 32.81, -117
    { 403, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf79239} }, // C OSM: 9947502 WD: Q5015067 39.58, -105 x 39.76, -105
    { 275, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008348} }, // D OSM: 9947503 WD: Q5207092 39.58, -105 x 39.75, -105
    { 535, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x552683} }, // E OSM: 9947507 WD: Q5324803 39.52, -105 x 39.76, -104.9
    { 329, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xee3e33} }, // F OSM: 9947520 WD: Q5427493 39.52, -105 x 39.75, -104.9
    { 34, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0075bf} }, // H OSM: 9947525 WD: Q5636307 39.63, -105 x 39.75, -104.8
    { 584, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xb7f037} }, // R OSM: 9947529 WD: Q5515134 39.52, -104.9 x 39.77, -104.8
    { 733, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x37b5a5} }, // W OSM: 9947532 WD: Q7958496 39.72, -105.2 x 39.76, -105
    { 281, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x13a538} }, // T1 OSM: 9953164 WD: Q109610512 49.15, -0.3663 x 49.2, -0.3291
    { 1062, 28823, 28449, LineMetaDataContent::RapidTransit, Color{0x28543d} }, // S12 OSM: 9959066 WD: Q1160881 45.36, 9.158 x 45.55, 9.32
    { 4082, 24523, 19551, LineMetaDataContent::Subway, Color{0x996746} }, // AREX OSM: 9961461 WD: Q487643 37.44, 126.4 x 37.6, 127
    { 4087, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xd1aa00} }, // SAR-VIN OSM: 9963645 WD: Q10318744 -22.68, -43.25 x -22.57, -43.18
    { 4095, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x660066} }, // Belford Roxo OSM: 9963651 WD: Q10318671 -22.91, -43.4 x -22.76, -43.19
    { 4108, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf60619} }, // Deodoro OSM: 9963665 WD: Q18473921 -22.91, -43.39 x -22.85, -43.19
    { 4116, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfa8835} }, // Saracuruna OSM: 9963667 WD: Q10318727 -22.91, -43.31 x -22.68, -43.19
    { 4127, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x5194c4} }, // JRI-PBI OSM: 9963669 WD: Q10318719 -22.64, -43.71 x -22.61, -43.65
    { 4135, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x96333b} }, // SAR-GIM OSM: 9963674 WD: Q10318688 -22.68, -43.25 x -22.52, -42.98
    { 4143, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x6b297e} }, // Parangaba-Mucuripe OSM: 9963934 WD: Q10318709 -3.776, -38.56 x -3.72, -38.48
    { 4162, 31329, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // Oeste OSM: 9963937 WD: Q14325543 -3.77, -38.66 x -3.718, -38.54
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009ee3} }, // 4 OSM: 9964886 WD: Q121253960 52.25, 10.51 x 52.27, 10.56
    { 687, 31367, 1356, LineMetaDataContent::RapidTransit, Color{0x00bfff} }, // A OSM: 9971068 WD: Q2323144 55.46, 12.17 x 55.93, 12.59
    { 871, NoLogo, 31389, LineMetaDataContent::RapidTransit, Color{0xde1d43} }, // LR OSM: 9976617 WD: Q112627789 39.17, -76.68 x 39.5, -76.62
    { 3224, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x808080} }, // B1 OSM: 9987140 40.78, 28.77 x 41.03, 29.41
    { 149, 31423, 5171, LineMetaDataContent::Subway, Color{0xde64a1} }, // 15 OSM: 10011657 WD: Q4226438 55.7, 37.73 x 55.73, 37.93
    { 359, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // Blue OSM: 10012484 WD: Q4929376 35.11, -80.88 x 35.32, -80.73
    { 138, 31448, NoLogo, LineMetaDataContent::Tramway, Color{0x009cdd} }, // 9 OSM: 10015448 WD: Q26197601 53.41, 14.49 x 53.47, 14.55
    { 3763, 29289, NoLogo, LineMetaDataContent::Subway, Color{0x8ba2ae} }, // MG OSM: 10023806 WD: Q283861 35.55, 139.6 x 35.63, 139.7
    { 1466, 31468, NoLogo, LineMetaDataContent::RapidTransit, Color{0xbcbe00} }, // E2 OSM: 10025161 WD: Q104233849 43.27, -2.021 x 43.35, -1.782
    { 3769, 29339, NoLogo, LineMetaDataContent::Subway, Color{0x01aaaa} }, // DT OSM: 10032468 WD: Q1190086 35.47, 139.4 x 36.11, 139.8
    { 56, 31485, NoLogo, LineMetaDataContent::RapidTransit, Color{0xee1b2e} }, // 1 OSM: 10036404 WD: Q5159786 45.4, -75.74 x 45.43, -75.61
    { 4168, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x00a650} }, // OT OSM: 10036880 WD: Q1063832 35.36, 139.2 x 35.67, 139.7
    { 406, 31504, NoLogo, LineMetaDataContent::RapidTransit, Color{0x9ab6d3} }, // S OSM: 10077909 WD: Q56525586 47.15, -122.5 x 47.6, -122.2
    { 680, 31536, NoLogo, LineMetaDataContent::RapidTransit, Color{0x9ab6d3} }, // N OSM: 10077955 WD: Q56525585 47.6, -122.4 x 47.98, -122.2
    { 67, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe3000b} }, // 10 OSM: 10082596 WD: Q121253957 52.25, 10.51 x 52.31, 10.54
    { 16, 31568, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00a0df} }, // 2 OSM: 10084246 WD: Q5328844 47.59, -122.2 x 47.65, -122.1
    { 1713, 31600, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00953b} }, // C-5 OSM: 10089940 WD: Q9026057 39.44, -0.5754 x 39.95, -0.2703
    { 2668, 31614, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfab700} }, // C-2 OSM: 10090322 WD: Q9026042 38.88, -0.7543 x 39.47, -0.378
    { 2161, 31629, NoLogo, LineMetaDataContent::RapidTransit, Color{0x870099} }, // C-3 OSM: 10090427 WD: Q5682717 39.42, -1.203 x 39.57, -0.3669
    { 4171, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa17800} }, // 김포 골드라인 OSM: 10092719 37.56, 126.6 x 37.65, 126.8
    { 138, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 9 OSM: 10092776 WD: Q15222207 63.4, 10.31 x 63.43, 10.39
    { 22, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xd6a461} }, // 18 OSM: 10095918 WD: Q6553089 31.04, 121.5 x 31.34, 121.6
    { 4191, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00214d} }, // 910 OSM: 10098291 55.76, 12.5 x 55.81, 12.53
    { 4195, 30639, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00843d} }, // Green-D OSM: 10099594 WD: Q172031 42.32, -71.25 x 42.38, -71.06
    { 138, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x4ea391} }, // 9 OSM: 10112938 WD: Q121410314 47.12, 27.56 x 47.19, 27.59
    { 145, 31647, NoLogo, LineMetaDataContent::Subway, Color{0xb289bc} }, // 14 OSM: 10131355 WD: Q63781395 34.72, 113.5 x 34.78, 113.5
    { 4203, NoLogo, 4324, LineMetaDataContent::Subway, Color{0x3f48cc} }, // Daxing Airport OSM: 10136967 WD: Q19840478 39.51, 116.3 x 39.85, 116.4
    { 56, 31667, 27588, LineMetaDataContent::Subway, Color{0xa55fc8} }, // 1 OSM: 10149342 WD: Q18654264 36.5, 116.8 x 36.68, 116.9
    { 56, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xcd5c5c} }, // 1 OSM: 10163085 WD: Q66660306 31.63, 119.9 x 31.9, 120
    { 281, NoLogo, 31701, LineMetaDataContent::Tramway, Color{0x363d42} }, // T1 OSM: 10181950 WD: Q48747416 43.93, 4.8 x 43.94, 4.841
    { 4218, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x015698} }, // River Line OSM: 10213690 WD: Q2155505 39.94, -75.13 x 40.22, -74.71
    { 511, NoLogo, 30532, LineMetaDataContent::RapidTransit, Color{0xee343f} }, // L2 OSM: 10214162 WD: Q16927050 -33.92, 151.2 x -33.86, 151.2
    { 1603, 31732, 10083, LineMetaDataContent::Tramway, Color{0x873f98} }, // T6 OSM: 10218859 WD: Q21657685 45.73, 4.835 x 45.75, 4.897
    { 4168, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffe100} }, // OT OSM: 10238058 34.97, 135.7 x 35.07, 135.9
    { 63, NoLogo, 28970, LineMetaDataContent::RapidTransit, Color{0x81cd7b} }, // S1 OSM: 10249610 WD: Q3239193 47.51, 7.591 x 47.57, 8.063
    { 217, NoLogo, 28970, LineMetaDataContent::RapidTransit, Color{0x5ba3d8} }, // S3 OSM: 10249618 WD: Q3239191 47.33, 7.08 x 47.55, 7.918
    { 403, 31752, NoLogo, LineMetaDataContent::Subway, Color{0x00dd00} }, // C OSM: 10258970 WD: Q1057729 34.64, 135.4 x 34.73, 135.8
    { 4229, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x343f4b} }, // CMET OSM: 10271387 WD: Q16927042 -35.28, 149.1 x -35.19, 149.2
    { 4234, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x004792} }, // APT Blue OSM: 10274979 32.86, -96.94 x 32.87, -96.93
    { 515, NoLogo, 31768, LineMetaDataContent::Tramway, Color{0x009640} }, // L3 OSM: 10281452 WD: Q16655742 43.66, 7.194 x 43.71, 7.212
    { 1231, 31790, 2965, LineMetaDataContent::Subway, Color{0xff0a0a} }, // M3 OSM: 10283923 WD: Q1094251 55.67, 12.53 x 55.71, 12.59
    { 4243, 25617, NoLogo, LineMetaDataContent::Subway, Color{0x65b724} }, // BTS Sukhumvit OSM: 10285801 WD: Q4921598 13.57, 100.5 x 13.93, 100.6
    { 507, NoLogo, 31768, LineMetaDataContent::Tramway, Color{0xd20a11} }, // L1 OSM: 10286521 WD: Q3238669 43.7, 7.254 x 43.73, 7.293
    { 329, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // F OSM: 10286522 WD: Q3537109 35.91, 136.2 x 36.07, 136.2
    { 739, 31802, 31827, LineMetaDataContent::RapidTransit, Color{0xed9f2d} }, // D1 OSM: 10309188 WD: Q62091003 55.67, 37.28 x 56.01, 37.59
    { 742, 31840, 31827, LineMetaDataContent::RapidTransit, Color{0xdf477c} }, // D2 OSM: 10309312 WD: Q62091175 55.43, 37.18 x 55.84, 37.74
    { 56, NoLogo, 31865, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 10309985 WD: Q4349061 53.2, 50.13 x 53.21, 50.28
    { 4257, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff88bb} }, // Rochdale - East Didsbury OSM: 10310648 WD: Q113534467 53.41, -2.28 x 53.62, -2.088
    { 4282, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x887766} }, // Shaw and Crompton - East Didsbury OSM: 10310683 WD: Q113534413 53.41, -2.28 x 53.58, -2.089
    { 4316, 31887, NoLogo, LineMetaDataContent::Subway, Color{0xffd700} }, // JB OSM: 10312072 WD: Q1091295 35.61, 139.6 x 35.9, 140.1
    { 2405, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0066bb} }, // Manchester Airport - Manchester Victoria OSM: 10314875 WD: Q22712167 53.37, -2.297 x 53.49, -2.238
    { 4319, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff7700} }, // Ashton-under-Lyne – MediaCityUK OSM: 10320090 53.47, -2.297 x 53.49, -2.098
    { 55, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xe9231b} }, // 11 OSM: 10320583 WD: Q3832713 40.89, 14.21 x 40.97, 14.24
    { 1864, NoLogo, 29894, LineMetaDataContent::Subway, Color{0xf9b428} }, // Gold OSM: 10322047 WD: Q22948672 25.26, 51.44 x 25.29, 51.57
    { 4353, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00ccff} }, // Ashton-under-Lyne – Eccles OSM: 10326857 WD: Q113532665 53.47, -2.335 x 53.49, -2.098
    { 4382, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x881188} }, // Piccadilly - Altrincham OSM: 10328430 WD: Q113534550 53.39, -2.347 x 53.48, -2.23
    { 2854, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffbb00} }, // Bury - Manchester Piccadilly OSM: 10334672 WD: Q113533465 53.48, -2.321 x 53.59, -2.226
    { 4406, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008800} }, // Altrincham – Bury OSM: 10334764 WD: Q113533738 53.39, -2.347 x 53.59, -2.226
    { 4426, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xd32232} }, // ESFECO OSM: 10334823 WD: Q1132053 -22.95, -43.22 x -22.94, -43.2
    { 4433, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff6600} }, // MSC 821 OSM: 10366537 14.17, 121 x 14.62, 121.3
    { 200, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff6600} }, // MSC 1708 OSM: 10366538 14.17, 121 x 14.62, 121.3
    { 4441, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf9cc3e} }, // Kariega CBD OSM: 10374699 WD: Q124409835 -33.96, 25.41 x -33.77, 25.62
    { 4453, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf58220} }, // Berlin OSM: 10374784 WD: Q124413495 -33.02, 27.58 x -32.88, 27.91
    { 56, 31909, 31909, LineMetaDataContent::Subway, Color{0xbf3a35} }, // 1 OSM: 10379854 WD: Q47004909 34.24, 117.1 x 34.27, 117.3
    { 56, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0080bc} }, // 1 OSM: 10380194 WD: Q10893610 36.04, 103.7 x 36.1, 103.9
    { 145, 31925, NoLogo, LineMetaDataContent::Subway, Color{0x00c1d5} }, // 14 OSM: 10381397 WD: Q85884202 34.37, 108.8 x 34.46, 109.1
    { 60, 31946, NoLogo, LineMetaDataContent::Subway, Color{0xf39800} }, // 3 OSM: 10383244 WD: Q10946022 29.65, 121.4 x 29.91, 121.6
    { 4460, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x073686} }, // KS OSM: 10384058 WD: Q855470 35.53, 139.8 x 35.81, 140.4
    { 6, 31967, NoLogo, LineMetaDataContent::Subway, Color{0x0db0c8} }, // 5 OSM: 10386968 WD: Q11102446 30.17, 120 x 30.32, 120.3
    { 6, 31987, NoLogo, LineMetaDataContent::Subway, Color{0x2a5947} }, // 5 OSM: 10387105 WD: Q15928521 34.72, 113.6 x 34.78, 113.8
    { 4210, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffc425} }, // Airport OSM: 10391556 WD: Q409266 -27.47, 153 x -27.39, 153.1
    { 110, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffa500} }, // 22 OSM: 10396259 WD: Q2885972 52.07, 5.112 x 52.09, 5.184
    { 4463, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x96c93c} }, // Taipa OSM: 10402175 WD: Q15935354 22.14, 113.5 x 22.18, 113.6
    { 639, NoLogo, 29894, LineMetaDataContent::Subway, Color{0x009530} }, // Green OSM: 10403427 WD: Q25343673 25.27, 51.35 x 25.32, 51.53
    { 4469, NoLogo, 860, LineMetaDataContent::Tramway, Color{0xdb6198} }, // 305 OSM: 10409526 WD: Q121194029 51.46, 7.152 x 51.48, 7.324
    { 4473, NoLogo, 860, LineMetaDataContent::Tramway, Color{0x40558e} }, // 309 OSM: 10409567 WD: Q121194691 51.44, 7.297 x 51.48, 7.337
    { 4477, NoLogo, 860, LineMetaDataContent::Tramway, Color{0xe28e07} }, // 316 OSM: 10409642 WD: Q121194695 51.48, 7.16 x 51.53, 7.272
    { 515, NoLogo, 30532, LineMetaDataContent::RapidTransit, Color{0xee343f} }, // L3 OSM: 10411683 WD: Q16927050 -33.93, 151.2 x -33.86, 151.2
    { 56, 32006, NoLogo, LineMetaDataContent::Tramway, Color{0x991199} }, // 1 OSM: 10413963 WD: Q15883002 51.2, 4.388 x 51.26, 4.421
    { 4481, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // 4М OSM: 10423669 47.83, 33.34 x 48, 33.5
    { 4485, 6500, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // 3М OSM: 10423670 WD: Q106432004 47.88, 33.39 x 48, 33.5
    { 4489, 22863, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // 2М OSM: 10423671 WD: Q106432003 47.89, 33.39 x 48, 33.5
    { 4493, 22632, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // 1М OSM: 10423672 WD: Q106432002 47.89, 33.39 x 47.96, 33.46
    { 3528, 8579, 226, LineMetaDataContent::RapidTransit, Color{0x006db6} }, // RB 32 OSM: 10432813 WD: Q7388251 51.43, 6.775 x 51.58, 7.459
    { 4497, NoLogo, 32028, LineMetaDataContent::RapidTransit, Color{} }, // Manassas OSM: 10433415 WD: Q6747017 38.73, -77.53 x 38.9, -77
    { 4506, NoLogo, 32028, LineMetaDataContent::RapidTransit, Color{0xe73035} }, // Fredericksburg OSM: 10433416 WD: Q5499211 38.22, -77.46 x 38.9, -77
    { 4521, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00bbb3} }, // CHW OSM: 10433666 WD: Q5093959 39.95, -75.21 x 40.08, -75.15
    { 4525, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa57b27} }, // CHE OSM: 10433667 WD: Q5093950 39.95, -75.21 x 40.08, -75.15
    { 4529, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x91456c} }, // AIR OSM: 10433668 WD: Q4698916 39.87, -75.26 x 39.96, -75.16
    { 4533, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x775ca7} }, // CYN OSM: 10433669 WD: Q5200188 39.95, -75.23 x 40.01, -75.17
    { 3278, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xee5067} }, // NOR OSM: 10433670 WD: Q6747157 39.95, -75.35 x 40.12, -75.15
    { 4537, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0081c5} }, // ELW OSM: 10433671 WD: Q6805374 39.89, -75.46 x 39.98, -75.15
    { 4541, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x8ed16a} }, // NWK OSM: 10433672 WD: Q8022734 39.67, -75.75 x 39.96, -75.16
    { 1323, 32057, 226, LineMetaDataContent::RapidTransit, Color{0xc72a80} }, // L5 OSM: 10443588 WD: Q104416090 46.18, 5.999 x 46.22, 6.144
    { 1327, 32089, 226, LineMetaDataContent::RapidTransit, Color{0x00b3b9} }, // L6 OSM: 10447940 WD: Q104416091 46.1, 5.821 x 46.22, 6.144
    { 16, 32121, NoLogo, LineMetaDataContent::Subway, Color{0x00643a} }, // 2 OSM: 10458608 WD: Q20063925 26.04, 119.1 x 26.11, 119.4
    { 503, 32140, 226, LineMetaDataContent::RapidTransit, Color{0xdc911b} }, // L4 OSM: 10464491 WD: Q104416089 46.17, 6.121 x 46.32, 6.237
    { 55, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x3850a2} }, // 11 OSM: 10467354 WD: Q15944362 36.1, 120.5 x 36.48, 120.8
    { 59, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x00ab84} }, // 13 OSM: 10467728 WD: Q15937512 35.67, 119.7 x 35.98, 120.2
    { 4545, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // Sado OSM: 10484570 WD: Q1314068 38.51, -9.08 x 38.66, -8.838
    { 231, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00ace7} }, // 17 OSM: 10486182 WD: Q3238620 46.19, 6.125 x 46.2, 6.232
    { 687, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe2121a} }, // A OSM: 10486983 WD: Q3239053 47.83, 1.9 x 47.93, 1.939
    { 16, NoLogo, 27690, LineMetaDataContent::Subway, Color{0x4bb134} }, // 2 OSM: 10488738 WD: Q24838989 24.48, 117.9 x 24.58, 118.2
    { 60, 32172, NoLogo, LineMetaDataContent::Subway, Color{0xf57b00} }, // 3 OSM: 10488912 WD: Q6112757 31.26, 120.5 x 31.37, 120.8
    { 60, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x098137} }, // 3 OSM: 10488951 WD: Q17023374 31.69, 117.1 x 31.93, 117.4
    { 700, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x6a911a} }, // T2 OSM: 10490757 30.69, 103.8 x 30.83, 104
    { 271, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x762a80} }, // B OSM: 10494114 WD: Q3239067 47.9, 1.854 x 47.91, 1.977
    { 515, 32193, 226, LineMetaDataContent::RapidTransit, Color{0x6c9d40} }, // L3 OSM: 10505987 WD: Q104416088 45.91, 6.121 x 46.32, 6.703
    { 4550, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x6a911a} }, // T2B OSM: 10506169 30.73, 104 x 30.8, 104
    { 56, 32225, NoLogo, LineMetaDataContent::Subway, Color{0xe82311} }, // 1 OSM: 10507454 WD: Q76339003 40.78, 111.6 x 40.86, 111.8
    { 4559, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xce8e00} }, // Hempstead OSM: 10511736 WD: Q5712708 40.68, -73.97 x 40.73, -73.62
    { 4569, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xc60c30} }, // Port Washington OSM: 10511737 WD: Q7231025 40.74, -73.99 x 40.83, -73.69
    { 4585, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x006983} }, // Montauk OSM: 10511738 WD: Q4044495 40.7, -73.99 x 41.05, -71.95
    { 454, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00af3f} }, // Oyster Bay OSM: 10511739 WD: Q7116314 40.7, -73.99 x 40.88, -73.53
    { 4593, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0039a6} }, // Port Jefferson OSM: 10511740 WD: Q7230720 40.7, -73.99 x 40.94, -73.05
    { 4554, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00a1de} }, // West Hempstead OSM: 10511742 WD: Q7985342 40.66, -73.97 x 40.71, -73.64
    { 60, 32247, 27588, LineMetaDataContent::Subway, Color{0x3f63e6} }, // 3 OSM: 10513363 WD: Q24837836 36.62, 117.1 x 36.77, 117.2
    { 4608, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x4ca585} }, // TGM1 OSM: 10519279 WD: Q80912905 22.9, 112.8 x 22.95, 112.9
    { 507, 32281, 226, LineMetaDataContent::RapidTransit, Color{0xbf3527} }, // L1 OSM: 10521809 WD: Q104416086 46.17, 6.121 x 46.4, 6.581
    { 511, 32313, 226, LineMetaDataContent::RapidTransit, Color{0x0085c4} }, // L2 OSM: 10526246 WD: Q104416087 45.9, 6.116 x 46.32, 6.362
    { 6, 32345, NoLogo, LineMetaDataContent::Subway, Color{0xbb29bb} }, // 5 OSM: 10526316 WD: Q22100474 30.45, 104 x 30.83, 104.1
    { 4613, 32355, NoLogo, LineMetaDataContent::LocalTrain, Color{0xe31937} }, // Hartford Line OSM: 10530881 WD: Q7008596 41.3, -72.93 x 42.11, -72.58
    { 4627, 32385, NoLogo, LineMetaDataContent::LongDistanceTrain, Color{0x007dbe} }, // IR 65 OSM: 10533323 WD: Q116053231 46.95, 7.24 x 47.13, 7.47
    { 700, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x229922} }, // T2 OSM: 10547015 WD: Q124261209 51.02, 3.699 x 51.11, 3.773
    { 138, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xef7c00} }, // 9 OSM: 10547655 48.34, 10.89 x 48.37, 10.9
    { 687, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe3028c} }, // A OSM: 10551319 WD: Q93096868 48.38, -4.556 x 48.43, -4.444
    { 145, 32400, NoLogo, LineMetaDataContent::Subway, Color{0x827a04} }, // 14 OSM: 10557252 WD: Q6553074 31.22, 121.3 x 31.27, 121.6
    { 1422, 32410, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf79729} }, // Orange OSM: 10561837 WD: Q81533754 37.36, -122.1 x 37.42, -121.8
    { 4633, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x80276c} }, // CR-Greenbush OSM: 10563012 WD: Q5603780 42.18, -71.06 x 42.35, -70.74
    { 4646, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x80276c} }, // CR-Worcester OSM: 10563013 WD: Q801994 42.23, -71.8 x 42.36, -71.06
    { 4659, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x80276c} }, // CR-Fairmount OSM: 10563014 WD: Q5430648 42.24, -71.13 x 42.35, -71.05
    { 4672, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x80276c} }, // CR-Haverhill OSM: 10563015 WD: Q172528 42.37, -71.18 x 42.82, -71.06
    { 4685, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x80276c} }, // CR-Lowell OSM: 10563016 WD: Q172536 42.37, -71.32 x 42.64, -71.06
    { 4695, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x80276c} }, // CR-Middleborough OSM: 10563017 WD: Q104818537 41.88, -71.06 x 42.35, -70.92
    { 4712, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x80276c} }, // CR-Needham OSM: 10563018 WD: Q6986548 42.27, -71.24 x 42.35, -71.06
    { 4723, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x80276c} }, // CR-Newburyport OSM: 10563019 WD: Q172516 42.37, -71.08 x 42.8, -70.63
    { 4738, NoLogo, 32430, LineMetaDataContent::RapidTransit, Color{0x0171ce} }, // 91/Perris Valley OSM: 10563416 WD: Q4645737 33.76, -118.2 x 34.06, -117.2
    { 4755, NoLogo, 32430, LineMetaDataContent::RapidTransit, Color{0xbd295b} }, // Inland Empire-Orange County OSM: 10563417 WD: Q6380515 33.19, -117.9 x 34.1, -117.3
    { 4769, NoLogo, 32430, LineMetaDataContent::RapidTransit, Color{0xff7602} }, // Orange County OSM: 10563418 WD: Q5220500 33.19, -118.2 x 34.06, -117.4
    { 4783, NoLogo, 32430, LineMetaDataContent::RapidTransit, Color{0x682e85} }, // Riverside OSM: 10563419 WD: Q4801982 33.96, -118.2 x 34.06, -117.4
    { 4793, NoLogo, 32430, LineMetaDataContent::RapidTransit, Color{0xa32236} }, // San Bernardino OSM: 10563420 WD: Q4798016 34.05, -118.2 x 34.11, -117.2
    { 4808, NoLogo, 32430, LineMetaDataContent::RapidTransit, Color{0xf6a706} }, // Ventura County OSM: 10563421 WD: Q4132754 34.05, -119.2 x 34.29, -118.2
    { 4823, NoLogo, 32430, LineMetaDataContent::RapidTransit, Color{0x1d9d02} }, // Antelope Valley OSM: 10563422 WD: Q4162507 34.05, -118.5 x 34.7, -118.1
    { 3431, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // Blue Line OSM: 10563564 25.31, 51.42 x 25.32, 51.43
    { 4839, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x4ba7a6} }, // Turquoise Line OSM: 10563806 25.41, 51.49 x 25.43, 51.5
    { 3857, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xdd722d} }, // Orange Line OSM: 10563807 25.37, 51.49 x 25.43, 51.53
    { 4854, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xd64488} }, // Purple Line OSM: 10563808 25.37, 51.49 x 25.42, 51.53
    { 2680, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // Central OSM: 10570207 WD: Q10329283 -7.232, -39.41 x -7.206, -39.3
    { 56, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x8a8988} }, // 1 OSM: 10570395 WD: Q10318643 -5.111, -42.82 x -5.08, -42.74
    { 1614, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x008000} }, // CBTU OSM: 10570416 WD: Q18484877 -7.131, -34.98 x -6.974, -34.83
    { 4056, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // Norte OSM: 10570453 -3.683, -40.37 x -3.663, -40.34
    { 2376, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // Sul OSM: 10570461 -3.699, -40.36 x -3.682, -40.33
    { 4866, 32449, NoLogo, LineMetaDataContent::LocalTrain, Color{0xdf091d} }, // RE 1 OSM: 10573474 WD: Q322058 48.14, 11.08 x 49.45, 11.57
    { 4871, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // 550 OSM: 10577109 WD: Q113084731 30.26, -97.86 x 30.59, -97.7
    { 4875, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe87308} }, // R17 OSM: 10578984 41.09, 1.145 x 41.4, 2.194
    { 16, 32465, 13598, LineMetaDataContent::Tramway, Color{0xf18e00} }, // 2 OSM: 10579671 WD: Q3238812 43.57, 3.831 x 43.65, 3.931
    { 60, 32475, 13598, LineMetaDataContent::Tramway, Color{0xcbd300} }, // 3 OSM: 10579672 WD: Q3238911 43.56, 3.81 x 43.62, 3.964
    { 56, 32485, 13598, LineMetaDataContent::Tramway, Color{0x005ba1} }, // 1 OSM: 10579673 WD: Q3238667 43.6, 3.817 x 43.64, 3.92
    { 4879, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xee293d} }, // TEX OSM: 10580066 WD: Q28228164 32.75, -97.34 x 32.94, -97.04
    { 4883, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008c99} }, // 630 OSM: 10588005 32.72, -117.4 x 33.19, -117.2
    { 4887, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008c99} }, // 656 OSM: 10588005 32.72, -117.4 x 33.19, -117.2
    { 4891, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008c99} }, // 636 OSM: 10588005 32.72, -117.4 x 33.19, -117.2
    { 4895, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008c99} }, // 662 OSM: 10588005 32.72, -117.4 x 33.19, -117.2
    { 4899, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008c99} }, // 640 OSM: 10588005 32.72, -117.4 x 33.19, -117.2
    { 1981, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008c99} }, // 654 OSM: 10588005 32.72, -117.4 x 33.19, -117.2
    { 4903, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffa300} }, // BTANIC OSM: 10601134 WD: Q113613430 -34.92, 138.6 x -34.91, 138.6
    { 4910, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x55502b} }, // UP Express OSM: 10608917 WD: Q497520 43.64, -79.62 x 43.71, -79.38
    { 3512, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7d4d31} }, // S15 OSM: 10615459 47.46, 8.895 x 47.56, 9.041
    { 1046, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x9285bf} }, // S10 OSM: 10615934 47.46, 9.021 x 47.57, 9.38
    { 4921, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x794400} }, // Stouffville OSM: 10624851 WD: Q3239216 43.64, -79.38 x 44, -79.23
    { 4933, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x009ac7} }, // Richmond Hill OSM: 10624852 WD: Q3239183 43.64, -79.43 x 43.88, -79.32
    { 74, 32495, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf57f25} }, // 21 OSM: 10624853 WD: Q3239156 43.52, -79.87 x 43.67, -79.38
    { 4947, 32495, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf57f25} }, // MI OSM: 10624853 WD: Q3239156 43.52, -79.87 x 43.67, -79.38
    { 4950, 32514, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00853f} }, // Kitchener OSM: 10624854 WD: Q3239126 43.46, -80.49 x 43.71, -79.38
    { 4960, 32536, NoLogo, LineMetaDataContent::RapidTransit, Color{0x003768} }, // Barrie OSM: 10624855 WD: Q3239071 43.64, -79.69 x 44.37, -79.38
    { 4967, 32555, NoLogo, LineMetaDataContent::RapidTransit, Color{0xee3124} }, // Lakeshore East OSM: 10624856 WD: Q3239134 43.64, -79.38 x 43.87, -78.89
    { 1090, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x8c86bf} }, // S28 OSM: 10644936 WD: Q115747154 47.29, 7.939 x 47.39, 8.172
    { 4982, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0072bc} }, // South Coast OSM: 10646254 WD: Q124416304 -30.36, 30.71 x -29.84, 31.02
    { 5004, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa6ce39} }, // West OSM: 10646666 -29.92, 30.97 x -29.84, 31.05
    { 906, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00baf1} }, // New Main OSM: 10646667 WD: Q124416307 -29.91, 30.59 x -29.73, 31.02
    { 5009, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00652e} }, // Umlazi OSM: 10646668 WD: Q124416305 -29.97, 30.87 x -29.88, 31.05
    { 5016, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf9cc3e} }, // Crossmoor OSM: 10646669 WD: Q124416311 -29.95, 30.86 x -29.84, 31.02
    { 5026, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xee1d23} }, // kwaMashu OSM: 10646670 WD: Q124416310 -29.97, 30.87 x -29.74, 31.03
    { 5035, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x6e2527} }, // Old Main OSM: 10646671 WD: Q124416308 -29.91, 30.86 x -29.82, 31.02
    { 4994, 32582, NoLogo, LineMetaDataContent::RapidTransit, Color{0x9f142c} }, // Lakeshore West OSM: 10647448 WD: Q3239135 43.25, -79.89 x 43.65, -79.38
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe86220} }, // 2 OSM: 10647637 WD: Q122382718 49.77, 18.22 x 49.85, 18.29
    { 109, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xb41d8e} }, // S22 OSM: 10650450 47.39, 9.359 x 47.43, 9.462
    { 970, 32609, NoLogo, LineMetaDataContent::Subway, Color{0xfedb00} }, // Y OSM: 10658528 WD: Q5971413 24.98, 121.5 x 25.06, 121.5
    { 3732, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x00ffff} }, // Aqua Line OSM: 10659365 WD: Q62051025 21.11, 79 x 21.15, 79.15
    { 634, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00652e} }, // Dark Green OSM: 10670621 WD: Q124425757 -26.68, 27.82 x -26.2, 28.09
    { 364, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf9cc3e} }, // Yellow OSM: 10670624 WD: Q124425811 -26.34, 27.39 x -26.2, 28.04
    { 5044, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // Metrorail OSM: 10670933 WD: Q124429578 -26.23, 27.94 x -26.21, 28.17
    { 5044, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xed038c} }, // Metrorail OSM: 10671112 WD: Q124425732 -25.73, 28.28 x -25.72, 28.36
    { 60, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe5097f} }, // 3 OSM: 10685120 WD: Q122382719 49.77, 18.17 x 49.83, 18.27
    { 2571, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf7941d} }, // S14 OSM: 10685821 47.56, 9.102 x 47.66, 9.192
    { 5054, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xadd8e6} }, // LRT OSM: 10693161 WD: Q65762187 -6.193, 106.9 x -6.155, 106.9
    { 41, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf26531} }, // S7 OSM: 10696321 47.48, 9.102 x 47.57, 9.51
    { 2194, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x3e6c01} }, // 102 OSM: 10696526 39.91, -75.3 x 39.96, -75.26
    { 2129, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x3e6c01} }, // 101 OSM: 10696527 39.91, -75.39 x 39.96, -75.26
    { 217, 32633, 2455, LineMetaDataContent::RapidTransit, Color{0xe6007e} }, // S3 OSM: 10699280 WD: Q116125181 46.95, 15.42 x 47.1, 16.02
    { 67, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x3e6c01} }, // 10 OSM: 10703006 WD: Q7389780 39.95, -75.25 x 39.98, -75.16
    { 2114, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x3e6c01} }, // 34 OSM: 10703188 WD: Q7389786 39.94, -75.25 x 39.96, -75.16
    { 1222, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x3e6c01} }, // 36 OSM: 10703676 WD: Q7389789 39.9, -75.24 x 39.96, -75.16
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x3e6c01} }, // 11 OSM: 10705415 WD: Q7389783 39.92, -75.26 x 39.96, -75.16
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x3e6c01} }, // 13 OSM: 10705526 WD: Q7389784 39.92, -75.26 x 39.96, -75.16
    { 51, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x5da526} }, // S2 OSM: 10724094 WD: Q115646644 46.82, 8.496 x 47.45, 9.063
    { 217, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0xf58220} }, // S3 OSM: 10724334 WD: Q115646645 47, 8.297 x 47.1, 8.632
    { 306, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0xa62b48} }, // S4 OSM: 10736536 WD: Q115646646 46.91, 8.3 x 47.05, 8.398
    { 44, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0xee3d96} }, // S5 OSM: 10736575 WD: Q115646648 46.84, 8.185 x 47.05, 8.314
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009846} }, // 4 OSM: 10741026 WD: Q122382720 49.79, 18.18 x 49.85, 18.32
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x9d9e9e} }, // 6 OSM: 10743087 WD: Q122382722 49.77, 18.22 x 49.85, 18.29
    { 290, 32651, 2455, LineMetaDataContent::RapidTransit, Color{0xf39200} }, // S6 OSM: 10748876 WD: Q116125188 46.72, 15.21 x 47.07, 15.48
    { 433, 32669, 7769, LineMetaDataContent::Subway, Color{0x5d9732} }, // M2 OSM: 10760559 WD: Q2519385 45.4, 9.145 x 45.55, 9.437
    { 1231, 32689, 7769, LineMetaDataContent::Subway, Color{0xfdb813} }, // M3 OSM: 10788272 WD: Q2519355 45.43, 9.163 x 45.53, 9.257
    { 352, 32709, 7769, LineMetaDataContent::Subway, Color{0xee2e24} }, // M1 OSM: 10803053 WD: Q2400801 45.46, 9.084 x 45.54, 9.239
    { 700, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffcd00} }, // T2 OSM: 10807282 WD: Q122222970 53.45, 18.72 x 53.5, 18.77
    { 1295, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00cdff} }, // T3 OSM: 10807448 WD: Q122222945 53.45, 18.72 x 53.49, 18.76
    { 234, NoLogo, 32729, LineMetaDataContent::RapidTransit, Color{0x644215} }, // S50 OSM: 10816434 WD: Q110305283 46.48, 6.836 x 46.62, 7.087
    { 2088, NoLogo, 32729, LineMetaDataContent::RapidTransit, Color{0x005f6e} }, // S30 OSM: 10816437 WD: Q115701424 46.78, 6.638 x 46.85, 7.154
    { 1860, NoLogo, 32729, LineMetaDataContent::RapidTransit, Color{0x6e9ed4} }, // S21 OSM: 10816438 WD: Q110305258 46.69, 6.911 x 47, 7.154
    { 1285, NoLogo, 32729, LineMetaDataContent::RapidTransit, Color{0x24318a} }, // S20 OSM: 10816439 WD: Q115702408 46.69, 6.911 x 47.01, 7.154
    { 5058, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00975f} }, // 5A OSM: 10837439 WD: Q121317834 49.48, 8.463 x 49.51, 8.596
    { 149, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x3fbfaa} }, // 15 OSM: 10899251 47.1, 37.62 x 47.12, 37.65
    { 8, 32755, 2965, LineMetaDataContent::Subway, Color{0x36b6f1} }, // M4 OSM: 10925800 WD: Q88965328 55.67, 12.56 x 55.71, 12.6
    { 5061, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x4682b4} }, // Airside E OSM: 10956203 WD: Q121502077 27.98, -82.54 x 27.98, -82.54
    { 44, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x8dc63f} }, // S5 OSM: 10958455 WD: Q108602185 47.4, 9.102 x 47.57, 9.642
    { 5071, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x4682b4} }, // SKY OSM: 10958822 WD: Q121502085 27.96, -82.54 x 27.98, -82.53
    { 1062, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x6a489d} }, // S12 OSM: 10961967 WD: Q106455671 46.85, 9.441 x 47.05, 9.562
    { 246, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x38b54a} }, // S24 OSM: 10963118 47.36, 9.451 x 47.38, 9.538
    { 1860, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x089690} }, // S21 OSM: 10963311 WD: Q106455085 47.33, 9.359 x 47.43, 9.462
    { 3639, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffa500} }, // 1720 OSM: 10976185 13.13, 123.2 x 13.62, 123.8
    { 4073, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffa500} }, // 1530 OSM: 10976234 13.59, 123 x 13.77, 123.2
    { 5075, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffa500} }, // 1645 OSM: 10976234 13.59, 123 x 13.77, 123.2
    { 680, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x9f26b4} }, // N OSM: 11004619 WD: Q19877104 39.75, -105 x 39.92, -104.9
    { 5080, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xee0011} }, // The Trafford Centre – Cornbrook OSM: 11041584 WD: Q113532624 53.46, -2.348 x 53.47, -2.267
    { 567, 32767, NoLogo, LineMetaDataContent::Subway, Color{0x0000ff} }, // TS OSM: 11065563 WD: Q2913662 35.51, 139.4 x 36.11, 139.8
    { 2507, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xee1d23} }, // 505 OSM: 11065833 WD: Q3238946 43.65, -79.45 x 43.68, -79.35
    { 26, 32801, NoLogo, LineMetaDataContent::Subway, Color{0xffb25b} }, // 16 OSM: 11076299 WD: Q22099544 30.2, 119.7 x 30.27, 120
    { 34, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x303888} }, // H OSM: 11093106 WD: Q5654835 18.94, 72.83 x 19.12, 73.12
    { 5114, NoLogo, 25191, LineMetaDataContent::Subway, Color{0x252525} }, // JSQ–33 via HOB OSM: 11100813 WD: Q1931652 40.72, -74.06 x 40.75, -73.99
    { 67, 32822, NoLogo, LineMetaDataContent::Subway, Color{0x62aa3c} }, // 10 OSM: 11123255 WD: Q20688706 41.71, 123.3 x 41.86, 123.5
    { 406, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffc0cb} }, // S OSM: 11135401 WD: Q5364907 34.32, 134.1 x 34.34, 134.2
    { 572, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffff00} }, // K OSM: 11135402 WD: Q5371397 34.19, 133.8 x 34.35, 134.1
    { 680, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // N OSM: 11135412 WD: Q5364831 34.27, 134 x 34.35, 134.2
    { 227, NoLogo, 32854, LineMetaDataContent::RapidTransit, Color{0xa05ea6} }, // 27 OSM: 11151437 WD: Q106813236 59.35, 18.04 x 59.66, 18.27
    { 1091, NoLogo, 32854, LineMetaDataContent::RapidTransit, Color{0xa05ea6} }, // 28 OSM: 11151439 WD: Q106813260 59.35, 18.04 x 59.48, 18.31
    { 1059, NoLogo, 32854, LineMetaDataContent::RapidTransit, Color{0xa05ea6} }, // 29 OSM: 11151441 WD: Q106813276 59.35, 18.04 x 59.43, 18.1
    { 63, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x000000} }, // S1 OSM: 11183563 47.15, 9.601 x 47.55, 9.817
    { 51, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x000000} }, // S2 OSM: 11185452 WD: Q108086901 47.16, 9.078 x 47.48, 9.651
    { 217, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x000000} }, // S3 OSM: 11185510 47.45, 9.637 x 47.55, 9.754
    { 306, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x000000} }, // S4 OSM: 11185615 47.08, 9.812 x 47.16, 9.918
    { 41, 32889, 2455, LineMetaDataContent::RapidTransit, Color{0xbe1622} }, // S7 OSM: 11185888 WD: Q116125192 46.96, 15.08 x 47.07, 15.42
    { 85, 32907, 2455, LineMetaDataContent::RapidTransit, Color{0xf39200} }, // S61 OSM: 11185889 WD: Q116125190 46.72, 15.21 x 47.07, 15.42
    { 5131, 32926, 4032, LineMetaDataContent::Subway, Color{0xff6319} }, // <F> OSM: 11248274 WD: Q111495096 40.58, -74 x 40.77, -73.78
    { 60, 32953, NoLogo, LineMetaDataContent::Subway, Color{0xabcd03} }, // 3 OSM: 11257190 WD: Q17030673 28.1, 112.9 x 28.25, 113.1
    { 6, 32983, NoLogo, LineMetaDataContent::Subway, Color{0xffe200} }, // 5 OSM: 11257230 WD: Q18668926 28.1, 113 x 28.28, 113.1
    { 5135, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00aeef} }, // HBLR OSM: 11269271 WD: Q114054273 40.65, -74.13 x 40.79, -74.01
    { 5140, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xae1ea3} }, // D10 OSM: 11270864 51.1, 14.97 x 51.29, 17.04
    { 1695, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x9a6b31} }, // S42 OSM: 11277216 WD: Q106451501 47.28, 8.204 x 47.44, 8.539
    { 60, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 3 OSM: 11279461 46.95, 31.98 x 46.98, 32.03
    { 1231, 33013, 21437, LineMetaDataContent::Subway, Color{0x008000} }, // M3 OSM: 11299964 WD: Q12289405 42.68, 23.24 x 42.7, 23.35
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff000c} }, // 1 OSM: 11321268 WD: Q16347621 56.94, 24.01 x 56.99, 24.24
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff000c} }, // 2 OSM: 11321421 WD: Q16348252 56.94, 24.05 x 56.96, 24.12
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff000c} }, // 5 OSM: 11321694 WD: Q16349936 56.94, 24.01 x 57.02, 24.13
    { 42, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff000c} }, // 7 OSM: 11321946 WD: Q16350085 56.91, 24.1 x 56.96, 24.19
    { 67, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff000c} }, // 10 OSM: 11322063 WD: Q13098696 56.91, 24.08 x 56.95, 24.14
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff000c} }, // 11 OSM: 11322567 WD: Q16347642 56.95, 24.1 x 57.01, 24.17
    { 149, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x3e6c01} }, // 15 OSM: 11328858 WD: Q3444107 39.96, -75.25 x 39.98, -75.13
    { 5144, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xda291c} }, // Mattapan OSM: 11359791 WD: Q172144 42.27, -71.09 x 42.28, -71.06
    { 5153, 33038, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00843d} }, // Green-B OSM: 11359792 WD: Q172011 42.34, -71.17 x 42.36, -71.06
    { 5161, 33068, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00843d} }, // Green-C OSM: 11359793 WD: Q172022 42.34, -71.15 x 42.36, -71.06
    { 5169, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x73757d} }, // Metro OSM: 11364344 WD: Q3333824 42.88, -78.88 x 42.95, -78.82
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf10000} }, // 1 OSM: 11365072 WD: Q121507132 39.01, 125.7 x 39.03, 125.7
    { 359, NoLogo, 6385, LineMetaDataContent::RapidTransit, Color{0x0000f8} }, // Blue OSM: 11366428 WD: Q4929372 38.59, -90.35 x 38.65, -90.05
    { 82, NoLogo, 6578, LineMetaDataContent::Tramway, Color{0xce1417} }, // 63 OSM: 11375919 WD: Q123168072 59.93, 30.44 x 59.96, 30.49
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8b0000} }, // 2 OSM: 11376584 WD: Q124639342 47.88, 33.29 x 47.91, 33.43
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8b0000} }, // 1 OSM: 11376585 WD: Q124639341 47.88, 33.3 x 47.93, 33.43
    { 2668, 18482, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00874d} }, // C-2 OSM: 11378343 WD: Q5987206 37.39, -6.01 x 37.45, -5.95
    { 649, 23598, NoLogo, LineMetaDataContent::LocalTrain, Color{0x619bc1} }, // C-1 OSM: 11378450 WD: Q5987193 37.18, -5.98 x 37.66, -5.53
    { 2161, 33098, NoLogo, LineMetaDataContent::LocalTrain, Color{0xff061d} }, // C-3 OSM: 11382024 WD: Q5987212 37.39, -5.975 x 37.93, -5.704
    { 3537, 33123, NoLogo, LineMetaDataContent::RapidTransit, Color{0x991b87} }, // C-4 OSM: 11382119 WD: Q5987216 37.34, -5.98 x 37.42, -5.934
    { 110, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8b0000} }, // 22 OSM: 11382749 WD: Q124639356 47.88, 33.29 x 47.91, 33.46
    { 60, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8b0000} }, // 3 OSM: 11383230 WD: Q124639344 47.87, 33.29 x 47.91, 33.44
    { 1713, 33150, NoLogo, LineMetaDataContent::LocalTrain, Color{0x053388} }, // C-5 OSM: 11384993 WD: Q5987218 37.33, -6.208 x 37.45, -5.95
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8b0000} }, // 5 OSM: 11478143 WD: Q124639346 47.83, 33.34 x 47.9, 33.43
    { 322, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8b0000} }, // 25 OSM: 11478144 WD: Q124639358 47.83, 33.34 x 47.91, 33.46
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8b0000} }, // 4 OSM: 11478145 WD: Q124639345 47.83, 33.29 x 47.91, 33.36
    { 41, 33182, 28449, LineMetaDataContent::RapidTransit, Color{0xed2a81} }, // S7 OSM: 11479781 WD: Q26878568 45.48, 9.184 x 45.86, 9.399
    { 63, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x11385b} }, // S1 OSM: 11482970 WD: Q43285793 39.7, 116.1 x 39.9, 116.7
    { 2593, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x55c5d0} }, // S81 OSM: 11484467 47.39, 9.275 x 47.42, 9.369
    { 5175, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x00b9f2} }, // S82 OSM: 11484468 WD: Q108602785 47.42, 9.367 x 47.46, 9.4
    { 2668, 18482, NoLogo, LineMetaDataContent::LocalTrain, Color{0x00874d} }, // C-2 OSM: 11488015 WD: Q5987203 36.7, -4.724 x 36.82, -4.427
    { 649, 23598, NoLogo, LineMetaDataContent::RapidTransit, Color{0x619bc1} }, // C-1 OSM: 11488016 WD: Q25411554 36.54, -4.624 x 36.72, -4.427
    { 39, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x4b0082} }, // T OSM: 11490693 WD: Q7833528 18.99, 72.97 x 19.19, 73.12
    { 851, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0092db} }, // 301 OSM: 11494376 43.42, -80.55 x 43.5, -80.44
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x26ff00} }, // 2 OSM: 11495026 WD: Q121506603 38.98, 125.7 x 39.04, 125.8
    { 60, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff00ef} }, // 3 OSM: 11495033 WD: Q121506943 38.97, 125.7 x 39.05, 125.7
    { 42, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8b0000} }, // 7 OSM: 11495622 WD: Q124639348 47.83, 33.35 x 47.9, 33.43
    { 227, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8b0000} }, // 27 OSM: 11495623 WD: Q124639359 47.83, 33.35 x 47.91, 33.46
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8b0000} }, // 6 OSM: 11495624 WD: Q124639347 47.83, 33.29 x 47.91, 33.38
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8b0000} }, // 8 OSM: 11495625 WD: Q124639349 47.83, 33.34 x 47.84, 33.38
    { 138, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8b0000} }, // 9 OSM: 11495626 WD: Q124639350 47.87, 33.38 x 47.91, 33.46
    { 649, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff061d} }, // C-1 OSM: 11498246 36.46, -6.288 x 36.75, -6.066
    { 5179, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff061d} }, // C-1a OSM: 11498247 36.53, -6.206 x 36.54, -6.194
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8b0000} }, // 11 OSM: 11500038 WD: Q124639352 47.83, 33.35 x 47.91, 33.39
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8b0000} }, // 12 OSM: 11500039 WD: Q124639354 47.87, 33.38 x 47.91, 33.44
    { 145, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8b0000} }, // 14 OSM: 11500040 WD: Q124639355 47.9, 33.38 x 47.91, 33.46
    { 67, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8b0000} }, // 10 OSM: 11500041 WD: Q124639351 47.83, 33.34 x 47.91, 33.39
    { 5184, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x97c93d} }, // WEST OSM: 11501325 WD: Q7988020 -36.91, 174.6 x -36.84, 174.8
    { 5189, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00aeef} }, // ONE OSM: 11501967 WD: Q28180487 -36.93, 174.8 x -36.87, 174.8
    { 290, NoLogo, 28970, LineMetaDataContent::RapidTransit, Color{0xe9583f} }, // S6 OSM: 11519985 WD: Q63705067 47.54, 7.591 x 47.71, 7.849
    { 5193, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0072bc} }, // N6 OSM: 11522997 47.55, 7.587 x 47.59, 7.656
    { 1231, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffcf06} }, // M3 OSM: 11525600 WD: Q2637212 50.41, 4.43 x 50.48, 4.452
    { 5196, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // Thilawa OSM: 11548643 16.66, 96.16 x 16.86, 96.26
    { 5204, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // Eastern University OSM: 11548647 16.74, 96.16 x 16.86, 96.29
    { 5223, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // Ywar Thar Gyi OSM: 11548648 16.78, 96.16 x 16.93, 96.27
    { 5237, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffff00} }, // Computer University OSM: 11548671 16.78, 96.07 x 17.01, 96.16
    { 5257, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffff00} }, // Insein - Hlaw Karr OSM: 11548680 16.87, 96.08 x 17, 96.11
    { 5276, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // Dagon University OSM: 11549059 16.78, 96.16 x 16.91, 96.23
    { 5293, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x545656} }, // U Coimbra<=>Figueira OSM: 11562467 WD: Q125980002 40.12, -8.848 x 40.23, -8.432
    { 2114, NoLogo, 16277, LineMetaDataContent::Tramway, Color{0x858585} }, // 34 OSM: 11565304 WD: Q100991407 52.04, 4.244 x 52.08, 4.543
    { 5314, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe1e1ff} }, // SN 4 OSM: 11566470 50.97, -0.1728 x 51.5, 0.213
    { 5319, 33196, NoLogo, LineMetaDataContent::LocalTrain, Color{0x00bfff} }, // KK OSM: 11568311 WD: Q906807 35.18, 139.6 x 35.64, 139.8
    { 16, NoLogo, 23021, LineMetaDataContent::Subway, Color{0xfec30a} }, // 2 OSM: 11582700 WD: Q85776743 37.97, 114.5 x 38.09, 114.5
    { 27, 33222, NoLogo, LineMetaDataContent::Subway, Color{0x3abca8} }, // 6 OSM: 11583149 WD: Q6119435 22.54, 113.8 x 22.79, 114.1
    { 67, 33245, NoLogo, LineMetaDataContent::Subway, Color{0xf8779e} }, // 10 OSM: 11583622 WD: Q15925362 22.52, 114.1 x 22.7, 114.1
    { 672, 33269, NoLogo, LineMetaDataContent::RapidTransit, Color{0x449ad5} }, // R1 OSM: 11592118 WD: Q2395239 41.36, 2.02 x 41.77, 2.769
    { 8, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x84c8eb} }, // M4 OSM: 11592482 WD: Q1841724 50.41, 4.435 x 50.43, 4.503
    { 290, NoLogo, 4285, LineMetaDataContent::RapidTransit, Color{0xd73598} }, // S6 OSM: 11604486 WD: Q124206421 49.96, 14.07 x 50.06, 14.41
    { 5322, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xee1d23} }, // E11 OSM: 11604709 WD: Q106925455 47.48, 7.584 x 47.55, 7.612
    { 5326, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfed304} }, // 2V OSM: 11610608 WD: Q1488532 48.1, 20.73 x 48.1, 20.81
    { 5329, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfed304} }, // 1V OSM: 11610610 WD: Q1484152 48.1, 20.68 x 48.11, 20.81
    { 5332, 33286, 19551, LineMetaDataContent::Subway, Color{0xf5a200} }, // 272 OSM: 11619514 WD: Q84389881 37.24, 126.6 x 37.58, 127.1
    { 5336, 33308, 33349, LineMetaDataContent::Tramway, Color{0xdce3e9} }, // T1a OSM: 11636568 WD: Q117008305 38.72, 35.37 x 38.79, 35.63
    { 5340, 33367, 33349, LineMetaDataContent::Tramway, Color{0xdce3e9} }, // T2a OSM: 11636816 WD: Q117008320 38.69, 35.49 x 38.73, 35.56
    { 5344, 33408, NoLogo, LineMetaDataContent::Subway, Color{0xb8007c} }, // TL-3 OSM: 11637375 WD: Q5986357 20.62, -103.4 x 20.74, -103.3
    { 281, 33308, 33349, LineMetaDataContent::Tramway, Color{0xdce3e9} }, // T1 OSM: 11641755 WD: Q117008305 38.72, 35.37 x 38.79, 35.63
    { 9, 33474, NoLogo, LineMetaDataContent::Subway, Color{0xffa500} }, // 4 OSM: 11643429 WD: Q24837537 24.86, 102.7 x 25.11, 102.9
    { 700, 33367, 33349, LineMetaDataContent::Tramway, Color{0xdce3e9} }, // T2 OSM: 11644048 WD: Q117008320 38.69, 35.49 x 38.73, 35.56
    { 5349, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xc16c18} }, // 4–环–5 OSM: 11665748 29.41, 106.4 x 29.63, 106.7
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xa78b6b} }, // 1 OSM: 11678493 WD: Q17440810 45.81, 15.95 x 45.82, 16.02
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf05972} }, // 2 OSM: 11678494 WD: Q17440806 45.79, 15.93 x 45.82, 16.04
    { 170, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xd19563} }, // 44 OSM: 11685877 WD: Q120720222 50.06, 19.94 x 50.08, 20.07
    { 22, 33494, NoLogo, LineMetaDataContent::Subway, Color{0x006272} }, // 18 OSM: 11697795 WD: Q22100462 30.27, 104.1 x 30.61, 104.5
    { 16, 33505, NoLogo, LineMetaDataContent::Subway, Color{0x0645ad} }, // 2 OSM: 11697809 WD: Q82669483 40.75, 111.6 x 40.87, 111.8
    { 11, 33527, 9561, LineMetaDataContent::Subway, Color{0xff8040} }, // M5 OSM: 11697885 WD: Q1641397 44.41, 26.01 x 44.44, 26.07
    { 5361, 33543, NoLogo, LineMetaDataContent::Subway, Color{0x004da3} }, // TJ OSM: 11700880 WD: Q2782450 35.44, 139.2 x 36.12, 139.7
    { 5364, 33574, NoLogo, LineMetaDataContent::Subway, Color{0xed772d} }, // SI OSM: 11703137 WD: Q842649 35.72, 139.1 x 35.99, 139.7
    { 16, 33593, 26958, LineMetaDataContent::Subway, Color{0x008000} }, // 2 OSM: 11720074 WD: Q6427302 22.56, 88.33 x 22.59, 88.43
    { 271, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x406681} }, // B OSM: 11727456 35.02, 135.7 x 35.03, 135.7
    { 5367, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xa58704} }, // APM Gold Line OSM: 11747102 WD: Q25540775 13.72, 100.5 x 13.73, 100.5
    { 5381, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x81609f} }, // Π2 OSM: 11748540 WD: Q116036452 38.24, 21.73 x 38.3, 21.78
    { 5385, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf7ad41} }, // Π1 OSM: 11748541 WD: Q116036470 38.14, 21.56 x 38.24, 21.73
    { 306, 33633, 2455, LineMetaDataContent::RapidTransit, Color{0xd7df23} }, // S4 OSM: 11758267 WD: Q112707549 47.25, 11.08 x 47.58, 12.17
    { 44, 33646, 2455, LineMetaDataContent::RapidTransit, Color{0x5b9a6d} }, // S5 OSM: 11758341 WD: Q112707550 47.24, 10.86 x 47.39, 11.78
    { 217, 33659, 2455, LineMetaDataContent::RapidTransit, Color{0xb4bece} }, // S3 OSM: 11763862 WD: Q112707548 47, 11.39 x 47.26, 11.51
    { 47, 33672, 2455, LineMetaDataContent::RapidTransit, Color{0x257ca7} }, // S8 OSM: 11763916 WD: Q112707555 47.42, 12.06 x 47.52, 12.63
    { 410, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x035eb9} }, // M OSM: 11772006 WD: Q118902123 61.17, 23.5 x 61.51, 23.86
    { 649, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // C-1 OSM: 11784871 42.99, -4.141 x 43.46, -3.812
    { 5389, 14813, NoLogo, LineMetaDataContent::LocalTrain, Color{0xfdda24} }, // 86981 OSM: 11792135 WD: Q205585 42.42, 2.88 x 42.7, 3.168
    { 220, 14813, NoLogo, LineMetaDataContent::LocalTrain, Color{0xfdda24} }, // 86967 OSM: 11792136 WD: Q205585 42.42, 2.866 x 43.83, 4.367
    { 383, 14813, NoLogo, LineMetaDataContent::LocalTrain, Color{0xfdda24} }, // 86989 OSM: 11792146 WD: Q205585 42.42, 2.866 x 43.94, 4.805
    { 1357, 14813, NoLogo, LineMetaDataContent::LocalTrain, Color{0xfdda24} }, // 86987 OSM: 11792148 WD: Q205585 42.42, 2.866 x 43.94, 4.805
    { 1007, 14813, NoLogo, LineMetaDataContent::LocalTrain, Color{0xfdda24} }, // 86998 OSM: 11792152 WD: Q205585 42.42, 2.866 x 43.83, 4.366
    { 423, 14813, NoLogo, LineMetaDataContent::LocalTrain, Color{0xfdda24} }, // 86996 OSM: 11792153 WD: Q205585 42.42, 2.866 x 43.83, 4.366
    { 5395, 14813, NoLogo, LineMetaDataContent::LocalTrain, Color{0xfdda24} }, // 86960 OSM: 11792154 WD: Q205585 42.42, 2.879 x 42.7, 3.168
    { 5401, 14813, NoLogo, LineMetaDataContent::LocalTrain, Color{0xfdda24} }, // 86964 OSM: 11792157 WD: Q205585 42.42, 2.879 x 42.7, 3.168
    { 1381, 33692, NoLogo, LineMetaDataContent::RapidTransit, Color{0x9a897e} }, // E5 OSM: 11796871 WD: Q104233835 43.3, -1.983 x 43.32, -1.931
    { 1295, 33709, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfab700} }, // T3 OSM: 11797706 WD: Q5986343 39.57, 2.654 x 39.72, 3.203
    { 700, 33720, NoLogo, LineMetaDataContent::RapidTransit, Color{0x6495ed} }, // T2 OSM: 11797707 WD: Q5986167 39.58, 2.654 x 39.76, 3.034
    { 281, 33720, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // T1 OSM: 11797708 WD: Q5986167 39.58, 2.654 x 39.72, 2.908
    { 60, 33731, NoLogo, LineMetaDataContent::Subway, Color{0x0101f8} }, // 3 OSM: 11798336 WD: Q19852709 31.5, 120.2 x 31.6, 120.4
    { 2665, 33756, NoLogo, LineMetaDataContent::Subway, Color{0xf5a300} }, // TN OSM: 11801852 WD: Q3449834 35.51, 139.4 x 36.85, 139.9
    { 5407, 33788, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe71212} }, // TI OSM: 11801907 WD: Q1049699 36.02, 139.2 x 36.43, 139.7
    { 178, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xf7943a} }, // O OSM: 11803501 WD: Q18385578 31.46, 74.24 x 31.59, 74.43
    { 27, NoLogo, 7769, LineMetaDataContent::Subway, Color{0x0099cc} }, // 6 OSM: 11807149 WD: Q3832666 40.82, 14.19 x 40.84, 14.25
    { 1295, 33822, NoLogo, LineMetaDataContent::Tramway, Color{0xcc0099} }, // T3 OSM: 11813038 WD: Q117327547 36.88, 30.66 x 36.99, 30.72
    { 700, 33863, NoLogo, LineMetaDataContent::Tramway, Color{0x027ffd} }, // T2 OSM: 11813041 WD: Q116369823 36.87, 30.68 x 36.89, 30.72
    { 5410, 33904, NoLogo, LineMetaDataContent::Tramway, Color{0xff6400} }, // T1A OSM: 11813042 WD: Q117327542 36.89, 30.64 x 36.94, 30.81
    { 5414, 33946, NoLogo, LineMetaDataContent::Tramway, Color{0xff6400} }, // T1B OSM: 11813043 WD: Q117327753 36.89, 30.64 x 36.95, 30.88
    { 5418, 33988, NoLogo, LineMetaDataContent::LocalTrain, Color{} }, // FEX OSM: 11815470 WD: Q100533383 52.36, 13.36 x 52.55, 13.6
    { 5422, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // CK OSM: 11830794 WD: Q5097496 33.75, 130.7 x 33.87, 130.8
    { 34, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0072bc} }, // H OSM: 11839798 WD: Q1074266 42.64, 141.3 x 43.11, 141.7
    { 60, NoLogo, 21391, LineMetaDataContent::Subway, Color{0x008000} }, // 3 OSM: 11845129 WD: Q2889805 53.88, 27.54 x 53.9, 27.55
    { 5425, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xd12027} }, // NH OSM: 11851821 WD: Q1137838 34.76, 136.8 x 35.41, 137.4
    { 511, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000cd} }, // L2 OSM: 11871075 WD: Q121834229 30.44, 114.4 x 30.51, 114.5
    { 1864, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfece0c} }, // Gold OSM: 11873946 WD: Q5059275 35.21, -80.86 x 35.25, -80.82
    { 60, 34007, NoLogo, LineMetaDataContent::Subway, Color{0x90403e} }, // 3 OSM: 11899105 WD: Q30641320 21.03, 105.7 x 21.05, 105.8
    { 556, 34037, NoLogo, LineMetaDataContent::LocalTrain, Color{0xcb8daa} }, // RB 48 OSM: 11913928 WD: Q107023360 48.04, 11.6 x 48.13, 12.19
    { 5428, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // Т1 OSM: 11921539 59.94, 30.26 x 59.96, 30.35
    { 700, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xde1c77} }, // T2 OSM: 11922903 WD: Q108045346 50.3, 18.73 x 50.4, 18.92
    { 9, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xdae600} }, // 4 OSM: 11923211 WD: Q26262003 22.75, 108.2 x 22.77, 108.5
    { 1239, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xd77d00} }, // 31 OSM: 11997852 WD: Q1760190 59.33, 17.95 x 59.36, 17.98
    { 322, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 25 OSM: 12010107 WD: Q2619013 52.27, 4.831 x 52.34, 4.876
    { 2157, 34054, 226, LineMetaDataContent::RapidTransit, Color{0x009640} }, // S44 OSM: 12014994 WD: Q122841884 49.47, 8.428 x 49.52, 8.442
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x509e2f} }, // 1 OSM: 12021098 WD: Q120550959 55.71, 13.19 x 55.73, 13.24
    { 27, 34074, NoLogo, LineMetaDataContent::Subway, Color{0xb36924} }, // 6 OSM: 12039115 WD: Q22100481 30.43, 103.9 x 30.81, 104.1
    { 511, NoLogo, 31768, LineMetaDataContent::Tramway, Color{0x004f9f} }, // L2 OSM: 12078298 WD: Q3238814 43.66, 7.199 x 43.7, 7.285
    { 19, 34084, NoLogo, LineMetaDataContent::Subway, Color{0x88dd00} }, // 8 OSM: 12086373 WD: Q26262006 30.54, 104 x 30.72, 104.2
    { 231, 34094, NoLogo, LineMetaDataContent::Subway, Color{0x80e0a7} }, // 17 OSM: 12095438 WD: Q28973151 30.64, 103.9 x 30.65, 104
    { 1046, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // S10 OSM: 12110561 47.86, 7.83 x 48.06, 8.504
    { 403, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xef3f30} }, // C OSM: 12112439 WD: Q55597911 47.44, -0.6042 x 47.48, -0.5492
    { 42, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 7 OSM: 12114202 WD: Q122917038 44.78, 20.37 x 44.81, 20.52
    { 138, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 9 OSM: 12114471 WD: Q100151898 44.76, 20.37 x 44.81, 20.48
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 11 OSM: 12114747 WD: Q122917039 44.79, 20.37 x 44.83, 20.46
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 13 OSM: 12115860 WD: Q122917041 44.77, 20.37 x 44.81, 20.43
    { 56, NoLogo, 34105, LineMetaDataContent::Tramway, Color{0x00985f} }, // 1 OSM: 12116142 WD: Q111355036 60.16, 24.93 x 60.22, 24.96
    { 16, NoLogo, 34105, LineMetaDataContent::Tramway, Color{0x00985f} }, // 2 OSM: 12116144 WD: Q111354560 60.16, 24.92 x 60.2, 24.96
    { 60, NoLogo, 34105, LineMetaDataContent::Tramway, Color{0x00985f} }, // 3 OSM: 12116149 WD: Q111354658 60.16, 24.9 x 60.2, 24.96
    { 9, NoLogo, 34105, LineMetaDataContent::Tramway, Color{0x00985f} }, // 4 OSM: 12116155 WD: Q111354573 60.17, 24.87 x 60.2, 24.98
    { 6, NoLogo, 34105, LineMetaDataContent::Tramway, Color{0x00985f} }, // 5 OSM: 12116158 WD: Q111355032 60.16, 24.94 x 60.17, 24.97
    { 27, NoLogo, 34105, LineMetaDataContent::Tramway, Color{0x00985f} }, // 6 OSM: 12116159 WD: Q111354303 60.15, 24.93 x 60.21, 24.98
    { 42, NoLogo, 34105, LineMetaDataContent::Tramway, Color{0x00985f} }, // 7 OSM: 12116160 WD: Q111354531 60.15, 24.91 x 60.2, 24.96
    { 19, NoLogo, 34105, LineMetaDataContent::Tramway, Color{0x00985f} }, // 8 OSM: 12116163 WD: Q111354700 60.16, 24.91 x 60.21, 24.98
    { 138, NoLogo, 34105, LineMetaDataContent::Tramway, Color{0x00985f} }, // 9 OSM: 12116164 WD: Q111354553 60.15, 24.91 x 60.21, 24.95
    { 67, NoLogo, 34105, LineMetaDataContent::Tramway, Color{0x00985f} }, // 10 OSM: 12116165 WD: Q111354624 60.16, 24.89 x 60.21, 24.95
    { 9, 34130, NoLogo, LineMetaDataContent::Subway, Color{0xabcd03} }, // 4 OSM: 12144421 WD: Q10946023 29.78, 121.4 x 29.98, 121.6
    { 5432, 34151, NoLogo, LineMetaDataContent::LocalTrain, Color{0xffb200} }, // RB 14 OSM: 12144619 WD: Q106109581 48.74, 11.16 x 48.9, 11.44
    { 6, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0a9eda} }, // 5 OSM: 12148182 WD: Q692803 40.81, 14.04 x 40.88, 14.25
    { 1366, 34168, NoLogo, LineMetaDataContent::Tramway, Color{0x7c72b3} }, // T5 OSM: 12174617 WD: Q48848864 41.02, 28.94 x 41.09, 28.97
    { 51, 34196, 2455, LineMetaDataContent::RapidTransit, Color{0x4f9961} }, // S2 OSM: 12206186 WD: Q112707418 46.73, 12.27 x 46.83, 12.77
    { 153, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xbe1622} }, // 19 OSM: 12226279 WD: Q121368369 44.38, 26.08 x 44.43, 26.2
    { 149, 34209, NoLogo, LineMetaDataContent::Subway, Color{0xbba786} }, // 15 OSM: 12231218 WD: Q6553078 31.02, 121.4 x 31.35, 121.4
    { 1079, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x00c000} }, // 2A OSM: 12231738 WD: Q30919856 20.95, 105.7 x 21.03, 105.8
    { 16, 34219, NoLogo, LineMetaDataContent::Tramway, Color{0xfab71b} }, // 2 OSM: 12232119 WD: Q121359279 50.89, 11.58 x 50.93, 11.62
    { 6, 34243, NoLogo, LineMetaDataContent::Tramway, Color{0x6a2e74} }, // 5 OSM: 12232120 WD: Q121359282 50.88, 11.58 x 50.93, 11.64
    { 9, 34267, NoLogo, LineMetaDataContent::Tramway, Color{0xda020e} }, // 4 OSM: 12232121 WD: Q121359281 50.88, 11.58 x 50.96, 11.62
    { 60, 34291, NoLogo, LineMetaDataContent::Tramway, Color{0x7f5f00} }, // 3 OSM: 12232122 WD: Q121359280 50.88, 11.58 x 50.9, 11.64
    { 56, 34315, NoLogo, LineMetaDataContent::Tramway, Color{0xe94c0a} }, // 1 OSM: 12232123 WD: Q121359278 50.88, 11.58 x 50.96, 11.62
    { 5438, 34339, NoLogo, LineMetaDataContent::LocalTrain, Color{0xffffff} }, // RB 54 OSM: 12233202 WD: Q113229669 47.58, 11.53 x 48.14, 12.2
    { 5444, 34356, NoLogo, LineMetaDataContent::LocalTrain, Color{} }, // RE 5 OSM: 12234223 WD: Q113228374 47.81, 11.53 x 48.14, 13.05
    { 5449, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf0e68c} }, // Limited OSM: 12246239 37, -122.4 x 37.78, -121.6
    { 2194, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x2f4f4f} }, // 102 OSM: 12315495 WD: Q121688873 44.29, 23.72 x 44.39, 23.85
    { 1429, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x2f4f4f} }, // 100 OSM: 12315496 WD: Q121688751 44.31, 23.77 x 44.34, 23.83
    { 2129, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x2f4f4f} }, // 101 OSM: 12315497 WD: Q121688812 44.29, 23.75 x 44.36, 23.85
    { 5457, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe3e049} }, // TECO OSM: 12321313 27.94, -82.46 x 27.96, -82.44
    { 5462, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xdb161c} }, // QLine OSM: 12330605 42.33, -83.07 x 42.37, -83.05
    { 410, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // M OSM: 12331275 WD: Q123244689 43.03, -87.92 x 43.05, -87.9
    { 406, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // S OSM: 12332844 34.65, 133.9 x 34.67, 133.9
    { 34, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // H OSM: 12332845 34.66, 133.9 x 34.67, 133.9
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // 2 OSM: 12340019 WD: Q18155116 29.95, -90.07 x 29.96, -90.06
    { 559, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x90ee90} }, // 48 OSM: 12340020 WD: Q121433227 29.96, -90.1 x 29.98, -90.08
    { 714, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 47 OSM: 12340021 29.95, -90.11 x 29.98, -90.07
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 12 OSM: 12340022 WD: Q18155455 29.93, -90.13 x 29.96, -90.07
    { 359, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00aae4} }, // Blue OSM: 12340243 34.74, -92.27 x 34.76, -92.26
    { 639, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x66ff00} }, // Green OSM: 12340244 34.74, -92.27 x 34.75, -92.26
    { 56, NoLogo, 7769, LineMetaDataContent::Subway, Color{0xfeca1b} }, // 1 OSM: 12341393 WD: Q1085934 40.84, 14.22 x 40.9, 14.27
    { 700, NoLogo, 34372, LineMetaDataContent::Tramway, Color{0x50ab43} }, // T2 OSM: 12342707 WD: Q30634535 38.4, 27.07 x 38.44, 27.17
    { 1570, NoLogo, 34392, LineMetaDataContent::RapidTransit, Color{0x800080} }, // Purple OSM: 12356340 WD: Q4533683 29.7, -95.37 x 29.76, -95.33
    { 371, NoLogo, 34392, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // Red OSM: 12356341 WD: Q16934038 29.67, -95.41 x 29.83, -95.36
    { 639, NoLogo, 34392, LineMetaDataContent::RapidTransit, Color{0x008000} }, // Green OSM: 12356342 WD: Q4262189 29.74, -95.37 x 29.76, -95.3
    { 5468, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff1b6e} }, // APT Rose OSM: 12360663 32.86, -96.94 x 32.87, -96.93
    { 5477, 34415, 14361, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // m1 OSM: 12371355 WD: Q685114 46.52, 6.564 x 46.54, 6.63
    { 281, NoLogo, 34372, LineMetaDataContent::Tramway, Color{0x50ab43} }, // T1 OSM: 12378475 WD: Q21523607 38.45, 27.06 x 38.49, 27.13
    { 60, 34442, NoLogo, LineMetaDataContent::Subway, Color{0xff8000} }, // 3 OSM: 12380649 WD: Q56377988 25.67, -100.3 x 25.71, -100.3
    { 6, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xc1d522} }, // 5 OSM: 12385671 WD: Q43445187 31.7, 117.3 x 31.94, 117.3
    { 60, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xbe1622} }, // 3 OSM: 12400122 WD: Q97197739 44.47, 26.02 x 44.49, 26.07
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x146eb7} }, // 4 OSM: 12400338 WD: Q107104582 40.83, 14.26 x 40.85, 14.31
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x4096d2} }, // 1 OSM: 12400369 WD: Q107104562 40.84, 14.26 x 40.87, 14.29
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x267cc0} }, // 2 OSM: 12400406 WD: Q107104575 40.83, 14.27 x 40.87, 14.31
    { 1050, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x1c3f94} }, // 399 OSM: 12417807 33.12, -117.4 x 33.22, -117.1
    { 16, 34456, NoLogo, LineMetaDataContent::RapidTransit, Color{0x025257} }, // 2 OSM: 12462807 WD: Q2274338 40.82, 14.13 x 40.86, 14.31
    { 9, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x203f7d} }, // 4 OSM: 12462853 WD: Q1000745 40.81, 14.04 x 40.85, 14.25
    { 5480, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0d82c7} }, // OH OSM: 12463786 WD: Q11430772 35.23, 139 x 35.69, 139.7
    { 5483, 34475, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0090d3} }, // E3a OSM: 12498778 WD: Q43223339 43.29, -2.97 x 43.3, -2.928
    { 290, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0xd72319} }, // S6 OSM: 12524258 WD: Q110186534 49.44, 10.58 x 49.58, 11.08
    { 5487, 34493, NoLogo, LineMetaDataContent::LocalTrain, Color{0xe50000} }, // RE 31 OSM: 12529911 WD: Q113462372 49.44, 11.08 x 50.31, 12.09
    { 5493, 34510, NoLogo, LineMetaDataContent::LocalTrain, Color{} }, // RE 32 OSM: 12535805 WD: Q113462373 49.9, 10.89 x 50.16, 11.6
    { 5499, 34527, NoLogo, LineMetaDataContent::LocalTrain, Color{} }, // RE 35 OSM: 12535884 WD: Q113462494 49.9, 10.89 x 50.31, 11.94
    { 5505, 34544, NoLogo, LineMetaDataContent::LocalTrain, Color{} }, // RB 18 OSM: 12548478 WD: Q104149638 50.26, 10.78 x 50.34, 10.96
    { 5511, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x4682b4} }, // Airside C OSM: 12560187 WD: Q121502054 27.98, -82.53 x 27.98, -82.53
    { 5521, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x4682b4} }, // Airside F OSM: 12560190 WD: Q121502074 27.98, -82.54 x 27.98, -82.54
    { 5531, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x4682b4} }, // Airside A OSM: 12560197 WD: Q121502044 27.98, -82.53 x 27.98, -82.53
    { 1786, 34561, 5804, LineMetaDataContent::Tramway, Color{0x5291ce} }, // T9 OSM: 12564972 WD: Q3537038 48.75, 2.365 x 48.82, 2.419
    { 281, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xd22630} }, // T1 OSM: 12567203 39.71, 116.5 x 39.8, 116.6
    { 5541, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x5ab034} }, // LEB OSM: 12569757 46.52, 6.599 x 46.69, 6.704
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x800080} }, // 1 OSM: 12603876 WD: Q98199553 33.49, 119 x 33.6, 119.2
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 1 OSM: 12606970 WD: Q107191166 37.99, -1.174 x 38.04, -1.124
    { 2997, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x78b942} }, // Verde OSM: 12632067 -9.672, -35.74 x -9.65, -35.72
    { 3028, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x1a5ba3} }, // Azul OSM: 12632071 WD: Q124719723 -9.625, -35.86 x -9.478, -35.75
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xed1c24} }, // 2 OSM: 12661403 WD: Q121361538 50.49, 12.13 x 50.51, 12.17
    { 8, NoLogo, 21437, LineMetaDataContent::Subway, Color{0xffff00} }, // M4 OSM: 12668937 WD: Q101570868 42.65, 23.26 x 42.74, 23.42
    { 56, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfdc434} }, // 1 OSM: 12686111 WD: Q56388740 46.24, 20.12 x 46.42, 20.34
    { 60, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 3 OSM: 12758107 WD: Q112487273 61.44, 23.72 x 61.51, 23.87
    { 584, 34594, NoLogo, LineMetaDataContent::Tramway, Color{0x81cf00} }, // R OSM: 12765542 WD: Q3239181 50.64, 3.071 x 50.69, 3.179
    { 39, 34614, NoLogo, LineMetaDataContent::Tramway, Color{0x0099ff} }, // T OSM: 12765723 WD: Q3239234 50.64, 3.071 x 50.72, 3.159
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 2 OSM: 12771496 WD: Q11676682 31.56, 130.5 x 31.6, 130.6
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // 1 OSM: 12771497 WD: Q11676681 31.53, 130.5 x 31.6, 130.6
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x005bac} }, // 2 OSM: 12791164 WD: Q19856264 26.52, 106.6 x 26.7, 106.8
    { 5545, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xcc0000} }, // UAE Exchange OSM: 12820286 WD: Q97940934 24.98, 55.09 x 25.06, 55.13
    { 60, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x800080} }, // 3 OSM: 12824257 12.82, 80.22 x 13.15, 80.27
    { 6, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // 5 OSM: 12828618 12.9, 80.16 x 13.1, 80.23
    { 5558, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // IR87 OSM: 12856601 47.49, 19.08 x 47.89, 20.42
    { 5563, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xaacd46} }, // G40 OSM: 12856603 WD: Q112963120 46.37, 18.15 x 47.5, 19.04
    { 5567, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffcd28} }, // Z42 OSM: 12856604 WD: Q112225437 46.96, 18.76 x 47.5, 19.04
    { 60, NoLogo, 27690, LineMetaDataContent::Subway, Color{0x0c89de} }, // 3 OSM: 12893656 WD: Q47500936 24.43, 118.1 x 24.58, 118.3
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x529fc9} }, // 2 OSM: 12914035 WD: Q106783516 31.75, 119.9 x 31.8, 120.1
    { 56, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xc5003e} }, // 1 OSM: 12920991 WD: Q24835360 29.92, 120.2 x 30.31, 120.6
    { 231, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0b4355} }, // 17 OSM: 12925063 WD: Q67934269 34.05, 113.8 x 34.61, 113.9
    { 6, 34634, NoLogo, LineMetaDataContent::Subway, Color{0xa6e35f} }, // 5 OSM: 12925442 WD: Q15939245 34.22, 108.7 x 34.27, 109
    { 60, 31909, 31909, LineMetaDataContent::Subway, Color{0x008bd5} }, // 3 OSM: 12935364 WD: Q47291030 34.15, 117.2 x 34.28, 117.2
    { 16, 31909, 31909, LineMetaDataContent::Subway, Color{0xef8200} }, // 2 OSM: 12935365 WD: Q47004987 34.21, 117.2 x 34.33, 117.3
    { 9, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff8000} }, // 4 OSM: 12940680 13.03, 80.08 x 13.05, 80.28
    { 56, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xc4608c} }, // 1 OSM: 12942003 WD: Q15936968 34.66, 112.3 x 34.7, 112.6
    { 27, 34654, NoLogo, LineMetaDataContent::Subway, Color{0x485cc7} }, // 6 OSM: 13040751 WD: Q52596166 34.15, 108.8 x 34.28, 109.1
    { 138, 34674, NoLogo, LineMetaDataContent::Subway, Color{0xff9e1b} }, // 9 OSM: 13042254 WD: Q97350661 34.27, 109.1 x 34.4, 109.2
    { 19, 34694, NoLogo, LineMetaDataContent::Subway, Color{0xac145a} }, // 8 OSM: 13042427 WD: Q11102451 30.3, 120.4 x 30.31, 120.5
    { 3191, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xa065aa} }, // U2Z OSM: 13045481 WD: Q118746734 48.2, 16.36 x 48.22, 16.37
    { 138, 34704, NoLogo, LineMetaDataContent::Subway, Color{0xbe4d00} }, // 9 OSM: 13060970 WD: Q18653898 30.25, 120.2 x 30.46, 120.3
    { 56, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xdfaa00} }, // 1 OSM: 13067815 WD: Q15935678 35.94, 120.2 x 36.34, 120.4
    { 19, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xdf1995} }, // 8 OSM: 13068450 WD: Q22100048 36.17, 120 x 36.4, 120.4
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 1 OSM: 13072753 WD: Q112485271 61.49, 23.77 x 61.51, 23.82
    { 27, 34714, NoLogo, LineMetaDataContent::Subway, Color{0x0072ce} }, // 6 OSM: 13077350 WD: Q11102449 30.05, 119.9 x 30.3, 120.2
    { 9, 34728, NoLogo, LineMetaDataContent::Subway, Color{0x6bc349} }, // 4 OSM: 13077360 WD: Q11102444 30.16, 120.1 x 30.36, 120.2
    { 5571, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x273583} }, // TER 22 OSM: 13081021 WD: Q123653112 45.15, 0.6938 x 47.39, 4.862
    { 63, 34748, NoLogo, LineMetaDataContent::Subway, Color{0x1b61ae} }, // S1 OSM: 13084233 WD: Q15910427 27.91, 120.6 x 27.99, 121
    { 138, 34779, NoLogo, LineMetaDataContent::Subway, Color{0xffb81c} }, // 9 OSM: 13088859 WD: Q28972638 30.58, 104 x 30.7, 104.1
    { 6, 34789, NoLogo, LineMetaDataContent::Subway, Color{0xe93cac} }, // 5 OSM: 13091428 WD: Q6553133 31.23, 120.4 x 31.37, 120.8
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf90303} }, // 5 OSM: 13118861 WD: Q121662891 54.68, 20.45 x 54.73, 20.53
    { 5578, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x5eb3e4} }, // TNH1 OSM: 13124236 WD: Q18651563 23, 113.2 x 23.04, 113.2
    { 5583, 34810, NoLogo, LineMetaDataContent::LongDistanceTrain, Color{0x005b23} }, // IR 35 OSM: 13131233 WD: Q115996431 46.85, 7.434 x 47.44, 9.562
    { 5589, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xd42d1b} }, // THP1 OSM: 13140107 WD: Q63687256 23.18, 113.5 x 23.22, 113.5
    { 1323, NoLogo, 3439, LineMetaDataContent::Tramway, Color{0x172983} }, // L5 OSM: 13154071 WD: Q9025966 38.34, -0.479 x 38.38, -0.4118
    { 5594, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // Ouargla tram OSM: 13159622 WD: Q123362872 31.94, 5.265 x 31.96, 5.333
    { 1623, NoLogo, 34825, LineMetaDataContent::RapidTransit, Color{} }, // M95 OSM: 13167233 WD: Q3897221 38.1, 13.11 x 38.2, 13.38
    { 16, 34846, NoLogo, LineMetaDataContent::Subway, Color{0xdb6d1c} }, // 2 OSM: 13176924 WD: Q5947229 22.48, 113.9 x 22.57, 114.2
    { 19, 34869, NoLogo, LineMetaDataContent::Subway, Color{0xdb6d1c} }, // 8 OSM: 13176927 WD: Q11174946 22.56, 114.2 x 22.61, 114.3
    { 5607, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7a121c} }, // EKV OSM: 13180873 WD: Q124522867 -1.323, 36.83 x -1.289, 36.92
    { 5611, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7a121c} }, // LKY OSM: 13180875 WD: Q124527576 -1.49, 36.83 x -1.289, 37
    { 170, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xbe1622} }, // 44 OSM: 13199272 WD: Q61082462 44.44, 26.02 x 44.47, 26.09
    { 290, 34892, 12277, LineMetaDataContent::Subway, Color{0xb58bd7} }, // S6 OSM: 13200482 WD: Q10945834 31.92, 118.9 x 32.06, 119.2
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce7f46} }, // 11 OSM: 13217860 55.7, 52.34 x 55.74, 52.47
    { 42, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x808080} }, // 7 OSM: 13242817 WD: Q122395005 49.17, 16.55 x 49.23, 16.63
    { 22, 34913, NoLogo, LineMetaDataContent::Subway, Color{0x0047ba} }, // 18 OSM: 13246294 WD: Q11062044 22.7, 113.3 x 23.13, 113.6
    { 16, 34934, NoLogo, LineMetaDataContent::Subway, Color{0x00ae59} }, // 2 OSM: 13250192 WD: Q10921993 45.72, 126.5 x 45.87, 126.7
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00008b} }, // 5 OSM: 13252243 WD: Q123353000 56.45, 84.95 x 56.48, 84.99
    { 5615, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x37bbed} }, // TRS OSM: 13262889 WD: Q39081226 -24.98, -65.65 x -24.65, -65.04
    { 5619, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf3c847} }, // Northern Express OSM: 13296139 -34.12, 18.43 x -33.91, 18.86
    { 5636, 34958, 4324, LineMetaDataContent::Subway, Color{0xa12830} }, // 1E OSM: 13298577 WD: Q1039452 39.85, 116.5 x 39.91, 116.7
    { 16, 34983, NoLogo, LineMetaDataContent::Tramway, Color{0x009cdd} }, // 2 OSM: 13305615 WD: Q13390010 53.38, 14.55 x 53.45, 14.64
    { 5639, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // TAD OSM: 13308590 WD: Q18286525 -27.78, -64.27 x -27.73, -64.24
    { 5643, 35003, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7a745a} }, // F1 OSM: 13313680 WD: Q503503 41.03, 28.99 x 41.04, 28.99
    { 5646, 35031, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7a745a} }, // F2 OSM: 13313681 WD: Q387264 41.02, 28.97 x 41.03, 28.97
    { 9, 35059, NoLogo, LineMetaDataContent::Subway, Color{0x00a0e9} }, // 4 OSM: 13317505 WD: Q15938386 34.68, 113.6 x 34.83, 113.7
    { 60, 35078, NoLogo, LineMetaDataContent::Subway, Color{0xf39939} }, // 3 OSM: 13317992 WD: Q15950459 34.67, 113.6 x 34.84, 113.8
    { 507, 35097, 24833, LineMetaDataContent::Subway, Color{0xff7400} }, // L1 OSM: 13335174 WD: Q6515333 10.48, -66.96 x 10.52, -66.79
    { 5649, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x37bbed} }, // TPC OSM: 13341386 -31.77, -60.53 x -31.73, -60.29
    { 503, 35118, 24833, LineMetaDataContent::Subway, Color{0xfff000} }, // L4 OSM: 13350037 WD: Q21659772 10.43, -67.01 x 10.5, -66.84
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 6 OSM: 13372659 WD: Q114829246 49.58, 17.23 x 49.6, 17.28
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x1871b3} }, // 5 OSM: 13372660 WD: Q114829245 49.57, 17.25 x 49.59, 17.28
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffa500} }, // 4 OSM: 13372661 WD: Q114829243 49.58, 17.23 x 49.6, 17.29
    { 60, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 3 OSM: 13372662 WD: Q114829242 49.57, 17.25 x 49.6, 17.28
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x40e0d0} }, // 2 OSM: 13372663 WD: Q114829241 49.59, 17.22 x 49.6, 17.28
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff69b4} }, // 1 OSM: 13372664 WD: Q114829240 49.58, 17.23 x 49.59, 17.28
    { 42, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x77b5fe} }, // 7 OSM: 13372665 WD: Q114829247 49.59, 17.22 x 49.6, 17.28
    { 16, NoLogo, 19, LineMetaDataContent::Tramway, Color{0xffcc00} }, // 2 OSM: 13395428 WD: Q121355964 51.29, 12.28 x 51.34, 12.44
    { 138, NoLogo, 19, LineMetaDataContent::Tramway, Color{0xffcc00} }, // 9 OSM: 13397093 WD: Q121345246 51.3, 12.37 x 51.38, 12.43
    { 2129, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 101 OSM: 13397151 WD: Q122781322 44.93, 26 x 44.96, 26.03
    { 2194, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 102 OSM: 13397152 WD: Q122781344 44.93, 25.99 x 44.96, 26.01
    { 26, 35139, NoLogo, LineMetaDataContent::Tramway, Color{0x2f4f4f} }, // 16 OSM: 13401153 WD: Q121753792 46.17, 21.32 x 46.2, 21.34
    { 149, 35156, NoLogo, LineMetaDataContent::Tramway, Color{0x2f4f4f} }, // 15 OSM: 13401154 WD: Q121753790 46.18, 21.29 x 46.2, 21.34
    { 15, 35173, NoLogo, LineMetaDataContent::Tramway, Color{0x2f4f4f} }, // 12 OSM: 13401155 WD: Q121753786 46.14, 21.32 x 46.18, 21.59
    { 55, 35190, NoLogo, LineMetaDataContent::Tramway, Color{0x2f4f4f} }, // 11 OSM: 13401156 WD: Q121753785 46.14, 21.29 x 46.2, 21.59
    { 27, 35207, NoLogo, LineMetaDataContent::Tramway, Color{0x2f4f4f} }, // 6 OSM: 13401157 WD: Q121753780 46.17, 21.28 x 46.21, 21.33
    { 42, 35223, NoLogo, LineMetaDataContent::Tramway, Color{0x2f4f4f} }, // 7 OSM: 13401158 WD: Q121753781 46.17, 21.29 x 46.2, 21.36
    { 60, 35239, NoLogo, LineMetaDataContent::Tramway, Color{0x2f4f4f} }, // 3 OSM: 13401159 WD: Q121753779 46.14, 21.29 x 46.2, 21.33
    { 56, 35255, NoLogo, LineMetaDataContent::Tramway, Color{0x2f4f4f} }, // 1 OSM: 13401160 WD: Q121753777 46.17, 21.29 x 46.2, 21.33
    { 3979, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 1R OSM: 13406771 WD: Q122617992 47.05, 21.91 x 47.08, 21.94
    { 5653, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 1N OSM: 13408107 WD: Q2129486 47.05, 21.91 x 47.08, 21.94
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 8 OSM: 13408524 47.05, 21.9 x 47.08, 21.93
    { 3653, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x966c29} }, // 6A OSM: 13417394 WD: Q121317837 49.44, 8.419 x 49.49, 8.518
    { 5656, 35271, NoLogo, LineMetaDataContent::Tramway, Color{0x2f4f4f} }, // 15b OSM: 13423415 WD: Q121753791 46.18, 21.29 x 46.22, 21.35
    { 341, 35289, NoLogo, LineMetaDataContent::Tramway, Color{0x9462b1} }, // 23 OSM: 13443923 WD: Q121419539 47.07, 15.44 x 47.07, 15.46
    { 254, 17063, NoLogo, LineMetaDataContent::LocalTrain, Color{} }, // 38 OSM: 13445438 WD: Q9025925 41.62, -0.9127 x 42, 0.6352
    { 3453, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffff00} }, // Yellow Line OSM: 13475082 25.31, 51.42 x 25.32, 51.45
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 13 OSM: 13489151 WD: Q62302293 52.1, 11.59 x 52.11, 11.65
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xffda01} }, // 2 OSM: 13502832 WD: Q6850047 28.56, 115.8 x 28.7, 116
    { 60, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0079c3} }, // 3 OSM: 13507037 WD: Q10908095 28.51, 115.9 x 28.7, 116
    { 42, 35301, NoLogo, LineMetaDataContent::Subway, Color{0x88129e} }, // 7 OSM: 13528567 WD: Q11102450 30.2, 120.2 x 30.33, 120.5
    { 67, 35311, NoLogo, LineMetaDataContent::Subway, Color{0xdaa520} }, // 10 OSM: 13535688 WD: Q18653896 30.27, 120.1 x 30.38, 120.1
    { 9, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff850d} }, // 4 OSM: 13536846 WD: Q43283453 31.76, 117.1 x 31.95, 117.3
    { 60, 35322, NoLogo, LineMetaDataContent::Subway, Color{0xffd700} }, // 3 OSM: 13538221 WD: Q11102442 30.21, 120 x 30.39, 120.3
    { 56, 35342, 19551, LineMetaDataContent::Subway, Color{0x009088} }, // 1 OSM: 13538911 WD: Q626996 35.11, 126.8 x 35.16, 126.9
    { 5660, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x004f9e} }, // S 7 OSM: 13540625 51.45, 11.55 x 51.52, 12
    { 9, 35367, NoLogo, LineMetaDataContent::Subway, Color{0x800080} }, // 4 OSM: 13540934 WD: Q19852710 31.47, 120.3 x 31.63, 120.3
    { 6, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x3b62a9} }, // 5 OSM: 13557463 WD: Q26262004 22.75, 108.3 x 22.87, 108.4
    { 5664, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x50af47} }, // S 47 OSM: 13562799 51.48, 11.96 x 51.52, 11.99
    { 2165, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00b9f2} }, // SKA1 OSM: 13563236 WD: Q125997734 49.99, 19.8 x 50.08, 20.06
    { 1062, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // S12 OSM: 13566082 48.87, 8.347 x 49.02, 8.518
    { 2047, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe6007e} }, // SKA2 OSM: 13571816 WD: Q125998347 49.96, 19.2 x 50.57, 20.1
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x6fba2c} }, // 2 OSM: 13592842 WD: Q48899497 34.6, 112.4 x 34.71, 112.5
    { 5646, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xc10230} }, // F2 OSM: 13604445 WD: Q10886732 22.97, 113 x 23.01, 113.3
    { 60, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 3 OSM: 13606198 WD: Q785655 41.87, 12.47 x 41.92, 12.52
    { 56, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xffa500} }, // 1 OSM: 13615315 WD: Q110419397 26.48, 80.25 x 26.51, 80.32
    { 243, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x00ced1} }, // 20 OSM: 13620411 WD: Q27940747 22.65, 113.8 x 22.72, 113.8
    { 55, 35392, 4324, LineMetaDataContent::Subway, Color{0xed796a} }, // 11 OSM: 13623628 WD: Q6553057 39.91, 116.1 x 39.93, 116.2
    { 231, 35413, 4324, LineMetaDataContent::Subway, Color{0x00a9a9} }, // 17 OSM: 13625147 WD: Q24834015 39.79, 116.4 x 40.13, 116.6
    { 153, 35434, 4324, LineMetaDataContent::Subway, Color{0xd6aac1} }, // 19 OSM: 13625329 WD: Q6553202 39.81, 116.3 x 39.98, 116.4
    { 6, 35455, NoLogo, LineMetaDataContent::Subway, Color{0x1d2088} }, // 5 OSM: 13626146 WD: Q10946024 29.81, 121.5 x 29.92, 121.6
    { 59, 35476, NoLogo, LineMetaDataContent::Subway, Color{0xffe400} }, // 13 OSM: 13633615 WD: Q10938159 39.15, 121.7 x 39.43, 121.9
    { 5669, 35497, NoLogo, LineMetaDataContent::LocalTrain, Color{} }, // RE 3 OSM: 13646696 WD: Q93290679 48.14, 11.48 x 48.78, 13.45
    { 6, 35513, NoLogo, LineMetaDataContent::Subway, Color{0xa43034} }, // 5 OSM: 13647962 WD: Q11124520 30.43, 114.3 x 30.65, 114.4
    { 26, 35533, NoLogo, LineMetaDataContent::Subway, Color{0xc24c6d} }, // 16 OSM: 13648363 WD: Q11124505 30.27, 114 x 30.51, 114.2
    { 736, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xee0000} }, // E7 OSM: 13649968 48.1, 11.58 x 48.14, 11.61
    { 9, NoLogo, 28116, LineMetaDataContent::Subway, Color{0x1c7736} }, // 4 OSM: 13652091 WD: Q10940016 39.1, 117.2 x 39.14, 117.4
    { 102, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xee0000} }, // 37 OSM: 13664761 48.14, 11.6 x 48.18, 11.64
    { 9, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x00a560} }, // 4 OSM: 13681035 WD: Q15907959 28.6, 115.7 x 28.72, 116
    { 1610, 35554, 2455, LineMetaDataContent::RapidTransit, Color{0xe6007e} }, // S31 OSM: 13708521 WD: Q116125183 47.1, 15.62 x 47.22, 15.71
    { 19, NoLogo, 28116, LineMetaDataContent::Subway, Color{0x602e7c} }, // 8 OSM: 13711701 WD: Q10940012 38.98, 117.3 x 39.04, 117.4
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xca9822} }, // 6 OSM: 13743101 WD: Q121316067 50.89, 10.56 x 50.9, 10.58
    { 687, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe10d19} }, // A OSM: 13746337 WD: Q2204240 48.52, 7.694 x 48.6, 7.754
    { 271, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009ee0} }, // B OSM: 13746399 WD: Q2799227 48.55, 7.689 x 48.63, 7.769
    { 1285, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xb4532f} }, // S20 OSM: 13763963 47.33, 9.359 x 47.43, 9.462
    { 3990, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xc6912f} }, // S23 OSM: 13763964 47.29, 9.252 x 47.41, 9.437
    { 3524, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0xb55b59} }, // S26 OSM: 13763966 WD: Q819377 47.45, 9.59 x 47.47, 9.601
    { 321, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x66a4d9} }, // S25 OSM: 13763967 WD: Q337800 47.45, 9.493 x 47.48, 9.541
    { 145, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf38230} }, // 14 OSM: 13773639 WD: Q108223064 45.44, 9.117 x 45.5, 9.188
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf38230} }, // 2 OSM: 13792262 WD: Q108223056 45.44, 9.139 x 45.5, 9.188
    { 149, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf38230} }, // 15 OSM: 13795534 WD: Q108223065 45.38, 9.149 x 45.46, 9.19
    { 5674, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe31837} }, // Ferny Grove OSM: 13878514 WD: Q5445172 -27.47, 152.9 x -27.4, 153
    { 5686, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa54399} }, // Doomben OSM: 13885130 WD: Q5297079 -27.47, 153 x -27.42, 153.1
    { 3282, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfe5000} }, // SEAFRD OSM: 13890308 -35.19, 138.5 x -34.92, 138.6
    { 145, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x81c180} }, // 14 OSM: 13890546 WD: Q122382729 49.79, 18.26 x 49.86, 18.32
    { 5694, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x007dc3} }, // OUTHA OSM: 13901930 WD: Q7111976 -34.92, 138.5 x -34.78, 138.6
    { 5700, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x007dc3} }, // GRNG OSM: 13901931 WD: Q5595697 -34.92, 138.5 x -34.88, 138.6
    { 5705, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xc23b33} }, // GAWC OSM: 13903112 WD: Q5528455 -34.92, 138.6 x -34.59, 138.7
    { 5710, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfe5000} }, // FLNDRS OSM: 13905568 WD: Q7821676 -35.02, 138.6 x -34.92, 138.6
    { 5717, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x00ffff} }, // Aqua OSM: 13916711 WD: Q59155699 18.51, 73.8 x 18.56, 73.91
    { 1570, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x800080} }, // Purple OSM: 13917129 WD: Q59155676 18.53, 73.8 x 18.63, 73.86
    { 5722, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x1578be} }, // Redcliffe Peninsula OSM: 13945821 WD: Q7419371 -27.47, 153 x -27.22, 153.1
    { 281, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xcc5923} }, // T1 OSM: 13962101 WD: Q30947487 30.4, 114.1 x 30.5, 114.2
    { 60, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf38230} }, // 3 OSM: 13986519 WD: Q108223057 45.4, 9.174 x 45.46, 9.188
    { 60, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0000ff} }, // 3 OSM: 13986696 WD: Q54366530 17.39, 78.38 x 17.45, 78.56
    { 110, 35573, NoLogo, LineMetaDataContent::Subway, Color{0xcd5228} }, // 22 OSM: 13988001 WD: Q32177258 22.94, 113.3 x 23.02, 113.4
    { 16, 20020, NoLogo, LineMetaDataContent::Subway, Color{0xffff00} }, // 2 OSM: 13989917 WD: Q28419528 19.13, 72.83 x 19.26, 72.87
    { 42, 20020, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // 7 OSM: 13989918 WD: Q28419537 19.11, 72.85 x 19.25, 72.87
    { 44, 35594, 2455, LineMetaDataContent::RapidTransit, Color{0xec008c} }, // S5 OSM: 13995159 WD: Q67882950 48.27, 14.02 x 48.3, 14.29
    { 217, 35605, 2455, LineMetaDataContent::RapidTransit, Color{0x3f318f} }, // S3 OSM: 13995160 WD: Q67882855 48.26, 14.29 x 48.36, 14.52
    { 51, 35616, 2455, LineMetaDataContent::RapidTransit, Color{0x00aaad} }, // S2 OSM: 13995161 WD: Q67882763 48.16, 14.02 x 48.29, 14.29
    { 63, 35627, 2455, LineMetaDataContent::RapidTransit, Color{0xf58220} }, // S1 OSM: 13995162 WD: Q67882646 48.02, 14.29 x 48.3, 14.52
    { 306, 35638, 2455, LineMetaDataContent::RapidTransit, Color{0x96bc33} }, // S4 OSM: 13995163 WD: Q67882906 47.91, 14.1 x 48.29, 14.29
    { 227, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffff00} }, // 27 OSM: 14001354 WD: Q121545133 42.66, 23.28 x 42.73, 23.32
    { 138, 35649, NoLogo, LineMetaDataContent::Subway, Color{0x862041} }, // 9 OSM: 14004564 WD: Q15917000 29.54, 106.4 x 29.76, 106.6
    { 5742, 15132, 10419, LineMetaDataContent::RapidTransit, Color{0x159dd9} }, // R40 OSM: 14008626 WD: Q96483953 48.23, 16.21 x 48.35, 16.37
    { 67, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf38230} }, // 10 OSM: 14011006 WD: Q108223062 45.45, 9.163 x 45.49, 9.206
    { 5746, 35674, NoLogo, LineMetaDataContent::LongDistanceTrain, Color{0x1eb2b3} }, // IR 66 OSM: 14049006 WD: Q116053240 46.93, 6.811 x 47.1, 7.439
    { 1725, 35689, 10083, LineMetaDataContent::Tramway, Color{0x873f98} }, // T7 OSM: 14071538 WD: Q98842997 45.76, 4.923 x 45.78, 4.981
    { 9, 35709, 9126, LineMetaDataContent::Subway, Color{0x9933ff} }, // 4 OSM: 14074756 WD: Q55663681 41.21, 69.22 x 41.3, 69.37
    { 6, 35735, NoLogo, LineMetaDataContent::Subway, Color{0x893b67} }, // 5 OSM: 14085418 WD: Q25305553 25.98, 119.2 x 26.11, 119.4
    { 3224, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00a49f} }, // B1 OSM: 14125993 WD: Q7521893 39.91, 32.58 x 39.97, 32.97
    { 5752, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00467f} }, // Shorncliffe OSM: 14136709 WD: Q7501515 -27.47, 153 x -27.32, 153.1
    { 5764, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x094b8d} }, // LIL OSM: 14142941 WD: Q6548623 -37.83, 144.9 x -37.76, 145.3
    { 67, 35754, NoLogo, LineMetaDataContent::Tramway, Color{0xb3cb6d} }, // 10 OSM: 14166437 WD: Q18638829 39.45, -0.378 x 39.46, -0.3348
    { 5768, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffa500} }, // 7AB OSM: 14194208 WD: Q108058493 51.72, 19.41 x 51.78, 19.55
    { 16, 35786, NoLogo, LineMetaDataContent::Tramway, Color{0x229922} }, // 2 OSM: 14211347 WD: Q1854674 51.18, 4.373 x 51.26, 4.464
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // 2 OSM: 14215022 WD: Q97325177 37.71, 112.6 x 37.92, 112.6
    { 5772, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf3b015} }, // MTR OSM: 14217249 WD: Q17628181 -34.17, -70.75 x -33.45, -70.68
    { 5776, 35808, NoLogo, LineMetaDataContent::LocalTrain, Color{} }, // RB 73 OSM: 14228504 WD: Q113458371 47.57, 10.32 x 47.71, 10.58
    { 2597, 35825, 5804, LineMetaDataContent::Tramway, Color{0x827a04} }, // T10 OSM: 14232362 WD: Q3537026 48.76, 2.248 x 48.79, 2.304
    { 1778, 35859, 3675, LineMetaDataContent::Tramway, Color{0x8a5f20} }, // T13 OSM: 14263358 WD: Q3515106 48.8, 2.043 x 48.97, 2.095
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x6899ff} }, // 8 OSM: 14300554 WD: Q124657538 55.86, 49 x 55.87, 49.11
    { 27, 35893, NoLogo, LineMetaDataContent::Subway, Color{0x005bac} }, // 6 OSM: 14303415 WD: Q46096730 28.17, 112.8 x 28.22, 113.2
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x1251b4} }, // 2 OSM: 14306359 WD: Q110315870 55.77, 49.09 x 55.79, 49.11
    { 42, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xb64dce} }, // 7 OSM: 14306360 WD: Q124657537 55.73, 49.07 x 55.83, 49.22
    { 5782, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffcd28} }, // Z40 OSM: 14319938 WD: Q112225436 46.37, 18.15 x 47.5, 19.04
    { 6, 35923, NoLogo, LineMetaDataContent::Tramway, Color{0x931980} }, // 5 OSM: 14320910 WD: Q123158516 56.81, 53.15 x 56.88, 53.26
    { 6, 35942, 13598, LineMetaDataContent::Tramway, Color{0x95254c} }, // 5 OSM: 14329573 WD: Q16655754 43.59, 3.822 x 43.65, 3.876
    { 44, 35952, 226, LineMetaDataContent::RapidTransit, Color{0xf3c737} }, // S5 OSM: 14372453 WD: Q116211506 46.53, 13.83 x 46.62, 14.04
    { 359, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x3bbfef} }, // Blue OSM: 14381218 30.2, -97.75 x 30.42, -97.66
    { 145, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009fe3} }, // 14 OSM: 14402833 51.33, 12.32 x 51.34, 12.38
    { 74, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 21 OSM: 14412282 WD: Q122439371 45.24, 27.94 x 45.3, 27.97
    { 247, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 24 OSM: 14412292 WD: Q122439376 45.19, 27.9 x 45.25, 27.95
    { 5786, 35973, NoLogo, LineMetaDataContent::LongDistanceTrain, Color{0xed1c24} }, // RE80 OSM: 14432436 WD: Q107263607 45.49, 8.801 x 46.18, 9.274
    { 5791, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x187dcd} }, // JT OSM: 14434654 WD: Q112169762 29.31, 106.3 x 29.41, 106.4
    { 5794, 35987, 3675, LineMetaDataContent::Tramway, Color{0xb90845} }, // T12 OSM: 14456255 WD: Q3536986 48.62, 2.256 x 48.73, 2.427
    { 2336, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xef8016} }, // R12 OSM: 14460896 59.31, 24.42 x 59.44, 24.74
    { 5798, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xc33032} }, // Jinyi OSM: 14489040 WD: Q117774718 29.08, 119.6 x 29.33, 120.1
    { 5804, NoLogo, 4285, LineMetaDataContent::RapidTransit, Color{0xadca00} }, // S88 OSM: 14500437 WD: Q124286542 49.78, 14.18 x 50.08, 14.47
    { 47, NoLogo, 4285, LineMetaDataContent::RapidTransit, Color{0xadca00} }, // S8 OSM: 14500438 WD: Q107983477 49.83, 14.37 x 50.08, 14.7
    { 27, 36021, NoLogo, LineMetaDataContent::Subway, Color{0x005eb8} }, // 6 OSM: 14509136 WD: Q24886992 25.9, 119.4 x 26.02, 119.6
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x45b09f} }, // 11 OSM: 14542032 WD: Q120720209 50.01, 19.89 x 50.04, 20
    { 138, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf38230} }, // 9 OSM: 14552272 WD: Q108223061 45.45, 9.17 x 45.49, 9.208
    { 2155, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x228b22} }, // V OSM: 14576928 WD: Q114313190 -17.47, -66.33 x -17.4, -66.15
    { 584, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // R OSM: 14576929 WD: Q114312991 -17.46, -66.15 x -17.4, -66.12
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffcc99} }, // 2 OSM: 14594830 WD: Q106963559 22.67, 114 x 22.72, 114.1
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x93cb44} }, // 1 OSM: 14594832 WD: Q106963564 22.67, 114 x 22.69, 114.1
    { 5808, 36040, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffce00} }, // S90 OSM: 14604626 WD: Q108075807 45.87, 8.92 x 46.17, 9.005
    { 1285, 36053, NoLogo, LineMetaDataContent::RapidTransit, Color{0x007dc6} }, // S20 OSM: 14604783 WD: Q3832731 46.15, 8.801 x 46.22, 9.042
    { 1046, 36066, NoLogo, LineMetaDataContent::RapidTransit, Color{0xed1c24} }, // S10 OSM: 14604788 WD: Q3832722 45.81, 8.933 x 46.35, 9.074
    { 2088, 36079, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00a651} }, // S30 OSM: 14604990 WD: Q3832740 45.66, 8.624 x 46.16, 8.942
    { 173, 36092, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe35a13} }, // S60 OSM: 14605103 WD: Q112899163 45.97, 8.86 x 46.01, 8.948
    { 265, 36105, NoLogo, LineMetaDataContent::RapidTransit, Color{0x6cc27f} }, // S40 OSM: 14605384 WD: Q47219003 45.81, 8.833 x 45.87, 9.074
    { 234, 36118, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7d4808} }, // S50 OSM: 14605385 WD: Q47219058 45.6, 8.704 x 46.35, 9.042
    { 56, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // 1 OSM: 14611374 WD: Q48868979 38.64, -9.167 x 38.69, -9.147
    { 60, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // 3 OSM: 14611403 WD: Q48868985 38.66, -9.208 x 38.69, -9.147
    { 16, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffff00} }, // 2 OSM: 14611445 WD: Q48868981 38.64, -9.18 x 38.67, -9.151
    { 153, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x05c3de} }, // 19 OSM: 14613133 WD: Q48903466 30.22, 120 x 30.3, 120.5
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 2 OSM: 14630830 WD: Q122387791 50.49, 13.64 x 50.51, 13.66
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 1 OSM: 14630831 WD: Q122387790 50.49, 13.6 x 50.61, 13.65
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 4 OSM: 14630832 WD: Q122387793 50.49, 13.6 x 50.61, 13.65
    { 60, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 3 OSM: 14630833 WD: Q122387792 50.51, 13.6 x 50.61, 13.66
    { 27, 36131, NoLogo, LineMetaDataContent::Subway, Color{0x920783} }, // 6 OSM: 14642983 WD: Q15935783 34.67, 113.4 x 34.74, 113.5
    { 138, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 9 OSM: 14644778 47.2, 38.88 x 47.22, 38.94
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // 2 OSM: 14657624 WD: Q65081142 22.98, 72.53 x 23.1, 72.6
    { 572, 36150, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe96bb0} }, // K OSM: 14669757 WD: Q5184164 33.96, -118.4 x 34.02, -118.3
    { 4210, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0bd5fe} }, // Airport OSM: 14677578 WD: Q109448267 -31.98, 115.8 x -31.92, 116
    { 2187, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe3000b} }, // 4A OSM: 14712448 WD: Q121317832 49.48, 8.364 x 49.53, 8.509
    { 5812, 36175, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7a745a} }, // F4 OSM: 14738977 WD: Q31193345 41.08, 29.05 x 41.09, 29.05
    { 281, 36203, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7bb932} }, // T1 OSM: 14758569 WD: Q5985905 36.41, -6.288 x 36.53, -6.134
    { 258, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x7b2c1c} }, // 42 OSM: 14759884 WD: Q123363432 50.08, 14.38 x 50.1, 14.43
    { 145, 36221, NoLogo, LineMetaDataContent::Subway, Color{0xf2c75c} }, // 14 OSM: 14764338 WD: Q21245993 22.54, 114.1 x 22.76, 114.4
    { 5815, NoLogo, 16871, LineMetaDataContent::RapidTransit, Color{0x9364cc} }, // XR OSM: 14773915 WD: Q111297173 51.46, -0.9747 x 51.63, 0.3296
    { 5818, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfdda24} }, // GR01 OSM: 14785799 WD: Q55074880 37.06, 37.33 x 37.17, 37.45
    { 56, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 14870574 WD: Q47015943 31.91, 120.8 x 32.11, 121
    { 18, 36245, 20592, LineMetaDataContent::Subway, Color{0x23387f} }, // M8 OSM: 14900218 WD: Q5996245 40.95, 29.09 x 41.03, 29.16
    { 67, NoLogo, 28116, LineMetaDataContent::Subway, Color{0xb9cf09} }, // 10 OSM: 14903908 WD: Q10940015 39.05, 117.2 x 39.15, 117.3
    { 5823, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xcccccc} }, // AGTS OSM: 14910918 WD: Q5259735 39.85, -104.7 x 39.86, -104.7
    { 16, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xbf4525} }, // 2 OSM: 14933919 WD: Q114608664 60.35, 5.289 x 60.39, 5.362
    { 56, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xed4800} }, // 1 OSM: 14934588 WD: Q28412165 27.48, 118 x 27.63, 118.1
    { 55, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 11 OSM: 14937318 WD: Q123346615 51.53, 45.98 x 51.6, 46.03
    { 8, 36273, 7769, LineMetaDataContent::Subway, Color{0x2f4481} }, // M4 OSM: 14937470 WD: Q943476 45.46, 9.198 x 45.47, 9.278
    { 507, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x30556e} }, // L1 OSM: 14942883 WD: Q28759219 56.15, 10.2 x 56.41, 10.88
    { 15, 36293, NoLogo, LineMetaDataContent::Subway, Color{0xa192b2} }, // 12 OSM: 14944729 WD: Q11559867 22.47, 113.8 x 22.73, 113.9
    { 5828, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x428d89} }, // 6B OSM: 14953717 WD: Q114025973 22.77, 113.9 x 22.81, 114
    { 511, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x30556e} }, // L2 OSM: 14973319 WD: Q28759221 55.97, 10.12 x 56.23, 10.23
    { 243, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xa0216e} }, // 20 OSM: 14987053 47.39, 8.353 x 47.43, 8.489
    { 1856, NoLogo, 9368, LineMetaDataContent::RapidTransit, Color{0xed6fa7} }, // S19 OSM: 14987372 WD: Q110973246 50.4, 4.335 x 50.9, 4.488
    { 5831, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00aff0} }, // S74 OSM: 14995079 WD: Q115171353 47.72, 18.11 x 47.78, 18.74
    { 5835, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffff00} }, // S 10 OSM: 14995860 51.32, 12.27 x 51.37, 12.39
    { 60, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xca0000} }, // 3 OSM: 14999192 WD: Q121662729 54.69, 20.47 x 54.72, 20.53
    { 5840, 36317, NoLogo, LineMetaDataContent::LocalTrain, Color{0x816da6} }, // RE8 OSM: 15001253 WD: Q112992594 51.46, 11.36 x 53.9, 13.71
    { 1985, 36336, 9368, LineMetaDataContent::LocalTrain, Color{0x202776} }, // S53 OSM: 15014017 WD: Q115285815 50.85, 3.601 x 51.11, 3.986
    { 631, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xcd2c0e} }, // S9 OSM: 15018427 WD: Q125989610 49.74, 18.2 x 49.82, 18.62
    { 281, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfdec4a} }, // T1 OSM: 15022247 WD: Q950794 45.69, 9.676 x 45.76, 9.798
    { 667, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xbe1622} }, // 55 OSM: 15036277 WD: Q121368518 44.43, 26.11 x 44.44, 26.18
    { 3182, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xee4b95} }, // TL10 OSM: 15045727 WD: Q125903428 51.37, -0.4163 x 51.88, 0.612
    { 331, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x81cae8} }, // S33 OSM: 15046198 WD: Q125989622 49.63, 17.61 x 49.8, 17.94
    { 1042, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x81cae8} }, // S32 OSM: 15046201 WD: Q125989621 49.64, 17.91 x 49.71, 17.96
    { 1610, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x81cae8} }, // S31 OSM: 15046203 WD: Q125989620 49.71, 18.01 x 49.75, 18.07
    { 9, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x007a33} }, // 4 OSM: 15051229 WD: Q15947246 36.06, 120.3 x 36.14, 120.6
    { 2113, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x81cae8} }, // S34 OSM: 15052368 WD: Q125989623 49.6, 17.94 x 49.64, 18.01
    { 51, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa05a43} }, // S2 OSM: 15052628 WD: Q125989602 49.52, 18.21 x 49.91, 18.76
    { 217, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x3b91ca} }, // S3 OSM: 15052633 WD: Q125989603 49.57, 17.74 x 49.9, 18.36
    { 47, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xdd801e} }, // S8 OSM: 15052634 WD: Q125989609 49.54, 18.04 x 49.71, 18.15
    { 3840, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x002f87} }, // F3 OSM: 15054273 WD: Q10886733 22.82, 113.1 x 23.02, 113.3
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc80404} }, // 4 OSM: 15057097 WD: Q118322264 55.87, 26.51 x 55.89, 26.55
    { 63, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0061ae} }, // S1 OSM: 15058106 WD: Q48899113 28.32, 121.3 x 28.66, 121.4
    { 290, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x9040ba} }, // S6 OSM: 15058252 WD: Q125989607 49.47, 17.96 x 49.85, 18.37
    { 5844, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // IR85 OSM: 15058598 47.49, 19.08 x 47.78, 19.95
    { 26, 36357, NoLogo, LineMetaDataContent::Subway, Color{0x1e22aa} }, // 16 OSM: 15059918 WD: Q11215578 22.69, 114.2 x 22.74, 114.4
    { 5849, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x6699cc} }, // 215 OSM: 15059991 WD: Q105045768 46.95, 6.839 x 46.99, 6.928
    { 27, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x006e34} }, // 6 OSM: 15060937 WD: Q97257710 23.73, 90.36 x 23.87, 90.42
    { 5853, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x83898f} }, // 58d OSM: 15062383 -37.84, 145 x -37.81, 145
    { 60, 26935, 26958, LineMetaDataContent::Subway, Color{0x800080} }, // 3 OSM: 15068969 WD: Q27502952 22.45, 88.3 x 22.52, 88.32
    { 5857, 36381, 20592, LineMetaDataContent::Subway, Color{0xa1609b} }, // M11 OSM: 15083966 WD: Q31193348 41.07, 28.7 x 41.26, 29.01
    { 5861, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffdd00} }, // D7 OSM: 15087039 51.03, 17 x 51.7, 17.43
    { 5864, 36410, 20592, LineMetaDataContent::Subway, Color{} }, // M14 OSM: 15099622 WD: Q31193350 41.02, 29.05 x 41.08, 29.09
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xb141fc} }, // 2 OSM: 15203534 WD: Q123341836 53.73, 20.48 x 53.78, 20.5
    { 2376, 36439, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // Sul OSM: 15268630 WD: Q10374983 -6.071, -35.26 x -5.78, -35.21
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe77817} }, // 5 OSM: 15268961 WD: Q121410308 47.14, 27.54 x 47.17, 27.64
    { 3188, NoLogo, 3439, LineMetaDataContent::Tramway, Color{0x706e6d} }, // L9 OSM: 15320668 WD: Q11690013 38.55, -0.1354 x 38.84, 0.1131
    { 5868, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff6500} }, // D4 OSM: 15321385 50.69, 16.48 x 51.1, 17.07
    { 42, 36453, 12277, LineMetaDataContent::Subway, Color{0x4a7729} }, // 7 OSM: 15336346 WD: Q10906687 32.11, 118.8 x 32.13, 118.9
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 2 OSM: 15354644 WD: Q123362825 41.22, 36.34 x 41.29, 36.46
    { 60, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffa500} }, // 3 OSM: 15360948 WD: Q123362853 41.37, 36.19 x 41.38, 36.23
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 1 OSM: 15378703 WD: Q112134173 41.29, 36.23 x 41.37, 36.34
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf38230} }, // 5 OSM: 15402181 WD: Q108223059 45.47, 9.19 x 45.51, 9.238
    { 703, NoLogo, 32729, LineMetaDataContent::RapidTransit, Color{0xefd51f} }, // RE3 OSM: 15413862 WD: Q115749580 46.6, 6.906 x 46.85, 7.191
    { 1465, NoLogo, 32729, LineMetaDataContent::RapidTransit, Color{0xc31622} }, // RE2 OSM: 15413942 WD: Q115749575 46.6, 6.906 x 46.95, 7.44
    { 572, 36473, NoLogo, LineMetaDataContent::RapidTransit, Color{0xc3b091} }, // K OSM: 15443527 WD: Q10914168 24.94, 121.5 x 24.99, 121.5
    { 5871, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x2e2076} }, // 240 OSM: 15446398 50.74, 15.52 x 51.1, 17.04
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf38230} }, // 12 OSM: 15460064 WD: Q108223063 45.46, 9.119 x 45.52, 9.224
    { 1295, 36501, NoLogo, LineMetaDataContent::Tramway, Color{0x0d0dff} }, // T3 OSM: 15463464 WD: Q123413686 37.03, 37.31 x 37.09, 37.35
    { 109, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x3a6198} }, // S22 OSM: 15463831 WD: Q115743565 47.29, 7.688 x 47.31, 7.71
    { 281, 36530, NoLogo, LineMetaDataContent::Tramway, Color{0xff2b0a} }, // T1 OSM: 15470243 WD: Q123413668 37.02, 37.32 x 37.07, 37.38
    { 700, 36559, NoLogo, LineMetaDataContent::Tramway, Color{0x08ff08} }, // T2 OSM: 15471518 WD: Q123413681 37.06, 37.33 x 37.09, 37.38
    { 16, 36588, NoLogo, LineMetaDataContent::Subway, Color{0x229954} }, // 2 OSM: 15510494 WD: Q97218492 29.57, 52.5 x 29.62, 52.53
    { 5875, 36612, 20592, LineMetaDataContent::Subway, Color{0xc8cb2d} }, // M12 OSM: 15520693 WD: Q31193310 40.97, 29.06 x 41.04, 29.12
    { 26, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf38230} }, // 16 OSM: 15532977 WD: Q108223067 45.45, 9.121 x 45.48, 9.229
    { 153, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf38230} }, // 19 OSM: 15535050 WD: Q108223068 45.46, 9.151 x 45.5, 9.238
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffb752} }, // 1 OSM: 15540826 WD: Q116860182 35.92, 0.06022 x 35.98, 0.1102
    { 247, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf38230} }, // 24 OSM: 15545551 WD: Q108223069 45.42, 9.188 x 45.46, 9.204
    { 16, 36641, 36666, LineMetaDataContent::Subway, Color{0x58e558} }, // 2 OSM: 15545706 WD: Q116978502 35.7, 50.88 x 35.86, 51.01
    { 58, 36716, 20592, LineMetaDataContent::Subway, Color{0x0ca950} }, // M13 OSM: 15547419 WD: Q48742876 40.98, 29.04 x 41.03, 29.25
    { 1497, 36745, 20592, LineMetaDataContent::Subway, Color{0xf19ebf} }, // M7 OSM: 15547431 WD: Q16949749 41.03, 28.67 x 41.09, 29.01
    { 5879, 36773, 20592, LineMetaDataContent::Subway, Color{0xffd400} }, // M9 OSM: 15547473 WD: Q25209252 40.98, 28.77 x 41.08, 28.86
    { 5882, 36801, 20592, LineMetaDataContent::Subway, Color{} }, // M20 OSM: 15547627 WD: Q109779737 40.97, 28.62 x 41.03, 28.95
    { 392, NoLogo, 6578, LineMetaDataContent::Tramway, Color{0xce1417} }, // 30 OSM: 15554589 WD: Q123168050 59.92, 30.38 x 59.93, 30.44
    { 227, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf38230} }, // 27 OSM: 15555911 WD: Q108223070 45.45, 9.194 x 45.46, 9.255
    { 2619, 36830, 33349, LineMetaDataContent::Tramway, Color{0x73c0d5} }, // T3a OSM: 15568057 WD: Q117008328 38.72, 35.4 x 38.79, 35.63
    { 1295, 36830, 33349, LineMetaDataContent::Tramway, Color{0x73c0d5} }, // T3 OSM: 15568179 WD: Q117008328 38.72, 35.4 x 38.79, 35.63
    { 5886, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf38230} }, // 31/ OSM: 15571764 WD: Q108223071 45.49, 9.191 x 45.56, 9.218
    { 332, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf38230} }, // 33 OSM: 15572354 WD: Q108223072 45.47, 9.182 x 45.49, 9.242
    { 5890, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf5b85a} }, // 6b OSM: 15589420 WD: Q122781782 45.74, 21.22 x 45.76, 21.25
    { 265, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x70ad46} }, // S40 OSM: 15592519 52.07, 20.95 x 52.2, 21.02
    { 306, NoLogo, 9590, LineMetaDataContent::RapidTransit, Color{0x2f7b20} }, // S4 OSM: 15592520 WD: Q124516393 52.07, 20.94 x 52.45, 21.03
    { 687, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffbf00} }, // A OSM: 15603175 WD: Q4647009 32.98, -97.13 x 33.21, -96.93
    { 5893, 36871, NoLogo, LineMetaDataContent::LocalTrain, Color{0x697c8a} }, // RB32 OSM: 15608623 WD: Q112802971 52.3, 13.27 x 52.37, 13.51
    { 5898, 36891, NoLogo, LineMetaDataContent::LocalTrain, Color{} }, // RB 50 OSM: 15608624 WD: Q62594268 50.03, 9.683 x 50.19, 10.25
    { 6, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xe60012} }, // 5 OSM: 15611913 WD: Q28411250 38.88, 121.6 x 39.05, 121.7
    { 5904, 36908, NoLogo, LineMetaDataContent::LocalTrain, Color{0x501689} }, // RB21 OSM: 15615526 WD: Q105947745 52.39, 12.94 x 52.55, 13.39
    { 5909, 36928, NoLogo, LineMetaDataContent::LocalTrain, Color{0xad5937} }, // RB37 OSM: 15615531 WD: Q112803049 52.24, 12.96 x 52.42, 13.19
    { 341, NoLogo, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 23 OSM: 15624869 WD: Q100741440 47.47, 19.05 x 47.51, 19.09
    { 5914, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008752} }, // Caboolture OSM: 15625847 WD: Q5015753 -27.47, 153 x -27.08, 153.1
    { 5925, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008752} }, // Sunshine Coast OSM: 15631421 WD: Q16927337 -27.47, 152.7 x -26.16, 153.1
    { 687, 36948, 36968, LineMetaDataContent::Subway, Color{0x00a562} }, // A OSM: 15640862 WD: Q1292805 50.07, 14.34 x 50.1, 14.52
    { 271, 37006, 36968, LineMetaDataContent::Subway, Color{0xf8b322} }, // B OSM: 15640873 WD: Q1460442 50.04, 14.29 x 50.11, 14.58
    { 403, 37026, 36968, LineMetaDataContent::Subway, Color{0xcf003d} }, // C OSM: 15640889 WD: Q168571 50.03, 14.43 x 50.13, 14.53
    { 535, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00ad4f} }, // E OSM: 15654116 WD: Q118612325 36.78, 10.1 x 36.79, 10.18
    { 1231, 37046, 37068, LineMetaDataContent::Subway, Color{0x35ab52} }, // M3 OSM: 15655643 WD: Q2420584 50.39, 30.43 x 50.48, 30.7
    { 352, 37088, 37068, LineMetaDataContent::Subway, Color{0xdd2a26} }, // M1 OSM: 15655644 WD: Q2334153 50.44, 30.35 x 50.47, 30.65
    { 433, 37110, 37068, LineMetaDataContent::Subway, Color{0x2782c5} }, // M2 OSM: 15655645 WD: Q2204296 50.37, 30.45 x 50.52, 30.53
    { 5940, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffc425} }, // Gold Coast OSM: 15667052 WD: Q5578678 -28.1, 153 x -27.46, 153.4
    { 359, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0000ff} }, // Blue OSM: 15668739 WD: Q116413296 6.446, 3.312 x 6.479, 3.395
    { 153, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffa500} }, // 19 OSM: 15670312 WD: Q122339250 51.72, 19.43 x 51.83, 19.49
    { 42, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf38230} }, // 7 OSM: 15677604 WD: Q108223060 45.49, 9.191 x 45.52, 9.234
    { 22, 37132, NoLogo, LineMetaDataContent::Subway, Color{0x2cd5c4} }, // 18 OSM: 15749314 WD: Q17038985 29.4, 106.4 x 29.55, 106.5
    { 19, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff8000} }, // 8 OSM: 15782337 WD: Q47012748 -33.57, -70.61 x -33.41, -70.56
    { 56, NoLogo, 37157, LineMetaDataContent::Subway, Color{0xe31d1b} }, // 1 OSM: 15797036 WD: Q18419905 -0.2955, -78.56 x -0.1546, -78.48
    { 275, 37168, 10163, LineMetaDataContent::Tramway, Color{0x91619d} }, // D OSM: 15797847 WD: Q16655779 44.82, -0.6675 x 44.89, -0.55
    { 306, 37202, 12277, LineMetaDataContent::Subway, Color{0xff631b} }, // S4 OSM: 15804062 WD: Q15939013 32.2, 118.3 x 32.31, 118.6
    { 5951, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00aff0} }, // S225 OSM: 15809425 46.91, 19.7 x 47.18, 20.18
    { 138, 37232, NoLogo, LineMetaDataContent::Subway, Color{0xff00ff} }, // 9 OSM: 15809438 WD: Q47012852 -33.62, -70.65 x -33.43, -70.57
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 6 OSM: 15840812 WD: Q122585347 55.81, 37.41 x 55.86, 37.51
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 4 OSM: 15840813 WD: Q122585346 55.75, 37.66 x 55.82, 37.73
    { 138, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 9 OSM: 15840817 WD: Q122585350 55.78, 37.58 x 55.79, 37.61
    { 243, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x595fa7} }, // 20 OSM: 15858526 52.38, 16.91 x 52.41, 16.98
    { 153, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0c7cac} }, // 19 OSM: 15865362 WD: Q123224131 51.11, 16.96 x 51.14, 17.08
    { 51, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0xffc0cb} }, // S2 OSM: 15865690 WD: Q115756448 46.7, 9.386 x 46.85, 9.531
    { 63, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x62a0ea} }, // S1 OSM: 15865708 WD: Q115756382 46.8, 9.386 x 46.98, 9.689
    { 22, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xee1d23} }, // 18 OSM: 15867095 WD: Q107024375 41.15, -8.668 x 41.15, -8.615
    { 5956, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe7a4d0} }, // M206 OSM: 15874032 50.58, 16.12 x 51.1, 17.04
    { 5961, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xc65312} }, // D3 OSM: 15898497 51.1, 16.84 x 51.61, 17.04
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // 2 OSM: 15924888 WD: Q65050458 36.03, 103.8 x 36.07, 103.9
    { 178, NoLogo, 3913, LineMetaDataContent::RapidTransit, Color{0x035eb9} }, // O OSM: 15925639 WD: Q118924451 60.46, 25.66 x 60.98, 26.96
    { 1083, NoLogo, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 1A OSM: 15953835 WD: Q15982260 47.48, 19.03 x 47.55, 19.11
    { 1083, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfdc434} }, // 1A OSM: 15961882 WD: Q56388740 46.24, 20.12 x 46.27, 20.15
    { 5964, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xb70a06} }, // D9 OSM: 15984417 50.1, 16.63 x 51.1, 17.07
    { 5967, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff8500} }, // 223 OSM: 15984569 50.69, 16.33 x 51.1, 17.07
    { 5971, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xbde705} }, // 245 OSM: 15984766 50.4, 16.24 x 50.79, 16.66
    { 26, NoLogo, 3169, LineMetaDataContent::Tramway, Color{0xce1417} }, // 16 OSM: 15997372 WD: Q123339547 50.46, 30.46 x 50.52, 30.52
    { 5975, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce0000} }, // PR OSM: 16019086 53.24, 19.57 x 53.58, 20.17
    { 5975, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xce0000} }, // PR OSM: 16019103 51.22, 22.57 x 51.25, 22.72
    { 782, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x238132} }, // RL OSM: 16020122 52.17, 20.69 x 52.44, 21.07
    { 5978, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x20409a} }, // CB OSM: 16035222 WD: Q56390365 -6.377, 106.8 x -6.204, 106.9
    { 5981, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x89728e} }, // SCLR OSM: 16056777 33.38, -112.1 x 33.46, -112.1
    { 1717, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x89728e} }, // DPH OSM: 16056811 33.45, -112.1 x 33.45, -112.1
    { 149, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x009b3e} }, // 15 OSM: 16065725 WD: Q120441391 40.85, 14.27 x 41.14, 14.77
    { 26, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x11472c} }, // 16 OSM: 16071949 WD: Q120437141 40.85, 14.24 x 41.35, 14.42
    { 42, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xeb262b} }, // 7 OSM: 16072815 WD: Q1388214 40.83, 14.27 x 40.88, 14.34
    { 59, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x751056} }, // 13 OSM: 16074085 WD: Q120496331 40.63, 14.27 x 40.85, 14.49
    { 145, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x8480d7} }, // 14 OSM: 16074777 WD: Q3743529 40.75, 14.27 x 40.85, 14.54
    { 15, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf799b5} }, // 12 OSM: 16074833 WD: Q3743527 40.8, 14.27 x 40.88, 14.62
    { 5986, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0e6938} }, // BK OSM: 16079480 WD: Q56390372 -6.265, 106.8 x -6.204, 107
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf38230} }, // 1 OSM: 16086391 WD: Q108223055 45.47, 9.119 x 45.52, 9.217
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf38230} }, // 4 OSM: 16086511 WD: Q108223058 45.47, 9.179 x 45.53, 9.192
    { 5989, 37257, NoLogo, LineMetaDataContent::Subway, Color{0xdb7093} }, // Xihuan OSM: 16103884 WD: Q120358322 27.97, 112.9 x 28.1, 112.9
    { 26, 37286, NoLogo, LineMetaDataContent::Subway, Color{0xea8464} }, // 16 OSM: 16104056 WD: Q116783831 34.23, 108.7 x 34.34, 108.8
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x307fe2} }, // 2 OSM: 16136208 WD: Q85883422 30.05, 120.6 x 30.05, 120.7
    { 2167, 37307, 37307, LineMetaDataContent::RapidTransit, Color{0x6bc700} }, // A1 OSM: 16141765 WD: Q19582331 45.44, -73.57 x 45.5, -73.43
    { 231, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x96a7b1} }, // 17 OSM: 16147231 WD: Q123363027 56.76, 60.55 x 56.86, 60.61
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 5 OSM: 16156014 WD: Q121140495 44.03, 42.98 x 44.05, 43.12
    { 42, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 7 OSM: 16156025 WD: Q121140521 44.04, 43.03 x 44.05, 43.06
    { 5996, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x59ff00} }, // D13 OSM: 16172604 51.21, 15.88 x 51.42, 16.17
    { 149, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf7ab64} }, // 15 OSM: 16179482 WD: Q121317829 49.48, 8.463 x 49.51, 8.554
    { 752, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00abe5} }, // GN4 OSM: 16179487 51.52, -0.2073 x 51.9, -0.08581
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xa92683} }, // 4 OSM: 16206854 55.69, 52.41 x 55.77, 52.53
    { 67, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 10 OSM: 16206855 55.67, 52.28 x 55.77, 52.45
    { 138, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x72a891} }, // 9 OSM: 16206856 55.67, 52.28 x 55.77, 52.45
    { 5961, 37347, 31827, LineMetaDataContent::RapidTransit, Color{0xe15d29} }, // D3 OSM: 16213702 WD: Q65127804 55.56, 37.17 x 55.98, 38.24
    { 584, NoLogo, 37372, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // R OSM: 16226515 WD: Q7304510 32, 34.74 x 32.11, 34.89
    { 22, 37388, 8171, LineMetaDataContent::Tramway, Color{0x9ebfe3} }, // 18 OSM: 16241563 WD: Q12013459 50.78, 4.326 x 50.82, 4.341
    { 51, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xe4222b} }, // S2 OSM: 16244469 WD: Q17030015 27.76, 120.7 x 28.13, 121
    { 6000, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xd2a1f3} }, // T46 OSM: 16253188 WD: Q115220048 50.23, 18.99 x 50.27, 19.07
    { 9, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff7f00} }, // 4 OSM: 16253271 WD: Q25346431 25.99, 119.3 x 26.1, 119.4
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0e4094} }, // 12 OSM: 16257454 51.34, 12.37 x 51.38, 12.39
    { 6004, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00467f} }, // Cleveland OSM: 16264432 WD: Q5132306 -27.52, 153 x -27.44, 153.3
    { 6014, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe31837} }, // Beenleigh OSM: 16264773 WD: Q4879912 -27.72, 153 x -27.46, 153.2
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffa500} }, // 6 OSM: 16265222 WD: Q121833005 53.01, 18.59 x 53.06, 18.7
    { 60, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 3 OSM: 16265225 WD: Q55676152 53.01, 18.55 x 53.06, 18.6
    { 42, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffa500} }, // 7 OSM: 16265486 WD: Q123338681 53.01, 18.56 x 53.03, 18.65
    { 6024, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x1f9cd8} }, // NC (SB) OSM: 16270337 WD: Q125156771 53.34, -6.332 x 53.71, -6.112
    { 149, NoLogo, 4977, LineMetaDataContent::Tramway, Color{0x097969} }, // 15 OSM: 16274967 WD: Q122202409 45.06, 7.621 x 45.08, 7.733
    { 5868, 37410, 31827, LineMetaDataContent::RapidTransit, Color{0x3fb485} }, // D4 OSM: 16275214 WD: Q63928373 55.55, 37.07 x 55.8, 38.01
    { 439, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0079bf} }, // 80 OSM: 16298478 WD: Q125869342 45.8, 15.69 x 45.89, 16.24
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0c7cac} }, // 13 OSM: 16299592 WD: Q122307231 51.11, 16.95 x 51.12, 17.09
    { 153, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xa29786} }, // 19 OSM: 16309523 WD: Q114425800 50.05, 14.43 x 50.08, 14.52
    { 67, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x434242} }, // 10 OSM: 16310472 WD: Q122382725 49.77, 18.25 x 49.83, 18.32
    { 341, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 23 OSM: 16317056 WD: Q122439374 45.24, 27.94 x 45.3, 27.96
    { 322, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 25 OSM: 16318124 WD: Q122439377 45.21, 27.92 x 45.25, 27.95
    { 110, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 22 OSM: 16318291 WD: Q122439373 45.24, 27.94 x 45.3, 27.97
    { 6032, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 1S OSM: 16337692 WD: Q122617993 47.07, 21.88 x 47.08, 21.91
    { 3975, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x1934d5} }, // 2R OSM: 16337737 WD: Q122617994 47.04, 21.9 x 47.06, 21.94
    { 6035, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 3N OSM: 16337799 WD: Q122617995 47.03, 21.93 x 47.07, 21.96
    { 6038, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 4N OSM: 16337930 WD: Q122617996 47.03, 21.91 x 47.08, 21.96
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 4 OSM: 16337931 WD: Q122617996 47.03, 21.94 x 47.04, 21.96
    { 42, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x8a8585} }, // 7 OSM: 16358740 -33.38, -70.53 x -33.35, -70.51
    { 149, NoLogo, 34105, LineMetaDataContent::RapidTransit, Color{0x007e79} }, // 15 OSM: 16363614 WD: Q31085928 60.18, 24.81 x 60.23, 25.08
    { 47, 37435, 226, LineMetaDataContent::RapidTransit, Color{0xa46fa9} }, // S8 OSM: 16380270 WD: Q122818946 49.47, 8.444 x 49.69, 8.511
    { 41, 37454, 226, LineMetaDataContent::RapidTransit, Color{0xee499c} }, // S7 OSM: 16384835 WD: Q122818933 49.32, 8.537 x 49.45, 8.676
    { 6041, 37473, 226, LineMetaDataContent::RapidTransit, Color{0xfb3199} }, // S39 OSM: 16388764 WD: Q122818916 49.48, 8.454 x 49.53, 8.482
    { 9, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x4b0082} }, // 4 OSM: 16393681 WD: Q21245990 41.65, 123.4 x 41.88, 123.5
    { 6045, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // Kalayang OSM: 16414281 -6.131, 106.7 x -6.12, 106.7
    { 67, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xbe6254} }, // 10 OSM: 16441473 WD: Q97276018 34.75, 113.4 x 34.75, 113.6
    { 2597, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf2665b} }, // T10 OSM: 16456217 WD: Q115219875 50.3, 18.88 x 50.35, 18.95
    { 6054, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffd700} }, // GLK OSM: 16467689 -28.04, 153.3 x -27.93, 153.4
    { 6058, 37493, 3582, LineMetaDataContent::RapidTransit, Color{0xb2d019} }, // C-5a OSM: 16468881 WD: Q16595900 43.37, -5.856 x 43.54, -5.676
    { 153, 37522, NoLogo, LineMetaDataContent::Subway, Color{0x5c88db} }, // 19 OSM: 16494854 WD: Q46461818 30.27, 103.8 x 30.76, 104.5
    { 9, NoLogo, 3169, LineMetaDataContent::Tramway, Color{0x78ccc9} }, // 4 OSM: 16507598 WD: Q123339542 50.48, 30.57 x 50.53, 30.61
    { 6, 6542, 3169, LineMetaDataContent::Tramway, Color{0x78ccc9} }, // 5 OSM: 16507674 WD: Q123339543 50.48, 30.57 x 50.53, 30.63
    { 756, NoLogo, 37533, LineMetaDataContent::Subway, Color{0x77248b} }, // N1 OSM: 16533437 WD: Q17068873 19.02, 73.04 x 19.07, 73.1
    { 6063, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xf0631e} }, // Delhi–Meerut RapidX OSM: 16534370 WD: Q30644700 28.66, 77.37 x 28.84, 77.58
    { 6085, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x1578be} }, // Springfield OSM: 16554068 WD: Q7581106 -27.67, 152.9 x -27.46, 153
    { 535, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x9085ba} }, // E OSM: 16603044 WD: Q2903493 48.53, 7.733 x 48.61, 7.786
    { 329, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x97bf0d} }, // F OSM: 16603070 WD: Q2724954 48.58, 7.716 x 48.59, 7.777
    { 227, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x80dfff} }, // 27 OSM: 16616831 WD: Q2106734 52.36, 4.786 x 52.36, 4.852
    { 1363, 37558, 33349, LineMetaDataContent::Tramway, Color{0xdce3e9} }, // T4 OSM: 16625348 WD: Q123249317 38.7, 35.49 x 38.73, 35.57
    { 26, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 16 OSM: 16626601 WD: Q123905215 49.51, 8.525 x 49.52, 8.535
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 2 OSM: 16636892 WD: Q123336434 41.75, 140.7 x 41.79, 140.8
    { 582, NoLogo, 30755, LineMetaDataContent::RapidTransit, Color{0x009158} }, // 23R OSM: 16653794 WD: Q23091313 53.46, -113.5 x 53.55, -113.4
    { 6097, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xc23b33} }, // SALIS OSM: 16672157 -34.92, 138.6 x -34.76, 138.6
    { 6103, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfe5000} }, // NOAR OSM: 16672579 -35.14, 138.5 x -34.92, 138.6
    { 3827, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x007dc3} }, // OSBORN OSM: 16672584 -34.92, 138.5 x -34.79, 138.6
    { 6108, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x007cba} }, // FESTVL OSM: 16672585 WD: Q115096643 -34.98, 138.5 x -34.92, 138.6
    { 6115, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x007dc3} }, // GLAN OSM: 16672586 -34.92, 138.5 x -34.84, 138.6
    { 6120, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xc23b33} }, // GAW OSM: 16672587 -34.92, 138.6 x -34.6, 138.7
    { 649, 23598, NoLogo, LineMetaDataContent::RapidTransit, Color{0x009ad5} }, // C-1 OSM: 16748029 WD: Q5987188 37.97, -1.131 x 38.35, -0.4964
    { 2161, 15219, NoLogo, LineMetaDataContent::RapidTransit, Color{0xbb29bb} }, // C-3 OSM: 16750145 WD: Q5987209 38.35, -0.5322 x 38.4, -0.4964
    { 2155, 37599, 3675, LineMetaDataContent::LocalTrain, Color{0x9f9825} }, // V OSM: 16792587 WD: Q123097765 48.72, 2.134 x 48.8, 2.259
    { 6124, 37633, NoLogo, LineMetaDataContent::LocalTrain, Color{0xc3403f} }, // ER-02 OSM: 16794669 WD: Q107613007 39.44, -0.3834 x 40.48, 0.4628
    { 6130, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffa500} }, // 2-ая Сормовская линия OSM: 16801501 56.34, 43.83 x 56.37, 43.88
    { 6169, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // 1-ая Сормовская линия OSM: 16801504 56.3, 43.83 x 56.37, 43.94
    { 6208, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // Приокская линия OSM: 16801507 56.15, 43.79 x 56.32, 44.09
    { 138, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x771e1b} }, // 9 OSM: 16807055 WD: Q120442703 40.85, 14.27 x 40.97, 14.62
    { 55, 37648, 1925, LineMetaDataContent::Tramway, Color{} }, // 11 OSM: 16807373 WD: Q123741718 49.43, 11.06 x 49.46, 11.14
    { 67, 37666, 1925, LineMetaDataContent::Tramway, Color{} }, // 10 OSM: 16807577 WD: Q123741708 49.44, 11.05 x 49.49, 11.12
    { 2368, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xef8016} }, // R15 OSM: 16832732 59.12, 24.29 x 59.44, 24.74
    { 60, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xee2737} }, // 3 OSM: 16843978 WD: Q123825602 26.38, 106.7 x 26.66, 106.8
    { 15, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x1a60a5} }, // 12 OSM: 16848925 WD: Q97276033 34.7, 113.7 x 34.8, 113.8
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0069b4} }, // 13 OSM: 16856381 WD: Q63348707 52.32, 9.717 x 52.43, 9.802
    { 511, 37684, 20845, LineMetaDataContent::Subway, Color{0xffc300} }, // L2 OSM: 16861886 WD: Q2894390 -12.06, -76.97 x -12.04, -76.94
    { 153, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x5ac1a7} }, // 19 OSM: 16890961 WD: Q61883430 30.48, 114.4 x 30.61, 114.5
    { 6238, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x000000} }, // REX1 OSM: 16908294 47.15, 9.601 x 47.55, 9.817
    { 672, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x000000} }, // R1 OSM: 16908313 47.15, 9.601 x 47.51, 9.817
    { 2258, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x000000} }, // R2 OSM: 16908348 47.16, 9.478 x 47.26, 9.617
    { 55, NoLogo, 28116, LineMetaDataContent::Subway, Color{0x004998} }, // 11 OSM: 16914085 WD: Q10940013 39.06, 117.3 x 39.08, 117.4
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0072c8} }, // 2 OSM: 16918817 32, 120.8 x 32.08, 121
    { 1295, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x1199dd} }, // T3 OSM: 16919186 WD: Q124157448 51, 3.709 x 51.05, 3.751
    { 6243, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8cd5de} }, // T41 OSM: 16949588 WD: Q121818770 50.25, 18.97 x 50.29, 19.02
    { 6247, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xdf1278} }, // T30 OSM: 16998183 WD: Q121832402 50.33, 18.84 x 50.4, 18.92
    { 63, NoLogo, 4285, LineMetaDataContent::RapidTransit, Color{0xf27e00} }, // S1 OSM: 16998465 WD: Q107983587 50.03, 14.43 x 50.11, 15.21
    { 631, NoLogo, 4285, LineMetaDataContent::RapidTransit, Color{0x0c823b} }, // S9 OSM: 16998476 WD: Q107981273 49.78, 14.43 x 50.08, 14.73
    { 1285, NoLogo, 4285, LineMetaDataContent::RapidTransit, Color{0x004c8a} }, // S20 OSM: 16998486 WD: Q107981848 49.67, 15.21 x 50.03, 15.48
    { 6251, 11763, 226, LineMetaDataContent::RapidTransit, Color{0xf5821f} }, // REX3 OSM: 17003122 WD: Q116212120 46.6, 14.31 x 46.84, 14.86
    { 6256, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x094b8d} }, // BEG OSM: 17011815 WD: Q52468593 -37.91, 144.9 x -37.81, 145.4
    { 1295, NoLogo, 34372, LineMetaDataContent::Tramway, Color{0xff0000} }, // T3 OSM: 17087733 WD: Q117209865 38.49, 27.03 x 38.51, 27.06
    { 6260, 37712, NoLogo, LineMetaDataContent::LocalTrain, Color{} }, // RB 40 OSM: 17097027 WD: Q62594138 50.03, 10.13 x 50.58, 10.45
    { 63, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xee2737} }, // S1 OSM: 17126909 WD: Q85884965 31.68, 120.3 x 31.93, 120.3
    { 56, NoLogo, 37736, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 17151480 WD: Q61132107 10.77, 106.7 x 10.88, 106.8
    { 56, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0000ff} }, // 1 OSM: 17168709 24.54, 46.61 x 24.84, 46.78
    { 371, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // Red OSM: 17169524 WD: Q124472663 24.71, 46.62 x 24.8, 46.84
    { 6266, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x71771d} }, // RL3 OSM: 17169920 41.61, 0.6331 x 41.68, 1.276
    { 667, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x27404e} }, // 55 OSM: 17234032 WD: Q125858857 43.5, 16.11 x 43.68, 16.49
    { 56, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x050505} }, // 1 OSM: 17248700 52.26, 104.3 x 52.29, 104.3
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xec008c} }, // 2 OSM: 17248967 52.48, -2.12 x 52.55, -2.024
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x050505} }, // 2 OSM: 17262470 52.27, 104.3 x 52.29, 104.3
    { 60, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x050505} }, // 3 OSM: 17262471 52.26, 104.3 x 52.29, 104.3
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x050505} }, // 4 OSM: 17262669 52.28, 104.3 x 52.29, 104.4
    { 6270, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x050505} }, // 4а OSM: 17262670 52.28, 104.3 x 52.29, 104.4
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x050505} }, // 5 OSM: 17262736 52.26, 104.3 x 52.29, 104.4
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x050505} }, // 6 OSM: 17262737 52.26, 104.3 x 52.29, 104.4
    { 110, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0c7cac} }, // 22 OSM: 17271943 WD: Q122307239 51.08, 16.95 x 51.14, 17.06
    { 2157, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x812990} }, // S44 OSM: 17295945 47.56, 9.103 x 47.66, 9.192
    { 27, 26935, 26958, LineMetaDataContent::Subway, Color{0xf47421} }, // 6 OSM: 17320239 WD: Q28050323 22.47, 88.39 x 22.52, 88.4
    { 6260, 37756, NoLogo, LineMetaDataContent::LocalTrain, Color{} }, // RB 40 OSM: 17329127 WD: Q113237935 48.12, 11.53 x 48.28, 12.52
    { 6274, 37773, NoLogo, LineMetaDataContent::LocalTrain, Color{0xbf73bf} }, // RB 33 OSM: 17329553 WD: Q113257915 48.14, 11.48 x 48.55, 12.14
    { 56, NoLogo, 37790, LineMetaDataContent::Subway, Color{0xffd700} }, // 1 OSM: 17332151 WD: Q120727502 27.16, 78.02 x 27.18, 78.06
    { 227, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x7b2c1c} }, // 27 OSM: 17363700 WD: Q16655738 50, 14.4 x 50.11, 14.46
    { 433, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x489224} }, // M2 OSM: 17392107 WD: Q2094433 50.4, 4.271 x 50.42, 4.452
    { 27, 37800, NoLogo, LineMetaDataContent::Subway, Color{0xe88f99} }, // 6 OSM: 17399102 WD: Q17041527 43.77, 125.2 x 43.87, 125.4
    { 6, NoLogo, 12277, LineMetaDataContent::Subway, Color{0xf2da51} }, // 5 OSM: 17417178 WD: Q10906685 31.89, 118.8 x 31.96, 118.8
    { 2114, 37820, NoLogo, LineMetaDataContent::LocalTrain, Color{0x94288e} }, // 34 OSM: 17463221 WD: Q9025916 41.09, -0.9102 x 41.66, 2.194
    { 217, NoLogo, 4285, LineMetaDataContent::RapidTransit, Color{0xf27e00} }, // S3 OSM: 17510471 WD: Q107983587 50.09, 14.43 x 50.42, 14.92
    { 51, NoLogo, 4285, LineMetaDataContent::RapidTransit, Color{0xf27e00} }, // S2 OSM: 17510472 WD: Q107983587 50.03, 14.43 x 50.2, 15.21
    { 27, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x6cace4} }, // 6 OSM: 17518162 WD: Q15951864 35.89, 120.1 x 36.07, 120.2
    { 6280, NoLogo, 4285, LineMetaDataContent::RapidTransit, Color{0x221e44} }, // S49 OSM: 17518306 WD: Q124209102 50.06, 14.39 x 50.16, 14.54
    { 1584, NoLogo, 4285, LineMetaDataContent::RapidTransit, Color{0x004c8a} }, // S18 OSM: 17618880 WD: Q107981848 49.84, 14.91 x 50.03, 15.22
    { 42, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xaf9778} }, // 7 OSM: 17625150 WD: Q122382723 49.77, 18.16 x 49.83, 18.25
    { 2109, NoLogo, 13458, LineMetaDataContent::RapidTransit, Color{0xf8a01d} }, // S35 OSM: 17667387 WD: Q126280860 46.98, 7.193 x 47.08, 7.307
    { 1221, NoLogo, 13458, LineMetaDataContent::RapidTransit, Color{0x2eaad7} }, // S36 OSM: 17680047 WD: Q126364854 47.07, 7.305 x 47.14, 7.372
    { 6284, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00985f} }, // 1T OSM: 17684227 60.15, 24.92 x 60.22, 24.96
    { 1837, NoLogo, 13458, LineMetaDataContent::RapidTransit, Color{0xf8a01d} }, // S41 OSM: 17691416 WD: Q126435512 46.76, 7.533 x 47.2, 7.659
    { 6287, NoLogo, 13458, LineMetaDataContent::RapidTransit, Color{0xe93f3c} }, // S37 OSM: 17692752 WD: Q126462529 47, 7.1 x 47.13, 7.246
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x2ea9df} }, // 4 OSM: 17703074 WD: Q60489245 41.65, 123.4 x 41.72, 123.5
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x5b3256} }, // 5 OSM: 17703079 WD: Q28415059 41.74, 123.5 x 41.83, 123.7
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf9906f} }, // 6 OSM: 17703082 WD: Q60489247 41.63, 123.4 x 41.67, 123.5
    { 335, NoLogo, 13458, LineMetaDataContent::RapidTransit, Color{0xb2ab15} }, // S45 OSM: 17719346 WD: Q126599145 47, 7.706 x 47.03, 7.737
    { 1695, NoLogo, 13458, LineMetaDataContent::RapidTransit, Color{0xf05c5b} }, // S42 OSM: 17721914 WD: Q126682726 46.76, 7.602 x 47.02, 7.659
    { 2589, NoLogo, 13458, LineMetaDataContent::RapidTransit, Color{0xaabdc7} }, // S43 OSM: 17721916 WD: Q126684691 46.76, 7.602 x 46.88, 7.629
};

static constexpr const auto line_data_count = sizeof(line_data) / sizeof(LineMetaDataContent);

static inline constexpr uint16_t Bucket(uint16_t index) { return line_data_count + index; }

static const int16_t line_data_bucketTable[] = {
    3824, 1728, 1744, 1745, 1746, 1727, -1,
    3613, 2158, -1,
    469, 473, 2955, 524, 523, 501, 2957, -1,
    1534, 3205, 3204, -1,
    1436, 2146, 2995, 3309, 3310, 3311, -1,
    1566, 3591, 3335, 1489, 1567, 1575, -1,
    1106, 2514, 322, -1,
    2979, 1822, 2981, 2982, 2983, -1,
    1170, 1171, 1166, 428, 1167, 1172, 1173, 1165, 1168, 1169, -1,
    536, 535, 1546, -1,
    521, 2792, 460, -1,
    1348, 243, -1,
    2012, 2974, 1453, 2976, 2978, -1,
    2217, 2219, 1029, -1,
    282, 2860, 2859, 285, -1,
    3212, 3211, -1,
    3203, 1535, 3207, 3206, 1742, 1720, -1,
    1797, 1796, -1,
    2034, 2045, 3554, -1,
    637, 1984, 1873, 326, 1982, 1983, -1,
    2127, 2128, 2156, 2162, 2961, 2962, 2950, -1,
    836, 840, 841, -1,
    3515, 3535, -1,
    3443, 3273, -1,
    1636, 1747, 1866, 1438, -1,
    1747, 1866, -1,
    1880, 1269, 984, 1253, 3643, 2166, 987, 944, 943, 1886, 429, 3573, 985, -1,
    3682, 3674, 1767, 1586, 1583, 1582, -1,
    2355, 1572, 1485, 1472, 1488, -1,
    442, 3100, 2730, 446, 3674, 2547, -1,
    323, 2520, -1,
    2771, 3779, 2768, -1,
    3677, 2771, 3779, 2768, 2769, -1,
    3539, 3519, -1,
    3352, 2941, 3353, -1,
    3175, 2231, 2019, 2232, 2270, 2234, 2532, -1,
    2852, 2363, 2361, 2892, 3190, 2646, 3189, 3215, 3078, 2362, -1,
    1113, 3274, 2700, 1112, -1,
    1114, 1113, 3274, 2700, 1112, 2678, 1105, -1,
    2011, 2824, 2823, 2980, -1,
    3639, 1783, 1069, -1,
    3116, 662, -1,
    1174, 685, -1,
    261, 3016, 3027, -1,
    296, 526, 2308, 2933, 1014, 2294, 2873, 2796, 527, 2295, -1,
    1129, 1123, 1220, 1127, 812, -1,
    1433, 2836, 2837, 1800, 1799, 2838, -1,
    1450, 2972, 2964, -1,
    3749, 1948, 1949, 1945, 1548, 297, 1947, -1,
    3135, 3134, -1,
    3201, 1548, -1,
    1922, 2478, 1914, -1,
    1965, 2204, -1,
    3169, 2997, 1713, 2205, 1704, 1714, 1716, 1688, 1689, 1686, 1687, 1717, 1616, 1685, 891, -1,
    1892, 1578, 3724, 1322, -1,
    2900, 2890, 2891, -1,
    3708, 1794, 3578, 1803, 2814, -1,
    863, 242, 2522, 1985, 305, -1,
    1958, 1967, 3574, 1968, -1,
    994, 487, 995, 1430, 757, 1011, -1,
    2138, 2149, 2150, 2139, 3488, 3611, 3610, 3063, 3062, 3061, 2663, 3060, -1,
    1691, 602, 115, 119, 904, 333, 908, 909, 1437, -1,
    1958, 1967, 3574, -1,
    1577, 1691, 602, 768, 498, 119, 2926, 906, 907, 908, 909, 1437, 910, 911, 912, 916, 955, 917, 918, -1,
    837, 838, 839, 842, -1,
    2497, 2496, 1645, 935, -1,
    2846, 2214, -1,
    2846, 3597, 3629, 3627, -1,
    3532, 2530, 995, 1430, -1,
    2342, 2127, 2129, 2138, 2130, 2128, 2149, 2150, 2156, 2139, 3363, 2147, 587, 2163, 2483, 2439, -1,
    2342, 3500, -1,
    2163, 583, 2467, 1118, 1119, 25, 1852, -1,
    705, 706, 893, -1,
    549, 3500, -1,
    3799, 3641, 259, 815, -1,
    3263, 3196, 3199, -1,
    3796, 1907, 1906, -1,
    549, 3818, 3817, 3231, 3272, 1260, 2572, -1,
    983, 1262, -1,
    1070, 2402, 2398, 2397, 787, 2401, 2404, 3648, 3649, 3826, 387, 1605, 389, -1,
    256, 451, 1258, 1257, 1881, 1882, -1,
    1899, 1175, 1080, 983, 1262, 982, 2165, -1,
    990, 992, 991, -1,
    1056, 36, 1301, 988, 986, 1899, 14, -1,
    3796, 2709, 3054, 3095, 2719, -1,
    1059, 1060, 2719, -1,
    3793, 3826, 3795, 387, 3825, -1,
    1059, 1060, 382, 1581, -1,
    1563, 3336, 1571, 1576, 1574, 1573, 1565, 1494, 3507, 3337, 2639, -1,
    1369, 3233, 892, -1,
    2691, 2690, -1,
    2143, 3653, 3652, -1,
    2191, 2182, -1,
    2448, 2408, 2407, 2336, 2338, 2337, -1,
    2041, 2711, -1,
    1836, 2903, 420, 2570, 2902, -1,
    3179, 3176, 3633, 3632, -1,
    2888, 3726, -1,
    3710, 680, 678, 1017, 1018, 3711, -1,
    2594, 3754, -1,
    2257, 2387, 3180, -1,
    3186, 3750, -1,
    3331, 3780, -1,
    1838, 2807, -1,
    2715, 3098, -1,
    2717, 2783, -1,
    2186, 2187, -1,
    2870, 2456, -1,
    386, 2194, -1,
    1503, 1063, 2466, 3439, 511, 510, 397, 398, 512, -1,
    2250, 3744, -1,
    2079, 2609, 2654, 3165, 3306, 2854, 2350, -1,
    2643, 2756, 2793, 2739, -1,
    3720, 3646, 3719, 3472, -1,
    2985, 2430, 2281, 1821, -1,
    3002, 856, 853, 3004, 851, 3006, 3007, 852, 3003, 855, 3005, 854, -1,
    2985, 2430, -1,
    2821, 2825, 2826, 2827, 2828, 2829, 2830, -1,
    207, 341, 1633, 2463, -1,
    2773, 2772, -1,
    2285, 2292, 2283, 2284, 2286, 2287, 2289, -1,
    2996, 3511, -1,
    1780, 1782, 1781, -1,
    1441, 1440, -1,
    2014, 2013, 2010, -1,
    3014, 3017, 3018, 3015, 3013, 3012, -1,
    2927, 2265, 2267, -1,
    3018, 3013, 3012, -1,
    2727, 2729, 2731, 2737, 371, 366, 2765, 2764, 3096, 370, 2787, 2789, 2790, 2782, 2568, 2953, 2779, 2567, 2761, 301, 2956, 2954, 372, 2958, 2175, -1,
    2727, 2731, 2737, 370, 2789, 2956, -1,
    1216, 1214, 3702, 2599, 2604, 2601, -1,
    1180, 245, 244, -1,
    3032, 3033, -1,
    3024, 3022, 3026, 3020, 3023, 3025, -1,
    1973, 1974, -1,
    3122, 2132, -1,
    3121, 3122, -1,
    1768, 1316, 2671, 2676, -1,
    2218, 2577, 1607, 2574, 2169, 2171, 2179, 2176, 2180, 2174, -1,
    1651, 2861, -1,
    1651, 2801, -1,
    2997, 3804, -1,
    335, 336, -1,
    271, 2735, 2006, 2736, 2121, 1927, 2035, 2030, 2033, 241, 3164, 1811, 2123, 1793, -1,
    1978, 1977, 1976, 1243, 1164, 1242, 1980, 1248, 1249, 1979, 1245, 1986, 1928, 971, 3502, 598, 1874, -1,
    1957, 3569, 1951, 1952, 1946, 1953, 1962, 1963, 1964, 1955, -1,
    1328, 1330, -1,
    858, 857, -1,
    2939, 3318, 2167, -1,
    2575, 2130, 2137, 2159, 2161, 2140, 3363, 2630, 2660, 2661, 3834, 2662, 2632, -1,
    1962, 1956, -1,
    1960, 960, -1,
    1939, 3243, 210, 211, -1,
    1957, 1951, 1579, 1952, 1946, -1,
    1471, 1480, 1481, 1484, 1483, -1,
    543, 915, 83, 84, 98, -1,
    913, 1054, 1725, 1055, 1052, -1,
    3304, 3305, 3261, -1,
    834, 828, 829, 1408, 832, 835, 843, -1,
    3691, 3261, -1,
    2617, 2621, 2620, 2619, -1,
    2312, 1845, -1,
    3492, 2321, -1,
    3697, 3614, 3461, 3621, 3622, 3057, 3055, 3056, 1075, 2525, 2556, 2833, 2554, 2526, 2527, 2528, 2529, 2555, -1,
    2159, 2161, 2140, 2160, 2148, 2157, 592, 2469, 2486, 3048, 2797, 2627, 2485, 3101, -1,
    3011, 2469, 1261, 2485, 3815, 1305, -1,
    2529, 2530, -1,
    1659, 1662, -1,
    3786, 3785, -1,
    3243, 210, 592, 2627, -1,
    19, 1750, 22, 16, 922, 1120, 1121, 150, 1850, 1851, -1,
    1310, 3037, 3815, -1,
    116, 117, 118, 1429, 1256, 126, 419, 46, 57, 30, 58, 59, 2616, 47, 48, 49, 50, 51, 52, 53, 54, -1,
    1272, 1273, 1274, 1275, -1,
    874, 1429, -1,
    3260, 815, -1,
    239, 238, 230, 3308, -1,
    1658, 1659, 1660, 1661, 1662, -1,
    3198, 3197, -1,
    361, 2492, 2491, 184, 1902, 363, 185, 797, 144, 1307, -1,
    238, 230, -1,
    3481, 3483, 3479, -1,
    3541, 3543, 3542, 1766, -1,
    3171, 388, 3520, -1,
    936, 967, 962, 1183, -1,
    1543, 622, 1646, 659, 1647, 649, 648, 180, -1,
    222, 3426, -1,
    152, 132, 159, -1,
    139, 110, 112, 171, 299, 300, 114, 170, 1133, 3571, 2454, -1,
    97, 27, 28, 1823, 1266, 3640, 405, 178, 179, 2633, 93, 1938, 2818, 187, 12, 15, 275, 340, 169, 166, 165, 140, 164, 163, 162, -1,
    97, 405, 178, 179, 15, 275, -1,
    2844, 138, 374, 385, 290, 1361, 255, -1,
    2714, 2720, -1,
    3042, 3450, -1,
    3681, 3604, 3680, -1,
    3585, 3579, 3590, -1,
    1569, 604, 603, 1468, -1,
    1568, 3664, 1564, -1,
    1562, 3570, -1,
    1569, 604, 1468, -1,
    3584, 3585, 1998, 3590, 1997, 3586, 3575, -1,
    1373, 1374, 1375, -1,
    1189, 1196, -1,
    3681, 3675, 3604, 3680, -1,
    1394, 1390, 1416, 1420, 1395, 1389, 1650, 1012, 1032, 343, 3686, 1840, 970, 1885, 3638, 3637, -1,
    1019, 1016, 1104, 1020, 969, -1,
    1667, 1506, 3602, 1508, 1509, -1,
    2097, 2098, 1861, 226, 2008, -1,
    684, 3654, -1,
    2924, 2923, 2922, -1,
    1343, 1344, 1342, -1,
    1989, 2028, -1,
    702, 1044, -1,
    3370, 3371, 2504, -1,
    3159, 3160, -1,
    2815, 2884, -1,
    2710, 2317, 2320, -1,
    3764, 3464, -1,
    3074, 3075, -1,
    2109, 2108, -1,
    2752, 2757, 2758, 2760, -1,
    550, 567, 516, 2406, 570, 947, 1820, 582, 548, 505, 574, 573, 651, 653, 571, 1237, 563, 566, -1,
    940, 3490, -1,
    3031, 2657, -1,
    2482, 2385, 2381, 2382, 2388, 2432, 2384, -1,
    2188, 2386, 2728, 3428, -1,
    2447, 2442, 2446, 3239, 2948, -1,
    866, 2452, 3659, 3182, 2451, 1076, 3485, 2450, -1,
    3376, 2702, 3434, 3587, 2706, 3362, -1,
    330, 328, 332, -1,
    2260, 2603, 2724, 3167, 2712, 2742, 332, -1,
    3445, 2716, 2708, -1,
    2442, 3239, 2948, -1,
    2799, 3347, -1,
    2209, 2908, 2210, 2799, 3342, 3347, -1,
    3341, 2216, -1,
    2470, 2945, 3338, -1,
    1108, 3449, -1,
    2629, 1427, 1426, 403, -1,
    3422, 3080, 3424, 3351, -1,
    3358, 3715, -1,
    2465, 2235, 2909, 3441, -1,
    2304, 2947, -1,
    1268, 1267, 1270, 2239, 3373, -1,
    1854, 1996, 1994, 1995, 2969, 3265, 1858, 2864, 302, 1860, 1991, 1864, 307, 1992, 1993, -1,
    391, 3381, 509, 1504, 1502, 2869, 508, 3131, 3317, -1,
    2507, 2501, -1,
    2307, 2246, -1,
    2536, 2261, 2834, -1,
    2536, 2544, -1,
    2305, 2225, 2224, 3822, -1,
    2536, 2524, -1,
    2437, 2438, -1,
    3086, 3084, -1,
    2698, 2365, -1,
    2477, 2910, 2641, 1597, -1,
    3377, 2302, -1,
    288, 252, 303, 0, 63, 1, 250, 3797, 3494, -1,
    2798, 804, 2741, -1,
    2480, 3755, -1,
    2813, 2812, 2970, -1,
    1294, 2552, -1,
    2589, 2591, -1,
    1758, 1545, -1,
    2820, 2819, 3076, 2831, -1,
    1632, 2856, 2855, -1,
    2775, 2774, -1,
    3293, 3291, 3292, -1,
    1051, 966, 1057, 979, -1,
    2003, 2004, 2005, -1,
    2268, 2269, 2266, 2009, -1,
    2845, 2264, -1,
    3041, 2934, 2309, -1,
    2780, 522, 365, 3099, 2762, 520, 1022, 368, 2296, 1023, 369, 2747, -1,
    522, 520, 1023, -1,
    3665, 2083, 2085, 1904, -1,
    246, 2017, -1,
    1320, 2809, 809, -1,
    1320, 1124, 2809, -1,
    2277, 2278, 3390, -1,
    1842, 2203, -1,
    2800, 2806, 2805, -1,
    2973, 2971, 2975, 2977, 3112, 2866, 2755, 2221, 2220, -1,
    3145, 3551, -1,
    3121, 3126, -1,
    1759, 3673, 1754, 1752, 2327, -1,
    298, 1950, -1,
    2851, 3210, -1,
    2136, 2135, -1,
    1523, 2206, 1617, -1,
    578, 576, 577, 1683, -1,
    3208, 3209, 3202, -1,
    3000, 2998, 2999, -1,
    1030, 1031, 1048, 3662, -1,
    799, 1380, -1,
    2029, 2046, 269, 268, -1,
    2429, 272, -1,
    3517, 1877, 3771, -1,
    1244, 1247, -1,
    2145, 2144, 3327, 3328, -1,
    1364, 3821, -1,
    1896, 1296, 1930, 2202, 2328, 1894, 2021, 2275, 1338, 1909, 1940, 2331, 2022, 1388, 1941, 1942, 1954, 1956, -1,
    2936, 2937, -1,
    1551, 394, -1,
    565, 488, -1,
    489, 3725, 565, 491, 488, -1,
    1387, 1405, 1176, 2965, 2659, 2668, 3831, 2667, 2664, 1376, -1,
    1387, 1176, 2659, 2668, 3840, 236, -1,
    2160, 2157, 2877, 2785, 589, 2878, 2763, -1,
    1942, 1943, 1955, -1,
    1897, 930, -1,
    2626, 3153, -1,
    3453, 3454, 2273, -1,
    771, 1580, -1,
    769, 770, 771, 772, 773, -1,
    1280, 1941, -1,
    1769, 1775, 2435, 3163, 1771, 1732, 1734, 1735, 1736, -1,
    1665, 1666, 2914, -1,
    1580, 1702, 1701, -1,
    499, 1487, 1493, -1,
    499, 2917, 493, 494, 496, -1,
    411, 3560, -1,
    2649, 2650, 2515, -1,
    3695, 3693, 3694, 3690, 3691, 3776, -1,
    3435, 831, -1,
    3695, 3690, 3776, -1,
    37, 39, -1,
    3221, 3222, -1,
    2069, 3628, 1975, -1,
    3620, 3626, 3599, 2066, 2069, 2405, 3557, 1975, 3262, -1,
    2226, 2322, -1,
    3531, 3534, 3529, -1,
    3130, 2553, -1,
    590, 2786, 3050, 3051, 236, -1,
    2788, 2785, 2784, 2786, 3019, 589, 2878, 2763, -1,
    2474, 3049, 3050, -1,
    1095, 1929, 1094, 713, 1098, 1096, 1097, 1090, 1092, 1100, 1093, 579, 1839, 2460, 593, 1072, 2726, 2455, 583, 575, 580, 2461, 591, 2440, 595, -1,
    3530, 3532, 3529, -1,
    3048, 2474, -1,
    1310, 592, 2726, 583, 2474, 2468, 575, 2467, 354, -1,
    3672, 3070, -1,
    1310, 3091, 3455, 3072, 3029, 3456, 3071, 3068, 3039, 3133, -1,
    1654, 1656, 1657, -1,
    3090, 3091, -1,
    3196, 3197, 1363, -1,
    1748, 1749, 24, 1740, 21, 561, 874, 552, -1,
    1005, 1337, 919, 920, 922, -1,
    1003, 3707, 1004, 1001, 1007, 1005, 1006, 3064, 1008, 3413, 1009, 1010, 1337, 919, 920, 922, 874, 552, -1,
    202, 1609, 1832, 1613, 1272, 1273, 921, 942, 406, -1,
    921, 942, 712, 406, -1,
    500, 919, 920, -1,
    1902, 796, 145, 144, -1,
    3778, 216, 739, 217, 231, 695, 646, 694, -1,
    1654, 1656, -1,
    174, 568, 796, 145, 1299, -1,
    2417, 2416, 1445, -1,
    1431, 1828, 1923, -1,
    3482, 3480, -1,
    647, 1073, 1879, 1102, 2393, 2392, 2390, 2400, 2395, 2394, 3820, 714, 715, 2473, 3552, 767, 775, 777, 2403, 3828, 3521, 3794, -1,
    647, 1073, 1879, 2393, 2392, 2390, 2400, 2394, 3820, 714, 2473, 3552, 767, 775, 777, 3825, 3828, -1,
    790, 792, 793, -1,
    1150, 3782, 2538, 2539, 1151, 1157, 1143, 1149, 1147, 1158, 1152, 959, 1061, 1449, -1,
    1411, 1412, 1413, -1,
    1648, 196, -1,
    130, 3398, -1,
    154, 155, 156, -1,
    75, 77, 72, -1,
    75, 76, 77, 72, -1,
    1555, 1764, 1766, 2475, -1,
    554, 558, 559, 560, 585, 553, 586, 3644, -1,
    7, 6, 95, 92, 32, 31, 94, 33, 3223, 8, 5, 188, 168, -1,
    1555, 2475, -1,
    64, 1585, 1584, 79, -1,
    66, 122, 64, 82, 137, 123, 81, 1988, 1585, 1584, 1233, 1218, 1336, 79, 80, -1,
    945, 721, -1,
    2471, 421, -1,
    415, 1712, 412, 2549, 2551, 416, 2353, 1570, 605, 1403, 1467, 1465, -1,
    1570, 1467, 1465, -1,
    1448, 3036, 3830, 2420, 2471, -1,
    864, 860, -1,
    1367, 1368, 1115, 1371, 1234, 1700, 1372, 860, 3791, 3716, 1110, 1314, -1,
    1178, 1177, -1,
    444, 443, -1,
    875, 876, 890, 879, 888, 3670, 889, 881, 885, 448, -1,
    1552, 1537, 1698, 2513, 2512, 1694, 2511, 1695, 2049, 1693, 1835, 1536, 1538, 3669, 2510, 2534, 1540, 1541, 2050, 1834, 2051, 2065, -1,
    2689, 2688, 2687, 2686, 2685, 2683, 2682, 2681, 3657, 2696, 2694, 2680, 2693, 3496, -1,
    2688, 2687, 2686, 2683, 2682, 2681, 3657, 2696, 2694, 2679, 2693, 3496, -1,
    682, 337, 3722, 683, 1499, 3721, 3723, -1,
    795, 1846, 1847, -1,
    1418, 1649, 1392, -1,
    1711, 1623, 1622, 1626, 1638, 1621, 1630, 1618, 1619, -1,
    1128, 1211, 1212, 1210, 1231, 1135, -1,
    902, 896, -1,
    2131, 3087, 3088, -1,
    3405, 3404, -1,
    1669, 1671, -1,
    956, 807, 808, 1841, -1,
    848, 849, 821, 823, 3264, 827, 847, 726, 846, 819, 845, 737, 822, 3577, 2126, 1142, 2125, 3188, -1,
    3513, 3733, 3731, -1,
    3104, 3105, 3106, -1,
    3258, 3740, 3252, 1990, 358, 355, -1,
    923, 744, 976, 692, 924, 734, 732, 1034, 724, 1088, 925, 926, 687, 725, 723, 733, 927, 738, 735, 746, 686, 1045, 3117, 747, 743, 3232, -1,
    2503, 2502, -1,
    1673, 1674, -1,
    2193, 3333, 3345, 3334, -1,
    3161, 3157, 3156, 3158, -1,
    2073, 2074, -1,
    3766, 3768, 3468, 3767, 1384, 3467, 3765, 3466, 3763, -1,
    2333, 2332, 2571, -1,
    3802, 2557, 2558, 3803, -1,
    2055, 2638, -1,
    2106, 477, 476, 480, -1,
    668, 669, -1,
    1201, 1204, 1203, 1259, 546, 3667, 1409, 545, 562, 3666, 1868, 581, 652, -1,
    2847, 1901, 3667, 1409, 572, 652, -1,
    3562, 564, -1,
    1444, 1065, 1903, 865, -1,
    2088, 1221, 1223, 1224, 517, 3506, -1,
    1026, 3709, 1027, 1028, -1,
    1145, 1935, 1931, 1936, 1871, 1970, 401, 1972, 395, 1250, -1,
    2648, 3546, -1,
    873, 2445, 2963, 3241, 3359, -1,
    1217, 1366, 1932, 1738, -1,
    327, 1802, 2778, -1,
    2324, 2702, -1,
    3168, 3553, 3592, 2713, 2064, 3369, -1,
    2223, 2222, 3097, 3699, -1,
    2459, 3784, 2675, 2674, 3444, 2707, 2314, -1,
    2907, 3676, -1,
    3700, 2208, -1,
    2215, 2197, 3386, -1,
    2215, 3781, 2197, 3387, 3386, 2912, -1,
    2952, 3187, -1,
    1640, 2230, -1,
    3419, 3420, -1,
    2938, 3491, -1,
    2464, 3356, 2911, 3355, -1,
    3340, 3349, -1,
    2303, 3423, 3298, -1,
    2906, 3343, -1,
    3823, 2258, -1,
    2673, 3605, 2672, -1,
    396, 392, 3440, 399, 1062, 1053, -1,
    3558, 2506, 2505, 2701, 2508, -1,
    3442, 2255, 3642, -1,
    2541, 2076, -1,
    2196, 2195, -1,
    1627, 1628, 1629, 3836, 3838, -1,
    1627, 3083, 1628, 1629, 3836, 3837, 2811, -1,
    2436, 2433, 2056, -1,
    534, 531, 532, -1,
    534, 532, -1,
    2374, 2373, 2376, -1,
    2349, 2356, 2610, 2607, 2850, 2360, 2600, 2584, 2359, -1,
    788, 1116, 362, 295, 125, 265, 458, 1109, 249, -1,
    11, 3151, -1,
    2733, 2767, -1,
    182, 181, 1292, 1293, 1295, 1756, -1,
    1865, 1867, 3178, -1,
    1722, 1723, -1,
    2280, 2290, 2288, 2291, -1,
    996, 973, -1,
    2271, 2272, -1,
    2236, 2238, 2803, 214, 2669, 3079, 2802, 2254, -1,
    3040, 3046, 3047, 3045, 2931, 2306, -1,
    2725, 2298, 2299, 3082, 1888, -1,
    2725, 2780, -1,
    2082, 3660, 2081, 2084, 2086, -1,
    601, 1138, -1,
    1321, 1311, -1,
    2212, 2211, 2213, 1474, -1,
    3120, 3123, -1,
    3536, 539, 1816, 3538, 3537, 2103, -1,
    1755, 1751, 1753, -1,
    1276, 2183, -1,
    1276, 2190, 2183, 2189, -1,
    356, 1905, 1303, -1,
    447, 1833, -1,
    356, 409, 1905, 1303, 1910, -1,
    281, 279, 280, 1653, 1652, 2861, -1,
    410, 1815, -1,
    1684, 2378, -1,
    1530, 2531, 1527, 1524, 1525, 1532, 1529, 1528, 1684, 2378, 1521, 1522, 1520, -1,
    1239, 3244, -1,
    1354, 1830, -1,
    2897, 2894, 2899, 2893, 2898, -1,
    2743, 2744, 2746, 2745, -1,
    2944, 2949, -1,
    1883, 1878, -1,
    1925, 2087, 2495, 1326, 1377, -1,
    1884, 1875, -1,
    703, 704, -1,
    3155, 3170, -1,
    2329, 1264, 1263, 850, 1911, -1,
    1335, 1333, 1327, 1329, 1331, 2875, -1,
    1359, 1358, 1356, 1357, -1,
    1455, 1457, 1456, -1,
    2565, 1400, 2578, 2580, 2581, 2582, 2563, 2625, 2564, 2566, 2573, 3172, 3154, -1,
    236, 237, -1,
    2585, 3153, -1,
    1400, 2582, 2563, 2564, 2566, 2573, 3154, -1,
    203, 205, -1,
    203, 205, 740, -1,
    763, 121, 1690, -1,
    1434, 2966, 3790, -1,
    2921, 1285, 1286, 3497, 1279, 1282, 1283, 1284, 1547, 1278, -1,
    1772, 1773, 1777, 1770, 2434, 1774, -1,
    101, 1378, 102, 378, 377, -1,
    1778, 1770, 2434, -1,
    1462, 1476, 1479, 1463, 1478, 3236, 1482, 1470, -1,
    90, 87, 1703, 91, 88, 89, 86, 1696, 761, 85, 762, 1697, -1,
    763, 121, 1690, 1692, -1,
    1591, 1421, 1428, 1447, 1592, 755, 1593, 1542, 1594, 1595, 1596, -1,
    1421, 755, 1542, 497, 2919, 495, -1,
    2918, 914, -1,
    2509, 3651, -1,
    3302, 3300, 3692, -1,
    2895, 3302, 3692, -1,
    2276, 2040, -1,
    3195, 3194, -1,
    45, 41, 100, 38, 3484, 43, 423, 99, 42, 44, 40, 2100, 2099, 3103, 3324, -1,
    3296, 3290, -1,
    2227, 2228, -1,
    590, 2786, -1,
    3568, 2786, -1,
    2474, 2468, -1,
    1310, 2474, 2468, 594, 2457, -1,
    2460, 3048, 2461, 2440, -1,
    3048, 2484, 2461, 2440, -1,
    3010, 3068, -1,
    3092, 1261, 3068, -1,
    1310, 594, -1,
    20, 818, 23, 3431, 1432, -1,
    500, 874, -1,
    719, 1608, 663, 1843, 1272, 1274, 1275, -1,
    1238, 3549, 3237, 3741, -1,
    999, 1000, 500, 3742, -1,
    1610, 1615, 1614, -1,
    708, 709, 430, 700, 1274, 1275, -1,
    707, 708, 709, 430, 700, 941, 1510, 468, 1511, 1304, 1514, 1515, 1516, -1,
    785, 786, -1,
    950, 353, 949, 197, 948, -1,
    232, 258, -1,
    212, 2586, 213, 2587, 359, -1,
    190, 191, 175, 194, 189, 192, 1349, 176, 248, 1306, 1300, 1246, 1298, 1308, 1309, -1,
    696, 697, 2579, 698, 699, 1924, -1,
    467, 465, 466, 1819, 464, 463, -1,
    1287, 1289, -1,
    697, 699, 1924, -1,
    3729, 3650, 3793, 3825, -1,
    3650, 3793, -1,
    1379, 1350, 2410, 2411, 2412, 1351, 2413, -1,
    61, 62, 441, 440, 437, 449, 450, -1,
    1154, 1159, 1439, -1,
    1078, 2857, 1501, 1107, 2843, 1101, -1,
    218, 225, 1241, 219, 220, 221, 223, 518, 1155, -1,
    148, 149, 147, -1,
    1553, 1560, 1064, 1561, 1554, 547, 1556, 1557, 1558, 1765, -1,
    4, 29, 35, 96, 2, 3, 899, 13, -1,
    1553, 1560, 1561, 1554, 1556, 1558, 1765, -1,
    658, 292, 294, 293, -1,
    776, 870, 780, 783, 2849, -1,
    776, 780, 2849, -1,
    3183, 1677, 1678, 1679, 1680, 798, 3184, 801, 810, 800, 811, 1675, 1672, 1676, -1,
    439, 438, 3042, -1,
    128, 67, 65, 113, -1,
    1049, 151, 766, 765, 3486, -1,
    310, 379, 380, 309, 1549, 1550, 381, 104, 3375, 308, 1598, -1,
    3396, 3395, 3393, 3391, 3397, -1,
    304, 813, -1,
    606, 2548, 425, 413, 9, 607, 620, 619, 2637, 611, 616, 621, 414, 1340, 254, 618, 614, 609, 615, 613, 513, 1404, 1402, 1779, -1,
    3247, 3248, 3245, 3246, -1,
    1641, 1642, 2583, 3636, 2117, 1643, 1644, -1,
    3414, 3406, -1,
    2422, 3730, 427, 2419, 3465, 1452, 3028, 3052, 3053, -1,
    3747, 3792, 1699, -1,
    1491, 1490, 1492, -1,
    2347, 2345, 2424, 2344, 2346, 2597, 2595, 2425, 2423, 2341, 2426, 2596, -1,
    1184, 3523, 1190, 1191, 1193, 1195, 1197, 1199, 1185, 1186, 3185, 1187, 1200, 431, 1188, 1194, -1,
    1191, 1193, 1200, 431, 1194, -1,
    877, 3728, 878, 880, 3814, 882, 883, 884, 887, -1,
    346, 350, -1,
    346, 1606, 347, 350, 348, 1498, 349, 352, 351, 1721, -1,
    1848, 1265, -1,
    1396, 1497, 1419, 1393, 1068, 1398, 1637, 1743, 1417, 1625, 1391, 1422, -1,
    1663, 3600, 1664, -1,
    141, 897, 900, 898, 142, 146, 143, 895, 901, -1,
    1324, 1323, -1,
    1790, 1787, 1788, 1789, 2519, -1,
    1790, 1791, 1787, 1788, 1789, 321, 2519, -1,
    1790, 1791, 1787, 1788, 1789, 3089, 321, 2519, 1117, -1,
    3735, 3736, 329, 3737, -1,
    3276, 3277, 3275, -1,
    844, 3299, 3372, 816, 968, -1,
    3400, 3401, -1,
    3514, 3732, -1,
    3109, 3107, -1,
    671, 681, 274, 273, -1,
    965, 963, -1,
    3119, 3150, 3147, 3148, 3149, 3118, 3124, 3128, 3141, 3125, 3129, 3127, 3142, 3140, 3144, -1,
    339, 338, -1,
    1341, 1347, -1,
    675, 676, 677, 3518, -1,
    868, 1089, -1,
    1033, 1036, 1039, -1,
    1035, 728, 1038, 1317, 729, 1040, 1021, 745, 1037, -1,
    3696, 2732, -1,
    2319, 2318, -1,
    690, 3469, -1,
    3768, 3468, -1,
    3617, 3618, -1,
    1917, 1916, 1915, 3704, 1919, 3705, -1,
    2170, 2119, 2054, -1,
    2152, 2153, -1,
    1792, 2750, 2749, 2753, 2754, 2759, -1,
    1792, 2750, 2749, -1,
    344, 481, 482, -1,
    1235, 1227, 1230, -1,
    506, 584, 1933, 507, 650, -1,
    679, 665, 2588, -1,
    977, 3774, 315, 3773, 316, 317, 311, 319, 312, 313, -1,
    977, 315, 316, 312, -1,
    1222, 1225, -1,
    627, 631, 635, 636, 629, 630, 1795, 626, 1826, 634, 638, 628, 641, 624, 640, 632, 1812, 645, 633, 623, 1825, 642, -1,
    631, 636, 629, 630, 1795, 626, 1812, 623, -1,
    1890, 1163, -1,
    1889, 1890, 1872, 1971, 1163, 1179, 1602, -1,
    3477, 3478, -1,
    3470, 3471, -1,
    2444, 3475, -1,
    3596, 3816, -1,
    556, 741, 514, 3378, -1,
    1362, 402, 2704, -1,
    2252, 3364, -1,
    331, 2777, -1,
    3368, 331, -1,
    3746, 3544, -1,
    1081, 1126, 1125, 1087, -1,
    3806, 3808, 3810, 3811, -1,
    2251, 3717, -1,
    1425, 3030, -1,
    2911, 3421, -1,
    2184, 3214, 3427, -1,
    2871, 3339, -1,
    2242, 2946, -1,
    2184, 2185, 3214, 3427, -1,
    2242, 2490, 2946, 2489, -1,
    2192, 2233, -1,
    3438, 2453, -1,
    3788, 3447, 3451, -1,
    2201, 1999, -1,
    2201, 1999, 2862, -1,
    2018, 2263, 2002, -1,
    2263, 2262, 2002, -1,
    974, 975, -1,
    861, 862, 1601, -1,
    2062, 2061, 2071, -1,
    2366, 2367, 2368, 2364, 2370, 2369, -1,
    736, 3192, 2372, -1,
    2608, 2611, -1,
    2351, 2358, 2352, 2348, 2357, 2593, -1,
    3761, 727, -1,
    1355, 691, 360, 457, 459, -1,
    470, 471, -1,
    2874, 2920, -1,
    2913, 3493, -1,
    2244, 2245, 3297, -1,
    462, 1634, 1496, -1,
    3286, 3285, -1,
    3285, 3284, -1,
    1443, 1442, -1,
    2670, 2642, 2766, -1,
    214, 215, -1,
    3043, 3110, 3044, 2930, 2929, 2932, 525, -1,
    2930, 2929, 525, -1,
    3110, 525, -1,
    1139, 247, -1,
    1140, 1139, -1,
    2300, 2901, -1,
    2535, 1824, 334, 2104, 2101, -1,
    2199, 2200, -1,
    2178, 2168, -1,
    2168, 2198, -1,
    287, 284, 3365, -1,
    278, 277, -1,
    1526, 1533, 1517, 1519, 1518, -1,
    263, 929, -1,
    2428, 2427, -1,
    2832, 2794, -1,
    2897, 2894, -1,
    2120, 2032, -1,
    2120, 2122, -1,
    408, 1318, 1319, -1,
    1981, 961, -1,
    2560, 2943, -1,
    490, 2635, -1,
    490, 492, 2635, -1,
    1893, 1895, -1,
    204, 206, -1,
    204, 206, 1762, -1,
    2274, 3756, 3757, -1,
    1156, 1737, 1706, 376, -1,
    1156, 1378, 1732, -1,
    1461, 1477, 1464, 1460, 1469, -1,
    541, 542, -1,
    120, 764, -1,
    997, 1726, 1024, 1715, -1,
    2518, 2517, 2516, -1,
    2500, 2602, -1,
    1708, 1710, -1,
    3289, 3218, -1,
    2237, 2253, -1,
    251, 407, -1,
    1856, 1853, 1857, 1855, -1,
    1856, 1857, 1855, -1,
    2068, 1144, -1,
    3624, 3631, 3474, 3635, 3609, -1,
    3634, 3635, 3609, 3658, -1,
    1084, 1085, -1,
    2484, 2467, -1,
    1839, 2460, -1,
    3037, 3091, 3039, -1,
    198, 201, -1,
    2618, 201, 56, 60, -1,
    198, 60, -1,
    998, 1002, -1,
    701, 711, 1512, 1513, -1,
    1273, 1512, 1514, -1,
    1254, 417, 1255, 418, 2967, -1,
    3777, 172, -1,
    173, 193, 789, -1,
    3270, 3268, -1,
    177, 233, -1,
    1161, 3323, 1353, 1352, -1,
    1071, 2391, 2396, 2399, 774, -1,
    1071, 2396, 2399, 774, -1,
    2653, 436, -1,
    1148, 1153, -1,
    951, 953, -1,
    17, 18, -1,
    1410, 1414, 1415, -1,
    519, 224, 1146, 3429, -1,
    133, 3418, 158, 134, 135, -1,
    111, 3512, -1,
    73, 989, -1,
    73, 71, 989, -1,
    1559, 1620, -1,
    200, 760, -1,
    781, 3382, 782, 784, -1,
    781, 3382, 782, -1,
    375, 2883, 3066, -1,
    435, 433, 434, -1,
    435, 433, -1,
    931, 932, -1,
    933, 931, 932, 934, -1,
    78, 160, -1,
    183, 106, 109, 108, 107, 103, 74, 127, -1,
    1407, 720, 946, -1,
    3580, 3583, -1,
    612, 3678, 3645, 617, 455, 393, 2656, -1,
    716, 717, 748, 718, 749, -1,
    717, 748, 718, 749, 3245, -1,
    3679, 872, 661, 660, 544, -1,
    3405, 3404, 3408, -1,
    612, 455, -1,
    1198, 1760, 871, -1,
    3382, 784, 783, -1,
    2748, 886, -1,
    3058, 3059, -1,
    1785, 1786, 320, 1791, -1,
    1785, 1786, -1,
    1077, 1446, -1,
    3734, 3412, -1,
    803, 958, 957, -1,
    722, 731, 730, -1,
    817, 820, -1,
    342, 357, -1,
    1505, 1668, 2867, -1,
    1505, 1668, 1507, 2867, -1,
    2007, 227, -1,
    657, 3588, -1,
    2634, 3683, 283, 814, -1,
    3683, 814, -1,
    964, 3751, 3752, -1,
    1345, 1346, -1,
    3833, 3254, 3255, 3257, -1,
    3249, 3833, 3250, 3251, 3253, 3254, 3255, 3256, 3257, -1,
    1042, 1495, 1041, -1,
    3181, 3177, 3759, -1,
    1920, 1918, -1,
    2142, 2141, -1,
    2988, 2989, -1,
    2152, 2153, 2154, -1,
    485, 486, -1,
    345, 485, 478, 486, 483, 484, -1,
    1232, 1226, 1228, 1229, 373, 3545, -1,
    1205, 1206, -1,
    654, 2024, -1,
    1202, 1207, 1829, -1,
    452, 314, 306, 318, -1,
    750, 666, 672, 754, 751, 3508, 753, -1,
    750, 666, 670, 672, 754, 751, 3508, 753, -1,
    644, 643, 639, 625, -1,
    644, 625, -1,
    627, 631, 636, 1826, 638, 645, 623, 644, 1825, 643, 625, -1,
    1937, 3703, 1863, -1,
    2091, 1937, 2164, 3703, 1160, 1240, -1,
    1804, 1805, 1806, 1808, 1730, 1807, 1731, -1,
    1804, 1805, 1806, 1808, 1730, 1807, 1731, 1818, 1817, 1809, 2791, 1810, -1,
    3528, 3527, -1,
    3809, 3812, 3813, -1,
    2113, 3138, -1,
    2018, 2076, -1,
    2047, 2107, -1,
    3330, 3329, -1,
    426, 253, 3595, 557, -1,
    3463, 3462, -1,
    742, 1729, 1291, 1290, -1,
    2881, 3294, -1,
    3287, 3288, -1,
    2479, 3280, -1,
    2803, 2802, -1,
    1137, 1141, -1,
    1831, 1900, 2636, -1,
    2993, 2994, -1,
    3770, 286, 284, -1,
    928, 1590, -1,
    1015, 2631, -1,
    825, 830, -1,
    3459, 3460, -1,
    3487, 3459, 3460, 3698, 3524, -1,
    1099, 1091, -1,
    3271, 3267, 3269, -1,
    456, 1424, -1,
    1559, 1064, -1,
    600, 234, 597, -1,
    600, 597, -1,
    432, 434, -1,
    105, 3350, -1,
    3394, 3392, -1,
    424, 2550, 422, -1,
    454, 424, 2550, 453, -1,
    3409, 3403, 3402, 3407, -1,
    2697, 2692, -1,
    3572, 3361, -1,
    321, 3235, -1,
    3411, 3410, -1,
    1505, 1668, -1,
    674, 675, -1,
    635, 629, 630, 628, -1,
    1806, 1808, 1807, -1,
    530, 529, 528, -1,
    1091, 2474, -1,
    70, 69, -1,
    672, 753, -1,
    631, 629, 630, 623, 644, -1,
    3282, 3281, -1,
    636, 1795, -1,
};

static const constexpr LineMetaDataQuadTreeDepthIndex line_data_depthOffsets[] = {
    { 27, 0 },
    { 26, 3 },
    { 25, 20 },
    { 24, 73 },
    { 23, 198 },
    { 22, 450 },
    { 21, 848 },
    { 20, 1295 },
    { 19, 1736 },
    { 18, 1961 },
    { 17, 2059 },
    { 16, 2131 },
};

static const constexpr LineMetaDataZIndex line_data_zquadtree[] = {
    { 227, Bucket(0) }, // 30.8, -5.517 x 44.22, 7.905
    { 230, 3357 }, // 44.22, -5.517 x 57.64, 7.905
    { 236, Bucket(7) }, // 44.22, 7.905 x 57.64, 21.33
    { 390, 2984 }, // 30.8, -119.6 x 37.51, -112.9
    { 397, 2540 }, // 37.51, -112.9 x 44.22, -106.2
    { 400, 2240 }, // 44.22, -126.3 x 50.93, -119.6
    { 431, Bucket(10) }, // 37.51, -79.34 x 44.22, -72.63
    { 773, 2955 }, // 37.51, -72.63 x 44.22, -65.91
    { 903, 1315 }, // 37.51, -12.23 x 44.22, -5.517
    { 909, 1934 }, // 37.51, -5.517 x 44.22, 1.194
    { 911, Bucket(18) }, // 37.51, 1.194 x 44.22, 7.905
    { 922, 1436 }, // 44.22, 1.194 x 50.93, 7.905
    { 923, 1966 }, // 50.93, 1.194 x 57.64, 7.905
    { 944, Bucket(22) }, // 44.22, 7.905 x 50.93, 14.62
    { 945, 993 }, // 50.93, 7.905 x 57.64, 14.62
    { 946, Bucket(29) }, // 44.22, 14.62 x 50.93, 21.33
    { 950, Bucket(36) }, // 57.64, 14.62 x 64.35, 21.33
    { 956, 2770 }, // 57.64, 21.33 x 64.35, 28.04
    { 2321, 3712 }, // 50.93, 34.75 x 57.64, 41.46
    { 2627, 3647 }, // -29.6, 148.8 x -22.89, 155.5
    { 1555, 2677 }, // 34.15, -123 x 37.51, -119.6
    { 1558, 2677 }, // 37.51, -123 x 40.86, -119.6
    { 1560, Bucket(40) }, // 30.8, -119.6 x 34.15, -116.2
    { 1561, 1822 }, // 34.15, -119.6 x 37.51, -116.2
    { 1695, Bucket(46) }, // 40.86, -89.4 x 44.22, -86.05
    { 1724, Bucket(57) }, // 37.51, -79.34 x 40.86, -75.98
    { 1726, Bucket(61) }, // 37.51, -75.98 x 40.86, -72.63
    { 1727, 474 }, // 40.86, -75.98 x 44.22, -72.63
    { 2313, 325 }, // -32.96, -65.91 x -29.6, -62.56
    { 2314, 243 }, // -36.31, -62.56 x -32.96, -59.2
    { 2336, Bucket(65) }, // -36.31, -59.2 x -32.96, -55.85
    { 3093, Bucket(68) }, // 40.86, -72.63 x 44.22, -69.27
    { 3636, Bucket(74) }, // 37.51, -5.517 x 40.86, -2.162
    { 3637, 1961 }, // 40.86, -5.517 x 44.22, -2.162
    { 3638, Bucket(78) }, // 37.51, -2.162 x 40.86, 1.194
    { 3639, 3416 }, // 40.86, -2.162 x 44.22, 1.194
    { 3644, Bucket(83) }, // 37.51, 1.194 x 40.86, 4.549
    { 3645, Bucket(86) }, // 40.86, 1.194 x 44.22, 4.549
    { 3685, Bucket(93) }, // 54.28, -5.517 x 57.64, -2.162
    { 3686, Bucket(96) }, // 50.93, -2.162 x 54.28, 1.194
    { 3689, Bucket(100) }, // 47.57, 1.194 x 50.93, 4.549
    { 3690, Bucket(107) }, // 44.22, 4.549 x 47.57, 7.905
    { 3692, 1251 }, // 50.93, 1.194 x 54.28, 4.549
    { 3735, Bucket(115) }, // 40.86, 11.26 x 44.22, 14.62
    { 3741, 3805 }, // 40.86, 14.62 x 44.22, 17.97
    { 3764, 2498 }, // 37.51, 21.33 x 40.86, 24.68
    { 3776, Bucket(119) }, // 44.22, 7.905 x 47.57, 11.26
    { 3778, 1908 }, // 44.22, 11.26 x 47.57, 14.62
    { 3779, Bucket(122) }, // 47.57, 11.26 x 50.93, 14.62
    { 3780, Bucket(125) }, // 50.93, 7.905 x 54.28, 11.26
    { 3781, Bucket(130) }, // 54.28, 7.905 x 57.64, 11.26
    { 3782, Bucket(133) }, // 50.93, 11.26 x 54.28, 14.62
    { 3783, 943 }, // 54.28, 11.26 x 57.64, 14.62
    { 3785, Bucket(147) }, // 47.57, 14.62 x 50.93, 17.97
    { 3786, Bucket(154) }, // 44.22, 17.97 x 47.57, 21.33
    { 3787, 3432 }, // 47.57, 17.97 x 50.93, 21.33
    { 3788, Bucket(160) }, // 50.93, 14.62 x 54.28, 17.97
    { 3790, 3684 }, // 50.93, 17.97 x 54.28, 21.33
    { 3800, Bucket(167) }, // 57.64, 14.62 x 60.99, 17.97
    { 3802, Bucket(167) }, // 57.64, 17.97 x 60.99, 21.33
    { 3824, Bucket(170) }, // 57.64, 21.33 x 60.99, 24.68
    { 3826, Bucket(174) }, // 57.64, 24.68 x 60.99, 28.04
    { 9180, 3073 }, // 10.66, 122 x 14.02, 125.3
    { 9265, 2115 }, // 34.15, 48.17 x 37.51, 51.53
    { 9285, 2887 }, // 54.28, 34.75 x 57.64, 38.1
    { 9771, 2705 }, // 20.73, 111.9 x 24.09, 115.3
    { 9863, Bucket(180) }, // 27.44, 118.6 x 30.8, 122
    { 9875, Bucket(183) }, // 34.15, 118.6 x 37.51, 122
    { 9883, Bucket(187) }, // 34.15, 125.3 x 37.51, 128.7
    { 9886, Bucket(187) }, // 37.51, 125.3 x 40.86, 128.7
    { 9913, 3227 }, // 34.15, 135.4 x 37.51, 138.8
    { 9915, Bucket(195) }, // 34.15, 138.8 x 37.51, 142.1
    { 10510, 3655 }, // -29.6, 152.2 x -26.25, 155.5
    { 3830, 2075 }, // -12.82, -77.66 x -11.15, -75.98
    { 6221, Bucket(206) }, // 35.83, -123 x 37.51, -121.3
    { 6232, Bucket(211) }, // 37.51, -123 x 39.18, -121.3
    { 6243, Bucket(219) }, // 32.47, -117.9 x 34.15, -116.2
    { 6337, 502 }, // 32.47, -112.9 x 34.15, -111.2
    { 6723, Bucket(224) }, // 32.47, -97.79 x 34.15, -96.11
    { 6770, Bucket(228) }, // 37.51, -91.08 x 39.18, -89.4
    { 6782, Bucket(231) }, // 40.86, -87.73 x 42.54, -86.05
    { 6879, Bucket(234) }, // 42.54, -81.01 x 44.22, -79.34
    { 6898, 2928 }, // 37.51, -77.66 x 39.18, -75.98
    { 6901, 261 }, // 42.54, -79.34 x 44.22, -77.66
    { 6905, Bucket(238) }, // 39.18, -75.98 x 40.86, -74.3
    { 6907, 1473 }, // 39.18, -74.3 x 40.86, -72.63
    { 6910, 2964 }, // 40.86, -74.3 x 42.54, -72.63
    { 6922, 905 }, // 44.22, -94.44 x 45.9, -92.76
    { 7082, 2615 }, // 44.22, -74.3 x 45.9, -72.63
    { 9219, 3499 }, // -34.64, -70.95 x -32.96, -69.27
    { 9268, 3379 }, // -26.25, -65.91 x -24.57, -64.24
    { 9407, Bucket(249) }, // -24.57, -47.46 x -22.89, -45.78
    { 9751, Bucket(255) }, // -24.57, -44.1 x -22.89, -42.43
    { 9794, Bucket(255) }, // -22.89, -44.1 x -21.21, -42.43
    { 11817, 3380 }, // -34.64, 17.97 x -32.96, 19.65
    { 11913, 2904 }, // -34.64, 24.68 x -32.96, 26.36
    { 12372, Bucket(262) }, // 40.86, -72.63 x 42.54, -70.95
    { 14463, Bucket(266) }, // 42.54, -7.195 x 44.22, -5.517
    { 14533, Bucket(274) }, // 35.83, -5.517 x 37.51, -3.839
    { 14535, 1827 }, // 35.83, -3.839 x 37.51, -2.162
    { 14549, Bucket(277) }, // 42.54, -5.517 x 44.22, -3.839
    { 14551, Bucket(280) }, // 42.54, -3.839 x 44.22, -2.162
    { 14552, 3769 }, // 37.51, -2.162 x 39.18, -0.4838
    { 14555, 3772 }, // 39.18, -0.4838 x 40.86, 1.194
    { 14558, Bucket(284) }, // 40.86, -0.4838 x 42.54, 1.194
    { 14580, Bucket(287) }, // 40.86, 1.194 x 42.54, 2.872
    { 14651, Bucket(303) }, // 52.61, -7.195 x 54.28, -5.517
    { 14729, 384 }, // 45.9, -2.162 x 47.57, -0.4838
    { 14739, Bucket(308) }, // 52.61, -3.839 x 54.28, -2.162
    { 14745, Bucket(309) }, // 52.61, -2.162 x 54.28, -0.4838
    { 14746, Bucket(312) }, // 50.93, -0.4838 x 52.61, 1.194
    { 14756, Bucket(318) }, // 47.57, 1.194 x 49.25, 2.872
    { 14759, Bucket(324) }, // 49.25, 2.872 x 50.93, 4.549
    { 14762, Bucket(329) }, // 44.22, 6.227 x 45.9, 7.905
    { 14763, Bucket(336) }, // 45.9, 6.227 x 47.57, 7.905
    { 14765, 1959 }, // 49.25, 4.549 x 50.93, 6.227
    { 14766, 333 }, // 47.57, 6.227 x 49.25, 7.905
    { 14767, Bucket(349) }, // 49.25, 6.227 x 50.93, 7.905
    { 14770, Bucket(359) }, // 50.93, 2.872 x 52.61, 4.549
    { 14778, Bucket(363) }, // 50.93, 6.227 x 52.61, 7.905
    { 14940, Bucket(383) }, // 40.86, 11.26 x 42.54, 12.94
    { 15031, 1103 }, // 29.12, 29.72 x 30.8, 31.39
    { 15058, Bucket(388) }, // 37.51, 23 x 39.18, 24.68
    { 15066, 2323 }, // 37.51, 26.36 x 39.18, 28.04
    { 15089, Bucket(393) }, // 39.18, 28.04 x 40.86, 29.72
    { 15092, Bucket(396) }, // 40.86, 28.04 x 42.54, 29.72
    { 15104, Bucket(401) }, // 44.22, 7.905 x 45.9, 9.583
    { 15105, Bucket(406) }, // 45.9, 7.905 x 47.57, 9.583
    { 15107, Bucket(423) }, // 45.9, 9.583 x 47.57, 11.26
    { 15108, Bucket(426) }, // 47.57, 7.905 x 49.25, 9.583
    { 15109, Bucket(434) }, // 49.25, 7.905 x 50.93, 9.583
    { 15110, Bucket(438) }, // 47.57, 9.583 x 49.25, 11.26
    { 15111, Bucket(441) }, // 49.25, 9.583 x 50.93, 11.26
    { 15113, Bucket(446) }, // 45.9, 11.26 x 47.57, 12.94
    { 15115, Bucket(450) }, // 45.9, 12.94 x 47.57, 14.62
    { 15116, Bucket(454) }, // 47.57, 11.26 x 49.25, 12.94
    { 15117, Bucket(462) }, // 49.25, 11.26 x 50.93, 12.94
    { 15119, Bucket(465) }, // 49.25, 12.94 x 50.93, 14.62
    { 15120, 937 }, // 50.93, 7.905 x 52.61, 9.583
    { 15121, Bucket(479) }, // 52.61, 7.905 x 54.28, 9.583
    { 15122, 937 }, // 50.93, 9.583 x 52.61, 11.26
    { 15123, 990 }, // 52.61, 9.583 x 54.28, 11.26
    { 15127, 3564 }, // 55.96, 9.583 x 57.64, 11.26
    { 15128, Bucket(486) }, // 50.93, 11.26 x 52.61, 12.94
    { 15129, Bucket(494) }, // 52.61, 11.26 x 54.28, 12.94
    { 15130, Bucket(498) }, // 50.93, 12.94 x 52.61, 14.62
    { 15132, 289 }, // 54.28, 11.26 x 55.96, 12.94
    { 15137, Bucket(506) }, // 45.9, 14.62 x 47.57, 16.29
    { 15139, 1576 }, // 45.9, 16.29 x 47.57, 17.97
    { 15140, Bucket(512) }, // 47.57, 14.62 x 49.25, 16.29
    { 15141, Bucket(516) }, // 49.25, 14.62 x 50.93, 16.29
    { 15142, Bucket(522) }, // 47.57, 16.29 x 49.25, 17.97
    { 15145, Bucket(527) }, // 45.9, 17.97 x 47.57, 19.65
    { 15148, 2639 }, // 47.57, 17.97 x 49.25, 19.65
    { 15149, Bucket(539) }, // 49.25, 17.97 x 50.93, 19.65
    { 15154, 3598 }, // 50.93, 16.29 x 52.61, 17.97
    { 15160, Bucket(543) }, // 50.93, 17.97 x 52.61, 19.65
    { 15171, 972 }, // 59.32, 9.583 x 60.99, 11.26
    { 15271, Bucket(546) }, // 49.25, 29.72 x 50.93, 31.39
    { 15299, 2027 }, // 59.32, 23 x 60.99, 24.68
    { 15302, 3200 }, // 60.99, 23 x 62.67, 24.68
    { 15305, 2027 }, // 59.32, 24.68 x 60.99, 26.36
    { 34771, Bucket(550) }, // 12.34, 76.69 x 14.02, 78.37
    { 34779, 2380 }, // 12.34, 80.05 x 14.02, 81.72
    { 36159, Bucket(553) }, // 2.275, 100.2 x 3.952, 101.9
    { 36246, Bucket(560) }, // 0.597, 103.5 x 2.275, 105.2
    { 36702, Bucket(563) }, // 14.02, 120.3 x 15.7, 122
    { 36922, 2559 }, // 24.09, 46.49 x 25.76, 48.17
    { 36944, Bucket(569) }, // 37.51, 34.75 x 39.18, 36.43
    { 37142, Bucket(574) }, // 54.28, 36.43 x 55.96, 38.1
    { 37175, 3775 }, // 55.96, 43.14 x 57.64, 44.81
    { 37276, Bucket(577) }, // 54.28, 51.53 x 55.96, 53.2
    { 37526, Bucket(584) }, // 27.44, 76.69 x 29.12, 78.37
    { 39056, Bucket(587) }, // 24.09, 101.9 x 25.76, 103.5
    { 39063, Bucket(591) }, // 29.12, 103.5 x 30.8, 105.2
    { 39065, Bucket(594) }, // 25.76, 105.2 x 27.44, 106.9
    { 39085, Bucket(597) }, // 22.41, 111.9 x 24.09, 113.6
    { 39100, Bucket(600) }, // 27.44, 111.9 x 29.12, 113.6
    { 39103, Bucket(603) }, // 29.12, 113.6 x 30.8, 115.3
    { 39162, Bucket(606) }, // 37.51, 113.6 x 39.18, 115.3
    { 39449, 3522 }, // 25.76, 118.6 x 27.44, 120.3
    { 39453, 3340 }, // 29.12, 118.6 x 30.8, 120.3
    { 39455, 3259 }, // 29.12, 120.3 x 30.8, 122
    { 39493, Bucket(609) }, // 35.83, 115.3 x 37.51, 117
    { 39495, 2456 }, // 35.83, 117 x 37.51, 118.6
    { 39496, 2666 }, // 30.8, 118.6 x 32.47, 120.3
    { 39498, Bucket(612) }, // 30.8, 120.3 x 32.47, 122
    { 39505, Bucket(615) }, // 39.18, 115.3 x 40.86, 117
    { 39514, 2310 }, // 37.51, 120.3 x 39.18, 122
    { 39540, Bucket(625) }, // 40.86, 122 x 42.54, 123.7
    { 39652, 2876 }, // 34.15, 135.4 x 35.83, 137.1
    { 39660, Bucket(628) }, // 34.15, 138.8 x 35.83, 140.4
    { 39661, 3216 }, // 35.83, 138.8 x 37.51, 140.4
    { 39679, 2339 }, // 42.54, 140.4 x 44.22, 142.1
    { 41819, 1705 }, // -41.35, 174 x -39.67, 175.7
    { 41823, 10 }, // -37.99, 174 x -36.31, 175.7
    { 42019, Bucket(636) }, // -34.64, 150.5 x -32.96, 152.2
    { 42041, Bucket(641) }, // -27.92, 152.2 x -26.25, 153.9
    { 12287, 1870 }, // -37.15, -73.46 x -36.31, -72.63
    { 16292, 555 }, // 5.63, -75.98 x 6.469, -75.14
    { 24928, 1111 }, // 37.51, -123 x 38.35, -122.1
    { 24967, Bucket(646) }, // 33.31, -118.8 x 34.15, -117.9
    { 24972, Bucket(651) }, // 32.47, -117.9 x 33.31, -117.1
    { 24978, Bucket(664) }, // 34.15, -118.8 x 34.99, -117.9
    { 25542, Bucket(667) }, // 39.18, -105.3 x 40.02, -104.5
    { 25633, Bucket(675) }, // 45.06, -123 x 45.9, -122.1
    { 25637, 2855 }, // 46.73, -123 x 47.57, -122.1
    { 25789, 2773 }, // 50.09, -114.6 x 50.93, -113.7
    { 25832, Bucket(680) }, // 50.93, -114.6 x 51.77, -113.7
    { 26628, Bucket(683) }, // 19.05, -99.47 x 19.89, -98.63
    { 26711, 2996 }, // 29.96, -98.63 x 30.8, -97.79
    { 26717, Bucket(691) }, // 29.96, -97.79 x 30.8, -96.95
    { 26892, 3001 }, // 32.47, -97.79 x 33.31, -96.95
    { 26894, Bucket(694) }, // 32.47, -96.95 x 33.31, -96.11
    { 27399, Bucket(698) }, // 33.31, -85.21 x 34.15, -84.37
    { 27405, Bucket(698) }, // 33.31, -84.37 x 34.15, -83.53
    { 27503, Bucket(701) }, // 40.02, -80.18 x 40.86, -79.34
    { 27519, Bucket(705) }, // 43.38, -80.18 x 44.22, -79.34
    { 27593, Bucket(712) }, // 38.35, -77.66 x 39.18, -76.82
    { 27605, Bucket(716) }, // 43.38, -79.34 x 44.22, -78.5
    { 27620, 2935 }, // 39.18, -75.98 x 40.02, -75.14
    { 27629, Bucket(720) }, // 40.02, -74.3 x 40.86, -73.46
    { 27640, Bucket(746) }, // 40.86, -74.3 x 41.7, -73.46
    { 27690, 2537 }, // 44.22, -93.6 x 45.06, -92.76
    { 28329, Bucket(753) }, // 45.06, -74.3 x 45.9, -73.46
    { 28331, 3702 }, // 45.06, -73.46 x 45.9, -72.63
    { 36877, 2718 }, // -33.8, -70.95 x -32.96, -70.11
    { 36901, 1271 }, // -33.8, -69.27 x -32.96, -68.43
    { 36912, 1271 }, // -32.96, -69.27 x -32.12, -68.43
    { 37049, 3389 }, // -32.12, -60.88 x -31.28, -60.04
    { 37182, 3525 }, // -17.86, -66.75 x -17.02, -65.91
    { 37377, 1297 }, // -35.47, -59.2 x -34.64, -58.37
    { 37380, Bucket(760) }, // -34.64, -59.2 x -33.8, -58.37
    { 37527, 1624 }, // -30.44, -51.65 x -29.6, -50.82
    { 40084, 2842 }, // -4.436, -39.07 x -3.597, -38.23
    { 40097, 1475 }, // -8.631, -35.72 x -7.792, -34.88
    { 40112, 2810 }, // -6.114, -35.72 x -5.275, -34.88
    { 47663, 2905 }, // -33.8, 27.2 x -32.96, 28.04
    { 47674, 2905 }, // -32.96, 27.2 x -32.12, 28.04
    { 47727, Bucket(764) }, // -27.09, 27.2 x -26.25, 28.04
    { 47738, 3033 }, // -26.25, 27.2 x -25.41, 28.04
    { 47775, Bucket(767) }, // -30.44, 30.55 x -29.6, 31.39
    { 47813, 3032 }, // -27.09, 28.04 x -26.25, 28.88
    { 49491, 1451 }, // 41.7, -71.79 x 42.54, -70.95
    { 57767, Bucket(774) }, // 33.31, -8.034 x 34.15, -7.195
    { 57773, 1611 }, // 33.31, -7.195 x 34.15, -6.356
    { 57791, Bucket(777) }, // 36.67, -6.356 x 37.51, -5.517
    { 57829, 3162 }, // 40.02, -8.872 x 40.86, -8.034
    { 57834, Bucket(780) }, // 37.51, -6.356 x 38.35, -5.517
    { 57840, Bucket(783) }, // 40.86, -8.872 x 41.7, -8.034
    { 57855, 1944 }, // 43.38, -6.356 x 44.22, -5.517
    { 58189, Bucket(788) }, // 40.02, -3.839 x 40.86, -3
    { 58210, 1219 }, // 37.51, -1.323 x 38.35, -0.4838
    { 58214, Bucket(799) }, // 39.18, -1.323 x 40.02, -0.4838
    { 58217, 3603 }, // 38.35, -0.4838 x 39.18, 0.3551
    { 58220, Bucket(802) }, // 39.18, -0.4838 x 40.02, 0.3551
    { 58226, 599 }, // 40.86, -1.323 x 41.7, -0.4838
    { 58227, 599 }, // 41.7, -1.323 x 42.54, -0.4838
    { 58234, Bucket(805) }, // 40.86, 0.3551 x 41.7, 1.194
    { 58310, 3213 }, // 39.18, 2.033 x 40.02, 2.872
    { 58316, 3213 }, // 39.18, 2.872 x 40.02, 3.711
    { 58618, Bucket(808) }, // 54.28, -6.356 x 55.12, -5.517
    { 58982, 270 }, // 52.61, -1.323 x 53.45, -0.4838
    { 58984, Bucket(811) }, // 50.93, -0.4838 x 51.77, 0.3551
    { 59027, Bucket(826) }, // 48.41, 2.033 x 49.25, 2.872
    { 59039, Bucket(844) }, // 50.09, 3.711 x 50.93, 4.549
    { 59041, Bucket(855) }, // 45.06, 4.549 x 45.9, 5.388
    { 59043, Bucket(858) }, // 45.06, 5.388 x 45.9, 6.227
    { 59046, 2939 }, // 45.9, 5.388 x 46.73, 6.227
    { 59051, 479 }, // 45.06, 7.066 x 45.9, 7.905
    { 59052, Bucket(861) }, // 45.9, 6.227 x 46.73, 7.066
    { 59053, 2167 }, // 46.73, 6.227 x 47.57, 7.066
    { 59055, Bucket(865) }, // 46.73, 7.066 x 47.57, 7.905
    { 59061, Bucket(879) }, // 50.09, 4.549 x 50.93, 5.388
    { 59063, Bucket(882) }, // 50.09, 5.388 x 50.93, 6.227
    { 59066, Bucket(885) }, // 47.57, 7.066 x 48.41, 7.905
    { 59070, 919 }, // 49.25, 7.066 x 50.09, 7.905
    { 59082, Bucket(890) }, // 50.93, 3.711 x 51.77, 4.549
    { 59083, 1733 }, // 51.77, 3.711 x 52.61, 4.549
    { 59105, Bucket(896) }, // 51.77, 4.549 x 52.61, 5.388
    { 59112, Bucket(902) }, // 50.93, 6.227 x 51.77, 7.066
    { 59114, Bucket(908) }, // 50.93, 7.066 x 51.77, 7.905
    { 59752, 3367 }, // 37.51, 12.94 x 38.35, 13.78
    { 59759, Bucket(914) }, // 40.02, 13.78 x 40.86, 14.62
    { 59763, Bucket(918) }, // 41.7, 12.1 x 42.54, 12.94
    { 59770, Bucket(926) }, // 40.86, 13.78 x 41.7, 14.62
    { 59864, 1182 }, // 40.86, 16.29 x 41.7, 17.13
    { 59893, Bucket(929) }, // 43.38, 17.97 x 44.22, 18.81
    { 60232, Bucket(934) }, // 37.51, 23 x 38.35, 23.84
    { 60331, 3713 }, // 31.63, 33.91 x 32.47, 34.75
    { 60370, 2067 }, // 40.86, 28.88 x 41.7, 29.72
    { 60390, Bucket(937) }, // 39.18, 32.23 x 40.02, 33.07
    { 60419, Bucket(940) }, // 45.06, 8.744 x 45.9, 9.583
    { 60420, 2162 }, // 45.9, 7.905 x 46.73, 8.744
    { 60421, Bucket(959) }, // 46.73, 7.905 x 47.57, 8.744
    { 60422, 3531 }, // 45.9, 8.744 x 46.73, 9.583
    { 60423, Bucket(974) }, // 46.73, 8.744 x 47.57, 9.583
    { 60425, Bucket(981) }, // 45.06, 9.583 x 45.9, 10.42
    { 60426, Bucket(984) }, // 44.22, 10.42 x 45.06, 11.26
    { 60429, Bucket(987) }, // 46.73, 9.583 x 47.57, 10.42
    { 60432, Bucket(990) }, // 47.57, 7.905 x 48.41, 8.744
    { 60433, Bucket(995) }, // 48.41, 7.905 x 49.25, 8.744
    { 60434, Bucket(1006) }, // 47.57, 8.744 x 48.41, 9.583
    { 60435, Bucket(1010) }, // 48.41, 8.744 x 49.25, 9.583
    { 60436, 980 }, // 49.25, 7.905 x 50.09, 8.744
    { 60437, Bucket(1032) }, // 50.09, 7.905 x 50.93, 8.744
    { 60438, Bucket(1037) }, // 49.25, 8.744 x 50.09, 9.583
    { 60442, 363 }, // 47.57, 10.42 x 48.41, 11.26
    { 60443, Bucket(1040) }, // 48.41, 10.42 x 49.25, 11.26
    { 60444, 257 }, // 49.25, 9.583 x 50.09, 10.42
    { 60446, Bucket(1043) }, // 49.25, 10.42 x 50.09, 11.26
    { 60447, 3312 }, // 50.09, 10.42 x 50.93, 11.26
    { 60448, Bucket(1048) }, // 44.22, 11.26 x 45.06, 12.1
    { 60453, Bucket(1054) }, // 46.73, 11.26 x 47.57, 12.1
    { 60464, Bucket(1057) }, // 47.57, 11.26 x 48.41, 12.1
    { 60465, 3260 }, // 48.41, 11.26 x 49.25, 12.1
    { 60467, 2472 }, // 48.41, 12.1 x 49.25, 12.94
    { 60468, Bucket(1068) }, // 49.25, 11.26 x 50.09, 12.1
    { 60474, Bucket(1071) }, // 47.57, 13.78 x 48.41, 14.62
    { 60476, 1288 }, // 49.25, 12.94 x 50.09, 13.78
    { 60477, Bucket(1075) }, // 50.09, 12.94 x 50.93, 13.78
    { 60478, Bucket(1080) }, // 49.25, 13.78 x 50.09, 14.62
    { 60483, 959 }, // 51.77, 8.744 x 52.61, 9.583
    { 60489, Bucket(1084) }, // 51.77, 9.583 x 52.61, 10.42
    { 60492, Bucket(1086) }, // 52.61, 9.583 x 53.45, 10.42
    { 60493, Bucket(1089) }, // 53.45, 9.583 x 54.28, 10.42
    { 60512, Bucket(1098) }, // 50.93, 11.26 x 51.77, 12.1
    { 60513, Bucket(1101) }, // 51.77, 11.26 x 52.61, 12.1
    { 60514, Bucket(1105) }, // 50.93, 12.1 x 51.77, 12.94
    { 60515, 2072 }, // 51.77, 12.1 x 52.61, 12.94
    { 60516, 159 }, // 52.61, 11.26 x 53.45, 12.1
    { 60521, Bucket(1117) }, // 51.77, 12.94 x 52.61, 13.78
    { 60522, 1764 }, // 50.93, 13.78 x 51.77, 14.62
    { 60524, Bucket(1143) }, // 52.61, 12.94 x 53.45, 13.78
    { 60526, 2042 }, // 52.61, 13.78 x 53.45, 14.62
    { 60531, Bucket(1150) }, // 55.12, 12.1 x 55.96, 12.94
    { 60547, 3727 }, // 45.06, 15.45 x 45.9, 16.29
    { 60549, Bucket(1158) }, // 46.73, 14.62 x 47.57, 15.45
    { 60550, 199 }, // 45.9, 15.45 x 46.73, 16.29
    { 60551, Bucket(1161) }, // 46.73, 15.45 x 47.57, 16.29
    { 60564, 3829 }, // 49.25, 14.62 x 50.09, 15.45
    { 60568, 1058 }, // 47.57, 16.29 x 48.41, 17.13
    { 60573, Bucket(1164) }, // 50.09, 16.29 x 50.93, 17.13
    { 60574, Bucket(1168) }, // 49.25, 17.13 x 50.09, 17.97
    { 60581, 1562 }, // 46.73, 17.97 x 47.57, 18.81
    { 60583, Bucket(1172) }, // 46.73, 18.81 x 47.57, 19.65
    { 60588, 3325 }, // 45.9, 19.65 x 46.73, 20.49
    { 60589, Bucket(1177) }, // 46.73, 19.65 x 47.57, 20.49
    { 60592, Bucket(1181) }, // 47.57, 17.97 x 48.41, 18.81
    { 60594, Bucket(1184) }, // 47.57, 18.81 x 48.41, 19.65
    { 60596, Bucket(1188) }, // 49.25, 17.97 x 50.09, 18.81
    { 60599, Bucket(1196) }, // 50.09, 18.81 x 50.93, 19.65
    { 60600, 1564 }, // 47.57, 19.65 x 48.41, 20.49
    { 60604, Bucket(1200) }, // 49.25, 19.65 x 50.09, 20.49
    { 60605, 1196 }, // 50.09, 19.65 x 50.93, 20.49
    { 60609, 1899 }, // 51.77, 14.62 x 52.61, 15.45
    { 60610, 3706 }, // 50.93, 15.45 x 51.77, 16.29
    { 60616, Bucket(1203) }, // 50.93, 16.29 x 51.77, 17.13
    { 60651, Bucket(1208) }, // 51.77, 20.49 x 52.61, 21.33
    { 60686, Bucket(1225) }, // 59.32, 10.42 x 60.16, 11.26
    { 60811, 324 }, // 58.48, 17.13 x 59.32, 17.97
    { 60933, 2354 }, // 46.73, 21.33 x 47.57, 22.17
    { 60975, Bucket(1231) }, // 46.73, 27.2 x 47.57, 28.04
    { 60994, 3685 }, // 50.93, 22.17 x 51.77, 23
    { 61039, Bucket(1237) }, // 53.45, 27.2 x 54.28, 28.04
    { 61085, Bucket(1243) }, // 50.09, 29.72 x 50.93, 30.55
    { 61112, Bucket(1246) }, // 47.57, 33.07 x 48.41, 33.91
    { 61123, 664 }, // 51.77, 28.88 x 52.61, 29.72
    { 61145, Bucket(1250) }, // 55.12, 29.72 x 55.96, 30.55
    { 61221, Bucket(1254) }, // 60.16, 24.68 x 60.99, 25.52
    { 61324, Bucket(1257) }, // 59.32, 29.72 x 60.16, 30.55
    { 136265, Bucket(1260) }, // -1.92, 36.43 x -1.081, 37.26
    { 139110, 504 }, // 12.34, 79.21 x 13.18, 80.05
    { 144855, Bucket(1264) }, // 16.54, 95.99 x 17.37, 96.82
    { 144877, Bucket(1267) }, // 13.18, 100.2 x 14.02, 101
    { 144984, Bucket(1270) }, // 0.597, 103.5 x 1.436, 104.4
    { 146059, Bucket(1274) }, // -35.47, 137.9 x -34.64, 138.8
    { 146887, Bucket(1277) }, // 13.18, 122.8 x 14.02, 123.7
    { 147713, 3713 }, // 31.63, 34.75 x 32.47, 35.59
    { 147743, 3555 }, // 36.67, 37.26 x 37.51, 38.1
    { 147794, 3606 }, // 40.86, 35.59 x 41.7, 36.43
    { 147800, 3606 }, // 40.86, 36.43 x 41.7, 37.26
    { 148043, 2658 }, // 24.92, 50.69 x 25.76, 51.53
    { 148065, 2658 }, // 24.92, 51.53 x 25.76, 52.36
    { 148161, Bucket(1280) }, // 24.92, 54.88 x 25.76, 55.72
    { 148251, 2114 }, // 34.99, 50.69 x 35.83, 51.53
    { 148406, 404 }, // 35.83, 59.08 x 36.67, 59.91
    { 148495, Bucket(1283) }, // 46.73, 37.26 x 47.57, 38.1
    { 148571, Bucket(1288) }, // 55.12, 37.26 x 55.96, 38.1
    { 149068, 2889 }, // 52.61, 49.85 x 53.45, 50.69
    { 149667, 3081 }, // 18.21, 72.5 x 19.05, 73.34
    { 149670, 3081 }, // 19.05, 72.5 x 19.89, 73.34
    { 149970, Bucket(1307) }, // 40.86, 69.14 x 41.7, 69.98
    { 150064, Bucket(1310) }, // 20.73, 78.37 x 21.57, 79.21
    { 150105, Bucket(1313) }, // 28.28, 76.69 x 29.12, 77.53
    { 150525, 2545 }, // 43.38, 86.76 x 44.22, 87.6
    { 150527, 2545 }, // 43.38, 87.6 x 44.22, 88.44
    { 156222, Bucket(1321) }, // 22.41, 107.7 x 23.25, 108.6
    { 156253, Bucket(1326) }, // 29.96, 103.5 x 30.8, 104.4
    { 156278, Bucket(1332) }, // 29.12, 106.1 x 29.96, 106.9
    { 156342, Bucket(1341) }, // 22.41, 112.8 x 23.25, 113.6
    { 156343, 2816 }, // 23.25, 112.8 x 24.09, 113.6
    { 156345, Bucket(1348) }, // 21.57, 113.6 x 22.41, 114.4
    { 156348, Bucket(1352) }, // 22.41, 113.6 x 23.25, 114.4
    { 156402, 3504 }, // 27.44, 112.8 x 28.28, 113.6
    { 156413, Bucket(1360) }, // 29.96, 113.6 x 30.8, 114.4
    { 156424, Bucket(1364) }, // 30.8, 103.5 x 31.63, 104.4
    { 156549, Bucket(1368) }, // 33.31, 108.6 x 34.15, 109.4
    { 156560, Bucket(1371) }, // 34.15, 108.6 x 34.99, 109.4
    { 156592, 3346 }, // 34.15, 111.9 x 34.99, 112.8
    { 156600, Bucket(1378) }, // 34.15, 113.6 x 34.99, 114.4
    { 157770, Bucket(1381) }, // 24.09, 117.8 x 24.92, 118.6
    { 157777, Bucket(1385) }, // 28.28, 115.3 x 29.12, 116.1
    { 157803, Bucket(1388) }, // 24.92, 121.2 x 25.76, 122
    { 157815, Bucket(1393) }, // 29.96, 119.5 x 30.8, 120.3
    { 157816, Bucket(1398) }, // 27.44, 120.3 x 28.28, 121.2
    { 157822, Bucket(1401) }, // 29.12, 121.2 x 29.96, 122
    { 157961, Bucket(1406) }, // 31.63, 117 x 32.47, 117.8
    { 157963, 1267 }, // 31.63, 117.8 x 32.47, 118.6
    { 157985, Bucket(1409) }, // 31.63, 118.6 x 32.47, 119.5
    { 157989, 3319 }, // 33.31, 118.6 x 34.15, 119.5
    { 157992, 3360 }, // 30.8, 120.3 x 31.63, 121.2
    { 157993, 3789 }, // 31.63, 120.3 x 32.47, 121.2
    { 157994, Bucket(1415) }, // 30.8, 121.2 x 31.63, 122
    { 158012, 2940 }, // 35.83, 120.3 x 36.67, 121.2
    { 158022, Bucket(1431) }, // 39.18, 116.1 x 40.02, 117
    { 158025, Bucket(1441) }, // 38.35, 117 x 39.18, 117.8
    { 158028, 2507 }, // 39.18, 117 x 40.02, 117.8
    { 158059, Bucket(1444) }, // 38.35, 121.2 x 39.18, 122
    { 158135, Bucket(1447) }, // 36.67, 126.2 x 37.51, 127
    { 158140, 2155 }, // 35.83, 127 x 36.67, 127.9
    { 158141, Bucket(1451) }, // 36.67, 127 x 37.51, 127.9
    { 158163, 2249 }, // 41.7, 122.8 x 42.54, 123.7
    { 158175, Bucket(1454) }, // 43.38, 124.5 x 44.22, 125.3
    { 158177, 2112 }, // 38.35, 125.3 x 39.18, 126.2
    { 158178, Bucket(1447) }, // 37.51, 126.2 x 38.35, 127
    { 158184, Bucket(1459) }, // 37.51, 127 x 38.35, 127.9
    { 158197, Bucket(1455) }, // 43.38, 125.3 x 44.22, 126.2
    { 158481, Bucket(1462) }, // 34.99, 128.7 x 35.83, 129.5
    { 158512, 533 }, // 34.15, 132.1 x 34.99, 132.9
    { 158520, Bucket(1465) }, // 34.15, 133.7 x 34.99, 134.6
    { 158608, Bucket(1468) }, // 34.15, 135.4 x 34.99, 136.3
    { 158643, Bucket(1471) }, // 34.99, 139.6 x 35.83, 140.4
    { 158646, 2477 }, // 35.83, 139.6 x 36.67, 140.4
    { 158696, 2078 }, // 37.51, 140.4 x 38.35, 141.3
    { 158718, 3225 }, // 42.54, 141.3 x 43.38, 142.1
    { 158883, Bucket(1476) }, // 45.06, 126.2 x 45.9, 127
    { 165214, Bucket(1479) }, // -37.99, 144.6 x -37.15, 145.5
    { 168076, Bucket(1489) }, // -34.64, 150.5 x -33.8, 151.4
    { 168164, Bucket(1493) }, // -27.92, 152.2 x -27.09, 153
    { 49148, 1869 }, // -37.15, -73.46 x -36.73, -73.05
    { 64751, 2058 }, // 8.566, -79.76 x 8.986, -79.34
    { 64762, 2058 }, // 8.986, -79.76 x 9.405, -79.34
    { 99549, Bucket(1496) }, // 37.09, -122.1 x 37.51, -121.7
    { 99714, Bucket(1500) }, // 37.51, -122.5 x 37.93, -122.1
    { 99721, 2431 }, // 37.93, -122.1 x 38.35, -121.7
    { 99726, Bucket(1503) }, // 38.35, -121.7 x 38.77, -121.3
    { 99748, 2591 }, // 38.35, -121.3 x 38.77, -120.9
    { 99891, 3303 }, // 32.89, -117.5 x 33.31, -117.1
    { 101661, Bucket(1506) }, // 40.44, -112.1 x 40.86, -111.6
    { 102169, Bucket(1509) }, // 39.6, -105.3 x 40.02, -104.9
    { 102511, 1724 }, // 48.83, -123.4 x 49.25, -123
    { 102522, 1724 }, // 49.25, -123.4 x 49.67, -123
    { 102533, 209 }, // 45.48, -123 x 45.9, -122.5
    { 102551, 1632 }, // 47.15, -122.5 x 47.57, -122.1
    { 102594, Bucket(1514) }, // 47.57, -122.5 x 47.99, -122.1
    { 103356, Bucket(1518) }, // 53.45, -113.7 x 53.86, -113.3
    { 106512, 1365 }, // 19.05, -99.47 x 19.47, -99.05
    { 106963, Bucket(1521) }, // 29.54, -95.69 x 29.96, -95.28
    { 108494, 1051 }, // 41.7, -88.14 x 42.12, -87.73
    { 108516, Bucket(1525) }, // 41.7, -87.73 x 42.12, -87.31
    { 108753, 1454 }, // 22.83, -82.69 x 23.25, -82.27
    { 109796, 2848 }, // 34.99, -81.01 x 35.41, -80.59
    { 110025, Bucket(1530) }, // 41.28, -81.85 x 41.7, -81.43
    { 110078, 3009 }, // 43.38, -79.76 x 43.8, -79.34
    { 110206, 1544 }, // 36.67, -76.4 x 37.09, -75.98
    { 110375, Bucket(1534) }, // 38.77, -77.24 x 39.18, -76.82
    { 110392, Bucket(1539) }, // 39.18, -76.82 x 39.6, -76.4
    { 110483, Bucket(1542) }, // 39.6, -75.56 x 40.02, -75.14
    { 110486, 2309 }, // 40.02, -75.56 x 40.44, -75.14
    { 110517, Bucket(1546) }, // 40.44, -74.3 x 40.86, -73.88
    { 110519, 2808 }, // 40.44, -73.88 x 40.86, -73.46
    { 110560, Bucket(1559) }, // 40.86, -74.3 x 41.28, -73.88
    { 112810, 3017 }, // 44.22, -79.76 x 44.64, -79.34
    { 113319, 2612 }, // 45.48, -73.88 x 45.9, -73.46
    { 136649, 1603 }, // -39.25, -68.43 x -38.83, -68.01
    { 147508, Bucket(1563) }, // -33.8, -70.95 x -33.38, -70.53
    { 148730, 3526 }, // -17.86, -66.33 x -17.44, -65.91
    { 148731, 3526 }, // -17.44, -66.33 x -17.02, -65.91
    { 149522, Bucket(1568) }, // -34.64, -58.78 x -34.22, -58.37
    { 149777, 588 }, // -27.5, -59.2 x -27.09, -58.78
    { 150518, Bucket(1571) }, // -23.73, -47.04 x -23.31, -46.62
    { 150524, Bucket(1575) }, // -23.73, -46.62 x -23.31, -46.2
    { 151432, 2092 }, // -16.18, -48.3 x -15.76, -47.88
    { 152823, Bucket(1579) }, // 10.24, -67.17 x 10.66, -66.75
    { 156712, 2840 }, // -22.89, -43.27 x -22.47, -42.85
    { 157463, Bucket(1583) }, // -13.24, -38.65 x -12.82, -38.23
    { 160339, 1763 }, // -4.017, -38.65 x -3.597, -38.23
    { 160450, 3601 }, // -6.114, -35.3 x -5.694, -34.88
    { 188152, 2493 }, // 8.986, 7.066 x 9.405, 7.485
    { 189075, Bucket(1586) }, // -34.22, 18.39 x -33.8, 18.81
    { 190954, 3032 }, // -26.25, 27.62 x -25.83, 28.04
    { 196652, 2094 }, // 18.21, -70.11 x 18.63, -69.69
    { 196782, 1539 }, // 18.21, -66.33 x 18.63, -65.91
    { 197967, Bucket(1590) }, // 42.12, -71.37 x 42.54, -70.95
    { 197978, 2975 }, // 42.54, -71.37 x 42.96, -70.95
    { 197989, 2971 }, // 42.12, -70.95 x 42.54, -70.53
    { 231161, Bucket(1600) }, // 36.25, -6.356 x 36.67, -5.936
    { 231164, 3145 }, // 36.67, -6.356 x 37.09, -5.936
    { 231165, Bucket(1603) }, // 37.09, -6.356 x 37.51, -5.936
    { 231167, 3121 }, // 37.09, -5.936 x 37.51, -5.517
    { 231214, 2942 }, // 38.35, -9.292 x 38.77, -8.872
    { 231300, 2942 }, // 38.35, -8.872 x 38.77, -8.453
    { 231317, 2327 }, // 40.44, -8.872 x 40.86, -8.453
    { 231360, Bucket(1606) }, // 40.86, -8.872 x 41.28, -8.453
    { 231419, Bucket(1612) }, // 42.96, -5.936 x 43.38, -5.517
    { 232540, 2134 }, // 36.67, -4.678 x 37.09, -4.259
    { 232565, 1921 }, // 37.09, -3.839 x 37.51, -3.42
    { 232735, 2576 }, // 40.44, -4.259 x 40.86, -3.839
    { 232757, 2173 }, // 40.44, -3.839 x 40.86, -3.42
    { 232817, 3201 }, // 42.96, -3.839 x 43.38, -3.42
    { 232869, 1741 }, // 38.77, -0.4838 x 39.18, -0.06436
    { 232880, 1741 }, // 39.18, -0.4838 x 39.6, -0.06436
    { 232913, Bucket(1615) }, // 42.96, -2.162 x 43.38, -1.742
    { 232938, 1719 }, // 40.86, 0.7745 x 41.28, 1.194
    { 233076, 2020 }, // 36.67, 2.872 x 37.09, 3.291
    { 233242, Bucket(1618) }, // 39.18, 2.452 x 39.6, 2.872
    { 233243, Bucket(1618) }, // 39.6, 2.452 x 40.02, 2.872
    { 233280, 1719 }, // 40.86, 1.194 x 41.28, 1.613
    { 233289, Bucket(1621) }, // 41.28, 2.033 x 41.7, 2.452
    { 233300, Bucket(1625) }, // 43.38, 1.194 x 43.8, 1.613
    { 233317, Bucket(1630) }, // 42.12, 2.872 x 42.54, 3.291
    { 233328, Bucket(1630) }, // 42.54, 2.872 x 42.96, 3.291
    { 233340, Bucket(1634) }, // 43.38, 3.711 x 43.8, 4.13
    { 233468, 3240 }, // 43.38, 7.066 x 43.8, 7.485
    { 234425, 1891 }, // 53.03, -6.356 x 53.45, -5.936
    { 235593, 2968 }, // 47.99, -4.678 x 48.41, -4.259
    { 235596, 2968 }, // 48.41, -4.678 x 48.83, -4.259
    { 235659, Bucket(1638) }, // 44.64, -0.9032 x 45.06, -0.4838
    { 235671, Bucket(1643) }, // 47.15, -1.742 x 47.57, -1.323
    { 235709, 1209 }, // 47.15, 0.3551 x 47.57, 0.7745
    { 235714, 1380 }, // 47.57, -1.742 x 47.99, -1.323
    { 235762, 1313 }, // 49.25, -0.06436 x 49.67, 0.3551
    { 235811, 267 }, // 51.35, -3.42 x 51.77, -3
    { 235909, 260 }, // 52.19, -2.162 x 52.61, -1.742
    { 235937, Bucket(1646) }, // 51.35, -0.4838 x 51.77, -0.06436
    { 235971, Bucket(1651) }, // 54.7, -1.742 x 55.12, -1.323
    { 236108, Bucket(1654) }, // 48.41, 2.033 x 48.83, 2.452
    { 236109, Bucket(1658) }, // 48.83, 2.033 x 49.25, 2.452
    { 236149, Bucket(1661) }, // 50.51, 2.872 x 50.93, 3.291
    { 236150, 2016 }, // 50.09, 3.291 x 50.51, 3.711
    { 236158, Bucket(1666) }, // 50.09, 4.13 x 50.51, 4.549
    { 236159, Bucket(1669) }, // 50.51, 4.13 x 50.93, 4.549
    { 236165, 472 }, // 45.48, 4.549 x 45.9, 4.969
    { 236183, 688 }, // 47.15, 4.969 x 47.57, 5.388
    { 236186, Bucket(1688) }, // 45.9, 5.808 x 46.31, 6.227
    { 236191, Bucket(1691) }, // 47.15, 5.808 x 47.57, 6.227
    { 236203, Bucket(1694) }, // 44.64, 7.485 x 45.06, 7.905
    { 236206, Bucket(1697) }, // 45.06, 7.485 x 45.48, 7.905
    { 236209, 3295 }, // 46.31, 6.227 x 46.73, 6.647
    { 236214, 3593 }, // 46.73, 6.647 x 47.15, 7.066
    { 236220, Bucket(1703) }, // 46.73, 7.066 x 47.15, 7.485
    { 236221, 2878 }, // 47.15, 7.066 x 47.57, 7.485
    { 236222, Bucket(1714) }, // 46.73, 7.485 x 47.15, 7.905
    { 236223, Bucket(1721) }, // 47.15, 7.485 x 47.57, 7.905
    { 236245, Bucket(1729) }, // 50.51, 4.549 x 50.93, 4.969
    { 236253, 1849 }, // 50.51, 5.388 x 50.93, 5.808
    { 236264, Bucket(1733) }, // 47.57, 7.066 x 47.99, 7.485
    { 236266, Bucket(1736) }, // 47.57, 7.485 x 47.99, 7.905
    { 236267, 161 }, // 47.99, 7.485 x 48.41, 7.905
    { 236270, Bucket(1739) }, // 48.41, 7.485 x 48.83, 7.905
    { 236279, Bucket(1743) }, // 50.51, 6.647 x 50.93, 7.066
    { 236282, 920 }, // 49.25, 7.485 x 49.67, 7.905
    { 236285, Bucket(1746) }, // 50.51, 7.066 x 50.93, 7.485
    { 236330, Bucket(1752) }, // 50.93, 4.13 x 51.35, 4.549
    { 236334, Bucket(1755) }, // 51.77, 4.13 x 52.19, 4.549
    { 236420, 1733 }, // 51.77, 4.549 x 52.19, 4.969
    { 236421, 2494 }, // 52.19, 4.549 x 52.61, 4.969
    { 236422, Bucket(1765) }, // 51.77, 4.969 x 52.19, 5.388
    { 236450, Bucket(1769) }, // 50.93, 6.647 x 51.35, 7.066
    { 236451, Bucket(1773) }, // 51.35, 6.647 x 51.77, 7.066
    { 236457, Bucket(1777) }, // 51.35, 7.066 x 51.77, 7.485
    { 237206, Bucket(1783) }, // 60.16, 4.969 x 60.58, 5.388
    { 238710, Bucket(1786) }, // 36.67, 10 x 37.09, 10.42
    { 238975, 1654 }, // 43.8, 10.84 x 44.22, 11.26
    { 239039, Bucket(1790) }, // 40.44, 14.2 x 40.86, 14.62
    { 239052, Bucket(1797) }, // 41.7, 12.1 x 42.12, 12.52
    { 239054, 3435 }, // 41.7, 12.52 x 42.12, 12.94
    { 239082, Bucket(1800) }, // 40.86, 14.2 x 41.28, 14.62
    { 239424, 3690 }, // 40.86, 14.62 x 41.28, 15.04
    { 241008, Bucket(1804) }, // 42.54, 23 x 42.96, 23.42
    { 241276, Bucket(1807) }, // 36.67, 30.55 x 37.09, 30.97
    { 241436, 2207 }, // 40.02, 28.88 x 40.44, 29.3
    { 241474, Bucket(1810) }, // 40.86, 28.46 x 41.28, 28.88
    { 241480, Bucket(1814) }, // 40.86, 28.88 x 41.28, 29.3
    { 241563, Bucket(1824) }, // 39.6, 32.65 x 40.02, 33.07
    { 241672, 1046 }, // 44.22, 8.744 x 44.64, 9.163
    { 241677, Bucket(1827) }, // 45.48, 8.744 x 45.9, 9.163
    { 241679, Bucket(1831) }, // 45.48, 9.163 x 45.9, 9.583
    { 241682, 3532 }, // 45.9, 8.324 x 46.31, 8.744
    { 241684, Bucket(1834) }, // 46.73, 7.905 x 47.15, 8.324
    { 241685, Bucket(1840) }, // 47.15, 7.905 x 47.57, 8.324
    { 241686, Bucket(1849) }, // 46.73, 8.324 x 47.15, 8.744
    { 241687, Bucket(1853) }, // 47.15, 8.324 x 47.57, 8.744
    { 241688, Bucket(1879) }, // 45.9, 8.744 x 46.31, 9.163
    { 241692, Bucket(1883) }, // 46.73, 8.744 x 47.15, 9.163
    { 241693, Bucket(1886) }, // 47.15, 8.744 x 47.57, 9.163
    { 241694, Bucket(1896) }, // 46.73, 9.163 x 47.15, 9.583
    { 241695, Bucket(1899) }, // 47.15, 9.163 x 47.57, 9.583
    { 241701, 3576 }, // 45.48, 9.583 x 45.9, 10
    { 241706, Bucket(1910) }, // 44.22, 10.84 x 44.64, 11.26
    { 241717, Bucket(1914) }, // 47.15, 9.583 x 47.57, 10
    { 241727, Bucket(1917) }, // 47.15, 10.84 x 47.57, 11.26
    { 241728, 1939 }, // 47.57, 7.905 x 47.99, 8.324
    { 241729, 1939 }, // 47.99, 7.905 x 48.41, 8.324
    { 241730, 595 }, // 47.57, 8.324 x 47.99, 8.744
    { 241733, 1432 }, // 48.83, 7.905 x 49.25, 8.324
    { 241735, Bucket(1921) }, // 48.83, 8.324 x 49.25, 8.744
    { 241736, 592 }, // 47.57, 8.744 x 47.99, 9.163
    { 241742, 198 }, // 48.41, 9.163 x 48.83, 9.583
    { 241744, Bucket(1930) }, // 49.25, 7.905 x 49.67, 8.324
    { 241746, Bucket(1936) }, // 49.25, 8.324 x 49.67, 8.744
    { 241747, Bucket(1955) }, // 49.67, 8.324 x 50.09, 8.744
    { 241750, Bucket(1965) }, // 50.09, 8.324 x 50.51, 8.744
    { 241752, Bucket(1970) }, // 49.25, 8.744 x 49.67, 9.163
    { 241754, 919 }, // 49.25, 9.163 x 49.67, 9.583
    { 241756, 712 }, // 50.09, 8.744 x 50.51, 9.163
    { 241771, Bucket(1974) }, // 47.99, 10.84 x 48.41, 11.26
    { 241775, 231 }, // 48.83, 10.84 x 49.25, 11.26
    { 241786, Bucket(1979) }, // 49.25, 10.84 x 49.67, 11.26
    { 241789, 954 }, // 50.51, 10.42 x 50.93, 10.84
    { 241792, Bucket(1988) }, // 44.22, 11.26 x 44.64, 11.68
    { 241798, 364 }, // 45.06, 11.68 x 45.48, 12.1
    { 241804, 1631 }, // 45.06, 12.1 x 45.48, 12.52
    { 241805, 1631 }, // 45.48, 12.1 x 45.9, 12.52
    { 241813, 1363 }, // 47.15, 11.26 x 47.57, 11.68
    { 241823, 2416 }, // 47.15, 12.52 x 47.57, 12.94
    { 241845, 2416 }, // 47.15, 12.94 x 47.57, 13.36
    { 241849, 3510 }, // 46.31, 13.78 x 46.73, 14.2
    { 241851, 1236 }, // 46.31, 14.2 x 46.73, 14.62
    { 241854, 1236 }, // 46.73, 14.2 x 47.15, 14.62
    { 241855, 2720 }, // 47.15, 14.2 x 47.57, 14.62
    { 241856, 3196 }, // 47.57, 11.26 x 47.99, 11.68
    { 241857, Bucket(1991) }, // 47.99, 11.26 x 48.41, 11.68
    { 241858, 3196 }, // 47.57, 11.68 x 47.99, 12.1
    { 241859, 145 }, // 47.99, 11.68 x 48.41, 12.1
    { 241860, 1902 }, // 48.41, 11.26 x 48.83, 11.68
    { 241861, 231 }, // 48.83, 11.26 x 49.25, 11.68
    { 241862, 1902 }, // 48.41, 11.68 x 48.83, 12.1
    { 241866, Bucket(1998) }, // 47.57, 12.52 x 47.99, 12.94
    { 241872, 231 }, // 49.25, 11.26 x 49.67, 11.68
    { 241885, 869 }, // 50.51, 12.1 x 50.93, 12.52
    { 241887, Bucket(2001) }, // 50.51, 12.52 x 50.93, 12.94
    { 241888, Bucket(1997) }, // 47.57, 12.94 x 47.99, 13.36
    { 241899, Bucket(2005) }, // 47.99, 14.2 x 48.41, 14.62
    { 241909, Bucket(2002) }, // 50.51, 12.94 x 50.93, 13.36
    { 241911, 1764 }, // 50.51, 13.36 x 50.93, 13.78
    { 241915, Bucket(2008) }, // 49.67, 14.2 x 50.09, 14.62
    { 241917, 1764 }, // 50.51, 13.78 x 50.93, 14.2
    { 241918, Bucket(2031) }, // 50.09, 14.2 x 50.51, 14.62
    { 241926, Bucket(2049) }, // 51.77, 8.324 x 52.19, 8.744
    { 241935, 1061 }, // 52.19, 9.163 x 52.61, 9.583
    { 241946, 1061 }, // 52.61, 9.163 x 53.03, 9.583
    { 241957, Bucket(2053) }, // 52.19, 9.583 x 52.61, 10
    { 241960, 954 }, // 50.93, 10.42 x 51.35, 10.84
    { 241961, 153 }, // 51.35, 10.42 x 51.77, 10.84
    { 241962, Bucket(2068) }, // 50.93, 10.84 x 51.35, 11.26
    { 241972, Bucket(2072) }, // 53.45, 9.583 x 53.86, 10
    { 242034, 3567 }, // 55.96, 10 x 56.38, 10.42
    { 242056, Bucket(2075) }, // 50.93, 12.1 x 51.35, 12.52
    { 242068, Bucket(2078) }, // 53.45, 11.26 x 53.86, 11.68
    { 242071, Bucket(2082) }, // 53.86, 11.68 x 54.28, 12.1
    { 242077, Bucket(2086) }, // 53.86, 12.1 x 54.28, 12.52
    { 242082, Bucket(2091) }, // 50.93, 13.36 x 51.35, 13.78
    { 242085, Bucket(2096) }, // 52.19, 12.94 x 52.61, 13.36
    { 242087, Bucket(2105) }, // 52.19, 13.36 x 52.61, 13.78
    { 242088, Bucket(2119) }, // 50.93, 13.78 x 51.35, 14.2
    { 242096, 1252 }, // 52.61, 12.94 x 53.03, 13.36
    { 242149, 400 }, // 55.54, 12.94 x 55.96, 13.36
    { 242193, 1236 }, // 46.31, 14.62 x 46.73, 15.04
    { 242196, 1236 }, // 46.73, 14.62 x 47.15, 15.04
    { 242198, 3094 }, // 46.73, 15.04 x 47.15, 15.45
    { 242199, 228 }, // 47.15, 15.04 x 47.57, 15.45
    { 242251, Bucket(2122) }, // 47.99, 15.87 x 48.41, 16.29
    { 242257, Bucket(2028) }, // 49.67, 14.62 x 50.09, 15.04
    { 242271, 2063 }, // 50.51, 15.87 x 50.93, 16.29
    { 242273, Bucket(2127) }, // 47.99, 16.29 x 48.41, 16.71
    { 242275, Bucket(2143) }, // 47.99, 16.71 x 48.41, 17.13
    { 242281, Bucket(2143) }, // 47.99, 17.13 x 48.41, 17.55
    { 242299, Bucket(2146) }, // 49.67, 17.55 x 50.09, 17.97
    { 242333, Bucket(2149) }, // 47.15, 18.81 x 47.57, 19.23
    { 242334, 1486 }, // 46.73, 19.23 x 47.15, 19.65
    { 242356, 1486 }, // 46.73, 19.65 x 47.15, 20.07
    { 242376, Bucket(2162) }, // 47.57, 18.81 x 47.99, 19.23
    { 242385, Bucket(2166) }, // 49.67, 17.97 x 50.09, 18.39
    { 242390, Bucket(2172) }, // 50.09, 18.39 x 50.51, 18.81
    { 242396, Bucket(2175) }, // 50.09, 18.81 x 50.51, 19.23
    { 242409, 3174 }, // 47.99, 20.49 x 48.41, 20.91
    { 242417, 3430 }, // 49.67, 19.65 x 50.09, 20.07
    { 242432, Bucket(2188) }, // 50.93, 14.62 x 51.35, 15.04
    { 242450, Bucket(2191) }, // 52.61, 15.04 x 53.03, 15.45
    { 242466, Bucket(2194) }, // 50.93, 16.71 x 51.35, 17.13
    { 242471, Bucket(2205) }, // 52.19, 16.71 x 52.61, 17.13
    { 242571, Bucket(2228) }, // 51.35, 19.23 x 51.77, 19.65
    { 242574, Bucket(2243) }, // 51.77, 19.23 x 52.19, 19.65
    { 242578, Bucket(2256) }, // 52.61, 18.39 x 53.03, 18.81
    { 242579, Bucket(2256) }, // 53.03, 18.39 x 53.45, 18.81
    { 242591, Bucket(2264) }, // 53.86, 19.23 x 54.28, 19.65
    { 242607, Bucket(2268) }, // 52.19, 20.91 x 52.61, 21.33
    { 242626, Bucket(2272) }, // 54.28, 18.39 x 54.7, 18.81
    { 242745, Bucket(2282) }, // 59.74, 10.42 x 60.16, 10.84
    { 242818, Bucket(2289) }, // 57.64, 11.68 x 58.06, 12.1
    { 243333, 1067 }, // 58.9, 17.97 x 59.32, 18.39
    { 243344, Bucket(2292) }, // 59.32, 17.97 x 59.74, 18.39
    { 243728, Bucket(2296) }, // 45.9, 21.33 x 46.31, 21.75
    { 243766, Bucket(2299) }, // 46.73, 23.42 x 47.15, 23.84
    { 243833, Bucket(2302) }, // 49.67, 23.84 x 50.09, 24.26
    { 243850, Bucket(2307) }, // 44.22, 25.94 x 44.64, 26.36
    { 243886, Bucket(2326) }, // 45.06, 27.62 x 45.48, 28.04
    { 244092, Bucket(2330) }, // 56.8, 23.84 x 57.22, 24.26
    { 244197, 656 }, // 55.54, 26.36 x 55.96, 26.78
    { 244374, 3102 }, // 46.73, 31.81 x 47.15, 32.23
    { 244550, 2817 }, // 55.12, 28.46 x 55.54, 28.88
    { 244783, 3518 }, // 58.9, 24.26 x 59.32, 24.68
    { 244794, 3518 }, // 59.32, 24.26 x 59.74, 24.68
    { 244884, Bucket(2334) }, // 60.16, 24.68 x 60.58, 25.1
    { 245299, Bucket(2341) }, // 59.74, 30.13 x 60.16, 30.55
    { 545061, Bucket(2368) }, // -1.5, 36.43 x -1.081, 36.85
    { 545063, 2502 }, // -1.5, 36.85 x -1.081, 37.26
    { 545991, 1674 }, // 8.566, 38.52 x 8.986, 38.94
    { 546002, Bucket(2371) }, // 8.986, 38.52 x 9.405, 38.94
    { 556126, 2172 }, // 9.824, 76.27 x 10.24, 76.69
    { 556465, Bucket(2374) }, // 12.76, 80.05 x 13.18, 80.47
    { 579420, Bucket(2379) }, // 16.54, 95.99 x 16.95, 96.4
    { 579509, Bucket(2384) }, // 13.6, 100.2 x 14.02, 100.6
    { 579709, 2776 }, // -3.178, 104.4 x -2.758, 104.8
    { 579743, 3687 }, // -6.533, 106.5 x -6.114, 106.9
    { 579765, 3687 }, // -6.533, 106.9 x -6.114, 107.3
    { 579937, 2462 }, // 1.016, 103.5 x 1.436, 104
    { 581002, 3801 }, // 10.66, 106.5 x 11.08, 106.9
    { 581702, 3548 }, // -32.12, 115.7 x -31.7, 116.1
    { 584239, Bucket(2387) }, // -35.05, 138.3 x -34.64, 138.8
    { 587235, Bucket(2397) }, // 14.44, 120.7 x 14.86, 121.2
    { 590049, 2110 }, // 21.15, 39.78 x 21.57, 40.2
    { 590753, Bucket(2401) }, // 24.5, 46.49 x 24.92, 46.91
    { 591755, 2023 }, // 37.93, 46.07 x 38.35, 46.49
    { 592345, 2052 }, // 29.54, 52.36 x 29.96, 52.78
    { 593005, 3625 }, // 35.41, 50.69 x 35.83, 51.11
    { 593007, Bucket(2406) }, // 35.41, 51.11 x 35.83, 51.53
    { 593016, 3625 }, // 35.83, 50.69 x 36.25, 51.11
    { 593040, 2053 }, // 32.47, 51.53 x 32.89, 51.95
    { 593988, Bucket(2409) }, // 48.41, 34.75 x 48.83, 35.17
    { 594011, Bucket(2414) }, // 49.67, 36.01 x 50.09, 36.43
    { 594285, Bucket(2417) }, // 55.54, 37.26 x 55.96, 37.68
    { 594287, Bucket(2431) }, // 55.54, 37.68 x 55.96, 38.1
    { 594825, Bucket(2438) }, // 51.35, 45.65 x 51.77, 46.07
    { 596245, Bucket(2441) }, // 53.86, 48.17 x 54.28, 48.59
    { 596288, Bucket(2441) }, // 54.28, 48.17 x 54.7, 48.59
    { 596301, Bucket(2446) }, // 55.54, 49.01 x 55.96, 49.43
    { 596429, Bucket(2453) }, // 55.54, 52.36 x 55.96, 52.78
    { 596979, 1145 }, // 56.38, 60.33 x 56.8, 60.75
    { 596982, Bucket(2458) }, // 56.8, 60.33 x 57.22, 60.75
    { 598745, Bucket(2469) }, // 22.83, 72.5 x 23.25, 72.92
    { 599721, 3217 }, // 31.22, 74.17 x 31.63, 74.59
    { 600420, 2243 }, // 28.28, 76.69 x 28.7, 77.11
    { 600422, 2383 }, // 28.28, 77.11 x 28.7, 77.53
    { 600497, 3436 }, // 26.18, 80.05 x 26.6, 80.47
    { 600502, 2449 }, // 26.6, 80.47 x 27.02, 80.89
    { 600508, 2449 }, // 26.6, 80.89 x 27.02, 81.31
    { 600826, 2379 }, // 22.41, 88.02 x 22.83, 88.44
    { 601457, 2111 }, // 42.96, 76.69 x 43.38, 77.11
    { 624890, 3234 }, // 22.41, 108.1 x 22.83, 108.6
    { 624908, 1047 }, // 24.92, 102.7 x 25.34, 103.1
    { 625015, Bucket(2472) }, // 30.38, 104 x 30.8, 104.4
    { 625051, 2116 }, // 26.18, 106.5 x 26.6, 106.9
    { 625054, 2116 }, // 26.6, 106.5 x 27.02, 106.9
    { 625112, 3516 }, // 29.12, 106.1 x 29.54, 106.5
    { 625115, 2703 }, // 29.54, 106.5 x 29.96, 106.9
    { 625371, Bucket(2478) }, // 22.83, 113.2 x 23.25, 113.6
    { 625383, Bucket(2483) }, // 21.99, 114 x 22.41, 114.4
    { 625392, 3565 }, // 22.41, 113.6 x 22.83, 114
    { 625393, Bucket(2487) }, // 22.83, 113.6 x 23.25, 114
    { 625394, Bucket(2490) }, // 22.41, 114 x 22.83, 114.4
    { 625609, Bucket(2497) }, // 27.86, 112.8 x 28.28, 113.2
    { 625655, Bucket(2502) }, // 30.38, 114 x 30.8, 114.4
    { 625661, 3784 }, // 30.38, 114.4 x 30.8, 114.9
    { 625776, Bucket(2510) }, // 35.83, 103.5 x 36.25, 104
    { 626240, Bucket(2513) }, // 34.15, 108.6 x 34.57, 109
    { 626242, 3348 }, // 34.15, 109 x 34.57, 109.4
    { 626338, 2708 }, // 30.8, 114 x 31.22, 114.4
    { 626379, Bucket(2516) }, // 34.57, 113.2 x 34.99, 113.6
    { 626401, Bucket(2520) }, // 34.57, 113.6 x 34.99, 114
    { 626495, Bucket(2527) }, // 40.44, 111.5 x 40.86, 111.9
    { 626538, 3187 }, // 40.86, 111.5 x 41.28, 111.9
    { 626562, 3498 }, // 37.51, 112.3 x 37.93, 112.8
    { 631002, Bucket(2530) }, // 22.41, 119.9 x 22.83, 120.3
    { 631024, Bucket(2530) }, // 22.41, 120.3 x 22.83, 120.7
    { 631110, Bucket(2533) }, // 28.28, 115.7 x 28.7, 116.1
    { 631144, 3561 }, // 27.44, 117.8 x 27.86, 118.2
    { 631186, Bucket(2536) }, // 25.76, 119.1 x 26.18, 119.5
    { 631212, 1887 }, // 24.92, 121.2 x 25.34, 121.6
    { 631262, Bucket(2539) }, // 29.96, 119.9 x 30.38, 120.3
    { 631276, 3589 }, // 28.28, 121.2 x 28.7, 121.6
    { 631281, 3340 }, // 29.54, 120.3 x 29.96, 120.7
    { 631284, Bucket(2544) }, // 29.96, 120.3 x 30.38, 120.7
    { 631844, Bucket(2547) }, // 31.63, 117 x 32.05, 117.4
    { 631855, 3663 }, // 32.05, 118.2 x 32.47, 118.6
    { 631904, Bucket(2551) }, // 34.15, 117 x 34.57, 117.4
    { 631940, Bucket(2554) }, // 31.63, 118.6 x 32.05, 119.1
    { 631941, Bucket(2557) }, // 32.05, 118.6 x 32.47, 119.1
    { 631950, 3800 }, // 31.63, 119.9 x 32.05, 120.3
    { 631971, 2490 }, // 31.22, 120.7 x 31.63, 121.2
    { 631974, 3556 }, // 31.63, 120.7 x 32.05, 121.2
    { 631975, 3556 }, // 32.05, 120.7 x 32.47, 121.2
    { 631976, 1859 }, // 30.8, 121.2 x 31.22, 121.6
    { 632026, 3827 }, // 35.83, 119.9 x 36.25, 120.3
    { 632048, 3582 }, // 35.83, 120.3 x 36.25, 120.7
    { 632089, Bucket(2561) }, // 39.6, 116.1 x 40.02, 116.5
    { 632092, 392 }, // 40.02, 116.1 x 40.44, 116.5
    { 632101, Bucket(2568) }, // 38.77, 117 x 39.18, 117.4
    { 632112, Bucket(2570) }, // 39.18, 117 x 39.6, 117.4
    { 632239, Bucket(2574) }, // 38.77, 121.6 x 39.18, 122
    { 632250, 3442 }, // 39.18, 121.6 x 39.6, 122
    { 632526, 3425 }, // 34.99, 126.6 x 35.41, 127
    { 632543, Bucket(2578) }, // 37.09, 126.6 x 37.51, 127
    { 632559, 2196 }, // 35.41, 128.3 x 35.83, 128.7
    { 632565, 2076 }, // 37.09, 127 x 37.51, 127.4
    { 632570, Bucket(2581) }, // 35.83, 128.3 x 36.25, 128.7
    { 632581, 2255 }, // 38.77, 122 x 39.18, 122.4
    { 632651, Bucket(2584) }, // 41.28, 123.2 x 41.7, 123.7
    { 632654, Bucket(2590) }, // 41.7, 123.2 x 42.12, 123.7
    { 632709, 3139 }, // 38.77, 125.3 x 39.18, 125.8
    { 632714, 2541 }, // 37.51, 126.6 x 37.93, 127
    { 633924, Bucket(2598) }, // 34.99, 128.7 x 35.41, 129.1
    { 634048, Bucket(2602) }, // 34.15, 132.1 x 34.57, 132.5
    { 634050, Bucket(2606) }, // 34.15, 132.5 x 34.57, 132.9
    { 634080, 3085 }, // 34.15, 133.7 x 34.57, 134.2
    { 634433, 2879 }, // 34.57, 135.4 x 34.99, 135.8
    { 634446, Bucket(2609) }, // 34.99, 136.7 x 35.41, 137.1
    { 634450, 2886 }, // 35.83, 135.8 x 36.25, 136.3
    { 634573, Bucket(2613) }, // 35.41, 139.6 x 35.83, 140
    { 635535, 2301 }, // 45.48, 126.6 x 45.9, 127
    { 660847, 1082 }, // -38.41, 145.1 x -37.99, 145.5
    { 660856, Bucket(2623) }, // -37.99, 144.6 x -37.57, 145.1
    { 669174, Bucket(2633) }, // -37.15, 174.4 x -36.73, 174.8
    { 669180, 11 }, // -37.15, 174.8 x -36.73, 175.3
    { 672260, 2880 }, // -35.47, 148.8 x -35.05, 149.3
    { 672307, Bucket(2636) }, // -34.22, 150.9 x -33.8, 151.4
    { 256343, 2655 }, // -2.968, -79.13 x -2.758, -78.92
    { 259050, 2651 }, // 8.986, -79.55 x 9.195, -79.34
    { 398857, Bucket(2639) }, // 37.72, -122.5 x 37.93, -122.3
    { 399485, 2282 }, // 33.94, -118.3 x 34.15, -118.1
    { 403703, Bucket(2646) }, // 20.52, -103.5 x 20.73, -103.2
    { 403874, 3178 }, // 20.73, -103.5 x 20.94, -103.2
    { 405594, 3688 }, // 33.31, -112.3 x 33.52, -112.1
    { 405616, 2543 }, // 33.31, -112.1 x 33.52, -111.8
    { 406645, 1757 }, // 40.65, -112.1 x 40.86, -111.8
    { 410047, Bucket(2650) }, // 49.04, -123.2 x 49.25, -123
    { 410090, Bucket(2650) }, // 49.25, -123.2 x 49.46, -123
    { 410134, 208 }, // 45.48, -122.7 x 45.69, -122.5
    { 410204, 1302 }, // 47.15, -122.5 x 47.36, -122.3
    { 410389, Bucket(2650) }, // 49.04, -123 x 49.25, -122.7
    { 410432, Bucket(2650) }, // 49.25, -123 x 49.46, -122.7
    { 426051, Bucket(2653) }, // 19.26, -99.26 x 19.47, -99.05
    { 426054, 2293 }, // 19.47, -99.26 x 19.68, -99.05
    { 430305, 1079 }, // 32.68, -96.95 x 32.89, -96.74
    { 433978, Bucket(2658) }, // 41.7, -87.94 x 41.91, -87.73
    { 434064, Bucket(2658) }, // 41.7, -87.73 x 41.91, -87.52
    { 435871, Bucket(2661) }, // 25.55, -80.39 x 25.76, -80.18
    { 435914, Bucket(2661) }, // 25.76, -80.39 x 25.97, -80.18
    { 438484, 1443 }, // 33.73, -84.37 x 33.94, -84.16
    { 440280, 3137 }, // 43.38, -80.59 x 43.59, -80.39
    { 440315, Bucket(2664) }, // 43.59, -79.55 x 43.8, -79.34
    { 441681, 2238 }, // 43.59, -79.34 x 43.8, -79.13
    { 441935, Bucket(2673) }, // 39.81, -75.35 x 40.02, -75.14
    { 441957, 2306 }, // 39.81, -75.14 x 40.02, -74.93
    { 442069, 2804 }, // 40.65, -74.3 x 40.86, -74.09
    { 442071, Bucket(2680) }, // 40.65, -74.09 x 40.86, -73.88
    { 442242, Bucket(2686) }, // 40.86, -74.09 x 41.07, -73.88
    { 443047, 903 }, // 44.85, -93.39 x 45.06, -93.18
    { 453139, 2853 }, // 45.27, -75.77 x 45.48, -75.56
    { 590035, Bucket(2689) }, // -33.59, -70.74 x -33.38, -70.53
    { 598090, Bucket(2695) }, // -34.64, -58.57 x -34.43, -58.37
    { 602074, Bucket(2698) }, // -23.73, -46.83 x -23.52, -46.62
    { 605731, 2093 }, // -15.97, -48.09 x -15.76, -47.88
    { 611292, 2409 }, // 10.24, -67.17 x 10.45, -66.96
    { 611295, 3388 }, // 10.45, -66.96 x 10.66, -66.75
    { 624095, 1801 }, // -23.1, -43.48 x -22.89, -43.27
    { 624117, 1801 }, // -23.1, -43.27 x -22.89, -43.06
    { 626849, 2835 }, // -22.68, -43.27 x -22.47, -43.06
    { 626900, 1761 }, // -19.96, -44.1 x -19.75, -43.89
    { 630271, 3322 }, // -9.679, -35.93 x -9.469, -35.72
    { 639724, 2990 }, // -7.372, -39.49 x -7.162, -39.28
    { 641357, 2841 }, // -3.807, -38.65 x -3.597, -38.44
    { 641566, Bucket(2701) }, // -8.211, -35.09 x -8.001, -34.88
    { 641615, 2992 }, // -7.162, -35.09 x -6.953, -34.88
    { 641637, 2992 }, // -7.162, -34.88 x -6.953, -34.67
    { 752610, 2652 }, // 8.986, 7.276 x 9.195, 7.485
    { 764412, 3021 }, // -30.02, 30.97 x -29.81, 31.18
    { 765184, 3034 }, // -26.25, 28.04 x -26.04, 28.25
    { 765190, 3035 }, // -25.83, 28.25 x -25.62, 28.46
    { 786609, 2095 }, // 18.42, -70.11 x 18.63, -69.9
    { 791871, 1385 }, // 42.33, -71.16 x 42.54, -70.95
    { 918960, 129 }, // 28.28, -16.42 x 28.49, -16.21
    { 924375, 1589 }, // 33.94, -6.985 x 34.15, -6.775
    { 924663, Bucket(2706) }, // 37.3, -6.146 x 37.51, -5.936
    { 924669, 3123 }, // 37.3, -5.936 x 37.51, -5.727
    { 924857, Bucket(2709) }, // 38.56, -9.292 x 38.77, -9.082
    { 925443, Bucket(2716) }, // 41.07, -8.663 x 41.28, -8.453
    { 930760, 3623 }, // 35.83, -0.06436 x 36.04, 0.1454
    { 930939, Bucket(2720) }, // 40.23, -4.049 x 40.44, -3.839
    { 931025, Bucket(2723) }, // 40.23, -3.839 x 40.44, -3.63
    { 931028, 2189 }, // 40.44, -3.839 x 40.65, -3.63
    { 931269, 1383 }, // 43.17, -3.839 x 43.38, -3.63
    { 931279, Bucket(2728) }, // 43.17, -3.21 x 43.38, -3
    { 931280, 1383 }, // 43.38, -3.839 x 43.59, -3.63
    { 931299, Bucket(2732) }, // 42.75, -2.791 x 42.96, -2.581
    { 931301, Bucket(2735) }, // 43.17, -3 x 43.38, -2.791
    { 931364, 3320 }, // 37.93, -1.323 x 38.14, -1.113
    { 931435, 1652 }, // 39.39, -0.6935 x 39.6, -0.4838
    { 931521, Bucket(2741) }, // 39.39, -0.4838 x 39.6, -0.2741
    { 932306, Bucket(2748) }, // 36.67, 3.081 x 36.88, 3.291
    { 932379, 3366 }, // 31.84, 5.179 x 32.05, 5.388
    { 933134, Bucket(2751) }, // 41.28, 1.823 x 41.49, 2.033
    { 933156, Bucket(2754) }, // 41.28, 2.033 x 41.49, 2.243
    { 933711, 264 }, // 43.17, 5.179 x 43.38, 5.388
    { 933733, 264 }, // 43.17, 5.388 x 43.38, 5.598
    { 933873, 2882 }, // 43.59, 7.066 x 43.8, 7.276
    { 942684, 805 }, // 47.15, -1.742 x 47.36, -1.532
    { 942719, Bucket(2768) }, // 47.36, -0.6935 x 47.57, -0.4838
    { 942860, Bucket(2771) }, // 47.99, -1.742 x 48.2, -1.532
    { 943082, 262 }, // 49.25, 0.9842 x 49.46, 1.194
    { 943343, Bucket(2777) }, // 53.24, -2.371 x 53.45, -2.162
    { 943354, Bucket(2774) }, // 53.45, -2.371 x 53.65, -2.162
    { 943415, 2105 }, // 55.75, -4.468 x 55.96, -4.259
    { 943421, 2105 }, // 55.75, -4.259 x 55.96, -4.049
    { 943637, 3807 }, // 52.4, -2.162 x 52.61, -1.952
    { 943695, Bucket(2780) }, // 53.24, -1.532 x 53.45, -1.323
    { 943713, 756 }, // 52.82, -1.323 x 53.03, -1.113
    { 943750, 2031 }, // 51.35, -0.2741 x 51.56, -0.06436
    { 943756, 2124 }, // 51.35, -0.06436 x 51.56, 0.1454
    { 944279, 2624 }, // 45.69, 3.081 x 45.9, 3.291
    { 944395, Bucket(2785) }, // 47.78, 1.823 x 47.99, 2.033
    { 944435, Bucket(2788) }, // 48.62, 2.243 x 48.83, 2.452
    { 944438, Bucket(2791) }, // 48.83, 2.243 x 49.04, 2.452
    { 944444, Bucket(2797) }, // 48.83, 2.452 x 49.04, 2.662
    { 944567, Bucket(2800) }, // 49.04, 3.92 x 49.25, 4.13
    { 944603, 2015 }, // 50.3, 3.501 x 50.51, 3.711
    { 944610, Bucket(2800) }, // 49.25, 3.92 x 49.46, 4.13
    { 944635, Bucket(2803) }, // 50.3, 4.34 x 50.51, 4.549
    { 944639, Bucket(2806) }, // 50.72, 4.34 x 50.93, 4.549
    { 944663, Bucket(2812) }, // 45.69, 4.759 x 45.9, 4.969
    { 944690, Bucket(2819) }, // 45.06, 5.598 x 45.27, 5.808
    { 944732, 689 }, // 47.15, 4.969 x 47.36, 5.179
    { 944747, Bucket(2824) }, // 46.11, 6.017 x 46.31, 6.227
    { 944750, 383 }, // 46.31, 6.017 x 46.52, 6.227
    { 944836, 383 }, // 46.31, 6.227 x 46.52, 6.437
    { 944881, 3835 }, // 46.94, 7.066 x 47.15, 7.276
    { 944888, 3841 }, // 46.73, 7.485 x 46.94, 7.695
    { 944891, 237 }, // 46.94, 7.695 x 47.15, 7.905
    { 944893, Bucket(2828) }, // 47.36, 7.485 x 47.57, 7.695
    { 944894, Bucket(2842) }, // 47.15, 7.695 x 47.36, 7.905
    { 944895, Bucket(2845) }, // 47.36, 7.695 x 47.57, 7.905
    { 945003, 2118 }, // 49.46, 6.017 x 49.67, 6.227
    { 945064, Bucket(2848) }, // 47.57, 7.485 x 47.78, 7.695
    { 945067, Bucket(2856) }, // 47.78, 7.695 x 47.99, 7.905
    { 945070, Bucket(2859) }, // 47.99, 7.695 x 48.2, 7.905
    { 945119, Bucket(2863) }, // 50.72, 6.856 x 50.93, 7.066
    { 945290, Bucket(2867) }, // 50.93, 3.501 x 51.14, 3.711
    { 945312, Bucket(2867) }, // 50.93, 3.711 x 51.14, 3.92
    { 945323, Bucket(2871) }, // 51.14, 4.34 x 51.35, 4.549
    { 945337, Bucket(2882) }, // 51.98, 4.13 x 52.19, 4.34
    { 945338, Bucket(2889) }, // 51.77, 4.34 x 51.98, 4.549
    { 945339, Bucket(2895) }, // 51.98, 4.34 x 52.19, 4.549
    { 945680, 1734 }, // 51.77, 4.549 x 51.98, 4.759
    { 945686, Bucket(2899) }, // 52.19, 4.759 x 52.4, 4.969
    { 945795, 540 }, // 51.14, 6.437 x 51.35, 6.647
    { 945801, Bucket(2908) }, // 51.14, 6.647 x 51.35, 6.856
    { 945802, Bucket(2921) }, // 50.93, 6.856 x 51.14, 7.066
    { 945806, Bucket(2926) }, // 51.35, 6.856 x 51.56, 7.066
    { 945828, Bucket(2938) }, // 51.35, 7.066 x 51.56, 7.276
    { 945830, Bucket(2945) }, // 51.35, 7.276 x 51.56, 7.485
    { 954840, Bucket(2948) }, // 36.67, 10 x 36.88, 10.21
    { 955490, 1588 }, // 39.18, 8.953 x 39.39, 9.163
    { 955496, 1588 }, // 39.18, 9.163 x 39.39, 9.373
    { 956157, Bucket(2951) }, // 40.65, 14.2 x 40.86, 14.41
    { 956245, 1656 }, // 44.01, 11.26 x 44.22, 11.47
    { 956328, Bucket(2955) }, // 40.86, 14.2 x 41.07, 14.41
    { 957525, 3690 }, // 40.65, 14.62 x 40.86, 14.83
    { 957833, 1181 }, // 41.07, 16.71 x 41.28, 16.92
    { 962042, Bucket(2959) }, // 29.96, 31.18 x 30.17, 31.39
    { 962384, 2040 }, // 29.96, 31.39 x 30.17, 31.6
    { 963591, Bucket(2962) }, // 38.14, 21.54 x 38.35, 21.75
    { 963597, 3194 }, // 38.14, 21.75 x 38.35, 21.96
    { 963726, 2311 }, // 37.93, 23.63 x 38.14, 23.84
    { 964034, Bucket(2965) }, // 42.54, 23.21 x 42.75, 23.42
    { 964250, Bucket(2981) }, // 38.35, 26.99 x 38.56, 27.2
    { 965105, 3219 }, // 36.88, 30.55 x 37.09, 30.76
    { 965920, 1144 }, // 40.86, 28.88 x 41.07, 29.09
    { 966253, Bucket(2984) }, // 39.81, 32.65 x 40.02, 32.86
    { 966713, 3563 }, // 45.27, 9.163 x 45.48, 9.373
    { 966737, 237 }, // 46.94, 7.905 x 47.15, 8.115
    { 966739, 3049 }, // 46.94, 8.115 x 47.15, 8.324
    { 966740, Bucket(2842) }, // 47.15, 7.905 x 47.36, 8.115
    { 966741, 2877 }, // 47.36, 7.905 x 47.57, 8.115
    { 966742, 590 }, // 47.15, 8.115 x 47.36, 8.324
    { 966743, 591 }, // 47.36, 8.115 x 47.57, 8.324
    { 966745, Bucket(2987) }, // 46.94, 8.324 x 47.15, 8.534
    { 966748, Bucket(2987) }, // 47.15, 8.324 x 47.36, 8.534
    { 966749, Bucket(2990) }, // 47.36, 8.324 x 47.57, 8.534
    { 966750, Bucket(2993) }, // 47.15, 8.534 x 47.36, 8.744
    { 966751, Bucket(2996) }, // 47.36, 8.534 x 47.57, 8.744
    { 966752, 3533 }, // 45.9, 8.744 x 46.11, 8.953
    { 966767, 3671 }, // 46.52, 9.373 x 46.73, 9.583
    { 966772, Bucket(3002) }, // 47.15, 8.744 x 47.36, 8.953
    { 966773, Bucket(3007) }, // 47.36, 8.744 x 47.57, 8.953
    { 966775, Bucket(3012) }, // 47.36, 8.953 x 47.57, 9.163
    { 966778, 3671 }, // 46.73, 9.373 x 46.94, 9.583
    { 966783, 3458 }, // 47.36, 9.373 x 47.57, 9.583
    { 966864, 3672 }, // 46.73, 9.583 x 46.94, 9.792
    { 966865, 1261 }, // 46.94, 9.583 x 47.15, 9.792
    { 966867, 3093 }, // 46.94, 9.792 x 47.15, 10
    { 966868, 1261 }, // 47.15, 9.583 x 47.36, 9.792
    { 966869, Bucket(3015) }, // 47.36, 9.583 x 47.57, 9.792
    { 966870, 3093 }, // 47.15, 9.792 x 47.36, 10
    { 966916, 740 }, // 47.99, 7.905 x 48.2, 8.115
    { 966921, 1939 }, // 47.78, 8.324 x 47.99, 8.534
    { 966922, Bucket(3019) }, // 47.57, 8.534 x 47.78, 8.744
    { 966924, 1939 }, // 47.99, 8.324 x 48.2, 8.534
    { 966940, Bucket(3022) }, // 48.83, 8.324 x 49.04, 8.534
    { 966941, 1432 }, // 49.04, 8.324 x 49.25, 8.534
    { 966942, 1432 }, // 48.83, 8.534 x 49.04, 8.744
    { 966944, 2484 }, // 47.57, 8.744 x 47.78, 8.953
    { 966964, 874 }, // 48.83, 8.744 x 49.04, 8.953
    { 966965, Bucket(3028) }, // 49.04, 8.744 x 49.25, 8.953
    { 966966, 201 }, // 48.83, 8.953 x 49.04, 9.163
    { 966967, Bucket(3028) }, // 49.04, 8.953 x 49.25, 9.163
    { 966972, 201 }, // 48.83, 9.163 x 49.04, 9.373
    { 966973, 874 }, // 49.04, 9.163 x 49.25, 9.373
    { 966975, 874 }, // 49.04, 9.373 x 49.25, 9.583
    { 966983, Bucket(3031) }, // 49.88, 8.115 x 50.09, 8.324
    { 966985, Bucket(3039) }, // 49.46, 8.324 x 49.67, 8.534
    { 966986, Bucket(3044) }, // 49.25, 8.534 x 49.46, 8.744
    { 966988, 552 }, // 49.67, 8.324 x 49.88, 8.534
    { 966989, Bucket(1034) }, // 49.88, 8.324 x 50.09, 8.534
    { 966990, Bucket(3049) }, // 49.67, 8.534 x 49.88, 8.744
    { 966991, Bucket(3053) }, // 49.88, 8.534 x 50.09, 8.744
    { 967002, Bucket(3060) }, // 50.09, 8.534 x 50.3, 8.744
    { 967013, Bucket(3035) }, // 49.88, 8.744 x 50.09, 8.953
    { 967024, Bucket(3035) }, // 50.09, 8.744 x 50.3, 8.953
    { 967071, 815 }, // 49.04, 10.21 x 49.25, 10.42
    { 967082, 3196 }, // 47.57, 11.05 x 47.78, 11.26
    { 967085, Bucket(3074) }, // 48.2, 10.84 x 48.41, 11.05
    { 967110, Bucket(3077) }, // 49.67, 9.792 x 49.88, 10
    { 967146, Bucket(3083) }, // 49.25, 11.05 x 49.46, 11.26
    { 967252, Bucket(3086) }, // 47.15, 11.26 x 47.36, 11.47
    { 967430, Bucket(3092) }, // 47.99, 11.47 x 48.2, 11.68
    { 967465, 2476 }, // 47.78, 12.52 x 47.99, 12.73
    { 967467, 2418 }, // 47.78, 12.73 x 47.99, 12.94
    { 967551, Bucket(3108) }, // 50.72, 12.73 x 50.93, 12.94
    { 967553, 2418 }, // 47.78, 12.94 x 47.99, 13.15
    { 967597, Bucket(3115) }, // 48.2, 14.2 x 48.41, 14.41
    { 967628, Bucket(3122) }, // 49.67, 13.36 x 49.88, 13.57
    { 967637, Bucket(3125) }, // 50.72, 12.94 x 50.93, 13.15
    { 967663, Bucket(3129) }, // 49.88, 14.41 x 50.09, 14.62
    { 967672, 1604 }, // 50.09, 14.2 x 50.3, 14.41
    { 967674, Bucket(3134) }, // 50.09, 14.41 x 50.3, 14.62
    { 967723, Bucket(3137) }, // 51.14, 9.373 x 51.35, 9.583
    { 967726, 1379 }, // 51.35, 9.373 x 51.56, 9.583
    { 967742, 1439 }, // 52.19, 9.373 x 52.4, 9.583
    { 967780, Bucket(3145) }, // 53.03, 8.744 x 53.24, 8.953
    { 967802, 1647 }, // 53.45, 9.373 x 53.65, 9.583
    { 967809, 2410 }, // 51.14, 9.583 x 51.35, 9.792
    { 967828, Bucket(3153) }, // 52.19, 9.583 x 52.4, 9.792
    { 967860, Bucket(3157) }, // 52.19, 10.42 x 52.4, 10.63
    { 967864, 1382 }, // 51.77, 10.84 x 51.98, 11.05
    { 967866, 1382 }, // 51.77, 11.05 x 51.98, 11.26
    { 967872, 1061 }, // 52.61, 9.583 x 52.82, 9.792
    { 967890, 1122 }, // 53.45, 9.792 x 53.65, 10
    { 967896, 1122 }, // 53.45, 10 x 53.65, 10.21
    { 968206, Bucket(3164) }, // 51.35, 11.89 x 51.56, 12.1
    { 968211, Bucket(3174) }, // 51.98, 11.47 x 52.19, 11.68
    { 968227, 3399 }, // 51.14, 12.31 x 51.35, 12.52
    { 968230, 3399 }, // 51.35, 12.31 x 51.56, 12.52
    { 968240, 186 }, // 51.77, 12.1 x 51.98, 12.31
    { 968320, 1924 }, // 50.93, 12.94 x 51.14, 13.15
    { 968321, 1080 }, // 51.14, 12.94 x 51.35, 13.15
    { 968322, 1766 }, // 50.93, 13.15 x 51.14, 13.36
    { 968324, 1080 }, // 51.35, 12.94 x 51.56, 13.15
    { 968330, Bucket(3178) }, // 50.93, 13.57 x 51.14, 13.78
    { 968349, Bucket(3189) }, // 52.4, 13.36 x 52.61, 13.57
    { 968351, 34 }, // 52.4, 13.57 x 52.61, 13.78
    { 968352, Bucket(3198) }, // 50.93, 13.78 x 51.14, 13.99
    { 968382, Bucket(3206) }, // 52.19, 14.41 x 52.4, 14.62
    { 968431, Bucket(3211) }, // 53.24, 14.41 x 53.45, 14.62
    { 968442, Bucket(3217) }, // 53.45, 14.41 x 53.65, 14.62
    { 968765, Bucket(3221) }, // 45.69, 15.87 x 45.9, 16.08
    { 968795, Bucket(3236) }, // 46.94, 15.24 x 47.15, 15.45
    { 968817, 439 }, // 46.94, 15.45 x 47.15, 15.66
    { 969006, 113 }, // 47.99, 16.08 x 48.2, 16.29
    { 969007, 3486 }, // 48.2, 16.08 x 48.41, 16.29
    { 969092, Bucket(3240) }, // 47.99, 16.29 x 48.2, 16.5
    { 969093, Bucket(3245) }, // 48.2, 16.29 x 48.41, 16.5
    { 969111, Bucket(3251) }, // 49.04, 16.5 x 49.25, 16.71
    { 969185, Bucket(3263) }, // 49.46, 17.13 x 49.67, 17.34
    { 969246, Bucket(3269) }, // 45.48, 18.6 x 45.69, 18.81
    { 969335, Bucket(3272) }, // 47.36, 19.02 x 47.57, 19.23
    { 969358, Bucket(3297) }, // 44.64, 20.28 x 44.85, 20.49
    { 969407, Bucket(3302) }, // 45.69, 21.12 x 45.9, 21.33
    { 969451, Bucket(3310) }, // 46.11, 21.12 x 46.31, 21.33
    { 969540, 1458 }, // 49.67, 17.97 x 49.88, 18.18
    { 969542, Bucket(3313) }, // 49.67, 18.18 x 49.88, 18.39
    { 969584, 1370 }, // 50.09, 18.81 x 50.3, 19.02
    { 969585, Bucket(3323) }, // 50.3, 18.81 x 50.51, 19.02
    { 969591, Bucket(3327) }, // 50.72, 19.02 x 50.93, 19.23
    { 969638, 3173 }, // 47.99, 20.7 x 48.2, 20.91
    { 969659, Bucket(3331) }, // 48.62, 21.12 x 48.83, 21.33
    { 969671, Bucket(3344) }, // 49.88, 19.86 x 50.09, 20.07
    { 969682, Bucket(3361) }, // 50.09, 19.86 x 50.3, 20.07
    { 969866, Bucket(3367) }, // 50.93, 16.92 x 51.14, 17.13
    { 969966, Bucket(3377) }, // 53.03, 17.76 x 53.24, 17.97
    { 970287, 2695 }, // 51.56, 19.44 x 51.77, 19.65
    { 970298, 2695 }, // 51.77, 19.44 x 51.98, 19.65
    { 970308, Bucket(3380) }, // 53.03, 17.97 x 53.24, 18.18
    { 970365, Bucket(3391) }, // 54.07, 19.23 x 54.28, 19.44
    { 970425, 1625 }, // 51.98, 20.91 x 52.19, 21.12
    { 970428, Bucket(3394) }, // 52.19, 20.91 x 52.4, 21.12
    { 970459, Bucket(3407) }, // 53.65, 20.28 x 53.86, 20.49
    { 970481, Bucket(3407) }, // 53.65, 20.49 x 53.86, 20.7
    { 970506, 1639 }, // 54.28, 18.6 x 54.49, 18.81
    { 970982, 1134 }, // 59.74, 10.63 x 59.95, 10.84
    { 971215, 2863 }, // 63.3, 10.21 x 63.51, 10.42
    { 971274, Bucket(3411) }, // 57.64, 11.89 x 57.85, 12.1
    { 972858, Bucket(3421) }, // 58.48, 16.08 x 58.69, 16.29
    { 972991, Bucket(3424) }, // 59.11, 17.76 x 59.32, 17.97
    { 973034, Bucket(3424) }, // 59.32, 17.76 x 59.53, 17.97
    { 973333, Bucket(3430) }, // 59.11, 17.97 x 59.32, 18.18
    { 973335, 1066 }, // 59.11, 18.18 x 59.32, 18.39
    { 973376, Bucket(3438) }, // 59.32, 17.97 x 59.53, 18.18
    { 974913, 3414 }, // 46.11, 21.33 x 46.31, 21.54
    { 974937, Bucket(3448) }, // 46.94, 21.75 x 47.15, 21.96
    { 974986, Bucket(3453) }, // 44.22, 23.63 x 44.43, 23.84
    { 975008, Bucket(3454) }, // 44.22, 23.84 x 44.43, 24.05
    { 975401, Bucket(3457) }, // 44.43, 25.94 x 44.64, 26.15
    { 975405, Bucket(3463) }, // 44.85, 25.94 x 45.06, 26.15
    { 975546, Bucket(3466) }, // 45.06, 27.83 x 45.27, 28.04
    { 976370, Bucket(3469) }, // 56.8, 24.05 x 57.01, 24.26
    { 977371, Bucket(3472) }, // 50.3, 30.34 x 50.51, 30.55
    { 977393, Bucket(3477) }, // 50.3, 30.55 x 50.51, 30.76
    { 977795, Bucket(3480) }, // 47.78, 33.28 x 47.99, 33.49
    { 977850, Bucket(3496) }, // 48.41, 34.54 x 48.62, 34.75
    { 978328, Bucket(3499) }, // 55.12, 30.13 x 55.33, 30.34
    { 979342, 3326 }, // 61.41, 23.63 x 61.62, 23.84
    { 979520, Bucket(3502) }, // 59.32, 24.68 x 59.53, 24.89
    { 981196, Bucket(3507) }, // 59.74, 30.13 x 59.95, 30.34
    { 981197, Bucket(3510) }, // 59.95, 30.13 x 60.16, 30.34
    { 981198, Bucket(3514) }, // 59.74, 30.34 x 59.95, 30.55
    { 2226005, 2444 }, // 17.16, 78.37 x 17.37, 78.58
    { 2314234, 2335 }, // 3.114, 101.6 x 3.323, 101.9
    { 2317681, 2562 }, // 16.75, 95.99 x 16.95, 96.19
    { 2318038, 2326 }, // 13.6, 100.4 x 13.81, 100.6
    { 2318975, Bucket(3524) }, // -6.324, 106.7 x -6.114, 106.9
    { 2319061, 3696 }, // -6.324, 106.9 x -6.114, 107.1
    { 2319751, Bucket(3527) }, // 1.226, 103.7 x 1.436, 104
    { 2336958, Bucket(3530) }, // -35.05, 138.6 x -34.84, 138.8
    { 2337002, Bucket(3533) }, // -34.64, 138.6 x -34.43, 138.8
    { 2348942, 2334 }, // 14.44, 120.9 x 14.65, 121.2
    { 2348943, 2569 }, // 14.65, 120.9 x 14.86, 121.2
    { 2363737, 2177 }, // 36.88, 35.17 x 37.09, 35.38
    { 2363889, Bucket(3536) }, // 36.88, 37.26 x 37.09, 37.47
    { 2363892, 3618 }, // 37.09, 37.26 x 37.3, 37.47
    { 2364718, 3608 }, // 41.28, 36.22 x 41.49, 36.43
    { 2366712, 2313 }, // 40.02, 44.4 x 40.23, 44.6
    { 2366847, Bucket(3539) }, // 44.01, 42.93 x 44.22, 43.14
    { 2368699, 2916 }, // 25.13, 51.32 x 25.34, 51.53
    { 2370578, 3332 }, // 24.92, 55.09 x 25.13, 55.3
    { 2372031, Bucket(3546) }, // 35.62, 51.32 x 35.83, 51.53
    { 2372373, 2170 }, // 35.62, 51.53 x 35.83, 51.74
    { 2372817, Bucket(3550) }, // 40.23, 49.85 x 40.44, 50.06
    { 2374508, 1682 }, // 36.25, 59.49 x 36.46, 59.7
    { 2375923, Bucket(3553) }, // 46.94, 37.47 x 47.15, 37.68
    { 2375926, Bucket(3560) }, // 47.15, 37.47 x 47.36, 37.68
    { 2375954, Bucket(3564) }, // 48.41, 34.96 x 48.62, 35.17
    { 2376047, 667 }, // 49.88, 36.22 x 50.09, 36.43
    { 2376286, Bucket(3568) }, // 47.15, 38.73 x 47.36, 38.94
    { 2377139, 584 }, // 55.33, 37.47 x 55.54, 37.68
    { 2377142, Bucket(3572) }, // 55.54, 37.47 x 55.75, 37.68
    { 2377143, 515 }, // 55.75, 37.47 x 55.96, 37.68
    { 2378169, Bucket(3578) }, // 48.62, 44.4 x 48.83, 44.6
    { 2379211, Bucket(3582) }, // 56.17, 43.77 x 56.38, 43.98
    { 2379233, Bucket(3593) }, // 56.17, 43.98 x 56.38, 44.19
    { 2385205, Bucket(3598) }, // 55.75, 49.01 x 55.96, 49.22
    { 2385716, 3374 }, // 55.54, 52.36 x 55.75, 52.57
    { 2387535, Bucket(3601) }, // 53.24, 58.87 x 53.45, 59.08
    { 2387546, Bucket(3624) }, // 53.45, 58.87 x 53.65, 59.08
    { 2387919, Bucket(3633) }, // 56.59, 60.54 x 56.8, 60.75
    { 2387930, Bucket(3636) }, // 56.8, 60.54 x 57.01, 60.75
    { 2394685, 3136 }, // 18.84, 72.92 x 19.05, 73.13
    { 2394722, Bucket(3644) }, // 19.05, 72.71 x 19.26, 72.92
    { 2394728, 3136 }, // 19.05, 72.92 x 19.26, 73.13
    { 2394777, Bucket(3647) }, // 18.42, 73.76 x 18.63, 73.97
    { 2399524, 938 }, // 41.28, 69.14 x 41.49, 69.35
    { 2400768, Bucket(3650) }, // 17.37, 78.37 x 17.58, 78.58
    { 2401371, 2325 }, // 26.81, 75.64 x 27.02, 75.85
    { 2401532, 3819 }, // 27.02, 77.95 x 27.23, 78.16
    { 2401683, 2389 }, // 28.49, 76.9 x 28.7, 77.11
    { 2403306, Bucket(3653) }, // 22.41, 88.23 x 22.62, 88.44
    { 2420007, 2089 }, // 54.91, 82.77 x 55.12, 82.98
    { 2420206, Bucket(3656) }, // 56.38, 84.87 x 56.59, 85.08
    { 2490838, 3594 }, // 23.67, 90.32 x 23.88, 90.53
    { 2499337, 3230 }, // 20.94, 105.6 x 21.15, 105.8
    { 2499632, 2256 }, // 24.92, 102.7 x 25.13, 102.9
    { 2500061, 2441 }, // 30.59, 104 x 30.8, 104.2
    { 2501476, 2960 }, // 22.83, 112.8 x 23.04, 113
    { 2501484, 3476 }, // 22.83, 113.2 x 23.04, 113.4
    { 2501485, Bucket(3661) }, // 23.04, 113.2 x 23.25, 113.4
    { 2501487, Bucket(3665) }, // 23.04, 113.4 x 23.25, 113.6
    { 2501533, Bucket(3668) }, // 22.2, 114 x 22.41, 114.2
    { 2501570, 3368 }, // 22.41, 113.8 x 22.62, 114
    { 2501571, 2064 }, // 22.62, 113.8 x 22.83, 114
    { 2501576, Bucket(3671) }, // 22.41, 114 x 22.62, 114.2
    { 2502620, 3473 }, // 30.38, 114 x 30.59, 114.2
    { 2502622, 3228 }, // 30.38, 114.2 x 30.59, 114.4
    { 2502644, 3228 }, // 30.38, 114.4 x 30.59, 114.6
    { 2502792, 2963 }, // 30.8, 104 x 31.01, 104.2
    { 2505431, 3341 }, // 33.94, 113.8 x 34.15, 114
    { 2505484, 3433 }, // 34.57, 112.3 x 34.78, 112.6
    { 2505518, Bucket(3674) }, // 34.57, 113.4 x 34.78, 113.6
    { 2506404, 3166 }, // 37.93, 114.4 x 38.14, 114.6
    { 2516119, Bucket(3677) }, // 52.4, 103.7 x 52.61, 104
    { 2516126, Bucket(3682) }, // 52.19, 104.2 x 52.4, 104.4
    { 2524747, Bucket(3687) }, // 25.97, 119.3 x 26.18, 119.5
    { 2524802, 1459 }, // 24.09, 120.5 x 24.29, 120.7
    { 2524850, Bucket(3690) }, // 24.92, 121.4 x 25.13, 121.6
    { 2525051, 3421 }, // 30.17, 120.1 x 30.38, 120.3
    { 2525137, Bucket(3693) }, // 30.17, 120.3 x 30.38, 120.5
    { 2525138, 3701 }, // 29.96, 120.5 x 30.17, 120.7
    { 2527419, 2259 }, // 31.84, 118.4 x 32.05, 118.6
    { 2527618, 3344 }, // 34.15, 117.2 x 34.36, 117.4
    { 2527751, 2665 }, // 31.43, 118.8 x 31.63, 119.1
    { 2527761, 2259 }, // 31.84, 118.6 x 32.05, 118.8
    { 2527762, 2665 }, // 31.63, 118.8 x 31.84, 119.1
    { 2527791, Bucket(3696) }, // 31.43, 120.1 x 31.63, 120.3
    { 2527800, Bucket(3700) }, // 31.63, 119.9 x 31.84, 120.1
    { 2527875, 2489 }, // 31.01, 120.5 x 31.22, 120.7
    { 2527876, Bucket(3703) }, // 31.22, 120.3 x 31.43, 120.5
    { 2527877, Bucket(3706) }, // 31.43, 120.3 x 31.63, 120.5
    { 2527878, Bucket(3711) }, // 31.22, 120.5 x 31.43, 120.7
    { 2527879, 2490 }, // 31.43, 120.5 x 31.63, 120.7
    { 2527884, Bucket(3703) }, // 31.22, 120.7 x 31.43, 120.9
    { 2527905, 2647 }, // 31.01, 121.2 x 31.22, 121.4
    { 2528107, 2233 }, // 36.04, 120.1 x 36.25, 120.3
    { 2528193, Bucket(3716) }, // 36.04, 120.3 x 36.25, 120.5
    { 2528334, 2499 }, // 39.6, 115.9 x 39.81, 116.1
    { 2528357, Bucket(3719) }, // 39.81, 116.1 x 40.02, 116.3
    { 2528359, 390 }, // 39.81, 116.3 x 40.02, 116.5
    { 2528407, Bucket(3722) }, // 38.97, 117.2 x 39.18, 117.4
    { 2528415, 2521 }, // 38.97, 117.6 x 39.18, 117.8
    { 2530173, Bucket(3726) }, // 37.3, 126.6 x 37.51, 126.8
    { 2530175, 2018 }, // 37.3, 126.8 x 37.51, 127
    { 2530260, 2001 }, // 37.09, 127 x 37.3, 127.2
    { 2530261, 2262 }, // 37.3, 127 x 37.51, 127.2
    { 2530704, 3837 }, // 41.7, 123.7 x 41.91, 123.9
    { 2530814, 2722 }, // 43.8, 125.1 x 44.01, 125.3
    { 2530839, 3115 }, // 38.97, 125.6 x 39.18, 125.8
    { 2530856, Bucket(3729) }, // 37.51, 126.6 x 37.72, 126.8
    { 2530858, Bucket(3733) }, // 37.51, 126.8 x 37.72, 127
    { 2530944, Bucket(3737) }, // 37.51, 127 x 37.72, 127.2
    { 2535619, Bucket(3741) }, // 32.68, 130.6 x 32.89, 130.8
    { 2535633, 2044 }, // 33.52, 130.4 x 33.73, 130.6
    { 2535638, 3224 }, // 33.73, 130.6 x 33.94, 130.8
    { 2536030, Bucket(3744) }, // 33.73, 132.7 x 33.94, 132.9
    { 2536195, 2043 }, // 34.36, 132.3 x 34.57, 132.5
    { 2536201, 2043 }, // 34.36, 132.5 x 34.57, 132.7
    { 2536364, Bucket(3748) }, // 34.57, 135 x 34.78, 135.2
    { 2537732, Bucket(3752) }, // 34.57, 135.4 x 34.78, 135.6
    { 2537735, 2372 }, // 34.78, 135.6 x 34.99, 135.8
    { 2537746, Bucket(3759) }, // 34.99, 135.6 x 35.2, 135.8
    { 2537786, 2375 }, // 34.99, 136.9 x 35.2, 137.1
    { 2538267, 2645 }, // 35.2, 139.4 x 35.41, 139.6
    { 2538292, Bucket(3763) }, // 35.41, 139.6 x 35.62, 139.8
    { 2538293, Bucket(3766) }, // 35.62, 139.6 x 35.83, 139.8
    { 2538314, 2614 }, // 35.83, 139.4 x 36.04, 139.6
    { 2538336, 2614 }, // 35.83, 139.6 x 36.04, 139.8
    { 2539149, 2077 }, // 38.14, 140.9 x 38.35, 141.1
    { 2539410, Bucket(3773) }, // 41.7, 140.7 x 41.91, 140.9
    { 2539492, 2340 }, // 42.96, 141.3 x 43.17, 141.5
    { 2643426, Bucket(3776) }, // -37.99, 144.8 x -37.78, 145.1
    { 2676426, Bucket(3782) }, // -41.35, 174.6 x -41.14, 174.8
    { 2676448, 471 }, // -41.35, 174.8 x -41.14, 175
    { 2689229, 2738 }, // -34.01, 150.9 x -33.8, 151.1
    { 2689231, Bucket(3785) }, // -34.01, 151.1 x -33.8, 151.4
    { 2690615, 3748 }, // -28.13, 153.2 x -27.92, 153.4
    { 2690638, Bucket(3788) }, // -27.5, 152.8 x -27.3, 153
    { 2690660, Bucket(3788) }, // -27.5, 153 x -27.3, 153.2
    { 1028415, 3661 }, // -0.3468, -78.6 x -0.2419, -78.5
    { 1028458, 3661 }, // -0.2419, -78.6 x -0.137, -78.5
    { 1028501, 3661 }, // -0.3468, -78.5 x -0.2419, -78.39
    { 1028544, 3661 }, // -0.2419, -78.5 x -0.137, -78.39
    { 1042715, 1130 }, // 6.154, -75.67 x 6.259, -75.56
    { 1597918, 3547 }, // 33.94, -118.4 x 34.05, -118.3
    { 1597940, 3547 }, // 33.94, -118.3 x 34.05, -118.2
    { 1620607, Bucket(3791) }, // 25.66, -100.4 x 25.76, -100.3
    { 1620693, Bucket(3791) }, // 25.66, -100.3 x 25.76, -100.2
    { 1622465, 1466 }, // 33.42, -112.1 x 33.52, -111.9
    { 1626582, 2542 }, // 40.65, -111.9 x 40.76, -111.8
    { 1634715, 2533 }, // 39.71, -105 x 39.81, -104.9
    { 1639162, 207 }, // 45.48, -123.1 x 45.58, -123
    { 1640536, Bucket(3795) }, // 45.48, -122.7 x 45.58, -122.6
    { 1641514, 2858 }, // 47.57, -122.2 x 47.68, -122.1
    { 1653704, 3762 }, // 53.45, -113.5 x 53.55, -113.4
    { 1718167, Bucket(3799) }, // 29.85, -90.14 x 29.96, -90.03
    { 1718210, Bucket(3802) }, // 29.96, -90.14 x 30.06, -90.03
    { 1735915, 1050 }, // 41.81, -87.83 x 41.91, -87.73
    { 1735916, 2488 }, // 41.91, -87.94 x 42.02, -87.83
    { 1736257, 1050 }, // 41.81, -87.73 x 41.91, -87.62
    { 1736261, 1013 }, // 42.02, -87.73 x 42.12, -87.62
    { 1743890, 3069 }, // 27.86, -82.59 x 27.96, -82.48
    { 1743891, 3069 }, // 27.96, -82.59 x 28.07, -82.48
    { 1753594, Bucket(3805) }, // 33.73, -84.47 x 33.84, -84.37
    { 1753936, 1442 }, // 33.73, -84.37 x 33.84, -84.27
    { 1756742, 3229 }, // 35.2, -80.91 x 35.3, -80.8
    { 1758961, 3279 }, // 42.23, -83.11 x 42.33, -83.01
    { 1758964, 3279 }, // 42.33, -83.11 x 42.44, -83.01
    { 1761262, Bucket(3808) }, // 43.59, -79.44 x 43.69, -79.34
    { 1761263, 240 }, // 43.69, -79.44 x 43.8, -79.34
    { 1766103, 2845 }, // 39.08, -76.72 x 39.18, -76.61
    { 1766693, 3114 }, // 42.85, -78.92 x 42.96, -78.81
    { 1766724, Bucket(3812) }, // 43.59, -79.34 x 43.69, -79.23
    { 1767743, Bucket(3815) }, // 39.92, -75.25 x 40.02, -75.14
    { 1767786, Bucket(3823) }, // 40.02, -75.25 x 40.13, -75.14
    { 1767829, Bucket(3827) }, // 39.92, -75.14 x 40.02, -75.04
    { 1767872, 525 }, // 40.02, -75.14 x 40.13, -75.04
    { 1768305, 2247 }, // 40.55, -73.88 x 40.65, -73.78
    { 1813112, 1215 }, // 45.48, -73.67 x 45.58, -73.57
    { 2372011, 3383 }, // -27.82, -64.34 x -27.71, -64.24
    { 2392191, Bucket(3830) }, // -34.74, -58.47 x -34.64, -58.37
    { 2392362, Bucket(3833) }, // -34.64, -58.47 x -34.53, -58.37
    { 2408299, 1325 }, // -23.63, -46.73 x -23.52, -46.62
    { 2408345, 1926 }, // -24.04, -46.41 x -23.94, -46.31
    { 2408385, 1325 }, // -23.63, -46.62 x -23.52, -46.52
    { 2442711, 2096 }, // 10.56, -71.68 x 10.66, -71.58
    { 2444773, 2036 }, // 10.14, -68.01 x 10.24, -67.91
    { 2496469, Bucket(3836) }, // -23, -43.27 x -22.89, -43.16
    { 2507278, 2839 }, // -22.68, -43.79 x -22.58, -43.69
    { 2507300, 2839 }, // -22.68, -43.69 x -22.58, -43.58
    { 2557665, 2991 }, // -5.17, -42.85 x -5.065, -42.74
    { 3007285, 3656 }, // 6.364, 3.291 x 6.469, 3.396
    { 3007328, 3656 }, // 6.469, 3.291 x 6.574, 3.396
    { 3055274, 3034 }, // -26.25, 27.93 x -26.14, 28.04
    { 3060053, 3033 }, // -26.35, 28.04 x -26.25, 28.14
    { 3060736, 3032 }, // -26.25, 28.04 x -26.14, 28.14
    { 3167481, 3111 }, // 42.23, -71.16 x 42.33, -71.05
    { 3167484, 3113 }, // 42.33, -71.16 x 42.44, -71.05
    { 3698582, 3146 }, // 36.46, -6.251 x 36.56, -6.146
    { 3698654, 124 }, // 37.3, -6.041 x 37.4, -5.936
    { 3699431, Bucket(3839) }, // 38.66, -9.187 x 38.77, -9.082
    { 3699442, 2101 }, // 38.77, -9.187 x 38.87, -9.082
    { 3723759, 2200 }, // 40.34, -3.944 x 40.44, -3.839
    { 3723780, 2316 }, // 37.72, -3.839 x 37.82, -3.734
    { 3724101, Bucket(3845) }, // 40.34, -3.839 x 40.44, -3.734
    { 3724103, Bucket(3848) }, // 40.34, -3.734 x 40.44, -3.63
    { 3724112, 2199 }, // 40.44, -3.839 x 40.55, -3.734
    { 3724114, Bucket(3851) }, // 40.44, -3.734 x 40.55, -3.63
    { 3724778, 1383 }, // 43.38, -3.944 x 43.48, -3.839
    { 3725120, 3201 }, // 43.38, -3.839 x 43.48, -3.734
    { 3725204, 2546 }, // 43.17, -3 x 43.27, -2.896
    { 3725205, 3307 }, // 43.27, -3 x 43.38, -2.896
    { 3725248, 1905 }, // 43.38, -3 x 43.48, -2.896
    { 3725458, 2279 }, // 37.93, -1.218 x 38.03, -1.113
    { 3725546, 287 }, // 38.35, -0.5886 x 38.45, -0.4838
    { 3725845, 3365 }, // 38.24, -0.4838 x 38.35, -0.3789
    { 3725888, Bucket(3854) }, // 38.35, -0.4838 x 38.45, -0.3789
    { 3726086, Bucket(3858) }, // 39.39, -0.3789 x 39.5, -0.2741
    { 3726495, 475 }, // 41.6, -1.008 x 41.7, -0.9032
    { 3726517, 475 }, // 41.6, -0.9032 x 41.7, -0.7984
    { 3727022, 1718 }, // 41.07, 1.089 x 41.18, 1.194
    { 3732484, 1718 }, // 41.07, 1.194 x 41.18, 1.299
    { 3732501, 3804 }, // 41.6, 1.194 x 41.7, 1.299
    { 3732624, 1739 }, // 41.28, 2.033 x 41.39, 2.138
    { 3732627, Bucket(3861) }, // 41.39, 2.138 x 41.49, 2.243
    { 3733446, 3509 }, // 43.59, 3.815 x 43.69, 3.92
    { 3734847, 263 }, // 43.27, 5.283 x 43.38, 5.388
    { 3734873, 2872 }, // 43.9, 4.759 x 44.01, 4.864
    { 3734933, Bucket(3867) }, // 43.27, 5.388 x 43.38, 5.493
    { 3770738, 806 }, // 47.15, -1.637 x 47.26, -1.532
    { 3771949, Bucket(3870) }, // 47.89, 0.1454 x 47.99, 0.2502
    { 3771960, Bucket(3870) }, // 47.99, 0.1454 x 48.1, 0.2502
    { 3771991, Bucket(3873) }, // 49.15, -0.3789 x 49.25, -0.2741
    { 3772198, 1312 }, // 49.46, 0.0405 x 49.57, 0.1454
    { 3773416, 3077 }, // 53.45, -2.371 x 53.55, -2.266
    { 3773663, 1798 }, // 55.86, -4.364 x 55.96, -4.259
    { 3774784, Bucket(3876) }, // 53.45, -2.162 x 53.55, -2.057
    { 3775003, Bucket(3879) }, // 51.45, -0.1692 x 51.56, -0.06436
    { 3775025, Bucket(3882) }, // 51.45, -0.06436 x 51.56, 0.0405
    { 3777261, Bucket(3885) }, // 45.37, 4.34 x 45.48, 4.445
    { 3777272, 408 }, // 45.48, 4.34 x 45.58, 4.445
    { 3777741, 3501 }, // 48.73, 2.243 x 48.83, 2.347
    { 3777743, 3316 }, // 48.73, 2.347 x 48.83, 2.452
    { 3777754, Bucket(3889) }, // 48.83, 2.347 x 48.94, 2.452
    { 3778551, 2523 }, // 50.82, 4.235 x 50.93, 4.34
    { 3778557, 2330 }, // 50.82, 4.34 x 50.93, 4.445
    { 3778652, 1332 }, // 45.69, 4.759 x 45.79, 4.864
    { 3778654, 1025 }, // 45.69, 4.864 x 45.79, 4.969
    { 3778763, 1360 }, // 45.16, 5.703 x 45.27, 5.808
    { 3778990, Bucket(3892) }, // 46.11, 6.122 x 46.21, 6.227
    { 3779255, Bucket(3895) }, // 44.95, 7.59 x 45.06, 7.695
    { 3779298, Bucket(3898) }, // 45.06, 7.59 x 45.16, 7.695
    { 3779531, 1386 }, // 46.84, 7.381 x 46.94, 7.485
    { 3779533, 3832 }, // 47.05, 7.276 x 47.15, 7.381
    { 3779534, 1386 }, // 46.94, 7.381 x 47.05, 7.485
    { 3779553, 1376 }, // 46.84, 7.485 x 46.94, 7.59
    { 3779556, 1376 }, // 46.94, 7.485 x 47.05, 7.59
    { 3779571, 3616 }, // 47.26, 7.59 x 47.36, 7.695
    { 3779575, 3153 }, // 47.47, 7.59 x 47.57, 7.695
    { 3779577, 3616 }, // 47.26, 7.695 x 47.36, 7.8
    { 3779822, 779 }, // 48.62, 6.122 x 48.73, 6.227
    { 3780233, Bucket(3902) }, // 47.68, 7.276 x 47.78, 7.381
    { 3780271, Bucket(3905) }, // 47.89, 7.8 x 47.99, 7.905
    { 3780282, Bucket(3908) }, // 47.99, 7.8 x 48.1, 7.905
    { 3780329, Bucket(3912) }, // 48.52, 7.695 x 48.62, 7.8
    { 3780564, 131 }, // 50.72, 7.066 x 50.82, 7.171
    { 3781292, 1281 }, // 51.14, 4.34 x 51.24, 4.445
    { 3781350, 1776 }, // 51.98, 4.235 x 52.08, 4.34
    { 3781355, Bucket(3916) }, // 51.87, 4.445 x 51.98, 4.549
    { 3782721, Bucket(3921) }, // 51.87, 4.549 x 51.98, 4.654
    { 3782745, 3758 }, // 52.29, 4.759 x 52.4, 4.864
    { 3782747, Bucket(3925) }, // 52.29, 4.864 x 52.4, 4.969
    { 3783183, Bucket(3931) }, // 51.24, 6.542 x 51.35, 6.647
    { 3783194, Bucket(3931) }, // 51.35, 6.542 x 51.45, 6.647
    { 3783208, Bucket(3934) }, // 50.93, 6.856 x 51.03, 6.961
    { 3783323, Bucket(3937) }, // 51.45, 7.381 x 51.56, 7.485
    { 3819363, Bucket(3942) }, // 36.77, 10.11 x 36.88, 10.21
    { 3821962, 1587 }, // 39.18, 9.058 x 39.29, 9.163
    { 3823599, Bucket(3946) }, // 43.69, 11.16 x 43.8, 11.26
    { 3823610, Bucket(3946) }, // 43.8, 11.16 x 43.9, 11.26
    { 3823615, 1656 }, // 44.11, 11.16 x 44.22, 11.26
    { 3824155, Bucket(3949) }, // 38.03, 13.25 x 38.14, 13.36
    { 3824177, 1707 }, // 38.03, 13.36 x 38.14, 13.46
    { 3824629, Bucket(3952) }, // 40.76, 14.2 x 40.86, 14.3
    { 3824843, 826 }, // 41.81, 12.41 x 41.91, 12.52
    { 3824846, 824 }, // 41.91, 12.41 x 42.02, 12.52
    { 3824865, 833 }, // 41.81, 12.52 x 41.91, 12.62
    { 3824981, 1654 }, // 44.11, 11.26 x 44.22, 11.37
    { 3825312, 3289 }, // 40.86, 14.2 x 40.97, 14.3
    { 3829792, 2037 }, // 37.51, 15.04 x 37.61, 15.14
    { 3830101, 3695 }, // 40.76, 14.62 x 40.86, 14.72
    { 3830784, 3776 }, // 40.86, 14.62 x 40.97, 14.72
    { 3833178, 2622 }, // 43.8, 18.29 x 43.9, 18.39
    { 3833200, 2622 }, // 43.8, 18.39 x 43.9, 18.5
    { 3854843, Bucket(3955) }, // 40.55, 22.9 x 40.65, 23
    { 3856139, Bucket(3958) }, // 42.64, 23.32 x 42.75, 23.42
    { 3857001, 3798 }, // 38.45, 26.99 x 38.56, 27.09
    { 3860419, 3220 }, // 36.77, 30.66 x 36.88, 30.76
    { 3860422, 3220 }, // 36.88, 30.66 x 36.98, 30.76
    { 3863355, Bucket(3961) }, // 39.71, 30.45 x 39.81, 30.55
    { 3863441, Bucket(3966) }, // 39.71, 30.55 x 39.81, 30.66
    { 3863595, Bucket(3970) }, // 40.97, 28.77 x 41.07, 28.88
    { 3863681, 2068 }, // 40.97, 28.88 x 41.07, 28.98
    { 3863686, 2070 }, // 41.07, 28.98 x 41.18, 29.09
    { 3866853, Bucket(3973) }, // 45.37, 9.163 x 45.48, 9.268
    { 3866864, Bucket(3979) }, // 45.48, 9.163 x 45.58, 9.268
    { 3866968, 236 }, // 47.15, 8.115 x 47.26, 8.219
    { 3866971, 591 }, // 47.26, 8.219 x 47.36, 8.324
    { 3866975, 2458 }, // 47.47, 8.219 x 47.57, 8.324
    { 3866993, 2784 }, // 47.26, 8.324 x 47.36, 8.429
    { 3866994, 2474 }, // 47.15, 8.429 x 47.26, 8.534
    { 3866995, 2474 }, // 47.26, 8.429 x 47.36, 8.534
    { 3866996, 2784 }, // 47.36, 8.324 x 47.47, 8.429
    { 3867004, Bucket(3984) }, // 47.36, 8.534 x 47.47, 8.639
    { 3867007, Bucket(3987) }, // 47.47, 8.639 x 47.57, 8.744
    { 3867089, 1839 }, // 47.26, 8.744 x 47.36, 8.849
    { 3867092, Bucket(3990) }, // 47.36, 8.744 x 47.47, 8.849
    { 3867093, 2460 }, // 47.47, 8.744 x 47.57, 8.849
    { 3867096, 3048 }, // 47.15, 8.953 x 47.26, 9.058
    { 3867097, 3048 }, // 47.26, 8.953 x 47.36, 9.058
    { 3867100, 3048 }, // 47.36, 8.953 x 47.47, 9.058
    { 3867103, Bucket(3993) }, // 47.47, 9.058 x 47.57, 9.163
    { 3867126, 3132 }, // 47.36, 9.268 x 47.47, 9.373
    { 3867130, 3787 }, // 47.15, 9.478 x 47.26, 9.583
    { 3867256, 1083 }, // 45.48, 10.21 x 45.58, 10.32
    { 3867460, 3672 }, // 46.94, 9.583 x 47.05, 9.687
    { 3867461, 3090 }, // 47.05, 9.583 x 47.15, 9.687
    { 3867463, 3090 }, // 47.05, 9.687 x 47.15, 9.792
    { 3867472, 3787 }, // 47.15, 9.583 x 47.26, 9.687
    { 3867658, 2458 }, // 47.57, 8.219 x 47.68, 8.324
    { 3867690, 2484 }, // 47.57, 8.639 x 47.68, 8.744
    { 3867763, 26 }, // 48.94, 8.429 x 49.04, 8.534
    { 3867772, 1432 }, // 49.04, 8.534 x 49.15, 8.639
    { 3867775, 500 }, // 49.15, 8.639 x 49.25, 8.744
    { 3867855, Bucket(3997) }, // 48.73, 9.058 x 48.83, 9.163
    { 3867865, 874 }, // 48.94, 8.953 x 49.04, 9.058
    { 3867866, 198 }, // 48.83, 9.058 x 48.94, 9.163
    { 3867877, Bucket(4000) }, // 48.73, 9.163 x 48.83, 9.268
    { 3867888, Bucket(4005) }, // 48.83, 9.163 x 48.94, 9.268
    { 3867890, 198 }, // 48.83, 9.268 x 48.94, 9.373
    { 3867896, 198 }, // 48.83, 9.373 x 48.94, 9.478
    { 3867935, 1273 }, // 49.98, 8.219 x 50.09, 8.324
    { 3867942, 3743 }, // 49.46, 8.429 x 49.57, 8.534
    { 3867947, Bucket(4008) }, // 49.36, 8.639 x 49.46, 8.744
    { 3867954, 3741 }, // 49.67, 8.429 x 49.78, 8.534
    { 3867963, 1612 }, // 49.78, 8.639 x 49.88, 8.744
    { 3867967, 711 }, // 49.98, 8.639 x 50.09, 8.744
    { 3868010, Bucket(4011) }, // 50.09, 8.639 x 50.19, 8.744
    { 3868053, 1273 }, // 49.98, 8.744 x 50.09, 8.849
    { 3868096, Bucket(4016) }, // 50.09, 8.744 x 50.19, 8.849
    { 3868191, 1912 }, // 48.31, 9.897 x 48.41, 10
    { 3868234, 1912 }, // 48.41, 9.897 x 48.52, 10
    { 3868319, 417 }, // 48.31, 10.74 x 48.41, 10.84
    { 3868341, Bucket(4020) }, // 48.31, 10.84 x 48.41, 10.95
    { 3868585, Bucket(4026) }, // 49.36, 11.05 x 49.46, 11.16
    { 3868637, 951 }, // 50.82, 10.63 x 50.93, 10.74
    { 3868676, 1657 }, // 44.43, 11.26 x 44.53, 11.37
    { 3869010, 235 }, // 47.15, 11.37 x 47.26, 11.47
    { 3869721, Bucket(4029) }, // 48.1, 11.47 x 48.2, 11.57
    { 3869723, 3448 }, // 48.1, 11.57 x 48.2, 11.68
    { 3869824, 3196 }, // 47.57, 12.1 x 47.68, 12.2
    { 3869871, 2415 }, // 47.89, 12.83 x 47.99, 12.94
    { 3869882, 2415 }, // 47.99, 12.83 x 48.1, 12.94
    { 3869953, 232 }, // 49.36, 11.26 x 49.46, 11.37
    { 3870047, Bucket(4033) }, // 50.82, 11.57 x 50.93, 11.68
    { 3870079, Bucket(4036) }, // 50.82, 11.99 x 50.93, 12.1
    { 3870149, Bucket(4039) }, // 50.4, 12.1 x 50.51, 12.2
    { 3870160, Bucket(4039) }, // 50.51, 12.1 x 50.61, 12.2
    { 3870165, 233 }, // 50.82, 12.1 x 50.93, 12.2
    { 3870171, 1655 }, // 50.61, 12.41 x 50.72, 12.52
    { 3870174, 1655 }, // 50.72, 12.41 x 50.82, 12.52
    { 3870653, Bucket(4044) }, // 49.98, 14.41 x 50.09, 14.51
    { 3870696, Bucket(4050) }, // 50.09, 14.41 x 50.19, 14.51
    { 3870709, 1764 }, // 50.82, 14.2 x 50.93, 14.3
    { 3870822, 791 }, // 51.98, 8.429 x 52.08, 8.534
    { 3870828, 791 }, // 51.98, 8.534 x 52.08, 8.639
    { 3870893, 2414 }, // 51.24, 9.373 x 51.35, 9.478
    { 3871034, 436 }, // 53.03, 8.639 x 53.13, 8.744
    { 3871120, Bucket(4055) }, // 53.03, 8.744 x 53.13, 8.849
    { 3871315, Bucket(4058) }, // 52.29, 9.687 x 52.4, 9.792
    { 3871368, Bucket(4061) }, // 50.93, 10.63 x 51.03, 10.74
    { 3871387, Bucket(4064) }, // 51.45, 10.74 x 51.56, 10.84
    { 3871394, Bucket(4067) }, // 50.93, 10.95 x 51.03, 11.05
    { 3872366, 2781 }, // 55.33, 10.32 x 55.44, 10.42
    { 3872452, 2781 }, // 55.33, 10.42 x 55.44, 10.53
    { 3872825, Bucket(4071) }, // 51.45, 11.89 x 51.56, 11.99
    { 3872847, Bucket(4076) }, // 52.08, 11.57 x 52.19, 11.68
    { 3872909, Bucket(4082) }, // 51.24, 12.31 x 51.35, 12.41
    { 3872938, 1923 }, // 50.93, 12.83 x 51.03, 12.94
    { 3872962, 1423 }, // 51.77, 12.2 x 51.87, 12.31
    { 3873091, 157 }, // 53.55, 11.37 x 53.65, 11.47
    { 3873150, Bucket(4085) }, // 54.07, 11.99 x 54.18, 12.1
    { 3873236, Bucket(4088) }, // 54.07, 12.1 x 54.18, 12.2
    { 3873280, 1923 }, // 50.93, 12.94 x 51.03, 13.04
    { 3873323, Bucket(4092) }, // 51.03, 13.67 x 51.14, 13.78
    { 3873397, Bucket(4095) }, // 52.5, 13.36 x 52.61, 13.46
    { 3873406, 859 }, // 52.4, 13.67 x 52.5, 13.78
    { 3873463, 596 }, // 51.66, 14.3 x 51.77, 14.41
    { 3873493, 229 }, // 52.5, 13.78 x 52.61, 13.88
    { 3873727, Bucket(4098) }, // 53.34, 14.51 x 53.45, 14.62
    { 3873770, Bucket(4103) }, // 53.45, 14.51 x 53.55, 14.62
    { 3874011, 375 }, // 55.65, 12.41 x 55.75, 12.52
    { 3874014, 2865 }, // 55.75, 12.41 x 55.86, 12.52
    { 3874033, Bucket(4107) }, // 55.65, 12.52 x 55.75, 12.62
    { 3874036, 2865 }, // 55.75, 12.52 x 55.86, 12.62
    { 3874393, 3238 }, // 55.65, 13.15 x 55.75, 13.25
    { 3875061, 1681 }, // 45.79, 15.87 x 45.9, 15.98
    { 3875063, 1681 }, // 45.79, 15.98 x 45.9, 16.08
    { 3875183, Bucket(4111) }, // 47.05, 15.35 x 47.15, 15.45
    { 3875269, Bucket(4115) }, // 47.05, 15.45 x 47.15, 15.56
    { 3876027, 78 }, // 48.1, 16.19 x 48.2, 16.29
    { 3876190, Bucket(4118) }, // 50.72, 14.93 x 50.82, 15.04
    { 3876212, Bucket(4121) }, // 50.72, 15.04 x 50.82, 15.14
    { 3876369, Bucket(4126) }, // 48.1, 16.29 x 48.2, 16.4
    { 3876372, Bucket(4129) }, // 48.2, 16.29 x 48.31, 16.4
    { 3876411, Bucket(4138) }, // 48.1, 17.03 x 48.2, 17.13
    { 3876497, Bucket(4139) }, // 48.1, 17.13 x 48.2, 17.24
    { 3876783, Bucket(4142) }, // 49.57, 17.87 x 49.67, 17.97
    { 3876794, 3580 }, // 49.67, 17.87 x 49.78, 17.97
    { 3877340, 617 }, // 47.36, 19.02 x 47.47, 19.12
    { 3877341, Bucket(4145) }, // 47.47, 19.02 x 47.57, 19.12
    { 3877342, 608 }, // 47.36, 19.12 x 47.47, 19.23
    { 3877435, Bucket(4153) }, // 44.74, 20.38 x 44.85, 20.49
    { 3877521, Bucket(4159) }, // 44.74, 20.49 x 44.85, 20.59
    { 3877669, Bucket(4165) }, // 46.21, 20.07 x 46.31, 20.17
    { 3877806, Bucket(4171) }, // 46.11, 21.22 x 46.21, 21.33
    { 3878024, Bucket(4175) }, // 47.57, 19.02 x 47.68, 19.12
    { 3878149, 3583 }, // 49.57, 17.97 x 49.67, 18.08
    { 3878160, 3581 }, // 49.67, 17.97 x 49.78, 18.08
    { 3878638, 2343 }, // 48.62, 21.22 x 48.73, 21.33
    { 3878685, Bucket(4178) }, // 49.98, 19.86 x 50.09, 19.96
    { 3878687, 1192 }, // 49.98, 19.96 x 50.09, 20.07
    { 3878730, 1192 }, // 50.09, 19.96 x 50.19, 20.07
    { 3879189, Bucket(4182) }, // 53.34, 14.62 x 53.45, 14.72
    { 3879203, 445 }, // 52.71, 15.14 x 52.82, 15.24
    { 3879467, Bucket(4186) }, // 51.03, 17.03 x 51.14, 17.13
    { 3881149, 2684 }, // 51.66, 19.44 x 51.77, 19.54
    { 3881192, 2684 }, // 51.77, 19.44 x 51.87, 19.54
    { 3881322, Bucket(4189) }, // 53.45, 18.71 x 53.55, 18.81
    { 3881712, 1397 }, // 52.19, 20.91 x 52.29, 21.01
    { 3885096, 894 }, // 57.64, 11.89 x 57.74, 11.99
    { 3892138, Bucket(4192) }, // 59.32, 17.87 x 59.42, 17.97
    { 3893504, Bucket(4197) }, // 59.32, 17.97 x 59.42, 18.08
    { 3899652, 3408 }, // 46.11, 21.33 x 46.21, 21.43
    { 3899741, Bucket(4200) }, // 47.47, 21.54 x 47.57, 21.64
    { 3899751, Bucket(4203) }, // 47.05, 21.85 x 47.15, 21.96
    { 3900258, 1670 }, // 46.73, 23.53 x 46.84, 23.63
    { 3901331, Bucket(4206) }, // 49.78, 23.95 x 49.88, 24.05
    { 3901603, Bucket(4210) }, // 44.32, 26.05 x 44.43, 26.15
    { 3901606, Bucket(4214) }, // 44.43, 26.05 x 44.53, 26.15
    { 3902191, Bucket(4217) }, // 45.37, 27.93 x 45.48, 28.04
    { 3902415, Bucket(4220) }, // 47.05, 27.51 x 47.15, 27.62
    { 3902426, Bucket(4224) }, // 47.15, 27.51 x 47.26, 27.62
    { 3905481, 3108 }, // 56.91, 24.05 x 57.01, 24.16
    { 3906522, Bucket(4229) }, // 53.86, 27.51 x 53.97, 27.62
    { 3906544, Bucket(4229) }, // 53.86, 27.62 x 53.97, 27.72
    { 3907159, Bucket(4232) }, // 55.86, 26.46 x 55.96, 26.57
    { 3907653, 357 }, // 45.37, 28.04 x 45.48, 28.14
    { 3909485, 673 }, // 50.4, 30.34 x 50.51, 30.45
    { 3909487, Bucket(4235) }, // 50.4, 30.45 x 50.51, 30.55
    { 3909498, Bucket(4240) }, // 50.51, 30.45 x 50.61, 30.55
    { 3909573, Bucket(4243) }, // 50.4, 30.55 x 50.51, 30.66
    { 3909584, Bucket(4243) }, // 50.51, 30.55 x 50.61, 30.66
    { 3911180, 3143 }, // 47.78, 33.28 x 47.89, 33.39
    { 3911183, 2925 }, // 47.89, 33.39 x 47.99, 33.49
    { 3913290, Bucket(4247) }, // 55.12, 30.03 x 55.23, 30.13
    { 3913312, Bucket(4247) }, // 55.12, 30.13 x 55.23, 30.24
    { 3917370, 3354 }, // 61.41, 23.74 x 61.52, 23.84
    { 3917456, 3326 }, // 61.41, 23.84 x 61.52, 23.95
    { 3917909, 3518 }, // 59.21, 24.68 x 59.32, 24.79
    { 3918081, 674 }, // 59.42, 24.68 x 59.53, 24.79
    { 3918109, Bucket(4250) }, // 60.05, 24.89 x 60.16, 25
    { 3918152, Bucket(4255) }, // 60.16, 24.89 x 60.26, 25
    { 3924787, 693 }, // 59.84, 30.24 x 59.95, 30.34
    { 3924792, 1043 }, // 59.74, 30.34 x 59.84, 30.45
    { 3924793, 3630 }, // 59.84, 30.34 x 59.95, 30.45
    { 3924796, Bucket(4265) }, // 59.95, 30.34 x 60.05, 30.45
    { 9276245, 3038 }, // -6.219, 106.9 x -6.114, 107
    { 9453665, 1074 }, // 31.74, 35.17 x 31.84, 35.27
    { 9455557, 3615 }, // 36.98, 37.26 x 37.09, 37.37
    { 9455568, 3615 }, // 37.09, 37.26 x 37.19, 37.37
    { 9457775, Bucket(4269) }, // 38.66, 35.48 x 38.77, 35.59
    { 9467390, Bucket(4273) }, // 44.01, 43.03 x 44.11, 43.14
    { 9467626, Bucket(4276) }, // 41.7, 44.71 x 41.81, 44.81
    { 9468949, 2142 }, // 41.6, 44.81 x 41.7, 44.92
    { 9468992, 2142 }, // 41.7, 44.81 x 41.81, 44.92
    { 9474799, 2896 }, // 25.24, 51.42 x 25.34, 51.53
    { 9474810, Bucket(4279) }, // 25.34, 51.42 x 25.45, 51.53
    { 9476165, 2916 }, // 25.24, 51.53 x 25.34, 51.63
    { 9476176, Bucket(4279) }, // 25.34, 51.53 x 25.45, 51.63
    { 9477522, 3619 }, // 29.54, 52.47 x 29.64, 52.57
    { 9490927, Bucket(4282) }, // 40.34, 49.74 x 40.44, 49.85
    { 9503693, 2751 }, // 47.05, 37.47 x 47.15, 37.58
    { 9503695, 3065 }, // 47.05, 37.58 x 47.15, 37.68
    { 9503773, Bucket(4286) }, // 48.31, 34.96 x 48.41, 35.06
    { 9503816, Bucket(4289) }, // 48.41, 34.96 x 48.52, 35.06
    { 9505146, Bucket(4296) }, // 47.15, 38.84 x 47.26, 38.94
    { 9508566, Bucket(4303) }, // 55.75, 37.37 x 55.86, 37.47
    { 9508571, Bucket(4306) }, // 55.65, 37.58 x 55.75, 37.68
    { 9508572, Bucket(4309) }, // 55.75, 37.47 x 55.86, 37.58
    { 9508574, 1208 }, // 55.75, 37.58 x 55.86, 37.68
    { 9508593, 2024 }, // 55.65, 37.68 x 55.75, 37.79
    { 9508596, 1208 }, // 55.75, 37.68 x 55.86, 37.79
    { 9516847, 2025 }, // 56.28, 43.87 x 56.38, 43.98
    { 9516933, Bucket(4313) }, // 56.28, 43.98 x 56.38, 44.08
    { 9540821, 3503 }, // 55.86, 49.01 x 55.96, 49.11
    { 9543146, Bucket(4318) }, // 56.8, 53.1 x 56.91, 53.2
    { 9543445, 672 }, // 56.7, 53.2 x 56.8, 53.31
    { 9543488, Bucket(4326) }, // 56.8, 53.2 x 56.91, 53.31
    { 9550143, Bucket(4335) }, // 53.34, 58.97 x 53.45, 59.08
    { 9550186, Bucket(4340) }, // 53.45, 58.97 x 53.55, 59.08
    { 9550229, Bucket(4343) }, // 53.34, 59.08 x 53.45, 59.18
    { 9551677, Bucket(4355) }, // 56.7, 60.54 x 56.8, 60.65
    { 9551720, Bucket(4359) }, // 56.8, 60.54 x 56.91, 60.65
    { 9578743, 3753 }, // 18.95, 73.02 x 19.05, 73.13
    { 9578890, 2038 }, // 19.05, 72.81 x 19.16, 72.92
    { 9578914, 3753 }, // 19.05, 73.02 x 19.16, 73.13
    { 9598098, 939 }, // 41.28, 69.25 x 41.39, 69.35
    { 9603074, 2443 }, // 17.37, 78.47 x 17.48, 78.58
    { 9613227, 3191 }, // 22.51, 88.33 x 22.62, 88.44
    { 9680031, 2090 }, // 55.02, 82.88 x 55.12, 82.98
    { 9997350, 3266 }, // 20.94, 105.7 x 21.04, 105.8
    { 10000222, 3242 }, // 30.59, 103.8 x 30.69, 104
    { 10000244, 3242 }, // 30.59, 104 x 30.69, 104.1
    { 10000245, 2951 }, // 30.69, 104 x 30.8, 104.1
    { 10005755, 2915 }, // 22.09, 113.5 x 22.2, 113.6
    { 10005942, 2057 }, // 23.04, 113.3 x 23.14, 113.4
    { 10006111, Bucket(4366) }, // 22.3, 113.9 x 22.41, 114
    { 10006134, 1862 }, // 22.2, 114.1 x 22.3, 114.2
    { 10006277, 2702 }, // 22.72, 113.6 x 22.83, 113.7
    { 10006278, 3437 }, // 22.62, 113.7 x 22.72, 113.8
    { 10006282, Bucket(4374) }, // 22.41, 113.9 x 22.51, 114
    { 10006283, 2064 }, // 22.51, 113.9 x 22.62, 114
    { 10006287, 3566 }, // 22.72, 113.9 x 22.83, 114
    { 10006292, 2252 }, // 23.04, 113.6 x 23.14, 113.7
    { 10006304, 1810 }, // 22.41, 114 x 22.51, 114.1
    { 10006308, Bucket(4387) }, // 22.62, 114 x 22.72, 114.1
    { 10019167, 2208 }, // 34.05, 108.9 x 34.15, 109
    { 10022075, 2868 }, // 34.68, 113.5 x 34.78, 113.6
    { 10064479, 1086 }, // 52.5, 103.8 x 52.61, 104
    { 10064506, Bucket(4390) }, // 52.19, 104.3 x 52.29, 104.4
    { 10096388, 2229 }, // 22.62, 120.3 x 22.72, 120.4
    { 10099402, 3612 }, // 24.92, 121.5 x 25.03, 121.6
    { 10099404, 1635 }, // 25.13, 121.4 x 25.24, 121.5
    { 10110743, 2959 }, // 36.56, 117.1 x 36.67, 117.2
    { 10110786, 2959 }, // 36.67, 117.1 x 36.77, 117.2
    { 10111157, 2871 }, // 31.53, 119.9 x 31.63, 120
    { 10111167, 2185 }, // 31.53, 120.2 x 31.63, 120.3
    { 10111204, 2871 }, // 31.84, 119.9 x 31.95, 120
    { 10111630, 2421 }, // 31.01, 121.5 x 31.11, 121.6
    { 10121045, 2018 }, // 37.4, 127 x 37.51, 127.1
    { 10123259, 2723 }, // 43.9, 125.2 x 44.01, 125.3
    { 10123358, Bucket(4394) }, // 38.97, 125.7 x 39.08, 125.8
    { 10123380, 3138 }, // 38.97, 125.8 x 39.08, 125.9
    { 10123776, Bucket(4397) }, // 37.51, 127 x 37.61, 127.1
    { 10123780, 2000 }, // 37.72, 127 x 37.82, 127.1
    { 10124624, 2722 }, // 43.8, 125.3 x 43.9, 125.5
    { 10124625, 2723 }, // 43.9, 125.3 x 44.01, 125.5
    { 10142190, Bucket(4400) }, // 33.52, 130.3 x 33.63, 130.4
    { 10142231, Bucket(4403) }, // 31.53, 130.5 x 31.63, 130.6
    { 10142532, Bucket(4400) }, // 33.52, 130.4 x 33.63, 130.5
    { 10142976, Bucket(2581) }, // 35.83, 128.7 x 35.93, 128.8
    { 10145466, 2699 }, // 34.57, 135.3 x 34.68, 135.4
    { 10150928, 2699 }, // 34.57, 135.4 x 34.68, 135.5
    { 10150943, 2371 }, // 34.89, 135.7 x 34.99, 135.8
    { 10150986, 2371 }, // 34.99, 135.7 x 35.1, 135.8
    { 10151145, 2377 }, // 35.1, 136.9 x 35.2, 137
    { 10151147, 2721 }, // 35.1, 137 x 35.2, 137.1
    { 10153083, 2080 }, // 35.51, 139.5 x 35.62, 139.6
    { 10153157, 759 }, // 35.3, 139.6 x 35.41, 139.7
    { 10153168, 2048 }, // 35.41, 139.6 x 35.51, 139.7
    { 10153172, 758 }, // 35.62, 139.6 x 35.72, 139.7
    { 10153175, 2592 }, // 35.72, 139.7 x 35.83, 139.8
    { 10153346, 2605 }, // 35.83, 139.7 x 35.93, 139.8
    { 10157968, 2561 }, // 42.96, 141.3 x 43.06, 141.4
    { 10573707, Bucket(4406) }, // -37.89, 145 x -37.78, 145.1
    { 10706798, 3152 }, // -36.94, 174.7 x -36.84, 174.8
    { 10756919, 2740 }, // -33.9, 151 x -33.8, 151.1
    { 10762554, Bucket(4411) }, // -27.5, 152.9 x -27.4, 153
    { 10762640, Bucket(4411) }, // -27.5, 153 x -27.4, 153.1
    { 3922166, 3783 }, // -12.09, -76.98 x -12.04, -76.92
    { 4170863, 1813 }, // 6.207, -75.61 x 6.259, -75.56
    { 4170949, 1813 }, // 6.207, -75.56 x 6.259, -75.51
    { 6381721, Bucket(4414) }, // 37.77, -122.4 x 37.82, -122.4
    { 6382490, 2590 }, // 38.56, -121.5 x 38.61, -121.5
    { 6393016, 2822 }, // 32.68, -117.2 x 32.74, -117.1
    { 6461986, 1865 }, // 20.73, -103.4 x 20.78, -103.3
    { 6872671, 3283 }, // 29.9, -90.08 x 29.96, -90.03
    { 6872842, 3283 }, // 29.96, -90.08 x 30.01, -90.03
    { 6884885, Bucket(4419) }, // 32.84, -96.95 x 32.89, -96.9
    { 6884889, 1784 }, // 32.74, -96.85 x 32.79, -96.8
    { 6918343, Bucket(4422) }, // 34.73, -92.29 x 34.78, -92.23
    { 6943678, 1013 }, // 42.02, -87.78 x 42.07, -87.73
    { 6944481, Bucket(4425) }, // 43.01, -87.94 x 43.06, -87.88
    { 6975585, 3278 }, // 27.91, -82.48 x 27.96, -82.43
    { 7029750, 1401 }, // 39.08, -84.53 x 39.13, -84.47
    { 7045051, 215 }, // 43.64, -79.39 x 43.69, -79.34
    { 7066897, Bucket(4428) }, // 43.64, -79.34 x 43.69, -79.28
    { 7071146, 2306 }, // 40.02, -75.19 x 40.08, -75.14
    { 7073139, 2297 }, // 40.7, -74.04 x 40.76, -73.99
    { 7073144, 2248 }, // 40.65, -73.99 x 40.7, -73.94
    { 7252456, 1213 }, // 45.48, -73.57 x 45.53, -73.52
    { 9568767, 1141 }, // -34.69, -58.42 x -34.64, -58.37
    { 9569134, 1131 }, // -34.95, -58 x -34.9, -57.95
    { 9569220, 1131 }, // -34.95, -57.95 x -34.9, -57.89
    { 9569450, Bucket(4431) }, // -34.64, -58.42 x -34.58, -58.37
    { 9780728, 2039 }, // 10.45, -66.86 x 10.51, -66.81
    { 9780730, 2039 }, // 10.45, -66.81 x 10.51, -66.75
    { 9985879, Bucket(4434) }, // -22.94, -43.21 x -22.89, -43.16
    { 10084346, 3321 }, // -9.679, -35.77 x -9.627, -35.72
    { 10239102, Bucket(4438) }, // -3.702, -40.38 x -3.65, -40.33
    { 12242944, 3033 }, // -26.25, 28.04 x -26.19, 28.09
    { 14703373, 503 }, // 28.44, -16.32 x 28.49, -16.26
    { 14797725, 2102 }, // 38.71, -9.187 x 38.77, -9.135
    { 14797768, 2102 }, // 38.77, -9.187 x 38.82, -9.135
    { 14882592, 2133 }, // 36.67, -4.468 x 36.72, -4.416
    { 14896391, 2315 }, // 40.18, -3.787 x 40.23, -3.734
    { 14896402, 2315 }, // 40.23, -3.787 x 40.29, -3.734
    { 14898943, 1383 }, // 43.33, -3.892 x 43.38, -3.839
    { 14902015, 3770 }, // 38.29, -0.5362 x 38.35, -0.4838
    { 14902186, Bucket(4441) }, // 38.35, -0.5362 x 38.4, -0.4838
    { 14903552, 286 }, // 38.35, -0.4838 x 38.4, -0.4314
    { 14904345, 3495 }, // 39.45, -0.3789 x 39.5, -0.3265
    { 14933786, 1399 }, // 43.59, 3.868 x 43.64, 3.92
    { 14939390, Bucket(4445) }, // 43.27, 5.336 x 43.33, 5.388
    { 14939732, 928 }, // 43.27, 5.388 x 43.33, 5.441
    { 14941982, 2885 }, // 43.69, 7.223 x 43.75, 7.276
    { 14942004, 2885 }, // 43.69, 7.276 x 43.75, 7.328
    { 15087964, 2795 }, // 49.15, -0.3789 x 49.2, -0.3265
    { 15091940, 266 }, // 51.45, -3.21 x 51.51, -3.158
    { 15094740, 1798 }, // 55.86, -4.259 x 55.91, -4.206
    { 15111020, 1876 }, // 48.94, 2.347 x 48.99, 2.4
    { 15111117, 1898 }, // 48.99, 2.557 x 49.04, 2.61
    { 15114203, 3714 }, // 50.77, 4.287 x 50.82, 4.34
    { 15114225, 3714 }, // 50.77, 4.34 x 50.82, 4.392
    { 15114619, 3489 }, // 45.74, 4.916 x 45.79, 4.969
    { 15114705, 3489 }, // 45.74, 4.969 x 45.79, 5.021
    { 15117023, 492 }, // 45, 7.643 x 45.06, 7.695
    { 15118127, 1015 }, // 46.89, 7.433 x 46.94, 7.485
    { 15118138, Bucket(4448) }, // 46.94, 7.433 x 47, 7.485
    { 15118257, 3839 }, // 47, 7.695 x 47.05, 7.748
    { 15121911, 120 }, // 50.88, 6.909 x 50.93, 6.961
    { 15287793, 802 }, // 40.7, 8.534 x 40.76, 8.586
    { 15296623, 1709 }, // 38.08, 13.3 x 38.14, 13.36
    { 15298431, 3218 }, // 40.81, 14.14 x 40.86, 14.2
    { 15298519, 3301 }, // 40.81, 14.25 x 40.86, 14.3
    { 15299375, Bucket(4451) }, // 41.86, 12.47 x 41.91, 12.52
    { 15299461, Bucket(4451) }, // 41.86, 12.52 x 41.91, 12.57
    { 15301250, 3301 }, // 40.86, 14.25 x 40.91, 14.3
    { 15332801, 2623 }, // 43.85, 18.39 x 43.9, 18.44
    { 15419575, 1844 }, // 37.87, 23.69 x 37.93, 23.74
    { 15419618, 1844 }, // 37.93, 23.69 x 37.98, 23.74
    { 15435807, 1969 }, // 31.16, 29.87 x 31.22, 29.92
    { 15435850, 1969 }, // 31.22, 29.87 x 31.27, 29.92
    { 15467327, Bucket(4454) }, // 45.42, 9.111 x 45.48, 9.163
    { 15467370, Bucket(4454) }, // 45.48, 9.111 x 45.53, 9.163
    { 15467413, Bucket(4457) }, // 45.42, 9.163 x 45.48, 9.216
    { 15467456, Bucket(4457) }, // 45.48, 9.163 x 45.53, 9.216
    { 15467850, 590 }, // 47.15, 8.062 x 47.21, 8.115
    { 15467880, 236 }, // 47.15, 8.219 x 47.21, 8.272
    { 15467881, 236 }, // 47.21, 8.219 x 47.26, 8.272
    { 15467882, 236 }, // 47.15, 8.272 x 47.21, 8.324
    { 15467994, 1099 }, // 47.36, 8.482 x 47.42, 8.534
    { 15468016, Bucket(4463) }, // 47.36, 8.534 x 47.42, 8.586
    { 15468376, 2460 }, // 47.36, 8.849 x 47.42, 8.901
    { 15468379, 3010 }, // 47.42, 8.901 x 47.47, 8.953
    { 15468381, 3010 }, // 47.52, 8.849 x 47.57, 8.901
    { 15468382, 3010 }, // 47.47, 8.901 x 47.52, 8.953
    { 15468383, 3010 }, // 47.52, 8.901 x 47.57, 8.953
    { 15468394, 3091 }, // 47.15, 9.111 x 47.21, 9.163
    { 15468395, 3091 }, // 47.21, 9.111 x 47.26, 9.163
    { 15468398, 3091 }, // 47.26, 9.111 x 47.31, 9.163
    { 15468399, 3091 }, // 47.31, 9.111 x 47.36, 9.163
    { 15468410, 3091 }, // 47.36, 9.111 x 47.42, 9.163
    { 15468411, 3091 }, // 47.42, 9.111 x 47.47, 9.163
    { 15468501, 3037 }, // 47.52, 9.163 x 47.57, 9.216
    { 15469848, 3672 }, // 46.94, 9.687 x 47, 9.74
    { 15471096, 1432 }, // 49.04, 8.639 x 49.09, 8.691
    { 15471099, 500 }, // 49.09, 8.691 x 49.15, 8.744
    { 15471469, 874 }, // 48.99, 9.058 x 49.04, 9.111
    { 15471471, 874 }, // 48.99, 9.111 x 49.04, 9.163
    { 15471508, 55 }, // 48.73, 9.163 x 48.78, 9.216
    { 15471556, 198 }, // 48.94, 9.163 x 48.99, 9.216
    { 15471557, 874 }, // 48.99, 9.163 x 49.04, 9.216
    { 15471558, 198 }, // 48.94, 9.216 x 48.99, 9.268
    { 15471559, 874 }, // 48.99, 9.216 x 49.04, 9.268
    { 15471564, 198 }, // 48.94, 9.268 x 48.99, 9.32
    { 15471565, 874 }, // 48.99, 9.268 x 49.04, 9.32
    { 15471566, 198 }, // 48.94, 9.32 x 48.99, 9.373
    { 15471567, 874 }, // 48.99, 9.32 x 49.04, 9.373
    { 15471588, 198 }, // 48.94, 9.373 x 48.99, 9.425
    { 15471589, 874 }, // 48.99, 9.373 x 49.04, 9.425
    { 15471591, 874 }, // 48.99, 9.425 x 49.04, 9.478
    { 15471597, 874 }, // 48.99, 9.478 x 49.04, 9.53
    { 15471740, 2026 }, // 49.98, 8.219 x 50.04, 8.272
    { 15471840, 552 }, // 49.67, 8.534 x 49.72, 8.586
    { 15471869, 710 }, // 50.04, 8.639 x 50.09, 8.691
    { 15472040, 710 }, // 50.09, 8.639 x 50.14, 8.691
    { 15472384, 701 }, // 50.09, 8.744 x 50.14, 8.796
    { 15472767, 1913 }, // 48.36, 9.95 x 48.41, 10
    { 15472853, 1913 }, // 48.36, 10 x 48.41, 10.05
    { 15472938, 1913 }, // 48.41, 9.95 x 48.46, 10
    { 15473024, 1913 }, // 48.41, 10 x 48.46, 10.05
    { 15474341, 2481 }, // 49.41, 11.05 x 49.46, 11.1
    { 15475485, 981 }, // 45.42, 12.2 x 45.48, 12.26
    { 15475528, 981 }, // 45.48, 12.2 x 45.53, 12.26
    { 15478892, 3446 }, // 48.1, 11.57 x 48.15, 11.63
    { 15478893, 195 }, // 48.15, 11.57 x 48.2, 11.63
    { 15480189, Bucket(4466) }, // 50.88, 11.57 x 50.93, 11.63
    { 15480318, 867 }, // 50.82, 12.05 x 50.88, 12.1
    { 15480597, 1162 }, // 50.46, 12.1 x 50.51, 12.15
    { 15480773, 1655 }, // 50.67, 12.52 x 50.72, 12.57
    { 15482295, 3540 }, // 50.46, 13.62 x 50.51, 13.67
    { 15482338, 3540 }, // 50.51, 13.62 x 50.56, 13.67
    { 15485474, 952 }, // 50.93, 10.68 x 50.98, 10.74
    { 15485838, 1381 }, // 51.87, 11 x 51.92, 11.05
    { 15485860, 1381 }, // 51.87, 11.05 x 51.92, 11.1
    { 15491112, Bucket(4466) }, // 50.93, 11.57 x 50.98, 11.63
    { 15491224, 1136 }, // 51.14, 11.78 x 51.19, 11.84
    { 15491682, 3718 }, // 51.35, 12.36 x 51.4, 12.41
    { 15491754, 1924 }, // 50.93, 12.89 x 50.98, 12.94
    { 15491962, Bucket(4470) }, // 52.4, 12.47 x 52.45, 12.52
    { 15492048, Bucket(4470) }, // 52.4, 12.52 x 52.45, 12.57
    { 15492602, 71 }, // 54.07, 12.05 x 54.13, 12.1
    { 15493636, Bucket(4473) }, // 51.03, 13.78 x 51.09, 13.83
    { 15493853, Bucket(4476) }, // 51.72, 14.3 x 51.77, 14.35
    { 15494024, Bucket(4480) }, // 51.77, 14.3 x 51.82, 14.35
    { 15494124, 291 }, // 52.29, 14.51 x 52.34, 14.56
    { 15494909, 778 }, // 53.39, 14.51 x 53.45, 14.56
    { 15495080, 778 }, // 53.45, 14.51 x 53.5, 14.56
    { 15500734, 432 }, // 47.05, 15.4 x 47.1, 15.45
    { 15501076, Bucket(4483) }, // 47.05, 15.45 x 47.1, 15.51
    { 15504111, 160 }, // 48.15, 16.24 x 48.2, 16.29
    { 15504122, 103 }, // 48.2, 16.24 x 48.25, 16.29
    { 15505477, 69 }, // 48.15, 16.29 x 48.2, 16.35
    { 15505479, 3350 }, // 48.15, 16.35 x 48.2, 16.4
    { 15505488, 68 }, // 48.2, 16.29 x 48.25, 16.35
    { 15505490, Bucket(4486) }, // 48.2, 16.35 x 48.25, 16.4
    { 15506972, Bucket(4489) }, // 49.57, 17.24 x 49.62, 17.29
    { 15509342, Bucket(4492) }, // 47.47, 18.97 x 47.52, 19.02
    { 15509364, Bucket(4496) }, // 47.47, 19.02 x 47.52, 19.07
    { 15509369, 610 }, // 47.42, 19.12 x 47.47, 19.18
    { 15509743, 537 }, // 44.79, 20.44 x 44.85, 20.49
    { 15511227, Bucket(4501) }, // 46.16, 21.27 x 46.21, 21.33
    { 15514553, 2598 }, // 48.67, 21.22 x 48.73, 21.27
    { 15514743, 276 }, // 50.04, 19.91 x 50.09, 19.96
    { 15516928, 3382 }, // 53.45, 14.62 x 53.5, 14.67
    { 15524597, Bucket(4506) }, // 51.72, 19.44 x 51.77, 19.49
    { 15524768, Bucket(4506) }, // 51.77, 19.44 x 51.82, 19.49
    { 15530175, 3361 }, // 54.65, 20.44 x 54.7, 20.49
    { 15530218, 3361 }, // 54.7, 20.44 x 54.76, 20.49
    { 15530517, Bucket(4509) }, // 54.65, 20.49 x 54.7, 20.54
    { 15530560, Bucket(4509) }, // 54.7, 20.49 x 54.76, 20.54
    { 15567871, 1791 }, // 59.26, 17.92 x 59.32, 17.97
    { 15568554, Bucket(4512) }, // 59.32, 17.92 x 59.37, 17.97
    { 15574016, 3235 }, // 59.32, 17.97 x 59.37, 18.02
    { 15598609, Bucket(4503) }, // 46.16, 21.33 x 46.21, 21.38
    { 15599006, Bucket(4515) }, // 47.05, 21.9 x 47.1, 21.96
    { 15609792, Bucket(4518) }, // 47.15, 27.62 x 47.21, 27.67
    { 15626088, 3226 }, // 53.86, 27.51 x 53.92, 27.57
    { 15628638, 655 }, // 55.86, 26.52 x 55.91, 26.57
    { 15666862, Bucket(4521) }, // 59.42, 24.63 x 59.47, 24.68
    { 37088620, 3193 }, // 13.7, 100.5 x 13.76, 100.5
    { 37103583, 3745 }, // -6.166, 106.6 x -6.114, 106.7
    { 37391332, 3008 }, // -34.95, 138.6 x -34.9, 138.6
    { 37835467, 3607 }, // 41.33, 36.16 x 41.39, 36.22
    { 37870335, 2142 }, // 41.65, 44.76 x 41.7, 44.81
    { 37899197, 3417 }, // 25.29, 51.42 x 25.34, 51.47
    { 37899243, 2987 }, // 25.4, 51.47 x 25.45, 51.53
    { 37904660, 2896 }, // 25.24, 51.53 x 25.29, 51.58
    { 38034296, 3668 }, // 55.75, 37.58 x 55.8, 37.63
    { 38067390, 318 }, // 56.28, 43.92 x 56.33, 43.98
    { 38163282, 3505 }, // 55.75, 49.06 x 55.8, 49.11
    { 38171119, 3374 }, // 55.7, 52.31 x 55.75, 52.36
    { 38172415, 750 }, // 56.75, 53.15 x 56.8, 53.2
    { 38172587, 752 }, // 56.85, 53.15 x 56.91, 53.2
    { 38173781, 753 }, // 56.75, 53.2 x 56.8, 53.26
    { 38173953, 752 }, // 56.85, 53.2 x 56.91, 53.26
    { 38200746, 643 }, // 53.45, 59.02 x 53.5, 59.08
    { 38200917, Bucket(4524) }, // 53.39, 59.08 x 53.45, 59.13
    { 38201088, Bucket(4352) }, // 53.45, 59.08 x 53.5, 59.13
    { 38206711, 2091 }, // 56.75, 60.6 x 56.8, 60.65
    { 38723305, 551 }, // 56.43, 84.98 x 56.49, 85.03
    { 40024447, 1809 }, // 22.35, 114 x 22.41, 114
    { 40024532, 461 }, // 22.3, 114 x 22.35, 114.1
    { 40024533, Bucket(4529) }, // 22.35, 114 x 22.41, 114.1
    { 40025216, Bucket(4529) }, // 22.41, 114 x 22.46, 114.1
    { 40044672, 2951 }, // 30.8, 104 x 30.85, 104
    { 40089669, 3746 }, // 34.73, 113.6 x 34.78, 113.7
    { 40384186, 2229 }, // 22.62, 120.3 x 22.67, 120.3
    { 40444842, 2184 }, // 31.63, 120.3 x 31.69, 120.3
    { 40446208, 2184 }, // 31.63, 120.3 x 31.69, 120.4
    { 40571221, 2196 }, // 35.78, 128.7 x 35.83, 128.8
    { 40576486, 1600 }, // 33.84, 132.7 x 33.89, 132.8
    { 40579130, Bucket(4533) }, // 34.36, 132.4 x 34.41, 132.5
    { 40579216, 530 }, // 34.36, 132.5 x 34.41, 132.5
    { 40581857, 2061 }, // 34.62, 135.2 x 34.68, 135.3
    { 40581860, 2061 }, // 34.68, 135.2 x 34.73, 135.3
    { 40581862, 2060 }, // 34.68, 135.3 x 34.73, 135.3
    { 40605957, 2721 }, // 35.15, 137.1 x 35.2, 137.1
    { 40612326, 2613 }, // 35.51, 139.4 x 35.57, 139.5
    { 40612340, 2606 }, // 35.72, 139.4 x 35.78, 139.4
    { 40612676, 2080 }, // 35.51, 139.6 x 35.57, 139.7
    { 40612701, 2605 }, // 35.78, 139.7 x 35.83, 139.8
    { 40613410, 2640 }, // 35.83, 139.9 x 35.88, 139.9
    { 25933824, 2245 }, // 25.76, -100.3 x 25.79, -100.3
    { 26155971, 3559 }, // 39.84, -104.7 x 39.87, -104.7
    { 27683990, 569 }, // 35.15, -90.01 x 35.17, -89.98
    { 27902258, 3314 }, // 27.96, -82.56 x 27.99, -82.53
    { 27902264, 3315 }, // 27.96, -82.53 x 27.99, -82.51
    { 28142893, 2487 }, // 42.2, -83.37 x 42.23, -83.35
    { 28143389, 1132 }, // 42.3, -83.06 x 42.33, -83.03
    { 28143432, 1132 }, // 42.33, -83.06 x 42.36, -83.03
    { 28285952, 2306 }, // 40.02, -75.14 x 40.05, -75.12
    { 37762474, 3739 }, // -33.38, -70.55 x -33.35, -70.53
    { 37762645, 3739 }, // -33.4, -70.53 x -33.38, -70.5
    { 37762816, 3739 }, // -33.38, -70.53 x -33.35, -70.5
    { 59602602, 1905 }, // 43.38, -3.027 x 43.41, -3
    { 59722010, 1837 }, // 41.39, 2.111 x 41.41, 2.138
    { 59722038, 1531 }, // 41.44, 2.164 x 41.47, 2.19
    { 59758968, 1814 }, // 43.27, 5.546 x 43.3, 5.572
    { 60458445, 1334 }, // 45.76, 4.812 x 45.79, 4.838
    { 60469317, 2943 }, // 46.18, 6.227 x 46.21, 6.253
    { 60469695, 1500 }, // 46.5, 6.62 x 46.52, 6.647
    { 60469738, 1500 }, // 46.52, 6.62 x 46.55, 6.647
    { 60470037, 1500 }, // 46.5, 6.647 x 46.52, 6.673
    { 60470080, 1500 }, // 46.52, 6.647 x 46.55, 6.673
    { 60499973, 1435 }, // 51.01, 3.711 x 51.03, 3.737
    { 60499984, 1435 }, // 51.03, 3.711 x 51.06, 3.737
    { 60500687, 1277 }, // 51.22, 4.418 x 51.24, 4.445
    { 60523536, 1737 }, // 51.87, 4.549 x 51.9, 4.576
    { 60531285, 542 }, // 51.32, 6.647 x 51.35, 6.673
    { 61197503, 833 }, // 41.88, 12.49 x 41.91, 12.52
    { 61281621, 3776 }, // 40.84, 14.62 x 40.86, 14.64
    { 61743317, 1969 }, // 31.19, 29.92 x 31.22, 29.95
    { 61818977, 2644 }, // 41.1, 28.98 x 41.12, 29.01
    { 61818984, 3550 }, // 41.07, 29.03 x 41.1, 29.06
    { 61869311, 3487 }, // 45.45, 9.137 x 45.48, 9.163
    { 61869482, 3487 }, // 45.48, 9.137 x 45.5, 9.163
    { 61871532, 236 }, // 47.21, 8.272 x 47.23, 8.298
    { 61871535, 591 }, // 47.23, 8.298 x 47.26, 8.324
    { 61871952, 2784 }, // 47.47, 8.324 x 47.49, 8.35
    { 61871978, Bucket(4537) }, // 47.36, 8.508 x 47.39, 8.534
    { 61873508, 2460 }, // 47.42, 8.849 x 47.44, 8.875
    { 61873509, 2460 }, // 47.44, 8.849 x 47.47, 8.875
    { 61873520, 2460 }, // 47.47, 8.849 x 47.49, 8.875
    { 61873521, 2460 }, // 47.49, 8.849 x 47.52, 8.875
    { 61873522, 3010 }, // 47.47, 8.875 x 47.49, 8.901
    { 61873523, 3010 }, // 47.49, 8.875 x 47.52, 8.901
    { 61873570, 3091 }, // 47.15, 9.084 x 47.18, 9.111
    { 61873571, 3091 }, // 47.18, 9.084 x 47.21, 9.111
    { 61873574, 3091 }, // 47.21, 9.084 x 47.23, 9.111
    { 61873575, 3091 }, // 47.23, 9.084 x 47.26, 9.111
    { 61873586, 3091 }, // 47.26, 9.084 x 47.28, 9.111
    { 61873587, 3091 }, // 47.28, 9.084 x 47.31, 9.111
    { 61873590, 3091 }, // 47.31, 9.084 x 47.34, 9.111
    { 61873591, 3091 }, // 47.34, 9.084 x 47.36, 9.111
    { 61873634, 3091 }, // 47.36, 9.084 x 47.39, 9.111
    { 61873635, 3091 }, // 47.39, 9.084 x 47.42, 9.111
    { 61873638, 3091 }, // 47.42, 9.084 x 47.44, 9.111
    { 61873639, 3091 }, // 47.44, 9.084 x 47.47, 9.111
    { 61879509, 3090 }, // 47.13, 9.792 x 47.15, 9.818
    { 61879621, 3457 }, // 47.44, 9.583 x 47.47, 9.609
    { 61879632, 3457 }, // 47.47, 9.583 x 47.49, 9.609
    { 61884391, 500 }, // 49.12, 8.665 x 49.15, 8.691
    { 61884392, 1432 }, // 49.04, 8.691 x 49.07, 8.717
    { 61885882, 198 }, // 48.94, 9.137 x 48.96, 9.163
    { 61886360, 198 }, // 48.94, 9.425 x 48.96, 9.451
    { 61889536, 708 }, // 50.09, 8.744 x 50.12, 8.77
    { 61898102, 3452 }, // 50.88, 10.55 x 50.9, 10.58
    { 61923136, 1655 }, // 50.72, 12.52 x 50.75, 12.54
    { 61966557, 3718 }, // 51.32, 12.36 x 51.35, 12.39
    { 61973999, 167 }, // 52.48, 13.33 x 52.5, 13.36
    { 62016447, Bucket(4540) }, // 48.18, 16.27 x 48.2, 16.29
    { 62016490, 70 }, // 48.2, 16.27 x 48.23, 16.29
    { 62021909, 70 }, // 48.18, 16.29 x 48.2, 16.32
    { 62021911, 68 }, // 48.18, 16.32 x 48.2, 16.35
    { 62021952, 70 }, // 48.2, 16.29 x 48.23, 16.32
    { 62120703, 3572 }, // 54.68, 20.46 x 54.7, 20.49
    { 62120874, 3572 }, // 54.7, 20.46 x 54.73, 20.49
    { 62271487, 321 }, // 59.29, 17.94 x 59.32, 17.97
    { 62296064, 320 }, // 59.32, 17.97 x 59.34, 18
    { 62394437, 3403 }, // 46.18, 21.33 x 46.21, 21.35
    { 62396015, 3738 }, // 47.02, 21.93 x 47.05, 21.96
    { 151255697, 1339 }, // 29.25, 47.96 x 29.28, 47.99
    { 151341957, 3607 }, // 41.36, 36.22 x 41.39, 36.24
    { 151860305, 2151 }, // 40.36, 49.85 x 40.39, 49.87
    { 152137151, 1406 }, // 55.73, 37.66 x 55.75, 37.68
    { 152137194, 1406 }, // 55.75, 37.66 x 55.78, 37.68
    { 152137493, 1406 }, // 55.73, 37.68 x 55.75, 37.71
    { 152137536, 1406 }, // 55.75, 37.68 x 55.78, 37.71
    { 152651770, 3503 }, // 55.86, 48.98 x 55.88, 49.01
    { 152689663, Bucket(4543) }, // 56.77, 53.18 x 56.8, 53.2
    { 152803669, 1795 }, // 53.42, 59.08 x 53.45, 59.1
    { 152804352, Bucket(4546) }, // 53.45, 59.08 x 53.47, 59.1
    { 161973743, 794 }, // 39.05, 125.7 x 39.08, 125.8
    { 161974085, 794 }, // 39.05, 125.8 x 39.08, 125.8
    { 162305944, 1599 }, // 33.84, 132.7 x 33.86, 132.8
    { 162316523, 136 }, // 34.39, 132.4 x 34.41, 132.5
    { 162324783, Bucket(4552) }, // 34.65, 133.9 x 34.68, 133.9
    { 162450911, 2640 }, // 35.8, 139.9 x 35.83, 139.9
    { 171291302, 1987 }, // -41.29, 174.8 x -41.27, 174.8
    { 172124673, 2734 }, // -32.93, 151.8 x -32.91, 151.8
    { 103729834, 2245 }, // 25.76, -100.3 x 25.78, -100.3
    { 103832300, 3689 }, // 33.44, -112.1 x 33.46, -112.1
    { 113170325, 367 }, // 40.74, -73.99 x 40.76, -73.98
    { 151049215, 3739 }, // -33.39, -70.54 x -33.38, -70.53
    { 153713678, 2241 }, // -30, -51.2 x -29.98, -51.18
    { 153713700, 2241 }, // -30, -51.18 x -29.98, -51.17
    { 238342614, 2181 }, // 40.42, -3.721 x 40.43, -3.708
    { 239030251, 929 }, // 43.29, 5.375 x 43.3, 5.388
    { 241994431, 1435 }, // 51.02, 3.697 x 51.03, 3.711
    { 242125824, 542 }, // 51.35, 6.647 x 51.36, 6.66
    { 245170176, 3695 }, // 40.86, 14.62 x 40.88, 14.63
    { 247275642, 3385 }, // 41.02, 28.97 x 41.03, 28.98
    { 247275729, 3384 }, // 41.03, 28.98 x 41.05, 28.99
    { 247486136, 236 }, // 47.21, 8.298 x 47.22, 8.311
    { 247494047, 3010 }, // 47.46, 8.888 x 47.47, 8.901
    { 247494272, 3048 }, // 47.15, 9.058 x 47.17, 9.071
    { 247494273, 3048 }, // 47.17, 9.058 x 47.18, 9.071
    { 247494275, 3091 }, // 47.17, 9.071 x 47.18, 9.084
    { 247494276, 3048 }, // 47.18, 9.058 x 47.19, 9.071
    { 247494277, 3048 }, // 47.19, 9.058 x 47.21, 9.071
    { 247494278, 3091 }, // 47.18, 9.071 x 47.19, 9.084
    { 247494279, 3091 }, // 47.19, 9.071 x 47.21, 9.084
    { 247494288, 3048 }, // 47.21, 9.058 x 47.22, 9.071
    { 247494289, 3048 }, // 47.22, 9.058 x 47.23, 9.071
    { 247494290, 3091 }, // 47.21, 9.071 x 47.22, 9.084
    { 247494291, 3091 }, // 47.22, 9.071 x 47.23, 9.084
    { 247494292, 3048 }, // 47.23, 9.058 x 47.25, 9.071
    { 247494293, 3048 }, // 47.25, 9.058 x 47.26, 9.071
    { 247494294, 3091 }, // 47.23, 9.071 x 47.25, 9.084
    { 247494295, 3091 }, // 47.25, 9.071 x 47.26, 9.084
    { 247494336, 3048 }, // 47.26, 9.058 x 47.27, 9.071
    { 247494337, 3048 }, // 47.27, 9.058 x 47.28, 9.071
    { 247494338, 3091 }, // 47.26, 9.071 x 47.27, 9.084
    { 247494339, 3091 }, // 47.27, 9.071 x 47.28, 9.084
    { 247494340, 3048 }, // 47.28, 9.058 x 47.3, 9.071
    { 247494341, 3048 }, // 47.3, 9.058 x 47.31, 9.071
    { 247494342, 3091 }, // 47.28, 9.071 x 47.3, 9.084
    { 247494343, 3091 }, // 47.3, 9.071 x 47.31, 9.084
    { 247494352, 3048 }, // 47.31, 9.058 x 47.32, 9.071
    { 247494353, 3048 }, // 47.32, 9.058 x 47.34, 9.071
    { 247494354, 3091 }, // 47.31, 9.071 x 47.32, 9.084
    { 247494355, 3091 }, // 47.32, 9.071 x 47.34, 9.084
    { 247494356, 3048 }, // 47.34, 9.058 x 47.35, 9.071
    { 247494357, 3048 }, // 47.35, 9.058 x 47.36, 9.071
    { 247494358, 3091 }, // 47.34, 9.071 x 47.35, 9.084
    { 247494359, 3091 }, // 47.35, 9.071 x 47.36, 9.084
    { 247494528, 3048 }, // 47.36, 9.058 x 47.38, 9.071
    { 247494529, 3048 }, // 47.38, 9.058 x 47.39, 9.071
    { 247494530, 3091 }, // 47.36, 9.071 x 47.38, 9.084
    { 247494531, 3091 }, // 47.38, 9.071 x 47.39, 9.084
    { 247494532, 3048 }, // 47.39, 9.058 x 47.4, 9.071
    { 247494533, 3048 }, // 47.4, 9.058 x 47.42, 9.071
    { 247494534, 3091 }, // 47.39, 9.071 x 47.4, 9.084
    { 247494535, 3091 }, // 47.4, 9.071 x 47.42, 9.084
    { 247494544, 3048 }, // 47.42, 9.058 x 47.43, 9.071
    { 247494545, 3048 }, // 47.43, 9.058 x 47.44, 9.071
    { 247494546, 3091 }, // 47.42, 9.071 x 47.43, 9.084
    { 247494547, 3091 }, // 47.43, 9.071 x 47.44, 9.084
    { 247494548, 3048 }, // 47.44, 9.058 x 47.46, 9.071
    { 247494550, 3091 }, // 47.44, 9.071 x 47.46, 9.084
    { 247494551, 3091 }, // 47.46, 9.071 x 47.47, 9.084
    { 247548346, 3760 }, // 49.51, 8.521 x 49.53, 8.534
    { 247548688, 3760 }, // 49.51, 8.534 x 49.53, 8.547
    { 248011755, 3415 }, // 47.06, 15.44 x 47.08, 15.45
    { 248017217, 3415 }, // 47.06, 15.45 x 47.08, 15.47
    { 249755989, Bucket(4518) }, // 47.14, 27.62 x 47.15, 27.63
    { 606387153, 2986 }, // 25.3, 51.42 x 25.32, 51.43
    { 611217408, Bucket(4555) }, // 53.45, 59.08 x 53.46, 59.09
    { 646361821, 2628 }, // 25.12, 121.5 x 25.13, 121.5
    { 646361992, 2628 }, // 25.13, 121.5 x 25.15, 121.5
    { 647899818, 2076 }, // 37.51, 127 x 37.52, 127
    { 688497326, 2734 }, // -32.93, 151.8 x -32.92, 151.8
    { 446436142, 3067 }, // 27.98, -82.54 x 27.98, -82.53
    { 446436228, 3313 }, // 27.98, -82.53 x 27.98, -82.53
    { 947054399, 538 }, // 38.71, -9.141 x 38.71, -9.135
    { 947054442, 538 }, // 38.71, -9.141 x 38.72, -9.135
    { 947054485, 538 }, // 38.71, -9.135 x 38.71, -9.128
    { 947054528, 538 }, // 38.71, -9.135 x 38.72, -9.128
    { 967977898, 1435 }, // 51.03, 3.704 x 51.04, 3.711
    { 979168146, 978 }, // 41.83, 12.89 x 41.84, 12.9
    { 987895808, 1969 }, // 31.22, 29.92 x 31.22, 29.93
    { 989977099, 3091 }, // 47.16, 9.078 x 47.17, 9.084
    { 990221653, 708 }, // 50.08, 8.744 x 50.09, 8.75
    { 990309034, 1902 }, // 48.41, 11.25 x 48.42, 11.26
    { 2443122005, 750 }, // 56.79, 53.2 x 56.8, 53.21
    { 2596894943, 1599 }, // 33.83, 132.8 x 33.84, 132.8
    { 2598693247, 2059 }, // 35.19, 136.9 x 35.2, 136.9
    { 2598693930, 2059 }, // 35.2, 136.9 x 35.21, 136.9
};
}
