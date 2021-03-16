#include <string>
#include <iostream>
#include "Package.h"
#include "TwoDayPackage.h"
#include "OvernightPackage.h"
using namespace std;

int main()
{
  Package handCuffs("Mr.Rogers", "Mrs.Rogers", "4th street", "12th street", "Pheonix", "Seattle", 26523, 46234, 300, 2);
  TwoDayPackage candles("Bob Ross", "Oprah", "8th street", "9th street", "Quebec", "Toronto", 63452, 34563, 100, 4, 20);
  OvernightPackage blindFolds("Kermit", "Cookie monster", "1st street", "Sesame Street", "Nice", "Paris", 62452, 65437, 30, 5, 2);

  cout << "Package of weight 300 and cost 2 credits per gram costs: " << handCuffs.calculateCost() << endl;
  cout << "Two Day Package of weight 100, cost 4 credits per gram, and a flat fee of 20 costs: " << candles.calculateCost() << endl;
  cout << "Overnight Package of weight 30, cost 5 credit per gram, and additional fee per gram of 2 costs: " << blindFolds.calculateCost() << endl;

}
