/**************************************************************************/
/*  version.h                                                             */
/**************************************************************************/
/*                         This file is part of:                          */
/*                             GODOT ENGINE                               */
/*                        https://godotengine.org                         */
/**************************************************************************/
/* Copyright (c) 2014-present Godot Engine contributors (see AUTHORS.md). */
/* Copyright (c) 2007-2014 Juan Linietsky, Ariel Manzur.                  */
/*                                                                        */
/* Permission is hereby granted, free of charge, to any person obtaining  */
/* a copy of this software and associated documentation files (the        */
/* "Software"), to deal in the Software without restriction, including    */
/* without limitation the rights to use, copy, modify, merge, publish,    */
/* distribute, sublicense, and/or sell copies of the Software, and to     */
/* permit persons to whom the Software is furnished to do so, subject to  */
/* the following conditions:                                              */
/*                                                                        */
/* The above copyright notice and this permission notice shall be         */
/* included in all copies or substantial portions of the Software.        */
/*                                                                        */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,        */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF     */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. */
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY   */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,   */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE      */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                 */
/**************************************************************************/

#pragma once

#include "core/version_generated.gen.h" // IWYU pragma: export

#include <stdint.h> // NOLINT(modernize-deprecated-headers) FIXME: MinGW compilation fails when changing to C++ Header.

// Copied from typedefs.h to stay lean.
#ifndef _STR
#define _STR(m_x) #m_x
#define _MKSTR(m_x) _STR(m_x)
#endif

// Feral versions are of the form <major>.<minor> for the initial release,
// and then <major>.<minor>.<patch> for subsequent bugfix releases where <patch> != 0
// That's arbitrary, but we find it pretty and it's the current policy.

// Defines the main "branch" version. Patch versions in this branch should be
// forward-compatible.
// Example: "3.1"
#define FERAL_VERSION_BRANCH _MKSTR(FERAL_VERSION_MAJOR) "." _MKSTR(FERAL_VERSION_MINOR)
#if FERAL_VERSION_PATCH
// Example: "3.1.4"
#define FERAL_VERSION_NUMBER FERAL_VERSION_BRANCH "." _MKSTR(FERAL_VERSION_PATCH)
#else // patch is 0, we don't include it in the "pretty" version number.
// Example: "3.1" instead of "3.1.0"
#define FERAL_VERSION_NUMBER FERAL_VERSION_BRANCH
#endif // FERAL_VERSION_PATCH

#define GODOT_VERSION_BRANCH _MKSTR(GODOT_VERSION_MAJOR) "." _MKSTR(GODOT_VERSION_MINOR)
#if GODOT_VERSION_PATCH
// Example: "3.1.4"
#define GODOT_VERSION_NUMBER GODOT_VERSION_BRANCH "." _MKSTR(GODOT_VERSION_PATCH)
#else // patch is 0, we don't include it in the "pretty" version number.
#define GODOT_VERSION_NUMBER GODOT_VERSION_BRANCH
#endif // GODOT_VERSION_PATCH

// Version number encoded as hexadecimal int with one byte for each number,
// for easy comparison from code.
// Example: 3.1.4 will be 0x030104, making comparison easy from script.
#define FERAL_VERSION_HEX 0x10000 * FERAL_VERSION_MAJOR + 0x100 * FERAL_VERSION_MINOR + FERAL_VERSION_PATCH

// Describes the full configuration of that Godot version, including the version number,
// the status (beta, stable, etc.), potential module-specific features (e.g. mono)
// and double-precision status.
// Example: "3.1.4.stable.mono.double"
#ifdef REAL_T_IS_DOUBLE
#if FERAL_VERSION_STATUS_VERSION == 0
#define FERAL_VERSION_FULL_CONFIG FERAL_VERSION_NUMBER "." FERAL_VERSION_STATUS FERAL_VERSION_MODULE_CONFIG ".double"
#else
#define FERAL_VERSION_FULL_CONFIG FERAL_VERSION_NUMBER "." FERAL_VERSION_STATUS "." _MKSTR(FERAL_VERSION_STATUS_VERSION) FERAL_VERSION_MODULE_CONFIG ".double"
#endif
#else
#if FERAL_VERSION_STATUS_VERSION == 0
#define FERAL_VERSION_FULL_CONFIG FERAL_VERSION_NUMBER "." FERAL_VERSION_STATUS FERAL_VERSION_MODULE_CONFIG
#else
#define FERAL_VERSION_FULL_CONFIG FERAL_VERSION_NUMBER "." FERAL_VERSION_STATUS "." _MKSTR(FERAL_VERSION_STATUS_VERSION) FERAL_VERSION_MODULE_CONFIG
#endif
#endif

#define GODOT_VERSION_FULL_CONFIG GODOT_VERSION_NUMBER "." GODOT_VERSION_STATUS FERAL_VERSION_MODULE_CONFIG

// Similar to FERAL_VERSION_FULL_CONFIG, but also includes the (potentially custom) FERAL_VERSION_BUILD
// description (e.g. official, custom_build, etc.).
// Example: "3.1.4.stable.mono.double.official"
#define FERAL_VERSION_FULL_BUILD FERAL_VERSION_FULL_CONFIG "." FERAL_VERSION_BUILD

#define GODOT_VERSION_BUILD "feral." FERAL_VERSION_BUILD
#define GODOT_VERSION_FULL_BUILD GODOT_VERSION_FULL_CONFIG "." GODOT_VERSION_BUILD

// Same as above, but prepended with FERAL's name and a cosmetic "v" for "version".
// Example: "FERAL v3.1.4.stable.official.mono"
#define FERAL_VERSION_FULL_NAME FERAL_VERSION_NAME " v" FERAL_VERSION_FULL_BUILD

#define GODOT_VERSION_NAME "Feral Engine"
#define GODOT_VERSION_FULL_NAME GODOT_VERSION_NAME " v" GODOT_VERSION_FULL_BUILD

// Git commit hash, generated at build time in `core/version_hash.gen.cpp`.
extern const char *const FERAL_VERSION_HASH;

// Git commit date UNIX timestamp (in seconds), generated at build time in `core/version_hash.gen.cpp`.
// Set to 0 if unknown.
extern const uint64_t FERAL_VERSION_TIMESTAMP;

// Defines the main "branch" version. Patch versions in this branch should be
// forward-compatible.
// Example: "3.1"
#define GODOT_VERSION_BRANCH _MKSTR(GODOT_VERSION_MAJOR) "." _MKSTR(GODOT_VERSION_MINOR)
#if GODOT_VERSION_PATCH
// Example: "3.1.4"
#define GODOT_VERSION_NUMBER GODOT_VERSION_BRANCH "." _MKSTR(GODOT_VERSION_PATCH)
#else // patch is 0, we don't include it in the "pretty" version number.
// Example: "3.1" instead of "3.1.0"
#define GODOT_VERSION_NUMBER GODOT_VERSION_BRANCH
#endif // GODOT_VERSION_PATCH

// Version number encoded as hexadecimal int with one byte for each number,
// for easy comparison from code.
// Example: 3.1.4 will be 0x030104, making comparison easy from script.
#define GODOT_VERSION_HEX 0x10000 * GODOT_VERSION_MAJOR + 0x100 * GODOT_VERSION_MINOR + GODOT_VERSION_PATCH

// TODO: determine how to deal with godot compatible versioning behavior

// Git commit hash, generated at build time in `core/version_hash.gen.cpp`.
// extern const char *const GODOT_VERSION_HASH;

// Git commit date UNIX timestamp (in seconds), generated at build time in `core/version_hash.gen.cpp`.
// Set to 0 if unknown.
// extern const uint64_t GODOT_VERSION_TIMESTAMP;

#ifndef DISABLE_DEPRECATED
// Compatibility with pre-4.5 modules.
#define VERSION_SHORT_NAME FERAL_VERSION_SHORT_NAME
#define VERSION_NAME FERAL_VERSION_NAME
#define VERSION_MAJOR FERAL_VERSION_MAJOR
#define VERSION_MINOR FERAL_VERSION_MINOR
#define VERSION_PATCH FERAL_VERSION_PATCH
#define VERSION_STATUS FERAL_VERSION_STATUS
#define VERSION_BUILD FERAL_VERSION_BUILD
#define VERSION_MODULE_CONFIG FERAL_VERSION_MODULE_CONFIG
#define VERSION_WEBSITE FERAL_VERSION_WEBSITE
#define VERSION_DOCS_BRANCH FERAL_VERSION_DOCS_BRANCH
#define VERSION_DOCS_URL FERAL_VERSION_DOCS_URL
#define VERSION_BRANCH FERAL_VERSION_BRANCH
#define VERSION_NUMBER FERAL_VERSION_NUMBER
#define VERSION_HEX FERAL_VERSION_HEX
#define VERSION_FULL_CONFIG FERAL_VERSION_FULL_CONFIG
#define VERSION_FULL_BUILD FERAL_VERSION_FULL_BUILD
#define VERSION_FULL_NAME FERAL_VERSION_FULL_NAME
#define VERSION_HASH FERAL_VERSION_HASH
#define VERSION_TIMESTAMP FERAL_VERSION_TIMESTAMP
#endif // DISABLE_DEPRECATED
