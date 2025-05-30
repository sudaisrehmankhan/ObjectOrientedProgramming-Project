#ifndef CUSTOMERWINDOW_H
#define CUSTOMERWINDOW_H

#include <QWidget>
#include <QListWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>

class CustomerWindow : public QWidget {
    Q_OBJECT

public:
    CustomerWindow(QStackedWidget *stack, QWidget *parent = nullptr);

private slots:
    void applyCoupon();
    void viewOrderHistory();
    void placeOrder();
    void addToCart();
    void showCart();

private:
    QListWidget *productList;
    QListWidget *cartList;
    QLineEdit *searchBar;
    QPushButton *cartButton;
    QPushButton *addToCartButton;
};

#endif
