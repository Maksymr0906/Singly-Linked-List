#include "List.hpp"

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

