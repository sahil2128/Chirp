#pragma once

#include "../utils/node.hpp"

class argument
{
    public:
    std::string name;
    std::string dtype;
};

class function
{
    public:
    std::string name;
    std::string dtype;
    std::vector<argument> args;
};


namespace gen
{
    std::string gen_entry(node);
    std::string gen_function_call(node);
    std::string gen_function(node);
    
    void set_nspace(std::string);
    std::string get_nspace();
}