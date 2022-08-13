#include "libftprintf.h"
#include <stdio.h>

void leaks()
{
	system("leaks a.out");
}

int	main(void)
{
	// atexit(leaks);
	int ft_printf_count = 0;
	char *ptr = malloc(sizeof(char));
	printf("\n%p\n", ptr);
	// int printf_count = 0;
	ft_printf_count = ft_printf("hola %c caballero %s\n que vive en %p y numero %d\nMejor numero %u", 'h', "del zodiaco", ptr, 500, -500);
	// printf_count = printf("%");
	// sleep(5);
	return (0);
}

