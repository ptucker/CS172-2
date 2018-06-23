#include "People.h"
using namespace std;

People::People(string nameSet) {
  name = nameSet;
}

string People::get_name() {
  return name;
}

void People::set_name(string nameSet) {
  name = nameSet;
}