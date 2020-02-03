#include "env.hpp"
#include "lexer.hpp"
#include "tracker.hpp"
#include "parser.hpp"

#include "../log.hpp"
#include "../handler.hpp"
#include "../tracker.hpp"

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

        std::vector<node> n = run();

        return n;
    }

    bool match(token_type t)
    {
        if(tokens.at(pos).type == t)
        {
            //log(debug,"Matched " + std::to_string((int)t));
            pos++;
            return true;
        }
        return false;
    }

    bool expect(token_type t)
    {
        if(tokens.at(pos).type == t)
        {
            pos++;
            return true;
        }        
        // Code to throw the error not done yet

        if(tokens.at(pos).type == eof)
        {
            handler::error_at_line(
                "Unexpected end of file",
                tracker::get_token_location(pos - 1).line
                );
        }
        else
        {
            handler::error_at_token("Unexpected token",pos);
        }

        next();
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
        if(pos + 1 >= tokens.size())
        {
            log(debug,"Tried to look outside of token list");
            token t;
            t.type = out_of_range;
            return t;
        }
        else 
        {
            return tokens.at(pos + 1);
        }
    }

    token look_now()
    {
        
        return tokens.at(pos);
    }

    token look_back()
    {
        return tokens.at(pos - 1);
    }

    int get_pos()
    {
        return pos;
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