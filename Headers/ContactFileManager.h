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
public:
    ContactFileManager(int userId, string contactFileName = "contacts.txt", string tempFileName = "temp.txt")
    :CURRUSERID(userId), CONTACTFILENAME(contactFileName), TEMPFILENAME(tempFileName){};
    vector<Contact> getContacts();
    
};

#endif