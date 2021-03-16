//
// Created by aes on 12/24/19.
//

#include <iostream>
#include <random>
#include <ctime>
using namespace std;

double rGen()
{
    return (rand()+0.0)/RAND_MAX;
}

char GenerateCoinHTWithProb(double p)
{
    double r = rGen();
    if (r < p)
    {
        return 'H';
    }
    else
    {
        return 'T';
    }
}

int main() {
    srand(time(NULL));
    cout << GenerateCoinHTWithProb(0.3) << endl;
    cout << GenerateCoinHTWithProb(0.3) << endl;
    cout << GenerateCoinHTWithProb(0.3) << endl;
    cout << GenerateCoinHTWithProb(0.3) << endl;
    cout << GenerateCoinHTWithProb(0.3) << endl;
    cout << GenerateCoinHTWithProb(0.3) << endl;
    cout << GenerateCoinHTWithProb(0.3) << endl;
    cout << GenerateCoinHTWithProb(0.3) << endl;
    cout << GenerateCoinHTWithProb(0.3) << endl;
    cout << GenerateCoinHTWithProb(0.3) << endl;


    return 0;
}