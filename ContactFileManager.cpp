#include "ContactFileManager.h"

int ContactFileManager::getLastUserId(){
    return this->lastUserId;
}

vector<Contact> ContactFileManager::getContacts(){
    fstream contactFile;
    vector<Contact> contacts;
    contactFile.open(CONTACT_FILE_NAME, ios::in);
    if(!contactFile.good()){
        cout << "Cannot access contact file" << endl;
        return contacts;
    }
    string line, item;
    int lineNr = 1;
    while(getline(contactFile, line) && line!=""){
        stringstream ss(line);
        Contact contact;
        while(getline(ss, item, '|')){
            switch(lineNr){
                case 1: contact.setContactId(stoi(item)); 
                        this->lastUserId = stoi(item); break;
                case 2: contact.setUserId(stoi(item)); break;
                case 3: contact.setName(item); break;
                case 4: contact.setSurname(item); break;
                case 5: contact.setEmail(item); break;
                case 6: contact.setNrTel(item); break;
                case 7: contact.setAddress(item); lineNr=0;
                        if(CURR_USER_ID == contact.getUserId()){
                            contacts.push_back(contact);
                        }
                        break;
            }
            lineNr++;
        }
    }
    contactFile.close();
    return contacts;
}

string ContactFileManager::convertToFileLine(Contact contact){
    string line;
    line +=to_string(contact.getContactId()) + "|";
    line +=to_string(contact.getUserId()) + "|";
    line +=contact.getName() + "|";
    line +=contact.getSurname() + "|";
    line +=contact.getEmail() + "|";
    line +=contact.getNrTel() + "|";
    line +=contact.getAddress();
    return line;

}

void ContactFileManager::addContactToFile(Contact contact){
    fstream contactFile;
    contactFile.open(CONTACT_FILE_NAME, ios::app);
    if(!contactFile.good()){
        cout << "Cannot access contact file" << endl;
        return ;
    }
    contactFile << convertToFileLine(contact) << endl;
    contactFile.close();
}

void ContactFileManager::updateContactFile(Contact contact, bool edit) {
    fstream contactFile, tempFile;
    contactFile.open(CONTACT_FILE_NAME, ios::in);
    tempFile.open(TEMP_FILE_NAME, ios::out);

    if (!contactFile.good() || !tempFile.good()) {
        cout << "Cannot access contact file" << endl;
        return;
    }

    string line, item;
    int lineNr = 1;
    
    while (getline(contactFile, line) && line != "") {
        stringstream ss(line);
        Contact tempContact;

        while (getline(ss, item, '|')) {
            switch (lineNr) {
                case 1: tempContact.setContactId(stoi(item)); break;
                case 2: tempContact.setUserId(stoi(item)); break;
                case 3: tempContact.setName(item); break;
                case 4: tempContact.setSurname(item); break;
                case 5: tempContact.setEmail(item); break;
                case 6: tempContact.setNrTel(item); break;
                case 7: tempContact.setAddress(item); lineNr = 0; break;
            }
            lineNr++;
        }

        if (tempContact.getContactId() == contact.getContactId()) {
            if (edit) {
                tempFile << convertToFileLine(contact) << endl; 
            }

        } else {
            tempFile << line << endl; 
        }
    }

    contactFile.close();
    tempFile.close();

    remove(CONTACT_FILE_NAME.c_str());
    rename(TEMP_FILE_NAME.c_str(), CONTACT_FILE_NAME.c_str());
}
