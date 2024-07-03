#include "../Headers/ContactManager.h"

ContactManager::ContactManager()
    :contactFileManager(userManager.getUserData().getId()){
    this->logedUserId = userManager.getUserData().getId();
    this->contacts = contactFileManager.getContacts();
}

void ContactManager::addContact(){

}