#include <iostream>
using namespace std;

void printASCII(char, char, int);

int main(){

  char ch1;
  char ch2;
  int numberPerLine;
  
  cout << "Enter ch1 and ch2: ";
  cin >> ch1 >> ch2;

  cout << "How many values per line? ";
  cin >> numberPerLine;

  printASCII(ch1, ch2, numberPerLine);

}

void printASCII(char ch1, char ch2, int numberPerLine){

  int count = 0;

  for( int i = (int)ch1; i <= (int)ch2; i++ ){
    cout << i << "\t";
    count += 1;

    if( count == numberPerLine ){
      cout << endl;
      count = 0;
    }

  }

  cout << endl;

}
