/*
Author: Evan Huang
Course: CSCI-135
Instructor: Mike Zamansky
Assignment: Lab 11
    - Functions for A-C revolving the network class.
*/
#include <cctype>
#include <iostream>
#include <algorithm>
#include "profile.h"
#include "network.h"


Network::Network() {
    numUsers = 0;

    for (int row = 0; row < MAX_USERS; row++) {
        for (int col = 0; col < MAX_USERS; col++) {
            following[row][col] = false;
        }
    }
}


bool Network::addUser(std::string usrn, std::string dspn) {
    for (char ch : usrn)
        if (!isalnum(ch)) return false;

    if (numUsers > MAX_USERS - 1) {
        return false;
    }

    // Instead of findID since you should not have the same display names as well.
    for (Profile pf : profiles) {
        if (usrn == pf.getUsername() || dspn == pf.getDisplayName()) {
            return false;
        }
    }
    profiles[numUsers] = {usrn, dspn};
    numUsers++;
    return true;
}


int Network::findID(std::string usrn) {
    for (int i = 0; i < MAX_USERS; i++) {
        if (profiles[i].getUsername() == usrn) {
            return i;
        }
    }
    return -1;
}


bool Network::follow(std::string usrn1, std::string usrn2) {
    if (usrn1 == usrn2 || findID(usrn1) == -1 || findID(usrn2) == -1)
        return false;

    following[findID(usrn1)][findID(usrn2)] = true;
    return true;
}


void Network::printDot() {
    std::cout << "digraph {\n";
    for (Profile pf : profiles) {
        if (pf.getUsername() != "") {
            std::cout << " \"@" << pf.getDisplayName() << "\"\n";
        }
    }

    std::cout << "\n";
    for (int row = 0; row < MAX_USERS; row++) {
        for (int col = 0; col < MAX_USERS; col++) {
            if (following[row][col]) {
                std::cout << " \"@" << profiles[row].getDisplayName()
                << "\" -> \"@" << profiles[col].getDisplayName() << "\"\n";
            }
        }
    }
    std::cout << "}" << std::endl;
}

