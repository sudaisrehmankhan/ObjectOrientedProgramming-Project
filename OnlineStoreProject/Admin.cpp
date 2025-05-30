#include "Admin.h"
#include <iostream>
using namespace std;

Admin::Admin() {
    username = "admin";
    password = "admin123";
    productList[0] = Product(1, "Laptop", 1000, 10);
    productList[1] = Product(2, "Phone", 500, 20);
    productCount = 2;
    netProfit = 0;
    nextProductId = 3;
}

void Admin::addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        cout << "Product list full.\n";
        return;
    }
    string name;
    double price;
    int quantity;
    cout << "Enter Product Name, Price, and Quantity: ";
    cin >> name >> price >> quantity;
    productList[productCount++] = Product(nextProductId++, name, price, quantity);
    cout << "Product added successfully with ID: " << (nextProductId-1) << ".\n";
}

void Admin::viewProducts() {
    cout << "Available Products:\n";
    for (int i = 0; i < productCount; i++) {
        cout << "ID: " << productList[i].id << ", Name: " << productList[i].name 
             << ", Price: $" << productList[i].price << ", Quantity: " << productList[i].quantity
             << ", Rating: " << productList[i].getAverageRating() << "/5\n";
    }
}

void Admin::removeProduct() {
    int id;
    cout << "Enter Product ID to remove: ";
    cin >> id;
    bool found = false;
    for (int i = 0; i < productCount; i++) {
        if (productList[i].id == id) {
            for (int j = i; j < productCount - 1; j++) {
                productList[j] = productList[j + 1];
            }
            productCount--;
            found = true;
            cout << "Product removed successfully.\n";
            break;
        }
    }
    if (!found) {
        cout << "Product not found.\n";
    }
}

void Admin::showNetProfit() {
    cout << "Net Profit: $" << netProfit << endl;
}

Product* Admin::getProductList() {
    return productList;
}

int Admin::getProductCount() {
    return productCount;
}

void Admin::addToProfit(double amount) {
    netProfit += amount;
}

void Admin::analyticsDashboard() {
    cout << "\n--- Admin Analytics Dashboard ---\n";
    cout << "Total Products: " << productCount << endl;
    cout << "Total Sales (Net Profit): $" << netProfit << endl;
    if (productCount > 0) {
        cout << "\nTop Rated Products:\n";
        for (int i = 0; i < min(3, productCount); i++) {
            cout << productList[i].name << " - Rating: " 
                 << productList[i].getAverageRating() << "/5\n";
        }
    }
}

void Admin::viewAllReviews() {
    cout << "\n--- All Product Reviews ---\n";
    for (int i = 0; i < productCount; i++) {
        if (!productList[i].reviews.empty()) {
            cout << "\nProduct: " << productList[i].name << " (ID: " << productList[i].id << ")\n";
            productList[i].displayReviews();
        }
    }
}

void Admin::menu() {
    int choice;
    do {
        cout << "\nAdmin Menu:\n";
        cout << "1. View Products\n2. Add Product\n3. Remove Product\n"
             << "4. Show Net Profit\n5. Analytics Dashboard\n"
             << "6. View All Reviews\n7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: viewProducts(); break;
            case 2: addProduct(); break;
            case 3: removeProduct(); break;
            case 4: showNetProfit(); break;
            case 5: analyticsDashboard(); break;
            case 6: viewAllReviews(); break;
            case 7: cout << "Exiting Admin Menu...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 7);
}
