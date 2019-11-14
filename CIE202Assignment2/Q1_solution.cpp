#include <iostream>
using namespace std;

int main(){

  int numFirstClass = 0;
  int numEconomy = 0;
  int type;
  char decision;
  int plane[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

  cout << "Please type 1 for \"first class\"\nPlease type 2 for \"economy\"\nPlease type 3 to exit" << endl;

  while( numEconomy < 5 || numFirstClass < 5 ){

    cout << "Choose seat type: ";
    cin >> type;

    if( type == 3 ){
      break;
    }

    if( type == 1 && numFirstClass == 5 && numEconomy < 5 ){
      cout << "First class is complete. Is economy acceptable? (y/n)\nChoose seat type: ";
      cin >> decision;

      if( decision == 'y' ){
	type = 2;
      }else{
	cout << "Next flight leaves in 3 hours" << endl;
	continue;
      }
    }

    if( type == 2 && numEconomy == 5 && numFirstClass < 5 ){
      cout << "Economy is complete. Is first class acceptable? (y/n)\nChoose seat type: ";
      cin >> decision;

      if( decision == 'y' ){
	type = 1;
      }else{
	cout << "Next flight leaves in 3 hours" << endl;
	continue;
      }
    }

    if( type == 1 ){ // We don't need to check if first class is full, as the while loop condition together with the economy switcher above already handle that.
      plane[numFirstClass] = 1;
      numFirstClass++;
      cout << "Seat " << numFirstClass << " (first class)" << endl;
    }

    if( type == 2 ){
      plane[5+numEconomy] = 1;
      numEconomy++;
      cout << "Seat " << 5+numEconomy << " (economy)" << endl;
    }
      
  }
}
