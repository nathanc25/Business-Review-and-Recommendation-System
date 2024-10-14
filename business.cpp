#include <iostream>
#include <vector>
#include "business.h"

Business::Business() {}
Business::Business(std::string aname,
                   std::string acity,
                   int azip,
                   double arating,
                   int areviews,
                   int aprice,
                   std::string acategories) {
    name = aname;
    city = acity;
    zip = azip;
    rating = arating;
    reviews = areviews;
    price = aprice;
    categories = acategories;
}


std::string Business::getName() const {
    return name;
}
std::string Business::getCity() const {
    return city;
}
int Business::getZip() const {
    return zip;
}
double Business::getRating() const {
    return rating;
}
int Business::getReviews() const {
    return reviews;
}
int Business::getPrice() const {
    return price;
}
std::string Business::getCategories() const {
    return categories;
}

bool compareRating(const Business& b1, const Business& b2) {
    return b1.getRating() > b2.getRating();
}
