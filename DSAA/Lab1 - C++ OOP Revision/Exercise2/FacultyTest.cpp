#include "Faculty.h"
#include <iostream>
#include <string>

int main(){
  Student* G1 = new Graduate("GGG", 111, 2010);
  Student* U1 = new Undergraduate("U3U", 333, 3);
  Student* U2 = new Undergraduate("U2U", 222, 4);

  Faculty F1;
  F1.addStudent(G1);
  F1.addStudent(U1);
  F1.addStudent(U2);

  F1.printInfo();

  F1.passAll();
  F1.printInfo();

  F1.passAll();
  F1.printInfo();

  F1.passAll();
  F1.printInfo();
}

  

  
