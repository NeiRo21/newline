#pragma once

#include "newline/newline_defs.h"

namespace newline::utf32 {
    inline constexpr u32newline None = U"";

    inline constexpr u32newline LineFeed = U"\u000A";
    inline constexpr const u32newline& LF = LineFeed;

    inline constexpr u32newline VerticalTab = U"\u000B";
    inline constexpr const u32newline& VT = VerticalTab;

    inline constexpr u32newline FormFeed = U"\u000C";
    inline constexpr const u32newline& FF = FormFeed;

    inline constexpr u32newline CarriageReturn = U"\u000D";
    inline constexpr const u32newline& CR = CarriageReturn;

    inline constexpr u32newline CRLF = U"\u000D\u000A";

    inline constexpr u32newline NextLine = U"\u0085";
    inline constexpr const u32newline& NEL = NextLine;

    inline constexpr u32newline LineSeparator = U"\u2028";
    inline constexpr const u32newline& LS = LineSeparator;

    inline constexpr u32newline ParagraphSeparator = U"\u2029";
    inline constexpr const u32newline& PS = ParagraphSeparator;
}
