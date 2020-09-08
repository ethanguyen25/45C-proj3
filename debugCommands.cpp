//debugCommands.cpp

#include <iostream>
#include <string>

#include "debugCommands.hpp"

void debugCommands::debugState(std::string& debugStatus, 
    const std::string& line)
{
    if ((debugStatus == "OFF") and (line == "ON"))
    {
        debugStatus = "ON";
        std::cout << "ON NOW" << std::endl;
    }
    else if ((debugStatus == "ON") and (line == "ON"))
    {
        std::cout << "ON ALREADY" << std::endl;
    }
    else if ((debugStatus == "ON") and (line == "OFF"))
    {
        debugStatus = "OFF";
        std::cout << "OFF NOW" << std::endl;
    }
    else if ((debugStatus == "OFF") and (line == "OFF"))
    {
        std::cout << "OFF ALREADY" << std::endl;
    }
    else
    {
        std::cout << "INVALID" << std::endl;
    }
}

void debugCommands::loginCount(HashMap& hm, const std::string& debugStatus) 
{
    if (debugStatus == "ON")
    {
        std::cout << hm.size() << std::endl;
    }
    else
    {
        std::cout << "INVALID" << std::endl;
    }
}

void debugCommands::bucketC(HashMap& hm, const std::string& debugStatus,
                            const std::string& line)
{
    if (debugStatus == "ON" and line == "COUNT")
    {
        std::cout << hm.bucketCount() << std::endl;
    }
    else
    {
        std::cout << "INVALID" << std::endl;
    }
}

void debugCommands::loadF(HashMap& hm, const std::string& debugStatus,
                          const std::string& line)
{
    if (debugStatus == "ON" and line == "FACTOR")
    {
        std::cout << hm.loadFactor() << std::endl;
    }
    else
    {
        std::cout << "INVALID" << std::endl;
    }

}

void debugCommands::maxBS(HashMap& hm, const std::string& debugStatus,
                          const std::string& line)
{
    if (debugStatus == "ON" and line == "BUCKET SIZE")
    {
        std::cout << hm.maxBucketSize() << std::endl;
    }
    else
    {
        std::cout << "INVALID" << std::endl;
    }

}






















