/*
    SPDX-FileCopyrightText: 2024 Jonah Brüchert <jbb@kaidan.im>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#pragma once

#include <QObject>
#include <QNetworkReply>

/// Tracks completion and errors of a number of QNetworkReplies
class NetworkReplyCollection : public QObject {
    Q_OBJECT

public:
    NetworkReplyCollection(std::vector<QNetworkReply *> replies, QObject *parent = nullptr);

    /// Emitted when all tracked replies finished
    Q_SIGNAL void allFinished();

    /// Emitted every time one of the replies has an error
    Q_SIGNAL void errorOccured(QNetworkReply *, QNetworkReply::NetworkError error);

    std::vector<QNetworkReply *> replies() {
        return m_replies;
    }

private:
    void checkFinished() {
        bool finished = std::all_of(m_replies.begin(), m_replies.end(), [](QNetworkReply *reply) {
            return !reply || reply->isFinished();
        });
        if (finished) {
            Q_EMIT allFinished();
        }
    }

    std::vector<QNetworkReply *> m_replies;
};
