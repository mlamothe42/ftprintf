/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_conv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamothe <mlamothe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 06:54:07 by mlamothe          #+#    #+#             */
/*   Updated: 2021/01/14 22:17:21 by mlamothe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*ft_strpadding(int type, int n)
{
	char	*ret;

	if (!(ret = malloc((n + 1) * sizeof(char))))
		return (NULL);
	ret[n] = 0;
	if (type == 1)
	{
		while (--n >= 0)
			ret[n] = '0';
	}
	else
	{
		while (--n >= 0)
			ret[n] = ' ';
	}
	return (ret);
}

char	*ft_utoa(unsigned int n)
{
	unsigned int	nbr;
	int				i;
	int				j;
	char			*word;

	i = 0;
	nbr = n;
	while ((nbr = nbr / 10) != 0)
		++i;
	++i;
	word = set_word(n, i);
	j = -1;
	word[i] = 0;
	nbr = n;
	while (j < --i)
	{
		word[i] = (nbr % 10) + 48;
		nbr = nbr / 10;
	}
	return (word);
}

char	*ft_xtoa(unsigned int n, int cap)
{
	unsigned int	nbr;
	int				i;
	int				j;
	char			*word;

	i = 0;
	nbr = n;
	while ((nbr = nbr / 16) != 0)
		++i;
	++i;
	word = set_word(n, i);
	j = -1;
	word[i] = 0;
	nbr = n;
	while (j < --i)
	{
		if (nbr % 16 < 10)
			word[i] = (nbr % 16) + 48;
		else
			word[i] = (nbr % 16) + cap;
		nbr = nbr / 16;
	}
	return (word);
}

char	*ft_lxtoa(unsigned long n)
{
	unsigned long	nbr;
	int				i;
	int				j;
	char			*word;

	i = 0;
	nbr = n;
	while ((nbr = nbr / 16) != 0)
		++i;
	i += 3;
	word = set_word(n, i);
	j = 1;
	word[i] = 0;
	word[0] = '0';
	word[1] = 'x';
	nbr = n;
	while (j < --i)
	{
		if (nbr % 16 < 10)
			word[i] = (nbr % 16) + 48;
		else
			word[i] = (nbr % 16) + 87;
		nbr = nbr / 16;
	}
	return (word);
}

char *ft_nil(int i)
{
	char	*ret;

	if (!(ret = malloc(7)))
		return (NULL);
	ret[0] = '(';
	if(i)
	{
		ret[1] = 'n';
		ret[2] = 'i';
		ret[3] = 'l';
		ret[4] = ')';
		ret[5] = 0;
	}
	else{
		ret[1] = 'n';
		ret[2] = 'u';
		ret[3] = 'l';
		ret[4] = 'l';
		ret[5] = ')';
		ret[6] = 0;
	}
	return (ret);
}
