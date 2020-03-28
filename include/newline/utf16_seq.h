#pragma once

#include "newline/newline_defs.h"

namespace newline::utf16 {
    inline constexpr u16newline None = u"";

    inline constexpr u16newline LineFeed = u"\u000A";
    inline constexpr const u16newline& LF = LineFeed;

    inline constexpr u16newline VerticalTab = u"\u000B";
    inline constexpr const u16newline& VT = VerticalTab;

    inline constexpr u16newline FormFeed = u"\u000C";
    inline constexpr const u16newline& FF = FormFeed;

    inline constexpr u16newline CarriageReturn = u"\u000D";
    inline constexpr const u16newline& CR = CarriageReturn;

    inline constexpr u16newline CRLF = u"\u000D\u000A";

    inline constexpr u16newline NextLine = u"\u0085";
    inline constexpr const u16newline& NEL = NextLine;

    inline constexpr u16newline LineSeparator = u"\u2028";
    inline constexpr const u16newline& LS = LineSeparator;

    inline constexpr u16newline ParagraphSeparator = u"\u2029";
    inline constexpr const u16newline& PS = ParagraphSeparator;
}
