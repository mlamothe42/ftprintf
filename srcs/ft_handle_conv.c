/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_conv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamothe <mlamothe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 06:05:27 by mlamothe          #+#    #+#             */
/*   Updated: 2021/01/17 17:39:57 by mlamothe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		ft_handle_char(va_list ap, char **printed, t_options *opts)
{
	char	*word;
	char	c;

	if (!(word = malloc(2 * sizeof(char))))
		return (-1);
	c = va_arg(ap, int);
	word[0] = c;
	word[1] = 0;
	//if (!word[0])
	//	return (ft_handle_char_null(word, printed, opts));
	if (opts->flags == 0 && opts->width > 1)
		if (!(word = ft_reallocate(
		ft_strpadding(opts->flags, opts->width - 1), word)))
			return (-1);
	if (opts->flags == 2 && opts->width > 1)
		if (!(word = ft_reallocate(word,
		ft_strpadding(opts->flags, opts->width - 1))))
			return (-1);
	*printed = ft_reallocate(*printed, word);
	return (0);
}

int		ft_handle_string(va_list ap, char **printed, t_options *opts)
{
	char *word;

	if (opts->flags == 1)
		return (-1);
	word = va_arg(ap, char *);
	if (!word)
		return (ft_handle_string_null(printed, opts));
	word = ft_strdup(word);
	if (opts->precision < (signed int)ft_strlen(word) && opts->precision > -1)
		ft_strlcpy(word, word, opts->precision + 1);
	if (opts->flags == 0 && opts->width > (signed int)ft_strlen(word))
		if (!(word = ft_reallocate(
		ft_strpadding(opts->flags, opts->width - ft_strlen(word)), word)))
			return (-1);
	if (opts->flags == 2 && opts->width > (signed int)ft_strlen(word))
		if (!(word = ft_reallocate(word,
		ft_strpadding(opts->flags, opts->width - ft_strlen(word)))))
			return (-1);
	*printed = ft_reallocate(*printed, word);
	return (0);
}

int		ft_handle_address(va_list ap, char **printed, t_options *opts)
{
	char *nbr;
	unsigned long ptr;

	if (!(ptr = va_arg(ap, unsigned long)))
		nbr = ft_nil(1);
	if(ptr && !(nbr = ft_lxtoa(ptr)))
		return (-1);
	if (opts->precision > (signed int)ft_strlen(nbr))
		if (!(nbr = ft_reallocate(
		ft_strpadding(1, opts->precision - ft_strlen(nbr)), nbr)))
			return (-1);
	if (opts->flags != 2 && opts->width > (signed int)ft_strlen(nbr))
		if (!(nbr = ft_reallocate(
		ft_strpadding(opts->flags, opts->width - ft_strlen(nbr)), nbr)))
			return (-1);
	if (opts->flags == 2 && opts->width > (signed int)ft_strlen(nbr))
		if (!(nbr = ft_reallocate(nbr,
		ft_strpadding(opts->flags, opts->width - ft_strlen(nbr)))))
			return (-1);
	*printed = ft_reallocate(*printed, nbr);
	return (0);
}

int		ft_handle_int(va_list ap, char **printed, t_options *opts)
{
	char	*nbr;

	if (!(nbr = ft_itoa(va_arg(ap, int))))
		return (-1);
	if (!(nbr = ft_handle_int_prec(nbr, opts)))
		return (-1);
	if (opts->flags == 1 && opts->precision > -1)
		opts->flags = 0;
	if (opts->flags == 1 && opts->width > (signed int)ft_strlen(nbr))
		if (!(nbr = ft_reallocate_int(
		ft_strpadding(opts->flags, opts->width - ft_strlen(nbr)), nbr)))
			return (-1);
	if (opts->flags == 0 && opts->width > (signed int)ft_strlen(nbr))
		if (!(nbr = ft_reallocate(
		ft_strpadding(opts->flags, opts->width - ft_strlen(nbr)), nbr)))
			return (-1);
	if (opts->flags == 2 && opts->width > (signed int)ft_strlen(nbr))
		if (!(nbr = ft_reallocate(nbr,
		ft_strpadding(opts->flags, opts->width - ft_strlen(nbr)))))
			return (-1);
	*printed = ft_reallocate(*printed, nbr);
	return (0);
}

int		ft_handle_hex(va_list ap, char **printed, t_options *opts)
{
	char	*nbr;

	if (!(nbr = ft_xtoa(va_arg(ap, int), ft_lower_upper(opts->conversion))))
		return (-1);
	if (nbr[0] == '0' && opts->precision == 0)
		nbr[0] = 0;
	if (opts->precision > (signed int)ft_strlen(nbr))
		if (!(nbr = ft_reallocate(
		ft_strpadding(1, opts->precision - ft_strlen(nbr)), nbr)))
			return (-1);
	if (opts->flags == 1 && opts->precision > -1)
		opts->flags = 0;
	if (opts->flags != 2 && opts->width > (signed int)ft_strlen(nbr))
		if (!(nbr = ft_reallocate(
		ft_strpadding(opts->flags, opts->width - ft_strlen(nbr)), nbr)))
			return (-1);
	if (opts->flags == 2 && opts->width > (signed int)ft_strlen(nbr))
		if (!(nbr = ft_reallocate(nbr,
		ft_strpadding(opts->flags, opts->width - ft_strlen(nbr)))))
			return (-1);
	*printed = ft_reallocate(*printed, nbr);
	return (0);
}
