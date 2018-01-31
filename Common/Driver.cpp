#include "stdafx.h"
	
extern "C"
{
	DRIVER_INITIALIZE DriverEntry;
	DRIVER_UNLOAD UnloadDriver;
};

PDRIVER_UNLOAD Old_Unload = nullptr;

PDRIVER_OBJECT g_pDriverObject = nullptr;
PVOID g_pDrvImageBase = nullptr;
SIZE_T g_DrvImageSize = 0;
wchar_t g_DriverRegistryKey[MAX_PATH] = {};
PLIST_ENTRY PsLoadedModuleList = nullptr;

_Use_decl_annotations_
EXTERN_C
VOID UnloadDriver(
	_In_ DRIVER_OBJECT *DriverObject
)
{			
	cc_doexit(0,0,0);
}
_Use_decl_annotations_
EXTERN_C
NTSTATUS
DriverEntry(
	__in DRIVER_OBJECT* driverObject,
	__in UNICODE_STRING* registryPath
)
{
	NTSTATUS ns = STATUS_UNSUCCESSFUL;
	
	//CRT init
	cc_init(0);

	std::vector<int> vt;
	vt.push_back(1);
	vt.push_back(2);
	vt.push_back(3);
	vt.push_back(4);
	
	DbgPrint("vector element value:%d\r\n", vt[0]);

	return ns;
}