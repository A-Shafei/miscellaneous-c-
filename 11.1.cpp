#include <iostream>
#include <string>
using namespace std;

struct MovieData {

  string title;
  string director;
  int yearReleased;
  int runningTime;

};

void displayer(MovieData movie){

  cout << "The title is: " << movie.title << endl;
  cout << "Director is: " << movie.director << endl;
  cout << "Year released is: " << movie.yearReleased << endl;
  cout << "Running time is: " << movie.runningTime << endl;

}

int main(){

  MovieData movie1, movie2;

  cout << "Enter title: ";
  cin >> movie1.title;

  cout << "Enter director: ";
  cin >> movie1.director;

  cout << "Enter yearReleased: ";
  cin >> movie1.yearReleased;

  cout << "Enter Running time: ";
  cin >> movie1.runningTime;

  cout << "Enter title: ";
  cin >> movie2.title;

  cout << "Enter director: ";
  cin >> movie2.director;

  cout << "Enter yearReleased: ";
  cin >> movie2.yearReleased;

  cout << "Enter Running time: ";
  cin >> movie2.runningTime;

  displayer(movie1);

  displayer(movie2);

}
