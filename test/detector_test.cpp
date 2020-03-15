#include "newline/detector.hpp"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <sstream>
#include <string>

using ::testing::Eq;

template<typename T>
class DetectorTest : public ::testing::Test
{
protected:
    static const T NewlineSeq[];
    static const T NoNewlineSeq[];
    static const T EmptySeq[];
    static const T IncompleteNewlineSeq[];
    static const T OffsetNewlineSeq[];
};

template<> const char DetectorTest<char>::NewlineSeq[]         = "\r\n";
template<> const wchar_t DetectorTest<wchar_t>::NewlineSeq[]   = L"\r\n";
template<> const char16_t DetectorTest<char16_t>::NewlineSeq[] = u"\r\n";
template<> const char32_t DetectorTest<char32_t>::NewlineSeq[] = U"\r\n";

template<> const char DetectorTest<char>::NoNewlineSeq[]         = "test";
template<> const wchar_t DetectorTest<wchar_t>::NoNewlineSeq[]   = L"test";
template<> const char16_t DetectorTest<char16_t>::NoNewlineSeq[] = u"test";
template<> const char32_t DetectorTest<char32_t>::NoNewlineSeq[] = U"test";

template<> const char DetectorTest<char>::EmptySeq[]         = "";
template<> const wchar_t DetectorTest<wchar_t>::EmptySeq[]   = L"";
template<> const char16_t DetectorTest<char16_t>::EmptySeq[] = u"";
template<> const char32_t DetectorTest<char32_t>::EmptySeq[] = U"";

template<>
const char DetectorTest<char>::IncompleteNewlineSeq[]         = "\r";
template<>
const wchar_t DetectorTest<wchar_t>::IncompleteNewlineSeq[]   = L"\r";
template<>
const char16_t DetectorTest<char16_t>::IncompleteNewlineSeq[] = u"\r";
template<>
const char32_t DetectorTest<char32_t>::IncompleteNewlineSeq[] = U"\r";

template<>
const char DetectorTest<char>::OffsetNewlineSeq[]         = "\r\r\n";
template<>
const wchar_t DetectorTest<wchar_t>::OffsetNewlineSeq[]   = L"\r\r\n";
template<>
const char16_t DetectorTest<char16_t>::OffsetNewlineSeq[] = u"\r\r\n";
template<>
const char32_t DetectorTest<char32_t>::OffsetNewlineSeq[] = U"\r\r\n";


using NewlineSeqTypes = ::testing::Types<char, wchar_t, char16_t, char32_t>;
TYPED_TEST_CASE(DetectorTest, NewlineSeqTypes);


TYPED_TEST(DetectorTest, detectsNewlineInStream)
{
    constexpr newline::basic_newline<TypeParam> newlineSeq{this->NewlineSeq};
    constexpr newline::detector detector{newlineSeq};

    const std::basic_string<TypeParam> inputString{this->NewlineSeq};
    std::basic_stringstream<TypeParam> ss{inputString};

    ASSERT_THAT(detector.isnext(ss.rdbuf()), Eq(true));
    ASSERT_THAT(detector.isnext(ss), Eq(true));
}

TYPED_TEST(DetectorTest, failsToDetectInNoNewlineStream)
{
    constexpr newline::basic_newline<TypeParam> newlineSeq{this->NewlineSeq};
    constexpr newline::detector detector{newlineSeq};

    const std::basic_string<TypeParam> inputString{this->NoNewlineSeq};
    std::basic_stringstream<TypeParam> ss{inputString};

    ASSERT_THAT(detector.isnext(ss.rdbuf()), Eq(false));
    ASSERT_THAT(detector.isnext(ss), Eq(false));
}

TYPED_TEST(DetectorTest, failsToDetectInEmptyStream)
{
    constexpr newline::basic_newline<TypeParam> newlineSeq{this->NewlineSeq};
    constexpr newline::detector detector{newlineSeq};

    const std::basic_string<TypeParam> inputString{this->EmptySeq};
    std::basic_stringstream<TypeParam> ss{inputString};

    ASSERT_THAT(detector.isnext(ss.rdbuf()), Eq(false));
    ASSERT_THAT(detector.isnext(ss), Eq(false));
}

TYPED_TEST(DetectorTest, failsToDetectInIncompleteNewlineStream)
{
    constexpr newline::basic_newline<TypeParam> newlineSeq{this->NewlineSeq};
    constexpr newline::detector detector{newlineSeq};

    const std::basic_string<TypeParam> inputString{this->IncompleteNewlineSeq};
    std::basic_stringstream<TypeParam> ss{inputString};

    ASSERT_THAT(detector.isnext(ss.rdbuf()), Eq(false));
    ASSERT_THAT(detector.isnext(ss), Eq(false));
}

TYPED_TEST(DetectorTest, failsToDetectInOffsetNewlineStream)
{
    constexpr newline::basic_newline<TypeParam> newlineSeq{this->NewlineSeq};
    constexpr newline::detector detector{newlineSeq};

    const std::basic_string<TypeParam> inputString{this->OffsetNewlineSeq};
    std::basic_stringstream<TypeParam> ss{inputString};

    ASSERT_THAT(detector.isnext(ss.rdbuf()), Eq(false));
    ASSERT_THAT(detector.isnext(ss), Eq(false));
}
