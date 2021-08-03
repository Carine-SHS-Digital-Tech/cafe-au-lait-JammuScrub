// cafe-au-lait-JammuScrub.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;



void NewOrder()
{

}

void DailySummary()
{
    string DiningMode;

    while (true)
    { 
        cout << "1) Dine-In\n2) Take-Away\n";
        cin >> DiningMode;
        if (DiningMode == "1") 
        {
            int tax = 1;
            break;
        }
        else if (DiningMode == "2") 
        {
            int tax = 1.05;
            break;
        }
        else {
            cout << "Error: Select Actual Option";
        }
    }

    cout << "Options:\n1) Cappuccino $3.00\n2) Espresso $2.25\n3) Latte $2.50\n4) Iced Coffee $2.50\n";
    int counter = 0;

    while (counter <= 4)
    {  
        cin >> OrderItem;
        if (DiningMode == "1") 
        {
            int tax = 1;
            break;
        }
        else if (DiningMode == "2") 
        {
            int tax = 1.05;
            break;
        }
        else {
            cout << "Error: Select Actual Option";
        }
    }





}

int main()
{
    
    string OrderType;
    cout << "1) New Order\n2) Daily Summary\n";
    cin >> OrderType;

    if (OrderType == "1") 
    {
        NewOrder();
    }
    else if (OrderType == "2") 
    {
        DailySummary();
    }

    return 0;
}
