//I affirm that all code given below was written solely by me, Levi, and that any
//help I received adhered to the rules stated for this exam.

#ifndef RUNNER_H
#define RUNNER_H

#include <string>
using namespace std;
class Runner {
private:
  string firstname;
  string lastname;
  int pace;
public:
  Runner(string, string, int);
  string get_firstname();
  string get_lastname();
  int get_pace();
};



#endif

