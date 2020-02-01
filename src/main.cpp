#include "utils/io.hpp"
#include "utils/node.hpp"
#include "parser/env.hpp"
#include "gen/gen.hpp"

#include "cmd.hpp"
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
        std::string target = std::string(argv[1]);
        std::vector<std::string> fvalue = utils::read_lines(target); // File value
        gen::generate(parser::parse(fvalue));
    }

    return 0;
}