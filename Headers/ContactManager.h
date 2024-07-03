#ifndef CONTACTMANAGER_H
#define CONTACTMANAGER_H
#include "contact.h"
#include "UserManager.h"
#include "ContactFileManager.h"
#include <iostream>
#include <vector>
using namespace std;

class ContactManager{
    ContactFileManager contactFileManager;
    vector<Contact> contacts;
    int logedUserId;
    string getAddress();
public:
    ContactManager(int logedUserId);
    void addContact();
    void showContacts();
};

#endif