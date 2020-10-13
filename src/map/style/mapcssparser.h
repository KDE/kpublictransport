/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KOSMINDOORMAP_MAPCSSPARSER_H
#define KOSMINDOORMAP_MAPCSSPARSER_H

#include "kosmindoormap_export.h"

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
class KOSMINDOORMAP_EXPORT MapCSSParser
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
