/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:34:59 by rrouille          #+#    #+#             */
/*   Updated: 2022/11/09 19:23:35 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	ft_conversion(va_list args, const char conversion)
{
	if (conversion == 'c')
		ft_putchar_fd(va_start(args, char), 1);
	else if (conversion == 's')
		ft_putstr_fd(va_start(args, char *), 1);
	else if (conversion == 'p')
		ft_putstr_fd(va_start(args, void *), 1);
	else if (conversion == 'd')
		ft_putstr_fd(va_start(args, double), 1);
	else if (conversion == 'i')
		ft_putstr_fd(va_start(args, int), 1);
	else if (conversion == 'u')
		ft_putstr_fd(va_start(args, unsigned int), 1);
	else if (conversion == 'x')
		ft_putstr_fd(va_start(args, char *), 1);
	else if (conversion == 'X')
		ft_putstr_fd(va_start(args, char *), 1);
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
