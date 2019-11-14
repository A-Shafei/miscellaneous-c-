#include <iostream>
#include <ctime>
using namespace std;

int main(){

  srand(time(NULL));

  int numTrials = 1000000;

  int hitsIn1 = 0;
  int hitsIn2 = 0;
  int hitsIn3 = 0;
  int hitsIn4 = 0;

  for( int i = 0; i < numTrials; i++ ){

    double x = rand() * 2.0 / RAND_MAX - 1;
    double y = rand() * 2.0 / RAND_MAX - 1;

    //The line between two regions in considered a part of neither. This is to avoid needless ambiguity.
    
    if( x < 0 ){ hitsIn1 += 1; }

    if( x + y > 1 ){ hitsIn2 += 1; }

    if( x > 0 && y > 0 && x + y < 1 ){ hitsIn3 += 1; }

    if( x > 0 && y < 0 ){ hitsIn4 += 1; }

  }

  cout << "Total hits in odd-numbered regions: " << hitsIn1 + hitsIn3 << endl;
  cout << "Percentage of hits in odd-numbered regions (analogous to probability): " << (100.0 * (hitsIn1 + hitsIn3) / 1000000) << endl;

  //The laws of probability dictate that the actual probability is 0.5 + 0.125 = 0.625 so let's hope it comes out close to that.
  
}
