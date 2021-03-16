#ifndef CARGOSHIP_H
#define CARGOSHIP_H
#include <string>
#include "Ship.h"

class CargoShip : public Ship
{
 private:
  double capacity;

 public:
 CargoShip():Ship()
    {
      capacity = 0.0;
    }
 CargoShip(std::string sName, std::string sYearBuilt, double sCapacity):Ship(sName, sYearBuilt)
    {
      capacity = sCapacity;
    }
  void print();
};


#endif
