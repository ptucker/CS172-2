#ifndef PEOPLE_H
#define PEOPLE_H

#include <string>

using namespace std;
class People {
private:
  string name;
public:
  People(string);
  string get_name();
  void set_name(string);
};

#endif // !PEOPLE_H
#pragma once
