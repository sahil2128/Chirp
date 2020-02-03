/*
Error handler, handles erorrs
*/
#pragma once

#include <string>

namespace handler
{
    /*
    Handler
    */
    void error_at_line(std::string,int);
    
    /*
    Dumps error at specified token
    */
    void error_at_token(std::string,int);
}