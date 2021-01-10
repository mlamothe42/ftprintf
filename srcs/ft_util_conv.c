/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_conv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamothe <mlamothe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 06:54:07 by mlamothe          #+#    #+#             */
/*   Updated: 2021/01/10 09:41:51 by mlamothe         ###   ########.fr       */
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

char	*ft_xtoa(unsigned int n)
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
		{
			word[i] = (nbr % 16) + 87;
		}
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
