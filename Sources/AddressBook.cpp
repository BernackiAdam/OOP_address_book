#include "../Headers/AddressBook.h"

AddressBook::AddressBook(){
    currUser = loginPage();
}

User AddressBook::getLogUser(){
    return userManager.getUserData();
}

void AddressBook::logout(){
    this->currUser = userManager.logout();
    
}

User AddressBook::loginPage(){
    cout << "Hello" << endl;
    cout << "1. Register" << endl;
    cout << "2. Login" << endl;
    cout << "3. exit" << endl;
    int choice;
    cin >> choice;
    switch(choice){
        case 1: userManager.registration(); break;
        case 2: userManager.login(); 
            currUser = getLogUser();
            userPage(currUser);
            break;
        case 3: exit(0);
        default: break;
    }
    return this->currUser;
}

void AddressBook::userPage(User &currUser){
    ContactManager contactManager(currUser.getId());
    while(currUser.getId()!=0){
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
        switch (choice)
        {
        // case 1:
        //     searchFriend(contacts);
        //     break;
        case 2:
            contactManager.showContacts();
            break;
        case 3:
            contactManager.addContact();
            break;
        // case 4:
        //     deleteAFriend(contacts, currUserId);
        //     break;
        // case 5:
        //     editFriend(contacts, currUserId);
        //     break;
        case 6:
            currUser = userManager.changePassword(currUser);
            break;
        case 7:
            // contacts.clear();
            logout();
            break;
        case 9:
            exit(0);
        };
    }
}
