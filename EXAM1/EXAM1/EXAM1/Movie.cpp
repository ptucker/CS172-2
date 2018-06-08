//I affirm that all code given below was written solely by me, David Martin, and that any help I received adhered to the rules stated for this exam.
#include "Movie.h"
#include "Theater.h"

Movie::Movie()
{
	title = "Bull Durham";
	genre = "Comedy";
	showTime = 0;
}
Movie::Movie(string Title, string Genre, int ShowTime)
{
	title = Title;
	genre = Genre;
	showTime = ShowTime;
}
string Movie::GetTitle()
{
	return title;
}// Returns the movie title
string Movie::GetGenre()
{
	return genre;
}// Returns the movie genre
int Movie::GetShowtime()
{
	return showTime;
}//When is this movie shown?