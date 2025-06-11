/*
    SPDX-FileCopyrightText: 2018 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "abstractbackend.h"
#include "logging.h"
#include "http/useragent_p.h"
#include "standardpaths_p.h"

#include <KPublicTransport/JourneyReply>
#include <KPublicTransport/JourneyRequest>
#include <KPublicTransport/Location>

#include <QDebug>
#include <QDir>
#include <QJsonDocument>
#include <QNetworkReply>

using namespace Qt::Literals::StringLiterals;
using namespace KPublicTransport;

AbstractBackend::AbstractBackend() = default;
AbstractBackend::~AbstractBackend() = default;

QString AbstractBackend::backendId() const
{
    return m_backendId;
}

void AbstractBackend::setBackendId(const QString& id)
{
    m_backendId = id;
}

QTimeZone AbstractBackend::timeZone() const
{
    return m_timeZone;
}

void AbstractBackend::setTimeZone(const QTimeZone &tz)
{
    m_timeZone = tz;
}

QStringList AbstractBackend::supportedLanguages() const
{
    return m_supportedLanguages;
}

void AbstractBackend::setSupportedLanguages(const QStringList &langs)
{
    m_supportedLanguages = langs;
}

QString AbstractBackend::preferredLanguage() const
{
    const auto localeLangs = QLocale().uiLanguages();
    for (const auto &l : localeLangs) {
        if (m_supportedLanguages.contains(l)) {
            return l;
        }
        if (l.size() > 2 && l[2] == QLatin1Char('-') && m_supportedLanguages.contains(QStringView(l).left(2))) {
            return l.left(2);
        }
    }

    if (!m_supportedLanguages.empty()) {
        return m_supportedLanguages.at(0);
    }
    return QStringLiteral("en");
}

QStringList AbstractBackend::preferredLanguages() const
{
    QStringList langs;
    const auto localeLangs = QLocale().uiLanguages();
    for (const auto &l : localeLangs) {
        if (m_supportedLanguages.contains(l)) {
            if (!langs.contains(l)) {
                langs.push_back(l);
            }
            continue;
        }
        if (l.size() <= 2 || l[2] != '-'_L1) {
            continue;
        }
        if (const auto l2 = QStringView(l).left(2); m_supportedLanguages.contains(l2) && !langs.contains(l2)) {
            langs.push_back(l2.toString());
        }
    }

    // ensure this is never empty
    if (langs.empty() && !localeLangs.empty()) {
        langs.push_back(localeLangs.front().left(2));
    }

    return langs;
}

void AbstractBackend::init()
{
}

AbstractBackend::Capabilities AbstractBackend::capabilities() const
{
    return NoCapability;
}

bool AbstractBackend::needsLocationQuery(const Location &loc, QueryType type) const
{
    Q_UNUSED(loc);
    Q_UNUSED(type);
    return false;
}

bool AbstractBackend::queryStopover(const StopoverRequest &request, StopoverReply *reply, QNetworkAccessManager *nam) const
{
    Q_UNUSED(request);
    Q_UNUSED(reply);
    Q_UNUSED(nam);
    return false;
}

bool AbstractBackend::queryJourney(const JourneyRequest &request, JourneyReply *reply, QNetworkAccessManager *nam) const
{
    Q_UNUSED(request);
    Q_UNUSED(reply);
    Q_UNUSED(nam);
    return false;
}

bool AbstractBackend::queryLocation(const LocationRequest &request, LocationReply *reply, QNetworkAccessManager *nam) const
{
    Q_UNUSED(request);
    Q_UNUSED(reply);
    Q_UNUSED(nam);
    return false;
}

void AbstractBackend::addAttributions(Reply *reply, std::vector<Attribution> &&attributions)
{
    reply->addAttributions(std::move(attributions));
}

Attribution AbstractBackend::attribution() const
{
    return m_attribution;
}

void AbstractBackend::setAttribution(const Attribution &attr)
{
    m_attribution = attr;
}

bool AbstractBackend::isLoggingEnabled() const
{
    return qEnvironmentVariableIsSet("KPUBLICTRANSPORT_LOG_DIR");
}

QString AbstractBackend::logDir() const
{
    const QString dir = qEnvironmentVariable("KPUBLICTRANSPORT_LOG_DIR") + QLatin1Char('/') + m_backendId + QLatin1Char('/');
    QDir().mkpath(dir);
    return dir;
}

void AbstractBackend::logRequest(const char *typeName, const QJsonObject &requestData, const QNetworkRequest &netRequest, const QByteArray &postData) const
{
    const QString baseFile = logDir() + QDateTime::currentDateTime().toString(QStringLiteral("yyyyMMddThhmmss.zzz")) + QLatin1Char('-') + QLatin1String(typeName);

    if (!postData.isEmpty()) {
        QFile dataFile(baseFile + QLatin1String("-3-post-data"));
        if (!dataFile.open(QFile::WriteOnly)) {
            qCWarning(Log) << "could not open" << dataFile.fileName() << dataFile.errorString();
            return;
        }
        dataFile.write(postData);
    }

    QFile httpFile(baseFile + QLatin1String("-2-http-request.txt"));

    qCWarning(Log) << "Logging requests to: " << httpFile.fileName();

    if (!httpFile.open(QFile::WriteOnly)) {
        qCWarning(Log) << "could not open" << httpFile.fileName() << httpFile.error();
        return;
    }
    httpFile.write(netRequest.url().toString().toUtf8());
    httpFile.write("\n");
    const auto headers = netRequest.rawHeaderList();
    for (const auto &header : headers) {
        httpFile.write(header);
        httpFile.write(": ");
        httpFile.write(netRequest.rawHeader(header));
        httpFile.write("\n");
    }

    QFile reqFile(baseFile + QLatin1String("-1-request.json"));
    if (!reqFile.open(QFile::WriteOnly)) {
        qCWarning(Log) << "could not open" << reqFile.fileName() << reqFile.error();
        return;
    }
    reqFile.write(QJsonDocument(requestData).toJson());
}

void AbstractBackend::logReply(const char *typeName, QNetworkReply *netReply, const QByteArray &data) const
{
    const QString baseFile = logDir() + QDateTime::currentDateTime().toString(QStringLiteral("yyyyMMddThhmmss.zzz")) + QLatin1Char('-') + QLatin1String(typeName);

    if (!data.isEmpty()) {
        const auto contentType = netReply->header(QNetworkRequest::ContentTypeHeader).toString();
        QString ext;
        if (contentType == QLatin1String("application/json") || data.startsWith("{")) {
            ext = QStringLiteral(".json");
        } else if (contentType == QLatin1String("application/xml") || data.startsWith("<")) {
            ext = QStringLiteral(".xml");
        } else if (data.startsWith("\x1f\x8b")) {
            ext = QStringLiteral(".gz");
        }

        QFile dataFile(baseFile + QLatin1String("-5-reply-data") + ext);
        if (!dataFile.open(QFile::WriteOnly)) {
            qCWarning(Log) << "could not open" << dataFile.fileName() << dataFile.errorString();
            return;
        }
        dataFile.write(data);
    }

    QFile httpFile(baseFile + QLatin1String("-4-http-reply.txt"));
    if (!httpFile.open(QFile::WriteOnly)) {
        qCWarning(Log) << "could not open" << httpFile.fileName() << httpFile.error();
        return;
    }
    httpFile.write(netReply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toString().toUtf8());
    httpFile.write(" ");
    httpFile.write(netReply->attribute(QNetworkRequest::HttpReasonPhraseAttribute).toString().toUtf8());
    httpFile.write("\n");
    const auto &headers = netReply->rawHeaderPairs();
    for (const auto &header : headers) {
        httpFile.write(header.first);
        httpFile.write(": ");
        httpFile.write(header.second);
        httpFile.write("\n");
    }
}

bool AbstractBackend::queryTrip([[maybe_unused]] const TripRequest &request, [[maybe_unused]] TripReply *reply, [[maybe_unused]] QNetworkAccessManager *nam) const
{
    return false;
}

bool AbstractBackend::queryVehicleLayout(const VehicleLayoutRequest &request, VehicleLayoutReply *reply, QNetworkAccessManager *nam) const
{
    Q_UNUSED(request);
    Q_UNUSED(reply);
    Q_UNUSED(nam);
    return false;
}

void AbstractBackend::setCustomCaCertificate(const QString &caCert)
{
    QFile f(StandardPaths::locateFile("networks/certs/"_L1 + caCert));
    if (!f.open(QFile::ReadOnly)) {
        qCWarning(Log) << f.fileName() << f.errorString();
        return;
    }
    m_customCaCerts = QSslCertificate::fromDevice(&f, QSsl::Pem);
}

void AbstractBackend::setPkcs12(const QString &pkcs12Name)
{
    QFile f(StandardPaths::locateFile("networks/certs/"_L1 + pkcs12Name));
    if (!f.open(QFile::ReadOnly)) {
        qCWarning(Log) << f.fileName() << f.errorString();
        return;
    }
    QList<QSslCertificate> caCerts;
    const auto r = QSslCertificate::importPkcs12(&f, &m_privateKey, &m_clientCert, &caCerts, "");
    if (!r) {
        qCWarning(Log) << "Failed to load PKCS#12 bundle" << f.fileName();
    }
}

void AbstractBackend::applySslConfiguration(QNetworkRequest &request) const
{
    auto sslConfig = request.sslConfiguration();
    if (!m_customCaCerts.empty()) {
        sslConfig.setCaCertificates(m_customCaCerts);
    }
    if (!m_clientCert.isNull()) {
        sslConfig.setLocalCertificate(m_clientCert);
    }
    if (!m_privateKey.isNull()) {
        sslConfig.setPrivateKey(m_privateKey);
    }
    request.setSslConfiguration(std::move(sslConfig));
}

void AbstractBackend::applyUserAgent(QNetworkRequest &request)
{
    request.setHeader(QNetworkRequest::UserAgentHeader, Http::userAgent().toUtf8());
}
