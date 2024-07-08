#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include "../Headers/UserManager.h"
#include "../Headers/ContactManager.h"
#include <iostream>

using namespace std;

class AddressBook{
    UserManager userManager;
    ContactManager *contactManager;
    User currUser; 
    User logout();
public:
    AddressBook();
    ~AddressBook(){
        delete contactManager;
        contactManager=NULL;
    }
    User getLogUser();
    User loginPage();
    void userPage(User& currUser);

};

#endif