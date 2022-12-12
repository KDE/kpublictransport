/*
    SPDX-FileCopyrightText: 2022 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_RESTONBOARDBACKEND_H
#define KPUBLICTRANSPORT_RESTONBOARDBACKEND_H

#include "kpublictransportonboard_export.h"
#include "abstractonboardbackend_p.h"

class QNetworkRequest;

namespace KPublicTransport {

/** Backend that uses an REST API.
 *  Primarily used as interface for unit tests of parser code.
 *  @internal exported only for unit tests
 */
class KPUBLICTRANSPORTONBOARD_EXPORT RestOnboardBackend : public AbstractOnboardBackend
{
    Q_OBJECT
public:
    ~RestOnboardBackend();

    void requestPosition(QNetworkAccessManager *nam) override final;
    void requestJourney(QNetworkAccessManager *nam) override final;

    virtual QNetworkRequest createPositionRequest() const = 0;
    virtual QNetworkRequest createJourneyRequest() const = 0;
    virtual PositionData parsePositionData(const QJsonValue &response) const = 0;
    virtual Journey parseJourneyData(const QJsonValue &response) const = 0;

protected:
    explicit RestOnboardBackend(QObject *parent = nullptr);
};

}

#endif // KPUBLICTRANSPORT_RESTONBOARDBACKEND_H
