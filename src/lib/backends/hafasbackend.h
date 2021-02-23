/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_HAFASBACKEND_H
#define KPUBLICTRANSPORT_HAFASBACKEND_H

#include "abstractbackend.h"

#include <KPublicTransport/Line>

#include <unordered_map>

namespace KPublicTransport {

/** Base class for Hafas-based backends. */
class HafasBackend : public AbstractBackend
{
    Q_GADGET
    Q_PROPERTY(QString endpoint MEMBER m_endpoint)
    Q_PROPERTY(QJsonArray products WRITE setProductsMap)
    Q_PROPERTY(QJsonObject lineModeMap WRITE setLineModeMap)
    /** Identifier type used for stations. Default is backendId(). */
    Q_PROPERTY(QString locationIdentifierType MEMBER m_locationIdentifierType)
    /** Standard location Identifier type ("ibnr" or "uic"), if supported by the backend. */
    Q_PROPERTY(QString standardLocationIdentifierType MEMBER m_standardLocationIdentifierType)
    /** UIC country codes for countries this produces valid IBNR or UIC station codes. */
    Q_PROPERTY(QJsonArray standardLocationIdentifierCountries WRITE setStandardLocationIdentifierCountries)

protected:
    QString locationIdentifierType() const;
    QString standardLocationIdentifierType() const;
    QString locationIdentifier(const Location &loc) const;

    QString m_endpoint;
    std::unordered_map<int, Line::Mode> m_lineModeMap;
    std::vector<uint8_t> m_uicCountryCodes;

private:
    void setStandardLocationIdentifierCountries(const QJsonArray &a);

    void setProductsMap(const QJsonArray &array);
    void setLineModeMap(const QJsonObject &obj);
    QString m_locationIdentifierType;
    QString m_standardLocationIdentifierType;
};

}

#endif // KPUBLICTRANSPORT_HAFASBACKEND_H
