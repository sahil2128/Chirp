#include "types.hpp"

namespace gen
{
    std::string gen_dtype(node n)
    {
        std::string res;
        int regular = 0;
        int ptrs = 0;

        for(node t : n.get_all())
        {
            if(t.value == "none")
            {
                res += "void";
                regular++;
            }
            else if(t.value == "pointer")
            {
                ptrs++;
            }
            else
            {
                res += t.value;
                regular++;
            }
            res += " ";
        }

        if(regular == 0)
        {
            res += "void";
        }

        for(int i = 0; i < ptrs; i++)
        {
            res += "*";
        }

        return res;
    }
}