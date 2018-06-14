#include <iostream>
#include <string>
using namespace std;

// 17/20

template <typename T>
bool isSorted(const T list[], int size);

int main() {
  int k[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  cout << isSorted(k, 9) << endl;
  double l[] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9 };
  cout << isSorted(l, 9) << endl;
  //Only looks at first letter, will try to fix later.
  string j[] = { "az ", "cz ", "d ", "e" };
  cout << isSorted(j, 4) << endl;
}

template <typename T>
bool isSorted(const T list[], int size) {

  for (int sorted = 0; sorted < size - 1; sorted++) {
    T highest;
    highest = list[sorted];
    //PT -- this should work for strings, too, since string supports >
    // -3
    //Could use this and for loop to sort after first letter, but don't have time to implement.
    if (typeid(T) == typeid(string)) {
      cout << "Sort string (Idk what to sort by)" << endl;
    }
    if (highest > list[sorted + 1]) {
      return false;
    }

  }
  return true;
}
