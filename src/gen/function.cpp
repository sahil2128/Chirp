#include "function.hpp"
#include "compound.hpp"
#include "variable.hpp"
#include "values.hpp"
#include "types.hpp"

#include "../log.hpp"

namespace gen
{
    std::vector<function> funcs;
    std::string nspace;

    std::string gen_entry(node n)
    {
        std::string res;

        res += "int entry()";
        res += gen_compound(n.get("compound"));

        // TODO: Give error if
        // there's two entries

        return res;
    }

    // No overloading yet
    std::string gen_function_call(node n)
    {
        std::string res;
        std::string id;

        log(debug,"Generating function call");

        for(char c : n.get("identifier").get(0).value)
        {
            if(c == '.')
            {
                id += "_";
            }
            else
            {
                id += c; 
            }
        }

        res += id;

        bool hasArgs = false;

        res += "(";

        for(node arg : n.get("args").get_all())
        {
            if(arg.value != "")
            {
                log(debug,arg.value);
                res += gen_expr(arg);
                res += ",";
            }
            hasArgs = true;
        }

        if(hasArgs)
        {
            res.pop_back();
        }

        res += ");";

        return res;
    }

    std::string gen_function(node n)
    {
        std::string res;

        res += gen_dtype(n.get("data_type"));
        res += " ";
        if(!nspace.empty())
        {
            res += nspace + "_";
        }
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

        if(n.get("compound").value != "undefined")
        {
            res += gen_compound(n.get("compound"));
        }
        else
        {
            res += ";";
        }

        return res;
    }

    void set_nspace(std::string txt)
    {
        nspace = txt;
    }

    std::string get_nspace()
    {
        return nspace;
    }
}