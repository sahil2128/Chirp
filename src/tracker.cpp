#include "tracker.hpp"

namespace tracker
{
    std::vector<std::vector<std::string>> source;
    std::vector<std::string> line; // current line

    int col = 0; // source.at(col)
    int cursor = 0; // source.at(col).at(cursor)

    std::vector<std::string> get_line()
    {
        return source.at(col);
    }

    std::vector<std::string> get_line(int pos)
    {
        return source.at(pos);
    }

    void push_word(std::string word)
    {
        line.push_back(word);
        cursor++;
    }

    void push_line()
    {
        source.push_back(line);
        col++;
        line.clear();
    }

    bool next_word()
    {
        if(source.at(col).size() - 1 < cursor + 1)
        {
            // Next line
            cursor = 0;
            col++;
        }
        else
        {
            cursor++;
        }
    }

    bool next_line()
    {
        col++;
    }

    void to_word(int tpos)
    {
        
    }

    void to_start()
    {
        col = 0;
        cursor = 0;
    }

    int get_col()
    {
        return col;
    }

    int get_cursor()
    {
        return cursor;
    }

    void to_col(int c)
    {
        col = c;
    }

    void to_row(int r)
    {
        cursor = r;
    }

    void reset()
    {
        col = 0;
        cursor = 0;
        line.clear();
        source.clear();
    }
}