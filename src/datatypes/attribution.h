/*
    Copyright (C) 2019 Volker Krause <vkrause@kde.org>

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

#ifndef KPUBLICTRANSPORT_ATTRIBUTION_H
#define KPUBLICTRANSPORT_ATTRIBUTION_H

#include "kpublictransport_export.h"

#include <QExplicitlySharedDataPointer>
#include <QMetaType>

class QString;
class QUrl;

namespace KPublicTransport {

class AttributionPrivate;

/** Copyright and license information about the provided data.
 *  Should be displayed by the application in order to comply with licenses and/or terms and conditions
 *  of the data providers.
 */
class KPUBLICTRANSPORT_EXPORT Attribution
{
    Q_GADGET
    /** Name of the entity providing the data. */
    Q_PROPERTY(QString name READ name WRITE setName)
    /** Link to the entity providing the data. */
    Q_PROPERTY(QUrl url READ url WRITE setUrl)
    /** Name of the license for the provided data. */
    Q_PROPERTY(QString license READ license WRITE setLicense)
    /** Link to the license or terms and conditions text. */
    Q_PROPERTY(QUrl licenseUrl READ licenseUrl WRITE setLicenseUrl)

public:
    explicit Attribution();
    Attribution(const Attribution&);
    ~Attribution();
    Attribution& operator=(const Attribution&);

    QString name() const;
    void setName(const QString &name);

    QUrl url() const;
    void setUrl(const QUrl &url);

    QString license() const;
    void setLicense(const QString &license);

    QUrl licenseUrl() const;
    void setLicenseUrl(const QUrl &url);

private:
    QExplicitlySharedDataPointer<AttributionPrivate> d;
};

}

Q_DECLARE_METATYPE(KPublicTransport::Attribution)

#endif // KPUBLICTRANSPORT_ATTRIBUTION_H
