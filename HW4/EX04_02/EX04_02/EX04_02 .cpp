#include <iostream>

using namespace std;

int* doubleCapacity(const int* list, int size);

int main() {
  int originalArray[5] = {1, 2 ,3 ,4 ,5};
  int* x = originalArray;
  for (int set = 0; set < 5; set++) {
    x[set] = 1;
  }

  x = doubleCapacity(x, 5);

  for (int set2 = 5; set2 < 10; set2++) {
    x[set2] = 2;
  }

  for (int out = 0; out < 10; out++) {
    cout << x[out] << endl;
  }

  delete[] x;
  return 0;
}

int* doubleCapacity(const int* list, int size) {
  int* biggerbuddy = new int[2 * size];
  for (int input = 0; input < size; input++) {
    biggerbuddy[input] = list[input];
  }
  list = biggerbuddy;
  return biggerbuddy;
}