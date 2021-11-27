/*
Author: Evan Huang
Course: CSCI-135
Instructor: Mike Zamansky
Assignment: Lab 11
    - Functions for A-C revolving the network class.
*/
#include <iostream>
#include <algorithm>
#include "profile.h"
#include "network.h"


bool isAlphaNum(std::string s)
{
    for (char ch : s)
    {
        if (!isalnum(ch))
        {
            return true;
        }
    }
    return false;
}


bool Network::addUser(std::string usrn, std::string dspn)
{
    if (numUsers > MAX_USERS - 1 || isAlphaNum(usrn))
    {
        return false;
    }

    for (Profile pf : profiles)
    {
        if (usrn == pf.getUsername() || dspn == pf.getDisplayName())
        {
            return false;
        }
    }
    profiles[numUsers] = {usrn, dspn};
    numUsers++;
    return true;
}


int Network::findID(std::string usrn)
{
    int count = 0;
    for (Profile pf : profiles)
    {
        if (pf.getUsername() == usrn)
        {
            return count;
        }
        count++;
    }
    return -1;
}


bool Network::follow(std::string usrn1, std::string usrn2)
{
    int count = 0;
    for (Profile pf : profiles)
    {
        if (pf.getUsername() == usrn1 || pf.getUsername() == usrn2)
        {
            count++;
        }
    }
    if (count < 2)
    {
        return false;
    }
    following[findID(usrn1)][findID(usrn2)] = true;
    return true;
}


void Network::printDot()
{
    std::cout << "digraph {\n";
    for (Profile pf : profiles)
    {
        if (pf.getUsername() != "")
        {
            std::cout << " \"@" << pf.getDisplayName() << "\"\n";

        }
    }

    std::cout << "\n";
    for (int row = 0; row < MAX_USERS; row++)
    {
        for (int col = 0; col < MAX_USERS; col++)
        {
            if (following[row][col])
            {
                std::cout << " \"@" << profiles[row].getDisplayName()
                          << "\" -> \"@" << profiles[col].getDisplayName() << "\"\n";
            }
        }
    }
    std::cout << "}" << std::endl;
}


Network::Network()
{
    numUsers = 0;

    for (int row = 0; row < MAX_USERS; row++)
    {
        for (int col = 0; col < MAX_USERS; col++)
        {
            following[row][col] = false;
        }
    }
}
