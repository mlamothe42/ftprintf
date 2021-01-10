/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamothe <mlamothe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 04:11:53 by mlamothe          #+#    #+#             */
/*   Updated: 2021/01/10 08:42:07 by mlamothe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int	ft_handle_conversion(t_options *opts, char c, int *i)
{
	if (ft_is_conversion(c))
	{
		opts->conversion = c;
		++(*i);
		return (0);
	}
	return (-1);
}

int	ft_handle_flags(t_options *opts, char c, int *i)
{
	if (c == '0')
	{
		if (opts->flags == 1)
			return (-1);
		if (opts->flags == 0)
			opts->flags = 1;
		++(*i);
	}
	else
	{
		if (opts->flags == 2)
			return (-1);
		opts->flags = 2;
		++(*i);
	}
	return (0);
}

int	ft_handle_width(t_options *opts, char c, int *i)
{
	opts->width = opts->width * 10 + (c - 48);
	++(*i);
	return (0);
}

int	ft_handle_precision(t_options *opts, char c, int *i)
{
	if (opts->precision == -1)
		opts->precision = 0;
	opts->precision = opts->precision * 10 + (c - 48);
	++(*i);
	return (0);
}
