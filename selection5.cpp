#include <iostream>
#include <string>
using namespace std;

int main(){

  int today_int;
  int jump;
  string today_str;
  string future_day;
  
  cout << "Enter today: (Sunday is 0 ... Saturday is 6)" << endl;
  cin >> today_int;

  cout << "Enter elapsed jump:" << endl;
  cin >> jump;

  switch( (today_int) ){
  case 0: cout << "Today is Sunday ";
  
  switch( (today_int + jump) % 7 ){
  case 0: cout << "Today is 
  

  return 0;
}
