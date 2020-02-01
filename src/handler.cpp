#include "handler.hpp"
#include "tracker.hpp"
#include "log.hpp"
#include "utils/color.hpp"

#include <stdlib.h>
#include <vector>
#include <iostream>

namespace handler
{
    std::vector<err> errors;

    void dump()
    {
        std::cout<<tracker::get_col()<<":"<<tracker::get_cursor();
        std::cout<<"|   ";
        
        int i = 0;
        int cursor = tracker::get_cursor();

        for(std::string w : tracker::get_line())
        {
            if(i == cursor)
            {
                std::cout<<utils::make_color(utils::red,w + " ");
            }
            else
            {
                std::cout<<w<<" ";    
            }

            i++;
        }

        std::cout<<"\n";
    }

    void acc_error(std::string txt)
    {
        err e;
        e.msg = txt;

        e.col = tracker::get_col();
        e.row = tracker::get_cursor();

        errors.push_back(e);
        log(error,txt);    
    }

    bool run_errors()
    {
        if(errors.size() > 0)
        {
            for(err e: errors)
            {
                tracker::to_col(e.col);
                tracker::to_row(e.row);
                dump();
                log(error,e.msg);
            }

            log(error,"Too much errors, quiting");
            std::exit(-1);

            return true;
        }
        else
        {
            return false;
        }
    }
}