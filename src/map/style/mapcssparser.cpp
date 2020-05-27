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

#include "mapcssparser.h"

#include "mapcssparser_p.h"
#include "mapcssscanner.h"
#include "mapcssstyle.h"

#include <QDebug>
#include <QFile>
#include <QFileInfo>
#include <QScopeGuard>

#include <cstring>

char* unquoteString(const char *str)
{
    const auto size = strlen(str) - 2;
    if (size <= 0)
        return nullptr;
    auto out = (char*)malloc(size + 1);
    memset(out, 0, size + 1);
    auto outIt = out;
    for (auto it = str + 1; it < str + size + 1; ++it, ++outIt) {
        if (*it == '\\') {
            ++it;
            switch (*it) {
                case '\\':
                case '"':
                    *outIt = *it; break;
                case 'n':
                    *outIt = '\n'; break;
                case 't':
                    *outIt = '\t'; break;
                default:
                    *outIt++ = '\\';
                    *outIt = *it;
            }
        } else {
            *outIt = *it;
        }
    }
    return out;
}

using namespace KOSMIndoorMap;

bool MapCSSParser::hasError() const
{
    return m_error;
}

QString MapCSSParser::fileName() const
{
    return m_currentFileName;
}

MapCSSStyle MapCSSParser::parse(const QString &fileName)
{
    m_error = true;

    MapCSSStyle style;
    parse(&style, fileName);
    if (m_error) {
        return MapCSSStyle();
    }

    return style;
}

void MapCSSParser::parse(MapCSSStyle *style, const QString &fileName)
{
    QFile f(fileName);
    if (!f.open(QFile::ReadOnly)) {
        qWarning() << f.fileName() << f.errorString();
        return;
    }
    m_currentFileName = fileName;
    m_currentStyle = style;

    yyscan_t scanner;
    if (yylex_init(&scanner)) {
        return;
    }
    const auto lexerCleanup = qScopeGuard([&scanner]{ yylex_destroy(scanner); });

    const auto b = f.readAll();
    YY_BUFFER_STATE state;
    state = yy_scan_string(b.constData(), scanner);
    if (yyparse(this, scanner)) {
        return;
    }

    yy_delete_buffer(state, scanner);

    m_error = false;
    m_currentStyle = nullptr;
}

void MapCSSParser::addImport(char* fileName)
{
    auto cssFile = QString::fromUtf8(fileName);
    free(fileName);

    if (QFileInfo(cssFile).isRelative()) {
        cssFile = QFileInfo(m_currentFileName).absolutePath() + QLatin1Char('/') + cssFile;
    }

    MapCSSParser p;
    p.parse(m_currentStyle, cssFile);
}

void MapCSSParser::addRule(MapCSSRule *rule)
{
    m_currentStyle->m_rules.push_back(std::unique_ptr<MapCSSRule>(rule));
}
