#include <iostream>

using namespace std;

int main() {
  int arraysize;
  cout << "Input array size: ";
  cin >> arraysize;


  int *x = NULL;
  x = new int[arraysize];
  cout << "Input numbers: ";
  for (int count = 0; count < arraysize; count++) {
    cin >> x[count];
  }

  int avg = 0;
  for (int add = 0; add < arraysize; add++) {
    avg += x[add];
  }
  avg = avg / arraysize;
  cout << "Average: " << avg << endl;

  int aboveaverage = 0;
  for (int test = 0; test < arraysize; test++) {
    if (x[test] > avg) aboveaverage++;
  }
  cout << "Amount of number above average: " << aboveaverage << endl;

  delete[] x;
  return (0);
}