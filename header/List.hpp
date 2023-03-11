#pragma once

#include "Book.hpp"

class List {
private:
    Book *book;
    List *next;
public:
    List() :next{nullptr}, book{nullptr} {}
    List(Book book_val, List next_val) 
    :book{new Book{book_val}}, next{new List{next_val}} {
    }
    ~List();

    bool is_list_empty() {return book == nullptr;}
    void push_back();
    void print();
};



