# KPublicTransport

A library for accessing realtime public transport data and for performing
public transport journey queries.

!! Before using this, please read the license compliance and attribution section below !!

## Data Model

This largely follows the concepts and naming conventions used by [Navitia](https://navitia.io).

The key elements are:

* KPublicTransport::Journey (getting from one place to another)
* KPublicTransport::Stopover (departures/arrivals)

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

Additionally, a few proprietary/vendor-specific backends are supported too though.

Configurations for more than 60 backend services can be found in 'src/lib/networks'.

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
