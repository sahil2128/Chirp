#include "compound.hpp"

#include "stack.hpp"
#include "statement.hpp"

namespace gen
{
    std::string gen_compound(node n)
    {
        std::string res;
        stack_up();
        res += "{";

        for(node stmt : n.get_all())
        {
            res += gen_statement(stmt);
        }

        res += "}";
        stack_down();
        return res;
    }   
}