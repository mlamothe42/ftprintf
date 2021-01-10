#include "ft_printf.h" 

int		main(void)
{
	char *s;

	s = malloc(15);
	ft_printf("MON TEST %30p BANANE\n", s);
	printf("SON TEST %30p BANANE\n", s);
	free(s);
	return (0);
}