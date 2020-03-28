#pragma once

#include "newline/newline_defs.h"
#include "newline/detector.hpp"

#include <istream>
#include <string>

namespace newline {

template<typename CharT, typename Traits, typename Alloc>
std::basic_istream<CharT, Traits>& getline(
        std::basic_istream<CharT, Traits>& is,
        std::basic_string<CharT, Traits, Alloc>& str,
        const basic_newline<CharT>& eol)
{
    using istream_type   = std::basic_istream<CharT, Traits>;
    using string_type    = std::basic_string<CharT, Traits, Alloc>;
    using streambuf_type = std::basic_streambuf<CharT, Traits>;

    constexpr auto EOF_VALUE = Traits::eof();

    str.clear();

    typename istream_type::sentry se{is, true};
    auto sb = is.rdbuf();
    detector d{eol};

    for (;;) {
        if (d.isnext(sb)) {
            return is;
        }

        auto c = sb->sbumpc();
        if (c == EOF_VALUE) {
            //handle the case when the last line has no eol
            if (str.empty()) {
                is.setstate(std::ios::eofbit);
            }
            return is;
        }
        else {
            str += static_cast<CharT>(c);
        }
    }
}

}
