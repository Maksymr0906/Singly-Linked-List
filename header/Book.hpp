#pragma once

#include <iostream>
#include <string>
#include <iomanip>

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