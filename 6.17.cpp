#include <iostream>
using namespace std;

bool isValid(double, double, double);
double perimeter(double);

int main(){

  double side1, side2, side3;

  cout << "Enter the three sides: ";
  cin >> side1 >> side2 >> side3;

  if( isValid(side1, side2, side3) ){
    cout << "perimeter is: " << perimeter(side1) << endl;
  } else {
    cout << "Input is invlid!" << endl;
  }

}

bool isValid( double side1, double side2, double side3 ){
  return (side1 == side2 && side2 == side3);
}

double perimeter(double side1){
  return (side1 * 3);
}
