#include <iostream>
#include <algorithm>
#include "profile.h"
#include "network.h"


bool isAlphaNum(std::string s){
    for (char ch : s){
        if (!isalpha(ch) || !isdigit(ch) && ch == ' '){
            return true;
        }
    }
    return false;
}


bool Network::addUser(std::string usrn, std::string dspn){
    if (numUsers > MAX_USERS || isAlphaNum(usrn) || isAlphaNum(dspn)){
        return false;
    }

    for (Profile pf : profiles){
        if (usrn == pf.getUsername() || dspn == pf.getDisplayName()){
            return false;
        }
    }
    profiles[numUsers] = {usrn, dspn};
    numUsers++;
    return true;
}


int Network::findID(std::string usrn){
    int count = 0;
    for (Profile pf : profiles){
        if (pf.getUsername() == usrn){
            return count;
        }
        count++;
    }
    return -1;
}

bool Network::follow(std::string usrn1, std::string usrn2){
    for (Profile pf : profiles){
        if (pf.getUsername() == usrn1){

        }
    } 

}


Network::Network(){
    numUsers = 0;

    for (int row = 0; row < MAX_USERS; row++){
        for (int col = 0; col < MAX_USERS; col++){
           following[row][col] = false; 
        }
    }
}
