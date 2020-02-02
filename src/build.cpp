#include "build.hpp"
#include "log.hpp"

#include "utils/io.hpp"

#include <unistd.h>
#include <iostream>

std::string o;

// TODO: Remove 

namespace build
{
    std::string remove_extension(std::string txt)
    {
        std::string res;

        for(char c : txt)
        {
            if(c != '.')
            {
                res += c;
            }
            else
            {
                break;
            }
        }

        return res;
    }

    // Really needs improvement
    bool command_exists(std::string c)
    {
        // Unix
        std::string cmd = "which " + c + " > /dev/null";
        
        // TODO: Windows

        if(system(cmd.c_str()) == 256)
        {
            return false;
        }
        return true;
    }

    void delete_file()
    {
        // Unefficient, should be changed
        system("rm temp.c");
    }

    void build_file(std::string content, std::string target)
    {
        o = remove_extension(target);
        utils::write("temp.c",content);
        
        if(command_exists("gcc"))
        {
            std::string cmd = "gcc temp.c -w -c -nostdlib -o ";
            cmd += o;
            cmd += ".o";

            system(cmd.c_str());

            std::string ld = "ld lib/syscall.o " + o + ".o ";
            system(ld.c_str());
        }
        else if (command_exists("clang"))
        {
            std::string cmd = "clang temp.c -o ";
            cmd += o;
            system(cmd.c_str());
        }
        else
        {
            log(error,"No C compiler is installed on this computer.");
            log(error,"Please install gcc or clang");
        }

        delete_file();
    }
}