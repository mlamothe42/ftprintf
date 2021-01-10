/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_conv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamothe <mlamothe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 06:05:27 by mlamothe          #+#    #+#             */
/*   Updated: 2021/01/10 09:40:26 by mlamothe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int	ft_handle_char(va_list ap, char **printed, t_options *opts)
{
	char *word;

	if (opts->flags == 1 || opts->precision != -1)
		return (-1);
	if (!(word = malloc(2 * sizeof(char))))
		return (-1);
	word[0] = va_arg(ap, int);
	word[1] = 0;
	if (opts->flags == 0 && opts->width > ft_strlen(word))
		if (!(word = ft_reallocate(
		ft_strpadding(opts->flags, opts->width - ft_strlen(word)), word)))
			return (-1);
	if (opts->flags == 2 && opts->width > ft_strlen(word))
		if (!(word = ft_reallocate(word,
		ft_strpadding(opts->flags, opts->width - ft_strlen(word)))))
			return (-1);
	*printed = ft_reallocate(*printed, word);
	return (0);
}

int	ft_handle_string(va_list ap, char **printed, t_options *opts)
{
	char *word;

	if (opts->flags == 1)
		return (-1);
	word = ft_strdup(va_arg(ap, char *));
	if (opts->precision < (signed int)ft_strlen(word) &&
		opts->precision > -1)
	{
		ft_strlcpy(word, word, opts->precision + 1);
	}
	if (opts->flags == 0 && opts->width > ft_strlen(word))
		if (!(word = ft_reallocate(
		ft_strpadding(opts->flags, opts->width - ft_strlen(word)), word)))
			return (-1);
	if (opts->flags == 2 && opts->width > ft_strlen(word))
		if (!(word = ft_reallocate(word,
		ft_strpadding(opts->flags, opts->width - ft_strlen(word)))))
			return (-1);
	*printed = ft_reallocate(*printed, word);
	return (0);
}

int	ft_handle_address(va_list ap, char **printed, t_options *opts)
{
	char *nbr;

	if (opts->precision != -1 || opts->flags == 1 ||
		!(nbr = ft_lxtoa(va_arg(ap, unsigned long))))
		return (-1);
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

int	ft_handle_int(va_list ap, char **printed, t_options *opts)
{
	char *nbr;

	if (!(nbr = ft_itoa(va_arg(ap, int))))
		return (-1);
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

int	ft_handle_hex(va_list ap, char **printed, t_options *opts)
{
	char *nbr;

	if (!(nbr = ft_xtoa(va_arg(ap, unsigned long))))
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
