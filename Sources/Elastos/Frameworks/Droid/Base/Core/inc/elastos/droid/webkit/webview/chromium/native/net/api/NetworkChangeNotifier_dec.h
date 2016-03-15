//This file is autogenerated for
//    NetworkChangeNotifier.java
//put this file at the end of the include list
//so the type definition used in this file will be found
#ifndef ELASTOS_NETWORKCHANGENOTIFIER_CALLBACK_DEC_HH
#define ELASTOS_NETWORKCHANGENOTIFIER_CALLBACK_DEC_HH


#ifdef __cplusplus
extern "C"
{
#endif
    extern void Elastos_NetworkChangeNotifier_nativeNotifyConnectionTypeChanged(IInterface* caller,Handle64 nativePtr,Int32 newConnectionType);
    extern void Elastos_NetworkChangeNotifier_InitCallback(Handle64 cb);
#ifdef __cplusplus
}
#endif


namespace Elastos {
namespace Droid {
namespace Webkit {
namespace Webview {
namespace Chromium {
namespace Net {

struct ElaNetworkChangeNotifierCallback
{
    AutoPtr<IInterface> (*elastos_NetworkChangeNotifier_init)(IInterface* context);
    Int32 (*elastos_NetworkChangeNotifier_getCurrentConnectionType)(IInterface* obj);
    void (*elastos_NetworkChangeNotifier_addNativeObserver)(IInterface* obj, Handle64 nativeChangeNotifier);
    void (*elastos_NetworkChangeNotifier_removeNativeObserver)(IInterface* obj, Handle64 nativeChangeNotifier);
    void (*elastos_NetworkChangeNotifier_forceConnectivityState)(Boolean networkAvailable);
};

void* NetworkChangeNotifier::ElaNetworkChangeNotifierCallback_Init()
{
    static ElaNetworkChangeNotifierCallback sElaNetworkChangeNotifierCallback;

    sElaNetworkChangeNotifierCallback.elastos_NetworkChangeNotifier_init = &NetworkChangeNotifier::Init;
    sElaNetworkChangeNotifierCallback.elastos_NetworkChangeNotifier_getCurrentConnectionType = &NetworkChangeNotifier::GetCurrentConnectionType;
    sElaNetworkChangeNotifierCallback.elastos_NetworkChangeNotifier_addNativeObserver = &NetworkChangeNotifier::AddNativeObserver;
    sElaNetworkChangeNotifierCallback.elastos_NetworkChangeNotifier_removeNativeObserver = &NetworkChangeNotifier::RemoveNativeObserver;
    sElaNetworkChangeNotifierCallback.elastos_NetworkChangeNotifier_forceConnectivityState = &NetworkChangeNotifier::ForceConnectivityState;

    Elastos_NetworkChangeNotifier_InitCallback((Handle64)&sElaNetworkChangeNotifierCallback);
    return &sElaNetworkChangeNotifierCallback;
}

static void* sPElaNetworkChangeNotifierCallback = NetworkChangeNotifier::ElaNetworkChangeNotifierCallback_Init();

} // namespace Net
} // namespace Chromium
} // namespace Webview
} // namespace Webkit
} // namespace Droid
} // namespace Elastos

#endif //ELASTOS_NETWORKCHANGENOTIFIER_CALLBACK_DEC_HH