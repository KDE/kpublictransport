/*
    Copyright (C) 2020 Volker Krause <vkrause@kde.org>

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

#include <loader/maploader.h>
#include <renderer/painterrenderer.h>
#include <renderer/view.h>
#include <scene/scenegraph.h>
#include <scene/scenecontroller.h>
#include <style/mapcssparser.h>
#include <style/mapcssstyle.h>

#include <QApplication>
#include <QMouseEvent>
#include <QComboBox>
#include <QHBoxLayout>

using namespace KOSMIndoorMap;

class MapWidget : public QWidget
{
public:
    explicit MapWidget(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;

    SceneGraph m_sg;
    SceneController m_controller;
    PainterRenderer m_renderer;
    View m_view;
    QPoint m_lastPanPoint;
};

MapWidget::MapWidget(QWidget* parent)
    : QWidget(parent)
{
    m_renderer.setPaintDevice(this);
    m_view.setScreenSize(size());
}

void MapWidget::paintEvent(QPaintEvent *event)
{
    m_renderer.render(m_sg, &m_view);
    return QWidget::paintEvent(event);
}

void MapWidget::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    m_view.setScreenSize(size());
}

void MapWidget::mousePressEvent(QMouseEvent *event)
{
    m_lastPanPoint = event->pos();
    QWidget::mousePressEvent(event);
}

void MapWidget::mouseMoveEvent(QMouseEvent *event)
{
    m_view.panScreenSpace(m_lastPanPoint - event->pos());
    m_lastPanPoint = event->pos();
    QWidget::mouseMoveEvent(event);
    update();
}

void MapWidget::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::RightButton) {
        m_sg.itemsAt(m_view.mapScreenToScene(event->pos()));
    }
}

void MapWidget::wheelEvent(QWheelEvent *event)
{
    if (event->angleDelta().y() > 0) {
        m_view.zoomIn(event->position());
    } else {
        m_view.zoomOut(event->position());
    }
    QWidget::wheelEvent(event);
    m_controller.updateScene(m_sg);
    update();
}


static QString cssPath(const QString &styleName)
{
    return QLatin1String(SOURCE_DIR "/../src/map/assets/css/") + styleName + QLatin1String(".mapcss");
//     return QLatin1String(":/org.kde.kosmindoormap/assets/css/") + styleName + QLatin1String(".mapcss");
}

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    MapLoader loader;
    loader.loadFromO5m(QStringLiteral("/k/osm/berlin_hbf.o5m"));

    MapCSSParser cssParser;
    auto style = cssParser.parse(cssPath(QStringLiteral("breeze-light")));

    MapWidget widget;
    widget.resize(480, 720);
    widget.m_view.setSceneBoundingBox(loader.m_data.boundingBox());
    widget.m_controller.setDataSet(&loader.m_data);
    widget.m_controller.setStyleSheet(&style);
    widget.m_controller.setView(&widget.m_view);

    auto layout = new QHBoxLayout(&widget);
    layout->setAlignment(Qt::AlignTop);

    auto levelBox = new QComboBox;
    layout->addWidget(levelBox);
    for (const auto &l : loader.m_data.m_levelMap) {
        if (l.first.isFullLevel()) {
            levelBox->addItem(l.first.name(), l.first.numericLevel());
        }
    }
    QObject::connect(levelBox, &QComboBox::currentTextChanged, &app, [&]() {
        widget.m_view.setLevel(levelBox->currentData().toInt());
        widget.m_controller.updateScene(widget.m_sg);
        widget.update();
    });
    levelBox->setCurrentText(QLatin1String("0"));

    auto styleBox = new QComboBox;
    layout->addWidget(styleBox);
    styleBox->addItems({QStringLiteral("breeze-light"), QStringLiteral("breeze-dark"), QStringLiteral("diagnostic")});
    QObject::connect(styleBox, &QComboBox::currentTextChanged, &app, [&](const QString &styleName) {
        MapCSSParser p;
        style = p.parse(cssPath(styleName));
        widget.m_controller.setStyleSheet(&style);
        widget.m_controller.updateScene(widget.m_sg);
        widget.update();
    });

    widget.show();
    return app.exec();
}
