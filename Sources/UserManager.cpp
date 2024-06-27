#include "../Headers/UserManager.h"

void UserManager::rejestration(){
    string login, password;
    int lastFreeId;
    while(true){
        cout << "Type 0 for exit" << endl;
        cout << "Enter login: ";
        cin >> login;
        if(login == "0") return;
        bool taken = fileManager.checkLogin(login);
        if(taken){
            cout << "This login is already taken." << endl;
            cout << endl;
            continue;
        }
        else{
            cout << "Enter password: ";
            cin >> password;
            lastFreeId = fileManager.getFreeUserId();
            user.setId(lastFreeId+1);
            user.setLogin(login);
            user.setPassword(password);
            fileManager.saveUser(user);
            cout << endl;
            cout << "Account has been created." << endl;
            cout << endl;
            return;
        }
        
        
    }
}