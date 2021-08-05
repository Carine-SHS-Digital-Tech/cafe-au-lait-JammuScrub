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

    float tax = 0;

    while (true)
    { 
        cout << "\n1) Dine-In\n2) Take-Away\n";
        cin >> DiningMode;
        if (DiningMode == "1") 
        {
            tax = 0;
            break;
        }
        else if (DiningMode == "2") 
        {
            tax = 0.05;
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

    float EXTRACHARGES = (PriceC + PriceE + PriceL + PriceI) * tax;
    float AMOUNTDUE = (PriceC + PriceE + PriceL + PriceI) * (1 + tax);
    

    

    cout << "|  Quantity  |  Menu Item  |  Single Item + Ex GST  |  Single Item + GST  |  Total Line Item Value  |\n";
    cout << "|     " << QuantityC << "      |" << "  Cappuccino |" << "         $3.00          |" << "        $3.30        |";
    printf_s("          $%.2f          |\n", PriceC);
    cout << "|     " << QuantityE << "      |" << "   Espresso  |" << "         $2.25          |" << "        $2.47        |";
    printf_s("          $%.2f          |\n", PriceE);
    cout << "|     " << QuantityL << "      |" << "    Latte    |" << "         $2.50          |" << "        $2.75        |";
    printf_s("          $%.2f          |", PriceL);
    printf_s(" EXTRA CHARGES: $%.2f |\n", EXTRACHARGES);
    cout << "|     " << QuantityI << "      |" << " Iced Coffee |" << "         $2.50          |" << "        $2.75        |";
    printf_s("          $%.2f          |", PriceI);
    printf_s(" AMOUNT DUE: $%.2f    |\n", AMOUNTDUE);

    float AmountTendered = 0;
    cout << "Amount Tendered: ";
    cin >> AmountTendered;

    float ChangeRequired = AmountTendered - AMOUNTDUE;

    cout << "|  Quantity  |  Menu Item  |  Single Item + Ex GST  |  Single Item + GST  |  Total Line Item Value  |\n";
    cout << "|     " << QuantityC << "      |" << "  Cappuccino |" << "         $3.00          |" << "        $3.30        |";
    printf_s("          $%.2f          |\n", PriceC);
    cout << "|     " << QuantityE << "      |" << "   Espresso  |" << "         $2.25          |" << "        $2.47        |";
    printf_s("          $%.2f          |\n", PriceE);
    cout << "|     " << QuantityL << "      |" << "    Latte    |" << "         $2.50          |" << "        $2.75        |";
    printf_s("          $%.2f          |", PriceL);
    printf_s(" AMOUNT TENDERED: $%.2f|\n", AmountTendered);
    cout << "|     " << QuantityI << "      |" << " Iced Coffee |" << "         $2.50          |" << "        $2.75        |";
    printf_s("          $%.2f          |", PriceI);
    printf_s(" CHANGE REQUIRED: $%.2f |\n", ChangeRequired);

    return;
}

int main()
{

    string OrderType;
    

    while (true)
    {
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
        else {
            cout << "Error: Select Actual Option";
        }
    }

    return 0;
}
