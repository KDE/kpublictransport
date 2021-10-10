/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include <../lib/datatypes/backend_p.h>
#include <../lib/backends/hafasmgatebackend.h>

#include <KPublicTransport/Backend>
#include <KPublicTransport/Manager>

#include <QCoreApplication>
#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>

using namespace KPublicTransport;

static void listConGroups(const QByteArray &data)
{
    const auto svcResL = QJsonDocument::fromJson(data).object().value(QLatin1String("svcResL")).toArray();
    if (svcResL.empty()) {
        qDebug() << "empty reponse" << data;
        return;
    }

    const auto res = svcResL.at(0).toObject().value(QLatin1String("res")).toObject();
    const auto conGrpL = res.value(QLatin1String("conGrpL")).toArray();
    for (const auto &conGrpV : conGrpL) {
        const auto conGrpObj = conGrpV.toObject();
        qDebug() << conGrpObj.value(QLatin1String("name")).toString();
        const auto requests = conGrpObj.value(QLatin1String("requests")).toArray();
        for (const auto requestV : requests) {
            const auto requestObj = requestV.toObject();
            qDebug() << "    " << requestObj.value(QLatin1String("id")).toString();
        }
    }
}

int main(int argc, char **argv)
{
    QCoreApplication app(argc, argv);

    QNetworkAccessManager nam;
    nam.setRedirectPolicy(QNetworkRequest::NoLessSafeRedirectPolicy);

    Manager ptMgr;
    int jobCount = 0;

    for (const auto &backend : ptMgr.backends()) {
        const auto impl = dynamic_cast<const HafasMgateBackend*>(BackendPrivate::impl(backend));
        if (!impl) {
            continue;
        }

        QJsonObject req;
        req.insert(QLatin1String("getConGroups"), true);
        QJsonObject serverInfo;
        serverInfo.insert(QStringLiteral("meth"), QLatin1String("ServerInfo"));
        serverInfo.insert(QStringLiteral("req"), req);

        QByteArray postData;
        const auto netReq = impl->makePostRequest(serverInfo, postData);
        ++jobCount;
        auto netReply = nam.post(netReq, postData);
        QObject::connect(netReply, &QNetworkReply::finished, &nam, [netReply, &jobCount, backend]() {
            --jobCount;
            netReply->deleteLater();

            qDebug() << "************************************************" << backend.identifier();
            if (netReply->error() != QNetworkReply::NoError) {
                qWarning() << netReply->errorString();
            } else {
                listConGroups(netReply->readAll());
            }

            if (jobCount == 0) {
                QCoreApplication::quit();
            }
        });
    }

    return app.exec();
}
