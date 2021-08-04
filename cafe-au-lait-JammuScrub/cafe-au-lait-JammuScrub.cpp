// cafe-au-lait-JammuScrub.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <list>
using namespace std;



void DailySummary()
{

}

void NewOrder()
{
    string DiningMode;

    while (true)
    { 
        cout << "\n1) Dine-In\n2) Take-Away\n";
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

    cout << "\nOptions:\n1) Cappuccino $3.00\n2) Espresso $2.25\n3) Latte $2.50\n4) Iced Coffee $2.50\n5) Finish Order\n";
    int counter = 0;
    string OrderItem;
    
    list<string> ORDERITEMS;

    while (counter < 4)
    {  
        cin >> OrderItem;
        if (OrderItem == "1") 
        {
            ORDERITEMS.push_back("Cappuccino");
            counter += 1;
        }
        else if (OrderItem == "2") 
        {
            ORDERITEMS.push_back("Espresso");
            counter += 1;
        }
        else if (OrderItem == "3")
        {
            ORDERITEMS.push_back("Latte");
            counter += 1;
        }
        else if (OrderItem == "4")
        {
            ORDERITEMS.push_back("Iced Coffee");
            counter += 1;
        }
        else if (OrderItem == "5")
        {
            break;
        }
        else {
            cout << "Error: Select Actual Option\n";
        }
    }

    int QuantityC = 0;
    int QuantityE = 0;
    int QuantityL = 0;
    int QuantityI = 0;

    for (string CurrentItem : ORDERITEMS)
    {
        if (CurrentItem == "Cappuccino")
            QuantityC += 1;
        else if (CurrentItem == "Espresso")
            QuantityE += 1;
        else if (CurrentItem == "Latte")
            QuantityL += 1;
        else if (CurrentItem == "Iced Coffee")
            QuantityI += 1;
    }

    float PriceC = 3 * 1.1 * QuantityC;
    float PriceE = 2.25 * 1.1 * QuantityE;
    float PriceL = 2.5 * 1.1 * QuantityL;
    float PriceI = 2.5 * 1.1 * QuantityI;




    cout << "|  Quantity  |  Menu Item  |  Single Item + Ex GST  |  Single Item + GST  |  Total Line Item Value  |\n";
    cout << "|     " << QuantityC << "      |" << "  Cappuccino |" << "        $3.00           |" << "         $3.30        |" << "        $" << round(PriceC) << "        |" << "\n";
    cout << "|     " << QuantityE << "      |" << "   Espresso  |" << "        $2.25           |" << "         $2.47        |" << "        $" << round(PriceE) << "        |" << "\n";
    cout << "|     " << QuantityL << "      |" << "    Latte    |" << "        $2.50           |" << "         $2.75        |" << "        $" << round(PriceL) << "        |" << "\n";
    cout << "|     " << QuantityI << "      |" << " Iced Coffee |" << "        $2.50           |" << "         $2.75        |" << "        $" << round(PriceI) << "        |" << "\n";


}

int main()
{
    map<float, string> ITEMS = { {3.00, "Cappucino",},
                               {2.25, "Espresso",},
                               {2.50, "Latte",},
                               {2.50, "Iced Coffee",}
    };

    string OrderType;
    cout << "1) New Order\n2) Daily Summary\n";
    cin >> OrderType;

    while (true)
    {
        if (OrderType == "1") 
        {
            NewOrder();
            break;
        }
        else if (OrderType == "2") 
        {
            DailySummary();
            break;
        }
        else {
            cout << "Error: Select Actual Option";
        }
    }

    return 0;
}
