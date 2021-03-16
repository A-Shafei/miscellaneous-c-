#ifndef CRUISESHIP_H
#define CRUISESHIP_H
#include <string>
#include "Ship.h"

class CruiseShip : public Ship
{
 private:
  int maxPassengers;

 public:
 CruiseShip():Ship()
    {
      maxPassengers = 0;
    }
 CruiseShip(std::string sName,std::string sYearBuilt,int sMaxPassengers):Ship(sName, sYearBuilt)
    {
      maxPassengers = sMaxPassengers;
    }
  void print();
};

#endif
