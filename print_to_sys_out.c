#include "libftprintf.h"

void    print_to_sys_out(void *str) 
{
    ft_putstr_fd((char *)str, 1);
    ft_putchar_fd('\n', 1);
}