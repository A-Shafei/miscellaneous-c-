#include <iostream>
using namespace std;

void multiply(double*, double*, double*, int);

int main(){

  double num1, num2, num3;
  int constant;
  
  cout << "Enter three numbers: ";
  cin >> num1 >> num2 >> num3;

  cout << "Enter constant: ";
  cin >> constant;

  multiply(&num1, &num2, &num3, constant);

  cout << "The three numbers are: " << num1 << " " << num2 << " " << num3 << endl;

}

void multiply(double* ptr1, double* ptr2, double* ptr3, int constant){

  *ptr1 = *ptr1 * constant;
  *ptr2 = *ptr2 * constant;
  *ptr3 = *ptr3 * constant;

}
