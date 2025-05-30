#include "loginwindow.h"
#include "adminwindow.h"
#include "customerwindow.h"
#include <QMessageBox>

LoginWindow::LoginWindow(QStackedWidget *stack, QWidget *parent) : QWidget(parent), stackWidget(stack) {
    QLabel *emailLabel = new QLabel("Email:");
    QLabel *passwordLabel = new QLabel("Password:");
    emailField = new QLineEdit;
    passwordField = new QLineEdit;
    passwordField->setEchoMode(QLineEdit::Password);

    QPushButton *loginButton = new QPushButton("Login");

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(emailLabel);
    layout->addWidget(emailField);
    layout->addWidget(passwordLabel);
    layout->addWidget(passwordField);
    layout->addWidget(loginButton);
    setLayout(layout);

    connect(loginButton, &QPushButton::clicked, this, &LoginWindow::handleLogin);
}

void LoginWindow::handleLogin() {
    QString email = emailField->text();
    QString password = passwordField->text();

    if (email == "admin" && password == "admin123") {
        stackWidget->setCurrentIndex(1); // Admin window
    } else if (email == "customer" && password == "cust123") {
        stackWidget->setCurrentIndex(2); // Customer window
    } else {
        QMessageBox::warning(this, "Login Failed", "Invalid credentials");
    }
}
