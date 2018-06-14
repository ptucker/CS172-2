#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

// 20/20

template <typename T>
void shuffle(vector<T>& v);

int main() {
  srand(static_cast<unsigned int>(time(0)));


  vector<int> rondaldMcdonald(10);
  for (int input = 0; static_cast<unsigned int>(input) < rondaldMcdonald.size(); input++) {
    rondaldMcdonald[input] = input + 1;
  }


  for (int output = 0; static_cast<unsigned int>(output) < rondaldMcdonald.size(); output++) {
    cout << rondaldMcdonald[output] << endl;
  }

  cout << "Shuffling..." << endl;
  shuffle(rondaldMcdonald);

  for (int output = 0; static_cast<unsigned int>(output) < rondaldMcdonald.size(); output++) {
    cout << rondaldMcdonald[output] << endl;
  }
  cout << endl;

  cout << "Large states string test:" << endl;
  cout << endl;
  string states[] = { "Alaska",
    "Alabama",
    "Arkansas",
    "American Samoa",
    "Arizona",
    "California",
    "Colorado",
    "Connecticut",
    "District of Columbia",
    "Delaware",
    "Florida",
    "Georgia",
    "Guam",
    "Hawaii",
    "Iowa",
    "Idaho",
    "Illinois",
    "Indiana",
    "Kansas",
    "Kentucky",
    "Louisiana",
    "Massachusetts",
    "Maryland",
    "Maine",
    "Michigan",
    "Minnesota",
    "Missouri",
    "Mississippi",
    "Montana",
    "North Carolina",
    " North Dakota",
    "Nebraska",
    "New Hampshire",
    "New Jersey",
    "New Mexico",
    "Nevada",
    "New York",
    "Ohio",
    "Oklahoma",
    "Oregon",
    "Pennsylvania",
    "Puerto Rico",
    "Rhode Island",
    "South Carolina",
    "South Dakota",
    "Tennessee",
    "Texas",
    "Utah",
    "Virginia",
    "Virgin Islands",
    "Vermont",
    "Washington",
    "Wisconsin",
    "West Virginia",
    "Wyoming" };
  vector<string> test;
  for (int sorting = 0; sorting < 54; sorting++) {
    test.push_back(states[sorting]);
  }
  for (int sorting = 0; sorting < test.size(); sorting++) {
    cout << test[sorting] << endl;
  }
  cout << endl;
  cout << endl;
  cout << "Shuffling..." << endl;
  cout << endl;
  cout << endl;
  shuffle(test);
  for (int sorting = 0; sorting < test.size(); sorting++) {
    cout << test[sorting] << endl;
  }
}

template <typename T>
void shuffle(vector<T>& v) {
  vector<T> temp;
  temp = v;
  vector<int> randomize(v.size());

  //Creates a list of random numbers up to v.size().
  for (int change = 0; static_cast<unsigned int>(change) < v.size(); change++) {
      randomize[change] = rand() % v.size();
      for (int check = change; check >= 0; check--) {
        if (randomize[change] == randomize[check]) {
          randomize[change] = rand() % v.size();
          check = change;
        }
      }
  }
  //Inputs shuffled/randomized list into referenced vector.
  for (int input = 0; static_cast<unsigned int>(input) < v.size(); input++) {
    v[input] = temp[randomize[input]];
  }

}
