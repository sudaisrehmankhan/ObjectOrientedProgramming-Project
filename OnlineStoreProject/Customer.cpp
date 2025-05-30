#include "Customer.h"
#include <iostream>
using namespace std;

Customer::Customer(Admin* a) {
    admin = a;
    username = "customer";
    password = "cust123";
    cartCount = 0;
    orderCount = 0;
    discount = 0;
    couponCount = 2;
    coupons[0] = Coupon("WELCOME10", 0.1, time(0) + 30*24*60*60);
    coupons[1] = Coupon("SUMMER20", 0.2, time(0) + 15*24*60*60);
}

void Customer::viewProducts() {
    Product* productList = admin->getProductList();
    int productCount = admin->getProductCount();
    for (int i = 0; i < productCount; i++) {
        cout << "ID: " << productList[i].id << ", Name: " << productList[i].name 
             << ", Price: $" << productList[i].price << ", Quantity: " << productList[i].quantity
             << ", Rating: " << productList[i].getAverageRating() << "/5\n";
    }
}

void Customer::searchProducts() {
    string term;
    cout << "Enter search term: ";
    cin >> term;
    Product* productList = admin->getProductList();
    int productCount = admin->getProductCount();
    bool found = false;
    for (int i = 0; i < productCount; i++) {
        if (productList[i].name.find(term) != string::npos) {
            if (!found) cout << "Search Results:\n";
            found = true;
            cout << "ID: " << productList[i].id << ", Name: " << productList[i].name 
                 << ", Price: $" << productList[i].price << ", Rating: " 
                 << productList[i].getAverageRating() << "/5\n";
        }
    }
    if (!found) cout << "No products found.\n";
}

void Customer::filterProducts() {
    int choice;
    cout << "Filter by:\n1. Price Range\n2. Minimum Rating\nEnter choice: ";
    cin >> choice;
    Product* productList = admin->getProductList();
    int productCount = admin->getProductCount();
    bool found = false;
    if (choice == 1) {
        double minP, maxP;
        cout << "Enter min and max price: ";
        cin >> minP >> maxP;
        for (int i = 0; i < productCount; i++) {
            if (productList[i].price >= minP && productList[i].price <= maxP) {
                if (!found) cout << "Filtered Products:\n";
                found = true;
                cout << "ID: " << productList[i].id << ", Name: " << productList[i].name 
                     << ", Price: $" << productList[i].price << "\n";
            }
        }
    } else if (choice == 2) {
        double minRating;
        cout << "Enter minimum rating: ";
        cin >> minRating;
        for (int i = 0; i < productCount; i++) {
            if (productList[i].getAverageRating() >= minRating) {
                if (!found) cout << "Filtered Products:\n";
                found = true;
                cout << "ID: " << productList[i].id << ", Name: " << productList[i].name 
                     << ", Rating: " << productList[i].getAverageRating() << "/5\n";
            }
        }
    }
    if (!found) cout << "No products match.\n";
}

void Customer::addToCart() {
    int id, qty;
    cout << "Enter Product ID: "; cin >> id;
    cout << "Enter Quantity: "; cin >> qty;
    Product* productList = admin->getProductList();
    int productCount = admin->getProductCount();
    for (int i = 0; i < productCount; i++) {
        if (productList[i].id == id) {
            if (productList[i].quantity < qty) {
                cout << "Only " << productList[i].quantity << " in stock.\n";
                return;
            }
            for (int j = 0; j < qty && cartCount < MAX_CART_ITEMS; j++) {
                cart[cartCount++] = productList[i];
            }
            cout << "Added to cart.\n";
            return;
        }
    }
    cout << "Product not found.\n";
}

void Customer::removeFromCart() {
    if (cartCount == 0) {
        cout << "Cart is empty.\n";
        return;
    }
    int id;
    cout << "Enter Product ID to remove: ";
    cin >> id;
    bool found = false;
    for (int i = 0; i < cartCount; i++) {
        if (cart[i].id == id) {
            for (int j = i; j < cartCount - 1; j++) {
                cart[j] = cart[j + 1];
            }
            cartCount--;
            found = true;
            cout << "Removed from cart.\n";
            break;
        }
    }
    if (!found) cout << "Product not in cart.\n";
}

void Customer::viewCart() {
    if (cartCount == 0) {
        cout << "Your cart is empty.\n";
        return;
    }
    double total = 0;
    cout << "Your Cart:\n";
    for (int i = 0; i < cartCount; i++) {
        cout << "ID: " << cart[i].id << ", Name: " << cart[i].name 
             << ", Price: $" << cart[i].price << "\n";
        total += cart[i].price;
    }
    cout << "Total: $" << total << "\n";
    if (discount > 0) {
        cout << "Discount: " << (discount*100) << "%\n";
        cout << "Final Total: $" << total * (1 - discount) << "\n";
    }
}

void Customer::applyCoupon() {
    string code;
    cout << "Available Coupons:\n";
    for (int i = 0; i < couponCount; i++) {
        if (coupons[i].isValid()) {
            cout << "Code: " << coupons[i].code << ", Discount: " 
                 << (coupons[i].discount*100) << "%\n";
        }
    }
    cout << "Enter coupon code: ";
    cin >> code;
    for (int i = 0; i < couponCount; i++) {
        if (coupons[i].code == code && coupons[i].isValid()) {
            discount = coupons[i].discount;
            cout << "Coupon applied!\n";
            return;
        }
    }
    cout << "Invalid or expired coupon.\n";
}

void Customer::placeOrder() {
    if (cartCount == 0) {
        cout << "Cart is empty.\n";
        return;
    }
    string name, email, phone, address;
    cout << "Enter Name: "; cin >> name;
    cout << "Enter Email: "; cin >> email;
    cout << "Enter Phone: "; cin >> phone;
    cout << "Enter Address: "; cin >> address;
    Product* productList = admin->getProductList();
    int productCount = admin->getProductCount();
    for (int i = 0; i < cartCount; i++) {
        for (int j = 0; j < productCount; j++) {
            if (productList[j].id == cart[i].id) {
                productList[j].quantity--;
                break;
            }
        }
    }
    if (orderCount < MAX_ORDERS) {
        orders[orderCount].orderId = 1000 + orderCount;
        orders[orderCount].itemCount = cartCount;
        orders[orderCount].status = "Processing";
        orders[orderCount].orderDate = time(0);
        double total = 0;
        for (int i = 0; i < cartCount; i++) {
            orders[orderCount].items[i] = cart[i];
            total += cart[i].price;
        }
        total -= total * discount;
        orders[orderCount].total = total;
        admin->addToProfit(total);
        cout << "Order placed! Order ID: " << orders[orderCount].orderId 
             << ", Total: $" << total << "\n";
        orderCount++;
        cartCount = 0;
        discount = 0;
    } else {
        cout << "Order limit reached.\n";
    }
}

void Customer::viewOrderHistory() {
    if (orderCount == 0) {
        cout << "No orders yet.\n";
        return;
    }
    for (int i = 0; i < orderCount; i++) {
        cout << "\nOrder ID: " << orders[i].orderId 
             << "\nDate: " << ctime(&orders[i].orderDate)
             << "Status: " << orders[i].status 
             << "\nTotal: $" << orders[i].total << "\n";
    }
}

void Customer::trackOrder() {
    if (orderCount == 0) {
        cout << "No orders to track.\n";
        return;
    }
    int id;
    cout << "Enter Order ID: ";
    cin >> id;
    for (int i = 0; i < orderCount; i++) {
        if (orders[i].orderId == id) {
            orders[i].displayStatus();
            return;
        }
    }
    cout << "Order not found.\n";
}

void Customer::addReview() {
    int productId;
    cout << "Enter Product ID to review: ";
    cin >> productId;
    Product* productList = admin->getProductList();
    int productCount = admin->getProductCount();
    for (int i = 0; i < productCount; i++) {
        if (productList[i].id == productId) {
            int rating;
            string review;
            cout << "Enter rating (1-5): ";
            cin >> rating;
            productList[i].addRating(rating);
            cout << "Enter your review: ";
            cin.ignore();
            getline(cin, review);
            productList[i].addReview(review);
            return;
        }
    }
    cout << "Product not found.\n";
}

void Customer::displayStoreInfo() {
    cout << "\n=== WELCOME TO OUR STORE ===\n";
    cout << "Best deals on electronics!\n";
    cout << "Open 24/7 online\n";
    cout << "Customer support: support@store.com\n\n";
}

void Customer::menu() {
    displayStoreInfo();
    int choice;
    do {
        cout << "\nCustomer Menu:\n";
        cout << "1. View Products\n2. Search Products\n3. Filter Products\n"
             << "4. Add to Cart\n5. Remove from Cart\n6. View Cart\n"
             << "7. Apply Coupon\n8. Place Order\n9. View Order History\n"
             << "10. Track Order\n11. Add Review\n12. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: viewProducts(); break;
            case 2: searchProducts(); break;
            case 3: filterProducts(); break;
            case 4: addToCart(); break;
            case 5: removeFromCart(); break;
            case 6: viewCart(); break;
            case 7: applyCoupon(); break;
            case 8: placeOrder(); break;
            case 9: viewOrderHistory(); break;
            case 10: trackOrder(); break;
            case 11: addReview(); break;
            case 12: cout << "Exiting Customer Menu...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 12);
}
