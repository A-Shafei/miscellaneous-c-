#ifndef OVERNIGHTPACKAGE_H
#define OVERNIGHTPACKAGE_H
#include <string>
#include "Package.h"
//It seems to be bad practice to expand namespaces in header files

class OvernightPackage : public Package
{
 public:
  OvernightPackage();
  OvernightPackage(std::string, std::string, std::string, std::string, std::string, std::string, int, int, double, double, double);
  double calculateCost(); //Redefined implementation in OvernightPackage.cpp
  
 private:
  double additionalFeePerGram;
};

#endif
