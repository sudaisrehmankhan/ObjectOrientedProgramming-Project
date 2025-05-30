#ifndef COUPON_H
#define COUPON_H

#include <string>
#include <ctime>
using namespace std;

class Coupon {
public:
    string code;
    double discount;
    time_t expiry;

    Coupon();
    Coupon(string c, double d, time_t e);
    bool isValid();
};

#endif
