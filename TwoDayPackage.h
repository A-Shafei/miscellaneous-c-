#ifndef TWODAYPACKAGE_H
#define TWODAYPACKAGE_H
#include <string>
#include "Package.h"
//It seems to be bad practice to expand namespaces in header files

class TwoDayPackage : public Package
{
 public:
  TwoDayPackage();
  TwoDayPackage(std::string, std::string, std::string, std::string, std::string, std::string, int, int, double, double, double);
  double calculateCost(); //Redefined implementation in TwoDayPackage.cpp
  
 private:
  double flatRate;
};

#endif
