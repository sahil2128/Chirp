#include "log.hpp"

#include "utils/color.hpp"

#include <iostream>

void log(log_level level, std::string txt)
{
    std::string prefix;
    utils::color c;

    if(level == debug)
    {
        prefix = "debug";
        c = utils::blue;
    }
    else if(level == error)
    {
        prefix = "error";
        c = utils::red;
    }
    else if(level == warning)
    {
        prefix = "warning";
        c = utils::yellow;
    }

    std::cout<<make_color(c,prefix)<<":"<<txt<<std::endl;
}