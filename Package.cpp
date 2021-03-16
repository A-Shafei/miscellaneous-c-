#include <iostream>
#include <string>
#include <cstdlib>
#include "Package.h"
using namespace std;

Package::Package()
{
  sndName = "";
  rcpName = "";
  sndAddress = "";
  rcpAddress = "";
  sndCity = "";
  rcpCity = "";
  sndPostalCode = 0;
  rcpPostalCode = 0;
  weight = 0.0;
  costPerGram = 0.0;
}

Package::Package(string mySndName, string myRcpName, string mySndAddress, string myRcpAddress, string mySndCity, string myRcpCity, int mySndPostalCode, int myRcpPostalCode, double myWeight, double myCostPerGram)
{
  if( myWeight > 0 && myCostPerGram > 0 )
    {
      sndName = mySndName;
      rcpName = myRcpName;
      sndAddress = mySndAddress;
      rcpAddress = myRcpAddress;
      sndCity = mySndCity;
      rcpCity = myRcpCity;
      sndPostalCode = mySndPostalCode;
      rcpPostalCode = myRcpPostalCode;
      weight = myWeight;
      costPerGram = myCostPerGram;
    }
  else
    {
      cout << "Invalid weight or cost per gram!" << endl;
      exit(EXIT_FAILURE);
    }
}

double Package::calculateCost()
{
  return weight * costPerGram;
}

double Package::getWeight()
{
  return weight;
}
