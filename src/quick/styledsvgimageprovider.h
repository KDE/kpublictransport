/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_STYLEDSVGIMAGEPROVIDER_H
#define KPUBLICTRANSPORT_STYLEDSVGIMAGEPROVIDER_H

#include <QQuickImageProvider>

namespace KPublicTransport {

/** Image provider injecting a CSS style sheet into an SVG, based on URI parameters. */
class StyledSvgImageProvider : public QQuickImageProvider
{
public:
    explicit StyledSvgImageProvider();
    ~StyledSvgImageProvider() override;
    QImage requestImage(const QString &id, QSize *size, const QSize &requestedSize) override;
};

}

#endif // KPUBLICTRANSPORT_STYLEDSVGIMAGEPROVIDER_H
