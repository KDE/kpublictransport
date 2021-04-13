/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_BACKEND_P_H
#define KPUBLICTRANSPORT_BACKEND_P_H

#include "coveragearea.h"

#include <QSharedData>
#include <QString>

#include <memory>

class QJsonObject;

namespace KPublicTransport {

class AbstractBackend;
class Backend;

class BackendPrivate : public QSharedData {
public:
    static const AbstractBackend* impl(const Backend &b);
    static void setImpl(Backend &b, std::unique_ptr<AbstractBackend> &&impl);
    static Backend fromJson(const QJsonObject &obj);

    std::unique_ptr<AbstractBackend> m_backendImpl;
    QString name;
    QString description;
    CoverageArea coverage[3];
};

}

#endif // KPUBLICTRANSPORT_BACKEND_P_H
