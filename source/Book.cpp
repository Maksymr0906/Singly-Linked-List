#include "Book.hpp"

std::ostream &operator<<(std::ostream &os, const Book &obj) {
    os  << std::setw(25) << obj.name_of_author      
        << std::setw(25) << obj.name_of_book        
        << std::setw(25) << obj.year_of_publication;

    return os;
}

std::istream &operator>>(std::istream &is, Book &obj) {
    std::cout << "Enter the name of author: ";
    is >> obj.name_of_author;

    std::cout << "Enter the name of book: ";
    is >> obj.name_of_book;

    std::cout << "Enter the year of publication: ";
    is >> obj.year_of_publication;

    return is;
}