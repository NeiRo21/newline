#pragma once

template<typename T>
class Sequences
{
public:
    static const T NewlineSeq[];
    static const T NoNewlineSeq[];
    static const T EmptySeq[];
    static const T IncompleteNewlineSeq[];
    static const T OffsetNewlineSeq[];
};

template<> const char Sequences<char>::NewlineSeq[]         = "\r\n";
template<> const wchar_t Sequences<wchar_t>::NewlineSeq[]   = L"\r\n";
template<> const char16_t Sequences<char16_t>::NewlineSeq[] = u"\r\n";
template<> const char32_t Sequences<char32_t>::NewlineSeq[] = U"\r\n";

template<> const char Sequences<char>::NoNewlineSeq[]         = "test";
template<> const wchar_t Sequences<wchar_t>::NoNewlineSeq[]   = L"test";
template<> const char16_t Sequences<char16_t>::NoNewlineSeq[] = u"test";
template<> const char32_t Sequences<char32_t>::NoNewlineSeq[] = U"test";

template<> const char Sequences<char>::EmptySeq[]         = "";
template<> const wchar_t Sequences<wchar_t>::EmptySeq[]   = L"";
template<> const char16_t Sequences<char16_t>::EmptySeq[] = u"";
template<> const char32_t Sequences<char32_t>::EmptySeq[] = U"";

template<>
const char Sequences<char>::IncompleteNewlineSeq[]         = "\r";
template<>
const wchar_t Sequences<wchar_t>::IncompleteNewlineSeq[]   = L"\r";
template<>
const char16_t Sequences<char16_t>::IncompleteNewlineSeq[] = u"\r";
template<>
const char32_t Sequences<char32_t>::IncompleteNewlineSeq[] = U"\r";

template<>
const char Sequences<char>::OffsetNewlineSeq[]         = "\r\r\n";
template<>
const wchar_t Sequences<wchar_t>::OffsetNewlineSeq[]   = L"\r\r\n";
template<>
const char16_t Sequences<char16_t>::OffsetNewlineSeq[] = u"\r\r\n";
template<>
const char32_t Sequences<char32_t>::OffsetNewlineSeq[] = U"\r\r\n";

