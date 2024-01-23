/*
    SPDX-FileCopyrightText: 2023 Jonah Brüchert <jbb@kaidan.im>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>

#include <unordered_map>

#include "localbackendutils.h"
#include "journeyrequest.h"


using namespace KPublicTransport::LocalBackendUtils;

class Transliteration {
public:
    /// simplify less common characters into simpler multi-character equivalents
    QString latinize(const QString &string) const {
        static std::unordered_map<QChar, QStringView> table {
            {u'đ', u"dj"}, {u'ć', u"c"}
        };

        QString out;
        out.reserve(string.size());

        for (auto c : string) {
            if (table.contains(c)) {
                out.append(table.at(c));
            } else {
                out.push_back(c);
            }
        }

        return out;
    }

    /// Converts strings from the cyrillic alphabet to their latin equivalents
    QString transliterate(const QString &cyrillic) const {
        // Avoid construction of transliteration table and manual string copy if nothing requires transliteration
        if (std::none_of(cyrillic.begin(), cyrillic.end(), [](QChar c) {
                return c.script() == QChar::Script_Cyrillic;
            })) {
            // No copy, because implicitly shared
            return cyrillic;
        }

        // Generated from <table> element on https://de.wikipedia.org/wiki/ISO_9
        // using src/lib/networks/stations/generate_transliteration_table.py
        static std::unordered_map<QChar, QStringView> iso9Table = {
            {u'А', u"A"}, {u'а', u"a"}, {u'Ӑ', u"Ă"}, {u'ӑ', u"ă"}, {u'Ӓ', u"Ä"},
            {u'ӓ', u"ä"}, {u'Ә', u"A"}, {u'ә', u"a"}, {u'Б', u"B"}, {u'б', u"b"},
            {u'В', u"V"}, {u'в', u"v"}, {u'Г', u"G"}, {u'г', u"g"}, {u'Ґ', u"G"},
            {u'ґ', u"g"}, {u'Ҕ', u"Ğ"}, {u'ҕ', u"ğ"}, {u'Ғ', u"Ġ"}, {u'ғ', u"ġ"},
            {u'Д', u"D"}, {u'д', u"d"}, {u'Ђ', u"Đ"}, {u'ђ', u"đ"}, {u'Ѓ', u"Ǵ"},
            {u'ѓ', u"ǵ"}, {u'Е', u"E"}, {u'е', u"e"}, {u'Ё', u"Ë"}, {u'ё', u"ë"},
            {u'Ӗ', u"Ĕ"}, {u'ӗ', u"ĕ"}, {u'Є', u"Ê"}, {u'є', u"ê"}, {u'Ҽ', u"C"},
            {u'ҽ', u"c"}, {u'Ҿ', u"Ç"}, {u'ҿ', u"ç"}, {u'Ж', u"Ž"}, {u'ж', u"ž"},
            {u'Ӂ', u"Z"}, {u'ӂ', u"z"}, {u'Ӝ', u"Z"}, {u'ӝ', u"z"}, {u'Җ', u"Ž"},
            {u'җ', u"ž"}, {u'З', u"Z"}, {u'з', u"z"}, {u'Ӟ', u"Z"}, {u'ӟ', u"z"},
            {u'Ѕ', u"Ẑ"}, {u'ѕ', u"ẑ"}, {u'Ӡ', u"Ź"}, {u'ӡ', u"ź"}, {u'И', u"I"},
            {u'и', u"i"}, {u'Ӥ', u"Î"}, {u'ӥ', u"î"}, {u'І', u"Ì"}, {u'і', u"ì"},
            {u'Ї', u"Ï"}, {u'ї', u"ï"}, {u'Й', u"J"}, {u'й', u"j"}, {u'Ј', u"J"},
            {u'ј', u"ǰ"}, {u'К', u"K"}, {u'к', u"k"}, {u'Қ', u"Ķ"}, {u'қ', u"ķ"},
            {u'Ҟ', u"K"}, {u'ҟ', u"k"}, {u'Л', u"L"}, {u'л', u"l"}, {u'Љ', u"L"},
            {u'љ', u"l̂"}, {u'М', u"M"}, {u'м', u"m"}, {u'Н', u"N"}, {u'н', u"n"},
            {u'Њ', u"N"}, {u'њ', u"n"}, {u'Ҥ', u"Ṅ"}, {u'ҥ', u"ṅ"}, {u'Ң', u"Ṇ"},
            {u'ң', u"ṇ"}, {u'О', u"O"}, {u'о', u"o"}, {u'Ӧ', u"Ö"}, {u'ӧ', u"ö"},
            {u'Ө', u"Ô"}, {u'ө', u"ô"}, {u'П', u"P"}, {u'п', u"p"}, {u'Ҧ', u"Ṕ"},
            {u'ҧ', u"ṕ"}, {u'Р', u"R"}, {u'р', u"r"}, {u'С', u"S"}, {u'с', u"s"},
            {u'Ҫ', u"Ç"}, {u'ҫ', u"ç"}, {u'Т', u"T"}, {u'т', u"t"}, {u'Ҭ', u"Ţ"},
            {u'ҭ', u"ţ"}, {u'Ћ', u"Ć"}, {u'ћ', u"ć"}, {u'Ќ', u"Ḱ"}, {u'ќ', u"ḱ"},
            {u'У', u"U"}, {u'у', u"u"}, {u'У', u"Ú"}, {u'у', u"ú"}, {u'Ў', u"Ŭ"},
            {u'ў', u"ŭ"}, {u'Ӱ', u"Ü"}, {u'ӱ', u"ü"}, {u'Ӳ', u"Ű"}, {u'ӳ', u"ű"},
            {u'Ү', u"Ù"}, {u'ү', u"ù"}, {u'Ф', u"F"}, {u'ф', u"f"}, {u'Х', u"H"},
            {u'х', u"h"}, {u'Ҳ', u"Ḩ"}, {u'ҳ', u"ḩ"}, {u'Һ', u"Ḥ"}, {u'һ', u"ḥ"},
            {u'Ц', u"C"}, {u'ц', u"c"}, {u'Ҵ', u"C"}, {u'ҵ', u"c"}, {u'Ч', u"Č"},
            {u'ч', u"č"}, {u'Ӵ', u"C"}, {u'ӵ', u"c"}, {u'Ҷ', u"Ç"}, {u'ҷ', u"ç"},
            {u'Џ', u"D"}, {u'џ', u"d"}, {u'Ш', u"Š"}, {u'ш', u"š"}, {u'Щ', u"Ŝ"},
            {u'щ', u"ŝ"}, {u'Ы', u"Y"}, {u'ы', u"y"}, {u'Ӹ', u"Ÿ"}, {u'ӹ', u"ÿ"},
            {u'Э', u"È"}, {u'э', u"è"}, {u'Ю', u"Û"}, {u'ю', u"û"}, {u'Я', u"Â"},
            {u'я', u"â"}, {u'Ѣ', u"Ě"}, {u'ѣ', u"ě"}, {u'Ѫ', u"Ǎ"}, {u'ѫ', u"ǎ"},
            {u'Ѳ', u"F"}, {u'ѳ', u"f"}, {u'Ѵ', u"Ỳ"}, {u'ѵ', u"ỳ"}, {u'Ҩ', u"Ò"},
            {u'ҩ', u"ò"}, {u'Ӏ', u"‡"}, {u'’', u"‵"},
        };


        QString out;
        out.reserve(cyrillic.size());

        for (auto c : cyrillic) {
            if (iso9Table.contains(c)) {
                out.append(iso9Table.at(c));
            } else {
                out.push_back(c);
            }
        }

        return out;
    };
};


QString KPublicTransport::LocalBackendUtils::makeSearchableName(const QString &name)
{
    Transliteration t;
    return t.latinize(t.transliterate(name))
        // Remove parts in parantheses, the DB API likes to add the country in parantheses
        .replace(QRegularExpression(QStringLiteral(R"(\([^)]*\))")), QString())
        // Split accents into their own charcters
        .normalized(QString::NormalizationForm_D)
        // filter those characters out
        .replace(QRegularExpression(QStringLiteral("[^a-zA-Z0-9\\s]")), QString())
        // Remove spaces
        .replace(QStringLiteral(" "), QString())
        .toLower()
        .trimmed();
}

bool KPublicTransport::LocalBackendUtils::isInSelectedTimeframe(const QDateTime &departure, const QDateTime &arrival, const JourneyRequest &req)
{
    // Filter for requested arrival / departure time frame
    if (req.dateTimeMode() == JourneyRequest::Departure) {
        if (departure < req.dateTime()) {
            return false;
        }
    } else {
        if (arrival > req.dateTime()) {
            return false;
        }
    }

    return true;
}
