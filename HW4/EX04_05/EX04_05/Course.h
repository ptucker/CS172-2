#ifndef COURSE_H
#define COURSE_H
#include <string>
using namespace std;

class Course {
public:
  Course(const string& courseName, int capacity);
  ~Course();
  Course(const Course&);
  string getCourseName() const;
  void addStudent(const string& name);
  void dropStudent(const string& name);
  void clear();
  string* getStudents() const;
  int getNumberOfStudents();

private:
  string courseName;
  string* students;
  int numberOfStudents;
  int capacity;
};

#endif