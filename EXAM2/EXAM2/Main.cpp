//I affirm that all code given below was written solely by me, Levi, and that any
//help I received adhered to the rules stated for this exam.

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include "Runner.h"
using namespace std;
int amountOfRunners = 0;

//Inputs all names from file into vector.
void nameToVector(ifstream &runners, vector<Runner> &peoplePass) {
  string tempFirst;
  string tempLast;
  int tempPace;
  while (runners.good()) {
    amountOfRunners++;
    runners >> tempFirst >> tempLast >> tempPace;
    Runner* temp = new Runner(tempFirst, tempLast, tempPace);
    peoplePass.push_back(*temp);
  }
}


void vectorSort(vector<Runner> &peoplePass) {
  vector<Runner> sortPeople;

  //Inputs fastest people into new vector.
  for (int bounds = 0; bounds <= 1200; bounds++) {
    for (int inputPeople = 0; inputPeople < amountOfRunners - 1; inputPeople++) {
      if (peoplePass[inputPeople].get_pace() == bounds) {
        Runner* temp = new Runner (peoplePass[inputPeople]);
        sortPeople.push_back(*temp);
      }
    }
  }

  //Copys new vector to the reference one.
  for (int inputPeople = 0; inputPeople < amountOfRunners - 1; inputPeople++) {
      peoplePass[inputPeople] = sortPeople[inputPeople];
  }
}

//Inputs the names into each file based on pace(In order as long as vectorSort is called first).
void fileInput(vector<Runner> peoplePass) {
  fstream outWhite;
  outWhite.open("white.txt", ios::out | ios::trunc);
  fstream outYellow;
  outYellow.open("yellow.txt", ios::out | ios::trunc);
  fstream outGreen;
  outGreen.open("green.txt", ios::out | ios::trunc);
  fstream outOrange;
  outOrange.open("orange.txt", ios::out | ios::trunc);
  fstream outBlue;
  outBlue.open("blue.txt", ios::out | ios::trunc);
  fstream outLilac;
  outLilac.open("lilac.txt", ios::out | ios::trunc);
  fstream outRed;
  outRed.open("red.txt", ios::out | ios::trunc);

  string tempFirst;
  string tempLast;

  for (int input = 0; input < amountOfRunners - 1; input++) {

    //Input all names for white class
    if (peoplePass[input].get_pace() >= 0 && peoplePass[input].get_pace() <= 360) {
      tempFirst = peoplePass[input].get_firstname();
      tempLast = peoplePass[input].get_lastname();
      outWhite << tempFirst << " " << tempLast << endl;
    }
    //Input all names for yellow class
    if (peoplePass[input].get_pace() >= 361 && peoplePass[input].get_pace() <= 420) {
      tempFirst = peoplePass[input].get_firstname();
      tempLast = peoplePass[input].get_lastname();
      outYellow << tempFirst << " " << tempLast << endl;
    }
    //Input all names for green class
    if (peoplePass[input].get_pace() >= 421 && peoplePass[input].get_pace() <= 480) {
      tempFirst = peoplePass[input].get_firstname();
      tempLast = peoplePass[input].get_lastname();
      outGreen << tempFirst << " " << tempLast << endl;
    }
    //Input all names for orange class
    if (peoplePass[input].get_pace() >= 481 && peoplePass[input].get_pace() <= 540) {
      tempFirst = peoplePass[input].get_firstname();
      tempLast = peoplePass[input].get_lastname();
      outOrange << tempFirst << " " << tempLast << endl;
    }
    //Input all names for blue class
    if (peoplePass[input].get_pace() >= 541 && peoplePass[input].get_pace() <= 600) {
      tempFirst = peoplePass[input].get_firstname();
      tempLast = peoplePass[input].get_lastname();
      outBlue << tempFirst << " " << tempLast << endl;
    }
    //Input all names for lilac class
    if (peoplePass[input].get_pace() >= 601 && peoplePass[input].get_pace() <= 720) {
      tempFirst = peoplePass[input].get_firstname();
      tempLast = peoplePass[input].get_lastname();
      outLilac << tempFirst << " " << tempLast << endl;
    }
    //Input all names for red class
    if (peoplePass[input].get_pace() >= 721 && peoplePass[input].get_pace() <= 1200) {
      tempFirst = peoplePass[input].get_firstname();
      tempLast = peoplePass[input].get_lastname();
      outRed << tempFirst << " " << tempLast << endl;
    }

    //Outputs warning if a runners pace was entered incorrectly.
    if (peoplePass[input].get_pace() < 0 || peoplePass[input].get_pace() > 1200) {
      cout << "WARNING!!! pace for runner " << input + 1 << " is out of bounds." << endl;
    }

  }
  cout << amountOfRunners << " runner's names were succesfully sorted." << endl;
}

int main() {
  vector<Runner> people;
  ifstream runners;
  runners.open("registrants.txt");

  if (!runners.is_open()) {
    cout << "File not found." << endl;
  }

  nameToVector(runners, people);
  vectorSort(people);
  fileInput(people);
}