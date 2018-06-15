#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

int main() {
  char filename[50];
  ifstream characters;
  cin.getline(filename, 50);
  characters.open(filename);

  if (!characters.is_open()) {
    cout << "File not found." << endl;
  }
  char temp;
  int total = 0;
  while (characters >> temp) {
    total++;
  }
  cout << "Number of characters: " << total << endl;
}