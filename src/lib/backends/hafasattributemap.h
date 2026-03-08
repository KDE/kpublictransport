/*
    SPDX-FileCopyrightText: 2019-2026 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_HAFASATTRIBUTEMAP_H
#define KPUBLICTRANSPORT_HAFASATTRIBUTEMAP_H

#include <kpublictransport_export.h>

#include <QAnyStringView>
#include <QExplicitlySharedDataPointer>
#include <qobjectdefs.h>

namespace KPublicTransport {

class Feature;
class HafasAttributeData;
class HafasAttributeMap;
class HafasAttributeMapData;

/** A single Hafas attribute description.
 *
 *  @internal only exported for (indirect) use in unit tests.
 */
class KPUBLICTRANSPORT_EXPORT HafasAttribute {
    Q_GADGET
public:
    enum Type {
        Undefined,
        Ignore, ///< drop entirely
        Note, ///< just pass through the text (for overrides)
        Feature,
        Operator, ///< operator name
        TrainFormation,
        PlatformSectors,
    };
    Q_ENUM(Type)

    [[nodiscard]] Type type() const;
    [[nodiscard]] class Feature feature() const;
private:
    friend class HafasAttributeMap;
    friend class HafasAttributeMapData;
    explicit HafasAttribute(const HafasAttributeData *dd);
    const HafasAttributeData *d = nullptr;
};

/** Lookup of Hafas attribute codes.
 *
 *  While mainly used in the various flavours of Hafas backends,
 *  those codes also appear in NeTEx data and thus potentially also
 *  in backends consuming such data.
 *
 *  @internal only exported for (indirect) use in unit tests.
 */
class KPUBLICTRANSPORT_EXPORT HafasAttributeMap {
public:
    explicit HafasAttributeMap();
    explicit HafasAttributeMap(QStringView name);
    HafasAttributeMap(HafasAttributeMap &&) noexcept;
    ~HafasAttributeMap();
    HafasAttributeMap& operator=(HafasAttributeMap &&) noexcept;

    /** Lifetime is limited by the lifetime of HafasAttributeMap. */
    [[nodiscard]] HafasAttribute lookup(QAnyStringView category, QAnyStringView code) const;

    /** Force reloading of attribute mapps as result of an online update. */
    static void reload();

private:
    QExplicitlySharedDataPointer<HafasAttributeMapData> d;
};

}

#endif
