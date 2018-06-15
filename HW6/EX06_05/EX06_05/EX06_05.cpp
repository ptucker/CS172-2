#include <iostream>
#include <string>
#include <cmath>
//a + bi + c + di = (a + c) + (b + d)i
//a + bi - (c + di) = (a -c) + (b - d)i
//(a + bi) * (c + di) = (a * c - b * d) + (b * c + a * d)i
//(a + bi) / (c + di) = (a * c + b * d) / (c * c + d * d) + (b * c - a * d) / (c * c + d * d)
using namespace std;

class Complex {
private:
  //I'm using doubles because math usually ends up using them...
  double a;
  double b;
  double c;
  double d;
public:
  Complex() {
    a = 0;
    b = 0;
  }
  Complex(double aInput, double bInput) {
    a = aInput;
    b = bInput;
  }
  Complex(double aInput) {
    a = aInput;
    b = 0;
  }

  double getRealPart() { return a; }

  //I don't know if this should be a string and return for example 5i instead of 5.
  double getImaginaryPart() { return b; }

  double add() {

  }
  double subtract() {

  }
  double multiply() {

  }
  double divide() {

  }
  double abs() {
    return sqrt(a * a + b * a);
  }
  
  double operator [](int index) {
    if (index == 0) {
      return a;
    }
    else {
      return b;
    }
  }

};

int main() {
  cout << sqrt(-1) << endl;
}