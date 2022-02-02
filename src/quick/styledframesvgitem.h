/*
    SPDX-FileCopyrightText: 2020-2022 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_STYLEDFRAMESVGITEM_H
#define KPUBLICTRANSPORT_STYLEDFRAMESVGITEM_H

#include <QImage>
#include <QQuickPaintedItem>

namespace KPublicTransport {

/** Styled SVG border-image element. */
class StyledFrameSvgItem : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(double borderTop MEMBER m_borderTop NOTIFY borderTopChanged)
    Q_PROPERTY(double borderBottom MEMBER m_borderBottom NOTIFY borderBottomChanged)
    Q_PROPERTY(double borderLeft MEMBER m_borderLeft NOTIFY borderLeftChanged)
    Q_PROPERTY(double borderRight MEMBER m_borderRight NOTIFY borderRightChanged)

    Q_PROPERTY(QColor lineColor MEMBER m_lineColor NOTIFY colorChanged)
    Q_PROPERTY(QColor backgroundColor MEMBER m_fillColor NOTIFY colorChanged) // fillColor is already a property in the base class

    Q_PROPERTY(QString source MEMBER m_source NOTIFY sourceChanged)

public:
    explicit StyledFrameSvgItem(QQuickItem *parent = nullptr);
    ~StyledFrameSvgItem();

    void paint(QPainter *painter) override;

Q_SIGNALS:
    void borderTopChanged();
    void borderBottomChanged();
    void borderLeftChanged();
    void borderRightChanged();
    void colorChanged();
    void sourceChanged();

private:
    void invalidateImage();
    void loadImage();

    double m_borderTop = 0;
    double m_borderBottom = 0;
    double m_borderLeft = 0;
    double m_borderRight = 0;
    QColor m_lineColor;
    QColor m_fillColor;
    QString m_source;
    QImage m_image;
};

}

#endif // KPUBLICTRANSPORT_STYLEDFRAMESVGITEM_H
