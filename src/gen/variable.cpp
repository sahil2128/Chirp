#include "variable.hpp"
#include "values.hpp"
#include "types.hpp"

#include <iostream>

variable::variable()
{
    defined = false;
    height = 0;
}

namespace gen
{
    std::string gen_var_dec(node n)
    {
        std::string res;

        //res += n.get("data_type").get(0).value;
        res += gen_dtype(n.get("data_type"));
        res += " ";
        res += n.get("identifier").get(0).value;
        res += ";\n";

        if(n.get("assignment").value != "undefined")
        {
            res += gen_assign(n.get("assignment"));
        }
        else
        {
        }
        
        return res;
    }

    std::string gen_assign(node n)
    {
        std::string res;

        res += n.get("identifier").get(0).value;
        res += " = ";
        res += gen_expr(n.get("expression").get(0));
        res += ";\n";

        return res;
    }
}