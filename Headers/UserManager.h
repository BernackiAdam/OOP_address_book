#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include "../Headers/user.h"
#include "../Headers/FileManager.h"
using namespace std;

class UserManager{
    User user;
    FileManager fileManager;
public:
    void rejestration();
    void login();
    void logout();

};

#endif