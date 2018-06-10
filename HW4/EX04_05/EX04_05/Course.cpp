#include <iostream>
#include "Course.h"
using namespace std;

// 19/20

Course::Course(const string& courseName, int capacity) {
  numberOfStudents = 0;
  this->courseName = courseName;
  this->capacity = capacity;
  students = new string[capacity];
}
//Destructor
Course::~Course() {
  delete [] students;
}
//Constructor / Deep Copy
Course::Course(const Course& course) {
  courseName = course.courseName;
  numberOfStudents = course.numberOfStudents;
  capacity = course.capacity;
  students = new string[capacity];
  for (int copy = 0; copy < numberOfStudents; copy++) {
    students[copy] = course.students[copy];
  }
}

string Course::getCourseName() const {
  return courseName;
}

void Course::addStudent(const string& name) {
  string* increaseSize = NULL;
  if (numberOfStudents == capacity) {
    //PT -- probably better to double the capacity, rather than incrementing it
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
  
  //PT -- put the delete into the if (numberOfStudents == capacity) case
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

void Course::clear() {
  for (int erase = 0; erase < capacity; erase++) {
    students[erase] = "";
  }
  capacity = 0;
  //PT -- numberOfStudents = 0;
  // -1
}

string* Course::getStudents() const {
  return students;
}

int Course::getNumberOfStudents() {
  return numberOfStudents;
}
