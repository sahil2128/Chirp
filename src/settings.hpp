/*
Contains the settings for the compiler, like the source file and other stuff
*/
#pragma once

#include <string>

// To avoid variable duplication,
// this uses set_... and get_...
namespace settings
{
    bool get_option(std::string);
    void toggle_option(std::string);
}