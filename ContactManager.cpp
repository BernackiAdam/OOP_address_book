#include "ContactManager.h"

ContactManager::ContactManager(int logedUserId)
    :contactFileManager(logedUserId){
    this->logedUserId = logedUserId;
    this->contacts = contactFileManager.getContacts();
}

string ContactManager::getlineValue(){
    string value;
    cin.sync();
    getline(cin, value);
    return value;
}

void ContactManager::displayContact(Contact contact){
    cout << "Friend id. " << contact.getContactId() << ": ";
    cout << contact.getName() << " ";
    cout << contact.getSurname() << ", ";
    cout << contact.getEmail() << ", " << endl;
    cout << contact.getNrTel() << ", ";
    cout << contact.getAddress() << endl;
    cout << endl;
}

Contact ContactManager::getContactData(Contact contact = Contact()){
    string item;
    cout << endl;
    cout << "Enter friend's name: ";
    cin >> item;
        contact.setName(item);
    cout << "Enter friend's surname: ";
    cin >> item;
        contact.setSurname(item);
    cout << "Enter friend's email address: ";
    cin >> item;
        contact.setEmail(item);
    cout << "Enter friend's telephone number: ";
    cin >> item;
        contact.setNrTel(item);
    cout << "Enter friend's address: ";
    cin.ignore();
    item = getlineValue();
        contact.setAddress(item);
    return contact;
}

void ContactManager::addContact(){
    Contact newContact = getContactData();

    newContact.setUserId(this->logedUserId);
    newContact.setContactId(contactFileManager.getLastUserId()+1);
    
    contacts.push_back(newContact);
    contactFileManager.addContactToFile(newContact);
}

void ContactManager::showContacts(){
    if(contacts.size()==0){
        cout << endl;
        cout << "You dont have any contacts yet." << endl;
        cout << endl;
        return;
    }
    cout << endl;
    for(auto contact : contacts){
        // cout << "Friend id. " << contact.getContactId() << ": ";
        // cout << contact.getName() << " ";
        // cout << contact.getSurname() << ", ";
        // cout << contact.getEmail() << ", " << endl;
        // cout << contact.getNrTel() << ", ";
        // cout << contact.getAddress() << endl;
        // cout << endl;
        displayContact(contact);
    }
}

Contact ContactManager::editContactData(Contact contact) {
    int choice;

    while (true) {
        cout << "What would you like to change (enter a number)" << endl;
        cout << "1. Change Name: " << contact.getName() << endl;
        cout << "2. Change Surname: " << contact.getSurname() << endl;
        cout << "3. Change Email: " << contact.getEmail() << endl;
        cout << "4. Change Phone Number: " << contact.getNrTel() << endl;
        cout << "5. Change Address: " << contact.getAddress() << endl;
        cout << "6. Save and Exit" << endl;
        cout << "Select an option: ";
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
            case 1:
                cout << "Enter new name: ";
                contact.setName(getlineValue());
                break;
            case 2:
                cout << "Enter new surname: ";
                contact.setSurname(getlineValue());
                break;
            case 3:
                cout << "Enter new email: ";
                contact.setEmail(getlineValue());
                break;
            case 4:
                cout << "Enter new phone number: ";
                contact.setNrTel(getlineValue());
                break;
            case 5:
                cout << "Enter new address: ";
                contact.setAddress(getlineValue());
                break;
            case 6:
                cout << "Changes saved successfully." << endl;
                return contact;
            default:
                cout << "Invalid option, please try again." << endl;
        }
    }
}

int ContactManager::getIdOfTheContact(){
    showContacts();
    int editedContactId;
    cout << "Enter id of the contact: ";
    cin >> editedContactId;
    cout << endl;
    return editedContactId;
}

string ContactManager::toLower(string item){
    transform(item.begin(), item.end(), item.begin(), ::tolower);
    return item; 
}

void ContactManager::editContact(){
    int contactId = getIdOfTheContact();
    for(auto &contact : contacts){
        if(contact.getContactId() == contactId){
            contact = editContactData(contact);
            contactFileManager.updateContactFile(contact);
            return;
        }
    }
    cout << "There is no contact with this Id" << endl;
    return;
}

void ContactManager::deleteContact(){
    int contactId = getIdOfTheContact();
    for(auto &contact : contacts){
        if(contact.getContactId() == contactId){
            cout << "Are you sure that you want to delete " << contact.getName() << " " << contact.getSurname() << endl;
            cout << "Type yes or no: ";
            string consent = "";
            while(1){
                cin >> consent;
                consent = toLower(consent);
                if(toLower(consent) == "no"){
                    cout << "Contact will not be deleted" << endl;
                    return;
                } else if (toLower(consent) == "yes")
                {
                    contactFileManager.updateContactFile(contact, false);
                    this-> contacts = contactFileManager.getContacts();
                    cout << "Contact was deleted" << endl;
                    return;
                }else{
                    cout << "Wrong answer, try again: ";
                    continue;
                }
            } 
        } 
    }
    cout << "Contact with that id could not be found" << endl;
    return;
}


void ContactManager::searchContact() {
    if (contacts.empty()) {
        cout << "No contacts available to search." << endl;
        return;
    }

    cout << "Search by:" << endl;
    cout << "1. Name" << endl;
    cout << "2. Surname" << endl;
    cout << "3. Email" << endl;
    cout << "4. Phone Number" << endl;
    cout << "5. Address" << endl;
    cout << "Enter your choice: ";

    int choice;
    cin >> choice;
    cin.ignore(); 

    string searchValue;
    cout << "Enter search value: ";
    searchValue = getlineValue();

    vector<Contact> foundContacts;
    for (auto& contact : contacts) {
        switch (choice) {
            case 1:
                if (contact.getName() == searchValue)
                    foundContacts.push_back(contact);
                break;
            case 2:
                if (contact.getSurname() == searchValue)
                    foundContacts.push_back(contact);
                break;
            case 3:
                if (contact.getEmail() == searchValue)
                    foundContacts.push_back(contact);
                break;
            case 4:
                if (contact.getNrTel() == searchValue)
                    foundContacts.push_back(contact);
                break;
            case 5:
                if (contact.getAddress() == searchValue)
                    foundContacts.push_back(contact);
                break;
            default:
                cout << "Invalid option." << endl;
                return;
        }
    }

    if (foundContacts.empty()) {
        cout << "No contacts found." << endl;
    } else {
        cout << "Found contacts:" << endl;
        for (auto& contact : foundContacts) {
            displayContact(contact);
        }
    }
}