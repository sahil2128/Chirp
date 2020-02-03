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
    int col = 0;
    int tkn_start = 0;

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
        else if(word == "ptr" || word == "long" || word == "int" || word == "char" || word == "bool" || word == "byte" || word == "none")
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

            case '$':
            t.type = deref;
            break;
        }
        return t;
    }

    std::vector<token> lexe(std::vector<std::string> input)
    {
        std::vector<token> res;
        int pos = 0;

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
                    int start = i;

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

                    tracker::push_token(start,i);
                }
                else if(c == '#')
                {
                    break;
                }
                else if(isspace(c))
                {
                    if(!word.empty())
                    {
                        res.push_back(get_token_word(word));
                        tracker::push_token(i - word.size(),i);
                        word.clear();
                    }
                }
                // --- TERRIBLE STUFF STARTING ---
                // Oof
                else if(c == '{' || c == '}' || c == '(' || c == ')' 
                || c == ':' || c == ',' || c == '$')
                {
                    if(!word.empty())
                    {
                        res.push_back(get_token_word(word));
                        tracker::push_token( (i - word.size()) - 1,i - 1);
                    }

                    res.push_back(get_token_char(c));
                    tracker::push_token(i - 1,i);
                    word.clear();
                }
                else if(c == '+' || c == '-' || c == '*' || c == '/')
                {
                    int strt = i;

                    token t;
                    t.value += c;

                    if(line.at(i + 1) == '=')
                    {
                        i++;
                        t.value += '=';
                    }

                    t.type = math_op;
                    res.push_back(t);
                    tracker::push_token(strt,i);
                }
                else if(c == '<' || c == '>' || c == '!' || c == '=')
                {
                    int strt = i;
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
                    tracker::push_token(strt,i);
                }
                // --- TERRIBLE STUFF DONE ---
                else
                {
                    word += c;
                }
            }
            tracker::next_line();
        }

        token end;
        end.type = eof;
        res.push_back(end);
        
        return res;
    }
}