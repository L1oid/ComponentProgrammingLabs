#include <iostream>
#include <windows.h>
#include <fstream>
#include <vector>
#include "IUnknown.h"
#include "OBJBASE.h"

using namespace std;

HINSTANCE hinstLib;
vector<HINSTANCE> libs(1);

extern "C" HRESULT_ __declspec(dllexport) GetClassObject(CLSID_ CLSID, IID_ IID, void** ppv)
{
    FunctionType DLLGetClassObject;
    string temp;
    string str_cls_id = to_string(CLSID);
    char path[MAX_PATH] = {};
    ifstream f("C:/Users/lloid/Documents/GitHub/DLLComponentProgramming/build/Reg.txt");
    while(f >> temp)
    {
        if (temp == str_cls_id)
        {
            f >> path;
            break;
        }
    }
    f.close();
    hinstLib = LoadLibrary(path);
    if (!hinstLib)
    {
           cout << "DLL not found111 !" << endl;
           return S_FALSE_;
    }
    libs.push_back(hinstLib);
    DLLGetClassObject = (FunctionType) GetProcAddress(hinstLib, "DLLGetClassObject");
    if (!DLLGetClassObject)
    {
          cout << "DLL DLLGetClassObject not found !!" << endl;
          return S_FALSE_;
    } 
    return DLLGetClassObject(CLSID, IID, ppv);
}

extern "C" HRESULT_ __declspec(dllexport) FreeUnusedLibrires()
{
    FunctionType2 DllCanUnloadNow_;
    HRESULT_ result;
    for (int i = 0; i < libs.size(); i++)
    {
        DllCanUnloadNow_ = (FunctionType2) GetProcAddress(libs[i], "DllCanUnloadNow_");
        if (DllCanUnloadNow_)
        {
            result = DllCanUnloadNow_();
            if (result == S_OK_)
            {
                FreeLibrary(libs[i]);
                libs.erase(libs.begin() + i);
                libs.resize(libs.size() - 1);
            }
        }
    }
    return result;
}