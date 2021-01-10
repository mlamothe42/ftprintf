/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamothe <mlamothe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 18:29:50 by mlamothe          #+#    #+#             */
/*   Updated: 2020/10/12 16:40:01 by mlamothe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		calc_mots(char *str, char c)
{
	int i;
	int nb;

	i = -1;
	nb = 0;
	while (str[++i])
	{
		while (str[i] && str[i] == c)
			i++;
		while (str[i] && str[i] != c)
			i++;
		if (str[i] == 0)
			i--;
		nb++;
	}
	return (nb + 1);
}

int		size_mot(char *str, char c, int i)
{
	int	smot;

	smot = 0;
	while (str[i] && str[i] != c)
	{
		smot++;
		i++;
	}
	return (smot);
}

char	*crea_mot(char *str, char c, int *i)
{
	char	*mot;
	int		smot;
	int		j;

	smot = size_mot(str, c, *i);
	mot = malloc((smot + 1) * sizeof(char));
	j = -1;
	while (++j < smot)
	{
		mot[j] = str[*i];
		(*i)++;
	}
	mot[j] = 0;
	return (mot);
}

char	**ft_split(char *str, char c)
{
	int		i;
	char	**tous;
	int		nbmots;

	i = -1;
	nbmots = 0;
	if (str == NULL ||
		(!(tous = (char **)malloc(calc_mots(str, c) * sizeof(char *)))))
	{
		return (NULL);
	}
	while (str[++i])
	{
		while (str[i] == c)
			i++;
		if (str[i])
		{
			tous[nbmots] = crea_mot(str, c, &i);
			nbmots++;
		}
		i--;
	}
	tous[nbmots] = 0;
	i = -1;
	return (tous);
}
