#include "libftprintf.h"
#include "libft/libft.h"
#include <stdio.h>

int	main(void)
{
	int count;

	count = count_place_holders("%s holea  djfsl %%%% l% c %x %X %uasjf %c\n alksdji\n");
	printf("%d\n", count);

	return (0);
}