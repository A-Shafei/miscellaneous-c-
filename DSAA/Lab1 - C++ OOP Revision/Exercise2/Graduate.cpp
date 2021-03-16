#include <iostream>
#include "Graduate.h"

Graduate::Graduate(std::string newName, int newID, int newGradYear)
  : Student(newName, newID){
  if( newGradYear < 0 ){
    std::cout << "Invalid graduation year!" << std::endl;
    exit(0);
  }
  gradYear = newGradYear;
}

void Graduate::printInfo(){
  std::cout << "Graduate name is:\t" << name << std::endl;
  std::cout << "Graduate ID is:\t" << ID << std::endl;
  std::cout << "Graduation year is:\t" << gradYear << std::endl;
}
