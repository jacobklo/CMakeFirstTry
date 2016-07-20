#include "testLib1.h"
#define CATCH_CONFIG_MAIN
#include "Catch.h"
#include "Lib1/Lib1.h"

TEST_CASE( "Lib1 Test", "[testLib1]" )
{
  Lib1 l;
  SECTION( " test 1 " )
  {
    CHECK ( l.GetNumber() == 123 );
  }
  
  l.SetNumber( 234 );
  SECTION( " test 2 " )
  {
    CHECK ( l.GetNumber() == 235 );
  }
  
  l.SetNumber( 345 );
  SECTION( " test 3 " )
  {
    CHECK ( l.GetNumber() == 345 );
  }
}