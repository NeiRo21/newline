#pragma once

#include "newline/detector.hpp"

#include <istream>
#include <string>

namespace newline {

template<typename CharT, typename Traits, typename Alloc>
std::basic_istream<CharT, Traits>& getline(
        std::basic_istream<CharT, Traits>& is,
        const basic_newline<CharT>& lineTerminator,
        std::basic_string<CharT, Traits, Alloc>& result)
{
    using istream_type   = std::basic_istream<CharT, Traits>;
    using string_type    = std::basic_string<CharT, Traits, Alloc>;
    using streambuf_type = std::basic_streambuf<CharT, Traits>;

    constexpr auto EOF_VALUE = Traits::eof();

    result.clear();

    typename istream_type::sentry se{is, true};
    auto sb = is.rdbuf();
    detector d{lineTerminator};

    for (;;) {
        if (d.isnext(sb)) {
            return is;
        }

        auto c = sb->sbumpc();
        if (c == EOF_VALUE) {
            //handle the case when the last line has no terminator
            if (result.empty()) {
                is.setstate(std::ios::eofbit);
            }
            return is;
        }
        else {
            result += static_cast<CharT>(c);
        }
    }
}

}

