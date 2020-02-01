/*
Error handler, handles erorrs
*/
#pragma once

#include <string>

namespace handler
{
    class err
    {
        public:
        std::string msg;
        int col;
        int row;
    };

    /*
    Dumps the current line
    */
    void dump();

    /*
    Add an error to the accumulated errors
    */
    void acc_error(std::string);

    /*
    Will exits for all the accumulated errors.
    If there's no errors then it will return false
    */
    bool run_errors();
}