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
