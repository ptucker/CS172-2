#include <iostream>
#include "CircleWithConstantMemberFunctions.h"
using namespace std;

int main() {
  Circle test1(4);
  Circle test2(5);

  bool greaterthan;
  bool greaterthanequal;
  bool equalto;
  bool notequalto;
  bool lessthanequal;
  bool lessthan;
  greaterthan =       test1 < test2;
  greaterthanequal =  test1 <= test2;
  equalto =           test1 == test2;
  notequalto =        test1 != test2;
  lessthanequal =     test1 >= test2;
  lessthan =          test1 > test2;
  cout << "Test1 = 4" << endl;
  cout << "Test2 = 5" << endl;
  cout << "Test1 <  Test2: " << greaterthan << endl;
  cout << "Test1 <= Test2: " << greaterthanequal << endl;
  cout << "Test1 == Test2: " << equalto << endl;
  cout << "Test1 != Test2: " << notequalto << endl;
  cout << "Test1 >= Test2: " << lessthanequal << endl;
  cout << "Test1 >  Test2: " << lessthan << endl;

}