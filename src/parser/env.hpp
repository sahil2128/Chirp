/*
Parser environment
*/
#pragma once

#include "../utils/node.hpp"
#include "token.hpp"

#include <vector>
#include <string>

namespace parser
{
    /*
    Setup the parser environment, and does the whole parsing process, then
    returns the parse tree.
    Takes a vector with each line of the file as input
    */
    std::vector<node> parse(std::vector<std::string>);

    /*
    If the current token's type is matching the token type
    provided, the function will return true and move the
    cursor forward
    */
    bool match(token_type);

    /*
    If the current token is matching the token type provided, will return true,
    otherwise will return false and throw an error.
    */
    bool expect(token_type);

    /*
    Goes to the next token, returns true if the operation is succesfull,
    otherwise will return false
    */
    bool next();

    void back();

    /*
    Returns the token one step forward
    */
    token look_forward();

    /*
    Returns the current token
    */
    token look_now();

    /*
    Returns the last token consumed
    */
    token look_back();

    /*
    Saves the current location, so you
    can revert back later
    */
    void mark_location();

    /*
    Goes back to the marked location
    */
    void go_back();
}