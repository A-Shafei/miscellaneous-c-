#include <iostream>
using namespace std;

int main(){

  int a, b, c;

  cout << "Enter the three edges: ";
  cin >> a >> b >> c;

  if( a == b && a == c ){
    cout << "Equilatiral triangle" << endl;
  } else if( a == b || a == c || b == c ){
    cout << "Isosceles triangle" << endl;
  } else {
    cout << "Scalene trianlge" << endl;
  }

}
