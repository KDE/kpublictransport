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

private:
    friend int ::yyparse(KOSMIndoorMap::MapCSSParser*, void*);

    void parse(MapCSSStyle *style, const QString &fileName);

    /** @internal for use by the generated parser only. */
    void addImport(char *fileName);
    void addRule(MapCSSRule *rule);

    MapCSSStyle *m_currentStyle = nullptr;
    QString m_currentFileName;
    bool m_error = false;
    // TODO error message and location?
};

}

#endif // KOSMINDOORMAP_MAPCSSPARSER_H
