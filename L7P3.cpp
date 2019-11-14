#include <iostream>
using namespace std;

double* doubleArray( double* arr, int size);

int main(){

  double originalArray[] = {5.2, 5.3, 5.4, 5.5};
  double* newArray;
  
  cout << "Before calling: " << endl;
  cout << "Original array is: " << endl;

  for( int i=0 ; i<4 ; i++ ){
    cout << originalArray[i] << endl;
  }

  newArray = doubleArray(originalArray, 4);

  cout << "After calling: " << endl;
  cout << "Original array is: " << endl;

  for( int i=0 ; i<4 ; i++ ){
    cout << originalArray[i] << endl;
  }

  cout << "New array is: " << endl;
  
  for( int i=0 ; i<4 ; i++ ){
    cout << newArray[i] << endl;
  }

}

double* doubleArray( double* arr, int size){

  double* temp = new double;

  for( int i=0 ; i<size ; i++ ){

    temp[i] = arr[i] * 2;

  }

  return temp;

}
