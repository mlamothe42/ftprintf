#include "libft.h"
#include <string.h>
#include <stdio.h>


int main(void)
{
	printf("%s\n", ft_strnstr("Les chaussettes sont propres", " ", 0));
	printf("%s\n", strnstr("Les chaussettes sont propres", "chaussettes", 0));
}