#include <iostream>
#include "../Headers/AddressBook.h"



using namespace std;

int main(){
    AddressBook addressBook;
    User logedUser;
    while(1){
        if(logedUser.getId()==0){
            logedUser = addressBook.loginPage();
        }
        else{
            addressBook.userPage(logedUser);
        }
    }
}