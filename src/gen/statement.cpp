#include "statement.hpp"
#include "variable.hpp" 
#include "function.hpp"
#include "values.hpp"

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
        else if(n.value == "assign")
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
        else
        {
            log(error,"Unrecognized statement type");
        }

        return res;
    }
}