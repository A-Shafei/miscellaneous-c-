#include <iostream>
using namespace std;

int main(){

  double a = 3.1;

  switch( a ){
  case 3.4:
    cout << 'd' << endl;
    break;
  case 3.3:
    cout << 'c' << endl;
    break;
  case 3.2:
    cout << 'b' << endl;
    break;
  case 3.1:
    cout << 'a' << endl;
    break;
  default:
    cout << "defaulted" << endl;
    break;
  }

}
