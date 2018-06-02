//I affirm that all code given below was written solely by me, Levi, and 
//that any help I received adhered to the rules stated for this exam.
#ifndef THEATER_H_
#define THEATER_H_

#include <string>
#include "Movie.h"
using namespace std;
class Theater {
private:
  int CokePrice = 3;
  int PopcornPrice = 2;
  string TheaterName;
  string PhoneNumber;
  //Action 1, Comedy 2, Horror 3, Documentary 4
  string GenreHour[24];
  string MovieHour[24];
public:
  Theater(string Name, string Phone);
  void AddMovie(Movie& Movie);
  string GetMovieForHour(int hour);

  int GetShowTimeForGenre(string Genre);

  int GetPopcornPrice();
  int GetCokePrice();
};
#endif
