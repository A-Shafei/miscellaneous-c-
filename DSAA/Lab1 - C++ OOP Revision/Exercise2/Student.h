#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student{
 public:
  Student(std::string, int);
  std::string getName();
  int getID();
  void printInfo();
  virtual int getGradYear(){
    return 0;
  }
  virtual bool pass(){
    return false;
  }

 protected:
  std::string name;
  int ID;
};

#endif
