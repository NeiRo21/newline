#include "newline/getline.hpp"
#include "test_defs.hpp"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <sstream>
#include <string>

using ::testing::Eq;

template<typename T>
class GetlineTest : public ::testing::Test
{};

using NewlineSeqTypes = ::testing::Types<char, wchar_t, char16_t, char32_t>;
TYPED_TEST_CASE(GetlineTest, NewlineSeqTypes);

TYPED_TEST(GetlineTest, readsTerminatedLineFromStream)
{
    using Seq = Sequences<TypeParam>;

    constexpr newline::basic_newline<TypeParam> TERMINATOR{Seq::NewlineSeq};

    const std::basic_string<TypeParam> ExpectedString{Seq::NoNewlineSeq};
    std::basic_string<TypeParam> inputString{
            ExpectedString + Seq::NewlineSeq + ExpectedString};
    std::basic_stringstream<TypeParam> ss{inputString};

    std::basic_string<TypeParam> result;
    newline::getline(ss, TERMINATOR, result);

    ASSERT_THAT(result, Eq(ExpectedString));
}

TYPED_TEST(GetlineTest, readsTillEndOfStreamForEmptyTerminator)
{
    using Seq = Sequences<TypeParam>;

    constexpr newline::basic_newline<TypeParam> TERMINATOR{Seq::EmptySeq};

    std::basic_string<TypeParam> inputString{Seq::NoNewlineSeq};
    (inputString += Seq::NewlineSeq) += Seq::NoNewlineSeq;
    std::basic_stringstream<TypeParam> ss{inputString};

    std::basic_string<TypeParam> result;
    newline::getline(ss, TERMINATOR, result);

    ASSERT_THAT(result, Eq(inputString));
}

