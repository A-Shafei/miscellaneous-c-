#include <string>
#include <iostream>
#include "OvernightPackage.h"
using namespace std;

OvernightPackage::OvernightPackage() : Package()
    {
      additionalFeePerGram = 0.0;
    }

OvernightPackage::OvernightPackage(string mySndName, string myRcpName, string mySndAddress, string myRcpAddress, string mySndCity, string myRcpCity, int mySndPostalCode, int myRcpPostalCode, double myWeight, double myCostPerGram, double myAdditionalFeePerGram) : Package(mySndName, myRcpName, mySndAddress, myRcpAddress, mySndCity, myRcpCity, mySndPostalCode, myRcpPostalCode, myWeight, myCostPerGram)
    {
      additionalFeePerGram = myAdditionalFeePerGram;
    }

double OvernightPackage::calculateCost()
{
  return Package::calculateCost() + additionalFeePerGram*Package::getWeight();
}
