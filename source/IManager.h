#ifndef IMANAGER_H
#define IMANAGER_H
#include "Server.h"
#include "Server2.h"
#include "OBJBASE.h"
HRESULT_ CreateInstance(CLSID_, IID_, void**);
HRESULT_ GetClassObject(CLSID_, IID_, void**);
#endif