/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inits.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamothe <mlamothe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 03:37:49 by mlamothe          #+#    #+#             */
/*   Updated: 2021/01/10 09:45:57 by mlamothe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

t_options	ft_init_opts(void)
{
	t_options	opts;

	opts.flags = 0;
	opts.width = 0;
	opts.precision = -1;
	opts.length = 0;
	opts.conversion = 0;
	return (opts);
}
