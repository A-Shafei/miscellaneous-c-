#include <iostream>
using namespace std;

int negateArray( double const * arr , int);

int main(){

  int numZeros;
  double myArray[] = {-4, 0, 6, -2, 0, 8, -1, 0, 7};

  numZeros = negateArray(myArray, 9);

  cout << "counted zeros " << numZeros << endl;

  cout << "Here are the new elements: " << endl;

  for( int i=0 ; i<9 ; i++ ){
    cout << myArray[i] << endl;
  }
  
}

int negateArray( double const * arr, int size){

  int count;
  double crap;

  for( int i=0 ; i<size ; i++ ){

    if( arr[i] == 0 ){
      count++;
      continue;
    }

    arr[i] = -arr[i];

  }


  return count;
  
}

  
