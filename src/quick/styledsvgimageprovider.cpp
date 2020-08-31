/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "styledsvgimageprovider.h"

#include <QBuffer>
#include <QDebug>
#include <QFile>
#include <QGuiApplication>
#include <QImageReader>
#include <QUrlQuery>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>

using namespace KPublicTransport;

StyledSvgImageProvider::StyledSvgImageProvider()
    : QQuickImageProvider(QQuickImageProvider::Image)
{
}

StyledSvgImageProvider::~StyledSvgImageProvider() = default;

QImage StyledSvgImageProvider::requestImage(const QString &id, QSize *size, const QSize &requestedSize)
{
    qDebug() << id << requestedSize;

    // decode id
    const auto idx = id.indexOf(QLatin1Char('?'));
    const auto svgName = idx >= 0 ? id.left(idx) : id;
    const QUrlQuery svgArgs(idx < 0 ? QString() : id.mid(idx + 1));
    qDebug() << svgName << svgArgs.queryItems();

    // find SVG
    const QString svgFileName = QLatin1String(":/org.kde.kpublictransport/ui/assets/") + svgName + QLatin1String(".svg");
    QFile svgFile(svgFileName);
    if (!svgFile.open(QFile::ReadOnly)) {
        qWarning() << "Failed to open SVG file:" << svgFile.fileName() << svgFile.errorString();
        return {};
    }

    // prepare CSS
    QFile cssFile(QStringLiteral(":/org.kde.kpublictransport/ui/assets/style.css"));
    if (!cssFile.open(QFile::ReadOnly)) {
        qWarning() << "Failed to open CSS file:" << cssFile.fileName() << cssFile.errorString();
        return {};
    }
    auto css = QString::fromUtf8(cssFile.readAll());
    const auto cssItems = svgArgs.queryItems();
    for (const auto &cssItem : cssItems) {
        css.replace(QLatin1String("{{") + cssItem.first + QLatin1String("}}"), cssItem.second);
    }

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
    imgReader.setScaledSize(imgReader.size() * qGuiApp->devicePixelRatio());
    auto img = imgReader.read();
    img.setDevicePixelRatio(qGuiApp->devicePixelRatio());
    *size = imgReader.size();
    return img;
}
