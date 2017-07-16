#include <util/getline.hpp>

#include <gtest/gtest.h>

#include <sstream>
#include <string>


template<typename T, std::size_t N>
std::size_t sizeOfArray(const T(&)[N])
{
    return N;
}

template<typename CharT, typename Traits, typename Alloc>
std::basic_string<CharT, Traits, Alloc> trimEndl(const std::basic_string<CharT, Traits, Alloc>& s)
{
    typedef std::basic_string<CharT, Traits, Alloc> string_type;
    const typename string_type::value_type CR = '\r';
    const typename string_type::value_type LF = '\n';

    string_type res = s;
    if (!res.empty()) {
        typename string_type::const_reverse_iterator it = res.rbegin();
        if (*it == LF) {
            ++it;
            if (*it == CR) {
                ++it;
            }
        }
        else if (*it == CR) {
            ++it;
        }
        res.erase(it.base(), res.end());
    }
    return res;
}

TEST(GetlineTest, charStrings)
{
    const std::string Src[] = {
        "an LF-terminated line\n",
        "\n", // an empty LF-terminated line
        "a CRLF-terminated line\r\n",
        "\r\n", // an empty CRLF-terminated line
        "a CR-terminated line\r",
        "\r", // an empty CR-terminated line
        "the last line without a terminator"
    };
    const std::size_t SrcSize = sizeOfArray(Src);

    std::stringstream ss;
    for (std::size_t i = 0; i < SrcSize; ++i) {
        ss << Src[i];
    }

    std::string t;
    std::size_t i = 0;
    while (ss.good() && i < SrcSize) {
        util::getline(ss, t);
        ASSERT_EQ(t, trimEndl(Src[i]));
        ++i;
    }

    // dummy read to set eof
    ss >> t;

    ASSERT_TRUE(ss.eof());
    ASSERT_EQ(i, SrcSize);
}

TEST(GetlineTest, wcharStrings)
{
    const std::wstring Src[] = {
        L"an LF-terminated line\n",
        L"\n", // an empty LF-terminated line
        L"a CRLF-terminated line\r\n",
        L"\r\n", // an empty CRLF-terminated line
        L"a CR-terminated line\r",
        L"\r", // an empty CR-terminated line
        L"the last line without a terminator"
    };
    const std::size_t SrcSize = sizeOfArray(Src);

    std::wstringstream ss;
    for (std::size_t i = 0; i < SrcSize; ++i) {
        ss << Src[i];
    }

    std::wstring t;
    std::size_t i = 0;
    while (ss.good() && i < SrcSize) {
        util::getline(ss, t);
        ASSERT_EQ(t, trimEndl(Src[i]));
        ++i;
    }

    // dummy read to set eof
    ss >> t;

    ASSERT_TRUE(ss.eof());
    ASSERT_EQ(i, SrcSize);
}

