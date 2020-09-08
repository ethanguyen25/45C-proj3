//userCommands.hpp


#ifndef USERCOMMANDS_HPP
#define USERCOMMANDS_HPP

#include "HashMap.hpp"
#include <string>


class userCommands
{

public:

    void create(HashMap& hm, const std::string& username,
              const std::string& password);

    void login(HashMap& hm, const std::string& username,
              const std::string& password);

    void removed(HashMap& hm, const std::string& username);

private:
    
    HashMap hm;

    const std::string username;
    
    const std::string password;
};




//void clearing(HashMap& hm);
#endif
