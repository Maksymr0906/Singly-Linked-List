#pragma once

#include "Book.hpp"
#include <iomanip>

class List {
private:
    Book *book;
    List *next;
public:
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
    void push(Book *book, const int& position);
    void push_front(Book *book);
    void print();
    int size();
};

void print_headline();