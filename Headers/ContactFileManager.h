#ifndef CONTACTFILEMANAGER_H
#define CONTACTFILEMANAGER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "../Headers/contact.h"
using namespace std;

class UserFileManager{
public:
    vector<Contact> getContacts(int currUserId);
    
};

#endif