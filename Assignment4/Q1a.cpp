#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{

  string fileName;
  fstream inputHandle;
  fstream outputHandle;
  char ch;

  cout << "Enter the name of the file you want to encrypt: ";
  cin >> fileName;

  inputHandle.open(fileName.c_str(), ios::in);
  outputHandle.open(fileName.substr(0,fileName.length()-4).append("Encrypted.txt"), ios::out);

  while (inputHandle >> noskipws >> ch)
  {
    outputHandle << char(ch+4);
  }

  inputHandle.close();
  outputHandle.close();
  
}


