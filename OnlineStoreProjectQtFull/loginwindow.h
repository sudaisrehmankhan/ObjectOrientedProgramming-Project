#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QLabel>
#include <QStackedWidget>

class LoginWindow : public QWidget {
    Q_OBJECT

public:
    LoginWindow(QStackedWidget *stack, QWidget *parent = nullptr);

private slots:
    void handleLogin();

private:
    QLineEdit *emailField;
    QLineEdit *passwordField;
    QStackedWidget *stackWidget;
};

#endif
