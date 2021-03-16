#include "Shop.h"
#include <iostream>

int main(){
  Shop S;
  S.addBag();
  S.addBag();
  S.addBag();
  S.printAllBags();
  Bag* Bp;
  Bp = new Bag(15.6, 7);
  Bp->setPrice(130);
  Bag* ptr = S.getBag(2);
  std::cout << "Comparison result: " << Bp->Compare(*ptr) << std::endl;
  S.sell(6.6, 6); //Best I can do is assume the user will input this size
                  //and this number of slots for the second bag. 
  S.printAllBags();
}
