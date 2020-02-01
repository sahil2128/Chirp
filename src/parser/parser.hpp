#pragma once

#include "../utils/node.hpp"
#include <vector>

namespace parser
{
    // Put those there, so I don't have to declare one before the other
    node get_compound_stmt();
    node get_expr_stmt();
    node get_stmt();
    /*
    Runs the parser, and returns a vector of root
    tree nodes of every statements
    */
    std::vector<node> run();
}