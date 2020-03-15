#pragma once

#include <string_view>

namespace newline {

template<typename CharT>
using generic_newline = std::basic_string_view<CharT>;

using newline     = generic_newline<char>;
using newline_w   = generic_newline<wchar_t>;
using newline_u16 = generic_newline<char16_t>;
using newline_u32 = generic_newline<char32_t>;

#define NEWLINE_DEF(NAME, NEWLINE_SEQ) \
    inline constexpr newline NAME{NEWLINE_SEQ};\
    inline constexpr newline_w NAME##_w{L##NEWLINE_SEQ};\
    inline constexpr newline_u16 NAME##_u16{u##NEWLINE_SEQ};\
    inline constexpr newline_u32 NAME##_u32{U##NEWLINE_SEQ};

#define NEWLINE_ALIAS(DEST, SRC) \
    inline constexpr const newline& DEST = SRC;\
    inline constexpr const newline_w& DEST##_w = SRC##_w;\
    inline constexpr const newline_u16& DEST##_u16 = SRC##_u16;\
    inline constexpr const newline_u32& DEST##_u32 = SRC##_u32;
}

