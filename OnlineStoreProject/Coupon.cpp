#include "Coupon.h"
#include <ctime>

Coupon::Coupon() {}

Coupon::Coupon(string c, double d, time_t e)
    : code(c), discount(d), expiry(e) {}

bool Coupon::isValid() {
    return time(0) < expiry;
}
