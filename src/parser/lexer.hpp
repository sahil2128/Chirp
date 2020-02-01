#pragma once

#include <vector>
#include <string>

#include "token.hpp"

namespace parser
{
    std::vector<token> lexe(std::vector<std::string>);
}