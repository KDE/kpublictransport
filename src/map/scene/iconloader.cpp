/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "iconloader.h"

#include <QBuffer>
#include <QByteArray>
#include <QDebug>
#include <QFile>
#include <QGuiApplication>
#include <QIconEngine>
#include <QImageReader>
#include <QPainter>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>

using namespace KOSMIndoorMap;

/** Device pixel ratio preserving simple icon engine for our SVG assets. */
class IconEngine : public QIconEngine
{
public:
    explicit IconEngine(QImage &&img)
        : m_image(std::move(img))
    {
    }

    ~IconEngine() = default;

    QList<QSize> availableSizes(QIcon::Mode mode, QIcon::State state) const override
    {
        Q_UNUSED(mode);
        Q_UNUSED(state);
        return { m_image.size() / m_image.devicePixelRatio() };
    }

    QIconEngine* clone() const override
    {
        auto engine = new IconEngine;
        engine->m_image = m_image;
        return engine;
    }

    void paint(QPainter *painter, const QRect &rect, QIcon::Mode mode, QIcon::State state) override
    {
        Q_UNUSED(mode);
        Q_UNUSED(state);
        painter->drawImage(rect, m_image);
    }

private:
    explicit IconEngine() = default;
    QImage m_image;
};

static bool operator<(const IconData &lhs, const IconData &rhs)
{
    if (lhs.name == rhs.name) {
        if (lhs.color.rgb() == rhs.color.rgb()) {
            return lhs.size.width() < rhs.size.width();
        }
        return lhs.color.rgb() < rhs.color.rgb();
    }
    return lhs.name < rhs.name;
}

static bool operator==(const IconData &lhs, const IconData &rhs)
{
    return lhs.name == rhs.name && lhs.color == rhs.color && lhs.size == rhs.size;
}

QIcon IconLoader::loadIcon(const IconData &iconData) const
{
    // check our cache
    auto it = std::lower_bound(m_cache.begin(), m_cache.end(), iconData, [](const auto &lhs, const auto &rhs) { return lhs.data < rhs; });
    if (it != m_cache.end() && (*it).data == iconData) {
        return (*it).icon;
    }

    // check if it's one of our bundled assets
    const QString path = QLatin1String(":/org.kde.kosmindoormap/assets/icons/") + iconData.name + QLatin1String(".svg");
    QFile f(path);
    if (f.open(QFile::ReadOnly)) {
        CacheEntry entry;
        entry.data = iconData;
        entry.icon = loadSvgAsset(&f, iconData);
        it = m_cache.insert(it, std::move(entry));
        return (*it).icon;
    }

    // TODO file system URLs

    // XDG icons
    const auto icon = QIcon::fromTheme(iconData.name);
    if (icon.isNull()) {
        qWarning() << "Failed to find icon:" << iconData.name;
    }
    return icon;
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
    return QIcon(new IconEngine(std::move(img)));
}
