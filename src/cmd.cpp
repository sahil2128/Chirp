#include "cmd.hpp"

#include "settings.hpp"

#include <iostream>
#include <vector>
#include <string>

namespace command
{
    bool parse(int argc,char* argv[])
    {
        for(int i = 0; i < argc; i++)
        {
            //std::cout<<argv[i]<<std::endl;
        }

        return true;
    }
}