#include <iostream>
#include <vector>
#include <string>
#include "Appointment.h"
using namespace std;

Appointment::Appointment() {

}

void Appointment::set_Appointment(Patient pat, Doctor doc, Date Setdate) {
  Patient * tempPerson = new Patient(pat);
  peeps.push_back(*tempPerson);
  delete tempPerson;

  Doctor * tempDoc = new Doctor(doc);
  docs.push_back(*tempDoc);
  delete tempDoc;

  Date * tempDate = new Date(Setdate);
  time.push_back(*tempDate);
  delete tempDate;
  amount++;
}

void Appointment::get_Appointment(string nameInput) {
  for (int find = 0; find < amount; find++) {
    if (peeps[find].get_name() == nameInput) {
      cout << peeps[find].get_name() << "'s appointment is scheduled for "
        << time[find].getHour() << ":" << time[find].getMinute() << " " << time[find].getPMorAM()
        << " on " << time[find].getMonth() << "/" << time[find].getDay() << "/" << time[find].getYear()
        << " with " << docs[find].get_Profession() << " Dr. " << docs[find].get_name() << endl;
    }
  }
}

int Appointment::get_amount() { return amount; }

Date Appointment::get_time(int index) {
  return time[index];
}

Patient Appointment::get_Patient(int index) {
  return peeps[index];
}

Doctor Appointment::get_Doctor(int index) {
  return docs[index];
}