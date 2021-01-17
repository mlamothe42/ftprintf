/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamothe <mlamothe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 18:03:34 by mlamothe          #+#    #+#             */
/*   Updated: 2021/01/17 17:38:38 by mlamothe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		ft_select_ft(va_list ap, char **printed, t_options *opts)
{
	if (opts->conversion == 'c')
		return (ft_handle_char(ap, printed, opts));
	if (opts->conversion == 's')
		return (ft_handle_string(ap, printed, opts));
	if (opts->conversion == 'p')
		return (ft_handle_address(ap, printed, opts));
	if (opts->conversion == 'd' || opts->conversion == 'i')
		return (ft_handle_int(ap, printed, opts));
	if (opts->conversion == 'x' || opts->conversion == 'X')
		return (ft_handle_hex(ap, printed, opts));
	if (opts->conversion == 'u')
		return (ft_handle_unsigned(ap, printed, opts));
	if (opts->conversion == '\%')
		return (ft_handle_percent(printed));
	return (-1);
}

int		ft_check_type(const char *str, int *i, va_list ap, char **printed)
{
	t_options	opts;

	opts = ft_init_opts();
	++(*i);
	while (ft_is_flag(str[*i]))
		if (ft_handle_flags(&opts, str[*i], i))
			return (-1);
	while (ft_is_sign(str[*i]))
		ft_handle_sign(&opts, str[*i], i);
	if (ft_handle_width(ap, &opts, str, i))
		return (-1);
	opts.width *= opts.sign;
	if (str[*i] == '.')
	{
		++(*i);
		if (ft_handle_precision(ap, &opts, str, i))
			return (-1);
	}
	if (ft_handle_conversion(&opts, str[*i]))
		return (-1);
	return (ft_select_ft(ap, printed, &opts));
}

int		ft_printf_loop(const char *str, char **printed, va_list ap)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (str[++i])
	{
		if (str[i] == '%')
		{
			*printed = ft_realloc_to(printed, str, j, i);
			if (ft_check_type(str, &i, ap, printed))
			{
				free(*printed);
				free(printed);
				return (-1);
			}
			j = i+1;
		}
	}
	*printed = ft_realloc_to(printed, str, j, i);
	return (0);
}

int		ft_printf(const char *str, ...)
{
	va_list	ap;
	char	**printed;
	int		i;

	if (!(printed = malloc(sizeof(char *))))
		return (-1);
	va_start(ap, str);
	if ((ft_printf_loop(str, printed, ap)))
		return (-1);
	write(1, *printed, 53);
	va_end(ap);
	i = ft_strlen(*printed);
	free(*printed);
	free(printed);
	return (i);
}
