//I affirm that all code given below was written solely by me, Levi, and that any
//help I received adhered to the rules stated for this exam.

#include <string>
#include "Runner.h"

using namespace std;

Runner::Runner(string setfirst, string setlast, int setpace) {
  firstname = setfirst;
  lastname = setlast;
  pace = setpace;
}

string Runner::get_firstname() { return firstname; }

string Runner::get_lastname() { return lastname; }

int Runner::get_pace() { return pace; }