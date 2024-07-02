#include "../Headers/UserManager.h"

UserManager::UserManager(){
    this->users = fileManager.getUsers();
}



void UserManager::rejestration(){
    string login, password;
    int lastFreeId;
    User newUser;
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
            newUser.setId(lastFreeId+1);
            newUser.setLogin(login);
            newUser.setPassword(password);
            fileManager.saveUser(newUser);
            cout << endl;
            cout << "Account has been created." << endl;
            cout << endl;
            return;
        }  
    }
}

void UserManager::login(){
    string login;
    cout << "Type 0 to exit" << endl;
    while(1){
        cout << "Enter your login: ";
        cin >> login;
        bool loginExist = fileManager.checkLogin(login);
        if(!loginExist){
            cout << "Wrong login" << endl;
        }
        else{
            User currUser = fileManager.getUserData(login);
            string password;
            int incorrectPasswd = 0;
            while(incorrectPasswd < 3){
                cout << "Enter password: ";
                cin >> password;
                if(currUser.getPassword() == password){
                    this->user = currUser;
                    cout << "Welcome!" << endl;
                    return;
                }
                else{
                    cout << "Incorrect password" << endl;
                    if(incorrectPasswd == 2){
                        cout << "You reached limit of trys" << endl;
                        return;
                    }
                    cout << "You have " << 2-incorrectPasswd 
                        << " attepts left." << endl;
                        cout << endl;
                    incorrectPasswd++;
                    continue;
                }
            }
        }

    }
}
