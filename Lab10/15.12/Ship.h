#ifndef SHIP_H
#define SHIP_H
#include <string>

class Ship
{
 protected:
  std::string name;
  std::string yearBuilt;

 public:
  Ship()
    {
      name = "None given";
      yearBuilt = "None given";
    }
  Ship(std::string sName, std::string sYearBuilt)
    {
      name = sName;
      yearBuilt = sYearBuilt;
    }
  void setName(std::string sName)
    {
       name = sName;
    }
  std::string getName()
    {
      return name;
    }
  void setYearBuilt(std::string sYearBuilt)
    {
      yearBuilt = sYearBuilt;
    }
  std::string getYearBuilt()
    {
      return yearBuilt;
    }
  virtual void print();
};
//Non-trivial function implimintations (namely, print()) is in the .cpp filexf
#endif
