#include <iostream>
#include <string>
using namespace std;

string sort(string& s);

int main() {
  string input;
  cout << "Enter a string s: ";
  getline(cin, input);
  sort(input);
  cout << "The sorted string is " << input << endl;
  return 0;
}

string sort(string& s) {
  int stringLength = s.length();
  string tempstring = "";
  char tempchar;
  for (int letter = 97; letter < 123; letter++) {
    tempchar = letter;
    for (int stringCheck = 0; stringCheck < stringLength; stringCheck++) {
      if (s[stringCheck] == letter) {
        tempstring += tempchar;
      }
    }
  }
  s = tempstring;
  return s;
}