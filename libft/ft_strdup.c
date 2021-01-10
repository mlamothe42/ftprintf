/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamothe <mlamothe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 19:29:27 by mlamothe          #+#    #+#             */
/*   Updated: 2020/10/12 16:40:44 by mlamothe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	char	*res;

	i = -1;
	if (!(res = malloc((ft_strlen(src) + 1) * sizeof(char))))
		return (NULL);
	while (src[++i])
		res[i] = src[i];
	res[i] = 0;
	return (res);
}
