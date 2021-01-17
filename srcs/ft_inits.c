/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inits.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamothe <mlamothe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 03:37:49 by mlamothe          #+#    #+#             */
/*   Updated: 2021/01/14 19:20:20 by mlamothe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

t_options	ft_init_opts(void)
{
	t_options	opts;

	opts.flags = 0;
	opts.width = -1;
	opts.precision = -1;
	opts.length = 0;
	opts.sign = 1;
	opts.conversion = 0;
	return (opts);
}

int			ft_lower_upper(char c)
{
	if (c == 'x')
		return (87);
	else
		return (55);
}
