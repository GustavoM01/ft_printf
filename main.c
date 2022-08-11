#include "libftprintf.h"
#include <stdio.h>

void leaks()
{
	system("leaks a.out");
}

int	main(void)
{
	atexit(leaks);
	int finalCountdown = 0;
	char *c = "%s\n";

	finalCountdown = ft_printf(c);

	// printf("count is: %d", finalCountdown);
	
	// check_leaks();
	// sleep(5);
	return (0);
}

