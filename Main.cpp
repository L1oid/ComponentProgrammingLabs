#include <iostream>
#include "IManager.h"
#include "OBJBASE.h"
using namespace std;

/*
class ServerDecorator
{
    private:
        IX* pX = NULL;
        IY* pY = NULL;
        IClassFactory* pF = NULL;
        HRESULT_ result;
    public:
        ServerDecorator(CLSID_ CLSID, IID_ IID)
        {
            result = GetClassObject(CLSID, IID, (void**)&pF);
        }
        ServerDecorator(ServerDecorator& )
        {

        }
        ~ServerDecorator()
        {
            pX=
        }
        void Func1()
        {
            pX->Func1();
        }
        void Func2()
        {
            pY->Func2();
        }
};
*/
int main()
{
    IClassFactory* pF = NULL;
    HRESULT_ result = GetClassObject(CLSID_SERVER, IID_ICLASSFACTORY, (void**)&pF);
    if (result == S_OK)
    {
        IY* pY = NULL;
        result = pF->CreateInstance2(IID_IY, (void**)&pY, 3, 6);
        if (result == S_OK)
        {
            cout << "NOD: " << pY->Nod() << endl;
        }
        else cout << "Warning" << endl;
        result = pY->QueryInterface(IID_IX, (void**)&pY);
        if (result == S_OK)
        {
            cout << "NOK: " << pY->Nod() << endl;
            pY->Release();
        }
        else cout << "Warning" << endl;
        pY->Release();
    }
    else cout << "Warning" << endl;
    pF->Release();
    system("pause");
    return 0;
}