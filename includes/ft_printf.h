/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamothe <mlamothe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 01:35:08 by mlamothe          #+#    #+#             */
/*   Updated: 2021/01/15 20:46:45 by mlamothe         ###   ########.fr       */
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
	int				width;
	int				precision;
	int				length;
	int				sign;
	char			conversion;
}		t_options;

char		*ft_reallocate(char *str1, char *str2);

char		*ft_reallocate_int(char *str1, char *str2);

char		*ft_realloc_to(char **str1, const char *str2, int j, int i);

t_options	ft_init_opts(void);

int			ft_is_valid(char c);

int			ft_is_number(char c);

int			ft_is_flag(char c);

int			ft_is_precision(char c);

int			ft_is_conversion(char c);

int			ft_is_sign(char c);

int			ft_lower_upper(char c);

int			ft_handle_conversion(t_options *opts, char c);

int			ft_handle_flags(t_options *opts, char c, int *i);

int			ft_handle_width(va_list ap, t_options *opts, const char *str, int *i);

int			ft_handle_precision(va_list ap, t_options *opts,
								const char *str, int *i);

void		ft_handle_sign(t_options *opts, char c, int *i);

int			ft_select_ft(va_list ap, char **printed, t_options *opts);

int			ft_handle_address(va_list ap, char **printed, t_options *opts);

char		*ft_handle_address_bis(char *nbr, t_options *opts);

int			ft_handle_char(va_list ap, char **printed, t_options *opts);

int			ft_handle_char_null(char *word, char **printed, t_options *opts);

int			ft_handle_string(va_list ap, char **printed, t_options *opts);

int			ft_handle_string_null(char **printed, t_options *opts);

int			ft_handle_int(va_list ap, char **printed, t_options *opts);

char		*ft_handle_int_prec(char *nbr, t_options *opts);

int			ft_handle_hex(va_list ap, char **printed, t_options *opts);

char		*ft_handle_hex_bis(char *nbr, t_options *opts);

int			ft_handle_percent(char **printed);

int			ft_handle_unsigned(va_list ap, char **printed, t_options *opts);

char		*ft_strpadding(int type, int n);

char		*ft_utoa(unsigned int n);

char		*ft_xtoa(unsigned int n, int cap);

char		*ft_lxtoa(unsigned long n);

char		*set_word(int n, int i);

char		*ft_nil(int i);

#endif