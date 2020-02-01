#include "settings.hpp"

bool is_verbose = false; // Default setting

namespace settings
{
    bool get_option(std::string n)
    {
        if(n == "-v")
        {
            return is_verbose;
        }
        else 
        {
            // Error
        }
    }

    void toggle_option(std::string n)
    {
        if(n == "-v")
        {
            if(is_verbose)
            {
                is_verbose = false;
            }
            else
            {
                is_verbose = true;
            }
        }
        else
        {
            // Error
        }
        
    }
}