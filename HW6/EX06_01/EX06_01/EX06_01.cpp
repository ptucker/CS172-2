#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
  srand(static_cast<unsigned int>(time(0)));

  ofstream testFile;
  testFile.open("Exercise13_1.txt", ios::out | ios::app);
  if (testFile.fail()) {
    cout << "File does not exist." << endl;
    cout << "Exit Program." << endl;
  }
  for (int random = 0; random < 100; random++) {
    testFile << rand() % 1000 << " ";
  }
  cout << "Successful." << endl;
  testFile.close();
}