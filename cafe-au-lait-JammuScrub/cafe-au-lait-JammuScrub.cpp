// cafe-au-lait-JammuScrub.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;


void Type(string OrderType)
{

    if (OrderType == "1") {
        cout << "Bruh";
    }
    else if (OrderType == "2") {
        cout << "Not Bruh";
    }

}

int main()
{

    string OrderType;
    cout << "1) New Order\n2) Daily Summary\n";
    cin >> OrderType;
    Type(OrderType);

    return 0;
}
