#!/bin/sh
# SPDX-FileCopyrightText: 2024 Volker Krause <vkrause@kde.org>
# SPDX-License-Identifier: BSD-2-Clause
#
# Convert VRS client certificate into a format consumable by OpenSSL 3
#

CERT_PASSWORD=xyH7PEpUdfyr6Zcb

openssl pkcs12 -in $1 -out vrs-client-cert.pem -passin pass:$CERT_PASSWORD -noenc -legacy
openssl pkcs12 -export -in vrs-client-cert.pem -out vrs-client-cert.p12 -passout pass:
