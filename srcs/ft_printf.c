/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:34:59 by rrouille          #+#    #+#             */
/*   Updated: 2022/11/19 13:08:05 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
* @author	rrouille
* @title	Printf
* @notice	This project is clear and efficient. You have to recode printf. You
*			will then be able to reuse it in your future projects. This project
*			is mainly about variable size arguments.
*/

#include "ft_printf.h"

/**
* @notice	This function prints a string.
* @param	char_pointer		The string to print.
* @return	int					The lenght of characters of the printed
*								string.
*/
int	print_str(char *str)
{
	int	len;

	len = 0;
	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	while (str[len])
		ft_putchar_fd(str[len++], 1);
	return (len);
}

/**
* @notice	This function prints the unsigned interger number.
* @param	unsigned_int		The unsigned integer number to print.
* @return	int					The lenght of characters of the printed
*								unsigned integer.
*/
int	print_unsigned(unsigned int num)
{
	int		len;
	char	*numchar;

	len = 0;
	if (num == 0)
	{
		ft_putchar_fd('0', 1);
		len++;
	}
	else
	{
		numchar = ft_unsigned_itoa(num);
		len += print_str(numchar);
		free(numchar);
	}
	return (len);
}

/**
* @notice	This function prints a number.
* @param	int					The number to print.
* @return	int					The lenght of characters of the printed
*								number.
*/
int	print_nbr(int num)
{
	int		len;
	char	*numchar;

	len = 0;
	numchar = ft_itoa(num);
	len = print_str(numchar);
	free(numchar);
	return (len);
}

/**
* @notice	This function links and converts the character next to '%' to the
*			correct argument and function.
* @param	va_list				The arguments.
* @param	const_char			The character next to '%'.
* @return	int					The lenght of characters of the printed
*								conversion.
*/
int	arg_conversion(va_list args, const char conversion)
{
	int	len;

	len = 1;
	if (conversion == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	else if (conversion == 's')
		len = print_str(va_arg(args, char *));
	else if (conversion == 'p')
		len = print_ptr(va_arg(args, unsigned long long));
	else if (conversion == 'd' || conversion == 'i')
		len = print_nbr(va_arg(args, int));
	else if (conversion == 'u')
		len = print_unsigned(va_arg(args, unsigned int));
	else if (conversion == 'x' || conversion == 'X')
		len = print_hex(va_arg(args, unsigned int), conversion);
	else if (conversion == '%')
		ft_putstr_fd("%", 1);
	return (len);
}

/**
* @notice	The printf utility conversions and prints its arguments, after the
*			first, under control of the conversion. The conversion is a character
*			string which contains three types of objects: plain characters, which
*			are simply copied to standard output, character escape sequences
*			which are converted and copied to the standard output, and conversion
*			specifications, each of which causes printing of the next successive
*			argument.
* @param	const_char			The arguments are treated as strings
* @param	...					A variadic argument corresponding to each character
*								after the '%' if there is some.
* @return	int					The string lenght of all arguments.
*/
int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += arg_conversion(args, str[i + 1]);
			i++;
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}
