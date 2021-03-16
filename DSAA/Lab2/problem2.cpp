#include <iostream>

template <typename T>
class Matrix{
  T values[5][7];
public:
  bool AddValue(int row,int col,T Value);
  bool BelongTo(T Value);
  void PrintRow(int row);
  void Print();
  T MaxValue();
};

template <typename T>
bool Matrix<T>::AddValue(int row, int col, T Value){
  values[row][col] = Value;
  return true;
}

template <typename T>
bool Matrix<T>::BelongTo(T Value){
  for( int i = 0; i < 5; i++ ){
    for( int j = 0; j < 7; j++ ){
      if( Value == values[i][j] )
	return true;
    }
  }
  return false;
}

template <typename T>
void Matrix<T>::PrintRow(int row){
  for( int i = 0; i < 7; i++ ){
    std::cout << values[row][i] << "\t";
  }
  std::cout << std::endl;
}

template <typename T>
void Matrix<T>::Print(){
  for( int i = 0; i < 5; i++ ){
    this->PrintRow(i);
  }
}

template <typename T>
T Matrix<T>::MaxValue(){
  T currentMax = values[0][0];
  for( int i = 0; i < 5; i++ ){
    for( int j = 0; j < 7; j++ ){
      if( values[i][j] > currentMax )
	currentMax = values[i][j];
    }
  }
  return currentMax;
}

int main(){
  return 0;
}
