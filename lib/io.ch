require "syscall.ch"
require "str.ch"


none print(char ptr: txt)
{
    write(1,txt,get_size(txt))
}