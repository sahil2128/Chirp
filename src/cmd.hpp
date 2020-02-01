/*
Does command relate stuff, like parsing commands
*/
#pragma

namespace command
{
    /*
    Will parse the commands, and modify the settings to match it.

    ARGUMENTS
    (int) argc: argument count
    (char*[]) argv: argument value
    
    RETURN VALUES
    If the parsing was succesfull, the function will return true, in the case of an 
    error, it will return false
    */ 
    bool parse(int,char*[]);
}