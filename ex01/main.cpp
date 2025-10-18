#include <cctype>
#include <iostream>
#include <sstream>
#include <string>

#include "PhoneBook.hpp"

static std::string getInput(const std::string text);
static void toUpperCase(std::string &str);
static void handleSearch(const PhoneBook &phoneBook);
static void handleAdd(PhoneBook &phoneBook);

int main(void) {
    PhoneBook phoneBook;
    std::string command_line;
    Contact newContact("Adam", "Zed", "godblessed", "123456", "doesn't exists");

    phoneBook.addContact(newContact);
    newContact.setFirstName("Vitezslav Lockheart");
    phoneBook.addContact(newContact);
    phoneBook.displayAllContacts();

    while (true) {
        std::cout << "Enter command: ADD, SEARCH, EXIT" << '\n';
        if (std::getline(std::cin, command_line)) {
            toUpperCase(command_line);
            if (command_line == "EXIT") {
                break;
            } else if (command_line == "SEARCH") {
                handleSearch(phoneBook);
            } else if (command_line == "ADD") {
                handleAdd(phoneBook);
            }
        } else {
            std::cout << std::endl
                      << "Input stream closed. Exiting." << std::endl;
            break;
        }
    }
    std::cout << "Thanks for using my PhoneBook." << '\n';
    return 0;
}

static void toUpperCase(std::string &str) {
    for (size_t i = 0; i < str.length(); i++) {
        str[i] = std::toupper(str[i]);
    }
}

static void handleSearch(const PhoneBook &phoneBook) {
    phoneBook.displayAllContacts();
    std::cout << "Enter index: ";
    std::string line;
    if (!std::getline(std::cin, line)) {
        std::cout << std::endl
                  << "Input stream closed. Aborting search." << std::endl;
        return;
    }
    std::stringstream ss(line);
    int index;
    if (ss >> index && !(ss >> std::ws && !ss.eof())) {
        if (index >= 0 && index < phoneBook.numContacts())
            phoneBook.displayContactByIndex(index);
        else {
            std::cout << "Wrong index." << '\n';
            index = 0;
        }
    } else {
        std::cout << "Error: Invalid index. Please enter a number." << '\n';
    }
}

static void handleAdd(PhoneBook &phoneBook) {
    Contact newContact;
    std::string field;

    std::cout << "Add new contact detils:" << '\n';
    field = getInput("First name: ");
    if (std::cin.eof())
        return;
    newContact.setFirstName(field);

    field = getInput("Last name: ");
    if (std::cin.eof())
        return;
    newContact.setLastName(field);

    field = getInput("Nickname: ");
    if (std::cin.eof())
        return;
    newContact.setNickname(field);

    field = getInput("Phone number: ");
    if (std::cin.eof())
        return;
    newContact.setPhoneNumber(field);

    field = getInput("Darkest secret: ");
    if (std::cin.eof())
        return;
    newContact.setDarkestSecret(field);

    phoneBook.addContact(newContact);
    std::cout << "Contact added successfully!" << '\n';
}

static std::string getInput(const std::string text) {
    std::string input = "";

    while (true) {
        std::cout << text;
        if (!std::getline(std::cin, input)) {
            std::cout << std::endl
                      << "Input stream closed. Aborting ADD." << std::endl;
            return "";
        }
        if (!input.empty()) {
            break;
        }
        std::cout << "Field cannot be empty." << '\n';
    }
    return input;
}
