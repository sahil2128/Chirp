#pragma once

#include "variable.hpp"

namespace gen
{
    void push_var(variable);
    variable& get_var(std::string);

    void stack_up();
    void stack_down();
}