#include "List.hpp"

List::~List() {
    delete book;
    book = nullptr;
    delete next;
    next = nullptr;
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