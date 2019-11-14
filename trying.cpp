#include <iostream>
#include <math.h>
using namespace std;

int main() {
  int a;
  int b;
  int c;
  double root1;
  double root2;

  cout << "Enter a: " << endl;
  cin >> a;
  cout << "Enter b: " << endl;
  cin >> b;
  cout << "Enter c: " << endl;
  cin >> c;
  
  int dis = pow(b, 2) - 4 * a * c;

  if( dis > 0 ){
    cout << "Two real roots:" << endl;
    root1 = ( -b + pow(dis, 0.5) ) / (2 * a);
    root2 = ( -b - pow(dis, 0.5) ) / (2 * a);
    cout << "First root: " << root1 << endl;
    cout << "Second root: " << root2 << endl;
  } else if( dis == 0 ){
    cout << "One real root:" << endl;
    root1 = ( -b ) / (2 * a);
    cout << "Only root: " << root1 << endl;
  } else if( dis < 0 ){
    cout << "No real roots!" << endl;
  }

  
  return 0;
}
