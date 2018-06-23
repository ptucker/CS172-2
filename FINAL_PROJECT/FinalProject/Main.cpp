#include <iostream>
#include <fstream>
#include "Date.h"
#include "Appointment.h"
#include "Doctor.h"
#include "Patient.h"
using namespace std;

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

void userIn(Appointment &appointments) {

  string docNameTemp, docProfTemp, patNameTemp, tempAMorPM;
  int tempMonth, tempDay, tempYear, tempHour, tempMinute;

  bool input = false;
  char userInput;
  cout << "Would you like to input an appointment? Enter Yes(y) or No(n):";
  cin >> userInput;
  if (userInput == 'n') {
    input = false;
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
    if (userInput == 'n') {
      input = false;
    }
  }

}



int main() {
  Appointment schedule;

  fileIn(schedule);

  userIn(schedule);
  patientFind(schedule);
  fileOut(schedule);

}