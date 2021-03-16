#include <iostream>
#include <ctime>
using namespace std;

void swap(double * a, double * b)
{
    double temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(double list[], int n)
{
    bool swapped = 1;
    while (swapped)
    {
        swapped = 0;
        for (int i = 0; i < n-1; i++)
        {
            if (list[i] > list[i+1])
            {
                swap(&list[i], &list[i+1]);
                swapped = 1;
            }
        }
    }
}

int main() {

    double test[] = {5.0, 9.0, 4.0, 5.0, 2.0};
    bubbleSort(test, 5);

    for (int i = 0; i < 5; i++)
    {
        cout << test[i] << endl;
    }

    return 0;
}