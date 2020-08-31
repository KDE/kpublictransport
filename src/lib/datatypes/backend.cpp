/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "backend.h"
#include "datatypes_p.h"

#include <QString>

using namespace KPublicTransport;

namespace KPublicTransport {

class BackendPrivate : public QSharedData {
public:
    QString identifier;
    QString name;
    QString description;
    bool isSecure;
};
}

KPUBLICTRANSPORT_MAKE_GADGET(Backend)
KPUBLICTRANSPORT_MAKE_PROPERTY(Backend, QString, identifier, setIdentifier)
KPUBLICTRANSPORT_MAKE_PROPERTY(Backend, QString, name, setName)
KPUBLICTRANSPORT_MAKE_PROPERTY(Backend, QString, description, setDescription)
KPUBLICTRANSPORT_MAKE_PROPERTY(Backend, bool, isSecure, setIsSecure)

QString Backend::primaryCountryCode() const
{
    if (identifier().size() > 3 && identifier().at(2) == QLatin1Char('_')) {
        return identifier().left(2).toUpper();
    }
    return {};
}

#include "moc_backend.cpp"
