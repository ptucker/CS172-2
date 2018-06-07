#include <iostream>
#include "Course.h"
using namespace std;

Course::Course(const string& courseName, int capacity) {
  numberOfStudents = 0;
  this->courseName = courseName;
  this->capacity = capacity;
  students = new string[capacity];
}

Course::~Course() {
  delete [] students;
}

string Course::getCourseName() const {
  return courseName;
}

void Course::addStudent(const string& name) {
  students[numberOfStudents] = name;
  numberOfStudents++;
}

void Course::dropStudent(const string& name) {
  int shift = -1;
  for (int i = 0; i < numberOfStudents; i++) {
    if (students[i] == name) {
      shift = i;
      //In case of errors a blank won't appear.
      students[i] = "REMOVED";
      numberOfStudents--;
    }
  }
  //Replaces removed name in array with all above names.
  if (shift != -1) {
    for (int change = shift; change < numberOfStudents; change++) {
      students[change] = students[change + 1];
    }
  }
}

string* Course::getStudents() const {
  return students;
}

int Course::getNumberOfStudents() {
  return numberOfStudents;
}