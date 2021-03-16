#include "Shop.h"
#include <iostream>

Shop::Shop(){
  quantity = 0;
  totalProfit = 0.0;
}

int Shop::isAvailable(float desiredSize, int desiredSlots){
  for( int i = 0; i < quantity; i++ ){
    Bag* currentBag = bagList[i];
    if( currentBag->getSize() == desiredSize &&
	currentBag->getSlots() == desiredSlots )
    {
      return i;
    }
  }
  return -1;
}

bool Shop::addBag(){
  if( quantity == 50 ){
    std::cout << "Sorry, no more vacant places for bags" << std::endl;
    return false;
  }
  
  bagList[quantity] = new Bag;
  std::cout << "An info-less bag has been added." << std::endl;
  bagList[quantity]->ReadInfo();
  quantity++;
  return true;
}

Bag* Shop::getBag(int desiredIndex){
  return bagList[desiredIndex];
}

bool Shop::sell(float desiredSize, int desiredSlots){
  int foundIndex = this->isAvailable(desiredSize, desiredSlots);

  if( foundIndex == -1 ){
    std::cout << "Sorry, no such bag found to sell!" << std::endl;
    return false;
  }

  totalProfit += bagList[foundIndex]->getPrice();
  delete bagList[foundIndex];
  //Now the memory location it points to is back to being unassigned

  //If that wasn't the last element, then there's now a gap we should fill
  if( foundIndex != quantity-1 ){
    bagList[foundIndex] = bagList[quantity-1];
  }
  quantity--;
  return true;

  //It might appear that next time we add a bag it'll cause a memory leak
  //But actually we can safely assign a new memory address to the array element
  //at the index equal to "quantity"
  //This is because we have it's contents also pointed to by the pointer that
  //was at the gap
  //They can be deleted when we use delete on that one
  //I.. think that's how pointers work.. :'D
}

void Shop::printAllBags(){
  for( int i = 0; i < quantity; i++ ){
    std::cout << "Details of bag at index " << i << ": " << std::endl;
    bagList[i]->PrintInfo();
  }
}



    
