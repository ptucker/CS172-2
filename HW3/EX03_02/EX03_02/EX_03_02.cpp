#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

class QuadraticEquation {
public:
  //Question doesn't specify if decimals will be input
  //but math usually has decimals so I used double.
  double a;
  double b;
  double c;
  QuadraticEquation(double ainput, double binput, double cinput) {
    a = ainput;
    b = binput;
    c = cinput;
  }
  double getA() {
    return a;
  }
  double getB() {
    return b;
  }
  double getC() {
    return c;
  }

  double getDiscriminant() {
    return (b * b) - (4 * a * c);
  }
  double getRoot1() {
    if (getDiscriminant() < 0) {
      return 0;
    }
    else {
      return ((-b) + sqrt(getDiscriminant())) / (2 * a);
    }
  }
  double getRoot2() {
    if (getDiscriminant() < 0) {
      return 0;
    }
    else {
      return ((-b) - sqrt(getDiscriminant())) / (2 * a);
    }
  }
};

int main() {
  double a;
  double b;
  double c;
  cout << "Enter a value for a, b and c: ";
  cin >> a >> b >> c;
  QuadraticEquation test(a, b, c);
  if (test.getDiscriminant() == 0) {
    cout << "r = " << test.getRoot1() << endl;
  }
  if (test.getDiscriminant() > 0) {
    cout << "r1 = " << test.getRoot1() << endl;
    cout << "r2 = " << test.getRoot2() << endl;
  }
  if (test.getDiscriminant() < 0) {
    cout << "The equation has no real roots." << endl;
  }
  return(0);
}