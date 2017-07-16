#include <istream>
#include <string>


namespace util {

// Based on https://stackoverflow.com/questions/6089231/getting-std-ifstream-to-handle-lf-cr-and-crlf
// TODO if reading from a file stream, has it to be opened in binary mode?

template<typename CharT, typename Traits, typename Alloc>
std::basic_istream<CharT, Traits>& getline(std::basic_istream<CharT, Traits>& is,
                                           std::basic_string<CharT, Traits, Alloc>& t)
{
    typedef std::basic_istream<CharT, Traits>       istream_type;
    typedef std::basic_string<CharT, Traits, Alloc> string_type;
    typedef std::basic_streambuf<CharT, Traits>     streambuf_type;

    const typename Traits::int_type EOF_VALUE = Traits::eof();
    const typename Traits::int_type CR_VALUE  = '\r';
    const typename Traits::int_type LF_VALUE  = '\n';

    t.clear();

    typename istream_type::sentry se(is, true);
    streambuf_type* sb = is.rdbuf();

    for (;;) {
        typename Traits::int_type c = sb->sbumpc();
        switch (c) {
        case LF_VALUE:
            return is;

        case CR_VALUE:
            if (sb->sgetc() == LF_VALUE) {
                sb->sbumpc();
            }
            return is;

        case EOF_VALUE:
            // Also handle the case when the last line has no line ending
            if (t.empty()) {
                is.setstate(std::ios::eofbit);
            }
            return is;

        default:
            t += static_cast<CharT>(c);
        }
    }
}

}

