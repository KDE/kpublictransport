/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_BACKEND_P_H
#define KPUBLICTRANSPORT_BACKEND_P_H

#include <QSharedData>
#include <QString>

class QJsonObject;

namespace KPublicTransport {

class Backend;

class BackendPrivate : public QSharedData {
public:
    static Backend fromJson(const QJsonObject &obj, const QString &backendId);

    QString identifier;
    QString name;
    QString description;
    bool isSecure;
};

}

#endif // KPUBLICTRANSPORT_BACKEND_P_H
