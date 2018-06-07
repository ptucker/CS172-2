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
  string* increaseSize = NULL;
  if (numberOfStudents == capacity) {
    increaseSize = new string[++capacity];
    for (int copy = 0; copy < numberOfStudents; copy++) {
      increaseSize[copy] = students[copy];
    }
    students = increaseSize;
    students[numberOfStudents] = name;
    numberOfStudents++;
  }
  else {
    students[numberOfStudents] = name;
    numberOfStudents++;
  }
  //Hangs when I use delete I think its because students points at
  //increaseSize and when deleted doesn't have anything to look to.
  //Sorry RAM
  //delete[] increaseSize;
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