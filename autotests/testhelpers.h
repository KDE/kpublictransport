/*
    SPDX-FileCopyrightText: 2019-2021 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef TESTHELPERS_H
#define TESTHELPERS_H

#include <QFile>
#include <QJsonDocument>
#include <QProcess>
#include <QTest>

namespace Test {
    QByteArray readFile(const QString &fn)
    {
        QFile f(fn);
        f.open(QFile::ReadOnly | QFile::Text);
        return f.readAll();
    }

    template <typename T>
    inline bool compareJson(const QString &refFile, const T &output, const T &ref)
    {
        if (output != ref) {
            QFile failFile(refFile + QLatin1String(".fail"));
            failFile.open(QFile::WriteOnly);
            failFile.write(QJsonDocument(output).toJson());
            failFile.close();

            QProcess proc;
            proc.setProcessChannelMode(QProcess::ForwardedChannels);
            proc.start(QStringLiteral("diff"), {QStringLiteral("-u"), refFile, failFile.fileName()});
            if (!proc.waitForFinished()) {
                // e.g. Windows CI not having diff
                qDebug() << "Actual:";
                qDebug().noquote() << output;
                qDebug() << "Expected:";
                qDebug().noquote() << ref;
            }
            return false;
        }
        return true;
    }

    inline bool compareXml(const QString &refFile, const QByteArray &output, const QByteArray &ref)
    {
        if (output != ref) {
            QFile failFile(refFile + QLatin1String(".fail"));
            failFile.open(QFile::WriteOnly);
            failFile.write(output);
            failFile.close();

            QProcess proc;
            proc.setProcessChannelMode(QProcess::ForwardedChannels);
            proc.start(QStringLiteral("diff"), {QStringLiteral("-u"), refFile, failFile.fileName()});
            if (!proc.waitForFinished()) {
                // e.g. Windows CI not having diff
                qDebug() << "Actual:";
                qDebug().noquote() << output;
                qDebug() << "Expected:";
                qDebug().noquote() << ref;
            }
            return false;
        }
        return true;
    }

}

#endif
