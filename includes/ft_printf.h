/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamothe <mlamothe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 01:35:08 by mlamothe          #+#    #+#             */
/*   Updated: 2021/01/10 10:28:27 by mlamothe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include "../libft/libft.h"

# include <unistd.h>

# include <stdlib.h>

# include <stdio.h>

# include <stdarg.h>

int		ft_printf(const char *str, ...);

typedef struct s_options
{
	int				flags;
	unsigned int	width;
	int				precision;
	int				length;
	char			conversion;
}		t_options;

char		*ft_reallocate(char *str1, char *str2);

char		*ft_realloc_to(char **str1, const char *str2, int j, int i);

t_options	ft_init_opts(void);

int			ft_is_valid(char c);

int			ft_is_number(char c);

int			ft_is_flag(char c);

int			ft_is_precision(char c);

int			ft_is_conversion(char c);

int			ft_handle_conversion(t_options *opts, char c, int *i);

int			ft_handle_flags(t_options *opts, char c, int *i);

int			ft_handle_width(t_options *opts, char c, int *i);

int			ft_handle_precision(t_options *opts, char c, int *i);

int			ft_select_ft(va_list ap, char **printed, t_options *opts);

int			ft_handle_address(va_list ap, char **printed, t_options *opts);

int			ft_handle_char(va_list ap, char **printed, t_options *opts);

int			ft_handle_string(va_list ap, char **printed, t_options *opts);

int			ft_handle_int(va_list ap, char **printed, t_options *opts);

int			ft_handle_hex(va_list ap, char **printed, t_options *opts);

int			ft_handle_percent(va_list ap, char **printed, t_options *opts);

int			ft_handle_unsigned(va_list ap, char **printed, t_options *opts);

char		*ft_strpadding(int type, int n);

char		*ft_utoa(unsigned int n);

char		*ft_xtoa(unsigned int n);

char		*ft_lxtoa(unsigned long n);

char		*set_word(int n, int i);

#endif