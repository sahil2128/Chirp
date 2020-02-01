#include "io.hpp"

#include <fstream>
#include <iostream>

namespace utils
{
    void write(std::string filename,std::string data)
    {
        
    }

    std::vector<std::string> read_lines(std::string filename)
    {
        std::vector<std::string> res;

        std::ifstream file(filename);
        std::string line;

        while(std::getline(file,line))
        {
            // Removing carriage returns
            if(line.at(line.size() - 1) == (int)13)
            {
                line.pop_back();
            }

            res.push_back(line);
        }

        return res;
    }
}