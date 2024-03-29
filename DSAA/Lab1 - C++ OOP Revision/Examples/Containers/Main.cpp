#include "Locker.h"
#include "Dept.h"

#include <iostream>
using namespace std;


int main()
{
	Employee* pE1 = new Employee("Ahmed", 12345, 25, 12, 1975); 
	pE1->PrintData();

	
	Employee* pE2 = new Employee("Hossam", 102030, 30, 5, 1980); 
	pE2->PrintData();

	Dept* pD = new Dept(2, 2);	//2 emps max and 2 lockers max (just For simplicity)
	pD->printData();

	pD->Hire(pE2);
	pD->printData();
	pD->Hire(pE1);
	pD->printData();

	pD->Assign(1, 12345);
	pD->printData();


	delete pD;
	pE1->PrintData();
	pE2->PrintData();

	delete pE1;
	delete pE2;

	return 0;
}
