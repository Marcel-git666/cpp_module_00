#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
private:
	Contact contacts[8];
	int		contactCount;
	int		nextIndex;

public:
	PhoneBook();
	~PhoneBook();

	void addContact(const Contact& newContact);
	void displayContact(const Contact& contact) const;
	void displayAllContacts() const;
	void searchContact(int index) const;
	int numContacts() const;
};

#endif
