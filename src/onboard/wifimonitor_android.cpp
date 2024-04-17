/*
    SPDX-FileCopyrightText: 2022 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "wifimonitor_p.h"
#include "logging.h"

#include <QSharedData>

#include <private/qandroidextras_p.h>
#include <QCoreApplication>
#include <QJniEnvironment>
#include <QJniObject>

using namespace KPublicTransport;

namespace KPublicTransport {
class WifiMonitorBackend : public QSharedData
{
public:
    void setSsid(const QString &ssid);
    void setStatus(int statusCode);

    std::vector<WifiMonitor*> frontends;
    WifiMonitor::Status status = WifiMonitor::NotAvailable;
    QJniObject wifiMonitor;
};
}

void WifiMonitorBackend::setSsid(const QString &ssid)
{
    for (auto m : frontends) {
        m->setSsid(ssid);
    }
}

void WifiMonitorBackend::setStatus(int statusCode)
{
    if (status == statusCode) {
        return;
    }
    status = static_cast<WifiMonitor::Status>(statusCode);
    for (auto m : frontends) {
        Q_EMIT m->statusChanged();
    }
}

static WifiMonitorBackend *s_backend = nullptr;

static void setSsid(JNIEnv *env, [[maybe_unused]] jobject that, jstring ssid)
{
    if (s_backend) {
        const char *str = env->GetStringUTFChars(ssid, nullptr);
        s_backend->setSsid(QString::fromUtf8(str));
        env->ReleaseStringUTFChars(ssid, str);
    }
}

static void setStatus([[maybe_unused]] JNIEnv *env, [[maybe_unused]] jobject that, jint statusCode)
{
    if (s_backend) {
        s_backend->setStatus(statusCode);
    }
}

static const JNINativeMethod methods[] = {
    {"setSsid", "(Ljava/lang/String;)V", (void *)setSsid},
    {"setStatus", "(I)V", (void *)setStatus},
};

WifiMonitor::WifiMonitor(QObject *parent)
    : QObject(parent)
{
    static bool nativesRegistered = false;
    if (!nativesRegistered) {
        QJniEnvironment env;
        jclass cls = env->FindClass("org/kde/publictransport/onboard/WifiMonitor");
        if (env->RegisterNatives(cls, methods, sizeof(methods) / sizeof(JNINativeMethod)) < 0) {
            qCWarning(Log) << "Failed to register native functions!";
        }
        nativesRegistered = true;
    }

    if (!s_backend) {
        s_backend = new WifiMonitorBackend;
#if QT_VERSION >= QT_VERSION_CHECK(6, 7, 0)
        s_backend->wifiMonitor = QJniObject("org/kde/publictransport/onboard/WifiMonitor", QNativeInterface::QAndroidApplication::context());
#else
        s_backend->wifiMonitor = QJniObject("org/kde/publictransport/onboard/WifiMonitor", "(Landroid/content/Context;)V",
                                            QNativeInterface::QAndroidApplication::context());
#endif
    }

    s_backend->ref.ref();
    s_backend->frontends.push_back(this);
}

WifiMonitor::~WifiMonitor()
{
    s_backend->ref.deref();
    if (!s_backend->ref) {
        delete s_backend;
        s_backend = nullptr;
    } else {
        auto it = std::find(s_backend->frontends.begin(), s_backend->frontends.end(), this);
        if (it != s_backend->frontends.end()) {
            s_backend->frontends.erase(it);
        }
    }
}

WifiMonitor::Status WifiMonitor::status() const
{
    return s_backend->status;
}

void WifiMonitor::requestPermissions()
{
    // TODO make this properly async
    QtAndroidPrivate::requestPermission(QStringLiteral("android.permission.ACCESS_FINE_LOCATION"));
    s_backend->wifiMonitor.callMethod<void>("checkStatus", "()V");
}
