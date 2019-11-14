#include <iostream>
using namespace std;

void displayer(const int* arr, int size){
  cout << "{ ";
  for( int i = 0 ; i < size ; i++ ){
    cout << arr[i] << " ";
  }
  cout << "}" << endl;
}

int multi(int* x, int* y){

  int sum = *x + *y;

  *x = 2 * *x;
  *y = 2 * *y;

  return sum;
  
}

int main(){

  int a = 5;
  int b = 6;

  int sum = multi(&a, &b);

  cout << a << " " << b << " " << sum << endl;

}
