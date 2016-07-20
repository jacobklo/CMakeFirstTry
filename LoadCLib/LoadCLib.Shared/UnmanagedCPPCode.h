#pragma once

class CUnmanagedCPPCode
{
private:
	int number;
public:
	CUnmanagedCPPCode();
	~CUnmanagedCPPCode();
	int GetNumber();
	void SetNumber(int newNumber);
};