#include "libftprintf.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    t_list **list;
    
    ft_lstadd_back(list, ft_lstnew("contenido"));
    ft_lstadd_back(list, ft_lstnew("contenido2"));

    ft_lstiter(*list, &print_to_sys_out);

    return (0);
}
