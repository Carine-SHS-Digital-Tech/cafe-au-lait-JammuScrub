#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <list>
using namespace std;

int TotalDineIn = 0;
int TotalTakeAway = 0;
int TotalOrders = 0;
int TotalCups = 0;
int TotalIncome = 0;
int TotalGST = 0;
int CappuccinoCount = 0;
int EspressoCount = 0;
int LatteCount = 0;
int IcedCoffeeCount = 0;

ofstream DailySummaryCSV("DailySummary.csv");


void DailySummary()
{

    cout << setw(13) << "Total Dine-In" << "|" << setw(20) << "Total Take-Away" << "|" << setw(20) << "Total Cups" << "|" << setw(20) << "Total Orders" << "|" << setw(20) << "Total Income" << "|" << setw(20) << "GST Collected" << "|" << endl;
    cout << setw(13) << TotalDineIn << "|" << setw(20) << TotalTakeAway << "|" << setw(20) << TotalCups << "|" << setw(20) << TotalOrders << "|" << setw(20) << TotalIncome << "|" << setw(20) << TotalGST << "|" << endl;

    DailySummaryCSV << "\nORDERS_COUNT,DINE-IN,TAKE-AWAY,CAPPUCCINO_COUNT,ESPRESSO_COUNT,LATTE_COUNT,ICED COFFEE_COUNT,CUPS_COUNT,GST_COLLECTED,DAILY_INCOME\n";
    DailySummaryCSV << TotalOrders << "," << TotalDineIn << "," << TotalTakeAway << "," << CappuccinoCount << "," << EspressoCount << "," << LatteCount << "," << IcedCoffeeCount << "," << TotalCups << "," << TotalGST << "," << TotalIncome;

    DailySummaryCSV.close();
    return;
}

void NewOrder()
{
    
    //Adds to the total order count
    TotalOrders += 1;
    // Adds an Order_Id to .csv file
    DailySummaryCSV << "\n" << TotalOrders << ",";
    
    string DiningMode;
    float tax = 0;

    //Selecting the dining mode + updating totals and adding extra charges
    while (true)
    { 
        cout << "\n1) Dine-In\n2) Take-Away\n";
        cin >> DiningMode;
        if (DiningMode == "1") 
        {
            tax = 0;
            TotalDineIn += 1;
            DailySummaryCSV << "Dine-In,";
            break;
        }
        else if (DiningMode == "2") 
        {
            tax = 0.05;
            TotalTakeAway += 1;
            DailySummaryCSV << "Take-Away,";
            break;
        }
        else {
            cout << "Error: Select Actual Option";
        }
    }

    //Printing options
    cout << "\nOptions:\n1) Cappuccino $3.00\n2) Espresso $2.25\n3) Latte $2.50\n4) Iced Coffee $2.50\n5) Finish Order\n";
    string OrderItem;
    
    list<string> ORDERITEMS;

    //Adding coffees to order 
    while (true)
    {  
        cin >> OrderItem;
        if (OrderItem == "1") 
        {
            ORDERITEMS.push_back("Cappuccino");
        }
        else if (OrderItem == "2") 
        {
            ORDERITEMS.push_back("Espresso");
        }
        else if (OrderItem == "3")
        {
            ORDERITEMS.push_back("Latte");
        }
        else if (OrderItem == "4")
        {
            ORDERITEMS.push_back("Iced Coffee");
        }
        else if (OrderItem == "5")
        {
            break;
        }
        else {
            cout << "Error: Select Actual Option\n";
        }
    }

    //Defining quantities
    int QuantityC = 0;
    int QuantityE = 0;
    int QuantityL = 0;
    int QuantityI = 0;

    //Counting coffees in the order
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

    //Adding to coffee count totals
    CappuccinoCount += QuantityC;
    EspressoCount += QuantityE;
    LatteCount += QuantityL;
    IcedCoffeeCount += QuantityI;

    //Adding order items to .csv
    DailySummaryCSV << "Cappuccino," << QuantityC << "," << 3*QuantityC << ",Espresso," << QuantityE << "," << 2.25 * QuantityE << ",Latte," << QuantityL << "," << 2.5 * QuantityL << ",Iced Coffee," << QuantityI << "," << 2.5 * QuantityI;

    //Calculating prices with gst
    float PriceC = 3 * 1.1 * QuantityC;
    float PriceE = 2.25 * 1.1 * QuantityE;
    float PriceL = 2.5 * 1.1 * QuantityL;
    float PriceI = 2.5 * 1.1 * QuantityI;

    //Calculating prices without gst
    float PriceGSTC = 3 * 1.1 * QuantityC - 3 * QuantityC;
    float PriceGSTE = 2.25 * 1.1 * QuantityE - 2.25 * QuantityE;
    float PriceGSTL = 2.5 * 1.1 * QuantityL - 2.5 * QuantityL;
    float PriceGSTI = 2.5 * 1.1 * QuantityI - 2.5 * QuantityI;

    //Adding to totals
    TotalIncome += (PriceC + PriceE + PriceL + PriceI);
    TotalGST += (PriceGSTC + PriceGSTE + PriceGSTL + PriceGSTI);
    TotalCups += (QuantityC + QuantityE + QuantityL + QuantityI);

    //Adding total cups and gst to .csv
    DailySummaryCSV << "," << (QuantityC + QuantityE + QuantityL + QuantityI);
    DailySummaryCSV << "," << (PriceGSTC + PriceGSTE + PriceGSTL + PriceGSTI);

    //Calculating extracharges
    float ExtraCharges = (PriceC + PriceE + PriceL + PriceI) * tax;

    //Adding extra charges to .csv
    DailySummaryCSV << "," << ExtraCharges;

    //Addubg amount due to .csv and total
    float AmountDue = (PriceC + PriceE + PriceL + PriceI) * (1 + tax);
    DailySummaryCSV << "," << AmountDue;

    //Printing the order table
    cout << "|  Quantity  |  Menu Item  |  Single Item + Ex GST  |  Single Item + GST  |  Total Line Item Value  |\n";
    cout << "|     " << QuantityC << "      |" << "  Cappuccino |" << "         $3.00          |" << "        $3.30        |";
    printf_s("          $%.2f          |\n", PriceC);
    cout << "|     " << QuantityE << "      |" << "   Espresso  |" << "         $2.25          |" << "        $2.47        |";
    printf_s("          $%.2f          |\n", PriceE);
    cout << "|     " << QuantityL << "      |" << "    Latte    |" << "         $2.50          |" << "        $2.75        |";
    printf_s("          $%.2f          |", PriceL);
    printf_s(" EXTRA CHARGES: $%.2f |\n", ExtraCharges);
    cout << "|     " << QuantityI << "      |" << " Iced Coffee |" << "         $2.50          |" << "        $2.75        |";
    printf_s("          $%.2f          |", PriceI);
    printf_s(" AMOUNT DUE: $%.2f    |\n", AmountDue);

    //Calculating the amount of change required
    float AmountTendered = 0;
    cout << "Amount Tendered: ";
    cin >> AmountTendered;
    float ChangeRequired = AmountTendered - AmountDue;

    //Printing the sales reciept
    cout << "SALES RECIEPT:\n";
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
    //Adding headings to .csv
    DailySummaryCSV << "ORDER_ID,TYPE,ITEM_1,QTY_1,EXGST_1,ITEM_2,QTY_2,EXGST_2,ITEM_3,QTY_3,EXGST_3,ITEM_4,QTY_4,EXGST_4,ORDER_CUPS,ORDER_GST,ORDER_TAX,ORDER_TOTAL";
    

    string OrderType;

    //Selecting new order and daily summary
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
