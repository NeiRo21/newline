#pragma once

#include "newline/newline_defs.h"

namespace newline::wide {
    inline constexpr wnewline None = L"";

    inline constexpr wnewline LineFeed = L"\u000A";
    inline constexpr const wnewline& LF = LineFeed;

    inline constexpr wnewline VerticalTab = L"\u000B";
    inline constexpr const wnewline& VT = VerticalTab;

    inline constexpr wnewline FormFeed = L"\u000C";
    inline constexpr const wnewline& FF = FormFeed;

    inline constexpr wnewline CarriageReturn = L"\u000D";
    inline constexpr const wnewline& CR = CarriageReturn;

    inline constexpr wnewline CRLF = L"\u000D\u000A";

    inline constexpr wnewline NextLine = L"\u0085";
    inline constexpr const wnewline& NEL = NextLine;

    inline constexpr wnewline LineSeparator = L"\u2028";
    inline constexpr const wnewline& LS = LineSeparator;

    inline constexpr wnewline ParagraphSeparator = L"\u2029";
    inline constexpr const wnewline& PS = ParagraphSeparator;
}
