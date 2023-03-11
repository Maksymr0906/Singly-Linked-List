#include "Book.hpp"

std::ostream &operator<<(std::ostream &os, const Book &obj) {
    os  << "Name of author: "      << obj.name_of_author      << std::endl   
        << "Name of book: "        << obj.name_of_book        << std::endl
        << "Year of publication: " << obj.year_of_publication << std::endl;

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