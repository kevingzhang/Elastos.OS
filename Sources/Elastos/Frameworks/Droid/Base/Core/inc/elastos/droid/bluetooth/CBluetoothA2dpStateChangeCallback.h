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

#ifndef __ELASTOS_DROID_BLUETOOTH_CBLUETOOTHA2DOSTATECHANGECALLBACK_H__
#define __ELASTOS_DROID_BLUETOOTH_CBLUETOOTHA2DOSTATECHANGECALLBACK_H__

#include "_Elastos_Droid_Bluetooth_CBluetoothA2dpStateChangeCallback.h"
#include "Elastos.Droid.Bluetooth.h"
#include "Elastos.Droid.Os.h"
#include "elastos/droid/bluetooth/BluetoothA2dp.h"

using Elastos::Droid::Os::IBinder;

namespace Elastos {
namespace Droid {
namespace Bluetooth {

CarClass(CBluetoothA2dpStateChangeCallback)
    , public Object
    , public IIBluetoothStateChangeCallback
    , public IBinder
{
public:
    CAR_INTERFACE_DECL()

    CAR_OBJECT_DECL()

    CBluetoothA2dpStateChangeCallback();

    CARAPI constructor(
        /* [in] */ IInterface* host);

    CARAPI OnBluetoothStateChange(
        /* [in] */ Boolean on);

    CARAPI ToString(
        /* [out] */ String* info)
    {
        VALIDATE_NOT_NULL(info)
        return Object::ToString(info);
    }
private:
    BluetoothA2dp* mHost;
};

} // namespace Bluetooth
} // namespace Droid
} // namespace Elastos

#endif //__ELASTOS_DROID_BLUETOOTH_CBLUETOOTHA2DOSTATECHANGECALLBACK_H__
