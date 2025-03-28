#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include "user.h"
#include "UserFileManager.h"
using namespace std;

class UserManager{
    UserFileManager fileManager;
    vector<User> users;

    User checkUser(string login, int id=0);
    int getFreeId();
    int getUserIndex(User &currUser);
    bool checkPassword(string password);
public:
    UserManager();
    void registration();
    User login();
    bool changePassword(User& user);

};

#endif