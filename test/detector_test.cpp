#include "newline/detector.hpp"
#include "test_defs.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <sstream>
#include <string>

using ::testing::Eq;

template<typename T>
class DetectorTest : public ::testing::Test
{};

using NewlineSeqTypes = ::testing::Types<char, wchar_t, char16_t, char32_t>;
TYPED_TEST_CASE(DetectorTest, NewlineSeqTypes);

TYPED_TEST(DetectorTest, detectsNewlineInStream)
{
    using Seq = Sequences<TypeParam>;

    constexpr newline::basic_newline<TypeParam> newlineSeq{Seq::NewlineSeq};
    constexpr newline::detector detector{newlineSeq};

    const std::basic_string<TypeParam> inputString{Seq::NewlineSeq};
    std::basic_stringstream<TypeParam> ss{inputString};

    ASSERT_THAT(detector.isnext(ss.rdbuf()), Eq(true));
    ASSERT_THAT(detector.isnext(ss), Eq(true));
}

TYPED_TEST(DetectorTest, failsToDetectInNoNewlineStream)
{
    using Seq = Sequences<TypeParam>;

    constexpr newline::basic_newline<TypeParam> newlineSeq{Seq::NewlineSeq};
    constexpr newline::detector detector{newlineSeq};

    const std::basic_string<TypeParam> inputString{Seq::NoNewlineSeq};
    std::basic_stringstream<TypeParam> ss{inputString};

    ASSERT_THAT(detector.isnext(ss.rdbuf()), Eq(false));
    ASSERT_THAT(detector.isnext(ss), Eq(false));
}

TYPED_TEST(DetectorTest, failsToDetectInEmptyStream)
{
    using Seq = Sequences<TypeParam>;

    constexpr newline::basic_newline<TypeParam> newlineSeq{Seq::NewlineSeq};
    constexpr newline::detector detector{newlineSeq};

    const std::basic_string<TypeParam> inputString{Seq::EmptySeq};
    std::basic_stringstream<TypeParam> ss{inputString};

    ASSERT_THAT(detector.isnext(ss.rdbuf()), Eq(false));
    ASSERT_THAT(detector.isnext(ss), Eq(false));
}

TYPED_TEST(DetectorTest, failsToDetectInIncompleteNewlineStream)
{
    using Seq = Sequences<TypeParam>;

    constexpr newline::basic_newline<TypeParam> newlineSeq{Seq::NewlineSeq};
    constexpr newline::detector detector{newlineSeq};

    const std::basic_string<TypeParam> inputString{Seq::IncompleteNewlineSeq};
    std::basic_stringstream<TypeParam> ss{inputString};

    ASSERT_THAT(detector.isnext(ss.rdbuf()), Eq(false));
    ASSERT_THAT(detector.isnext(ss), Eq(false));
}

TYPED_TEST(DetectorTest, failsToDetectInOffsetNewlineStream)
{
    using Seq = Sequences<TypeParam>;

    constexpr newline::basic_newline<TypeParam> newlineSeq{Seq::NewlineSeq};
    constexpr newline::detector detector{newlineSeq};

    const std::basic_string<TypeParam> inputString{Seq::OffsetNewlineSeq};
    std::basic_stringstream<TypeParam> ss{inputString};

    ASSERT_THAT(detector.isnext(ss.rdbuf()), Eq(false));
    ASSERT_THAT(detector.isnext(ss), Eq(false));
}
