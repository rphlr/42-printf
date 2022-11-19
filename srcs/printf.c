/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:34:59 by rrouille          #+#    #+#             */
/*   Updated: 2022/11/19 12:43:06 by rrouille         ###   ########.fr       */
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

/*
ft_putunsigned
print_str
ft_printnbr
ptr_len
put_ptr
ft_printptr
charlen
ft_conversion
ft_printf*/

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
* @notice	This function counts the lenght of an unsigned integer number converted
*			into a hexadecimal.
* @param	unsigned_int		The unsigned integer number to convert in
*								hexadecimal.
* @return	int					The lenght of characters of the hexadecimal number.
*/
int	hex_len(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		num /= 16;
		len++;
	}
	return (len);
}

/**
* @notice	This function converts an unsigned integer number into hexadecimal.
* @param	unsigned_int		The unsigned integer number to convert in
*								hexadecimal.
* @param	const_char			The conversion needed ('x' for lowercase and 'X'
*								for uppercase).
* @return	void				No return value needed now.
*/
void	put_hex(unsigned int num, const char conversion)
{
	if (num >= 16)
	{
		put_hex(num / 16, conversion);
		put_hex(num % 16, conversion);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
		{
			if (conversion == 'x')
				ft_putchar_fd((num - 10 + 'a'), 1);
			if (conversion == 'X')
				ft_putchar_fd((num - 10 + 'A'), 1);
		}
	}
}

/**
* @notice	This function checks an unsigned integer number, converts it into
*			hexadecimal, prints it and counts its lenght.
* @param	unsigned_int		The unsigned integer number to convert in
*								hexadecimal.
* @param	const_char			The conversion needed ('x' for lowercase and 'X'
*								for uppercase).
* @return	int					The lenght of characters of the hexadecimal number.
*/
int	print_hex(unsigned int num, const char conversion)
{
	if (num == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	else
		put_hex(num, conversion);
	return (hex_len(num));
}

/**
* @notice	This function counts the lenght of a integer number.
* @param	unsigned_int		The unsigned integer number to count lenght.
* @return	int					The lenght of characters of the number.
*/
int	num_len(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

/**
* @notice	This function converts an unsigned interger number to a
*			string.
* @param	unsigned_int		The unsigned integer number to convert.
* @return	string				The converted number.
*/
char	*unsigned_itoa(unsigned int num)
{
	char	*numchar;
	int		len;

	len = num_len(num);
	numchar = (char *)malloc(sizeof(char) * (len + 1));
	if (!numchar)
		return (NULL);
	numchar[len] = '\0';
	while (num != 0)
	{
		numchar[len - 1] = num % 10 + '0';
		num /= 10;
		len--;
	}
	return (numchar);
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
		numchar = unsigned_itoa(num);
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
* @notice	This function counts the lenght of a pointer.
* @param	uintptr_t			The unsigned integer pointer to count lenght.
* @return	int					The lenght of characters of the pointer.
*/
int	ptr_len(uintptr_t num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

/**
* @notice	This function converts a pointer.
* @param	uintptr_t			The unsigned integer pointer to print.
* @return	void				No return value needed now.
*/
void	put_ptr(uintptr_t num)
{
	if (num >= 16)
	{
		put_ptr(num / 16);
		put_ptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
			ft_putchar_fd((num - 10 + 'a'), 1);
	}
}

/**
* @notice	This function prints the pointer of something.
* @param	unsigned_long_long	The unsigned integer pointer to print.
* @return	int					The lenght of characters of the printed
*								pointer.
*/
int	print_ptr(unsigned long long ptr)
{
	int	len;

	len = 2;
	ft_putstr_fd("0x", 1);
	if (ptr == 0)
	{
		ft_putchar_fd('0', 1);
		len++;
	}
	else
	{
		put_ptr(ptr);
		len += ptr_len(ptr);
	}
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

