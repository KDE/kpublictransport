/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef EXAMPLEUTIL_H
#define EXAMPLEUTIL_H

#include <KPublicTransport/Journey>
#include <KPublicTransport/JourneyQueryModel>
#include <KPublicTransport/Location>
#include <KPublicTransport/LocationQueryModel>
#include <KPublicTransport/Stopover>
#include <KPublicTransport/StopoverQueryModel>

#include <QDebug>
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QObject>
#include <QUrl>

class ExampleUtil : public QObject
{
    Q_OBJECT
public:
    Q_INVOKABLE void saveTo(QObject *model, const QUrl &fileName)
    {
        QFile f(fileName.toLocalFile());
        if (!f.open(QFile::WriteOnly)) {
            qWarning() << f.errorString() << fileName;
            return;
        }

        using namespace KPublicTransport;

        if (qobject_cast<JourneyQueryModel*>(model)) {
            f.write(QJsonDocument(Journey::toJson(qobject_cast<JourneyQueryModel*>(model)->journeys())).toJson());
        } else if (qobject_cast<StopoverQueryModel*>(model)) {
            f.write(QJsonDocument(Stopover::toJson(qobject_cast<StopoverQueryModel*>(model)->departures())).toJson());
        } else if (qobject_cast<LocationQueryModel*>(model)) {
            f.write(QJsonDocument(Location::toJson(qobject_cast<LocationQueryModel*>(model)->locations())).toJson());
        }
    }

    Q_INVOKABLE void saveTo(const KPublicTransport::JourneySection &jny, const QUrl &fileName)
    {
        QFile f(fileName.toLocalFile());
        if (!f.open(QFile::WriteOnly)) {
            qWarning() << f.errorString() << fileName;
            return;
        }
        f.write(QJsonDocument(KPublicTransport::JourneySection::toJson(jny)).toJson());
    }
};

#endif // EXAMPLEUTIL_H
