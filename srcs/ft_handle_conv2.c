/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_conv2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamothe <mlamothe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 08:42:24 by mlamothe          #+#    #+#             */
/*   Updated: 2021/01/10 09:49:34 by mlamothe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int	ft_handle_percent(va_list ap, char **printed, t_options *opts)
{
	char *per;

	(void)ap;
	(void)opts;
	if (!(per = malloc(sizeof(char) * 2)))
		return (-1);
	per[0] = '%';
	per[1] = 0;
	*printed = ft_reallocate(*printed, per);
	printf("%s\n", *printed);
	return (0);
}

int	ft_handle_unsigned(va_list ap, char **printed, t_options *opts)
{
	char *nbr;

	if (!(nbr = ft_utoa(va_arg(ap, unsigned long))))
		return (-1);
	if (nbr[0] == '0' && opts->precision == 0)
		nbr[0] = 0;
	if (opts->precision > (signed int)ft_strlen(nbr))
		if (!(nbr = ft_reallocate(
		ft_strpadding(1, opts->precision - ft_strlen(nbr)), nbr)))
			return (-1);
	if (opts->flags != 2 && opts->width > ft_strlen(nbr))
		if (!(nbr = ft_reallocate(
		ft_strpadding(opts->flags, opts->width - ft_strlen(nbr)), nbr)))
			return (-1);
	if (opts->flags == 2 && opts->width > ft_strlen(nbr))
		if (!(nbr = ft_reallocate(nbr,
		ft_strpadding(opts->flags, opts->width - ft_strlen(nbr)))))
			return (-1);
	*printed = ft_reallocate(*printed, nbr);
	return (0);
}
