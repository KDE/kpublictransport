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

#include <cmath>

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

        // polygon properties
        FillColor, /// area fill color
        FillOpacity, /// area fill opacity

        // label properties
        Text, /// label content
        TextColor, /// text color used for the label

        // casing properites

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
