/*
    SPDX-FileCopyrightText: 2018 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "lineutil_p.h"
#include "linecompare_p.h"
#include "assetrepository_p.h"

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
