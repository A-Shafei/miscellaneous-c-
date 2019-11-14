#include <iostream>
#include <math.h>
using namespace std;

double f(int);

int main(){

  int n;
  
  cout << "Enter n: ";
  cin >> n;
  
  cout << "n\tf(n)" << endl;

  for( int i = 1; i <= n; i++ ){
    cout << i << "\t" << f(i) << endl;
  }

}

double f(int n){

  double sum = 0;

  for( int i = 1; i <= n; i++ ){
    sum += (1.0/pow(i, 2));
  }

  return (pow(6*sum, 0.5));

}
