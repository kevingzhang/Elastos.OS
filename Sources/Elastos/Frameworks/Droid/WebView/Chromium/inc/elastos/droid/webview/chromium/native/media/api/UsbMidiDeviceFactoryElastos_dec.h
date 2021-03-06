//=========================================================================
// Copyright (C) 2012 The Elastos Open Source Project
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//=========================================================================

//This file is autogenerated for
//    UsbMidiDeviceFactoryAndroid.java
//put this file at the end of the include list
//so the type definition used in this file will be found
#ifndef ELASTOS_USBMIDIDEVICEFACTORYANDROID_CALLBACK_DEC_HH
#define ELASTOS_USBMIDIDEVICEFACTORYANDROID_CALLBACK_DEC_HH


#ifdef __cplusplus
extern "C"
{
#endif
    extern void Elastos_UsbMidiDeviceFactoryAndroid_nativeOnUsbMidiDeviceRequestDone(Handle64 nativeUsbMidiDeviceFactoryAndroid,ArrayOf<IInterface*>* devices);
    extern void Elastos_UsbMidiDeviceFactoryAndroid_InitCallback(Handle64 cb);
#ifdef __cplusplus
}
#endif


namespace Elastos {
namespace Droid {
namespace Webkit {
namespace Webview {
namespace Chromium {
namespace Media {

struct ElaUsbMidiDeviceFactoryAndroidCallback
{
    AutoPtr<IInterface> (*elastos_UsbMidiDeviceFactoryAndroid_create)(Handle64 nativePointer);
    Boolean (*elastos_UsbMidiDeviceFactoryAndroid_enumerateDevices)(IInterface* obj, IInterface* context);
    void (*elastos_UsbMidiDeviceFactoryAndroid_close)(IInterface* obj);
};

void* UsbMidiDeviceFactoryElastos::ElaUsbMidiDeviceFactoryElastosCallback_Init()
{
    static ElaUsbMidiDeviceFactoryAndroidCallback sElaUsbMidiDeviceFactoryAndroidCallback;

    sElaUsbMidiDeviceFactoryAndroidCallback.elastos_UsbMidiDeviceFactoryAndroid_create = &UsbMidiDeviceFactoryElastos::Create;
    sElaUsbMidiDeviceFactoryAndroidCallback.elastos_UsbMidiDeviceFactoryAndroid_enumerateDevices = &UsbMidiDeviceFactoryElastos::EnumerateDevices;
    sElaUsbMidiDeviceFactoryAndroidCallback.elastos_UsbMidiDeviceFactoryAndroid_close = &UsbMidiDeviceFactoryElastos::Close;

    Elastos_UsbMidiDeviceFactoryAndroid_InitCallback((Handle64)&sElaUsbMidiDeviceFactoryAndroidCallback);
    return &sElaUsbMidiDeviceFactoryAndroidCallback;
}

static void* sPElaUsbMidiDeviceFactoryAndroidCallback = UsbMidiDeviceFactoryElastos::ElaUsbMidiDeviceFactoryElastosCallback_Init();

} // namespace Media
} // namespace Chromium
} // namespace Webview
} // namespace Webkit
} // namespace Droid
} // namespace Elastos

#endif //ELASTOS_USBMIDIDEVICEFACTORYANDROID_CALLBACK_DEC_HH
