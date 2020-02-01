#include "gen.hpp"

#include "../log.hpp"
#include "../handler.hpp"
#include "../utils/io.hpp"
#include "../parser/env.hpp"

#include "function.hpp"
#include "variable.hpp"

#include <iostream>

namespace gen
{
    std::string generate(std::vector<node> toplevel)
    {
        std::string result;

        for(node n : toplevel)
        {
            if(n.value == "entry")
            {
                // This one is special
                log(debug,"Generating entry");

                result += gen_entry(n);
            }
            else if(n.value == "declaration")
            {
                log(debug,"Generating top-level declaration");

                result += gen_var_dec(n);
            }
            else if(n.value == "function")
            {
                log(debug,"Generating function");

                result += gen_function(n);
            }
            else if(n.value == "import")
            {
                std::string filename = n.get(0).value;
                
                filename.erase(0, 1);
                filename.pop_back();

                std::cout<<"Filename is "<<filename<<std::endl;
                result += generate(parser::parse(utils::read_lines(filename)));
            }
            else
            {
                // Error
                handler::acc_error("Unrecognized top-level statement");
            }
            
        }

        //std::cout<<result<<std::endl;
        return result;
    }
}