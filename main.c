#include "libftprintf.h"
#include <stdio.h>
int	main()
{
	int count;

	count = count_ph("%s holea  djfsl % lasjf %c\n alksdji\n");
	printf("%d\n", count);

	return (0);
}
