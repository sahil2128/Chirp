/*
Makes file I/O easier, as if it wasn't already easy.
*/
#pragma once

#include <vector>
#include <string>

namespace utils
{
    void write(std::string,std::string);
    /*
    Read the specified file and returns a vector with each files
    */
    std::vector<std::string> read_lines(std::string);
}