#pragma once

#include <string>

#include "../utils/node.hpp"

class variable
{
    public:
    variable();
    std::string name;
    std::string type;
    bool defined;
    int height;
};

namespace gen
{
    std::string gen_var_dec(node);
    std::string gen_assign(node);
}