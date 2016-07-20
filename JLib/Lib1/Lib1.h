#pragma once

#include "Include1.h"

#ifdef WIN32
  #define DLL_EXPORT __declspec (dllexport)
#else
  #define DLL_EXPORT
#endif

class Lib1 : public Include1
{
public:
  Lib1();
  ~Lib1();
  void SetNumber( int newNumber );
  int GetNumber();
private:
  int number;
};
