#include "tracker.hpp"

#include <iostream>

namespace tracker
{
    std::vector<std::string> source_file;
    std::vector<location> locations;
    int cline = 0; // current line


    location push_token(int _start,int _stop)
    {
        location l;

        l.start = _start;
        l.stop = _stop;
        l.line = cline;

        locations.push_back(l);

        //std::cout<<locations.size()<<":"<<l.line<<":"<<l.start<<"-"<<l.stop<<std::endl;

        return l;
    }

    location get_token_location(int id)
    {
        // Should not pose any problem
        // because the number of locations
        // is supposed to be the same
        // as the number of tokens.
        return locations.at(id);
    }

    void next_line()
    {
        cline++;
    }

    std::string get_line(int i)
    {
        return source_file.at(i);
    }

    int get_line_count()
    {
        return source_file.size() - 1;
    }

    void set_source(std::vector<std::string> s)
    {
        source_file = s;
    }
}