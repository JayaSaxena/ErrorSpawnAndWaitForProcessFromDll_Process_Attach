// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
#include <iostream>

void CreateNewProcess()
{
	STARTUPINFOW startUpInfow;
	memset(&startUpInfow, 0, sizeof(startUpInfow));
	//pInfow, sizeof(startUpInfow));
	startUpInfow.cb = sizeof(startUpInfow);

	PROCESS_INFORMATION processInformation;
	memset(&processInformation, 0, sizeof(processInformation));

	WCHAR cmd[] = L"childProcessToBeSpawnedAndWaitedByDll.exe";
	//WCHAR cmd[] = L"C:\\Users\\jaya.saxena\\Source\\Cloudhouse.AppAcceleratorV\\src\\Win32\\Debug\\AAV.exe /f Notepad.exe";

	if (!CreateProcess(NULL, // No module name (use command line)
		cmd, //argv[1], // Command line
		NULL, // Process handle not inheritable
		NULL, // Thread handle not inheritable
		FALSE, // Set handle inheritance to FALSE
		0, // No creation flags
		NULL, // Use parent's environment block
		NULL, // Use parent's starting directory
		&startUpInfow, // Pointer to STARTUPINFO structure
		&processInformation) // Pointer to PROCESS_INFORMATION structure
		)
	{
		std::cout << "Parent Exe's Dll:: CreateProcess failed" << GetLastError() << std::endl;
		return;
	}
	std::cout << "Parent Exe's Dll:: Spawned Child Process Id is:: " << GetProcessId(processInformation.hProcess) << std::endl;
	std::cout << "Parent Exe's Dll:: Waiting until child process exits." << std::endl;
 	WaitForSingleObject(processInformation.hProcess, INFINITE);
	std::cout << "Parent Exe's Dll:: Child process terminated." << std::endl;

	CloseHandle(processInformation.hProcess);
	CloseHandle(processInformation.hThread);
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
		CreateNewProcess();
		std::cout << "Parent Exe's Dll:: DllMain()::DLL_PROCESS_ATTACH  terminating." << std::endl;
		break;
    case DLL_THREAD_ATTACH:

    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

