// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file is autogenerated by
//     api_generator
// For
//     org/chromium/base/PowerMonitor

#ifndef ELASTOS_ORG_CHROMIUM_BASE_POWERMONITOR_JNI
#define ELASTOS_ORG_CHROMIUM_BASE_POWERMONITOR_JNI

//#include <jni.h>

#include "ElAndroid.h"
#include "elastos.h"
#include "base/logging.h"

//#include "base/android/jni_int_wrapper.h"

// Step 1: forward declarations.

namespace base {
namespace android {

extern "C" {

static void OnBatteryChargingChanged();

__attribute__((visibility("default")))
void Elastos_PowerMonitor_nativeOnBatteryChargingChanged() {
    return OnBatteryChargingChanged();
}

static void OnMainActivitySuspended();

__attribute__((visibility("default")))
void Elastos_PowerMonitor_nativeOnMainActivitySuspended() {
    return OnMainActivitySuspended();
}

static void OnMainActivityResumed();

__attribute__((visibility("default")))
void Elastos_PowerMonitor_nativeOnMainActivityResumed() {
    return OnMainActivityResumed();
}

};  // extern "C"

// Step 2: method stubs.

// Step 3: Callback init .
struct ElaPowerMonitorCallback
{
    Elastos::Boolean (*elastos_PowerMonitor_isBatteryPower)();
};

extern "C" {
static struct ElaPowerMonitorCallback* sElaPowerMonitorCallback;
__attribute__((visibility("default")))
void Elastos_PowerMonitor_InitCallback(Elastos::Handle32 cb)
{
    sElaPowerMonitorCallback = (struct ElaPowerMonitorCallback*)cb;
    DLOG(INFO) << "init pointer for sElaPowerMonitorCallback is:" << sElaPowerMonitorCallback;
}
}; // extern "C"

static bool RegisterNativesImpl() {

  return true;
}

}  // namespace android
}  // namespace base

#endif  // ELASTOS_ORG_CHROMIUM_BASE_POWERMONITOR_JNI
