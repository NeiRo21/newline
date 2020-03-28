#pragma once

#include "newline/newline_defs.h"

namespace newline::byte {
    inline constexpr newline None = "";

    inline constexpr newline Unix = "\n";
    inline constexpr const newline& Linux   = Unix;
    inline constexpr const newline& MacOSX  = Unix;
    inline constexpr const newline& OSX     = Unix;
    inline constexpr const newline& AIX     = Unix;
    inline constexpr const newline& HPUX    = Unix;
    inline constexpr const newline& SunOS   = Unix;
    inline constexpr const newline& Solaris = Unix;
    inline constexpr const newline& FreeBSD = Unix;
    inline constexpr const newline& OpenBSD = Unix;
    inline constexpr const newline& NetBSD  = Unix;
    inline constexpr const newline& BeOS    = Unix;
    inline constexpr const newline& Amiga   = Unix;
    inline constexpr const newline& RISCOS  = Unix;
    inline constexpr const newline& QNX     = Unix;
    inline constexpr const newline& Multics = Unix;
    inline constexpr const newline& Xenix   = Unix;

    inline constexpr newline Windows = "\r\n";
    inline constexpr const newline& DOS      = Windows;
    inline constexpr const newline& OS2      = Windows;
    inline constexpr const newline& AtariTOS = Windows;
    inline constexpr const newline& CPM      = Windows;
    inline constexpr const newline& MPM      = Windows;
    inline constexpr const newline& TOPS12   = Windows;
    inline constexpr const newline& RT11     = Windows;
    inline constexpr const newline& Symbian  = Windows;
    inline constexpr const newline& PalmOS   = Windows;
    inline constexpr const newline& CPC      = Windows;

    inline constexpr newline ZXSpectrum = "\r";
    inline constexpr const newline& Commodore64  = ZXSpectrum;
    inline constexpr const newline& Commodore128 = ZXSpectrum;
    inline constexpr const newline& AcornBBC     = ZXSpectrum;
    inline constexpr const newline& TRS80        = ZXSpectrum;
    inline constexpr const newline& AppleII      = ZXSpectrum;
    inline constexpr const newline& Oberon       = ZXSpectrum;
    inline constexpr const newline& OS9          = ZXSpectrum;
    inline constexpr const newline& MacOS        = ZXSpectrum;
    inline constexpr const newline& LispMachine  = ZXSpectrum;

    inline constexpr newline QNX_PrePosix = "\x1E";

    inline constexpr newline AcornBBC_Spooled = "\n\r";
    inline constexpr const newline& RISCOS_Spooled = AcornBBC_Spooled;

    inline constexpr newline Atari8 = "\x9B";

    inline constexpr newline EBCDIC = "\x15";
    inline constexpr const newline& OS390 = EBCDIC;
    inline constexpr const newline& zOS   = EBCDIC;
    inline constexpr const newline& OS400 = EBCDIC;
    inline constexpr const newline& i5OS  = EBCDIC;
}
