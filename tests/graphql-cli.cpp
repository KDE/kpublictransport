/*
    Copyright (C) 2020 Volker Krause <vkrause@kde.org>

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
