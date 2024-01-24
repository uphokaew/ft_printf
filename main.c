/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uphokaew <uphokaew@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:23:20 by uphokaew          #+#    #+#             */
/*   Updated: 2024/01/24 17:23:08 by uphokaew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	printf("\t |  Len: %d\n", ft_printf("123456"));
	printf("\t |  Len: %d (Real)\n", printf("123456"));

	printf("\t |  Len: %d\n", ft_printf("Test1: ff%222", "5"));
	printf("\t |  Len: %d (Real)\n", printf("Test1: ff%222", "5"));

	printf("\t |  Len: %d\n", ft_printf("Test2: ff%M %222", "4"));
	printf("\t |  Len: %d (Real)\n", printf("Test2: ff%M %222", "4"));

	printf("\t |  Len: %d\n", ft_printf("Test3: %sff%M%222", "g"));
	printf("\t |  Len: %d (Real)\n", printf("Test3: %sff%M%222", "g"));

	printf("\t |  Len: %d\n", ft_printf("Test4: %sff%M %M22", "g"));
	printf("\t |  Len: %d (Real)\n", printf("Test4: %sff%M %M22", "g"));

	ft_printf("C_Test: %X\n", -200000);
	printf("R_Test: %X\n", -200000);
	ft_printf("C_Test2: %M\n", -200000);
	printf("R_Test2: %M\n", -200000);
	
	// printf("%d\n", write(-1, "1", 1));
	return (0);
}
