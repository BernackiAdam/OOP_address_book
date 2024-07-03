#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "../Headers/user.h"
using namespace std;

class FileManager{
    const string USERFILENAME;

public:
    FileManager(string userFileName = "users.txt")
    :USERFILENAME(userFileName){};

    vector<User> getUsersFromFile();
    void saveUserToFile(User user);
    void updateUserFile(vector<User> users);
};

#endif