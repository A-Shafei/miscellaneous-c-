#include <iostream>
#include "Circle.h"
#include "Rectangle.h"
using namespace std;

int main(){
  BasicShape * C1;
  BasicShape * R1;
  C1 = new Circle(400, 500, 14.8);
  cout << C1->getArea() << endl;
  R1 = new Rectangle(4, 5);
  cout << R1->getArea() << endl;
}
