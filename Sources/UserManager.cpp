#include "../Headers/UserManager.h"

UserManager::UserManager(){
    this->users = fileManager.getUsersFromFile();
}

User UserManager::getUserData(){
    return this->logedUser;
}
User UserManager::logout(){
    User user;
    this->logedUser = user;
    return logedUser;
}

User UserManager::checkUser(string login, int id){
    User checkedUser;
    for(auto user: users){
        if(user.getLogin() == login || user.getId() == id){
            checkedUser = user;
            return checkedUser;
        }
    }
    return checkedUser;
}

int UserManager::getFreeId(){
    int lastFreeId;
    if(users.empty()){return lastFreeId = 0;}
    else{return lastFreeId = users.back().getId();}
}

void UserManager::registration(){
    string login, password;
    int lastFreeId = getFreeId();

    while(true){
        cout << "Type 0 for exit" << endl;
        cout << "Enter login: ";
        cin >> login;
        if(login == "0") return;
        User newUser = checkUser(login);
        if(newUser.getLogin() != ""){
            cout << "This login is already taken." << endl;
            cout << endl;
            continue;
        }
        else{
            cout << "Enter password: ";
            cin >> password;
            newUser.setId(lastFreeId+1);
            newUser.setLogin(login);
            newUser.setPassword(password);
            users.push_back(newUser);
            fileManager.saveUserToFile(newUser);
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
    while(login!="0"){
        cout << "Enter your login: ";
        cin >> login;
        User checkedUser = checkUser(login);
        if(checkedUser.getId()==0){
            cout << "Wrong login" << endl;
        }
        else{
            if(checkPassword(checkedUser.getPassword())){
                cout << "Welcome!" << endl;
                this->logedUser = checkedUser;
            }
            return;
        }
    }
}

int UserManager::getUserIndex(User &currUser){
    int index=0;
    for(auto user : users){
        if(user.getId() == currUser.getId()){
            return index;
        }
        index++;
    }
    return 0;
}

User UserManager::changePassword(User &currUser){
    string oldPassword, newPassword;
    string line;
    int trys = 0;
    int userIndex = getUserIndex(currUser);
    cout << "Please, enter your old password" << endl;
    
    if(!checkPassword(users[userIndex].getPassword())){
        logout();
        return this->logedUser;
    }
    cout << "Enter new password: ";
    cin >> newPassword;
    users[userIndex].setPassword(newPassword);
    currUser.setPassword(newPassword);
    fileManager.updateUserFile(users);
    cout << "Password has been changed" << endl;
    cout << endl;
    return logedUser;
}

bool UserManager::checkPassword(string checkedPassword){
    string password;
    int incorrectPasswd = 0;
    bool passwordCorrect = true;
    bool passwordIncorrect = false;
    // cout << "Type 0 to exit" << endl;
    while(incorrectPasswd < 3){
        cout << "Enter password: ";
        cin >> password;
        if(password=="0") return false;
        if(checkedPassword == password){
            return passwordCorrect;
        }
        else{
            cout << "Incorrect password" << endl;
            if(incorrectPasswd == 2){
                cout << "You reached limit of trys" << endl;
                return passwordIncorrect;
            }
            cout << "You have " << 2-incorrectPasswd 
                << " attepts left." << endl;
                cout << endl;
            incorrectPasswd++;
        }
    }
    return passwordIncorrect;
}