#pragma once

#include "Book.hpp"
#include <iomanip>

class List {
friend void create_list(List *&head, const int& number_of_elements);

private:
    Book *book;
    List *next;
public:
    void set_book(Book *book) {this->book = book;}
    Book get_book() {return *book;}

    List *get_next() {return next;}
    void set_next(List *next) {this->next = next;}

    List():book{nullptr}, next{nullptr} {}
    List(Book book_val, List next_val) 
    :book{new Book{book_val}}, next{new List{next_val}} {
    }
    List(Book *book_val)
    :book{new Book{*book_val}}, next{nullptr} {
    }
    List(Book *book_val, List *next_val)
    :book{new Book{*book_val}}, next{new List{*next_val}} {
    }

    ~List();

    bool is_list_empty() {return book == nullptr;}
    void push_back(Book *book);
    void push(Book *book, const int &position);
    void push_front(Book *book);
    void print();
    int size();
    void pop_back();
    void pop_front();
    void pop(const int &position);
};

void print_headline();
void delete_list(List *&head);
