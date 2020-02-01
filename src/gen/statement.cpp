#include "statement.hpp"
#include "variable.hpp" 
#include "function.hpp"
#include "values.hpp"
#include "loop.hpp"

#include "log.hpp"

namespace gen
{
    std::string gen_ret(node n)
    {
        std::string res;

        res += "return ";
        res += gen_expr(n.get("expression").get(0));
        res += ";\n";

        return res;
    }

    std::string gen_statement(node n)
    {
        std::string res;

        if(n.value == "declaration")
        {
            res = gen_var_dec(n);
        }
        else if(n.value == "if")
        {
            res = gen_if(n);
        }
        else if(n.value == "else")
        {
            res = gen_else(n);
        }
        else if(n.value == "assignment")
        {
            res = gen_assign(n);
        }
        else if(n.value == "call")
        {
            res = gen_function_call(n);
        }
        else if(n.value == "return")
        {
            res = gen_ret(n);
        }
        else if(n.value == "while")
        {
            res = gen_while(n);
        }
        else
        {
            log(error,"Unrecognized statement type");
        }

        return res;
    }
}