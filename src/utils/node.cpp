#include "node.hpp"
#include "utils.hpp"
#include "../log.hpp"

#include <iostream>

node ohno("undefined");

node::node()
{
    // Doesn't need anything yet, might have some stuff later
}

node::node(std::string v)
{
    value = v;
}

node& node::get(std::string name)
{
    // Very inneficient, but I doubt there will be a lot of direct child nodes
    for(node& child : this->childs)
    {
        if(child.value == name)
        {
            return child;
        }
    }
    // Need some error feedback or something
    log(debug,"Node " + name + " not found on tree");
    log(debug,"Dumping " + dump_xml());
    return ohno;
}

node& node::get(int p)
{
    if(this->childs.size() >= p)
    {
        return childs.at(p);
    }
    else
    {
        // Need some error feedback or something
        log(debug,"Node " + std::to_string(p) + " not found on tree");
        log(debug,"Dumping " + dump_xml());
        return ohno;
    }
}

node& node::push(node n)
{
    this->childs.push_back(n);
    return this->childs.at(this->childs.size() - 1);
}

std::vector<node> node::get_all()
{
    return childs;
}

std::string node::dump()
{
    std::string res;

    std::vector<node> queue;
    std::vector<node> stage;
    
    // Adding current node's child
    for(int i = 0; i < this->childs.size(); i++)
    {
        queue.push_back(this->childs.at(i));
    }

    // Recursively finding child nodes
    for(int i = 0; i < queue.size(); i++){
        node now = queue.at(i);

        //std::cout<<now.value<<" ";
        res += now.value + " ";

        for(node child:now.childs)
        {
            stage.push_back(child);
        }

        if(i == queue.size() - 1)
        {
            res += "\n";

            queue.insert(queue.end(),stage.begin(),stage.end());
            stage.clear();
        }
    }

    return res;
}

std::string node::dump_xml()
{
    std::string res;

    std::string v;

    if(utils::is_number(value))
    {
        v = "_" + value;
    }
    else
    {
        v = value;
    }

    res += "<" + v + ">";

    for(node child : childs)
    {
        res += child.dump_xml();
    }

    res += "</" + v + ">";

    return res;
}