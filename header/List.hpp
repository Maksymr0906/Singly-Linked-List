#pragma once

#include "Book.hpp"
#include <iomanip>
#include <iostream>

class Node {
private:
    Book book;
    Node *next;
public:
    Node(): book{Book{}}, next{nullptr} {}
    Node(Book book): book{Book{book}}, next{nullptr} {}

    Node *get_next() {return this->next;}
    void set_next(Node *next) {this->next = next;}

    Book get_book() {return this->book;}
};

class List {
private:
    Node *head;

public:
    List(): head{nullptr} {}

    void push_back(Book book);
    void push_front(Book book);
    void pop_back();
    bool is_list_empty();
    void print();
};

void create_list(List *&list);
void delete_list(List *&list);