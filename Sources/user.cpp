#include "../Headers/user.h"
User::User(){
    this->id = 0;
    this->login = "";
    this->password = "";
}
int User::getId(){
    return this->id;
}

string User::getLogin(){
    return this->login;
}

string User::getPassword(){
    return this->password;
}

void User::setId(int newId){
    this->id = newId;
}

void User::setLogin(string login){
    this->login = login;
}

void User::setPassword(string password){
    this->password = password;
}