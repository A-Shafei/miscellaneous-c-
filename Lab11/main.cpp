#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
    fstream fileObject;
    string fileName;
    int count = 0;
    string extracted;

    cout << "Enter the file name: ";
    cin >> fileName;

    fileObject.open(fileName.c_str(), ios::in);

    if (true)
    {
        getline(fileObject, extracted);
        count++;
        while (!fileObject.eof() && count < 10)
        {
            cout << extracted << endl;
            getline(fileObject, extracted);
            count++;
        }
    }
    else
    {
        cout << "Error! File could not be opened!" << endl;
    }

    if (count > 0 && count < 10)
    {
        cout << "Fewer than 10 lines. Entire file was displayed." << endl;
    }

    return 0;
}

///home/aes/CLionProjects/Lab11/testing.txt