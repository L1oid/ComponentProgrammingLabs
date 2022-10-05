#ifndef OBJBASE_H
#define OBJBASE_H

#define CLSID_ int
#define IID_ int
#define HRESULT_ int
#define ULONG_ int

const int IID_IUNKNOWN = 0;
const int IID_IX = 1;
const int IID_IY = 2;
const int IID_IZ = 3;
const int IID_ICLASSFACTORY = 1;
const int IID_ICLASSFACTORY2 = 2;

const int CLSID_SERVER = 1;
const int CLSID_SERVERMOD = 2;

const int S_OK_ = 0;
const int S_FALSE_ = 1;

typedef HRESULT_ (*FunctionType) (CLSID_, IID_, void**);
typedef HRESULT_ (*FunctionType2) ();

#endif