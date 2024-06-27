#include "../Headers/FileManager.h"

bool FileManager::checkLogin(string login){
    userFile.open("users.txt", ios::in | ios::app);
    string line, item;
    int lineNr = 1;
    bool taken=false;
    while(getline(userFile,line) && line!=""){
        stringstream ss(line);
        while(getline(ss, item, '|')){
            switch(lineNr){
                case 1: break;
                case 2: if(item==login) return taken=true; break;
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
    userFile.open("users.txt", ios::in);
    string line;
    string lastUserId = "0";
    while(getline(userFile, line) && line!=""){
        lastUserId=line[2];
    }
    userFile.close();
    return stoi(lastUserId);
}

void FileManager::saveUser(User user){
    userFile.open("users.txt", ios::app);
    userFile << user.getId() << "|" ;
    userFile << user.getLogin() << "|" ;
    userFile << user.getPassword() << "|" ;
    userFile.close();
}