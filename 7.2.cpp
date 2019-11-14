#include <iostream>
using namespace std;

int main(){

  int nums[6];
  int hand;
  int max, min;

  
  for( int i = 0; i < 6; i++ ){
    cout << "Enter num" << i+1 << ": ";
    cin >> hand;
    nums[i] = hand;
  }

  max = nums[0];
  min = nums[0];

  for( int i = 0; i < 6; i++ ){
    if( nums[i] > max ){
      max = nums[i];
    }
    if( nums[i] < max ){
      min = nums[i];
    }
  }

  cout << "Max is: " << max << endl;
  cout << "Min is: " << min << endl;

}
