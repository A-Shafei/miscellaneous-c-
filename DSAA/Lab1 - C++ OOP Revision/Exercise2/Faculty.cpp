#include <iostream>
#include "Faculty.h"

Faculty::Faculty(){
  sCount = 0;
}

bool Faculty::addStudent(Student* pS){
  if( sCount > 200 ){
    return false;
  }
  sList[sCount] = pS;
  sCount++;
  return true;
}

bool Faculty::dropStudent(int index){ //The question doesn't want to use delete
  if( index < 0 || index > sCount ){
    return false;
  }
  sList[index] = sList[sCount-1];
  sList[sCount-1] = nullptr;
  sCount--;
  return true;
}

void Faculty::passAll(){
  for( int i = 0; i < sCount; i++ ){
    Student* cand = sList[i];
    if( cand->getGradYear() == -1 ){
      bool graduated = cand->pass();
      if( graduated ){
	Student* newGrad = new Graduate(cand->getName(), cand->getID(), 2017);
	this->dropStudent(i);
	this->addStudent(newGrad);
	delete cand; //I think this cleans it up nicely and doesn't break anything..
      }
    }
  }
}

void Faculty::printInfo(){
  int numGrads = 0;
  int numUndergrads = 0;
  std::cout << "Information of Graduates: " << std::endl;
  for( int i = 0; i < sCount; i++ ){
    if( sList[i]->getGradYear() == -1 ){
      numUndergrads++;
    }
    else{
      numGrads++;
      sList[i]->printInfo(); //Two birds one stone.
    }
  }
  std::cout << "Number of Graduates: " << numGrads << std::endl;
  std::cout << "Number of Undergrads: " << numUndergrads << std::endl;
}
      
