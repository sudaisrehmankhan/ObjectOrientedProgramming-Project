#ifndef ORDER_H
#define ORDER_H

#include "Product.h"
#include <ctime>

const int MAX_CART_ITEMS = 100;

class Order {
public:
    int orderId;
    Product items[MAX_CART_ITEMS];
    int itemCount;
    std::string status;
    time_t orderDate;
    double total;

    Order();
    void displayStatus();
};

#endif
