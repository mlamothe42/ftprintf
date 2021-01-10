/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamothe <mlamothe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 16:31:46 by mlamothe          #+#    #+#             */
/*   Updated: 2020/10/12 16:47:06 by mlamothe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*word;

	i = -1;
	if ((ft_strlen(s) - start) < len)
		len = (ft_strlen(s) - start);
	if (!(word = malloc((len + 1) * sizeof(char))))
		return (NULL);
	while (s[start] && (size_t)++i < len)
	{
		word[i] = s[start];
		++start;
	}
	word[i] = 0;
	return (word);
}
