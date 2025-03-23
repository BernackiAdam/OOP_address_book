#ifndef CONTACTMANAGER_H
#define CONTACTMANAGER_H
#include "contact.h"
#include "UserManager.h"
#include "ContactFileManager.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class ContactManager{
    int logedUserId;
    vector<Contact> contacts;
    ContactFileManager contactFileManager;
    string getlineValue();
    Contact getContactData(Contact);
    Contact editContactData(Contact);
    int getIdOfTheContact();
    string toLower(string);
    void displayContact(Contact);
public:
    ContactManager(int logedUserId);
    void addContact();
    void showContacts();
    void editContact();
    void deleteContact();
    void searchContact();
};

#endif