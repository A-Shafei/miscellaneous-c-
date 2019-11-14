#include <iostream>
#include <string>
using namespace std;

int main(){
  int x;
  int y;

  cout << "First number: " << endl;
  cin >> x;
  cout << "Second number: " << endl;
  cin >> y;
  
  string res = ( x % y == 0 ) ? "Divisible" : "Not Divisible";
  cout << res << endl;

  return 0;
}
