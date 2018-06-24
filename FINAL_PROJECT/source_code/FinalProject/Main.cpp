#include <iostream>
#include <fstream>
#include "Date.h"
#include "Appointment.h"
#include "Doctor.h"
#include "Patient.h"
using namespace std;

//Outputs appointment class to a file to save appointments.
void fileOut(Appointment &appointments) {
  fstream outAppointments;
  outAppointments.open("Appointments.txt", ios::out | ios::trunc);
  for (int out = 0; out < appointments.get_amount(); out++) {
    Date * tempDate = new Date(appointments.get_time(out));
    Patient * tempPat = new Patient(appointments.get_Patient(out));
    Doctor * tempDoc = new Doctor(appointments.get_Doctor(out));
    outAppointments << tempPat->get_name() << " "
                    << tempDate->getMonth() << " " << tempDate->getDay() << " " << tempDate->getYear() << " "
                    << tempDate->getHour() << " " << tempDate->getMinute() << " " << tempDate->getPMorAM() << " "
                    << tempDoc->get_name() << " " << tempDoc->get_Profession() << endl;
  }
}

//Inputs appointments stored in program into appointment class.
void fileIn(Appointment &appointments) {

  string docNameTemp, docProfTemp, patNameTemp, tempAMorPM;
  int tempMonth, tempDay, tempYear, tempHour, tempMinute;

  fstream inAppointments;
  inAppointments.open("Appointments.txt", ios::in);
  int x = 0;
  while(inAppointments.good()) {
    patNameTemp = "";
    inAppointments >> patNameTemp >> tempMonth >> tempDay >> tempYear >> tempHour >> tempMinute >> tempAMorPM >> docNameTemp >> docProfTemp;
    if (patNameTemp == "") {
      break;
    }
    Doctor * docTemp = new Doctor(docNameTemp);
    docTemp->set_Profession(docProfTemp);
    Patient * patTemp = new Patient(patNameTemp);
    Date * dateTemp = new Date(tempMonth, tempDay, tempYear, tempHour, tempMinute, tempAMorPM);
    appointments.set_Appointment(*patTemp, *docTemp, *dateTemp);
    x++;
    delete docTemp;
    delete patTemp;
    delete dateTemp;
  }

}

//Allows user to search for a patients appointment.
void patientFind(Appointment &appointments) {
  string name;
  bool search = false;
  char userinput;
  cout << "Would you like to search for a patient's appointment? Enter Yes(y) or No(n): ";
  cin >> userinput;
  if (userinput == 'y') {
    search = true;
  }
  while (search) {
    cout << "Enter patients name:";
    cin >> name;
    appointments.get_Appointment(name);
    cout << "Would you like to search for another patient's appointment? Enter Yes(y) or No(n): ";
    cin >> userinput;
    if (userinput == 'n') {
      search = false;
    }
  }
}

//Allows user to create an appointment.
void userIn(Appointment &appointments) {

  string docNameTemp, docProfTemp, patNameTemp, tempAMorPM;
  int tempMonth, tempDay, tempYear, tempHour, tempMinute;

  bool input = false;
  char userInput;
  cout << "Would you like to input an appointment? Enter Yes(y) or No(n):";
  cin >> userInput;
  if (userInput == 'y' || userInput == 'Y') {
    input = true;
  }
  while (input) {
    cout << "Input Patient's name: ";
    cin >> patNameTemp;
    cout << "Input Doctor's name: ";
    cin >> docNameTemp;
    cout << "Input Doctor's Profession: ";
    cin >> docProfTemp;
    cout << "Input MM/DD/YYYY: ";
    cin >> tempMonth >> tempDay >> tempYear;
    cout << "Input time HH MM: ";
    cin >> tempHour >> tempMinute;
    cout << "AM or PM: ";
    cin >> tempAMorPM;

    Doctor * docTemp = new Doctor(docNameTemp);
    docTemp->set_Profession(docProfTemp);
    Patient * patTemp = new Patient(patNameTemp);
    Date * dateTemp = new Date(tempMonth, tempDay, tempYear, tempHour, tempMinute, tempAMorPM);
    appointments.set_Appointment(*patTemp, *docTemp, *dateTemp);
    delete docTemp;
    delete patTemp;
    delete dateTemp;

    cout << "Would you like to input another appointment? Enter Yes(y) or No(n):";
    cin >> userInput;
    if (userInput == 'n' || userInput == 'N') {
      input = false;
    }
  }

}

//Outputs appointments in order that are within 2 weeks of realtime.
void appointmentOrderOutput(Appointment &appointments) {
  Appointment * temp = new Appointment(appointments);
  Date now;
  vector<int> order(appointments.get_amount());
  //Tests if there are any appointments scheduled for years ahead because
  //it takes a lot of time to go through for loops ahead if you go through it multiple times
  //so if appointments are only scheduled for a certain year then it cuts down calculation time.
  int max = now.getYear();
  for (int yearStart = now.getYear(); yearStart <= now.getYear() + 10; yearStart++) {
    for (int index = 0; index < appointments.get_amount(); index++) {
      Date * temp = new Date(appointments.get_time(index));
      if (temp->getYear() == yearStart) {
        max = yearStart;
      }
    }
  }


  int difference = max - now.getYear();
  int orderNum = 0;
  //Very unefficient way at finding order of appointments.
  for (int year = now.getYear(); year <= now.getYear() + difference; year++) {
    for (int month = 1; month <= 12; month++) {
      for (int day = 1; day <= 30; day++) {
        for (int hour = 1; hour <= 12; hour++) {
          for (int minute = 1; minute < 60; minute++) {
            for (int check = 0; check < appointments.get_amount(); check++) {
              Date * temp = new Date(appointments.get_time(check));
              if (temp->getMonth() == month && temp->getDay() == day && temp->getHour() == hour && temp->getMinute() == minute) {
                order[check] = orderNum;
                orderNum++;
              }
            }
          }
        }
      }
    }
  }

  //Calculates and puts which appointments that are less than 2 weeks away into a bool vector.
  Date realTime;
  vector<bool> output(appointments.get_amount());
  for (int zero = 0; zero < appointments.get_amount(); zero++) {
    output[zero] = 0;
  }
  int isItThatTypeOfMonth;
  int dayTemp = -1;
  for (int index = 0; index < appointments.get_amount(); index++) {
    Date * tempDate = new Date(appointments.get_time(index));

    //Accounds for months that have 30 or 31 days.
    //July and august have 31 days which messes up % 2...
    if (realTime.getMonth() == 1 ||
        realTime.getMonth() == 3 ||
        realTime.getMonth() == 5 ||
        realTime.getMonth() == 7 ||
        realTime.getMonth() == 8 ||
        realTime.getMonth() == 10 ||
        realTime.getMonth() == 12) {
      isItThatTypeOfMonth = 1;
    }
    else {
      isItThatTypeOfMonth = 0;
    }
    if (realTime.getMonth() == 2) {  //Because of february 
      isItThatTypeOfMonth = -2;
    }
    if (realTime.getMonth() == 2 && realTime.getYear() % 4 == 0) {  //For leap years (Should be fine until 2100)
      isItThatTypeOfMonth = -1;
    }


    if (realTime.getDay() > 16) {
      dayTemp = isItThatTypeOfMonth + 30 - realTime.getDay();
      if (realTime.getMonth() + 1 == tempDate->getMonth() && tempDate->getDay() <= dayTemp) {
        output[index] = 1;
      }
      if (realTime.getMonth() == tempDate->getMonth() && tempDate->getDay() >= realTime.getDay()) {
        output[index] = 1;
      }
    }
    if (realTime.getDay() <= 16) {
      dayTemp = realTime.getDay() + 14;
      if (realTime.getMonth() == tempDate->getMonth() && tempDate->getDay() < dayTemp) {
        output[index] = 1;
      }
    }
    delete tempDate;
  }

  //Outputs appointments in order, but only if they are less than 2 weeks away.
  for (int replace = 0; replace < orderNum; replace++) {
    for (int index = 0; index < appointments.get_amount(); index++) {
      if (order[index] == replace && output[index] == true) {
        Patient * temp2 = new Patient(temp->get_Patient(index));
        temp->get_Appointment(temp2->get_name());
      }
    }
  }


  delete temp;
}


int main() {
  //Creates an object for the appointment class.
  //You could create a vector with object type Appointment
  //and just use different objects as different offices.
  Appointment schedule;
  fileIn(schedule);
  userIn(schedule);
  patientFind(schedule);
  appointmentOrderOutput(schedule);
  fileOut(schedule);
}