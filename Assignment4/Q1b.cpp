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

  cout << "Enter the name of the file you want to decrypt: ";
  cin >> fileName;

  inputHandle.open(fileName.c_str(), ios::in);
  outputHandle.open(fileName.substr(0,fileName.length()-13).append("Decrypted.txt"), ios::out);
  //this weird file naming is to have have get named to a pretty name like from
  //WhateverEncrypted.txt
  //to
  //WhateverDecrypted.txt

  while (inputHandle >> noskipws >> ch)
  {
    outputHandle << char(ch-4);
  }

  inputHandle.close();
  outputHandle.close();

}
