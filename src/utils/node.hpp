/*
This does all the tree stuff
*/
#pragma once

#include <string>
#include <vector>

/*
Very rudimentary tree node class
*/
class node
{
    public:
    node();
    node(std::string);

    /*
    Value of the node
    */
    std::string value;

    /*
    Position of the node in the parent
    */
    int position;

    /* 
    Returns child node with the same value,
    if none is found then one with the same name will be created 
    */
    node& get(std::string);

    /*
    Return child at specified position in the vector
    */
    node& get(int);

    /*
    Pushes child node to current node.
    Also returns a pointer to the new node.
    */
    node& push(node);

    /*
    Returns the vector of childs
    */
    std::vector<node> get_all();

    /*
    Dumps all of the tree's content onto a string that's with a
    newline for every level of the tree.
    */
    std::string dump();

    /*
    Dumps the tree into a string that is valid xml.
    */
    std::string dump_xml();
    private:
    std::vector<node> childs;
};