#include "Package.h"
#include "TwoDayPackage.h"
#include <iostream>
using namespace std;

int main()
{
  Package toys("Adam", "Eve", "5th street", "7th street", "Cairo", "Istanbul", 02615, 05262, 700, 2);
  cout << toys.calculateCost() << endl;
  TwoDayPackage fastToys("Lucifer", "John", "5th street", "7th street", "Cairo", "Istanbul", 02615, 05262, 800, 3, 50);
  cout << fastToys.calculateCost() << endl;
}
