/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "iconloader.h"

#include <QBuffer>
#include <QByteArray>
#include <QFile>
#include <QGuiApplication>
#include <QIcon>
#include <QImageReader>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>

using namespace KOSMIndoorMap;

QIcon IconLoader::loadIcon(const IconData &iconData) const
{
//     qDebug() << "loading" << iconData.name << iconData.color << iconData.size;
    // TODO we might want to add a cache here for the colorized SVG icons...

    // check if it's one of our bundled assets
    const QString path = QLatin1String(":/org.kde.kosmindoormap/assets/icons/") + iconData.name + QLatin1String(".svg");
    QFile f(path);
    if (f.open(QFile::ReadOnly)) {
        return loadSvgAsset(&f, iconData);
    }

    // TODO file system URLs

    // XDG icons
    return QIcon::fromTheme(iconData.name);
}

QIcon IconLoader::loadSvgAsset(QIODevice *svgFile, const IconData &iconData) const
{
    // prepare CSS
    const QString css = QLatin1String(".ColorScheme-Text { color:") + iconData.color.name(QColor::HexArgb) + QLatin1String("; }");

    // inject CSS (inspired by KIconLoader)
    QByteArray processedContents;
    QXmlStreamReader reader(svgFile);
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
    imgReader.setScaledSize((iconData.size.isValid() ? iconData.size.toSize() : imgReader.size()) * qGuiApp->devicePixelRatio());
    auto img = imgReader.read();
    img.setDevicePixelRatio(qGuiApp->devicePixelRatio());
    return QIcon(QPixmap::fromImage(std::move(img)));
}
