#pragma once

#include "newline/newline_defs.h"

namespace newline::utf8 {
    inline constexpr u8newline None = "";

    inline constexpr u8newline LineFeed = "\u000A";
    inline constexpr const u8newline& LF = LineFeed;

    inline constexpr u8newline VerticalTab = "\u000B";
    inline constexpr const u8newline& VT = VerticalTab;

    inline constexpr u8newline FormFeed = "\u000C";
    inline constexpr const u8newline& FF = FormFeed;

    inline constexpr u8newline CarriageReturn = "\u000D";
    inline constexpr const u8newline& CR = CarriageReturn;

    inline constexpr u8newline CRLF = "\u000D\u000A";

    inline constexpr u8newline NextLine = "\u0085";
    inline constexpr const u8newline& NEL = NextLine;

    inline constexpr u8newline LineSeparator = "\u2028";
    inline constexpr const u8newline& LS = LineSeparator;

    inline constexpr u8newline ParagraphSeparator = "\u2029";
    inline constexpr const u8newline& PS = ParagraphSeparator;
}
