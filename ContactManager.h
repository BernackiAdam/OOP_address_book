#ifndef CONTACTMANAGER_H
#define CONTACTMANAGER_H
#include "contact.h"
#include "UserManager.h"
#include "ContactFileManager.h"
#include <iostream>
#include <vector>
using namespace std;

class ContactManager{
    int logedUserId;
    vector<Contact> contacts;
    ContactFileManager contactFileManager;
    string enterAddress();
public:
    ContactManager(int logedUserId);
    void addContact();
    void showContacts();
};

#endif