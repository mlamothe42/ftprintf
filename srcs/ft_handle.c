/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamothe <mlamothe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 04:11:53 by mlamothe          #+#    #+#             */
/*   Updated: 2021/01/14 19:51:12 by mlamothe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		ft_handle_conversion(t_options *opts, char c)
{
	if (ft_is_conversion(c))
	{
		opts->conversion = c;
		return (0);
	}
	return (-1);
}

int		ft_handle_flags(t_options *opts, char c, int *i)
{
	if (c == '0')
	{
		//if (opts->flags == 1)
		//	return (-1);
		if (opts->flags == 0)
			opts->flags = 1;
		++(*i);
	}
	else
	{
		opts->flags = 2;
		++(*i);
	}
	return (0);
}

int		ft_handle_width(va_list ap, t_options *opts, const char *str,
						 int *i)
{
	if (str[*i] == '*')
	{
		opts->width = va_arg(ap, int);
		if (opts->width < 0)
		{
			opts->width *= -1;
			opts->flags = 2;
			/*if (opts->flags != 2)
			{
				opts->flags = 2;
			}
			else
				return (-1);*/
		}
		++(*i);
	}
	else
	{
		if (ft_is_number(str[*i]))
			opts->width = 0;
		while (ft_is_number(str[*i]))
		{
			opts->width = opts->width * 10 + (str[*i] - 48);
			++(*i);
		}
	}
	return (0);
}

void	ft_handle_sign(t_options *opts, char c, int *i)
{
	if (c == '-' || c == '+')
	{
		if (c == '-')
			opts->sign *= -1;
		++(*i);
	}
}

int		ft_handle_precision(va_list ap, t_options *opts, const char *str,
							 int *i)
{
	
	if (str[*i] == '*')
	{
		opts->precision = va_arg(ap, int);
		++(*i);
	}
	else
	{
		if (opts->precision == -1)
			opts->precision = 0;
		while (ft_is_number(str[*i]))
		{
			opts->precision = opts->precision * 10 + (str[*i] - 48);
			++(*i);
		}
	}
	return (0);
}
