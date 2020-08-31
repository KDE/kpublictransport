/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include <kgraphql.h>

#include <QCommandLineParser>
#include <QCoreApplication>
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkAccessManager>

#include <iostream>

#define S(x) QStringLiteral(x)

int main(int argc, char **argv)
{
    QCoreApplication app(argc, argv);
    QCommandLineParser parser;
    parser.setApplicationDescription(S("graphql-cli"));
    parser.addHelpOption();
    QCommandLineOption endpointOption({ S("u"), S("url") }, S("GraphQL query endpoint"), S("url"));
    parser.addOption(endpointOption);
    QCommandLineOption queryOption({ S("q"), S("query") }, S("GraphQL query to run"), S("query-file"));
    parser.addOption(queryOption);
    QCommandLineOption variableOption({ S("v"), S("variable") }, S("GraphQL variable"), S("variable=value"));
    parser.addOption(variableOption);
    parser.process(app);

    QNetworkAccessManager nam;
    nam.setRedirectPolicy(QNetworkRequest::NoLessSafeRedirectPolicy);

    KGraphQLRequest req(QUrl(parser.value(endpointOption)));
    req.setQueryFromFile(parser.value(queryOption));

    for (const auto &var : parser.values(variableOption)) {
        const auto split = var.split(QLatin1Char('='));
        if (split.size() != 2) {
            continue;
        }

        bool ok = false;
        float num = split[1].toFloat(&ok);
        if (ok) {
            req.setVariable(split[0], num);
        } else {
            req.setVariable(split[0], split[1]);
        }
    }

    KGraphQL::query(req, &nam, [&app](const KGraphQLReply &reply) {
        switch (reply.error()) {
            case KGraphQLReply::NoError:
                std::cout << QJsonDocument(reply.data()).toJson().constData() << std::endl;
                break;
            case KGraphQLReply::NetworkError:
                std::cerr << "Network error: " << qPrintable(reply.errorString()) << std::endl;
                break;
            case KGraphQLReply::QueryError:
                std::cerr << "Query error: " << qPrintable(reply.errorString()) << std::endl;
                break;
        }
        app.quit();
    });

    return app.exec();
}
