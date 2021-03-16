#include <iostream>

int main(){
  int darts;
  int counter = 0;
  int totalCounter = 0;
  double pi;
  std::cout << "Please enter the number of darts" << std::endl;
  std::cin >> darts;

  srand(time(NULL));

  double x;
  double y;
  for(int i = 0; i < darts; i++){
    x = ( (rand() % (2 * darts + 1)) - darts + 0.0 ) / darts;
    y = ( (rand() % (2 * darts + 1)) - darts + 0.0 ) / darts;
    if( x*x + y*y <= 1 ){
      counter += 1;
    }
    totalCounter += 1;
  }
  pi = (4 * counter + 0.0) / totalCounter;
  std::cout << "PI Estimate is: " << pi << std::endl;
    
}
