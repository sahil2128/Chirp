#include "color.hpp"

#include <iostream>

namespace utils
{
    /*
    Currently only implemented on linux, but I'll make it
    work on windows.
    */
    std::string make_color(color c,std::string txt)
    {
        std::string res = "\e[";
        
        switch(c)
        {
            case blue:
            res += "34";
            break;
            
            case red:
            res += "31";
            break;
            
            case yellow:
            res += "33";
            break;

            default:
            res += "39";
            break;
        }

        res += "m ";
        res += txt;
        res += "\e[0m";

        return res;
    }
}