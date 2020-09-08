//main.cpp

#include <iostream>
#include <string>
#include <sstream>

#include "HashMap.hpp"
#include "userCommands.hpp"
#include "debugCommands.hpp"
#include "handleIt.hpp"


int main()
{
    HashMap hm;
    userCommands uc;
    debugCommands dc;
    HandleIt handle;

    handle.handleInputs(hm, uc, dc);
    
    return 0;
}
    





























