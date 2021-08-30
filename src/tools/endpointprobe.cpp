/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include <QCoreApplication>
#include <QDebug>
#include <QDirIterator>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QRectF>

#include <deque>
#include <iostream>

class Job
{
public:
    QString fileName;
    QUrl endpoint;
    QList<QSslCertificate> caCert;

    enum Task {
        HttpsProbe,
        HttpsCustomCaProbe,
        HttpProbe,
    };
    int task = HttpsProbe;
};

class EndpointProber : public QObject
{
    Q_OBJECT
public:
    void addJob(Job &&job);

Q_SIGNALS:
    void finished();

public:
    void processNext();
    QNetworkAccessManager m_nam;

private:
    std::deque<Job> m_queue;
    bool m_jobRunning = false;
};


void EndpointProber::addJob(Job &&job)
{
    // we need to do this strictly sequential, so we can reset the QNAM connection cache
    // without doing that changes to the SSL config will have no effect
    m_queue.push_back(std::move(job));
    processNext();
}

void EndpointProber::processNext()
{
    if (m_jobRunning) {
        return;
    }
    if (m_queue.empty()) {
        Q_EMIT finished();
        return;
    }

    auto job = m_queue.front();
    m_queue.pop_front();

    QNetworkReply *reply = nullptr;
    switch (job.task) {
        case Job::HttpsProbe:
        {
            auto url = job.endpoint;
            url.setScheme(QStringLiteral("https"));
            qDebug() << "https probe on" << job.fileName;
            reply = m_nam.get(QNetworkRequest(url));
            break;
        }
        case Job::HttpsCustomCaProbe:
        {
            if (job.caCert.isEmpty()) {
                job.task = Job::HttpProbe;
                addJob(std::move(job));
                return;
            } else {
                m_nam.clearConnectionCache();
                auto url = job.endpoint;
                url.setScheme(QStringLiteral("https"));
                QNetworkRequest req(url);
                auto sslConfig = req.sslConfiguration();
                sslConfig.setCaCertificates(job.caCert);
                req.setSslConfiguration(sslConfig);
                qDebug() << "https w/ custom CA probe on" << job.fileName;
                reply = m_nam.get(req);
            }
            break;
        }
        case Job::HttpProbe:
        {
            auto url = job.endpoint;
            url.setScheme(QStringLiteral("http"));
            qDebug() << "http probe on" << job.fileName;
            reply = m_nam.get(QNetworkRequest(url));
            break;
        }
    }

    m_jobRunning = true;
    connect(reply, &QNetworkReply::sslErrors, this, [job](const auto &errors) {
        if (job.task == Job::HttpsProbe && !job.caCert.empty()) {
            return;
        }
        qWarning() << "SSL failure on" << job.fileName;
        for (const auto &error : errors) {
            qWarning() << "  " << error << error.certificate();
        }
    });
    QObject::connect(reply, &QNetworkReply::finished, this, [this, reply, job]() {
        reply->deleteLater();
        m_jobRunning = false;
        bool success = true;
        switch (reply->error()) {
            case QNetworkReply::ConnectionRefusedError:
            case QNetworkReply::RemoteHostClosedError:
            case QNetworkReply::HostNotFoundError:
            case QNetworkReply::TimeoutError:
            case QNetworkReply::TooManyRedirectsError:
            case QNetworkReply::InsecureRedirectError:
            case QNetworkReply::UnknownNetworkError:
            case QNetworkReply::ProtocolFailure:
            case QNetworkReply::UnknownServerError:
                qWarning() << "Network error on" << job.fileName << reply->errorString() << job.task << reply->request().url();
                success = false;
                break;
            case QNetworkReply::SslHandshakeFailedError:
                success = (job.task == Job::HttpsCustomCaProbe || job.caCert.isEmpty());
                break; // handled above
            case QNetworkReply::NoError:
            case QNetworkReply::ContentNotFoundError:
            case QNetworkReply::ContentAccessDenied:
            case QNetworkReply::InternalServerError:
                break; // considered successful
            default:
                qWarning() << "Unhandled error case:" << reply->error() << reply->errorString();
                break;
        }

        // TODO update config file with the results here!
        if (success) {
            switch (job.task) {
                case Job::HttpsProbe:
                    if (job.endpoint.scheme() == QLatin1String("http")) {
                        qWarning() << job.fileName << "can be upgraded to https!";
                    }
                    break;
                case Job::HttpsCustomCaProbe:
                    qWarning() << job.fileName << "needs a custom CA workaround";
                    break;
                case Job::HttpProbe:
                    qWarning() << job.fileName << "does not support transport security!";
                    break;
            }
        } else {
            if (job.task != Job::HttpProbe) {
                auto nextJob = job;
                nextJob.task++;
                addJob(std::move(nextJob));
            } else {
                qWarning() << job.fileName << "seems dead!";
            }
        }

        processNext();
    });
}


/** Probes availabiliy of endpoint URLs and their SSL setups. */
int main(int argc, char **argv)
{
    QCoreApplication app(argc, argv);
    if (app.arguments().size() <= 1) {
        std::cerr << "Usage: " << argv[0] << " [path to network configs]" << std::endl;
        return 1;
    }

    EndpointProber prober;
    prober.m_nam.setRedirectPolicy(QNetworkRequest::NoLessSafeRedirectPolicy);

    QDirIterator it(app.arguments().at(1), QDir::Files);
    while (it.hasNext()) {
        Job job;
        job.fileName = it.next();
        QFile f(job.fileName);
        if (!f.fileName().endsWith(QLatin1String(".json"))) {
            continue;
        }
        if (!f.open(QFile::ReadOnly)) {
            qWarning() << "Failed to open" << f.fileName() << f.errorString();
            continue;
        }

        const auto doc = QJsonDocument::fromJson(f.readAll());
        const auto options = doc.object().value(QLatin1String("options")).toObject();
        job.endpoint = QUrl(options.value(QLatin1String("endpoint")).toString());
        if (!job.endpoint.isValid() || job.endpoint.scheme().isEmpty()) {
            qWarning() << "No API endpoint in" << job.fileName;
            continue;
        }
        job.caCert = QSslCertificate::fromPath(it.path() + QStringLiteral("/certs/") + options.value(QLatin1String("customCaCertificate")).toString());

        prober.addJob(std::move(job));
    }

    QObject::connect(&prober, &EndpointProber::finished, &app, &QCoreApplication::quit, Qt::QueuedConnection);
    return app.exec();
}

#include "endpointprobe.moc"
