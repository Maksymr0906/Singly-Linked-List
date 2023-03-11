#pragma once

#include <iostream>
#include <string>

class Book {
    friend std::ostream &operator<<(std::ostream &os, const Book &book);
    friend std::istream &operator>>(std::istream &is, Book &book);

private:
    std::string name_of_author;
    std::string name_of_book;
    int year_of_publication;
public:
    int get_year_of_publication() {return year_of_publication;}
    void set_year_of_publication(int year_of_publication) {this->year_of_publication = year_of_publication;}

    std::string get_name_of_author() {return name_of_author;}
    void set_name_of_author(std::string name_of_author) {this->name_of_author = name_of_author;}

    std::string get_name_of_book() {return name_of_book;}
    void set_name_of_book(std::string name_of_book) {this->name_of_book = name_of_book;}

    Book(std::string name_of_author_val = "None", std::string name_of_book_val = "None", int year_of_publication_val = 2023) 
    :name_of_author{name_of_author_val}, name_of_book{name_of_book_val}, year_of_publication{year_of_publication_val} {
    }

    ~Book() {
    }
};

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