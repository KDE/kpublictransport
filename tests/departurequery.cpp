/*
    Copyright (C) 2018 Volker Krause <vkrause@kde.org>

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

#include <KPublicTransport/Attribution>
#include <KPublicTransport/Departure>
#include <KPublicTransport/DepartureReply>
#include <KPublicTransport/DepartureRequest>
#include <KPublicTransport/Location>
#include <KPublicTransport/Manager>

#include <QQmlApplicationEngine>
#include <QQmlContext>

#include <QApplication>
#include <QDateTime>
#include <QDebug>
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QUrl>

using namespace KPublicTransport;

class QueryManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool loading READ loading NOTIFY loadingChanged)
    Q_PROPERTY(QString errorMessage READ errorMessage NOTIFY errorMessageChanged)
public:
    Q_INVOKABLE void queryDeparture(const QString &name, double fromLat, double fromLon, bool queryArrival)
    {
        engine->rootContext()->setContextProperty(QStringLiteral("_departures"), QVariantList());
        m_loading = true;
        emit loadingChanged();
        m_errorMsg.clear();
        emit errorMessageChanged();

        Location from;
        from.setCoordinate(fromLat, fromLon);
        from.setName(name);

        DepartureRequest depReq(from);
        depReq.setMode(queryArrival ? DepartureRequest::QueryArrival : DepartureRequest::QueryDeparture);

        auto reply = ptMgr.queryDeparture(depReq);
        QObject::connect(reply, &DepartureReply::finished, this, [reply, this]{
            m_loading = false;
            emit loadingChanged();

            if (reply->error() == DepartureReply::NoError) {
                m_departures = reply->takeResult();
                QVariantList l;
                l.reserve(m_departures.size());
                std::transform(m_departures.begin(), m_departures.end(), std::back_inserter(l), [](const auto &journey) { return QVariant::fromValue(journey); });
                engine->rootContext()->setContextProperty(QStringLiteral("_departures"), l);

                QVariantList attrs;
                attrs.reserve(reply->attributions().size());
                std::transform(reply->attributions().begin(), reply->attributions().end(), std::back_inserter(attrs), [](const auto &attr) { return QVariant::fromValue(attr); });
                engine->rootContext()->setContextProperty(QStringLiteral("_attributions"), attrs);
            } else {
                m_errorMsg = reply->errorString();
                emit errorMessageChanged();
            }
            reply->deleteLater();
        });
    }

    Q_INVOKABLE void setAllowInsecure(bool insecure)
    {
        ptMgr.setAllowInsecureBackends(insecure);
    }

    Q_INVOKABLE void saveTo(const QUrl &fileName)
    {
        QFile f(fileName.toLocalFile());
        if (!f.open(QFile::WriteOnly)) {
            qWarning() << f.errorString() << fileName;
            return;
        }
        f.write(QJsonDocument(Departure::toJson(m_departures)).toJson());
    }

    Q_INVOKABLE QString locationIds(const QVariant &v)
    {
        const auto loc = v.value<Location>();
        const auto ids = loc.identifiers();
        QStringList l;
        l.reserve(ids.size());
        for (auto it = ids.begin(); it != ids.end(); ++it) {
            l.push_back(it.key() + QLatin1String(": ") + it.value());
        }
        return l.join(QLatin1String(", "));
    }

    bool loading() const { return m_loading; }
    QString errorMessage() const { return m_errorMsg; }

    QQmlEngine *engine = nullptr;

Q_SIGNALS:
    void loadingChanged();
    void errorMessageChanged();

private:
    Manager ptMgr;
    std::vector<Departure> m_departures;
    QString m_errorMsg;
    bool m_loading = false;
};

int main(int argc, char **argv)
{
    QCoreApplication::setApplicationName(QStringLiteral("departurequery"));
    QCoreApplication::setOrganizationName(QStringLiteral("KDE"));
    QCoreApplication::setOrganizationDomain(QStringLiteral("kde.org"));

    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
    QApplication app(argc, argv);

    QueryManager mgr;
    QQmlApplicationEngine engine;
    mgr.engine = &engine;
    engine.rootContext()->setContextProperty(QStringLiteral("_queryMgr"), &mgr);
    engine.load(QStringLiteral("qrc:/departurequery.qml"));
    return app.exec();
}

#include "departurequery.moc"
