#include <iostream>
#include <string>
#include "Admin.h"
#include "Customer.h"
using namespace std;

int main() {
    Admin admin;
    Customer customer(&admin);
    User* user = nullptr;

    string email, password;
    int choice;
    do {
        cout << "\nLogin as:\n1. Admin\n2. Customer\n3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter email: ";
                cin >> email;
                cout << "Enter password: ";
                cin >> password;
                if (email == "admin" && password == "admin123") {
                    admin.menu();
                } else {
                    cout << "Invalid credentials!\n";
                }
                break;
            case 2:
                cout << "Enter email: ";
                cin >> email;
                cout << "Enter password: ";
                cin >> password;
                if (email == "customer" && password == "cust123") {
                    customer.menu();
                } else {
                    cout << "Invalid credentials!\n";
                }
                break;
            case 3: cout << "Thank you! Exiting program.\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 3);

    return 0;
}
