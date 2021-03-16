#include <iostream>
using namespace std;

int showSmallest(int * arr, int length, int currentWinner)
{
    if (length == 0)
    {
        return currentWinner;
    }

    int myChallenger = arr[length-1];

    if (myChallenger < currentWinner)
    {
        return showSmallest(arr, length-1, myChallenger);
    }
    else
    {
        return showSmallest(arr, length-1, currentWinner);
    }
}

int showSmallest(int * arr, int length)
{
    showSmallest(arr, length, arr[0]);
}

int main()
{
    int arr[] = {62, 34, 70, 4, -60, 56};

    cout << showSmallest(arr, 6) << endl;
}