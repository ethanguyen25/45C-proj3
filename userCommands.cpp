//userCommands.cpp

#include <iostream>
#include <string>
#include <sstream>

#include "userCommands.hpp"
#include "HashMap.hpp"

void userCommands::create(HashMap& hm, const std::string& username, 
              const std::string& password)
{
  //std::cout << username << " " << password << std::endl;  

    if (hm.contains(username) and username != "")
    {
        std::cout << "EXISTS" << std::endl;
    }
    else
    {
        hm.add(username, password);
        std::cout << "CREATED" << std::endl;
    }
}

void userCommands::login(HashMap& hm, const std::string& username, 
              const std::string& password)
{
    if ((hm.contains(username)) and 
        (hm.value(username) == password))
    {
        std::cout << "SUCCEEDED" << std::endl;
    }
    else
    {
        std::cout << "FAILED" << std::endl;
    }
}

void userCommands::removed(HashMap& hm, const std::string& username)
{
    if (username == "")
    {
        std::cout << "INVALID" << std::endl;
    }
    else if (hm.contains(username) == false)
    {
        std::cout << "NONEXISTENT" << std::endl;
    }
    else
    {
        hm.remove(username);
        std::cout << "REMOVED" << std::endl;
    }
    
}
/*
void clearing(HashMap& hm)
{
    hm.clear();
}
*/



