#ifndef PRODUCT_H
#define PRODUCT_H

#include <QString>

class Product {
public:
    Product(QString name = "", double price = 0.0);
    QString getName() const;
    double getPrice() const;

private:
    QString name;
    double price;
};

#endif // PRODUCT_H

