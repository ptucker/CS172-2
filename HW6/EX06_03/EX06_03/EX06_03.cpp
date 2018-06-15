#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class FindBaby {
private:
  int year;
  string name;
  char gender;
  int rank;
  static int amountOfPeople;
public:
  FindBaby(int yearinput, string nameinput, char genderinput, int rankinput) {
    year = yearinput;
    name = nameinput;
    gender = genderinput;
    rank = rankinput;
    amountOfPeople++;
  }

  int getAmountOfPeople() { return amountOfPeople; }

  int getRank() {return rank;}
  string getName() { return name; }
  bool testName(string nametoTest) {
    if (nametoTest == name) {
      return true;
    }
    else {
      return false;
    }
  }
};

int FindBaby::amountOfPeople = 0;



void nameToRank(vector<FindBaby>& baby2, string isThisTheName, string year) {
  int runtime = baby2[0].getAmountOfPeople();
  bool foundperson = false;
  for (int operationFindBaby = 0; operationFindBaby < runtime; operationFindBaby++) {
    if (baby2[operationFindBaby].getName() == isThisTheName) {
      foundperson = true;
      cout << baby2[operationFindBaby].getName() << " is ranked #" << baby2[operationFindBaby].getRank() << " in year " << year << endl;
      break;
    }
  }

  if (foundperson == false) {
    cout << "The name " << isThisTheName << " is not ranked in year " << year << endl;
  }

}

void inputNamesIntoVectorClass(ifstream &baby, string year, vector<FindBaby>& finder) {

  while (baby.good()) {
    int yearSend = stoi(year);
    int rankSend;
    string nameSend, temp;
    char tempchar;


    //Gets input for male names and rank.
    baby >> rankSend >> nameSend >> temp;
    FindBaby *tempSend = new FindBaby(yearSend, nameSend, 'M', rankSend);
    finder.push_back(*tempSend);
    delete tempSend;


    //Keeps rank from male and gets female name.
    baby >> nameSend >> temp;
    FindBaby *tempSend2 = new FindBaby(yearSend, nameSend, 'F', rankSend);
    finder.push_back(*tempSend2);
    delete tempSend2;
  }
}


int main() {
  string year;

  cout << "Enter the year:";
  cin >> year;

  ifstream baby;
  baby.open("Babynameranking" + year + ".txt");

  if (!baby.is_open()) {
    cout << "File not found." << endl;
  }



  vector<FindBaby> babyNames;
  inputNamesIntoVectorClass(baby, year, babyNames);


  char whyDoWeNeedGender;
  string nameToTest;
  cout << "Enter the gender:";
  cin >> whyDoWeNeedGender;
  cout << "Enter the name:";
  cin >> nameToTest;

  nameToRank(babyNames, nameToTest, year);
  baby.close();
}