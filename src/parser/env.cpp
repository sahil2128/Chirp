#include "env.hpp"
#include "lexer.hpp"
#include "tracker.hpp"
#include "parser.hpp"
#include "../log.hpp"
#include "../handler.hpp"

#include <iostream>

namespace parser
{
    std::vector<token> tokens;
    int pos = 0;
    int marked = 0;

    std::vector<node> parse(std::vector<std::string> lines)
    {
        //std::cout<<"--=== LEXER ===--"<<std::endl;
        log(debug,"--=== LEXER ===--");

        tokens = lexe(lines);

        for(token t : tokens)
        {
            log(debug,">" + t.value + "< : " + std::to_string(t.type));
        }

        //std::cout<<"--=== PARSING ===--"<<std::endl;
        log(debug,"--=== PARSER ===--");

        pos = 0;
        marked = 0;

        tracker::to_start();
        std::vector<node> n = run();

        // Should handle errors here instead of aborting when
        // you get a new erorr, and stopping the parser from
        // finding other errors.
        handler::run_errors();

        return n;
    }

    bool match(token_type t)
    {
        if(tokens.at(pos).type == t)
        {
            //log(debug,"Matched " + std::to_string((int)t));
            pos++;
            tracker::next_word();
            return true;
        }
        return false;
    }

    bool expect(token_type t)
    {
        if(tokens.at(pos).type == t)
        {
            pos++;
            tracker::next_word();
            return true;
        }

        tracker::next_word();
        //handler::dump();
        handler::acc_error("Unexpected token: " + tokens.at(pos).value + ", expected token id: " + std::to_string(t));
        next();
        
        // Code to throw the error not done yet
        return false;
    }

    bool next()
    {
        pos++;
        return true;
    }

    void back()
    {
        pos--;
    }

    token look_forward()
    {
        return tokens.at(pos + 1);
    }

    token look_now()
    {
        return tokens.at(pos);
    }

    token look_back()
    {
        return tokens.at(pos - 1);
    }

    void mark_location()
    {
        marked = pos;
        //log(debug,"Marked location at " + std::to_string(marked));
    }

    void go_back()
    {
        pos = marked;
        //log(debug,"Going back to " + std::to_string(marked));
    }
}