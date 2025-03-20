#include <iostream>
#include "AddressBook.h"
using namespace std;

int main(){
    AddressBook addressBook;
    int choice;
    while(1){
        if(!addressBook.isUserLoggedIn()){
            cout << "Hello" << endl;
            cout << "1. Register" << endl;
            cout << "2. Login" << endl;
            cout << "3. exit" << endl;
            cin >> choice;
            switch(choice){
                case 1: addressBook.registration(); break;
                case 2: addressBook.login(); 
                    break;
                case 3: exit(0);
                default: break;
            }
        }
        else{
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
                addressBook.showContacts();
                break;
            case 3:
                addressBook.addContact();
                break;
            // case 4:
            //     deleteAFriend(contacts, currUserId);
            //     break;
            // case 5:
            //     editFriend(contacts, currUserId);
            //     break;
            case 6:
                addressBook.changePassword();
                break;
            case 7:
                // User user;
                // this->currUser = user;
                addressBook.setCurrentUser(User());
                break;
            case 9:
                exit(0);
            default:
                continue;
            };
        }
    }
}