#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Product {
public:
    int id;
    string name;
    double price;
    int quantity;
    vector<int> ratings;
    vector<string> reviews;

    Product();
    Product(int i, string n, double p, int q);

    void addRating(int rating);
    void addReview(string review);
    void displayReviews();
    double getAverageRating();
};

#endif
