# SPDX-FileCopyrightText: 2024 Volker Krause <vkrause@kde.org>
# SPDX-License-Identifier: BSD-2-Clause

#! /usr/bin/env bash
$XGETTEXT `find -name \*.cpp -o -name \*.qml -o -name \*.js` -o $podir/kpublictransport.pot
