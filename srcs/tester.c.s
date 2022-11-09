/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:53:47 by rrouille          #+#    #+#             */
/*   Updated: 2022/11/09 19:23:46 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int	main(void)
{
	int		test1;
	char	test2;

	test1 = 21;
	test2 = "Bonjour !";
	printf("%i\n%s", test1, test2);
	ft_printf("%i\n%s", test1, test2);
}
