/*
    Copyright (C) 2019 Volker Krause <vkrause@kde.org>

    This program is free software; you can redistribute it and/or modify it
    under the terms of the GNU Library General Public License as published by
    the Free Software Foundation; either version 2 of the License, or (at your
    option) any later version.

    This program is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public
    License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#ifndef EXAMPLEUTIL_H
#define EXAMPLEUTIL_H

#include <KPublicTransport/Departure>
#include <KPublicTransport/DepartureQueryModel>
#include <KPublicTransport/Journey>
#include <KPublicTransport/JourneyQueryModel>
#include <KPublicTransport/Location>

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
        } else if (qobject_cast<DepartureQueryModel*>(model)) {
            f.write(QJsonDocument(Departure::toJson(qobject_cast<DepartureQueryModel*>(model)->departures())).toJson());
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
