#pragma once

#include <string>
using namespace std;

#include "Employee.h"

class Locker
{
	
	string size;
	int floor;
	Employee* pEmp; 	//an Employee can use a locker [Association Relationship]

public:
	Locker(string s="small", int f=2);
	~Locker();
	void AssignLocker(Employee* pE);
	void printInfo();
	
};
