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

template<> inline const char     Sequences<char>::NewlineSeq[]     = "\r\n";
template<> inline const wchar_t  Sequences<wchar_t>::NewlineSeq[]  = L"\r\n";
template<> inline const char16_t Sequences<char16_t>::NewlineSeq[] = u"\r\n";
template<> inline const char32_t Sequences<char32_t>::NewlineSeq[] = U"\r\n";

template<> inline const char     Sequences<char>::NoNewlineSeq[]     = "test";
template<> inline const wchar_t  Sequences<wchar_t>::NoNewlineSeq[]  = L"test";
template<> inline const char16_t Sequences<char16_t>::NoNewlineSeq[] = u"test";
template<> inline const char32_t Sequences<char32_t>::NoNewlineSeq[] = U"test";

template<> inline const char     Sequences<char>::EmptySeq[]     = "";
template<> inline const wchar_t  Sequences<wchar_t>::EmptySeq[]  = L"";
template<> inline const char16_t Sequences<char16_t>::EmptySeq[] = u"";
template<> inline const char32_t Sequences<char32_t>::EmptySeq[] = U"";

template<>
inline const char     Sequences<char>::IncompleteNewlineSeq[]     = "\r";
template<>
inline const wchar_t  Sequences<wchar_t>::IncompleteNewlineSeq[]  = L"\r";
template<>
inline const char16_t Sequences<char16_t>::IncompleteNewlineSeq[] = u"\r";
template<>
inline const char32_t Sequences<char32_t>::IncompleteNewlineSeq[] = U"\r";

template<>
inline const char     Sequences<char>::OffsetNewlineSeq[]     = "\r\r\n";
template<>
inline const wchar_t  Sequences<wchar_t>::OffsetNewlineSeq[]  = L"\r\r\n";
template<>
inline const char16_t Sequences<char16_t>::OffsetNewlineSeq[] = u"\r\r\n";
template<>
inline const char32_t Sequences<char32_t>::OffsetNewlineSeq[] = U"\r\r\n";

