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
    Book *book = new Book();

    int number{};

    do  {
        instruction();
        option = get_option();

        switch (option) {
        case Option::CREATE_LIST: 
            cout << "Enter the number of elements: ";
            cin >> number;
            create_list(head, number);
            break;
        case Option::PRINT_LIST:
            head->print();
            break;
        case Option::ADD_ELEMENT_TO_LIST:
            break;
        case Option::DELETE_ELEMENT_FROM_LIST:
            break;
        case Option::FIND_BOOK_BY_KEYWORD:
            break;
        case Option::IS_LIST_EMPTY:
            cout << boolalpha << head->is_list_empty() << endl;
            break;
        case Option::DELETE_LIST:
            delete_list(head);
            break;
        case Option::EXIT:
            break;
        default:
            cout << "Incorrect option" << endl;
            break;
        }
    } while (option != Option::EXIT);
}