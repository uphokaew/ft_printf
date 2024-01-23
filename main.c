/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uphokaew <uphokaew@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:23:20 by uphokaew          #+#    #+#             */
/*   Updated: 2024/01/23 18:19:43 by uphokaew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	// printf("\t |  Len: %d\n", ft_printf("123456"));
	// printf("\t |  Len: %d (Real)\n", printf("123456"));
	printf("\t |  Len: %d\n", ft_printf("Test: %sff%A222", "g"));
	printf("\t |  Len: %d (Real)\n", printf("Test: %sff%A222", "g"));
	// ft_printf("C_Test: %sff%222\n", "g");
	// printf("R_Test: %sff%222\n", "g");
	// printf("%d\n", write(-1, "1", 1));
	return (0);
}
