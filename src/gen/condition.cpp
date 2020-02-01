#include "condition.hpp"

#include "values.hpp"

namespace gen
{
    // Kinda useless but eh
    std::string gen_cond_op(std::string sym)
    {
        std::string res;

        if(sym == "equals")
        {
            res = "==";
        }
        else if(sym == "bigger")
        {
            res = "<";
        }
        else if(sym == "smaller")
        {
            res = "<";
        }
        else if("smaller_equals")
        {
            res = "<=";
        }
        else if("bigger_equals")
        {
            res = ">=";
        }

        return res;
    }

    std::string gen_condition(node n)
    {
        std::string res;
        res += "(";

        std::string op = gen_cond_op(n.value);

        res += gen_expr(n.get(0));
        res += " ";
        res += op;
        res += " ";
        res += gen_expr(n.get(1));

        res += ")";
        return res;
    }
}