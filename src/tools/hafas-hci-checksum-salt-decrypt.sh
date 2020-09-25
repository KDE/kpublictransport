#!/bin/sh
# SPDX-License-Identifier: CC0-1.0
# SPDX-FileCopyrightText: none
#
# Decode Hafas checksum salts

salt=$1

if [ -z "$salt" ]; then
    echo "Usage: $1 <base64 encrypted salt>"
    exit 1
fi

echo $salt | openssl aes-128-cbc -d -K 61483646387A527569426E6D33336655 -iv 00000000000000000000000000000000 -a | xxd -g 16
