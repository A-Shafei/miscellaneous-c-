#pragma once
#include <iostream>
#include <string.h>
using namespace std;

class Employee{

 public:
  string name;
  int number;
  string Hire_date;
  static int Employee_Numbers;

  Employee();

  Employee(string eName, int eNumber, string eHire_date);

  void setHiringDate(string eHire_date);

  string getEmployeeName();

  void Print();

};
