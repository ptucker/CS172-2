#include "Theater.h"
#include <string>
#include <iostream>
using namespace std;
Theater::Theater(string Name, string Phone) {
  TheaterName = Name;
  PhoneNumber = Phone;
}
void Theater::AddMovie(Movie& Movie) {
  /*
  cout << Movie.GetTitle() << endl;
  cout << Movie.GetGenre() << endl;
  cout << Movie.GetShowTime() << endl;
  */
  MovieHour[Movie.GetShowTime()] = Movie.GetTitle();
  GenreHour[Movie.GetShowTime()] = Movie.GetGenre();


}
string Theater::GetMovieForHour(int hour) {
  /*
  for (int time = 0; time < 24; time++) {
      cout << MovieHour[time] << time << endl;
  }
  */
  if (hour < 24 && hour > 0) {
    for (int hours = hour; hours < 24; hours++) {
      if (MovieHour[hours] != "") {
        return MovieHour[hours];
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

int Theater::GetPopcornPrice() {
  return PopcornPrice;
}
int Theater::GetCokePrice() {
  return CokePrice;
}