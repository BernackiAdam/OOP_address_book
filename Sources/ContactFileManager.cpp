#include "../Headers/ContactFileManager.h"

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

void ContactFileManager::addContactToFile(Contact contact){
    fstream contactFile;
    contactFile.open(CONTACT_FILE_NAME, ios::app);
    if(!contactFile.good()){
        cout << "Cannot access contact file" << endl;
        return ;
    }
    contactFile << contact.getContactId() << "|";
    contactFile << contact.getUserId() << "|";
    contactFile << contact.getName() << "|";
    contactFile << contact.getSurname() << "|";
    contactFile << contact.getEmail() << "|";
    contactFile << contact.getNrTel() << "|";
    contactFile << contact.getAddress() << endl;

    contactFile.close();
}

void ContactFileManager::updateContactFile(const vector<Contact>& contacts){

}