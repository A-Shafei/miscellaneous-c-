#include <iostream>
#include <string>
#include "Ship.h"
#include "CruiseShip.h"
#include "CargoShip.h"
using namespace std;

//Our main program that sould be able to create instances of ship and call print()

int main()
{

  Ship * ptr[3];

  ptr[0] = new Ship("HMSBeegle", "1894");
  ptr[1] = new CruiseShip("RoyalExpress" , "1985", 2000);
  ptr[2] = new CargoShip("BigMover", "2008", 50);

  for(int i=0 ; i<3 ; i++ ){
    ptr[i]->print();
  }

}
