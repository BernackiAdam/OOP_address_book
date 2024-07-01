#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include "../Headers/user.h"
using namespace std;

class FileManager{
public:
    bool checkLogin(string login);
    int getFreeUserId();
    void saveUser(User user);
    User getUserData(string login);
};

#endif