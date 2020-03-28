#pragma once

#include <string_view>

namespace newline {

template<typename CharT>
using basic_newline = std::basic_string_view<CharT>;

using newline    = basic_newline<char>;
using u8newline  = newline;
using wnewline   = basic_newline<wchar_t>;
using u16newline = basic_newline<char16_t>;
using u32newline = basic_newline<char32_t>;
}
