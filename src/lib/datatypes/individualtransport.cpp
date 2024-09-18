/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "individualtransport.h"
#include "json_p.h"
#include "datatypes_p.h"
#include "variant_p.h"

#include <QDebug>

using namespace Qt::Literals::StringLiterals;

namespace KPublicTransport {
class IndividualTransportPrivate : public QSharedData
{
public:
    IndividualTransport::Mode mode = IndividualTransport::Walk;
    IndividualTransport::Qualifier qualifier = IndividualTransport::None;
};
}

using namespace KPublicTransport;

KPUBLICTRANSPORT_MAKE_GADGET(IndividualTransport)
KPUBLICTRANSPORT_MAKE_PROPERTY(IndividualTransport, IndividualTransport::Mode, mode, setMode)
KPUBLICTRANSPORT_MAKE_PROPERTY(IndividualTransport, IndividualTransport::Qualifier, qualifier, setQualifier)

IndividualTransport::IndividualTransport(IndividualTransport::Mode mode, IndividualTransport::Qualifier qualifier)
    : d(new IndividualTransportPrivate)
{
    d->mode = mode;
    d->qualifier = qualifier;
}

bool IndividualTransport::operator==(const IndividualTransport &other) const
{
    return d->mode == other.mode() && d->qualifier == other.qualifier();
}

bool IndividualTransport::operator!=(const IndividualTransport &other) const
{
    return d->mode != other.mode() || d->qualifier != other.qualifier();
}

QString IndividualTransport::modeIconName(IndividualTransport::Mode mode)
{
    switch (mode) {
        case IndividualTransport::Bike:
             return u"qrc:///org.kde.kpublictransport/assets/images/transport-mode-bike.svg"_s;
        case IndividualTransport::Car:
            return u"qrc:///org.kde.kpublictransport/assets/images/transport-mode-car.svg"_s;
        case IndividualTransport::Walk:
            return u"qrc:///org.kde.kpublictransport/assets/images/transport-mode-walk.svg"_s;
    }

    return u"question"_s;
}

QString IndividualTransport::modeIconName() const
{
    return IndividualTransport::modeIconName(mode());
}

QJsonObject IndividualTransport::toJson(const IndividualTransport &it)
{
    return Json::toJson(it);
}

QJsonArray IndividualTransport::toJson(const std::vector<IndividualTransport> &its)
{
    return Json::toJson(its);
}

IndividualTransport IndividualTransport::fromJson(const QJsonObject &obj)
{
    return Json::fromJson<IndividualTransport>(obj);
}

std::vector<IndividualTransport> IndividualTransport::fromJson(const QJsonArray &array)
{
    return Json::fromJson<IndividualTransport>(array);
}

std::vector<IndividualTransport> IndividualTransport::fromVariant(const QVariantList &v)
{
    return Variant::fromVariantList<IndividualTransport>(v);
}

#include "moc_individualtransport.cpp"
