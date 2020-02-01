#include "utils.hpp"

namespace utils
{
    bool is_number(std::string txt)
    {
        for(char c : txt)
        {
            if(!isdigit(c))
            {
                return false;   
            }
        }
        return true;
    }
}