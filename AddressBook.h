#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include "UserManager.h"
#include "ContactManager.h"
#include "user.h"
#include <iostream>

using namespace std;

class AddressBook{
    UserManager userManager;
    ContactManager *contactManager;
    User currUser; 
    void logout();
public:
    AddressBook();
    ~AddressBook(){
        delete contactManager;
        contactManager=NULL;
    }
    bool isUserLoggedIn();
    void registration();
    void login();
    void showContacts();
    void addContact();
    void changePassword();
    void setCurrentUser(User user);
    void editContact();
    void deleteContact();
    void searchContact();
};

#endif