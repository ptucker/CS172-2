#include <iostream>

using namespace std;

class Fan {
public:
  //Could be in private because of mutators and
  //accessors but question didn't specify.
  int speed;
  bool on;
  double radius;
  Fan() {
    speed = 1;
    on = true;
    radius = 5.0;
  }
  Fan(int input, bool setStatus, double inputrad) {
    speed = input;
    on = setStatus;
    radius = inputrad;
  }
  //All accessors
  int getSpeed() {
    return speed;
  }
  bool getOn() {
    return on;
  }
  double getRadius() {
    return radius;
  }
  //All mutators
  int setSpeed(int inputSpeed) {
    speed = inputSpeed;
  }
  bool setOn(bool setStatus) {
    on = setStatus;
  }
  double setRadius(double inputRadius) {
    radius = inputRadius;
  }
};

int main() {
  Fan def();
  Fan one(3, true, 10);
  Fan two(2, false, 5);
  cout << "Fan one status: ";
  if (one.getOn()) {
    cout << "On" << endl;
  }
  else {
    cout << "Off" << endl;
  }
  cout << "Fan one speed: " << one.getSpeed() << endl;
  cout << "Fan one radius: " << one.getRadius() << endl;

  cout << endl;

  cout << "Fan two status: ";
  if (two.getOn()) {
    cout << "On" << endl;
  }
  else {
    cout << "Off" << endl;
  }
  cout << "Fan two speed: " << two.getSpeed() << endl;
  cout << "Fan two radius: " << two.getRadius() << endl;
  return(0);
}