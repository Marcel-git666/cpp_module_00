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

    while (true) {
        std::cout << "Enter command: ADD, SEARCH, EXIT" << '\n';
        std::string command_line;
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
    if (phoneBook.numContacts() == 0) {
        std::cout << "PhoneBook is empty\n";
        return;
    }
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
        }
    } else {
        std::cout << "Error: Invalid index. Please enter a number." << '\n';
    }
}

static void handleAdd(PhoneBook &phoneBook) {
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

    std::cout << "Add new contact details:" << '\n';
    firstName = getInput("First name: ");
    if (std::cin.eof())
        return;
    lastName = getInput("Last name: ");
    if (std::cin.eof())
        return;
    nickname = getInput("Nickname: ");
    if (std::cin.eof())
        return;

    phoneNumber = getInput("Phone number: ");
    if (std::cin.eof())
        return;

    darkestSecret = getInput("Darkest secret: ");
    if (std::cin.eof())
        return;

    Contact newContact(firstName, lastName, nickname, phoneNumber,
                       darkestSecret);
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
