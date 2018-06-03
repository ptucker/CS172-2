//I affirm that all code given below was written solely by me, Levi, and 
//that any help I received adhered to the rules stated for this exam.
#include "Movie.h"
#include <string>

using namespace std;
Movie::Movie() {
  genre = "Comedy";
}
Movie::Movie(string Title, string Genre, int ShowTime) {
  title = Title;
  genre = Genre;
  showTime = ShowTime;
}

string Movie::GetTitle() {return title;}
string Movie::GetGenre() {return Movie::genre;}
int Movie::GetShowTime() {return showTime;}