#ifndef CONTACTFILEMANAGER_H
#define CONTACTFILEMANAGER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "../Headers/contact.h"
using namespace std;

class ContactFileManager{
    const string CONTACTFILENAME;
    const string TEMPFILENAME;
    const int CURRUSERID;
    int lastUserId;
public:
    ContactFileManager(int userId, string contactFileName = "contacts.txt", string tempFileName = "temp.txt")
    :CURRUSERID(userId), CONTACTFILENAME(contactFileName), TEMPFILENAME(tempFileName){this->lastUserId = 0;}
    vector<Contact> getContacts();
    int getLastUserId();
    void updateContactFile(const vector<Contact>& contacts);
    void addContactToFile(Contact contact);
};

#endif