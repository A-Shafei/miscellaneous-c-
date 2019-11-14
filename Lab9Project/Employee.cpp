#include <iostream>
#include <string.h>
#include "Employee.h"
using namespace std;

Employee::Employee(){
  name = "None given";
  number = -1;
  Hire_date = "None ginen";
  Employee_Numbers++;
}

Employee::Employee(string eName, int eNumber, string eHire_date){
  name = eName;
  number = eNumber;
  Hire_date = eHire_date;
  Employee_Numbers++;
}

void Employee::setHiringDate(string eHire_date){
  Hire_date = eHire_date;
}

string Employee::getEmployeeName(){
  return name;
}

void Employee::Print(){
  cout << "Employee Name is : " << name << " , Employee Number is : " << number << " , Hiring Date is : " << Hire_date << endl;
}
