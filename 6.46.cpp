#include <iostream>
#include <string>
using namespace std;

string swapCase(const string& s);

int main(){

  string s;
  
  cout << "Enter your string: " << endl;
  getline(cin, s);

  cout << swapCase(s) << endl;

}

string swapCase(const string& s){

  int size = s.length();
  string temp = s;
  
  for( int i = 0 ; i < size ; i++ ){

    if( isupper(s[i]) ){
      temp[i] = tolower(s[i]);
    }
    if( islower(s[i]) ){
      temp[i] = toupper(s[i]);
    }

  }

  return temp;

}
    
