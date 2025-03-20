#include "FileManager.h"

vector<User> FileManager::getUsersFromFile(){
    fstream userFile;
    vector<User> users;
    string line, item;
    int lineNr = 1;
    userFile.open(USER_FILE_NAME, ios::in);
    if(!userFile.good()){
        cout << "Error, cannot access user file" << endl;
        return users;
    }
    while(getline(userFile, line) && line!=""){
        stringstream ss(line);
        User currentUser;
        while(getline(ss, item, '|')){
            switch(lineNr){
                case 1: currentUser.setId(stoi(item)); break;
                case 2: currentUser.setLogin(item); break;
                case 3: currentUser.setPassword(item); 
                        users.push_back(currentUser);
                        lineNr=0;
                        break;
            }
            lineNr++;
        }
    }
    userFile.close();
    return users;
}

void FileManager::saveUserToFile(User user){
    fstream userFile;
    userFile.open(USER_FILE_NAME, ios::app);
    if(!userFile.good()){
        cout << "Error during saving user file" << endl;
        return;
    }
    userFile << user.getId() << "|";
    userFile << user.getLogin() << "|";
    userFile << user.getPassword() << endl;

    userFile.close();
}

void FileManager::updateUserFile(vector<User> users){
    fstream userFile;
    userFile.open(USER_FILE_NAME, ios::out);
    if(!userFile.good()){
        cout << "Cannot access user file" << endl;
        return;
    }
    for(auto user : users){
            userFile << user.getId() << "|";
            userFile << user.getLogin() << "|";
            userFile << user.getPassword() << "|" << endl;
        }
}
