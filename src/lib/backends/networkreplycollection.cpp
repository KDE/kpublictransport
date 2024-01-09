/*
    SPDX-FileCopyrightText: 2024 Jonah Brüchert <jbb@kaidan.im>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "networkreplycollection.h"

NetworkReplyCollection::NetworkReplyCollection(std::vector<QNetworkReply *> replies, QObject *parent)
    : QObject(parent)
{
    m_replies = std::move(replies);
    checkFinished();

    for (auto *reply : m_replies) {
        connect(reply, &QNetworkReply::finished, this, &NetworkReplyCollection::checkFinished);
        connect(reply, &QNetworkReply::errorOccurred, this, [reply, this](auto error) {
            Q_EMIT errorOccured(reply, error);
        });
    }
}
