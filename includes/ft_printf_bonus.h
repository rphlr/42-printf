/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 19:30:20 by aperez-b          #+#    #+#             */
/*   Updated: 2022/11/28 16:30:50 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H

# define FT_PRINTF_BONUS_H

# include "ft_printf.h"
# include <stdarg.h>

/* Struct to keep track of various format parameters */
typedef struct s_format
{
	int		minus;
	int		plus;
	int		width;
	int		precision;
	int		neg_prec;
	char	specifier;
	int		zero;
	int		dot;
	int		space;
	int		sharp;
}			t_format;

# define INT_MIN -2147483648
# define UINT_MAX 4294967295

/* String containing printf's specifiers */
# define SPECIFIERS	"cspdiuxX%"

/* Hexadecimal base (lowercase) */
# define HEXALOW	"0123456789abcdef"

/* Hexadecimal base (uppercase) */
# define HEXAUP		"0123456789ABCDEF"

/* Custom function to format and print data */
int			ft_printf(const char *str, ...);

/* Initializes default parameters for new format struct */
t_format	ft_newformat(void);

/* Calls printing function depending on the specifier */
int			ft_print_format(t_format f, va_list ap);

/* Prints chars with format */
int			ft_print_c_pct(t_format f, va_list ap);

/* Prints strings with format */
int			ft_print_s(t_format f, va_list ap);

/* Prints decimal number with format */
int			ft_print_d_i_u(t_format f, va_list ap);

/* Prints hexadecimal number with format */
int			ft_print_x(t_format f, va_list ap);

/* Prints 0x followed by a hexadecimal number with format */
int			ft_print_p(t_format f, va_list ap);

/* Checks the str after a '%' is found and fills struct */
int			ft_parse(char *str, va_list	ap);

#endif
