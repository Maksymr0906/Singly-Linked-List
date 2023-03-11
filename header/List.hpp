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



List::~List() {
    delete book;
    delete next;
}

void List::push_back() {
    List *new_element = new List;
    new_element->book = new Book;
    std::cin >> *new_element->book;
    new_element->next = nullptr;

    if(this->is_list_empty()) {
        *this = *new_element;
        return ;
    }

    List *temp = this;
    while(temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = new_element;
}

void List::print() {
    if(this->is_list_empty()) {
        std::cout << "List is empty" << std::endl;
        return ;
    }

    List *temp = this;
    while(temp != nullptr) {
        std::cout << *temp->book << std::endl;
        temp = temp->next;
    }
}