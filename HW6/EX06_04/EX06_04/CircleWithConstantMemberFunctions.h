#ifndef CIRCLE_H
#define CIRCLE_H

class Circle {
public:
  Circle();
  Circle(double);
  double getArea() const;
  double getRadius() const;
  void setRadius(double);
  static int getNumberOfObjects();
  bool operator < (const Circle&) const;
  bool operator <= (const Circle&) const;
  bool operator == (const Circle&) const;
  bool operator != (const Circle&) const;
  bool operator >= (const Circle&) const;
  bool operator > (const Circle&) const;
private:
  double radius;
  static int numberOfObjects;
};
#endif
