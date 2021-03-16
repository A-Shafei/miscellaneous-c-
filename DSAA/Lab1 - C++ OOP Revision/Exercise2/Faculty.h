#ifndef FACULTY_H
#define FACULTY_H

#include "Graduate.h"
#include "Undergraduate.h"

class Faculty{
 public:
  Faculty();
  bool addStudent(Student*);
  bool dropStudent(int);
  void passAll();
  void printInfo();

 private:
  Student* sList[200];
  int sCount;
};p

#endif
