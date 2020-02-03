#include "handler.hpp"
#include "tracker.hpp"
#include "log.hpp"

#include "utils/color.hpp"

#include <iostream>

namespace handler
{
    bool fatal = false;
    int local_line = 0;

    std::vector<std::string> dump(tracker::location l)
    {
        std::vector<std::string> res;

        int sline; // start line
        int eline; // end line

        if(l.line < 1)
        {
            sline = 0;
            local_line = 0;
        }
        else
        {
            sline = l.line - 1;
            local_line = 1;
        }

        // Might cause error if error is at last line
        if(l.line < tracker::get_line_count())
        {
            eline = l.line + 1;  
        }
        else
        {
            eline = l.line;
        }

        // Largest number's, number of digit + 3
        // Basicaly the distance from the first character
        // to the "|" character, while dumping a line 
        int colsize = std::to_string(eline).size() + 1;
        std::string base_col;

        for(int i = 0; i < colsize; i++)
        {
            base_col += " ";
        }

        for(int y = sline; y <= eline; y++)
        {
            std::string line;
            std::string col = base_col;

            int x = 0;
            for(char c:std::to_string(y))
            {
                col.at(x) = c;
                x++;
            }

            line += col;
            line += "| ";
            line += tracker::get_line(y);
            res.push_back(line);
        }

        return res;
    }

    void error_at_line(std::string msg,int line_num)
    {
        fatal = true;
        log(debug,"Starting error message logging");

        tracker::location l;
        l.line = line_num;
        l.start = 0;
        l.stop = tracker::get_line(line_num).size() - 1;

        std::string helper = "At\n"; // Locationg helper
        helper += "   line:" + std::to_string(line_num);
        log(error,msg + '\n' + helper);

        std::vector<std::string> dumped = dump(l);

        // Finds the column size
        int col_size = 0;
        std::string col_str;

        for(char c : dumped.at(0))
        {
            if(c != '|')
            {
                col_size++;
                col_str += " ";
            }
            else
            {
                break;
            }
        }

        // Prints out the location
        int y = 0;
        for(std::string line : dumped)
        {
            if(y == local_line)
            {
                std::cout<<"\e[1m"<<line<<"\e[0m"<<std::endl;
                std::cout<<col_str<<"|";

                std::string spaces;
                for(int i = 0; i < l.start; i++)
                {
                    spaces += " ";
                }

                std::cout<<spaces;

                std::string marks;
                for(int i = l.start; i <= l.stop; i++)
                {
                    marks += "^";
                }
                std::cout<<utils::make_color(utils::red,marks)<<std::endl;
            }
            else
            {
                std::cout<<line<<std::endl;
            }

            if(y < dumped.size() - 1 && y != local_line)
            {
                std::cout<<col_str<<"|"<<std::endl;
            }

            y++;
        }
    }

    void error_at_token(std::string msg,int index)
    {
        fatal = true;
        log(debug,"Starting error message logging");
        
        tracker::location l = tracker::get_token_location(index);

        std::vector<std::string> lines = dump(l);

        std::string helper = "At\n"; // Locationg helper
        helper += "   line:" + std::to_string(l.line);
        helper += "\n";
        helper += "   from:" + std::to_string(l.start) = " to "+ std::to_string(l.stop);
        log(error,msg + '\n' + helper);

        // Prints out the location
        for(std::string line : lines)
        {
            std::cout<<line<<std::endl;
        }
    }
}