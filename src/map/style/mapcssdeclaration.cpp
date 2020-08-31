/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "mapcssdeclaration.h"
#include "logging.h"

#include <QDebug>
#include <QIODevice>

#include <cstring>

using namespace KOSMIndoorMap;

// keep this sorted by property name!
struct {
    const char* name;
    MapCSSDeclaration::Property property;
    int flags;
} static constexpr const property_types[] = {
    // only those properties have their corresonding flag set that actually trigger emission of a scene graph item
    // e.g. for a label we either need a text or an icon, the visual properties for those on their own would be a no-op
    { "casing-color", MapCSSDeclaration::CasingColor, MapCSSDeclaration::LabelProperty },
    { "casing-dashes", MapCSSDeclaration::CasingDashes, MapCSSDeclaration::NoFlag },
    { "casing-linecap", MapCSSDeclaration::CasingLineCap, MapCSSDeclaration::NoFlag },
    { "casing-linejoin", MapCSSDeclaration::CasingLineJoin, MapCSSDeclaration::NoFlag },
    { "casing-opacity", MapCSSDeclaration::CasingOpacity, MapCSSDeclaration::NoFlag },
    { "casing-width", MapCSSDeclaration::CasingWidth, MapCSSDeclaration::LineProperty },
    { "color", MapCSSDeclaration::Color, MapCSSDeclaration::LineProperty },
    { "dashes", MapCSSDeclaration::Dashes, MapCSSDeclaration::NoFlag },
    { "fill-color", MapCSSDeclaration::FillColor, MapCSSDeclaration::AreaProperty | MapCSSDeclaration::CanvasProperty }, // TODO this also applies to lines
    { "fill-image", MapCSSDeclaration::FillImage, MapCSSDeclaration::AreaProperty | MapCSSDeclaration::CanvasProperty },
    { "fill-opacity", MapCSSDeclaration::FillOpacity, MapCSSDeclaration::AreaProperty },
    { "font-family", MapCSSDeclaration::FontFamily, MapCSSDeclaration::NoFlag },
    { "font-size", MapCSSDeclaration::FontSize, MapCSSDeclaration::NoFlag },
    { "font-style", MapCSSDeclaration::FontStyle, MapCSSDeclaration::NoFlag },
    { "font-variant", MapCSSDeclaration::FontVariant, MapCSSDeclaration::NoFlag },
    { "font-weight", MapCSSDeclaration::FontWeight, MapCSSDeclaration::NoFlag },
    { "icon-color", MapCSSDeclaration::IconColor, MapCSSDeclaration::NoFlag },
    { "icon-height", MapCSSDeclaration::IconWidth, MapCSSDeclaration::NoFlag },
    { "icon-image", MapCSSDeclaration::IconImage, MapCSSDeclaration::LabelProperty },
    { "icon-opacity", MapCSSDeclaration::IconOpacity, MapCSSDeclaration::NoFlag },
    { "icon-width", MapCSSDeclaration::IconWidth, MapCSSDeclaration::NoFlag },
    { "image", MapCSSDeclaration::Image, MapCSSDeclaration::LineProperty },
    { "linecap", MapCSSDeclaration::LineCap, MapCSSDeclaration::NoFlag },
    { "linejoin", MapCSSDeclaration::LineJoin, MapCSSDeclaration::NoFlag },
    { "max-width", MapCSSDeclaration::MaxWidth, MapCSSDeclaration::NoFlag },
    { "opacity", MapCSSDeclaration::Opacity, MapCSSDeclaration::NoFlag },
    { "shield-casing-color", MapCSSDeclaration::ShieldCasingColor, MapCSSDeclaration::LabelProperty },
    { "shield-casing-width", MapCSSDeclaration::ShieldCasingWidth, MapCSSDeclaration::NoFlag },
    { "shield-color", MapCSSDeclaration::ShieldColor, MapCSSDeclaration::LabelProperty },
    { "shield-frame-color", MapCSSDeclaration::ShieldFrameColor, MapCSSDeclaration::LabelProperty },
    { "shield-frame-width", MapCSSDeclaration::ShieldFrameWidth, MapCSSDeclaration::NoFlag },
    { "shield-image", MapCSSDeclaration::ShieldImage, MapCSSDeclaration::LabelProperty },
    { "shield-opacity", MapCSSDeclaration::ShieldOpacity, MapCSSDeclaration::NoFlag },
    { "shield-shape", MapCSSDeclaration::ShieldShape, MapCSSDeclaration::NoFlag },
    { "shield-text", MapCSSDeclaration::ShieldText, MapCSSDeclaration::LabelProperty },
    { "text", MapCSSDeclaration::Text, MapCSSDeclaration::LabelProperty },
    { "text-color", MapCSSDeclaration::TextColor, MapCSSDeclaration::CanvasProperty },
    { "text-decoration", MapCSSDeclaration::TextDecoration, MapCSSDeclaration::NoFlag },
    { "text-halo-color", MapCSSDeclaration::TextHaloColor, MapCSSDeclaration::NoFlag },
    { "text-halo-radius", MapCSSDeclaration::TextHaloRadius, MapCSSDeclaration::NoFlag },
    { "text-offset", MapCSSDeclaration::TextOffset, MapCSSDeclaration::NoFlag },
    { "text-opacity", MapCSSDeclaration::TextOpacity, MapCSSDeclaration::NoFlag },
    { "text-position", MapCSSDeclaration::TextPosition, MapCSSDeclaration::NoFlag },
    { "text-transform", MapCSSDeclaration::TextTransform, MapCSSDeclaration::NoFlag },
    { "width", MapCSSDeclaration::Width, MapCSSDeclaration::LineProperty },
    { "z-index", MapCSSDeclaration::ZIndex, MapCSSDeclaration::NoFlag },
};

struct {
    const char *name;
    Qt::PenCapStyle capStyle;
} static constexpr const capstyle_map[] = {
    { "none", Qt::FlatCap },
    { "round", Qt::RoundCap },
    { "square", Qt::SquareCap },
};

struct {
    const char *name;
    Qt::PenJoinStyle joinStyle;
} static constexpr const joinstyle_map[] = {
    { "bevel", Qt::BevelJoin },
    { "miter", Qt::MiterJoin },
    { "round", Qt::RoundJoin },
};

struct {
    const char *name;
    QFont::Capitalization capitalizationStyle;
} static constexpr const capitalizationstyle_map[] = {
    { "capitalize", QFont::Capitalize },
    { "lowercase", QFont::AllLowercase },
    { "none", QFont::MixedCase },
    { "normal", QFont::MixedCase },
    { "small-caps", QFont::SmallCaps },
    { "uppercase", QFont::AllUppercase },
};

struct {
    const char *name;
    MapCSSDeclaration::Unit unit;
} static constexpr const unit_map[] = {
    { "m", MapCSSDeclaration::Meters },
    { "pt", MapCSSDeclaration::Point },
    { "px", MapCSSDeclaration::Pixels },
};

MapCSSDeclaration::MapCSSDeclaration() = default;
MapCSSDeclaration::~MapCSSDeclaration() = default;

MapCSSDeclaration::Property MapCSSDeclaration::property() const
{
    return m_property;
}

int MapCSSDeclaration::propertyFlags() const
{
    return m_flags;
}

int MapCSSDeclaration::intValue() const
{
    return m_doubleValue;
}

double MapCSSDeclaration::doubleValue() const
{
    return m_doubleValue;
}

QString MapCSSDeclaration::stringValue() const
{
    return m_stringValue;
}

QColor MapCSSDeclaration::colorValue() const
{
    if (!m_colorValue.isValid() && !m_stringValue.isEmpty()) {
        return QColor(m_stringValue);
    }
    return m_colorValue;
}

QByteArray MapCSSDeclaration::keyValue() const
{
    return m_identValue;
}

QVector<double> MapCSSDeclaration::dashesValue() const
{
    return m_dashValue;
}

void MapCSSDeclaration::setDoubleValue(double val)
{
    m_doubleValue = val;
}

void MapCSSDeclaration::setPropertyName(const char *name, std::size_t len)
{
    const auto it = std::lower_bound(std::begin(property_types), std::end(property_types), name, [len](const auto &lhs, const char *rhs) {
        const auto lhsLen = std::strlen(lhs.name);
        const auto cmp = std::strncmp(lhs.name, rhs, std::min(lhsLen, len));
        return cmp < 0 || (cmp == 0 && lhsLen < len);
    });
    if (it == std::end(property_types) || std::strncmp((*it).name, name, std::max(len, std::strlen((*it).name))) != 0) {
        qCWarning(Log) << "Unknown property declaration:" << QByteArray::fromRawData(name, len);
        m_property = Unknown;
        return;
    }
    m_property = (*it).property;
    m_flags = (*it).flags;
}

void MapCSSDeclaration::setIdentifierValue(const char *val, int len)
{
    m_identValue = QByteArray(val, len);
}

void MapCSSDeclaration::setStringValue(char *str)
{
    m_stringValue = QString::fromUtf8(str);
    free(str);
}

void MapCSSDeclaration::setColorRgba(uint32_t argb)
{
    m_colorValue = QColor::fromRgba(argb);
    //qDebug() << m_colorValue << argb;
}

void MapCSSDeclaration::setDashesValue(const QVector<double> &dashes)
{
    m_dashValue = dashes;
}

Qt::PenCapStyle MapCSSDeclaration::capStyle() const
{
    for (const auto &c : capstyle_map) {
        if (std::strcmp(c.name, m_identValue.constData()) == 0) {
            return c.capStyle;
        }
    }
    qDebug() << "unknown line cap style:" << m_identValue;
    return Qt::FlatCap;
}

Qt::PenJoinStyle MapCSSDeclaration::joinStyle() const
{
    for (const auto &j : joinstyle_map) {
        if (std::strcmp(j.name, m_identValue.constData()) == 0) {
            return j.joinStyle;
        }
    }
    return Qt::RoundJoin;
}

QFont::Capitalization MapCSSDeclaration::capitalizationStyle() const
{
    for (const auto &c : capitalizationstyle_map) {
        if (std::strcmp(c.name, m_identValue.constData()) == 0) {
            return c.capitalizationStyle;
        }
    }
    return QFont::MixedCase;
}

bool MapCSSDeclaration::isBoldStyle() const
{
    return m_identValue == "bold";
}

bool MapCSSDeclaration::isItalicStyle() const
{
    return m_identValue == "italic";
}

bool MapCSSDeclaration::isUnderlineStyle() const
{
    return m_identValue == "underline";
}

bool MapCSSDeclaration::textFollowsLine() const
{
    return m_identValue == "line";
}

MapCSSDeclaration::Unit MapCSSDeclaration::unit() const
{
    return m_unit;
}

void MapCSSDeclaration::setUnit(const char *val, int len)
{
    for (const auto &u : unit_map) {
        if (std::strncmp(u.name, val, std::max<std::size_t>(std::strlen(u.name), len)) == 0) {
            m_unit = u.unit;
            return;
        }
    }
    qCWarning(Log) << "unknown unit:" << QByteArray(val, len);
    m_unit = NoUnit;
}

void MapCSSDeclaration::compile(const OSM::DataSet &dataSet)
{
    Q_UNUSED(dataSet);
    // TODO resolve tag key if m_identValue is one
}

void MapCSSDeclaration::write(QIODevice *out) const
{
    out->write("    ");

    for (const auto &p : property_types) {
        if (p.property == m_property) {
            out->write(p.name);
            break;
        }
    }

    out->write(": ");
    if (!std::isnan(m_doubleValue)) {
        out->write(QByteArray::number(m_doubleValue));
    } else if (m_colorValue.isValid()) {
        out->write(m_colorValue.name(QColor::HexArgb).toUtf8());
    } else if (!m_dashValue.isEmpty()) {
        for (const auto &d : m_dashValue) {
            out->write(QByteArray::number(d));
            out->write(", ");
        }
    } else if (!m_stringValue.isEmpty()) {
        out->write("\"");
        out->write(m_stringValue.toUtf8()); // this would need to be quoted...
        out->write("\"");
    } else {
        out->write(m_identValue);
    }

    for (const auto &u : unit_map) {
        if (u.unit == m_unit) {
            out->write(u.name);
            break;
        }
    }

    out->write(";\n");
}
