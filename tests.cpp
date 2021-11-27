/*
Author: Evan Huang
Course: CSCI-135
Instructor: Mike Zamansky
Assignment: Lab 11
    - Test Cases for tasks A-C.
*/
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define CHECK DOCTEST_CHECK
#include "doctest.h"
#include "profile.h"
#include "network.h"

TEST_CASE("Task A:"){
    Profile p1("marco", "Marco");
    CHECK(p1.getUsername() == "marco");
    CHECK(p1.getFullName() == "Marco (@marco)");

    p1.setDisplayName("Marco Rossi");
    CHECK(p1.getUsername() == "marco");
    CHECK(p1.getFullName() == "Marco Rossi (@marco)");

    Profile p2("tarma1", "Tarma Roving"); 
    CHECK(p2.getUsername() == "tarma1");
    CHECK(p2.getFullName() == "Tarma Roving (@tarma1)");

    Profile p3("ThisGuyEvan", "Evan Huang");
    CHECK(p3.getUsername() == "ThisGuyEvan");
    CHECK(p3.getFullName() == "Evan Huang (@ThisGuyEvan)");
}

TEST_CASE("Task B:"){
    Network nw;
    CHECK(nw.addUser("mario", "Mario") == true);
    CHECK(nw.addUser("luigi", "Luigi") == true);
    CHECK(nw.addUser("mario", "Mario2") == false);
    CHECK(nw.addUser("mario 2", "Mario2") == false);
    CHECK(nw.addUser("mario-2", "Mario2") == false);

    for(int i = 2; i < 20; i++){
        CHECK(nw.addUser("mario" + std::to_string(i), 
                         "mario" + std::to_string(i)) == true);
    }
 
    CHECK(nw.addUser("yoshi", "Yoshi") == false);
    
    Network nw2;
    CHECK(nw2.addUser("", "") == false);
    CHECK(nw2.addUser("james", "JaMeS") == true);
    CHECK(nw2.addUser("madison", "Madiisoon") == true);
    CHECK(nw2.addUser("jamesy_2", "madisa_2") == false);
    CHECK(nw2.addUser("8am<3", "8pm</3") == false);
}

TEST_CASE("Task C:"){
    Network nw1 = Network();
    nw1.addUser("mario", "Mario");
    nw1.addUser("luigi", "Luigi");
    nw1.addUser("yoshi", "Yoshi");
    nw1.addUser("wario", "Wario");
    CHECK(nw1.follow("mario", "luigi") == true);
    CHECK(nw1.follow("mario", "wario") == true);
    CHECK(nw1.follow("mario", "wario") == true);
    CHECK(nw1.follow("mario", "mario") == false);

    Network nw2 = Network();
    nw2.addUser("Evan", "Huang");
    nw2.addUser("Lab", "Eleven");
    nw2.addUser("November", "27th");
    nw2.addUser("bob", "ross");
    CHECK(nw2.follow("Evan", "Lab") == true);
    CHECK(nw2.follow("Evan", "November") == true);
    CHECK(nw2.follow("November", "bob") == true);
    CHECK(nw2.follow("bob", "ross") == false);
}
   
