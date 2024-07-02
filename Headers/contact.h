#ifndef CONTACT_H
#define CONTACT_H
#include <iostream>
using namespace std;

class Contact{
    int userId;
    int contactId;
    string name;
    string surname;
    string email;
    string nrTel;
    string address;
public:
    Contact();

    int getContactId();
    int getUserId();
    string getName();
    string getSurname();
    string getEmail();
    string getNrTel();
    string getAddress();

    void setContactId(int);
    void setUserId(int);
    void setName(string);
    void setSurname(string);
    void setEmail(string);
    void setNrTel(string);
    void setAddress(string);

};

#endif    
    
