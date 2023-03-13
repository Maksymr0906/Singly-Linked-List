#include "List.hpp"

void create_list(List *&head, const int& number_of_elements) {
    Book *book = new Book();
    std::cin >> *book;
    head = new List();
    head->book = book;
    head->next = nullptr;

    List *current_node = head;

    while(head->size() < number_of_elements) {
        current_node->next = new List();
        book = new Book();
        std::cin >> *book;
        current_node->next->book = book;
        current_node->next->next = nullptr;

        current_node = current_node->next;
    }
}

List::~List() {
    delete book;
    book = nullptr;
}

int List::size() {
    int size{};
    List *temp = this;
    while(temp != nullptr) {
        temp = temp->next;
        size++;
    }
    return size;
}

void List::push_back(Book *book) {
    List *new_element = new List{book};

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

void List::push(Book *book, const int& position) {
    List *new_element = new List{book};

    if(this->size() < position) {
        this->push_back(book);
    }
    else if(this->size() == 0) {
        this->push_front(book);
    }
    else {
        List *temp = this;
        int counter{};
        while(counter != position - 2) {
            temp = temp->next;
            counter++;
        }
        new_element->next = temp->next;
        temp->next = new_element;
    }
}

void List::push_front(Book *book) {
    List *new_element = new List{book};

    if(this->is_list_empty()) {
        *this = *new_element;
        return ;
    }
    
    Book temp = *this->book;
    new_element->next = this->next;
    this->next = new_element;
    *this->book = *new_element->book;
    *new_element->book = temp;
}

void print_headline() {
    std::cout << std::setw(25) << "Name of author"
              << std::setw(25) << "Name of book"
              << std::setw(25) << "Year of publication" << std::endl;
}

void List::print() {
    if(this->is_list_empty()) {
        std::cout << std::endl << "List is empty" << std::endl;
        return ;
    }

    List *temp = this;

    print_headline();
    while(temp != nullptr) {
        std::cout << *temp->book << std::endl;
        temp = temp->next;
    }
}

void delete_list(List *&head) {
    List *temp = head;

    while(head->get_next() != nullptr) {
        temp = head;
        head = head->get_next();
        delete temp;
    }

    head->set_book(nullptr);
    head->set_next(nullptr);
}

