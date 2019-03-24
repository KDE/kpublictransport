/*
    Copyright (C) 2019 Volker Krause <vkrause@kde.org>

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

#ifndef KPUBLICTRANSPORT_HAFASPARSER_H
#define KPUBLICTRANSPORT_HAFASPARSER_H

#include "kpublictransport_export.h"

#include <KPublicTransport/Line>
#include <KPublicTransport/Reply>

#include <QString>

#include <unordered_map>

namespace KPublicTransport {

/** Common base for the various Hafas response parsers.
 *  @internal only exported for unit tests
 */
class KPUBLICTRANSPORT_EXPORT HafasParser
{
public:
    void setLocationIdentifierType(const QString &idType);

    Reply::Error error() const;
    QString errorMessage() const;

protected:
    HafasParser(const std::unordered_map<int, Line::Mode> &modeMap);
    ~HafasParser();

    void clearErrorState();
    Line::Mode parseLineMode(const QString &modeId) const;
    Line::Mode parseLineMode(const QStringRef &modeId) const;
    Line::Mode parseLineMode(int modeId) const;

protected:
    QString m_locationIdentifierType;
    mutable QString m_errorMsg;
    mutable Reply::Error m_error = Reply::NoError;

private:
    Q_DISABLE_COPY(HafasParser)
    const std::unordered_map<int, Line::Mode> &m_lineModeMap;
};

}

#endif // KPUBLICTRANSPORT_HAFASPARSER_H
