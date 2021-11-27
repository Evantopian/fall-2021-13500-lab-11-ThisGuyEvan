#include <iostream>
#include "profile.h"


std::string Profile::getUsername(){

  return Profile::username;
}


std::string Profile::getFullName(){
  return Profile::displayname + " (@" + Profile::username + ")";
}

void Profile::setDisplayName(std::string dispn){
  Profile::displayname = dispn;
}


Profile::Profile(std::string usrn, std::string dispn){
  Profile::username = usrn;
  Profile::displayname = dispn;
}
