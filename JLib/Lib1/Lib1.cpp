#include "Lib1.h"

Lib1::Lib1()
{
  number = 123;
}

Lib1::~Lib1()
{

}

void Lib1::SetNumber( int newNumber )
{
  number = newNumber;
}

int Lib1::GetNumber()
{
  return number;
}
