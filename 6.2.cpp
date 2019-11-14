#include <iostream>
using namespace std;

double averageDigits(long);

int main(){

  long i;

  cout << "Enter your number: ";
  cin >> i;

  cout << "The average of the digits is: " << averageDigits(i) << endl;

}

double averageDigits(long n){

  double total;
  int count;

  while( n != 0 ){
    total += n % 10;
    n /= 10;
    count += 1;
  }

  return total/count;
}
    
