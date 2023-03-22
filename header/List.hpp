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
friend void delete_list(List *&list);

private:
    Node *head;

public:
    List(): head{nullptr} {}

    void push_back(const Book book);
    void push_in_specific_place(const Book book, const int &position);
    void push_front(const Book book);
    void pop_back();
    void pop_in_specific_place(const int& position);
    void pop_front();
    bool is_list_empty();
    void print();
};

void create_list(List *&list);
void delete_list(List *&list);
void print_headline();
void push_element_to_list(List *&list, const Book book);
int get_number(const std::string &message);