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

#ifndef KOSMINDOORMAP_MAPCSSDECLARATION_H
#define KOSMINDOORMAP_MAPCSSDECLARATION_H

#include <QByteArray>
#include <QColor>
#include <QFont>
#include <QPen>

#include <cmath>

namespace OSM {
class DataSet;
}

class QIODevice;

namespace KOSMIndoorMap { class MapCSSParser; }
int yyparse(KOSMIndoorMap::MapCSSParser*, void*);

namespace KOSMIndoorMap {

/** Property/value declaration of a MapCSS rule.
 *  @see https://wiki.openstreetmap.org/wiki/MapCSS/0.2#Vocabulary
 */
class MapCSSDeclaration
{
public:
    explicit MapCSSDeclaration();
    ~MapCSSDeclaration();

    /** The property set by this declaration. */
    enum Property {
        Unknown,

        // general properites
        ZIndex, /// z-order

        // line properties
        Width, /// line width
        Color, /// line color
        Opacity, /// line opacity
        Dashes, /// line dash pattern
        Image, /// fill image for the line
        LineCap, /// line end cap style: none (default), round, square
        LineJoin, /// line join style: round (default), miter, bevel

        // line casing properties
        CasingWidth, /// line casing width
        CasingColor, /// line casing color
        CasingOpacity, /// line casing opacity
        CasingDashes, /// line casing dash pattern
        CasingLineCap, /// line casing end cap
        CasingLineJoin, /// line casing join style

        // missing here: extrude properites

        // polygon (and canvas) properties
        FillColor, /// area fill color
        FillOpacity, /// area fill opacity
        FillImage, /// image to fill the area with

        // icon properties
        IconImage, /// URL to the icon image
        IconWidth, /// icon width
        IconHeight, /// icon height
        IconOpacity, /// icon opacity

        // label properties
        FontFamily, /// font name
        FontSize, /// font size
        FontWeight, /// font weight: bold or normal (default)
        FontStyle, /// italic or normal (default)
        FontVariant, /// small-caps or normal (default)
        TextDecoration, /// none (default) or underline
        TextTransform, /// none (default), uppercase, lowercase or capitalize
        TextColor, /// text color used for the label
        TextOpacity, /// text opacity
        TextPosition, /// @p line or @p center
        TextOffset, /// vertical offset from the center of the way or point
        MaxWidth, /// maximum width before wrapping
        Text, /// label content
        TextHaloColor, /// text halo color
        TextHaloRadius, /// text halo radius

        // shield properites (casing > frame > shield > text)
        ShieldColor, /// shield color
        ShieldOpacity, /// shield opacity
        ShieldFrameColor, /// shield frame color
        ShieldFrameWidth, /// shield frame width (0 to disable)
        ShieldCasingColor, /// schield casing color
        ShieldCasingWidth, /// shield  casing width
        ShieldText, /// text to render on the shield
        ShieldImage, /// background image of the shield
        ShieldShape, /// @p rounded or @p rectangular
    };

    Property property() const;

    /** The type of property. Helps to determine which kind of geometry we need to emit for a rule. */
    enum PropertyFlag {
        NoFlag = 0,
        AreaProperty = 1,
        LineProperty = 2,
        LabelProperty = 4,
        CanvasProperty = 8,
    };
    int propertyFlags() const;

    /** Numeric value for this property. */
    int intValue() const;
    double doubleValue() const;
    /** Quoted string value. */
    QString stringValue() const;
    /** Color value for this property. */
    QColor colorValue() const;
    /** Tag key name value. */
    QByteArray keyValue() const;
    /** Line dashes. */
    QVector<double> dashesValue() const;

    Qt::PenCapStyle capStyle() const;
    Qt::PenJoinStyle joinStyle() const;
    QFont::Capitalization capitalizationStyle() const;
    bool isBoldStyle() const;
    bool isItalicStyle() const;
    bool isUnderlineStyle() const;
    bool textFollowsLine() const;

    void compile(const OSM::DataSet &dataSet);
    void write(QIODevice *out) const;

private:
    friend int ::yyparse(KOSMIndoorMap::MapCSSParser*, void*);

    /** @internal, for use by the parser. */
    void setPropertyName(const char *name, std::size_t len);
    void setIdentifierValue(const char *val, int len);
    void setDoubleValue(double val);
    void setStringValue(char *str);
    void setColorRgba(uint32_t argb);
    void setDashesValue(const QVector<double> &dashes);

    Property m_property = Unknown;
    int m_flags = NoFlag;
    // ### merge all of this into a QVariant?
    QByteArray m_identValue;
    QColor m_colorValue;
    double m_doubleValue = NAN;
    QVector<double> m_dashValue;
    QString m_stringValue;
};

}

#endif // KOSMINDOORMAP_MAPCSSDECLARATION_H
