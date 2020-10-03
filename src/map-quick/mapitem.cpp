/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "mapitem.h"

#include <KOSMIndoorMap/HitDetector>
#include <KOSMIndoorMap/MapCSSParser>
#include <KOSMIndoorMap/OverlaySource>

#include <QDebug>
#include <QGuiApplication>
#include <QPainter>
#include <QPalette>
#include <QQuickWindow>
#include <QStandardPaths>

using namespace KOSMIndoorMap;

MapItem::MapItem(QQuickItem *parent)
    : QQuickPaintedItem(parent)
    , m_loader(new MapLoader(this))
    , m_view(new View(this))
    , m_floorLevelModel(new FloorLevelModel(this))
{
    connect(m_loader, &MapLoader::isLoadingChanged, this, &MapItem::clear);
    connect(m_loader, &MapLoader::done, this, &MapItem::loaderDone);

    m_view->setScreenSize({100, 100}); // FIXME this breaks view when done too late!
    m_controller.setView(m_view);
    connect(m_view, &View::floorLevelChanged, this, [this]() { update(); });
    connect(m_view, &View::transformationChanged, this, [this]() { update(); });

    setStylesheetName({}); // set default stylesheet
}

MapItem::~MapItem() = default;

void MapItem::paint(QPainter *painter)
{
    m_controller.updateScene(m_sg);
    m_renderer.setPainter(painter);
    m_renderer.render(m_sg, m_view);
}

MapLoader* MapItem::loader() const
{
    return m_loader;
}

View* MapItem::view() const
{
    return m_view;
}

QString MapItem::styleSheetName() const
{
    return m_styleSheetName;
}

void MapItem::setStylesheetName(const QString &styleSheet)
{
    QString styleFile;

    if (styleSheet.isEmpty() || styleSheet == QLatin1String("default")) {
        if (QGuiApplication::palette().base().color().value() > 128) {
            setStylesheetName(QStringLiteral("breeze-light"));
        } else {
            setStylesheetName(QStringLiteral("breeze-dark"));
        }
        return;
    } else {
        styleFile = styleSheet.contains(QLatin1Char(':')) ? QUrl::fromUserInput(styleSheet).toLocalFile() : styleSheet;
        if (!QFile::exists(styleFile)) {
#ifndef Q_OS_ANDROID
            auto searchPaths = QStandardPaths::standardLocations(QStandardPaths::GenericDataLocation);
#else
            auto searchPaths = QStandardPaths::standardLocations(QStandardPaths::DataLocation);
#endif
            searchPaths.push_back(QStringLiteral(":"));
            for (const auto &searchPath : qAsConst(searchPaths)) {
                const QString f = searchPath + QLatin1String("/org.kde.kosmindoormap/assets/css/") + styleSheet + QLatin1String(".mapcss");
                if (QFile::exists(f)) {
                    qDebug() << "resolved stylesheet name to" << f;
                    styleFile = f;
                    break;
                }
            }
        }
    }

    if (m_styleSheetName == styleFile) {
        return;
    }
    m_styleSheetName = styleFile;
    m_style = MapCSSStyle();

    if (!m_styleSheetName.isEmpty()) {
        MapCSSParser cssParser;
        m_style = cssParser.parse(m_styleSheetName);

        if (cssParser.hasError()) {
            m_errorMessage = cssParser.errorMessage();
            emit errorChanged();
            return;
        }
    }

    m_style.compile(m_data.dataSet());
    m_controller.setStyleSheet(&m_style);

    emit styleSheetChanged();
    update();
}

FloorLevelModel* MapItem::floorLevelModel() const
{
    return m_floorLevelModel;
}

void MapItem::geometryChanged(const QRectF &newGeometry, const QRectF &oldGeometry)
{
    QQuickPaintedItem::geometryChanged(newGeometry, oldGeometry);
    m_view->setScreenSize(newGeometry.size().toSize());
    // the scale factor isn't automatically applied to the paint device, only to the input coordinates
    // so we need to handle this manually here
    m_view->setDeviceTransform(QTransform::fromScale(window()->devicePixelRatio(), window()->devicePixelRatio()));
}

void MapItem::loaderDone()
{
    m_floorLevelModel->setMapData(nullptr);
    m_sg.clear();

    if (!m_loader->hasError()) {
        m_data = m_loader->takeData();
        m_view->setSceneBoundingBox(m_data.boundingBox());
        m_controller.setDataSet(&m_data);
        m_style.compile(m_data.dataSet());
        m_controller.setStyleSheet(&m_style);
        m_view->setLevel(0);
        m_floorLevelModel->setMapData(&m_data);
        m_view->floorLevelChanged();
        emit mapDataChanged();
    }

    Q_EMIT errorChanged();
    update();
}

OSMElement MapItem::elementAt(double x, double y) const
{
    HitDetector detector;
    const auto item = detector.itemAt(QPointF(x, y), m_sg, m_view);
    if (item) {
        qDebug() << item->element.url();
        for (auto it = item->element.tagsBegin(); it != item->element.tagsEnd(); ++it) {
            qDebug() << "    " << (*it).key.name() << (*it).value;
        }
        return OSMElement(item->element);
    }
    return {};
}

void MapItem::clear()
{
    if (!m_loader->isLoading() || m_sg.items().empty()) {
        return;
    }

    m_sg.clear();
    m_controller.setDataSet(nullptr);
    m_data = MapData();
    emit mapDataChanged();
    emit errorChanged();
    update();
}

bool MapItem::hasError() const
{
    return !m_errorMessage.isEmpty() || m_loader->hasError();
}

QString MapItem::errorMessage() const
{
    return m_errorMessage.isEmpty() ? m_loader->errorMessage() : m_errorMessage;
}

MapData* MapItem::mapData()
{
    if (m_data.m_levelMap.empty()) {
        return nullptr;
    }
    return &m_data;
}

QVariant MapItem::overlaySources() const
{
    return m_overlaySources;
}

void MapItem::setOverlaySources(const QVariant &overlays)
{
    std::vector<OverlaySource> sources;
    if (overlays.canConvert<QVariantList>()) {
        const auto l = overlays.value<QVariantList>();
        for (const auto &v : l) {
            addOverlaySource(sources, v);
        }
    } else {
        addOverlaySource(sources, overlays);
    }

    m_controller.setOverlaySources(std::move(sources));
    emit overlaySourcesChanged();
    update();
}

void MapItem::addOverlaySource(std::vector<OverlaySource> &overlaySources, const QVariant &source)
{
    const auto obj = source.value<QObject*>();
    if (auto model = qobject_cast<QAbstractItemModel*>(obj)) {
        OverlaySource overlay(model);
        overlay.setUpdateCallback(this, [this]() {
            m_controller.overlaySourceUpdated();
            update();
        });
        overlay.setResetCallback(this, [this]() {
            m_style.compile(m_data.dataSet());
        });
        overlaySources.push_back(std::move(overlay));
    } else {
        qWarning() << "unsupported overlay source:" << source << obj;
    }
}
