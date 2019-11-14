#include <iostream>
using namespace std;

int main(){

  cout << "Meters\tFeet\t|\tFeet\tMeters" << endl;
  for( int i=1; i<=15; i++ ){
    cout << i << "\t" << i * 3.28 << "\t|\t" << i * 3 << "\t" << i * 3 / 3.28 << endl;
  }

}

