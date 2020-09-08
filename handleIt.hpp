//handleIt.hpp

#ifndef HANDLEIT_HPP
#define HANDLEIT_HPP

#include "handleIt.hpp"
#include "HashMap.hpp"
#include "userCommands.hpp"
#include "debugCommands.hpp"

#include <iostream>
#include <string>
#include <sstream>



class HandleIt
{
public:
    
    void handleInputs(HashMap& hm, userCommands& uc, 
                  debugCommands& dc);
 
private:
    
    HashMap hm;

    userCommands uc;

    debugCommands dc;

    std::string debugStatus;

    std::string command;

    std::string line;
    
    std::string wholeLine;

    std::string username;

    std::string password;

    std::stringstream ss1;
};


#endif
                  
