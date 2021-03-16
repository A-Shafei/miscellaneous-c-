#include "Bag.h"
#include <iostream>

Bag::Bag(float newSize, int newSlots){
  size = newSize;
  slots = newSlots;
  price = 0;
}

bool Bag::setSize(float newSize){
  if( newSize > 0 ){
    size = newSize;
    return true;
  }
  return false;
}

bool Bag::setSlots(int newSlots){
  if( newSlots > 0 ){
    slots = newSlots;
    return true;
  }
  return false;
}

bool Bag::setPrice(float newPrice){
  if( newPrice > 0 ){
    price = newPrice;
    return true;
  }
  return false;
}

float Bag::getSize(){
  return size;
}

int Bag::getSlots(){
  return slots;
}

float Bag::getPrice(){
  return price;
}

int Bag::Compare(Bag otherBag){
  if( size > otherBag.size ){ //intentionally not needing the getter
    return 1;
  }
  if( otherBag.size > size ){
    return -1;
  }
  if( slots > otherBag.slots ){
    return 1;
  }
  if( otherBag.slots > slots ){
    return -1;
  }
  return 0;
}

void Bag::PrintInfo(){
  std::cout << "Bag size is:\t\t" << size << "\nNumber of slots is:\t" << slots << "\nBag price is:\t\t" << price << std::endl;
}

void Bag::ReadInfo(){
  std::cout << "This Dialouge let's you supply your desired bag info.\n" << "Enter bag size: ";
  std::cin >> size;
  std::cout << "Enter number of slots: ";
  std::cin >> slots;
  std::cout << "Enter price: ";
  std::cin >> price;
  std::cout << "Your changes have been saved." << std::endl;
}
