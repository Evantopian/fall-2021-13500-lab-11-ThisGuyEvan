#include <iostream>
#include <algorithm>
#include "profile.h"
#include "network.h"


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


bool isAlphaNum(std::string s){
    for (char ch : s){
        if (!isalpha(ch) || isdigit(ch) || ch == ' '){
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


Network::Network(){
    numUsers = 0;
}
