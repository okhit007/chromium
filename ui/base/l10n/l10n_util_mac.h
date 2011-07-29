// Copyright (c) 2011 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef UI_BASE_L10N_L10N_UTIL_MAC_H_
#define UI_BASE_L10N_L10N_UTIL_MAC_H_
#pragma once

#include <string>
#include <vector>

#include "base/basictypes.h"
#include "base/string16.h"
#include "ui/ui_api.h"

#ifdef __OBJC__
@class NSString;
#else
class NSString;
#endif

namespace l10n_util {

// Remove the Windows-style accelerator marker (for labels, menuitems, etc.)
// and change "..." into an ellipsis.
// Returns the result in an autoreleased NSString.
UI_API NSString* FixUpWindowsStyleLabel(const string16& label);

// Pulls resource string from the string bundle and returns it.
UI_API NSString* GetNSString(int message_id);

// Get a resource string and replace $1-$2-$3 with |a| and |b|
// respectively.  Additionally, $$ is replaced by $.
UI_API NSString* GetNSStringF(int message_id,
                              const string16& a);
UI_API NSString* GetNSStringF(int message_id,
                              const string16& a,
                              const string16& b);
UI_API NSString* GetNSStringF(int message_id,
                              const string16& a,
                              const string16& b,
                              const string16& c);
UI_API NSString* GetNSStringF(int message_id,
                              const string16& a,
                              const string16& b,
                              const string16& c,
                              const string16& d);

// Variants that return the offset(s) of the replaced parameters. (See
// app/l10n_util.h for more details.)
UI_API NSString* GetNSStringF(int message_id,
                              const string16& a,
                              const string16& b,
                              std::vector<size_t>* offsets);

// Same as GetNSString, but runs the result through FixUpWindowsStyleLabel
// before returning it.
UI_API NSString* GetNSStringWithFixup(int message_id);

// Same as GetNSStringF, but runs the result through FixUpWindowsStyleLabel
// before returning it.
UI_API NSString* GetNSStringFWithFixup(int message_id,
                                       const string16& a);
UI_API NSString* GetNSStringFWithFixup(int message_id,
                                       const string16& a,
                                       const string16& b);
UI_API NSString* GetNSStringFWithFixup(int message_id,
                                       const string16& a,
                                       const string16& b,
                                       const string16& c);
UI_API NSString* GetNSStringFWithFixup(int message_id,
                                       const string16& a,
                                       const string16& b,
                                       const string16& c,
                                       const string16& d);

// Support the override of the locale with the value from Cocoa.
UI_API void OverrideLocaleWithCocoaLocale();
UI_API const std::string& GetLocaleOverride();

}  // namespace l10n_util

#endif  // UI_BASE_L10N_L10N_UTIL_MAC_H_
