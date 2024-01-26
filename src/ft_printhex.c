/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uphokaew <uphokaew@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 20:10:38 by uphokaew          #+#    #+#             */
/*   Updated: 2024/01/26 14:44:26 by uphokaew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_hex(unsigned int n, char c, int div)
{
	int		length;
	char	*symbol;

	length = 0;
	if (c == 'x')
		symbol = "0123456789abcdef";
	if (c == 'X')
		symbol = "0123456789ABCDEF";
	while (div > 0)
	{
		if (write(1, &symbol[n / div], 1) == -1)
			return (-1);
		length++;
		n %= div;
		div /= 16;
	}
	return (length);
}

int	ft_printhex(unsigned int hex, char c)
{
	unsigned int	div;
	unsigned int	temp;

	div = 1;
	temp = hex;
	while (temp >= 16)
	{
		temp /= 16;
		div *= 16;
	}
	return (print_hex(hex, c, div));
}
