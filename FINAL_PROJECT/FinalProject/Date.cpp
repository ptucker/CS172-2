#include <ctime>
#include "Date.h"
using namespace std;

  Date::Date() {
    // Have to add _CRT_SECURE_NO_WARNINGS to Visual Studio c++ preprocessor definitions for localtime to work
    //If you don't it tells you to put localtime_s and I don't know how to change my code to work with that...
    time_t tt;
    time(&tt);
    tm TM = *localtime(&tt);
    year = TM.tm_year + 1900;
    month = TM.tm_mon + 1;
    day = TM.tm_mday;
    //Outputs time without military format.
    if (TM.tm_hour > 12) {
      hour = TM.tm_hour - 12;
    }
    else {
      hour = TM.tm_hour;
    }
    minute = TM.tm_min;
    second = TM.tm_sec;
  }

  Date::Date(int monthInput, int dayInput, int yearInput) {
    year = yearInput;
    month = monthInput;
    day = dayInput;


  }


  //When setting appointments you usually don't include seconds which is why I left it out of constructor
  Date::Date(int monthInput, int dayInput, int yearInput, int hourInput, int minuteInput) {
    time_t tt;
    time(&tt);
    tm TM = *localtime(&tt);
    year = yearInput;
    month = monthInput;
    day = dayInput;

    hour = hourInput;
    minute = minuteInput;
    second = TM.tm_sec + 1;

  }

  int Date::getYear() { return year; }
  int Date::getDay() { return day; }
  int Date:: getMonth() { return month; }

  int Date::getHour() { return hour; }
  int Date::getMinute() { return minute; }
  int Date::getSecond() { return second; }
