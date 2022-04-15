#include <windows.h>

extern "C" double __declspec(dllexport) TestFunction(double a, double b)
{
     return (a+b)*100;
}

extern "C" HRESULT_ __declspec(dllexport) GetClassObject(CLSID_ CLSID, IID_ IID, void** ppv)
{
    IUnknown* pIUnknown = NULL;
    switch (CLSID) 
    {
    case CLSID_SERVER:
        pIUnknown = (IClassFactory*) new ServerFactory;
        cout << "GetClassObject: ServerFactory connected." << endl;
        break;
    case CLSID_SERVER2:
        pIUnknown = (IClassFactory*) new Server2Factory;
        cout << "GetClassObject: Server2Factory connected." << endl;
        break;
    default:
        cout << "GetClassObject: connection error." << endl;
        return S_FAIL;
        break;
    }
    return pIUnknown->QueryInterface(IID, ppv);
}


BOOL APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    switch (fdwReason)
    {
        case DLL_PROCESS_ATTACH:
            // attach to process
            // return FALSE to fail DLL load
            break;

        case DLL_PROCESS_DETACH:
            // detach from process
            break;

        case DLL_THREAD_ATTACH:
            // attach to thread
            break;

        case DLL_THREAD_DETACH:
            // detach from thread
            break;
    }
    return TRUE; // succesful
}