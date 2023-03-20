#include "List.hpp"

void create_list(List *&list) {
    if(!list->is_list_empty()) {
        //delete previous list
    }

    size_t number_of_elements{};
    Book book{};

    std::cout << "Enter the number of elements in a new list: ";
    std::cin >> number_of_elements;

    for (size_t i = 0; i < number_of_elements; i++) {
        std::cin >> book;
        list->push_back(book);
    }
}

void delete_list(List *&list) {

}

bool List::is_list_empty() {
    return this->head == nullptr? true: false;
}

void List::push_back(Book book) {
    if(this->is_list_empty()) {
        this->head = new Node{book};
        return ;
    }

    Node *new_element = new Node{book};
    Node *temp = this->head;
    while(temp->get_next() != nullptr) {
        temp = temp->get_next();
    }

    temp->set_next(new_element);
}

void List::push_front(Book book) {
    if(this->is_list_empty()) {
        this->head = new Node{book};
        return ;
    }

    Node *new_element = new Node{book};
    new_element->set_next(this->head);
    this->head = new_element;
}

void List::print() {
    if(this->is_list_empty()) {
        std::cout << "List is empty" << std::endl;
        return ;
    }

    Node *temp = this->head;

    while(temp != nullptr) {
        std::cout << temp->get_book() << std::endl;
        temp = temp->get_next();
    }
}

void List::pop_back() {
    if(this->is_list_empty()) {
        std::cout << "List is empty" << std::endl;
        return ;
    }

    Node *temp = this->head;
    while(temp->get_next() != nullptr) {
        temp = temp->get_next();
    }

    delete temp->get_next();
    temp->set_next(nullptr);
}