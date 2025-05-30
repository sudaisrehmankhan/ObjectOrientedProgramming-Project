#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"
#include "Product.h"
#include <algorithm>

const int MAX_PRODUCTS = 100;

class Admin : public User {
    Product productList[MAX_PRODUCTS];
    int productCount;
    double netProfit;
    int nextProductId;

public:
    Admin();

    void addProduct();
    void viewProducts();
    void removeProduct();
    void showNetProfit();
    Product* getProductList();
    int getProductCount();
    void addToProfit(double amount);
    void analyticsDashboard();
    void viewAllReviews();
    void menu() override;
};

#endif
