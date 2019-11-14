#include <iostream>
using namespace std;

int main(){

  int n1, n2;
  double diff;

  cout << "Enter your two numbers: ";
  cin >> n1 >> n2;

  diff = n1 - n2;

  if( n1 % n2 == 0 ){
    cout << n1 << " is divisible by " << n2 << endl;
  } else {
    cout << n1 << " is not divisble " << n2 << endl;
  }

}
