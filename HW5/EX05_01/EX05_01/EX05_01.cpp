#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename T>
int linearSearch(T[], T, int);

int main()
{
  int list[] = { 1, 4, 4, 2, 5, -3, 6, 2 };
  double list2[] = { 1.5, 2.75, 3.2, 4.8, 7.4 };
  string list3[] = { "Hello ", " my ", " name ", " is ", " Levi." };

  int i = linearSearch(list, 4, 8);
  int j = linearSearch(list2, 2.75, 5);
  int k = linearSearch(list3, string(" is "), 5);

  cout << i << "\t" << list[i] << endl;
  cout << j << "\t" <<list2[j] << endl;
  cout << k << "\t" << list3[k] << endl;
  return 0;
}

template <typename T>
int linearSearch(T list[], T key, int arraySize){
  for (int i = 0; i < arraySize; i++){
    if (key == list[i])
      return i;
  }

  return -1;
}