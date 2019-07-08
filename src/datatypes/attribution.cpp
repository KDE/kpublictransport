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

#include "attribution.h"

#include <QString>
#include <QUrl>

using namespace KPublicTransport;

namespace KPublicTransport {

class AttributionPrivate : public QSharedData {
public:
    QString name;
    QUrl url;
    QString license;
    QUrl licenseUrl;
};
}

Attribution::Attribution()
    : d(new AttributionPrivate)
{}

Attribution::Attribution(const Attribution&) = default;
Attribution::~Attribution() = default;
Attribution& Attribution::operator=(const Attribution&) = default;

QString Attribution::name() const
{
    return d->name;
}

void Attribution::setName(const QString &name)
{
    d.detach();
    d->name = name;
}

QUrl Attribution::url() const
{
    return d->url;
}

void Attribution::setUrl(const QUrl &url)
{
    d.detach();
    d->url = url;
}

QString Attribution::license() const
{
    return d->license;
}

void Attribution::setLicense(const QString &license)
{
    d.detach();
    d->license = license;
}

QUrl Attribution::licenseUrl() const
{
    return d->licenseUrl;
}

void Attribution::setLicenseUrl(const QUrl &url)
{
    d.detach();
    d->licenseUrl = url;
}

#include "moc_attribution.cpp"
