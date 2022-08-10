#include "libftprintf.h"
#include <stdio.h>

int	main(void)
{
	int finalCountdown = 0;
	char *c = "%s%d%c%d%c\n";
	printf("count is: %d\n", finalCountdown);
	
	finalCountdown = ft_printf(c);

	printf("count is: %d", finalCountdown);
	
	// check_leaks();
	return (0);
}

