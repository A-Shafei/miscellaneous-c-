#include <iostream>
#include <string>
using namespace std;

int main(){

  int s1, s2, s3, s4, s5;
  
  cout << "Enter today's sales for store 1: ";
  cin >> s1;  
  cout << "Enter today's sales for store 2: ";
  cin >> s2;  
  cout << "Enter today's sales for store 3: ";
  cin >> s3;  
  cout << "Enter today's sales for store 4: ";
  cin >> s4;  
  cout << "Enter today's sales for store 5: ";
  cin >> s5;

  cout << "SALES BAR CHART" << endl;
  cout << "(Each * = $100)" << endl;
  cout << "Store 1: " << string(s1/100, '*') << endl;
  cout << "Store 2: " << string(s2/100, '*') << endl;
  cout << "Store 3: " << string(s3/100, '*') << endl;
  cout << "Store 4: " << string(s4/100, '*') << endl;
  cout << "Store 5: " << string(s5/100, '*') << endl;

}
