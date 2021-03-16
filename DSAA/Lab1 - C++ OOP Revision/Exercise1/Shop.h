#ifndef SHOP_H
#define SHOP_H

#include "Bag.h"

class Shop{
 public:
  Shop();
  int isAvailable(float, int);
  bool addBag();
  Bag* getBag(int);
  bool sell(float, int);
  void printAllBags();

 private:
  Bag* bagList[50];
  int quantity;
  float totalProfit;

};
  
#endif
