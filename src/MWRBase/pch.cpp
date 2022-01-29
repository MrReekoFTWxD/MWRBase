// pch.cpp: source file corresponding to the pre-compiled header

#include "pch.h"

// When you are using pre-compiled headers, this source file is necessary for compilation to succeed.

__int64 ResolveImport(LPCWSTR Library)
{
    return (__int64)GetModuleHandle(Library);
}