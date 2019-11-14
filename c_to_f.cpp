#include <iostream>
#include <string>
using namespace std;

int main(){

  double c;
  double f;
  
  cout << "Enter temp in C: ";
  
  cin >> c;

  f = (9.0/5) * c + 32;

  cout << "Temp in f is: " << f << endl;
  
  return 0;
}
