#pragma once
#include "UnmanagedCPPCode.h"
#include <limits.h>
#include <stddef.h>

/************************************************************************/
/* 
The if __cplusplus is needed!!!!!
extern "C" is needed to export to C# code!
*/
/************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

class LoadCLib {
public:
    static char * getTemplateInfo();
    LoadCLib();
    ~LoadCLib();
	
};

int getChar();
/************************************************************************/
/*
CPP WRAPPER METHODS
This shows how to port C++ class to C# code
In order for C# to use C++ class, you can use PInvoke.
In C# code, use DllImport ("libraryName") to import this as a library
The CPPCLASSWRAPPER_ classes is actually a wrapper C class to create/load/destroy a C++ class.
It has to work like this

When implement, 
1) write normal C++ code/classes
2) create CPP wrapper for each methods of the class  ( include create class and destroy class )
3) In C# code, use [DllImport ] to call all the CPP wrapper class

REFERENCE: http://www.codeproject.com/Articles/18032/How-to-Marshal-a-C-Class
*/
/************************************************************************/
CUnmanagedCPPCode * CPPCLASSWRAPPER_CUnmanagedCPPCodeClass_CreateClass();
void CPPCLASSWRAPPER_CUnmanagedCPPCodeClass_DestroyCLass(CUnmanagedCPPCode * pObject);
int CPPCLASSWRAPPER_CUnmanagedCPPCodeClass_GetNumber(CUnmanagedCPPCode * pObject);
void CPPCLASSWRAPPER_CUnmanagedCPPCodeClass_SetNumber(CUnmanagedCPPCode * pObject, int newNumber);

#ifdef __cplusplus
}
#endif