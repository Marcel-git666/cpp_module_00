#include "Contact.hpp"
#include <iostream>

Contact::Contact(const std::string &firstName, const std::string &lastName,
                 const std::string &nickname, const std::string &phoneNumber,
                 const std::string &darkestSecret)
    : firstName(firstName), lastName(lastName), nickname(nickname),
      phoneNumber(phoneNumber), darkestSecret(darkestSecret) {}

Contact::Contact() {}

// Getter methods implementation
const std::string &Contact::getFirstName() const { return firstName; }

const std::string &Contact::getLastName() const { return lastName; }

const std::string &Contact::getNickname() const { return nickname; }

const std::string &Contact::getPhoneNumber() const { return phoneNumber; }

const std::string &Contact::getDarkestSecret() const { return darkestSecret; }

void Contact::display() const {
    std::cout << this->getFirstName() << '\n';
    std::cout << this->getLastName() << '\n';
    std::cout << this->getNickname() << '\n';
    std::cout << this->getPhoneNumber() << '\n';
    std::cout << this->getDarkestSecret() << '\n';
}
