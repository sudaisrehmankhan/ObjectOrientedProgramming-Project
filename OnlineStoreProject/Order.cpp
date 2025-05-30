#include "Order.h"
#include <iostream>
using namespace std;

Order::Order() : orderId(0), itemCount(0), total(0) {
    status = "Processing";
    orderDate = time(0);
}

void Order::displayStatus() {
    cout << "Order ID: " << orderId << "\nStatus: " << status 
         << "\nDate: " << ctime(&orderDate) << "Total: $" << total << endl;
}
