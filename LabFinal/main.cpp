#include <iostream>
#include <string>
using namespace std;

class Expenses
{
private:
    string Name;
    double Income;
    double list[5];
    int Number_of_spent_Expenses;

public:
    Expenses()
    {
        Name = "";
        Income = 0.0;
        list[0] = 0.0; list[1] = 0.0; list[2] = 0.0; list[3] = 0.0; list[4] = 0.0;
        Number_of_spent_Expenses = 0;
    }
    Expenses(string myName, double myIncome)
    {
        Name = myName;
        Income = myIncome;
        //Remember the "necessary checks"
        Number_of_spent_Expenses = 0;
    }
    void PRINT_EXPENSES()
    {
        cout << "Name: " << Name << endl;
        cout << "Income: " << Income << endl;
        cout << "Total Number of expenses: " << Number_of_spent_Expenses << endl;
        cout << "List of expenses:" << endl;
        for (int i = 0; i<Number_of_spent_Expenses; i++)
        {
            cout << list[i] << endl;
        }
    }
    double GET_LEFT_MONEY()
    {
        double total = Income;
        for (int i = 0; i<Number_of_spent_Expenses; i++)
        {
            total = total - list[i];
        }
        return total;
    }
    bool ADD_EXPENSE(double myAmount)
    {
        if (GET_LEFT_MONEY() - myAmount < 0)
        {
            cout << "Not sufficient money left in the wallet" << endl;
            return false;
        }
        if (Number_of_spent_Expenses == 5)
        {
            cout << "you have exceeded the number of transactions this week" << endl;
            return false;
        }
        int insertion_index;
        for (int i; i<Number_of_spent_Expenses; i++)
        {
            if (myAmount < list[i])
            {
                insertion_index = i;
                break;
            }
        }

    }
    void PRINT_STATISTICS()
    {
        double total = 0.0;
        for (int i = 0; i<Number_of_spent_Expenses; i++)
        {
            total = total + list[i];
        }
        double average = total / Number_of_spent_Expenses;
        cout << "Average Expenses: " << average << endl;
        cout << "Left Money: " << GET_LEFT_MONEY() << endl;
        cout << "Left number of expenses: " << 5 - Number_of_spent_Expenses << endl;
    }
};

int main() {
    double myAmount = 6.2;
    int insertion_index;
    double testList[5] = {2.1, 5.2, 6.3, 11.5, 100.1};
    for (int i; i<4; i++)
    {
        if (myAmount < testList[i])
        {
            insertion_index = i;
            break;
        }
    }
    cout << insertion_index << endl;


    return 0;
}