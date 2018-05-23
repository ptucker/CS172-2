#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cmath>
using namespace std;
//EX01_01
/*
a) When a program runs on a computer, the part of the computer that carries out the instructions is called the ___CPU______ .
b) When a program runs on a computer, it is stored in __RAM_(Main Memory)______ .
c) When a program is not running, it is stored ----Answer: i) on a disk
    i) on a disk
    ii) in level-2 cache (L2)
    iii) in main memory
    iv) on the Ethernet or wi-fi
d) a bit is ----Answer: v) a binary digit, like 0 or 1
    i) a metalic rod inserted into a horses mouth to control it while riding.
    ii) a small amount of data.
    iii) an alternative term for byte.
    iv) an electronic device used in computers.
    v) a binary digit, like 0 or 1
e) A byte in memory is identified by a unique number called its __Address____ .
f) In modern computer systems, a byte consists of ___8___ bits.
g) An operating system ----Answer: v) all of the above
    i) is the chief hardware unit in a computer.
    ii) is loaded into the computer each time it needs to carry out an operation.
    iii) ensures that programs will not run on the computer at the same time.
    iv) allocates resources like memory to programs that are running
    v) all of the above
h) Application software ----Answer: ii) is any software that is runs with the support of the operating system.
    i) processes applications for jobs, school admission, etc.
    ii) is any software that is runs with the support of the operating system.
    iii) was invented by Microsoft.
    iv) is applied to the computer for the purpose of running the operating system.
    v) none of the above

*/

void ex02();
void ex03();
void ex04();
int ex04Double(int dbl);
int add(int input1, int input2);
int addone(int &input);
void ex05();
void ex05ArrayPass(int array[], int size);
void ex05ArrayCheck(int array[], int size);
int main() {
  srand(static_cast<unsigned int>(time(0)));
  ex02();
  ex03();
  ex04();
  ex05();
  return(0);
}

void ex02() {
  bool hasPassedTest = true;
  int x = (rand() % 100) + 1;
  int y = (rand() % 100) + 1;

  if (x >= y) {
    cout << "x is greater than or equal to y." << endl;
  }

  int numberOfShares;
  cout << "Input numberOfShares: ";
  cin >> numberOfShares;
  if (numberOfShares < 100) {
    cout << "numberOfShares is less than 100." << endl;
  }
  else {
    cout << "numberOfShares is greater than 100." << endl;
  }

  int boxWidth, bookWidth;
  cout << "Input box width: ";
  cin >> boxWidth;
  cout << "Input book width: ";
  cin >> bookWidth;
  if (boxWidth % bookWidth == 0) {
    cout << "Box width is evenly divisible by the book width." << endl;
  }

  int shelfLife;
  int temperature;
  cout << "Input shelf life of box of chocolates: ";
  cin >> shelfLife;
  cout << "Input outside temperature: ";
  cin >> temperature;
  if (temperature > 90) {
    shelfLife -= 4;
  }
}

void ex03() {
  int area;
  char response;
  cout << "Input area: ";
  cin >> area;
  cout << "Length is " << sqrt(area) << endl;
  cout << "Diagonal is " << fixed
       << setprecision(2) << sqrt(area + area) << endl;

  cout << "Enter Yes(y) or no(n): ";
  cin >> response;
  if (response == 'y') {
    cout << "yes" << endl;
  }
  if (response == 'n') {
    cout << "no" << endl;
  }

  char tab = '\t';
  string mailingAddress;
  string emptyString = mailingAddress;
  cout << "Enter mailing Address: ";
  cin.ignore();
  getline(cin, mailingAddress);
}

void ex04() {
  int usernumber;
  cout << "Enter a number between 1 and 10: ";
  cin >> usernumber;
  while (usernumber < 1 || usernumber > 10) {
    cout << "Enter a valid input: ";
    cin >> usernumber;
  } 
  
  for (int cube = 1; cube <= usernumber; cube++) {
    cout << cube * cube * cube << endl;
  }

  int count = 0;
  do {
    cout << "*";
    count++;
  } while (usernumber > count + 1);
  cout << endl;

  for (int even = 0; even <= 40; even++) {
    if (even % 2 == 0) {
      cout << even << endl;
    }
  }

  cout << "User input doubled: ";
  cout << ex04Double(usernumber) << endl;

  int randnumber1 = rand();
  int randnumber2 = rand();
  cout << add(randnumber1, randnumber2) << endl;
}

int ex04Double(int dbl) {
  return dbl * 2;
}

int add(int input1, int input2) {
  return input1 + input2;
}

int addone(int &input) {
  return ++input;
}

void ex05() {
  int inputs[5];
  cout << "Input 5 numbers : ";
  for (int count = 0; count < 5; count++) {
    cin >> inputs[count];
  }

  int sum = 0;
  //unsigned because always positive
  //and allows bigger numbers to be entered without error
  unsigned int product = 1;
  for (int count = 0; count < 5; count++) {
    sum += inputs[count];
  }
  for (int count = 0; count < 5; count++) {
    product *= inputs[count];
  }
  cout << "Sum of numbers: " << sum << endl;
  cout << "Product of numbers: " << product << endl;

  ex05ArrayPass(inputs, 5);
  ex05ArrayCheck(inputs, 5);
}

void ex05ArrayPass(int array[], int size) {
  for (int count = 0; count < size; count++) {
    cout << array[count] << endl;
  }
}

void ex05ArrayCheck(int array[], int size) {
  int check;
  bool isThere = false;
  cout << "Enter a number: ";
  cin >> check;
  for (int count = 0; count < size; count++) {
    if (check == array[count]) {
      isThere = true;
    }
  }
  if (isThere) {
    cout << check << " is in the array." << endl;
  }
  else {
    cout << check << " is NOT in the array." << endl;
  }
}