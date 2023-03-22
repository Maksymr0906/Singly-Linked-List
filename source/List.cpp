#include "List.hpp"

void create_list(List *&list) {
    if(!list->is_list_empty()) {
        delete_list(list);
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
    if(list->is_list_empty()) {
        std::cout << "List is empty" << std::endl;
        return ;
    }

    Node *element_to_delete = list->head;
    while(list->head != nullptr) {
        list->head = list->head->get_next();
        delete element_to_delete;
        element_to_delete = list->head;
    }
}

bool List::is_list_empty() {
    return this->head == nullptr? true: false;
}

void push_element_to_list(List *&list, const Book book) {
    std::cout << "1 - push front\n"
              << "2 - push in specific place\n"
              << "3 - push back\n";

    int choice = get_number("Your choice: ");
    if(choice == 1) {
        list->push_front(book);
    }
    else if(choice == 2) {
        int position = get_number("Enter the position: ");
        list->push_in_specific_place(book, position);
    }
    else if(choice == 3) {
        list->push_back(book);
    }
    else std::cout << "Incorrect choice" << std::endl;
}

void List::push_back(const Book book) {
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

void List::push_in_specific_place(const Book book, const int &position) {
    if(this->is_list_empty()) {
        this->push_front(book);
        return ;
    }

    if(position == 0) {
        this->push_front(book);
        return ;
    }

    Node *temp = this->head;
    int size{1};
    while(temp != nullptr && size < position) {
        temp = temp->get_next();
        size++;
    }

    if(size == position) {
        Node *new_element = new Node{book};
        new_element->set_next(temp->get_next());
        temp->set_next(new_element);
    }
    else {
        this->push_back(book);
    }
}

void List::push_front(const Book book) {
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
    
    print_headline();
    Node *temp = this->head;

    while(temp != nullptr) {
        std::cout << temp->get_book() << std::endl;
        temp = temp->get_next();
    }
}

void delete_element_from_list(List *&list) {
    std::cout << "1 - pop front\n"
              << "2 - pop from specific place\n"
              << "3 - pop back\n";

    int choice = get_number("Your choice: ");
    if(choice == 1) {
        list->pop_front();
    }
    else if(choice == 2) {
        int position = get_number("Enter the position: ");
        list->pop_from_specific_place(position);
    }
    else if(choice == 3) {
        list->pop_back();
    }
    else std::cout << "Incorrect choice" << std::endl;
}

void List::pop_back() {
    if(this->is_list_empty()) {
        std::cout << "List is empty" << std::endl;
        return ;
    }

    if(this->head->get_next() == nullptr) {
        delete this->head;
        this->head = nullptr;
        return ;
    }
    
    Node *temp = this->head;
    while(temp->get_next()->get_next() != nullptr) {
        temp = temp->get_next();
    }

    Node *element_to_delete = temp->get_next();    
    temp->set_next(nullptr);
    delete element_to_delete;
    element_to_delete->set_next(nullptr);
}

void List::pop_from_specific_place(const int &position) {
    if(this->is_list_empty()) {
        return ;
    }

    if(position == 0) {
        this->pop_front();
        return ;
    }

    Node *temp = this->head;
    int size{1};
    while(temp != nullptr && size < position) {
        temp = temp->get_next();
        size++;
    }

    if(size == position) {
        Node *element_to_delete = temp->get_next();
        temp->set_next(temp->get_next()->get_next());
    }
    else std::cout << "This element does not exist" << std::endl;
}

void List::pop_front() {
    if(this->is_list_empty()) {
        std::cout << "List is empty" << std::endl;
        return ;
    }

    Node *temp = this->head;
    this->head = this->head->get_next();
    delete temp;
    temp = nullptr;
}

void List::find_book_by_keyword(const std::string &keyword) {
    if(this->is_list_empty()) {
        return ;
    }

    std::string name_of_book{};
    Node *temp = this->head;
    std::cout << "Book with this keyword: " << std::endl;
    while(temp != nullptr) {
        name_of_book = to_lower_case(temp->get_book().get_name_of_book());
        if(name_of_book.find(keyword) != std::string::npos) {
            std::cout << temp->get_book() << std::endl;
        }

        temp = temp->get_next();
    }
}

int get_number(const std::string &message) {
    int number;
    std::cout << message << std::endl;
    std::cin >> number;
    return number;
}

void print_headline() {
    std::cout << std::setw(25) << "Name of the author" 
              << std::setw(25) << "Name of the book"
              << std::setw(25) << "Year of the publication"
              << std::endl;
}

std::string to_lower_case(const std::string &str) {
    std::string temp{str};

    for (size_t i = 0; i < temp.size(); i++)    {
        temp[i] = tolower(temp[i]);
    }

    return temp;
}