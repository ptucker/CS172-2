//I affirm that all code given below was written solely by me, Levi, and 
//that any help I received adhered to the rules stated for this exam.
#ifndef MOVIE_H_
#define MOVIE_H_

#include <string>
//have to put this or string doesn't work.
using namespace std;
class Movie {
private:
  string genre;
  const string Action = "Action";
  const string Comedy = "Comedy";
  const string Horror = "Horror";
  const string Documentary = "Documentary";

  string title;
  int showTime;
public:
  Movie();
  Movie(string Title, string Genre, int ShowTime);
  string GetTitle();
  string GetGenre();
  int GetShowTime();
 };
#endif
