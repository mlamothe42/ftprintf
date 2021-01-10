/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamothe <mlamothe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 16:50:14 by mlamothe          #+#    #+#             */
/*   Updated: 2020/10/12 16:40:50 by mlamothe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*word;
	int		i;
	int		j;

	if (!(word = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char))))
		return (NULL);
	i = -1;
	while (s1[++i])
		word[i] = s1[i];
	j = -1;
	while (s2[++j])
	{
		word[i] = s2[j];
		++i;
	}
	word[i] = 0;
	return (word);
}
