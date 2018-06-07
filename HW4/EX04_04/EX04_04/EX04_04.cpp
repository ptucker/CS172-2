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

  const double getArea() { return width * height; }
  const double getPerimeter() { return (2 * width) + (2 * height); }

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
    //This hurts me on the inside, but it's the only way I can think of right now.
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
    //I got stuck on this for 45 minutes and realized I was still calling contains instead of overlaps...
    //Coding standards in cs171 said to use 75 characters max but most screens we use now
    //can output over 150 characters and I think splitting these if statements into 75 characters would
    //make it very hard to read.

    //These if statements test if a side of a rectangle is between the two sides on another rectangle.
    //If they are overlapping 2 lines have to cross which is why I set overlapTest == 2 in end to output true.
    if ((ptr->getx() - (0.5 * ptr->getwidth())) < (x + (0.5 * width)) &&
                                                  (x + (0.5 * width)) < (ptr->getx() + (0.5 * ptr->getwidth()))) {
      overlapTest++;
    }
    if ((ptr->getx() - (0.5 * ptr->getwidth())) < (x - (0.5 * width)) &&
                                                  (x - (0.5 * width)) < (ptr->getx() + (0.5 * ptr->getwidth()))) {
      overlapTest++;
    }

    if ((ptr->gety() - (0.5 * ptr->getheight())) < (y + (0.5 * height)) &&
                                                   (y + (0.5 * height)) < (ptr->gety() + (0.5 * ptr->getheight()))) {
      overlapTest++;
    }
    if ((ptr->gety() - (0.5 * ptr->getheight())) < (y - (0.5 * height)) &&
                                                   (y - (0.5 * height)) < (ptr->gety() + (0.5 * ptr->getheight()))) {
      overlapTest++;
    }

    //For overlap to happen 2 of these have to be true if 1, 3, or 4 are
    //output it either isn't a rectangle anymore or a weird bug.
    if (overlapTest == 2) {
      return true;
    }
    else {
      return false;
    }
  }
};


int main() {
  Rectangle2D Rich(0, 0, 2, 4);
  Rectangle2D Rich2(1, 1, 4, 4);
  cout << Rich.getArea() << endl;
  return 0;
}