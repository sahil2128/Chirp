#include "lexer.hpp"

#include "tracker.hpp"
#include "utils.hpp"

#include <iostream>

/*
This is probably one of the most basic parts of the code, if this doesn't work
well or has problems expanding, then changing it is highly recommended
*/

namespace parser
{
    token get_token_word(std::string word)
    {
        token t;
        t.value = word;
        
        if(word == "entry")
        {
            t.type = entry;
        }
        else if(word == "if")
        {
            t.type = if_kw;
        }
        else if(word == "else")
        {
            t.type = else_kw;
        }
        else if(word == "ret")
        {
            t.type = ret_kw;
        }
        else if(word == "while")
        {
            t.type = while_kw;
        }
        else if(word == "for")
        {
            t.type = for_kw;
        }
        else if(word == "namespace")
        {
            t.type = namespace_kw;
        }
        else if(word == "import")
        {
            t.type = import_kw;
        }
        else if(word == "ptr" || word == "int" || word == "char" || word == "bool" || word == "byte" || word == "none")
        {
            t.type = dtype;
        }
        else
        {
            if(utils::is_number(word))
            {
                t.type = literal;
            }
            else
            {
                if(word == "true" || word == "false")
                {
                    t.type = literal;
                }
                else
                {
                    t.type = ident;
                }
            }
        }
        return t;
    }

    token get_token_char(char c)
    {
        token t;
        t.value = c;

        switch(c)
        {
            case '{':
            t.type = lbrace;
            break;
            case '}':
            t.type = rbrace;
            break;
            
            case '(':
            t.type = lparen;
            break;
            case ')':
            t.type = rparen;
            break;
            
            case '[':
            t.type = lbracket;
            break;
            case ']':
            t.type = rbracket;
            break;

            case ':':
            t.type = confirm;
            break;
            
            case ',':
            t.type = comma;
            break;
        }
        return t;
    }

    std::vector<token> lexe(std::vector<std::string> input)
    {
        std::vector<token> res;
        int pos = 0;

        //tracker::reset();

        std::string word;

        for(std::string line : input)
        {
            line += ' '; // very big brain fix
            for(int i = 0; i < line.size() - 1; i++)
            {
                char c = line.at(i);

                if(c == '"')
                {
                    token t;
                    t.type = literal;
                    i++;
                    t.value += "\"";
                    while(line.at(i) != '"')
                    {
                        t.value += line.at(i);
                        i++;
                    }
                    t.value += "\"";
                    res.push_back(t);
                    tracker::push_word(t.value);
                }
                else if(isspace(c))
                {
                    if(!word.empty())
                    {
                        res.push_back(get_token_word(word));
                        tracker::push_word(word);
                        word.clear();   
                    }
                }
                // Oof
                else if(c == '{' || c == '}' || c == '(' || c == ')' 
                || c == ':' || c == ',')
                {
                    if(!word.empty())
                    {
                        res.push_back(get_token_word(word));
                        tracker::push_word(word);
                    }

                    res.push_back(get_token_char(c));
                    tracker::push_word(std::string(1,c));
                    word.clear();
                }
                // --- TERRIBLE STUFF STARTING ---
                else if(c == '+' || c == '-' || c == '*' || c == '/')
                {
                    token t;
                    t.value += c;

                    if(line.at(i + 1) == '=')
                    {
                        i++;
                        t.value += '=';
                    }

                    t.type = math_op;
                    res.push_back(t);
                    tracker::push_word(t.value);
                }
                else if(c == '<' || c == '>' || c == '!' || c == '=')
                {
                    token t;
                    t.value += c;
                    t.type = cond_op;

                    if(line.at(i + 1) == '=')
                    {
                        i++;
                        t.value += '=';
                    }
                    else if(c == '=')
                    {
                        t.type = assign;
                    }
                    res.push_back(t);
                    tracker::push_word(t.value);
                }
            /*    else if(c == '=')
                {
                    token t;
                    t.value = "=";
                    t.type = assign;
                    tracker::push_word("=");
                } */
                // --- TERRIBLE STUFF DONE ---
                else
                {
                    word += c;
                }
            }
            tracker::push_line();
        }

        token end;
        end.type = eof;
        res.push_back(end);
        
        return res;
    }
}