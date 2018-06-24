#ifndef DATE_H
#define DATE_H
#include <ctime>
using namespace std;

class Date {
private:
  int year, month, day;
  int hour, minute;
  string PMorAM;
public:

  Date();
  Date(int monthInput, int dayInput, int yearInput);
  Date(int monthInput, int dayInput, int yearInput, int hourInput, int minuteInput, string when);

  int getYear();
  int getDay();
  int getMonth();

  int getHour();
  int getMinute();
  string getPMorAM();
};

#endif // !DATE_H

