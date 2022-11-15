/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:35:04 by rrouille          #+#    #+#             */
/*   Updated: 2022/11/15 11:27:42 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
void	ft_printstr(char *numero);
void	ft_putunsigned(unsigned int num);
void	ft_puthexa(unsigned int num, const char conversion);
void	ft_printnbr(int num);
void	ft_conversion(va_list args, const char conversion);

#endif