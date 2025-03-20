#include "contact.h"

Contact::Contact(int userId, int contactId, string name, string surname, string email, string nrTel , string address){
    this->userId = userId;
    this->contactId = contactId;
    this->name = name;
    this->surname = surname;
    this->email = email;
    this->nrTel = nrTel;
    this->address = address;
}

int Contact::getContactId(){return this->contactId;}
int Contact::getUserId(){return this->userId;}
string Contact::getName(){return this->name;}
string Contact::getSurname(){return this->surname;}
string Contact::getEmail(){return this->email;}
string Contact::getNrTel(){return this->nrTel;}
string Contact::getAddress(){return this->address;}

void Contact::setContactId(int contactId){this->contactId = contactId;}
void Contact::setUserId(int userId){this->userId = userId;}
void Contact::setName(string name){this->name = name;}
void Contact::setSurname(string surname){this->surname = surname;}
void Contact::setEmail(string email){this->email = email;}
void Contact::setNrTel(string nrTel){this->nrTel = nrTel;}
void Contact::setAddress(string address){this->address = address;}