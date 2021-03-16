#ifndef GRADUATE_H
#define GRADUATE_H

#include <string>
#include "Student.h"

class Graduate: public Student{
 public:
  Graduate(std::string, int, int);
  void printInfo();

 private:
  int gradYear;
};

#endif
