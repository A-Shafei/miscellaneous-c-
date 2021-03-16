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
    Expenses(string myName, double myIncome)
    {
        if (myName == "")
        {
            cout << "Name is empty!" << endl;
            exit(0);
        }
        if (myIncome < 0)
        {
            cout << "Income can't be negative!" << endl;
            exit(0);
        }
        Name = myName;
        Income = myIncome;
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
        int insertion_index = Number_of_spent_Expenses;
        for (int i=0; i<Number_of_spent_Expenses; i++)
        {
            if (myAmount < list[i])
            {
                insertion_index = i;
                break;
            }
        }
        if (insertion_index == Number_of_spent_Expenses) //if we can just add to the end and all present are smaller
        {
            list[insertion_index] = myAmount;
            Number_of_spent_Expenses++;
            return true;
        }
        double hand = myAmount;
        double temp;
        int workingIndex = insertion_index;
        while (workingIndex <= Number_of_spent_Expenses)
        {
            temp = list[workingIndex];
            list[workingIndex] = hand;
            hand = temp;
            workingIndex++;
        }
        Number_of_spent_Expenses++;
        return true;

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
    Expenses Amy("Amy", 20);

    Amy.ADD_EXPENSE(5.2);
    Amy.ADD_EXPENSE(6.3);
    Amy.ADD_EXPENSE(2.1);
    Amy.ADD_EXPENSE(11.5);
    Amy.ADD_EXPENSE(1.1);
    Amy.ADD_EXPENSE(2.3);

    Amy.PRINT_STATISTICS();

    return 0;
}
