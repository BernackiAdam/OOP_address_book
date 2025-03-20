#include "ContactManager.h"

ContactManager::ContactManager(int logedUserId)
    :contactFileManager(logedUserId){
    this->logedUserId = logedUserId;
    this->contacts = contactFileManager.getContacts();
}

string ContactManager::enterAddress(){
    string address;
    cin.sync();
    getline(cin, address);
    return address;
}

void ContactManager::addContact(){
    Contact newContact;
    string item;
    cout << endl;
    cout << "Enter new friend's name: ";
    cin >> item;
        newContact.setName(item);
    cout << "Enter new friend's surname: ";
    cin >> item;
        newContact.setSurname(item);
    cout << "Enter new friend's email address: ";
    cin >> item;
        newContact.setEmail(item);
    cout << "Enter new friend's telephone number: ";
    cin >> item;
        newContact.setNrTel(item);
    cout << "Enter new friend's address: ";
    cin.ignore();
    item = enterAddress();
        newContact.setAddress(item);

    newContact.setUserId(this->logedUserId);
    newContact.setContactId(contactFileManager.getLastUserId()+1);
    
    contacts.push_back(newContact);
    contactFileManager.addContactToFile(newContact);
}

void ContactManager::showContacts(){
    for(auto contact : contacts){
        cout << "Friend id. " << contact.getContactId() << ": ";
        cout << contact.getName() << " ";
        cout << contact.getSurname() << ", ";
        cout << contact.getEmail() << ", " << endl;
        cout << contact.getNrTel() << ", ";
        cout << contact.getAddress() << endl;
        cout << endl;
    }
}