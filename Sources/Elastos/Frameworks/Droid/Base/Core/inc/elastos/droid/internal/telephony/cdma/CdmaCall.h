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

#ifndef __ELASTOS_DROID_INTERNAL_TELEPHONY_CDMA_CDMACALL_H__
#define __ELASTOS_DROID_INTERNAL_TELEPHONY_CDMA_CDMACALL_H__

#include "elastos/droid/ext/frameworkext.h"
#include "elastos/droid/internal/telephony/Call.h"

// import com.android.internal.telephony.CallStateException;

using Elastos::Droid::Internal::Telephony::Call;
using Elastos::Droid::Internal::Telephony::ICallState;
using Elastos::Droid::Internal::Telephony::IPhone;
using Elastos::Droid::Internal::Telephony::IConnection;
using Elastos::Droid::Internal::Telephony::IDriverCall;
using Elastos::Utility::IList;

namespace Elastos {
namespace Droid {
namespace Internal {
namespace Telephony {
namespace Cdma {

/**
  * {@hide}
  */
class CdmaCall
    : public Call
    , public ICdmaCall
{
public:
    CAR_INTERFACE_DECL();

    CdmaCall();
    /****************************** Constructors *****************************/
    /*package*/
    CARAPI constructor(
        /* [in] */ ICdmaCallTracker* owner);

    virtual CARAPI Dispose();

    /************************** Overridden from Call *************************/
    // @Override // IConnection
    CARAPI GetConnections(
        /* [out] */ IList** result);

    // @Override
    CARAPI GetPhone(
        /* [out] */ IPhone** result);

    // @Override
    CARAPI IsMultiparty(
        /* [out] */ Boolean* resutl);

    /** Please note: if this is the foreground call and a
      *  background call exists, the background call will be resumed
      *  because an AT+CHLD=1 will be sent
      */
    // @Override
    CARAPI Hangup();

    // @Override
    CARAPI ToString(
        /* [out] */ String* result);

    //***** Called from CdmaConnection
    /*package*/
    virtual CARAPI Attach(
        /* [in] */ IConnection* conn,
        /* [in] */ IDriverCall* dc);

    /*package*/
    virtual CARAPI AttachFake(
        /* [in] */ IConnection* conn,
        /* [in] */ ICallState state);

    /**
      * Called by CdmaConnection when it has disconnected
      */
    virtual CARAPI ConnectionDisconnected(
        /* [in] */ ICdmaConnection* conn,
        /* [out] */ Boolean* result);

    /*package*/
    virtual CARAPI Detach(
        /* [in] */ ICdmaConnection* conn);

    /*package*/
    virtual CARAPI Update(
        /* [in] */ ICdmaConnection* conn,
        /* [in] */ IDriverCall* dc,
        /* [out] */ Boolean* result);

    /**
      * @return true if there's no space in this call for additional
      * connections to be added via "conference"
      */
    /*package*/
    virtual CARAPI IsFull(
        /* [out] */ Boolean* result);

    //***** Called from CdmaCallTracker
    /**
      * Called when this Call is being hung up locally (eg, user pressed "end")
      * Note that at this point, the hangup request has been dispatched to the radio
      * but no response has yet been received so update() has not yet been called
      */
    virtual CARAPI OnHangupLocal();

    /**
      * Called when it's time to clean up disconnected Connection objects
      */
    virtual CARAPI ClearDisconnected();

public:
    /*************************** Instance Variables **************************/
    /*package*/
    AutoPtr<ICdmaCallTracker> mOwner;
};

} // namespace Cdma
} // namespace Telephony
} // namespace Internal
} // namespace Droid
} // namespace Elastos

#endif // __ELASTOS_DROID_INTERNAL_TELEPHONY_CDMA_CDMACALL_H__

