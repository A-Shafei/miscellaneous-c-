#include <iostream>
using namespace std;

bool isSorted(const int list[], int size);

int main(){

  int list[80];
  int size;

  cout << "Enter list: ";
  cin >> list[0];

  size = list[0];

  for( int i = 1 ; i <= size ; i++ ){
    cin >> list[i];
      }

  if( isSorted(list, size) ){
    cout << "The list is already sorted" << endl;
  }else{
    cout << "The list is not sorted" << endl;
  }
  
}

bool isSorted(const int list[], int size){
  
  for( int i = 2 ; i < size ; i++ ){
    if( list[i] < list[i-1] ){
      return false;
    }
  }
  
  return true;

}
    
