#ifndef HW4_BUSINESS_H
#define HW4_BUSINESS_H
#include <iostream>
#include <vector>

class Business {
public:
    Business();
    Business(std::string aname,
             std::string acity,
             int azip,
             double arating,
             int areviews,
             int aprice,
             std::string acategories);

    // accessors
    std::string getName() const;
    std::string getCity() const;
    int getZip() const;
    double getRating() const;
    int getReviews() const;
    int getPrice() const;
    std::string getCategories() const;

private:
    std::string name;
    std::string city;
    int zip;
    double rating;
    int reviews;
    int price;
    std::string categories;
};

bool compareRating(const Business& b1, const Business& b2);

#endif //HW4_BUSINESS_H
