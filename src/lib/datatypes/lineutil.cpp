/*
    SPDX-FileCopyrightText: 2018 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "lineutil_p.h"
#include "linecompare_p.h"

#include <knowledgedb/linemetadata.h>

#include <KPublicTransport/Location>

#include <QColor>
#include <QDebug>
#include <QString>
#include <QUrl>

using namespace KPublicTransport;

bool LineUtil::isSameLineNameStrict(const QString &lhs, const QString &rhs)
{
    return Internal::isSameLineName(lhs, rhs, Internal::StrictCompare);
}

bool LineUtil::isSameLineNameFuzzy(const QString &lhs, const QString &rhs)
{
    return Internal::isSameLineName(lhs, rhs, Internal::FuzzyCompare);
}

bool LineUtil::isHighlyIdentifyingName(QStringView s)
{
    return s.size() >= 2
        && std::any_of(s.begin(), s.end(), [](QChar c) { return c.isDigit(); })
        && std::any_of(s.begin(), s.end(), [](QChar c) { return c.isLetter(); });
}

bool LineUtil::isCompatibleMode(Line::Mode lhs, Line::Mode rhs)
{
    if (lhs == rhs || lhs == Line::Unknown || rhs == Line::Unknown) {
        return true;
    }

    if (lhs == Line::Train) {
        return rhs == Line::LocalTrain || rhs == Line::LongDistanceTrain || rhs == Line::RapidTransit;
    }
    if (rhs == Line::Train) {
        return lhs == Line::LocalTrain || lhs == Line::LongDistanceTrain || lhs == Line::RapidTransit;
    }

    return false;
}

bool LineUtil::isCompatibleBaseMode(Line::Mode lhs, Line::Mode rhs)
{
    if ((lhs == Line::RapidTransit || lhs == Line::Metro || lhs == Line::Tramway)
     && (rhs == Line::RapidTransit || rhs == Line::Metro || rhs == Line::Tramway)) {
        return true;
    }

    return isCompatibleMode(lhs, rhs);
}
