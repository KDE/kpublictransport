# KPublicTransport

A library for access realtime public transport data and for performing
public transport journey queries.

!! Before using this, please read the compliance section below !!

## Data Model

This largely follows the concepts and naming conventions used by [Navitia](https://navitia.io).

## Supported Operations

* Location searches: retrieve stop information based on name or geo coordinates.
* Arrival/departure queries: retrieve base schedule and if available realtime information
  about upcoming arrivals and departures at a stop.
* Journey queries: obtain ways to get from A to B.

## Backends

All data is retrieved from online backends, this library is not offline capable.
The primary backend is [Navitia](https://navitia.io), which is Free Software and
relies on Open Data. Support for proprietary/vendor-specific APIs exists too though.

## Compliance

When using the data retrieved by this library you need to comply with the license
terms of the backends this is coming from, in particular https://www.navitia.io/api-term-of-use.

Support for aggregating license/copyright information from the backends and making this
available for display has not been implemented yet, so you are on your own at this point
in ensuring you comply with those terms.
