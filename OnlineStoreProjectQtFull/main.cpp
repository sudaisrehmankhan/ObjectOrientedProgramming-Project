#include <QApplication>
#include <QStackedWidget>
#include "loginwindow.h"
#include "adminwindow.h"
#include "customerwindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QStackedWidget *stack = new QStackedWidget;

    LoginWindow *login = new LoginWindow(stack);
    AdminWindow *admin = new AdminWindow(stack);
    CustomerWindow *customer = new CustomerWindow(stack);

    stack->addWidget(login);
    stack->addWidget(admin);
    stack->addWidget(customer);

    stack->setCurrentWidget(login);
    stack->resize(400, 300);
    stack->show();

    return app.exec();
}
