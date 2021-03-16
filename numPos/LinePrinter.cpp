//
// Created by aes on 12/12/19.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string extractor;
    fstream fileData;

    fileData.open("herehere.txt", ios::in);

    if (fileData)
    {
        getline(fileData, extractor);

        while (fileData)
        {
            cout << extractor << endl;
            getline(fileData, extractor);
        }

        fileData.close();

    }
    else
    {
        cout << "The file didn't open!" << endl;
    }
}