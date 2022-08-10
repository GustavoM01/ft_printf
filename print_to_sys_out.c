#include "libftprintf.h"

void    print_to_sys_out(t_placeholder *ph) 
{
    ft_putstr_fd(ph->start, 1);
    ft_putchar_fd('\n', 1);
}