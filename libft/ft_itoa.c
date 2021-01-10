/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamothe <mlamothe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 18:42:42 by mlamothe          #+#    #+#             */
/*   Updated: 2020/10/12 16:35:30 by mlamothe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*set_word(int n, int i)
{
	char	*word;

	if (n < 0)
	{
		if (!(word = malloc((i + 2) * sizeof(char))))
			return (NULL);
		word[0] = '-';
	}
	else if (!(word = malloc((i + 1) * sizeof(char))))
		return (NULL);
	return (word);
}

char	*ft_itoa(int n)
{
	long	nbr;
	int		i;
	int		j;
	char	*word;

	i = 0;
	nbr = n;
	while ((nbr = nbr / 10) != 0)
		++i;
	++i;
	word = set_word(n, i);
	j = (n < 0) ? 0 : -1;
	i = i + ((n < 0) ? 1 : 0);
	word[i] = 0;
	nbr = n;
	nbr = nbr * ((n < 0) ? -1 : 1);
	while (j < --i)
	{
		word[i] = (nbr % 10) + 48;
		nbr = nbr / 10;
	}
	return (word);
}
