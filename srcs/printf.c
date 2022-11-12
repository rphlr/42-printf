/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:34:59 by rrouille          #+#    #+#             */
/*   Updated: 2022/11/12 14:45:13 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	ft_puthexa(unsigned int num, const char conversion)
{
	if (num == 0)
		ft_putchar_fd("0", 1);
	else if (num >= 16)
	{
		print_hexa(num / 16, conversion);
		print_hexa(num % 16, conversion);
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

void	ft_putunsigned(unsigned int num)
{
	char	*numero;
	int		len;

	if (num == 0)
		ft_putchar_fd("0", 1);
	else
	{
		len = 0;
		while (num != 0)
		{
			len++;
			num = num / 10;
		}
		numero = (char *)malloc(sizeof(char) * (len + 1));
		if (!numero)
			return (0);
		numero[len] = '\0';
		while (num != 0)
		{
			numero[len - 1] = num % 10 + 48;
			num = num / 10;
			len--;
		}
		ft_printstr(numero);
		free(numero);
	}
}

int	ft_printstr(char *numero)
{
	int	i;

	i = 0;
	if (numero == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	while (numero[i])
	{
		write(1, &numero[i], 1);
		i++;
	}
	return (i);
}

void	ft_printnbr(int num)
{
	char	*numero;

	numero = ft_itoa(num);
	ft_printstr(numero);
	free(numero);
}

void	ft_conversion(va_list args, const char conversion)
{
	if (conversion == 'c')
		ft_putchar_fd(va_start(args, char), 1);
	else if (conversion == 's')
		ft_putstr_fd(va_start(args, char *), 1);
	else if (conversion == 'p')
		ft_putstr_fd(va_start(args, void *), 1);
	else if (conversion == 'd')
		ft_printnbr(va_start(args, int), 1);
	else if (conversion == 'i')
		ft_printnbr(va_start(args, int));
	else if (conversion == 'u')
		ft_putunsigned(va_start(args, unsigned int));
	else if (conversion == 'x' || conversion == 'X')
		ft_puthexa(va_start(args, unsigned int), conversion);
	else if (conversion == '%')
		ft_putstr_fd(ft_putchar_fd('%', 1), 1);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		j;
	int		len;
	va_list	args;

	while (str[i])
	{
		j = i + 1;
		if (str[i] == '%')
		{
			len++;
			ft_formats(args, str[j]);
			i++;
		}
		else
		{
			len++;
			ft_putchar_fd(str[j], 1);
		}
		i++;
	}
	va_end(args);
	return (len);
}
