#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
  private:
    Contact contacts[8];
    int contactCount;
    int nextIndex;

  public:
    PhoneBook();

    void addContact(const Contact &newContact);
    void displayAllContacts() const;
    void displayContactByIndex(int index) const;
    int numContacts() const;
};

#endif
