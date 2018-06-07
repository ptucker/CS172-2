#include <iostream>
#include "Course.h"
using namespace std;


int main() {
  Course course1("Physics", 3);
  course1.addStudent("Rich");
  course1.addStudent("Michael");
  course1.addStudent("Keaton");

  
  cout << "Students in " << course1.getCourseName() << ":" << endl;
  string* getNames = course1.getStudents();
  for (int output = 0; output < course1.getNumberOfStudents(); output++) {
    cout << getNames[output] << endl;
  }
  cout << endl;
  cout << "Michael dropped from " << course1.getCourseName() << " :(" << endl;
  course1.dropStudent("Michael");
  cout << "Students in " << course1.getCourseName() << ":" << endl;
  for (int output = 0; output < course1.getNumberOfStudents(); output++) {
    cout << getNames[output] << endl;
  }
  return 0;
}