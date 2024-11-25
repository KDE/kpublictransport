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
    "REX7/S7\0"
    "R5/S5\0"
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
    "T22\0"
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
    "Hammersmith & City\0"
    "TL11\0"
    "TL12\0"
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
    "MMTS\0"
    "SYK\0"
    "ISL\0"
    "TCL\0"
    "21R\0"
    "AEL\0"
    "EAL\0"
    "TML\0"
    "28E\0"
    "Belfast-Bangor\0"
    "Belfast-Larne\0"
    "S9\0"
    "Dark Green\0"
    "639\0"
    "C-3\0"
    "C-1\0"
    "U ATE-CRI\0"
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
    "S32\0"
    "Arènes-Colomiers\0"
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
    "FC3\0"
    "FL5\0"
    "FL6\0"
    "FL7\0"
    "FL8\0"
    "LEX\0"
    "635\0"
    "655\0"
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
    "T20\0"
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
    "T Line\0"
    "T7\0"
    "IC LSA<=>BRA\0"
    "U BRA\0"
    "T3b\0"
    "Rhônexpress\0"
    "Line 3\0"
    "KTL\0"
    "T13\0"
    "T17\0"
    "T9\0"
    "T15\0"
    "T24\0"
    "T21\0"
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
    "106\0"
    "101\0"
    "108\0"
    "U17\0"
    "U18\0"
    "WTR\0"
    "TDV\0"
    "S44\0"
    "1 Line\0"
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
    "C2\0"
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
    "R9\0"
    "RB24\0"
    "R7\0"
    "TL10\0"
    "TL9\0"
    "U2Z\0"
    "ML1\0"
    "ML2\0"
    "ML3\0"
    "I1\0"
    "RL2\0"
    "R2Nord\0"
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
    "U CIS-CSO\0"
    "U CSO-CIS\0"
    "Cascais\0"
    "U OEI-CSO\0"
    "U CSO-OEI\0"
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
    "ATS\0"
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
    "MSC 711\0"
    "MNC\0"
    "RE 22\0"
    "C-9\0"
    "СТ-2\0"
    "NT\0"
    "U AZA-LSA\0"
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
    "5XX\0"
    "8XX\0"
    "1XX\0"
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
    "S Line\0"
    "N Line\0"
    "2 Line\0"
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
    "Metrorail\0"
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
    "U BAO-PSD\0"
    "U PSD-BAO\0"
    "U CRI-ATE\0"
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
    "640\0"
    "662\0"
    "636\0"
    "656\0"
    "BTANIC\0"
    "UP Express\0"
    "Stouffville\0"
    "Richmond Hill\0"
    "MI\0"
    "KI\0"
    "Barrie\0"
    "Lakeshore East\0"
    "South Coast\0"
    "West\0"
    "Umlazi\0"
    "Crossmoor\0"
    "kwaMashu\0"
    "Old Main\0"
    "S22\0"
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
    "30205\0"
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
    "PTDOCK\0"
    "NH\0"
    "Т1\0"
    "RB 14\0"
    "RB 54\0"
    "RE 5\0"
    "4XX\0"
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
    "Atlantic City\0"
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
    "15b\0"
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
    "MTR\0"
    "RB 73\0"
    "Z40\0"
    "RE80\0"
    "JT\0"
    "T12\0"
    "Jinyi\0"
    "S90\0"
    "U AZA-ATE\0"
    "F4\0"
    "XR\0"
    "GR01\0"
    "AGTS\0"
    "6B\0"
    "S74\0"
    "S 10\0"
    "RE8\0"
    "IR85\0"
    "58d\0"
    "M11\0"
    "D7\0"
    "D83\0"
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
    "D13\0"
    "T46\0"
    "Cleveland\0"
    "Beenleigh\0"
    "NC (SB)\0"
    "1N\0"
    "1S\0"
    "S39\0"
    "Kalayang\0"
    "GLK\0"
    "C-5a\0"
    "Delhi–Meerut RapidX\0"
    "Springfield\0"
    "23R\0"
    "SALIS\0"
    "NOAR\0"
    "FESTVL\0"
    "GAW\0"
    "ER-02\0"
    "2-ая Сормовская линия\0"
    "1-ая Сормовская линия\0"
    "Приокская линия\0"
    "REX1\0"
    "T30\0"
    "S88\0"
    "REX3\0"
    "BEG\0"
    "RB 40\0"
    "RL3\0"
    "4а\0"
    "S65\0"
    "RB 33\0"
    "S49\0"
    "1T\0"
    "S37\0"
    "Тр9\0"
    "云巴\0"
    "10E\0"
    "9E\0"
    "8T\0"
    "6XX\0"
    "Мінск => Чырвоны Сцяг\0"
    "Чырвоны Сцяг => Мінск\0"
    "U SAL-BAO\0"
    "U BAO-SAL\0"
    "Seac Pai Van\0"
    "Э\0"
    "U ATE-AZA\0"
    "U LSA-AZA\0"
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
    "KVV icon tram 3.svg\0"
    "KVV icon tram 1.svg\0"
    "KVV icon tram 5.svg\0"
    "KVV icon tram 4.svg\0"
    "KVV icon S8.svg\0"
    "KVV icon tram 8.svg\0"
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
    "S1 S-Bahn Stuttgart Logo (2021).svg\0"
    "S2 S-Bahn Stuttgart Logo (2021).svg\0"
    "S3 S-Bahn Stuttgart Logo (2021).svg\0"
    "Metro Centro.PNG\0"
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
    "KVV icon S6.svg\0"
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
    "Nürnberg T5.svg\0"
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
    "Nürnberg T4.svg\0"
    "Nürnberg T8.svg\0"
    "S11 Steiermark.svg\0"
    "Logo Strausberger Eisenbahn.svg\0"
    "Nürnberg S1.svg\0"
    "Nürnberg S2.svg\0"
    "Nürnberg S3.svg\0"
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
    "Nürnberg S5.svg\0"
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
    "SHM Line 2 icon.svg\0"
    "Paris transit icons - Train U.svg\0"
    "Paris transit icons - Train.svg\0"
    "Logo NN Tram.svg\0"
    "SHM Line 7 icon.svg\0"
    "Stockholm Pendeltag Logo.svg\0"
    "Stockholm commuter rail symbol 2024.svg\0"
    "Paris transit icons - Train K.svg\0"
    "Logo Saarbahn.svg\0"
    "28E CCFL.png\0"
    "Berlin transit icons - S9.svg\0"
    "M1-20px.svg\0"
    "Warsaw Metro logo.svg\0"
    "Helsingin lähiliikenteen logo.png\0"
    "Cercanías C3 (Azul).svg\0"
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
    "Budapest Tram line17 icon.svg\0"
    "RE7 VBB (2021).png\0"
    "Euskotren Tranbia.svg\0"
    "Tramway Budapest 6.svg\0"
    "Tramway Budapest 4.svg\0"
    "BKV h5 jms.svg\0"
    "Budapest hev symbol.svg\0"
    "Frankfurt U2.svg\0"
    "Tranvía Zaragoza L1.svg\0"
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
    "Toulouse line C symbol.svg\0"
    "Toulouse \"TER\" symbol.svg\0"
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
    "Nürnberg T6.svg\0"
    "Izhevsk Tram 1.svg\0"
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
    "Nürnberg S4.svg\0"
    "KVV icon tram 2.svg\0"
    "Metropolitana di Roma - logo linea A.svg\0"
    "Logo Metropolitane Italia.svg\0"
    "Metropolitana di Roma - logo linea B.svg\0"
    "Ferrovia Roma-Giardinetti.svg\0"
    "Ferrovia Roma-Lido.svg\0"
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
    "KVV icon S4.svg\0"
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
    "Tashkent metro logo.svg\0"
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
    "MetroBS logo.svg\0"
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
    "KVV icon S31.svg\0"
    "KVV icon S32.svg\0"
    "KVV icon S51.svg\0"
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
    "KVV icon S42.svg\0"
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
    "S6 Tirol (2021).svg\0"
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
    "Metropolitana di Roma - logo linea C.svg\0"
    "Linka 1 (Bratislava).svg\0"
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
    "KVV icon S41.svg\0"
    "Icon 2 (set f).png\0"
    "IC 8 logo.svg\0"
    "Hannover S51.svg\0"
    "Hannover S21.svg\0"
    "S-Bahn Salzburg.svg\0"
    "Hannover S8.svg\0"
    "Taichung Metro Green Line icon.svg\0"
    "Gvba4.svg\0"
    "Gvba12.svg\0"
    "Gvba1.svg\0"
    "Gvba2.svg\0"
    "Gvba3.svg\0"
    "Gvba5.svg\0"
    "Gvba7.svg\0"
    "Gvba19.svg\0"
    "Gvba13.svg\0"
    "Gvba14.svg\0"
    "Gvba24.svg\0"
    "Gvba17.svg\0"
    "Gvba26.svg\0"
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
    "Poznań ikona linii tramwajowej 5.png\0"
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
    "Prag Esko Logo.svg\0"
    "Cercanías C3.svg\0"
    "S1 barcelona.svg\0"
    "S2 barcelona.svg\0"
    "Line 1 (Sound Transit) icon.svg\0"
    "Hamburg RE5.svg\0"
    "Kaohsiung Rapid Transit Circular Line.svg\0"
    "Athens Suburban Railway Line 3.svg\0"
    "Hamburg S2-2023.svg\0"
    "Hamburg S5.svg\0"
    "Hamburg A1.svg\0"
    "Línia 2 de Metrovalència.svg\0"
    "Línia 9 de Metrovalència.svg\0"
    "Línia 7 de Metrovalència.svg\0"
    "S3 barcelona.svg\0"
    "S4 barcelona.svg\0"
    "R6 barcelona.svg\0"
    "R60 barcelona.svg\0"
    "R5 barcelona.svg\0"
    "R50 barcelona.svg\0"
    "Poznań ikona linii tramwajowej 17.png\0"
    "Poznań ikona linii tramwajowej 13.png\0"
    "Poznań ikona linii tramwajowej 15.png\0"
    "Poznań ikona linii tramwajowej 10.png\0"
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
    "MTR LR 614P.svg\0"
    "MTR LR 615P.svg\0"
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
    "Victoria line roundel.svg\0"
    "Underground.svg\0"
    "Icon 4 (set yellow).png\0"
    "MTR LR 505.svg\0"
    "MTR LR 507.svg\0"
    "MTR LR 610.svg\0"
    "MTR LR 615.svg\0"
    "MTR LR 614.svg\0"
    "MTR LR 751.svg\0"
    "MTR LR 761P.svg\0"
    "AubagneTram.svg\0"
    "18E CCFL.png\0"
    "MTR LR 706.svg\0"
    "MTR LR 705.svg\0"
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
    "KVV icon S81.svg\0"
    "SHM Line 1 icon.svg\0"
    "SHM Line 16 icon.svg\0"
    "SHM Line 5 icon.svg\0"
    "SHM Line 3 icon.svg\0"
    "SHM Line 6 icon.svg\0"
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
    "Central Line roundel.svg\0"
    "Paris transit icons - RER E.svg\0"
    "STIB-MIVB Line 2.svg\0"
    "GZM Line 6 icon.svg\0"
    "Euskotren E1.svg\0"
    "Berlin transit icons - S41.svg\0"
    "STIB-MIVB Line 81.svg\0"
    "Brussel S-Trein S1.svg\0"
    "Cercanías C4 (MoradoAM).svg\0"
    "Cercanías C5 (VerdeAM).svg\0"
    "S10-Tilo.svg\0"
    "Gand S-Trein S51.svg\0"
    "Liege S-Trein S44.svg\0"
    "Antwerpen S-Trein S34.svg\0"
    "Charleroi S-Trein S61.svg\0"
    "Charleroi S-Trein S62.svg\0"
    "Charleroi S-Trein S63.svg\0"
    "Antwerpen S-Trein S33.svg\0"
    "Gand S-Trein S52.svg\0"
    "Charleroi S-Trein S64.svg\0"
    "Logo-casa-T1.svg\0"
    "Logo-casa-T2.svg\0"
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
    "SHM Line 4 icon.svg\0"
    "SHM Line 8 icon.svg\0"
    "SHM Line 9 icon.svg\0"
    "SHM Line 12 icon.svg\0"
    "SHM Line 13 icon.svg\0"
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
    "Tabriz Metro Logo.svg\0"
    "NNMetro Line 2.svg\0"
    "Helsinki metro logo round edges.svg\0"
    "Helsingin metro logo.svg\0"
    "Bakerloo line roundel.svg\0"
    "H&c line roundel.svg\0"
    "Jubilee line roundel.svg\0"
    "Metropolitan line roundel.svg\0"
    "District line roundel.svg\0"
    "Logo metropolitana di Catania.svg\0"
    "Logo of Mumbai Metro Line 1.svg\0"
    "RB66 VBB (2021).png\0"
    "Astram Logo.svg\0"
    "Subway FukuokaHakozaki.svg\0"
    "Fukuoka City Subway Logo.svg\0"
    "Piccadilly line roundel.svg\0"
    "Northern line roundel.svg\0"
    "Subway FukuokaKuko.svg\0"
    "Poznań ikona linii tramwajowej 16.png\0"
    "Poznań ikona linii tramwajowej 6.png\0"
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
    "DLR roundel.svg\0"
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
    "Saburtalo Line.svg\0"
    "Metro Tbilisi logo.svg\0"
    "Akhmeteli–Varketili Line.svg\0"
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
    "RER Vaudois.png\0"
    "RB24 VBB (2021).png\0"
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
    "Thessaloniki Metro logo.svg\0"
    "TTC - Line 2 - Bloor-Danforth line.svg\0"
    "NJM Line 3 icon.svg\0"
    "SZRT Line 1 icon.svg\0"
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
    "Delhi Metro logo.svg\0"
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
    "Nürnberg T7.svg\0"
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
    "S11 S-Bahn Stuttgart Logo (2021).svg\0"
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
    "CRRT line2 logo.svg\0"
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
    "NYCS-bull-trans-SIR-Std.svg\0"
    "Icon-green-line-default.svg\0"
    "TfNSW T1.svg\0"
    "NYCS-bull-trans-M-Std.svg\0"
    "NYCS-bull-trans-L-Std.svg\0"
    "TfNSW T4.svg\0"
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
    "TfNSW T5.svg\0"
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
    "Krivoy Rog high-speed tram line 3М.svg\0"
    "Krivoy Rog high-speed tram line 2М.svg\0"
    "Krivoy Rog high-speed tram line 1M.svg\0"
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
    "SHM Line 14 icon.svg\0"
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
    "New Taipei Metro Line Y.svg\0"
    "S3 Steiermark.svg\0"
    "S6 Steiermark.svg\0"
    "Milano linea M2.svg\0"
    "Milano linea M3.svg\0"
    "Suin-Bundang Line.svg\0"
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
    "长沙地铁5号线线标.svg\0"
    "Sofia-metro-lines-03.svg\0"
    "Icon-green-line-b-default.svg\0"
    "Icon-green-line-c-default.svg\0"
    "Cercanías C3 (Rojo).svg\0"
    "Cercanías C4 (Morado).svg\0"
    "Cercanías C5 (Azul oscuro).svg\0"
    "Milano S7.svg\0"
    "Indian Railways Suburban Railway Logo.svg\0"
    "Cercanías C1a.svg\0"
    "Number prefix Keikyū.PNG\0"
    "ShenzhenMetroLine6.svg\0"
    "ShenzhenMetroLine10.svg\0"
    "R1 barcelona.svg\0"
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
    "Gvba25.svg\0"
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
    "Nürnberg S6.svg\0"
    "Bayern RE 31.svg\0"
    "Bayern RE 32.svg\0"
    "Bayern RE 35.svg\0"
    "Bayern RB 18.svg\0"
    "Paris transit icons - Tram 9.svg\0"
    "Sofia-metro-lines-04.svg\0"
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
    "Mitteldeutschland S7.svg\0"
    "WX Metro Line 4 icon.svg\0"
    "Mitteldeutschland S47.svg\0"
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
    "Mmmocl-logo-cropped.svg\0"
    "Maha Mumbai Metro.png\0"
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
    "KRT Line 5 icon.svg\0"
    "TAM-5.svg\0"
    "File S5 Kärnten.svg\0"
    "RE80-Tilo.svg\0"
    "Paris transit icons - Tram 12.svg\0"
    "Icon of FZM L6.svg\0"
    "S90-Tilo.svg\0"
    "S20-Tilo.svg\0"
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
    "Bayern S7 St Gallen.svg\0"
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
    "长株潭城际西环线.svg\0"
    "XAM Line 16 icon.svg\0"
    "Logo Réseau express métropolitain.svg\0"
    "O-Train Line 2.svg\0"
    "Moskwa Metro Line D3.svg\0"
    "Dankal Logo.svg\0"
    "STIB-MIVB Line 18.svg\0"
    "Moskwa Metro Line D4.svg\0"
    "RheinNeckar S8.svg\0"
    "RheinNeckar S7.svg\0"
    "RheinNeckar S39.svg\0"
    "Cercanías C5a (VerdeAM).svg\0"
    "NaviMumbaiMetro-Logo.png\0"
    "Izhevsk Tram 5.svg\0"
    "Gvba27.svg\0"
    "Kayseri public transport - T4 symbol.svg\0"
    "CDML19.svg\0"
    "Paris transit icons - Train V.svg\0"
    "Icono ER02.svg\0"
    "Nürnberg T11.svg\0"
    "Nürnberg T10.svg\0"
    "Lima Metro Linea 2 logo.svg\0"
    "Bayern RB 40 Erfurt.svg\0"
    "HCMC Metro logo.svg\0"
    "Bayern RB 40.svg\0"
    "Bayern RB 33.svg\0"
    "UPMRC.svg\0"
    "CCRT Line6 logo.svg\0"
    "Mitja distància Ca6.svg\0"
    "Hiroden Logomark.svg\0"
    "Santiago de Chile L7.svg\0"
    "Santiago de Chile L9.svg\0"
    "Liege S-Trein S42.svg\0"
    "SZRT Line 6 icon.svg\0"
    "Logo of Mumbai Metro Line 3.png\0"
    "Moskwa Metro Line 16.svg\0"
    "SZRT Line 8 icon.svg\0"
    "STIB-MIVB Line 10.svg\0"
    "Istanbul T7 Line Symbol.svg\0"
    "Logo-casa-T4-indice.svg\0"
    "Logo-casa-T3-indice.svg\0"
    "Izhevsk Tram 12.svg\0"
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
    { 46, 196, 226, LineMetaDataContent::RapidTransit, Color{0x8070b7} }, // S7 OSM: 14809 WD: Q7388362 52.39, 13.07 x 52.57, 13.57
    { 4, 242, 226, LineMetaDataContent::RapidTransit, Color{0x8070b7} }, // S75 OSM: 14810 WD: Q3744483 52.5, 13.43 x 52.57, 13.54
    { 52, 273, 226, LineMetaDataContent::RapidTransit, Color{0xf25721} }, // S5 OSM: 14811 WD: Q3743008 52.5, 13.28 x 52.59, 13.91
    { 55, 303, 226, LineMetaDataContent::RapidTransit, Color{0x52b447} }, // S8 OSM: 14984 WD: Q4048678 52.35, 13.29 x 52.69, 13.63
    { 59, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x9313ba} }, // S2 OSM: 16111 48.95, 8.283 x 49.11, 8.505
    { 64, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xb3ee3a} }, // 1 OSM: 17413 WD: Q120801440 51.49, 10.79 x 51.52, 10.8
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x2e8b57} }, // 2 OSM: 17415 WD: Q120804196 51.5, 10.78 x 51.51, 10.82
    { 68, 333, NoLogo, LineMetaDataContent::Tramway, Color{0x996633} }, // 3 OSM: 17839 WD: Q121359743 48.99, 8.295 x 49.02, 8.444
    { 64, 353, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 1 OSM: 17840 WD: Q121359727 49, 8.347 x 49.04, 8.479
    { 62, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // S11 OSM: 17842 48.87, 8.373 x 49.13, 8.518
    { 71, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // S1 OSM: 17843 48.8, 8.373 x 49.13, 8.458
    { 6, 373, NoLogo, LineMetaDataContent::Tramway, Color{0x18a6d9} }, // 5 OSM: 17847 WD: Q121359745 49, 8.347 x 49.02, 8.463
    { 9, 393, NoLogo, LineMetaDataContent::Tramway, Color{0xffcc00} }, // 4 OSM: 17848 WD: Q121359744 48.98, 8.347 x 49.05, 8.452
    { 55, 413, NoLogo, LineMetaDataContent::RapidTransit, Color{0x6d682a} }, // S8 OSM: 17849 WD: Q112623864 48.44, 8.215 x 49.01, 8.83
    { 19, 429, NoLogo, LineMetaDataContent::Tramway, Color{0xff9933} }, // 8 OSM: 17855 WD: Q121359748 48.98, 8.452 x 49, 8.479
    { 74, 449, 19, LineMetaDataContent::Tramway, Color{0xbe1414} }, // M10 OSM: 17865 WD: Q62500489 52.5, 13.34 x 52.54, 13.45
    { 66, 469, 19, LineMetaDataContent::Tramway, Color{0xbe1414} }, // M13 OSM: 17884 WD: Q62512599 52.51, 13.34 x 52.56, 13.48
    { 82, 489, 19, LineMetaDataContent::Tramway, Color{0x996699} }, // 21 OSM: 17885 WD: Q62476959 52.45, 13.45 x 52.53, 13.52
    { 85, 508, 526, LineMetaDataContent::RapidTransit, Color{0xeda5b4} }, // U13 OSM: 19070 WD: Q70718526 48.76, 9.134 x 48.81, 9.254
    { 90, 555, 19, LineMetaDataContent::Tramway, Color{0x009999} }, // 63 OSM: 19115 WD: Q63996601 52.43, 13.53 x 52.5, 13.61
    { 94, 574, 19, LineMetaDataContent::Tramway, Color{0x669933} }, // 61 OSM: 19265 WD: Q62512736 52.43, 13.51 x 52.46, 13.69
    { 98, 593, 19, LineMetaDataContent::Tramway, Color{0x009933} }, // 68 OSM: 19271 WD: Q62470539 52.37, 13.57 x 52.46, 13.65
    { 105, 612, 19, LineMetaDataContent::Tramway, Color{0x006633} }, // 62 OSM: 19296 WD: Q62476843 52.42, 13.57 x 52.51, 13.61
    { 110, 631, 19, LineMetaDataContent::Tramway, Color{0x993333} }, // 37 OSM: 19451 WD: Q62499413 52.45, 13.5 x 52.53, 13.53
    { 114, NoLogo, 650, LineMetaDataContent::Tramway, Color{} }, // 88 OSM: 19597 WD: Q638246 52.46, 13.63 x 52.48, 13.81
    { 63, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 11 OSM: 19762 WD: Q108783975 42.66, 23.24 x 42.75, 23.32
    { 118, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 22 OSM: 19763 WD: Q108783982 42.69, 23.28 x 42.7, 23.39
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 12 OSM: 19765 WD: Q108783976 42.68, 23.31 x 42.75, 23.33
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 8 OSM: 19766 WD: Q108783965 42.69, 23.24 x 42.72, 23.32
    { 75, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 10 OSM: 19768 WD: Q108783971 42.66, 23.28 x 42.7, 23.34
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 6 OSM: 19771 WD: Q108783961 42.68, 23.27 x 42.75, 23.32
    { 68, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 3 OSM: 19777 WD: Q108783914 42.7, 23.29 x 42.73, 23.32
    { 47, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 7 OSM: 19782 WD: Q108783862 42.66, 23.28 x 42.72, 23.32
    { 64, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 1 OSM: 19787 WD: Q108783893 42.68, 23.3 x 42.71, 23.32
    { 121, 668, 526, LineMetaDataContent::RapidTransit, Color{0xc7956c} }, // U1 OSM: 19916 WD: Q106879557 48.75, 9.138 x 48.81, 9.277
    { 124, 685, 526, LineMetaDataContent::RapidTransit, Color{0xf58220} }, // U2 OSM: 19917 WD: Q106879558 48.77, 9.122 x 48.83, 9.238
    { 127, 702, 526, LineMetaDataContent::RapidTransit, Color{0x935f39} }, // U3 OSM: 19918 WD: Q106879559 48.71, 9.112 x 48.73, 9.202
    { 130, 719, 526, LineMetaDataContent::RapidTransit, Color{0x7a68ae} }, // U4 OSM: 19919 WD: Q106879560 48.77, 9.158 x 48.79, 9.25
    { 133, 736, 526, LineMetaDataContent::RapidTransit, Color{0x00baf2} }, // U5 OSM: 19920 WD: Q106879561 48.69, 9.136 x 48.8, 9.187
    { 136, 753, 526, LineMetaDataContent::RapidTransit, Color{0xec008c} }, // U6 OSM: 19921 WD: Q106879562 48.69, 9.064 x 48.81, 9.192
    { 139, 770, 526, LineMetaDataContent::RapidTransit, Color{0x0eb48d} }, // U7 OSM: 19922 WD: Q106879563 48.71, 9.173 x 48.84, 9.296
    { 142, 787, 526, LineMetaDataContent::RapidTransit, Color{0xc3b47d} }, // U8 OSM: 19923 WD: Q106879564 48.71, 9.112 x 48.76, 9.296
    { 145, 804, 526, LineMetaDataContent::RapidTransit, Color{0xffd503} }, // U9 OSM: 19924 WD: Q106879565 48.76, 9.122 x 48.79, 9.254
    { 75, 821, 526, LineMetaDataContent::Tramway, Color{0xf8b710} }, // 10 OSM: 19925 WD: Q143861 48.75, 9.167 x 48.76, 9.174
    { 148, 846, 526, LineMetaDataContent::RapidTransit, Color{0xcccccc} }, // U11 OSM: 19926 WD: Q106879566 48.77, 9.168 x 48.8, 9.226
    { 14, 864, 526, LineMetaDataContent::RapidTransit, Color{0x93bbe9} }, // U12 OSM: 19927 WD: Q106879567 48.72, 9.118 x 48.87, 9.271
    { 152, 882, 526, LineMetaDataContent::RapidTransit, Color{0x69be51} }, // U14 OSM: 19928 WD: Q70723042 48.73, 9.111 x 48.84, 9.23
    { 156, 900, 526, LineMetaDataContent::RapidTransit, Color{0x005aab} }, // U15 OSM: 19929 WD: Q106879570 48.74, 9.156 x 48.85, 9.234
    { 160, 918, 526, LineMetaDataContent::RapidTransit, Color{0xcccccc} }, // U19 OSM: 19930 WD: Q106879572 48.79, 9.213 x 48.83, 9.238
    { 75, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x312783} }, // 10 OSM: 19941 WD: Q112609299 53.06, 8.752 x 53.12, 8.9
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x005ca9} }, // 2 OSM: 19942 WD: Q112609282 53.06, 8.752 x 53.12, 8.9
    { 165, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x9eb4a5} }, // 72 OSM: 20258 WD: Q6811968 -37.86, 145 x -37.8, 145.1
    { 170, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc4121a} }, // 49 OSM: 20313 WD: Q47545799 48.2, 16.26 x 48.21, 16.36
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc4121a} }, // 6 OSM: 20838 WD: Q47545889 48.17, 16.34 x 48.2, 16.4
    { 64, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc4121a} }, // 1 OSM: 20839 WD: Q17348925 48.17, 16.35 x 48.22, 16.41
    { 22, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc4121a} }, // 18 OSM: 20840 WD: Q47563623 48.18, 16.34 x 48.2, 16.41
    { 146, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc4121a} }, // 9 OSM: 21046 WD: Q47545921 48.2, 16.32 x 48.23, 16.34
    { 174, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc4121a} }, // 52 OSM: 21047 WD: Q47545789 48.19, 16.27 x 48.2, 16.34
    { 75, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc4121a} }, // 10 OSM: 21055 WD: Q47563295 48.19, 16.28 x 48.23, 16.32
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf287b6} }, // 2 OSM: 22852 WD: Q56558793 54.09, 12.08 x 54.11, 12.17
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf8a500} }, // 6 OSM: 22871 WD: Q56558799 54.07, 12.09 x 54.09, 12.14
    { 64, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x5d106a} }, // 1 OSM: 23389 WD: Q56558792 54.09, 12.05 x 54.16, 12.16
    { 178, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc4121a} }, // 44 OSM: 23620 WD: Q47630524 48.21, 16.31 x 48.22, 16.36
    { 68, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x690713} }, // 3 OSM: 23742 WD: Q56558795 54.07, 12.09 x 54.11, 12.18
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc30175} }, // 4 OSM: 23743 WD: Q56558796 54.07, 12.1 x 54.11, 12.18
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe2001d} }, // 5 OSM: 23747 WD: Q56558797 54.06, 12.05 x 54.16, 12.14
    { 182, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc4121a} }, // 60 OSM: 26608 WD: Q47657489 48.13, 16.26 x 48.2, 16.34
    { 130, 936, 948, LineMetaDataContent::Subway, Color{0x029540} }, // U4 OSM: 27113 WD: Q877322 48.18, 16.26 x 48.25, 16.39
    { 136, 964, 948, LineMetaDataContent::Subway, Color{0x9c6830} }, // U6 OSM: 27115 WD: Q281409 48.13, 16.31 x 48.26, 16.4
    { 186, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc4121a} }, // O OSM: 27148 WD: Q20439830 48.17, 16.36 x 48.23, 16.39
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc4121a} }, // 5 OSM: 27149 WD: Q20439827 48.2, 16.34 x 48.23, 16.39
    { 0, NoLogo, 976, LineMetaDataContent::Subway, Color{0x70b1d0} }, // U70 OSM: 27662 WD: Q121295965 51.22, 6.566 x 51.33, 6.803
    { 188, NoLogo, 976, LineMetaDataContent::Subway, Color{0x0063af} }, // U76 OSM: 27663 WD: Q121295971 51.17, 6.566 x 51.33, 6.834
    { 192, NoLogo, 976, LineMetaDataContent::Subway, Color{0x7197cf} }, // U77 OSM: 27667 WD: Q121295972 51.21, 6.735 x 51.24, 6.823
    { 196, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe94190} }, // 709 OSM: 27956 WD: Q121297876 51.19, 6.684 x 51.25, 6.855
    { 200, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xbd1616} }, // 704 OSM: 27957 WD: Q121297871 51.2, 6.78 x 51.25, 6.797
    { 204, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x7e1974} }, // 707 OSM: 27999 WD: Q121297874 51.21, 6.746 x 51.28, 6.793
    { 213, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf29eb7} }, // 708 OSM: 28000 WD: Q121297875 51.22, 6.765 x 51.25, 6.803
    { 217, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf07d00} }, // 701 OSM: 28049 WD: Q4461914 51.2, 6.778 x 51.27, 6.847
    { 221, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe30613} }, // 706 OSM: 28052 WD: Q121297873 51.2, 6.739 x 51.24, 6.812
    { 182, 990, 19, LineMetaDataContent::Tramway, Color{0x0b9ada} }, // 60 OSM: 28289 WD: Q62512766 52.44, 13.5 x 52.46, 13.64
    { 225, 1009, 226, LineMetaDataContent::RapidTransit, Color{0x055a99} }, // S3 OSM: 28314 WD: Q7388282 52.43, 13.2 x 52.53, 13.75
    { 231, 1039, 19, LineMetaDataContent::Tramway, Color{0x009933} }, // 67 OSM: 28352 WD: Q66459350 52.44, 13.51 x 52.46, 13.59
    { 235, 1058, 19, LineMetaDataContent::Tramway, Color{0x993333} }, // 27 OSM: 28377 WD: Q66091843 52.44, 13.46 x 52.56, 13.59
    { 238, 1077, 19, LineMetaDataContent::Tramway, Color{0xa6422a} }, // M17 OSM: 28391 WD: Q62512560 52.43, 13.51 x 52.57, 13.54
    { 243, 1097, 19, LineMetaDataContent::Tramway, Color{0xbe1414} }, // 50 OSM: 28420 WD: Q62499869 52.54, 13.34 x 52.61, 13.43
    { 246, NoLogo, 976, LineMetaDataContent::Subway, Color{0x009a93} }, // U79 OSM: 28424 WD: Q1272295 51.19, 6.739 x 51.47, 6.815
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 5 OSM: 29322 WD: Q108783922 42.66, 23.24 x 42.7, 23.32
    { 251, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 20 OSM: 29391 WD: Q108783981 42.66, 23.31 x 42.7, 23.42
    { 82, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x945692} }, // 21 OSM: 29440 WD: Q4415661 51.91, 4.368 x 51.94, 4.525
    { 255, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x945692} }, // 24 OSM: 29446 WD: Q14500289 51.91, 4.341 x 51.94, 4.525
    { 259, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc4121a} }, // 43 OSM: 29564 WD: Q47630223 48.21, 16.29 x 48.23, 16.36
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0777c1} }, // 6 OSM: 30058 WD: Q122395004 49.17, 16.55 x 49.23, 16.61
    { 110, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc4121a} }, // 37 OSM: 31353 WD: Q47566702 48.21, 16.35 x 48.25, 16.36
    { 262, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc4121a} }, // 38 OSM: 31355 WD: Q47566941 48.21, 16.34 x 48.26, 16.36
    { 266, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc4121a} }, // 42 OSM: 32332 WD: Q47629937 48.21, 16.33 x 48.23, 16.36
    { 270, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc4121a} }, // 41 OSM: 32333 WD: Q47629601 48.21, 16.31 x 48.24, 16.36
    { 274, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc4121a} }, // 40 OSM: 32334 WD: Q47629313 48.21, 16.32 x 48.23, 16.36
    { 63, NoLogo, 19, LineMetaDataContent::Tramway, Color{0xd62631} }, // 11 OSM: 33897 WD: Q121350810 51.28, 12.22 x 51.4, 12.4
    { 75, NoLogo, 19, LineMetaDataContent::Tramway, Color{0xd62631} }, // 10 OSM: 33900 WD: Q121350630 51.3, 12.32 x 51.37, 12.4
    { 26, NoLogo, 19, LineMetaDataContent::Tramway, Color{0xe3000f} }, // 16 OSM: 34068 WD: Q121351163 51.3, 12.38 x 51.4, 12.4
    { 277, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x005395} }, // WLB OSM: 34086 WD: Q875199 48, 16.23 x 48.2, 16.37
    { 47, NoLogo, 19, LineMetaDataContent::Tramway, Color{0x0e4094} }, // 7 OSM: 34148 WD: Q121345153 51.34, 12.27 x 51.36, 12.48
    { 98, NoLogo, 976, LineMetaDataContent::Tramway, Color{0xcea4cb} }, // 68 OSM: 34480 WD: Q20035838 50.7, 6.985 x 50.76, 7.156
    { 71, 1116, 226, LineMetaDataContent::RapidTransit, Color{0x5c8e3c} }, // S1 OSM: 35610 WD: Q18946157 48.59, 8.861 x 48.8, 9.444
    { 59, 1152, 226, LineMetaDataContent::RapidTransit, Color{0xff2e1d} }, // S2 OSM: 35611 WD: Q66537943 48.68, 9.105 x 48.83, 9.527
    { 225, 1188, 226, LineMetaDataContent::RapidTransit, Color{0xff7d24} }, // S3 OSM: 35612 WD: Q67504621 48.69, 9.105 x 48.94, 9.426
    { 146, NoLogo, 976, LineMetaDataContent::Tramway, Color{0xe6877e} }, // 9 OSM: 36132 WD: Q63442544 50.92, 6.907 x 50.94, 7.096
    { 15, NoLogo, 976, LineMetaDataContent::Tramway, Color{0x8cc63f} }, // 12 OSM: 36133 WD: Q63442549 50.9, 6.939 x 51.03, 6.96
    { 157, NoLogo, 976, LineMetaDataContent::Tramway, Color{0x54ad4b} }, // 15 OSM: 36134 WD: Q63442560 50.92, 6.898 x 51.02, 6.966
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc4121a} }, // 2 OSM: 36362 WD: Q47545833 48.2, 16.31 x 48.24, 16.39
    { 283, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc4121a} }, // D OSM: 36371 WD: Q901027 48.18, 16.36 x 48.26, 16.39
    { 289, NoLogo, 1224, LineMetaDataContent::Tramway, Color{0xcf0a1d} }, // T1 OSM: 36937 WD: Q112391133 37.38, -5.996 x 37.39, -5.977
    { 295, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x83898f} }, // 58 OSM: 37338 WD: Q28428375 -37.84, 144.9 x -37.74, 145
    { 298, 1241, 226, LineMetaDataContent::RapidTransit, Color{0x874a0a} }, // S6 OSM: 37419 WD: Q67501804 48.76, 8.872 x 48.83, 9.195
    { 302, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc4121a} }, // 46 OSM: 38368 WD: Q47631053 48.21, 16.3 x 48.21, 16.36
    { 63, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc4121a} }, // 11 OSM: 38482 WD: Q70516548 48.15, 16.35 x 48.18, 16.47
    { 289, NoLogo, 1277, LineMetaDataContent::Tramway, Color{0xff0000} }, // T1 OSM: 38872 WD: Q5985908 28.45, -16.32 x 28.49, -16.25
    { 157, NoLogo, 19, LineMetaDataContent::Tramway, Color{0x0e4094} }, // 15 OSM: 38883 WD: Q98379997 51.29, 12.26 x 51.34, 12.44
    { 306, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc8d300} }, // 65 OSM: 39079 WD: Q20035842 50.72, 7.071 x 50.76, 7.156
    { 27, 1315, NoLogo, LineMetaDataContent::Tramway, Color{0x9049a8} }, // 6 OSM: 48024 WD: Q62296933 52.13, 11.57 x 52.15, 11.68
    { 64, 1343, NoLogo, LineMetaDataContent::Tramway, Color{0xb6005c} }, // 1 OSM: 48025 WD: Q62289804 52.11, 11.59 x 52.17, 11.64
    { 9, 1371, NoLogo, LineMetaDataContent::Tramway, Color{0x73e700} }, // 4 OSM: 48453 WD: Q62295350 52.11, 11.58 x 52.16, 11.67
    { 6, 1399, NoLogo, LineMetaDataContent::Tramway, Color{0xb48654} }, // 5 OSM: 48459 WD: Q62296384 52.09, 11.58 x 52.16, 11.62
    { 310, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc4121a} }, // 71 OSM: 51076 WD: Q42297591 48.15, 16.36 x 48.22, 16.47
    { 279, 1427, 1449, LineMetaDataContent::RapidTransit, Color{0x32cd32} }, // B OSM: 51750 WD: Q1903862 55.65, 12.27 x 55.81, 12.59
    { 64, NoLogo, 19, LineMetaDataContent::Tramway, Color{0x62b32c} }, // 1 OSM: 51858 WD: Q121343878 51.31, 12.26 x 51.35, 12.41
    { 136, 1459, 1489, LineMetaDataContent::Subway, Color{0x8c6dab} }, // U6 OSM: 51942 WD: Q99720 52.44, 13.33 x 52.56, 13.39
    { 64, 1500, NoLogo, LineMetaDataContent::Tramway, Color{0xffffff} }, // 1 OSM: 52282 WD: Q106921117 57.64, 11.9 x 57.73, 12.05
    { 6, 1522, NoLogo, LineMetaDataContent::Tramway, Color{0xeb1923} }, // 5 OSM: 52617 WD: Q106921184 57.7, 11.89 x 57.74, 12.05
    { 47, 1544, NoLogo, LineMetaDataContent::Tramway, Color{0x7d4313} }, // 7 OSM: 53027 WD: Q10562726 57.64, 11.9 x 57.76, 12.07
    { 55, 1566, 226, LineMetaDataContent::RapidTransit, Color{0xffc734} }, // S8 OSM: 53231 WD: Q17148488 48, 11.17 x 48.35, 11.79
    { 314, 1582, 226, LineMetaDataContent::RapidTransit, Color{0xff2d1d} }, // S4 OSM: 53235 WD: Q7388308 48.04, 11.04 x 48.18, 11.97
    { 27, 1598, NoLogo, LineMetaDataContent::Tramway, Color{0xfa8719} }, // 6 OSM: 53254 WD: Q10562724 57.68, 11.89 x 57.76, 12.04
    { 146, 1620, NoLogo, LineMetaDataContent::Tramway, Color{0x1e8164} }, // 9 OSM: 53748 WD: Q62299846 52.08, 11.6 x 52.18, 11.64
    { 16, 1648, NoLogo, LineMetaDataContent::Tramway, Color{0x004799} }, // 2 OSM: 53752 WD: Q62291398 52.06, 11.63 x 52.15, 11.68
    { 19, 1676, NoLogo, LineMetaDataContent::Tramway, Color{0xf29400} }, // 8 OSM: 53770 WD: Q62299313 52.06, 11.63 x 52.18, 11.68
    { 298, 1704, NoLogo, LineMetaDataContent::RapidTransit, Color{0x3d2d7c} }, // S6 OSM: 53844 WD: Q106378407 48.75, 8.549 x 48.9, 8.705
    { 318, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc4121a} }, // 26 OSM: 53994 WD: Q47564171 48.23, 16.38 x 48.29, 16.49
    { 75, 1720, NoLogo, LineMetaDataContent::Tramway, Color{0xaac1e1} }, // 10 OSM: 54125 WD: Q62288523 52.11, 11.59 x 52.21, 11.67
    { 75, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x9acd32} }, // 10 OSM: 54452 WD: Q116487045 51.49, 10.77 x 51.58, 10.8
    { 64, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xda0873} }, // 1 OSM: 54602 WD: Q121360083 53.59, 11.41 x 53.65, 11.47
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xd9261c} }, // 2 OSM: 54603 WD: Q121360084 53.59, 11.36 x 53.65, 11.47
    { 68, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe87878} }, // 3 OSM: 54604 WD: Q121360085 53.57, 11.38 x 53.6, 11.47
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xdb214c} }, // 4 OSM: 54605 WD: Q121360086 53.57, 11.38 x 53.65, 11.43
    { 68, 1749, NoLogo, LineMetaDataContent::Tramway, Color{0xffd600} }, // 3 OSM: 55097 WD: Q62292031 52.09, 11.58 x 52.16, 11.63
    { 321, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x408040} }, // S 1 OSM: 55107 WD: Q56378592 52, 11.62 x 53.01, 11.87
    { 105, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc4121a} }, // 62 OSM: 56814 WD: Q47671923 48.16, 16.27 x 48.2, 16.37
    { 52, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // S5 OSM: 56923 WD: Q319443 48.03, 7.589 x 48.16, 7.77
    { 145, 1777, 1489, LineMetaDataContent::Subway, Color{0xf3791d} }, // U9 OSM: 58423 WD: Q99744 52.46, 13.32 x 52.56, 13.37
    { 142, 1807, 1489, LineMetaDataContent::Subway, Color{0x224f86} }, // U8 OSM: 58424 WD: Q99729 52.47, 13.33 x 52.6, 13.43
    { 139, 1837, 1489, LineMetaDataContent::Subway, Color{0x528dba} }, // U7 OSM: 58425 WD: Q99725 52.42, 13.2 x 52.54, 13.5
    { 127, 1867, 1489, LineMetaDataContent::Subway, Color{0x16683d} }, // U3 OSM: 58426 WD: Q99702 52.44, 13.24 x 52.51, 13.45
    { 124, 1897, 1489, LineMetaDataContent::Subway, Color{0xda421e} }, // U2 OSM: 58428 WD: Q99697 52.5, 13.24 x 52.57, 13.41
    { 130, 1927, 1489, LineMetaDataContent::Subway, Color{0xf0d722} }, // U4 OSM: 58429 WD: Q99708 52.48, 13.34 x 52.5, 13.36
    { 133, 1957, 1489, LineMetaDataContent::Subway, Color{0x7e5330} }, // U5 OSM: 58430 WD: Q99711 52.49, 13.37 x 52.54, 13.63
    { 121, 1987, 1489, LineMetaDataContent::Subway, Color{0x7dad4c} }, // U1 OSM: 58767 WD: Q99691 52.5, 13.33 x 52.51, 13.45
    { 19, NoLogo, 19, LineMetaDataContent::Tramway, Color{0xffcc00} }, // 8 OSM: 58819 WD: Q121345179 51.32, 12.28 x 51.36, 12.47
    { 68, NoLogo, 19, LineMetaDataContent::Tramway, Color{0x62b32c} }, // 3 OSM: 58829 WD: Q121344175 51.31, 12.28 x 51.38, 12.49
    { 6, 2017, 2034, LineMetaDataContent::Tramway, Color{0x8b539d} }, // 5 OSM: 61453 WD: Q104867893 49.41, 11.07 x 49.46, 11.14
    { 239, 2058, 19, LineMetaDataContent::Tramway, Color{0x865a46} }, // 17 OSM: 61454 WD: Q20438593 48.13, 11.49 x 48.17, 11.57
    { 161, 2079, 19, LineMetaDataContent::Tramway, Color{0xdc281e} }, // 19 OSM: 61456 WD: Q20438608 48.14, 11.46 x 48.15, 11.63
    { 22, 2100, 19, LineMetaDataContent::Tramway, Color{0x00a03c} }, // 18 OSM: 61458 WD: Q20438601 48.1, 11.49 x 48.14, 11.6
    { 325, NoLogo, 19, LineMetaDataContent::Tramway, Color{0x865a46} }, // N17 OSM: 61459 WD: Q123336308 48.13, 11.56 x 48.15, 11.61
    { 64, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf78a21} }, // 1 OSM: 61460 WD: Q121304774 50.85, 12.07 x 50.89, 12.09
    { 59, 2121, 226, LineMetaDataContent::RapidTransit, Color{0x018a47} }, // S2 OSM: 61466 WD: Q3743635 52.34, 13.36 x 52.68, 13.59
    { 329, 2151, 226, LineMetaDataContent::RapidTransit, Color{0x018a47} }, // S25 OSM: 61469 WD: Q7388229 52.4, 13.21 x 52.64, 13.4
    { 127, 2182, 1489, LineMetaDataContent::Subway, Color{0xfcdf00} }, // U3 OSM: 62839 WD: Q781351 53.54, 9.969 x 53.59, 10.08
    { 334, 2197, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe18813} }, // J OSM: 63222 WD: Q6109356 37.72, -122.4 x 37.79, -122.4
    { 337, 2215, NoLogo, LineMetaDataContent::Tramway, Color{0xf0e68c} }, // F OSM: 63224 WD: Q1137818 37.76, -122.4 x 37.81, -122.4
    { 340, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc4121a} }, // 33 OSM: 63565 WD: Q47566422 48.21, 16.34 x 48.24, 16.38
    { 71, 2243, 226, LineMetaDataContent::RapidTransit, Color{0x36caec} }, // S1 OSM: 63809 WD: Q7388207 48.13, 11.48 x 48.4, 11.79
    { 298, 2259, 226, LineMetaDataContent::RapidTransit, Color{0x00ac6f} }, // S6 OSM: 63839 WD: Q7388348 47.91, 11.27 x 48.15, 11.97
    { 68, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff7f00} }, // 3 OSM: 63875 WD: Q121287743 51.82, 12.18 x 51.84, 12.24
    { 301, 2275, 226, LineMetaDataContent::RapidTransit, Color{0xba8a4d} }, // S46 OSM: 64094 WD: Q3737194 52.3, 13.28 x 52.52, 13.64
    { 343, 2309, 226, LineMetaDataContent::RapidTransit, Color{0xba8a4d} }, // S45 OSM: 64095 WD: Q2090939 52.36, 13.36 x 52.48, 13.57
    { 330, 2340, 19, LineMetaDataContent::Tramway, Color{0xe6828c} }, // 25 OSM: 66008 WD: Q20439051 48.04, 11.52 x 48.14, 11.6
    { 15, 2361, 19, LineMetaDataContent::Tramway, Color{0x903f98} }, // 12 OSM: 66043 WD: Q20438570 48.15, 11.49 x 48.17, 11.58
    { 26, 2382, 19, LineMetaDataContent::Tramway, Color{0x006cb2} }, // 16 OSM: 66044 WD: Q20438583 48.13, 11.51 x 48.18, 11.64
    { 235, 2403, 19, LineMetaDataContent::Tramway, Color{0xf0a014} }, // 27 OSM: 66053 WD: Q20439073 48.13, 11.56 x 48.18, 11.58
    { 251, 2424, 19, LineMetaDataContent::Tramway, Color{0x00aadc} }, // 20 OSM: 66079 WD: Q20438843 48.14, 11.51 x 48.18, 11.56
    { 82, 2445, 19, LineMetaDataContent::Tramway, Color{0x00aadc} }, // 21 OSM: 66080 WD: Q20439015 48.12, 11.53 x 48.17, 11.64
    { 349, 2473, 19, LineMetaDataContent::Tramway, Color{0x96c81e} }, // 23 OSM: 66100 WD: Q20439033 48.16, 11.59 x 48.19, 11.59
    { 352, 2494, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe67310} }, // A3 OSM: 66588 WD: Q19606155 53.75, 9.656 x 53.8, 9.983
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 4 OSM: 66741 WD: Q121338665 49.77, 9.893 x 49.8, 9.94
    { 314, 2509, 226, LineMetaDataContent::RapidTransit, Color{0x0065b7} }, // S4 OSM: 66840 WD: Q67504669 48.77, 9.155 x 48.95, 9.426
    { 355, 2545, 2564, LineMetaDataContent::RapidTransit, Color{0x8d1d81} }, // S51 OSM: 67184 WD: Q116125186 46.7, 15.63 x 46.73, 15.99
    { 360, 2583, 19, LineMetaDataContent::Tramway, Color{0xbe1414} }, // M1 OSM: 67233 WD: Q62512139 52.52, 13.37 x 52.6, 13.41
    { 52, 2602, 226, LineMetaDataContent::RapidTransit, Color{0x00b7e1} }, // S5 OSM: 67283 WD: Q18926034 48.77, 9.122 x 48.95, 9.195
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x1074bc} }, // 4 OSM: 68612 WD: Q124656079 49.86, 8.555 x 49.9, 8.683
    { 68, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf59e00} }, // 3 OSM: 69178 WD: Q121310314 47.97, 7.796 x 48, 7.85
    { 64, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe8001b} }, // 1 OSM: 69191 WD: Q121309531 47.98, 7.808 x 48.03, 7.895
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008bc5} }, // 5 OSM: 69199 WD: Q121310770 47.99, 7.788 x 48, 7.852
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x13a538} }, // 2 OSM: 69202 WD: Q121310201 47.96, 7.833 x 48.02, 7.858
    { 367, NoLogo, 2638, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // Blue OSM: 71390 WD: Q6714611 45.49, -123 x 45.54, -122.4
    { 372, NoLogo, 2638, LineMetaDataContent::RapidTransit, Color{0xffff00} }, // Yellow OSM: 71397 WD: Q6714624 45.51, -122.7 x 45.61, -122.7
    { 379, NoLogo, 2638, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // Red OSM: 71404 WD: Q6714623 45.49, -122.9 x 45.59, -122.6
    { 62, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // S11 OSM: 71595 47.86, 7.701 x 48.16, 8.504
    { 225, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // S3 OSM: 71656 WD: Q895607 47.85, 7.698 x 48, 7.843
    { 64, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf6a6ab} }, // 1 OSM: 71785 WD: Q106996879 47.25, 11.39 x 47.28, 11.41
    { 68, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xd66775} }, // 3 OSM: 71787 WD: Q106996895 47.26, 11.39 x 47.27, 11.43
    { 383, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xee1d23} }, // 501 OSM: 72291 WD: Q3238944 43.59, -79.54 x 43.67, -79.28
    { 387, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xee1d23} }, // 503 OSM: 72293 WD: Q4639788 43.65, -79.38 x 43.68, -79.28
    { 9, 2658, 2034, LineMetaDataContent::Tramway, Color{0xf3898f} }, // 4 OSM: 72527 WD: Q104867838 49.43, 11.05 x 49.49, 11.07
    { 19, 2675, 2034, LineMetaDataContent::Tramway, Color{0x00bbfe} }, // 8 OSM: 73226 WD: Q104868033 49.43, 11.08 x 49.47, 11.14
    { 64, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfbba00} }, // 1 OSM: 73662 WD: Q61888705 51.45, 11.94 x 51.51, 11.99
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff9900} }, // 2 OSM: 73667 WD: Q61889098 51.43, 11.89 x 51.49, 11.99
    { 68, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0066cc} }, // 3 OSM: 73670 WD: Q61887067 51.43, 11.96 x 51.52, 11.99
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x9b1006} }, // 4 OSM: 73671 WD: Q61889270 51.44, 11.93 x 51.51, 11.99
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0f3f93} }, // 5 OSM: 73672 WD: Q61889316 51.29, 11.93 x 51.51, 12.07
    { 47, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff6699} }, // 7 OSM: 73929 WD: Q61889355 51.48, 11.93 x 51.51, 12.04
    { 146, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x999933} }, // 9 OSM: 73932 WD: Q61889418 51.48, 11.89 x 51.48, 11.99
    { 75, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x336633} }, // 10 OSM: 73933 WD: Q61889438 51.48, 11.9 x 51.49, 11.99
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x228b22} }, // 6 OSM: 75919 WD: Q121537242 53.85, 27.58 x 53.95, 27.63
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000cd} }, // 5 OSM: 75939 WD: Q121537241 53.91, 27.54 x 53.95, 27.62
    { 62, 2692, 2564, LineMetaDataContent::RapidTransit, Color{0x00983a} }, // S11 OSM: 76229 WD: Q116125180 47.2, 15.24 x 47.23, 15.34
    { 394, NoLogo, 2711, LineMetaDataContent::Tramway, Color{0xe30613} }, // 89 OSM: 77259 WD: Q68081929 52.53, 13.84 x 52.58, 13.88
    { 71, 2743, 226, LineMetaDataContent::RapidTransit, Color{0x9a2a23} }, // S1 OSM: 77908 WD: Q7388209 49.27, 10.9 x 49.9, 11.46
    { 59, 2760, 226, LineMetaDataContent::RapidTransit, Color{0x65b949} }, // S2 OSM: 77962 WD: Q7388248 49.24, 11.04 x 49.51, 11.56
    { 225, 2777, 226, LineMetaDataContent::RapidTransit, Color{0xff561d} }, // S3 OSM: 77971 WD: Q7388284 49.38, 11.08 x 49.45, 11.35
    { 68, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xef1c29} }, // 3 OSM: 78206 WD: Q121304819 50.84, 12.05 x 50.91, 12.1
    { 68, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x4098de} }, // 3 OSM: 79325 WD: Q60318542 51.72, 14.3 x 51.76, 14.35
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xa81a30} }, // 6 OSM: 89518 WD: Q1664234 47.23, 11.4 x 47.26, 11.44
    { 298, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x0066b3} }, // S6 OSM: 91626 WD: Q115646650 46.9, 7.778 x 47.22, 8.31
    { 46, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x78b6e4} }, // S7 OSM: 91629 WD: Q115646652 47.06, 7.778 x 47.22, 8.082
    { 397, 2794, NoLogo, LineMetaDataContent::LocalTrain, Color{0xe50000} }, // RE 30 OSM: 93946 WD: Q113462371 49.44, 11.08 x 49.95, 11.63
    { 403, 2811, NoLogo, LineMetaDataContent::LocalTrain, Color{0xf09280} }, // RB 12 OSM: 100360 WD: Q114717482 49.44, 10.66 x 49.51, 11.09
    { 9, 2828, 2861, LineMetaDataContent::Subway, Color{0xa21a68} }, // 4 OSM: 102389 WD: Q54373 43.76, -79.41 x 43.78, -79.35
    { 185, 2904, 2931, LineMetaDataContent::RapidTransit, Color{0xef7b10} }, // LO OSM: 112649 WD: Q110199216 51.38, -0.3962 x 51.7, 0.1233
    { 411, 2954, 2986, LineMetaDataContent::RapidTransit, Color{0xfcd946} }, // C OSM: 122886 WD: Q200906 48.43, 1.995 x 49.05, 2.427
    { 413, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x37bbed} }, // LS OSM: 129379 WD: Q15982573 -35.19, -59.43 x -34.58, -58.41
    { 416, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x37bbed} }, // LSM OSM: 129382 WD: Q3239199 -34.61, -59.08 x -34.45, -58.37
    { 420, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x37bbed} }, // LM OSM: 129383 WD: Q66759479 -34.59, -59.04 x -34.1, -58.37
    { 423, 3016, NoLogo, LineMetaDataContent::RapidTransit, Color{0xef3e33} }, // LU OSM: 129393 WD: Q7887242 -34.6, -58.7 x -34.53, -58.46
    { 429, 3046, 3074, LineMetaDataContent::Tramway, Color{0xf38733} }, // P OSM: 129505 WD: Q3409024 -34.69, -58.47 x -34.64, -58.44
    { 234, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf0a014} }, // N27 OSM: 129569 48.08, 11.55 x 48.18, 11.59
    { 434, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe33385} }, // 96 OSM: 132386 WD: Q12061652 -37.87, 145 x -37.77, 145
    { 437, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfeba10} }, // 86 OSM: 137969 WD: Q12061650 -37.82, 144.9 x -37.68, 145.1
    { 22, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 18 OSM: 139323 WD: Q108783978 42.68, 23.32 x 42.72, 23.34
    { 68, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x88d1f0} }, // 3 OSM: 144407 WD: Q6811954 -37.89, 145 x -37.8, 145.1
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe04038} }, // 5 OSM: 145649 WD: Q6811959 -37.87, 145 x -37.8, 145.1
    { 170, 3089, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 49 OSM: 147322 WD: Q1491114 47.47, 19.02 x 47.5, 19.06
    { 441, 3113, 3125, LineMetaDataContent::Subway, Color{0xfdc110} }, // M2 OSM: 152340 WD: Q1880954 55.63, 12.49 x 55.69, 12.65
    { 64, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009640} }, // 1 OSM: 153893 WD: Q104796303 53.04, 8.741 x 53.09, 8.965
    { 444, 3151, NoLogo, LineMetaDataContent::LocalTrain, Color{0x2a89ca} }, // RB 80 OSM: 158860 WD: Q114713941 49.66, 9.933 x 49.8, 10.15
    { 52, 3168, 226, LineMetaDataContent::RapidTransit, Color{0x23c4fc} }, // S5 OSM: 160986 WD: Q55632180 49.26, 11.08 x 49.45, 11.21
    { 450, 3185, NoLogo, LineMetaDataContent::LocalTrain, Color{0x5d97ce} }, // RB 81 OSM: 161886 WD: Q107110025 49.45, 10.27 x 49.58, 10.59
    { 64, 3202, 3202, LineMetaDataContent::Tramway, Color{0xec008c} }, // 1 OSM: 163714 WD: Q104534472 52.47, -2.125 x 52.59, -1.896
    { 418, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x004595} }, // M OSM: 165610 WD: Q55079952 49.39, 1.042 x 49.45, 1.106
    { 360, 3241, 3265, LineMetaDataContent::Subway, Color{0x0075be} }, // M1 OSM: 165613 WD: Q3238660 43.29, 5.374 x 43.33, 5.43
    { 441, 3297, 3265, LineMetaDataContent::Subway, Color{0xe30513} }, // M2 OSM: 165618 WD: Q3238804 43.27, 5.367 x 43.33, 5.403
    { 459, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x49805b} }, // 59 OSM: 167658 WD: Q6811962 -37.82, 144.9 x -37.71, 145
    { 469, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x6ccff6} }, // Bay OSM: 168229 WD: Q17017970 51.47, -3.172 x 51.48, -3.167
    { 487, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf0af11} }, // City OSM: 168230 51.47, -3.249 x 51.52, -3.17
    { 492, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xee4b95} }, // TL11 OSM: 168327 WD: Q125903429 51.36, -0.3277 x 51.75, -0.0954
    { 497, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xee4b95} }, // TL12 OSM: 168327 WD: Q125903429 51.36, -0.3277 x 51.75, -0.0954
    { 64, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x003828} }, // 1 OSM: 170076 WD: Q110883264 52.92, -1.263 x 53.04, -1.145
    { 502, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x42816b} }, // 181 (SN) OSM: 172834 51.28, -0.1728 x 51.49, -0.07193
    { 372, NoLogo, 3321, LineMetaDataContent::RapidTransit, Color{0xd39f06} }, // Yellow OSM: 172864 WD: Q10318747 54.95, -1.623 x 55.04, -1.429
    { 68, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x78ccc9} }, // 3 OSM: 173596 50.43, 30.37 x 50.45, 30.49
    { 157, NoLogo, 3346, LineMetaDataContent::Tramway, Color{0xce1417} }, // 15 OSM: 174237 WD: Q123344569 50.42, 30.41 x 50.46, 30.49
    { 511, 3371, 226, LineMetaDataContent::RapidTransit, Color{0x52b447} }, // S85 OSM: 175267 WD: Q4048677 52.41, 13.32 x 52.61, 13.58
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xb7cbd8} }, // 2 OSM: 176853 WD: Q120720200 50.05, 19.91 x 50.07, 19.96
    { 19, 3402, NoLogo, LineMetaDataContent::Subway, Color{0x82cee6} }, // 8 OSM: 178504 WD: Q18638820 39.46, -0.339 x 39.46, -0.3254
    { 27, 3433, NoLogo, LineMetaDataContent::Subway, Color{0x9b70cb} }, // 6 OSM: 178505 WD: Q3832664 39.46, -0.3726 x 39.5, -0.3256
    { 9, 3464, NoLogo, LineMetaDataContent::Subway, Color{0x004a99} }, // 4 OSM: 178506 WD: Q3238939 39.47, -0.4364 x 39.53, -0.3256
    { 6, 3495, NoLogo, LineMetaDataContent::Subway, Color{0x009870} }, // 5 OSM: 178522 WD: Q3238965 39.46, -0.4744 x 39.49, -0.3383
    { 68, 3526, NoLogo, LineMetaDataContent::Subway, Color{0xdd052b} }, // 3 OSM: 178523 WD: Q3238906 39.47, -0.4744 x 39.59, -0.33
    { 64, 3557, NoLogo, LineMetaDataContent::Subway, Color{0xfdc600} }, // 1 OSM: 178526 WD: Q2165952 39.08, -0.5268 x 39.59, -0.3815
    { 22, NoLogo, 3346, LineMetaDataContent::Tramway, Color{0xce1417} }, // 18 OSM: 179505 WD: Q123339549 50.44, 30.48 x 50.47, 30.52
    { 516, 3588, 3616, LineMetaDataContent::Tramway, Color{0xc19dc2} }, // L4 OSM: 190184 WD: Q5474600 38.35, -0.4911 x 38.38, -0.4118
    { 520, 3657, 3616, LineMetaDataContent::Tramway, Color{0xd72028} }, // L1 OSM: 190196 WD: Q594538 38.35, -0.4911 x 38.55, -0.1348
    { 524, NoLogo, 3616, LineMetaDataContent::Tramway, Color{0x00ff00} }, // L2 OSM: 190199 WD: Q9025903 38.35, -0.5172 x 38.39, -0.4678
    { 528, NoLogo, 3616, LineMetaDataContent::Tramway, Color{0xf9d114} }, // L3 OSM: 190203 WD: Q9025931 38.35, -0.4911 x 38.43, -0.3952
    { 531, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf58122} }, // 109 OSM: 190802 WD: Q6811947 -37.84, 144.9 x -37.81, 145.1
    { 411, 3685, 1449, LineMetaDataContent::RapidTransit, Color{0xffa500} }, // C OSM: 191280 WD: Q4452746 55.66, 12.07 x 55.84, 12.59
    { 34, 3707, 1449, LineMetaDataContent::RapidTransit, Color{0xe64415} }, // H OSM: 191281 WD: Q1891933 55.66, 12.36 x 55.73, 12.59
    { 64, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfff101} }, // 1 OSM: 194681 WD: Q109558646 52.32, 14.53 x 52.34, 14.56
    { 68, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf36f42} }, // 3 OSM: 194690 WD: Q109558673 52.29, 14.47 x 52.34, 14.56
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xcc693a} }, // 5 OSM: 195194 WD: Q109558671 52.32, 14.5 x 52.35, 14.55
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xb368ab} }, // 4 OSM: 195195 WD: Q109558672 52.29, 14.47 x 52.36, 14.55
    { 536, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x33bdca} }, // 57 OSM: 196209 WD: Q16926803 -37.82, 144.9 x -37.77, 145
    { 539, 3729, 3759, LineMetaDataContent::RapidTransit, Color{0xff6600} }, // C7 OSM: 207184 WD: Q27976587 43.35, -6.113 x 43.55, -5.676
    { 542, 3778, 3759, LineMetaDataContent::RapidTransit, Color{0x5599ff} }, // C-8 OSM: 207192 WD: Q27976836 43.12, -5.829 x 43.28, -5.566
    { 547, NoLogo, 19, LineMetaDataContent::Tramway, Color{0x0e4094} }, // 4E OSM: 207342 WD: Q68574879 51.32, 12.35 x 51.35, 12.43
    { 9, NoLogo, 19, LineMetaDataContent::Tramway, Color{0x0e4094} }, // 4 OSM: 207342 WD: Q68574879 51.32, 12.35 x 51.35, 12.43
    { 550, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00a5e3} }, // North Jersey Coast OSM: 207401 WD: Q7055732 40.07, -74.29 x 40.77, -73.99
    { 16, 3809, NoLogo, LineMetaDataContent::Subway, Color{0x97d700} }, // 2 OSM: 207417 WD: Q1325437 31.15, 121.3 x 31.24, 121.8
    { 572, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x434244} }, // 48 OSM: 207445 WD: Q16926797 -37.82, 144.9 x -37.79, 145.1
    { 64, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 1 OSM: 207718 WD: Q121590538 45.55, 18.62 x 45.57, 18.73
    { 424, 3829, 3863, LineMetaDataContent::RapidTransit, Color{0xb90845} }, // U OSM: 215565 WD: Q93559 48.76, 1.943 x 48.89, 2.237
    { 16, NoLogo, 3895, LineMetaDataContent::Tramway, Color{0xce1417} }, // 2 OSM: 227555 WD: Q123224636 56.31, 43.98 x 56.33, 44.03
    { 47, 3912, NoLogo, LineMetaDataContent::Subway, Color{0xff6900} }, // 7 OSM: 228608 WD: Q2707909 31.17, 121.3 x 31.41, 121.6
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffff00} }, // 8 OSM: 237270 WD: Q106673737 49.17, 16.57 x 49.21, 16.69
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00ff00} }, // 2 OSM: 237285 WD: Q122395000 49.13, 16.59 x 49.2, 16.64
    { 64, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xd40000} }, // 1 OSM: 237306 WD: Q122394999 49.19, 16.51 x 49.25, 16.61
    { 68, NoLogo, 3895, LineMetaDataContent::Tramway, Color{0xce1417} }, // 3 OSM: 240614 WD: Q123224637 56.27, 43.92 x 56.32, 43.95
    { 6, NoLogo, 3895, LineMetaDataContent::Tramway, Color{0xce1417} }, // 5 OSM: 240615 WD: Q123337615 56.26, 43.97 x 56.32, 44
    { 19, NoLogo, 3895, LineMetaDataContent::Tramway, Color{0xce1417} }, // 8 OSM: 240656 WD: Q123224638 56.21, 43.77 x 56.28, 43.91
    { 22, NoLogo, 3895, LineMetaDataContent::Tramway, Color{0xce1417} }, // 18 OSM: 240658 WD: Q123224642 56.29, 43.99 x 56.31, 44.03
    { 161, NoLogo, 3895, LineMetaDataContent::Tramway, Color{0xce1417} }, // 19 OSM: 240659 WD: Q123337413 56.26, 43.97 x 56.3, 44.05
    { 82, NoLogo, 3895, LineMetaDataContent::Tramway, Color{0xce1417} }, // 21 OSM: 240660 WD: Q123224643 56.27, 43.92 x 56.32, 44.01
    { 118, NoLogo, 3895, LineMetaDataContent::Tramway, Color{0xce1417} }, // 22 OSM: 240661 WD: Q123224644 56.25, 43.84 x 56.27, 43.9
    { 235, NoLogo, 3895, LineMetaDataContent::Tramway, Color{0xce1417} }, // 27 OSM: 240662 WD: Q123224645 56.3, 43.94 x 56.32, 44.05
    { 575, NoLogo, 3895, LineMetaDataContent::Tramway, Color{0xce1417} }, // 417 OSM: 240666 WD: Q123224646 56.24, 43.83 x 56.32, 43.95
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x648fa8} }, // 12 OSM: 241383 WD: Q1759931 59.32, 17.92 x 59.33, 17.98
    { 400, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xd77d00} }, // 30 OSM: 241384 WD: Q1760190 59.29, 17.96 x 59.36, 18.12
    { 259, 3932, 3961, LineMetaDataContent::RapidTransit, Color{0xf166a7} }, // 43 OSM: 241411 WD: Q106806959 58.9, 17.53 x 59.57, 18.16
    { 270, 3932, 3961, LineMetaDataContent::RapidTransit, Color{0xf166a7} }, // 41 OSM: 241413 WD: Q106806951 59.17, 17.63 x 59.63, 18.07
    { 572, 3932, 3961, LineMetaDataContent::RapidTransit, Color{0xf166a7} }, // 48 OSM: 241414 WD: Q106808255 59.04, 17.31 x 59.19, 17.65
    { 581, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x37bbed} }, // TS OSM: 252385 WD: Q802144 -31.42, -64.54 x -30.86, -64.17
    { 586, 4001, 3863, LineMetaDataContent::RapidTransit, Color{0x9f9825} }, // K OSM: 253357 WD: Q93382 48.88, 2.352 x 49.23, 2.887
    { 588, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x007dc5} }, // ISL OSM: 269670 WD: Q989316 22.26, 114.1 x 22.29, 114.2
    { 592, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xf7943e} }, // TCL OSM: 269671 WD: Q989358 22.28, 113.9 x 22.36, 114.2
    { 597, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 1R OSM: 271401 WD: Q122617992 47.05, 21.91 x 47.08, 21.94
    { 600, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x00888a} }, // AEL OSM: 272078 WD: Q409036 22.29, 113.9 x 22.36, 114.2
    { 604, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x53b7e8} }, // EAL OSM: 272132 WD: Q989339 22.28, 114.1 x 22.53, 114.2
    { 608, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x923011} }, // TML OSM: 272133 WD: Q5329661 22.29, 114 x 22.45, 114.2
    { 321, 4035, NoLogo, LineMetaDataContent::RapidTransit, Color{0xef7c00} }, // S 1 OSM: 273002 WD: Q65643711 49.11, 6.891 x 49.41, 7.069
    { 612, 4053, NoLogo, LineMetaDataContent::Tramway, Color{0xff7e00} }, // 28E OSM: 274460 WD: Q63034669 38.71, -9.17 x 38.72, -9.128
    { 616, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf7bf56} }, // Belfast-Bangor OSM: 275877 WD: Q3743313 54.59, -5.945 x 54.67, -5.671
    { 631, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xd85054} }, // Belfast-Larne OSM: 275882 WD: Q3743316 54.59, -5.945 x 54.85, -5.709
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // 2 OSM: 284941 WD: Q121832844 53.01, 18.55 x 53.04, 18.67
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // 2 OSM: 300207 48.46, 34.61 x 48.52, 34.69
    { 64, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff00ff} }, // 1 OSM: 300208 48.51, 34.57 x 48.52, 34.62
    { 645, 4066, 226, LineMetaDataContent::RapidTransit, Color{0x9a3052} }, // S9 OSM: 304163 WD: Q4048680 52.36, 13.2 x 52.53, 13.57
    { 653, NoLogo, 2638, LineMetaDataContent::RapidTransit, Color{0x008000} }, // Green OSM: 304623 WD: Q6714613 45.44, -122.7 x 45.54, -122.6
    { 660, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x2774b9} }, // 39 OSM: 309018 WD: Q17355356 45.41, 28.01 x 45.47, 28.03
    { 360, 4096, 4108, LineMetaDataContent::Subway, Color{0x0000ff} }, // M1 OSM: 309619 WD: Q17462780 52.13, 20.93 x 52.29, 21.07
    { 64, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 1 OSM: 311323 WD: Q123221543 48.44, 35.02 x 48.48, 35.07
    { 63, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 11 OSM: 311324 WD: Q123221548 48.42, 34.98 x 48.48, 35.02
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 2 OSM: 337341 WD: Q99494736 49.79, 9.892 x 49.8, 9.936
    { 645, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf49ac1} }, // S9 OSM: 349282 47.3, 9.039 x 47.46, 9.088
    { 429, NoLogo, 4130, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // P OSM: 357191 WD: Q118874962 60.17, 24.84 x 60.33, 25.06
    { 663, 4165, NoLogo, LineMetaDataContent::LocalTrain, Color{0x0000ff} }, // C-3 OSM: 357360 WD: Q4802044 42.99, -3.016 x 43.26, -2.882
    { 667, 4190, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // C-1 OSM: 357967 WD: Q3239078 43.25, -3.03 x 43.33, -2.928
    { 47, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x2774b9} }, // 7 OSM: 358090 WD: Q122616086 45.41, 28.01 x 45.44, 28.05
    { 679, NoLogo, 4130, LineMetaDataContent::RapidTransit, Color{0x035eb9} }, // I OSM: 358139 WD: Q118874956 60.17, 24.84 x 60.33, 25.06
    { 681, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x630016} }, // STB OSM: 359908 WD: Q872840 47.16, 11.35 x 47.27, 11.4
    { 686, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x723b1f} }, // 35 OSM: 363305 WD: Q5123100 -37.82, 144.9 x -37.81, 145
    { 689, 4215, NoLogo, LineMetaDataContent::LocalTrain, Color{0xffffff} }, // RB 55 OSM: 363679 WD: Q108409627 47.68, 11.53 x 48.14, 12.01
    { 161, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8f4a78} }, // 19 OSM: 363891 WD: Q6811950 -37.82, 145 x -37.73, 145
    { 225, 4232, 226, LineMetaDataContent::RapidTransit, Color{0x862996} }, // S3 OSM: 364187 WD: Q56996474 47.88, 11.17 x 48.22, 11.7
    { 695, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // SIR1 OSM: 365296 WD: Q107133892 45.37, 11.87 x 45.44, 11.89
    { 701, 4248, 4274, LineMetaDataContent::Subway, Color{0x6cbe45} }, // G OSM: 366764 WD: Q126527 40.64, -74 x 40.75, -73.94
    { 47, 4291, 4274, LineMetaDataContent::Subway, Color{0xb933ad} }, // 7 OSM: 366765 WD: Q126203 40.74, -74 x 40.76, -73.83
    { 414, 4317, 4274, LineMetaDataContent::Subway, Color{0x808183} }, // S OSM: 366766 WD: Q126698 40.75, -73.99 x 40.76, -73.98
    { 705, 4343, 4274, LineMetaDataContent::Subway, Color{0xfccc0a} }, // N OSM: 366768 WD: Q126434 40.58, -74.02 x 40.78, -73.91
    { 707, 4369, 4274, LineMetaDataContent::Subway, Color{0xfccc0a} }, // Q OSM: 366769 WD: Q126448 40.58, -74 x 40.78, -73.95
    { 712, 4395, 4274, LineMetaDataContent::Subway, Color{0x0039a6} }, // A OSM: 366774 WD: Q126344 40.58, -74.01 x 40.87, -73.75
    { 27, 4421, 4274, LineMetaDataContent::Subway, Color{0x00933c} }, // 6 OSM: 366777 WD: Q126192 40.71, -74.01 x 40.85, -73.83
    { 598, 4447, 4274, LineMetaDataContent::Subway, Color{0xfccc0a} }, // R OSM: 366780 WD: Q126459 40.62, -74.03 x 40.77, -73.84
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 8 OSM: 367548 47.2, 38.88 x 47.22, 38.94
    { 714, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x9acd32} }, // Bx OSM: 367751 55.65, 12.27 x 55.75, 12.59
    { 337, 4473, 1449, LineMetaDataContent::RapidTransit, Color{0xffc225} }, // F OSM: 381625 WD: Q2133631 55.65, 12.49 x 55.73, 12.57
    { 47, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008030} }, // 7 OSM: 382533 WD: Q2590490 51.91, 4.471 x 51.93, 4.526
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xdf60a4} }, // 8 OSM: 382535 WD: Q3277304 51.9, 4.432 x 51.95, 4.488
    { 330, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x6192c7} }, // 25 OSM: 382566 WD: Q2321951 51.84, 4.46 x 51.96, 4.514
    { 75, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xa05a2c} }, // 10 OSM: 383124 WD: Q122395010 49.19, 16.56 x 49.22, 16.68
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00ccff} }, // 12 OSM: 384321 WD: Q122395012 49.18, 16.58 x 49.23, 16.62
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff00ff} }, // 5 OSM: 384539 49.16, 16.59 x 49.22, 16.63
    { 717, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe40000} }, // 155 OSM: 391346 46.38, 6.073 x 46.47, 6.235
    { 721, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa3429b} }, // TER T2 OSM: 394022 WD: Q3536981 47.09, -1.542 x 47.22, -1.286
    { 548, 4495, 1449, LineMetaDataContent::RapidTransit, Color{0x9370db} }, // E OSM: 394091 WD: Q4624816 55.46, 12.17 x 55.81, 12.59
    { 63, 4517, NoLogo, LineMetaDataContent::Subway, Color{0x76232f} }, // 11 OSM: 396879 WD: Q2636308 31.13, 120.6 x 31.4, 121.7
    { 16, 4527, 4547, LineMetaDataContent::Subway, Color{0x00529b} }, // 2 OSM: 414866 WD: Q680973 39.9, 116.3 x 39.95, 116.4
    { 64, 4582, 4547, LineMetaDataContent::Subway, Color{0xa12830} }, // 1 OSM: 415571 WD: Q748987 39.85, 116.2 x 39.94, 116.7
    { 67, 4602, 4547, LineMetaDataContent::Subway, Color{0xf9e700} }, // 13 OSM: 417951 WD: Q847744 39.94, 116.3 x 40.07, 116.5
    { 360, 4623, 4645, LineMetaDataContent::Subway, Color{0xffd800} }, // M1 OSM: 418343 WD: Q1078111 47.5, 19.05 x 47.52, 19.09
    { 725, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x006d78} }, // T2 OSM: 418631 WD: Q16011471 47.22, 5.951 x 47.25, 6.03
    { 75, 4659, 4547, LineMetaDataContent::Subway, Color{0x178abb} }, // 10 OSM: 420835 WD: Q847886 39.84, 116.3 x 39.98, 116.5
    { 6, 4680, 4547, LineMetaDataContent::Subway, Color{0xae005f} }, // 5 OSM: 420836 WD: Q647340 39.84, 116.4 x 40.08, 116.4
    { 19, 4700, 4547, LineMetaDataContent::Subway, Color{0x00997a} }, // 8 OSM: 420837 WD: Q847771 39.76, 116.3 x 40.1, 116.4
    { 9, 4720, 4547, LineMetaDataContent::Subway, Color{0x008994} }, // 4 OSM: 420838 WD: Q304264 39.67, 116.3 x 40.01, 116.4
    { 64, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xcf657c} }, // 1 OSM: 420868 55.56, 12.97 x 55.71, 13.19
    { 82, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x559734} }, // 21 OSM: 422738 WD: Q123363033 56.81, 60.54 x 56.86, 60.64
    { 19, 4740, NoLogo, LineMetaDataContent::Subway, Color{0x008c95} }, // 8 OSM: 443998 WD: Q862965 23.09, 113.2 x 23.24, 113.4
    { 598, 4760, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // R OSM: 447451 WD: Q697140 25.03, 121.4 x 25.17, 121.6
    { 64, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0026ff} }, // 1 OSM: 453141 WD: Q104222652 36.23, 59.44 x 36.35, 59.64
    { 71, 4784, 226, LineMetaDataContent::RapidTransit, Color{0xd474ae} }, // S1 OSM: 454054 WD: Q2579762 52.42, 13.18 x 52.75, 13.4
    { 46, 4814, 226, LineMetaDataContent::RapidTransit, Color{0x20543f} }, // S7 OSM: 456933 WD: Q2588691 49.83, 8.488 x 50.11, 8.664
    { 349, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 23 OSM: 532064 WD: Q108783983 42.65, 23.37 x 42.68, 23.41
    { 289, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe40716} }, // T1 OSM: 535990 WD: Q3239228 45.41, 4.364 x 45.48, 4.394
    { 729, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x009de0} }, // E3 OSM: 542311 43.25, -2.929 x 43.3, -2.836
    { 709, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0363ff} }, // T1 A OSM: 548496 WD: Q1688502 36.72, 3.083 x 36.78, 3.263
    { 64, 4831, NoLogo, LineMetaDataContent::RapidTransit, Color{0xbf4525} }, // 1 OSM: 556308 WD: Q110248494 60.29, 5.232 x 60.39, 5.361
    { 735, NoLogo, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 56 OSM: 557061 WD: Q1491414 47.43, 18.96 x 47.54, 19.05
    { 161, 4857, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 19 OSM: 557063 WD: Q776651 47.47, 19.02 x 47.55, 19.05
    { 739, 4881, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 47 OSM: 557066 WD: Q1491058 47.43, 19.04 x 47.5, 19.06
    { 270, 4905, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 41 OSM: 557068 WD: Q1490823 47.44, 18.98 x 47.55, 19.05
    { 94, 4929, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 61 OSM: 557070 WD: Q1491592 47.48, 18.96 x 47.54, 19.05
    { 16, 4953, NoLogo, LineMetaDataContent::Tramway, Color{0x0068b3} }, // 2 OSM: 563459 WD: Q78198199 48.32, 10.84 x 48.38, 10.91
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xef7c00} }, // 8 OSM: 563484 48.33, 10.89 x 48.37, 10.9
    { 181, 4973, 226, LineMetaDataContent::RapidTransit, Color{0x928d1d} }, // S60 OSM: 570588 WD: Q63952011 48.69, 8.922 x 48.83, 9.195
    { 742, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff6600} }, // MSC 1908 OSM: 660480 14.2, 121 x 14.62, 121.2
    { 751, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe41346} }, // S13 OSM: 660876 WD: Q125989614 49.88, 17.88 x 49.93, 17.92
    { 182, 5010, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 60 OSM: 899388 WD: Q851167 47.5, 18.98 x 47.51, 19.01
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 4 OSM: 900844 WD: Q108783918 42.66, 23.26 x 42.72, 23.34
    { 459, 5034, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 59 OSM: 906131 WD: Q744461 47.48, 19 x 47.51, 19.02
    { 239, 5058, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 17 OSM: 911937 WD: Q1486400 47.44, 19.02 x 47.55, 19.05
    { 26, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffda66} }, // 16 OSM: 916109 WD: Q16926791 -37.87, 145 x -37.8, 145
    { 63, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xb0cb1f} }, // 11 OSM: 917563 WD: Q122382726 49.78, 18.23 x 49.86, 18.29
    { 755, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffa21d} }, // MD-W OSM: 932986 WD: Q5250950 41.88, -88.33 x 42.06, -87.64
    { 760, 5088, NoLogo, LineMetaDataContent::LocalTrain, Color{0x269900} }, // RE7 OSM: 939026 WD: Q95186801 51.53, 12.23 x 52.53, 14.06
    { 161, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x7ac9ce} }, // 19 OSM: 948994 WD: Q104868215 50.08, 8.581 x 50.1, 8.684
    { 174, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x19aacd} }, // 52 OSM: 960169 WD: Q120720226 50.02, 19.89 x 50.1, 20.04
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x19633a} }, // 6 OSM: 962031 WD: Q121419537 47.06, 15.41 x 47.08, 15.48
    { 68, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x68ba45} }, // 3 OSM: 962059 WD: Q121419534 47.07, 15.42 x 47.1, 15.46
    { 47, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe42714} }, // 7 OSM: 962240 WD: Q121419538 47.06, 15.39 x 47.08, 15.47
    { 64, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00b8ea} }, // 1 OSM: 962920 WD: Q121419533 47.07, 15.39 x 47.11, 15.49
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x95c11f} }, // 8 OSM: 963052 WD: Q112609295 53.05, 8.741 x 53.1, 8.84
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffcc00} }, // 6 OSM: 963103 WD: Q112609293 53.05, 8.783 x 53.11, 8.859
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x025191} }, // 5 OSM: 963685 WD: Q121419536 47.03, 15.42 x 47.1, 15.45
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xdeaa2e} }, // 4 OSM: 963737 WD: Q121419535 47.04, 15.41 x 47.07, 15.46
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe30613} }, // 4 OSM: 964983 WD: Q112609286 53.03, 8.799 x 53.16, 8.945
    { 68, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009fe3} }, // 3 OSM: 966312 WD: Q98313027 53.06, 8.752 x 53.12, 8.868
    { 764, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00a54f} }, // D1 OSM: 1014078 51.1, 15.22 x 51.29, 17.04
    { 68, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xdb2016} }, // 3 OSM: 1028300 WD: Q120670490 52.73, 15.23 x 52.76, 15.28
    { 64, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xdb2016} }, // 1 OSM: 1028301 WD: Q120670257 52.72, 15.18 x 52.76, 15.28
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xdb2016} }, // 2 OSM: 1028303 WD: Q120670488 52.72, 15.18 x 52.75, 15.24
    { 767, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x004a8f} }, // D2 OSM: 1050561 51.1, 16.17 x 51.22, 17.04
    { 289, NoLogo, 5107, LineMetaDataContent::Tramway, Color{0x808080} }, // T1 OSM: 1059709 WD: Q107172293 42.84, -2.702 x 42.87, -2.649
    { 770, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe00885} }, // D8 OSM: 1067686 51.1, 17 x 51.31, 17.12
    { 773, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0075bf} }, // N10 OSM: 1070763 53.06, 8.752 x 53.12, 8.9
    { 778, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe30613} }, // N4 OSM: 1070810 53.03, 8.799 x 53.16, 8.945
    { 781, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009640} }, // N1 OSM: 1070812 53.04, 8.741 x 53.09, 8.965
    { 63, NoLogo, 3895, LineMetaDataContent::Tramway, Color{0xce1417} }, // 11 OSM: 1102233 WD: Q123224640 56.32, 43.98 x 56.33, 44.01
    { 27, 5129, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 6 OSM: 1102938 WD: Q1491542 47.48, 19.02 x 47.51, 19.07
    { 9, 5152, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 4 OSM: 1102941 WD: Q1490736 47.47, 19.02 x 47.51, 19.07
    { 784, 5175, 5190, LineMetaDataContent::RapidTransit, Color{0x8a236c} }, // H5 OSM: 1103027 WD: Q1031914 47.51, 19.03 x 47.66, 19.08
    { 64, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffc734} }, // 1 OSM: 1105466 WD: Q121219450 52.4, 12.47 x 52.43, 12.57
    { 788, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x1aaa6f} }, // 64 OSM: 1110830 WD: Q6811964 -37.91, 145 x -37.8, 145
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x004c6c} }, // 6 OSM: 1111658 WD: Q16926785 -37.86, 145 x -37.76, 145.1
    { 231, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xac7963} }, // 67 OSM: 1111659 WD: Q6811965 -37.89, 145 x -37.8, 145.1
    { 791, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfaa634} }, // Raritan Valley OSM: 1122386 WD: Q7294577 40.56, -74.9 x 40.74, -74.16
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x90ee90} }, // 5 OSM: 1133389 49.84, 24.03 x 49.86, 24.04
    { 806, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xf173ac} }, // DRL OSM: 1139477 WD: Q989330 22.32, 114 x 22.33, 114
    { 712, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xed389c} }, // A OSM: 1142411 WD: Q16900249 45.5, -122.7 x 45.53, -122.7
    { 810, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe41f25} }, // N82 OSM: 1147592 48.24, 14.28 x 48.33, 14.36
    { 243, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe41f25} }, // 50 OSM: 1149422 WD: Q121368142 48.31, 14.26 x 48.32, 14.29
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe41f25} }, // 2 OSM: 1149423 WD: Q121368139 48.24, 14.28 x 48.33, 14.36
    { 68, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe41f25} }, // 3 OSM: 1149424 WD: Q121368140 48.23, 14.23 x 48.31, 14.29
    { 64, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe41f25} }, // 1 OSM: 1149425 WD: Q121368138 48.25, 14.28 x 48.33, 14.32
    { 124, 5214, 1489, LineMetaDataContent::Subway, Color{0x00a54f} }, // U2 OSM: 1150977 WD: Q3040891 50.1, 8.64 x 50.22, 8.688
    { 814, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0039a6} }, // Harlem OSM: 1158719 WD: Q5658559 40.75, -73.98 x 41.82, -73.55
    { 821, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x29c2ce} }, // JVL OSM: 1171503 WD: Q16926948 -41.28, 174.8 x -41.22, 174.8
    { 825, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf48a30} }, // MEL OSM: 1171726 WD: Q124378470 -41.28, 174.8 x -41.2, 174.9
    { 78, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008be0} }, // TER 21 OSM: 1184795 WD: Q120094781 45.67, 4.762 x 45.77, 4.827
    { 829, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x009b3a} }, // Hudson OSM: 1186686 40.75, -73.99 x 41.71, -73.86
    { 836, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff7900} }, // Port Jervis OSM: 1190915 WD: Q7230730 41.11, -74.69 x 41.49, -74.09
    { 520, 5231, NoLogo, LineMetaDataContent::Tramway, Color{0xe52422} }, // L1 OSM: 1190932 WD: Q28662810 41.62, -0.9378 x 41.69, -0.8708
    { 161, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 19 OSM: 1203707 WD: Q123221555 48.48, 34.94 x 48.53, 35.03
    { 22, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 18 OSM: 1203711 WD: Q123221554 48.48, 34.94 x 48.53, 35.03
    { 157, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 15 OSM: 1204826 WD: Q123221551 48.44, 34.96 x 48.48, 35.02
    { 848, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0065ff} }, // SFM A OSM: 1204872 WD: Q3832760 45.23, 7.39 x 45.31, 7.604
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 5 OSM: 1205626 WD: Q123221544 48.44, 34.94 x 48.48, 35.06
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 6 OSM: 1205663 WD: Q123221545 48.48, 35.02 x 48.5, 35.07
    { 146, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 9 OSM: 1205679 WD: Q123221547 48.48, 35.02 x 48.5, 35.12
    { 239, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 17 OSM: 1205794 WD: Q123221553 48.45, 35.01 x 48.48, 35.03
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 4 OSM: 1205827 WD: Q123346559 48.45, 35.02 x 48.48, 35.04
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 12 OSM: 1205902 WD: Q123221549 48.38, 35 x 48.48, 35.04
    { 26, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 16 OSM: 1205923 WD: Q123221552 48.4, 34.98 x 48.45, 35.03
    { 854, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0065ff} }, // SFM 2 OSM: 1210497 WD: Q3832754 44.89, 7.337 x 45.19, 7.89
    { 9, NoLogo, 5256, LineMetaDataContent::Tramway, Color{0xff0000} }, // 4 OSM: 1212297 WD: Q122202405 45.01, 7.624 x 45.13, 7.715
    { 67, NoLogo, 5256, LineMetaDataContent::Tramway, Color{0x7f9be1} }, // 13 OSM: 1213866 WD: Q122202408 45.06, 7.632 x 45.08, 7.7
    { 75, NoLogo, 5256, LineMetaDataContent::Tramway, Color{0xd9a500} }, // 10 OSM: 1221336 WD: Q122202407 45.02, 7.614 x 45.08, 7.672
    { 68, NoLogo, 5256, LineMetaDataContent::Tramway, Color{0xff9b0a} }, // 3 OSM: 1225333 WD: Q122202404 45.07, 7.624 x 45.1, 7.708
    { 146, NoLogo, 5256, LineMetaDataContent::Tramway, Color{0x35bdff} }, // 9 OSM: 1226867 WD: Q122202406 45.05, 7.655 x 45.11, 7.688
    { 860, NoLogo, 976, LineMetaDataContent::Tramway, Color{0x95aa53} }, // 308 OSM: 1228606 WD: Q121194689 51.4, 7.16 x 51.52, 7.284
    { 864, NoLogo, 976, LineMetaDataContent::Tramway, Color{0xb14e7a} }, // 310 OSM: 1228607 WD: Q121194693 51.44, 7.152 x 51.48, 7.337
    { 685, NoLogo, 976, LineMetaDataContent::Subway, Color{0x294488} }, // U35 OSM: 1228608 WD: Q2466100 51.45, 7.21 x 51.55, 7.273
    { 21, NoLogo, 976, LineMetaDataContent::Tramway, Color{0x72a7a0} }, // 318 OSM: 1228609 WD: Q121194696 51.42, 7.143 x 51.52, 7.284
    { 868, NoLogo, 976, LineMetaDataContent::Tramway, Color{0xea504c} }, // 306 OSM: 1228610 WD: Q121194687 51.48, 7.16 x 51.53, 7.223
    { 872, NoLogo, 976, LineMetaDataContent::Tramway, Color{0x6ba5d9} }, // 302 OSM: 1228611 WD: Q85178556 51.46, 7.056 x 51.58, 7.324
    { 876, NoLogo, 976, LineMetaDataContent::Tramway, Color{0x00b2f6} }, // 301 OSM: 1236118 WD: Q121175248 51.5, 7.019 x 51.58, 7.11
    { 880, 5295, 226, LineMetaDataContent::RapidTransit, Color{0xf47a14} }, // S 5 OSM: 1241173 WD: Q67505528 49.14, 8.674 x 49.42, 9.102
    { 884, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe00034} }, // New Haven OSM: 1260624 40.75, -73.98 x 41.31, -72.92
    { 894, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x89728e} }, // VMLR OSM: 1266358 WD: Q171699 33.41, -112.1 x 33.58, -111.8
    { 725, NoLogo, 1277, LineMetaDataContent::Tramway, Color{0x0000ff} }, // T2 OSM: 1286854 WD: Q5986172 28.44, -16.3 x 28.47, -16.29
    { 899, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x16a117} }, // Chengalpattu - Arakkonam OSM: 1289049 WD: Q7568860 12.69, 79.64 x 13.08, 79.98
    { 68, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 3 OSM: 1343415 WD: Q122585345 55.64, 37.6 x 55.76, 37.7
    { 64, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 1 OSM: 1343815 WD: Q122585344 55.6, 37.59 x 55.66, 37.61
    { 26, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 16 OSM: 1348910 WD: Q122585356 55.6, 37.59 x 55.7, 37.63
    { 255, 5314, 4547, LineMetaDataContent::Subway, Color{0xd61572} }, // 24 OSM: 1350576 WD: Q5944471 39.77, 116.4 x 39.84, 116.6
    { 524, 5314, 4547, LineMetaDataContent::Subway, Color{0xd61572} }, // L2 OSM: 1350576 WD: Q5944471 39.77, 116.4 x 39.84, 116.6
    { 235, 5341, 4547, LineMetaDataContent::Subway, Color{0xd47daa} }, // 27 OSM: 1350622 WD: Q5066697 39.97, 116.2 x 40.24, 116.3
    { 703, 5369, 4547, LineMetaDataContent::Subway, Color{0xd85f26} }, // 25N OSM: 1350671 WD: Q5433860 39.72, 116.1 x 39.86, 116.3
    { 520, NoLogo, 4547, LineMetaDataContent::Subway, Color{0x9b91b1} }, // L1 OSM: 1354082 WD: Q847767 39.94, 116.4 x 40.08, 116.6
    { 924, 5396, 5190, LineMetaDataContent::RapidTransit, Color{0xee7101} }, // H7 OSM: 1358702 WD: Q1031921 47.42, 19.07 x 47.48, 19.07
    { 68, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 3 OSM: 1361661 WD: Q123352902 56.48, 84.95 x 56.48, 85.02
    { 239, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 17 OSM: 1371410 WD: Q122585357 55.82, 37.62 x 55.89, 37.67
    { 63, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 11 OSM: 1371613 WD: Q122585352 55.78, 37.62 x 55.83, 37.82
    { 927, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x14ffff} }, // 5а OSM: 1372294 WD: Q124657535 55.73, 49.07 x 55.83, 49.22
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xcc9900} }, // 8 OSM: 1374424 WD: Q61887882 51.45, 11.95 x 51.52, 11.99
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x99cc00} }, // 12 OSM: 1375884 WD: Q61888162 51.48, 11.96 x 51.52, 11.99
    { 935, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfece08} }, // Main OSM: 1377995 WD: Q6736006 40.73, -74.17 x 41.11, -74.03
    { 940, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa1d4ae} }, // Gladstone OSM: 1377996 WD: Q5566325 40.67, -74.67 x 40.77, -73.99
    { 950, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xb9c9df} }, // Bergen County OSM: 1377997 WD: Q4891507 40.73, -74.15 x 41.11, -74.03
    { 964, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00a94e} }, // Morristown OSM: 1377998 WD: Q1948559 40.71, -74.83 x 40.91, -73.99
    { 975, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe76b5b} }, // Montclair-Boonton OSM: 1377999 WD: Q6904583 40.73, -74.83 x 40.93, -73.99
    { 409, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff8942} }, // FXC OSM: 1388637 WD: Q8565193 39.95, -75.18 x 40.08, -75.08
    { 993, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7c5e4a} }, // DOY OSM: 1388640 WD: Q6487336 39.95, -75.28 x 40.31, -75.13
    { 997, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffd457} }, // WAR OSM: 1390135 WD: Q7969637 39.95, -75.18 x 40.26, -74.82
    { 1001, NoLogo, 5411, LineMetaDataContent::RapidTransit, Color{0xfaa93f} }, // Camden OSM: 1403279 WD: Q5025789 38.9, -77.01 x 39.28, -76.62
    { 1008, NoLogo, 5411, LineMetaDataContent::RapidTransit, Color{0xfbcab6} }, // Brunswick OSM: 1405417 WD: Q4979520 38.9, -77.96 x 39.46, -76.99
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 2 OSM: 1405516 WD: Q122917034 44.8, 20.45 x 44.83, 20.48
    { 1018, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff7f00} }, // 12E OSM: 1411178 WD: Q1487139 38.71, -9.138 x 38.72, -9.13
    { 1022, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff00ff} }, // 15E OSM: 1411205 WD: Q63229924 38.69, -9.233 x 38.71, -9.135
    { 269, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00008b} }, // 041 OSM: 1413948 WD: Q121357423 51.3, 6.497 x 51.33, 6.602
    { 265, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00008b} }, // 042 OSM: 1413950 WD: Q121358966 51.3, 6.554 x 51.37, 6.619
    { 258, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00008b} }, // 043 OSM: 1413951 WD: Q121358976 51.33, 6.566 x 51.36, 6.648
    { 177, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00008b} }, // 044 OSM: 1413956 WD: Q121358885 51.33, 6.513 x 51.37, 6.659
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfdc434} }, // 4 OSM: 1443866 WD: Q1490746 46.24, 20.12 x 46.28, 20.16
    { 6, 5426, 5450, LineMetaDataContent::Subway, Color{0x802f08} }, // 5 OSM: 1462012 WD: Q831673 55.73, 37.57 x 55.78, 37.66
    { 9, 5555, 5450, LineMetaDataContent::Subway, Color{0x33ccff} }, // 4 OSM: 1463287 WD: Q834540 55.73, 37.44 x 55.75, 37.61
    { 68, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe5005a} }, // 3 OSM: 1469415 WD: Q89494370 51.02, 13.7 x 51.1, 13.75
    { 68, 5579, 5450, LineMetaDataContent::Subway, Color{0x0000ff} }, // 3 OSM: 1472548 WD: Q626941 55.73, 37.35 x 55.86, 37.8
    { 1026, 5603, NoLogo, LineMetaDataContent::LocalTrain, Color{0xffb200} }, // RB 13 OSM: 1472736 WD: Q113237031 48.35, 10.88 x 48.75, 11.45
    { 64, 5620, 5450, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 1475758 WD: Q729631 55.55, 37.4 x 55.82, 37.75
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffa500} }, // 4 OSM: 1476874 WD: Q123352951 56.45, 84.98 x 56.48, 85.02
    { 645, 5644, 226, LineMetaDataContent::RapidTransit, Color{0x73c82c} }, // S9 OSM: 1483885 WD: Q115215302 48.99, 8.399 x 49.71, 8.58
    { 1035, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0896dd} }, // 98 OSM: 1490387 WD: Q106462644 52.36, 13.03 x 52.4, 13.1
    { 1038, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 91 OSM: 1492311 WD: Q92930854 52.36, 13.01 x 52.4, 13.1
    { 712, 5663, 5702, LineMetaDataContent::Subway, Color{0x0000ff} }, // A OSM: 1502599 WD: Q17621067 6.152, -75.63 x 6.339, -75.54
    { 64, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // 1 OSM: 1503481 WD: Q123352876 56.47, 84.95 x 56.53, 85.02
    { 1042, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x897cb9} }, // 78 OSM: 1504645 WD: Q6811971 -37.87, 145 x -37.81, 145
    { 1045, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x19488e} }, // 92 OSM: 1505928 WD: Q106462634 52.36, 13.03 x 52.42, 13.14
    { 1048, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfe9800} }, // 93 OSM: 1509473 WD: Q106461089 52.36, 13.06 x 52.41, 13.1
    { 1051, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x838a8f} }, // 94 OSM: 1512265 WD: Q106462647 52.37, 13.01 x 52.4, 13.11
    { 339, 5730, 226, LineMetaDataContent::RapidTransit, Color{0x803c9f} }, // S33 OSM: 1513484 WD: Q115206384 49.12, 8.364 x 49.24, 8.594
    { 27, 5750, 5450, LineMetaDataContent::Subway, Color{0xffa500} }, // 6 OSM: 1514439 WD: Q175271 55.6, 37.51 x 55.89, 37.67
    { 47, 5774, 5450, LineMetaDataContent::Subway, Color{0xff00ff} }, // 7 OSM: 1516383 WD: Q924028 55.67, 37.43 x 55.86, 37.86
    { 146, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 9 OSM: 1524904 WD: Q123346616 51.51, 45.94 x 51.54, 46.02
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 2 OSM: 1524905 WD: Q123346611 51.46, 45.93 x 51.51, 45.95
    { 75, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 10 OSM: 1524906 WD: Q123346620 51.52, 45.96 x 51.54, 46.02
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 4 OSM: 1524907 WD: Q123346619 51.56, 45.89 x 51.59, 45.93
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 6 OSM: 1524908 WD: Q123346617 51.57, 45.88 x 51.59, 45.93
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 5 OSM: 1524910 WD: Q123346621 51.45, 45.89 x 51.48, 45.91
    { 47, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 7 OSM: 1524911 WD: Q123346614 51.45, 45.9 x 51.51, 45.95
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 8 OSM: 1524912 WD: Q123346618 51.48, 45.89 x 51.53, 45.98
    { 68, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 3 OSM: 1525325 WD: Q123346613 51.53, 45.93 x 51.59, 46.02
    { 26, NoLogo, 5256, LineMetaDataContent::Tramway, Color{0xe0abff} }, // 16 OSM: 1525348 WD: Q122202410 45.05, 7.65 x 45.09, 7.698
    { 19, 5798, 5450, LineMetaDataContent::Subway, Color{0xffff00} }, // 8 OSM: 1526351 WD: Q585986 55.74, 37.63 x 55.76, 37.87
    { 75, 5822, 5450, LineMetaDataContent::Subway, Color{0xb4d445} }, // 10 OSM: 1532877 WD: Q582194 55.61, 37.54 x 55.93, 37.76
    { 1054, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xdc281e} }, // N19 OSM: 1536166 48.12, 11.46 x 48.15, 11.64
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 12 OSM: 1538177 WD: Q122585353 55.72, 37.66 x 55.79, 37.82
    { 243, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 50 OSM: 1538180 WD: Q122585371 55.75, 37.6 x 55.79, 37.72
    { 302, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 46 OSM: 1538181 WD: Q122585368 55.73, 37.67 x 55.83, 37.77
    { 110, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 37 OSM: 1538182 WD: Q122585363 55.75, 37.65 x 55.78, 37.82
    { 1059, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 32 OSM: 1538183 WD: Q122585361 55.75, 37.66 x 55.79, 37.75
    { 225, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x0097d8} }, // S3 OSM: 1549250 WD: Q7388286 47.32, 8.501 x 47.53, 8.806
    { 1062, 5847, 5874, LineMetaDataContent::RapidTransit, Color{0x6265ac} }, // Arènes-Colomiers OSM: 1557176 WD: Q3239085 43.59, 1.332 x 43.6, 1.418
    { 279, 5900, 5927, LineMetaDataContent::Subway, Color{0xffd900} }, // B OSM: 1557177 WD: Q3239063 43.56, 1.43 x 43.64, 1.478
    { 289, 5951, 5979, LineMetaDataContent::Tramway, Color{0x004687} }, // T1 OSM: 1557178 WD: Q3239230 43.59, 1.36 x 43.67, 1.444
    { 712, 6003, 5927, LineMetaDataContent::Subway, Color{0xdb001b} }, // A OSM: 1557179 WD: Q3239050 43.57, 1.392 x 43.63, 1.483
    { 1080, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf6c454} }, // S10 OSM: 1561016 WD: Q687279 47.35, 8.465 x 47.38, 8.54
    { 314, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe67d63} }, // S4 OSM: 1567629 WD: Q685807 47.27, 8.517 x 47.38, 8.558
    { 146, 6030, 5450, LineMetaDataContent::Subway, Color{0xa0a2a3} }, // 9 OSM: 1570146 WD: Q739170 55.57, 37.57 x 55.9, 37.63
    { 16, 6054, 5450, LineMetaDataContent::Subway, Color{0x006400} }, // 2 OSM: 1572626 WD: Q834482 55.61, 37.47 x 55.88, 37.77
    { 254, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x946644} }, // S24 OSM: 1574036 WD: Q7388228 47.17, 8.512 x 47.75, 9.106
    { 15, 6078, 5450, LineMetaDataContent::Subway, Color{0xbac8e8} }, // 12 OSM: 1580617 WD: Q678759 55.54, 37.52 x 55.6, 37.59
    { 434, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00a995} }, // 96 OSM: 1585204 WD: Q106462646 52.36, 13.05 x 52.43, 13.14
    { 1085, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x59c133} }, // 99 OSM: 1585259 WD: Q106462643 52.37, 13.06 x 52.4, 13.11
    { 62, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0xccaaff} }, // S11 OSM: 1588232 WD: Q56435440 47.37, 8.048 x 47.54, 8.771
    { 1088, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x37bbed} }, // TMR OSM: 1603490 -27.47, -59.05 x -27.42, -58.98
    { 1092, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x00c0f3} }, // S29 OSM: 1609488 WD: Q115646661 47.17, 7.903 x 47.49, 8.257
    { 71, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x00ab4e} }, // S1 OSM: 1609559 WD: Q115646641 47.04, 8.098 x 47.2, 8.525
    { 298, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x7751a1} }, // S6 OSM: 1609735 WD: Q7388350 47.26, 8.305 x 47.48, 8.683
    { 1096, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0xd8242b} }, // S12 OSM: 1614502 WD: Q7388182 47.37, 8.208 x 47.7, 9.043
    { 25, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x64b97a} }, // S16 OSM: 1618466 WD: Q7388193 47.28, 8.511 x 47.45, 8.621
    { 339, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x2da7df} }, // S33 OSM: 1619213 WD: Q7388269 47.5, 8.611 x 47.7, 8.726
    { 645, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x00a34f} }, // S9 OSM: 1620987 WD: Q7388394 47.35, 8.501 x 47.7, 8.721
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc32b3c} }, // 2 OSM: 1624727 WD: Q60282113 51.75, 14.31 x 51.76, 14.35
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x239537} }, // 4 OSM: 1628047 WD: Q60328960 51.72, 14.32 x 51.79, 14.35
    { 725, 6103, 6136, LineMetaDataContent::Tramway, Color{0xbb4a9b} }, // T2 OSM: 1635139 WD: Q1771110 48.82, 2.217 x 48.92, 2.288
    { 667, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // C-1 OSM: 1636998 WD: Q59928410 41.63, -1.023 x 41.72, -0.8658
    { 64, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xece116} }, // 1 OSM: 1637446 WD: Q60213236 51.75, 14.33 x 51.78, 14.34
    { 712, 6167, 3074, LineMetaDataContent::Subway, Color{0x1ca4cb} }, // A OSM: 1637478 WD: Q1209679 -34.63, -58.47 x -34.61, -58.37
    { 22, NoLogo, 976, LineMetaDataContent::Tramway, Color{0x0095da} }, // 18 OSM: 1646141 WD: Q20035834 50.73, 6.893 x 50.98, 7.096
    { 1100, 6195, 5190, LineMetaDataContent::RapidTransit, Color{0xed6e86} }, // H9 OSM: 1647378 WD: Q947539 47.5, 19.14 x 47.55, 19.27
    { 1103, 6195, 5190, LineMetaDataContent::RapidTransit, Color{0xed6e86} }, // H8 OSM: 1647379 WD: Q947539 47.5, 19.14 x 47.6, 19.36
    { 1106, 6210, 5190, LineMetaDataContent::RapidTransit, Color{0x7b4400} }, // H6 OSM: 1647380 WD: Q1031918 47.18, 18.94 x 47.47, 19.12
    { 64, 6225, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 1 OSM: 1658046 WD: Q651686 47.46, 19.02 x 47.55, 19.11
    { 255, 6248, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 24 OSM: 1658053 WD: Q1489900 47.44, 19.07 x 47.5, 19.12
    { 243, 6272, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 50 OSM: 1658057 WD: Q643837 47.43, 19.13 x 47.47, 19.22
    { 105, 6296, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 62 OSM: 1658060 WD: Q1491622 47.48, 19.07 x 47.54, 19.14
    { 266, 6320, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 42 OSM: 1658062 WD: Q1490864 47.45, 19.13 x 47.47, 19.15
    { 68, 6344, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 3 OSM: 1658063 WD: Q1490196 47.44, 19.09 x 47.52, 19.14
    { 153, 6367, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 14 OSM: 1658066 WD: Q1485881 47.52, 19.06 x 47.59, 19.12
    { 1109, 6391, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 69 OSM: 1658067 WD: Q1491929 47.52, 19.09 x 47.55, 19.15
    { 174, 6415, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 52 OSM: 1658071 WD: Q1491293 47.42, 19.1 x 47.47, 19.13
    { 1112, 6439, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 62A OSM: 1658072 WD: Q743389 47.48, 19.1 x 47.54, 19.14
    { 110, 6464, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 37 OSM: 1658073 WD: Q1490525 47.47, 19.07 x 47.5, 19.18
    { 1116, 6488, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 51A OSM: 1658076 WD: Q16516127 47.47, 19.07 x 47.48, 19.08
    { 356, 6513, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 51 OSM: 1658077 WD: Q1491245 47.44, 19.07 x 47.48, 19.12
    { 1120, 6537, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 28A OSM: 1658080 WD: Q12813290 47.47, 19.07 x 47.5, 19.18
    { 1125, 6559, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 28 OSM: 1658081 WD: Q1490084 47.47, 19.07 x 47.5, 19.18
    { 1128, 6583, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 37A OSM: 1658082 WD: Q287376 47.49, 19.07 x 47.5, 19.14
    { 71, 6608, 226, LineMetaDataContent::RapidTransit, Color{0x33b540} }, // S1 OSM: 1660624 WD: Q19377130 53.55, 9.705 x 53.65, 10.09
    { 68, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 3 OSM: 1666928 WD: Q123353080 53.36, 58.96 x 53.45, 59.09
    { 82, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 21 OSM: 1667031 WD: Q123353102 53.36, 58.96 x 53.43, 59.01
    { 146, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 9 OSM: 1667386 WD: Q123353086 53.36, 58.98 x 53.48, 59.09
    { 157, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 15 OSM: 1667885 WD: Q123353095 53.36, 58.96 x 53.48, 59.06
    { 64, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 1 OSM: 1667972 WD: Q123353077 53.39, 58.97 x 53.44, 59.1
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 2 OSM: 1667973 WD: Q123353078 53.4, 58.96 x 53.44, 59.08
    { 67, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 13 OSM: 1672599 WD: Q123353091 53.4, 58.96 x 53.45, 59.09
    { 153, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 14 OSM: 1672601 WD: Q123353092 53.4, 58.96 x 53.45, 59.09
    { 75, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 10 OSM: 1672603 WD: Q123353087 53.35, 58.96 x 53.45, 59.09
    { 255, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 24 OSM: 1672604 WD: Q123353105 53.35, 58.96 x 53.44, 58.98
    { 1093, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 29 OSM: 1672605 WD: Q123353109 53.36, 58.97 x 53.44, 59.01
    { 239, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 17 OSM: 1672606 WD: Q123353098 53.36, 58.96 x 53.44, 58.98
    { 63, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 11 OSM: 1672607 WD: Q123353088 53.4, 58.97 x 53.44, 59.08
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 12 OSM: 1672608 WD: Q123353089 53.36, 58.96 x 53.45, 59.08
    { 283, 6623, 2986, LineMetaDataContent::RapidTransit, Color{0x00824e} }, // D OSM: 1673421 WD: Q1425351 48.29, 2.344 x 49.26, 2.657
    { 22, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 18 OSM: 1673878 WD: Q123353099 53.36, 58.96 x 53.41, 59.1
    { 47, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 7 OSM: 1673879 WD: Q123353084 53.36, 58.98 x 53.42, 59.03
    { 118, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 22 OSM: 1673880 WD: Q123353103 53.36, 58.96 x 53.42, 59.03
    { 251, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 20 OSM: 1673881 WD: Q123353101 53.35, 58.96 x 53.42, 59.03
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 6 OSM: 1673882 WD: Q123353083 53.4, 58.96 x 53.43, 59.03
    { 686, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 35 OSM: 1675482 WD: Q123353114 53.39, 59.04 x 53.45, 59.1
    { 400, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 30 OSM: 1675489 WD: Q123353111 53.36, 58.98 x 53.45, 59.09
    { 1125, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 28 OSM: 1675490 WD: Q123353108 53.36, 58.96 x 53.44, 59.08
    { 124, 6655, 1489, LineMetaDataContent::Subway, Color{0xff0000} }, // U2 OSM: 1676043 WD: Q3433227 49.42, 11.03 x 49.49, 11.11
    { 64, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe96020} }, // 1 OSM: 1679960 WD: Q16655728 50.09, 14.34 x 50.1, 14.46
    { 124, 6672, 1489, LineMetaDataContent::Subway, Color{0xee1d23} }, // U2 OSM: 1686090 WD: Q275451 53.53, 9.943 x 53.64, 10.15
    { 121, 6687, 1489, LineMetaDataContent::Subway, Color{0x0066b3} }, // U1 OSM: 1687370 WD: Q248623 53.55, 9.985 x 53.71, 10.29
    { 318, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 26 OSM: 1689065 WD: Q122585360 55.68, 37.54 x 55.73, 37.62
    { 660, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 39 OSM: 1689391 WD: Q122585365 55.68, 37.54 x 55.76, 37.7
    { 1134, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // А OSM: 1689398 WD: Q4461919 55.73, 37.63 x 55.76, 37.7
    { 739, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 47 OSM: 1689752 WD: Q122585369 55.68, 37.61 x 55.73, 37.69
    { 262, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 38 OSM: 1690017 WD: Q122585364 55.68, 37.59 x 55.75, 37.72
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc80404} }, // 2 OSM: 1707564 WD: Q20902214 55.87, 26.53 x 55.9, 26.56
    { 68, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x66cc66} }, // 3 OSM: 1707565 WD: Q25529489 55.87, 26.5 x 55.91, 26.59
    { 64, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc80404} }, // 1 OSM: 1708351 WD: Q25529488 55.87, 26.51 x 55.9, 26.56
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x946238} }, // 2 OSM: 1713906 WD: Q109558674 52.34, 14.5 x 52.35, 14.56
    { 225, 6702, 226, LineMetaDataContent::RapidTransit, Color{0x5d1d81} }, // S3 OSM: 1727359 WD: Q19368685 53.46, 9.797 x 53.66, 10.03
    { 336, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfdc434} }, // 3F OSM: 1733222 WD: Q570656 46.25, 20.11 x 46.28, 20.16
    { 68, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfdc434} }, // 3 OSM: 1733225 WD: Q1490201 46.25, 20.12 x 46.28, 20.16
    { 379, NoLogo, 6717, LineMetaDataContent::RapidTransit, Color{0xf80000} }, // Red OSM: 1737997 WD: Q7304508 38.51, -90.36 x 38.74, -89.88
    { 174, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x7c7c7b} }, // 52 OSM: 1744154 WD: Q108464208 49.96, 8.246 x 50, 8.28
    { 64, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xee1d23} }, // 1 OSM: 1756406 WD: Q121537880 51.9, 29.21 x 52.05, 29.33
    { 1137, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // СТ OSM: 1759150 WD: Q107191041 48.7, 44.5 x 48.8, 44.6
    { 75, 6745, NoLogo, LineMetaDataContent::Tramway, Color{0xffffff} }, // 10 OSM: 1762641 WD: Q123158615 56.84, 53.18 x 56.88, 53.28
    { 1142, 6765, 6787, LineMetaDataContent::Subway, Color{0x0000ff} }, // 2 Салтівська OSM: 1766294 WD: Q2332390 49.99, 36.23 x 50.03, 36.34
    { 1165, 6810, 6787, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 Холодногірсько-заводська OSM: 1766295 WD: Q2710248 49.95, 36.18 x 49.99, 36.4
    { 1215, 6832, 6787, LineMetaDataContent::Subway, Color{0x008000} }, // 3 Олексіївська OSM: 1766296 WD: Q2109890 49.98, 36.2 x 50.06, 36.27
    { 63, 6854, NoLogo, LineMetaDataContent::Tramway, Color{0xde4800} }, // 11 OSM: 1766772 WD: Q123158574 56.84, 53.23 x 56.87, 53.28
    { 64, 6874, 3346, LineMetaDataContent::Tramway, Color{0x78ccc9} }, // 1 OSM: 1767386 WD: Q63890946 50.41, 30.38 x 50.45, 30.49
    { 16, 6874, 3346, LineMetaDataContent::Tramway, Color{0x78ccc9} }, // 2 OSM: 1773735 WD: Q63890965 50.41, 30.37 x 50.43, 30.41
    { 64, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff6600} }, // 1 OSM: 1783293 WD: Q25522217 59.44, 24.67 x 59.46, 24.79
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff6600} }, // 2 OSM: 1783294 WD: Q18624670 59.43, 24.67 x 59.46, 24.81
    { 68, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff6600} }, // 3 OSM: 1783295 WD: Q25522221 59.41, 24.73 x 59.44, 24.79
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff6600} }, // 4 OSM: 1783296 WD: Q16409268 59.41, 24.73 x 59.44, 24.81
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x06a0e6} }, // 2 OSM: 1788097 55.67, 52.28 x 55.73, 52.47
    { 1242, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x1b522b} }, // 12а OSM: 1789317 55.67, 52.28 x 55.75, 52.47
    { 153, NoLogo, 3346, LineMetaDataContent::Tramway, Color{0xce1417} }, // 14 OSM: 1794175 WD: Q123344581 50.42, 30.41 x 50.47, 30.52
    { 64, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 1 OSM: 1795490 WD: Q121832771 53.01, 18.56 x 53.03, 18.7
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 4 OSM: 1795572 WD: Q121832895 53.01, 18.56 x 53.04, 18.67
    { 15, NoLogo, 3346, LineMetaDataContent::Tramway, Color{0xce1417} }, // 12 OSM: 1798934 WD: Q123339546 50.46, 30.34 x 50.55, 30.52
    { 1247, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa82618} }, // SSL OSM: 1811654 41.59, -87.62 x 41.88, -86.29
    { 27, NoLogo, 6890, LineMetaDataContent::Tramway, Color{0xce1417} }, // 6 OSM: 1821113 WD: Q123168035 59.93, 30.23 x 59.97, 30.36
    { 274, NoLogo, 6890, LineMetaDataContent::Tramway, Color{0xce1417} }, // 40 OSM: 1821265 WD: Q123168054 59.93, 30.25 x 60.01, 30.37
    { 725, 6908, 6938, LineMetaDataContent::Tramway, Color{0xab0672} }, // T2 OSM: 1824544 WD: Q106915028 47.29, 5.006 x 47.37, 5.059
    { 289, 6961, 6938, LineMetaDataContent::Tramway, Color{0xcc0088} }, // T1 OSM: 1824550 WD: Q3238664 47.31, 5.028 x 47.33, 5.112
    { 1251, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x509e2f} }, // BEL OSM: 1826236 WD: Q4881878 -35.03, 138.6 x -34.92, 138.6
    { 400, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x4f4a9f} }, // 30 OSM: 1830395 WD: Q6811953 -37.81, 144.9 x -37.81, 145
    { 26, NoLogo, 6890, LineMetaDataContent::Tramway, Color{0xce1417} }, // 16 OSM: 1831075 WD: Q123168040 59.9, 30.27 x 59.93, 30.37
    { 270, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 41 OSM: 1831189 59.88, 30.24 x 59.92, 30.29
    { 127, 6991, 1489, LineMetaDataContent::Subway, Color{0x00868b} }, // U3 OSM: 1857497 WD: Q3433219 49.44, 11.02 x 49.47, 11.09
    { 121, 7008, 1489, LineMetaDataContent::Subway, Color{0x000066} }, // U1 OSM: 1857639 WD: Q3433210 49.4, 10.96 x 49.48, 11.14
    { 64, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0101df} }, // 1 OSM: 1860406 WD: Q104189103 50.82, 12.88 x 50.84, 12.92
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x6a0888} }, // 2 OSM: 1860407 WD: Q104189205 50.81, 12.92 x 50.84, 12.95
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffff00} }, // 4 OSM: 1860420 WD: Q104189434 50.78, 12.88 x 50.84, 12.93
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff8000} }, // 5 OSM: 1862032 WD: Q104189624 50.78, 12.88 x 50.83, 12.97
    { 82, 7025, NoLogo, LineMetaDataContent::Tramway, Color{0xf89c0e} }, // 21 OSM: 1871117 WD: Q85093119 50.07, 8.567 x 50.11, 8.67
    { 26, 7055, NoLogo, LineMetaDataContent::Tramway, Color{0xf47216} }, // 16 OSM: 1871120 WD: Q111155014 50.1, 8.644 x 50.14, 8.745
    { 1256, NoLogo, 6890, LineMetaDataContent::Tramway, Color{0xce1417} }, // 36 OSM: 1871436 WD: Q123168051 59.85, 30.06 x 59.89, 30.28
    { 712, 7085, NoLogo, LineMetaDataContent::Tramway, Color{0xed2625} }, // A OSM: 1874970 WD: Q2066292 49.23, 4.004 x 49.28, 4.032
    { 279, 7115, NoLogo, LineMetaDataContent::Tramway, Color{0x00aef0} }, // B OSM: 1874971 WD: Q2085986 49.22, 3.996 x 49.28, 4.032
    { 63, 7145, NoLogo, LineMetaDataContent::Tramway, Color{0xfbbc09} }, // 11 OSM: 1875166 WD: Q85088920 50.1, 8.552 x 50.13, 8.774
    { 15, 7175, NoLogo, LineMetaDataContent::Tramway, Color{0xc73a17} }, // 12 OSM: 1875167 WD: Q85090131 50.08, 8.581 x 50.13, 8.756
    { 153, 7205, NoLogo, LineMetaDataContent::Tramway, Color{0xf1471d} }, // 14 OSM: 1875169 WD: Q85112445 50.1, 8.618 x 50.13, 8.716
    { 157, 7235, NoLogo, LineMetaDataContent::Tramway, Color{0xfbbc09} }, // 15 OSM: 1875170 WD: Q85112688 50.09, 8.636 x 50.1, 8.745
    { 239, 7265, NoLogo, LineMetaDataContent::Tramway, Color{0xf1471d} }, // 17 OSM: 1875171 WD: Q107028657 50.06, 8.619 x 50.12, 8.695
    { 251, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x939597} }, // 20 OSM: 1875174 WD: Q85089542 50.07, 8.65 x 50.11, 8.67
    { 22, 7295, NoLogo, LineMetaDataContent::Tramway, Color{0xf89c0e} }, // 18 OSM: 1875175 WD: Q109953001 50.08, 8.671 x 50.16, 8.704
    { 298, 7325, 226, LineMetaDataContent::RapidTransit, Color{0xf57921} }, // S6 OSM: 1880910 WD: Q3238987 50.1, 8.633 x 50.34, 8.789
    { 239, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8d1d2c} }, // 17 OSM: 1903836 WD: Q96578284 47.35, 8.482 x 47.4, 8.542
    { 68, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xb71965} }, // 3 OSM: 1904828 WD: Q16655744 50, 14.4 x 50.13, 14.48
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x9bd6f9} }, // 4 OSM: 1904829 WD: Q16655748 50.02, 14.35 x 50.08, 14.48
    { 75, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 10 OSM: 1905347 WD: Q100151899 44.76, 20.45 x 44.83, 20.48
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 12 OSM: 1905348 WD: Q122917040 44.77, 20.41 x 44.81, 20.49
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 5 OSM: 1905349 WD: Q122917036 44.78, 20.45 x 44.83, 20.52
    { 243, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x1d1d1b} }, // 50 OSM: 1909761 WD: Q68580427 49.96, 8.175 x 50.02, 8.275
    { 9, 7342, NoLogo, LineMetaDataContent::Tramway, Color{0x4f71b9} }, // 4 OSM: 1910445 WD: Q21041079 48.14, 17.03 x 48.2, 17.18
    { 47, 7367, NoLogo, LineMetaDataContent::Tramway, Color{0xfeec06} }, // 7 OSM: 1925351 WD: Q21041082 48.14, 17.11 x 48.22, 17.17
    { 1059, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xbe1622} }, // 32 OSM: 1925789 WD: Q117220924 44.4, 26.05 x 44.43, 26.1
    { 344, NoLogo, 6890, LineMetaDataContent::Tramway, Color{0xce1417} }, // 45 OSM: 1926572 WD: Q123168058 59.83, 30.32 x 59.88, 30.41
    { 1093, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 29 OSM: 1926573 59.83, 30.32 x 59.9, 30.35
    { 259, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 43 OSM: 1927169 59.83, 30.32 x 59.89, 30.4
    { 330, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xbe1622} }, // 25 OSM: 1928780 WD: Q121368432 44.37, 25.98 x 44.43, 26.1
    { 330, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 25 OSM: 1933012 59.83, 30.35 x 59.93, 30.4
    { 170, NoLogo, 6890, LineMetaDataContent::Tramway, Color{0xce1417} }, // 49 OSM: 1933013 WD: Q123168062 59.83, 30.35 x 59.93, 30.42
    { 47, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xbe1622} }, // 7 OSM: 1936713 WD: Q85980453 44.37, 26.09 x 44.43, 26.1
    { 739, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xbe1622} }, // 47 OSM: 1936802 WD: Q121368510 44.41, 26.05 x 44.43, 26.1
    { 82, NoLogo, 6890, LineMetaDataContent::Tramway, Color{0xce1417} }, // 21 OSM: 1938644 WD: Q123168044 59.98, 30.24 x 60.06, 30.38
    { 572, NoLogo, 6890, LineMetaDataContent::Tramway, Color{0xce1417} }, // 48 OSM: 1938658 WD: Q123168061 59.98, 30.19 x 59.99, 30.35
    { 251, NoLogo, 6890, LineMetaDataContent::Tramway, Color{0xce1417} }, // 20 OSM: 1938751 WD: Q123168043 59.96, 30.32 x 60.05, 30.38
    { 295, NoLogo, 6890, LineMetaDataContent::Tramway, Color{0xce1417} }, // 58 OSM: 1939721 WD: Q123168067 60.04, 30.3 x 60.07, 30.38
    { 712, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xa83939} }, // A OSM: 1940504 WD: Q10883225 35, 135.7 x 35.02, 135.7
    { 270, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xbe1622} }, // 41 OSM: 1940779 WD: Q4982647 44.41, 26.03 x 44.48, 26.08
    { 692, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 55 OSM: 1942053 59.99, 30.23 x 60.06, 30.37
    { 27, 7392, 2034, LineMetaDataContent::Tramway, Color{0xfef303} }, // 6 OSM: 1942851 WD: Q104867938 49.43, 11.05 x 49.46, 11.12
    { 59, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // S2 OSM: 1946076 WD: Q884374 48, 7.84 x 48.17, 8.072
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 2 OSM: 1949380 WD: Q123352923 56.45, 84.95 x 56.48, 84.99
    { 411, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x913108} }, // C OSM: 1958845 WD: Q121410577 37.79, -122.4 x 37.79, -122.4
    { 146, NoLogo, 6890, LineMetaDataContent::Tramway, Color{0xce1417} }, // 9 OSM: 1959399 WD: Q123168038 59.98, 30.32 x 60.04, 30.44
    { 75, NoLogo, 6890, LineMetaDataContent::Tramway, Color{0xce1417} }, // 10 OSM: 1965337 WD: Q123168039 59.91, 30.41 x 59.95, 30.5
    { 19, NoLogo, 6890, LineMetaDataContent::Tramway, Color{0xce1417} }, // 8 OSM: 1965401 WD: Q123168037 59.93, 30.44 x 59.95, 30.49
    { 459, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 59 OSM: 1965402 59.93, 30.44 x 59.97, 30.49
    { 788, NoLogo, 6890, LineMetaDataContent::Tramway, Color{0xce1417} }, // 64 OSM: 1965403 WD: Q123168073 59.93, 30.44 x 59.98, 30.51
    { 153, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 14 OSM: 1968651 WD: Q122917042 44.76, 20.47 x 44.81, 20.52
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 6 OSM: 1968652 WD: Q122917037 44.78, 20.47 x 44.81, 20.52
    { 64, 7409, NoLogo, LineMetaDataContent::Tramway, Color{0xca0706} }, // 1 OSM: 1973051 WD: Q28667619 56.79, 53.18 x 56.88, 53.21
    { 9, 7409, NoLogo, LineMetaDataContent::Tramway, Color{0xca0706} }, // 4 OSM: 1973053 WD: Q28667619 56.84, 53.18 x 56.88, 53.25
    { 47, 7428, NoLogo, LineMetaDataContent::Tramway, Color{0x2f0583} }, // 7 OSM: 1973055 WD: Q123158699 56.86, 53.18 x 56.88, 53.25
    { 146, 7447, NoLogo, LineMetaDataContent::Tramway, Color{0xca0706} }, // 9 OSM: 1973056 WD: Q123158593 56.79, 53.19 x 56.88, 53.25
    { 16, 7466, NoLogo, LineMetaDataContent::Tramway, Color{0x1aab47} }, // 2 OSM: 1973058 WD: Q123155973 56.84, 53.2 x 56.88, 53.25
    { 1259, NoLogo, 976, LineMetaDataContent::Tramway, Color{0xd01519} }, // 107 OSM: 1976059 WD: Q121174870 51.41, 6.993 x 51.51, 7.103
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x003828} }, // 2 OSM: 1984325 WD: Q110883507 52.9, -1.207 x 52.99, -1.145
    { 1263, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x82bf40} }, // SFM3 OSM: 1988841 WD: Q3832756 45.04, 6.71 x 45.14, 7.678
    { 700, 7485, NoLogo, LineMetaDataContent::Tramway, Color{0xfcc70d} }, // SG OSM: 1994315 WD: Q339069 35.64, 139.6 x 35.67, 139.7
    { 589, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x004ea2} }, // SL OSM: 1994316 WD: Q6360898 35.33, 139.6 x 35.39, 139.7
    { 441, 7510, 19, LineMetaDataContent::Tramway, Color{0x33ff33} }, // M2 OSM: 2001598 WD: Q62512253 52.52, 13.41 x 52.57, 13.44
    { 1268, NoLogo, 976, LineMetaDataContent::Subway, Color{0x008fc2} }, // U75 OSM: 2003447 WD: Q121295970 51.2, 6.684 x 51.23, 6.847
    { 1041, NoLogo, 976, LineMetaDataContent::Subway, Color{0x009adf} }, // U78 OSM: 2003448 WD: Q107015816 51.22, 6.734 x 51.27, 6.795
    { 67, NoLogo, 976, LineMetaDataContent::Tramway, Color{0x967b68} }, // 13 OSM: 2003476 WD: Q63442554 50.91, 6.908 x 50.97, 7.038
    { 6, NoLogo, 976, LineMetaDataContent::Tramway, Color{0x948fb8} }, // 5 OSM: 2003477 WD: Q63442534 50.93, 6.888 x 50.98, 6.96
    { 1273, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc4121a} }, // 31 OSM: 2005491 WD: Q47565641 48.22, 16.37 x 48.3, 16.42
    { 400, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc4121a} }, // 30 OSM: 2005591 WD: Q47564751 48.26, 16.4 x 48.3, 16.42
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x88822a} }, // 5 OSM: 2024979 WD: Q16655756 50.02, 14.35 x 50.09, 14.48
    { 68, NoLogo, 976, LineMetaDataContent::Tramway, Color{0xe693b5} }, // 3 OSM: 2026288 WD: Q63442521 50.93, 6.87 x 50.98, 7.086
    { 94, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x98c000} }, // 61 OSM: 2026289 WD: Q20035840 50.7, 7.071 x 50.76, 7.112
    { 105, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x61af20} }, // 62 OSM: 2026290 WD: Q20035841 50.7, 7.095 x 50.74, 7.176
    { 90, NoLogo, 976, LineMetaDataContent::Tramway, Color{0x60d6f7} }, // 63 OSM: 2026291 WD: Q20035835 50.68, 7.047 x 50.75, 7.159
    { 1279, NoLogo, 976, LineMetaDataContent::Tramway, Color{0xe5007d} }, // 66 OSM: 2026292 WD: Q20035836 50.64, 7.092 x 50.79, 7.217
    { 231, NoLogo, 976, LineMetaDataContent::Tramway, Color{0xee99bf} }, // 67 OSM: 2026293 WD: Q20035837 50.68, 7.092 x 50.79, 7.203
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x149a93} }, // 6 OSM: 2032473 WD: Q16655760 50.07, 14.42 x 50.11, 14.48
    { 47, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe31e25} }, // 7 OSM: 2061854 WD: Q16655764 50.06, 14.39 x 50.11, 14.55
    { 64, 7529, NoLogo, LineMetaDataContent::Tramway, Color{0x009cdd} }, // 1 OSM: 2067963 WD: Q12804359 53.41, 14.49 x 53.46, 14.56
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x605047} }, // 8 OSM: 2070554 WD: Q16655766 50.09, 14.39 x 50.11, 14.53
    { 15, 7549, NoLogo, LineMetaDataContent::Tramway, Color{0x009cdd} }, // 12 OSM: 2074000 WD: Q28792440 53.4, 14.53 x 53.45, 14.55
    { 289, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe3002b} }, // T1 OSM: 2074462 48.65, 6.145 x 48.7, 6.225
    { 6, 7570, NoLogo, LineMetaDataContent::Tramway, Color{0x009cdd} }, // 5 OSM: 2077222 WD: Q25501513 53.43, 14.49 x 53.46, 14.58
    { 63, 7590, NoLogo, LineMetaDataContent::Tramway, Color{0x009cdd} }, // 11 OSM: 2077355 WD: Q32946105 53.4, 14.53 x 53.45, 14.58
    { 27, 7611, NoLogo, LineMetaDataContent::Tramway, Color{0x009cdd} }, // 6 OSM: 2077516 WD: Q26003028 53.42, 14.55 x 53.48, 14.61
    { 19, 7631, NoLogo, LineMetaDataContent::Tramway, Color{0x009cdd} }, // 8 OSM: 2080359 WD: Q26160394 53.38, 14.49 x 53.43, 14.64
    { 47, 7651, NoLogo, LineMetaDataContent::Tramway, Color{0x009cdd} }, // 7 OSM: 2080360 WD: Q26111009 53.38, 14.49 x 53.46, 14.64
    { 68, 7671, NoLogo, LineMetaDataContent::Tramway, Color{0xef7c00} }, // 3 OSM: 2083643 WD: Q99229508 48.27, 10.88 x 48.37, 10.9
    { 27, 7691, NoLogo, LineMetaDataContent::Tramway, Color{0x94c11c} }, // 6 OSM: 2083654 WD: Q121146595 48.35, 10.84 x 48.37, 10.96
    { 146, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x43ac3c} }, // 9 OSM: 2088592 WD: Q16655771 50.06, 14.3 x 50.09, 14.5
    { 64, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xb5c426} }, // 1 OSM: 2100315 WD: Q6811945 -37.85, 144.9 x -37.74, 145
    { 250, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00aadc} }, // N20 OSM: 2101204 48.14, 11.51 x 48.18, 11.57
    { 64, 7711, 976, LineMetaDataContent::Tramway, Color{0x0000ff} }, // 1 OSM: 2102327 WD: Q117468577 51.98, 8.502 x 52.06, 8.546
    { 68, 7731, 976, LineMetaDataContent::Tramway, Color{0xffff00} }, // 3 OSM: 2102329 WD: Q117468931 52.02, 8.518 x 52.06, 8.543
    { 16, 7751, 976, LineMetaDataContent::Tramway, Color{0x008000} }, // 2 OSM: 2102391 WD: Q117468882 52, 8.532 x 52.06, 8.628
    { 9, 7771, 976, LineMetaDataContent::Tramway, Color{0xff0000} }, // 4 OSM: 2102392 WD: Q117468952 52, 8.485 x 52.05, 8.589
    { 1282, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffc56b} }, // 금수산태양궁전궤도전차 OSM: 2102520 WD: Q121507263 39.06, 125.8 x 39.07, 125.8
    { 1319, 7791, 226, LineMetaDataContent::RapidTransit, Color{0xe7526b} }, // S20 OSM: 2113865 WD: Q7388223 48.04, 11.04 x 48.18, 11.54
    { 46, 7808, 226, LineMetaDataContent::RapidTransit, Color{0x983224} }, // S7 OSM: 2113867 WD: Q7388364 47.91, 11.42 x 48.14, 11.78
    { 239, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf58220} }, // 17 OSM: 2114099 WD: Q116950113 45.79, 15.89 x 45.82, 16.02
    { 64, 7824, 7868, LineMetaDataContent::Tramway, Color{0x00a651} }, // 1 OSM: 2116454 WD: Q3238670 47.2, -1.639 x 47.26, -1.515
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x9a94c8} }, // 5 OSM: 2136277 WD: Q117157320 45.79, 15.89 x 45.82, 16.02
    { 68, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc96e80} }, // 3 OSM: 2149224 WD: Q17440804 45.79, 15.94 x 45.8, 16.04
    { 1323, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x4dbe63} }, // Тр3 OSM: 2161840 WD: Q124709844 49.81, 24 x 49.84, 24.04
    { 1329, 7898, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf37021} }, // T3 OSM: 2166474 WD: Q2407219 -33.93, 150.9 x -33.86, 151.2
    { 16, 7911, 7868, LineMetaDataContent::Tramway, Color{0xee1c25} }, // 2 OSM: 2166523 WD: Q3238813 47.19, -1.593 x 47.26, -1.542
    { 68, 7955, 7868, LineMetaDataContent::Tramway, Color{0x006db1} }, // 3 OSM: 2166524 WD: Q3238913 47.18, -1.617 x 47.25, -1.542
    { 1332, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8e4b34} }, // Тр2 OSM: 2169223 WD: Q124709803 49.82, 23.99 x 49.84, 24.07
    { 1338, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x35ccf5} }, // Тр4 OSM: 2171616 WD: Q124735420 49.78, 23.99 x 49.84, 24.06
    { 19, 7999, NoLogo, LineMetaDataContent::RapidTransit, Color{0x808080} }, // 8 OSM: 2174536 WD: Q3296720 -23.55, -46.98 x -23.51, -46.64
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc96d6a} }, // 4 OSM: 2180576 WD: Q116969401 45.79, 15.95 x 45.83, 16.08
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf8a98e} }, // 6 OSM: 2183641 WD: Q17440873 45.78, 15.93 x 45.82, 16
    { 146, 8010, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00a88e} }, // 9 OSM: 2183695 WD: Q5245848 -23.76, -46.78 x -23.53, -46.69
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x666666} }, // 2 OSM: 2189262 WD: Q121590540 45.55, 18.68 x 45.56, 18.73
    { 161, NoLogo, 3346, LineMetaDataContent::Tramway, Color{0xce1417} }, // 19 OSM: 2191470 WD: Q123339551 50.46, 30.45 x 50.52, 30.52
    { 314, 8021, 226, LineMetaDataContent::RapidTransit, Color{0x000080} }, // S4 OSM: 2199152 WD: Q7388307 49.25, 10.3 x 49.44, 11.08
    { 344, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xbe1622} }, // 45 OSM: 2202119 WD: Q121368501 44.45, 26.02 x 44.49, 26.08
    { 26, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xbe1622} }, // 16 OSM: 2202705 WD: Q97192577 44.43, 26.11 x 44.48, 26.13
    { 16, 8038, NoLogo, LineMetaDataContent::Tramway, Color{0x0071bc} }, // 2 OSM: 2203208 WD: Q121359742 48.98, 8.345 x 49.04, 8.479
    { 1256, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xbe1622} }, // 36 OSM: 2203210 WD: Q121368246 44.43, 26.11 x 44.48, 26.19
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xbe1622} }, // 5 OSM: 2203626 WD: Q121368338 44.43, 26.08 x 44.5, 26.11
    { 63, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xbe1622} }, // 11 OSM: 2205114 WD: Q85980501 44.39, 26.02 x 44.47, 26.09
    { 302, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xbe1622} }, // 46 OSM: 2205366 44.43, 26.08 x 44.46, 26.19
    { 153, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xbe1622} }, // 14 OSM: 2206781 WD: Q97192564 44.43, 26.11 x 44.45, 26.18
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x1c63b7} }, // 2 OSM: 2206997 WD: Q104521890 41.91, 12.46 x 41.93, 12.48
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xed1c24} }, // 5 OSM: 2206998 WD: Q104537333 41.88, 12.5 x 41.9, 12.57
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xbfdf14} }, // 8 OSM: 2206999 WD: Q104537360 41.87, 12.44 x 41.9, 12.52
    { 82, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xbe1622} }, // 21 OSM: 2207121 WD: Q99757067 44.43, 26.1 x 44.48, 26.16
    { 712, 8058, 8099, LineMetaDataContent::Subway, Color{0xf68b1f} }, // A OSM: 2207255 WD: Q572544 41.84, 12.42 x 41.91, 12.59
    { 279, 8129, 8099, LineMetaDataContent::Subway, Color{0x3783c6} }, // B OSM: 2208346 WD: Q2666571 41.83, 12.46 x 41.95, 12.57
    { 1344, 8170, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfbbc09} }, // FC1 OSM: 2208347 WD: Q3743595 41.87, 12.51 x 41.9, 12.56
    { 548, 8200, NoLogo, LineMetaDataContent::Subway, Color{0x7eb9e6} }, // E OSM: 2208348 WD: Q1088941 41.71, 12.28 x 41.88, 12.48
    { 1348, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7e7bb4} }, // FC3 OSM: 2208349 41.91, 12.48 x 42.01, 12.5
    { 153, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00adef} }, // 14 OSM: 2208350 WD: Q415821 41.89, 12.5 x 41.9, 12.57
    { 161, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf89c0e} }, // 19 OSM: 2208351 WD: Q104537271 41.88, 12.46 x 41.92, 12.57
    { 519, 8223, NoLogo, LineMetaDataContent::RapidTransit, Color{0x007663} }, // FL1 OSM: 2208499 WD: Q3737286 41.79, 12.25 x 42.44, 12.65
    { 523, 8258, NoLogo, LineMetaDataContent::RapidTransit, Color{0x004174} }, // FL2 OSM: 2208500 WD: Q3737287 41.9, 12.53 x 42.1, 13.43
    { 527, 8293, NoLogo, LineMetaDataContent::RapidTransit, Color{0x88aca0} }, // FL3 OSM: 2208501 WD: Q3737289 41.87, 12.08 x 42.43, 12.53
    { 515, 8328, NoLogo, LineMetaDataContent::RapidTransit, Color{0x965b0e} }, // FL4 OSM: 2208502 WD: Q25064 41.67, 12.5 x 41.9, 12.78
    { 1352, 8363, NoLogo, LineMetaDataContent::RapidTransit, Color{0xdccc00} }, // FL5 OSM: 2208503 WD: Q3737292 41.86, 11.8 x 42.09, 12.53
    { 1356, 8398, NoLogo, LineMetaDataContent::RapidTransit, Color{0xd880b4} }, // FL6 OSM: 2208504 WD: Q3737295 41.48, 12.5 x 41.9, 13.83
    { 1360, 8433, NoLogo, LineMetaDataContent::RapidTransit, Color{0x9acc66} }, // FL7 OSM: 2208505 WD: Q661786 41.25, 12.5 x 41.9, 13.72
    { 1364, 8468, NoLogo, LineMetaDataContent::RapidTransit, Color{0x6cbf68} }, // FL8 OSM: 2208506 WD: Q3737301 41.45, 12.5 x 41.9, 12.66
    { 1368, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xca0a23} }, // LEX OSM: 2208507 WD: Q1207539 41.79, 12.25 x 41.9, 12.53
    { 255, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xbe1622} }, // 24 OSM: 2208755 WD: Q121368425 44.44, 26.04 x 44.49, 26.09
    { 274, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xbe1622} }, // 40 OSM: 2210742 WD: Q121368458 44.41, 26.11 x 44.44, 26.2
    { 235, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xbe1622} }, // 27 OSM: 2211466 WD: Q121368436 44.41, 26.09 x 44.43, 26.2
    { 349, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xbe1622} }, // 23 OSM: 2211745 WD: Q121368420 44.39, 26.07 x 44.43, 26.18
    { 75, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xbe1622} }, // 10 OSM: 2212352 WD: Q61085901 44.39, 26.05 x 44.45, 26.14
    { 64, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe31e24} }, // 1 OSM: 2212352 WD: Q61085901 44.39, 26.05 x 44.45, 26.14
    { 19, 8503, 8524, LineMetaDataContent::Tramway, Color{0x169fdb} }, // 8 OSM: 2262665 WD: Q431783 50.8, 4.353 x 50.85, 4.44
    { 1372, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008c99} }, // 635 OSM: 2271832 32.72, -117.4 x 33.19, -117.2
    { 1272, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008c99} }, // 631 OSM: 2271832 32.72, -117.4 x 33.19, -117.2
    { 305, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008c99} }, // 665 OSM: 2271832 32.72, -117.4 x 33.19, -117.2
    { 535, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008c99} }, // 657 OSM: 2271832 32.72, -117.4 x 33.19, -117.2
    { 1376, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008c99} }, // 655 OSM: 2271832 32.72, -117.4 x 33.19, -117.2
    { 659, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008c99} }, // 639 OSM: 2271832 32.72, -117.4 x 33.19, -117.2
    { 101, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0092d8} }, // TER 62 OSM: 2272886 WD: Q120094802 45.15, 5.417 x 45.57, 6.045
    { 1380, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0092d8} }, // TER 60 OSM: 2274103 WD: Q120094799 45.15, 5.417 x 45.57, 6.045
    { 1390, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x669933} }, // 87 OSM: 2282096 WD: Q121341867 52.44, 13.69 x 52.46, 13.76
    { 1393, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf39ec4} }, // T4 OSM: 2305411 WD: Q108046070 50.29, 18.73 x 50.31, 18.83
    { 712, 8550, 2986, LineMetaDataContent::RapidTransit, Color{0xe3051c} }, // A OSM: 2333448 WD: Q741818 48.75, 2.012 x 49.05, 2.782
    { 1329, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf1665b} }, // T3 OSM: 2335747 WD: Q108045397 50.27, 18.73 x 50.34, 18.79
    { 64, 8582, NoLogo, LineMetaDataContent::Subway, Color{0xe4002b} }, // 1 OSM: 2336458 WD: Q263572 29.53, 106.2 x 29.62, 106.6
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfbba00} }, // 2 OSM: 2344988 WD: Q121305020 50.84, 12.05 x 50.85, 12.08
    { 174, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 52 OSM: 2345812 59.83, 30.14 x 59.88, 30.26
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe30613} }, // 4 OSM: 2368452 WD: Q121196133 50.72, 12.43 x 50.75, 12.49
    { 75, 8607, NoLogo, LineMetaDataContent::Tramway, Color{0x009cdd} }, // 10 OSM: 2372195 WD: Q26298715 53.42, 14.49 x 53.43, 14.56
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xa8d4af} }, // 8 OSM: 2375053 WD: Q120720205 50.01, 19.88 x 50.08, 19.95
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfdc434} }, // 2 OSM: 2380276 WD: Q1488541 46.24, 20.13 x 46.27, 20.15
    { 64, 8628, NoLogo, LineMetaDataContent::Subway, Color{0x10069f} }, // 1 OSM: 2381769 WD: Q6118988 30.39, 104.1 x 30.72, 104.1
    { 314, 8638, NoLogo, LineMetaDataContent::RapidTransit, Color{0x9f184c} }, // S4 OSM: 2395148 WD: Q106362966 48.99, 8.349 x 49.48, 9.528
    { 64, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0c7cac} }, // 1 OSM: 2395313 WD: Q122307220 51.1, 17.03 x 51.15, 17.11
    { 75, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0c7cac} }, // 10 OSM: 2395314 WD: Q122307228 51.1, 16.87 x 51.15, 17.11
    { 63, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0c7cac} }, // 11 OSM: 2395315 WD: Q122307229 51.08, 16.97 x 51.13, 17.07
    { 153, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0c7cac} }, // 14 OSM: 2395316 WD: Q122307232 51.07, 16.98 x 51.14, 17.03
    { 157, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0c7cac} }, // 15 OSM: 2395317 WD: Q122307233 51.07, 17.01 x 51.15, 17.03
    { 239, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0c7cac} }, // 17 OSM: 2395318 WD: Q122307235 51.07, 16.99 x 51.12, 17.1
    { 68, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0c7cac} }, // 3 OSM: 2395323 WD: Q122307221 51.08, 16.87 x 51.15, 17.08
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0c7cac} }, // 4 OSM: 2395324 WD: Q122307222 51.08, 16.97 x 51.11, 17.11
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0c7cac} }, // 5 OSM: 2395325 WD: Q122307223 51.08, 16.98 x 51.11, 17.08
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0c7cac} }, // 6 OSM: 2395326 WD: Q122307224 51.07, 17.01 x 51.13, 17.1
    { 47, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0c7cac} }, // 7 OSM: 2395327 WD: Q122307225 51.07, 16.99 x 51.15, 17.04
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0c7cac} }, // 8 OSM: 2395328 WD: Q122307226 51.08, 17.03 x 51.13, 17.06
    { 146, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0c7cac} }, // 9 OSM: 2395329 WD: Q122307227 51.07, 17.01 x 51.12, 17.1
    { 22, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0c7cac} }, // 18 OSM: 2395331 WD: Q122307236 51.08, 16.95 x 51.14, 17.05
    { 82, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0c7cac} }, // 21 OSM: 2395338 WD: Q122307238 51.08, 16.95 x 51.14, 17.05
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0c7cac} }, // 12 OSM: 2395339 WD: Q122307230 51.11, 16.96 x 51.14, 17.1
    { 55, 8654, NoLogo, LineMetaDataContent::RapidTransit, Color{0x04a5c8} }, // S8 OSM: 2396232 WD: Q110714378 41.35, 1.919 x 41.48, 2.148
    { 1396, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8e0043} }, // T5 OSM: 2396696 WD: Q108046096 50.29, 18.73 x 50.35, 18.92
    { 355, 8671, 226, LineMetaDataContent::RapidTransit, Color{0xf8a20d} }, // S51 OSM: 2412316 WD: Q96388878 49.3, 8.674 x 49.42, 8.991
    { 75, 8691, NoLogo, LineMetaDataContent::Tramway, Color{0xb4e16e} }, // 10 OSM: 2413392 WD: Q106921203 57.68, 11.89 x 57.73, 11.98
    { 19, 8714, NoLogo, LineMetaDataContent::Tramway, Color{0x872387} }, // 8 OSM: 2413517 WD: Q10562727 57.65, 11.91 x 57.8, 12.05
    { 67, 8736, NoLogo, LineMetaDataContent::Tramway, Color{0xfee6c2} }, // 13 OSM: 2413518 WD: Q10562720 57.66, 11.85 x 57.72, 11.99
    { 16, 8759, NoLogo, LineMetaDataContent::Tramway, Color{0xfff014} }, // 2 OSM: 2413613 WD: Q106921120 57.67, 11.93 x 57.71, 12
    { 9, 8781, NoLogo, LineMetaDataContent::Tramway, Color{0x14823c} }, // 4 OSM: 2413615 WD: Q106921167 57.65, 11.97 x 57.8, 12.05
    { 738, 8803, 226, LineMetaDataContent::RapidTransit, Color{0xba8a4d} }, // S47 OSM: 2413847 WD: Q3742025 52.45, 13.43 x 52.47, 13.56
    { 68, 8834, NoLogo, LineMetaDataContent::Tramway, Color{0x004b85} }, // 3 OSM: 2418220 WD: Q106921163 57.67, 11.91 x 57.72, 12.03
    { 146, 8856, NoLogo, LineMetaDataContent::Tramway, Color{0x6ec8dc} }, // 9 OSM: 2418235 WD: Q106921200 57.68, 11.9 x 57.8, 12.05
    { 63, 8878, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 11 OSM: 2418236 WD: Q106921207 57.66, 11.85 x 57.76, 12.07
    { 1399, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // 901 OSM: 2440421 WD: Q1617191 44.85, -93.28 x 44.98, -93.2
    { 347, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x787fbc} }, // RB23 OSM: 2441590 WD: Q1699351 50.56, 6.761 x 50.74, 7.098
    { 113, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf0e130} }, // 888 OSM: 2442946 44.98, -93.73 x 45.33, -93.25
    { 71, 8901, 226, LineMetaDataContent::RapidTransit, Color{0x109c37} }, // S1 OSM: 2444997 WD: Q7388210 51.16, 6.772 x 51.52, 7.46
    { 62, 8912, 226, LineMetaDataContent::RapidTransit, Color{0xf39200} }, // S11 OSM: 2445000 WD: Q7388174 50.94, 6.674 x 51.28, 7.125
    { 1096, 8924, 226, LineMetaDataContent::RapidTransit, Color{0x009640} }, // S12 OSM: 2445001 WD: Q7388180 50.76, 6.713 x 50.95, 7.66
    { 751, 8936, 226, LineMetaDataContent::RapidTransit, Color{0x00a6eb} }, // S13 OSM: 2445007 WD: Q7388184 50.81, 6.482 x 50.95, 7.151
    { 59, 8948, 226, LineMetaDataContent::RapidTransit, Color{0x006db6} }, // S2 OSM: 2445008 WD: Q7388251 51.45, 7.015 x 51.62, 7.46
    { 1124, 8959, 226, LineMetaDataContent::RapidTransit, Color{0x4a0b4d} }, // S28 OSM: 2445009 WD: Q7388234 51.2, 6.594 x 51.25, 7.153
    { 225, 8971, 226, LineMetaDataContent::RapidTransit, Color{0xffff00} }, // S3 OSM: 2445010 WD: Q7388285 51.4, 6.835 x 51.48, 7.181
    { 314, 8982, 226, LineMetaDataContent::RapidTransit, Color{0xf5821f} }, // S4 OSM: 2445011 WD: Q7388319 51.5, 7.334 x 51.55, 7.692
    { 52, 8993, 226, LineMetaDataContent::RapidTransit, Color{0x98c60f} }, // S5 OSM: 2445012 WD: Q7388333 51.36, 7.325 x 51.52, 7.46
    { 298, 9004, 226, LineMetaDataContent::RapidTransit, Color{0xe6007e} }, // S6 OSM: 2445013 WD: Q7388349 50.94, 6.79 x 51.45, 7.023
    { 97, 9015, 226, LineMetaDataContent::RapidTransit, Color{0x14bae6} }, // S68 OSM: 2445014 WD: Q7388346 51.1, 6.79 x 51.23, 7.074
    { 55, 9027, 226, LineMetaDataContent::RapidTransit, Color{0xb23815} }, // S8 OSM: 2445015 WD: Q7388383 51.19, 6.445 x 51.36, 7.46
    { 645, 9038, 226, LineMetaDataContent::RapidTransit, Color{0xc7007f} }, // S9 OSM: 2445016 WD: Q7388395 51.23, 6.921 x 51.74, 7.46
    { 71, 9049, 226, LineMetaDataContent::RapidTransit, Color{0xec192e} }, // S1 OSM: 2445551 WD: Q67858837 49.33, 7.334 x 49.48, 9.424
    { 59, 9068, 226, LineMetaDataContent::RapidTransit, Color{0x2960b5} }, // S2 OSM: 2445552 WD: Q64667644 49.34, 7.768 x 49.48, 9.144
    { 225, 9087, 226, LineMetaDataContent::RapidTransit, Color{0x00a896} }, // S3 OSM: 2445553 WD: Q2781002 49.87, 8.504 x 50.16, 8.699
    { 225, 9104, 226, LineMetaDataContent::RapidTransit, Color{0xfcd804} }, // S3 OSM: 2445554 WD: Q68929824 48.98, 8.262 x 49.48, 8.685
    { 64, 9123, 9143, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 2446076 WD: Q519861 59.84, 30.25 x 60.05, 30.44
    { 16, 9162, 9143, LineMetaDataContent::Subway, Color{0x0000ff} }, // 2 OSM: 2446077 WD: Q1459627 59.83, 30.3 x 60.07, 30.38
    { 68, 9182, 9143, LineMetaDataContent::Subway, Color{0x008000} }, // 3 OSM: 2446078 WD: Q1509576 59.83, 30.2 x 59.99, 30.5
    { 9, 9202, 9143, LineMetaDataContent::Subway, Color{0xffa500} }, // 4 OSM: 2446079 WD: Q1784097 59.91, 30.32 x 59.93, 30.48
    { 6, 9222, 9143, LineMetaDataContent::Subway, Color{0x800080} }, // 5 OSM: 2446080 WD: Q1579583 59.82, 30.25 x 60.01, 30.43
    { 725, 9242, 9264, LineMetaDataContent::Tramway, Color{0xf5e615} }, // T2 OSM: 2449769 WD: Q3238811 43.3, 5.367 x 43.32, 5.406
    { 289, 9285, 9264, LineMetaDataContent::Tramway, Color{0xf18e00} }, // T1 OSM: 2452278 WD: Q3238668 43.29, 5.381 x 43.3, 5.444
    { 1403, 9307, 9336, LineMetaDataContent::Tramway, Color{0xa7ce39} }, // TT OSM: 2466526 WD: Q2448517 47.74, 7.088 x 47.81, 7.344
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xab0000} }, // 2 OSM: 2468631 WD: Q122681310 50.75, 15.03 x 50.78, 15.08
    { 68, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xab0000} }, // 3 OSM: 2468632 WD: Q122681352 50.74, 15.01 x 50.78, 15.08
    { 63, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xab0000} }, // 11 OSM: 2468639 WD: Q122681278 50.72, 15.04 x 50.77, 15.17
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xab0000} }, // 5 OSM: 2468640 WD: Q122681379 50.74, 15.04 x 50.77, 15.1
    { 1406, 9359, 9383, LineMetaDataContent::Subway, Color{0x10069f} }, // Μ3 OSM: 2473158 WD: Q6553119 37.91, 23.64 x 38.02, 23.95
    { 225, 9437, 226, LineMetaDataContent::RapidTransit, Color{0xdb6eab} }, // S3 OSM: 2474189 WD: Q63433452 52.16, 9.739 x 52.38, 10.02
    { 52, 9453, 226, LineMetaDataContent::RapidTransit, Color{0xf78a18} }, // S5 OSM: 2474199 WD: Q63433456 51.71, 8.737 x 52.46, 9.773
    { 16, 9469, 9495, LineMetaDataContent::Subway, Color{0x0000ff} }, // 2 OSM: 2507796 WD: Q2001449 41.29, 69.2 x 41.35, 69.32
    { 68, 9519, 9495, LineMetaDataContent::Subway, Color{0x008000} }, // 3 OSM: 2507797 WD: Q4534678 41.3, 69.27 x 41.38, 69.3
    { 64, 9545, 9495, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 2507927 WD: Q4515924 41.21, 69.19 x 41.33, 69.33
    { 52, 9571, 226, LineMetaDataContent::RapidTransit, Color{0xa52a2a} }, // S5 OSM: 2515355 WD: Q2515085 50.1, 8.583 x 50.25, 8.699
    { 314, 9588, 226, LineMetaDataContent::RapidTransit, Color{0xfecb09} }, // S4 OSM: 2515408 WD: Q2204443 49.99, 8.516 x 50.18, 8.699
    { 1410, 9605, NoLogo, LineMetaDataContent::LocalTrain, Color{0x0080ff} }, // RE5 OSM: 2523198 WD: Q50374543 52.47, 12.11 x 54.31, 13.46
    { 1414, 9624, NoLogo, LineMetaDataContent::LocalTrain, Color{0x80004d} }, // RE4 OSM: 2523200 WD: Q15195675 52, 12.35 x 52.6, 13.38
    { 68, 9643, NoLogo, LineMetaDataContent::Tramway, Color{0xe31f25} }, // 3 OSM: 2529467 WD: Q21041078 48.12, 17.11 x 48.22, 17.17
    { 146, 9668, NoLogo, LineMetaDataContent::Tramway, Color{0x829714} }, // 9 OSM: 2529468 WD: Q21041086 48.14, 17.05 x 48.17, 17.18
    { 67, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 13 OSM: 2529840 WD: Q122585354 55.77, 37.65 x 55.83, 37.77
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x800080} }, // 5 OSM: 2531144 WD: Q121338696 49.72, 9.925 x 49.8, 9.968
    { 68, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0066ff} }, // 3 OSM: 2531145 WD: Q121338683 49.74, 9.925 x 49.8, 9.961
    { 64, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffbb00} }, // 1 OSM: 2531240 WD: Q100555102 49.77, 9.929 x 49.8, 9.955
    { 64, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff2e17} }, // 1 OSM: 2531659 WD: Q121311468 50.93, 10.67 x 50.95, 10.71
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xaf2a21} }, // 2 OSM: 2531812 WD: Q121315985 50.94, 10.71 x 50.96, 10.72
    { 68, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff9929} }, // 3 OSM: 2531813 WD: Q121315996 50.94, 10.68 x 50.96, 10.72
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffb530} }, // 4 OSM: 2531864 WD: Q2430929 50.86, 10.52 x 50.95, 10.71
    { 46, 9693, 226, LineMetaDataContent::RapidTransit, Color{0x00afb5} }, // S7 OSM: 2544304 WD: Q1195962 51.16, 7.004 x 51.28, 7.253
    { 1418, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff3818} }, // Тр1 OSM: 2548724 WD: Q1032126 49.83, 24 x 49.84, 24.06
    { 1424, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8144a3} }, // Тр6 OSM: 2548730 WD: Q124735422 49.84, 24 x 49.87, 24.04
    { 71, 9704, 226, LineMetaDataContent::RapidTransit, Color{0x7760b0} }, // S1 OSM: 2548861 WD: Q63433445 52.27, 8.934 x 52.42, 9.773
    { 1430, 9720, 9742, LineMetaDataContent::RapidTransit, Color{0x005d30} }, // RE29 OSM: 2550762 WD: Q1374322 50.56, 5.559 x 50.77, 6.093
    { 1435, 9764, 9802, LineMetaDataContent::Subway, Color{0x82dc73} }, // 7bis OSM: 2554103 WD: Q50749 48.88, 2.365 x 48.88, 2.4
    { 298, 9835, 226, LineMetaDataContent::RapidTransit, Color{0x005aab} }, // S6 OSM: 2557420 WD: Q63433460 52.37, 9.739 x 52.62, 10.06
    { 19, NoLogo, 3346, LineMetaDataContent::Tramway, Color{0xce1417} }, // 8 OSM: 2560439 WD: Q123339544 50.4, 30.63 x 50.46, 30.66
    { 1125, NoLogo, 3346, LineMetaDataContent::Tramway, Color{0xce1417} }, // 28 OSM: 2561862 WD: Q123339554 50.46, 30.6 x 50.53, 30.64
    { 118, NoLogo, 3346, LineMetaDataContent::Tramway, Color{0xce1417} }, // 22 OSM: 2561865 WD: Q123339552 50.42, 30.6 x 50.49, 30.69
    { 1440, 9851, 9874, LineMetaDataContent::Subway, Color{0x62361b} }, // Brown OSM: 2562976 WD: Q3112936 41.88, -87.71 x 41.97, -87.63
    { 314, 9903, 226, LineMetaDataContent::RapidTransit, Color{0x972f50} }, // S4 OSM: 2567719 WD: Q63433455 52.16, 9.687 x 52.58, 9.957
    { 8, 9919, 9935, LineMetaDataContent::Subway, Color{0x228b22} }, // M4 OSM: 2568424 WD: Q2552821 44.45, 26.03 x 44.5, 26.07
    { 524, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x9ecd58} }, // L2 OSM: 2568862 WD: Q115328482 59.72, 10.61 x 59.92, 10.84
    { 1316, 9953, 9964, LineMetaDataContent::RapidTransit, Color{0x2e8ec7} }, // S2/S20 OSM: 2569296 WD: Q108084309 52.17, 20.94 x 52.26, 21.3
    { 289, 9982, 6136, LineMetaDataContent::Tramway, Color{0x216eb4} }, // T1 OSM: 2572573 WD: Q369969 48.9, 2.274 x 48.94, 2.47
    { 520, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x9ecd58} }, // L1 OSM: 2575540 WD: Q115217962 59.74, 10.34 x 59.96, 11.05
    { 1446, 10015, 9874, LineMetaDataContent::Subway, Color{0xf9461c} }, // Orange OSM: 2578312 WD: Q3180068 41.79, -87.74 x 41.89, -87.63
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xdb7093} }, // 2 OSM: 2578716 WD: Q48759284 32.78, 130.7 x 32.8, 130.8
    { 68, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x1e90ff} }, // 3 OSM: 2578717 WD: Q48759291 32.78, 130.7 x 32.82, 130.8
    { 1453, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 100 OSM: 2579608 60, 30.34 x 60.06, 30.44
    { 64, 10040, 10059, LineMetaDataContent::Subway, Color{0xe50b00} }, // 1 OSM: 2580502 WD: Q1771534 56.24, 43.86 x 56.32, 43.99
    { 1457, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xa52a2a} }, // Scala mobile OSM: 2581270 41.84, 12.89 x 41.84, 12.89
    { 379, 10071, 9874, LineMetaDataContent::Subway, Color{0xc60c30} }, // Red OSM: 2584583 WD: Q642623 41.72, -87.67 x 42.02, -87.62
    { 298, 10092, 226, LineMetaDataContent::RapidTransit, Color{0xec192e} }, // S6 OSM: 2587144 WD: Q96388302 49.44, 8.242 x 50.07, 8.667
    { 725, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x228b22} }, // T2 OSM: 2597272 WD: Q113671831 45.46, 12.21 x 45.49, 12.25
    { 1470, 10111, 226, LineMetaDataContent::RapidTransit, Color{0x6b2c94} }, // S 8 OSM: 2605126 WD: Q63213955 51.47, 11.98 x 51.87, 12.66
    { 880, 273, 226, LineMetaDataContent::RapidTransit, Color{0xf17f1a} }, // S 5 OSM: 2606971 WD: Q63216051 50.7, 11.99 x 51.48, 12.48
    { 1474, 10136, NoLogo, LineMetaDataContent::LocalTrain, Color{0xa5027d} }, // RB14 OSM: 2607468 WD: Q15119376 52.36, 12.88 x 52.61, 13.6
    { 1479, 10156, 226, LineMetaDataContent::RapidTransit, Color{0x00a650} }, // S 4 OSM: 2607472 WD: Q63215993 51.25, 12.37 x 51.59, 13.25
    { 1483, 10181, NoLogo, LineMetaDataContent::LocalTrain, Color{0x0474ec} }, // RE 18 OSM: 2607473 WD: Q63348135 51.04, 13.5 x 51.75, 14.33
    { 1489, 10201, NoLogo, LineMetaDataContent::LocalTrain, Color{0xffe600} }, // RE2 OSM: 2607475 WD: Q15119419 51.75, 11.36 x 53.9, 14.33
    { 1493, 10220, NoLogo, LineMetaDataContent::LocalTrain, Color{0x00a25d} }, // RE 15 OSM: 2607476 WD: Q105947741 51.04, 13.5 x 51.46, 14.23
    { 71, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x66cdaa} }, // S1 OSM: 2609006 WD: Q50331474 54.08, 12.06 x 54.18, 12.13
    { 1499, 10240, NoLogo, LineMetaDataContent::LocalTrain, Color{0x36803d} }, // RE1 OSM: 2609008 WD: Q19624774 53.36, 10 x 54.08, 12.15
    { 225, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0xa66540} }, // S3 OSM: 2609009 WD: Q50331483 53.79, 12.06 x 54.18, 12.35
    { 59, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x9400d3} }, // S2 OSM: 2609011 WD: Q50331479 53.8, 12.06 x 54.18, 12.17
    { 728, 10256, NoLogo, LineMetaDataContent::LocalTrain, Color{0xff5900} }, // RE3 OSM: 2609916 WD: Q15195663 51.58, 12.66 x 54.31, 14.29
    { 1503, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff9700} }, // SFM 1 OSM: 2610264 WD: Q3832755 44.97, 7.603 x 45.42, 7.824
    { 1509, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // SFM 4 OSM: 2610270 WD: Q3832758 44.69, 7.602 x 45.23, 8.031
    { 653, 10275, 9874, LineMetaDataContent::Subway, Color{0x009b3a} }, // Green OSM: 2613599 WD: Q3176204 41.78, -87.81 x 41.89, -87.61
    { 1515, 10298, 976, LineMetaDataContent::Tramway, Color{0x7fd2e6} }, // U44 OSM: 2615764 WD: Q121288210 51.51, 7.385 x 51.53, 7.484
    { 82, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe2000a} }, // 21 OSM: 2617691 WD: Q121338914 49.4, 8.675 x 49.43, 8.693
    { 118, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfcc200} }, // 22 OSM: 2617692 WD: Q121338815 49.4, 8.627 x 49.41, 8.693
    { 349, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe48e00} }, // 23 OSM: 2617693 WD: Q121338937 49.34, 8.685 x 49.41, 8.693
    { 255, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8b1c75} }, // 24 OSM: 2617694 WD: Q121338925 49.37, 8.66 x 49.47, 8.691
    { 318, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf39a9a} }, // 26 OSM: 2617695 WD: Q121338888 49.38, 8.658 x 49.43, 8.693
    { 64, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf39b9b} }, // 1 OSM: 2619044 WD: Q121317818 49.42, 8.463 x 49.55, 8.536
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xb10346} }, // 2 OSM: 2619045 WD: Q121317819 49.48, 8.457 x 49.5, 8.539
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe3000b} }, // 4 OSM: 2619046 WD: Q121317822 49.46, 8.17 x 49.54, 8.509
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00975f} }, // 5 OSM: 2619047 WD: Q111985934 49.4, 8.463 x 49.55, 8.693
    { 68, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xd6ad00} }, // 3 OSM: 2621587 WD: Q121317820 49.45, 8.449 x 49.54, 8.482
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x966c29} }, // 6 OSM: 2621588 WD: Q121317824 49.44, 8.419 x 49.49, 8.525
    { 47, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffcc00} }, // 7 OSM: 2621590 WD: Q121317825 49.48, 8.407 x 49.52, 8.545
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe17500} }, // 8 OSM: 2621591 WD: Q121317826 49.42, 8.407 x 49.52, 8.536
    { 1519, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfcdc12} }, // SFM7 OSM: 2622309 WD: Q15077685 44.55, 7.602 x 45.23, 7.753
    { 47, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0921} }, // 7 OSM: 2622564 WD: Q106767450 52.18, 20.94 x 52.26, 21.06
    { 372, 10312, 9874, LineMetaDataContent::Subway, Color{0xf9e300} }, // Yellow OSM: 2622574 WD: Q595450 42.02, -87.75 x 42.04, -87.67
    { 1524, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x20825c} }, // PAO OSM: 2629939 WD: Q7132125 39.95, -75.76 x 40.05, -75.15
    { 146, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf171ab} }, // 9 OSM: 2629996 WD: Q56302775 46.93, 7.436 x 46.97, 7.468
    { 68, 10336, 10358, LineMetaDataContent::Subway, Color{0xa066aa} }, // 3 OSM: 2635252 WD: Q15731044 59.85, 10.5 x 59.94, 10.85
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffff00} }, // 6 OSM: 2635960 55.67, 52.28 x 55.77, 52.45
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009746} }, // 8 OSM: 2635970 55.67, 52.28 x 55.77, 52.45
    { 16, 10379, 10358, LineMetaDataContent::Subway, Color{0xf26522} }, // 2 OSM: 2636245 WD: Q15731043 59.91, 10.61 x 59.95, 10.92
    { 6, 10401, 10358, LineMetaDataContent::Subway, Color{0x50b848} }, // 5 OSM: 2640907 WD: Q15731051 59.91, 10.71 x 59.97, 10.93
    { 47, NoLogo, 6890, LineMetaDataContent::Tramway, Color{0xce1417} }, // 7 OSM: 2641075 WD: Q123168036 59.88, 30.39 x 59.93, 30.5
    { 1528, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // Meadowlands OSM: 2641818 WD: Q6803384 40.73, -74.1 x 40.83, -74.03
    { 1540, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa0218c} }, // Pascack Valley OSM: 2641819 WD: Q11328810 40.73, -74.1 x 41.11, -74.01
    { 1555, 10423, 976, LineMetaDataContent::Tramway, Color{0x8874c7} }, // U46 OSM: 2642232 WD: Q107740407 51.5, 7.459 x 51.53, 7.471
    { 1396, 10437, 10457, LineMetaDataContent::Tramway, Color{0x873f98} }, // T5 OSM: 2643507 WD: Q3238967 45.73, 4.879 x 45.74, 4.948
    { 68, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xef7f1b} }, // 3 OSM: 2644926 55.72, 52.41 x 55.77, 52.5
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 5 OSM: 2646596 55.72, 52.41 x 55.76, 52.5
    { 47, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x393186} }, // 7 OSM: 2646626 55.69, 52.41 x 55.77, 52.53
    { 542, 10485, 3759, LineMetaDataContent::RapidTransit, Color{0x76777a} }, // C-8 OSM: 2647592 WD: Q8880127 40.38, -4.271 x 40.74, -3.181
    { 712, 10503, 10537, LineMetaDataContent::Tramway, Color{0x802990} }, // A OSM: 2648050 WD: Q2658981 44.83, -0.7015 x 44.89, -0.5081
    { 279, 10563, 10537, LineMetaDataContent::Tramway, Color{0xed164b} }, // B OSM: 2648235 WD: Q2420027 44.79, -0.6632 x 44.89, -0.5415
    { 146, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xdb1702} }, // 9 OSM: 2648370 WD: Q106766521 52.18, 20.94 x 52.25, 21.12
    { 22, NoLogo, 6890, LineMetaDataContent::Tramway, Color{0xce1417} }, // 18 OSM: 2651053 WD: Q123168041 59.99, 30.23 x 60.02, 30.25
    { 349, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 23 OSM: 2651263 59.9, 30.35 x 59.97, 30.5
    { 255, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 24 OSM: 2651264 59.83, 30.38 x 59.93, 30.51
    { 161, NoLogo, 6890, LineMetaDataContent::Tramway, Color{0xce1417} }, // 19 OSM: 2651265 WD: Q123168042 59.98, 30.19 x 59.99, 30.26
    { 1134, NoLogo, 6890, LineMetaDataContent::Tramway, Color{0xce1417} }, // А OSM: 2651266 WD: Q123168077 59.9, 30.44 x 59.92, 30.5
    { 235, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 27 OSM: 2651267 59.83, 30.44 x 59.92, 30.51
    { 739, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 47 OSM: 2652192 60, 30.23 x 60.02, 30.31
    { 306, NoLogo, 6890, LineMetaDataContent::Tramway, Color{0xce1417} }, // 65 OSM: 2652193 WD: Q123168074 59.91, 30.39 x 59.93, 30.5
    { 536, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 57 OSM: 2652194 60, 30.37 x 60.02, 30.44
    { 262, NoLogo, 6890, LineMetaDataContent::Tramway, Color{0xce1417} }, // 38 OSM: 2652196 WD: Q123168052 59.98, 30.35 x 60.05, 30.44
    { 105, NoLogo, 6890, LineMetaDataContent::Tramway, Color{0xce1417} }, // 62 OSM: 2652197 WD: Q123168071 59.83, 30.38 x 59.84, 30.42
    { 182, NoLogo, 6890, LineMetaDataContent::Tramway, Color{0xce1417} }, // 60 OSM: 2652198 WD: Q123168069 59.85, 30.12 x 59.88, 30.26
    { 94, NoLogo, 6890, LineMetaDataContent::Tramway, Color{0xce1417} }, // 61 OSM: 2652199 WD: Q123168070 59.97, 30.34 x 60.05, 30.41
    { 1559, 8099, 8099, LineMetaDataContent::Subway, Color{0xff0000} }, // Metropolitana OSM: 2653212 WD: Q1163754 44.4, 8.881 x 44.44, 8.983
    { 27, 10597, NoLogo, LineMetaDataContent::Subway, Color{0x2c8195} }, // 6 OSM: 2653338 WD: Q6553143 25.03, 102.7 x 25.1, 102.9
    { 411, 10617, 10537, LineMetaDataContent::Tramway, Color{0xcf56a0} }, // C OSM: 2654042 WD: Q2331392 44.77, -0.6237 x 44.92, -0.5499
    { 330, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc4121a} }, // 25 OSM: 2654656 WD: Q47563867 48.22, 16.4 x 48.26, 16.48
    { 1573, 10651, 9874, LineMetaDataContent::Subway, Color{0xe27ea6} }, // Pink OSM: 2656070 WD: Q3112661 41.85, -87.76 x 41.89, -87.63
    { 367, 10673, 9874, LineMetaDataContent::Subway, Color{0x00a1de} }, // Blue OSM: 2672370 WD: Q2534873 41.87, -87.9 x 41.98, -87.63
    { 1578, 10695, 976, LineMetaDataContent::Tramway, Color{0xa3d20b} }, // U47 OSM: 2673747 WD: Q121287774 51.49, 7.382 x 51.55, 7.556
    { 146, 10709, 4547, LineMetaDataContent::Subway, Color{0x87d300} }, // 9 OSM: 2674584 WD: Q5929508 39.81, 116.3 x 39.94, 116.3
    { 1582, 10729, 976, LineMetaDataContent::Tramway, Color{0xfcdc00} }, // U41 OSM: 2674820 WD: Q121288228 51.48, 7.44 x 51.59, 7.502
    { 1586, 10743, 976, LineMetaDataContent::Tramway, Color{0x00a991} }, // U43 OSM: 2675103 WD: Q121287834 51.51, 7.419 x 51.53, 7.625
    { 47, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x9e0234} }, // 7 OSM: 2675693 WD: Q91660996 51.04, 13.63 x 51.14, 13.8
    { 1594, 10757, 9874, LineMetaDataContent::Subway, Color{0x522398} }, // Purple OSM: 2675822 WD: Q3112074 41.88, -87.69 x 42.07, -87.63
    { 71, 10781, 10793, LineMetaDataContent::RapidTransit, Color{0x159dd9} }, // S1 OSM: 2679058 WD: Q17101540 48.17, 16.33 x 48.34, 16.92
    { 59, 10809, 10793, LineMetaDataContent::RapidTransit, Color{0x159dd9} }, // S2 OSM: 2679059 WD: Q96484152 48.08, 16.28 x 48.72, 16.57
    { 225, 10821, 10793, LineMetaDataContent::RapidTransit, Color{0x159dd9} }, // S3 OSM: 2679060 WD: Q96484012 47.81, 16.06 x 48.56, 16.41
    { 59, 10833, 226, LineMetaDataContent::RapidTransit, Color{0x118349} }, // S2 OSM: 2682237 WD: Q63433449 52.28, 9.217 x 52.65, 9.773
    { 1601, 10849, 4547, LineMetaDataContent::Subway, Color{0x007e84} }, // 4S OSM: 2684711 WD: Q5242742 39.67, 116.3 x 39.81, 116.4
    { 157, 10874, 4547, LineMetaDataContent::Subway, Color{0x6a1d44} }, // 15 OSM: 2688949 WD: Q734917 39.99, 116.3 x 40.13, 116.7
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x006b42} }, // 12 OSM: 2690192 WD: Q93767629 51.04, 13.67 x 51.06, 13.81
    { 318, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00aaad} }, // 26 OSM: 2705952 WD: Q119905487 59.27, 18.27 x 59.29, 18.3
    { 330, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00aaad} }, // 25 OSM: 2705957 WD: Q119905177 59.28, 18.11 x 59.31, 18.31
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff7f50} }, // 2 OSM: 2710819 WD: Q106767016 52.29, 20.93 x 52.34, 20.97
    { 1604, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x003e7e} }, // TRE OSM: 2716975 WD: Q2453601 32.75, -97.33 x 32.82, -96.81
    { 75, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x179ed8} }, // 10 OSM: 2728288 WD: Q16655703 50.06, 14.3 x 50.13, 14.48
    { 63, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8c683c} }, // 11 OSM: 2728371 WD: Q16655705 50.05, 14.43 x 50.09, 14.5
    { 1608, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0xeb3c2e} }, // S18 OSM: 2729450 WD: Q686782 47.29, 8.547 x 47.37, 8.71
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x4c2d5f} }, // 12 OSM: 2729904 WD: Q16655709 50.03, 14.37 x 50.11, 14.45
    { 64, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // 1 OSM: 2746761 WD: Q12406939 31.77, 35.18 x 31.83, 35.24
    { 11, 10895, 8099, LineMetaDataContent::Subway, Color{0xb395d0} }, // M5 OSM: 2753306 WD: Q3238963 45.48, 9.117 x 45.53, 9.212
    { 27, 10915, NoLogo, LineMetaDataContent::Subway, Color{0xf67599} }, // 6 OSM: 2768662 WD: Q5931449 29.49, 106.4 x 29.85, 106.7
    { 64, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffff00} }, // 1 OSM: 2773495 WD: Q1484153 47.52, 21.62 x 47.56, 21.63
    { 64, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe3000b} }, // 1 OSM: 2777016 WD: Q121253956 52.2, 10.51 x 52.33, 10.54
    { 1612, 10940, NoLogo, LineMetaDataContent::Tramway, Color{0x7b2f3d} }, // M-Line OSM: 2788830 WD: Q124774997 32.78, -96.8 x 32.81, -96.79
    { 1619, 10964, 226, LineMetaDataContent::RapidTransit, Color{0xd7171f} }, // S 3 OSM: 2793231 WD: Q62749908 51.31, 11.91 x 51.49, 13.11
    { 68, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x687362} }, // 3 OSM: 2797182 52.5, 103.8 x 52.58, 103.9
    { 1623, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x149943} }, // STY OSM: 2797718 WD: Q7619599 -38.37, 145.1 x -38.14, 145.2
    { 1559, 10989, 10989, LineMetaDataContent::Subway, Color{0xed1c24} }, // Metropolitana OSM: 2797904 WD: Q1725884 45.51, 10.21 x 45.58, 10.28
    { 75, 11006, NoLogo, LineMetaDataContent::Tramway, Color{0xce1f75} }, // 10 OSM: 2799185 WD: Q70711877 47.38, 8.536 x 47.45, 8.573
    { 15, 11031, NoLogo, LineMetaDataContent::Tramway, Color{0x92d6e3} }, // 12 OSM: 2799201 WD: Q70711314 47.4, 8.556 x 47.45, 8.608
    { 64, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x4c677a} }, // 1 OSM: 2801578 52.52, 103.9 x 52.56, 103.9
    { 47, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe5e6ea} }, // 7 OSM: 2802264 52.5, 103.8 x 52.53, 103.9
    { 68, NoLogo, 6890, LineMetaDataContent::Tramway, Color{0xce1417} }, // 3 OSM: 2804939 WD: Q123168034 59.92, 30.28 x 59.97, 30.36
    { 735, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 56 OSM: 2804944 59.86, 30.23 x 59.88, 30.26
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x70492c} }, // 5 OSM: 2807017 WD: Q96483196 47.36, 8.516 x 47.38, 8.572
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xbe8543} }, // 6 OSM: 2807025 WD: Q96483372 47.36, 8.531 x 47.38, 8.572
    { 47, 11056, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 7 OSM: 2807030 WD: Q70712535 47.34, 8.53 x 47.41, 8.597
    { 146, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x322e71} }, // 9 OSM: 2807033 WD: Q70710278 47.37, 8.495 x 47.41, 8.592
    { 153, 11080, NoLogo, LineMetaDataContent::Tramway, Color{0x0093d0} }, // 14 OSM: 2807051 WD: Q70714895 47.37, 8.495 x 47.42, 8.55
    { 63, 11105, NoLogo, LineMetaDataContent::Tramway, Color{0x00923c} }, // 11 OSM: 2807068 WD: Q70714560 47.35, 8.533 x 47.42, 8.583
    { 68, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00923c} }, // 3 OSM: 2807070 WD: Q96483170 47.36, 8.485 x 47.38, 8.567
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x322e71} }, // 4 OSM: 2807089 WD: Q96483185 47.35, 8.49 x 47.39, 8.561
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xcb0a25} }, // 2 OSM: 2807095 WD: Q73249054 47.35, 8.444 x 47.4, 8.561
    { 157, 11130, NoLogo, LineMetaDataContent::Tramway, Color{0xcb0a25} }, // 15 OSM: 2807117 WD: Q70707977 47.37, 8.533 x 47.4, 8.548
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8bc036} }, // 8 OSM: 2807118 WD: Q96483377 47.36, 8.504 x 47.39, 8.567
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf39100} }, // 5 OSM: 2810470 WD: Q121253961 52.23, 10.48 x 52.26, 10.54
    { 26, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x13519c} }, // 16 OSM: 2820891 WD: Q16655718 50.06, 14.3 x 50.08, 14.53
    { 64, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0b0080} }, // 1 OSM: 2826218 WD: Q5017774 29.85, 31.23 x 30.16, 31.34
    { 9, 11155, 10358, LineMetaDataContent::Subway, Color{0x0054a6} }, // 4 OSM: 2827680 WD: Q15731046 59.87, 10.71 x 59.97, 10.93
    { 372, NoLogo, 11172, LineMetaDataContent::Subway, Color{0xffe800} }, // Yellow OSM: 2827687 WD: Q54874971 37.6, -122.5 x 38.02, -121.9
    { 274, 3932, 3961, LineMetaDataContent::RapidTransit, Color{0xf166a7} }, // 40 OSM: 2836163 WD: Q106806725 59.17, 17.63 x 59.86, 18.07
    { 68, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x006531} }, // 3 OSM: 2837394 WD: Q121253959 52.24, 10.47 x 52.29, 10.58
    { 64, 11186, NoLogo, LineMetaDataContent::Subway, Color{0xe60039} }, // 1 OSM: 2843401 WD: Q6850056 28.68, 115.8 x 28.75, 116
    { 811, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xbed639} }, // 82 OSM: 2844184 WD: Q6811974 -37.8, 144.9 x -37.77, 144.9
    { 1627, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x923cb0} }, // T6 OSM: 2850494 WD: Q108046114 50.23, 18.89 x 50.35, 19.02
    { 379, 11212, 11172, LineMetaDataContent::Subway, Color{0xed1c24} }, // Red OSM: 2851513 WD: Q3809179 37.6, -122.5 x 37.94, -122.3
    { 1446, 11229, 11172, LineMetaDataContent::Subway, Color{0xfaa61a} }, // Orange OSM: 2851514 WD: Q3866809 37.37, -122.4 x 37.94, -121.9
    { 653, 11245, 11172, LineMetaDataContent::Subway, Color{0x4db848} }, // Green OSM: 2851729 WD: Q3720557 37.37, -122.5 x 37.81, -121.9
    { 367, 11263, 11172, LineMetaDataContent::Subway, Color{0x00aeef} }, // Blue OSM: 2851730 WD: Q3720569 37.69, -122.5 x 37.81, -121.9
    { 1630, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf3ca00} }, // T14 OSM: 2856767 WD: Q108046257 50.23, 18.99 x 50.27, 19.11
    { 63, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x86c5a2} }, // 11 OSM: 2858845 WD: Q18165625 -37.82, 144.9 x -37.73, 145
    { 47, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x878a83} }, // 7 OSM: 2860817 WD: Q1138075 59.32, 18.06 x 59.33, 18.11
    { 1634, 11278, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00907a} }, // S31 OSM: 2872363 WD: Q106450415 48.99, 8.399 x 49.18, 8.747
    { 1058, 11295, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00907a} }, // S32 OSM: 2872364 WD: Q106362984 48.99, 8.399 x 49.16, 8.775
    { 355, 11312, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf49694} }, // S51 OSM: 2872365 WD: Q126120770 48.89, 8.262 x 49.23, 8.705
    { 173, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf49694} }, // S52 OSM: 2872366 48.98, 8.262 x 49.23, 8.404
    { 130, 11329, 1489, LineMetaDataContent::Subway, Color{0x2ec6ff} }, // U4 OSM: 2872790 WD: Q209739 53.53, 9.983 x 53.56, 10.04
    { 63, 11344, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff7f50} }, // 11 OSM: 2875658 WD: Q5245830 -23.56, -46.64 x -23.52, -46.19
    { 15, 11356, NoLogo, LineMetaDataContent::RapidTransit, Color{0x1c146b} }, // 12 OSM: 2877633 WD: Q5245789 -23.55, -46.62 x -23.48, -46.33
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8c6e66} }, // 6 OSM: 2877971 52.5, 103.8 x 52.56, 103.9
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xec7394} }, // 4 OSM: 2877979 52.5, 103.8 x 52.53, 103.9
    { 47, 11368, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa8034f} }, // 7 OSM: 2885794 WD: Q3296728 -23.55, -46.87 x -23.19, -46.62
    { 64, 11379, 10358, LineMetaDataContent::Subway, Color{0x00b6f1} }, // 1 OSM: 2890637 WD: Q15731038 59.87, 10.65 x 59.98, 10.82
    { 75, 11396, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00ced1} }, // 10 OSM: 2893113 WD: Q5245819 -23.74, -46.62 x -23.54, -46.39
    { 279, 11408, 5702, LineMetaDataContent::Subway, Color{0xffa500} }, // B OSM: 2896644 WD: Q18420098 6.247, -75.61 x 6.259, -75.57
    { 1640, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x37bbed} }, // TU OSM: 2897278 WD: Q16438501 -34.95, -57.95 x -34.9, -57.92
    { 1643, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x546684} }, // DPM OSM: 2914673 WD: Q1201543 42.32, -83.05 x 42.34, -83.04
    { 321, 11447, 226, LineMetaDataContent::RapidTransit, Color{0xffff00} }, // S 1 OSM: 2920398 WD: Q56600177 51.31, 12.27 x 51.37, 12.41
    { 161, 11472, NoLogo, LineMetaDataContent::Tramway, Color{0xf7942a} }, // 19 OSM: 2921482 WD: Q109462009 59.85, 10.72 x 59.93, 10.8
    { 22, 11496, NoLogo, LineMetaDataContent::Tramway, Color{0xfdb927} }, // 18 OSM: 2921905 WD: Q56850451 59.91, 10.71 x 59.95, 10.78
    { 9, NoLogo, 11516, LineMetaDataContent::Tramway, Color{0xff0000} }, // 4 OSM: 2930171 WD: Q121323126 51.15, 11.8 x 51.16, 11.81
    { 411, 11548, 3074, LineMetaDataContent::Subway, Color{0x003ea1} }, // C OSM: 2931139 WD: Q1157050 -34.63, -58.38 x -34.59, -58.37
    { 279, 11576, 3074, LineMetaDataContent::Subway, Color{0xc20924} }, // B OSM: 2933167 WD: Q1157061 -34.6, -58.49 x -34.57, -58.37
    { 548, 11604, 3074, LineMetaDataContent::Subway, Color{0x6b297e} }, // E OSM: 2933872 WD: Q1044919 -34.64, -58.46 x -34.59, -58.37
    { 283, 11632, 3074, LineMetaDataContent::Subway, Color{0x217861} }, // D OSM: 2934099 WD: Q1157052 -34.61, -58.46 x -34.56, -58.37
    { 34, 11660, 3074, LineMetaDataContent::Subway, Color{0xf4cc21} }, // H OSM: 2934107 WD: Q1132660 -34.64, -58.41 x -34.58, -58.39
    { 441, 11688, 9935, LineMetaDataContent::Subway, Color{0x4b5799} }, // M2 OSM: 2947130 WD: Q1884455 44.35, 26.09 x 44.48, 26.16
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf9b000} }, // 4 OSM: 2951397 WD: Q63350784 52.37, 9.596 x 52.42, 9.819
    { 289, 11704, NoLogo, LineMetaDataContent::Tramway, Color{0x281570} }, // T1 OSM: 2962731 WD: Q6043955 41, 28.86 x 41.03, 28.99
    { 64, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x75c3b0} }, // 1 OSM: 2969493 WD: Q123363011 56.77, 60.51 x 56.83, 60.61
    { 1051, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x6f1b14} }, // 94 OSM: 2982672 WD: Q121335024 51.48, 11.93 x 51.51, 11.97
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf9b000} }, // 6 OSM: 2991603 WD: Q63350805 52.32, 9.69 x 52.42, 9.837
    { 63, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf9b000} }, // 11 OSM: 2991649 WD: Q63350814 52.37, 9.713 x 52.39, 9.775
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf9b000} }, // 5 OSM: 2991701 WD: Q63350794 52.36, 9.659 x 52.41, 9.859
    { 64, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe4003a} }, // 1 OSM: 2995652 WD: Q63344401 52.24, 9.731 x 52.44, 9.86
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe4003a} }, // 2 OSM: 2998555 WD: Q63345326 52.28, 9.734 x 52.42, 9.837
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe4003a} }, // 8 OSM: 2998722 WD: Q63345432 52.33, 9.734 x 52.39, 9.805
    { 239, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x76b82a} }, // 17 OSM: 2998733 WD: Q63348315 52.34, 9.718 x 52.38, 9.743
    { 75, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x76b82a} }, // 10 OSM: 3004809 WD: Q63348270 52.37, 9.664 x 52.39, 9.756
    { 1648, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x051541} }, // 95 OSM: 3006197 WD: Q121335025 51.42, 11.96 x 51.52, 11.99
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xed1943} }, // 12 OSM: 3009639 WD: Q2189640 51.88, 4.471 x 51.92, 4.568
    { 68, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0069b4} }, // 3 OSM: 3016071 WD: Q63348707 52.33, 9.69 x 52.44, 9.848
    { 47, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0069b4} }, // 7 OSM: 3038575 WD: Q63348805 52.33, 9.69 x 52.41, 9.854
    { 146, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0069b4} }, // 9 OSM: 3038600 WD: Q63349759 52.34, 9.667 x 52.38, 9.744
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008dd2} }, // 2 OSM: 3060916 WD: Q123363012 56.84, 60.56 x 56.9, 60.64
    { 64, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff7f27} }, // 1 OSM: 3061200 WD: Q121361537 50.49, 12.14 x 50.51, 12.18
    { 68, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00a2e8} }, // 3 OSM: 3061204 WD: Q121361539 50.49, 12.1 x 50.51, 12.14
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf5b2b6} }, // 4 OSM: 3066680 WD: Q123363014 56.8, 60.6 x 56.86, 60.67
    { 157, 11732, 9802, LineMetaDataContent::Subway, Color{0xa50034} }, // 15 OSM: 3094380 WD: Q3240151 48.78, 2.197 x 48.92, 2.583
    { 1651, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x236214} }, // UP-N OSM: 3117549 WD: Q7885883 41.88, -87.85 x 42.59, -87.64
    { 1656, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff821d} }, // MD-N OSM: 3117594 WD: Q16982046 41.88, -88.18 x 42.4, -87.64
    { 1661, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7c53af} }, // NCS OSM: 3117600 WD: Q7054760 41.88, -88.09 x 42.48, -87.64
    { 1665, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfae218} }, // UP-NW OSM: 3117607 WD: Q16985937 41.88, -88.62 x 42.42, -87.64
    { 1671, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfeb8fa} }, // UP-W OSM: 3117615 WD: Q7885886 41.86, -88.47 x 41.9, -87.64
    { 1676, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x77b337} }, // BNSF OSM: 3117619 WD: Q4836140 41.76, -88.31 x 41.88, -87.64
    { 1681, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xee4848} }, // HC OSM: 3117625 WD: Q5738778 41.52, -88.08 x 41.88, -87.64
    { 678, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa81818} }, // RI OSM: 3117651 WD: Q7354508 41.51, -88.08 x 41.88, -87.63
    { 1684, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x117bac} }, // SWS OSM: 3117664 WD: Q7565331 41.42, -87.99 x 41.88, -87.64
    { 1688, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf67b7b} }, // ME OSM: 3117670 WD: Q4501968 41.46, -87.72 x 41.89, -87.55
    { 1691, 11768, 226, LineMetaDataContent::RapidTransit, Color{0x00ffff} }, // S 2 OSM: 3119892 WD: Q56809294 51.31, 12.23 x 51.87, 12.66
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xafe0ee} }, // 8 OSM: 3144745 WD: Q56302773 46.94, 7.374 x 46.95, 7.487
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x088742} }, // 2 OSM: 3152801 WD: Q121311235 51.13, 14.94 x 51.17, 14.99
    { 64, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff2e17} }, // 1 OSM: 3152809 WD: Q121311074 51.12, 14.97 x 51.17, 14.99
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf7bc58} }, // 5 OSM: 3154103 WD: Q123363015 56.85, 60.59 x 56.89, 60.67
    { 1695, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // LBN OSM: 3155062 WD: Q46654325 -34.59, -58.87 x -34.42, -58.37
    { 359, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // FM1 OSM: 3158700 WD: Q130331714 41.12, 16.78 x 41.14, 16.87
    { 440, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0xffc100} }, // FM2 OSM: 3158701 WD: Q130331727 41.11, 16.68 x 41.14, 16.87
    { 46, 11793, 226, LineMetaDataContent::RapidTransit, Color{0xa5ce43} }, // S7 OSM: 3168072 WD: Q63433461 52.37, 9.739 x 52.62, 10.06
    { 64, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x26ac9f} }, // 1 OSM: 3171605 WD: Q120720199 50.06, 19.9 x 50.09, 20.06
    { 68, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009abd} }, // 3 OSM: 3171607 WD: Q120720201 50.01, 19.93 x 50.09, 20.02
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xd19563} }, // 4 OSM: 3171608 WD: Q120720202 50.06, 19.88 x 50.09, 20.06
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf08365} }, // 5 OSM: 3171635 WD: Q120720203 50.07, 19.93 x 50.09, 20.06
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x15834a} }, // 6 OSM: 3171642 WD: Q120720204 50.03, 19.9 x 50.06, 20
    { 75, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf3c13d} }, // 10 OSM: 3171684 WD: Q120720207 50.01, 19.93 x 50.07, 20.12
    { 67, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xd73c31} }, // 13 OSM: 3171685 WD: Q120720210 50.01, 19.9 x 50.08, 20.02
    { 153, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe5097f} }, // 14 OSM: 3171686 WD: Q120720211 50.06, 19.9 x 50.1, 20.04
    { 26, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x3dab46} }, // 16 OSM: 3171687 WD: Q120720212 50.07, 20 x 50.1, 20.07
    { 22, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x962983} }, // 18 OSM: 3171688 WD: Q120720215 50.02, 19.89 x 50.11, 19.96
    { 146, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xa2d9f7} }, // 9 OSM: 3171689 WD: Q120720206 50.01, 19.96 x 50.1, 20.04
    { 251, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x3dab46} }, // 20 OSM: 3171692 WD: Q120720217 50.04, 19.9 x 50.07, 20
    { 82, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x86755d} }, // 21 OSM: 3171693 WD: Q120720218 50.06, 20.01 x 50.1, 20.12
    { 118, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0094d6} }, // 22 OSM: 3171694 WD: Q120720220 50.01, 19.92 x 50.09, 20.07
    { 239, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xb96638} }, // 17 OSM: 3171695 WD: Q120720213 50.02, 19.89 x 50.08, 19.96
    { 255, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xb2ad81} }, // 24 OSM: 3171696 WD: Q120720221 50.01, 19.88 x 50.08, 19.98
    { 243, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf39430} }, // 50 OSM: 3171697 WD: Q120720225 50.01, 19.93 x 50.11, 19.98
    { 157, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 15 OSM: 3184018 55.8, 37.39 x 55.81, 37.51
    { 349, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 23 OSM: 3184019 55.81, 37.49 x 55.84, 37.53
    { 400, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 30 OSM: 3184021 55.8, 37.39 x 55.84, 37.53
    { 1125, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 28 OSM: 3184024 55.78, 37.45 x 55.81, 37.51
    { 75, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 10 OSM: 3184063 WD: Q122585351 55.8, 37.39 x 55.81, 37.46
    { 82, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 21 OSM: 3184064 55.8, 37.39 x 55.81, 37.46
    { 235, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 27 OSM: 3184107 55.81, 37.5 x 55.84, 37.58
    { 330, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 25 OSM: 3186266 WD: Q122585359 55.79, 37.62 x 55.83, 37.69
    { 712, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xca305b} }, // A OSM: 3190626 WD: Q3537211 47.34, 0.6578 x 47.42, 0.7119
    { 67, 11809, NoLogo, LineMetaDataContent::Tramway, Color{0x00b26b} }, // 13 OSM: 3201250 WD: Q109462007 59.85, 10.59 x 59.93, 10.8
    { 63, 11833, NoLogo, LineMetaDataContent::Tramway, Color{0x82c341} }, // 11 OSM: 3218724 WD: Q109462005 59.91, 10.72 x 59.96, 10.79
    { 15, 11857, NoLogo, LineMetaDataContent::Tramway, Color{0xa166aa} }, // 12 OSM: 3221100 WD: Q109462006 59.91, 10.7 x 59.96, 10.79
    { 1699, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf2665b} }, // T20 OSM: 3221748 WD: Q108046457 50.26, 18.94 x 50.3, 19.07
    { 9, 11881, 11926, LineMetaDataContent::Subway, Color{0xf1ce00} }, // 4 OSM: 3228501 WD: Q1597847 45.51, -73.56 x 45.52, -73.52
    { 16, 11969, 11926, LineMetaDataContent::Subway, Color{0xd06d07} }, // 2 OSM: 3228502 WD: Q967397 45.47, -73.73 x 45.56, -73.55
    { 6, 12014, 11926, LineMetaDataContent::Subway, Color{0x3465b4} }, // 5 OSM: 3228503 WD: Q1726049 45.49, -73.63 x 45.56, -73.6
    { 64, 12059, 11926, LineMetaDataContent::Subway, Color{0x069037} }, // 1 OSM: 3228504 WD: Q1925762 45.45, -73.6 x 45.6, -73.53
    { 16, 12104, NoLogo, LineMetaDataContent::Subway, Color{0x00629b} }, // 2 OSM: 3244073 WD: Q1047377 22.99, 113.3 x 23.24, 113.3
    { 124, 12124, 948, LineMetaDataContent::Subway, Color{0xa762a4} }, // U2 OSM: 3245522 WD: Q873397 48.21, 16.36 x 48.23, 16.51
    { 1703, 12136, NoLogo, LineMetaDataContent::Tramway, Color{0x802168} }, // C4 OSM: 3252393 WD: Q107432442 37.6, -0.9773 x 37.65, -0.7876
    { 68, 12155, NoLogo, LineMetaDataContent::Subway, Color{0xd9001c} }, // 3 OSM: 3252762 WD: Q3294315 -23.55, -46.67 x -23.53, -46.47
    { 68, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff091d} }, // 3 OSM: 3257819 WD: Q124657531 55.73, 49.1 x 55.79, 49.15
    { 64, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x01959a} }, // 1 OSM: 3257821 WD: Q110315656 55.77, 49.07 x 55.86, 49.11
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x2a6f39} }, // 4 OSM: 3257827 WD: Q110365894 55.74, 49.17 x 55.82, 49.24
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffd028} }, // 5 OSM: 3257853 WD: Q124657533 55.73, 49.07 x 55.83, 49.22
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff026b} }, // 6 OSM: 3257865 WD: Q124657536 55.82, 49.08 x 55.86, 49.18
    { 68, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 3 OSM: 3258552 47.2, 38.9 x 47.23, 38.94
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 4 OSM: 3258575 47.2, 38.88 x 47.26, 38.92
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 5 OSM: 3258583 47.2, 38.89 x 47.24, 38.94
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 6 OSM: 3258591 47.2, 38.88 x 47.24, 38.91
    { 47, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 7 OSM: 3258600 47.22, 38.89 x 47.26, 38.92
    { 239, 12169, NoLogo, LineMetaDataContent::Tramway, Color{0xef4123} }, // 17 OSM: 3259480 WD: Q109462008 59.91, 10.71 x 59.95, 10.78
    { 64, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 1 OSM: 3272067 47.2, 38.88 x 47.23, 38.92
    { 121, 12193, 948, LineMetaDataContent::Subway, Color{0xe20613} }, // U1 OSM: 3278144 WD: Q663755 48.14, 16.37 x 48.28, 16.45
    { 1706, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x202f7b} }, // T16 OSM: 3281921 WD: Q108046378 50.23, 18.99 x 50.29, 19.03
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 2 OSM: 3285146 47.2, 38.92 x 47.26, 38.94
    { 225, 12205, 226, LineMetaDataContent::RapidTransit, Color{0xf5821f} }, // S3 OSM: 3298634 WD: Q116212120 46.54, 14.24 x 46.84, 14.86
    { 47, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 7 OSM: 3299881 WD: Q122585349 55.77, 37.58 x 55.82, 37.73
    { 75, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x9e2a96} }, // 10 OSM: 3303135 WD: Q121317828 49.47, 8.412 x 49.5, 8.453
    { 712, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe40428} }, // A OSM: 3309751 WD: Q3239051 47.44, -0.5963 x 47.51, -0.5454
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009846} }, // 6 OSM: 3314564 WD: Q123363016 56.82, 60.55 x 56.89, 60.64
    { 26, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xaf1867} }, // 16 OSM: 3315633 WD: Q121335023 51.43, 11.9 x 51.48, 11.99
    { 9, 12221, 9802, LineMetaDataContent::Subway, Color{0xa0006e} }, // 4 OSM: 3326845 WD: Q50743 48.8, 2.316 x 48.9, 2.359
    { 153, 12256, 9802, LineMetaDataContent::Subway, Color{0x640082} }, // 14 OSM: 3328694 WD: Q50761 48.73, 2.31 x 48.92, 2.387
    { 64, 12292, 9802, LineMetaDataContent::Subway, Color{0xffbe00} }, // 1 OSM: 3328695 WD: Q13224 48.84, 2.23 x 48.89, 2.441
    { 146, 12327, 9802, LineMetaDataContent::Subway, Color{0xd2d200} }, // 9 OSM: 3328717 WD: Q50753 48.83, 2.231 x 48.87, 2.442
    { 130, 12362, 12378, LineMetaDataContent::Subway, Color{0x00a082} }, // U4 OSM: 3328726 WD: Q20439761 48.13, 11.52 x 48.15, 11.62
    { 75, 12402, 9802, LineMetaDataContent::Subway, Color{0xdc9600} }, // 10 OSM: 3328741 WD: Q50754 48.84, 2.228 x 48.85, 2.365
    { 27, 12438, 9802, LineMetaDataContent::Subway, Color{0x82dc73} }, // 6 OSM: 3328765 WD: Q50746 48.83, 2.285 x 48.87, 2.402
    { 47, 12473, 9802, LineMetaDataContent::Subway, Color{0xff82b4} }, // 7 OSM: 3328805 WD: Q50748 48.79, 2.332 x 48.92, 2.411
    { 47, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x18b2ae} }, // 7 OSM: 3331526 WD: Q123363017 56.84, 60.5 x 56.9, 60.64
    { 1710, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe40521} }, // KT OSM: 3348003 WD: Q1510414 51.08, 2.581 x 51.34, 3.285
    { 1713, 12508, NoLogo, LineMetaDataContent::LocalTrain, Color{0xeb7405} }, // RB55 OSM: 3366300 WD: Q63224617 52.64, 13.04 x 52.75, 13.21
    { 1718, 12528, NoLogo, LineMetaDataContent::LocalTrain, Color{0x007734} }, // RB20 OSM: 3366342 WD: Q68007873 52.39, 12.97 x 52.75, 13.29
    { 64, 12548, NoLogo, LineMetaDataContent::Tramway, Color{0xe3000f} }, // 1 OSM: 3367545 WD: Q78199222 48.34, 10.87 x 48.38, 10.94
    { 9, 12568, NoLogo, LineMetaDataContent::Tramway, Color{0x941680} }, // 4 OSM: 3367554 WD: Q121146092 48.37, 10.88 x 48.4, 10.89
    { 1723, 12588, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0097ba} }, // S42 OSM: 3368507 WD: Q121237874 49.14, 8.875 x 49.25, 9.229
    { 58, 12605, 226, LineMetaDataContent::RapidTransit, Color{0xff9e00} }, // RS2 OSM: 3372285 WD: Q84703704 52.79, 8.597 x 53.57, 8.895
    { 70, 12620, 226, LineMetaDataContent::RapidTransit, Color{0x0000ee} }, // RS1 OSM: 3372313 WD: Q84703702 52.92, 8.516 x 53.21, 9.238
    { 1273, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 31 OSM: 3375725 55.78, 37.45 x 55.82, 37.5
    { 292, 12635, NoLogo, LineMetaDataContent::LocalTrain, Color{0xffffff} }, // RB 58 OSM: 3379684 WD: Q108409640 47.85, 11.53 x 48.14, 12.12
    { 314, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0xec008c} }, // S4 OSM: 3379960 WD: Q106453719 47.04, 8.814 x 47.48, 9.651
    { 1727, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0xfdd456} }, // S 5X OSM: 3382470 WD: Q63216058 50.7, 11.99 x 51.48, 12.48
    { 178, 12652, 8524, LineMetaDataContent::Tramway, Color{0xf3c300} }, // 44 OSM: 3394367 WD: Q1931983 50.82, 4.409 x 50.84, 4.514
    { 660, 12674, 8524, LineMetaDataContent::Tramway, Color{0xe43c2e} }, // 39 OSM: 3394368 WD: Q2719066 50.83, 4.409 x 50.85, 4.504
    { 347, 12696, NoLogo, LineMetaDataContent::LocalTrain, Color{0xeb7405} }, // RB23 OSM: 3399395 WD: Q108546612 52.36, 12.97 x 52.53, 13.6
    { 75, 12715, 12736, LineMetaDataContent::Subway, Color{0xeac384} }, // 10 OSM: 3400216 WD: Q6553053 31.98, 118.6 x 32.07, 118.8
    { 64, 12759, 12736, LineMetaDataContent::Subway, Color{0x00a2df} }, // 1 OSM: 3400217 WD: Q6127241 31.9, 118.8 x 32.15, 118.9
    { 1732, 12779, NoLogo, LineMetaDataContent::LocalTrain, Color{0xff5900} }, // RB13 OSM: 3407777 WD: Q63434598 52.53, 12.94 x 52.55, 13.31
    { 16, 12799, 12736, LineMetaDataContent::Subway, Color{0xc7003f} }, // 2 OSM: 3413089 WD: Q5960302 31.96, 118.7 x 32.12, 119
    { 1737, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // MTM OSM: 3413332 WD: Q1337838 -32.96, -68.85 x -32.84, -68.78
    { 71, 12819, 226, LineMetaDataContent::RapidTransit, Color{0x0095da} }, // S1 OSM: 3413905 WD: Q600891 49.97, 8.244 x 50.11, 8.885
    { 59, 12836, 226, LineMetaDataContent::RapidTransit, Color{0xee1c23} }, // S2 OSM: 3414422 WD: Q1985592 50.01, 8.31 x 50.16, 8.813
    { 55, 12853, 226, LineMetaDataContent::RapidTransit, Color{0xd7df23} }, // S8 OSM: 3415070 WD: Q2005458 49.98, 8.242 x 50.13, 8.931
    { 645, 12870, 226, LineMetaDataContent::RapidTransit, Color{0x91268f} }, // S9 OSM: 3415113 WD: Q508402 49.98, 8.244 x 50.13, 8.931
    { 1741, 12887, 3759, LineMetaDataContent::RapidTransit, Color{0xfab700} }, // C-5 OSM: 3418151 WD: Q3832677 40.25, -3.883 x 40.41, -3.677
    { 15, 12905, NoLogo, LineMetaDataContent::Tramway, Color{0xe40521} }, // 12 OSM: 3419132 WD: Q2200976 51.22, 4.42 x 51.23, 4.44
    { 146, 12928, NoLogo, LineMetaDataContent::Tramway, Color{0xef7d00} }, // 9 OSM: 3419133 WD: Q1891687 51.2, 4.35 x 51.22, 4.484
    { 255, 12950, NoLogo, LineMetaDataContent::Tramway, Color{0x69c0ac} }, // 24 OSM: 3419134 WD: Q2483765 51.2, 4.408 x 51.24, 4.484
    { 68, 12973, NoLogo, LineMetaDataContent::Tramway, Color{0xffcc00} }, // 3 OSM: 3419435 WD: Q3238908 51.22, 4.305 x 51.26, 4.464
    { 9, 12995, NoLogo, LineMetaDataContent::Tramway, Color{0x00a6e2} }, // 4 OSM: 3419473 WD: Q2344285 51.18, 4.372 x 51.22, 4.435
    { 6, 13017, NoLogo, LineMetaDataContent::Tramway, Color{0x822a3a} }, // 5 OSM: 3419525 WD: Q2147524 51.22, 4.345 x 51.23, 4.512
    { 27, 13039, NoLogo, LineMetaDataContent::Tramway, Color{0xe6007e} }, // 6 OSM: 3419912 WD: Q2128494 51.18, 4.391 x 51.26, 4.443
    { 47, 13061, NoLogo, LineMetaDataContent::Tramway, Color{0x0056a4} }, // 7 OSM: 3420306 WD: Q2413292 51.17, 4.4 x 51.23, 4.451
    { 75, 13083, NoLogo, LineMetaDataContent::Tramway, Color{0xc8d300} }, // 10 OSM: 3420544 WD: Q2318513 51.17, 4.362 x 51.23, 4.512
    { 157, 13106, NoLogo, LineMetaDataContent::Tramway, Color{0xffffff} }, // 15 OSM: 3420997 WD: Q959739 51.17, 4.362 x 51.22, 4.494
    { 64, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf5d200} }, // 1 OSM: 3430333 WD: Q122382395 49.72, 13.37 x 49.78, 13.4
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf5d200} }, // 2 OSM: 3430559 WD: Q122382396 49.73, 13.32 x 49.75, 13.41
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf5d200} }, // 4 OSM: 3430578 WD: Q122382397 49.73, 13.36 x 49.78, 13.38
    { 1644, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x913108} }, // PM OSM: 3433159 WD: Q113367771 37.78, -122.4 x 37.81, -122.4
    { 1746, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x913108} }, // PH OSM: 3433160 WD: Q121410548 37.78, -122.4 x 37.81, -122.4
    { 586, 13129, NoLogo, LineMetaDataContent::RapidTransit, Color{0x549dbf} }, // K OSM: 3433320 WD: Q6342899 37.72, -122.5 x 37.79, -122.4
    { 590, 13150, NoLogo, LineMetaDataContent::RapidTransit, Color{0x932290} }, // L OSM: 3435879 WD: Q16981005 37.74, -122.5 x 37.79, -122.4
    { 418, 13169, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008851} }, // M OSM: 3435882 WD: Q6720518 37.71, -122.5 x 37.79, -122.4
    { 705, 13191, NoLogo, LineMetaDataContent::RapidTransit, Color{0x004988} }, // N OSM: 3435884 WD: Q6956302 37.76, -122.5 x 37.79, -122.4
    { 161, 13208, 8524, LineMetaDataContent::Tramway, Color{0xe43c2e} }, // 19 OSM: 3437796 WD: Q2702907 50.86, 4.324 x 50.9, 4.357
    { 1749, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x37bbed} }, // LBS OSM: 3443504 WD: Q67311453 -34.85, -59.05 x -34.65, -58.42
    { 133, 13230, 12378, LineMetaDataContent::Subway, Color{0xa06e1e} }, // U5 OSM: 3475206 WD: Q3832790 48.09, 11.5 x 48.14, 11.65
    { 136, 13246, 12378, LineMetaDataContent::Subway, Color{0x005a96} }, // U6 OSM: 3477966 WD: Q751039 48.11, 11.47 x 48.27, 11.67
    { 127, 13262, 12378, LineMetaDataContent::Subway, Color{0xe66432} }, // U3 OSM: 3484056 WD: Q20439760 48.09, 11.48 x 48.19, 11.59
    { 168, 13278, NoLogo, LineMetaDataContent::LocalTrain, Color{0x992746} }, // RB49 OSM: 3490614 WD: Q84436359 51.44, 13.25 x 51.75, 14.32
    { 1753, 13298, NoLogo, LineMetaDataContent::Tramway, Color{0xf38b00} }, // T Line OSM: 3494094 WD: Q1999971 47.24, -122.5 x 47.27, -122.4
    { 524, 13330, NoLogo, LineMetaDataContent::Subway, Color{0x000000} }, // L2 OSM: 3517295 WD: Q3011583 43.24, -3.042 x 43.33, -2.881
    { 136, 13353, 1489, LineMetaDataContent::Subway, Color{0x007ec6} }, // U6 OSM: 3524791 WD: Q19863008 50.11, 8.624 x 50.14, 8.708
    { 298, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x66c18c} }, // S6 OSM: 3529247 WD: Q108602196 46.92, 8.814 x 47.23, 9.084
    { 121, 13370, 12378, LineMetaDataContent::Subway, Color{0x46b450} }, // U1 OSM: 3531712 WD: Q20439756 48.1, 11.53 x 48.18, 11.58
    { 124, 13386, 12378, LineMetaDataContent::Subway, Color{0xb4283c} }, // U2 OSM: 3531713 WD: Q830301 48.11, 11.54 x 48.21, 11.7
    { 139, 13402, 12378, LineMetaDataContent::Subway, Color{0x46b450} }, // U7 OSM: 3531714 WD: Q20439774 48.1, 11.53 x 48.18, 11.65
    { 142, 13418, 12378, LineMetaDataContent::Subway, Color{0xb4283c} }, // U8 OSM: 3531715 WD: Q20439777 48.1, 11.56 x 48.18, 11.65
    { 71, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x006536} }, // S1 OSM: 3533698 WD: Q106453739 47.4, 8.632 x 47.7, 9.4
    { 6, 13434, NoLogo, LineMetaDataContent::Subway, Color{0x9200c3} }, // 5 OSM: 3539820 WD: Q3308465 -23.66, -46.77 x -23.59, -46.63
    { 712, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe3000b} }, // A OSM: 3555528 WD: Q107044417 49.49, 0.09576 x 49.53, 0.137
    { 279, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00963e} }, // B OSM: 3555531 WD: Q107044421 49.49, 0.09576 x 49.52, 0.1801
    { 1760, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf49fc5} }, // T7 OSM: 3571840 WD: Q108046131 50.26, 18.92 x 50.35, 19.06
    { 1763, 13448, NoLogo, LineMetaDataContent::LongDistanceTrain, Color{0x0e7135} }, // IC LSA<=>BRA OSM: 3572421 WD: Q917100 38.71, -9.123 x 41.55, -8.415
    { 1776, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x50b948} }, // U BRA OSM: 3579399 WD: Q124220670 41.14, -8.61 x 41.55, -8.434
    { 660, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 39 OSM: 3587361 59.86, 30.38 x 59.93, 30.47
    { 725, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffdd00} }, // T2 OSM: 3589646 WD: Q3239232 45.44, 4.384 x 45.45, 4.403
    { 1329, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xafcb07} }, // T3 OSM: 3589647 WD: Q3239231 45.42, 4.378 x 45.47, 4.405
    { 64, 13465, NoLogo, LineMetaDataContent::Subway, Color{0x1a5ba3} }, // 1 OSM: 3596996 WD: Q3362568 -23.65, -46.64 x -23.48, -46.6
    { 9, 13479, NoLogo, LineMetaDataContent::Subway, Color{0xffd700} }, // 4 OSM: 3613482 WD: Q3308457 -23.59, -46.73 x -23.54, -46.63
    { 379, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xcd5c5c} }, // Red OSM: 3616739 WD: Q2472181 53.28, -6.438 x 53.35, -6.229
    { 68, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00bb00} }, // 3 OSM: 3618379 WD: Q107187377 58.58, 16.13 x 58.61, 16.19
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xcc0000} }, // 2 OSM: 3618409 WD: Q107187376 58.55, 16.13 x 58.61, 16.23
    { 16, 13493, NoLogo, LineMetaDataContent::Subway, Color{0x008162} }, // 2 OSM: 3619672 WD: Q588499 -23.6, -46.69 x -23.55, -46.58
    { 1782, 13507, 6136, LineMetaDataContent::Tramway, Color{0x009641} }, // T3b OSM: 3662457 WD: Q3136247 48.85, 2.274 x 48.9, 2.411
    { 289, 13541, 10457, LineMetaDataContent::Tramway, Color{0x873f98} }, // T1 OSM: 3667340 WD: Q2903 45.73, 4.817 x 45.79, 4.884
    { 1786, NoLogo, 10457, LineMetaDataContent::Tramway, Color{0xb80e28} }, // Rhônexpress OSM: 3667553 WD: Q1559 45.72, 4.862 x 45.78, 5.077
    { 725, 13561, 10457, LineMetaDataContent::Tramway, Color{0x873f98} }, // T2 OSM: 3667554 WD: Q2906 45.69, 4.819 x 45.75, 4.956
    { 1329, 13581, 10457, LineMetaDataContent::Tramway, Color{0x873f98} }, // T3 OSM: 3667555 WD: Q2911 45.75, 4.862 x 45.78, 5.035
    { 1393, 13601, 10457, LineMetaDataContent::Tramway, Color{0x873f98} }, // T4 OSM: 3667556 WD: Q2918 45.69, 4.858 x 45.78, 4.888
    { 279, 13621, 13642, LineMetaDataContent::Subway, Color{0x007dc5} }, // B OSM: 3687323 WD: Q2965 45.7, 4.802 x 45.77, 4.863
    { 283, 13671, 13642, LineMetaDataContent::Subway, Color{0x00ac4d} }, // D OSM: 3687324 WD: Q2976 45.7, 4.803 x 45.78, 4.89
    { 411, 13692, 13642, LineMetaDataContent::Subway, Color{0xf99d1d} }, // C OSM: 3687325 WD: Q2969 45.77, 4.827 x 45.79, 4.836
    { 712, 13713, 13642, LineMetaDataContent::Subway, Color{0xee3898} }, // A OSM: 3687326 WD: Q2944 45.75, 4.826 x 45.77, 4.922
    { 127, 13734, 948, LineMetaDataContent::Subway, Color{0xef7c00} }, // U3 OSM: 3752340 WD: Q876472 48.17, 16.31 x 48.21, 16.42
    { 146, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x93c13b} }, // 9 OSM: 3757041 WD: Q121317827 49.46, 8.17 x 49.49, 8.523
    { 105, 13746, 8524, LineMetaDataContent::Tramway, Color{0xf29dc3} }, // 62 OSM: 3775501 WD: Q2544169 50.86, 4.334 x 50.9, 4.435
    { 1799, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // Line 3 OSM: 3788350 WD: Q341464 29.25, 47.97 x 29.26, 47.97
    { 572, 13768, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 48 OSM: 3820771 WD: Q15982247 47.44, 19.03 x 47.5, 19.06
    { 68, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 3 OSM: 3822945 WD: Q121539704 55.16, 30.21 x 55.2, 30.24
    { 47, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 7 OSM: 3823035 WD: Q121539707 55.16, 30.12 x 55.2, 30.27
    { 64, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 1 OSM: 3823370 55.16, 30.12 x 55.2, 30.23
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 2 OSM: 3823520 WD: Q121539702 55.16, 30.12 x 55.19, 30.24
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 6 OSM: 3824263 WD: Q121539706 55.16, 30.12 x 55.2, 30.19
    { 146, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 9 OSM: 3824285 WD: Q121539710 55.16, 30.12 x 55.2, 30.2
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 8 OSM: 3824316 WD: Q121539708 55.16, 30.14 x 55.2, 30.24
    { 896, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x37bbed} }, // LR OSM: 3846824 WD: Q3239186 -35.58, -59.09 x -34.63, -57.95
    { 1125, 13792, 19, LineMetaDataContent::Tramway, Color{0x00a082} }, // 28 OSM: 3858971 WD: Q20439076 48.13, 11.56 x 48.17, 11.58
    { 68, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xbbee00} }, // 3 OSM: 3862190 WD: Q100159791 51.27, 9.441 x 51.34, 9.518
    { 47, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf5f000} }, // 7 OSM: 3862890 WD: Q114442370 51.27, 9.441 x 51.33, 9.541
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x924192} }, // 6 OSM: 3883145 WD: Q121361542 50.49, 12.11 x 50.53, 12.18
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x880015} }, // 5 OSM: 3883412 WD: Q121361541 50.49, 12.11 x 50.52, 12.17
    { 1571, 13813, 13843, LineMetaDataContent::Subway, Color{0xed1c24} }, // a OSM: 3889841 WD: Q24641190 48.09, -1.711 x 48.12, -1.644
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008995} }, // 12 OSM: 3903646 WD: Q18165631 -37.86, 145 x -37.81, 145
    { 411, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe4007c} }, // C OSM: 3921484 WD: Q3239086 45.17, 5.69 x 45.19, 5.776
    { 548, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x58318a} }, // E OSM: 3921488 WD: Q3239103 45.17, 5.661 x 45.26, 5.72
    { 279, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009b3a} }, // B OSM: 3921491 WD: Q3239068 45.18, 5.698 x 45.21, 5.787
    { 712, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0076bd} }, // A OSM: 3921492 WD: Q3239056 45.14, 5.671 x 45.2, 5.734
    { 283, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf39a00} }, // D OSM: 3921494 WD: Q3239096 45.17, 5.715 x 45.2, 5.759
    { 360, 13865, 3125, LineMetaDataContent::Subway, Color{0x007d58} }, // M1 OSM: 3931373 WD: Q1880894 55.62, 12.49 x 55.69, 12.59
    { 64, 13877, NoLogo, LineMetaDataContent::Subway, Color{0xf3d03e} }, // 1 OSM: 3936877 WD: Q1047385 23.07, 113.2 x 23.15, 113.3
    { 298, 13897, 2564, LineMetaDataContent::RapidTransit, Color{0xd4b4c4} }, // S6 OSM: 3937942 WD: Q112707551 47.25, 11.1 x 47.49, 11.4
    { 360, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe5442e} }, // M1 OSM: 3939086 WD: Q2740923 50.4, 4.271 x 50.42, 4.452
    { 1807, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x233e81} }, // TL OSM: 3939642 WD: Q2576140 19.26, -99.15 x 19.34, -99.11
    { 6, 13917, NoLogo, LineMetaDataContent::Subway, Color{0xc5003e} }, // 5 OSM: 3967180 WD: Q862888 23.05, 113.2 x 23.15, 113.5
    { 1810, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x7fa5d7} }, // T13 OSM: 3981303 WD: Q108046225 50.26, 18.96 x 50.3, 19.03
    { 1814, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x4499a8} }, // T17 OSM: 3981695 WD: Q108046412 50.28, 18.73 x 50.35, 18.95
    { 1818, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8ac53a} }, // T9 OSM: 3981764 WD: Q108046147 50.27, 18.87 x 50.35, 18.97
    { 1821, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x664c9c} }, // T15 OSM: 3984435 WD: Q108046344 50.26, 19.01 x 50.3, 19.2
    { 1825, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf2665b} }, // T24 OSM: 3990046 WD: Q108046716 50.27, 19.08 x 50.33, 19.15
    { 1829, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x650133} }, // T21 OSM: 3990849 WD: Q108046550 50.27, 19.08 x 50.34, 19.27
    { 117, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc5daf0} }, // T22 OSM: 3990873 WD: Q108046617 50.32, 19.07 x 50.34, 19.27
    { 1833, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe897bb} }, // T27 OSM: 3991031 WD: Q108046791 50.27, 19.11 x 50.33, 19.23
    { 46, NoLogo, 13937, LineMetaDataContent::RapidTransit, Color{0xf07f3a} }, // S7 OSM: 4006931 WD: Q115689937 46.93, 7.438 x 46.98, 7.563
    { 1837, 13953, 6136, LineMetaDataContent::Tramway, Color{0xb1a245} }, // T8 OSM: 4007734 WD: Q3239029 48.93, 2.294 x 48.96, 2.358
    { 349, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x66ba86} }, // 23 OSM: 4016993 WD: Q2914455 51.88, 4.432 x 51.92, 4.574
    { 64, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00bb00} }, // 1 OSM: 4037940 WD: Q105476776 51.31, 9.423 x 51.37, 9.502
    { 285, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa3429b} }, // TER T1 OSM: 4042689 WD: Q123466158 47.22, -1.549 x 47.72, -1.371
    { 64, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009036} }, // 1 OSM: 4043180 WD: Q121324553 51.89, 11.05 x 51.9, 11.07
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe2001a} }, // 2 OSM: 4043225 WD: Q121324704 51.87, 11.04 x 51.9, 11.07
    { 1840, 13986, 3759, LineMetaDataContent::RapidTransit, Color{0x000000} }, // S-2 OSM: 4051679 WD: Q107407547 43.34, -3.85 x 43.46, -3.707
    { 1844, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xdb0032} }, // GLNELG OSM: 4055996 WD: Q123413316 -34.98, 138.5 x -34.91, 138.6
    { 367, 14018, NoLogo, LineMetaDataContent::Subway, Color{0x003da5} }, // Blue OSM: 4086917 WD: Q152015 42.36, -71.06 x 42.41, -70.99
    { 68, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x99b3be} }, // 3 OSM: 4089342 WD: Q56302770 46.94, 7.431 x 46.95, 7.441
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0089cf} }, // 6 OSM: 4089819 WD: Q56302772 46.93, 7.419 x 46.95, 7.563
    { 1851, 14045, 8524, LineMetaDataContent::Tramway, Color{0xa12944} }, // 97 OSM: 4092822 WD: Q1865502 50.8, 4.313 x 50.84, 4.357
    { 239, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xae4a34} }, // 17 OSM: 4096027 WD: Q106766682 52.18, 20.94 x 52.34, 21.01
    { 340, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x800000} }, // 33 OSM: 4096028 WD: Q106769899 52.21, 20.92 x 52.29, 21.01
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 6 OSM: 4096029 WD: Q106767360 52.24, 20.93 x 52.3, 21.12
    { 157, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xdb1702} }, // 15 OSM: 4096032 WD: Q106766968 52.18, 20.94 x 52.28, 21.02
    { 153, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xde2916} }, // 14 OSM: 4096034 WD: Q106767826 52.16, 20.98 x 52.22, 21.08
    { 75, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf7230c} }, // 10 OSM: 4096042 WD: Q106766948 52.17, 20.9 x 52.24, 21.02
    { 1125, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x960018} }, // 28 OSM: 4096046 WD: Q106767043 52.24, 20.9 x 52.28, 21.05
    { 64, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf08080} }, // 1 OSM: 4096062 WD: Q106767154 52.21, 20.98 x 52.31, 21.04
    { 235, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xa52a2a} }, // 27 OSM: 4096066 WD: Q106767943 52.22, 20.93 x 52.27, 20.98
    { 118, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xbb0b0b} }, // 22 OSM: 4096081 WD: Q106767519 52.22, 20.94 x 52.27, 21.09
    { 9, 14067, 14077, LineMetaDataContent::Tramway, Color{0x4a2a15} }, // 4 OSM: 4107687 WD: Q3238942 43.59, 3.872 x 43.62, 3.897
    { 63, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xee1d23} }, // 11 OSM: 4108299 WD: Q3239102 47.47, 7.573 x 47.58, 7.612
    { 1453, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // 100 OSM: 4117854 39.1, -84.52 x 39.12, -84.51
    { 1265, 14106, 4645, LineMetaDataContent::Subway, Color{0x005ca5} }, // M3 OSM: 4121437 WD: Q692916 47.46, 19.05 x 47.56, 19.15
    { 8, 14128, 4645, LineMetaDataContent::Subway, Color{0x4ca22f} }, // M4 OSM: 4121438 WD: Q832651 47.46, 19.02 x 47.5, 19.08
    { 441, 14150, 4645, LineMetaDataContent::Subway, Color{0xe41f18} }, // M2 OSM: 4121439 WD: Q1071156 47.49, 19.02 x 47.51, 19.14
    { 47, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xee1d23} }, // 7 OSM: 4152763 WD: Q56302771 46.94, 7.38 x 46.95, 7.472
    { 411, 14172, 8099, LineMetaDataContent::Subway, Color{0x008751} }, // C OSM: 4173958 WD: Q2261550 41.86, 12.51 x 41.89, 12.71
    { 259, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 43 OSM: 4179202 WD: Q122585366 55.71, 37.66 x 55.79, 37.72
    { 64, 14213, NoLogo, LineMetaDataContent::Tramway, Color{0xf56202} }, // 1 OSM: 4198214 WD: Q21041074 48.14, 17.11 x 48.16, 17.12
    { 64, 14238, NoLogo, LineMetaDataContent::Tramway, Color{0xf18700} }, // 1 OSM: 4222397 WD: Q108215311 50.96, 10.99 x 51.01, 11.04
    { 16, 14264, NoLogo, LineMetaDataContent::Tramway, Color{0xe3000b} }, // 2 OSM: 4222399 WD: Q108215316 50.95, 10.98 x 50.98, 11.07
    { 68, 14290, NoLogo, LineMetaDataContent::Tramway, Color{0x67095f} }, // 3 OSM: 4222400 WD: Q108215641 50.94, 10.99 x 51.01, 11.09
    { 9, 14316, NoLogo, LineMetaDataContent::Tramway, Color{0x007ac3} }, // 4 OSM: 4222401 WD: Q108215690 50.97, 10.96 x 51, 11.07
    { 6, 14342, NoLogo, LineMetaDataContent::Tramway, Color{0x00883c} }, // 5 OSM: 4222402 WD: Q108215699 50.97, 11.02 x 51.02, 11.04
    { 27, 14368, NoLogo, LineMetaDataContent::Tramway, Color{0x78ac28} }, // 6 OSM: 4222403 WD: Q108215015 50.96, 11 x 51.01, 11.04
    { 22, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xdc143c} }, // 18 OSM: 4230615 WD: Q106767037 52.18, 20.99 x 52.29, 21.02
    { 318, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xb22222} }, // 26 OSM: 4230616 WD: Q106768213 52.22, 20.91 x 52.29, 21.09
    { 255, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xbc2001} }, // 24 OSM: 4230814 WD: Q106766559 52.22, 20.91 x 52.26, 21.12
    { 67, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xed0000} }, // 13 OSM: 4230815 WD: Q106767561 52.22, 20.93 x 52.26, 21.06
    { 251, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xbf3030} }, // 20 OSM: 4230816 WD: Q106767203 52.24, 20.9 x 52.29, 21.03
    { 1854, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfecc00} }, // 103 OSM: 4232441 WD: Q121299588 51.45, 6.914 x 51.49, 7.075
    { 441, 14394, 4108, LineMetaDataContent::Subway, Color{0xff0000} }, // M2 OSM: 4232535 WD: Q3832673 52.23, 20.91 x 52.29, 21.06
    { 64, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff7f00} }, // 1 OSM: 4234654 WD: Q121287729 51.8, 12.24 x 51.84, 12.24
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x18683c} }, // 6 OSM: 4236150 WD: Q121219170 52.4, 12.52 x 52.44, 12.57
    { 186, 14406, NoLogo, LineMetaDataContent::Subway, Color{0xffb619} }, // O OSM: 4250359 WD: Q6141590 24.99, 121.4 x 25.1, 121.5
    { 701, 14430, NoLogo, LineMetaDataContent::Subway, Color{0xcedc00} }, // G OSM: 4250382 WD: Q8044250 24.96, 121.5 x 25.05, 121.6
    { 1858, 14469, NoLogo, LineMetaDataContent::Subway, Color{0xa74c00} }, // BR OSM: 4264893 WD: Q707644 25, 121.5 x 25.09, 121.6
    { 1861, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00519e} }, // 104 OSM: 4272612 WD: Q121299589 51.43, 6.877 x 51.46, 6.934
    { 1865, 14494, NoLogo, LineMetaDataContent::RapidTransit, Color{0xb7d828} }, // S41 OSM: 4272651 WD: Q121237670 49.14, 9.106 x 49.35, 9.229
    { 1869, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x8b231d} }, // SFM 6 OSM: 4277114 WD: Q15077697 44.88, 7.654 x 45.12, 8.209
    { 1875, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // C11 OSM: 4287063 WD: Q104192648 50.71, 12.77 x 50.84, 12.93
    { 52, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf49694} }, // S5 OSM: 4292646 48.89, 8.243 x 49.06, 8.705
    { 16, 14511, NoLogo, LineMetaDataContent::Subway, Color{0x028f34} }, // 2 OSM: 4292976 WD: Q2333639 -22.95, -43.37 x -22.81, -43.17
    { 289, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffcc00} }, // T1 OSM: 4307991 WD: Q124256351 51.02, 3.692 x 51.06, 3.75
    { 1393, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe40521} }, // T4 OSM: 4307994 WD: Q124261809 51.02, 3.709 x 51.07, 3.75
    { 1879, 14530, NoLogo, LineMetaDataContent::LongDistanceTrain, Color{0x1a8fce} }, // IC 8 OSM: 4421943 WD: Q115932389 46.29, 7.437 x 47.59, 9.38
    { 1884, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x0080c8} }, // S19 OSM: 4434302 WD: Q30597732 50.76, 6.482 x 50.95, 7.66
    { 355, 14544, 226, LineMetaDataContent::RapidTransit, Color{0xf78a18} }, // S51 OSM: 4435864 WD: Q63433457 52.1, 9.374 x 52.4, 9.773
    { 1888, 14561, 226, LineMetaDataContent::RapidTransit, Color{0x118349} }, // S21 OSM: 4435868 WD: Q63433451 52.28, 9.466 x 52.38, 9.773
    { 379, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xcc0000} }, // Red OSM: 4439533 WD: Q7304502 33.64, -84.45 x 33.95, -84.34
    { 1892, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xf67705} }, // Gold OSM: 4439534 WD: Q5578774 33.64, -84.45 x 33.9, -84.28
    { 653, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x009544} }, // Green OSM: 4439535 WD: Q5602819 33.75, -84.43 x 33.78, -84.28
    { 367, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0274ba} }, // Blue OSM: 4439536 WD: Q4929368 33.75, -84.47 x 33.78, -84.23
    { 314, NoLogo, 14578, LineMetaDataContent::RapidTransit, Color{0x903f98} }, // S4 OSM: 4452991 WD: Q106368752 47.62, 12.87 x 47.84, 13
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe2e200} }, // 2 OSM: 4459896 WD: Q1488530 47.52, 21.61 x 47.56, 21.63
    { 1897, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xb7cd00} }, // 105 OSM: 4460024 WD: Q121299590 51.43, 6.9 x 51.48, 7.049
    { 239, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x714684} }, // 17 OSM: 4464579 WD: Q122382731 49.77, 18.16 x 49.83, 18.26
    { 55, 14598, 226, LineMetaDataContent::RapidTransit, Color{0x8ec7e8} }, // S8 OSM: 4470844 WD: Q63433462 52.32, 9.687 x 52.46, 9.792
    { 1901, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x80276c} }, // CR-Providence OSM: 4473913 WD: Q7252371 41.58, -71.49 x 42.35, -71.06
    { 1915, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x80276c} }, // CR-Franklin OSM: 4476404 WD: Q5491659 42.08, -71.44 x 42.35, -71.05
    { 157, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x714684} }, // 15 OSM: 4479092 WD: Q122382730 49.77, 18.22 x 49.8, 18.26
    { 1927, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x80276c} }, // CR-Kingston OSM: 4479349 WD: Q104818472 41.98, -71.06 x 42.35, -70.72
    { 16, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xc00000} }, // 2 OSM: 4479817 WD: Q125559509 22.92, -82.42 x 23.13, -82.34
    { 153, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x5a1e82} }, // 14 OSM: 4489019 WD: Q3238565 46.17, 6.06 x 46.24, 6.144
    { 22, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xb82f89} }, // 18 OSM: 4489020 WD: Q3238636 46.17, 6.055 x 46.23, 6.144
    { 157, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x84471c} }, // 15 OSM: 4489138 WD: Q3238583 46.17, 6.101 x 46.22, 6.149
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xea556f} }, // 5 OSM: 4492488 WD: Q122382721 49.82, 18.05 x 49.85, 18.16
    { 64, 14614, NoLogo, LineMetaDataContent::Subway, Color{0x008000} }, // 1 OSM: 4494027 WD: Q10914047 24.11, 120.6 x 24.19, 120.7
    { 9, 14649, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 4 OSM: 4494871 WD: Q2105648 52.34, 4.889 x 52.38, 4.905
    { 15, 14659, NoLogo, LineMetaDataContent::Tramway, Color{0xab10d2} }, // 12 OSM: 4495366 WD: Q14500288 52.35, 4.879 x 52.38, 4.919
    { 64, 14670, NoLogo, LineMetaDataContent::Tramway, Color{0xffbf00} }, // 1 OSM: 4497227 WD: Q2663350 52.35, 4.775 x 52.36, 4.934
    { 16, 14680, NoLogo, LineMetaDataContent::Tramway, Color{0xffbf00} }, // 2 OSM: 4497722 WD: Q2033321 52.34, 4.804 x 52.38, 4.899
    { 68, 14690, NoLogo, LineMetaDataContent::Tramway, Color{0xab10d2} }, // 3 OSM: 4498754 WD: Q2051638 52.35, 4.87 x 52.38, 4.952
    { 1939, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffcd28} }, // Z70 OSM: 4498934 WD: Q109333261 47.51, 18.86 x 47.83, 19.16
    { 1943, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xb0c4de} }, // PST OSM: 4499555 WD: Q7119275 33.43, -112 x 33.45, -112
    { 1947, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00aff0} }, // S70 OSM: 4500998 WD: Q109333249 47.51, 18.86 x 47.83, 19.16
    { 309, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00aff0} }, // S71 OSM: 4500999 WD: Q109333250 47.51, 19.06 x 47.78, 19.3
    { 6, 14700, NoLogo, LineMetaDataContent::Tramway, Color{0xffbf00} }, // 5 OSM: 4501532 WD: Q2343376 52.3, 4.867 x 52.39, 4.886
    { 47, 14710, NoLogo, LineMetaDataContent::Tramway, Color{0xff7f00} }, // 7 OSM: 4502267 WD: Q4405692 52.36, 4.818 x 52.38, 4.94
    { 161, 14720, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 19 OSM: 4507967 WD: Q2402279 52.34, 4.838 x 52.39, 4.971
    { 242, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00aff0} }, // S50 OSM: 4508158 WD: Q104161828 47.17, 19.06 x 47.52, 20.18
    { 1951, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00985f} }, // Babylon OSM: 4509487 WD: Q4838506 40.66, -73.99 x 40.75, -73.33
    { 1959, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x999e9e} }, // VLT Curado-Cajueiro Seco OSM: 4510189 WD: Q18473919 -8.177, -34.99 x -8.075, -34.93
    { 1984, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // VLT Cabo - Cajueiro Seco OSM: 4510254 WD: Q18473915 -8.287, -35.04 x -8.168, -34.93
    { 67, 14731, NoLogo, LineMetaDataContent::Tramway, Color{0xab10d2} }, // 13 OSM: 4512711 WD: Q2157983 52.37, 4.803 x 52.38, 4.899
    { 153, 14742, NoLogo, LineMetaDataContent::Tramway, Color{0x00ff00} }, // 14 OSM: 4513498 WD: Q2108285 52.36, 4.892 x 52.38, 4.94
    { 255, 14753, NoLogo, LineMetaDataContent::Tramway, Color{0xf49ac1} }, // 24 OSM: 4513900 WD: Q2651682 52.34, 4.857 x 52.36, 4.9
    { 239, 14764, NoLogo, LineMetaDataContent::Tramway, Color{0x007fff} }, // 17 OSM: 4514442 WD: Q2400889 52.36, 4.786 x 52.38, 4.899
    { 318, 14775, NoLogo, LineMetaDataContent::Tramway, Color{0xd59758} }, // 26 OSM: 4514564 WD: Q2503173 52.35, 4.903 x 52.38, 5.005
    { 243, 14786, 14825, LineMetaDataContent::Subway, Color{0x29ab4d} }, // 50 OSM: 4515358 WD: Q2466111 52.29, 4.834 x 52.4, 4.99
    { 356, 14850, 14825, LineMetaDataContent::Subway, Color{0xf69931} }, // 51 OSM: 4515359 WD: Q61964024 52.33, 4.834 x 52.4, 4.924
    { 2010, 14889, 14825, LineMetaDataContent::Subway, Color{0xfcfb05} }, // 54 OSM: 4515360 WD: Q2183200 52.29, 4.9 x 52.38, 4.99
    { 2014, 14928, 14825, LineMetaDataContent::Subway, Color{0xff0000} }, // 53 OSM: 4515361 WD: Q2163442 52.31, 4.9 x 52.38, 4.985
    { 1888, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00aff0} }, // S21 OSM: 4517111 WD: Q101148856 46.89, 19.06 x 47.52, 19.71
    { 2017, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00aff0} }, // S210 OSM: 4522098 WD: Q109333255 46.89, 19.48 x 47.1, 19.71
    { 1399, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009adf} }, // 901 OSM: 4525409 WD: Q121292575 51.43, 6.732 x 51.51, 6.887
    { 2022, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffcd28} }, // Z50 OSM: 4537671 WD: Q104170252 47.17, 19.06 x 47.52, 20.18
    { 1080, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00aff0} }, // S10 OSM: 4543849 WD: Q103726127 47.45, 17.64 x 47.75, 19.03
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xbd1522} }, // 2 OSM: 4543902 WD: Q122204280 50.78, 19.12 x 50.84, 19.15
    { 64, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x1c70b8} }, // 1 OSM: 4543906 WD: Q122204279 50.78, 19.12 x 50.84, 19.17
    { 68, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x38a935} }, // 3 OSM: 4543907 WD: Q122204281 50.77, 19.12 x 50.84, 19.16
    { 2026, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009adf} }, // 903 OSM: 4544338 WD: Q121292819 51.37, 6.729 x 51.57, 6.795
    { 2030, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffcd28} }, // Z30 OSM: 4546118 WD: Q109333259 47.17, 18.42 x 47.5, 19.04
    { 356, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 51 OSM: 4554929 59.98, 30.4 x 60.05, 30.44
    { 2034, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffa500} }, // NS OSM: 4566683 WD: Q16959474 45.49, -122.7 x 45.53, -122.7
    { 63, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe9383f} }, // 11 OSM: 4591254 WD: Q106770207 52.21, 20.91 x 52.26, 21.05
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff1493} }, // 5 OSM: 4621317 WD: Q55676167 53.01, 18.55 x 53.03, 18.7
    { 2037, 14967, 14994, LineMetaDataContent::Subway, Color{0xe2007a} }, // m2 OSM: 4621397 WD: Q3239144 46.51, 6.626 x 46.54, 6.662
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x94c11a} }, // 2 OSM: 4622863 WD: Q121253958 52.23, 10.52 x 52.29, 10.54
    { 47, 15019, 4547, LineMetaDataContent::Subway, Color{0xffc66e} }, // 7 OSM: 4624900 WD: Q6553149 39.85, 116.3 x 39.89, 116.7
    { 153, 15039, 4547, LineMetaDataContent::Subway, Color{0xd4a7a1} }, // 14 OSM: 4624915 WD: Q6553070 39.86, 116.2 x 40.03, 116.5
    { 27, 15060, 4547, LineMetaDataContent::Subway, Color{0xbb8900} }, // 6 OSM: 4625142 WD: Q6553138 39.9, 116.2 x 39.93, 116.7
    { 64, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xec008c} }, // 1 OSM: 4628650 WD: Q121410306 47.15, 27.56 x 47.19, 27.63
    { 68, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00a650} }, // 3 OSM: 4629075 WD: Q121410307 47.15, 27.57 x 47.17, 27.66
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf9c0c1} }, // 6 OSM: 4631231 WD: Q121410309 47.16, 27.54 x 47.17, 27.59
    { 47, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x2e3092} }, // 7 OSM: 4631274 WD: Q121410310 47.14, 27.54 x 47.17, 27.64
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xd2e288} }, // 8 OSM: 4631290 WD: Q121410311 47.14, 27.56 x 47.19, 27.64
    { 121, 15080, 1489, LineMetaDataContent::Subway, Color{0xb8282e} }, // U1 OSM: 4656730 WD: Q198432 50.1, 8.634 x 50.17, 8.688
    { 127, 15097, 1489, LineMetaDataContent::Subway, Color{0x4a5eaa} }, // U3 OSM: 4656731 WD: Q19862991 50.1, 8.537 x 50.22, 8.688
    { 130, 15114, 1489, LineMetaDataContent::Subway, Color{0xf172ac} }, // U4 OSM: 4656732 WD: Q19862998 50.11, 8.652 x 50.14, 8.754
    { 133, 15131, 1489, LineMetaDataContent::Subway, Color{0x007942} }, // U5 OSM: 4656733 WD: Q3040872 50.11, 8.663 x 50.16, 8.692
    { 139, 15148, 1489, LineMetaDataContent::Subway, Color{0xe4a024} }, // U7 OSM: 4656734 WD: Q3040904 50.11, 8.608 x 50.14, 8.754
    { 142, 15165, 1489, LineMetaDataContent::Subway, Color{0xc77db5} }, // U8 OSM: 4656735 WD: Q3063407 50.1, 8.621 x 50.18, 8.688
    { 145, 15182, 1489, LineMetaDataContent::Subway, Color{0xeed700} }, // U9 OSM: 4656736 WD: Q19862984 50.14, 8.621 x 50.2, 8.674
    { 1393, 2668, NoLogo, LineMetaDataContent::Tramway, Color{0x008176} }, // T4 OSM: 4665787 WD: Q49368235 41.4, 2.167 x 41.42, 2.231
    { 1627, 7402, NoLogo, LineMetaDataContent::Tramway, Color{0x008176} }, // T6 OSM: 4665788 WD: Q49375135 41.39, 2.187 x 41.42, 2.231
    { 1396, 2027, NoLogo, LineMetaDataContent::Tramway, Color{0x008176} }, // T5 OSM: 4665789 WD: Q49394264 41.39, 2.187 x 41.44, 2.233
    { 1329, 7904, NoLogo, LineMetaDataContent::Tramway, Color{0x008176} }, // T3 OSM: 4667001 WD: Q49770929 41.37, 2.053 x 41.39, 2.143
    { 289, 9300, NoLogo, LineMetaDataContent::Tramway, Color{0x008176} }, // T1 OSM: 4667002 WD: Q49770336 41.36, 2.058 x 41.39, 2.143
    { 725, 9257, NoLogo, LineMetaDataContent::Tramway, Color{0x008176} }, // T2 OSM: 4667003 WD: Q49770664 41.36, 2.058 x 41.39, 2.143
    { 524, 15199, 15216, LineMetaDataContent::Subway, Color{0x992f9c} }, // L2 OSM: 4671269 WD: Q1348921 41.38, 2.163 x 41.45, 2.244
    { 516, 15241, 15216, LineMetaDataContent::Subway, Color{0xfab70a} }, // L4 OSM: 4671321 WD: Q961384 41.38, 2.163 x 41.45, 2.218
    { 1353, 15258, 15216, LineMetaDataContent::Subway, Color{0x317bc8} }, // L5 OSM: 4673514 WD: Q1348939 41.36, 2.071 x 41.43, 2.187
    { 2040, 15275, 15216, LineMetaDataContent::Subway, Color{0x00adef} }, // L10 Nord OSM: 4673515 WD: Q1785338 41.42, 2.186 x 41.44, 2.234
    { 528, 15293, 15216, LineMetaDataContent::Subway, Color{0x39af57} }, // L3 OSM: 4673516 WD: Q385168 41.37, 2.11 x 41.45, 2.188
    { 1365, 15310, 15216, LineMetaDataContent::Subway, Color{0xe27aaf} }, // L8 OSM: 4673517 WD: Q763319 41.35, 2.035 x 41.37, 2.148
    { 1361, 15327, 15216, LineMetaDataContent::Subway, Color{0xac5414} }, // L7 OSM: 4673518 WD: Q678390 41.39, 2.137 x 41.41, 2.169
    { 520, 15344, 15216, LineMetaDataContent::Subway, Color{0xe33638} }, // L1 OSM: 4673519 WD: Q1348946 41.34, 2.099 x 41.45, 2.218
    { 493, 15361, 15216, LineMetaDataContent::Subway, Color{0x9ed74c} }, // L11 OSM: 4673520 WD: Q1419762 41.45, 2.173 x 41.46, 2.186
    { 1357, 15379, 15216, LineMetaDataContent::Subway, Color{0x7280c0} }, // L6 OSM: 4673521 WD: Q1577019 41.39, 2.125 x 41.4, 2.169
    { 2049, 15396, 15216, LineMetaDataContent::Subway, Color{0xf6842a} }, // L9 Nord OSM: 4673522 WD: Q1577033 41.42, 2.186 x 41.46, 2.22
    { 1276, 15413, NoLogo, LineMetaDataContent::LocalTrain, Color{0xfdda24} }, // 86966 OSM: 4684542 WD: Q205585 42.42, 2.866 x 43.94, 4.805
    { 2057, 15413, NoLogo, LineMetaDataContent::LocalTrain, Color{0xfdda24} }, // 86990 OSM: 4684543 WD: Q205585 42.42, 2.866 x 43.19, 3.168
    { 161, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x60d1c5} }, // 19 OSM: 4748539 52.37, 16.9 x 52.46, 16.94
    { 64, 15426, NoLogo, LineMetaDataContent::Tramway, Color{0xca0047} }, // 1 OSM: 4748602 WD: Q117280796 52.38, 16.83 x 52.4, 17
    { 16, 15464, NoLogo, LineMetaDataContent::Tramway, Color{0x79bee2} }, // 2 OSM: 4750038 WD: Q108006450 52.37, 16.88 x 52.42, 16.94
    { 2063, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x800080} }, // Tren Urbano OSM: 4751620 WD: Q1577126 18.39, -66.15 x 18.44, -66.05
    { 68, 15502, NoLogo, LineMetaDataContent::Tramway, Color{0x6d053d} }, // 3 OSM: 4756145 WD: Q108000703 52.37, 16.91 x 52.46, 16.98
    { 6, 15540, NoLogo, LineMetaDataContent::Tramway, Color{0x76ce47} }, // 5 OSM: 4763766 WD: Q111590889 52.38, 16.88 x 52.41, 16.96
    { 531, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00943c} }, // 109 OSM: 4773640 WD: Q121299593 51.45, 6.955 x 51.46, 7.075
    { 2077, 15578, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe67310} }, // A2 OSM: 4785912 WD: Q19582807 53.71, 9.889 x 54.08, 10.02
    { 2080, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x004d9f} }, // Tide OSM: 4788761 WD: Q112724328 36.84, -76.3 x 36.86, -76.19
    { 2085, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xec1c24} }, // 703 OSM: 4789075 WD: Q7304509 40.54, -112 x 40.77, -111.8
    { 2089, NoLogo, 5411, LineMetaDataContent::RapidTransit, Color{0xbdbadc} }, // Penn OSM: 4799477 WD: Q7163197 38.9, -77.01 x 39.56, -76.07
    { 19, 15593, NoLogo, LineMetaDataContent::Tramway, Color{0xfc95c5} }, // 8 OSM: 4828592 WD: Q1962342 51.21, 4.42 x 51.22, 4.492
    { 2094, 15615, 3759, LineMetaDataContent::RapidTransit, Color{0xffcc00} }, // C6 OSM: 4840309 WD: Q77072004 43.34, -5.856 x 43.39, -5.361
    { 68, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008080} }, // 3 OSM: 5143295 WD: Q122395001 49.2, 16.52 x 49.23, 16.64
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffa500} }, // 4 OSM: 5151976 WD: Q122395002 49.19, 16.58 x 49.23, 16.65
    { 289, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00a5c1} }, // T1 OSM: 5157502 WD: Q16011470 47.22, 5.951 x 47.26, 6.061
    { 2, 15642, NoLogo, LineMetaDataContent::Tramway, Color{0x0d7b49} }, // 0 OSM: 5175545 WD: Q108006493 52.39, 16.89 x 52.41, 16.94
    { 64, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe4002c} }, // 1 OSM: 5185991 WD: Q91659218 51, 13.67 x 51.06, 13.82
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xeb5b2d} }, // 2 OSM: 5186008 WD: Q91659698 51.01, 13.65 x 51.06, 13.85
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc9061a} }, // 4 OSM: 5186035 WD: Q91660551 51.02, 13.56 x 51.16, 13.84
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffdd00} }, // 6 OSM: 5186067 WD: Q93766509 51, 13.68 x 51.06, 13.84
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x229133} }, // 8 OSM: 5186073 WD: Q64022460 51.03, 13.72 x 51.12, 13.77
    { 146, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x93c355} }, // 9 OSM: 5186435 WD: Q93767104 51, 13.69 x 51.08, 13.8
    { 75, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf9b000} }, // 10 OSM: 5186677 WD: Q93767517 51.04, 13.71 x 51.07, 13.81
    { 63, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc2ddaf} }, // 11 OSM: 5186681 WD: Q91034464 51.02, 13.73 x 51.07, 13.86
    { 67, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfdc300} }, // 13 OSM: 5186751 WD: Q93767971 51, 13.69 x 51.08, 13.8
    { 2097, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00aff0} }, // S150 OSM: 5189451 WD: Q101110277 47.18, 18.01 x 47.75, 18.42
    { 2102, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xaacd46} }, // G30 OSM: 5189583 WD: Q104161605 47.17, 18.43 x 47.5, 19.04
    { 2106, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00aff0} }, // S820 OSM: 5189587 WD: Q109333257 47.17, 19.67 x 47.66, 20.18
    { 1723, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00aff0} }, // S42 OSM: 5189590 WD: Q112963134 46.96, 18.76 x 47.5, 19.04
    { 2111, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xaacd46} }, // G10 OSM: 5189591 WD: Q103834888 47.45, 17.14 x 47.91, 19.12
    { 2116, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00aff0} }, // S30 OSM: 5189595 WD: Q101095853 46.75, 17.56 x 47.5, 19.04
    { 2120, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00aff0} }, // S220 OSM: 5189596 WD: Q112963797 46.85, 19.7 x 47.18, 20.18
    { 2125, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xaacd46} }, // G71 OSM: 5189597 WD: Q109333268 47.51, 19.06 x 47.78, 19.3
    { 2129, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xaacd46} }, // G70 OSM: 5189600 WD: Q109333266 47.51, 18.86 x 47.83, 19.16
    { 2133, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xaacd46} }, // G43 OSM: 5189602 WD: Q109333264 47.17, 18.42 x 47.48, 19.35
    { 1319, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00aff0} }, // S20 OSM: 5189604 WD: Q103835740 46.23, 19.06 x 47.52, 20.14
    { 273, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00aff0} }, // S40 OSM: 5189605 WD: Q112963108 46.37, 18.15 x 47.5, 19.04
    { 1255, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00aff0} }, // S36 OSM: 5189606 WD: Q109333242 47.25, 18.69 x 47.48, 19.35
    { 2137, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00aff0} }, // S35 OSM: 5189607 WD: Q109333241 46.44, 16.99 x 47.5, 19.04
    { 2141, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00aff0} }, // S34 OSM: 5189609 WD: Q104433012 46.69, 17.24 x 47.5, 19.04
    { 64, NoLogo, 976, LineMetaDataContent::Tramway, Color{0xd52330} }, // 1 OSM: 5209167 WD: Q63442516 50.93, 6.816 x 50.96, 7.162
    { 2145, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x1f9cd8} }, // NC (NB) OSM: 5214593 WD: Q125156771 53.34, -6.429 x 54, -6.112
    { 1058, 15680, 9742, LineMetaDataContent::RapidTransit, Color{0xf26021} }, // S32 OSM: 5219521 WD: Q87069535 51.08, 4.283 x 51.54, 4.467
    { 47, NoLogo, 976, LineMetaDataContent::Tramway, Color{0xe6855c} }, // 7 OSM: 5231292 WD: Q63442539 50.87, 6.797 x 50.94, 7.06
    { 46, 15706, 10793, LineMetaDataContent::RapidTransit, Color{0x159dd9} }, // S7 OSM: 5248498 WD: Q17101554 48.1, 16.38 x 48.57, 17.01
    { 181, 15718, 10793, LineMetaDataContent::RapidTransit, Color{0x159dd9} }, // S60 OSM: 5248503 WD: Q96483899 47.81, 16.23 x 48.19, 16.78
    { 242, 15731, 10793, LineMetaDataContent::RapidTransit, Color{0x159dd9} }, // S50 OSM: 5248504 WD: Q96483895 48.17, 15.98 x 48.21, 16.34
    { 2153, 15744, 10793, LineMetaDataContent::RapidTransit, Color{0x159dd9} }, // S80 OSM: 5248538 WD: Q96483911 48.17, 16.26 x 48.23, 16.51
    { 343, 15757, 10793, LineMetaDataContent::RapidTransit, Color{0xbdd542} }, // S45 OSM: 5248540 WD: Q17101545 48.19, 16.26 x 48.26, 16.39
    { 273, 15770, 10793, LineMetaDataContent::RapidTransit, Color{0x159dd9} }, // S40 OSM: 5248548 WD: Q96483953 48.21, 15.62 x 48.35, 16.37
    { 64, NoLogo, 15783, LineMetaDataContent::Tramway, Color{0x0000ff} }, // 1 OSM: 5252357 WD: Q112081451 39.22, 9.125 x 39.27, 9.143
    { 16, NoLogo, 15783, LineMetaDataContent::Tramway, Color{0x0080ff} }, // 2 OSM: 5252358 WD: Q112081586 39.26, 9.126 x 39.29, 9.177
    { 64, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xeb4690} }, // 1 OSM: 5293755 33.98, -6.865 x 34.05, -6.794
    { 1329, 15806, 9264, LineMetaDataContent::Tramway, Color{0x96be0d} }, // T3 OSM: 5296539 WD: Q3238910 43.29, 5.367 x 43.32, 5.384
    { 2157, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x996c1b} }, // 106 OSM: 5310407 WD: Q121299586 51.44, 6.95 x 51.48, 7.019
    { 2161, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00519e} }, // 101 OSM: 5310407 WD: Q121299586 51.44, 6.95 x 51.48, 7.019
    { 2165, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xeca900} }, // 108 OSM: 5310861 WD: Q121299592 51.41, 6.993 x 51.48, 7.019
    { 148, NoLogo, 976, LineMetaDataContent::Subway, Color{0x342a82} }, // U11 OSM: 5311905 WD: Q110928761 51.42, 6.992 x 51.54, 7.026
    { 2169, NoLogo, 976, LineMetaDataContent::Subway, Color{0x68b6e3} }, // U17 OSM: 5312041 WD: Q121298190 51.43, 6.973 x 51.5, 7.013
    { 2173, NoLogo, 976, LineMetaDataContent::Subway, Color{0x0080c8} }, // U18 OSM: 5312153 WD: Q88799606 51.43, 6.886 x 51.46, 7.013
    { 2178, 15828, NoLogo, LineMetaDataContent::Subway, Color{0x02ac39} }, // TR OSM: 5326658 WD: Q843148 35.7, 140 x 35.73, 140.1
    { 146, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8a2be2} }, // 9 OSM: 5329880 WD: Q122395008 49.19, 16.61 x 49.23, 16.65
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x221815} }, // 6 OSM: 5335066 WD: Q957721 33.84, 132.8 x 33.85, 132.8
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x036eb8} }, // 5 OSM: 5335067 33.84, 132.8 x 33.85, 132.8
    { 68, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe60012} }, // 3 OSM: 5335068 33.84, 132.8 x 33.85, 132.8
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x6a7045} }, // 8 OSM: 5351647 WD: Q123363018 56.83, 60.56 x 56.9, 60.69
    { 2181, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x37bbed} }, // TDV OSM: 5371521 WD: Q23951292 -38.96, -68.23 x -38.96, -68.06
    { 2185, NoLogo, 15857, LineMetaDataContent::RapidTransit, Color{0x221e44} }, // S44 OSM: 5378417 WD: Q124214433 50.23, 14.24 x 50.28, 14.31
    { 314, NoLogo, 15857, LineMetaDataContent::RapidTransit, Color{0xf27e00} }, // S4 OSM: 5378441 WD: Q107983587 50.09, 14.3 x 50.45, 14.44
    { 663, 15876, 3759, LineMetaDataContent::RapidTransit, Color{0x8b039b} }, // C-3 OSM: 5382815 WD: Q8879464 40.03, -3.71 x 40.48, -3.608
    { 356, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x4a4a49} }, // 51 OSM: 5387664 49.96, 8.178 x 50.02, 8.26
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x1ca9e1} }, // 5 OSM: 5389816 WD: Q124656080 49.85, 8.65 x 49.9, 8.683
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00a54f} }, // 2 OSM: 5390308 WD: Q124656077 49.86, 8.631 x 49.87, 8.682
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x662584} }, // 2 OSM: 5391128 33.99, -6.872 x 34.04, -6.752
    { 47, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xed028c} }, // 7 OSM: 5394295 WD: Q124656082 49.81, 8.644 x 49.87, 8.657
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xdf2a29} }, // 8 OSM: 5394296 WD: Q124656083 49.74, 8.613 x 49.92, 8.658
    { 146, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x7cbe45} }, // 9 OSM: 5394637 WD: Q124656084 49.85, 8.555 x 49.87, 8.67
    { 68, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf6c027} }, // 3 OSM: 5394736 WD: Q124656078 49.85, 8.631 x 49.88, 8.657
    { 71, 15894, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffa500} }, // S1 OSM: 5405974 WD: Q5425454 41.39, 2.007 x 41.58, 2.169
    { 59, 15911, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7e971e} }, // S2 OSM: 5405975 WD: Q5425453 41.39, 2.068 x 41.57, 2.169
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xd51a1f} }, // 8 OSM: 5412689 WD: Q108000373 54.34, 18.58 x 54.42, 18.73
    { 146, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x185696} }, // 9 OSM: 5412706 WD: Q117011206 54.34, 18.58 x 54.39, 18.73
    { 251, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf9b000} }, // 20 OSM: 5421483 51.04, 13.71 x 51.07, 13.74
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00aeef} }, // 6 OSM: 5424499 WD: Q116997752 54.32, 18.56 x 54.42, 18.65
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xa6ce39} }, // 2 OSM: 5424501 WD: Q108000249 54.33, 18.56 x 54.42, 18.65
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf58220} }, // 12 OSM: 5446660 WD: Q117011363 54.33, 18.56 x 54.42, 18.65
    { 64, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x000080} }, // 1 OSM: 5465576 WD: Q10318641 -30.03, -51.23 x -29.69, -51.13
    { 1273, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8b0000} }, // 31 OSM: 5475000 WD: Q106770155 52.18, 20.99 x 52.19, 21.02
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xa2238e} }, // 4 OSM: 5486024 WD: Q116984679 54.33, 18.57 x 54.42, 18.64
    { 64, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc3272b} }, // 1 OSM: 5490398 WD: Q15934788 41.66, 123.4 x 41.74, 123.5
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x003171} }, // 2 OSM: 5490399 WD: Q28415057 41.63, 123.5 x 41.74, 123.5
    { 68, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x007b43} }, // 3 OSM: 5490400 WD: Q28415058 41.65, 123.4 x 41.72, 123.5
    { 47, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xac8c6a} }, // 7 OSM: 5504875 WD: Q108000365 54.32, 18.6 x 54.4, 18.67
    { 289, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // T1 OSM: 5510640 WD: Q113671848 45.44, 12.25 x 45.51, 12.32
    { 2189, 15928, NoLogo, LineMetaDataContent::RapidTransit, Color{0x3dae2b} }, // 1 Line OSM: 5517061 WD: Q1067251 47.42, -122.3 x 47.82, -122.3
    { 1446, NoLogo, 2638, LineMetaDataContent::RapidTransit, Color{0xffa500} }, // Orange OSM: 5543450 WD: Q6714620 45.43, -122.7 x 45.53, -122.6
    { 279, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0088ab} }, // B OSM: 5575252 WD: Q115210980 45.5, -122.7 x 45.54, -122.7
    { 2183, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfebeb5} }, // V OSM: 5576487 WD: Q11152362 25.15, 121.4 x 25.2, 121.5
    { 1410, 15960, NoLogo, LineMetaDataContent::LocalTrain, Color{0xb9d643} }, // RE5 OSM: 5577109 WD: Q64223427 53.45, 8.704 x 53.86, 10.03
    { 349, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc60800} }, // 23 OSM: 5579462 WD: Q106766924 52.24, 20.91 x 52.26, 21.04
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xecb224} }, // 5 OSM: 5587313 WD: Q116997091 54.37, 18.56 x 54.41, 18.68
    { 68, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xed028c} }, // 3 OSM: 5587314 WD: Q108000276 54.32, 18.6 x 54.41, 18.68
    { 411, 15976, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7cbd52} }, // C OSM: 5593997 WD: Q4121246 22.59, 120.3 x 22.66, 120.3
    { 64, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x392991} }, // 1 OSM: 5594238 WD: Q122781780 45.75, 21.21 x 45.77, 21.26
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xdd2b1c} }, // 2 OSM: 5594256 WD: Q122781781 45.73, 21.2 x 45.77, 21.26
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0c0c0c} }, // 8 OSM: 5594329 WD: Q122781784 45.73, 21.21 x 45.75, 21.26
    { 146, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x82d8df} }, // 9 OSM: 5594335 WD: Q122781785 45.73, 21.2 x 45.75, 21.26
    { 352, 16018, NoLogo, LineMetaDataContent::RapidTransit, Color{0x78be20} }, // A3 OSM: 5596928 WD: Q47477355 37.99, 23.57 x 38.46, 23.87
    { 59, 16053, 226, LineMetaDataContent::RapidTransit, Color{0xa70f47} }, // S2 OSM: 5607597 WD: Q19390036 53.49, 9.932 x 53.56, 10.32
    { 52, 16073, 226, LineMetaDataContent::RapidTransit, Color{0x008abd} }, // S5 OSM: 5607598 WD: Q63451353 53.46, 9.477 x 53.6, 10.03
    { 2198, 16088, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe79500} }, // A1 OSM: 5610369 WD: Q19368804 53.59, 9.898 x 53.77, 9.973
    { 68, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff6347} }, // 3 OSM: 5611529 WD: Q106767972 52.24, 21.02 x 52.3, 21.12
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff5e4d} }, // 4 OSM: 5611530 WD: Q106767540 52.17, 21 x 52.31, 21.04
    { 16, 16103, NoLogo, LineMetaDataContent::Subway, Color{0xe70095} }, // 2 OSM: 5616937 WD: Q3832658 39.43, -0.5963 x 39.62, -0.3815
    { 146, 16134, NoLogo, LineMetaDataContent::Subway, Color{0xb7814f} }, // 9 OSM: 5622181 WD: Q18613779 39.47, -0.5603 x 39.54, -0.3521
    { 47, 16165, NoLogo, LineMetaDataContent::Subway, Color{0xf28c00} }, // 7 OSM: 5626070 WD: Q11690011 39.43, -0.4726 x 39.47, -0.3383
    { 2201, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xed1d24} }, // S1A OSM: 5642742 WD: Q56692645 44.16, 10.98 x 44.52, 11.34
    { 68, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xbe1716} }, // 3 OSM: 5646916 WD: Q121196130 50.69, 12.46 x 50.74, 12.53
    { 2205, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa02225} }, // S1B OSM: 5648214 WD: Q56692647 44.22, 11.18 x 44.51, 11.38
    { 2209, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xbed747} }, // S2A OSM: 5648243 WD: Q56692650 44.48, 11.01 x 44.52, 11.34
    { 2213, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x73a534} }, // S2B OSM: 5648273 WD: Q56692652 44.49, 11.35 x 44.7, 11.81
    { 225, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa50575} }, // S3 OSM: 5648349 WD: Q56692654 44.51, 11.11 x 44.98, 11.34
    { 2217, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0066b3} }, // S4A OSM: 5648362 WD: Q56692656 44.51, 11.32 x 44.84, 11.6
    { 2221, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x2a2a86} }, // S4B OSM: 5648385 WD: Q56692658 44.36, 11.34 x 44.51, 11.72
    { 52, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfdc214} }, // S5 OSM: 5648393 WD: Q56692659 44.51, 10.93 x 44.65, 11.34
    { 251, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffa500} }, // 20 OSM: 5664426 WD: Q30716928 52.01, 5.076 x 52.09, 5.184
    { 82, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffa500} }, // 21 OSM: 5664427 WD: Q81422423 52.01, 5.028 x 52.09, 5.184
    { 63, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf05b72} }, // 11 OSM: 5668462 WD: Q121410312 47.15, 27.54 x 47.17, 27.63
    { 67, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00adef} }, // 13 OSM: 5668463 WD: Q121410313 47.15, 27.56 x 47.19, 27.63
    { 1453, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 100 OSM: 5671142 WD: Q122466845 46.78, 23.59 x 46.8, 23.65
    { 2161, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 101 OSM: 5673692 WD: Q122466868 46.75, 23.54 x 46.78, 23.59
    { 2225, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 102 OSM: 5673737 WD: Q122466923 46.75, 23.54 x 46.8, 23.65
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x9ad2ae} }, // 8 OSM: 5685450 WD: Q17440814 45.78, 15.97 x 45.86, 16
    { 2229, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // E-W OSM: 5697658 WD: Q53778901 9.01, 38.72 x 9.022, 38.87
    { 2233, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // S-N OSM: 5697659 WD: Q53779001 8.936, 38.73 x 9.039, 38.77
    { 47, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xa3c2d1} }, // 7 OSM: 5706899 WD: Q117193191 45.78, 15.95 x 45.82, 16.04
    { 146, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x9a94c8} }, // 9 OSM: 5707039 WD: Q17440798 45.8, 15.94 x 45.82, 16.02
    { 63, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfff685} }, // 11 OSM: 5707158 WD: Q116913595 45.81, 15.93 x 45.83, 16.08
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc77db4} }, // 12 OSM: 5707171 WD: Q116918230 45.8, 15.94 x 45.82, 16.04
    { 67, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xa58e9b} }, // 13 OSM: 5707277 WD: Q116921343 45.8, 15.96 x 45.82, 16.03
    { 153, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf8abad} }, // 14 OSM: 5707492 WD: Q116940834 45.78, 15.95 x 45.84, 16
    { 157, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xee1d23} }, // 15 OSM: 5707544 WD: Q17440801 45.84, 15.97 x 45.86, 15.98
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x66cc00} }, // 2 OSM: 5711071 WD: Q56911095 36.28, 59.55 x 36.33, 59.68
    { 225, 16196, NoLogo, LineMetaDataContent::RapidTransit, Color{0x36a390} }, // S3 OSM: 5721287 WD: Q110713935 41.35, 2.005 x 41.4, 2.148
    { 314, 16213, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa25e23} }, // S4 OSM: 5721688 WD: Q110714007 41.35, 1.888 x 41.54, 2.148
    { 2237, 16230, NoLogo, LineMetaDataContent::RapidTransit, Color{0xb8b6b7} }, // R6 OSM: 5724702 WD: Q110714580 41.35, 1.63 x 41.58, 2.148
    { 2240, 16247, NoLogo, LineMetaDataContent::RapidTransit, Color{0x707072} }, // R60 OSM: 5724705 WD: Q120985663 41.35, 1.63 x 41.58, 2.148
    { 2244, 16265, NoLogo, LineMetaDataContent::RapidTransit, Color{0x38b0b1} }, // R5 OSM: 5724850 WD: Q110714601 41.35, 1.828 x 41.73, 2.148
    { 2247, 16282, NoLogo, LineMetaDataContent::RapidTransit, Color{0x3592a3} }, // R50 OSM: 5724851 WD: Q120986306 41.35, 1.828 x 41.73, 2.148
    { 239, NoLogo, 976, LineMetaDataContent::Tramway, Color{0x6dcff6} }, // 17 OSM: 5740169 WD: Q63442567 50.86, 6.957 x 50.93, 7.004
    { 26, NoLogo, 976, LineMetaDataContent::Tramway, Color{0x21bfc1} }, // 16 OSM: 5742444 WD: Q20035833 50.68, 6.943 x 50.99, 7.159
    { 9, NoLogo, 976, LineMetaDataContent::Tramway, Color{0xe06e9f} }, // 4 OSM: 5742445 WD: Q63442527 50.93, 6.873 x 51.02, 7.044
    { 239, 16300, NoLogo, LineMetaDataContent::Tramway, Color{0x166187} }, // 17 OSM: 5742856 WD: Q120645681 52.37, 16.88 x 52.41, 16.98
    { 67, 16339, NoLogo, LineMetaDataContent::Tramway, Color{0xb18506} }, // 13 OSM: 5744834 WD: Q108000662 52.37, 16.83 x 52.41, 16.95
    { 157, 16378, NoLogo, LineMetaDataContent::Tramway, Color{0xadb4bb} }, // 15 OSM: 5745673 WD: Q110074597 52.38, 16.83 x 52.46, 16.92
    { 2251, NoLogo, 976, LineMetaDataContent::Subway, Color{0x59c6f2} }, // U71 OSM: 5747258 WD: Q87660333 51.19, 6.763 x 51.26, 6.82
    { 2255, NoLogo, 976, LineMetaDataContent::Subway, Color{0x1d3a8f} }, // U83 OSM: 5748738 WD: Q121295976 51.19, 6.763 x 51.25, 6.855
    { 75, 16417, NoLogo, LineMetaDataContent::Tramway, Color{0xf2b023} }, // 10 OSM: 5752352 WD: Q108006469 52.37, 16.9 x 52.46, 16.95
    { 2259, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xd2a1f3} }, // T49 OSM: 5755247 WD: Q121818693 50.34, 18.87 x 50.4, 18.92
    { 2263, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xdf1278} }, // T23 OSM: 5755248 WD: Q115219679 50.26, 18.97 x 50.29, 19.07
    { 2267, NoLogo, 976, LineMetaDataContent::Subway, Color{0x4465ad} }, // U73 OSM: 5756097 WD: Q121295967 51.19, 6.775 x 51.24, 6.867
    { 164, NoLogo, 976, LineMetaDataContent::Subway, Color{0x25b8c5} }, // U72 OSM: 5756147 WD: Q121295966 51.16, 6.775 x 51.3, 6.886
    { 2271, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc0087f} }, // 705 OSM: 5757151 WD: Q121297872 51.2, 6.774 x 51.28, 6.787
    { 2275, 16456, NoLogo, LineMetaDataContent::RapidTransit, Color{0x006434} }, // R2Sud OSM: 5758580 WD: Q114215437 41.19, 1.523 x 41.4, 2.194
    { 2281, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff6600} }, // HVL OSM: 5793083 WD: Q5950953 -41.28, 174.8 x -41.13, 175.1
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xa4107f} }, // 4 OSM: 5804724 WD: Q3476269 51.91, 4.453 x 51.96, 4.504
    { 520, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x800080} }, // L1 OSM: 5812905 WD: Q95982832 38.09, 13.37 x 38.11, 13.41
    { 524, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffa500} }, // L2 OSM: 5812931 WD: Q95983858 38.13, 13.29 x 38.13, 13.34
    { 516, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // L4 OSM: 5813038 WD: Q95983909 38.1, 13.33 x 38.13, 13.34
    { 528, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // L3 OSM: 5813039 WD: Q95983869 38.13, 13.3 x 38.14, 13.34
    { 75, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x4b371b} }, // 10 OSM: 5821632 WD: Q117011248 54.35, 18.57 x 54.4, 18.67
    { 2285, NoLogo, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 47B OSM: 5830635 WD: Q22696462 47.44, 18.98 x 47.5, 19.06
    { 2289, 16474, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00a85a} }, // R2 OSM: 5838299 WD: Q1880046 41.28, 1.978 x 41.6, 2.292
    { 2292, 16491, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff131a} }, // R3 OSM: 5844031 WD: Q2113761 41.36, 1.896 x 42.46, 2.297
    { 2295, 16508, 976, LineMetaDataContent::Tramway, Color{0xffbacd} }, // U49 OSM: 5847183 WD: Q121288291 51.48, 7.442 x 51.52, 7.476
    { 2299, 16522, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff8c00} }, // R4 OSM: 5849061 WD: Q2226508 41.19, 1.524 x 41.72, 2.189
    { 2302, 16539, NoLogo, LineMetaDataContent::RapidTransit, Color{0x9b1987} }, // R8 OSM: 5866129 WD: Q3817638 41.45, 1.926 x 41.6, 2.292
    { 2305, 16556, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00bdac} }, // RT1 OSM: 5866193 WD: Q5985874 41.11, 1.098 x 41.16, 1.255
    { 2309, 16574, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe579cb} }, // RT2 OSM: 5867875 WD: Q9025898 41, 0.9109 x 41.27, 1.6
    { 2313, 16592, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0073ce} }, // RG1 OSM: 5867923 WD: Q5985872 41.36, 2.099 x 42.42, 3.161
    { 2317, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0060a9} }, // Expo Line OSM: 5881298 WD: Q736619 49.18, -123.1 x 49.29, -122.8
    { 2327, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xffd520} }, // Millennium Line OSM: 5881419 WD: Q1534900 49.25, -123.1 x 49.29, -122.8
    { 2343, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x009ac8} }, // Canada Line OSM: 5881439 WD: Q1031997 49.17, -123.2 x 49.29, -123.1
    { 2355, 16607, 976, LineMetaDataContent::Tramway, Color{0xfbba00} }, // U42 OSM: 5890483 WD: Q121288273 51.47, 7.433 x 51.56, 7.547
    { 2359, 16621, 976, LineMetaDataContent::Tramway, Color{0xdc2a1b} }, // U45 OSM: 5892934 WD: Q107740406 51.49, 7.455 x 51.54, 7.475
    { 2363, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xb30437} }, // R16 OSM: 5917493 40.6, 0.4494 x 41.4, 2.194
    { 2367, 16635, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffdd00} }, // R12 OSM: 5927786 WD: Q9026146 41.36, 0.6331 x 41.75, 2.189
    { 548, 16665, NoLogo, LineMetaDataContent::Tramway, Color{0x1e9999} }, // E OSM: 5953002 WD: Q5324790 37.78, -122.4 x 37.81, -122.4
    { 426, 16688, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf4858d} }, // 614P OSM: 5955260 WD: Q62127915 22.37, 114 x 22.41, 114
    { 2371, 16704, NoLogo, LineMetaDataContent::RapidTransit, Color{0x006684} }, // 615P OSM: 5955261 WD: Q62127917 22.37, 114 x 22.41, 114
    { 712, 16720, 16758, LineMetaDataContent::Subway, Color{0x00aa50} }, // A OSM: 5955845 WD: Q2310450 51.9, 4.314 x 51.96, 4.566
    { 279, 16783, 16758, LineMetaDataContent::Subway, Color{0xffd301} }, // B OSM: 5955846 WD: Q2960661 51.9, 4.105 x 51.99, 4.587
    { 411, 16821, 16758, LineMetaDataContent::Subway, Color{0xef1f1f} }, // C OSM: 5955847 WD: Q2058778 51.83, 4.319 x 51.94, 4.601
    { 283, 16859, 16758, LineMetaDataContent::Subway, Color{0x1bc5e9} }, // D OSM: 5955848 WD: Q2034685 51.83, 4.319 x 51.92, 4.497
    { 548, 16897, 16935, LineMetaDataContent::Subway, Color{0x1a389a} }, // E OSM: 5955849 WD: Q2687418 51.87, 4.325 x 52.08, 4.497
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x90130c} }, // 2 OSM: 5955850 WD: Q1982139 51.88, 4.464 x 51.9, 4.554
    { 47, 16957, NoLogo, LineMetaDataContent::Subway, Color{0x97d700} }, // 7 OSM: 5971692 WD: Q6553152 22.93, 113.2 x 23.2, 113.5
    { 2376, 15396, 15216, LineMetaDataContent::Subway, Color{0xf6842a} }, // L9 Sud OSM: 5972747 WD: Q1577033 41.29, 2.055 x 41.38, 2.134
    { 2383, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // NL1 OSM: 5976635 48.98, 8.362 x 49.05, 8.479
    { 667, 16977, NoLogo, LineMetaDataContent::RapidTransit, Color{0x009ad5} }, // C-1 OSM: 6016052 WD: Q5987195 38.97, -0.4197 x 39.47, -0.1622
    { 2387, 16996, NoLogo, LineMetaDataContent::LocalTrain, Color{0x002369} }, // R11 OSM: 6021945 WD: Q11050690 41.38, 2.139 x 42.43, 3.161
    { 330, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xad390e} }, // 25 OSM: 6023038 WD: Q106766870 52.21, 20.98 x 52.3, 21.05
    { 2391, 17026, NoLogo, LineMetaDataContent::RapidTransit, Color{0xed3896} }, // R13 OSM: 6025765 WD: Q6018166 41.18, 0.6331 x 41.62, 2.194
    { 2395, 17056, NoLogo, LineMetaDataContent::RapidTransit, Color{0x4e53ab} }, // R14 OSM: 6028425 WD: Q2880157 41.11, 0.6331 x 41.62, 2.194
    { 2399, 17086, NoLogo, LineMetaDataContent::RapidTransit, Color{0x9a836c} }, // R15 OSM: 6028724 WD: Q5845244 41.09, 0.4797 x 41.4, 2.194
    { 2403, 17116, NoLogo, LineMetaDataContent::LocalTrain, Color{0x009641} }, // RE6 OSM: 6059535 WD: Q63438537 53.55, 8.31 x 54.91, 9.936
    { 239, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x4d3d00} }, // 17 OSM: 6061801 48.99, 8.347 x 49.05, 8.452
    { 22, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00805a} }, // 18 OSM: 6061803 49, 8.431 x 49.05, 8.479
    { 548, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // E OSM: 6062533 48.95, 8.283 x 49.11, 8.505
    { 283, 17132, 17159, LineMetaDataContent::RapidTransit, Color{0xf9c212} }, // D OSM: 6063097 WD: Q10318679 41.1, -8.611 x 41.18, -8.586
    { 548, 17180, 17159, LineMetaDataContent::RapidTransit, Color{0x937bb8} }, // E OSM: 6063237 WD: Q10318682 41.15, -8.67 x 41.24, -8.582
    { 337, 17207, 17159, LineMetaDataContent::RapidTransit, Color{0xf68b1f} }, // F OSM: 6064751 WD: Q10318684 41.15, -8.694 x 41.19, -8.542
    { 712, 17234, 17159, LineMetaDataContent::RapidTransit, Color{0x3caeef} }, // A OSM: 6064925 WD: Q18473912 41.15, -8.694 x 41.19, -8.582
    { 411, 17261, 17159, LineMetaDataContent::RapidTransit, Color{0x8bc63e} }, // C OSM: 6065645 WD: Q10318673 41.15, -8.656 x 41.27, -8.586
    { 414, 17288, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffcc00} }, // S OSM: 6071918 WD: Q7395342 37.74, -122.5 x 37.79, -122.4
    { 200, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00a076} }, // 704 OSM: 6073252 WD: Q5602824 40.69, -112 x 40.78, -111.9
    { 217, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0055a4} }, // 701 OSM: 6073253 WD: Q4929373 40.53, -111.9 x 40.77, -111.9
    { 64, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0fa14a} }, // 1 OSM: 6077697 WD: Q107024373 41.14, -8.668 x 41.15, -8.616
    { 161, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0971b7} }, // 19 OSM: 6080693 WD: Q120720216 50.01, 19.93 x 50.09, 19.96
    { 64, 17307, NoLogo, LineMetaDataContent::Subway, Color{0x000080} }, // 1 OSM: 6087653 WD: Q10318642 -19.95, -44.03 x -19.82, -43.91
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xea5297} }, // 4 OSM: 6092716 WD: Q121310605 47.99, 7.829 x 48.04, 7.863
    { 2407, 17324, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // Sul OSM: 6113028 WD: Q10318728 -3.895, -38.63 x -3.72, -38.53
    { 321, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0xf36421} }, // S 1 OSM: 6116272 WD: Q56378877 50.88, 13.46 x 51.16, 14.24
    { 1691, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0xb8282e} }, // S 2 OSM: 6116280 WD: Q56378880 50.96, 13.72 x 51.13, 13.93
    { 1619, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0xed0172} }, // S 3 OSM: 6116305 WD: Q56378881 50.9, 13.34 x 51.04, 13.73
    { 314, 17362, 10793, LineMetaDataContent::RapidTransit, Color{0x159dd9} }, // S4 OSM: 6157906 WD: Q96484000 47.81, 15.98 x 48.4, 16.41
    { 279, 17374, 17159, LineMetaDataContent::RapidTransit, Color{0xe62621} }, // B OSM: 6161229 WD: Q10318669 41.15, -8.758 x 41.38, -8.582
    { 64, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc01115} }, // 1 OSM: 6182760 WD: Q2085324 51.98, 4.277 x 52.12, 4.359
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x006600} }, // 2 OSM: 6182761 WD: Q3926989 52.05, 4.236 x 52.09, 4.383
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0093de} }, // 6 OSM: 6182762 WD: Q2205103 52.06, 4.264 x 52.1, 4.4
    { 63, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xcd853f} }, // 11 OSM: 6192619 WD: Q2084217 52.06, 4.27 x 52.11, 4.324
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff66ff} }, // 12 OSM: 6192620 WD: Q2541548 52.06, 4.252 x 52.09, 4.324
    { 146, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xa6c116} }, // 9 OSM: 6192621 WD: Q2293268 52.03, 4.257 x 52.12, 4.324
    { 157, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe63a6b} }, // 15 OSM: 6197181 WD: Q2202159 52.04, 4.31 x 52.08, 4.393
    { 26, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfa7222} }, // 16 OSM: 6197182 WD: Q2746551 52.02, 4.274 x 52.08, 4.327
    { 239, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x006b8b} }, // 17 OSM: 6197183 WD: Q2417431 52.02, 4.272 x 52.1, 4.339
    { 161, NoLogo, 16935, LineMetaDataContent::Tramway, Color{0xc01115} }, // 19 OSM: 6197184 WD: Q2886326 52.01, 4.35 x 52.09, 4.406
    { 2411, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff9c2a} }, // N2 OSM: 6227258 47.47, 19.05 x 47.51, 19.08
    { 1054, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff9c2a} }, // N19 OSM: 6227261 47.48, 19.04 x 47.53, 19.06
    { 2414, NoLogo, 17401, LineMetaDataContent::RapidTransit, Color{0x0275a4} }, // BLUE OSM: 6265609 WD: Q4929367 32.65, -96.81 x 32.92, -96.56
    { 281, NoLogo, 17401, LineMetaDataContent::RapidTransit, Color{0xcc0000} }, // RED OSM: 6265610 WD: Q16984038 32.72, -96.87 x 33.03, -96.7
    { 2419, NoLogo, 17401, LineMetaDataContent::RapidTransit, Color{0x00873f} }, // GREEN OSM: 6265672 WD: Q5602816 32.72, -96.94 x 32.99, -96.68
    { 2425, NoLogo, 17401, LineMetaDataContent::RapidTransit, Color{0xcc6600} }, // ORANGE OSM: 6265702 WD: Q7099665 32.78, -97.04 x 33.03, -96.7
    { 2432, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000066} }, // 620 OSM: 6265792 WD: Q112867830 32.75, -96.82 x 32.78, -96.81
    { 75, 17436, 17457, LineMetaDataContent::Subway, Color{0x0000ff} }, // 10 OSM: 6286483 WD: Q3239219 59.33, 17.88 x 59.4, 18.07
    { 63, 17436, 17457, LineMetaDataContent::Subway, Color{0x0000ff} }, // 11 OSM: 6286484 WD: Q3239220 59.33, 17.91 x 59.42, 18.07
    { 239, 17484, 17457, LineMetaDataContent::Subway, Color{0x008000} }, // 17 OSM: 6286485 WD: Q3239225 59.27, 17.83 x 59.37, 18.13
    { 22, 17484, 17457, LineMetaDataContent::Subway, Color{0x008000} }, // 18 OSM: 6286486 WD: Q3239226 59.23, 17.83 x 59.37, 18.1
    { 161, 17484, 17457, LineMetaDataContent::Subway, Color{0x008000} }, // 19 OSM: 6286487 WD: Q3239227 59.26, 17.83 x 59.37, 18.08
    { 67, 17507, 17457, LineMetaDataContent::Subway, Color{0xff0000} }, // 13 OSM: 6286488 WD: Q3239222 59.24, 17.81 x 59.36, 18.1
    { 153, 17507, 17457, LineMetaDataContent::Subway, Color{0xff0000} }, // 14 OSM: 6286489 WD: Q3239223 59.29, 17.96 x 59.4, 18.08
    { 64, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe51919} }, // 1 OSM: 6336724 47.1, 37.54 x 47.15, 37.62
    { 2468, 17529, 17555, LineMetaDataContent::Subway, Color{0x0a9cda} }, // Victoria OSM: 6354922 WD: Q203030 51.46, -0.1441 x 51.59, -0.01927
    { 2477, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00abe5} }, // GN5 OSM: 6367814 51.52, -0.2222 x 51.8, -0.08648
    { 1132, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 14А OSM: 6389258 WD: Q123353093 53.43, 58.96 x 53.45, 59.08
    { 2481, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x3a75c4} }, // North Clyde OSM: 6399061 55.85, -4.733 x 56, -3.19
    { 2493, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x2e8b57} }, // North Berwick OSM: 6399368 55.93, -3.187 x 56.06, -2.513
    { 2507, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xcc5500} }, // Maryhill OSM: 6403662 55.86, -4.321 x 55.9, -4.239
    { 2516, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x629f3f} }, // Santa Cruz OSM: 6432131 WD: Q10318722 -22.92, -43.69 x -22.85, -43.19
    { 2527, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0691f6} }, // Japeri OSM: 6432248 WD: Q10318695 -22.91, -43.66 x -22.64, -43.19
    { 9, 17571, NoLogo, LineMetaDataContent::Subway, Color{0xffcc29} }, // 4 OSM: 6432702 WD: Q6553130 -23.01, -43.31 x -22.98, -43.2
    { 1806, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x00ab4e} }, // KTL OSM: 6452936 WD: Q736412 22.29, 114.2 x 22.34, 114.3
    { 2534, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xee4b95} }, // TL8 OSM: 6464333 WD: Q125903427 51.28, -0.2222 x 51.8, 0.2044
    { 2538, 17595, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe6180a} }, // 505 OSM: 6481283 WD: Q13645607 22.38, 114 x 22.41, 114
    { 2542, 17610, NoLogo, LineMetaDataContent::RapidTransit, Color{0x1a8539} }, // 507 OSM: 6481317 WD: Q15917019 22.37, 114 x 22.41, 114
    { 2546, 17625, NoLogo, LineMetaDataContent::RapidTransit, Color{0x8d3219} }, // 610 OSM: 6481421 WD: Q15908713 22.37, 114 x 22.45, 114
    { 2550, 17640, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf4e619} }, // 615 OSM: 6481435 WD: Q62127916 22.37, 114 x 22.45, 114
    { 2554, 17655, NoLogo, LineMetaDataContent::RapidTransit, Color{0x44adc3} }, // 614 OSM: 6485195 WD: Q62127914 22.37, 114 x 22.45, 114
    { 2558, 17670, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf58c14} }, // 751 OSM: 6485220 WD: Q62127921 22.39, 114 x 22.47, 114
    { 2562, 17685, NoLogo, LineMetaDataContent::RapidTransit, Color{0x70147b} }, // 761P OSM: 6485222 WD: Q15909914 22.44, 114 x 22.47, 114
    { 2567, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf7931d} }, // SN 5 OSM: 6489645 51.07, -0.3187 x 51.5, 0.2699
    { 235, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 27 OSM: 6490955 WD: Q123353107 53.35, 58.96 x 53.48, 59.06
    { 2572, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009933} }, // T-A OSM: 6491413 6.233, -75.57 x 6.248, -75.54
    { 289, NoLogo, 17701, LineMetaDataContent::Tramway, Color{0xed1c24} }, // T1 OSM: 6497386 WD: Q110618690 43.28, 5.547 x 43.3, 5.566
    { 2576, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x6633ff} }, // T1 R OSM: 6545828 WD: Q118592004 36.72, 3.083 x 36.78, 3.263
    { 2581, 17717, NoLogo, LineMetaDataContent::Tramway, Color{0xff00ff} }, // 18E OSM: 6547489 WD: Q63230200 38.7, -9.203 x 38.71, -9.145
    { 221, 17730, NoLogo, LineMetaDataContent::RapidTransit, Color{0xba85bb} }, // 706 OSM: 6558996 WD: Q62127919 22.45, 114 x 22.47, 114
    { 2271, 17745, NoLogo, LineMetaDataContent::RapidTransit, Color{0x8cc022} }, // 705 OSM: 6558997 WD: Q62127918 22.45, 114 x 22.47, 114
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe41f25} }, // 4 OSM: 6576221 WD: Q121368141 48.22, 14.23 x 48.31, 14.29
    { 153, 17760, 5450, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // 14 OSM: 6576716 WD: Q26856861 55.69, 37.49 x 55.85, 37.75
    { 548, 17785, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf7b618} }, // E OSM: 6584634 WD: Q4993859 34.01, -118.5 x 34.05, -118.2
    { 712, 17810, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0072bc} }, // A OSM: 6585129 WD: Q3267759 33.77, -118.3 x 34.15, -117.9
    { 2585, 17835, NoLogo, LineMetaDataContent::LocalTrain, Color{0x009bd5} }, // RB22 OSM: 6593456 WD: Q68006335 52.3, 12.97 x 52.41, 13.64
    { 2590, 17855, NoLogo, LineMetaDataContent::Tramway, Color{0xff7f00} }, // 25E OSM: 6595981 WD: Q63230206 38.71, -9.17 x 38.72, -9.135
    { 1273, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 31 OSM: 6617507 WD: Q123353112 53.38, 58.97 x 53.44, 59.1
    { 26, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 16 OSM: 6627041 WD: Q123353097 53.36, 58.96 x 53.41, 59.1
    { 98, 17868, NoLogo, LineMetaDataContent::LocalTrain, Color{} }, // 68 OSM: 6641022 WD: Q9025977 36.83, -3.668 x 37.42, -2.43
    { 2594, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // C13 OSM: 6641930 WD: Q104192645 50.59, 12.69 x 50.92, 12.98
    { 1093, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 29 OSM: 6653146 55.81, 37.52 x 55.84, 37.58
    { 1784, 17894, 13843, LineMetaDataContent::Subway, Color{0x00893e} }, // b OSM: 6659014 WD: Q24641690 48.09, -1.707 x 48.13, -1.62
    { 64, 17924, 17953, LineMetaDataContent::Tramway, Color{0x0000ff} }, // 1 OSM: 6667548 WD: Q30926891 -22.91, -43.21 x -22.89, -43.17
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xec7e2b} }, // 6 OSM: 6674002 WD: Q124656081 49.74, 8.613 x 49.92, 8.658
    { 725, NoLogo, 5107, LineMetaDataContent::Tramway, Color{0x008000} }, // T2 OSM: 6679929 WD: Q107172304 42.84, -2.685 x 42.88, -2.664
    { 47, 17974, NoLogo, LineMetaDataContent::Tramway, Color{0x174ca1} }, // 7 OSM: 6679981 WD: Q117302440 52.38, 16.88 x 52.44, 16.96
    { 22, 18012, NoLogo, LineMetaDataContent::Tramway, Color{0xfdd100} }, // 18 OSM: 6680332 WD: Q108000680 52.38, 16.88 x 52.42, 17
    { 2598, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffa500} }, // MSC OSM: 6686325 14.2, 121 x 14.62, 121.2
    { 498, 18051, 15216, LineMetaDataContent::Subway, Color{0xb2aed3} }, // L12 OSM: 6699916 WD: Q20107064 41.4, 2.119 x 41.4, 2.126
    { 153, 18069, NoLogo, LineMetaDataContent::Subway, Color{0x81312f} }, // 14 OSM: 6728233 WD: Q6553073 23.24, 113.3 x 23.57, 113.6
    { 2602, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x6c421b} }, // S14 OSM: 6731045 WD: Q7388188 47.27, 8.429 x 47.41, 8.841
    { 71, 18090, 9964, LineMetaDataContent::RapidTransit, Color{0xe74a4a} }, // S1 OSM: 6747873 WD: Q108084414 52.11, 20.8 x 52.26, 21.26
    { 2606, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x9a9b9f} }, // Тр8 OSM: 6749431 WD: Q124735426 49.78, 24.03 x 49.84, 24.06
    { 64, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x791714} }, // 1 OSM: 6774704 WD: Q10318644 -12.99, -38.52 x -12.89, -38.44
    { 2014, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x646363} }, // 53 OSM: 6783604 WD: Q84991746 49.96, 8.197 x 50, 8.275
    { 2612, 18101, 18124, LineMetaDataContent::Tramway, Color{0x83b81a} }, // Τ6 OSM: 6792080 WD: Q25535312 37.92, 23.7 x 37.97, 23.74
    { 2616, 18164, 18124, LineMetaDataContent::Tramway, Color{0x83b81a} }, // Τ7 OSM: 6792082 WD: Q25535308 37.85, 23.64 x 37.95, 23.75
    { 68, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x552200} }, // 3 OSM: 6792594 WD: Q121691515 54.16, 19.39 x 54.19, 19.43
    { 2620, 18187, 9742, LineMetaDataContent::RapidTransit, Color{0x202776} }, // S43 OSM: 6794665 WD: Q86674587 50.62, 5.567 x 50.85, 5.718
    { 46, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfff90a} }, // S7 OSM: 6796259 48.63, 8.065 x 49.01, 8.433
    { 309, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfff90a} }, // S71 OSM: 6796260 48.63, 8.065 x 48.99, 8.405
    { 2624, 18209, NoLogo, LineMetaDataContent::RapidTransit, Color{0x6d682a} }, // S81 OSM: 6796368 WD: Q106362968 48.44, 8.215 x 48.99, 8.83
    { 47, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffa500} }, // 7 OSM: 6799066 39.75, 30.49 x 39.76, 30.54
    { 64, 18226, NoLogo, LineMetaDataContent::Subway, Color{0xe4002b} }, // 1 OSM: 6800211 WD: Q1326478 31.11, 121.4 x 31.4, 121.5
    { 1393, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00bfff} }, // T4 OSM: 6800375 39.75, 30.49 x 39.78, 30.56
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffff00} }, // 6 OSM: 6800648 39.71, 30.49 x 39.78, 30.62
    { 2628, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffff00} }, // T10 OSM: 6800876 39.74, 30.52 x 39.8, 30.6
    { 26, 18246, NoLogo, LineMetaDataContent::Subway, Color{0x2cd5c4} }, // 16 OSM: 6803864 WD: Q5954911 30.91, 121.6 x 31.2, 121.9
    { 6, 18267, NoLogo, LineMetaDataContent::Subway, Color{0xac4fc6} }, // 5 OSM: 6806165 WD: Q1331322 30.91, 121.4 x 31.12, 121.5
    { 68, 18287, NoLogo, LineMetaDataContent::Subway, Color{0xffd100} }, // 3 OSM: 6817204 WD: Q1326495 31.15, 121.4 x 31.41, 121.5
    { 68, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf0e68c} }, // 3 OSM: 6820173 WD: Q121537239 53.85, 27.54 x 53.93, 27.63
    { 2632, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xb6bd00} }, // SIL OSM: 6827213 WD: Q2041013 22.24, 114.1 x 22.28, 114.2
    { 146, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x13a962} }, // 9 OSM: 6831389 WD: Q123363019 56.75, 60.57 x 56.8, 60.63
    { 27, 18307, NoLogo, LineMetaDataContent::Subway, Color{0xd9017a} }, // 6 OSM: 6840940 WD: Q631135 31.15, 121.5 x 31.36, 121.6
    { 2636, 18327, NoLogo, LineMetaDataContent::RapidTransit, Color{0x692832} }, // TL-1 OSM: 6849311 WD: Q5985920 20.61, -103.4 x 20.74, -103.4
    { 760, 18393, NoLogo, LineMetaDataContent::LocalTrain, Color{0xef7d00} }, // RE7 OSM: 6851149 WD: Q1753399 53.55, 9.374 x 54.78, 10.14
    { 2641, 18409, NoLogo, LineMetaDataContent::RapidTransit, Color{0x407058} }, // TL-2 OSM: 6851904 WD: Q5986178 20.66, -103.4 x 20.68, -103.3
    { 2646, 18475, 5450, LineMetaDataContent::Subway, Color{0xffff00} }, // 8А OSM: 6855054 WD: Q1978532 55.61, 37.28 x 55.75, 37.54
    { 524, 18500, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe36523} }, // L2 OSM: 6857222 WD: Q5986175 -37.02, -73.16 x -36.82, -73.06
    { 520, 18558, NoLogo, LineMetaDataContent::RapidTransit, Color{0xdd3018} }, // L1 OSM: 6857223 WD: Q5985914 -36.98, -73.12 x -36.71, -72.94
    { 22, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc92223} }, // 18 OSM: 6893258 WD: Q123363029 56.81, 60.54 x 56.86, 60.67
    { 251, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xa2d9f7} }, // 20 OSM: 6895239 WD: Q123363032 56.82, 60.61 x 56.87, 60.67
    { 334, 18626, 3863, LineMetaDataContent::RapidTransit, Color{0xc6cc00} }, // J OSM: 6904183 WD: Q93388 48.88, 1.478 x 49.29, 2.326
    { 2650, 18660, 6136, LineMetaDataContent::Tramway, Color{0xf68c59} }, // T3a OSM: 6907402 WD: Q2420695 48.82, 2.27 x 48.85, 2.411
    { 1393, 18694, 6136, LineMetaDataContent::Tramway, Color{0xf2af00} }, // T4 OSM: 6910344 WD: Q1826681 48.89, 2.476 x 48.93, 2.571
    { 1396, 18727, 6136, LineMetaDataContent::Tramway, Color{0xb156a1} }, // T5 OSM: 6910410 WD: Q3238968 48.94, 2.356 x 48.98, 2.391
    { 1627, 18760, 6136, LineMetaDataContent::Tramway, Color{0xe85426} }, // T6 OSM: 6910437 WD: Q3238993 48.78, 2.169 x 48.81, 2.301
    { 1760, 18793, 6136, LineMetaDataContent::Tramway, Color{0xb98b59} }, // T7 OSM: 6910465 WD: Q3239019 48.71, 2.352 x 48.79, 2.373
    { 157, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf8c800} }, // 15 OSM: 6914129 WD: Q29258503 50.07, 14.36 x 50.1, 14.47
    { 2654, 18826, NoLogo, LineMetaDataContent::LocalTrain, Color{0x66aa22} }, // RB10 OSM: 6924342 WD: Q15195695 52.47, 12.88 x 52.61, 13.38
    { 2115, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x5cda21} }, // RS30 OSM: 6925925 53.05, 8.002 x 53.18, 8.815
    { 313, 18846, 226, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // RS4 OSM: 6925927 WD: Q84703708 53.05, 8.452 x 53.49, 8.815
    { 2659, 18861, 18861, LineMetaDataContent::Subway, Color{0xffcf00} }, // Orlyval OSM: 6928902 WD: Q432593 48.73, 2.3 x 48.76, 2.37
    { 2667, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x142b4a} }, // CDGVAL OSM: 6928933 WD: Q1023114 49, 2.542 x 49.01, 2.572
    { 225, NoLogo, 9964, LineMetaDataContent::RapidTransit, Color{0xffae00} }, // S3 OSM: 6931734 WD: Q124516332 52.17, 20.94 x 52.44, 21.18
    { 2403, 18884, NoLogo, LineMetaDataContent::LocalTrain, Color{0xe64dff} }, // RE6 OSM: 6933203 WD: Q63224485 52.5, 11.76 x 53.16, 13.3
    { 712, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x800080} }, // A OSM: 6937084 WD: Q4268353 24.96, 121.2 x 25.09, 121.5
    { 758, 18903, 4274, LineMetaDataContent::Subway, Color{0xfccc0a} }, // W OSM: 6942556 WD: Q126567 40.7, -74.01 x 40.78, -73.91
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xd79c58} }, // 12 OSM: 6945653 WD: Q123363022 56.82, 60.58 x 56.86, 60.69
    { 157, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xd5d6ec} }, // 15 OSM: 6966205 WD: Q123363025 56.77, 60.58 x 56.84, 60.69
    { 2674, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008531} }, // Luas Green Line OSM: 6975500 WD: Q2086105 53.24, -6.298 x 53.37, -6.143
    { 2690, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x68c56b} }, // DART OSM: 6979159 WD: Q125147653 53.14, -6.255 x 53.45, -6.06
    { 64, 18929, 9336, LineMetaDataContent::Tramway, Color{0xc00027} }, // 1 OSM: 6981890 WD: Q2211906 47.74, 7.321 x 47.78, 7.343
    { 6, 18954, 18975, LineMetaDataContent::Subway, Color{0xf6a90b} }, // 5 OSM: 6996917 WD: Q957143 50.81, 4.266 x 50.86, 4.432
    { 16, 18999, 9336, LineMetaDataContent::Tramway, Color{0xffd80e} }, // 2 OSM: 7006051 WD: Q2024859 47.73, 7.297 x 47.76, 7.352
    { 64, 19024, 18975, LineMetaDataContent::Subway, Color{0xb5378c} }, // 1 OSM: 7006076 WD: Q1345228 50.84, 4.319 x 50.86, 4.464
    { 68, 19045, 9336, LineMetaDataContent::Tramway, Color{0x00a651} }, // 3 OSM: 7006942 WD: Q3238912 47.74, 7.275 x 47.76, 7.344
    { 16, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x142b4a} }, // 2 OSM: 7011253 WD: Q52773923 49, 2.578 x 49, 2.591
    { 1499, 19070, NoLogo, LineMetaDataContent::LocalTrain, Color{0xff0000} }, // RE1 OSM: 7024716 WD: Q15119401 52.13, 11.63 x 52.53, 14.66
    { 16, 19089, 17953, LineMetaDataContent::Tramway, Color{0x008000} }, // 2 OSM: 7064054 WD: Q30926895 -22.91, -43.21 x -22.9, -43.17
    { 1256, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 36 OSM: 7080875 WD: Q122585362 55.75, 37.71 x 55.83, 37.82
    { 59, 19118, 226, LineMetaDataContent::RapidTransit, Color{0x6cc247} }, // S2 OSM: 7091572 WD: Q7388247 48.13, 11.25 x 48.41, 11.91
    { 2695, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe63323} }, // MTN OSM: 7106220 WD: Q24960835 -33.63, -70.71 x -33.45, -70.68
    { 520, 19134, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // L1 OSM: 7106760 WD: Q3011576 43.24, -3.013 x 43.4, -2.897
    { 314, 19157, 226, LineMetaDataContent::RapidTransit, Color{0xed1c24} }, // S4 OSM: 7113761 WD: Q116210481 46.55, 13.37 x 46.63, 13.85
    { 59, 19173, 226, LineMetaDataContent::RapidTransit, Color{0x3c8475} }, // S2 OSM: 7113763 WD: Q116210398 46.62, 13.85 x 46.77, 14.37
    { 71, 19189, 226, LineMetaDataContent::RapidTransit, Color{0x17489e} }, // S1 OSM: 7113764 WD: Q116209766 46.6, 12.77 x 46.95, 14.48
    { 47, 19205, 8524, LineMetaDataContent::Tramway, Color{0xefe048} }, // 7 OSM: 7135778 WD: Q3239018 50.81, 4.336 x 50.9, 4.408
    { 528, 19226, NoLogo, LineMetaDataContent::Subway, Color{0xe3007d} }, // L3 OSM: 7141757 WD: Q2992379 43.25, -2.926 x 43.27, -2.889
    { 1045, 19249, 8524, LineMetaDataContent::Tramway, Color{0xe43c2e} }, // 92 OSM: 7152034 WD: Q2661521 50.79, 4.34 x 50.88, 4.381
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x37b355} }, // 2 OSM: 7157243 WD: Q60031554 48.38, 9.936 x 48.43, 9.987
    { 64, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xed1b24} }, // 1 OSM: 7157244 WD: Q60031375 48.39, 9.955 x 48.43, 10.03
    { 1415, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x2b2963} }, // E4 OSM: 7158306 43.2, -2.926 x 43.42, -2.667
    { 68, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 3 OSM: 7176448 WD: Q121133044 44.03, 43 x 44.05, 43.12
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 2 OSM: 7176450 WD: Q121133004 44.04, 42.98 x 44.06, 43.06
    { 64, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 1 OSM: 7176452 WD: Q121132934 44.03, 43.03 x 44.04, 43.11
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 8 OSM: 7181179 WD: Q121140865 44.03, 43.03 x 44.05, 43.12
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 6 OSM: 7181183 WD: Q121140561 44.04, 43 x 44.06, 43.06
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 4 OSM: 7181187 WD: Q121140903 44.03, 43.06 x 44.06, 43.12
    { 520, 19271, NoLogo, LineMetaDataContent::RapidTransit, Color{0xc00b31} }, // L1 OSM: 7183555 WD: Q29634861 37.14, -3.654 x 37.23, -3.592
    { 2699, 19295, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // C-2 OSM: 7193330 WD: Q4802702 43.25, -3.112 x 43.32, -2.928
    { 2703, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // C14 OSM: 7204222 WD: Q104192612 50.7, 12.85 x 50.99, 12.98
    { 2707, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // C15 OSM: 7211723 WD: Q104192546 50.81, 12.92 x 50.97, 13.12
    { 16, 19313, 9802, LineMetaDataContent::Subway, Color{0x0055c8} }, // 2 OSM: 7227705 WD: Q50718 48.85, 2.278 x 48.88, 2.399
    { 64, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x93c21c} }, // 1 OSM: 7252644 WD: Q60669571 -23.97, -46.41 x -23.96, -46.31
    { 2711, 19348, 17555, LineMetaDataContent::Subway, Color{0xe42313} }, // Central OSM: 7254206 WD: Q205355 51.5, -0.4377 x 51.69, 0.1146
    { 548, 19373, 2986, LineMetaDataContent::RapidTransit, Color{0xc04191} }, // E OSM: 7271953 WD: Q668655 48.74, 2.225 x 48.9, 2.759
    { 67, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf6c828} }, // 13 OSM: 7295272 WD: Q96483392 47.35, 8.481 x 47.41, 8.542
    { 16, 19405, 18975, LineMetaDataContent::Subway, Color{0xed6c23} }, // 2 OSM: 7305855 WD: Q1826676 50.83, 4.321 x 50.87, 4.37
    { 63, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xef7f1a} }, // 11 OSM: 7313918 WD: Q123363021 56.84, 60.5 x 56.84, 60.56
    { 27, 19426, NoLogo, LineMetaDataContent::Subway, Color{0x80225f} }, // 6 OSM: 7322006 WD: Q6553140 23.11, 113.2 x 23.2, 113.5
    { 153, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 14 OSM: 7339185 WD: Q122585355 55.68, 37.54 x 55.73, 37.61
    { 1500, 19446, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0063a9} }, // E1 OSM: 7353799 WD: Q43263877 43.16, -2.926 x 43.31, -1.981
    { 75, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xb0cb1f} }, // 10 OSM: 7361616 WD: Q123363020 56.82, 60.5 x 56.88, 60.64
    { 67, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x024428} }, // 13 OSM: 7363045 WD: Q123363023 56.83, 60.5 x 56.88, 60.69
    { 153, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc86a16} }, // 14 OSM: 7363436 WD: Q123363024 56.76, 60.59 x 56.9, 60.64
    { 1865, 19463, 226, LineMetaDataContent::RapidTransit, Color{0x9f4c37} }, // S41 OSM: 7369771 WD: Q12374455 52.46, 13.28 x 52.55, 13.48
    { 71, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // S1 OSM: 7370516 47.8, 7.589 x 48.06, 8.504
    { 453, 19494, 8524, LineMetaDataContent::Tramway, Color{0x4c8b33} }, // 81 OSM: 7375224 WD: Q2133516 50.82, 4.28 x 50.84, 4.408
    { 71, 19516, 9742, LineMetaDataContent::RapidTransit, Color{0x005f33} }, // S1 OSM: 7382640 WD: Q24929119 50.6, 4.32 x 51.22, 4.497
    { 59, NoLogo, 9742, LineMetaDataContent::RapidTransit, Color{0xf16122} }, // S2 OSM: 7383577 WD: Q56309162 50.61, 4.139 x 50.9, 4.716
    { 1319, NoLogo, 9742, LineMetaDataContent::RapidTransit, Color{0x009696} }, // S20 OSM: 7386794 WD: Q56309254 50.67, 4.565 x 50.88, 4.719
    { 1703, 19539, 3759, LineMetaDataContent::RapidTransit, Color{0x66ff00} }, // C4 OSM: 7387133 WD: Q5987394 43.49, -6.152 x 43.59, -5.676
    { 2719, 19568, 3759, LineMetaDataContent::RapidTransit, Color{0xffcc00} }, // C5 OSM: 7387134 WD: Q27968528 43.25, -5.728 x 43.54, -5.565
    { 52, NoLogo, 9742, LineMetaDataContent::RapidTransit, Color{0xffcc06} }, // S5 OSM: 7387151 WD: Q56309389 50.69, 3.87 x 51.02, 4.484
    { 2722, 3729, 3759, LineMetaDataContent::RapidTransit, Color{0xff6600} }, // F7 OSM: 7387168 WD: Q27976587 43.35, -6.113 x 43.55, -5.856
    { 1345, 4190, 3759, LineMetaDataContent::LocalTrain, Color{0xff0000} }, // C1 OSM: 7387234 WD: Q5987183 43.07, -5.877 x 43.54, -5.676
    { 1349, 13986, 3759, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // C3 OSM: 7387332 WD: Q5987208 43.36, -5.931 x 43.59, -5.806
    { 2725, 19295, 3759, LineMetaDataContent::RapidTransit, Color{0x008000} }, // C2 OSM: 7387377 WD: Q5987199 43.29, -5.877 x 43.37, -5.645
    { 225, NoLogo, 9742, LineMetaDataContent::RapidTransit, Color{0x222975} }, // S3 OSM: 7388964 WD: Q56309590 50.82, 3.814 x 51.02, 4.366
    { 314, NoLogo, 9742, LineMetaDataContent::RapidTransit, Color{0xcb2127} }, // S4 OSM: 7389117 WD: Q56309251 50.82, 4.039 x 51.02, 4.523
    { 298, NoLogo, 9742, LineMetaDataContent::RapidTransit, Color{0x965f26} }, // S6 OSM: 7391007 WD: Q56309855 50.69, 3.87 x 50.89, 4.378
    { 46, NoLogo, 9742, LineMetaDataContent::RapidTransit, Color{0x571759} }, // S7 OSM: 7391045 WD: Q56309167 50.73, 4.241 x 50.92, 4.434
    { 55, NoLogo, 9742, LineMetaDataContent::RapidTransit, Color{0x0096cb} }, // S8 OSM: 7391071 WD: Q56309403 50.65, 3.814 x 50.91, 4.617
    { 645, NoLogo, 9742, LineMetaDataContent::RapidTransit, Color{0x67bc45} }, // S9 OSM: 7391314 WD: Q56309779 50.6, 4.335 x 50.9, 5.08
    { 1080, 19596, 9742, LineMetaDataContent::RapidTransit, Color{0x000000} }, // S10 OSM: 7391375 WD: Q56309273 50.83, 4.039 x 51.02, 4.366
    { 355, 19609, NoLogo, LineMetaDataContent::LocalTrain, Color{0x035e33} }, // S51 OSM: 7392144 WD: Q115284858 50.74, 3.575 x 51.18, 3.758
    { 2185, 19630, 9742, LineMetaDataContent::RapidTransit, Color{0xcc2027} }, // S44 OSM: 7392745 WD: Q86669124 50.62, 5.08 x 50.75, 5.694
    { 1865, 9720, 9742, LineMetaDataContent::RapidTransit, Color{0x005d30} }, // S41 OSM: 7392801 WD: Q1374322 50.56, 5.559 x 50.66, 5.854
    { 2728, 19295, 3759, LineMetaDataContent::RapidTransit, Color{0x009739} }, // C2f OSM: 7393461 WD: Q107407546 43.31, -4.232 x 43.46, -3.811
    { 2141, 19652, 9742, LineMetaDataContent::RapidTransit, Color{0xcc2027} }, // S34 OSM: 7394087 WD: Q87251581 51.02, 3.979 x 51.22, 4.434
    { 93, 19678, NoLogo, LineMetaDataContent::RapidTransit, Color{0x005d30} }, // S61 OSM: 7394292 WD: Q84951112 50.39, 4.432 x 50.67, 4.881
    { 2732, 19704, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf26021} }, // S62 OSM: 7395296 WD: Q86070870 50.4, 4.17 x 50.51, 4.439
    { 89, 19730, NoLogo, LineMetaDataContent::RapidTransit, Color{0x1a2277} }, // S63 OSM: 7396143 WD: Q85178055 50.27, 3.967 x 50.41, 4.439
    { 2736, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x4a611c} }, // RL1 OSM: 7399137 WD: Q3781389 41.62, 0.631 x 41.79, 0.8166
    { 339, 19756, 9742, LineMetaDataContent::RapidTransit, Color{0x202776} }, // S33 OSM: 7400676 WD: Q87071069 51.14, 4.421 x 51.22, 5.115
    { 173, 19782, NoLogo, LineMetaDataContent::LocalTrain, Color{0xf26021} }, // S52 OSM: 7400734 WD: Q115285798 50.77, 3.71 x 51.04, 3.875
    { 787, 19803, NoLogo, LineMetaDataContent::RapidTransit, Color{0xcc2027} }, // S64 OSM: 7403404 WD: Q85944484 50.06, 4.387 x 50.41, 4.538
    { 330, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffff00} }, // 25 OSM: 7409703 31.2, 29.9 x 31.22, 29.93
    { 161, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x7e71b1} }, // 19 OSM: 7415625 WD: Q123363031 56.81, 60.54 x 56.89, 60.59
    { 349, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xd3db58} }, // 23 OSM: 7415926 WD: Q123363034 56.83, 60.55 x 56.89, 60.69
    { 255, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xa75f4a} }, // 24 OSM: 7417521 WD: Q123363035 56.86, 60.5 x 56.9, 60.64
    { 64, 19829, NoLogo, LineMetaDataContent::Tramway, Color{0xf38230} }, // 1 OSM: 7418079 WD: Q59134535 33.53, -7.67 x 33.6, -7.5
    { 16, 19846, NoLogo, LineMetaDataContent::Tramway, Color{0xffdb2f} }, // 2 OSM: 7418090 WD: Q59159905 33.56, -7.682 x 33.61, -7.507
    { 1393, 19863, NoLogo, LineMetaDataContent::Tramway, Color{0xffa500} }, // T4 OSM: 7420266 WD: Q15507510 41.02, 28.85 x 41.12, 28.93
    { 67, 19891, 9802, LineMetaDataContent::Subway, Color{0x82c8e6} }, // 13 OSM: 7420641 WD: Q50759 48.81, 2.284 x 48.95, 2.369
    { 15, 19927, 9802, LineMetaDataContent::Subway, Color{0x00643c} }, // 12 OSM: 7420642 WD: Q50757 48.82, 2.273 x 48.91, 2.381
    { 63, 19963, 9802, LineMetaDataContent::Subway, Color{0x6e491e} }, // 11 OSM: 7420643 WD: Q50756 48.86, 2.348 x 48.89, 2.48
    { 19, 19999, 9802, LineMetaDataContent::Subway, Color{0xd282be} }, // 8 OSM: 7420644 WD: Q50751 48.77, 2.278 x 48.87, 2.464
    { 6, 20034, 9802, LineMetaDataContent::Subway, Color{0xff7f32} }, // 5 OSM: 7420645 WD: Q50745 48.83, 2.354 x 48.91, 2.449
    { 2740, 20069, 9802, LineMetaDataContent::Subway, Color{0x82c8e6} }, // 3bis OSM: 7420646 WD: Q50742 48.87, 2.399 x 48.88, 2.407
    { 429, 20107, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf28e42} }, // P OSM: 7420696 WD: Q93874 48.51, 2.359 x 49.18, 3.409
    { 598, 20141, 3863, LineMetaDataContent::RapidTransit, Color{0xf3a4ba} }, // R OSM: 7420697 WD: Q93383 48.01, 2.374 x 48.84, 2.943
    { 34, 20175, 3863, LineMetaDataContent::RapidTransit, Color{0x7b4339} }, // H OSM: 7420698 WD: Q93386 48.88, 2.093 x 49.26, 2.468
    { 705, 20209, 3863, LineMetaDataContent::RapidTransit, Color{0x00a88f} }, // N OSM: 7420700 WD: Q93376 48.64, 1.37 x 48.99, 2.32
    { 279, 20243, 2986, LineMetaDataContent::RapidTransit, Color{0x5291ce} }, // B OSM: 7420701 WD: Q1347825 48.69, 2.071 x 49.01, 2.642
    { 2745, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // CCL OSM: 7422278 WD: Q954278 -41.29, 174.8 x -41.28, 174.8
    { 414, 20275, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfd8fb4} }, // S OSM: 7424196 WD: Q2329867 48.17, 16.33 x 48.26, 16.4
    { 586, NoLogo, 4130, LineMetaDataContent::RapidTransit, Color{0x035eb9} }, // K OSM: 7435653 WD: Q118874957 60.17, 24.93 x 60.41, 25.11
    { 712, 20297, 4130, LineMetaDataContent::RapidTransit, Color{0x8c4799} }, // A OSM: 7440364 WD: Q118874158 60.17, 24.81 x 60.22, 24.94
    { 9, 20315, NoLogo, LineMetaDataContent::Subway, Color{0x5f259f} }, // 4 OSM: 7448424 WD: Q1326504 31.18, 121.4 x 31.26, 121.5
    { 19, 20335, NoLogo, LineMetaDataContent::Subway, Color{0x009fdf} }, // 8 OSM: 7451833 WD: Q1152341 31.06, 121.5 x 31.32, 121.5
    { 146, 20355, NoLogo, LineMetaDataContent::Subway, Color{0x71c5e8} }, // 9 OSM: 7451835 WD: Q1152370 30.99, 121.2 x 31.27, 121.7
    { 15, 20375, NoLogo, LineMetaDataContent::Subway, Color{0x007b5f} }, // 12 OSM: 7451887 WD: Q877180 31.13, 121.3 x 31.28, 121.6
    { 67, 20396, NoLogo, LineMetaDataContent::Subway, Color{0xef95cf} }, // 13 OSM: 7451890 WD: Q607539 31.17, 121.3 x 31.25, 121.6
    { 75, 20417, NoLogo, LineMetaDataContent::Subway, Color{0xc1a7e2} }, // 10 OSM: 7452119 WD: Q528209 31.17, 121.3 x 31.36, 121.6
    { 46, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf9e32c} }, // S7 OSM: 7508635 WD: Q125989608 49.67, 18.35 x 49.75, 18.64
    { 314, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x83d9e0} }, // S4 OSM: 7510544 WD: Q125989605 49.68, 18.04 x 49.91, 18.55
    { 2749, 20427, 20452, LineMetaDataContent::RapidTransit, Color{0xed8000} }, // I2 OSM: 7527498 WD: Q484739 37.44, 126.6 x 37.6, 126.8
    { 424, 20480, 20452, LineMetaDataContent::RapidTransit, Color{0xfda600} }, // U OSM: 7530882 WD: Q491655 37.72, 127 x 37.75, 127.1
    { 548, NoLogo, 20452, LineMetaDataContent::RapidTransit, Color{0x509f22} }, // E OSM: 7531174 WD: Q489609 37.24, 127.1 x 37.29, 127.2
    { 758, 20508, 20452, LineMetaDataContent::RapidTransit, Color{0xb0ce18} }, // W OSM: 7533584 WD: Q3832795 37.58, 127 x 37.66, 127
    { 367, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // Blue OSM: 7548642 41.47, -81.71 x 41.51, -81.54
    { 653, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // Green OSM: 7548643 41.48, -81.71 x 41.51, -81.52
    { 379, NoLogo, 20546, LineMetaDataContent::Subway, Color{0xff0000} }, // Red OSM: 7551457 WD: Q2136023 41.41, -81.84 x 41.53, -81.58
    { 68, NoLogo, 20569, LineMetaDataContent::Tramway, Color{0x00ff00} }, // 3 OSM: 7560907 WD: Q7833152 51.34, -0.1055 x 51.38, -0.01743
    { 64, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 1 OSM: 7568956 WD: Q4461887 53.89, 27.54 x 53.95, 27.62
    { 47, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8b0000} }, // 7 OSM: 7571262 WD: Q121537243 53.85, 27.54 x 53.91, 27.63
    { 2752, 20587, 20604, LineMetaDataContent::Subway, Color{0xffd100} }, // YL OSM: 7572167 WD: Q4710841 38.79, -77.08 x 38.91, -77.02
    { 2755, NoLogo, 20625, LineMetaDataContent::RapidTransit, Color{0xbcbdc0} }, // Silver OSM: 7572385 WD: Q86752660 40.29, -80.03 x 40.45, -79.99
    { 2762, 20658, NoLogo, LineMetaDataContent::RapidTransit, Color{0x005cb9} }, // 510 OSM: 7572438 WD: Q4929374 32.54, -117.2 x 32.88, -117
    { 2766, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x80276c} }, // CR-Fitchburg OSM: 7573753 WD: Q172548 42.36, -71.85 x 42.58, -71.06
    { 379, NoLogo, 20625, LineMetaDataContent::RapidTransit, Color{0xec1b24} }, // Red OSM: 7574880 WD: Q7304506 40.34, -80.05 x 40.45, -79.99
    { 367, NoLogo, 20625, LineMetaDataContent::RapidTransit, Color{0x77b6e4} }, // Blue OSM: 7575525 WD: Q18229920 40.34, -80.05 x 40.45, -79.99
    { 725, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x15618e} }, // T2 OSM: 7580423 WD: Q3239070 50.32, 3.511 x 50.46, 3.596
    { 289, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xd73527} }, // T1 OSM: 7580424 WD: Q3239057 50.32, 3.385 x 50.37, 3.523
    { 2786, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0066cc} }, // TC OSM: 7597545 WD: Q3538439 -34.51, -58.58 x -34.42, -58.48
    { 16, 20697, 20452, LineMetaDataContent::Subway, Color{0x33a23d} }, // 2 OSM: 7625892 WD: Q17501 37.48, 126.8 x 37.57, 127.1
    { 9, 20720, 20452, LineMetaDataContent::Subway, Color{0x32a1c8} }, // 4 OSM: 7625893 WD: Q489253 37.3, 126.7 x 37.72, 127.2
    { 520, 20743, NoLogo, LineMetaDataContent::Subway, Color{0x659acd} }, // L1 OSM: 7627370 WD: Q20685853 36.71, 3.054 x 36.79, 3.138
    { 356, 20775, 8524, LineMetaDataContent::Tramway, Color{0xf3c300} }, // 51 OSM: 7632520 WD: Q751385 50.84, 4.33 x 50.89, 4.349
    { 1048, 20797, 8524, LineMetaDataContent::Tramway, Color{0xed7807} }, // 93 OSM: 7632524 WD: Q2845878 50.82, 4.33 x 50.89, 4.372
    { 64, 20819, 20843, LineMetaDataContent::Subway, Color{0x147049} }, // 1 OSM: 7643008 WD: Q21034316 38.02, 46.23 x 38.08, 46.36
    { 170, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 49 OSM: 7657682 WD: Q122585370 55.68, 37.62 x 55.7, 37.69
    { 16, 20865, 10059, LineMetaDataContent::Subway, Color{0x006abc} }, // 2 OSM: 7660420 WD: Q1771527 56.32, 43.89 x 56.34, 43.97
    { 459, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x929292} }, // 59 OSM: 7662334 WD: Q68580821 49.99, 8.223 x 50.02, 8.26
    { 360, 20884, 20920, LineMetaDataContent::Subway, Color{0xf25e24} }, // M1 OSM: 7664663 WD: Q56399711 60.14, 24.64 x 60.21, 25.15
    { 441, 20884, 20920, LineMetaDataContent::Subway, Color{0xf25e24} }, // M2 OSM: 7664664 WD: Q56399732 60.16, 24.8 x 60.24, 25.11
    { 2789, 20945, 17555, LineMetaDataContent::Subway, Color{0xae6017} }, // Bakerloo OSM: 7666698 WD: Q19892 51.5, -0.3355 x 51.59, -0.1007
    { 473, 20971, 17555, LineMetaDataContent::Subway, Color{0xf4a9be} }, // Hammersmith & City OSM: 7666927 WD: Q211270 51.49, -0.2269 x 51.54, 0.08088
    { 2798, NoLogo, 17555, LineMetaDataContent::Subway, Color{0xffd329} }, // Circle OSM: 7671007 WD: Q210321 51.49, -0.2269 x 51.53, -0.07523
    { 2805, NoLogo, 17555, LineMetaDataContent::Subway, Color{0x93ceba} }, // Waterloo & City OSM: 7672075 WD: Q207699 51.5, -0.1142 x 51.51, -0.09074
    { 2821, 20992, 17555, LineMetaDataContent::Subway, Color{0x949699} }, // Jubilee OSM: 7673326 WD: Q961290 51.5, -0.3029 x 51.62, 0.01244
    { 2829, 21017, 17555, LineMetaDataContent::Subway, Color{0x91005a} }, // Metropolitan OSM: 7673626 WD: Q19891 51.51, -0.6366 x 51.71, -0.0757
    { 2842, 21047, 17555, LineMetaDataContent::Subway, Color{0x00a166} }, // District OSM: 7677096 WD: Q211265 51.42, -0.3016 x 51.56, 0.2526
    { 64, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xcc0000} }, // 1 OSM: 7680781 10.15, -68.01 x 10.2, -68
    { 64, 21073, 21073, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 7683834 WD: Q239927 37.51, 15.04 x 37.52, 15.1
    { 64, 21107, NoLogo, LineMetaDataContent::Subway, Color{0x0000ff} }, // 1 OSM: 7684062 WD: Q6553099 19.09, 72.82 x 19.13, 72.91
    { 2851, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008f75} }, // CAT OSM: 7685186 10.48, -66.81 x 10.49, -66.8
    { 68, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x00af23} }, // 3 OSM: 7686574 WD: Q5017776 30.02, 31.18 x 30.15, 31.43
    { 2855, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xdc241f} }, // NSL OSM: 7695961 WD: Q759229 1.27, 103.7 x 1.45, 103.9
    { 2859, 21139, NoLogo, LineMetaDataContent::LocalTrain, Color{0x06844b} }, // RB66 OSM: 7699251 WD: Q67991420 53.02, 13.97 x 53.42, 14.55
    { 64, 21159, 21159, LineMetaDataContent::Subway, Color{0xffa500} }, // 1 OSM: 7702663 WD: Q106335393 34.39, 132.4 x 34.48, 132.5
    { 34, 21175, 21202, LineMetaDataContent::Subway, Color{0x0077cc} }, // H OSM: 7702769 WD: Q1073881 33.59, 130.4 x 33.63, 130.4
    { 2882, 21231, 17555, LineMetaDataContent::Subway, Color{0x094fa3} }, // Piccadilly OSM: 7702940 WD: Q207689 51.46, -0.4877 x 51.65, -0.09515
    { 2893, 21259, 17555, LineMetaDataContent::Subway, Color{0x000000} }, // Northern OSM: 7702944 WD: Q214793 51.4, -0.2756 x 51.65, -0.08677
    { 586, 21285, 21202, LineMetaDataContent::Subway, Color{0xff4500} }, // K OSM: 7703353 WD: Q908188 33.58, 130.3 x 33.6, 130.4
    { 2902, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xc61094} }, // MM OSM: 7703640 WD: Q852314 35.44, 139.6 x 35.47, 139.7
    { 26, 21308, NoLogo, LineMetaDataContent::Tramway, Color{0x51279e} }, // 16 OSM: 7704225 WD: Q117430136 52.38, 16.91 x 52.46, 17
    { 27, 21347, NoLogo, LineMetaDataContent::Tramway, Color{0x38ab43} }, // 6 OSM: 7705201 WD: Q108000749 52.39, 16.85 x 52.41, 17
    { 19, 21385, NoLogo, LineMetaDataContent::Tramway, Color{0xe7212a} }, // 8 OSM: 7705202 WD: Q117303255 52.41, 16.88 x 52.42, 17
    { 64, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xee3c3c} }, // 1 OSM: 7705626 WD: Q66782266 29.55, 52.45 x 29.69, 52.6
    { 64, NoLogo, 21423, LineMetaDataContent::Subway, Color{0x1a988c} }, // 1 OSM: 7705633 WD: Q104230289 32.49, 51.53 x 32.86, 51.75
    { 47, 21446, 21470, LineMetaDataContent::Subway, Color{0x6a00ff} }, // 7 OSM: 7705644 WD: Q20110124 35.67, 51.35 x 35.79, 51.49
    { 9, 21492, 21470, LineMetaDataContent::Subway, Color{0xffff00} }, // 4 OSM: 7705669 WD: Q20110121 35.69, 51.3 x 35.75, 51.5
    { 2905, 21516, 20452, LineMetaDataContent::RapidTransit, Color{0x8652a1} }, // BGL OSM: 7705740 WD: Q87056 35.16, 128.9 x 35.27, 129
    { 2909, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x43b02a} }, // THZ1 OSM: 7708095 WD: Q15906593 23.1, 113.3 x 23.11, 113.4
    { 520, 15344, NoLogo, LineMetaDataContent::Subway, Color{0xdf2937} }, // L1 OSM: 7712343 WD: Q25420888 8.962, -79.55 x 9.083, -79.51
    { 586, 21538, 21580, LineMetaDataContent::Subway, Color{0xec78b4} }, // K OSM: 7712576 WD: Q1078347 35.2, 136.9 x 35.2, 136.9
    { 598, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x3e754e} }, // R OSM: 7712694 WD: Q7360056 34.68, 135.3 x 34.72, 135.3
    { 429, 21613, NoLogo, LineMetaDataContent::RapidTransit, Color{0x3573bd} }, // P OSM: 7712875 WD: Q7230715 34.64, 135.2 x 34.7, 135.2
    { 586, 21639, 21661, LineMetaDataContent::Subway, Color{0x267dce} }, // K OSM: 7712969 WD: Q844019 34.65, 135.1 x 34.69, 135.2
    { 317, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfb5373} }, // D26 OSM: 7713151 50.58, 15.93 x 50.82, 16.07
    { 9, 21692, NoLogo, LineMetaDataContent::Subway, Color{0xdc241f} }, // 4 OSM: 7713538 WD: Q1004293 22.52, 114 x 22.73, 114.1
    { 146, 21715, NoLogo, LineMetaDataContent::Tramway, Color{0xf7822a} }, // 9 OSM: 7715858 WD: Q108006623 52.37, 16.9 x 52.44, 16.94
    { 441, 21753, 21781, LineMetaDataContent::Subway, Color{0x009a4c} }, // M2 OSM: 7719078 WD: Q1880934 41.01, 28.95 x 41.14, 29.03
    { 8, 21805, 21781, LineMetaDataContent::Subway, Color{0xe91e76} }, // M4 OSM: 7719080 WD: Q1880989 40.88, 29.02 x 41, 29.31
    { 360, 21833, 21781, LineMetaDataContent::Subway, Color{0xe32726} }, // M1 OSM: 7719081 WD: Q6048705 40.98, 28.82 x 41.05, 28.95
    { 1265, 21861, 21781, LineMetaDataContent::Subway, Color{0x00a8e1} }, // M3 OSM: 7719082 WD: Q1880963 40.97, 28.77 x 41.12, 28.88
    { 29, 21889, 21781, LineMetaDataContent::Subway, Color{0xcaaa79} }, // M6 OSM: 7719783 WD: Q16949744 41.08, 29.01 x 41.09, 29.05
    { 414, 21917, 21661, LineMetaDataContent::Subway, Color{0x00ae8e} }, // S OSM: 7720729 WD: Q1066548 34.66, 135 x 34.76, 135.2
    { 2914, 21940, NoLogo, LineMetaDataContent::LocalTrain, Color{0xda6ba2} }, // RB51 OSM: 7724425 WD: Q63348259 52.39, 12.33 x 52.6, 12.56
    { 363, 21960, 21973, LineMetaDataContent::Subway, Color{0x1e398d} }, // MRT Blue OSM: 7725030 WD: Q2486364 13.71, 100.4 x 13.81, 100.6
    { 1590, 21996, 21973, LineMetaDataContent::Subway, Color{0x893b90} }, // MRT Purple OSM: 7725058 WD: Q6584549 13.81, 100.4 x 13.89, 100.5
    { 520, 22011, 22034, LineMetaDataContent::Subway, Color{0x228b22} }, // L1 OSM: 7727216 WD: Q5985884 -12.21, -77.01 x -11.96, -76.93
    { 2919, 22080, 20452, LineMetaDataContent::Subway, Color{0xc82127} }, // 326 OSM: 7728256 WD: Q20388 37.29, 127 x 37.52, 127.1
    { 2923, 22113, 22113, LineMetaDataContent::Subway, Color{0x2e8b57} }, // 仙台市南北線 (Sendai Namboku Line) OSM: 7732249 WD: Q908156 38.21, 140.9 x 38.32, 140.9
    { 2964, 22113, 22113, LineMetaDataContent::Subway, Color{0x00bfff} }, // 仙台市東西線 (Sendai Tozai Line) OSM: 7732250 WD: Q7450186 38.24, 140.8 x 38.26, 140.9
    { 279, 22141, 22188, LineMetaDataContent::Subway, Color{0x005ba5} }, // B OSM: 7732280 WD: Q841360 35.4, 139.5 x 35.57, 139.6
    { 701, 22223, 22188, LineMetaDataContent::Subway, Color{0x048d58} }, // G OSM: 7732283 WD: Q910329 35.51, 139.5 x 35.56, 139.6
    { 520, 22271, NoLogo, LineMetaDataContent::Subway, Color{0xcc0000} }, // L1 OSM: 7732970 WD: Q4215382 -33.46, -70.72 x -33.41, -70.54
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xffbe2e} }, // 2 OSM: 7732971 WD: Q11690005 -33.58, -70.68 x -33.38, -70.64
    { 516, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x292d91} }, // L4 OSM: 7732972 WD: Q9025952 -33.62, -70.6 x -33.42, -70.57
    { 3003, 22296, NoLogo, LineMetaDataContent::Subway, Color{0x0099ff} }, // L4A OSM: 7732973 WD: Q11690009 -33.54, -70.67 x -33.52, -70.6
    { 1353, 22322, NoLogo, LineMetaDataContent::Subway, Color{0x006633} }, // L5 OSM: 7732974 WD: Q9025969 -33.53, -70.76 x -33.44, -70.6
    { 1357, 22347, NoLogo, LineMetaDataContent::Subway, Color{0x8e16a1} }, // L6 OSM: 7732978 WD: Q5986809 -33.48, -70.7 x -33.42, -70.6
    { 68, 22372, 9802, LineMetaDataContent::Subway, Color{0x6e6e00} }, // 3 OSM: 7733214 WD: Q50741 48.86, 2.28 x 48.9, 2.418
    { 64, 22407, 22407, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 7733917 WD: Q2047989 55.74, 49.08 x 55.86, 49.22
    { 64, 5620, 22428, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 7733918 WD: Q594532 54.98, 82.89 x 55.06, 82.94
    { 16, 6054, 22428, LineMetaDataContent::Subway, Color{0x008000} }, // 2 OSM: 7733919 WD: Q2711371 55.03, 82.9 x 55.04, 82.98
    { 64, NoLogo, 22455, LineMetaDataContent::Subway, Color{0x1c8c3a} }, // 1 OSM: 7733920 WD: Q750441 56.8, 60.6 x 56.9, 60.63
    { 3007, 22474, NoLogo, LineMetaDataContent::Subway, Color{0x076c57} }, // Verde OSM: 7733971 WD: Q10318743 -15.84, -48.12 x -15.79, -47.88
    { 3013, 22493, NoLogo, LineMetaDataContent::Subway, Color{0xeb9710} }, // Laranja OSM: 7733972 WD: Q10318700 -15.87, -48.09 x -15.79, -47.88
    { 16, 22517, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // 2 OSM: 7734060 WD: Q25421356 18.48, -69.97 x 18.51, -69.86
    { 64, 22532, NoLogo, LineMetaDataContent::Subway, Color{0x0000ff} }, // 1 OSM: 7734061 WD: Q25421357 18.45, -69.93 x 18.55, -69.9
    { 64, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // 1 OSM: 7734069 10.62, -71.67 x 10.64, -71.62
    { 64, 22548, 22580, LineMetaDataContent::Subway, Color{0x0000ff} }, // 1 OSM: 7734077 WD: Q28604 53.85, 27.47 x 53.95, 27.69
    { 16, NoLogo, 22580, LineMetaDataContent::Subway, Color{0xff0000} }, // 2 OSM: 7734078 WD: Q2638932 53.86, 27.43 x 53.91, 27.67
    { 441, 22601, 22626, LineMetaDataContent::Subway, Color{0x0000ff} }, // M2 OSM: 7734092 WD: Q12295702 42.66, 23.28 x 42.74, 23.32
    { 360, 22647, 22626, LineMetaDataContent::Subway, Color{0xff0000} }, // M1 OSM: 7734093 WD: Q20020737 42.63, 23.26 x 42.73, 23.38
    { 3021, 22672, 22703, LineMetaDataContent::Subway, Color{0xdf096f} }, // Vermelha OSM: 7734163 WD: Q163215 38.73, -9.153 x 38.78, -9.099
    { 3030, 22733, 22703, LineMetaDataContent::Subway, Color{0xf4bc18} }, // Amarela OSM: 7734164 WD: Q1826607 38.72, -9.173 x 38.79, -9.145
    { 3038, NoLogo, 22703, LineMetaDataContent::Subway, Color{0x4e84c4} }, // Azul OSM: 7734165 WD: Q1826609 38.71, -9.224 x 38.76, -9.122
    { 3007, 22763, 22703, LineMetaDataContent::Subway, Color{0x00aaa6} }, // Verde OSM: 7734166 WD: Q1826613 38.71, -9.166 x 38.76, -9.133
    { 3043, 22791, 22791, LineMetaDataContent::Subway, Color{0xff6600} }, // Subway OSM: 7734173 WD: Q106328343 55.85, -4.312 x 55.88, -4.253
    { 64, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 7734180 WD: Q4504162 48.47, 34.93 x 48.48, 35.02
    { 705, 22810, 21202, LineMetaDataContent::Subway, Color{0x008000} }, // N OSM: 7734239 WD: Q1039166 33.55, 130.3 x 33.59, 130.4
    { 379, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xcc0000} }, // Red OSM: 7734262 WD: Q1369034 24.96, 55.13 x 25.27, 55.39
    { 653, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x00cc00} }, // Green OSM: 7734263 WD: Q1544621 25.22, 55.29 x 25.28, 55.4
    { 414, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xffc0cb} }, // S OSM: 7734268 WD: Q16240707 21.33, 39.87 x 21.42, 39.98
    { 64, 22837, 22862, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 7734272 WD: Q1473986 43.22, 76.84 x 43.27, 76.95
    { 16, 22884, 22884, LineMetaDataContent::Subway, Color{0x008000} }, // 2 OSM: 7734279 WD: Q712790 39.03, 125.7 x 39.07, 125.8
    { 64, 22884, 22884, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 7734280 WD: Q711112 39.01, 125.7 x 39.07, 125.8
    { 64, 22916, 21470, LineMetaDataContent::Subway, Color{0xff0f04} }, // 1 OSM: 7735256 WD: Q20110118 35.4, 50.98 x 35.8, 51.44
    { 6, 22940, 21470, LineMetaDataContent::RapidTransit, Color{0x008033} }, // 5 OSM: 7735262 WD: Q20110122 35.72, 50.72 x 35.96, 51.33
    { 64, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x259b24} }, // 1 OSM: 7740660 WD: Q19856263 26.5, 106.6 x 26.66, 106.7
    { 47, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe10886} }, // 7 OSM: 7741475 WD: Q122781783 45.72, 21.2 x 45.77, 21.23
    { 289, 22964, NoLogo, LineMetaDataContent::Tramway, Color{0x64318f} }, // T1 OSM: 7758458 WD: Q50319281 49.58, 6.111 x 49.64, 6.176
    { 68, 22984, 21470, LineMetaDataContent::Subway, Color{0x00aad4} }, // 3 OSM: 7770934 WD: Q20110120 35.63, 51.34 x 35.8, 51.52
    { 3050, 23008, 23008, LineMetaDataContent::RapidTransit, Color{0x00afad} }, // B-L OSM: 7772561 WD: Q110165973 51.46, -0.08835 x 51.51, -0.009527
    { 3054, 23008, 23008, LineMetaDataContent::RapidTransit, Color{0x00afad} }, // B-WA OSM: 7772562 WD: Q115768816 51.49, -0.08835 x 51.51, 0.07755
    { 3059, 23008, 23008, LineMetaDataContent::RapidTransit, Color{0x00afad} }, // S-L OSM: 7772563 WD: Q115770034 51.46, -0.02285 x 51.54, -0.003982
    { 3063, 23008, 23008, LineMetaDataContent::RapidTransit, Color{0x00afad} }, // TG-B OSM: 7772565 WD: Q110167827 51.51, -0.07453 x 51.51, 0.07189
    { 3068, 23008, 23008, LineMetaDataContent::RapidTransit, Color{0x00afad} }, // SI-WA OSM: 7772566 WD: Q110167188 51.49, -0.01335 x 51.55, 0.07755
    { 1265, 23024, 9935, LineMetaDataContent::Subway, Color{0xbc1725} }, // M3 OSM: 7772846 WD: Q2735258 44.41, 25.99 x 44.44, 26.21
    { 360, 23040, 9935, LineMetaDataContent::Subway, Color{0xffff00} }, // M1 OSM: 7772847 WD: Q2056949 44.41, 26.04 x 44.45, 26.2
    { 3074, 23056, NoLogo, LineMetaDataContent::LongDistanceTrain, Color{0xdd3327} }, // IC 1 OSM: 7778963 WD: Q115929517 46.21, 6.099 x 47.51, 9.371
    { 3079, 23070, NoLogo, LineMetaDataContent::LongDistanceTrain, Color{0xf29220} }, // IC 5 OSM: 7778977 WD: Q115932346 46.21, 6.099 x 47.51, 9.511
    { 3084, 23084, NoLogo, LineMetaDataContent::LongDistanceTrain, Color{0x9084bd} }, // IC 2 OSM: 7779154 WD: Q115932323 46, 8.496 x 47.38, 9.042
    { 3089, 23098, NoLogo, LineMetaDataContent::LongDistanceTrain, Color{0x048c45} }, // IC 3 OSM: 7779203 WD: Q115932338 46.85, 7.587 x 47.55, 9.562
    { 82, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xb56631} }, // 21 OSM: 7779520 WD: Q1432090 59.34, 18.1 x 59.36, 18.23
    { 520, 23112, 23142, LineMetaDataContent::Subway, Color{0x008000} }, // L1 OSM: 7781389 WD: Q2668472 37.33, -6.052 x 37.38, -5.934
    { 524, 23176, NoLogo, LineMetaDataContent::RapidTransit, Color{0x173ba0} }, // L2 OSM: 7781442 WD: Q5986162 36.68, -4.458 x 36.72, -4.43
    { 520, 23195, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe60000} }, // L1 OSM: 7781445 WD: Q5392889 36.71, -4.496 x 36.72, -4.423
    { 441, 23214, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe93324} }, // M2 OSM: 7781535 WD: Q11180785 39.58, 2.654 x 39.63, 2.725
    { 360, 23233, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf1b03e} }, // M1 OSM: 7781536 WD: Q5985887 39.58, 2.648 x 39.63, 2.673
    { 3094, 23252, NoLogo, LineMetaDataContent::LongDistanceTrain, Color{0xad1f23} }, // IC 51 OSM: 7782231 WD: Q115932401 47.13, 7.239 x 47.55, 7.619
    { 3100, 23267, NoLogo, LineMetaDataContent::LongDistanceTrain, Color{0xffc909} }, // IC 21 OSM: 7782364 WD: Q115932392 46, 7.587 x 47.55, 9.042
    { 3106, 23282, NoLogo, LineMetaDataContent::LongDistanceTrain, Color{0xb69495} }, // IR 26 OSM: 7782601 WD: Q115987448 46.15, 7.586 x 47.55, 9.042
    { 3112, 23297, NoLogo, LineMetaDataContent::LongDistanceTrain, Color{0x66711f} }, // IR 27 OSM: 7782646 WD: Q115987465 47.04, 7.586 x 47.55, 8.311
    { 16, 23312, 23331, LineMetaDataContent::Subway, Color{0x008000} }, // 2 OSM: 7786077 WD: Q2210273 41.72, 44.72 x 41.73, 44.8
    { 64, 23354, 23331, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 7786078 WD: Q340562 41.69, 44.78 x 41.79, 44.87
    { 548, 23385, 23385, LineMetaDataContent::RapidTransit, Color{0xffff00} }, // E OSM: 7786518 WD: Q1714062 50.4, 30.39 x 50.5, 30.64
    { 16, 23415, 23435, LineMetaDataContent::Subway, Color{0xed1d24} }, // 2 OSM: 7786752 WD: Q3238802 50.62, 2.974 x 50.74, 3.181
    { 64, 23461, 23435, LineMetaDataContent::Subway, Color{0xffd400} }, // 1 OSM: 7786754 WD: Q3238658 50.61, 3.036 x 50.64, 3.143
    { 3118, 23481, NoLogo, LineMetaDataContent::LongDistanceTrain, Color{0x7a448f} }, // IR 75 OSM: 7787427 WD: Q116053272 47.04, 8.286 x 47.66, 9.192
    { 3124, 23496, NoLogo, LineMetaDataContent::LongDistanceTrain, Color{0x006788} }, // IR 46 OSM: 7787446 WD: Q116052876 46.15, 7.907 x 47.38, 9.042
    { 3130, 23511, NoLogo, LineMetaDataContent::LongDistanceTrain, Color{0xf193bd} }, // IR 70 OSM: 7787497 WD: Q116053265 47.04, 8.286 x 47.45, 8.593
    { 3136, 23526, NoLogo, LineMetaDataContent::LongDistanceTrain, Color{0x93c13e} }, // IC 6 OSM: 7791233 WD: Q115932382 46.29, 7.434 x 47.55, 7.991
    { 3141, 23540, NoLogo, LineMetaDataContent::LongDistanceTrain, Color{0xe95097} }, // IC 61 OSM: 7791339 WD: Q115932445 46.65, 7.434 x 47.55, 7.918
    { 2214, 23555, NoLogo, LineMetaDataContent::Subway, Color{0x90ee90} }, // 2B OSM: 7792472 WD: Q3832656 40.38, 49.85 x 40.38, 49.87
    { 64, 23555, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 7792473 WD: Q3832654 40.37, 49.83 x 40.42, 49.95
    { 16, 23555, NoLogo, LineMetaDataContent::Subway, Color{0x008000} }, // 2 OSM: 7792474 WD: Q3832656 40.37, 49.8 x 40.43, 49.95
    { 68, 23555, NoLogo, LineMetaDataContent::Subway, Color{0x800080} }, // 3 OSM: 7792475 WD: Q25547220 40.4, 49.78 x 40.43, 49.82
    { 64, 23576, 20452, LineMetaDataContent::Subway, Color{0x007448} }, // 1 OSM: 7792528 WD: Q200310 36.32, 127.3 x 36.39, 127.5
    { 3147, 23601, NoLogo, LineMetaDataContent::LongDistanceTrain, Color{0x15ae8d} }, // IR 15 OSM: 7793337 WD: Q115973525 46.21, 6.099 x 47.31, 8.311
    { 108, 23616, NoLogo, LineMetaDataContent::LongDistanceTrain, Color{0xb8da89} }, // IR37 OSM: 7793439 WD: Q116052863 47.35, 7.585 x 47.55, 8.539
    { 3153, 23631, NoLogo, LineMetaDataContent::LocalTrain, Color{0x009bd5} }, // RB 43 OSM: 7793791 WD: Q84429153 51.58, 13.24 x 52.34, 14.73
    { 3159, 23651, NoLogo, LineMetaDataContent::LongDistanceTrain, Color{0xa36b1f} }, // IR 16 OSM: 7794142 WD: Q115987375 46.95, 7.434 x 47.49, 8.539
    { 3165, 23666, NoLogo, LineMetaDataContent::LongDistanceTrain, Color{0xae126f} }, // IR 36 OSM: 7794220 WD: Q116052855 47.38, 7.585 x 47.57, 8.566
    { 3171, 23681, NoLogo, LineMetaDataContent::LongDistanceTrain, Color{0x25539c} }, // IR 17 OSM: 7795137 WD: Q115987430 46.95, 7.433 x 47.35, 7.908
    { 3177, 23696, NoLogo, LineMetaDataContent::LongDistanceTrain, Color{0x007ca3} }, // IR 90 OSM: 7796313 WD: Q115973464 46.11, 6.099 x 46.54, 7.988
    { 1884, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0xf58220} }, // S19 OSM: 7800298 WD: Q25352054 47.37, 8.227 x 47.6, 8.787
    { 26, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xa75f4a} }, // 16 OSM: 7801277 WD: Q123363026 56.81, 60.56 x 56.86, 60.65
    { 3183, 23711, 226, LineMetaDataContent::RapidTransit, Color{0xf17f1a} }, // S 9 OSM: 7805411 WD: Q63217750 51.45, 11.98 x 51.52, 12.64
    { 3187, NoLogo, 23736, LineMetaDataContent::RapidTransit, Color{0xe5007d} }, // R9 OSM: 7813522 WD: Q110265757 46.49, 6.631 x 46.98, 7.192
    { 2302, NoLogo, 23736, LineMetaDataContent::RapidTransit, Color{0x9084be} }, // R8 OSM: 7813578 WD: Q110256517 46.54, 6.791 x 46.82, 6.94
    { 3190, 23752, NoLogo, LineMetaDataContent::LocalTrain, Color{0xda6ba2} }, // RB24 OSM: 7814259 WD: Q67993390 51.53, 13.4 x 52.84, 14.06
    { 2292, NoLogo, 23736, LineMetaDataContent::RapidTransit, Color{0x23318a} }, // R3 OSM: 7818748 WD: Q115446633 46.21, 6.37 x 46.73, 7.003
    { 697, NoLogo, 23736, LineMetaDataContent::RapidTransit, Color{0xf39100} }, // R1 OSM: 7819263 WD: Q110265543 46.49, 6.517 x 46.81, 6.727
    { 2244, NoLogo, 23736, LineMetaDataContent::RapidTransit, Color{0x00681d} }, // R5 OSM: 7819266 WD: Q115454944 46.47, 6.395 x 46.54, 6.838
    { 3195, NoLogo, 23736, LineMetaDataContent::RapidTransit, Color{0xf7941d} }, // R7 OSM: 7819287 WD: Q1366579 46.46, 6.762 x 46.49, 6.845
    { 671, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x777777} }, // U ATE-CRI OSM: 7823073 WD: Q576138 38.71, -9.174 x 38.99, -8.965
    { 516, 23772, 23795, LineMetaDataContent::Subway, Color{0x824100} }, // L4 OSM: 7827780 WD: Q1826677 40.42, -3.716 x 40.48, -3.635
    { 520, 23815, 23795, LineMetaDataContent::Subway, Color{0x67c0dd} }, // L1 OSM: 7831481 WD: Q1826675 40.36, -3.706 x 40.48, -3.591
    { 16, 23838, 21470, LineMetaDataContent::Subway, Color{0x003380} }, // 2 OSM: 7832325 WD: Q20110119 35.69, 51.33 x 35.74, 51.55
    { 3199, 23862, 23795, LineMetaDataContent::Subway, Color{0x015396} }, // L10 OSM: 7834660 WD: Q1760090 40.34, -3.813 x 40.56, -3.611
    { 679, NoLogo, 23886, LineMetaDataContent::Subway, Color{0x7fffd4} }, // I OSM: 7834960 WD: Q106775989 9.95, 76.28 x 10.11, 76.35
    { 1365, 23907, 23795, LineMetaDataContent::Subway, Color{0xff0080} }, // L8 OSM: 7837169 WD: Q1475527 40.44, -3.692 x 40.49, -3.572
    { 3204, 23930, 23795, LineMetaDataContent::Subway, Color{0x9c3293} }, // L9 OSM: 7837206 WD: Q1759707 40.3, -3.721 x 40.5, -3.447
    { 3209, 23953, 4274, LineMetaDataContent::Subway, Color{0x996633} }, // Z OSM: 7837591 WD: Q3239257 40.68, -74.01 x 40.72, -73.8
    { 1353, 23979, 23795, LineMetaDataContent::Subway, Color{0x96bf0d} }, // L5 OSM: 7838614 WD: Q1568028 40.38, -3.769 x 40.46, -3.588
    { 360, 24002, 24002, LineMetaDataContent::Subway, Color{0xffa500} }, // M1 OSM: 7838818 WD: Q1577356 36.98, 35.26 x 37.05, 35.34
    { 528, 24023, 23795, LineMetaDataContent::Subway, Color{0xffdf00} }, // L3 OSM: 7838838 WD: Q1826673 40.34, -3.72 x 40.44, -3.692
    { 524, 24046, 23795, LineMetaDataContent::Subway, Color{0xfb0f0c} }, // L2 OSM: 7838963 WD: Q1826679 40.42, -3.71 x 40.45, -3.602
    { 1361, 24069, 23795, LineMetaDataContent::Subway, Color{0xed7b24} }, // L7 OSM: 7840623 WD: Q1826683 40.42, -3.727 x 40.5, -3.524
    { 598, 24092, 23795, LineMetaDataContent::Subway, Color{0xffffff} }, // R OSM: 7840747 WD: Q1496137 40.42, -3.72 x 40.42, -3.71
    { 1594, NoLogo, 24114, LineMetaDataContent::Subway, Color{0xe542de} }, // Purple OSM: 7841332 WD: Q7261433 12.9, 77.46 x 13, 77.76
    { 498, 24130, 23795, LineMetaDataContent::Subway, Color{0xa49a00} }, // L12 OSM: 7841412 WD: Q1558864 40.28, -3.876 x 40.35, -3.71
    { 64, 24154, NoLogo, LineMetaDataContent::Subway, Color{0xf03b3f} }, // 1 OSM: 7841834 WD: Q11085985 31.44, 120.3 x 31.68, 120.3
    { 16, 24179, NoLogo, LineMetaDataContent::Subway, Color{0x00a43c} }, // 2 OSM: 7841837 WD: Q11085986 31.55, 120.2 x 31.61, 120.5
    { 64, NoLogo, 24204, LineMetaDataContent::Subway, Color{0xe53e30} }, // 1 OSM: 7841839 WD: Q30326155 38.04, 114.4 x 38.16, 114.6
    { 68, NoLogo, 24204, LineMetaDataContent::Subway, Color{0x00a1e0} }, // 3 OSM: 7841854 WD: Q30326157 38, 114.4 x 38.08, 114.7
    { 64, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x00b04f} }, // 1 OSM: 7841881 WD: Q17498765 22.82, 108.2 x 22.84, 108.4
    { 1357, 24227, 23795, LineMetaDataContent::Subway, Color{0x939393} }, // L6 OSM: 7842094 WD: Q514227 40.39, -3.746 x 40.45, -3.668
    { 493, 24250, 23795, LineMetaDataContent::Subway, Color{0x006400} }, // L11 OSM: 7842127 WD: Q608251 40.36, -3.778 x 40.39, -3.718
    { 653, NoLogo, 24114, LineMetaDataContent::Subway, Color{0x009933} }, // Green OSM: 7842288 WD: Q17054000 12.86, 77.47 x 13.06, 77.58
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xaf272f} }, // 2 OSM: 7844345 WD: Q11149384 36.06, 120.3 x 36.17, 120.5
    { 16, NoLogo, 24274, LineMetaDataContent::Subway, Color{0x53b848} }, // 2 OSM: 7845614 WD: Q20647027 12.99, 80.19 x 13.09, 80.27
    { 239, 24297, NoLogo, LineMetaDataContent::Subway, Color{0xc09c83} }, // 17 OSM: 7845847 WD: Q6553108 31.07, 121 x 31.2, 121.3
    { 16, 24318, 20452, LineMetaDataContent::Subway, Color{0x18be00} }, // 2 OSM: 7845969 WD: Q200332 35.83, 128.4 x 35.87, 128.8
    { 64, 24341, 20452, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 7845971 WD: Q200331 35.8, 128.5 x 35.89, 128.7
    { 16, 24364, NoLogo, LineMetaDataContent::Subway, Color{0xfff100} }, // 2 OSM: 7846276 WD: Q15908164 34.66, 113.6 x 34.87, 113.7
    { 3211, 24383, 24407, LineMetaDataContent::RapidTransit, Color{0x4682b4} }, // ML1 OSM: 7849381 WD: Q2058921 40.48, -3.669 x 40.51, -3.651
    { 3215, 24433, 24407, LineMetaDataContent::RapidTransit, Color{0x660066} }, // ML2 OSM: 7853073 WD: Q3832710 40.4, -3.812 x 40.45, -3.775
    { 3219, 24457, 24407, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // ML3 OSM: 7853483 WD: Q3832709 40.39, -3.905 x 40.41, -3.775
    { 3223, 24481, 20452, LineMetaDataContent::Subway, Color{0x6fa0ce} }, // I1 OSM: 7854149 WD: Q487733 37.38, 126.6 x 37.57, 126.7
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x02406f} }, // 2 OSM: 7857258 WD: Q10318650 -12.98, -38.48 x -12.9, -38.34
    { 3226, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x61bf1a} }, // RL2 OSM: 7867506 WD: Q3781389 41.62, 0.631 x 42.24, 0.9662
    { 3230, 24506, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa6c82b} }, // R2Nord OSM: 7867878 WD: Q114215296 41.3, 2.052 x 41.77, 2.673
    { 3195, 24524, NoLogo, LineMetaDataContent::RapidTransit, Color{0xba55d3} }, // R7 OSM: 7867903 WD: Q1647981 41.43, 2.115 x 41.51, 2.189
    { 3237, 24541, 24568, LineMetaDataContent::Subway, Color{0xff0000} }, // B1 OSM: 7868621 WD: Q56067295 40.19, 28.95 x 40.27, 29.12
    { 16, 24586, NoLogo, LineMetaDataContent::Subway, Color{0xef3340} }, // 2 OSM: 7869228 WD: Q5934457 34.11, 108.9 x 34.4, 109
    { 64, 24606, NoLogo, LineMetaDataContent::Subway, Color{0x0077c8} }, // 1 OSM: 7869253 WD: Q14917524 34.27, 108.7 x 34.34, 109.1
    { 68, 24626, NoLogo, LineMetaDataContent::Subway, Color{0xb688a9} }, // 3 OSM: 7869255 WD: Q15927288 34.22, 108.8 x 34.4, 109.1
    { 16, 24646, NoLogo, LineMetaDataContent::Subway, Color{0xd9001c} }, // 2 OSM: 7869334 WD: Q16282623 -8.111, -35.02 x -8.069, -34.89
    { 64, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xe77405} }, // 1 OSM: 7869352 WD: Q104231463 -8.092, -35 x -8.024, -34.89
    { 2407, 24662, NoLogo, LineMetaDataContent::Subway, Color{0x1a5ba3} }, // Sul OSM: 7869374 WD: Q10329288 -8.168, -34.93 x -8.069, -34.88
    { 3240, 24675, 24568, LineMetaDataContent::Subway, Color{0x000000} }, // B2 OSM: 7869622 WD: Q61074931 40.19, 28.87 x 40.22, 29.21
    { 64, 24702, NoLogo, LineMetaDataContent::Subway, Color{0xe60012} }, // 1 OSM: 7871046 WD: Q15303225 34.75, 113.5 x 34.83, 113.8
    { 146, 24721, NoLogo, LineMetaDataContent::Subway, Color{0xa2ae73} }, // 9 OSM: 7871541 WD: Q28441548 34.49, 113.7 x 34.66, 113.9
    { 3243, 24741, 3759, LineMetaDataContent::RapidTransit, Color{0x8fbe00} }, // C-10 OSM: 7871793 WD: Q583732 40.4, -4.009 x 40.63, -3.594
    { 667, 24760, 3759, LineMetaDataContent::RapidTransit, Color{0x009ad5} }, // C-1 OSM: 7871905 WD: Q3832674 40.4, -3.722 x 40.49, -3.593
    { 3248, 24778, 3759, LineMetaDataContent::RapidTransit, Color{0xde0118} }, // C-7 OSM: 7872150 WD: Q8879938 40.38, -3.874 x 40.51, -3.365
    { 379, 24796, NoLogo, LineMetaDataContent::Subway, Color{0xda291c} }, // Red OSM: 7874288 WD: Q152039 42.21, -71.14 x 42.4, -71
    { 1446, 24822, NoLogo, LineMetaDataContent::Subway, Color{0xed8b00} }, // Orange OSM: 7874312 WD: Q152029 42.3, -71.11 x 42.44, -71.06
    { 16, 24851, NoLogo, LineMetaDataContent::Subway, Color{0x00afec} }, // 2 OSM: 7875250 WD: Q15919822 28.15, 112.9 x 28.21, 113.1
    { 64, 24881, NoLogo, LineMetaDataContent::Subway, Color{0xe60012} }, // 1 OSM: 7875257 WD: Q15911087 28.07, 112.9 x 28.34, 113
    { 9, 24911, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7d4697} }, // 4 OSM: 7875301 WD: Q6553125 43.75, 125.3 x 43.91, 125.4
    { 68, 24932, NoLogo, LineMetaDataContent::RapidTransit, Color{0x009943} }, // 3 OSM: 7875360 WD: Q6123656 43.77, 125.3 x 43.91, 125.4
    { 712, 24953, 24953, LineMetaDataContent::Subway, Color{0x056d2e} }, // A OSM: 7877753 WD: Q770771 39.92, 32.81 x 39.93, 32.88
    { 360, NoLogo, 24970, LineMetaDataContent::Subway, Color{0xbf0e1c} }, // M1 OSM: 7877773 WD: Q21526526 39.92, 32.73 x 39.97, 32.86
    { 441, NoLogo, 24970, LineMetaDataContent::Subway, Color{0xbf0e1c} }, // M2 OSM: 7877891 WD: Q21526527 39.88, 32.68 x 39.92, 32.86
    { 186, 24992, NoLogo, LineMetaDataContent::Subway, Color{0xffa500} }, // O OSM: 7879290 WD: Q7099668 22.62, 120.3 x 22.63, 120.4
    { 598, 25032, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // R OSM: 7879291 WD: Q7304504 22.56, 120.3 x 22.79, 120.4
    { 68, 25069, 20452, LineMetaDataContent::Subway, Color{0xfe5b10} }, // 3 OSM: 7879839 WD: Q20393 37.48, 126.7 x 37.68, 127.1
    { 6, 25092, 20452, LineMetaDataContent::Subway, Color{0x996cac} }, // 5 OSM: 7879871 WD: Q92530 37.49, 126.8 x 37.58, 127.2
    { 68, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x006dbb} }, // 3 OSM: 7883242 WD: Q15907883 36.05, 120.3 x 36.17, 120.4
    { 146, 25115, 20452, LineMetaDataContent::Subway, Color{0xaa9872} }, // 9 OSM: 7883317 WD: Q17503 37.5, 126.8 x 37.58, 127.1
    { 16, 25138, NoLogo, LineMetaDataContent::Subway, Color{0xd60e19} }, // 2 OSM: 7883944 WD: Q10946021 29.81, 121.5 x 29.95, 121.7
    { 64, 25159, 2861, LineMetaDataContent::Subway, Color{0xf8c300} }, // 1 OSM: 7884489 WD: Q54369 43.65, -79.53 x 43.79, -79.38
    { 64, 25208, 25238, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 7885089 WD: Q56277837 40.59, 22.93 x 40.65, 22.97
    { 16, 25266, 2861, LineMetaDataContent::Subway, Color{0x00923f} }, // 2 OSM: 7885287 WD: Q54371 43.64, -79.54 x 43.73, -79.26
    { 68, 25305, 12736, LineMetaDataContent::Subway, Color{0x009651} }, // 3 OSM: 7885547 WD: Q10906683 31.87, 118.7 x 32.17, 118.8
    { 3252, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x77278b} }, // WCE OSM: 7887557 49.13, -123.1 x 49.29, -122.3
    { 3256, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x000000} }, // Conexão Metrô-Aeroporto OSM: 7889062 WD: Q23891467 -29.99, -51.18 x -29.99, -51.18
    { 64, 25325, NoLogo, LineMetaDataContent::Subway, Color{0x5cb439} }, // 1 OSM: 7889178 WD: Q45668 31.28, 120.5 x 31.33, 120.8
    { 3282, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x808080} }, // RMGL OSM: 7890003 28.42, 77.09 x 28.5, 77.11
    { 64, 25346, NoLogo, LineMetaDataContent::Subway, Color{0xfec04f} }, // 1 OSM: 7890223 WD: Q5985916 25.68, -100.4 x 25.76, -100.2
    { 16, 25360, NoLogo, LineMetaDataContent::Subway, Color{0x6bc069} }, // 2 OSM: 7890224 WD: Q2842186 25.67, -100.3 x 25.77, -100.3
    { 16, 25374, NoLogo, LineMetaDataContent::Subway, Color{0x0066a1} }, // 2 OSM: 7890240 WD: Q6379343 38.9, 121.5 x 39.02, 121.7
    { 414, 4317, 4274, LineMetaDataContent::Subway, Color{0x808183} }, // S OSM: 7893704 WD: Q126772 40.58, -73.84 x 40.61, -73.81
    { 414, 25394, 4274, LineMetaDataContent::Subway, Color{0x808183} }, // S OSM: 7894362 WD: Q126725 40.66, -73.96 x 40.68, -73.96
    { 64, 25421, NoLogo, LineMetaDataContent::Subway, Color{0xb63f1f} }, // 1 OSM: 7894481 WD: Q5934658 41.76, 123.2 x 41.81, 123.5
    { 16, 25452, NoLogo, LineMetaDataContent::Subway, Color{0xe5703a} }, // 2 OSM: 7894597 WD: Q5933526 41.62, 123.4 x 41.96, 123.5
    { 64, 25483, NoLogo, LineMetaDataContent::Subway, Color{0xeb212f} }, // 1 OSM: 7895188 WD: Q15941872 25.98, 119.3 x 26.15, 119.4
    { 67, 25502, NoLogo, LineMetaDataContent::Subway, Color{0x8e8c13} }, // 13 OSM: 7895357 WD: Q6553065 23.08, 113.4 x 23.14, 113.6
    { 16, 25523, 25238, LineMetaDataContent::Subway, Color{0x0070ff} }, // 2 OSM: 7898299 WD: Q56277844 40.57, 22.93 x 40.65, 22.97
    { 3287, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xee1d23} }, // 512 OSM: 7904557 WD: Q3238950 43.67, -79.47 x 43.69, -79.39
    { 68, 25553, NoLogo, LineMetaDataContent::Subway, Color{0xdd00bb} }, // 3 OSM: 7908058 WD: Q5976456 38.92, 121.6 x 39.15, 122
    { 16, 25573, NoLogo, LineMetaDataContent::Subway, Color{0x0000ff} }, // 2 OSM: 7909740 WD: Q11087464 25.03, 102.7 x 25.12, 102.8
    { 64, 25593, NoLogo, LineMetaDataContent::Subway, Color{0xdb372b} }, // 1 OSM: 7909748 WD: Q11087462 24.83, 102.7 x 25.03, 102.9
    { 71, 25613, 12736, LineMetaDataContent::Subway, Color{0x4bbbb4} }, // S1 OSM: 7913272 WD: Q10946118 31.72, 118.8 x 31.97, 118.9
    { 225, 25634, 12736, LineMetaDataContent::Subway, Color{0xba84ac} }, // S3 OSM: 7913273 WD: Q10945835 31.91, 118.5 x 31.99, 118.8
    { 64, 25655, NoLogo, LineMetaDataContent::Subway, Color{0x00ab39} }, // 1 OSM: 7913936 WD: Q842103 22.53, 113.8 x 22.65, 114.1
    { 712, 25678, 20452, LineMetaDataContent::Subway, Color{0x3681b7} }, // A OSM: 7919001 WD: Q487643 37.44, 126.4 x 37.6, 127
    { 19, 25704, 20452, LineMetaDataContent::Subway, Color{0xea545d} }, // 8 OSM: 7919019 WD: Q45086 37.43, 127.1 x 37.64, 127.2
    { 27, 25727, 20452, LineMetaDataContent::Subway, Color{0xcd7c2f} }, // 6 OSM: 7919154 WD: Q92549 37.53, 126.9 x 37.62, 127.1
    { 418, NoLogo, 25750, LineMetaDataContent::Subway, Color{0x00a651} }, // M OSM: 7919553 WD: Q106336770 39.29, -76.78 x 39.41, -76.59
    { 3292, 25805, 20604, LineMetaDataContent::Subway, Color{0xed8b00} }, // OR OSM: 7919601 WD: Q4715683 38.88, -77.27 x 38.95, -76.87
    { 3299, 25822, 20604, LineMetaDataContent::Subway, Color{0xbf0d3e} }, // RD OSM: 7919630 WD: Q2193330 38.89, -77.17 x 39.12, -76.99
    { 3302, 25836, 20604, LineMetaDataContent::Subway, Color{0x919d9d} }, // SV OSM: 7919737 WD: Q4711838 38.88, -77.49 x 39.01, -76.84
    { 3305, 25853, 20604, LineMetaDataContent::Subway, Color{0x009cde} }, // BL OSM: 7919758 WD: Q2602185 38.77, -77.17 x 38.9, -76.84
    { 3308, 25868, 20604, LineMetaDataContent::Subway, Color{0x008000} }, // GR OSM: 7919786 WD: Q4715207 38.83, -77.03 x 39.01, -76.91
    { 47, 25884, 20452, LineMetaDataContent::Subway, Color{0x54640d} }, // 7 OSM: 7922930 WD: Q22910 37.48, 126.7 x 37.7, 127.1
    { 653, NoLogo, 25907, LineMetaDataContent::Subway, Color{0x62bb46} }, // Green OSM: 7924527 WD: Q55734262 25.68, -80.32 x 25.85, -80.2
    { 1446, NoLogo, 25907, LineMetaDataContent::Subway, Color{0xf78f1e} }, // Orange OSM: 7924528 WD: Q55734269 25.68, -80.31 x 25.81, -80.2
    { 283, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009933} }, // D OSM: 7925628 WD: Q3239098 48.57, 7.692 x 48.59, 7.816
    { 411, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf29400} }, // C OSM: 7925656 WD: Q2321331 48.55, 7.735 x 48.59, 7.773
    { 27, 25946, 18975, LineMetaDataContent::Subway, Color{0x0066a3} }, // 6 OSM: 7927182 WD: Q668977 50.83, 4.321 x 50.9, 4.37
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff7000} }, // 2 OSM: 7927236 WD: Q5017773 29.98, 31.2 x 30.12, 31.25
    { 524, 25967, 25988, LineMetaDataContent::Subway, Color{0x00dc3c} }, // L2 OSM: 7927568 WD: Q5986160 10.43, -67.01 x 10.51, -66.92
    { 528, 26007, 25988, LineMetaDataContent::Subway, Color{0x0887ff} }, // L3 OSM: 7927573 WD: Q21346332 10.43, -66.94 x 10.5, -66.88
    { 3311, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xced64d} }, // L1B OSM: 7928119 WD: Q107191177 37.99, -1.187 x 38.01, -1.161
    { 64, 26028, NoLogo, LineMetaDataContent::Subway, Color{0xf04e98} }, // 1 OSM: 7935038 WD: Q2295084 19.4, -99.2 x 19.43, -99.07
    { 411, 26049, NoLogo, LineMetaDataContent::RapidTransit, Color{0x58a738} }, // C OSM: 7935053 WD: Q2482571 33.91, -118.4 x 33.95, -118.1
    { 283, 26074, NoLogo, LineMetaDataContent::Subway, Color{0xa05da5} }, // D OSM: 7935318 WD: Q3916689 34.05, -118.3 x 34.06, -118.2
    { 9, 26099, NoLogo, LineMetaDataContent::Subway, Color{0x80ffff} }, // 4 OSM: 7935352 WD: Q2837181 19.4, -99.12 x 19.49, -99.1
    { 6, 26120, NoLogo, LineMetaDataContent::Subway, Color{0xffff11} }, // 5 OSM: 7935366 WD: Q1152238 19.41, -99.15 x 19.5, -99.07
    { 15, 26141, NoLogo, LineMetaDataContent::Subway, Color{0xb69764} }, // 12 OSM: 7935368 WD: Q5985548 19.29, -99.2 x 19.38, -99.01
    { 47, 26163, NoLogo, LineMetaDataContent::Subway, Color{0xff8000} }, // 7 OSM: 7935375 WD: Q929645 19.36, -99.2 x 19.51, -99.19
    { 712, 26184, NoLogo, LineMetaDataContent::Subway, Color{0xa3277d} }, // A OSM: 7935382 WD: Q3239049 19.35, -99.07 x 19.42, -98.96
    { 19, 26205, NoLogo, LineMetaDataContent::Subway, Color{0x30c090} }, // 8 OSM: 7935426 WD: Q1149545 19.35, -99.14 x 19.45, -99.06
    { 279, 26226, NoLogo, LineMetaDataContent::Subway, Color{0x408080} }, // B OSM: 7935433 WD: Q3239062 19.43, -99.16 x 19.53, -99.03
    { 16, 26247, NoLogo, LineMetaDataContent::Subway, Color{0x0080ff} }, // 2 OSM: 7935439 WD: Q1152993 19.34, -99.22 x 19.46, -99.13
    { 146, 26268, NoLogo, LineMetaDataContent::Subway, Color{0x804000} }, // 9 OSM: 7935444 WD: Q3239046 19.4, -99.19 x 19.42, -99.06
    { 68, 26289, NoLogo, LineMetaDataContent::Subway, Color{0xae9d27} }, // 3 OSM: 7935449 WD: Q945935 19.32, -99.18 x 19.5, -99.12
    { 27, 26310, NoLogo, LineMetaDataContent::Subway, Color{0xe00050} }, // 6 OSM: 7935454 WD: Q3238990 19.48, -99.2 x 19.51, -99.1
    { 3315, 26331, NoLogo, LineMetaDataContent::Subway, Color{0xdb5450} }, // PATCO OSM: 7939445 WD: Q2043730 39.83, -75.17 x 39.96, -75
    { 2177, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x233e99} }, // WTR OSM: 7940934 WD: Q7986701 39.95, -75.18 x 40.26, -74.82
    { 2779, NoLogo, 26346, LineMetaDataContent::Subway, Color{0xef3941} }, // NWK–WTC OSM: 7943869 WD: Q2673356 40.71, -74.16 x 40.74, -74.01
    { 3321, 26355, 26346, LineMetaDataContent::Subway, Color{0x009e58} }, // HOB–WTC OSM: 7943874 WD: Q2789573 40.71, -74.04 x 40.74, -74.01
    { 3331, NoLogo, 26346, LineMetaDataContent::Subway, Color{0x0082c6} }, // HOB–33 OSM: 7943885 WD: Q2319374 40.73, -74.03 x 40.75, -73.99
    { 3340, NoLogo, 26346, LineMetaDataContent::Subway, Color{0xfdb827} }, // JSQ–33 OSM: 7943962 WD: Q4993433 40.72, -74.06 x 40.75, -73.99
    { 64, 26369, NoLogo, LineMetaDataContent::Subway, Color{0xe77405} }, // 1 OSM: 7944061 WD: Q2333617 -22.98, -43.24 x -22.9, -43.17
    { 64, 26393, NoLogo, LineMetaDataContent::Subway, Color{0xc8102e} }, // 1 OSM: 7948593 WD: Q10921992 45.6, 126.6 x 45.79, 126.7
    { 68, 26417, NoLogo, LineMetaDataContent::Subway, Color{0xffc72c} }, // 3 OSM: 7949019 WD: Q10921994 45.69, 126.5 x 45.79, 126.7
    { 64, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xf50000} }, // 1 OSM: 7949047 WD: Q10916959 31.69, 117.3 x 31.92, 117.3
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x006bfa} }, // 2 OSM: 7949335 WD: Q10916960 31.82, 117.1 x 31.88, 117.5
    { 64, 26441, NoLogo, LineMetaDataContent::Subway, Color{0xe50011} }, // 1 OSM: 7949339 WD: Q15913092 43.79, 125.3 x 43.95, 125.3
    { 3349, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xf58220} }, // BSL OSM: 7950670 WD: Q837022 39.91, -75.17 x 40.04, -75.14
    { 64, 26461, NoLogo, LineMetaDataContent::Subway, Color{0x42b227} }, // 1 OSM: 7951024 WD: Q6379309 38.84, 121.5 x 39.02, 121.6
    { 3353, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0066ff} }, // MFL OSM: 7953598 WD: Q823251 39.95, -75.26 x 40.02, -75.08
    { 3357, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x84388a} }, // NHSL OSM: 7953621 WD: Q2205806 39.96, -75.35 x 40.11, -75.26
    { 15, 26481, NoLogo, LineMetaDataContent::Subway, Color{0x523e98} }, // 12 OSM: 7957874 WD: Q10938157 38.8, 121.1 x 38.86, 121.5
    { 3362, 26502, 9383, LineMetaDataContent::Subway, Color{0x007a33} }, // Μ1 OSM: 7963514 WD: Q6553095 37.94, 23.64 x 38.07, 23.81
    { 3366, 26526, 9383, LineMetaDataContent::Subway, Color{0xda291c} }, // Μ2 OSM: 7963569 WD: Q9295813 37.89, 23.69 x 38.02, 23.75
    { 64, NoLogo, 26550, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 7963913 WD: Q10318696 40.14, 44.47 x 40.2, 44.52
    { 19, 26568, NoLogo, LineMetaDataContent::Subway, Color{0x9dabaa} }, // 8 OSM: 7964884 WD: Q11124525 30.43, 114.3 x 30.68, 114.4
    { 3370, 26588, 24407, LineMetaDataContent::Tramway, Color{0x98cd37} }, // ML4 OSM: 7968999 WD: Q1637556 40.22, -3.773 x 40.25, -3.749
    { 3374, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x006400} }, // Tranvía OSM: 7981323 WD: Q926857 37.77, -3.79 x 37.8, -3.778
    { 3383, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0354a6} }, // DTL OSM: 7981644 WD: Q1663943 1.278, 103.7 x 1.413, 104
    { 3387, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x9016b2} }, // NEL OSM: 7981649 WD: Q1725116 1.265, 103.8 x 1.415, 103.9
    { 2745, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff9a00} }, // CCL OSM: 7981685 WD: Q2154003 1.265, 103.8 x 1.353, 103.9
    { 3391, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x009530} }, // EWL OSM: 7981689 WD: Q1895425 1.276, 103.6 x 1.373, 104
    { 1265, 26612, 24970, LineMetaDataContent::Subway, Color{0xbf0e1c} }, // M3 OSM: 7981707 WD: Q21526528 39.97, 32.55 x 39.99, 32.73
    { 8, 26646, 24970, LineMetaDataContent::Subway, Color{0xedaf2e} }, // M4 OSM: 7981756 WD: Q31193144 39.92, 32.84 x 40, 32.88
    { 360, 26680, 26706, LineMetaDataContent::Subway, Color{0x0000ff} }, // M1 OSM: 7981873 WD: Q3238655 38.39, 26.99 x 38.47, 27.23
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xed1c24} }, // 2 OSM: 7986215 WD: Q11103955 22.86, 113.7 x 23.09, 113.9
    { 3395, 26728, 26750, LineMetaDataContent::Subway, Color{0xff748c} }, // Pink Line OSM: 7989308 WD: Q17053988 26.88, 75.75 x 26.93, 75.83
    { 3405, 26772, NoLogo, LineMetaDataContent::Subway, Color{0x246b5b} }, // BTS Silom OSM: 7989387 WD: Q2634702 13.71, 100.5 x 13.75, 100.5
    { 3415, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf9c212} }, // U AVO OSM: 7993108 WD: Q25430027 40.64, -8.654 x 41.15, -8.564
    { 9, 26785, NoLogo, LineMetaDataContent::Tramway, Color{0xea4f80} }, // 4 OSM: 7999217 WD: Q2527775 50.79, 4.318 x 50.86, 4.363
    { 330, 26806, 8524, LineMetaDataContent::Tramway, Color{0xa12944} }, // 25 OSM: 7999338 WD: Q3238750 50.8, 4.358 x 50.87, 4.408
    { 692, 26828, 8524, LineMetaDataContent::Tramway, Color{0xf3c300} }, // 55 OSM: 7999374 WD: Q2236365 50.86, 4.358 x 50.88, 4.416
    { 811, 26850, 8524, LineMetaDataContent::Tramway, Color{0x91bee7} }, // 82 OSM: 7999733 WD: Q2534011 50.78, 4.29 x 50.87, 4.341
    { 68, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffcc00} }, // 3 OSM: 8000255 WD: Q13422345 14.54, 121 x 14.65, 121.1
    { 64, 26872, 26872, LineMetaDataContent::RapidTransit, Color{0x008000} }, // 1 OSM: 8000262 WD: Q4165607 14.48, 121 x 14.66, 121
    { 16, NoLogo, 26872, LineMetaDataContent::Subway, Color{0x800080} }, // 2 OSM: 8000265 WD: Q4165317 14.6, 121 x 14.63, 121.1
    { 3421, 26885, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfe8e10} }, // AG OSM: 8000298 WD: Q113297999 3.12, 101.7 x 3.186, 101.8
    { 146, 26906, NoLogo, LineMetaDataContent::Subway, Color{0x008000} }, // 9 OSM: 8000326 WD: Q6717618 2.982, 101.6 x 3.177, 101.8
    { 3424, 26927, NoLogo, LineMetaDataContent::RapidTransit, Color{0x721422} }, // SP OSM: 8000405 WD: Q113297920 2.994, 101.6 x 3.186, 101.7
    { 333, 26948, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe0115f} }, // KJ OSM: 8000461 WD: Q248445 2.996, 101.6 x 3.231, 101.7
    { 39, 26969, 26993, LineMetaDataContent::Subway, Color{0xff8c00} }, // T OSM: 8000572 WD: Q981826 43.03, 141.3 x 43.09, 141.5
    { 705, 27005, 26993, LineMetaDataContent::Subway, Color{0x008800} }, // N OSM: 8000575 WD: Q843793 42.99, 141.3 x 43.11, 141.4
    { 2237, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0377ae} }, // R6 OSM: 8005936 48.62, 21.19 x 48.71, 21.24
    { 3427, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x3a88bf} }, // 941 OSM: 8009538 WD: Q115756382 46.7, 9.386 x 46.98, 9.689
    { 68, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x55bace} }, // 3 OSM: 8013591 WD: Q3238909 48.68, 21.26 x 48.72, 21.3
    { 47, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x5cbf14} }, // 7 OSM: 8013592 WD: Q3239017 48.68, 21.24 x 48.73, 21.27
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x7477b0} }, // 4 OSM: 8013593 WD: Q3238941 48.68, 21.24 x 48.74, 21.27
    { 146, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf5d907} }, // 9 OSM: 8013594 WD: Q3239047 48.68, 21.23 x 48.74, 21.3
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xd2005c} }, // 2 OSM: 8013595 WD: Q3238807 48.72, 21.24 x 48.74, 21.27
    { 418, 27031, 27071, LineMetaDataContent::Subway, Color{0xf62e36} }, // M OSM: 8015940 WD: Q1147028 35.67, 139.6 x 35.73, 139.8
    { 712, 27099, NoLogo, LineMetaDataContent::Subway, Color{0xe85298} }, // A OSM: 8019854 WD: Q720653 35.58, 139.7 x 35.71, 139.8
    { 414, 27128, NoLogo, LineMetaDataContent::Subway, Color{0x6cbb5a} }, // S OSM: 8019866 WD: Q1374502 35.65, 139.4 x 35.8, 139.9
    { 548, 27158, NoLogo, LineMetaDataContent::Subway, Color{0xb6007a} }, // E OSM: 8019893 WD: Q384862 35.65, 139.6 x 35.76, 139.8
    { 679, 27184, NoLogo, LineMetaDataContent::Subway, Color{0x0079c2} }, // I OSM: 8019914 WD: Q1374506 35.63, 139.6 x 35.79, 139.8
    { 3431, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xaacd46} }, // G44 OSM: 8021111 WD: Q101110571 47.36, 18.87 x 47.5, 19.04
    { 3435, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00aff0} }, // S506 OSM: 8021112 WD: Q111752752 47.19, 21.58 x 47.52, 21.82
    { 3440, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xaacd46} }, // G50 OSM: 8021114 WD: Q109333265 47.17, 19.06 x 47.52, 20.18
    { 411, 27210, 27071, LineMetaDataContent::Subway, Color{0x00bb85} }, // C OSM: 8026069 WD: Q1075089 35.66, 139.7 x 35.78, 139.8
    { 705, 27247, 27071, LineMetaDataContent::Subway, Color{0x00ac9b} }, // N OSM: 8026071 WD: Q520772 35.63, 139.7 x 35.78, 139.8
    { 701, 27284, 27071, LineMetaDataContent::Subway, Color{0xff9500} }, // G OSM: 8026077 WD: Q1073046 35.66, 139.7 x 35.71, 139.8
    { 995, 27319, 27071, LineMetaDataContent::Subway, Color{0xc1a470} }, // Y OSM: 8026115 WD: Q787305 35.64, 139.6 x 35.79, 139.8
    { 39, 27360, 27071, LineMetaDataContent::Subway, Color{0x009bbf} }, // T OSM: 8026124 WD: Q1147054 35.66, 139.7 x 35.71, 140
    { 34, 27396, 27071, LineMetaDataContent::Subway, Color{0xb5b5ac} }, // H OSM: 8026149 WD: Q1196223 35.64, 139.7 x 35.75, 139.8
    { 3209, 27432, 27071, LineMetaDataContent::Subway, Color{0x8f76d6} }, // Z OSM: 8026157 WD: Q1376030 35.51, 139.4 x 36.11, 139.8
    { 337, 27471, 27071, LineMetaDataContent::Subway, Color{0x9c5e31} }, // F OSM: 8026161 WD: Q1332908 35.44, 139.4 x 36.05, 139.7
    { 414, 27511, NoLogo, LineMetaDataContent::Subway, Color{0xe44d93} }, // S OSM: 8028801 WD: Q1073354 34.64, 135.5 x 34.69, 135.6
    { 418, 27551, NoLogo, LineMetaDataContent::Subway, Color{0xe5171f} }, // M OSM: 8028805 WD: Q1192413 34.56, 135.5 x 34.83, 135.5
    { 679, 27588, NoLogo, LineMetaDataContent::Subway, Color{0xee7b1a} }, // I OSM: 8028826 WD: Q1066118 34.67, 135.5 x 34.76, 135.6
    { 586, 27628, NoLogo, LineMetaDataContent::Subway, Color{0x814721} }, // K OSM: 8028828 WD: Q1143250 34.64, 135.5 x 34.71, 135.5
    { 705, 27666, NoLogo, LineMetaDataContent::Subway, Color{0xa9cc51} }, // N OSM: 8028846 WD: Q284828 34.67, 135.5 x 34.72, 135.6
    { 995, 27720, NoLogo, LineMetaDataContent::Subway, Color{0x0078be} }, // Y OSM: 8028853 WD: Q1067748 34.61, 135.5 x 34.7, 135.5
    { 39, 27759, NoLogo, LineMetaDataContent::Subway, Color{0x522886} }, // T OSM: 8028879 WD: Q1142773 34.6, 135.5 x 34.75, 135.6
    { 586, 27797, 27822, LineMetaDataContent::Subway, Color{0x3cb371} }, // K OSM: 8030551 WD: Q762347 34.96, 135.8 x 35.06, 135.8
    { 39, 27841, 27822, LineMetaDataContent::Subway, Color{0xff4500} }, // T OSM: 8030553 WD: Q1143898 34.93, 135.7 x 35.01, 135.8
    { 414, 27863, 21580, LineMetaDataContent::Subway, Color{0xff0000} }, // S OSM: 8030762 WD: Q1132780 35.09, 136.9 x 35.17, 137
    { 34, 27908, 21580, LineMetaDataContent::Subway, Color{0xffffcc} }, // H OSM: 8030765 WD: Q1132799 35.14, 136.9 x 35.18, 137
    { 548, 27953, 21580, LineMetaDataContent::Subway, Color{0x8f76d6} }, // E OSM: 8030779 WD: Q1045061 35.09, 136.9 x 35.14, 136.9
    { 39, 27992, 21580, LineMetaDataContent::Subway, Color{0xadd8e6} }, // T OSM: 8030785 WD: Q1043806 35.12, 136.9 x 35.22, 137
    { 418, 28034, 21580, LineMetaDataContent::Subway, Color{0x8f76d6} }, // M OSM: 8031607 WD: Q906775 35.12, 136.9 x 35.2, 137
    { 645, 28073, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe9527d} }, // S9 OSM: 8033205 WD: Q110714397 41.35, 2.001 x 41.41, 2.148
    { 64, 28090, 28113, LineMetaDataContent::Subway, Color{0x0000ff} }, // 1 OSM: 8034179 WD: Q6427301 22.46, 88.34 x 22.65, 88.4
    { 64, NoLogo, 24274, LineMetaDataContent::Subway, Color{0x3281c4} }, // 1 OSM: 8037596 WD: Q19891160 12.97, 80.16 x 13.18, 80.31
    { 3444, 28143, 28166, LineMetaDataContent::Subway, Color{0x4169e1} }, // Blue Line OSM: 8037671 WD: Q1029921 28.55, 77.02 x 28.66, 77.38
    { 2679, 28187, 28166, LineMetaDataContent::Subway, Color{0x008000} }, // Green Line OSM: 8037672 WD: Q5602820 28.65, 76.91 x 28.7, 77.17
    { 3454, 28210, 28166, LineMetaDataContent::Subway, Color{0x553592} }, // Violet Line OSM: 8037706 WD: Q3634451 28.34, 77.21 x 28.67, 77.32
    { 3466, 28233, 28166, LineMetaDataContent::Subway, Color{0xffdf00} }, // Yellow Line OSM: 8037713 WD: Q795156 28.46, 77.07 x 28.75, 77.23
    { 3478, NoLogo, 28166, LineMetaDataContent::Subway, Color{0xff8c00} }, // AEx OSM: 8037716 WD: Q5253735 28.55, 77.04 x 28.64, 77.22
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xeb3d1a} }, // 2 OSM: 8040132 WD: Q21245979 22.72, 108.3 x 22.89, 108.4
    { 68, 28256, NoLogo, LineMetaDataContent::Subway, Color{0xfe4998} }, // 3 OSM: 8040148 WD: Q11087465 24.99, 102.6 x 25.05, 102.8
    { 3482, 28276, 28166, LineMetaDataContent::Subway, Color{0xcc338b} }, // Magenta Line OSM: 8051576 WD: Q19893471 28.54, 77.08 x 28.63, 77.34
    { 146, 28299, 28166, LineMetaDataContent::Subway, Color{0x838996} }, // 9 OSM: 8051593 WD: Q47100305 28.61, 76.98 x 28.62, 77.02
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xb5a08e} }, // 2 OSM: 8054142 WD: Q29221208 50.03, 14.34 x 50.1, 14.42
    { 67, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xdb9841} }, // 13 OSM: 8054850 WD: Q16655711 50.07, 14.43 x 50.08, 14.47
    { 22, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x9dc329} }, // 18 OSM: 8054951 WD: Q16655724 50.05, 14.39 x 50.11, 14.44
    { 239, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xa88cbf} }, // 17 OSM: 8055113 WD: Q16655722 50, 14.4 x 50.13, 14.46
    { 349, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x605047} }, // 23 OSM: 8055138 WD: Q29251387 50.07, 14.38 x 50.09, 14.43
    { 82, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf3987b} }, // 21 OSM: 8055260 WD: Q29229965 50, 14.39 x 50.07, 14.44
    { 153, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8dcdcc} }, // 14 OSM: 8057517 WD: Q16655713 50.05, 14.42 x 50.11, 14.48
    { 318, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x792522} }, // 26 OSM: 8057518 WD: Q16655738 50.05, 14.3 x 50.1, 14.54
    { 330, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe31e25} }, // 25 OSM: 8057519 WD: Q16655736 50.08, 14.32 x 50.11, 14.55
    { 255, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x1a5a7b} }, // 24 OSM: 8057520 WD: Q16655734 50.06, 14.42 x 50.13, 14.48
    { 251, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf1a1c5} }, // 20 OSM: 8057521 WD: Q16655730 50.03, 14.3 x 50.1, 14.41
    { 1038, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 91 OSM: 8060206 WD: Q122382126 50.07, 14.32 x 50.1, 14.49
    { 118, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf3987b} }, // 22 OSM: 8060656 WD: Q16655732 50.05, 14.32 x 50.09, 14.54
    { 1085, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xdc008f} }, // 99 OSM: 8060661 WD: Q29633417 50.06, 14.3 x 50.08, 14.51
    { 1035, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xdc008f} }, // 98 OSM: 8060662 WD: Q29633902 50.06, 14.3 x 50.09, 14.5
    { 11, 28322, 21781, LineMetaDataContent::Subway, Color{0x683064} }, // M5 OSM: 8061299 WD: Q1229371 40.98, 29.01 x 41.03, 29.23
    { 63, 28350, 5450, LineMetaDataContent::Subway, Color{0x82c0c0} }, // 11 OSM: 8119161 WD: Q617574 55.65, 37.44 x 55.8, 37.74
    { 47, 28375, NoLogo, LineMetaDataContent::LocalTrain, Color{0x139593} }, // 7 OSM: 8119877 WD: Q6151888 2.743, 101.7 x 3.134, 101.7
    { 27, 28396, NoLogo, LineMetaDataContent::LocalTrain, Color{0x800080} }, // 6 OSM: 8119880 WD: Q1431592 2.743, 101.7 x 3.134, 101.7
    { 289, 22532, NoLogo, LineMetaDataContent::Subway, Color{0x0000ff} }, // T1 OSM: 8120923 WD: Q56168307 10.34, -67.04 x 10.43, -67.01
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffaa00} }, // 4 OSM: 8125362 WD: Q114442363 51.2, 9.413 x 51.32, 9.722
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xcc00bb} }, // 5 OSM: 8125363 WD: Q114442364 51.25, 9.39 x 51.34, 9.502
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x773300} }, // 6 OSM: 8125364 WD: Q114442358 51.28, 9.444 x 51.34, 9.518
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x11bbbb} }, // 8 OSM: 8125365 WD: Q114442371 51.29, 9.425 x 51.33, 9.564
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000bb} }, // 2 OSM: 8126133 WD: Q114442360 51.25, 9.39 x 51.28, 9.448
    { 62, NoLogo, 14578, LineMetaDataContent::RapidTransit, Color{0xb72841} }, // S11 OSM: 8149205 WD: Q106368746 47.98, 12.85 x 48.04, 12.93
    { 225, NoLogo, 14578, LineMetaDataContent::RapidTransit, Color{0x22b24c} }, // S3 OSM: 8149206 WD: Q106368750 47.28, 12.79 x 47.84, 13.23
    { 59, NoLogo, 14578, LineMetaDataContent::RapidTransit, Color{0x0072bc} }, // S2 OSM: 8149207 WD: Q106368749 47.81, 12.97 x 47.97, 13.27
    { 71, NoLogo, 14578, LineMetaDataContent::RapidTransit, Color{0xb72841} }, // S1 OSM: 8149208 WD: Q106368744 47.81, 12.92 x 47.99, 13.05
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf2a0c5} }, // 12 OSM: 8154861 WD: Q122382727 49.77, 18.25 x 49.83, 18.32
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x38beef} }, // 8 OSM: 8157519 WD: Q122382724 49.82, 18.16 x 49.85, 18.29
    { 3495, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfdc500} }, // U CIS-CSO OSM: 8158317 WD: Q124221027 38.69, -9.418 x 38.71, -9.145
    { 3505, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfdc500} }, // U CSO-CIS OSM: 8158318 WD: Q124221027 38.69, -9.418 x 38.71, -9.145
    { 3515, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfdc500} }, // Cascais OSM: 8161652 WD: Q124221027 38.69, -9.418 x 38.71, -9.145
    { 3523, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfdc500} }, // U OEI-CSO OSM: 8161653 WD: Q124221027 38.69, -9.32 x 38.71, -9.145
    { 3533, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfdc500} }, // U CSO-OEI OSM: 8161654 WD: Q124221027 38.69, -9.32 x 38.71, -9.145
    { 3543, 28417, NoLogo, LineMetaDataContent::RapidTransit, Color{0x999999} }, // 浦江 OSM: 8167022 WD: Q29704153 31.03, 121.5 x 31.06, 121.5
    { 64, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf7a707} }, // 1 OSM: 8177074 WD: Q122382717 49.77, 18.25 x 49.85, 18.29
    { 2299, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0377ae} }, // R4 OSM: 8196259 48.62, 21.19 x 48.73, 21.25
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xea7b08} }, // 6 OSM: 8196338 WD: Q3238992 48.7, 21.23 x 48.73, 21.27
    { 2292, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0377ae} }, // R3 OSM: 8197830 48.62, 21.19 x 48.74, 21.25
    { 3195, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0377ae} }, // R7 OSM: 8197872 48.62, 21.19 x 48.73, 21.24
    { 725, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // T2 OSM: 8209896 WD: Q16655789 47.99, 0.1929 x 48.02, 0.2359
    { 289, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xeb001b} }, // T1 OSM: 8209897 WD: Q3239229 47.96, 0.152 x 48.02, 0.2304
    { 653, NoLogo, 3321, LineMetaDataContent::RapidTransit, Color{0x009933} }, // Green OSM: 8212097 WD: Q10318779 54.9, -1.711 x 55.04, -1.382
    { 279, 28438, NoLogo, LineMetaDataContent::Subway, Color{0xe3131b} }, // B OSM: 8219357 WD: Q2778331 34.05, -118.4 x 34.17, -118.2
    { 372, NoLogo, 11172, LineMetaDataContent::RapidTransit, Color{0xffe800} }, // Yellow OSM: 8237627 WD: Q54874971 38, -121.9 x 38.02, -121.8
    { 3395, NoLogo, 28166, LineMetaDataContent::Subway, Color{0xfc8eac} }, // Pink Line OSM: 8242438 WD: Q19891094 28.57, 77.12 x 28.72, 77.32
    { 68, 28463, 20452, LineMetaDataContent::Subway, Color{0xbb8c00} }, // 3 OSM: 8247017 WD: Q86468 35.17, 129 x 35.21, 129.1
    { 9, NoLogo, 16935, LineMetaDataContent::Tramway, Color{0xfc751c} }, // 4 OSM: 8255319 WD: Q2735863 52.04, 4.245 x 52.08, 4.543
    { 68, NoLogo, 16935, LineMetaDataContent::Tramway, Color{0x703276} }, // 3 OSM: 8255320 WD: Q3056105 52.05, 4.228 x 52.08, 4.518
    { 64, 28486, 20452, LineMetaDataContent::Subway, Color{0xf06a00} }, // 1 OSM: 8255698 WD: Q86356 35.05, 129 x 35.28, 129.1
    { 16, 28509, 20452, LineMetaDataContent::Subway, Color{0x81bf48} }, // 2 OSM: 8258658 WD: Q86467 35.13, 129 x 35.34, 129.2
    { 3550, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0054a6} }, // 311 OSM: 8272972 WD: Q85977451 35.16, 129.1 x 35.54, 129.4
    { 55, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x5e2d91} }, // S8 OSM: 8294822 WD: Q7388382 47.2, 8.519 x 47.5, 8.782
    { 46, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0xfebe10} }, // S7 OSM: 8294823 WD: Q7388366 47.22, 8.511 x 47.5, 8.824
    { 47, 28532, NoLogo, LineMetaDataContent::Subway, Color{0x6ad1e3} }, // 7 OSM: 8297146 WD: Q11074646 30.61, 104 x 30.7, 104.1
    { 68, 28542, NoLogo, LineMetaDataContent::Subway, Color{0xd40f7d} }, // 3 OSM: 8297273 WD: Q8985154 30.54, 103.9 x 30.82, 104.2
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x008000} }, // 2 OSM: 8297697 WD: Q84767109 17.37, 78.48 x 17.45, 78.5
    { 64, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 8297698 WD: Q54366523 17.35, 78.37 x 17.5, 78.55
    { 16, 28552, NoLogo, LineMetaDataContent::Subway, Color{0xff5c39} }, // 2 OSM: 8298113 WD: Q4391357 30.56, 104 x 30.76, 104.3
    { 9, 28562, NoLogo, LineMetaDataContent::Subway, Color{0x44af52} }, // 4 OSM: 8298132 WD: Q11074645 30.64, 103.8 x 30.69, 104.2
    { 75, 28572, NoLogo, LineMetaDataContent::Subway, Color{0x003da5} }, // 10 OSM: 8298254 WD: Q11074644 30.41, 103.8 x 30.63, 104
    { 15, 28583, NoLogo, LineMetaDataContent::Subway, Color{0xffcc00} }, // 12 OSM: 8298259 WD: Q17053935 2.931, 101.6 x 3.215, 101.7
    { 64, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 8299497 WD: Q18128813 26.77, 80.88 x 26.89, 81
    { 3554, 28605, NoLogo, LineMetaDataContent::Subway, Color{0xf2a900} }, // 环 OSM: 8300611 WD: Q15915083 29.5, 106.4 x 29.61, 106.6
    { 6, 28630, NoLogo, LineMetaDataContent::Subway, Color{0x00a3e0} }, // 5 OSM: 8300867 WD: Q15912187 29.41, 106.4 x 29.76, 106.6
    { 75, 28655, NoLogo, LineMetaDataContent::Subway, Color{0x3c1053} }, // 10 OSM: 8300873 WD: Q15914281 29.51, 106.5 x 29.75, 106.7
    { 3558, 28680, 4547, LineMetaDataContent::Tramway, Color{0xe1261c} }, // 西郊 OSM: 8303696 WD: Q3400451 39.97, 116.2 x 39.99, 116.3
    { 3565, 28705, 226, LineMetaDataContent::RapidTransit, Color{0x56033a} }, // S 6 OSM: 8303864 WD: Q63217185 51.06, 12.37 x 51.4, 12.7
    { 1888, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x799ccd} }, // S21 OSM: 8303997 WD: Q7388225 47.38, 8.47 x 47.44, 8.55
    { 16, 28730, 28764, LineMetaDataContent::Subway, Color{0xfdb935} }, // 2 OSM: 8306848 WD: Q28412021 36.62, 116.9 x 36.71, 117.2
    { 1865, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0xf9aa8f} }, // S41 OSM: 8306928 WD: Q15088595 47.49, 8.535 x 47.53, 8.724
    { 3569, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x75593b} }, // S27 OSM: 8308820 WD: Q106451356 47.47, 8.22 x 47.62, 8.308
    { 64, 28784, NoLogo, LineMetaDataContent::Subway, Color{0x0067a1} }, // 1 OSM: 8309087 WD: Q5963161 30.57, 114.1 x 30.71, 114.3
    { 3573, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0xbda07c} }, // S15 OSM: 8309090 WD: Q7388191 47.22, 8.368 x 47.51, 8.864
    { 52, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x48b4ca} }, // S5 OSM: 8311264 WD: Q7388335 47.17, 8.429 x 47.41, 8.864
    { 3577, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0099aa} }, // JRL OSM: 8312419 WD: Q3391052 1.312, 103.7 x 1.386, 103.7
    { 3581, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x000000} }, // WES OSM: 8313440 WD: Q12072781 45.31, -122.8 x 45.49, -122.8
    { 16, 28804, NoLogo, LineMetaDataContent::Subway, Color{0xff7300} }, // 2 OSM: 8323745 WD: Q2657097 30.12, 120 x 30.36, 120.3
    { 64, 28824, NoLogo, LineMetaDataContent::Subway, Color{0x1590ca} }, // 1 OSM: 8324096 WD: Q10946020 29.84, 121.4 x 29.92, 121.9
    { 26, 28845, 4547, LineMetaDataContent::Subway, Color{0x6da843} }, // 16 OSM: 8324250 WD: Q6553080 39.83, 116.1 x 40.07, 116.3
    { 2116, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x0588cc} }, // S30 OSM: 8327718 WD: Q7388265 47.5, 8.722 x 47.59, 9.106
    { 3585, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x007e94} }, // S26 OSM: 8327719 WD: Q2321332 47.26, 8.724 x 47.51, 8.934
    { 751, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x7a4c29} }, // S13 OSM: 8327720 WD: Q7388186 47.13, 8.675 x 47.23, 8.75
    { 64, NoLogo, 28866, LineMetaDataContent::Subway, Color{0xec7000} }, // 1 OSM: 8337169 WD: Q15953685 24.45, 118 x 24.66, 118.1
    { 579, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00a3e0} }, // MMTS OSM: 8337461 WD: Q1952301 17.26, 78.28 x 17.64, 78.68
    { 71, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffbabe} }, // S1 OSM: 8340382 WD: Q125989601 49.82, 17.91 x 49.93, 18.21
    { 3589, 28886, NoLogo, LineMetaDataContent::LocalTrain, Color{} }, // RB 32 OSM: 8347311 WD: Q113258586 48.73, 12.19 x 48.91, 12.69
    { 270, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x7b2c1c} }, // 41 OSM: 8350410 WD: Q29229288 50.09, 14.39 x 50.1, 14.43
    { 329, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0xb41e8e} }, // S25 OSM: 8355962 WD: Q18391643 46.92, 8.519 x 47.38, 9.084
    { 1470, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0xffc700} }, // S 8 OSM: 8376374 WD: Q115244230 51.04, 13.72 x 51.27, 14.09
    { 456, 28903, NoLogo, LineMetaDataContent::LocalTrain, Color{} }, // RB 59 OSM: 8377332 WD: Q110188017 47.87, 12.64 x 47.93, 12.73
    { 3595, 28920, NoLogo, LineMetaDataContent::Subway, Color{0x939598} }, // JL OSM: 8391469 WD: Q5365768 35.75, 139.8 x 35.9, 140.1
    { 3598, 19539, NoLogo, LineMetaDataContent::RapidTransit, Color{0x802168} }, // C-4 OSM: 8394326 WD: Q43264468 43.19, -3.198 x 43.27, -2.926
    { 590, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf3d9a6} }, // L OSM: 8400989 WD: Q123244737 43.04, -87.91 x 43.04, -87.9
    { 3602, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008752} }, // Rosewood OSM: 8409183 WD: Q6065655 -27.64, 152.6 x -27.46, 153
    { 47, 28942, 2034, LineMetaDataContent::Tramway, Color{0x667ab3} }, // 7 OSM: 8426298 WD: Q104867986 49.43, 11.08 x 49.45, 11.09
    { 64, 28959, 28166, LineMetaDataContent::Subway, Color{0xff4040} }, // 1 OSM: 8429148 WD: Q3278367 28.67, 77.1 x 28.72, 77.42
    { 2137, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x73b3d7} }, // S35 OSM: 8437405 WD: Q7388272 47.46, 8.724 x 47.51, 9.043
    { 1092, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x32a384} }, // S29 OSM: 8437511 WD: Q7388235 47.5, 8.714 x 47.66, 8.856
    { 273, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0xad99c9} }, // S40 OSM: 8437648 WD: Q7388295 47.13, 8.682 x 47.22, 8.817
    { 3611, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x198ea3} }, // S17 OSM: 8437734 WD: Q115195960 47.34, 8.27 x 47.41, 8.406
    { 3615, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // ExpressTram OSM: 8438647 WD: Q5421647 42.2, -83.36 x 42.21, -83.35
    { 3627, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfc0200} }, // ATS OSM: 8438739 WD: Q2828747 41.97, -87.91 x 41.99, -87.88
    { 9, 28982, NoLogo, LineMetaDataContent::Subway, Color{0x0072ce} }, // 4 OSM: 8439223 WD: Q6112249 31.13, 120.6 x 31.41, 120.7
    { 16, 29003, NoLogo, LineMetaDataContent::Subway, Color{0xe60000} }, // 2 OSM: 8439253 WD: Q1054280 31.25, 120.6 x 31.44, 120.8
    { 3631, 29024, NoLogo, LineMetaDataContent::LocalTrain, Color{0xffffff} }, // RB 57 OSM: 8442834 WD: Q108409635 47.71, 11.53 x 48.14, 11.76
    { 732, 29041, NoLogo, LineMetaDataContent::LocalTrain, Color{0xffffff} }, // RB 56 OSM: 8442835 WD: Q108409632 47.68, 11.53 x 48.14, 11.71
    { 372, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffff00} }, // Yellow OSM: 8464133 WD: Q55683262 9.006, 7.272 x 9.057, 7.472
    { 174, 29063, 14825, LineMetaDataContent::Subway, Color{0x00adef} }, // 52 OSM: 8466672 WD: Q2466115 52.34, 4.874 x 52.4, 4.933
    { 3637, 29102, 3863, LineMetaDataContent::Tramway, Color{0xe65e37} }, // T11 OSM: 8467024 WD: Q1083349 48.93, 2.302 x 48.96, 2.424
    { 2077, 29136, NoLogo, LineMetaDataContent::RapidTransit, Color{0x9b26b6} }, // A2 OSM: 8467447 WD: Q17853551 37.91, 23.71 x 38.07, 23.95
    { 2198, 29171, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffcd00} }, // A1 OSM: 8467448 WD: Q47477364 37.91, 23.64 x 38.07, 23.95
    { 3641, 29206, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00a3e0} }, // A4 OSM: 8467516 WD: Q20552930 37.91, 22.73 x 38.09, 23.74
    { 3644, 29241, 4547, LineMetaDataContent::Subway, Color{0xd85f26} }, // 25S OSM: 8469061 WD: Q8048350 39.7, 116 x 39.73, 116.1
    { 289, NoLogo, 29267, LineMetaDataContent::Tramway, Color{0x254395} }, // T1 OSM: 8475071 WD: Q55693065 43.75, 11.17 x 43.8, 11.25
    { 146, NoLogo, 29292, LineMetaDataContent::Subway, Color{0x063a91} }, // 9 OSM: 8478970 WD: Q3125123 39.01, 117.2 x 39.14, 117.7
    { 584, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7a121c} }, // SYK OSM: 8489646 WD: Q124521879 -1.361, 36.83 x -1.289, 36.91
    { 3648, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7a121c} }, // KKY OSM: 8489647 WD: Q124527546 -1.315, 36.64 x -1.115, 36.83
    { 3652, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7a121c} }, // RIU OSM: 8489648 WD: Q124536401 -1.301, 36.83 x -1.15, 36.96
    { 68, NoLogo, 29292, LineMetaDataContent::Subway, Color{0x128bbe} }, // 3 OSM: 8489969 WD: Q6553117 39.05, 117.1 x 39.24, 117.3
    { 16, NoLogo, 29292, LineMetaDataContent::Subway, Color{0xece114} }, // 2 OSM: 8489970 WD: Q6553104 39.13, 117.1 x 39.16, 117.4
    { 64, 29309, 29292, LineMetaDataContent::Subway, Color{0xbd0016} }, // 1 OSM: 8489971 WD: Q6126171 39, 117.1 x 39.21, 117.4
    { 27, NoLogo, 29292, LineMetaDataContent::Subway, Color{0x9f216f} }, // 6 OSM: 8490135 WD: Q10940001 39.04, 117.1 x 39.21, 117.3
    { 9, 29339, NoLogo, LineMetaDataContent::RapidTransit, Color{0x009049} }, // 4 OSM: 8499866 WD: Q109046034 36.8, 10.06 x 36.82, 10.19
    { 3656, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 201 OSM: 8505446 52.37, 16.91 x 52.46, 16.98
    { 153, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xaa6133} }, // 14 OSM: 8505950 52.38, 16.88 x 52.46, 16.92
    { 15, 29363, NoLogo, LineMetaDataContent::Tramway, Color{0xc597cd} }, // 12 OSM: 8505951 WD: Q108000820 52.37, 16.91 x 52.46, 16.95
    { 63, 29402, NoLogo, LineMetaDataContent::Tramway, Color{0x5ec79f} }, // 11 OSM: 8505952 WD: Q108000659 52.37, 16.89 x 52.44, 16.96
    { 3660, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf166a7} }, // 42X OSM: 8506177 58.9, 17.86 x 59.63, 18.16
    { 3664, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // TGM OSM: 8510421 WD: Q1306749 36.8, 10.19 x 36.88, 10.34
    { 6, 29441, NoLogo, LineMetaDataContent::RapidTransit, Color{0x009049} }, // 5 OSM: 8510688 WD: Q109046037 36.8, 10.12 x 36.84, 10.18
    { 68, 29465, NoLogo, LineMetaDataContent::RapidTransit, Color{0x009049} }, // 3 OSM: 8510789 WD: Q109046031 36.8, 10.13 x 36.83, 10.18
    { 16, 29489, NoLogo, LineMetaDataContent::RapidTransit, Color{0x009049} }, // 2 OSM: 8511768 WD: Q109046023 36.81, 10.18 x 36.86, 10.2
    { 178, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf166a7} }, // 44 OSM: 8518402 59.2, 17.81 x 59.45, 18.07
    { 3668, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf166a7} }, // 43X OSM: 8518405 58.9, 17.81 x 59.45, 18.16
    { 62, 29513, 226, LineMetaDataContent::RapidTransit, Color{0x59b243} }, // S11 OSM: 8525098 WD: Q107020232 48.59, 8.861 x 48.8, 9.242
    { 64, 29550, 29292, LineMetaDataContent::Tramway, Color{0x8fc31f} }, // 1 OSM: 8548848 WD: Q1659593 39.02, 117.7 x 39.09, 117.7
    { 590, 29573, 3863, LineMetaDataContent::RapidTransit, Color{0x7577c0} }, // L OSM: 8557335 WD: Q93379 48.81, 2.011 x 49.05, 2.324
    { 146, 29607, 8524, LineMetaDataContent::Tramway, Color{0xc44f97} }, // 9 OSM: 8624098 WD: Q28609936 50.86, 4.275 x 50.9, 4.332
    { 3672, 29628, 20452, LineMetaDataContent::Subway, Color{0x0c8e72} }, // GC OSM: 8656365 WD: Q20192 37.58, 127 x 37.88, 127.7
    { 71, 29648, 29662, LineMetaDataContent::RapidTransit, Color{0xee333e} }, // S1 OSM: 8661616 WD: Q46365 45.31, 9.032 x 45.62, 9.498
    { 59, 29684, 29662, LineMetaDataContent::RapidTransit, Color{0x00aa8a} }, // S2 OSM: 8661617 WD: Q1160540 45.43, 9.14 x 45.65, 9.238
    { 225, 29698, 29662, LineMetaDataContent::RapidTransit, Color{0xab2a42} }, // S3 OSM: 8662821 WD: Q600028 45.47, 9.032 x 45.62, 9.176
    { 314, 29712, 29662, LineMetaDataContent::RapidTransit, Color{0x82c44e} }, // S4 OSM: 8662822 WD: Q1160571 45.47, 9.133 x 45.67, 9.175
    { 52, 29726, 29662, LineMetaDataContent::RapidTransit, Color{0xf79647} }, // S5 OSM: 8662846 WD: Q1159300 45.46, 8.789 x 45.82, 9.591
    { 298, 29740, 29662, LineMetaDataContent::RapidTransit, Color{0xf3d035} }, // S6 OSM: 8662847 WD: Q1160580 45.43, 8.625 x 45.53, 9.591
    { 3675, 15396, 15216, LineMetaDataContent::Subway, Color{0x009fe3} }, // L10 Sud OSM: 8663605 WD: Q1577033 41.32, 2.113 x 41.38, 2.148
    { 3683, 29754, 20452, LineMetaDataContent::Subway, Color{0x73c7a6} }, // G·J OSM: 8667957 WD: Q18233162 37.47, 126.7 x 37.9, 127.6
    { 590, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffff00} }, // L OSM: 8668342 WD: Q48770897 39.74, -105 x 39.76, -105
    { 3688, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 202 OSM: 8671531 52.38, 16.91 x 52.46, 17
    { 546, 29780, NoLogo, LineMetaDataContent::Tramway, Color{0xff7f00} }, // 24E OSM: 8682141 WD: Q63230204 38.71, -9.162 x 38.73, -9.143
    { 64, 29793, 20452, LineMetaDataContent::Subway, Color{0x005daa} }, // 1 OSM: 8691899 WD: Q20280 36.77, 126.6 x 38.1, 127.2
    { 3692, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008144} }, // 902 OSM: 8708438 WD: Q5060656 44.95, -93.28 x 44.98, -93.09
    { 26, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf9b000} }, // 16 OSM: 8712352 WD: Q110253214 52.32, 9.722 x 52.38, 9.837
    { 22, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe4003a} }, // 18 OSM: 8712368 WD: Q107242125 52.33, 9.734 x 52.39, 9.804
    { 3696, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa4228e} }, // 750 OSM: 8718106 40.23, -112 x 41.23, -111.7
    { 3700, 29816, 20452, LineMetaDataContent::Subway, Color{0x8fc31e} }, // 321 OSM: 8725316 WD: Q109116480 37.3, 126.8 x 37.68, 126.8
    { 3705, 29854, NoLogo, LineMetaDataContent::Tramway, Color{0x808080} }, // 720 OSM: 8725393 WD: Q7634842 40.72, -111.9 x 40.72, -111.9
    { 581, 29874, NoLogo, LineMetaDataContent::Tramway, Color{0x9bb14f} }, // TS OSM: 8729960 WD: Q23308659 33.41, -111.9 x 33.43, -111.9
    { 3709, 29899, 20452, LineMetaDataContent::Subway, Color{0x0054a6} }, // GG OSM: 8735483 WD: Q24044969 37.26, 127.1 x 37.41, 127.6
    { 64, NoLogo, 29919, LineMetaDataContent::Subway, Color{0x10069f} }, // 1 OSM: 8742572 WD: Q17498490 43.76, 87.47 x 43.92, 87.62
    { 289, 29932, 29932, LineMetaDataContent::Tramway, Color{0x008000} }, // T1 OSM: 8753522 WD: Q2661356 43.24, -2.952 x 43.27, -2.905
    { 3712, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x409337} }, // PKM3 OSM: 8780894 WD: Q112660402 52.09, 16.11 x 52.81, 17.22
    { 15, 29949, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 12 OSM: 8823281 WD: Q1485440 47.55, 19.09 x 47.57, 19.13
    { 3717, NoLogo, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 56A OSM: 8823482 WD: Q21996124 47.48, 18.96 x 47.54, 19.05
    { 3721, 29973, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 59A OSM: 8823524 WD: Q1491496 47.48, 19 x 47.51, 19.02
    { 3725, NoLogo, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 59B OSM: 8823525 WD: Q22810651 47.48, 18.96 x 47.54, 19.02
    { 39, 29998, NoLogo, LineMetaDataContent::RapidTransit, Color{0xd40843} }, // T OSM: 8826111 WD: Q1755582 37.71, -122.4 x 37.8, -122.4
    { 55, 30022, 29662, LineMetaDataContent::RapidTransit, Color{0xf8b1b0} }, // S8 OSM: 8840314 WD: Q1160824 45.48, 9.183 x 45.86, 9.435
    { 751, 30036, 29662, LineMetaDataContent::RapidTransit, Color{0x99642e} }, // S13 OSM: 8840315 WD: Q1160881 45.19, 9.081 x 45.58, 9.245
    { 645, 30051, 29662, LineMetaDataContent::RapidTransit, Color{0xa0499a} }, // S9 OSM: 8840324 WD: Q56920 45.4, 8.956 x 45.65, 9.274
    { 62, 30065, 29662, LineMetaDataContent::RapidTransit, Color{0x9d91c5} }, // S11 OSM: 8840325 WD: Q1160879 45.48, 9.028 x 45.83, 9.274
    { 68, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xffa500} }, // 3 OSM: 8857387 24.57, 46.54 x 24.73, 46.86
    { 27, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x800080} }, // 6 OSM: 8857388 WD: Q106740378 24.7, 46.64 x 24.81, 46.83
    { 9, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xf8eb00} }, // 4 OSM: 8857389 WD: Q106740374 24.77, 46.64 x 24.96, 46.72
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf5a300} }, // 12 OSM: 8871002 WD: Q16655708 46.17, 6.129 x 46.2, 6.207
    { 2599, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // SC OSM: 8888446 43.03, 141.3 x 43.06, 141.4
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf37b24} }, // 4 OSM: 9063210 47.1, 37.51 x 47.12, 37.65
    { 3729, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // Circular OSM: 9084313 WD: Q8048613 16.78, 96.09 x 16.94, 96.18
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xa68351} }, // 2 OSM: 9112026 WD: Q16854978 47.54, 7.571 x 47.59, 7.651
    { 68, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x324ea1} }, // 3 OSM: 9118502 WD: Q16854981 47.55, 7.553 x 47.59, 7.631
    { 64, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x835237} }, // 1 OSM: 9118510 WD: Q16854970 47.55, 7.573 x 47.57, 7.608
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0072bc} }, // 6 OSM: 9128621 WD: Q16854982 47.55, 7.537 x 47.59, 7.656
    { 3738, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff6319} }, // Long Beach OSM: 9129728 WD: Q6672281 40.59, -73.99 x 40.75, -73.65
    { 3749, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x6e3219} }, // Far Rockaway OSM: 9129758 WD: Q5434607 40.61, -73.98 x 40.7, -73.7
    { 47, 30080, NoLogo, LineMetaDataContent::Subway, Color{0x8b0000} }, // 7 OSM: 9140122 WD: Q6749694 14.65, 121 x 14.77, 121.1
    { 3762, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff6600} }, // MSC 711 OSM: 9165725 14.2, 121 x 14.62, 121.2
    { 3770, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // MNC OSM: 9165727 14.61, 121 x 14.67, 121
    { 3774, 30103, NoLogo, LineMetaDataContent::LocalTrain, Color{} }, // RE 22 OSM: 9173483 WD: Q108179529 48.33, 11.68 x 49.01, 12.22
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf171ab} }, // 8 OSM: 9173651 WD: Q16854983 47.55, 7.557 x 47.59, 7.608
    { 3598, 30120, 3759, LineMetaDataContent::RapidTransit, Color{0x00289c} }, // C-4 OSM: 9174513 WD: Q1919488 40.24, -3.778 x 40.65, -3.634
    { 75, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfeca0a} }, // 10 OSM: 9177454 WD: Q7885420 47.48, 7.459 x 47.55, 7.62
    { 3780, 30138, 3759, LineMetaDataContent::RapidTransit, Color{0xffa500} }, // C-9 OSM: 9181540 WD: Q8880294 40.74, -4.066 x 40.82, -3.963
    { 2699, 19295, 3759, LineMetaDataContent::RapidTransit, Color{0x008a29} }, // C-2 OSM: 9187669 WD: Q2287356 40.38, -3.694 x 40.64, -3.181
    { 153, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf58220} }, // 14 OSM: 9190891 WD: Q16854972 47.52, 7.587 x 47.57, 7.694
    { 68, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 3 OSM: 9192778 WD: Q104189065 50.81, 12.92 x 50.84, 12.93
    { 157, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00a54f} }, // 15 OSM: 9193744 WD: Q89415715 47.53, 7.587 x 47.56, 7.6
    { 26, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xa6ce39} }, // 16 OSM: 9196819 WD: Q16854975 47.53, 7.584 x 47.56, 7.605
    { 239, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00aeef} }, // 17 OSM: 9201222 WD: Q16854977 47.48, 7.545 x 47.58, 7.593
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf5b85a} }, // 6 OSM: 9217293 WD: Q122781782 45.74, 21.22 x 45.76, 21.25
    { 424, 30156, NoLogo, LineMetaDataContent::RapidTransit, Color{0x1662b8} }, // U OSM: 9221982 WD: Q1191079 35.62, 139.8 x 35.67, 139.8
    { 161, NoLogo, 30183, LineMetaDataContent::RapidTransit, Color{0xff1493} }, // 19 OSM: 9234808 WD: Q154730 47.39, 7.729 x 47.49, 7.773
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xd64560} }, // 2 OSM: 9235815 WD: Q106996888 47.26, 11.35 x 47.28, 11.44
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8b445b} }, // 5 OSM: 9235816 WD: Q106996949 47.26, 11.34 x 47.28, 11.46
    { 3784, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // СТ-2 OSM: 9244973 WD: Q107191059 48.68, 44.47 x 48.8, 44.6
    { 367, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x002666} }, // Blue OSM: 9248096 WD: Q4929369 38.45, -121.5 x 38.65, -121.4
    { 653, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x006633} }, // Green OSM: 9248097 WD: Q16000108 38.57, -121.5 x 38.6, -121.5
    { 1892, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffba00} }, // Gold OSM: 9248098 WD: Q5578775 38.55, -121.5 x 38.68, -121.2
    { 3791, 30206, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff69b4} }, // NT OSM: 9253571 WD: Q910032 35.73, 139.8 x 35.81, 139.8
    { 3801, 30238, NoLogo, LineMetaDataContent::Tramway, Color{0xd85b81} }, // SA OSM: 9254426 WD: Q1064795 35.71, 139.7 x 35.75, 139.8
    { 3804, NoLogo, 28166, LineMetaDataContent::Subway, Color{0x00ffff} }, // Aqua Line OSM: 9256785 WD: Q41668068 28.44, 77.37 x 28.59, 77.55
    { 2289, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0377ae} }, // R2 OSM: 9266121 48.62, 21.19 x 48.71, 21.3
    { 2302, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0377ae} }, // R8 OSM: 9266263 48.62, 21.19 x 48.71, 21.27
    { 697, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0377ae} }, // R1 OSM: 9273350 48.62, 21.19 x 48.72, 21.27
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0377ae} }, // 5 OSM: 9274837 WD: Q3238964 48.7, 21.24 x 48.72, 21.27
    { 3814, 30267, NoLogo, LineMetaDataContent::RapidTransit, Color{0xcc3333} }, // exo1 OSM: 9288759 WD: Q3239247 45.39, -74.14 x 45.5, -73.57
    { 1624, 30312, NoLogo, LineMetaDataContent::RapidTransit, Color{0xda0442} }, // TY OSM: 9288983 WD: Q1192468 35.47, 139.6 x 35.66, 139.7
    { 3819, 30337, NoLogo, LineMetaDataContent::RapidTransit, Color{0x808080} }, // exo4 OSM: 9298215 WD: Q3239087 45.36, -73.66 x 45.5, -73.51
    { 725, NoLogo, 29267, LineMetaDataContent::Tramway, Color{0x5d3988} }, // T2 OSM: 9298542 WD: Q61670436 43.77, 11.2 x 43.8, 11.25
    { 63, 30382, NoLogo, LineMetaDataContent::Subway, Color{0x6a1d44} }, // 11 OSM: 9318442 WD: Q4698920 22.52, 113.8 x 22.79, 114.1
    { 3824, 30406, NoLogo, LineMetaDataContent::RapidTransit, Color{0x009900} }, // exo2 OSM: 9326028 WD: Q3239074 45.45, -74 x 45.77, -73.57
    { 3829, 30451, NoLogo, LineMetaDataContent::Subway, Color{0x3564af} }, // SR OSM: 9336150 WD: Q1065949 35.78, 139.7 x 35.89, 139.8
    { 3832, 30483, NoLogo, LineMetaDataContent::RapidTransit, Color{0xef473d} }, // SY OSM: 9338171 WD: Q842520 35.77, 139.4 x 35.77, 139.4
    { 3835, 30502, NoLogo, LineMetaDataContent::RapidTransit, Color{0x009cd2} }, // MG OSM: 9340970 WD: Q283861 35.55, 139.6 x 35.63, 139.7
    { 3838, 30527, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf18c43} }, // OM OSM: 9341650 WD: Q384995 35.6, 139.6 x 35.61, 139.7
    { 3841, 30552, NoLogo, LineMetaDataContent::RapidTransit, Color{0x20a288} }, // DT OSM: 9341816 WD: Q1190086 35.51, 139.4 x 35.66, 139.7
    { 3844, 30577, NoLogo, LineMetaDataContent::RapidTransit, Color{0xee86a7} }, // IK OSM: 9342009 WD: Q1192388 35.56, 139.7 x 35.63, 139.7
    { 1738, 30602, NoLogo, LineMetaDataContent::RapidTransit, Color{0xae0378} }, // TM OSM: 9343887 WD: Q379292 35.56, 139.7 x 35.59, 139.7
    { 3847, 30627, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff00ff} }, // exo5 OSM: 9344059 WD: Q3239152 45.52, -73.67 x 45.74, -73.49
    { 3852, 30672, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0068b7} }, // KD OSM: 9344153 WD: Q842701 35.53, 139.5 x 35.56, 139.5
    { 2034, 30697, NoLogo, LineMetaDataContent::RapidTransit, Color{0x10a899} }, // NS OSM: 9346454 WD: Q846381 35.91, 139.6 x 36.01, 139.6
    { 3855, 30725, NoLogo, LineMetaDataContent::RapidTransit, Color{0x6600cc} }, // exo3 OSM: 9348176 WD: Q3239159 45.49, -73.57 x 45.58, -73.18
    { 3860, 30770, 526, LineMetaDataContent::RapidTransit, Color{0xbac219} }, // U16 OSM: 9354869 WD: Q106879571 48.8, 9.087 x 48.81, 9.277
    { 68, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x4682b4} }, // 3 OSM: 9357105 WD: Q121543796 43.83, 18.31 x 43.86, 18.43
    { 349, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf8b710} }, // 23 OSM: 9396890 48.75, 9.179 x 48.81, 9.221
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x4682b4} }, // 6 OSM: 9402053 WD: Q121543799 43.83, 18.31 x 43.86, 18.41
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x4682b4} }, // 5 OSM: 9402054 WD: Q121543798 43.85, 18.34 x 43.86, 18.43
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x4682b4} }, // 4 OSM: 9402055 WD: Q121543797 43.83, 18.31 x 43.86, 18.4
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x4682b4} }, // 2 OSM: 9402056 WD: Q121543794 43.85, 18.37 x 43.86, 18.43
    { 64, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x4682b4} }, // 1 OSM: 9402057 WD: Q121543793 43.86, 18.4 x 43.86, 18.43
    { 712, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xad2624} }, // A OSM: 9413576 WD: Q1419423 45.76, 3.082 x 45.81, 3.134
    { 82, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00ae9d} }, // 21 OSM: 9414064 WD: Q16854979 47.56, 7.573 x 47.57, 7.608
    { 52, NoLogo, 30183, LineMetaDataContent::RapidTransit, Color{0x79d4f0} }, // S5 OSM: 9414242 WD: Q63705361 47.59, 7.608 x 47.64, 7.744
    { 1255, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0xcb7eb5} }, // S36 OSM: 9414253 WD: Q15088595 47.52, 8.22 x 47.62, 8.538
    { 3864, 30788, NoLogo, LineMetaDataContent::Subway, Color{0xf890a5} }, // 捷運紅線 (新北投支線) OSM: 9437207 WD: Q8044505 25.13, 121.5 x 25.14, 121.5
    { 3305, 30827, NoLogo, LineMetaDataContent::Subway, Color{0x007ec7} }, // BL OSM: 9437778 WD: Q708378 24.96, 121.4 x 25.05, 121.6
    { 1605, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x2ab04f} }, // RE OSM: 9441941 46.95, 7.438 x 47.2, 7.559
    { 645, NoLogo, 13937, LineMetaDataContent::RapidTransit, Color{0xea1a2a} }, // S9 OSM: 9441942 WD: Q115689939 46.95, 7.438 x 46.99, 7.458
    { 55, NoLogo, 13937, LineMetaDataContent::RapidTransit, Color{0x201f20} }, // S8 OSM: 9441943 WD: Q115689938 46.95, 7.438 x 47.13, 7.535
    { 3585, 30852, 226, LineMetaDataContent::RapidTransit, Color{0x018a47} }, // S26 OSM: 9445376 WD: Q7388232 52.4, 13.28 x 52.59, 13.44
    { 63, NoLogo, 3346, LineMetaDataContent::Tramway, Color{0xce1417} }, // 11 OSM: 9446625 WD: Q123339545 50.46, 30.46 x 50.5, 30.52
    { 360, NoLogo, 8099, LineMetaDataContent::Subway, Color{0xff0000} }, // M1 OSM: 9449959 WD: Q3238662 45.02, 7.591 x 45.08, 7.68
    { 68, 30883, 17953, LineMetaDataContent::Tramway, Color{0xffff00} }, // 3 OSM: 9453120 WD: Q61000373 -22.91, -43.19 x -22.9, -43.17
    { 2214, NoLogo, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 2B OSM: 9453936 WD: Q113118555 47.42, 19.05 x 47.51, 19.12
    { 27, 30912, 21470, LineMetaDataContent::Subway, Color{0xff5599} }, // 6 OSM: 9468298 WD: Q20110123 35.62, 51.28 x 35.77, 51.46
    { 3895, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffcd28} }, // Z72 OSM: 9470080 WD: Q101321651 47.51, 18.71 x 47.78, 19.1
    { 3903, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff6600} }, // RN OSM: 9477810 WD: Q1055870 35.81, 139.9 x 35.86, 139.9
    { 3906, 30936, NoLogo, LineMetaDataContent::Subway, Color{0xffff00} }, // KS-AE OSM: 9480386 WD: Q1045305 35.54, 139.7 x 35.81, 140.4
    { 2762, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xee1d23} }, // 510 OSM: 9481706 WD: Q787200 43.64, -79.4 x 43.67, -79.38
    { 360, 30964, 30979, LineMetaDataContent::Subway, Color{0x168388} }, // M1 OSM: 9487066 WD: Q63781320 -33.91, 150.9 x -33.69, 151.2
    { 3912, 30991, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7a745a} }, // F3 OSM: 9488738 WD: Q31193173 41.1, 28.99 x 41.11, 28.99
    { 2422, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x006400} }, // EN OSM: 9499957 WD: Q250760 35.3, 139.5 x 35.34, 139.6
    { 3915, 31019, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00a6bf} }, // SS OSM: 9507192 WD: Q195685 35.7, 139.3 x 35.91, 139.7
    { 725, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x46837b} }, // T2 OSM: 9515444 WD: Q18118581 31.02, 121.2 x 31.06, 121.3
    { 64, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0000ff} }, // 1 OSM: 9522022 WD: Q61990549 23, 72.51 x 23.05, 72.67
    { 64, 31037, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa6dfe6} }, // 1 OSM: 9525005 WD: Q109046020 36.75, 10.18 x 36.8, 10.22
    { 27, 31061, NoLogo, LineMetaDataContent::RapidTransit, Color{0x652c90} }, // 6 OSM: 9530554 WD: Q109046039 36.72, 10.18 x 36.8, 10.22
    { 524, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x48a23e} }, // L2 OSM: 9536631 WD: Q25420937 9.029, -79.51 x 9.104, -79.35
    { 367, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // Blue OSM: 9542499 9.046, 7.285 x 9.155, 7.344
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009999} }, // 5 OSM: 9544852 WD: Q112609290 53.08, 8.752 x 53.12, 8.818
    { 3918, 31085, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffff00} }, // JN OSM: 9555851 WD: Q1366263 35.51, 139.4 x 35.7, 139.7
    { 3921, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // Linea 1 OSM: 9562447 WD: Q113469626 -2.921, -79.04 x -2.882, -78.97
    { 3929, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xffa500} }, // Orange Line OSM: 9571557 WD: Q61996404 21.05, 79.05 x 21.19, 79.12
    { 379, NoLogo, 31107, LineMetaDataContent::Subway, Color{0xe2251c} }, // Red OSM: 9573815 WD: Q25343681 25.19, 51.49 x 25.42, 51.62
    { 71, NoLogo, 13937, LineMetaDataContent::RapidTransit, Color{0x4cb848} }, // S1 OSM: 9577262 WD: Q115689931 46.75, 7.15 x 46.97, 7.631
    { 59, NoLogo, 13937, LineMetaDataContent::RapidTransit, Color{0x00abe5} }, // S2 OSM: 9577399 WD: Q115689932 46.88, 7.241 x 46.97, 7.784
    { 314, NoLogo, 13937, LineMetaDataContent::RapidTransit, Color{0x45bfad} }, // S4 OSM: 9579475 WD: Q115689934 46.75, 7.407 x 47.07, 7.784
    { 2185, NoLogo, 13937, LineMetaDataContent::RapidTransit, Color{0x5d5910} }, // S44 OSM: 9582296 WD: Q115689941 46.75, 7.407 x 47.2, 7.737
    { 52, NoLogo, 13937, LineMetaDataContent::RapidTransit, Color{0x7f0041} }, // S5 OSM: 9582947 WD: Q115689935 46.82, 6.933 x 47.01, 7.44
    { 298, NoLogo, 13937, LineMetaDataContent::RapidTransit, Color{0xea595b} }, // S6 OSM: 9584378 WD: Q115689936 46.82, 7.34 x 46.95, 7.439
    { 46, 31135, 12736, LineMetaDataContent::Subway, Color{0xca8687} }, // S7 OSM: 9584586 WD: Q10946062 31.61, 118.9 x 31.76, 119
    { 645, 31156, 12736, LineMetaDataContent::Subway, Color{0xf1bc1a} }, // S9 OSM: 9584587 WD: Q47471478 31.34, 118.8 x 31.76, 118.9
    { 173, NoLogo, 13937, LineMetaDataContent::RapidTransit, Color{0xe9ce0e} }, // S52 OSM: 9584652 WD: Q115689943 46.93, 7.192 x 46.98, 7.44
    { 225, NoLogo, 13937, LineMetaDataContent::RapidTransit, Color{0x8a6aae} }, // S3 OSM: 9585454 WD: Q115689933 46.89, 7.24 x 47.13, 7.499
    { 3941, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xee1d23} }, // 504 OSM: 9585574 WD: Q3238945 43.63, -79.45 x 43.68, -79.35
    { 3945, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xee1d23} }, // 509 OSM: 9585849 WD: Q3238948 43.64, -79.42 x 43.65, -79.38
    { 3949, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xee1e23} }, // U GUS OSM: 9586670 WD: Q124221046 41.14, -8.61 x 41.44, -8.294
    { 55, 31177, 12736, LineMetaDataContent::Subway, Color{0xeca153} }, // S8 OSM: 9588181 WD: Q10945880 32.13, 118.7 x 32.47, 119
    { 9, 31198, 12736, LineMetaDataContent::Subway, Color{0xa513c0} }, // 4 OSM: 9588283 WD: Q10906684 32.06, 118.7 x 32.13, 119
    { 68, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xd3b466} }, // 3 OSM: 9588292 WD: Q11124519 30.49, 114.2 x 30.67, 114.3
    { 16, 31218, NoLogo, LineMetaDataContent::Subway, Color{0xec9cbb} }, // 2 OSM: 9592190 WD: Q5952205 30.44, 114.2 x 30.77, 114.4
    { 3955, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x3caeef} }, // U MCS OSM: 9599441 WD: Q18473945 41.14, -8.61 x 41.26, -8.136
    { 3961, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x9b68a0} }, // ACE OSM: 9599550 37.33, -122 x 37.96, -121.3
    { 3965, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x114533} }, // SMART OSM: 9599558 37.95, -122.8 x 38.51, -122.5
    { 344, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x006400} }, // 45 OSM: 9600350 51.78, 19.41 x 51.85, 19.51
    { 259, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x006400} }, // 43 OSM: 9600351 51.75, 19.21 x 51.78, 19.46
    { 270, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x006400} }, // 41 OSM: 9600352 51.66, 19.32 x 51.74, 19.46
    { 22, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 18 OSM: 9600353 WD: Q108047266 51.74, 19.38 x 51.77, 19.5
    { 239, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffc0cb} }, // 17 OSM: 9600354 WD: Q108074811 51.7, 19.41 x 51.78, 19.51
    { 26, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffc0cb} }, // 16 OSM: 9600355 WD: Q122338999 51.73, 19.36 x 51.8, 19.51
    { 157, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffc0cb} }, // 15 OSM: 9600356 WD: Q108000775 51.72, 19.45 x 51.78, 19.51
    { 153, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // 14 OSM: 9600357 WD: Q108049889 51.74, 19.38 x 51.76, 19.51
    { 67, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 13 OSM: 9600358 WD: Q108068380 51.73, 19.37 x 51.8, 19.49
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 12 OSM: 9600359 WD: Q108049384 51.74, 19.38 x 51.78, 19.53
    { 63, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffa500} }, // 11 OSM: 9600360 WD: Q108049347 51.7, 19.41 x 51.83, 19.46
    { 3971, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // 10AB OSM: 9600361 WD: Q108049512 51.73, 19.38 x 51.76, 19.58
    { 3976, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 9AB OSM: 9600362 WD: Q108049814 51.73, 19.41 x 51.77, 19.58
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // 8 OSM: 9600363 WD: Q108049476 51.75, 19.36 x 51.8, 19.54
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffa500} }, // 6 OSM: 9600365 WD: Q108049423 51.72, 19.45 x 51.8, 19.49
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x800080} }, // 5 OSM: 9600366 WD: Q108068411 51.72, 19.37 x 51.8, 19.5
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 4 OSM: 9600367 51.74, 19.43 x 51.83, 19.51
    { 68, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffa500} }, // 3 OSM: 9600368 WD: Q108049494 51.72, 19.45 x 51.81, 19.55
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffa500} }, // 2 OSM: 9600370 WD: Q108049451 51.74, 19.36 x 51.8, 19.51
    { 64, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x800080} }, // 1 OSM: 9600371 WD: Q108068411 51.75, 19.46 x 51.8, 19.49
    { 3980, NoLogo, 31238, LineMetaDataContent::Tramway, Color{0x32cd32} }, // HN OSM: 9603867 WD: Q5648522 34.54, 135.4 x 34.65, 135.5
    { 429, 31260, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00a0de} }, // P OSM: 9603949 WD: Q1073366 34.61, 135.4 x 34.64, 135.5
    { 3983, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xce202f} }, // 5XX OSM: 9604090 WD: Q29095201 37.33, -122.4 x 37.78, -121.9
    { 3987, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfae4a7} }, // 8XX OSM: 9604091 WD: Q130348068 37, -121.9 x 37.33, -121.6
    { 3991, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // 1XX OSM: 9604092 WD: Q130355213 37.31, -122.4 x 37.78, -121.9
    { 9, 31304, NoLogo, LineMetaDataContent::Subway, Color{0x00843d} }, // 4 OSM: 9607978 WD: Q863422 22.75, 113.4 x 23.13, 113.6
    { 9, 31324, NoLogo, LineMetaDataContent::Subway, Color{0xdc8633} }, // 4 OSM: 9609521 WD: Q15900365 29.6, 106.5 x 29.77, 106.8
    { 3995, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x00b5e2} }, // APM OSM: 9611409 WD: Q862929 23.11, 113.3 x 23.14, 113.3
    { 82, 31349, NoLogo, LineMetaDataContent::Subway, Color{0x201747} }, // 21 OSM: 9611531 WD: Q6553110 23.13, 113.4 x 23.29, 113.8
    { 3999, 31370, NoLogo, LineMetaDataContent::Subway, Color{0xc4d600} }, // GF OSM: 9612493 WD: Q3272527 22.96, 113.1 x 23.09, 113.3
    { 27, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x007128} }, // 6 OSM: 9617440 WD: Q15899990 30.49, 114.1 x 30.65, 114.3
    { 47, 31396, NoLogo, LineMetaDataContent::Subway, Color{0xeb7c16} }, // 7 OSM: 9617441 WD: Q11124507 30.32, 114.2 x 30.89, 114.4
    { 52, 31416, 2564, LineMetaDataContent::RapidTransit, Color{0x8d1d81} }, // S5 OSM: 9626749 WD: Q116125185 46.71, 15.42 x 47.07, 15.63
    { 4002, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x97c616} }, // CRL OSM: 9627859 WD: Q3335354 1.311, 103.7 x 1.406, 104
    { 4006, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x734538} }, // TEL OSM: 9627860 WD: Q7795883 1.272, 103.8 x 1.448, 104
    { 47, 31434, NoLogo, LineMetaDataContent::Subway, Color{0x0035ad} }, // 7 OSM: 9629866 WD: Q5938409 22.52, 113.9 x 22.6, 114.1
    { 68, 31457, NoLogo, LineMetaDataContent::Subway, Color{0x00a2e1} }, // 3 OSM: 9629887 WD: Q1065551 22.51, 114 x 22.73, 114.3
    { 71, 31480, 2564, LineMetaDataContent::RapidTransit, Color{0x00983a} }, // S1 OSM: 9631352 WD: Q116125178 47.07, 15.28 x 47.41, 15.42
    { 9, 31498, NoLogo, LineMetaDataContent::Subway, Color{0x920783} }, // 4 OSM: 9632502 WD: Q24835582 28.14, 112.9 x 28.3, 113.1
    { 9, 31528, NoLogo, LineMetaDataContent::Subway, Color{0xa6d30b} }, // 4 OSM: 9633082 WD: Q6553126 30.53, 114 x 30.61, 114.4
    { 63, 31548, NoLogo, LineMetaDataContent::Subway, Color{0xf6d300} }, // 11 OSM: 9633134 WD: Q11124500 30.49, 114.4 x 30.49, 114.7
    { 528, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x83441d} }, // L3 OSM: 9633218 WD: Q5986353 -33.46, -70.73 x -33.37, -70.56
    { 645, 31569, 2564, LineMetaDataContent::RapidTransit, Color{0x9f7fb8} }, // S9 OSM: 9634178 WD: Q116125198 47.41, 15.27 x 47.61, 15.68
    { 55, 31587, 2564, LineMetaDataContent::RapidTransit, Color{0x5cc1d1} }, // S8 OSM: 9634179 WD: Q116125196 47.17, 14.44 x 47.42, 15.28
    { 590, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0067c0} }, // L OSM: 9638873 WD: Q1329642 35.17, 137 x 35.18, 137.1
    { 16, 31605, NoLogo, LineMetaDataContent::Subway, Color{0x3b6a96} }, // 2 OSM: 9642906 WD: Q15913266 43.86, 125.2 x 43.88, 125.4
    { 19, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x25b7bc} }, // 8 OSM: 9642908 WD: Q15956288 43.95, 125.3 x 44.01, 125.4
    { 6, 31625, NoLogo, LineMetaDataContent::Subway, Color{0x9950b2} }, // 5 OSM: 9645952 WD: Q5926109 22.48, 113.9 x 22.63, 114.1
    { 64, 31648, 4274, LineMetaDataContent::Subway, Color{0xee352e} }, // 1 OSM: 9651536 WD: Q126093 40.7, -74.02 x 40.89, -73.9
    { 1319, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0xf05b94} }, // S20 OSM: 9652168 WD: Q111523342 47.24, 8.536 x 47.38, 8.756
    { 16, 31674, 4274, LineMetaDataContent::Subway, Color{0xee352e} }, // 2 OSM: 9655665 WD: Q126142 40.63, -74.01 x 40.9, -73.85
    { 68, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x571887} }, // 3 OSM: 9656354 WD: Q25824052 22.72, 108.2 x 22.88, 108.4
    { 68, 31700, 4274, LineMetaDataContent::Subway, Color{0xee352e} }, // 3 OSM: 9663807 WD: Q126151 40.66, -74.01 x 40.82, -73.88
    { 4010, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x6c8bc6} }, // D11 OSM: 9672611 51.1, 16.15 x 51.4, 17.04
    { 9, 31726, 4274, LineMetaDataContent::Subway, Color{0x00933c} }, // 4 OSM: 9677108 WD: Q126163 40.66, -74.01 x 40.89, -73.88
    { 418, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xce0037} }, // M OSM: 9677671 WD: Q60608236 -6.292, 106.8 x -6.191, 106.8
    { 520, 31752, 31765, LineMetaDataContent::RapidTransit, Color{0xee343f} }, // L1 OSM: 9678605 WD: Q14543324 -33.91, 151.1 x -33.87, 151.2
    { 590, 31765, 31765, LineMetaDataContent::RapidTransit, Color{0xe4022d} }, // L OSM: 9678765 WD: Q17016515 -32.93, 151.8 x -32.92, 151.8
    { 16, NoLogo, 20569, LineMetaDataContent::Tramway, Color{0xff0000} }, // 2 OSM: 9680853 WD: Q7833150 51.37, -0.2081 x 51.42, -0.02612
    { 9, NoLogo, 20569, LineMetaDataContent::Tramway, Color{0xb5e61d} }, // 4 OSM: 9680854 WD: Q7833148 51.37, -0.2081 x 51.42, -0.04953
    { 6, 31777, 4274, LineMetaDataContent::Subway, Color{0x00933c} }, // 5 OSM: 9682651 WD: Q126177 40.63, -74.01 x 40.9, -73.83
    { 1627, 31803, NoLogo, LineMetaDataContent::RapidTransit, Color{0x783d1d} }, // T6 OSM: 9684395 WD: Q125727482 -33.92, 151 x -33.86, 151
    { 1818, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xd11f2f} }, // T9 OSM: 9697199 WD: Q63653326 -33.9, 151.1 x -33.7, 151.2
    { 1760, 31823, NoLogo, LineMetaDataContent::RapidTransit, Color{0x6f818e} }, // T7 OSM: 9698738 WD: Q4663585 -33.86, 151 x -33.85, 151.1
    { 1837, 31836, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00954c} }, // T8 OSM: 9698883 WD: Q4698965 -34.07, 150.8 x -33.86, 151.2
    { 146, 31849, NoLogo, LineMetaDataContent::Subway, Color{0x846e74} }, // 9 OSM: 9699772 WD: Q5939429 22.51, 113.9 x 22.57, 114.1
    { 2414, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // BLUE OSM: 9701744 WD: Q113480379 53.33, -1.508 x 53.4, -1.344
    { 4014, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x800080} }, // PURP OSM: 9701781 WD: Q113480418 53.34, -1.469 x 53.38, -1.424
    { 4019, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffff00} }, // YELL OSM: 9701824 WD: Q113471568 53.38, -1.51 x 53.42, -1.405
    { 1403, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // TT OSM: 9701873 WD: Q113480455 53.38, -1.469 x 53.44, -1.343
    { 4024, 31872, 4274, LineMetaDataContent::Subway, Color{0x006bb6} }, // SIR OSM: 9701910 WD: Q1273068 40.51, -74.25 x 40.64, -74.07
    { 26, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0c7cac} }, // 16 OSM: 9704849 WD: Q122307234 51.08, 16.99 x 51.15, 17.06
    { 153, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe2368c} }, // 14 OSM: 9708096 47.14, 37.54 x 47.18, 37.62
    { 67, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe2368c} }, // 13 OSM: 9708097 47.14, 37.54 x 47.18, 37.62
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x13b5eb} }, // 8 OSM: 9708100 47.1, 37.51 x 47.12, 37.56
    { 75, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x4f3893} }, // 10 OSM: 9708103 47.1, 37.51 x 47.17, 37.62
    { 68, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf37b24} }, // 3 OSM: 9709247 47.1, 37.51 x 47.12, 37.65
    { 4028, 31900, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00843d} }, // Green-E OSM: 9709938 WD: Q172040 42.33, -71.12 x 42.41, -71.06
    { 289, 31928, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf99d1c} }, // T1 OSM: 9709950 WD: Q979843 -33.9, 150.7 x -33.6, 151.2
    { 63, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x897ab7} }, // 11 OSM: 9712140 47.1, 37.54 x 47.18, 37.65
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffbf00} }, // 5 OSM: 9712141 47.1, 37.54 x 47.15, 37.65
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffbf00} }, // 6 OSM: 9712142 47.1, 37.54 x 47.12, 37.65
    { 146, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0068b2} }, // 9 OSM: 9712143 47.1, 37.54 x 47.18, 37.65
    { 418, 31941, 4274, LineMetaDataContent::Subway, Color{0xff6319} }, // M OSM: 9712349 WD: Q126418 40.7, -74 x 40.76, -73.84
    { 590, 31967, 4274, LineMetaDataContent::Subway, Color{0xa7a9ac} }, // L OSM: 9716997 WD: Q126534 40.65, -74 x 40.74, -73.9
    { 645, NoLogo, 30183, LineMetaDataContent::RapidTransit, Color{0x9589c6} }, // S9 OSM: 9719969 WD: Q3239195 47.35, 7.81 x 47.46, 7.918
    { 4036, 4291, 4274, LineMetaDataContent::Subway, Color{0xb933ad} }, // <7> OSM: 9721629 WD: Q126203 40.74, -74 x 40.76, -73.83
    { 4040, 4421, 4274, LineMetaDataContent::Subway, Color{0x00933c} }, // <6> OSM: 9721630 WD: Q126192 40.71, -74.01 x 40.85, -73.83
    { 4044, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x5d2f0b} }, // 511 OSM: 9724236 WD: Q4639990 43.64, -79.42 x 43.67, -79.4
    { 1393, 31993, NoLogo, LineMetaDataContent::RapidTransit, Color{0x005aa3} }, // T4 OSM: 9724606 WD: Q5330503 -34.14, 151 x -33.87, 151.2
    { 2363, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xef8016} }, // R16 OSM: 9725787 WD: Q125884567 59.08, 24.24 x 59.44, 24.74
    { 4048, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xef8016} }, // R31 OSM: 9725788 WD: Q11026783 59.28, 24.72 x 59.44, 25.61
    { 2395, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xef8016} }, // R14 OSM: 9726762 WD: Q8567799 59.31, 24.06 x 59.44, 24.74
    { 2391, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xef8016} }, // R13 OSM: 9726763 WD: Q125882969 59.31, 24.24 x 59.44, 24.74
    { 3688, 32006, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // 202 OSM: 9729897 WD: Q51912653 51.04, -114.2 x 51.13, -113.9
    { 3656, 32018, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // 201 OSM: 9729912 WD: Q51898028 50.9, -114.2 x 51.13, -114.1
    { 4052, NoLogo, 32029, LineMetaDataContent::RapidTransit, Color{0xfc6357} }, // 22R OSM: 9730137 WD: Q14192100 53.46, -113.5 x 53.57, -113.5
    { 596, NoLogo, 32029, LineMetaDataContent::RapidTransit, Color{0x3a59a9} }, // 21R OSM: 9730138 WD: Q12054219 53.46, -113.5 x 53.6, -113.4
    { 64, 32062, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // 1 OSM: 9732464 WD: Q56188749 -3.033, 104.7 x -2.894, 104.8
    { 4056, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xed1d24} }, // TWL OSM: 9736531 WD: Q1194568 22.28, 114.1 x 22.38, 114.2
    { 4060, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x7d499d} }, // TKL OSM: 9736612 WD: Q989347 22.29, 114.2 x 22.32, 114.3
    { 334, 32110, 4274, LineMetaDataContent::Subway, Color{0x996633} }, // J OSM: 9747970 WD: Q126484 40.68, -74.01 x 40.72, -73.8
    { 279, 32136, 4274, LineMetaDataContent::Subway, Color{0xff6319} }, // B OSM: 9748435 WD: Q126381 40.58, -74 x 40.87, -73.89
    { 590, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x679f5a} }, // L OSM: 9749315 WD: Q112398566 55.36, 10.34 x 55.41, 10.44
    { 337, 32162, 4274, LineMetaDataContent::Subway, Color{0xff6319} }, // F OSM: 9753684 WD: Q126404 40.58, -74 x 40.77, -73.78
    { 82, 32188, NoLogo, LineMetaDataContent::Subway, Color{0xb2007b} }, // 21 OSM: 9765661 WD: Q11124502 30.65, 114.3 x 30.72, 114.6
    { 329, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0xf17079} }, // S25 OSM: 9767545 WD: Q115743707 47.28, 8.204 x 47.48, 8.341
    { 4064, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0xfece08} }, // S23 OSM: 9767546 WD: Q115743940 47.22, 7.784 x 47.49, 8.308
    { 3585, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0xc89f3b} }, // S26 OSM: 9767547 WD: Q115646660 47.14, 7.907 x 47.4, 8.436
    { 411, 32209, 4274, LineMetaDataContent::Subway, Color{0x0039a6} }, // C OSM: 9767766 WD: Q126358 40.67, -74.01 x 40.84, -73.87
    { 2602, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x13ae99} }, // S14 OSM: 9768340 WD: Q115747591 47.24, 8.041 x 47.39, 8.19
    { 283, 32235, 4274, LineMetaDataContent::Subway, Color{0xff6319} }, // D OSM: 9769161 WD: Q126396 40.58, -74.01 x 40.88, -73.88
    { 548, 32261, 4274, LineMetaDataContent::Subway, Color{0x0039a6} }, // E OSM: 9769302 WD: Q126368 40.7, -74.01 x 40.76, -73.8
    { 4068, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x000000} }, // 751P OSM: 9788142 WD: Q15903000 22.41, 114 x 22.47, 114
    { 4073, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xee3a41} }, // NEC OSM: 9795466 WD: Q7057868 40.22, -74.75 x 40.77, -73.99
    { 1396, 32287, NoLogo, LineMetaDataContent::RapidTransit, Color{0xc4258f} }, // T5 OSM: 9796604 WD: Q5193991 -33.98, 150.8 x -33.6, 151
    { 725, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe73331} }, // T2 OSM: 9797089 WD: Q109610513 49.18, -0.3663 x 49.21, -0.348
    { 1329, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009adf} }, // T3 OSM: 9797090 WD: Q109610514 49.15, -0.364 x 49.19, -0.3411
    { 1604, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf686c3} }, // TRE OSM: 9797671 WD: Q7838588 39.95, -75.2 x 40.22, -74.75
    { 1634, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0xffc709} }, // S31 OSM: 9800222 WD: Q115646663 47.05, 8.548 x 47.16, 8.724
    { 725, 32300, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0098cd} }, // T2 OSM: 9800349 WD: Q44131634 -33.98, 150.8 x -33.82, 151.2
    { 9, 32313, NoLogo, LineMetaDataContent::Subway, Color{0x39b09e} }, // 4 OSM: 9807766 WD: Q15939632 34.14, 108.9 x 34.38, 109
    { 4077, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x8c493a} }, // Cape Flats OSM: 9812222 WD: Q5034802 -34.06, 18.43 x -33.92, 18.5
    { 4088, 32333, NoLogo, LineMetaDataContent::RapidTransit, Color{0x002d9a} }, // C-6 OSM: 9812239 WD: Q5987225 39.44, -0.3834 x 39.99, -0.05181
    { 3436, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xee1d23} }, // 506 OSM: 9816773 WD: Q3238947 43.65, -79.46 x 43.69, -79.3
    { 868, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xee1d23} }, // 306 OSM: 9816774 WD: Q3238947 43.65, -79.45 x 43.69, -79.3
    { 4092, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x3096c2} }, // NLR OSM: 9821052 WD: Q56760909 40.73, -74.19 x 40.78, -74.16
    { 4096, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xed1c24} }, // Southern Suburbs OSM: 9822441 WD: Q7570093 -34.19, 18.43 x -33.92, 18.47
    { 4113, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x33bef3} }, // Central Line OSM: 9822444 WD: Q5061363 -34.07, 18.43 x -33.91, 18.71
    { 68, 32351, NoLogo, LineMetaDataContent::Subway, Color{0xeca154} }, // 3 OSM: 9841063 WD: Q862941 22.94, 113.3 x 23.4, 113.5
    { 4126, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0194d7} }, // JFK OSM: 9862004 WD: Q406683 40.64, -73.83 x 40.7, -73.78
    { 67, 32371, NoLogo, LineMetaDataContent::RapidTransit, Color{0x2ca05a} }, // 13 OSM: 9881314 WD: Q6553067 -23.55, -46.64 x -23.43, -46.49
    { 4130, 32383, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // Norte OSM: 9881792 WD: Q10374984 -5.797, -35.42 x -5.632, -35.21
    { 146, 32401, NoLogo, LineMetaDataContent::Subway, Color{0x017cbf} }, // 9 OSM: 9893306 WD: Q11138917 41.72, 123.3 x 41.84, 123.5
    { 653, 32432, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa0cf65} }, // Green OSM: 9897509 WD: Q6925400 37.28, -122 x 37.41, -121.9
    { 367, 32451, NoLogo, LineMetaDataContent::RapidTransit, Color{0x3bb4e6} }, // Blue OSM: 9897510 WD: Q4737344 37.24, -121.9 x 37.41, -121.8
    { 3203, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xee4b95} }, // TL9 OSM: 9898994 WD: Q125903430 51.37, -0.4163 x 51.88, 0.08924
    { 4136, 32469, NoLogo, LineMetaDataContent::LocalTrain, Color{0x59191f} }, // AERA1 City OSM: 9921501 WD: Q1133704 13.69, 100.5 x 13.76, 100.8
    { 146, 32484, NoLogo, LineMetaDataContent::Subway, Color{0x71cc98} }, // 9 OSM: 9924027 WD: Q6553161 23.36, 113.1 x 23.4, 113.3
    { 64, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xb22222} }, // 1 OSM: 9934001 WD: Q121537929 55.5, 28.58 x 55.53, 28.67
    { 1723, 32504, 226, LineMetaDataContent::RapidTransit, Color{0xc36939} }, // S42 OSM: 9942315 WD: Q15118875 52.46, 13.28 x 52.55, 13.48
    { 701, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffd700} }, // G OSM: 9942698 WD: Q5578772 39.75, -105.1 x 39.81, -105
    { 279, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // B OSM: 9942699 WD: Q19865232 39.75, -105 x 39.82, -105
    { 712, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x57c0e8} }, // A OSM: 9942719 WD: Q5328174 39.75, -105 x 39.85, -104.7
    { 2755, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x949599} }, // Silver OSM: 9946498 32.71, -117.2 x 32.72, -117.2
    { 4148, 32535, NoLogo, LineMetaDataContent::RapidTransit, Color{0x04aa4f} }, // 530 OSM: 9946502 WD: Q11681429 32.71, -117.2 x 32.79, -117
    { 4152, 32575, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf6821e} }, // 520 OSM: 9946503 WD: Q597476 32.71, -117.2 x 32.79, -117
    { 411, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf79239} }, // C OSM: 9947502 WD: Q5015067 39.58, -105 x 39.76, -105
    { 283, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008348} }, // D OSM: 9947503 WD: Q5207092 39.58, -105 x 39.75, -105
    { 548, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x552683} }, // E OSM: 9947507 WD: Q5324803 39.52, -105 x 39.76, -104.9
    { 337, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xee3e33} }, // F OSM: 9947520 WD: Q5427493 39.52, -105 x 39.75, -104.9
    { 34, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0075bf} }, // H OSM: 9947525 WD: Q5636307 39.63, -105 x 39.75, -104.8
    { 598, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xb7f037} }, // R OSM: 9947529 WD: Q5515134 39.52, -104.9 x 39.77, -104.8
    { 758, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x37b5a5} }, // W OSM: 9947532 WD: Q7958496 39.72, -105.2 x 39.76, -105
    { 289, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x13a538} }, // T1 OSM: 9953164 WD: Q109610512 49.15, -0.3663 x 49.2, -0.3291
    { 1096, 30036, 29662, LineMetaDataContent::RapidTransit, Color{0x28543d} }, // S12 OSM: 9959066 WD: Q1160881 45.36, 9.158 x 45.55, 9.32
    { 4156, 25678, 20452, LineMetaDataContent::Subway, Color{0x996746} }, // AREX OSM: 9961461 WD: Q487643 37.44, 126.4 x 37.6, 127
    { 4161, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xd1aa00} }, // SAR-VIN OSM: 9963645 WD: Q10318744 -22.68, -43.25 x -22.57, -43.18
    { 4169, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x660066} }, // Belford Roxo OSM: 9963651 WD: Q10318671 -22.91, -43.4 x -22.76, -43.19
    { 4182, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf60619} }, // Deodoro OSM: 9963665 WD: Q18473921 -22.91, -43.39 x -22.85, -43.19
    { 4190, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfa8835} }, // Saracuruna OSM: 9963667 WD: Q10318727 -22.91, -43.31 x -22.68, -43.19
    { 4201, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x5194c4} }, // JRI-PBI OSM: 9963669 WD: Q10318719 -22.64, -43.71 x -22.61, -43.65
    { 4209, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x96333b} }, // SAR-GIM OSM: 9963674 WD: Q10318688 -22.68, -43.25 x -22.52, -42.98
    { 4217, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x6b297e} }, // Parangaba-Mucuripe OSM: 9963934 WD: Q10318709 -3.776, -38.56 x -3.72, -38.48
    { 4236, 32616, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // Oeste OSM: 9963937 WD: Q14325543 -3.77, -38.66 x -3.718, -38.54
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009ee3} }, // 4 OSM: 9964886 WD: Q121253960 52.25, 10.51 x 52.27, 10.56
    { 712, 32654, 1449, LineMetaDataContent::RapidTransit, Color{0x00bfff} }, // A OSM: 9971068 WD: Q2323144 55.46, 12.17 x 55.93, 12.59
    { 896, NoLogo, 32676, LineMetaDataContent::RapidTransit, Color{0xde1d43} }, // LR OSM: 9976617 WD: Q112627789 39.17, -76.68 x 39.5, -76.62
    { 3237, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x808080} }, // B1 OSM: 9987140 40.78, 28.77 x 41.03, 29.41
    { 157, 32710, 5450, LineMetaDataContent::Subway, Color{0xde64a1} }, // 15 OSM: 10011657 WD: Q4226438 55.7, 37.73 x 55.73, 37.93
    { 367, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // Blue OSM: 10012484 WD: Q4929376 35.11, -80.88 x 35.32, -80.73
    { 146, 32735, NoLogo, LineMetaDataContent::Tramway, Color{0x009cdd} }, // 9 OSM: 10015448 WD: Q26197601 53.41, 14.49 x 53.47, 14.55
    { 3835, 30502, NoLogo, LineMetaDataContent::Subway, Color{0x8ba2ae} }, // MG OSM: 10023806 WD: Q283861 35.55, 139.6 x 35.63, 139.7
    { 1490, 32755, NoLogo, LineMetaDataContent::RapidTransit, Color{0xbcbe00} }, // E2 OSM: 10025161 WD: Q104233849 43.27, -2.021 x 43.35, -1.782
    { 3841, 30552, NoLogo, LineMetaDataContent::Subway, Color{0x01aaaa} }, // DT OSM: 10032468 WD: Q1190086 35.47, 139.4 x 36.11, 139.8
    { 64, 32772, NoLogo, LineMetaDataContent::RapidTransit, Color{0xee1b2e} }, // 1 OSM: 10036404 WD: Q5159786 45.4, -75.74 x 45.43, -75.61
    { 4242, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x00a650} }, // OT OSM: 10036880 WD: Q1063832 35.36, 139.2 x 35.67, 139.7
    { 4245, 32791, NoLogo, LineMetaDataContent::RapidTransit, Color{0x9ab6d3} }, // S Line OSM: 10077909 WD: Q56525586 47.15, -122.5 x 47.6, -122.2
    { 4252, 32823, NoLogo, LineMetaDataContent::RapidTransit, Color{0x9ab6d3} }, // N Line OSM: 10077955 WD: Q56525585 47.6, -122.4 x 47.98, -122.2
    { 75, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe3000b} }, // 10 OSM: 10082596 WD: Q121253957 52.25, 10.51 x 52.31, 10.54
    { 4259, 32855, NoLogo, LineMetaDataContent::RapidTransit, Color{0x007cad} }, // 2 Line OSM: 10084246 WD: Q5328844 47.59, -122.2 x 47.65, -122.1
    { 1741, 32887, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00953b} }, // C-5 OSM: 10089940 WD: Q9026057 39.44, -0.5754 x 39.95, -0.2703
    { 2699, 32901, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfab700} }, // C-2 OSM: 10090322 WD: Q9026042 38.88, -0.7543 x 39.47, -0.378
    { 663, 32916, NoLogo, LineMetaDataContent::RapidTransit, Color{0x870099} }, // C-3 OSM: 10090427 WD: Q5682717 39.42, -1.203 x 39.57, -0.3669
    { 4266, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa17800} }, // 김포 골드라인 OSM: 10092719 37.56, 126.6 x 37.65, 126.8
    { 146, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 9 OSM: 10092776 WD: Q15222207 63.4, 10.31 x 63.43, 10.39
    { 22, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xd6a461} }, // 18 OSM: 10095918 WD: Q6553089 31.04, 121.5 x 31.34, 121.6
    { 4286, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00214d} }, // 910 OSM: 10098291 55.76, 12.5 x 55.81, 12.53
    { 4290, 31900, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00843d} }, // Green-D OSM: 10099594 WD: Q172031 42.32, -71.25 x 42.38, -71.06
    { 146, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x4ea391} }, // 9 OSM: 10112938 WD: Q121410314 47.12, 27.56 x 47.19, 27.59
    { 667, 4190, NoLogo, LineMetaDataContent::LocalTrain, Color{0xff0000} }, // C-1 OSM: 10121808 WD: Q79636430 43.02, -2.34 x 43.34, -1.8
    { 153, 32934, NoLogo, LineMetaDataContent::Subway, Color{0xb289bc} }, // 14 OSM: 10131355 WD: Q63781395 34.72, 113.5 x 34.78, 113.5
    { 4298, NoLogo, 4547, LineMetaDataContent::Subway, Color{0x3f48cc} }, // Daxing Airport OSM: 10136967 WD: Q19840478 39.51, 116.3 x 39.85, 116.4
    { 64, 32954, 28764, LineMetaDataContent::Subway, Color{0xa55fc8} }, // 1 OSM: 10149342 WD: Q18654264 36.5, 116.8 x 36.68, 116.9
    { 64, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xcd5c5c} }, // 1 OSM: 10163085 WD: Q66660306 31.63, 119.9 x 31.9, 120
    { 289, NoLogo, 32988, LineMetaDataContent::Tramway, Color{0x363d42} }, // T1 OSM: 10181950 WD: Q48747416 43.93, 4.8 x 43.94, 4.841
    { 4313, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x015698} }, // River Line OSM: 10213690 WD: Q2155505 39.94, -75.13 x 40.22, -74.71
    { 524, NoLogo, 31765, LineMetaDataContent::RapidTransit, Color{0xee343f} }, // L2 OSM: 10214162 WD: Q16927050 -33.92, 151.2 x -33.86, 151.2
    { 1627, 33019, 10457, LineMetaDataContent::Tramway, Color{0x873f98} }, // T6 OSM: 10218859 WD: Q21657685 45.73, 4.835 x 45.75, 4.897
    { 4242, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffe100} }, // OT OSM: 10238058 34.97, 135.7 x 35.07, 135.9
    { 71, NoLogo, 30183, LineMetaDataContent::RapidTransit, Color{0x81cd7b} }, // S1 OSM: 10249610 WD: Q3239193 47.51, 7.591 x 47.57, 8.063
    { 225, NoLogo, 30183, LineMetaDataContent::RapidTransit, Color{0x5ba3d8} }, // S3 OSM: 10249618 WD: Q3239191 47.33, 7.08 x 47.55, 7.918
    { 411, 33039, NoLogo, LineMetaDataContent::Subway, Color{0x65c03a} }, // C OSM: 10258970 WD: Q1057729 34.64, 135.4 x 34.73, 135.8
    { 4324, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x343f4b} }, // CMET OSM: 10271387 WD: Q94701342 -35.28, 149.1 x -35.19, 149.2
    { 4329, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x004792} }, // APT Blue OSM: 10274979 32.86, -96.94 x 32.87, -96.93
    { 528, NoLogo, 33055, LineMetaDataContent::Tramway, Color{0x009640} }, // L3 OSM: 10281452 WD: Q16655742 43.66, 7.194 x 43.71, 7.212
    { 1265, 33077, 3125, LineMetaDataContent::Subway, Color{0xff0a0a} }, // M3 OSM: 10283923 WD: Q1094251 55.67, 12.53 x 55.71, 12.59
    { 4338, 26772, NoLogo, LineMetaDataContent::Subway, Color{0x65b724} }, // BTS Sukhumvit OSM: 10285801 WD: Q4921598 13.57, 100.5 x 13.93, 100.6
    { 520, NoLogo, 33055, LineMetaDataContent::Tramway, Color{0xd20a11} }, // L1 OSM: 10286521 WD: Q3238669 43.7, 7.254 x 43.73, 7.293
    { 337, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // F OSM: 10286522 WD: Q3537109 35.91, 136.2 x 36.07, 136.2
    { 764, 33089, 33114, LineMetaDataContent::RapidTransit, Color{0xed9f2d} }, // D1 OSM: 10309188 WD: Q62091003 55.67, 37.28 x 56.01, 37.59
    { 767, 33127, 33114, LineMetaDataContent::RapidTransit, Color{0xdf477c} }, // D2 OSM: 10309312 WD: Q62091175 55.43, 37.18 x 55.84, 37.74
    { 64, NoLogo, 33152, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 10309985 WD: Q4349061 53.2, 50.13 x 53.21, 50.28
    { 4352, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff88bb} }, // Rochdale - East Didsbury OSM: 10310648 WD: Q113534467 53.41, -2.28 x 53.62, -2.088
    { 4377, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x887766} }, // Shaw and Crompton - East Didsbury OSM: 10310683 WD: Q113534413 53.41, -2.28 x 53.58, -2.089
    { 4411, 33174, NoLogo, LineMetaDataContent::Subway, Color{0xffd700} }, // JB OSM: 10312072 WD: Q1091295 35.61, 139.6 x 35.9, 140.1
    { 2436, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0066bb} }, // Manchester Airport - Manchester Victoria OSM: 10314875 WD: Q22712167 53.37, -2.297 x 53.49, -2.238
    { 4414, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff7700} }, // Ashton-under-Lyne – MediaCityUK OSM: 10320090 53.47, -2.297 x 53.49, -2.098
    { 63, NoLogo, 8099, LineMetaDataContent::Subway, Color{0xeb6a2d} }, // 11 OSM: 10320583 WD: Q3832713 40.89, 14.21 x 40.97, 14.24
    { 1892, NoLogo, 31107, LineMetaDataContent::Subway, Color{0xf9b428} }, // Gold OSM: 10322047 WD: Q22948672 25.26, 51.44 x 25.29, 51.57
    { 4448, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00ccff} }, // Ashton-under-Lyne – Eccles OSM: 10326857 WD: Q113532665 53.47, -2.335 x 53.49, -2.098
    { 4477, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x881188} }, // Piccadilly - Altrincham OSM: 10328430 WD: Q113534550 53.39, -2.347 x 53.48, -2.23
    { 2864, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffbb00} }, // Bury - Manchester Piccadilly OSM: 10334672 WD: Q113533465 53.48, -2.321 x 53.59, -2.226
    { 4501, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008800} }, // Altrincham – Bury OSM: 10334764 WD: Q113533738 53.39, -2.347 x 53.59, -2.226
    { 4521, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xd32232} }, // ESFECO OSM: 10334823 WD: Q1132053 -22.95, -43.22 x -22.94, -43.2
    { 4528, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff6600} }, // MSC 821 OSM: 10366537 14.17, 121 x 14.62, 121.3
    { 208, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff6600} }, // MSC 1708 OSM: 10366538 14.17, 121 x 14.62, 121.3
    { 4536, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf9cc3e} }, // Kariega CBD OSM: 10374699 WD: Q124409835 -33.96, 25.41 x -33.77, 25.62
    { 4548, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf58220} }, // Berlin OSM: 10374784 WD: Q124413495 -33.02, 27.58 x -32.88, 27.91
    { 64, 33196, 33196, LineMetaDataContent::Subway, Color{0xbf3a35} }, // 1 OSM: 10379854 WD: Q47004909 34.24, 117.1 x 34.27, 117.3
    { 64, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0080bc} }, // 1 OSM: 10380194 WD: Q10893610 36.04, 103.7 x 36.1, 103.9
    { 153, 33212, NoLogo, LineMetaDataContent::Subway, Color{0x00c1d5} }, // 14 OSM: 10381397 WD: Q85884202 34.37, 108.8 x 34.46, 109.1
    { 68, 33233, NoLogo, LineMetaDataContent::Subway, Color{0xf39800} }, // 3 OSM: 10383244 WD: Q10946022 29.65, 121.4 x 29.91, 121.6
    { 4555, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x073686} }, // KS OSM: 10384058 WD: Q855470 35.53, 139.8 x 35.81, 140.4
    { 6, 33254, NoLogo, LineMetaDataContent::Subway, Color{0x0db0c8} }, // 5 OSM: 10386968 WD: Q11102446 30.17, 120 x 30.32, 120.3
    { 6, 33274, NoLogo, LineMetaDataContent::Subway, Color{0x2a5947} }, // 5 OSM: 10387105 WD: Q15928521 34.72, 113.6 x 34.78, 113.8
    { 4305, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffc425} }, // Airport OSM: 10391556 WD: Q409266 -27.47, 153 x -27.39, 153.1
    { 118, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffa500} }, // 22 OSM: 10396259 WD: Q2885972 52.07, 5.112 x 52.09, 5.184
    { 4558, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xed038c} }, // Metrorail OSM: 10398176 WD: Q124425732 -25.73, 28.28 x -25.72, 28.36
    { 4568, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x96c93c} }, // Taipa OSM: 10402175 WD: Q15935354 22.14, 113.5 x 22.18, 113.6
    { 653, NoLogo, 31107, LineMetaDataContent::Subway, Color{0x009530} }, // Green OSM: 10403427 WD: Q25343673 25.27, 51.35 x 25.32, 51.53
    { 4574, NoLogo, 976, LineMetaDataContent::Tramway, Color{0xdb6198} }, // 305 OSM: 10409526 WD: Q121194029 51.46, 7.152 x 51.48, 7.324
    { 4578, NoLogo, 976, LineMetaDataContent::Tramway, Color{0x40558e} }, // 309 OSM: 10409567 WD: Q121194691 51.44, 7.297 x 51.48, 7.337
    { 4582, NoLogo, 976, LineMetaDataContent::Tramway, Color{0xe28e07} }, // 316 OSM: 10409642 WD: Q121194695 51.48, 7.16 x 51.53, 7.272
    { 528, NoLogo, 31765, LineMetaDataContent::RapidTransit, Color{0xee343f} }, // L3 OSM: 10411683 WD: Q16927050 -33.93, 151.2 x -33.86, 151.2
    { 64, 33293, NoLogo, LineMetaDataContent::Tramway, Color{0x8c2b87} }, // 1 OSM: 10413963 WD: Q15883002 51.2, 4.388 x 51.26, 4.421
    { 4586, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // 4М OSM: 10423669 47.83, 33.34 x 48, 33.5
    { 4590, 33315, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // 3М OSM: 10423670 WD: Q106432004 47.88, 33.39 x 48, 33.5
    { 4594, 33355, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // 2М OSM: 10423671 WD: Q106432003 47.89, 33.39 x 48, 33.5
    { 4598, 33395, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // 1М OSM: 10423672 WD: Q106432002 47.89, 33.39 x 47.96, 33.46
    { 3589, 8948, 226, LineMetaDataContent::RapidTransit, Color{0x006db6} }, // RB 32 OSM: 10432813 WD: Q7388251 51.43, 6.775 x 51.58, 7.459
    { 4602, NoLogo, 33434, LineMetaDataContent::RapidTransit, Color{} }, // Manassas OSM: 10433415 WD: Q6747017 38.73, -77.53 x 38.9, -77
    { 4611, NoLogo, 33434, LineMetaDataContent::RapidTransit, Color{0xe73035} }, // Fredericksburg OSM: 10433416 WD: Q5499211 38.22, -77.46 x 38.9, -77
    { 4626, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00bbb3} }, // CHW OSM: 10433666 WD: Q5093959 39.95, -75.21 x 40.08, -75.15
    { 4630, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa57b27} }, // CHE OSM: 10433667 WD: Q5093950 39.95, -75.21 x 40.08, -75.15
    { 4634, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x91456c} }, // AIR OSM: 10433668 WD: Q4698916 39.87, -75.26 x 39.96, -75.16
    { 4638, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x775ca7} }, // CYN OSM: 10433669 WD: Q5200188 39.95, -75.23 x 40.01, -75.17
    { 3291, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xee5067} }, // NOR OSM: 10433670 WD: Q6747157 39.95, -75.35 x 40.12, -75.15
    { 4642, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0081c5} }, // ELW OSM: 10433671 WD: Q6805374 39.89, -75.46 x 39.98, -75.15
    { 4646, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x8ed16a} }, // NWK OSM: 10433672 WD: Q8022734 39.67, -75.75 x 39.96, -75.16
    { 1353, 33463, 226, LineMetaDataContent::RapidTransit, Color{0xc72a80} }, // L5 OSM: 10443588 WD: Q104416090 46.18, 5.999 x 46.22, 6.144
    { 1357, 33495, 226, LineMetaDataContent::RapidTransit, Color{0x00b3b9} }, // L6 OSM: 10447940 WD: Q104416091 46.1, 5.821 x 46.22, 6.144
    { 16, 33527, NoLogo, LineMetaDataContent::Subway, Color{0x00643a} }, // 2 OSM: 10458608 WD: Q20063925 26.04, 119.1 x 26.11, 119.4
    { 516, 33546, 226, LineMetaDataContent::RapidTransit, Color{0xdc911b} }, // L4 OSM: 10464491 WD: Q104416089 46.17, 6.121 x 46.32, 6.237
    { 63, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x3850a2} }, // 11 OSM: 10467354 WD: Q15944362 36.1, 120.5 x 36.48, 120.8
    { 67, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x00ab84} }, // 13 OSM: 10467728 WD: Q15937512 35.67, 119.7 x 35.98, 120.2
    { 4650, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x2daae1} }, // U BAO-PSD OSM: 10483783 WD: Q1314068 38.51, -9.08 x 38.66, -8.838
    { 4660, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x2daae1} }, // U PSD-BAO OSM: 10484566 WD: Q1314068 38.51, -9.08 x 38.66, -8.838
    { 239, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00ace7} }, // 17 OSM: 10486182 WD: Q3238620 46.19, 6.125 x 46.2, 6.232
    { 712, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe2121a} }, // A OSM: 10486983 WD: Q3239053 47.83, 1.9 x 47.93, 1.939
    { 16, NoLogo, 28866, LineMetaDataContent::Subway, Color{0x4bb134} }, // 2 OSM: 10488738 WD: Q24838989 24.48, 117.9 x 24.58, 118.2
    { 68, 33578, NoLogo, LineMetaDataContent::Subway, Color{0xf57b00} }, // 3 OSM: 10488912 WD: Q6112757 31.26, 120.5 x 31.37, 120.8
    { 68, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x098137} }, // 3 OSM: 10488951 WD: Q17023374 31.69, 117.1 x 31.93, 117.4
    { 725, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x6a911a} }, // T2 OSM: 10490757 30.69, 103.8 x 30.83, 104
    { 4670, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x777777} }, // U CRI-ATE OSM: 10491039 WD: Q576138 38.71, -9.174 x 38.99, -8.965
    { 279, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x762a80} }, // B OSM: 10494114 WD: Q3239067 47.9, 1.854 x 47.91, 1.977
    { 528, 33599, 226, LineMetaDataContent::RapidTransit, Color{0x6c9d40} }, // L3 OSM: 10505987 WD: Q104416088 45.91, 6.121 x 46.32, 6.703
    { 4680, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x6a911a} }, // T2B OSM: 10506169 30.73, 104 x 30.8, 104
    { 64, 33631, NoLogo, LineMetaDataContent::Subway, Color{0xe82311} }, // 1 OSM: 10507454 WD: Q76339003 40.78, 111.6 x 40.86, 111.8
    { 4689, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xce8e00} }, // Hempstead OSM: 10511736 WD: Q5712708 40.68, -73.97 x 40.73, -73.62
    { 4699, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xc60c30} }, // Port Washington OSM: 10511737 WD: Q7231025 40.74, -73.99 x 40.83, -73.69
    { 4715, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x006983} }, // Montauk OSM: 10511738 WD: Q4044495 40.7, -73.99 x 41.05, -71.95
    { 462, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00af3f} }, // Oyster Bay OSM: 10511739 WD: Q7116314 40.7, -73.99 x 40.88, -73.53
    { 4723, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0039a6} }, // Port Jefferson OSM: 10511740 WD: Q7230720 40.7, -73.99 x 40.94, -73.05
    { 4684, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00a1de} }, // West Hempstead OSM: 10511742 WD: Q7985342 40.66, -73.97 x 40.71, -73.64
    { 68, 33653, 28764, LineMetaDataContent::Subway, Color{0x3f63e6} }, // 3 OSM: 10513363 WD: Q24837836 36.62, 117.1 x 36.77, 117.2
    { 4738, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x4ca585} }, // TGM1 OSM: 10519279 WD: Q80912905 22.9, 112.8 x 22.95, 112.9
    { 520, 33687, 226, LineMetaDataContent::RapidTransit, Color{0xbf3527} }, // L1 OSM: 10521809 WD: Q104416086 46.17, 6.121 x 46.4, 6.581
    { 524, 33719, 226, LineMetaDataContent::RapidTransit, Color{0x0085c4} }, // L2 OSM: 10526246 WD: Q104416087 45.9, 6.116 x 46.32, 6.362
    { 6, 33751, NoLogo, LineMetaDataContent::Subway, Color{0xbb29bb} }, // 5 OSM: 10526316 WD: Q22100474 30.45, 104 x 30.83, 104.1
    { 4743, 33761, NoLogo, LineMetaDataContent::LocalTrain, Color{0xe31937} }, // Hartford Line OSM: 10530881 WD: Q7008596 41.3, -72.93 x 42.11, -72.58
    { 4757, 33791, NoLogo, LineMetaDataContent::LongDistanceTrain, Color{0x007dbe} }, // IR 65 OSM: 10533323 WD: Q116053231 46.95, 7.24 x 47.13, 7.47
    { 725, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x15882e} }, // T2 OSM: 10547015 WD: Q124261209 51.02, 3.699 x 51.11, 3.773
    { 146, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xef7c00} }, // 9 OSM: 10547655 48.34, 10.89 x 48.37, 10.9
    { 712, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe3028c} }, // A OSM: 10551319 WD: Q93096868 48.38, -4.556 x 48.43, -4.444
    { 153, 33806, NoLogo, LineMetaDataContent::Subway, Color{0x827a04} }, // 14 OSM: 10557252 WD: Q6553074 31.22, 121.3 x 31.27, 121.6
    { 1446, 33827, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf79729} }, // Orange OSM: 10561837 WD: Q81533754 37.36, -122.1 x 37.42, -121.8
    { 4763, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x80276c} }, // CR-Greenbush OSM: 10563012 WD: Q5603780 42.18, -71.06 x 42.35, -70.74
    { 4776, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x80276c} }, // CR-Worcester OSM: 10563013 WD: Q801994 42.23, -71.8 x 42.36, -71.06
    { 4789, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x80276c} }, // CR-Fairmount OSM: 10563014 WD: Q5430648 42.24, -71.13 x 42.35, -71.05
    { 4802, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x80276c} }, // CR-Haverhill OSM: 10563015 WD: Q172528 42.37, -71.18 x 42.82, -71.06
    { 4815, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x80276c} }, // CR-Lowell OSM: 10563016 WD: Q172536 42.37, -71.32 x 42.64, -71.06
    { 4825, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x80276c} }, // CR-Middleborough OSM: 10563017 WD: Q104818537 41.88, -71.06 x 42.35, -70.92
    { 4842, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x80276c} }, // CR-Needham OSM: 10563018 WD: Q6986548 42.27, -71.24 x 42.35, -71.06
    { 4853, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x80276c} }, // CR-Newburyport OSM: 10563019 WD: Q172516 42.37, -71.08 x 42.8, -70.63
    { 4868, NoLogo, 33847, LineMetaDataContent::RapidTransit, Color{0x0171ce} }, // 91/Perris Valley OSM: 10563416 WD: Q4645737 33.76, -118.2 x 34.06, -117.2
    { 4885, NoLogo, 33847, LineMetaDataContent::RapidTransit, Color{0xbd295b} }, // Inland Empire-Orange County OSM: 10563417 WD: Q6380515 33.19, -117.9 x 34.1, -117.3
    { 4899, NoLogo, 33847, LineMetaDataContent::RapidTransit, Color{0xff7602} }, // Orange County OSM: 10563418 WD: Q5220500 33.19, -118.2 x 34.06, -117.4
    { 4913, NoLogo, 33847, LineMetaDataContent::RapidTransit, Color{0x682e85} }, // Riverside OSM: 10563419 WD: Q4801982 33.96, -118.2 x 34.06, -117.4
    { 4923, NoLogo, 33847, LineMetaDataContent::RapidTransit, Color{0xa32236} }, // San Bernardino OSM: 10563420 WD: Q4798016 34.05, -118.2 x 34.11, -117.2
    { 4938, NoLogo, 33847, LineMetaDataContent::RapidTransit, Color{0xf6a706} }, // Ventura County OSM: 10563421 WD: Q4132754 34.05, -119.2 x 34.29, -118.2
    { 4953, NoLogo, 33847, LineMetaDataContent::RapidTransit, Color{0x1d9d02} }, // Antelope Valley OSM: 10563422 WD: Q4162507 34.05, -118.5 x 34.7, -118.1
    { 3444, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // Blue Line OSM: 10563564 25.31, 51.42 x 25.32, 51.43
    { 4969, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x4ba7a6} }, // Turquoise Line OSM: 10563806 25.41, 51.49 x 25.43, 51.5
    { 3929, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xdd722d} }, // Orange Line OSM: 10563807 25.37, 51.49 x 25.43, 51.53
    { 4984, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xd64488} }, // Purple Line OSM: 10563808 25.37, 51.49 x 25.42, 51.53
    { 2711, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // Central OSM: 10570207 WD: Q10329283 -7.232, -39.41 x -7.206, -39.3
    { 64, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x8a8988} }, // 1 OSM: 10570395 WD: Q10318643 -5.111, -42.82 x -5.08, -42.74
    { 1638, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x008000} }, // CBTU OSM: 10570416 WD: Q18484877 -7.131, -34.98 x -6.974, -34.83
    { 4130, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // Norte OSM: 10570453 -3.683, -40.37 x -3.663, -40.34
    { 2407, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // Sul OSM: 10570461 -3.699, -40.36 x -3.682, -40.33
    { 4996, 33866, NoLogo, LineMetaDataContent::LocalTrain, Color{0xdf091d} }, // RE 1 OSM: 10573474 WD: Q322058 48.14, 11.08 x 49.45, 11.57
    { 5001, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // 550 OSM: 10577109 WD: Q113084731 30.26, -97.86 x 30.59, -97.7
    { 5005, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe87308} }, // R17 OSM: 10578984 41.09, 1.145 x 41.4, 2.194
    { 16, 33882, 14077, LineMetaDataContent::Tramway, Color{0xf18e00} }, // 2 OSM: 10579671 WD: Q3238812 43.57, 3.831 x 43.65, 3.931
    { 68, 33892, 14077, LineMetaDataContent::Tramway, Color{0xcbd300} }, // 3 OSM: 10579672 WD: Q3238911 43.56, 3.81 x 43.62, 3.964
    { 64, 33902, 14077, LineMetaDataContent::Tramway, Color{0x005ba1} }, // 1 OSM: 10579673 WD: Q3238667 43.6, 3.817 x 43.64, 3.92
    { 5009, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xee293d} }, // TEX OSM: 10580066 WD: Q28228164 32.75, -97.34 x 32.94, -97.04
    { 2009, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008c99} }, // 654 OSM: 10588005 32.72, -117.4 x 33.19, -117.2
    { 5013, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008c99} }, // 630 OSM: 10588005 32.72, -117.4 x 33.19, -117.2
    { 5017, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008c99} }, // 640 OSM: 10588005 32.72, -117.4 x 33.19, -117.2
    { 5021, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008c99} }, // 662 OSM: 10588005 32.72, -117.4 x 33.19, -117.2
    { 5025, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008c99} }, // 636 OSM: 10588005 32.72, -117.4 x 33.19, -117.2
    { 5029, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008c99} }, // 656 OSM: 10588005 32.72, -117.4 x 33.19, -117.2
    { 5033, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffa300} }, // BTANIC OSM: 10601134 WD: Q113613430 -34.92, 138.6 x -34.91, 138.6
    { 5040, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x55502b} }, // UP Express OSM: 10608917 WD: Q497520 43.64, -79.62 x 43.71, -79.38
    { 3573, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7d4d31} }, // S15 OSM: 10615459 47.46, 8.895 x 47.56, 9.041
    { 1080, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x9285bf} }, // S10 OSM: 10615934 47.46, 9.021 x 47.57, 9.38
    { 5051, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x794400} }, // Stouffville OSM: 10624851 WD: Q3239216 43.64, -79.38 x 44, -79.23
    { 5063, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x009ac7} }, // Richmond Hill OSM: 10624852 WD: Q3239183 43.64, -79.43 x 43.98, -79.32
    { 5077, 33912, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf57f25} }, // MI OSM: 10624853 WD: Q3239156 43.52, -79.87 x 43.67, -79.38
    { 5080, 33931, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00853f} }, // KI OSM: 10624854 WD: Q3239126 43.46, -80.49 x 43.71, -79.38
    { 5083, 33953, NoLogo, LineMetaDataContent::RapidTransit, Color{0x003768} }, // Barrie OSM: 10624855 WD: Q3239071 43.64, -79.69 x 44.37, -79.38
    { 5090, 33972, NoLogo, LineMetaDataContent::RapidTransit, Color{0xee3124} }, // Lakeshore East OSM: 10624856 WD: Q3239134 43.64, -79.38 x 43.87, -78.89
    { 1124, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x8c86bf} }, // S28 OSM: 10644936 WD: Q115747154 47.29, 7.939 x 47.39, 8.172
    { 5105, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0072bc} }, // South Coast OSM: 10646254 WD: Q124416304 -30.36, 30.71 x -29.84, 31.02
    { 5117, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa6ce39} }, // West OSM: 10646666 -29.92, 30.97 x -29.84, 31.05
    { 931, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00baf1} }, // New Main OSM: 10646667 WD: Q124416307 -29.91, 30.59 x -29.73, 31.02
    { 5122, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00652e} }, // Umlazi OSM: 10646668 WD: Q124416305 -29.97, 30.87 x -29.88, 31.05
    { 5129, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf9cc3e} }, // Crossmoor OSM: 10646669 WD: Q124416311 -29.95, 30.86 x -29.84, 31.02
    { 5139, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xee1d23} }, // kwaMashu OSM: 10646670 WD: Q124416310 -29.97, 30.87 x -29.74, 31.03
    { 5148, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x6e2527} }, // Old Main OSM: 10646671 WD: Q124416308 -29.91, 30.86 x -29.82, 31.02
    { 4643, 33999, NoLogo, LineMetaDataContent::RapidTransit, Color{0x9f142c} }, // LW OSM: 10647448 WD: Q3239135 43.11, -79.89 x 43.65, -79.06
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe86220} }, // 2 OSM: 10647637 WD: Q122382718 49.77, 18.22 x 49.85, 18.29
    { 5157, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xb41d8e} }, // S22 OSM: 10650450 47.39, 9.359 x 47.43, 9.462
    { 995, 34026, NoLogo, LineMetaDataContent::Subway, Color{0xfedb00} }, // Y OSM: 10658528 WD: Q5971413 24.98, 121.5 x 25.06, 121.5
    { 3804, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x00ffff} }, // Aqua Line OSM: 10659365 WD: Q62051025 21.11, 79 x 21.15, 79.15
    { 648, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00652e} }, // Dark Green OSM: 10670621 WD: Q124425757 -26.68, 27.82 x -26.2, 28.09
    { 372, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf9cc3e} }, // Yellow OSM: 10670624 WD: Q124425811 -26.34, 27.39 x -26.2, 28.04
    { 4558, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // Metrorail OSM: 10670933 WD: Q124429578 -26.23, 27.94 x -26.21, 28.17
    { 68, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe5097f} }, // 3 OSM: 10685120 WD: Q122382719 49.77, 18.17 x 49.83, 18.27
    { 2602, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf7941d} }, // S14 OSM: 10685821 47.56, 9.102 x 47.66, 9.192
    { 5161, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xadd8e6} }, // LRT OSM: 10693161 WD: Q65762187 -6.193, 106.9 x -6.155, 106.9
    { 46, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf26531} }, // S7 OSM: 10696321 47.48, 9.102 x 47.57, 9.51
    { 2225, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x3e6c01} }, // 102 OSM: 10696526 WD: Q56285819 39.91, -75.3 x 39.96, -75.26
    { 2161, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x3e6c01} }, // 101 OSM: 10696527 WD: Q7389797 39.91, -75.39 x 39.96, -75.26
    { 225, 34054, 2564, LineMetaDataContent::RapidTransit, Color{0xe6007e} }, // S3 OSM: 10699280 WD: Q116125181 46.95, 15.42 x 47.1, 16.01
    { 75, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x3e6c01} }, // 10 OSM: 10703006 WD: Q7389780 39.95, -75.25 x 39.98, -75.16
    { 2142, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x3e6c01} }, // 34 OSM: 10703188 WD: Q7389786 39.94, -75.25 x 39.96, -75.16
    { 1256, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x3e6c01} }, // 36 OSM: 10703676 WD: Q7389789 39.9, -75.24 x 39.96, -75.16
    { 63, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x3e6c01} }, // 11 OSM: 10705415 WD: Q7389783 39.92, -75.26 x 39.96, -75.16
    { 67, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x3e6c01} }, // 13 OSM: 10705526 WD: Q7389784 39.92, -75.26 x 39.96, -75.16
    { 59, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x5da526} }, // S2 OSM: 10724094 WD: Q115646644 46.82, 8.496 x 47.45, 9.063
    { 225, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0xf58220} }, // S3 OSM: 10724334 WD: Q115646645 47, 8.297 x 47.1, 8.632
    { 314, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0xa62b48} }, // S4 OSM: 10736536 WD: Q115646646 46.91, 8.3 x 47.05, 8.398
    { 52, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0xee3d96} }, // S5 OSM: 10736575 WD: Q115646648 46.84, 8.185 x 47.05, 8.314
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009846} }, // 4 OSM: 10741026 WD: Q122382720 49.79, 18.18 x 49.85, 18.32
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x9d9e9e} }, // 6 OSM: 10743087 WD: Q122382722 49.77, 18.22 x 49.85, 18.29
    { 298, 34072, 2564, LineMetaDataContent::RapidTransit, Color{0xf39200} }, // S6 OSM: 10748876 WD: Q116125188 46.72, 15.21 x 47.07, 15.48
    { 441, 34090, 8099, LineMetaDataContent::Subway, Color{0x5d9732} }, // M2 OSM: 10760559 WD: Q2519385 45.4, 9.145 x 45.55, 9.437
    { 1265, 34110, 8099, LineMetaDataContent::Subway, Color{0xfdb813} }, // M3 OSM: 10788272 WD: Q2519355 45.43, 9.163 x 45.53, 9.257
    { 21, 34130, 20452, LineMetaDataContent::Subway, Color{0xf5a200} }, // 318 OSM: 10799694 WD: Q84389881 37.25, 127 x 37.58, 127.1
    { 360, 34152, 8099, LineMetaDataContent::Subway, Color{0xee2e24} }, // M1 OSM: 10803053 WD: Q2400801 45.46, 9.084 x 45.54, 9.239
    { 725, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffcd00} }, // T2 OSM: 10807282 WD: Q122222970 53.45, 18.72 x 53.5, 18.77
    { 1329, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00cdff} }, // T3 OSM: 10807448 WD: Q122222945 53.45, 18.72 x 53.49, 18.76
    { 242, NoLogo, 34172, LineMetaDataContent::RapidTransit, Color{0x644215} }, // S50 OSM: 10816434 WD: Q110305283 46.48, 6.836 x 46.62, 7.087
    { 2116, NoLogo, 34172, LineMetaDataContent::RapidTransit, Color{0x005f6e} }, // S30 OSM: 10816437 WD: Q115701424 46.78, 6.638 x 46.85, 7.154
    { 1888, NoLogo, 34172, LineMetaDataContent::RapidTransit, Color{0x6e9ed4} }, // S21 OSM: 10816438 WD: Q110305258 46.69, 6.911 x 47, 7.154
    { 1319, NoLogo, 34172, LineMetaDataContent::RapidTransit, Color{0x24318a} }, // S20 OSM: 10816439 WD: Q115702408 46.69, 6.911 x 47.01, 7.154
    { 5165, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00975f} }, // 5A OSM: 10837439 WD: Q121317834 49.48, 8.463 x 49.51, 8.596
    { 2289, NoLogo, 23736, LineMetaDataContent::RapidTransit, Color{0xdd2f1d} }, // R2 OSM: 10839602 WD: Q115446591 46.49, 6.517 x 46.81, 6.727
    { 2299, NoLogo, 23736, LineMetaDataContent::RapidTransit, Color{0x6e9dd4} }, // R4 OSM: 10839603 WD: Q115454819 46.32, 6.214 x 46.73, 6.964
    { 157, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x3fbfaa} }, // 15 OSM: 10899251 47.1, 37.62 x 47.12, 37.65
    { 8, 34198, 3125, LineMetaDataContent::Subway, Color{0x36b6f1} }, // M4 OSM: 10925800 WD: Q88965328 55.65, 12.52 x 55.71, 12.6
    { 787, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0xad6389} }, // S64 OSM: 10947584 WD: Q115597678 47.66, 8.43 x 47.7, 8.634
    { 5168, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x4682b4} }, // Airside E OSM: 10956203 WD: Q121502077 27.98, -82.54 x 27.98, -82.54
    { 52, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x8dc63f} }, // S5 OSM: 10958455 WD: Q108602185 47.4, 9.102 x 47.57, 9.642
    { 5178, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x4682b4} }, // SKY OSM: 10958822 WD: Q121502085 27.96, -82.54 x 27.98, -82.53
    { 1096, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x6a489d} }, // S12 OSM: 10961967 WD: Q106455671 46.85, 9.441 x 47.05, 9.562
    { 254, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x38b54a} }, // S24 OSM: 10963118 47.36, 9.451 x 47.38, 9.538
    { 1888, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x089690} }, // S21 OSM: 10963311 WD: Q106455085 47.33, 9.359 x 47.43, 9.462
    { 3704, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffa500} }, // 1720 OSM: 10976185 13.13, 123.2 x 13.62, 123.8
    { 4147, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffa500} }, // 1530 OSM: 10976234 13.59, 123 x 13.77, 123.2
    { 5182, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffa500} }, // 1645 OSM: 10976234 13.59, 123 x 13.77, 123.2
    { 705, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x9f26b4} }, // N OSM: 11004619 WD: Q19877104 39.75, -105 x 39.92, -104.9
    { 5187, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xee0011} }, // The Trafford Centre – Cornbrook OSM: 11041584 WD: Q113532624 53.46, -2.348 x 53.47, -2.267
    { 581, 34210, NoLogo, LineMetaDataContent::Subway, Color{0x0000ff} }, // TS OSM: 11065563 WD: Q2913662 35.51, 139.4 x 36.11, 139.8
    { 2538, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xee1d23} }, // 505 OSM: 11065833 WD: Q3238946 43.65, -79.45 x 43.68, -79.35
    { 26, 34244, NoLogo, LineMetaDataContent::Subway, Color{0xffb25b} }, // 16 OSM: 11076299 WD: Q22099544 30.2, 119.7 x 30.27, 120
    { 5221, NoLogo, 26346, LineMetaDataContent::Subway, Color{0x252525} }, // JSQ–33 via HOB OSM: 11100813 WD: Q1931652 40.72, -74.06 x 40.75, -73.99
    { 75, 34265, NoLogo, LineMetaDataContent::Subway, Color{0x62aa3c} }, // 10 OSM: 11123255 WD: Q20688706 41.71, 123.3 x 41.86, 123.5
    { 414, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffc0cb} }, // S OSM: 11135401 WD: Q5364907 34.32, 134.1 x 34.34, 134.2
    { 586, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffff00} }, // K OSM: 11135402 WD: Q5371397 34.19, 133.8 x 34.35, 134.1
    { 705, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // N OSM: 11135412 WD: Q5364831 34.27, 134 x 34.35, 134.2
    { 235, NoLogo, 34297, LineMetaDataContent::RapidTransit, Color{0xa05ea6} }, // 27 OSM: 11151437 WD: Q106813236 59.35, 18.04 x 59.66, 18.27
    { 1125, NoLogo, 34297, LineMetaDataContent::RapidTransit, Color{0xa05ea6} }, // 28 OSM: 11151439 WD: Q106813260 59.35, 18.04 x 59.48, 18.31
    { 1093, NoLogo, 34297, LineMetaDataContent::RapidTransit, Color{0xa05ea6} }, // 29 OSM: 11151441 WD: Q106813276 59.35, 18.04 x 59.43, 18.1
    { 71, NoLogo, 14578, LineMetaDataContent::RapidTransit, Color{0x000000} }, // S1 OSM: 11183563 WD: Q30109859 47.15, 9.601 x 47.55, 9.817
    { 59, NoLogo, 14578, LineMetaDataContent::RapidTransit, Color{0x000000} }, // S2 OSM: 11185452 WD: Q117314830 47.16, 9.078 x 47.48, 9.651
    { 225, NoLogo, 14578, LineMetaDataContent::RapidTransit, Color{0x000000} }, // S3 OSM: 11185510 WD: Q30109886 47.45, 9.637 x 47.55, 9.754
    { 314, NoLogo, 14578, LineMetaDataContent::RapidTransit, Color{0x000000} }, // S4 OSM: 11185615 WD: Q30109904 47.08, 9.812 x 47.16, 9.918
    { 46, 34332, 2564, LineMetaDataContent::RapidTransit, Color{0xbe1622} }, // S7 OSM: 11185888 WD: Q116125192 46.96, 15.08 x 47.07, 15.42
    { 93, 34350, 2564, LineMetaDataContent::RapidTransit, Color{0xf39200} }, // S61 OSM: 11185889 WD: Q116125190 46.72, 15.21 x 47.07, 15.42
    { 5238, 34369, 4274, LineMetaDataContent::Subway, Color{0xff6319} }, // <F> OSM: 11248274 WD: Q111495096 40.58, -74 x 40.77, -73.78
    { 6, 34396, NoLogo, LineMetaDataContent::Subway, Color{0xffe200} }, // 5 OSM: 11257230 WD: Q18668926 28.1, 113 x 28.28, 113.1
    { 5242, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00aeef} }, // HBLR OSM: 11269271 WD: Q114054273 40.65, -74.13 x 40.79, -74.01
    { 5247, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xae1ea3} }, // D10 OSM: 11270864 51.1, 14.97 x 51.29, 17.04
    { 1723, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x9a6b31} }, // S42 OSM: 11277216 WD: Q106451501 47.28, 8.204 x 47.44, 8.539
    { 68, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 3 OSM: 11279461 46.95, 31.98 x 46.98, 32.03
    { 1265, 34426, 22626, LineMetaDataContent::Subway, Color{0x008000} }, // M3 OSM: 11299964 WD: Q12289405 42.68, 23.24 x 42.7, 23.35
    { 64, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff000c} }, // 1 OSM: 11321268 WD: Q16347621 56.94, 24.01 x 56.99, 24.24
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff000c} }, // 2 OSM: 11321421 WD: Q16348252 56.94, 24.05 x 56.96, 24.12
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff000c} }, // 5 OSM: 11321694 WD: Q16349936 56.94, 24.01 x 57.02, 24.13
    { 47, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff000c} }, // 7 OSM: 11321946 WD: Q16350085 56.91, 24.1 x 56.96, 24.19
    { 75, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff000c} }, // 10 OSM: 11322063 WD: Q13098696 56.91, 24.08 x 56.95, 24.14
    { 63, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff000c} }, // 11 OSM: 11322567 WD: Q16347642 56.95, 24.1 x 57.01, 24.17
    { 157, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x3e6c01} }, // 15 OSM: 11328858 WD: Q3444107 39.96, -75.25 x 39.98, -75.13
    { 5251, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xda291c} }, // Mattapan OSM: 11359791 WD: Q172144 42.27, -71.09 x 42.28, -71.06
    { 5260, 34451, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00843d} }, // Green-B OSM: 11359792 WD: Q172011 42.34, -71.17 x 42.36, -71.06
    { 5268, 34481, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00843d} }, // Green-C OSM: 11359793 WD: Q172022 42.34, -71.15 x 42.36, -71.06
    { 5276, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x73757d} }, // Metro OSM: 11364344 WD: Q3333824 42.88, -78.88 x 42.95, -78.82
    { 64, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf10000} }, // 1 OSM: 11365072 WD: Q121507132 39.01, 125.7 x 39.03, 125.7
    { 367, NoLogo, 6717, LineMetaDataContent::RapidTransit, Color{0x0000f8} }, // Blue OSM: 11366428 WD: Q4929372 38.59, -90.35 x 38.65, -90.05
    { 90, NoLogo, 6890, LineMetaDataContent::Tramway, Color{0xce1417} }, // 63 OSM: 11375919 WD: Q123168072 59.93, 30.44 x 59.96, 30.49
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8b0000} }, // 2 OSM: 11376584 WD: Q124639342 47.88, 33.29 x 47.91, 33.43
    { 64, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8b0000} }, // 1 OSM: 11376585 WD: Q124639341 47.88, 33.3 x 47.93, 33.43
    { 2699, 19295, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00874d} }, // C-2 OSM: 11378343 WD: Q5987206 37.39, -6.01 x 37.45, -5.95
    { 667, 24760, NoLogo, LineMetaDataContent::LocalTrain, Color{0x619bc1} }, // C-1 OSM: 11378450 WD: Q5987193 37.18, -5.98 x 37.66, -5.53
    { 663, 34511, NoLogo, LineMetaDataContent::LocalTrain, Color{0xff061d} }, // C-3 OSM: 11382024 WD: Q5987212 37.39, -5.975 x 37.93, -5.704
    { 3598, 34536, NoLogo, LineMetaDataContent::RapidTransit, Color{0x991b87} }, // C-4 OSM: 11382119 WD: Q5987216 37.34, -5.98 x 37.42, -5.934
    { 118, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8b0000} }, // 22 OSM: 11382749 WD: Q124639356 47.88, 33.29 x 47.91, 33.46
    { 68, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8b0000} }, // 3 OSM: 11383230 WD: Q124639344 47.87, 33.29 x 47.91, 33.44
    { 1741, 34563, NoLogo, LineMetaDataContent::LocalTrain, Color{0x053388} }, // C-5 OSM: 11384993 WD: Q5987218 37.33, -6.208 x 37.45, -5.95
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8b0000} }, // 5 OSM: 11478143 WD: Q124639346 47.83, 33.34 x 47.9, 33.43
    { 330, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8b0000} }, // 25 OSM: 11478144 WD: Q124639358 47.83, 33.34 x 47.91, 33.46
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8b0000} }, // 4 OSM: 11478145 WD: Q124639345 47.83, 33.29 x 47.91, 33.36
    { 46, 34595, 29662, LineMetaDataContent::RapidTransit, Color{0xed2a81} }, // S7 OSM: 11479781 WD: Q26878568 45.48, 9.184 x 45.86, 9.399
    { 71, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x11385b} }, // S1 OSM: 11482970 WD: Q43285793 39.7, 116.1 x 39.9, 116.7
    { 2624, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x55c5d0} }, // S81 OSM: 11484467 47.39, 9.275 x 47.42, 9.369
    { 5282, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x00b9f2} }, // S82 OSM: 11484468 WD: Q108602785 47.42, 9.367 x 47.46, 9.4
    { 2699, 19295, NoLogo, LineMetaDataContent::LocalTrain, Color{0x00874d} }, // C-2 OSM: 11488015 WD: Q5987203 36.7, -4.724 x 36.82, -4.427
    { 667, 24760, NoLogo, LineMetaDataContent::RapidTransit, Color{0x619bc1} }, // C-1 OSM: 11488016 WD: Q25411554 36.54, -4.624 x 36.72, -4.427
    { 39, NoLogo, 34609, LineMetaDataContent::RapidTransit, Color{0x4b0082} }, // T OSM: 11490693 WD: Q7833528 18.99, 72.97 x 19.19, 73.12
    { 876, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0092db} }, // 301 OSM: 11494376 43.42, -80.55 x 43.5, -80.44
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x26ff00} }, // 2 OSM: 11495026 WD: Q121506603 38.98, 125.7 x 39.04, 125.8
    { 68, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff00ef} }, // 3 OSM: 11495033 WD: Q121506943 38.97, 125.7 x 39.05, 125.7
    { 47, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8b0000} }, // 7 OSM: 11495622 WD: Q124639348 47.83, 33.35 x 47.9, 33.43
    { 235, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8b0000} }, // 27 OSM: 11495623 WD: Q124639359 47.83, 33.35 x 47.91, 33.46
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8b0000} }, // 6 OSM: 11495624 WD: Q124639347 47.83, 33.29 x 47.91, 33.38
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8b0000} }, // 8 OSM: 11495625 WD: Q124639349 47.83, 33.34 x 47.84, 33.38
    { 146, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8b0000} }, // 9 OSM: 11495626 WD: Q124639350 47.87, 33.38 x 47.91, 33.46
    { 667, 4190, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff061d} }, // C-1 OSM: 11498246 WD: Q109916345 36.46, -6.288 x 36.75, -6.066
    { 5286, 34651, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff061d} }, // C-1a OSM: 11498247 WD: Q114795934 36.53, -6.206 x 36.54, -6.194
    { 63, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8b0000} }, // 11 OSM: 11500038 WD: Q124639352 47.83, 33.35 x 47.91, 33.39
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8b0000} }, // 12 OSM: 11500039 WD: Q124639354 47.87, 33.38 x 47.91, 33.44
    { 153, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8b0000} }, // 14 OSM: 11500040 WD: Q124639355 47.9, 33.38 x 47.91, 33.46
    { 75, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8b0000} }, // 10 OSM: 11500041 WD: Q124639351 47.83, 33.34 x 47.91, 33.39
    { 5291, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x97c93d} }, // WEST OSM: 11501325 WD: Q7988020 -36.91, 174.6 x -36.84, 174.8
    { 5296, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00aeef} }, // ONE OSM: 11501967 WD: Q28180487 -36.93, 174.8 x -36.87, 174.8
    { 298, NoLogo, 30183, LineMetaDataContent::RapidTransit, Color{0xe9583f} }, // S6 OSM: 11519985 WD: Q63705067 47.54, 7.591 x 47.71, 7.849
    { 5300, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0072bc} }, // N6 OSM: 11522997 47.55, 7.587 x 47.59, 7.656
    { 1265, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffcf06} }, // M3 OSM: 11525600 WD: Q2637212 50.41, 4.43 x 50.48, 4.452
    { 5303, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // Thilawa OSM: 11548643 16.66, 96.16 x 16.86, 96.26
    { 5311, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // Eastern University OSM: 11548647 16.74, 96.16 x 16.86, 96.29
    { 5330, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // Ywar Thar Gyi OSM: 11548648 16.78, 96.16 x 16.93, 96.27
    { 5344, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffff00} }, // Computer University OSM: 11548671 16.78, 96.07 x 17.01, 96.16
    { 5364, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffff00} }, // Insein - Hlaw Karr OSM: 11548680 16.87, 96.08 x 17, 96.11
    { 5383, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // Dagon University OSM: 11549059 16.78, 96.16 x 16.91, 96.23
    { 5400, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x545656} }, // U Coimbra<=>Figueira OSM: 11562467 WD: Q125980002 40.12, -8.848 x 40.22, -8.432
    { 2142, NoLogo, 16935, LineMetaDataContent::Tramway, Color{0x858585} }, // 34 OSM: 11565304 WD: Q100991407 52.04, 4.244 x 52.08, 4.543
    { 5421, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe1e1ff} }, // SN 4 OSM: 11566470 50.97, -0.1728 x 51.5, 0.213
    { 5426, 34670, NoLogo, LineMetaDataContent::LocalTrain, Color{0x00bfff} }, // KK OSM: 11568311 WD: Q906807 35.18, 139.6 x 35.64, 139.8
    { 16, NoLogo, 24204, LineMetaDataContent::Subway, Color{0xfec30a} }, // 2 OSM: 11582700 WD: Q85776743 37.97, 114.5 x 38.09, 114.5
    { 27, 34696, NoLogo, LineMetaDataContent::Subway, Color{0x3abca8} }, // 6 OSM: 11583149 WD: Q6119435 22.54, 113.8 x 22.79, 114.1
    { 75, 34719, NoLogo, LineMetaDataContent::Subway, Color{0xf8779e} }, // 10 OSM: 11583622 WD: Q15925362 22.52, 114.1 x 22.7, 114.1
    { 697, 34743, NoLogo, LineMetaDataContent::RapidTransit, Color{0x449ad5} }, // R1 OSM: 11592118 WD: Q2395239 41.36, 2.02 x 41.77, 2.769
    { 8, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x84c8eb} }, // M4 OSM: 11592482 WD: Q1841724 50.41, 4.435 x 50.43, 4.503
    { 5429, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xee1d23} }, // E11 OSM: 11604709 WD: Q106925455 47.48, 7.584 x 47.55, 7.612
    { 5433, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfed304} }, // 2V OSM: 11610608 WD: Q1488532 48.1, 20.73 x 48.1, 20.81
    { 5436, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfed304} }, // 1V OSM: 11610610 WD: Q1484152 48.1, 20.68 x 48.11, 20.81
    { 5439, 34130, 20452, LineMetaDataContent::Subway, Color{0xf5a200} }, // 272 OSM: 11636212 WD: Q84389881 37.24, 126.6 x 37.58, 127.1
    { 5443, 34760, 34801, LineMetaDataContent::Tramway, Color{0xdce3e9} }, // T1a OSM: 11636568 WD: Q117008305 38.72, 35.37 x 38.79, 35.63
    { 5447, 34819, 34801, LineMetaDataContent::Tramway, Color{0xdce3e9} }, // T2a OSM: 11636816 WD: Q117008320 38.69, 35.49 x 38.73, 35.56
    { 5451, 34860, NoLogo, LineMetaDataContent::Subway, Color{0xb8007c} }, // TL-3 OSM: 11637375 WD: Q5986357 20.62, -103.4 x 20.74, -103.3
    { 289, 34760, 34801, LineMetaDataContent::Tramway, Color{0xdce3e9} }, // T1 OSM: 11641755 WD: Q117008305 38.72, 35.37 x 38.79, 35.63
    { 9, 34926, NoLogo, LineMetaDataContent::Subway, Color{0xffa500} }, // 4 OSM: 11643429 WD: Q24837537 24.86, 102.7 x 25.11, 102.9
    { 725, 34819, 34801, LineMetaDataContent::Tramway, Color{0xdce3e9} }, // T2 OSM: 11644048 WD: Q117008320 38.69, 35.49 x 38.73, 35.56
    { 5456, 34130, 20452, LineMetaDataContent::Subway, Color{0xf5a200} }, // 30205 OSM: 11651119 WD: Q84389881 37.36, 126.6 x 37.48, 126.7
    { 5462, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xc16c18} }, // 4–环–5 OSM: 11665748 29.41, 106.4 x 29.63, 106.7
    { 64, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xa78b6b} }, // 1 OSM: 11678493 WD: Q17440810 45.81, 15.95 x 45.82, 16.02
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf05972} }, // 2 OSM: 11678494 WD: Q17440806 45.79, 15.93 x 45.82, 16.04
    { 178, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xd19563} }, // 44 OSM: 11685877 WD: Q120720222 50.06, 19.94 x 50.08, 20.07
    { 22, 34946, NoLogo, LineMetaDataContent::Subway, Color{0x006272} }, // 18 OSM: 11697795 WD: Q22100462 30.27, 104.1 x 30.61, 104.5
    { 16, 34957, NoLogo, LineMetaDataContent::Subway, Color{0x005bac} }, // 2 OSM: 11697809 WD: Q82669483 40.75, 111.6 x 40.87, 111.8
    { 11, 34979, 9935, LineMetaDataContent::Subway, Color{0xff8040} }, // M5 OSM: 11697885 WD: Q1641397 44.41, 26.01 x 44.44, 26.07
    { 5474, 34995, NoLogo, LineMetaDataContent::Subway, Color{0x004da3} }, // TJ OSM: 11700880 WD: Q2782450 35.44, 139.2 x 36.12, 139.7
    { 5477, 35026, NoLogo, LineMetaDataContent::Subway, Color{0xed772d} }, // SI OSM: 11703137 WD: Q842649 35.72, 139.1 x 35.99, 139.7
    { 16, 35045, 28113, LineMetaDataContent::Subway, Color{0x008000} }, // 2 OSM: 11720074 WD: Q6427302 22.56, 88.33 x 22.59, 88.43
    { 279, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x406681} }, // B OSM: 11727456 35.02, 135.7 x 35.03, 135.7
    { 5480, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xa58704} }, // APM Gold Line OSM: 11747102 WD: Q25540775 13.72, 100.5 x 13.73, 100.5
    { 5494, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x81609f} }, // Π2 OSM: 11748540 WD: Q116036452 38.24, 21.73 x 38.3, 21.78
    { 5498, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf7ad41} }, // Π1 OSM: 11748541 WD: Q116036470 38.14, 21.56 x 38.24, 21.73
    { 314, 35085, 2564, LineMetaDataContent::RapidTransit, Color{0xd7df23} }, // S4 OSM: 11758267 WD: Q112707549 47.25, 11.08 x 47.58, 12.17
    { 52, 35098, 2564, LineMetaDataContent::RapidTransit, Color{0x5b9a6d} }, // S5 OSM: 11758341 WD: Q112707550 47.24, 10.86 x 47.39, 11.78
    { 225, 35111, 2564, LineMetaDataContent::RapidTransit, Color{0xb4bece} }, // S3 OSM: 11763862 WD: Q112707548 47, 11.39 x 47.26, 11.51
    { 55, 35124, 2564, LineMetaDataContent::RapidTransit, Color{0x257ca7} }, // S8 OSM: 11763916 WD: Q112707555 47.42, 12.06 x 47.52, 12.63
    { 667, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // C-1 OSM: 11784871 42.99, -4.141 x 43.46, -3.812
    { 228, 15413, NoLogo, LineMetaDataContent::LocalTrain, Color{0xfdda24} }, // 86967 OSM: 11792134 WD: Q205585 42.42, 2.866 x 43.83, 4.367
    { 5502, 15413, NoLogo, LineMetaDataContent::LocalTrain, Color{0xfdda24} }, // 86981 OSM: 11792135 WD: Q205585 42.42, 2.88 x 42.7, 3.168
    { 391, 15413, NoLogo, LineMetaDataContent::LocalTrain, Color{0xfdda24} }, // 86989 OSM: 11792146 WD: Q205585 42.42, 2.866 x 43.94, 4.805
    { 1387, 15413, NoLogo, LineMetaDataContent::LocalTrain, Color{0xfdda24} }, // 86987 OSM: 11792148 WD: Q205585 42.42, 2.866 x 43.94, 4.805
    { 1032, 15413, NoLogo, LineMetaDataContent::LocalTrain, Color{0xfdda24} }, // 86998 OSM: 11792152 WD: Q205585 42.42, 2.866 x 43.83, 4.366
    { 431, 15413, NoLogo, LineMetaDataContent::LocalTrain, Color{0xfdda24} }, // 86996 OSM: 11792153 WD: Q205585 42.42, 2.866 x 43.83, 4.366
    { 5508, 15413, NoLogo, LineMetaDataContent::LocalTrain, Color{0xfdda24} }, // 86960 OSM: 11792154 WD: Q205585 42.42, 2.879 x 42.7, 3.168
    { 5514, 15413, NoLogo, LineMetaDataContent::LocalTrain, Color{0xfdda24} }, // 86964 OSM: 11792157 WD: Q205585 42.42, 2.879 x 42.7, 3.168
    { 1411, 35144, NoLogo, LineMetaDataContent::RapidTransit, Color{0x9a897e} }, // E5 OSM: 11796871 WD: Q104233835 43.3, -1.983 x 43.32, -1.931
    { 1329, 35161, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfab700} }, // T3 OSM: 11797706 WD: Q5986343 39.57, 2.654 x 39.72, 3.203
    { 725, 35172, NoLogo, LineMetaDataContent::RapidTransit, Color{0x6495ed} }, // T2 OSM: 11797707 WD: Q5986167 39.58, 2.654 x 39.76, 3.034
    { 289, 35172, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // T1 OSM: 11797708 WD: Q5986167 39.58, 2.654 x 39.72, 2.908
    { 68, 35183, NoLogo, LineMetaDataContent::Subway, Color{0x0088ee} }, // 3 OSM: 11798336 WD: Q19852709 31.5, 120.2 x 31.6, 120.4
    { 2696, 35208, NoLogo, LineMetaDataContent::Subway, Color{0xf5a300} }, // TN OSM: 11801852 WD: Q3449834 35.51, 139.4 x 36.85, 139.9
    { 5520, 35240, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe71212} }, // TI OSM: 11801907 WD: Q1049699 36.02, 139.2 x 36.43, 139.7
    { 186, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xf7943a} }, // O OSM: 11803501 WD: Q18385578 31.46, 74.24 x 31.59, 74.43
    { 27, NoLogo, 8099, LineMetaDataContent::Subway, Color{0x0099cc} }, // 6 OSM: 11807149 WD: Q3832666 40.82, 14.19 x 40.84, 14.25
    { 1329, 35274, NoLogo, LineMetaDataContent::Tramway, Color{0xcc0099} }, // T3 OSM: 11813038 WD: Q117327547 36.88, 30.66 x 36.99, 30.72
    { 725, 35315, NoLogo, LineMetaDataContent::Tramway, Color{0x027ffd} }, // T2 OSM: 11813041 WD: Q116369823 36.87, 30.68 x 36.89, 30.72
    { 5523, 35356, NoLogo, LineMetaDataContent::Tramway, Color{0xff6400} }, // T1A OSM: 11813042 WD: Q117327542 36.89, 30.64 x 36.94, 30.81
    { 5527, 35398, NoLogo, LineMetaDataContent::Tramway, Color{0xff6400} }, // T1B OSM: 11813043 WD: Q117327753 36.89, 30.64 x 36.95, 30.88
    { 5531, 35440, NoLogo, LineMetaDataContent::LocalTrain, Color{} }, // FEX OSM: 11815470 WD: Q100533383 52.36, 13.36 x 52.55, 13.6
    { 5539, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // CK OSM: 11830794 WD: Q5097496 33.75, 130.7 x 33.87, 130.8
    { 279, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00569d} }, // B OSM: 11833214 WD: Q3239066 47.47, -0.6035 x 47.49, -0.5266
    { 34, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0072bc} }, // H OSM: 11839798 WD: Q1074266 42.64, 141.3 x 43.11, 141.7
    { 68, NoLogo, 22580, LineMetaDataContent::Subway, Color{0x008000} }, // 3 OSM: 11845129 WD: Q2889805 53.88, 27.54 x 53.9, 27.55
    { 5542, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xd12027} }, // NH OSM: 11851821 WD: Q1137838 34.76, 136.8 x 35.41, 137.4
    { 524, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // L2 OSM: 11871074 WD: Q121834206 30.45, 114.4 x 30.5, 114.5
    { 520, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000cd} }, // L1 OSM: 11871075 WD: Q121834229 30.44, 114.4 x 30.51, 114.4
    { 1892, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfece0c} }, // Gold OSM: 11873946 WD: Q5059275 35.21, -80.86 x 35.25, -80.82
    { 68, 35459, NoLogo, LineMetaDataContent::Subway, Color{0xa5b635} }, // 3 OSM: 11899105 WD: Q30641320 21.03, 105.7 x 21.05, 105.8
    { 569, 35489, NoLogo, LineMetaDataContent::LocalTrain, Color{0xcb8daa} }, // RB 48 OSM: 11913928 WD: Q107023360 48.04, 11.6 x 48.13, 12.19
    { 5545, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // Т1 OSM: 11921539 59.94, 30.26 x 59.96, 30.35
    { 725, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xde1c77} }, // T2 OSM: 11922903 WD: Q108045346 50.3, 18.73 x 50.4, 18.92
    { 9, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xdae600} }, // 4 OSM: 11923211 WD: Q26262003 22.75, 108.2 x 22.77, 108.5
    { 1273, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xd77d00} }, // 31 OSM: 11997852 WD: Q1760190 59.33, 17.95 x 59.36, 17.98
    { 330, 35506, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 25 OSM: 12010107 WD: Q2619013 52.23, 4.811 x 52.34, 4.876
    { 2185, 35517, 226, LineMetaDataContent::RapidTransit, Color{0x009640} }, // S44 OSM: 12014995 WD: Q122841884 49.47, 8.428 x 49.52, 8.442
    { 64, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x509e2f} }, // 1 OSM: 12021098 WD: Q120550959 55.71, 13.19 x 55.73, 13.24
    { 27, 35537, NoLogo, LineMetaDataContent::Subway, Color{0xb36924} }, // 6 OSM: 12039115 WD: Q22100481 30.43, 103.9 x 30.81, 104.1
    { 524, NoLogo, 33055, LineMetaDataContent::Tramway, Color{0x004f9f} }, // L2 OSM: 12078298 WD: Q3238814 43.66, 7.199 x 43.7, 7.285
    { 19, 35547, NoLogo, LineMetaDataContent::Subway, Color{0x88dd00} }, // 8 OSM: 12086373 WD: Q26262006 30.54, 104 x 30.72, 104.2
    { 239, 35557, NoLogo, LineMetaDataContent::Subway, Color{0x80e0a7} }, // 17 OSM: 12095438 WD: Q28973151 30.64, 103.9 x 30.65, 104
    { 1080, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffffff} }, // S10 OSM: 12110561 47.86, 7.83 x 48.06, 8.504
    { 411, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x379e32} }, // C OSM: 12112440 WD: Q55597911 47.44, -0.6035 x 47.48, -0.5492
    { 47, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 7 OSM: 12114202 WD: Q122917038 44.78, 20.37 x 44.81, 20.52
    { 146, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 9 OSM: 12114471 WD: Q100151898 44.76, 20.37 x 44.81, 20.48
    { 63, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 11 OSM: 12114747 WD: Q122917039 44.79, 20.37 x 44.83, 20.46
    { 67, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 13 OSM: 12115860 WD: Q122917041 44.77, 20.37 x 44.81, 20.43
    { 64, NoLogo, 35568, LineMetaDataContent::Tramway, Color{0x00985f} }, // 1 OSM: 12116142 WD: Q111355036 60.16, 24.92 x 60.22, 24.96
    { 16, NoLogo, 35568, LineMetaDataContent::Tramway, Color{0x00985f} }, // 2 OSM: 12116144 WD: Q111354560 60.16, 24.92 x 60.2, 24.96
    { 68, NoLogo, 35568, LineMetaDataContent::Tramway, Color{0x00985f} }, // 3 OSM: 12116149 WD: Q111354658 60.16, 24.89 x 60.21, 24.96
    { 9, NoLogo, 35568, LineMetaDataContent::Tramway, Color{0x00985f} }, // 4 OSM: 12116155 WD: Q111354573 60.17, 24.87 x 60.2, 24.98
    { 6, NoLogo, 35568, LineMetaDataContent::Tramway, Color{0x00985f} }, // 5 OSM: 12116158 WD: Q111355032 60.16, 24.94 x 60.17, 24.97
    { 27, NoLogo, 35568, LineMetaDataContent::Tramway, Color{0x00985f} }, // 6 OSM: 12116159 WD: Q111354303 60.15, 24.93 x 60.21, 24.98
    { 47, NoLogo, 35568, LineMetaDataContent::Tramway, Color{0x00985f} }, // 7 OSM: 12116160 WD: Q111354531 60.15, 24.91 x 60.2, 24.96
    { 19, NoLogo, 35568, LineMetaDataContent::Tramway, Color{0x00985f} }, // 8 OSM: 12116163 WD: Q111354700 60.15, 24.91 x 60.21, 24.98
    { 146, NoLogo, 35568, LineMetaDataContent::Tramway, Color{0x00985f} }, // 9 OSM: 12116164 WD: Q111354553 60.15, 24.91 x 60.21, 24.95
    { 75, NoLogo, 35568, LineMetaDataContent::Tramway, Color{0x00985f} }, // 10 OSM: 12116165 WD: Q111354624 60.16, 24.93 x 60.2, 24.96
    { 9, 35593, NoLogo, LineMetaDataContent::Subway, Color{0xabcd03} }, // 4 OSM: 12144421 WD: Q10946023 29.78, 121.4 x 29.98, 121.6
    { 5549, 35614, NoLogo, LineMetaDataContent::LocalTrain, Color{0xffb200} }, // RB 14 OSM: 12144619 WD: Q106109581 48.74, 11.16 x 48.9, 11.44
    { 6, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0a9eda} }, // 5 OSM: 12148182 WD: Q692803 40.81, 14.04 x 40.88, 14.25
    { 1396, 35631, NoLogo, LineMetaDataContent::Tramway, Color{0x7c72b3} }, // T5 OSM: 12174617 WD: Q48848864 41.02, 28.94 x 41.09, 28.97
    { 59, 35659, 2564, LineMetaDataContent::RapidTransit, Color{0x4f9961} }, // S2 OSM: 12206186 WD: Q112707418 46.73, 12.27 x 46.83, 12.77
    { 161, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xbe1622} }, // 19 OSM: 12226279 WD: Q121368369 44.38, 26.08 x 44.43, 26.2
    { 157, 35672, NoLogo, LineMetaDataContent::Subway, Color{0xbba786} }, // 15 OSM: 12231218 WD: Q6553078 31.02, 121.4 x 31.35, 121.4
    { 1113, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x00c000} }, // 2A OSM: 12231738 WD: Q30919856 20.95, 105.7 x 21.03, 105.8
    { 16, 35682, NoLogo, LineMetaDataContent::Tramway, Color{0xfab71b} }, // 2 OSM: 12232119 WD: Q121359279 50.89, 11.58 x 50.93, 11.62
    { 6, 35706, NoLogo, LineMetaDataContent::Tramway, Color{0x6a2e74} }, // 5 OSM: 12232120 WD: Q121359282 50.88, 11.58 x 50.93, 11.64
    { 9, 35730, NoLogo, LineMetaDataContent::Tramway, Color{0xda020e} }, // 4 OSM: 12232121 WD: Q121359281 50.88, 11.58 x 50.96, 11.62
    { 68, 35754, NoLogo, LineMetaDataContent::Tramway, Color{0x7f5f00} }, // 3 OSM: 12232122 WD: Q121359280 50.88, 11.58 x 50.9, 11.64
    { 64, 35778, NoLogo, LineMetaDataContent::Tramway, Color{0xe94c0a} }, // 1 OSM: 12232123 WD: Q121359278 50.88, 11.58 x 50.96, 11.62
    { 5555, 35802, NoLogo, LineMetaDataContent::LocalTrain, Color{0xffffff} }, // RB 54 OSM: 12233202 WD: Q113229669 47.58, 11.53 x 48.14, 12.2
    { 5561, 35819, NoLogo, LineMetaDataContent::LocalTrain, Color{} }, // RE 5 OSM: 12234223 WD: Q113228374 47.81, 11.53 x 48.14, 13.05
    { 5566, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x99d7dc} }, // 4XX OSM: 12246239 WD: Q130355183 37.33, -122.4 x 37.78, -121.9
    { 712, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffbf00} }, // A OSM: 12249521 WD: Q4647009 32.98, -97.13 x 33.21, -96.93
    { 2225, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x2f4f4f} }, // 102 OSM: 12315495 WD: Q121688873 44.29, 23.72 x 44.39, 23.85
    { 1453, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x2f4f4f} }, // 100 OSM: 12315496 WD: Q121688751 44.31, 23.77 x 44.34, 23.83
    { 2161, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x2f4f4f} }, // 101 OSM: 12315497 WD: Q121688812 44.29, 23.75 x 44.36, 23.85
    { 5570, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe3e049} }, // TECO OSM: 12321313 27.94, -82.46 x 27.96, -82.44
    { 5575, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xdb161c} }, // QLine OSM: 12330605 42.33, -83.07 x 42.37, -83.05
    { 418, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // M OSM: 12331275 WD: Q123244689 43.03, -87.92 x 43.05, -87.9
    { 414, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // S OSM: 12332844 34.65, 133.9 x 34.67, 133.9
    { 34, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // H OSM: 12332845 34.66, 133.9 x 34.67, 133.9
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // 2 OSM: 12340019 WD: Q18155116 29.95, -90.07 x 29.96, -90.06
    { 572, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x90ee90} }, // 48 OSM: 12340020 WD: Q121433227 29.96, -90.1 x 29.98, -90.08
    { 739, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 47 OSM: 12340021 29.95, -90.11 x 29.98, -90.07
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 12 OSM: 12340022 WD: Q18155455 29.93, -90.13 x 29.96, -90.07
    { 367, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00aae4} }, // Blue OSM: 12340243 34.74, -92.27 x 34.76, -92.26
    { 653, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x66ff00} }, // Green OSM: 12340244 34.74, -92.27 x 34.75, -92.26
    { 64, NoLogo, 8099, LineMetaDataContent::Subway, Color{0xfeca1b} }, // 1 OSM: 12341393 WD: Q1085934 40.84, 14.22 x 40.9, 14.27
    { 725, NoLogo, 35835, LineMetaDataContent::Tramway, Color{0x50ab43} }, // T2 OSM: 12342707 WD: Q30634535 38.4, 27.07 x 38.44, 27.17
    { 1594, NoLogo, 35855, LineMetaDataContent::RapidTransit, Color{0x800080} }, // Purple OSM: 12356340 WD: Q4533683 29.7, -95.37 x 29.76, -95.33
    { 379, NoLogo, 35855, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // Red OSM: 12356341 WD: Q16934038 29.67, -95.41 x 29.83, -95.36
    { 653, NoLogo, 35855, LineMetaDataContent::RapidTransit, Color{0x008000} }, // Green OSM: 12356342 WD: Q4262189 29.74, -95.37 x 29.76, -95.3
    { 5581, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff1b6e} }, // APT Rose OSM: 12360663 32.86, -96.94 x 32.87, -96.93
    { 5590, 35878, 14994, LineMetaDataContent::RapidTransit, Color{0xe2007a} }, // m1 OSM: 12371355 WD: Q685114 46.52, 6.564 x 46.54, 6.63
    { 289, NoLogo, 35835, LineMetaDataContent::Tramway, Color{0x50ab43} }, // T1 OSM: 12378475 WD: Q21523607 38.45, 27.06 x 38.49, 27.13
    { 68, 35905, NoLogo, LineMetaDataContent::Subway, Color{0xff8000} }, // 3 OSM: 12380649 WD: Q56377988 25.67, -100.3 x 25.71, -100.3
    { 6, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xc1d522} }, // 5 OSM: 12385671 WD: Q43445187 31.7, 117.3 x 31.94, 117.3
    { 68, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xbe1622} }, // 3 OSM: 12400122 WD: Q97197739 44.47, 26.02 x 44.49, 26.07
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x146eb7} }, // 4 OSM: 12400338 WD: Q107104582 40.83, 14.26 x 40.85, 14.31
    { 64, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x4096d2} }, // 1 OSM: 12400369 WD: Q107104562 40.84, 14.26 x 40.87, 14.29
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x267cc0} }, // 2 OSM: 12400406 WD: Q107104575 40.83, 14.27 x 40.87, 14.31
    { 298, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa349a4} }, // S6 OSM: 12405171 WD: Q125996922 48.94, 16.61 x 49.19, 17.47
    { 1084, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x1c3f94} }, // 399 OSM: 12417807 33.12, -117.4 x 33.22, -117.1
    { 16, 35919, NoLogo, LineMetaDataContent::RapidTransit, Color{0x025257} }, // 2 OSM: 12462807 WD: Q2274338 40.82, 14.13 x 40.86, 14.31
    { 9, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x203f7d} }, // 4 OSM: 12462853 WD: Q1000745 40.81, 14.04 x 40.85, 14.25
    { 5593, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0d82c7} }, // OH OSM: 12463786 WD: Q11430772 35.23, 139 x 35.69, 139.7
    { 5596, 35938, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0090d3} }, // E3a OSM: 12498778 WD: Q43223339 43.29, -2.97 x 43.3, -2.928
    { 298, 35956, 226, LineMetaDataContent::RapidTransit, Color{0xd72319} }, // S6 OSM: 12524258 WD: Q110186534 49.44, 10.58 x 49.58, 11.08
    { 5600, 35973, NoLogo, LineMetaDataContent::LocalTrain, Color{0xe50000} }, // RE 31 OSM: 12529911 WD: Q113462372 49.44, 11.08 x 50.31, 12.09
    { 5606, 35990, NoLogo, LineMetaDataContent::LocalTrain, Color{} }, // RE 32 OSM: 12535805 WD: Q113462373 49.9, 10.89 x 50.16, 11.6
    { 5612, 36007, NoLogo, LineMetaDataContent::LocalTrain, Color{} }, // RE 35 OSM: 12535884 WD: Q113462494 49.9, 10.89 x 50.31, 11.94
    { 5618, 36024, NoLogo, LineMetaDataContent::LocalTrain, Color{} }, // RB 18 OSM: 12548478 WD: Q104149638 50.26, 10.78 x 50.34, 10.96
    { 5624, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x4682b4} }, // Airside C OSM: 12560187 WD: Q121502054 27.98, -82.53 x 27.98, -82.53
    { 5634, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x4682b4} }, // Airside F OSM: 12560190 WD: Q121502074 27.98, -82.54 x 27.98, -82.54
    { 5644, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x4682b4} }, // Airside A OSM: 12560197 WD: Q121502044 27.98, -82.53 x 27.98, -82.53
    { 1818, 36041, 6136, LineMetaDataContent::Tramway, Color{0x5291ce} }, // T9 OSM: 12564972 WD: Q3537038 48.75, 2.365 x 48.82, 2.419
    { 289, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xd22630} }, // T1 OSM: 12567203 39.71, 116.5 x 39.8, 116.6
    { 5654, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x015dab} }, // Atlantic City OSM: 12577780 WD: Q756350 39.36, -75.2 x 40.01, -74.44
    { 289, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x800080} }, // T1 OSM: 12603876 WD: Q98199553 33.49, 119 x 33.6, 119.2
    { 520, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xced64d} }, // L1 OSM: 12606970 WD: Q107191166 37.99, -1.174 x 38.04, -1.124
    { 3007, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x78b942} }, // Verde OSM: 12632067 -9.672, -35.74 x -9.65, -35.72
    { 3038, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x1a5ba3} }, // Azul OSM: 12632071 WD: Q124719723 -9.625, -35.86 x -9.478, -35.75
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xed1c24} }, // 2 OSM: 12661403 WD: Q121361538 50.49, 12.13 x 50.51, 12.17
    { 8, 36074, 22626, LineMetaDataContent::Subway, Color{0xffff00} }, // M4 OSM: 12668937 WD: Q101570868 42.65, 23.26 x 42.74, 23.42
    { 64, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfdc434} }, // 1 OSM: 12686111 WD: Q56388740 46.24, 20.12 x 46.42, 20.34
    { 68, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 3 OSM: 12758107 WD: Q112487273 61.44, 23.77 x 61.5, 23.87
    { 598, 36099, NoLogo, LineMetaDataContent::Tramway, Color{0x81cf00} }, // R OSM: 12765542 WD: Q3239181 50.64, 3.071 x 50.69, 3.179
    { 39, 36119, NoLogo, LineMetaDataContent::Tramway, Color{0x0099ff} }, // T OSM: 12765723 WD: Q3239234 50.64, 3.071 x 50.72, 3.159
    { 64, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // 1 OSM: 12771497 WD: Q11676681 31.53, 130.5 x 31.6, 130.6
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 2 OSM: 12771498 WD: Q11676682 31.56, 130.5 x 31.6, 130.6
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x005bac} }, // 2 OSM: 12791164 WD: Q19856264 26.52, 106.6 x 26.7, 106.8
    { 5668, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xcc0000} }, // UAE Exchange OSM: 12820286 WD: Q97940934 24.98, 55.09 x 25.06, 55.13
    { 9, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff8000} }, // 4 OSM: 12824987 13.03, 80.08 x 13.05, 80.28
    { 6, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // 5 OSM: 12828618 12.9, 80.16 x 13.16, 80.24
    { 5681, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // IR87 OSM: 12856601 47.49, 19.08 x 47.89, 20.42
    { 5686, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xaacd46} }, // G40 OSM: 12856603 WD: Q112963120 46.37, 18.15 x 47.5, 19.04
    { 5690, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffcd28} }, // Z42 OSM: 12856604 WD: Q112225437 46.96, 18.76 x 47.5, 19.04
    { 64, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x1b5eab} }, // 1 OSM: 12884475 WD: Q104632069 37.76, 112.4 x 37.86, 112.6
    { 68, NoLogo, 28866, LineMetaDataContent::Subway, Color{0x0c89de} }, // 3 OSM: 12893656 WD: Q47500936 24.43, 118.1 x 24.58, 118.3
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x529fc9} }, // 2 OSM: 12914035 WD: Q106783516 31.75, 119.9 x 31.8, 120.1
    { 64, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xc5003e} }, // 1 OSM: 12920991 WD: Q24835360 29.92, 120.2 x 30.31, 120.6
    { 239, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0b4355} }, // 17 OSM: 12925063 WD: Q67934269 34.05, 113.8 x 34.61, 113.9
    { 6, 36139, NoLogo, LineMetaDataContent::Subway, Color{0xa6e35f} }, // 5 OSM: 12925442 WD: Q15939245 34.22, 108.7 x 34.27, 109
    { 68, 33196, 33196, LineMetaDataContent::Subway, Color{0x008bd5} }, // 3 OSM: 12935364 WD: Q47291030 34.15, 117.2 x 34.28, 117.2
    { 16, 33196, 33196, LineMetaDataContent::Subway, Color{0xef8200} }, // 2 OSM: 12935365 WD: Q47004987 34.21, 117.2 x 34.33, 117.3
    { 68, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x800080} }, // 3 OSM: 12940682 12.82, 80.22 x 13.15, 80.27
    { 64, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xc4608c} }, // 1 OSM: 12942003 WD: Q15936968 34.66, 112.3 x 34.7, 112.6
    { 27, 36159, NoLogo, LineMetaDataContent::Subway, Color{0x485cc7} }, // 6 OSM: 13040751 WD: Q52596166 34.12, 108.8 x 34.28, 109.1
    { 146, 36179, NoLogo, LineMetaDataContent::Subway, Color{0xff9e1b} }, // 9 OSM: 13042254 WD: Q97350661 34.27, 109.1 x 34.4, 109.2
    { 19, 36199, NoLogo, LineMetaDataContent::Subway, Color{0xac145a} }, // 8 OSM: 13042427 WD: Q11102451 30.3, 120.4 x 30.31, 120.5
    { 3207, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xa065aa} }, // U2Z OSM: 13045481 WD: Q118746734 48.2, 16.36 x 48.22, 16.37
    { 146, 36209, NoLogo, LineMetaDataContent::Subway, Color{0xbe4d00} }, // 9 OSM: 13060970 WD: Q18653898 30.25, 120.2 x 30.46, 120.3
    { 64, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xdfaa00} }, // 1 OSM: 13067815 WD: Q15935678 35.94, 120.2 x 36.34, 120.4
    { 19, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xdf1995} }, // 8 OSM: 13068450 WD: Q22100048 36.17, 120 x 36.4, 120.4
    { 64, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 1 OSM: 13072753 WD: Q112485271 61.5, 23.72 x 61.51, 23.82
    { 27, 36219, NoLogo, LineMetaDataContent::Subway, Color{0x0072ce} }, // 6 OSM: 13077350 WD: Q11102449 30.05, 119.9 x 30.3, 120.2
    { 9, 36233, NoLogo, LineMetaDataContent::Subway, Color{0x6bc349} }, // 4 OSM: 13077360 WD: Q11102444 30.16, 120.1 x 30.36, 120.2
    { 5694, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x273583} }, // TER 22 OSM: 13081021 WD: Q123653112 45.15, 0.6938 x 47.39, 4.862
    { 71, 36253, NoLogo, LineMetaDataContent::Subway, Color{0x1b61ae} }, // S1 OSM: 13084233 WD: Q15910427 27.91, 120.6 x 27.99, 121
    { 146, 36284, NoLogo, LineMetaDataContent::Subway, Color{0xffb81c} }, // 9 OSM: 13088859 WD: Q28972638 30.58, 104 x 30.7, 104.1
    { 6, 36294, NoLogo, LineMetaDataContent::Subway, Color{0xe93cac} }, // 5 OSM: 13091428 WD: Q6553133 31.23, 120.4 x 31.37, 120.8
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf90303} }, // 5 OSM: 13118861 WD: Q121662891 54.68, 20.45 x 54.73, 20.53
    { 5701, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x5eb3e4} }, // TNH1 OSM: 13124236 WD: Q18651563 23, 113.2 x 23.04, 113.2
    { 5706, 36315, NoLogo, LineMetaDataContent::LongDistanceTrain, Color{0x005619} }, // IR 35 OSM: 13131233 WD: Q115996431 46.85, 7.434 x 47.44, 9.562
    { 5712, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xd42d1b} }, // THP1 OSM: 13140107 WD: Q63687256 23.18, 113.5 x 23.22, 113.5
    { 5717, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // Ouargla tram OSM: 13159622 WD: Q123362872 31.94, 5.265 x 31.96, 5.333
    { 1647, NoLogo, 36330, LineMetaDataContent::RapidTransit, Color{} }, // M95 OSM: 13167233 WD: Q3897221 38.1, 13.11 x 38.2, 13.38
    { 16, 36351, NoLogo, LineMetaDataContent::Subway, Color{0xdb6d1c} }, // 2 OSM: 13176924 WD: Q5947229 22.48, 113.9 x 22.57, 114.2
    { 19, 36374, NoLogo, LineMetaDataContent::Subway, Color{0xdb6d1c} }, // 8 OSM: 13176927 WD: Q11174946 22.56, 114.2 x 22.61, 114.3
    { 5730, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7a121c} }, // EKV OSM: 13180873 WD: Q124522867 -1.323, 36.83 x -1.289, 36.92
    { 5734, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7a121c} }, // LKY OSM: 13180875 WD: Q124527576 -1.49, 36.83 x -1.289, 37
    { 178, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xbe1622} }, // 44 OSM: 13199272 WD: Q61082462 44.44, 26.02 x 44.47, 26.09
    { 298, 36397, 12736, LineMetaDataContent::Subway, Color{0xb58bd7} }, // S6 OSM: 13200482 WD: Q10945834 31.92, 118.9 x 32.06, 119.2
    { 63, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce7f46} }, // 11 OSM: 13217860 55.7, 52.34 x 55.74, 52.47
    { 47, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x808080} }, // 7 OSM: 13242817 WD: Q122395005 49.17, 16.55 x 49.23, 16.63
    { 22, 36418, NoLogo, LineMetaDataContent::Subway, Color{0x0047ba} }, // 18 OSM: 13246294 WD: Q11062044 22.7, 113.3 x 23.13, 113.6
    { 16, 36439, NoLogo, LineMetaDataContent::Subway, Color{0x00ae59} }, // 2 OSM: 13250192 WD: Q10921993 45.72, 126.5 x 45.87, 126.7
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00008b} }, // 5 OSM: 13252243 WD: Q123353000 56.45, 84.95 x 56.48, 84.99
    { 5738, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x37bbed} }, // TRS OSM: 13262889 WD: Q39081226 -24.98, -65.65 x -24.65, -65.04
    { 5742, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf3c847} }, // Northern Express OSM: 13296139 -34.12, 18.43 x -33.91, 18.86
    { 5759, 36463, 4547, LineMetaDataContent::Subway, Color{0xa12830} }, // 1E OSM: 13298577 WD: Q1039452 39.85, 116.5 x 39.91, 116.7
    { 16, 36488, NoLogo, LineMetaDataContent::Tramway, Color{0x009cdd} }, // 2 OSM: 13305615 WD: Q13390010 53.38, 14.55 x 53.45, 14.64
    { 5762, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // TAD OSM: 13308590 WD: Q18286525 -27.78, -64.27 x -27.73, -64.24
    { 5766, 36508, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7a745a} }, // F1 OSM: 13313680 WD: Q503503 41.03, 28.99 x 41.04, 28.99
    { 5769, 36536, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7a745a} }, // F2 OSM: 13313681 WD: Q387264 41.02, 28.97 x 41.03, 28.97
    { 9, 36564, NoLogo, LineMetaDataContent::Subway, Color{0x00a0e9} }, // 4 OSM: 13317505 WD: Q15938386 34.68, 113.6 x 34.83, 113.7
    { 68, 36583, NoLogo, LineMetaDataContent::Subway, Color{0xf39939} }, // 3 OSM: 13317992 WD: Q15950459 34.67, 113.6 x 34.84, 113.8
    { 520, 36602, 25988, LineMetaDataContent::Subway, Color{0xff7400} }, // L1 OSM: 13335174 WD: Q6515333 10.48, -66.96 x 10.52, -66.79
    { 5772, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x37bbed} }, // TPC OSM: 13341386 -31.77, -60.53 x -31.73, -60.29
    { 516, 36623, 25988, LineMetaDataContent::Subway, Color{0xfff000} }, // L4 OSM: 13350037 WD: Q21659772 10.43, -67.01 x 10.5, -66.84
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 6 OSM: 13372659 WD: Q114829246 49.58, 17.23 x 49.6, 17.28
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x1871b3} }, // 5 OSM: 13372660 WD: Q114829245 49.57, 17.25 x 49.59, 17.28
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffa500} }, // 4 OSM: 13372661 WD: Q114829243 49.58, 17.23 x 49.6, 17.29
    { 68, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 3 OSM: 13372662 WD: Q114829242 49.57, 17.25 x 49.6, 17.28
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x40e0d0} }, // 2 OSM: 13372663 WD: Q114829241 49.59, 17.22 x 49.6, 17.28
    { 64, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff69b4} }, // 1 OSM: 13372664 WD: Q114829240 49.58, 17.23 x 49.59, 17.28
    { 47, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x77b5fe} }, // 7 OSM: 13372665 WD: Q114829247 49.59, 17.22 x 49.6, 17.28
    { 16, NoLogo, 19, LineMetaDataContent::Tramway, Color{0xffcc00} }, // 2 OSM: 13395428 WD: Q121355964 51.29, 12.28 x 51.34, 12.44
    { 146, NoLogo, 19, LineMetaDataContent::Tramway, Color{0xffcc00} }, // 9 OSM: 13397093 WD: Q121345246 51.3, 12.37 x 51.38, 12.43
    { 2161, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 101 OSM: 13397151 WD: Q122781322 44.93, 26 x 44.96, 26.03
    { 2225, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 102 OSM: 13397152 WD: Q122781344 44.93, 25.99 x 44.96, 26.01
    { 26, 36644, NoLogo, LineMetaDataContent::Tramway, Color{0x2f4f4f} }, // 16 OSM: 13401153 WD: Q121753792 46.17, 21.32 x 46.2, 21.34
    { 157, 36661, NoLogo, LineMetaDataContent::Tramway, Color{0x2f4f4f} }, // 15 OSM: 13401154 WD: Q121753790 46.18, 21.29 x 46.2, 21.34
    { 15, 36678, NoLogo, LineMetaDataContent::Tramway, Color{0x2f4f4f} }, // 12 OSM: 13401155 WD: Q121753786 46.14, 21.32 x 46.18, 21.59
    { 63, 36695, NoLogo, LineMetaDataContent::Tramway, Color{0x2f4f4f} }, // 11 OSM: 13401156 WD: Q121753785 46.14, 21.29 x 46.2, 21.59
    { 27, 36712, NoLogo, LineMetaDataContent::Tramway, Color{0x2f4f4f} }, // 6 OSM: 13401157 WD: Q121753780 46.17, 21.28 x 46.21, 21.33
    { 47, 36728, NoLogo, LineMetaDataContent::Tramway, Color{0x2f4f4f} }, // 7 OSM: 13401158 WD: Q121753781 46.17, 21.29 x 46.2, 21.36
    { 68, 36744, NoLogo, LineMetaDataContent::Tramway, Color{0x2f4f4f} }, // 3 OSM: 13401159 WD: Q121753779 46.14, 21.29 x 46.2, 21.33
    { 64, 36760, NoLogo, LineMetaDataContent::Tramway, Color{0x2f4f4f} }, // 1 OSM: 13401160 WD: Q121753777 46.17, 21.29 x 46.2, 21.33
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 8 OSM: 13408524 47.05, 21.9 x 47.08, 21.93
    { 3718, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x966c29} }, // 6A OSM: 13417394 WD: Q121317837 49.44, 8.419 x 49.49, 8.518
    { 5776, 36776, NoLogo, LineMetaDataContent::Tramway, Color{0x2f4f4f} }, // 15b OSM: 13423415 WD: Q121753791 46.18, 21.29 x 46.22, 21.35
    { 349, 36794, NoLogo, LineMetaDataContent::Tramway, Color{0x9462b1} }, // 23 OSM: 13443923 WD: Q121419539 47.07, 15.44 x 47.07, 15.46
    { 262, 17868, NoLogo, LineMetaDataContent::LocalTrain, Color{} }, // 38 OSM: 13445438 WD: Q9025925 41.62, -0.9127 x 42, 0.6352
    { 3466, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffff00} }, // Yellow Line OSM: 13475082 25.31, 51.42 x 25.32, 51.45
    { 67, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 13 OSM: 13489151 WD: Q62302293 52.1, 11.59 x 52.11, 11.65
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xffda01} }, // 2 OSM: 13502832 WD: Q6850047 28.56, 115.8 x 28.7, 116
    { 68, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0079c3} }, // 3 OSM: 13507037 WD: Q10908095 28.52, 115.9 x 28.7, 116
    { 47, 36806, NoLogo, LineMetaDataContent::Subway, Color{0x88129e} }, // 7 OSM: 13528567 WD: Q11102450 30.2, 120.2 x 30.33, 120.5
    { 75, 36816, NoLogo, LineMetaDataContent::Subway, Color{0xdaa520} }, // 10 OSM: 13535688 WD: Q18653896 30.27, 120.1 x 30.38, 120.1
    { 9, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff850d} }, // 4 OSM: 13536846 WD: Q43283453 31.76, 117.1 x 31.95, 117.3
    { 68, 36827, NoLogo, LineMetaDataContent::Subway, Color{0xffd700} }, // 3 OSM: 13538221 WD: Q11102442 30.21, 120 x 30.39, 120.3
    { 64, 36847, 20452, LineMetaDataContent::Subway, Color{0x009088} }, // 1 OSM: 13538911 WD: Q626996 35.11, 126.8 x 35.16, 126.9
    { 46, 36872, 226, LineMetaDataContent::RapidTransit, Color{0x004f9e} }, // S7 OSM: 13540625 WD: Q63217583 51.45, 11.55 x 51.52, 12
    { 9, 36897, NoLogo, LineMetaDataContent::Subway, Color{0x800080} }, // 4 OSM: 13540934 WD: Q19852710 31.47, 120.3 x 31.63, 120.3
    { 6, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x3b62a9} }, // 5 OSM: 13557463 WD: Q26262004 22.75, 108.3 x 22.87, 108.4
    { 5780, 36922, 226, LineMetaDataContent::RapidTransit, Color{0x50af47} }, // S 47 OSM: 13562799 WD: Q115234715 51.48, 11.96 x 51.52, 11.99
    { 2196, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00b9f2} }, // SKA1 OSM: 13563236 WD: Q125997734 49.99, 19.8 x 50.08, 20.06
    { 1096, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // S12 OSM: 13566082 48.87, 8.347 x 49.02, 8.518
    { 2075, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe6007e} }, // SKA2 OSM: 13571816 WD: Q125998347 49.96, 19.2 x 50.57, 20.1
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x6fba2c} }, // 2 OSM: 13592842 WD: Q48899497 34.6, 112.4 x 34.71, 112.5
    { 5769, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xc10230} }, // F2 OSM: 13604445 WD: Q10886732 22.97, 113 x 23.01, 113.3
    { 68, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 3 OSM: 13606198 WD: Q785655 41.87, 12.47 x 41.92, 12.52
    { 64, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xffa500} }, // 1 OSM: 13615315 WD: Q110419397 26.48, 80.25 x 26.51, 80.32
    { 251, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x88dbdf} }, // 20 OSM: 13620411 WD: Q27940747 22.65, 113.8 x 22.72, 113.8
    { 63, 36948, 4547, LineMetaDataContent::Subway, Color{0xed796a} }, // 11 OSM: 13623628 WD: Q6553057 39.91, 116.1 x 39.93, 116.2
    { 239, 36969, 4547, LineMetaDataContent::Subway, Color{0x00a9a9} }, // 17 OSM: 13625147 WD: Q24834015 39.79, 116.4 x 40.13, 116.6
    { 161, 36990, 4547, LineMetaDataContent::Subway, Color{0xd6aac1} }, // 19 OSM: 13625329 WD: Q6553202 39.81, 116.3 x 39.98, 116.4
    { 6, 37011, NoLogo, LineMetaDataContent::Subway, Color{0x1d2088} }, // 5 OSM: 13626146 WD: Q10946024 29.81, 121.5 x 29.92, 121.6
    { 67, 37032, NoLogo, LineMetaDataContent::Subway, Color{0xffe400} }, // 13 OSM: 13633615 WD: Q10938159 39.15, 121.7 x 39.43, 121.9
    { 5785, 37053, NoLogo, LineMetaDataContent::LocalTrain, Color{} }, // RE 3 OSM: 13646696 WD: Q93290679 48.14, 11.48 x 48.78, 13.45
    { 6, 37069, NoLogo, LineMetaDataContent::Subway, Color{0xa43034} }, // 5 OSM: 13647962 WD: Q11124520 30.43, 114.3 x 30.65, 114.4
    { 26, 37089, NoLogo, LineMetaDataContent::Subway, Color{0xc24c6d} }, // 16 OSM: 13648363 WD: Q11124505 30.27, 114 x 30.51, 114.2
    { 761, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xee0000} }, // E7 OSM: 13649968 48.1, 11.58 x 48.14, 11.61
    { 9, NoLogo, 29292, LineMetaDataContent::Subway, Color{0x1c7736} }, // 4 OSM: 13652091 WD: Q10940016 39.1, 117.2 x 39.14, 117.4
    { 110, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xee0000} }, // 37 OSM: 13664761 48.14, 11.6 x 48.18, 11.64
    { 9, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x00a560} }, // 4 OSM: 13681035 WD: Q15907959 28.6, 115.7 x 28.72, 116
    { 1634, 37110, 2564, LineMetaDataContent::RapidTransit, Color{0xe6007e} }, // S31 OSM: 13708521 WD: Q116125183 47.1, 15.62 x 47.22, 15.71
    { 19, NoLogo, 29292, LineMetaDataContent::Subway, Color{0x602e7c} }, // 8 OSM: 13711701 WD: Q10940012 38.98, 117.3 x 39.04, 117.4
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xca9822} }, // 6 OSM: 13743101 WD: Q121316067 50.89, 10.56 x 50.9, 10.58
    { 712, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe10d19} }, // A OSM: 13746337 WD: Q2204240 48.52, 7.694 x 48.6, 7.754
    { 279, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009ee0} }, // B OSM: 13746399 WD: Q2799227 48.55, 7.689 x 48.63, 7.769
    { 1319, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xb4532f} }, // S20 OSM: 13763963 47.33, 9.359 x 47.43, 9.462
    { 4064, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xc6912f} }, // S23 OSM: 13763964 47.29, 9.252 x 47.41, 9.437
    { 3585, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0xb55b59} }, // S26 OSM: 13763966 WD: Q819377 47.45, 9.59 x 47.47, 9.601
    { 329, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x66a4d9} }, // S25 OSM: 13763967 WD: Q337800 47.45, 9.493 x 47.48, 9.541
    { 153, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf38230} }, // 14 OSM: 13773639 WD: Q108223064 45.44, 9.117 x 45.5, 9.188
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf38230} }, // 2 OSM: 13792262 WD: Q108223056 45.44, 9.139 x 45.5, 9.188
    { 157, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf38230} }, // 15 OSM: 13795534 WD: Q108223065 45.38, 9.149 x 45.46, 9.19
    { 5790, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe31837} }, // Ferny Grove OSM: 13878514 WD: Q5445172 -27.47, 152.9 x -27.4, 153
    { 5802, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa54399} }, // Doomben OSM: 13885130 WD: Q5297079 -27.47, 153 x -27.42, 153.1
    { 3295, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfe5000} }, // SEAFRD OSM: 13890308 WD: Q7045547 -35.19, 138.5 x -34.92, 138.6
    { 153, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x81c180} }, // 14 OSM: 13890546 WD: Q122382729 49.79, 18.26 x 49.86, 18.32
    { 5810, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x007dc3} }, // OUTHA OSM: 13901930 WD: Q7111976 -34.92, 138.5 x -34.78, 138.6
    { 5816, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x007dc3} }, // GRNG OSM: 13901931 WD: Q5595697 -34.92, 138.5 x -34.88, 138.6
    { 5821, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xc23b33} }, // GAWC OSM: 13903112 WD: Q5528455 -34.92, 138.6 x -34.59, 138.7
    { 5826, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfe5000} }, // FLNDRS OSM: 13905568 WD: Q7821676 -35.02, 138.6 x -34.92, 138.6
    { 5833, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x357aac} }, // Aqua OSM: 13916711 WD: Q59155699 18.51, 73.8 x 18.56, 73.91
    { 1594, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x800080} }, // Purple OSM: 13917129 WD: Q59155676 18.5, 73.8 x 18.63, 73.86
    { 5838, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x1578be} }, // Redcliffe Peninsula OSM: 13945821 WD: Q7419371 -27.47, 153 x -27.22, 153.1
    { 289, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xcc5923} }, // T1 OSM: 13962101 WD: Q30947487 30.4, 114.1 x 30.5, 114.2
    { 68, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf38230} }, // 3 OSM: 13986519 WD: Q108223057 45.4, 9.174 x 45.46, 9.188
    { 68, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0000ff} }, // 3 OSM: 13986696 WD: Q54366530 17.39, 78.38 x 17.45, 78.56
    { 118, 37129, NoLogo, LineMetaDataContent::Subway, Color{0xcd5228} }, // 22 OSM: 13988001 WD: Q32177258 22.94, 113.3 x 23.02, 113.4
    { 16, 37150, NoLogo, LineMetaDataContent::Subway, Color{0xffff00} }, // 2 OSM: 13989917 WD: Q28419528 19.13, 72.83 x 19.26, 72.87
    { 47, 37174, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // 7 OSM: 13989918 WD: Q28419537 19.11, 72.85 x 19.25, 72.87
    { 52, 37196, 2564, LineMetaDataContent::RapidTransit, Color{0xec008c} }, // S5 OSM: 13995159 WD: Q67882950 48.27, 14.02 x 48.3, 14.29
    { 225, 37207, 2564, LineMetaDataContent::RapidTransit, Color{0x3f318f} }, // S3 OSM: 13995160 WD: Q67882855 48.26, 14.29 x 48.36, 14.52
    { 59, 37218, 2564, LineMetaDataContent::RapidTransit, Color{0x00aaad} }, // S2 OSM: 13995161 WD: Q67882763 48.16, 14.02 x 48.29, 14.29
    { 71, 37229, 2564, LineMetaDataContent::RapidTransit, Color{0xf58220} }, // S1 OSM: 13995162 WD: Q67882646 48.02, 14.29 x 48.3, 14.52
    { 314, 37240, 2564, LineMetaDataContent::RapidTransit, Color{0x96bc33} }, // S4 OSM: 13995163 WD: Q67882906 47.91, 14.1 x 48.29, 14.29
    { 235, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffff00} }, // 27 OSM: 14001354 WD: Q121545133 42.66, 23.28 x 42.73, 23.32
    { 146, 37251, NoLogo, LineMetaDataContent::Subway, Color{0x862041} }, // 9 OSM: 14004564 WD: Q15917000 29.54, 106.4 x 29.76, 106.6
    { 5858, 15770, 10793, LineMetaDataContent::RapidTransit, Color{0x159dd9} }, // R40 OSM: 14008626 WD: Q96483953 48.23, 16.21 x 48.35, 16.37
    { 75, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf38230} }, // 10 OSM: 14011006 WD: Q108223062 45.45, 9.163 x 45.49, 9.206
    { 5862, 37276, NoLogo, LineMetaDataContent::LongDistanceTrain, Color{0x1eb2b3} }, // IR 66 OSM: 14049006 WD: Q116053240 46.93, 6.811 x 47.1, 7.439
    { 1760, 37291, 10457, LineMetaDataContent::Tramway, Color{0x873f98} }, // T7 OSM: 14071538 WD: Q98842997 45.76, 4.923 x 45.78, 4.981
    { 9, 37311, 9495, LineMetaDataContent::Subway, Color{0x9933ff} }, // 4 OSM: 14074756 WD: Q55663681 41.21, 69.22 x 41.3, 69.37
    { 6, 37337, NoLogo, LineMetaDataContent::Subway, Color{0x893b67} }, // 5 OSM: 14085418 WD: Q25305553 25.98, 119.2 x 26.11, 119.4
    { 3237, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00a49f} }, // B1 OSM: 14125993 WD: Q7521893 39.91, 32.58 x 39.97, 32.97
    { 5868, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00467f} }, // Shorncliffe OSM: 14136709 WD: Q7501515 -27.47, 153 x -27.32, 153.1
    { 5880, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x094b8d} }, // LIL OSM: 14142941 WD: Q6548623 -37.83, 144.9 x -37.76, 145.3
    { 75, 37356, NoLogo, LineMetaDataContent::Subway, Color{0xb3cb6d} }, // 10 OSM: 14166437 WD: Q18638829 39.45, -0.378 x 39.46, -0.3348
    { 1353, NoLogo, 3616, LineMetaDataContent::Tramway, Color{0x172983} }, // L5 OSM: 14193223 WD: Q9025966 38.34, -0.479 x 38.38, -0.4118
    { 47, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffa500} }, // 7 OSM: 14194208 WD: Q108058493 51.74, 19.42 x 51.78, 19.55
    { 16, 37388, NoLogo, LineMetaDataContent::Tramway, Color{0x15882e} }, // 2 OSM: 14211347 WD: Q1854674 51.18, 4.373 x 51.26, 4.464
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xb31c21} }, // 2 OSM: 14215022 WD: Q97325177 37.71, 112.6 x 37.92, 112.6
    { 5884, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x56ae35} }, // MTR OSM: 14217249 WD: Q17628181 -34.17, -70.75 x -33.45, -70.68
    { 5888, 37410, NoLogo, LineMetaDataContent::LocalTrain, Color{} }, // RB 73 OSM: 14228504 WD: Q113458371 47.57, 10.32 x 47.71, 10.58
    { 2628, 37427, 6136, LineMetaDataContent::Tramway, Color{0x827a04} }, // T10 OSM: 14232362 WD: Q3537026 48.76, 2.248 x 48.79, 2.304
    { 1810, 37461, 3863, LineMetaDataContent::Tramway, Color{0x8a5f20} }, // T13 OSM: 14263358 WD: Q3515106 48.8, 2.043 x 48.97, 2.095
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x6899ff} }, // 8 OSM: 14300553 WD: Q124657538 55.86, 49 x 55.87, 49.11
    { 27, 37495, NoLogo, LineMetaDataContent::Subway, Color{0x005bac} }, // 6 OSM: 14303415 WD: Q46096730 28.17, 112.8 x 28.22, 113.2
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x1251b4} }, // 2 OSM: 14306359 WD: Q110315870 55.77, 49.09 x 55.79, 49.11
    { 47, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xb64dce} }, // 7 OSM: 14306360 WD: Q124657537 55.73, 49.07 x 55.83, 49.22
    { 6, 37525, NoLogo, LineMetaDataContent::Subway, Color{0x008000} }, // 5 OSM: 14317129 WD: Q24837356 24.93, 102.7 x 25.07, 102.8
    { 5894, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffcd28} }, // Z40 OSM: 14319938 WD: Q112225436 46.37, 18.15 x 47.5, 19.04
    { 6, 37545, 14077, LineMetaDataContent::Tramway, Color{0x95254c} }, // 5 OSM: 14329573 WD: Q16655754 43.59, 3.822 x 43.65, 3.876
    { 52, 37555, 226, LineMetaDataContent::RapidTransit, Color{0xf3c737} }, // S5 OSM: 14372453 WD: Q116211506 46.53, 13.83 x 46.62, 14.04
    { 367, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x3bbfef} }, // Blue OSM: 14381218 30.2, -97.75 x 30.42, -97.66
    { 153, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009bde} }, // 14 OSM: 14402834 51.33, 12.32 x 51.34, 12.38
    { 82, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 21 OSM: 14412282 WD: Q122439371 45.24, 27.94 x 45.3, 27.97
    { 255, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 24 OSM: 14412292 WD: Q122439376 45.19, 27.9 x 45.25, 27.95
    { 5898, 37576, NoLogo, LineMetaDataContent::LongDistanceTrain, Color{0xed1c24} }, // RE80 OSM: 14432436 WD: Q107263607 45.49, 8.801 x 46.18, 9.274
    { 5903, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x187dcd} }, // JT OSM: 14434654 WD: Q112169762 29.31, 106.3 x 29.41, 106.4
    { 5906, 37590, 3863, LineMetaDataContent::Tramway, Color{0xb90845} }, // T12 OSM: 14456255 WD: Q3536986 48.62, 2.256 x 48.73, 2.427
    { 2367, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xef8016} }, // R12 OSM: 14460896 59.31, 24.42 x 59.44, 24.74
    { 5910, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xc33032} }, // Jinyi OSM: 14489040 WD: Q117774718 29.08, 119.6 x 29.33, 120.1
    { 27, 37624, NoLogo, LineMetaDataContent::Subway, Color{0x005eb8} }, // 6 OSM: 14509136 WD: Q24886992 25.9, 119.4 x 26.02, 119.6
    { 63, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x45b09f} }, // 11 OSM: 14542032 WD: Q120720209 50.01, 19.89 x 50.04, 20
    { 146, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf38230} }, // 9 OSM: 14552272 WD: Q108223061 45.45, 9.17 x 45.49, 9.208
    { 2183, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x228b22} }, // V OSM: 14576928 WD: Q114313190 -17.47, -66.33 x -17.4, -66.15
    { 598, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // R OSM: 14576929 WD: Q114312991 -17.46, -66.15 x -17.4, -66.12
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffcc99} }, // 2 OSM: 14594829 WD: Q106963559 22.67, 114 x 22.72, 114.1
    { 64, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x93cb44} }, // 1 OSM: 14594831 WD: Q106963564 22.67, 114 x 22.69, 114.1
    { 5916, 37643, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffce00} }, // S90 OSM: 14604626 WD: Q108075807 45.87, 8.92 x 46.17, 9.005
    { 1319, 37656, NoLogo, LineMetaDataContent::RapidTransit, Color{0x007dc6} }, // S20 OSM: 14604783 WD: Q3832731 46.15, 8.801 x 46.22, 9.042
    { 1080, 19596, NoLogo, LineMetaDataContent::RapidTransit, Color{0xed1c24} }, // S10 OSM: 14604788 WD: Q3832722 45.81, 8.933 x 46.35, 9.074
    { 2116, 37669, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00a651} }, // S30 OSM: 14604990 WD: Q3832740 45.66, 8.624 x 46.16, 8.942
    { 181, 37682, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe35a13} }, // S60 OSM: 14605103 WD: Q112899163 45.97, 8.86 x 46.01, 8.948
    { 273, 37695, NoLogo, LineMetaDataContent::RapidTransit, Color{0x6cc27f} }, // S40 OSM: 14605384 WD: Q47219003 45.81, 8.833 x 45.87, 9.074
    { 242, 37708, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7d4808} }, // S50 OSM: 14605385 WD: Q47219058 45.6, 8.704 x 46.35, 9.042
    { 64, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x01a3e1} }, // 1 OSM: 14611374 WD: Q48868979 38.64, -9.167 x 38.69, -9.147
    { 68, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xbcd019} }, // 3 OSM: 14611403 WD: Q48868985 38.66, -9.208 x 38.69, -9.147
    { 16, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffcc01} }, // 2 OSM: 14611445 WD: Q48868981 38.64, -9.18 x 38.67, -9.151
    { 161, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x05c3de} }, // 19 OSM: 14613133 WD: Q48903466 30.22, 120 x 30.3, 120.5
    { 5920, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x777777} }, // U AZA-ATE OSM: 14615977 WD: Q576138 38.71, -9.174 x 39.07, -8.867
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 2 OSM: 14630830 WD: Q122387791 50.49, 13.64 x 50.51, 13.66
    { 64, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 1 OSM: 14630831 WD: Q122387790 50.49, 13.6 x 50.61, 13.65
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 4 OSM: 14630832 WD: Q122387793 50.49, 13.6 x 50.61, 13.65
    { 68, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 3 OSM: 14630833 WD: Q122387792 50.51, 13.6 x 50.61, 13.66
    { 27, 37721, NoLogo, LineMetaDataContent::Subway, Color{0x920783} }, // 6 OSM: 14642983 WD: Q15935783 34.67, 113.4 x 34.74, 113.5
    { 146, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 9 OSM: 14644778 47.2, 38.88 x 47.22, 38.94
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // 2 OSM: 14657624 WD: Q65081142 22.98, 72.53 x 23.2, 72.69
    { 586, 37740, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe96bb0} }, // K OSM: 14669757 WD: Q5184164 33.89, -118.4 x 34.02, -118.3
    { 4305, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0bd5fe} }, // Airport OSM: 14677578 WD: Q109448267 -31.98, 115.8 x -31.92, 116
    { 2218, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe3000b} }, // 4A OSM: 14712448 WD: Q121317832 49.48, 8.364 x 49.53, 8.509
    { 5930, 37765, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7a745a} }, // F4 OSM: 14738977 WD: Q31193345 41.08, 29.05 x 41.09, 29.05
    { 289, 37793, NoLogo, LineMetaDataContent::RapidTransit, Color{0x7bb932} }, // T1 OSM: 14758569 WD: Q5985905 36.41, -6.288 x 36.53, -6.134
    { 266, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x7b2c1c} }, // 42 OSM: 14759884 WD: Q123363432 50.08, 14.38 x 50.1, 14.43
    { 153, 37811, NoLogo, LineMetaDataContent::Subway, Color{0xf2c75c} }, // 14 OSM: 14764338 WD: Q21245993 22.54, 114.1 x 22.76, 114.4
    { 5933, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x9364cc} }, // XR OSM: 14773915 WD: Q130546459 51.46, -0.9747 x 51.63, 0.3296
    { 5936, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfdda24} }, // GR01 OSM: 14785799 WD: Q55074880 37.06, 37.33 x 37.17, 37.45
    { 64, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 14870574 WD: Q47015943 31.91, 120.8 x 32.11, 121
    { 18, 37835, 21781, LineMetaDataContent::Subway, Color{0x23387f} }, // M8 OSM: 14900218 WD: Q5996245 40.95, 29.09 x 41.03, 29.16
    { 75, NoLogo, 29292, LineMetaDataContent::Subway, Color{0xb9cf09} }, // 10 OSM: 14903908 WD: Q10940015 39.05, 117.2 x 39.15, 117.3
    { 5941, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xcccccc} }, // AGTS OSM: 14910918 WD: Q5259735 39.85, -104.7 x 39.86, -104.7
    { 16, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xbf4525} }, // 2 OSM: 14933919 WD: Q114608664 60.35, 5.289 x 60.39, 5.362
    { 64, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xed4800} }, // 1 OSM: 14934588 WD: Q28412165 27.48, 118 x 27.63, 118.1
    { 63, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce1417} }, // 11 OSM: 14937318 WD: Q123346615 51.53, 45.98 x 51.6, 46.03
    { 8, 37863, 8099, LineMetaDataContent::Subway, Color{0x2f4481} }, // M4 OSM: 14937470 WD: Q943476 45.44, 9.129 x 45.47, 9.278
    { 520, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x30556e} }, // L1 OSM: 14942883 WD: Q28759219 56.15, 10.2 x 56.41, 10.88
    { 15, 37883, NoLogo, LineMetaDataContent::Subway, Color{0xa192b2} }, // 12 OSM: 14944729 WD: Q11559867 22.47, 113.8 x 22.73, 113.9
    { 5946, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x428d89} }, // 6B OSM: 14953717 WD: Q114025973 22.77, 113.9 x 22.81, 114
    { 524, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x30556e} }, // L2 OSM: 14973319 WD: Q28759221 55.97, 10.12 x 56.23, 10.23
    { 251, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xa0216e} }, // 20 OSM: 14987053 47.39, 8.353 x 47.43, 8.489
    { 1884, NoLogo, 9742, LineMetaDataContent::RapidTransit, Color{0xed6fa7} }, // S19 OSM: 14987372 WD: Q110973246 50.4, 4.335 x 50.9, 4.488
    { 5949, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00aff0} }, // S74 OSM: 14995079 WD: Q115171353 47.72, 18.11 x 47.78, 18.74
    { 5953, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffff00} }, // S 10 OSM: 14995860 51.32, 12.27 x 51.37, 12.39
    { 68, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xca0000} }, // 3 OSM: 14999192 WD: Q121662729 54.69, 20.47 x 54.72, 20.53
    { 5958, 37907, NoLogo, LineMetaDataContent::LocalTrain, Color{0x816da6} }, // RE8 OSM: 15001253 WD: Q112992594 51.46, 11.36 x 53.9, 13.71
    { 2013, 37926, 9742, LineMetaDataContent::LocalTrain, Color{0x202776} }, // S53 OSM: 15013894 WD: Q115285815 50.85, 3.601 x 51.11, 3.986
    { 645, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xcd2c0e} }, // S9 OSM: 15018427 WD: Q125989610 49.74, 18.2 x 49.82, 18.62
    { 289, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xfdec4a} }, // T1 OSM: 15022247 WD: Q950794 45.69, 9.676 x 45.76, 9.798
    { 692, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xbe1622} }, // 55 OSM: 15036277 WD: Q121368518 44.43, 26.11 x 44.44, 26.18
    { 41, 37947, 226, LineMetaDataContent::RapidTransit, Color{0x000000} }, // REX7/S7 OSM: 15037199 WD: Q108602207 47.45, 9.637 x 47.55, 9.754
    { 3198, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xee4b95} }, // TL10 OSM: 15045727 WD: Q125903428 51.37, -0.4163 x 51.88, 0.612
    { 339, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x81cae8} }, // S33 OSM: 15046198 WD: Q125989622 49.63, 17.61 x 49.8, 17.94
    { 1058, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x81cae8} }, // S32 OSM: 15046201 WD: Q125989621 49.64, 17.91 x 49.71, 17.96
    { 1634, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x81cae8} }, // S31 OSM: 15046203 WD: Q125989620 49.71, 18.01 x 49.75, 18.07
    { 49, NoLogo, 14578, LineMetaDataContent::RapidTransit, Color{0x000000} }, // R5/S5 OSM: 15050094 WD: Q130340074 47.24, 9.603 x 47.48, 9.755
    { 9, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x007a33} }, // 4 OSM: 15051229 WD: Q15947246 36.06, 120.3 x 36.14, 120.6
    { 2141, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x81cae8} }, // S34 OSM: 15052369 WD: Q125989623 49.6, 17.94 x 49.64, 18.01
    { 59, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa05a43} }, // S2 OSM: 15052628 WD: Q125989602 49.51, 18.21 x 49.91, 18.76
    { 225, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x3b91ca} }, // S3 OSM: 15052633 WD: Q125989603 49.57, 17.74 x 49.9, 18.36
    { 55, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xdd801e} }, // S8 OSM: 15052634 WD: Q125989609 49.54, 18.04 x 49.85, 18.28
    { 3912, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x002f87} }, // F3 OSM: 15054273 WD: Q10886733 22.82, 113 x 23.15, 113.3
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xc80404} }, // 4 OSM: 15057097 WD: Q118322264 55.87, 26.51 x 55.89, 26.55
    { 71, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0061ae} }, // S1 OSM: 15058106 WD: Q48899113 28.32, 121.3 x 28.66, 121.4
    { 298, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x9040ba} }, // S6 OSM: 15058252 WD: Q125989607 49.47, 17.96 x 49.85, 18.37
    { 5962, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // IR85 OSM: 15058598 47.49, 19.08 x 47.78, 19.95
    { 26, 37971, NoLogo, LineMetaDataContent::Subway, Color{0x1e22aa} }, // 16 OSM: 15059918 WD: Q11215578 22.69, 114.2 x 22.73, 114.4
    { 27, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x006e34} }, // 6 OSM: 15060937 WD: Q97257710 23.73, 90.36 x 23.87, 90.42
    { 5967, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x83898f} }, // 58d OSM: 15062383 -37.84, 145 x -37.81, 145
    { 68, 28090, 28113, LineMetaDataContent::Subway, Color{0x800080} }, // 3 OSM: 15068969 WD: Q27502952 22.45, 88.3 x 22.52, 88.32
    { 5971, 37995, 21781, LineMetaDataContent::Subway, Color{0xa1609b} }, // M11 OSM: 15083966 WD: Q31193348 41.07, 28.7 x 41.26, 29.01
    { 5975, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x754030} }, // D7 OSM: 15087038 51.03, 17.03 x 51.1, 17.35
    { 5978, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffdd00} }, // D83 OSM: 15087040 51.1, 17 x 51.7, 17.43
    { 5982, 38024, 21781, LineMetaDataContent::Subway, Color{0xb16400} }, // M14 OSM: 15099622 WD: Q31193350 41.02, 29.05 x 41.08, 29.1
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xb141fc} }, // 2 OSM: 15203534 WD: Q123341836 53.73, 20.48 x 53.78, 20.5
    { 2407, 38053, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // Sul OSM: 15268630 WD: Q10374983 -6.071, -35.26 x -5.78, -35.21
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe77817} }, // 5 OSM: 15268961 WD: Q121410308 47.14, 27.54 x 47.17, 27.64
    { 3204, NoLogo, 3616, LineMetaDataContent::Tramway, Color{0x706e6d} }, // L9 OSM: 15320668 WD: Q11690013 38.55, -0.1354 x 38.84, 0.1131
    { 5986, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff6500} }, // D4 OSM: 15321385 50.69, 16.48 x 51.1, 17.07
    { 47, 38067, 12736, LineMetaDataContent::Subway, Color{0x4a7729} }, // 7 OSM: 15336346 WD: Q10906687 32.11, 118.8 x 32.13, 118.9
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 2 OSM: 15351429 WD: Q123362825 41.22, 36.34 x 41.29, 36.46
    { 64, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 1 OSM: 15351430 WD: Q112134173 41.29, 36.23 x 41.37, 36.34
    { 68, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffa500} }, // 3 OSM: 15360948 WD: Q123362853 41.37, 36.19 x 41.38, 36.23
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf38230} }, // 5 OSM: 15402181 WD: Q108223059 45.47, 9.19 x 45.51, 9.238
    { 728, NoLogo, 34172, LineMetaDataContent::RapidTransit, Color{0xefd51f} }, // RE3 OSM: 15413862 WD: Q115749580 46.6, 6.906 x 46.85, 7.191
    { 1489, NoLogo, 34172, LineMetaDataContent::RapidTransit, Color{0xc31622} }, // RE2 OSM: 15413942 WD: Q115749575 46.6, 6.906 x 46.95, 7.44
    { 586, 38087, NoLogo, LineMetaDataContent::RapidTransit, Color{0xc3b091} }, // K OSM: 15443527 WD: Q10914168 24.94, 121.5 x 24.99, 121.5
    { 5989, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x2e2076} }, // 240 OSM: 15446398 50.74, 15.52 x 51.1, 17.04
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf38230} }, // 12 OSM: 15460064 WD: Q108223063 45.46, 9.119 x 45.52, 9.224
    { 1329, 38115, NoLogo, LineMetaDataContent::Tramway, Color{0x0d0dff} }, // T3 OSM: 15463465 WD: Q123413686 37.03, 37.31 x 37.09, 37.35
    { 5157, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x3a6198} }, // S22 OSM: 15463831 WD: Q115743565 47.29, 7.688 x 47.31, 7.71
    { 289, 38144, NoLogo, LineMetaDataContent::Tramway, Color{0xff2b0a} }, // T1 OSM: 15470243 WD: Q123413668 37.02, 37.32 x 37.07, 37.38
    { 725, 38173, NoLogo, LineMetaDataContent::Tramway, Color{0x08ff08} }, // T2 OSM: 15471518 WD: Q123413681 37.06, 37.33 x 37.09, 37.38
    { 16, 38202, NoLogo, LineMetaDataContent::Subway, Color{0x229954} }, // 2 OSM: 15510494 WD: Q97218492 29.57, 52.5 x 29.62, 52.53
    { 5993, 38226, 21781, LineMetaDataContent::Subway, Color{0xc8cb2d} }, // M12 OSM: 15520693 WD: Q31193310 40.97, 29.06 x 41.04, 29.12
    { 26, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf38230} }, // 16 OSM: 15532977 WD: Q108223067 45.45, 9.121 x 45.48, 9.229
    { 161, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf38230} }, // 19 OSM: 15535050 WD: Q108223068 45.46, 9.151 x 45.5, 9.238
    { 64, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffb752} }, // 1 OSM: 15540826 WD: Q116860182 35.92, 0.06022 x 35.98, 0.1102
    { 255, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf38230} }, // 24 OSM: 15545551 WD: Q108223069 45.42, 9.188 x 45.46, 9.204
    { 16, 38255, 38280, LineMetaDataContent::Subway, Color{0x58e558} }, // 2 OSM: 15545706 WD: Q116978502 35.7, 50.88 x 35.86, 51.01
    { 66, 38330, 21781, LineMetaDataContent::Subway, Color{0x0ca950} }, // M13 OSM: 15547419 WD: Q48742876 40.98, 29.04 x 41.03, 29.25
    { 1521, 38359, 21781, LineMetaDataContent::Subway, Color{0xf19ebf} }, // M7 OSM: 15547431 WD: Q16949749 41.03, 28.67 x 41.09, 29.01
    { 5997, 38387, 21781, LineMetaDataContent::Subway, Color{0xffd400} }, // M9 OSM: 15547473 WD: Q25209252 40.98, 28.77 x 41.08, 28.86
    { 6000, 38415, 21781, LineMetaDataContent::Subway, Color{} }, // M20 OSM: 15547627 WD: Q109779737 40.97, 28.62 x 41.03, 28.88
    { 400, NoLogo, 6890, LineMetaDataContent::Tramway, Color{0xce1417} }, // 30 OSM: 15554589 WD: Q123168050 59.92, 30.38 x 59.93, 30.44
    { 235, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf38230} }, // 27 OSM: 15555911 WD: Q108223070 45.45, 9.194 x 45.46, 9.255
    { 2650, 38444, 34801, LineMetaDataContent::Tramway, Color{0x73c0d5} }, // T3a OSM: 15568057 WD: Q117008328 38.72, 35.4 x 38.79, 35.63
    { 1329, 38444, 34801, LineMetaDataContent::Tramway, Color{0x73c0d5} }, // T3 OSM: 15568179 WD: Q117008328 38.72, 35.4 x 38.79, 35.63
    { 6004, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf38230} }, // 31/ OSM: 15571764 WD: Q108223071 45.49, 9.191 x 45.56, 9.218
    { 340, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf38230} }, // 33 OSM: 15572354 WD: Q108223072 45.47, 9.182 x 45.49, 9.242
    { 6008, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf5b85a} }, // 6b OSM: 15589420 WD: Q122781782 45.74, 21.22 x 45.76, 21.25
    { 273, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x70ad46} }, // S40 OSM: 15592519 52.07, 20.95 x 52.2, 21.02
    { 314, NoLogo, 9964, LineMetaDataContent::RapidTransit, Color{0x2f7b20} }, // S4 OSM: 15592520 WD: Q124516393 52.07, 20.94 x 52.45, 21.03
    { 6011, 38485, NoLogo, LineMetaDataContent::LocalTrain, Color{0x697c8a} }, // RB32 OSM: 15608623 WD: Q112802971 52.3, 13.27 x 52.37, 13.51
    { 6016, 38505, NoLogo, LineMetaDataContent::LocalTrain, Color{} }, // RB 50 OSM: 15608624 WD: Q62594268 50.03, 9.683 x 50.19, 10.25
    { 6, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xe60012} }, // 5 OSM: 15611913 WD: Q28411250 38.88, 121.6 x 39.05, 121.7
    { 6022, 38522, NoLogo, LineMetaDataContent::LocalTrain, Color{0x501689} }, // RB21 OSM: 15615526 WD: Q105947745 52.39, 12.94 x 52.55, 13.39
    { 6027, 38542, NoLogo, LineMetaDataContent::LocalTrain, Color{0xad5937} }, // RB37 OSM: 15615531 WD: Q112803049 52.24, 12.96 x 52.42, 13.19
    { 349, NoLogo, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 23 OSM: 15624869 WD: Q100741440 47.47, 19.05 x 47.51, 19.09
    { 6032, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008752} }, // Caboolture OSM: 15625847 WD: Q5015753 -27.47, 153 x -27.08, 153.1
    { 6043, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008752} }, // Sunshine Coast OSM: 15631421 WD: Q16927337 -27.47, 152.7 x -26.16, 153.1
    { 712, 38562, 38582, LineMetaDataContent::Subway, Color{0x00a562} }, // A OSM: 15640862 WD: Q1292805 50.07, 14.34 x 50.1, 14.52
    { 279, 38620, 38582, LineMetaDataContent::Subway, Color{0xf8b322} }, // B OSM: 15640873 WD: Q1460442 50.04, 14.29 x 50.11, 14.58
    { 411, 38640, 38582, LineMetaDataContent::Subway, Color{0xcf003d} }, // C OSM: 15640889 WD: Q168571 50.03, 14.43 x 50.13, 14.53
    { 548, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00ad4f} }, // E OSM: 15654116 WD: Q118612325 36.78, 10.1 x 36.79, 10.18
    { 1265, 38660, 38682, LineMetaDataContent::Subway, Color{0x35ab52} }, // M3 OSM: 15655643 WD: Q2420584 50.39, 30.43 x 50.48, 30.7
    { 360, 38702, 38682, LineMetaDataContent::Subway, Color{0xdd2a26} }, // M1 OSM: 15655644 WD: Q2334153 50.44, 30.35 x 50.47, 30.65
    { 441, 38724, 38682, LineMetaDataContent::Subway, Color{0x2782c5} }, // M2 OSM: 15655645 WD: Q2204296 50.37, 30.45 x 50.52, 30.53
    { 6058, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffc425} }, // Gold Coast OSM: 15667052 WD: Q5578678 -28.1, 153 x -27.46, 153.4
    { 367, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0000ff} }, // Blue OSM: 15668739 WD: Q116413296 6.446, 3.312 x 6.479, 3.395
    { 161, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffa500} }, // 19 OSM: 15670312 WD: Q122339250 51.72, 19.43 x 51.83, 19.49
    { 47, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf38230} }, // 7 OSM: 15677604 WD: Q108223060 45.49, 9.191 x 45.52, 9.234
    { 22, 38746, NoLogo, LineMetaDataContent::Subway, Color{0x2cd5c4} }, // 18 OSM: 15749314 WD: Q17038985 29.4, 106.4 x 29.55, 106.5
    { 64, NoLogo, 38771, LineMetaDataContent::Subway, Color{0xe31d1b} }, // 1 OSM: 15797036 WD: Q18419905 -0.2955, -78.56 x -0.1546, -78.48
    { 283, 38782, 10537, LineMetaDataContent::Tramway, Color{0x91619d} }, // D OSM: 15797847 WD: Q16655779 44.82, -0.6675 x 44.89, -0.55
    { 314, 38816, 12736, LineMetaDataContent::Subway, Color{0xff631b} }, // S4 OSM: 15804062 WD: Q15939013 32.2, 118.3 x 32.31, 118.6
    { 6069, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00aff0} }, // S225 OSM: 15809425 46.91, 19.7 x 47.18, 20.18
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 6 OSM: 15840812 WD: Q122585347 55.81, 37.41 x 55.86, 37.51
    { 146, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 9 OSM: 15840817 WD: Q122585350 55.78, 37.58 x 55.79, 37.61
    { 251, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x595fa7} }, // 20 OSM: 15858526 52.38, 16.91 x 52.41, 16.98
    { 161, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0c7cac} }, // 19 OSM: 15865362 WD: Q123224131 51.11, 16.96 x 51.14, 17.08
    { 59, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0xffc0cb} }, // S2 OSM: 15865690 WD: Q115756448 46.7, 9.386 x 46.85, 9.531
    { 71, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x62a0ea} }, // S1 OSM: 15865708 WD: Q115756382 46.8, 9.386 x 46.98, 9.689
    { 22, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xee1d23} }, // 18 OSM: 15867094 WD: Q107024375 41.15, -8.668 x 41.15, -8.615
    { 6074, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe7a4d0} }, // M206 OSM: 15874032 50.58, 16.12 x 51.1, 17.04
    { 6079, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xc65312} }, // D3 OSM: 15898497 51.1, 16.84 x 51.61, 17.04
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // 2 OSM: 15924888 WD: Q65050458 36.03, 103.8 x 36.07, 103.9
    { 186, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x035eb9} }, // O OSM: 15925639 WD: Q118924451 60.46, 25.66 x 60.98, 26.96
    { 1117, NoLogo, 170, LineMetaDataContent::Tramway, Color{0xffd800} }, // 1A OSM: 15953835 WD: Q15982260 47.48, 19.03 x 47.55, 19.11
    { 1117, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfdc434} }, // 1A OSM: 15961882 WD: Q56388740 46.24, 20.12 x 46.27, 20.15
    { 6082, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xb70a06} }, // D9 OSM: 15984417 50.1, 16.63 x 51.1, 17.07
    { 6085, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff8500} }, // 223 OSM: 15984570 50.69, 16.33 x 51.1, 17.07
    { 6089, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xbde705} }, // 245 OSM: 15984766 50.4, 16.24 x 50.79, 16.66
    { 26, NoLogo, 3346, LineMetaDataContent::Tramway, Color{0xce1417} }, // 16 OSM: 15997372 WD: Q123339547 50.46, 30.46 x 50.52, 30.52
    { 6093, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xce0000} }, // PR OSM: 16019086 53.24, 19.57 x 53.58, 20.17
    { 6093, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xce0000} }, // PR OSM: 16019103 51.22, 22.57 x 51.25, 22.72
    { 807, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x238132} }, // RL OSM: 16020122 52.17, 20.69 x 52.44, 21.07
    { 6096, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x20409a} }, // CB OSM: 16035222 WD: Q56390365 -6.377, 106.8 x -6.204, 106.9
    { 6099, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x89728e} }, // SCLR OSM: 16056777 33.38, -112.1 x 33.46, -112.1
    { 1745, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x89728e} }, // DPH OSM: 16056811 33.45, -112.1 x 33.45, -112.1
    { 157, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x009b3e} }, // 15 OSM: 16065725 WD: Q120441391 40.85, 14.27 x 41.14, 14.77
    { 26, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x11472c} }, // 16 OSM: 16071949 WD: Q120437141 40.85, 14.24 x 41.35, 14.42
    { 47, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xeb262b} }, // 7 OSM: 16072815 WD: Q1388214 40.83, 14.27 x 40.88, 14.34
    { 67, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x751056} }, // 13 OSM: 16074085 WD: Q120496331 40.63, 14.27 x 40.85, 14.49
    { 153, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x8480d7} }, // 14 OSM: 16074777 WD: Q3743529 40.75, 14.27 x 40.85, 14.54
    { 15, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xf799b5} }, // 12 OSM: 16074833 WD: Q3743527 40.8, 14.27 x 40.88, 14.62
    { 6104, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0e6938} }, // BK OSM: 16079480 WD: Q56390372 -6.265, 106.8 x -6.204, 107
    { 64, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf38230} }, // 1 OSM: 16086391 WD: Q108223055 45.47, 9.119 x 45.52, 9.217
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf38230} }, // 4 OSM: 16086511 WD: Q108223058 45.47, 9.179 x 45.53, 9.192
    { 68, 38846, NoLogo, LineMetaDataContent::Subway, Color{0xabcd03} }, // 3 OSM: 16103884 WD: Q120358322 27.97, 112.9 x 28.25, 113.1
    { 26, 38875, NoLogo, LineMetaDataContent::Subway, Color{0xea8464} }, // 16 OSM: 16104056 WD: Q116783831 34.23, 108.7 x 34.34, 108.8
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x307fe2} }, // 2 OSM: 16136208 WD: Q85883422 30.05, 120.6 x 30.05, 120.7
    { 2198, 38896, 38896, LineMetaDataContent::RapidTransit, Color{0x6bc700} }, // A1 OSM: 16141765 WD: Q19582331 45.44, -73.57 x 45.5, -73.43
    { 239, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x96a7b1} }, // 17 OSM: 16147231 WD: Q123363027 56.76, 60.55 x 56.86, 60.61
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 5 OSM: 16156014 WD: Q121140495 44.03, 42.98 x 44.05, 43.12
    { 47, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 7 OSM: 16156025 WD: Q121140521 44.04, 43.03 x 44.05, 43.06
    { 6107, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x59ff00} }, // D13 OSM: 16172604 51.21, 15.88 x 51.42, 16.17
    { 9, 38936, NoLogo, LineMetaDataContent::RapidTransit, Color{0x76b82b} }, // 4 OSM: 16176187 WD: Q20814403 45.32, -75.67 x 45.35, -75.65
    { 157, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf7ab64} }, // 15 OSM: 16179482 WD: Q121317829 49.48, 8.463 x 49.51, 8.554
    { 777, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00abe5} }, // GN4 OSM: 16179487 51.52, -0.2073 x 51.9, -0.08581
    { 16, 38936, NoLogo, LineMetaDataContent::RapidTransit, Color{0x76b82b} }, // 2 OSM: 16190572 WD: Q20814403 45.28, -75.72 x 45.41, -75.63
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xa92683} }, // 4 OSM: 16206854 55.69, 52.41 x 55.77, 52.53
    { 75, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 10 OSM: 16206855 55.67, 52.28 x 55.77, 52.45
    { 146, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x72a891} }, // 9 OSM: 16206856 55.67, 52.28 x 55.77, 52.45
    { 6079, 38955, 33114, LineMetaDataContent::RapidTransit, Color{0xe15d29} }, // D3 OSM: 16213702 WD: Q65127804 55.56, 37.17 x 55.98, 38.24
    { 64, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffeedd} }, // 1 OSM: 16221996 WD: Q121691512 54.14, 19.39 x 54.19, 19.44
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xaa8800} }, // 2 OSM: 16222005 WD: Q121691513 54.14, 19.4 x 54.18, 19.44
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x225500} }, // 4 OSM: 16222014 WD: Q121691517 54.14, 19.4 x 54.19, 19.44
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x006680} }, // 5 OSM: 16222015 WD: Q121691519 54.16, 19.4 x 54.19, 19.43
    { 598, NoLogo, 38980, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // R OSM: 16226515 WD: Q7304510 32, 34.74 x 32.11, 34.89
    { 22, 38996, 8524, LineMetaDataContent::Tramway, Color{0x91bee7} }, // 18 OSM: 16241563 WD: Q12013459 50.78, 4.326 x 50.82, 4.341
    { 59, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xe4222b} }, // S2 OSM: 16244469 WD: Q17030015 27.76, 120.7 x 28.13, 121
    { 6111, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xd2a1f3} }, // T46 OSM: 16253188 WD: Q115220048 50.23, 18.99 x 50.27, 19.07
    { 9, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff7f00} }, // 4 OSM: 16253271 WD: Q25346431 25.99, 119.3 x 26.1, 119.4
    { 6115, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00467f} }, // Cleveland OSM: 16264432 WD: Q5132306 -27.52, 153 x -27.44, 153.3
    { 6125, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe31837} }, // Beenleigh OSM: 16264773 WD: Q4879912 -27.72, 153 x -27.46, 153.2
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffa500} }, // 6 OSM: 16265222 WD: Q121833005 53.01, 18.59 x 53.06, 18.7
    { 68, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008000} }, // 3 OSM: 16265225 WD: Q55676152 53.01, 18.55 x 53.06, 18.6
    { 47, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffa500} }, // 7 OSM: 16265486 WD: Q123338681 53.01, 18.56 x 53.03, 18.65
    { 6135, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x1f9cd8} }, // NC (SB) OSM: 16270337 WD: Q125156771 53.34, -6.429 x 54, -6.112
    { 64, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xcc302a} }, // 1 OSM: 16274456 WD: Q112841862 40.72, 8.545 x 40.74, 8.562
    { 157, NoLogo, 5256, LineMetaDataContent::Tramway, Color{0x097969} }, // 15 OSM: 16274967 WD: Q122202409 45.06, 7.621 x 45.08, 7.733
    { 5986, 39018, 33114, LineMetaDataContent::RapidTransit, Color{0x3fb485} }, // D4 OSM: 16275214 WD: Q63928373 55.55, 37.07 x 55.8, 38.01
    { 447, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0079bf} }, // 80 OSM: 16298478 WD: Q125869342 45.8, 15.69 x 45.89, 16.24
    { 67, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0c7cac} }, // 13 OSM: 16299592 WD: Q122307231 51.11, 16.95 x 51.12, 17.09
    { 161, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xa29786} }, // 19 OSM: 16309523 WD: Q114425800 50.05, 14.43 x 50.08, 14.52
    { 75, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x434242} }, // 10 OSM: 16310472 WD: Q122382725 49.77, 18.25 x 49.83, 18.32
    { 349, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 23 OSM: 16317056 WD: Q122439374 45.24, 27.94 x 45.3, 27.96
    { 118, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 22 OSM: 16317267 WD: Q122439373 45.24, 27.94 x 45.3, 27.97
    { 330, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 25 OSM: 16318123 WD: Q122439377 45.21, 27.92 x 45.25, 27.95
    { 6143, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 1N OSM: 16337680 WD: Q122617990 47.05, 21.91 x 47.08, 21.94
    { 6146, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 1S OSM: 16337692 WD: Q122617993 47.07, 21.88 x 47.08, 21.91
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x1934d5} }, // 2 OSM: 16337738 WD: Q122617994 47.04, 21.9 x 47.06, 21.94
    { 68, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 3 OSM: 16337800 WD: Q122617995 47.03, 21.92 x 47.07, 21.96
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 4 OSM: 16337932 WD: Q122617996 47.03, 21.91 x 47.08, 21.96
    { 157, NoLogo, 35568, LineMetaDataContent::RapidTransit, Color{0x007e79} }, // 15 OSM: 16363614 WD: Q31085928 60.18, 24.81 x 60.23, 25.08
    { 55, 39043, 226, LineMetaDataContent::RapidTransit, Color{0xa46fa9} }, // S8 OSM: 16380270 WD: Q122818946 49.47, 8.444 x 49.69, 8.511
    { 46, 39062, 226, LineMetaDataContent::RapidTransit, Color{0xee499c} }, // S7 OSM: 16384835 WD: Q122818933 49.32, 8.537 x 49.45, 8.676
    { 6149, 39081, 226, LineMetaDataContent::RapidTransit, Color{0xfb3199} }, // S39 OSM: 16388764 WD: Q122818916 49.48, 8.454 x 49.53, 8.482
    { 9, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x4b0082} }, // 4 OSM: 16393681 WD: Q21245990 41.65, 123.4 x 41.88, 123.5
    { 6153, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // Kalayang OSM: 16414281 -6.131, 106.7 x -6.12, 106.7
    { 75, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xbe6254} }, // 10 OSM: 16441473 WD: Q97276018 34.75, 113.4 x 34.75, 113.6
    { 6162, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffd700} }, // GLK OSM: 16467689 WD: Q112306598 -28.04, 153.3 x -27.93, 153.4
    { 6166, 39101, 3759, LineMetaDataContent::RapidTransit, Color{0xb2d019} }, // C-5a OSM: 16468881 WD: Q16595900 43.37, -5.856 x 43.54, -5.676
    { 9, NoLogo, 3346, LineMetaDataContent::Tramway, Color{0x78ccc9} }, // 4 OSM: 16507598 WD: Q123339542 50.48, 30.57 x 50.53, 30.61
    { 6, 6874, 3346, LineMetaDataContent::Tramway, Color{0x78ccc9} }, // 5 OSM: 16507674 WD: Q123339543 50.48, 30.57 x 50.53, 30.63
    { 781, NoLogo, 39130, LineMetaDataContent::Subway, Color{0x77248b} }, // N1 OSM: 16533437 WD: Q17068873 19.02, 73.04 x 19.07, 73.1
    { 6171, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xf0631e} }, // Delhi–Meerut RapidX OSM: 16534370 WD: Q30644700 28.66, 77.37 x 28.84, 77.58
    { 6, 39155, NoLogo, LineMetaDataContent::Tramway, Color{0x931980} }, // 5 OSM: 16542977 WD: Q123158516 56.81, 53.15 x 56.88, 53.26
    { 6193, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x1578be} }, // Springfield OSM: 16554068 WD: Q7581106 -27.67, 152.9 x -27.46, 153
    { 548, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x9085ba} }, // E OSM: 16603044 WD: Q2903493 48.53, 7.733 x 48.61, 7.786
    { 337, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x97bf0d} }, // F OSM: 16603070 WD: Q2724954 48.58, 7.716 x 48.59, 7.777
    { 235, 39174, NoLogo, LineMetaDataContent::Tramway, Color{0x80dfff} }, // 27 OSM: 16616831 WD: Q2106734 52.36, 4.786 x 52.36, 4.852
    { 1393, 39185, 34801, LineMetaDataContent::Tramway, Color{0xdce3e9} }, // T4 OSM: 16625348 WD: Q123249317 38.7, 35.49 x 38.73, 35.57
    { 26, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 16 OSM: 16626601 WD: Q123905215 49.51, 8.525 x 49.52, 8.535
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // 5 OSM: 16636889 WD: Q123336516 41.76, 140.7 x 41.79, 140.8
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 2 OSM: 16636892 WD: Q123336434 41.75, 140.7 x 41.79, 140.8
    { 6205, NoLogo, 32029, LineMetaDataContent::RapidTransit, Color{0x009158} }, // 23R OSM: 16653794 WD: Q23091313 53.46, -113.5 x 53.55, -113.4
    { 68, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x871f58} }, // 3 OSM: 16664741 WD: Q123363013 56.81, 60.54 x 56.86, 60.64
    { 6209, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xc23b33} }, // SALIS OSM: 16672157 -34.92, 138.6 x -34.76, 138.6
    { 6215, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xfe5000} }, // NOAR OSM: 16672579 -35.14, 138.5 x -34.92, 138.6
    { 3899, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x007dc3} }, // OSBORN OSM: 16672584 -34.92, 138.5 x -34.79, 138.6
    { 6220, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x007cba} }, // FESTVL OSM: 16672585 WD: Q115096643 -34.98, 138.5 x -34.92, 138.6
    { 5535, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x007dc3} }, // PTDOCK OSM: 16672586 -34.92, 138.5 x -34.84, 138.6
    { 6227, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xc23b33} }, // GAW OSM: 16672587 -34.92, 138.6 x -34.6, 138.7
    { 667, 24760, NoLogo, LineMetaDataContent::RapidTransit, Color{0x009ad5} }, // C-1 OSM: 16748029 WD: Q5987188 37.97, -1.131 x 38.35, -0.4964
    { 663, 15876, NoLogo, LineMetaDataContent::RapidTransit, Color{0xbb29bb} }, // C-3 OSM: 16750145 WD: Q5987209 38.35, -0.5322 x 38.4, -0.4964
    { 161, 39226, NoLogo, LineMetaDataContent::Subway, Color{0x5c88db} }, // 19 OSM: 16764494 WD: Q46461818 30.27, 103.8 x 30.76, 104.5
    { 2183, 39237, 3863, LineMetaDataContent::RapidTransit, Color{0x9f9825} }, // V OSM: 16792587 WD: Q123097765 48.72, 2.134 x 48.8, 2.259
    { 6231, 39271, NoLogo, LineMetaDataContent::LocalTrain, Color{0xc3403f} }, // ER-02 OSM: 16794669 WD: Q107613007 39.44, -0.3834 x 40.48, 0.4628
    { 6237, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xffa500} }, // 2-ая Сормовская линия OSM: 16801501 56.34, 43.83 x 56.37, 43.88
    { 6276, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x008000} }, // 1-ая Сормовская линия OSM: 16801503 56.3, 43.83 x 56.37, 43.94
    { 6315, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x0000ff} }, // Приокская линия OSM: 16801508 56.15, 43.79 x 56.32, 44.09
    { 146, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x771e1b} }, // 9 OSM: 16807055 WD: Q120442703 40.85, 14.27 x 40.97, 14.62
    { 63, 39286, 2034, LineMetaDataContent::Tramway, Color{} }, // 11 OSM: 16807373 WD: Q123741718 49.43, 11.06 x 49.46, 11.14
    { 75, 39304, 2034, LineMetaDataContent::Tramway, Color{} }, // 10 OSM: 16807577 WD: Q123741708 49.44, 11.05 x 49.49, 11.12
    { 2399, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xef8016} }, // R15 OSM: 16832732 59.12, 24.29 x 59.44, 24.74
    { 68, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xee2737} }, // 3 OSM: 16843978 WD: Q123825602 26.38, 106.7 x 26.66, 106.8
    { 15, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x1a60a5} }, // 12 OSM: 16848925 WD: Q97276033 34.7, 113.7 x 34.8, 113.8
    { 67, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0069b4} }, // 13 OSM: 16856381 WD: Q63348707 52.32, 9.717 x 52.43, 9.802
    { 524, 39322, 22034, LineMetaDataContent::Subway, Color{0xffc300} }, // L2 OSM: 16861886 WD: Q2894390 -12.06, -76.97 x -12.04, -76.94
    { 161, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x5ac1a7} }, // 19 OSM: 16890961 WD: Q61883430 30.48, 114.4 x 30.61, 114.5
    { 6345, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x000000} }, // REX1 OSM: 16908294 47.15, 9.601 x 47.55, 9.817
    { 697, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x000000} }, // R1 OSM: 16908313 47.15, 9.601 x 47.51, 9.817
    { 2289, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x000000} }, // R2 OSM: 16908348 47.16, 9.478 x 47.26, 9.617
    { 63, NoLogo, 29292, LineMetaDataContent::Subway, Color{0x004998} }, // 11 OSM: 16914085 WD: Q10940013 39.06, 117.3 x 39.08, 117.4
    { 16, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0072c8} }, // 2 OSM: 16918817 32, 120.8 x 32.08, 121
    { 1329, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00a6e2} }, // T3 OSM: 16919186 WD: Q124157448 51, 3.709 x 51.05, 3.751
    { 6350, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xdf1278} }, // T30 OSM: 16998183 WD: Q121832402 50.33, 18.84 x 50.4, 18.92
    { 71, NoLogo, 15857, LineMetaDataContent::RapidTransit, Color{0xf27e00} }, // S1 OSM: 16998465 WD: Q107983587 50.03, 14.43 x 50.11, 15.21
    { 645, NoLogo, 15857, LineMetaDataContent::RapidTransit, Color{0x0c823b} }, // S9 OSM: 16998476 WD: Q107981273 49.78, 14.43 x 50.08, 14.73
    { 1319, NoLogo, 15857, LineMetaDataContent::RapidTransit, Color{0x004c8a} }, // S20 OSM: 16998486 WD: Q107981848 49.67, 15.21 x 50.03, 15.48
    { 55, NoLogo, 15857, LineMetaDataContent::RapidTransit, Color{0xadca00} }, // S8 OSM: 16999860 WD: Q107983477 49.83, 14.37 x 50.08, 14.7
    { 6354, NoLogo, 15857, LineMetaDataContent::RapidTransit, Color{0xadca00} }, // S88 OSM: 16999884 WD: Q124286542 49.78, 14.18 x 50.08, 14.47
    { 46, NoLogo, 15857, LineMetaDataContent::RapidTransit, Color{0x8a0e99} }, // S7 OSM: 16999924 WD: Q107981429 49.92, 14.08 x 50.08, 14.44
    { 298, NoLogo, 15857, LineMetaDataContent::RapidTransit, Color{0xd73598} }, // S6 OSM: 16999925 WD: Q124206421 49.96, 14.07 x 50.06, 14.41
    { 5157, NoLogo, 15857, LineMetaDataContent::RapidTransit, Color{0x004c8a} }, // S22 OSM: 17000048 WD: Q124207650 50.09, 14.43 x 50.23, 14.88
    { 6358, 12205, 226, LineMetaDataContent::RapidTransit, Color{0xf5821f} }, // REX3 OSM: 17003122 WD: Q116212120 46.6, 14.31 x 46.84, 14.86
    { 6363, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x094b8d} }, // BEG OSM: 17011815 WD: Q52468593 -37.91, 144.9 x -37.81, 145.4
    { 516, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe4022d} }, // L4 OSM: 17051048 WD: Q22271918 -33.82, 151 x -33.78, 151
    { 1329, NoLogo, 35835, LineMetaDataContent::Tramway, Color{0xff0000} }, // T3 OSM: 17087733 WD: Q117209865 38.49, 27.03 x 38.51, 27.06
    { 6367, 39350, NoLogo, LineMetaDataContent::LocalTrain, Color{} }, // RB 40 OSM: 17097027 WD: Q62594138 50.03, 10.13 x 50.58, 10.45
    { 71, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xee2737} }, // S1 OSM: 17126909 WD: Q85884965 31.68, 120.3 x 31.93, 120.3
    { 64, NoLogo, 39374, LineMetaDataContent::Subway, Color{0xff0000} }, // 1 OSM: 17151480 WD: Q61132107 10.77, 106.7 x 10.88, 106.8
    { 64, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x0000ff} }, // 1 OSM: 17168709 24.54, 46.61 x 24.84, 46.78
    { 379, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff0000} }, // Red OSM: 17169524 WD: Q124472663 24.71, 46.62 x 24.8, 46.84
    { 6373, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x71771d} }, // RL3 OSM: 17169920 41.61, 0.6331 x 41.68, 1.276
    { 692, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x27404e} }, // 55 OSM: 17234032 WD: Q125858857 43.5, 16.11 x 43.68, 16.49
    { 64, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x050505} }, // 1 OSM: 17248700 52.26, 104.3 x 52.29, 104.3
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xec008c} }, // 2 OSM: 17248967 52.48, -2.12 x 52.55, -2.023
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x050505} }, // 2 OSM: 17262470 52.27, 104.3 x 52.29, 104.3
    { 68, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x050505} }, // 3 OSM: 17262471 52.26, 104.3 x 52.29, 104.3
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x050505} }, // 4 OSM: 17262669 52.28, 104.3 x 52.29, 104.4
    { 6377, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x050505} }, // 4а OSM: 17262670 52.28, 104.3 x 52.29, 104.4
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x050505} }, // 5 OSM: 17262736 52.26, 104.3 x 52.29, 104.4
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x050505} }, // 6 OSM: 17262737 52.26, 104.3 x 52.29, 104.4
    { 6381, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x6ab560} }, // S65 OSM: 17271238 WD: Q130279395 47.65, 8.571 x 47.7, 8.634
    { 118, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0c7cac} }, // 22 OSM: 17271943 WD: Q122307239 51.08, 16.95 x 51.14, 17.06
    { 2732, NoLogo, 226, LineMetaDataContent::RapidTransit, Color{0x979b51} }, // S62 OSM: 17283322 WD: Q115597873 47.7, 8.631 x 47.76, 8.844
    { 2185, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x812990} }, // S44 OSM: 17295945 47.56, 9.103 x 47.66, 9.192
    { 27, 28090, 28113, LineMetaDataContent::Subway, Color{0xf47421} }, // 6 OSM: 17320239 WD: Q28050323 22.47, 88.39 x 22.52, 88.4
    { 6367, 39394, NoLogo, LineMetaDataContent::LocalTrain, Color{} }, // RB 40 OSM: 17329127 WD: Q113237935 48.12, 11.53 x 48.28, 12.52
    { 6385, 39411, NoLogo, LineMetaDataContent::LocalTrain, Color{0xbf73bf} }, // RB 33 OSM: 17329553 WD: Q113257915 48.14, 11.48 x 48.55, 12.14
    { 64, NoLogo, 39428, LineMetaDataContent::Subway, Color{0xffd700} }, // 1 OSM: 17332151 WD: Q120727502 27.16, 78.02 x 27.18, 78.06
    { 235, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x7b2c1c} }, // 27 OSM: 17363700 WD: Q16655738 50, 14.4 x 50.11, 14.46
    { 441, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x489224} }, // M2 OSM: 17392107 WD: Q2094433 50.4, 4.271 x 50.42, 4.452
    { 27, 39438, NoLogo, LineMetaDataContent::Subway, Color{0xe88f99} }, // 6 OSM: 17399102 WD: Q17041527 43.77, 125.2 x 43.87, 125.4
    { 6, NoLogo, 12736, LineMetaDataContent::Subway, Color{0xf2da51} }, // 5 OSM: 17417178 WD: Q10906685 31.89, 118.8 x 31.96, 118.8
    { 2142, 39458, NoLogo, LineMetaDataContent::LocalTrain, Color{0x94288e} }, // 34 OSM: 17463221 WD: Q9025916 41.09, -0.9102 x 41.66, 2.194
    { 225, NoLogo, 15857, LineMetaDataContent::RapidTransit, Color{0xf27e00} }, // S3 OSM: 17510471 WD: Q107983587 50.09, 14.43 x 50.42, 14.92
    { 59, NoLogo, 15857, LineMetaDataContent::RapidTransit, Color{0xf27e00} }, // S2 OSM: 17510472 WD: Q107983587 50.03, 14.43 x 50.2, 15.21
    { 27, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x6cace4} }, // 6 OSM: 17518162 WD: Q15951864 35.89, 120.1 x 36.07, 120.2
    { 6391, NoLogo, 15857, LineMetaDataContent::RapidTransit, Color{0x221e44} }, // S49 OSM: 17518306 WD: Q124209102 50.06, 14.39 x 50.16, 14.54
    { 64, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xa8c45b} }, // 1 OSM: 17573457 WD: Q4461884 48.69, 44.45 x 48.71, 44.51
    { 1608, NoLogo, 15857, LineMetaDataContent::RapidTransit, Color{0x004c8a} }, // S18 OSM: 17618880 WD: Q107981848 49.84, 14.91 x 50.03, 15.22
    { 47, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xaf9778} }, // 7 OSM: 17625150 WD: Q122382723 49.77, 18.16 x 49.83, 18.25
    { 2137, NoLogo, 13937, LineMetaDataContent::RapidTransit, Color{0xf8a01d} }, // S35 OSM: 17667387 WD: Q126280860 46.98, 7.193 x 47.08, 7.307
    { 1255, NoLogo, 13937, LineMetaDataContent::RapidTransit, Color{0x2eaad7} }, // S36 OSM: 17680047 WD: Q126364854 47.07, 7.305 x 47.14, 7.372
    { 6395, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00985f} }, // 1T OSM: 17684227 60.15, 24.92 x 60.22, 24.96
    { 1865, NoLogo, 13937, LineMetaDataContent::RapidTransit, Color{0xf8a01d} }, // S41 OSM: 17691416 WD: Q126435512 46.76, 7.533 x 47.2, 7.659
    { 6398, NoLogo, 13937, LineMetaDataContent::RapidTransit, Color{0xe93f3c} }, // S37 OSM: 17692752 WD: Q126462529 47, 7.1 x 47.13, 7.246
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x2ea9df} }, // 4 OSM: 17703073 WD: Q60489245 41.65, 123.4 x 41.72, 123.5
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x5b3256} }, // 5 OSM: 17703079 WD: Q28415059 41.74, 123.5 x 41.83, 123.7
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf9906f} }, // 6 OSM: 17703082 WD: Q60489247 41.63, 123.4 x 41.67, 123.5
    { 343, NoLogo, 13937, LineMetaDataContent::RapidTransit, Color{0xb2ab15} }, // S45 OSM: 17719346 WD: Q126599145 47, 7.706 x 47.03, 7.737
    { 1723, NoLogo, 13937, LineMetaDataContent::RapidTransit, Color{0xf05c5b} }, // S42 OSM: 17721914 WD: Q126682726 46.76, 7.602 x 47.02, 7.659
    { 2620, NoLogo, 13937, LineMetaDataContent::RapidTransit, Color{0xaabdc7} }, // S43 OSM: 17721916 WD: Q126684691 46.76, 7.602 x 46.88, 7.629
    { 1888, NoLogo, 13937, LineMetaDataContent::RapidTransit, Color{0xb2ab15} }, // S21 OSM: 17729990 WD: Q126375827 46.76, 7.602 x 46.88, 7.629
    { 301, NoLogo, 13937, LineMetaDataContent::RapidTransit, Color{0xc5c5c5} }, // S46 OSM: 17732995 WD: Q126722833 46.96, 7.462 x 47.2, 7.623
    { 62, NoLogo, 13937, LineMetaDataContent::RapidTransit, Color{0xc5c5c5} }, // S11 OSM: 17733316 WD: Q126723656 46.75, 7.439 x 46.97, 7.63
    { 725, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x00c000} }, // T2 OSM: 17739982 WD: Q127634096 21.02, 105.8 x 21.07, 105.9
    { 5157, NoLogo, 13937, LineMetaDataContent::RapidTransit, Color{0xc5c5c5} }, // S22 OSM: 17744674 WD: Q126741563 46.88, 7.438 x 46.97, 7.79
    { 1329, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x810080} }, // T3 OSM: 17746162 WD: Q126688499 53.82, -3.056 x 53.93, -3.007
    { 725, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x810080} }, // T2 OSM: 17746167 WD: Q126688487 53.78, -3.058 x 53.82, -3.05
    { 289, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x810080} }, // T1 OSM: 17746184 WD: Q121905024 53.78, -3.058 x 53.93, -3.007
    { 22, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x714684} }, // 18 OSM: 17758259 WD: Q122382731 49.77, 18.23 x 49.85, 18.29
    { 68, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009cdd} }, // 3 OSM: 17801363 53.41, 14.49 x 53.46, 14.55
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x009cdd} }, // 4 OSM: 17801519 53.42, 14.53 x 53.43, 14.56
    { 64, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 1 OSM: 17814455 22.88, 113.9 x 22.89, 113.9
    { 68, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffa500} }, // 3 OSM: 17814719 22.88, 113.9 x 22.89, 113.9
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0000ff} }, // 2 OSM: 17814720 22.88, 113.9 x 22.89, 113.9
    { 15, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x0e4094} }, // 12 OSM: 17823595 51.32, 12.37 x 51.38, 12.4
    { 64, NoLogo, 39483, LineMetaDataContent::Tramway, Color{0xf56400} }, // 1 OSM: 17824358 WD: Q16934349 34.35, 132.5 x 34.4, 132.5
    { 47, 39504, NoLogo, LineMetaDataContent::Subway, Color{0x868383} }, // 7 OSM: 17824814 WD: Q30106092 -33.44, -70.75 x -33.35, -70.51
    { 19, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0xff8000} }, // 8 OSM: 17824838 WD: Q47012748 -33.57, -70.61 x -33.41, -70.56
    { 146, 39529, NoLogo, LineMetaDataContent::Subway, Color{0xff00ff} }, // 9 OSM: 17824839 WD: Q47012852 -33.62, -70.65 x -33.43, -70.57
    { 16, NoLogo, 39483, LineMetaDataContent::Tramway, Color{0xff0000} }, // 2 OSM: 17829928 WD: Q16934367 34.31, 132.3 x 34.4, 132.5
    { 1723, 39554, 9742, LineMetaDataContent::RapidTransit, Color{0xea5921} }, // S42 OSM: 17837183 WD: Q86525060 50.59, 5.456 x 50.62, 5.585
    { 68, NoLogo, 39483, LineMetaDataContent::Tramway, Color{0x13349b} }, // 3 OSM: 17862442 WD: Q5770095 34.35, 132.4 x 34.4, 132.5
    { 6, NoLogo, 39483, LineMetaDataContent::Tramway, Color{0x53c76c} }, // 5 OSM: 17862537 WD: Q5770098 34.35, 132.5 x 34.4, 132.5
    { 27, NoLogo, 39483, LineMetaDataContent::Tramway, Color{0xfefe00} }, // 6 OSM: 17865453 WD: Q15698320 34.37, 132.4 x 34.4, 132.5
    { 47, NoLogo, 39483, LineMetaDataContent::Tramway, Color{0x316631} }, // 7 OSM: 17868350 WD: Q5770102 34.35, 132.4 x 34.41, 132.5
    { 19, NoLogo, 39483, LineMetaDataContent::Tramway, Color{0xff61d2} }, // 8 OSM: 17868437 WD: Q5770106 34.37, 132.4 x 34.41, 132.5
    { 146, NoLogo, 39483, LineMetaDataContent::Tramway, Color{0x666666} }, // 9 OSM: 17868556 WD: Q5770109 34.39, 132.5 x 34.4, 132.5
    { 27, 39576, NoLogo, LineMetaDataContent::Subway, Color{0x3fb9e4} }, // 6 OSM: 17876064 WD: Q60748166 31.27, 120.5 x 31.38, 120.8
    { 68, 39597, NoLogo, LineMetaDataContent::Subway, Color{0x02b7bb} }, // 3 OSM: 17876724 WD: Q17068887 19.06, 72.85 x 19.13, 72.88
    { 6402, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x1b5620} }, // Тр9 OSM: 17887458 WD: Q124735446 49.83, 23.99 x 49.86, 24.04
    { 6408, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x00a5ff} }, // 云巴 OSM: 17925374 WD: Q85884212 34.16, 108.8 x 34.24, 108.9
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x008f4d} }, // 2 OSM: 17944395 WD: Q8192892 33.84, 132.8 x 33.85, 132.8
    { 2237, NoLogo, 23736, LineMetaDataContent::RapidTransit, Color{0x94c01a} }, // R6 OSM: 17946664 WD: Q115455110 46.47, 6.395 x 46.69, 6.913
    { 153, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xb53586} }, // 14 OSM: 17947118 50.93, 6.949 x 50.97, 7.007
    { 6415, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xe30613} }, // 10E OSM: 17954274 51.3, 12.37 x 51.31, 12.4
    { 6419, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xffcc00} }, // 9E OSM: 17954276 51.31, 12.37 x 51.38, 12.43
    { 6422, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00985f} }, // 8T OSM: 17996071 60.15, 24.91 x 60.21, 24.98
    { 26, 39629, 5450, LineMetaDataContent::Subway, Color{0x03795f} }, // 16 OSM: 18020157 WD: Q18239278 55.62, 37.48 x 55.67, 37.52
    { 19, 39654, NoLogo, LineMetaDataContent::Subway, Color{0xa09200} }, // 8 OSM: 18026577 WD: Q6553157 31.25, 120.5 x 31.38, 120.7
    { 146, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x974578} }, // 9 OSM: 18052953 WD: Q122216457 53.1, 17.99 x 53.14, 18.06
    { 6, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xf8c300} }, // 5 OSM: 18052954 WD: Q122216453 53.12, 17.99 x 53.17, 18.17
    { 68, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff0000} }, // 3 OSM: 18052956 WD: Q122216451 53.12, 17.96 x 53.17, 18.17
    { 27, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x00993d} }, // 6 OSM: 18052957 WD: Q122216454 53.1, 18 x 53.13, 18.11
    { 16, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x28166f} }, // 2 OSM: 18052958 WD: Q122216450 53.1, 18 x 53.15, 18.06
    { 19, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x8f5144} }, // 8 OSM: 18052959 WD: Q122216456 53.1, 17.99 x 53.14, 18.06
    { 75, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xb50094} }, // 10 OSM: 18052960 WD: Q122216458 53.12, 18 x 53.17, 18.17
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x9dcd17} }, // 4 OSM: 18052961 WD: Q122216452 53.1, 18 x 53.13, 18.06
    { 64, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x75c5f0} }, // 1 OSM: 18052962 WD: Q122216449 53.12, 17.96 x 53.15, 18.06
    { 47, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xff6600} }, // 7 OSM: 18052963 WD: Q122216455 53.1, 18.04 x 53.17, 18.17
    { 52, NoLogo, 15857, LineMetaDataContent::RapidTransit, Color{0xf27e00} }, // S5 OSM: 18058106 WD: Q107983587 50.08, 14.08 x 50.15, 14.41
    { 67, NoLogo, 35568, LineMetaDataContent::Tramway, Color{0x00985f} }, // 13 OSM: 18064772 WD: Q105156970 60.18, 24.92 x 60.2, 24.98
    { 686, NoLogo, 8524, LineMetaDataContent::Tramway, Color{0x336195} }, // 35 OSM: 18077847 WD: Q120225339 50.86, 4.347 x 50.9, 4.398
    { 75, 39675, 8524, LineMetaDataContent::Tramway, Color{0x8f4199} }, // 10 OSM: 18078371 WD: Q111210270 50.81, 4.336 x 50.91, 4.402
    { 2137, NoLogo, 9742, LineMetaDataContent::RapidTransit, Color{0x0091cc} }, // S35 OSM: 18081371 WD: Q125298427 51.22, 4.421 x 51.36, 4.633
    { 1760, 39697, NoLogo, LineMetaDataContent::Tramway, Color{0xb16400} }, // T7 OSM: 18085218 WD: Q129566114 41.03, 28.91 x 41.05, 28.94
    { 1393, 39725, NoLogo, LineMetaDataContent::Tramway, Color{0x4e7fc0} }, // T4 OSM: 18086824 WD: Q112843286 33.56, -7.625 x 33.59, -7.516
    { 6425, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xdcddde} }, // 6XX OSM: 18087072 WD: Q130356823 37.31, -122.4 x 37.78, -121.9
    { 1329, 39749, NoLogo, LineMetaDataContent::Tramway, Color{0x79549e} }, // T3 OSM: 18088102 WD: Q112843280 33.54, -7.612 x 33.6, -7.546
    { 9, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0x000000} }, // 4 OSM: 18088225 WD: Q122585346 55.75, 37.66 x 55.82, 37.78
    { 75, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x009f4d} }, // 10 OSM: 18089015 WD: Q130361184 34.32, 109 x 34.52, 109.1
    { 6, NoLogo, 29292, LineMetaDataContent::Subway, Color{0xf8b5c4} }, // 5 OSM: 18099359 WD: Q109344086 38.95, 117.1 x 39.27, 117.2
    { 6429, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // Мінск => Чырвоны Сцяг OSM: 18109043 53.89, 27.55 x 54.04, 28.2
    { 6467, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xff0000} }, // Чырвоны Сцяг => Мінск OSM: 18116867 53.89, 27.55 x 54.04, 28.2
    { 6505, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x2daae1} }, // U SAL-BAO OSM: 18157385 WD: Q1314068 38.53, -9.08 x 38.66, -8.871
    { 6515, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x2daae1} }, // U BAO-SAL OSM: 18157386 WD: Q1314068 38.53, -9.08 x 38.66, -8.871
    { 64, NoLogo, 6890, LineMetaDataContent::Tramway, Color{0xce1417} }, // 1 OSM: 18165464 WD: Q123168035 59.93, 30.23 x 59.96, 30.26
    { 225, NoLogo, NoLogo, LineMetaDataContent::Subway, Color{0x9d9d9e} }, // S3 OSM: 18168636 WD: Q97200617 30.11, 104.4 x 30.28, 104.7
    { 62, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xe41346} }, // S11 OSM: 18195342 WD: Q125989612 49.9, 17.91 x 49.94, 18.19
    { 1113, NoLogo, 24274, LineMetaDataContent::Subway, Color{0x53b848} }, // 2A OSM: 18214853 WD: Q20647027 12.98, 80.16 x 13.09, 80.27
    { 6525, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x8966c3} }, // Seac Pai Van OSM: 18238280 WD: Q17500826 22.13, 113.6 x 22.14, 113.6
    { 68, 7466, NoLogo, LineMetaDataContent::Tramway, Color{0x1aab47} }, // 3 OSM: 18253532 WD: Q123155973 56.79, 53.19 x 56.85, 53.25
    { 15, 39773, NoLogo, LineMetaDataContent::Tramway, Color{0xca0706} }, // 12 OSM: 18261043 WD: Q123158535 56.79, 53.19 x 56.87, 53.28
    { 19, 39155, NoLogo, LineMetaDataContent::Tramway, Color{0x931980} }, // 8 OSM: 18261047 WD: Q123158516 56.84, 53.23 x 56.88, 53.26
    { 6538, NoLogo, NoLogo, LineMetaDataContent::Tramway, Color{0xee1d23} }, // Э OSM: 18265752 WD: Q121537880 51.9, 29.21 x 52.05, 29.33
    { 6541, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0x777777} }, // U ATE-AZA OSM: 18298965 WD: Q576138 38.71, -9.174 x 39.07, -8.865
    { 6551, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa162a5} }, // U LSA-AZA OSM: 18317501 WD: Q576138 38.71, -9.122 x 39.07, -8.865
    { 3794, NoLogo, NoLogo, LineMetaDataContent::RapidTransit, Color{0xa162a5} }, // U AZA-LSA OSM: 18317718 WD: Q576138 38.71, -9.122 x 39.07, -8.867
};

static constexpr const auto line_data_count = sizeof(line_data) / sizeof(LineMetaDataContent);

static inline constexpr uint16_t Bucket(uint16_t index) { return line_data_count + index; }

static const int16_t line_data_bucketTable[] = {
    3822, 1697, 1713, 1714, 1715, 1696, -1,
    3601, 2126, -1,
    456, 460, 2940, 511, 510, 488, 2942, -1,
    1508, 3189, 3188, -1,
    1412, 2114, 2980, 3297, 3298, 3299, -1,
    1540, 3579, 3323, 1464, 1541, 1549, -1,
    1084, 2493, 319, -1,
    2964, 1792, 2966, 2967, 2968, -1,
    1148, 1149, 1144, 414, 1145, 1150, 1151, 1143, 1146, 1147, -1,
    516, 515, 1520, -1,
    508, 2773, 446, -1,
    1326, 242, -1,
    1980, 2959, 1428, 2961, 2963, -1,
    2190, 2192, 1008, -1,
    280, 2841, 2840, -1,
    3196, 3195, -1,
    3186, 1509, 3191, 3190, 1711, 1690, -1,
    1767, 1766, -1,
    2002, 2013, 3540, -1,
    625, 1952, 1841, 323, 1950, 1951, -1,
    2095, 2096, 2124, 2130, 2946, 2947, 2935, 3050, -1,
    819, 823, 824, -1,
    3502, 3520, -1,
    3429, 3259, -1,
    1609, 1716, 1834, 1414, -1,
    1716, 1834, -1,
    1848, 1247, 963, 1232, 3630, 2136, 966, 924, 923, 1854, 415, 3559, 964, -1,
    3666, 3658, 1736, 1560, 1557, 1556, -1,
    2328, 1546, 1460, 1447, 1463, -1,
    428, 3085, 2712, 432, 3658, 2527, -1,
    320, 2499, -1,
    2752, 3770, 2749, -1,
    3661, 2752, 3770, 2749, 2750, -1,
    3524, 3506, -1,
    3341, 2924, 3342, -1,
    3159, 2204, 1987, 2205, 2243, 2207, 2512, -1,
    2833, 2336, 2874, 3175, 2627, 3174, 3199, 3065, 2335, -1,
    2683, 3260, 2681, 3897, 1091, 1090, -1,
    2683, 3260, 2681, 3897, 1092, 1091, 1090, 2658, 1083, -1,
    1979, 2805, 2804, 2965, -1,
    3261, 1753, 1047, -1,
    3101, 650, -1,
    1152, 671, -1,
    3000, 3011, -1,
    3306, 513, 2281, 2916, 993, 2267, 2855, 2777, 514, 2268, -1,
    1107, 1101, 1199, 1105, 795, -1,
    1409, 2817, 2818, 1770, 1769, 2819, -1,
    1425, 2957, 2949, -1,
    3737, 1915, 1916, 1912, 1522, 294, 1914, -1,
    3120, 3119, -1,
    3185, 1522, -1,
    1889, 346, 2457, 1881, -1,
    1933, 2177, -1,
    3154, 2982, 1683, 2178, 1674, 1684, 1686, 1658, 1659, 1656, 1657, 1687, 1589, 1655, 871, -1,
    1860, 1552, 3713, 1300, -1,
    2882, 2872, 2873, -1,
    3693, 1764, 3565, 1773, 2795, -1,
    844, 241, 2502, 1953, 302, -1,
    1925, 1935, 3560, 1936, -1,
    973, 474, 974, 1406, 742, 990, -1,
    2106, 2117, 2118, 2107, 3474, 2138, 3049, 2135, 2134, 3599, 3598, 3047, 3045, 2643, 3044, -1,
    1661, 590, 115, 119, 884, 888, 889, 1413, -1,
    1925, 1935, 3560, -1,
    1551, 1661, 590, 753, 485, 119, 2909, 886, 887, 888, 889, 1413, 890, 891, 892, 896, 935, 897, 898, -1,
    820, 821, 822, 825, -1,
    2476, 2475, 1618, 915, -1,
    2827, 2187, -1,
    2827, 3584, 3617, 3615, -1,
    3517, 2510, 974, 1406, -1,
    2315, 2095, 2097, 2106, 2098, 2096, 2117, 2118, 2124, 2107, 3352, 2115, 575, 2131, 2462, 2417, -1,
    2315, 3487, -1,
    2131, 571, 2445, 1096, 1097, 3812, 25, 1820, -1,
    691, 692, 873, -1,
    529, 3487, -1,
    3795, 3628, 258, 798, -1,
    3249, 3181, 3184, -1,
    3791, 1874, 1873, -1,
    529, 3816, 3815, 3217, 3258, 1239, 2553, -1,
    962, 1241, -1,
    1048, 2375, 2371, 2370, 772, 2374, 2377, 3635, 3636, 3824, 3790, 1579, 3890, -1,
    255, 437, 1237, 1236, 1849, 1850, -1,
    1867, 1153, 1058, 962, 1241, 961, 2133, -1,
    969, 971, 970, -1,
    1035, 36, 1279, 967, 965, 1867, 14, -1,
    3791, 2691, 3037, 3081, 2701, -1,
    1038, 1039, 2701, -1,
    3783, 3824, 3785, 3790, 3823, -1,
    1038, 1039, 3290, 1555, -1,
    1537, 3324, 1545, 1550, 1548, 1547, 1539, 1469, 3495, 3325, 2620, -1,
    1346, 3219, 872, -1,
    3585, 3586, -1,
    2660, 2672, 2671, -1,
    2111, 3640, 3639, -1,
    2165, 2156, -1,
    2426, 2381, 2380, 2309, 2311, 2310, -1,
    2009, 2693, -1,
    1806, 2885, 406, 2551, 2884, -1,
    3163, 3160, 3621, 3620, -1,
    2870, 3716, -1,
    3696, 666, 665, 996, 997, 3697, -1,
    2575, 3741, -1,
    2230, 2360, 3164, -1,
    3171, 3761, -1,
    3319, 3771, -1,
    1808, 2788, -1,
    2196, 2697, 3083, -1,
    2699, 2764, -1,
    2160, 2161, -1,
    2852, 2434, -1,
    376, 2168, -1,
    1477, 1042, 2444, 3425, 498, 497, 383, 384, 499, -1,
    2223, 3733, -1,
    2047, 2590, 2635, 3150, 3294, 2835, 2323, -1,
    2624, 2737, 2774, 2721, -1,
    3709, 3633, 3708, 3458, -1,
    2970, 2408, 2254, 1791, 3533, -1,
    2988, 835, 834, 2991, 839, 2989, 2987, 838, 2992, 837, 2990, 836, -1,
    2970, 2408, -1,
    2802, 2806, 2807, 2808, 2809, 2810, 2811, -1,
    206, 338, 1606, 2441, -1,
    2754, 2753, -1,
    2258, 2265, 2256, 2257, 2259, 2260, 2262, -1,
    2981, 3498, -1,
    1750, 1752, 1751, -1,
    1417, 1416, -1,
    1982, 1981, 1978, -1,
    3001, 3002, 2999, 2998, 2997, -1,
    2910, 2238, 2240, -1,
    3002, 2998, 2997, -1,
    2709, 2711, 2713, 2719, 362, 357, 2746, 2745, 3082, 361, 2768, 2770, 2771, 2763, 2549, 2938, 2760, 2548, 2742, 298, 2941, 2939, 363, 2943, 2149, -1,
    2709, 2713, 2719, 361, 2770, 2941, -1,
    1195, 1193, 3686, 2580, 2585, 2582, -1,
    3857, 2700, -1,
    1158, 244, 243, -1,
    3016, 3017, -1,
    3008, 3006, 3010, 3004, 3007, 3009, -1,
    1941, 1942, 3896, -1,
    3107, 2100, -1,
    2396, 3915, 2141, 3525, 3917, 2394, 2933, 2395, 2398, 3916, 2397, -1,
    3915, 3525, 3917, 3916, -1,
    3106, 3107, -1,
    1737, 1294, 2651, 2656, -1,
    2191, 2558, 1580, 2555, 2143, 2145, 2153, 2150, 2154, 2148, -1,
    1624, 2842, -1,
    1624, 2782, -1,
    2982, 3800, -1,
    332, 333, -1,
    3848, 3846, -1,
    269, 2717, 1974, 2718, 2089, 1894, 2003, 1998, 2001, 240, 3149, 1781, 2091, 1763, -1,
    1946, 1945, 1944, 1222, 1142, 1221, 1948, 1227, 1228, 1947, 1224, 1954, 1895, 950, 3489, 586, 1842, -1,
    1924, 3555, 1918, 1919, 1913, 1920, 1930, 1931, 1932, 1922, -1,
    1306, 1308, -1,
    841, 840, -1,
    2922, 2137, 2139, 3873, -1,
    2556, 2098, 2105, 2127, 2129, 2108, 3352, 2611, 3843, 2640, 2641, 3833, 2642, 3842, 2613, -1,
    1930, 1923, -1,
    939, 1927, -1,
    1906, 3229, 209, 210, -1,
    1924, 1918, 1553, 1929, 3894, 1919, 1913, -1,
    1446, 1455, 1456, 1459, 1458, -1,
    523, 895, 83, 84, 98, -1,
    893, 1033, 1694, 1034, 1031, -1,
    3292, 3293, 3247, -1,
    817, 811, 812, 1383, 818, 826, -1,
    3675, 3247, -1,
    2598, 2602, 2601, 2600, -1,
    2285, 1815, -1,
    3478, 2294, -1,
    3681, 3602, 3447, 3609, 3610, 3041, 3038, 3039, 3549, 1053, 2505, 2536, 2814, 2534, 2506, 2507, 2508, 2509, 2535, -1,
    2127, 2129, 2108, 2128, 2116, 2125, 580, 2447, 2465, 3031, 2778, 2608, 2464, 3086, -1,
    2996, 2447, 1240, 2464, 3813, 1283, -1,
    2509, 2510, -1,
    1632, 1635, -1,
    3777, 3776, -1,
    3229, 209, 580, 2608, -1,
    19, 1719, 22, 16, 902, 1098, 1099, 149, 1818, 1819, -1,
    1288, 3020, 3813, -1,
    116, 2500, 117, 118, 1405, 1235, 126, 405, 46, 57, 30, 58, 59, 2597, 47, 48, 49, 50, 51, 52, 53, 54, -1,
    1250, 1251, 1252, 1253, -1,
    854, 1405, -1,
    3246, 798, -1,
    238, 237, 229, 3296, -1,
    1631, 1632, 1633, 1634, 1635, -1,
    3183, 3182, -1,
    352, 2471, 2470, 183, 1870, 354, 184, 781, 143, 1285, -1,
    237, 229, -1,
    3467, 3469, 3465, -1,
    3527, 3529, 3528, 1735, -1,
    3789, 3788, 3787, -1,
    916, 946, 941, 1161, -1,
    1517, 610, 1619, 647, 1620, 637, 636, 179, -1,
    221, 3412, -1,
    151, 132, 158, -1,
    138, 110, 112, 170, 114, 169, 1111, 3557, 2432, -1,
    97, 27, 28, 1793, 1244, 3627, 391, 177, 178, 2614, 93, 1905, 2799, 186, 12, 15, 273, 337, 168, 165, 164, 139, 163, 162, 161, -1,
    97, 391, 177, 178, 15, 273, -1,
    2825, 137, 365, 375, 288, 1339, 254, -1,
    2696, 2702, -1,
    3025, 3436, -1,
    3665, 3592, 3664, -1,
    3573, 3566, 3578, -1,
    1543, 592, 591, 1443, -1,
    1542, 3650, 1538, -1,
    1536, 3556, -1,
    1543, 592, 1443, -1,
    3572, 3573, 1966, 3578, 1965, 3574, 3561, -1,
    1350, 1351, 1352, -1,
    1167, 1174, -1,
    3665, 3659, 3592, 3664, -1,
    1371, 1370, 1369, 1366, 1392, 1396, 1372, 1623, 991, 1011, 340, 3670, 1810, 949, 1853, 3626, 3625, -1,
    998, 995, 1082, 999, 948, -1,
    1638, 1480, 3590, 1482, 1483, -1,
    2065, 2066, 1829, 225, 1976, 3902, 3903, -1,
    670, 3641, -1,
    2907, 2906, 2905, -1,
    652, 3914, -1,
    1321, 1322, 1320, -1,
    1957, 1996, -1,
    688, 1023, -1,
    3358, 3359, 2483, -1,
    3144, 3145, -1,
    2796, 2866, -1,
    2692, 2290, 2293, -1,
    3754, 3450, -1,
    3061, 3062, -1,
    2077, 2076, -1,
    2734, 2738, 2739, 2741, -1,
    530, 555, 503, 2379, 557, 927, 1790, 570, 528, 492, 561, 560, 642, 639, 3899, 559, 641, 558, 1216, 543, 554, -1,
    920, 3476, -1,
    3015, 2637, -1,
    2461, 2358, 2354, 2355, 2361, 2410, 2357, -1,
    2162, 2359, 2710, 3414, -1,
    2425, 2420, 2424, 3225, 2932, -1,
    846, 2430, 3646, 3167, 2429, 1054, 3471, 2428, -1,
    3364, 2684, 3420, 3575, 2688, 3351, -1,
    327, 325, 329, -1,
    2233, 2584, 2706, 3152, 2694, 2724, 329, -1,
    3431, 2698, 2690, -1,
    2420, 3225, 2932, -1,
    2780, 3336, -1,
    2182, 3900, 2890, 2183, 2780, 3331, 3336, -1,
    3330, 2189, -1,
    2448, 2929, 3327, -1,
    1086, 3435, -1,
    2610, 1403, 1402, 389, -1,
    3408, 3067, 3410, 3340, -1,
    3347, 3705, -1,
    2443, 2208, 2891, 3427, -1,
    2277, 2931, -1,
    1246, 1245, 1248, 2212, 3361, -1,
    3349, 3868, 3879, -1,
    1822, 1964, 1962, 1963, 2954, 3251, 1826, 2845, 299, 1828, 1959, 1832, 304, 1960, 1961, -1,
    378, 3369, 495, 1478, 1476, 2851, 496, 3116, 3305, -1,
    2486, 2480, -1,
    2280, 2219, -1,
    2516, 2234, 2815, -1,
    2516, 2524, -1,
    2278, 2198, 2197, 3820, -1,
    2516, 2504, -1,
    2415, 2416, -1,
    3072, 3070, -1,
    2679, 2338, -1,
    2456, 2892, 2622, 1571, -1,
    3365, 2275, -1,
    286, 251, 300, 0, 63, 1, 249, 3792, 3480, -1,
    2779, 787, 2723, -1,
    2459, 3743, -1,
    2794, 2793, 2955, -1,
    1272, 2532, -1,
    2570, 2572, -1,
    1727, 1519, -1,
    2801, 2800, 3063, 2812, -1,
    1605, 2837, 2836, -1,
    2756, 2755, -1,
    3280, 3278, 3279, -1,
    1030, 945, 1036, 958, -1,
    1971, 1972, 1973, -1,
    2241, 2242, 2239, 1977, -1,
    2826, 2237, -1,
    3024, 2917, 2282, -1,
    2761, 509, 356, 3084, 2743, 507, 1001, 359, 2269, 1002, 360, 2729, -1,
    509, 507, 1002, -1,
    3859, 2051, 2053, 1871, -1,
    245, 1985, -1,
    1298, 2790, 792, -1,
    1298, 1102, 2790, -1,
    2250, 2251, 3378, -1,
    1812, 2176, -1,
    2781, 2787, 2786, -1,
    2958, 2956, 2960, 2962, 3097, 2847, 2736, 2194, 2193, -1,
    3130, 3537, -1,
    3106, 3111, -1,
    2925, 3905, 2926, 3904, -1,
    1728, 3657, 1723, 1721, 1722, 2300, -1,
    295, 1917, -1,
    2849, 2832, 3194, -1,
    2104, 2103, -1,
    1497, 2179, 1590, -1,
    566, 563, 564, 565, -1,
    3192, 3193, 3187, -1,
    2985, 2983, 2984, -1,
    1009, 1010, 1027, 3648, -1,
    783, 1357, -1,
    1997, 2014, 266, 267, -1,
    2407, 270, -1,
    3504, 1845, 3762, -1,
    1223, 1226, -1,
    2113, 2112, 3315, 3316, -1,
    1342, 3819, -1,
    1864, 3893, 1897, 2301, 1862, 1989, 2248, 1316, 1876, 1907, 2304, 1990, 1365, 1908, 1909, 1921, 1923, -1,
    2919, 2920, -1,
    1525, 381, -1,
    553, 475, -1,
    476, 3715, 553, 478, 475, -1,
    1364, 1382, 1154, 2950, 2639, 3046, 3845, 2648, 3830, 2647, 2644, 1353, -1,
    1364, 1154, 2639, 3845, 2648, 3839, 235, -1,
    2128, 2125, 2859, 2766, 577, 2860, 2744, -1,
    1909, 1910, 1922, -1,
    1865, 910, -1,
    2607, 3138, -1,
    3439, 3440, 2246, -1,
    756, 1554, -1,
    487, 899, 900, -1,
    754, 755, 756, 757, 758, -1,
    1258, 1908, -1,
    1738, 1744, 2413, 3148, 1740, 1701, 1703, 1704, 1705, -1,
    1636, 1637, 2896, -1,
    1554, 1672, 1671, -1,
    486, 1462, 1468, -1,
    486, 2900, 480, 481, 483, -1,
    397, 3546, -1,
    2630, 2631, 2494, -1,
    3679, 3677, 3678, 3674, 3675, 3767, -1,
    3421, 814, -1,
    3679, 3674, 3767, -1,
    37, 39, -1,
    3205, 3206, -1,
    2037, 3616, 1943, -1,
    3608, 3614, 3587, 2034, 2037, 2378, 3543, 1943, 3248, -1,
    2199, 2295, -1,
    3516, 3519, 3514, -1,
    3115, 2533, -1,
    578, 2767, 3033, 3034, 235, -1,
    2769, 2766, 2765, 2767, 3003, 577, 2860, 2744, -1,
    2453, 3032, 3033, -1,
    1073, 1896, 1072, 699, 1076, 1074, 1075, 1068, 1070, 1078, 1071, 567, 1809, 2438, 581, 1050, 2708, 2433, 571, 562, 568, 2439, 579, 2418, 583, -1,
    3515, 3517, 3514, -1,
    3031, 2453, -1,
    1288, 580, 2708, 571, 2453, 2446, 562, 2445, 344, -1,
    3656, 3057, -1,
    1288, 3077, 3441, 3059, 3013, 3442, 3058, 3055, 3022, 3118, -1,
    1627, 1629, 1630, -1,
    3569, 3076, 3077, -1,
    3181, 3182, 1341, -1,
    3053, 583, -1,
    1717, 1718, 24, 1709, 21, 541, 854, 532, -1,
    984, 1315, 899, 900, 902, -1,
    982, 3692, 983, 980, 986, 984, 985, 3048, 987, 3399, 988, 989, 1315, 899, 900, 902, 854, 532, -1,
    201, 1582, 1802, 1586, 1250, 1251, 901, 922, 392, -1,
    901, 922, 698, 392, -1,
    1870, 780, 144, 143, -1,
    3769, 215, 724, 216, 230, 681, 634, 680, -1,
    1627, 1629, -1,
    173, 556, 780, 144, 1277, -1,
    2390, 2389, 1420, -1,
    1407, 1798, 1890, -1,
    3468, 3466, -1,
    635, 1051, 1847, 1080, 2366, 2365, 2363, 2373, 2368, 2367, 3818, 700, 701, 2452, 3538, 752, 760, 762, 2376, 3826, 3786, 3784, -1,
    635, 1051, 1847, 2366, 2365, 2363, 2373, 2367, 3818, 700, 2452, 3538, 752, 760, 762, 3823, 3826, -1,
    775, 777, 778, -1,
    1128, 3773, 2518, 2519, 1129, 1135, 1121, 1127, 1125, 1136, 1130, 938, 1040, 1424, -1,
    1387, 1388, 1389, -1,
    1621, 195, -1,
    130, 3386, -1,
    153, 154, 155, -1,
    75, 77, 72, -1,
    75, 76, 77, 72, -1,
    1529, 1733, 1735, 2454, -1,
    534, 538, 539, 540, 573, 533, 574, 3631, -1,
    7, 6, 95, 92, 32, 31, 94, 33, 3207, 8, 5, 187, 167, -1,
    1529, 2454, -1,
    64, 1559, 1558, 79, -1,
    66, 122, 64, 82, 136, 123, 81, 1956, 1559, 1558, 1212, 1197, 1314, 79, 80, -1,
    925, 707, -1,
    2450, 407, -1,
    401, 1682, 398, 2529, 2531, 402, 2326, 1544, 593, 1380, 1442, 1440, -1,
    1544, 1442, 1440, -1,
    1423, 3019, 3829, 2393, 2450, 3908, -1,
    845, 843, -1,
    1345, 1093, 1348, 1213, 1191, 1670, 1349, 843, 3706, 1088, 1292, 1347, -1,
    1156, 1155, -1,
    430, 429, -1,
    855, 856, 870, 859, 2730, 868, 3654, 869, 861, 865, 434, -1,
    1526, 1511, 1668, 2492, 2491, 1664, 2490, 1665, 2017, 1663, 1805, 1510, 1512, 3653, 2489, 2514, 1514, 1515, 2018, 1804, 2019, 2033, -1,
    2670, 2669, 2668, 2667, 2666, 2664, 2663, 2662, 3644, 2677, 2675, 2661, 2674, 3483, -1,
    2669, 2668, 2667, 2664, 2663, 2662, 3644, 2677, 2675, 2659, 2674, 3483, -1,
    668, 334, 3711, 669, 1473, 3710, 3712, -1,
    3699, 3700, 3701, -1,
    1394, 1622, 1368, -1,
    1681, 1596, 1595, 1612, 1599, 1611, 1594, 1603, 1591, 1592, -1,
    1106, 1189, 1190, 1188, 1210, 1113, -1,
    882, 876, -1,
    2099, 3073, 3074, -1,
    3393, 3392, -1,
    1640, 1642, -1,
    936, 790, 791, 1811, -1,
    832, 831, 804, 806, 3250, 810, 830, 712, 829, 802, 828, 722, 805, 3563, 2094, 1120, 2093, 3173, -1,
    3500, 3722, 3721, -1,
    3089, 3090, 3091, -1,
    3729, 3237, 3238, 1958, 349, 345, -1,
    903, 729, 955, 678, 904, 719, 717, 1013, 710, 1066, 905, 906, 673, 711, 709, 718, 907, 723, 720, 731, 672, 1024, 3102, 732, 728, 3218, -1,
    2482, 2481, -1,
    1644, 1645, -1,
    2167, 3909, 3334, 3321, 3322, -1,
    3146, 3142, 3141, 3143, -1,
    2041, 2042, -1,
    3756, 3758, 3454, 1361, 3453, 3755, 3452, 3757, 3753, -1,
    2306, 2305, 2552, -1,
    3798, 2537, 2538, 3799, -1,
    2023, 2619, -1,
    2074, 464, 463, 467, -1,
    656, 657, -1,
    1179, 1182, 1181, 1238, 526, 1384, 525, 542, 3651, 1836, 569, 640, -1,
    2828, 1869, 1384, 640, -1,
    3548, 552, -1,
    2056, 1200, 1202, 1203, 504, 3493, -1,
    1005, 3695, 1006, 1007, -1,
    1123, 1902, 1898, 1903, 1839, 1938, 387, 1940, 3752, 1229, -1,
    2629, 3532, -1,
    853, 2423, 2948, 3227, 3348, -1,
    1196, 1344, 1899, 1707, -1,
    324, 1772, 2759, -1,
    2297, 2684, -1,
    3153, 3539, 3580, 2695, 2032, 3357, -1,
    2195, 3683, -1,
    2437, 3775, 2655, 2654, 3430, 2689, 2287, -1,
    2889, 3660, -1,
    3684, 2181, -1,
    2188, 2171, 3374, -1,
    2188, 3772, 2171, 3375, 3374, 2894, -1,
    2937, 3172, -1,
    3326, 3485, -1,
    1613, 2203, -1,
    3405, 3406, -1,
    2921, 3477, -1,
    2442, 3345, 2893, 3344, -1,
    3329, 3338, -1,
    2276, 3409, 3285, -1,
    2888, 3332, -1,
    3821, 2231, -1,
    2653, 3593, 2652, -1,
    382, 379, 3426, 385, 1041, 1032, -1,
    3544, 2485, 2484, 3901, 2487, -1,
    3428, 2228, 3629, -1,
    3040, 2521, 2044, -1,
    3040, 2044, -1,
    2170, 2169, -1,
    1600, 1601, 1602, 3835, 3837, -1,
    1600, 3069, 1601, 1602, 3835, 3836, 2792, -1,
    2414, 2411, 2024, -1,
    3856, 3862, 3863, 3865, -1,
    3856, 3863, -1,
    2347, 2346, 2349, -1,
    2322, 2329, 2591, 2588, 2831, 2333, 2581, 2565, 2332, -1,
    773, 1094, 353, 293, 125, 263, 444, 1087, 248, -1,
    11, 3136, -1,
    2715, 2748, -1,
    181, 180, 1270, 1271, 1273, 1725, -1,
    1833, 1835, 3162, -1,
    1691, 1692, -1,
    2253, 2263, 2261, 2264, -1,
    975, 952, -1,
    2244, 2245, -1,
    2209, 2211, 2784, 213, 2649, 3066, 2783, 2227, -1,
    3023, 3029, 3030, 3028, 2914, 2279, -1,
    2707, 2271, 2272, 3068, 1856, -1,
    2707, 2761, -1,
    2834, 3694, 3691, -1,
    2050, 3858, 2049, 2052, 2054, -1,
    589, 1116, -1,
    1299, 1289, -1,
    2185, 2184, 2186, 1449, -1,
    3105, 3108, -1,
    3521, 519, 1786, 3523, 3522, 2071, -1,
    1724, 1720, -1,
    1254, 2157, -1,
    1254, 2164, 2157, 2163, -1,
    347, 1872, 1281, -1,
    433, 1803, -1,
    347, 395, 1872, 1281, 1877, -1,
    279, 277, 278, 1626, 1625, 2842, -1,
    396, 1785, -1,
    1654, 2351, -1,
    1504, 2511, 1501, 1498, 1499, 1506, 1503, 1502, 1654, 2351, 1495, 1496, 1494, -1,
    1218, 3209, 3230, -1,
    1332, 1800, -1,
    2879, 2876, 2881, 2875, 2880, -1,
    2725, 2726, 2728, 2727, -1,
    2928, 2934, -1,
    1851, 1846, -1,
    1892, 2055, 2474, 1304, 1354, -1,
    1852, 1843, -1,
    689, 690, -1,
    3140, 3155, -1,
    2302, 1243, 1242, 833, 1878, -1,
    1313, 1311, 1305, 1307, 1309, 2857, -1,
    1337, 1336, 1334, 1335, -1,
    1430, 1432, 1431, -1,
    3841, 3840, -1,
    2546, 1377, 2559, 2561, 2562, 2563, 2544, 2606, 2545, 2547, 2554, 3156, 3139, -1,
    235, 236, -1,
    2566, 3138, -1,
    1377, 2563, 2544, 2545, 2547, 2554, 3139, -1,
    202, 204, -1,
    202, 204, 725, -1,
    748, 121, 1660, -1,
    1410, 2951, 3781, 1411, -1,
    2904, 1263, 1264, 3484, 1257, 1260, 1261, 1262, 1521, 1256, -1,
    1741, 1742, 1746, 1739, 2412, 1743, -1,
    101, 1355, 102, 369, 368, -1,
    1747, 1739, 2412, -1,
    1437, 1451, 1454, 1438, 1453, 3222, 1457, 1445, -1,
    90, 87, 1673, 91, 88, 89, 86, 1666, 746, 85, 747, 1667, -1,
    748, 3874, 121, 1660, 1662, -1,
    1566, 1397, 1404, 1422, 1565, 740, 1567, 1516, 1568, 1569, 1570, -1,
    1397, 740, 1516, 484, 2902, 482, -1,
    2901, 894, -1,
    2488, 3638, -1,
    3289, 3287, 3676, -1,
    2877, 3289, 3676, -1,
    2249, 2008, -1,
    3180, 3179, -1,
    45, 41, 100, 38, 3470, 43, 409, 99, 42, 44, 40, 2068, 2067, 3088, 3312, -1,
    3283, 3277, -1,
    2200, 2201, -1,
    578, 2767, -1,
    3554, 2767, -1,
    2453, 2446, -1,
    1288, 2453, 2446, 582, 2435, -1,
    2438, 3031, 2439, 2418, -1,
    3031, 2463, 2439, 2418, -1,
    2995, 3055, -1,
    3564, 3078, 1240, 3055, -1,
    1288, 582, 3810, -1,
    20, 801, 23, 3417, 1408, -1,
    487, 854, -1,
    705, 1581, 651, 1813, 1250, 1252, 1253, -1,
    1217, 3535, 3223, 3730, -1,
    978, 979, 487, 3731, -1,
    1583, 1588, 1587, -1,
    694, 695, 416, 686, 1252, 1253, -1,
    693, 694, 695, 416, 686, 921, 1484, 455, 1485, 1282, 1488, 1489, 1490, -1,
    770, 771, -1,
    930, 343, 929, 196, 928, -1,
    231, 257, -1,
    211, 2567, 212, 2568, 350, -1,
    189, 190, 174, 193, 188, 191, 1327, 175, 247, 1284, 1278, 1225, 1276, 1286, 1287, -1,
    682, 683, 2560, 684, 685, 1891, -1,
    454, 452, 453, 1789, 451, 450, -1,
    1265, 1267, -1,
    683, 685, 1891, -1,
    3719, 3637, 3783, 3823, -1,
    3637, 3783, -1,
    1356, 1328, 2383, 2384, 2385, 1329, 2386, -1,
    61, 62, 427, 426, 423, 435, 436, -1,
    1132, 1137, 1415, -1,
    1056, 2838, 1475, 1085, 2824, 1079, -1,
    217, 224, 1220, 218, 219, 220, 222, 505, 1133, -1,
    147, 148, 146, -1,
    297, 296, 3387, 3876, -1,
    1527, 1534, 1043, 1535, 1528, 527, 1530, 1531, 1532, 1734, -1,
    4, 29, 35, 96, 2, 3, 879, 13, -1,
    1527, 1534, 1535, 1528, 1530, 1532, 1734, -1,
    646, 290, 292, 291, -1,
    761, 850, 3850, 765, 769, 768, 2830, -1,
    761, 3850, 765, 769, 2830, -1,
    3168, 1648, 1649, 1650, 1651, 782, 3169, 785, 793, 784, 794, 1646, 1643, 1647, -1,
    425, 424, 3025, -1,
    128, 67, 65, 113, -1,
    1028, 150, 751, 750, 3472, -1,
    307, 370, 371, 306, 1523, 1524, 372, 104, 3363, 305, 1572, -1,
    3384, 3383, 3381, 3379, 3385, -1,
    301, 796, -1,
    594, 2528, 411, 399, 9, 595, 608, 607, 2618, 599, 604, 609, 400, 1318, 253, 606, 602, 597, 603, 601, 500, 1381, 1379, 1748, -1,
    3233, 3234, 3231, 3232, -1,
    1614, 1615, 2564, 3624, 2085, 1616, 1617, -1,
    3400, 3394, -1,
    2400, 3720, 413, 2392, 3451, 1427, 3849, 3012, 3035, 3036, -1,
    3782, 1669, -1,
    1466, 1465, 1467, -1,
    2320, 2318, 2402, 2317, 2319, 2578, 2576, 2403, 2401, 2314, 2404, 2577, -1,
    1162, 3508, 1168, 1169, 1171, 1173, 1175, 1177, 1163, 1164, 3170, 1165, 1178, 417, 1166, 1172, -1,
    1162, 1169, 1171, 1165, 1178, 417, 1172, -1,
    857, 3718, 858, 860, 3811, 862, 863, 864, 867, -1,
    3888, 3882, -1,
    3888, 3886, 3884, 3882, 3887, 3881, 3883, 3889, 3885, 3880, -1,
    1816, 3702, -1,
    1373, 1472, 1395, 1046, 1375, 1610, 1712, 1393, 1598, 1367, 1398, -1,
    140, 877, 880, 878, 141, 145, 142, 875, 881, -1,
    1302, 1301, -1,
    1760, 1757, 1758, 1759, 2498, -1,
    1760, 1761, 1757, 1758, 1759, 318, 2498, -1,
    1760, 1761, 1757, 1758, 1759, 3075, 318, 2498, 1095, -1,
    3726, 3727, 3728, -1,
    3263, 3264, 3262, -1,
    827, 3286, 3360, 799, 947, -1,
    3388, 3389, -1,
    3501, 3723, -1,
    3094, 3092, -1,
    659, 667, 272, 271, -1,
    944, 942, -1,
    3104, 3135, 3132, 3133, 3134, 3103, 3109, 3113, 3126, 3110, 3114, 3112, 3127, 3125, 3129, -1,
    336, 335, -1,
    1319, 1325, -1,
    662, 663, 664, 3505, -1,
    3906, 848, 1067, -1,
    3906, 1012, 1015, 1018, -1,
    1014, 713, 1017, 1295, 714, 1019, 1000, 730, 1016, -1,
    3680, 2714, -1,
    2292, 2291, -1,
    676, 3455, -1,
    3758, 3454, -1,
    3605, 3606, -1,
    1884, 1883, 1882, 3688, 1886, 3689, -1,
    2144, 2087, 2022, -1,
    2120, 2121, -1,
    1762, 2732, 2731, 2735, 2542, 2740, -1,
    1762, 2732, 2731, -1,
    341, 468, 469, -1,
    1214, 1206, 1209, -1,
    493, 572, 1900, 494, 3878, 638, -1,
    3827, 653, 2569, -1,
    956, 3765, 312, 3764, 313, 314, 308, 316, 309, 310, -1,
    956, 312, 313, 309, -1,
    546, 549, 550, 551, 544, -1,
    1201, 1204, -1,
    615, 619, 623, 624, 617, 618, 1765, 614, 1796, 622, 626, 616, 629, 612, 628, 620, 1782, 633, 621, 611, 1795, 630, -1,
    619, 624, 617, 618, 1765, 614, 1782, 611, -1,
    1858, 1141, -1,
    1857, 1858, 1840, 1939, 1141, 1157, 1576, -1,
    3463, 3464, -1,
    3456, 3457, -1,
    2422, 3461, -1,
    3583, 3814, -1,
    536, 726, 501, 3366, -1,
    2229, 3494, -1,
    1340, 388, 2686, -1,
    2225, 3353, -1,
    328, 2758, -1,
    3356, 328, -1,
    3214, 3213, -1,
    3735, 3530, -1,
    1059, 1104, 1103, 1065, -1,
    3802, 3804, 3806, 3807, -1,
    2224, 3707, -1,
    1401, 3014, -1,
    2893, 3407, -1,
    2158, 3198, 3413, -1,
    2853, 3328, -1,
    2215, 2930, -1,
    2158, 2159, 3198, 3413, -1,
    2215, 2469, 2930, 2468, -1,
    2166, 2206, -1,
    3424, 2431, -1,
    3779, 3433, 3437, -1,
    3166, 2175, 1967, -1,
    2175, 1967, 2843, -1,
    1986, 2236, 1970, -1,
    3040, 2236, 2235, 1970, -1,
    953, 954, -1,
    3872, 1575, -1,
    2030, 2029, 2039, -1,
    2339, 2340, 2341, 2337, 2343, 2342, -1,
    721, 3177, 2345, -1,
    2589, 2592, -1,
    2324, 2331, 2334, 2325, 2321, 2330, 2574, -1,
    3750, 3749, -1,
    1333, 677, 351, 443, 445, -1,
    457, 458, -1,
    3793, 2720, -1,
    2856, 2903, -1,
    2895, 3479, -1,
    2217, 2218, 3284, -1,
    449, 1607, 1471, -1,
    3273, 3272, -1,
    3272, 3271, -1,
    1419, 1418, -1,
    2650, 2623, 2747, -1,
    213, 214, -1,
    3026, 3095, 3027, 2913, 2912, 2915, 512, -1,
    2913, 2912, 512, -1,
    3095, 512, -1,
    1117, 246, -1,
    1118, 1117, -1,
    2273, 2883, -1,
    2515, 1794, 331, 2072, 2069, -1,
    2173, 2174, -1,
    2152, 2142, -1,
    2142, 2172, -1,
    285, 282, 3482, -1,
    276, 275, -1,
    1500, 1507, 1491, 1493, 1492, -1,
    261, 909, -1,
    2406, 2405, -1,
    2813, 2775, -1,
    2879, 2876, -1,
    2088, 2000, -1,
    2088, 2090, -1,
    394, 1296, 1297, -1,
    1949, 940, -1,
    1274, 2503, -1,
    1274, 3892, 2303, -1,
    2540, 2927, -1,
    477, 2616, -1,
    477, 479, 2616, -1,
    1861, 1863, -1,
    203, 205, -1,
    203, 205, 1731, -1,
    2247, 3744, 3745, -1,
    1134, 1706, 1676, 367, -1,
    1134, 1355, 1701, -1,
    1436, 1452, 1439, 1435, 1444, -1,
    521, 522, -1,
    120, 749, -1,
    976, 1695, 1003, 1685, -1,
    2497, 2496, 2495, -1,
    2479, 2583, -1,
    1678, 1680, -1,
    3276, 3202, -1,
    807, 815, -1,
    2210, 2226, -1,
    250, 393, -1,
    1824, 1821, 1825, 1823, -1,
    1824, 1825, 1823, -1,
    2036, 1122, -1,
    2036, 3895, -1,
    3612, 3619, 3460, 3623, 3597, -1,
    3622, 3623, 3597, 3645, -1,
    1062, 1063, -1,
    2463, 2445, -1,
    1809, 2438, -1,
    3020, 3077, 3022, -1,
    197, 200, -1,
    2599, 200, 56, 60, -1,
    197, 60, -1,
    977, 981, -1,
    687, 697, 1486, 1487, -1,
    1251, 1486, 1488, -1,
    1233, 403, 1234, 404, 2952, -1,
    3768, 171, -1,
    172, 192, 774, -1,
    3256, 3254, -1,
    176, 232, -1,
    1139, 3311, 1331, 1330, -1,
    1049, 2364, 2369, 2372, 759, -1,
    1049, 2369, 2372, 759, -1,
    2634, 422, -1,
    1126, 1131, -1,
    931, 933, -1,
    17, 18, -1,
    1386, 1390, 1391, -1,
    506, 223, 1124, 3415, -1,
    133, 3404, 157, 134, 135, -1,
    111, 3875, 3499, -1,
    73, 968, -1,
    73, 71, 968, -1,
    1533, 1593, -1,
    199, 745, -1,
    766, 3370, 767, -1,
    366, 2865, -1,
    421, 419, 420, -1,
    421, 419, -1,
    911, 912, -1,
    911, 912, 914, -1,
    78, 159, -1,
    182, 106, 109, 108, 107, 103, 74, 127, -1,
    1385, 706, 926, -1,
    3567, 3571, -1,
    600, 3662, 3632, 605, 441, 380, 1749, -1,
    702, 703, 733, 704, 734, -1,
    703, 733, 704, 734, 3231, -1,
    3663, 852, 649, 648, 524, -1,
    3393, 3392, 3396, -1,
    600, 441, -1,
    1176, 1729, 851, -1,
    3370, 769, 768, -1,
    3042, 3043, -1,
    1755, 1756, 317, 1761, -1,
    1755, 1756, -1,
    1055, 1421, -1,
    3725, 3398, -1,
    786, 937, 3870, -1,
    708, 716, 715, -1,
    800, 803, -1,
    339, 348, -1,
    1479, 1639, 2848, -1,
    1479, 1639, 1481, 2848, -1,
    1975, 226, -1,
    645, 3576, -1,
    2615, 3667, 281, 797, -1,
    3667, 797, -1,
    943, 3738, 3739, -1,
    1323, 1324, -1,
    3832, 3240, 3241, 3242, 3877, 3243, -1,
    3235, 3244, 3891, 3832, 3236, 3239, 3240, 3241, 3242, 3877, 3243, -1,
    1021, 1470, 1020, -1,
    3165, 3161, 3747, -1,
    1887, 1885, -1,
    2110, 2109, -1,
    2973, 2974, -1,
    2120, 2121, 2122, -1,
    472, 473, -1,
    342, 472, 465, 473, 470, 471, -1,
    1211, 1205, 1207, 1208, 364, 3531, -1,
    1183, 1184, -1,
    1180, 1185, 1799, -1,
    438, 311, 303, 315, -1,
    547, 548, -1,
    735, 654, 3912, 739, 736, 3742, 738, -1,
    735, 654, 658, 3912, 739, 736, 3742, 3913, 738, -1,
    632, 631, 627, 613, -1,
    632, 613, -1,
    615, 619, 624, 1796, 626, 633, 611, 632, 1795, 631, 613, -1,
    1904, 3687, 1831, -1,
    2059, 1904, 2132, 3687, 1138, 1219, -1,
    2006, 3869, -1,
    1774, 1775, 1776, 1778, 1699, 1777, 1700, -1,
    1774, 1775, 1776, 1778, 1699, 1777, 1700, 1788, 1787, 1779, 2772, 1780, -1,
    3854, 3853, -1,
    3513, 3512, -1,
    3805, 3808, 3809, -1,
    2081, 3123, -1,
    1986, 2044, -1,
    2015, 2075, -1,
    3317, 3318, -1,
    412, 252, 3582, 537, -1,
    3449, 3448, -1,
    727, 1698, 1269, 1268, -1,
    2863, 3281, -1,
    3274, 3275, -1,
    2458, 3267, -1,
    2784, 2783, -1,
    1115, 1119, -1,
    1801, 1868, 2617, -1,
    2978, 2979, -1,
    3760, 284, 282, -1,
    908, 1564, -1,
    994, 2612, -1,
    808, 813, -1,
    3445, 3446, -1,
    3473, 3445, 3446, 3682, 3509, -1,
    1077, 1069, -1,
    3257, 3253, 3255, -1,
    442, 1400, -1,
    1533, 1043, -1,
    588, 233, 585, -1,
    588, 585, -1,
    763, 3851, -1,
    418, 420, -1,
    105, 3339, -1,
    3382, 3380, -1,
    410, 2530, 408, -1,
    440, 410, 2530, 439, -1,
    3397, 3391, 3390, 3395, -1,
    3370, 769, -1,
    2678, 2673, -1,
    3558, 3350, -1,
    318, 3221, -1,
    3724, 326, -1,
    1479, 1639, -1,
    661, 662, -1,
    3912, 3911, 738, -1,
    623, 617, 618, 616, -1,
    1776, 1778, 1777, -1,
    3864, 3866, -1,
    1069, 2453, -1,
    70, 69, -1,
    619, 617, 618, 611, 632, -1,
    3269, 3268, -1,
    624, 1765, -1,
};

static const constexpr LineMetaDataQuadTreeDepthIndex line_data_depthOffsets[] = {
    { 27, 0 },
    { 26, 3 },
    { 25, 20 },
    { 24, 73 },
    { 23, 196 },
    { 22, 449 },
    { 21, 852 },
    { 20, 1313 },
    { 19, 1763 },
    { 18, 1992 },
    { 17, 2079 },
    { 16, 2150 },
};

static const constexpr LineMetaDataZIndex line_data_zquadtree[] = {
    { 227, Bucket(0) }, // 30.8, -5.517 x 44.22, 7.905
    { 230, 3346 }, // 44.22, -5.517 x 57.64, 7.905
    { 236, Bucket(7) }, // 44.22, 7.905 x 57.64, 21.33
    { 390, 2969 }, // 30.8, -119.6 x 37.51, -112.9
    { 397, 2520 }, // 37.51, -112.9 x 44.22, -106.2
    { 400, 2213 }, // 44.22, -126.3 x 50.93, -119.6
    { 431, Bucket(10) }, // 37.51, -79.34 x 44.22, -72.63
    { 773, 2940 }, // 37.51, -72.63 x 44.22, -65.91
    { 903, 1293 }, // 37.51, -12.23 x 44.22, -5.517
    { 909, 1901 }, // 37.51, -5.517 x 44.22, 1.194
    { 911, Bucket(18) }, // 37.51, 1.194 x 44.22, 7.905
    { 922, 1412 }, // 44.22, 1.194 x 50.93, 7.905
    { 923, 1934 }, // 50.93, 1.194 x 57.64, 7.905
    { 944, Bucket(22) }, // 44.22, 7.905 x 50.93, 14.62
    { 945, 972 }, // 50.93, 7.905 x 57.64, 14.62
    { 946, Bucket(29) }, // 44.22, 14.62 x 50.93, 21.33
    { 950, Bucket(36) }, // 57.64, 14.62 x 64.35, 21.33
    { 956, 2751 }, // 57.64, 21.33 x 64.35, 28.04
    { 2321, 3698 }, // 50.93, 34.75 x 57.64, 41.46
    { 2627, 3634 }, // -29.6, 148.8 x -22.89, 155.5
    { 1555, 2657 }, // 34.15, -123 x 37.51, -119.6
    { 1558, 2657 }, // 37.51, -123 x 40.86, -119.6
    { 1560, Bucket(40) }, // 30.8, -119.6 x 34.15, -116.2
    { 1561, 1792 }, // 34.15, -119.6 x 37.51, -116.2
    { 1695, Bucket(46) }, // 40.86, -89.4 x 44.22, -86.05
    { 1724, Bucket(57) }, // 37.51, -79.34 x 40.86, -75.98
    { 1726, Bucket(61) }, // 37.51, -75.98 x 40.86, -72.63
    { 1727, 461 }, // 40.86, -75.98 x 44.22, -72.63
    { 2313, 322 }, // -32.96, -65.91 x -29.6, -62.56
    { 2314, 242 }, // -36.31, -62.56 x -32.96, -59.2
    { 2336, Bucket(65) }, // -36.31, -59.2 x -32.96, -55.85
    { 3093, Bucket(68) }, // 40.86, -72.63 x 44.22, -69.27
    { 3636, Bucket(74) }, // 37.51, -5.517 x 40.86, -2.162
    { 3637, 1928 }, // 40.86, -5.517 x 44.22, -2.162
    { 3638, Bucket(78) }, // 37.51, -2.162 x 40.86, 1.194
    { 3639, 3402 }, // 40.86, -2.162 x 44.22, 1.194
    { 3644, Bucket(82) }, // 37.51, 1.194 x 40.86, 4.549
    { 3645, Bucket(85) }, // 40.86, 1.194 x 44.22, 4.549
    { 3685, Bucket(92) }, // 54.28, -5.517 x 57.64, -2.162
    { 3686, Bucket(95) }, // 50.93, -2.162 x 54.28, 1.194
    { 3689, Bucket(99) }, // 47.57, 1.194 x 50.93, 4.549
    { 3690, Bucket(106) }, // 44.22, 4.549 x 47.57, 7.905
    { 3692, 1230 }, // 50.93, 1.194 x 54.28, 4.549
    { 3735, Bucket(115) }, // 40.86, 11.26 x 44.22, 14.62
    { 3741, 3801 }, // 40.86, 14.62 x 44.22, 17.97
    { 3764, 2477 }, // 37.51, 21.33 x 40.86, 24.68
    { 3776, Bucket(119) }, // 44.22, 7.905 x 47.57, 11.26
    { 3778, 1875 }, // 44.22, 11.26 x 47.57, 14.62
    { 3779, Bucket(122) }, // 47.57, 11.26 x 50.93, 14.62
    { 3780, Bucket(125) }, // 50.93, 7.905 x 54.28, 11.26
    { 3781, Bucket(130) }, // 54.28, 7.905 x 57.64, 11.26
    { 3782, Bucket(133) }, // 50.93, 11.26 x 54.28, 14.62
    { 3783, 923 }, // 54.28, 11.26 x 57.64, 14.62
    { 3785, Bucket(147) }, // 47.57, 14.62 x 50.93, 17.97
    { 3786, Bucket(154) }, // 44.22, 17.97 x 47.57, 21.33
    { 3787, 3418 }, // 47.57, 17.97 x 50.93, 21.33
    { 3788, Bucket(160) }, // 50.93, 14.62 x 54.28, 17.97
    { 3790, 3668 }, // 50.93, 17.97 x 54.28, 21.33
    { 3800, Bucket(167) }, // 57.64, 14.62 x 60.99, 17.97
    { 3802, Bucket(167) }, // 57.64, 17.97 x 60.99, 21.33
    { 3824, Bucket(170) }, // 57.64, 21.33 x 60.99, 24.68
    { 3826, Bucket(174) }, // 57.64, 24.68 x 60.99, 28.04
    { 9180, 3060 }, // 10.66, 122 x 14.02, 125.3
    { 9265, 2083 }, // 34.15, 48.17 x 37.51, 51.53
    { 9285, 2869 }, // 54.28, 34.75 x 57.64, 38.1
    { 9771, 2687 }, // 20.73, 111.9 x 24.09, 115.3
    { 9863, Bucket(180) }, // 27.44, 118.6 x 30.8, 122
    { 9875, Bucket(183) }, // 34.15, 118.6 x 37.51, 122
    { 9883, Bucket(187) }, // 34.15, 125.3 x 37.51, 128.7
    { 9886, Bucket(187) }, // 37.51, 125.3 x 40.86, 128.7
    { 9913, 3212 }, // 34.15, 135.4 x 37.51, 138.8
    { 9915, Bucket(195) }, // 34.15, 138.8 x 37.51, 142.1
    { 10510, 3642 }, // -29.6, 152.2 x -26.25, 155.5
    { 3830, 2043 }, // -12.82, -77.66 x -11.15, -75.98
    { 6221, Bucket(205) }, // 35.83, -123 x 37.51, -121.3
    { 6232, Bucket(212) }, // 37.51, -123 x 39.18, -121.3
    { 6243, Bucket(222) }, // 32.47, -117.9 x 34.15, -116.2
    { 6337, 489 }, // 32.47, -112.9 x 34.15, -111.2
    { 6723, Bucket(227) }, // 32.47, -97.79 x 34.15, -96.11
    { 6770, Bucket(231) }, // 37.51, -91.08 x 39.18, -89.4
    { 6782, Bucket(234) }, // 40.86, -87.73 x 42.54, -86.05
    { 6879, Bucket(237) }, // 42.54, -81.01 x 44.22, -79.34
    { 6898, 2911 }, // 37.51, -77.66 x 39.18, -75.98
    { 6901, 3011 }, // 42.54, -79.34 x 44.22, -77.66
    { 6905, Bucket(240) }, // 39.18, -75.98 x 40.86, -74.3
    { 6907, 1448 }, // 39.18, -74.3 x 40.86, -72.63
    { 6910, 2949 }, // 40.86, -74.3 x 42.54, -72.63
    { 6922, 885 }, // 44.22, -94.44 x 45.9, -92.76
    { 7082, 2596 }, // 44.22, -74.3 x 45.9, -72.63
    { 9219, 3486 }, // -34.64, -70.95 x -32.96, -69.27
    { 9268, 3367 }, // -26.25, -65.91 x -24.57, -64.24
    { 9407, Bucket(251) }, // -24.57, -47.46 x -22.89, -45.78
    { 9751, Bucket(257) }, // -24.57, -44.1 x -22.89, -42.43
    { 9794, Bucket(257) }, // -22.89, -44.1 x -21.21, -42.43
    { 11817, 3368 }, // -34.64, 17.97 x -32.96, 19.65
    { 11913, 2886 }, // -34.64, 24.68 x -32.96, 26.36
    { 12372, Bucket(264) }, // 40.86, -72.63 x 42.54, -70.95
    { 14463, Bucket(268) }, // 42.54, -7.195 x 44.22, -5.517
    { 14533, Bucket(276) }, // 35.83, -5.517 x 37.51, -3.839
    { 14535, 1797 }, // 35.83, -3.839 x 37.51, -2.162
    { 14549, Bucket(279) }, // 42.54, -5.517 x 44.22, -3.839
    { 14551, Bucket(282) }, // 42.54, -3.839 x 44.22, -2.162
    { 14552, 3759 }, // 37.51, -2.162 x 39.18, -0.4838
    { 14555, 3763 }, // 39.18, -0.4838 x 40.86, 1.194
    { 14558, Bucket(287) }, // 40.86, -0.4838 x 42.54, 1.194
    { 14580, Bucket(290) }, // 40.86, 1.194 x 42.54, 2.872
    { 14651, Bucket(306) }, // 52.61, -7.195 x 54.28, -5.517
    { 14729, 374 }, // 45.9, -2.162 x 47.57, -0.4838
    { 14739, Bucket(311) }, // 52.61, -3.839 x 54.28, -2.162
    { 14745, Bucket(312) }, // 52.61, -2.162 x 54.28, -0.4838
    { 14746, Bucket(315) }, // 50.93, -0.4838 x 52.61, 1.194
    { 14756, Bucket(321) }, // 47.57, 1.194 x 49.25, 2.872
    { 14759, Bucket(327) }, // 49.25, 2.872 x 50.93, 4.549
    { 14762, Bucket(332) }, // 44.22, 6.227 x 45.9, 7.905
    { 14763, Bucket(339) }, // 45.9, 6.227 x 47.57, 7.905
    { 14765, 1926 }, // 49.25, 4.549 x 50.93, 6.227
    { 14767, Bucket(355) }, // 49.25, 6.227 x 50.93, 7.905
    { 14770, Bucket(364) }, // 50.93, 2.872 x 52.61, 4.549
    { 14778, Bucket(368) }, // 50.93, 6.227 x 52.61, 7.905
    { 14940, Bucket(388) }, // 40.86, 11.26 x 42.54, 12.94
    { 15031, 1081 }, // 29.12, 29.72 x 30.8, 31.39
    { 15058, Bucket(393) }, // 37.51, 23 x 39.18, 24.68
    { 15066, 2296 }, // 37.51, 26.36 x 39.18, 28.04
    { 15089, Bucket(398) }, // 39.18, 28.04 x 40.86, 29.72
    { 15092, Bucket(401) }, // 40.86, 28.04 x 42.54, 29.72
    { 15104, Bucket(406) }, // 44.22, 7.905 x 45.9, 9.583
    { 15105, Bucket(411) }, // 45.9, 7.905 x 47.57, 9.583
    { 15107, Bucket(428) }, // 45.9, 9.583 x 47.57, 11.26
    { 15108, Bucket(431) }, // 47.57, 7.905 x 49.25, 9.583
    { 15109, Bucket(440) }, // 49.25, 7.905 x 50.93, 9.583
    { 15110, Bucket(444) }, // 47.57, 9.583 x 49.25, 11.26
    { 15111, Bucket(447) }, // 49.25, 9.583 x 50.93, 11.26
    { 15113, Bucket(452) }, // 45.9, 11.26 x 47.57, 12.94
    { 15115, Bucket(456) }, // 45.9, 12.94 x 47.57, 14.62
    { 15116, Bucket(460) }, // 47.57, 11.26 x 49.25, 12.94
    { 15117, Bucket(468) }, // 49.25, 11.26 x 50.93, 12.94
    { 15119, Bucket(471) }, // 49.25, 12.94 x 50.93, 14.62
    { 15120, 917 }, // 50.93, 7.905 x 52.61, 9.583
    { 15121, Bucket(485) }, // 52.61, 7.905 x 54.28, 9.583
    { 15122, 917 }, // 50.93, 9.583 x 52.61, 11.26
    { 15123, 969 }, // 52.61, 9.583 x 54.28, 11.26
    { 15127, 3550 }, // 55.96, 9.583 x 57.64, 11.26
    { 15128, Bucket(492) }, // 50.93, 11.26 x 52.61, 12.94
    { 15129, Bucket(500) }, // 52.61, 11.26 x 54.28, 12.94
    { 15130, Bucket(504) }, // 50.93, 12.94 x 52.61, 14.62
    { 15132, 287 }, // 54.28, 11.26 x 55.96, 12.94
    { 15137, Bucket(512) }, // 45.9, 14.62 x 47.57, 16.29
    { 15139, 1550 }, // 45.9, 16.29 x 47.57, 17.97
    { 15140, Bucket(518) }, // 47.57, 14.62 x 49.25, 16.29
    { 15141, Bucket(522) }, // 49.25, 14.62 x 50.93, 16.29
    { 15142, Bucket(528) }, // 47.57, 16.29 x 49.25, 17.97
    { 15145, Bucket(533) }, // 45.9, 17.97 x 47.57, 19.65
    { 15148, 2620 }, // 47.57, 17.97 x 49.25, 19.65
    { 15149, Bucket(545) }, // 49.25, 17.97 x 50.93, 19.65
    { 15154, Bucket(549) }, // 50.93, 16.29 x 52.61, 17.97
    { 15160, Bucket(552) }, // 50.93, 17.97 x 52.61, 19.65
    { 15171, 951 }, // 59.32, 9.583 x 60.99, 11.26
    { 15271, Bucket(556) }, // 49.25, 29.72 x 50.93, 31.39
    { 15299, 1995 }, // 59.32, 23 x 60.99, 24.68
    { 15305, 1995 }, // 59.32, 24.68 x 60.99, 26.36
    { 34771, Bucket(560) }, // 12.34, 76.69 x 14.02, 78.37
    { 34779, 2353 }, // 12.34, 80.05 x 14.02, 81.72
    { 36159, Bucket(563) }, // 2.275, 100.2 x 3.952, 101.9
    { 36246, Bucket(570) }, // 0.597, 103.5 x 2.275, 105.2
    { 36702, Bucket(573) }, // 14.02, 120.3 x 15.7, 122
    { 36922, 2539 }, // 24.09, 46.49 x 25.76, 48.17
    { 36944, Bucket(579) }, // 37.51, 34.75 x 39.18, 36.43
    { 37142, Bucket(584) }, // 54.28, 36.43 x 55.96, 38.1
    { 37175, 3766 }, // 55.96, 43.14 x 57.64, 44.81
    { 37276, Bucket(587) }, // 54.28, 51.53 x 55.96, 53.2
    { 37526, Bucket(594) }, // 27.44, 76.69 x 29.12, 78.37
    { 39056, Bucket(597) }, // 24.09, 101.9 x 25.76, 103.5
    { 39063, Bucket(601) }, // 29.12, 103.5 x 30.8, 105.2
    { 39065, Bucket(604) }, // 25.76, 105.2 x 27.44, 106.9
    { 39085, Bucket(607) }, // 22.41, 111.9 x 24.09, 113.6
    { 39100, Bucket(610) }, // 27.44, 111.9 x 29.12, 113.6
    { 39103, Bucket(614) }, // 29.12, 113.6 x 30.8, 115.3
    { 39162, Bucket(617) }, // 37.51, 113.6 x 39.18, 115.3
    { 39449, 3507 }, // 25.76, 118.6 x 27.44, 120.3
    { 39453, 3329 }, // 29.12, 118.6 x 30.8, 120.3
    { 39455, 3245 }, // 29.12, 120.3 x 30.8, 122
    { 39493, Bucket(620) }, // 35.83, 115.3 x 37.51, 117
    { 39495, 2434 }, // 35.83, 117 x 37.51, 118.6
    { 39496, 2646 }, // 30.8, 118.6 x 32.47, 120.3
    { 39498, Bucket(623) }, // 30.8, 120.3 x 32.47, 122
    { 39505, Bucket(626) }, // 39.18, 115.3 x 40.86, 117
    { 39514, 2283 }, // 37.51, 120.3 x 39.18, 122
    { 39540, Bucket(636) }, // 40.86, 122 x 42.54, 123.7
    { 39652, 2858 }, // 34.15, 135.4 x 35.83, 137.1
    { 39660, Bucket(639) }, // 34.15, 138.8 x 35.83, 140.4
    { 39661, 3200 }, // 35.83, 138.8 x 37.51, 140.4
    { 39679, 2312 }, // 42.54, 140.4 x 44.22, 142.1
    { 41819, 1675 }, // -41.35, 174 x -39.67, 175.7
    { 41823, 10 }, // -37.99, 174 x -36.31, 175.7
    { 42019, Bucket(647) }, // -34.64, 150.5 x -32.96, 152.2
    { 42041, Bucket(652) }, // -27.92, 152.2 x -26.25, 153.9
    { 12287, 1838 }, // -37.15, -73.46 x -36.31, -72.63
    { 16292, 535 }, // 5.63, -75.98 x 6.469, -75.14
    { 24887, 2682 }, // 36.67, -122.1 x 37.51, -121.3
    { 24928, 1089 }, // 37.51, -123 x 38.35, -122.1
    { 24967, Bucket(657) }, // 33.31, -118.8 x 34.15, -117.9
    { 24972, Bucket(663) }, // 32.47, -117.9 x 33.31, -117.1
    { 24978, Bucket(676) }, // 34.15, -118.8 x 34.99, -117.9
    { 25542, Bucket(679) }, // 39.18, -105.3 x 40.02, -104.5
    { 25633, Bucket(687) }, // 45.06, -123 x 45.9, -122.1
    { 25637, 2836 }, // 46.73, -123 x 47.57, -122.1
    { 25789, 2754 }, // 50.09, -114.6 x 50.93, -113.7
    { 25832, Bucket(692) }, // 50.93, -114.6 x 51.77, -113.7
    { 26628, Bucket(695) }, // 19.05, -99.47 x 19.89, -98.63
    { 26711, 2981 }, // 29.96, -98.63 x 30.8, -97.79
    { 26717, Bucket(703) }, // 29.96, -97.79 x 30.8, -96.95
    { 26892, 2986 }, // 32.47, -97.79 x 33.31, -96.95
    { 26894, Bucket(706) }, // 32.47, -96.95 x 33.31, -96.11
    { 27399, Bucket(710) }, // 33.31, -85.21 x 34.15, -84.37
    { 27405, Bucket(710) }, // 33.31, -84.37 x 34.15, -83.53
    { 27503, Bucket(713) }, // 40.02, -80.18 x 40.86, -79.34
    { 27519, Bucket(717) }, // 43.38, -80.18 x 44.22, -79.34
    { 27593, Bucket(723) }, // 38.35, -77.66 x 39.18, -76.82
    { 27605, Bucket(727) }, // 43.38, -79.34 x 44.22, -78.5
    { 27620, 2918 }, // 39.18, -75.98 x 40.02, -75.14
    { 27629, Bucket(731) }, // 40.02, -74.3 x 40.86, -73.46
    { 27640, Bucket(757) }, // 40.86, -74.3 x 41.7, -73.46
    { 27690, 2517 }, // 44.22, -93.6 x 45.06, -92.76
    { 28329, Bucket(764) }, // 45.06, -74.3 x 45.9, -73.46
    { 28331, 3686 }, // 45.06, -73.46 x 45.9, -72.63
    { 36877, Bucket(771) }, // -33.8, -70.95 x -32.96, -70.11
    { 36901, 1249 }, // -33.8, -69.27 x -32.96, -68.43
    { 36912, 1249 }, // -32.96, -69.27 x -32.12, -68.43
    { 37049, 3377 }, // -32.12, -60.88 x -31.28, -60.04
    { 37182, 3510 }, // -17.86, -66.75 x -17.02, -65.91
    { 37377, 1275 }, // -35.47, -59.2 x -34.64, -58.37
    { 37380, Bucket(774) }, // -34.64, -59.2 x -33.8, -58.37
    { 37527, 1597 }, // -30.44, -51.65 x -29.6, -50.82
    { 40084, 2823 }, // -4.436, -39.07 x -3.597, -38.23
    { 40097, 1450 }, // -8.631, -35.72 x -7.792, -34.88
    { 40112, 2791 }, // -6.114, -35.72 x -5.275, -34.88
    { 47663, 2887 }, // -33.8, 27.2 x -32.96, 28.04
    { 47674, 2887 }, // -32.96, 27.2 x -32.12, 28.04
    { 47727, Bucket(778) }, // -27.09, 27.2 x -26.25, 28.04
    { 47738, 3017 }, // -26.25, 27.2 x -25.41, 28.04
    { 47775, Bucket(781) }, // -30.44, 30.55 x -29.6, 31.39
    { 47813, 3016 }, // -27.09, 28.04 x -26.25, 28.88
    { 49491, 1426 }, // 41.7, -71.79 x 42.54, -70.95
    { 57767, Bucket(788) }, // 33.31, -8.034 x 34.15, -7.195
    { 57773, 1584 }, // 33.31, -7.195 x 34.15, -6.356
    { 57791, Bucket(792) }, // 36.67, -6.356 x 37.51, -5.517
    { 57803, Bucket(795) }, // 38.35, -9.711 x 39.18, -8.872
    { 57825, Bucket(807) }, // 38.35, -8.872 x 39.18, -8.034
    { 57829, 3147 }, // 40.02, -8.872 x 40.86, -8.034
    { 57834, Bucket(812) }, // 37.51, -6.356 x 38.35, -5.517
    { 57840, Bucket(815) }, // 40.86, -8.872 x 41.7, -8.034
    { 57855, 1911 }, // 43.38, -6.356 x 44.22, -5.517
    { 58189, Bucket(820) }, // 40.02, -3.839 x 40.86, -3
    { 58210, 1198 }, // 37.51, -1.323 x 38.35, -0.4838
    { 58214, Bucket(831) }, // 39.18, -1.323 x 40.02, -0.4838
    { 58217, 3591 }, // 38.35, -0.4838 x 39.18, 0.3551
    { 58220, Bucket(834) }, // 39.18, -0.4838 x 40.02, 0.3551
    { 58226, 587 }, // 40.86, -1.323 x 41.7, -0.4838
    { 58227, 587 }, // 41.7, -1.323 x 42.54, -0.4838
    { 58234, Bucket(837) }, // 40.86, 0.3551 x 41.7, 1.194
    { 58310, 3197 }, // 39.18, 2.033 x 40.02, 2.872
    { 58316, 3197 }, // 39.18, 2.872 x 40.02, 3.711
    { 58618, Bucket(840) }, // 54.28, -6.356 x 55.12, -5.517
    { 58957, Bucket(843) }, // 53.45, -3.839 x 54.28, -3
    { 58982, 268 }, // 52.61, -1.323 x 53.45, -0.4838
    { 58984, Bucket(846) }, // 50.93, -0.4838 x 51.77, 0.3551
    { 59027, Bucket(861) }, // 48.41, 2.033 x 49.25, 2.872
    { 59039, Bucket(879) }, // 50.09, 3.711 x 50.93, 4.549
    { 59041, Bucket(890) }, // 45.06, 4.549 x 45.9, 5.388
    { 59043, Bucket(893) }, // 45.06, 5.388 x 45.9, 6.227
    { 59046, 2922 }, // 45.9, 5.388 x 46.73, 6.227
    { 59051, 466 }, // 45.06, 7.066 x 45.9, 7.905
    { 59052, Bucket(896) }, // 45.9, 6.227 x 46.73, 7.066
    { 59055, Bucket(901) }, // 46.73, 7.066 x 47.57, 7.905
    { 59061, Bucket(917) }, // 50.09, 4.549 x 50.93, 5.388
    { 59063, Bucket(920) }, // 50.09, 5.388 x 50.93, 6.227
    { 59066, Bucket(923) }, // 47.57, 7.066 x 48.41, 7.905
    { 59082, Bucket(928) }, // 50.93, 3.711 x 51.77, 4.549
    { 59083, 1702 }, // 51.77, 3.711 x 52.61, 4.549
    { 59104, 3894 }, // 50.93, 4.549 x 51.77, 5.388
    { 59105, Bucket(936) }, // 51.77, 4.549 x 52.61, 5.388
    { 59112, Bucket(942) }, // 50.93, 6.227 x 51.77, 7.066
    { 59114, Bucket(948) }, // 50.93, 7.066 x 51.77, 7.905
    { 59752, 3355 }, // 37.51, 12.94 x 38.35, 13.78
    { 59759, Bucket(954) }, // 40.02, 13.78 x 40.86, 14.62
    { 59763, Bucket(958) }, // 41.7, 12.1 x 42.54, 12.94
    { 59770, Bucket(965) }, // 40.86, 13.78 x 41.7, 14.62
    { 59864, 1160 }, // 40.86, 16.29 x 41.7, 17.13
    { 59893, Bucket(968) }, // 43.38, 17.97 x 44.22, 18.81
    { 60232, Bucket(973) }, // 37.51, 23 x 38.35, 23.84
    { 60331, 3703 }, // 31.63, 33.91 x 32.47, 34.75
    { 60370, 2035 }, // 40.86, 28.88 x 41.7, 29.72
    { 60390, Bucket(976) }, // 39.18, 32.23 x 40.02, 33.07
    { 60419, Bucket(979) }, // 45.06, 8.744 x 45.9, 9.583
    { 60420, 2130 }, // 45.9, 7.905 x 46.73, 8.744
    { 60421, Bucket(999) }, // 46.73, 7.905 x 47.57, 8.744
    { 60422, 3516 }, // 45.9, 8.744 x 46.73, 9.583
    { 60423, Bucket(1014) }, // 46.73, 8.744 x 47.57, 9.583
    { 60425, Bucket(1021) }, // 45.06, 9.583 x 45.9, 10.42
    { 60426, Bucket(1024) }, // 44.22, 10.42 x 45.06, 11.26
    { 60429, Bucket(1027) }, // 46.73, 9.583 x 47.57, 10.42
    { 60432, Bucket(1030) }, // 47.57, 7.905 x 48.41, 8.744
    { 60433, Bucket(1035) }, // 48.41, 7.905 x 49.25, 8.744
    { 60434, Bucket(1046) }, // 47.57, 8.744 x 48.41, 9.583
    { 60435, Bucket(1050) }, // 48.41, 8.744 x 49.25, 9.583
    { 60436, 959 }, // 49.25, 7.905 x 50.09, 8.744
    { 60437, Bucket(1073) }, // 50.09, 7.905 x 50.93, 8.744
    { 60438, Bucket(1078) }, // 49.25, 8.744 x 50.09, 9.583
    { 60442, 354 }, // 47.57, 10.42 x 48.41, 11.26
    { 60443, Bucket(1081) }, // 48.41, 10.42 x 49.25, 11.26
    { 60444, 256 }, // 49.25, 9.583 x 50.09, 10.42
    { 60446, Bucket(1084) }, // 49.25, 10.42 x 50.09, 11.26
    { 60447, 3300 }, // 50.09, 10.42 x 50.93, 11.26
    { 60448, Bucket(1089) }, // 44.22, 11.26 x 45.06, 12.1
    { 60453, Bucket(1095) }, // 46.73, 11.26 x 47.57, 12.1
    { 60464, Bucket(1098) }, // 47.57, 11.26 x 48.41, 12.1
    { 60465, 3246 }, // 48.41, 11.26 x 49.25, 12.1
    { 60467, 2451 }, // 48.41, 12.1 x 49.25, 12.94
    { 60468, Bucket(1109) }, // 49.25, 11.26 x 50.09, 12.1
    { 60474, Bucket(1112) }, // 47.57, 13.78 x 48.41, 14.62
    { 60476, 1266 }, // 49.25, 12.94 x 50.09, 13.78
    { 60477, Bucket(1116) }, // 50.09, 12.94 x 50.93, 13.78
    { 60478, Bucket(1121) }, // 49.25, 13.78 x 50.09, 14.62
    { 60483, 938 }, // 51.77, 8.744 x 52.61, 9.583
    { 60489, Bucket(1125) }, // 51.77, 9.583 x 52.61, 10.42
    { 60492, Bucket(1127) }, // 52.61, 9.583 x 53.45, 10.42
    { 60493, Bucket(1130) }, // 53.45, 9.583 x 54.28, 10.42
    { 60512, Bucket(1139) }, // 50.93, 11.26 x 51.77, 12.1
    { 60513, Bucket(1142) }, // 51.77, 11.26 x 52.61, 12.1
    { 60514, Bucket(1146) }, // 50.93, 12.1 x 51.77, 12.94
    { 60515, 2040 }, // 51.77, 12.1 x 52.61, 12.94
    { 60516, 158 }, // 52.61, 11.26 x 53.45, 12.1
    { 60521, Bucket(1156) }, // 51.77, 12.94 x 52.61, 13.78
    { 60522, 1733 }, // 50.93, 13.78 x 51.77, 14.62
    { 60524, Bucket(1182) }, // 52.61, 12.94 x 53.45, 13.78
    { 60526, 2010 }, // 52.61, 13.78 x 53.45, 14.62
    { 60531, Bucket(1189) }, // 55.12, 12.1 x 55.96, 12.94
    { 60547, 3717 }, // 45.06, 15.45 x 45.9, 16.29
    { 60549, Bucket(1197) }, // 46.73, 14.62 x 47.57, 15.45
    { 60550, 198 }, // 45.9, 15.45 x 46.73, 16.29
    { 60551, Bucket(1200) }, // 46.73, 15.45 x 47.57, 16.29
    { 60564, 3828 }, // 49.25, 14.62 x 50.09, 15.45
    { 60568, 1037 }, // 47.57, 16.29 x 48.41, 17.13
    { 60573, Bucket(1203) }, // 50.09, 16.29 x 50.93, 17.13
    { 60574, Bucket(1207) }, // 49.25, 17.13 x 50.09, 17.97
    { 60581, 1536 }, // 46.73, 17.97 x 47.57, 18.81
    { 60583, Bucket(1211) }, // 46.73, 18.81 x 47.57, 19.65
    { 60588, 3313 }, // 45.9, 19.65 x 46.73, 20.49
    { 60589, Bucket(1216) }, // 46.73, 19.65 x 47.57, 20.49
    { 60592, Bucket(1220) }, // 47.57, 17.97 x 48.41, 18.81
    { 60594, Bucket(1223) }, // 47.57, 18.81 x 48.41, 19.65
    { 60596, Bucket(1227) }, // 49.25, 17.97 x 50.09, 18.81
    { 60599, Bucket(1235) }, // 50.09, 18.81 x 50.93, 19.65
    { 60600, 1538 }, // 47.57, 19.65 x 48.41, 20.49
    { 60604, Bucket(1239) }, // 49.25, 19.65 x 50.09, 20.49
    { 60605, 1174 }, // 50.09, 19.65 x 50.93, 20.49
    { 60609, 1867 }, // 51.77, 14.62 x 52.61, 15.45
    { 60610, 3690 }, // 50.93, 15.45 x 51.77, 16.29
    { 60616, Bucket(1242) }, // 50.93, 16.29 x 51.77, 17.13
    { 60651, Bucket(1247) }, // 51.77, 20.49 x 52.61, 21.33
    { 60686, Bucket(1265) }, // 59.32, 10.42 x 60.16, 11.26
    { 60811, 321 }, // 58.48, 17.13 x 59.32, 17.97
    { 60933, 2327 }, // 46.73, 21.33 x 47.57, 22.17
    { 60975, Bucket(1271) }, // 46.73, 27.2 x 47.57, 28.04
    { 60994, 3669 }, // 50.93, 22.17 x 51.77, 23
    { 61039, Bucket(1277) }, // 53.45, 27.2 x 54.28, 28.04
    { 61085, Bucket(1285) }, // 50.09, 29.72 x 50.93, 30.55
    { 61112, Bucket(1288) }, // 47.57, 33.07 x 48.41, 33.91
    { 61123, Bucket(1292) }, // 51.77, 28.88 x 52.61, 29.72
    { 61145, Bucket(1295) }, // 55.12, 29.72 x 55.96, 30.55
    { 61221, Bucket(1299) }, // 60.16, 24.68 x 60.99, 25.52
    { 61324, Bucket(1302) }, // 59.32, 29.72 x 60.16, 30.55
    { 136265, Bucket(1305) }, // -1.92, 36.43 x -1.081, 37.26
    { 139110, 491 }, // 12.34, 79.21 x 13.18, 80.05
    { 144855, Bucket(1309) }, // 16.54, 95.99 x 17.37, 96.82
    { 144877, Bucket(1312) }, // 13.18, 100.2 x 14.02, 101
    { 144984, Bucket(1315) }, // 0.597, 103.5 x 1.436, 104.4
    { 146059, Bucket(1319) }, // -35.47, 137.9 x -34.64, 138.8
    { 146887, Bucket(1322) }, // 13.18, 122.8 x 14.02, 123.7
    { 147713, 3703 }, // 31.63, 34.75 x 32.47, 35.59
    { 147743, 3541 }, // 36.67, 37.26 x 37.51, 38.1
    { 147794, 3594 }, // 40.86, 35.59 x 41.7, 36.43
    { 147800, 3594 }, // 40.86, 36.43 x 41.7, 37.26
    { 148043, 2638 }, // 24.92, 50.69 x 25.76, 51.53
    { 148065, 2638 }, // 24.92, 51.53 x 25.76, 52.36
    { 148161, Bucket(1325) }, // 24.92, 54.88 x 25.76, 55.72
    { 148251, 2082 }, // 34.99, 50.69 x 35.83, 51.53
    { 148406, 390 }, // 35.83, 59.08 x 36.67, 59.91
    { 148495, Bucket(1328) }, // 46.73, 37.26 x 47.57, 38.1
    { 148571, Bucket(1333) }, // 55.12, 37.26 x 55.96, 38.1
    { 149068, 2871 }, // 52.61, 49.85 x 53.45, 50.69
    { 149970, Bucket(1355) }, // 40.86, 69.14 x 41.7, 69.98
    { 150064, Bucket(1358) }, // 20.73, 78.37 x 21.57, 79.21
    { 150105, Bucket(1361) }, // 28.28, 76.69 x 29.12, 77.53
    { 150525, 2525 }, // 43.38, 86.76 x 44.22, 87.6
    { 150527, 2525 }, // 43.38, 87.6 x 44.22, 88.44
    { 156222, Bucket(1369) }, // 22.41, 107.7 x 23.25, 108.6
    { 156253, Bucket(1374) }, // 29.96, 103.5 x 30.8, 104.4
    { 156278, Bucket(1380) }, // 29.12, 106.1 x 29.96, 106.9
    { 156342, Bucket(1389) }, // 22.41, 112.8 x 23.25, 113.6
    { 156343, 2797 }, // 23.25, 112.8 x 24.09, 113.6
    { 156345, Bucket(1396) }, // 21.57, 113.6 x 22.41, 114.4
    { 156348, Bucket(1400) }, // 22.41, 113.6 x 23.25, 114.4
    { 156402, 3491 }, // 27.44, 112.8 x 28.28, 113.6
    { 156413, Bucket(1408) }, // 29.96, 113.6 x 30.8, 114.4
    { 156424, Bucket(1412) }, // 30.8, 103.5 x 31.63, 104.4
    { 156549, Bucket(1416) }, // 33.31, 108.6 x 34.15, 109.4
    { 156560, Bucket(1419) }, // 34.15, 108.6 x 34.99, 109.4
    { 156592, 3335 }, // 34.15, 111.9 x 34.99, 112.8
    { 156600, Bucket(1427) }, // 34.15, 113.6 x 34.99, 114.4
    { 157770, Bucket(1430) }, // 24.09, 117.8 x 24.92, 118.6
    { 157777, Bucket(1434) }, // 28.28, 115.3 x 29.12, 116.1
    { 157803, Bucket(1437) }, // 24.92, 121.2 x 25.76, 122
    { 157815, Bucket(1442) }, // 29.96, 119.5 x 30.8, 120.3
    { 157816, Bucket(1447) }, // 27.44, 120.3 x 28.28, 121.2
    { 157822, Bucket(1450) }, // 29.12, 121.2 x 29.96, 122
    { 157961, Bucket(1455) }, // 31.63, 117 x 32.47, 117.8
    { 157963, 1245 }, // 31.63, 117.8 x 32.47, 118.6
    { 157985, Bucket(1458) }, // 31.63, 118.6 x 32.47, 119.5
    { 157989, 3307 }, // 33.31, 118.6 x 34.15, 119.5
    { 157992, Bucket(1464) }, // 30.8, 120.3 x 31.63, 121.2
    { 157993, 3780 }, // 31.63, 120.3 x 32.47, 121.2
    { 157994, Bucket(1468) }, // 30.8, 121.2 x 31.63, 122
    { 158012, 2923 }, // 35.83, 120.3 x 36.67, 121.2
    { 158022, Bucket(1484) }, // 39.18, 116.1 x 40.02, 117
    { 158025, Bucket(1494) }, // 38.35, 117 x 39.18, 117.8
    { 158028, 2486 }, // 39.18, 117 x 40.02, 117.8
    { 158059, Bucket(1497) }, // 38.35, 121.2 x 39.18, 122
    { 158135, Bucket(1500) }, // 36.67, 126.2 x 37.51, 127
    { 158140, 2123 }, // 35.83, 127 x 36.67, 127.9
    { 158141, Bucket(1504) }, // 36.67, 127 x 37.51, 127.9
    { 158163, 2222 }, // 41.7, 122.8 x 42.54, 123.7
    { 158175, Bucket(1507) }, // 43.38, 124.5 x 44.22, 125.3
    { 158177, 2080 }, // 38.35, 125.3 x 39.18, 126.2
    { 158178, Bucket(1500) }, // 37.51, 126.2 x 38.35, 127
    { 158184, Bucket(1512) }, // 37.51, 127 x 38.35, 127.9
    { 158197, Bucket(1508) }, // 43.38, 125.3 x 44.22, 126.2
    { 158481, Bucket(1515) }, // 34.99, 128.7 x 35.83, 129.5
    { 158512, 3860 }, // 34.15, 132.1 x 34.99, 132.9
    { 158520, Bucket(1518) }, // 34.15, 133.7 x 34.99, 134.6
    { 158608, Bucket(1521) }, // 34.15, 135.4 x 34.99, 136.3
    { 158643, Bucket(1524) }, // 34.99, 139.6 x 35.83, 140.4
    { 158646, 2456 }, // 35.83, 139.6 x 36.67, 140.4
    { 158696, 2046 }, // 37.51, 140.4 x 38.35, 141.3
    { 158718, 3210 }, // 42.54, 141.3 x 43.38, 142.1
    { 158883, Bucket(1529) }, // 45.06, 126.2 x 45.9, 127
    { 165214, Bucket(1532) }, // -37.99, 144.6 x -37.15, 145.5
    { 168076, Bucket(1542) }, // -34.64, 150.5 x -33.8, 151.4
    { 168164, Bucket(1546) }, // -27.92, 152.2 x -27.09, 153
    { 49148, 1837 }, // -37.15, -73.46 x -36.73, -73.05
    { 64751, 2026 }, // 8.566, -79.76 x 8.986, -79.34
    { 64762, 2026 }, // 8.986, -79.76 x 9.405, -79.34
    { 99549, Bucket(1549) }, // 37.09, -122.1 x 37.51, -121.7
    { 99714, Bucket(1553) }, // 37.51, -122.5 x 37.93, -122.1
    { 99721, 2409 }, // 37.93, -122.1 x 38.35, -121.7
    { 99726, Bucket(1556) }, // 38.35, -121.7 x 38.77, -121.3
    { 99748, 2572 }, // 38.35, -121.3 x 38.77, -120.9
    { 99891, 3291 }, // 32.89, -117.5 x 33.31, -117.1
    { 101661, Bucket(1559) }, // 40.44, -112.1 x 40.86, -111.6
    { 102169, Bucket(1562) }, // 39.6, -105.3 x 40.02, -104.9
    { 102511, 1693 }, // 48.83, -123.4 x 49.25, -123
    { 102522, 1693 }, // 49.25, -123.4 x 49.67, -123
    { 102533, 208 }, // 45.48, -123 x 45.9, -122.5
    { 102551, 1605 }, // 47.15, -122.5 x 47.57, -122.1
    { 102594, Bucket(1567) }, // 47.57, -122.5 x 47.99, -122.1
    { 103356, Bucket(1571) }, // 53.45, -113.7 x 53.86, -113.3
    { 106512, 1343 }, // 19.05, -99.47 x 19.47, -99.05
    { 106963, Bucket(1574) }, // 29.54, -95.69 x 29.96, -95.28
    { 108494, 1030 }, // 41.7, -88.14 x 42.12, -87.73
    { 108516, Bucket(1578) }, // 41.7, -87.73 x 42.12, -87.31
    { 108753, 1429 }, // 22.83, -82.69 x 23.25, -82.27
    { 109796, 2829 }, // 34.99, -81.01 x 35.41, -80.59
    { 110025, Bucket(1583) }, // 41.28, -81.85 x 41.7, -81.43
    { 110078, 2994 }, // 43.38, -79.76 x 43.8, -79.34
    { 110206, 1518 }, // 36.67, -76.4 x 37.09, -75.98
    { 110375, Bucket(1587) }, // 38.77, -77.24 x 39.18, -76.82
    { 110392, Bucket(1592) }, // 39.18, -76.82 x 39.6, -76.4
    { 110483, Bucket(1595) }, // 39.6, -75.56 x 40.02, -75.14
    { 110486, 2282 }, // 40.02, -75.56 x 40.44, -75.14
    { 110517, Bucket(1599) }, // 40.44, -74.3 x 40.86, -73.88
    { 110519, 2789 }, // 40.44, -73.88 x 40.86, -73.46
    { 110560, Bucket(1612) }, // 40.86, -74.3 x 41.28, -73.88
    { 112810, 3001 }, // 44.22, -79.76 x 44.64, -79.34
    { 113319, 2593 }, // 45.48, -73.88 x 45.9, -73.46
    { 136649, 1577 }, // -39.25, -68.43 x -38.83, -68.01
    { 147508, Bucket(1616) }, // -33.8, -70.95 x -33.38, -70.53
    { 148730, 3511 }, // -17.86, -66.33 x -17.44, -65.91
    { 148731, 3511 }, // -17.44, -66.33 x -17.02, -65.91
    { 149522, Bucket(1621) }, // -34.64, -58.78 x -34.22, -58.37
    { 149777, 576 }, // -27.5, -59.2 x -27.09, -58.78
    { 150518, Bucket(1624) }, // -23.73, -47.04 x -23.31, -46.62
    { 150524, Bucket(1628) }, // -23.73, -46.62 x -23.31, -46.2
    { 151432, 2060 }, // -16.18, -48.3 x -15.76, -47.88
    { 152823, Bucket(1632) }, // 10.24, -67.17 x 10.66, -66.75
    { 156712, 2821 }, // -22.89, -43.27 x -22.47, -42.85
    { 157463, Bucket(1636) }, // -13.24, -38.65 x -12.82, -38.23
    { 160339, 1732 }, // -4.017, -38.65 x -3.597, -38.23
    { 160450, 3589 }, // -6.114, -35.3 x -5.694, -34.88
    { 188152, 2472 }, // 8.986, 7.066 x 9.405, 7.485
    { 189075, Bucket(1639) }, // -34.22, 18.39 x -33.8, 18.81
    { 190954, 3016 }, // -26.25, 27.62 x -25.83, 28.04
    { 196652, 2062 }, // 18.21, -70.11 x 18.63, -69.69
    { 196782, 1513 }, // 18.21, -66.33 x 18.63, -65.91
    { 197967, Bucket(1643) }, // 42.12, -71.37 x 42.54, -70.95
    { 197978, 2960 }, // 42.54, -71.37 x 42.96, -70.95
    { 197989, 2956 }, // 42.12, -70.95 x 42.54, -70.53
    { 231161, Bucket(1653) }, // 36.25, -6.356 x 36.67, -5.936
    { 231164, 3130 }, // 36.67, -6.356 x 37.09, -5.936
    { 231165, Bucket(1656) }, // 37.09, -6.356 x 37.51, -5.936
    { 231167, 3106 }, // 37.09, -5.936 x 37.51, -5.517
    { 231214, Bucket(1659) }, // 38.35, -9.292 x 38.77, -8.872
    { 231300, Bucket(1659) }, // 38.35, -8.872 x 38.77, -8.453
    { 231317, 2300 }, // 40.44, -8.872 x 40.86, -8.453
    { 231360, Bucket(1664) }, // 40.86, -8.872 x 41.28, -8.453
    { 231419, Bucket(1671) }, // 42.96, -5.936 x 43.38, -5.517
    { 232540, 2102 }, // 36.67, -4.678 x 37.09, -4.259
    { 232565, 1888 }, // 37.09, -3.839 x 37.51, -3.42
    { 232735, 2557 }, // 40.44, -4.259 x 40.86, -3.839
    { 232757, 2147 }, // 40.44, -3.839 x 40.86, -3.42
    { 232817, 3185 }, // 42.96, -3.839 x 43.38, -3.42
    { 232827, 2849 }, // 42.96, -2.581 x 43.38, -2.162
    { 232868, 283 }, // 38.35, -0.4838 x 38.77, -0.06436
    { 232869, 1710 }, // 38.77, -0.4838 x 39.18, -0.06436
    { 232880, 1710 }, // 39.18, -0.4838 x 39.6, -0.06436
    { 232913, Bucket(1674) }, // 42.96, -2.162 x 43.38, -1.742
    { 232938, 1689 }, // 40.86, 0.7745 x 41.28, 1.194
    { 233076, 1988 }, // 36.67, 2.872 x 37.09, 3.291
    { 233242, Bucket(1678) }, // 39.18, 2.452 x 39.6, 2.872
    { 233243, Bucket(1678) }, // 39.6, 2.452 x 40.02, 2.872
    { 233280, 1689 }, // 40.86, 1.194 x 41.28, 1.613
    { 233289, Bucket(1681) }, // 41.28, 2.033 x 41.7, 2.452
    { 233300, Bucket(1685) }, // 43.38, 1.194 x 43.8, 1.613
    { 233317, Bucket(1690) }, // 42.12, 2.872 x 42.54, 3.291
    { 233328, Bucket(1690) }, // 42.54, 2.872 x 42.96, 3.291
    { 233340, Bucket(1694) }, // 43.38, 3.711 x 43.8, 4.13
    { 233468, 3226 }, // 43.38, 7.066 x 43.8, 7.485
    { 234425, 1859 }, // 53.03, -6.356 x 53.45, -5.936
    { 235593, 2953 }, // 47.99, -4.678 x 48.41, -4.259
    { 235596, 2953 }, // 48.41, -4.678 x 48.83, -4.259
    { 235659, Bucket(1698) }, // 44.64, -0.9032 x 45.06, -0.4838
    { 235671, Bucket(1703) }, // 47.15, -1.742 x 47.57, -1.323
    { 235709, 1187 }, // 47.15, 0.3551 x 47.57, 0.7745
    { 235714, 1357 }, // 47.57, -1.742 x 47.99, -1.323
    { 235762, 1291 }, // 49.25, -0.06436 x 49.67, 0.3551
    { 235811, 265 }, // 51.35, -3.42 x 51.77, -3
    { 235909, 259 }, // 52.19, -2.162 x 52.61, -1.742
    { 235937, Bucket(1706) }, // 51.35, -0.4838 x 51.77, -0.06436
    { 235971, Bucket(1711) }, // 54.7, -1.742 x 55.12, -1.323
    { 236108, Bucket(1714) }, // 48.41, 2.033 x 48.83, 2.452
    { 236109, Bucket(1718) }, // 48.83, 2.033 x 49.25, 2.452
    { 236149, Bucket(1721) }, // 50.51, 2.872 x 50.93, 3.291
    { 236150, 1984 }, // 50.09, 3.291 x 50.51, 3.711
    { 236158, Bucket(1726) }, // 50.09, 4.13 x 50.51, 4.549
    { 236159, Bucket(1729) }, // 50.51, 4.13 x 50.93, 4.549
    { 236165, 459 }, // 45.48, 4.549 x 45.9, 4.969
    { 236183, 674 }, // 47.15, 4.969 x 47.57, 5.388
    { 236186, Bucket(1747) }, // 45.9, 5.808 x 46.31, 6.227
    { 236191, Bucket(1750) }, // 47.15, 5.808 x 47.57, 6.227
    { 236203, Bucket(1753) }, // 44.64, 7.485 x 45.06, 7.905
    { 236206, Bucket(1756) }, // 45.06, 7.485 x 45.48, 7.905
    { 236209, 3282 }, // 46.31, 6.227 x 46.73, 6.647
    { 236214, 3046 }, // 46.73, 6.647 x 47.15, 7.066
    { 236220, Bucket(1762) }, // 46.73, 7.066 x 47.15, 7.485
    { 236221, 2860 }, // 47.15, 7.066 x 47.57, 7.485
    { 236222, Bucket(1775) }, // 46.73, 7.485 x 47.15, 7.905
    { 236223, Bucket(1783) }, // 47.15, 7.485 x 47.57, 7.905
    { 236245, Bucket(1791) }, // 50.51, 4.549 x 50.93, 4.969
    { 236253, 1817 }, // 50.51, 5.388 x 50.93, 5.808
    { 236264, Bucket(1795) }, // 47.57, 7.066 x 47.99, 7.485
    { 236266, Bucket(1798) }, // 47.57, 7.485 x 47.99, 7.905
    { 236267, 160 }, // 47.99, 7.485 x 48.41, 7.905
    { 236270, Bucket(1801) }, // 48.41, 7.485 x 48.83, 7.905
    { 236279, Bucket(1805) }, // 50.51, 6.647 x 50.93, 7.066
    { 236282, Bucket(1809) }, // 49.25, 7.485 x 49.67, 7.905
    { 236285, Bucket(1812) }, // 50.51, 7.066 x 50.93, 7.485
    { 236330, Bucket(1818) }, // 50.93, 4.13 x 51.35, 4.549
    { 236334, Bucket(1821) }, // 51.77, 4.13 x 52.19, 4.549
    { 236420, 1702 }, // 51.77, 4.549 x 52.19, 4.969
    { 236421, 2473 }, // 52.19, 4.549 x 52.61, 4.969
    { 236422, Bucket(1831) }, // 51.77, 4.969 x 52.19, 5.388
    { 236450, Bucket(1835) }, // 50.93, 6.647 x 51.35, 7.066
    { 236451, Bucket(1839) }, // 51.35, 6.647 x 51.77, 7.066
    { 236457, Bucket(1843) }, // 51.35, 7.066 x 51.77, 7.485
    { 237206, Bucket(1849) }, // 60.16, 4.969 x 60.58, 5.388
    { 238710, Bucket(1852) }, // 36.67, 10 x 37.09, 10.42
    { 238975, 1627 }, // 43.8, 10.84 x 44.22, 11.26
    { 239039, Bucket(1856) }, // 40.44, 14.2 x 40.86, 14.62
    { 239052, Bucket(1863) }, // 41.7, 12.1 x 42.12, 12.52
    { 239054, 3421 }, // 41.7, 12.52 x 42.12, 12.94
    { 239082, Bucket(1866) }, // 40.86, 14.2 x 41.28, 14.62
    { 239424, 3674 }, // 40.86, 14.62 x 41.28, 15.04
    { 241008, Bucket(1870) }, // 42.54, 23 x 42.96, 23.42
    { 241276, Bucket(1873) }, // 36.67, 30.55 x 37.09, 30.97
    { 241436, 2180 }, // 40.02, 28.88 x 40.44, 29.3
    { 241474, Bucket(1876) }, // 40.86, 28.46 x 41.28, 28.88
    { 241480, Bucket(1880) }, // 40.86, 28.88 x 41.28, 29.3
    { 241563, Bucket(1890) }, // 39.6, 32.65 x 40.02, 33.07
    { 241672, 1025 }, // 44.22, 8.744 x 44.64, 9.163
    { 241677, Bucket(1893) }, // 45.48, 8.744 x 45.9, 9.163
    { 241679, Bucket(1897) }, // 45.48, 9.163 x 45.9, 9.583
    { 241682, 3517 }, // 45.9, 8.324 x 46.31, 8.744
    { 241684, Bucket(1900) }, // 46.73, 7.905 x 47.15, 8.324
    { 241685, Bucket(1906) }, // 47.15, 7.905 x 47.57, 8.324
    { 241686, Bucket(1915) }, // 46.73, 8.324 x 47.15, 8.744
    { 241687, Bucket(1919) }, // 47.15, 8.324 x 47.57, 8.744
    { 241688, Bucket(1945) }, // 45.9, 8.744 x 46.31, 9.163
    { 241692, Bucket(1949) }, // 46.73, 8.744 x 47.15, 9.163
    { 241693, Bucket(1952) }, // 47.15, 8.744 x 47.57, 9.163
    { 241694, Bucket(1962) }, // 46.73, 9.163 x 47.15, 9.583
    { 241695, Bucket(1965) }, // 47.15, 9.163 x 47.57, 9.583
    { 241701, 3562 }, // 45.48, 9.583 x 45.9, 10
    { 241706, Bucket(1976) }, // 44.22, 10.84 x 44.64, 11.26
    { 241717, Bucket(1980) }, // 47.15, 9.583 x 47.57, 10
    { 241727, Bucket(1984) }, // 47.15, 10.84 x 47.57, 11.26
    { 241728, 1906 }, // 47.57, 7.905 x 47.99, 8.324
    { 241729, 1906 }, // 47.99, 7.905 x 48.41, 8.324
    { 241730, Bucket(1988) }, // 47.57, 8.324 x 47.99, 8.744
    { 241733, 1408 }, // 48.83, 7.905 x 49.25, 8.324
    { 241735, Bucket(1991) }, // 48.83, 8.324 x 49.25, 8.744
    { 241736, 580 }, // 47.57, 8.744 x 47.99, 9.163
    { 241742, 197 }, // 48.41, 9.163 x 48.83, 9.583
    { 241744, Bucket(2000) }, // 49.25, 7.905 x 49.67, 8.324
    { 241746, Bucket(2006) }, // 49.25, 8.324 x 49.67, 8.744
    { 241747, Bucket(2025) }, // 49.67, 8.324 x 50.09, 8.744
    { 241750, Bucket(2035) }, // 50.09, 8.324 x 50.51, 8.744
    { 241752, Bucket(1808) }, // 49.25, 8.744 x 49.67, 9.163
    { 241754, 899 }, // 49.25, 9.163 x 49.67, 9.583
    { 241756, 698 }, // 50.09, 8.744 x 50.51, 9.163
    { 241771, Bucket(2040) }, // 47.99, 10.84 x 48.41, 11.26
    { 241775, 230 }, // 48.83, 10.84 x 49.25, 11.26
    { 241786, Bucket(2045) }, // 49.25, 10.84 x 49.67, 11.26
    { 241789, 934 }, // 50.51, 10.42 x 50.93, 10.84
    { 241792, Bucket(2054) }, // 44.22, 11.26 x 44.64, 11.68
    { 241798, 355 }, // 45.06, 11.68 x 45.48, 12.1
    { 241804, 1604 }, // 45.06, 12.1 x 45.48, 12.52
    { 241805, 1604 }, // 45.48, 12.1 x 45.9, 12.52
    { 241813, 1341 }, // 47.15, 11.26 x 47.57, 11.68
    { 241823, 2389 }, // 47.15, 12.52 x 47.57, 12.94
    { 241845, 2389 }, // 47.15, 12.94 x 47.57, 13.36
    { 241849, 3497 }, // 46.31, 13.78 x 46.73, 14.2
    { 241851, 1215 }, // 46.31, 14.2 x 46.73, 14.62
    { 241854, 1215 }, // 46.73, 14.2 x 47.15, 14.62
    { 241855, 2702 }, // 47.15, 14.2 x 47.57, 14.62
    { 241856, 3181 }, // 47.57, 11.26 x 47.99, 11.68
    { 241857, Bucket(2057) }, // 47.99, 11.26 x 48.41, 11.68
    { 241858, 3181 }, // 47.57, 11.68 x 47.99, 12.1
    { 241859, 144 }, // 47.99, 11.68 x 48.41, 12.1
    { 241860, 1870 }, // 48.41, 11.26 x 48.83, 11.68
    { 241861, 230 }, // 48.83, 11.26 x 49.25, 11.68
    { 241862, 1870 }, // 48.41, 11.68 x 48.83, 12.1
    { 241866, Bucket(2064) }, // 47.57, 12.52 x 47.99, 12.94
    { 241872, 230 }, // 49.25, 11.26 x 49.67, 11.68
    { 241885, 849 }, // 50.51, 12.1 x 50.93, 12.52
    { 241887, Bucket(2067) }, // 50.51, 12.52 x 50.93, 12.94
    { 241888, Bucket(2063) }, // 47.57, 12.94 x 47.99, 13.36
    { 241899, Bucket(2071) }, // 47.99, 14.2 x 48.41, 14.62
    { 241909, Bucket(2068) }, // 50.51, 12.94 x 50.93, 13.36
    { 241911, 1733 }, // 50.51, 13.36 x 50.93, 13.78
    { 241915, Bucket(2074) }, // 49.67, 14.2 x 50.09, 14.62
    { 241917, 1733 }, // 50.51, 13.78 x 50.93, 14.2
    { 241918, Bucket(2097) }, // 50.09, 14.2 x 50.51, 14.62
    { 241926, Bucket(2115) }, // 51.77, 8.324 x 52.19, 8.744
    { 241935, 1040 }, // 52.19, 9.163 x 52.61, 9.583
    { 241946, 1040 }, // 52.61, 9.163 x 53.03, 9.583
    { 241957, Bucket(2119) }, // 52.19, 9.583 x 52.61, 10
    { 241960, 934 }, // 50.93, 10.42 x 51.35, 10.84
    { 241961, 152 }, // 51.35, 10.42 x 51.77, 10.84
    { 241962, Bucket(2134) }, // 50.93, 10.84 x 51.35, 11.26
    { 241972, Bucket(2138) }, // 53.45, 9.583 x 53.86, 10
    { 242034, 3553 }, // 55.96, 10 x 56.38, 10.42
    { 242056, Bucket(2141) }, // 50.93, 12.1 x 51.35, 12.52
    { 242068, Bucket(2144) }, // 53.45, 11.26 x 53.86, 11.68
    { 242071, Bucket(2148) }, // 53.86, 11.68 x 54.28, 12.1
    { 242077, Bucket(2152) }, // 53.86, 12.1 x 54.28, 12.52
    { 242082, Bucket(2157) }, // 50.93, 13.36 x 51.35, 13.78
    { 242085, Bucket(2162) }, // 52.19, 12.94 x 52.61, 13.36
    { 242087, Bucket(2171) }, // 52.19, 13.36 x 52.61, 13.78
    { 242088, Bucket(2185) }, // 50.93, 13.78 x 51.35, 14.2
    { 242096, 1231 }, // 52.61, 12.94 x 53.03, 13.36
    { 242149, 386 }, // 55.54, 12.94 x 55.96, 13.36
    { 242193, 1215 }, // 46.31, 14.62 x 46.73, 15.04
    { 242196, 1215 }, // 46.73, 14.62 x 47.15, 15.04
    { 242198, 3080 }, // 46.73, 15.04 x 47.15, 15.45
    { 242199, 227 }, // 47.15, 15.04 x 47.57, 15.45
    { 242251, Bucket(2188) }, // 47.99, 15.87 x 48.41, 16.29
    { 242257, Bucket(2094) }, // 49.67, 14.62 x 50.09, 15.04
    { 242271, 2031 }, // 50.51, 15.87 x 50.93, 16.29
    { 242273, Bucket(2193) }, // 47.99, 16.29 x 48.41, 16.71
    { 242275, Bucket(2209) }, // 47.99, 16.71 x 48.41, 17.13
    { 242281, Bucket(2209) }, // 47.99, 17.13 x 48.41, 17.55
    { 242299, Bucket(2212) }, // 49.67, 17.55 x 50.09, 17.97
    { 242333, Bucket(2215) }, // 47.15, 18.81 x 47.57, 19.23
    { 242334, 1461 }, // 46.73, 19.23 x 47.15, 19.65
    { 242356, 1461 }, // 46.73, 19.65 x 47.15, 20.07
    { 242376, Bucket(2228) }, // 47.57, 18.81 x 47.99, 19.23
    { 242385, Bucket(2232) }, // 49.67, 17.97 x 50.09, 18.39
    { 242390, Bucket(2239) }, // 50.09, 18.39 x 50.51, 18.81
    { 242396, Bucket(2242) }, // 50.09, 18.81 x 50.51, 19.23
    { 242409, 3158 }, // 47.99, 20.49 x 48.41, 20.91
    { 242417, 3416 }, // 49.67, 19.65 x 50.09, 20.07
    { 242432, Bucket(2255) }, // 50.93, 14.62 x 51.35, 15.04
    { 242450, Bucket(2258) }, // 52.61, 15.04 x 53.03, 15.45
    { 242466, Bucket(2261) }, // 50.93, 16.71 x 51.35, 17.13
    { 242471, Bucket(2273) }, // 52.19, 16.71 x 52.61, 17.13
    { 242571, Bucket(2296) }, // 51.35, 19.23 x 51.77, 19.65
    { 242574, Bucket(2311) }, // 51.77, 19.23 x 52.19, 19.65
    { 242578, Bucket(2324) }, // 52.61, 18.39 x 53.03, 18.81
    { 242579, Bucket(2324) }, // 53.03, 18.39 x 53.45, 18.81
    { 242591, Bucket(2332) }, // 53.86, 19.23 x 54.28, 19.65
    { 242607, Bucket(2336) }, // 52.19, 20.91 x 52.61, 21.33
    { 242626, Bucket(2340) }, // 54.28, 18.39 x 54.7, 18.81
    { 242745, Bucket(2351) }, // 59.74, 10.42 x 60.16, 10.84
    { 242818, Bucket(2358) }, // 57.64, 11.68 x 58.06, 12.1
    { 243333, 1045 }, // 58.9, 17.97 x 59.32, 18.39
    { 243344, Bucket(2361) }, // 59.32, 17.97 x 59.74, 18.39
    { 243728, Bucket(2365) }, // 45.9, 21.33 x 46.31, 21.75
    { 243766, Bucket(2368) }, // 46.73, 23.42 x 47.15, 23.84
    { 243833, Bucket(2371) }, // 49.67, 23.84 x 50.09, 24.26
    { 243850, Bucket(2376) }, // 44.22, 25.94 x 44.64, 26.36
    { 243886, Bucket(2395) }, // 45.06, 27.62 x 45.48, 28.04
    { 244092, Bucket(2399) }, // 56.8, 23.84 x 57.22, 24.26
    { 244197, 644 }, // 55.54, 26.36 x 55.96, 26.78
    { 244374, 3087 }, // 46.73, 31.81 x 47.15, 32.23
    { 244550, 2798 }, // 55.12, 28.46 x 55.54, 28.88
    { 244783, 3505 }, // 58.9, 24.26 x 59.32, 24.68
    { 244794, 3505 }, // 59.32, 24.26 x 59.74, 24.68
    { 244884, Bucket(2403) }, // 60.16, 24.68 x 60.58, 25.1
    { 245299, Bucket(2410) }, // 59.74, 30.13 x 60.16, 30.55
    { 545061, Bucket(2437) }, // -1.5, 36.43 x -1.081, 36.85
    { 545063, 2481 }, // -1.5, 36.85 x -1.081, 37.26
    { 545991, 1645 }, // 8.566, 38.52 x 8.986, 38.94
    { 546002, Bucket(2440) }, // 8.986, 38.52 x 9.405, 38.94
    { 556126, 2146 }, // 9.824, 76.27 x 10.24, 76.69
    { 556465, Bucket(2443) }, // 12.76, 80.05 x 13.18, 80.47
    { 556501, 2449 }, // 16.95, 78.37 x 17.37, 78.79
    { 579420, Bucket(2449) }, // 16.54, 95.99 x 16.95, 96.4
    { 579509, Bucket(2454) }, // 13.6, 100.2 x 14.02, 100.6
    { 579709, 2757 }, // -3.178, 104.4 x -2.758, 104.8
    { 579743, 3671 }, // -6.533, 106.5 x -6.114, 106.9
    { 579765, 3671 }, // -6.533, 106.9 x -6.114, 107.3
    { 579937, 2440 }, // 1.016, 103.5 x 1.436, 104
    { 581002, 3797 }, // 10.66, 106.5 x 11.08, 106.9
    { 581702, 3534 }, // -32.12, 115.7 x -31.7, 116.1
    { 584239, Bucket(2457) }, // -35.05, 138.3 x -34.64, 138.8
    { 587235, Bucket(2467) }, // 14.44, 120.7 x 14.86, 121.2
    { 590049, 2078 }, // 21.15, 39.78 x 21.57, 40.2
    { 590753, Bucket(2471) }, // 24.5, 46.49 x 24.92, 46.91
    { 591755, 1991 }, // 37.93, 46.07 x 38.35, 46.49
    { 592345, 2020 }, // 29.54, 52.36 x 29.96, 52.78
    { 593005, 3613 }, // 35.41, 50.69 x 35.83, 51.11
    { 593007, Bucket(2476) }, // 35.41, 51.11 x 35.83, 51.53
    { 593016, 3613 }, // 35.83, 50.69 x 36.25, 51.11
    { 593040, 2021 }, // 32.47, 51.53 x 32.89, 51.95
    { 593988, Bucket(2479) }, // 48.41, 34.75 x 48.83, 35.17
    { 594011, Bucket(2484) }, // 49.67, 36.01 x 50.09, 36.43
    { 594285, Bucket(2487) }, // 55.54, 37.26 x 55.96, 37.68
    { 594287, Bucket(2500) }, // 55.54, 37.68 x 55.96, 38.1
    { 594825, Bucket(2505) }, // 51.35, 45.65 x 51.77, 46.07
    { 596301, Bucket(2508) }, // 55.54, 49.01 x 55.96, 49.43
    { 596429, Bucket(2515) }, // 55.54, 52.36 x 55.96, 52.78
    { 596979, 1123 }, // 56.38, 60.33 x 56.8, 60.75
    { 596982, Bucket(2520) }, // 56.8, 60.33 x 57.22, 60.75
    { 598745, Bucket(2531) }, // 22.83, 72.5 x 23.25, 72.92
    { 599721, 3201 }, // 31.22, 74.17 x 31.63, 74.59
    { 600106, 2449 }, // 17.37, 77.95 x 17.79, 78.37
    { 600192, 2449 }, // 17.37, 78.37 x 17.79, 78.79
    { 600420, 2216 }, // 28.28, 76.69 x 28.7, 77.11
    { 600422, 2356 }, // 28.28, 77.11 x 28.7, 77.53
    { 600497, 3422 }, // 26.18, 80.05 x 26.6, 80.47
    { 600502, 2427 }, // 26.6, 80.47 x 27.02, 80.89
    { 600508, 2427 }, // 26.6, 80.89 x 27.02, 81.31
    { 600826, 2352 }, // 22.41, 88.02 x 22.83, 88.44
    { 601457, 2079 }, // 42.96, 76.69 x 43.38, 77.11
    { 624834, 3844 }, // 20.73, 105.6 x 21.15, 106.1
    { 624890, 3220 }, // 22.41, 108.1 x 22.83, 108.6
    { 624908, 1026 }, // 24.92, 102.7 x 25.34, 103.1
    { 625015, Bucket(2534) }, // 30.38, 104 x 30.8, 104.4
    { 625020, 3907 }, // 29.96, 104.4 x 30.38, 104.8
    { 625051, 2084 }, // 26.18, 106.5 x 26.6, 106.9
    { 625054, 2084 }, // 26.6, 106.5 x 27.02, 106.9
    { 625112, 3503 }, // 29.12, 106.1 x 29.54, 106.5
    { 625115, 2685 }, // 29.54, 106.5 x 29.96, 106.9
    { 625371, Bucket(2540) }, // 22.83, 113.2 x 23.25, 113.6
    { 625383, Bucket(2545) }, // 21.99, 114 x 22.41, 114.4
    { 625392, 3551 }, // 22.41, 113.6 x 22.83, 114
    { 625393, Bucket(2549) }, // 22.83, 113.6 x 23.25, 114
    { 625394, Bucket(2552) }, // 22.41, 114 x 22.83, 114.4
    { 625609, Bucket(2559) }, // 27.86, 112.8 x 28.28, 113.2
    { 625655, Bucket(2562) }, // 30.38, 114 x 30.8, 114.4
    { 625661, 3775 }, // 30.38, 114.4 x 30.8, 114.9
    { 625776, Bucket(2570) }, // 35.83, 103.5 x 36.25, 104
    { 626240, Bucket(2573) }, // 34.15, 108.6 x 34.57, 109
    { 626242, 3337 }, // 34.15, 109 x 34.57, 109.4
    { 626338, 2690 }, // 30.8, 114 x 31.22, 114.4
    { 626379, Bucket(2576) }, // 34.57, 113.2 x 34.99, 113.6
    { 626401, Bucket(2580) }, // 34.57, 113.6 x 34.99, 114
    { 626495, Bucket(2587) }, // 40.44, 111.5 x 40.86, 111.9
    { 626538, 3172 }, // 40.86, 111.5 x 41.28, 111.9
    { 626562, Bucket(2590) }, // 37.51, 112.3 x 37.93, 112.8
    { 631002, Bucket(2593) }, // 22.41, 119.9 x 22.83, 120.3
    { 631024, Bucket(2593) }, // 22.41, 120.3 x 22.83, 120.7
    { 631110, Bucket(2596) }, // 28.28, 115.7 x 28.7, 116.1
    { 631144, 3547 }, // 27.44, 117.8 x 27.86, 118.2
    { 631186, Bucket(2599) }, // 25.76, 119.1 x 26.18, 119.5
    { 631212, 1855 }, // 24.92, 121.2 x 25.34, 121.6
    { 631262, Bucket(2602) }, // 29.96, 119.9 x 30.38, 120.3
    { 631276, 3577 }, // 28.28, 121.2 x 28.7, 121.6
    { 631281, 3329 }, // 29.54, 120.3 x 29.96, 120.7
    { 631284, Bucket(2607) }, // 29.96, 120.3 x 30.38, 120.7
    { 631844, Bucket(2610) }, // 31.63, 117 x 32.05, 117.4
    { 631855, 3649 }, // 32.05, 118.2 x 32.47, 118.6
    { 631904, Bucket(2614) }, // 34.15, 117 x 34.57, 117.4
    { 631940, Bucket(2617) }, // 31.63, 118.6 x 32.05, 119.1
    { 631941, Bucket(2620) }, // 32.05, 118.6 x 32.47, 119.1
    { 631950, 3796 }, // 31.63, 119.9 x 32.05, 120.3
    { 631971, 2469 }, // 31.22, 120.7 x 31.63, 121.2
    { 631974, 3542 }, // 31.63, 120.7 x 32.05, 121.2
    { 631975, 3542 }, // 32.05, 120.7 x 32.47, 121.2
    { 631976, 1827 }, // 30.8, 121.2 x 31.22, 121.6
    { 632026, 3825 }, // 35.83, 119.9 x 36.25, 120.3
    { 632048, 3570 }, // 35.83, 120.3 x 36.25, 120.7
    { 632089, Bucket(2624) }, // 39.6, 116.1 x 40.02, 116.5
    { 632092, 379 }, // 40.02, 116.1 x 40.44, 116.5
    { 632101, Bucket(2631) }, // 38.77, 117 x 39.18, 117.4
    { 632112, Bucket(2633) }, // 39.18, 117 x 39.6, 117.4
    { 632239, Bucket(2637) }, // 38.77, 121.6 x 39.18, 122
    { 632250, 3428 }, // 39.18, 121.6 x 39.6, 122
    { 632526, 3411 }, // 34.99, 126.6 x 35.41, 127
    { 632543, Bucket(2641) }, // 37.09, 126.6 x 37.51, 127
    { 632559, 2170 }, // 35.41, 128.3 x 35.83, 128.7
    { 632565, Bucket(2645) }, // 37.09, 127 x 37.51, 127.4
    { 632570, Bucket(2648) }, // 35.83, 128.3 x 36.25, 128.7
    { 632581, 2228 }, // 38.77, 122 x 39.18, 122.4
    { 632651, Bucket(2651) }, // 41.28, 123.2 x 41.7, 123.7
    { 632654, Bucket(2657) }, // 41.7, 123.2 x 42.12, 123.7
    { 632709, 3124 }, // 38.77, 125.3 x 39.18, 125.8
    { 632714, 2521 }, // 37.51, 126.6 x 37.93, 127
    { 633924, Bucket(2665) }, // 34.99, 128.7 x 35.41, 129.1
    { 634048, Bucket(2669) }, // 34.15, 132.1 x 34.57, 132.5
    { 634050, Bucket(2674) }, // 34.15, 132.5 x 34.57, 132.9
    { 634080, 3071 }, // 34.15, 133.7 x 34.57, 134.2
    { 634433, 2861 }, // 34.57, 135.4 x 34.99, 135.8
    { 634446, Bucket(2677) }, // 34.99, 136.7 x 35.41, 137.1
    { 634450, 2868 }, // 35.83, 135.8 x 36.25, 136.3
    { 634573, Bucket(2681) }, // 35.41, 139.6 x 35.83, 140
    { 635535, 2274 }, // 45.48, 126.6 x 45.9, 127
    { 660847, 1060 }, // -38.41, 145.1 x -37.99, 145.5
    { 660856, Bucket(2691) }, // -37.99, 144.6 x -37.57, 145.1
    { 669174, Bucket(2701) }, // -37.15, 174.4 x -36.73, 174.8
    { 669180, 11 }, // -37.15, 174.8 x -36.73, 175.3
    { 672260, 2862 }, // -35.47, 148.8 x -35.05, 149.3
    { 672307, Bucket(2704) }, // -34.22, 150.9 x -33.8, 151.4
    { 256343, 2636 }, // -2.968, -79.13 x -2.758, -78.92
    { 259050, 2632 }, // 8.986, -79.55 x 9.195, -79.34
    { 398857, Bucket(2707) }, // 37.72, -122.5 x 37.93, -122.3
    { 399485, 2255 }, // 33.94, -118.3 x 34.15, -118.1
    { 403703, Bucket(2714) }, // 20.52, -103.5 x 20.73, -103.2
    { 403874, 3162 }, // 20.73, -103.5 x 20.94, -103.2
    { 405594, 3672 }, // 33.31, -112.3 x 33.52, -112.1
    { 405616, 2523 }, // 33.31, -112.1 x 33.52, -111.8
    { 406645, 1726 }, // 40.65, -112.1 x 40.86, -111.8
    { 410047, Bucket(2718) }, // 49.04, -123.2 x 49.25, -123
    { 410090, Bucket(2718) }, // 49.25, -123.2 x 49.46, -123
    { 410134, 207 }, // 45.48, -122.7 x 45.69, -122.5
    { 410204, 1280 }, // 47.15, -122.5 x 47.36, -122.3
    { 410389, Bucket(2718) }, // 49.04, -123 x 49.25, -122.7
    { 410432, Bucket(2718) }, // 49.25, -123 x 49.46, -122.7
    { 426051, Bucket(2721) }, // 19.26, -99.26 x 19.47, -99.05
    { 426054, 2266 }, // 19.47, -99.26 x 19.68, -99.05
    { 430305, 1057 }, // 32.68, -96.95 x 32.89, -96.74
    { 433978, Bucket(2726) }, // 41.7, -87.94 x 41.91, -87.73
    { 434064, Bucket(2726) }, // 41.7, -87.73 x 41.91, -87.52
    { 435871, Bucket(2729) }, // 25.55, -80.39 x 25.76, -80.18
    { 435914, Bucket(2729) }, // 25.76, -80.39 x 25.97, -80.18
    { 438484, 1419 }, // 33.73, -84.37 x 33.94, -84.16
    { 440280, 3122 }, // 43.38, -80.59 x 43.59, -80.39
    { 440315, Bucket(2732) }, // 43.59, -79.55 x 43.8, -79.34
    { 441681, 2211 }, // 43.59, -79.34 x 43.8, -79.13
    { 441935, Bucket(2741) }, // 39.81, -75.35 x 40.02, -75.14
    { 441957, 2279 }, // 39.81, -75.14 x 40.02, -74.93
    { 442069, 2785 }, // 40.65, -74.3 x 40.86, -74.09
    { 442071, Bucket(2748) }, // 40.65, -74.09 x 40.86, -73.88
    { 442242, Bucket(2754) }, // 40.86, -74.09 x 41.07, -73.88
    { 443047, 883 }, // 44.85, -93.39 x 45.06, -93.18
    { 453139, Bucket(2757) }, // 45.27, -75.77 x 45.48, -75.56
    { 590035, Bucket(2761) }, // -33.59, -70.74 x -33.38, -70.53
    { 598090, Bucket(2767) }, // -34.64, -58.57 x -34.43, -58.37
    { 602074, Bucket(2770) }, // -23.73, -46.83 x -23.52, -46.62
    { 605731, 2061 }, // -15.97, -48.09 x -15.76, -47.88
    { 611292, 2382 }, // 10.24, -67.17 x 10.45, -66.96
    { 611295, 3376 }, // 10.45, -66.96 x 10.66, -66.75
    { 624095, 1771 }, // -23.1, -43.48 x -22.89, -43.27
    { 624117, 1771 }, // -23.1, -43.27 x -22.89, -43.06
    { 626849, 2816 }, // -22.68, -43.27 x -22.47, -43.06
    { 626900, 1730 }, // -19.96, -44.1 x -19.75, -43.89
    { 630271, 3310 }, // -9.679, -35.93 x -9.469, -35.72
    { 639724, 2975 }, // -7.372, -39.49 x -7.162, -39.28
    { 641357, 2822 }, // -3.807, -38.65 x -3.597, -38.44
    { 641566, Bucket(2773) }, // -8.211, -35.09 x -8.001, -34.88
    { 641615, 2977 }, // -7.162, -35.09 x -6.953, -34.88
    { 641637, 2977 }, // -7.162, -34.88 x -6.953, -34.67
    { 752610, 2633 }, // 8.986, 7.276 x 9.195, 7.485
    { 764412, 3005 }, // -30.02, 30.97 x -29.81, 31.18
    { 765184, 3018 }, // -26.25, 28.04 x -26.04, 28.25
    { 765190, 2897 }, // -25.83, 28.25 x -25.62, 28.46
    { 786609, 2063 }, // 18.42, -70.11 x 18.63, -69.9
    { 791871, 1362 }, // 42.33, -71.16 x 42.54, -70.95
    { 918960, 129 }, // 28.28, -16.42 x 28.49, -16.21
    { 924375, 1563 }, // 33.94, -6.985 x 34.15, -6.775
    { 924663, Bucket(2778) }, // 37.3, -6.146 x 37.51, -5.936
    { 924669, 3108 }, // 37.3, -5.936 x 37.51, -5.727
    { 924857, Bucket(2781) }, // 38.56, -9.292 x 38.77, -9.082
    { 925443, Bucket(2788) }, // 41.07, -8.663 x 41.28, -8.453
    { 930760, 3611 }, // 35.83, -0.06436 x 36.04, 0.1454
    { 930939, Bucket(2791) }, // 40.23, -4.049 x 40.44, -3.839
    { 931025, Bucket(2794) }, // 40.23, -3.839 x 40.44, -3.63
    { 931028, 2163 }, // 40.44, -3.839 x 40.65, -3.63
    { 931269, 1360 }, // 43.17, -3.839 x 43.38, -3.63
    { 931279, Bucket(2799) }, // 43.17, -3.21 x 43.38, -3
    { 931280, 1360 }, // 43.38, -3.839 x 43.59, -3.63
    { 931299, Bucket(2803) }, // 42.75, -2.791 x 42.96, -2.581
    { 931301, Bucket(2806) }, // 43.17, -3 x 43.38, -2.791
    { 931364, 3308 }, // 37.93, -1.323 x 38.14, -1.113
    { 931386, 283 }, // 38.35, -0.6935 x 38.56, -0.4838
    { 931435, 1625 }, // 39.39, -0.6935 x 39.6, -0.4838
    { 931521, Bucket(2812) }, // 39.39, -0.4838 x 39.6, -0.2741
    { 932306, Bucket(2819) }, // 36.67, 3.081 x 36.88, 3.291
    { 932379, 3354 }, // 31.84, 5.179 x 32.05, 5.388
    { 933134, Bucket(2822) }, // 41.28, 1.823 x 41.49, 2.033
    { 933156, Bucket(2825) }, // 41.28, 2.033 x 41.49, 2.243
    { 933711, 262 }, // 43.17, 5.179 x 43.38, 5.388
    { 933733, 262 }, // 43.17, 5.388 x 43.38, 5.598
    { 933873, 2864 }, // 43.59, 7.066 x 43.8, 7.276
    { 942684, 788 }, // 47.15, -1.742 x 47.36, -1.532
    { 942719, Bucket(2839) }, // 47.36, -0.6935 x 47.57, -0.4838
    { 942860, Bucket(2843) }, // 47.99, -1.742 x 48.2, -1.532
    { 943082, 260 }, // 49.25, 0.9842 x 49.46, 1.194
    { 943343, Bucket(2849) }, // 53.24, -2.371 x 53.45, -2.162
    { 943354, Bucket(2846) }, // 53.45, -2.371 x 53.65, -2.162
    { 943415, 2073 }, // 55.75, -4.468 x 55.96, -4.259
    { 943421, 2073 }, // 55.75, -4.259 x 55.96, -4.049
    { 943637, 3803 }, // 52.4, -2.162 x 52.61, -1.952
    { 943695, Bucket(2852) }, // 53.24, -1.532 x 53.45, -1.323
    { 943713, 741 }, // 52.82, -1.323 x 53.03, -1.113
    { 943750, 1999 }, // 51.35, -0.2741 x 51.56, -0.06436
    { 943756, 2092 }, // 51.35, -0.06436 x 51.56, 0.1454
    { 944279, 2605 }, // 45.69, 3.081 x 45.9, 3.291
    { 944395, Bucket(2857) }, // 47.78, 1.823 x 47.99, 2.033
    { 944435, Bucket(2860) }, // 48.62, 2.243 x 48.83, 2.452
    { 944438, Bucket(2863) }, // 48.83, 2.243 x 49.04, 2.452
    { 944444, Bucket(2869) }, // 48.83, 2.452 x 49.04, 2.662
    { 944567, Bucket(2872) }, // 49.04, 3.92 x 49.25, 4.13
    { 944603, 1983 }, // 50.3, 3.501 x 50.51, 3.711
    { 944610, Bucket(2872) }, // 49.25, 3.92 x 49.46, 4.13
    { 944635, Bucket(2875) }, // 50.3, 4.34 x 50.51, 4.549
    { 944639, Bucket(2878) }, // 50.72, 4.34 x 50.93, 4.549
    { 944663, Bucket(2884) }, // 45.69, 4.759 x 45.9, 4.969
    { 944690, Bucket(2891) }, // 45.06, 5.598 x 45.27, 5.808
    { 944732, 675 }, // 47.15, 4.969 x 47.36, 5.179
    { 944747, Bucket(2896) }, // 46.11, 6.017 x 46.31, 6.227
    { 944750, 373 }, // 46.31, 6.017 x 46.52, 6.227
    { 944836, 373 }, // 46.31, 6.227 x 46.52, 6.437
    { 944847, 3046 }, // 46.52, 6.856 x 46.73, 7.066
    { 944881, 3834 }, // 46.94, 7.066 x 47.15, 7.276
    { 944888, Bucket(2900) }, // 46.73, 7.485 x 46.94, 7.695
    { 944891, 236 }, // 46.94, 7.695 x 47.15, 7.905
    { 944893, Bucket(2903) }, // 47.36, 7.485 x 47.57, 7.695
    { 944894, Bucket(2917) }, // 47.15, 7.695 x 47.36, 7.905
    { 944895, Bucket(2920) }, // 47.36, 7.695 x 47.57, 7.905
    { 945003, 2086 }, // 49.46, 6.017 x 49.67, 6.227
    { 945012, 3861 }, // 50.51, 5.388 x 50.72, 5.598
    { 945055, 330 }, // 49.04, 6.856 x 49.25, 7.066
    { 945064, Bucket(2923) }, // 47.57, 7.485 x 47.78, 7.695
    { 945067, Bucket(2931) }, // 47.78, 7.695 x 47.99, 7.905
    { 945070, Bucket(2934) }, // 47.99, 7.695 x 48.2, 7.905
    { 945077, 330 }, // 49.04, 7.066 x 49.25, 7.276
    { 945098, 330 }, // 49.25, 6.856 x 49.46, 7.066
    { 945119, Bucket(2938) }, // 50.72, 6.856 x 50.93, 7.066
    { 945120, 330 }, // 49.25, 7.066 x 49.46, 7.276
    { 945122, 899 }, // 49.25, 7.276 x 49.46, 7.485
    { 945123, 899 }, // 49.46, 7.276 x 49.67, 7.485
    { 945290, Bucket(2942) }, // 50.93, 3.501 x 51.14, 3.711
    { 945312, Bucket(2942) }, // 50.93, 3.711 x 51.14, 3.92
    { 945323, Bucket(2947) }, // 51.14, 4.34 x 51.35, 4.549
    { 945337, Bucket(2958) }, // 51.98, 4.13 x 52.19, 4.34
    { 945338, Bucket(2965) }, // 51.77, 4.34 x 51.98, 4.549
    { 945339, Bucket(2971) }, // 51.98, 4.34 x 52.19, 4.549
    { 945680, 1703 }, // 51.77, 4.549 x 51.98, 4.759
    { 945686, Bucket(2975) }, // 52.19, 4.759 x 52.4, 4.969
    { 945795, 520 }, // 51.14, 6.437 x 51.35, 6.647
    { 945801, Bucket(2984) }, // 51.14, 6.647 x 51.35, 6.856
    { 945802, Bucket(2997) }, // 50.93, 6.856 x 51.14, 7.066
    { 945806, Bucket(3003) }, // 51.35, 6.856 x 51.56, 7.066
    { 945828, Bucket(3015) }, // 51.35, 7.066 x 51.56, 7.276
    { 945830, Bucket(3022) }, // 51.35, 7.276 x 51.56, 7.485
    { 954840, Bucket(3025) }, // 36.67, 10 x 36.88, 10.21
    { 955490, 1562 }, // 39.18, 8.953 x 39.39, 9.163
    { 955496, 1562 }, // 39.18, 9.163 x 39.39, 9.373
    { 956157, Bucket(3028) }, // 40.65, 14.2 x 40.86, 14.41
    { 956245, 1629 }, // 44.01, 11.26 x 44.22, 11.47
    { 956328, Bucket(3032) }, // 40.86, 14.2 x 41.07, 14.41
    { 957525, 3674 }, // 40.65, 14.62 x 40.86, 14.83
    { 957833, 1159 }, // 41.07, 16.71 x 41.28, 16.92
    { 962042, Bucket(3036) }, // 29.96, 31.18 x 30.17, 31.39
    { 962384, 2008 }, // 29.96, 31.39 x 30.17, 31.6
    { 963591, Bucket(3039) }, // 38.14, 21.54 x 38.35, 21.75
    { 963597, 3179 }, // 38.14, 21.75 x 38.35, 21.96
    { 963726, 2284 }, // 37.93, 23.63 x 38.14, 23.84
    { 964034, Bucket(3042) }, // 42.54, 23.21 x 42.75, 23.42
    { 964250, Bucket(3058) }, // 38.35, 26.99 x 38.56, 27.2
    { 965105, 3203 }, // 36.88, 30.55 x 37.09, 30.76
    { 965920, 1122 }, // 40.86, 28.88 x 41.07, 29.09
    { 966253, Bucket(3061) }, // 39.81, 32.65 x 40.02, 32.86
    { 966737, 236 }, // 46.94, 7.905 x 47.15, 8.115
    { 966739, 3032 }, // 46.94, 8.115 x 47.15, 8.324
    { 966740, Bucket(2917) }, // 47.15, 7.905 x 47.36, 8.115
    { 966741, 2859 }, // 47.36, 7.905 x 47.57, 8.115
    { 966742, 578 }, // 47.15, 8.115 x 47.36, 8.324
    { 966743, 579 }, // 47.36, 8.115 x 47.57, 8.324
    { 966745, Bucket(3064) }, // 46.94, 8.324 x 47.15, 8.534
    { 966748, Bucket(3064) }, // 47.15, 8.324 x 47.36, 8.534
    { 966749, Bucket(3067) }, // 47.36, 8.324 x 47.57, 8.534
    { 966750, Bucket(3070) }, // 47.15, 8.534 x 47.36, 8.744
    { 966751, Bucket(3073) }, // 47.36, 8.534 x 47.57, 8.744
    { 966752, 3518 }, // 45.9, 8.744 x 46.11, 8.953
    { 966767, 3655 }, // 46.52, 9.373 x 46.73, 9.583
    { 966772, Bucket(3079) }, // 47.15, 8.744 x 47.36, 8.953
    { 966773, Bucket(3084) }, // 47.36, 8.744 x 47.57, 8.953
    { 966775, Bucket(3089) }, // 47.36, 8.953 x 47.57, 9.163
    { 966778, 3655 }, // 46.73, 9.373 x 46.94, 9.583
    { 966783, 3444 }, // 47.36, 9.373 x 47.57, 9.583
    { 966864, 3656 }, // 46.73, 9.583 x 46.94, 9.792
    { 966865, 1240 }, // 46.94, 9.583 x 47.15, 9.792
    { 966867, 3079 }, // 46.94, 9.792 x 47.15, 10
    { 966868, 1240 }, // 47.15, 9.583 x 47.36, 9.792
    { 966869, Bucket(3092) }, // 47.36, 9.583 x 47.57, 9.792
    { 966870, 3079 }, // 47.15, 9.792 x 47.36, 10
    { 966916, 725 }, // 47.99, 7.905 x 48.2, 8.115
    { 966921, 1906 }, // 47.78, 8.324 x 47.99, 8.534
    { 966922, Bucket(3097) }, // 47.57, 8.534 x 47.78, 8.744
    { 966924, 1906 }, // 47.99, 8.324 x 48.2, 8.534
    { 966940, Bucket(3101) }, // 48.83, 8.324 x 49.04, 8.534
    { 966941, 1408 }, // 49.04, 8.324 x 49.25, 8.534
    { 966942, 1408 }, // 48.83, 8.534 x 49.04, 8.744
    { 966944, 2463 }, // 47.57, 8.744 x 47.78, 8.953
    { 966964, 854 }, // 48.83, 8.744 x 49.04, 8.953
    { 966965, Bucket(3107) }, // 49.04, 8.744 x 49.25, 8.953
    { 966966, 200 }, // 48.83, 8.953 x 49.04, 9.163
    { 966967, Bucket(3107) }, // 49.04, 8.953 x 49.25, 9.163
    { 966972, 200 }, // 48.83, 9.163 x 49.04, 9.373
    { 966973, 854 }, // 49.04, 9.163 x 49.25, 9.373
    { 966975, 854 }, // 49.04, 9.373 x 49.25, 9.583
    { 966983, Bucket(3110) }, // 49.88, 8.115 x 50.09, 8.324
    { 966985, Bucket(3118) }, // 49.46, 8.324 x 49.67, 8.534
    { 966986, Bucket(3123) }, // 49.25, 8.534 x 49.46, 8.744
    { 966988, 532 }, // 49.67, 8.324 x 49.88, 8.534
    { 966989, Bucket(1075) }, // 49.88, 8.324 x 50.09, 8.534
    { 966990, Bucket(3128) }, // 49.67, 8.534 x 49.88, 8.744
    { 966991, Bucket(3132) }, // 49.88, 8.534 x 50.09, 8.744
    { 967002, Bucket(3139) }, // 50.09, 8.534 x 50.3, 8.744
    { 967013, Bucket(3114) }, // 49.88, 8.744 x 50.09, 8.953
    { 967024, Bucket(3114) }, // 50.09, 8.744 x 50.3, 8.953
    { 967071, 798 }, // 49.04, 10.21 x 49.25, 10.42
    { 967082, 3181 }, // 47.57, 11.05 x 47.78, 11.26
    { 967085, Bucket(3153) }, // 48.2, 10.84 x 48.41, 11.05
    { 967110, Bucket(3156) }, // 49.67, 9.792 x 49.88, 10
    { 967146, Bucket(3162) }, // 49.25, 11.05 x 49.46, 11.26
    { 967252, Bucket(3165) }, // 47.15, 11.26 x 47.36, 11.47
    { 967430, Bucket(3171) }, // 47.99, 11.47 x 48.2, 11.68
    { 967465, 2455 }, // 47.78, 12.52 x 47.99, 12.73
    { 967467, 2391 }, // 47.78, 12.73 x 47.99, 12.94
    { 967551, Bucket(3187) }, // 50.72, 12.73 x 50.93, 12.94
    { 967553, 2391 }, // 47.78, 12.94 x 47.99, 13.15
    { 967597, Bucket(3194) }, // 48.2, 14.2 x 48.41, 14.41
    { 967628, Bucket(3201) }, // 49.67, 13.36 x 49.88, 13.57
    { 967637, Bucket(3204) }, // 50.72, 12.94 x 50.93, 13.15
    { 967663, Bucket(3208) }, // 49.88, 14.41 x 50.09, 14.62
    { 967672, 1578 }, // 50.09, 14.2 x 50.3, 14.41
    { 967674, Bucket(3213) }, // 50.09, 14.41 x 50.3, 14.62
    { 967723, Bucket(3216) }, // 51.14, 9.373 x 51.35, 9.583
    { 967726, 1356 }, // 51.35, 9.373 x 51.56, 9.583
    { 967742, 1415 }, // 52.19, 9.373 x 52.4, 9.583
    { 967780, Bucket(3224) }, // 53.03, 8.744 x 53.24, 8.953
    { 967802, 1620 }, // 53.45, 9.373 x 53.65, 9.583
    { 967809, 2383 }, // 51.14, 9.583 x 51.35, 9.792
    { 967828, Bucket(3232) }, // 52.19, 9.583 x 52.4, 9.792
    { 967860, Bucket(3236) }, // 52.19, 10.42 x 52.4, 10.63
    { 967864, 1359 }, // 51.77, 10.84 x 51.98, 11.05
    { 967866, 1359 }, // 51.77, 11.05 x 51.98, 11.26
    { 967872, 1040 }, // 52.61, 9.583 x 52.82, 9.792
    { 967890, 1100 }, // 53.45, 9.792 x 53.65, 10
    { 967896, 1100 }, // 53.45, 10 x 53.65, 10.21
    { 968206, Bucket(3243) }, // 51.35, 11.89 x 51.56, 12.1
    { 968211, Bucket(3253) }, // 51.98, 11.47 x 52.19, 11.68
    { 968227, Bucket(3257) }, // 51.14, 12.31 x 51.35, 12.52
    { 968230, Bucket(3259) }, // 51.35, 12.31 x 51.56, 12.52
    { 968240, 185 }, // 51.77, 12.1 x 51.98, 12.31
    { 968320, 1891 }, // 50.93, 12.94 x 51.14, 13.15
    { 968321, 1058 }, // 51.14, 12.94 x 51.35, 13.15
    { 968322, 1735 }, // 50.93, 13.15 x 51.14, 13.36
    { 968324, 1058 }, // 51.35, 12.94 x 51.56, 13.15
    { 968330, Bucket(3262) }, // 50.93, 13.57 x 51.14, 13.78
    { 968349, Bucket(3273) }, // 52.4, 13.36 x 52.61, 13.57
    { 968351, 34 }, // 52.4, 13.57 x 52.61, 13.78
    { 968352, Bucket(3282) }, // 50.93, 13.78 x 51.14, 13.99
    { 968382, Bucket(3290) }, // 52.19, 14.41 x 52.4, 14.62
    { 968431, Bucket(3295) }, // 53.24, 14.41 x 53.45, 14.62
    { 968442, Bucket(3303) }, // 53.45, 14.41 x 53.65, 14.62
    { 968502, 3052 }, // 55.54, 12.31 x 55.75, 12.52
    { 968508, 3052 }, // 55.54, 12.52 x 55.75, 12.73
    { 968765, Bucket(3309) }, // 45.69, 15.87 x 45.9, 16.08
    { 968795, Bucket(3324) }, // 46.94, 15.24 x 47.15, 15.45
    { 968817, 425 }, // 46.94, 15.45 x 47.15, 15.66
    { 969006, 113 }, // 47.99, 16.08 x 48.2, 16.29
    { 969007, 3472 }, // 48.2, 16.08 x 48.41, 16.29
    { 969053, 913 }, // 50.72, 15.04 x 50.93, 15.24
    { 969092, Bucket(3328) }, // 47.99, 16.29 x 48.2, 16.5
    { 969093, Bucket(3333) }, // 48.2, 16.29 x 48.41, 16.5
    { 969111, Bucket(3339) }, // 49.04, 16.5 x 49.25, 16.71
    { 969185, Bucket(3351) }, // 49.46, 17.13 x 49.67, 17.34
    { 969246, Bucket(3357) }, // 45.48, 18.6 x 45.69, 18.81
    { 969335, Bucket(3360) }, // 47.36, 19.02 x 47.57, 19.23
    { 969358, Bucket(3385) }, // 44.64, 20.28 x 44.85, 20.49
    { 969407, Bucket(3390) }, // 45.69, 21.12 x 45.9, 21.33
    { 969451, Bucket(3398) }, // 46.11, 21.12 x 46.31, 21.33
    { 969540, 1433 }, // 49.67, 17.97 x 49.88, 18.18
    { 969542, Bucket(3401) }, // 49.67, 18.18 x 49.88, 18.39
    { 969585, Bucket(3412) }, // 50.3, 18.81 x 50.51, 19.02
    { 969591, Bucket(3415) }, // 50.72, 19.02 x 50.93, 19.23
    { 969638, 3157 }, // 47.99, 20.7 x 48.2, 20.91
    { 969659, Bucket(3419) }, // 48.62, 21.12 x 48.83, 21.33
    { 969671, Bucket(3432) }, // 49.88, 19.86 x 50.09, 20.07
    { 969682, Bucket(3449) }, // 50.09, 19.86 x 50.3, 20.07
    { 969866, Bucket(3457) }, // 50.93, 16.92 x 51.14, 17.13
    { 969966, Bucket(3467) }, // 53.03, 17.76 x 53.24, 17.97
    { 970287, 2676 }, // 51.56, 19.44 x 51.77, 19.65
    { 970298, 2676 }, // 51.77, 19.44 x 51.98, 19.65
    { 970308, Bucket(3470) }, // 53.03, 17.97 x 53.24, 18.18
    { 970365, Bucket(3481) }, // 54.07, 19.23 x 54.28, 19.44
    { 970425, 1598 }, // 51.98, 20.91 x 52.19, 21.12
    { 970428, Bucket(3484) }, // 52.19, 20.91 x 52.4, 21.12
    { 970459, 3588 }, // 53.65, 20.28 x 53.86, 20.49
    { 970481, 3588 }, // 53.65, 20.49 x 53.86, 20.7
    { 970982, 1112 }, // 59.74, 10.63 x 59.95, 10.84
    { 971215, 2844 }, // 63.3, 10.21 x 63.51, 10.42
    { 971274, Bucket(3496) }, // 57.64, 11.89 x 57.85, 12.1
    { 972858, Bucket(3506) }, // 58.48, 16.08 x 58.69, 16.29
    { 972991, Bucket(3509) }, // 59.11, 17.76 x 59.32, 17.97
    { 973034, Bucket(3509) }, // 59.32, 17.76 x 59.53, 17.97
    { 973333, Bucket(3515) }, // 59.11, 17.97 x 59.32, 18.18
    { 973335, 1044 }, // 59.11, 18.18 x 59.32, 18.39
    { 973376, Bucket(3523) }, // 59.32, 17.97 x 59.53, 18.18
    { 974913, 3400 }, // 46.11, 21.33 x 46.31, 21.54
    { 974937, Bucket(3533) }, // 46.94, 21.75 x 47.15, 21.96
    { 974986, Bucket(3537) }, // 44.22, 23.63 x 44.43, 23.84
    { 975008, Bucket(3538) }, // 44.22, 23.84 x 44.43, 24.05
    { 975401, Bucket(3541) }, // 44.43, 25.94 x 44.64, 26.15
    { 975405, Bucket(3547) }, // 44.85, 25.94 x 45.06, 26.15
    { 975546, Bucket(3550) }, // 45.06, 27.83 x 45.27, 28.04
    { 976370, Bucket(3553) }, // 56.8, 24.05 x 57.01, 24.26
    { 977371, Bucket(3556) }, // 50.3, 30.34 x 50.51, 30.55
    { 977393, Bucket(3561) }, // 50.3, 30.55 x 50.51, 30.76
    { 977795, Bucket(3564) }, // 47.78, 33.28 x 47.99, 33.49
    { 977850, Bucket(3580) }, // 48.41, 34.54 x 48.62, 34.75
    { 978004, Bucket(1282) }, // 53.86, 28.04 x 54.07, 28.25
    { 978328, Bucket(3583) }, // 55.12, 30.13 x 55.33, 30.34
    { 979342, 3343 }, // 61.41, 23.63 x 61.62, 23.84
    { 979520, Bucket(3586) }, // 59.32, 24.68 x 59.53, 24.89
    { 981196, Bucket(3591) }, // 59.74, 30.13 x 59.95, 30.34
    { 981197, Bucket(3595) }, // 59.95, 30.13 x 60.16, 30.34
    { 981198, Bucket(3600) }, // 59.74, 30.34 x 59.95, 30.55
    { 2225663, 2449 }, // 17.16, 78.16 x 17.37, 78.37
    { 2226005, 2422 }, // 17.16, 78.37 x 17.37, 78.58
    { 2314234, 2308 }, // 3.114, 101.6 x 3.323, 101.9
    { 2317681, 2543 }, // 16.75, 95.99 x 16.95, 96.19
    { 2318038, 2299 }, // 13.6, 100.4 x 13.81, 100.6
    { 2318975, Bucket(3610) }, // -6.324, 106.7 x -6.114, 106.9
    { 2319061, 3680 }, // -6.324, 106.9 x -6.114, 107.1
    { 2319751, Bucket(3613) }, // 1.226, 103.7 x 1.436, 104
    { 2336958, Bucket(3616) }, // -35.05, 138.6 x -34.84, 138.8
    { 2337002, Bucket(3619) }, // -34.64, 138.6 x -34.43, 138.8
    { 2348942, 2307 }, // 14.44, 120.9 x 14.65, 121.2
    { 2348943, 2550 }, // 14.65, 120.9 x 14.86, 121.2
    { 2363737, 2151 }, // 36.88, 35.17 x 37.09, 35.38
    { 2363889, Bucket(3622) }, // 36.88, 37.26 x 37.09, 37.47
    { 2363892, 3606 }, // 37.09, 37.26 x 37.3, 37.47
    { 2364718, 3595 }, // 41.28, 36.22 x 41.49, 36.43
    { 2366712, 2286 }, // 40.02, 44.4 x 40.23, 44.6
    { 2366847, Bucket(3625) }, // 44.01, 42.93 x 44.22, 43.14
    { 2368699, 2899 }, // 25.13, 51.32 x 25.34, 51.53
    { 2370578, 3320 }, // 24.92, 55.09 x 25.13, 55.3
    { 2372031, Bucket(3632) }, // 35.62, 51.32 x 35.83, 51.53
    { 2372373, 2144 }, // 35.62, 51.53 x 35.83, 51.74
    { 2372817, Bucket(3636) }, // 40.23, 49.85 x 40.44, 50.06
    { 2374508, 1653 }, // 36.25, 59.49 x 36.46, 59.7
    { 2375923, Bucket(3639) }, // 46.94, 37.47 x 47.15, 37.68
    { 2375926, Bucket(3646) }, // 47.15, 37.47 x 47.36, 37.68
    { 2375954, Bucket(3650) }, // 48.41, 34.96 x 48.62, 35.17
    { 2376047, 655 }, // 49.88, 36.22 x 50.09, 36.43
    { 2376286, Bucket(3654) }, // 47.15, 38.73 x 47.36, 38.94
    { 2377139, 572 }, // 55.33, 37.47 x 55.54, 37.68
    { 2377142, Bucket(3658) }, // 55.54, 37.47 x 55.75, 37.68
    { 2377143, 502 }, // 55.75, 37.47 x 55.96, 37.68
    { 2378169, Bucket(3665) }, // 48.62, 44.4 x 48.83, 44.6
    { 2379211, Bucket(3669) }, // 56.17, 43.77 x 56.38, 43.98
    { 2379233, Bucket(3680) }, // 56.17, 43.98 x 56.38, 44.19
    { 2379302, Bucket(3685) }, // 51.35, 45.86 x 51.56, 46.07
    { 2385205, Bucket(3691) }, // 55.75, 49.01 x 55.96, 49.22
    { 2385716, 3362 }, // 55.54, 52.36 x 55.75, 52.57
    { 2387535, Bucket(3694) }, // 53.24, 58.87 x 53.45, 59.08
    { 2387546, Bucket(3717) }, // 53.45, 58.87 x 53.65, 59.08
    { 2387919, Bucket(3726) }, // 56.59, 60.54 x 56.8, 60.75
    { 2387930, Bucket(3729) }, // 56.8, 60.54 x 57.01, 60.75
    { 2394685, 3121 }, // 18.84, 72.92 x 19.05, 73.13
    { 2394722, Bucket(3737) }, // 19.05, 72.71 x 19.26, 72.92
    { 2394728, 3121 }, // 19.05, 72.92 x 19.26, 73.13
    { 2394777, Bucket(3740) }, // 18.42, 73.76 x 18.63, 73.97
    { 2399524, 918 }, // 41.28, 69.14 x 41.49, 69.35
    { 2400768, Bucket(3743) }, // 17.37, 78.37 x 17.58, 78.58
    { 2401371, 2298 }, // 26.81, 75.64 x 27.02, 75.85
    { 2401532, 3817 }, // 27.02, 77.95 x 27.23, 78.16
    { 2401683, 2362 }, // 28.49, 76.9 x 28.7, 77.11
    { 2403306, Bucket(3746) }, // 22.41, 88.23 x 22.62, 88.44
    { 2420007, 2057 }, // 54.91, 82.77 x 55.12, 82.98
    { 2420206, Bucket(3749) }, // 56.38, 84.87 x 56.59, 85.08
    { 2490838, 3581 }, // 23.67, 90.32 x 23.88, 90.53
    { 2499337, 3216 }, // 20.94, 105.6 x 21.15, 105.8
    { 2499610, 3494 }, // 24.92, 102.5 x 25.13, 102.7
    { 2499632, Bucket(3754) }, // 24.92, 102.7 x 25.13, 102.9
    { 2500061, 2419 }, // 30.59, 104 x 30.8, 104.2
    { 2501476, 2945 }, // 22.83, 112.8 x 23.04, 113
    { 2501484, 3462 }, // 22.83, 113.2 x 23.04, 113.4
    { 2501485, Bucket(3757) }, // 23.04, 113.2 x 23.25, 113.4
    { 2501487, Bucket(3761) }, // 23.04, 113.4 x 23.25, 113.6
    { 2501533, Bucket(3764) }, // 22.2, 114 x 22.41, 114.2
    { 2501570, 3356 }, // 22.41, 113.8 x 22.62, 114
    { 2501571, 2032 }, // 22.62, 113.8 x 22.83, 114
    { 2501576, Bucket(3767) }, // 22.41, 114 x 22.62, 114.2
    { 2502620, 3459 }, // 30.38, 114 x 30.59, 114.2
    { 2502622, Bucket(3770) }, // 30.38, 114.2 x 30.59, 114.4
    { 2502644, 3213 }, // 30.38, 114.4 x 30.59, 114.6
    { 2502792, 2948 }, // 30.8, 104 x 31.01, 104.2
    { 2505431, 3330 }, // 33.94, 113.8 x 34.15, 114
    { 2505484, 3419 }, // 34.57, 112.3 x 34.78, 112.6
    { 2505518, Bucket(3773) }, // 34.57, 113.4 x 34.78, 113.6
    { 2506404, 3151 }, // 37.93, 114.4 x 38.14, 114.6
    { 2516119, Bucket(3776) }, // 52.4, 103.7 x 52.61, 104
    { 2516126, Bucket(3781) }, // 52.19, 104.2 x 52.4, 104.4
    { 2524747, Bucket(3786) }, // 25.97, 119.3 x 26.18, 119.5
    { 2524802, 1434 }, // 24.09, 120.5 x 24.29, 120.7
    { 2524850, Bucket(3789) }, // 24.92, 121.4 x 25.13, 121.6
    { 2525051, 3407 }, // 30.17, 120.1 x 30.38, 120.3
    { 2525137, Bucket(3792) }, // 30.17, 120.3 x 30.38, 120.5
    { 2525138, 3685 }, // 29.96, 120.5 x 30.17, 120.7
    { 2527419, 2232 }, // 31.84, 118.4 x 32.05, 118.6
    { 2527618, 3333 }, // 34.15, 117.2 x 34.36, 117.4
    { 2527751, 2645 }, // 31.43, 118.8 x 31.63, 119.1
    { 2527761, 2232 }, // 31.84, 118.6 x 32.05, 118.8
    { 2527762, 2645 }, // 31.63, 118.8 x 31.84, 119.1
    { 2527791, Bucket(3795) }, // 31.43, 120.1 x 31.63, 120.3
    { 2527800, Bucket(3799) }, // 31.63, 119.9 x 31.84, 120.1
    { 2527875, 2468 }, // 31.01, 120.5 x 31.22, 120.7
    { 2527876, Bucket(3802) }, // 31.22, 120.3 x 31.43, 120.5
    { 2527877, Bucket(3805) }, // 31.43, 120.3 x 31.63, 120.5
    { 2527878, Bucket(3810) }, // 31.22, 120.5 x 31.43, 120.7
    { 2527879, 2469 }, // 31.43, 120.5 x 31.63, 120.7
    { 2527884, Bucket(3802) }, // 31.22, 120.7 x 31.43, 120.9
    { 2527905, 2628 }, // 31.01, 121.2 x 31.22, 121.4
    { 2528107, 2206 }, // 36.04, 120.1 x 36.25, 120.3
    { 2528193, Bucket(3815) }, // 36.04, 120.3 x 36.25, 120.5
    { 2528334, 2478 }, // 39.6, 115.9 x 39.81, 116.1
    { 2528357, Bucket(3818) }, // 39.81, 116.1 x 40.02, 116.3
    { 2528359, 377 }, // 39.81, 116.3 x 40.02, 116.5
    { 2528407, Bucket(3821) }, // 38.97, 117.2 x 39.18, 117.4
    { 2528415, 2501 }, // 38.97, 117.6 x 39.18, 117.8
    { 2530173, Bucket(3825) }, // 37.3, 126.6 x 37.51, 126.8
    { 2530175, 1986 }, // 37.3, 126.8 x 37.51, 127
    { 2530260, 1969 }, // 37.09, 127 x 37.3, 127.2
    { 2530261, 2235 }, // 37.3, 127 x 37.51, 127.2
    { 2530704, 3836 }, // 41.7, 123.7 x 41.91, 123.9
    { 2530814, 2704 }, // 43.8, 125.1 x 44.01, 125.3
    { 2530839, 3100 }, // 38.97, 125.6 x 39.18, 125.8
    { 2530856, Bucket(3829) }, // 37.51, 126.6 x 37.72, 126.8
    { 2530858, Bucket(3833) }, // 37.51, 126.8 x 37.72, 127
    { 2530944, Bucket(3837) }, // 37.51, 127 x 37.72, 127.2
    { 2535619, Bucket(3842) }, // 32.68, 130.6 x 32.89, 130.8
    { 2535633, 2012 }, // 33.52, 130.4 x 33.73, 130.6
    { 2535638, 3208 }, // 33.73, 130.6 x 33.94, 130.8
    { 2536030, Bucket(3845) }, // 33.73, 132.7 x 33.94, 132.9
    { 2536195, 2011 }, // 34.36, 132.3 x 34.57, 132.5
    { 2536201, 2011 }, // 34.36, 132.5 x 34.57, 132.7
    { 2536364, Bucket(3848) }, // 34.57, 135 x 34.78, 135.2
    { 2537732, Bucket(3852) }, // 34.57, 135.4 x 34.78, 135.6
    { 2537735, 2345 }, // 34.78, 135.6 x 34.99, 135.8
    { 2537746, Bucket(3859) }, // 34.99, 135.6 x 35.2, 135.8
    { 2537786, 2348 }, // 34.99, 136.9 x 35.2, 137.1
    { 2538267, 2626 }, // 35.2, 139.4 x 35.41, 139.6
    { 2538292, Bucket(3863) }, // 35.41, 139.6 x 35.62, 139.8
    { 2538293, Bucket(3866) }, // 35.62, 139.6 x 35.83, 139.8
    { 2538314, 2595 }, // 35.83, 139.4 x 36.04, 139.6
    { 2538336, 2595 }, // 35.83, 139.6 x 36.04, 139.8
    { 2539149, 2045 }, // 38.14, 140.9 x 38.35, 141.1
    { 2539410, Bucket(3874) }, // 41.7, 140.7 x 41.91, 140.9
    { 2539492, 2313 }, // 42.96, 141.3 x 43.17, 141.5
    { 2643426, Bucket(3877) }, // -37.99, 144.8 x -37.78, 145.1
    { 2676426, Bucket(3883) }, // -41.35, 174.6 x -41.14, 174.8
    { 2676448, 458 }, // -41.35, 174.8 x -41.14, 175
    { 2689229, Bucket(3886) }, // -34.01, 150.9 x -33.8, 151.1
    { 2689231, Bucket(3889) }, // -34.01, 151.1 x -33.8, 151.4
    { 2689240, 3793 }, // -33.8, 150.9 x -33.59, 151.1
    { 2690615, 3736 }, // -28.13, 153.2 x -27.92, 153.4
    { 2690638, Bucket(3892) }, // -27.5, 152.8 x -27.3, 153
    { 2690660, Bucket(3892) }, // -27.5, 153 x -27.3, 153.2
    { 1028415, 3647 }, // -0.3468, -78.6 x -0.2419, -78.5
    { 1028458, 3647 }, // -0.2419, -78.6 x -0.137, -78.5
    { 1028501, 3647 }, // -0.3468, -78.5 x -0.2419, -78.39
    { 1028544, 3647 }, // -0.2419, -78.5 x -0.137, -78.39
    { 1042715, 1108 }, // 6.154, -75.67 x 6.259, -75.56
    { 1620607, Bucket(3895) }, // 25.66, -100.4 x 25.76, -100.3
    { 1620693, Bucket(3895) }, // 25.66, -100.3 x 25.76, -100.2
    { 1622465, 1441 }, // 33.42, -112.1 x 33.52, -111.9
    { 1626582, 2522 }, // 40.65, -111.9 x 40.76, -111.8
    { 1634715, 2513 }, // 39.71, -105 x 39.81, -104.9
    { 1639162, 206 }, // 45.48, -123.1 x 45.58, -123
    { 1640536, Bucket(3899) }, // 45.48, -122.7 x 45.58, -122.6
    { 1641514, 2839 }, // 47.57, -122.2 x 47.68, -122.1
    { 1653704, 3751 }, // 53.45, -113.5 x 53.55, -113.4
    { 1718167, Bucket(3903) }, // 29.85, -90.14 x 29.96, -90.03
    { 1718210, Bucket(3906) }, // 29.96, -90.14 x 30.06, -90.03
    { 1735915, 1029 }, // 41.81, -87.83 x 41.91, -87.73
    { 1735916, 2467 }, // 41.91, -87.94 x 42.02, -87.83
    { 1736257, 1029 }, // 41.81, -87.73 x 41.91, -87.62
    { 1736261, 992 }, // 42.02, -87.73 x 42.12, -87.62
    { 1743890, 3056 }, // 27.86, -82.59 x 27.96, -82.48
    { 1743891, 3056 }, // 27.96, -82.59 x 28.07, -82.48
    { 1753594, Bucket(3909) }, // 33.73, -84.47 x 33.84, -84.37
    { 1753936, 1418 }, // 33.73, -84.37 x 33.84, -84.27
    { 1756742, 3215 }, // 35.2, -80.91 x 35.3, -80.8
    { 1758961, 3266 }, // 42.23, -83.11 x 42.33, -83.01
    { 1758964, 3266 }, // 42.33, -83.11 x 42.44, -83.01
    { 1761262, Bucket(3912) }, // 43.59, -79.44 x 43.69, -79.34
    { 1761263, 239 }, // 43.69, -79.44 x 43.8, -79.34
    { 1766103, 2826 }, // 39.08, -76.72 x 39.18, -76.61
    { 1766693, 3099 }, // 42.85, -78.92 x 42.96, -78.81
    { 1766724, Bucket(3916) }, // 43.59, -79.34 x 43.69, -79.23
    { 1767743, Bucket(3919) }, // 39.92, -75.25 x 40.02, -75.14
    { 1767786, Bucket(3927) }, // 40.02, -75.25 x 40.13, -75.14
    { 1767829, Bucket(3931) }, // 39.92, -75.14 x 40.02, -75.04
    { 1767872, 512 }, // 40.02, -75.14 x 40.13, -75.04
    { 1768305, 2220 }, // 40.55, -73.88 x 40.65, -73.78
    { 1813112, 1194 }, // 45.48, -73.67 x 45.58, -73.57
    { 2372011, 3371 }, // -27.82, -64.34 x -27.71, -64.24
    { 2392191, Bucket(3934) }, // -34.74, -58.47 x -34.64, -58.37
    { 2392362, Bucket(3937) }, // -34.64, -58.47 x -34.53, -58.37
    { 2408299, 1303 }, // -23.63, -46.73 x -23.52, -46.62
    { 2408345, 1893 }, // -24.04, -46.41 x -23.94, -46.31
    { 2408385, 1303 }, // -23.63, -46.62 x -23.52, -46.52
    { 2442711, 2064 }, // 10.56, -71.68 x 10.66, -71.58
    { 2444773, 2004 }, // 10.14, -68.01 x 10.24, -67.91
    { 2496469, Bucket(3940) }, // -23, -43.27 x -22.89, -43.16
    { 2507278, 2820 }, // -22.68, -43.79 x -22.58, -43.69
    { 2507300, 2820 }, // -22.68, -43.69 x -22.58, -43.58
    { 2557665, 2976 }, // -5.17, -42.85 x -5.065, -42.74
    { 3007285, 3643 }, // 6.364, 3.291 x 6.469, 3.396
    { 3007328, 3643 }, // 6.469, 3.291 x 6.574, 3.396
    { 3055274, 3018 }, // -26.25, 27.93 x -26.14, 28.04
    { 3060053, 3017 }, // -26.35, 28.04 x -26.25, 28.14
    { 3060736, 3016 }, // -26.25, 28.04 x -26.14, 28.14
    { 3167481, 3096 }, // 42.23, -71.16 x 42.33, -71.05
    { 3167484, 3098 }, // 42.33, -71.16 x 42.44, -71.05
    { 3697124, 3898 }, // 33.52, -7.614 x 33.63, -7.509
    { 3698582, 3131 }, // 36.46, -6.251 x 36.56, -6.146
    { 3698654, 124 }, // 37.3, -6.041 x 37.4, -5.936
    { 3699431, Bucket(3943) }, // 38.66, -9.187 x 38.77, -9.082
    { 3699442, 2069 }, // 38.77, -9.187 x 38.87, -9.082
    { 3723759, 2174 }, // 40.34, -3.944 x 40.44, -3.839
    { 3723780, 2289 }, // 37.72, -3.839 x 37.82, -3.734
    { 3724101, Bucket(3949) }, // 40.34, -3.839 x 40.44, -3.734
    { 3724103, Bucket(3952) }, // 40.34, -3.734 x 40.44, -3.63
    { 3724112, 2173 }, // 40.44, -3.839 x 40.55, -3.734
    { 3724114, Bucket(3955) }, // 40.44, -3.734 x 40.55, -3.63
    { 3724778, 1360 }, // 43.38, -3.944 x 43.48, -3.839
    { 3725120, 3185 }, // 43.38, -3.839 x 43.48, -3.734
    { 3725204, 2526 }, // 43.17, -3 x 43.27, -2.896
    { 3725205, 3295 }, // 43.27, -3 x 43.38, -2.896
    { 3725248, 1872 }, // 43.38, -3 x 43.48, -2.896
    { 3725458, 2252 }, // 37.93, -1.218 x 38.03, -1.113
    { 3725546, 285 }, // 38.35, -0.5886 x 38.45, -0.4838
    { 3725845, 3482 }, // 38.24, -0.4838 x 38.35, -0.3789
    { 3725888, Bucket(3958) }, // 38.35, -0.4838 x 38.45, -0.3789
    { 3726086, Bucket(3962) }, // 39.39, -0.3789 x 39.5, -0.2741
    { 3726495, 462 }, // 41.6, -1.008 x 41.7, -0.9032
    { 3726517, 462 }, // 41.6, -0.9032 x 41.7, -0.7984
    { 3727022, 1688 }, // 41.07, 1.089 x 41.18, 1.194
    { 3732484, 1688 }, // 41.07, 1.194 x 41.18, 1.299
    { 3732501, 3800 }, // 41.6, 1.194 x 41.7, 1.299
    { 3732624, 1708 }, // 41.28, 2.033 x 41.39, 2.138
    { 3732627, Bucket(3965) }, // 41.39, 2.138 x 41.49, 2.243
    { 3733446, 3496 }, // 43.59, 3.815 x 43.69, 3.92
    { 3734847, 261 }, // 43.27, 5.283 x 43.38, 5.388
    { 3734873, 2854 }, // 43.9, 4.759 x 44.01, 4.864
    { 3734933, Bucket(3971) }, // 43.27, 5.388 x 43.38, 5.493
    { 3770738, 789 }, // 47.15, -1.637 x 47.26, -1.532
    { 3771949, Bucket(3974) }, // 47.89, 0.1454 x 47.99, 0.2502
    { 3771960, Bucket(3974) }, // 47.99, 0.1454 x 48.1, 0.2502
    { 3771991, Bucket(3977) }, // 49.15, -0.3789 x 49.25, -0.2741
    { 3772198, 1290 }, // 49.46, 0.0405 x 49.57, 0.1454
    { 3773295, 3847 }, // 53.76, -3.105 x 53.86, -3
    { 3773416, 3064 }, // 53.45, -2.371 x 53.55, -2.266
    { 3773663, 1768 }, // 55.86, -4.364 x 55.96, -4.259
    { 3774784, Bucket(3980) }, // 53.45, -2.162 x 53.55, -2.057
    { 3775003, Bucket(3983) }, // 51.45, -0.1692 x 51.56, -0.06436
    { 3775025, Bucket(3986) }, // 51.45, -0.06436 x 51.56, 0.0405
    { 3777261, Bucket(3989) }, // 45.37, 4.34 x 45.48, 4.445
    { 3777272, 394 }, // 45.48, 4.34 x 45.58, 4.445
    { 3777741, 3488 }, // 48.73, 2.243 x 48.83, 2.347
    { 3777743, 3304 }, // 48.73, 2.347 x 48.83, 2.452
    { 3777754, Bucket(3993) }, // 48.83, 2.347 x 48.94, 2.452
    { 3778551, Bucket(3996) }, // 50.82, 4.235 x 50.93, 4.34
    { 3778557, Bucket(3999) }, // 50.82, 4.34 x 50.93, 4.445
    { 3778652, 1310 }, // 45.69, 4.759 x 45.79, 4.864
    { 3778654, 1004 }, // 45.69, 4.864 x 45.79, 4.969
    { 3778763, 1338 }, // 45.16, 5.703 x 45.27, 5.808
    { 3778990, Bucket(4003) }, // 46.11, 6.122 x 46.21, 6.227
    { 3779255, Bucket(4006) }, // 44.95, 7.59 x 45.06, 7.695
    { 3779298, Bucket(4009) }, // 45.06, 7.59 x 45.16, 7.695
    { 3779379, 2140 }, // 46.42, 6.751 x 46.52, 6.856
    { 3779477, 3046 }, // 46.63, 7.066 x 46.73, 7.171
    { 3779531, 1363 }, // 46.84, 7.381 x 46.94, 7.485
    { 3779533, 3831 }, // 47.05, 7.276 x 47.15, 7.381
    { 3779534, 1363 }, // 46.94, 7.381 x 47.05, 7.485
    { 3779553, 1353 }, // 46.84, 7.485 x 46.94, 7.59
    { 3779556, 1353 }, // 46.94, 7.485 x 47.05, 7.59
    { 3779571, 3604 }, // 47.26, 7.59 x 47.36, 7.695
    { 3779575, 3138 }, // 47.47, 7.59 x 47.57, 7.695
    { 3779577, 3604 }, // 47.26, 7.695 x 47.36, 7.8
    { 3779822, 764 }, // 48.62, 6.122 x 48.73, 6.227
    { 3780233, Bucket(4013) }, // 47.68, 7.276 x 47.78, 7.381
    { 3780271, Bucket(4016) }, // 47.89, 7.8 x 47.99, 7.905
    { 3780282, Bucket(4019) }, // 47.99, 7.8 x 48.1, 7.905
    { 3780329, Bucket(4023) }, // 48.52, 7.695 x 48.62, 7.8
    { 3780564, 131 }, // 50.72, 7.066 x 50.82, 7.171
    { 3781292, 1259 }, // 51.14, 4.34 x 51.24, 4.445
    { 3781350, 1745 }, // 51.98, 4.235 x 52.08, 4.34
    { 3781355, Bucket(4027) }, // 51.87, 4.445 x 51.98, 4.549
    { 3782721, Bucket(4032) }, // 51.87, 4.549 x 51.98, 4.654
    { 3782745, 3746 }, // 52.29, 4.759 x 52.4, 4.864
    { 3782747, Bucket(4036) }, // 52.29, 4.864 x 52.4, 4.969
    { 3783183, Bucket(4042) }, // 51.24, 6.542 x 51.35, 6.647
    { 3783194, Bucket(4042) }, // 51.35, 6.542 x 51.45, 6.647
    { 3783208, Bucket(4045) }, // 50.93, 6.856 x 51.03, 6.961
    { 3783323, Bucket(4048) }, // 51.45, 7.381 x 51.56, 7.485
    { 3819363, Bucket(4053) }, // 36.77, 10.11 x 36.88, 10.21
    { 3821962, 1561 }, // 39.18, 9.058 x 39.29, 9.163
    { 3823599, Bucket(4057) }, // 43.69, 11.16 x 43.8, 11.26
    { 3823610, Bucket(4057) }, // 43.8, 11.16 x 43.9, 11.26
    { 3823615, 1629 }, // 44.11, 11.16 x 44.22, 11.26
    { 3824155, Bucket(4060) }, // 38.03, 13.25 x 38.14, 13.36
    { 3824177, 1677 }, // 38.03, 13.36 x 38.14, 13.46
    { 3824629, Bucket(4063) }, // 40.76, 14.2 x 40.86, 14.3
    { 3824843, 809 }, // 41.81, 12.41 x 41.91, 12.52
    { 3824846, Bucket(4066) }, // 41.91, 12.41 x 42.02, 12.52
    { 3824865, 816 }, // 41.81, 12.52 x 41.91, 12.62
    { 3824981, 1627 }, // 44.11, 11.26 x 44.22, 11.37
    { 3825312, 3276 }, // 40.86, 14.2 x 40.97, 14.3
    { 3829792, 2005 }, // 37.51, 15.04 x 37.61, 15.14
    { 3830101, 3679 }, // 40.76, 14.62 x 40.86, 14.72
    { 3830784, 3767 }, // 40.86, 14.62 x 40.97, 14.72
    { 3833178, 2603 }, // 43.8, 18.29 x 43.9, 18.39
    { 3833200, 2603 }, // 43.8, 18.39 x 43.9, 18.5
    { 3854843, Bucket(4069) }, // 40.55, 22.9 x 40.65, 23
    { 3856139, Bucket(4072) }, // 42.64, 23.32 x 42.75, 23.42
    { 3857001, 3794 }, // 38.45, 26.99 x 38.56, 27.09
    { 3860419, 3204 }, // 36.77, 30.66 x 36.88, 30.76
    { 3860422, 3204 }, // 36.88, 30.66 x 36.98, 30.76
    { 3863355, Bucket(4075) }, // 39.71, 30.45 x 39.81, 30.55
    { 3863441, Bucket(4080) }, // 39.71, 30.55 x 39.81, 30.66
    { 3863595, Bucket(4084) }, // 40.97, 28.77 x 41.07, 28.88
    { 3863681, Bucket(4087) }, // 40.97, 28.88 x 41.07, 28.98
    { 3863686, 2038 }, // 41.07, 28.98 x 41.18, 29.09
    { 3866853, Bucket(4090) }, // 45.37, 9.163 x 45.48, 9.268
    { 3866864, Bucket(4096) }, // 45.48, 9.163 x 45.58, 9.268
    { 3866968, 235 }, // 47.15, 8.115 x 47.26, 8.219
    { 3866971, 579 }, // 47.26, 8.219 x 47.36, 8.324
    { 3866975, 2436 }, // 47.47, 8.219 x 47.57, 8.324
    { 3866993, 2765 }, // 47.26, 8.324 x 47.36, 8.429
    { 3866994, 2453 }, // 47.15, 8.429 x 47.26, 8.534
    { 3866995, 2453 }, // 47.26, 8.429 x 47.36, 8.534
    { 3866996, 2765 }, // 47.36, 8.324 x 47.47, 8.429
    { 3867004, Bucket(4101) }, // 47.36, 8.534 x 47.47, 8.639
    { 3867007, Bucket(4104) }, // 47.47, 8.639 x 47.57, 8.744
    { 3867089, 1809 }, // 47.26, 8.744 x 47.36, 8.849
    { 3867092, Bucket(4107) }, // 47.36, 8.744 x 47.47, 8.849
    { 3867093, 2438 }, // 47.47, 8.744 x 47.57, 8.849
    { 3867096, 3031 }, // 47.15, 8.953 x 47.26, 9.058
    { 3867097, 3031 }, // 47.26, 8.953 x 47.36, 9.058
    { 3867100, 3031 }, // 47.36, 8.953 x 47.47, 9.058
    { 3867103, Bucket(4110) }, // 47.47, 9.058 x 47.57, 9.163
    { 3867126, 3117 }, // 47.36, 9.268 x 47.47, 9.373
    { 3867130, 3778 }, // 47.15, 9.478 x 47.26, 9.583
    { 3867256, 1061 }, // 45.48, 10.21 x 45.58, 10.32
    { 3867460, 3656 }, // 46.94, 9.583 x 47.05, 9.687
    { 3867461, 3076 }, // 47.05, 9.583 x 47.15, 9.687
    { 3867463, 3076 }, // 47.05, 9.687 x 47.15, 9.792
    { 3867472, 3778 }, // 47.15, 9.583 x 47.26, 9.687
    { 3867658, 2436 }, // 47.57, 8.219 x 47.68, 8.324
    { 3867690, 2463 }, // 47.57, 8.639 x 47.68, 8.744
    { 3867763, 26 }, // 48.94, 8.429 x 49.04, 8.534
    { 3867772, 1408 }, // 49.04, 8.534 x 49.15, 8.639
    { 3867775, 487 }, // 49.15, 8.639 x 49.25, 8.744
    { 3867855, Bucket(4114) }, // 48.73, 9.058 x 48.83, 9.163
    { 3867865, 854 }, // 48.94, 8.953 x 49.04, 9.058
    { 3867866, 197 }, // 48.83, 9.058 x 48.94, 9.163
    { 3867877, Bucket(4117) }, // 48.73, 9.163 x 48.83, 9.268
    { 3867888, Bucket(4122) }, // 48.83, 9.163 x 48.94, 9.268
    { 3867890, 197 }, // 48.83, 9.268 x 48.94, 9.373
    { 3867896, 197 }, // 48.83, 9.373 x 48.94, 9.478
    { 3867935, 1251 }, // 49.98, 8.219 x 50.09, 8.324
    { 3867942, 3732 }, // 49.46, 8.429 x 49.57, 8.534
    { 3867947, Bucket(4125) }, // 49.36, 8.639 x 49.46, 8.744
    { 3867954, 3730 }, // 49.67, 8.429 x 49.78, 8.534
    { 3867963, 1585 }, // 49.78, 8.639 x 49.88, 8.744
    { 3867967, 697 }, // 49.98, 8.639 x 50.09, 8.744
    { 3868010, Bucket(4128) }, // 50.09, 8.639 x 50.19, 8.744
    { 3868053, 1251 }, // 49.98, 8.744 x 50.09, 8.849
    { 3868096, Bucket(4133) }, // 50.09, 8.744 x 50.19, 8.849
    { 3868191, 1879 }, // 48.31, 9.897 x 48.41, 10
    { 3868234, 1879 }, // 48.41, 9.897 x 48.52, 10
    { 3868319, 403 }, // 48.31, 10.74 x 48.41, 10.84
    { 3868341, Bucket(4137) }, // 48.31, 10.84 x 48.41, 10.95
    { 3868585, Bucket(4143) }, // 49.36, 11.05 x 49.46, 11.16
    { 3868637, 931 }, // 50.82, 10.63 x 50.93, 10.74
    { 3868676, 1630 }, // 44.43, 11.26 x 44.53, 11.37
    { 3869010, 234 }, // 47.15, 11.37 x 47.26, 11.47
    { 3869721, Bucket(4146) }, // 48.1, 11.47 x 48.2, 11.57
    { 3869723, 3434 }, // 48.1, 11.57 x 48.2, 11.68
    { 3869824, 3181 }, // 47.57, 12.1 x 47.68, 12.2
    { 3869871, 2388 }, // 47.89, 12.83 x 47.99, 12.94
    { 3869882, 2388 }, // 47.99, 12.83 x 48.1, 12.94
    { 3869953, 231 }, // 49.36, 11.26 x 49.46, 11.37
    { 3870047, Bucket(4150) }, // 50.82, 11.57 x 50.93, 11.68
    { 3870079, Bucket(4153) }, // 50.82, 11.99 x 50.93, 12.1
    { 3870149, Bucket(4156) }, // 50.4, 12.1 x 50.51, 12.2
    { 3870160, Bucket(4156) }, // 50.51, 12.1 x 50.61, 12.2
    { 3870165, 232 }, // 50.82, 12.1 x 50.93, 12.2
    { 3870171, 1628 }, // 50.61, 12.41 x 50.72, 12.52
    { 3870174, 1628 }, // 50.72, 12.41 x 50.82, 12.52
    { 3870653, Bucket(4161) }, // 49.98, 14.41 x 50.09, 14.51
    { 3870696, Bucket(4167) }, // 50.09, 14.41 x 50.19, 14.51
    { 3870709, 1733 }, // 50.82, 14.2 x 50.93, 14.3
    { 3870822, 776 }, // 51.98, 8.429 x 52.08, 8.534
    { 3870828, 776 }, // 51.98, 8.534 x 52.08, 8.639
    { 3870893, 2387 }, // 51.24, 9.373 x 51.35, 9.478
    { 3871034, 422 }, // 53.03, 8.639 x 53.13, 8.744
    { 3871120, Bucket(4172) }, // 53.03, 8.744 x 53.13, 8.849
    { 3871315, Bucket(4175) }, // 52.29, 9.687 x 52.4, 9.792
    { 3871368, Bucket(4178) }, // 50.93, 10.63 x 51.03, 10.74
    { 3871387, Bucket(4181) }, // 51.45, 10.74 x 51.56, 10.84
    { 3871394, Bucket(4184) }, // 50.93, 10.95 x 51.03, 11.05
    { 3872366, 2762 }, // 55.33, 10.32 x 55.44, 10.42
    { 3872452, 2762 }, // 55.33, 10.42 x 55.44, 10.53
    { 3872825, Bucket(4188) }, // 51.45, 11.89 x 51.56, 11.99
    { 3872847, Bucket(4193) }, // 52.08, 11.57 x 52.19, 11.68
    { 3872909, Bucket(4199) }, // 51.24, 12.31 x 51.35, 12.41
    { 3872920, 111 }, // 51.35, 12.31 x 51.45, 12.41
    { 3872938, 1890 }, // 50.93, 12.83 x 51.03, 12.94
    { 3872962, 1399 }, // 51.77, 12.2 x 51.87, 12.31
    { 3873091, 156 }, // 53.55, 11.37 x 53.65, 11.47
    { 3873150, Bucket(4203) }, // 54.07, 11.99 x 54.18, 12.1
    { 3873236, Bucket(4206) }, // 54.07, 12.1 x 54.18, 12.2
    { 3873280, 1890 }, // 50.93, 12.94 x 51.03, 13.04
    { 3873323, Bucket(4210) }, // 51.03, 13.67 x 51.14, 13.78
    { 3873397, Bucket(4213) }, // 52.5, 13.36 x 52.61, 13.46
    { 3873406, 842 }, // 52.4, 13.67 x 52.5, 13.78
    { 3873463, 584 }, // 51.66, 14.3 x 51.77, 14.41
    { 3873493, 228 }, // 52.5, 13.78 x 52.61, 13.88
    { 3873727, Bucket(4216) }, // 53.34, 14.51 x 53.45, 14.62
    { 3873770, Bucket(4216) }, // 53.45, 14.51 x 53.55, 14.62
    { 3874011, 366 }, // 55.65, 12.41 x 55.75, 12.52
    { 3874014, 2846 }, // 55.75, 12.41 x 55.86, 12.52
    { 3874033, Bucket(4220) }, // 55.65, 12.52 x 55.75, 12.62
    { 3874036, 2846 }, // 55.75, 12.52 x 55.86, 12.62
    { 3874393, 3224 }, // 55.65, 13.15 x 55.75, 13.25
    { 3875061, 1652 }, // 45.79, 15.87 x 45.9, 15.98
    { 3875063, 1652 }, // 45.79, 15.98 x 45.9, 16.08
    { 3875183, Bucket(4223) }, // 47.05, 15.35 x 47.15, 15.45
    { 3875269, Bucket(4227) }, // 47.05, 15.45 x 47.15, 15.56
    { 3876027, 78 }, // 48.1, 16.19 x 48.2, 16.29
    { 3876190, Bucket(4230) }, // 50.72, 14.93 x 50.82, 15.04
    { 3876212, Bucket(4233) }, // 50.72, 15.04 x 50.82, 15.14
    { 3876369, Bucket(4237) }, // 48.1, 16.29 x 48.2, 16.4
    { 3876372, Bucket(4240) }, // 48.2, 16.29 x 48.31, 16.4
    { 3876411, Bucket(4249) }, // 48.1, 17.03 x 48.2, 17.13
    { 3876497, Bucket(4250) }, // 48.1, 17.13 x 48.2, 17.24
    { 3876783, Bucket(4253) }, // 49.57, 17.87 x 49.67, 17.97
    { 3876794, 3567 }, // 49.67, 17.87 x 49.78, 17.97
    { 3876798, 3908 }, // 49.88, 17.87 x 49.98, 17.97
    { 3877340, 605 }, // 47.36, 19.02 x 47.47, 19.12
    { 3877341, Bucket(4256) }, // 47.47, 19.02 x 47.57, 19.12
    { 3877342, 596 }, // 47.36, 19.12 x 47.47, 19.23
    { 3877435, Bucket(4264) }, // 44.74, 20.38 x 44.85, 20.49
    { 3877521, Bucket(4270) }, // 44.74, 20.49 x 44.85, 20.59
    { 3877669, Bucket(4276) }, // 46.21, 20.07 x 46.31, 20.17
    { 3877806, Bucket(4282) }, // 46.11, 21.22 x 46.21, 21.33
    { 3878024, Bucket(4286) }, // 47.57, 19.02 x 47.68, 19.12
    { 3878149, 3571 }, // 49.57, 17.97 x 49.67, 18.08
    { 3878160, 3568 }, // 49.67, 17.97 x 49.78, 18.08
    { 3878638, 2316 }, // 48.62, 21.22 x 48.73, 21.33
    { 3878685, Bucket(4289) }, // 49.98, 19.86 x 50.09, 19.96
    { 3878687, 1170 }, // 49.98, 19.96 x 50.09, 20.07
    { 3878730, 1170 }, // 50.09, 19.96 x 50.19, 20.07
    { 3879189, Bucket(4293) }, // 53.34, 14.62 x 53.45, 14.72
    { 3879203, 431 }, // 52.71, 15.14 x 52.82, 15.24
    { 3879467, 866 }, // 51.03, 17.03 x 51.14, 17.13
    { 3881149, 2665 }, // 51.66, 19.44 x 51.77, 19.54
    { 3881192, 2665 }, // 51.77, 19.44 x 51.87, 19.54
    { 3881322, Bucket(4297) }, // 53.45, 18.71 x 53.55, 18.81
    { 3881712, 1374 }, // 52.19, 20.91 x 52.29, 21.01
    { 3885096, 874 }, // 57.64, 11.89 x 57.74, 11.99
    { 3892138, Bucket(4300) }, // 59.32, 17.87 x 59.42, 17.97
    { 3893504, Bucket(4305) }, // 59.32, 17.97 x 59.42, 18.08
    { 3899652, 3396 }, // 46.11, 21.33 x 46.21, 21.43
    { 3899741, Bucket(4308) }, // 47.47, 21.54 x 47.57, 21.64
    { 3899751, Bucket(4311) }, // 47.05, 21.85 x 47.15, 21.96
    { 3900258, 1641 }, // 46.73, 23.53 x 46.84, 23.63
    { 3901331, Bucket(4314) }, // 49.78, 23.95 x 49.88, 24.05
    { 3901603, Bucket(4318) }, // 44.32, 26.05 x 44.43, 26.15
    { 3901606, Bucket(4322) }, // 44.43, 26.05 x 44.53, 26.15
    { 3902191, Bucket(4325) }, // 45.37, 27.93 x 45.48, 28.04
    { 3902415, Bucket(4328) }, // 47.05, 27.51 x 47.15, 27.62
    { 3902426, Bucket(4332) }, // 47.15, 27.51 x 47.26, 27.62
    { 3905481, 3093 }, // 56.91, 24.05 x 57.01, 24.16
    { 3906522, Bucket(4337) }, // 53.86, 27.51 x 53.97, 27.62
    { 3906544, Bucket(4337) }, // 53.86, 27.62 x 53.97, 27.72
    { 3907159, Bucket(4340) }, // 55.86, 26.46 x 55.96, 26.57
    { 3907653, 348 }, // 45.37, 28.04 x 45.48, 28.14
    { 3909485, 660 }, // 50.4, 30.34 x 50.51, 30.45
    { 3909487, Bucket(4343) }, // 50.4, 30.45 x 50.51, 30.55
    { 3909498, Bucket(4348) }, // 50.51, 30.45 x 50.61, 30.55
    { 3909573, Bucket(4351) }, // 50.4, 30.55 x 50.51, 30.66
    { 3909584, Bucket(4351) }, // 50.51, 30.55 x 50.61, 30.66
    { 3911180, 3128 }, // 47.78, 33.28 x 47.89, 33.39
    { 3911183, 2908 }, // 47.89, 33.39 x 47.99, 33.49
    { 3913290, Bucket(4355) }, // 55.12, 30.03 x 55.23, 30.13
    { 3913312, Bucket(4355) }, // 55.12, 30.13 x 55.23, 30.24
    { 3917370, 3314 }, // 61.41, 23.74 x 61.52, 23.84
    { 3917456, 3314 }, // 61.41, 23.84 x 61.52, 23.95
    { 3917909, 3505 }, // 59.21, 24.68 x 59.32, 24.79
    { 3918081, 661 }, // 59.42, 24.68 x 59.53, 24.79
    { 3918109, Bucket(4358) }, // 60.05, 24.89 x 60.16, 25
    { 3918152, Bucket(4365) }, // 60.16, 24.89 x 60.26, 25
    { 3924787, 679 }, // 59.84, 30.24 x 59.95, 30.34
    { 3924792, 1022 }, // 59.74, 30.34 x 59.84, 30.45
    { 3924793, 3618 }, // 59.84, 30.34 x 59.95, 30.45
    { 3924796, Bucket(4377) }, // 59.95, 30.34 x 60.05, 30.45
    { 9276245, 3021 }, // -6.219, 106.9 x -6.114, 107
    { 9453665, 1052 }, // 31.74, 35.17 x 31.84, 35.27
    { 9455557, 3603 }, // 36.98, 37.26 x 37.09, 37.37
    { 9455568, 3603 }, // 37.09, 37.26 x 37.19, 37.37
    { 9457775, Bucket(4381) }, // 38.66, 35.48 x 38.77, 35.59
    { 9467390, Bucket(4385) }, // 44.01, 43.03 x 44.11, 43.14
    { 9467626, Bucket(4388) }, // 41.7, 44.71 x 41.81, 44.81
    { 9468949, 2110 }, // 41.6, 44.81 x 41.7, 44.92
    { 9468992, 2110 }, // 41.7, 44.81 x 41.81, 44.92
    { 9474799, 2878 }, // 25.24, 51.42 x 25.34, 51.53
    { 9474810, Bucket(4391) }, // 25.34, 51.42 x 25.45, 51.53
    { 9476165, 2899 }, // 25.24, 51.53 x 25.34, 51.63
    { 9476176, Bucket(4391) }, // 25.34, 51.53 x 25.45, 51.63
    { 9477522, 3607 }, // 29.54, 52.47 x 29.64, 52.57
    { 9490927, Bucket(4394) }, // 40.34, 49.74 x 40.44, 49.85
    { 9503693, 2733 }, // 47.05, 37.47 x 47.15, 37.58
    { 9503695, 3051 }, // 47.05, 37.58 x 47.15, 37.68
    { 9503773, Bucket(4398) }, // 48.31, 34.96 x 48.41, 35.06
    { 9503816, Bucket(4401) }, // 48.41, 34.96 x 48.52, 35.06
    { 9505146, Bucket(4408) }, // 47.15, 38.84 x 47.26, 38.94
    { 9508566, Bucket(4415) }, // 55.75, 37.37 x 55.86, 37.47
    { 9508571, 1992 }, // 55.65, 37.58 x 55.75, 37.68
    { 9508572, Bucket(4418) }, // 55.75, 37.47 x 55.86, 37.58
    { 9508574, 1186 }, // 55.75, 37.58 x 55.86, 37.68
    { 9508593, 1992 }, // 55.65, 37.68 x 55.75, 37.79
    { 9508596, 1186 }, // 55.75, 37.68 x 55.86, 37.79
    { 9516847, 1993 }, // 56.28, 43.87 x 56.38, 43.98
    { 9516933, Bucket(4422) }, // 56.28, 43.98 x 56.38, 44.08
    { 9517209, 545 }, // 51.45, 45.86 x 51.56, 45.97
    { 9517212, Bucket(4427) }, // 51.56, 45.86 x 51.66, 45.97
    { 9540821, 3490 }, // 55.86, 49.01 x 55.96, 49.11
    { 9543146, Bucket(4430) }, // 56.8, 53.1 x 56.91, 53.2
    { 9543445, 3912 }, // 56.7, 53.2 x 56.8, 53.31
    { 9543488, Bucket(4438) }, // 56.8, 53.2 x 56.91, 53.31
    { 9550143, Bucket(4448) }, // 53.34, 58.97 x 53.45, 59.08
    { 9550186, Bucket(4453) }, // 53.45, 58.97 x 53.55, 59.08
    { 9550229, Bucket(4456) }, // 53.34, 59.08 x 53.45, 59.18
    { 9551677, Bucket(4468) }, // 56.7, 60.54 x 56.8, 60.65
    { 9551720, Bucket(4472) }, // 56.8, 60.54 x 56.91, 60.65
    { 9578743, 3740 }, // 18.95, 73.02 x 19.05, 73.13
    { 9578890, Bucket(4479) }, // 19.05, 72.81 x 19.16, 72.92
    { 9578914, 3740 }, // 19.05, 73.02 x 19.16, 73.13
    { 9598098, 919 }, // 41.28, 69.25 x 41.39, 69.35
    { 9603074, 2421 }, // 17.37, 78.47 x 17.48, 78.58
    { 9613227, 3176 }, // 22.51, 88.33 x 22.62, 88.44
    { 9680031, 2058 }, // 55.02, 82.88 x 55.12, 82.98
    { 9997350, 3252 }, // 20.94, 105.7 x 21.04, 105.8
    { 10000222, 3228 }, // 30.59, 103.8 x 30.69, 104
    { 10000244, 3228 }, // 30.59, 104 x 30.69, 104.1
    { 10000245, 2936 }, // 30.69, 104 x 30.8, 104.1
    { 10005755, 2898 }, // 22.09, 113.5 x 22.2, 113.6
    { 10005942, 2025 }, // 23.04, 113.3 x 23.14, 113.4
    { 10006111, Bucket(4482) }, // 22.3, 113.9 x 22.41, 114
    { 10006134, 1830 }, // 22.2, 114.1 x 22.3, 114.2
    { 10006277, 2684 }, // 22.72, 113.6 x 22.83, 113.7
    { 10006278, 3423 }, // 22.62, 113.7 x 22.72, 113.8
    { 10006282, Bucket(4490) }, // 22.41, 113.9 x 22.51, 114
    { 10006283, 2032 }, // 22.51, 113.9 x 22.62, 114
    { 10006287, 3552 }, // 22.72, 113.9 x 22.83, 114
    { 10006292, 2225 }, // 23.04, 113.6 x 23.14, 113.7
    { 10006296, Bucket(4503) }, // 22.83, 113.8 x 22.93, 113.9
    { 10006304, 1780 }, // 22.41, 114 x 22.51, 114.1
    { 10006308, Bucket(4506) }, // 22.62, 114 x 22.72, 114.1
    { 10019167, 2181 }, // 34.05, 108.9 x 34.15, 109
    { 10019848, 3871 }, // 34.15, 108.8 x 34.26, 108.9
    { 10022075, 2850 }, // 34.68, 113.5 x 34.78, 113.6
    { 10064479, 1064 }, // 52.5, 103.8 x 52.61, 104
    { 10064506, Bucket(4509) }, // 52.19, 104.3 x 52.29, 104.4
    { 10096388, 2202 }, // 22.62, 120.3 x 22.72, 120.4
    { 10099402, 3600 }, // 24.92, 121.5 x 25.03, 121.6
    { 10099404, 1608 }, // 25.13, 121.4 x 25.24, 121.5
    { 10110743, 2944 }, // 36.56, 117.1 x 36.67, 117.2
    { 10110786, 2944 }, // 36.67, 117.1 x 36.77, 117.2
    { 10111157, 2853 }, // 31.53, 119.9 x 31.63, 120
    { 10111167, 2159 }, // 31.53, 120.2 x 31.63, 120.3
    { 10111204, 2853 }, // 31.84, 119.9 x 31.95, 120
    { 10111630, 2399 }, // 31.01, 121.5 x 31.11, 121.6
    { 10121045, 1986 }, // 37.4, 127 x 37.51, 127.1
    { 10123259, 2705 }, // 43.9, 125.2 x 44.01, 125.3
    { 10123358, Bucket(4513) }, // 38.97, 125.7 x 39.08, 125.8
    { 10123380, 3123 }, // 38.97, 125.8 x 39.08, 125.9
    { 10123434, 3040 }, // 37.51, 126.9 x 37.61, 127
    { 10123776, Bucket(4516) }, // 37.51, 127 x 37.61, 127.1
    { 10123780, 1968 }, // 37.72, 127 x 37.82, 127.1
    { 10124624, 2704 }, // 43.8, 125.3 x 43.9, 125.5
    { 10124625, 2705 }, // 43.9, 125.3 x 44.01, 125.5
    { 10142190, Bucket(4519) }, // 33.52, 130.3 x 33.63, 130.4
    { 10142231, Bucket(4522) }, // 31.53, 130.5 x 31.63, 130.6
    { 10142532, Bucket(4519) }, // 33.52, 130.4 x 33.63, 130.5
    { 10142976, Bucket(2648) }, // 35.83, 128.7 x 35.93, 128.8
    { 10145466, 2680 }, // 34.57, 135.3 x 34.68, 135.4
    { 10150928, 2680 }, // 34.57, 135.4 x 34.68, 135.5
    { 10150943, 2344 }, // 34.89, 135.7 x 34.99, 135.8
    { 10150986, 2344 }, // 34.99, 135.7 x 35.1, 135.8
    { 10151145, 2350 }, // 35.1, 136.9 x 35.2, 137
    { 10151147, 2703 }, // 35.1, 137 x 35.2, 137.1
    { 10153083, 2048 }, // 35.51, 139.5 x 35.62, 139.6
    { 10153157, 744 }, // 35.3, 139.6 x 35.41, 139.7
    { 10153168, 2016 }, // 35.41, 139.6 x 35.51, 139.7
    { 10153172, 743 }, // 35.62, 139.6 x 35.72, 139.7
    { 10153175, 2573 }, // 35.72, 139.7 x 35.83, 139.8
    { 10153346, 2586 }, // 35.83, 139.7 x 35.93, 139.8
    { 10157968, 2541 }, // 42.96, 141.3 x 43.06, 141.4
    { 10573707, Bucket(4525) }, // -37.89, 145 x -37.78, 145.1
    { 10706798, 3137 }, // -36.94, 174.7 x -36.84, 174.8
    { 10756919, 2722 }, // -33.9, 151 x -33.8, 151.1
    { 10762554, Bucket(4530) }, // -27.5, 152.9 x -27.4, 153
    { 10762640, Bucket(4530) }, // -27.5, 153 x -27.4, 153.1
    { 3922166, 3774 }, // -12.09, -76.98 x -12.04, -76.92
    { 4170863, 1783 }, // 6.207, -75.61 x 6.259, -75.56
    { 4170949, 1783 }, // 6.207, -75.56 x 6.259, -75.51
    { 6381721, Bucket(4533) }, // 37.77, -122.4 x 37.82, -122.4
    { 6382490, 2571 }, // 38.56, -121.5 x 38.61, -121.5
    { 6393016, 2803 }, // 32.68, -117.2 x 32.74, -117.1
    { 6461986, 1833 }, // 20.73, -103.4 x 20.78, -103.3
    { 6872671, 3270 }, // 29.9, -90.08 x 29.96, -90.03
    { 6872842, 3270 }, // 29.96, -90.08 x 30.01, -90.03
    { 6884885, Bucket(4538) }, // 32.84, -96.95 x 32.89, -96.9
    { 6884889, 1754 }, // 32.74, -96.85 x 32.79, -96.8
    { 6918343, Bucket(4541) }, // 34.73, -92.29 x 34.78, -92.23
    { 6943678, 992 }, // 42.02, -87.78 x 42.07, -87.73
    { 6944481, Bucket(4544) }, // 43.01, -87.94 x 43.06, -87.88
    { 6975585, 3265 }, // 27.91, -82.48 x 27.96, -82.43
    { 7029750, 1378 }, // 39.08, -84.53 x 39.13, -84.47
    { 7045051, 214 }, // 43.64, -79.39 x 43.69, -79.34
    { 7066897, Bucket(4547) }, // 43.64, -79.34 x 43.69, -79.28
    { 7071146, 2279 }, // 40.02, -75.19 x 40.08, -75.14
    { 7073139, 2270 }, // 40.7, -74.04 x 40.76, -73.99
    { 7073144, 2221 }, // 40.65, -73.99 x 40.7, -73.94
    { 7252456, 1192 }, // 45.48, -73.57 x 45.53, -73.52
    { 9568767, 1119 }, // -34.69, -58.42 x -34.64, -58.37
    { 9569134, 1109 }, // -34.95, -58 x -34.9, -57.95
    { 9569220, 1109 }, // -34.95, -57.95 x -34.9, -57.89
    { 9569450, Bucket(4550) }, // -34.64, -58.42 x -34.58, -58.37
    { 9780728, 2007 }, // 10.45, -66.86 x 10.51, -66.81
    { 9780730, 2007 }, // 10.45, -66.81 x 10.51, -66.75
    { 9985879, Bucket(4553) }, // -22.94, -43.21 x -22.89, -43.16
    { 10084346, 3309 }, // -9.679, -35.77 x -9.627, -35.72
    { 10239102, Bucket(4557) }, // -3.702, -40.38 x -3.65, -40.33
    { 12242944, 3017 }, // -26.25, 28.04 x -26.19, 28.09
    { 14703373, 490 }, // 28.44, -16.32 x 28.49, -16.26
    { 14797725, 2070 }, // 38.71, -9.187 x 38.77, -9.135
    { 14797768, 2070 }, // 38.77, -9.187 x 38.82, -9.135
    { 14882592, 2101 }, // 36.67, -4.468 x 36.72, -4.416
    { 14896391, 2288 }, // 40.18, -3.787 x 40.23, -3.734
    { 14896402, 2288 }, // 40.23, -3.787 x 40.29, -3.734
    { 14898943, 1360 }, // 43.33, -3.892 x 43.38, -3.839
    { 14902015, 3760 }, // 38.29, -0.5362 x 38.35, -0.4838
    { 14902186, Bucket(4560) }, // 38.35, -0.5362 x 38.4, -0.4838
    { 14903552, 284 }, // 38.35, -0.4838 x 38.4, -0.4314
    { 14904345, 3481 }, // 39.45, -0.3789 x 39.5, -0.3265
    { 14933786, 1376 }, // 43.59, 3.868 x 43.64, 3.92
    { 14939390, Bucket(4564) }, // 43.27, 5.336 x 43.33, 5.388
    { 14939732, 908 }, // 43.27, 5.388 x 43.33, 5.441
    { 14941982, 2867 }, // 43.69, 7.223 x 43.75, 7.276
    { 14942004, 2867 }, // 43.69, 7.276 x 43.75, 7.328
    { 15087964, 2776 }, // 49.15, -0.3789 x 49.2, -0.3265
    { 15091940, 264 }, // 51.45, -3.21 x 51.51, -3.158
    { 15094740, 1768 }, // 55.86, -4.259 x 55.91, -4.206
    { 15111020, 1844 }, // 48.94, 2.347 x 48.99, 2.4
    { 15111117, 1866 }, // 48.99, 2.557 x 49.04, 2.61
    { 15114203, 3704 }, // 50.77, 4.287 x 50.82, 4.34
    { 15114225, 3704 }, // 50.77, 4.34 x 50.82, 4.392
    { 15114619, 3475 }, // 45.74, 4.916 x 45.79, 4.969
    { 15114705, 3475 }, // 45.74, 4.969 x 45.79, 5.021
    { 15117023, 479 }, // 45, 7.643 x 45.06, 7.695
    { 15118127, 994 }, // 46.89, 7.433 x 46.94, 7.485
    { 15118138, Bucket(4567) }, // 46.94, 7.433 x 47, 7.485
    { 15118257, 3838 }, // 47, 7.695 x 47.05, 7.748
    { 15121911, 120 }, // 50.88, 6.909 x 50.93, 6.961
    { 15287793, 3714 }, // 40.7, 8.534 x 40.76, 8.586
    { 15296623, 1679 }, // 38.08, 13.3 x 38.14, 13.36
    { 15298431, 3202 }, // 40.81, 14.14 x 40.86, 14.2
    { 15298519, 3288 }, // 40.81, 14.25 x 40.86, 14.3
    { 15299375, Bucket(4570) }, // 41.86, 12.47 x 41.91, 12.52
    { 15299461, Bucket(4570) }, // 41.86, 12.52 x 41.91, 12.57
    { 15301250, 3288 }, // 40.86, 14.25 x 40.91, 14.3
    { 15332801, 2604 }, // 43.85, 18.39 x 43.9, 18.44
    { 15419575, 1814 }, // 37.87, 23.69 x 37.93, 23.74
    { 15419618, 1814 }, // 37.93, 23.69 x 37.98, 23.74
    { 15435807, 1937 }, // 31.16, 29.87 x 31.22, 29.92
    { 15435850, 1937 }, // 31.22, 29.87 x 31.27, 29.92
    { 15467327, Bucket(4573) }, // 45.42, 9.111 x 45.48, 9.163
    { 15467370, Bucket(4573) }, // 45.48, 9.111 x 45.53, 9.163
    { 15467413, Bucket(4576) }, // 45.42, 9.163 x 45.48, 9.216
    { 15467456, Bucket(4576) }, // 45.48, 9.163 x 45.53, 9.216
    { 15467850, 578 }, // 47.15, 8.062 x 47.21, 8.115
    { 15467880, 235 }, // 47.15, 8.219 x 47.21, 8.272
    { 15467881, 235 }, // 47.21, 8.219 x 47.26, 8.272
    { 15467882, 235 }, // 47.15, 8.272 x 47.21, 8.324
    { 15467994, 1077 }, // 47.36, 8.482 x 47.42, 8.534
    { 15468016, Bucket(4582) }, // 47.36, 8.534 x 47.42, 8.586
    { 15468376, 2438 }, // 47.36, 8.849 x 47.42, 8.901
    { 15468379, 2995 }, // 47.42, 8.901 x 47.47, 8.953
    { 15468381, 2995 }, // 47.52, 8.849 x 47.57, 8.901
    { 15468382, 2995 }, // 47.47, 8.901 x 47.52, 8.953
    { 15468383, 2995 }, // 47.52, 8.901 x 47.57, 8.953
    { 15468394, 3077 }, // 47.15, 9.111 x 47.21, 9.163
    { 15468395, 3077 }, // 47.21, 9.111 x 47.26, 9.163
    { 15468398, 3077 }, // 47.26, 9.111 x 47.31, 9.163
    { 15468399, 3077 }, // 47.31, 9.111 x 47.36, 9.163
    { 15468410, 3077 }, // 47.36, 9.111 x 47.42, 9.163
    { 15468411, 3077 }, // 47.42, 9.111 x 47.47, 9.163
    { 15468501, 3020 }, // 47.52, 9.163 x 47.57, 9.216
    { 15469848, 3656 }, // 46.94, 9.687 x 47, 9.74
    { 15471096, 1408 }, // 49.04, 8.639 x 49.09, 8.691
    { 15471099, 487 }, // 49.09, 8.691 x 49.15, 8.744
    { 15471469, 854 }, // 48.99, 9.058 x 49.04, 9.111
    { 15471471, 854 }, // 48.99, 9.111 x 49.04, 9.163
    { 15471508, 55 }, // 48.73, 9.163 x 48.78, 9.216
    { 15471556, 197 }, // 48.94, 9.163 x 48.99, 9.216
    { 15471557, 854 }, // 48.99, 9.163 x 49.04, 9.216
    { 15471558, 197 }, // 48.94, 9.216 x 48.99, 9.268
    { 15471559, 854 }, // 48.99, 9.216 x 49.04, 9.268
    { 15471564, 197 }, // 48.94, 9.268 x 48.99, 9.32
    { 15471565, 854 }, // 48.99, 9.268 x 49.04, 9.32
    { 15471566, 197 }, // 48.94, 9.32 x 48.99, 9.373
    { 15471567, 854 }, // 48.99, 9.32 x 49.04, 9.373
    { 15471588, 197 }, // 48.94, 9.373 x 48.99, 9.425
    { 15471589, 854 }, // 48.99, 9.373 x 49.04, 9.425
    { 15471591, 854 }, // 48.99, 9.425 x 49.04, 9.478
    { 15471597, 854 }, // 48.99, 9.478 x 49.04, 9.53
    { 15471740, 1994 }, // 49.98, 8.219 x 50.04, 8.272
    { 15471840, 532 }, // 49.67, 8.534 x 49.72, 8.586
    { 15471869, 696 }, // 50.04, 8.639 x 50.09, 8.691
    { 15472040, 696 }, // 50.09, 8.639 x 50.14, 8.691
    { 15472384, 687 }, // 50.09, 8.744 x 50.14, 8.796
    { 15472767, 1880 }, // 48.36, 9.95 x 48.41, 10
    { 15472853, 1880 }, // 48.36, 10 x 48.41, 10.05
    { 15472938, 1880 }, // 48.41, 9.95 x 48.46, 10
    { 15473024, 1880 }, // 48.41, 10 x 48.46, 10.05
    { 15474341, 2460 }, // 49.41, 11.05 x 49.46, 11.1
    { 15475485, 960 }, // 45.42, 12.2 x 45.48, 12.26
    { 15475528, 960 }, // 45.48, 12.2 x 45.53, 12.26
    { 15478892, 3432 }, // 48.1, 11.57 x 48.15, 11.63
    { 15478893, 194 }, // 48.15, 11.57 x 48.2, 11.63
    { 15480189, Bucket(4585) }, // 50.88, 11.57 x 50.93, 11.63
    { 15480318, 847 }, // 50.82, 12.05 x 50.88, 12.1
    { 15480597, 1140 }, // 50.46, 12.1 x 50.51, 12.15
    { 15480773, 1628 }, // 50.67, 12.52 x 50.72, 12.57
    { 15482295, 3526 }, // 50.46, 13.62 x 50.51, 13.67
    { 15482338, 3526 }, // 50.51, 13.62 x 50.56, 13.67
    { 15485474, 932 }, // 50.93, 10.68 x 50.98, 10.74
    { 15485838, 1358 }, // 51.87, 11 x 51.92, 11.05
    { 15485860, 1358 }, // 51.87, 11.05 x 51.92, 11.1
    { 15491112, Bucket(4585) }, // 50.93, 11.57 x 50.98, 11.63
    { 15491224, 1114 }, // 51.14, 11.78 x 51.19, 11.84
    { 15491639, 3855 }, // 51.3, 12.36 x 51.35, 12.41
    { 15491682, 3855 }, // 51.35, 12.36 x 51.4, 12.41
    { 15491754, 1891 }, // 50.93, 12.89 x 50.98, 12.94
    { 15491962, Bucket(4589) }, // 52.4, 12.47 x 52.45, 12.52
    { 15492048, Bucket(4589) }, // 52.4, 12.52 x 52.45, 12.57
    { 15492602, 71 }, // 54.07, 12.05 x 54.13, 12.1
    { 15493636, Bucket(4592) }, // 51.03, 13.78 x 51.09, 13.83
    { 15493853, Bucket(4595) }, // 51.72, 14.3 x 51.77, 14.35
    { 15494024, Bucket(4599) }, // 51.77, 14.3 x 51.82, 14.35
    { 15494124, 289 }, // 52.29, 14.51 x 52.34, 14.56
    { 15494909, Bucket(4602) }, // 53.39, 14.51 x 53.45, 14.56
    { 15495080, 763 }, // 53.45, 14.51 x 53.5, 14.56
    { 15500734, 418 }, // 47.05, 15.4 x 47.1, 15.45
    { 15501076, Bucket(4605) }, // 47.05, 15.45 x 47.1, 15.51
    { 15504111, 159 }, // 48.15, 16.24 x 48.2, 16.29
    { 15504122, 103 }, // 48.2, 16.24 x 48.25, 16.29
    { 15505477, 69 }, // 48.15, 16.29 x 48.2, 16.35
    { 15505479, 3339 }, // 48.15, 16.35 x 48.2, 16.4
    { 15505488, 68 }, // 48.2, 16.29 x 48.25, 16.35
    { 15505490, Bucket(4608) }, // 48.2, 16.35 x 48.25, 16.4
    { 15506972, Bucket(4611) }, // 49.57, 17.24 x 49.62, 17.29
    { 15509342, Bucket(4614) }, // 47.47, 18.97 x 47.52, 19.02
    { 15509364, Bucket(4618) }, // 47.47, 19.02 x 47.52, 19.07
    { 15509369, 598 }, // 47.42, 19.12 x 47.47, 19.18
    { 15509743, 517 }, // 44.79, 20.44 x 44.85, 20.49
    { 15511227, Bucket(4623) }, // 46.16, 21.27 x 46.21, 21.33
    { 15514553, 2579 }, // 48.67, 21.22 x 48.73, 21.27
    { 15514743, 274 }, // 50.04, 19.91 x 50.09, 19.96
    { 15516928, Bucket(4628) }, // 53.45, 14.62 x 53.5, 14.67
    { 15524597, Bucket(4631) }, // 51.72, 19.44 x 51.77, 19.49
    { 15524768, Bucket(4631) }, // 51.77, 19.44 x 51.82, 19.49
    { 15530175, 3350 }, // 54.65, 20.44 x 54.7, 20.49
    { 15530218, 3350 }, // 54.7, 20.44 x 54.76, 20.49
    { 15530517, Bucket(4634) }, // 54.65, 20.49 x 54.7, 20.54
    { 15530560, Bucket(4634) }, // 54.7, 20.49 x 54.76, 20.54
    { 15567871, 1761 }, // 59.26, 17.92 x 59.32, 17.97
    { 15568554, Bucket(4637) }, // 59.32, 17.92 x 59.37, 17.97
    { 15574016, 3221 }, // 59.32, 17.97 x 59.37, 18.02
    { 15598609, Bucket(4625) }, // 46.16, 21.33 x 46.21, 21.38
    { 15599006, Bucket(4640) }, // 47.05, 21.9 x 47.1, 21.96
    { 15605327, 447 }, // 49.83, 24 x 49.88, 24.05
    { 15609792, Bucket(4643) }, // 47.15, 27.62 x 47.21, 27.67
    { 15626088, 3211 }, // 53.86, 27.51 x 53.92, 27.57
    { 15628638, 643 }, // 55.86, 26.52 x 55.91, 26.57
    { 15666862, Bucket(4646) }, // 59.42, 24.63 x 59.47, 24.68
    { 37088620, 3178 }, // 13.7, 100.5 x 13.76, 100.5
    { 37103583, 3734 }, // -6.166, 106.6 x -6.114, 106.7
    { 37391332, 2993 }, // -34.95, 138.6 x -34.9, 138.6
    { 37835467, 3596 }, // 41.33, 36.16 x 41.39, 36.22
    { 37870335, 2110 }, // 41.65, 44.76 x 41.7, 44.81
    { 37899197, 3403 }, // 25.29, 51.42 x 25.34, 51.47
    { 37899243, 2972 }, // 25.4, 51.47 x 25.45, 51.53
    { 37904660, 2878 }, // 25.24, 51.53 x 25.29, 51.58
    { 38034296, 3652 }, // 55.75, 37.58 x 55.8, 37.63
    { 38067390, 315 }, // 56.28, 43.92 x 56.33, 43.98
    { 38163282, 3492 }, // 55.75, 49.06 x 55.8, 49.11
    { 38171119, 3362 }, // 55.7, 52.31 x 55.75, 52.36
    { 38172415, 735 }, // 56.75, 53.15 x 56.8, 53.2
    { 38172586, 3911 }, // 56.8, 53.15 x 56.85, 53.2
    { 38172587, 737 }, // 56.85, 53.15 x 56.91, 53.2
    { 38173781, Bucket(4650) }, // 56.75, 53.2 x 56.8, 53.26
    { 38173952, 3911 }, // 56.8, 53.2 x 56.85, 53.26
    { 38173953, 737 }, // 56.85, 53.2 x 56.91, 53.26
    { 38200746, 631 }, // 53.45, 59.02 x 53.5, 59.08
    { 38200917, Bucket(4653) }, // 53.39, 59.08 x 53.45, 59.13
    { 38201088, Bucket(4465) }, // 53.45, 59.08 x 53.5, 59.13
    { 38206711, 2059 }, // 56.75, 60.6 x 56.8, 60.65
    { 38723305, 531 }, // 56.43, 84.98 x 56.49, 85.03
    { 40024447, 1779 }, // 22.35, 114 x 22.41, 114
    { 40024532, 448 }, // 22.3, 114 x 22.35, 114.1
    { 40024533, Bucket(4658) }, // 22.35, 114 x 22.41, 114.1
    { 40025216, Bucket(4658) }, // 22.41, 114 x 22.46, 114.1
    { 40044672, 2936 }, // 30.8, 104 x 30.85, 104
    { 40089669, 3735 }, // 34.73, 113.6 x 34.78, 113.7
    { 40384186, 2202 }, // 22.62, 120.3 x 22.67, 120.3
    { 40444842, 2158 }, // 31.63, 120.3 x 31.69, 120.3
    { 40446208, 2158 }, // 31.63, 120.3 x 31.69, 120.4
    { 40571221, 2170 }, // 35.78, 128.7 x 35.83, 128.8
    { 40576486, 1574 }, // 33.84, 132.7 x 33.89, 132.8
    { 40579130, Bucket(4662) }, // 34.36, 132.4 x 34.41, 132.5
    { 40579216, 3864 }, // 34.36, 132.5 x 34.41, 132.5
    { 40581857, 2029 }, // 34.62, 135.2 x 34.68, 135.3
    { 40581860, 2029 }, // 34.68, 135.2 x 34.73, 135.3
    { 40581862, 2028 }, // 34.68, 135.3 x 34.73, 135.3
    { 40605957, 2703 }, // 35.15, 137.1 x 35.2, 137.1
    { 40612326, 2594 }, // 35.51, 139.4 x 35.57, 139.5
    { 40612340, 2587 }, // 35.72, 139.4 x 35.78, 139.4
    { 40612676, 2048 }, // 35.51, 139.6 x 35.57, 139.7
    { 40612701, 2586 }, // 35.78, 139.7 x 35.83, 139.8
    { 40613410, 2621 }, // 35.83, 139.9 x 35.88, 139.9
    { 25933824, 2218 }, // 25.76, -100.3 x 25.79, -100.3
    { 26155971, 3545 }, // 39.84, -104.7 x 39.87, -104.7
    { 27902258, 3302 }, // 27.96, -82.56 x 27.99, -82.53
    { 27902264, 3303 }, // 27.96, -82.53 x 27.99, -82.51
    { 28142893, 2466 }, // 42.2, -83.37 x 42.23, -83.35
    { 28143389, 1110 }, // 42.3, -83.06 x 42.33, -83.03
    { 28143432, 1110 }, // 42.33, -83.06 x 42.36, -83.03
    { 28285952, 2279 }, // 40.02, -75.14 x 40.05, -75.12
    { 59602602, 1872 }, // 43.38, -3.027 x 43.41, -3
    { 59722010, 1807 }, // 41.39, 2.111 x 41.41, 2.138
    { 59722038, 1505 }, // 41.44, 2.164 x 41.47, 2.19
    { 59758968, 1784 }, // 43.27, 5.546 x 43.3, 5.572
    { 60458445, 1312 }, // 45.76, 4.812 x 45.79, 4.838
    { 60469317, 2927 }, // 46.18, 6.227 x 46.21, 6.253
    { 60469695, 1474 }, // 46.5, 6.62 x 46.52, 6.647
    { 60469738, 1474 }, // 46.52, 6.62 x 46.55, 6.647
    { 60470037, 1474 }, // 46.5, 6.647 x 46.52, 6.673
    { 60470080, 1474 }, // 46.52, 6.647 x 46.55, 6.673
    { 60500687, 1255 }, // 51.22, 4.418 x 51.24, 4.445
    { 60523536, 1706 }, // 51.87, 4.549 x 51.9, 4.576
    { 60531285, 522 }, // 51.32, 6.647 x 51.35, 6.673
    { 61197503, 816 }, // 41.88, 12.49 x 41.91, 12.52
    { 61281621, 3767 }, // 40.84, 14.62 x 40.86, 14.64
    { 61743317, 1937 }, // 31.19, 29.92 x 31.22, 29.95
    { 61818977, 2625 }, // 41.1, 28.98 x 41.12, 29.01
    { 61818984, 3536 }, // 41.07, 29.03 x 41.1, 29.06
    { 61869311, 3473 }, // 45.45, 9.137 x 45.48, 9.163
    { 61869482, 3473 }, // 45.48, 9.137 x 45.5, 9.163
    { 61871532, 235 }, // 47.21, 8.272 x 47.23, 8.298
    { 61871535, 579 }, // 47.23, 8.298 x 47.26, 8.324
    { 61871952, 2765 }, // 47.47, 8.324 x 47.49, 8.35
    { 61871978, Bucket(4665) }, // 47.36, 8.508 x 47.39, 8.534
    { 61873508, 2438 }, // 47.42, 8.849 x 47.44, 8.875
    { 61873509, 2438 }, // 47.44, 8.849 x 47.47, 8.875
    { 61873520, 2438 }, // 47.47, 8.849 x 47.49, 8.875
    { 61873521, 2438 }, // 47.49, 8.849 x 47.52, 8.875
    { 61873522, 2995 }, // 47.47, 8.875 x 47.49, 8.901
    { 61873523, 2995 }, // 47.49, 8.875 x 47.52, 8.901
    { 61873570, 3077 }, // 47.15, 9.084 x 47.18, 9.111
    { 61873571, 3077 }, // 47.18, 9.084 x 47.21, 9.111
    { 61873574, 3077 }, // 47.21, 9.084 x 47.23, 9.111
    { 61873575, 3077 }, // 47.23, 9.084 x 47.26, 9.111
    { 61873586, 3077 }, // 47.26, 9.084 x 47.28, 9.111
    { 61873587, 3077 }, // 47.28, 9.084 x 47.31, 9.111
    { 61873590, 3077 }, // 47.31, 9.084 x 47.34, 9.111
    { 61873591, 3077 }, // 47.34, 9.084 x 47.36, 9.111
    { 61873634, 3077 }, // 47.36, 9.084 x 47.39, 9.111
    { 61873635, 3077 }, // 47.39, 9.084 x 47.42, 9.111
    { 61873638, 3077 }, // 47.42, 9.084 x 47.44, 9.111
    { 61873639, 3077 }, // 47.44, 9.084 x 47.47, 9.111
    { 61879509, 3076 }, // 47.13, 9.792 x 47.15, 9.818
    { 61879621, 3443 }, // 47.44, 9.583 x 47.47, 9.609
    { 61879632, 3443 }, // 47.47, 9.583 x 47.49, 9.609
    { 61884391, 487 }, // 49.12, 8.665 x 49.15, 8.691
    { 61884392, 1408 }, // 49.04, 8.691 x 49.07, 8.717
    { 61885882, 197 }, // 48.94, 9.137 x 48.96, 9.163
    { 61886360, 197 }, // 48.94, 9.425 x 48.96, 9.451
    { 61889536, 694 }, // 50.09, 8.744 x 50.12, 8.77
    { 61898102, 3438 }, // 50.88, 10.55 x 50.9, 10.58
    { 61923136, 1628 }, // 50.72, 12.52 x 50.75, 12.54
    { 61973999, 166 }, // 52.48, 13.33 x 52.5, 13.36
    { 62016447, Bucket(4668) }, // 48.18, 16.27 x 48.2, 16.29
    { 62016490, 70 }, // 48.2, 16.27 x 48.23, 16.29
    { 62021909, 70 }, // 48.18, 16.29 x 48.2, 16.32
    { 62021911, 68 }, // 48.18, 16.32 x 48.2, 16.35
    { 62021952, 70 }, // 48.2, 16.29 x 48.23, 16.32
    { 62120703, 3558 }, // 54.68, 20.46 x 54.7, 20.49
    { 62120874, 3558 }, // 54.7, 20.46 x 54.73, 20.49
    { 62271487, 318 }, // 59.29, 17.94 x 59.32, 17.97
    { 62296064, 317 }, // 59.32, 17.97 x 59.34, 18
    { 62394437, 3391 }, // 46.18, 21.33 x 46.21, 21.35
    { 151255697, 1317 }, // 29.25, 47.96 x 29.28, 47.99
    { 151341957, 3596 }, // 41.36, 36.22 x 41.39, 36.24
    { 151860305, 2119 }, // 40.36, 49.85 x 40.39, 49.87
    { 152651770, 3490 }, // 55.86, 48.98 x 55.88, 49.01
    { 152689663, Bucket(4649) }, // 56.77, 53.18 x 56.8, 53.2
    { 152803669, 1765 }, // 53.42, 59.08 x 53.45, 59.1
    { 152804352, Bucket(4671) }, // 53.45, 59.08 x 53.47, 59.1
    { 160092089, 3910 }, // 22.12, 113.5 x 22.15, 113.6
    { 161973743, 779 }, // 39.05, 125.7 x 39.08, 125.8
    { 161974085, 779 }, // 39.05, 125.8 x 39.08, 125.8
    { 162305944, 1573 }, // 33.84, 132.7 x 33.86, 132.8
    { 162316523, 3867 }, // 34.39, 132.4 x 34.41, 132.5
    { 162324783, Bucket(4677) }, // 34.65, 133.9 x 34.68, 133.9
    { 162450911, 2621 }, // 35.8, 139.9 x 35.83, 139.9
    { 171291302, 1955 }, // -41.29, 174.8 x -41.27, 174.8
    { 172124673, 2716 }, // -32.93, 151.8 x -32.91, 151.8
    { 103729834, 2218 }, // 25.76, -100.3 x 25.78, -100.3
    { 103832300, 3673 }, // 33.44, -112.1 x 33.46, -112.1
    { 113170325, 358 }, // 40.74, -73.99 x 40.76, -73.98
    { 153713678, 2214 }, // -30, -51.2 x -29.98, -51.18
    { 153713700, 2214 }, // -30, -51.18 x -29.98, -51.17
    { 238342614, 2155 }, // 40.42, -3.721 x 40.43, -3.708
    { 239030251, 909 }, // 43.29, 5.375 x 43.3, 5.388
    { 242125824, 522 }, // 51.35, 6.647 x 51.36, 6.66
    { 245170176, 3679 }, // 40.86, 14.62 x 40.88, 14.63
    { 247275642, 3373 }, // 41.02, 28.97 x 41.03, 28.98
    { 247275729, 3372 }, // 41.03, 28.98 x 41.05, 28.99
    { 247486136, 235 }, // 47.21, 8.298 x 47.22, 8.311
    { 247494047, 2995 }, // 47.46, 8.888 x 47.47, 8.901
    { 247494272, 3031 }, // 47.15, 9.058 x 47.17, 9.071
    { 247494273, 3031 }, // 47.17, 9.058 x 47.18, 9.071
    { 247494275, 3077 }, // 47.17, 9.071 x 47.18, 9.084
    { 247494276, 3031 }, // 47.18, 9.058 x 47.19, 9.071
    { 247494277, 3031 }, // 47.19, 9.058 x 47.21, 9.071
    { 247494278, 3077 }, // 47.18, 9.071 x 47.19, 9.084
    { 247494279, 3077 }, // 47.19, 9.071 x 47.21, 9.084
    { 247494288, 3031 }, // 47.21, 9.058 x 47.22, 9.071
    { 247494289, 3031 }, // 47.22, 9.058 x 47.23, 9.071
    { 247494290, 3077 }, // 47.21, 9.071 x 47.22, 9.084
    { 247494291, 3077 }, // 47.22, 9.071 x 47.23, 9.084
    { 247494292, 3031 }, // 47.23, 9.058 x 47.25, 9.071
    { 247494293, 3031 }, // 47.25, 9.058 x 47.26, 9.071
    { 247494294, 3077 }, // 47.23, 9.071 x 47.25, 9.084
    { 247494295, 3077 }, // 47.25, 9.071 x 47.26, 9.084
    { 247494336, 3031 }, // 47.26, 9.058 x 47.27, 9.071
    { 247494337, 3031 }, // 47.27, 9.058 x 47.28, 9.071
    { 247494338, 3077 }, // 47.26, 9.071 x 47.27, 9.084
    { 247494339, 3077 }, // 47.27, 9.071 x 47.28, 9.084
    { 247494340, 3031 }, // 47.28, 9.058 x 47.3, 9.071
    { 247494341, 3031 }, // 47.3, 9.058 x 47.31, 9.071
    { 247494342, 3077 }, // 47.28, 9.071 x 47.3, 9.084
    { 247494343, 3077 }, // 47.3, 9.071 x 47.31, 9.084
    { 247494352, 3031 }, // 47.31, 9.058 x 47.32, 9.071
    { 247494353, 3031 }, // 47.32, 9.058 x 47.34, 9.071
    { 247494354, 3077 }, // 47.31, 9.071 x 47.32, 9.084
    { 247494355, 3077 }, // 47.32, 9.071 x 47.34, 9.084
    { 247494356, 3031 }, // 47.34, 9.058 x 47.35, 9.071
    { 247494357, 3031 }, // 47.35, 9.058 x 47.36, 9.071
    { 247494358, 3077 }, // 47.34, 9.071 x 47.35, 9.084
    { 247494359, 3077 }, // 47.35, 9.071 x 47.36, 9.084
    { 247494528, 3031 }, // 47.36, 9.058 x 47.38, 9.071
    { 247494529, 3031 }, // 47.38, 9.058 x 47.39, 9.071
    { 247494530, 3077 }, // 47.36, 9.071 x 47.38, 9.084
    { 247494531, 3077 }, // 47.38, 9.071 x 47.39, 9.084
    { 247494532, 3031 }, // 47.39, 9.058 x 47.4, 9.071
    { 247494533, 3031 }, // 47.4, 9.058 x 47.42, 9.071
    { 247494534, 3077 }, // 47.39, 9.071 x 47.4, 9.084
    { 247494535, 3077 }, // 47.4, 9.071 x 47.42, 9.084
    { 247494544, 3031 }, // 47.42, 9.058 x 47.43, 9.071
    { 247494545, 3031 }, // 47.43, 9.058 x 47.44, 9.071
    { 247494546, 3077 }, // 47.42, 9.071 x 47.43, 9.084
    { 247494547, 3077 }, // 47.43, 9.071 x 47.44, 9.084
    { 247494548, 3031 }, // 47.44, 9.058 x 47.46, 9.071
    { 247494550, 3077 }, // 47.44, 9.071 x 47.46, 9.084
    { 247494551, 3077 }, // 47.46, 9.071 x 47.47, 9.084
    { 247548346, 3748 }, // 49.51, 8.521 x 49.53, 8.534
    { 247548688, 3748 }, // 49.51, 8.534 x 49.53, 8.547
    { 248011755, 3401 }, // 47.06, 15.44 x 47.08, 15.45
    { 248017217, 3401 }, // 47.06, 15.45 x 47.08, 15.47
    { 249755989, Bucket(4643) }, // 47.14, 27.62 x 47.15, 27.63
    { 606387153, 2971 }, // 25.3, 51.42 x 25.32, 51.43
    { 611217408, Bucket(4680) }, // 53.45, 59.08 x 53.46, 59.09
    { 640402994, 3852 }, // 22.88, 113.9 x 22.89, 113.9
    { 646361821, 2609 }, // 25.12, 121.5 x 25.13, 121.5
    { 646361992, 2609 }, // 25.13, 121.5 x 25.15, 121.5
    { 647899818, 2044 }, // 37.51, 127 x 37.52, 127
    { 688497326, 2716 }, // -32.93, 151.8 x -32.92, 151.8
    { 446436142, 3054 }, // 27.98, -82.54 x 27.98, -82.53
    { 446436228, 3301 }, // 27.98, -82.53 x 27.98, -82.53
    { 947054399, 518 }, // 38.71, -9.141 x 38.71, -9.135
    { 947054442, 518 }, // 38.71, -9.141 x 38.72, -9.135
    { 947054485, 518 }, // 38.71, -9.135 x 38.71, -9.128
    { 947054528, 518 }, // 38.71, -9.135 x 38.72, -9.128
    { 979168146, 957 }, // 41.83, 12.89 x 41.84, 12.9
    { 987895808, 1937 }, // 31.22, 29.92 x 31.22, 29.93
    { 989977099, 3077 }, // 47.16, 9.078 x 47.17, 9.084
    { 990221653, 694 }, // 50.08, 8.744 x 50.09, 8.75
    { 990309034, 1870 }, // 48.41, 11.25 x 48.42, 11.26
    { 2443122005, 735 }, // 56.79, 53.2 x 56.8, 53.21
    { 2596894943, 1573 }, // 33.83, 132.8 x 33.84, 132.8
    { 2598693247, 2027 }, // 35.19, 136.9 x 35.2, 136.9
    { 2598693930, 2027 }, // 35.2, 136.9 x 35.21, 136.9
};
}
