#include <iostream>
#include "../Headers/AddressBook.h"



using namespace std;

int main(){
    AddressBook addressBook;
    User currUser;
    while(1){
        if(currUser.getId()==0){
            currUser = addressBook.loginPage();
        }
        else{
            addressBook.userPage(currUser);
        }
    }

}