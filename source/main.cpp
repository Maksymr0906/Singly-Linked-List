#include <iostream>
#include "List.hpp"

using namespace std;

enum class Option {
    CREATE_LIST = 1,
    PRINT_LIST, 
    ADD_ELEMENT_TO_LIST,
    DELETE_ELEMENT_FROM_LIST,
    FIND_BOOK_BY_KEYWORD,
    IS_LIST_EMPTY,
    DELETE_LIST,
    EXIT
};

void instruction() {
    cout << "1 - Create the list"                       << endl
         << "2 - Print the list"                        << endl
         << "3 - Add element to the list"               << endl
         << "4 - Delete element from the list"          << endl
         << "5 - Find the book by keyword in the title" << endl
         << "6 - Check if the list is empty"            << endl
         << "7 - Delete the whole list"                 << endl
         << "8 - Exit"                                  << endl;
}

Option get_option() {
    int choice{};
    cout << "\nYour choice: ";
    cin >> choice;

    return static_cast<Option>(choice);
}

int main() {
    List *head = new List();
    Option option;
    int position{};
    Book *book = new Book();
    do  {
        instruction();
        option = get_option();

        switch (option) {
        case Option::CREATE_LIST: 
            cin >> *book;
            head->push_front(book);
            break;
        case Option::PRINT_LIST:
            head->print();
            break;
        case Option::ADD_ELEMENT_TO_LIST:
            cin >> *book;
            head->push_back(book);
            break;
        case Option::DELETE_ELEMENT_FROM_LIST:
            cin >> *book;
            cin >> position;
            head->push(book, position);
            break;
        case Option::FIND_BOOK_BY_KEYWORD:
            cout << head->size() << endl;
            break;
        case Option::IS_LIST_EMPTY:
            cout << boolalpha << head->is_list_empty() << endl;
            break;
        case Option::DELETE_LIST:
            break;
        case Option::EXIT:
            break;
        default:
            cout << "Incorrect option" << endl;
            break;
        }
    } while (option != Option::EXIT);
}