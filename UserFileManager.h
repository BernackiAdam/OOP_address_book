#ifndef USERFILEMANAGER_H
#define USERFILEMANAGER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "user.h"
#include "BaseFileManager.h"
using namespace std;

class UserFileManager : public BaseFileManager{
    const string USER_FILE_NAME;

public:
    UserFileManager(string userFileName = "users.txt")
    :USER_FILE_NAME(userFileName){};

    vector<User> getUsersFromFile();
    void saveUserToFile(User user);
    void updateUserFile(vector<User> users);
};

#endif