/*
Tracks the location of the lexer,parser and code generator. Mostly usefull during
semantic analysis to throw errors.
*/
#pragma once

#include <string>
#include <vector>

namespace tracker
{
    class location
    {
        public:
        int start; // Starting position
        int stop; // Stopping position
        int line; // Line where the token is located
    };

    /*
    Gives token location to the tracker.
    --- Parameters ---

    int index, index of the token 
    in the token vector

    int start, starting position in the input line

    int stop, stoping position in the input line
    */
    location push_token(int,int);

    /*
    Returns the location of token, at given
    index in vector.
    */
    location get_token_location(int);

    /*
    Tells the tracker that's it at the next line
    */
    void next_line();

    /*
    Returns line as a string at specific row
    */
    std::string get_line(int);

    /*
    Returns the size(in lines) of source file
    */
    int get_line_count();

    /*
    Sets the source file as a
    vector of strings for each line
    */
    void set_source(std::vector<std::string>);
}