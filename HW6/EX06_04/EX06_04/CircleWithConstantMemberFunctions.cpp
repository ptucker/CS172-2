#include "CircleWithConstantMemberFunctions.h"

int Circle::numberOfObjects = 0;

//Construct a circle object
Circle::Circle() {
  radius = 1;
  numberOfObjects++;
}

//Construct a circle object
Circle::Circle(double newRadius) {
  radius = newRadius;
  numberOfObjects++;
}

//Return the area of this cirlce
double Circle::getArea() const{
  return radius * radius * 3.14159;
}

double Circle::getRadius() const{
  return radius;
}

//Set a new radius
void Circle::setRadius(double newRadius) {
  radius = (newRadius >= 0) ? newRadius : 0;
}

//Return the number of circle objects
int Circle::getNumberOfObjects() {
  return numberOfObjects;
}

//Not sure if we need to make functions with all operators, question didn't specify
bool Circle::operator < (const Circle& thisRad) const{
  if (radius < thisRad.getRadius()) {
    return true;
  }
  else {
    return false;
  }
}

bool Circle::operator <= (const Circle& thisRad) const {
  if (radius <= thisRad.getRadius()) {
    return true;
  }
  else {
    return false;
  }
}

bool Circle::operator == (const Circle& thisRad) const {
  if (radius == thisRad.getRadius()) {
    return true;
  }
  else {
    return false;
  }
}

bool Circle::operator != (const Circle& thisRad) const {
  if (radius != thisRad.getRadius()) {
    return true;
  }
  else {
    return false;
  }
}

bool Circle::operator >= (const Circle& thisRad) const {
  if (radius >= thisRad.getRadius()) {
    return true;
  }
  else {
    return false;
  }
}

bool Circle::operator > (const Circle& thisRad) const {
  if (radius > thisRad.getRadius()) {
    return true;
  }
  else {
    return false;
  }
}