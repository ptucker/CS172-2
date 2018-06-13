#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

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
}

template <typename T>
void shuffle(vector<T>& v) {
  vector<T> temp;
  temp = v;

  vector<int> randomize(v.size());

  //Creates a list of random numbers 1 to 10 with no repeats.
  for (int change = 0; static_cast<unsigned int>(change) < v.size(); change++) {
      randomize[change] = rand() % 10;
      for (int check = change; check >= 0; check--) {
        if (randomize[change] == randomize[check]) {
          randomize[change] = rand() % 10;
          check = change;
        }
      }
  }
  //Inputs shuffled/randomized list into referenced vector.
  for (int input = 0; static_cast<unsigned int>(input) < v.size(); input++) {
    v[input] = temp[randomize[input]];
  }

}