#include <iostream>
#include <math.h>
using namespace std;

int main(){

  double a, b, c;
  double r1, r2, dis;
  
  cout << "Enter a, b, and c: ";
  cin >> a >> b >> c;

  dis = b * b - 4 * a * c;

  if( dis > 0 ){
    r1 = ( -b + pow(dis, 0.5) ) / ( 2 * a );
    r2 = ( -b - pow(dis, 0.5) ) / ( 2 * a );
    cout << "Two real roots: " << endl;
    cout << r1 << endl;
    cout << r2 << endl;
  } else if( dis == 0 ){
    r1 = ( -b ) / ( 2 * a );
    cout << "One real root: " << endl;
    cout << r1 << endl;
  } else {
    cout << "No real roots!" << endl;
  }
}
