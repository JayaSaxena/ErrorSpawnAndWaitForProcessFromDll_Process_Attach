// ApplicationToUseDllMain.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>


int main()
{
	HINSTANCE dllHandle = LoadLibrary(L"CreateProcessCallFromDll.dll");
	if( dllHandle != NULL)
	{
		FreeLibrary(dllHandle);
	}
    return 0;
}

