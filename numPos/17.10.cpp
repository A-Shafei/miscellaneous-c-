//
// Created by aes on 12/12/19.
//

#include <iostream>
#include <string>
using namespace std;

int howMany(string text, char ch)
{
    if (text.length() == 0)
    {return 0;}

    if (text[text.length()-1] == ch)
    {return 1 + howMany(text.substr(0, text.length()-1), ch);}
    else
    {return howMany(text.substr(0, text.length()-1), ch);}
}

int main()
{
    string testString = "ithingi";

    cout << howMany(testString, 'i') << endl;

}