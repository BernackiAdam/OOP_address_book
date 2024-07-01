#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include "../Headers/user.h"
#include "../Headers/FileManager.h"
using namespace std;

class UserManager{
    FileManager fileManager;
    User user;
    int logedUserId;
public:
    UserManager(int logedUserId=0){
        this->logedUserId = logedUserId;
    }
    void rejestration();
    void login();
    void logout();
    User getUserData();
    void changePassword();
    int getCurrUserId();
};

#endif