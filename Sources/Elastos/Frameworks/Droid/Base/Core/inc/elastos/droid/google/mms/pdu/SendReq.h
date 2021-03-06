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

#ifndef __ELASTOS_DROID_GOOGLE_MMS_PDU_SENDREQ_H__
#define __ELASTOS_DROID_GOOGLE_MMS_PDU_SENDREQ_H__

#include "elastos/droid/ext/frameworkext.h"
#include "elastos/droid/google/mms/pdu/MultimediaMessagePdu.h"

namespace Elastos {
namespace Droid {
namespace Google {
namespace Mms {
namespace Pdu {

class SendReq
    : public MultimediaMessagePdu
    , public ISendReq
{
public:
    CAR_INTERFACE_DECL();

    SendReq();

    CARAPI constructor();

    /**
      * Constructor, used when composing a M-Send.req pdu.
      *
      * @param contentType the content type value
      * @param from the from value
      * @param mmsVersion current viersion of mms
      * @param transactionId the transaction-id value
      * @throws InvalidHeaderValueException if parameters are invalid.
      *         NullPointerException if contentType, form or transactionId is null.
      */
    CARAPI constructor(
        /* [in] */ ArrayOf<Byte>* contentType,
        /* [in] */ IEncodedStringValue* from,
        /* [in] */ Int32 mmsVersion,
        /* [in] */ ArrayOf<Byte>* transactionId);

    /**
      * Constructor with given headers.
      *
      * @param headers Headers for this PDU.
      */
    CARAPI constructor(
        /* [in] */ IPduHeaders* headers);

    /**
      * Constructor with given headers and body
      *
      * @param headers Headers for this PDU.
      * @param body Body of this PDu.
      */
    CARAPI constructor(
        /* [in] */ IPduHeaders* headers,
        /* [in] */ IPduBody* body);

    /**
      * Get Bcc value.
      *
      * @return the value
      */
    virtual CARAPI GetBcc(
        /* [out] */ ArrayOf<IEncodedStringValue*>** result);

    /**
      * Add a "BCC" value.
      *
      * @param value the value
      * @throws NullPointerException if the value is null.
      */
    virtual CARAPI AddBcc(
        /* [in] */ IEncodedStringValue* value);

    /**
      * Set "BCC" value.
      *
      * @param value the value
      * @throws NullPointerException if the value is null.
      */
    virtual CARAPI SetBcc(
        /* [in] */ ArrayOf<IEncodedStringValue*>* value);

    /**
      * Get CC value.
      *
      * @return the value
      */
    virtual CARAPI GetCc(
        /* [out] */ ArrayOf<IEncodedStringValue*>** result);

    /**
      * Add a "CC" value.
      *
      * @param value the value
      * @throws NullPointerException if the value is null.
      */
    virtual CARAPI AddCc(
        /* [in] */ IEncodedStringValue* value);

    /**
      * Set "CC" value.
      *
      * @param value the value
      * @throws NullPointerException if the value is null.
      */
    virtual CARAPI SetCc(
        /* [in] */ ArrayOf<IEncodedStringValue*>* value);

    /**
      * Get Content-type value.
      *
      * @return the value
      */
    virtual CARAPI GetContentType(
        /* [out] */ ArrayOf<Byte>** result);

    /**
      * Set Content-type value.
      *
      * @param value the value
      * @throws NullPointerException if the value is null.
      */
    virtual CARAPI SetContentType(
        /* [in] */ ArrayOf<Byte>* value);

    /**
      * Get X-Mms-Delivery-Report value.
      *
      * @return the value
      */
    virtual CARAPI GetDeliveryReport(
        /* [out] */ Int32* result);

    /**
      * Set X-Mms-Delivery-Report value.
      *
      * @param value the value
      * @throws InvalidHeaderValueException if the value is invalid.
      */
    virtual CARAPI SetDeliveryReport(
        /* [in] */ Int32 value);

    /**
      * Get X-Mms-Expiry value.
      *
      * Expiry-value = Value-length
      *      (Absolute-token Date-value | Relative-token Delta-seconds-value)
      *
      * @return the value
      */
    virtual CARAPI GetExpiry(
        /* [out] */ Int64* result);

    /**
      * Set X-Mms-Expiry value.
      *
      * @param value the value
      */
    virtual CARAPI SetExpiry(
        /* [in] */ Int64 value);

    /**
      * Get X-Mms-MessageSize value.
      *
      * Expiry-value = size of message
      *
      * @return the value
      */
    virtual CARAPI GetMessageSize(
        /* [out] */ Int64* result);

    /**
      * Set X-Mms-MessageSize value.
      *
      * @param value the value
      */
    virtual CARAPI SetMessageSize(
        /* [in] */ Int64 value);

    /**
      * Get X-Mms-Message-Class value.
      * Message-class-value = Class-identifier | Token-text
      * Class-identifier = Personal | Advertisement | Informational | Auto
      *
      * @return the value
      */
    virtual CARAPI GetMessageClass(
        /* [out] */ ArrayOf<Byte>** result);

    /**
      * Set X-Mms-Message-Class value.
      *
      * @param value the value
      * @throws NullPointerException if the value is null.
      */
    virtual CARAPI SetMessageClass(
        /* [in] */ ArrayOf<Byte>* value);

    /**
      * Get X-Mms-Read-Report value.
      *
      * @return the value
      */
    virtual CARAPI GetReadReport(
        /* [out] */ Int32* result);

    /**
      * Set X-Mms-Read-Report value.
      *
      * @param value the value
      * @throws InvalidHeaderValueException if the value is invalid.
      */
    virtual CARAPI SetReadReport(
        /* [in] */ Int32 value);

    /**
      * Set "To" value.
      *
      * @param value the value
      * @throws NullPointerException if the value is null.
      */
    virtual CARAPI SetTo(
        /* [in] */ ArrayOf<IEncodedStringValue*>* value);

    /**
      * Get X-Mms-Transaction-Id field value.
      *
      * @return the X-Mms-Report-Allowed value
      */
    virtual CARAPI GetTransactionId(
        /* [out] */ ArrayOf<Byte>** result);

    /**
      * Set X-Mms-Transaction-Id field value.
      *
      * @param value the value
      * @throws NullPointerException if the value is null.
      */
    virtual CARAPI SetTransactionId(
        /* [in] */ ArrayOf<Byte>* value);

private:
    CARAPI_(AutoPtr<ArrayOf<Byte> >) GenerateTransactionId();

private:
    static const String TAG;
};

} // namespace Pdu
} // namespace Mms
} // namespace Google
} // namespace Droid
} // namespace Elastos

#endif // __ELASTOS_DROID_GOOGLE_MMS_PDU_SENDREQ_H__

