/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include <KOSMIndoorMap/HitDetector>
#include <KOSMIndoorMap/MapCSSParser>
#include <KOSMIndoorMap/MapCSSStyle>
#include <KOSMIndoorMap/MapData>
#include <KOSMIndoorMap/MapLoader>
#include <KOSMIndoorMap/PainterRenderer>
#include <KOSMIndoorMap/SceneController>
#include <KOSMIndoorMap/SceneGraph>
#include <KOSMIndoorMap/View>

#include <QApplication>
#include <QCommandLineParser>
#include <QMouseEvent>
#include <QComboBox>
#include <QHBoxLayout>
#include <QPainter>
#include <QRegularExpression>

using namespace KOSMIndoorMap;

static QString cssPath(const QString &styleName)
{
    return QLatin1String(SOURCE_DIR "/../src/map/assets/css/") + styleName + QLatin1String(".mapcss");
//     return QLatin1String(":/org.kde.kosmindoormap/assets/css/") + styleName + QLatin1String(".mapcss");
}

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
    void setMapData(MapData &&data);
    void setStyleSheet(const QString &styleName);

    MapData m_data;
    SceneGraph m_sg;
    MapCSSStyle m_style;
    SceneController m_controller;
    PainterRenderer m_renderer;
    View m_view;
    QPoint m_lastPanPoint;
};

MapWidget::MapWidget(QWidget* parent)
    : QWidget(parent)
{
    m_view.setScreenSize(size());
    m_controller.setView(&m_view);
}

void MapWidget::paintEvent(QPaintEvent *event)
{
    m_controller.updateScene(m_sg);
    QPainter p(this);
    m_renderer.setPainter(&p);
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
        HitDetector detector;
        const auto items = detector.itemsAt(event->pos(), m_sg, &m_view);
        for (const auto item : items) {
            qDebug() << item->element.url();
            for (auto it = item->element.tagsBegin(); it != item->element.tagsEnd(); ++it) {
                qDebug() << "    " << (*it).key.name() << (*it).value;
            }
            switch (item->element.type()) {
                case OSM::Type::Null:
                case OSM::Type::Node:
                    break;
                case OSM::Type::Way:
                    for (const auto &node : item->element.way()->nodes) {
                        qDebug() << "      " << node;
                    }
                    break;
                case OSM::Type::Relation:
                    for (const auto &mem : item->element.relation()->members) {
                        qDebug() << "      " << mem.role().name() << (int)mem.type() << mem.id;
                    }
                    break;
            }
        }
    }
}

void MapWidget::wheelEvent(QWheelEvent *event)
{
    if (event->angleDelta().y() > 0) {
#if QT_VERSION <= QT_VERSION_CHECK(5, 14, 0)
        m_view.zoomIn(event->pos());
#else
        m_view.zoomIn(event->position());
#endif
    } else {
#if QT_VERSION <= QT_VERSION_CHECK(5, 14, 0)
        m_view.zoomOut(event->pos());
#else
        m_view.zoomOut(event->position());
#endif
    }
    QWidget::wheelEvent(event);
    update();
}

void MapWidget::setMapData(MapData &&data)
{
    m_data = std::move(data);
    m_controller.setDataSet(&m_data);
    m_view.setSceneBoundingBox(m_data.boundingBox());
    m_style.compile(m_data.dataSet());
    m_controller.setStyleSheet(&m_style);
    update();
}

void MapWidget::setStyleSheet(const QString &styleName)
{
    MapCSSParser cssParser;
    m_style = cssParser.parse(cssPath(styleName));
    m_style.compile(m_data.dataSet());
    m_controller.setStyleSheet(&m_style);
}


int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    QCommandLineParser parser;
    QCommandLineOption coordOpt({QStringLiteral("coordinate"), QStringLiteral("c")}, QStringLiteral("coordinate of the location to load"), QStringLiteral("lat,lon"));
    parser.addOption(coordOpt);
    QCommandLineOption fileOpt({QStringLiteral("file"), QStringLiteral("f")}, QStringLiteral("O5M or OSM PBF file to load"), QStringLiteral("file"));
    parser.addOption(fileOpt);
    parser.addHelpOption();
    parser.addVersionOption();
    parser.process(app);

    MapWidget widget;
    widget.resize(480, 720);
    widget.setStyleSheet(QStringLiteral("breeze-light"));

    auto layout = new QHBoxLayout(&widget);
    layout->setAlignment(Qt::AlignTop);

    auto levelBox = new QComboBox;
    layout->addWidget(levelBox);
    QObject::connect(levelBox, &QComboBox::currentTextChanged, &app, [&]() {
        widget.m_view.setLevel(levelBox->currentData().toInt());
        widget.update();
    });

    auto styleBox = new QComboBox;
    layout->addWidget(styleBox);
    styleBox->addItems({QStringLiteral("breeze-light"), QStringLiteral("breeze-dark"), QStringLiteral("diagnostic")});
    QObject::connect(styleBox, &QComboBox::currentTextChanged, &app, [&](const QString &styleName) {
        widget.setStyleSheet(styleName);
        widget.update();
    });

    widget.show();

    MapLoader loader;
    QObject::connect(&loader, &MapLoader::done, &app, [&]() {
        widget.setMapData(loader.takeData());
        levelBox->clear();
        for (const auto &l : widget.m_data.m_levelMap) {
            if (l.first.isFullLevel()) {
                levelBox->addItem(l.first.name(), l.first.numericLevel());
            }
        }
        levelBox->setCurrentText(QLatin1String("0"));
    });

    if (parser.isSet(fileOpt)) {
        loader.loadFromFile(parser.value(fileOpt));
    } else if (parser.isSet(coordOpt)) {
        const auto s = parser.value(coordOpt).split(QRegularExpression(QStringLiteral("[,/;]")));
        loader.loadForCoordinate(s.at(0).toDouble(), s.at(1).toDouble());
    }

    return app.exec();
}
