#pragma once

#include "condition.hpp"
#include "compound.hpp"

#include "../utils/node.hpp"

namespace gen
{
    std::string gen_if(node);
    std::string gen_while(node);
}