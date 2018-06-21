#ifndef DATE_H
#define DATE_H
#include <ctime>
using namespace std;

class Date {
private:
  int year, month, day;
  int hour, minute, second;
public:

  Date();
  Date(int monthInput, int dayInput, int yearInput);
  Date(int monthInput, int dayInput, int yearInput, int hourInput, int minuteInput);

  int getYear();
  int getDay();
  int getMonth();

  int getHour();
  int getMinute();
  int getSecond();
};

#endif // !DATE_H

