/*
    SPDX-FileCopyrightText: 2022 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "abstractonboardbackend_p.h"

using namespace KPublicTransport;

AbstractOnboardBackend::AbstractOnboardBackend(QObject *parent)
    : QObject(parent)
{
}

AbstractOnboardBackend::~AbstractOnboardBackend() = default;
