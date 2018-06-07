#include <iostream>

using namespace std;

int main() {
  //Using 8 because book test has 8 numbers.
  int arraysize = 8;
  int* x = new int[arraysize];
  x[0] = 1;
  x[1] = 2;
  x[2] = 4;
  x[3] = 5;
  x[4] = 10;
  x[5] = 100;
  x[6] = 2;
  x[7] = -22;
  //This didn't work, I have no time to investigate.
  //x[] = { 1, 2, 4, 5, 10, 100, 2, -22 };


  //So I can compare all numbers to the last number in array.
  int smallest = arraysize - 1;
  for (int test = 0; test < arraysize; test++) {
    if (x[test] < x[smallest]) {
      smallest = test;
    }
  }
  cout << "Smallest number: " << x[smallest] << endl;
  return 0;
}