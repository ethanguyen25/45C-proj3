//handleIt.cpp

#include "handleIt.hpp"
#include "HashMap.hpp"
#include "userCommands.hpp"
#include "debugCommands.hpp"

#include <iostream>
#include <string>
#include <sstream>


void HandleIt::handleInputs(HashMap& hm, userCommands& uc, 
                            debugCommands& dc)
{

    debugStatus = "OFF";

    bool flag = true;
    while (flag)
    {
        //first input = command
        //std::cin >> command;
        //std::cin.ignore(1);
        
        std::getline(std::cin, wholeLine);
        std::stringstream ss1(wholeLine);
        ss1 >> command;
        
        if (command == "QUIT")
        {
            std::cout << "GOODBYE" << std::endl;
            flag = false;
            break;
        }
        else if (command == "CLEAR")
        {
            hm.clear();
            std::cout << "CLEARED" << std::endl;
        }
        else if (command == "CREATE" or command == "LOGIN")
        {
             
            //std::getline(std::cin, line);
            if (command == "CREATE")
            {
                //std::stringstream ss1(line);
                ss1 >> username >> password;
                //std::cout << username << " " << password << std::endl;
                if (username != "" and password != "")
                {
                    uc.create(hm, username, password);
                    username = "";
                    password = "";
                }
                else
                {
                    std::cout << "INVALID" << std::endl;
                }
            }
            else
            {
                ss1 >> username >> password;
                if (username == "COUNT" and password == "")
                {
                    dc.loginCount(hm, debugStatus);
                    username = "";
                }
                else if (username != "" and password != "")
                {
                    uc.login(hm, username, password);
                    username = "";
                    password = "";
                }
                else
                {
                    std::cout << "INVALID" << std::endl;
                }
                
            }
        }
        else if (command == "REMOVE")
        {
            ss1 >> line;
            uc.removed(hm, line);
            line = "";
        }
        else if (command == "DEBUG")
        {
            ss1 >> line;
            dc.debugState(debugStatus, line);
            line = "";
        }
        else if (command == "BUCKET")
        {
            ss1 >> line;
            if (line != "")
            {
                dc.bucketC(hm, debugStatus, line);
                line = "";
            }
            else
            {
                std::cout << "INVALID" << std::endl;
            }
        }
        else if (command == "LOAD")
        {
            ss1 >> line;
            dc.loadF(hm, debugStatus, line);
            line = "";
        }
        else if (command == "MAX")
        {
            ss1 >> username >> password;
            line = username + " " + password;
            //std::cout << line << std::endl;
            dc.maxBS(hm, debugStatus, line);
            username = "";
            password = "";
        }
        else
        {
            std::cout << "INVALID" << std::endl;
        }
    }




}
