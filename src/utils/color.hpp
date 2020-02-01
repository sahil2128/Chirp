/*
Color
*/
#pragma once

#include <string>

namespace utils
{
    enum color {
        blue,
        red,
        yellow
    };
    
    std::string make_color(color,std::string);
}