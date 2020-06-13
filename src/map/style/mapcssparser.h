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

#ifndef KOSMINDOORMAP_MAPCSSPARSER_H
#define KOSMINDOORMAP_MAPCSSPARSER_H

#include <QString>

namespace KOSMIndoorMap { class MapCSSParser; }
int yyparse(KOSMIndoorMap::MapCSSParser*, void*);
struct YYLTYPE;
typedef void* yyscan_t;
void yyerror(YYLTYPE*, KOSMIndoorMap::MapCSSParser*, yyscan_t, char const*);

namespace KOSMIndoorMap {

class MapCSSStyle;
class MapCSSRule;

/** MapCSS parser. */
class MapCSSParser
{
public:
    MapCSSStyle parse(const QString &fileName);

    bool hasError() const;
    QString fileName() const;
    QString errorMessage() const;

private:
    friend int ::yyparse(KOSMIndoorMap::MapCSSParser*, void*);
    friend void ::yyerror(YYLTYPE*, KOSMIndoorMap::MapCSSParser*, yyscan_t, char const*);

    void parse(MapCSSStyle *style, const QString &fileName);

    /** @internal for use by the generated parser only. */
    bool addImport(char *fileName);
    void addRule(MapCSSRule *rule);
    void setError(const QString &msg, int line, int column);

    MapCSSStyle *m_currentStyle = nullptr;
    QString m_currentFileName;
    bool m_error = false;
    QString m_errorMsg;
    int m_line = 0;
    int m_column = 0;
};

}

#endif // KOSMINDOORMAP_MAPCSSPARSER_H
