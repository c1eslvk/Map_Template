#include <iostream>
#include "BookInformations.h"
using namespace std;

BookInformations::BookInformations() {
    author = "";
    category = "";
    numOfPages = 0;
    status = "";
}

BookInformations::BookInformations(string author, string category, int numOfPages, string status) {
    this->author = author;
    this->category = category;
    this->numOfPages = numOfPages;
    this->status = status;
}

BookInformations::BookInformations(const BookInformations& other) {
    author = other.author;
    category = other.category;
    numOfPages = other.numOfPages;
    status = other.status;
}

BookInformations& BookInformations::operator=(const BookInformations& other) {
    if (this != &other) {
        author = other.author;
        category = other.category;
        numOfPages = other.numOfPages;
        status = other.status;
    }
    return *this;
}

ostream& operator<<(ostream& os, const BookInformations& book) {
    os << "Author: " << book.author << ", Category: " << book.category << ", Number of pages: " << book.numOfPages << ", Status: " << book.status;
    return os;
}