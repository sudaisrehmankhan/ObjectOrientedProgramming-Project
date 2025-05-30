#include "customerwindow.h"
#include <QLabel>
#include <QMessageBox>
#include <QInputDialog>
#include <QFile>
#include <QTextStream>

CustomerWindow::CustomerWindow(QStackedWidget *stack, QWidget *parent) : QWidget(parent) {
    QVBoxLayout *mainLayout = new QVBoxLayout;

    QLabel *title = new QLabel("Customer Dashboard - Browse Products");
    mainLayout->addWidget(title);

    productList = new QListWidget;
    QStringList sampleProducts = {
        "1. Laptop - $1000",
        "2. Phone - $500",
        "3. Keyboard - $50",
        "4. Mouse - $25"
    };
    productList->addItems(sampleProducts);
    mainLayout->addWidget(productList);

    addToCartButton = new QPushButton("Add to Cart");
    cartButton = new QPushButton("View Cart");

    QHBoxLayout *btnLayout = new QHBoxLayout;
    btnLayout->addWidget(addToCartButton);
    btnLayout->addWidget(cartButton);
    mainLayout->addLayout(btnLayout);

    cartList = new QListWidget;
    cartList->hide();
    mainLayout->addWidget(cartList);

    QPushButton *orderBtn = new QPushButton("Place Order");
    QPushButton *couponBtn = new QPushButton("Apply Coupon");
    QPushButton *historyBtn = new QPushButton("View Order History");

    mainLayout->addWidget(orderBtn);
    mainLayout->addWidget(couponBtn);
    mainLayout->addWidget(historyBtn);

    connect(addToCartButton, &QPushButton::clicked, this, &CustomerWindow::addToCart);
    connect(cartButton, &QPushButton::clicked, this, &CustomerWindow::showCart);
    connect(orderBtn, &QPushButton::clicked, this, &CustomerWindow::placeOrder);
    connect(couponBtn, &QPushButton::clicked, this, &CustomerWindow::applyCoupon);
    connect(historyBtn, &QPushButton::clicked, this, &CustomerWindow::viewOrderHistory);

    setLayout(mainLayout);
}

void CustomerWindow::addToCart() {
    QListWidgetItem *selectedItem = productList->currentItem();
    if (selectedItem) {
        cartList->addItem(selectedItem->text());
        QMessageBox::information(this, "Cart", "Item added to cart!");
    } else {
        QMessageBox::warning(this, "Cart", "Please select a product to add.");
    }
}

void CustomerWindow::showCart() {
    cartList->setVisible(!cartList->isVisible());
}

void CustomerWindow::placeOrder() {
    if (cartList->count() == 0) {
        QMessageBox::warning(this, "Order", "Your cart is empty!");
        return;
    }

    QFile file("orders.txt");
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out << "New Order:\n";
        for (int i = 0; i < cartList->count(); ++i) {
            out << "- " << cartList->item(i)->text() << "\n";
        }
        out << "----------------------------\n";
        file.close();
        QMessageBox::information(this, "Order", "Order placed and saved!");
        cartList->clear();
    } else {
        QMessageBox::critical(this, "Error", "Unable to save order to file.");
    }
}

void CustomerWindow::applyCoupon() {
    bool ok;
    QString code = QInputDialog::getText(this, "Apply Coupon", "Enter coupon code:", QLineEdit::Normal, "", &ok);

    if (ok && !code.isEmpty()) {
        if (code == "WELCOME10" || code == "SUMMER20") {
            QMessageBox::information(this, "Coupon", "Coupon applied! 10% discount.");
        } else {
            QMessageBox::warning(this, "Coupon", "Invalid or expired coupon.");
        }
    }
}

void CustomerWindow::viewOrderHistory() {
    QFile file("orders.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        QString content = in.readAll();
        QMessageBox::information(this, "Order History", content);
        file.close();
    } else {
        QMessageBox::warning(this, "Error", "Could not read order history.");
    }
}
