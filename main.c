/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uphokaew <uphokaew@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:23:20 by uphokaew          #+#    #+#             */
/*   Updated: 2024/01/24 16:57:17 by uphokaew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	printf("\t |  Len: %d\n", ft_printf("123456"));
	printf("\t |  Len: %d (Real)\n", printf("123456"));

	printf("\t |  Len: %d\n", ft_printf("Test1: %sff%%%222", "g"));
	printf("\t |  Len: %d (Real)\n", printf("Test1: %sff%%%222", "g"));

	printf("\t |  Len: %d\n", ft_printf("Test2: %sff%M %222", "g"));
	printf("\t |  Len: %d (Real)\n", printf("Test2: %sff%M %222", "g"));

	printf("\t |  Len: %d\n", ft_printf("Test2: %sff%M%222", "g"));
	printf("\t |  Len: %d (Real)\n", printf("Test2: %sff%M%222", "g"));

	ft_printf("C_Test: %X\n", -200000);
	printf("R_Test: %X\n", -200000);
	ft_printf("C_Test2: %M\n", -200000);
	printf("R_Test2: %M\n", -200000);
	
	// printf("%d\n", write(-1, "1", 1));
	return (0);
}
