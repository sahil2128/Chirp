#include "utils/io.hpp"
#include "utils/node.hpp"
#include "parser/env.hpp"
#include "gen/gen.hpp"

#include "settings.hpp"
#include "build.hpp"
#include "log.hpp"

#include <iostream>

int main(int argc,char* argv[])
{
    if(argc < 2)
    {
        log(error,"No filename has been specified.");
        return 1;
    }
    else
    {
        for(int i = 1; i < argc; i++)
        {
            std::string arg = argv[i];
            
            if(arg.at(0) == '-')
            {
                settings::toggle_option(arg);
            }
        }

        std::string target = std::string(argv[1]);
        std::vector<std::string> fvalue = utils::read_lines(target); // File value
        build::build_file(gen::generate(parser::parse(fvalue)),target);
    }
    return 0;
}