#include <iostream>
#include <string.h>
#include "Employee.h"
using namespace std;

int main(){

  Employee e1("Dan", 1, "23 05 2011");

  cout << e1.getEmployeeName() << endl;

}
