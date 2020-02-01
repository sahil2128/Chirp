#include "loop.hpp"
#include "condition.hpp"
#include "compound.hpp"

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

    std::string gen_while(node n)
    {
        std::string res;

        res += "while";
        
        res += gen_condition(n.get("condition").get(0));
        res += gen_compound(n.get("compound"));


        return res;
    }
}