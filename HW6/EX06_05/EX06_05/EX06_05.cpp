#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
#include <iomanip>
using namespace std;

//PT -- better to separate this into its own file.
class Complex {
private:
  double a, b;
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

  string toString() {
    string i = "i";
    ostringstream doubleToStringA;
    ostringstream doubleToStringB;
    doubleToStringA << a;
    doubleToStringB << b;
    string aString = doubleToStringA.str();
    string bString = doubleToStringB.str();
    if (b == 0) {
      return aString;
    }
    return aString + " + " + bString + i;
  }

  double getRealPart() { return a; }

  //I don't know if this should be a string and return for example 5i instead of 5.
  //PT -- I think this is fine.
  double getImaginaryPart() { return b; }


  //a + bi + c + di = (a + c) + (b + d)i
  Complex add(Complex sent) {
    Complex toBeSent;
    toBeSent.a = a + sent.a;
    toBeSent.b = b + sent.b;
    return toBeSent;
  }
  //a + bi - (c + di) = (a -c) + (b - d)i
  Complex subtract(Complex sent) {
    Complex toBeSent;
    toBeSent.a = a - sent.a;
    toBeSent.b = b - sent.b;
    return toBeSent;
  }
  //(a + bi) * (c + di) = (a * c - b * d) + (b * c + a * d)i
  Complex multiply(Complex sent) {
    Complex toBeSent;
    toBeSent.a = a * sent.a - b * sent.b;
    toBeSent.b = a * sent.b + sent.a * b;
    return toBeSent;
  }
  //(a + bi) / (c + di) = (a * c + b * d) / (c * c + d * d) + (b * c - a * d) / (c * c + d * d)
  Complex divide(Complex sent) {
    Complex toBeSent;
    toBeSent.a = (a * sent.a + b * sent.b)/(sent.a * sent.a + sent.b * sent.b);
    toBeSent.b = (b * sent.a - a * sent.b) / (sent.a * sent.a + sent.b * sent.b);
    return toBeSent;
  }

  double abs() {
    return sqrt(a * a + b * b);
  }
  


  Complex operator +(const Complex& sent) {
    return add(sent);
  }
  Complex operator -(const Complex& sent) {
    return subtract(sent);
  }
  Complex operator *(const Complex& sent) {
    return multiply(sent);
  }
  Complex operator /(const Complex& sent) {
    return divide(sent);
  }

  //I thought about this for awhile and wouldn't these just be same as above???
  //If object1 + object2 above then thats like object1 = object1 + object2 here which is same?
  Complex operator +=(const Complex& sent) {
    return add(sent);
  }
  Complex operator -=(const Complex& sent) {
    return subtract(sent);
  }
  Complex operator *=(const Complex& sent) {
    return multiply(sent);
  }
  Complex operator /=(const Complex& sent) {
    return divide(sent);
  }

  //Do same thing later not sure why it's on question twice or if I'm supposed to make them do different things?
  //Complex operator [] (int index)


  Complex operator +() {
    Complex send;
    //Would just add from 0.
    send.a = a;
    send.b = b;
    return send;
  }
  Complex operator -() {
    Complex send;
    //Would just subtract from 0.
    send.a = -a;
    send.b = -b;
    return send;
  }


  //Pre increment
  Complex operator ++() {
    Complex sendIt;
    sendIt.a = ++a;
    sendIt.b = ++b;
    return sendIt;
  }
  Complex operator --() {
    Complex sendIt;
    sendIt.a = --a;
    sendIt.b = --b;
    return sendIt;
  }
  //Post increment, apparently adding int tells compiler its a post increment? Doesn't really make sense to me.
  //PT -- come visit me sometime
  Complex operator ++(int post) {
    Complex sendIt;
    sendIt.a = a++;
    sendIt.b = b++;
    return sendIt;
  }
  Complex operator --(int post) {
    Complex sendIt;
    sendIt.a = a--;
    sendIt.b = b--;
    return sendIt;
  }

  
  friend ostream& operator <<(ostream& out, const Complex& complex) {
    out << complex.a << " + " << complex.b << "i";
    return out;
  }
  friend istream& operator >>(istream& in, Complex& complex) {
    double aa;
    double bb;
    cout << "Enter complex number: ";
    in >> aa >> bb;
    complex.a = aa;
    complex.b = bb;
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
  double a, b;
  cout << "Enter the first complex number: ";
  cin >> a >> b;
  Complex object1(a, b);
  cout << "Enter the second complex number: ";
  cin >> a >> b;
  Complex object2(a, b);
  Complex temp;

  cout << fixed << setprecision(1);
  temp = object1.add(object2);
  cout << "(" << object1.toString() << ") + (" << object2.toString() << ") = " << temp << endl;

  temp = object1.subtract(object2);
  cout << "(" << object1.toString() << ") - (" << object2.toString() << ") = " << temp << endl;

  cout << fixed << setprecision(2);
  temp = object1.multiply(object2);
  cout << "(" << object1.toString() << ") * (" << object2.toString() << ") = " << temp << endl;

  cout << fixed << setprecision(4);
  temp = object1.divide(object2);
  cout << "(" << object1.toString() << ") / (" << object2.toString() << ") = " << temp.getRealPart() << " + " << fixed << setprecision(1) << temp.getImaginaryPart() << "i" << endl;

  cout << fixed << setprecision(15);
  cout << "|" << object1.toString() << "| = " << object1.abs() << endl;
}
