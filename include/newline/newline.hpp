#pragma once

#include "newline/defs.h"

namespace newline {
    NEWLINE_DEF(UnixNewline, "\n")
    NEWLINE_ALIAS(LinuxNewline,         UnixNewline)
    NEWLINE_ALIAS(MacOSNewline,         UnixNewline)
    NEWLINE_ALIAS(AIXNewline,           UnixNewline)
    NEWLINE_ALIAS(HPUXNewline,          UnixNewline)
    NEWLINE_ALIAS(SunOSNewline,         UnixNewline)
    NEWLINE_ALIAS(SolarisNewline,       UnixNewline)
    NEWLINE_ALIAS(FreeBSDNewline,       UnixNewline)
    NEWLINE_ALIAS(OpenBSDNewline,       UnixNewline)
    NEWLINE_ALIAS(NetBSDNewline,        UnixNewline)
    NEWLINE_ALIAS(BeOSNewline,          UnixNewline)
    NEWLINE_ALIAS(AmigaNewline,         UnixNewline)
    NEWLINE_ALIAS(RISCOSNewline,        UnixNewline)
    NEWLINE_ALIAS(QNXNewline,           UnixNewline)

    NEWLINE_DEF(WindowsNewline, "\r\n")
    NEWLINE_ALIAS(DOSNewline,           WindowsNewline)
    NEWLINE_ALIAS(OS2Newline,           WindowsNewline)
    NEWLINE_ALIAS(AtariTOSNewline,      WindowsNewline)
    NEWLINE_ALIAS(CPMNewline,           WindowsNewline)
    NEWLINE_ALIAS(TOPS10Newline,        WindowsNewline)
    NEWLINE_ALIAS(RT11Newline,          WindowsNewline)
    NEWLINE_ALIAS(SymbianOSNewline,     WindowsNewline)
    NEWLINE_ALIAS(PalmOSNewline,        WindowsNewline)

    NEWLINE_DEF(ZXSpectrumNewline, "\r")
    NEWLINE_ALIAS(Commodore64Newline,   ZXSpectrumNewline)
    NEWLINE_ALIAS(C64Newline,           ZXSpectrumNewline)
    NEWLINE_ALIAS(Commodore128Newline,  ZXSpectrumNewline)
    NEWLINE_ALIAS(C128Newline,          ZXSpectrumNewline)
    NEWLINE_ALIAS(AcornBBCNewline,      ZXSpectrumNewline)
    NEWLINE_ALIAS(TRS80Newline,         ZXSpectrumNewline)
    NEWLINE_ALIAS(AppleIINewline,       ZXSpectrumNewline)
    NEWLINE_ALIAS(OberonNewline,        ZXSpectrumNewline)
    NEWLINE_ALIAS(OS9Newline,           ZXSpectrumNewline)

    NEWLINE_DEF(QNXPrePosixNewline, "\x1E")

    NEWLINE_DEF(AcornBBCSpooledNewline, "\n\r")
    NEWLINE_ALIAS(RISCOSSpooledNewline, AcornBBCSpooledNewline)

    NEWLINE_DEF(Atari8Newline, "\x9B")

    NEWLINE_DEF(EBCDICNewline, "\x15")
    NEWLINE_ALIAS(OS390Newline,         EBCDICNewline)
    NEWLINE_ALIAS(ZOSNewline,           EBCDICNewline)
    NEWLINE_ALIAS(OS400Newline,         EBCDICNewline)
    NEWLINE_ALIAS(I5OSNewline,          EBCDICNewline)
}

