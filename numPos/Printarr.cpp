//
// Created by aes on 12/12/19.
//

#include <iostream>

void Printarr(int * arr, int length)
{
    if (length == 0)
    {
        return;
    }
    std::cout << arr[0] << std::endl;
    Printarr(arr+1, length-1);
}

int main() {
    int test[8] = {6, 9, -2, 7, -8, 6, 4, -6};
    Printarr(test, 8);
}