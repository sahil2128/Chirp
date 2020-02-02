ptr raw_syscall(
    ptr: call_number,
    ptr: param1,
    ptr: param2,
    ptr: param3,
    ptr: param4,
    ptr: param5
    )

none write(int: fd, ptr: data, long int: size)
{
    raw_syscall(1,fd,data,size,0,0)
}

entry
{
    write(1,"Hello,World!\n",14)

    ret 0
}