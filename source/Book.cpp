#include "Book.hpp"

std::ostream &operator<<(std::ostream &os, const Book &obj) {
    os  << std::setw(25) << obj.name_of_author      
        << std::setw(25) << obj.name_of_book        
        << std::setw(25) << obj.year_of_publication;

    return os;
}

std::istream &operator>>(std::istream &is, Book &obj) {
    std::cout << "Enter the name of the author: ";
    std::cin.ignore();
    getline(is, obj.name_of_author);

    std::cout << "Enter the name of the book: ";
    getline(is, obj.name_of_book);

    std::cout << "Enter the year of the publication: ";
    is >> obj.year_of_publication;

    return is;
}