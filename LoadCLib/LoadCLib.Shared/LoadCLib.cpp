#include "LoadCLib.h"

#define PLATFORM_ANDROID 0
#define PLATFORM_IOS 1

char * LoadCLib::getTemplateInfo()
{
#if PLATFORM == PLATFORM_IOS
	static char info[] = "Platform for iOS";
#elif PLATFORM == PLATFORM_ANDROID
	static char info[] = "Platform for Android";
#else
	static char info[] = "Undefined platform";
#endif

	return info;
}

LoadCLib::LoadCLib()
{
}

LoadCLib::~LoadCLib()
{
}

int getChar()
{
	return 42;
}

CUnmanagedCPPCode * CPPCLASSWRAPPER_CUnmanagedCPPCodeClass_CreateClass()
{
	return new CUnmanagedCPPCode();
}

void CPPCLASSWRAPPER_CUnmanagedCPPCodeClass_DestroyCLass(CUnmanagedCPPCode * pObject)
{
	if (pObject == NULL)
		return;
	delete pObject;
	pObject = NULL;
}

int CPPCLASSWRAPPER_CUnmanagedCPPCodeClass_GetNumber(CUnmanagedCPPCode * pObject)
{
	if (pObject == NULL) {
		return INT_MIN;
	}
	return pObject->GetNumber();
}
void CPPCLASSWRAPPER_CUnmanagedCPPCodeClass_SetNumber(CUnmanagedCPPCode * pObject, int newNumber)
{
	if (pObject == NULL) {
		return;
	}
	pObject->SetNumber(newNumber);
}