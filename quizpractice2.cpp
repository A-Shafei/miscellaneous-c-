#include <iostream>
using namespace std;

void displayer(const int* arr, int size){
  cout << "{ ";
  for( int i = 0 ; i < size ; i++ ){
    cout << arr[i] << " ";
  }
  cout << "}" << endl;
}

int* doubler(const int* arr, int size){
  int* doubled = new int[size * 2];

  for( int i = 0 ; i < size ; i++ ){
    doubled[i] = arr[i];
  }

  for( int i = size ; i < size * 2 ; i++ ){
    doubled[i] = 1;
  }

  return doubled;
}

int main(){
  int size;

  cout << "How shlong is yer array? ";
  cin >> size;

  int* test = new int[size];

  cout << "Gimme one by one!" << endl;
  
  for( int i = 0 ; i < size ; i++ ){
    cin >> test[i];
  }

  displayer(test, size);

  int* doublyboi = doubler(test, size);

  displayer(doublyboi, size*2);

  delete [] doublyboi;
  delete [] test;

  
}
