#include <iostream>
using namespace std;

class EvenNumber {
public:
  int even;
  EvenNumber() {
    even = 0;
  }
  EvenNumber(int input) {
    even = input;
  }
  int getValue() {
    return even;
  }
  int getNext() {
    return even + 2;
  }
  int getPrevious() {
    return even - 2;
  }
};

int main() {
  EvenNumber object1(16);
  cout << "Original number: " << object1.getValue() << endl;
  cout << "Next number: " << object1.getNext() << endl;
  cout << "Previous number: " << object1.getPrevious() << endl;
  return(0);
}