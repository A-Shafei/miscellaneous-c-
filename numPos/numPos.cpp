//
// Created by aes on 12/11/19.
//

#include <iostream>

int numPos(int arr[], int length)
{
    if (length == 0)
    {
        return 0;
    }
    else if (arr[length-1] > 0)
    {
        return 1 + numPos(arr, length - 1);
    }
    else
    {
        return numPos(arr, length - 1);
    }
}

int main() {
    int test[8] = {6, 9, -2, 7, -8, 6, 4, -6};
    std::cout << numPos(test, 8) << std::endl;
}