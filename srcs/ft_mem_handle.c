/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamothe <mlamothe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 03:34:21 by mlamothe          #+#    #+#             */
/*   Updated: 2021/01/15 19:15:27 by mlamothe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*ft_reallocate(char *str1, char *str2)
{
	int		i;
	int		j;
	char	*ret;

	if (!(ret = malloc((ft_strlen(str1) + (ft_strlen(str2) + 1)
		* sizeof(char)))))
		return (NULL);
	i = -1;
	j = -1;
	while (str1[++i])
		ret[++j] = str1[i];
	i = -1;
	while (str2[++i])
		ret[++j] = str2[i];
	ret[j + 1] = 0;
	free(str2);
	free(str1);
	return (ret);
}

char	*ft_reallocate_int(char *str1, char *str2)
{
	int		i;
	int		j;
	char	*ret;

	if (!(ret = malloc((ft_strlen(str1) + (ft_strlen(str2) + 1)
		* sizeof(char)))))
		return (NULL);
	i = -1;
	j = -1;
	if (str2[0] == '-')
		ret[++j] = '-';
	while (str1[++i])
		ret[++j] = str1[i];
	i = -1;
	if (ret[0] == '-')
		++i;
	while (str2[++i])
		ret[++j] = str2[i];
	ret[j + 1] = 0;
	free(str2);
	free(str1);
	return (ret);
}

char	*ft_realloc_to(char **str1, const char *str2, int j, int i)
{
	int		k;
	int		p;
	char	*ret;

	if (!(p = j))
	{
		if (!(ret = malloc((ft_strlen(str2) + 1) * sizeof(char))))
			return (NULL);
	}
	else if (!(ret = malloc((ft_strlen((*str1)) + (ft_strlen(str2) + 1)
		* sizeof(char)))))
		return (NULL);
	if ((k = (j == 0) ? 0 : -1))
		while ((*str1)[++k])
			ret[k] = (*str1)[k];
	while (j < i)
	{
		ret[k] = str2[j];
		++k;
		++j;
	}
	ret[k] = 0;
	if (p)
		free(*str1);
	return (ret);
}
