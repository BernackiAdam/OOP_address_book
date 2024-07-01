#include <iostream>
#include "../Headers/AddressBook.h"



using namespace std;

int main(){
    AddressBook addressBook;
    User user;
    int logUserId = 0;
    while(1){
        if(logUserId==0){
            logUserId = addressBook.loginPage();
            user = addressBook.getLogUser();
        }
        else{
            addressBook.userPage(user);
        }
    }
}