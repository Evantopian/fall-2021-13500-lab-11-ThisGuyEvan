#include <iostream>
#include "profile.h"


std::string Profile::getUsername(){

  return username;
}


std::string Profile::getFullName(){
  return displayname + " (@" + username + ")";
}

std::string Profile::getDisplayName(){
  return displayname;
}

void Profile::setDisplayName(std::string dspn){
  displayname = dspn;
}


Profile::Profile(std::string usrn, std::string dspn){
  username = usrn;
  displayname = dspn;
}

Profile::Profile(){
  username = "";
  displayname = "";
}
