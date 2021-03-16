#include "Student.h"
#include <iostream>

Student::Student(std::string newName, int newID){
  if( newName == "" ){
    std::cout << "Name can't be empty" << std::endl;
    exit(0);
  }
  if( newID < 1 ){
    std::cout << "ID has to be at least 1" << std::endl;
    exit(0);
  }
  name = newName;
  ID = newID;
}

std::string Student::getName(){
  return name;
}

int Student::getID(){
  return ID;
}

void Student::printInfo(){
  std::cout << "Student name is:\t" << name << std::endl;
  std::cout << "Student ID is:\t" << ID << std:: endl;
}
  
