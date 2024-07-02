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

public:
    UserManager();
    void rejestration();
    void login();
    void logout();
    User getUserData();
    void changePassword(User user);
    int getCurrUserId();
};

#endif