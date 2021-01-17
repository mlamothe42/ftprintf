/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_conv2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamothe <mlamothe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 08:42:24 by mlamothe          #+#    #+#             */
/*   Updated: 2021/01/15 21:00:15 by mlamothe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int	ft_handle_percent(char **printed)
{
	char *per;

	if (!(per = malloc(sizeof(char) * 2)))
		return (-1);
	per[0] = '\%';
	per[1] = 0;
	*printed = ft_reallocate(*printed, per);
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

char	*ft_handle_int_prec(char *nbr, t_options *opts)
{
	int		len;
	char	*ret;

	if ((!opts->precision) && nbr[0]== '0')
		nbr[0] = 0;
	len = ft_strlen(nbr);
	if (nbr[0] == '-')
		--len;
	if (opts->precision > len)
		if (!(ret = ft_reallocate_int(
		ft_strpadding(1, opts->precision - len), nbr)))
			return (NULL);
	return (ret);
}

int		ft_handle_string_null(char **printed, t_options *opts)
{
	char *word;
	
	word = ft_nil(0);
	if (opts->precision < (signed int)ft_strlen(word) && opts->precision > -1)
		ft_strlcpy(word, word, 1);
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

int		ft_handle_char_null(char *word, char **printed, t_options *opts)
{
	char	c;
	
	c = 0;
	if (opts->flags == 0 && opts->width > 1)
		if (!(word = ft_reallocate(
		ft_strpadding(opts->flags, opts->width - 1), word)))
			return (-1);
	if (opts->width > 1 && opts->flags == 2)
	{
		write(1, *printed, ft_strlen(*printed));
		write(1,  &c, 1);
		ft_bzero(*printed, ft_strlen(*printed));
	}
	if (opts->flags == 2 && opts->width > 1)
		if (!(word = ft_reallocate(word,
		ft_strpadding(opts->flags, opts->width - 1))))
			return (-1);
	*printed = ft_reallocate(*printed, word);
	if (opts->width < 2 || opts->flags == 0)
	{
		write(1, *printed, ft_strlen(*printed));
		write(1, &c, 1);
		ft_bzero(*printed, ft_strlen(*printed));
	}
	return (0);
}
