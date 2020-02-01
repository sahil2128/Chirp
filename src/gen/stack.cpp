#include "stack.hpp"

#include "../handler.hpp"

#include <vector>

namespace gen
{
    int height = 0;
    std::string name_space;
    std::vector<variable> vars;

    void push_var(variable v)
    {
        v.height = height;
        vars.push_back(v);
    }

    variable& get_var(std::string id)
    {
        for(variable& v:vars)
        {
            if(v.name == id)
            {
                return v;
            }
        }

        variable var;
        var.name = "undefined"; // oof
        handler::acc_error("Variable " + id + " isn't declared yet.");
        return var;
    }
    
    void stack_up()
    {
        height++;
    }

    void stack_down()
    {
        height--;

        // Very unefficient
        std::vector<variable> keeping;

        for(variable v:vars)
        {
            if(v.height <= height)
            {
                keeping.push_back(v);
            }
        }

        vars = keeping;
    }
}