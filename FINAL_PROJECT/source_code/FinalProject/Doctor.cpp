#include "Doctor.h"

using namespace std;

Doctor::Doctor(string DocName) : People(DocName) {};

void Doctor::set_Profession(string ProfessionEnter) {
  type = ProfessionEnter;
}

string Doctor::get_Profession() { return type; }