#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "user.h"
using namespace std;

class FileManager{
    const string USER_FILE_NAME;

public:
    FileManager(string userFileName = "users.txt")
    :USER_FILE_NAME(userFileName){};

    vector<User> getUsersFromFile();
    void saveUserToFile(User user);
    void updateUserFile(vector<User> users);
};

#endif