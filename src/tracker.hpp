/*
Tracks the location of the lexer,parser and code generator. Mostly usefull during
semantic analysis to throw errors.
*/
#pragma once

#include <string>
#include <vector>

namespace tracker
{
    /*
    Returns the current line, as a string
    */
    std::vector<std::string> get_line();

    /*
    Returns the line at specified column
    */
    std::vector<std::string> get_line(int);

    /*
    Adds the string to the current line
    */
    void push_word(std::string);

    /*
    Saves all the pushed words in the current line, and goes to the next one
    */
    void push_line();

    /*
    Goes to the next word
    Return false, if you can't go next
    */
    bool next_word();

    /*
    Goes to the next line
    Return false, if you can't go next
    */
    bool next_line();

    /*
    Moves the cursor to the specified token position, and also makes the
    line the line where the token is.
    */
   void to_word(int);

   /*
   Returns to the earliest tracked word
   */
   void to_start();

    /*
    Returns the current line column
    */
    int get_col();

    /*
    Returns the current cursor(row)
    */
    int get_cursor();

    void to_col(int);
    void to_row(int);

    void reset();
}