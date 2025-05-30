#include "adminwindow.h"
#include "Product.h"
#include <QLineEdit>
#include <QPushButton>
#include <QTableWidget>
#include <QHeaderView>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QLabel>

AdminWindow::AdminWindow(QStackedWidget *stack, QWidget *parent) : QWidget(parent) {
    QVBoxLayout *mainLayout = new QVBoxLayout;

    QLabel *title = new QLabel("Admin Dashboard - Product Management");
    mainLayout->addWidget(title);

    productTable = new QTableWidget(0, 4);
    productTable->setHorizontalHeaderLabels({ "ID", "Name", "Price", "Quantity" });
    productTable->horizontalHeader()->setStretchLastSection(true);
    productTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    mainLayout->addWidget(productTable);

    QHBoxLayout *inputLayout = new QHBoxLayout;
    nameInput = new QLineEdit;
    nameInput->setPlaceholderText("Product Name");
    priceInput = new QLineEdit;
    priceInput->setPlaceholderText("Price");
    qtyInput = new QLineEdit;
    qtyInput->setPlaceholderText("Quantity");
    QPushButton *addBtn = new QPushButton("Add Product");

    inputLayout->addWidget(nameInput);
    inputLayout->addWidget(priceInput);
    inputLayout->addWidget(qtyInput);
    inputLayout->addWidget(addBtn);

    mainLayout->addLayout(inputLayout);

    connect(addBtn, &QPushButton::clicked, this, &AdminWindow::addProduct);

    setLayout(mainLayout);
}

void AdminWindow::addProduct() {
    QString name = nameInput->text();
    double price = priceInput->text().toDouble();
    int quantity = qtyInput->text().toInt();

    if (name.isEmpty() || price <= 0 || quantity <= 0) {
        QMessageBox::warning(this, "Input Error", "Please enter valid name, price, and quantity.");
        return;
    }

    int row = productTable->rowCount();
    productTable->insertRow(row);
    productTable->setItem(row, 0, new QTableWidgetItem(QString::number(row + 1)));
    productTable->setItem(row, 1, new QTableWidgetItem(name));
    productTable->setItem(row, 2, new QTableWidgetItem(QString::number(price)));
    productTable->setItem(row, 3, new QTableWidgetItem(QString::number(quantity)));

    nameInput->clear();
    priceInput->clear();
    qtyInput->clear();
}
