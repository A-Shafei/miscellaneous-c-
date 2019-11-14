#include <iostream>
using namespace std;

void multiply(double& num1, double& num2, double& num3, int constant);

int main(){

  double num1, num2, num3;
  int constant;

  cout << "Enter your three numbers: ";
  cin >> num1 >> num2 >> num3;

  cout << "Enter your constant: ";
  cin >> constant;
  
  multiply(num1, num2, num3, constant);

}

void multiply(double& num1, double& num2, double& num3, int constant){

  num1 = num1 * constant;
  num2 = num2 * constant;
  num3 = num3 * constant;

  cout << num1 << endl << num2 << endl << num3 << endl;

}
