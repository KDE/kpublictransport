#!/bin/sh
# SPDX-FileCopyrightText: 2024 Volker Krause <vkrause@kde.org>
# SPDX-License-Identifier: LGPL-2.0-or-later

curl "https://europe.motis-project.de/api/v1/geocode?text=Karlsruhe%20Hbf&language=en" > location-name-search.in.json
curl "https://europe.motis-project.de/api/v1/reverse-geocode?place=51.3455,12.3821" > location-geo-search.in.json
curl "https://europe.motis-project.de/api/v1/map/stops?min=48.3982,9.98176&max=48.4009,9.98356" > location-map-stations.in.json

curl "https://europe.motis-project.de/api/v1/stoptimes?time=2024-10-18T11:00:00Z&stopId=at-Railway-Current-Reference-Data_Pde:02000:80953&n=10&arriveBy=false" > stopover-departure.in.json
curl "https://europe.motis-project.de/api/v1/stoptimes?stopId=de-DELFI_de%3A02000%3A8002553%3A3%3A255306&arriveBy=true&n=10" > stopover-arrival.in.json
curl "https://europe.motis-project.de/api/v1/stoptimes?stopId=ch-opentransportdataswiss_8501753%3A0%3AA&arriveBy=true&n=10" > stopover-arrival-realtime.in.json

curl "https://europe.motis-project.de/api/v1/plan?fromPlace=49.0041,2.5711,0&toPlace=48.8439,2.37708,0&numItineraries=3&arriveBy=false" > journey-transit.in.json
curl "https://europe.motis-project.de/api/v1/plan?fromPlace=48.77376011971705,9.170308904682798,0&toPlace=48.78503407036962,9.189244751020539,0&arriveBy=false&timetableView=true&wheelchair=false&preTransitModes=WALK,BIKE_RENTAL&postTransitModes=WALK,BIKE_RENTAL&directModes=WALK,BIKE_RENTAL" > journey-bike-rental.in.json
curl "https://europe.motis-project.de/api/v1/plan?fromPlace=52.50602341723939%2C13.45152382711484%2C0&toPlace=52.50494050893889%2C13.448614380176252%2C0&arriveBy=false&timetableView=true&wheelchair=false&mode=WALK" > journey-direct-walk.in.json
