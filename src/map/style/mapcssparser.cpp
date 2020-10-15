/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "mapcssparser.h"
#include "logging.h"

#include "mapcssparser_p.h"
#include "mapcssrule_p.h"
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

QString MapCSSParser::errorMessage() const
{
    if (!m_error) {
        return {};
    }

    return m_errorMsg + QLatin1String(": ") + fileName() + QLatin1Char(':') + QString::number(m_line) + QLatin1Char(':') + QString::number(m_column);
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
        qCWarning(Log) << f.fileName() << f.errorString();
        m_error = true;
        m_errorMsg = f.errorString();
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
        m_error = true;
        return;
    }

    yy_delete_buffer(state, scanner);

    m_error = false;
    m_currentStyle = nullptr;
}

bool MapCSSParser::addImport(char* fileName)
{
    auto cssFile = QString::fromUtf8(fileName);
    free(fileName);

    if (QFileInfo(cssFile).isRelative()) {
        cssFile = QFileInfo(m_currentFileName).absolutePath() + QLatin1Char('/') + cssFile;
    }

    MapCSSParser p;
    p.parse(m_currentStyle, cssFile);
    if (p.hasError()) {
        m_error = p.m_error;
        m_errorMsg = p.errorMessage();
    }
    return !p.hasError();
}

void MapCSSParser::addRule(MapCSSRule *rule)
{
    m_currentStyle->m_rules.push_back(std::unique_ptr<MapCSSRule>(rule));
}

void MapCSSParser::setError(const QString &msg, int line, int column)
{
    m_error = true;
    m_errorMsg = msg;
    m_line = line;
    m_column = column;
}
