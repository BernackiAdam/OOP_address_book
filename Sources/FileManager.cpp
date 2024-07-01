#include "../Headers/FileManager.h"

bool FileManager::checkLogin(string login){
    fstream userFile;
    userFile.open("users.txt", ios::in | ios::app);
    string line, item;
    int lineNr = 1;
    bool taken=false;
    while(getline(userFile,line) && line!=""){
        stringstream ss(line);
        while(getline(ss, item, '|')){
            switch(lineNr){
                case 1: break;
                case 2: 
                        if(item==login){
                            userFile.close();
                            return taken = true;
                        } 
                        break;
                    
                case 3: 
                    lineNr=0;
                    break;
            }
            lineNr++;
            }
        }
    userFile.close();
    return taken;
}
int FileManager::getFreeUserId(){
    fstream userFile;
    userFile.open("users.txt", ios::in);
    string line;
    string lastUserId = "0";
    while(getline(userFile, line) && line!=""){
        lastUserId=line[0];
    }
    userFile.close();
    int freeId = stoi(lastUserId);
    return freeId;
}

void FileManager::saveUser(User user){
    fstream userFile;
    userFile.open("users.txt", ios::app);
    userFile << user.getId() << "|" ;
    userFile << user.getLogin() << "|" ;
    userFile << user.getPassword() << "|" << endl;
    userFile.close();
}

User FileManager::getUserData(string login){
    fstream userFile;
    userFile.open("users.txt", ios::in);
    User user;
    int userId;
    string currLogin, password;
    string line, item;
    int lineNr = 1;
    while(getline(userFile, line)){
        stringstream ss(line);
        while(getline(ss, item, '|')){
            switch(lineNr){
                case 1: userId = stoi(item); break;
                case 2: currLogin = item; break;
                case 3: password = item;
                    if(currLogin == login){
                        user.setId(userId);
                        user.setLogin(currLogin);
                        user.setPassword(password);
                        return user;
                    }
                    lineNr = 0;
                    break;

            }
            lineNr++;
        }
    }
    return user;
}
