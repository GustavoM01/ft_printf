#include "libftprintf.h"
#include "libft/libft.h"
#include <stdio.h>

int	main(void)
{
	int count;

	count = ft_printf("%s holea  djfsl %%%% l% c %x %X %uasjf %c\n alksdji\n");
	printf("-------------------------------\n");
	printf("%d\n", count);

	return (0);
}