#include <iostream>
#include "Undergraduate.h"

Undergraduate::Undergraduate(std::string newName, int newID, int newCurrentYear)
  : Student(newName, newID){
  if( newCurrentYear < 0 ){
    std::cout << "Invalid current year!" << std::endl;
    exit(0);
  }
  currentYear = newCurrentYear;
  gradYear = -1; //Left as this for undergrads
}

int Undergraduate::getCurrentYear(){
  return currentYear;
}

bool Undergraduate::pass(){
  if( currentYear == 4 ){
    return true;
  }
  currentYear++;
  return false;
}

void Undergraduate::printInfo(){
  std::cout << "Undergraduate name is:\t" << name << std::endl;
  std::cout << "Undergraduate ID is:\t" << ID << std::endl;
  std::cout << "Current faculty year is:\t" << currentYear << std::endl;
}

int Undergraduate::getGradYear(){
  return gradYear;
}
  
