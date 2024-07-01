#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include "../Headers/UserManager.h"
#include <iostream>

using namespace std;

class AddressBook{
    UserManager userManager;
    User currUser;
    void rejestration();
    void login();   
public:
    User getLogUser();
    int loginPage();
    void userPage(User currUser);
};

#endif