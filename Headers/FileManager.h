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
    const string CONTACTFILENAME;

public:
    FileManager(string userFileName = "users.txt", string contactFileName = "contacts.txt")
    :USERFILENAME(userFileName), CONTACTFILENAME(contactFileName){};

    vector<User> getUsersFromFile();
    void saveUserToFile(User user);
    void updateUserFile(vector<User> users);
};

#endif