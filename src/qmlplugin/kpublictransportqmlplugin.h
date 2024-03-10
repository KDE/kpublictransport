/*
    SPDX-FileCopyrightText: 2019 Nicolas Fella <nicolas.fella@gmx.de>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORTQMLPLUGIN_H
#define KPUBLICTRANSPORTQMLPLUGIN_H

#include <QQmlEngine>
#include <QQmlExtensionPlugin>

#include <KPublicTransport/BackendModel>
#include <KPublicTransport/JourneyQueryModel>
#include <KPublicTransport/LocationHistoryModel>
#include <KPublicTransport/LocationQueryModel>
#include <KPublicTransport/Manager>
#include <KPublicTransport/PathModel>
#include <KPublicTransport/StopoverQueryModel>
#include <KPublicTransport/VehicleLayoutQueryModel>

struct ManagerForeign {
    Q_GADGET
    QML_ELEMENT
    QML_FOREIGN(KPublicTransport::Manager)
    QML_NAMED_ELEMENT(Manager)
};

struct StopoverQueryModelForeign {
    Q_GADGET
    QML_ELEMENT
    QML_FOREIGN(KPublicTransport::StopoverQueryModel)
    QML_NAMED_ELEMENT(StopoverQueryModel)
};

struct JourneyQueryModelForeign {
    Q_GADGET
    QML_ELEMENT
    QML_FOREIGN(KPublicTransport::JourneyQueryModel)
    QML_NAMED_ELEMENT(JourneyQueryModel)
};

struct LocationHistoryModelForeign {
    Q_GADGET
    QML_ELEMENT
    QML_FOREIGN(KPublicTransport::LocationHistoryModel)
    QML_NAMED_ELEMENT(LocationHistoryModel)
};

struct LocationQueryModelForeign {
    Q_GADGET
    QML_ELEMENT
    QML_FOREIGN(KPublicTransport::LocationQueryModel)
    QML_NAMED_ELEMENT(LocationQueryModel)
};

struct BackendModelForeign {
    Q_GADGET
    QML_ELEMENT
    QML_FOREIGN(KPublicTransport::BackendModel)
    QML_NAMED_ELEMENT(BackendModel)
};

struct VehicleLayoutQueryModelForeign {
    Q_GADGET
    QML_ELEMENT
    QML_FOREIGN(KPublicTransport::VehicleLayoutQueryModel)
    QML_NAMED_ELEMENT(VehicleLayoutQueryModel)
};

struct PathModelForeign {
    Q_GADGET
    QML_ELEMENT
    QML_FOREIGN(KPublicTransport::PathModel)
    QML_NAMED_ELEMENT(PathModel)
};

namespace DisruptionForeign
{
Q_NAMESPACE
QML_NAMED_ELEMENT(Disruption)
QML_FOREIGN_NAMESPACE(KPublicTransport::Disruption)
};

namespace LoadForeign
{
Q_NAMESPACE
QML_NAMED_ELEMENT(Load)
QML_FOREIGN_NAMESPACE(KPublicTransport::Load)
};

class KPublicTransportQmlPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT

    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")

    void registerTypes(const char* uri) override;
};

#endif // KPUBLICTRANSPORTQMLPLUGIN_H

