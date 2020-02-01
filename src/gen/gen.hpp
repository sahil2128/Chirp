/*
Assembly generator, will generate assembly that can then be 
*/
#pragma once

#include <vector>
#include <string>

#include "../utils/node.hpp"

namespace gen
{
    std::string generate(std::vector<node>);
}