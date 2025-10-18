#include "PhoneBook.hpp"
#include <iomanip>
#include <iostream>
#include <string>

PhoneBook::PhoneBook() {
    contactCount = 0;
    nextIndex = 0;
}

static void displayField(const std::string &text, size_t width);

void PhoneBook::addContact(const Contact &newContact) {
    contacts[nextIndex] = newContact;
    if (contactCount < 8) {
        contactCount++;
    }
    nextIndex = (nextIndex + 1) % 8;
}

void PhoneBook::displayAllContacts() const {
    int width = 10;
    std::cout << "========== +++++ PhoneBook +++++ ==========" << '\n';
    for (int i = 0; i < contactCount; i++) {
        std::cout << std::setw(width) << i << "|";
        displayField(contacts[i].getFirstName(), width);
        std::cout << "|";
        displayField(contacts[i].getLastName(), width);
        std::cout << "|";
        displayField(contacts[i].getNickname(), width);
        std::cout << '\n';
    }
}

void PhoneBook::displayContactByIndex(int index) const {
    contacts[index].display();
    contacts[index].getLastName();
    contacts[index].getNickname();
    contacts[index].getPhoneNumber();
    contacts[index].getDarkestSecret();
}

int PhoneBook::numContacts() const { return contactCount; }

static void displayField(const std::string &text, size_t width) {
    if (text.length() <= width) {
        std::cout << std::setw(width) << text;
    } else {
        std::string truncated = text.substr(0, width - 1) + ".";
        std::cout << truncated;
    }
}
