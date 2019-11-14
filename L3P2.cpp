#include <iostream>
#include <string>
using namespace std;

int main(){

  srand(time(0));
  
  string w1, w2;
  double prob;

  cout << "Enter your two words: ";
  cin >> w1 >> w2;

  cout << "Enter the probability of the first word: ";
  cin >> prob;

  prob = prob * 100;

  for( int i = 1; i <= 100; i++ ){
    int luckNum = rand() % 101;
    if( luckNum <= prob ){
      cout << w1 << endl;
    } else {
      cout << w2 << endl;
    }
  }
  
}
