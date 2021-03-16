#include <iostream>

template <typename T>
T GetMax(T values[], int size){
  T currentMax = values[0];
  for( int i = 1; i < size; i++ ){
    if( values[i] > currentMax ){
      currentMax = values[i];
    }
  }
  return currentMax;
}

int main(){
  int someInts[4] = {52, 86, 23, 11};
  std::cout << GetMax <int> (someInts,4) << std::endl;

  long someLongs[5] = {523333333333, 86, 23, 11, 9};
  std::cout << GetMax <long> (someLongs,5) << std::endl;

  double someDoubles[4] = {52.4, 86.2, 23.0, 11};
  std::cout << GetMax <double> (someDoubles,4) << std::endl;

  char someChars[4] = {'a', 't', 'n', 'b'};
  std::cout << GetMax <char> (someChars,4) << std::endl;

  std::string someStrings[4] = {"Hey", "What?", "Hmmm...", "Okay"};
  std::cout << GetMax <std::string> (someStrings,4) << std::endl;
}
