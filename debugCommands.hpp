//debugCommands.hpp

#ifndef DEBUGCOMMANDS_HPP
#define DEBUGCOMMANDS_HPP

#include "HashMap.hpp"
#include <string>


class debugCommands
{
public:
    void debugState(std::string& debugStatus, const std::string& line);

    void loginCount(HashMap& hm, const std::string& debugStatus); 

    void bucketC(HashMap& hm, const std::string& debugStatus,
                 const std::string& line); 

    void loadF(HashMap& hm, const std::string& debugStatus, 
                 const std::string& line); 

    void maxBS(HashMap& hm, const std::string& debugStatus, 
                 const std::string& line); 

private:
    
    HashMap hm;

    const std::string line;

    const std::string debugStatus;


};

#endif
