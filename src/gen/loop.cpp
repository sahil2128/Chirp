#include "loop.hpp"
#include "condition.hpp"
#include "compound.hpp"

#include "../log.hpp"

namespace gen
{
    std::string gen_if(node n)
    {
        std::string res;

        res += "if";

        res += gen_condition(n.get("condition").get(0));
        res += gen_compound(n.get("compound"));

        return res;
    }

    std::string gen_else(node n)
    {
        std::string res;

        res += "else";

        if(n.get("condition").value != "undefined")
        {
            res += " if";
            res += gen_condition(n.get("condition").get(0));
        }
        else
        {
            log(debug,"No condition on else stmt");
        }

        res += gen_compound(n.get("compound"));

        return res;
    }

    std::string gen_while(node n)
    {
        std::string res;

        res += "while";
        
        res += gen_condition(n.get("condition").get(0));
        res += gen_compound(n.get("compound"));


        return res;
    }
}