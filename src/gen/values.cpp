#include "values.hpp"
#include "variable.hpp"

#include "../log.hpp"

#include <iostream>

namespace gen
{
    std::string gen_op(node n)
    {
        std::string res;

        if(n.value != "undefined")
        {
            res += n.get(0).value;
        }
        else if(n.value != "undefined")
        {
            res += n.get(0).value;
        }
        else
        {
            // Might have to be an error
            res = "undefined";
            log(warning,"Unable to generate operand");
        }
        

        return res;
    }

    bool is_math_op(std::string txt)
    {
        if(txt == "add" || txt == "sub" ||
        txt == "multi" || txt == "div")
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    std::string gen_math_op(std::string txt)
    {
        std::string res;

        if(txt == "add")
        {
            res = "+";
        }
        else if(txt == "sub")
        {
            res = "-";
        }
        else if(txt == "multi")
        {
            res = "*";
        }
        else if(txt == "div")
        {
            res = "/";
        }

        return res;
    }

    std::string gen_expr(node n)
    {
        std::string res;

        if(is_math_op(n.value))
        {
            res += gen_op(n.get(0));
            res += gen_math_op(n.value);
            res += gen_expr(n.get(1));
        }
        else
        {
            res = gen_op(n/*.get(0)*/);
        }

        return res;
    }
}