// childProcessToBeSpawnedAndWaitedByDll.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>

int main()
{
	std::cout << "Child Process:: I am Spawned, might be by a Dll" <<std::endl;
	MessageBox(NULL, L"Child Process Spawned by DllMain???", L"Child Process Spawned",MB_OK);

	std::cout << "Child Process:: Loading ieframe Dll library" << std::endl;
	//HINSTANCE hdll = LoadLibrary(L"ntdll.dll");
	HINSTANCE hdll = LoadLibrary(L"ieframe.dll");
	if (hdll == NULL) 
		std::cout << "Child Process:: Error in loading the library" << std::endl;
	else
		FreeLibrary(hdll);

	std::cout << "Child Process:: Exitting" << std::endl;
	MessageBox(NULL, L"Child Process Exiting", L"Child Process", MB_OK);
	return 0;
}

