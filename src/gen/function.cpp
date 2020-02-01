#include "function.hpp"
#include "compound.hpp"
#include "variable.hpp"

namespace gen
{
    std::vector<function> funcs;

    std::string gen_entry(node n)
    {
        std::string res;

        res += "int main()";
        res += gen_compound(n.get("compound"));

        // TODO: Give error if
        // there's two entries

        return res;
    }

    std::string gen_function_call(node n)
    {
        std::string res;

        return res;
    }

    std::string gen_function_decl(node n)
    {
        std::string res;

        return res;
    }

    std::string gen_function(node n)
    {
        std::string res;

        res += n.get("data_type").get(0).value;
        res += " ";
        res += n.get("identifier").get(0).value;
        res += "(";
        
        bool hasParams = false;

        for(node param : n.get("params").get_all())
        {
            if(param.value != "")
            {
                res += gen_var_dec(param);
                res.pop_back();
                res.pop_back();
                res += ",";
            }
            hasParams = true;
        }

        if(hasParams)
        {
            res.pop_back();
        }
        
        res += ")";

        res += gen_compound(n.get("compound"));

        return res;
    }
}