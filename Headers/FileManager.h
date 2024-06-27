#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include "../Headers/user.h"
using namespace std;

class FileManager{
    fstream userFile;
    fstream ContactFile;
public:
    bool checkLogin(string login);
    int getFreeUserId();
    void saveUser(User user);
};

#endif