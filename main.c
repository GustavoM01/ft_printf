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
	char *ptr = malloc(sizeof(char *) * 5);
	ft_strlcpy(ptr, "hola", 5);
	// printf("\n%p\n", ptr);
	// int printf_count = 0;
	
	ft_printf_count = ft_printf("hola %++d y %+c", 5, 'z');
	// ft_printf_count = ft_printf("hola %c caballero %s\n que vive en %p y numero %d\nMejor numero %u\nhex: %x\nHEX: %X", 'h', "del zodiaco", ptr, 500, -500, 1000, 1000);
	// printf("\n%x\n%X", 1000, 1000);
	// printf_count = printf("%");
	// sleep(5);

	// '%' WITHOUT FORMAT
	// int result = printf("\nhola perrito bato\nHOLA%    +++  d", 5);
	printf("\n%d\n", ft_printf_count);
	// printf("\n%#u\n", 5);
	free(ptr);
	return (0);
}

