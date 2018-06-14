#include <iostream>
#include <string>
using namespace std;

// 16/20

template<typename T>
class vector {
private:
  T * data;
  int amount;
  //PT -- need to also track the size of the memory allocated. amount keeps track of the number of items, which is different.
public:
  vector() {
    data = new T[0];
    amount = 0;
  }
  vector(int sizeInput) {
    data = new T[sizeInput];
    amount = sizeInput;
  }
  ~vector() {
    delete[] data;
  }

  //After research they call this a subscript operator function.
  //I'm not sure if I should already know this by now but I do now...
  //PT -- good.
  T &operator[](int index) {
    return data[index];
  }


  void push_back(T input) {
    T* temp = data;
    //PT -- you shouldn't always need to re-allocate the buffer. That's inefficient.
    // -2
    data = new T[++amount];
    //To save steps I inremented amount so I have to -1 for amount.
    for (int inputData = 0; inputData < amount - 1; inputData++) {
      data[inputData] = temp[inputData];
    }
    data[amount - 1] = input;
    delete[] temp;
  }


  void pop_back() {
    T* temp = data;
    //PT -- you shouldn't always need to re-allocate the buffer. That's inefficient.
    // -2
    data = new T[--amount];
    for (int inputData = 0; inputData < amount; inputData++) {
      data[inputData] = temp[inputData];
    }
    delete[] temp;
  }


  unsigned const int size() { return amount; }


  const T at(int location) { return data[location]; }


  const bool empty() {
    if (amount == 0) {
      return true;
    }
    else {
      return false;
    }
  }

  void clear() {
    amount = 0;
    data = NULL;
  }

  void swap(vector& swapee) {
    T* temp = data;
    T* temp2 = swapee.data;
    data = new T[swapee.amount];
    for (int inputData = 0; inputData < swapee.amount; inputData++) {
      data[inputData] = temp2[inputData];
    }
    swapee.data = new T[amount];
    for (int inputData = 0; inputData < amount; inputData++) {
      swapee.data[inputData] = temp[inputData];
    }
    delete[] temp;
    delete[] temp2;
    //Assign new amount values.
    int tempAmt = amount;
    int* swapeeChange = &swapee.amount;
    amount = swapee.amount;
    *swapeeChange = tempAmt;
  }


};

int main() {
  //Testing to see if my Vector Class works like library one.
  vector<int> testingVec;
  for (int input = 1; input < 6; input++) {
    testingVec.push_back(input);
  }
  for (int input = 0; input < 5; input++) {
    cout << testingVec.at(input) << endl;
  }
  testingVec.pop_back();
  cout << "Popped" << endl;
  for (int input = 0; input < 5; input++) {
    cout << testingVec.at(input) << endl;
  }
  cout << "Vec size should be 4 after pop: "<< testingVec.size() << endl;

  vector<int> testingVec2;
  cout << "Vec1 size " << testingVec.size() << " Vec2 size " << testingVec2.size() << endl;
  cout << "Commencing swap..." << endl;
  testingVec.swap(testingVec2);
  cout << "Vec1 size " << testingVec.size() << " Vec2 size " << testingVec2.size() << endl;

  //Creates string vector with a size of 2.
  vector<string> stringVector(2);
  stringVector[0] = "Hello ";
  stringVector[1] = "world.";
  cout << stringVector[0] << stringVector[1] << endl;

}
