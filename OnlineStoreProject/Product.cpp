#include "Product.h"

Product::Product() : quantity(0) {}

Product::Product(int i, string n, double p, int q)
    : id(i), name(n), price(p), quantity(q) {}

void Product::addRating(int rating) {
    if (rating >= 1 && rating <= 5) {
        ratings.push_back(rating);
        cout << "Rating added successfully!\n";
    } else {
        cout << "Invalid rating. Please enter a number between 1 and 5.\n";
    }
}

void Product::addReview(string review) {
    reviews.push_back(review);
    cout << "Review added successfully!\n";
}

void Product::displayReviews() {
    if (reviews.empty()) {
        cout << "No reviews yet.\n";
    } else {
        for (const auto& review : reviews) {
            cout << "- " << review << endl;
        }
    }
}

double Product::getAverageRating() {
    if (ratings.empty()) return 0;
    double sum = 0;
    for (int rating : ratings) {
        sum += rating;
    }
    return sum / ratings.size();
}
