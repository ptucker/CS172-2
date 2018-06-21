#include <iostream>
#include "Date.h"

using namespace std;

int main() {
  Date test;
  cout << test.getMonth() << " " << test.getDay() << " " << test.getYear() << "  ";
  cout << test.getHour() << ":" << test.getMinute() << ":" << test.getSecond() << endl;
  Date test2(4, 21, 2018);
  cout << test2.getMonth() << " " << test2.getDay() << " " << test2.getYear() << endl;
}