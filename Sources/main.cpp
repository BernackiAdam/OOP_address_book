#include <iostream>
#include "../Headers/AddressBook.h"



using namespace std;

int main(){
    AddressBook addressBook;
    while(1){
        cout << "Hello" << endl;
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. exit" << endl;
        int choice;
        cin >> choice;
        switch(choice){
            case 1: addressBook.rejestration(); break;
            case 2: addressBook.login(); break;
            case 3: exit(3);
            default: break;
        }
    }
}