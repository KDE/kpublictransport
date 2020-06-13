%{
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

#include "mapcssparser_p.h"
#include "style/mapcssselector.h"

extern char* unquoteString(const char *str);

using namespace KOSMIndoorMap;

int yy_column = 1;
#define YY_USER_ACTION yylloc->first_line = yylloc->last_line = yylineno + 1; \
    yylloc->first_column = yy_column; \
    yylloc->last_column = yy_column + yyleng - 1; \
    yy_column += yyleng;

%}

%option warn nodefault

%option reentrant
%option noyywrap
%option nounput
%option never-interactive
%option bison-bridge
%option bison-locations
%option yylineno

INITIAL     [[:alpha:]]|"_"
SUBSEQUENT  {INITIAL}|[0-9]
IDENTIFIER  {INITIAL}{SUBSEQUENT}*

SPACE       [ \t\r]+

HEX         [a-fA-F0-9]
/* TODO: HEXCOLOR3 */
HEXCOLOR6   "#"{HEX}{6}
HEXCOLOR8   "#"{HEX}{8}

INTEGER     [0-9]+
DOUBLE      {INTEGER}|([0-9]+[.][0-9]*|[0-9]*[.][0-9]+)([eE][-+]?[0-9]+)?
STRING_ELEMENT  [^\\"]|"\\\""|"\\\\"|"\\n"|"\\t"
STRING      ["]{STRING_ELEMENT}*["]

%x comment

%%

"\n"    { yy_column = 1; }
{SPACE} {}

"[" { return T_LBRACKET; }
"]" { return T_RBRACKET; }
"{" { return T_LBRACE; }
"}" { return T_RBRACE; }
"(" { return T_LPAREN; }
")" { return T_RPAREN; }
":" { return T_COLON; }
";" { return T_SEMICOLON; }
"," { return T_COMMA; }
" " { return T_SPACE; }
"-" { return T_DASH; }
"+" { return T_PLUS; }
"|z" { return T_ZOOM; }
"*" { return T_STAR; }

"="  { yylval->binaryOp = MapCSSCondition::Equal; return T_BINARY_OP; }
"!=" { yylval->binaryOp = MapCSSCondition::NotEqual; return T_BINARY_OP; }
"<"  { yylval->binaryOp = MapCSSCondition::LessThan; return T_BINARY_OP; }
">"  { yylval->binaryOp = MapCSSCondition::GreaterThan; return T_BINARY_OP; }
"<=" { yylval->binaryOp = MapCSSCondition::LessOrEqual; return T_BINARY_OP; }
">=" { yylval->binaryOp = MapCSSCondition::GreaterOrEqual; return T_BINARY_OP; }

"@import" { return T_KEYWORD_IMPORT; }
"url"     { return T_KEYWORD_URL; }

{IDENTIFIER} {
    yylval->strRef.str = yytext;
    yylval->strRef.len = yyleng;
    return T_IDENT;
}

{HEXCOLOR8}  {
    yylval->uintVal = strtol(yytext + 1, nullptr, 16);
    return T_HEX_COLOR;
}
{HEXCOLOR6}  {
    yylval->uintVal = 0xff000000 | strtol(yytext + 1, nullptr, 16);
    return T_HEX_COLOR;
}

{STRING} {
    yylval->str = unquoteString(yytext);
    return T_STRING;
}

{DOUBLE} {
    yylval->doubleVal = strtod(yytext, nullptr);
    return T_DOUBLE;
}

"//"[^\n]*\n { yy_column = 1; }

"/*"             BEGIN(comment);
<comment>[^*\n]*
<comment>"*"+[^*/\n]*
<comment>\n      { yy_column = 1; }
<comment>"*"+"/" BEGIN(INITIAL);

. {
    printf("unexpected character: %s at %d:%d\n", yytext, yylloc->first_line, yylloc->first_column);
}

%%
