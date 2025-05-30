#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "User.h"
#include "Admin.h"
#include "Order.h"
#include "Coupon.h"

const int MAX_ORDERS = 50;
const int MAX_COUPONS = 10;

class Customer : public User {
    Product cart[MAX_CART_ITEMS];
    int cartCount;
    Order orders[MAX_ORDERS];
    int orderCount;
    Admin* admin;
    double discount;
    Coupon coupons[MAX_COUPONS];
    int couponCount;

public:
    Customer(Admin* a);

    void viewProducts();
    void searchProducts();
    void filterProducts();
    void addToCart();
    void removeFromCart();
    void viewCart();
    void applyCoupon();
    void placeOrder();
    void viewOrderHistory();
    void trackOrder();
    void addReview();
    void displayStoreInfo();
    void menu() override;
};

#endif
