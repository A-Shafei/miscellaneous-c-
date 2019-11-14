#include <iostream>
using namespace std;

//This program is dying to get implemented using object orientation. I'm too lazy, so I'll just use what we saw in lectures.

int main(){

  int t;
  
  cout << "Enter Temperature in Degrees F: ";
  cin >> t;

  cout << "At " << t << " Degrees F: " << endl;

  if( t <= -173 ){
    cout << "Ethyl alcohol will freeze" << endl;
  } else if( t >= 172 ){
    cout << "Ethyl alcohol will boil" << endl;
  }

  if( t <= -38 ){
    cout << "Mercury will freeze" << endl;
  } else if( t >= 676 ){
    cout << "Mercury will boil" << endl;
  }  

  if( t <= -362 ){
    cout << "Oxygen will freeze" << endl;
  } else if( t >= -306 ){
    cout << "Oxygen will boil" << endl;
  }  

  if( t <= 32 ){
    cout << "Water will freeze" << endl;
  } else if( t >= 212 ){
    cout << "Water will boil" << endl;
  }
  
}
