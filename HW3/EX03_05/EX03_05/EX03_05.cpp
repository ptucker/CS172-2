#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class MyInteger {
public:
  int value;
  MyInteger(int input) {
    value = input;
  }
  //Const functions
  int getValue() const {
    return value;
  }
  bool isEven() const {
    if (value % 2 == 0) {
      return true;
    }
    else {
      return false;
    }
  }
  bool isOdd() const{
    if (value % 2 == 0) {
      return false;
    }
    else {
      return true;
    }
  }
  bool isPrime() const{
    if (sqrt(value) * sqrt(value) == value) {
      return true;
    }
    else {
      return false;
    }
  }
  //Static in class
  static bool isEven(int input) {
    if (input % 2 == 0) {
      return true;
    }
    else {
      return false;
    }
  }
  static bool isOdd(int input) {
    if (input % 2 == 0) {
      return false;
    }
    else {
      return true;
    }
  }
  static bool isPrime(int input) {
    if (sqrt(input) * sqrt(input) == input) {
      return true;
    }
    else {
      return false;
    }
  }

  bool equals(int input) {
    if (value == input) {
      return true;
    }
    else {
      return false;
    }
  }

  int parseInt(const string& input) {
    int number = 0;
    int tempnum = 1;
    int size = input.length();
    for (int count = 0; count < size; count++) {
      tempnum = static_cast<int>(input[count]);
      tempnum -= 48;
      if (count > 0) {
        number *= 10;
        number += tempnum;
      }
      else {
        number = tempnum;
      }
    }
    return number;
  }
};

//Static call to class.
static bool isEven(const MyInteger& name);
static bool isOdd(const MyInteger& name);
static bool isPrime(const MyInteger& name);
static bool equals(const MyInteger& name);


int main() {
  int temp;
  cout << "Enter a number: ";
  cin >> temp;
  MyInteger obj1(temp);
  cout << "Even: " << isEven(obj1) << endl;
  cout << "Odd: " << isOdd(obj1) << endl;
  cout << "Prime: " << isPrime(obj1) << endl;
  int temp2;
  cout << "Enter another one: ";
  cin >> temp2;
  MyInteger obj2(temp2);
  cout << "Even: " << obj2.isEven() << endl;
  cout << "Odd: " << obj2.isOdd() << endl;
  cout << "Prime: " << obj2.isPrime() << endl;
  cout << "Equal: " << obj1.equals(obj2.getValue()) << endl;

  string toNumber;
  cout << "Enter a number: ";
  cin >> toNumber;
  cout << "Input number: " << obj1.parseInt(toNumber) << endl;
  return 0;
}


static bool isEven(const MyInteger& name) {
  if (name.getValue() % 2 == 0) {
    return true;
  }
  else {
    return false;
  }
}
static bool isOdd(const MyInteger& name) {
  if (name.getValue() % 2 == 0) {
    return false;
  }
  else {
    return true;
  }
}
static bool isPrime(const MyInteger& name) {
  if (sqrt(name.getValue()) * sqrt(name.getValue()) == name.getValue()) {
    return true;
  }
  else {
    return false;
  }
}
//Says set equal to value but value isn't a static type.
static bool equals(const MyInteger& name) {
  if (name.getValue() == 5) {
    return true;
  }
  else {
    return false;
  }
}