#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Drink{
  string name;
  double cost;
  int number;
};

void printer(Drink arr[]){
  cout << fixed;
  cout << setprecision(2);
  cout << left << setw(4) << "No";
  cout << left << setw(12) << "Drink Name";
  cout << left << setw(8) << "Cost";
  cout << left << setw(15) << "Availability" << endl;
  cout << "------------------------------------" << endl;
  for( int i = 0 ; i < 5 ; i++ ){
    cout << left << setw(4) << i+1;
    cout << left << setw(12) << arr[i].name;
    cout << left << setw(8) << arr[i].cost;
    cout << left << setw(15) << arr[i].number << endl;
  }
}

void cashier(int choice, double& total, Drink arr[]){
  if( choice == 0 ){
    return;
  }

  double cash;

  cout << "Cash: ";
  cin >> cash;

  if( arr[choice-1].number == 0 ){
    cout << "Sold out!" << endl;
    return;
  }
  if( cash < 0 ){
    cout << "Negative values are not allowed!" << endl;
    return;
  }
  if( cash > 10 ){
    cout << "Values greater than 10.00 are not allowed!" << endl;
    return;
  }
  if( cash < arr[choice-1].cost ){
    cout << "Item costs more than " << cash << endl;
    return;
  }

  cout << "Change: " << cash - arr[choice-1].cost << endl;
  total += arr[choice-1].cost;
  arr[choice-1].number--;
}
  

int main(){

  double total = 0;
  int choice;
  
  Drink d1;
  d1.name = "Cola";
  d1.cost = 5.00;
  d1.number = 5;

  Drink d2;
  d2.name = "Pepsi";
  d2.cost = 5.00;
  d2.number = 5;

  Drink d3;
  d3.name = "Lemon-Lime";
  d3.cost = 2.50;
  d3.number = 5;

  Drink d4;
  d4.name = "Grape Soda";
  d4.cost = 2.75;
  d4.number = 5;

  Drink d5;
  d5.name = "Cream Soda";
  d5.cost = 3.00;
  d5.number = 5;

  Drink stock[5] = {d1, d2, d3, d4, d5};
  
  printer(stock);

  cout << "\nEnter drink number to buy or 0 to exit" << endl;

  do{

    cout << "Your choice: ";
    cin >> choice;
    
    cashier(choice, total, stock);
    
  } while( choice != 0 );

  cout << "Money earned: " << total << endl;

}
