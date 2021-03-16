#include <iostream>
#include <iomanip>

int main(){

  double k1 = 0;
  double k2 = 0;
  double k3 = 0;
  double k4 = 0;

  double dx = 0.00000000001;

  double y = 1;

  for(double i=0;i<=1;i+=dx){

    k1 = y;
    k2 = y + dx * k1 / 2.0;
    k3 = y + dx * k2 / 2.0;
    k4 = y + dx * k3;

    y = y + (1.0/6) * dx * (k1 + 2*k2 + 2*k3 + k4);
    
  }

  std::cout << std::setprecision(15) << y << std::endl;

}
