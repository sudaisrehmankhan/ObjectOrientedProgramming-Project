#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QWidget>
#include <QStackedWidget>
#include <QTableWidget>
#include <QLineEdit>

class AdminWindow : public QWidget {
    Q_OBJECT

public:
    AdminWindow(QStackedWidget *stack, QWidget *parent = nullptr);

private slots:
    void addProduct();

private:
    QTableWidget *productTable;
    QLineEdit *nameInput;
    QLineEdit *priceInput;
    QLineEdit *qtyInput;
};

#endif
