#include "libftprintf.h"
#include <stdio.h>

int	main(void)
{
	int count;

	// printf("%s holea%                                                           jfsl %%%% l% c %x %X %uasjf %c\n alksdji\n");
	count = ft_printf("%s holea%    jfsl %%%% l% c %x %X %uasjf %c\n alksdji\n");
	// printf("-------------------------------\n");
	// printf("%d\n", count);
	
	return (0);
}