#ifndef UNDERGRADUATE_H
#define UNDERGRADUATE_H

#include <string>
#include "Student.h"

class Undergraduate: public Student{
 public:
  Undergraduate(std::string, int, int);
  int getCurrentYear();
  bool pass();
  void printInfo();
  int getGradYear(); //Nice to tell them apart using this

 private:
  int currentYear;
  int gradYear;
};

#endif
