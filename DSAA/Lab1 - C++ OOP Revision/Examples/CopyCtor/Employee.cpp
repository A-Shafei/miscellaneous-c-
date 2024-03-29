#include "Employee.h"
#include <iostream>
using namespace std;


Employee::Employee(string m_name, string m_job)
{
	cout<<"\nConstructor is Called..";
    job = m_job;
    name = m_name;
	LastPromotion = nullptr;
}

Employee::~Employee()
{
	cout<<"\nEntered Destructor";
	cout.flush();
	if(LastPromotion)
	{
		delete LastPromotion;
		LastPromotion = nullptr;
	}
	cout<<"\nout of the Destructor";
	cout.flush();
}
void Employee::setName(string m_name)
{
	name= m_name;
}
void Employee::setJob(string m_job)
{
	job = m_job;
}
string Employee::getName() const
{
	return name;
}
string Employee::getJob() const
{
	return job;
}

void Employee::setLastProm(double P)
{
	if(!LastPromotion)
		LastPromotion = new double;
	*LastPromotion = P;
}

void Employee::PrintInfo()
{
	cout<<"\nEmployee info...";
	cout<<"Job is "<<getJob()<<" , name is "<<getName();
	if(LastPromotion)
		cout<<" , LastPromo "<<*LastPromotion;
	else
		cout<<" ,No promotions yet";

}


//The copy constructor
//step2
//uncomment the following 
Employee::Employee(const Employee& rhs)
{
	cout<<"\n\n *** *** *** COPY Constructor is Called *** *** ***\n";
	cout.flush();
	if(this != &rhs)	//check for self-assignment
	{
		job = rhs.job;
		name = rhs.name;
		LastPromotion = new double;
		*LastPromotion = *rhs.LastPromotion;
	}
} 





