#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <cmath>

#include "business.h"

std::string findName(std::string& line){
    int start = 0;
    // starting from the position start, and search the string variable line,
    // to find the first name string.
    int key_start = line.find("name", start);
    // if not found, return now
    if(key_start == std::string::npos){
        return "";
    }
    int value_start = key_start + 7;
    // remind them to use escape.
    int value_end = line.find("\"", value_start);
    int len = value_end - value_start;
    // go from start to end, but exclude the character at end.
    // when we use the substr(start, length) function on a std::string,
    // the substring includes the character at the start position,
    // and the length of the substring is length.
    // It does not include the character at the position start + length.
    std::string name = line.substr(value_start, len);
    return name;
}

std::string findCategories(std::string& line){
    int start = 0;
    // starting from the position start, and search the string variable line,
    // to find the first categories string.
    int key_start = line.find("categories", start);
    // if not found, return now
    if(key_start == std::string::npos){
        return "";
    }
    int value_start = key_start + 13;
    // remind them to use escape.
    int value_end = line.find("\"", value_start);
    int len = value_end - value_start;
    // go from start to end, but exclude the character at end.
    // when we use the substr(start, length) function on a std::string,
    // the substring includes the character at the start position,
    // and the length of the substring is length.
    // It does not include the character at the position start + length.
    std::string categories = line.substr(value_start, len);
    return categories;
}

double findRating(std::string& line){
    int start = 0;
    // starting from the position start, and search the string variable line,
    // to find the first stars string.
    int key_start = line.find("stars", start);
    // if not found, return now
    if(key_start == std::string::npos){
        return -1.0;
    }
    int value_start = key_start + 7;
    // remind them to use escape.
    int value_end = line.find("\"", value_start);
    // -1 here because this is not a string.
    int len = value_end - value_start - 1;
    // go from start to end, but exclude the character at end.
    // when we use the substr(start, length) function on a std::string,
    // the substring includes the character at the start position,
    // and the length of the substring is length.
    // It does not include the character at the position start + length.
    // convert this string to a double
    double stars = std::stod(line.substr(value_start, len));
    return stars;
}

int findPrice(std::string& line){
    int start = 0;
    // starting from the position start, and search the string variable line,
    // to find the first RestaurantsPriceRange2 string.
    int key_start = line.find("RestaurantsPriceRange2", start);
    // if not found, return now
    if(key_start == std::string::npos){
        return -1;
    }
    int value_start = key_start + 25;
    // remind them to use escape.
    int value_end = line.find("\"", value_start);
    // -1 here because this is not a string.
    int len = value_end - value_start;
    // go from start to end, but exclude the character at end.
    // when we use the substr(start, length) function on a std::string,
    // the substring includes the character at the start position,
    // and the length of the substring is length.
    // It does not include the character at the position start + length.
    // convert this string to an integer
    int price = std::stoi(line.substr(value_start, len));
    return price;
}

int findZip(std::string& line) {
    int start = 0;
    // starting from the position start, and search the string variable line,
    // to find the zip string.
    int key_start = line.find("postal_code", start);
    // if not found, return now
    if(key_start == std::string::npos){
        return -1;
    }
    int value_start = key_start + 14;
    // remind them to use escape.
    int value_end = line.find("\"", value_start);
    int len = value_end - value_start;
    // go from start to end, but exclude the character at end.
    // when we use the substr(start, length) function on a std::string,
    // the substring includes the character at the start position,
    // and the length of the substring is length.
    // It does not include the character at the position start + length.

    // check if zip code is valid
    std::string zipcode = line.substr(value_start, len);
    bool numbers = true;
    for (size_t i=0; i<zipcode.size();i++) {
        if (isdigit(zipcode[i])==false) {
            numbers=false;
            break;
        }
    }
    if (zipcode == "") {
        numbers=false;
    }

    if (numbers) {
        int Zip = std::stoi(line.substr(value_start, len));
        return Zip;
    } else {
        return -1;
    }

}

std::string findCity(std::string& line){
    int start = 0;
    // starting from the position start, and search the string variable line,
    // to find the city string.
    int key_start = line.find("city", start);
    // if not found, return now
    if(key_start == std::string::npos){
        return "";
    }
    int value_start = key_start + 7;
    // remind them to use escape.
    int value_end = line.find("\"", value_start);
    int len = value_end - value_start;
    // go from start to end, but exclude the character at end.
    // when we use the substr(start, length) function on a std::string,
    // the substring includes the character at the start position,
    // and the length of the substring is length.
    // It does not include the character at the position start + length.
    std::string city = line.substr(value_start, len);
    return city;
}

int findReviews(std::string& line){
    int start = 0;
    // starting from the position start, and search the string variable line,
    // to find the first review_count string.
    int key_start = line.find("review_count", start);
    // if not found, return now
    if(key_start == std::string::npos){
        return -1;
    }
    int value_start = key_start + 14;
    // remind them to use escape.
    int value_end = line.find("\"", value_start);
    // -1 here because this is not a string.
    int len = value_end - value_start;
    // go from start to end, but exclude the character at end.
    // when we use the substr(start, length) function on a std::string,
    // the substring includes the character at the start position,
    // and the length of the substring is length.
    // It does not include the character at the position start + length.
    // convert this string to an integer
    int reviews = std::stoi(line.substr(value_start, len));
    return reviews;
}

std::vector<std::string> makeWords(std::string& line) {
    // break up a line of categories into a vector
    std::string word = "";
    std::vector<std::string> words;

    // goes through each category by character
    for (size_t i=0; i<line.size(); i++) {
        if (i==line.size()-1) {
            word += line[i];
            words.push_back(word);
        }
        else if (line[i]==',' or line[i]==' ' or line[i]=='\\' or line[i]=='/') {
            words.push_back(word);
            word="";
        }
        else {
            word += line[i];
        }
    }
    return words;
}

std::string convertRating(double& rating) {
    std::string stars;
    double num = floor(rating);

    // finds amount of stars
    for (double i=0.0; i<num;i++) {
        stars+= "\u2605";
    }

    // finds if need to add half
    double diff = rating - num;
    if (diff==0.5) {
        stars+= "\u00BD";
    }

    return stars;
}

std::string convertPrice(int& price) {
    // check if there is price
    if (price==-1) {
        return " ";
    }
    else {
        std::string dollars = " ";
        // finds amount of dollars
        for (int i = 0; i<price; i++) {
            dollars += "$";
        }
        return dollars;
    }
}


// name, city, zip, rating, reviews, price, categories
int main(int argc, char* argv[]) {
    if(argc<5){
        std::cout << "Not enough arguments" << std::endl;
        exit(1);
    }

    const std::string inputstring = argv[1];
    const std::string outputstring = argv[2];
    const int zip = std::stoi(argv[3]);
    std::vector<std::string> usercategories;

    // set vector for categories
    for (int i = 4; i<argc; i++) {
        usercategories.push_back(std::string(argv[i]));
    }

    // open files
    std::ifstream input(inputstring);
    std::ofstream output(outputstring);

    // check files are open
    if (!input.is_open()) {
        std::cerr << "Failed to open the input file." << std::endl;
        exit(1);
    } if (!output.is_open()) {
        std::cerr << "Failed to open the output file." << std::endl;
        exit(1);
    }

    // find matching categories
    std::string line;
    std::vector<std::string> categories;
    std::list<Business> businesses;

    while (std::getline(input, line)) {
        std::string categoriesline = findCategories(line);
        categories = makeWords(categoriesline);

        // match zip code
        if (findZip(line) == zip) {
            for (size_t i=0; i<categories.size(); i++) {
                bool found = false;
                for (size_t j=0; j<usercategories.size(); j++) {
                    // if find matching category
                    if (categories[i] == usercategories[j]) {
                        found = true;
                        // make list of class objects
                        businesses.push_back(Business(findName(line), findCity(line), findZip(line), findRating(line),
                                                      findReviews(line), findPrice(line), findCategories(line)));
                        break;
                    }
                }
                // breaks out of for loop for efficiency
                if (found) {
                    break;
                }
            }
        }

    }

    // sort list by rating
    businesses.sort(compareRating);

    // output
    // if no businesses found
    if (businesses.size() == 0) {
        output << "Sorry, we couldn't find any results" << std::endl;
        exit(1);
    }

    // prints list of businesses
    int count = 0;
    std::list<Business>::iterator itr = businesses.begin();
    while(itr != businesses.end()){
        double ratingstring = (*itr).getRating();
        int pricestring = (*itr).getPrice();
        count++;
        output << "=====================" << std::endl;
        output << count << ". " << (*itr).getName() << std::endl;
        output << convertRating(ratingstring) << " " << (*itr).getRating() << " (" << (*itr).getReviews() << " reviews)" << std::endl;
        output << (*itr).getCity() << convertPrice(pricestring) << std::endl;
        output << (*itr).getCategories() << std::endl;
        ++itr;
    }
    output << "=====================" << std::endl;


    input.close();
    output.close();
    return 0;
}