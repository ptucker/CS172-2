//I affirm that all code given below was written solely by me, Levi, and 
//that any help I received adhered to the rules stated for this exam.
#include "Theater.h"
#include <string>
using namespace std;
Theater::Theater(string Name, string Phone) {
  TheaterName = Name;
  PhoneNumber = Phone;
}

void Theater::AddMovie(Movie& Movie) {
  MovieHour[Movie.GetShowTime()] = Movie.GetTitle();
  GenreHour[Movie.GetShowTime()] = Movie.GetGenre();
}

string Theater::GetMovieForHour(int hour) {
  if (hour > 0 && hour < 24) {
    //Returns movies started after input time up to hour 24.
    for (int time = hour; time < 24; time++) {
      if (MovieHour[time] != "") {
        return MovieHour[time];
      }
    }
  }
  else {
    return "";
  }
}

int Theater::GetShowTimeForGenre(string Genre) {
  for (int time = 0; time < 24; time++) {
    if (GenreHour[time] == Genre) {
      return time;
      break;
    }
  }
  return -1;
}

int Theater::GetPopcornPrice() {return PopcornPrice;}
int Theater::GetCokePrice() {return CokePrice;}