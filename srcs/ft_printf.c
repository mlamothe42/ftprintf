/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamothe <mlamothe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 18:03:34 by mlamothe          #+#    #+#             */
/*   Updated: 2021/01/10 10:46:16 by mlamothe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

# include "../libft/libft.h"

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
	if (opts->conversion == '%')
		return (ft_handle_percent(ap, printed, opts));
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
	//printf("flag : %d\n", opts.flags);
	while (ft_is_number(str[*i]))
		if (ft_handle_width(&opts, str[*i], i))
			return (-1);
	//printf("width : %d\n", opts.width);
	if (str[*i] == '.')
	{
		++(*i);
		while (ft_is_number(str[*i]))
			if (ft_handle_precision(&opts, str[*i], i))
				return (-1);
		if (opts.precision == -1)
			opts.precision = 0;
	}
	//printf("precision : %d\n", opts.precision);
	if (ft_handle_conversion(&opts, str[*i], i))
		return (-1);
	//printf("conversion : %c\n\n", opts.conversion);
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
				printf("OMG ERREUR CASSEZ VOUS\n");
				free(*printed);
				free(printed);
				return (-1);
			}
			j = i;
		}
	}
	*printed = ft_realloc_to(printed, str, j, i);
	return (0);
}

int		ft_printf(const char *str, ...)
{
	va_list	ap;
	char	**printed;

	if (!(printed = malloc(sizeof(char *))))
		return (-1);
	va_start(ap, str);
	if ((ft_printf_loop(str, printed, ap)))
		return (-1);
	write(1, *printed, ft_strlen(*printed));
	va_end(ap);
	free(*printed);
	free(printed);
	return (0);
}
