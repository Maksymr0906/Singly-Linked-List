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
    List *list = new List();
    Book book{};
    Option option;

    int number{};

    do  {
        instruction();
        option = get_option();

        switch (option) {
        case Option::CREATE_LIST:
            create_list(list);
            break;
        case Option::PRINT_LIST:
            list->print();
            break;
        case Option::ADD_ELEMENT_TO_LIST:
            break;
        case Option::DELETE_ELEMENT_FROM_LIST:
            break;
        case Option::FIND_BOOK_BY_KEYWORD:
            break;
        case Option::IS_LIST_EMPTY:
            std::cout << boolalpha << list->is_list_empty() << std::endl;
            break;
        case Option::DELETE_LIST:
            delete_list(list);
            break;
        case Option::EXIT:
            break;
        default:
            cout << "Incorrect option" << endl;
            break;
        }
    } while (option != Option::EXIT);
}