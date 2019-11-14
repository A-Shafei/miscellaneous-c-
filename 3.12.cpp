#include <iostream>
#include <ctime>
using namespace std;

int main(){

  srand(time(0));

  int num = rand() % 11;
  cout << num << endl;
  int state = num % 2;
  int guess;

  cout << "Enter 0 for even and 1 for odd: ";
  cin >> guess;

  if( guess == state ){
    cout << "You were right!" << endl;
  } else {
    cout << "You were wrong!" << endl;
  }

}
