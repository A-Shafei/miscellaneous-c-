#include <string>
#include <iostream>
#include "TwoDayPackage.h"
using namespace std;

TwoDayPackage::TwoDayPackage() : Package()
    {
      flatRate = 0.0;
    }

TwoDayPackage::TwoDayPackage(string mySndName, string myRcpName, string mySndAddress, string myRcpAddress, string mySndCity, string myRcpCity, int mySndPostalCode, int myRcpPostalCode, double myWeight, double myCostPerGram, double myFlatRate) : Package(mySndName, myRcpName, mySndAddress, myRcpAddress, mySndCity, myRcpCity, mySndPostalCode, myRcpPostalCode, myWeight, myCostPerGram)
    {
      flatRate = myFlatRate;
    }

double TwoDayPackage::calculateCost()
{
  return Package::calculateCost() + flatRate;
}
