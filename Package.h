#ifndef PACKAGE_H
#define PACKAGE_H
#include <string>

class Package
{
 public:
  Package();
  Package(std::string, std::string, std::string, std::string, std::string, std::string, int, int, double, double);
  double calculateCost();
  double getWeight();
  
 private:
  std::string sndName;
  std::string rcpName;
  std::string sndAddress;
  std::string rcpAddress;
  std::string sndCity;
  std::string rcpCity;
  int sndPostalCode;
  int rcpPostalCode;
  double weight;
  double costPerGram;
};
  

#endif
