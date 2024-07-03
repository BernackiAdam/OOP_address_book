#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include "../Headers/UserManager.h"
#include "../Headers/ContactManager.h"
#include <iostream>

using namespace std;

class AddressBook{
    UserManager userManager;
    User currUser; 
    void logout();
public:
    User getLogUser();
    User loginPage();
    void userPage(User& currUser);
};

#endif