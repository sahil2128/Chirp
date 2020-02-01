#include "log.hpp"

#include "utils/color.hpp"
#include "settings.hpp"

#include <iostream>

void log(log_level level, std::string txt)
{
    std::string prefix;
    utils::color c;

    if(level == debug)
    {
        if(settings::get_option("-v"))
        {
            prefix = "debug";
            c = utils::blue;
            std::cout<<make_color(c,prefix)<<":"<<txt<<std::endl;
        }
    }
    else if(level == error)
    {
        prefix = "error";
        c = utils::red;
        std::cout<<make_color(c,prefix)<<":"<<txt<<std::endl;
    }
    else if(level == warning)
    {
        prefix = "warning";
        c = utils::yellow;
        std::cout<<make_color(c,prefix)<<":"<<txt<<std::endl;
    }

    //std::cout<<make_color(c,prefix)<<":"<<txt<<std::endl;
}