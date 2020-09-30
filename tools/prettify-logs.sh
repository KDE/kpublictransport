#!/bin/sh
#
# SPDX-FileCopyrightText: 2018 Volker Krause <vkrause@kde.org>
# SPDX-License-Identifier: CC0-1.0
#
# Makes network repsonses in the log folder easier to read by formatting and unpacking them
#

if [ -z "$KPUBLICTRANSPORT_LOG_DIR" ]; then
    echo "$KPUBLICTRANSPORT_LOG_DIR not set"
    exit 1
fi

if ! [ -z "`which jq`" ]; then
    for i in `find $KPUBLICTRANSPORT_LOG_DIR -name "*.json"`; do
        jq '.' $i > $i.pretty
        if ! [ "$?" == 0 ]; then
            echo "parse error in $i"
            rm $i.pretty
        else
            mv $i.pretty $i
        fi
    done
else
    echo "Skipping JSON prettification, jq not found";
fi

if ! [ -z "`which xmllint`" ]; then
    for i in `find $KPUBLICTRANSPORT_LOG_DIR -name "*.xml"`; do
        xmllint --format $i > $i.pretty
        if ! [ "$?" == 0 ]; then
            echo "parse error in $i"
            rm $i.pretty
        else
            mv $i.pretty $i
        fi
    done
else
    echo "Skipping XML prettification, xmllint not found";
fi

if ! [ -z "`which gunzip`" ]; then
    for i in `find $KPUBLICTRANSPORT_LOG_DIR -name "*.gz"`; do
        gunzip $i
    done
else
    echo "Skipping GZip unpacking, gzip not found";
fi
