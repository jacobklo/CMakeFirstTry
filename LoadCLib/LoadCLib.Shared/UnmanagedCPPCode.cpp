#include "UnmanagedCPPCode.h"

CUnmanagedCPPCode::CUnmanagedCPPCode()
{
	number = 54321;
}

CUnmanagedCPPCode::~CUnmanagedCPPCode()
{
}

int CUnmanagedCPPCode::GetNumber()
{
	return number;
}

void CUnmanagedCPPCode::SetNumber(int newNumber)
{
	number = newNumber;
}