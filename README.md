# newline
_newline_ is a C++17 header-only library for text processing.
Its main feature is support of various known newline (end of line) sequences as well as arbitrary user-defined ones.

### Getting started:
Just include `newline/newline.h` to access all features.

See **Features** for details about accessing individual features.

## Features
| Feature | Header |
| --- | --- |
| Basic definitions e.g. `basic_newline` template | `newline_defs.h` |
| 8 bit charset newline sequence constants | `byte_seq.h` |
| UTF8 newline sequence constants | `utf8_seq.h` |
| UTF16 newline sequence constants | `utf16_seq.h` |
| UTF32 newline sequence constants | `utf32_seq.h` |
| Wide char newline sequence constants | `wide_seq.h` |
| Newline detector | `detector.hpp` |
| `getline` implementation | `getline.hpp` |

## Platforms
_newline_ is designed to be cross-platform.

It has currently been tested on:
* Linux x86_64 (GCC)
* Windows x86_64 (MiniGW)

## Requirements
* a C++17-enabled compiler

### Build requirements (unit tests)
* [CMake](https://cmake.org) >= 3.12
