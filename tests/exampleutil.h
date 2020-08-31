/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef EXAMPLEUTIL_H
#define EXAMPLEUTIL_H

#include <KPublicTransport/Journey>
#include <KPublicTransport/JourneyQueryModel>
#include <KPublicTransport/Location>
#include <KPublicTransport/Stopover>
#include <KPublicTransport/StopoverQueryModel>

#include <QDebug>
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
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
        }
    }

    Q_INVOKABLE QString locationIds(const QVariant &v)
    {
        using namespace KPublicTransport;

        const auto loc = v.value<Location>();
        const auto ids = loc.identifiers();
        QStringList l;
        l.reserve(ids.size());
        for (auto it = ids.begin(); it != ids.end(); ++it) {
            l.push_back(it.key() + QLatin1String(": ") + it.value());
        }
        return l.join(QLatin1String(", "));
    }
};

#endif // EXAMPLEUTIL_H
