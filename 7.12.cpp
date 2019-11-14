#include <iostream>
#include <ctime>
#include<chrono>
using namespace std;
using namespace std::chrono;

void selectionSort(int list[], int listSize){
  for (int i = 0; i < listSize - 1; i++){ // Find the minimum in the list[i..listSize-1]
    double currentMin = list[i];
    int currentMinIndex = i;
      
    for (int j = i + 1; j < listSize; j++){
      if (currentMin > list[j]){
	currentMin = list[j];
	currentMinIndex = j;
      }
    } // Swap list[i] with list[currentMinIndex] if necessary;
    if (currentMinIndex != i){
      list[currentMinIndex] = list[i];
      list[i] = currentMin;
    }
  }
}

int binarySearch(const int list[], int key, int listSize){
  int low = 0;
  int high = listSize - 1;
 
  while (high >= low){
      int mid = (low + high) / 2;
      if (key < list[mid])
	high = mid - 1;
      else if (key == list[mid])
	return mid;
      else
	low = mid + 1;
  }
 
  return -low - 1;
}

int linearSearch(const int list[], int key, int arraySize){
  for (int i = 0; i < arraySize; i++){
      if (key == list[i]){
	return i;
      }
  }
  return -1;
}

int main(){

  int key;
  cout << "Enter key: ";
  cin >> key;
  
  int guinea[100000];

  srand(time(NULL));
  
  for( int i=0 ; i<100000 ; i++ ){
    guinea[i] = rand();
  }

  long time0 = time(0);
  auto t0 = std::chrono::high_resolution_clock::now();

  linearSearch(guinea, key, 100000);

  long time1 = time(0);
  auto t1 = std::chrono::high_resolution_clock::now();

  selectionSort(guinea, 100000);

  long time2 = time(0);
  auto t2 = std::chrono::high_resolution_clock::now();

  binarySearch(guinea, key, 100000);

  long time3 = time(0);
  auto t3 = std::chrono::high_resolution_clock::now();
  
  auto duration1 = std::chrono::duration_cast<std::chrono::microseconds>( t1 - t0 ).count();
  auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
  auto duration3 = std::chrono::duration_cast<std::chrono::microseconds>( t3 - t2 ).count();

  std::cout << duration1 << endl << duration2 << endl << duration3 << endl;
    
  
}
