#include "Point.h"
#include <iostream>
using namespace std;


int main()
{
	Point P1;		//No parameters passed ==> Default constructor is called
	
	//According to the number of parameters passed, the appropriate constrcutor is called.
	Point P2(2);
	Point P3(3, 3);
	Point P4(4,4,4);
	
	//Dynamic Object Allocation (the "new" operator)
	//You can use any constructor

	// Q: How many calls for the destructors? Is that correct or not and why? 
	// Q: What's missing?  
	Point* ptr;
	ptr = new Point;
	ptr = new Point(3, 4);
	ptr = new Point(5, 6, 7);

	cout<<"\nSeven objects were constructed using different types of constructors";	
	cout<<endl;

	
	return 0;
}