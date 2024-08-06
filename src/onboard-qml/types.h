/*
    SPDX-FileCopyrightText: 2022 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_ONBOARD_TYPES_H
#define KPUBLICTRANSPORT_ONBOARD_TYPES_H

#include <KPublicTransport/OnboardStatus>

#include <QQmlEngine>

struct OnboardStatusForeign {
    Q_GADGET
    QML_NAMED_ELEMENT(OnboardStatus)
    QML_FOREIGN(KPublicTransport::OnboardStatus)
};

#endif
