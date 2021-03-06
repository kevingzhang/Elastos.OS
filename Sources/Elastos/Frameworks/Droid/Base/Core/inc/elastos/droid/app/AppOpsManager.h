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

#ifndef __ELASTOS_DROID_APP_APP_OPS_MANAGER_H__
#define __ELASTOS_DROID_APP_APP_OPS_MANAGER_H__

#include "elastos/droid/ext/frameworkext.h"
#include "Elastos.Droid.App.h"
#define HASH_FOR_APP
#include "elastos/droid/ext/frameworkhash.h"
#include "elastos/core/Object.h"
#include "elastos/utility/etl/HashMap.h"

using Elastos::Droid::Content::IContext;
using Elastos::Droid::Os::IBinder;
using Elastos::Droid::Internal::App::IIAppOpsCallback;
using Elastos::Droid::Internal::App::IIAppOpsService;

using Elastos::Utility::IList;
using Elastos::Utility::IArrayList;
using Elastos::Utility::Etl::HashMap;

namespace Elastos {
namespace Droid {
namespace App {

/**
 * API for interacting with "application operation" tracking.
 *
 * <p>This API is not generally intended for third party application developers; most
 * features are only available to system applications.  Obtain an instance of it through
 * {@link Context#getSystemService(String) Context.getSystemService} with
 * {@link Context#APP_OPS_SERVICE Context.APP_OPS_SERVICE}.</p>
 */
class AppOpsManager
    : public Object
    , public IAppOpsManager
{
    /**
     * <p>App ops allows callers to:</p>
     *
     * <ul>
     * <li> Note when operations are happening, and find out if they are allowed for the current
     * caller.</li>
     * <li> Disallow specific apps from doing specific operations.</li>
     * <li> Collect all of the current information about operations that have been executed or
     * are not being allowed.</li>
     * <li> Monitor for changes in whether an operation is allowed.</li>
     * </ul>
     *
     * <p>Each operation is identified by a single integer; these integers are a fixed set of
     * operations, enumerated by the OP_* constants.
     *
     * <p></p>When checking operations, the result is a "mode" integer indicating the current
     * setting for the operation under that caller: MODE_ALLOWED, MODE_IGNORED (don't execute
     * the operation but fake its behavior enough so that the caller doesn't crash),
     * MODE_ERRORED (throw a SecurityException back to the caller; the normal operation calls
     * will do this for you).
     */

public:
    /**
     * Class holding all of the operation information associated with an app.
     * @hide
     */
    class PackageOps
        : public Object
        , public IAppOpsManagerPackageOps
        , public IParcelable
    {
    public:
        CAR_INTERFACE_DECL()

        PackageOps();

        virtual ~PackageOps();

        CARAPI constructor();

        CARAPI constructor(
            /* [in] */ const String& packageName,
            /* [in] */ Int32 uid,
            /* [in] */ IList* entries);

        CARAPI GetPackageName(
            /* [out] */ String* str);

        CARAPI GetUid(
            /* [out] */ Int32* uid);

        CARAPI GetOps(
            /* [out] */ IList** ops);

        CARAPI WriteToParcel(
            /* [in] */ IParcel* dest);

        CARAPI ReadFromParcel(
            /* [out] */ IParcel* source);

        CARAPI ToString(
            /* [out] */ String* str);
    private:
        String mPackageName;
        Int32 mUid;
        AutoPtr<IList> mEntries;//List<OpEntry>
    };

    /**
     * Class holding the information about one unique operation of an application.
     * @hide
     */
    class OpEntry
        : public Object
        , public IAppOpsManagerOpEntry
        , public IParcelable
    {
    public:
        CAR_INTERFACE_DECL()

        OpEntry();

        virtual ~OpEntry();

        CARAPI constructor();

        CARAPI constructor(
            /* [in] */ Int32 op,
            /* [in] */ Int32 mode,
            /* [in] */ Int32 time,
            /* [in] */ Int32 rejectTime,
            /* [in] */ Int32 duration,
            /* [in] */ Int32 allowedCount,
            /* [in] */ Int32 ignoredCount);

        CARAPI GetOp(
            /* [out] */ Int32* op);

        CARAPI GetMode(
            /* [out] */ Int32* mode);

        CARAPI GetTime(
            /* [out] */ Int64* time);

        CARAPI GetRejectTime(
            /* [out] */ Int64* time);

        CARAPI IsRunning(
            /* [out] */ Boolean* running);

        CARAPI GetDuration(
            /* [out] */ Int32* duration);

        CARAPI GetAllowedCount(
            /* [out] */ Int32* allowedCount);

        CARAPI GetIgnoredCount(
            /* [out] */ Int32* ignoredCount);

        CARAPI WriteToParcel(
            /* [in] */ IParcel* dest);

        CARAPI ReadFromParcel(
            /* [in] */ IParcel* source);

        CARAPI ToString(
            /* [out] */ String* str);
    private:
        Int32 mOp;
        Int32 mMode;
        Int64 mTime;
        Int64 mRejectTime;
        Int32 mDuration;
        Int32 mAllowedCount;
        Int32 mIgnoredCount;
    };

    /**
     * Callback for notification of changes to operation state.
     * This allows you to see the raw op codes instead of strings.
     * @hide
     */
    class OnOpChangedInternalListener
        : public Object
        , public IAppOpsManagerOnOpChangedInternalListener
        , public IAppOpsManagerOnOpChangedListener
    {
    public:
        CAR_INTERFACE_DECL()

        CARAPI OnOpChanged(
            /* [in] */ const String& op,
            /* [in] */ const String& packageName);

        CARAPI OnOpChanged(
            /* [in] */ Int32 op,
            /* [in] */ const String& packageName);

        CARAPI ToString(
            /* [out] */ String* str);
    };

public:
    CAR_INTERFACE_DECL()

    AppOpsManager();

    virtual ~AppOpsManager();

    CARAPI ToString(
        /* [out] */ String* str);

    /**
     * Retrieve the op switch that controls the given operation.
     * @hide
     */
    static Int32 OpToSwitch(
        /* [in] */ Int32 op);

    /**
     * Retrieve a non-localized name for the operation, for debugging output.
     * @hide
     */
    static String OpToName(
        /* [in] */ Int32 op);

    /**
     * Map a non-localized name for the operation back to the Op number
     * @hide
     */
    static Int32 NameToOp(
        /* [in] */ const String& name);

    /**
     * Retrieve the permission associated with an operation, or null if there is not one.
     * @hide
     */
    static String OpToPermission(
        /* [in] */ Int32 op);

    /**
     * Retrieve the user restriction associated with an operation, or null if there is not one.
     * @hide
     */
    static String OpToRestriction(
        /* [in] */ Int32 op);

    /**
     * Retrieve whether the op allows the system (and system ui) to
     * bypass the user restriction.
     * @hide
     */
    static Boolean OpAllowSystemBypassRestriction(
        /* [in] */ Int32 op);

    /**
     * Retrieve the default mode for the operation.
     * @hide
     */
    static Int32 OpToDefaultMode(
        /* [in] */ Int32 op,
        /* [in] */ Boolean isStrict);

    /**
     * Retrieve whether the op allows itself to be reset.
     * @hide
     */
    static Boolean OpAllowsReset(
        /* [in] */ Int32 op);

    CARAPI constructor(
        /* [in] */ IContext* context,
        /* [in] */ IIAppOpsService* service);

    /**
     * Retrieve current operation state for all applications.
     *
     * @param ops The set of operations you are interested in, or null if you want all of them.
     * @hide
     */
    CARAPI GetPackagesForOps(
        /* [in] */ ArrayOf<Int32>* ops,
        /* [out] */ IList** packages); //List<AppOpsManager.PackageOps>

    /**
     * Retrieve current operation state for one application.
     *
     * @param uid The uid of the application of interest.
     * @param packageName The name of the application of interest.
     * @param ops The set of operations you are interested in, or null if you want all of them.
     * @hide
     */
    CARAPI GetOpsForPackage(
        /* [in] */ Int32 uid,
        /* [in] */ const String& packageName,
        /* [in] */ ArrayOf<Int32>* ops,
        /* [out] */ IList** list); //List<AppOpsManager.PackageOps>

    /** @hide */
    CARAPI SetMode(
        /* [in] */ Int32 code,
        /* [in] */ Int32 uid,
        /* [in] */ const String& packageName,
        /* [in] */ Int32 mode);

    /**
     * Set a non-persisted restriction on an audio operation at a stream-level.
     * Restrictions are temporary additional constraints imposed on top of the persisted rules
     * defined by {@link #setMode}.
     *
     * @param code The operation to restrict.
     * @param usage The {@link android.media.AudioAttributes} usage value.
     * @param mode The restriction mode (MODE_IGNORED,MODE_ERRORED) or MODE_ALLOWED to unrestrict.
     * @param exceptionPackages Optional list of packages to exclude from the restriction.
     * @hide
     */
    CARAPI SetRestriction(
        /* [in] */ Int32 code,
        /* [in] */ Int32 usage,
        /* [in] */ Int32 mode,
        /* [in] */ ArrayOf<String>* exceptionPackages);

    /** @hide */
    CARAPI ResetAllModes();

    /**
     * Monitor for changes to the operating mode for the given op in the given app package.
     * @param op The operation to monitor, one of OPSTR_*.
     * @param packageName The name of the application to monitor.
     * @param callback Where to report changes.
     */
    CARAPI StartWatchingMode(
        /* [in] */ const String& op,
        /* [in] */ const String& packageName,
        /* [in] */ IAppOpsManagerOnOpChangedListener* callback);

    /**
     * Monitor for changes to the operating mode for the given op in the given app package.
     * @param op The operation to monitor, one of OP_*.
     * @param packageName The name of the application to monitor.
     * @param callback Where to report changes.
     * @hide
     */
    CARAPI StartWatchingMode(
        /* [in] */ Int32 op,
        /* [in] */ const String& packageName,
        /* [in] */ IAppOpsManagerOnOpChangedListener* callback);

    /**
     * Stop monitoring that was previously started with {@link #startWatchingMode}.  All
     * monitoring associated with this callback will be removed.
     */
    CARAPI StopWatchingMode(
        /* [in] */ IAppOpsManagerOnOpChangedListener* callback);

    /**
     * {@hide}
     */
    static CARAPI StrOpToOp(
        /* [in] */ const String& op,
        /* [out] */ Int32* result);

    /**
     * Do a quick check for whether an application might be able to perform an operation.
     * This is <em>not</em> a security check; you must use {@link #noteOp(String, Int32, String)}
     * or {@link #startOp(String, Int32, String)} for your actual security checks, which also
     * ensure that the given uid and package name are consistent.  This function can just be
     * used for a quick check to see if an operation has been disabled for the application,
     * as an early reject of some work.  This does not modify the time stamp or other data
     * about the operation.
     * @param op The operation to check.  One of the OPSTR_* constants.
     * @param uid The user id of the application attempting to perform the operation.
     * @param packageName The name of the application attempting to perform the operation.
     * @return Returns {@link #MODE_ALLOWED} if the operation is allowed, or
     * {@link #MODE_IGNORED} if it is not allowed and should be silently ignored (without
     * causing the app to crash).
     * @throws SecurityException If the app has been configured to crash on this op.
     */
    CARAPI CheckOp(
        /* [in] */ const String& op,
        /* [in] */ Int32 uid,
        /* [in] */ const String& packageName,
        /* [out] */ Int32* result);

    /**
     * Like {@link #checkOp} but instead of throwing a {@link SecurityException} it
     * returns {@link #MODE_ERRORED}.
     */
    CARAPI CheckOpNoThrow(
        /* [in] */ const String& op,
        /* [in] */ Int32 uid,
        /* [in] */ const String& packageName,
        /* [out] */ Int32* result);

    /**
     * Make note of an application performing an operation.  Note that you must pass
     * in both the uid and name of the application to be checked; this function will verify
     * that these two match, and if not, return {@link #MODE_IGNORED}.  If this call
     * succeeds, the last execution time of the operation for this app will be updated to
     * the current time.
     * @param op The operation to note.  One of the OPSTR_* constants.
     * @param uid The user id of the application attempting to perform the operation.
     * @param packageName The name of the application attempting to perform the operation.
     * @return Returns {@link #MODE_ALLOWED} if the operation is allowed, or
     * {@link #MODE_IGNORED} if it is not allowed and should be silently ignored (without
     * causing the app to crash).
     * @throws SecurityException If the app has been configured to crash on this op.
     */
    CARAPI NoteOp(
        /* [in] */ const String& op,
        /* [in] */ Int32 uid,
        /* [in] */ const String& packageName,
        /* [out] */ Int32* result);

    /**
     * Like {@link #noteOp} but instead of throwing a {@link SecurityException} it
     * returns {@link #MODE_ERRORED}.
     */
    CARAPI NoteOpNoThrow(
        /* [in] */ const String& op,
        /* [in] */ Int32 uid,
        /* [in] */ const String& packageName,
        /* [out] */ Int32* result);

    /**
     * Report that an application has started executing a long-running operation.  Note that you
     * must pass in both the uid and name of the application to be checked; this function will
     * verify that these two match, and if not, return {@link #MODE_IGNORED}.  If this call
     * succeeds, the last execution time of the operation for this app will be updated to
     * the current time and the operation will be marked as "running".  In this case you must
     * later call {@link #FinishOp(String, Int32, String)} to report when the application is no
     * longer performing the operation.
     * @param op The operation to start.  One of the OPSTR_* constants.
     * @param uid The user id of the application attempting to perform the operation.
     * @param packageName The name of the application attempting to perform the operation.
     * @return Returns {@link #MODE_ALLOWED} if the operation is allowed, or
     * {@link #MODE_IGNORED} if it is not allowed and should be silently ignored (without
     * causing the app to crash).
     * @throws SecurityException If the app has been configured to crash on this op.
     */
    CARAPI StartOp(
        /* [in] */ const String& op,
        /* [in] */ Int32 uid,
        /* [in] */ const String& packageName,
        /* [out] */ Int32* result);

    /**
     * Like {@link #startOp} but instead of throwing a {@link SecurityException} it
     * returns {@link #MODE_ERRORED}.
     */
    CARAPI StartOpNoThrow(
        /* [in] */ const String& op,
        /* [in] */ Int32 uid,
        /* [in] */ const String& packageName,
        /* [out] */ Int32* result);

    /**
     * Report that an application is no longer performing an operation that had previously
     * been started with {@link #startOp(String, Int32, String)}.  There is no validation of input
     * or result; the parameters supplied here must be the exact same ones previously passed
     * in when starting the operation.
     */
    CARAPI FinishOp(
        /* [in] */ const String& op,
        /* [in] */ Int32 uid,
        /* [in] */ const String& packageName);

    static CARAPI_(Boolean) IsStrictEnable();

    /**
     * Do a quick check for whether an application might be able to perform an operation.
     * This is <em>not</em> a security check; you must use {@link #noteOp(Int32, Int32, String)}
     * or {@link #startOp(Int32, Int32, String)} for your actual security checks, which also
     * ensure that the given uid and package name are consistent.  This function can just be
     * used for a quick check to see if an operation has been disabled for the application,
     * as an early reject of some work.  This does not modify the time stamp or other data
     * about the operation.
     * @param op The operation to check.  One of the OP_* constants.
     * @param uid The user id of the application attempting to perform the operation.
     * @param packageName The name of the application attempting to perform the operation.
     * @return Returns {@link #MODE_ALLOWED} if the operation is allowed, or
     * {@link #MODE_IGNORED} if it is not allowed and should be silently ignored (without
     * causing the app to crash).
     * @throws SecurityException If the app has been configured to crash on this op.
     * @hide
     */
    CARAPI CheckOp(
        /* [in] */ Int32 op,
        /* [in] */ Int32 uid,
        /* [in] */ const String& packageName,
        /* [out] */ Int32* result);

    /**
     * Like {@link #checkOp} but instead of throwing a {@link SecurityException} it
     * returns {@link #MODE_ERRORED}.
     * @hide
     */
    CARAPI CheckOpNoThrow(
        /* [in] */ Int32 op,
        /* [in] */ Int32 uid,
        /* [in] */ const String& packageName,
        /* [out] */ Int32* result);

    /**
     * Do a quick check to validate if a package name belongs to a UID.
     *
     * @throws SecurityException if the package name doesn't belong to the given
     *             UID, or if ownership cannot be verified.
     */
    CARAPI CheckPackage(
        /* [in] */ Int32 uid,
        /* [in] */ const String& packageName);

    /**
     * Like {@link #checkOp} but at a stream-level for audio operations.
     * @hide
     */
    CARAPI CheckAudioOp(
        /* [in] */ Int32 op,
        /* [in] */ Int32 stream,
        /* [in] */ Int32 uid,
        /* [in] */ const String& packageName,
        /* [out] */ Int32* result);

    /**
     * Like {@link #checkAudioOp} but instead of throwing a {@link SecurityException} it
     * returns {@link #MODE_ERRORED}.
     * @hide
     */
    CARAPI CheckAudioOpNoThrow(
        /* [in] */ Int32 op,
        /* [in] */ Int32 stream,
        /* [in] */ Int32 uid,
        /* [in] */ const String& packageName,
        /* [out] */ Int32* result);

    /**
     * Make note of an application performing an operation.  Note that you must pass
     * in both the uid and name of the application to be checked; this function will verify
     * that these two match, and if not, return {@link #MODE_IGNORED}.  If this call
     * succeeds, the last execution time of the operation for this app will be updated to
     * the current time.
     * @param op The operation to note.  One of the OP_* constants.
     * @param uid The user id of the application attempting to perform the operation.
     * @param packageName The name of the application attempting to perform the operation.
     * @return Returns {@link #MODE_ALLOWED} if the operation is allowed, or
     * {@link #MODE_IGNORED} if it is not allowed and should be silently ignored (without
     * causing the app to crash).
     * @throws SecurityException If the app has been configured to crash on this op.
     * @hide
     */
    CARAPI NoteOp(
        /* [in] */ Int32 op,
        /* [in] */ Int32 uid,
        /* [in] */ const String& packageName,
        /* [out] */ Int32* result);

    /**
     * Like {@link #noteOp} but instead of throwing a {@link SecurityException} it
     * returns {@link #MODE_ERRORED}.
     * @hide
     */
    CARAPI NoteOpNoThrow(
        /* [in] */ Int32 op,
        /* [in] */ Int32 uid,
        /* [in] */ const String& packageName,
        /* [out] */ Int32* result);

    /** @hide */
    CARAPI NoteOp(
        /* [in] */ Int32 op,
        /* [out] */ Int32* result);

    /** @hide */
    static CARAPI GetToken(
        /* [in] */ IIAppOpsService* service,
        /* [out] */ IBinder** binder);

    /**
     * Report that an application has started executing a long-running operation.  Note that you
     * must pass in both the uid and name of the application to be checked; this function will
     * verify that these two match, and if not, return {@link #MODE_IGNORED}.  If this call
     * succeeds, the last execution time of the operation for this app will be updated to
     * the current time and the operation will be marked as "running".  In this case you must
     * later call {@link #FinishOp(Int32, Int32, String)} to report when the application is no
     * longer performing the operation.
     * @param op The operation to start.  One of the OP_* constants.
     * @param uid The user id of the application attempting to perform the operation.
     * @param packageName The name of the application attempting to perform the operation.
     * @return Returns {@link #MODE_ALLOWED} if the operation is allowed, or
     * {@link #MODE_IGNORED} if it is not allowed and should be silently ignored (without
     * causing the app to crash).
     * @throws SecurityException If the app has been configured to crash on this op.
     * @hide
     */
    CARAPI StartOp(
        /* [in] */ Int32 op,
        /* [in] */ Int32 uid,
        /* [in] */ const String& packageName,
        /* [out] */ Int32* result);

    /**
     * Like {@link #startOp} but instead of throwing a {@link SecurityException} it
     * returns {@link #MODE_ERRORED}.
     * @hide
     */
    CARAPI StartOpNoThrow(
        /* [in] */ Int32 op,
        /* [in] */ Int32 uid,
        /* [in] */ const String& packageName,
        /* [out] */ Int32* result);

    /** @hide */
    CARAPI StartOp(
        /* [in] */ Int32 op,
        /* [out] */ Int32* result);

    /**
     * Report that an application is no longer performing an operation that had previously
     * been started with {@link #startOp(Int32, Int32, String)}.  There is no validation of input
     * or result; the parameters supplied here must be the exact same ones previously passed
     * in when starting the operation.
     * @hide
     */
    CARAPI FinishOp(
        /* [in] */ Int32 op,
        /* [in] */ Int32 uid,
        /* [in] */ const String& packageName);

    /** @hide */
    CARAPI FinishOp(
        /* [in] */ Int32 op);

    /** @hide */
    CARAPI IsControlAllowed(
        /* [in] */ Int32 op,
        /* [in] */ const String& packageName,
        /* [out] */ Boolean* result);

    /** @hide */
    CARAPI GetPrivacyGuardSettingForPackage(
        /* [in] */ Int32 uid,
        /* [in] */ const String& packageName,
        /* [out] */ Boolean* state);

    /** @hide */
    CARAPI SetPrivacyGuardSettingForPackage(
        /* [in] */ Int32 uid,
        /* [in] */ const String& packageName,
        /* [in] */ Boolean state);

    /** @hide */
    CARAPI ResetCounters();

    /**
     * Check if op in strict mode
     * @hide
     */
    static CARAPI_(Boolean) IsStrictOp(
        /* [in] */ Int32 code);


    /** @hide */
    static CARAPI_(Int32) StringToMode(
        /* [in] */ const String& permission);

    /** @hide */
    static CARAPI_(Int32) StringOpToOp(
        /* [in] */ const String& op);

private:
    String BuildSecurityExceptionMsg(
        /* [in] */ Int32 op,
        /* [in] */ Int32 uid,
        /* [in] */ const String& packageName);

public:
    /**
     * This maps each operation to the string constant for it.
     * If it doesn't have a string constant, it maps to null.
     */
    static String sOpToString[62];

    /**
     * This maps each operation to the public string constant for it.
     * If it doesn't have a public string constant, it maps to null.
     */
    static String sOpToOpString[62];

    /**
     * This provides a simple name for each operation to be used
     * in debug output.
     */
    static String sOpNames[62];

private:
    static const String TAG;

    IContext* mContext;
    AutoPtr<IIAppOpsService> mService;
    HashMap<AutoPtr<IAppOpsManagerOnOpChangedListener>, AutoPtr<IIAppOpsCallback> > mModeWatchers;
    Object mModeWatchersLock;

    static AutoPtr<IBinder> sToken;
    static Object sClassLock;

    static const Int32 sOpLength;

    static String OPSTR_GPS; // ="android:gps";
    static String OPSTR_VIBRATE; // = "android:vibrate";
    static String OPSTR_READ_CONTACTS; // = "android:read_contacts";
    static String OPSTR_WRITE_CONTACTS; //= "android:write_contacts";
    static String OPSTR_READ_CALL_LOG; // = "android:read_call_log";
    static String OPSTR_WRITE_CALL_LOG; // = "android:write_call_log";
    static String OPSTR_READ_CALENDAR; // = "android:read_calendar";
    static String OPSTR_WRITE_CALENDAR; // = "android:write_calendar";
    static String OPSTR_WIFI_SCAN; // = "android:wifi_scan";
    static String OPSTR_POST_NOTIFICATION; // = "android:post_notification";
    static String OPSTR_NEIGHBORING_CELLS; // = "android:neighboring_cells";
    static String OPSTR_CALL_PHONE; // = "android:call_phone";
    static String OPSTR_READ_SMS; // = "android:read_sms";
    static String OPSTR_WRITE_SMS; // = "android:write_sms";
    static String OPSTR_RECEIVE_SMS; // = "android:receive_sms";
    static String OPSTR_RECEIVE_EMERGECY_SMS; // = "android:receive_emergecy_sms";
    static String OPSTR_RECEIVE_MMS; // = "android:receive_mms";
    static String OPSTR_RECEIVE_WAP_PUSH; // = "android:receive_wap_push";
    static String OPSTR_SEND_SMS; // = "android:send_sms";
    static String OPSTR_READ_ICC_SMS; //= "android:read_icc_sms";
    static String OPSTR_WRITE_ICC_SMS; // = "android:write_icc_sms";
    static String OPSTR_WRITE_SETTINGS; // = "android:write_settings";
    static String OPSTR_SYSTEM_ALERT_WINDOW; // = "android:system_alert_window";
    static String OPSTR_ACCESS_NOTIFICATIONS; // = "android:access_notifications";
    static String OPSTR_CAMERA; // = "android:camera";
    static String OPSTR_RECORD_AUDIO; // = "android:record_audio";
    static String OPSTR_PLAY_AUDIO; // = "android:play_audio";
    static String OPSTR_READ_CLIPBOARD; // = "android:read_clipboard";
    static String OPSTR_WRITE_CLIPBOARD; // = "android:write_clipboard";
    static String OPSTR_TAKE_MEDIA_BUTTONS; // = "android:take_media_buttons";
    static String OPSTR_TAKE_AUDIO_FOCUS; // = "android:take_audio_focus";
    static String OPSTR_AUDIO_MASTER_VOLUME; // = "android:audio_master_volume";
    static String OPSTR_AUDIO_VOICE_VOLUME; // = "android:audio_voice_volume";
    static String OPSTR_AUDIO_RING_VOLUME; // = "android:audio_ring_volume";
    static String OPSTR_AUDIO_MEDIA_VOLUME; // = "android:audio_media_volume";
    static String OPSTR_AUDIO_ALARM_VOLUME; // = "android:audio_alarm_volume";
    static String OPSTR_AUDIO_NOTIFICATION_VOLUME; // = "android:audio_notification_volume";
    static String OPSTR_AUDIO_BLUETOOTH_VOLUME; // = "android:audio_bluetooth_volume";
    static String OPSTR_WAKE_LOCK; // = "android:wake_lock";
    static String OPSTR_MUTE_MICROPHONE; // = "android:mute_microphone";
    static String OPSTR_TOAST_WINDOW; // = "android:toast_window";
    static String OPSTR_PROJECT_MEDIA; // = "android:project_media";
    static String OPSTR_WIFI_CHANGE; // = "android:wifi_change";
    static String OPSTR_BLUETOOTH_CHANGE; // = "android:bluetooth_change";
    static String OPSTR_SEND_MMS; // = "android:send_mms";
    static String OPSTR_READ_MMS; // = "android:read_mms";
    static String OPSTR_WRITE_MMS; // = "android:write_mms";
    static String OPSTR_BOOT_COMPLETED; // = "android:boot_completed";
    static String OPSTR_NFC_CHANGE; // = "android:nfc_change";
    static String OPSTR_DELETE_SMS; // = "android:delete_sms";
    static String OPSTR_DELETE_MMS; // = "android:delete_mms";
    static String OPSTR_DELETE_CONTACTS; // = "android:delete_contacts";
    static String OPSTR_DELETE_CALL_LOG; // = "android:delete_call_log";
    static String OPSTR_DATA_CONNECT_CHANGE; // = "android:data_connect_change";
    static String OPSTR_ALARM_WAKEUP; // = "android:alarm_wakeup";
    static String OPSTR_SU; // = "android:su";

    /**
     * This maps each operation to the operation that serves as the
     * switch to determine whether it is allowed.  Generally this is
     * a 1:1 mapping, but for some things (like location) that have
     * multiple low-level operations being tracked that should be
     * presented to the user as one switch then this can be used to
     * make them all controlled by the same single operation.
     */
    static Int32 sOpToSwitch[62];

    /**
     * This optionally maps a permission to an operation.  If there
     * is no permission associated with an operation, it is null.
     */
    static String sOpPerms[62];

    /**
     * Specifies whether an Op should be restricted by a user restriction.
     * Each Op should be filled with a restriction string from UserManager or
     * null to specify it is not affected by any user restriction.
     */
    static String sOpRestrictions[62];

    /**
     * This specifies whether each option should allow the system
     * (and system ui) to bypass the user restriction when active.
     */
    static Boolean sOpAllowSystemRestrictionBypass[62];


    /**
     * This specifies the default mode for each operation.
     */
    static Int32 sOpDefaultMode[62];

    /**
     * This specifies the default mode for each strict operation.
     */
    static Int32 sOpDefaultStrictMode[62];

    /**
     * This specifies if operation is in strict mode.
     */
    static Boolean sOpStrictMode[62];

    /**
     * This specifies whether each option is allowed to be reset
     * when resetting all app preferences.  Disable reset for
     * app ops that are under strong control of some part of the
     * system (such as OP_WRITE_SMS, which should be allowed only
     * for whichever app is selected as the current SMS app).
     */
    static Boolean sOpDisableReset[62];

    static AutoPtr<HashMap<String, Int32> > sOpStrToOp;
    static AutoPtr<HashMap<String, Int32> > sOpStringToOp;
    static AutoPtr<HashMap<String, Int32> > sNameToOp;
};

} // namespace App
} // namespace Droid
} // namespace Elastos

#endif //__ELASTOS_DROID_APP_APP_OPS_MANAGER_H__
