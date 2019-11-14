#include <iostream>
#include <string>
#include <ctime>
using namespace std;


int main(){
  int numTrials = 2147483646;	// 
  int numHits = 0;
  srand(time(0));

  for (int i = 0; i < numTrials; i++){
    double x = rand() * 2.0 / RAND_MAX - 1;
    double y = rand() * 2.0 / RAND_MAX -1;
    if ( x * x + y * y <= 1 )
      numHits++;
  }
  double pi = 4.0 * numHits / numTrials;
  cout << "PI is " << pi << endl;
}
