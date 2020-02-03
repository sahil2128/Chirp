#include "io.hpp"

#include <fstream>
#include <iostream>

#include "../log.hpp"

namespace utils
{
    void write(std::string filename,std::string data)
    {
        std::ofstream file(filename);

        if(!file)
        {
            log(error,"Couldn't write to file named: " + filename);
        }
        else
        {
            file << data;
            file.close();
        }
    }

    std::vector<std::string> read_lines(std::string filename)
    {
        std::vector<std::string> res;

        std::ifstream file(filename);

        if(!file)
        {
            log(error,"Couldn't open file named: " + filename);
            std::exit(-1);
        }

        std::string line;

        while(std::getline(file,line))
        {
            // Removing carriage returns
            if(line.size() > 0)
            {
                if(line.at(line.size() - 1) == (int)13)
                {
                    line.pop_back();
                }
            }

            res.push_back(line);
        }

        return res;
    }
}