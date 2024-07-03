#ifndef CONTACTMANAGER_H
#define CONTACTMANAGER_H
#include "contact.h"
#include "UserManager.h"
#include "ContactFileManager.h"
#include <iostream>
#include <vector>
using namespace std;

class ContactManager{
    UserManager userManager;
    ContactFileManager contactFileManager;
    vector<Contact> contacts;
    int logedUserId;
public:
    ContactManager();
    void addContact();
    void showContacts();

};

#endif