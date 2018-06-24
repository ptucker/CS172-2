#include <iostream>
#include <vector>
#include <string>
#include "Appointment.h"
using namespace std;

Appointment::Appointment() {

}

void Appointment::set_Appointment(Patient pat, Doctor doc, Date Setdate) {

  bool input = true;
  int errorNumber = -1;
  int tempHour = -1;
  int minuteCheck = -1;

  //Checks if there are any appointments with the same doctor within + or - 30 minutes.
  //So appointments can be scheduled 30 mintues apart but not less than that to allow time
  //for doctor to work with patients.
  for (int x = 0; x < amount; x++) {
    //For AM or PM appointments.
    if (doc.get_name() == docs[x].get_name() &&
      Setdate.getYear() == time[x].getYear() &&
      Setdate.getMonth() == time[x].getMonth() &&
      Setdate.getPMorAM() == time[x].getPMorAM() &&
        Setdate.getDay() == time[x].getDay()) {
      if (Setdate.getMinute() < 30) {
        if (Setdate.getHour() == time[x].getHour() || Setdate.getHour() - 1 == time[x].getHour()) {
          minuteCheck = 30 + Setdate.getMinute();
          if (Setdate.getHour() == time[x].getHour() && time[x].getMinute() < minuteCheck) {
            input = false;
            errorNumber = x;
            break;
          }
          if (Setdate.getHour() - 1 == time[x].getHour() && time[x].getMinute() > minuteCheck) {
            input = false;
            errorNumber = x;
            break;
          }
        }
      }
      if (Setdate.getMinute() > 30) {
        if (Setdate.getHour() == time[x].getHour() || Setdate.getHour() + 1 == time[x].getHour()) {
          minuteCheck = Setdate.getMinute() - 30;
          if (Setdate.getHour() == time[x].getHour() && time[x].getMinute() > minuteCheck) {
            input = false;
            errorNumber = x;
            break;
          }
          if (Setdate.getHour() + 1 == time[x].getHour() && time[x].getMinute() < minuteCheck) {
            input = false;
            errorNumber = x;
            break;
          }
        }
      }
      if (Setdate.getMinute() == 30 && time[x].getHour() == Setdate.getHour()) {
        if (time[x].getMinute() <= 59 && time[x].getMinute() >= 1) {
          input = false;
          errorNumber = x;
          break;
        }
      }
    }


    //For around 12 appointments where AM and PM change and 12 to 1 which is harder to code because not + 1.
    if (doc.get_name() == docs[x].get_name() &&
      Setdate.getYear() == time[x].getYear() &&
      Setdate.getMonth() == time[x].getMonth() &&
      Setdate.getPMorAM() != time[x].getPMorAM() && // If one is at 12:00 PM and other is at 11:50 AM
      Setdate.getDay() == time[x].getDay()) {
      if (Setdate.getMinute() < 30 && Setdate.getHour() == 12) {
        if (time[x].getHour() == 11) {
          minuteCheck = 30 + Setdate.getMinute();
          if (time[x].getMinute() > minuteCheck) {
            input = false;
            errorNumber = x;
            break;
          }
        }
      }
      if (Setdate.getMinute() > 30 && Setdate.getHour() == 11) {
        if (time[x].getHour() == 12) {
          minuteCheck = Setdate.getMinute() - 30;
          if (time[x].getMinute() < minuteCheck) {
            input = false;
            errorNumber = x;
            break;
          }
        }
      }
    }
  }


  //Only allows an appointment to be scheduled if there are no time conflicts.
  if (input) {
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
  else {
    cout << "Error!!! Scheduling conflict. " << peeps[errorNumber].get_name() << "'s appointment is too close. Here is there appointment information." << endl;
    get_Appointment(peeps[errorNumber].get_name());
  }
}

void Appointment::get_Appointment(string nameInput) {
  for (int find = 0; find < amount; find++) {
    if (peeps[find].get_name() == nameInput) {
      cout << peeps[find].get_name() << "'s    \t appointment is scheduled for "
        << time[find].getHour() << ":" << time[find].getMinute() << " " << time[find].getPMorAM()
        << " on " << time[find].getMonth() << "/" << time[find].getDay() << "/" << time[find].getYear()
        << " with " << docs[find].get_Profession() << " Dr. " << docs[find].get_name() << endl;
    }
  }
}

int Appointment::get_amount() { return amount; }

Date Appointment::get_time(int index) { return time[index]; }

Patient Appointment::get_Patient(int index) { return peeps[index]; }

Doctor Appointment::get_Doctor(int index) { return docs[index]; }
