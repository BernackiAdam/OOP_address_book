#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include "../Headers/user.h"
#include "../Headers/FileManager.h"
using namespace std;

class UserManager{
    FileManager fileManager;
    vector<User> users;
    User logedUser;

    User checkUser(string login, int id=0);
    int getFreeId();
    int getUserIndex(User &currUser);
public:
    UserManager();
    void registration();
    void login();
    void logout();
    User getUserData();
    void changePassword(User& user);
    int getCurrUserId();

};

#endif