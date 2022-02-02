/*
    SPDX-FileCopyrightText: 2020-2022 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "styledframesvgitem.h"

#include <QBuffer>
#include <QDebug>
#include <QFile>
#include <QImageReader>
#include <QPainter>
#include <QQuickWindow>
#include <QUrlQuery>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>

using namespace KPublicTransport;

StyledFrameSvgItem::StyledFrameSvgItem(QQuickItem *parent)
    : QQuickPaintedItem(parent)
{
    const auto updateFunc = [this]() { update(); };
    connect(this, &StyledFrameSvgItem::borderTopChanged, this, updateFunc);
    connect(this, &StyledFrameSvgItem::borderBottomChanged, this, updateFunc);
    connect(this, &StyledFrameSvgItem::borderLeftChanged, this, updateFunc);
    connect(this, &StyledFrameSvgItem::borderRightChanged, this, updateFunc);
    connect(this, &StyledFrameSvgItem::colorChanged, this, &StyledFrameSvgItem::invalidateImage);
    connect(this, &StyledFrameSvgItem::sourceChanged, this, &StyledFrameSvgItem::invalidateImage);

    setImplicitSize(48, 48);
}

StyledFrameSvgItem::~StyledFrameSvgItem() = default;

void StyledFrameSvgItem::paint(QPainter *painter)
{
    loadImage();
    if (m_image.isNull()) {
        return;
    }

    const auto dpr = window()->devicePixelRatio();
    const double xSrcOffsets[4] = { 0.0, m_borderLeft * dpr, m_image.width() - m_borderRight * dpr, (double)m_image.width() };
    const double ySrcOffsets[4] = { 0.0, m_borderTop * dpr, m_image.height() - m_borderBottom * dpr, (double)m_image.height() };
    const double xDestOffsets[4] = { 0.0, m_borderLeft, width() - m_borderRight, width() };
    const double yDestOffsets[4] = { 0.0, m_borderTop, height() - m_borderBottom, height() };

    for (int xi = 0; xi < 3; ++xi) {
        for (int yi = 0; yi < 3; ++yi) {
            QRectF srcRect(QPointF(xSrcOffsets[xi], ySrcOffsets[yi]), QPointF(xSrcOffsets[xi + 1], ySrcOffsets[yi + 1]));
            QRectF destRect(QPointF(xDestOffsets[xi], yDestOffsets[yi]), QPointF(xDestOffsets[xi + 1], yDestOffsets[yi + 1]));
            if (srcRect.width() <= 0 || srcRect.height() <= 0) {
                continue;
            }
            painter->drawImage(destRect, m_image, srcRect);
        }
    }
}

void StyledFrameSvgItem::invalidateImage()
{
    m_image = {};
    update();
}

void StyledFrameSvgItem::loadImage()
{
    if (!m_image.isNull() || m_source.isEmpty()) {
        return;
    }

    // find SVG
    QFile svgFile(m_source);
    if (!svgFile.open(QFile::ReadOnly)) {
        qWarning() << "Failed to open SVG file:" << svgFile.fileName() << svgFile.errorString();
        return;
    }

    // prepare CSS
    QFile cssFile(QStringLiteral(":/org.kde.kpublictransport/ui/assets/style.css"));
    if (!cssFile.open(QFile::ReadOnly)) {
        qWarning() << "Failed to open CSS file:" << cssFile.fileName() << cssFile.errorString();
        return;
    }
    auto css = QString::fromUtf8(cssFile.readAll());
    css.replace(QLatin1String("{{fillColor}}"), m_fillColor.name(QColor::HexArgb));
    css.replace(QLatin1String("{{lineColor}}"), m_lineColor.name(QColor::HexArgb));

    // inject CSS (inspired by KIconLoader)
    QByteArray processedContents;
    QXmlStreamReader reader(&svgFile);
    QBuffer buffer(&processedContents);
    buffer.open(QIODevice::WriteOnly);
    QXmlStreamWriter writer(&buffer);
    while (!reader.atEnd()) {
        if (reader.readNext() == QXmlStreamReader::StartElement &&
            reader.qualifiedName() == QLatin1String("style") &&
            reader.attributes().value(QLatin1String("id")) == QLatin1String("current-color-scheme")) {
            writer.writeStartElement(QStringLiteral("style"));
            writer.writeAttributes(reader.attributes());
            writer.writeCharacters(css);
            writer.writeEndElement();
            while (reader.tokenType() != QXmlStreamReader::EndElement) {
                reader.readNext();
            }
        } else if (reader.tokenType() != QXmlStreamReader::Invalid) {
            writer.writeCurrentToken(reader);
        }
    }
    buffer.close();

    // render SVG
    buffer.open(QIODevice::ReadOnly);
    buffer.seek(0);
    QImageReader imgReader(&buffer, "svg");
    imgReader.setScaledSize(imgReader.size() * window()->devicePixelRatio());
    m_image = imgReader.read();
    m_image.setDevicePixelRatio(window()->devicePixelRatio());
    setImplicitSize(imgReader.size().width(), m_image.size().height());
}
