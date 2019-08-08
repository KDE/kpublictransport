# KPublicTransport

A library for accessing realtime public transport data and for performing
public transport journey queries.

!! Before using this, please read the compliance section below !!

## Data Model

This largely follows the concepts and naming conventions used by [Navitia](https://navitia.io).

The key elements are:

* KPublicTransport::Journey
* KPublicTransport::Departure

## Supported Operations

* Location searches: retrieve stop information based on name or geo coordinates.
* Arrival/departure queries: retrieve base schedule and if available realtime information
  about upcoming arrivals and departures at a stop.
* Journey queries: obtain ways to get from A to B.

All operations can be started from KPublicTransport::Manager with an API similar to
QNetworkAccessManager.

## Backends

All data is retrieved from online backends, this library is not offline capable.
The primary backend is [Navitia](https://navitia.io), which is Free Software and
relies on Open Data. Support for proprietary/vendor-specific APIs exists too though.

## Compliance

When using the data retrieved by this library you need to comply with the license
terms of the backends this is coming from, in particular https://www.navitia.io/api-term-of-use.

Attribution information that need to be displayed in an appropriate place in the
application using this are provided globally via KPublicTransport::Manager::attributions()
as well as more fine-grained per query reply via KPublicTransport::Reply::attributions().

## Development

Setting the `KPUBLICTRANSPORT_LOG_DIR` environment variable will result in all network operations
being logged there, grouped by backend, and including the full network traffic. This is useful for
example to capture rare scenarios not parsed correctly yet, or for exploring what additional information
is available that KPublicTransport does not expose yet.
