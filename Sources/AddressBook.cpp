#include "../Headers/AddressBook.h"

void AddressBook::rejestration(){
    userManager.rejestration();
}

void AddressBook::login(){
    userManager.login();
}

User AddressBook::getLogUser(){
    return userManager.getUserData();
}
int AddressBook::loginPage(){
    cout << "Hello" << endl;
    cout << "1. Register" << endl;
    cout << "2. Login" << endl;
    cout << "3. exit" << endl;
    int choice;
    cin >> choice;
    switch(choice){
        case 1: rejestration(); break;
        case 2: login(); 
            currUser = getLogUser();
            break;
        case 3: exit(0);
        default: break;
    }
    
    return currUser.getId();
}

void AddressBook::userPage(User currUser){
    int choice;
    cout << "Your address book." << endl;
    cout << "1. Search your friend" << endl;
    cout << "2. Show all friends" << endl;
    cout << "3. Add a friend" << endl;
    cout << "4. Delete a friend" << endl;
    cout << "5. Edit a friend" << endl;
    cout << "6. Change Password" << endl;
    cout << "7. Logout" << endl;
    cout << "9. Exit" << endl;
    cin >> choice;
    // switch (choice)
    // {
    // case 1:
    //     searchFriend(contacts);
    //     break;
    // case 2:
    //     showFriends(contacts);
    //     break;
    // case 3:
    //     addAdresate(contacts, currUserId, lastFreeId);
    //     break;
    // case 4:
    //     deleteAFriend(contacts, currUserId);
    //     break;
    // case 5:
    //     editFriend(contacts, currUserId);
    //     break;
    // case 6:
    //     changePasswd(currUser, currUserId);
    //     break;
    // case 7:
    //     contacts.clear();
    //     currUserId = 0;
    //     break;
    // case 9:
    //     exit(0);
    // };
}
