#include "libftprintf.h"
#include <stdio.h>

int	main(void)
{
	int count;
	char *c = "%s holea%    jfsl %%%% l% c %x %X %uasjf %cmake \n alksdji\n";
	// printf("%s holea%                                                           jfsl %%%% l% c %x %X %uasjf %c\n alksdji\n");
	count = ft_printf(c);
	// printf("-------------------------------\n");
	// printf("%d\n", count);
	
	// check_leaks();
	return (0);
}

