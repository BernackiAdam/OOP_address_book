#ifndef CONTACTFILEMANAGER_H
#define CONTACTFILEMANAGER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "contact.h"
using namespace std;

class ContactFileManager{
    const string CONTACT_FILE_NAME;
    const string TEMP_FILE_NAME;
    const int CURR_USER_ID;
    int lastUserId;
    string convertToFileLine(Contact);
public:
    ContactFileManager(int userId, string contactFileName = "contacts.txt", string tempFileName = "temp.txt")
    :CURR_USER_ID(userId), CONTACT_FILE_NAME(contactFileName), TEMP_FILE_NAME(tempFileName){this->lastUserId = 0;}
    vector<Contact> getContacts();
    int getLastUserId();
    void updateContactFile(Contact contact, bool edit = true);
    void addContactToFile(Contact contact);
};

#endif