#include "ft_printf.h"
#include <stdio.h>

void leaks()
{
	system("leaks a.out");
}

int	main(void)
{
	
	// atexit(leaks);
	int ft_printf_count = 0;
	int printf_count = 0;
	char *ptr = malloc(sizeof(char *) * 5);
	ft_strlcpy(ptr, "hola", 5);
	// printf("\n%p\n", ptr);
	// int printf_count = 0;

	// CHAR
	ft_printf_count = ft_printf("hola %c\n");
	printf_count = printf("hola %c\n");
	if (ft_printf_count == printf_count)
		printf("Tienen el mismo retorno\n\n");

	ft_printf_count = ft_printf("hola %c\n", 5000);
	printf_count = printf("hola %c\n", 5000);
	if (ft_printf_count == printf_count)
		printf("Tienen el mismo retorno\n\n");

	ft_printf_count = ft_printf("hola %c\nCaraballo\n", 5000);
	printf_count = printf("hola %c\nCaraballo\n", 5000);
	if (ft_printf_count == printf_count)
		printf("Tienen el mismo retorno\n\n");
	// BONUS CHAR
	ft_printf_count = ft_printf("%c %     c %+++ ++c %###c\n", 'a', 'b', 'c', 'd');
	printf_count = printf("%c %     c %+++ ++c %###c\n", 'a', 'b', 'c', 'd');
	if (ft_printf_count == printf_count)
		printf("Tienen el mismo retorno\n\n");
	
	// printf("\nft_printf_count: %d\nprintf_count: %d\n", ft_printf_count, printf_count);
	// ft_printf_count = ft_printf("hola %+++++ bd y %+   c", 5, 'z');
	// ft_printf_count = ft_printf("hola %c caballero %s\n que vive en %p y numero %d\nMejor numero %u\nhex: %x\nHEX: %X", 'h', "del zodiaco", ptr, 500, -500, 1000, 1000);
	// printf("\n%x\n%X", 1000, 1000);
	// printf_count = printf("%");
	// sleep(5);

	// '%' WITHOUT FORMAT
	// int result = printf("\nhola perrito bato\nHOLA%    +++  d", 5);
	// printf_count = printf("\nhola %+++++ bd y %c", 5, 'z');
	// printf("\n%d\n", ft_printf_count);
	// printf("%d\n", printf_count);
	free(ptr);
	return (0);
}

