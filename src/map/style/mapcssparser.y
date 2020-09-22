%{
/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "mapcssparser_p.h"
#include "mapcssscanner.h"

#include "style/mapcssparser.h"
#include "style/mapcssrule.h"
#include "style/mapcssselector.h"
#include "style/mapcssstyle.h"

void yyerror(YYLTYPE *loc, KOSMIndoorMap::MapCSSParser *parser, yyscan_t scanner, char const* msg)
{
    (void)scanner;
    qWarning() << "PARSER ERROR:" << msg << "in" << parser->fileName() << "line:" << loc->first_line << "column:" << loc->first_column;
    parser->setError(QString::fromUtf8(msg), loc->first_line, loc->first_column);
}

using namespace KOSMIndoorMap;

%}

%code requires {

#include "style/mapcsscondition.h"
#include "style/mapcssselector.h"

namespace KOSMIndoorMap {
class MapCSSDeclaration;
class MapCSSParser;
class MapCSSRule;
class MapCSSStyle;

struct StringRef {
    const char *str;
    int len;
};

struct ZoomRange {
    int low;
    int high;
};

}

#ifndef YY_TYPEDEF_YY_SCANNER_T
#define YY_TYPEDEF_YY_SCANNER_T
typedef void* yyscan_t;
#endif

using namespace KOSMIndoorMap;

}

%define api.pure
%define parse.error verbose

%locations
%lex-param { yyscan_t scanner }
%parse-param { KOSMIndoorMap::MapCSSParser *parser }
%parse-param { yyscan_t scanner }

%union {
    uint32_t uintVal;
    double doubleVal;
    ZoomRange zoomRange;

    char *str;
    StringRef strRef;

    MapCSSRule *rule;
    MapCSSSelector *selector;
    MapCSSBasicSelector *basicSelector;
    MapCSSCondition *condition;
    MapCSSConditionHolder *conditionHolder;
    MapCSSCondition::Operator binaryOp;
    MapCSSDeclaration *declaration;
}

%token T_LBRACKET
%token T_RBRACKET
%token T_LBRACE
%token T_RBRACE
%token T_LPAREN
%token T_RPAREN
%token T_COLON
%token T_SEMICOLON
%token T_COMMA
%token T_SPACE
%token T_DASH
%token T_PLUS
%token T_STAR
%token T_ZOOM
%token T_EXCLAMATION_MARK
%token T_EQUALS
%token T_DOT
%token <binaryOp> T_BINARY_OP
%token T_KEYWORD_IMPORT
%token T_KEYWORD_URL
%token T_KEYWORD_RGBA
%token T_KEYWORD_RGB
%token T_KEYWORD_SET
%token <strRef> T_IDENT
%token <uintVal> T_HEX_COLOR
%token <str> T_STRING
%token <doubleVal> T_DOUBLE

%type <rule> Rule
%type <selector> Selectors
%type <selector> Selector
%type <basicSelector> BasicSelector
%type <conditionHolder> Tests
%type <condition> Test
%type <zoomRange> ZoomRange
%type <condition> Condition
%type <binaryOp> BinaryOp
%type <strRef> Key
%type <rule> Declarations
%type <declaration> Declaration
%type <strRef> PropertyName
%type <declaration> PropertyValue
%type <doubleVal> DoubleValue

%destructor { free($$); } <str>
%destructor { delete $$; } <rule>
%destructor { delete $$; } <selector>
%destructor { delete $$; } <conditionHolder>
%destructor { delete $$; } <condition>
%destructor { delete $$; } <declaration>

%verbose

%%
// see https://wiki.openstreetmap.org/wiki/MapCSS/0.2/BNF

Ruleset:
  Rule
| Ruleset Rule
;

Rule:
  Selectors T_LBRACE Declarations T_RBRACE {
    $3->setSelector($1);
    parser->addRule($3);
    $$ = nullptr;
  }
| Import { $$ = nullptr; }
;

Import:
  T_KEYWORD_IMPORT T_KEYWORD_URL T_LPAREN T_STRING T_RPAREN T_SEMICOLON {
    if (!parser->addImport($4)) {
        YYABORT;
    }
  }
| T_KEYWORD_IMPORT T_KEYWORD_URL T_LPAREN T_STRING T_RPAREN T_IDENT T_SEMICOLON { parser->addImport($4); }
;

Selectors:
  Selector { $$ = $1; }
| Selectors T_COMMA Selector { if (auto u = dynamic_cast<MapCSSUnionSelector*>($1)) {
    u->selectors.push_back(std::unique_ptr<MapCSSSelector>($3));
    $$ = $1;
  } else {
    auto s = new MapCSSUnionSelector;
    s->selectors.push_back(std::unique_ptr<MapCSSSelector>($1));
    s->selectors.push_back(std::unique_ptr<MapCSSSelector>($3));
    $$ = s;
  }}
;

Selector:
  BasicSelector { $$ = $1; }
| Selector BasicSelector { if (auto chain = dynamic_cast<MapCSSChainedSelector*>($1)) {
    chain->selectors.push_back(std::unique_ptr<MapCSSBasicSelector>($2));
    $$ = $1;
  } else {
    auto s = new MapCSSChainedSelector;
    s->selectors.push_back(std::unique_ptr<MapCSSBasicSelector>(static_cast<MapCSSBasicSelector*>($1)));
    s->selectors.push_back(std::unique_ptr<MapCSSBasicSelector>($2));
    $$ = s;
  }}
;

// TODO incomplete: missing class
BasicSelector:
  T_IDENT ZoomRange Tests {
    $$ = new MapCSSBasicSelector;
    $$->setObjectType($1.str, $1.len);
    $$->setZoomRange($2.low, $2.high);
    $$->setConditions($3);
  }
| T_STAR ZoomRange Tests {
    $$ = new MapCSSBasicSelector;
    $$->objectType = MapCSSBasicSelector::Any;
    $$->setZoomRange($2.low, $2.high);
    $$->setConditions($3);
  }
;

ZoomRange:
  %empty { $$.low = 0; $$.high = 0; }
| T_ZOOM T_DOUBLE[Low] T_DASH T_DOUBLE[High] { $$.low = $Low; $$.high = $High; }
| T_ZOOM T_DOUBLE[Low] T_DASH { $$.low = $Low; $$.high = 0; }
| T_ZOOM T_DOUBLE { $$.low = $2; $$.high = $2; }
| T_ZOOM T_DASH T_DOUBLE[High] { $$.low = 0; $$.high = $High; }

Tests:
  %empty { $$ = nullptr; }
| Tests Test { if ($1) { $1->addCondition($2); $$ = $1; } else { auto holder = new MapCSSConditionHolder; holder->addCondition($2); $$ = holder; }}
;

Test: T_LBRACKET Condition T_RBRACKET { $$ = $2; };

// TODO incomplete: quoted names, regexps
Condition:
  Key BinaryOp T_IDENT { $$ = new MapCSSCondition; $$->setKey($1.str, $1.len); $$->setOperation($2); $$->setValue($3.str, $3.len); }
| Key BinaryOp DoubleValue { $$ = new MapCSSCondition; $$->setKey($1.str, $1.len); $$->setOperation($2); $$->setValue($3); }
| T_EXCLAMATION_MARK Key { $$ = new MapCSSCondition; $$->setOperation(MapCSSCondition::KeyNotSet); $$->setKey($2.str, $2.len); }
| Key { $$ = new MapCSSCondition; $$->setOperation(MapCSSCondition::KeySet); $$->setKey($1.str, $1.len); }
;

BinaryOp:
  T_BINARY_OP { $$ = $1; }
| T_EQUALS    { $$ = MapCSSCondition::Equal; }

Key:
  T_IDENT { $$ = $1; }
| Key T_COLON T_IDENT { $$.str = $1.str; $$.len = $3.str - $1.str + $3.len; }
;

Declarations:
  %empty { $$ = new MapCSSRule; }
| Declarations Declaration { $$ = $1; $$->addDeclaration($2); }
;

Declaration:
  PropertyName T_COLON PropertyValue T_SEMICOLON { $$ = $3; $$->setPropertyName($1.str, $1.len); }
| T_KEYWORD_SET Key T_EQUALS T_STRING T_SEMICOLON { $$ = new MapCSSDeclaration(MapCSSDeclaration::TagDeclaration); }
| T_KEYWORD_SET Key T_EQUALS T_DOUBLE T_SEMICOLON { $$ = new MapCSSDeclaration(MapCSSDeclaration::TagDeclaration); }
| T_KEYWORD_SET Key T_SEMICOLON { $$ = new MapCSSDeclaration(MapCSSDeclaration::TagDeclaration); }
| T_KEYWORD_SET T_DOT T_IDENT T_SEMICOLON { $$ = new MapCSSDeclaration(MapCSSDeclaration::ClassDeclaration); }
;

PropertyName:
  T_IDENT { $$ = $1; }
| T_IDENT T_DASH PropertyName { $$.str = $1.str; $$.len = $3.str - $1.str + $3.len; }
;

// TODO incomplete: missing size, url, eval
PropertyValue:
  Key { $$ = new MapCSSDeclaration(MapCSSDeclaration::PropertyDeclaration); $$->setIdentifierValue($1.str, $1.len); }
| T_HEX_COLOR { $$ = new MapCSSDeclaration(MapCSSDeclaration::PropertyDeclaration); $$->setColorRgba($1); }
| DoubleValue T_IDENT { $$ = new MapCSSDeclaration(MapCSSDeclaration::PropertyDeclaration); $$->setDoubleValue($1); $$->setUnit($2.str, $2.len); }
| DoubleValue { $$ = new MapCSSDeclaration(MapCSSDeclaration::PropertyDeclaration); $$->setDoubleValue($1); }
| T_DOUBLE T_COMMA T_DOUBLE { $$ = new MapCSSDeclaration(MapCSSDeclaration::PropertyDeclaration); $$->setDashesValue({$1, $3}); } // generalize to n dash distances
| T_STRING { $$ = new MapCSSDeclaration(MapCSSDeclaration::PropertyDeclaration); $$->setStringValue($1); }
| T_KEYWORD_RGBA T_LPAREN T_DOUBLE[R] T_COMMA T_DOUBLE[G] T_COMMA T_DOUBLE[B] T_COMMA T_DOUBLE[A] T_RPAREN {
    $$ = new MapCSSDeclaration(MapCSSDeclaration::PropertyDeclaration);
    uint32_t c = 0;
    c |= (uint32_t)($A * 255.0) << 24;
    c |= (uint32_t)($R * 255.0) << 16;
    c |= (uint32_t)($G * 255.0) << 8;
    c |= (uint32_t)($B * 255.0) << 0;
    $$->setColorRgba(c);
  }
| T_KEYWORD_RGB T_LPAREN T_DOUBLE[R] T_COMMA T_DOUBLE[G] T_COMMA T_DOUBLE[B] T_RPAREN {
    $$ = new MapCSSDeclaration(MapCSSDeclaration::PropertyDeclaration);
    uint32_t c = 0;
    c |= 0xff << 24;
    c |= (uint32_t)($R * 255.0) << 16;
    c |= (uint32_t)($G * 255.0) << 8;
    c |= (uint32_t)($B * 255.0) << 0;
    $$->setColorRgba(c);
  }
;

DoubleValue:
  T_DOUBLE { $$ = $1; }
| T_DASH T_DOUBLE { $$ = -$2; }
| T_PLUS T_DOUBLE { $$ = $2; }
;

%%
