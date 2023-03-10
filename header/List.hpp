#pragma once

#include "Book.hpp"

class List {
private:
    Book *book;
    List *next;
public:
    List() :next{nullptr}, book{nullptr} {}

    List(Book book_val, List next_val)
    :book{nullptr}, next{nullptr} {
        book = new Book;
        *book = book_val;

        next = new List;
        *next = next_val;
    }

    ~List() {
        delete book;
        delete next;
    }
};