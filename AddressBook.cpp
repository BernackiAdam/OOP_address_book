#include "AddressBook.h"

AddressBook::AddressBook(){
    contactManager = NULL;
    this->currUser = User();
}

bool AddressBook::isUserLoggedIn(){
    if(currUser.getId() == 0){
        return false;
    } else{
        return true;
    }
}

void AddressBook::logout(){
    this->currUser = User();
    delete contactManager;
    contactManager = NULL;
}

void AddressBook::registration(){
    userManager.registration();
}

void AddressBook::login(){
    this->currUser = userManager.login();
    if(currUser.getId() != 0){
        contactManager = new ContactManager(currUser.getId());
    }
}

void AddressBook::showContacts(){
    contactManager->showContacts();
}

void AddressBook::addContact(){
    contactManager->addContact();
}

void AddressBook::changePassword(){
    if(!userManager.changePassword(this->currUser)){
        logout();
    }
}

void AddressBook::setCurrentUser(User user){
    this->currUser=user;
}
