# KPublicTransport

A library for accessing realtime public transport data and for performing
public transport journey queries.

This includes:
* Finding bus stops or train stations, departures/arrivals from there, and journeys between those.
* Path and routing information for individual transport sections of a journey.
* Information about train coach and train station platform layouts.
* Information about rental vehicle positions and availability, such as shared bikes or scooters.
* Realtime information about the operational status of elevators or escalators.

!! Before using this, please read the license compliance and attribution section below !!

## Data Model

The key elements are:

* KPublicTransport::Journey (getting from one place to another)
* KPublicTransport::Stopover (departures/arrivals)
* KPublicTransport::Location (a place, stop, or train station, rental vehicle dock, floating rental vehicle, elevator/escalator,
ie. anything that has a geo coordinate associated with it).

## Supported Operations

* Location searches: retrieve stop information based on name or geo coordinates.
* Stopover (arrival/departure) queries: retrieve base schedule and if available realtime information
  about upcoming arrivals and departures at a stop.
* Journey queries: obtain ways to get from A to B.
* Vehicle and platform layout queries: information about where coaches stop on a platform,
and how a platform is structured.

All operations can be started from KPublicTransport::Manager with an API similar to
QNetworkAccessManager.

## Backends

All data is retrieved from online backend services, this library is not offline capable.
The following Free Software/Open Data backend types are supported:
* [Navitia](https://navitia.io).
* [OpenTripPlanner](http://opentripplanner.org), in the REST, Digitransit and Entur variants.
* [GBFS](https://github.com/NABSA/gbfs/) feeds for rental vehicles, such as provided by
the [OpenBike](https://github.com/stadtulm/OpenBike/) bike rental system.
* [accessibility.cloud](https://accessibility.cloud/) for realtime elevator/escalator status information.

Additionally, a few proprietary/vendor-specific backends are supported too though.

Configurations for about 70 backend services can be found in 'src/lib/networks'.
Backend service configations follow the [Transport API Repository](https://github.com/public-transport/transport-apis/)
format.

## License Compliance and Attribution

When using the data retrieved by this library you need to comply with the license
terms of the backends this is coming from, in particular https://www.navitia.io/api-term-of-use.

Attribution information that need to be displayed in an appropriate place in the
application using this are provided globally via KPublicTransport::Manager::attributions()
as well as more fine-grained per query reply via KPublicTransport::Reply::attributions().

Besides attributing backend data correctly, this library also contains static data
retrieved from [Wikidata](https://wikidata.org) under licensed as CC0 as well as data
from [OpenStreetMap](https://openstreetmap.org) under licensed as ODbL, so those should
be appropriately credited in your application as well.

## Development

Setting the `KPUBLICTRANSPORT_LOG_DIR` environment variable will result in all network operations
being logged there, grouped by backend, and including the full network traffic. This is useful for
example to capture rare scenarios not parsed correctly yet, or for exploring what additional information
is available that KPublicTransport does not expose yet.
