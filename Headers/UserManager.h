#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include "../Headers/user.h"
#include "../Headers/FileManager.h"
using namespace std;

class UserManager{
    FileManager fileManager;
    int logedUserId;
public:
    void rejestration();
    void login();
    void logout();
    User getUserData();
};

#endif