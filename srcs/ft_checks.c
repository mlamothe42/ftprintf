/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamothe <mlamothe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 03:47:05 by mlamothe          #+#    #+#             */
/*   Updated: 2021/01/10 09:46:02 by mlamothe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int	ft_is_conversion(char c)
{
	return (ft_strchr("cspdiuxX%", c) != NULL);
}

int	ft_is_flag(char c)
{
	return (ft_strchr("-0", c) != NULL);
}

int	ft_is_number(char c)
{
	return (ft_strchr("0123456789", c) != NULL);
}

int	ft_is_valid(char c)
{
	return (ft_is_conversion(c) || ft_is_flag(c) || ft_is_number(c)
			|| c == '.');
}
