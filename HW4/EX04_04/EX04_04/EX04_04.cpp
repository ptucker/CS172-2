#include <iostream>
#include <cmath>
using namespace std;

class Rectangle2D {
private:
  double x, y, width, height;
public:
  Rectangle2D() {
    x = 0;
    y = 0;
    width = 1;
    height = 1;
  }
  Rectangle2D(double xset, double yset, double widthset, double heightset) {
    x = xset;
    y = yset;
    width = widthset;
    height = heightset;
  }


  const double setx(double inputx) { x = inputx; }
  const double sety(double inputy) { y = inputy; }
  const double setwidth(double inputwidth) { width = inputwidth; }
  const double setheight(double inputheight) { height = inputheight; }

  const double getx() { return x; }
  const double gety() { return y; }
  const double getwidth() { return width; }
  const double getheight() { return height; }

  const double getArea() { return x * y; }
  const double getPerimeter() { return (2 * x) + (2 * y); }

  const bool contains(double x2, double y2) {
    //Probably a more elegant way to do this but I need to finish other problems.
    if (x2 < x + (width * 0.5)) {
      if (x2 > x - (width * 0.5)) {
        if (y2 < y + (height * 0.5)) {
          if (y2 > y - (height * 0.5)) {
            return true;
          }
        }
      }
    }
    return false;
  }

  const bool contains(const Rectangle2D &r) {
    //top bottom left right
    Rectangle2D* ptr = new Rectangle2D();
    *ptr = r;
    if ((ptr->gety() + (0.5 * ptr->getheight())) < (y + (0.5 * height))) {
      if ((ptr->gety() - (0.5 * ptr->getheight())) > (y - (0.5 * height))) {
        if ((ptr->getx() - (0.5 * ptr->getwidth())) > (x - (0.5 * width))) {
          if ((ptr->getx() + (0.5 * ptr->getwidth())) < (x + (0.5 * width))) {
            return true;
          }
        }
      }
    }
    return false;
  }

  const bool overlaps(const Rectangle2D &r) {
    int overlapTest = 0;
    Rectangle2D* ptr = new Rectangle2D();
    *ptr = r;
    if ((ptr->getx() - (0.5 * ptr->getwidth())) < (x + (0.5 * width)) < (ptr->getx() + (0.5 * ptr->getwidth()))) {
      cout << "test";
      overlapTest++;
    }
    if (((ptr->getx() - (0.5 * ptr->getwidth())) < (x - (0.5 * width))) && ((x - (0.5 * width)) < (ptr->getx() + (0.5 * ptr->getwidth())))) {
      overlapTest++;
    }

    if ((ptr->gety() - (0.5 * ptr->getheight())) < (y + (0.5 * height)) && (y + (0.5 * height)) < (ptr->gety() + (0.5 * ptr->getheight()))) {
      overlapTest++;
    }
    if ((ptr->gety() - (0.5 * ptr->getheight())) < (y - (0.5 * height)) && (y - (0.5 * height)) < (ptr->gety() + (0.5 * ptr->getheight()))) {
      overlapTest++;
    }

    
    if (overlapTest > 0) {
      return true;
    }
    else {
      return false;
    }
  }
};


int main() {
  Rectangle2D Rich(0, 0, 4, 4);
  Rectangle2D Rich2(1, 1, 4, 4);
  cout << Rich.contains(Rich2) << endl;
  return 0;
}